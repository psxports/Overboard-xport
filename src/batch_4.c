#include "psx.h"
#include "draft_signatures.h"
#include "native_extra_signatures.h"
#include "native_runtime.h"
#include "game_signatures.h"
#include "decomp_208_signatures.h"
#include "native_timers.h"

uint32 ob_main_80012A90(uint32 slot)
{
    FUNCTION_MARKER(0x80012A90, "SLES_008.65");
    uint32 channel = ob_card_channel(slot);
    uint32 local = ob_draft_scratch_acquire(16);
    ob_draft_unresolved_call(0x80064028, 3, local, 0x80010000, channel);
    ob_draft_unresolved_call(0x80055944, 1, local);
    uint32 result = sub_800129FC(slot);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_main_80012B70(uint32 slot)
{
    FUNCTION_MARKER(0x80012B70, "SLES_008.65");
    uint32 local = ob_draft_scratch_acquire(128);
    w_u8(local, 255); w_u8(local + 1, 255);
    overboard_drain_extended_events();
    do
    {
        uint32 channel = ob_card_channel(slot);
        if (ob_draft_unresolved_call(0x80063BB4, 3, channel, 0, local)) break;
    } while (1);
    uint32 result = !overboard_poll_extended_event();
    if (result) result = !sub_800129FC(slot);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_main_80013318(uint32 slot, uint32 name)
{
    FUNCTION_MARKER(0x80013318, "SLES_008.65");
    uint32 channel = ob_card_channel(slot);
    uint32 local = ob_draft_scratch_acquire(64);
    ob_draft_unresolved_call(0x80064028, 4, local, 0x80010048, channel, name);
    uint32 result = ob_draft_unresolved_call(0x80055974, 1, local);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_main_80013360(uint32 slot, uint32 name, uint32 blocks, uint32 data)
{
    FUNCTION_MARKER(0x80013360, "SLES_008.65");
    if (ob_main_800132A0(slot, name)) return 0;
    uint32 local = ob_draft_scratch_acquire(64);
    uint32 channel = ob_card_channel(slot);
    ob_draft_unresolved_call(0x80064028, 4, local, 0x80010048, channel, name);
    blocks &= 255;
    uint32 descriptor = ob_draft_unresolved_call(0x80055904, 2, local, (blocks << 16) | 512);
    uint32 result = 0;
    if (descriptor != UINT32_MAX)
    {
        ob_draft_unresolved_call(0x80055934, 1, descriptor);
        descriptor = ob_draft_unresolved_call(0x80055904, 2, local, 2);
        if (descriptor != UINT32_MAX)
        {
            uint32 length = blocks << 13;
            uint32 written = ob_draft_unresolved_call(0x80055924, 3, descriptor, data, length);
            ob_draft_unresolved_call(0x80055934, 1, descriptor);
            if (written == length) { sub_80012BE8(slot); result = 1; }
        }
    }
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_main_800130C4(uint32 output, uint32 title, uint32 frames, uint32 blocks, uint32 palette, uint32 images)
{
    FUNCTION_MARKER(0x800130C4, "SLES_008.65");
    ob_draft_unresolved_call(0x80063FD8, 3, output, 0, 512);
    w_u8(output, 83); w_u8(output + 1, 67);
    w_u8(output + 2, frames + 16);
    w_u8(output + 3, blocks);
    ob_draft_unresolved_call(0x80063FA8, 3, output + 4, title, 32);
    for (uint32 offset = 0; offset < 32; offset += 16)
    {
        uint32 words[4];
        for (uint32 i = 0; i < 4; ++i) words[i] = r_u32(palette + offset + i * 4);
        for (uint32 i = 0; i < 4; ++i) w_u32(output + 96 + offset + i * 4, words[i]);
    }
    frames &= 255;
    for (uint32 frame = 0; frame < frames; ++frame)
    {
        uint32 source = r_u32(images + frame * 4);
        uint32 destination = output + 128 + frame * 128;
        for (uint32 offset = 0; offset < 128; offset += 16)
        {
            uint32 words[4];
            for (uint32 i = 0; i < 4; ++i) words[i] = r_u32(source + offset + i * 4);
            for (uint32 i = 0; i < 4; ++i) w_u32(destination + offset + i * 4, words[i]);
        }
    }
    ob_main_80015E98(title, output + 4, 32);
    return 0;
}

uint32 ob_main_80020BD8(uint32 texture, uint32 pixels, uint32 palette)
{
    FUNCTION_MARKER(0x80020BD8, "SLES_008.65");
    uint32 clut_handle = sub_80025874(r_u32(texture) >> 17);
    uint32 page_handle = sub_80025874((r_u32(texture) >> 2) & 32767);
    uint32 page = r_u32(page_handle), clut = r_u32(clut_handle);
    uint32 local = ob_draft_scratch_acquire(8);
    w_u16(local + 4, 4); w_u16(local + 6, 16);
    w_u16(local, (((page >> 16) & 15) << 6) + ((page >> 6) & 60));
    w_u16(local + 2, ((page >> 8) & 240) + (((page >> 16) << 4) & 256));
    ob_draft_unresolved_call(0x8005C504, 1, 0);
    ob_draft_unresolved_call(0x8005C7C8, 2, local, pixels);
    clut = (clut >> 2) << 4;
    w_u16(local, clut & 1023); w_u16(local + 2, clut >> 10);
    w_u16(local + 4, 16); w_u16(local + 6, 1);
    ob_draft_unresolved_call(0x8005C7C8, 2, local, palette);
    uint32 result = ob_draft_unresolved_call(0x8005C504, 1, 0);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_main_8002A110(uint32 vector, uint32 output)
{
    FUNCTION_MARKER(0x8002A110, "SLES_008.65");
    sint32 x = r_s16(vector), z = r_s16(vector + 4);
    uint32 length = sub_8002B868((uint32)(x * x) + (uint32)(z * z));
    sint32 divisor = (sint16)length;
    if (divisor)
    {
        sint32 first = (sint32)((uint32)(sint32)r_s16(vector) << 14) / divisor;
        sint32 second = (sint32)((uint32)(sint32)r_s16(vector + 4) << 14) / divisor;
        w_u16(output + 2, 0);
        w_u16(output, second); w_u16(output + 4, 0 - (uint32)first);
        sint32 y = -r_s16(vector + 2);
        w_u16(output + 8, length);
        w_u16(output + 6, (y * (sint16)first) >> 14);
        y = -r_s16(vector + 2);
        w_u16(output + 10, (y * (sint16)second) >> 14);
        w_u16(output + 12, r_u16(vector));
        w_u16(output + 14, r_u16(vector + 2));
        uint32 result = r_u16(vector + 4);
        w_u16(output + 16, result);
        return result;
    }
    w_u16(output, 16384); w_u16(output + 2, 0); w_u16(output + 4, 0);
    w_u16(output + 6, 0); w_u16(output + 8, 0);
    w_u16(output + 10, r_s16(vector + 2) > 0 ? (uint32)-16384 : 16384);
    w_u16(output + 12, 0);
    sint32 result = r_s16(vector + 2);
    w_u16(output + 14, result > 0 ? 16384 : (uint32)-16384);
    w_u16(output + 16, 0);
    return (uint32)result;
}

uint32 ob_main_8001A4A0(uint32 x, uint32 z)
{
    FUNCTION_MARKER(0x8001A4A0, "SLES_008.65");
    uint32 map = r_u32(0x80077644);
    uint32 origin = r_u32(0x80077458);
    return sub_8001A4B0(x, z, origin, map);
}

uint32 ob_main_80013614(uint32 slot, uint32 direction)
{
    FUNCTION_MARKER(0x80013614, "SLES_008.65");
    uint32 status = 2;
    for (uint32 attempt = 0; attempt < 9; ++attempt)
    {
        if (!direction)
        {
            if (slot != UINT32_MAX) status = sub_80012758(slot);
            if (status < 2 || status == 3) return slot;
            slot = slot == 7 ? 0 : slot + 1;
        }
        else if (direction == 1) slot = slot == 7 ? 0 : slot + 1;
        else if (direction == UINT32_MAX) slot = (sint32)slot > 0 ? slot - 1 : 7;
        if (slot != UINT32_MAX) status = sub_80012758(slot);
        if (attempt == 8) return UINT32_MAX;
        if (status < 2 || status == 3) return slot;
    }
    return UINT32_MAX;
}

uint32 ob_main_80016D24(uint32 intensity)
{
    FUNCTION_MARKER(0x80016D24, "SLES_008.65");
    return ob_main_80016d2c(intensity, r_u32(0x800775BC));
}

uint32 ob_main_80016d2c(uint32 intensity, uint32 end)
{
    FUNCTION_MARKER(0x80016D2C, "SLES_008.65");
    uint32 packet = r_u32(0x800774A8);
    if ((sint32)(end - packet) < 12)
        return 1;
    uint32 previous = r_u32(0x80077634);
    uint32 tag = r_u32(previous);
    uint32 old_tag = r_u32(previous);
    w_u32(0x800774A8, packet + 36);
    w_u32(0x80077634, packet);
    w_u32(previous, (tag & 0xFF000000) | (packet & 0xFFFFFF));
    POLY_G4 *polygon = (POLY_G4 *)psx_addr(packet, sizeof(POLY_G4));
    setPolyG4(polygon);
    setSemiTrans(polygon, 1);
    for (uint32 vertex = 0; vertex < 4; ++vertex)
        for (uint32 channel = 0; channel < 3; ++channel)
            w_u8(packet + 4 + vertex * 8 + channel, vertex < 2 ? intensity : 0);
    uint32 tail = r_u32(0x80077634);
    w_u16(packet + 8, 0);
    w_u16(packet + 10, 0);
    w_u16(packet + 16, 384);
    w_u16(packet + 18, 0);
    w_u16(packet + 24, 0);
    w_u16(packet + 26, 256);
    w_u16(packet + 32, 384);
    w_u16(packet + 34, 256);
    uint32 result = (r_u32(tail) & 0xFF000000) | (old_tag & 0xFFFFFF);
    w_u32(tail, result);
    return result;
}

uint32 ob_main_80016E4C(uint32 mode)
{
    FUNCTION_MARKER(0x80016E4C, "SLES_008.65");
    uint32 end = r_u32(0x800775BC);
    uint32 packet = r_u32(0x800774A8);
    uint32 previous = r_u32(0x80077634);
    uint32 old_tag = r_u32(previous);
    if ((sint32)(end - packet) < 64) return 1;
    uint32 tag = r_u32(previous);
    uint32 environment = r_u32(0x8007737C);
    w_u32(previous, (tag & 0xFF000000) | (packet & 0xFFFFFF));
    uint32 local = ob_draft_scratch_acquire(96);
    for (uint32 i = 0; i < 10; ++i) w_u16(local + i * 2, r_u16(environment + i * 2));
    w_u32(0x80077634, packet);
    uint32 value = r_u16(environment + 20);
    w_u32(0x800774A8, packet + 64);
    w_u8(local + 22, mode);
    w_u16(local + 20, value);
    for (uint32 i = 23; i < 28; ++i) w_u8(local + i, r_u8(environment + i));
    ob_draft_unresolved_call(0x8005D3F0, 2, packet, local);
    uint32 tail = r_u32(0x80077634);
    uint32 result = (r_u32(tail) & 0xFF000000) | (old_tag & 0xFFFFFF);
    w_u32(tail, result);
    ob_draft_scratch_release(local);
    return result;
}

static uint32 ob_missing_add_trap(uint32 first, uint32 second, uint32 owner)
{
    uint32 result = first + second;
    if ((~(first ^ second) & (first ^ result) & 0x80000000) != 0)
        return ob_native_missing_value(owner, "Original signed ADD overflow");
    return result;
}

uint32 ob_main_80029CD0(uint32 vector, uint32 matrix, uint32 output)
{
    FUNCTION_MARKER(0x80029CD0, "SLES_008.65");
    sint32 x = r_s32(vector);
    sint32 y = r_s32(vector + 4);
    sint32 z = r_s32(vector + 8);
    uint32 result = 0;
    for (uint32 row = 0; row < 3; ++row)
    {
        uint32 first = (uint32)(((sint64)x * r_s16(matrix + row * 6)) >> 14);
        uint32 second = (uint32)(((sint64)y * r_s16(matrix + row * 6 + 2)) >> 14);
        uint32 sum = ob_missing_add_trap(second, first, 0x80029CD0);
        sint64 product = (sint64)z * r_s16(matrix + row * 6 + 4);
        uint32 value = ob_missing_add_trap((uint32)(product >> 14), sum, 0x80029CD0);
        w_u32(output + row * 4, value);
        result = (uint32)((uint64)product >> 32) << 18;
    }
    return result;
}

uint32 ob_main_8002ACA8(uint32 matrix, uint32 angle, uint32 output)
{
    FUNCTION_MARKER(0x8002ACA8, "SLES_008.65");
    uint32 offset = (((angle & 65535) + 8) >> 4) * 2;
    uint32 cosine = (uint32)r_s16(0x8006CB04 + offset);
    uint32 sine = (uint32)r_s16(0x8006C304 + offset);
    uint32 x[3], y[3];
    for (uint32 row = 0; row < 3; ++row)
    {
        x[row] = (uint32)r_s16(matrix + row * 6);
        y[row] = (uint32)r_s16(matrix + row * 6 + 2);
    }
    w_u16(output + 2, (uint32)((sint32)(x[0] * sine + y[0] * cosine) >> 14));
    w_u16(output, (uint32)((sint32)(x[0] * cosine - y[0] * sine) >> 14));
    uint32 value = r_u16(matrix + 4);
    w_u16(output + 6, (uint32)((sint32)(x[1] * cosine - y[1] * sine) >> 14));
    w_u16(output + 8, (uint32)((sint32)(x[1] * sine + y[1] * cosine) >> 14));
    w_u16(output + 4, value);
    value = r_u16(matrix + 10);
    w_u16(output + 12, (uint32)((sint32)(x[2] * cosine - y[2] * sine) >> 14));
    w_u16(output + 10, value);
    w_u16(output + 14, (uint32)((sint32)(x[2] * sine + y[2] * cosine) >> 14));
    value = r_u16(matrix + 16);
    w_u16(output + 16, value);
    return value;
}

uint32 ob_main_80049318(uint32 contact)
{
    FUNCTION_MARKER(0x80049318, "SLES_008.65");
    uint32 state = r_u32(contact + 20), first = r_u32(contact + 4), second = r_u32(contact + 8);
    sub_80048994(contact);
    sint32 maximum = r_s32(contact + 76);
    sint32 value = r_s32(contact + 80);
    if (maximum < value) maximum = value;
    value = r_s32(contact + 72);
    if (value < maximum) value = maximum;
    uint32 flags = r_u32(state) & 0xFFFFFFF7;
    w_u32(state, flags);
    if (value >= 0)
    {
        w_u32(state, flags | 16);
        w_u32(first + 256, 0); w_u32(second + 256, 0);
        return 0;
    }
    w_u32(state, flags | 32);
    uint32 mask = r_u32(second + 136) & r_u32(first + 160);
    uint32 other = r_u32(first + 136);
    w_u32(first + 256, mask);
    w_u32(second + 256, other & r_u32(second + 160));
    return 8;
}

uint32 ob_main_80049CEC(uint32 contact)
{
    FUNCTION_MARKER(0x80049CEC, "SLES_008.65");
    sub_80048994(contact);
    w_u32(0x80078EE8, r_u32(contact + 72));
    w_u32(0x80078EEC, r_u32(contact + 76));
    uint32 value = r_u32(contact + 80);
    w_u16(0x80078ED8, 0); w_u16(0x80078EDA, 0); w_u16(0x80078EDC, 0);
    w_u32(0x80078EF0, value);
    uint32 state = r_u32(contact + 20), first = r_u32(contact + 4);
    uint32 flags = r_u32(state), second = r_u32(contact + 8);
    uint32 field, result;
    if (flags & 0x10000)
    {
        for (uint32 axis = 0; axis < 3; ++axis)
            if (!r_u32(contact + 72 + axis * 4))
                w_u16(0x80078ED8 + axis * 2, r_u32(contact + 48 + axis * 4) == r_u32(contact + 36 + axis * 4) ? (uint32)-16384 : 16384);
        field = 148; result = 68;
    }
    else
    {
        for (uint32 axis = 0; axis < 3; ++axis)
        {
            if (axis) flags = r_u32(state);
            uint32 bit = 0x100 << (axis * 2);
            if (flags & (bit * 3)) w_u16(0x80078ED8 + axis * 2, flags & bit ? 16384 : (uint32)-16384);
        }
        w_u32(state, (r_u32(state) & 0xFFFFC0BF) | 16);
        field = 156; result = 2;
    }
    uint32 mask = r_u32(second + 136) & r_u32(first + field);
    uint32 other = r_u32(first + 136);
    w_u32(first + 256, mask);
    w_u32(second + 256, other & r_u32(second + field));
    return result;
}

uint32 ob_main_80049FCC(uint32 first, uint32 second, uint32 third, uint32 fourth)
{
    FUNCTION_MARKER(0x80049FCC, "SLES_008.65");
    uint32 locals = ob_draft_scratch_acquire(32);
    for (uint32 i = 0; i < 3; ++i) w_u32(locals + i * 4, r_u32(first + i * 4) << 8);
    for (uint32 i = 0; i < 3; ++i) w_u32(locals + 16 + i * 4, r_u32(second + i * 4) << 8);
    uint32 result = sub_8004A048(locals, locals + 16, (sint32)third, (sint32)fourth);
    ob_draft_scratch_release(locals);
    return result;
}

uint32 ob_main_8004BD74(uint32 state)
{
    FUNCTION_MARKER(0x8004BD74, "SLES_008.65");
    return ob_main_8004bd7c(state, r_u32(0x800665D8));
}

uint32 ob_main_8004bd7c(uint32 state, uint32 map)
{
    FUNCTION_MARKER(0x8004BD7C, "SLES_008.65");
    if (map & 3)
        map = sub_800257CC(0x800665D8);
    else
        w_u16(map - 6, r_u16(map - 6) + 1);
    uint32 indices = r_u32(state + 4);
    w_u32(0x80077644, map);
    ob_classify_effect_index(indices, map);
    uint32 cells = r_u32(state);
    uint32 current_map = r_u32(0x80077644);
    ob_classify_effect_cell(cells, current_map);
    return sub_800257A0(0x800665D8);
}

uint32 ob_main_8004BE08(uint32 position)
{
    FUNCTION_MARKER(0x8004BE08, "SLES_008.65");
    uint32 map = r_u32(0x800665D8);
    if (map & 3) map = sub_800257CC(0x800665D8);
    else w_u16(map - 6, r_u16(map - 6) + 1);
    w_u32(0x80077644, map);
    uint32 locals = ob_draft_scratch_acquire(24);
    sub_80051400(position, locals);
    uint32 cell = r_u32(locals + 8);
    uint32 value = r_u8(cell + 1);
    if (value)
    {
        uint32 original = r_u8(cell);
        uint32 count = value >> 6;
        if (value & 63)
        {
            do
            {
                cell = r_u32(locals + 8);
                w_u8(cell, r_u8(cell) + 1);
                cell = r_u32(locals + 8);
                uint32 entry = r_u8(cell);
                map = r_u32(0x80077644);
                ++count;
                if (!r_s8(r_u32(map + 24) + entry * 24 + 21)) break;
            } while (1);
        }
        ob_game_800BBA70(position, original, r_u8(r_u32(locals + 8)), r_u32(0x800882BC));
        w_u8(r_u32(locals + 8) + 1, count << 6);
        ob_classify_effect_index(r_u32(locals + 4), r_u32(0x80077644));
        ob_classify_effect_cell(r_u32(locals), r_u32(0x80077644));
    }
    uint32 result = sub_800257A0(0x800665D8);
    ob_draft_scratch_release(locals);
    return result;
}

uint32 ob_main_8001DFCC(uint32 mode)
{
    FUNCTION_MARKER(0x8001DFCC, "SLES_008.65");
    uint32 result = r_u8(0x8006C00C);
    if (result) w_u8(0x80078BEC, mode);
    return result;
}

uint32 ob_main_80011870(uint32 mode)
{
    FUNCTION_MARKER(0x80011870, "SLES_008.65");
    ob_main_8001DFCC(mode & 255);
    w_u32(0x80065B70, mode == 4);
    return 1;
}

uint32 ob_main_80012164(uint32 value)
{
    FUNCTION_MARKER(0x80012164, "SLES_008.65");
    return sub_8001DEB4(value & 255);
}

uint32 ob_main_800135EC(void)
{
    FUNCTION_MARKER(0x800135EC, "SLES_008.65");
    sint32 offset = 3864;
    do
    {
        w_u32(0x80089D2C + (uint32)offset, 1);
        offset -= 552;
    } while (offset >= 0);
    return (uint32)offset;
}

uint32 ob_main_8001A690(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x8001A690, "SLES_008.65");
    uint32 players = r_u8(0x8006C230);
    if (players < 2)
    {
        uint32 data = r_u32(object + 108);
        uint32 count = r_u8(data + 44);
        if (!count)
        {
            w_u32(object + 288, 20);
            return 20;
        }
        if (players == 1) w_u8(data + 44, count - 1);
    }
    w_u32(object + 288, 22);
    w_u8(0x80086A2C, 0);
    w_u32(0x80089990, time);
    return 22;
}

uint32 ob_main_8001AFC8(void)
{
    FUNCTION_MARKER(0x8001AFC8, "SLES_008.65");
    uint32 state = r_u32(0x80066030) * 12345 + 1;
    w_u32(0x80066030, state);
    return state & 32767;
}

uint32 ob_main_8004545C(uint32 object)
{
    FUNCTION_MARKER(0x8004545C, "SLES_008.65");
    return object + 36;
}

uint32 ob_main_80045D0C(uint32 object)
{
    FUNCTION_MARKER(0x80045D0C, "SLES_008.65");
    sub_800454BC(object);
    return ob_detach_owner_child(object);
}

uint32 ob_main_800499C0(uint32 contact)
{
    FUNCTION_MARKER(0x800499C0, "SLES_008.65");
    uint32 state = r_u32(contact + 20);
    uint32 first = r_u32(contact + 4);
    uint32 value = r_u32(state);
    uint32 second = r_u32(contact + 8);
    w_u32(state, (value & 0xFFFFFFDF) | 16);
    w_u32(first + 256, r_u32(second + 136) & r_u32(first + 168));
    w_u32(second + 256, r_u32(first + 136) & r_u32(second + 168));
    return 16;
}

uint32 ob_main_8004E680(uint32 object)
{
    FUNCTION_MARKER(0x8004E680, "SLES_008.65");
    uint32 result = r_u8(object + 52) - 1;
    w_u8(object + 52, result);
    return result;
}

uint32 ob_main_8004F9A0(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x8004F9A0, "SLES_008.65");
    uint32 result = r_u32(object + 208);
    uint32 selected = time;
    if ((sint32)result >= 0)
    {
        uint32 node = r_u32(object + 24);
        result = r_u32(node + 124) + r_u32(object + 84) - r_u32(object + 200);
        if (result == r_u32(object + 72))
        {
            result = r_u32(node + 136);
            selected = result ? time + 1 : 0x7FFFFF01;
        }
    }
    w_u32(object + 160, selected);
    return result;
}

uint32 ob_main_80024E04(void)
{
    FUNCTION_MARKER(0x80024E04, "SLES_008.65");
    for (uint32 row = 0; row < 20; ++row)
    {
        uint32 result = row;
        for (uint32 i = 0; i < 6; ++i)
        {
            uint32 object = r_u32(0x8009CF20 + i * 4);
            uint32 first = r_u8(object + 120);
            uint32 second = r_u8(object + 121);
            sint32 expected = r_s8(0x8006C264 + row * 6 + i);
            if ((sint32)(first == second ? first : second) != expected) result = UINT32_MAX;
        }
        if ((sint32)result >= 0) return result;
    }
    return UINT32_MAX;
}

uint32 ob_main_8001F6E8(uint32 voice, uint32 pitch)
{
    FUNCTION_MARKER(0x8001F6E8, "SLES_008.65");
    uint32 result = r_u8(0x8006C00C);
    if (!result) return result;
    if (voice == UINT32_MAX) return UINT32_MAX;
    if (voice >= 24) return voice * 8;
    uint32 record = voice * 28;
    result = r_u32(0x80078544 + record) & 2;
    if (!result) return result;
    sint32 first = r_s8(0x80078554 + record);
    w_u32(0x8007854C + record, pitch);
    uint32 channel = (uint32)first * 28;
    uint32 owner = r_u32(0x800782B4 + channel);
    uint32 base = r_u32(0x80078540 + record);
    uint32 attributes = ob_draft_scratch_acquire(64);
    if (owner == voice)
    {
        w_u32(attributes, 1u << ((uint32)first & 31));
        w_u32(attributes + 4, 16);
        uint32 value = (uint32)((sint32)(pitch * base) / 256) & 65535;
        w_u16(attributes + 20, value);
        w_u32(0x800782B0 + channel, value);
        ob_draft_unresolved_call(0x80062EE8, 1, attributes);
    }
    sint32 second = r_s8(0x80078555 + record);
    result = (uint32)second;
    if (second)
    {
        channel = (uint32)second * 28;
        result = r_u32(0x800782B4 + channel);
        if (result == voice)
        {
            w_u32(attributes, 1u << ((uint32)second & 31));
            w_u32(attributes + 4, 16);
            uint32 value = (uint32)((sint32)(pitch * base) / 256) & 65535;
            w_u16(attributes + 20, value);
            w_u32(0x800782B0 + channel, value);
            result = ob_draft_unresolved_call(0x80062EE8, 1, attributes);
        }
    }
    ob_draft_scratch_release(attributes);
    return result;
}

uint32 ob_main_80011D80(uint32 voice, uint32 pitch)
{
    FUNCTION_MARKER(0x80011D80, "SLES_008.65");
    return ob_main_8001F6E8(voice, pitch);
}

uint32 ob_main_80011F24(uint32 node, uint32 voice, uint32 pitch, uint32 time)
{
    FUNCTION_MARKER(0x80011F24, "SLES_008.65");
    uint32 position = sub_80045464(node, time), listener = r_u32(0x800D5C8C), velocity[3];
    if (r_u32(0x800C8300) == 64) { velocity[0] = 0; velocity[1] = 0; velocity[2] = 0; }
    else
    {
        uint32 listener_node = r_u32(listener + 44);
        for (uint32 i = 0; i < 3; ++i) velocity[i] = r_u32(listener_node + 132 + i * 4);
    }
    uint32 relative[3];
    for (uint32 i = 0; i < 3; ++i) relative[i] = (r_s32(node + 132 + i * 4) >> 2) - ((sint32)velocity[i] >> 2);
    uint32 listener_position = sub_80045490(r_u32(listener + 44), time), separation[3];
    for (uint32 i = 0; i < 3; ++i) separation[i] = r_u32(listener_position + i * 4) - r_u32(position + i * 4);
    sint32 adjustment = 0;
    if (relative[0] | relative[1] | relative[2])
    {
        uint32 norm = relative[0] * relative[0] + relative[1] * relative[1] + relative[2] * relative[2];
        sint32 dot = (sint32)(relative[0] * separation[0] + relative[1] * separation[1] + relative[2] * separation[2]);
        if ((sint32)norm > 0x800000) norm = 0x800000;
        else if ((sint32)norm < -0x800000) norm = 0xFF800000;
        uint32 product = norm * 36;
        if (dot > 0) adjustment = (sint32)product / 0x800000;
        else if (dot < 0) adjustment = (sint32)(0 - product) / 0x800000;
    }
    return ob_main_80011D80(voice, pitch + adjustment);
}

uint32 ob_main_80046660(uint32 first, uint32 second, uint32 time)
{
    FUNCTION_MARKER(0x80046660, "SLES_008.65");
    uint32 major = first, minor = second;
    if (r_s32(second + 24) >= r_s32(first + 24)) { major = second; minor = first; }
    uint32 record = r_u32(r_u32(0x80077148) + r_u32(major + 24) * 4) + r_u32(minor + 24) * 8;
    uint32 old = r_u32(record);
    sub_80046BE8(major, minor, record, time);
    return sub_80047450(major, minor, record, old);
}

void ob_main_80015E98(uint32 text, uint32 output, uint32 count)
{
    FUNCTION_MARKER(0x80015E98, "SLES_008.65");
    uint32 character = r_u8(text);
    while (character && count)
    {
        ++text;
        uint32 encoded = ob_main_80015F70(character);
        w_u16(output, ((encoded & 255) << 8) | ((encoded & 0xFF00) >> 8));
        output += 2; character = r_u8(text); --count;
    }
    if (!character && (sint32)count > 0) w_u16(output, 0);
}

uint32 ob_main_80015F70(uint32 character)
{
    FUNCTION_MARKER(0x80015F70, "SLES_008.65");
    if ((uint8)(character - 32) >= 96) return 0;
    return r_u16(0x80065DFC + (uint8)character * 2);
}

uint32 ob_main_800452A4(uint32 node, uint32 time, uint32 output)
{
    FUNCTION_MARKER(0x800452A4, "SLES_008.65");
    sub_800454BC(node);
    uint32 words[4];
    for (uint32 i = 0; i < 4; ++i) words[i] = r_u32(node + 54 + i * 4);
    for (uint32 i = 0; i < 4; ++i) w_u32(output + i * 4, words[i]);
    uint32 result = r_s16(node + 70);
    w_u16(output + 16, result); return result;
}

uint32 ob_game_80091aa8(uint32 object)
{
    FUNCTION_MARKER(0x80091AA8, "GAME.BIN");
    return ob_game_800BCAA0(object);
}

uint32 ob_game_800bcf9c(uint32 object)
{
    FUNCTION_MARKER(0x800BCF9C, "GAME.BIN");
    return ob_game_800BCAA0(object);
}

sint32 ob_main_8001193c(void)
{
    FUNCTION_MARKER(0x8001193C, "SLES_008.65");
    return sub_8001DFF0();
}

uint32 ob_main_80026850(uint32 handle)
{
    FUNCTION_MARKER(0x80026850, "SLES_008.65");
    uint32 data = r_u32(handle);
    return r_u8(data - 8);
}

sint32 ob_main_8002c774(void)
{
    FUNCTION_MARKER(0x8002C774, "SLES_008.65");
    return -1;
}

void ob_main_8002da74(uint32 value)
{
    FUNCTION_MARKER(0x8002DA74, "SLES_008.65");
    w_u32(0x80077358, value);
}

uint32 ob_main_80050868(uint32 incoming_v0)
{
    FUNCTION_MARKER(0x80050868, "SLES_008.65");
    return incoming_v0;
}

sint32 ob_main_800513f0(void)
{
    FUNCTION_MARKER(0x800513F0, "SLES_008.65");
    return 0;
}

uint32 ob_game_800c1914(uint32 incoming_v0)
{
    FUNCTION_MARKER(0x800C1914, "GAME.BIN");
    return incoming_v0;
}

uint32 ob_main_8004372c(uint32 parent, uint32 type)
{
    FUNCTION_MARKER(0x8004372C, "SLES_008.65");
    return ob_find_first_typed_child(parent, type);
}

uint32 ob_main_8004374c(uint32 parent, sint32 identifier)
{
    FUNCTION_MARKER(0x8004374C, "SLES_008.65");
    return sub_800437C4(parent, identifier);
}

uint32 ob_main_8004376c(uint32 parent, uint32 type, uint32 identifier)
{
    FUNCTION_MARKER(0x8004376C, "SLES_008.65");
    return ob_find_typed_object(parent, type, identifier);
}

uint32 ob_game_800a70c8(void)
{
    FUNCTION_MARKER(0x800A70C8, "GAME.BIN");
    uint32 mask = 0;
    ob_snapshot_controller_flags();
    for (uint32 button = 0; button < 16; ++button)
    {
        if (ob_consume_button_edge(button))
            mask |= 1 << button;
    }
    return mask;
}

uint32 ob_game_800a712c(void)
{
    FUNCTION_MARKER(0x800A712C, "GAME.BIN");
    return ob_snapshot_controller_flags();
}

uint32 ob_game_800a714c(uint32 button)
{
    FUNCTION_MARKER(0x800A714C, "GAME.BIN");
    return ob_consume_button_edge(button & 255);
}

uint32 ob_game_800a71c8(void)
{
    FUNCTION_MARKER(0x800A71C8, "GAME.BIN");
    uint32 counter = ob_native_timers_get(0xF2000001);
    w_u16(0x800C82DC, counter);
    return counter;
}

uint32 ob_game_800a7284(void)
{
    FUNCTION_MARKER(0x800A7284, "GAME.BIN");
    uint32 counter = ob_native_timers_get(0xF2000001);
    w_u16(0x800C82E0, counter);
    return counter;
}

uint32 ob_game_800a72b0(void)
{
    FUNCTION_MARKER(0x800A72B0, "GAME.BIN");
    uint32 counter = ob_native_timers_get(0xF2000001);
    w_u16(0x800C82D8, counter);
    return counter;
}

uint32 ob_game_800a72dc(void)
{
    FUNCTION_MARKER(0x800A72DC, "GAME.BIN");
    uint32 counter = ob_native_timers_get(0xF2000001);
    w_u16(0x800C82D4, counter);
    return counter;
}

uint32 ob_game_800a7a60(uint32 object, uint32 first, uint32 second)
{
    FUNCTION_MARKER(0x800A7A60, "GAME.BIN");
    w_u32(object + 100, 0x800A7700);
    return ob_game_800BCB90(object, first, second);
}

uint32 ob_game_800a7cc4(uint32 object, uint32 first, uint32 second)
{
    FUNCTION_MARKER(0x800A7CC4, "GAME.BIN");
    w_u32(object + 100, 0x800A7C20);
    return ob_game_800BCB90(object, first, second);
}

sint32 ob_game_800a7a88(uint32 object, uint32 contact)
{
    FUNCTION_MARKER(0x800A7A88, "GAME.BIN");
    return sub_80047FF0(contact);
}

uint32 ob_game_800a991c(uint32 object, uint32 first, uint32 second)
{
    FUNCTION_MARKER(0x800A991C, "GAME.BIN");
    w_u32(object + 100, 0x800A9950);
    w_u32(object + 96, first);
    w_u32(object + 92, second);
    return ob_register_effect_object(object + 64);
}

uint32 ob_game_800a7c20(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800A7C20, "GAME.BIN");
    ob_game_800A6C34(object, 23, time);
    uint32 interval = ob_main_8001AFC8() / 4;
    w_u32(object + 316, time + interval + 4000);
    ob_main_80011A24(0x80067224, 128, 256, r_u32(object + 44), time, 0);
    interval = ob_main_8001AFC8() / 4;
    return ob_game_800a7cc4(object, 0, time + interval + 8000);
}

uint32 ob_game_800a9890(uint32 object)
{
    FUNCTION_MARKER(0x800A9890, "GAME.BIN");
    sub_8004E644(r_u32(object + 60));
    sub_8004651C(r_u32(object + 52));
    ob_free_geometry_object(r_u32(object + 48));
    sub_80045124(r_u32(object + 44));
    ob_game_800955B0(object);
    return ob_unlink_object_record(object);
}

uint32 ob_game_800a98f4(uint32 object)
{
    FUNCTION_MARKER(0x800A98F4, "GAME.BIN");
    uint32 cell = ob_draft_scratch_acquire(4);
    w_u32(cell, object);
    ob_game_800a9890(object);
    uint32 result = ob_release_pool_cell(cell);
    ob_draft_scratch_release(cell);
    return result;
}

uint32 ob_game_800a11d8(uint32 object)
{
    FUNCTION_MARKER(0x800A11D8, "GAME.BIN");
    sub_8004E644(r_u32(object + 60));
    ob_free_geometry_object(r_u32(object + 48));
    sub_80045124(r_u32(object + 44));
    ob_game_800955B0(object);
    return ob_unlink_object_record(object);
}

uint32 ob_game_800a1230(uint32 object)
{
    FUNCTION_MARKER(0x800A1230, "GAME.BIN");
    uint32 cell = ob_draft_scratch_acquire(4);
    w_u32(cell, object);
    ob_game_800a11d8(object);
    uint32 result = ob_release_pool_cell(cell);
    ob_draft_scratch_release(cell);
    return result;
}

uint32 ob_game_800a11a4(uint32 object, uint32 first, uint32 second)
{
    FUNCTION_MARKER(0x800A11A4, "GAME.BIN");
    w_u32(object + 100, 0x800A0FE8);
    w_u32(object + 96, first);
    w_u32(object + 92, second);
    return ob_register_effect_object(object + 64);
}

uint32 ob_game_800a23d0(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800A23D0, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    sint32 index = r_s16(data + 32);
    uint32 records = r_u32(data + 4);
    uint32 sound = r_u32(records + index * 24 + 16);
    return ob_main_80011A24(sound, 144, 64, r_u32(object + 44), time, 0);
}

sint32 ob_game_800a8ae8(uint32 first, uint32 second, uint32 time)
{
    FUNCTION_MARKER(0x800A8AE8, "GAME.BIN");
    sint32 heading = (sint16)ob_game_800A8A40(first, second, time);
    if (heading > 8192) return -9;
    if (heading < -8192) return 9;
    if (heading > 512) return -8;
    return heading < -512 ? 8 : 0;
}

uint32 ob_game_800a0d74(uint32 parent, uint32 attributes, uint32 time)
{
    FUNCTION_MARKER(0x800A0D74, "GAME.BIN");
    uint32 cell = ob_draft_scratch_acquire(4);
    w_u32(cell, 0);
    sub_800262CC(cell, 132);
    ob_game_800a0dd8(r_u32(cell), parent, attributes, time);
    uint32 result = r_u32(cell);
    ob_draft_scratch_release(cell);
    return result;
}

uint32 ob_game_800a0dd8(uint32 object, uint32 parent, uint32 attributes, uint32 time)
{
    FUNCTION_MARKER(0x800A0DD8, "GAME.BIN");
    sub_80043600(object, parent, 0);
    w_u32(object, 0x800C5334);
    ob_game_80095528(object, 1002, 0x800A1230, time);
    w_u32(object + 44, sub_80044E5C(object, 0x80073660, time));
    uint32 geometry = sub_80043E3C(object, 0x80073638);
    uint32 node = r_u32(object + 44);
    w_u32(object + 48, geometry);
    w_u32(node + 8, 0x10000001);
    w_u32(r_u32(object + 48) + 48, 0x10000001);
    if (r_s16(attributes + 52) < 2)
    {
        geometry = r_u32(object + 48);
        w_u32(geometry + 40, r_u32(attributes + 32));
        w_u32(object + 124, 0);
    }
    else
    {
        uint32 shape = r_u32(attributes + 32);
        geometry = r_u32(object + 48);
        w_u32(geometry + 40, r_u32(shape));
        w_u32(object + 124, r_u32(attributes + 32));
    }
    ob_resolve_shape_links(r_u32(object + 48));
    w_u16(r_u32(object + 48) + 56, 0);
    sub_80045848(r_u32(object + 44), attributes + 12);
    sub_800458B4(r_u32(object + 44), attributes, time);
    w_u32(r_u32(object + 44) + 132, 0);
    w_u32(r_u32(object + 44) + 136, 0);
    w_u32(r_u32(object + 44) + 140, 0);
    sub_80045ADC(r_u32(object + 44));
    uint32 local = ob_draft_scratch_acquire(8);
    w_u32(local, 0);
    w_u32(local + 4, 0);
    w_u32(object + 60, sub_8004E518(object, local, time, 6));
    w_u16(object + 112, r_u16(attributes + 44));
    w_u16(object + 114, r_u16(attributes + 46));
    uint32 data = r_u32(attributes + 36);
    sint32 animated = r_s16(object + 114);
    w_u32(object + 108, data);
    w_u32(object + 104, r_u32(attributes + 40));
    w_u16(object + 116, r_u16(attributes + 48));
    w_u16(object + 118, r_u16(attributes + 50));
    uint32 mode = r_u16(attributes + 52);
    w_u16(object + 122, 0);
    w_u16(object + 120, mode);
    if (animated)
        sub_800440B8(r_u32(object + 48), r_s16(object + 112));
    w_u16(object + 130, 0);
    uint32 result = r_u16(attributes + 54);
    data = r_u32(object + 108);
    w_u16(object + 128, result);
    if (data) result = ob_game_800a11a4(object, 0, time);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_800a0fe8(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800A0FE8, "GAME.BIN");
    uint32 previous = r_u32(object + 28);
    sint32 rotation_speed = r_s16(object + 128);
    w_u32(object + 28, time);
    uint32 elapsed = time - previous;
    if (rotation_speed)
    {
        ob_set_object_time(r_u32(object + 44), time);
        uint32 angle = r_u16(object + 130) + r_u16(object + 128);
        uint32 node = r_u32(object + 44);
        w_u16(object + 130, angle);
        uint32 matrix = ob_main_8004545C(node);
        ob_y_angle_matrix14(r_s16(object + 130), matrix);
        ob_invalidate_object_matrix(r_u32(object + 44));
    }
    uint32 lifetime = r_u32(object + 104);
    if (lifetime)
    {
        lifetime -= elapsed;
        w_u32(object + 104, lifetime);
        if ((sint32)lifetime <= 0) return ob_game_800a1230(object);
    }
    sint32 step = r_s16(object + 114);
    if (step)
    {
        uint32 angle = r_u16(object + 112) + step;
        uint32 geometry = r_u32(object + 48);
        w_u16(object + 112, angle);
        sub_800440B8(geometry, (sint16)angle);
        if (r_s16(object + 112) >= r_s16(object + 118))
            w_u16(object + 114, 0 - r_u16(object + 114));
        if (r_s16(object + 116) >= r_s16(object + 112))
            w_u16(object + 114, 0 - r_u16(object + 114));
    }
    uint32 frames = r_u32(object + 124);
    if (frames)
    {
        sint32 index = r_s16(object + 122);
        uint32 geometry = r_u32(object + 48);
        w_u32(geometry + 40, r_u32(frames + index * 4));
        sint32 next = r_s16(object + 122) + 1;
        sint32 count = r_s16(object + 120);
        if (!count) ob_native_guest_break(0x800A0FE8, 7);
        /* The signed halfword index plus one cannot reach INT32_MIN */
        w_u16(object + 122, next % count);
    }
    return ob_game_800a11a4(object, context, time + r_u32(object + 108));
}

uint32 ob_game_80094724(uint32 index, uint32 distance, uint32 angle, uint32 enabled)
{
    FUNCTION_MARKER(0x80094724, "GAME.BIN");
    uint32 offset = index * 28;
    w_u32(0x800C4D28 + offset, distance * 2000 + 7000);
    w_u16(0x800C4D24 + offset, (angle << 9) + 4096);
    w_u32(0x800C4D3C + offset, enabled ? 0 : 8);
    w_u32(0x800C4D18, index);
    return ob_game_80093D00(index);
}

uint32 ob_game_80094964(uint32 object, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x80094964, "GAME.BIN");
    uint32 attributes = r_u32(object + 56);
    ob_set_object_time(r_u32(object + 44), time);
    if (r_s16(attributes + 164))
    {
        uint32 node = r_u32(object + 44);
        w_u32(node + 132, 0 - r_u32(node + 132));
    }
    if (r_s16(attributes + 168))
    {
        uint32 node = r_u32(object + 44);
        w_u32(node + 140, 0 - r_u32(node + 140));
    }
    return sub_80045ADC(r_u32(object + 44));
}

uint32 ob_game_800974c8(uint32 descriptor, uint32 context)
{
    FUNCTION_MARKER(0x800974C8, "GAME.BIN");
    uint32 cell = ob_draft_scratch_acquire(4);
    w_u32(cell, 0);
    sub_800262CC(cell, 16);
    uint32 slot = r_u32(cell);
    if (slot) ob_game_80097524(slot, descriptor, context);
    uint32 result = r_u32(cell);
    ob_draft_scratch_release(cell);
    return result;
}

uint32 ob_game_800976e4(uint32 object, uint32 position, uint32 angle, uint32 distance, uint32 time)
{
    FUNCTION_MARKER(0x800976E4, "GAME.BIN");
    uint32 offset = (((angle & 65535) + 8) >> 4) * 2;
    uint32 dx = distance * r_s16(0x8006C304 + offset);
    w_u32(0x800C84CC, r_u32(position) + dx);
    w_u32(0x800C84D0, r_u32(position + 4));
    uint32 dz = distance * r_s16(0x8006CB04 + offset);
    w_u32(0x800C84D4, r_u32(position + 8) + dz);
    return ob_game_80097578(object, 0x800C84C0, time);
}

uint32 ob_game_800979f0(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800979F0, "GAME.BIN");
    uint32 previous = r_u32(object + 28);
    sint32 remaining = r_s16(object + 328);
    uint32 controller = r_u32(object + 112);
    uint32 elapsed = time - previous;
    if (remaining < 1000)
    {
        w_u16(object + 328, 4000);
        uint32 direction;
        do
        {
            direction = (ob_main_8001AFC8() & 7) - 3;
            w_u16(object + 320, direction);
        } while ((uint16)direction == 0);
    }
    else w_u16(object + 328, remaining - elapsed);
    uint32 scale = r_u16(r_u32(controller) + 6);
    uint32 delta = scale * elapsed * r_u16(object + 320);
    uint32 rotation = r_u32(object + 124);
    uint32 result = r_u16(rotation + 4) + delta;
    w_u16(rotation + 4, result);
    return result;
}

