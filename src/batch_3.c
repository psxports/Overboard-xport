#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_extra_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800A07D0(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800A07D0, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(48);
    sub_80045378(r_u32(r_u32(0x8006C134) + 44), time, local + 32);
    sub_80045378(r_u32(object + 44), time, local + 16);
    if (ob_game_80099798(local + 32, local + 16) < 10000) ob_game_800A074C(object);
    sub_80045A7C(r_u32(object + 44), time);
    ob_main_80045410(r_u32(object + 44), local);
    uint32 result = ob_game_800A1BD4(object, (r_u32(local) | r_u32(local + 8)) != 0);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_800A9ED0(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800A9ED0, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    ob_game_800AA8F0(object, time);
    if (r_u32(object + 288) == 33)
    {
        uint32 parameters = r_u32(object + 124);
        w_u32(parameters, r_u32(parameters) * 2);
    }
    ob_game_800A2BEC(object);
    uint32 next = time + 200;
    if (r_u32(object + 288) == 30)
    {
        ob_game_800B7C7C(r_u32(object + 120), 7, 4);
        uint32 spawned = ob_game_800B5CB4(object, 0, 0, time);
        if (spawned)
        {
            uint32 actor = r_u32(0x800D5C98 + r_u8(r_u32(object + 108) + 44) * 4);
            sub_800465E8(r_u32(spawned + 52), r_u32(actor + 52));
        }
        next = time + 50;
    }
    uint32 result = ob_game_800BCB90(object, 0, next);
    w_u32(object + 28, time);
    return result;
}

uint32 ob_game_800BB968(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800BB968, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    uint32 result = r_u32(object + 28);
    if (time == result) return result;
    ob_game_800B9EB8(object, time);
    uint32 parameters = r_u32(object + 124);
    ob_game_800BA108(object, parameters + 4, r_u32(parameters), r_u32(object + 44));
    return ob_game_800C0744(object, 0, time + r_s16(object + 308));
}

uint32 ob_game_800AA74C(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800AA74C, "GAME.BIN");
    uint32 node = sub_800437C4(r_u32(r_u32(object + 44) + 12), 65931);
    uint32 local = ob_draft_scratch_acquire(136);
    ob_game_800B8E40(node, local, time);
    w_u32(local + 44, 0x800C48E4); w_u8(local + 92, 12); w_u32(local + 56, 500);
    w_u16(local + 86, 93); w_u16(local + 88, 140); w_u16(local + 90, 93);
    w_u32(local + 120, 0); w_u32(local + 124, 0); w_u32(local + 128, 500);
    w_u32(local + 4, r_u32(local + 4) + 1000);
    uint32 matrix = ob_main_8004545C(node);
    sub_8002AF54(matrix, -8192, local + 96);
    sub_80029B70(local + 120, local + 96, local + 32);
    ob_game_80092408(r_u32(0x80083E34), local, time, 6);
    sub_8002AF54(matrix, 8192, local + 96);
    sub_80029B70(local + 120, local + 96, local + 32);
    uint32 result = ob_game_80092408(r_u32(0x80083E34), local, time, 6);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_800AAA44(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800AAA44, "GAME.BIN");
    if (r_u32(r_u32(object + 44) + 136)) return ob_game_800BCAA0(object);
    sub_80046544(r_u32(object + 52));
    sub_80045A7C(r_u32(object + 44), time);
    sub_80045A44(r_u32(object + 44), 0x800C61B4);
    ob_main_80044080(r_u32(object + 48), 0x800698CC);
    w_u8(r_u32(object + 60) + 54, 1);
    ob_main_80011A24(0x800698D0, 255, 256, r_u32(object + 44), time, 0);
    sub_80045378(r_u32(object + 44), time, 0x800C5554);
    uint32 row = (uint32)(r_s16(object + 326) * 104);
    uint32 value = r_u16(0x800CBA32 + row);
    w_u32(0x800C5558, (uint32)-1000); w_u16(0x800C556A, -11824); w_u32(0x800C5560, value);
    ob_game_800A50BC(0x800C5554);
    w_u32(object + 92, time + 1000);
    return sub_80045EF4(object + 64);
}

uint32 ob_game_800A074C(uint32 object)
{
    FUNCTION_MARKER(0x800A074C, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    uint32 result = (uint32)r_s16(data + 32);
    if (result) return result;
    uint32 counter = r_u32(0x800C6268);
    w_u32(0x800C6268, counter + 1);
    if (!(counter & 1)) return 0;
    if (r_u16(data + 40)) return ob_game_800A1BD4(object, 2);
    result = r_u16(data + 42);
    return result ? ob_game_800A1BD4(object, 3) : result;
}

uint32 ob_game_800AA898(uint32 node, uint32 time)
{
    FUNCTION_MARKER(0x800AA898, "GAME.BIN");
    sub_80045378(node, time, 0x800C5554);
    w_u32(0x800C5560, 241); w_u16(0x800C5566, 8); w_u32(0x800C5558, 0);
    return ob_game_800A50BC(0x800C5554);
}

uint32 ob_game_800ABF74(uint32 angle, uint32 direction, uint32 limit)
{
    FUNCTION_MARKER(0x800ABF74, "GAME.BIN");
    sint32 difference = (sint16)angle - r_s16(direction);
    if (difference < 0) difference = -difference;
    return difference < (sint16)limit;
}

uint32 ob_game_800ABCA0(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800ABCA0, "GAME.BIN");
    uint32 remaining = r_u32(object + 316) - (time - r_u32(object + 28));
    if ((sint32)remaining > 0) { w_u32(object + 316, remaining); return 0; }
    w_u32(object + 316, 2000);
    return 1;
}

uint32 ob_game_800AA8F0(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800AA8F0, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    uint32 head = 0x800CBA00 + (uint32)(r_s16(object + 326) * 104);
    uint32 current = head, count = 0;
    if (r_u32(head + 72) != head)
    {
        do { current = r_u32(current + 72); }
        while (r_u32(current + 96) != 234 && r_u32(current + 72) != head);
    }
    w_u32(data + 84, current);
    while (r_u32(current + 72) != head) { current = r_u32(current + 72); ++count; }
    w_u16(data + 88, count);
    uint32 record = r_u32(r_u32(r_u32(data + 84) + 80) + 108) + (uint32)((sint16)count * 44);
    uint32 x = r_u32(record + 4), y = r_u32(record + 8), z = r_u32(record + 12);
    w_u32(0x800C84CC, x); w_u32(0x800C84D0, y); w_u32(0x800C84D4, z);
    ob_game_80097578(object, 0x800C84C0, time);
    ob_game_80097850(object, 0x800C84C0, 0, time);
    return ob_game_800997FC(object, 0x800C84C0, time);
}

uint32 ob_game_800AB9F8(uint32 object, uint32 event, uint32 time)
{
    FUNCTION_MARKER(0x800AB9F8, "GAME.BIN");
    if (r_u32(event + 48) >= 12000) return 0;
    uint32 sides = ob_game_800ABC3C(r_u16(r_u32(object + 116) + 44), 4096);
    if (r_u32(object + 292) == 20)
    {
        w_u8(r_u32(object + 120) + 112, 0);
        w_u8(r_u32(object + 120) + 113, 0);
        if ((sides & 2) && ob_game_800B5C50(0, r_u32(object + 120), time))
        {
            ob_game_800B5CB4(object, 0, 0, time);
            for (uint32 i = 1; i < 4; ++i)
            {
                w_u8(r_u32(object + 120) + 112, i);
                ob_game_800B5CB4(object, 0, 0, time);
            }
        }
        uint32 result = sides & 1;
        if (result)
        {
            result = ob_game_800B5C50(1, r_u32(object + 120), time);
            if (result)
            {
                result = ob_game_800B5CB4(object, 1, 0, time);
                for (uint32 i = 1; i < 4; ++i)
                {
                    w_u8(r_u32(object + 120) + 113, i);
                    result = ob_game_800B5CB4(object, 1, 0, time);
                }
            }
        }
        return result;
    }
    if (sides & 2) ob_game_800B5BD8(0, r_u32(object + 120), 1, time);
    if (sides & 1) ob_game_800B5BD8(1, r_u32(object + 120), 1, time);
    if ((sides & 2) && ob_game_800B5C50(0, r_u32(object + 120), time)) ob_game_800B5CB4(object, 0, 0, time);
    uint32 result = sides & 1;
    if (result)
    {
        result = ob_game_800B5C50(1, r_u32(object + 120), time);
        if (result) return ob_game_800B5CB4(object, 1, 0, time);
    }
    return result;
}

