#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"
#include "native_extra_signatures.h"

uint32 ob_game_800A9E48(uint32 animation)
{
    FUNCTION_MARKER(0x800A9E48, "GAME.BIN");
    uint32 current = r_u32(0x800C546C);
    uint32 previous = 0;
    uint32 handle = ob_draft_scratch_acquire(4);
    w_u32(handle, current);
    while (current != 0)
    {
        if (current == animation)
        {
            uint32 next = r_u32(current);
            if (previous == 0) w_u32(0x800C546C, next);
            else w_u32(previous, next);
            uint32 result = sub_800263B4(handle);
            ob_draft_scratch_release(handle);
            return result;
        }
        previous = current;
        current = r_u32(previous);
        w_u32(handle, current);
    }
    ob_draft_scratch_release(handle);
    return current;
}

uint32 ob_game_800AEFCC(uint32 descriptor)
{
    FUNCTION_MARKER(0x800AEFCC, "GAME.BIN");
    uint32 result = ob_game_800AF07C(descriptor) << 16;
    if (result == 0) return result;
    uint32 previous = r_u32(0x800C84EC);
    if (previous == 0) return result;
    if (previous == descriptor)
    {
        uint32 next = r_u32(descriptor + 76);
        result = r_u16(0x800C8364) - 1;
        w_u32(descriptor + 76, 0);
        w_u32(0x800C84EC, next);
    }
    else
    {
        for (;;)
        {
            result = r_u32(previous + 76);
            if (result == descriptor) break;
            if (result == 0) return result;
            previous = result;
        }
        result = r_u16(0x800C8364) - 1;
        w_u32(previous + 76, r_u32(descriptor + 76));
        w_u32(descriptor + 76, 0);
    }
    w_u16(0x800C8364, result);
    return result;
}

uint32 ob_game_8009B0F0(uint32 descriptor)
{
    FUNCTION_MARKER(0x8009B0F0, "GAME.BIN");
    uint32 result = r_u32(descriptor + 72);
    if (result == 0) return result;
    if (result == descriptor)
    {
        uint32 slot = r_u16(descriptor + 54);
        uint32 table = r_u32(0x8007719C);
        uint32 disabled = r_u32(0x8006C228);
        w_u32(descriptor + 72, 0);
        result = table + slot * 4;
        w_u32(result, 0);
        if (disabled == 0)
            result = ob_draft_unresolved_call(0x800BA234, 3, r_u8(descriptor + 59), 2, r_u32(0x80077334));
        return result;
    }
    uint32 previous = descriptor;
    do { previous = r_u32(previous + 72); } while (r_u32(previous + 72) != descriptor);
    uint32 next = r_u32(descriptor + 72);
    uint32 table = r_u32(0x8007719C);
    w_u32(previous + 72, next);
    uint32 slot = r_u16(descriptor + 54);
    w_u32(descriptor + 72, 0);
    result = table + slot * 4;
    w_u32(result, previous);
    return result;
}

uint32 ob_game_800A0B6C(uint32 slot)
{
    FUNCTION_MARKER(0x800A0B6C, "GAME.BIN");
    slot = (uint32)(sint32)(sint16)slot;
    if (slot == UINT32_MAX) return UINT32_MAX;
    uint32 descriptor = 0x800CBA00 + slot * 104;
    if (r_u32(descriptor + 72) != 0) ob_game_8009B0F0(descriptor);
    return ob_game_800A0B38(descriptor);
}

/* These cleanup callsites do not consume an original return carrier */
static void ob_game_800BC8D8(uint32 object)
{
    FUNCTION_MARKER(0x800BC8D8, "GAME.BIN");
    if (object == 0) return;
    uint32 behavior = r_u32(object + 60);
    if (behavior != 0) ob_draft_unresolved_call(0x8004E644, 1, behavior);
    uint32 geometry = r_u32(object + 52);
    if (geometry != 0) sub_8004651C(geometry);
    uint32 node = r_u32(object + 44);
    if (node != 0) sub_80045124(node);
    ob_game_800955B0(object);
    sub_80043664(object);
}

