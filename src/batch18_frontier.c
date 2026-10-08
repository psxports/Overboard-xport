#include "batch18_frontier.h"
#include "draft_signatures.h"

uint32 ob_insert_depth_node(uint32 root)
{
    FUNCTION_MARKER(0x80042368u, "SLES_008.65");
    uint32 inserted = r_u32(0x800770F0u);
    uint32 root_key = r_u32(root + 8u);
    uint32 inserted_key = r_u32(inserted + 8u);
    uint32 child_field = (int32_t)root_key < (int32_t)inserted_key ? 0x2Cu : 0x30u;
    uint32 child = r_u32(root + child_field);
    if (child != 0u)
        return ob_insert_depth_node(child);
    w_u32(root + child_field, inserted);
    return child;
}

static uint32 ob_collect_geometry_tree(uint32 node, uint32 output, uint32 stack, uint32 visibility, uint32 threshold, int callbacks)
{
    w_u32(stack, 0u);
    stack += 4u;

visit_node:
{
    uint32 first_child = r_u32(node);
    if (first_child == 0u && r_u32(node + 4u) == 0u)
    {
        uint32 count = r_u16(node + 8u);
        uint32 source = node + 10u;
        while ((count & 0xFFFFu) != 0u)
        {
            uint32 index = r_u16(source);
            source += 2u;
            w_u16(output, index);
            output += 2u;
            count -= 1u;
        }
        goto unwind;
    }
    if (callbacks)
    {
        first_child = r_u32(node);
        if (first_child == 0xFFFFFFFFu && r_u32(node + 4u) == first_child)
        {
            w_u16(output, 0xFFFFu);
            uint32 index = r_u16(node + 8u);
            output += 2u;
            w_u16(output, index);
            uint32 extra = r_u16(node + 10u);
            output += 2u;
            w_u16(output, extra);
            output += 2u;
            goto unwind;
        }
    }
    uint32 index = r_u16(node + 8u);
    uint32 visible = r_u32(visibility + (index << 2));
    if (visible != 0u)
    {
        uint32 right = r_u32(node + 4u);
        if (right != 0u)
        {
            w_u32(stack, node | 1u);
            node = r_u32(node + 4u);
            stack += 4u;
            goto visit_node;
        }
        if (index < threshold)
        {
            w_u16(output, index);
            output += 2u;
        }
        w_u32(stack, 3u);
        node = r_u32(node);
    }
    else
    {
        uint32 left = callbacks ? first_child : r_u32(node);
        if (left != 0u)
        {
            w_u32(stack, node | 2u);
            node = r_u32(node);
            stack += 4u;
            goto visit_node;
        }
        if (index < threshold)
        {
            w_u16(output, index);
            output += 2u;
        }
        w_u32(stack, 3u);
        node = r_u32(node + 4u);
    }
    stack += 4u;
    goto visit_node;
}

unwind:
    stack -= 4u;
pop_node:
    do
    {
        node = r_u32(stack);
        stack -= 4u;
    } while ((node & 3u) == 3u);
    stack += 4u;
    if (node == 0u)
        return 0u;
    uint32 tag = node & 1u;
    node &= 0xFFFFFFFCu;
    uint32 index = r_u16(node + 8u);
    if (index < threshold)
    {
        w_u16(output, index);
        output += 2u;
    }
    uint32 child_field = tag != 0u ? 0u : 4u;
    uint32 child = r_u32(node + child_field);
    stack -= 4u;
    if (child == 0u)
        goto pop_node;
    stack += 4u;
    w_u32(stack, 3u);
    node = r_u32(node + child_field);
    stack += 4u;
    goto visit_node;
}

uint32 ob_collect_geometry_indices(uint32 root, uint32 depth)
{
    FUNCTION_MARKER(0x80039E68u, "SLES_008.65");
    uint32 output = r_u32(0x80077420u);
    uint32 remaining = r_u32(0x8007759Cu);
    uint32 visibility = r_u32(0x800773A4u);
    uint32 threshold = r_u16(0x800775F0u);
    uint32 temporary = (depth << 2) < remaining ? 0u : ob_draft_scratch_acquire(800u);
    uint32 stack = temporary != 0u ? temporary : r_u32(0x80077530u);
    uint32 result = ob_collect_geometry_tree(root, output, stack, visibility, threshold, 0);
    if (temporary != 0u)
        ob_draft_scratch_release(temporary);
    return result;
}

uint32 ob_collect_geometry_callbacks(uint32 root, uint32 depth)
{
    FUNCTION_MARKER(0x80039C30u, "SLES_008.65");
    uint32 output = r_u32(0x80077420u);
    uint32 remaining = r_u32(0x8007759Cu);
    uint32 visibility = r_u32(0x800773A4u);
    uint32 threshold = r_u16(0x800775F0u);
    uint32 temporary = (depth << 2) < remaining ? 0u : ob_draft_scratch_acquire(800u);
    uint32 stack = temporary != 0u ? temporary : r_u32(0x80077530u);
    uint32 result = ob_collect_geometry_tree(root, output, stack, visibility, threshold, 1);
    if (temporary != 0u)
        ob_draft_scratch_release(temporary);
    return result;
}

uint32 ob_build_geometry_order(uint32 descriptor)
{
    FUNCTION_MARKER(0x80039BD8u, "SLES_008.65");
    uint32 output = r_u32(0x800775E4u);
    uint32 callbacks = r_u16(descriptor);
    w_u32(0x80077420u, output);
    uint32 root = r_u32(descriptor + 0x38u);
    uint32 depth = r_u32(descriptor + 0x1Cu);
    if (callbacks != 0u)
        return ob_collect_geometry_callbacks(root, depth);
    return ob_collect_geometry_indices(root, depth);
}
