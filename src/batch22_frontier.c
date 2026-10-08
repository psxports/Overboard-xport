#include "batch22_frontier.h"

uint32 ob_reset_file_setup(uint32 incoming_result)
{
    FUNCTION_MARKER(0x80054CA8u, "SLES_008.65");
    w_u32(0x800896BCu, 0u);
    w_u32(0x800896ECu, 0u);
    w_u32(0x8007FA80u, 0u);
    w_u32(0x80084A48u, 0u);
    w_u32(0x800771D8u, 0u);
    return incoming_result;
}

uint32 ob_stamp_object_records(uint32 incoming_result)
{
    FUNCTION_MARKER(0x80034530u, "SLES_008.65");
    uint32 node = r_u32(0x80077594u);
    uint32 result = incoming_result;
    if (node == 0u)
        return result;
    uint32 timestamp = r_u32(0x800882BCu);
    do
    {
        sint32 type = r_s16(node + 4u);
        result = type < 3 ? 1u : 0u;
        if (type == 0)
        {
            uint32 payload = r_u32(node + 8u);
            result = timestamp + r_u16(payload + 10u);
            w_u32(payload + 44u, result);
        }
        else if (type > 0 && type <= 3)
        {
            uint32 payload = r_u32(node + 8u);
            result = timestamp + r_u16(payload + 8u);
            w_u32(payload + 16u, result);
            if (type == 3)
            {
                payload = r_u32(node + 8u);
                result = timestamp + r_u16(payload + 32u);
                w_u32(payload + 40u, result);
            }
        }
        node = r_u32(node);
    } while (node != 0u);
    return result;
}

uint32 ob_init_optional_link(uint32 node)
{
    FUNCTION_MARKER(0x80043DACu, "SLES_008.65");
    w_u32(node + 4u, 0u);
    w_u32(node, 0u);
    return node;
}

uint32 ob_attach_link_record(uint32 head, uint32 node)
{
    FUNCTION_MARKER(0x80043D20u, "SLES_008.65");
    w_u32(node + 4u, head);
    uint32 previous = r_u32(head + 4u);
    w_u32(node, previous);
    w_u32(head + 4u, node);
    return previous;
}

uint32 ob_attach_optional_link(uint32 node, uint32 head)
{
    FUNCTION_MARKER(0x80043DECu, "SLES_008.65");
    return ob_attach_link_record(head, node);
}

uint32 ob_init_reference_record(uint32 object, uint32 head)
{
    FUNCTION_MARKER(0x80043BACu, "SLES_008.65");
    uint32 link = object + 16u;
    w_u32(object, 0u);
    w_u32(object + 4u, 0u);
    w_u32(object + 8u, 0u);
    w_u32(object + 12u, 0u);
    w_u32(object + 28u, 0u);
    w_u32(object + 24u, 0u);
    w_u32(object + 32u, 0u);
    w_u32(object + 36u, 0u);
    uint32 result = ob_init_optional_link(link);
    if (head != 0u)
        result = ob_attach_optional_link(link, head);
    return result;
}

