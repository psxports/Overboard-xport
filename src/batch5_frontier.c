#include "batch5_frontier.h"
#include "audit_frontier.h"
#include "memory_frontier.h"

uint32 ob_memory_unlock_block(uint32 block, uint32 flags)
{
    FUNCTION_MARKER(0x80027810u, "SLES_008.65");
    if (flags & 1u)
    {
        uint32 count = r_u16(block + 34u);
        if (count != 0u)
            w_u16(block + 34u, count - 1u);
    }
    uint32 result = flags & 2u;
    if (result != 0u)
    {
        uint32 count = r_u16(block + 36u);
        result = count - 1u;
        if (count != 0u)
            w_u16(block + 36u, result);
    }
    return result;
}

uint32 ob_align_value(uint32 value, uint32 alignment)
{
    FUNCTION_MARKER(0x8002DB6Cu, "SLES_008.65");
    uint32 mask = alignment - 1u;
    return (value + mask) & ~mask;
}

uint32 ob_memory_set_slot_tail(uint32 identifier, uint32 value)
{
    FUNCTION_MARKER(0x80027AACu, "SLES_008.65");
    uint32 slot = ob_memory_valid_slot_address(identifier & 0xFFFFu);
    uint32 object = r_u32(slot);
    w_u32(object + 12u, value);
    return object;
}

uint32 ob_memory_set_word_for_payload(uint32 payload, uint32 value)
{
    FUNCTION_MARKER(0x800255F0u, "SLES_008.65");
    uint32 identifier = ob_memory_find_identifier(payload);
    return ob_memory_set_slot_word(identifier & 0xFFFFu, value);
}

uint32 ob_memory_set_tail_for_payload(uint32 payload, uint32 value)
{
    FUNCTION_MARKER(0x80025658u, "SLES_008.65");
    uint32 identifier = ob_memory_find_identifier(payload);
    return ob_memory_set_slot_tail(identifier & 0xFFFFu, value);
}

uint32 ob_init_geometry_callbacks(void)
{
    FUNCTION_MARKER(0x80035178u, "SLES_008.65");
    ob_memory_set_word_for_payload(0x8006615Cu, 0x80034E10u);
    ob_memory_set_word_for_payload(0x80066160u, 0x800349D8u);
    ob_memory_set_word_for_payload(0x80066150u, 0x80034910u);
    uint32 width = r_u32(0x800775DCu);
    uint32 x = r_u32(0x800775E0u);
    uint32 height = r_u32(0x80077370u);
    uint32 y = r_u32(0x80077378u);
    w_u32(0x80077608u, 0u);
    w_u32(0x800773F4u, 0u);
    uint32 result = width + 512u;
    w_u32(0x800774D8u, result);
    w_u32(0x800774DCu, x);
    w_u32(0x800774B4u, height);
    w_u32(0x800774B8u, y);
    for (uint32 offset = 224u;; offset -= 16u)
    {
        w_u16(0x8007F8CCu + offset, 0u);
        if (offset == 0u)
            break;
    }
    return result;
}

uint32 ob_init_object_callbacks(void)
{
    FUNCTION_MARKER(0x80033F48u, "SLES_008.65");
    ob_memory_set_word_for_payload(0x80066144u, 0x80033528u);
    return ob_memory_set_tail_for_payload(0x80066144u, 0x80033F24u);
}

uint32 ob_reset_geometry_record(uint32 record)
{
    FUNCTION_MARKER(0x8002DC10u, "SLES_008.65");
    for (uint32 index = 0u; index < 80u; ++index)
        w_u8(record + index, 0u);
    w_u16(record + 76u, 256u);
    w_u16(record + 18u, 0u);
    w_u16(record + 20u, 500u);
    return 500u;
}

uint32 ob_init_geometry_record(void)
{
    FUNCTION_MARKER(0x80030924u, "SLES_008.65");
    ob_reset_geometry_record(0x800882C8u);
    uint32 result = r_u32(0x800882F8u) | 0x22u;
    w_u32(0x800882F8u, result);
    return result;
}
