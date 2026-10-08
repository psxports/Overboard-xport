#include "batch12_frontier.h"
#include "memory_frontier.h"

uint32 ob_draw_text_begin(uint32 incoming_result)
{
    FUNCTION_MARKER(0x800170C8u, "SLES_008.65");
    return incoming_result;
}

uint32 ob_draw_text_end(uint32 incoming_result)
{
    FUNCTION_MARKER(0x800170C0u, "SLES_008.65");
    return incoming_result;
}

uint32 ob_handle_slot_address(uint32 identifier)
{
    FUNCTION_MARKER(0x80025874u, "SLES_008.65");
    return ob_memory_slot_address(identifier & 0xFFFFu);
}

uint32 ob_fill_words(uint32 destination, uint32 bytes, uint32 value, uint32 incoming_result)
{
    FUNCTION_MARKER(0x80024D24u, "SLES_008.65");
    uint32 count = bytes >> 2;
    if (count == 0u)
        return incoming_result;
    for (uint32 index = 0u; index < count; ++index)
    {
        w_u32(destination, value);
        destination += 4u;
    }
    return 0u;
}

uint32 ob_build_weight_tree(uint32 tree)
{
    FUNCTION_MARKER(0x80021C74u, "SLES_008.65");
    uint32 weights = tree + 4u;
    w_u32(tree + 0x2014u, 0xFFFFu);
    uint32 count = 0x101u;
    uint32 next_weight = tree + 0x1014u;
    for (;;)
    {
        uint32 first = 0x201u;
        uint32 second = 0x201u;
        for (uint32 index = 0u; (int32_t)index < (int32_t)count; ++index)
        {
            uint32 weight = r_u32(weights + (index << 4));
            if (weight == 0u)
                continue;
            if (weight < r_u32(weights + (first << 4)))
            {
                second = first;
                first = index;
            }
            else if (weight < r_u32(weights + (second << 4)))
                second = index;
        }
        if (second == 0x201u)
            break;
        uint32 first_address = weights + (first << 4);
        uint32 second_address = weights + (second << 4);
        uint32 first_weight = r_u32(first_address);
        uint32 second_weight = r_u32(second_address);
        w_u32(next_weight, first_weight + second_weight);
        first_weight = r_u32(first_address);
        w_u32(first_address, 0u);
        w_u32(first_address + 4u, first_weight);
        second_weight = r_u32(second_address);
        ++count;
        w_u32(second_address, 0u);
        w_u32(second_address + 4u, second_weight);
        w_u32(next_weight + 8u, first);
        w_u32(next_weight + 12u, second);
        next_weight += 16u;
    }
    uint32 root = count - 1u;
    uint32 root_address = weights + (root << 4);
    uint32 root_weight = r_u32(root_address);
    w_u32(root_address + 4u, root_weight);
    return root;
}
