#include "native_card.h"
#include "xport.h"
#include "psx.h"
#include "game_signatures.h"
#include "native_extra_signatures.h"
#include "draft_signatures.h"
#include "movie_player.h"

uint32 ob_main_80015374(uint32 player, uint32 position)
{
    FUNCTION_MARKER(0x80015374, "SLES_008.65");
    uint32 scale = r_u32(0x8006C174);
    sint32 numerator = (sint32)(384 - scale * 106);
    sint32 divisor = r_s8(0x8006C235) - 1;
    if (!divisor) return ob_native_missing_value(0x80015374, "BREAK 7 division by zero");
    if (divisor == -1 && numerator == INT32_MIN)
        return ob_native_missing_value(0x80015374, "BREAK 6 division overflow");
    uint32 index = (uint32)(sint32)(sint16)player;
    uint32 x = (uint32)(sint32)(sint16)position * (uint32)(numerator / divisor) + scale * 21;
    uint32 y = 236 - scale * 30;
    uint32 player_cell = 0x8006C138 + index * 4;
    uint32 object = r_u32(player_cell);
    if (!object) return 0;
    uint32 data = r_u32(object + 108);
    uint32 short_x = (uint32)(sint32)(sint16)x;
    uint32 short_y = (uint32)(sint32)(sint16)y;
    sub_8001578C((sint32)index, (sint32)short_x, (sint32)short_y, 1);
    scale = r_u32(0x8006C174);
    sub_80020FD4(r_u32(0x80065CE4 + index * 4), 0, 0, 63, 31,
        short_x, short_y, scale * 63, scale * 31, 0);
    uint32 attributes = r_u32(r_u32(player_cell) + 120);
    uint32 weapon = (uint32)(sint32)r_s8(attributes + 135);
    if (r_s8(data + weapon + 106))
    {
        uint32 ammunition_index = (uint32)(sint32)r_s8(0x800C5EED + weapon * 4);
        uint32 variant = (uint32)(sint32)r_s8(data + weapon + 130);
        sint32 available = r_s16(data + ammunition_index * 2 + 120);
        sint32 cost = r_s16(0x800C5B64 + (weapon * 35 + variant * 7) * 2);
        uint32 disabled = (sint32)((uint32)available - (uint32)cost) < 0;
        uint32 color = disabled ? 0 : 128;
        if (r_s8(data + weapon + 143) > 0) w_u8(data + weapon + 143, 0);
        uint32 x_offset = (uint32)(sint32)r_s16(0x80065DCC + weapon * 2);
        scale = r_u32(0x8006C174);
        uint32 icon_x = short_x + x_offset * scale;
        uint32 y_offset = (uint32)(sint32)r_s16(0x80065DDC + weapon * 2);
        uint32 icon_y = short_y + y_offset * scale;
        sub_8002140C(r_u32(0x80065CC4 + weapon * 4), 0, 0, 15, 15,
            icon_x, icon_y, scale * 15, scale * 15, disabled, color, color, color);
    }
    scale = r_u32(0x8006C174);
    uint32 ammunition_index = (uint32)(sint32)r_s8(0x800C5EED + weapon * 4);
    sub_80013C00((uint32)(sint32)r_s16(data + ammunition_index * 2 + 120), short_x + scale * 54, short_y + scale * 7);
    uint32 selected = (uint32)(sint32)r_s8(data + 177);
    if (r_s8(data + selected + 130) >= 0)
    {
        uint32 row = 0;
        uint32 table = 0x80065DB4;
        do
        {
            uint32 x_offset = (uint32)(sint32)r_s16(table) + 3;
            scale = r_u32(0x8006C174);
            uint32 y_offset = (uint32)(sint32)r_s16(0x80065DC0 + row * 2) - 37;
            sub_80020A70(short_x + x_offset * scale, short_y + y_offset * scale,
                scale * 2, scale * 2, 255, 255, 32, 0);
            selected = (uint32)(sint32)r_s8(data + 177);
            sint32 last = r_s8(data + selected + 130);
            ++row;
            table += 2;
            if (last < (sint32)row) break;
        } while (1);
    }
    scale = r_u32(0x8006C174);
    return ob_main_80013DA4(r_u8(data + 44), short_x + scale * 29, short_y + scale * 10);
}

static void ob_batch6_edge_gte(uint32 vertex)
{
    uint32 plane = r_u32(0x80077414) + 4;
    uint32 first = r_u32(plane);
    uint32 second = r_u32(plane + 4);
    xport_gte_write_control(0, first);
    xport_gte_write_control(1, second);
    xport_gte_write_data(0, r_u32(vertex + 8));
    xport_gte_write_data(1, r_u32(vertex + 12));
    xport_gte_execute(0x486012);
    w_u32(0x1F800000, xport_gte_read_data(25));
}

uint32 ob_main_80033158(uint32 edge, uint32 output)
{
    FUNCTION_MARKER(0x80033158, "SLES_008.65");
    uint32 mask = (uint32)1 << ((r_u16(0x80077380) + 8) & 31);
    uint32 vertex = r_u32(edge + 8);
    w_u32(edge + 28, r_u32(edge + 28) | mask);
    uint32 link;
    if (r_u32(vertex + 16) & mask)
    {
        link = edge + 8;
        uint32 first = r_u32(edge + 4);
        w_u32(0x80077570, vertex);
        w_u16(edge + 42, 1);
        vertex = first;
    }
    else
    {
        uint32 other = r_u32(edge + 4);
        link = edge + 4;
        w_u16(edge + 42, 0);
        w_u32(0x80077570, other);
    }
    ob_batch6_edge_gte(vertex);
    uint32 first_distance = (uint32)(r_s32(0x1F800000) >> 2);
    uint32 second_vertex = r_u32(0x80077570);
    ob_batch6_edge_gte(second_vertex);
    uint32 plane = r_u32(0x80077414);
    uint32 second_distance = (uint32)(r_s32(0x1F800000) >> 2);
    uint32 inverse = r_u8(plane + 10);
    uint32 delta;
    if (inverse)
    {
        first_distance = 0 - first_distance;
        second_distance = 0 - second_distance;
        delta = first_distance - second_distance;
        w_u16(edge + 32, r_u32(plane) - second_distance);
    }
    else
    {
        delta = second_distance - first_distance;
        w_u16(edge + 32, r_u32(plane) - first_distance);
    }
    sint32 divisor = (sint16)delta;
    sint32 numerator = (sint32)((uint32)(sint32)r_s16(edge + 32) << 12);
    if (!divisor) return ob_native_missing_value(0x80033158, "BREAK 7 division by zero");
    if (divisor == -1 && numerator == INT32_MIN)
        return ob_native_missing_value(0x80033158, "BREAK 6 division overflow");
    uint32 fraction = (uint32)(numerator / divisor);
    w_u16(edge + 34, delta);
    if (inverse)
    {
        w_u16(0x800735D0, fraction);
        second_vertex = r_u32(0x80077570);
    }
    else
    {
        second_vertex = r_u32(0x80077570);
        w_u16(0x800735D0, fraction);
    }
    w_u16(0x800735D8, fraction);
    w_u16(0x800735E0, fraction);
    uint32 vector = ob_draft_scratch_acquire(8);
    for (uint32 index = 0; index < 3; ++index)
    {
        uint32 a = r_u16((inverse ? vertex : second_vertex) + 8 + index * 2);
        uint32 b = r_u16((inverse ? second_vertex : vertex) + 8 + index * 2);
        w_u16(vector + index * 2, a - b);
    }
    uint32 controls[5];
    for (uint32 index = 0; index < 5; ++index) controls[index] = r_u32(0x800735D0 + index * 4);
    for (uint32 index = 0; index < 5; ++index) xport_gte_write_control(index, controls[index]);
    xport_gte_write_data(0, r_u32(vector));
    xport_gte_write_data(1, r_u32(vector + 4));
    xport_gte_execute(0x486012);
    w_u32(0x1F800000, xport_gte_read_data(25));
    w_u32(0x1F800004, xport_gte_read_data(26));
    w_u32(0x1F800008, xport_gte_read_data(27));
    if (inverse) second_vertex = r_u32(0x80077570);
    uint32 origin = inverse ? second_vertex : vertex;
    for (uint32 index = 0; index < 3; ++index)
    {
        uint32 amount = r_u32(0x1F800000 + index * 4);
        uint32 coordinate = r_u16(origin + 8 + index * 2);
        if (inverse && index == 2) plane = r_u32(0x80077414);
        w_u16(output + 8 + index * 2, coordinate + amount);
    }
    ob_draft_scratch_release(vector);
    if (inverse)
    {
        uint32 threshold = r_u32(plane);
        w_u16(edge + 34, second_distance - first_distance);
        w_u16(edge + 32, threshold - first_distance);
    }
    w_u32(link, output);
    if (r_u8(edge + 24)) ob_main_8002C5DC(output);
    else w_u32(output + 16, 0);
    return ob_main_80033074(output);
}

