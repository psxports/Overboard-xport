#include "batch24_frontier.h"
#include "batch17_frontier.h"

static uint32 ob_matrix_pair14(uint32 first, uint32 first_coefficient, uint32 second, uint32 second_coefficient)
{
    uint32 sum = first * first_coefficient + second * second_coefficient;
    return (uint32)((sint32)sum >> 14);
}

uint32 ob_rotate_matrix_z14(uint32 matrix, uint32 angle, uint32 output)
{
    FUNCTION_MARKER(0x8002AB48u, "SLES_008.65");
    uint32 offset = (((angle & 0xFFFFu) + 8u) >> 4) << 1;
    uint32 x0 = (uint32)r_s16(matrix);
    uint32 cosine = (uint32)r_s16(0x8006CB04u + offset);
    uint32 y0 = (uint32)r_s16(matrix + 6u);
    uint32 sine = (uint32)r_s16(0x8006C304u + offset);
    uint32 x1 = (uint32)r_s16(matrix + 2u);
    uint32 y1 = (uint32)r_s16(matrix + 8u);
    uint32 x2 = (uint32)r_s16(matrix + 4u);
    uint32 y2 = (uint32)r_s16(matrix + 10u);
    uint32 negative_sine = 0u - sine;
    w_u16(output, ob_matrix_pair14(x0, cosine, y0, sine));
    w_u16(output + 2u, ob_matrix_pair14(x1, cosine, y1, sine));
    w_u16(output + 4u, ob_matrix_pair14(x2, cosine, y2, sine));
    w_u16(output + 6u, ob_matrix_pair14(x0, negative_sine, y0, cosine));
    w_u16(output + 8u, ob_matrix_pair14(x1, negative_sine, y1, cosine));
    w_u16(output + 10u, ob_matrix_pair14(x2, negative_sine, y2, cosine));
    uint32 value = r_u16(matrix + 12u);
    w_u16(output + 12u, value);
    value = r_u16(matrix + 14u);
    w_u16(output + 14u, value);
    value = r_u16(matrix + 16u);
    w_u16(output + 16u, value);
    return value;
}

uint32 ob_rotate_matrix_x14(uint32 matrix, uint32 angle, uint32 output)
{
    FUNCTION_MARKER(0x8002A870u, "SLES_008.65");
    uint32 offset = (((angle & 0xFFFFu) + 8u) >> 4) << 1;
    uint32 y0 = (uint32)r_s16(matrix + 6u);
    uint32 cosine = (uint32)r_s16(0x8006CB04u + offset);
    uint32 z0 = (uint32)r_s16(matrix + 12u);
    uint32 sine = (uint32)r_s16(0x8006C304u + offset);
    uint32 y1 = (uint32)r_s16(matrix + 8u);
    uint32 z1 = (uint32)r_s16(matrix + 14u);
    uint32 y2 = (uint32)r_s16(matrix + 10u);
    uint32 z2 = (uint32)r_s16(matrix + 16u);
    uint32 negative_sine = 0u - sine;
    uint32 value = r_u16(matrix);
    w_u16(output, value);
    value = r_u16(matrix + 2u);
    w_u16(output + 2u, value);
    value = r_u16(matrix + 4u);
    w_u16(output + 6u, ob_matrix_pair14(y0, cosine, z0, sine));
    w_u16(output + 8u, ob_matrix_pair14(y1, cosine, z1, sine));
    w_u16(output + 10u, ob_matrix_pair14(y2, cosine, z2, sine));
    w_u16(output + 12u, ob_matrix_pair14(y0, negative_sine, z0, cosine));
    w_u16(output + 14u, ob_matrix_pair14(y1, negative_sine, z1, cosine));
    w_u16(output + 4u, value);
    uint32 result = z2 * cosine;
    uint32 sum = y2 * negative_sine + result;
    w_u16(output + 16u, (uint32)((sint32)sum >> 14));
    return result;
}

uint32 ob_set_object_time(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x80045A7Cu, "SLES_008.65");
    uint32 result = r_u32(object + 0xA0u) & 0x10u;
    if (result != 0u)
        w_u32(object + 0x4Cu, time);
    else
    {
        ob_advance_object(object, time, result);
        result = ob_invalidate_object_position(object);
    }
    w_u32(object + 0x48u, time);
    return result;
}

