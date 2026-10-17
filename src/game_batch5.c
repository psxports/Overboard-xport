#include "xport.h"
#include "psx.h"
#include "game_signatures.h"
#include "native_extra_signatures.h"
#include "draft_signatures.h"
#include "movie_player.h"

uint32 ob_game_8009C9E0(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x8009C9E0, "GAME.BIN");
    uint32 source = r_u32(record + 52);
    sub_80045A7C(r_u32(object + 44), time);
    uint32 flags = r_u32(record + 28);
    if (flags & 0x10804400)
    {
        ob_main_80011A24(0x80066304, 128, 256, r_u32(object + 44), time, 0);
        if (r_u32(object + 288) == 6) w_u32(object + 288, 4);
        if (r_u32(object + 132))
        {
            uint32 slot = (uint32)(sint32)r_s16(object + 326);
            if (r_u16(0x800CBA46 + slot * 104))
            {
                uint32 rate = ob_game_800B8FBC(object, r_u32(record + 52));
                if (ob_game_800A52C4(object, (uint32)(sint32)(sint16)rate, 0xFFFFFFFF))
                {
                    uint32 parent = r_u32(object + 132);
                    w_u32(object + 288, 3);
                    w_u32(object + 316, time + 1500);
                    uint32 health = ob_game_800901A8(r_u32(parent + 292));
                    parent = r_u32(object + 132);
                    health &= 0xFFFF;
                    w_u32(0x800D6498, health);
                    w_u32(0x800C835C, health);
                    slot = (uint32)(sint32)r_s16(parent + 326);
                    w_u16(0x800CBA46 + slot * 104, health * 2);
                }
            }
        }
        return (uint32)sub_80047FF0(record);
    }
    if (!(flags & 0x8020)) return (uint32)sub_80047FF0(record);
    uint32 slot = (uint32)(sint32)r_s16(object + 326);
    if (r_u16(0x800CBA46 + slot * 104))
    {
        ob_game_800A2AEC(object, source, 1500, time);
        w_u32(r_u32(source + 124) + 8, time + 500);
    }
    else
    {
        ob_game_800A2AEC(object, source, 500, time);
        w_u32(r_u32(source + 124) + 8, time + 100);
    }
    slot = (uint32)(sint32)r_s16(object + 326);
    if (r_u16(0x800CBA46 + slot * 104))
    {
        slot = (uint32)(sint32)r_s16(source + 326);
        if (r_u16(0x800CBA46 + slot * 104)) ob_game_800A52C4(source, 64, 0xFFFFFFFF);
    }
    sub_80047FF0(record);
    return sub_80045A44(r_u32(object + 44), 0x8006C160);
}

uint32 ob_game_800A7440(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x800A7440, "GAME.BIN");
    uint32 flags = r_u32(record + 28);
    uint32 source = r_u32(record + 52);
    if (flags & 0x8000)
    {
        sub_80047FF0(record);
        uint32 slot = (uint32)(sint32)r_s16(source + 326);
        if (r_u16(0x800CBA46 + slot * 104)) ob_game_800A52C4(source, 64, 0xFFFFFFFF);
        ob_main_80011A24(0x800663DC, 128, 256, r_u32(object + 44), time, 0);
        slot = (uint32)(sint32)r_s16(source + 326);
        if (r_u16(0x800CBA46 + slot * 104))
        {
            sub_80045A7C(r_u32(object + 44), time);
            uint32 first = sub_80045464(r_u32(source + 44), time);
            uint32 second = sub_80045464(r_u32(object + 44), time);
            uint32 locals = ob_draft_scratch_acquire(24);
            uint32 first_z = r_u32(first + 8);
            uint32 second_z = r_u32(second + 8);
            uint32 first_x = r_u32(first);
            uint32 second_x = r_u32(second);
            sub_80028280((sint32)(first_z - second_z), (sint32)(first_x - second_x), locals, locals + 4);
            if ((sint32)time < (sint32)(r_u32(source + 280) + 250) && r_u16(source + 300) == r_u16(object + 302))
            {
                uint32 data = r_u32(source + 124);
                w_u32(data, r_u32(data) + 1000);
                sub_80045A44(r_u32(object + 44), 0x8006C160);
            }
            else
            {
                uint32 data = r_u32(source + 124);
                sint32 angle = r_s16(locals);
                sint32 previous = r_s16(data + 4);
                uint32 difference = (uint32)(angle - previous < 0 ? previous - angle : angle - previous) & 0xFFFF;
                if (difference < 0x4000)
                {
                    data = r_u32(source + 124);
                    w_u16(data + 4, r_u16(locals));
                    w_u32(r_u32(source + 124), 5000);
                }
                else
                {
                    uint32 heading = r_u16(locals);
                    data = r_u32(source + 124);
                    w_u16(data + 4, heading - 0x8000);
                    w_u32(r_u32(source + 124), (uint32)-5000);
                }
            }
            ob_draft_scratch_release(locals);
        }
        uint32 result = time + 250;
        w_u32(r_u32(source + 124) + 8, result);
        return result;
    }
    if (flags & 0x20)
    {
        sub_80047FF0(record);
        ob_main_80011A24(0x800663DC, 128, 256, r_u32(object + 44), time, 0);
        w_u32(object + 280, time);
        uint32 result = r_u16(source + 302);
        w_u16(object + 300, result);
        return result;
    }
    return (uint32)sub_80047FF0(record);
}

uint32 ob_main_8002C7D8(void)
{
    FUNCTION_MARKER(0x8002C7D8, "SLES_008.65");
    uint32 viewport = r_u32(0x800773AC);
    uint32 camera = r_u32(0x8007741C);
    w_u32(0x80077504, 0x8002CF44);
    w_u32(viewport + 12, 256);
    w_u32(viewport, 384);
    w_u32(viewport + 4, 240);
    w_u32(viewport + 8, 384);
    w_u32(camera, 0);
    w_u32(camera + 4, viewport);
    w_u32(camera + 8, 0);
    w_u32(camera + 12, 0);
    w_u32(camera + 16, 1);
    w_u32(camera + 20, 0);
    uint32 primitive = ob_draft_scratch_acquire(24);
    ob_draft_unresolved_call(0x8005BAE8, 1, primitive);
    w_u8(primitive + 4, 0);
    w_u8(primitive + 5, 0);
    w_u8(primitive + 6, 0);
    w_u16(primitive + 8, 0);
    w_u16(primitive + 10, 0);
    w_u16(primitive + 12, 384);
    w_u16(primitive + 14, 0);
    w_u16(primitive + 16, 0);
    w_u16(primitive + 18, 240);
    w_u16(primitive + 20, 384);
    w_u16(primitive + 22, 240);
    w_u32(0x8007737C, 0x80086AD8);
    ob_draft_unresolved_call(0x8005C954, 2, 0x80086B48, 8);
    w_u32(0x8007737C, 0x80086A48);
    ob_draft_unresolved_call(0x8005C954, 2, 0x80086AB8, 8);
    ob_draft_unresolved_call(0x8005C064, 1, 0);
    ob_draft_unresolved_call(0x8005ABC0, 5, 0x80086A48, 0, 0, 384, 240);
    ob_draft_unresolved_call(0x8005AC90, 5, 0x80086AA4, 0, 240, 384, 240);
    ob_draft_unresolved_call(0x8005ABC0, 5, 0x80086AD8, 0, 240, 384, 240);
    ob_draft_unresolved_call(0x8005AC90, 5, 0x80086B34, 0, 0, 384, 240);
    w_u32(0x800775DC, 384);
    w_u32(0x800775E0, 0);
    w_u32(0x80077370, 384);
    w_u32(0x80077378, 0);
    ob_draft_unresolved_call(0x8005AD0C, 2, 960, 256);
    uint32 font = ob_draft_unresolved_call(0x8005ADB0, 6, 26, 32, 256, 200, 0, 512);
    ob_draft_unresolved_call(0x8005ACCC, 1, font);
    ob_draft_unresolved_call(0x8005C504, 1, 0);
    ob_draft_unresolved_call(0x80059CA8, 1, 0);
    ob_draft_unresolved_call(0x8005B994, 2, r_u32(0x8007737C) + 112, primitive);
    ob_draft_unresolved_call(0x8005CB78, 1, 0x80086A48);
    ob_draft_unresolved_call(0x8005CB04, 1, r_u32(0x8007737C) + 112);
    ob_draft_unresolved_call(0x8005C504, 1, 0);
    ob_draft_unresolved_call(0x8005CB78, 1, 0x80086AD8);
    ob_draft_unresolved_call(0x8005CB04, 1, r_u32(0x8007737C) + 112);
    ob_draft_unresolved_call(0x8005C504, 1, 0);
    w_u32(0x8007737C, 0x80086AD8);
    ob_draft_unresolved_call(0x8005C954, 2, 0x80086B48, 8);
    w_u32(0x8007737C, 0x80086A48);
    ob_draft_unresolved_call(0x8005C954, 2, 0x80086AB8, 8);
    ob_draft_unresolved_call(0x8005C468, 1, 1);
    ob_draft_unresolved_call(0x8005CD50, 1, 0x80086AA4);
    ob_draft_unresolved_call(0x8005CB78, 1, 0x80086A48);
    w_u32(0x800773D0, 0);
    ob_draft_scratch_release(primitive);
    return 0xFFFFFFFF;
}