uint32 ob_main_800184EC(void)
{
    FUNCTION_MARKER(0x800184EC, "SLES_008.65");
    uint32 submenu = 0;
    uint32 selected = 0;
    uint32 size = 30;
    uint32 message = 0;
    uint32 phase = 0;
    sint32 timer = r_s32(0x8008969C);
    uint32 fixed_timer = (uint32)(timer / 100) * 100 + 90;
    sub_800544EC();
    sub_80054CD8();
    sub_8001E108();
    ob_main_8001FB50();
    do
    {
        w_u32(0x8008969C, fixed_timer);
        sub_80054320();
        sub_8002D25C(0x8008CED0, (sint32)0x80086B70);
        if (phase != 1)
        {
            if (phase == 0)
            {
                size += 10;
                if (size == 110)
                {
                    phase = 1;
                    sub_800544EC();
                }
            }
            else if (phase == 2)
            {
                size -= 10;
                if (message && size == 40) phase = 7;
                else if (size == 30) phase = 3;
            }
            else if (phase == 7) phase = 3;
        }
        if (phase == 1)
        {
            if (sub_80054440(3))
            {
                selected = 0;
                phase = 2;
            }
            if (submenu == 0)
            {
                if (sub_80054440(4)) selected = selected ? selected - 1 : 2;
                else if (sub_80054440(6)) selected = selected == 2 ? 0 : selected + 1;
                else if (sub_80054440(14))
                {
                    if (selected == 0) phase = 2;
                    else if (selected == 1)
                    {
                        submenu = 1;
                        sub_800544EC();
                        selected = 4;
                    }
                    else if (selected == 2)
                    {
                        submenu = 2;
                        sub_800544EC();
                        selected = 6;
                    }
                }
            }
            else if (submenu == 1)
            {
                if (sub_80054440(12))
                {
                    submenu = 0;
                    sub_800544EC();
                    selected = 1;
                }
                else if (sub_80054440(7) || sub_80054440(5)) selected = selected == 3 ? 4 : 3;
                else if (sub_80054440(14))
                {
                    if (selected == 3)
                    {
                        message = 0x8001030C;
                        phase = 2;
                    }
                    else
                    {
                        submenu = 0;
                        sub_800544EC();
                        selected = 1;
                    }
                }
            }
            else if (submenu == 2)
            {
                if (sub_80054440(12))
                {
                    submenu = 0;
                    sub_800544EC();
                    selected = 2;
                }
                else if (sub_80054440(7) || sub_80054440(5)) selected = selected == 5 ? 6 : 5;
                else if (sub_80054440(14))
                {
                    if (selected == 5)
                    {
                        message = 0x80010238;
                        phase = 2;
                    }
                    else
                    {
                        submenu = 0;
                        sub_800544EC();
                        selected = 2;
                    }
                }
            }
        }
        ob_draft_unresolved_call(0x800188E8, 5, phase, message, submenu, selected, size);
        while (r_u32(0x80077620)) {}
        ob_draft_unresolved_call(0x8005C504, 1, 0);
        w_u32(0x8007754C, r_u32(0x8007737C));
        sub_8002CFA8();
        w_u32(0x80077620, 1);
    } while (phase != 3);
    sub_800544EC();
    sub_80054CEC();
    if (selected == 0)
    {
        sub_8001E1E0();
        ob_main_8001FBCC();
        return 0;
    }
    if (selected == 3)
    {
        w_u32(0x8006C220, 0);
        w_u32(0x8006C224, 0);
        return 1;
    }
    return selected == 5 ? 2 : 0;
}

static void ob_batch6_light_color(uint32 normal, uint32 color)
{
    xport_gte_write_data(0, r_u32(normal));
    xport_gte_write_data(1, r_u32(normal + 4));
    xport_gte_write_data(6, r_u32(color));
    xport_gte_execute(0x108041B);
    w_u32(0x1F800008, xport_gte_read_data(22));
}

static uint32 ob_batch6_color_links(uint32 node, uint32 *output)
{
    if (r_u16(node + 38) == 1)
    {
        w_u32(node + 16, *output);
        *output += 16;
        w_u32(node + 12, *output);
        return 1;
    }
    w_u32(node + 12, *output);
    *output += 16;
    w_u32(node + 16, *output);
    return 0;
}

uint32 ob_main_8003CC8C(uint32 context, uint32 last)
{
    FUNCTION_MARKER(0x8003CC8C, "SLES_008.65");
    uint32 reverse = 0;
    uint32 skip = r_u16(0x800775B4) * 2;
    uint32 stream = r_u32(0x80077418) + skip;
    uint32 mask = r_u16(0x800775A0);
    uint32 flags = r_u16(0x800774E4) | r_u16(0x80077480);
    w_u32(0x80077418, stream);
    w_u16(0x800774E4, flags);
    flags &= mask;
    w_u16(0x800774E4, flags);
    if (flags & 1)
    {
        uint32 descriptor = r_u32(0x80077394);
        uint32 color = r_u32(stream);
        w_u32(descriptor + 4, color);
        return color;
    }
    if (flags & 2)
    {
        uint32 descriptor = r_u32(0x80077394);
        uint32 color = r_u32(stream);
        uint32 node = r_u32(descriptor);
        w_u32(0x80077418, stream + 4);
        w_u32(0x800775E8, color);
        w_u32(descriptor + 4, r_u32(stream + 4));
        uint32 output = r_u32(0x80077648);
        uint32 input = stream + 8;
        while (node)
        {
            reverse = r_u16(node + 38) == 1;
            w_u32(node + (reverse ? 16 : 12), output);
            w_u32(output, r_u8(input++));
            w_u32(output + 4, r_u8(input++));
            output += 16;
            w_u32(node + (reverse ? 12 : 16), output);
            last = node;
            node = r_u32(last);
        }
    }
    else if (flags & 4)
    {
        uint32 descriptor = r_u32(0x80077394);
        w_u32(descriptor + 4, r_u32(stream));
        uint32 output = r_u32(0x80077648);
        uint32 node = r_u32(descriptor);
        uint32 indexed = r_u16(0x800775A6);
        stream += 4;
        w_u32(0x80077418, stream);
        if (indexed && (flags & 0x80))
        {
            w_u32(0x80077418, stream + skip);
            uint32 normals = r_u32(r_u32(0x80077598) + 48);
            while (node)
            {
                uint32 input = r_u32(0x80077418);
                uint32 normal = normals + r_u16(input) * 8;
                uint32 color = r_u32(0x80077394) + 4;
                ob_batch6_light_color(normal, color);
                w_u16(output + 8, r_u8(0x1F800008));
                w_u16(output + 10, r_u8(0x1F800009));
                w_u16(output + 12, r_u8(0x1F80000A));
                reverse = ob_batch6_color_links(node, &output);
                last = node;
                input = r_u32(0x80077418);
                node = r_u32(last);
                w_u32(0x80077418, input + 2);
            }
        }
        else
        {
            uint32 normals = r_u32(r_u32(0x80077598) + 44);
            while (node)
            {
                uint32 input;
                uint32 color;
                if (r_u16(0x800774E4) & 0x80)
                {
                    uint32 normal = normals + r_u32(0x80077514) * 12;
                    ob_batch6_light_color(normal, r_u32(0x80077394) + 4);
                    input = r_u32(0x80077418);
                    color = 0x1F800008;
                }
                else
                {
                    input = r_u32(0x80077418);
                    color = r_u32(0x80077394) + 4;
                }
                uint32 product = r_u16(input) * r_u8(color);
                w_u16(output + 8, ((sint32)product >> 4) & 255);
                product = r_u16(input) * r_u8(color + 1);
                w_u32(0x80077418, input + 2);
                w_u16(output + 10, ((sint32)product >> 4) & 255);
                product = r_u16(input) * r_u8(color + 2);
                w_u16(output + 12, ((sint32)product >> 4) & 255);
                reverse = ob_batch6_color_links(node, &output);
                last = node;
                node = r_u32(last);
            }
        }
    }
    else return 0;
    uint32 result = r_u32(0x80077648);
    /* TODO Empty lists retain the incoming second argument as the final link owner */
    w_u32(last + (reverse ? 12 : 16), result);
    return result;
}

uint32 ob_game_800B41FC(uint32 object, uint32 velocity)
{
    FUNCTION_MARKER(0x800B41FC, "GAME.BIN");
    uint32 node = r_u32(0x800C84EC);
    uint32 x_force = 0;
    uint32 z_force = 0;
    while (node)
    {
        if (r_u32(node + 96) == 165)
        {
            uint32 source = r_u32(node + 80);
            if (r_u32(source + 288) == 25)
            {
                uint32 distance = ob_game_80099798(r_u32(object + 44) + 80, r_u32(source + 44) + 80);
                uint32 range = r_u16(node + 50) * 750;
                if ((sint32)distance < (sint32)range)
                {
                    source = r_u32(r_u32(node + 80) + 44);
                    uint32 target = r_u32(object + 44);
                    uint32 dz = r_u32(source + 88) - r_u32(target + 88);
                    uint32 dx = r_u32(source + 80) - r_u32(target + 80);
                    uint32 heading = sub_80027F98(dz, dx);
                    range = r_u16(node + 50) * 750;
                    sint32 numerator = (sint32)(distance << 11);
                    sint32 divisor = (sint32)range;
                    if (!divisor) return ob_native_missing_value(0x800B41FC, "BREAK 7 division by zero");
                    if (divisor == -1 && numerator == INT32_MIN)
                        return ob_native_missing_value(0x800B41FC, "BREAK 6 division overflow");
                    sint32 limit = (sint16)(4096 - (uint32)(numerator / divisor));
                    sint32 angle = (sint16)heading;
                    sint32 direction = r_s16(node + 48);
                    sint32 difference = angle - direction;
                    if (difference < 0) difference = direction - angle;
                    if (difference < limit)
                    {
                        uint32 radius = r_u16(node + 50);
                        uint32 strength;
                        if ((sint32)distance < (sint32)(radius * 375)) strength = radius * 100;
                        else strength = (uint32)((sint32)((radius * 750 - distance) * 200) / 750);
                        uint32 index = ((r_u16(node + 48) + 8) >> 4) * 2;
                        sint32 product = (sint32)(strength * (uint32)(sint32)r_s16(0x8006C304 + index));
                        x_force += (uint32)(product / 16384);
                        index = ((r_u16(node + 48) + 8) >> 4) * 2;
                        product = (sint32)(strength * (uint32)(sint32)r_s16(0x8006CB04 + index));
                        z_force += (uint32)(product / 16384);
                    }
                }
            }
        }
        node = r_u32(node + 76);
    }
    uint32 current = r_u32(velocity);
    uint32 magnitude = (sint32)x_force < 0 ? 0 - x_force : x_force;
    uint32 decrement = (uint32)((sint32)x_force / 20);
    uint32 delta = current - decrement;
    if ((sint32)delta < 0) delta = decrement - current;
    if ((sint32)delta < (sint32)magnitude)
        w_u32(velocity, r_u32(velocity) - (uint32)((sint32)x_force / 20));
    current = r_u32(velocity + 8);
    magnitude = (sint32)z_force < 0 ? 0 - z_force : z_force;
    decrement = (uint32)((sint32)z_force / 20);
    delta = current - decrement;
    if ((sint32)delta < 0) delta = decrement - current;
    if ((sint32)delta < (sint32)magnitude)
        w_u32(velocity + 8, r_u32(velocity + 8) - (uint32)((sint32)z_force / 20));
    current = r_u32(velocity);
    magnitude = (sint32)current < 0 ? 0 - current : current;
    if ((sint32)magnitude < 100) w_u32(velocity, 0);
    current = r_u32(velocity + 8);
    magnitude = (sint32)current < 0 ? 0 - current : current;
    uint32 result = (sint32)magnitude < 100;
    if (result) w_u32(velocity + 8, 0);
    return result;
}

