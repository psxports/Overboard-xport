#include "xport.h"
#include "psx.h"
#include "game_signatures.h"
#include "native_extra_signatures.h"
#include "draft_signatures.h"
#include "movie_player.h"

static void ob_batch7_set_contact_motion(uint32 player, uint32 owner, uint32 time)
{
    uint32 slot = (uint32)(sint32)r_s16(owner + 326);
    uint32 heading = r_u16(0x800CBA30 + slot * 104);
    w_u16(r_u32(player + 124) + 4, heading - 0x8000);
    w_u32(r_u32(player + 124), 3500);
    w_u32(r_u32(player + 124) + 8, time + 500);
}

static sint32 ob_batch7_neighbor_height(uint32 query, uint32 direction)
{
    return r_s32(query + r_u32(0x800C5B44 + direction * 4) * 4);
}

uint32 ob_game_800B51B0(uint32 owner, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x800B51B0, "GAME.BIN");
    uint32 player = r_u32(record + 52);
    uint32 data = r_u32(player + 108);
    uint32 locals = ob_draft_scratch_acquire(232);
    uint32 first_position = locals;
    uint32 temporary = locals + 16;
    uint32 query = locals + 32;
    sub_80045A7C(r_u32(owner + 44), time);
    sub_80045A7C(r_u32(player + 44), time);
    uint32 kind = r_u32(record + 24);
    if (kind == 32)
    {
        sub_800453C4(r_u32(player + 44), time, first_position);
        if (r_u8(data + 47) == 1 || r_u32(first_position + 4)) goto finish;
        if (!r_s16(data + 168))
        {
            if (r_u32(owner + 292) != 161) goto finish;
            ob_batch7_set_contact_motion(player, owner, time);
            sub_8004F2C4(r_u32(player + 56), 0);
            ob_main_8004E66C(r_u32(player + 60));
            ob_main_8004E66C(r_u32(r_u32(player + 136) + 60));
            ob_main_8004E66C(r_u32(r_u32(player + 140) + 60));
            if (r_u8(data + 47)) w_u32(data + 36, 1);
            w_u16(data + 172, 0xFFFF);
            w_u16(data + 168, 1);
            w_u16(data + 170, 0xFFFF);
            sub_8004651C(r_u32(player + 52));
            ob_game_800BE604(player, temporary, time);
            w_u16(data + 168, 0);
            sub_800453C4(r_u32(owner + 44), time, locals + 104);
            sub_800458B4(r_u32(player + 44), locals + 104, time);
            w_u32(data + 76, 0);
            w_u32(data + 72, 0);
            w_u32(data + 68, 0);
            goto finish;
        }
        sint32 owner_slot = r_s16(owner + 326);
        if (r_s16(data + 170) == owner_slot)
        {
            ob_batch7_set_contact_motion(player, owner, time);
            sub_80045378(r_u32(owner + 44), time, temporary);
            sub_800458B4(r_u32(player + 44), temporary, time);
            goto finish;
        }
        if (r_u16(0x800CBA36 + (uint32)owner_slot * 104)) goto finish;
        if (r_u32(owner + 292) == 161)
        {
            w_u16(data + 170, (uint32)owner_slot);
            goto finish;
        }
        uint32 position = sub_80045464(r_u32(owner + 44), time);
        sub_8004C64C(position, 1, 1, query);
        uint32 motion = r_u32(player + 124);
        uint32 heading = r_u16(motion + 4);
        uint32 direction = heading >> 14;
        if (ob_batch7_neighbor_height(query, direction) < -1919)
        {
            w_u16(motion + 4, heading - 0x8000);
            uint32 pitch = (ob_draft_unresolved_call(0x8001AFC8, 0) - 128) & 255;
            sub_80011984(0x80066304, 128, 15, 15, pitch, 0, 0);
            goto finish;
        }
        if (ob_batch7_neighbor_height(query, direction ^ 2) >= -1919) goto finish;
        sub_80045378(r_u32(owner + 44), time, locals + 72);
        sub_800458B4(r_u32(player + 44), locals + 72, time);
        sub_80011984(0x80066304, 128, 15, 15, 256, 0, 0);
        uint32 turn;
        if (ob_batch7_neighbor_height(query, (direction - 1) & 3) >= -1919) turn = 0x4000;
        else if (ob_batch7_neighbor_height(query, (direction + 1) & 3) >= -1919) turn = (uint32)-0x4000;
        else turn = (uint32)-0x8000;
        motion = r_u32(player + 124);
        w_u16(motion + 4, r_u16(motion + 4) + turn);
    }
    else if (kind == 16)
    {
        w_u32(data + 76, 0);
        w_u32(data + 72, 0);
        w_u32(data + 68, 0);
        sub_800453C4(r_u32(player + 44), time, temporary);
        if (r_u8(data + 47) == 1 || r_u32(temporary + 4) || r_s16(data + 172) != -1) goto finish;
        if (r_s16(data + 168))
        {
            if (r_s16(data + 170) != r_s16(owner + 326)) goto finish;
            w_u32(r_u32(player + 124), 1500);
            w_u16(data + 168, 0);
            w_u32(r_u32(player + 124) + 8, time + 500);
            w_u8(r_u32(player + 60) + 52, 0);
            w_u8(r_u32(r_u32(player + 136) + 60) + 52, 0);
            w_u8(r_u32(r_u32(player + 140) + 60) + 52, 0);
            w_u16(data + 170, 0xFFFF);
            w_u16(data + 172, 0);
            sub_8004651C(r_u32(player + 52));
            ob_game_800BE604(player, locals + 120, time);
            sub_80011984(0x800660C0, 128, 15, 15, 256, 0, 0);
            sub_80011DE0((uint32)(sint32)r_s16(owner + 306), 128);
            ob_main_8001DE60();
        }
        else if (r_u32(owner + 292) == 161)
        {
            uint32 slot = (uint32)(sint32)r_s16(owner + 326);
            if (r_u16(0x800CBA36 + slot * 104))
            {
                uint32 target = r_u32(0x800CBA48 + slot * 104);
                uint32 position = sub_80045464(r_u32(player + 44), time);
                w_u32(query, r_u32(target + 32));
                w_u32(query + 4, r_u32(target + 36));
                w_u32(query + 8, r_u32(target + 40));
                ob_draft_unresolved_call(0x8004BE08, 1, query);
                uint32 dz = r_u32(target + 40) - r_u32(position + 8);
                uint32 dx = r_u32(target + 32) - r_u32(position);
                sub_80028280((sint32)dz, (sint32)dx, locals + 208, locals + 212);
                uint32 travel = (r_u32(locals + 212) << 10) / 10000;
                w_u16(r_u32(player + 124) + 4, r_u16(locals + 208));
                w_u32(r_u32(player + 124) + 8, time + travel);
                uint32 target_slot = (uint32)((sint32)((target - 0x800CBA00) * 0xC4EC4EC5) >> 3);
                w_u16(data + 170, target_slot);
            }
            else
            {
                w_u16(data + 170, 0xFFFF);
                w_u32(r_u32(player + 124) + 8, time + 100000);
            }
            w_u32(r_u32(player + 124), 10000);
            sint32 motion = r_s32(r_u32(player + 124));
            if (motion <= 0) motion = 1;
            w_u16(data + 168, (uint32)motion);
            sub_80011984(0x800660BC, 128, 15, 15, 256, 0, 0);
            sub_8001DDF8();
            ob_draft_unresolved_call(0x80012164, 1, 127);
            sub_80011DE0((uint32)(sint32)r_s16(owner + 306), 32);
        }
    }
finish:
    uint32 result = (uint32)sub_80047FF0(record);
    ob_draft_scratch_release(locals);
    return result;
}

static uint32 ob_batch7_round_scale8(uint32 value, uint32 scale)
{
    uint32 adjustment = (sint32)value > 0 ? scale >> 1 : (uint32)((sint32)(0 - scale) >> 1);
    uint32 numerator = (value << 8) + adjustment;
    if (!scale) return ob_native_missing_value(0x80040E28, "BREAK 7 render scale division by zero");
    return (uint32)((sint32)numerator / (sint32)scale);
}