uint32 ob_game_800966EC(uint32 object, uint32 requested, uint32 time)
{
    FUNCTION_MARKER(0x800966EC, "GAME.BIN");
    uint32 previous = r_u32(object + 288);
    uint32 data = r_u32(object + 108);
    if (previous == requested) return previous;
    if (requested != 14 && requested != 15) return 15;
    if (requested == 14)
    {
        uint32 slot = (uint32)(sint32)r_s16(object + 326);
        w_u16(0x800CBA32 + slot * 104, 1);
        w_u8(0x800D6492, 1);
        if (r_u32(object + 288) == 12) return 25;
        uint32 active = r_u32(object + 64);
        w_u16(object + 308, 25);
        if (active) sub_80045F20(object + 64);
        ob_game_800C0744(object, 0, time);
        w_u32(object + 288, requested);
        return ob_main_80011A24(0x8006649C, 128, 256, r_u32(object + 44), time, 0);
    }
    uint32 parent = r_u32(data);
    uint32 position = sub_80045464(r_u32(parent + 44), time);
    uint32 bounds = ob_draft_scratch_acquire(32);
    w_u32(bounds, r_u32(position) - 4500);
    w_u32(bounds + 4, r_u32(position + 4) - 100);
    w_u32(bounds + 8, r_u32(position + 8) - 4500);
    w_u32(bounds + 16, r_u32(position) + 4500);
    w_u32(bounds + 20, r_u32(position + 4) + 100);
    w_u32(bounds + 24, r_u32(position + 8) + 4500);
    /* TODO Bind the missing box query adapter */
    uint32 hit = ob_draft_unresolved_call(0x80049FCC, 4, bounds, bounds + 16, 0x400080A0, time);
    ob_draft_scratch_release(bounds);
    uint32 slot = (uint32)(sint32)r_s16(object + 326);
    w_u16(0x800CBA32 + slot * 104, 0);
    w_u8(0x800D6492, 1);
    if (!hit)
    {
        if (r_u32(object + 288) != 13)
        {
            uint32 shape = r_u32(parent + 52);
            if (r_u32(shape + 28)) ob_main_8004659C(shape, time);
            uint32 active = r_u32(object + 64);
            w_u16(object + 308, 25);
            if (active) sub_80045F20(object + 64);
            ob_game_800C0744(object, 0, time);
            w_u32(object + 288, requested);
        }
        return ob_main_80011A24(0x8006649C, 128, 256, r_u32(object + 44), time, 0);
    }
    uint32 active = r_u32(object + 64);
    w_u16(object + 308, 25);
    if (active) sub_80045F20(object + 64);
    ob_game_800C0744(object, 0, time + 25);
    w_u32(object + 288, 38);
    return 38;
}


static uint32 ob_batch5_rotate_pair(uint32 first, uint32 second, uint32 first_scale, uint32 second_scale)
{
    return (first * first_scale + second * second_scale) >> 14;
}

uint32 ob_main_8002DF2C(uint32 matrix, uint32 angles, uint32 local)
{
    FUNCTION_MARKER(0x8002DF2C, "SLES_008.65");
    uint32 index = (r_u16(angles) + 8) >> 4;
    uint32 a = (uint32)(sint32)r_s16(matrix);
    uint32 cosine = (uint32)(sint32)r_s16(0x8006CB04 + index * 2);
    uint32 b;
    uint32 sine;
    uint32 c;
    uint32 d;
    uint32 e;
    uint32 f;
    uint32 result;
    if (local)
    {
        sine = (uint32)(sint32)r_s16(0x8006C304 + index * 2);
        b = (uint32)(sint32)r_s16(matrix + 12);
        c = (uint32)(sint32)r_s16(matrix + 2);
        d = (uint32)(sint32)r_s16(matrix + 14);
        e = (uint32)(sint32)r_s16(matrix + 4);
        f = (uint32)(sint32)r_s16(matrix + 16);
        w_u16(matrix, ob_batch5_rotate_pair(a, b, cosine, 0 - sine));
        w_u16(matrix + 2, ob_batch5_rotate_pair(c, d, cosine, 0 - sine));
        w_u16(matrix + 4, ob_batch5_rotate_pair(e, f, cosine, 0 - sine));
        w_u16(matrix + 12, ob_batch5_rotate_pair(a, b, sine, cosine));
        w_u16(matrix + 14, ob_batch5_rotate_pair(c, d, sine, cosine));
        result = ob_batch5_rotate_pair(e, f, sine, cosine);
    }
    else
    {
        b = (uint32)(sint32)r_s16(matrix + 4);
        sine = (uint32)(sint32)r_s16(0x8006C304 + index * 2);
        c = (uint32)(sint32)r_s16(matrix + 6);
        d = (uint32)(sint32)r_s16(matrix + 10);
        e = (uint32)(sint32)r_s16(matrix + 12);
        f = (uint32)(sint32)r_s16(matrix + 16);
        w_u16(matrix + 10, ob_batch5_rotate_pair(c, d, 0 - sine, cosine));
        w_u16(matrix, ob_batch5_rotate_pair(a, b, cosine, sine));
        w_u16(matrix + 4, ob_batch5_rotate_pair(a, b, 0 - sine, cosine));
        w_u16(matrix + 6, ob_batch5_rotate_pair(c, d, cosine, sine));
        w_u16(matrix + 12, ob_batch5_rotate_pair(e, f, cosine, sine));
        result = ob_batch5_rotate_pair(e, f, 0 - sine, cosine);
    }
    w_u16(matrix + 16, result);
    return result;
}

uint32 ob_main_8002E2BC(uint32 matrix, uint32 angles, uint32 local)
{
    FUNCTION_MARKER(0x8002E2BC, "SLES_008.65");
    uint32 index = (r_u16(angles + 2) + 8) >> 4;
    uint32 result;
    if (local)
    {
        uint32 a = (uint32)(sint32)r_s16(matrix + 6);
        uint32 cosine = (uint32)(sint32)r_s16(0x8006CB04 + index * 2);
        uint32 b = (uint32)(sint32)r_s16(matrix + 12);
        uint32 sine = (uint32)(sint32)r_s16(0x8006C304 + index * 2);
        uint32 c = (uint32)(sint32)r_s16(matrix + 8);
        uint32 d = (uint32)(sint32)r_s16(matrix + 14);
        uint32 e = (uint32)(sint32)r_s16(matrix + 10);
        uint32 f = (uint32)(sint32)r_s16(matrix + 16);
        w_u16(matrix + 8, ob_batch5_rotate_pair(c, d, cosine, sine));
        w_u16(matrix + 10, ob_batch5_rotate_pair(e, f, cosine, sine));
        w_u16(matrix + 14, ob_batch5_rotate_pair(c, d, 0 - sine, cosine));
        w_u16(matrix + 6, ob_batch5_rotate_pair(a, b, cosine, sine));
        w_u16(matrix + 12, ob_batch5_rotate_pair(a, b, 0 - sine, cosine));
        result = ob_batch5_rotate_pair(e, f, 0 - sine, cosine);
    }
    else
    {
        uint32 a = (uint32)(sint32)r_s16(matrix + 2);
        uint32 cosine = (uint32)(sint32)r_s16(0x8006CB04 + index * 2);
        uint32 sine = (uint32)(sint32)r_s16(0x8006C304 + index * 2);
        uint32 b = (uint32)(sint32)r_s16(matrix + 4);
        uint32 c = (uint32)(sint32)r_s16(matrix + 8);
        uint32 d = (uint32)(sint32)r_s16(matrix + 10);
        uint32 e = (uint32)(sint32)r_s16(matrix + 14);
        uint32 f = (uint32)(sint32)r_s16(matrix + 16);
        w_u16(matrix + 4, ob_batch5_rotate_pair(a, b, sine, cosine));
        w_u16(matrix + 2, ob_batch5_rotate_pair(a, b, cosine, 0 - sine));
        w_u16(matrix + 8, ob_batch5_rotate_pair(c, d, cosine, 0 - sine));
        w_u16(matrix + 10, ob_batch5_rotate_pair(c, d, sine, cosine));
        w_u16(matrix + 14, ob_batch5_rotate_pair(e, f, cosine, 0 - sine));
        result = ob_batch5_rotate_pair(e, f, sine, cosine);
    }
    w_u16(matrix + 16, result);
    return result;
}

uint32 ob_game_8009C018(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x8009C018, "GAME.BIN");
    uint32 source = r_u32(record + 52);
    sub_80045A7C(r_u32(object + 44), time);
    uint32 flags = r_u32(record + 28);
    if (flags & 0x10904400)
    {
        uint32 slot = (uint32)(sint32)r_s16(object + 326);
        if (!r_u16(0x800CBA46 + slot * 104)) return (uint32)sub_80047FF0(record);
        uint32 first = r_u16(0x800D6590);
        uint32 second = r_u16(0x800D6592);
        uint32 third = r_u16(0x800D6594);
        uint32 fourth = r_u16(0x800D6596);
        if (first | second | third | fourth) return (uint32)sub_80047FF0(record);
        source = r_u32(record + 52);
        sint32 rate = (sint16)ob_game_800B8FBC(object, source);
        sint32 kind = r_s16(source + 132);
        if (kind == 5) rate /= 8;
        else if (kind == 4) rate /= 4;
        ob_game_800A52C4(object, (uint32)(sint32)(sint16)rate, 0xFFFFFFFF);
        slot = (uint32)(sint32)r_s16(object + 326);
        uint32 total = r_u32(0x800C835C);
        uint32 health = r_u16(0x800CBA46 + slot * 104);
        w_u32(0x800C835C, total - ((uint32)rate << 6));
        if (!health)
        {
            uint32 x = r_u32(0x8008D874);
            uint32 y = r_u32(0x8008D878);
            uint32 z = r_u32(0x8008D87C);
            uint32 vector = ob_draft_scratch_acquire(16);
            w_u32(vector, x);
            w_u32(vector + 4, y);
            w_u32(vector + 8, z);
            sub_80045A44(r_u32(object + 44), 0x8006C160);
            uint32 node = (uint32)sub_800437C4(r_u32(r_u32(object + 44) + 12), 66002);
            sub_80045A7C(node, time);
            sub_80045A44(node, vector);
            ob_draft_scratch_release(vector);
            ob_main_80011A24(0x800666C4, 255, 256, r_u32(object + 44), time, 0);
            w_u32(object + 288, 3);
            w_u32(object + 316, time + 2666);
        }
        return (uint32)sub_80047FF0(record);
    }
    if (flags & 0x8020)
    {
        uint32 slot = (uint32)(sint32)r_s16(object + 326);
        if (r_u16(0x800CBA46 + slot * 104))
        {
            slot = (uint32)(sint32)r_s16(source + 326);
            if (r_u16(0x800CBA46 + slot * 104)) ob_game_800A52C4(source, 10, 0xFFFFFFFF);
        }
    }
    return (uint32)sub_80047FF0(record);
}

