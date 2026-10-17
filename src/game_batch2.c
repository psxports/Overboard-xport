#include "xport.h"
#include "psx.h"
#include "game_signatures.h"
#include "native_extra_signatures.h"
#include "draft_signatures.h"
#include "movie_player.h"

static uint32 ob_batch2_load_unaligned(uint32 address)
{
    uint32 high = r_u32((address + 3) & ~3);
    uint32 low = r_u32(address & ~3);
    uint32 offset = address & 3;
    return offset ? (low >> (offset * 8)) | (high << ((4 - offset) * 8)) : low;
}

static void ob_batch2_store_unaligned(uint32 address, uint32 value)
{
    uint32 end = address + 3;
    uint32 offset = end & 3;
    w_masked_u32(end & ~3, value >> ((3 - offset) * 8), (1 << (offset + 1)) - 1);
    offset = address & 3;
    w_masked_u32(address & ~3, value << (offset * 8), (15 << offset) & 15);
}

void ob_game_800997F4(void)
{
    FUNCTION_MARKER(0x800997F4, "GAME.BIN");
}

void ob_game_800A2C78(uint32 object)
{
    FUNCTION_MARKER(0x800A2C78, "GAME.BIN");
    w_u32(object + 4, 0);
}

void ob_game_800A499C(void)
{
    FUNCTION_MARKER(0x800A499C, "GAME.BIN");
}

void ob_game_800BB3C4(void)
{
    FUNCTION_MARKER(0x800BB3C4, "GAME.BIN");
}

void ob_game_800BCA98(void)
{
    FUNCTION_MARKER(0x800BCA98, "GAME.BIN");
}

uint32 ob_game_800A2C80(uint32 object)
{
    FUNCTION_MARKER(0x800A2C80, "GAME.BIN");
    return r_u32(object + 4) != 0;
}

void ob_main_8001FFB8(void)
{
    FUNCTION_MARKER(0x8001FFB8, "SLES_008.65");
}

void ob_main_80024318(void)
{
    FUNCTION_MARKER(0x80024318, "SLES_008.65");
}

void ob_main_800279CC(void)
{
    FUNCTION_MARKER(0x800279CC, "SLES_008.65");
}

void ob_main_8003979C(void)
{
    FUNCTION_MARKER(0x8003979C, "SLES_008.65");
}

void ob_main_800397A4(void)
{
    FUNCTION_MARKER(0x800397A4, "SLES_008.65");
}

void ob_main_8004F06C(void)
{
    FUNCTION_MARKER(0x8004F06C, "SLES_008.65");
}

uint32 ob_game_80097FC4(uint32 object, uint32 state)
{
    FUNCTION_MARKER(0x80097FC4, "GAME.BIN");
    uint32 previous = r_u8(object);
    w_u8(object, state);
    w_u32(object + 12, 0);
    w_u8(object + 1, previous);
    return previous;
}

uint32 ob_game_800BC3C4(uint32 object)
{
    FUNCTION_MARKER(0x800BC3C4, "GAME.BIN");
    w_u32(object + 288, 35);
    w_u16(object + 308, 50);
    return 50;
}

uint32 ob_game_800C191C(uint32 object)
{
    FUNCTION_MARKER(0x800C191C, "GAME.BIN");
    uint32 flags = r_u8(object + 56) & 0xF7;
    w_u8(object + 56, flags);
    return flags;
}

uint32 ob_game_800C1930(uint32 object)
{
    FUNCTION_MARKER(0x800C1930, "GAME.BIN");
    uint32 flags = r_u8(object + 56) | 8;
    w_u8(object + 56, flags);
    return flags;
}

uint32 ob_game_800C1944(uint32 object)
{
    FUNCTION_MARKER(0x800C1944, "GAME.BIN");
    return (r_u8(object + 56) & 8) != 0;
}

uint32 ob_movie_8008E3B4(void)
{
    FUNCTION_MARKER(0x8008E3B4, "MOVIE.BIN");
    return r_u32(r_u32(0x8008E9D8));
}

uint32 ob_game_800A9E30(uint32 object, uint32 x, uint32 y, uint32 z, uint32 value)
{
    FUNCTION_MARKER(0x800A9E30, "GAME.BIN");
    w_u32(object + 12, x);
    w_u32(object + 16, y);
    w_u32(object + 20, z);
    w_u32(object + 8, value);
    return value;
}

void ob_game_800C0F54(uint32 object, uint32 value)
{
    FUNCTION_MARKER(0x800C0F54, "GAME.BIN");
    w_u32(object + 8, value);
    w_u32(object + 12, value);
    w_u32(object + 16, value);
    w_u32(object + 20, 0);
    w_u32(object + 24, 0);
    w_u32(object + 28, 0);
}