uint32 ob_game_80097ab4(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x80097AB4, "GAME.BIN");
    uint32 attributes = r_u32(object + 116);
    uint32 candidate = r_u16(attributes + 44);
    uint32 controller = r_u32(object + 112);
    if (((candidate + 32700) & 65535) > 0xFF78)
        candidate += 60 * ((ob_main_8001AFC8() & 6) - 3);
    uint32 elapsed = time - r_u32(object + 28);
    uint32 sign = 1;
    if ((sint16)candidate < 0)
    {
        sign = 0xFFFFFFFF;
        candidate = 0 - (uint32)(sint32)(sint16)candidate;
    }
    uint32 configuration = r_u32(controller);
    uint32 limit = r_u16(configuration + 4) * elapsed;
    sint32 magnitude = (sint16)candidate;
    uint32 adjustment = sign * limit;
    uint32 apply = magnitude >= (sint32)limit;
    if (!apply)
    {
        limit = r_u16(configuration + 6) * elapsed;
        adjustment = sign * limit;
        apply = (sint32)limit < magnitude;
    }
    if (apply)
    {
        uint32 rotation = r_u32(object + 124);
        w_u16(rotation + 4, r_u16(rotation + 4) + adjustment);
    }
    return (sint16)candidate != r_s16(attributes + 44);
}