uint32 ob_game_800AA390(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x800AA390, "GAME.BIN");
    uint32 flags = r_u32(record + 28);
    uint32 data = r_u32(object + 108);
    uint32 source = r_u32(record + 52);
    uint32 parent = r_u32(data);
    if (flags & 0x8020)
    {
        sub_80045A7C(r_u32(source + 44), time);
        sub_80045A7C(r_u32(object + 44), time);
        w_u32(object + 280, time);
        w_u16(object + 300, r_u16(source + 302));
        if ((sint32)time < (sint32)(r_u32(source + 280) + 50))
        {
            w_u32(r_u32(source + 124), 0);
            uint32 slot = (uint32)(sint32)r_s16(parent + 326);
            if (!r_u16(0x800CBA46 + slot * 104)) sub_80046544(r_u32(object + 52));
        }
        else
        {
            uint32 slot = (uint32)(sint32)r_s16(parent + 326);
            if (r_u16(0x800CBA46 + slot * 104))
            {
                slot = (uint32)(sint32)r_s16(source + 326);
                if (r_u16(0x800CBA46 + slot * 104)) ob_game_800A52C4(source, 8, 0xFFFFFFFF);
            }
            else
            {
                ob_game_800A2AEC(object, source, 500, time);
                w_u32(r_u32(source + 124) + 8, time + 100);
            }
        }
        w_u32(source + 280, time);
        w_u16(source + 300, r_u16(object + 302));
        sub_80047FF0(record);
        return sub_80045A44(r_u32(object + 44), 0x8006C160);
    }
    if (!(flags & 0x10804400)) return (uint32)sub_80047FF0(record);
    sub_80047FF0(record);
    uint32 slot = (uint32)(sint32)r_s16(parent + 326);
    uint32 health = r_u16(0x800CBA46 + slot * 104);
    if (!health) return health;
    /* Original reads the collision record again after releasing it */
    sint32 rate = (sint16)ob_game_800B8FBC(object, r_u32(record + 52));
    w_u32(0x800C835C, r_u32(0x800C835C) - ((uint32)rate << 6));
    if (ob_game_800A52C4(parent, (uint32)rate, 0xFFFFFFFF)) return ob_game_800AAC34(parent, time);
    if (rate < 36) return 1;
    return ob_main_80011A24(0x800698C0, 255, 256, r_u32(object + 44), time, 0);
}


