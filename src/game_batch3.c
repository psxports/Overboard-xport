#include "xport.h"
#include "psx.h"
#include "game_signatures.h"
#include "native_extra_signatures.h"
#include "draft_signatures.h"
#include "movie_player.h"

uint32 ob_main_80015D40(uint32 input, uint32 output, uint32 capacity)
{
    FUNCTION_MARKER(0x80015D40, "SLES_008.65");
    uint32 character;
    do
    {
        uint32 previous = capacity;
        --capacity;
        character = (sint32)previous >= 2 ? r_u8(input) : 0;
        if (character >= 0x81)
        {
            uint32 second = r_u8(input + 1);
            input += 2;
            w_u8(output++, ob_main_80015F24((character << 8) | second));
        }
        else
        {
            w_u8(output++, character);
            ++input;
        }
    } while (character);
    if ((sint32)capacity > 0) w_u8(output, 0);
    return capacity;
}

uint32 ob_main_80017618(uint32 text, uint32 x, uint32 y, uint32 style)
{
    FUNCTION_MARKER(0x80017618, "SLES_008.65");
    uint32 red, green, blue, flags = 0;
    switch (style)
    {
    case 0: red = 52; green = 44; blue = 30; break;
    case 1: red = 128; green = 128; blue = 128; break;
    case 2: red = 52; green = 44; blue = 30; flags = 1; break;
    case 3: red = 96; green = 32; blue = 32; break;
    case 4: red = 108; green = 96; blue = 32; break;
    default: return 0;
    }
    return ob_draft_unresolved_call(0x80013A6C, 7, text, x, y, red, green, blue, flags);
}

uint32 ob_game_800ADB68(uint32 object)
{
    FUNCTION_MARKER(0x800ADB68, "GAME.BIN");
    uint32 handle = ob_draft_scratch_acquire(4);
    w_u32(handle, object);
    if (r_s16(object + 44)) ob_game_800ADD1C(object);
    uint32 head = r_u32(0x800C84F0);
    object = r_u32(handle);
    if (head == object)
        w_u32(0x800C84F0, r_u32(object));
    else
    {
        uint32 previous = head;
        while (r_u32(previous) != object) previous = r_u32(previous);
        w_u32(previous, r_u32(r_u32(handle)));
    }
    object = r_u32(handle);
    ob_game_8009F6A4(r_u32(object + 16));
    uint32 result = ob_draft_unresolved_call(0x800263B4, 1, handle);
    ob_draft_scratch_release(handle);
    return result;
}

uint32 ob_game_800BB8A4(uint32 object, uint32 record)
{
    FUNCTION_MARKER(0x800BB8A4, "GAME.BIN");
    sub_80047FF0(record);
    uint32 result = r_u32(record + 28) & 0x8020;
    if (result)
    {
        uint32 slot = (uint32)(sint32)r_s16(object + 326);
        uint32 selector = r_u16(0x800CBA34 + slot * 104);
        uint32 bits = r_u16(0x80089B24);
        w_u16(0x80089B24, bits | ((uint32)1 << (selector & 31)));
        sub_80011984(0x8006647C, 128, 15, 15, 256, 0, 0);
        ob_game_800A4AC8(selector);
        result = ob_game_800BCAA0(object);
    }
    return result;
}

uint32 ob_game_800AC338(uint32 object)
{
    FUNCTION_MARKER(0x800AC338, "GAME.BIN");
    if (r_u8(r_u32(0x80077190) + 40) != 2) return 2;
    uint32 kind = r_u32(object + 292);
    if (kind - 21 >= 10) return 0;
    uint32 result;
    switch (kind)
    {
    case 21: result = 0x80069608; break;
    case 22: result = 0x8006960C; break;
    case 23: result = 0x800693CC; break;
    case 25: result = 0x80069414; break;
    case 27: result = 0x80069610; break;
    case 28: result = 0x80069614; break;
    case 30: result = 0x80069618; break;
    default: return 0x800AC40C;
    }
    w_u32(r_u32(object + 48) + 40, result);
    return result;
}

uint32 ob_game_800B8F08(uint32 first, uint32 second, uint32 radius, uint32 strength)
{
    FUNCTION_MARKER(0x800B8F08, "GAME.BIN");
    if (strength & 0x2000) return 0;
    sint32 distance = (sint32)ob_game_80099798(first + 108, second + 108);
    sint32 limit = (sint16)radius;
    if (distance >= limit) return 0;
    uint32 difference = (uint32)limit - (uint32)distance;
    sint32 product = (sint32)(difference * (uint32)(sint32)(sint16)strength);
    if (!limit) return ob_native_missing_value(0x800B8F08, "BREAK 7 signed division by zero");
    if (limit == -1 && product == INT32_MIN)
        return ob_native_missing_value(0x800B8F08, "BREAK 6 signed division overflow");
    return (uint32)(sint32)(sint16)(product / limit);
}

uint32 ob_game_800A200C(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800A200C, "GAME.BIN");
    uint32 kind = r_u32(object + 292);
    uint32 data = r_u32(object + 108);
    uint32 result = 36;
    if (kind == 33)
    {
        if (r_u16(data + 36) != 0xFFFF)
            ob_draft_unresolved_call(0x800A20D0, 4, object, r_u8(data + 44), 0x100BF, time);
        result = r_u16(data + 38);
        if (result != 0xFFFF)
            result = ob_draft_unresolved_call(0x800A20D0, 4, object, r_u8(data + 45), 0x100C3, time);
    }
    else if (kind == 36)
        result = ob_draft_unresolved_call(0x800A20D0, 4, object, r_u8(data + 44), 0x1018C, time);
    w_u32(data + 12, time);
    return result;
}

uint32 ob_game_800A6D2C(uint32 node, uint32 time)
{
    FUNCTION_MARKER(0x800A6D2C, "GAME.BIN");
    uint32 attributes = ob_draft_scratch_acquire(96);
    sub_80029E54(attributes + 12);
    uint32 position = sub_80045464(node, time);
    uint32 owner = r_u32(0x80083E34);
    w_u32(attributes + 48, 0);
    w_u32(attributes, r_u32(position));
    w_u32(attributes + 4, r_u32(position + 4));
    uint32 z = r_u32(position + 8);
    w_u32(attributes + 76, 1);
    w_u32(attributes + 44, 0x800C4A74);
    w_u32(attributes + 56, 150);
    w_u32(attributes + 40, 0);
    w_u32(attributes + 36, 0);
    w_u32(attributes + 32, 0);
    w_u32(attributes + 60, 0);
    w_u8(attributes + 93, 1);
    w_u8(attributes + 94, 0);
    w_u8(attributes + 92, 1);
    w_u16(attributes + 86, 200);
    w_u16(attributes + 88, 200);
    w_u16(attributes + 90, 200);
    w_u32(attributes + 8, z);
    uint32 result = ob_game_80092408(owner, attributes, time, 6);
    ob_draft_scratch_release(attributes);
    return result;
}

uint32 ob_game_8009DE18(uint32 object, uint32 unused, uint32 time)
{
    FUNCTION_MARKER(0x8009DE18, "GAME.BIN");
    uint32 node = r_u32(object + 44);
    uint32 data = r_u32(object + 56);
    sub_80045A7C(node, time);
    if (r_s16(data + 164))
    {
        node = r_u32(object + 44);
        w_u32(node + 132, 0 - r_u32(node + 132));
    }
    if (r_s16(data + 168))
    {
        node = r_u32(object + 44);
        w_u32(node + 140, 0 - r_u32(node + 140));
    }
    sub_80045ADC(r_u32(object + 44));
    return ob_main_80011A24(0x80067228, 64, 192, r_u32(object + 44), time, 0);
}

uint32 ob_game_800ADDA8(uint32 object, uint32 selector, uint32 time)
{
    FUNCTION_MARKER(0x800ADDA8, "GAME.BIN");
    sub_80045A7C(r_u32(object + 12), time);
    uint32 position = ob_draft_scratch_acquire(16);
    uint32 index = (uint32)(sint32)(sint16)selector;
    uint32 table = r_u32(object + 24) + index * 12;
    sub_800453C4(r_u32(object + 12), time, position);
    uint32 height = r_u32(table + 8);
    uint32 previous = r_u32(object + 60);
    w_u32(position + 4, r_u32(position + 4) - (height - previous));
    sub_800458B4(r_u32(object + 12), position, time);
    w_u32(object + 52, r_u32(table));
    w_u32(object + 56, r_u32(table + 4));
    uint32 result = r_u32(table + 8);
    w_u32(object + 60, result);
    ob_draft_scratch_release(position);
    return result;
}

