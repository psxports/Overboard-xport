#include "batch19_frontier.h"

void ob_restore_heap_pointer(uint32 pointer)
{
    FUNCTION_MARKER(0x8002DA68u, "SLES_008.65");
    w_u32(0x80077354u, pointer);
}

uint32 ob_release_pool_cell(uint32 cell)
{
    FUNCTION_MARKER(0x800263B4u, "SLES_008.65");
    uint32 object = r_u32(cell);
    uint32 pool = r_u32(object - 4u);
    uint32 free_head = r_u32(pool + 8u);
    w_u32(object - 4u, free_head);
    w_u32(pool + 8u, object - 4u);
    uint32 count = r_u16(pool - 4u);
    uint32 directory = r_u32(pool + 4u);
    w_u16(pool - 4u, count - 1u);
    uint32 first = r_u32(directory + 4u);
    uint32 result = first < pool;
    if (first != 0u && result != 0u)
        w_u32(directory + 4u, pool);
    w_u32(cell, 0u);
    return result;
}

uint32 ob_unlink_reference_node(uint32 node)
{
    FUNCTION_MARKER(0x80043C94u, "SLES_008.65");
    uint32 previous = r_u32(node + 4u);
    uint32 next = r_u32(node);
    w_u32(previous, next);
    w_u32(next + 4u, previous);
    uint32 object = r_u32(node + 8u);
    w_u32(node + 4u, 0u);
    w_u32(node, 0u);
    if (object != 0u)
    {
        w_u32(object + 12u, 0u);
        w_u32(node + 8u, 0u);
    }
    uint32 result = r_u32(node + 12u) - 1u;
    w_u32(node + 12u, result);
    return result;
}

uint32 ob_detach_link_record(uint32 parent, uint32 record)
{
    FUNCTION_MARKER(0x80043D38u, "SLES_008.65");
    uint32 head = r_u32(parent + 4u);
    uint32 field = parent + 4u;
    if (head != record)
    {
        do
        {
            field = r_u32(field);
            head = r_u32(field);
        } while (head != record);
    }
    uint32 result = r_u32(record);
    w_u32(field, result);
    w_u32(record, 0u);
    w_u32(record + 4u, 0u);
    return result;
}

uint32 ob_detach_optional_link_record(uint32 record)
{
    FUNCTION_MARKER(0x80043E14u, "SLES_008.65");
    uint32 parent = r_u32(record + 4u);
    return ob_detach_link_record(parent, record);
}

uint32 ob_clear_optional_link(uint32 record)
{
    FUNCTION_MARKER(0x80043DBCu, "SLES_008.65");
    uint32 parent = r_u32(record + 4u);
    if (parent != 0u)
        return ob_detach_optional_link_record(record);
    return parent;
}

uint32 ob_reset_reference_record(uint32 record)
{
    FUNCTION_MARKER(0x80043C18u, "SLES_008.65");
    uint32 next = r_u32(record);
    if (next != 0u)
        ob_unlink_reference_node(record);
    w_u32(record + 12u, 0u);
    w_u32(record + 28u, 0u);
    w_u32(record + 32u, 0u);
    w_u32(record + 36u, 0u);
    return ob_clear_optional_link(record + 16u);
}

uint32 ob_free_reference_record(uint32 record, uint32 guest_sp)
{
    FUNCTION_MARKER(0x80043C6Cu, "SLES_008.65");
    w_u32(guest_sp, record);
    ob_reset_reference_record(record);
    return ob_release_pool_cell(guest_sp);
}

uint32 ob_clear_reference_list(uint32 list, uint32 incoming_result, uint32 guest_sp)
{
    FUNCTION_MARKER(0x80043AF4u, "SLES_008.65");
    uint32 node = r_u32(list);
    uint32 next = r_u32(node);
    uint32 result = incoming_result;
    while (next != 0u)
    {
        ob_unlink_reference_node(node);
        result = r_u32(node + 12u);
        if (result == 0u)
            result = ob_free_reference_record(node, guest_sp - 0x20u);
        node = next;
        next = r_u32(next);
    }
    return result;
}