uint32 ob_game_800AB640(uint32 object, uint32 unused, uint32 time)
{
    FUNCTION_MARKER(0x800AB640, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    sub_80045A7C(r_u32(object + 44), time);
    uint32 locals = ob_draft_scratch_acquire(64);
    uint32 result;
    if ((sint32)time < r_s32(data + 4))
    {
        uint32 speed = 0 - (uint32)(sint32)r_s16(data + 14);
        uint32 elapsed = r_u32(data + 8) - time;
        sint32 rotation = (sint32)(speed * elapsed) / 1000;
        uint32 state = r_u32(object + 124);
        uint32 heading = r_u16(data + 12) - r_u16(state + 4);
        uint32 matrix = ob_draft_unresolved_call(0x8004545C, 2, r_u32(object + 44), time);
        sub_8002ADFC(matrix, (uint32)(sint32)(sint16)heading, locals);
        sub_8002A870(locals, (uint32)(sint32)(sint16)rotation, locals + 24);
        sub_8002ADFC(locals + 24, (uint32)(sint32)(sint16)(0 - heading), locals);
        sub_80045848(r_u32(object + 44), locals);
        sub_80045B74(r_u32(object + 44));
        w_u32(locals + 56, 0);
        w_u32(locals + 48, 0);
        uint32 remaining = r_u32(data + 4) - time;
        sint32 velocity = (sint32)(0 - (1000 - remaining) * 500) / 1000;
        w_u32(locals + 52, (uint32)velocity);
        sub_80045A44(r_u32(object + 44), locals + 48);
        w_u32(data + 8, time);
        w_u32(object + 100, 0x800AB640);
        w_u32(object + 92, time + 50);
        result = sub_80045EF4(object + 64);
    }
    else
    {
        ob_game_8009A704(object);
        w_u8(r_u32(object + 60) + 54, 1);
        uint32 child = r_u32(object + 136);
        if (child) ob_main_8004E66C(r_u32(child + 60));
        sub_80045A44(r_u32(object + 44), 0x800C61B4);
        sub_800453C4(r_u32(object + 44), time, locals + 48);
        uint32 x = r_u32(locals + 48);
        uint32 y = r_u32(locals + 52);
        uint32 z = r_u32(locals + 56);
        sint32 classification = (sint16)ob_game_800AC238(x, y, z);
        uint32 slot = (uint32)(sint32)r_s16(object + 326);
        w_u8(0x800CBA5D + slot * 104, (uint32)classification);
        w_u16(object + 308, classification ? 1500 : 3000);
        ob_game_800AC338(object);
        uint32 duration = (uint32)(sint32)r_s16(object + 308);
        w_u32(object + 100, 0x800AB8BC);
        w_u32(object + 92, time + duration);
        sub_80045EF4(object + 64);
        result = ob_draft_unresolved_call(0x800B83FC, 4, r_u32(object + 44), 10, 300, time);
    }
    ob_draft_scratch_release(locals);
    return result;
}

uint32 ob_main_8002E64C(uint32 matrix, uint32 angles, uint32 local)
{
    FUNCTION_MARKER(0x8002E64C, "SLES_008.65");
    uint32 index = (r_u16(angles + 4) + 8) >> 4;
    uint32 a = (uint32)(sint32)r_s16(matrix);
    uint32 cosine = (uint32)(sint32)r_s16(0x8006CB04 + index * 2);
    uint32 result;
    if (local)
    {
        uint32 b = (uint32)(sint32)r_s16(matrix + 6);
        uint32 sine = (uint32)(sint32)r_s16(0x8006C304 + index * 2);
        uint32 c = (uint32)(sint32)r_s16(matrix + 2);
        uint32 d = (uint32)(sint32)r_s16(matrix + 8);
        uint32 e = (uint32)(sint32)r_s16(matrix + 4);
        uint32 f = (uint32)(sint32)r_s16(matrix + 10);
        w_u16(matrix, ob_batch5_rotate_pair(a, b, cosine, sine));
        w_u16(matrix + 2, ob_batch5_rotate_pair(c, d, cosine, sine));
        w_u16(matrix + 6, ob_batch5_rotate_pair(a, b, 0 - sine, cosine));
        w_u16(matrix + 4, ob_batch5_rotate_pair(e, f, cosine, sine));
        w_u16(matrix + 8, ob_batch5_rotate_pair(c, d, 0 - sine, cosine));
        result = ob_batch5_rotate_pair(e, f, 0 - sine, cosine);
        w_u16(matrix + 10, result);
    }
    else
    {
        uint32 sine = (uint32)(sint32)r_s16(0x8006C304 + index * 2);
        uint32 b = (uint32)(sint32)r_s16(matrix + 2);
        uint32 c = (uint32)(sint32)r_s16(matrix + 6);
        uint32 d = (uint32)(sint32)r_s16(matrix + 8);
        uint32 e = (uint32)(sint32)r_s16(matrix + 12);
        uint32 f = (uint32)(sint32)r_s16(matrix + 14);
        w_u16(matrix + 12, ob_batch5_rotate_pair(e, f, cosine, 0 - sine));
        w_u16(matrix, ob_batch5_rotate_pair(a, b, cosine, 0 - sine));
        w_u16(matrix + 2, ob_batch5_rotate_pair(a, b, sine, cosine));
        w_u16(matrix + 6, ob_batch5_rotate_pair(c, d, cosine, 0 - sine));
        w_u16(matrix + 8, ob_batch5_rotate_pair(c, d, sine, cosine));
        result = ob_batch5_rotate_pair(e, f, sine, cosine);
        w_u16(matrix + 14, result);
    }
    return result;
}

uint32 ob_main_80018190(uint32 kind, uint32 text, uint32 submenu, uint32 selection, uint32 height)
{
    FUNCTION_MARKER(0x80018190, "SLES_008.65");
    uint32 center = (uint32)((sint32)(256 - height) / 2);
    ob_game_800BA1C8();
    sub_80013FA4(r_u32(0x800882BC));
    sub_8002192C(0);
    sub_80020A70(0, 0, 384, 256, 80, 60, 44, 1);
    sub_8002192C(2);
    sub_80020A70(0, 0, 384, 256, 12, 20, 36, 1);
    /* TODO Bind the missing panel helper */
    ob_draft_unresolved_call(0x800176C8, 4, 87, center, 210, height);
    if (kind == 1)
    {
        ob_main_800175A8(0x80010298, center + 26, 1);
        if (!submenu)
        {
            ob_main_800175A8(0x800102AC, center + 61, selection == 0);
            ob_main_800175A8(0x800102B4, center + 72, selection == 1);
            ob_main_800175A8(0x800102C0, center + 83, selection == 2);
        }
        else if (submenu == 2)
        {
            ob_main_800175A8(0x800102C8, center + 61, 1);
            ob_main_800175A8(0x800102D0, center + 83, selection == 13);
            ob_main_800175A8(0x800102DC, center + 83, selection == 14);
        }
    }
    else if (kind == 5)
    {
        ob_main_800175A8(0x800102E8, center + 26, 1);
        uint32 name = ob_draft_scratch_acquire(16);
        for (uint32 index = 0; index < 10; ++index)
        {
            ob_draft_unresolved_call(0x80064028, 3, name, 0x80010300, index + 1);
            uint32 style = r_s8(0x8006C247) == (sint32)index ? 2 : index == selection - 3;
            ob_main_800175A8(name, center + 52 + index * 10, style);
        }
        ob_draft_scratch_release(name);
    }
    if (kind == 7 && text) ob_main_800175A8(text, 124, 1);
    sub_8004C944(r_u32(0x800882BC));
    uint32 primitive = r_u32(0x800773D0) ? 0x8008C6C8 : 0x8008CF70;
    return ob_draft_unresolved_call(0x8005B994, 2, r_u32(0x8007737C) + 112, primitive);
}

uint32 ob_game_800A1D74(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800A1D74, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    uint32 animation = r_u32(data);
    uint32 frame;
    for (;;)
    {
        frame = (uint32)((sint32)(time - r_u32(animation + 40)) / 40);
        sint32 narrow = (sint16)frame;
        if (r_s16(data + 34) < narrow)
        {
            uint32 index = (uint32)(sint32)r_s16(data + 32);
            uint32 table = r_u32(data + 4);
            uint32 callback = r_u32(table + index * 24 + 8);
            ob_draft_unresolved_call(callback, 2, object, time);
            if (r_s16(data + 34) < narrow) w_u16(data + 34, 255);
        }
        if ((sint16)frame < r_s16(animation + 44)) break;
        uint32 index = (uint32)(sint32)r_s16(data + 32);
        uint32 table = r_u32(data + 4);
        uint32 callback = r_u32(table + index * 24 + 12);
        ob_draft_unresolved_call(callback, 2, object, time);
        sint32 frames = r_s16(animation + 44);
        uint32 start = r_u32(animation + 40) + (uint32)frames * 40;
        ob_game_800ADDA8(animation, (uint32)frames, time);
        uint32 first = r_u8(data + 78);
        uint32 second = r_u8(data + 79);
        sint32 elapsed = (sint32)(time - start);
        if (first == second)
        {
            sint32 divisor = r_s16(animation + 44);
            if (!divisor) return ob_native_missing_value(0x800A1D74, "BREAK 7 signed remainder by zero");
            if (divisor == -1 && elapsed == (sint32)0x80000000)
                return ob_native_missing_value(0x800A1D74, "BREAK 6 signed remainder overflow");
            sint32 remainder = elapsed % divisor;
            w_u32(animation + 60, 0);
            w_u32(animation + 56, 0);
            w_u32(animation + 52, 0);
            w_u32(animation + 40, time - (uint32)remainder);
        }
        else
        {
            ob_game_800ADD1C(animation);
            uint32 selected = ob_game_800A1C68(object) & 0xFF;
            w_u16(data + 32, selected);
            table = r_u32(data + 4);
            ob_game_800ADC1C(animation, r_u32(table + selected * 24), start);
        }
        uint32 elapsed_now = time - r_u32(animation + 40);
        index = (uint32)(sint32)r_s16(data + 32);
        table = r_u32(data + 4);
        uint32 marker = r_u16(table + index * 24 + 20);
        index = (uint32)(sint32)r_s16(data + 32);
        w_u16(data + 34, marker);
        table = r_u32(data + 4);
        callback = r_u32(table + index * 24 + 4);
        frame = (uint32)((sint32)elapsed_now / 40);
        ob_draft_unresolved_call(callback, 2, object, time);
        if ((sint16)frame < r_s16(animation + 44)) break;
    }
    uint32 result = ob_game_800A2C80(data);
    if (result)
    {
        ob_game_800ADD44(animation, (uint32)(sint32)(sint16)frame, time);
        result = ob_game_800A200C(object, time);
    }
    return result;
}


uint32 ob_game_8009F090(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x8009F090, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    uint32 flags = r_u32(record + 28);
    if (flags & 0x10804400)
    {
        uint32 source = r_u32(record + 52);
        if (r_s16(source + 134) == 9)
        {
            uint32 slot = (uint32)(sint32)r_s16(object + 326);
            if (r_u16(0x800CBA46 + slot * 104))
            {
                uint32 data = r_u32(object + 108);
                uint32 heading = r_u16(r_u32(data) + 26);
                sub_80045A7C(r_u32(source + 44), time);
                sint32 half = r_s16(source + 138) / 2;
                sint32 angle = (sint16)(r_u16(source + 146) - (heading - 0x8000));
                if (angle < 0) angle = -angle;
                uint32 rate = (uint32)half;
                if (angle > 4096) rate = (uint32)(half < 0 ? half + 3 : half) >> 2;
                ob_main_80011A24(0x8006913C, 255, 256, r_u32(object + 44), time, 0);
                sint32 narrow = (sint16)rate;
                if (narrow >= 0)
                {
                    w_u32(0x800C835C, r_u32(0x800C835C) - ((uint32)narrow << 6));
                    if (ob_game_800A52C4(object, (uint32)narrow, 0xFFFFFFFF))
                    {
                        uint32 locals = ob_draft_scratch_acquire(32);
                        uint32 x = r_u32(0x8008D9B0);
                        uint32 y = r_u32(0x8008D9B4);
                        uint32 z = r_u32(0x8008D9B8);
                        w_u32(locals, x);
                        w_u32(locals + 4, y);
                        w_u32(locals + 8, z);
                        x = r_u32(0x8008D9BC);
                        y = r_u32(0x8008D9C0);
                        z = r_u32(0x8008D9C4);
                        w_u32(locals + 16, x);
                        w_u32(locals + 20, y);
                        w_u32(locals + 24, z);
                        sub_8001195C((uint32)(sint32)r_s16(object + 306));
                        slot = (uint32)(sint32)r_s16(object + 326);
                        w_u32(object + 288, 3);
                        w_u16(0x800CBA32 + slot * 104, 1);
                        ob_game_800A9E30(r_u32(data), 0, 0, 0, 1);
                        uint32 node = (uint32)sub_800437C4(r_u32(r_u32(object + 44) + 12), 65846);
                        sub_80045A7C(node, time);
                        sub_800458B4(node, locals, time);
                        sub_80045A44(node, locals + 16);
                        sub_80045F20(object + 64);
                        ob_game_800BCB90(object, 0, time + 50);
                        ob_draft_scratch_release(locals);
                    }
                }
            }
        }
    }
    else if (flags & 0x8020)
    {
        uint32 source = r_u32(record + 52);
        w_u32(object + 280, time);
        w_u16(object + 300, r_u16(source + 302));
        ob_game_800AC640(object, 2);
    }
    return (uint32)sub_80047FF0(record);
}

uint32 ob_game_800BADAC(uint32 input, uint32 time)
{
    FUNCTION_MARKER(0x800BADAC, "GAME.BIN");
    uint32 group = r_u8(input + 12);
    uint32 node = r_u32(r_u32(0x8007719C) + group * 4);
    uint32 head;
    do
    {
        uint32 object = r_u32(node + 80);
        if (object)
        {
            uint32 kind = r_u32(object + 292);
            if (kind == 48 || kind == 58) ob_game_800A8CE0(object, time);
            else if (kind >= 50 && kind <= 72 && !(kind & 1)) ob_game_800A8CE0(r_u32(node + 80), time);
            else if (kind == 157 || kind == 158) ob_game_80094CC0(object, time);
            else if (kind == 240) ob_game_800BC3C4(object);
            else if (kind == 33) ob_game_800A1AF8(object, time);
            else if (kind >= 20 && kind < 32) ob_game_800AB4E4(object, time);
            else if (kind == 11) ob_game_800BCAA0(object);
        }
        else
        {
            for (uint32 index = 0; index < 400; ++index)
            {
                uint32 identifier = r_u16(0x800CBA44 + index * 104);
                if (identifier == r_u16(node + 68))
                {
                    uint32 kind = r_u32(node + 44);
                    if (kind >= 48 && kind <= 72 && !(kind & 1))
                        w_u32(node + 44, r_u32(node + 44) + 1);
                    else ob_game_800A0B6C(index);
                }
            }
        }
        uint32 table = r_u32(0x8007719C);
        node = r_u32(node + 72);
        head = r_u32(table + group * 4);
    } while (node != head);
    return head;
}

uint32 ob_game_800BB07C(uint32 input, uint32 time)
{
    FUNCTION_MARKER(0x800BB07C, "GAME.BIN");
    uint32 group = r_u8(input + 12);
    uint32 node = r_u32(r_u32(0x8007719C) + group * 4);
    uint32 marker = 0;
    uint32 marker_known = 0;
    uint32 head;
    do
    {
        uint32 kind = r_u32(node + 96);
        if (kind == 149 || kind == 153) ob_game_800BB9E8(input, node, time);
        else if (kind == 235)
        {
            uint32 object = r_u32(node + 80);
            if (object)
            {
                w_u32(r_u32(object + 108), 1);
                ob_game_800BB630(r_u32(node + 80), 0, time);
            }
            ob_draft_unresolved_call(0x8001A4A0, 2, r_u32(node + 32), r_u32(node + 40));
            marker = r_u16(node + 52);
            marker_known = 1;
            w_u32(node + 100, 17);
            w_u16(node + 50, 1);
        }
        uint32 table = r_u32(0x8007719C);
        node = r_u32(node + 72);
        head = r_u32(table + group * 4);
    } while (node != head);
    uint32 count = r_u16(r_u32(0x80077190));
    if (!count) return count;
    uint32 index = 0;
    uint32 offset = 0;
    do
    {
        uint32 record = r_u32(0x80077194) + offset;
        if (r_u16(record + 22) == group)
        {
            uint32 kind = r_u32(record + 12);
            if (kind >= 229 && kind < 231)
            {
                /* TODO Original s5 has no defined marker unless a type235 entry was visited */
                if (!marker_known) return ob_native_missing_value(0x800BB07C, "TODO Marker requires a type235 entry in the input group");
                w_u16(record + 20, marker);
                uint32 mode = r_u8(0x8006C22C);
                if ((mode != 0 || (r_u8(record + 24) & 1))
                    && (mode != 1 || (r_u8(record + 24) & 2))
                    && (mode != 2 || (r_u8(record + 24) & 4)))
                {
                    uint32 metadata = r_u32(0x80077190);
                    uint32 limit = r_u8(record + 25);
                    uint32 level = r_u8(metadata + 42);
                    if (level < limit)
                    {
                        sint32 slot = (sint16)ob_game_800A50BC(record);
                        uint32 base = r_u32(0x80077194);
                        record = base + offset;
                        uint32 record_group = r_u16(record + 22);
                        uint32 table = r_u32(0x8007719C);
                        head = r_u32(table + record_group * 4);
                        uint32 entry = 0x800CBA00 + (uint32)slot * 104;
                        if (!head)
                        {
                            w_u32(entry + 72, entry);
                            record_group = r_u16(record + 22);
                            w_u32(table + record_group * 4, entry);
                        }
                        else
                        {
                            uint32 last = head;
                            while (r_u32(last + 72) != head) last = r_u32(last + 72);
                            base = r_u32(0x80077194);
                            w_u32(last + 72, entry);
                            record_group = r_u16(base + offset + 22);
                            table = r_u32(0x8007719C);
                            w_u32(entry + 72, r_u32(table + record_group * 4));
                        }
                        w_u16(0x800CBA58 + (uint32)slot * 104, index);
                    }
                }
            }
        }
        count = r_u16(r_u32(0x80077190));
        ++index;
        offset += 28;
    } while (index < count);
    return 0;
}

uint32 ob_main_8002EF88(uint32 first, uint32 second, uint32 output)
{
    FUNCTION_MARKER(0x8002EF88, "SLES_008.65");
    uint32 a[9];
    uint32 b[9];
    a[0] = (uint32)(sint32)r_s16(first);
    b[0] = (uint32)(sint32)r_s16(second);
    a[1] = (uint32)(sint32)r_s16(first + 2);
    b[3] = (uint32)(sint32)r_s16(second + 6);
    a[2] = (uint32)(sint32)r_s16(first + 4);
    b[6] = (uint32)(sint32)r_s16(second + 12);
    b[1] = (uint32)(sint32)r_s16(second + 2);
    b[4] = (uint32)(sint32)r_s16(second + 8);
    b[7] = (uint32)(sint32)r_s16(second + 14);
    b[2] = (uint32)(sint32)r_s16(second + 4);
    b[5] = (uint32)(sint32)r_s16(second + 10);
    b[8] = (uint32)(sint32)r_s16(second + 16);
    a[3] = (uint32)(sint32)r_s16(first + 6);
    a[4] = (uint32)(sint32)r_s16(first + 8);
    a[5] = (uint32)(sint32)r_s16(first + 10);
    a[6] = (uint32)(sint32)r_s16(first + 12);
    a[7] = (uint32)(sint32)r_s16(first + 14);
    a[8] = (uint32)(sint32)r_s16(first + 16);
    uint32 result[9];
    for (uint32 row = 0; row < 3; ++row)
        for (uint32 column = 0; column < 3; ++column)
            result[row * 3 + column] = (a[row * 3] * b[column] + a[row * 3 + 1] * b[3 + column] + a[row * 3 + 2] * b[6 + column]) >> 14;
    w_u16(output, result[0]);
    w_u16(output + 6, result[3]);
    w_u16(output + 12, result[6]);
    w_u16(output + 2, result[1]);
    w_u16(output + 8, result[4]);
    w_u16(output + 14, result[7]);
    w_u16(output + 4, result[2]);
    w_u16(output + 10, result[5]);
    w_u16(output + 16, result[8]);
    return result[6];
}


uint32 ob_main_8004492C(uint32 object, uint32 chain, uint32 draw, uint32 flags, uint32 options)
{
    FUNCTION_MARKER(0x8004492C, "SLES_008.65");
    options &= 0xFFFF;
    if (r_u32(object + 28) || r_u32(object + 32))
    {
        uint32 node = r_u32(object + 48);
        if (node)
        {
            sub_800454BC(node);
            uint32 position = sub_80045464(r_u32(object + 48), r_u32(0x80077448));
            node = r_u32(object + 48);
            uint32 plane = ob_main_80032058(position, node + 66);
            uint32 child_offset;
            if (r_u32(object + 28))
            {
                if (r_u32(object + 32))
                {
                    uint32 vector = ob_draft_scratch_acquire(16);
                    uint32 value = r_u32(position);
                    uint32 camera = r_u32(0x800843D8);
                    w_u32(vector, value - camera);
                    value = r_u32(position + 4);
                    camera = r_u32(0x800843DC);
                    w_u32(vector + 4, value - camera);
                    value = r_u32(position + 8);
                    camera = r_u32(0x800843E0);
                    w_u32(vector + 8, value - camera);
                    ob_main_80029384(vector, vector);
                    uint32 x = (uint32)(sint32)r_s16(node + 66);
                    uint32 vx = r_u32(vector);
                    uint32 y = (uint32)(sint32)r_s16(node + 68);
                    uint32 vy = r_u32(vector + 4);
                    uint32 z = (uint32)(sint32)r_s16(node + 70);
                    uint32 vz = r_u32(vector + 8);
                    uint32 dot = x * vx + y * vy + z * vz;
                    ob_draft_scratch_release(vector);
                    uint32 first = (sint32)dot < 0 ? 0 : 1;
                    uint32 token = ob_main_800320F8(plane, first);
                    ob_main_8004492C(r_u32(object + 28 + first * 4), chain, draw, flags & 0xFFFF, options);
                    ob_main_80032148((uint32)(sint32)(sint16)token);
                    child_offset = first ? 28 : 32;
                    token = ob_main_800320F8(plane, first ^ 1);
                    ob_main_8004492C(r_u32(object + child_offset), chain, draw, flags & 0xFFFF, options);
                    return ob_main_80032148((uint32)(sint32)(sint16)token);
                }
                child_offset = 28;
            }
            else child_offset = 32;
            uint32 token = ob_main_800320F8(plane, child_offset == 32);
            ob_main_8004492C(r_u32(object + child_offset), chain, draw, flags & 0xFFFF, options);
            return ob_main_80032148((uint32)(sint32)(sint16)token);
        }
        if (r_u32(object + 32)) ob_main_8004492C(r_u32(object + 32), chain, draw, flags & 0xFFFF, options);
        uint32 child = r_u32(object + 28);
        if (child) return ob_main_8004492C(r_u32(object + 28), chain, draw, flags & 0xFFFF, options);
        return child;
    }
    flags |= r_u16(object + 52);
    if (chain) return ob_main_8004492C(chain, r_u32(chain + 40), draw, flags & 0xFFFF, options);
    return sub_8004434C(draw, flags & 0xFFFF, options);
}

uint32 ob_main_8001D818(uint32 input)
{
    FUNCTION_MARKER(0x8001D818, "SLES_008.65");
    if (!r_s8(input + 33))
    {
        for (uint32 offset = 0; offset < 368; offset += 16)
        {
            uint32 a = r_u32(input + offset);
            uint32 b = r_u32(input + offset + 4);
            uint32 c = r_u32(input + offset + 8);
            uint32 d = r_u32(input + offset + 12);
            w_u32(0x800899A8 + offset, a);
            w_u32(0x800899AC + offset, b);
            w_u32(0x800899B0 + offset, c);
            w_u32(0x800899B4 + offset, d);
        }
        uint32 a = r_u32(input + 368);
        uint32 b = r_u32(input + 372);
        w_u32(0x80089B18, a);
        w_u32(0x80089B1C, b);
        for (uint32 index = 0; index < 4; ++index) w_u8(0x8006C22C + index, r_u8(input + 34 + index));
        for (uint32 table = 0; table < 5; ++table)
            for (uint32 index = 0; index < 13; ++index)
            {
                uint32 value = r_u32(input + 80 + table * 52 + index * 4);
                uint32 destination = r_u32(0x80065CB0 + table * 4);
                w_u32(destination + index * 4, value);
            }
        for (uint32 index = 0; index < 13; ++index) w_u8(0x8006C254 + index, r_u8(input + 340 + index));
        for (uint32 index = 0; index < 5; ++index) w_u16(0x8006C24A + index * 2, r_u16(input + 354 + index * 2));
        w_u8(0x8006C246, r_u8(input + 364));
        w_u8(0x8006C248, r_u8(input + 365));
        w_u8(0x8006C240, r_u8(input + 366));
        w_u8(0x8006C249, r_u8(input + 367));
        uint32 result = r_u8(input + 368);
        w_u8(0x8006C247, result);
        return result;
    }
    for (uint32 index = 0; index < 13; ++index)
    {
        w_u8(0x800899CE + index, r_u8(input + 38 + index));
        w_u8(0x800899DB + index, r_u8(input + 51 + index));
    }
    for (uint32 index = 0; index < 5; ++index) w_u16(0x800899E8 + index * 2, r_u16(input + 64 + index * 2));
    w_u8(0x800899F2, r_u8(input + 74));
    w_u16(0x800899F6, r_u16(input + 78));
    uint32 mode = r_u8(input + 33);
    w_u8(0x8006C230, 1);
    w_u8(0x8006C231, mode);
    for (uint32 table = 0; table < 5; ++table)
        for (uint32 index = 0; index < 13; ++index)
        {
            uint32 source = r_u32(0x80065CB0 + table * 4);
            w_u32(0x800899F8 + table * 52 + index * 4, r_u32(source + index * 4));
        }
    return 0;
}

uint32 ob_game_800963B4(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x800963B4, "GAME.BIN");
    uint32 flags = r_u32(record + 28);
    uint32 source = r_u32(record + 52);
    if (!(flags & 0x400180A0)) return (uint32)sub_80047FF0(record);
    uint32 kind = r_u32(object + 292);
    uint32 special = kind == 13;
    if (!special)
    {
        uint32 parent = r_u32(object + 132);
        if (parent) special = r_u32(parent + 292) == 174;
    }
    if (special)
    {
        if (flags & 0x20)
        {
            uint32 damage = r_u8(r_u32(source + 108) + 46) == 3 ? 3 : 24;
            if (ob_game_800A52C4(source, damage, 0xFFFFFFFF)) ob_game_800B3210(source, time);
        }
        else if (flags & 0x80)
        {
            if (ob_game_800A52C4(source, 24, 0xFFFFFFFF)) ob_game_800AFE94(source, time);
        }
        else if (flags & 0x8000)
        {
            if (ob_game_800A52C4(source, 24, 0xFFFFFFFF)) ob_game_800AB4E4(source, time);
        }
        if (r_u32(object + 292) == 13) ob_main_80011A24(0x8006860C, 128, 256, r_u32(object + 44), time, 0);
    }
    sub_80047FF0(record);
    if (r_u32(object + 292) == 255) return 255;
    uint32 locals = ob_draft_scratch_acquire(32);
    sub_80045A7C(r_u32(object + 44), time);
    ob_main_80045410(r_u32(object + 44), locals);
    sub_80045A7C(r_u32(source + 44), time);
    ob_main_80045410(r_u32(source + 44), locals + 16);
    /* Original reads record normals after releasing the collision record */
    if (!r_u32(locals) && r_s16(record + 16)) w_u32(locals + 16, 0 - r_u32(locals + 16));
    else if (!r_u32(locals + 8) && r_s16(record + 20)) w_u32(locals + 24, 0 - r_u32(locals + 24));
    else
    {
        uint32 z = r_u32(locals + 8);
        uint32 x = r_u32(locals);
        w_u32(locals + 24, z << 2);
        w_u32(locals + 16, x << 2);
    }
    uint32 first = sub_80045464(r_u32(object + 44), time);
    uint32 second = sub_80045464(r_u32(source + 44), time);
    sint32 first_x = r_s32(first);
    sint32 second_x = r_s32(second);
    if (second_x < first_x && r_s32(locals + 16) > 0) w_u32(locals + 16, 0);
    first_x = r_s32(first);
    second_x = r_s32(second);
    if (first_x < second_x && r_s32(locals + 16) < 0) w_u32(locals + 16, 0);
    sint32 first_z = r_s32(first + 8);
    sint32 second_z = r_s32(second + 8);
    if (second_z < first_z && r_s32(locals + 24) > 0) w_u32(locals + 24, 0);
    first_z = r_s32(first + 8);
    second_z = r_s32(second + 8);
    if (first_z < second_z && r_s32(locals + 24) < 0) w_u32(locals + 24, 0);
    sub_80045A44(r_u32(source + 44), locals + 16);
    uint32 data = r_u32(source + 124);
    w_u32(data, (uint32)(r_s32(data) / 2));
    w_u32(r_u32(source + 124) + 8, time + 50);
    w_u32(object + 280, time);
    uint32 result = r_u16(source + 302);
    w_u16(object + 300, result);
    ob_draft_scratch_release(locals);
    return result;
}