uint32 ob_main_80040E28(uint32 object)
{
    FUNCTION_MARKER(0x80040E28, "SLES_008.65");
    if ((sint32)(r_u32(0x800775BC) - r_u32(0x800774A8)) < 64) return 1;
    uint32 matrix = r_u32(object + 28);
    const uint32 transpose[9] = { 0, 6, 12, 2, 8, 14, 4, 10, 16 };
    for (uint32 index = 0; index < 9; ++index)
        w_u16(0x1F800040 + index * 2, (uint32)(r_s16(matrix + transpose[index]) >> 2));
    ob_draft_unresolved_call(0x8005F288, 3, 0x8008C8A8, 0x1F800040, 0x1F800060);
    uint32 first_y = r_u16(0x1F800066);
    uint32 second_y = r_u16(0x1F80006A);
    w_u16(0x1F800066, 0 - first_y);
    uint32 third_y = r_u16(0x1F800068);
    w_u16(0x1F80006A, 0 - second_y);
    w_u16(0x1F800068, 0 - third_y);
    uint32 resource = r_u32(object + 24);
    uint32 value = r_u32(object + 12);
    uint32 scale = r_u16(r_u32(object + 24) + 8);
    w_u32(0x80077598, resource);
    w_u32(0x1F800074, ob_batch7_round_scale8(value, scale));
    for (uint32 axis = 1; axis < 3; ++axis)
    {
        value = r_u32(object + 12 + axis * 4);
        scale = r_u16(r_u32(object + 24) + 8);
        value = ob_batch7_round_scale8(value, scale);
        w_u32(0x1F800074 + axis * 4, axis == 1 ? 0 - value : value);
    }
    for (uint32 axis = 0; axis < 3; ++axis)
    {
        value = r_u32(r_u32(object + 28) + 36 + axis * 4);
        scale = r_u16(resource + 8);
        w_u32(0x1F800088 + axis * 4, ob_batch7_round_scale8(value, scale));
    }
    uint32 maximum = r_u32(0x1F800074);
    if ((sint32)maximum < 0) maximum = 0 - maximum;
    for (uint32 axis = 1; axis < 3; ++axis)
    {
        value = r_u32(0x1F800074 + axis * 4);
        if ((sint32)value < 0) value = 0 - value;
        if (maximum < value) maximum = value;
    }
    uint32 shifts = 0;
    while (maximum >= 0x7FF9)
    {
        maximum >>= 1;
        uint32 x = r_u32(0x1F800074);
        uint32 z = r_u32(0x1F80007C);
        w_u32(0x1F800074, (uint32)((sint32)x >> 1));
        uint32 y = r_u32(0x1F800078);
        w_u32(0x1F80007C, (uint32)((sint32)z >> 1));
        w_u32(0x1F800078, (uint32)((sint32)y >> 1));
        ++shifts;
    }
    uint32 light = ob_draft_scratch_acquire(40);
    ob_draft_unresolved_call(0x8005F288, 3, 0x80088818, 0x1F800040, light);
    ob_draft_unresolved_call(0x8005F3C8, 1, light);
    sub_8005F488(r_u32(r_u32(0x800770C0) + 8));
    if (shifts)
        for (uint32 index = 0; index < 9; ++index)
            w_u16(0x1F800060 + index * 2, (uint32)(r_s16(0x1F800060 + index * 2) >> (shifts & 31)));
    ob_draft_unresolved_call(0x8005F398, 1, 0x1F800060);
    ob_draft_unresolved_call(0x8005F428, 1, 0x1F800060);
    uint32 polygon_index = r_u32(object + 40);
    uint32 polygons = r_u32(resource + 52);
    uint32 vertices = r_u32(resource + 32);
    uint32 feature = r_u16(resource + 18);
    uint32 polygon = r_u32(polygons + polygon_index * 4);
    polygon_index = r_u32(object + 40);
    w_u32(0x80077574, 0x1F800100);
    w_u16(0x800775A6, feature);
    uint32 flags = r_u16(polygon);
    uint32 attributes = r_u16(object + 2);
    uint32 count = r_u16(polygon + 2);
    w_u32(0x80077514, polygon_index);
    w_u16(0x8007748C, attributes);
    uint32 stream_count = r_u16(polygon + 2);
    w_u16(0x80077480, ((attributes & 0x600) >> 2) | (attributes & 0x6000));
    w_u16(0x800775A0, 0xFFFF);
    uint32 offset_count = r_u16(polygon + 2);
    w_u16(0x800774E4, flags);
    w_u16(0x800775B4, count);
    uint32 indices = polygon + stream_count * 2 + 4;
    w_u32(0x80077418, polygon + offset_count * 4 + 4);
    count = r_u16(polygon + 2);
    w_u32(0x80077384, indices);
    uint32 index = 0;
    uint32 destination = 0x1F800190;
    while ((sint32)index < (sint32)count)
    {
        uint32 vertex = vertices + r_u16(indices) * 8;
        indices += 2;
        for (uint32 axis = 0; axis < 3; ++axis)
            w_u16(destination + axis * 2, r_u16(vertex + axis * 2) - r_u32(0x1F800088 + axis * 4));
        ++index;
        destination += 8;
        count = r_u16(polygon + 2);
    }
    uint32 projected = r_u32(0x80077574);
    for (uint32 word = 0; word < 6; ++word) xport_gte_write_data(word, r_u32(projected + 144 + word * 4));
    xport_gte_execute(0x280030);
    w_u32(projected, xport_gte_read_data(12));
    w_u32(projected + 24, xport_gte_read_data(13));
    flags = xport_gte_read_flag();
    w_u32(projected + 48, xport_gte_read_data(14));
    w_u32(0x1F800080, flags);
    uint32 result = r_u32(0x1F800080) & 0x26000;
    uint32 restore_h;
    if (!result)
    {
        if (r_u16(polygon + 2) == 4)
        {
            xport_gte_write_data(0, r_u32(projected + 168));
            xport_gte_write_data(1, r_u32(projected + 172));
            xport_gte_execute(0x180001);
            flags = xport_gte_read_flag();
            w_u32(projected + 72, xport_gte_read_data(14));
            w_u32(0x1F800080, flags);
        }
        uint32 order = r_u32(0x80077350);
        w_u32(0x80077384, 0x80073628);
        uint32 head = r_u32(0x8007737C) + order * 4 + 112;
        w_u32(0x80077634, head);
        uint32 old_link = r_u32(head);
        ob_draft_unresolved_call(0x8003BB2C, 0);
        head = r_u32(0x80077634);
        restore_h = r_u16(0x80077498);
        result = (r_u32(head) & 0xFF000000) | (old_link & 0xFFFFFF);
        w_u32(head, result);
    }
    else restore_h = r_u16(0x80077498);
    sub_8005F488(restore_h);
    ob_draft_scratch_release(light);
    return result;
}

static void ob_batch7_trigger_actor(uint32 trigger, uint32 record, uint32 time)
{
    uint32 kind = r_u32(record + 96);
    if (kind == 158)
    {
        uint32 object = r_u32(record + 80);
        if (object)
        {
            uint32 state = r_u8(trigger + 3);
            uint32 properties = r_u32(object + 112);
            uint32 geometry = r_u32(object + 48);
            w_u32(geometry + 40, r_u32(properties + (state ? 20 : 16)));
        }
    }
    else if (kind == 162)
    {
        uint32 object = r_u32(record + 80);
        if (object)
        {
            uint32 node = (uint32)sub_800437C4(r_u32(r_u32(object + 44) + 12), 0x10086);
            uint32 data = r_u32(object + 108);
            if (!r_u32(data))
            {
                w_u32(data + 4, time + 500);
                w_u32(data, ob_game_800A9D9C(node, 0x3FFE, 0, 0));
            }
            else w_u32(data + 4, r_u32(data + 4) + 500);
            w_u16(data + 10, r_u16(data + 10) - 0x8000);
        }
    }
    else if (kind == 163)
    {
        uint32 object = r_u32(record + 80);
        if (!object) return;
        uint32 node = (uint32)sub_800437C4(r_u32(r_u32(object + 44) + 12), 0x1007B);
        uint32 state = r_u8(trigger + 3);
        uint32 data = r_u32(object + 108);
        if (state)
        {
            uint32 animation = r_u32(data);
            if (animation) ob_game_800A9E48(animation);
            animation = ob_game_800A9D9C(node, 0x3FFE, 0, 0);
            uint32 angle = r_u16(data + 10);
            w_u32(data, animation);
            w_u16(animation + 24, angle);
            angle = r_u16(data + 10);
            w_u32(data + 4, time + 500);
            w_u16(data + 10, angle - 0x8000);
            node = (uint32)sub_800437C4(r_u32(r_u32(object + 44) + 12), 0x1007C);
            animation = r_u32(data + 16);
            if (animation) ob_game_800A9E48(animation);
            sint32 remaining = (sint32)(r_u32(trigger + 8) - time);
            if (!remaining)
            {
                ob_native_missing_value(0x800BA234, "BREAK 7 trigger animation time division by zero");
                return;
            }
            uint32 rate = (uint32)((sint32)0xFF9C0258 / remaining);
            animation = ob_game_800A9D9C(node, 0, rate, 0);
            w_u32(data + 16, animation);
            uint32 voice = ob_main_80011A24(0x800683CC, 255, 256, r_u32(object + 44), time, 1);
            w_u16(object + 306, voice);
            w_u8(object + 341, 255);
        }
        else
        {
            uint32 animation = ob_game_800A9D9C(node, 0xCCC, 0, 0);
            uint32 angle = r_u16(data + 10);
            w_u32(data, animation);
            w_u16(animation + 24, angle);
            angle = r_u16(data + 10);
            w_u32(data + 4, time + 166);
            w_u16(data + 10, angle - 0x8000);
            sub_8001195C((uint32)(sint32)r_s16(object + 306));
            w_u16(object + 306, 0xFFFF);
            ob_main_80011A24(0x800660D4, 255, 256, r_u32(object + 44), time, 0);
            ob_game_800A9E48(r_u32(data + 16));
            w_u32(data + 16, 0);
        }
    }
}

