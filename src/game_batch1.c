#include "game_batch1.h"
#include "batch12_frontier.h"

uint32 ob_update_player_heading_and_phase(void)
{
    FUNCTION_MARKER(0x800159C8u, "SLES_008.65");
    uint32 index = 0u;
    while (index < r_u8(0x8006C230u))
    {
        uint32 slot = 0x8006C138u + index * 4u;
        uint32 player = r_u32(slot);
        if (player != 0u)
        {
            uint32 selector = (uint32)r_s16(player + 0x146u);
            uint32 record = r_u32(player + 0x6Cu);
            uint32 target = r_u16(0x800CBA46u + selector * 104u);
            uint32 heading = r_u16(record + 0xAEu);
            sint32 difference = (sint32)heading - (sint32)target;
            if (difference > -512 && difference < 512)
            {
                w_u16(record + 0xAEu, target);
                player = r_u32(slot);
                if (r_u32(player + 0x120u) == 21u)
                    w_u32(player + 0x120u, 2u);
            }
            heading = r_u16(record + 0xAEu);
            if (heading < target)
                w_u16(record + 0xAEu, heading + 512u);
            else if (target < heading)
                w_u16(record + 0xAEu, heading - 512u);
        }
        ++index;
    }
    uint32 increment = (uint32)r_s16(0x8006C21Cu);
    uint32 total = r_u32(0x800771CCu) + increment;
    int64_t product = (int64_t)(sint32)total * INT64_C(0x45E7B273);
    sint32 high = (sint32)((uint64_t)product >> 32);
    uint32 quotient = (uint32)(high >> 12) - (uint32)((sint32)total >> 31);
    uint32 result = quotient * 125u;
    w_u32(0x800771CCu, total - result * 120u);
    return result;
}

uint32 ob_rotate_short_pair(uint32 first, uint32 second, uint32 angle)
{
    FUNCTION_MARKER(0x8002E8D8u, "SLES_008.65");
    uint32 table_offset = (((angle & 0xFFFFu) + 8u) >> 4) << 1;
    uint32 sine = (uint32)r_s16(0x8006CB04u + table_offset);
    uint32 x = (uint32)r_s16(first);
    uint32 cosine = (uint32)r_s16(0x8006C304u + table_offset);
    uint32 y = (uint32)r_s16(second);
    uint32 rotated_first = (sine * x + cosine * y) >> 14;
    uint32 result = (sine * y + cosine * (0u - x)) >> 14;
    w_u16(first, rotated_first);
    w_u16(second, result);
    return result;
}

uint32 ob_append_fade_quad(uint32 intensity)
{
    FUNCTION_MARKER(0x80016C20u, "SLES_008.65");
    uint32 limit = r_u32(0x800775BCu);
    uint32 packet = r_u32(0x800774A8u);
    if ((sint32)(limit - packet) < 12)
        return 1u;
    uint32 previous = r_u32(0x80077634u);
    uint32 tag = r_u32(previous);
    uint32 old_link = r_u32(previous);
    w_u32(0x800774A8u, packet + 24u);
    w_u32(0x80077634u, packet);
    w_u32(previous, (tag & 0xFF000000u) | (packet & 0x00FFFFFFu));
    w_u8(packet + 3u, 5u);
    w_u8(packet + 7u, 0x28u);
    uint32 command = r_u8(packet + 7u);
    w_u8(packet + 7u, command | 2u);
    w_u8(packet + 4u, intensity);
    w_u8(packet + 5u, intensity);
    w_u8(packet + 6u, intensity);
    uint32 current = r_u32(0x80077634u);
    w_u16(packet + 8u, 0u);
    w_u16(packet + 10u, 0u);
    w_u16(packet + 12u, 384u);
    w_u16(packet + 14u, 0u);
    w_u16(packet + 16u, 0u);
    w_u16(packet + 18u, 256u);
    w_u16(packet + 20u, 384u);
    w_u16(packet + 22u, 256u);
    uint32 result = (r_u32(current) & 0xFF000000u) | (old_link & 0x00FFFFFFu);
    w_u32(current, result);
    return result;
}

static uint32 ob_quad_texture_page(uint32 blend)
{
    uint32 graph = r_u8(0x80075BECu);
    if (graph == 1u)
        return (blend & 3u) << 7;
    graph = r_u8(0x80075BECu);
    if (graph == 2u)
        return (blend & 3u) << 7;
    return (blend & 3u) << 5;
}

static uint32 ob_quad_texture_window(uint32 rectangle)
{
    if (rectangle == 0u)
        return 0u;
    uint32 x = r_u8(rectangle) >> 3;
    uint32 width = ((0u - (uint32)r_s16(rectangle + 4u)) & 255u) >> 3;
    uint32 y = r_u8(rectangle + 2u) >> 3;
    uint32 height = ((0u - (uint32)r_s16(rectangle + 6u)) & 255u) >> 3;
    return 0xE2000000u | (x << 10) | (y << 15) | (height << 5) | width;
}

uint32 ob_append_draw_mode(uint32 blend, uint32 caller_stack)
{
    FUNCTION_MARKER(0x8002192Cu, "SLES_008.65");
    uint32 rectangle = caller_stack - 48u + 24u;
    uint32 rectangle_first = r_u32(0x800107F0u);
    uint32 rectangle_second = r_u32(0x800107F4u);
    w_u32(rectangle, rectangle_first);
    w_u32(rectangle + 4u, rectangle_second);
    uint32 limit = r_u32(0x800775BCu);
    uint32 packet = r_u32(0x800774A8u);
    if ((sint32)(limit - packet) < 12)
        return 1u;
    uint32 previous = r_u32(0x80077634u);
    uint32 old_link = r_u32(previous);
    w_u32(0x800774A8u, packet + 12u);
    uint32 texture_page = ob_quad_texture_page(blend) & 0xFFFFu;
    w_u8(packet + 3u, 2u);
    uint32 graph = r_u8(0x80075BECu);
    uint32 mode = (graph - 1u < 2u) ? ((texture_page & 0x27FFu) | 0x1000u) : ((texture_page & 0x09FFu) | 0x0400u);
    w_u32(packet + 4u, 0xE1000000u | mode);
    uint32 window = ob_quad_texture_window(rectangle);
    w_u32(packet + 8u, window);
    uint32 current = r_u32(0x80077634u);
    uint32 tag = r_u32(current);
    w_u32(0x80077634u, packet);
    w_u32(current, (tag & 0xFF000000u) | (packet & 0x00FFFFFFu));
    uint32 result = (r_u32(packet) & 0xFF000000u) | (old_link & 0x00FFFFFFu);
    w_u32(packet, result);
    return result;
}

uint32 ob_append_solid_quad(uint32 x, uint32 y, uint32 width, uint32 height, uint32 caller_stack)
{
    FUNCTION_MARKER(0x80020A70u, "SLES_008.65");
    uint32 limit = r_u32(0x800775BCu);
    uint32 packet = r_u32(0x800774A8u);
    uint32 previous = r_u32(0x80077634u);
    uint32 flags = r_u32(caller_stack + 28u);
    uint32 old_link = r_u32(previous);
    if ((sint32)(limit - packet) < 24)
        return 1u;
    w_u32(0x800774A8u, packet + 24u);
    uint32 tag = r_u32(previous);
    w_u32(0x80077634u, packet);
    w_u32(previous, (tag & 0xFF000000u) | (packet & 0x00FFFFFFu));
    ob_quad_texture_page(1u);
    w_u8(packet + 3u, 5u);
    w_u8(packet + 7u, 0x28u);
    if ((flags & 1u) != 0u)
        w_u8(packet + 7u, r_u8(packet + 7u) | 2u);
    uint32 right = x + width;
    w_u16(packet + 8u, x);
    w_u16(packet + 10u, y);
    w_u16(packet + 12u, right);
    w_u16(packet + 14u, y);
    w_u16(packet + 16u, x);
    uint32 color = r_u8(caller_stack + 16u);
    w_u8(packet + 4u, color);
    color = r_u8(caller_stack + 20u);
    w_u8(packet + 5u, color);
    color = r_u8(caller_stack + 24u);
    w_u8(packet + 6u, color);
    uint32 current = r_u32(0x80077634u);
    uint32 bottom = y + height;
    w_u16(packet + 18u, bottom);
    w_u16(packet + 20u, right);
    w_u16(packet + 22u, bottom);
    uint32 result = (r_u32(current) & 0xFF000000u) | (old_link & 0x00FFFFFFu);
    w_u32(current, result);
    return result;
}

