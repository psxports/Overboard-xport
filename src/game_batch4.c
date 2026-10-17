#include "xport.h"
#include "psx.h"
#include "game_signatures.h"
#include "native_extra_signatures.h"
#include "draft_signatures.h"
#include "movie_player.h"

static sint32 ob_batch4_divide(uint32 owner, sint32 value, sint32 divisor)
{
    if (!divisor) return (sint32)ob_native_missing_value(owner, "BREAK 7 signed division by zero");
    if (divisor == -1 && value == (sint32)0x80000000)
        return (sint32)ob_native_missing_value(owner, "BREAK 6 signed division overflow");
    return value / divisor;
}

uint32 ob_main_8001C148(uint32 kind, uint32 x, uint32 y, uint32 time, uint32 value)
{
    FUNCTION_MARKER(0x8001C148, "SLES_008.65");
    sint32 count = r_s16(0x80077084);
    if (count >= 34) return 0;
    uint32 offset = (uint32)count * 36;
    if ((sint16)kind < 22)
    {
        uint32 index = (uint32)((sint16)kind / 4);
        uint32 resource = r_u32(0x8006BCA8 + index * 4);
        w_u16(0x80083EC6 + offset, (kind & 2) << 4);
        w_u16(0x80083EC4 + offset, (kind & 1) << 5);
        w_u16(0x80083EC8 + offset, 31);
        w_u16(0x80083ECA + offset, 31);
        w_u32(0x80083EC0 + offset, resource);
    }
    else
    {
        uint32 index = kind - 22;
        uint32 resource = r_u32(0x8006BCBC);
        w_u16(0x80083EC4 + offset, (index & 1) << 5);
        w_u16(0x80083EC8 + offset, 31);
        w_u16(0x80083EC6 + offset, ((index & 2) << 3) + 32);
        w_u16(0x80083ECA + offset, 15);
        w_u32(0x80083EC0 + offset, resource);
    }
    offset = (uint32)(sint32)r_s16(0x80077084) * 36;
    w_u8(0x80083EE0 + offset, 128);
    count = r_s16(0x80077084);
    w_u16(0x80083ECC + offset, x);
    w_u16(0x80083ECE + offset, y);
    w_u32(0x80083ED4 + offset, time);
    w_u16(0x80083EDE + offset, value);
    w_u8(0x80083EE1 + (uint32)count * 36, 128);
    offset = (uint32)(sint32)r_s16(0x80077084) * 36;
    w_u8(0x80083EE2 + offset, 128);
    count = r_s16(0x80077084);
    offset = (uint32)count * 36;
    w_u16(0x80083ED8 + offset, 0);
    w_u16(0x80083EDA + offset, 0);
    w_u16(0x80083EDC + offset, 0);
    w_u16(0x80077084, (uint32)count + 1);
    return offset;
}

uint32 ob_game_80094DA4(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x80094DA4, "GAME.BIN");
    uint32 flags = r_u32(record + 28);
    if (flags & 0x10804400)
    {
        uint32 descriptor = ob_game_800A0D38(object);
        uint32 source = r_u32(record + 52);
        uint32 rate = ob_game_800B8FBC(object, source);
        if (!r_u8(descriptor + 27) && ob_game_800A52C4(object, (uint32)(sint32)(sint16)rate, 0xFFFFFFFF))
            w_u32(object + 288, 3);
        ob_main_80011A24(0x800660D4, 128, 256, r_u32(object + 44), time, 0);
        w_u32(object + 164, 256);
        if (r_u32(r_u32(source + 52) + 136) == 1024 && (sint32)time >= r_s32(r_u32(object + 124) + 8))
        {
            ob_draft_unresolved_call(0x800BA234, 3, r_u8(descriptor + 27), 0, time);
            w_u32(r_u32(object + 124) + 8, time + 250);
        }
        sub_80047FF0(record);
    }
    else if (flags & 0x8020)
    {
        sub_80045A7C(r_u32(object + 44), time);
        ob_game_800AC640(object, 2);
        sub_80047FF0(record);
    }
    w_u32(object + 164, 192);
    return 192;
}

static uint32 ob_batch4_clip_depth(uint32 object, uint32 output, uint32 near_plane, uint32 owner)
{
    uint32 bit = near_plane ? 0x20 : 0x10;
    uint32 flags = r_u32(object + 28);
    uint32 second = r_u32(object + 8);
    w_u32(object + 28, flags | bit);
    uint32 first;
    uint32 link;
    if (r_u32(second + 16) & bit)
    {
        first = r_u32(object + 4);
        link = object + 8;
        w_u32(0x80077570, second);
        w_u16(object + 42, 1);
    }
    else
    {
        first = second;
        uint32 other = r_u32(object + 4);
        link = object + 4;
        w_u16(object + 42, 0);
        w_u32(0x80077570, other);
    }
    uint32 plane = r_u16(near_plane ? 0x80077520 : 0x8007752C);
    uint32 first_z = r_u16(first + 12);
    second = r_u32(0x80077570);
    if (near_plane) plane = 0 - plane;
    w_u16(object + 32, plane - first_z);
    uint32 second_z = r_u16(second + 12);
    first_z = r_u16(first + 12);
    uint32 difference = second_z - first_z;
    w_u16(object + 34, difference);
    sint32 second_x = r_s16(second + 8);
    sint32 first_x = r_s16(first + 8);
    sint32 distance = r_s16(object + 32);
    sint32 quotient = ob_batch4_divide(owner, (sint32)((uint32)(second_x - first_x) * (uint32)distance), (sint16)difference);
    sint32 first_y = r_s16(first + 10);
    sint32 second_y = r_s16(second + 10);
    w_u16(output + 8, (uint32)first_x + (uint32)quotient);
    distance = r_s16(object + 32);
    sint32 divisor = r_s16(object + 34);
    quotient = ob_batch4_divide(owner, (sint32)((uint32)(second_y - first_y) * (uint32)distance), divisor);
    first_y = r_u16(first + 10);
    w_u16(output + 12, plane);
    w_u16(output + 10, (uint32)first_y + (uint32)quotient);
    w_u32(link, output);
    return ob_main_8002C5DC(output);
}

uint32 ob_main_8002C018(uint32 object, uint32 output)
{
    FUNCTION_MARKER(0x8002C018, "SLES_008.65");
    return ob_batch4_clip_depth(object, output, 0, 0x8002C018);
}

uint32 ob_main_8002C16C(uint32 object, uint32 output)
{
    FUNCTION_MARKER(0x8002C16C, "SLES_008.65");
    return ob_batch4_clip_depth(object, output, 1, 0x8002C16C);
}

uint32 ob_game_80091F3C(uint32 object, uint32 spread, uint32 time)
{
    FUNCTION_MARKER(0x80091F3C, "GAME.BIN");
    uint32 locals = ob_draft_scratch_acquire(72);
    sub_80045A7C(r_u32(object + 44), time);
    sub_80045378(r_u32(r_u32(0x8006C138) + 44), time, locals + 56);
    uint32 x = r_u32(locals + 56);
    uint32 y = r_u32(locals + 60);
    uint32 z = r_u32(locals + 64);
    w_u32(0x800C84CC, x);
    w_u32(0x800C84D0, y);
    w_u32(0x800C84D4, z);
    ob_game_80097578(object, 0x800C84C0, time);
    if (spread)
    {
        uint32 random = ob_draft_unresolved_call(0x8001AFC8, 0);
        if (spread == 0xFFFFFFFF && random == 0x80000000)
            return ob_native_missing_value(0x80091F3C, "BREAK 6 signed remainder overflow");
        sint32 remainder = (sint32)random % (sint32)spread;
        uint32 half = (uint32)((sint32)(spread + (spread >> 31)) >> 1);
        w_u16(0x800C84C0, r_u16(0x800C84C0) + (uint32)remainder - half);
    }
    sub_80029F58((uint32)(sint32)r_s16(0x800C84C0), locals);
    uint32 state = r_u32(object + 124);
    w_u16(state + 4, r_u16(0x800C84C0));
    w_u32(locals + 28, 0);
    w_u32(locals + 24, 0);
    w_u32(locals + 32, 600);
    sub_80029B70(locals + 24, locals, locals + 40);
    sub_80045A44(r_u32(object + 44), locals + 40);
    sub_80045848(r_u32(object + 44), locals);
    uint32 result = sub_80045B74(r_u32(object + 44));
    ob_draft_scratch_release(locals);
    return result;
}

