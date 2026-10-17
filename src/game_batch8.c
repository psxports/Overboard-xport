#include "xport.h"
#include "psx.h"
#include "game_signatures.h"
#include "native_extra_signatures.h"
#include "draft_signatures.h"
#include "movie_player.h"
#include "native_runtime.h"

typedef struct
{
    uint32 cursor;
    uint32 used;
    uint32 capacity;
    uint32 stride;
    uint32 ready;
} OB_CLIP_POOL;

static sint32 ob_batch8_divide(uint32 numerator, uint32 denominator)
{
    if (!denominator) return (sint32)ob_native_missing_value(0x8003DF98, "BREAK 7 signed division by zero");
    if (denominator == 0xFFFFFFFF && numerator == 0x80000000)
        return (sint32)ob_native_missing_value(0x8003DF98, "BREAK 6 signed division overflow");
    return (sint32)numerator / (sint32)denominator;
}

static void ob_batch8_matrix(uint32 matrix, uint32 translation)
{
    uint32 words[5];
    for (uint32 index = 0; index < 5; ++index) words[index] = r_u32(matrix + index * 4);
    for (uint32 index = 0; index < 5; ++index) xport_gte_write_control(index, words[index]);
    for (uint32 index = 0; index < 3; ++index) words[index] = r_u32(translation + 20 + index * 4);
    for (uint32 index = 0; index < 3; ++index) xport_gte_write_control(index + 5, words[index]);
}

static void ob_batch8_transform(uint32 input, uint32 output)
{
    xport_gte_write_data(0, r_u32(input));
    xport_gte_write_data(1, r_u32(input + 4));
    xport_gte_execute(0x480012);
    uint32 x = xport_gte_read_data(25);
    uint32 y = xport_gte_read_data(26);
    w_u16(output + 8, x);
    uint32 z = xport_gte_read_data(27);
    w_u16(output + 10, y);
    w_u16(output + 12, z);
}

static uint32 ob_batch8_pool_take(OB_CLIP_POOL *pool)
{
    /* TODO Original attribute locals are undefined when the model flag is absent */
    if (!pool->ready) return ob_native_missing_value(0x8003DF98, "Uninitialized clipping attribute pool");
    uint32 result = pool->cursor;
    pool->cursor += pool->stride;
    pool->used = (pool->used + 1) & 0xFFFF;
    if (pool->used == pool->capacity)
    {
        pool->cursor = sub_8002D98C(pool->used * pool->stride);
        pool->used = 0;
    }
    return result;
}

static void ob_batch8_interpolate_color(uint32 first, uint32 second, uint32 first_weight, uint32 second_weight, uint32 output)
{
    uint32 xy = r_u32(first);
    uint32 z = r_u32(first + 4);
    xport_gte_write_data(8, first_weight);
    xport_gte_write_data(9, xy & 0xFFFF);
    xport_gte_write_data(10, (uint32)((sint32)xy >> 16));
    xport_gte_write_data(11, z & 0xFFFF);
    xport_gte_execute(0x198003D);
    xy = r_u32(second);
    z = r_u32(second + 4);
    xport_gte_read_data(31);
    xport_gte_write_data(8, second_weight);
    xport_gte_write_data(9, xy & 0xFFFF);
    xport_gte_write_data(10, (uint32)((sint32)xy >> 16));
    xport_gte_write_data(11, z & 0xFFFF);
    xport_gte_execute(0x1A8003E);
    uint32 x = xport_gte_read_data(9);
    uint32 y = xport_gte_read_data(10);
    z = xport_gte_read_data(11);
    w_u32(output, (x & 0xFFFF) | (y << 16));
    w_u32(output + 4, z);
}

static uint32 ob_batch8_interpolate_attributes(uint32 edge, OB_CLIP_POOL *pool)
{
    uint32 output = ob_batch8_pool_take(pool);
    uint32 destination = edge + 12;
    uint32 first;
    uint32 second;
    if (r_u16(edge + 42) == 1)
    {
        first = r_u32(edge + 12);
        second = r_u32(edge + 16);
        destination = edge + 16;
    }
    else
    {
        first = r_u32(edge + 16);
        second = r_u32(edge + 12);
    }
    if (r_u16(0x800774E4) & 2)
    {
        uint32 target = r_u32(second);
        uint32 base = r_u32(first);
        uint32 numerator = (target - base) * (uint32)(sint32)r_s16(edge + 32);
        uint32 delta = (uint32)ob_batch8_divide(numerator, (uint32)(sint32)r_s16(edge + 34));
        base = r_u32(first + 4);
        target = r_u32(second + 4);
        w_u32(output, delta + r_u32(first));
        numerator = (target - base) * (uint32)(sint32)r_s16(edge + 32);
        delta = (uint32)ob_batch8_divide(numerator, (uint32)(sint32)r_s16(edge + 34));
        w_u32(output + 4, delta + r_u32(first + 4));
    }
    else
    {
        uint32 numerator = (uint32)(sint32)r_s16(edge + 32) << 12;
        uint32 fraction = (uint32)ob_batch8_divide(numerator, (uint32)(sint32)r_s16(edge + 34));
        ob_batch8_interpolate_color(first + 8, second + 8, 4096 - fraction, fraction, output + 8);
    }
    w_u32(destination, output);
    return output;
}

static void ob_batch8_project_clip_point(uint32 point)
{
    if (!r_u8(point + 20)) return;
    uint32 flags = r_u32(point + 16);
    if (flags & 0x40)
    {
        uint32 matrix = r_u32(0x80077558);
        uint32 x = (uint32)(sint32)r_s16(point + 8);
        uint32 translation = r_u32(matrix + 20);
        uint32 scale = r_u16(0x80077498);
        uint32 numerator = (x + translation) * scale;
        uint32 z = (uint32)(sint32)r_s16(point + 12) + r_u32(matrix + 28);
        w_u16(point, (uint32)ob_batch8_divide(numerator, z));
        uint32 y = (uint32)(sint32)r_s16(point + 10) + r_u32(matrix + 24);
        numerator = y * scale;
        z = (uint32)(sint32)r_s16(point + 12) + r_u32(matrix + 28);
        uint32 quotient = (uint32)ob_batch8_divide(numerator, z);
        x = r_u16(0x800774A4);
        y = r_u16(0x800774A6);
        w_u16(point + 2, quotient);
        uint32 screen_x = r_u16(point);
        uint32 screen_y = r_u16(point + 2);
        w_u16(point, screen_x + x);
        w_u16(point + 2, screen_y + y);
    }
    else
    {
        xport_gte_write_data(0, r_u32(point + 8));
        xport_gte_write_data(1, r_u32(point + 12));
        xport_gte_execute(0x180001);
        w_u32(point, xport_gte_read_data(14));
    }
    w_u8(point + 20, 0);
}

static uint32 ob_batch8_close_chain(uint32 saved_tag, uint32 exhausted)
{
    uint32 head = r_u32(0x80077634);
    uint32 tag = (r_u32(head) & 0xFF000000) | (saved_tag & 0xFFFFFF);
    w_u32(head, tag);
    return exhausted ? head : tag;
}

