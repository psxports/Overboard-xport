#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_extra_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800BB494(uint32 time)
{
    FUNCTION_MARKER(0x800BB494, "GAME.BIN");
    uint32 count = r_u8(r_u32(0x80077190) + 2);
    if (!count) return count;
    uint32 index = 0;
    do
    {
        uint32 offset = index * 16;
        uint32 record = r_u32(0x80077198) + offset;
        while (r_u8(record + 3))
        {
            uint32 type = r_u8(record + 2);
            if (type <= 5 || type == 7)
                w_u8(r_u32(0x80077198) + offset + 3, 0);
            else if (type == 8)
            {
                w_u8(r_u32(0x80077198) + offset + 3, 0);
                ob_game_800BAB08(r_u32(0x80077198) + offset, time);
            }
            else if (type >= 9 && type <= 11)
            {
                record = r_u32(0x80077198) + offset;
                w_u8(record + 3, r_u8(record + 3) - 1);
                ob_game_800BABEC(r_u32(0x80077198) + offset, 8 - type);
            }
            record = r_u32(0x80077198) + offset;
        }
        count = r_u8(r_u32(0x80077190) + 2);
        ++index;
    } while ((sint32)index < (sint32)count);
    return 0;
}

uint32 ob_game_800953B4(uint32 object)
{
    FUNCTION_MARKER(0x800953B4, "GAME.BIN");
    sub_8004E644(r_u32(object + 60));
    sub_80044058(r_u32(object + 48));
    sub_80045124(r_u32(object + 44));
    ob_game_800955B0(object);
    return sub_80043664(object);
}

uint32 ob_game_800A19D8(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800A19D8, "GAME.BIN");
    w_u32(object + 100, 0x800A1A00);
    return ob_game_800BCB90(object, context, time);
}

uint32 ob_game_800A9160(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800A9160, "GAME.BIN");
    w_u32(object + 100, 0x800A8F04);
    return ob_game_800BCB90(object, context, time);
}

uint32 ob_game_800B7F60(uint32 node, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800B7F60, "GAME.BIN");
    uint32 record = ob_draft_scratch_acquire(96);
    ob_game_800B8E40(node, record, time);
    w_u32(record + 44, 0x800C4958);
    w_u32(record + 56, 300);
    w_u16(record + 88, 105);
    w_u8(record + 92, 8);
    w_u16(record + 86, 75);
    w_u16(record + 90, 75);
    w_u8(record + 93, 4);
    uint32 result = ob_game_80092408(r_u32(0x80083E34), record, time, 6);
    ob_draft_scratch_release(record);
    return result;
}

uint32 ob_game_800B9A28(uint32 node, uint32 vector, uint32 scale, uint32 duration, uint32 time)
{
    FUNCTION_MARKER(0x800B9A28, "GAME.BIN");
    uint32 record = ob_draft_scratch_acquire(96);
    ob_game_800B8E40(node, record, time);
    w_u32(record + 44, 0x800C48E4);
    w_u32(record + 56, (uint32)(sint32)(sint16)duration);
    w_u8(record + 92, 12);
    uint32 x = r_u32(vector), y = r_u32(vector + 4), z = r_u32(vector + 8);
    w_u32(record + 32, x);
    w_u32(record + 36, y);
    w_u32(record + 40, z);
    sint32 half = (sint16)scale / 2;
    w_u16(record + 86, half);
    w_u16(record + 90, half);
    w_u16(record + 88, scale);
    w_u8(record + 93, 4);
    uint32 result = ob_game_80092408(r_u32(0x80083E34), record, time, 6);
    ob_draft_scratch_release(record);
    return result;
}

uint32 ob_game_800BBDF8(uint32 position, uint32 time)
{
    FUNCTION_MARKER(0x800BBDF8, "GAME.BIN");
    uint32 record = ob_draft_scratch_acquire(96);
    w_u32(record + 44, 0x800C47E8);
    w_u32(record + 56, 1300);
    w_u16(record + 90, 250);
    w_u16(record + 86, 250);
    w_u16(record + 88, 1000);
    w_u8(record + 92, 14);
    w_u8(record + 93, 4);
    w_u32(record + 76, 1);
    w_u32(record + 48, 0);
    w_u32(record + 32, 0);
    w_u32(record + 36, 0);
    w_u32(record + 40, 0);
    w_u8(record + 94, 0);
    w_u32(record + 60, 0);
    w_u8(record + 95, 1);
    uint32 random = ob_random15() & 255;
    w_u32(record, r_u32(position) + random - 128);
    w_u32(record + 4, r_u32(position + 4) + 750);
    random = ob_random15() & 255;
    w_u32(record + 8, r_u32(position + 8) + random - 128);
    uint32 result = ob_game_80092408(r_u32(0x80083E34), record, time, 6);
    ob_draft_scratch_release(record);
    return result;
}

uint32 ob_game_800C0B78(uint32 object)
{
    FUNCTION_MARKER(0x800C0B78, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    uint32 info = ob_game_800C1094(r_u32(r_u32(object + 48) + 40));
    sint32 width = r_s16(info + 66), height = r_s16(info + 70);
    uint32 level = r_u8(0x8006C231);
    if (((level - 8 < 4) && r_u32(object + 292) != 31) ||
        ((level - 12 < 4) && r_u32(object + 292) != 28 && r_u32(object + 292) != 30))
    {
        w_u8(data + 26, 4);
        return 4;
    }
    w_u8(data + 28, width >= 1601);
    w_u8(data + 26, height >= 2601 ? 1 : height >= 2001 ? 2 : 3);
    sint32 result = (r_s8(data + 26) + r_s8(data + 28)) / 2;
    w_u8(data + 27, result);
    return (uint32)result;
}

uint32 ob_game_80097850(uint32 object, uint32 heading, uint32 mode, uint32 time)
{
    FUNCTION_MARKER(0x80097850, "GAME.BIN");
    sint32 sign = 1;
    uint32 angle = r_u16(heading);
    uint32 state = r_u32(object + 112);
    uint32 elapsed = time - r_u32(object + 28);
    if ((uint16)mode == 1) angle -= 32768;
    if ((uint16)(angle + 32700) > 0xFF78)
        angle += 60 * ((ob_main_8001AFC8() & 6) - 3);
    if ((sint16)angle < 0)
    {
        sign = -1;
        angle = (uint32)-(sint16)angle;
    }
    sint32 step = (sint16)(r_u16(r_u32(state) + 4) * elapsed);
    sint32 magnitude = (sint16)angle;
    sint32 change;
    if (magnitude >= step) change = sign * step;
    else if (magnitude >= step / 2) change = sign * step / 2;
    else if (magnitude >= step / 4) change = sign * step / 4;
    else return magnitude != r_s16(heading);
    uint32 parameters = r_u32(object + 124);
    w_u16(parameters + 4, r_u16(parameters + 4) + change);
    return (sint16)angle != r_s16(heading);
}

uint32 ob_game_80097BD4(uint32 object, uint32 mode, uint32 time)
{
    FUNCTION_MARKER(0x80097BD4, "GAME.BIN");
    uint32 state = r_u32(object + 112);
    uint32 elapsed = time - r_u32(object + 28);
    uint32 upper = r_u16(r_u32(state));
    sint32 lower = 0;
    mode &= 255;
    if (mode == 6) lower = 50;
    else if (mode == 7) upper *= 2;
    if (mode == 2 || mode == 3)
    {
        upper = mode == 2 ? r_u16(r_u32(r_u32(0x8006C138) + 124)) : upper / 2;
        sint32 target = (sint16)upper;
        sint32 speed = r_s32(r_u32(object + 124));
        lower = target;
        if (target == speed) return (uint32)target;
        mode = speed < target ? 0 : 1;
    }
    if (mode == 0 || mode == 1 || mode == 4 || mode == 5 || mode == 6 || mode == 7)
    {
        uint32 delta = r_u16(r_u32(state) + 2) * elapsed;
        uint32 parameters = r_u32(object + 124);
        uint32 speed = r_u32(parameters);
        w_u32(parameters, mode == 0 || mode == 7 ? speed + delta : speed - delta);
        parameters = r_u32(object + 124);
        sint32 limit = mode == 0 || mode == 7 ? (sint16)upper :
            mode == 4 ? -(sint16)upper : mode == 5 ? -((sint16)upper * 2) : lower;
        speed = r_u32(parameters);
        if ((mode == 0 || mode == 7) ? limit < (sint32)speed : (sint32)speed < limit)
            w_u32(parameters, (uint32)limit);
    }
    return r_u32(r_u32(object + 124));
}

uint32 ob_game_80098088(uint32 object, uint32 mode, uint32 time)
{
    FUNCTION_MARKER(0x80098088, "GAME.BIN");
    uint32 parameters = r_u32(object + 124);
    if (!parameters) return 0;
    if ((sint32)time < r_s32(parameters + 8)) return 1;
    return ob_game_80097BD4(object, mode & 255, time);
}

uint32 ob_game_80097E28(uint32 context, uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x80097E28, "GAME.BIN");
    uint32 record = r_u32(object + 116);
    uint32 product = r_u32(r_u32(object + 124)) * (time - r_u32(object + 28));
    w_u32(0x800C6260, (uint32)((sint32)product >> 8));
    uint32 callbacks = 0x800C4E74 + r_u8(record) * 24;
    if (!r_u32(0x8006C134)) w_u32(0x8006C134, r_u32(0x800C9968));
    ob_game_80097578(object, 0x800C90F8, time);
    uint32 row = (uint32)(r_s16(object + 326) * 104);
    uint32 value = r_u32(0x800CBA3C + row);
    w_u32(0x800C8328, 0);
    w_u32(0x800C8324, value);
    row = (uint32)(r_s16(object + 326) * 104);
    w_u32(0x800C832C, r_u32(0x800CBA40 + row));
    ob_game_80097578(object, 0x800C8318, time);
    w_u16(object + 312, r_u16(object + 312) & 0xFFFB);
    uint32 target = r_u32(callbacks);
    if (target) ob_draft_unresolved_call(target, 3, object, context, time);
    target = r_u32(callbacks + 8);
    if (target) ob_draft_unresolved_call(target, 3, object, context, time);
    target = r_u32(callbacks + 20);
    if (target) ob_draft_unresolved_call(target, 3, object, context, time);
    record = r_u32(object + 116);
    w_u8(record + 116, 0);
    return record;
}