uint32 ob_game_800B3EF0(uint32 object, uint32 mode, uint32 time)
{
    FUNCTION_MARKER(0x800B3EF0, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    uint32 deadline = time + 100;
    uint32 selection = mode & 0xFF;
    if (selection == 1) deadline = (time + r_u32(data + 36) - 5000) | 1;
    uint32 state = r_u8(data + 45);
    if (state > 128)
    {
        w_u8(data + 47, mode);
        w_u32(data + 40, deadline);
        w_u32(data + 36, (uint32)(sint32)r_s16(0x800C5B38 + selection * 2));
        return sub_80011984(0x80066620, 128, 15, 15, 256, 0, 0);
    }
    if (state) w_u8(data + 45, 2 - state);
    uint32 sound = 0x80066620;
    if (selection == 4)
    {
        sound = 0x80067224;
        w_u8(data + 45, 1);
    }
    else if (selection == 3)
    {
        ob_game_8009A704(object);
        w_u8(data + 45, 128);
    }
    else w_u8(data + 45, ~r_u8(data + 45));
    sub_80011984(sound, 128, 15, 15, 256, 0, 0);
    w_u8(data + 47, mode);
    uint32 result = (uint32)(sint32)r_s16(0x800C5B38 + selection * 2);
    w_u32(data + 40, deadline);
    w_u32(data + 36, result);
    return result;
}

uint32 ob_game_800BB658(uint32 object, uint32 unused, uint32 time)
{
    FUNCTION_MARKER(0x800BB658, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    sub_80045A7C(r_u32(r_u32(r_u32(object + 48) + 32) + 52), time);
    if (time == r_u32(object + 28)) return 2;
    uint32 data = r_u32(object + 108);
    uint32 state = r_u32(data);
    if (state == 1 || state == 2)
    {
        if (state == 1) sub_80011984(0x8006647C, 128, 15, 15, 256, 0, 0);
        else
        {
            uint32 geometry = r_u32(object + 48);
            uint32 resource = r_u32(object + 112);
            uint32 node = r_u32(geometry + 32);
            w_u32(node + 40, r_u32(resource + 20));
        }
        uint32 node = r_u32(r_u32(r_u32(object + 48) + 32) + 52);
        sub_80045A44(node, state == 1 ? 0x800C6198 : 0x800C61A4);
        ob_game_800BB630(object, 0, time + 3000);
        uint32 result = r_u32(data) + 1;
        w_u32(data, result);
        return result;
    }
    if ((sint32)state < 3) return 1;
    if (state != 3) return 3;
    uint32 result = sub_80045A44(r_u32(r_u32(r_u32(object + 48) + 32) + 52), 0x8006C160);
    w_u32(data, 0);
    return result;
}

uint32 ob_main_80015B1C(uint32 seconds)
{
    FUNCTION_MARKER(0x80015B1C, "SLES_008.65");
    if ((sint32)seconds >= 60)
    {
        uint32 scale = r_u32(0x8006C174);
        ob_main_80015CAC((uint32)(sint32)(sint16)(192 - 30 * scale), 20, (uint32)(sint32)(sint16)((sint32)seconds / 60));
    }
    uint32 scale = r_u32(0x8006C174);
    ob_main_80015CAC((uint32)(sint32)(sint16)(192 - 14 * scale), 20, 10);
    sint32 tens = (sint32)seconds % 60 / 10;
    scale = r_u32(0x8006C174);
    ob_main_80015CAC((uint32)(sint32)(sint16)(192 - 5 * scale), 20, (uint32)(sint32)(sint16)tens);
    scale = r_u32(0x8006C174);
    return ob_main_80015CAC((uint32)(sint32)(sint16)(192 + 12 * scale), 20, (uint32)(sint32)(sint16)((sint32)seconds % 10));
}


void ob_main_80013A6C(uint32 text, uint32 x, uint32 y, uint32 red, uint32 green, uint32 blue, uint32 flags)
{
    FUNCTION_MARKER(0x80013A6C, "SLES_008.65");
    uint32 character = r_u8(text);
    while (character)
    {
        if (((character - 97) & 0xFF) < 26) character -= 32;
        character &= 0xFF;
        if (character == 32) x += 9;
        else if (r_u8(0x80065D4C))
        {
            uint32 index = 0;
            uint32 entry = r_u8(0x80065D4C);
            while (entry != character)
            {
                entry = r_u8(0x80065D4C + ++index);
                if (!entry) break;
            }
            if (r_u8(0x80065D4C + index))
            {
                uint32 u = index % 7 * 9;
                uint32 v = index / 7 * 9;
                sub_80020864(0x8006664C, u + 1, v + 1, 8, 8, x, y, flags, red, green, blue);
                x += 9;
            }
        }
        character = r_u8(++text);
    }
}

uint32 ob_main_8004D4A0(uint32 descriptor, uint32 x_table, uint32 z_table, uint32 condition, uint32 coarse_x, uint32 coarse_z)
{
    FUNCTION_MARKER(0x8004D4A0, "SLES_008.65");
    uint32 x_selector = 0x800736DC + (uint32)(sint32)r_s8(x_table) * 4;
    uint32 base_x = (uint32)(sint32)(sint8)coarse_x * 4;
    uint32 base_z = (uint32)(sint32)(sint8)coarse_z * 4;
    for (uint32 column = 0; column < 4; ++column, ++x_selector)
    {
        uint32 z_selector = 0x800736DC + (uint32)(sint32)r_s8(z_table) * 4;
        for (uint32 row = 0; row < 4; ++row, ++z_selector)
        {
            uint32 map = r_u32(0x80077644);
            uint32 packed = r_u16(descriptor);
            uint32 cell = r_u32(map + 20);
            uint32 block = packed & 0xFFF0;
            if (block)
            {
                uint32 z = (uint32)(sint32)r_s8(z_selector);
                uint32 x = (uint32)(sint32)r_s8(x_selector);
                cell += (block + x + z * 4) * 4;
            }
            uint32 depth = condition;
            if (depth)
            {
                uint32 x = r_u8(x_selector);
                uint32 z = r_u8(z_selector);
                uint32 height = r_u16(cell + 2) & 0xFFFC;
                depth = sub_8004DAA4((uint32)(sint32)(sint8)(x + coarse_x * 4), (uint32)(sint32)(sint8)(z + coarse_z * 4), 2, (uint32)((sint32)(height << 16) >> 14));
            }
            if (depth != 0xFFFFFFFF)
            {
                uint32 x = (uint32)(sint32)r_s8(x_selector);
                uint32 z = (uint32)(sint32)r_s8(z_selector);
                sub_8004E028(base_x + x, base_z + z, cell);
            }
        }
    }
    return 0;
}

uint32 ob_main_8004D2FC(uint32 descriptor, uint32 x_record, uint32 z_record, uint32 x_table, uint32 z_table, uint32 condition)
{
    FUNCTION_MARKER(0x8004D2FC, "SLES_008.65");
    uint32 x_selector = 0x800736DC + (uint32)(sint32)r_s8(x_record + 1) * 4;
    for (uint32 column = 0; column < 4; ++column, ++x_selector, ++x_table)
    {
        uint32 z_selector = 0x800736DC + (uint32)(sint32)r_s8(z_record + 1) * 4;
        uint32 z_pointer = z_table;
        for (uint32 row = 0; row < 4; ++row, ++z_selector, ++z_pointer)
        {
            uint32 map = r_u32(0x80077644);
            uint32 packed = r_u16(descriptor);
            uint32 cell = r_u32(map + 16);
            uint32 block = packed & 0xFFF0;
            if (block)
            {
                uint32 z = (uint32)(sint32)r_s8(z_selector);
                uint32 x = (uint32)(sint32)r_s8(x_selector);
                cell += (block + x + z * 4) * 2;
            }
            uint32 depth = condition;
            if (depth)
            {
                uint32 x = r_u8(x_record);
                uint32 local_x = r_u8(x_selector);
                uint32 local_z = r_u8(z_selector);
                uint32 z = r_u8(z_record);
                depth = sub_8004DAA4((uint32)(sint32)(sint8)(local_x + x * 4), (uint32)(sint32)(sint8)(local_z + z * 4), 1, 0);
            }
            if (depth != 0xFFFFFFFF)
            {
                uint32 x = r_u8(x_record);
                uint32 local_x = r_u8(x_selector);
                uint32 z = r_u8(z_record);
                uint32 local_z = r_u8(z_selector);
                ob_main_8004D4A0(cell, x_table, z_pointer, depth, (uint32)(sint32)(sint8)(local_x + x * 4), (uint32)(sint32)(sint8)(local_z + z * 4));
            }
        }
    }
    return 0;
}

uint32 ob_game_80091918(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x80091918, "GAME.BIN");
    uint32 locals = ob_draft_scratch_acquire(80);
    uint32 first = r_u32(0x8008D444);
    uint32 second = r_u32(0x8008D448);
    uint32 third = r_u32(0x8008D44C);
    w_u32(locals + 32, first);
    w_u32(locals + 36, second);
    w_u32(locals + 40, third);
    sub_80045A7C(r_u32(object + 44), time);
    if (r_u32(object + 64)) sub_80045F20(object + 64);
    sub_800453C4(r_u32(object + 44), time, locals);
    w_u32(locals + 12, 180);
    uint32 angle = r_u16(r_u32(object + 124) + 4);
    w_u16(locals + 18, 0);
    w_u16(locals + 20, 0);
    w_u16(locals + 22, 0);
    w_u8(locals + 24, 7);
    w_u8(locals + 25, 0);
    w_u8(locals + 26, 0);
    w_u8(locals + 27, 0);
    w_u16(locals + 16, angle);
    ob_game_800A50BC(locals);
    uint32 child = ob_game_800AEEE8(time);
    w_u32(locals + 64, 0);
    w_u32(locals + 68, 0xFFFFFF9C);
    w_u32(locals + 72, r_u32(r_u32(object + 124)));
    uint32 matrix = ob_draft_unresolved_call(0x8004545C, 2, r_u32(child + 44), time);
    sub_80029B70(locals + 64, matrix, locals + 48);
    sub_80045A44(r_u32(child + 44), locals + 48);
    sub_80045848(r_u32(child + 44), matrix);
    for (uint32 index = 0; index < 3; ++index)
    {
        w_u32(locals + 12, 181);
        uint32 random = ob_draft_unresolved_call(0x8001AFC8, 0);
        w_u16(locals + 16, random);
        ob_game_800A50BC(locals);
        child = ob_game_800AEEE8(time);
        sub_80045A44(r_u32(child + 44), locals + 32);
    }
    uint32 result = ob_game_800BCAA0(object);
    ob_draft_scratch_release(locals);
    return result;
}

uint32 ob_game_800A8B44(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x800A8B44, "GAME.BIN");
    uint32 slot = (uint32)(sint32)r_s16(object + 326);
    ob_game_800C191C(0x800CBA00 + slot * 104);
    if (r_u32(record + 28) & 0x10904400)
    {
        uint32 kind = r_u32(object + 292);
        uint32 source = r_u32(record + 52);
        if (kind - 74 < 2 || kind - 76 < 2 || (kind == 68 && r_s16(source + 132) == 6))
            return (uint32)sub_80047FF0(record);
        uint32 rate = ob_game_800B8FBC(object, source);
        sub_80047FF0(record);
        slot = (uint32)(sint32)r_s16(object + 326);
        uint32 result = r_u16(0x800CBA46 + slot * 104);
        if (result)
        {
            result = ob_game_800A52C4(object, (uint32)(sint32)(sint16)rate, 0xFFFFFFFF);
            if (result) result = ob_draft_unresolved_call(0x800A8CE0, 2, object, time);
        }
        return result;
    }
    if (r_u32(object + 292) - 15 >= 2) return (uint32)sub_80047FF0(record);
    uint32 shape = r_u32(object + 52);
    w_u32(object + 288, 3);
    sub_80046544(shape);
    sub_80045A7C(r_u32(object + 44), time);
    sub_80045A44(r_u32(object + 44), 0x8006C160);
    sub_80047FF0(record);
    ob_game_800A9680(object, time);
    return ob_game_800BCAA0(object);
}