uint32 ob_game_800B83FC(uint32 node, uint32 count, uint32 step, uint32 time)
{
    FUNCTION_MARKER(0x800B83FC, "GAME.BIN");
    if (r_s16(0x800C5B54) != 1) return 1;
    uint32 position = sub_80045464(node, time);
    uint32 first = ob_draft_scratch_acquire(192);
    uint32 second = first + 96;
    sub_80029E54(first + 12);
    w_u8(first + 92, 60);
    w_u32(first + 44, 0x800C4978);
    w_u8(first + 93, 4);
    w_u16(first + 90, 40);
    w_u16(first + 86, 40);
    w_u16(first + 88, 160);
    w_u32(first + 48, 0);
    w_u8(first + 94, 0);
    w_u32(first + 76, 1);
    w_u32(first + 60, 1);
    w_u8(first + 95, 1);
    w_u32(first + 36, 250);
    uint32 random = sub_8001B008();
    uint32 x = r_u32(position) - 128 + (random & 255);
    uint32 y = r_u32(position + 4);
    random = sub_8001B008();
    uint32 z = r_u32(position + 8) - 128 + (random & 255);
    sub_80029E54(second + 12);
    w_u8(second + 92, 3);
    w_u32(second + 56, 300);
    w_u32(second + 44, 0x800C4A68);
    w_u32(second + 48, 0);
    w_u8(second + 93, 1);
    w_u8(second + 94, 0);
    w_u32(second + 76, 1);
    w_u8(second + 95, 1);
    w_u16(second + 88, 190);
    w_u16(second + 90, 190);
    w_u16(second + 86, 190);
    w_u32(second + 40, 0);
    w_u32(second + 36, 0);
    w_u32(second + 32, 0);
    /* TODO Fields not written by the original retain unspecified local contents */
    uint32 result = 190;
    if (count == 1)
    {
        w_u32(first + 32, (sub_8001B008() & 127) - 64);
        w_u32(first + 40, (sub_8001B008() & 127) - 64);
        w_u32(first, x);
        w_u32(first + 4, y);
        w_u32(first + 8, z);
        w_u32(first + 56, (uint32)((sint32)(0 - (y << 8)) / 250));
        ob_game_80092408(r_u32(0x80083E34), first, time, 1);
        uint32 duration = r_u32(first + 56);
        uint32 x_product = r_u32(first + 32) * duration;
        uint32 z_product = r_u32(first + 40) * duration;
        w_u32(second + 4, count);
        w_u32(second + 60, duration + r_u32(first + 60));
        w_u32(second, x + (uint32)((sint32)x_product >> 8));
        w_u32(second + 8, z + (uint32)((sint32)z_product >> 8));
        result = ob_game_80092408(r_u32(0x80083E34), second, time, 4);
    }
    else if (count)
    {
        uint32 y_step = (uint32)((sint32)(0 - step * 1000) >> 8);
        uint32 index = 0;
        do
        {
            w_u32(first + 32, (sub_8001B008() & 127) - 64);
            w_u32(first + 40, (sub_8001B008() & 127) - 64);
            uint32 age = r_u32(first + 60);
            uint32 x_product = age * r_u32(node + 132);
            uint32 previous_y = y - (uint32)((sint32)(age * 250) >> 8);
            uint32 previous_x = x - (uint32)((sint32)x_product >> 8);
            w_u32(first + 4, previous_y);
            w_u32(first, previous_x);
            uint32 duration = (uint32)((sint32)(0 - (y << 8)) / 250);
            w_u32(first + 56, duration);
            uint32 z_product = age * r_u32(node + 140);
            w_u32(first + 8, z - (uint32)((sint32)z_product >> 8));
            if ((sint32)duration > 0)
            {
                ob_game_80092408(r_u32(0x80083E34), first, time, 1);
                duration = r_u32(first + 56);
                x_product = r_u32(first + 32) * duration;
                z_product = r_u32(first + 40) * duration;
                w_u32(second + 4, 1);
                w_u32(second + 60, duration + r_u32(first + 60));
                w_u32(second, r_u32(first) + (uint32)((sint32)x_product >> 8));
                w_u32(second + 8, r_u32(first + 8) + (uint32)((sint32)z_product >> 8));
                ob_game_80092408(r_u32(0x80083E34), second, time, 4);
            }
            w_u32(first + 60, r_u32(first + 60) + step);
            x_product = step * r_u32(node + 132);
            y += y_step;
            x += (uint32)((sint32)x_product >> 8);
            z_product = step * r_u32(node + 140);
            ++index;
            z += (uint32)((sint32)z_product >> 8);
            result = z;
        } while (index != count);
    }
    ob_draft_scratch_release(first);
    return result;
}

uint32 ob_main_800188E8(uint32 phase, uint32 message, uint32 submenu, uint32 selected, uint32 height)
{
    FUNCTION_MARKER(0x800188E8, "SLES_008.65");
    sint32 top = (sint32)(256 - height) / 2;
    ob_game_800BA1C8();
    sub_80013FA4(r_u32(0x800882BC));
    sub_8002192C(0);
    sub_80020A70(0, 0, 384, 256, 80, 60, 44, 1);
    sub_8002192C(2);
    sub_80020A70(0, 0, 384, 256, 12, 20, 36, 1);
    ob_draft_unresolved_call(0x800176C8, 4, 117, (uint32)top, 150, height);
    if (phase == 1)
    {
        ob_main_800175A8(0x80010318, (uint32)top + 26, 1);
        if (submenu == 0)
        {
            ob_main_800175A8(0x80010324, (uint32)top + 61, selected == 0);
            ob_main_800175A8(0x80010330, (uint32)top + 72, selected == 1);
            ob_main_800175A8(0x800102C0, (uint32)top + 83, selected == 2);
        }
        else if (submenu == 1)
        {
            ob_main_800175A8(0x80010338, (uint32)top + 61, 1);
            ob_main_800175A8(0x800102D0, (uint32)top + 83, selected == 3);
            ob_main_800175A8(0x800102DC, (uint32)top + 83, selected == 4);
        }
        else if (submenu == 2)
        {
            ob_main_800175A8(0x800102C8, (uint32)top + 61, 1);
            ob_main_800175A8(0x800102D0, (uint32)top + 83, selected == 5);
            ob_main_800175A8(0x800102DC, (uint32)top + 83, selected == 6);
        }
        if (r_u8(0x8006C230) == 1)
        {
            uint32 x = 140;
            uint32 y = (uint32)top + 39;
            for (uint32 index = 0; index < 6; ++index)
            {
                uint32 controller = r_u8(0x8006C231);
                sint32 kind = r_s8(0x8006C264 + controller * 6 + index);
                if (kind >= 0 && kind <= 3)
                    sub_80021460(0x80066624 + (uint32)kind * 4, 0, 0, 16, 16, x, y, 0);
                x += 18;
            }
        }
    }
    if (r_u8(0x8006C230) == 1)
    {
        uint32 multitap = ob_main_800541A8(0);
        if (!sub_800540F8(0))
        {
            ob_main_800175A8(multitap ? 0x80010370 : 0x80010344, 31, 1);
            ob_main_800175A8(0x8001035C, 41, 1);
        }
    }
    else
    {
        uint32 multitap = ob_main_800541A8(0);
        uint32 configuration = r_u32(0x8006C130);
        if (configuration == 1 && !multitap)
        {
            ob_main_800175A8(0x80010388, 214, 1);
            ob_main_800175A8(0x8001035C, 224, 1);
        }
        else if (configuration == 2 && !ob_main_800541A8(4))
        {
            ob_main_800175A8(0x8001039C, 214, 1);
            ob_main_800175A8(0x8001035C, 224, 1);
        }
        else if (!sub_800540F8(0))
        {
            ob_main_800175A8(multitap ? 0x80010370 : 0x80010344, 31, 1);
            ob_main_800175A8(0x8001035C, 41, 1);
        }
    }
    if ((phase == 7 || phase == 3) && message) ob_main_800175A8(message, 124, 1);
    sub_8004C944(r_u32(0x800882BC));
    uint32 environment = r_u32(0x800773D0) ? 0x8008C6C8 : 0x8008CF70;
    ob_draft_unresolved_call(0x8005B994, 2, r_u32(0x8007737C) + 112, environment);
    return sub_8001FC60();
}