uint32 ob_append_textured_vertices(uint32 descriptor, uint32 u, uint32 v, uint32 u_end, uint32 caller_stack)
{
    FUNCTION_MARKER(0x80020D64u, "SLES_008.65");
    uint32 local = caller_stack - 64u;
    uint32 limit = r_u32(0x800775BCu);
    uint32 initial_packet = r_u32(0x800774A8u);
    uint32 initial_head = r_u32(0x80077634u);
    uint32 old_link = r_u32(initial_head);
    w_u32(local + 16u, old_link);
    if ((sint32)(limit - initial_packet) < 40)
        return 1u;
    uint32 packed = r_u32(descriptor);
    uint32 palette_slot = ob_handle_slot_address(packed >> 17);
    packed = r_u32(descriptor);
    uint32 texture_slot = ob_handle_slot_address((packed >> 2) & 0x7FFFu);
    uint32 texture = r_u32(texture_slot);
    uint32 palette = r_u32(palette_slot);
    uint32 packet = r_u32(0x800774A8u);
    uint32 previous = r_u32(0x80077634u);
    uint32 base_u = (texture >> 4) & 0xF0u;
    uint32 base_v = (texture >> 8) & 0xF0u;
    w_u32(0x800774A8u, packet + 40u);
    uint32 tag = r_u32(previous);
    w_u32(0x80077634u, packet);
    w_u32(previous, (tag & 0xFF000000u) | (packet & 0x00FFFFFFu));
    w_u8(packet + 3u, 9u);
    w_u8(packet + 7u, 0x2Cu);
    uint32 flags = r_u32(caller_stack + 36u);
    if ((flags & 1u) != 0u)
        w_u8(packet + 7u, r_u8(packet + 7u) | 2u);
    uint32 point = r_u32(caller_stack + 20u);
    uint32 coordinate = r_u16(point);
    w_u16(packet + 8u, coordinate);
    coordinate = r_u16(point + 2u);
    w_u16(packet + 10u, coordinate);
    point = r_u32(caller_stack + 24u);
    coordinate = r_u16(point);
    w_u16(packet + 16u, coordinate);
    coordinate = r_u16(point + 2u);
    w_u16(packet + 18u, coordinate);
    point = r_u32(caller_stack + 32u);
    coordinate = r_u16(point);
    w_u16(packet + 24u, coordinate);
    coordinate = r_u16(point + 2u);
    w_u16(packet + 26u, coordinate);
    point = r_u32(caller_stack + 28u);
    coordinate = r_u16(point);
    w_u16(packet + 32u, coordinate);
    coordinate = r_u16(point + 2u);
    w_u8(packet + 4u, 128u);
    w_u8(packet + 5u, 128u);
    w_u8(packet + 6u, 128u);
    w_u16(packet + 34u, coordinate);
    uint32 left;
    uint32 right;
    uint32 top;
    uint32 bottom;
    if ((texture & 4u) == 0u)
    {
        left = base_u + u;
        top = base_v + v;
        right = base_u + u_end;
        w_u8(packet + 12u, left);
        w_u8(packet + 13u, top);
        w_u8(packet + 20u, right);
        w_u8(packet + 21u, top);
        w_u8(packet + 28u, left);
        bottom = base_v + r_u32(caller_stack + 16u);
    }
    else
    {
        left = base_u + v;
        top = base_v + u;
        w_u8(packet + 12u, left);
        w_u8(packet + 13u, top);
        right = base_u + r_u32(caller_stack + 16u);
        w_u8(packet + 21u, top);
        bottom = base_v + u_end;
        w_u8(packet + 20u, right);
        w_u8(packet + 28u, left);
    }
    w_u8(packet + 29u, bottom);
    w_u8(packet + 36u, right);
    w_u8(packet + 37u, bottom);
    uint32 current = r_u32(0x80077634u);
    w_u16(packet + 14u, palette >> 2);
    w_u16(packet + 22u, texture >> 16);
    old_link = r_u32(local + 16u);
    uint32 result = (r_u32(current) & 0xFF000000u) | (old_link & 0x00FFFFFFu);
    w_u32(current, result);
    return result;
}

static uint32 ob_texture_quad_flags(uint32 texture, uint32 flags)
{
    if ((texture & 4u) != 0u)
    {
        if ((flags & 0x38u) == 0u)
            flags |= 8u;
        else if ((flags & 8u) != 0u)
            flags ^= 0x18u;
        else if ((flags & 0x10u) != 0u)
            flags ^= 0x30u;
        else
            flags ^= 0x20u;
        flags ^= 4u;
    }
    return flags;
}

uint32 ob_append_textured_glyph(uint32 descriptor, uint32 u, uint32 v, uint32 width, uint32 caller_stack)
{
    FUNCTION_MARKER(0x80020450u, "SLES_008.65");
    uint32 limit = r_u32(0x800775BCu);
    uint32 initial_packet = r_u32(0x800774A8u);
    uint32 local = caller_stack - 104u;
    uint32 flags = r_u32(caller_stack + 28u);
    uint32 initial_head = r_u32(0x80077634u);
    w_u32(local + 16u, u);
    w_u32(local + 24u, v);
    uint32 old_link = r_u32(initial_head);
    w_u32(local + 32u, old_link);
    if ((sint32)(limit - initial_packet) < 40)
        return 1u;
    uint32 packed = r_u32(descriptor);
    uint32 palette_slot = ob_handle_slot_address(packed >> 17);
    packed = r_u32(descriptor);
    w_u32(local + 40u, palette_slot);
    uint32 texture_slot = ob_handle_slot_address((packed >> 2) & 0x7FFFu);
    uint32 texture = r_u32(texture_slot);
    palette_slot = r_u32(local + 40u);
    uint32 packet = r_u32(0x800774A8u);
    uint32 previous = r_u32(0x80077634u);
    uint32 base_u = (texture >> 4) & 0xF0u;
    uint32 base_v = (texture >> 8) & 0xF0u;
    uint32 palette = r_u32(palette_slot);
    w_u32(0x800774A8u, packet + 40u);
    w_u32(local + 40u, palette);
    uint32 tag = r_u32(previous);
    w_u32(0x80077634u, packet);
    w_u32(previous, (tag & 0xFF000000u) | (packet & 0x00FFFFFFu));
    w_u8(packet + 3u, 9u);
    w_u8(packet + 7u, 0x2Cu);
    w_u32(local + 48u, texture >> 16);
    if ((flags & 1u) != 0u)
        w_u8(packet + 7u, r_u8(packet + 7u) | 2u);
    flags = ob_texture_quad_flags(texture, flags);
    uint32 right_u;
    uint32 top_v;
    uint32 bottom_v;
    uint32 x;
    uint32 y;
    uint32 right_x;
    uint32 bottom_y;
    uint32 height;
    if ((flags & 0x38u) == 0u)
    {
        u = r_u32(local + 16u);
        v = r_u32(local + 24u);
        uint32 left_u = base_u + u;
        right_u = left_u + width;
        w_u8(local + 56u, left_u);
        top_v = base_v + v;
        height = r_u32(caller_stack + 16u);
        x = r_u16(caller_stack + 20u);
        bottom_v = top_v + height;
        w_u16(packet + 8u, x);
        y = r_u16(caller_stack + 24u);
        w_u16(packet + 10u, y);
        x = r_u32(caller_stack + 20u);
        right_x = x + width;
        w_u16(packet + 16u, right_x);
        y = r_u16(caller_stack + 24u);
        w_u16(packet + 18u, y);
        x = r_u16(caller_stack + 20u);
        w_u16(packet + 24u, x);
        y = r_u32(caller_stack + 24u);
        height = r_u32(caller_stack + 16u);
        bottom_y = y + height;
        w_u16(packet + 26u, bottom_y);
        w_u16(packet + 32u, right_x);
        w_u16(packet + 34u, bottom_y);
    }
    else if ((flags & 8u) != 0u)
    {
        v = r_u32(local + 24u);
        height = r_u32(caller_stack + 16u);
        uint32 left_u = base_u + v;
        right_u = left_u + height;
        u = r_u32(local + 16u);
        x = r_u32(caller_stack + 20u);
        w_u8(local + 56u, left_u);
        top_v = base_v + u;
        bottom_v = top_v + width;
        right_x = x + width;
        w_u16(packet + 8u, right_x);
        y = r_u16(caller_stack + 24u);
        w_u16(packet + 16u, right_x);
        w_u16(packet + 10u, y);
        y = r_u32(caller_stack + 24u);
        height = r_u32(caller_stack + 16u);
        bottom_y = y + height;
        w_u16(packet + 18u, bottom_y);
        x = r_u16(caller_stack + 20u);
        w_u16(packet + 24u, x);
        y = r_u16(caller_stack + 24u);
        w_u16(packet + 32u, x);
        w_u16(packet + 34u, bottom_y);
        w_u16(packet + 26u, y);
    }
    else if ((flags & 0x10u) != 0u)
    {
        u = r_u32(local + 16u);
        v = r_u32(local + 24u);
        uint32 left_u = base_u + u;
        right_u = left_u + width;
        w_u8(local + 56u, left_u);
        top_v = base_v + v;
        x = r_u32(caller_stack + 20u);
        height = r_u32(caller_stack + 16u);
        right_x = x + width;
        w_u16(packet + 8u, right_x);
        y = r_u32(caller_stack + 24u);
        bottom_v = top_v + height;
        bottom_y = y + height;
        w_u16(packet + 10u, bottom_y);
        x = r_u16(caller_stack + 20u);
        w_u16(packet + 18u, bottom_y);
        w_u16(packet + 24u, right_x);
        w_u16(packet + 16u, x);
        y = r_u16(caller_stack + 24u);
        w_u16(packet + 32u, x);
        w_u16(packet + 26u, y);
        w_u16(packet + 34u, y);
    }
    else
    {
        v = r_u32(local + 24u);
        height = r_u32(caller_stack + 16u);
        uint32 left_u = base_u + v;
        right_u = left_u + height;
        u = r_u32(local + 16u);
        x = r_u16(caller_stack + 20u);
        w_u8(local + 56u, left_u);
        top_v = base_v + u;
        w_u16(packet + 8u, x);
        y = r_u32(caller_stack + 24u);
        height = r_u32(caller_stack + 16u);
        bottom_y = y + height;
        w_u16(packet + 10u, bottom_y);
        x = r_u16(caller_stack + 20u);
        w_u16(packet + 16u, x);
        y = r_u16(caller_stack + 24u);
        w_u16(packet + 18u, y);
        x = r_u32(caller_stack + 20u);
        bottom_v = top_v + width;
        right_x = x + width;
        w_u16(packet + 24u, right_x);
        w_u16(packet + 26u, bottom_y);
        w_u16(packet + 32u, right_x);
        w_u16(packet + 34u, y);
    }
    w_u8(packet + 4u, 128u);
    w_u8(packet + 5u, 128u);
    w_u8(packet + 6u, 128u);
    if ((flags & 2u) != 0u)
    {
        uint32 left_u = r_u8(local + 56u);
        w_u8(local + 56u, right_u);
        right_u = left_u;
    }
    if ((flags & 4u) != 0u)
    {
        uint32 swap = top_v;
        top_v = bottom_v;
        bottom_v = swap;
    }
    uint32 left_u = r_u8(local + 56u);
    w_u8(packet + 13u, top_v);
    w_u8(packet + 20u, right_u);
    w_u8(packet + 21u, top_v);
    w_u8(packet + 12u, left_u);
    w_u8(packet + 28u, left_u);
    w_u8(packet + 29u, bottom_v);
    w_u8(packet + 36u, right_u);
    w_u8(packet + 37u, bottom_v);
    palette = r_u32(local + 40u);
    uint32 current = r_u32(0x80077634u);
    w_u16(packet + 14u, palette >> 2);
    uint32 page = r_u16(local + 48u);
    w_u16(packet + 22u, page);
    tag = r_u32(current);
    old_link = r_u32(local + 32u);
    uint32 result = (tag & 0xFF000000u) | (old_link & 0x00FFFFFFu);
    w_u32(current, result);
    return result;
}