uint32 ob_game_800BBEE0(void)
{
    FUNCTION_MARKER(0x800BBEE0, "GAME.BIN");
    uint32 attributes = ob_draft_scratch_acquire(32);
    w_u32(attributes + 12, 237);
    w_u16(attributes + 16, 0);
    w_u16(attributes + 20, 0);
    w_u16(attributes + 22, 0);
    w_u8(attributes + 24, 7);
    w_u8(attributes + 25, 0);
    w_u8(attributes + 26, 0);
    w_u8(attributes + 27, 0);
    uint32 random = ob_draft_unresolved_call(0x8001B008, 0);
    uint32 origin = r_u32(r_u32(0x80077190) + 16);
    w_u32(attributes + 4, 10000);
    w_u32(attributes, origin - 0x4000 + random);
    random = ob_draft_unresolved_call(0x8001B008, 0);
    origin = r_u32(r_u32(0x80077190) + 24);
    w_u32(attributes + 8, origin - 0x4000 + random);
    random = ob_draft_unresolved_call(0x8001B008, 0);
    w_u16(attributes + 18, (uint32)(((sint32)random >> 8) % 3));
    uint32 index = (uint32)(sint32)(sint16)ob_game_800A50BC(attributes);
    uint32 group = r_u16(attributes + 22);
    uint32 table = r_u32(0x8007719C);
    uint32 head = r_u32(table + group * 4);
    uint32 entry = 0x800CBA00 + index * 104;
    if (!head)
    {
        w_u32(entry + 72, entry);
        group = r_u16(attributes + 22);
        w_u32(table + group * 4, entry);
    }
    else
    {
        uint32 last = head;
        while (r_u32(last + 72) != head) last = r_u32(last + 72);
        w_u32(last + 72, entry);
        group = r_u16(attributes + 22);
        table = r_u32(0x8007719C);
        w_u32(entry + 72, r_u32(table + group * 4));
    }
    uint32 result = index * 104;
    w_u16(0x800CBA58 + result, 0xFFFF);
    ob_draft_scratch_release(attributes);
    return result;
}

uint32 ob_game_8009E750(uint32 object, uint32 scale, uint32 time)
{
    FUNCTION_MARKER(0x8009E750, "GAME.BIN");
    uint32 narrow = (uint32)(sint32)(sint16)scale;
    ob_draft_unresolved_call(0x800440B8, 2, r_u32(object + 48), narrow);
    uint32 child = r_u32(object + 136);
    if (child) ob_draft_unresolved_call(0x800440B8, 2, r_u32(child + 48), narrow);
    sint32 first_size = (sint32)(scale * 1300) / 256;
    uint32 half = (uint32)((sint32)(scale + (scale >> 31)) >> 1);
    sint32 second_size = (sint32)((half + 128) * 5200) / 256;
    uint32 locals = ob_draft_scratch_acquire(144);
    ob_game_800C0F70(locals, (uint32)first_size, (uint32)second_size);
    ob_game_8008FFE0(object, locals, 0x800C3484);
    uint32 descriptor = r_u32(r_u32(object + 48) + 48);
    w_u32(locals + 80, 0x8009DEDC);
    w_u32(locals + 4, descriptor);
    sub_8004651C(r_u32(object + 52));
    uint32 shape = sub_80046184(object, locals, time);
    uint32 effect = locals + 88;
    w_u32(object + 52, shape);
    w_u32(effect + 4, 0x10000001);
    w_u32(effect, 0);
    ob_game_80090070(object, effect, 0x800C3664);
    uint32 size = (uint32)((sint32)(scale * 800) / 256);
    w_u32(effect + 16, size);
    w_u32(effect + 12, size);
    w_u32(effect + 8, size);
    w_u32(effect + 48, 0x8009DE18);
    w_u16(effect + 38, 0xFFFF);
    w_u16(effect + 36, 0);
    sub_8004F31C(r_u32(object + 56));
    uint32 result = (uint32)sub_8004F074((sint32)object, (sint32)effect, (sint32)time);
    w_u32(object + 56, result);
    ob_draft_scratch_release(locals);
    return result;
}

uint32 ob_main_8003DDB4(uint32 color)
{
    FUNCTION_MARKER(0x8003DDB4, "SLES_008.65");
    uint32 remaining = r_u16(0x800775B4) - 2;
    uint32 indices = r_u32(0x80077384);
    uint32 first = r_u16(indices);
    if (remaining != 0xFFFFFFFF)
    {
        do
        {
            uint32 previous = r_u32(0x80077634);
            uint32 packet = r_u32(0x800774A8);
            indices = r_u32(0x80077384);
            uint32 tag = r_u32(previous);
            w_u32(0x800774A8, packet + 16);
            w_u32(0x80077384, indices + 2);
            w_u32(0x80077634, packet);
            w_u32(previous, (tag & 0xFF000000) | (packet & 0xFFFFFF));
            uint32 index = r_u16(indices);
            uint32 vertices = r_u32(0x80077574);
            w_u32(packet + 8, r_u32(vertices + index * 24));
            index = r_u16(indices + 2);
            w_u32(packet + 12, r_u32(vertices + index * 24));
            w_u32(packet + 4, r_u32(color));
            uint32 command = r_u16(0x800774E4) & 0x100 ? 66 : 64;
            w_u8(packet + 3, 3);
            w_u8(packet + 7, command);
            --remaining;
        } while (remaining != 0xFFFFFFFF);
    }
    uint32 packet = r_u32(0x800774A8);
    uint32 previous = r_u32(0x80077634);
    w_u32(0x800774A8, packet + 16);
    uint32 tag = r_u32(previous);
    w_u32(0x80077634, packet);
    indices = r_u32(0x80077384);
    w_u32(previous, (tag & 0xFF000000) | (packet & 0xFFFFFF));
    uint32 index = r_u16(indices);
    uint32 vertices = r_u32(0x80077574);
    w_u32(packet + 8, r_u32(vertices + index * 24));
    w_u32(packet + 12, r_u32(vertices + first * 24));
    w_u32(packet + 4, r_u32(color));
    uint32 result = r_u16(0x800774E4) & 0x100 ? 66 : 64;
    w_u8(packet + 3, 3);
    w_u8(packet + 7, result);
    return result;
}