uint32 ob_game_800BA108(uint32 object, uint32 angles, uint32 distance, uint32 node)
{
    FUNCTION_MARKER(0x800BA108, "GAME.BIN");
    uint32 locals = ob_draft_scratch_acquire(80);
    uint32 first = locals;
    uint32 vector = locals + 24;
    uint32 position = locals + 40;
    uint32 second = locals + 56;
    w_u32(vector + 4, 0);
    w_u32(vector, 0);
    w_u32(vector + 8, distance);
    sub_80029EEC((uint32)(sint32)r_s16(object + 148), second);
    sub_8002AF54(second, (uint32)(sint32)r_s16(angles), first);
    sub_80029B70(vector, first, position);
    uint32 negative = 0 - r_u32(object + 152);
    sub_8002A9DC(first, (uint32)(sint32)(sint16)negative, second);
    sub_80045848(node, second);
    sub_80045B74(node);
    uint32 result = sub_80045A44(node, position);
    ob_draft_scratch_release(locals);
    return result;
}

uint32 ob_main_8001D404(void)
{
    FUNCTION_MARKER(0x8001D404, "SLES_008.65");
    uint32 data = r_u32(r_u32(0x8006C138) + 108);
    for (uint32 index = 0; index < 13; ++index)
    {
        if (!r_s8(data + index + 106))
        {
            w_u8(0x800899CE + index, 0);
            w_u8(0x800899DB + index, 0);
        }
        else
        {
            w_u8(0x800899CE + index, 1);
            w_u8(0x800899DB + index, r_u8(data + index + 130));
        }
    }
    for (uint32 index = 0; index < 5; ++index)
        w_u16(0x800899E8 + index * 2, r_u16(data + 120 + index * 2));
    uint32 selected = r_u8(data + 44);
    uint32 player = r_u32(0x8006C138);
    w_u8(0x800899F2, selected);
    uint32 slot = (uint32)(sint32)r_s16(player + 326);
    uint32 result = r_u16(0x800CBA46 + slot * 104);
    w_u16(0x800899F6, result);
    return result;
}

void ob_main_8003DCDC(uint32 list)
{
    FUNCTION_MARKER(0x8003DCDC, "SLES_008.65");
    uint32 node = r_u32(list);
    while (node)
    {
        uint32 previous = r_u32(0x80077634);
        uint32 packet = r_u32(0x800774A8);
        uint32 tag = r_u32(previous);
        w_u32(0x80077634, packet);
        w_u32(previous, (tag & 0xFF000000) | (packet & 0xFFFFFF));
        uint32 point = r_u32(node + 4);
        w_u32(0x800774A8, packet + 16);
        w_u32(packet + 8, r_u32(point));
        w_u32(packet + 12, r_u32(r_u32(node + 8)));
        w_u32(packet + 4, r_u32(list + 4));
        uint32 translucent = r_u16(0x800774E4) & 0x100;
        w_u8(packet + 3, 3);
        w_u8(packet + 7, translucent ? 66 : 64);
        node = r_u32(node);
    }
}

uint32 ob_main_8005FB28(uint32 handle, uint32 buffer, uint32 size)
{
    FUNCTION_MARKER(0x8005FB28, "SLES_008.65");
    uint32 total = 0;
    while (size)
    {
        uint32 chunk = size > 0x8000 ? 0x8000 : size;
        uint32 result = ob_draft_unresolved_call(0x8005FBE8, 4, 0, handle, chunk, buffer);
        total += result;
        if (result == 0xFFFFFFFF) return 0xFFFFFFFF;
        buffer += result;
        size -= result;
        if ((sint32)result < (sint32)chunk) break;
    }
    return total;
}

static uint32 ob_batch3_card_transfer(uint32 port, uint32 filename, uint32 blocks, uint32 buffer, uint32 operation)
{
    if (!ob_main_800132A0(port, filename)) return 0;
    uint32 channel = sub_80013794(port);
    uint32 path = ob_draft_scratch_acquire(64);
    ob_draft_unresolved_call(0x80064028, 4, path, 0x80010048, channel, filename);
    uint32 handle = ob_draft_unresolved_call(0x80055904, 2, path, 2);
    uint32 success = 0;
    if (handle != 0xFFFFFFFF)
    {
        uint32 size = (blocks & 0xFF) << 13;
        uint32 transferred = ob_draft_unresolved_call(operation, 3, handle, buffer, size);
        success = transferred == size;
        ob_draft_unresolved_call(0x80055934, 1, handle);
    }
    ob_draft_scratch_release(path);
    return success;
}

uint32 ob_main_8001345C(uint32 port, uint32 filename, uint32 blocks, uint32 buffer)
{
    FUNCTION_MARKER(0x8001345C, "SLES_008.65");
    return ob_batch3_card_transfer(port, filename, blocks, buffer, 0x80055924);
}

uint32 ob_main_80013524(uint32 port, uint32 filename, uint32 blocks, uint32 buffer)
{
    FUNCTION_MARKER(0x80013524, "SLES_008.65");
    return ob_batch3_card_transfer(port, filename, blocks, buffer, 0x80055914);
}


uint32 ob_main_80034608(void)
{
    FUNCTION_MARKER(0x80034608, "SLES_008.65");
    uint32 result = r_u32(0x80077594);
    if (!result) return result;
    uint32 handle = ob_draft_scratch_acquire(4);
    do
    {
        uint32 object = r_u32(0x80077594);
        w_u32(handle, object);
        sint32 kind = r_s16(object + 4);
        if (kind == 0) ob_main_800346CC(object + 8);
        else if (kind == 1 || kind == 2) ob_main_800346EC(object + 8);
        else if (kind == 3) ob_main_80034724(object + 8);
        w_u32(0x80077594, r_u32(r_u32(handle)));
        ob_draft_unresolved_call(0x800263B4, 1, handle);
        result = r_u32(0x80077594);
    } while (result);
    ob_draft_scratch_release(handle);
    return result;
}

