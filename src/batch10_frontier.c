#include "batch10_frontier.h"
#include "memory_frontier.h"
#include "audit_frontier.h"

uint32 ob_consume_button_edge(uint32 index)
{
    FUNCTION_MARKER(0x80054440u, "SLES_008.65");
    index &= 0xFFu;
    uint32 saved = r_u8(0x80088318u + index);
    if ((saved & 0x20u) == 0u)
        return 0u;
    uint32 current = r_u8(0x8007FA00u + index);
    saved = r_u8(0x80088318u + index);
    w_u8(0x8007FA00u + index, current & 0xDFu);
    w_u8(0x80088318u + index, saved & 0xDFu);
    return 0xFFFFFFFFu;
}

uint32 ob_clear_button_edges(void)
{
    FUNCTION_MARKER(0x800544ECu, "SLES_008.65");
    for (uint32 index = 0u; index < 128u; ++index)
    {
        uint32 current = r_u8(0x8007FA00u + index);
        w_u8(0x8007FA00u + index, current & 0xDFu);
        uint32 saved = r_u8(0x80088318u + index);
        w_u8(0x80088318u + index, saved & 0xDFu);
    }
    return 0u;
}

uint32 ob_switch_frame_buffer(void)
{
    FUNCTION_MARKER(0x8002CFA8u, "SLES_008.65");
    uint32 state = 1u - r_u32(0x800773D0u);
    w_u32(0x800773D0u, state);
    uint32 frame_buffer = state != 0u ? 0x80086AD8u : 0x80086A48u;
    w_u32(0x8007737Cu, frame_buffer);
    return frame_buffer;
}

uint32 ob_memory_coalesce_free(uint32 block)
{
    FUNCTION_MARKER(0x80027154u, "SLES_008.65");
    uint32 previous = r_u32(block);
    if (previous != 0u && (r_u8(previous + 32u) & 0x80u) != 0u)
    {
        block = previous;
        ob_memory_unlink_free(block);
        ob_memory_merge_next(block);
    }
    uint32 next = r_u32(block + 4u);
    if (next != 0u && (r_u8(next + 32u) & 0x80u) != 0u)
    {
        ob_memory_unlink_free(next);
        ob_memory_merge_next(block);
    }
    return ob_memory_insert_free(block);
}