uint32 ob_rotate_matrix_rows14(uint32 source, uint32 angle, uint32 output)
{
    FUNCTION_MARKER(0x8002AF54u, "SLES_008.65");
    uint32 offset = (((angle & 0xFFFFu) + 8u) >> 4) << 1;
    sint32 first_x = r_s16(source);
    sint32 cosine = r_s16(0x8006CB04u + offset);
    uint32 first_cosine = (uint32)((sint64)first_x * cosine);
    sint32 first_z = r_s16(source + 4u);
    sint32 sine = r_s16(0x8006C304u + offset);
    uint32 first_sine = (uint32)((sint64)first_z * sine);
    sint32 negative_sine = -sine;
    uint32 first_negative = (uint32)((sint64)first_x * negative_sine);
    uint32 first_z_cosine = (uint32)((sint64)first_z * cosine);
    sint32 second_x = r_s16(source + 6u);
    uint32 second_cosine = (uint32)((sint64)second_x * cosine);
    sint32 second_z = r_s16(source + 10u);
    uint32 second_sine = (uint32)((sint64)second_z * sine);
    uint32 second_negative = (uint32)((sint64)second_x * negative_sine);
    uint32 second_z_cosine = (uint32)((sint64)second_z * cosine);
    sint32 third_x = r_s16(source + 12u);
    uint32 third_cosine = (uint32)((sint64)third_x * cosine);
    sint32 third_z = r_s16(source + 16u);
    uint32 third_sine = (uint32)((sint64)third_z * sine);
    uint32 third_negative = (uint32)((sint64)third_x * negative_sine);
    uint32 first_output = (uint32)((sint32)(first_cosine + first_sine) >> 14);
    uint32 first_z_output = (uint32)((sint32)(first_negative + first_z_cosine) >> 14);
    uint32 second_output = (uint32)((sint32)(second_cosine + second_sine) >> 14);
    w_u16(output, first_output);
    uint32 second_z_output = (uint32)((sint32)(second_negative + second_z_cosine) >> 14);
    uint32 third_sum = third_cosine + third_sine;
    uint32 first_y = r_u16(source + 2u);
    uint32 result = (uint32)((sint64)third_z * cosine);
    w_u16(output + 4u, first_z_output);
    w_u16(output + 6u, second_output);
    w_u16(output + 2u, first_y);
    uint32 second_y = r_u16(source + 8u);
    uint32 third_output = (uint32)((sint32)third_sum >> 14);
    w_u16(output + 10u, second_z_output);
    w_u16(output + 12u, third_output);
    w_u16(output + 8u, second_y);
    uint32 third_y = r_u16(source + 14u);
    w_u16(output + 14u, third_y);
    uint32 third_z_output = (uint32)((sint32)(third_negative + result) >> 14);
    w_u16(output + 16u, third_z_output);
    return result;
}

uint32 ob_find_first_typed_child(uint32 parent, uint32 type)
{
    FUNCTION_MARKER(0x8004378Cu, "SLES_008.65");
    uint32 child = r_u32(parent + 20u);
    while (child != 0u)
    {
        uint32 child_type = r_u32(child);
        if (child_type == type)
            return child;
        child = r_u32(child + 16u);
    }
    return 0u;
}

uint32 ob_insert_ordered_object(uint32 list, uint32 object)
{
    FUNCTION_MARKER(0x800439BCu, "SLES_008.65");
    uint32 cursor = r_u32(list + 12u);
    uint32 primary = r_u32(object + 28u);
    uint32 secondary = r_u32(object + 24u);
    uint32 restart = cursor == 0u;
    if (cursor != 0u)
    {
        uint32 cached_primary = r_u32(cursor + 28u);
        restart = (sint32)primary < (sint32)cached_primary;
        w_u32(cursor + 8u, 0u);
        if (!restart && primary == cached_primary)
        {
            uint32 cached_secondary = r_u32(cursor + 24u);
            restart = (sint32)cached_secondary < (sint32)secondary;
        }
    }
    if (restart)
        cursor = r_u32(list);
    if (r_u32(cursor) != 0u)
    {
        for (;;)
        {
            uint32 cursor_primary = r_u32(cursor + 28u);
            if ((sint32)cursor_primary >= (sint32)primary)
                break;
            cursor = r_u32(cursor);
            if (r_u32(cursor) == 0u)
                break;
        }
        for (;;)
        {
            uint32 next = r_u32(cursor);
            if (next == 0u)
                break;
            uint32 cursor_primary = r_u32(cursor + 28u);
            if (primary != cursor_primary)
                break;
            uint32 cursor_secondary = r_u32(cursor + 24u);
            if ((sint32)cursor_secondary < (sint32)secondary)
                break;
            cursor = next;
        }
    }
    uint32 previous = r_u32(cursor + 4u);
    w_u32(object, cursor);
    w_u32(object + 4u, previous);
    w_u32(previous, object);
    w_u32(cursor + 4u, object);
    w_u32(list + 12u, object);
    uint32 counter = r_u32(object + 12u);
    w_u32(object + 8u, list);
    uint32 result = counter + 1u;
    w_u32(object + 12u, result);
    return result;
}

uint32 ob_register_effect_object(uint32 object)
{
    FUNCTION_MARKER(0x80045EF4u, "SLES_008.65");
    return ob_insert_ordered_object(0x800896F0u, object);
}