uint32 ob_game_800B4FF8(uint32 object, uint32 value, uint32 time)
{
    FUNCTION_MARKER(0x800B4FF8, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    if ((sint32)value < 0) w_u32(data + 56, r_u32(data + 56) - value);
    else w_u32(data + 56, value);
    uint32 result = r_u32(data + 92);
    if (!result)
    {
        uint32 attributes = ob_draft_scratch_acquire(32);
        sub_800453C4(r_u32(object + 44), time, attributes);
        w_u32(attributes + 4, 0);
        uint32 resource = r_u32(object + 124);
        uint32 owner = r_u32(0x80083E34);
        uint32 identifier = r_u16(resource + 4);
        w_u32(attributes + 12, 233);
        w_u16(attributes + 16, identifier);
        result = ob_game_800BC3D8(owner, attributes, time);
        w_u32(data + 92, result);
        ob_main_8004E66C(r_u32(r_u32(object + 136) + 60));
        result = ob_main_8004E66C(r_u32(r_u32(object + 140) + 60));
        ob_draft_scratch_release(attributes);
    }
    return result;
}

uint32 ob_game_800A1CA8(uint32 object, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x800A1CA8, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    uint32 owner = r_u32(data);
    ob_game_800ADDA8(owner, (uint32)(sint32)r_s16(owner + 44), time);
    ob_game_800ADD1C(r_u32(data));
    uint32 offset = (state & 0xFF) * 24;
    uint32 table = r_u32(data + 4);
    owner = r_u32(data);
    ob_draft_unresolved_call(0x800ADC1C, 3, owner, r_u32(table + offset), time);
    uint32 index = r_u8(data + 78);
    w_u8(data + index + 46, state);
    table = r_u32(data + 4);
    index = r_u8(data + 78);
    w_u8(data + 79, index);
    w_u16(data + 34, r_u16(table + offset + 20));
    uint32 result = ob_draft_unresolved_call(0x800A1D74, 2, object, time);
    w_u16(data + 32, state & 0xFF);
    return result;
}

uint32 ob_movie_8008E064(uint32 option)
{
    FUNCTION_MARKER(0x8008E064, "MOVIE.BIN");
    if (option != 0 && option != 1)
        return ob_draft_unresolved_call(0x80064018, 2, 0x8008D02C, option);
    /* TODO Confirm MDEC register support before this path is used */
    w_u32(r_u32(0x8008E9D8), 0x80000000);
    w_u32(r_u32(0x8008E9AC), 0);
    w_u32(r_u32(0x8008E9B8), 0);
    if (option == 1)
    {
        uint32 dma = r_u32(0x8008E9B8);
        uint32 control = r_u32(0x8008E9D8);
        r_u32(dma);
        w_u32(control, 0x60000000);
        return 0x60000000;
    }
    w_u32(r_u32(0x8008E9D8), 0x60000000);
    ob_movie_8008E160(0x8008E894, 32);
    return ob_movie_8008E160(0x8008E918, 32);
}

uint32 ob_main_80048610(uint32 object)
{
    FUNCTION_MARKER(0x80048610, "SLES_008.65");
    uint32 record = r_u32(object + 20);
    w_u32(record, r_u32(record) | 0x8000);
    uint32 result;
    if (r_s32(object + 72) >= 0 || r_s32(object + 76) >= 0 || r_s32(object + 80) >= 0)
        result = r_u32(object);
    else if (r_u32(object + 60) || r_u32(object + 64) || r_u32(object + 68))
    {
        sub_80048B60(object);
        sub_80048BF4(object);
        result = r_u32(object + 108);
    }
    else result = 0x7FFFFF01;
    w_u32(record + 4, result);
    return result;
}

uint32 ob_game_800B9260(uint32 node, uint32 scale, uint32 time)
{
    FUNCTION_MARKER(0x800B9260, "GAME.BIN");
    uint32 attributes = ob_draft_scratch_acquire(96);
    ob_game_800B8E40(node, attributes, time);
    uint32 quarter = (uint32)((sint32)(sint16)scale >> 2);
    w_u32(attributes + 44, 0x800C4B58);
    uint32 owner = r_u32(0x80083E34);
    w_u32(attributes + 56, 200);
    w_u16(attributes + 88, quarter);
    w_u16(attributes + 90, quarter);
    w_u16(attributes + 86, 10);
    w_u8(attributes + 92, 1);
    w_u8(attributes + 93, 4);
    ob_game_80092408(owner, attributes, time, 6);
    uint32 sixteenth = (uint32)((sint32)(sint16)scale >> 4);
    owner = r_u32(0x80083E34);
    w_u32(attributes + 44, 0x800C4B5C);
    w_u32(attributes + 56, 500);
    w_u16(attributes + 88, sixteenth);
    w_u16(attributes + 90, sixteenth);
    w_u16(attributes + 86, 10);
    w_u8(attributes + 92, 1);
    w_u8(attributes + 93, 4);
    uint32 result = ob_game_80092408(owner, attributes, time, 6);
    ob_draft_scratch_release(attributes);
    return result;
}

uint32 ob_game_800BAB08(uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x800BAB08, "GAME.BIN");
    uint32 locals = ob_draft_scratch_acquire(40);
    uint32 cell = locals + 16;
    sub_800514E4(r_u8(record + 12), r_u8(record + 13), cell);
    uint32 map = r_u32(0x80077644);
    uint32 x = r_u8(record + 12);
    uint32 scale = r_u32(map);
    w_u32(locals + 4, 0);
    w_u32(locals, x * scale - r_u32(0x80077458));
    uint32 z = r_u8(record + 13);
    scale = r_u32(map);
    w_u32(locals + 8, r_u32(0x80077468) - z * scale);
    ob_game_800BBA70(locals, r_u8(record + 14), r_u8(record + 15), time);
    uint32 selector = r_u8(record + 3);
    uint32 surface = r_u32(cell + 8);
    uint32 value = r_u8(record + (selector ? 15 : 14));
    w_u8(surface, value);
    uint32 result = ob_draft_unresolved_call(0x8004BD74, 1, cell);
    ob_draft_scratch_release(locals);
    return result;
}

void ob_game_8009A704(uint32 object)
{
    FUNCTION_MARKER(0x8009A704, "GAME.BIN");
    uint32 state = r_u32(object + 128);
    if (!state) return;
    uint32 child = r_u32(state + 20);
    if (child)
    {
        ob_game_80092C14(child);
        /* The existing destructor's extra C parameters are unused */
        ob_game_80092B30(r_u32(r_u32(object + 128) + 20), 0, 0);
        ob_main_80044080(r_u32(r_u32(object + 128) + 12), 0x800662CC);
    }
    child = r_u32(r_u32(object + 128) + 24);
    if (child)
    {
        ob_game_80092C14(child);
        ob_game_80092B30(r_u32(r_u32(object + 128) + 24), 0, 0);
        ob_main_80044080(r_u32(r_u32(object + 128) + 16), 0x800662CC);
    }
    ob_draft_unresolved_call(0x800263B4, 1, object + 128);
    uint32 voice = (uint32)(sint32)r_s16(object + 306);
    w_u32(object + 128, 0);
    sub_8001195C(voice);
    w_u16(object + 306, 0);
}

uint32 ob_game_800B7DA8(uint32 object, uint32 kind)
{
    FUNCTION_MARKER(0x800B7DA8, "GAME.BIN");
    uint32 offset = kind * 20;
    w_u32(object + 100, 0);
    w_u32(object + 96, 0);
    w_u8(object + 113, 0);
    w_u8(object + 112, 0);
    uint32 value = r_u16(0x800C5F2E + offset);
    w_u16(object + 110, 0);
    w_u16(object + 108, 0);
    w_u8(object + 115, 0);
    w_u8(object + 116, 0);
    w_u8(object + 114, 0);
    w_u16(object + 106, value);
    w_u16(object + 104, value);
    uint32 index = r_u32(0x800C5F20 + offset);
    w_u8(object + 136, r_u8(0x800C5EEC + index * 4));
    index = r_u32(0x800C5F20 + offset);
    w_u8(object + 137, r_u8(0x800C5EED + index * 4));
    w_u8(object + 135, r_u32(0x800C5F20 + offset));
    for (uint32 index = 0; index < 7; ++index)
        w_u16(object + 118 + index * 2, r_u16(0x800C5F24 + offset + index * 2));
    w_u8(object + 134, 128);
    w_u16(object + 132, 0);
    return 128;
}

uint32 ob_main_8003D0EC(void)
{
    FUNCTION_MARKER(0x8003D0EC, "SLES_008.65");
    uint32 flags = r_u16(0x800774E4);
    uint32 additional = r_u16(0x80077480);
    flags |= additional;
    uint32 masked = flags & r_u16(0x800775A0);
    w_u16(0x800774E4, flags);
    uint32 count = r_u16(0x800775B4);
    uint32 cursor = r_u32(0x80077418);
    w_u16(0x800774E4, masked);
    cursor += count * 2;
    w_u32(0x80077418, cursor);
    if (masked & 2)
    {
        w_u32(0x80077418, cursor + 4);
        w_u16(0x800774E4, (masked ^ 2) | 1);
    }
    else if (masked & 4) w_u16(0x800774E4, (masked ^ 4) | 1);
    if (r_u16(0x800774E4) & 0x80)
    {
        uint32 index = r_u32(0x80077514);
        uint32 model = r_u32(0x80077598);
        uint32 vertex = r_u32(model + 44) + index * 12;
        uint32 output = r_u32(0x80077394) + 4;
        uint32 result = r_u32(0x80077418);
        xport_gte_write_data(0, r_u32(vertex));
        xport_gte_write_data(1, r_u32(vertex + 4));
        xport_gte_write_data(6, r_u32(result));
        xport_gte_execute(0x108041B);
        w_u32(output, xport_gte_read_data(22));
        return result;
    }
    uint32 source = r_u32(0x80077418);
    uint32 output = r_u32(0x80077394);
    uint32 result = r_u32(source);
    w_u32(output + 4, result);
    return result;
}