sint32 ob_game_800a3270(sint32 threshold, uint32 layer)
{
    FUNCTION_MARKER(0x800A3270, "GAME.BIN");
    sint32 slot = (sint16)layer;
    uint32 grid = 0x800D5EA4 + slot * 504;
    ob_fill_words(grid, 504, 0xFEFEFEFE, 0x800D5EA4);
    w_u16(0x800C6270, 10);
    w_u16(0x800C6272, 10);
    w_u16(0x800C627C, 65535);
    w_u16(0x800C6274, 0);
    w_u32(0x800C81B0, 0);
    w_u32(0x800C81B4, 1);
    w_u8(grid + 250, 0);
    w_u16(0x800C81C0, r_s8(0x800D648C + slot));
    w_u16(0x800C81C4, r_s8(0x800D648F + slot));
    uint32 depth = 0;
    sint32 result;
    do
    {
        result = ob_game_800a3384(threshold, slot, depth);
        ++depth;
    } while (result != -1);
    return result;
}

sint32 ob_game_800a3384(sint32 threshold, uint32 layer, uint32 depth)
{
    FUNCTION_MARKER(0x800A3384, "GAME.BIN");
    sint32 slot = (sint16)layer;
    uint32 grid = 0x800D5EA4 + slot * 504;
    for (;;)
    {
        uint32 offset = r_u32(0x800C81B0) * 8;
        sint32 column = r_s16(0x800C6270 + offset);
        sint32 distance = r_s16(0x800C6274 + offset);
        sint32 row = r_s16(0x800C6272 + offset);
        if (distance == -1) return -1;
        if ((sint32)depth < distance) return 0;
        uint32 cell = grid + column * 24 + row;
        if (column - 1 >= 0 && r_s8(cell - 24) == -2)
            ob_game_800a3574(threshold, (sint16)depth, slot, column - 1, row);
        if (column + 1 < 21 && r_s8(cell + 24) == -2)
            ob_game_800a3574(threshold, (sint16)depth, slot, column + 1, row);
        if (row - 1 >= 0 && r_s8(cell - 1) == -2)
            ob_game_800a3574(threshold, (sint16)depth, slot, column, row - 1);
        if (row + 1 < 21 && r_s8(cell + 1) == -2)
            ob_game_800a3574(threshold, (sint16)depth, slot, column, row + 1);
        w_u32(0x800C81B0, r_u32(0x800C81B0) + 1);
    }
}