uint32 ob_game_800A1BB4(uint32 object, uint32 value)
{
    FUNCTION_MARKER(0x800A1BB4, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    w_u8(data + 78, 0);
    w_u8(data + 46, 0);
    w_u8(data + 79, 0);
    w_u16(data + 32, 0);
    w_u32(data + 12, value);
    return data;
}

uint32 ob_main_8002FA88(uint32 matrix, uint32 scale)
{
    FUNCTION_MARKER(0x8002FA88, "SLES_008.65");
    uint32 clamped = (scale & 0xFFFF) > 0xFF00;
    if (clamped)
        scale = 0xFF00;
    w_u16(matrix + 76, scale);
    return clamped;
}

uint32 ob_main_800346CC(uint32 handle)
{
    FUNCTION_MARKER(0x800346CC, "SLES_008.65");
    return ob_release_pool_cell(handle);
}

uint32 ob_game_800A2D4C(uint32 position)
{
    FUNCTION_MARKER(0x800A2D4C, "GAME.BIN");
    uint32 x = r_u32(position);
    uint32 y = r_u32(position + 4);
    uint32 z = r_u32(position + 8);
    w_u32(0x800C84E0, x);
    w_u32(0x800C84E4, y);
    w_u32(0x800C84E8, z);
    return x;
}

uint32 ob_main_8001CE24(void)
{
    FUNCTION_MARKER(0x8001CE24, "SLES_008.65");
    sub_80026758(0x8006BCC0);
    return 0;
}

uint32 ob_main_80033F24(uint32 handle, uint32 previous)
{
    FUNCTION_MARKER(0x80033F24, "SLES_008.65");
    uint32 geometry = r_u32(handle);
    return ob_relocate_geometry(geometry, geometry - previous);
}

void ob_main_800355F4(void)
{
    FUNCTION_MARKER(0x800355F4, "SLES_008.65");
    ob_restore_heap_pointer(r_u32(0x800773C0));
}

uint32 ob_main_8004A2C4(void)
{
    FUNCTION_MARKER(0x8004A2C4, "SLES_008.65");
    return ob_memory_release_reference(0x800665D8);
}

uint32 ob_main_8004B98C(uint32 handle, uint32 previous)
{
    FUNCTION_MARKER(0x8004B98C, "SLES_008.65");
    uint32 tables = r_u32(handle);
    return ob_relocate_effect_tables(tables, tables - previous);
}

uint32 ob_game_800ADD1C(uint32 object)
{
    FUNCTION_MARKER(0x800ADD1C, "GAME.BIN");
    uint32 handle = r_u32(object + 20);
    w_u16(object + 44, 0);
    return ob_memory_release_reference(handle);
}

uint32 ob_game_800BCB90(uint32 object, uint32 first, uint32 second)
{
    FUNCTION_MARKER(0x800BCB90, "GAME.BIN");
    w_u32(object + 96, first);
    w_u32(object + 92, second);
    return ob_register_effect_object(object + 64);
}

uint32 ob_main_800121A4(void)
{
    FUNCTION_MARKER(0x800121A4, "SLES_008.65");
    ob_draft_unresolved_call(0x8001E074, 0);
    return ob_enable_audio_processing();
}

uint32 ob_game_800BB630(uint32 object, uint32 first, uint32 second)
{
    FUNCTION_MARKER(0x800BB630, "GAME.BIN");
    w_u32(object + 100, 0x800BB658);
    return ob_game_800BCB90(object, first, second);
}

uint32 ob_main_80026710(uint32 handle, uint32 size)
{
    FUNCTION_MARKER(0x80026710, "SLES_008.65");
    return sub_800271EC(r_u32(handle) - 40, size);
}

uint32 ob_main_8001CF2C(uint32 index)
{
    FUNCTION_MARKER(0x8001CF2C, "SLES_008.65");
    return r_u8(r_u32(0x8006BCC0) + 376 * index + 881) != 0;
}

uint32 ob_main_80024B70(void)
{
    FUNCTION_MARKER(0x80024B70, "SLES_008.65");
    ob_main_800121A4();
    return ob_draft_unresolved_call(0x8001DE60, 0);
}

uint32 ob_main_8002D940(void)
{
    FUNCTION_MARKER(0x8002D940, "SLES_008.65");
    uint32 result = r_u32(0x800770B4);
    if (result)
        result = ob_main_80026710(0x800770B4, 0);
    w_u32(0x800770CC, 0);
    w_u32(0x800770D0, 0);
    return result;
}

uint32 ob_game_80094D6C(uint32 object, uint32 unused, uint32 time)
{
    FUNCTION_MARKER(0x80094D6C, "GAME.BIN");
    ob_set_object_time(r_u32(object + 44), time);
    return ob_game_800BCAA0(object);
}

uint32 ob_game_800AFF34(uint32 object, uint32 unused, uint32 time)
{
    FUNCTION_MARKER(0x800AFF34, "GAME.BIN");
    ob_set_object_time(r_u32(object + 44), time);
    return ob_game_800BCAA0(object);
}

uint32 ob_game_800C0594(uint32 object)
{
    FUNCTION_MARKER(0x800C0594, "GAME.BIN");
    sub_8001195C((uint32)(sint32)r_s16(object + 306));
    w_u16(object + 306, 0xFFFF);
    return UINT32_MAX;
}

uint32 ob_main_8001CDE4(void)
{
    FUNCTION_MARKER(0x8001CDE4, "SLES_008.65");
    sub_80026694(0x8006BCC0, 0x2000, 0);
    ob_draft_unresolved_call(0x80063FD8, 3, r_u32(0x8006BCC0), 0, 0x2000);
    return 0;
}

uint32 ob_main_800320F8(uint32 object, uint32 flags)
{
    FUNCTION_MARKER(0x800320F8, "SLES_008.65");
    uint32 active = r_u16(0x800775A2);
    uint32 cursor = r_u16(0x800773C4);
    uint32 index = r_u16(0x8008CFE0 + cursor * 2);
    w_u16(0x800775A2, active + 1);
    w_u16(0x800773C4, cursor + 1);
    w_u32(0x800881A8 + index * 8, object);
    w_u16(0x800881AC + index * 8, flags);
    return (uint32)(sint32)(sint16)index;
}

uint32 ob_main_80032148(uint32 index)
{
    FUNCTION_MARKER(0x80032148, "SLES_008.65");
    uint32 offset = (uint32)((sint32)(sint16)index * 8);
    w_u32(0x800881A8 + offset, 0);
    uint32 cursor = r_u16(0x800773C4) - 1;
    uint32 active = r_u16(0x800775A2) - 1;
    w_u16(0x800773C4, cursor);
    w_u16(0x8008CFE0 + (cursor & 0xFFFF) * 2, index);
    w_u16(0x800775A2, active);
    return 0;
}

uint32 ob_main_800346EC(uint32 handle)
{
    FUNCTION_MARKER(0x800346EC, "SLES_008.65");
    sub_80026758(r_u32(handle) + 20);
    return ob_release_pool_cell(handle);
}

uint32 ob_game_800A1BD4(uint32 object, uint32 value)
{
    FUNCTION_MARKER(0x800A1BD4, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    uint32 index = (r_u8(data + 79) + 1) & 31;
    w_u8(data + 79, index);
    uint32 result = data + index;
    w_u8(result + 46, value);
    return result;
}

uint32 ob_game_800B41B8(uint32 data, uint32 index, uint32 amount)
{
    FUNCTION_MARKER(0x800B41B8, "GAME.BIN");
    uint32 slot = data + index * 2 + 120;
    uint32 value = r_u16(slot) + amount;
    w_u16(slot, value);
    sint32 limit = r_s32(0x800C5AF8 + index * 4);
    uint32 clamped = limit < (sint16)value;
    if (clamped)
        w_u16(slot, (uint32)limit);
    return clamped;
}

uint32 ob_movie_8008DFE0(uint32 mode)
{
    FUNCTION_MARKER(0x8008DFE0, "MOVIE.BIN");
    if (mode)
        return (ob_movie_8008E3B4() >> 24) & 1;
    return ob_draft_unresolved_call(0x8008E31C, 0);
}

uint32 ob_game_800A1C68(uint32 object)
{
    FUNCTION_MARKER(0x800A1C68, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    uint32 index = (r_u8(data + 78) + 1) & 31;
    w_u8(data + 78, index);
    uint32 result = r_u8(data + index + 46);
    w_u16(data + 32, result);
    return result;
}

uint32 ob_game_8009F660(uint32 owner)
{
    FUNCTION_MARKER(0x8009F660, "GAME.BIN");
    uint32 handle = ob_draft_scratch_acquire(4);
    w_u32(handle, 0);
    sub_800262CC(handle, 60);
    ob_draft_unresolved_call(0x8009F6CC, 2, r_u32(handle), owner);
    uint32 result = r_u32(handle);
    ob_draft_scratch_release(handle);
    return result;
}

uint32 ob_game_800B4164(uint32 data, uint32 index)
{
    FUNCTION_MARKER(0x800B4164, "GAME.BIN");
    uint32 slot = data + index * 2 + 120;
    uint32 amount = r_u32(0x800C5AB0 + index * 4);
    uint32 value = r_u16(slot) + amount;
    w_u16(slot, value);
    sint32 limit = r_s32(0x800C5AF8 + index * 4);
    uint32 clamped = limit < (sint16)value;
    if (clamped)
        w_u16(slot, (uint32)limit);
    return clamped;
}

uint32 ob_main_80034724(uint32 handle)
{
    FUNCTION_MARKER(0x80034724, "SLES_008.65");
    sub_80026758(r_u32(handle) + 20);
    sub_80026758(r_u32(handle) + 44);
    return ob_release_pool_cell(handle);
}

uint32 ob_main_80015F24(uint32 character)
{
    FUNCTION_MARKER(0x80015F24, "SLES_008.65");
    uint32 table = 0x80065E3C;
    uint32 code = 32;
    uint32 entry = r_u16(table);
    character &= 0xFFFF;
    while (entry)
    {
        if (entry == character)
            return code & 0xFF;
        table += 2;
        entry = r_u16(table);
        ++code;
    }
    return 63;
}

uint32 ob_main_8001DE60(void)
{
    FUNCTION_MARKER(0x8001DE60, "SLES_008.65");
    uint32 result = r_u8(0x8006C00C);
    if (result)
    {
        uint32 enabled = r_u8(0x8006C00D);
        result = 6;
        if (enabled)
        {
            uint32 attributes = ob_draft_scratch_acquire(24);
            w_u32(attributes, 6);
            w_u16(attributes + 8, 0);
            w_u16(attributes + 10, 0);
            result = ob_draft_unresolved_call(0x80061924, 1, attributes);
            w_u8(0x8006C00E, 0);
            ob_draft_scratch_release(attributes);
        }
    }
    return result;
}

uint32 ob_main_8002F3D8(uint32 matrix)
{
    FUNCTION_MARKER(0x8002F3D8, "SLES_008.65");
    ob_main_8002F420(matrix);
    uint32 flags = r_u32(matrix + 48) & 0xFFFFFFE3;
    w_u32(matrix + 48, flags);
    return flags;
}

uint32 ob_game_800954CC(void)
{
    FUNCTION_MARKER(0x800954CC, "GAME.BIN");
    uint32 node = r_u32(0x800C4DC0);
    uint32 result = 0x800C4E08;
    while (node != 0x800C4E08)
    {
        result = ob_draft_unresolved_call(r_u32(node + 40), 1, node);
        node = r_u32(0x800C4DC0);
    }
    return result;
}

uint32 ob_main_8002D888(void)
{
    FUNCTION_MARKER(0x8002D888, "SLES_008.65");
    return ob_main_8002D940();
}

uint32 ob_main_80034500(uint32 object)
{
    FUNCTION_MARKER(0x80034500, "SLES_008.65");
    sub_80034430(object);
    return (uint32)sub_80034430(object + 24);
}

uint32 ob_movie_8008DF84(uint32 output, uint32 size)
{
    FUNCTION_MARKER(0x8008DF84, "MOVIE.BIN");
    return ob_movie_8008E1F4(output, size);
}

uint32 ob_game_8009F6A4(uint32 object)
{
    FUNCTION_MARKER(0x8009F6A4, "GAME.BIN");
    uint32 handle = ob_draft_scratch_acquire(4);
    w_u32(handle, object);
    ob_game_8009F728(object);
    uint32 result = ob_release_pool_cell(handle);
    ob_draft_scratch_release(handle);
    return result;
}

uint32 ob_main_8002F420(uint32 matrix)
{
    FUNCTION_MARKER(0x8002F420, "SLES_008.65");
    uint32 vector = ob_draft_scratch_acquire(8);
    w_u16(vector, r_u16(matrix));
    w_u16(vector + 2, r_u16(matrix + 2));
    w_u16(vector + 4, r_u16(matrix + 4));
    sub_8003042C(vector, matrix);
    ob_draft_unresolved_call(0x800305CC, 3, matrix, matrix + 12, matrix + 6);
    w_u16(vector, r_u16(matrix + 6));
    w_u16(vector + 2, r_u16(matrix + 8));
    w_u16(vector + 4, r_u16(matrix + 10));
    sub_8003042C(vector, matrix + 6);
    uint32 result = ob_draft_unresolved_call(0x800305CC, 3, matrix + 6, matrix, matrix + 12);
    ob_draft_scratch_release(vector);
    return result;
}

uint32 ob_main_8001E074(void)
{
    FUNCTION_MARKER(0x8001E074, "SLES_008.65");
    uint32 result = r_u8(0x8006C00C);
    if (result)
    {
        ob_draft_unresolved_call(0x8006272C, 2, 0, 0xFFFFFF);
        for (uint32 index = 0; index < 24; ++index)
        {
            uint32 offset = index * 28;
            w_u32(0x800782A0 + offset, 0);
            w_u32(0x800782A4 + offset, 0);
            w_u32(0x80078544 + offset, 0);
            w_u8(0x80078554 + offset, 0xFF);
            w_u8(0x80078555 + offset, 0xFF);
        }
        w_u8(0x8006C011, 0);
        result = 0;
    }
    return result;
}

uint32 ob_movie_8008E1F4(uint32 output, uint32 size)
{
    FUNCTION_MARKER(0x8008E1F4, "MOVIE.BIN");
    ob_movie_8008E31C();
    uint32 control = r_u32(0x8008E9DC);
    w_u32(control, r_u32(control) | 0x88);
    w_u32(r_u32(0x8008E9B8), 0);
    w_u32(r_u32(0x8008E9B0), output);
    w_u32(r_u32(0x8008E9B4), ((size >> 5) << 16) | 0x20);
    uint32 channel = r_u32(0x8008E9B8);
    /* TODO Confirm MDEC DMA register support before this path is used */
    w_u32(channel, 0x1000200);
    return channel;
}

uint32 ob_movie_8008E31C(void)
{
    FUNCTION_MARKER(0x8008E31C, "MOVIE.BIN");
    if (r_u32(r_u32(0x8008E9B8)) & 0x1000000)
    {
        uint32 remaining = 0x100000;
        for (;;)
        {
            --remaining;
            if (remaining == UINT32_MAX)
            {
                ob_draft_unresolved_call(0x8008E3CC, 1, 0x8008D058);
                return UINT32_MAX;
            }
            if (!(r_u32(r_u32(0x8008E9B8)) & 0x1000000))
                return 0;
        }
    }
    return 0;
}

uint32 ob_game_8009F728(uint32 object)
{
    FUNCTION_MARKER(0x8009F728, "GAME.BIN");
    uint32 child = r_u32(object + 40);
    w_u16(object + 24, 0);
    w_u32(object + 28, 0);
    if (child)
        ob_release_pool_cell(object + 40);
    w_u32(object + 36, 0);
    w_u32(object + 32, 0);
    w_u32(object + 44, 0);
    w_u32(object + 48, 0);
    w_u32(object + 52, 0);
    w_u32(object + 56, 0);
    return ob_unlink_object_record(object);
}

uint32 ob_main_8001D3C0(uint32 mode)
{
    FUNCTION_MARKER(0x8001D3C0, "SLES_008.65");
    w_u8(0x800899C9, mode);
    if (mode & 3)
        return ob_draft_unresolved_call(0x8001D404, 0);
    return ob_draft_unresolved_call(0x8001D4E4, 1, mode);
}

uint32 ob_main_8002FA40(uint32 matrix, uint32 angles)
{
    FUNCTION_MARKER(0x8002FA40, "SLES_008.65");
    uint32 first = ob_batch2_load_unaligned(angles);
    uint32 last = r_u16(angles + 4);
    ob_batch2_store_unaligned(matrix + 70, first);
    w_u16(matrix + 74, last);
    uint32 flags = (r_u32(matrix + 48) & 0xFFFFFFE0) | 1;
    w_u32(matrix + 48, flags);
    return flags;
}

uint32 ob_main_80046064(void)
{
    FUNCTION_MARKER(0x80046064, "SLES_008.65");
    w_u32(0x8007755C, 0);
    sub_80026758(0x80077140);
    sub_80026758(0x80077148);
    return sub_80026758(0x80077144);
}

uint32 ob_main_8004659C(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x8004659C, "SLES_008.65");
    uint32 result = r_u32(object + 28) - 1;
    w_u32(object + 28, result);
    if (!result)
    {
        sub_80046914((sint32)object, (sint32)time);
        result = ob_insert_artic_reference(r_u32(object + 32), object + 36);
    }
    return result;
}

uint32 ob_game_800A73F0(uint32 object, uint32 reference, uint32 time)
{
    FUNCTION_MARKER(0x800A73F0, "GAME.BIN");
    ob_set_object_time(r_u32(object + 44), time);
    ob_draft_unresolved_call(0x800AC640, 2, object, 2);
    return (uint32)sub_80047FF0(reference);
}

uint32 ob_game_800A1B60(uint32 object, uint32 unused, uint32 time)
{
    FUNCTION_MARKER(0x800A1B60, "GAME.BIN");
    ob_set_object_time(r_u32(object + 44), time);
    ob_draft_unresolved_call(0x800A6C34, 3, object, UINT32_MAX, time);
    return ob_game_800BCAA0(object);
}

uint32 ob_game_800A76A8(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800A76A8, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    uint32 result = 0xFFFF;
    if (r_u16(data + 36) != 0xFFFF)
    {
        result = ob_draft_unresolved_call(0x800A2284, 4, object, r_u8(data + 44), 0x10027, time);
        w_u32(data + 12, time);
    }
    return result;
}

uint32 ob_game_800AA62C(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800AA62C, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    uint32 result = 0xFFFF;
    if (r_u16(data + 36) != 0xFFFF)
        result = ob_draft_unresolved_call(0x800A2284, 4, object, r_u8(data + 44), 0x1018C, time);
    w_u32(data + 12, time);
    return result;
}

uint32 ob_game_8009F6CC(uint32 object, uint32 owner)
{
    FUNCTION_MARKER(0x8009F6CC, "GAME.BIN");
    sub_80043600(object, (sint32)owner, 0);
    w_u32(object, 0x800C52A4);
    w_u16(object + 24, 0);
    w_u32(object + 28, 0);
    w_u32(object + 36, 0);
    w_u32(object + 40, 0);
    w_u32(object + 32, 0);
    w_u32(object + 44, 0);
    w_u32(object + 48, 0);
    w_u32(object + 52, 0);
    w_u32(object + 56, 0);
    return 0x800C52A4;
}

uint32 ob_game_800AB0C4(uint32 object, uint32 unused, uint32 time)
{
    FUNCTION_MARKER(0x800AB0C4, "GAME.BIN");
    w_u8(r_u32(object + 116) + 116, 1);
    w_u32(r_u32(object + 124), 0);
    ob_set_object_time(r_u32(object + 44), time);
    return sub_80045A44(r_u32(object + 44), 0x8006C160);
}

uint32 ob_game_800B36D0(uint32 object, uint32 unused, uint32 time)
{
    FUNCTION_MARKER(0x800B36D0, "GAME.BIN");
    ob_set_object_time(r_u32(object + 44), time);
    sub_80045A44(r_u32(object + 44), 0x8006C160);
    return ob_draft_unresolved_call(0x8001A690, 2, object, time);
}

uint32 ob_game_800BB848(uint32 object, uint32 reference)
{
    FUNCTION_MARKER(0x800BB848, "GAME.BIN");
    ob_game_800A0D38(object);
    if ((r_u32(reference + 28) & 0x20) && r_u32(reference + 24) == 32)
        w_u32(0x8006C154, 1);
    return (uint32)sub_80047FF0(reference);
}

uint32 ob_game_800B31B4(uint32 object, uint32 target, uint32 time)
{
    FUNCTION_MARKER(0x800B31B4, "GAME.BIN");
    uint32 result = r_u32(target + 180);
    if (!result)
    {
        w_u32(target + 180, time);
        sub_8004651C(r_u32(object + 52));
        uint32 attributes = ob_draft_scratch_acquire(88);
        result = ob_game_800BE604(object, attributes, time);
        ob_draft_scratch_release(attributes);
    }
    return result;
}

uint32 ob_main_8001C33C(uint32 back, uint32 red, uint32 green, uint32 blue)
{
    FUNCTION_MARKER(0x8001C33C, "SLES_008.65");
    uint32 offset = ((uint32)(sint32)r_s16(0x80077084) - back) * 36;
    w_u8(0x80083EE0 + offset, red);
    offset = ((uint32)(sint32)r_s16(0x80077084) - back) * 36;
    w_u8(0x80083EE1 + offset, green);
    offset = ((uint32)(sint32)r_s16(0x80077084) - back) * 36;
    w_u8(0x80083EE2 + offset, blue);
    return offset;
}

uint32 ob_game_800A1AF8(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800A1AF8, "GAME.BIN");
    ob_set_object_time(r_u32(object + 44), time);
    sub_80045A44(r_u32(object + 44), 0x800C61B4);
    w_u32(object + 100, 0x800A1B60);
    w_u32(object + 96, 0);
    w_u32(object + 92, time + 2000);
    return ob_register_effect_object(object + 64);
}

uint32 ob_game_800A296C(void)
{
    FUNCTION_MARKER(0x800A296C, "GAME.BIN");
    uint32 count = r_u8(0x800D64B2);
    for (uint32 index = 0; index < count; ++index)
        if (!r_u32(0x800D5C98 + index * 4))
            return index;
    count = r_u8(0x800D64B2);
    w_u8(0x800D64B2, count + 1);
    return count;
}

static uint32 ob_batch2_create_object(uint32 size, uint32 constructor, uint32 owner, uint32 state, uint32 time)
{
    sint32 available = r_s32(0x8007755C);
    uint32 handle = ob_draft_scratch_acquire(4);
    w_u32(handle, 0);
    if (available > 0)
    {
        sub_800262CC(handle, (sint32)size);
        uint32 object = r_u32(handle);
        if (object)
            ob_draft_unresolved_call(constructor, 4, object, owner, state, time);
    }
    uint32 result = r_u32(handle);
    ob_draft_scratch_release(handle);
    return result;
}

uint32 ob_game_800955F8(uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x800955F8, "GAME.BIN");
    return ob_batch2_create_object(160, 0x80095670, owner, state, time);
}