uint32 ob_game_800BC958(uint32 object)
{
    FUNCTION_MARKER(0x800BC958, "GAME.BIN");
    uint32 parts[4];
    parts[0] = object;
    parts[1] = r_u32(object + 136);
    parts[2] = r_u32(object + 140);
    parts[3] = r_u32(object + 144);
    if (r_s32(object + 276) < 0) sub_8004F31C(r_u32(object + 56));
    if (r_u8(0x800C61B1) == 0) sub_80044058(r_u32(object + 48));
    for (uint32 index = 0; index < 4; ++index)
    {
        if (index != 0) sub_80044058(r_u32(parts[index] + 48));
        uint32 properties = ob_game_800901FC(r_u32(object + 292), index);
        if ((r_u8(properties + 36) & 64) != 0) w_u32(parts[index] + 44, 0);
        ob_game_800BC8D8(parts[index]);
        if (index == 3 || parts[index + 1] == 0) return 0;
    }
    return 0;
}

static void ob_game_80096360(uint32 object)
{
    FUNCTION_MARKER(0x80096360, "GAME.BIN");
    uint32 handle = r_u32(object + 108);
    uint32 child = r_u32(handle);
    if (child == 0) return;
    ob_game_800BE25C(child);
    ob_game_800BC958(r_u32(handle));
    sub_800263B4(handle);
}

uint32 ob_game_800BCAD4(uint32 object)
{
    FUNCTION_MARKER(0x800BCAD4, "GAME.BIN");
    uint32 handle = ob_draft_scratch_acquire(4);
    w_u32(handle, object);
    if ((r_u8(object + 324) & 1) != 0) w_u32(handle, r_u32(object + 132));
    object = r_u32(handle);
    if ((r_u32(object + 276) & 0x20000) != 0) ob_game_80096360(object);
    sint32 slot = r_s16(r_u32(handle) + 326);
    if (slot != -1) ob_game_800AEFCC(0x800CBA00 + (uint32)slot * 104);
    ob_game_800BE25C(r_u32(handle));
    ob_game_800BC958(r_u32(handle));
    uint32 result = sub_800263B4(handle);
    ob_draft_scratch_release(handle);
    return result;
}

uint32 ob_game_800BCAA0(uint32 object)
{
    FUNCTION_MARKER(0x800BCAA0, "GAME.BIN");
    uint32 slot = (uint32)(sint32)r_s16(object + 326);
    ob_game_800BCAD4(object);
    return ob_game_800A0B6C(slot);
}

uint32 ob_game_800BE25C(uint32 object)
{
    FUNCTION_MARKER(0x800BE25C, "GAME.BIN");
    sub_8001195C((uint32)(sint32)r_s16(object + 306));
    w_u16(object + 306, UINT16_MAX);
    uint32 type = r_u32(object + 292);
    uint32 data, child, index;
    switch (type)
    {
    case 20: case 21: case 22: case 23: case 24: case 25:
    case 26: case 27: case 28: case 29: case 30: case 31: case 255:
        ob_draft_unresolved_call(0x8009A704, 1, object);
        break;
    case 32:
        ob_draft_unresolved_call(0x8009C57C, 0);
        data = r_u32(object + 108);
        sub_8004651C(r_u32(data + 20));
        sub_800437C4(r_u32(r_u32(object + 44) + 12), 0x101D2);
        ob_draft_unresolved_call(0x800A9E48, 1, r_u32(data));
        w_u32(data, 0);
        break;
    case 33: case 36:
        data = r_u32(object + 108);
        index = r_u8(data + 44);
        if (index != 255) ob_game_800BCAA0(r_u32(0x800D5C98 + index * 4));
        if (type == 33)
        {
            index = r_u8(data + 45);
            if (index != 255) ob_game_800BCAA0(r_u32(0x800D5C98 + index * 4));
        }
        ob_draft_unresolved_call(0x800ADB68, 1, r_u32(data));
        break;
    case 38:
        data = r_u32(r_u32(r_u32(object + 108)) + 108);
        index = r_u16(object + 302);
        if (index == r_u16(data + 36))
        {
            w_u32(0x800D5C98 + r_u8(data + 44) * 4, 0);
            w_u8(data + 44, 255);
        }
        else if (index == r_u16(data + 38))
        {
            w_u32(0x800D5C98 + r_u8(data + 45) * 4, 0);
            w_u8(data + 45, 255);
        }
        break;
    case 39: case 40:
        data = r_u32(object + 108);
        child = r_u32(data);
        if (child != 0)
        {
            ob_draft_unresolved_call(0x800A9E48, 1, child);
            w_u32(data, 0);
        }
        break;
    case 41:
        ob_draft_unresolved_call(0x800ADB68, 1, r_u32(r_u32(object + 108)));
        break;
    case 156:
        data = r_u32(object + 108);
        if (r_s16(data + 14) != -1)
        {
            sub_8001195C((uint32)(sint32)r_s16(data + 14));
            w_u16(data + 14, UINT16_MAX);
        }
        break;
    case 159:
        data = r_u32(object + 108);
        ob_draft_unresolved_call(0x800A9E48, 1, r_u32(data + 8));
        w_u32(data + 8, 0);
        index = r_u8(r_u32(object + 108) + 44);
        if (index != 255) ob_game_800BCAA0(r_u32(0x800D5C98 + index * 4));
        break;
    case 162: case 163:
        data = r_u32(object + 108);
        child = r_u32(data);
        if (child != 0)
        {
            ob_draft_unresolved_call(0x800A9E48, 1, child);
            w_u32(data, 0);
        }
        child = r_u32(data + 16);
        if (child != 0)
        {
            ob_draft_unresolved_call(0x800A9E48, 1, child);
            w_u32(data + 16, 0);
        }
        break;
    case 165: case 229: case 230:
        data = r_u32(object + 108);
        ob_draft_unresolved_call(0x800A9E48, 1, r_u32(data));
        w_u32(data, 0);
        break;
    default:
        break;
    }
    return sub_80012184();
}