uint32 ob_game_80097064(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x80097064, "GAME.BIN");
    uint32 elapsed = time - r_u32(object + 28);
    if (elapsed)
    {
        sub_80045A7C(r_u32(object + 44), time);
        uint32 linked = r_u32(r_u32(object + 108));
        sub_80045A7C(r_u32(linked + 44), time);
        sint32 state = (sint16)ob_game_800A59D8(r_u32(object + 316), time);
        w_u32(object + 288, state);
        if (state >= 0 && state <= 3) ob_game_80098088(object, state >= 2, time);
        ob_game_80097228(object, linked, elapsed, time);
        uint32 matrix = ob_main_8004545C(r_u32(object + 44));
        sub_80029F58(r_s16(object + 296), matrix);
        w_u16(object + 296, r_u16(object + 296) + 14 * elapsed);
        sub_80045848(r_u32(object + 44), matrix);
        sub_80045B74(r_u32(object + 44));
        sub_80045B74(r_u32(linked + 44));
        if (r_u32(r_u32(object + 48) + 32))
        {
            uint32 local = ob_draft_scratch_acquire(24);
            sub_80029F58(r_s16(object + 296), local);
            sub_80045848(r_u32(r_u32(r_u32(object + 48) + 32) + 52), local);
            sub_80045B74(r_u32(r_u32(r_u32(object + 48) + 32) + 52));
            ob_draft_scratch_release(local);
        }
        ob_game_80097400(object, time);
    }
    uint32 result = ob_game_800C0744(object, 0, time + r_s16(object + 308));
    w_u32(object + 28, time);
    return result;
}

uint32 ob_game_80099030(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x80099030, "GAME.BIN");
    uint32 record = r_u32(object + 116), mode = 0;
    if (r_u16(record + 104) == 1)
    {
        if (r_s16(record + 82) != -1) mode = r_u32(0x800C90FC) < r_u32(record + 60) ? 2 : 1;
        if (mode == 1 || mode == 2) return ob_game_80097FC4(r_u32(object + 116), mode == 1 ? 9 : 8);
        return 2;
    }
    if (r_s8(record + 110) > 0 && r_s8(record + 110) < r_s8(record + 111)) mode = 2;
    else
    {
        record = r_u32(object + 116);
        if (r_s16(record + 82) != -1) mode = r_u32(0x800C90FC) < r_u32(record + 60) ? 2 : 1;
    }
    if (r_u32(object + 292) == 33 && r_u32(r_u32(object + 116) + 56) < r_u32(0x800C831C)) mode = 3;
    if (!mode) return 1;
    if (mode == 2)
    {
        record = r_u32(object + 116);
        if (r_u8(record) == 3)
        {
            ob_game_80097FC4(record, 4);
            w_u8(r_u32(object + 116) + 16, 5);
            record = r_u32(object + 116);
            uint32 result = time + r_s16(record + 106);
            w_u32(record + 12, result);
            return result;
        }
        w_u8(record + 98, r_u8(record + 98) + 1);
        record = r_u32(object + 116);
        if (r_u8(record + 98) < r_u8(record + 99))
        {
            ob_game_80097FC4(record, 5);
            w_u8(r_u32(object + 116) + 16, 2);
            w_u32(r_u32(object + 116) + 12, time + 260);
        }
        else
        {
            w_u8(record + 98, 0);
            ob_game_80097FC4(r_u32(object + 116), 1);
            w_u8(r_u32(object + 116) + 16, 5);
            record = r_u32(object + 116);
            w_u32(record + 12, time + r_s16(record + 106));
        }
    }
    else if (mode == 1)
    {
        if (r_u8(r_u32(object + 116)) != 3 && r_u32(object + 292) == 7)
        {
            uint32 data = r_u32(object + 108);
            if (!r_u32(data))
            {
                w_u32(data + 4, time + 7000); w_u32(data, 1);
                w_u16(data + 8, 256); w_u16(data + 10, 256);
            }
        }
        ob_game_80097FC4(r_u32(object + 116), 3);
    }
    else
    {
        ob_game_80097FC4(r_u32(object + 116), 5);
        w_u8(r_u32(object + 116) + 16, 2);
        uint32 result = time + 260;
        w_u32(r_u32(object + 116) + 12, result);
        return result;
    }
    record = r_u32(object + 116);
    w_u8(record + 111, 0);
    return record;
}

uint32 ob_game_8009DC58(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x8009DC58, "GAME.BIN");
    uint32 row = (uint32)(r_s16(object + 326) * 104);
    uint32 angle = r_u16(0x800CBA30 + row) + (time & 255) - 32768;
    uint32 animation = r_u32(object + 120);
    if (r_s8(animation + 135) != 11) ob_game_800B7C7C(animation, 11, 0);
    w_u16(r_u32(object + 120) + 122, -4096);
    uint32 first = ob_game_800B5CB4(object, 0, (sint16)(angle - 3072), time);
    if (first)
    {
        sub_800465E8(r_u32(first + 52), r_u32(object + 52));
        uint32 linked = r_u32(object + 132);
        if (linked) sub_800465E8(r_u32(first + 52), r_u32(linked + 52));
    }
    uint32 result = ob_game_800B5CB4(object, 1, (sint16)(angle + 3072), time);
    if (result)
    {
        uint32 second = result;
        sub_800465E8(r_u32(second + 52), r_u32(object + 52));
        result = r_u32(object + 132);
        if (result) return sub_800465E8(r_u32(second + 52), r_u32(result + 52));
    }
    return result;
}

uint32 ob_game_800A56C8(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800A56C8, "GAME.BIN");
    if (time != r_u32(object + 28))
    {
        sub_80045A7C(r_u32(object + 44), time);
        uint32 data = r_u32(r_u32(0x8006C138) + 108);
        if (r_u8(data + 46) != 3 && !r_s16(data + 172))
        {
            ob_game_80097578(object, 0x800C90F8, time);
            if (r_u32(0x800C90FC) < 3500 && r_s32(0x800C9108) < 100)
                ob_game_800A52C4(r_u32(0x8006C138), 8, UINT32_MAX);
        }
        sint32 state = (sint16)ob_game_800A59D8(r_u32(object + 316), time);
        w_u32(object + 288, state);
        if (state >= 0 && state <= 3) ob_game_80098088(object, state >= 2, time);
        else if (state == 4 || state == 5)
            ob_game_800A5A7C(object, (sint16)(r_u16(object + 296) + (state == 4 ? 32768 : 0)), 1, time);
        uint32 matrix = ob_main_8004545C(r_u32(object + 44));
        sub_80029F58(r_s16(r_u32(object + 124) + 4), matrix);
        uint32 local = ob_draft_scratch_acquire(32);
        w_u32(local + 4, 0); w_u32(local, 0); w_u32(local + 8, r_u32(r_u32(object + 124)));
        sub_80029B70(local, matrix, local + 16);
        sub_80045A44(r_u32(object + 44), local + 16);
        sub_80045848(r_u32(object + 44), matrix);
        ob_game_800A58D8(object, local + 16, 0, time);
        sub_80045B74(r_u32(object + 44));
        ob_draft_scratch_release(local);
    }
    uint32 interval = (uint32)r_s16(object + 308);
    w_u32(object + 28, time);
    return ob_game_800C0744(object, 0, time + interval);
}

uint32 ob_game_800BC0A8(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800BC0A8, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    uint32 result = r_u32(object + 28);
    if (result == time) return result;
    uint32 player = r_u32(0x8006C134);
    if (player)
    {
        uint32 local = ob_draft_scratch_acquire(32);
        sub_80045378(r_u32(player + 44), time, local);
        sub_80045378(r_u32(object + 44), time, local + 16);
        sint32 delta = (sint32)(r_u32(local + 16) - r_u32(local));
        if (delta >= 20001)
        {
            w_u32(local + 16, r_u32(local) - 20000);
            uint32 random = sub_8001B008();
            w_u32(local + 24, r_u32(local + 8) + 16384 - random);
        }
        else if (delta < -20000)
        {
            w_u32(local + 16, r_u32(local) + 20000);
            uint32 random = sub_8001B008();
            w_u32(local + 24, r_u32(local + 8) - 16384 + random);
        }
        delta = (sint32)(r_u32(local + 24) - r_u32(local + 8));
        if (delta >= 20001)
        {
            w_u32(local + 24, r_u32(local + 8) - 20000);
            uint32 random = sub_8001B008();
            w_u32(local + 16, r_u32(local) + 16384 - random);
        }
        else if (delta < -20000)
        {
            w_u32(local + 24, r_u32(local + 8) + 20000);
            uint32 random = sub_8001B008();
            w_u32(local + 16, r_u32(local) - 16384 + random);
        }
        sub_800458B4(r_u32(object + 44), local + 16, time);
        ob_draft_scratch_release(local);
    }
    return ob_game_800C0744(object, 0, time + r_s16(object + 308));
}

uint32 ob_game_800BC208(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800BC208, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    uint32 result = r_u32(object + 28);
    if (result == time) return result;
    uint32 player = r_u32(0x8006C134);
    if (player)
    {
        uint32 data = r_u32(object + 108);
        uint32 local = ob_draft_scratch_acquire(40);
        sub_80045378(r_u32(player + 44), time, local);
        sub_80045378(r_u32(object + 44), time, local + 16);
        sub_80028280(r_u32(local + 8) - r_u32(local + 24), r_u32(local) - r_u32(local + 16), local + 32, local + 36);
        uint32 state = r_u32(object + 288);
        if (state == 35 && r_s16(data) == 1)
        {
            ob_game_800BCAA0(object);
            ob_draft_scratch_release(local);
            return 1;
        }
        if (state == 34 && r_s16(data) == 16)
        {
            w_u32(object + 288, 36); w_u16(object + 308, 500);
        }
        else if (state == 34 || state == 35)
        {
            sint32 step = (sint16)(r_s16(data) + (state == 34 ? 1 : -1));
            sint32 product = step * r_s16(data + 2);
            w_u16(data, step);
            if (product < 0) product += 15;
            sub_800440B8(r_u32(object + 48), (sint32)((uint32)product << 12) >> 16);
        }
        else if (state == 36 && r_u32(local + 36) < 7500) ob_game_800B5CB4(object, 0, 0, time);
        ob_draft_scratch_release(local);
    }
    return ob_game_800C0744(object, 0, time + r_s16(object + 308));
}