uint32 ob_game_8009A0C4(uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x8009A0C4, "GAME.BIN");
    return ob_batch2_create_object(160, 0x8009A13C, owner, state, time);
}

uint32 ob_game_8009A7E8(uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x8009A7E8, "GAME.BIN");
    return ob_batch2_create_object(176, 0x8009A860, owner, state, time);
}

uint32 ob_game_8009C57C(void)
{
    FUNCTION_MARKER(0x8009C57C, "GAME.BIN");
    sub_8004651C(r_u32(0x800C84A0));
    sub_8004651C(r_u32(0x800C84A4));
    sub_8004651C(r_u32(0x800C84A8));
    return (uint32)sub_8004651C(r_u32(0x800C84AC));
}

uint32 ob_game_8009F784(uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x8009F784, "GAME.BIN");
    return ob_batch2_create_object(160, 0x8009F7FC, owner, state, time);
}

uint32 ob_game_800A1258(uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x800A1258, "GAME.BIN");
    return ob_batch2_create_object(160, 0x800A12D0, owner, state, time);
}

uint32 ob_game_800A2E24(uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x800A2E24, "GAME.BIN");
    return ob_batch2_create_object(160, 0x800A2E9C, owner, state, time);
}

uint32 ob_game_800A4E4C(uint32 group)
{
    FUNCTION_MARKER(0x800A4E4C, "GAME.BIN");
    if (!r_u16(r_u32(0x80077190)))
        return 0;
    uint32 index = 0;
    uint32 offset = 0;
    for (;;)
    {
        uint32 entry = r_u32(0x80077194) + offset;
        if (r_u16(entry + 22) == group)
        {
            uint32 mode = r_u8(0x8006C22C);
            if ((mode != 0 || (r_u8(entry + 24) & 1)) &&
                (mode != 1 || (r_u8(entry + 24) & 2)) &&
                (mode != 2 || (r_u8(entry + 24) & 4)) &&
                r_u8(r_u32(0x80077190) + 42) < r_u8(entry + 25))
            {
                uint32 kind = r_u32(entry + 12);
                if (kind != 250)
                {
                    if (kind == 5)
                        w_u32(entry + 12, 3);
                    entry = r_u32(0x80077194) + offset;
                    if (r_u32(entry + 12) - 169 >= 2)
                    {
                        uint32 slot = (uint32)(sint32)(sint16)ob_game_800A50BC(entry) * 104;
                        entry = r_u32(0x80077194) + offset;
                        uint32 table = r_u32(0x8007719C);
                        uint32 head = r_u32(table + r_u16(entry + 22) * 4);
                        uint32 node = 0x800CBA00 + slot;
                        if (!head)
                        {
                            w_u32(node + 72, node);
                            w_u32(table + r_u16(entry + 22) * 4, node);
                        }
                        else
                        {
                            uint32 tail = head;
                            if (r_u32(tail + 72) != head)
                            {
                                do
                                {
                                    tail = r_u32(tail + 72);
                                } while (r_u32(tail + 72) != head);
                            }
                            w_u32(tail + 72, node);
                            entry = r_u32(0x80077194) + offset;
                            table = r_u32(0x8007719C);
                            w_u32(node + 72, r_u32(table + r_u16(entry + 22) * 4));
                        }
                        w_u16(node + 88, index);
                    }
                }
            }
        }
        ++index;
        if ((sint32)index >= r_u16(r_u32(0x80077190)))
            return 0;
        offset += 28;
    }
}