uint32 ob_main_8003DF98(uint32 object, uint32 context)
{
    FUNCTION_MARKER(0x8003DF98, "SLES_008.65");
    uint32 previous_state = 0;
    if (!r_u32(0x800774CC)) w_u32(0x80077634, r_u32(0x8007737C) + r_u32(0x80077350) * 4 + 112);
    uint32 saved_tag = r_u32(r_u32(0x80077634));
    if (r_u16(0x80077638))
    {
        uint32 input = r_u32(r_u32(0x80077598) + 32);
        ob_batch8_matrix(r_u32(0x80077558), 0x8007FE08);
        uint32 count = r_u16(0x80077388);
        uint32 output = r_u32(0x80077574);
        for (uint32 index = 0; index < count; ++index)
        {
            ob_batch8_transform(input, output);
            input += 8;
            w_u16(output + 22, r_u16(output + 22) | 0x8000);
            output += 24;
        }
        ob_classify_clip_planes(r_u32(0x80077574), r_u16(0x80077388));
        ob_main_80032A68(r_u32(0x80077574), r_u16(0x80077388));
    }
    uint32 edge_cursor = r_u32(0x80077518);
    uint32 count = r_u16(0x800775A4);
    for (uint32 index = 0; index < count; ++index, edge_cursor += 44) w_u32(edge_cursor + 28, 128);
    uint32 capacity = r_u16(0x80077388) >> 1;
    OB_CLIP_POOL points = {0, 0, capacity, 24, 1};
    OB_CLIP_POOL attributes = {0, 0, 0, 16, 0};
    points.cursor = sub_8002D98C(capacity * 24);
    if (r_u16(object + 6) & 1)
    {
        attributes.capacity = capacity;
        attributes.cursor = sub_8002D98C(capacity * 16);
        attributes.ready = 1;
    }
    uint32 order = r_u32(0x800775E4);
    uint32 remaining = r_u16(0x800775F0) + r_u16(r_u32(0x80077598));
    while (remaining)
    {
        --remaining;
        uint32 identifier = r_u16(order);
        if (identifier == 0xFFFF)
        {
            uint32 saved = sub_800409E0();
            uint32 low = r_u16(order + 2);
            uint32 argument = r_u32(context + 32);
            w_u32(0x800774CC, r_u32(0x800774CC) + 1);
            uint32 packed = (r_u16(order + 4) << 16) + low;
            uint32 kind = r_u16(context + 2);
            ob_draft_unresolved_call(r_u32(context + 36), 3, argument, packed, kind);
            w_u32(0x800774CC, r_u32(0x800774CC) - 1);
            sub_80040BF0(saved);
            order += 6;
            if ((sint32)(r_u32(0x800775BC) - r_u32(0x800774A8)) < (sint32)(remaining << 6))
                return ob_batch8_close_chain(saved_tag, 1);
            continue;
        }
        w_u32(0x80077514, identifier);
        uint32 stream = r_u32(r_u32(0x800773A4) + identifier * 4);
        order += 2;
        w_u32(0x80077418, stream);
        if (!stream) continue;
        w_u32(0x80077418, stream + 2);
        uint32 flags = r_u16(stream);
        w_u32(0x80077384, stream + 2);
        uint32 planes = r_u16(0x80077638);
        w_u32(0x80077418, stream + 4);
        w_u16(0x800774E4, flags);
        count = r_u16(stream + 2);
        w_u16(0x800775B4, count);
        uint32 all = 0xFFFFFFFF;
        uint32 any = 0;
        uint32 vertices = r_u32(0x80077574);
        uint32 indices = stream + 4 + count * 2;
        if (!planes)
        {
            sint32 max_x = 0, min_x = 0, max_y = 0, min_y = 0;
            for (uint32 index = 0; index < count; ++index)
            {
                uint32 vertex = vertices + r_u16(indices + index * 2) * 24;
                uint32 code = (uint32)(sint32)r_s16(vertex + 22);
                sint32 x = r_s16(vertex);
                all &= code;
                any |= code;
                sint32 y = r_s16(vertex + 2);
                if (max_x < x) max_x = x;
                if (max_y < y) max_y = y;
                if (x < min_x) min_x = x;
                if (y < min_y) min_y = y;
            }
            if (all & 0xFFF) continue;
            if (!any || (max_x - min_x < 1023 && max_y - min_y < 500 && !(any & 0x7000)))
            {
                count = r_u16(0x800775B4);
                w_u32(0x80077384, r_u32(0x80077384) + count * 2 + 2);
                w_u32(0x80077418, r_u32(0x80077418) + count * 4);
                ob_main_8003BB2C();
                continue;
            }
        }
        else
        {
            for (uint32 index = 0; index < count; ++index)
            {
                uint32 code = r_u32(vertices + r_u16(indices + index * 2) * 24 + 16);
                all &= code;
                any |= code;
            }
            if (all & 0xFFFFFFBF) continue;
            if (!any)
            {
                count = r_u16(0x800775B4);
                w_u32(0x80077418, r_u32(0x80077418) + count * 4);
                w_u32(0x80077384, r_u32(0x80077384) + count * 2 + 2);
                ob_main_8003BB2C();
                continue;
            }
        }
        all = 0xFFFFFFFF;
        uint32 pending = 0;
        ob_batch8_matrix(r_u32(0x80077558), 0x8007FE08);
        any = 0;
        count = r_u16(0x800775B4);
        uint32 tail = r_u32(0x80077394);
        uint32 edge_table = r_u32(object + 36);
        vertices = r_u32(0x80077574);
        uint32 original_vertices = r_u32(r_u32(0x80077598) + 32);
        for (uint32 index = 0; index < count; ++index)
        {
            stream = r_u32(0x80077418);
            w_u32(0x80077418, stream + 2);
            uint32 edge_index = r_u16(stream);
            uint32 reverse = (edge_index & 0x4000) != 0;
            if (reverse) edge_index &= 0x3FFF;
            edge_cursor = r_u32(0x80077518) + edge_index * 44;
            w_u16(edge_cursor + 38, reverse ? 1 : 2);
            if (r_u32(edge_cursor + 28) & 0x80)
            {
                uint32 first = r_u16(edge_table + edge_index * 4);
                uint32 second = r_u16(edge_table + edge_index * 4 + 2);
                w_u32(edge_cursor + 4, vertices + first * 24);
                w_u32(edge_cursor + 8, vertices + second * 24);
                uint32 point = r_u32(edge_cursor + 4);
                if (r_s16(point + 22) >= 0)
                {
                    ob_batch8_transform(original_vertices + first * 8, point);
                    ob_main_8002C5DC(point);
                    w_u16(point + 22, r_u16(point + 22) | 0x8000);
                }
                point = r_u32(edge_cursor + 8);
                if (r_s16(point + 22) >= 0)
                {
                    ob_batch8_transform(original_vertices + second * 8, point);
                    ob_main_8002C5DC(point);
                    w_u16(point + 22, r_u16(point + 22) | 0x8000);
                }
                uint32 first_flags = r_u32(r_u32(edge_cursor + 4) + 16);
                uint32 second_flags = r_u32(r_u32(edge_cursor + 8) + 16);
                w_u32(edge_cursor + 28, 0);
                w_u16(edge_cursor + 42, 0);
                w_u32(edge_cursor + 20, first_flags & second_flags);
                w_u32(edge_cursor + 24, first_flags | second_flags);
            }
            uint32 both = r_u32(edge_cursor + 20);
            uint32 either = r_u32(edge_cursor + 24);
            uint32 extra = r_u32(edge_cursor + 28);
            w_u32(tail, edge_cursor);
            tail = edge_cursor;
            all &= both;
            any |= either;
            pending += extra;
        }
        if (all & 0xFFFFFFBF) continue;
        uint32 wire = r_u16(0x8007748C) & 0x3F;
        w_u32(edge_cursor, 0);
        if (wire) ob_main_8003D0EC();
        else ob_main_8003CC8C(0, tail);
        uint32 intersections = 0;
        if ((any & 0xFFFFFFBF) || pending)
        {
            uint32 masks = r_u32(0x800775C4);
            uint32 callbacks = r_u32(0x8007736C);
            w_u16(0x80077382, 1);
            w_u32(0x800775B8, r_u32(0x800773DC));
            w_u32(0x80077414, r_u32(0x80077560));
            uint32 plane_index = 0;
            while ((sint32)plane_index < (sint32)(r_u16(0x80077364) + r_u16(0x80077638)))
            {
                w_u16(0x80077380, r_u16(0x80077382) - 1);
                if ((r_u32(masks) & any) || pending)
                {
                    uint32 link = r_u32(0x80077394);
                    uint32 edge = r_u32(link);
                    w_u16(0x800775B4, 0);
                    while (edge)
                    {
                        uint32 mask = r_u32(masks);
                        if (r_u32(edge + 20) & mask) previous_state = 0;
                        else if ((r_u32(edge + 24) & mask) || (r_u32(edge + 28) & mask))
                        {
                            w_u16(0x800775B4, r_u16(0x800775B4) + 1);
                            uint32 point;
                            uint32 attribute = 0;
                            if (r_u32(edge + 28) & r_u32(masks))
                            {
                                point = r_u32(edge + (r_u16(edge + 42) ? 8 : 4));
                                if (r_u16(0x800774E4) & 6) attribute = ob_batch8_interpolate_attributes(edge, &attributes);
                                w_u8(point + 20, 128);
                            }
                            else
                            {
                                point = ob_batch8_pool_take(&points);
                                w_u8(point + 20, 128);
                                uint32 extra = r_u32(edge + 28);
                                if (extra) w_u32(edge + 28, extra | 0x80);
                                ob_draft_unresolved_call(r_u32(callbacks), 2, edge, point);
                                uint32 first = r_u32(r_u32(edge + 4) + 16);
                                uint32 second = r_u32(r_u32(edge + 8) + 16);
                                uint32 either = first | second;
                                w_u32(edge + 20, first & second);
                                uint32 both = r_u32(edge + 20);
                                any |= either;
                                w_u32(edge + 24, either);
                                if (both != either) w_u32(edge + 28, r_u32(edge + 28) | 0x80);
                                if (r_u16(0x800774E4) & 6) attribute = ob_batch8_interpolate_attributes(edge, &attributes);
                            }
                            ++intersections;
                            if ((intersections & 0xFFFF) > 24)
                            {
                                w_u32(0x800775B8, sub_8002D98C(528));
                                intersections = 1;
                            }
                            if (intersections & 1)
                            {
                                w_u32(link, edge);
                                uint32 bridge = r_u32(0x800775B8);
                                w_u32(bridge + 4, point);
                                if (r_u16(0x800774E4) & 6) w_u32(bridge + 12, attribute);
                                link = edge;
                            }
                            else
                            {
                                uint32 bridge = r_u32(0x800775B8);
                                w_u32(bridge + 8, point);
                                if (r_u16(0x800774E4) & 6) w_u32(bridge + 16, attribute);
                                if (previous_state && previous_state != 2)
                                {
                                    w_u32(link, edge);
                                    bridge = r_u32(0x800775B8);
                                    uint32 next = r_u32(edge);
                                    link = bridge;
                                    w_u32(bridge, next);
                                    w_u32(edge, link);
                                    edge = link;
                                }
                                else
                                {
                                    w_u32(link, r_u32(0x800775B8));
                                    bridge = r_u32(0x800775B8);
                                    link = edge;
                                    w_u32(bridge, edge);
                                }
                                bridge = r_u32(0x800775B8);
                                uint32 first = r_u32(bridge + 4);
                                uint32 second = r_u32(bridge + 8);
                                w_u16(0x800775B4, r_u16(0x800775B4) + 1);
                                uint32 first_flags = r_u32(first + 16);
                                uint32 second_flags = r_u32(second + 16);
                                w_u32(0x800775B8, bridge + 44);
                                w_u32(bridge + 28, 0);
                                w_u16(bridge + 42, 0);
                                w_u32(bridge + 20, first_flags & second_flags);
                                w_u32(bridge + 24, first_flags | second_flags);
                            }
                            previous_state = 2;
                        }
                        else
                        {
                            previous_state = 1;
                            w_u16(0x800775B4, r_u16(0x800775B4) + 1);
                            w_u32(link, edge);
                            link = edge;
                        }
                        edge = r_u32(edge);
                    }
                    w_u32(link, 0);
                }
                ++plane_index;
                w_u16(0x80077382, r_u16(0x80077382) + 1);
                callbacks += 4;
                w_u32(0x80077414, r_u32(0x80077414) + 12);
                masks += 4;
            }
        }
        ob_batch8_matrix(0x8007FE08, r_u32(0x80077558));
        uint32 output = (uint32)r_u16(0x800775B4) * 16 < r_u32(0x8007759C) ? r_u32(0x80077530) : 0x8008CB50;
        w_u32(0x800774C0, output);
        uint32 edge = r_u32(r_u32(0x80077394));
        uint32 previous_second = r_u32(edge + 8);
        uint32 previous_first = r_u32(edge + 4);
        while (edge)
        {
            uint32 first = r_u32(edge + 4);
            ob_batch8_project_clip_point(first);
            uint32 second = r_u32(edge + 8);
            ob_batch8_project_clip_point(second);
            uint32 selected = 0;
            if (first == previous_second) selected = second != first ? 2 : 1;
            else if (second == previous_second || first == previous_first) selected = 1;
            else if (second == previous_first) selected = 2;
            if (selected)
            {
                uint32 point = selected == 1 ? first : second;
                uint32 x = r_u16(point);
                uint32 format = r_u16(0x800774E4);
                w_u16(output, x);
                w_u16(output + 2, r_u16(point + 2));
                uint32 slot = edge + (selected == 1 ? 12 : 16);
                if (format & 2)
                {
                    w_u8(output + 8, r_u32(r_u32(slot)));
                    w_u8(output + 9, r_u32(r_u32(slot) + 4));
                }
                else if (format & 4)
                {
                    w_u8(output + 12, r_u16(r_u32(slot) + 8));
                    w_u8(output + 13, r_u16(r_u32(slot) + 10));
                    w_u8(output + 14, r_u16(r_u32(slot) + 12));
                }
                output += 16;
                previous_second = point;
                previous_first = selected == 1 ? second : first;
            }
            edge = r_u32(edge);
        }
        if ((sint32)(r_u32(0x800775BC) - r_u32(0x800774A8)) < (sint32)(r_u16(0x800775B4) << 6))
            return ob_batch8_close_chain(saved_tag, 1);
        ob_main_8003D20C();
        if ((sint32)(r_u32(0x800775BC) - r_u32(0x800774A8)) < (sint32)(remaining << 6))
            return ob_batch8_close_chain(saved_tag, 1);
    }
    return ob_batch8_close_chain(saved_tag, 0);
}