uint32 ob_game_80095670(uint32 object, uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x80095670, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(88);
    uint32 flags = r_u32(state + 76);
    w_u32(state + 64, 0x80067310);
    w_u32(state + 68, local);
    w_u32(state + 72, 0);
    if (flags != 0x8000000) w_u32(state + 76, 0x100000);
    w_u32(state + 80, 6);
    ob_game_800B66C4(object, owner, state, time);
    ob_game_800C0F70(local, 400, 300);
    w_u32(local + 44, 0x2097EFB6);
    w_u32(local + 48, 0x2097EFB6);
    w_u32(local + 60, 0x2097EFB6);
    w_u32(local + 40, 0);
    w_u32(local + 52, 0);
    w_u32(local + 56, 0);
    w_u32(local + 68, 0);
    w_u32(local + 64, 0);
    w_u32(local + 80, 0x800B73AC);
    w_u32(object + 52, sub_80046184(object, local, time));
    w_u32(object + 100, 0x80095768);
    w_u32(object + 92, time + 250);
    sub_80045EF4(object + 64);
    w_u32(object + 104, 1);
    ob_draft_scratch_release(local);
    return object;
}

uint32 ob_game_80091C9C(uint32 object, uint32 event, uint32 time)
{
    FUNCTION_MARKER(0x80091C9C, "GAME.BIN");
    uint32 type = r_u32(object + 292);
    if (type - 3 < 2)
    {
        uint32 data = r_u32(object + 108);
        if (r_s16(data + 4) > 0 || r_u32(event + 48) >= 0x57E4)
        {
            uint32 elapsed = time - r_u32(object + 28);
            w_u16(data + 4, r_u16(data + 4) - elapsed);
            return elapsed;
        }
        if (type == 4)
        {
            uint32 local = ob_draft_scratch_acquire(32);
            sub_80045378(r_u32(object + 44), time, local);
            w_u32(local + 4, r_u32(local + 4) - 500);
            uint32 row = (uint32)(r_s16(object + 326) * 104);
            w_u32(local + 12, r_u16(0x800CBA32 + row) + 15);
            row = (uint32)(r_s16(object + 326) * 104);
            w_u16(0x800CBA32 + row, r_u16(0x800CBA32 + row) + 1);
            row = (uint32)(r_s16(object + 326) * 104);
            w_u16(0x800CBA32 + row, r_u16(0x800CBA32 + row) & 1);
            uint32 heading = r_u16(r_u32(object + 124) + 4);
            w_u16(local + 18, 0);
            w_u16(local + 20, 0);
            w_u16(local + 22, 0);
            w_u8(local + 24, 7);
            w_u8(local + 25, 0);
            w_u8(local + 26, 0);
            w_u8(local + 27, 0);
            w_u16(local + 16, heading);
            ob_game_800A50BC(local);
            ob_game_800AEEE8(time);
            ob_draft_scratch_release(local);
            type = r_u32(object + 292);
        }
        if (type == 3)
        {
            ob_game_800B5BD8(0, r_u32(object + 120), r_u8(r_u32(object + 112) + 40), time);
            if (r_u32(event + 48) < r_u32(r_u32(object + 116) + 60) && r_s32(0x800C9108) < 100 &&
                ob_game_800B5C50(0, r_u32(object + 120), time))
                ob_game_800B5CB4(object, 0, 0, time);
        }
        uint32 result = r_u16(data + 4) + 10000;
        w_u16(data + 4, result);
        return result;
    }
    ob_game_800B5BD8(0, r_u32(object + 120), r_u8(r_u32(object + 112) + 40), time);
    uint32 result = r_u32(event + 48) < r_u32(r_u32(object + 116) + 60);
    if (result)
    {
        result = ob_game_800B5C50(0, r_u32(object + 120), time);
        if (result)
        {
            uint32 node = ob_game_800B5CB4(object, 0, 0, time);
            return sub_80046544(r_u32(node + 52));
        }
    }
    return result;
}

static void ob_batch9_shape(uint32 local, uint32 flags, uint32 callback)
{
    w_u32(local + 44, flags);
    w_u32(local + 48, flags);
    w_u32(local + 60, flags);
    w_u32(local + 40, 0);
    w_u32(local + 52, 0);
    w_u32(local + 56, 0);
    w_u32(local + 68, 0);
    w_u32(local + 64, 0);
    w_u32(local + 80, callback);
}

uint32 ob_game_8009A13C(uint32 object, uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x8009A13C, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(88);
    w_u32(state + 64, 0x8006723C);
    w_u32(state + 72, 0x80067248);
    w_u32(state + 68, local);
    w_u32(state + 80, 6);
    ob_game_800B66C4(object, owner, state, time);
    
    ob_batch9_shape(local, 0x3AB36, 0x8009A3C4);
    uint32 shape = sub_80046184(object, local, time);
    w_u32(object + 52, shape);
    w_u32(object + 100, 0x8009A25C);
    w_u32(object + 92, time + 75);
    sub_80045EF4(object + 64);
    w_u16(object + 136, ob_main_80011A24(0x8006724C, 128, 256, r_u32(object + 44), time, 1));
    w_u32(object + 104, ob_game_800951F0(owner, state, time));
    ob_draft_scratch_release(local);
    return object;
}

uint32 ob_game_8009F7FC(uint32 object, uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x8009F7FC, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(88);
    uint32 actor = r_u32(r_u32(state + 96) + 80);
    w_u32(state + 64, r_u32(r_u32(actor + 292) == 255 ? 0x800C4B60 : 0x800C4B80));
    sint32 type = r_s16(state + 50);
    w_u32(state + 72, 0);
    w_u32(state + 44, 0);
    if (type != 2) w_u32(state + 4, r_u32(state + 4) + (type == 1 ? -1600 : 3000));
    w_u32(state + 68, local);
    w_u32(state + 80, 6);
    ob_game_800B66C4(object, owner, state, time);
    
    ob_batch9_shape(local, 0x403AB36, 0x8009FA5C);
    ob_game_8009FA98(object, local + 20, (uint32)r_s16(state + 50));
    uint32 shape = sub_80046184(object, local, time);
    w_u32(object + 52, shape);
    w_u32(object + 100, 0x8009F944);
    w_u32(object + 92, time + 50);
    sub_80045EF4(object + 64);
    
    ob_draft_scratch_release(local);
    return object;
}

uint32 ob_game_800A12D0(uint32 object, uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x800A12D0, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(88);
    w_u32(state + 64, r_u32(state + 56) == 10 ? 0x80068414 : 0x800672B8);
    w_u32(state + 72, 0);
    w_u32(state + 68, local);
    w_u32(state + 80, 6);
    ob_game_800B66C4(object, owner, state, time);
    ob_game_800C0F70(local, 100, 1000);
    ob_batch9_shape(local, 0x2487EF36, 0x800B73AC);
    uint32 shape = sub_80046184(object, local, time);
    w_u32(object + 52, shape);
    w_u32(object + 100, 0x800A13D0);
    w_u32(object + 92, time + 200);
    sub_80045EF4(object + 64);
    w_u32(object + 104, 1);
    ob_draft_scratch_release(local);
    return object;
}

uint32 ob_game_800A2E9C(uint32 object, uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x800A2E9C, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(88);
    w_u32(state + 64, 0x80067314);
    w_u32(state + 72, 0x80067234);
    w_u16(state + 60, 350);
    w_u32(state + 68, local);
    w_u32(state + 80, 6);
    ob_game_800B66C4(object, owner, state, time);
    ob_game_800C0F54(local, 100);
    ob_batch9_shape(local, 0x3AB36, 0x800B6D10);
    uint32 shape = sub_80046184(object, local, time);
    w_u32(object + 52, shape);
    w_u32(object + 100, 0x800A2F7C);
    w_u32(object + 92, time + 1500);
    sub_80045EF4(object + 64);
    
    ob_draft_scratch_release(local);
    return object;
}

uint32 ob_game_800A5BBC(uint32 object, uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x800A5BBC, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(88);
    w_u32(state + 64, r_u32(state + 56) == 39 ? 0x80069130 : 0x80067318);
    w_u32(state + 72, 0);
    w_u32(state + 68, local);
    w_u32(state + 80, 6);
    ob_game_800B66C4(object, owner, state, time);
    w_u32(local + 36, 0x800000);
    ob_game_800C0F70(local, 500, 1000);
    ob_batch9_shape(local, 0x2486EF36, 0x800B7418);
    uint32 shape = sub_80046184(object, local, time);
    w_u32(object + 52, shape);
    sub_80046544(shape);
    w_u32(object + 100, 0x800A5D30);
    w_u32(object + 92, time + 200);
    sub_80045EF4(object + 64);
    w_u16(object + 136, 65535);
    w_u32(object + 104, 1);
    w_u16(object + 142, 40);
    w_u16(object + 144, r_s16(state + 50) == 1 ? 0 : -((sint16)(r_u16(state + 84) | 0x2000) * 2));
    sub_800440B8(r_u32(object + 48), 80);
    ob_draft_scratch_release(local);
    return object;
}

uint32 ob_game_800A9798(uint32 object, uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x800A9798, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(88);
    w_u32(state + 64, 0x80067314);
    w_u32(state + 72, 0);
    w_u32(state + 68, local);
    w_u32(state + 80, 6);
    ob_game_800B66C4(object, owner, state, time);
    ob_game_800C0F70(local, 100, 1000);
    ob_batch9_shape(local, 0x2487EF36, 0x800B73AC);
    uint32 shape = sub_80046184(object, local, time);
    w_u32(object + 52, shape);
    ob_main_80011A24(0x80067250, 128, 256, r_u32(object + 44), time, 0);
    w_u32(object + 100, 0x800A9950);
    w_u32(object + 92, time + 100);
    sub_80045EF4(object + 64);
    w_u32(object + 104, 0);
    ob_draft_scratch_release(local);
    return object;
}

uint32 ob_game_800AD798(uint32 object, uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x800AD798, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(88);
    w_u32(state + 64, 0x8006A97C);
    w_u32(state + 72, 0x80067234);
    w_u16(state + 60, 256);
    w_u32(state + 68, local);
    w_u32(state + 80, 6);
    ob_game_800B66C4(object, owner, state, time);
    ob_game_800C0F54(local, 100);
    ob_batch9_shape(local, 0x3AB36, 0x800B6D10);
    uint32 shape = sub_80046184(object, local, time);
    w_u32(object + 52, shape);
    w_u32(object + 100, 0x800AD8A4);
    w_u32(object + 92, time + 50);
    sub_80045EF4(object + 64);
    w_u32(object + 104, ob_game_800951F0(owner, state, time));
    ob_draft_scratch_release(local);
    return object;
}