uint32 ob_game_800A52C4(uint32 object, uint32 rate, uint32 time)
{
    FUNCTION_MARKER(0x800A52C4, "GAME.BIN");
    if (r_s8(0x8008AE6A))
        for (uint32 index = 0; index < 5; ++index)
            if (object == r_u32(0x8006C138 + index * 4))
                return 0;
    sint32 damage;
    if (time == UINT32_MAX)
        damage = (sint32)(sint16)rate * 64;
    else
    {
        sint32 product = (sint32)((time - r_u32(object + 28)) * (uint32)(sint32)(sint16)rate);
        damage = product / 1000;
    }
    if (damage > 0 && time == UINT32_MAX)
    {
        uint32 slot = (uint32)(sint32)r_s16(object + 326) * 104;
        if (r_u16(0x800CBA46 + slot))
            w_u8(r_u32(object + 60) + 55, 1);
    }
    uint32 slot = (uint32)(sint32)r_s16(object + 326) * 104;
    uint32 health = r_u16(0x800CBA46 + slot);
    if (damage >= (sint32)health)
    {
        w_u16(0x800CBA46 + slot, 0);
        slot = (uint32)(sint32)r_s16(object + 326) * 104;
        if (r_u16(0x800CBA46 + slot))
        {
            if (r_u32(object + 292) == 255)
                return UINT32_MAX;
            sub_80046544(r_u32(object + 52));
        }
        return UINT32_MAX;
    }
    sint32 remaining = (sint32)(health - (uint32)damage);
    uint32 maximum = ob_game_800901A8(r_u32(object + 292)) & 0xFFFF;
    uint32 value;
    if ((sint32)maximum < remaining)
    {
        value = ob_game_800901A8(r_u32(object + 292));
        slot = (uint32)(sint32)r_s16(object + 326) * 104;
    }
    else
    {
        slot = (uint32)(sint32)r_s16(object + 326) * 104;
        value = r_u16(0x800CBA46 + slot) - (uint32)damage;
    }
    w_u16(0x800CBA46 + slot, value);
    return 0;
}

uint32 ob_game_800A5B44(uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x800A5B44, "GAME.BIN");
    return ob_batch2_create_object(160, 0x800A5BBC, owner, state, time);
}

uint32 ob_game_800A9720(uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x800A9720, "GAME.BIN");
    return ob_batch2_create_object(160, 0x800A9798, owner, state, time);
}

uint32 ob_game_800AC640(uint32 object, uint32 kind)
{
    FUNCTION_MARKER(0x800AC640, "GAME.BIN");
    uint32 counter = r_u32(0x800C8330);
    uint32 output = 0x800D5DD8;
    w_u32(0x800C8330, counter + 1);
    if (counter & 1)
        output = 0x800D5D18;
    ob_game_800C0FC8(output, r_u32(object + 44), 164);
    uint32 attributes = r_u32(object + 124);
    if (attributes)
        ob_game_800C0FC8(output + 164, attributes, 16);
    else
    {
        w_u32(output + 164, 0);
        w_u16(output + 168, 0);
        w_u32(output + 172, 0);
    }
    w_u32(output + 180, r_u32(object + 112));
    uint32 result = r_u16(object + 302);
    w_u8(output + 186, kind);
    w_u16(output + 184, result);
    return result;
}

uint32 ob_game_800AD720(uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x800AD720, "GAME.BIN");
    return ob_batch2_create_object(160, 0x800AD798, owner, state, time);
}

uint32 ob_game_800AF798(uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x800AF798, "GAME.BIN");
    return ob_batch2_create_object(160, 0x800AF810, owner, state, time);
}

uint32 ob_game_800B5904(uint32 owner, uint32 state, uint32 time)
{
    FUNCTION_MARKER(0x800B5904, "GAME.BIN");
    return ob_batch2_create_object(160, 0x800B597C, owner, state, time);
}