uint32 ob_append_text_glyphs(uint32 string, uint32 x, uint32 y, uint32 caller_stack, uint32 incoming_result)
{
    FUNCTION_MARKER(0x80013908u, "SLES_008.65");
    uint32 character = r_u8(string);
    if (character == 0u)
        return incoming_result;
    uint32 local = caller_stack - 64u;
    for (;;)
    {
        if (((character - 97u) & 255u) < 26u)
            character -= 32u;
        character &= 255u;
        if (character == 32u)
            x += 9u;
        else if (r_u8(0x80065D4Cu) != 0u)
        {
            uint32 index = 0u;
            uint32 table = 0x80065D4Cu;
            uint32 entry = r_u8(table);
            uint32 column = 0u;
            uint32 row = 0u;
            for (;;)
            {
                ++table;
                if (entry == character)
                {
                    int64_t product = (int64_t)(sint32)index * (int64_t)(sint32)0x92492493u;
                    uint32 high = (uint32)((uint64_t)product >> 32);
                    uint32 quotient = (uint32)((sint32)(high + index) >> 2) - (uint32)((sint32)index >> 31);
                    column = (index - quotient * 7u) * 9u;
                    row = quotient * 9u;
                    break;
                }
                entry = r_u8(table);
                ++index;
                if (entry == 0u)
                    break;
            }
            if (r_u8(0x80065D4Cu + index) != 0u)
            {
                w_u32(local + 16u, 8u);
                w_u32(local + 20u, x);
                w_u32(local + 24u, y);
                w_u32(local + 28u, 0u);
                ob_append_textured_glyph(0x8006664Cu, column + 1u, row + 1u, 8u, local);
                x += 9u;
            }
        }
        ++string;
        character = r_u8(string);
        if (character == 0u)
            return 0xFFFFFF9Fu;
    }
}

uint32 ob_append_textured_rectangle(uint32 descriptor, uint32 u, uint32 v, uint32 width, uint32 caller_stack)
{
    FUNCTION_MARKER(0x80020FD4u, "SLES_008.65");
    uint32 limit = r_u32(0x800775BCu);
    uint32 initial_packet = r_u32(0x800774A8u);
    uint32 local = caller_stack - 104u;
    uint32 flags = r_u32(caller_stack + 36u);
    uint32 initial_head = r_u32(0x80077634u);
    w_u32(local + 16u, u);
    w_u32(local + 24u, v);
    w_u32(local + 32u, width);
    uint32 old_link = r_u32(initial_head);
    w_u32(local + 40u, old_link);
    if ((sint32)(limit - initial_packet) < 40)
        return 1u;
    uint32 packed = r_u32(descriptor);
    uint32 palette_slot = ob_handle_slot_address(packed >> 17);
    packed = r_u32(descriptor);
    w_u32(local + 48u, palette_slot);
    uint32 texture_slot = ob_handle_slot_address((packed >> 2) & 0x7FFFu);
    uint32 texture = r_u32(texture_slot);
    palette_slot = r_u32(local + 48u);
    uint32 packet = r_u32(0x800774A8u);
    uint32 previous = r_u32(0x80077634u);
    uint32 base_u = (texture >> 4) & 0xF0u;
    uint32 base_v = (texture >> 8) & 0xF0u;
    uint32 palette = r_u32(palette_slot);
    w_u32(0x800774A8u, packet + 40u);
    w_u32(local + 48u, palette);
    uint32 tag = r_u32(previous);
    w_u32(0x80077634u, packet);
    w_u32(previous, (tag & 0xFF000000u) | (packet & 0x00FFFFFFu));
    w_u8(packet + 3u, 9u);
    w_u8(packet + 7u, 0x2Cu);
    w_u32(local + 56u, texture >> 16);
    if ((flags & 1u) != 0u)
        w_u8(packet + 7u, r_u8(packet + 7u) | 2u);
    flags = ob_texture_quad_flags(texture, flags);
    uint32 left_u;
    uint32 right_u;
    uint32 top_v;
    uint32 bottom_v;
    uint32 x;
    uint32 y;
    uint32 right_x;
    uint32 bottom_y;
    uint32 height;
    if ((flags & 0x38u) == 0u)
    {
        u = r_u32(local + 16u);
        width = r_u32(local + 32u);
        left_u = base_u + u;
        right_u = left_u + width;
        v = r_u32(local + 24u);
        height = r_u32(caller_stack + 16u);
        top_v = base_v + v;
        bottom_v = top_v + height;
        x = r_u16(caller_stack + 20u);
        w_u16(packet + 8u, x);
        y = r_u16(caller_stack + 24u);
        w_u16(packet + 10u, y);
        x = r_u32(caller_stack + 20u);
        width = r_u32(caller_stack + 28u);
        right_x = x + width;
        w_u16(packet + 16u, right_x);
        y = r_u16(caller_stack + 24u);
        w_u16(packet + 18u, y);
        x = r_u16(caller_stack + 20u);
        w_u16(packet + 24u, x);
        y = r_u32(caller_stack + 24u);
        height = r_u32(caller_stack + 32u);
        bottom_y = y + height;
        w_u16(packet + 26u, bottom_y);
        w_u16(packet + 32u, right_x);
        w_u16(packet + 34u, bottom_y);
    }
    else if ((flags & 8u) != 0u)
    {
        v = r_u32(local + 24u);
        height = r_u32(caller_stack + 16u);
        left_u = base_u + v;
        right_u = left_u + height;
        u = r_u32(local + 16u);
        width = r_u32(local + 32u);
        top_v = base_v + u;
        bottom_v = top_v + width;
        x = r_u32(caller_stack + 20u);
        width = r_u32(caller_stack + 28u);
        right_x = x + width;
        w_u16(packet + 8u, right_x);
        y = r_u16(caller_stack + 24u);
        w_u16(packet + 16u, right_x);
        w_u16(packet + 10u, y);
        y = r_u32(caller_stack + 24u);
        height = r_u32(caller_stack + 32u);
        bottom_y = y + height;
        w_u16(packet + 18u, bottom_y);
        x = r_u16(caller_stack + 20u);
        w_u16(packet + 24u, x);
        y = r_u16(caller_stack + 24u);
        w_u16(packet + 32u, x);
        w_u16(packet + 34u, bottom_y);
        w_u16(packet + 26u, y);
    }
    else if ((flags & 0x10u) != 0u)
    {
        u = r_u32(local + 16u);
        width = r_u32(local + 32u);
        left_u = base_u + u;
        right_u = left_u + width;
        v = r_u32(local + 24u);
        height = r_u32(caller_stack + 16u);
        top_v = base_v + v;
        bottom_v = top_v + height;
        x = r_u32(caller_stack + 20u);
        width = r_u32(caller_stack + 28u);
        right_x = x + width;
        w_u16(packet + 8u, right_x);
        y = r_u32(caller_stack + 24u);
        height = r_u32(caller_stack + 32u);
        bottom_y = y + height;
        w_u16(packet + 10u, bottom_y);
        x = r_u16(caller_stack + 20u);
        w_u16(packet + 18u, bottom_y);
        w_u16(packet + 24u, right_x);
        w_u16(packet + 16u, x);
        y = r_u16(caller_stack + 24u);
        w_u16(packet + 32u, x);
        w_u16(packet + 26u, y);
        w_u16(packet + 34u, y);
    }
    else
    {
        v = r_u32(local + 24u);
        height = r_u32(caller_stack + 16u);
        left_u = base_u + v;
        right_u = left_u + height;
        u = r_u32(local + 16u);
        width = r_u32(local + 32u);
        top_v = base_v + u;
        bottom_v = top_v + width;
        x = r_u16(caller_stack + 20u);
        w_u16(packet + 8u, x);
        y = r_u32(caller_stack + 24u);
        height = r_u32(caller_stack + 32u);
        bottom_y = y + height;
        w_u16(packet + 10u, bottom_y);
        x = r_u16(caller_stack + 20u);
        w_u16(packet + 16u, x);
        y = r_u16(caller_stack + 24u);
        w_u16(packet + 18u, y);
        x = r_u32(caller_stack + 20u);
        width = r_u32(caller_stack + 28u);
        right_x = x + width;
        w_u16(packet + 24u, right_x);
        w_u16(packet + 26u, bottom_y);
        w_u16(packet + 32u, right_x);
        w_u16(packet + 34u, y);
    }
    w_u8(packet + 4u, 128u);
    w_u8(packet + 5u, 128u);
    w_u8(packet + 6u, 128u);
    if ((flags & 2u) != 0u)
    {
        uint32 swap = left_u;
        left_u = right_u;
        right_u = swap;
    }
    if ((flags & 4u) != 0u)
    {
        uint32 swap = top_v;
        top_v = bottom_v;
        bottom_v = swap;
    }
    w_u8(packet + 12u, left_u);
    w_u8(packet + 13u, top_v);
    w_u8(packet + 20u, right_u);
    w_u8(packet + 21u, top_v);
    w_u8(packet + 28u, left_u);
    w_u8(packet + 29u, bottom_v);
    w_u8(packet + 36u, right_u);
    w_u8(packet + 37u, bottom_v);
    palette = r_u32(local + 48u);
    uint32 current = r_u32(0x80077634u);
    w_u16(packet + 14u, palette >> 2);
    uint32 page = r_u16(local + 56u);
    w_u16(packet + 22u, page);
    tag = r_u32(current);
    old_link = r_u32(local + 40u);
    uint32 result = (tag & 0xFF000000u) | (old_link & 0x00FFFFFFu);
    w_u32(current, result);
    return result;
}