static uint32 ob_batch4_clip_side(uint32 object, uint32 output, uint32 bit, uint32 axis, uint32 plane_address, uint32 positive, uint32 owner)
{
    uint32 flags = r_u32(object + 28);
    uint32 second = r_u32(object + 8);
    w_u32(object + 28, flags | bit);
    uint32 first;
    uint32 link;
    if (r_u32(second + 16) & bit)
    {
        first = r_u32(object + 4);
        link = object + 8;
        w_u32(0x80077570, second);
        w_u16(object + 42, 1);
    }
    else
    {
        first = second;
        uint32 other = r_u32(object + 4);
        link = object + 4;
        w_u16(object + 42, 0);
        w_u32(0x80077570, other);
    }
    uint32 coordinate = r_u16(first + axis);
    uint32 plane = r_u16(plane_address);
    second = r_u32(0x80077570);
    uint32 shift = positive ? plane : 0 - plane;
    w_u16(first + axis, coordinate + shift);
    w_u16(second + axis, r_u16(second + axis) + shift);
    uint32 depth = r_u16(first + 12);
    coordinate = r_u16(first + axis);
    uint32 distance = positive ? depth + coordinate : depth - coordinate;
    w_u16(object + 32, distance);
    uint32 second_axis = (uint32)(sint32)r_s16(second + axis);
    uint32 second_depth = (uint32)(sint32)r_s16(second + 12);
    uint32 divisor = distance + (positive ? 0 - second_axis - second_depth : second_axis - second_depth);
    w_u16(object + 34, divisor);
    sint32 second_x = r_s16(second + 8);
    sint32 first_x = r_s16(first + 8);
    sint32 numerator = (sint32)((uint32)(second_x - first_x) * (uint32)(sint32)r_s16(object + 32));
    sint32 quotient = ob_batch4_divide(owner, numerator, (sint16)divisor);
    sint32 first_y = r_s16(first + 10);
    sint32 second_y = r_s16(second + 10);
    w_u16(output + 8, (uint32)first_x + (uint32)quotient);
    sint32 amount = r_s16(object + 32);
    numerator = (sint32)((uint32)(second_y - first_y) * (uint32)amount);
    quotient = ob_batch4_divide(owner, numerator, r_s16(object + 34));
    if (axis == 10)
    {
        uint32 y = r_u16(first + 10) + (uint32)quotient;
        w_u16(output + 10, y);
        uint32 reread = r_u16(output + 10);
        w_u16(output + 12, positive ? 0 - y : y);
        w_u16(output + 10, reread - shift);
    }
    else if (!positive)
    {
        uint32 x_depth = r_u16(output + 8);
        uint32 y = r_u16(first + 10);
        uint32 x = r_u16(output + 8);
        w_u16(output + 12, x_depth);
        w_u16(output + 8, x + plane);
        w_u16(output + 10, y + (uint32)quotient);
    }
    else
    {
        uint32 y = r_u16(first + 10);
        uint32 x = r_u16(output + 8);
        uint32 x_depth = r_u16(output + 8);
        w_u16(output + 8, x - plane);
        w_u16(output + 12, 0 - x_depth);
        w_u16(output + 10, y + (uint32)quotient);
    }
    w_u16(first + axis, r_u16(first + axis) - shift);
    w_u16(second + axis, r_u16(second + axis) - shift);
    w_u32(link, output);
    return ob_main_8002C5DC(output);
}

uint32 ob_main_8002B970(uint32 object, uint32 output)
{
    FUNCTION_MARKER(0x8002B970, "SLES_008.65");
    return ob_batch4_clip_side(object, output, 4, 10, 0x80077524, 0, 0x8002B970);
}

uint32 ob_main_8002BCC4(uint32 object, uint32 output)
{
    FUNCTION_MARKER(0x8002BCC4, "SLES_008.65");
    return ob_batch4_clip_side(object, output, 1, 8, 0x80077522, 0, 0x8002BCC4);
}

uint32 ob_main_8002BB18(uint32 object, uint32 output)
{
    FUNCTION_MARKER(0x8002BB18, "SLES_008.65");
    return ob_batch4_clip_side(object, output, 8, 10, 0x8007751E, 1, 0x8002BB18);
}

uint32 ob_main_8002BE6C(uint32 object, uint32 output)
{
    FUNCTION_MARKER(0x8002BE6C, "SLES_008.65");
    return ob_batch4_clip_side(object, output, 2, 8, 0x8007751C, 1, 0x8002BE6C);
}

uint32 ob_game_800A20D0(uint32 object, uint32 player, uint32 selector, uint32 time)
{
    FUNCTION_MARKER(0x800A20D0, "GAME.BIN");
    uint32 source = (uint32)sub_800437C4(r_u32(r_u32(object + 44) + 12), (sint32)selector);
    uint32 target = r_u32(r_u32(0x800D5C98 + (player & 0xFF) * 4) + 44);
    sub_80045A7C(target, time);
    sub_80045A7C(source, time);
    uint32 first = sub_80045464(source, time);
    uint32 second = sub_80045464(target, time);
    uint32 elapsed = time - r_u32(r_u32(object + 108) + 12);
    if (!elapsed) return sub_80045A44(target, 0x8006C160);
    uint32 vector = ob_draft_scratch_acquire(16);
    for (uint32 axis = 0; axis < 3; ++axis)
    {
        uint32 a = r_u32(first + axis * 4);
        uint32 b = r_u32(second + axis * 4);
        sint32 numerator = (sint32)((a - b) << 8);
        w_u32(vector + axis * 4, (uint32)ob_batch4_divide(0x800A20D0, numerator, (sint32)elapsed));
    }
    uint32 result = sub_80045A44(target, vector);
    ob_draft_scratch_release(vector);
    return result;
}

uint32 ob_game_800949FC(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x800949FC, "GAME.BIN");
    uint32 flags = r_u32(record + 28);
    if (flags & 0x10804400)
    {
        uint32 descriptor = ob_game_800A0D38(object);
        uint32 source = r_u32(record + 52);
        uint32 rate = ob_game_800B8FBC(object, source);
        if (!r_u8(descriptor + 27) && r_u32(object + 292) - 172 >= 2 && ob_game_800A52C4(object, (uint32)(sint32)(sint16)rate, 0xFFFFFFFF))
            w_u32(object + 288, 3);
        if (r_u32(object + 292) == 157)
            ob_main_80011A24(0x80066520, 128, 256, r_u32(object + 44), time, 0);
        w_u32(object + 164, 256);
        if (r_u32(r_u32(source + 112) + 96) == 255 && (sint32)time >= r_s32(r_u32(object + 124) + 8))
        {
            ob_draft_unresolved_call(0x800BA234, 3, r_u8(descriptor + 27), 0, time);
            w_u32(r_u32(object + 124) + 8, time + 250);
        }
        sub_80047FF0(record);
    }
    else if (flags & 0x18020)
    {
        sub_80045A7C(r_u32(object + 44), time);
        ob_game_800AC640(object, 2);
        sub_80047FF0(record);
        if (r_u32(object + 292) == 157)
            ob_main_80011A24(0x80066520, 128, 256, r_u32(object + 44), time, 0);
    }
    w_u32(object + 164, 192);
    return 192;
}

void ob_main_80026A0C(uint32 requested)
{
    FUNCTION_MARKER(0x80026A0C, "SLES_008.65");
    uint32 block = r_u32(0x80077218);
    while (block)
    {
        if (r_u32(r_u32(r_u32(0x80077224) + 8) + 16) >= requested) break;
        if (r_u8(block + 32) & 0x80)
        {
            uint32 next = r_u32(block + 4);
            if (next)
            {
                uint32 capacity = r_u32(block + 16) - 4;
                uint32 candidate = r_u32(0x8007721C);
                while (next < candidate)
                {
                    if ((r_u8(candidate + 32) & 1) && !r_u16(candidate + 34))
                    {
                        uint32 size = r_u32(candidate + 16);
                        uint32 used = r_u32(candidate + 20);
                        if (capacity >= size - used) break;
                    }
                    candidate = r_u32(candidate);
                }
                if (next < candidate)
                {
                    sub_8002785C(block);
                    /* TODO Bind the existing memory move adapters */
                    ob_draft_unresolved_call(0x800275F8, 2, candidate, block);
                    uint32 size = r_u32(candidate + 16);
                    uint32 used = r_u32(candidate + 20);
                    sub_800271EC(block, size - used);
                    ob_draft_unresolved_call(0x8002776C, 2, block, candidate + 40);
                    sub_80027154(candidate);
                }
                else if ((r_u8(next + 32) & 1) && !r_u16(next + 34))
                {
                    uint32 size = r_u32(next + 16);
                    uint32 used = r_u32(next + 20);
                    uint32 available = size - used;
                    sub_8002785C(block);
                    sub_80026950(block);
                    ob_draft_unresolved_call(0x800275F8, 2, next, block);
                    ob_draft_unresolved_call(0x8002776C, 2, block, next + 40);
                    sub_800271EC(block, available);
                }
            }
        }
        block = r_u32(block + 4);
    }
}