static sint32 ob_batch2_cell_divide(sint32 value, sint32 divisor)
{
    if (!divisor)
        return (sint32)ob_native_missing_value(0x800BBA70, "BREAK 7 signed division by zero");
    if (divisor == -1 && value == INT32_MIN)
        return (sint32)ob_native_missing_value(0x800BBA70, "BREAK 6 signed division overflow");
    return value / divisor;
}

uint32 ob_game_800BBA70(uint32 position, uint32 first, uint32 second, uint32 time)
{
    FUNCTION_MARKER(0x800BBA70, "GAME.BIN");
    uint32 map = r_u32(0x800665D8);
    if (map & 3)
        map = (uint32)sub_800257CC((sint32)0x800665D8);
    else
        w_u16(map - 6, r_u16(map - 6) + 1);
    sint32 scale = r_s32(map);
    uint32 origin_x = r_u32(0x80077458);
    sint32 cell_x = ob_batch2_cell_divide((sint32)(r_u32(position) + origin_x), scale);
    uint32 origin_z = r_u32(0x80077468);
    sint32 cell_z = ob_batch2_cell_divide((sint32)(origin_z - r_u32(position + 8)), scale);
    w_u32(position, (uint32)cell_x * (uint32)scale - origin_x);
    w_u32(position + 8, origin_z - (uint32)cell_z * r_u32(map));
    uint32 locals = ob_draft_scratch_acquire(120);
    sub_80051400(position, locals);
    uint32 selector = 0x800739FC + (r_u16(r_u32(locals + 8) + 2) & 3) * 9;
    for (uint32 index = 0; index < 9; ++index)
    {
        sint32 entry = r_s8(selector);
        uint32 surface = r_u32(locals + 8);
        uint32 base = (uint32)((sint32)((uint32)(r_u16(surface + 2) & 0xFFFC) << 16) >> 14);
        uint32 height = (uint32)(sint32)r_s8(r_u32(map + 24) + first * 24 + (uint32)entry + 12) << 6;
        w_u32(locals + 24 + (uint32)entry * 4, base + height);
        entry = r_s8(selector++);
        surface = r_u32(locals + 8);
        base = (uint32)((sint32)((uint32)(r_u16(surface + 2) & 0xFFFC) << 16) >> 14);
        height = (uint32)(sint32)r_s8(r_u32(map + 24) + second * 24 + (uint32)entry + 12) << 6;
        w_u32(locals + 64 + (uint32)entry * 4, base + height);
    }
    uint32 changed = 0;
    selector = 0x800739FC + (r_u16(r_u32(locals + 8) + 2) & 3) * 9;
    for (uint32 index = 0; index < 9; ++index, ++selector)
    {
        if (r_u32(locals + 24 + index * 4) != r_u32(locals + 64 + index * 4))
        {
            sint32 entry = r_s8(selector);
            sint32 column = (sint8)(entry - 3 * (entry / 3));
            w_u32(locals + 108, 0);
            w_u32(locals + 104, r_u32(position) + (uint32)(column * 2500) + 1250);
            entry = r_s8(selector);
            sint32 row = (sint8)(entry / 3);
            w_u32(locals + 112, r_u32(position + 8) - (uint32)(row * 2500) - 1250);
            changed = 1;
            ob_draft_unresolved_call(0x800BBDF8, 2, locals + 104, time);
        }
    }
    if (changed)
        sub_80011984(0x800666C4, 128, 15, 15, 256, 0, 0);
    ob_memory_release_reference(0x800665D8);
    ob_draft_scratch_release(locals);
    return 1;
}


uint32 ob_game_800ADD44(uint32 object, uint32 selector, uint32 time)
{
    FUNCTION_MARKER(0x800ADD44, "GAME.BIN");
    selector = (uint32)(sint32)(sint16)selector;
    ob_draft_unresolved_call(0x800ADDA8, 3, object, selector, time);
    ob_draft_unresolved_call(0x800ADE68, 2, object, selector);
    return sub_80045B74(r_u32(object + 12));
}

uint32 ob_main_80024C3C(void)
{
    FUNCTION_MARKER(0x80024C3C, "SLES_008.65");
    sub_8001DF58(0);
    ob_draft_unresolved_call(0x8001FAC8, 0);
    sub_80017554();
    ob_main_8004A2C4();
    ob_main_80024318();
    sub_80035220();
    ob_draft_unresolved_call(0x80034608, 0);
    sub_80026418();
    uint32 result = sub_8002439C();
    w_u32(0x800D675C, 0);
    return result;
}

void ob_main_8002DB80(uint32 identifier, uint32 message, uint32 callback, uint32 context)
{
    FUNCTION_MARKER(0x8002DB80, "SLES_008.65");
    if (callback)
        ob_draft_unresolved_call(callback, 1, context);
    uint32 name = 0x8007351C + identifier * 4;
    for (;;)
    {
        ob_draft_unresolved_call(0x8005C504, 1, 0);
        ob_draft_unresolved_call(0x8005B38C, 3, 0x80010B78, r_u32(name), message);
        ob_draft_unresolved_call(0x8005B068, 1, 0xFFFFFFFF);
        ob_draft_unresolved_call(r_u32(0x80077504), 0);
    }
}

uint32 ob_main_8002D9FC(uint32 size)
{
    FUNCTION_MARKER(0x8002D9FC, "SLES_008.65");
    uint32 upper = r_u32(0x80077358);
    uint32 lower = r_u32(0x80077354);
    if (upper - size < lower)
    {
        ob_main_8002DB80(22, 0x800109E8, 0, 0);
        w_u32(0x80077474, 0);
        return 0;
    }
    uint32 result = upper - ((size + 3) & 0xFFFFFFFC);
    w_u32(0x80077584, upper);
    w_u32(0x80077358, result);
    return result;
}

uint32 ob_main_8002F594(uint32 matrix, uint32 angles)
{
    FUNCTION_MARKER(0x8002F594, "SLES_008.65");
    ob_main_8002FA40(matrix, angles);
    ob_draft_unresolved_call(0x8002F5FC, 2, matrix, angles);
    uint32 flags = r_u32(matrix + 48);
    w_u16(matrix + 18, 0);
    flags = (flags & 0xFFFFFFE1) | 2;
    w_u32(matrix + 48, flags);
    return flags;
}

uint32 ob_game_800A0C34(void)
{
    FUNCTION_MARKER(0x800A0C34, "GAME.BIN");
    for (sint32 offset = 0xA218; offset >= 0; offset -= 104)
        w_u32(0x800CBA48 + (uint32)offset, 0);
    uint32 metadata = r_u32(0x80077190);
    if (r_u8(metadata + 3))
    {
        uint32 table = r_u32(0x8007719C);
        uint32 index = 0;
        do
        {
            w_u32(table, 0);
            uint32 count = r_u8(metadata + 3);
            ++index;
            table += 4;
            if (index >= count) break;
        } while (1);
    }
    return ob_game_800A0BE8();
}

uint32 ob_game_800AEEE8(uint32 time)
{
    FUNCTION_MARKER(0x800AEEE8, "GAME.BIN");
    uint32 slot = (uint32)(sint32)r_s16(0x800C9AB4);
    uint32 offset = slot * 104;
    if (r_u8(0x800CBA5C + offset) != 2)
        ob_game_800AE36C(0x800CBA00 + offset, slot, time);
    slot = (uint32)(sint32)r_s16(0x800C9AB4);
    return r_u32(0x800CBA50 + slot * 104);
}

uint32 ob_game_800BABEC(uint32 record, uint32 delta)
{
    FUNCTION_MARKER(0x800BABEC, "GAME.BIN");
    uint32 locals = ob_draft_scratch_acquire(24);
    sub_800514E4(r_u8(record + 12), r_u8(record + 13), locals);
    uint32 surface = r_u32(locals + 8);
    uint32 old = r_u16(surface + 2);
    w_u16(surface + 2, old & 0xFFFC);
    surface = r_u32(locals + 8);
    uint32 value = r_u16(surface + 2) | ((old + delta) & 3);
    w_u16(surface + 2, value);
    uint32 result = ob_draft_unresolved_call(0x8004BD74, 1, locals);
    ob_draft_scratch_release(locals);
    return result;
}

static void ob_batch2_copy_player_state(uint32 destination, uint32 source)
{
    uint32 end = source + 368;
    do
    {
        uint32 first = r_u32(source);
        uint32 second = r_u32(source + 4);
        uint32 third = r_u32(source + 8);
        uint32 fourth = r_u32(source + 12);
        w_u32(destination, first);
        w_u32(destination + 4, second);
        w_u32(destination + 8, third);
        w_u32(destination + 12, fourth);
        source += 16;
        destination += 16;
    } while (source != end);
    uint32 first = r_u32(source);
    uint32 second = r_u32(source + 4);
    w_u32(destination, first);
    w_u32(destination + 4, second);
}

