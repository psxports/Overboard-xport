#include "batch25_frontier.h"

uint32 ob_locate_spatial_cell(uint32 x, uint32 z, uint32 output)
{
    FUNCTION_MARKER(0x800514E4u, "SLES_008.65");
    uint32 coarse_x = (uint32)((sint32)x >> 4);
    uint32 coarse_z = (uint32)((sint32)z >> 4);
    uint32 map = r_u32(0x80077644u);
    uint32 middle_x = (x & 15u) >> 2;
    uint32 width = (uint32)r_s16(map + 4u);
    uint32 fine_x = x & 3u;
    uint32 middle_table = r_u32(map + 16u);
    uint32 middle_z = (z & 15u) >> 2;
    uint32 fine_z = z & 3u;
    uint32 coarse_table = r_u32(map + 12u);
    uint32 row = (uint32)(sint32)(sint8)coarse_z * width;
    uint32 coarse = coarse_table + (((uint32)(sint32)(sint8)coarse_x + row) << 1);
    uint32 coarse_value = r_u16(coarse);
    uint32 block = coarse_value & 0xFFF0u;
    if (block != 0u)
        middle_table += (block + middle_x + (middle_z << 2)) << 1;
    uint32 middle_value = r_u16(middle_table);
    uint32 fine_table = r_u32(map + 20u);
    block = middle_value & 0xFFF0u;
    if (block != 0u)
        fine_table += (block + fine_x + (fine_z << 2)) << 2;
    w_u32(output, coarse);
    w_u32(output + 4u, middle_table);
    w_u32(output + 8u, fine_table);
    uint32 cell = r_u8(fine_table);
    uint32 records = r_u32(map + 24u);
    w_u8(output + 18u, coarse_x);
    w_u8(output + 19u, middle_x);
    w_u8(output + 20u, fine_x);
    w_u8(output + 21u, coarse_z);
    w_u8(output + 22u, middle_z);
    w_u8(output + 23u, fine_z);
    w_u32(output + 12u, records + cell * 24u);
    records = r_u32(output + 12u);
    w_u8(output + 16u, 2u);
    uint32 result = r_u8(records + 22u);
    w_u8(output + 17u, result);
    return result;
}

uint32 ob_copy_spatial_heights(uint32 output, uint32 state, uint32 stride)
{
    FUNCTION_MARKER(0x8004C4D4u, "SLES_008.65");
    uint32 cell = r_u32(state + 8u);
    uint32 packed = r_u16(cell + 2u);
    uint32 step = (stride << 2) - 8u;
    uint32 selectors = 0x800739FCu + (packed & 3u) * 9u;
    uint32 selector = (uint32)r_s8(selectors);
    uint32 base = (uint32)((sint32)((packed & 0xFFFCu) << 16) >> 14);
    uint32 record = r_u32(state + 12u);
    uint32 result = (uint32)r_s8(record + selector + 12u) << 6;
    w_u32(output, base + result);
    for (uint32 index = 1u; index < 9u; ++index)
    {
        record = r_u32(state + 12u);
        selector = (uint32)r_s8(selectors + index);
        output += index == 3u || index == 6u ? step : 4u;
        result = (uint32)r_s8(record + selector + 12u) << 6;
        w_u32(output, base + result);
    }
    return result;
}