uint32 ob_game_800ABC3C(uint32 angle, uint32 tolerance)
{
    FUNCTION_MARKER(0x800ABC3C, "GAME.BIN");
    sint32 value = (uint16)angle, range = (uint16)tolerance;
    if (16384 - range < value && value < 16384 + range) return 1;
    if (49152 - range < value) return 2 * (value < 49152 + range);
    return 0;
}

uint32 ob_game_800997FC(uint32 object, uint32 direction, uint32 time)
{
    FUNCTION_MARKER(0x800997FC, "GAME.BIN");
    sint32 angle = r_s16(direction);
    if (angle < 0) angle = -angle;
    uint32 result, mode;
    if (angle < 12288 && r_u32(direction + 4) >= 2501) { result = 1; mode = 0; }
    else if (angle < 20481) { result = 3; mode = 3; }
    else { result = 4; mode = 6; }
    if (time != UINT32_MAX) ob_game_80098088(object, mode, time);
    return result;
}

uint32 ob_game_800A59D8(uint32 duration, uint32 time)
{
    FUNCTION_MARKER(0x800A59D8, "GAME.BIN");
    sint32 divisor = (sint32)(duration * 2 + 6000);
    if (!divisor) ob_native_guest_break(0x800A59D8, 7);
    if (divisor == -1 && time == 0x80000000) ob_native_guest_break(0x800A59D8, 6);
    sint32 phase = (sint32)time % divisor;
    if (phase < (sint32)duration) return 0;
    if (phase < (sint32)(duration + 1000)) return 2;
    if (phase < (sint32)(duration + 3000)) return 4;
    if (phase < (sint32)(duration * 2 + 3000)) return 1;
    if (phase < (sint32)(duration * 2 + 4000)) return 3;
    return phase < (sint32)(duration * 2 + 6000) ? 5 : 0;
}

uint32 ob_game_80098160(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x80098160, "GAME.BIN");
    uint32 type = r_u32(object + 292);
    sint32 navigation = type == 2 || type == 6 || type == 7 || type == 8 || (type >= 20 && type <= 31) || type == 33;
    if (type == 33)
    {
        uint32 data = r_u32(object + 108);
        if (r_u32(data + 28) && r_s32(data + 24) >= (sint32)time)
        {
            ob_game_80097850(object, 0x800C90F8, 0, time);
            ob_game_80098088(object, 0, time);
        }
        else
        {
            uint32 deadline = r_u32(data + 28);
            if ((sint32)deadline < (sint32)time)
            {
                if (deadline)
                {
                    w_u32(data + 24, time + 1000); w_u32(data + 28, 0);
                    ob_stop_sound_with_mask((uint32)r_s16(object + 306), context);
                    uint32 voice = ob_main_80011A24(0x80067320, 128, 512, r_u32(object + 44), time, 1);
                    uint32 parameters = r_u32(object + 124);
                    w_u16(object + 306, voice); w_u32(parameters, 0);
                }
                else
                {
                    uint32 volume = (uint32)((sint32)(1000 - (r_u32(data + 24) - time)) >> 3) + 128;
                    ob_main_80011E20((uint32)r_s16(object + 306), r_u32(object + 44), volume, time);
                }
            }
            if (r_s32(data + 24) < (sint32)time)
            {
                w_u16(r_u32(object + 116) + 52, 512);
                ob_game_800B006C(object, time);
                uint32 next = r_u32(data + 24);
                w_u32(data + 28, next + 5000); w_u32(data + 24, next + 6000);
                sub_8001195C((uint32)r_s16(object + 306));
                w_u16(object + 306, 65535);
            }
        }
    }
    sint32 state = navigation ? r_s16(object + 304) : -1;
    if (state == 0 || state == 128)
    {
        uint32 local = ob_draft_scratch_acquire(16);
        sub_80045378(r_u32(object + 44), time, local);
        if (ob_game_80099890(object, time))
        {
            w_u8(object + 340, r_u8(object + 340) + 1);
            ob_game_800A46C4(0, 0, time);
            uint32 angle = ob_game_80099F60(object, local, time);
            uint32 parameters = r_u32(object + 124);
            w_u16(parameters + 4, r_u16(parameters + 4) + angle);
            w_u16(object + 304, 200); w_u16(object + 328, 500);
            uint32 result = ob_game_80098088(object, 6, time);
            ob_draft_scratch_release(local);
            return result;
        }
        ob_draft_scratch_release(local);
    }
    else if (state == 200)
    {
        uint32 local = ob_draft_scratch_acquire(48);
        sub_80045378(r_u32(object + 44), time, local);
        ob_game_800A46C4(0, 0, time);
        uint32 x = (uint16)((sint32)(r_u32(local) + r_u32(0x80077458)) / 2500);
        uint32 z = (uint16)((sint32)(r_u32(0x80077468) - r_u32(local + 8)) / 2500);
        w_u32(local + 32, x); w_u32(local + 40, z);
        w_u32(local + 16, x - 3 * r_s16(0x800C90F4) - r_s8(0x800D648C) + 12);
        w_u32(local + 24, z - 3 * r_s16(0x800C90F6) - r_s8(0x800D648F) + 12);
        sint32 path = (sint32)ob_game_80099AFC(local + 16, local + 32, UINT32_MAX);
        if (path == -3)
        {
            ob_game_80098088(object, 1, time);
            ob_game_80097FC4(r_u32(object + 116), 3);
            w_u16(object + 304, 0);
        }
        else if (path == -2)
        {
            ob_game_800A46C4(0, 0, time);
            uint32 angle = ob_game_80099F60(object, local, time);
            uint32 parameters = r_u32(object + 124);
            w_u16(parameters + 4, r_u16(parameters + 4) + angle);
            ob_game_80098088(object, 6, time);
        }
        else
        {
            w_u32(0x800C84D0, 0);
            w_u32(0x800C84CC, r_u32(local + 32) * 2500 - r_u32(0x80077458) + 1250);
            w_u32(0x800C84D4, r_u32(0x80077468) - r_u32(local + 40) * 2500 - 1250);
            ob_game_80097578(object, 0x800C84C0, time);
            ob_game_80097850(object, 0x800C84C0, 0, time);
            ob_game_80099DE4(object, (uint32)path, time);
        }
        if (path >= 2) w_u16(object + 304, 0);
        ob_draft_scratch_release(local);
        return path < 2;
    }
    ob_game_80098088(object, 0, time);
    return ob_game_80097850(object, 0x800C90F8, 0, time);
}

uint32 ob_game_80098624(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x80098624, "GAME.BIN");
    uint32 type = r_u32(object + 292);
    if (type == 33)
    {
        ob_game_80097FC4(r_u32(object + 116), 5);
        w_u8(r_u32(object + 116) + 16, 3);
        return 3;
    }
    if (type == 234)
    {
        ob_game_80097850(object, 0x800C90F8, 0, time);
        sint32 changed = 0;
        if (r_u32(0x800C90FC) < r_u32(r_u32(object + 116) + 60) - 1000)
        {
            ob_game_80098088(object, 4, time); changed = 1;
        }
        if (r_u32(r_u32(object + 116) + 60) + 1000 < r_u32(0x800C90FC))
        {
            ob_game_80098088(object, 0, time); changed = 1;
        }
        if (!changed) ob_game_80098088(object, 1, time);
        return ob_game_8009B69C(object, time);
    }
    if (type == 3 || type == 10 || type == 11)
    {
        ob_game_80098088(object, 0, time);
        return ob_game_80097850(object, 0x800C90F8, 0, time);
    }
    sint32 clear = type >= 6 && type <= 8;
    if (clear || type == 2 || (type >= 20 && type <= 31))
    {
        sint32 state = r_s16(object + 304);
        if (state != 0 && state != 128 && state != 200)
        {
            if (clear) w_u16(object + 304, 0);
            return state < 129 ? 1 : 200;
        }
        uint32 local = ob_draft_scratch_acquire(16);
        sub_80045378(r_u32(object + 44), time, local);
        if (ob_game_80099890(object, time))
        {
            w_u8(object + 340, r_u8(object + 340) + 1);
            ob_game_800A46C4(0, 0, time);
            uint32 angle = ob_game_80099F60(object, local, time);
            uint32 parameters = r_u32(object + 124);
            w_u16(parameters + 4, r_u16(parameters + 4) + angle);
            uint32 result = ob_game_80098088(object, 6, time);
            if (clear) w_u16(object + 304, 0);
            ob_draft_scratch_release(local);
            return result;
        }
        ob_draft_scratch_release(local);
        type = r_u32(object + 292);
        if (clear)
        {
            uint32 result = type < 8 ? 6 : 8;
            if (type == 6 || type == 7 || type == 8)
            {
                uint32 mode = type == 6 ? 7 : type == 7 ? r_u32(0x800C90FC) < 3001 : 0;
                ob_game_80098088(object, mode, time);
                result = ob_game_80097850(object, 0x800C90F8, 0, time);
            }
            w_u16(object + 304, 0);
            return result;
        }
        if (type == 21 || type == 24 || type == 29)
        {
            ob_game_80098088(object, 1, time);
            ob_game_80097850(object, 0x800C90F8, 0, time);
            ob_game_80097FC4(r_u32(object + 116), 5);
            w_u8(r_u32(object + 116) + 16, 2);
            uint32 record = r_u32(object + 116);
            uint32 result = time + r_s16(record + 108);
            w_u32(record + 12, result); w_u16(object + 304, 0);
            return result;
        }
    }
    ob_game_80098088(object, 3, time);
    return ob_game_80097778(object, 0x800C90F8, time);
}