static uint32 ob_batch6_contact_weight(uint32 first, uint32 second)
{
    sint32 difference = (sint16)(first - second);
    if (difference < 0) difference = -difference;
    uint32 weight = (uint32)difference;
    if (weight < 0x4000) weight = 0x8000 - weight;
    weight = (weight - 0x4000) & 0xFFFF;
    if (weight < 0x800) weight = 0x800;
    return weight;
}

uint32 ob_game_800AD01C(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800AD01C, "GAME.BIN");
    uint32 counter = r_u32(0x80084444);
    uint32 recorded_id = r_u16(0x800D5DD0);
    uint32 object_id = r_u16(object + 302);
    w_u32(0x80084444, counter + 1);
    uint32 first = recorded_id == object_id ? 0x800D5DD8 : 0x800D5D18;
    uint32 second = recorded_id == object_id ? 0x800D5D18 : 0x800D5DD8;
    uint32 second_resource = r_u32(second + 180);
    uint32 first_resource = r_u32(first + 180);
    if (r_s32(object + 280) < (sint32)(time - 500))
        ob_main_80011A24(0x80067228, 128, 256, r_u32(object + 44), time, 0);
    uint32 second_heading = r_u16(second + 168);
    if (r_s32(second + 164) < 0) second_heading = (second_heading + 0x8000) & 0xFFFF;
    uint32 first_heading = r_u16(first + 168);
    if (r_s32(first + 164) < 0) first_heading = (first_heading + 0x8000) & 0xFFFF;
    uint32 second_position = sub_80045464(second, time);
    uint32 first_position = sub_80045464(first, time);
    uint32 locals = ob_draft_scratch_acquire(32);
    uint32 dz = r_u32(first_position + 8) - r_u32(second_position + 8);
    uint32 dx = r_u32(first_position) - r_u32(second_position);
    sub_80028280((sint32)dz, (sint32)dx, locals, locals + 4);
    uint32 heading = r_u16(locals);
    uint32 opposite = heading + 0x8000;
    /* The first computed weight has no consumer in the original */
    ob_batch6_contact_weight(second_heading, heading);
    uint32 weight = ob_batch6_contact_weight(first_heading, opposite);
    sint32 product = (sint32)(r_u32(first + 132) * weight);
    uint32 sum = r_u32(second + 132) + (uint32)(product / 16384);
    uint32 average_x = (uint32)((sint32)sum >> 1);
    w_u32(locals + 20, 0);
    w_u32(locals + 16, average_x);
    product = (sint32)(r_u32(first + 140) * weight);
    sum = r_u32(second + 140) + (uint32)(product / 16384);
    uint32 average_z = (uint32)((sint32)sum >> 1);
    w_u32(locals + 24, average_z);
    uint32 change_x = average_x - r_u32(second + 132);
    uint32 change_z = average_z - r_u32(second + 140);
    if (r_u8(first + 186) == 1)
    {
        sint32 difference = (sint32)(second_heading & 0x7FFF) - (sint32)(first_heading & 0x7FFF);
        if (difference < 0) difference = -difference;
        uint32 distance = (uint32)difference;
        if (distance > 0x4000) distance = 0x8000 - distance;
        uint32 scale = distance - 0x2000;
        product = (sint32)(scale * change_x);
        change_x += (uint32)(product / 65536);
        product = (sint32)(scale * change_z);
        change_z += (uint32)(product / 65536);
    }
    uint32 first_mass = r_u8(first_resource + 42);
    uint32 second_mass = r_u8(second_resource + 42);
    if (!second_mass)
        return ob_native_missing_value(0x800AD01C, "BREAK 7 collision mass division by zero");
    product = (sint32)(change_x * first_mass);
    change_x = (uint32)(product / (sint32)second_mass);
    product = (sint32)(change_z * first_mass);
    change_z = (uint32)(product / (sint32)second_mass);
    uint32 result_x = r_u32(second + 132) + change_x;
    w_u32(locals + 16, result_x);
    uint32 result_z = r_u32(second + 140) + change_z;
    uint32 quadrant = (r_u16(locals) + 0x2000) & 0xC000;
    w_u32(locals + 24, result_z);
    if (quadrant == 0 && (sint32)result_z > 0) w_u32(locals + 24, 0);
    else if (quadrant == 0x4000 && (sint32)result_x > 0) w_u32(locals + 16, 0);
    else if (quadrant == 0x8000 && (sint32)result_z < 0) w_u32(locals + 24, 0);
    else if (quadrant == 0xC000 && (sint32)result_x < 0) w_u32(locals + 16, 0);
    uint32 result = sub_80045A44(r_u32(object + 44), locals + 16);
    ob_draft_scratch_release(locals);
    return result;
}

static uint32 ob_batch6_panel_row(uint32 corner, uint32 middle, uint32 x, uint32 y, uint32 width, uint32 height)
{
    sub_80020450(corner, 0, 0, 15, height, x, y, 0);
    uint32 current_x = x + 15;
    uint32 remaining = width - 28;
    do
    {
        uint32 fragment = (sint32)remaining < 16 ? remaining : 15;
        sub_80020450(middle, 0, 0, fragment, height, current_x, y, 0);
        remaining -= 15;
        current_x += 15;
    } while ((sint32)remaining > 0);
    return sub_80020450(corner, 0, 0, 15, height, x + width - 15, y, 2);
}

uint32 ob_main_800176C8(uint32 x, uint32 y, uint32 width, uint32 height)
{
    FUNCTION_MARKER(0x800176C8, "SLES_008.65");
    if ((sint32)height < 30) height = 30;
    ob_batch6_panel_row(0x80066634, 0x80066640, x, y, width, 15);
    uint32 remaining = height - 30;
    if ((sint32)remaining >= 16)
        ob_batch6_panel_row(0x80066638, 0x80066644, x, y + 15, width, 15);
    else if ((sint32)remaining >= 0)
        ob_batch6_panel_row(0x80066638, 0x80066644, x, y + 15, width, remaining + 1);
    uint32 current_y = y + 29;
    remaining = height - 42;
    do
    {
        uint32 fragment = (sint32)remaining < 16 ? remaining : 15;
        ob_batch6_panel_row(0x8006663C, 0x80066648, x, current_y, width, fragment);
        remaining -= 15;
        current_y += 15;
    } while ((sint32)remaining > 0);
    return ob_batch6_panel_row(0x80066634, 0x80066640, x, y + height - 15, width, 15);
}

static void ob_batch6_bounce_axis(uint32 object, uint32 normal_address, uint32 offset)
{
    sint32 normal = r_s16(normal_address);
    if (!normal) return;
    uint32 reverse = 0;
    if (normal > 0)
    {
        if (r_s32(r_u32(object + 44) + offset) < 0) reverse = 1;
    }
    else if (r_s32(r_u32(object + 44) + offset) > 0) reverse = 1;
    if (reverse)
    {
        uint32 node = r_u32(object + 44);
        w_u32(node + offset, 0 - r_u32(node + offset));
    }
    else
    {
        uint32 value = r_s16(normal_address) > 0 ? 64 : (uint32)-64;
        w_u32(r_u32(object + 44) + offset, value);
    }
}

static void ob_batch6_damp_axis(uint32 object, uint32 normal_address, uint32 offset)
{
    if (!r_s16(normal_address)) return;
    uint32 node = r_u32(object + 44);
    w_u32(node + offset, (uint32)(r_s32(node + offset) / 2));
    node = r_u32(object + 44);
    uint32 value = r_u32(node + offset);
    if ((sint32)value < 0) value = 0 - value;
    if ((sint32)value < 16) w_u32(node + offset, 0);
}

uint32 ob_game_8009DEDC(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x8009DEDC, "GAME.BIN");
    uint32 flags = r_u32(record + 28);
    uint32 source = r_u32(record + 52);
    uint32 killed = 0;
    if (flags & 0x10904400)
    {
        sint32 kind = (sint16)r_u16(source + 132);
        uint32 strength = ob_game_800B8FBC(object, source);
        if ((uint16)strength < 64) strength = 64;
        if ((sint16)strength > 128) strength = 128;
        sub_80047FF0(record);
        if (kind == 7 || kind == 5)
        {
            sint32 size = r_s16(r_u32(object + 48) + 160) - (sint16)strength / 16;
            if (size < 80) size = 79;
            ob_game_8009E750(object, (uint32)size, time);
        }
        else killed = ob_game_800A52C4(object, (uint32)(sint32)(sint16)strength, 0xFFFFFFFF);
        if (kind == 5) sub_800465E8(r_u32(object + 52), r_u32(record + 48));
        sint32 size = r_s16(r_u32(object + 48) + 160);
        if (size < 80)
        {
            ob_game_800B979C(r_u32(object + 44), (uint32)size, 6, time);
            ob_main_80011A24(0x800666C4, 128, 320, r_u32(object + 44), time, 0);
            return ob_game_800BCAA0(object);
        }
        if (!killed) return 2;
        kind = r_s16(source + 132);
        uint32 reference = 0;
        if (kind == 2 || (uint16)(kind - 4) < 2 || kind == 3 || kind == 6)
            reference = r_u32(source + 52);
        ob_game_8009E3B0(object, reference, time);
        return ob_game_800BCAA0(object);
    }
    if (flags & 0x20040200)
    {
        uint32 source_node = r_u32(source + 44);
        if (r_u32(source_node + 132) || r_u32(source_node + 140))
        {
            sub_80047FF0(record);
            sint32 size = r_s16(r_u32(object + 48) + 160);
            if (size < 80)
            {
                ob_game_800B979C(r_u32(object + 44), (uint32)size, 6, time);
                ob_main_80011A24(0x800666C4, 128, 320, r_u32(object + 44), time, 0);
            }
            else ob_game_8009E3B0(object, 0, time);
            return ob_game_800BCAA0(object);
        }
    }
    sub_80047FF0(record);
    sub_80045A7C(r_u32(object + 44), time);
    ob_batch6_bounce_axis(object, record + 16, 132);
    ob_batch6_bounce_axis(object, record + 20, 140);
    if (!(r_u32(record + 28) & 0x10000) && r_u32(object + 280) == time
        && r_u16(object + 300) == r_u16(source + 302))
    {
        ob_batch6_damp_axis(object, record + 16, 132);
        ob_batch6_damp_axis(object, record + 20, 140);
    }
    w_u32(object + 280, time);
    uint32 contact = r_u16(source + 302);
    uint32 node = r_u32(object + 44);
    w_u16(object + 300, contact);
    return sub_80045ADC(node);
}