uint32 ob_game_800BA234(uint32 index, uint32 mode, uint32 time)
{
    FUNCTION_MARKER(0x800BA234, "GAME.BIN");
    index &= 255;
    if (!index) return 0;
    uint32 trigger = r_u32(0x80077198) + ((index - 1) & 255) * 16;
    mode &= 255;
    if (mode != 255)
    {
        uint32 required = r_u8(trigger + 1);
        if (required != 3 && required != mode) return 3;
    }
    if (r_u8(trigger + 1) == 3)
    {
        uint32 player = r_u32(0x8006C138);
        if (!player) return 0;
        uint32 data = r_u32(player + 108);
        uint32 group = r_u8(trigger + 5);
        if (r_u8(data + 178) != group) return group;
        sub_80011984(0x800660B8, 128, 15, 15, 256, 0, 0);
        w_u8(data + 178, 0);
    }
    if (r_u8(trigger + 2) >= 7)
    {
        uint32 bounds = ob_draft_scratch_acquire(72);
        uint32 map = r_u32(0x80077644);
        uint32 x = r_u8(trigger + 12) * r_u32(map) - r_u32(0x80077458);
        w_u32(bounds + 56, x);
        w_u32(bounds + 40, x + r_u32(map));
        uint32 z = r_u32(0x80077468) - r_u8(trigger + 13) * r_u32(map);
        w_u32(bounds + 48, z);
        w_u32(bounds + 64, z - r_u32(map));
        sub_8004C2C4(bounds, x, z);
        sint32 minimum = INT32_MAX;
        sint32 maximum = INT32_MIN;
        for (uint32 sample = 0; sample < 9; ++sample)
        {
            sint32 height = r_s32(bounds + sample * 4);
            if (height < minimum) minimum = height;
            if (maximum < height) maximum = height;
        }
        w_u32(bounds + 44, (uint32)maximum);
        w_u32(bounds + 60, (uint32)minimum);
        uint32 blocked = ob_draft_unresolved_call(0x80049FCC, 4, bounds + 56, bounds + 40, 0x182B2, time);
        if (blocked)
        {
            uint32 result = sub_80011984(0x800660D4, 128, 15, 15, 128, 0, 0);
            ob_draft_scratch_release(bounds);
            return result;
        }
        ob_draft_scratch_release(bounds);
    }
    uint32 behavior = r_u8(trigger);
    if (behavior == 1)
    {
        uint32 target = r_u8(trigger + 4);
        uint32 current = r_u8(trigger + 3);
        if (current == target) return current;
        w_u8(trigger + 3, target);
    }
    else if (behavior == 2)
    {
        uint32 current = r_u8(trigger + 3);
        w_u8(trigger + 3, current < r_u8(trigger + 4) ? current + 1 : 0);
    }
    else if (behavior == 3)
    {
        if (mode == 255)
        {
            uint32 current = r_u8(trigger + 3);
            if (!current) return 0xFFFFFFFF;
            --current;
            w_u8(trigger + 3, current);
            if (!(current & 255)) w_u32(trigger + 8, 0);
            else w_u32(trigger + 8, time + r_u8(trigger + 7) * 500);
        }
        else
        {
            uint32 current = r_u8(trigger + 3);
            uint32 limit = r_u8(trigger + 4);
            if (current >= limit) return current + 1;
            uint32 delay = r_u8(trigger + 7);
            w_u8(trigger + 3, current + 1);
            w_u32(trigger + 8, time + delay * 500);
        }
    }
    else if (behavior == 4)
    {
        if (r_u32(trigger + 8) == 1)
        {
            uint32 current = r_u8(trigger + 3);
            if (current < r_u8(trigger + 4)) w_u8(trigger + 3, current + 1);
            else
            {
                w_u8(trigger + 3, current - 1);
                w_u32(trigger + 8, 0xFFFFFFFF);
            }
        }
        else
        {
            uint32 current = r_u8(trigger + 3);
            if (current) w_u8(trigger + 3, current - 1);
            else
            {
                w_u8(trigger + 3, 1);
                w_u32(trigger + 8, 1);
            }
        }
    }
    else return behavior < 3 ? 1 : 4;
    uint32 group = r_u8(trigger + 5);
    uint32 head = r_u32(r_u32(0x8007719C) + group * 4);
    if (head)
    {
        uint32 node = head;
        do
        {
            ob_batch7_trigger_actor(trigger, node, time);
            node = r_u32(node + 72);
            group = r_u8(trigger + 5);
            head = r_u32(r_u32(0x8007719C) + group * 4);
        } while (node != head);
    }
    uint32 action = r_u8(trigger + 2);
    uint32 result = action < 12 ? r_u32(0x8008EB1C + action * 4) : 0;
    switch (action)
    {
    case 1: result = ob_game_800BAC58(trigger, time); break;
    case 2:
        result = mode == 255 ? ob_game_800BADAC(trigger, time) : ob_game_800BAD88(trigger);
        break;
    case 3: result = ob_game_800BADAC(trigger, time); break;
    case 4: result = ob_game_800BB07C(trigger, time); break;
    case 5: ob_game_800BB3C4(); break;
    case 8: result = ob_game_800BAB08(trigger, time); break;
    case 9: case 10: case 11:
    {
        uint32 delta = action - 8;
        if (r_u32(trigger + 8) == 0xFFFFFFFF) delta = 0 - delta;
        result = ob_game_800BABEC(trigger, delta);
        break;
    }
    }
    uint32 next = r_u8(trigger + 6);
    if (next) return ob_game_800BA234(next, mode, time);
    return result;
}

static uint32 ob_batch7_contact_weight(uint32 first, uint32 second)
{
    sint32 difference = (sint16)(first - second);
    if (difference < 0) difference = -difference;
    uint32 value = (uint32)difference;
    if (value < 0x4000) value = 0x8000 - value;
    value = (value - 0x4000) & 0xFFFF;
    return value < 0x800 ? 0x800 : value;
}

static uint32 ob_batch7_heading_gap(uint32 first, uint32 second)
{
    sint32 difference = (sint32)(first & 0x7FFF) - (sint32)(second & 0x7FFF);
    if (difference < 0) difference = -difference;
    uint32 gap = (uint32)difference;
    return gap > 0x4000 ? 0x8000 - gap : gap;
}

uint32 ob_game_800AC6F8(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800AC6F8, "GAME.BIN");
    uint32 counter = r_u32(0x80084444);
    uint32 recorded_id = r_u16(0x800D5DD0);
    uint32 object_id = r_u16(object + 302);
    w_u32(0x80084444, counter + 1);
    uint32 first = recorded_id == object_id ? 0x800D5DD8 : 0x800D5D18;
    uint32 second = recorded_id == object_id ? 0x800D5D18 : 0x800D5DD8;
    uint32 second_resource = r_u32(second + 180);
    uint32 first_resource = r_u32(first + 180);
    uint32 previous = r_u32(object + 280);
    if ((sint32)(time - 4) < (sint32)previous)
    {
        if (r_u16(object + 300) == r_u16(first + 184))
        {
            w_u32(r_u32(object + 124), 0);
            return sub_80045A44(r_u32(object + 44), 0x8006C160);
        }
        w_u32(r_u32(object + 124), 0);
        return sub_80045A44(r_u32(object + 44), 0x8006C160);
    }
    if ((sint32)previous < (sint32)(time - 500))
        ob_main_80011A24(0x80067228, 128, 256, r_u32(object + 44), time, 0);
    uint32 second_heading = r_u16(second + 168);
    if (r_s32(second + 164) < 0) second_heading = (second_heading - 0x8000) & 0xFFFF;
    uint32 first_heading = r_u16(first + 168);
    if (r_s32(first + 164) < 0) first_heading = (first_heading - 0x8000) & 0xFFFF;
    uint32 second_position = sub_80045464(second, time);
    uint32 first_position = sub_80045464(first, time);
    uint32 locals = ob_draft_scratch_acquire(112);
    uint32 difference = locals + 16;
    uint32 transformed = locals + 32;
    uint32 average = locals + 48;
    uint32 matrix = locals + 64;
    uint32 result_matrix = locals + 88;
    uint32 dz = r_u32(first_position + 8) - r_u32(second_position + 8);
    uint32 dx = r_u32(first_position) - r_u32(second_position);
    sub_80028280((sint32)dz, (sint32)dx, locals, locals + 4);
    uint32 heading = r_u16(locals);
    uint32 opposite = (heading + 0x8000) & 0xFFFF;
    uint32 gap = ob_batch7_heading_gap(second_heading, first_heading);
    uint32 reverse_gap = ob_batch7_heading_gap(first_heading, second_heading);
    uint32 side = (r_u16(second + 168) - heading + 0x4000) & 0xFFFF;
    uint32 weight = ob_batch7_contact_weight(second_heading, heading);
    uint32 other_weight = ob_batch7_contact_weight(first_heading, opposite);
    if (gap > 0x3800 && weight > 0x3800)
    {
        gap = (gap + ((0x4000 - gap) >> 1)) & 0xFFFF;
        weight = (weight + ((0x4000 - weight) >> 1)) & 0xFFFF;
    }
    if (reverse_gap > 0x3800 && other_weight > 0x3800)
    {
        reverse_gap = (reverse_gap + ((0x4000 - reverse_gap) >> 1)) & 0xFFFF;
        other_weight = (other_weight + ((0x4000 - other_weight) >> 1)) & 0xFFFF;
    }
    w_u32(difference + 4, 0);
    w_u32(difference, r_u32(second + 132) - r_u32(first + 132));
    w_u32(difference + 8, r_u32(second + 140) - r_u32(first + 140));
    w_u32(average + 4, 0);
    w_u32(average, (uint32)((sint32)(r_u32(second + 132) + r_u32(first + 132)) >> 1));
    w_u32(average + 8, (uint32)((sint32)(r_u32(second + 140) + r_u32(first + 140)) >> 1));
    sint32 heading_sum = r_s16(second + 168) + r_s16(first + 168);
    sub_80029F58((uint32)(heading_sum >> 1), matrix);
    /* TODO Bind the missing inverse-vector adapter at its original call boundary */
    ob_draft_unresolved_call(0x80029CD0, 3, average, matrix, transformed);
    uint32 local_matrix = (uint32)sub_80045430((sint32)second);
    ob_draft_unresolved_call(0x80029CD0, 3, difference, local_matrix, transformed);
    uint32 speed_z = r_u32(transformed + 8);
    sint32 product = (sint32)((gap - 0x2000) * speed_z);
    uint32 impulse = speed_z + (uint32)(product / 65536);
    uint32 first_mass = r_u8(first_resource + 42);
    uint32 second_mass = r_u8(second_resource + 42);
    uint32 scaled = impulse;
    if (first_mass < second_mass)
    {
        product = (sint32)((uint32)(sint32)(sint16)impulse * first_mass);
        if (!second_mass) return ob_native_missing_value(0x800AC6F8, "BREAK 7 collision mass division by zero");
        scaled = (uint32)(product / (sint32)second_mass);
    }
    product = (sint32)((uint32)(sint32)(sint16)scaled * weight);
    sint32 magnitude = product / 16384;
    if (magnitude < 0) magnitude = -magnitude;
    if ((sint16)magnitude <= 0) magnitude = 1;
    uint32 motion = r_u32(object + 124);
    if (side & 0x8000)
    {
        w_u32(motion, r_u32(motion) + (uint32)(sint32)(sint16)magnitude);
        motion = r_u32(object + 124);
        if (r_s32(motion) >= 3001) w_u32(motion, 3000);
    }
    else
    {
        w_u32(motion, r_u32(motion) - (uint32)(sint32)(sint16)magnitude);
        motion = r_u32(object + 124);
        if (r_s32(motion) < -2000) w_u32(motion, (uint32)-2000);
    }
    sint32 duration = (sint16)magnitude >> 3;
    motion = r_u32(object + 124);
    if (duration < 25) duration = 25;
    duration = (sint16)duration;
    if (duration >= 401) duration = 400;
    w_u32(motion + 8, time + (uint32)duration);
    uint32 damping = (r_u8(second_resource + 43) + r_u8(first_resource + 43)) >> 1;
    if (damping > 128)
    {
        motion = r_u32(object + 124);
        product = (sint32)(r_u32(motion) * (256 - damping));
        w_u32(motion, (uint32)(product >> 7));
    }
    else if (damping < 128)
    {
        motion = r_u32(object + 124);
        uint32 old_speed = r_u32(second + 164);
        uint32 current_speed = r_u32(motion);
        uint32 delta = current_speed - old_speed;
        if ((sint32)delta < 0) delta = old_speed - current_speed;
        uint32 minimum = (sint32)old_speed < (sint32)current_speed ? old_speed : current_speed;
        product = (sint32)(delta * (128 - damping));
        w_u32(motion, (uint32)(product >> 7) + minimum);
        w_u32(r_u32(object + 124) + 8, 0);
    }
    motion = r_u32(object + 124);
    uint32 speed = r_u32(motion);
    uint32 adjusted_heading = r_u16(motion + 4);
    if ((sint32)speed < 0) adjusted_heading = (adjusted_heading - 0x8000) & 0xFFFF;
    sint32 threshold = (sint16)(gap < 0x2000 ? gap + 0x2000 : 0x6000 - gap);
    uint32 turn = (sint32)weight < threshold ? weight : 0x4000 - weight;
    turn = (uint32)((sint16)turn / 3);
    uint32 heading_delta = heading - adjusted_heading;
    damping = (r_u8(first_resource + 43) + r_u8(second_resource + 43)) >> 1;
    if (damping > 128)
    {
        product = (sint32)((uint32)(sint32)(sint16)turn * (256 - damping));
        w_u32(r_u32(object + 124) + 8, 0);
        turn = (uint32)product >> 7;
    }
    uint32 add_turn = gap >= 0x3000 ? (heading_delta & 0x4000) : (heading_delta & 0x8000);
    motion = r_u32(object + 124);
    uint32 angle = r_u16(motion + 4);
    w_u16(motion + 4, add_turn ? angle + turn : angle - turn);
    ob_main_80045410(r_u32(object + 44), average);
    w_u32(transformed + 4, 0);
    w_u32(transformed, 0);
    w_u32(transformed + 8, r_u32(r_u32(object + 124)));
    sub_80029F58((uint32)(sint32)r_s16(r_u32(object + 124) + 4), result_matrix);
    sub_80029B70(transformed, result_matrix, average);
    uint32 quadrant = (r_u16(locals) + 0x2000) & 0xC000;
    if (quadrant == 0 && r_s32(average + 8) > 0) w_u32(average + 8, 0);
    else if (quadrant == 0x4000 && r_s32(average) > 0) w_u32(average, 0);
    else if (quadrant == 0x8000 && r_s32(average + 8) < 0) w_u32(average + 8, 0);
    else if (quadrant == 0xC000 && r_s32(average) < 0) w_u32(average, 0);
    uint32 result = sub_80045A44(r_u32(object + 44), average);
    ob_draft_scratch_release(locals);
    return result;
}