uint32 ob_game_800AF810(uint32 object, uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x800AF810, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(88);
    uint32 type = r_u32(r_u32(state + 96) + 96);
    w_u32(state + 64, type == 41 ? 0x8006A97C : type == 40 ? 0x80069134 : 0x8006731C);
    w_u32(state + 88, 5000);
    if (type == 33) w_u32(state + 4, r_u32(state + 4) + 2000);
    w_u32(state + 72, 0);
    w_u32(state + 68, local);
    w_u32(state + 80, 6);
    ob_game_800B66C4(object, owner, state, time);
    
    ob_batch9_shape(local, 0x3AB36, 0x800B6D10);
    uint32 shape = sub_80046184(object, local, time);
    w_u32(object + 52, shape);
    w_u32(object + 100, 0x800AF9B4);
    w_u32(object + 92, time + 200);
    sub_80045EF4(object + 64);
    w_u32(object + 104, ob_game_800951F0(owner, state, time));
    w_u16(object + 136, ob_main_80011A24(0x80067320, 42, 256, r_u32(object + 44), time, 1));
    w_u16(object + 134, 9);
    ob_draft_scratch_release(local);
    return object;
}

uint32 ob_game_800B597C(uint32 object, uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x800B597C, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(88);
    w_u32(state + 64, 0x80068F34);
    w_u32(state + 72, 0);
    w_u32(state + 76, 0x100000);
    w_u32(state + 68, local);
    w_u32(state + 80, 1);
    ob_game_800B66C4(object, owner, state, time);
    ob_game_800C0F70(local, 1000, 2000);
    ob_batch9_shape(local, 0x200582B2, 0x800B5B48);
    uint32 shape = sub_80046184(object, local, time);
    w_u32(object + 52, shape);
    w_u16(object + 134, 8);
    w_u32(object + 100, 0x800B5A8C);
    w_u32(object + 92, time + 400);
    sub_80045EF4(object + 64);
    w_u16(object + 136, ob_main_80011A24(0x80068F30, 160, 512, r_u32(object + 44), time, 1));
    ob_draft_scratch_release(local);
    return object;
}

uint32 ob_game_8009A25C(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x8009A25C, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    uint32 elapsed = time - r_u32(object + 28);
    if (elapsed)
    {
        ob_main_80011E20((uint32)r_s16(object + 136), r_u32(object + 44), 128, time);
        ob_draft_unresolved_call(0x80011F24, 4, r_u32(object + 44), (uint32)r_s16(object + 136), 256, time);
        ob_game_800B9988(r_u32(object + 44), 256, time);
        sint32 type = r_s16(r_u32(object + 48) + 160);
        if (type != 224)
        {
            uint32 node = r_u32(object + 44);
            uint32 delta = type == 288 ? (uint32)((sint32)(elapsed * 3) / 2) : elapsed * 6;
            w_u32(node + 136, r_u32(node + 136) - delta);
            sub_80045ADC(r_u32(object + 44));
            sub_80045B74(r_u32(object + 44));
        }
        w_u32(object + 28, time);
    }
    if (r_s32(r_u32(object + 44) + 112) > 0)
    {
        w_u32(object + 92, time + 150);
        return sub_80045EF4(object + 64);
    }
    ob_main_80011A24(0x80067240, 128, 256, r_u32(object + 44), time, 0);
    ob_game_800B7FDC(r_u32(object + 44), 0, 208, time);
    return ob_game_800B6C38(object);
}

uint32 ob_game_8009F944(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x8009F944, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    if (time != r_u32(object + 28))
    {
        ob_main_80011E20((uint32)r_s16(object + 136), r_u32(object + 44), 128, time);
        if (r_u32(object + 48))
        {
            uint32 actor = r_u32(r_u32(object + 112) + 80);
            uint32 table = actor && r_u32(actor + 292) == 255 ? 0x800C4B60 : 0x800C4B80;
            uint32 index = sub_8001B008() & 7;
            w_u32(r_u32(object + 48) + 40, r_u32(table + index * 4));
        }
        w_u32(object + 28, time);
    }
    if (r_s32(object + 128) < (sint32)time) return ob_game_800B6C38(object);
    w_u32(object + 92, time + 50);
    return sub_80045EF4(object + 64);
}

uint32 ob_game_800A1A00(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800A1A00, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    sub_80045A7C(r_u32(object + 44), time);
    if (time == r_u32(object + 28)) return 3;
    if (r_u32(object + 288) == 3)
    {
        if (r_s16(data + 32) != 3 && r_s32(r_u32(object + 44) + 84) <= 0)
        {
            ob_main_80011A24(0x80067588, 128, 128, r_u32(object + 44), time, 0);
            ob_game_800B89D8(r_u32(object + 44), 200, time);
            return ob_game_800BCAA0(object);
        }
    }
    else
    {
        ob_game_80097E28(0, object, time);
        ob_game_800A2BEC(object);
        w_u32(object + 28, time);
    }
    return ob_game_800A19D8(object, 0, time + 250);
}

uint32 ob_game_800A2F7C(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800A2F7C, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    uint32 local = ob_draft_scratch_acquire(104);
    w_u32(local + 56, UINT32_MAX);
    w_u16(local + 92, 4000);
    w_u32(local + 44, 2500);
    w_u16(local + 60, 304);
    w_u16(local + 84, -8332);
    w_u16(local + 50, 0x4000);
    w_u32(local + 76, 0x4000);
    w_u16(local + 86, 3);
    w_u8(local + 48, 0);
    w_u16(local + 52, 0);
    w_u32(local + 88, 550);
    w_u32(local + 96, r_u32(object + 112));
    sub_80045378(r_u32(object + 44), time, local);
    sub_80029E80(r_s16(local + 50), local + 12);
    uint32 spawned = ob_game_800A9720(r_u32(object + 12), local, time);
    if (spawned)
    {
        uint32 actor = r_u32(r_u32(spawned + 112) + 80);
        sub_800465E8(r_u32(spawned + 52), r_u32(actor + 52));
        uint32 linked = r_u32(actor + 132);
        if (linked) sub_800465E8(r_u32(spawned + 52), r_u32(linked + 52));
    }
    uint32 result = ob_game_800B6C38(object);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_800B6D10(uint32 object, uint32 contact, uint32 time)
{
    FUNCTION_MARKER(0x800B6D10, "GAME.BIN");
    uint32 other = r_u32(contact + 52);
    if (r_u32(other + 292) == 38 && r_s16(object + 132) == 9)
    {
        sub_800465E8(r_u32(object + 52), r_u32(other + 52));
        return sub_80047FF0(contact);
    }
    sint32 speed = r_s16(object + 138);
    if (speed < 0) speed = -speed;
    speed = (sint16)speed >> 3;
    uint32 volume = speed < 64 ? 64 : speed < 256 ? (uint32)speed : 255;
    ob_game_800B7F60(r_u32(object + 44), 0, time);
    sint32 type = r_s16(object + 132);
    uint32 sound = 0;
    switch (type)
    {
    case 0: case 1: case 11: sound = 0x80067238; break;
    case 3: case 4: case 8: case 9: case 12: sound = 0x800666C0; break;
    }
    if (sound) ob_main_80011A24(sound, volume, 256, r_u32(object + 44), time, 0);
    sub_80047FF0(contact);
    return ob_game_800B6C38(object);
}

uint32 ob_game_800B73AC(uint32 object, uint32 contact, uint32 time)
{
    FUNCTION_MARKER(0x800B73AC, "GAME.BIN");
    sub_800465E8(r_u32(contact + 8), r_u32(contact + 48));
    w_u32(object + 128, (time - 3) & 0xFFFFFFFE);
    return sub_80047FF0(contact);
}

static sint32 ob_batch9_scaled_size(uint32 object, sint32 divisor)
{
    return (sint16)((r_s16(object + 140) * 256) / divisor);
}

static uint32 ob_batch9_burst_update(uint32 object, uint32 time, sint32 barrel)
{
    ob_game_800B9DA0(object, time);
    if (r_u32(object + 104))
    {
        uint32 elapsed = time - r_u32(object + 28);
        if (elapsed)
        {
            sub_80045A7C(r_u32(object + 44), time);
            uint32 node = r_u32(object + 44);
            w_u32(node + 136, r_u32(node + 136) - elapsed * 5);
            sub_80045ADC(r_u32(object + 44));
        }
    }
    w_u32(object + 92, time + 200);
    sint32 expired = r_s32(object + 128) < (sint32)time;
    w_u32(object + 28, time);
    if (!expired) return sub_80045EF4(object + 64);
    sint32 phase = r_s16(object + 142);
    w_u32(object + 92, time + 180);
    if (phase != -1)
    {
        if ((sint32)(r_u32(object + 128) + 400) < (sint32)time)
        {
            ob_main_80011A24(0x80067588, 128, 256, r_u32(object + 44), time, 0);
            if (barrel)
            {
                ob_game_800B982C(r_u32(object + 44), ob_batch9_scaled_size(object, 4000), 6, time);
                w_u32(object + 104, 0);
            }
            return ob_game_800B6C38(object);
        }
        return sub_80045EF4(object + 64);
    }
    uint32 position = sub_80045490(r_u32(object + 44), time);
    ob_main_80011A24(0x800666C4, 128, 256, r_u32(object + 44), time, 0);
    sint32 height = r_s32(position + 4);
    if (height >= 201)
    {
        ob_game_800B90B8(r_u32(object + 44), ob_batch9_scaled_size(object, 1000), 6, time);
        ob_game_800B9348(r_u32(object + 44), ob_batch9_scaled_size(object, 2000), 4, time);
        ob_game_800B9584(r_u32(object + 44), ob_batch9_scaled_size(object, 1000), 6, time);
        ob_game_800B9584(r_u32(object + 44), ob_batch9_scaled_size(object, 2000), 6, time);
    }
    else if (barrel && height < -200)
    {
        ob_main_80011A24(0x80067588, 128, 128, r_u32(object + 44), time, 0);
        ob_game_800B9434(r_u32(object + 44), ob_batch9_scaled_size(object, 1000), 1, time);
        ob_game_800B979C(r_u32(object + 44), ob_batch9_scaled_size(object, 4000), 1, time);
    }
    else
    {
        ob_main_80011A24(0x80067588, 128, 128, r_u32(object + 44), time, 0);
        ob_game_800A1864(r_u32(object + 44), r_s16(object + 140) / 14, time);
        ob_game_800A18E4(r_u32(object + 44), r_s16(object + 140) / 14, time);
        uint32 vector = ob_draft_scratch_acquire(12);
        w_u32(vector + 8, 0);
        w_u32(vector + 4, 0);
        w_u32(vector, 0);
        ob_game_800B961C(r_u32(object + 44), vector, 0, ob_batch9_scaled_size(object, 5000), 6, time);
        w_u32(vector + 4, 1000);
        ob_game_800B961C(r_u32(object + 44), vector, 100, ob_batch9_scaled_size(object, 4000), 6, time);
        w_u32(vector + 4, 2000);
        ob_game_800B961C(r_u32(object + 44), vector, 200, ob_batch9_scaled_size(object, 2000), 6, time);
        ob_draft_scratch_release(vector);
    }
    sub_800440B8(r_u32(object + 48), 10);
    uint32 flags = r_u16(object + 138);
    w_u16(object + 142, 100);
    w_u16(object + 138, flags | 0x2000);
    uint32 local = ob_draft_scratch_acquire(88);
    w_u32(local + 4, 0x10000001);
    w_u32(local + 32, 200);
    w_u32(local + 72, object);
    w_u32(local + 76, 0);
    w_u32(local + 36, r_u32(r_u32(object + 52) + 136));
    sint32 size = r_s16(object + 140);
    ob_game_800C0F70(local, size, barrel ? size / 2 : 2000);
    ob_batch9_shape(local, barrel ? 0x2097EFB6 : 0x2487EF36, 0x800B75F0);
    sub_8004651C(r_u32(object + 52));
    w_u32(object + 52, sub_80046184(object, local, time));
    if (barrel)
    {
        w_u32(r_u32(object + 56) + 68, (uint32)r_s16(object + 140));
        w_u32(r_u32(object + 56) + 72, (uint32)r_s16(object + 140));
        w_u32(r_u32(object + 56) + 76, (uint32)r_s16(object + 140));
        sub_80045A7C(r_u32(object + 44), time);
        sub_80045ADC(r_u32(object + 44));
    }
    uint32 result = sub_80045EF4(object + 64);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_80095768(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x80095768, "GAME.BIN");
    return ob_batch9_burst_update(object, time, 1);
}

uint32 ob_game_800A13D0(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800A13D0, "GAME.BIN");
    return ob_batch9_burst_update(object, time, 0);
}