uint32 ob_append_colored_texture_quad(uint32 descriptor, uint32 u, uint32 v, uint32 width, uint32 caller_stack)
{
    FUNCTION_MARKER(0x80020864u, "SLES_008.65");
    uint32 limit = r_u32(0x800775BCu);
    uint32 initial_packet = r_u32(0x800774A8u);
    uint32 local = caller_stack - 80u;
    uint32 x = r_u32(caller_stack + 20u);
    uint32 y = r_u32(caller_stack + 24u);
    uint32 initial_head = r_u32(0x80077634u);
    w_u32(local + 16u, u);
    w_u32(local + 24u, v);
    uint32 old_link = r_u32(initial_head);
    w_u32(local + 32u, old_link);
    if ((sint32)(limit - initial_packet) < 40)
        return 1u;
    uint32 packed = r_u32(descriptor);
    uint32 palette_slot = ob_handle_slot_address(packed >> 17);
    packed = r_u32(descriptor);
    uint32 texture_slot = ob_handle_slot_address((packed >> 2) & 0x7FFFu);
    uint32 texture = r_u32(texture_slot);
    uint32 palette = r_u32(palette_slot);
    uint32 packet = r_u32(0x800774A8u);
    uint32 previous = r_u32(0x80077634u);
    uint32 base_u = (texture >> 4) & 0xF0u;
    uint32 base_v = texture >> 8;
    w_u32(0x800774A8u, packet + 40u);
    uint32 tag = r_u32(previous);
    uint32 page = texture >> 16;
    w_u32(0x80077634u, packet);
    w_u32(previous, (tag & 0xFF000000u) | (packet & 0x00FFFFFFu));
    w_u8(packet + 3u, 9u);
    w_u8(packet + 7u, 0x2Cu);
    uint32 flags = r_u32(caller_stack + 28u);
    base_v &= 0xF0u;
    if ((flags & 1u) != 0u)
        w_u8(packet + 7u, r_u8(packet + 7u) | 2u);
    u = r_u32(local + 16u);
    uint32 left_u = base_u + u;
    v = r_u32(local + 24u);
    uint32 right_x = x + width;
    uint32 top_v = base_v + v;
    uint32 height = r_u32(caller_stack + 16u);
    uint32 right_u = left_u + width;
    uint32 bottom_v = top_v + height;
    uint32 color = r_u8(caller_stack + 32u);
    w_u8(packet + 4u, color);
    color = r_u8(caller_stack + 36u);
    w_u8(packet + 5u, color);
    color = r_u8(caller_stack + 40u);
    w_u16(packet + 8u, x);
    w_u16(packet + 10u, y);
    w_u16(packet + 16u, right_x);
    w_u16(packet + 18u, y);
    w_u16(packet + 24u, x);
    w_u8(packet + 6u, color);
    height = r_u32(caller_stack + 16u);
    uint32 bottom_y = y + height;
    w_u16(packet + 26u, bottom_y);
    w_u16(packet + 32u, right_x);
    w_u16(packet + 34u, bottom_y);
    w_u8(packet + 12u, left_u);
    w_u8(packet + 13u, top_v);
    w_u8(packet + 20u, right_u);
    w_u8(packet + 21u, top_v);
    w_u8(packet + 28u, left_u);
    w_u8(packet + 29u, bottom_v);
    w_u8(packet + 36u, right_u);
    w_u8(packet + 37u, bottom_v);
    uint32 current = r_u32(0x80077634u);
    w_u16(packet + 14u, palette >> 2);
    w_u16(packet + 22u, page);
    tag = r_u32(current) & 0xFF000000u;
    old_link = r_u32(local + 32u);
    uint32 result = tag | (old_link & 0x00FFFFFFu);
    w_u32(current, result);
    return result;
}

uint32 ob_append_colored_texture_scaled(uint32 descriptor, uint32 u, uint32 v, uint32 width, uint32 caller_stack)
{
    FUNCTION_MARKER(0x8002140Cu, "SLES_008.65");
    uint32 local = caller_stack - 56u;
    uint32 height = r_u32(caller_stack + 16u);
    uint32 x = r_u32(caller_stack + 20u);
    uint32 y = r_u32(caller_stack + 24u);
    uint32 flags = r_u32(caller_stack + 36u);
    uint32 red = r_u32(caller_stack + 40u);
    uint32 green = r_u32(caller_stack + 44u);
    uint32 blue = r_u32(caller_stack + 48u);
    w_u32(local + 16u, height);
    w_u32(local + 20u, x);
    w_u32(local + 24u, y);
    w_u32(local + 28u, flags);
    w_u32(local + 32u, red);
    w_u32(local + 36u, green);
    w_u32(local + 40u, blue);
    return ob_append_colored_texture_quad(descriptor, u, v, width, local);
}

uint32 ob_classify_matrix_direction(uint32 matrix)
{
    FUNCTION_MARKER(0x8004A564u, "SLES_008.65");
    uint32 x = (uint32)r_s16(matrix + 12u);
    uint32 y = (uint32)r_s16(matrix + 16u);
    uint32 result = 0u;
    if ((sint32)x < (sint32)(0u - y))
    {
        result = 2u;
        x = 0u - x;
        y = 0u - y;
    }
    if ((sint16)y < (sint16)x)
        result |= 1u;
    return result;
}

uint32 ob_build_three_axis_codes(uint32 primary, uint32 secondary, uint32 table, uint32 position, uint32 limit)
{
    FUNCTION_MARKER(0x8004CF28u, "SLES_008.65");
    uint32 phase = ((uint32)((sint32)position >> 2)) & 3u;
    uint32 coarse = (uint32)((sint32)position >> 4);
    uint32 fine = position & 3u;
    uint32 end = table + 3u;
    do
    {
        sint32 entry = r_s8(table);
        if (entry != -128)
        {
            uint32 coordinate = coarse + (uint32)entry;
            uint32 override = r_u32(0x80077320u);
            if (override != 0u || ((sint32)coordinate < (sint32)limit && (sint32)coordinate >= 0))
            {
                w_u8(primary, coordinate);
                entry = r_s8(table);
                ++primary;
                if (entry == -1 || entry == 1)
                {
                    uint32 code = entry == -1 ? 3u : 0u;
                    w_u8(primary, code);
                    ++primary;
                    w_u8(secondary, code);
                    ++secondary;
                    w_u8(secondary, code);
                    ++secondary;
                    w_u8(secondary, code);
                    ++secondary;
                    w_u8(secondary, code);
                    ++secondary;
                }
                else if (entry == 0)
                {
                    w_u8(primary, phase);
                    ++primary;
                    w_u8(secondary, fine);
                    ++secondary;
                    w_u8(secondary, (phase & 1u) != 0u ? 3u : 0u);
                    ++secondary;
                    w_u8(secondary, phase >= 2u ? 3u : 0u);
                    ++secondary;
                    w_u8(secondary, phase >= 2u ? 3u : 0u);
                    ++secondary;
                }
            }
        }
        ++table;
    } while ((sint32)table < (sint32)end);
    w_u8(primary, 0xFFu);
    return 0xFFFFFFFFu;
}

uint32 ob_append_three_digit_indicator(uint32 value, uint32 x, uint32 y, uint32 caller_stack)
{
    FUNCTION_MARKER(0x80013C00u, "SLES_008.65");
    uint32 local = caller_stack - 96u;
    uint32 colored = (sint32)value < 6;
    uint32 count = 0u;
    do
    {
        sint64 product = (sint64)(sint32)value * INT64_C(0x66666667);
        sint32 high = (sint32)((uint64)product >> 32);
        uint32 quotient = (uint32)(high >> 2) - (uint32)((sint32)value >> 31);
        uint32 digit = value - quotient * 10u;
        uint32 row = 0u;
        if ((sint32)digit >= 6)
        {
            digit -= 6u;
            row = 6u;
        }
        uint32 u = digit * 5u;
        uint32 scale = r_u32(0x8006C174u);
        uint32 geometry_width = scale * 5u;
        uint32 geometry_height = scale * 6u;
        w_u32(local + 16u, 6u);
        w_u32(local + 20u, x);
        w_u32(local + 24u, y);
        w_u32(local + 36u, 0u);
        if (colored != 0u)
        {
            w_u32(local + 40u, 224u);
            w_u32(local + 44u, 64u);
            w_u32(local + 48u, 64u);
            w_u32(local + 28u, geometry_width);
            w_u32(local + 32u, geometry_height);
            ob_append_colored_texture_scaled(0x80066650u, u, row, 5u, local);
        }
        else
        {
            w_u32(local + 28u, geometry_width);
            w_u32(local + 32u, geometry_height);
            ob_append_textured_rectangle(0x80066650u, u, row, 5u, local);
        }
        scale = r_u32(0x8006C174u);
        ++count;
        x -= scale * 5u;
        value = quotient;
    } while (count < 3u);
    return 0u;
}