static uint32 ob_batch5_vlc_math(uint32 first, uint32 second, uint32 subtract)
{
    sint64 value = (sint64)(sint32)first;
    if (subtract) value -= (sint64)(sint32)second;
    else value += (sint64)(sint32)second;
    if (value < INT32_MIN || value > INT32_MAX)
        return ob_native_missing_value(0x8008E530, "Signed MIPS ADD/SUB overflow");
    return (uint32)(sint32)value;
}

static void ob_batch5_vlc_refill(uint32 *input, uint32 *bits, uint32 *count)
{
    uint32 refill = *count & 0x10;
    *count &= 0xF;
    if (refill)
    {
        uint32 word = r_u16(*input);
        *input = ob_batch5_vlc_math(*input, 2, 0);
        *bits |= word << (*count & 31);
    }
}

uint32 ob_movie_8008E530(uint32 input, uint32 output)
{
    FUNCTION_MARKER(0x8008E530, "MOVIE.BIN");
    uint32 quota = r_u32(0x8008E4FC);
    uint32 bits;
    uint32 count;
    uint32 quantizer;
    uint32 mode;
    uint32 first_dc;
    uint32 second_dc;
    uint32 third_dc;
    uint32 limit;
    uint32 top;
    uint32 table;
    uint32 code;
    uint32 extra;
    uint32 value;
    if (input)
    {
        mode = 0;
        first_dc = 0;
        second_dc = 0;
        third_dc = 0;
        quota = ob_batch5_vlc_math(quota, quota, 0);
        limit = ob_batch5_vlc_math(output, quota, 0);
        uint32 header = r_u16(input);
        uint32 second_header = r_u16(input + 2);
        quantizer = r_u16(input + 4);
        uint32 version = r_u16(input + 6);
        bits = r_u16(input + 8);
        uint32 tail = r_u16(input + 10);
        version = ob_batch5_vlc_math(version, 3, 1);
        quantizer <<= 10;
        if ((sint32)version >= 0) mode = 1;
        input = ob_batch5_vlc_math(input, 12, 0);
        bits = (bits << 16) | tail;
        count = 0;
        w_u16(output, header);
        w_u16(output + 2, second_header);
        output = ob_batch5_vlc_math(output, 2, 0);
        goto dc;
    }
    input = r_u32(0x8008E870);
    output = r_u32(0x8008E874);
    bits = r_u32(0x8008E878);
    count = r_u32(0x8008E87C);
    quantizer = r_u32(0x8008E880);
    mode = r_u32(0x8008E884);
    first_dc = r_u32(0x8008E888);
    second_dc = r_u32(0x8008E88C);
    third_dc = r_u32(0x8008E890);
    quota = ob_batch5_vlc_math(quota, quota, 0);
    limit = ob_batch5_vlc_math(output, quota, 0);
    goto ac;

dc:
    top = bits >> 22;
    output = ob_batch5_vlc_math(output, 2, 0);
    if (mode)
    {
        if (top == 0x3FF) goto terminal;
        uint32 relative = ob_batch5_vlc_math(mode, 3, 1);
        table = ob_batch5_vlc_math(0x8008F1E0, 0x400, 1);
        if ((sint32)relative >= 0) table = ob_batch5_vlc_math(table, 0x400, 1);
        table = ob_batch5_vlc_math(table, (bits >> 24) << 2, 0);
        uint32 prefix = r_u16(table);
        uint32 length = r_u16(table + 2);
        uint32 delta = 0;
        bits <<= prefix & 31;
        if (length)
        {
            uint32 shift = ob_batch5_vlc_math(32, length, 1);
            delta = bits >> (shift & 31);
            uint32 negative = bits & 0x80000000;
            bits <<= length & 31;
            if (!negative) delta = ob_batch5_vlc_math(delta, 0xFFFFFFFF >> (shift & 31), 1);
            count = ob_batch5_vlc_math(count, length, 0);
        }
        count = ob_batch5_vlc_math(count, prefix, 0);
        ob_batch5_vlc_refill(&input, &bits, &count);
        relative = ob_batch5_vlc_math(mode, 2, 1);
        uint32 coefficient = ob_batch5_vlc_math(third_dc, delta, 0);
        if ((sint32)relative > 0) third_dc = ob_batch5_vlc_math(third_dc, delta, 0);
        else
        {
            coefficient = ob_batch5_vlc_math(second_dc, delta, 0);
            if (!relative) second_dc = ob_batch5_vlc_math(second_dc, delta, 0);
            else
            {
                coefficient = ob_batch5_vlc_math(first_dc, delta, 0);
                first_dc = ob_batch5_vlc_math(first_dc, delta, 0);
            }
        }
        value = quantizer | ((coefficient << 2) & 0x3FF);
        mode = ob_batch5_vlc_math(mode, 1, 0);
        relative = ob_batch5_vlc_math(mode, 7, 1);
        w_u16(output, value);
        if (!relative) mode = ob_batch5_vlc_math(mode, 6, 1);
    }
    else
    {
        if (top == 0x1FF) goto terminal;
        bits <<= 10;
        count = ob_batch5_vlc_math(count, 10, 0);
        ob_batch5_vlc_refill(&input, &bits, &count);
        w_u16(output, quantizer | top);
    }
    value = output - limit;
    output = ob_batch5_vlc_math(output, 2, 0);
    if ((sint32)value >= 0)
    {
        w_u32(0x8008E870, input);
        w_u32(0x8008E874, output);
        w_u32(0x8008E878, bits);
        w_u32(0x8008E87C, count);
        w_u32(0x8008E880, quantizer);
        w_u32(0x8008E884, mode);
        w_u32(0x8008E888, first_dc);
        w_u32(0x8008E88C, second_dc);
        w_u32(0x8008E890, third_dc);
        return 1;
    }

ac:
    table = ob_batch5_vlc_math(0x8008F1E0, (bits >> 19) << 3, 0);
    code = r_u32(table);
    if (code) extra = r_u32(table + 4);
    else
    {
        bits <<= 8;
        count = ob_batch5_vlc_math(count, 8, 0);
        ob_batch5_vlc_refill(&input, &bits, &count);
        table = ob_batch5_vlc_math(0x8009F1E0, (bits >> 23) << 2, 0);
        code = r_u32(table);
        extra = 0;
    }
    value = code & 0xFF;
    bits <<= value & 31;
    count = ob_batch5_vlc_math(count, value, 0);
    ob_batch5_vlc_refill(&input, &bits, &count);
    value = code >> 16;
    if (value == 0x7C1F) goto escape;
    w_u16(output, value);
    if (value == 0xFE00) goto dc;
    output = ob_batch5_vlc_math(output, 2, 0);
    if (!extra) goto ac;
    value = extra & 0xFFFF;
    if (value == 0x7C1F) goto escape;
    w_u16(output, value);
    if (value == 0xFE00) goto dc;
    value = extra >> 16;
    output = ob_batch5_vlc_math(output, 2, 0);
    if (!value) goto ac;
    if (value == 0x7C1F) goto escape;
    w_u16(output, value);
    if (value == 0xFE00) goto dc;
    output = ob_batch5_vlc_math(output, 2, 0);
    goto ac;

escape:
    w_u16(output, bits >> 16);
    output = ob_batch5_vlc_math(output, 2, 0);
    value = r_u16(input);
    input = ob_batch5_vlc_math(input, 2, 0);
    bits = (bits << 16) | (value << (count & 31));
    goto ac;

terminal:
    value = 64;
    do
    {
        w_u16(output, 0xFE00);
        output = ob_batch5_vlc_math(output, 2, 0);
        uint32 previous = value;
        value = ob_batch5_vlc_math(value, 1, 1);
        if (!previous) break;
    } while (1);
    /* TODO Bind the SDK cache-control boundary for CP0 SR bit0x20000 */
    ob_native_missing_value(0x8008E530, "TODO Missing CP0 SR cache-control adapter");
    return 0;
}