static void ob_batch7_polygon_light(uint32 normal, uint32 color)
{
    xport_gte_write_data(0, r_u32(normal));
    xport_gte_write_data(1, r_u32(normal + 4));
    xport_gte_write_data(6, r_u32(color));
    xport_gte_execute(0x108041B);
}

static void ob_batch7_link_flat(uint32 packet, uint32 size)
{
    uint32 head = r_u32(0x80077634);
    uint32 cursor = r_u32(0x800774A8);
    w_u32(0x80077634, packet);
    uint32 tag = r_u32(head);
    w_u32(0x800774A8, cursor + size);
    w_u32(head, (tag & 0xFF000000) | (packet & 0xFFFFFF));
}

static uint32 ob_batch7_link_polygon(uint32 size)
{
    uint32 head = r_u32(0x80077634);
    uint32 packet = r_u32(0x800774A8);
    uint32 tag = r_u32(head);
    w_u32(0x800774A8, packet + size);
    w_u32(0x80077634, packet);
    w_u32(head, (tag & 0xFF000000) | (packet & 0xFFFFFF));
    return packet;
}

static uint32 ob_batch7_texture_polygon(uint32 size, uint32 page)
{
    if (!(r_u16(0x800774E4) & 0x200)) return ob_batch7_link_polygon(size);
    uint32 head = r_u32(0x80077634);
    uint32 mode_packet = r_u32(0x800774A8);
    uint32 stream = r_u32(0x80077418);
    uint32 tag = r_u32(head);
    w_u32(0x800774A8, mode_packet + 12);
    w_u32(0x80077634, mode_packet);
    w_u32(head, (tag & 0xFF000000) | (mode_packet & 0xFFFFFF));
    uint32 rectangle = ob_draft_scratch_acquire(8);
    for (uint32 index = 0; index < 4; ++index) w_u16(rectangle + index * 2, r_u8(stream + 12 + index));
    /* TODO Bind SetDrawMode with its required fifth texture-window argument */
    ob_draft_unresolved_call(0x8005D398, 5, mode_packet, 0, 1, page & 0xFFFF, rectangle);
    ob_draft_scratch_release(rectangle);
    uint32 packet = r_u32(0x800774A8);
    head = r_u32(0x80077634);
    uint32 restore = packet + size;
    tag = r_u32(head);
    w_u32(0x800774A8, restore);
    w_u32(0x800774A8, restore + 12);
    w_u32(0x80077634, packet);
    w_u32(0x80077634, restore);
    w_u32(head, (tag & 0xFF000000) | (packet & 0xFFFFFF));
    tag = r_u32(packet);
    w_u32(restore, 0x02000000);
    w_u32(restore + 4, 0xE1000200);
    w_u32(restore + 8, 0xE2000000);
    w_u32(packet, (tag & 0xFF000000) | (restore & 0xFFFFFF));
    return packet;
}

