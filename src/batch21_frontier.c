#include "batch21_frontier.h"
#include "batch5_frontier.h"
#include "batch16_frontier.h"

uint32 ob_relocate_effect_tables(uint32 descriptor, uint32 base)
{
    FUNCTION_MARKER(0x8004B9B0u, "SLES_008.65");
    uint32 cells = r_u32(descriptor + 12u);
    uint32 records = r_u32(descriptor + 20u);
    w_u32(descriptor + 12u, cells + base);
    uint32 indices = r_u32(descriptor + 16u);
    w_u32(descriptor + 20u, records + base);
    uint32 context = r_u32(descriptor + 28u);
    w_u32(descriptor + 16u, indices + base);
    uint32 blocks = r_u32(descriptor + 24u);
    context += base;
    w_u32(descriptor + 28u, context);
    w_u32(descriptor + 24u, blocks + base);
    uint32 value = r_u32(context + 4u);
    w_u32(context + 4u, value + base);
    context = r_u32(descriptor + 28u);
    value = r_u32(context + 8u);
    w_u32(context + 8u, value + base);
    context = r_u32(descriptor + 28u);
    value = r_u32(context + 12u);
    w_u32(context + 12u, value + base);
    uint32 first_context = r_u32(descriptor + 28u);
    uint32 context_global = r_u32(descriptor + 28u);
    uint32 last_context = r_u32(descriptor + 28u);
    uint32 first = r_u32(first_context + 4u);
    uint32 middle_context = r_u32(descriptor + 28u);
    uint32 last = r_u32(last_context + 12u);
    uint32 middle = r_u32(middle_context + 8u);
    w_u32(0x80077190u, context_global);
    w_u32(0x80077194u, first);
    w_u32(0x8007719Cu, last);
    w_u32(0x80077198u, middle);
    return middle;
}

uint32 ob_classify_effect_block(uint32 block)
{
    FUNCTION_MARKER(0x8004BA98u, "SLES_008.65");
    uint32 first = r_u32(block);
    sint32 maximum = r_s8(block + 12u);
    uint32 second = r_u32(block + 4u);
    uint32 mask = first != 0u ? (second != 0u) : (second != 0u ? 7u : 15u);
    for (uint32 index = 1u; index < 9u; ++index)
    {
        sint32 sample = r_s8(block + 12u + index);
        if (maximum < sample)
            maximum = sample;
    }
    if (maximum >= -127)
        mask &= ~8u;
    if (maximum >= -39)
        mask &= ~4u;
    if (maximum > 0)
        mask &= ~2u;
    if (maximum >= 101)
        mask &= ~1u;
    w_u8(block + 23u, (uint32)maximum);
    w_u8(block + 22u, mask);
    return 0xFFFFFFFEu;
}

uint32 ob_classify_effect_blocks(uint32 descriptor)
{
    FUNCTION_MARKER(0x8004BC2Cu, "SLES_008.65");
    uint32 count = r_u8(descriptor + 11u);
    uint32 block = r_u32(descriptor + 24u);
    uint32 result = 0xFFFFFFFFu;
    for (uint32 index = 0u; index < count; ++index)
    {
        result = ob_classify_effect_block(block);
        block += 24u;
    }
    return result;
}

uint32 ob_classify_effect_index(uint32 cell, uint32 descriptor)
{
    FUNCTION_MARKER(0x8004BB48u, "SLES_008.65");
    uint32 mask = 15u;
    uint32 encoded = r_u16(cell);
    uint32 blocks = r_u32(descriptor + 24u);
    uint32 table = r_u32(descriptor + 20u);
    uint32 record = table + ((encoded & 0xFFF0u) << 2);
    for (uint32 index = 0u; index < 16u; ++index)
    {
        uint32 block_index = r_u8(record);
        uint32 block = blocks + block_index * 24u;
        uint32 block_mask = r_u8(block + 22u);
        if (block_mask != 0u)
            mask &= block_mask;
        else
        {
            uint32 height_bits = r_u16(record + 2u);
            sint32 maximum = r_s8(block + 23u);
            sint32 height = ((sint32)(height_bits << 16)) >> 22;
            mask &= 1u;
            if (height + maximum >= 100)
                mask = 0u;
        }
        record += 4u;
    }
    uint32 result = (r_u16(cell) & 0xFFF0u) | mask;
    w_u16(cell, result);
    return result;
}

uint32 ob_classify_effect_indices(uint32 descriptor)
{
    FUNCTION_MARKER(0x8004BC88u, "SLES_008.65");
    uint32 count = r_u8(descriptor + 10u) << 4;
    uint32 cell = r_u32(descriptor + 16u);
    uint32 result = 0xFFFFFFFFu;
    for (uint32 index = 0u; index < count; ++index)
    {
        result = ob_classify_effect_index(cell, descriptor);
        cell += 2u;
    }
    return result;
}