uint32 ob_game_800B8818(uint32 node, uint32 size, uint32 height, uint32 time)
{
    FUNCTION_MARKER(0x800B8818, "GAME.BIN");
    /* TODO Preserve unspecified fields of the original effect record */
    uint32 record = ob_draft_scratch_acquire(96);
    sub_80029E54(record + 12);
    uint32 position = sub_80045464(node, time);
    w_u32(record + 44, 0x800C48E4);
    w_u8(record + 92, 12);
    w_u8(record + 93, 4);
    w_u32(record + 48, 0);
    w_u32(record + 60, 0);
    w_u8(record + 94, 0);
    w_u32(record + 76, 1);
    uint32 random = ob_draft_unresolved_call(0x8001B008, 0);
    w_u32(record + 56, 1500 * (random & 7) / 4);
    random = ob_draft_unresolved_call(0x8001B008, 0);
    w_u32(record, r_u32(position) + (random & 0x1FF) - 256);
    w_u32(record + 4, r_u32(position + 4) + height);
    random = ob_draft_unresolved_call(0x8001B008, 0);
    w_u32(record + 8, r_u32(position + 8) + (random & 0x1FF) - 256);
    random = ob_draft_unresolved_call(0x8001B008, 0);
    w_u32(record + 32, (random & 0xFF) - 128);
    random = ob_draft_unresolved_call(0x8001B008, 0);
    w_u32(record + 36, (random & 0xFF) + 128);
    random = ob_draft_unresolved_call(0x8001B008, 0);
    w_u32(record + 40, (random & 0xFF) - 128);
    random = ob_draft_unresolved_call(0x8001B008, 0);
    uint32 product = (uint32)((sint32)size >> 1) * ((random & 7) + 1);
    uint32 delta = (uint32)((sint32)product >> 3) - (uint32)((sint32)size >> 2);
    uint32 varied = size + (uint32)(sint32)(sint16)delta;
    if ((sint32)varied < 32) varied = 32;
    w_u16(record + 88, varied);
    w_u16(record + 90, (varied & 0xFFFF) * 2);
    w_u16(record + 86, (varied & 0xFFFF) * 2);
    ob_game_80092408(r_u32(0x80083E34), record, time, 6);
    ob_draft_scratch_release(record);
    return 1;
}


uint32 ob_game_80091AC8(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x80091AC8, "GAME.BIN");
    uint32 flags = r_u32(record + 28);
    if (flags & 0x10804400)
    {
        uint32 rate = ob_game_800B8FBC(object, r_u32(record + 52));
        sub_80047FF0(record);
        sint32 narrow = (sint16)rate;
        if (ob_game_800A52C4(object, (uint32)narrow, 0xFFFFFFFF))
        {
            uint32 kind = r_u32(object + 292);
            if (kind < 3) return kind < 5;
            if (kind < 5)
            {
                ob_game_80092098(object, time);
                return ob_game_8009172C(object, time);
            }
            if (kind != 10) return 10;
            ob_game_80092098(object, time);
            ob_main_80011A24(0x80068418, 128, 256, r_u32(object + 44), time, 0);
            return ob_game_80091918(object, time);
        }
        if (narrow > 0 && r_u32(object + 292) == 10)
            return ob_main_80011A24(0x80068418, 255, (rate * 4 + 256) & 0xFFFC, r_u32(object + 44), time, 0);
        return 10;
    }
    if (flags & 0x120)
    {
        sub_80045A7C(r_u32(object + 44), time);
        if (r_u32(object + 292) == 3)
        {
            ob_game_800AC640(object, 1);
            sub_80047FF0(record);
            return ob_draft_unresolved_call(0x800AC6F8, 2, object, time);
        }
        ob_game_800AC640(object, 2);
        sub_80047FF0(record);
        return ob_draft_unresolved_call(0x800AD01C, 2, object, time);
    }
    return (uint32)sub_80047FF0(record);
}

uint32 ob_game_800AA198(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x800AA198, "GAME.BIN");
    uint32 source = r_u32(record + 52);
    sub_80045A7C(r_u32(object + 44), time);
    uint32 flags = r_u32(record + 28);
    if (flags & 0x10804400)
    {
        uint32 slot = (uint32)(sint32)r_s16(object + 326);
        if (r_u16(0x800CBA46 + slot * 104))
        {
            source = r_u32(record + 52);
            if (r_s16(source + 132) != 5)
            {
                sint32 rate = (sint16)ob_game_800B8FBC(object, source);
                rate >>= 6;
                if (rate <= 0) rate = 1;
                else rate = (sint16)ob_game_800B8FBC(object, source) >> 6;
                w_u32(0x800C835C, r_u32(0x800C835C) - ((uint32)rate << 6));
                if (ob_game_800A52C4(object, (uint32)rate, 0xFFFFFFFF))
                    ob_game_800AAC34(object, time);
            }
        }
        return (uint32)sub_80047FF0(record);
    }
    if (!(flags & 0x8020)) return (uint32)sub_80047FF0(record);
    if (r_u32(source + 292) != 255)
    {
        ob_game_800A2AEC(object, source, 1500, time);
        w_u32(r_u32(source + 124) + 8, time + 100);
    }
    uint32 slot = (uint32)(sint32)r_s16(object + 326);
    if (r_u16(0x800CBA46 + slot * 104))
    {
        slot = (uint32)(sint32)r_s16(source + 326);
        if (r_u16(0x800CBA46 + slot * 104)) ob_game_800A52C4(source, 8, 0xFFFFFFFF);
    }
    sub_80047FF0(record);
    return sub_80045A44(r_u32(object + 44), 0x8006C160);
}

uint32 ob_game_8009172C(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x8009172C, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    ob_game_800A6C34(object, 0xFFFFFFFF, time);
    sub_8001195C((uint32)(sint32)r_s16(object + 306));
    uint32 geometry = r_u32(object + 48);
    w_u16(object + 306, 0xFFFF);
    w_u32(r_u32(geometry + 32) + 40, 0x800662CC);
    uint32 node = r_u32(r_u32(r_u32(object + 48) + 32) + 52);
    uint32 x = r_u32(node + 108);
    uint32 y = r_u32(node + 112);
    uint32 z = r_u32(node + 116);
    uint32 locals = ob_draft_scratch_acquire(64);
    w_u32(locals, x);
    w_u32(locals + 4, y);
    w_u32(locals + 8, z);
    uint32 kind = r_u32(object + 292);
    /* TODO The original leaves other attribute fields and unsupported kinds uninitialized */
    if (kind == 3) w_u32(locals + 12, 150);
    else if (kind == 4) w_u32(locals + 12, 151);
    w_u16(locals + 22, 0);
    w_u16(locals + 16, r_u16(r_u32(object + 124) + 4));
    ob_game_800A50BC(locals);
    uint32 slot = (uint32)(sint32)r_s16(0x800C9AB4);
    uint32 child = r_u32(0x800CBA50 + slot * 104);
    w_u32(r_u32(child + 44) + 132, 0);
    w_u32(r_u32(child + 44) + 136, 0xFFFFFFFF);
    w_u32(r_u32(child + 44) + 140, 0);
    sub_80045ADC(r_u32(child + 44));
    w_u32(locals + 52, 0);
    w_u32(locals + 48, 0);
    w_u32(locals + 56, r_u32(r_u32(object + 124)) * 3);
    uint32 matrix = ob_draft_unresolved_call(0x8004545C, 2, r_u32(object + 44), time);
    sub_80029B70(locals + 48, matrix, locals + 32);
    sub_80045A44(r_u32(object + 44), locals + 32);
    sub_80045848(r_u32(object + 44), matrix);
    uint32 active = r_u32(object + 64);
    w_u32(object + 28, time);
    if (active) sub_80045F20(object + 64);
    w_u32(object + 100, 0x80094884);
    w_u32(object + 96, 0);
    w_u32(object + 92, time + 200);
    uint32 result = sub_80045EF4(object + 64);
    ob_draft_scratch_release(locals);
    return result;
}

uint32 ob_game_800A2760(uint32 owner, uint32 original, uint32 output, uint32 count, uint32 unused, uint32 time)
{
    FUNCTION_MARKER(0x800A2760, "GAME.BIN");
    w_u16(output + 16, r_u16(original + 16));
    w_u16(output + 18, r_u16(original + 18));
    uint32 angle = r_u16(original + 20);
    w_u16(output + 22, 0);
    w_u32(output + 12, 38);
    w_u16(output + 20, angle);
    w_u32(output + 4, r_u32(original + 4));
    uint32 index = (r_u16(original + 16) + 8) >> 4;
    uint32 offset = (uint32)(sint32)r_s16(0x8006CB04 + index * 2) * 375;
    uint32 position = r_u32(original + 8);
    w_u32(output + 8, position - (uint32)((sint32)offset >> 12));
    index = (r_u16(original + 16) + 8) >> 4;
    offset = (uint32)(sint32)r_s16(0x8006C304 + index * 2) * 125;
    position = r_u32(original);
    w_u32(output, position - (uint32)((sint32)offset >> 12));
    w_u8(0x800D5C90, ob_game_800A296C());
    uint32 child = ob_game_800BC3D8(owner, output, time);
    w_u32(0x800D5C98 + r_u8(0x800D5C90) * 4, child);
    if (count == 2)
    {
        index = (r_u16(original + 16) + 8) >> 4;
        offset = (uint32)(sint32)r_s16(0x8006C304 + index * 2) * 125;
        position = r_u32(original);
        w_u32(output, position + (uint32)((sint32)offset >> 12));
        w_u8(0x800D5C91, ob_game_800A296C());
        child = ob_game_800BC3D8(owner, output, time);
        w_u32(0x800D5C98 + r_u8(0x800D5C91) * 4, child);
    }
    w_u32(output, r_u32(original));
    w_u32(output + 8, r_u32(original + 8));
    w_u32(output + 12, r_u32(original + 12));
    return output;
}