static void ob_batch8_rotation(uint32 matrix)
{
    uint32 words[5];
    for (uint32 index = 0; index < 5; ++index) words[index] = r_u32(matrix + index * 4);
    for (uint32 index = 0; index < 5; ++index) xport_gte_write_control(index, words[index]);
}

static void ob_batch8_translation(uint32 matrix)
{
    uint32 x = r_u32(matrix + 20);
    uint32 y = r_u32(matrix + 24);
    uint32 z = r_u32(matrix + 28);
    xport_gte_write_control(5, x);
    xport_gte_write_control(6, y);
    xport_gte_write_control(7, z);
}

static uint32 ob_batch8_plane_distance(uint32 plane, uint32 point)
{
    uint32 first = r_u32(plane + 4);
    uint32 second = r_u32(plane + 8);
    xport_gte_write_control(0, first);
    xport_gte_write_control(1, second);
    xport_gte_write_data(0, r_u32(point + 8));
    xport_gte_write_data(1, r_u32(point + 12));
    xport_gte_execute(0x486012);
    w_u32(0x1F800000, xport_gte_read_data(25));
    return (uint32)(r_s32(0x1F800000) >> 2);
}

static void ob_batch8_intersect_plane(uint32 edge, uint32 point)
{
    uint32 bit = (uint32)1 << ((r_u16(0x80077380) + 8) & 31);
    uint32 outside = r_u32(edge + 8);
    w_u32(edge + 28, r_u32(edge + 28) | bit);
    uint32 inside;
    uint32 destination;
    if (r_u32(outside + 16) & bit)
    {
        destination = edge + 8;
        inside = r_u32(edge + 4);
        w_u32(0x80077570, outside);
        w_u16(edge + 42, 1);
    }
    else
    {
        inside = outside;
        outside = r_u32(edge + 4);
        destination = edge + 4;
        w_u16(edge + 42, 0);
        w_u32(0x80077570, outside);
    }
    uint32 inside_distance = ob_batch8_plane_distance(r_u32(0x80077414), inside);
    uint32 outside_distance = ob_batch8_plane_distance(r_u32(0x80077414), r_u32(0x80077570));
    uint32 plane = r_u32(0x80077414);
    uint32 inverted = r_u8(plane + 10);
    uint32 denominator;
    if (inverted)
    {
        inside_distance = 0 - inside_distance;
        outside_distance = 0 - outside_distance;
        w_u16(edge + 32, r_u32(plane) - outside_distance);
        denominator = inside_distance - outside_distance;
    }
    else
    {
        w_u16(edge + 32, r_u32(plane) - inside_distance);
        denominator = outside_distance - inside_distance;
    }
    uint32 numerator = (uint32)(sint32)r_s16(edge + 32) << 12;
    uint32 fraction = (uint32)ob_batch8_divide(numerator, (uint32)(sint32)(sint16)denominator);
    w_u16(edge + 34, denominator);
    w_u16(0x800735D0, fraction);
    outside = r_u32(0x80077570);
    w_u16(0x800735D8, fraction);
    w_u16(0x800735E0, fraction);
    uint32 base = inverted ? outside : inside;
    uint32 target = inverted ? inside : outside;
    uint32 delta_x = (uint16)(r_u16(target + 8) - r_u16(base + 8));
    uint32 delta_y = (uint16)(r_u16(target + 10) - r_u16(base + 10));
    uint32 delta_z = (uint16)(r_u16(target + 12) - r_u16(base + 12));
    ob_batch8_rotation(0x800735D0);
    xport_gte_write_data(0, delta_x | (delta_y << 16));
    /* The original temporary vector's upper padding half is unused by GTE */
    xport_gte_write_data(1, delta_z);
    xport_gte_execute(0x486012);
    w_u32(0x1F800000, xport_gte_read_data(25));
    w_u32(0x1F800004, xport_gte_read_data(26));
    w_u32(0x1F800008, xport_gte_read_data(27));
    if (inverted) base = r_u32(0x80077570);
    w_u16(point + 8, r_u16(base + 8) + r_u32(0x1F800000));
    w_u16(point + 10, r_u16(base + 10) + r_u32(0x1F800004));
    w_u16(point + 12, r_u16(base + 12) + r_u32(0x1F800008));
    if (inverted)
    {
        plane = r_u32(0x80077414);
        uint32 distance = r_u32(plane);
        w_u16(edge + 34, outside_distance - inside_distance);
        w_u16(edge + 32, distance - inside_distance);
    }
    w_u32(destination, point);
    uint32 index = r_u16(0x80077382);
    plane = r_u32(0x80077560) + index * 12;
    w_u32(point + 16, 0);
    while ((sint32)index < (sint32)r_u16(0x80077638))
    {
        uint32 distance = ob_batch8_plane_distance(plane, point);
        if (r_u8(plane + 10)) distance = 0 - distance;
        w_u32(0x1F800000, distance);
        if (r_s32(plane) < r_s32(0x1F800000))
            w_u32(point + 16, r_u32(point + 16) | ((uint32)1 << ((index + 8) & 31)));
        ++index;
        plane += 12;
    }
}