uint32 ob_main_8001CE4C(uint32 buffer, uint32 index)
{
    FUNCTION_MARKER(0x8001CE4C, "SLES_008.65");
    ob_batch2_copy_player_state(r_u32(0x8006BCC0) + index * 376 + 512, buffer);
    return 0;
}

uint32 ob_main_8001CEBC(uint32 buffer, uint32 index)
{
    FUNCTION_MARKER(0x8001CEBC, "SLES_008.65");
    ob_batch2_copy_player_state(buffer, r_u32(0x8006BCC0) + index * 376 + 512);
    return 0;
}

uint32 ob_main_8001FB50(void)
{
    FUNCTION_MARKER(0x8001FB50, "SLES_008.65");
    uint32 result = r_u8(0x8006C012);
    if (result)
    {
        result = r_u8(0x80089968);
        if (result)
        {
            result = r_u8(0x80089968);
            if (result == 1)
            {
                while (ob_draft_unresolved_call(0x800562AC, 3, 9, 0, 0) != 1) {}
                result = 2;
                w_u8(0x80089968, result);
            }
        }
    }
    return result;
}

uint32 ob_game_800C1094(uint32 handle)
{
    FUNCTION_MARKER(0x800C1094, "GAME.BIN");
    uint32 resource = r_u32(handle);
    uint32 result;
    if (resource & 3)
        result = sub_800257CC(handle);
    else
    {
        w_u16(resource - 6, r_u16(resource - 6) + 1);
        result = r_u32(handle);
    }
    sub_800257A0(handle);
    return result;
}

uint32 ob_main_800175A8(uint32 text, uint32 y, uint32 style)
{
    FUNCTION_MARKER(0x800175A8, "SLES_008.65");
    uint32 length = ob_draft_unresolved_call(0x80063FB8, 1, text);
    uint32 width = length * 9 - 1;
    sint32 half = (sint32)(width + (width >> 31)) >> 1;
    return ob_draft_unresolved_call(0x80017618, 4, text, 192 - (uint32)half, y, style);
}

uint32 ob_main_800132A0(uint32 port, uint32 filename)
{
    FUNCTION_MARKER(0x800132A0, "SLES_008.65");
    uint32 channel = sub_80013794(port);
    uint32 path = ob_draft_scratch_acquire(64);
    ob_draft_unresolved_call(0x80064028, 4, path, 0x80010048, channel, filename);
    uint32 descriptor = ob_draft_unresolved_call(0x80055904, 2, path, 2);
    ob_draft_unresolved_call(0x80055934, 1, descriptor);
    ob_draft_scratch_release(path);
    return descriptor != 0xFFFFFFFF;
}

static uint32 ob_batch2_play_end_movie(uint32 filename, uint32 frames)
{
    sub_800170F8(2);
    sub_8002439C();
    sub_8001F874();
    ob_draft_unresolved_call(0x8008DD9C, 1, 0);
    ob_draft_unresolved_call(0x8008D0D8, 5, filename, frames, 1, 1, 1);
    sub_80024320();
    sub_8001F874();
    sub_80017178();
    return sub_80026418();
}

uint32 ob_main_80023D40(void)
{
    FUNCTION_MARKER(0x80023D40, "SLES_008.65");
    return ob_batch2_play_end_movie(0x80010914, 154);
}

uint32 ob_main_80023DB8(void)
{
    FUNCTION_MARKER(0x80023DB8, "SLES_008.65");
    return ob_batch2_play_end_movie(0x80010924, 1899);
}


uint32 ob_main_80024CA4(void)
{
    FUNCTION_MARKER(0x80024CA4, "SLES_008.65");
    ob_main_8004F06C();
    ob_main_80046064();
    if (r_u8(0x8006C230))
    {
        uint32 table = 0x8006C138;
        uint32 index = 0;
        do
        {
            w_u32(table, 0);
            uint32 count = r_u8(0x8006C230);
            ++index;
            table += 4;
            if (index >= count) break;
        } while (1);
    }
    w_u32(0x8006C134, 0);
    ob_draft_unresolved_call(0x8009450C, 3, 0, 0, 0);
    return sub_80017178();
}

uint32 ob_main_80032240(uint32 output)
{
    FUNCTION_MARKER(0x80032240, "SLES_008.65");
    uint32 active = r_u16(0x800775A2);
    if (!active) return 1;
    uint32 copied = 0;
    uint32 source = 0x800881A8;
    for (uint32 index = 0; index < 24; ++index, source += 8)
    {
        if ((copied & 0xFFFF) >= active) return 0;
        uint32 object = r_u32(source);
        if (object)
        {
            w_u32(output, object);
            uint32 flags = r_u16(source + 4);
            ++copied;
            w_u16(output + 4, flags);
            output += 8;
        }
    }
    return 0;
}

void ob_game_800A9188(uint32 object, uint32 start, uint32 time)
{
    FUNCTION_MARKER(0x800A9188, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    sint32 remaining = (sint32)(time - start);
    sint32 counter = 126;
    sint32 sum = 0;
    if (remaining > 0)
    {
        while (counter > 0)
        {
            sum += 64000 / counter;
            --counter;
            if (sum >= remaining) break;
        }
    }
    w_u8(data + 3, counter);
}

uint32 ob_game_800AAC34(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800AAC34, "GAME.BIN");
    ob_draft_unresolved_call(0x800A1CA8, 3, object, 6, time);
    ob_game_800A1BD4(object, 8);
    w_u32(object + 288, 3);
    sub_80045F20(object + 64);
    sub_80045A7C(r_u32(object + 44), time);
    sub_80045A44(r_u32(object + 44), 0x8006C160);
    return ob_draft_unresolved_call(0x800A2C8C, 1, object);
}

uint32 ob_movie_8008E284(void)
{
    FUNCTION_MARKER(0x8008E284, "MOVIE.BIN");
    if (r_u32(r_u32(0x8008E9D8)) & 0x20000000)
    {
        uint32 remaining = 0x100000;
        for (;;)
        {
            --remaining;
            if (remaining == 0xFFFFFFFF)
            {
                ob_draft_unresolved_call(0x8008E3CC, 1, 0x8008D048);
                return 0xFFFFFFFF;
            }
            if (!(r_u32(r_u32(0x8008E9D8)) & 0x20000000)) return 0;
        }
    }
    return 0;
}

uint32 ob_movie_8008E160(uint32 input, uint32 size)
{
    FUNCTION_MARKER(0x8008E160, "MOVIE.BIN");
    ob_movie_8008E284();
    uint32 control = r_u32(0x8008E9DC);
    w_u32(control, r_u32(control) | 0x88);
    w_u32(r_u32(0x8008E9A4), input + 4);
    w_u32(r_u32(0x8008E9A8), ((size >> 5) << 16) | 0x20);
    uint32 data = r_u32(0x8008E9D4);
    w_u32(data, r_u32(input));
    uint32 channel = r_u32(0x8008E9AC);
    /* TODO Confirm MDEC DMA register support before this path is used */
    w_u32(channel, 0x1000201);
    return channel;
}

uint32 ob_movie_8008DF08(uint32 input, uint32 flags)
{
    FUNCTION_MARKER(0x8008DF08, "MOVIE.BIN");
    uint32 value = r_u32(input);
    value = (flags & 1) ? value & 0xF7FFFFFF : value | 0x8000000;
    w_u32(input, value);
    value = r_u32(input);
    value = (flags & 2) ? value | 0x2000000 : value & 0xFDFFFFFF;
    w_u32(input, value);
    return ob_movie_8008E160(input, r_u16(input));
}

uint32 ob_main_8001FAC8(void)
{
    FUNCTION_MARKER(0x8001FAC8, "SLES_008.65");
    uint32 result = r_u8(0x8006C012);
    if (result)
    {
        uint32 command = r_u8(0x80089968) == 1 ? 9 : 8;
        while (ob_draft_unresolved_call(0x800562AC, 3, command, 0, 0) != 1) {}
        result = 2;
        w_u8(0x80089968, result);
    }
    return result;
}

uint32 ob_game_800A7AA8(uint32 object, uint32 enabled, uint32 time)
{
    FUNCTION_MARKER(0x800A7AA8, "GAME.BIN");
    uint32 state = r_u32(object + 288);
    uint32 result;
    if (!enabled)
    {
        if (state == 24) return 25;
        if (state == 25)
        {
            w_u32(object + 92, time + 200);
            ob_draft_unresolved_call(0x80045EF4, 1, object + 64);
        }
        result = 27;
    }
    else
    {
        if (state == 25) return 24;
        if (state == 24)
        {
            w_u32(object + 92, time + 200);
            ob_draft_unresolved_call(0x80045EF4, 1, object + 64);
        }
        result = 26;
    }
    w_u32(object + 288, result);
    return result;
}