uint32 ob_main_8001D5F0(uint32 output, uint32 mode)
{
    FUNCTION_MARKER(0x8001D5F0, "SLES_008.65");
    for (uint32 offset = 0; offset < 368; offset += 16)
    {
        uint32 a = r_u32(0x800899A8 + offset);
        uint32 b = r_u32(0x800899AC + offset);
        uint32 c = r_u32(0x800899B0 + offset);
        uint32 d = r_u32(0x800899B4 + offset);
        w_u32(output + offset, a);
        w_u32(output + offset + 4, b);
        w_u32(output + offset + 8, c);
        w_u32(output + offset + 12, d);
    }
    uint32 a = r_u32(0x80089B18);
    uint32 b = r_u32(0x80089B1C);
    w_u32(output + 368, a);
    w_u32(output + 372, b);
    for (uint32 index = 0; index < 4; ++index)
        w_u8(output + 34 + index, r_u8(0x8006C22C + index));
    for (uint32 table = 0; table < 5; ++table)
        for (uint32 index = 0; index < 13; ++index)
        {
            uint32 source = r_u32(0x80065CB0 + table * 4);
            w_u32(output + 80 + table * 52 + index * 4, r_u32(source + index * 4));
        }
    w_u8(output + 33, mode);
    w_u8(output + 369, 1);
    for (uint32 index = 0; index < 13; ++index)
        w_u8(output + 340 + index, r_u8(0x8006C254 + index));
    for (uint32 index = 0; index < 5; ++index)
        w_u16(output + 354 + index * 2, r_u16(0x8006C24A + index * 2));
    w_u8(output + 364, r_u8(0x8006C246));
    w_u8(output + 365, r_u8(0x8006C248));
    w_u8(output + 366, r_u8(0x8006C240));
    w_u8(output + 367, r_u8(0x8006C249));
    uint32 result = r_u8(0x8006C247);
    w_u8(output + 368, result);
    return result;
}

uint32 ob_game_800B820C(uint32 node, uint32 count, uint32 step, uint32 time)
{
    FUNCTION_MARKER(0x800B820C, "GAME.BIN");
    if (r_s16(0x800C5B54) != 1) return 1;
    /* TODO Preserve unspecified fields of the original effect record */
    uint32 record = ob_draft_scratch_acquire(112);
    sub_80029E54(record + 12);
    uint32 position = sub_80045464(node, time);
    w_u32(record + 44, 0x800C48E4);
    w_u32(record + 56, 500);
    w_u8(record + 92, 12);
    w_u8(record + 93, 4);
    w_u8(record + 95, 1);
    w_u16(record + 86, 204);
    w_u16(record + 90, 204);
    w_u32(record + 48, 0);
    w_u8(record + 94, 0);
    w_u32(record + 76, 1);
    w_u16(record + 88, 280);
    uint32 random = ob_draft_unresolved_call(0x8001B008, 0);
    w_u32(record, r_u32(position) - 256 + (random & 0x1FF));
    random = ob_draft_unresolved_call(0x8001B008, 0);
    w_u32(record + 4, r_u32(position + 4) - 256 + (random & 0x1FF));
    random = ob_draft_unresolved_call(0x8001B008, 0);
    uint32 z = r_u32(position + 8);
    w_u32(record + 60, 1);
    w_u32(record + 8, z - 256 + (random & 0x1FF));
    uint32 result = 0;
    for (uint32 axis = 0; axis < 3; ++axis)
    {
        result = (uint32)((sint32)(r_u32(node + 132 + axis * 4) * step) >> 8);
        w_u32(record + 96 + axis * 4, result);
    }
    for (uint32 index = 0; index != count; ++index)
    {
        random = ob_draft_unresolved_call(0x8001B008, 0);
        w_u32(record + 32, (random & 0x1FF) - 256);
        random = ob_draft_unresolved_call(0x8001B008, 0);
        w_u32(record + 36, random & 0x1FF);
        random = ob_draft_unresolved_call(0x8001B008, 0);
        w_u32(record + 40, (random & 0x1FF) - 256);
        ob_game_80092408(r_u32(0x80083E34), record, time, 6);
        uint32 x = r_u32(record);
        uint32 dx = r_u32(record + 96);
        uint32 y = r_u32(record + 4);
        uint32 dy = r_u32(record + 100);
        w_u32(record, x + dx);
        z = r_u32(record + 8);
        uint32 dz = r_u32(record + 104);
        w_u32(record + 4, y + dy);
        uint32 age = r_u32(record + 60);
        result = z + dz;
        w_u32(record + 8, result);
        w_u32(record + 60, age + step);
    }
    ob_draft_scratch_release(record);
    return result;
}