uint32 ob_game_80094884(uint32 object, uint32 unused, uint32 time)
{
    FUNCTION_MARKER(0x80094884, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    uint32 delta = time - r_u32(object + 28);
    if (delta)
    {
        uint32 state = r_u32(object + 288);
        if (state == 6 || state == 37) return ob_game_800BCAA0(object);
        if (r_u32(object + 292) != 181)
        {
            uint32 node = r_u32(object + 44);
            w_u32(node + 136, r_u32(node + 136) - delta * 2);
            sub_80045ADC(r_u32(object + 44));
            ob_draft_unresolved_call(0x800B820C, 4, r_u32(object + 44), 1, 150, time);
            w_u32(object + 92, time + 100);
            ob_draft_unresolved_call(0x80045EF4, 1, object + 64);
        }
        w_u32(object + 28, time);
    }
    return ob_game_800916A0(object, time);
}

uint32 ob_game_800B50C4(uint32 x, uint32 unused, uint32 z)
{
    FUNCTION_MARKER(0x800B50C4, "GAME.BIN");
    sint32 column = (sint32)(x + r_u32(0x80077458)) / 2500 % 3;
    sint32 row = (sint32)(r_u32(0x80077468) - z) / 2500 % 3;
    uint32 heights = ob_draft_scratch_acquire(40);
    sub_8004C2C4(heights, x, z);
    uint32 result = r_u32(heights + (uint32)(row * 3 + column) * 4);
    ob_draft_scratch_release(heights);
    return result;
}

uint32 ob_game_800C0CF4(uint32 object, uint32 record)
{
    FUNCTION_MARKER(0x800C0CF4, "GAME.BIN");
    uint32 handle = ob_game_800901FC(r_u32(object + 292), 0);
    uint32 resource = r_u32(handle);
    w_u32(object + 112, resource);
    uint32 distance = r_u16(record + 18) * 2500;
    uint32 data = r_u32(resource);
    sint32 divisor = (sint16)r_u16(data);
    if (!distance) distance = 7500;
    sint32 numerator = (sint32)(distance * 1000);
    if (!divisor) return ob_native_missing_value(0x800C0CF4, "BREAK 7 signed division by zero");
    if (divisor == -1 && numerator == INT32_MIN)
        return ob_native_missing_value(0x800C0CF4, "BREAK 6 signed division overflow");
    sint32 quotient = numerator / divisor;
    uint32 result = (uint32)(quotient / 4);
    w_u32(object + 316, result);
    return result;
}

uint32 ob_main_8004B8AC(uint32 handle)
{
    FUNCTION_MARKER(0x8004B8AC, "SLES_008.65");
    uint32 metadata = r_u32(handle);
    sub_8002679C(handle, 1);
    uint32 count = r_u8(metadata + 11);
    uint32 entry = r_u32(metadata + 24);
    uint32 index = 0;
    while (index < count)
    {
        uint32 target = r_u32(entry);
        if (target) sub_800267C4(target, 2);
        target = r_u32(entry + 4);
        if (target) sub_800267C4(target, 2);
        target = r_u32(entry + 8);
        if (target) sub_800267C4(target, 2);
        count = r_u8(metadata + 11);
        ++index;
        entry += 24;
    }
    uint32 result = sub_800267C4(handle, 1);
    w_u32(0x80077190, 0);
    w_u32(0x80077194, 0);
    w_u32(0x80077198, 0);
    w_u32(0x8007719C, 0);
    return result;
}

uint32 ob_main_8001D4E4(uint32 slot)
{
    FUNCTION_MARKER(0x8001D4E4, "SLES_008.65");
    uint32 table = 0x8006BD58 + slot * 13;
    uint32 data = r_u32(r_u32(0x8006C138) + 108);
    for (uint32 index = 0; index < 13; ++index)
    {
        if (!r_s8(table + index))
        {
            w_u8(0x800899CE + index, 0);
            w_u8(0x800899DB + index, 0);
        }
        else
        {
            w_u8(0x800899CE + index, 1);
            w_u8(0x800899DB + index, r_u8(table + index) - 1);
        }
    }
    for (uint32 index = 0; index < 5; ++index)
        w_u16(0x800899E8 + index * 2, r_u16(0x8006BEE0 + slot * 10 + index * 2));
    uint32 selected = r_u8(data + 44);
    uint32 player = r_u32(0x8006C138);
    w_u8(0x800899F2, selected);
    uint32 index = (uint32)(sint32)r_s16(player + 326);
    uint32 result = r_u16(0x800CBA46 + index * 104);
    w_u16(0x800899F6, result);
    return result;
}

uint32 ob_main_80033074(uint32 object)
{
    FUNCTION_MARKER(0x80033074, "SLES_008.65");
    uint32 index = r_u16(0x80077382);
    uint32 entry = r_u32(0x80077560) + index * 12;
    uint32 count = r_u16(0x80077638);
    while (index < count)
    {
        uint32 first = r_u32(entry + 4);
        uint32 second = r_u32(entry + 8);
        xport_gte_write_control(0, first);
        xport_gte_write_control(1, second);
        xport_gte_write_data(0, r_u32(object + 8));
        xport_gte_write_data(1, r_u32(object + 12));
        xport_gte_execute(0x486012);
        w_u32(0x1F800000, xport_gte_read_data(25));
        uint32 invert = r_u8(entry + 10);
        uint32 value = (uint32)(r_s32(0x1F800000) >> 2);
        if (invert) value = 0 - value;
        w_u32(0x1F800000, value);
        sint32 projection = r_s32(0x1F800000);
        if (r_s32(entry) < projection)
        {
            uint32 flags = r_u32(object + 16);
            w_u32(object + 16, flags | ((uint32)1 << ((index + 8) & 31)));
        }
        count = r_u16(0x80077638);
        ++index;
        entry += 12;
    }
    return 0;
}


uint32 ob_main_80045E98(void)
{
    FUNCTION_MARKER(0x80045E98, "SLES_008.65");
    uint32 result = 0x800896F0;
    uint32 object = r_u32(0x800896F0);
    while (object != 0x800896F4)
    {
        result = sub_80043C6C(object);
        object = r_u32(0x800896F0);
    }
    return result;
}

uint32 ob_main_8001FBCC(void)
{
    FUNCTION_MARKER(0x8001FBCC, "SLES_008.65");
    uint32 result = r_u8(0x8006C012);
    if (result)
    {
        result = r_u8(0x80089968);
        if (result == 2)
        {
            while (ob_draft_unresolved_call(0x800562AC, 3, 3, 0, 0) != 1) {}
            result = 1;
            w_u8(0x80089968, result);
        }
    }
    return result;
}

uint32 ob_main_8002CF44(void)
{
    FUNCTION_MARKER(0x8002CF44, "SLES_008.65");
    uint32 index = 1 - r_u32(0x800773D0);
    w_u32(0x800773D0, index);
    w_u32(0x8007737C, index ? 0x80086AD8 : 0x80086A48);
    ob_draft_unresolved_call(0x8005CB78, 1, r_u32(0x8007737C));
    return ob_draft_unresolved_call(0x8005CD50, 1, r_u32(0x8007737C) + 92);
}

uint32 ob_main_800348B4(uint32 descriptor, uint32 pixels)
{
    FUNCTION_MARKER(0x800348B4, "SLES_008.65");
    uint32 width = r_u16(descriptor + 2);
    uint32 height = r_u16(descriptor + 4);
    sint32 size = (sint32)(width * height);
    uint32 source = pixels;
    uint32 consumed = 0;
    uint32 result = height;
    while ((sint32)consumed < size)
    {
        uint32 first = r_u8(source++);
        uint32 second = r_u8(source++);
        consumed += 2;
        w_u8(pixels++, first + (second << 4));
        result = (sint32)consumed < size;
    }
    return result;
}

uint32 ob_main_800397AC(uint32 descriptor, uint32 context)
{
    FUNCTION_MARKER(0x800397AC, "SLES_008.65");
    sub_80039BD8(descriptor);
    if (r_u16(0x80077364))
        return ob_draft_unresolved_call(0x8003DF98, 2, descriptor, context);
    return ob_draft_unresolved_call(0x8003F528, 2, descriptor, context);
}

uint32 ob_game_800A6C34(uint32 object, uint32 unused, uint32 time)
{
    FUNCTION_MARKER(0x800A6C34, "GAME.BIN");
    uint32 slot = (uint32)(sint32)r_s16(object + 326);
    uint32 node = r_u32(object + 44);
    uint32 selector = r_u8(0x800CBA3A + slot * 104);
    uint32 x = r_u32(node + 80);
    uint32 y = r_u32(node + 84);
    uint32 z = r_u32(node + 88);
    uint32 attributes = ob_draft_scratch_acquire(32);
    w_u32(attributes, x);
    w_u32(attributes + 4, y);
    w_u32(attributes + 8, z);
    w_u32(attributes + 12, 229);
    uint32 index = (uint32)(sint32)(sint8)selector;
    uint32 variant = r_u8(0x800C53A8 + index);
    w_u16(attributes + 22, 0);
    w_u16(attributes + 20, variant);
    if (index == 17)
    {
        uint32 position = sub_80045464(r_u32(object + 44), time);
        uint32 random = ob_draft_unresolved_call(0x8001AFC8, 0);
        w_u16(attributes + 16, random << 1);
        w_u32(attributes + 4, r_u32(position + 4) + 10);
    }
    else w_u16(attributes + 16, 0);
    w_u16(attributes + 18, index);
    ob_game_800A50BC(attributes);
    uint32 result = ob_game_800AEEE8(time);
    ob_draft_scratch_release(attributes);
    return result;
}

uint32 ob_game_800AB8BC(uint32 object, uint32 unused, uint32 time)
{
    FUNCTION_MARKER(0x800AB8BC, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    uint32 slot = (uint32)(sint32)r_s16(object + 326);
    uint32 selector = r_u8(0x800CBA3A + slot * 104);
    if (selector != 17 && r_u32(object + 292) != 6)
        ob_game_800A6C34(object, (uint32)(sint32)(sint8)selector, time);
    slot = (uint32)(sint32)r_s16(object + 326);
    if (!r_u8(0x800CBA5D + slot * 104) || r_u32(object + 292) == 6)
        return ob_game_800BCAA0(object);
    return sub_80045A44(r_u32(object + 44), 0x8006C160);
}

uint32 ob_main_8002FD68(uint32 matrix, uint32 vector, uint32 output)
{
    FUNCTION_MARKER(0x8002FD68, "SLES_008.65");
    uint32 result = 0;
    for (uint32 row = 0; row < 3; ++row)
    {
        uint32 first = (uint32)(sint32)r_s16(vector);
        uint32 second = (uint32)(sint32)r_s16(matrix + row * 6);
        uint32 sum = first * second;
        first = (uint32)(sint32)r_s16(vector + 2);
        second = (uint32)(sint32)r_s16(matrix + row * 6 + 2);
        sum += first * second;
        first = (uint32)(sint32)r_s16(vector + 4);
        second = (uint32)(sint32)r_s16(matrix + row * 6 + 4);
        sum += first * second;
        result = (uint32)((sint32)sum >> 14);
        w_u16(output + row * 2, result);
    }
    return result;
}

uint32 ob_game_800A6A30(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x800A6A30, "GAME.BIN");
    sub_80047FF0(record);
    uint32 slot = (uint32)(sint32)r_s16(object + 326);
    if (r_u16(0x800CBA32 + slot * 104) != 25)
        return ob_draft_unresolved_call(0x800A6B28, 2, object, time);
    if (!(r_u32(record + 28) & 0x20)) return 32;
    if (r_u32(record + 24) != 32) return 32;
    uint32 data = r_u32(r_u32(0x8006C138) + 108);
    uint32 was_set = r_u8(data + 178) != 0;
    uint32 descriptor = ob_game_800A0D38(object);
    ob_draft_unresolved_call(0x800BA234, 3, r_u8(descriptor + 27), 1, time);
    if (!was_set) return 1;
    uint32 result = r_u8(data + 178);
    if (!result) return ob_draft_unresolved_call(0x800A6B28, 2, object, time);
    return result;
}

uint32 ob_game_800B4068(uint32 object, uint32 kind)
{
    FUNCTION_MARKER(0x800B4068, "GAME.BIN");
    uint32 index = (uint32)(sint32)(sint16)kind;
    uint32 variant = (uint32)(sint32)r_s8(0x800C5EED + index * 4);
    uint32 data = r_u32(object + 108);
    uint32 value = r_u32(0x800C5AC4 + index * 4);
    ob_game_800B41B8(data, variant, value);
    uint32 entry = data + index;
    if (!r_s8(entry + 106))
    {
        w_u8(entry + 106, 1);
        return 1;
    }
    uint32 level = r_u8(entry + 130) + 1;
    w_u8(entry + 130, level);
    if ((sint8)level >= 5) w_u8(entry + 130, 4);
    else w_u8(entry + 143, 120);
    uint32 animation = r_u32(object + 120);
    uint32 selected = (uint32)(sint32)r_s8(animation + 135);
    if (selected != index) return index;
    return ob_game_800B7C7C(animation, selected, (uint32)(sint32)r_s8(data + selected + 130));
}

uint32 ob_game_800AC238(uint32 x, uint32 unused, uint32 z)
{
    FUNCTION_MARKER(0x800AC238, "GAME.BIN");
    sint32 local_x = (sint32)(x + r_u32(0x80077458));
    sint32 local_z = (sint32)(r_u32(0x80077468) - z);
    sint32 coarse_x = local_x / 7500;
    sint32 coarse_z = local_z / 7500;
    sint32 fine_x = local_x / 2500;
    sint32 fine_z = local_z / 2500;
    uint32 heights = ob_draft_scratch_acquire(40);
    sub_8004C2C4(heights, x, z);
    uint32 column = (uint32)fine_x - (uint32)coarse_x * 3;
    uint32 row = (uint32)fine_z - (uint32)coarse_z * 3;
    uint32 result = r_s32(heights + column * 12 + row * 4) >= -2560;
    ob_draft_scratch_release(heights);
    return result;
}

uint32 ob_game_800B8FBC(uint32 object, uint32 source)
{
    FUNCTION_MARKER(0x800B8FBC, "GAME.BIN");
    uint32 value = r_u16(source + 138);
    uint32 negative = 0 - value;
    sint32 strength = (sint16)negative;
    if (strength < 0) return (uint32)(sint32)(sint16)value;
    if (negative & 0x2000) return 0;
    uint32 first = r_u32(object + 44);
    uint32 second = r_u32(source + 44);
    uint32 distance = ob_game_80099798(first + 108, second + 108);
    uint32 shape = r_u32(object + 52);
    uint32 radius = (uint32)(r_s32(shape + 76) >> 8);
    sint32 delta = (sint32)(distance - radius);
    if (delta < 0) return (uint32)strength;
    sint32 limit = r_s16(source + 140);
    if (delta >= limit) return 0;
    sint32 product = (sint32)(((uint32)limit - (uint32)delta) * (uint32)strength);
    if (!limit) return ob_native_missing_value(0x800B8FBC, "BREAK 7 signed division by zero");
    if (limit == -1 && product == INT32_MIN)
        return ob_native_missing_value(0x800B8FBC, "BREAK 6 signed division overflow");
    return (uint32)(sint32)(sint16)(product / limit);
}

uint32 ob_game_800AFF6C(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x800AFF6C, "GAME.BIN");
    uint32 flags = r_u32(record + 28);
    uint32 source = r_u32(record + 52);
    if (flags & 0x100000)
    {
        uint32 slot = (uint32)(sint32)r_s16(object + 326);
        if (r_u16(0x800CBA46 + slot * 104))
        {
            uint32 rate = ob_game_800B8FBC(object, source);
            if (ob_game_800A52C4(object, (uint32)(sint32)(sint16)rate, 0xFFFFFFFF))
            {
                ob_game_800AFE94(object, time);
                ob_main_80011A24(0x800666C0, 128, 256, r_u32(object + 44), time, 0);
            }
        }
    }
    else
    {
        if (!(flags & 0x20040000)) return 0;
        w_u32(object + 280, time);
        w_u16(object + 300, r_u16(source + 302));
    }
    return (uint32)sub_80047FF0(record);
}