uint32 ob_clear_owner_references(uint32 list, uint32 incoming_result, uint32 guest_sp)
{
    FUNCTION_MARKER(0x80043974u, "SLES_008.65");
    return ob_clear_reference_list(list, incoming_result, guest_sp - 0x18u);
}

static uint32 ob_detach_child_list(uint32 object)
{
    uint32 parent = r_u32(object + 0x18u);
    uint32 head = r_u32(parent + 0x20u);
    uint32 field = parent + 0x20u;
    if (head != object)
    {
        do
        {
            uint32 previous = r_u32(field);
            head = r_u32(previous + 0x1Cu);
            field = previous + 0x1Cu;
        } while (head != object);
    }
    uint32 result = r_u32(object + 0x1Cu);
    w_u32(field, result);
    w_u32(object + 0x18u, 0u);
    w_u32(object + 0x1Cu, 0u);
    return result;
}

uint32 ob_detach_owner_child(uint32 object)
{
    FUNCTION_MARKER(0x8004514Cu, "SLES_008.65");
    return ob_detach_child_list(object);
}

uint32 ob_detach_geometry_child(uint32 object)
{
    FUNCTION_MARKER(0x800440E8u, "SLES_008.65");
    return ob_detach_child_list(object);
}

uint32 ob_detach_foreign_geometry_child(uint32 object)
{
    FUNCTION_MARKER(0x800440C8u, "SLES_008.65");
    return ob_detach_geometry_child(object);
}

uint32 ob_detach_owned_record(uint32 parent, uint32 object)
{
    FUNCTION_MARKER(0x800436ECu, "SLES_008.65");
    uint32 head = r_u32(parent + 0x14u);
    uint32 field = parent + 0x14u;
    if (head != object)
    {
        do
        {
            uint32 previous = r_u32(field);
            head = r_u32(previous + 0x10u);
            field = previous + 0x10u;
        } while (head != object);
    }
    uint32 result = r_u32(object + 0x10u);
    w_u32(field, result);
    w_u32(object + 0x10u, 0u);
    w_u32(object + 0x0Cu, 0u);
    return result;
}

uint32 ob_clear_dependent_chain(uint32 object)
{
    FUNCTION_MARKER(0x80043D78u, "SLES_008.65");
    uint32 next = r_u32(object + 4u);
    uint32 field = object + 4u;
    while (next != 0u)
    {
        w_u32(field, 0u);
        field = next;
        w_u32(next + 4u, 0u);
        next = r_u32(next);
    }
    return next;
}

uint32 ob_clear_object_record(uint32 object)
{
    FUNCTION_MARKER(0x80043CF0u, "SLES_008.65");
    uint32 result = ob_clear_dependent_chain(object);
    w_u32(object, 0u);
    w_u32(object + 8u, 0u);
    return result;
}

uint32 ob_unlink_object_record(uint32 object)
{
    FUNCTION_MARKER(0x80043664u, "SLES_008.65");
    uint32 parent = r_u32(object + 12u);
    if (parent != 0u)
        ob_detach_owned_record(parent, object);
    ob_clear_object_record(object);
    return object;
}

uint32 ob_destroy_geometry_object(uint32 object, uint32 guest_sp)
{
    FUNCTION_MARKER(0x80043FD0u, "SLES_008.65");
    uint32 child = r_u32(object + 0x20u);
    while (child != 0u)
    {
        uint32 owner = r_u32(child + 12u);
        if (owner == object)
            ob_free_geometry_object(child, guest_sp - 0x18u);
        else
            ob_detach_foreign_geometry_child(child);
        child = r_u32(object + 0x20u);
    }
    uint32 parent = r_u32(object + 0x18u);
    if (parent != 0u)
        ob_detach_geometry_child(object);
    w_u32(object + 8u, 0u);
    return ob_unlink_object_record(object);
}

uint32 ob_free_geometry_object(uint32 object, uint32 guest_sp)
{
    FUNCTION_MARKER(0x80044058u, "SLES_008.65");
    w_u32(guest_sp, object);
    ob_destroy_geometry_object(object, guest_sp - 0x18u);
    return ob_release_pool_cell(guest_sp);
}