uint32 ob_main_80017C10(void)
{
    FUNCTION_MARKER(0x80017C10, "SLES_008.65");
    uint32 submenu = 0;
    uint32 selected = 0;
    uint32 height = 30;
    uint32 message = 0;
    uint32 phase = 0;
    sub_800544EC();
    sub_80054CD8();
    ob_main_800121A4();
    do
    {
        sub_80054320();
        sub_8002D25C(0x8008CED0, (sint32)0x80086B70);
        switch (phase)
        {
        case 0:
            height += 10;
            if (height == 110)
            {
                phase = 1;
                sub_800544EC();
            }
            break;
        case 2:
            height -= 10;
            if (message && height == 40) phase = 7;
            else if (height == 30) phase = 3;
            break;
        case 4:
            height += 10;
            if (height == 170)
            {
                phase = 5;
                sub_800544EC();
            }
            break;
        case 6:
            height -= 10;
            if (height == 110)
            {
                phase = 1;
                sub_800544EC();
            }
            break;
        case 7: phase = 3; break;
        }
        if (phase == 1 || phase == 5)
        {
            if (submenu == 0)
            {
                if (sub_80054440(4)) selected = selected ? selected - 1 : 2;
                else if (sub_80054440(6)) selected = selected == 2 ? 0 : selected + 1;
                else if (sub_80054440(14))
                {
                    if (selected == 0)
                    {
                        message = 0x8001022C;
                        phase = 2;
                    }
                    else if (selected == 1)
                    {
                        phase = 4;
                        sub_800544EC();
                        submenu = 1;
                        selected = r_s8(0x8006C247) ? 3 : 4;
                    }
                    else if (selected == 2)
                    {
                        submenu = 2;
                        sub_800544EC();
                        selected = 14;
                    }
                }
            }
            else if (submenu == 1)
            {
                if (sub_80054440(3) || sub_80054440(12))
                {
                    submenu = 0;
                    sub_800544EC();
                    selected = 1;
                    phase = 6;
                }
                else if (sub_80054440(4))
                {
                    --selected;
                    if (selected < 3) selected = 12;
                    if ((uint32)(sint32)r_s8(0x8006C247) == selected - 3)
                    {
                        --selected;
                        if (selected < 3) selected = 12;
                    }
                }
                else if (sub_80054440(6))
                {
                    ++selected;
                    if (selected >= 13) selected = 3;
                    if ((uint32)(sint32)r_s8(0x8006C247) == selected - 3)
                    {
                        ++selected;
                        if (selected >= 13) selected = 3;
                    }
                }
                else if (sub_80054440(14))
                {
                    sub_800544EC();
                    message = 0x80010238;
                    phase = 2;
                }
            }
            else if (submenu == 2)
            {
                if (sub_80054440(3) || sub_80054440(12))
                {
                    submenu = 0;
                    sub_800544EC();
                    selected = 2;
                }
                else if (sub_80054440(7) || sub_80054440(5)) selected = selected == 14 ? 13 : 14;
                else if (sub_80054440(14))
                {
                    if (selected == 13)
                    {
                        message = 0x80010238;
                        phase = 2;
                    }
                    else
                    {
                        submenu = 0;
                        sub_800544EC();
                        selected = 2;
                    }
                }
            }
        }
        ob_main_80018190(phase, message, submenu, selected, height);
        while (r_u32(0x80077620)) {}
        ob_draft_unresolved_call(0x8005C504, 1, 0);
        w_u32(0x8007754C, r_u32(0x8007737C));
        sub_8002CFA8();
        sub_8001FC60();
        w_u32(0x80077620, 1);
    } while (phase != 3);
    sub_80054CEC();
    sub_800544EC();
    w_u32(0x80089B78, 0);
    if (selected == 0) return 1;
    if (selected >= 3 && selected <= 12)
    {
        w_u8(0x8006C247, selected - 3);
        w_u8(0x8006C231, selected + 17);
        return 6;
    }
    return selected == 13 ? 2 : 0;
}

uint32 ob_main_80019360(uint32 phase, uint32 message, uint32 submenu, uint32 selected, uint32 height)
{
    FUNCTION_MARKER(0x80019360, "SLES_008.65");
    uint32 player = (uint32)(sint32)r_s16(0x800C4E70);
    uint32 data = r_u32(r_u32(0x8006C138 + player * 4) + 108);
    uint32 top = (uint32)((sint32)(256 - height) / 2);
    ob_game_800BA1C8();
    sub_80013FA4(r_u32(0x800882BC));
    sub_8002192C(0);
    sub_80020A70(0, 0, 384, 256, 80, 60, 44, 1);
    sub_8002192C(2);
    sub_80020A70(0, 0, 384, 256, 12, 20, 36, 1);
    ob_main_800176C8(92, top, 200, height);
    if (phase == 1)
    {
        if (r_s16(0x800D649C) > 0)
        {
            ob_main_800175A8(0x800103D0, top + 26, 1);
            sint32 counter = r_s32(0x8006602C);
            sint32 amount = r_s16(data + 32);
            uint32 text = ob_draft_scratch_acquire(32);
            if (amount < counter / 4)
            {
                ob_draft_unresolved_call(0x80064028, 4, text, 0x800103E4, (uint32)amount, (uint32)(sint32)r_s16(0x800D649C));
                amount = r_s16(data + 32);
                if (amount == r_s16(0x800D649C))
                {
                    if (r_u32(0x8006602C) == (uint32)amount * 4 + 5)
                        sub_80011984(0x800660AC, 128, 15, 15, 256, 0, 0);
                    if (r_u32(0x8006602C) & 8) ob_main_800175A8(0x800103F8, top + 81, 4);
                }
            }
            else
            {
                if (!(counter & 3)) sub_80011984(0x800660AC, 255, 15, 15, 256, 0, 0);
                counter = r_s32(0x8006602C);
                ob_draft_unresolved_call(0x80064028, 4, text, 0x800103E4, (uint32)(counter / 4), (uint32)(sint32)r_s16(0x800D649C));
            }
            w_u32(0x8006602C, r_u32(0x8006602C) + 1);
            ob_main_800175A8(text, top + 61, 3);
            ob_draft_scratch_release(text);
        }
        else ob_main_800175A8(0x80010408, top + 26, 1);
        if (submenu == 0)
        {
            ob_main_800175A8(0x80010324, top + 101, selected == 0);
            uint32 style = selected == 1;
            ob_main_800175A8(0x8001041C, top + 112, style);
            ob_main_800175A8(0x80010428, top + 123, selected == 2);
            ob_main_800175A8(0x800102C0, top + 134, selected == 3);
        }
        else if (submenu == 1)
        {
            ob_main_800175A8(0x800102C8, top + 101, 1);
            ob_main_800175A8(0x800102D0, top + 123, selected == 4);
            ob_main_800175A8(0x800102DC, top + 123, selected == 5);
        }
        else if (submenu == 2)
        {
            switch (selected)
            {
            case 6: case 7:
                ob_main_800175A8(0x80010454, top + 101, 1);
                ob_main_800175A8(0x800102D0, top + 123, selected == 6);
                ob_main_800175A8(0x800102DC, top + 123, selected == 7);
                break;
            case 9: case 10:
                ob_main_800175A8(selected == 9 ? 0x80010460 : 0x80010478, top + 101, 1);
                ob_main_800175A8(0x80010470, top + 123, 1);
                break;
            case 11: ob_main_800175A8(0x80010434, top + 101, 1); break;
            case 12: ob_main_800175A8(0x80010444, top + 101, 1); break;
            }
        }
        uint32 x = 140;
        for (uint32 index = 0; index < 6; ++index)
        {
            uint32 controller = r_u8(0x8006C231);
            sint32 kind = r_s8(0x8006C264 + controller * 6 + index);
            if (kind >= 0 && kind <= 3)
                sub_80021460(0x80066624 + (uint32)kind * 4, 0, 0, 16, 16, x, top + 39, 0);
            x += 18;
        }
    }
    else w_u32(0x8006602C, 0);
    if ((phase == 7 || phase == 3) && message) ob_main_800175A8(message, 124, 1);
    sub_8004C944(r_u32(0x800882BC));
    uint32 environment = r_u32(0x800773D0) ? 0x8008C6C8 : 0x8008CF70;
    return ob_draft_unresolved_call(0x8005B994, 2, r_u32(0x8007737C) + 112, environment);
}