uint32 ob_build_view_axis_codes(uint32 caller_stack)
{
    FUNCTION_MARKER(0x8004D0F8u, "SLES_008.65");
    sint32 height = r_s16(0x800C4CF0u);
    uint32 local = caller_stack - 32u;
    uint32 row = r_u8(0x80077425u);
    if (height >= 0x2C01)
        row += 2u;
    uint32 graph = r_u8(0x80077654u);
    uint32 table = 0x800736ECu + graph * 3u;
    uint32 dimensions = r_u32(0x80077644u);
    uint32 column = r_u8(0x80077424u);
    uint32 limit = (uint32)r_s16(dimensions + 4u);
    w_u32(local + 16u, limit);
    ob_build_three_axis_codes(0x80077430u, 0x80084AA8u, table, column, limit);
    graph = r_u8(0x80077654u);
    dimensions = r_u32(0x80077644u);
    limit = (uint32)r_s16(dimensions + 6u);
    table = 0x800736F8u + graph * 3u;
    w_u32(local + 16u, limit);
    return ob_build_three_axis_codes(0x80077438u, 0x80084AB8u, table, row, limit);
}

static uint32 ob_hud_round_product(uint32 coefficient, uint32 factor, uint32 scale)
{
    uint32 product = coefficient * factor * scale;
    if ((sint32)product < 0)
        product += 0x7FFFu;
    return (uint32)((sint32)product >> 15);
}

uint32 ob_append_player_hud(uint32 player_index, uint32 caller_stack)
{
    FUNCTION_MARKER(0x80014BF8u, "SLES_008.65");
    uint32 local = caller_stack - 176u;
    uint32 player_slot = 0x8006C138u + (uint32)((sint32)(player_index << 16) >> 14);
    uint32 player = r_u32(player_slot);
    if (player == 0u)
        return 0u;
    uint32 record = r_u32(player + 108u);
    uint32 scale = r_u32(0x8006C174u);
    w_u32(local + 16u, 31u);
    w_u32(local + 20u, 12u);
    w_u32(local + 24u, 20u);
    w_u32(local + 36u, 0u);
    w_u32(local + 28u, scale * 63u);
    w_u32(local + 32u, scale * 31u);
    ob_append_textured_rectangle(0x800666A8u, 0u, 0u, 63u, local);
    scale = r_u32(0x8006C174u);
    w_u32(local + 16u, 31u);
    w_u32(local + 20u, 12u);
    w_u32(local + 36u, 0u);
    w_u32(local + 24u, 20u + scale * 31u);
    w_u32(local + 28u, scale * 63u);
    w_u32(local + 32u, scale * 31u);
    ob_append_textured_rectangle(0x800666ACu, 0u, 0u, 63u, local);
    player = r_u32(player_slot);
    uint32 selection = r_u32(player + 120u);
    uint32 selected = (uint32)r_s8(selection + 135u);
    uint32 i = 0u;
    do
    {
        uint32 indicator = record + i;
        if (r_s8(indicator + 106u) != 0)
        {
            uint32 selector = (uint32)r_s8(0x800C5EEDu + i * 4u);
            uint32 level = (uint32)r_s8(indicator + 130u);
            uint32 current = (uint32)r_s16(record + selector * 2u + 120u);
            uint32 threshold = (uint32)r_s16(0x800C5B64u + level * 14u + i * 70u);
            uint32 difference = current - threshold;
            uint32 flags = 0u;
            uint32 color = 128u;
            if ((sint32)difference < 0)
            {
                flags = 1u;
                color = 0u;
            }
            sint32 flash = r_s8(indicator + 143u);
            if (flash > 0)
            {
                color += (uint32)flash;
                w_u8(indicator + 143u, (uint32)flash - 10u);
            }
            w_u32(local + 16u, 15u);
            uint32 offset_x = (uint32)r_s8(0x800C5EEEu + i * 4u);
            scale = r_u32(0x8006C174u);
            w_u32(local + 20u, 12u + (offset_x - 17u) * scale);
            uint32 offset_y = (uint32)r_s8(0x800C5EEFu + i * 4u);
            w_u32(local + 36u, flags);
            w_u32(local + 40u, color);
            w_u32(local + 44u, color);
            w_u32(local + 48u, color);
            w_u32(local + 28u, scale * 15u);
            w_u32(local + 32u, scale * 15u);
            w_u32(local + 24u, 20u + (offset_y - 16u) * scale);
            uint32 descriptor = r_u32(0x80065CC4u + i * 4u);
            ob_append_colored_texture_scaled(descriptor, 0u, 0u, 15u, local);
        }
        ++i;
    } while (i < 8u);
    scale = r_u32(0x8006C174u);
    uint32 selected_axis = (uint32)r_s8(0x800C5EEDu + selected * 4u);
    uint32 number = (uint32)r_s16(record + selected_axis * 2u + 120u);
    ob_append_three_digit_indicator(number, 12u + scale * 33u, 20u + scale * 27u, local);
    uint32 angle = (uint32)r_s16(record + 152u);
    uint32 wide = ((angle + 0x2200u) & 0x3C00u) == 0u;
    uint32 primary_angle = wide != 0u ? 0x2000u - angle : 0xFFFFFFF0u - angle;
    uint32 primary_offset = (((primary_angle & 0xFFFFu) + 8u) >> 4) * 2u;
    uint32 coefficient_x = (uint32)r_s16(0x8006CB04u + primary_offset);
    scale = r_u32(0x8006C174u);
    uint32 secondary_offset = ((((angle - 0x3C00u) & 0xFFFFu) + 8u) >> 4) * 2u;
    uint32 secondary_x = r_u16(0x8006CB04u + secondary_offset);
    uint32 secondary_y = r_u16(0x8006C304u + secondary_offset);
    uint32 primary_x = ob_hud_round_product(coefficient_x, wide != 0u ? 29u : 25u, scale);
    uint32 coefficient_y = (uint32)r_s16(0x8006C304u + primary_offset);
    uint32 primary_y = ob_hud_round_product(coefficient_y, wide != 0u ? 29u : 25u, scale);
    uint32 factor = wide != 0u ? 48u : 39u;
    uint32 extension_x = ob_hud_round_product((uint32)(sint16)secondary_x, factor, scale);
    uint32 extension_y = ob_hud_round_product((uint32)(sint16)secondary_y, factor, scale);
    w_u16(local + 56u, 12u + scale * 31u - primary_x - primary_y + extension_x);
    w_u16(local + 58u, 20u + scale * 30u + primary_y - primary_x + extension_y);
    uint32 doubled_x = (uint32)((sint32)(primary_x << 16) >> 15);
    uint32 doubled_y = (uint32)((sint32)(primary_y << 16) >> 15);
    uint32 vertex_x = r_u16(local + 56u);
    uint32 vertex_y = r_u16(local + 58u);
    w_u16(local + 64u, vertex_x + doubled_x);
    w_u16(local + 66u, vertex_y - doubled_y);
    w_u16(local + 72u, vertex_x + doubled_y);
    w_u16(local + 74u, vertex_y + doubled_x);
    w_u16(local + 80u, vertex_x + doubled_x + doubled_y);
    w_u16(local + 82u, vertex_y - doubled_y + doubled_x);
    angle = (uint32)r_s16(record + 152u);
    wide = ((angle + 0x2200u) & 0x3C00u) == 0u;
    uint32 descriptor = wide != 0u ? 0x800666B8u : 0x800666BCu;
    uint32 size = wide != 0u ? 28u : 24u;
    w_u32(local + 16u, size);
    w_u32(local + 20u, local + 56u);
    w_u32(local + 24u, local + 64u);
    w_u32(local + 28u, local + 80u);
    w_u32(local + 32u, local + 72u);
    w_u32(local + 36u, 0u);
    ob_append_textured_vertices(descriptor, 0u, 0u, size, local);
    angle = (uint32)r_s16(record + 152u);
    uint32 target = (uint32)r_s16(record + 154u);
    uint32 difference = angle - target;
    if (difference != 0u || r_s16(record + 156u) != 0)
    {
        if ((sint32)difference > 32767)
            difference += 0xFFFF0000u;
        else if (difference + 0x8000u > 0x8000u && (sint32)difference < -32767)
            difference += 0x10000u;
        uint32 half = (uint32)((sint32)(difference + (difference >> 31)) >> 1);
        uint32 acceleration = (uint32)r_s16(record + 156u);
        if ((sint32)difference >= 0)
            acceleration = (sint32)acceleration < (sint32)half ? acceleration + 1024u : half + 32u;
        else
            acceleration = (sint32)half < (sint32)acceleration ? acceleration - 1024u : half - 32u;
        w_u16(record + 156u, acceleration);
        angle = r_u16(record + 152u);
        acceleration = r_u16(record + 156u);
        w_u16(record + 152u, angle - acceleration);
        uint32 absolute = (sint32)difference < 0 ? 0u - difference : difference;
        if ((sint32)absolute < 128)
        {
            target = r_u16(record + 154u);
            w_u16(record + 156u, 0u);
            w_u16(record + 152u, target);
        }
    }
    uint32 selected_level = (uint32)r_s8(record + 177u);
    sint32 count = r_s8(record + selected_level + 130u);
    if (count < 0)
        return (uint32)count;
    i = 0u;
    do
    {
        uint32 offset_x = (uint32)r_s16(0x80065DB4u + i * 2u);
        scale = r_u32(0x8006C174u);
        uint32 offset_y = (uint32)r_s16(0x80065DC0u + i * 2u);
        uint32 x = 12u + (offset_x - 17u) * scale;
        uint32 y = 20u + (offset_y - 16u) * scale;
        w_u32(local + 28u, 0u);
        w_u32(local + 16u, 255u);
        w_u32(local + 20u, 255u);
        w_u32(local + 24u, 32u);
        ob_append_solid_quad(x, y, scale * 2u, scale * 2u, local);
        selected_level = (uint32)r_s8(record + 177u);
        count = r_s8(record + selected_level + 130u);
        ++i;
    } while ((sint32)i <= count);
    return 1u;
}