uint32 ob_game_800a3574(sint32 threshold, uint32 depth, uint32 layer, uint32 column, uint32 row)
{
    FUNCTION_MARKER(0x800A3574, "GAME.BIN");
    uint32 map_row = row + r_s16(0x800C81C4);
    uint32 map_index = map_row * r_s16(0x800C90F2);
    map_index += column + r_s16(0x800C81C0);
    uint32 map = r_u32(0x800C90D0);
    sint32 height = r_s32(map + map_index * 4);
    uint32 cell = 0x800D5EA4 + (sint16)layer * 504 + column * 24 + row;
    if (threshold < height)
    {
        w_u8(cell, 255);
        return cell;
    }
    w_u8(cell, depth + 1);
    uint32 tail = r_u32(0x800C81B4);
    uint32 offset = tail * 8;
    ++tail;
    w_u32(0x800C81B4, tail);
    uint32 result = tail * 8;
    w_u16(0x800C6270 + offset, column);
    w_u16(0x800C6272 + offset, row);
    w_u16(0x800C6274 + offset, depth + 1);
    w_u16(0x800C6274 + result, 65535);
    return result;
}

uint32 ob_game_800a55ec(uint32 count_pointer_v0)
{
    FUNCTION_MARKER(0x800A55EC, "GAME.BIN");
    uint32 count = r_u16(count_pointer_v0);
    w_u16(0x800D649C, 0);
    if (count)
    {
        uint32 mode = r_u8(0x8006C22C);
        uint32 record = r_u32(0x80077194);
        for (uint32 index = 0; index < count; ++index, record += 28)
        {
            if (mode == 0 && !(r_u8(record + 24) & 1)) continue;
            if (mode == 1 && !(r_u8(record + 24) & 2)) continue;
            if (mode == 2 && !(r_u8(record + 24) & 4)) continue;
            if (r_u32(record + 12) - 229 >= 2) continue;
            if (r_u16(record + 18) != 18) continue;
            w_u16(0x800D649C, r_u16(0x800D649C) + 1);
        }
    }
    return 0;
}

