#include "batch9_frontier.h"

uint32 ob_memory_payload_size(uint32 handle)
{
    FUNCTION_MARKER(0x800268D0u, "SLES_008.65");
    uint32 payload = r_u32(handle);
    uint32 allocated = r_u32(payload - 24u);
    uint32 overhead = r_u32(payload - 20u);
    return allocated - overhead;
}

uint32 ob_memory_release_reference(uint32 handle)
{
    FUNCTION_MARKER(0x800257A0u, "SLES_008.65");
    uint32 payload = r_u32(handle);
    uint32 flags = payload & 3u;
    if (flags != 0u)
        return flags;
    uint32 count = r_u16(payload - 6u) - 1u;
    w_u16(payload - 6u, count);
    return count;
}

uint32 ob_reset_overlay_state(void)
{
    FUNCTION_MARKER(0x800170D0u, "SLES_008.65");
    w_u32(0x80065FF8u, 0xFFFFFFFFu);
    w_u32(0x80065FFCu, 0u);
    w_u32(0x80065FF4u, 1u);
    return 1u;
}

uint32 ob_memory_query_statistics(uint32 output)
{
    FUNCTION_MARKER(0x800260C8u, "SLES_008.65");
    uint32 available = r_u32(0x80077248u);
    uint32 head = r_u32(0x80077224u);
    uint32 free_count = r_u32(0x8007723Cu);
    w_u32(output, available);
    uint32 block = r_u32(head + 8u);
    uint32 used_count = r_u32(0x80077240u);
    uint32 size = r_u32(block + 16u);
    w_u32(output + 8u, free_count);
    w_u32(output + 12u, used_count);
    uint32 result = size - 4u;
    w_u32(output + 4u, result);
    return result;
}

uint32 ob_stream_stub_result(void)
{
    FUNCTION_MARKER(0x80058FC0u, "SLES_008.65");
    return 1u;
}

uint32 ob_snapshot_controller_flags(void)
{
    FUNCTION_MARKER(0x80054320u, "SLES_008.65");
    for (uint32 offset = 0u; offset < 128u; offset += 16u)
    {
        uint32 first = r_u32(0x8007FA00u + offset);
        uint32 second = r_u32(0x8007FA04u + offset);
        uint32 third = r_u32(0x8007FA08u + offset);
        uint32 fourth = r_u32(0x8007FA0Cu + offset);
        w_u32(0x80088318u + offset, first);
        w_u32(0x8008831Cu + offset, second);
        w_u32(0x80088320u + offset, third);
        w_u32(0x80088324u + offset, fourth);
    }
    for (uint32 index = 0u; index < 128u; ++index)
    {
        uint32 value = r_u8(0x8007FA00u + index);
        w_u8(0x8007FA00u + index, value & 0xE1u);
    }
    return 0u;
}