uint32 ob_main_80018DB0(void)
{
    FUNCTION_MARKER(0x80018DB0, "SLES_008.65");
    uint32 submenu = 0;
    uint32 selected = 0;
    uint32 height = 30;
    uint32 message = 0;
    uint32 phase = 0;
    sub_80024D54(4095);
    ob_main_8001FAC8();
    ob_draft_unresolved_call(0x80059CA8, 1, 0);
    ob_draft_unresolved_call(0x80059CA8, 1, 0);
    uint32 track = (r_u8(0x8006C231) >> 2) * 5 + 10;
    w_u32(0x8007FAD0, track);
    sub_8001F9B0((sint32)track, 0);
    sub_8001DF58(r_u8(0x8006C22E));
    sub_800544EC();
    sub_80054CD8();
    ob_main_800121A4();
    uint32 level = r_u8(0x8006C231) + 1;
    w_u8(0x8006C231, level);
    ob_main_8001D3C0(level & 255);
    do
    {
        sub_80054320();
        sub_8002D25C(0x8008CED0, (sint32)0x80086B70);
        if (phase == 0)
        {
            height += 10;
            if (height == 160)
            {
                phase = 1;
                sub_800544EC();
            }
        }
        else if (phase == 2)
        {
            height -= 10;
            if (message && height == 40) phase = 7;
            else if (height == 30) phase = 3;
        }
        else if (phase == 7) phase = 3;
        if (submenu == 0)
        {
            if (sub_80054440(4))
            {
                selected = selected ? selected - 1 : 3;
            }
            else if (sub_80054440(6))
            {
                selected = selected == 3 ? 0 : selected + 1;
            }
            else if (sub_80054440(14))
            {
                if (selected == 0 || selected == 2)
                {
                    message = 0x80010238;
                    phase = 2;
                }
                else if (selected == 1)
                {
                    if (ob_native_save_game() == 1)
                    {
                        message = 0x80010238;
                        phase = 2;
                    }
                }
                else if (selected == 3)
                {
                    submenu = 1;
                    sub_800544EC();
                    selected = 5;
                }
            }
        }
        else if (submenu == 1)
        {
            if (sub_80054440(3) || sub_80054440(12))
            {
                submenu = 0;
                sub_800544EC();
                selected = 3;
            }
            else if (sub_80054440(7) || sub_80054440(5)) selected = selected == 5 ? 4 : 5;
            else if (sub_80054440(14))
            {
                if (selected == 4)
                {
                    message = 0x80010238;
                    phase = 2;
                }
                else
                {
                    submenu = 0;
                    sub_800544EC();
                    selected = 3;
                }
            }
        }
        ob_main_80019360(phase, message, submenu, selected, height);
        while (r_u32(0x80077620)) {}
        sub_8001FC60();
        ob_draft_unresolved_call(0x8005C504, 1, 0);
        w_u32(0x8007754C, r_u32(0x8007737C));
        sub_8002CFA8();
        w_u32(0x80077620, 1);
    } while (phase != 3);
    sub_80054CEC();
    sub_800544EC();
    if (selected == 0 || selected == 1) return 3;
    if (selected == 2) return 5;
    return selected == 4 ? 2 : 0;
}

static void ob_batch6_projection_flags(uint32 output, uint32 flags)
{
    if (flags & 0x26000)
    {
        if (flags & 0x2000) w_u16(output + 22, 0x2000);
        if (flags & 0x4000) w_u16(output + 22, 0x4000);
        if (flags & 0x20000)
        {
            w_u16(output + 22, 0x1000);
            w_u8(output + 20, 0x80);
        }
    }
    else w_u16(output + 22, 0);
}

static void ob_batch6_project_vertex(uint32 input, uint32 output, uint32 clear_marker)
{
    xport_gte_write_data(0, r_u32(input));
    xport_gte_write_data(1, r_u32(input + 4));
    xport_gte_execute(0x180001);
    uint32 flags = xport_gte_read_flag();
    w_u32(output, xport_gte_read_data(14));
    if (clear_marker) w_u8(output + 20, 0);
    ob_batch6_projection_flags(output, flags);
}

static void ob_batch6_screen_bounds(uint32 output, sint32 right, sint32 left, sint32 bottom, sint32 top)
{
    sint32 x = r_s16(output);
    uint32 mask = right < x ? 2 : x < left ? 1 : 0;
    sint32 y = r_s16(output + 2);
    if (bottom < y) mask |= 8;
    else if (y < top) mask |= 4;
    w_u16(output + 22, r_u16(output + 22) | mask);
}

uint32 ob_main_8003803C(uint32 object)
{
    FUNCTION_MARKER(0x8003803C, "SLES_008.65");
    uint32 output = r_u32(0x80077574);
    uint32 right_word = r_u32(0x80077398);
    uint32 input = r_u32(object + 32);
    sint32 bottom = (sint16)r_u32(0x8007739C);
    sint32 left = (sint16)r_u32(0x8007738C);
    sint32 top = (sint16)r_u32(0x80077390);
    uint32 count = r_u16(object + 10);
    sint32 right = (sint16)right_word;
    uint32 next = 3;
    if (count >= 3)
    {
        do
        {
            for (uint32 index = 0; index < 6; ++index) xport_gte_write_data(index, r_u32(input + index * 4));
            xport_gte_execute(0x280030);
            w_u8(output + 20, 0);
            w_u8(output + 44, 0);
            w_u8(output + 68, 0);
            w_u32(output, xport_gte_read_data(12));
            w_u32(output + 24, xport_gte_read_data(13));
            uint32 flags = xport_gte_read_flag();
            w_u32(output + 48, xport_gte_read_data(14));
            if (flags & 0x26000)
            {
                ob_batch6_project_vertex(input, output, 0);
                ob_batch6_project_vertex(input + 8, output + 24, 0);
                ob_batch6_project_vertex(input + 16, output + 48, 0);
            }
            else
            {
                w_u16(output + 22, 0);
                w_u16(output + 46, 0);
                w_u16(output + 70, 0);
            }
            ob_batch6_screen_bounds(output, right, left, bottom, top);
            ob_batch6_screen_bounds(output + 24, right, left, bottom, top);
            ob_batch6_screen_bounds(output + 48, right, left, bottom, top);
            input += 24;
            output += 72;
            next += 3;
        } while (count >= (uint16)next);
    }
    next -= 2;
    if (count < (uint16)next) return right_word << 16;
    do
    {
        ob_batch6_project_vertex(input, output, 1);
        ob_batch6_screen_bounds(output, right, left, bottom, top);
        input += 8;
        output += 24;
        ++next;
    } while (count >= (uint16)next);
    return 1;
}

static void ob_batch6_copy_transform(uint32 source, uint32 output)
{
    uint32 words[4];
    for (uint32 index = 0; index < 4; ++index) words[index] = r_u32(source + index * 4);
    for (uint32 index = 0; index < 4; ++index) w_u32(output + index * 4, words[index]);
    w_u16(output + 16, r_u16(source + 16));
    w_u32(output + 18, r_u32(source + 18));
}

static void ob_batch6_rotate_transform(uint32 matrix, uint32 angles, uint32 local)
{
    if (local)
    {
        if (r_s16(angles))
        {
            ob_main_8002DF2C(matrix, angles, 1);
            w_u16(matrix + 18, r_u16(matrix + 18) + 1);
        }
        if (r_s16(angles + 2))
        {
            ob_main_8002E2BC(matrix, angles, 1);
            w_u16(matrix + 18, r_u16(matrix + 18) + 1);
        }
        if (r_s16(angles + 4))
        {
            ob_main_8002E64C(matrix, angles, 1);
            w_u16(matrix + 18, r_u16(matrix + 18) + 1);
        }
    }
    else
    {
        if (r_s16(angles + 4))
        {
            ob_main_8002E64C(matrix, angles, 0);
            w_u16(matrix + 18, r_u16(matrix + 18) + 1);
        }
        if (r_s16(angles + 2))
        {
            ob_main_8002E2BC(matrix, angles, 0);
            w_u16(matrix + 18, r_u16(matrix + 18) + 1);
        }
        if (r_s16(angles))
        {
            ob_main_8002DF2C(matrix, angles, 0);
            w_u16(matrix + 18, r_u16(matrix + 18) + 1);
        }
    }
}