uint32 ob_game_800a62b0(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800A62B0, "GAME.BIN");
    ob_set_object_time(r_u32(object + 44), time);
    ob_main_80011A24(0x80067588, 78, 256, r_u32(object + 44), time, 0);
    uint32 node = r_u32(object + 44);
    w_u32(node + 132, r_s32(node + 132) / 4);
    w_u32(r_u32(object + 44) + 136, 0);
    node = r_u32(object + 44);
    w_u32(node + 140, r_s32(node + 140) / 4);
    uint32 result = sub_80045ADC(r_u32(object + 44));
    w_u32(object + 104, 0);
    return result;
}

uint32 ob_game_800a6e38(void)
{
    FUNCTION_MARKER(0x800A6E38, "GAME.BIN");
    uint32 record = r_u32(r_u32(0x800C5450) + 8);
    uint32 enabled = r_u32(0x800D64B8);
    uint32 object = r_u32(record);
    if (!enabled) return object;
    return ob_game_800a6e58(object);
}

uint32 ob_game_800a6e58(uint32 object_v0)
{
    FUNCTION_MARKER(0x800A6E58, "GAME.BIN");
    uint32 count = r_u32(0x800C84DC);
    uint32 value = r_u32(object_v0 + 136);
    w_u32(0x800C830C, value);
    if (count < 512)
    {
        w_u32(0x800C84DC, count + 1);
        uint32 tail = r_u32(0x800C8348);
        w_u32(0x800C84DC, count + 2);
        uint32 next = (tail + 1) & 511;
        w_u32(0x800C9110 + tail * 4, value);
        w_u32(0x800C8348, next);
        uint32 second = r_u32(0x800C8560);
        w_u32(0x800C8348, (next + 1) & 511);
        w_u32(0x800C9110 + next * 4, second);
    }
    uint32 record = r_u32(0x800C8310);
    w_u32(record + 16, 0);
    w_u32(record + 12, 0);
    return record;
}

