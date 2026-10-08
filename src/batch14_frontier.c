#include "batch14_frontier.h"

uint32 ob_set_audio_mode(uint32 mode)
{
    FUNCTION_MARKER(0x8001DF34u, "SLES_008.65");
    uint32 enabled = r_u8(0x8006C00Cu);
    if (enabled != 0u)
        w_u8(0x8006C010u, mode);
    return enabled;
}

uint32 ob_swap_bytes(uint32 value)
{
    FUNCTION_MARKER(0x80020260u, "SLES_008.65");
    return (value >> 24) | ((value >> 8) & 0xFF00u) | ((value & 0xFF00u) << 8) | (value << 24);
}

uint32 ob_relocate_geometry(uint32 geometry, uint32 base)
{
    FUNCTION_MARKER(0x80035618u, "SLES_008.65");
    uint32 entries = r_u32(geometry + 0x34u);
    uint32 field24 = r_u32(geometry + 0x24u);
    entries += base;
    uint32 field20 = r_u32(geometry + 0x20u);
    w_u32(geometry + 0x24u, base + field24);
    uint32 field2c = r_u32(geometry + 0x2Cu);
    w_u32(geometry + 0x34u, entries);
    w_u32(geometry + 0x20u, base + field20);
    uint32 field28 = r_u32(geometry + 0x28u);
    w_u32(geometry + 0x2Cu, base + field2c);
    uint32 entry_count = r_u16(geometry + 0xEu);
    w_u32(geometry + 0x28u, base + field28);
    uint32 field30 = r_u32(geometry + 0x30u);
    w_u32(geometry + 0x30u, base + field30);
    for (uint32 index = 0u; index < entry_count; ++index)
    {
        uint32 entry = r_u32(entries);
        w_u32(entries, base + entry);
        entries += 4u;
    }
    uint32 result = r_u16(geometry + 4u) & 2u;
    if (result == 0u)
        return result;
    uint32 count = r_u16(geometry + 0x10u);
    uint32 first_count = r_u16(geometry);
    uint32 stream = r_u32(geometry + 0x38u);
    count += first_count;
    stream += base;
    w_u32(geometry + 0x38u, stream);
    uint32 active = 0u;
    while ((count & 0xFFFFu) != 0u)
    {
        if (r_u32(stream) == 0u && r_u32(stream + 4u) == 0u)
        {
            uint32 run = r_u16(stream + 8u);
            stream += 12u;
            count -= run;
            if ((run & 1u) == 0u)
                ++run;
            stream += ((run & 0xFFFFu) << 1) - 2u;
        }
        else if (r_u32(stream) == 0xFFFFFFFFu && r_u32(stream + 4u) == 0xFFFFFFFFu)
        {
            --count;
            stream += 12u;
        }
        else
        {
            uint32 first = r_u32(stream);
            if (first != 0u)
                w_u32(stream, base + first);
            uint32 second = r_u32(stream + 4u);
            if (second != 0u)
                w_u32(stream + 4u, base + second);
            stream += 12u;
            --count;
            ++active;
        }
    }
    result = active + 4u;
    w_u32(geometry + 0x1Cu, result);
    return result;
}
