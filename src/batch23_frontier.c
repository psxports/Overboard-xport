#include "batch23_frontier.h"
#include "batch17_frontier.h"
#include "batch19_frontier.h"
#include "batch22_frontier.h"

uint32 ob_select_player_origin(uint32 identifier)
{
    FUNCTION_MARKER(0x8001A398u, "SLES_008.65");
    uint32 players = r_u8(0x8006C230u);
    if (players == 1u)
    {
        uint32 context = r_u32(0x80077190u);
        uint32 x = r_u32(context + 16u);
        uint32 y = r_u32(context + 20u);
        uint32 z = r_u32(context + 24u);
        w_u32(0x8008C6E8u, x);
        w_u32(0x8008C6ECu, y);
        w_u32(0x8008C6F0u, z);
        w_u16(0x8008C6F8u, 0u);
        return context;
    }
    uint32 context = r_u32(0x80077190u);
    uint32 count = r_u16(context);
    if (count == 0u)
        return count;
    uint32 index = 0u;
    uint32 offset = 0u;
    do
    {
        uint32 table = r_u32(0x80077194u);
        uint32 row = table + offset;
        uint32 type = r_u32(row + 12u);
        if (type == 250u)
        {
            uint32 row_identifier = r_u16(row + 18u);
            if (row_identifier == identifier)
            {
                uint32 captured_table = r_u32(0x80077194u);
                uint32 x = r_u32(row);
                uint32 y = r_u32(row + 4u);
                uint32 z = r_u32(row + 8u);
                w_u32(0x8008C6E8u, x);
                w_u32(0x8008C6ECu, y);
                w_u32(0x8008C6F0u, z);
                uint32 heading = r_u16(captured_table + offset + 16u);
                w_u16(0x8008C6F8u, heading);
            }
        }
        context = r_u32(0x80077190u);
        count = r_u16(context);
        ++index;
        offset += 28u;
    } while (index < count);
    return 0u;
}

uint32 ob_find_collision_slot(void)
{
    FUNCTION_MARKER(0x800460B0u, "SLES_008.65");
    uint32 capacity = r_u32(0x8007713Cu);
    uint32 index = 0u;
    if ((sint32)capacity > 0)
    {
        uint32 table = r_u32(0x80077140u);
        do
        {
            if (r_u32(table) == 0u)
                break;
            ++index;
            table += 4u;
        } while ((sint32)index < (sint32)capacity);
    }
    uint32 highest = r_u32(0x80077260u);
    if ((sint32)highest < (sint32)index)
        w_u32(0x80077260u, index);
    uint32 remaining = r_u32(0x8007755Cu);
    w_u32(0x8007755Cu, remaining - 1u);
    return index;
}

uint32 ob_remove_ordered_object(uint32 object, uint32 guest_sp)
{
    FUNCTION_MARKER(0x80043AB0u, "SLES_008.65");
    ob_unlink_reference_node(object);
    uint32 result = r_u32(object + 12u);
    if (result == 0u)
        result = ob_free_reference_record(object, guest_sp - 0x18u);
    return result;
}

uint32 ob_unregister_effect_object(uint32 object, uint32 guest_sp)
{
    FUNCTION_MARKER(0x80045F20u, "SLES_008.65");
    return ob_remove_ordered_object(object, guest_sp - 0x18u);
}

uint32 ob_update_object_collision_time(uint32 object, uint32 guest_sp)
{
    FUNCTION_MARKER(0x80047A60u, "SLES_008.65");
    uint32 minimum = 0x7FFFFF01u;
    uint32 first = r_u32(object + 0xBCu);
    if ((sint32)first < (sint32)minimum)
        minimum = first;
    uint32 second = r_u32(object + 0xC4u);
    if ((sint32)second < (sint32)minimum)
        minimum = second;
    uint32 previous = r_u32(object + 0xE8u);
    if (minimum == previous)
    {
        uint32 link = r_u32(object + 0xCCu);
        if (link != 0u)
            return link;
    }
    uint32 link = r_u32(object + 0xCCu);
    if (link != 0u)
        ob_unregister_effect_object(object + 0xCCu, guest_sp - 0x20u);
    uint32 callback = r_u32(object + 0xF0u);
    w_u32(object + 0xE8u, minimum);
    if (callback == 0u)
        return callback;
    if ((sint32)minimum > (sint32)0x7FFFFF00u)
        return 1u;
    return ob_register_effect_object(object + 0xCCu);
}

uint32 ob_update_ground_collision_time(uint32 object, uint32 guest_sp)
{
    FUNCTION_MARKER(0x8004F354u, "SLES_008.65");
    uint32 first = r_u32(object + 0x9Cu);
    uint32 second = r_u32(object + 0xA0u);
    uint32 pair_minimum = first;
    if ((sint32)second < (sint32)pair_minimum)
        pair_minimum = second;
    uint32 minimum = r_u32(object + 0x98u);
    if ((sint32)pair_minimum < (sint32)minimum)
        minimum = pair_minimum;
    uint32 previous = r_u32(object + 0x80u);
    if (minimum == previous)
    {
        uint32 link = r_u32(object + 0x64u);
        if (link != 0u)
            return link;
    }
    uint32 link = r_u32(object + 0x64u);
    if (link != 0u)
        ob_unregister_effect_object(object + 0x64u, guest_sp - 0x20u);
    uint32 callback = r_u32(object + 0x88u);
    w_u32(object + 0x80u, minimum);
    if (callback == 0u)
        return callback;
    if ((sint32)minimum > (sint32)0x7FFFFF00u)
        return 1u;
    return ob_register_effect_object(object + 0x64u);
}

uint32 ob_insert_artic_reference(uint32 object, uint32 reference)
{
    FUNCTION_MARKER(0x800451E4u, "SLES_008.65");
    return ob_insert_ordered_object(object + 0x90u, reference);
}

uint32 ob_copy_advanced_position(uint32 object, uint32 time, uint32 output)
{
    FUNCTION_MARKER(0x800453C4u, "SLES_008.65");
    ob_advance_object(object, time, 0u);
    uint32 x = r_u32(object + 0x50u);
    uint32 y = r_u32(object + 0x54u);
    uint32 z = r_u32(object + 0x58u);
    w_u32(output, x);
    w_u32(output + 4u, y);
    w_u32(output + 8u, z);
    return x;
}

uint32 ob_y_angle_matrix14(uint32 angle, uint32 matrix)
{
    FUNCTION_MARKER(0x80029F58u, "SLES_008.65");
    uint32 offset = (((angle & 0xFFFFu) + 8u) >> 4) << 1;
    uint32 sine = r_u16(0x8006C304u + offset);
    uint32 cosine = r_u16(0x8006CB04u + offset);
    w_u16(matrix + 2u, 0u);
    w_u16(matrix + 6u, 0u);
    w_u16(matrix + 8u, 0x4000u);
    w_u16(matrix + 10u, 0u);
    w_u16(matrix + 14u, 0u);
    uint32 result = 0u - sine;
    w_u16(matrix, cosine);
    w_u16(matrix + 4u, result);
    w_u16(matrix + 12u, sine);
    w_u16(matrix + 16u, cosine);
    return result;
}
