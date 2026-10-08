#include "batch16_frontier.h"

uint32 ob_link_object(uint32 parent, uint32 child)
{
    FUNCTION_MARKER(0x800436D4u, "SLES_008.65");
    w_u32(child + 12u, parent);
    uint32 previous = r_u32(parent + 20u);
    w_u32(child + 16u, previous);
    w_u32(parent + 20u, child);
    return previous;
}

uint32 ob_init_object_list(uint32 list)
{
    FUNCTION_MARKER(0x8004395Cu, "SLES_008.65");
    uint32 result = list + 4u;
    w_u32(list, result);
    w_u32(list + 4u, 0u);
    w_u32(list + 8u, list);
    w_u32(list + 12u, 0u);
    return result;
}

void ob_resolve_shape_links(uint32 root)
{
    FUNCTION_MARKER(0x80044130u, "SLES_008.65");
    uint32 current = root;
    uint32 parent = r_u32(root + 12u);
    while (current != 0u)
    {
        uint32 identifier = r_u32(current + 48u);
        if (identifier != 0u)
            w_u32(current + 52u, ob_find_typed_object(parent, 0x8007711Cu, identifier));
        current = ob_next_shape(root, current);
    }
}

uint32 ob_find_typed_object(uint32 parent, uint32 type, uint32 identifier)
{
    FUNCTION_MARKER(0x80043824u, "SLES_008.65");
    uint32 child = r_u32(parent + 20u);
    while (child != 0u)
    {
        uint32 child_type = r_u32(child);
        if (child_type == type)
        {
            uint32 result = ob_find_object_identifier(child, identifier);
            if (result != 0u)
                return result;
        }
        child = r_u32(child + 16u);
    }
    return 0u;
}

uint32 ob_find_object_identifier(uint32 object, uint32 identifier)
{
    FUNCTION_MARKER(0x8004389Cu, "SLES_008.65");
    uint32 own_identifier = r_u32(object + 8u);
    if (own_identifier == identifier)
        return object;
    uint32 child = r_u32(object + 20u);
    while (child != 0u)
    {
        uint32 child_type = r_u32(child);
        uint32 own_type = r_u32(object);
        if (child_type == own_type)
        {
            uint32 result = ob_find_object_identifier(child, identifier);
            if (result != 0u)
                return result;
        }
        child = r_u32(child + 16u);
    }
    return 0u;
}

uint32 ob_next_shape(uint32 root, uint32 object)
{
    FUNCTION_MARKER(0x800441ACu, "SLES_008.65");
    uint32 child = r_u32(object + 20u);
    while (child != 0u)
    {
        if (r_u32(child) == 0x80077104u)
            return child;
        child = r_u32(child + 16u);
    }
    if (object == root)
        return 0u;
    do
    {
        uint32 sibling = r_u32(object + 16u);
        while (sibling != 0u)
        {
            if (r_u32(sibling) == 0x80077104u)
                return sibling;
            sibling = r_u32(sibling + 16u);
        }
        object = r_u32(object + 12u);
    } while (object != root);
    return 0u;
}

uint32 ob_find_sound_slot(void)
{
    FUNCTION_MARKER(0x80020288u, "SLES_008.65");
    for (uint32 index = 0u; index < 24u; ++index)
    {
        uint32 flags = r_u32(0x80078544u + index * 28u);
        if ((flags & 1u) == 0u)
            return index;
    }
    return 0xFFFFFFFFu;
}

uint32 ob_find_voice_slot(void)
{
    FUNCTION_MARKER(0x800202E8u, "SLES_008.65");
    for (uint32 index = 0u; index < 24u; ++index)
    {
        uint32 flags = r_u32(0x800782A0u + index * 28u);
        if ((flags & 1u) == 0u)
            return index;
    }
    for (uint32 index = 0u; index < 24u; ++index)
    {
        uint32 sound = r_u32(0x800782B4u + index * 28u);
        uint32 flags = r_u32(0x80078544u + sound * 28u);
        if ((flags & 2u) == 0u)
            return index;
    }
    return 0xFFFFFFFFu;
}