uint32 ob_game_800A2284(uint32 object, uint32 player, uint32 identifier, uint32 time)
{
    FUNCTION_MARKER(0x800A2284, "GAME.BIN");
    uint32 part = sub_800437C4(r_u32(r_u32(object + 44) + 12), identifier);
    uint32 target = r_u32(r_u32(0x800D5C98 + player * 4) + 44);
    sub_80045A7C(part, time);
    sub_80045B74(part);
    uint32 transform = sub_80045464(part, time);
    return sub_800458B4(target, transform, time);
}

uint32 ob_game_800A08A0(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800A08A0, "GAME.BIN");
    uint32 data = r_u32(object + 108);
    if (r_u16(data + 36) != 0xFFFF)
        ob_game_800A2284(object, r_u8(data + 44), 0x100BF, time);
    uint32 result = r_u16(data + 38);
    if (result != 0xFFFF)
        result = ob_game_800A2284(object, r_u8(data + 45), 0x100C3, time);
    w_u32(data + 12, time);
    return result;
}

uint32 ob_game_800ADAD8(uint32 owner, uint32 unused, uint32 first, uint32 second)
{
    FUNCTION_MARKER(0x800ADAD8, "GAME.BIN");
    uint32 handle = ob_draft_scratch_acquire(4);
    w_u32(handle, 0);
    sub_800262CC(handle, 64);
    uint32 record = r_u32(handle);
    w_u32(record + 8, second);
    uint32 child_owner = r_u32(record + 8);
    w_u32(record + 12, first);
    uint32 child = ob_game_8009F660(child_owner);
    record = r_u32(handle);
    uint32 previous = r_u32(0x800C84F0);
    w_u32(record + 16, child);
    uint32 identifier = r_u32(owner + 8);
    w_u16(record + 44, 0);
    w_u32(record, previous);
    w_u32(0x800C84F0, record);
    w_u16(record + 50, identifier);
    ob_draft_scratch_release(handle);
    return record;
}

uint32 ob_game_800B979C(uint32 node, uint32 scale, uint32 flags, uint32 time)
{
    FUNCTION_MARKER(0x800B979C, "GAME.BIN");
    uint32 attributes = ob_draft_scratch_acquire(96);
    ob_game_800B8E40(node, attributes, time);
    w_u32(attributes + 44, 0x800C4BA0);
    w_u32(attributes + 56, 1000);
    w_u8(attributes + 92, 16);
    uint32 owner = r_u32(0x80083E34);
    w_u16(attributes + 90, scale);
    w_u16(attributes + 86, scale);
    w_u16(attributes + 88, scale);
    w_u8(attributes + 93, 1);
    uint32 result = ob_game_80092408(owner, attributes, time, flags);
    ob_draft_scratch_release(attributes);
    return result;
}

uint32 ob_game_800BB9E8(uint32 input, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x800BB9E8, "GAME.BIN");
    uint32 object = r_u32(record + 80);
    if (object)
        return ob_draft_unresolved_call(0x800966EC, 3, object, r_u8(input + 3) ? 14 : 15, time);
    if (r_u8(input + 3))
    {
        w_u32(record + 100, 12);
        w_u16(record + 50, 1);
        return 1;
    }
    w_u32(record + 100, 13);
    w_u16(record + 50, 0);
    return 13;
}

uint32 ob_main_800341A4(uint32 descriptor)
{
    FUNCTION_MARKER(0x800341A4, "SLES_008.65");
    uint32 handle = ob_draft_scratch_acquire(4);
    w_u32(handle, 0);
    sub_800262CC(handle, 48);
    uint32 first = r_u32(handle);
    uint32 length = r_u16(descriptor + 4);
    w_u8(first + 10, 0);
    uint32 second = r_u32(handle);
    w_u16(first + 8, length);
    uint32 base = r_u32(0x800882BC);
    length = r_u16(second + 8);
    w_u32(second + 16, base + length);
    length = r_u16(descriptor + 4);
    w_u8(second + 34, 0);
    uint32 result = r_u32(handle);
    w_u16(second + 32, length);
    length = r_u16(result + 32);
    base = r_u32(0x800882BC);
    w_u32(0x8007742C, result);
    w_u32(0x80077464, result + 24);
    w_u32(result + 40, base + length);
    ob_draft_scratch_release(handle);
    return result;
}

uint32 ob_game_800C0EB0(uint32 position, uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800C0EB0, "GAME.BIN");
    uint32 attributes = ob_draft_scratch_acquire(32);
    uint32 x = r_u32(position);
    uint32 previous = r_u32(0x800D6750);
    w_u32(attributes + 4, 0);
    w_u32(attributes, x);
    w_u32(attributes + 8, r_u32(position + 8));
    uint32 identifier = r_u16(object + 296);
    w_u16(attributes + 18, 0);
    w_u16(attributes + 16, identifier);
    uint32 kind = r_u32(object + 292);
    w_u16(attributes + 22, 0);
    w_u32(attributes + 12, 231);
    w_u16(attributes + 20, kind);
    if (r_u32(object + 292) == 246)
    {
        w_u32(0x800C82F0, 2000);
        w_u32(0x800C82F4, 1000);
        w_u32(0x800C82F8, 2000);
    }
    uint32 result = ob_game_800BC3D8(r_u32(0x80083E34), attributes, time);
    w_u32(0x800D6750, previous);
    ob_draft_scratch_release(attributes);
    return result;
}


uint32 ob_main_80015CAC(uint32 x, uint32 y, uint32 tile)
{
    FUNCTION_MARKER(0x80015CAC, "SLES_008.65");
    sint32 index = (sint16)tile;
    sint32 row = index / 4;
    uint32 u = (uint32)((index - row * 4) * 16);
    uint32 v = (uint32)row << 4;
    x = (uint32)(sint32)(sint16)x;
    y = (uint32)(sint32)(sint16)y;
    uint32 size = r_u32(0x8006C174) * 15;
    return sub_80020FD4(0x80076A70, u, v, 15, 15, x, y, size, size, 0);
}

uint32 ob_game_800B9584(uint32 node, uint32 scale, uint32 flags, uint32 time)
{
    FUNCTION_MARKER(0x800B9584, "GAME.BIN");
    uint32 attributes = ob_draft_scratch_acquire(96);
    ob_game_800B8E40(node, attributes, time);
    uint32 quarter = (uint32)((sint32)(sint16)scale >> 2);
    w_u32(attributes + 44, 0x800C47E8);
    w_u32(attributes + 56, 900);
    w_u8(attributes + 92, 14);
    uint32 owner = r_u32(0x80083E34);
    w_u16(attributes + 90, quarter);
    w_u16(attributes + 86, quarter);
    w_u16(attributes + 88, scale);
    w_u8(attributes + 93, 4);
    uint32 result = ob_game_80092408(owner, attributes, time, flags);
    ob_draft_scratch_release(attributes);
    return result;
}

uint32 ob_main_80024B98(void)
{
    FUNCTION_MARKER(0x80024B98, "SLES_008.65");
    sub_8004B70C();
    ob_draft_unresolved_call(0x800BB494, 1, r_u32(0x800882BC));
    ob_main_800121A4();
    if (r_u8(0x8006C230))
    {
        uint32 table = 0x8006C138;
        uint32 index = 0;
        do
        {
            w_u32(table, 0);
            uint32 count = r_u8(0x8006C230);
            ++index;
            table += 4;
            if (index >= count) break;
        } while (1);
    }
    w_u32(0x8006C228, 1);
    ob_game_800954CC();
    w_u32(0x8006C228, 0);
    ob_game_800A0C34();
    ob_draft_unresolved_call(0x80045E98, 0);
    return ob_draft_unresolved_call(0x800C1914, 0);
}

uint32 ob_game_80092098(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x80092098, "GAME.BIN");
    uint32 slot = (uint32)(sint32)r_s16(object + 326);
    w_u16(0x800CBA46 + slot * 104, 0);
    uint32 result = r_u32(object + 288);
    if (result != 1)
    {
        sub_8004651C(r_u32(object + 52));
        w_u32(object + 52, 0);
        w_u32(object + 288, 1);
        result = ob_main_80011A24(0x800666C0, 128, 256, r_u32(object + 44), time, 0);
    }
    return result;
}

uint32 ob_game_800AFE94(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800AFE94, "GAME.BIN");
    uint32 result = r_u32(object + 288);
    if (result == 3) return result;
    uint32 node = r_u32(object + 44);
    w_u32(object + 288, 3);
    sub_80045A7C(node, time);
    sub_80045A44(r_u32(object + 44), 0x800C61B4);
    sub_80046544(r_u32(object + 52));
    if (r_u32(object + 64)) sub_80045F20(object + 64);
    w_u32(object + 100, 0x800AFF34);
    w_u32(object + 96, 0);
    w_u32(object + 92, time + 2000);
    return ob_draft_unresolved_call(0x80045EF4, 1, object + 64);
}