uint32 ob_game_800B9DA0(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800B9DA0, "GAME.BIN");
    sint32 slot = r_s16(object + 120);
    if (slot == -1) return UINT32_MAX;
    uint32 offset = (uint32)(slot * 104);
    uint32 result = r_u16(object + 122);
    if (r_u16(0x800CBA44 + offset) != result) return result;
    result = r_u8(0x800CBA5C + offset) & 15;
    if (result != 2) return result;
    if (r_u32(r_u32(0x800CBA50 + offset) + 52))
    {
        sint32 type = r_s16(0x800CBA2C + offset);
        if (type < 3 || (type >= 5 && type != 10))
            ob_main_80046660(r_u32(object + 52), r_u32(r_u32(0x800CBA50 + offset) + 52), time);
    }
    w_u16(object + 120, 65535);
    return UINT32_MAX;
}

uint32 ob_game_800A2BEC(uint32 object)
{
    FUNCTION_MARKER(0x800A2BEC, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(56);
    sub_80029F58(r_s16(r_u32(object + 124) + 4), local);
    w_u32(local + 28, 0);
    w_u32(local + 24, 0);
    w_u32(local + 32, r_u32(r_u32(object + 124)));
    sub_80029B70(local + 24, local, local + 40);
    sub_80045A44(r_u32(object + 44), local + 40);
    sub_80045848(r_u32(object + 44), local);
    uint32 result = sub_80045B74(r_u32(object + 44));
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_800B9988(uint32 node, uint32 scale, uint32 time)
{
    FUNCTION_MARKER(0x800B9988, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(96);
    ob_game_800B8E40(node, local, time);
    w_u32(local + 44, 0x800C48E4);
    w_u32(local + 56, 400);
    w_u8(local + 92, 12);
    w_u32(local + 40, 0); w_u32(local + 36, 0); w_u32(local + 32, 0);
    w_u16(local + 86, (sint16)scale / 2);
    w_u16(local + 90, (sint16)scale / 2);
    w_u16(local + 88, scale);
    w_u8(local + 93, 4);
    uint32 result = ob_game_80092408(r_u32(0x80083E34), local, time, 6);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_800B961C(uint32 node, uint32 vector, uint32 delay, uint32 scale, uint32 flags, uint32 time)
{
    FUNCTION_MARKER(0x800B961C, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(96);
    ob_game_800B8E40(node, local, time);
    w_u32(local, r_u32(local) + r_u32(vector));
    w_u32(local + 4, r_u32(local + 4) + r_u32(vector + 4));
    uint32 z = r_u32(vector + 8);
    w_u32(local + 44, 0x800C47E8);
    w_u32(local + 56, 800);
    w_u8(local + 92, 14); w_u8(local + 93, 4);
    w_u16(local + 90, (sint16)scale >> 2);
    w_u16(local + 86, (sint16)scale >> 2);
    w_u16(local + 88, scale);
    w_u32(local + 60, delay);
    w_u8(local + 95, 1);
    w_u32(local + 8, r_u32(local + 8) + z);
    uint32 result = ob_game_80092408(r_u32(0x80083E34), local, time, flags);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_800A1864(uint32 node, uint32 scale, uint32 time)
{
    FUNCTION_MARKER(0x800A1864, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(96);
    ob_game_800B8E40(node, local, time);
    w_u32(local + 44, 0x800C4C98);
    w_u32(local + 56, 1000);
    w_u8(local + 92, 14);
    w_u16(local + 90, scale); w_u16(local + 86, scale); w_u16(local + 88, scale);
    w_u8(local + 93, 1);
    uint32 result = ob_game_80092408(r_u32(0x80083E34), local, time, 6);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_800A18E4(uint32 node, uint32 scale, uint32 time)
{
    FUNCTION_MARKER(0x800A18E4, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(96);
    ob_game_800B8E40(node, local, time);
    w_u32(local + 44, 0x800C4C60);
    w_u32(local + 56, 1000);
    w_u8(local + 92, 14);
    w_u16(local + 90, scale); w_u16(local + 86, scale); w_u16(local + 88, scale);
    w_u8(local + 93, 1);
    uint32 result = ob_game_80092408(r_u32(0x80083E34), local, time, 6);
    ob_draft_scratch_release(local);
    return result;
}

static void ob_batch9_effect_fields(uint32 local, uint32 texture, uint32 duration, uint32 first, uint32 second, uint32 third, uint32 type, uint32 mode)
{
    w_u32(local + 44, texture);
    w_u32(local + 56, duration);
    w_u16(local + 86, first); w_u16(local + 88, second); w_u16(local + 90, third);
    w_u8(local + 92, type); w_u8(local + 93, mode);
}

static void ob_batch9_four_effects(uint32 local, uint32 flags, uint32 time)
{
    for (uint32 i = 0; i < 4; ++i)
    {
        sub_80029F58((sint32)(i << 30) >> 16, local + 12);
        ob_game_80092408(r_u32(0x80083E34), local, time, flags);
    }
}

uint32 ob_game_800B90B8(uint32 node, uint32 scale, uint32 flags, uint32 time)
{
    FUNCTION_MARKER(0x800B90B8, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(96);
    ob_game_800B8E40(node, local, time);
    sint32 quarter = (sint16)scale >> 2;
    ob_batch9_effect_fields(local, 0x800C4B58, 200, 10, quarter, quarter, 1, 4);
    ob_game_80092408(r_u32(0x80083E34), local, time, flags);
    ob_batch9_effect_fields(local, 0x800C4B5C, 500, 10, quarter, quarter, 1, 4);
    ob_game_80092408(r_u32(0x80083E34), local, time, flags);
    ob_game_800B8E40(node, local, time);
    ob_batch9_effect_fields(local, 0x800C4AF0, 600, 1, (sint16)scale / 4, 1, 5, 4);
    ob_batch9_four_effects(local, flags, time);
    w_u32(local + 44, 0x800C4B04);
    w_u32(local + 4, 100);
    ob_draft_scratch_release(local);
    return 100;
}

uint32 ob_game_800B9348(uint32 node, uint32 scale, uint32 flags, uint32 time)
{
    FUNCTION_MARKER(0x800B9348, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(96);
    ob_game_800B8E40(node, local, time);
    w_u32(local + 4, 100);
    ob_batch9_effect_fields(local, 0x800C4B04, 1000, 1, (sint16)scale / 5, 1, 5, 4);
    ob_batch9_four_effects(local, flags, time);
    ob_draft_scratch_release(local);
    return 0;
}

uint32 ob_game_800B9434(uint32 node, uint32 scale, uint32 flags, uint32 time)
{
    FUNCTION_MARKER(0x800B9434, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(96);
    ob_game_800B8E40(node, local, time);
    sint32 quarter = (sint16)scale >> 2;
    ob_batch9_effect_fields(local, 0x800C4B5C, 1000, 10, quarter, quarter, 1, 4);
    ob_game_80092408(r_u32(0x80083E34), local, time, flags);
    ob_game_800B8E40(node, local, time);
    ob_batch9_effect_fields(local, 0x800C4C28, 1200, 1, (sint16)scale / 6, 1, 6, 4);
    ob_batch9_four_effects(local, flags, time);
    ob_draft_scratch_release(local);
    return 0;
}

uint32 ob_game_800B982C(uint32 node, uint32 scale, uint32 flags, uint32 time)
{
    FUNCTION_MARKER(0x800B982C, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(96);
    ob_game_800B8E40(node, local, time);
    w_u32(local + 4, 400);
    ob_batch9_effect_fields(local, 0x800C4BE0, 1000, scale, scale, scale, 18, 1);
    ob_game_80092408(r_u32(0x80083E34), local, time, flags);
    ob_game_800B8E40(node, local, time);
    w_u32(local + 4, 60);
    ob_batch9_effect_fields(local, 0x800C4C28, 1400, 1, (sint16)scale / 5, 1, 6, 4);
    ob_batch9_four_effects(local, flags, time);
    ob_draft_scratch_release(local);
    return 0;
}

uint32 ob_game_800A5D30(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800A5D30, "GAME.BIN");
    if (r_u32(object + 104))
    {
        uint32 elapsed = time - r_u32(object + 28);
        if (elapsed)
        {
            sub_80045A7C(r_u32(object + 44), time);
            uint32 node = r_u32(object + 44);
            w_u32(node + 136, r_u32(node + 136) - elapsed * 3);
            sub_80045ADC(r_u32(object + 44));
        }
        w_u32(object + 92, time + 200);
    }
    else
    {
        uint32 phase = r_u16(object + 142);
        w_u32(object + 92, time + 250);
        if (!(phase & 0x3000))
        {
            uint32 amount = phase & 0xFFF;
            sint32 limit = r_s16(object + 140) / 240 + 30;
            sub_800440B8(r_u32(object + 48), (amount * 2) | 1);
            if ((sint32)amount < limit)
            {
                phase = r_u16(object + 142) + 4;
                w_u32(object + 92, time + 100);
            }
            else phase = (uint32)(r_s16(object + 140) / 240 + 30) | 0x2000;
            w_u16(object + 142, phase);
        }
    }
    sint32 before = (sint32)time < r_s32(object + 128);
    w_u32(object + 28, time);
    if (before && (r_u16(object + 142) & 0x3000) == 0x1000)
    {
        sint32 amount = (r_u16(object + 142) & 0xFFF) / 8 - 1;
        if (amount <= 0) amount = 1;
        w_u16(object + 136, ob_main_80011A24(0x80067244, 1, 256, r_u32(object + 44), time, 1));
        uint32 local = ob_draft_scratch_acquire(96);
        ob_game_800B8E40(r_u32(object + 44), local, time);
        w_u32(local + 60, 400);
        w_u8(local + 95, 1);
        w_u32(local + 44, 0x800C4C40);
        w_u32(local + 56, 800 * amount);
        w_u32(local + 76, amount);
        sint32 size = r_s16(object + 140) / 14;
        w_u16(local + 86, 10);
        w_u8(local + 92, 8 * amount);
        w_u8(local + 93, 64);
        w_u16(local + 90, size); w_u16(local + 88, size);
        uint32 node = r_u32(object + 44);
        uint32 x = r_u32(node + 132), y = r_u32(node + 136), z = r_u32(node + 140);
        w_u32(local + 32, x); w_u32(local + 36, y); w_u32(local + 40, z);
        w_u32(object + 116, ob_game_80092408(r_u32(0x80083E34), local, time, 6));
        ob_game_800B8E40(r_u32(object + 44), local, time);
        w_u32(local + 56, 800);
        w_u32(local + 60, 0);
        w_u32(local + 44, 0x800C4C40);
        w_u32(local + 76, 2);
        size = r_s16(object + 140) / 14;
        w_u16(local + 86, 10); w_u16(local + 90, 10);
        w_u8(local + 92, 16); w_u8(local + 93, 64);
        w_u16(local + 88, size);
        node = r_u32(object + 44);
        x = r_u32(node + 132); y = r_u32(node + 136); z = r_u32(node + 140);
        w_u32(local + 32, x); w_u32(local + 36, y); w_u32(local + 40, z);
        ob_game_80092408(r_u32(0x80083E34), local, time, 6);
        uint32 flags = r_u16(object + 138);
        w_u32(object + 128, time - 1);
        w_u16(object + 138, flags | 0x2000);
        ob_draft_scratch_release(local);
    }
    if (r_s32(object + 128) >= (sint32)time) return sub_80045EF4(object + 64);
    if ((r_u16(object + 142) & 0x3000) == 0x1000)
    {
        uint32 local = ob_draft_scratch_acquire(88);
        w_u32(local + 4, 0x10000001); w_u32(local + 32, 200);
        w_u32(local + 36, 0x4000); w_u32(local + 72, object); w_u32(local + 76, 0);
        ob_game_800C0F70(local, 26 * (r_u16(object + 142) & 0xFFF) + 1100, 1000);
        ob_batch9_shape(local, 0x403AB36, 0x800B7418);
        sub_8004651C(r_u32(object + 52));
        uint32 shape = sub_80046184(object, local, time);
        sint32 divisor = r_s16(object + 140) / 80;
        sint32 volume = 80 * (r_u16(object + 142) & 0xFFF);
        if (!divisor) ob_native_guest_break(0x800A5D30, 7);
        w_u32(object + 52, shape);
        ob_main_80011E20((uint32)r_s16(object + 136), r_u32(object + 44), (volume / divisor) & 255, time);
        ob_draft_scratch_release(local);
    }
    sub_800440B8(r_u32(object + 48), ((r_u16(object + 142) & 0xFFF) * 2) | 1);
    uint32 phase = r_u16(object + 142);
    uint32 next = phase - 1;
    if ((sint32)((phase & 0xFFF) - 1) >= 20)
    {
        w_u16(object + 142, next);
        if ((next & 0x3000) != 0x1000) w_u16(object + 142, phase - 2);
        w_u32(object + 92, time + 100);
        return sub_80045EF4(object + 64);
    }
    uint32 vector = ob_draft_scratch_acquire(12);
    uint32 x = r_u32(0x8008E1B4), y = r_u32(0x8008E1B8), z = r_u32(0x8008E1BC);
    w_u32(vector, x); w_u32(vector + 4, y); w_u32(vector + 8, z);
    if (r_s16(object + 136) != -1)
    {
        ob_game_800B9A28(r_u32(object + 44), vector, 300, 800, time);
        sub_8001195C((uint32)r_s16(object + 136));
        w_u16(object + 136, 65535);
    }
    uint32 result = ob_game_800B6C38(object);
    ob_draft_scratch_release(vector);
    return result;
}

uint32 ob_game_800A8F04(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800A8F04, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    if (!r_u32(data + 4))
    {
        uint32 count = (r_u8(data + 3) - 1) & 255;
        w_u8(data + 3, count);
        if (count) w_u32(data + 4, time + 64000 / count);
    }
    sint32 result = r_s16(object + 308);
    if (result > 0)
    {
        result = (sint32)ob_game_800A8FD0(object, 0, time);
        uint32 next = r_u32(data + 4);
        w_u32(data + 4, 0);
        if ((sint32)next > 0) return ob_game_800A9160(object, 0, next);
    }
    return (uint32)result;
}

uint32 ob_game_800A9950(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800A9950, "GAME.BIN");
    uint32 deadline = r_u32(object + 128);
    w_u16(object + 120, 65535);
    w_u32(object + 92, time + 100);
    w_u32(object + 28, time);
    if ((sint32)deadline >= (sint32)time)
    {
        if (r_u32(r_u32(object + 112) + 96) == 255)
        {
            uint32 model = r_u32(object + 48);
            sub_800440B8(model, (sint16)(r_u16(model + 160) + 32));
        }
        ob_game_800B9988(r_u32(object + 44), 300, time);
        return sub_80045EF4(object + 64);
    }
    sint32 phase = r_s16(object + 142);
    w_u32(object + 92, time + 180);
    if (phase != -1)
    {
        if ((sint32)(r_u32(object + 128) + 400) < (sint32)time) return ob_game_800B6C38(object);
        return sub_80045EF4(object + 64);
    }
    ob_main_80011A24(0x800666C0, (r_s16(object + 140) >> 4) - 32, 256, r_u32(object + 44), time, 0);
    if ((r_u32(r_u32(object + 56) + 208) & 8) && !(r_u32(object + 128) & 1))
    {
        ob_game_800B90B8(r_u32(object + 44), ob_batch9_scaled_size(object, 1000), 6, time);
        ob_game_800B9348(r_u32(object + 44), ob_batch9_scaled_size(object, 2000), 4, time);
        ob_game_800B9584(r_u32(object + 44), ob_batch9_scaled_size(object, 1000), 6, time);
    }
    ob_game_800B9584(r_u32(object + 44), ob_batch9_scaled_size(object, 2000), 6, time);
    sub_800440B8(r_u32(object + 48), 10);
    uint32 flags = r_u16(object + 138);
    w_u16(object + 142, 100);
    w_u16(object + 138, flags | 0x2000);
    uint32 local = ob_draft_scratch_acquire(88);
    w_u32(local + 4, 0x10000001); w_u32(local + 32, 200);
    w_u32(local + 72, object); w_u32(local + 76, 0);
    w_u32(local + 36, r_u32(r_u32(object + 52) + 136));
    ob_game_800C0F70(local, r_s16(object + 140), 2000);
    ob_batch9_shape(local, 0x2487EF36, 0x800B75F0);
    sub_8004651C(r_u32(object + 52));
    w_u32(object + 52, sub_80046184(object, local, time));
    uint32 result = sub_80045EF4(object + 64);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_800AD8A4(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800AD8A4, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    uint32 elapsed = time - r_u32(object + 28);
    if (elapsed)
    {
        uint32 node = r_u32(object + 44);
        w_u32(node + 136, r_u32(node + 136) - elapsed * 5);
        sub_80045ADC(r_u32(object + 44));
        sub_80045B74(r_u32(object + 44));
        w_u32(object + 28, time);
    }
    uint32 position = sub_80045464(r_u32(object + 44), time);
    uint32 player_position = sub_80045464(r_u32(r_u32(0x8006C134) + 44), time);
    if (r_s32(player_position + 4) < r_s32(position + 4))
    {
        w_u32(object + 92, time + 200);
        return sub_80045EF4(object + 64);
    }
    uint32 local = ob_draft_scratch_acquire(104);
    w_u32(local + 56, UINT32_MAX); w_u32(local + 44, 1666); w_u16(local + 60, 320);
    w_u32(local + 76, 0x4000); w_u16(local + 84, 50); w_u16(local + 86, 9);
    w_u8(local + 48, 0); w_u16(local + 50, 0); w_u16(local + 52, 0);
    w_u32(local + 88, 5000); w_u16(local + 92, 0); w_u32(local + 96, r_u32(object + 112));
    sub_80045378(r_u32(object + 44), time, local);
    player_position = sub_80045464(r_u32(r_u32(0x8006C134) + 44), time);
    w_u32(local + 4, r_u32(player_position + 4) + 500);
    for (uint32 i = 0; i < 9; ++i)
    {
        sub_80029F58((sint16)(i * 7281), local + 12);
        uint32 spawned = ob_game_800AF798(r_u32(object + 12), local, time);
        if (spawned)
        {
            uint32 actor = r_u32(r_u32(spawned + 112) + 80);
            sub_800465E8(r_u32(spawned + 52), r_u32(actor + 52));
            uint32 linked = r_u32(actor + 132);
            if (linked) sub_800465E8(r_u32(spawned + 52), r_u32(linked + 52));
        }
    }
    ob_main_80011A24(0x800666C0, 128, 256, r_u32(object + 44), time, 0);
    uint32 result = ob_game_800B6C38(object);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_800AF9B4(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800AF9B4, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    if (time != r_u32(object + 28))
    {
        uint32 voice = (uint32)r_s16(object + 136), node = r_u32(object + 44);
        w_u32(object + 28, time);
        ob_main_80011E20(voice, node, 64, time);
    }
    if (r_s32(object + 128) < (sint32)time) return ob_game_800B6C38(object);
    if (r_s32(r_u32(object + 44) + 112) <= 0)
    {
        ob_main_80011A24(0x80067240, 128, 256, r_u32(object + 44), time, 0);
        w_u32(r_u32(object + 44) + 112, 0);
        ob_game_800B8138(r_u32(object + 44), 0, time);
        return ob_game_800B6C38(object);
    }
    w_u32(object + 92, time + 200);
    return sub_80045EF4(object + 64);
}

uint32 ob_game_800B5A8C(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800B5A8C, "GAME.BIN");
    ob_main_80011E20((uint32)r_s16(object + 136), r_u32(object + 44), 160, time);
    ob_draft_unresolved_call(0x80011F24, 4, r_u32(object + 44), (uint32)r_s16(object + 136), 512, time);
    sub_80045A7C(r_u32(object + 44), time);
    uint32 result = r_u32(object + 28);
    if (time == result) return result;
    if (r_s32(object + 128) < (sint32)time) return ob_game_800B6C38(object);
    ob_game_800B83FC(r_u32(object + 44), 1, 0, time);
    w_u32(object + 28, time); w_u32(object + 92, time + 300);
    return sub_80045EF4(object + 64);
}

uint32 ob_game_800951F0(uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x800951F0, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(4);
    w_u32(local, 0);
    sub_800262CC(local, 160);
    uint32 object = r_u32(local);
    ob_game_80095254(object, owner, state, time);
    object = r_u32(local);
    ob_draft_scratch_release(local);
    return object;
}

uint32 ob_game_80095254(uint32 object, uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x80095254, "GAME.BIN");
    sub_80043600(object, owner, 0);
    w_u32(object, 0x800C5B58);
    ob_game_80095528(object, 14, 0x800B6C38, time);
    w_u32(object + 44, sub_80044E5C(object, 0x80073660, time));
    uint32 model = sub_80043E3C(object, 0x80073638);
    w_u32(object + 48, model);
    w_u32(r_u32(object + 44) + 8, 0x10000001);
    w_u32(r_u32(object + 48) + 48, 0x10000001);
    w_u32(r_u32(object + 48) + 40, 0x80067230);
    sub_80044130(r_u32(object + 48));
    uint32 y = r_u32(state + 4);
    w_u32(state + 4, 5);
    sub_800458B4(r_u32(object + 44), state, time);
    w_u32(state + 4, y);
    sub_800440B8(r_u32(object + 48), 192);
    ob_main_800285A4(state + 24, r_u32(state + 44), r_u32(object + 44) + 132);
    w_u32(r_u32(object + 44) + 136, 0);
    sub_80045ADC(r_u32(object + 44));
    uint32 local = ob_draft_scratch_acquire(8);
    w_u32(local, 0); w_u32(local + 4, 0);
    uint32 effect = sub_8004E518(object, local, time, 6);
    w_u32(object + 60, effect);
    ob_main_8004E694(effect, 2);
    w_u32(object + 104, 0);
    ob_draft_scratch_release(local);
    return object;
}

uint32 ob_game_8009FF7C(uint32 first, uint32 second)
{
    FUNCTION_MARKER(0x8009FF7C, "GAME.BIN");
    uint32 x = r_u32(first) - r_u32(second);
    if ((sint32)x < 0) x = 0 - x;
    uint32 y = r_u32(first + 4) - r_u32(second + 4);
    if ((sint32)y < 0) y = 0 - y;
    uint32 z = r_u32(first + 8) - r_u32(second + 8);
    if ((sint32)z < 0) z = 0 - z;
    uint32 length = x < z ? z + (x >> 1) : x + (z >> 1);
    return length < y ? y + (length >> 1) : length + (y >> 1);
}

uint32 ob_game_8009FA98(uint32 object, uint32 output, uint32 mode)
{
    FUNCTION_MARKER(0x8009FA98, "GAME.BIN");
    uint32 current = r_u32(0x800C84EC), best = 0;
    sint32 distance = 0x3FFFFFFF;
    while (current)
    {
        uint32 type = r_u32(current + 96);
        sint32 eligible = 0;
        if ((sint32)mode >= 0 && (sint32)mode < 2)
        {
            switch (type)
            {
            case 0: case 2: case 37: case 40: case 41: case 49: case 51: case 53:
            case 55: case 57: case 59: case 61: case 63: case 65: case 67: case 69:
            case 71: case 73: case 74: case 75: case 76: case 77: case 149: case 153:
            case 156: case 159: case 160: case 161: case 164: case 166: case 167:
            case 168: case 174: case 175: case 229: case 230: case 231: case 233:
            case 234: case 235: case 236: case 237: case 239: case 240: case 241:
            case 242: case 248: case 249: case 254: break;
            default: eligible = current != r_u32(object + 112); break;
            }
        }
        else if (mode == 2 && (type == 76 || type == 68 || type == 255))
        {
            uint32 own = r_u32(object + 112), own_type = r_u32(own + 96);
            eligible = 1;
            if (own_type == 66 || own_type == 75)
            {
                sint32 angle = (sint16)ob_game_800A8A40(r_u32(own + 80), r_u32(current + 80), r_u32(0x80077334));
                sint32 second = (sint16)ob_game_800A8A40(r_u32(r_u32(object + 112) + 80), r_u32(current + 80), r_u32(0x80077334));
                eligible = (angle < 0 ? -second : second) < 3640;
            }
        }
        if (eligible)
        {
            uint32 actor = r_u32(current + 80);
            if (r_u8(r_u32(actor + 60) + 54) != 1 && r_u32(actor + 288) != 3 && r_u32(actor + 288) != 1)
            {
                sint32 candidate = (sint32)ob_game_8009FF7C(r_u32(object + 44) + 80, r_u32(actor + 44) + 80);
                if (candidate < distance) { distance = candidate; best = current; }
            }
        }
        current = r_u32(current + 76);
    }
    uint32 local = ob_draft_scratch_acquire(56);
    sub_80029E80((sint16)ob_main_8001AFC8(), local + 24);
    if (best && r_s16(object + 140) * 3 / 2 >= distance)
    {
        for (uint32 offset = 0; offset < 12; offset += 4)
            w_u32(output + offset, r_u32(r_u32(r_u32(best + 80) + 44) + 80 + offset) - r_u32(r_u32(object + 44) + 80 + offset));
        if (r_s16(object + 140) < distance)
        {
            if (!distance) ob_native_guest_break(0x8009FA98, 7);
            sint32 value = (sint32)(r_u32(output) * (uint32)r_s16(object + 140));
            if (distance == -1 && value == INT32_MIN) ob_native_guest_break(0x8009FA98, 6);
            w_u32(output, (uint32)(value / distance));
            value = (sint32)(r_u32(output + 8) * (uint32)r_s16(object + 140));
            if (distance == -1 && value == INT32_MIN) ob_native_guest_break(0x8009FA98, 6);
            w_u32(output + 8, (uint32)(value / distance));
            distance = r_s16(object + 140);
        }
    }
    else
    {
        distance = 6000;
        uint32 index = ((((sub_8001B008() * 2) & 65535) + 8) >> 4) * 2;
        w_u32(output, (uint32)((r_s16(0x8006C304 + index) * 375) >> 10));
        w_u32(output + 4, 0 - r_u32(r_u32(object + 44) + 84));
        w_u32(output + 8, (uint32)((r_s16(0x8006CB04 + index) * 375) >> 10));
    }
    sub_800440B8(r_u32(object + 48), (sint16)(distance / 19));
    sint32 angle = (sint16)sub_80027F98(distance, r_u32(output + 4));
    ob_main_8002ACA8(local + 24, angle, local);
    angle = (sint16)(0 - sub_80027F98(r_u32(output), r_u32(output + 8)));
    sub_8002AF54(local, angle, local + 24);
    uint32 result = sub_80045848(r_u32(object + 44), local + 24);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_800A8FD0(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800A8FD0, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(96);
    sub_80029E54(local + 12);
    uint32 position = sub_80045464(r_u32(object + 44), time);
    w_u32(local + 44, 0x800C48E4); w_u8(local + 92, 12); w_u8(local + 93, 4);
    w_u32(local + 48, 0); w_u32(local + 60, 0); w_u8(local + 94, 0); w_u32(local + 76, 2);
    uint32 result = ob_game_800A9058(object, local, position, time);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_800A9058(uint32 object, uint32 record, uint32 position, uint32 time)
{
    FUNCTION_MARKER(0x800A9058, "GAME.BIN");
    w_u32(record + 56, 750 * ((ob_main_8001AFC8() & 7) + 8));
    uint32 random = ob_main_8001AFC8() & 511;
    w_u32(record, r_u32(position) + random - 256);
    w_u32(record + 4, r_u32(position + 4) + 1100);
    random = ob_main_8001AFC8() & 511;
    w_u32(record + 8, r_u32(position + 8) + random - 256);
    w_u32(record + 32, (ob_main_8001AFC8() & 127) - 64);
    w_u32(record + 36, (ob_main_8001AFC8() & 255) + 128);
    w_u32(record + 40, (ob_main_8001AFC8() & 127) - 64);
    w_u16(record + 86, 280); w_u16(record + 88, 560); w_u16(record + 90, 280);
    return ob_game_80092408(r_u32(0x80083E34), record, time, 6);
}

uint32 ob_game_800947B8(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800947B8, "GAME.BIN");
    if ((sint32)(time - r_u32(object + 28)) >= 201)
    {
        sub_80045A7C(r_u32(object + 44), time);
        ob_game_80097E28(0, object, time);
        ob_game_800B9EB8(object, time);
        uint32 parameters = r_u32(object + 124);
        ob_game_800BA108(object, parameters + 4, r_u32(parameters), r_u32(object + 44));
        w_u32(object + 28, time);
    }
    if ((sint32)time >= (sint32)(r_u32(object + 332) + 250)) ob_game_8009231C(object, 4, time);
    ob_game_800916A0(object, time);
    return ob_game_800C0744(object, 0, time + r_s16(object + 308));
}

uint32 ob_game_80094BBC(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x80094BBC, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    uint32 elapsed = time - r_u32(object + 28);
    if (!elapsed) return 3;
    if (r_u32(object + 288) == 3) ob_game_80094CC0(object, time);
    else
    {
        ob_game_800B9EB8(object, time);
        uint32 parameters = r_u32(object + 124);
        ob_game_800BA108(object, parameters + 4, r_u32(parameters), r_u32(object + 44));
        ob_game_800C0744(object, 0, time + r_s16(object + 308));
    }
    uint32 result = 157;
    if (r_u32(object + 292) == 157)
    {
        result = r_u32(object + 316) - elapsed;
        w_u32(object + 316, result);
        if ((sint32)result < 0)
        {
            ob_main_80011A24(0x80067124, 32, 256, r_u32(object + 44), time, 0);
            result = r_u32(object + 316) + 2500;
            w_u32(object + 316, result);
        }
    }
    w_u32(object + 28, time);
    return result;
}

uint32 ob_game_80094EF8(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x80094EF8, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    uint32 data = r_u32(object + 108);
    if (time != r_u32(object + 28))
    {
        uint32 type = r_u32(object + 292);
        if (type >= 162 && type < 164 && r_u32(data) && r_u32(data + 4) < time + 50)
        {
            uint32 local = ob_draft_scratch_acquire(48);
            sub_80029EEC(0, local);
            sub_8002A9DC(local, r_s16(data + 10), local + 24);
            sub_8002AF54(local + 24, 0, local);
            sub_80045848(r_u32(r_u32(data) + 4), local);
            ob_game_800A9E48(r_u32(data));
            w_u32(data, 0);
            ob_draft_scratch_release(local);
        }
        w_u32(object + 28, time);
    }
    return ob_game_800C0744(object, 0, time + r_s16(object + 308));
}

uint32 ob_game_80096BB4(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x80096BB4, "GAME.BIN");
    if (time != r_u32(object + 28)) ob_game_80096C14(object, 1500, 500, time);
    uint32 result = ob_game_800C0744(object, 0, time + r_s16(object + 308));
    w_u32(object + 28, time);
    return result;
}

uint32 ob_game_800980CC(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800980CC, "GAME.BIN");
    ob_game_80097FD8(object);
    ob_game_80098088(object, 1, time);
    uint32 record = r_u32(object + 116);
    w_u8(record + 111, 0);
    return record;
}

uint32 ob_game_8009811C(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x8009811C, "GAME.BIN");
    ob_game_80098030(object);
    return ob_game_80098088(object, 1, time);
}

void ob_game_80099020(void)
{
    FUNCTION_MARKER(0x80099020, "GAME.BIN");
}

void ob_game_80099028(void)
{
    FUNCTION_MARKER(0x80099028, "GAME.BIN");
}

uint32 ob_game_80099324(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x80099324, "GAME.BIN");
    uint32 record = r_u32(object + 116);
    if (r_s16(record + 106) == -1 && r_u8(record) == 4) return 4;
    if (r_u32(object + 292) == 33 && r_u8(record) == 4)
    {
        w_u32(record + 12, time + 1000);
        record = r_u32(object + 116);
        if (r_u32(record + 56) < r_u32(0x800C831C))
        {
            w_u32(record + 12, time - 1000);
            record = r_u32(object + 116);
        }
    }
    else record = r_u32(object + 116);
    if (r_u32(record + 12) >= time) return 5;
    ob_game_80097FC4(record, r_u8(record + 16));
    record = r_u32(object + 116);
    if (r_u8(record) != 5) return 2;
    w_u8(record + 16, 2);
    record = r_u32(object + 116);
    uint32 result = time + r_s16(record + 108);
    w_u32(record + 12, result);
    return result;
}

uint32 ob_game_80099438(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x80099438, "GAME.BIN");
    uint32 type = r_u32(object + 292);
    if (type - 2 >= 32) return 0;
    if (type == 2 || (type >= 20 && type <= 31)) return ob_game_800ABCD4(object, time);
    if (type == 3 || type == 10) return ob_game_80091C9C(object, r_u32(object + 116), time);
    return 0x8009948C;
}

void ob_game_8009231C(uint32 object, uint32 frames, uint32 time)
{
    FUNCTION_MARKER(0x8009231C, "GAME.BIN");
    sint32 divisor = (sint16)frames;
    if (!divisor) return;
    sint32 frame = (sint16)(r_u16(object + 336) + 1) % divisor;
    uint32 state = r_u32(object + 112);
    w_u16(object + 336, frame);
    if (frame == 0 || frame == 2) w_u32(r_u32(object + 48) + 40, r_u32(state + 12));
    else if (frame == 1) w_u32(r_u32(object + 48) + 40, r_u32(state + 16));
    else if (frame == 3) w_u32(r_u32(object + 48) + 40, r_u32(state + 20));
    w_u32(object + 332, time);
}

uint32 ob_game_80097FD8(uint32 object)
{
    FUNCTION_MARKER(0x80097FD8, "GAME.BIN");
    uint32 record = r_u32(object + 116), count = r_u8(record + 2);
    uint32 tail = record + count;
    if (!count)
    {
        uint32 state = r_u8(record + 1);
        w_u8(record + 2, count + 1); w_u8(record + 3, state);
    }
    else if (r_u8(tail + 2) != r_u8(record + 1))
    {
        uint32 state = r_u8(record + 1);
        w_u8(record + 2, count + 1); w_u8(tail + 3, state);
    }
    return count + 1;
}

uint32 ob_game_80098030(uint32 object)
{
    FUNCTION_MARKER(0x80098030, "GAME.BIN");
    uint32 record = r_u32(object + 116), count = r_u8(record + 2);
    if (!count) return UINT32_MAX;
    uint32 result = count - 1;
    w_u8(record + 2, result);
    uint32 state = r_u8(record + (result & 255) + 3);
    result = record + r_u8(record + 2);
    w_u8(record + 1, state);
    state = r_u8(result + 3);
    result = record + r_u8(record + 2);
    w_u8(record, state); w_u8(result + 3, 0);
    return result;
}

uint32 ob_game_800B9EB8(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800B9EB8, "GAME.BIN");
    sint32 phase = (sint32)((r_u32(object + 156) + time) & 0xFFF) - 2048;
    w_u32(object + 148, phase);
    sint32 change = -1;
    if (phase >= 1025)
    {
        w_u32(object + 148, 2048 - phase);
        if (!r_u32(object + 160) && r_u32(object + 164)) change = 1;
    }
    else if (phase < -1024)
    {
        if (r_u32(object + 160) == 1 && r_u32(object + 164)) change = 0;
    }
    if (change != -1)
    {
        if (r_u32(object + 292) == 157)
        {
            sint32 divisor = 5 - r_s32(object + 164) / 48;
            if (!divisor) ob_native_guest_break(0x800B9EB8, 7);
            ob_main_80011A24(0x80066520, 128 / divisor, 256, r_u32(object + 44), time, 0);
        }
        w_u32(object + 160, change);
    }
    if (phase < -1024) w_u32(object + 148, 0 - 2048 - r_u32(object + 148));
    uint32 wave = (r_u32(object + 156) + time) & 1023;
    w_u32(object + 152, wave);
    uint32 result = wave < 513 ? 1 : 1024 - wave;
    if (wave >= 513) w_u32(object + 152, result);
    result = r_u32(object + 164) + 64;
    if (r_u32(object + 164))
    {
        uint32 x = r_u32(object + 148) * result;
        uint32 y = r_u32(object + 152) * (r_u32(object + 164) + 64);
        w_u32(object + 148, x); w_u32(object + 152, y);
        w_u32(object + 148, (uint32)((sint32)x / 64));
        w_u32(object + 152, (uint32)((sint32)y / 64));
        result = r_u32(object + 164) - 4;
        w_u32(object + 164, result);
    }
    return result;
}

static uint32 ob_batch9_child_node(uint32 object)
{
    return r_u32(r_u32(r_u32(object + 48) + 32) + 52);
}

uint32 ob_game_80096C14(uint32 object, uint32 forward, uint32 backward, uint32 time)
{
    FUNCTION_MARKER(0x80096C14, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    sub_80045A7C(ob_batch9_child_node(object), time);
    sub_80045A7C(ob_batch9_child_node(r_u32(object + 136)), time);
    uint32 linked = r_u32(r_u32(object + 108));
    sub_80045A7C(r_u32(linked + 44), time);
    uint32 local = ob_draft_scratch_acquire(32);
    sub_80045378(r_u32(object + 44), time, local);
    sub_80045378(ob_batch9_child_node(object), time, local + 16);
    sint32 heading = r_s16(object + 296);
    uint32 x = 0, z = 0;
    if (heading == -16384 || heading == 16384 || heading == 0 || heading == -32768)
    {
        uint32 first = heading == 0 || heading == -32768 ? local + 8 : local;
        uint32 second = heading == 0 || heading == -32768 ? local + 24 : local + 16;
        sint32 distance = (sint32)((heading == -16384 || heading == -32768) ?
            r_u32(first) - r_u32(second) : r_u32(second) - r_u32(first));
        uint32 speed = forward;
        if (r_u8(object + 323))
        {
            if (distance >= 1001) speed = 0 - backward;
            else
            {
                uint32 voice = (uint32)r_s16(object + 306);
                w_u8(object + 323, 0);
                ob_main_80011D80(voice, 256);
            }
        }
        else if (distance >= 4501)
        {
            speed = 0 - backward;
            uint32 voice = (uint32)r_s16(object + 306);
            w_u8(object + 323, 1);
            ob_main_80011D80(voice, 128);
        }
        if (heading == -16384 || heading == 16384) x = speed;
        else z = speed;
    }
    w_u32(ob_batch9_child_node(object) + 132, 0);
    sint32 speed = (sint16)x + (sint16)z;
    w_u32(ob_batch9_child_node(object) + 140, speed);
    sub_80045ADC(ob_batch9_child_node(object));
    sub_80045B74(ob_batch9_child_node(object));
    w_u32(ob_batch9_child_node(r_u32(object + 136)) + 132, 0);
    w_u32(ob_batch9_child_node(r_u32(object + 136)) + 140, speed);
    sub_80045ADC(ob_batch9_child_node(r_u32(object + 136)));
    sub_80045B74(ob_batch9_child_node(r_u32(object + 136)));
    uint32 index = ((r_u16(object + 296) + 8) >> 4) * 2;
    w_u32(r_u32(linked + 44) + 132, (sint16)x * (r_s16(0x8006C304 + index) >> 14));
    index = ((r_u16(object + 296) + 8) >> 4) * 2;
    w_u32(r_u32(linked + 44) + 140, (sint16)z * (r_s16(0x8006CB04 + index) >> 14));
    sub_80045ADC(r_u32(linked + 44));
    uint32 result = sub_80045B74(r_u32(linked + 44));
    ob_draft_scratch_release(local);
    return result;
}

void ob_game_8009DC50(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x8009DC50, "GAME.BIN");
    w_u32(object + 316, time);
}

void ob_game_800A06D4(void)
{
    FUNCTION_MARKER(0x800A06D4, "GAME.BIN");
}

void ob_game_800A0734(void)
{
    FUNCTION_MARKER(0x800A0734, "GAME.BIN");
}

void ob_game_800A073C(void)
{
    FUNCTION_MARKER(0x800A073C, "GAME.BIN");
}

void ob_game_800A0744(void)
{
    FUNCTION_MARKER(0x800A0744, "GAME.BIN");
}

void ob_game_800A2318(void)
{
    FUNCTION_MARKER(0x800A2318, "GAME.BIN");
}

void ob_game_800A7D8C(void)
{
    FUNCTION_MARKER(0x800A7D8C, "GAME.BIN");
}

void ob_game_800AA890(void)
{
    FUNCTION_MARKER(0x800AA890, "GAME.BIN");
}

uint32 ob_game_800A067C(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800A067C, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    uint32 entry = r_u32(data + 4) + (uint32)(r_s16(data + 32) * 24);
    return ob_main_80011A24(r_u32(entry + 16), 112, 512, r_u32(object + 44), time, 0);
}

uint32 ob_game_800A06DC(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800A06DC, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    uint32 entry = r_u32(data + 4) + (uint32)(r_s16(data + 32) * 24);
    return ob_main_80011A24(r_u32(entry + 16), 112, 512, r_u32(object + 44), time, 0);
}

uint32 ob_game_800A2320(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800A2320, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    uint32 entry = r_u32(data + 4) + (uint32)(r_s16(data + 32) * 24);
    return ob_main_80011A24(r_u32(entry + 16), 144, 256, r_u32(object + 44), time, 0);
}

uint32 ob_game_800A2378(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800A2378, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    uint32 entry = r_u32(data + 4) + (uint32)(r_s16(data + 32) * 24);
    return ob_main_80011A24(r_u32(entry + 16), 144, 128, r_u32(object + 44), time, 0);
}

uint32 ob_game_8009DC1C(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x8009DC1C, "GAME.BIN");
    w_u32(object + 288, 31); w_u32(object + 316, time + 2000);
    return 31;
}

uint32 ob_game_8009DC30(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x8009DC30, "GAME.BIN");
    if (r_u32(object + 288) != 3)
    {
        w_u32(object + 288, 31); w_u32(object + 316, time);
    }
    return 31;
}

uint32 ob_game_8009DDA8(void)
{
    FUNCTION_MARKER(0x8009DDA8, "GAME.BIN");
    sub_8001DDF8();
    ob_main_80012164(127);
    return sub_80011984(0x8006A980, 128, 15, 15, 256, 0, 0);
}

uint32 ob_game_8009DDF8(void)
{
    FUNCTION_MARKER(0x8009DDF8, "GAME.BIN");
    return ob_main_8001DE60();
}

uint32 ob_game_800A2428(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800A2428, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    if (r_s16(object + 306) != -1) return 1;
    uint32 entry = r_u32(data + 4) + (uint32)(r_s16(data + 32) * 24);
    uint32 result = ob_main_80011A24(r_u32(entry + 16), 144, 256, r_u32(object + 44), time, 1);
    w_u16(object + 306, result);
    return result;
}

uint32 ob_game_800A2498(uint32 object, uint32 incoming_mask)
{
    FUNCTION_MARKER(0x800A2498, "GAME.BIN");
    ob_stop_sound_with_mask((uint32)r_s16(object + 306), incoming_mask);
    w_u16(object + 306, 65535);
    return UINT32_MAX;
}

uint32 ob_game_800A7354(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800A7354, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    uint32 data = r_u32(object + 108);
    ob_game_800A20D0(object, r_u8(data + 44), 65575, time);
    uint32 index = r_u8(data + 44);
    w_u32(data + 12, time);
    uint32 actor = r_u32(0x800D5C98 + index * 4);
    ob_main_80011E20((uint32)r_s16(actor + 306), r_u32(actor + 44), 255, time);
    w_u32(object + 92, time + 150);
    return sub_80045EF4(object + 64);
}

uint32 ob_game_800AA684(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800AA684, "GAME.BIN");
    if (r_u32(object + 288) == 30)
    {
        w_u32(object + 288, 32);
        return 32;
    }
    uint32 data = r_u32(object + 108);
    w_u16(data + 34, r_u16(data + 34) + 25);
    w_u32(object + 288, 30);
    sub_80045F20(object + 64);
    ob_game_800BCB90(object, 0, time + 50);
    return ob_main_80011A24(0x800698C4, 144, 256, r_u32(object + 44), time, 0);
}

uint32 ob_game_800AA72C(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800AA72C, "GAME.BIN");
    return ob_game_800A9FDC(object, time);
}

uint32 ob_game_800A7B2C(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800A7B2C, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    uint32 position = r_u32(r_u32(data) + 20);
    uint32 state = r_u32(object + 288);
    if (state == 26 || state == 27)
    {
        uint32 moving = 1;
        if (state == 26)
        {
            position -= 200;
            sint32 limit = -60 * r_s16(object + 304);
            if (limit >= (sint32)position)
            {
                position = (uint32)limit; w_u32(object + 288, 25);
            }
        }
        else
        {
            position += 200;
            if ((sint32)position >= 0)
            {
                w_u32(object + 288, 24); position = 0; moving = 0;
            }
        }
        ob_game_800A9E30(r_u32(data), 0, 0, position, moving);
    }
    uint32 result = time + 200;
    if (r_u32(object + 288) - 26 < 2)
    {
        w_u32(object + 92, result);
        return sub_80045EF4(object + 64);
    }
    return result;
}

uint32 ob_game_800ABCD4(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800ABCD4, "GAME.BIN");
    uint32 type = r_u32(object + 292), state = r_u32(object + 112), result;
    if (type == 20 || type == 23 || type == 26)
        return ob_game_800AB9F8(object, r_u32(object + 116), time);
    if (type == 27)
    {
        if (r_u32(0x800C90FC) >= 9000) return 0;
        result = ob_game_800ABF74(r_s16(object + 298), 0x800C90F8, 4096);
        if (!result) return result;
        if ((uint32)r_u16(object + 298) - 2048 >= 0x7000 && ob_game_800B5C50(0, r_u32(object + 120), time))
        {
            w_u16(r_u32(state + 32), r_u16(object + 298));
            ob_game_800B5CB4(object, 0, 0, time);
        }
        if ((uint16)(r_u16(object + 298) + 30719) < 0x7000) return 1;
        result = ob_game_800B5C50(1, r_u32(object + 120), time);
        if (!result) return result;
        w_u16(r_u32(state + 36), r_u16(object + 298));
        return ob_game_800B5CB4(object, 1, 0, time);
    }
    if (type == 30)
    {
        result = ob_game_800ABCA0(object, time);
        if (!result) return result;
    }
    if (type == 22 || type == 25 || type == 28 || type == 30)
    {
        if (r_u32(0x800C90FC) >= 9000) return 0;
        result = ob_game_800ABF74(r_s16(object + 298), 0x800C90F8, 4096);
        if (!result) return result;
        w_u16(r_u32(r_u32(object + 112) + 32), r_u16(object + 298));
        result = ob_game_800B5C50(0, r_u32(object + 120), time);
        if (!result) return result;
        return ob_game_800B5CB4(object, 0, 0, time);
    }
    if (type == 31)
    {
        if ((sint32)time % 5000 < 3001) return 1;
        result = ob_game_800B5C50(0, r_u32(object + 120), time);
        if (!result) return result;
        return ob_game_800B5CB4(object, 0, 0, time);
    }
    if (type == 2 || type == 21 || type == 24 || type == 29)
    {
        if (r_u32(0x800C90FC) >= (uint32)(type == 24 ? 8000 : 11000)) return 0;
        result = ob_game_800ABF74(0, 0x800C90F8, 2048);
        if (!result) return result;
        result = ob_game_800B5C50(0, r_u32(object + 120), time);
        if (!result) return result;
        w_u16(r_u32(state + 32), 0);
        return ob_game_800B5CB4(object, 0, 0, time);
    }
    return type - 2 >= 30 ? 0 : 0x800ABF58;
}

uint32 ob_game_800A9FDC(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800A9FDC, "GAME.BIN");
    uint32 player = r_u32(0x8006C134);
    uint32 first = sub_80045464(r_u32(player + 44), time);
    uint32 second = sub_80045464(r_u32(object + 44), time);
    uint32 local = ob_draft_scratch_acquire(8);
    sub_80028280(r_u32(second + 8) - r_u32(first + 8), r_u32(second) - r_u32(first), local, local + 4);
    sint32 heading = r_s16(r_u32(object + 124) + 4);
    sint32 angle = r_s16(local) - heading;
    if (angle < 0) angle = -angle;
    uint32 action = 0;
    sint32 apply = 1;
    if (r_u32(local + 4) < 25000)
    {
        if (r_s32(object + 316) < (sint32)time)
        {
            ob_game_800AA898(r_u32(object + 44), time);
            w_u32(object + 316, time + 2500);
            ob_game_800A1BD4(object, 0);
        }
        if ((uint16)(angle - 16385) >= 0x7FFF) apply = 0;
        else if (r_u32(local + 4) < 15000)
        {
            if ((uint16)(angle - 28673) >= 0x1FFF || r_u32(local + 4) < 9001) action = 5;
            else if (r_s32(object + 316) < (sint32)time)
            {
                ob_game_800A1BD4(object, 3);
                w_u32(object + 316, time + 10000);
                apply = 0;
            }
            else apply = 0;
        }
        else if ((uint16)(angle - 32257) < 0x3FF) action = 1;
        else if ((uint16)(angle - 26625) < 0x2FFF) action = 2;
        else if (!((time >> 5) & 3)) action = 7;
    }
    if (apply) ob_game_800A1BD4(object, action);
    w_u32(object + 288, 18);
    ob_draft_scratch_release(local);
    return 18;
}