static void ob_batch8_project_gte_point(uint32 point)
{
    if (!r_u8(point + 20)) return;
    xport_gte_write_data(0, r_u32(point + 8));
    xport_gte_write_data(1, r_u32(point + 12));
    xport_gte_execute(0x180001);
    w_u32(point, xport_gte_read_data(14));
    w_u8(point + 20, 0);
}

uint32 ob_main_8003F528(uint32 object, uint32 context)
{
    FUNCTION_MARKER(0x8003F528, "SLES_008.65");
    uint32 previous_state = 0;
    if (!r_u32(0x800774CC)) w_u32(0x80077634, r_u32(0x8007737C) + r_u32(0x80077350) * 4 + 112);
    uint32 saved_tag = r_u32(r_u32(0x80077634));
    ob_batch8_matrix(r_u32(0x80077558), 0x8007FE08);
    uint32 input = r_u32(r_u32(0x80077598) + 32);
    uint32 vertex_count = r_u16(0x80077388);
    uint32 transformed = r_u32(0x80077574);
    for (uint32 index = 0; index < vertex_count; ++index)
    {
        ob_batch8_transform(input, transformed);
        input += 8;
        uint32 cached = r_u16(transformed + 22);
        w_u32(transformed + 16, 0);
        w_u16(transformed + 22, cached | 0x8000);
        transformed += 24;
    }
    ob_main_80032A68(r_u32(0x80077574), r_u16(0x80077388));
    uint32 edge_cursor = r_u32(0x80077518);
    uint32 count = r_u16(0x800775A4);
    for (uint32 index = 0; index < count; ++index, edge_cursor += 44) w_u32(edge_cursor + 28, 128);
    uint32 capacity = r_u16(0x80077388) >> 1;
    OB_CLIP_POOL points = {0, 0, capacity, 24, 1};
    OB_CLIP_POOL attributes = {0, 0, 0, 16, 0};
    points.cursor = sub_8002D98C(capacity * 24);
    if (r_u16(object + 6) & 1)
    {
        attributes.capacity = capacity;
        attributes.cursor = sub_8002D98C(capacity * 16);
        attributes.ready = 1;
    }
    uint32 order = r_u32(0x800775E4);
    ob_batch8_translation(r_u32(0x80077558));
    uint32 remaining = r_u16(0x800775F0) + r_u16(r_u32(0x80077598));
    while (remaining)
    {
        --remaining;
        uint32 identifier = r_u16(order);
        if (identifier == 0xFFFF)
        {
            uint32 saved = sub_800409E0();
            uint32 low = r_u16(order + 2);
            uint32 argument = r_u32(context + 32);
            w_u32(0x800774CC, r_u32(0x800774CC) + 1);
            uint32 packed = (r_u16(order + 4) << 16) + low;
            uint32 kind = r_u16(context + 2);
            ob_draft_unresolved_call(r_u32(context + 36), 3, argument, packed, kind);
            w_u32(0x800774CC, r_u32(0x800774CC) - 1);
            sub_80040BF0(saved);
            order += 6;
            if ((sint32)(r_u32(0x800775BC) - r_u32(0x800774A8)) < (sint32)(remaining << 6))
                return ob_batch8_close_chain(saved_tag, 1);
            continue;
        }
        w_u32(0x80077514, identifier);
        uint32 stream = r_u32(r_u32(0x800773A4) + identifier * 4);
        order += 2;
        w_u32(0x80077418, stream);
        if (!stream) continue;
        w_u32(0x80077418, stream + 2);
        uint32 flags = r_u16(stream);
        w_u32(0x80077384, stream + 2);
        w_u32(0x80077418, stream + 4);
        w_u16(0x800774E4, flags);
        count = r_u16(stream + 2);
        w_u16(0x800775B4, count);
        uint32 all = 0xFFFFFFFF;
        uint32 any = 0;
        uint32 vertices = r_u32(0x80077574);
        uint32 indices = stream + 4 + count * 2;
        for (uint32 index = 0; index < count; ++index)
        {
            uint32 code = r_u32(vertices + r_u16(indices + index * 2) * 24 + 16);
            all &= code;
            any |= code;
        }
        if (all) continue;
        if (!any)
        {
            count = r_u16(0x800775B4);
            w_u32(0x80077418, r_u32(0x80077418) + count * 4);
            w_u32(0x80077384, r_u32(0x80077384) + count * 2 + 2);
            ob_main_8003BB2C();
            continue;
        }
        all = 0xFFFFFFFF;
        uint32 pending = 0;
        any = 0;
        count = r_u16(0x800775B4);
        uint32 tail = r_u32(0x80077394);
        uint32 edge_table = r_u32(object + 36);
        vertices = r_u32(0x80077574);
        for (uint32 index = 0; index < count; ++index)
        {
            stream = r_u32(0x80077418);
            w_u32(0x80077418, stream + 2);
            uint32 edge_index = r_u16(stream);
            uint32 reverse = (edge_index & 0x4000) != 0;
            if (reverse) edge_index &= 0x3FFF;
            edge_cursor = r_u32(0x80077518) + edge_index * 44;
            w_u16(edge_cursor + 38, reverse ? 1 : 2);
            if (r_u32(edge_cursor + 28) & 0x80)
            {
                uint32 first = r_u16(edge_table + edge_index * 4);
                uint32 second = r_u16(edge_table + edge_index * 4 + 2);
                w_u32(edge_cursor + 4, vertices + first * 24);
                w_u32(edge_cursor + 8, vertices + second * 24);
                uint32 first_flags = r_u32(r_u32(edge_cursor + 4) + 16);
                uint32 second_flags = r_u32(r_u32(edge_cursor + 8) + 16);
                w_u32(edge_cursor + 28, 0);
                w_u16(edge_cursor + 42, 0);
                w_u32(edge_cursor + 20, first_flags & second_flags);
                w_u32(edge_cursor + 24, first_flags | second_flags);
            }
            uint32 both = r_u32(edge_cursor + 20);
            uint32 either = r_u32(edge_cursor + 24);
            uint32 extra = r_u32(edge_cursor + 28);
            w_u32(tail, edge_cursor);
            tail = edge_cursor;
            all &= both;
            any |= either;
            pending += extra;
        }
        if (all) continue;
        uint32 wire = r_u16(0x8007748C) & 0x3F;
        w_u32(edge_cursor, 0);
        if (wire) ob_main_8003D0EC();
        else ob_main_8003CC8C(0, tail);
        uint32 intersections = 0;
        {
            uint32 masks = r_u32(0x800775C4);
            w_u16(0x80077382, 1);
            w_u32(0x800775B8, r_u32(0x800773DC));
            w_u32(0x80077414, r_u32(0x80077560));
            uint32 plane_index = 0;
            while ((sint32)plane_index < (sint32)r_u16(0x80077638))
            {
                w_u16(0x80077380, r_u16(0x80077382) - 1);
                if ((r_u32(masks) & any) || pending)
                {
                    uint32 link = r_u32(0x80077394);
                    uint32 edge = r_u32(link);
                    w_u16(0x800775B4, 0);
                    while (edge)
                    {
                        uint32 mask = r_u32(masks);
                        if (r_u32(edge + 20) & mask) previous_state = 0;
                        else if ((r_u32(edge + 24) & mask) || (r_u32(edge + 28) & mask))
                        {
                            w_u16(0x800775B4, r_u16(0x800775B4) + 1);
                            uint32 point;
                            uint32 attribute = 0;
                            if (r_u32(edge + 28) & r_u32(masks))
                            {
                                point = r_u32(edge + (r_u16(edge + 42) ? 8 : 4));
                                if (r_u16(0x800774E4) & 6) attribute = ob_batch8_interpolate_attributes(edge, &attributes);
                                w_u8(point + 20, 128);
                            }
                            else
                            {
                                point = ob_batch8_pool_take(&points);
                                w_u8(point + 20, 128);
                                uint32 extra = r_u32(edge + 28);
                                if (extra) w_u32(edge + 28, extra | 0x80);
                                ob_batch8_intersect_plane(edge, point);
                                uint32 first = r_u32(r_u32(edge + 4) + 16);
                                uint32 second = r_u32(r_u32(edge + 8) + 16);
                                uint32 either = first | second;
                                w_u32(edge + 20, first & second);
                                uint32 both = r_u32(edge + 20);
                                any |= either;
                                w_u32(edge + 24, either);
                                if (both != either) w_u32(edge + 28, r_u32(edge + 28) | 0x80);
                                if (r_u16(0x800774E4) & 6) attribute = ob_batch8_interpolate_attributes(edge, &attributes);
                            }
                            ++intersections;
                            uint32 bridge_capacity = r_u16(0x800770EC);
                            if ((intersections & 0xFFFF) > bridge_capacity * 2)
                            {
                                w_u32(0x800775B8, sub_8002D98C(bridge_capacity * 44));
                                intersections = 1;
                            }
                            if (intersections & 1)
                            {
                                w_u32(link, edge);
                                uint32 bridge = r_u32(0x800775B8);
                                w_u32(bridge + 4, point);
                                if (r_u16(0x800774E4) & 6) w_u32(bridge + 12, attribute);
                                link = edge;
                            }
                            else
                            {
                                uint32 bridge = r_u32(0x800775B8);
                                w_u32(bridge + 8, point);
                                if (r_u16(0x800774E4) & 6) w_u32(bridge + 16, attribute);
                                if (previous_state && previous_state != 2)
                                {
                                    w_u32(link, edge);
                                    bridge = r_u32(0x800775B8);
                                    uint32 next = r_u32(edge);
                                    link = bridge;
                                    w_u32(bridge, next);
                                    w_u32(edge, link);
                                    edge = link;
                                }
                                else
                                {
                                    w_u32(link, r_u32(0x800775B8));
                                    bridge = r_u32(0x800775B8);
                                    link = edge;
                                    w_u32(bridge, edge);
                                }
                                bridge = r_u32(0x800775B8);
                                uint32 first = r_u32(bridge + 4);
                                uint32 second = r_u32(bridge + 8);
                                w_u16(0x800775B4, r_u16(0x800775B4) + 1);
                                uint32 first_flags = r_u32(first + 16);
                                uint32 second_flags = r_u32(second + 16);
                                w_u32(0x800775B8, bridge + 44);
                                w_u32(bridge + 28, 0);
                                w_u16(bridge + 42, 0);
                                w_u32(bridge + 20, first_flags & second_flags);
                                w_u32(bridge + 24, first_flags | second_flags);
                            }
                            previous_state = 2;
                        }
                        else
                        {
                            previous_state = 1;
                            w_u16(0x800775B4, r_u16(0x800775B4) + 1);
                            w_u32(link, edge);
                            link = edge;
                        }
                        edge = r_u32(edge);
                    }
                    w_u32(link, 0);
                }
                ++plane_index;
                w_u16(0x80077382, r_u16(0x80077382) + 1);
                w_u32(0x80077414, r_u32(0x80077414) + 12);
                masks += 4;
            }
        }
        ob_batch8_rotation(0x8007FE08);
        uint32 output = (uint32)r_u16(0x800775B4) * 16 < r_u32(0x8007759C) ? r_u32(0x80077530) : 0x8008CB50;
        w_u32(0x800774C0, output);
        uint32 edge = r_u32(r_u32(0x80077394));
        uint32 previous_second = r_u32(edge + 8);
        uint32 previous_first = r_u32(edge + 4);
        while (edge)
        {
            uint32 first = r_u32(edge + 4);
            ob_batch8_project_gte_point(first);
            uint32 second = r_u32(edge + 8);
            ob_batch8_project_gte_point(second);
            uint32 selected = 0;
            if (first == previous_second) selected = second != first ? 2 : 1;
            else if (second == previous_second || first == previous_first) selected = 1;
            else if (second == previous_first) selected = 2;
            if (selected)
            {
                uint32 point = selected == 1 ? first : second;
                uint32 x = r_u16(point);
                uint32 format = r_u16(0x800774E4);
                w_u16(output, x);
                w_u16(output + 2, r_u16(point + 2));
                uint32 slot = edge + (selected == 1 ? 12 : 16);
                if (format & 2)
                {
                    w_u8(output + 8, r_u32(r_u32(slot)));
                    w_u8(output + 9, r_u32(r_u32(slot) + 4));
                }
                else if (format & 4)
                {
                    w_u8(output + 12, r_u16(r_u32(slot) + 8));
                    w_u8(output + 13, r_u16(r_u32(slot) + 10));
                    w_u8(output + 14, r_u16(r_u32(slot) + 12));
                }
                output += 16;
                previous_second = point;
                previous_first = selected == 1 ? second : first;
            }
            edge = r_u32(edge);
        }
        if ((sint32)(r_u32(0x800775BC) - r_u32(0x800774A8)) < (sint32)(r_u16(0x800775B4) << 6))
            return ob_batch8_close_chain(saved_tag, 1);
        ob_main_8003D20C();
        if ((sint32)(r_u32(0x800775BC) - r_u32(0x800774A8)) < (sint32)(remaining << 6))
            return ob_batch8_close_chain(saved_tag, 1);
    }
    return ob_batch8_close_chain(saved_tag, 0);
}

