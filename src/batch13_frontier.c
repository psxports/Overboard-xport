#include "batch13_frontier.h"
#include "batch12_frontier.h"

uint32 ob_decode_weight_tree(uint32 tree, uint32 root)
{
    FUNCTION_MARKER(0x80021DE8u, "SLES_008.65");
    uint32 width = r_u16(tree);
    uint32 height = r_u16(tree + 2u);
    uint32 total = width * height;
    uint32 mask = 0x80u;
    uint32 emitted = 0u;
    uint32 weights = tree + 4u;
    uint32 stream = r_u32(tree + 0x2028u);
    uint32 output = r_u32(tree + 0x2030u);
    uint32 packed = r_u8(stream);
    uint32 result;
    do
    {
        uint32 node = root;
        do
        {
            uint32 child_offset = (packed & mask) != 0u ? 12u : 8u;
            node = r_u32(weights + (node << 4) + child_offset);
            mask >>= 1;
            if (mask == 0u)
            {
                mask = 0x80u;
                ++stream;
                packed = r_u8(stream);
            }
        } while ((int32_t)node >= 0x101);
        output -= 2u;
        uint32 symbols = r_u32(tree + 0x2024u);
        result = r_u16(symbols + (node << 1));
        ++emitted;
        w_u16(output, result);
    } while (emitted != total);
    return result;
}

uint32 ob_unpack_weight_image(uint32 tree)
{
    FUNCTION_MARKER(0x80021D80u, "SLES_008.65");
    for (uint32 index = 0u; index < 256u; ++index)
    {
        uint32 frequencies = r_u32(tree + 0x202Cu);
        uint32 frequency = r_u16(frequencies + (index << 1));
        w_u32(tree + (index << 4) + 4u, frequency);
    }
    w_u32(tree + 0x1004u, 0u);
    uint32 root = ob_build_weight_tree(tree);
    return ob_decode_weight_tree(tree, root);
}

uint32 ob_reset_geometry_workspace(void)
{
    FUNCTION_MARKER(0x80035220u, "SLES_008.65");
    uint32 start = r_u32(0x800775DCu);
    uint32 end = r_u32(0x800775E0u);
    uint32 first = r_u32(0x80077370u);
    uint32 second = r_u32(0x80077378u);
    w_u32(0x80077608u, 0u);
    w_u32(0x800773F4u, 0u);
    uint32 result = start + 0x200u;
    w_u32(0x800774D8u, result);
    w_u32(0x800774DCu, end);
    w_u32(0x800774B4u, first);
    w_u32(0x800774B8u, second);
    for (uint32 offset = 0xE0u;; offset -= 16u)
    {
        w_u16(0x8007F8CCu + offset, 0u);
        if (offset == 0u)
            break;
    }
    return result;
}

uint32 ob_set_update_callback(uint32 callback, uint32 incoming_result)
{
    FUNCTION_MARKER(0x80024F18u, "SLES_008.65");
    w_u32(0x80077090u, callback);
    return incoming_result;
}

uint32 ob_card_channel(uint32 index)
{
    FUNCTION_MARKER(0x80013794u, "SLES_008.65");
    switch (index)
    {
        case 0xFFFFFFFFu:
            return 0u;
        case 0u:
            return 0u;
        case 1u:
            return 1u;
        case 2u:
            return 2u;
        case 3u:
            return 3u;
        case 4u:
            return 0x10u;
        case 5u:
            return 0x11u;
        case 6u:
            return 0x12u;
        case 7u:
            return 0x13u;
        default:
            return 0u;
    }
}