uint32 ob_main_80012E78(uint32 port, uint32 filename, uint32 output)
{
    FUNCTION_MARKER(0x80012E78, "SLES_008.65");
    uint32 channel = sub_80013794(port);
    uint32 path = ob_draft_scratch_acquire(64);
    ob_draft_unresolved_call(0x80064028, 4, path, 0x80010048, channel, filename);
    uint32 handle = ob_draft_unresolved_call(0x80055904, 2, path, 1);
    if (handle == 0xFFFFFFFF)
    {
        ob_draft_scratch_release(path);
        return 0;
    }
    uint32 size = ob_draft_unresolved_call(0x80055914, 3, handle, output, 512);
    ob_draft_unresolved_call(0x80055934, 1, handle);
    ob_draft_scratch_release(path);
    if (size != 512 || r_u16(output) != 0x4353) return 0;
    ob_main_80015D40(output + 4, output + 4, 64);
    uint32 length = ob_draft_unresolved_call(0x80063FB8, 1, output + 4);
    if ((sint32)length > 0)
    {
        uint32 cursor = output + length * 2;
        do
        {
            if (r_s16(cursor + 4) != 32) break;
            w_u16(cursor + 4, 0);
            ++length;
            cursor += 2;
        } while ((sint32)length > 0);
    }
    return 1;
}