uint32 ob_game_800AEB60(uint32 descriptor, uint32 time)
{
    FUNCTION_MARKER(0x800AEB60, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(32);
    uint32 object = r_u32(descriptor + 80);
    w_u32(descriptor + 100, r_u32(object + 288));
    sub_80045378(r_u32(object + 44), time, local);
    w_u32(descriptor + 32, r_u32(local));
    w_u32(descriptor + 36, r_u32(local + 4));
    uint32 vertical_kind = r_u32(descriptor + 44) - 229;
    w_u32(descriptor + 40, r_u32(local + 8));
    if (vertical_kind < 2) w_u32(descriptor + 36, 0);
    uint32 type = r_u32(descriptor + 96);
    if ((type >= 2 && type <= 8) || type == 12 || (type >= 20 && type < 32))
    {
        object = r_u32(descriptor + 80);
        uint32 state = r_u32(object + 288);
        if ((state == 3 || state == 1) && (r_u8(descriptor + 93) == 0 || r_u32(object + 292) == 6))
        {
            uint32 result = ob_game_800BCAA0(object);
            ob_draft_scratch_release(local);
            return result;
        }
    }
    else if (type >= 49 && type <= 73 && (type & 1) != 0)
    {
        w_u8(descriptor + 93, 1);
        object = r_u32(descriptor + 80);
    }
    else if (type == 149 || type == 153)
    {
        uint32 position = r_u32(0x80077194) + r_u16(descriptor + 88) * 28;
        uint32 x = r_u32(position), y = r_u32(position + 4), z = r_u32(position + 8);
        w_u32(descriptor + 32, x); w_u32(descriptor + 36, y); w_u32(descriptor + 40, z);
        object = r_u32(descriptor + 80);
    }
    else if (type == 224)
    {
        object = r_u32(descriptor + 80);
        w_u16(descriptor + 50, r_u16(r_u32(object + 48) + 160));
        sub_80045A7C(r_u32(object + 44), time);
        ob_main_80045410(r_u32(r_u32(descriptor + 80) + 44), local + 16);
        object = r_u32(descriptor + 80);
        w_u32(descriptor + 60, r_u32(local + 16));
        w_u32(descriptor + 64, r_u32(local + 24));
    }
    else
        object = r_u32(descriptor + 80);
    ob_game_800BCAD4(object);
    w_u8(descriptor + 92, 1);
    w_u32(descriptor + 80, 0);
    ob_draft_scratch_release(local);
    return 1;
}