uint32 ob_game_800ac648(uint32 object, uint32 context, uint32 sequence_v1)
{
    FUNCTION_MARKER(0x800AC648, "GAME.BIN");
    uint32 destination = sequence_v1 & 1 ? 0x800D5D18 : 0x800D5DD8;
    w_u32(0x800C8330, sequence_v1 + 1);
    ob_game_800C0FC8(destination, r_u32(object + 44), 164);
    uint32 rotation = r_u32(object + 124);
    if (rotation)
        ob_game_800C0FC8(destination + 164, rotation, 16);
    else
    {
        w_u32(destination + 164, 0);
        w_u16(destination + 168, 0);
        w_u32(destination + 172, 0);
    }
    w_u32(destination + 180, r_u32(object + 112));
    uint32 result = r_u16(object + 302);
    w_u8(destination + 186, context);
    w_u16(destination + 184, result);
    return result;
}

uint32 ob_game_800ad5e8(uint32 object, uint32 node_handle, uint32 geometry_handle, uint32 time)
{
    FUNCTION_MARKER(0x800AD5E8, "GAME.BIN");
    uint32 node = r_u32(node_handle);
    if (node & 3)
        node = sub_800257CC(node_handle);
    else
    {
        w_u16(node - 6, r_u16(node - 6) + 1);
        node = r_u32(node_handle);
    }
    w_u32(object + 44, sub_80044E5C(object, node, time));
    ob_memory_release_reference(node_handle);
    uint32 geometry = r_u32(geometry_handle);
    if (geometry & 3)
        geometry = sub_800257CC(geometry_handle);
    else
    {
        w_u16(geometry - 6, r_u16(geometry - 6) + 1);
        geometry = r_u32(geometry_handle);
    }
    w_u32(object + 48, sub_80043E3C(object, geometry));
    ob_memory_release_reference(geometry_handle);
    return sub_80045A44(r_u32(object + 44), 0x8006C160);
}

uint32 ob_main_8001373c(uint32 index)
{
    FUNCTION_MARKER(0x8001373C, "SLES_008.65");
    ob_draft_unresolved_call(0x80063FD8, 3, 0x80089D28 + index * 552, 0, 552);
    return ob_draft_unresolved_call(0x80063FD8, 3, 0x80084AC8, 0, 7680);
}

sint32 ob_main_80014bac(uint32 object)
{
    FUNCTION_MARKER(0x80014BAC, "SLES_008.65");
    uint32 local = ob_draft_scratch_acquire(16);
    ob_main_80028a58(object + 12, local);
    sub_80028280(r_s16(local), r_s16(local + 4), local + 8, local + 12);
    uint32 angle = 0x4000 - r_u16(local + 8);
    w_u16(local + 8, angle);
    ob_draft_scratch_release(local);
    return (sint16)angle;
}

sint32 ob_main_800231a4(void)
{
    FUNCTION_MARKER(0x800231A4, "SLES_008.65");
    ob_main_8002D888();
    return ob_main_8002c774();
}

uint32 ob_main_8002682c(uint32 handle)
{
    FUNCTION_MARKER(0x8002682C, "SLES_008.65");
    return ob_main_8002794c(r_u32(handle) - 40);
}

uint32 ob_main_80027920(uint32 block)
{
    FUNCTION_MARKER(0x80027920, "SLES_008.65");
    uint32 next = r_u32(block + 12);
    uint32 previous = r_u32(block + 8);
    uint32 head = r_u32(0x80077228);
    w_u32(previous + 12, next);
    w_u32(next + 8, previous);
    next = r_u32(head + 12);
    w_u32(block + 8, head);
    w_u32(block + 12, next);
    w_u32(head + 12, block);
    w_u32(next + 8, block);
    return head;
}

uint32 ob_main_8002794c(uint32 block)
{
    FUNCTION_MARKER(0x8002794C, "SLES_008.65");
    uint32 previous = r_u32(block + 8);
    uint32 next = r_u32(block + 12);
    uint32 head = r_u32(0x8007722C);
    w_u32(previous + 12, next);
    w_u32(next + 8, previous);
    previous = r_u32(head + 8);
    w_u32(block + 12, head);
    w_u32(block + 8, previous);
    w_u32(head + 8, block);
    w_u32(previous + 12, block);
    return head;
}

uint32 ob_main_80028a58(uint32 source, uint32 destination)
{
    FUNCTION_MARKER(0x80028A58, "SLES_008.65");
    w_u16(destination, r_u16(source));
    w_u16(destination + 2, r_u16(source + 2));
    uint32 result = r_u16(source + 4);
    w_u16(destination + 4, result);
    return result;
}

uint32 ob_main_8002568c(uint32 identifier)
{
    FUNCTION_MARKER(0x8002568C, "SLES_008.65");
    uint32 handle = ob_memory_slot_address(identifier & 65535);
    uint32 flags = r_u32(handle) & 3;
    if (flags == 1) return sub_80025A9C(handle);
    return flags;
}