uint32 ob_border_cell_blocked(uint32 packed, uint32 position, uint32 radius, uint32 caller_stack)
{
    FUNCTION_MARKER(0x8004B0B0u, "SLES_008.65");
    /* Map 8004B0B0..8004B0CC */
    uint32 shifted = (uint32)((sint32)packed >> 16);
    uint32 local = caller_stack - 32u;
    w_u32(caller_stack, shifted);
    /* Map 8004B0CC..8004B108 */
    uint32 first = r_u8(caller_stack);
    uint32 dimensions = r_u32(0x80077644u);
    uint32 second = r_u8(caller_stack + 1u);
    uint32 cell = ob_border_cell_address((first | (second << 8)) << 16, dimensions, local);
    /* Map 8004B108..8004B12C */
    uint32 kind = r_u8(cell);
    dimensions = r_u32(0x80077644u);
    uint32 records = r_u32(dimensions + 24u);
    uint32 cell_height = r_u16(cell + 2u);
    uint32 record = records + kind * 24u;
    /* Map 8004B12C..8004B154 */
    uint32 base_height = (uint32)((sint32)((cell_height & 0xFFFCu) << 16) >> 14);
    uint32 cap = (uint32)r_s8(record + 23u);
    uint32 y = r_u32(position + 4u);
    uint32 ceiling = base_height + (cap << 6);
    uint32 orientation = 0u;
    if ((sint32)(y - ceiling) >= 0)
        return 0u;
    /* Map 8004B154..8004B1B0 */
    first = r_u8(caller_stack);
    uint32 extent = r_u32(dimensions);
    uint32 horizontal_product = first * extent;
    second = r_u8(caller_stack + 1u);
    uint32 x = r_u32(position);
    uint32 vertical_product = second * extent;
    uint32 z = r_u32(position + 8u);
    uint32 view_x = r_u32(0x800843D8u);
    uint32 origin_x = r_u32(0x80077458u);
    uint32 dx = x - view_x;
    uint32 horizontal = x + origin_x - horizontal_product;
    uint32 view_z = r_u32(0x800843E0u);
    uint32 dz = z - view_z;
    uint32 origin_z = r_u32(0x80077468u);
    uint32 negative_z = 0u - dz;
    uint32 vertical = origin_z - z - vertical_product;
    /* Map 8004B1B0..8004B1DC */
    if ((sint32)dx < (sint32)negative_z)
    {
        orientation = 2u;
        dx = 0u - dx;
        dz = negative_z;
    }
    if ((sint32)dz < (sint32)dx)
        orientation |= 1u;
    /* Map 8004B1DC..8004B204 */
    if ((orientation & 1u) == 0u)
    {
        uint32 swap = horizontal;
        horizontal = extent - vertical;
        vertical = swap;
    }
    if ((orientation & 2u) != 0u)
    {
        horizontal = extent - horizontal;
        vertical = extent - vertical;
    }
    /* Map 8004B204..8004B22C */
    uint32 upper = vertical + radius;
    uint32 lower = vertical - radius;
    if (((sint32)horizontal < 0 && (sint32)extent < (sint32)horizontal) || (sint32)upper < 0 || (sint32)extent < (sint32)lower)
        goto border_outside;
    /* Map 8004B22C..8004B25C */
    uint32 from = 3u;
    uint32 to = 3u;
    uint32 unit = r_u32(0x80077488u);
    if ((sint32)unit < (sint32)lower)
    {
        from = 4u;
        to = 4u;
        if ((sint32)(unit << 1) < (sint32)lower)
        {
            from = 5u;
            to = 5u;
        }
    }
    /* Map 8004B25C..8004B2A4 */
    if (to < 5u)
    {
        if (to < 4u && (sint32)r_u32(0x80077488u) < (sint32)(vertical + radius))
            to = 4u;
        unit = r_u32(0x80077488u);
        if ((sint32)(unit << 1) < (sint32)(vertical + radius))
            to = 5u;
    }
    /* Map 8004B2A4..8004B2B8 */
    unit = r_u32(0x80077488u);
    if ((sint32)horizontal < (sint32)unit)
        return 0u;
    /* Map 8004B2B8..8004B2E8 */
    uint32 rotation = ((uint32)r_s16(cell + 2u) - orientation) & 3u;
    uint32 table = 0x800739FCu + rotation * 9u;
    if ((sint32)to < (sint32)from)
        return 0u;
    /* Map 8004B2E8..8004B304 */
    uint32 far = (sint32)(unit << 1) < (sint32)horizontal;
    uint32 cursor = table + from;
    uint32 end = table + to;
    do
    {
        if (far != 0u)
        {
            /* Map 8004B304..8004B338 */
            cell_height = r_u16(cell + 2u);
            uint32 sample = (uint32)r_s8(cursor);
            base_height = (uint32)((sint32)((cell_height & 0xFFFCu) << 16) >> 14);
            sample = (uint32)r_s8(record + sample + 12u);
            y = r_u32(position + 4u);
            ceiling = base_height + (sample << 6);
            if ((sint32)y < (sint32)ceiling)
                return 1u;
        }
        /* Map 8004B338..8004B36C */
        cell_height = r_u16(cell + 2u);
        uint32 sample = (uint32)r_s8(cursor + 3u);
        base_height = (uint32)((sint32)((cell_height & 0xFFFCu) << 16) >> 14);
        sample = (uint32)r_s8(record + sample + 12u);
        y = r_u32(position + 4u);
        ceiling = base_height + (sample << 6);
        ++cursor;
        if ((sint32)y < (sint32)ceiling)
            return 1u;
        /* Map 8004B36C..8004B380 */
    } while ((sint32)end >= (sint32)cursor);
    return 0u;
border_outside:
    /* Map 8004B380..8004B39C */
    if ((sint32)horizontal < 0)
        return 0u;
    dimensions = r_u32(0x80077644u);
    return (uint32)((sint32)r_u32(dimensions) < (sint32)horizontal);
    /* Map 8004B39C..8004B3C4 */
}

uint32 ob_border_cell_address(uint32 packed, uint32 dimensions, uint32 caller_stack)
{
    FUNCTION_MARKER(0x8004B514u, "SLES_008.65");
    /* Map 8004B514..8004B524 */
    uint32 shifted = (uint32)((sint32)packed >> 16);
    w_u32(caller_stack, shifted);
    uint32 width = (uint32)r_s16(dimensions + 4u);
    /* Map 8004B524..8004B544 */
    uint32 x = r_u8(caller_stack);
    uint32 limit = width << 4;
    if ((sint32)x >= (sint32)limit)
        w_u8(caller_stack, limit - 1u);
    /* Map 8004B544..8004B568 */
    uint32 height = (uint32)r_s16(dimensions + 6u);
    uint32 z = r_u8(caller_stack + 1u);
    limit = height << 4;
    if ((sint32)z >= (sint32)limit)
        w_u8(caller_stack + 1u, limit - 1u);
    /* Map 8004B568..8004B594 */
    z = r_u8(caller_stack + 1u);
    width = (uint32)r_s16(dimensions + 4u);
    uint32 row_product = (z >> 4) * width;
    uint32 fine_z = z & 3u;
    x = r_u8(caller_stack);
    uint32 fine_x = x & 3u;
    uint32 mid_x = (x & 15u) >> 2;
    uint32 mid_z = (z & 15u) >> 2;
    /* Map 8004B594..8004B5BC */
    uint32 table = r_u32(dimensions + 12u);
    uint32 group = r_u16(table + (((x >> 4) + row_product) << 1)) & 0xFFF0u;
    uint32 intermediate;
    /* Map 8004B5BC..8004B5E8 */
    if (group != 0u)
    {
        table = r_u32(dimensions + 16u);
        intermediate = table + (group << 1) + ((mid_x + (mid_z << 2)) << 1);
    }
    else
    {
        /* Map 8004B5E8..8004B5EC */
        intermediate = r_u32(dimensions + 16u);
    }
    /* Map 8004B5EC..8004B604 */
    group = r_u16(intermediate) & 0xFFF0u;
    /* Map 8004B604..8004B624 */
    if (group != 0u)
    {
        table = r_u32(dimensions + 20u);
        return table + (group << 2) + ((fine_x + (fine_z << 2)) << 2);
    }
    /* Map 8004B624..8004B634 */
    return r_u32(dimensions + 20u);
}