void ob_main_8003D20C(void)
{
    FUNCTION_MARKER(0x8003D20C, "SLES_008.65");
    uint32 anchor = r_u32(0x800774C0);
    w_u8(0x1F80003C, 127);
    w_u8(0x1F80003D, 127);
    w_u8(0x1F80003E, 127);
    uint32 attributes = r_u16(0x8007748C);
    uint32 normals = r_u32(r_u32(0x80077598) + 44);
    if (attributes & 0x3F)
    {
        ob_main_8003DCDC(r_u32(0x80077394));
        return;
    }
    uint32 flags = r_u16(0x800774E4);
    uint32 format;
    if (flags & 1) format = 1;
    else if (flags & 4) format = 4;
    else if (flags & 2) format = 2;
    else return;
    uint32 count = r_u16(0x800775B4);
    uint32 page = format == 2 ? r_u32(0x800775E8) : 0;
    if (!count) return;
    uint32 used = 0;
    uint32 fan = 0;
    uint32 cursor = anchor + (format == 1 ? 32 : format == 4 ? 44 : 40);
    do
    {
        uint32 remaining = count - used + fan;
        uint32 quad = (sint32)remaining >= 4;
        if ((sint32)remaining < 3) used += 100;
        else if (format == 1)
        {
            flags = r_u16(0x800774E4);
            uint32 packet = r_u32(0x800774A8);
            if (quad && (flags & 0x4000)) w_u32(packet + 4, 0xFFFFFF);
            else if (flags & 0x80)
                ob_batch7_polygon_light(normals + r_u32(0x80077514) * 12, r_u32(0x80077394) + 4);
            else w_u32(packet + 4, r_u32(r_u32(0x80077394) + 4));
            ob_batch7_link_flat(packet, quad ? 24 : 20);
            w_u32(packet + 8, r_u32(anchor));
            w_u32(packet + 12, r_u32(cursor - 16));
            if (quad)
            {
                w_u32(packet + 20, r_u32(cursor));
                w_u32(packet + 16, r_u32(cursor + 16));
            }
            else w_u32(packet + 16, r_u32(cursor));
            flags = r_u16(0x800774E4);
            cursor += quad ? 48 : 32;
            if (flags & 0x80) w_u32(packet + 4, xport_gte_read_data(22));
            w_u8(packet + 3, quad ? 5 : 4);
            w_u8(packet + 7, (quad ? 0x28 : 0x20) | ((flags & 0x100) ? 2 : 0));
            used += fan ? (quad ? 2 : 1) : (quad ? 3 : 2);
        }
        else if (format == 4)
        {
            uint32 packet = ob_batch7_link_polygon(quad ? 36 : 28);
            w_u32(packet + 8, r_u32(anchor));
            w_u32(packet + 4, r_u32(anchor + 12));
            w_u32(packet + 16, r_u32(cursor - 28));
            w_u32(packet + 12, r_u32(cursor - 16));
            if (quad)
            {
                w_u32(packet + 32, r_u32(cursor - 12));
                w_u32(packet + 28, r_u32(cursor));
                w_u32(packet + 24, r_u32(cursor + 4));
                w_u32(packet + 20, r_u32(cursor + 16));
            }
            else
            {
                w_u32(packet + 24, r_u32(cursor - 12));
                w_u32(packet + 20, r_u32(cursor));
            }
            flags = r_u16(0x800774E4);
            cursor += quad ? 48 : 32;
            w_u8(packet + 3, quad ? 8 : 6);
            w_u8(packet + 7, (quad ? 0x38 : 0x30) | ((flags & 0x100) ? 2 : 0));
            used += fan ? (quad ? 2 : 1) : (quad ? 3 : 2);
        }
        else
        {
            uint32 packet = ob_batch7_texture_polygon(quad ? 40 : 32, page);
            if (r_u16(0x800774E4) & 0x80)
                ob_batch7_polygon_light(normals + r_u32(0x80077514) * 12, 0x1F80003C);
            else w_u32(packet + 4, 0x7F7F7F);
            w_u32(packet + 8, r_u32(anchor));
            w_u16(packet + 12, r_u16(anchor + 8));
            w_u32(packet + 16, r_u32(cursor - 24));
            w_u16(packet + 20, r_u16(cursor - 16));
            if (quad)
            {
                w_u32(packet + 32, r_u32(cursor - 8));
                w_u16(packet + 36, r_u16(cursor));
                w_u32(packet + 24, r_u32(cursor + 8));
                uint32 uv = r_u16(cursor + 16);
                w_u16(packet + 22, page);
                w_u16(packet + 28, uv);
            }
            else
            {
                w_u32(packet + 24, r_u32(cursor - 8));
                uint32 uv = r_u16(cursor);
                w_u16(packet + 22, page);
                w_u16(packet + 28, uv);
            }
            flags = r_u16(0x800774E4);
            w_u16(packet + 14, page >> 16);
            cursor += quad ? 48 : 32;
            if (flags & 0x80) w_u32(packet + 4, xport_gte_read_data(22));
            w_u8(packet + 3, quad ? 9 : 7);
            w_u8(packet + 7, (quad ? 0x2C : 0x24) | ((flags & 0x100) ? 2 : 0));
            used += fan ? (quad ? 2 : 1) : (quad ? 3 : 2);
        }
        if (!fan) fan = 1;
        count = r_u16(0x800775B4);
        cursor -= 16;
    } while ((sint32)used < (sint32)count);
}

static uint32 ob_batch7_contact_component(uint32 record, uint32 offset)
{
    return (uint16)(-r_s16(record + offset) / 256);
}

static uint32 ob_batch7_contact_impulse(uint32 object, uint32 record, uint32 time, uint32 minimum)
{
    uint32 xy = ob_batch7_contact_component(record, 16) | (ob_batch7_contact_component(record, 18) << 16);
    uint32 z = ob_batch7_contact_component(record, 20);
    /* Only the low half of the third argument is consumed */
    return ob_game_800B2150(object, xy, z, time, minimum);
}

uint32 ob_game_800B271C(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x800B271C, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    uint32 flags = r_u32(record + 28);
    uint32 source = r_u32(record + 52);
    uint32 data = r_u32(object + 108);
    if (flags & 0x18904400)
    {
        if (!r_s8(0x8008AE6A))
        {
            uint32 state = r_u32(object + 288);
            if (state != 21 && state != 23 && r_u8(data + 46) != 3)
            {
                uint32 slot = (uint32)(sint32)r_s16(object + 326) * 104;
                if (r_u16(0x800CBA46 + slot))
                {
                    sint32 damage = (sint16)ob_game_800B8FBC(object, source);
                    if (ob_game_800A52C4(object, (uint32)damage, 0xFFFFFFFF))
                    {
                        state = r_u32(object + 288);
                        if (state != 3 && state != 20)
                        {
                            ob_game_800B9584(r_u32(object + 44), 600, 6, time);
                            ob_main_80011A24(0x800666C0, 255, 256, r_u32(object + 44), time, 0);
                            ob_game_800B3210(object, time);
                        }
                    }
                }
            }
        }
        w_u32(object + 284, time);
        ob_game_800997F4();
        goto release_record;
    }
    if (flags & 0x40)
    {
        ob_game_800B372C(source, object, time);
        goto release_record;
    }
    if (flags & 0x18100)
    {
        if (flags & 0x10000)
        {
            if (!r_s8(0x8008AE6A))
            {
                uint32 state = r_u32(object + 288);
                if (state != 21 && state != 23 && r_u8(data + 46) != 3)
                {
                    uint32 slot = (uint32)(sint32)r_s16(object + 326) * 104;
                    if (r_u16(0x800CBA46 + slot) && ob_game_800A52C4(object, 20, 0xFFFFFFFF))
                    {
                        state = r_u32(object + 288);
                        if (state != 3 && state != 20) ob_game_800B3210(object, time);
                    }
                }
            }
            sub_80047FF0(record);
            uint32 xy = ob_batch7_contact_component(record, 16) | (ob_batch7_contact_component(record, 18) << 16);
            uint32 z = ob_batch7_contact_component(record, 20);
            ob_game_800B31B4(object, data, time);
            return ob_game_800B2150(object, xy, z, time, 4000);
        }
        ob_game_800AC640(object, 1);
        sub_80047FF0(record);
        ob_game_800AC6F8(object, time);
        if (!(r_u32(record + 28) & 0x20040000) && r_u32(object + 128) && !r_u32(source + 128))
            ob_game_8009A4A8(source, time);
        w_u32(object + 280, time);
        w_u16(object + 300, r_u16(source + 302));
        ob_game_800B31B4(object, data, time);
        goto finish;
    }
    if (flags & 0x24)
    {
        sub_80047FF0(record);
        uint32 xy = ob_batch7_contact_component(record, 16) | (ob_batch7_contact_component(record, 18) << 16);
        uint32 z = ob_batch7_contact_component(record, 20);
        ob_game_800B31B4(object, data, time);
        ob_game_800B2150(object, xy, z, time, 0);
        if (!(r_u32(record + 28) & 4) && r_u32(object + 128) && !r_u32(source + 128))
            ob_game_8009A4A8(source, time);
        goto finish;
    }
    if (flags & 0x20040000)
    {
        w_u32(object + 280, time);
        w_u16(object + 300, r_u16(source + 302));
        sub_80047FF0(record);
        uint32 xy = ob_batch7_contact_component(record, 16) | (ob_batch7_contact_component(record, 18) << 16);
        uint32 z = ob_batch7_contact_component(record, 20);
        uint32 minimum = 4000;
        if (r_u32(source + 292) == 13)
        {
            ob_game_800B31B4(object, data, time);
            minimum = 8000;
        }
        ob_game_800B2150(object, xy, z, time, minimum);
        goto finish;
    }
    if (flags & 2)
    {
        ob_game_800AC640(object, 1);
        sub_80047FF0(record);
        ob_game_800AC6F8(object, time);
        w_u32(object + 280, time);
        w_u16(object + 300, r_u16(source + 302));
        goto finish;
    }
    if (flags & 0x400200)
    {
        sub_80047FF0(record);
        uint32 player = r_u32(object + 124);
        uint32 index = ((r_u16(player + 4) + 8) >> 4) * 2;
        sint32 product = (sint32)(r_u32(player) * (uint32)(sint32)r_s16(0x8006C304 + index));
        w_u32(data + 52, (uint32)(product / 16384));
        player = r_u32(object + 124);
        index = ((r_u16(player + 4) + 8) >> 4) * 2;
        product = (sint32)(r_u32(player) * (uint32)(sint32)r_s16(0x8006CB04 + index));
        w_u32(data + 60, (uint32)(product / 16384));
        w_u16(data + 48, r_u16(r_u32(object + 124) + 4));
        if (r_u32(record + 28) & 0x200)
        {
            uint32 kind = r_u32(source + 292);
            uint32 rate = 8;
            uint32 minimum = 0;
            if (kind == 36 || kind == 32)
            {
                rate = 0;
                minimum = 3000;
            }
            else if (kind == 38)
            {
                uint32 parent_kind = r_u32(r_u32(r_u32(source + 108)) + 292);
                if (parent_kind == 36 || parent_kind == 33) rate = 0;
                else if (parent_kind == 159)
                {
                    rate = 32;
                    minimum = 3000;
                }
            }
            else if (kind == 39) rate = 0;
            if (!r_s8(0x8008AE6A) || r_u8(data + 46) != 3)
            {
                if (ob_game_800A52C4(object, rate, 0xFFFFFFFF))
                {
                    uint32 state = r_u32(object + 288);
                    if (state != 3 && state != 20) ob_game_800B3210(object, time);
                }
            }
            uint32 xy = ob_batch7_contact_component(record, 16) | (ob_batch7_contact_component(record, 18) << 16);
            uint32 z = ob_batch7_contact_component(record, 20);
            if (r_u32(source + 292) != 36) ob_game_800B31B4(object, data, time);
            ob_game_800B2150(object, xy, z, time, minimum);
        }
        else
        {
            uint32 position = ob_draft_scratch_acquire(12);
            sub_800453C4(r_u32(object + 44), time, position);
            uint32 contact = r_u8(data + 47) == 1 || r_u32(position + 4) != 0;
            ob_draft_scratch_release(position);
            if (contact && r_u32(record + 24) == 32)
                ob_batch7_contact_impulse(object, record, time, 30000);
        }
        ob_game_800B3AD0(object, data + 48, data + 52);
        goto finish;
    }
    if (flags & 0x2000000)
    {
        sub_80047FF0(record);
        uint32 kind = r_u32(source + 292);
        if (kind == 11)
        {
            uint32 slot = (uint32)(sint32)r_s16(object + 326) * 104;
            if (r_u16(0x800CBA46 + slot) >= 31 && !r_s8(0x8008AE6A))
            {
                /* TODO: Bind the absent MAIN random adapter */
                ob_draft_unresolved_call(0x8001AFC8, 0);
                slot = (uint32)(sint32)r_s16(object + 326) * 104;
                w_u8(0x800CBA3A + slot, 17);
                ob_game_800A6C34(object, 17, time);
                uint32 state = r_u32(object + 288);
                if (state != 21 && state != 23) ob_game_800A52C4(object, 15, 0xFFFFFFFF);
            }
        }
        else if (kind == 239)
        {
            sub_80011984(0x800660BC, 128, 15, 15, 256, 0, 0);
            ob_game_8009A704(object);
        }
        goto finish;
    }
release_record:
    sub_80047FF0(record);
finish:
    if (!r_u16(0x800CBA46 + (uint32)(sint32)r_s16(object + 326) * 104) && r_u32(object + 288) != 3)
        return ob_game_800B3210(object, time);
    return 3;
}