uint32 ob_main_8002575c(uint32 identifier)
{
    FUNCTION_MARKER(0x8002575C, "SLES_008.65");
    uint32 data = r_u32(ob_memory_slot_address(identifier & 65535));
    uint32 result = data & 3;
    if (!result)
    {
        result = r_u16(data - 6) - 1;
        w_u16(data - 6, result);
    }
    return result;
}

uint32 ob_main_80025834(uint32 handle)
{
    FUNCTION_MARKER(0x80025834, "SLES_008.65");
    uint32 data = r_u32(handle);
    uint32 flags = data & 3;
    if (flags) return flags;
    w_u16(data - 4, r_u16(data - 4) - 1);
    return ob_main_800267ec(handle);
}

uint32 ob_main_80025894(uint32 handle)
{
    FUNCTION_MARKER(0x80025894, "SLES_008.65");
    uint32 data = r_u32(handle);
    if (!data || (data & 3)) return 0;
    ob_main_800267ec(handle);
    return ob_memory_payload_size(handle);
}

uint32 ob_main_800258ec(uint32 identifier)
{
    FUNCTION_MARKER(0x800258EC, "SLES_008.65");
    uint32 handle = ob_memory_slot_address(identifier & 65535);
    uint32 data = r_u32(handle);
    uint32 flags = data & 3;
    if (data && !flags) return ob_main_8002682c(handle);
    return flags;
}

uint32 ob_main_80025930(uint32 handle)
{
    FUNCTION_MARKER(0x80025930, "SLES_008.65");
    uint32 data = r_u32(handle);
    uint32 flags = data & 3;
    if (data && !flags) return ob_main_8002682c(handle);
    return flags;
}

uint32 ob_main_80025968(uint32 identifier)
{
    FUNCTION_MARKER(0x80025968, "SLES_008.65");
    uint32 handle = ob_memory_slot_address(identifier & 65535);
    uint32 data = r_u32(handle);
    uint32 flags = data & 3;
    if (data && !flags) return sub_80026758(handle);
    return flags;
}

uint32 ob_main_800259e4(uint32 identifier)
{
    FUNCTION_MARKER(0x800259E4, "SLES_008.65");
    uint32 handle = ob_memory_slot_address(identifier & 65535);
    uint32 data = r_u32(handle);
    uint32 result = data & 3;
    if (data && !result)
    {
        result = ob_main_80026850(handle) & 8;
        if (result) return sub_800259AC(handle);
    }
    return result;
}

uint32 ob_main_80025a44(uint32 handle)
{
    FUNCTION_MARKER(0x80025A44, "SLES_008.65");
    uint32 data = r_u32(handle);
    uint32 result = data & 3;
    if (data && !result)
    {
        result = ob_main_80026850(handle) & 8;
        if (result) return sub_800259AC(handle);
    }
    return result;
}

uint32 ob_main_80026530(uint32 index)
{
    FUNCTION_MARKER(0x80026530, "SLES_008.65");
    uint32 offset = (index & 255) * 16;
    ob_main_80026bc0(r_u8(0x80078E48 + offset));
    uint32 flags = r_u8(0x80078E48 + offset);
    uint32 active = r_u8(0x80077250);
    w_u32(0x80078E54 + offset, 0);
    uint32 result = ~flags;
    w_u8(0x80077250, active & result);
    return result;
}

uint32 ob_main_8002662c(uint32 index)
{
    FUNCTION_MARKER(0x8002662C, "SLES_008.65");
    return ob_main_80026c18(r_u8(0x80078E48 + (index & 255) * 16));
}

uint32 ob_main_80026660(uint32 index)
{
    FUNCTION_MARKER(0x80026660, "SLES_008.65");
    return ob_main_80026ca4(r_u8(0x80078E48 + (index & 255) * 16));
}

uint32 ob_main_800267ec(uint32 handle)
{
    FUNCTION_MARKER(0x800267EC, "SLES_008.65");
    uint32 data = r_u32(handle);
    ob_main_80027920(data - 40);
    uint32 result = r_u8(data - 7) | r_u8(0x8007724C);
    w_u8(data - 7, result);
    return result;
}

uint32 ob_main_80026bc0(uint32 mask)
{
    FUNCTION_MARKER(0x80026BC0, "SLES_008.65");
    uint32 block = r_u32(r_u32(0x80077228) + 12);
    while (r_u32(block + 12))
    {
        uint32 flags = r_u8(block + 33);
        if (mask & flags) w_u8(block + 33, flags ^ mask);
        block = r_u32(block + 12);
    }
    return 0;
}

uint32 ob_main_80026c18(uint32 mask)
{
    FUNCTION_MARKER(0x80026C18, "SLES_008.65");
    uint32 head = r_u32(0x8007722C);
    uint32 remaining = r_u32(0x80077240) - 1;
    uint32 block = r_u32(head + 8);
    uint32 next = r_u32(block + 8);
    uint32 result = 0xFFFFFFFF;
    if (remaining != 0xFFFFFFFF)
    {
        do
        {
            uint32 flags = r_u8(block + 33);
            result = flags ^ mask;
            if (mask & flags)
            {
                w_u8(block + 33, result);
                result = ob_main_80027920(block);
            }
            block = next;
            next = r_u32(next + 8);
            --remaining;
        } while (remaining != 0xFFFFFFFF);
    }
    return result;
}

uint32 ob_main_80026ca4(uint32 mask)
{
    FUNCTION_MARKER(0x80026CA4, "SLES_008.65");
    uint32 head = r_u32(0x80077228);
    uint32 remaining = r_u32(0x80077240) - 1;
    uint32 block = r_u32(head + 12);
    uint32 next = r_u32(block + 8);
    uint32 result = 0xFFFFFFFF;
    if (remaining != 0xFFFFFFFF)
    {
        do
        {
            result = mask & r_u8(block + 33);
            if (result) result = ob_main_8002794c(block);
            block = next;
            next = r_u32(next + 8);
            --remaining;
        } while (remaining != 0xFFFFFFFF);
    }
    return result;
}

uint32 ob_main_800252dc(uint32 handle)
{
    FUNCTION_MARKER(0x800252DC, "SLES_008.65");
    uint32 cell = ob_draft_scratch_acquire(4);
    w_u32(cell, 0);
    sub_800256CC(handle);
    uint32 size = ob_memory_payload_size(handle);
    sub_80026694(cell, size, 0);
    ob_draft_unresolved_call(0x80063FC8, 3, r_u32(cell), r_u32(handle), size);
    sub_80026758(handle);
    uint32 record = r_u32(cell) + 20;
    uint32 index = 1;
    while ((sint32)index < r_s32(r_u32(cell) + 8))
    {
        uint32 value = r_u32(record);
        record += 4;
        if (value != 1)
        {
            uint32 entry = ob_memory_slot_address(index & 65535);
            if (r_u32(entry) != 1) sub_800256CC(entry);
        }
        ++index;
    }
    uint32 result = sub_80026758(cell);
    ob_draft_scratch_release(cell);
    return result;
}

uint32 ob_main_800253c4(uint32 handle)
{
    FUNCTION_MARKER(0x800253C4, "SLES_008.65");
    sub_800256CC(handle);
    ob_memory_lock_handle(handle, 1);
    uint32 data = r_u32(handle);
    uint32 record = data + 20;
    uint32 index = 1;
    while ((sint32)index < r_s32(data + 8))
    {
        uint32 value = r_u32(record);
        record += 4;
        if (value != 1)
        {
            uint32 entry = ob_memory_slot_address(index & 65535);
            if (!(r_u32(entry) & 3)) sub_80026758(entry);
            w_u32(entry, 1);
        }
        ++index;
    }
    ob_memory_unlock_handle(handle, 1);
    return sub_80026758(handle);
}

uint32 ob_main_800254a8(uint32 incoming_counter_v0)
{
    FUNCTION_MARKER(0x800254A8, "SLES_008.65");
    if (!incoming_counter_v0)
    {
        for (uint32 index = 1; index < r_u16(0x800775F2); ++index)
        {
            uint32 data = r_u32(ob_memory_slot_address(index & 65535));
            if (data && !(data & 3))
                w_u16(data - 6, r_u16(data - 6) + 1);
        }
    }
    uint32 result = r_u32(0x8007708C) + 1;
    w_u32(0x8007708C, result);
    return result;
}

uint32 ob_main_80025538(uint32 incoming_counter_v0)
{
    FUNCTION_MARKER(0x80025538, "SLES_008.65");
    uint32 result = incoming_counter_v0 - 1;
    w_u32(0x8007708C, result);
    if (result) return result;
    for (uint32 index = 1; index < r_u16(0x800775F2); ++index)
    {
        uint32 data = r_u32(ob_memory_slot_address(index & 65535));
        if (data && !(data & 3))
            w_u16(data - 6, r_u16(data - 6) - 1);
    }
    return 0;
}

uint32 ob_main_80027c28(uint32 identifier)
{
    FUNCTION_MARKER(0x80027C28, "SLES_008.65");
    uint32 tables = r_u32(0x800775F4);
    uint32 table = r_u32(tables + ((identifier >> 6) & 0x3FC));
    uint32 index = identifier & 255;
    uint32 handle = r_u32(table) + index * 4;
    uint32 data = r_u32(handle);
    if (data && !(data & 1)) sub_80026758(handle);
    uint32 bitmap = table + (index >> 3);
    w_u32(handle, 0);
    w_u16(table + 4, r_u16(table + 4) + 1);
    uint32 result = ~(128 >> (index & 7));
    w_u8(bitmap + 6, r_u8(bitmap + 6) & result);
    return result;
}

uint32 ob_main_80028a7c(uint32 source, uint32 destination)
{
    FUNCTION_MARKER(0x80028A7C, "SLES_008.65");
    ob_main_80028a58(source, destination);
    return sub_80028614(destination) & 65535;
}