uint32 ob_movie_8008E3CC(uint32 message)
{
    FUNCTION_MARKER(0x8008E3CC, "MOVIE.BIN");
    ob_draft_unresolved_call(0x80064018, 2, 0x8008D0C8, message);
    uint32 status_address = r_u32(0x8008E9D8);
    uint32 input_dma = r_u32(0x8008E9AC);
    uint32 status = r_u32(status_address);
    uint32 input = r_u32(input_dma);
    uint32 output_dma = r_u32(0x8008E9B8);
    uint32 input_address = r_u32(0x8008E9A4);
    uint32 output = r_u32(output_dma);
    uint32 output_address = r_u32(0x8008E9B0);
    uint32 destination = r_u32(output_address);
    uint32 source = r_u32(input_address);
    ob_draft_unresolved_call(0x80064018, 5, 0x8008D068, (input >> 24) & 1, (output >> 24) & 1, source, destination);
    ob_draft_unresolved_call(0x80064018, 8, 0x8008D090, (~status) >> 31, (status >> 30) & 1, (status >> 29) & 1, (status >> 28) & 1, (status >> 27) & 1, (status >> 25) & 1, (status >> 23) & 1);
    /* TODO Confirm MDEC register support before this timeout path is used */
    w_u32(r_u32(0x8008E9D8), 0x80000000);
    w_u32(r_u32(0x8008E9AC), 0);
    w_u32(r_u32(0x8008E9B8), 0);
    output_dma = r_u32(0x8008E9B8);
    status_address = r_u32(0x8008E9D8);
    r_u32(output_dma);
    w_u32(status_address, 0x60000000);
    return 0;
}

uint32 ob_game_800A2AEC(uint32 first, uint32 second, uint32 speed, uint32 time)
{
    FUNCTION_MARKER(0x800A2AEC, "GAME.BIN");
    uint32 second_position = sub_80045464(r_u32(second + 44), time);
    uint32 first_position = sub_80045464(r_u32(first + 44), time);
    uint32 locals = ob_draft_scratch_acquire(8);
    uint32 first_z = r_u32(first_position + 8);
    uint32 second_z = r_u32(second_position + 8);
    uint32 first_x = r_u32(first_position);
    uint32 second_x = r_u32(second_position);
    ob_draft_unresolved_call(0x80028280, 4, first_z - second_z, first_x - second_x, locals, locals + 4);
    uint32 state = r_u32(second + 124);
    sint32 heading = r_s16(locals);
    sint32 previous = r_s16(state + 4);
    uint32 difference = heading < previous ? (uint32)(previous - heading) : (uint32)(heading - previous);
    uint32 result;
    if ((sint16)difference < 0x4000)
    {
        state = r_u32(second + 124);
        w_u16(state + 4, r_u16(locals));
        state = r_u32(second + 124);
        result = 0 - speed;
        w_u32(state, result);
    }
    else
    {
        uint32 angle = r_u16(locals);
        state = r_u32(second + 124);
        w_u16(state + 4, angle - 0x8000);
        result = r_u32(second + 124);
        w_u32(result, speed);
    }
    ob_draft_scratch_release(locals);
    return result;
}


uint32 ob_game_800A8ADC(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800A8ADC, "GAME.BIN");
    uint32 target = r_u32(0x8006C134);
    sint32 angle = (sint16)ob_game_800A8A40(object, target, time);
    if (angle > 8192) return (uint32)-9;
    if (angle < -8192) return 9;
    if (angle > 512) return (uint32)-8;
    return angle < -512 ? 8 : 0;
}

uint32 ob_game_800A29E0(uint32 object, uint32 count)
{
    FUNCTION_MARKER(0x800A29E0, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    if ((sint32)count > 0)
    {
        uint32 player = r_u8(0x800D5C90);
        w_u8(data + 44, player);
        uint32 target = r_u32(0x800D5C98 + player * 4);
        uint32 identifier = r_u16(target + 302);
        player = r_u8(data + 44);
        w_u16(data + 36, identifier);
        target = r_u32(0x800D5C98 + player * 4);
        uint32 state = r_u32(target + 108);
        w_u32(state, object);
        w_u8(state + 4, r_u8(0x800D5C90));
    }
    else
    {
        w_u16(data + 36, 0xFFFF);
        w_u8(data + 44, 0xFF);
    }
    if ((sint32)count < 2)
    {
        w_u16(data + 38, 0xFFFF);
        w_u8(data + 45, 0xFF);
        return 0xFF;
    }
    uint32 player = r_u8(0x800D5C91);
    w_u8(data + 45, player);
    uint32 target = r_u32(0x800D5C98 + player * 4);
    uint32 identifier = r_u16(target + 302);
    player = r_u8(data + 45);
    w_u16(data + 38, identifier);
    target = r_u32(0x800D5C98 + player * 4);
    uint32 state = r_u32(target + 108);
    w_u32(state, object);
    uint32 result = r_u8(0x800D5C91);
    w_u8(state + 4, result);
    return result;
}

uint32 ob_game_800BAD88(uint32 record)
{
    FUNCTION_MARKER(0x800BAD88, "GAME.BIN");
    return ob_game_800A4E4C(r_u8(record + 12));
}


uint32 ob_game_800A6B28(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800A6B28, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    uint32 state = r_u32(data + 4);
    if (state == 17 || r_u32(object + 292) == 171 || state == 23)
        return ob_game_800BCAA0(object);
    sub_80045A7C(r_u32(object + 44), time);
    ob_game_800A9E30(r_u32(data), 0, 0xFFFFD8F0, 0, 1);
    sub_80045A44(r_u32(object + 44), 0x800C5438);
    sub_8004F2C4(r_u32(object + 56), 0);
    uint32 geometry = r_u32(object + 48);
    uint32 shape = r_u32(object + 52);
    uint32 identifier = r_u16(geometry + 160);
    w_u32(object + 288, 11);
    w_u16(object + 306, identifier);
    sub_80046544(shape);
    if (r_u32(object + 64)) sub_80045F20(object + 64);
    return ob_game_800C0744(object, 0, time + 100);
}

uint32 ob_game_800ADF84(uint32 object)
{
    FUNCTION_MARKER(0x800ADF84, "GAME.BIN");
    uint32 owner = r_u32(object + 8);
    uint32 state = r_u32(object + 16);
    uint32 node = sub_8004378C(owner, 0x8007711C);
    uint32 count = r_u16(object + 50);
    uint32 first_table = r_u32(object + 36);
    uint32 second_table = r_u32(object + 32);
    uint32 previous = r_u32(state + 36);
    w_u32(state + 48, 1);
    w_u32(state + 32, node);
    uint32 needed = (count + 1) & 0xFFFF;
    w_u32(state + 44, count);
    if (previous != needed)
    {
        if (r_u32(state + 40)) ob_draft_unresolved_call(0x800263B4, 1, state + 40);
        sub_800262CC(state + 40, needed * 4);
        w_u32(state + 36, needed);
    }
    uint32 output = r_u32(state + 40);
    for (uint32 index = 0; index < count; ++index)
    {
        uint32 identifier = r_u32(first_table);
        first_table += 4;
        uint32 part = sub_800437C4(r_u32(node + 12), identifier);
        w_u32(output, part);
        output += 4;
    }
    uint32 identifier = r_u32(second_table);
    uint32 part = sub_800437C4(r_u32(node + 12), identifier);
    w_u32(output, part);
    return 0;
}

uint32 ob_game_800ADC1C(uint32 object, uint32 handle, uint32 time)
{
    FUNCTION_MARKER(0x800ADC1C, "GAME.BIN");
    uint32 resource = r_u32(handle);
    if (resource & 3) resource = sub_800257CC(handle);
    else
    {
        w_u16(resource - 6, r_u16(resource - 6) + 1);
        resource = r_u32(handle);
    }
    w_u32(object + 20, handle);
    uint32 offset = r_u32(resource);
    uint32 index = (uint32)(sint32)r_s16(object + 50);
    w_u32(object + 28, resource + offset + index * 4 + 8);
    w_u32(object + 24, resource + r_u32(resource + 4) + 12);
    w_u32(object + 36, resource + r_u32(resource) + 4);
    w_u32(object + 32, resource + r_u32(resource + 4) + 4);
    offset = r_u32(resource);
    index = r_u32(resource + 8);
    uint32 frame = r_u16(resource + offset + index * 4 + 4);
    w_u32(object + 40, time);
    w_u32(object + 60, 0);
    w_u32(object + 56, 0);
    w_u32(object + 52, 0);
    w_u16(object + 44, frame);
    return ob_game_800ADF84(object);
}

uint32 ob_main_8001AE60(uint32 player, uint32 input)
{
    FUNCTION_MARKER(0x8001AE60, "SLES_008.65");
    uint32 offset = player * 56;
    if ((input & 4) && !(r_u32(0x800C9988 + offset) & 4))
    {
        sint32 selected = r_s32(0x800C9984 + offset);
        if (selected > 0) w_u32(0x800C9984 + offset, (uint32)selected - 1);
    }
    if ((input & 8) && !(r_u32(0x800C9988 + offset) & 8))
    {
        sint32 selected = r_s32(0x800C9984 + offset);
        if (selected < 2) w_u32(0x800C9984 + offset, (uint32)selected + 1);
    }
    if (input & 0x30)
    {
        uint32 selected = r_u32(0x800C9984 + offset);
        if (selected == 1) w_u32(0x800C996C + offset, r_u32(0x800C996C + offset) | 8);
        else if (selected == 2) w_u32(0x800C996C + offset, r_u32(0x800C996C + offset) | 4);
        w_u32(0x800C9984 + offset, 0xFFFFFFFF);
    }
    w_u32(0x800C9988 + offset, input);
    return offset;
}

uint32 ob_game_800ADE68(uint32 object, uint32 selector)
{
    FUNCTION_MARKER(0x800ADE68, "GAME.BIN");
    uint32 count = (uint32)(sint32)r_s16(object + 50);
    uint32 state = r_u32(object + 16);
    uint32 nodes = r_u32(state + 40);
    uint32 records = r_u32(object + 28) + (uint32)(sint32)(sint16)selector * count * 6;
    if (count)
    {
        uint32 matrices = ob_draft_scratch_acquire(48);
        do
        {
            uint32 node = r_u32(nodes);
            nodes += 4;
            uint32 y = r_u16(records + 2);
            uint32 z = r_u16(records + 4);
            uint32 x = (uint32)(sint32)r_s16(records);
            records += 6;
            --count;
            sub_80029E80(x, matrices);
            sub_8002AF54(matrices, (uint32)(sint32)(sint16)z, matrices + 24);
            ob_draft_unresolved_call(0x8002ACA8, 3, matrices + 24, (uint32)(sint32)(sint16)y, matrices);
            sub_80045848(node, matrices);
        } while (count);
        ob_draft_scratch_release(matrices);
    }
    return sub_80045B74(r_u32(r_u32(object + 16) + 32));
}

uint32 ob_game_8009EF5C(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x8009EF5C, "GAME.BIN");
    uint32 flags = r_u32(record + 28);
    uint32 source = r_u32(record + 52);
    if (flags & 0x10804400)
    {
        uint32 slot = (uint32)(sint32)r_s16(object + 326);
        if (r_u16(0x800CBA46 + slot * 104))
        {
            sint32 strength = r_s16(source + 138);
            if (strength < 0)
            {
                uint32 first = r_u32(object + 44);
                uint32 second = r_u32(source + 44);
                uint32 radius = (uint32)(sint32)r_s16(source + 140);
                strength = (sint16)ob_game_800B8F08(first, second, radius, (uint32)(sint32)(sint16)(0 - (uint32)strength));
            }
            if (strength >= 21)
            {
                slot = (uint32)(sint32)r_s16(object + 326);
                uint32 data = r_u32(object + 108);
                uint32 state = r_u32(data);
                uint32 previous = r_u16(0x800CBA30 + slot * 104);
                uint32 angle = r_u16(state + 26);
                uint32 result = ob_game_800B5CB4(object, 0, (uint32)(sint32)(sint16)(angle - previous), time);
                if (result)
                {
                    uint32 geometry = r_u32(result + 48);
                    w_u16(result + 138, 70);
                    ob_draft_unresolved_call(0x800440B8, 2, geometry, 600);
                }
            }
        }
    }
    return (uint32)sub_80047FF0(record);
}