static void ob_batch7_apply_heading(uint32 object, uint32 allow_child)
{
    uint32 matrix = ob_draft_scratch_acquire(24);
    sub_80029F58((uint32)(sint32)r_s16(object + 296), matrix);
    uint32 child = allow_child ? r_u32(r_u32(object + 48) + 32) : 0;
    if (child)
    {
        sub_80045848(r_u32(child + 52), matrix);
        sub_80045B74(r_u32(r_u32(r_u32(object + 48) + 32) + 52));
    }
    else
    {
        sub_80045848(r_u32(object + 44), matrix);
        sub_80045B74(r_u32(object + 44));
    }
    ob_draft_scratch_release(matrix);
}

static void ob_batch7_advance_heading(uint32 object, uint32 data, uint32 elapsed, uint32 fixed_rate)
{
    uint32 direction = r_u32(data + 12);
    if (direction == 0 || direction == 1)
    {
        uint32 change = (fixed_rate ? 8 : r_u32(data + 16)) * elapsed;
        uint32 angle = r_u16(object + 296);
        w_u16(object + 296, direction == 0 ? angle + change : angle - change);
    }
    ob_batch7_apply_heading(object, 1);
}

static uint32 ob_batch7_heading_height(uint32 object, uint32 time)
{
    uint32 position = ob_draft_scratch_acquire(12);
    sub_80045378(r_u32(object + 44), time, position);
    uint32 height = r_u32(position + 4);
    ob_draft_scratch_release(position);
    return height;
}

uint32 ob_game_800A7F88(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800A7F88, "GAME.BIN");
    uint32 slot = (uint32)(sint32)r_s16(object + 326) * 104;
    if (ob_game_800C1944(0x800CBA00 + slot) == 1) return 250;
    uint32 elapsed = time - r_u32(object + 28);
    uint32 kind = r_u32(object + 292);
    uint32 definition = r_u32(object + 112);
    uint32 data = r_u32(object + 108);
    switch (kind)
    {
    case 15:
    {
        ob_batch7_apply_heading(object, 0);
        if (ob_batch7_heading_height(object, time)) return 100;
        uint32 angle = ob_game_800A8A40(object, r_u32(0x8006C134), time);
        uint32 weapon = (uint16)(angle + 0x5555) < 0x5556 ? 1 : ((angle & 0xFFFF) >= 0x5556 ? 2 : 0);
        w_u8(r_u32(object + 120) + 112, weapon);
        ob_game_800B5CB4(object, 0, 0, time);
        return 100;
    }
    case 16:
        w_u16(object + 296, r_u16(object + 296) + (elapsed << 3));
        ob_batch7_apply_heading(object, 0);
        if (ob_batch7_heading_height(object, time)) return 200;
        if ((sint32)time % 5000 < 3001) return 200;
        if (ob_game_800B5C50(0, r_u32(object + 120), time)) ob_game_800B5CB4(object, 0, 0, time);
        return 200;
    case 48:
    {
        uint32 direction = r_u32(data + 12);
        if (direction == 0)
        {
            w_u8(r_u32(object + 120) + 112, r_u8(data + 1));
            sint32 last = r_u8(definition + 40) - 1;
            uint32 current = r_u8(data + 1);
            w_u8(data + 1, (sint32)current < last ? current + 1 : 0);
        }
        else if (direction == 1)
        {
            w_u8(r_u32(object + 120) + 112, r_u8(data + 1));
            uint32 current = r_u8(data + 1);
            w_u8(data + 1, current ? current - 1 : r_u8(definition + 40) - 1);
        }
        goto fire_interval;
    }
    case 50:
    {
        sint32 angle = (sint16)ob_game_800A8A40(object, r_u32(0x8006C134), time);
        w_u8(r_u32(object + 120) + 112, ((angle + 4096) / 8192 + 3) & 7);
        goto fire_interval;
    }
    case 52:
    {
        w_u8(r_u32(object + 120) + 112, r_u8(data + 1));
        if (r_s32(data + 8) < (sint32)time)
        {
            if (r_u8(data))
            {
                uint32 result = r_u32(data + 24);
                uint32 duration = r_u32(data + 24);
                w_u8(data, 0);
                w_u32(data + 8, time + duration);
                return result;
            }
            uint32 duration = r_u32(data + 20);
            w_u8(data, 1);
            w_u32(data + 8, time + duration);
        }
        if (r_u8(data + 2))
        {
            uint32 current = r_u8(data + 1);
            if (current) w_u8(data + 1, current - 1);
            else w_u8(data + 2, 0);
        }
        else
        {
            uint32 current = r_u8(data + 1);
            if ((sint32)current == r_u8(definition + 40) - 1) w_u8(data + 2, 1);
            else w_u8(data + 1, current + 1);
        }
        goto fire_interval;
    }
    case 54: case 74:
        if (r_s32(data + 8) < (sint32)time)
        {
            if (r_u8(data)) goto stop_sound;
            uint32 duration = r_u32(data + 20);
            w_u8(data, 1);
            w_u32(data + 8, time + duration);
            uint32 voice = ob_main_80011A24(0x8006725C, 255, 256, r_u32(object + 44), time, 1);
            w_u16(object + 306, voice);
            w_u8(object + 341, 255);
        }
        ob_game_800B5CB4(object, 0, 0, time);
        return 100;
    case 56:
        if ((sint32)elapsed > 0) ob_batch7_advance_heading(object, data, elapsed, 0);
        ob_game_800B5CB4(object, 0, 0, time);
        return 100;
    case 58:
        if ((sint32)elapsed > 0) ob_batch7_advance_heading(object, data, elapsed, 0);
        ob_game_800B5CB4(object, 0, 0, time);
        ob_game_800B5CB4(object, 1, 0, time);
        return 100;
    case 60:
    {
        uint32 state = r_u8(data);
        if (state == 0)
        {
            uint32 excess = time - r_u32(data + 8);
            if ((sint32)excess > 0) elapsed -= excess;
            if ((sint32)elapsed > 0) ob_batch7_advance_heading(object, data, elapsed, 1);
            if (r_s32(data + 8) >= (sint32)time) return 100;
            uint32 duration = r_u32(data + 20);
            w_u8(data, 1);
            w_u32(data + 8, time + duration);
        }
        else if (state != 1) return 250;
        for (uint32 index = 0; index < 4; ++index)
        {
            w_u8(r_u32(object + 120) + 112, index);
            ob_game_800B5CB4(object, 0, 0, time);
        }
        if (r_s32(data + 8) >= (sint32)time) return r_u32(data + 16);
        w_u8(data, 0);
        w_u32(data + 8, time + 1024);
        return 100;
    }
    case 62: case 72:
    {
        uint32 state = r_u8(data);
        if (state == 0)
        {
            if ((sint32)elapsed > 0)
            {
                sint32 rate = (sint16)ob_game_800A8ADC(object, time);
                if (rate)
                {
                    w_u16(object + 296, r_u16(object + 296) + (uint32)rate * elapsed);
                    ob_batch7_apply_heading(object, 1);
                    return 100;
                }
            }
            uint32 duration = r_u32(data + 20);
            w_u8(data, 1);
            w_u32(data + 8, time + duration);
        }
        else if (state != 1) return 250;
        if (r_s32(data + 8) < (sint32)time)
        {
            w_u8(data, 0);
            return 100;
        }
        goto fire_interval;
    }
    case 64:
        if (r_u32(r_u32(object + 48) + 32))
        {
            w_u16(object + 296, r_u16(object + 296) + (elapsed << 3));
            ob_batch7_apply_heading(object, 1);
        }
        ob_game_800B5CB4(object, 0, 0, time);
        return 200;
    case 66: case 75:
        if (r_s32(data + 8) < (sint32)time)
        {
            if (r_u8(data)) goto stop_sound;
            uint32 duration = r_u32(data + 20);
            w_u8(data, 1);
            w_u32(data + 8, time + duration);
            uint32 voice = ob_main_80011A24(0x80067254, 255, 256, r_u32(object + 44), time, 1);
            w_u16(object + 306, voice);
            w_u8(object + 341, 255);
        }
        if (r_u8(data) == 1) ob_game_800B5CB4(object, 0, 0, time);
        return 200;
    case 70: case 77:
        goto fire_interval;
    default:
        return 250;
    }