typedef struct
{
    uint32 status_v0;
    uint32 result_v1;
} OB_MONITOR_READ_REPLY;

static OB_MONITOR_READ_REPLY ob_batch8_monitor_read(uint32 operation, uint32 handle, uint32 size, uint32 buffer)
{
    /* TODO Bind host-monitor BREAK 0,0x106 and both returned register values */
    ob_native_missing(0x8005FBE8, 4, 4);
}

uint32 ob_main_8005FBE8(uint32 operation, uint32 handle, uint32 size, uint32 buffer)
{
    FUNCTION_MARKER(0x8005FBE8, "SLES_008.65");
    OB_MONITOR_READ_REPLY reply = ob_batch8_monitor_read(operation, handle, size, buffer);
    return reply.status_v0 == 0 ? reply.result_v1 : 0xFFFFFFFF;
}

uint32 ob_main_80063D08(uint32 io_base_v1)
{
    FUNCTION_MARKER(0x80063D08, "SLES_008.65");
    /* The original consumes incoming V1 instead of standard A0 */
    uint32 pending = r_u32(io_base_v1 + 0x1074) & 0x80;
    if (!pending) return 0;
    while (r_u32(io_base_v1 + 0x1044) & 0x80) {}
    uint32 continuation = r_u32(0x80077284);
    /* TODO Bind the BIOS tail continuation while retaining its V1 carrier */
    return ob_draft_unresolved_call(continuation, 1, io_base_v1);
}

