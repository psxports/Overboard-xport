#include "psx.h"
#include "draft_signatures.h"
#include "native_extra_signatures.h"
#include "native_runtime.h"
#include "game_signatures.h"

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
    uint32 end = r_u32(0x800775BC);
    uint32 packet = r_u32(0x800774A8);
    if ((sint32)(end - packet) < 12) return 1;
    uint32 previous = r_u32(0x80077634);
    uint32 old_tag = r_u32(previous);
    w_u32(0x800774A8, packet + 36);
    w_u32(0x80077634, packet);
    w_u32(previous, (old_tag & 0xFF000000) | (packet & 0xFFFFFF));
    ob_draft_unresolved_call(0x8005BB10, 1, packet);
    ob_draft_unresolved_call(0x8005BA48, 2, packet, 1);
    for (uint32 vertex = 0; vertex < 4; ++vertex)
        for (uint32 channel = 0; channel < 3; ++channel)
            w_u8(packet + 4 + vertex * 8 + channel, vertex < 2 ? intensity : 0);
    uint32 tail = r_u32(0x80077634);
    w_u16(packet + 8, 0); w_u16(packet + 10, 0);
    w_u16(packet + 16, 384); w_u16(packet + 18, 0);
    w_u16(packet + 24, 0); w_u16(packet + 26, 256);
    w_u16(packet + 32, 384); w_u16(packet + 34, 256);
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
    uint32 map = r_u32(0x800665D8);
    if (map & 3) map = sub_800257CC(0x800665D8);
    else w_u16(map - 6, r_u16(map - 6) + 1);
    w_u32(0x80077644, map);
    ob_classify_effect_index(r_u32(state + 4), map);
    ob_classify_effect_cell(r_u32(state), r_u32(0x80077644));
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