uint32 ob_game_80098A8C(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x80098A8C, "GAME.BIN");
    uint32 type = r_u32(object + 292);
    if (type == 33)
    {
        w_u16(object + 312, r_u16(object + 312) | 4);
        ob_game_80097850(object, 0x800C8318, 1, time);
        ob_game_80098088(object, 4, time);
        uint32 position = sub_80045464(r_u32(r_u32(0x8006C134) + 44), time);
        uint32 distance = ob_game_80099798(position, 0x800C8324);
        if (r_u32(0x800C831C) >= 4000)
        {
            uint32 record = r_u32(object + 116);
            if (distance >= r_u32(record + 56))
            {
                w_u32(record + 12, time + 260);
                return time + 260;
            }
        }
        uint32 record = r_u32(object + 116);
        w_u32(record + 12, 0);
        return record;
    }
    if (type == 234)
    {
        w_u16(object + 312, r_u16(object + 312) | 4);
        ob_game_80098088(object, 0, time);
        ob_game_80097850(object, 0x800C90F8, 1, time);
        return ob_game_8009B748(object, time);
    }
    if (!(type == 2 || type == 6 || (type >= 20 && type <= 31)))
    {
        w_u16(object + 312, r_u16(object + 312) | 4);
        ob_game_80098088(object, 0, time);
        ob_game_80097850(object, 0x800C90F8, 1, time);
        uint32 record = r_u32(object + 116);
        w_u8(record + 111, 0);
        return record;
    }
    if (type == 21 || type == 24 || type == 29)
    {
        w_u32(r_u32(object + 120) + 96, 0); w_u32(r_u32(object + 120) + 100, 0);
        w_u8(r_u32(object + 120) + 112, 0); w_u8(r_u32(object + 120) + 113, 0);
    }
    sint32 state = r_s16(object + 304);
    if (state == 0 || state == 128)
    {
        uint32 local = ob_draft_scratch_acquire(16);
        sub_80045378(r_u32(object + 44), time, local);
        if (ob_game_80099890(object, time))
        {
            w_u8(object + 340, r_u8(object + 340) + 1);
            ob_game_800A46C4(0, 0, time);
            uint32 angle = ob_game_80099F60(object, local, time);
            uint32 parameters = r_u32(object + 124);
            w_u16(parameters + 4, r_u16(parameters + 4) + angle);
            w_u16(object + 304, 200); w_u16(object + 328, 500);
            uint32 result = ob_game_80098088(object, 6, time);
            ob_draft_scratch_release(local);
            return result;
        }
        ob_draft_scratch_release(local);
        w_u16(object + 312, r_u16(object + 312) | 4);
        ob_game_80098088(object, 0, time);
        return ob_game_80097850(object, 0x800C90F8, 1, time);
    }
    if (state == 200)
    {
        uint32 local = ob_draft_scratch_acquire(48);
        sub_80045378(r_u32(object + 44), time, local);
        uint32 x = (uint16)((sint32)(r_u32(local) + r_u32(0x80077458)) / 2500);
        uint32 z = (uint16)((sint32)(r_u32(0x80077468) - r_u32(local + 8)) / 2500);
        w_u32(local + 32, x); w_u32(local + 40, z);
        w_u32(local + 16, x - 3 * r_s16(0x800C90F4) - r_s8(0x800D648C) + 12);
        w_u32(local + 24, z - 3 * r_s16(0x800C90F6) - r_s8(0x800D648F) + 12);
        sint32 path = (sint32)ob_game_80099AFC(local + 16, local + 32, 1);
        if (path == -3)
        {
            ob_game_80098088(object, 1, time);
            ob_game_80097FC4(r_u32(object + 116), 3);
        }
        else if (path == -2)
        {
            ob_game_800A46C4(0, 0, time);
            uint32 angle = ob_game_80099F60(object, local, time);
            uint32 parameters = r_u32(object + 124);
            w_u16(parameters + 4, r_u16(parameters + 4) + angle);
            ob_game_80098088(object, 6, time);
        }
        else
        {
            w_u32(0x800C84D0, 0);
            w_u32(0x800C84CC, r_u32(local + 32) * 2500 - r_u32(0x80077458) + 1250);
            w_u32(0x800C84D4, r_u32(0x80077468) - r_u32(local + 40) * 2500 - 1250);
            ob_game_80097578(object, 0x800C84C0, time);
            ob_game_80097850(object, 0x800C84C0, 0, time);
            ob_game_80099DE4(object, (uint32)path, time);
        }
        if (path >= 2) w_u16(object + 304, 0);
        ob_draft_scratch_release(local);
        return path < 2;
    }
    ob_game_80098088(object, 0, time);
    return ob_game_80097850(object, 0x800C90F8, 0, time);
}