uint32 ob_rotate_matrix_y14(uint32 matrix, uint32 angle, uint32 output)
{
    FUNCTION_MARKER(0x8002ADFCu, "SLES_008.65");
    uint32 offset = (((angle & 0xFFFFu) + 8u) >> 4) << 1;
    uint32 x0 = (uint32)r_s16(matrix);
    uint32 cosine = (uint32)r_s16(0x8006CB04u + offset);
    uint32 sine = (uint32)r_s16(0x8006C304u + offset);
    uint32 z0 = (uint32)r_s16(matrix + 12u);
    uint32 negative_sine = 0u - sine;
    uint32 x1 = (uint32)r_s16(matrix + 2u);
    uint32 z1 = (uint32)r_s16(matrix + 14u);
    uint32 x2 = (uint32)r_s16(matrix + 4u);
    uint32 z2 = (uint32)r_s16(matrix + 16u);
    w_u16(output, ob_matrix_pair14(x0, cosine, z0, negative_sine));
    w_u16(output + 2u, ob_matrix_pair14(x1, cosine, z1, negative_sine));
    w_u16(output + 4u, ob_matrix_pair14(x2, cosine, z2, negative_sine));
    uint32 value = r_u16(matrix + 6u);
    w_u16(output + 6u, value);
    value = r_u16(matrix + 8u);
    w_u16(output + 8u, value);
    value = r_u16(matrix + 10u);
    w_u16(output + 12u, ob_matrix_pair14(x0, sine, z0, cosine));
    w_u16(output + 14u, ob_matrix_pair14(x1, sine, z1, cosine));
    w_u16(output + 10u, value);
    uint32 result = z2 * cosine;
    uint32 sum = x2 * sine + result;
    w_u16(output + 16u, (uint32)((sint32)sum >> 14));
    return result;
}

uint32 ob_read_player_packet(uint32 output, uint32 index)
{
    FUNCTION_MARKER(0x8001A05Cu, "SLES_008.65");
    uint32 result = index * 7u;
    uint32 offset = result * 8u;
    uint32 count = r_u32(0x800C997Cu + offset);
    if ((sint32)count > 0)
        w_u32(output, 0u);
    else
    {
        uint32 value = r_u8(0x800C9980u + offset + count);
        w_u32(output, value);
        count = r_u32(0x800C997Cu + offset);
        result = (count ^ 0x80u) << 8;
        w_u32(output, value + result);
    }
    return result;
}

static uint32 ob_restore_player_callbacks(void)
{
    uint32 count = r_u8(0x8006C230u);
    uint32 index = 0u;
    uint32 offset = 0u;
    if (count != 0u)
    {
        do
        {
            w_u32(0x800C9964u + offset, 0x80019EA0u);
            w_u32(0x800C9960u + offset, 0x800A636Cu);
            count = r_u8(0x8006C230u);
            ++index;
            offset += 56u;
        } while (index < count);
    }
    return 0u;
}

uint32 ob_append_player_packet(uint32 count, uint32 value, uint32 offset)
{
    FUNCTION_MARKER(0x8001A0F0u, "SLES_008.65");
    if ((sint32)count <= 0)
    {
        w_u8(0x800C9980u + offset + count, value);
        uint32 reloaded = r_u32(0x800C997Cu + offset);
        w_u32(0x800C997Cu + offset, reloaded + 1u);
    }
    return ob_restore_player_callbacks();
}

uint32 ob_write_player_packet(uint32 index, uint32 value)
{
    FUNCTION_MARKER(0x8001A0CCu, "SLES_008.65");
    uint32 decoded = (value >> 8) ^ 0x80u;
    uint32 offset = index * 56u;
    uint32 count = r_u32(0x800C997Cu + offset);
    if (decoded == count)
        return ob_append_player_packet(count, value, offset);
    if (value == 0u && count == 1u)
    {
        uint32 total = r_u32(0x8007756Cu);
        uint32 reloaded = r_u32(0x800C997Cu + offset);
        w_u32(0x8007756Cu, total + 1u);
        w_u32(0x800C997Cu + offset, reloaded + 1u);
    }
    return ob_restore_player_callbacks();
}