uint32 ob_game_8009C428(uint32 unused, uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x8009C428, "GAME.BIN");
    uint32 attributes = ob_draft_scratch_acquire(88);
    w_u32(attributes, 0);
    ob_game_800C0F70(attributes, 1000, 5000);
    w_u32(attributes + 32, 1000);
    w_u32(attributes + 36, 0x4000000);
    w_u32(attributes + 40, 0);
    w_u32(attributes + 44, 0x1090C420);
    w_u32(attributes + 48, 0x1090C420);
    w_u32(attributes + 52, 0);
    w_u32(attributes + 56, 0);
    w_u32(attributes + 60, 0x1090C420);
    w_u32(attributes + 64, 0);
    w_u32(attributes + 68, 0);
    w_u32(attributes + 72, object);
    w_u32(attributes + 80, 0x8009C2C8);
    for (uint32 index = 0; index < 4; ++index)
    {
        uint32 identifier = r_u32(0x800C500C + index * 4);
        w_u32(attributes + 76, index);
        w_u32(attributes + 4, identifier);
        uint32 result = sub_80046184(object, attributes, time);
        w_u32(0x800C84A0 + index * 4, result);
        w_u16(0x800D6590 + index * 2, 16000);
        uint32 angle = r_u32(0x800C501C + index * 4);
        w_u16(0x800C9AB8 + index * 2, 6);
        w_u16(0x800C9AA8 + index * 2, angle);
    }
    w_u32(object + 288, 31);
    uint32 result = time + 2500;
    w_u32(object + 284, result);
    ob_draft_scratch_release(attributes);
    return result;
}

uint32 ob_game_800BAC58(uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x800BAC58, "GAME.BIN");
    uint32 offset = r_u8(record + 12) * 4;
    uint32 result = r_u32(0x8007719C) + offset;
    uint32 object = r_u32(result);
    if (!object) return result;
    do
    {
        uint32 kind = r_u32(object + 96);
        if (kind == 149 || kind == 153) ob_game_800BB9E8(record, object, time);
        else if (kind == 165) ob_game_800A7AA8(r_u32(object + 80), r_u8(record + 3), time);
        else if (kind == 37) w_u32(r_u32(object + 80) + 288, 4);
        else if (ob_game_800C1944(object)) ob_game_800C191C(object);
        else ob_game_800C1930(object);
        uint32 table = r_u32(0x8007719C);
        object = r_u32(object + 72);
        result = r_u32(table + offset);
    } while (object != result);
    return result;
}

uint32 ob_main_80013DA4(uint32 value, uint32 x, uint32 y)
{
    FUNCTION_MARKER(0x80013DA4, "SLES_008.65");
    if ((sint32)value >= 10)
    {
        uint32 scale = r_u32(0x8006C174);
        x -= scale * 2;
        sub_80020FD4(0x80066650, 0, 0, 5, 6, x, y, scale * 5, scale * 6, 0);
        scale = r_u32(0x8006C174);
        value -= 10;
        x += scale * 5;
    }
    sint32 digit = (sint32)value % 10;
    uint32 v = 0;
    if (digit >= 6) { digit -= 6; v = 6; }
    uint32 scale = r_u32(0x8006C174);
    return sub_80020FD4(0x80066650, (uint32)digit * 5, v, 5, 6, x, y, scale * 5, scale * 6, 0);
}

uint32 ob_main_8004D1C0(uint32 map)
{
    FUNCTION_MARKER(0x8004D1C0, "SLES_008.65");
    for (uint32 column = 0; column < 3; ++column)
    {
        uint32 x_address = 0x80077430 + column * 2;
        if (r_s8(x_address) == -1) return 0xFFFFFFFF;
        for (uint32 row = 0; row < 3; ++row)
        {
            uint32 z_address = 0x80077438 + row * 2;
            sint32 z = r_s8(z_address);
            if (z == -1) break;
            sint32 width = r_s16(map + 4);
            sint32 x = r_s8(x_address);
            uint32 index = (uint32)(x + z * width);
            uint32 target = r_u32(map + 12) + index * 2;
            uint32 result = sub_8004DAA4((uint32)x, (uint32)z, 0, 0);
            if (result != 0xFFFFFFFF)
            {
                sub_8004A908(index & 0xFF);
                ob_draft_unresolved_call(0x8004D2FC, 6, target, x_address, z_address, 0x80084AA8 + column * 4, 0x80084AB8 + row * 4, result);
            }
        }
    }
    return 0;
}

