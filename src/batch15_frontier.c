#include "batch15_frontier.h"
#include "batch5_frontier.h"

uint32 ob_set_scene_callback(uint32 callback, uint32 incoming_result)
{
    FUNCTION_MARKER(0x8001B048u, "SLES_008.65");
    w_u32(0x80066030u, callback);
    return incoming_result;
}

uint32 ob_init_scene_geometry(void)
{
    FUNCTION_MARKER(0x80044D50u, "SLES_008.65");
    w_u32(0x80077448u, 0u);
    w_u32(0x800843D8u, 0u);
    w_u32(0x800843DCu, 0u);
    w_u32(0x800843E0u, 0u);
    ob_identity_matrix14(0x80084388u);
    w_u32(0x800843A0u, 0u);
    w_u32(0x800843A4u, 0u);
    w_u32(0x800843A8u, 0u);
    return ob_reset_geometry_record(0x80086B70u);
}

uint32 ob_identity_matrix14(uint32 matrix)
{
    FUNCTION_MARKER(0x80029E54u, "SLES_008.65");
    w_u16(matrix, 0x4000u);
    w_u16(matrix + 2u, 0u);
    w_u16(matrix + 4u, 0u);
    w_u16(matrix + 6u, 0u);
    w_u16(matrix + 8u, 0x4000u);
    w_u16(matrix + 10u, 0u);
    w_u16(matrix + 12u, 0u);
    w_u16(matrix + 14u, 0u);
    w_u16(matrix + 16u, 0x4000u);
    return 0x4000u;
}

uint32 ob_copy_vector_words(uint32 source, uint32 destination)
{
    FUNCTION_MARKER(0x80029E30u, "SLES_008.65");
    uint32 result = 0u;
    for (uint32 offset = 0u; offset < 12u; offset += 4u)
    {
        result = r_u32(source + offset);
        w_u32(destination + offset, result);
    }
    return result;
}

uint32 ob_copy_matrix_halfwords(uint32 source, uint32 destination)
{
    FUNCTION_MARKER(0x8002B7FCu, "SLES_008.65");
    uint32 result = 0u;
    for (uint32 offset = 0u; offset < 18u; offset += 2u)
    {
        result = r_u16(source + offset);
        w_u16(destination + offset, result);
    }
    return result;
}

uint32 ob_set_geometry_translation(uint32 geometry, uint32 source)
{
    FUNCTION_MARKER(0x8002FAA8u, "SLES_008.65");
    uint32 first = r_u32(source);
    uint32 second = r_u32(source + 4u);
    uint32 third = r_u32(source + 8u);
    w_u32(geometry + 0x18u, first);
    w_u32(geometry + 0x1Cu, second);
    w_u32(geometry + 0x20u, third);
    uint32 flags = r_u32(geometry + 0x30u);
    uint32 result = flags | 0x20u;
    w_u32(geometry + 0x30u, result);
    return result;
}

uint32 ob_transpose_matrix(uint32 matrix)
{
    FUNCTION_MARKER(0x8002F560u, "SLES_008.65");
    uint32 first = r_u16(matrix + 2u);
    uint32 second = r_u16(matrix + 4u);
    uint32 third = r_u16(matrix + 6u);
    uint32 fourth = r_u16(matrix + 10u);
    uint32 fifth = r_u16(matrix + 12u);
    uint32 sixth = r_u16(matrix + 14u);
    w_u16(matrix + 6u, first);
    w_u16(matrix + 12u, second);
    w_u16(matrix + 2u, third);
    w_u16(matrix + 14u, fourth);
    w_u16(matrix + 4u, fifth);
    w_u16(matrix + 10u, sixth);
    return first;
}

uint32 ob_init_card_tables(void)
{
    FUNCTION_MARKER(0x8001D1B0u, "SLES_008.65");
    w_u8(0x800899F2u, 2u);
    for (uint32 index = 0u; index < 13u; ++index)
    {
        uint32 selection = r_u8(0x8006C231u);
        uint32 item = r_u8(0x8006BD58u + 13u * selection + index);
        if (item == 0u)
        {
            w_u8(0x800899CEu + index, 0u);
            w_u8(0x800899DBu + index, 0u);
        }
        else
        {
            w_u8(0x800899CEu + index, 1u);
            selection = r_u8(0x8006C231u);
            item = r_u8(0x8006BD58u + 13u * selection + index);
            w_u8(0x800899DBu + index, item - 1u);
        }
    }
    for (uint32 index = 0u; index < 5u; ++index)
    {
        uint32 selection = r_u8(0x8006C231u);
        uint32 item = r_u16(0x8006BEE0u + selection * 10u + index * 2u);
        w_u16(0x800899E8u + index * 2u, item);
    }
    for (uint32 table = 0u; table < 5u; ++table)
    {
        for (uint32 index = 0u; index < 13u; ++index)
        {
            uint32 source = r_u32(0x80065CB0u + table * 4u);
            uint32 item = r_u32(source + index * 4u);
            w_u32(0x800899F8u + table * 52u + index * 4u, item);
        }
    }
    return 0u;
}

uint32 ob_set_frame_callback(uint32 callback, uint32 incoming_result)
{
    FUNCTION_MARKER(0x8002CFE4u, "SLES_008.65");
    w_u32(0x80073518u, callback);
    return incoming_result;
}