uint32 ob_game_80097228(uint32 object, uint32 linked, uint32 elapsed, uint32 time)
{
    FUNCTION_MARKER(0x80097228, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(64);
    uint32 angle = r_u16(object + 296) + 16384;
    sub_80045378(r_u32(object + 44), time, local);
    uint32 x = r_u32(local), y = r_u32(local + 4), z = r_u32(local + 8);
    w_u32(local + 16, x); w_u32(local + 20, y); w_u32(local + 24, z);
    uint32 index = (((angle & 65535) + 8) >> 4) * 2;
    sint32 sine = r_s16(0x8006C304 + index);
    w_u32(local + 20, 0);
    w_u32(local + 16, x + ((375 * sine) >> 11));
    w_u32(local + 24, z + ((375 * r_s16(0x8006CB04 + index)) >> 11));
    sub_80045378(r_u32(linked + 44), time, local + 32);
    sint32 divisor = (sint32)elapsed;
    for (uint32 offset = 0; offset < 12; offset += 4)
    {
        sint32 numerator = (sint32)((r_u32(local + 16 + offset) - r_u32(local + 32 + offset)) << 8);
        if (!divisor) ob_native_guest_break(0x80097228, 7);
        if (divisor == -1 && numerator == INT32_MIN) ob_native_guest_break(0x80097228, 6);
        w_u32(local + 48 + offset, (uint32)(numerator / divisor));
    }
    uint32 result = sub_80045A44(r_u32(linked + 44), local + 48);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_80097400(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x80097400, "GAME.BIN");
    if (!r_s16(object + 304)) return 0;
    uint32 local = ob_draft_scratch_acquire(16);
    sub_80045378(r_u32(r_u32(0x8006C138) + 44), time, local);
    if (r_s32(local + 4) < 100) w_u16(object + 304, 0);
    uint32 data = r_u32(r_u32(0x8006C138) + 108);
    uint32 value = r_u16(data + 82) + 1400;
    w_u16(data + 82, value);
    if ((sint16)value >= 461) w_u16(data + 82, 460);
    value = r_u16(data + 80) + 3360;
    w_u16(data + 80, value);
    if ((sint16)value >= 18433) w_u16(data + 80, 18432);
    ob_draft_scratch_release(local);
    return 18432;
}

uint32 ob_game_80097778(uint32 object, uint32 direction, uint32 time)
{
    FUNCTION_MARKER(0x80097778, "GAME.BIN");
    uint32 event = r_u32(object + 116), previous = r_u32(object + 28);
    uint32 distance = r_u32(direction + 4), state = r_u32(object + 112), angle = r_u16(direction);
    uint32 limit = r_u32(event + 60), elapsed = time - previous;
    if (distance < limit && r_u32(event + 64) < distance)
    {
        sint32 turn = (sint16)(angle + ((sint16)angle < 0 ? 16384 : -16384));
        sint32 sign = 1;
        if (turn < 0) { sign = -1; turn = -turn; }
        state = r_u32(state);
        uint32 step = r_u16(state + 4) * elapsed;
        sint32 update = (sint16)turn >= (sint32)step;
        if (!update)
        {
            step = r_u16(state + 6) * elapsed;
            update = (sint32)step < (sint16)turn;
        }
        if (update)
        {
            uint32 parameters = r_u32(object + 124);
            w_u16(parameters + 4, r_u16(parameters + 4) + (uint32)sign * step);
        }
    }
    return (sint16)angle != r_s16(direction);
}

uint32 ob_game_8009B69C(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x8009B69C, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    uint32 local = ob_draft_scratch_acquire(24);
    sub_80045378(r_u32(object + 44), time, local);
    uint32 result = r_u8(data + 180), index = 0, record = data;
    if (result)
    {
        do
        {
            if ((sint32)(r_u32(record + 32) + r_u16(record + 28)) < (sint32)time)
            {
                uint32 frame = r_u16(record + 36);
                w_u16(record + 36, frame < r_u16(record + 44) ? frame + 1 : 0);
                w_u32(record + 32, time);
            }
            uint32 count = r_u8(data + 180);
            result = ++index < count;
            record += 44;
        } while (result);
    }
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_8009B748(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x8009B748, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    uint32 local = ob_draft_scratch_acquire(24);
    sub_80045378(r_u32(object + 44), time, local);
    uint32 result = r_u8(data + 180), index = 0, record = data;
    if (result)
    {
        do
        {
            w_u16(record + 36, 0);
            uint32 count = r_u8(data + 180);
            result = ++index < count;
            record += 44;
        } while (result);
    }
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_800A58D8(uint32 object, uint32 vector, uint32 mode, uint32 time)
{
    FUNCTION_MARKER(0x800A58D8, "GAME.BIN");
    sub_80045A7C(r_u32(r_u32(object + 136) + 44), time);
    sub_80045A44(r_u32(r_u32(object + 136) + 44), vector);
    if (!(sint16)mode)
    {
        uint32 matrix = ob_main_8004545C(r_u32(object + 44));
        uint32 local = ob_draft_scratch_acquire(24);
        sub_8002ADFC(matrix, (sint16)(40 * time), local);
        sub_80045848(r_u32(r_u32(object + 136) + 44), local);
        ob_draft_scratch_release(local);
    }
    else if ((sint16)mode == 1)
    {
        uint32 matrix = ob_main_8004545C(r_u32(object + 44));
        sub_80045848(r_u32(r_u32(object + 136) + 44), matrix);
    }
    return sub_80045B74(r_u32(r_u32(object + 136) + 44));
}

uint32 ob_game_800A5A7C(uint32 object, uint32 angle, uint32 mode, uint32 time)
{
    FUNCTION_MARKER(0x800A5A7C, "GAME.BIN");
    uint32 parameters = r_u32(object + 124);
    sint32 current = r_s16(parameters + 4);
    if (current != (sint16)angle)
    {
        uint32 state = r_u32(r_u32(object + 112));
        uint32 step = r_u16(state + 4) * (time - r_u32(object + 28));
        sint32 difference = (sint16)(current - angle);
        if (difference < 0) difference = -difference;
        if (!(sint16)mode) step = 0 - step;
        while ((sint16)step >= difference)
        {
            step = (uint32)((sint16)step / 2);
            if (!step) return (uint32)r_s16(r_u32(object + 124) + 4);
        }
        w_u16(parameters + 4, current + step);
    }
    return (uint32)r_s16(r_u32(object + 124) + 4);
}

uint32 ob_game_80099890(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x80099890, "GAME.BIN");
    return r_u8(r_u32(object + 116) + 116);
}

uint32 ob_game_800998A4(uint32 position, uint32 angle, uint32 distance)
{
    FUNCTION_MARKER(0x800998A4, "GAME.BIN");
    uint32 index = (((angle & 65535) + 8) >> 4) * 2;
    uint32 dx = (uint32)((sint32)(distance * (uint32)r_s16(0x8006C304 + index)) >> 14);
    uint32 dz = (uint32)((sint32)(distance * (uint32)r_s16(0x8006CB04 + index)) >> 14);
    uint32 x = r_u32(position) + dx, z = r_u32(position + 8) + dz;
    uint32 cell_x = (uint16)((sint32)(x + r_u32(0x80077458)) / 2500);
    uint32 cell_z = (uint16)((sint32)(r_u32(0x80077468) - z) / 2500);
    uint32 local = ob_draft_scratch_acquire(48);
    sub_8004C2C4(local, x, z);
    uint32 first_index = (cell_z % 3 * 3 + cell_x % 3) * 4;
    x = r_u32(position) + dx * 2; z = r_u32(position + 8) + dz * 2;
    cell_x = (uint16)((sint32)(x + r_u32(0x80077458)) / 2500);
    cell_z = (uint16)((sint32)(r_u32(0x80077468) - z) / 2500);
    uint32 result = r_s32(local + first_index) > 0;
    sub_8004C2C4(local, x, z);
    if (r_s32(local + (cell_z % 3 * 3 + cell_x % 3) * 4) > 0) result += 2;
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_80099C74(uint32 position, uint32 dx, uint32 dz, uint32 expected, uint32 mode)
{
    FUNCTION_MARKER(0x80099C74, "GAME.BIN");
    uint32 origin_x = r_u32(position), origin_z = r_u32(position + 8);
    uint32 x = origin_x + dx, z = origin_z + dz;
    if ((uint32)r_s8(0x800D5EA4 + x * 24 + z) != expected) return 0;
    uint32 count = 1;
    x = origin_x + dx * 2; z = origin_z + dz * 2;
    while ((sint32)x >= 0 && (sint32)z >= 0 && (sint32)x < 21 && (sint32)z < 21)
    {
        sint32 value = r_s8(0x800D5EA4 + x * 24 + z);
        if (value < 0) break;
        if (!((mode == UINT32_MAX && value < (sint32)expected) || (mode == 1 && (sint32)expected < value))) break;
        ++count;
        x = origin_x + dx * (count + 1);
        uint32 previous_x = r_u32(position) + dx * count;
        uint32 current_z = r_u32(position + 8);
        expected = (uint32)r_s8(0x800D5EA4 + previous_x * 24 + current_z + dz * count);
        z = current_z + dz * (count + 1);
        if (count >= 5) break;
    }
    return count;
}

uint32 ob_game_80099AFC(uint32 position, uint32 output, uint32 mode)
{
    FUNCTION_MARKER(0x80099AFC, "GAME.BIN");
    uint32 x = r_u32(position), z = r_u32(position + 8);
    sint32 value = r_s8(0x800D5EA4 + x * 24 + z);
    if (value == -2 || value == -1) return (uint32)-2;
    if ((sint32)x < 0 || (sint32)z < 0 || (sint32)x >= 21 || (sint32)z >= 21) return (uint32)-3;
    sint32 best = 0; uint32 direction = 0;
    for (uint32 i = 0; i < 4; ++i)
    {
        sint32 candidate = (sint32)ob_game_80099C74(position, (uint32)r_s8(0x800C4F7C + i),
            (uint32)r_s8(0x800C4F80 + i), value + (sint16)mode, (uint32)(sint32)(sint16)mode);
        if (best < candidate) { best = candidate; direction = i; }
    }
    w_u32(output, r_u32(output) + 3 * r_s8(0x800C4F7C + direction));
    sint32 dz = r_s8(0x800C4F80 + direction);
    uint32 old_z = r_u32(output + 8);
    w_u32(0x800C8494, direction);
    w_u32(output + 8, old_z + 3 * dz);
    return best;
}

uint32 ob_game_80099F60(uint32 object, uint32 position, uint32 time)
{
    FUNCTION_MARKER(0x80099F60, "GAME.BIN");
    uint32 elapsed = time - r_u32(object + 28);
    uint32 heading = r_u16(r_u32(object + 124) + 4);
    uint32 step = r_u16(r_u32(r_u32(object + 112)) + 4) * elapsed;
    uint32 left = ob_game_800998A4(position, (sint16)(heading - 8192), 2400);
    left += ob_game_800998A4(position, (sint16)(r_u16(r_u32(object + 124) + 4) - 16384), 2400);
    left += ob_game_800998A4(position, (sint16)(r_u16(r_u32(object + 124) + 4) - 24576), 2400);
    uint32 right = ob_game_800998A4(position, (sint16)(r_u16(r_u32(object + 124) + 4) + 8192), 2400);
    right += ob_game_800998A4(position, (sint16)(r_u16(r_u32(object + 124) + 4) + 16384), 2400);
    right += ob_game_800998A4(position, (sint16)(r_u16(r_u32(object + 124) + 4) + 24576), 2400);
    if ((sint32)left < (sint32)right) step = 0 - step;
    return (uint32)(sint32)(sint16)step;
}

uint32 ob_game_80099DE4(uint32 object, uint32 path, uint32 time)
{
    FUNCTION_MARKER(0x80099DE4, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(40);
    sub_80045378(r_u32(object + 44), time, local + 24);
    if (ob_game_80099890(object, time))
    {
        uint32 result = ob_game_80098088(object, 6, time);
        ob_draft_scratch_release(local);
        return result;
    }
    sint32 direction = r_s32(0x800C8494);
    /* Both original callers carry time in S2 on the undefined direction path */
    uint32 angle = direction == 0 ? (uint32)-16384 : direction == 1 ? 0 : direction == 2 ? 16384 : direction == 3 ? (uint32)-32768 : time;
    w_u32(local + 4, 2500);
    w_u16(local, angle - r_u16(r_u32(object + 124) + 4));
    uint32 kind = ob_game_800997FC(object, local, UINT32_MAX);
    uint32 mode = kind == 1 ? ((sint32)path >= 6 ? 0 : (sint32)path < 2 ? 6 : 3) : kind == 3 ? 3 : kind == 4 ? 1 : 6;
    uint32 result = ob_game_80098088(object, mode, time);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_800A46C4(uint32 owner, uint32 slot, uint32 time)
{
    FUNCTION_MARKER(0x800A46C4, "GAME.BIN");
    if (r_s16(0x800C90F4) == 32767 || r_s16(0x800C90F6) == 32767) ob_game_800A3134(r_u32(0x8006C138), time);
    uint32 stamp = 0x800D5E98 + (uint32)((sint16)slot * 4);
    if (r_s32(0x800C90D4) < r_s32(stamp))
    {
        for (uint32 i = 0; i < 3; ++i)
        {
            if (r_u32(0x800C90D8 + i * 4) == owner)
            {
                if (r_s32(stamp) < r_s32(0x800C90E4 + i * 4)) w_u32(stamp, time);
                break;
            }
        }
    }
    else w_u32(stamp, time);
    uint32 result = r_u32(stamp);
    if (result == time)
    {
        sub_80045A7C(r_u32(r_u32(0x8006C138) + 44), time);
        uint32 local = ob_draft_scratch_acquire(16);
        sub_80045378(r_u32(r_u32(0x8006C138) + 44), time, local);
        uint32 x = r_u32(local) - 1250;
        uint32 absolute_x = x + r_u32(0x80077458);
        uint32 z = r_u32(local + 8) + 1250;
        uint32 absolute_z = r_u32(0x80077468) - z;
        uint32 flags = r_u32(0x800C8560) | 32;
        w_u32(local, x); w_u32(local + 8, z); w_u32(0x800C8560, flags);
        w_u8(0x800D648C, 3); w_u8(0x800D648F, 3);
        w_u8(0x800D648C, (sint32)absolute_x / 2500 - 3 * r_s16(0x800C90F4) + 2);
        w_u8(0x800D648F, (sint32)absolute_z / 2500 - 3 * r_s16(0x800C90F6) + 2);
        ob_game_800A36A0(owner, 0);
        result = r_u32(0x800C8560) & 0xFFFFFFDF;
        w_u32(0x800C8560, result);
        ob_draft_scratch_release(local);
    }
    return result;
}

void ob_game_800B006C(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800B006C, "GAME.BIN");
    uint32 event = r_u32(object + 116);
    uint32 counts[2];
    counts[0] = r_u8(r_u32(object + 112) + 40);
    counts[1] = r_u8(r_u32(object + 112) + 41);
    for (uint32 side = 0; side < 2; ++side)
    {
        if (!counts[side] && !(r_u8(object + 323) & 16)) continue;
        ob_game_800B5BD8(side, r_u32(object + 120), counts[side], time);
        if (!ob_game_800B5C50(side, r_u32(object + 120), time)) continue;
        sint32 angle = r_s16(event + 44);
        uint32 tolerance = r_u16(object + 320);
        if (angle < 0) angle = -angle;
        if (angle >= (sint32)tolerance || (r_u16(object + 312) & 4)) continue;
        uint32 mode = r_u8(object + 323) & 15, shots;
        switch (mode)
        {
        case 0: case 4:
            ob_game_800B5CB4(object, side, 0, time); shots = 1; break;
        case 1:
            for (sint32 offset = -8192; offset <= 8192; offset += 2048)
                ob_game_800B5CB4(object, side, (uint32)offset, time);
            shots = 9; break;
        case 2:
        {
            sint32 spread = (sint16)(((ob_main_8001AFC8() & 255) * 910) / 128 + 910);
            ob_game_800B5CA4(0);
            ob_game_800B5CB4(object, side, spread, time);
            ob_game_800B5CB4(object, side, spread, time);
            ob_game_800B5CB4(object, side, -spread, time);
            ob_game_800B5CB4(object, side, -spread, time);
            ob_game_800B5CA4(1);
            ob_game_800B5CB4(object, side, 0, time);
            shots = 5; break;
        }
        case 3:
            ob_main_8001AFC8();
            ob_game_800B5CA4(0);
            for (uint32 i = 0; i < 4; ++i) ob_game_800B5CB4(object, side, 0, time);
            ob_game_800B5CA4(1);
            ob_game_800B5CB4(object, side, 0, time);
            shots = 5; break;
        default: continue;
        }
        w_u8(event + 111, r_u8(event + 111) + shots);
    }
}

uint32 ob_game_800AACB4(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800AACB4, "GAME.BIN");
    ob_game_800AC550(object, 20, time);
    uint32 slot = 0x800CBA00 + (uint32)(r_s16(object + 326) * 104);
    uint32 result = ob_game_800C1944(slot);
    if (result == 1) return result;
    result = r_u32(object + 28);
    uint32 data = r_u32(object + 108), elapsed = time - result;
    if (!elapsed) return result;
    sub_80045A7C(r_u32(object + 44), time);
    if (r_s16(object + 306)) ob_main_80011E20((uint32)r_s16(object + 306), r_u32(object + 44), 128, time);
    if (r_s32(r_u32(object + 124) + 8) < (sint32)time)
    {
        sint32 state = r_s16(object + 304);
        if (state == 0 || state == 128 || state == 130 || state == 200) ob_game_80097E28(0, object, time);
        else if (state == 133) ob_game_8009B1A4(object, elapsed, time);
        ob_game_800B9EB8(object, time);
        uint32 parameters = r_u32(object + 124);
        ob_game_800BA108(object, parameters + 4, r_u32(parameters), r_u32(object + 44));
    }
    uint32 type = r_u32(object + 292);
    if (type != 11 && type != 6) ob_game_800B45F4(object);
    ob_game_800ABFA8(object, time);
    result = ob_game_800AAF14(object, time);
    if (result) { w_u32(object + 28, time); return result; }
    uint32 parameters = r_u32(object + 124);
    w_u32(object + 28, time);
    if (r_s32(parameters) >= 401 && r_s32(data + 16) < (sint32)time)
    {
        ob_game_800B8BD0(r_u32(object + 44), r_s32(parameters) / 50 + 180, r_s16(parameters + 4), 600, time);
        w_u32(data + 16, time + (sint32)(4000 - r_u32(r_u32(object + 124))) / 60 + 70);
    }
    return ob_game_800C0744(object, 0, time + r_s16(object + 308));
}

uint32 ob_game_800AFA94(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800AFA94, "GAME.BIN");
    uint32 elapsed = time - r_u32(object + 28);
    sint32 destroy = 0;
    if (elapsed)
    {
        sub_80045A7C(r_u32(object + 44), time);
        uint32 matrix = ob_main_8004545C(r_u32(object + 44));
        if (r_u32(object + 292) == 12) ob_game_800B0484(object, time);
        else ob_game_80097E28(0, object, time);
        sub_80029E80(r_s16(object + 342), matrix);
        uint32 local = ob_draft_scratch_acquire(64);
        sub_8002AF54(matrix, r_s16(r_u32(object + 124) + 4), local);
        w_u32(local + 28, 0); w_u32(local + 24, 0);
        uint32 speed = r_u32(r_u32(object + 124));
        w_u32(local + 32, speed);
        if (r_s16(object + 342))
        {
            uint32 index = ((r_u16(object + 342) + 8) >> 4) * 2;
            uint32 product = speed * (uint32)(3 * r_s16(0x8006CB04 + index));
            w_u32(local + 32, (uint32)((sint32)product >> 14));
        }
        sub_80029B70(local + 24, local, local + 40);
        sub_80045A44(r_u32(object + 44), local + 40);
        sub_80045848(r_u32(object + 44), local);
        sub_80045B74(r_u32(object + 44));
        ob_draft_scratch_release(local);
        uint32 type = r_u32(object + 292);
        if (type == 12) ob_game_8009231C(object, 4, time);
        else if (type == 7)
        {
            uint32 data = r_u32(object + 108);
            if (r_u32(data))
            {
                if (r_s32(data + 4) < (sint32)time) destroy = 1;
                else
                {
                    uint32 value = 256;
                    if (r_s16(data + 8) == 256)
                    {
                        value = r_u16(data + 10) + 2; w_u16(data + 10, value);
                    }
                    w_u16(data + 8, value);
                    sub_800440B8(r_u32(object + 48), r_s16(data + 8));
                }
            }
        }
        else if (type == 8)
        {
            uint32 distance = r_u32(r_u32(object + 116) + 48);
            if (distance)
            {
                uint32 row = (uint32)(r_s16(object + 326) * 104);
                if (r_u16(0x800CBA36 + row) != 0xD1D0 &&
                    (distance < 10000 || r_u8(r_u32(object + 60) + 54) == 6))
                {
                    if (r_u8(r_u32(object + 60) + 54) == 1)
                    {
                        ob_game_800B89D8(r_u32(object + 44), 200, time);
                        w_u32(r_u32(object + 48) + 40, 0x80068F94);
                    }
                    w_u8(r_u32(object + 60) + 54, 6); w_u16(object + 308, 50);
                    uint32 rotation = r_u16(object + 342) + elapsed * 100;
                    uint32 phase = r_u32(object + 316) + elapsed;
                    w_u16(object + 342, rotation); w_u32(object + 316, phase);
                    if ((sint32)phase >= 2001)
                    {
                        w_u32(object + 316, 0);
                        ob_game_800B89D8(r_u32(object + 44), 200, time);
                        w_u32(r_u32(object + 48) + 40, 0x80068F98);
                        uint32 effect = r_u32(object + 60);
                        w_u16(object + 342, 0); w_u8(effect + 54, 1); w_u16(object + 308, 150);
                    }
                    else if ((sint32)phase % 4 >= 500 - r_s16(object + 308))
                        ob_game_800B89D8(r_u32(object + 44), 200, time);
                }
                uint32 event = r_u32(object + 116);
                if (r_u32(event + 48) < 1000 || r_s32(object + 332) < (sint32)time) destroy = 1;
            }
        }
        if (destroy)
        {
            w_u32(r_u32(object + 116) + 60, 75000);
            ob_game_80091C9C(object, r_u32(object + 116), time);
            ob_game_800BCAA0(object);
        }
    }
    if (destroy) return 1;
    uint32 result = ob_game_800C0744(object, 0, time + r_s16(object + 308));
    w_u32(object + 28, time);
    return result;
}

uint32 ob_game_8009ABFC(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x8009ABFC, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    uint32 local = ob_draft_scratch_acquire(56);
    if (!r_u8(data + 180))
    {
        uint32 count = 0;
        uint32 head = 0x800CBA00 + r_s16(object + 326) * 104;
        uint32 current = head;
        while (r_u32(current + 72) != head)
        {
            for (uint32 i = 0; i < 28; i += 4) w_u32(local + i, r_u32(0x8008D82C + i));
            current = r_u32(current + 72);
            w_u32(local, r_u32(current + 32)); w_u32(local + 4, r_u32(current + 36));
            w_u32(local + 8, r_u32(current + 40));
            uint32 child = ob_game_800BC3D8(r_u32(0x80083E34), local, time);
            uint32 record = data + (uint16)count * 44;
            w_u32(record + 4, r_u32(current + 32)); w_u32(record + 8, r_u32(current + 36));
            w_u32(record + 12, r_u32(current + 40));
            sub_80028280(r_u32(current + 40) - r_u32(head + 40), r_u32(current + 32) - r_u32(head + 32), record + 26, record + 16);
            w_u16(record + 26, r_u16(record + 26) - r_u16(r_u32(object + 124) + 4));
            w_u32(record + 4, r_u32(current + 32)); w_u32(record + 8, r_u32(current + 36));
            w_u32(record + 12, r_u32(current + 40)); w_u32(record + 20, child);
            w_u16(record + 36, 0); w_u16(record + 38, 0); w_u16(record + 28, 125); w_u32(record + 32, 0);
            sint32 slot = (sint32)((current - 0x800CBA00) * 0xC4EC4EC5) >> 3;
            w_u16(record + 24, slot);
            if (r_u32(0x800CBA2C + (sint16)slot * 104) == 36)
            {
                w_u32(r_u32(object + 116) + 56, 175000);
                w_u32(r_u32(object + 116) + 60, 175000);
                w_u32(r_u32(object + 116) + 64, 75000);
            }
            uint32 asset = r_u16(0x800CBA34 + r_s16(record + 24) * 104) & 0x1FFF;
            uint32 handle_slot = 0x800C4F80 + asset * 4;
            uint32 handle = r_u32(handle_slot), value = r_u32(handle);
            if (value & 3) value = sub_800257CC(handle);
            else
            {
                w_u16(value - 6, r_u16(value - 6) + 1);
                value = r_u32(r_u32(handle_slot));
            }
            w_u32(record + 40, value);
            w_u16(data + (uint16)count * 44 + 44, r_u32(r_u32(data + (uint16)count * 44 + 40)));
            ++count;
            sub_800257A0(r_u32(handle_slot));
        }
        w_u16(r_u32(object + 116) + 106, 65535);
        w_u8(data + 180, count);
    }
    if (r_u32(object + 288) != 3 && time != r_u32(object + 28))
    {
        sub_80045A7C(r_u32(object + 44), time);
        if (r_u8(data + 184) & 2) ob_game_8009B69C(object, time);
        else ob_game_80097E28(0, object, time);
        if (r_u8(data + 184) & 1)
        {
            w_u16(r_u32(object + 124) + 4, 0);
            w_u32(r_u32(object + 124), 0);
        }
        sub_80029F58(r_s16(r_u32(object + 124) + 4), local + 32);
        w_u32(local + 4, 0); w_u32(local, 0); w_u32(local + 8, r_u32(r_u32(object + 124)));
        sub_80029B70(local, local + 32, local + 16);
        sub_80045A44(r_u32(object + 44), local + 16);
        sub_80045848(r_u32(object + 44), local + 32);
        sub_80045B74(r_u32(object + 44));
        w_u32(object + 28, time);
        ob_game_8009B31C(object, time);
    }
    uint32 result = r_u8(data + 181);
    if (result) result = ob_game_800C0744(object, 0, time + r_s16(object + 308));
    ob_draft_scratch_release(local);
    return result;
}

void ob_game_800B5CA4(uint32 enabled)
{
    FUNCTION_MARKER(0x800B5CA4, "GAME.BIN");
    w_u16(0x800C5B54, enabled);
}

uint32 ob_game_800AAF14(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800AAF14, "GAME.BIN");
    uint32 state = r_u32(object + 128);
    if (!state) return 0;
    if (r_s32(state + 4) < (sint32)time)
    {
        sint32 size = (sint32)(r_u32(state) - time) >> 7;
        if (size < 150) size = 150;
        ob_game_800B8818(r_u32(object + 44), size, 4000, time);
        state = r_u32(object + 128);
        sint32 remaining = (sint32)(r_u32(state) - time) / 2;
        w_u32(state + 4, time + ((sint32)(20000 - (uint32)remaining) >> 8));
    }
    if (r_s32(r_u32(object + 128) + 8) < (sint32)time)
    {
        w_u8(0x800CBA3A + r_s16(object + 326) * 104, 17);
        ob_game_800A6C34(object, 17, time);
        ob_main_80011A24(0x800660BC, 128, 256, r_u32(object + 44), time, 0);
        w_u32(r_u32(object + 128) + 8, time + 3000);
    }
    if (r_u16(0x800CBA46 + r_s16(object + 326) * 104) && ob_game_800A52C4(object, 150, time))
    {
        ob_game_800AB4E4(object, time);
        return 1;
    }
    if (r_s32(r_u32(object + 128)) < (sint32)time) ob_game_8009A704(object);
    return 0;
}

uint32 ob_game_800AC550(uint32 object, uint32 threshold, uint32 time)
{
    FUNCTION_MARKER(0x800AC550, "GAME.BIN");
    uint32 result = r_u8(object + 340);
    if ((sint16)threshold >= (sint32)result) return result;
    uint32 event = r_u32(object + 116), type = r_u8(event);
    if (type == 1 || type == 3)
    {
        ob_game_80097FC4(event, 5);
        w_u16(object + 304, 0); w_u8(r_u32(object + 116) + 16, 2);
        event = r_u32(object + 116);
        result = time + (sint16)(r_s16(event + 108) / 5);
        w_u32(event + 12, result);
    }
    else if (type == 5) result = ob_game_80097FC4(event, 3);
    else
    {
        w_u8(object + 340, 0);
        return type < 4 ? 1 : 5;
    }
    w_u16(object + 304, 0); w_u8(object + 340, 0);
    return result;
}

uint32 ob_game_800ABFA8(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800ABFA8, "GAME.BIN");
    uint32 angle = r_u16(object + 298), elapsed = time - r_u32(object + 28);
    ob_game_80097578(object, 0x800C90F8, time);
    sint32 delta = (sint16)(r_u16(0x800C90F8) - angle);
    sint32 step = (sint16)(15 * elapsed), magnitude = delta < 0 ? -delta : delta;
    sint32 sign = delta ? delta / magnitude : 1;
    sint32 change = (sint32)((uint32)sign * (uint32)step);
    if (magnitude >= step) w_u16(object + 298, r_u16(object + 298) + change);
    else if (magnitude >= step / 2) w_u16(object + 298, r_u16(object + 298) + change / 2);
    else if (magnitude >= step / 4) w_u16(object + 298, r_u16(object + 298) + change / 4);
    uint32 child = r_u32(r_u32(object + 48) + 32);
    if (!child) return 0;
    uint32 local = ob_draft_scratch_acquire(24), result;
    if (ob_game_800901FC(r_u32(object + 292), 0) == 0x800C390C)
    {
        sint32 absolute = r_s16(object + 298);
        if (absolute < 0) absolute = -absolute;
        sub_80029F58((sint16)(absolute - 0x4000), local);
        sub_80045848(r_u32(r_u32(r_u32(object + 48) + 32) + 52), local);
        sub_80045B74(r_u32(r_u32(r_u32(object + 48) + 32) + 52));
        sub_80029F58((sint16)(0x4000 - absolute), local);
        sub_80045848(r_u32(r_u32(r_u32(r_u32(object + 48) + 32) + 28) + 52), local);
        child = r_u32(r_u32(r_u32(object + 48) + 32) + 28);
    }
    else
    {
        sub_80029F58(r_s16(object + 298), local);
        sub_80045848(r_u32(r_u32(r_u32(object + 48) + 32) + 52), local);
        child = r_u32(r_u32(object + 48) + 32);
    }
    result = sub_80045B74(r_u32(child + 52));
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_8009B1A4(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x8009B1A4, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    ob_game_80097578(object, 0x800C90F8, time);
    ob_game_800AB9F8(object, r_u32(object + 116), time);
    uint32 head = 0x800CBA00 + r_s16(object + 326) * 104, current = head, count = 0;
    if (r_u32(current + 72) != head)
    {
        do { current = r_u32(current + 72); }
        while (r_u32(current + 96) != 234 && r_u32(current + 72) != head);
    }
    w_u32(data + 20, current);
    while (r_u32(current + 72) != head) { current = r_u32(current + 72); ++count; }
    w_u16(data + 24, count);
    uint32 record = r_u32(r_u32(r_u32(data + 20) + 80) + 108) + (sint16)count * 44;
    w_u32(0x800C84CC, r_u32(record + 4)); w_u32(0x800C84D0, r_u32(record + 8)); w_u32(0x800C84D4, r_u32(record + 12));
    ob_game_80097578(object, 0x800C84C0, time);
    ob_game_80097850(object, 0x800C84C0, 0, time);
    return ob_game_800997FC(object, 0x800C84C0, time);
}

uint32 ob_game_800B8BD0(uint32 node, uint32 scale, uint32 angle, uint32 distance, uint32 time)
{
    FUNCTION_MARKER(0x800B8BD0, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(128);
    ob_game_800B8E40(node, local, time);
    uint32 index = (((uint16)angle + 8) >> 4) * 2;
    sint32 dx = (sint32)(distance * r_s16(0x8006C304 + index));
    sint32 dz = (sint32)(distance * r_s16(0x8006CB04 + index));
    w_u32(local, r_u32(local) - dx / 0x4000);
    w_u32(local + 8, r_u32(local + 8) - dz / 0x4000);
    for (uint32 i = 0; i < 16; i += 4) w_u32(local + 96 + i, r_u32(local + 12 + i));
    w_u16(local + 112, r_u16(local + 28));
    sub_8002ADFC(local + 96, (sint16)angle, local + 12);
    w_u32(local + 44, 0x800C48A8); w_u32(local + 56, 400); w_u8(local + 92, 7);
    w_u16(local + 86, scale); w_u16(local + 88, scale); w_u16(local + 90, scale);
    uint32 result = ob_game_80092408(r_u32(0x80083E34), local, time, 4);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_800A36A0(uint32 height, uint32 slot)
{
    FUNCTION_MARKER(0x800A36A0, "GAME.BIN");
    sint32 index = (sint16)slot;
    uint32 map = 0x800D5EA4 + index * 504;
    ob_fill_words(map, 504, 0xFEFEFEFE, map);
    w_u16(0x800C81C8, 10); w_u16(0x800C81CA, 10); w_u32(0x800C81B0, 0); w_u32(0x800C81B4, 1);
    w_u8(map + 250, 0); w_u16(0x800C81C0, r_s8(0x800D648C + index)); w_u16(0x800C81C4, r_s8(0x800D648F + index));
    for (uint32 x = 0; x < 21; ++x)
        for (uint32 z = 0; z < 21; ++z)
        {
            uint32 cell = ((z + r_s16(0x800C81C4)) * r_s16(0x800C90F2) + x + r_s16(0x800C81C0)) * 4 + r_u32(0x800C90D0);
            if ((sint32)height < r_s32(cell)) w_u8(map + x * 24 + z, 255);
        }
    ob_game_800A3834(index);
    return ob_game_800A43CC(index);
}

uint32 ob_game_800B0484(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800B0484, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(16), closest = 0, found = 0, mode = 1;
    sint32 nearest = 0x7FFFFFFF;
    sub_80045378(r_u32(object + 44), time, local);
    for (uint32 current = r_u32(0x800C84EC); current; current = r_u32(current + 76))
        if (r_u32(current + 44) - 229 < 2 && r_u16(current + 50) == 17 && !r_u32(current + 36))
        {
            sint32 distance = ob_game_80099798(current + 32, local);
            found = 1;
            if (distance < nearest) { closest = current; nearest = distance; }
        }
    if (found)
    {
        w_u16(object + 328, 0);
        w_u32(0x800C84CC, r_u32(closest + 32)); w_u32(0x800C84D0, r_u32(closest + 36)); w_u32(0x800C84D4, r_u32(closest + 40));
        mode = 0;
    }
    else
    {
        uint32 row = r_s16(object + 326) * 104;
        uint32 dx = r_u32(0x800C84CC) - r_u32(0x800CBA3C + row);
        if ((sint32)dx < 0) dx = 0 - dx;
        uint32 dz = r_u32(0x800C84D4) - r_u32(0x800CBA40 + row);
        if ((sint32)dz < 0) dz = 0 - dz;
        if ((sint32)(dx + dz) >= 2001)
        {
            w_u32(0x800C84D0, 0); w_u32(0x800C84CC, r_u32(0x800CBA3C + row));
            w_u32(0x800C84D4, r_u32(0x800CBA40 + r_s16(object + 326) * 104));
        }
    }
    ob_game_80097578(object, 0x800C84C0, time);
    ob_game_80097850(object, 0x800C84C0, 0, time);
    if (r_u32(0x800C84C4) < 400 && found == 1)
    {
        mode = 6;
        uint32 child = r_u32(closest + 80);
        ob_main_80011A24(0x800660C8, 128, 256, r_u32(object + 44), time, 0);
        ob_game_800BCAA0(child);
        ob_game_800B03D4(object, r_u32(0x8006C134), time);
    }
    else ob_game_80097850(object, 0x800C84C0, 0, time);
    uint32 result = ob_game_80098088(object, mode, time);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_8009B31C(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x8009B31C, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(40), data = r_u32(object + 108);
    sub_80045378(r_u32(object + 44), time, local);
    w_u8(data + 181, 0);
    uint32 result = r_u32(object + 124), angle = r_u16(result + 4);
    for (uint32 i = 0; i < r_u8(data + 180); ++i)
    {
        uint32 record = data + i * 44;
        if (r_u16(0x800CBA36 + r_s16(record + 24) * 104) == r_u16(0x800CBA36 + r_s16(object + 326) * 104))
        {
            w_u8(data + 181, r_u8(data + 181) + 1);
            uint32 index = (((uint16)(r_u16(record + 26) + angle) + 8) >> 4) * 2;
            uint32 radius = r_u32(record + 16);
            w_u32(local + 24, r_u32(local) + ((sint32)(radius * r_s16(0x8006C304 + index)) >> 14));
            w_u32(local + 28, r_u32(local + 4));
            w_u32(local + 32, r_u32(local + 8) + ((sint32)(radius * r_s16(0x8006CB04 + index)) >> 14));
            if (r_u16(record + 36))
            {
                uint32 asset = r_u16(0x800CBA34 + r_s16(record + 24) * 104) & 0x1FFF, dx = 0, dz = 0;
                if (asset)
                {
                    uint32 slot = 0x800C4F80 + asset * 4, handle = r_u32(slot), value = r_u32(handle);
                    if (value & 3) w_u32(record + 40, sub_800257CC(handle));
                    else { w_u16(value - 6, r_u16(value - 6) + 1); w_u32(record + 40, r_u32(r_u32(slot))); }
                    uint32 offset = r_u32(record + 40) + r_u16(record + 36) * 8;
                    dx = r_u32(offset); dz = r_u32(offset + 4);
                    sub_800257A0(r_u32(slot));
                }
                uint32 flags = r_u16(record + 38);
                if (flags & 0x8000) dx = 0 - dx;
                if (flags & 0x4000) dz = 0 - dz;
                index = ((angle + 8) >> 4) * 2;
                uint32 cosine = r_s16(0x8006CB04 + index), sine = r_s16(0x8006C304 + index);
                w_u32(local + 24, r_u32(local + 24) + ((sint32)(dx * cosine) >> 14) + ((sint32)(dz * sine) >> 14));
                w_u32(local + 32, r_u32(local + 32) + ((sint32)(dz * cosine) >> 14) - ((sint32)(dx * sine) >> 14));
            }
            w_u32(record + 4, r_u32(local + 24)); w_u32(record + 8, r_u32(local + 28)); w_u32(record + 12, r_u32(local + 32));
            sub_80045A7C(r_u32(r_u32(record + 20) + 44), time);
            sub_800458B4(r_u32(r_u32(record + 20) + 44), data + i * 44 + 4, time);
            sub_80045B74(r_u32(r_u32(record + 20) + 44));
        }
        result = (sint32)(i + 1) < r_u8(data + 180);
    }
    ob_draft_scratch_release(local);
    return result;
}