uint32 ob_game_800A7D94(uint32 object, uint32 unused, uint32 time)
{
    FUNCTION_MARKER(0x800A7D94, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    uint32 previous = r_u32(object + 28);
    uint32 elapsed = time - previous;
    if (!elapsed) return previous;
    uint32 kind = r_u32(object + 292);
    if (kind >= 49 && kind <= 73 && (kind & 1))
    {
        uint32 slot = (uint32)(sint32)r_s16(object + 326);
        ob_game_800A50BC(0x800CBA20 + slot * 104);
        ob_game_800AEEE8(time);
        return ob_game_800BCAA0(object);
    }
    if (kind == 15 || kind == 16)
    {
        uint32 state = r_u32(object + 288);
        if (state == 8)
        {
            uint32 node = r_u32(object + 44);
            w_u32(node + 136, r_u32(node + 136) - elapsed * 3);
            sub_80045ADC(r_u32(object + 44));
            sub_80045B74(r_u32(object + 44));
        }
        else if (state == 3 || state == 37)
        {
            if (state == 37) ob_game_800A9680(object, time);
            ob_game_800BCAA0(object);
            return 1;
        }
        else
        {
            uint32 position = ob_draft_scratch_acquire(16);
            sub_80045378(r_u32(object + 44), time, position);
            ob_draft_scratch_release(position);
            uint32 age = r_u32(object + 316) + elapsed;
            w_u32(object + 316, age);
            if ((sint32)age >= 5001)
            {
                ob_game_800A9680(object, time);
                w_u16(object + 308, 500);
                w_u32(object + 288, 3);
                w_u32(object + 316, 0xFFFFFFFF);
            }
        }
    }
    uint32 duration = ob_draft_unresolved_call(0x800A7F88, 2, object, time);
    w_u16(object + 308, duration);
    uint32 result = ob_game_800C0744(object, 0, time + (uint32)(sint32)(sint16)duration);
    w_u32(object + 28, time);
    return result;
}

uint32 ob_game_800A9204(uint32 object, uint32 descriptor, uint32 mode, uint32 time)
{
    FUNCTION_MARKER(0x800A9204, "GAME.BIN");
    uint32 flags = r_u16(object + 312) & 0xFFFC;
    w_u16(object + 312, flags);
    sint32 narrow = (sint8)mode;
    if (narrow && narrow != 1) return 1;
    if (narrow == 1)
    {
        w_u16(object + 312, flags | 1);
        uint32 node = sub_80044E5C(object, 0x80073660, time);
        w_u32(object + 44, node);
        uint32 shape = sub_80043E3C(object, 0x80073638);
        node = r_u32(object + 44);
        w_u32(object + 48, shape);
        w_u32(node + 8, 0x10000001);
        w_u32(r_u32(object + 48) + 48, 0x10000001);
        shape = r_u32(object + 48);
        uint32 result = r_u32(descriptor + 20);
        w_u32(shape + 40, result);
        return result;
    }
    uint32 handle = r_u32(descriptor + 8);
    if (handle)
    {
        uint32 data = r_u32(handle);
        if (data & 3) data = sub_800257CC(handle);
        else
        {
            w_u16(data - 6, r_u16(data - 6) + 1);
            data = r_u32(r_u32(descriptor + 8));
        }
        w_u32(object + 44, sub_80044E5C(object, data, time));
        sub_800257A0(r_u32(descriptor + 8));
    }
    else w_u32(object + 44, sub_80044E5C(object, 0x80073660, time));
    handle = r_u32(descriptor + 12);
    if (handle)
    {
        uint32 data = r_u32(handle);
        if (data & 3) data = sub_800257CC(handle);
        else
        {
            w_u16(data - 6, r_u16(data - 6) + 1);
            data = r_u32(r_u32(descriptor + 12));
        }
        w_u32(object + 48, sub_80043E3C(object, data));
        return sub_800257A0(r_u32(descriptor + 12));
    }
    uint32 shape = sub_80043E3C(object, 0x80073638);
    uint32 node = r_u32(object + 44);
    w_u32(object + 48, shape);
    w_u32(node + 8, 0x10000001);
    w_u32(r_u32(object + 48) + 48, 0x10000001);
    shape = r_u32(object + 48);
    uint32 result = r_u32(descriptor + 16);
    w_u32(shape + 40, result);
    return result;
}


uint32 ob_main_80048418(uint32 object)
{
    FUNCTION_MARKER(0x80048418, "SLES_008.65");
    uint32 result_record = r_u32(object + 20);
    w_u32(result_record, r_u32(result_record) | 0x8000);
    if ((!r_u32(object + 72) && r_s32(object + 76) < 0 && r_s32(object + 80) < 0)
        || (!r_u32(object + 76) && r_s32(object + 80) < 0 && r_s32(object + 72) < 0)
        || (!r_u32(object + 80) && r_s32(object + 72) < 0 && r_s32(object + 76) < 0))
    {
        uint32 result = 0x7FFFFF01;
        if (r_u32(object + 60) || r_u32(object + 64) || r_u32(object + 68))
        {
            sub_80048B60(object);
            uint32 axis = !r_u32(object + 72) ? 0 : !r_u32(object + 76) ? 1 : 2;
            if (r_s32(object + 96 + axis * 4) > 0)
            {
                if (r_s32(object + 84 + axis * 4) > 0) result = r_u32(object) + 1;
                else
                {
                    w_u32(result_record + 4, r_u32(object));
                    result = r_u32(result_record) | 0x10000;
                    w_u32(result_record, result);
                    return result;
                }
            }
            else
            {
                sub_80048BF4(object);
                result = r_u32(object + 108);
            }
        }
        w_u32(result_record + 4, result);
        return result;
    }
    uint32 result = r_u32(object);
    w_u32(result_record + 4, result);
    return result;
}

uint32 ob_game_800A2558(uint32 node, uint32 time, uint32 count, uint32 step, uint32 spread, uint32 size)
{
    FUNCTION_MARKER(0x800A2558, "GAME.BIN");
    spread &= 0xFFFF;
    if (spread < 2) spread = 2;
    uint32 record = ob_draft_scratch_acquire(96);
    ob_game_800B8E40(node, record, time);
    uint32 position = sub_80045464(node, time);
    w_u32(record + 44, 0x800C47E8);
    w_u32(record + 56, 1300);
    w_u16(record + 88, size * 2);
    w_u8(record + 92, 14);
    w_u8(record + 93, 4);
    w_u16(record + 86, size);
    w_u16(record + 90, size);
    w_u32(record + 60, 0);
    w_u8(record + 95, 1);
    uint32 result = position;
    uint32 divisor = spread - 1;
    uint32 half = spread >> 1;
    for (uint32 index = 0; index != count; ++index)
    {
        for (uint32 axis = 0; axis < 3; ++axis)
        {
            sint32 random = (sint32)ob_draft_unresolved_call(0x8001AFC8, 0);
            uint32 remainder = (uint32)(random % (sint32)divisor);
            w_u32(record + axis * 4, r_u32(position + axis * 4) + remainder - half);
        }
        ob_game_80092408(r_u32(0x80083E34), record, time, 6);
        w_u32(record + 60, r_u32(record + 60) + step);
        uint32 velocity = r_u32(node + 136);
        uint32 y = r_u32(position + 4);
        result = y + (uint32)((sint32)(velocity * step) >> 8);
        w_u32(position + 4, result);
    }
    ob_draft_scratch_release(record);
    return result;
}

uint32 ob_game_800A8CE0(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800A8CE0, "GAME.BIN");
    uint32 record = ob_draft_scratch_acquire(96);
    sub_80029E54(record + 12);
    uint32 scaled = (ob_game_800901A8(r_u32(object + 292)) & 0xFFFF) >> 6;
    uint32 size = scaled * 5;
    uint32 count = scaled >> 5;
    uint32 position = sub_80045464(r_u32(object + 44), time);
    w_u32(record + 44, 0x800C47E8);
    w_u32(record + 56, 1300);
    w_u16(record + 88, size * 2);
    w_u8(record + 92, 14);
    w_u8(record + 93, 4);
    w_u32(record + 48, 0);
    w_u32(record + 32, 0);
    w_u32(record + 36, 0);
    w_u32(record + 40, 0);
    w_u16(record + 86, size);
    w_u16(record + 90, size);
    w_u32(record + 76, 1);
    w_u8(record + 94, 0);
    w_u32(record + 60, 0);
    /* TODO The original leaves the first effect record's byte95 unspecified */
    uint32 height = 750;
    for (uint32 index = 0; index < count; ++index)
    {
        uint32 random = ob_draft_unresolved_call(0x8001AFC8, 0);
        w_u32(record, r_u32(position) + (random & 0x3FF) - 512);
        w_u32(record + 4, r_u32(position + 4) + height);
        random = ob_draft_unresolved_call(0x8001AFC8, 0);
        height += 1500;
        uint32 z = r_u32(position + 8);
        w_u32(record + 8, z + (random & 0x3FF) - 512);
        ob_game_80092408(r_u32(0x80083E34), record, time, 6);
        uint32 age = r_u32(record + 60);
        w_u8(record + 95, 1);
        w_u32(record + 60, age + 250);
    }
    ob_draft_scratch_release(record);
    ob_main_80011A24(0x800666C4, 255, 256, r_u32(object + 44), time, 0);
    uint32 kind = r_u32(object + 292);
    if (kind - 15 < 2)
    {
        w_u32(object + 288, 3);
        return 3;
    }
    uint32 slot = (uint32)(sint32)r_s16(object + 326);
    w_u32(object + 292, kind + 1);
    w_u32(0x800CBA2C + slot * 104, r_u32(0x800CBA2C + slot * 104) + 1);
    sub_80046544(r_u32(object + 52));
    if (r_u32(object + 64)) sub_80045F20(object + 64);
    w_u32(object + 100, 0x800A7D94);
    w_u32(object + 96, 0);
    w_u32(object + 92, time + 1100);
    return sub_80045EF4(object + 64);
}