uint32 ob_movie_8008E500(uint32 limit)
{
    FUNCTION_MARKER(0x8008E500, "MOVIE.BIN");
    if (limit == 0x80000000)
        return ob_native_missing_value(0x8008E500, "Signed MIPS ADDI overflow");
    sint32 test = (sint32)(limit - 1);
    uint32 previous = r_u32(0x8008E4FC);
    w_u32(0x8008E4FC, test <= 0 ? 0xFFFFFF : limit << 1);
    return previous;
}

uint32 ob_game_800A6DF0(uint32 object)
{
    FUNCTION_MARKER(0x800A6DF0, "GAME.BIN");
    uint32 node = r_u32(object + 44);
    w_u32(object + 288, 3);
    sub_80045A44(node, 0x800C542C);
    w_u8(r_u32(object + 60) + 54, 1);
    return 1;
}

uint32 ob_game_800A6624(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800A6624, "GAME.BIN");
    uint32 script = r_u32(object + 108);
    ob_set_object_time(r_u32(object + 44), time);
    uint32 elapsed = time - r_u32(object + 28);
    switch (r_u32(object + 288))
    {
    case 3:
        ob_game_800B83FC(r_u32(object + 44), 1, 1, time);
        return ob_game_800BCAA0(object);
    case 10:
        w_u32(object + 288, 7);
        break;
    case 7:
        w_u32(object + 252, (uint32)-2000);
        sub_800458B4(r_u32(object + 44), object + 248, time);
        ob_main_8004659C(r_u32(object + 52), time);
        sub_8004F2C4(r_u32(object + 56), 1);
        sub_800440B8(r_u32(object + 48), (uint32)r_s16(object + 306));
        ob_game_800A9E30(r_u32(script), 0, 500, 0, 1);
        /* TODO Bind the original effect operation at 8004E680 */
        ob_draft_unresolved_call(0x8004E680, 1, r_u32(object + 60));
        w_u8(r_u32(object + 60) + 54, 1);
        {
            uint32 node = r_u32(object + 44);
            w_u32(object + 288, 4);
            sub_80045A44(node, 0x800C5444);
        }
        break;
    case 8:
        if (elapsed)
        {
            uint32 node = r_u32(object + 44);
            w_u32(node + 136, r_u32(node + 136) - elapsed * 3);
            sub_80045ADC(r_u32(object + 44));
            ob_invalidate_object_matrix(r_u32(object + 44));
        }
        break;
    case 6:
        w_u8(r_u32(object + 60) + 54, 6);
        if (r_u32(script + 4) == 23)
        {
            uint32 vector = ob_draft_scratch_acquire(16);
            for (uint32 i = 0; i < 3; ++i)
                w_u32(vector + i * 4, r_u32(0x8008E1C0 + i * 4));
            sub_80045A44(r_u32(object + 44), vector);
            ob_draft_scratch_release(vector);
            w_u32(object + 288, 5);
        }
        if (r_u32(script + 4) == 17)
        {
            if (r_u32(script + 8) < time)
                ob_game_800A6DF0(object);
            else
                ob_main_80011A24(0x800660C4, 128, 256, r_u32(object + 44), time, 0);
        }
        break;
    case 5:
        {
            sint32 height = r_s32(r_u32(object + 44) + 112);
            uint32 value = height < 500 ? (uint32)(sint32)(sint16)(height / 4 + 100) : 225;
            sub_800440B8(r_u32(object + 48), value);
        }
        break;
    }
    uint32 state = r_u32(object + 288);
    w_u32(object + 28, time);
    uint32 next_time;
    switch (state)
    {
    case 3: next_time = time + 2000; break;
    case 5:
        if (r_s32(r_u32(object + 44) + 112) >= 5001)
        {
            ob_game_800A6D2C(r_u32(object + 44), time);
            ob_main_80011A24(0x80068ADC, 128, 256, r_u32(object + 44), time, 0);
            return ob_game_800BCAA0(object);
        }
        next_time = time + 200;
        break;
    case 6: next_time = time + 5000; break;
    case 7:
        w_u32(object + 252, (uint32)-2000);
        sub_800458B4(r_u32(object + 44), object + 248, time);
        next_time = time + r_u16(object + 268) * 1000;
        break;
    case 8: next_time = time + (uint32)r_s16(object + 308); break;
    case 11:
        {
            uint32 effect = r_u32(object + 48);
            w_u16(effect + 160, r_u16(effect + 160) - 50);
            if (r_s16(r_u32(object + 48) + 160) >= 51)
                next_time = time + 100;
            else
            {
                if (!r_u16(object + 268)) return ob_game_800BCAA0(object);
                ob_main_8004E66C(r_u32(object + 60));
                uint32 child = r_u32(object + 64);
                w_u32(object + 288, 10);
                if (child) ob_unregister_effect_object(object + 64);
                next_time = time;
            }
        }
        break;
    case 37: return ob_game_800BCAA0(object);
    default:
        /* The original leaves the second jump table target in V0 */
        return state - 3 < 35 ? r_u32(0x8008E260 + (state - 3) * 4) : 0;
    }
    return ob_game_800C0744(object, 0, next_time);
}