uint32 ob_main_80028e3c(uint32 vector)
{
    FUNCTION_MARKER(0x80028E3C, "SLES_008.65");
    sint32 x = r_s16(vector);
    sint32 y = r_s16(vector + 2);
    sint32 z = r_s16(vector + 4);
    uint32 squared = x * x;
    squared += y * y;
    squared += z * z;
    return sub_8002B868(squared) & 65535;
}

uint32 ob_main_80028e94(uint32 vector)
{
    FUNCTION_MARKER(0x80028E94, "SLES_008.65");
    sint32 x = r_s16(vector);
    sint32 y = r_s16(vector + 2);
    sint32 z = r_s16(vector + 4);
    uint32 squared = x * x;
    squared += y * y;
    squared += z * z;
    return ob_main_8002b904(squared) & 65535;
}

uint32 ob_main_800298dc(uint32 vector)
{
    FUNCTION_MARKER(0x800298DC, "SLES_008.65");
    uint32 x = r_u32(vector);
    uint32 y = r_u32(vector + 4);
    uint32 z = r_u32(vector + 8);
    return sub_8002B868(x * x + y * y + z * z) & 65535;
}

uint32 ob_main_80029934(uint32 vector)
{
    FUNCTION_MARKER(0x80029934, "SLES_008.65");
    return ob_main_80029954(vector);
}

uint32 ob_main_80029954(uint32 vector)
{
    FUNCTION_MARKER(0x80029954, "SLES_008.65");
    uint32 local = ob_draft_scratch_acquire(8);
    uint32 shift = sub_800292EC(vector, local);
    uint32 length = ob_main_80028e3c(local) & 65535;
    ob_draft_scratch_release(local);
    return length << (shift & 31);
}

uint32 ob_main_8002a2b0(uint32 matrix)
{
    FUNCTION_MARKER(0x8002A2B0, "SLES_008.65");
    return ob_main_800287d4(matrix + 6, matrix + 12, matrix);
}

uint32 ob_main_8002a2d8(uint32 matrix)
{
    FUNCTION_MARKER(0x8002A2D8, "SLES_008.65");
    return ob_main_800287d4(matrix + 12, matrix, matrix + 6);
}

uint32 ob_main_8002a300(uint32 matrix)
{
    FUNCTION_MARKER(0x8002A300, "SLES_008.65");
    return ob_main_800287d4(matrix, matrix + 6, matrix + 12);
}

uint32 ob_main_800287d4(uint32 first, uint32 second, uint32 output)
{
    FUNCTION_MARKER(0x800287D4, "SLES_008.65");
    sint32 ay = r_s16(first + 2);
    sint32 bz = r_s16(second + 4);
    sint32 az = r_s16(first + 4);
    sint32 by = r_s16(second + 2);
    sint32 bx = r_s16(second);
    sint32 ax = r_s16(first);
    uint32 x = ay * bz;
    x -= az * by;
    uint32 y = az * bx;
    y -= ax * bz;
    uint32 z = ax * by;
    uint32 result = -ay * bx;
    z += result;
    w_u16(output, (sint32)x >> 14);
    w_u16(output + 2, (sint32)y >> 14);
    w_u16(output + 4, (sint32)z >> 14);
    return result;
}

uint32 ob_main_8002b904(uint32 value)
{
    FUNCTION_MARKER(0x8002B904, "SLES_008.65");
    if (!value) return 0;
    uint32 shift = 0;
    while (!(value & 0xC0000000))
    {
        value <<= 2;
        ++shift;
    }
    uint32 index = ((value >> 23) + 1) >> 1;
    value = r_u32(0x80073110 + index * 4);
    if (shift) value = (value + (1 << (shift - 1))) >> shift;
    return value & 65535;
}

uint32 ob_main_80043924(void)
{
    FUNCTION_MARKER(0x80043924, "SLES_008.65");
    uint32 cell = ob_draft_scratch_acquire(4);
    w_u32(cell, 0);
    sub_800262CC(cell, 16);
    ob_init_object_list(r_u32(cell));
    uint32 result = r_u32(cell);
    ob_draft_scratch_release(cell);
    return result;
}

uint32 ob_main_80043994(uint32 list)
{
    FUNCTION_MARKER(0x80043994, "SLES_008.65");
    uint32 cell = ob_draft_scratch_acquire(4);
    w_u32(cell, list);
    ob_clear_owner_references(list);
    uint32 result = ob_release_pool_cell(cell);
    ob_draft_scratch_release(cell);
    return result;
}

uint32 ob_main_80043e88(uint32 object, uint32 parent, uint32 data)
{
    FUNCTION_MARKER(0x80043E88, "SLES_008.65");
    uint32 cursor = ob_draft_scratch_acquire(4);
    w_u32(cursor, data);
    uint32 result = sub_80043EAC(object, parent, cursor);
    ob_draft_scratch_release(cursor);
    return result;
}

uint32 ob_main_800442b0(uint32 parent, uint32 object)
{
    FUNCTION_MARKER(0x800442B0, "SLES_008.65");
    uint32 first = r_u32(parent + 36);
    uint32 field = parent + 36;
    if (first != object)
    {
        uint32 next;
        do
        {
            uint32 node = r_u32(field);
            next = r_u32(node + 40);
            field = node + 40;
        } while (next != object);
    }
    uint32 result = r_u32(object + 40);
    w_u32(field, result);
    w_u32(object + 40, 0);
    w_u32(object + 36, 0);
    return result;
}

uint32 ob_main_800445b0(uint32 parent, uint32 data)
{
    FUNCTION_MARKER(0x800445B0, "SLES_008.65");
    uint32 local = ob_draft_scratch_acquire(8);
    w_u32(local + 4, data);
    w_u32(local, 0);
    sub_800262CC(local, 56);
    ob_main_80044620(r_u32(local), parent, local + 4);
    uint32 result = r_u32(local);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_main_800445fc(uint32 object, uint32 parent, uint32 data)
{
    FUNCTION_MARKER(0x800445FC, "SLES_008.65");
    uint32 cursor = ob_draft_scratch_acquire(4);
    w_u32(cursor, data);
    uint32 result = ob_main_80044620(object, parent, cursor);
    ob_draft_scratch_release(cursor);
    return result;
}

uint32 ob_main_800447fc(uint32 object)
{
    FUNCTION_MARKER(0x800447FC, "SLES_008.65");
    uint32 cell = ob_draft_scratch_acquire(4);
    w_u32(cell, object);
    ob_main_8004472c(object);
    uint32 result = ob_release_pool_cell(cell);
    ob_draft_scratch_release(cell);
    return result;
}

uint32 ob_main_80044824(uint32 object)
{
    FUNCTION_MARKER(0x80044824, "SLES_008.65");
    return ob_main_80044844(object);
}

uint32 ob_main_80044844(uint32 object)
{
    FUNCTION_MARKER(0x80044844, "SLES_008.65");
    uint32 parent = r_u32(object + 24);
    uint32 result = r_u32(parent + 28);
    if (object == result) w_u32(parent + 28, 0);
    else w_u32(parent + 32, 0);
    w_u32(object + 24, 0);
    return result;
}

uint32 ob_main_80044870(uint32 object, uint32 incoming_v0)
{
    FUNCTION_MARKER(0x80044870, "SLES_008.65");
    return ob_main_80044894(object, r_u32(object + 12), incoming_v0);
}

uint32 ob_main_80044eb8(uint32 object, uint32 parent, uint32 data, uint32 time)
{
    FUNCTION_MARKER(0x80044EB8, "SLES_008.65");
    uint32 cursor = ob_draft_scratch_acquire(4);
    w_u32(cursor, data);
    uint32 result = sub_80044EDC(object, parent, cursor, time);
    ob_draft_scratch_release(cursor);
    return result;
}

uint32 ob_main_80045194(uint32 parent, uint32 object)
{
    FUNCTION_MARKER(0x80045194, "SLES_008.65");
    uint32 first = r_u32(parent + 32);
    uint32 field = parent + 32;
    if (first)
    {
        uint32 next;
        do
        {
            uint32 node = r_u32(field);
            next = r_u32(node + 28);
            field = node + 28;
        } while (next);
    }
    w_u32(field, object);
    w_u32(object + 24, parent);
    return ob_invalidate_object_matrix(object);
}

uint32 ob_main_80045804(uint32 object)
{
    FUNCTION_MARKER(0x80045804, "SLES_008.65");
    ob_identity_matrix14(object + 36);
    ob_invalidate_object_matrix(object);
    uint32 result = r_u32(object + 160) | 8;
    w_u32(object + 160, result);
    return result;
}

uint32 ob_main_80044620(uint32 object, uint32 parent, uint32 cursor)
{
    FUNCTION_MARKER(0x80044620, "SLES_008.65");
    uint32 data = r_u32(cursor);
    sub_80043600(object, parent, r_u32(data));
    w_u32(object, 0x80077110);
    w_u32(object + 24, 0);
    w_u32(object + 28, 0);
    w_u32(object + 32, 0);
    w_u32(object + 36, 0);
    w_u32(object + 40, 0);
    uint32 identifier = r_u32(data + 4);
    w_u32(object + 48, 0);
    w_u32(object + 44, identifier);
    w_u16(object + 52, r_u16(data + 8));
    w_u32(cursor, r_u32(cursor) + 20);
    uint32 cell = ob_draft_scratch_acquire(4);
    if (r_u32(data + 12))
    {
        w_u32(cell, 0);
        sub_800262CC(cell, 56);
        ob_main_80044620(r_u32(cell), object, cursor);
        uint32 child = r_u32(cell);
        w_u32(object + 28, child);
        w_u32(child + 24, object);
    }
    if (r_u32(data + 16))
    {
        w_u32(cell, 0);
        sub_800262CC(cell, 56);
        ob_main_80044620(r_u32(cell), object, cursor);
        uint32 child = r_u32(cell);
        w_u32(object + 32, child);
        w_u32(child + 24, object);
    }
    ob_draft_scratch_release(cell);
    return object;
}