fire_interval:
    ob_game_800B5CB4(object, 0, 0, time);
    return r_u32(data + 16);
stop_sound:
    w_u8(data, 0);
    w_u32(data + 8, time + r_u32(data + 24));
    sub_8001195C((uint32)(sint32)r_s16(object + 306));
    w_u16(object + 306, 0xFFFF);
    return r_u32(data + 24);
}

static void ob_batch7_result_glyph(uint32 kind, uint32 x, uint32 y, uint32 time, uint32 direction)
{
    ob_main_8001C148((uint32)(sint32)(sint16)kind, (uint32)(sint32)(sint16)x,
        (uint32)(sint32)(sint16)y, time, direction);
}

static void ob_batch7_result_row(const sint32 *kinds, const sint32 *offsets, uint32 count, uint32 scale, uint32 vertical, uint32 time, uint32 first_delay, uint32 direction)
{
    for (uint32 index = 0; index < count; ++index)
        ob_batch7_result_glyph(kinds[index], 192 + (uint32)offsets[index] * scale,
            128 + vertical * r_u32(0x8006C174), time + first_delay + index * 100, direction);
}

void ob_main_8001B060(uint32 time)
{
    FUNCTION_MARKER(0x8001B060, "SLES_008.65");
    sint32 state = r_s16(0x80076880);
    uint32 scale = r_u32(0x8006C174);
    switch (state)
    {
    case 0: case 1:
    {
        if (r_u8(0x8006C231) >= 20)
        {
            uint32 resource = r_u32(0x8008CEBC);
            w_u32(0x800843D0, resource);
            w_u32(0x8007FAD0, resource);
        }
        uint32 players = r_u8(0x8006C230);
        w_u32(0x800771F8, 0xFFFFFFFF);
        w_u32(0x800771FC, 0xFFFFFFFF);
        w_u32(0x80077204, 0xFFFFFFFF);
        w_u8(0x8008AE6A, 1);
        w_u32(0x80077200, 10000);
        w_u32(0x800774B0, time);
        w_u32(0x80077208, time);
        w_u16(0x80077084, 0);
        if (players == 1)
        {
            w_u16(0x80076880, 3);
            break;
        }
        uint32 ordinal = 0;
        if (players)
        {
            uint32 index = 0;
            do
            {
                uint32 object = r_u32(0x8006C138 + index * 4);
                if (object)
                {
                    uint32 slot = (uint32)(sint32)r_s16(object + 326) * 104;
                    if (r_u16(0x800CBA46 + slot))
                    {
                        uint32 data = r_u32(object + 108);
                        uint32 score = (r_u8(data + 44) + 1) & 255;
                        w_u8(data + 44, score);
                        if ((sint32)score >= r_s8(0x8006C246)) w_u32(0x800771F8, ordinal);
                        w_u32(0x800771FC, ordinal);
                        w_u32(0x80077204, index);
                    }
                    ++ordinal;
                }
                ++index;
                players = r_u8(0x8006C230);
            } while ((sint32)index < (sint32)players);
        }
        if (r_s16(0x80076880))
        {
            static const sint32 kinds[] = {12, 4, 6, 3, 8, 14, 3, 10, 21};
            static const sint32 offsets[] = {-140, -110, -89, -56, 0, 26, 56, 84, 112};
            ob_batch7_result_row(kinds, offsets, 9, scale, (uint32)-256, time, 200, 0);
        }
        else
        {
            static const sint32 kinds[] = {10, 8, 13, 7, 2, 8, 14, 3, 10, 21};
            static const sint32 offsets[] = {-154, -126, -98, -67, -35, 14, 40, 70, 98, 126};
            ob_batch7_result_row(kinds, offsets, 10, scale, (uint32)-256, time, 100, 0);
        }
        if (r_u32(0x800771FC) == 0xFFFFFFFF)
        {
            static const sint32 kinds[] = {2, 10, 0, 15, 21};
            static const sint32 offsets[] = {-70, -42, -14, 14, 48};
            ob_batch7_result_row(kinds, offsets, 5, scale, 224, time, 2000, 1);
        }
        else
        {
            ob_batch7_result_glyph(9, 192 - 98 * scale, 128 + 224 * r_u32(0x8006C174), time + 2000, 1);
            ob_batch7_result_glyph(r_u32(0x800771FC) + 16, 192 - 70 * scale, 128 + 224 * r_u32(0x8006C174), time + 2100, 1);
            static const sint32 kinds[] = {15, 4, 7, 11};
            static const sint32 offsets[] = {-10, 22, 39, 70};
            ob_batch7_result_row(kinds, offsets, 4, scale, 224, time, 2200, 1);
        }
        if (r_u32(0x800771F8) != 0xFFFFFFFF)
        {
            w_u16(0x80076880, 4);
            w_u32(0x80077200, r_u32(0x80077200) + 10000);
            ob_main_8001FAC8();
            sub_8001F9B0(10, 0);
            sub_8001DF58(r_u8(0x8006C22E));
        }
        else w_u16(0x80076880, 2);
        break;
    }
    case 2:
        ob_main_8001C3B0(time);
        break;
    case 3:
        return;
    case 4:
        if ((sint32)(time - r_u32(0x800774B0)) >= 6001)
        {
            sint32 count = r_s16(0x80077084);
            for (sint32 index = 0; index < count; ++index)
            {
                w_u16(0x80083EDC + (uint32)index * 36, 2);
                w_u16(0x80083ED8 + (uint32)index * 36, 0);
            }
            w_u16(0x80076880, 5);
        }
        ob_main_8001C3B0(time);
        break;
    case 5:
        if ((sint32)(time - r_u32(0x800774B0)) >= 6801)
        {
            w_u16(0x80077084, 0);
            w_u16(0x80076880, 6);
        }
        ob_main_8001C3B0(time);
        break;
    case 6:
        if (r_u32(0x800771F8) != 0xFFFFFFFF)
        {
            static const sint32 kinds[] = {10, 3, 11, 13, 5, 12, 11};
            static const sint32 offsets[] = {-98, -70, -42, -14, 16, 42, 70};
            ob_batch7_result_row(kinds, offsets, 7, scale, (uint32)-288, time, 600, 0);
            sint32 count = (sint32)ob_main_8001CBBC();
            uint32 rank_glyph = 22;
            uint32 row = 0;
            sint32 left = count;
            for (sint32 index = 0; index < count; ++index)
            {
                uint32 entry = 0x80088288 + (uint32)index * 6;
                uint32 start = time + (uint32)left * 500 + 1200;
                uint32 live_scale = r_u32(0x8006C174);
                uint32 y = row * scale + 128;
                ob_batch7_result_glyph(r_u16(entry + 4) + 16, 192 - 56 * scale - 328 * live_scale,
                    y - 62 * live_scale, start, 2);
                sint32 rank = r_s16(entry + 4);
                if ((uint32)rank < 5) rank_glyph = rank < 3 ? (uint32)rank + 22 : 25;
                /* The ranking helper initializes the first row to rank zero */
                live_scale = r_u32(0x8006C174);
                ob_batch7_result_glyph(rank_glyph, 192 - 28 * scale - 328 * live_scale,
                    y - 62 * live_scale, start, 2);
                live_scale = r_u32(0x8006C174);
                ob_batch7_result_glyph(9, 192 + 14 * scale + 328 * live_scale,
                    y - 62 * live_scale, start, 3);
                uint32 identity = r_u16(entry);
                live_scale = r_u32(0x8006C174);
                ob_batch7_result_glyph(identity + 16, 192 + 42 * scale + 328 * live_scale,
                    y - 62 * live_scale, start, 3);
                if (!index)
                    for (uint32 back = 1; back <= 4; ++back) ob_main_8001C33C(back, 192, 160, 128);
                --left;
                row += 28;
            }
        }
        w_u16(0x80076880, 2);
        break;
    default:
        break;
    }
    if (r_s32(0x80077200) < (sint32)(time - r_u32(0x800774B0)))
    {
        uint32 winner = r_u32(0x800771F8);
        w_u16(0x80076880, 3);
        w_u32(0x80089990, time + 500);
        w_u8(0x80086A2C, 0);
        if (winner != 0xFFFFFFFF)
        {
            uint32 index = r_u32(0x80077204);
            w_u32(0x80089B78, 1);
            w_u32(r_u32(0x8006C138 + index * 4) + 288, 20);
        }
    }
    uint32 pressed = 0;
    if (r_u32(0x800771FC) != 0xFFFFFFFF && r_u32(0x800771F8) == 0xFFFFFFFF)
        pressed = sub_80054440(((r_u32(0x80077204) << 4) + 14) & 254);
    else
    {
        uint32 players = r_u8(0x8006C230);
        if (players)
        {
            uint32 index = 0;
            do
            {
                if (r_u32(0x8006C138 + index * 4)) pressed |= sub_80054440((14 + index * 16) & 255);
                ++index;
                players = r_u8(0x8006C230);
            } while ((sint32)index < (sint32)players);
        }
    }
    uint32 start = r_u32(0x800774B0);
    sint32 remainder = (sint32)(time - start) % 10000;
    if (remainder >= 3001 && pressed) w_u32(0x800774B0, start - 10000 + (uint32)remainder);
}