uint32 ob_game_80095EEC(uint32 object, uint32 x, uint32 y, uint32 z, uint32 time)
{
    FUNCTION_MARKER(0x80095EEC, "GAME.BIN");
    uint32 locals = ob_draft_scratch_acquire(32);
    for (uint32 i = 0; i < 3; ++i)
        w_u32(locals + i * 4, r_u32(0x8008D660 + i * 4));
    uint32 parent = r_u32(r_u32(object + 108));
    ob_copy_advanced_position(r_u32(parent + 44), time, locals + 16);
    uint32 distance;
    switch (r_s16(object + 296))
    {
    case 0: distance = x - r_u32(locals + 16); break;
    case 16384: distance = r_u32(locals + 24) - z; break;
    case -32768: distance = r_u32(locals + 16) - x; break;
    case -16384: distance = z - r_u32(locals + 24); break;
    default:
        /* TODO The original leaves incoming S2 live for other orientations */
        return ob_native_missing_value(0x80095EEC, "Noncardinal orientation needs incoming S2");
    }
    sint32 absolute = (sint32)distance < 0 ? (sint32)(0 - distance) : (sint32)distance;
    uint32 state = r_u32(object + 288);
    uint32 vector = locals;
    uint32 update = 0;
    if (state == 38)
    {
        if (absolute >= 4000)
        {
            uint32 effect = r_u32(parent + 52);
            if (!r_u32(effect + 28)) sub_80046544(effect);
            sub_80045A44(r_u32(parent + 44), 0x8006C160);
        }
        else if (absolute < 51)
        {
            w_u32(object + 288, 13);
            sub_80045A44(r_u32(parent + 44), 0x8006C160);
        }
    }
    else if (state == 14 || state == 15)
    {
        if (state == 14 && absolute >= 4000)
        {
            uint32 effect = r_u32(parent + 52);
            if (!r_u32(effect + 28)) sub_80046544(effect);
            w_u32(object + 288, 12);
            vector = 0x8006C160;
        }
        else if (state == 15 && absolute < 51)
        {
            w_u32(object + 288, 13);
            vector = 0x8006C160;
        }
        else
        {
            sint32 orientation = r_s16(0x800CBA30 + (uint32)(sint32)r_s16(object + 326) * 104);
            uint32 speed = state == 14 ? 1000 : (uint32)-1000;
            if (orientation == -32768) w_u32(locals, speed);
            else if (orientation == 0) w_u32(locals, 0 - speed);
            else if (orientation == 16384) w_u32(locals + 8, speed);
            else if (orientation == -16384) w_u32(locals + 8, 0 - speed);
        }
        update = 1;
        sub_80045A44(r_u32(parent + 44), vector);
    }
    if (update)
    {
        if (r_u32(object + 64)) ob_unregister_effect_object(object + 64);
        ob_game_800C0744(object, 0, time + (uint32)r_s16(object + 308));
    }
    ob_draft_scratch_release(locals);
    return (uint32)(sint32)(sint16)distance;
}