uint32 ob_main_80029384(uint32 input, uint32 output)
{
    FUNCTION_MARKER(0x80029384, "SLES_008.65");
    uint32 x = r_u32(input);
    uint32 y = r_u32(input + 4);
    uint32 z = r_u32(input + 8);
    if ((sint32)x < 0) x = 0 - x;
    if ((sint32)y < 0) y = 0 - y;
    if ((sint32)z < 0) z = 0 - z;
    uint32 combined = x | y | z;
    uint32 shift = 0;
    while (combined > 0x7FFF)
    {
        combined >>= 1;
        ++shift;
    }
    w_u32(output, (uint32)(r_s32(input) >> shift));
    w_u32(output + 4, (uint32)(r_s32(input + 4) >> shift));
    w_u32(output + 8, (uint32)(r_s32(input + 8) >> shift));
    return shift;
}

uint32 ob_main_80032058(uint32 position, uint32 angles)
{
    FUNCTION_MARKER(0x80032058, "SLES_008.65");
    uint32 result = r_u32(0x80077404);
    uint32 first = r_u32(position);
    uint32 second = r_u32(position + 4);
    uint32 third = r_u32(position + 8);
    w_u32(result, first);
    w_u32(result + 4, second);
    w_u32(result + 8, third);
    uint32 target = r_u32(0x80077404);
    uint32 pair = ob_batch2_load_unaligned(angles);
    uint32 last = (uint32)(sint32)r_s16(angles + 4);
    ob_batch2_store_unaligned(target + 12, pair);
    w_u16(target + 16, last);
    uint32 total = r_u16(0x80077346);
    uint32 count = r_u16(0x80077550);
    uint32 next = r_u32(0x80077404) + 20;
    ++total;
    ++count;
    w_u16(0x80077550, count);
    w_u16(0x80077346, total);
    w_u32(0x80077404, next);
    if ((count & 0xFFFF) == 24)
    {
        w_u32(0x80077404, sub_8002D98C(480));
        w_u16(0x80077550, 0);
    }
    return result;
}

uint32 ob_game_800A7CEC(uint32 object, uint32 record)
{
    FUNCTION_MARKER(0x800A7CEC, "GAME.BIN");
    uint32 kind = r_u32(record + 24);
    uint32 volume = kind == 32 ? 256 : 206;
    ob_draft_unresolved_call(0x80011D80, 2, (uint32)(sint32)r_s16(object + 306), volume);
    uint32 child = r_u32(record + 52);
    if (r_u32(child + 128))
    {
        sub_80011984(0x80066438, 255, 15, 30, 256, 0, 0);
        ob_draft_unresolved_call(0x8009A704, 1, child);
    }
    return (uint32)sub_80047FF0(record);
}

uint32 ob_game_800A8A40(uint32 first, uint32 second, uint32 time)
{
    FUNCTION_MARKER(0x800A8A40, "GAME.BIN");
    uint32 locals = ob_draft_scratch_acquire(40);
    ob_draft_unresolved_call(0x80045378, 3, r_u32(first + 44), time, locals);
    ob_draft_unresolved_call(0x80045378, 3, r_u32(second + 44), time, locals + 16);
    uint32 second_z = r_u32(locals + 24);
    uint32 first_z = r_u32(locals + 8);
    uint32 second_x = r_u32(locals + 16);
    uint32 first_x = r_u32(locals);
    ob_draft_unresolved_call(0x80028280, 4, second_z - first_z, second_x - first_x, locals + 32, locals + 36);
    uint32 heading = r_u16(first + 296);
    uint32 target = r_u16(locals + 32);
    uint32 result = heading - target;
    w_u16(locals + 32, result);
    ob_draft_scratch_release(locals);
    return (uint32)(sint32)(sint16)result;
}

uint32 ob_main_8002755C(uint32 header, uint32 size)
{
    FUNCTION_MARKER(0x8002755C, "SLES_008.65");
    uint32 count = r_u16(header + 36);
    uint32 heap = r_u32(0x80077228);
    uint32 link = r_u32(header + 24);
    w_u16(header + 36, count + 1);
    uint32 result = sub_80026D30(size, heap);
    if (!result) ob_main_800279CC();
    uint32 payload = r_u32(link);
    uint32 previous = payload - 40;
    w_u16(payload - 4, r_u16(payload - 4) - 1);
    ob_draft_unresolved_call(0x800275F8, 2, previous, result);
    ob_draft_unresolved_call(0x8002776C, 2, result, payload);
    sub_80027154(previous);
    return result;
}

uint32 ob_main_800541A8(uint32 port)
{
    FUNCTION_MARKER(0x800541A8, "SLES_008.65");
    uint32 address = port ? 0x8008CE90 : 0x8008CB28;
    uint32 disconnected = r_u8(address);
    uint32 status = r_u8(address + 1);
    if (!disconnected) return (status >> 4) == 8;
    if ((status >> 4) != 8) return 0;
    w_u8(address + 1, status & 15);
    return 1;
}

uint32 ob_game_800A9680(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800A9680, "GAME.BIN");
    uint32 node = r_u32(object + 52);
    uint32 data = r_u32(object + 112);
    sub_80046544(node);
    uint32 saved = r_u8(data + 40);
    w_u8(data + 40, 0);
    ob_draft_unresolved_call(0x800B7DA8, 2, r_u32(object + 120), 8);
    ob_game_800B5BD8(0, r_u32(object + 120), r_u8(data + 40), time);
    uint32 result = ob_game_800B5C50(0, r_u32(object + 120), time);
    if (result) result = ob_game_800B5CB4(object, 0, 0, time);
    w_u8(data + 40, saved);
    return result;
}

uint32 ob_main_800305CC(uint32 first, uint32 second, uint32 output)
{
    FUNCTION_MARKER(0x800305CC, "SLES_008.65");
    uint32 a = (uint32)(sint32)r_s16(first + 4);
    uint32 b = (uint32)(sint32)r_s16(second + 2);
    uint32 product = a * b;
    a = (uint32)(sint32)r_s16(first + 2);
    b = (uint32)(sint32)r_s16(second + 4);
    uint32 negative = (0 - a) * b;
    w_u16(output, (uint32)((sint32)(product + negative) >> 14));
    a = (uint32)(sint32)r_s16(first);
    b = (uint32)(sint32)r_s16(second + 4);
    product = a * b;
    a = (uint32)(sint32)r_s16(first + 4);
    b = (uint32)(sint32)r_s16(second);
    negative = (0 - a) * b;
    w_u16(output + 2, (uint32)((sint32)(product + negative) >> 14));
    a = (uint32)(sint32)r_s16(first + 2);
    b = (uint32)(sint32)r_s16(second);
    product = a * b;
    a = (uint32)(sint32)r_s16(first);
    b = (uint32)(sint32)r_s16(second + 2);
    negative = (0 - a) * b;
    w_u16(output + 4, (uint32)((sint32)(product + negative) >> 14));
    return negative;
}

uint32 ob_game_80094CC0(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x80094CC0, "GAME.BIN");
    sub_80046544(r_u32(object + 52));
    sub_80045A7C(r_u32(object + 44), time);
    sub_80045A44(r_u32(object + 44), 0x800C4D94);
    w_u32(object + 100, 0x80094D6C);
    w_u32(object + 96, 0);
    w_u32(object + 92, time + 2000);
    ob_draft_unresolved_call(0x80045EF4, 1, object + 64);
    uint32 position = sub_80045464(r_u32(object + 44), time);
    w_u32(position + 4, 0xFFFFFFFF);
    sub_80045B74(r_u32(object + 44));
    return ob_draft_unresolved_call(0x800B83FC, 4, r_u32(object + 44), 10, 200, time);
}

uint32 ob_game_800AAB84(uint32 object, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x800AAB84, "GAME.BIN");
    sub_80046544(r_u32(object + 52));
    sub_80045A7C(r_u32(object + 44), time);
    sub_80045A44(r_u32(object + 44), 0x800C61B4);
    ob_main_80044080(r_u32(object + 48), 0x800698CC);
    w_u8(r_u32(object + 60) + 54, 1);
    ob_main_80011A24(0x800698D0, 255, 256, r_u32(object + 44), time, 0);
    return (uint32)sub_80047FF0(record);
}

uint32 ob_game_800A2C8C(uint32 object)
{
    FUNCTION_MARKER(0x800A2C8C, "GAME.BIN");
    ob_game_800A4AC8(1);
    uint32 slot = (uint32)(sint32)r_s16(object + 326);
    uint32 child = r_u32(0x800CBA48 + slot * 104);
    if (child)
    {
        ob_game_8009B0F0(child);
        slot = (uint32)(sint32)r_s16(object + 326);
        ob_game_8009B0F0(0x800CBA00 + slot * 104);
        slot = (uint32)(sint32)r_s16(object + 326);
    }
    w_u32(0x800C835C, 0);
    uint32 result = slot * 104;
    w_u16(0x800CBA36 + result, 0);
    return result;
}