uint32 ob_border_subcell_to_tile(uint32 output, uint32 packed, uint32 caller_stack)
{
    FUNCTION_MARKER(0x8004B3E8u, "SLES_008.65");
    /* Map 8004B3E8..8004B3FC */
    uint32 shifted = (uint32)((sint32)packed >> 16);
    uint32 local = caller_stack - 8u;
    uint32 dimensions = r_u32(0x80077644u);
    w_u32(caller_stack + 4u, shifted);
    /* Map 8004B3FC..8004B410 */
    uint32 z = r_u8(caller_stack + 5u);
    uint32 columns = (uint32)r_s16(dimensions + 4u);
    uint32 row_product = (z >> 4) * columns;
    /* Map 8004B410..8004B430 */
    uint32 x = r_u8(caller_stack + 4u);
    w_u8(local + 1u, (x & 15u) + ((z & 15u) << 4));
    /* Map 8004B430..8004B434 */
    w_u8(local, (x >> 4) + row_product);
    /* Map 8004B434..8004B444 */
    uint32 first = (uint32)r_s8(local);
    uint32 second = (uint32)r_s8(local + 1u);
    w_u8(output, first);
    w_u8(output + 1u, second);
    /* Map 8004B444..8004B450 */
    return output;
}

uint32 ob_classify_clip_planes(uint32 vertices, uint32 count)
{
    FUNCTION_MARKER(0x8002C4ACu, "SLES_008.65");
    uint32 remaining = count - 1u;
    count &= 0xFFFFu;
    uint32 top = r_u16(0x80077524u);
    uint32 bottom = r_u16(0x8007751Eu);
    uint32 right = r_u16(0x80077522u);
    uint32 left = r_u16(0x8007751Cu);
    uint32 far = r_u16(0x8007752Cu);
    uint32 middle = r_u16(0x80077520u);
    uint32 near = r_u16(0x8007735Cu);
    if (count == 0u)
        return right << 16;
    right = (uint32)(sint16)right;
    left = (uint32)(sint16)left;
    top = (uint32)(sint16)top;
    bottom = (uint32)(sint16)bottom;
    near = 0u - (uint32)(sint16)near;
    middle = 0u - (uint32)(sint16)middle;
    uint32 output = vertices + 16u;
    do
    {
        uint32 x = (uint32)r_s16(output - 8u);
        uint32 z = (uint32)r_s16(output - 4u);
        uint32 code = (uint32)((sint32)z < (sint32)(x - right));
        if ((sint32)z < (sint32)(0u - (x + left)))
            code |= 2u;
        uint32 y = (uint32)r_s16(output - 6u);
        if ((sint32)z < (sint32)(y - top))
            code |= 4u;
        if ((sint32)z < (sint32)(0u - (y + bottom)))
            code |= 8u;
        if ((sint32)z < (sint32)near)
        {
            code |= 0x40u;
            if ((sint32)z < (sint32)middle)
                code |= 0x20u;
        }
        else if ((sint16)far < (sint32)z)
            code |= 0x10u;
        w_u32(output, code & 0xFFFFu);
        output += 24u;
        uint32 result = remaining & 0xFFFFu;
        --remaining;
        if (result == 0u)
            return 0u;
    } while (1);
}

#include "psx.h"

uint32 ob_classify_object_sphere(uint32 position, uint32 resource)
{
    FUNCTION_MARKER(0x8003A430u, "SLES_008.65");
    uint32 view = r_u32(0x800775D0u);
    uint32 coordinate = r_u32(position);
    uint32 center = r_u32(view + 24u);
    w_u16(0x1F800020u, (uint32)((sint32)(coordinate - center) >> 4));
    coordinate = r_u32(position + 4u);
    center = r_u32(view + 28u);
    w_u16(0x1F800022u, (uint32)((sint32)(coordinate - center) >> 4));
    coordinate = r_u32(position + 8u);
    center = r_u32(view + 32u);
    w_u16(0x1F800024u, (uint32)((sint32)(coordinate - center) >> 4));
    uint32 first = r_u32(0x80083EA0u);
    uint32 second = r_u32(0x80083EA4u);
    uint32 third = r_u32(0x80083EA8u);
    uint32 fourth = r_u32(0x80083EACu);
    uint32 fifth = r_u32(0x80083EB0u);
    PsxGteSnapshot snapshot;
    psx_gte_snapshot(&snapshot);
    MATRIX matrix = snapshot.rotation;
    matrix.m[0][0] = (sint16)first;
    matrix.m[0][1] = (sint16)(first >> 16);
    matrix.m[0][2] = (sint16)second;
    matrix.m[1][0] = (sint16)(second >> 16);
    matrix.m[1][1] = (sint16)third;
    matrix.m[1][2] = (sint16)(third >> 16);
    matrix.m[2][0] = (sint16)fourth;
    matrix.m[2][1] = (sint16)(fourth >> 16);
    matrix.m[2][2] = (sint16)fifth;
    uint32 xy = r_u32(0x1F800020u);
    uint32 z = r_u32(0x1F800024u);
    SVECTOR input;
    input.vx = (sint16)xy;
    input.vy = (sint16)(xy >> 16);
    input.vz = (sint16)z;
    input.pad = 0;
    VECTOR output;
    ApplyMatrix(&matrix, &input, &output);
    uint32 scale = r_u16(resource + 22u);
    uint32 radius = r_u16(resource + 8u);
    radius = (uint32)((sint32)(scale * radius) >> 8);
    w_u32(0x1F800010u, (uint32)output.vx << 4);
    w_u32(0x1F800014u, (uint32)output.vy << 4);
    w_u32(0x1F800018u, (uint32)output.vz << 4);
    z = r_u32(0x1F800018u);
    if ((sint32)z < (sint32)(0u - radius))
        return 1u;
    uint32 narrow_radius = (uint32)(sint32)(sint16)radius;
    uint32 margin = (uint32)((sint32)(11585u * narrow_radius) >> 14) << 1;
    coordinate = r_u32(0x1F800010u);
    if ((sint32)z < (sint32)(coordinate - margin))
        return 1u;
    if ((sint32)z < (sint32)(0u - (coordinate + margin)))
        return 1u;
    coordinate = r_u32(0x1F800014u);
    if ((sint32)z < (sint32)(coordinate - margin))
        return 1u;
    return (uint32)((sint32)z < (sint32)(0u - (coordinate + margin)));
}

#include "memory_frontier.h"

uint32 ob_reserve_vertex_span(uint32 record, uint32 requested, uint32 stride)
{
    FUNCTION_MARKER(0x800357DCu, "SLES_008.65");
    /* Map 800357DC..800357EC */
    uint32 previous = r_u32(record);
    uint32 result = (uint32)((sint32)stride < (sint32)requested);
    if (previous != 0u)
    {
        /* Map 800357EC..80035800 */
        uint32 existing = (uint32)r_s8(record + 5u);
        result = (uint32)((sint32)existing < (sint32)requested);
        if (result == 0u)
            return result;
        /* Map 80035800..80035818 */
        uint32 free_head = r_u32(0x8007733Cu);
        w_u32(previous, free_head);
        existing = (uint32)r_s8(record + 5u);
        w_u32(0x8007733Cu, previous);
        w_u32(previous + 4u, existing);
        /* Map 80035818..80035824 */
        result = (uint32)((sint32)stride < (sint32)requested);
    }
    while (result != 0u)
    {
        stride += 4u;
        result = (uint32)((sint32)stride < (sint32)requested);
    }
    /* Map 8003581C..80035828 */
    /* Map 80035828..80035844 */
    uint32 allocation = r_u32(0x80077580u);
    result = stride << 2;
    w_u8(record + 4u, requested);
    w_u8(record + 5u, stride);
    w_u32(record, allocation);
    w_u32(0x80077580u, allocation + result);
    /* Map 80035844..8003584C */
    return result;
}

uint32 ob_append_sea_quad(uint32 first, uint32 second, uint32 third, uint32 fourth, uint32 caller_stack)
{
    FUNCTION_MARKER(0x8004EC6Cu, "SLES_008.65");
    sint32 first_x = r_s16(first);
    uint32 index = r_u16(caller_stack + 16u);
    if (first_x < 0 && r_s16(second) < 0 && r_s16(third) < 0 && r_s16(fourth) < 0)
        return 1u;
    if (r_s16(first + 2u) < 0 && r_s16(second + 2u) < 0 && r_s16(third + 2u) < 0 && r_s16(fourth + 2u) < 0)
        return 2u;
    first_x = r_s16(first);
    sint32 bound = (sint32)r_u32(0x800881A0u);
    if (first_x > bound && r_s16(second) > bound && r_s16(third) > bound && r_s16(fourth) > bound)
        return 3u;
    sint32 first_y = r_s16(first + 2u);
    bound = (sint32)r_u32(0x800896C0u);
    if (first_y > bound && r_s16(second + 2u) > bound && r_s16(third + 2u) > bound && r_s16(fourth + 2u) > bound)
        return 4u;
    uint32 table = r_u32(0x8007737Cu);
    uint32 end = r_u32(0x800775BCu);
    uint32 packet = r_u32(0x800774A8u);
    uint32 slot = table + 120u;
    w_u32(0x80077634u, slot);
    uint32 previous = r_u32(slot);
    if ((sint32)(end - packet) < 40)
        return slot;
    uint32 source = 0x800849A0u + 40u * (uint32)(sint32)(sint16)index;
    w_u32(0x800774A8u, packet + 40u);
    uint32 link = r_u32(slot);
    link = (link & 0xFF000000u) | (packet & 0xFFFFFFu);
    w_u32(0x80077634u, packet);
    w_u32(slot, link);
    uint32 destination = packet;
    for (uint32 chunk = 0; chunk < 2u; ++chunk)
    {
        uint32 word0 = r_u32(source);
        uint32 word1 = r_u32(source + 4u);
        uint32 word2 = r_u32(source + 8u);
        uint32 word3 = r_u32(source + 12u);
        w_u32(destination, word0);
        w_u32(destination + 4u, word1);
        w_u32(destination + 8u, word2);
        w_u32(destination + 12u, word3);
        source += 16u;
        destination += 16u;
    }
    uint32 word0 = r_u32(source);
    uint32 word1 = r_u32(source + 4u);
    w_u32(destination, word0);
    w_u32(destination + 4u, word1);
    w_u16(packet + 8u, r_u16(first));
    w_u16(packet + 10u, r_u16(first + 2u));
    w_u16(packet + 16u, r_u16(second));
    w_u16(packet + 18u, r_u16(second + 2u));
    w_u16(packet + 24u, r_u16(third));
    uint32 third_y = r_u16(third + 2u);
    uint32 final_packet = r_u32(0x80077634u);
    w_u16(packet + 26u, third_y);
    w_u16(packet + 32u, r_u16(fourth));
    w_u16(packet + 34u, r_u16(fourth + 2u));
    link = r_u32(final_packet);
    w_u32(final_packet, (link & 0xFF000000u) | (previous & 0xFFFFFFu));
    return 0u;
}

