#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_extra_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800B03D4(uint32 object, uint32 target, uint32 time)
{
    FUNCTION_MARKER(0x800B03D4, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(16);
    sub_80045A7C(r_u32(target + 44), time);
    sub_80045378(r_u32(target + 44), time, local);
    w_u32(0x800CBA3C + r_s16(object + 326) * 104, r_u32(local));
    uint32 result = r_s16(object + 326) * 104;
    w_u32(0x800CBA40 + result, r_u32(local + 8));
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_800A4900(uint32 distance, uint32 x, uint32 z, uint32 next)
{
    FUNCTION_MARKER(0x800A4900, "GAME.BIN");
    uint32 head = 0x800D64C0 + (sint16)distance * 2, record = (sint16)next * 8;
    w_u16(0x800C9AC4 + record, r_u16(head)); w_u16(head, next);
    w_u16(0x800C9AC0 + record, x); w_u16(0x800C9AC2 + record, z);
    return (sint16)(next + 1);
}

uint32 ob_game_800A4958(uint32 distance, uint32 previous)
{
    FUNCTION_MARKER(0x800A4958, "GAME.BIN");
    if ((sint16)previous == -1) return r_s16(0x800D64C0 + (sint16)distance * 2);
    return r_s16(0x800C9AC4 + (sint16)previous * 8);
}

uint32 ob_game_800A4600(uint32 distance, uint32 slot, uint32 x, uint32 z)
{
    FUNCTION_MARKER(0x800A4600, "GAME.BIN");
    w_u8(0x800D5EA4 + (sint16)slot * 504 + x * 24 + z, distance + 1);
    w_u32(0x800C81B8, (sint16)ob_game_800A4900((sint16)(distance + 1), (sint16)x, (sint16)z, r_s16(0x800C81B8)));
    sint32 next = (sint16)distance + 1;
    uint32 result = r_s32(0x800C82BC) < next;
    if (result) w_u32(0x800C82BC, next);
    return result;
}

uint32 ob_game_800A43CC(uint32 slot)
{
    FUNCTION_MARKER(0x800A43CC, "GAME.BIN");
    uint32 flags = r_u32(0x800C8560);
    sint32 distance = r_s32(0x800C82B8);
    w_u32(0x800C8560, flags | 128);
    if (distance == 127) return 127;
    uint32 map = 0x800D5EA4 + (sint16)slot * 504;
    while (distance <= r_s32(0x800C82BC))
    {
        w_u32(0x800C81BC, -1);
        for (;;)
        {
            sint32 index = (sint16)ob_game_800A4958((sint16)distance, r_s16(0x800C81BC));
            w_u32(0x800C81BC, index);
            if (index == -1) break;
            sint32 x = r_s16(0x800C9AC0 + index * 8), z = r_s16(0x800C9AC2 + index * 8);
            if (x > 0 && r_s8(map + (x - 1) * 24 + z) == -2) ob_game_800A4600((sint16)distance, (sint16)slot, x - 1, z);
            if (x + 1 < 21 && r_s8(map + (x + 1) * 24 + z) == -2) ob_game_800A4600((sint16)distance, (sint16)slot, x + 1, z);
            if (z > 0 && r_s8(map + x * 24 + z - 1) == -2) ob_game_800A4600((sint16)distance, (sint16)slot, x, z - 1);
            if (z + 1 < 21 && r_s8(map + x * 24 + z + 1) == -2) ob_game_800A4600((sint16)distance, (sint16)slot, x, z + 1);
        }
        ++distance;
    }
    uint32 result = r_u32(0x800C8560) & 0xFFFFFF7F;
    w_u32(0x800C8560, result);
    return result;
}

static void ob_navigation_ray(uint32 map, sint32 x, sint32 z, sint32 dx, sint32 dz, uint32 distance)
{
    while (r_s8(map + x * 24 + z) != -1)
    {
        if ((dx < 0 && x < 0) || (dx > 0 && x >= 21) || (dz < 0 && z < 0) || (dz > 0 && z >= 21)) break;
        ++distance;
        w_u8(map + x * 24 + z, distance);
        x += dx; z += dz;
    }
}

uint32 ob_game_800A3834(uint32 slot)
{
    FUNCTION_MARKER(0x800A3834, "GAME.BIN");
    sint32 cx = r_s16(0x800C81C8), cz = r_s16(0x800C81CA);
    uint32 flags = r_u32(0x800C8560);
    w_u32(0x800C8560, flags | 64);
    uint32 map = 0x800D5EA4 + (sint16)slot * 504;
    ob_navigation_ray(map, cx - 1, cz, -1, 0, 0);
    ob_navigation_ray(map, cx + 1, cz, 1, 0, 0);
    ob_navigation_ray(map, cx, cz - 1, 0, -1, 0);
    ob_navigation_ray(map, cx, cz + 1, 0, 1, 0);
    for (sint32 distance = 1; distance < 11; ++distance)
    {
        if (r_s8(map + (cx - distance) * 24 + cz) == distance)
        {
            ob_navigation_ray(map, cx - distance, cz - 1, 0, -1, distance);
            ob_navigation_ray(map, cx - distance, cz + 1, 0, 1, distance);
        }
        if (r_s8(map + cx * 24 + cz - distance) == distance)
        {
            ob_navigation_ray(map, cx - 1, cz - distance, -1, 0, distance);
            ob_navigation_ray(map, cx + 1, cz - distance, 1, 0, distance);
        }
        if (r_s8(map + (cx + distance) * 24 + cz) == distance)
        {
            ob_navigation_ray(map, cx + distance, cz - 1, 0, -1, distance);
            ob_navigation_ray(map, cx + distance, cz + 1, 0, 1, distance);
        }
        if (r_s8(map + cx * 24 + cz + distance) == distance)
        {
            ob_navigation_ray(map, cx - 1, cz + distance, -1, 0, distance);
            ob_navigation_ray(map, cx + 1, cz + distance, 1, 0, distance);
        }
    }
    for (sint32 i = 232; i >= 0; i -= 8) w_u16(0x800C81CC + i, -1);
    ob_fill_words(0x800D64C0, 200, -1, 0x800D64C0);
    w_u32(0x800C81B8, 0); w_u32(0x800C82B8, 127); w_u32(0x800C82BC, 0);
    for (sint32 x = 0; x < 21; ++x)
        for (sint32 z = 0; z < 21; ++z)
        {
            uint32 cell = map + x * 24 + z;
            if (r_s8(cell) != -2) continue;
            sint32 best = 126, bx = 0, bz = 0, value;
            if (x > 0 && (value = r_s8(cell - 24)) >= 0 && value < best) { best = value; bx = x - 1; bz = z; }
            if (z > 0 && (value = r_s8(cell - 1)) >= 0 && value < best) { best = value; bx = x; bz = z - 1; }
            if (x < 20 && (value = r_s8(cell + 24)) >= 0 && value < best) { best = value; bx = x + 1; bz = z; }
            if (z < 20 && (value = r_s8(cell + 1)) >= 0 && value < best) { best = value; bx = x; bz = z + 1; }
            if (best < r_s32(0x800C82B8)) w_u32(0x800C82B8, best);
            if (best != 126)
            {
                w_u32(0x800C81B8, (sint16)ob_game_800A4900(best, bx, bz, r_s16(0x800C81B8)));
                if (r_s32(0x800C82BC) < best) w_u32(0x800C82BC, best);
            }
        }
    w_u32(0x800C82C0, 0);
    uint32 result = r_u32(0x800C8560) & 0xFFFFFFBF;
    w_u32(0x800C8560, result);
    return result;
}

uint32 ob_game_8009B7A8(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x8009B7A8, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(56);
    sub_80045A7C(r_u32(object + 44), time);
    uint32 state = r_u32(object + 288);
    if (state == 2) goto finish;
    if (state == 3)
    {
        uint32 node = sub_800437C4(r_u32(r_u32(object + 44) + 12), 66002);
        sub_80045A7C(node, time);
        if ((sint32)time >= r_s32(object + 316))
        {
            uint32 shape = sub_800437C4(object, 66012);
            ob_main_80044080(shape, 0x800662CC);
            sub_80045A44(node, 0x8006C160); sub_80045A44(r_u32(object + 44), 0x8006C160);
            w_u32(object + 288, 29); ob_game_800A2C8C(object);
        }
        else
        {
            ob_game_800A2558(node, time, 1, 75, 700, 800);
            ob_game_800A2558(r_u32(object + 44), time, 1, 75, 700, 800);
            ob_main_80045410(node, local); w_u32(local + 4, r_u32(local + 4) + 500); sub_80045A44(node, local);
            for (uint32 i = 0; i < 12; ++i)
            {
                node = sub_800437C4(r_u32(r_u32(object + 44) + 12), r_u32(0x800C504C + i * 4));
                ob_game_800A2558(node, time, 2, 75, 100, 100);
                ob_game_800B8818(node, 100, 0, time);
            }
        }
        goto finish;
    }
    if (state == 29)
    {
        for (uint32 i = 0; i < 12; ++i)
            ob_game_800B8818(sub_800437C4(r_u32(r_u32(object + 44) + 12), r_u32(0x800C504C + i * 4)), 100, 0, time);
        goto finish;
    }
    uint32 position = sub_80045464(r_u32(object + 44), time);
    uint32 row = 0x800CBA20 + r_s16(object + 326) * 104;
    sub_80028280(r_u32(row + 8) - r_u32(position + 8), r_u32(row) - r_u32(position), local + 16, local + 20);
    uint32 player = sub_80045464(r_u32(r_u32(0x8006C134) + 44), time);
    for (uint32 i = 0; i < 4; ++i)
    {
        uint32 node = sub_800437C4(r_u32(r_u32(object + 44) + 12), r_u32(0x800C500C + i * 4));
        position = sub_80045464(node, time);
        sub_80028280(r_u32(player + 8) - r_u32(position + 8), r_u32(player) - r_u32(position), local + 48, local + 52);
        if (r_u32(object + 288) == 31)
        {
            uint32 angle_slot = 0x800C9AA8 + i * 2, velocity_slot = 0x800C9AB8 + i * 2;
            if (r_s32(object + 316) < (sint32)time)
            {
                sint32 delta = (sint16)(r_u16(local + 48) - r_u16(angle_slot));
                if (delta < 0) delta = -delta;
                if (delta < 500) { w_u32(object + 288, 30); w_u32(object + 316, time + 750); }
            }
            uint32 movement = (time - r_u32(object + 28)) * r_s16(velocity_slot);
            if ((sint32)movement < 0)
            {
                uint32 limit = r_u16(angle_slot) - r_u32(0x800C502C + i * 4);
                if (0 - movement >= limit) { w_u16(velocity_slot, 6); movement = limit; }
            }
            else
            {
                uint32 limit = r_u32(0x800C503C + i * 4) - r_u16(angle_slot);
                if (movement >= limit) { w_u16(velocity_slot, -6); movement = limit; }
            }
            uint32 angle = r_u16(angle_slot) + movement;
            w_u16(angle_slot, angle);
            uint32 matrix = ob_game_800AD6E0(local + 24, (sint16)angle);
            sub_80045848(node, matrix);
        }
    }
    position = sub_80045464(r_u32(object + 44), time);
    sub_80028280(r_u32(player + 8) - r_u32(position + 8), r_u32(player) - r_u32(position), local + 48, local + 52);
    if (!r_u32(object + 288))
    {
        sub_80045A44(r_u32(object + 44), 0x8006C160);
        sint32 angle = r_s16(r_u32(r_u32(object + 108)) + 26);
        ob_game_800B7C7C(r_u32(object + 120), 12, 4);
        w_u8(r_u32(object + 120) + 113, 4);
        for (uint32 i = 0; i < 4; ++i)
        {
            if (i) { uint32 animation = r_u32(object + 120); w_u8(animation + 113, r_u8(animation + 113) + 1); }
            ob_game_8009BF8C(object, 1, angle, time);
        }
        w_u32(object + 288, 31); w_u16(object + 308, 150);
        sint32 elapsed = (sint32)(time - r_u32(object + 332));
        w_u32(object + 316, time + 750);
        w_u32(object + 284, elapsed > 50000 ? time + 400 : time + ((sint32)(50000 - (uint32)elapsed) >> 3) + 400);
    }
    ob_game_800B7C7C(r_u32(object + 120), 7, 4);
    uint32 side = (((r_s16(local + 48) + 0x2000) >> 14) & 3) * 3, phase = time & 0x1C00;
    if (phase == 3072 || phase == 2048 || phase == 1024)
    {
        w_u8(r_u32(object + 120) + 112, side + (phase / 1024 - 1));
        ob_game_8009BF8C(object, 0, 0, time);
    }
    if (r_s32(object + 284) < (sint32)time)
    {
        w_u32(object + 316, time + 250);
        uint32 table = r_u32(0x800C50E4 + r_u8(object + 339) * 4), count = r_u8(table);
        sint32 random = (sint32)ob_main_8001AFC8() >> 3;
        if (!count) ob_native_guest_break(0x8009B7A8, 7);
        uint32 choice = (uint8)(random % (sint32)count);
        uint32 index = r_u8(table + choice + 1), next = r_u8(table + count + choice + 1);
        w_u32(local + 28, 0); w_u32(local + 24, r_u32(0x800C507C + index * 4));
        w_u32(local + 32, r_u32(0x800C508C + r_u8(table + choice + 1) * 4));
        sub_80045A44(r_u32(object + 44), local + 24);
        w_u32(object + 288, 0); w_u16(object + 308, 2702); w_u8(object + 339, next);
    }
    if (r_u32(object + 288) == 30)
    {
        if (r_s32(object + 316) < (sint32)time) { w_u32(object + 316, time + 250); w_u32(object + 288, 31); }
        else
        {
            uint32 direction = r_u16(local + 48) >> 14;
            if (r_s16(0x800D6590 + direction * 2) > 0)
            {
                ob_game_800B7C7C(r_u32(object + 120), 0, 0);
                w_u8(r_u32(object + 120) + 113, direction);
                ob_game_8009BF8C(object, 1, r_s16(0x800C9AA8 + direction * 2), time);
            }
        }
    }
finish:
    sint32 interval = r_s16(object + 308);
    w_u32(object + 28, time);
    uint32 result = ob_game_800BCB90(object, 0, time + interval);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_8009C65C(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x8009C65C, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    uint32 interval = 300;
    switch (r_u32(object + 288))
    {
    case 3:
        if (r_s32(object + 316) < (sint32)time)
        {
            if (!r_u32(object + 132)) ob_game_800A2C8C(object);
            ob_main_8004E66C(r_u32(object + 60)); sub_80046544(r_u32(object + 52));
            w_u32(object + 288, 29);
            return 29;
        }
        else
        {
            sint32 progress = (sint32)(1500 - (r_u32(object + 316) - time));
            sint32 size = (sint32)(((sint64)progress * 0x2AAAAAAB) >> 32) - (progress >> 31);
            if (size < 30) size = 30;
            ob_game_800A2558(r_u32(object + 44), time, 1, 50, (uint16)(progress / 3), (sint16)size);
            ob_main_80011A24(0x800666C0, 128, 256, r_u32(object + 44), time, 0);
        }
        break;
    case 4:
        if (r_s32(r_u32(object + 44) + 84) >= 0)
        {
            w_u8(r_u32(object + 60) + 54, 6); w_u32(object + 288, 7); w_u32(object + 316, time + 500);
            sub_80045A44(r_u32(object + 44), 0x8006C160);
        }
        break;
    case 21:
        ob_game_80092408(r_u32(0x80083E34), 0x800C84F8, time, 6);
        if (r_s32(object + 316) < (sint32)time)
        {
            w_u32(r_u32(object + 132) + 288, 7); w_u32(r_u32(object + 132) + 316, time + 500);
        }
        break;
    case 7:
        if (!r_u32(object + 132))
        {
            uint32 node = sub_800437C4(r_u32(r_u32(object + 44) + 12), 66074);
            sub_80045378(node, time, 0x800C5268);
            uint32 child = r_u32(0x800CBA50 + (sint16)ob_game_800A50BC(0x800C5268) * 104);
            w_u32(object + 132, child); w_u32(child + 132, object);
            w_u32(r_u32(object + 132) + 316, time + 500); w_u32(r_u32(object + 132) + 288, 7);
            w_u8(0x800C8554, 0); ob_game_8009DAE0(r_u32(object + 132));
            sub_800440B8(r_u32(r_u32(r_u32(object + 132) + 136) + 48), 8);
            ob_main_8004E66C(r_u32(r_u32(object + 132) + 60));
            ob_main_8004E66C(r_u32(r_u32(r_u32(object + 132) + 136) + 60));
            ob_game_8009D81C(object, time);
        }
        /* Fall through */
    case 23:
        if (r_u8(0x800C8554))
        {
            w_u16(0x800C8552, 100); w_u16(0x800C854E, 100); w_u16(0x800C8550, 300);
            ob_game_80092408(r_u32(0x80083E34), 0x800C84F8, time, 6);
        }
        interval = 50;
        break;
    case 22:
        if (r_u8(0x800C8554)) ob_game_80092408(r_u32(0x80083E34), 0x800C84F8, time, 6);
        interval = 50;
        break;
    }
    w_u32(object + 28, time);
    return ob_game_800BCB90(object, 0, time + interval);
}

static sint32 ob_boss_remainder(sint32 value, sint32 divisor)
{
    if (!divisor) ob_native_guest_break(0x8009CEB4, 7);
    if (divisor == -1 && value == (-2147483647 - 1)) ob_native_guest_break(0x8009CEB4, 6);
    return value % divisor;
}

uint32 ob_game_8009CEB4(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x8009CEB4, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(128), interval = 300, data;
    sint32 particles = 0;
    sub_80045A7C(r_u32(object + 44), time);
    data = r_u32(object + 108);
    if (r_u32(object + 288) != 7)
    {
        uint32 position = sub_80045464(r_u32(object + 44), time);
        uint32 player = sub_80045464(r_u32(r_u32(0x8006C134) + 44), time);
        sub_80028280(r_u32(position + 8) - r_u32(player + 8), r_u32(position) - r_u32(player), local + 24, local + 28);
        w_u16(0x800CBA30 + r_s16(object + 326) * 104, r_u16(local + 24));
        uint32 matrix = ob_game_800AD6E0(local, r_s16(local + 24));
        sub_80045848(r_u32(object + 44), matrix); sub_80045B74(r_u32(object + 44));
        matrix = ob_game_800AD6E0(local, r_s16(local + 24));
        sub_80045848(r_u32(r_u32(object + 136) + 44), matrix); sub_80045B74(r_u32(r_u32(object + 136) + 44));
    }
    switch (r_u32(object + 288))
    {
    case 7:
        if (r_s32(object + 316) < (sint32)time)
        {
            w_u32(object + 316, time + 1000); w_u32(object + 288, 23);
            ob_main_8004E680(r_u32(r_u32(object + 136) + 60));
            uint32 other = r_u32(object + 132), state = r_u32(other + 288);
            if (state != 29 && state != 3) w_u32(other + 288, 23);
            w_u16(object + 306, ob_main_80011A24(0x8006A988, 128, 128, r_u32(object + 44), time, 1));
        }
        interval = 50;
        break;
    case 23:
        if ((sint32)time < r_s32(object + 316))
        {
            uint32 remaining = r_u32(object + 316) - time;
            particles = (sint32)(1000 - remaining); interval = 50;
            sub_800440B8(r_u32(r_u32(object + 136) + 48), (sint16)(256 - (sint32)(remaining * 248) / 1000));
            ob_main_80011D80(r_s16(object + 306), r_s32(object + 316) < (sint32)time ? 1512 : 1128);
        }
        else
        {
            uint32 other = r_u32(object + 132);
            w_u32(object + 288, 0); w_u32(object + 316, time + 3000);
            uint32 state = r_u32(other + 288);
            if (state != 29 && state != 3) w_u32(other + 288, 0);
            ob_game_8009DB04(object, time);
            ob_main_8004E66C(r_u32(r_u32(object + 136) + 60)); ob_main_8004E680(r_u32(object + 60));
            sub_8001195C(r_s16(object + 306));
        }
        break;
    case 0:
        if ((sint32)time < r_s32(object + 316)) ob_game_8009D9D4(object, time);
        else if (ob_game_800A2C80(data))
        {
            if (r_u32(local + 28) < 8000)
            {
                ob_game_800B7DA8(r_u32(object + 120), 18);
                w_u32(object + 288, 30); w_u32(object + 316, time + 3000);
                ob_game_800A1CA8(object, 1, time);
                ob_game_800A1BD4(object, 2); ob_game_800A1BD4(object, 10); ob_game_800A1BD4(object, 4);
                ob_game_800A1BD4(object, 9); ob_game_800A1BD4(object, 11);
            }
            else
            {
                w_u32(object + 288, 31); w_u32(object + 316, time + 999999);
                ob_game_800A1CA8(object, 12, time);
                ob_game_800A1BD4(object, 4); ob_game_800A1BD4(object, 11); ob_game_800A1BD4(object, 9); ob_game_800A1BD4(object, 3);
            }
        }
        else { w_u32(object + 288, 31); w_u32(object + 316, time); }
        break;
    case 30:
        if (r_s16(data + 32) == 2 || (uint16)(r_u16(data + 32) - 6) < 3)
        { interval = 150; ob_game_8009DB74(object, r_u32(local + 28), time); }
        break;
    case 31:
        if ((sint32)time < r_s32(object + 316)) ob_game_8009D9D4(object, time);
        else
        {
            uint32 other = r_u32(object + 132), state = r_u32(other + 288);
            if (state == 29 || state == 3) { w_u32(object + 288, 0); w_u32(object + 316, time + 3000); }
            else
            {
                w_u32(other + 288, 22); w_u32(r_u32(object + 132) + 316, time + 1000);
                w_u32(object + 316, time + 1000); w_u32(object + 288, 22);
                uint32 x = 0 - r_u32(0x800C8518), z = 0 - r_u32(0x800C8520);
                w_u32(0x800C8518, x); w_u32(0x800C8520, z);
                sub_80045378(r_u32(object + 44), time, 0x800C84F8);
                sub_80045378(r_u32(r_u32(object + 136) + 44), time, 0x800C84F8);
                ob_game_8009DAE0(object);
                ob_main_8004E66C(r_u32(object + 60)); ob_main_8004E680(r_u32(r_u32(object + 136) + 60));
                sub_800440B8(r_u32(r_u32(object + 136) + 48), 256);
                w_u16(0x800C8552, 300); w_u16(0x800C8550, 300); w_u16(0x800C854E, 100);
                w_u16(object + 306, ob_main_80011A24(0x8006A988, 128, 512, r_u32(object + 44), time, 1));
            }
        }
        break;
    case 22:
        if ((sint32)time < r_s32(object + 316))
        {
            interval = 50;
            sint32 scale = (sint32)((r_u32(object + 316) - time) * 248) / 1000;
            sub_800440B8(r_u32(r_u32(object + 136) + 48), (sint16)(scale + 8));
            ob_main_80011E20(r_s16(object + 306), r_u32(object + 44), 128, time);
            ob_main_80011D80(r_s16(object + 306), r_s32(object + 316) < (sint32)time ? 1512 : 1128);
        }
        else
        {
            ob_main_8004E66C(r_u32(r_u32(object + 136) + 60));
            uint32 other = r_u32(object + 132), state = r_u32(other + 288);
            if (state == 29 || state == 3) { w_u32(object + 288, 23); w_u32(object + 316, time + 1000); }
            else
            {
                ob_game_8009D81C(other, time); w_u32(r_u32(object + 132) + 288, 23);
                w_u32(r_u32(object + 132) + 316, time + r_u32(0x800C8530));
                w_u32(object + 288, 7); w_u32(object + 316, time + r_u32(0x800C8530));
            }
            ob_game_8009DAE0(object);
            sub_800440B8(r_u32(r_u32(object + 136) + 48), 8);
            sub_8001195C(r_s16(object + 306));
        }
        break;
    case 3:
        if (r_s32(object + 316) < (sint32)time)
        {
            uint32 other = r_u32(object + 132);
            if (r_u32(other + 288) == 29) ob_game_800A2C8C(other);
            else
            {
                w_u32(other + 132, 0); w_u32(r_u32(object + 132) + 288, 7); w_u32(r_u32(object + 132) + 316, time + 500);
            }
            uint32 result = ob_game_800BCAA0(object);
            ob_draft_scratch_release(local); return result;
        }
        else
        {
            sint32 remaining = (sint32)(r_u32(object + 316) - time);
            uint32 dying = r_u32(r_u32(object + 132) + 288) == 29;
            sint32 progress = (sint32)((dying ? 11000 : 2500) - (uint32)remaining), volume = progress / 2;
            sint32 size = progress / (dying ? 10 : 4), minimum = dying ? 60 : 20;
            if (size < minimum) size = minimum;
            ob_game_800A2558(r_u32(object + 44), time, 1, 50, (uint16)volume, (sint16)size);
            ob_main_80011A24(0x800666C0, volume >= 251 ? 250 : volume, 256, r_u32(object + 44), time, 0);
        }
        break;
    }
    if (particles)
    {
        uint32 effect = local + 32;
        ob_game_800B8E40(r_u32(object + 44), effect, time);
        w_u8(effect + 92, 12); w_u32(effect + 44, 0x800C48E4); w_u32(effect + 56, 1500);
        w_u16(effect + 86, 100); w_u16(effect + 90, 100);
        w_u16(effect + 88, ob_boss_remainder(ob_main_8001AFC8(), particles) + particles);
        sint32 half = particles / 2, quarter = particles / 4;
        w_u32(effect + 32, ob_boss_remainder(ob_main_8001AFC8(), half) - quarter);
        w_u32(effect + 36, ob_boss_remainder(ob_main_8001AFC8(), particles) + 100);
        w_u32(effect + 40, ob_boss_remainder(ob_main_8001AFC8(), half) - quarter);
        w_u8(effect + 93, 4); ob_game_80092408(r_u32(0x80083E34), effect, time, 6);
    }
    w_u32(object + 28, time);
    uint32 result = ob_game_800BCB90(object, 0, time + interval);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_8009E8FC(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x8009E8FC, "GAME.BIN");
    if (time == r_u32(object + 28)) return time;
    uint32 data = r_u32(object + 108), local = ob_draft_scratch_acquire(160);
    uint32 state = r_u32(object + 288);
    w_u32(object + 28, time);
    if (state != 3)
    {
        sint32 speed = ((sint32)(time - r_u32(object + 332)) >> 8) + 200;
        if (speed >= 1801) speed = 1800;
        ob_game_800A9E30(r_u32(data), 0, speed, 0, 1);
    }
    if ((sint32)time >= r_s32(object + 316))
    {
        uint32 node = sub_800437C4(r_u32(r_u32(object + 44) + 12), 65846);
        sub_80045A7C(node, time);
        state = r_u32(object + 288);
        switch (state)
        {
        case 3:
            sub_80045378(node, time, local);
            sint32 height = r_s32(local + 4);
            if (height >= 10001 || !r_u32(data))
            {
                sub_80011984(0x800666C4, 255, 15, 15, 256, 0, 0);
                uint32 shape = sub_800437C4(object, 65842);
                ob_main_80044080(shape, 0x800662CC);
                w_u32(object + 288, 20);
                uint32 result = ob_game_800A2C8C(object);
                ob_draft_scratch_release(local); return result;
            }
            sint32 count = height >> 11;
            if (count <= 0) count = 1;
            ob_game_800A2558(node, time, count, 100, (uint16)height, 450);
            uint32 pitch = (ob_main_8001AFC8() & 127) + 64;
            ob_main_80011A24(0x800666C0, 128, pitch, r_u32(object + 44), time, 0);
            sub_80045378(r_u32(object + 44), time, local + 16);
            ob_main_800452A4(r_u32(object + 44), time, local + 28);
            ob_main_80045410(r_u32(object + 44), local + 48);
            w_u32(local + 20, 7000);
            ob_game_8009F360(r_u32(object + 104), local + 16, object, time);
            w_u32(object + 316, time + 200);
            break;
        case 13:
            w_u32(local + 136, r_u32(0x8008D958)); w_u32(local + 140, r_u32(0x8008D95C)); w_u32(local + 144, r_u32(0x8008D960));
            w_u32(object + 316, time + 2000); w_u32(object + 288, 14);
            sub_80045A44(node, local + 136);
            if (r_s16(object + 306) == -1) w_u16(object + 306, ob_main_80011A24(0x80069138, 255, 128, r_u32(object + 44), time, 1));
            break;
        case 14:
        case 15:
            w_u32(object + 316, time + (state == 14 ? 3000 : 3750)); w_u32(object + 288, state == 14 ? 18 : 13);
            sub_80045A44(node, 0x8006C160); sub_8001195C(r_s16(object + 306)); w_u16(object + 306, -1);
            break;
        case 18:
            if ((sint32)(time - r_u32(object + 332)) <= 57600)
            {
                uint32 position = sub_80045464(r_u32(object + 44), time);
                uint32 player = sub_80045464(r_u32(r_u32(0x8006C134) + 44), time);
                sub_80028280(r_u32(player + 8) - r_u32(position + 8), r_u32(player) - r_u32(position), local + 152, local + 156);
                uint32 angle = r_u16(r_u32(data) + 26);
                w_u32(object + 288, 12); w_u32(object + 316, time + 3000); w_u16(local + 152, r_u16(local + 152) - angle);
            }
            else
            {
                w_u32(object + 316, time + 2000); w_u32(object + 288, 15);
                if (r_s16(object + 306) == -1) w_u16(object + 306, ob_main_80011A24(0x80069138, 255, 128, r_u32(object + 44), time, 1));
                sub_80045A44(node, 0x800C5298);
            }
            break;
        case 20:
            break;
        default:
            w_u32(object + 316, time + 2000); w_u32(object + 288, 15);
            if (r_s16(object + 306) == -1) w_u16(object + 306, ob_main_80011A24(0x80069138, 255, 128, r_u32(object + 44), time, 1));
            uint32 animation = r_u32(object + 120);
            w_u16(animation + 130, r_u16(animation + 130) | 0x4000);
            ob_game_800B5CB4(object, 0, r_s16(r_u32(data) + 26), time);
            sub_80045A44(node, 0x800C5298);
            break;
        }
    }
    state = r_u32(object + 288);
    if (state != 3)
    {
        uint32 threshold = r_u16(object + 320), angle = r_u16(r_u32(data) + 26);
        if ((sint16)(angle - threshold) >= 0 && (sint16)(threshold - r_u16(object + 298)) >= 0)
        {
            ob_game_800B7C7C(r_u32(object + 120), 9, 1);
            for (uint32 i = 0; i < 4; ++i)
            {
                if (i) w_u8(r_u32(object + 120) + 113, i);
                ob_game_800B5CB4(object, 1, (sint16)(r_u16(r_u32(data) + 26) - 1536), time);
                ob_game_800B5CB4(object, 1, (sint16)(r_u16(r_u32(data) + 26) + 1536), time);
            }
            ob_game_800B7DA8(r_u32(object + 120), 6);
            w_u16(object + 320, r_u16(object + 320) + 0x2000);
        }
        w_u16(object + 298, r_u16(r_u32(data) + 26)); state = r_u32(object + 288);
    }
    uint32 result = 20;
    if (state == 12) ob_game_800B5CB4(object, 0, r_s16(r_u32(data) + 26), time);
    if (state != 20) result = ob_game_800BCB90(object, 0, time + 300);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_8009FA5C(uint32 object, uint32 contact)
{
    FUNCTION_MARKER(0x8009FA5C, "GAME.BIN");
    sub_800465E8(r_u32(object + 52), r_u32(contact + 48));
    return sub_80047FF0(contact);
}

uint32 ob_game_800B75F0(uint32 object, uint32 contact)
{
    FUNCTION_MARKER(0x800B75F0, "GAME.BIN");
    sub_800465E8(r_u32(contact + 8), r_u32(contact + 48));
    return sub_80047FF0(contact);
}

uint32 ob_game_800B5B48(uint32 object, uint32 contact, uint32 time)
{
    FUNCTION_MARKER(0x800B5B48, "GAME.BIN");
    ob_main_80011A24(0x800666C0, 128, 128, r_u32(object + 44), time, 0);
    ob_game_800B8D40(r_u32(object + 44), 0, time);
    ob_game_800B982C(r_u32(object + 44), 250, 6, time);
    sub_80047FF0(contact);
    return ob_game_800B6C38(object);
}

uint32 ob_game_8009A3C4(uint32 object, uint32 contact, uint32 time)
{
    FUNCTION_MARKER(0x8009A3C4, "GAME.BIN");
    if (r_u32(contact + 28) & 0x8020)
    {
        uint32 target = r_u32(contact + 52);
        ob_main_80011A24(0x800666C0, 128, 256, r_u32(object + 44), time, 0);
        ob_game_8009A4A8(target, time);
        sub_800465E8(r_u32(object + 52), r_u32(contact + 48));
        return sub_80047FF0(contact);
    }
    ob_main_80011A24(0x800666C0, 128, 256, r_u32(object + 44), time, 0);
    ob_game_800B7EEC(r_u32(object + 44), 0, time);
    sub_80047FF0(contact);
    return ob_game_800B6C38(object);
}

uint32 ob_game_800B7418(uint32 object, uint32 contact, uint32 time)
{
    FUNCTION_MARKER(0x800B7418, "GAME.BIN");
    uint32 target = r_u32(contact + 52);
    if (r_u32(target + 292) != 224) sub_800465E8(r_u32(contact + 8), r_u32(contact + 48));
    if (r_u32(object + 104))
    {
        if (!(r_u32(contact + 28) & 0x10804400) || r_s16(target + 132) != 5)
        {
            uint32 flags = r_u16(object + 142);
            w_u32(object + 128, time - 1); w_u16(object + 142, (flags & 0xFFF) | 0x3000);
        }
        w_u32(object + 104, 0);
    }
    else
    {
        if (r_u32(contact + 28) & 0x10804400)
        {
            sint32 damage = r_s16(target + 138);
            if (damage < 0) damage = (sint16)ob_game_800B8F08(r_u32(object + 44), r_u32(object + 44), r_s16(object + 140), (sint16)(0 - damage));
            sint32 health = r_s16(object + 144);
            if (health - damage > 0) w_u16(object + 144, health - damage);
            else if (health)
            {
                uint32 flags = r_u16(object + 142);
                w_u32(object + 128, time + 100000); w_u16(object + 144, 0); w_u16(object + 142, (flags & 0xFFF) | 0x1000);
            }
        }
        if ((r_u16(object + 142) & 0x3000) == 0x1000 && (r_u32(contact + 28) & 0x8020) &&
            (sint16)ob_game_80099798(r_u32(object + 44) + 108, r_u32(target + 44) + 108) < r_s16(object + 140) / 2)
            ob_game_8009A4A8(r_u32(contact + 52), time);
    }
    return sub_80047FF0(contact);
}

uint32 ob_game_8009BF8C(uint32 object, uint32 side, uint32 angle, uint32 time)
{
    FUNCTION_MARKER(0x8009BF8C, "GAME.BIN");
    uint32 child = ob_game_800B5CB4(object, (uint8)side, (sint16)angle, time), result = child;
    if (child) for (uint32 i = 0; i < 4; ++i) result = sub_800465E8(r_u32(child + 52), r_u32(0x800C84A0 + i * 4));
    return result;
}

uint32 ob_game_8009F360(uint32 owner, uint32 descriptor, uint32 parent, uint32 time)
{
    FUNCTION_MARKER(0x8009F360, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(8);
    w_u32(local, 0); sub_800262CC(local, 160);
    uint32 object = r_u32(local);
    if (object) ob_game_8009F3DC(object, owner, descriptor, parent, time);
    uint32 result = r_u32(local);
    ob_draft_scratch_release(local); return result;
}

uint32 ob_game_8009DB60(uint32 object)
{
    FUNCTION_MARKER(0x8009DB60, "GAME.BIN");
    w_u32(r_u32(object + 108) + 4, 0x800C510C);
    return 0x800C510C;
}

uint32 ob_game_8009DB04(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x8009DB04, "GAME.BIN");
    ob_game_8009DB60(object); ob_game_800A1CA8(object, 0, time); ob_game_800A1BD4(object, 3);
    return ob_game_800A1D74(object, time);
}

uint32 ob_game_8009DAE0(uint32 object)
{
    FUNCTION_MARKER(0x8009DAE0, "GAME.BIN");
    ob_game_800A2C78(r_u32(object + 108));
    return 0;
}

uint32 ob_game_8009DB74(uint32 object, uint32 distance, uint32 time)
{
    FUNCTION_MARKER(0x8009DB74, "GAME.BIN");
    uint32 animation = r_u32(object + 120);
    if (r_s8(animation + 135) != 6) ob_game_800B7C7C(animation, 6, 0);
    uint32 child = ob_game_800B5CB4(object, 0, 0, time);
    if (child) sub_800465E8(r_u32(child + 52), r_u32(object + 52));
    uint32 result = ob_game_800B5CB4(object, 1, 0, time);
    if (result) return sub_800465E8(r_u32(result + 52), r_u32(object + 52));
    return result;
}

uint32 ob_game_8009D9D4(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x8009D9D4, "GAME.BIN");
    if (r_u32(r_u32(object + 132) + 288) != 29) return 29;
    uint32 local = ob_draft_scratch_acquire(48);
    uint32 position = sub_80045464(r_u32(object + 44), time);
    uint32 player = sub_80045464(r_u32(r_u32(0x8006C134) + 44), time);
    sub_80028280(r_u32(player + 8) - r_u32(position + 8), r_u32(player) - r_u32(position), local + 40, local + 44);
    uint32 distance = r_u32(local + 44), vector = 0x8006C160;
    if (distance - 5001 >= 999)
    {
        sint32 angle = r_s16(local + 40);
        if (distance < 5000) angle = (sint16)(r_u16(local + 40) ^ 0x8000);
        sub_80029F58(angle, local); sub_80029B70(0x800C5284, local, local + 24); vector = local + 24;
    }
    uint32 result = sub_80045A44(r_u32(object + 44), vector);
    ob_draft_scratch_release(local); return result;
}

uint32 ob_game_8009D81C(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x8009D81C, "GAME.BIN");
    uint32 node = sub_800437C4(r_u32(r_u32(object + 44) + 12), 66074);
    uint32 position = sub_80045464(node, time), row = 0x800CBA20 + r_s16(r_u32(object + 132) + 326) * 104;
    uint32 random = ob_main_8001AFC8();
    w_u32(row, r_u32(position) - 0x3FFF + (random & 0x7FFF)); w_u32(row + 4, r_u32(position + 4));
    random = ob_main_8001AFC8(); w_u32(row + 8, r_u32(position + 8) - 0x3FFF + (random & 0x7FFF));
    sub_800458B4(r_u32(r_u32(object + 132) + 44), row, time);
    sub_800458B4(r_u32(r_u32(r_u32(object + 132) + 136) + 44), row, time);
    ob_game_800B8E40(node, 0x800C84F8, time);
    w_u8(0x800C8554, 8); w_u32(0x800C8524, 0x800C48E4); w_u8(0x800C8555, 4);
    uint32 local = ob_draft_scratch_acquire(48);
    sub_80028280(r_u32(row + 8) - r_u32(position + 8), r_u32(row) - r_u32(position), local + 40, local + 44);
    sub_80029F58(r_s16(local + 40), local);
    w_u32(local + 28, 0); w_u32(local + 24, 0); w_u32(local + 32, 4500);
    sub_80029B70(local + 24, local, 0x800C8518);
    uint32 result = (r_u32(local + 44) << 8) / 4500;
    w_u32(0x800C8530, result); ob_draft_scratch_release(local); return result;
}

uint32 ob_game_800B8D40(uint32 node, uint32 unused, uint32 time)
{
    FUNCTION_MARKER(0x800B8D40, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(96);
    ob_game_800B8E40(node, local, time);
    w_u32(local + 44, 0x800C48C4); w_u32(local + 56, 900);
    w_u16(local + 88, 250); w_u8(local + 92, 8); w_u16(local + 86, 125); w_u16(local + 90, 125); w_u8(local + 93, 4);
    uint32 result = ob_game_80092408(r_u32(0x80083E34), local, time, 1);
    ob_draft_scratch_release(local); return result;
}

uint32 ob_game_8009F3DC(uint32 object, uint32 owner, uint32 descriptor, uint32 parent, uint32 time)
{
    FUNCTION_MARKER(0x8009F3DC, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(88);
    w_u32(descriptor + 64, 0x8006912C); w_u32(descriptor + 68, local); w_u32(descriptor + 72, 0);
    w_u16(descriptor + 60, (ob_main_8001AFC8() & 511) + 200); w_u32(descriptor + 80, 6);
    w_u32(descriptor + 32, (ob_main_8001AFC8() & 2047) - 1024);
    w_u32(descriptor + 36, 988 - (ob_main_8001AFC8() & 1023));
    w_u32(descriptor + 40, (ob_main_8001AFC8() & 2047) - 1024); w_u32(descriptor + 44, 0); w_u16(descriptor + 86, 0);
    w_u32(descriptor + 96, 0x800CBA00 + r_s16(parent + 326) * 104);
    ob_game_800B66C4(object, owner, descriptor, time);
    w_u32(object + 52, 0); w_u32(object + 100, 0x8009F544); w_u32(object + 92, time + 100);
    sub_80045EF4(object + 64); sub_80045B74(r_u32(object + 44));
    uint32 x = (ob_main_8001AFC8() & 0x3FFF) - 0x2000, y = (ob_main_8001AFC8() & 0x3FFF) - 0x2000;
    uint32 z = (ob_main_8001AFC8() & 0x3FFF) - 0x2000;
    w_u32(object + 108, ob_game_800A9D9C(r_u32(object + 44), x, y, z));
    ob_draft_scratch_release(local); return object;
}

uint32 ob_game_8009F544(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x8009F544, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    uint32 node = r_u32(object + 44), elapsed = time - r_u32(object + 28);
    w_u32(node + 136, r_u32(node + 136) - elapsed);
    sub_80045ADC(r_u32(object + 44)); sub_80045B74(r_u32(object + 44));
    w_u32(object + 28, time); w_u32(object + 92, time + 100);
    return sub_80045EF4(object + 64);
}