uint32 ob_game_800B372C(uint32 object, uint32 target, uint32 time)
{
    FUNCTION_MARKER(0x800B372C, "GAME.BIN");
    if (r_u32(object + 292) == 171)
    {
        sub_80045A7C(r_u32(object + 44), time);
        sub_80045A44(r_u32(object + 44), 0x8006C160);
        sub_80045A7C(r_u32(object + 44), time);
        uint32 resource = r_u32(object + 112);
        uint32 attributes = r_u32(object + 120);
        ob_game_800B5BD8(0, attributes, r_u8(resource + 40), time);
        uint32 result = ob_game_800B5C50(0, r_u32(object + 120), time);
        if (result) result = ob_game_800B5CB4(object, 0, 0, time);
        return result;
    }
    uint32 data = r_u32(object + 108);
    uint32 kind = r_u32(data + 4);
    uint32 target_data = r_u32(target + 108);
    if (kind >= 26) return 20;
    if (kind != 20 && kind != 22)
    {
        sub_80011984(0x800660AC, 128, 15, 15, 256, 2, 0);
        kind = r_u32(data + 4);
    }
    if (kind >= 26) return 0;
    if (kind < 8) return ob_game_800B4068(target, kind);
    if (kind < 13) return ob_game_800B4164(target_data, kind - 8);
    switch (kind)
    {
    case 13: return ob_game_800B3EF0(target, 2, time);
    case 14: return ob_game_800B3EF0(target, 1, time);
    case 15: return ob_game_800B3EF0(target, 3, time);
    case 16: return ob_game_800A52C4(target, (uint32)-63, 0xFFFFFFFF);
    case 17:
        ob_game_800A52C4(target, (uint32)-15, 0xFFFFFFFF);
        return sub_80011984(0x800660C0, 128, 15, 15, 256, 0, 0);
    case 18:
    {
        uint32 result = r_u16(target_data + 32) + 1;
        w_u16(target_data + 32, result);
        return result;
    }
    case 21:
        w_u8(target_data + 44, r_u8(target_data + 44) + 1);
        return sub_80011984(0x800660B0, 128, 15, 15, 256, 2, 0);
    case 22:
    {
        uint32 slot = (uint32)(sint32)r_s16(object + 326);
        w_u8(target_data + 178, r_u16(0x800CBA36 + slot * 104));
        return sub_80011984(0x800660B4, 128, 15, 15, 256, 0, 0);
    }
    case 23: return ob_game_800B3EF0(target, 4, time);
    default: return 0x800B3A6C;
    }
}