uint32 ob_main_8002C5DC(uint32 object)
{
    FUNCTION_MARKER(0x8002C5DC, "SLES_008.65");
    sint32 x = r_s16(object + 8);
    sint32 right = r_s16(0x80077522);
    sint32 z = r_s16(object + 12);
    w_u32(object + 16, 0);
    if (z < x - right) w_u32(object + 16, 1);
    x = r_s16(object + 8);
    sint32 left = r_s16(0x8007751C);
    z = r_s16(object + 12);
    if (z < -(x + left)) w_u32(object + 16, r_u32(object + 16) | 2);
    sint32 y = r_s16(object + 10);
    sint32 bottom = r_s16(0x80077524);
    z = r_s16(object + 12);
    if (z < y - bottom) w_u32(object + 16, r_u32(object + 16) | 4);
    y = r_s16(object + 10);
    sint32 top = r_s16(0x8007751E);
    z = r_s16(object + 12);
    if (z < -(y + top)) w_u32(object + 16, r_u32(object + 16) | 8);
    z = r_s16(object + 12);
    sint32 far_plane = r_s16(0x8007752C);
    if (far_plane < z) w_u32(object + 16, r_u32(object + 16) | 16);
    sint32 result = -r_s16(0x8007735C);
    z = r_s16(object + 12);
    if (z < result)
    {
        uint32 flags = r_u32(object + 16);
        w_u32(object + 16, flags | 0x40);
        sint32 near_plane = r_s16(0x80077520);
        z = r_s16(object + 12);
        result = (sint32)(flags | 0x60);
        if (z < -near_plane) w_u32(object + 16, (uint32)result);
    }
    return (uint32)result;
}

static void ob_batch3_project_triple(uint32 input)
{
    for (uint32 index = 0; index < 6; ++index) xport_gte_write_data(index, r_u32(input + index * 4));
    xport_gte_execute(0x280030);
}

static void ob_batch3_store_triple(uint32 output)
{
    w_u32(output, xport_gte_read_data(12));
    w_u32(output + 24, xport_gte_read_data(13));
    w_u32(output + 48, xport_gte_read_data(14));
}

static void ob_batch3_project_single(uint32 input)
{
    xport_gte_write_data(0, r_u32(input));
    xport_gte_write_data(1, r_u32(input + 4));
    xport_gte_execute(0x180001);
}

uint32 ob_main_80037F0C(uint32 geometry)
{
    FUNCTION_MARKER(0x80037F0C, "SLES_008.65");
    uint32 output = r_u32(0x80077574);
    uint32 count = r_u16(geometry + 10);
    uint32 input = r_u32(geometry + 32);
    uint32 remaining = (count - 3) & 0xFFFF;
    ob_batch3_project_triple(input);
    input += 24;
    output += 72;
    uint32 processed = 3;
    if (remaining >= 3)
    {
        do
        {
            ob_batch3_store_triple(output - 72);
            ob_batch3_project_triple(input);
            input += 24;
            processed += 3;
            output += 72;
        } while (remaining >= (processed & 0xFFFF));
    }
    ob_batch3_store_triple(output - 72);
    if ((processed & 0xFFFF) >= count) return 0;
    ob_batch3_project_single(input);
    input += 8;
    uint32 destination = output + 24;
    do
    {
        w_u32(destination - 24, xport_gte_read_data(14));
        ob_batch3_project_single(input);
        input += 8;
        ++processed;
        destination += 24;
    } while ((processed & 0xFFFF) < count);
    uint32 result = destination - 24;
    w_u32(result, xport_gte_read_data(14));
    return result;
}

uint32 ob_game_800AB4E4(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800AB4E4, "GAME.BIN");
    uint32 result = r_u32(object + 288);
    if (result == 3) return result;
    uint32 slot = (uint32)(sint32)r_s16(object + 326);
    w_u32(object + 288, 3);
    if (r_u32(0x800CBA48 + slot * 104)) ob_game_8009B0F0(0x800CBA00 + slot * 104);
    slot = (uint32)(sint32)r_s16(object + 326);
    w_u16(0x800CBA36 + slot * 104, 0);
    sub_80045A7C(r_u32(object + 44), time);
    slot = (uint32)(sint32)r_s16(object + 326);
    w_u16(0x800CBA46 + slot * 104, 0);
    sub_80046544(r_u32(object + 52));
    uint32 data = r_u32(object + 108);
    w_u16(data + 12, r_u16(object + 296));
    uint32 random = ob_draft_unresolved_call(0x8001AFC8, 0);
    w_u16(data + 14, (random & 0x1FFF) + 4096);
    w_u32(data + 4, time + 1000);
    w_u32(data + 8, time);
    if (r_u32(object + 64)) sub_80045F20(object + 64);
    uint32 shape = r_u32(object + 52);
    w_u32(object + 100, 0x800AB640);
    w_u32(object + 96, 0);
    w_u32(object + 92, time + 50);
    sub_80046544(shape);
    return ob_draft_unresolved_call(0x80045EF4, 1, object + 64);
}

uint32 ob_game_800AC414(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x800AC414, "GAME.BIN");
    uint32 flags = r_u32(record + 28);
    uint32 source = r_u32(record + 52);
    if (flags & 0x20)
    {
        uint32 data = r_u32(source + 108);
        uint32 multiplier = r_u8(data + 46) == 3 ? 1 : 2;
        if (r_u32(object + 292) == 239)
        {
            if (r_u32(record + 24) == 32)
            {
                uint32 level = (uint32)(sint32)r_s16(object + 304) + 2;
                ob_game_800B4FF8(source, multiplier * 375 * level, time);
            }
        }
        else
        {
            ob_game_800B4FF8(source, multiplier * 750, time);
            ob_game_800A52C4(object, 10, 0xFFFFFFFF);
        }
        uint32 child = r_u32(object + 132);
        if (child && r_u32(child + 292) == 238 && r_u32(record + 24) == 32)
        {
            w_u16(child + 304, 1);
            w_u32(r_u32(object + 132) + 316, time);
        }
    }
    return (uint32)sub_80047FF0(record);
}

uint32 ob_main_8001CBBC(void)
{
    FUNCTION_MARKER(0x8001CBBC, "SLES_008.65");
    uint32 count = 0;
    uint32 players = r_u8(0x8006C230);
    for (uint32 index = 0; index < players; ++index)
    {
        uint32 object = r_u32(0x8006C138 + index * 4);
        if (object)
        {
            uint32 data = r_u32(object + 108);
            uint32 entry = 0x80088288 + count * 6;
            w_u16(entry, count);
            uint32 selected = r_u8(data + 44);
            ++count;
            w_u16(entry + 2, selected);
        }
        players = r_u8(0x8006C230);
    }
    for (uint32 remaining = count; remaining > 0; --remaining)
        for (uint32 index = 1; index < remaining; ++index)
        {
            uint32 entry = 0x80088288 + (index - 1) * 6;
            sint32 next = r_s16(entry + 8);
            sint32 current = r_s16(entry + 2);
            if (current < next)
            {
                w_u16(entry + 2, (uint32)next);
                w_u16(entry + 8, (uint32)current);
                uint32 next_id = r_u16(entry + 6);
                uint32 current_id = (uint32)(sint32)r_s16(entry);
                w_u16(entry, next_id);
                w_u16(entry + 6, current_id);
            }
        }
    w_u16(0x8008828C, 0);
    uint32 rank = 0;
    for (uint32 index = 1; index < count; ++index)
    {
        uint32 offset = (index - 1) * 6;
        sint32 next = r_s16(0x80088290 + offset);
        sint32 current = r_s16(0x8008828A + offset);
        if (next != current) ++rank;
        w_u16(0x80088292 + offset, rank);
    }
    return count;
}

uint32 ob_game_8009C2C8(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x8009C2C8, "GAME.BIN");
    sub_80045A7C(r_u32(object + 44), time);
    if (r_u32(record + 28) & 0x10904400)
    {
        uint32 source = r_u32(record + 52);
        uint32 index = r_u32(record + 44);
        sint32 rate = (sint16)ob_game_800B8FBC(object, source);
        if (rate)
        {
            uint32 part = sub_800437C4(object, r_u32(0x800C4FEC + index * 4));
            uint32 counter = 0x800D6590 + index * 2;
            uint32 damage = (uint32)rate << 6;
            w_u16(counter, r_u16(counter) - damage);
            w_u16(part + 56, r_u16(part + 56) | 0x4000);
            uint32 total = r_u32(0x800C835C);
            sint32 remaining = r_s16(counter);
            w_u32(0x800C835C, total - damage);
            if (remaining < 0)
            {
                w_u16(counter, 0);
                ob_main_80044080(part, 0x800662CC);
                uint32 node = r_u32(object + 44);
                uint32 identifier = r_u32(0x800C500C + index * 4);
                part = sub_800437C4(r_u32(node + 12), identifier);
                ob_draft_unresolved_call(0x800A2558, 6, part, time, 5, 50, 400, 400);
                sub_80046544(r_u32(record + 8));
            }
        }
    }
    return (uint32)sub_80047FF0(record);
}