uint32 ob_step_spatial_cell(uint32 state, uint32 axis, uint32 increment)
{
    FUNCTION_MARKER(0x8005160Cu, "SLES_008.65");
    uint32 coordinate_offset = axis == 1u ? 21u : 18u;
    uint32 coarse = r_u8(state + coordinate_offset);
    uint32 middle = r_u8(state + coordinate_offset + 1u);
    uint32 fine = r_u8(state + coordinate_offset + 2u);
    uint32 map = r_u32(0x80077644u);
    uint32 original_coarse = coarse;
    uint32 bound = (uint32)r_s16(map + (axis == 1u ? 6u : 4u));
    uint32 original_middle = middle;
    sint32 level = r_s8(state + 16u);
    if (level == 0)
        coarse += increment;
    else if (level == 1)
    {
        uint32 sum = middle + increment;
        middle = sum;
        if ((sint8)sum < 0)
        {
            middle = sum + 4u;
            --coarse;
        }
        else if ((sint8)sum >= 4)
        {
            middle = sum - 4u;
            ++coarse;
        }
    }
    else if (level == 2)
    {
        uint32 sum = fine + increment;
        fine = sum;
        if ((sint8)sum < 0)
        {
            fine = sum + 4u;
            --middle;
            if ((sint8)middle < 0)
            {
                middle += 4u;
                --coarse;
            }
        }
        else if ((sint8)sum >= 4)
        {
            fine = sum - 4u;
            ++middle;
            if ((sint8)middle >= 4)
            {
                middle -= 4u;
                ++coarse;
            }
        }
    }
    if ((sint8)coarse < 0 || (sint32)(sint8)coarse >= (sint32)bound)
    {
        w_u32(state, 0x800771C4u);
        w_u32(state + 4u, 0x800771C6u);
        w_u32(state + 8u, 0x800771C8u);
        w_u32(state + 12u, 0x80073A20u);
    }
    w_u8(state + coordinate_offset, coarse);
    w_u8(state + coordinate_offset + 1u, middle);
    w_u8(state + coordinate_offset + 2u, fine);
    uint32 fine_table;
    uint32 fine_z;
    uint32 block;
    if ((sint8)original_coarse != (sint8)coarse)
    {
        map = r_u32(0x80077644u);
        uint32 z = (uint32)r_s8(state + 21u);
        uint32 width = (uint32)r_s16(map + 4u);
        uint32 x = (uint32)r_s8(state + 18u);
        uint32 coarse_table = r_u32(map + 12u);
        coarse_table += (x + z * width) << 1;
        w_u32(state, coarse_table);
        uint32 coarse_value = r_u16(coarse_table);
        uint32 middle_table = r_u32(map + 16u);
        uint32 middle_z = (uint32)r_s8(state + 22u);
        middle_table += (coarse_value & 0xFFF0u) << 1;
        uint32 middle_x = (uint32)r_s8(state + 19u);
        middle_table += (middle_x + (middle_z << 2)) << 1;
        w_u32(state + 4u, middle_table);
        uint32 middle_value = r_u16(middle_table);
        fine_table = r_u32(map + 20u);
        fine_z = (uint32)r_s8(state + 23u);
        block = middle_value & 0xFFF0u;
    }
    else if ((sint8)original_middle != (sint8)middle)
    {
        uint32 coarse_table = r_u32(state);
        map = r_u32(0x80077644u);
        uint32 middle_z = (uint32)r_s8(state + 22u);
        uint32 coarse_value = r_u16(coarse_table);
        uint32 middle_table = r_u32(map + 16u);
        middle_table += (coarse_value & 0xFFF0u) << 1;
        uint32 middle_x = (uint32)r_s8(state + 19u);
        middle_table += (middle_x + (middle_z << 2)) << 1;
        w_u32(state + 4u, middle_table);
        uint32 middle_value = r_u16(middle_table);
        fine_table = r_u32(map + 20u);
        fine_z = (uint32)r_s8(state + 23u);
        block = middle_value & 0xFFF0u;
    }
    else
    {
        uint32 middle_table = r_u32(state + 4u);
        map = r_u32(0x80077644u);
        fine_z = (uint32)r_s8(state + 23u);
        uint32 middle_value = r_u16(middle_table);
        fine_table = r_u32(map + 20u);
        block = middle_value & 0xFFF0u;
    }
    fine_table += block << 2;
    uint32 fine_x = (uint32)r_s8(state + 20u);
    fine_table += (fine_x + (fine_z << 2)) << 2;
    w_u32(state + 8u, fine_table);
    uint32 cell = r_u8(fine_table);
    uint32 record_table = r_u32(map + 24u);
    w_u32(state + 12u, record_table + cell * 24u);
    level = r_s8(state + 16u);
    uint32 result = (uint32)(level < 2);
    if (level == 0 || level == 1)
    {
        uint32 table = r_u32(state + (level == 1 ? 4u : 0u));
        result = r_u16(table);
        w_u8(state + 17u, result);
    }
    else if (level >= 2)
    {
        result = 2u;
        if (level == 2)
        {
            uint32 record = r_u32(state + 12u);
            result = r_u8(record + 22u);
            w_u8(state + 17u, result);
        }
    }
    return result;
}