static void ob_batch7_link_indexed(uint32 packet, uint32 size)
{
    uint32 head = r_u32(0x80077634);
    w_u32(0x800774A8, packet + size);
    uint32 tag = r_u32(head);
    w_u32(0x80077634, packet);
    w_u32(head, (tag & 0xFF000000) | (packet & 0xFFFFFF));
}

static uint32 ob_batch7_indexed_texture(uint32 stream, uint32 size, uint32 page, uint32 flags)
{
    uint32 mode = r_u32(0x800774A8);
    if (!(flags & 0x200))
    {
        ob_batch7_link_indexed(mode, size);
        return mode;
    }
    uint32 head = r_u32(0x80077634);
    uint32 packet = mode + 12;
    uint32 tag = r_u32(head);
    w_u32(0x800774A8, packet);
    uint32 restore = mode + size + 12;
    w_u32(0x80077634, mode);
    w_u32(head, (tag & 0xFF000000) | (mode & 0xFFFFFF));
    w_u32(0x1F80000C, r_u8(stream + 16));
    w_u32(0x1F800010, r_u8(stream + 17));
    w_u32(0x1F800014, r_u8(stream + 18));
    uint32 height = r_u8(stream + 19);
    w_u32(0x800774A8, restore);
    w_u32(0x80077634, packet);
    w_u32(0x80077634, restore);
    w_u32(0x1F800018, height);
    w_u32(mode, 0x02000000);
    tag = r_u32(mode);
    w_u32(mode + 4, 0xE1000200 + (page & 0xFFFF));
    sint32 height_mask = (sint32)(r_u32(0x1F800018) - 1) >> 3;
    uint32 window = ((31 - (uint32)height_mask) << 5) + 0xE200001F;
    sint32 width_mask = (sint32)(r_u32(0x1F800014) - 1) >> 3;
    sint32 x = r_s32(0x1F80000C) >> 3;
    window = window - (uint32)width_mask + ((uint32)x << 10);
    sint32 y = r_s32(0x1F800010) >> 3;
    w_u32(mode, (tag & 0xFF000000) | (packet & 0xFFFFFF));
    window += (uint32)y << 15;
    w_u32(mode + 8, window);
    tag = r_u32(packet);
    w_u32(0x800774A8, restore + 12);
    w_u32(packet, (tag & 0xFF000000) | (restore & 0xFFFFFF));
    w_u32(restore, 0x02000000);
    w_u32(restore + 4, 0xE1000200);
    w_u32(restore + 8, 0xE2000000);
    return packet;
}

static void ob_batch7_indexed_coordinates(uint32 packet, uint32 indices, uint32 vertices, uint32 quad, uint32 flat)
{
    static const uint32 polygon_offsets[] = {8, 16, 32, 24};
    static const uint32 flat_offsets[] = {8, 12, 20, 16};
    uint32 count = quad ? 4 : 3;
    for (uint32 index = 0; index < count; ++index)
    {
        uint32 offset = flat ? flat_offsets[index] : polygon_offsets[index];
        if (!quad && index == 2) offset = flat ? 16 : 24;
        w_u32(packet + offset, r_u32(vertices + r_u16(indices + index * 2) * 24));
    }
}

uint32 ob_main_8003BB2C(void)
{
    FUNCTION_MARKER(0x8003BB2C, "SLES_008.65");
    uint32 flags = (r_u16(0x800774E4) | r_u16(0x80077480)) & r_u16(0x800775A0);
    uint32 stream = r_u32(0x80077418);
    uint32 indices = r_u32(0x80077384);
    uint32 vertices = r_u32(0x80077574);
    uint32 attributes = r_u16(0x8007748C);
    uint32 model = r_u32(0x80077598);
    uint32 normals = r_u32(model + 44);
    if (attributes & 0x3F)
    {
        uint32 color = stream + ((flags & 2) ? 4 : 0);
        if (flags & 0x80)
        {
            ob_batch7_polygon_light(normals + r_u32(0x80077514) * 12, color);
            w_u32(0x1F800000, xport_gte_read_data(22));
        }
        else w_u32(0x1F800000, r_u32(color));
        return ob_main_8003DDB4(0x1F800000);
    }
    if (flags & 2)
    {
        w_u8(0x1F800008, 127);
        uint32 count = r_u16(0x800775B4);
        w_u8(0x1F800009, 127);
        w_u8(0x1F80000A, 127);
        uint32 quad = count == 4;
        uint32 page = r_u32(stream);
        uint32 packet = ob_batch7_indexed_texture(stream, quad ? 40 : 32, page, flags);
        if (flags & 0x80) ob_batch7_polygon_light(normals + r_u32(0x80077514) * 12, 0x1F800008);
        else w_u32(packet + 4, 0x7F7F7F);
        w_u16(packet + 14, page >> 16);
        w_u16(packet + 22, page);
        ob_batch7_indexed_coordinates(packet, indices, vertices, quad, 0);
        w_u16(packet + 12, r_u16(stream + 8));
        w_u16(packet + 20, r_u16(stream + 10));
        w_u16(packet + (quad ? 36 : 28), r_u16(stream + 12));
        if (quad) w_u16(packet + 28, r_u16(stream + 14));
        if (flags & 0x80) w_u32(packet + 4, xport_gte_read_data(22));
        w_u8(packet + 3, quad ? 9 : 7);
        uint32 command = (quad ? 0x2C : 0x24) | ((flags & 0x100) ? 2 : 0);
        w_u8(packet + 7, command);
        return command;
    }
    if (flags & 4)
    {
        if ((flags & 0x80) && r_u16(0x800775A6))
        {
            uint32 count = r_u16(0x800775B4);
            uint32 vertex_normals = r_u32(model + 48);
            uint32 quad = count == 4;
            uint32 normal_indices = stream + (quad ? 12 : count * 2 + 4);
            uint32 first = vertex_normals + (uint32)(sint32)r_s16(normal_indices) * 8;
            uint32 second = vertex_normals + (uint32)(sint32)r_s16(normal_indices + 2) * 8;
            uint32 third = vertex_normals + (uint32)(sint32)r_s16(normal_indices + 4) * 8;
            uint32 packet = r_u32(0x800774A8);
            xport_gte_write_data(0, r_u32(first));
            xport_gte_write_data(1, r_u32(first + 4));
            xport_gte_write_data(2, r_u32(second));
            xport_gte_write_data(3, r_u32(second + 4));
            xport_gte_write_data(4, r_u32(third));
            xport_gte_write_data(5, r_u32(third + 4));
            xport_gte_write_data(6, r_u32(stream));
            xport_gte_execute(0x118043F);
            ob_batch7_link_indexed(packet, quad ? 36 : 28);
            ob_batch7_indexed_coordinates(packet, indices, vertices, quad, 0);
            w_u32(packet + 4, xport_gte_read_data(20));
            w_u32(packet + 12, xport_gte_read_data(21));
            w_u32(packet + (quad ? 28 : 20), xport_gte_read_data(22));
            if (quad)
            {
                uint32 normal = vertex_normals + (uint32)(sint32)r_s16(stream + 18) * 8;
                ob_batch7_polygon_light(normal, stream);
                w_u32(packet + 20, xport_gte_read_data(22));
            }
            w_u8(packet + 3, quad ? 8 : 6);
            uint32 command = (quad ? 0x38 : 0x30) | ((flags & 0x100) ? 2 : 0);
            w_u8(packet + 7, command);
            return command;
        }
        uint32 quad = r_u16(0x800775B4) == 4;
        uint32 packet = r_u32(0x800774A8);
        ob_batch7_link_indexed(packet, quad ? 36 : 28);
        ob_batch7_indexed_coordinates(packet, indices, vertices, quad, 0);
        uint32 color = indices + (quad ? 8 : 6);
        if (flags & 0x80)
        {
            ob_batch7_polygon_light(normals + r_u32(0x80077514) * 12, stream);
            w_u32(packet + 12, xport_gte_read_data(22));
            color = packet + 12;
        }
        uint32 red = r_u8(color);
        uint32 green = r_u8(color + 1);
        uint32 blue = r_u8(color + 2);
        static const uint32 color_offsets[] = {4, 12, 28, 20};
        uint32 weights = indices + (quad ? 12 : 10);
        for (uint32 index = 0; index < (uint32)(quad ? 4 : 3); ++index)
        {
            uint32 weight = r_u16(weights + index * 2);
            uint32 offset = !quad && index == 2 ? 20 : color_offsets[index];
            w_u8(packet + offset, (weight * red) >> 4);
            w_u8(packet + offset + 1, (weight * green) >> 4);
            w_u8(packet + offset + 2, (weight * blue) >> 4);
        }
        w_u8(packet + 3, quad ? 8 : 6);
        uint32 command = (quad ? 0x38 : 0x30) | ((flags & 0x100) ? 2 : 0);
        w_u8(packet + 7, command);
        return command;
    }
    if (!(flags & 1)) return 4;
    uint32 quad = r_u16(0x800775B4) == 4;
    uint32 packet = r_u32(0x800774A8);
    if (quad && (flags & 0x4000)) w_u32(packet + 4, 0xFFFFFF);
    else if (flags & 0x80) ob_batch7_polygon_light(normals + r_u32(0x80077514) * 12, stream);
    else w_u32(packet + 4, r_u32(stream));
    ob_batch7_link_flat(packet, quad ? 24 : 20);
    ob_batch7_indexed_coordinates(packet, indices, vertices, quad, 1);
    if (flags & 0x80) w_u32(packet + 4, xport_gte_read_data(22));
    w_u8(packet + 3, quad ? 5 : 4);
    uint32 command = (quad ? 0x28 : 0x20) | ((flags & 0x100) ? 2 : 0);
    w_u8(packet + 7, command);
    return command;
}