uint32 ob_init_sea_texture_packet(void)
{
    FUNCTION_MARKER(0x8004E70Cu, "SLES_008.65");
    uint32 descriptor = r_u32(0x80066C28u);
    uint32 first_slot = ob_memory_slot_address(descriptor >> 17);
    descriptor = r_u32(0x80066C28u);
    uint32 second_slot = ob_memory_slot_address((descriptor >> 2) & 0x7FFFu);
    uint32 first = r_u32(first_slot);
    uint32 second = r_u32(second_slot);
    /* Reuse the exact contextual SDK packet writes proved in batch 27 */
    w_u8(0x80084473u, 9u);
    w_u8(0x80084477u, 0x2Cu);
    w_u8(0x80084477u, r_u8(0x80084477u) | 2u);
    w_u8(0x80084474u, 0x80u);
    w_u8(0x80084475u, 0x80u);
    w_u8(0x80084476u, 0x80u);
    uint32 u = (second >> 4) & 0xF0u;
    uint32 v = (second >> 8) & 0xF0u;
    w_u8(0x8008447Cu, u + 63u);
    w_u8(0x8008447Du, v);
    w_u8(0x80084484u, u + 63u);
    w_u8(0x80084485u, v + 63u);
    w_u8(0x8008448Cu, u);
    w_u8(0x8008448Du, v);
    w_u8(0x80084494u, u);
    w_u8(0x80084495u, v + 63u);
    w_u16(0x8008447Eu, first >> 2);
    w_u16(0x80084486u, second >> 16);
    return u;
}

uint32 ob_unsigned_bit_length(uint32 value)
{
    FUNCTION_MARKER(0x800283C0u, "SLES_008.65");
    /* Map 800283C0..800283C8 */
    uint32 count = 0u;
    /* Map 800283C8..800283D4 */
    while (value != 0u)
    {
        value >>= 1;
        count += 1u;
    }
    /* Map 800283D4..800283DC */
    return count;
}

uint32 ob_world_store_pair(uint32 first, uint32 second, uint32 time, uint32 result_record, uint32 caller_stack)
{
    FUNCTION_MARKER(0x80048978u, "SLES_008.65");
    /* PC 80048978..80048990 */
    uint32 destination = r_u32(caller_stack + 16u);
    w_u32(destination, time);
    w_u32(destination + 4u, first);
    w_u32(destination + 8u, second);
    w_u32(destination + 20u, result_record);
    return destination;
}

uint32 ob_world_axis_entry_time(uint32 record, uint32 caller_stack)
{
    FUNCTION_MARKER(0x80048FECu, "SLES_008.65");
    /* PC 80048FEC..80048FFC */
    uint32 first = r_u32(record + 4u);
    uint32 first_gap = r_u32(record + 72u);
    uint32 second = r_u32(record + 8u);
    uint32 frame = caller_stack - 32u;
    /* PC 80049000..80049130 */
    for (uint32 axis = 0u; axis != 3u; ++axis)
    {
        uint32 gap = axis == 0u ? first_gap : r_u32(record + 72u + axis * 4u);
        if ((sint32)gap <= 0)
            w_u32(frame + 16u + axis * 4u, 0u);
        else
        {
            uint32 first_speed = r_u32(first + 100u + axis * 4u);
            uint32 second_speed = r_u32(second + 100u + axis * 4u);
            uint32 denominator = first_speed + second_speed;
            w_u32(frame + axis * 4u, denominator);
            if (denominator == 0u)
                return 0x7FFFFF01u;
            uint32 numerator = r_u32(record + 72u + axis * 4u);
            /* Zero denominator has returned and signed overflow is excluded by physical alias proof */
            uint32 quotient = (uint32)((sint32)numerator / (sint32)denominator);
            w_u32(frame + 16u + axis * 4u, quotient);
        }
    }
    /* PC 80049134..80049164 */
    uint32 max_time = r_u32(frame + 20u);
    uint32 z_time = r_u32(frame + 24u);
    if ((sint32)max_time < (sint32)z_time)
        max_time = z_time;
    uint32 x_time = r_u32(frame + 16u);
    if ((sint32)x_time < (sint32)max_time)
        x_time = max_time;
    /* PC 80049168..80049194 */
    uint32 first_limit = r_u32(first + 176u);
    uint32 second_limit = r_u32(second + 176u);
    if ((sint32)second_limit < (sint32)first_limit)
        first_limit = second_limit;
    if ((sint32)first_limit >= (sint32)x_time)
        return 0x7FFFFFFFu;
    /* PC 80049198..800491AC */
    return r_u32(record) + x_time;
}

uint32 ob_zero_callback(void)
{
    FUNCTION_MARKER(0x80013818u, "SLES_008.65");
    return 0u;
}

uint32 ob_controller_slot_ready(uint32 index)
{
    FUNCTION_MARKER(0x800540F8u, "SLES_008.65");
    uint32 base = index < 4u ? 0x8008CB28u : 0x8008CE90u;
    if (r_u8(base) != 0u)
        return 0u;
    uint32 kind = r_u8(base + 1u) >> 4;
    if (kind != 8u)
        return index == (index < 4u ? 0u : 4u);
    uint32 slot = base + (index << 3) + (index < 4u ? 2u : 0xFFFFFFE2u);
    return (r_u8(slot) ^ 0xFFu) != 0u;
}

uint32 ob_select_spatial_event(uint32 state)
{
    FUNCTION_MARKER(0x80050870u, "SLES_008.65");
    /* Map 80050870..80050890 */
    uint32 first = r_u32(state + 0xD4u);
    uint32 second = r_u32(state + 0x14Cu);
    uint32 result = state + 0x144u;
    if ((sint32)first < (sint32)second)
        result = state + 0xCCu;
    /* Map 80050890..800508C4 */
    else if (first == second)
    {
        uint32 first_fraction = r_u32(state + 0xD8u);
        uint32 second_scale = r_u32(state + 0x190u);
        uint32 second_fraction = r_u32(state + 0x150u);
        uint32 first_product = first_fraction * second_scale;
        uint32 first_scale = r_u32(state + 0x118u);
        uint32 second_product = second_fraction * first_scale;
        if ((sint32)second_product >= (sint32)first_product)
            result = state + 0xCCu;
    }
    /* Map 800508C4..800508D0 */
    w_u32(state + 0x70u, result);
    return result;
}

uint32 ob_collision_normalize_axes(uint32 collision)
{
    FUNCTION_MARKER(0x80048B60u, "SLES_008.65");
    /* Map 80048B60..80048B90 */
    uint32 speed = r_u32(collision + 0x3Cu);
    uint32 coordinate = r_u32(collision + 0x24u);
    w_u32(collision + 0x60u, (sint32)speed < 0 ? 0u - speed : speed);
    if ((sint32)speed < 0)
        coordinate = 0u - coordinate;
    w_u32(collision + 0x54u, coordinate);
    /* Map 80048B90..80048BC0 */
    speed = r_u32(collision + 0x40u);
    coordinate = r_u32(collision + 0x28u);
    w_u32(collision + 0x64u, (sint32)speed < 0 ? 0u - speed : speed);
    if ((sint32)speed < 0)
        coordinate = 0u - coordinate;
    w_u32(collision + 0x58u, coordinate);
    /* Map 80048BC0..80048BF4 */
    speed = r_u32(collision + 0x44u);
    coordinate = r_u32(collision + 0x2Cu);
    w_u32(collision + 0x68u, (sint32)speed < 0 ? 0u - speed : speed);
    if ((sint32)speed < 0)
        coordinate = 0u - coordinate;
    w_u32(collision + 0x5Cu, coordinate);
    return coordinate;
}

uint32 ob_select_earliest_flagged_contact(uint32 object)
{
    FUNCTION_MARKER(0x800479E0u, "SLES_008.65");
    uint32 remaining = r_u32(object + 180u);
    w_u32(object + 192u, 0xFFFFFFFFu);
    uint32 slot = r_u32(object + 24u);
    w_u32(object + 188u, 0x7FFFFFFFu);
    uint32 table = r_u32(0x80077148u);
    uint32 result = table + (slot << 2);
    uint32 row = r_u32(result);
    uint32 index = 0u;
    while (remaining != 0u)
    {
        result = r_u32(row) & 0x8000u;
        if (result != 0u)
        {
            uint32 time = r_u32(row + 4u);
            uint32 best = r_u32(object + 188u);
            result = (sint32)time < (sint32)best;
            if (result != 0u)
            {
                w_u32(object + 192u, index);
                w_u32(object + 188u, time);
            }
            remaining -= 1u;
        }
        row += 8u;
        index += 1u;
    }
    return result;
}