uint32 ob_main_8002E968(uint32 first, uint32 second, uint32 output)
{
    FUNCTION_MARKER(0x8002E968, "SLES_008.65");
    uint32 scale = ((uint32)r_u16(first + 76) * r_u16(second + 76)) >> 8;
    if ((uint16)scale > 0xFF00) scale = 0xFF00;
    w_u16(output + 76, scale);
    if (r_u32(first + 48) & 0x20)
    {
        uint32 flags = r_u32(second + 48);
        if (!(flags & 2))
        {
            if (flags & 1)
            {
                ob_main_8002F5FC(second, second + 70);
                flags = r_u32(second + 48);
                w_u16(second + 18, 0);
                w_u32(second + 48, (flags & 0xFFFFFFE3) | 2);
            }
            else ob_main_8002F594(second, 0x800770DC);
        }
        uint32 vector = ob_draft_scratch_acquire(16);
        sub_8002FED4(first + 24, second, vector);
        scale = r_u16(second + 76);
        if (scale != 256)
        {
            uint32 below_one = scale < 256;
            for (uint32 axis = 0; axis < 3; ++axis)
            {
                if (axis) scale = r_u16(second + 76);
                uint32 value = r_u32(vector + axis * 4);
                if (below_one) value = (uint32)((sint32)(value * scale) >> 8);
                else value = (uint32)((sint32)value >> 8) * scale;
                w_u32(vector + axis * 4, value);
            }
        }
        if (r_u32(second + 48) & 0x20)
        {
            for (uint32 axis = 0; axis < 3; ++axis)
                w_u32(output + 24 + axis * 4, r_u32(second + 24 + axis * 4) + r_u32(vector + axis * 4));
        }
        else
        {
            uint32 x = r_u32(vector);
            uint32 y = r_u32(vector + 4);
            uint32 z = r_u32(vector + 8);
            w_u32(output + 24, x);
            w_u32(output + 28, y);
            w_u32(output + 32, z);
        }
        ob_draft_scratch_release(vector);
        w_u32(output + 48, r_u32(output + 48) | 0x20);
    }
    else if (r_u32(second + 48) & 0x20)
    {
        uint32 x = r_u32(second + 24);
        uint32 y = r_u32(second + 28);
        uint32 z = r_u32(second + 32);
        w_u32(output + 24, x);
        w_u32(output + 28, y);
        w_u32(output + 32, z);
        w_u32(output + 48, r_u32(output + 48) | 0x20);
    }
    else
    {
        uint32 flags = r_u32(output + 48);
        w_u32(output + 24, 0);
        w_u32(output + 28, 0);
        w_u32(output + 32, 0);
        w_u32(output + 48, flags & 0xFFFFFFDF);
    }
    uint32 check_normalization = 0;
    if ((r_u32(first + 48) & 1) && (r_u32(second + 48) & 2))
    {
        ob_batch6_copy_transform(second, output);
        ob_batch6_rotate_transform(output, first + 70, 1);
        check_normalization = 1;
    }
    else if ((r_u32(first + 48) & 2) && (r_u32(second + 48) & 1))
    {
        ob_batch6_copy_transform(first, output);
        ob_batch6_rotate_transform(output, second + 70, 0);
        check_normalization = 1;
    }
    else if ((r_u32(first + 48) & 1) && (r_u32(second + 48) & 1))
    {
        ob_main_8002F5FC(output, second + 70);
        w_u16(output + 18, 0);
        w_u16(output + 20, 500);
        ob_batch6_rotate_transform(output, first + 70, 1);
    }
    else if ((r_u32(first + 48) & 2) && (r_u32(second + 48) & 2))
    {
        ob_main_8002EF88(first, second, output);
        uint32 count = r_u16(first + 18) + r_u16(second + 18);
        w_u16(output + 18, count);
        uint32 limit = r_u16(second + 20);
        count = r_u16(output + 18);
        w_u16(output + 20, limit);
        if (limit < count && !(r_u32(output + 48) & 0x10))
        {
            ob_main_8002F3D8(output);
            w_u16(output + 18, 0);
        }
    }
    else ob_main_8002F594(output, 0x800770DC);
    if (check_normalization && r_u16(output + 20) < r_u16(output + 18) && !(r_u32(output + 48) & 0x10))
    {
        ob_main_8002F3D8(output);
        w_u16(output + 18, 0);
    }
    uint32 result = (r_u32(output + 48) | 2) & 0xFFFFFFFE;
    w_u32(output + 48, result);
    return result;
}

static void ob_batch6_load_gte_matrix(uint32 matrix)
{
    uint32 words[5];
    for (uint32 index = 0; index < 5; ++index) words[index] = r_u32(matrix + index * 4);
    for (uint32 index = 0; index < 5; ++index) xport_gte_write_control(index, words[index]);
}

static void ob_batch6_transform_gte(uint32 vector)
{
    xport_gte_write_data(0, r_u32(vector));
    xport_gte_write_data(1, r_u32(vector + 4));
    xport_gte_execute(0x486012);
}

static void ob_batch6_store_gte_vector(uint32 output, uint32 shift)
{
    uint32 x = xport_gte_read_data(25);
    uint32 y = xport_gte_read_data(26);
    uint32 z = xport_gte_read_data(27);
    w_u16(output, (uint32)((sint32)x >> shift));
    w_u16(output + 2, (uint32)((sint32)y >> shift));
    w_u16(output + 4, (uint32)((sint32)z >> shift));
}

uint32 ob_main_800322BC(uint32 object)
{
    FUNCTION_MARKER(0x800322BC, "SLES_008.65");
    uint32 masks = r_u32(0x800775C4);
    uint32 callbacks = r_u32(0x8007736C);
    uint32 scale = r_u16(r_u32(object + 28) + 76);
    if (scale == 256) scale = r_u16(r_u32(object + 24) + 8);
    else
    {
        scale = (scale * r_u16(r_u32(object + 24) + 8)) >> 8;
        if ((uint16)scale > 0xFF00) scale = 0xFF00;
    }
    if (!r_u32(0x800774CC)) w_u16(0x80077324, 0);
    uint32 index = r_u16(0x80077324);
    uint32 input = object + 56;
    uint32 entry = 0x800897D8 + index * 8;
    while ((sint32)index < (sint32)(r_u16(object + 52) + r_u16(0x80077324)))
    {
        uint32 a = r_u32(input);
        uint32 b = r_u32(input + 4);
        w_u32(entry, a);
        w_u32(entry + 4, b);
        input += 8;
        ++index;
        entry += 8;
    }
    uint32 output = r_u32(0x80077560);
    uint32 transform = r_u32(object + 28);
    w_u16(0x80077324, index);
    uint32 count = r_u16(0x80077324);
    w_u16(0x80077638, 0);
    if (!count) return 0;
    uint32 position = transform + 24;
    scale &= 0xFFFF;
    uint32 positive_half = scale >> 1;
    uint32 negative_half = (uint32)((sint32)(0 - scale) >> 1);
    entry = 0x800897D8;
    index = 0;
    do
    {
        uint32 plane = r_u32(entry);
        for (uint32 axis = 0; axis < 3; ++axis)
            w_u32(0x1F800000 + axis * 4, r_u32(plane + axis * 4) - r_u32(position + axis * 4));
        if (scale != 256)
        {
            for (uint32 axis = 0; axis < 3; ++axis)
            {
                uint32 value = r_u32(0x1F800000 + axis * 4);
                uint32 numerator = (value << 8) + ((sint32)value > 0 ? positive_half : negative_half);
                if (!scale) return ob_native_missing_value(0x800322BC, "BREAK 7 plane scale division by zero");
                w_u32(0x1F800000 + axis * 4, (uint32)((sint32)numerator / (sint32)scale));
            }
        }
        uint32 maximum = r_u32(0x1F800000);
        if ((sint32)maximum < 0) maximum = 0 - maximum;
        uint32 value = r_u32(0x1F800004);
        if ((sint32)value < 0) value = 0 - value;
        if ((sint32)value > (sint32)maximum) maximum = value;
        value = r_u32(0x1F800008);
        if ((sint32)value < 0) value = 0 - value;
        if ((sint32)value > (sint32)maximum) maximum = value;
        uint32 shifts = 0;
        while ((sint32)maximum >= 18901)
        {
            maximum = (uint32)((sint32)maximum >> 1);
            uint32 x = r_u32(0x1F800000);
            uint32 z = r_u32(0x1F800008);
            w_u32(0x1F800000, (uint32)((sint32)x >> 1));
            uint32 y = r_u32(0x1F800004);
            w_u32(0x1F800008, (uint32)((sint32)z >> 1));
            w_u32(0x1F800004, (uint32)((sint32)y >> 1));
            ++shifts;
        }
        uint32 x = r_u32(0x1F800000);
        uint32 y = r_u32(0x1F800004);
        uint32 z = r_u32(0x1F800008);
        w_u16(0x1F80000C, x);
        w_u16(0x1F80000E, y);
        w_u16(0x1F800010, z);
        uint32 normal = plane + 12;
        uint32 first_word = r_u32(normal);
        uint32 second_word = r_u32(normal + 4);
        xport_gte_write_control(0, first_word);
        xport_gte_write_control(1, second_word);
        ob_batch6_transform_gte(0x1F80000C);
        uint32 distance = (uint32)((sint32)xport_gte_read_data(25) >> 2) << (shifts & 31);
        if (r_u16(entry + 4)) distance = 0 - distance;
        uint32 radius = r_u16(r_u32(object + 24) + 22);
        if ((sint32)distance < (sint32)radius)
        {
            if ((sint32)radius < (sint32)(0 - distance)) return 1;
            ob_batch6_load_gte_matrix(0x80089668);
            ob_batch6_transform_gte(0x1F80000C);
            ob_batch6_store_gte_vector(0x1F80001C, 0);
            ob_batch6_load_gte_matrix(0x8008C8A8);
            ob_batch6_transform_gte(normal);
            ob_batch6_store_gte_vector(0x1F800014, 0);
            xport_gte_write_control(0, r_u16(0x8007763C));
            uint32 third_scale = r_u16(0x80077640);
            uint32 second_scale = r_u16(0x8007763E);
            xport_gte_write_control(1, 0);
            xport_gte_write_control(3, 0);
            xport_gte_write_control(4, third_scale);
            xport_gte_write_control(2, second_scale);
            ob_batch6_transform_gte(0x1F800014);
            ob_batch6_store_gte_vector(0x1F800014, 2);
            uint32 first_y = r_u16(0x1F800016);
            uint32 second_y = r_u16(0x1F80001E);
            w_u16(0x1F800016, 0 - first_y);
            w_u16(0x1F80001E, 0 - second_y);
            first_word = r_u32(0x1F800014);
            second_word = r_u32(0x1F800018);
            xport_gte_write_control(0, first_word);
            xport_gte_write_control(1, second_word);
            ob_batch6_transform_gte(0x1F80001C);
            distance = (uint32)((sint32)xport_gte_read_data(25) >> 2) << (shifts & 31);
            if (r_u16(0x80077638) < 24)
            {
                uint32 inverse = r_u16(entry + 4);
                w_u8(output + 10, inverse);
                w_u32(output, (inverse & 255) ? 0 - distance : distance);
                uint32 packed = r_u32(0x1F800014);
                uint32 tail = r_u16(0x1F800018);
                w_u32(output + 4, packed);
                w_u16(output + 8, tail);
                output += 12;
                uint32 bit = (uint32)1 << ((r_u16(0x80077638) + 8) & 31);
                w_u32(masks, bit);
                masks += 4;
                w_u32(callbacks, 0x80033158);
                callbacks += 4;
                w_u16(0x80077638, r_u16(0x80077638) + 1);
            }
        }
        count = r_u16(0x80077324);
        ++index;
        entry += 8;
    } while ((sint32)index < (sint32)count);
    return 0;
}