uint32 ob_classify_effect_cell(uint32 cell, uint32 descriptor)
{
    FUNCTION_MARKER(0x8004BBE4u, "SLES_008.65");
    uint32 mask = 15u;
    uint32 encoded = r_u16(cell);
    uint32 table = r_u32(descriptor + 16u);
    uint32 entry = table + ((encoded & 0xFFF0u) << 1);
    for (uint32 index = 0u; index < 16u; ++index)
    {
        mask &= r_u16(entry);
        entry += 2u;
    }
    uint32 result = (r_u16(cell) & 0xFFF0u) | mask;
    w_u16(cell, result);
    return result;
}

uint32 ob_classify_effect_cells(uint32 descriptor)
{
    FUNCTION_MARKER(0x8004BCF8u, "SLES_008.65");
    sint32 width = r_s16(descriptor + 4u);
    sint32 height = r_s16(descriptor + 6u);
    uint32 cell = r_u32(descriptor + 12u);
    uint32 remaining = (uint32)((sint64)width * height) - 1u;
    uint32 result = 0xFFFFFFFFu;
    while (remaining != 0xFFFFFFFFu)
    {
        result = ob_classify_effect_cell(cell, descriptor);
        --remaining;
        cell += 2u;
    }
    return result;
}

uint32 ob_classify_effect_tables(uint32 descriptor)
{
    FUNCTION_MARKER(0x8004BA60u, "SLES_008.65");
    ob_classify_effect_blocks(descriptor);
    ob_classify_effect_indices(descriptor);
    return ob_classify_effect_cells(descriptor);
}

uint32 ob_effect_setup_stub_result(uint32 incoming_result)
{
    FUNCTION_MARKER(0x80024310u, "SLES_008.65");
    return incoming_result;
}

uint32 ob_clear_effect_workspace(void)
{
    FUNCTION_MARKER(0x8004B3C4u, "SLES_008.65");
    uint32 address = 0x80084994u;
    for (uint32 count = 0u; count < 256u; ++count)
    {
        w_u32(address, 0u);
        address -= 4u;
    }
    return address;
}

uint32 ob_init_view_geometry(void)
{
    FUNCTION_MARKER(0x80013820u, "SLES_008.65");
    uint32 descriptor = r_u32(0x800770C0u);
    uint32 width = r_u32(descriptor + 12u);
    width += width >> 31;
    uint32 height = r_u32(descriptor + 16u);
    height += height >> 31;
    uint32 origin_x = r_u32(0x80065DF0u);
    uint32 half_width = (uint32)((sint32)width >> 1);
    w_u32(0x80089B84u, half_width);
    uint32 x = origin_x - half_width;
    uint32 origin_y = r_u32(0x80065DF4u);
    uint32 half_height = (uint32)((sint32)height >> 1);
    w_u32(0x80089B88u, half_height);
    w_u32(0x80084AA0u, x);
    uint32 scale = r_u32(descriptor + 8u);
    uint32 y = half_height - origin_y;
    w_u32(0x80084AA4u, y);
    w_u32(0x80084AC4u, scale);
    ob_reset_geometry_record(0x80089B98u);
    uint32 flags = (r_u32(0x80089BC8u) | 2u) & 0xFFFFFFFEu;
    w_u32(0x80089BC8u, flags);
    ob_reset_geometry_record(0x8008C678u);
    uint32 result = (r_u32(0x80089BC8u) | 2u) & 0xFFFFFFFEu;
    w_u32(0x80089BC8u, result);
    return result;
}

uint32 ob_refresh_effect_records(void)
{
    FUNCTION_MARKER(0x8004B70Cu, "SLES_008.65");
    uint32 descriptor = r_u32(0x80077644u);
    uint32 count = r_u16(descriptor + 8u) << 4;
    uint32 record = r_u32(descriptor + 20u);
    uint32 result = 0xFFFFFFFFu;
    for (uint32 index = 0u; index < count; ++index)
    {
        uint32 value = r_u8(record + 1u);
        result = value >> 6;
        if (value != 0u)
        {
            uint32 block_index = r_u8(record) - result;
            w_u8(record, block_index);
            block_index &= 0xFFu;
            descriptor = r_u32(0x80077644u);
            uint32 blocks = r_u32(descriptor + 24u);
            result = r_u8(blocks + block_index * 24u + 21u);
            w_u8(record + 1u, result);
        }
        record += 4u;
    }
    return result;
}

uint32 ob_init_effect_object_list(void)
{
    FUNCTION_MARKER(0x80045D44u, "SLES_008.65");
    uint32 result = ob_init_object_list(0x800896F0u);
    w_u32(0x80077334u, 0u);
    return result;
}
