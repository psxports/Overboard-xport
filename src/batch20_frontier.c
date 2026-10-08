#include "batch20_frontier.h"
#include "batch19_frontier.h"
#include "audit_frontier.h"
#include "memory_frontier.h"
#include "batch5_frontier.h"

uint32 ob_free_object_record(uint32 object, uint32 guest_sp)
{
    FUNCTION_MARKER(0x800436ACu, "SLES_008.65");
    w_u32(guest_sp, object);
    ob_unlink_object_record(object);
    return ob_release_pool_cell(guest_sp);
}

uint32 ob_swap_pool_heads(uint32 first, uint32 second)
{
    FUNCTION_MARKER(0x80026444u, "SLES_008.65");
    uint32 second_head = r_u32(second);
    uint32 first_head = r_u32(first);
    w_u32(first, second_head);
    w_u32(second, first_head);
    w_u32(first_head - 0x10u, second);
    w_u32(second_head - 0x10u, first);
    return first_head;
}

uint32 ob_unbind_pool_head(uint32 cell)
{
    FUNCTION_MARKER(0x80026278u, "SLES_008.65");
    uint32 pool = r_u32(cell);
    uint32 directory = r_u32(pool + 4u);
    uint32 first = r_u32(directory + 4u);
    if (pool == first)
        w_u32(directory + 4u, 0u);
    uint32 head = r_u32(pool);
    if (head != 0u)
        return ob_swap_pool_heads(cell, pool);
    return head;
}

uint32 ob_set_callback_for_payload(uint32 payload, uint32 callback)
{
    FUNCTION_MARKER(0x80025624u, "SLES_008.65");
    uint32 identifier = ob_memory_find_identifier(payload);
    return ob_memory_set_slot_callback(identifier & 0xFFFFu, callback);
}

uint32 ob_init_effect_callbacks(void)
{
    FUNCTION_MARKER(0x8004B6ACu, "SLES_008.65");
    ob_memory_set_word_for_payload(0x80066A04u, 0x8004B7A0u);
    ob_set_callback_for_payload(0x80066A04u, 0x8004B8ACu);
    return ob_memory_set_tail_for_payload(0x80066A04u, 0x8004B98Cu);
}

uint32 ob_effect_stub_result(uint32 incoming_result)
{
    FUNCTION_MARKER(0x800170B8u, "SLES_008.65");
    return incoming_result;
}

uint32 ob_scene_stub_result(uint32 incoming_result)
{
    FUNCTION_MARKER(0x8004F064u, "SLES_008.65");
    return incoming_result;
}