static uint32 ob_batch5_round_product14(uint32 first, uint32 second)
{
    uint32 product = first * second;
    uint32 adjustment = (sint32)(first ^ second) < 0 ? 0 - 8192 : 8192;
    return (product + adjustment) >> 14;
}

uint32 ob_main_8002F5FC(uint32 matrix, uint32 angles)
{
    FUNCTION_MARKER(0x8002F5FC, "SLES_008.65");
    uint32 angle = r_u16(angles);
    if ((sint16)angle)
    {
        uint32 value = r_u16(0x8006CB04 + ((angle + 8) >> 4) * 2);
        w_u16(matrix + 2, 0);
        w_u16(matrix, value);
        uint32 index = ((r_u16(angles) + 8) >> 4) * 2;
        value = r_u16(0x8006C304 + index);
        w_u16(matrix + 6, 0);
        w_u16(matrix + 8, 0x4000);
        w_u16(matrix + 10, 0);
        w_u16(matrix + 4, 0 - value);
        index = ((r_u16(angles) + 8) >> 4) * 2;
        value = r_u16(0x8006C304 + index);
        w_u16(matrix + 14, 0);
        w_u16(matrix + 12, value);
        index = ((r_u16(angles) + 8) >> 4) * 2;
        w_u16(matrix + 16, r_u16(0x8006CB04 + index));
    }
    else
    {
        w_u16(matrix, 0x4000);
        w_u16(matrix + 2, 0);
        w_u16(matrix + 4, 0);
        w_u16(matrix + 6, 0);
        w_u16(matrix + 8, 0x4000);
        w_u16(matrix + 10, 0);
        w_u16(matrix + 12, 0);
        w_u16(matrix + 14, 0);
        w_u16(matrix + 16, 0x4000);
    }
    angle = r_u16(angles + 2);
    if ((sint16)angle)
    {
        uint32 index = ((angle + 8) >> 4) * 2;
        uint32 a = (uint32)(sint32)r_s16(matrix + 12);
        uint32 sine = (uint32)(sint32)r_s16(0x8006C304 + index);
        uint32 first = ob_batch5_round_product14(a, sine);
        index = ((r_u16(angles + 2) + 8) >> 4) * 2;
        uint32 b = (uint32)(sint32)r_s16(matrix + 16);
        sine = (uint32)(sint32)r_s16(0x8006C304 + index);
        uint32 cosine_word = r_u16(0x8006CB04 + index);
        uint32 second = ob_batch5_round_product14(b, sine);
        index = ((r_u16(angles + 2) + 8) >> 4) * 2;
        a = (uint32)(sint32)r_s16(matrix + 12);
        uint32 cosine = (uint32)(sint32)r_s16(0x8006CB04 + index);
        uint32 third = ob_batch5_round_product14(a, cosine);
        index = ((r_u16(angles + 2) + 8) >> 4) * 2;
        b = (uint32)(sint32)r_s16(matrix + 16);
        cosine = (uint32)(sint32)r_s16(0x8006CB04 + index);
        uint32 sine_word = r_u16(0x8006C304 + index);
        uint32 fourth = ob_batch5_round_product14(b, cosine);
        w_u16(matrix + 6, first);
        w_u16(matrix + 8, cosine_word);
        w_u16(matrix + 10, second);
        w_u16(matrix + 12, third);
        w_u16(matrix + 14, 0 - sine_word);
        w_u16(matrix + 16, fourth);
    }
    angle = r_u16(angles + 4);
    if (!(sint16)angle) return 0;
    uint32 index = ((angle + 8) >> 4) * 2;
    uint32 a = (uint32)(sint32)r_s16(matrix);
    uint32 cosine = (uint32)(sint32)r_s16(0x8006CB04 + index);
    uint32 b = (uint32)(sint32)r_s16(matrix + 6);
    uint32 sine = (uint32)(sint32)r_s16(0x8006C304 + index);
    uint32 center = (uint32)(sint32)r_s16(matrix + 8);
    uint32 first = ob_batch5_rotate_pair(a, b, cosine, sine);
    uint32 second = ob_batch5_round_product14(center, sine);
    index = ((r_u16(angles + 4) + 8) >> 4) * 2;
    uint32 c = (uint32)(sint32)r_s16(matrix + 4);
    cosine = (uint32)(sint32)r_s16(0x8006CB04 + index);
    sine = (uint32)(sint32)r_s16(0x8006C304 + index);
    uint32 d = (uint32)(sint32)r_s16(matrix + 10);
    uint32 third = ob_batch5_rotate_pair(c, d, cosine, sine);
    a = (uint32)(sint32)r_s16(matrix);
    b = (uint32)(sint32)r_s16(matrix + 6);
    uint32 fourth = ob_batch5_rotate_pair(a, b, 0 - sine, cosine);
    center = (uint32)(sint32)r_s16(matrix + 8);
    uint32 fifth = ob_batch5_round_product14(center, cosine);
    index = ((r_u16(angles + 4) + 8) >> 4) * 2;
    sine = (uint32)(sint32)r_s16(0x8006C304 + index);
    c = (uint32)(sint32)r_s16(matrix + 4);
    cosine = (uint32)(sint32)r_s16(0x8006CB04 + index);
    d = (uint32)(sint32)r_s16(matrix + 10);
    uint32 result = c * (0 - sine) + d * cosine;
    w_u16(matrix, first);
    w_u16(matrix + 2, second);
    w_u16(matrix + 4, third);
    w_u16(matrix + 6, fourth);
    w_u16(matrix + 8, fifth);
    w_u16(matrix + 10, result >> 14);
    return result;
}

uint32 ob_game_8009E3B0(uint32 object, uint32 reference, uint32 time)
{
    FUNCTION_MARKER(0x8009E3B0, "GAME.BIN");
    uint32 locals = ob_draft_scratch_acquire(104);
    uint32 launch = locals;
    uint32 rotated = locals + 16;
    uint32 velocity = locals + 32;
    uint32 matrix = locals + 48;
    uint32 attributes = locals + 72;
    ob_game_800B979C(r_u32(object + 44), (uint32)(sint32)r_s16(r_u32(object + 48) + 160), 6, time);
    ob_main_80011A24(0x800666C4, 128, 320, r_u32(object + 44), time, 0);
    uint32 slot = (uint32)(sint32)r_s16(object + 326);
    ob_game_800C1030(attributes, 0x800CBA20 + slot * 104, 28);
    for (uint32 index = 0; index < 2; ++index)
    {
        sub_80045378(r_u32(object + 44), time, attributes);
        ob_main_80045410(r_u32(object + 44), velocity);
        uint32 size = (uint32)(sint32)r_s16(r_u32(object + 48) + 160);
        if (!index)
        {
            w_u32(attributes, r_u32(attributes) - size);
            size = (uint32)(sint32)r_s16(r_u32(object + 48) + 160);
            w_u32(attributes + 8, r_u32(attributes + 8) + size);
            uint32 random = ob_draft_unresolved_call(0x8001AFC8, 0);
            w_u32(launch, r_u32(velocity) * 2 - ((uint32)((sint32)random >> 8) + 20));
            w_u32(launch + 4, r_u32(velocity + 4));
            random = ob_draft_unresolved_call(0x8001AFC8, 0);
            w_u32(launch + 8, r_u32(velocity + 8) * 2 + (uint32)((sint32)random >> 8) + 60);
        }
        else
        {
            w_u32(attributes, r_u32(attributes) + size);
            size = (uint32)(sint32)r_s16(r_u32(object + 48) + 160);
            w_u32(attributes + 8, r_u32(attributes + 8) - size);
            uint32 random = ob_draft_unresolved_call(0x8001AFC8, 0);
            w_u32(launch, r_u32(velocity) * 2 + (uint32)((sint32)random >> 8) + 80);
            w_u32(launch + 4, r_u32(velocity + 4));
            random = ob_draft_unresolved_call(0x8001AFC8, 0);
            w_u32(launch + 8, r_u32(velocity + 8) * 2 - (uint32)((sint32)random >> 8));
        }
        uint32 angle = sub_80027F98(r_u32(launch + 8), r_u32(launch));
        w_u16(attributes + 16, angle);
        sint32 allocated_slot = (sint16)ob_game_800A50BC(attributes);
        uint32 child = ob_game_800AEEE8(time);
        w_u16(r_u32(child + 124) + 4, r_u16(attributes + 16));
        uint32 random = ob_draft_unresolved_call(0x8001AFC8, 0);
        sub_80029F58((uint32)(sint32)(sint16)random, matrix);
        sub_80029B70(launch, matrix, rotated);
        sub_80045A44(r_u32(child + 44), rotated);
        sub_80045848(r_u32(child + 44), matrix);
        sint32 half_size = r_s16(r_u32(object + 48) + 160) / 2;
        ob_game_8009E750(child, (uint32)half_size, time);
        if (reference) sub_800465E8(r_u32(child + 52), reference);
        uint32 group = r_u16(attributes + 22);
        uint32 table = r_u32(0x8007719C);
        uint32 head = r_u32(table + group * 4);
        uint32 entry = 0x800CBA00 + (uint32)allocated_slot * 104;
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
    }
    ob_draft_scratch_release(locals);
    return 0;
}

static sint32 ob_batch5_cull_extent(uint32 product)
{
    uint32 doubled = (uint32)((sint32)product >> 14) << 1;
    uint32 scaled = (uint32)(sint32)(sint16)doubled * 11585;
    scaled += ((doubled ^ 0x2D41) & 0x8000) ? 0 - 8192 : 8192;
    return (sint32)scaled >> 14;
}

static void ob_batch5_append_plane(uint32 *masks, uint32 *callbacks, uint32 mask, uint32 callback, uint32 threshold, uint32 delta)
{
    w_u32(*masks, mask);
    *masks += 4;
    w_u32(*callbacks, callback);
    uint32 count = r_u16(0x80077364);
    w_u16(threshold, delta);
    w_u16(0x80077364, count + 1);
    *callbacks += 4;
}