uint32 ob_game_800B349C(uint32 object, uint32 unused, uint32 time)
{
    FUNCTION_MARKER(0x800B349C, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    sub_80045A7C(r_u32(object + 44), time);
    if ((sint32)time < r_s32(data + 20))
    {
        uint32 remaining = r_u32(data + 20) - time;
        sint32 velocity = (sint32)(0 - remaining * 500) / 1000;
        w_u32(data + 52, 0);
        w_u32(data + 56, (uint32)velocity);
        w_u32(data + 60, 0);
        w_u16(data + 90, r_s16(data + 90) > 0 ? 832 : (uint32)-832);
        w_u16(data + 88, r_s16(data + 88) > 0 ? 1728 : (uint32)-1728);
        w_u32(data + 24, time);
        w_u32(object + 100, 0x800B349C);
        w_u32(object + 96, 0);
        w_u32(object + 92, time + 50);
        sub_80045EF4(object + 64);
    }
    else
    {
        ob_game_8009A704(object);
        sint32 sound = r_s16(data + 104);
        if (sound != -1)
        {
            sub_8001195C((uint32)sound);
            w_u16(data + 104, 0xFFFF);
        }
        w_u8(r_u32(object + 60) + 54, 1);
        ob_main_8004E66C(r_u32(r_u32(object + 136) + 60));
        ob_main_8004E66C(r_u32(r_u32(object + 140) + 60));
        uint32 x = r_u32(0x800C61B4);
        uint32 y = r_u32(0x800C61B8);
        uint32 z = r_u32(0x800C61BC);
        w_u32(data + 52, x);
        w_u32(data + 56, y);
        w_u32(data + 60, z);
        w_u32(object + 100, 0x800B36D0);
        w_u32(object + 96, 0);
        w_u32(object + 92, time + 3000);
        sub_80045EF4(object + 64);
        ob_draft_unresolved_call(0x800B83FC, 4, r_u32(object + 44), 10, 300, time);
    }
    if (r_u32(data + 180))
    {
        w_u32(data + 180, 0);
        sub_8004651C(r_u32(object + 52));
        uint32 attributes = ob_draft_scratch_acquire(88);
        ob_game_800BE604(object, attributes, time);
        ob_draft_scratch_release(attributes);
    }
    uint32 shape = r_u32(object + 52);
    if (!r_u32(shape + 28)) sub_80046544(shape);
    ob_game_800B45F4(object);
    ob_game_800B47B0(object);
    return ob_game_800B3AD0(object, data + 48, data + 52);
}

uint32 ob_game_8009CC64(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x8009CC64, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    sub_80045A7C(r_u32(object + 44), time);
    if (r_u32(record + 28) & 0x10804400)
    {
        uint32 slot = (uint32)(sint32)r_s16(object + 326);
        if (r_u16(0x800CBA46 + slot * 104) && ob_game_800A2C80(data))
        {
            uint32 source = r_u32(record + 52);
            if (r_s16(source + 132) != 5)
            {
                sint32 rate = (sint16)ob_game_800B8FBC(object, source);
                rate /= 4;
                if (rate <= 0) rate = 1;
                else rate = (sint16)ob_game_800B8FBC(object, source) / 4;
                w_u32(0x800C835C, r_u32(0x800C835C) - ((uint32)rate << 6));
                if (ob_game_800A52C4(object, (uint32)rate, 0xFFFFFFFF))
                {
                    uint32 duration;
                    if (r_u32(r_u32(object + 132) + 288) == 29)
                    {
                        ob_game_800A1CA8(object, 13, time);
                        ob_game_800A1BD4(object, 11);
                        duration = 11000;
                    }
                    else
                    {
                        ob_game_800A1CA8(object, 5, time);
                        ob_game_800A1BD4(object, 11);
                        duration = 2500;
                    }
                    w_u32(object + 316, time + duration);
                    uint32 node = r_u32(object + 44);
                    w_u32(object + 288, 3);
                    sub_80045A44(node, 0x8006C160);
                }
                else
                {
                    sint32 state = r_s16(data + 32);
                    if (state != 6 && state != 8)
                    {
                        ob_main_80011A24(0x8006A984, 128, 256, r_u32(object + 44), time, 0);
                        uint32 random = ob_draft_unresolved_call(0x8001AFC8, 0);
                        ob_game_800A1CA8(object, random & 1 ? 8 : 6, time);
                        ob_game_800A1BD4(object, 3);
                        w_u32(object + 288, 30);
                    }
                }
            }
        }
    }
    return (uint32)sub_80047FF0(record);
}

uint32 ob_game_800A0010(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x800A0010, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    uint32 flags = r_u32(record + 28);
    if (flags & 0x10804400)
    {
        uint32 data = r_u32(object + 108);
        uint32 left = r_u16(data + 40);
        uint32 right = r_u16(data + 42);
        uint32 source = r_u32(record + 52);
        if (!(left | right))
        {
            uint32 slot = (uint32)(sint32)r_s16(object + 326);
            if (r_u16(0x800CBA46 + slot * 104))
            {
                uint32 state = r_u32(object + 124);
                uint32 source_node = r_u32(source + 44);
                uint32 heading = r_u16(state + 4);
                sub_80045A7C(source_node, time);
                sint32 angle = (sint16)(r_u16(source + 146) - (heading - 0x8000));
                if (angle < 0) angle = -angle;
                if (angle < 4096)
                {
                    uint32 rate = ob_game_800B8FBC(object, source) << 16;
                    w_u32(0x800C835C, r_u32(0x800C835C) - (uint32)((sint32)rate >> 12));
                    if (ob_game_800A52C4(object, (uint32)((sint32)rate >> 18), 0xFFFFFFFF))
                    {
                        sub_80045A44(r_u32(object + 44), 0x8006C160);
                        ob_game_800A1CA8(object, 4, time);
                        ob_game_800A1BD4(object, 0);
                        uint32 node = r_u32(object + 44);
                        w_u32(object + 288, 3);
                        sub_80045A44(node, 0x800C61B4);
                        ob_game_800A2558(r_u32(object + 44), time, 15, 100, 4096, 450);
                        ob_main_80011A24(0x800687C8, 255, 128, r_u32(object + 44), time, 0);
                        ob_game_800A2C8C(object);
                    }
                }
            }
        }
        return (uint32)sub_80047FF0(record);
    }
    if (!(flags & 0x8020)) return (uint32)sub_80047FF0(record);
    uint32 source = r_u32(record + 52);
    w_u32(object + 280, time);
    w_u16(object + 300, r_u16(source + 302));
    uint32 slot = (uint32)(sint32)r_s16(source + 326);
    if (r_u16(0x800CBA46 + slot * 104)) ob_game_800A52C4(source, 16, 0xFFFFFFFF);
    ob_game_800AC640(object, 2);
    sub_80047FF0(record);
    return ob_draft_unresolved_call(0x800AD01C, 2, object, time);
}

uint32 ob_game_8009A4A8(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x8009A4A8, "GAME.BIN");
    uint32 state = r_u32(object + 288);
    if (state == 21 || state == 23) return state;
    uint32 kind = r_u32(object + 292);
    if (kind >= 32)
    {
        if (kind != 255) return 255;
        if (r_u8(r_u32(object + 108) + 46) == 3) return 3;
    }
    else if (kind < 29 && (kind >= 23 || kind < 20)) return kind < 20;
    if (r_u8(r_u32(0x80077190) + 40) == 3 && r_u32(object + 292) != 255) return 255;
    uint32 existing = r_u32(object + 128);
    uint32 resource = r_u32(object + 112);
    if (existing) return existing;
    sub_800262CC(object + 128, 28);
    /* TODO Unwritten effect fields remain unspecified, including the second-only resource path */
    uint32 record = ob_draft_scratch_acquire(96);
    uint32 selector = r_u32(resource + 16);
    if (selector)
    {
        uint32 node = (uint32)sub_800437C4(object, (sint32)selector);
        w_u32(r_u32(object + 128) + 12, node);
        w_u32(record + 44, 0x800C4C40);
        w_u32(record + 56, 500);
        w_u16(record + 86, 240);
        w_u16(record + 88, 240);
        w_u16(record + 90, 240);
        w_u8(record + 92, 8);
        w_u8(record + 93, 4);
        w_u32(record + 60, 0);
        w_u8(record + 94, 0);
        w_u32(record + 76, 0xFFFFFFFF);
        w_u32(record + 48, object);
        w_u32(record + 52, r_u32(r_u32(object + 128) + 12));
        uint32 effect = ob_game_80092408(r_u32(0x80083E34), record, time, 6);
        w_u32(r_u32(object + 128) + 20, effect);
    }
    else
    {
        w_u32(r_u32(object + 128) + 20, 0);
        w_u32(r_u32(object + 128) + 12, 0);
    }
    selector = r_u32(resource + 20);
    if (selector)
    {
        uint32 node = (uint32)sub_800437C4(object, (sint32)selector);
        w_u32(r_u32(object + 128) + 16, node);
        w_u32(record + 60, 100);
        w_u8(record + 95, 1);
        w_u32(record + 52, r_u32(r_u32(object + 128) + 16));
        uint32 effect = ob_game_80092408(r_u32(0x80083E34), record, time, 6);
        w_u32(r_u32(object + 128) + 24, effect);
    }
    else
    {
        w_u32(r_u32(object + 128) + 24, 0);
        w_u32(r_u32(object + 128) + 16, 0);
    }
    ob_draft_scratch_release(record);
    uint32 sound = ob_main_80011A24(0x80067244, 128, 256, r_u32(object + 44), time, 1);
    uint32 data = r_u32(object + 128);
    w_u16(object + 306, sound);
    w_u32(data + 4, time);
    w_u32(r_u32(object + 128) + 8, time + 3000);
    uint32 result = time + 20000;
    w_u32(r_u32(object + 128), result);
    return result;
}

uint32 ob_game_800B3210(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800B3210, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    w_u32(data + 180, 0);
    uint32 count = r_u8(0x8006C230);
    sint32 available = r_s8(0x8006C235);
    if (count)
    {
        count = r_u8(0x8006C230);
        for (uint32 index = 0; index < count; ++index)
        {
            uint32 player = r_u32(0x8006C138 + index * 4);
            if (player)
            {
                uint32 state = r_u32(player + 288);
                if (state == 3 || state == 22) --available;
            }
        }
    }
    if (available < 3)
    {
        count = r_u8(0x8006C230);
        for (uint32 index = 0; index < count; ++index)
            if (r_u32(0x8006C138 + index * 4) == object) w_u16(0x800C4E70, index);
    }
    else
    {
        sint32 selected = r_s16(0x800C4E70);
        if (r_u32(0x8006C138 + (uint32)selected * 4) == object)
        {
            count = r_u8(0x8006C230);
            for (uint32 index = 0; index < count; ++index)
            {
                uint32 player = r_u32(0x8006C138 + index * 4);
                if (player)
                {
                    uint32 state = r_u32(player + 288);
                    if (state != 3 && state != 22 && (uint32)selected != index)
                    {
                        w_u16(0x800C4E70, index);
                        break;
                    }
                }
            }
        }
    }
    uint32 shape = r_u32(object + 52);
    if (!r_u32(shape + 28)) sub_80046544(shape);
    if (r_u8(data + 46))
    {
        w_u32(data + 36, 1);
        return 1;
    }
    uint32 slot = (uint32)(sint32)r_s16(object + 326);
    w_u32(object + 288, 3);
    w_u16(0x800CBA46 + slot * 104, 0);
    w_u32(data + 20, time + 1000);
    w_u32(data + 24, time);
    uint32 random = ob_draft_unresolved_call(0x8001B008, 0);
    w_u16(data + 28, random);
    random = ob_draft_unresolved_call(0x8001B008, 0);
    w_u16(data + 30, (random & 0x1FFF) + 4096);
    uint32 active = r_u32(object + 64);
    w_u32(object + 100, 0x800B349C);
    w_u32(object + 96, 0);
    w_u32(object + 92, time + 50);
    if (active) sub_80045F20(object + 64);
    sub_80045EF4(object + 64);
    uint32 level = r_u8(0x8006C231);
    if (level >= 20) return 0;
    uint32 result = (level >> 2) * 5 + 9;
    w_u32(0x8007FAD0, result);
    return result;
}
