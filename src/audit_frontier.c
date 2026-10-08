#include "audit_frontier.h"
#include "memory_frontier.h"
#include <stdint.h>

uint32 ob_file_reset_tables(void)
{
    FUNCTION_MARKER(0x80054CFCu, "SLES_008.65");
    for (uint32 offset = 32u;; offset -= 16u)
    {
        w_u32(0x80089908u + offset, 0u);
        if (offset == 0u)
            break;
    }
    w_u32(0x8007740Cu, 0u);
    for (uint32 offset = 216u;; offset -= 24u)
    {
        w_u8(0x8007FD18u + offset, 0u);
        if (offset == 0u)
            break;
    }
    w_u32(0x800775D4u, 0u);
    w_u32(0x800771E8u, 0u);
    return 0u;
}

uint32 ob_memory_unlink_used(uint32 block)
{
    FUNCTION_MARKER(0x80027978u, "SLES_008.65");
    uint32 previous = r_u32(block + 8u);
    uint32 count = r_u32(0x80077240u) - 1u;
    uint32 next = r_u32(block + 12u);
    w_u32(previous + 12u, next);
    w_u32(next + 8u, previous);
    w_u32(block + 12u, 0u);
    w_u32(block + 8u, 0u);
    w_u32(0x80077240u, count);
    return count;
}

uint32 ob_copy_string(uint32 destination, uint32 source)
{
    FUNCTION_MARKER(0x80025D50u, "SLES_008.65");
    uint32 value;
    do
    {
        value = r_u8(source);
        ++source;
        w_u8(destination, value);
        ++destination;
    } while (value != 0u);
    return value;
}

uint32 ob_bcd_to_frame(uint32 source)
{
    FUNCTION_MARKER(0x80056580u, "SLES_008.65");
    uint32 first = r_u8(source);
    uint32 second = r_u8(source + 1u);
    uint32 third = r_u8(source + 2u);
    uint32 minute = 10u * (first >> 4u) + (first & 15u);
    uint32 second_value = 10u * (second >> 4u) + (second & 15u);
    uint32 frame = 10u * (third >> 4u) + (third & 15u);
    return 75u * (60u * minute + second_value) + frame - 150u;
}

uint32 ob_file_entry_size(uint32 index)
{
    FUNCTION_MARKER(0x800556D8u, "SLES_008.65");
    return r_u32(0x80089914u + (index << 4u));
}

static uint32 ob_bcd_signed_value(uint32 value)
{
    uint32 biased = (int32_t)value < 0 ? value + 15u : value;
    int32_t quotient = (int32_t)biased >> 4u;
    return 10u * (uint32)quotient + (value & 15u);
}

uint32 ob_bcd_fields_to_frame(uint32 minute, uint32 second, uint32 frame, uint32 destination)
{
    FUNCTION_MARKER(0x80054D50u, "SLES_008.65");
    uint32 first = 4500u * ob_bcd_signed_value(minute);
    w_u32(destination, first);
    uint32 second_value = first + 75u * ob_bcd_signed_value(second);
    w_u32(destination, second_value);
    uint32 result = second_value + ob_bcd_signed_value(frame);
    w_u32(destination, result);
    return result;
}

uint32 ob_file_close_slot(uint32 index)
{
    FUNCTION_MARKER(0x800551B0u, "SLES_008.65");
    if (index >= 3u)
        return 0xFFFFFFFFu;
    uint32 address = 0x80089908u + (index << 4u);
    uint32 value = r_u32(address) & ~1u;
    w_u32(address, value);
    return 0u;
}

uint32 ob_string_equal_code(uint32 left, uint32 right)
{
    FUNCTION_MARKER(0x80025D6Cu, "SLES_008.65");
    for (;;)
    {
        uint32 left_byte = r_u8(left);
        uint32 right_byte = r_u8(right);
        if (left_byte != right_byte)
            return 0u;
        if (left_byte == 0u)
            return 0xFFFFFFFFu;
        ++left;
        ++right;
    }
}

uint32 ob_memory_merge_next(uint32 block)
{
    FUNCTION_MARKER(0x80026950u, "SLES_008.65");
    uint32 count = r_u32(0x80077238u);
    uint32 next = r_u32(block + 4u);
    w_u32(0x80077238u, count - 1u);
    uint32 size = r_u32(block + 16u);
    uint32 next_size = r_u32(next + 16u);
    uint32 successor = r_u32(next + 4u);
    uint32 merged = size + 40u + next_size;
    w_u32(block + 16u, merged);
    w_u32(successor, block);
    w_u32(block + 4u, successor);
    return merged;
}

uint32 ob_memory_find_identifier(uint32 payload)
{
    FUNCTION_MARKER(0x80027D78u, "SLES_008.65");
    uint32 tables = r_u32(0x800775F4u);
    for (uint32 group = 0u; group < 256u; ++group)
    {
        uint32 table = r_u32(tables + group * 4u);
        if (table == 0u)
            continue;
        uint32 difference = payload - r_u32(table);
        uint32 index = (uint32)((int32_t)difference >> 2u);
        if (index >= 256u)
            continue;
        uint32 byte_offset = (uint32)((int32_t)difference >> 5u);
        uint32 mask = 0x80u >> (index & 7u);
        if ((r_u8(table + byte_offset + 6u) & mask) != 0u)
            return (group << 8u) | index;
    }
    return 0u;
}

uint32 ob_memory_set_slot_word(uint32 identifier, uint32 value)
{
    FUNCTION_MARKER(0x80027A3Cu, "SLES_008.65");
    uint32 slot = ob_memory_valid_slot_address(identifier & 0xFFFFu);
    uint32 object = r_u32(slot);
    w_u32(object + 4u, value);
    return object;
}

uint32 ob_set_render_mode(uint32 mode)
{
    FUNCTION_MARKER(0x8005A9DCu, "SLES_008.65");
    uint32 previous = r_u32(0x80075008u);
    w_u32(0x80075008u, mode);
    return previous;
}

uint32 ob_get_render_mode(void)
{
    FUNCTION_MARKER(0x8005A9F4u, "SLES_008.65");
    return r_u32(0x80075008u);
}