uint32 ob_main_8003A064(uint32 object)
{
    FUNCTION_MARKER(0x8003A064, "SLES_008.65");
    uint32 matrix = r_u32(0x80077590);
    uint32 product = (uint32)(sint32)r_s16(object + 22) * (uint32)(sint32)r_s16(matrix);
    uint32 callbacks = r_u32(0x8007736C);
    uint32 offset = r_u16(0x80077638) * 4;
    uint32 masks = r_u32(0x800775C4) + offset;
    callbacks += offset;
    sint32 x = ob_batch5_cull_extent(product);
    matrix = r_u32(0x80077590);
    product = (uint32)(sint32)r_s16(object + 22) * (uint32)(sint32)r_s16(matrix + 8);
    sint32 y = ob_batch5_cull_extent(product);
    matrix = r_u32(0x80077590);
    product = (uint32)(sint32)r_s16(object + 22) * (uint32)(sint32)r_s16(matrix + 16);
    sint32 z = ob_batch5_cull_extent(product);
    uint32 base = r_u32(0x80077500);
    uint32 other = r_u32(0x800774FC);
    w_u16(0x800773C6, 0);
    w_u16(0x800773B0, 0);
    uint32 delta = base - other;
    if (y < (sint32)delta) w_u16(0x80077524, 32760);
    else
    {
        if ((sint32)(base + (uint32)y) < (sint32)other) return 1;
        ob_batch5_append_plane(&masks, &callbacks, 4, 0x8002B970, 0x80077524, delta);
    }
    base = r_u32(0x80077500);
    other = r_u32(0x800774FC);
    delta = base + other;
    if (y < (sint32)delta) w_u16(0x8007751E, 32760);
    else
    {
        if ((sint32)other < (sint32)(0 - base - (uint32)y)) return 1;
        ob_batch5_append_plane(&masks, &callbacks, 8, 0x8002BB18, 0x8007751E, delta);
    }
    base = r_u32(0x80077500);
    other = r_u32(0x800774F8);
    delta = base - other;
    if (x < (sint32)delta) w_u16(0x80077522, 32760);
    else
    {
        if ((sint32)(base + (uint32)x) < (sint32)other) return 1;
        ob_batch5_append_plane(&masks, &callbacks, 1, 0x8002BCC4, 0x80077522, delta);
    }
    base = r_u32(0x80077500);
    other = r_u32(0x800774F8);
    delta = base + other;
    if (x < (sint32)delta) w_u16(0x8007751C, 32760);
    else
    {
        if ((sint32)other < (sint32)(0 - base - (uint32)x)) return 1;
        ob_batch5_append_plane(&masks, &callbacks, 2, 0x8002BE6C, 0x8007751C, delta);
    }
    uint32 distance = r_u32(0x800774AC);
    base = r_u32(0x80077500);
    delta = distance - base;
    if ((sint32)delta >= z) w_u16(0x8007752C, 32760);
    else
    {
        if ((sint32)(distance + (uint32)z) < (sint32)base) return 1;
        ob_batch5_append_plane(&masks, &callbacks, 16, 0x8002C018, 0x8007752C, delta);
    }
    base = r_u32(0x80077500);
    uint32 near_distance = r_u32(0x80077508);
    delta = base - near_distance;
    if ((sint32)delta >= z)
    {
        w_u16(0x80077520, 32760);
        return 0;
    }
    uint32 far_distance = r_u32(0x800773B4);
    if ((sint32)base < (sint32)(far_distance - (uint32)z)) return 1;
    w_u32(masks, 32);
    w_u32(callbacks, 0x8002C16C);
    uint32 count = r_u16(0x80077364);
    w_u16(0x8007735C, delta);
    base = r_u32(0x80077500);
    far_distance = r_u32(0x800773B4);
    w_u16(0x80077364, count + 1);
    w_u16(0x80077520, base - far_distance);
    return 0;
}

uint32 ob_game_800AB120(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x800AB120, "GAME.BIN");
    uint32 slot = (uint32)(sint32)r_s16(object + 326);
    if (ob_game_800C1944(0x800CBA00 + slot * 104) == 1)
    {
        slot = (uint32)(sint32)r_s16(object + 326);
        ob_game_800C191C(0x800CBA00 + slot * 104);
        if (!r_u32(object + 64))
            ob_game_800C0744(object, 0, time + (uint32)(sint32)r_s16(object + 308));
    }
    uint32 flags = r_u32(record + 28);
    uint32 source = r_u32(record + 52);
    if (flags & 0x10904400)
    {
        uint32 state = r_u32(object + 116);
        uint32 kind = r_u8(state);
        if (kind == 4)
        {
            w_u32(state + 12, time + 5000);
            state = r_u32(object + 116);
            kind = r_u8(state);
        }
        if (kind == 5) w_u32(state + 12, r_u32(state + 12) - 500);
        if (r_u32(object + 292) == 6) goto release_record;
        slot = (uint32)(sint32)r_s16(object + 326);
        if (!r_u16(0x800CBA46 + slot * 104)) goto release_record;
        uint32 damage = ob_game_800B8FBC(object, source);
        if (!ob_game_800A52C4(object, (uint32)(sint32)(sint16)damage, 0xFFFFFFFF)) goto release_record;
        ob_game_800B9584(r_u32(object + 44), 600, 6, time);
        ob_main_80011A24(0x800666C0, 255, 256, r_u32(object + 44), time, 0);
        goto release_record;
    }
    if (flags & 0x20040000)
    {
        w_u32(object + 280, time);
        w_u16(object + 300, r_u16(source + 302));
        goto release_record;
    }
    if (flags & 0x18024)
    {
        if (r_u32(object + 292) == 11)
        {
            ob_main_80011A24(0x800660BC, 128, 256, r_u32(object + 44), time, 0);
            goto release_record;
        }
        if (flags & 0x10000)
        {
            sub_80045A7C(r_u32(object + 44), time);
            w_u32(r_u32(object + 124), 0);
            sub_80045A44(r_u32(object + 44), 0x8006C160);
            goto release_record;
        }
        sub_80045A7C(r_u32(object + 44), time);
        ob_game_800AC640(object, 1);
        sub_80047FF0(record);
        ob_draft_unresolved_call(0x800AC6F8, 2, object, time);
        if (r_u32(object + 128) && !r_u32(source + 128)) ob_game_8009A4A8(source, time);
        goto record_contact;
    }
    if (flags & 2)
    {
        sub_80045A7C(r_u32(object + 44), time);
        ob_game_800AC640(object, 1);
        sub_80047FF0(record);
        ob_draft_unresolved_call(0x800AC6F8, 2, object, time);
        goto record_contact;
    }
    if (!(flags & 0x200)) goto release_record;
    sub_80045A7C(r_u32(object + 44), time);
    sub_80047FF0(record);
    slot = (uint32)(sint32)r_s16(object + 326);
    if (r_u16(0x800CBA46 + slot * 104))
    {
        uint32 angles = r_u32(object + 124);
        uint32 node = r_u32(object + 44);
        ob_game_800BA108(object, angles + 4, r_u32(angles), node);
    }
    else sub_80046544(r_u32(object + 52));
record_contact:
    w_u32(object + 280, time);
    w_u16(object + 300, r_u16(source + 302));
    goto finish;
release_record:
    sub_80047FF0(record);
finish:
    slot = (uint32)(sint32)r_s16(object + 326);
    uint32 result = r_u16(0x800CBA46 + slot * 104);
    if (!result) return ob_game_800AB4E4(object, time);
    return result;
}

uint32 ob_game_800A0278(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x800A0278, "GAME.BIN");
    uint32 flags = r_u32(record + 28);
    uint32 source = r_u32(record + 52);
    uint32 owner = r_u32(r_u32(object + 108));
    if (flags & 0x8020)
    {
        sub_80045A7C(r_u32(source + 44), time);
        sub_80045A7C(r_u32(object + 44), time);
        w_u32(object + 280, time);
        w_u16(object + 300, r_u16(source + 302));
        if ((sint32)time < (sint32)(r_u32(source + 280) + 50)) w_u32(r_u32(source + 124), 0);
        else
        {
            uint32 slot = (uint32)(sint32)r_s16(source + 326);
            if (r_u16(0x800CBA46 + slot * 104)) ob_game_800A52C4(source, 16, 0xFFFFFFFF);
        }
        w_u32(source + 280, time);
        uint32 contact = r_u16(object + 302);
        uint32 data = r_u32(source + 124);
        w_u16(source + 300, contact);
        w_u32(data + 8, time + 300);
        ob_game_80097FC4(r_u32(owner + 116), 5);
        w_u32(r_u32(owner + 116) + 12, time + 1000);
        w_u8(r_u32(owner + 116) + 16, 3);
        sub_80047FF0(record);
        sub_80045A44(r_u32(object + 44), 0x8006C160);
        ob_game_800A1CA8(owner, 2, time);
        ob_game_800A1BD4(owner, 3);
        return ob_game_800A1BD4(owner, 0);
    }
    if (!(flags & 0x10804400)) return (uint32)sub_80047FF0(record);
    if (r_s16(source + 134) == 9)
    {
        sub_800465E8(r_u32(source + 52), r_u32(object + 52));
        return (uint32)sub_80047FF0(record);
    }
    uint32 damage = ob_game_800B8FBC(object, source) << 5;
    sub_80047FF0(record);
    uint32 holder = r_u32(object + 108);
    uint32 current_owner = r_u32(holder);
    uint32 data = r_u32(current_owner + 108);
    uint32 field;
    uint32 shape;
    uint32 effect;
    uint32 flag;
    if (r_u16(object + 302) == r_u16(data + 36))
    {
        field = 0;
        shape = (uint32)sub_800437C4(current_owner, 0x100D2);
        flag = 1;
    }
    else
    {
        field = 2;
        shape = (uint32)sub_800437C4(current_owner, 0x100D7);
        flag = 2;
    }
    sint32 amount = (sint16)damage;
    if (amount < r_u16(data + 40 + field))
    {
        w_u16(data + 40 + field, r_u16(data + 40 + field) - damage);
        uint32 result = r_u32(0x800C835C) - (uint32)amount;
        w_u16(shape + 56, r_u16(shape + 56) | 0x4000);
        w_u32(0x800C835C, result);
        return result;
    }
    w_u16(data + 36 + field, 0xFFFF);
    w_u16(data + 40 + field, 0);
    w_u8(data + 44 + field / 2, 0xFF);
    effect = (uint32)sub_800437C4(r_u32(holder), field ? 0x100C3 : 0x100BF);
    uint32 slot = (uint32)(sint32)r_s16(owner + 326);
    w_u8(0x800CBA5D + slot * 104, r_u8(0x800CBA5D + slot * 104) | flag);
    uint32 index = r_u8(data + 44 + field / 2);
    w_u32(0x800D5C98 + index * 4, 0);
    ob_main_80011A24(0x800687C8, 191, 256, r_u32(object + 44), time, 0);
    uint32 result = ob_game_800BCAA0(object);
    if (shape)
    {
        ob_main_80044080(shape, 0x800662CC);
        return ob_game_800A2558(effect, time, 10, 100, 1024, 225);
    }
    return result;
}