uint32 ob_game_80095DD4(uint32 object, uint32 x, uint32 y, uint32 z, uint32 time)
{
    FUNCTION_MARKER(0x80095DD4, "GAME.BIN");
    uint32 script = r_u32(object + 108);
    ob_set_object_time(r_u32(object + 44), time);
    ob_set_object_time(r_u32(r_u32(object + 140) + 44), time);
    ob_set_object_time(r_u32(r_u32(script) + 44), time);
    uint32 distance = ob_game_80095EEC(object, x, y, z, time);
    sint32 product = (sint16)distance * r_s16(script + 6);
    sint32 angle = product / 4000;
    uint32 local = ob_draft_scratch_acquire(24);
    uint32 matrix = ob_game_800AD6E0(local, (uint32)(sint32)(sint16)(r_u16(object + 296) - (uint32)angle));
    sub_80045848(r_u32(object + 44), matrix);
    matrix = ob_game_800AD6E0(local, (uint32)(sint32)(sint16)((uint32)angle + r_u16(object + 296)));
    uint32 result = sub_80045848(r_u32(r_u32(object + 140) + 44), matrix);
    w_u32(object + 28, time);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_80095D2C(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x80095D2C, "GAME.BIN");
    uint32 elapsed = time - r_u32(object + 28);
    uint32 result = 38;
    if (r_u32(object + 288) == 38)
        result = ob_game_800966EC(object, 15, time);
    if (elapsed)
    {
        uint32 row = (uint32)(sint32)r_s16(object + 326) * 104;
        uint32 x = r_u32(0x800CBA20 + row);
        uint32 y = r_u32(0x800CBA24 + row);
        uint32 z = r_u32(0x800CBA28 + row);
        result = ob_game_80095DD4(object, x, y, z, time);
    }
    return result;
}

uint32 ob_game_8009A860(uint32 object, uint32 owner, uint32 request, uint32 time)
{
    FUNCTION_MARKER(0x8009A860, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(88);
    uint32 texture = r_u32(0x800C4828);
    w_u32(request + 68, local);
    w_u32(request + 72, 0);
    w_u32(request + 80, 6);
    w_u32(request + 64, texture);
    ob_game_800B66C4(object, owner, request, time);
    w_u32(object + 156, object + 160);
    w_u32(object + 160, r_u32(request + 100));
    w_u32(r_u32(object + 156) + 4, r_u32(request + 104));
    w_u16(r_u32(object + 156) + 8, r_u16(request + 108));
    w_u16(r_u32(object + 156) + 10, r_u16(request + 110));
    w_u16(r_u32(object + 156) + 12, r_u16(request + 112));
    w_u32(local + 40, 0);
    w_u32(local + 44, 0x2407AB36);
    w_u32(local + 52, 0);
    w_u32(local + 56, 0);
    w_u32(local + 48, 0x2407AB36);
    w_u32(local + 60, 0x2407AB36);
    w_u32(local + 68, 0);
    w_u32(local + 64, 0);
    w_u32(local + 80, 0x8009AB64);
    w_u32(object + 52, sub_80046184(object, local, time));
    w_u32(object + 100, 0x8009A9A8);
    w_u32(object + 92, time + 140);
    uint32 frame = ((sint32)ob_random15() >> 4) & 1;
    sint32 size = (sint32)((uint32)(sint32)r_s16(object + 140) << frame);
    w_u16(object + 142, frame);
    sub_800440B8(r_u32(object + 48), (uint32)(sint32)(sint16)(size / 8 + 300));
    ob_register_effect_object(object + 64);
    ob_draft_scratch_release(local);
    return object;
}

uint32 ob_game_8009A9A8(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x8009A9A8, "GAME.BIN");
    uint32 elapsed = time - r_u32(object + 28);
    if (!r_u32(object + 116) && (sint32)(time - r_u32(object + 124)) >= 51)
    {
        uint32 source = r_u32(object + 156);
        if (source)
        {
            uint32 row = (uint32)(sint32)r_s16(source + 12) * 104;
            if (r_u8(0x800CBA5C + row) == 2 && r_u16(0x800CBA44 + row) == r_u16(source + 10))
            {
                ob_set_object_time(r_u32(source), time);
                ob_game_800B9AF4(object, time);
                ob_game_800B9C24(object, time);
            }
            else w_u32(object + 156, 0);
        }
    }
    if (elapsed)
    {
        if (r_u32(object + 48))
        {
            sint32 frame = (sint16)(r_u16(object + 142) + 2);
            w_u16(object + 142, frame);
            if (frame >= 14) w_u16(object + 142, 13);
            frame = r_s16(object + 142);
            uint32 model = r_u32(object + 48);
            w_u32(model + 40, r_u32(0x800C4828 + (uint32)frame * 4));
            sint32 product = r_s16(object + 142) * r_s16(object + 140);
            sub_800440B8(r_u32(object + 48), (uint32)(sint32)(sint16)(product / 8 + 300));
        }
        w_u32(object + 28, time);
    }
    if (r_s16(object + 142) == 13) return ob_game_800B6C38(object);
    w_u32(object + 92, time + 100);
    return ob_register_effect_object(object + 64);
}

uint32 ob_game_8009AB64(uint32 object, uint32 contact, uint32 time)
{
    FUNCTION_MARKER(0x8009AB64, "GAME.BIN");
    if (r_u32(contact + 28) & 0x8020)
    {
        ob_game_8009A4A8(r_u32(contact + 52), time);
        sub_80047FF0(contact);
        return (uint32)sub_800465E8(r_u32(object + 52), r_u32(contact + 48));
    }
    sub_80047FF0(contact);
    ob_game_800B7EEC(r_u32(object + 44), 0, time);
    return ob_game_800B6C38(object);
}

static uint32 ob_batch8_emit_linked_particle(uint32 object, uint32 time, uint32 secondary)
{
    uint32 locals = ob_draft_scratch_acquire(160);
    ob_game_800B8E40(r_u32(r_u32(object + 156)), locals, time);
    uint32 source = r_u32(object + 156);
    uint32 angle = (uint32)(sint32)(sint16)(r_u16(r_u32(source + 4)) + r_u16(source + 8));
    ob_y_angle_matrix14(angle, locals + 96);
    ob_rotate_matrix_x14(locals + 96, (uint32)r_s16(object + 148), locals + 120);
    ob_main_800285A4(locals + 132, r_u32(object + 152), locals + 32);
    w_u32(locals + 44, secondary ? 0x800C482C : 0x800C4828);
    w_u32(locals + 56, secondary ? 250 : 900);
    w_u8(locals + 95, 1);
    w_u32(locals + 60, 0);
    w_u8(locals + 92, secondary ? 5 : 16);
    if (secondary)
        for (uint32 i = 0; i < 3; ++i)
            w_u32(locals + i * 4, r_u32(locals + i * 4) + (uint32)(r_s32(locals + 32 + i * 4) / 4));
    sint32 size = r_s16(object + 140);
    uint32 low = (uint32)(size / 8 + 300);
    w_u16(locals + 86, low);
    w_u16(locals + 90, low);
    size = r_s16(object + 140);
    w_u16(locals + 88, size * (secondary ? 3 : 14) / 8 + 300);
    w_u8(locals + 93, 4);
    uint32 result = ob_game_80092408(r_u32(0x80083E34), locals, time, 6);
    if (!secondary) w_u32(object + 116, result);
    ob_draft_scratch_release(locals);
    return result;
}

uint32 ob_game_800B9AF4(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800B9AF4, "GAME.BIN");
    return ob_batch8_emit_linked_particle(object, time, 0);
}

uint32 ob_game_800B9C24(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800B9C24, "GAME.BIN");
    return ob_batch8_emit_linked_particle(object, time, 1);
}