uint32 ob_main_8001C3B0(uint32 time)
{
    FUNCTION_MARKER(0x8001C3B0, "SLES_008.65");
    sint32 count = r_s16(0x80077084);
    if (count <= 0) return (uint32)count;
    uint32 index = 0;
    uint32 entry = 0x80083EC0;
    do
    {
        if (r_s32(entry + 20) < (sint32)time)
        {
            sint32 state = r_s16(entry + 28);
            sint32 direction = r_s16(entry + 30);
            if (state == 0)
            {
                if (direction >= 0 && direction <= 3)
                {
                    uint32 angle = ((r_u16(entry + 24) + 8) >> 4) * 2;
                    sint32 delta = 0x4000 - r_s16(0x8006C304 + angle);
                    uint32 scale = r_u32(0x8006C174);
                    if (direction == 0) w_u16(entry + 14, r_u16(entry + 14) + (uint32)(delta / 448) * scale);
                    else if (direction == 1) w_u16(entry + 14, r_u16(entry + 14) - (uint32)(delta / 320) * scale);
                    else if (direction == 2) w_u16(entry + 12, r_u16(entry + 12) + (uint32)(delta / 256) * scale);
                    else w_u16(entry + 12, r_u16(entry + 12) - (uint32)(delta / 256) * scale);
                }
                uint32 angle = r_u16(entry + 24) + 1280;
                w_u16(entry + 24, angle);
                if ((sint16)angle >= 12288)
                {
                    uint32 y = r_u16(entry + 14);
                    uint32 x = r_u16(entry + 12);
                    w_u16(entry + 28, 1);
                    w_u16(entry + 18, y);
                    w_u16(entry + 16, x);
                }
            }
            else if (state == 1)
            {
                if (direction >= 0 && direction <= 3)
                {
                    uint32 angle = ((r_u16(entry + 24) + 8) >> 4) * 2;
                    sint32 delta = r_s16(0x8006CB04 + angle) - 0x4000;
                    uint32 scale = r_u32(0x8006C174);
                    sint32 divisor = direction < 2 ? 2560 : 6656;
                    w_u16(entry + 14, r_u16(entry + 18) + (uint32)(delta / divisor) * scale);
                    angle = ((r_u16(entry + 26) + 8) >> 4) * 2;
                    delta = r_s16(0x8006CB04 + angle) - 0x4000;
                    divisor = direction < 2 ? 4096 : 9216;
                    w_u16(entry + 12, r_u16(entry + 16) + (uint32)(delta / divisor) * scale);
                }
                uint32 first_angle = r_u16(entry + 24) + 1792;
                uint32 second_angle = r_u16(entry + 26) + 768;
                w_u16(entry + 24, first_angle);
                w_u16(entry + 26, second_angle);
            }
            else if (state == 2)
            {
                if (direction >= 0 && direction <= 3)
                {
                    uint32 delta = (uint32)(sint32)r_s16(entry + 24) * r_u32(0x8006C174);
                    uint32 coordinate = entry + (direction < 2 ? 14 : 12);
                    uint32 value = r_u16(coordinate);
                    if (direction == 0 || direction == 2) value -= delta;
                    else value += delta;
                    w_u16(coordinate, value);
                }
                w_u16(entry + 24, r_u16(entry + 24) + 2);
            }
        }
        uint32 difference = (uint32)(sint32)r_s16(entry + 18) - (uint32)(sint32)r_s16(entry + 14);
        uint32 highlight = 0;
        if (difference - 4 < 5)
        {
            if (difference == 8) highlight = 16;
            else if (difference == 4 || difference == 7) highlight = 32;
            else if (difference == 5 || difference == 6) highlight = 64;
        }
        sub_80020864(r_u32(entry), (uint32)(sint32)r_s16(entry + 4), (uint32)(sint32)r_s16(entry + 6),
            (uint32)(sint32)r_s16(entry + 8), (uint32)(sint32)r_s16(entry + 10),
            (uint32)(sint32)r_s16(entry + 12), (uint32)(sint32)r_s16(entry + 14), 0,
            r_u8(entry + 32) + highlight, r_u8(entry + 33) + highlight, r_u8(entry + 34) + highlight);
        ++index;
        count = r_s16(0x80077084);
        entry += 36;
    } while ((sint32)index < count);
    return 0;
}

static void ob_batch6_plane_triplet(uint32 vertices)
{
    uint32 first = r_u32(vertices + 8);
    uint32 second = r_u32(vertices + 56);
    uint32 third = r_u32(vertices + 60);
    xport_gte_write_control(0, first);
    xport_gte_write_control(3, second);
    xport_gte_write_control(4, third);
    first = r_u16(vertices + 12) + ((uint32)(sint32)r_s16(vertices + 32) << 16);
    second = r_u16(vertices + 34) + ((uint32)(sint32)r_s16(vertices + 36) << 16);
    xport_gte_write_control(1, first);
    xport_gte_write_control(2, second);
    xport_gte_write_data(0, r_u32(0x1F800030));
    xport_gte_write_data(1, r_u32(0x1F800034));
    xport_gte_execute(0x486012);
}

static void ob_batch6_store_plane_result(void)
{
    w_u32(0x1F800000, xport_gte_read_data(25));
    w_u32(0x1F800004, xport_gte_read_data(26));
    w_u32(0x1F800008, xport_gte_read_data(27));
}

static void ob_batch6_mark_triplet(uint32 vertices, uint32 threshold, uint32 inverse, uint32 bit)
{
    for (uint32 axis = 0; axis < 3; ++axis)
    {
        uint32 distance = (uint32)(r_s32(0x1F800000 + axis * 4) >> 2);
        if (inverse) distance = 0 - distance;
        if ((sint32)threshold < (sint32)distance)
        {
            uint32 flags = vertices + 16 + axis * 24;
            w_u32(flags, r_u32(flags) | bit);
        }
    }
}

uint32 ob_main_80032A68(uint32 vertices, uint32 count)
{
    FUNCTION_MARKER(0x80032A68, "SLES_008.65");
    uint32 plane_index = 0;
    uint32 plane_count = r_u16(0x80077638);
    uint32 plane = r_u32(0x80077560);
    if (!plane_count) return 0;
    uint32 bit_index = 8;
    do
    {
        w_u16(0x1F800030, r_u16(plane + 4));
        w_u16(0x1F800032, r_u16(plane + 6));
        w_u16(0x1F800034, r_u16(plane + 8));
        uint32 inverse = r_u8(plane + 10);
        uint32 threshold = r_u32(plane);
        uint32 current = vertices;
        uint32 reduced_count = count - 3;
        sint32 grouped_limit = (sint16)reduced_count;
        uint32 processed = 3;
        uint32 bit = (uint32)1 << (bit_index & 31);
        ob_batch6_plane_triplet(current);
        if (grouped_limit >= 3)
        {
            do
            {
                ob_batch6_store_plane_result();
                ob_batch6_plane_triplet(current + 72);
                ob_batch6_mark_triplet(current, threshold, inverse, bit);
                processed += 3;
                current += 72;
            } while (grouped_limit >= (sint32)processed);
        }
        ob_batch6_store_plane_result();
        ob_batch6_mark_triplet(current, threshold, inverse, bit);
        current += 72;
        count = reduced_count + 3;
        sint32 total = (sint16)count;
        if ((sint32)processed < total)
        {
            do
            {
                uint32 first = r_u32(0x1F800030);
                uint32 second = r_u32(0x1F800034);
                xport_gte_write_control(0, first);
                xport_gte_write_control(1, second);
                xport_gte_write_data(0, r_u32(current + 8));
                xport_gte_write_data(1, r_u32(current + 12));
                xport_gte_execute(0x486012);
                w_u32(0x1F800000, xport_gte_read_data(25));
                uint32 distance = (uint32)(r_s32(0x1F800000) >> 2);
                if (inverse) distance = 0 - distance;
                if ((sint32)threshold < (sint32)distance)
                    w_u32(current + 16, r_u32(current + 16) | bit);
                ++processed;
                current += 24;
            } while ((sint32)processed < total);
        }
        plane += 12;
        plane_count = r_u16(0x80077638);
        ++plane_index;
        ++bit_index;
    } while ((sint32)plane_index < (sint32)plane_count);
    return 0;
}
