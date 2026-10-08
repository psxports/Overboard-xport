#include "batch17_frontier.h"

uint32 ob_angle_matrix14(uint32 angle, uint32 matrix)
{
    FUNCTION_MARKER(0x80029E80u, "SLES_008.65");
    uint32 offset = (((angle & 0xFFFFu) + 8u) >> 4) << 1;
    uint32 sine = r_u16(0x8006C304u + offset);
    uint32 cosine = r_u16(0x8006CB04u + offset);
    w_u16(matrix, 0x4000u);
    w_u16(matrix + 2u, 0u);
    w_u16(matrix + 4u, 0u);
    w_u16(matrix + 6u, 0u);
    w_u16(matrix + 12u, 0u);
    w_u16(matrix + 10u, sine);
    sine = 0u - sine;
    w_u16(matrix + 8u, cosine);
    w_u16(matrix + 14u, sine);
    w_u16(matrix + 16u, cosine);
    return 0x4000u;
}

uint32 ob_random15(void)
{
    FUNCTION_MARKER(0x8001B008u, "SLES_008.65");
    uint32 seed = r_u32(0x80066034u);
    uint32 next = seed * 12345u + 1u;
    w_u32(0x80066034u, next);
    return next & 0x7FFFu;
}

uint32 ob_advance_object(uint32 object, uint32 time, uint32 incoming_result)
{
    FUNCTION_MARKER(0x80045758u, "SLES_008.65");
    uint32 previous = r_u32(object + 0x4Cu);
    if (time == previous)
        return incoming_result;
    uint32 result = r_u32(object + 0xA0u) & 0x10u;
    uint32 delta = time - previous;
    if (result == 0u && delta != 0u)
    {
        uint32 vx = r_u32(object + 0x84u);
        uint32 dx = vx * delta;
        uint32 vy = r_u32(object + 0x88u);
        uint32 dy = vy * delta;
        uint32 vz = r_u32(object + 0x8Cu);
        uint32 dz = vz * delta;
        uint32 x = r_u32(object + 0x5Cu);
        x += dx;
        uint32 y = r_u32(object + 0x60u);
        uint32 ix = (uint32)((int32_t)x >> 8);
        w_u32(object + 0x5Cu, x);
        w_u32(object + 0x50u, ix);
        y += dy;
        uint32 z = r_u32(object + 0x64u);
        uint32 iy = (uint32)((int32_t)y >> 8);
        w_u32(object + 0x60u, y);
        w_u32(object + 0x54u, iy);
        z += dz;
        result = (uint32)((int32_t)z >> 8);
        w_u32(object + 0x64u, z);
        w_u32(object + 0x58u, result);
    }
    w_u32(object + 0x4Cu, time);
    return result;
}

uint32 ob_clear_object_flags(uint32 object, uint32 mask)
{
    FUNCTION_MARKER(0x80045C98u, "SLES_008.65");
    uint32 flags = r_u32(object + 0xA0u);
    mask &= 0xFFu;
    uint32 result = ~mask;
    if ((flags & mask) != 0u)
    {
        result &= flags;
        w_u32(object + 0xA0u, result);
        uint32 child = r_u32(object + 0x20u);
        while (child != 0u)
        {
            result = ob_clear_object_flags(child, mask);
            child = r_u32(child + 0x1Cu);
        }
    }
    return result;
}

uint32 ob_invalidate_object_position(uint32 object)
{
    FUNCTION_MARKER(0x80045C30u, "SLES_008.65");
    uint32 flags = r_u32(object + 0xA0u);
    uint32 result = 0xFFFFFFFDu;
    if ((flags & 2u) != 0u)
    {
        result = flags & 0xFFFFFFFDu;
        w_u32(object + 0xA0u, result);
        uint32 child = r_u32(object + 0x20u);
        while (child != 0u)
        {
            result = ob_clear_object_flags(child, 2u);
            child = r_u32(child + 0x1Cu);
        }
    }
    return result;
}

uint32 ob_invalidate_object_matrix(uint32 object)
{
    FUNCTION_MARKER(0x80045B74u, "SLES_008.65");
    uint32 flags = r_u32(object + 0xA0u);
    if ((flags & 8u) != 0u)
    {
        uint32 first = r_u16(object + 0x24u);
        if (first != 0x4000u || r_u16(object + 0x2Cu) != first || r_u16(object + 0x34u) != first)
        {
            flags = r_u32(object + 0xA0u);
            w_u32(object + 0xA0u, flags & 0xFFFFFFF7u);
        }
    }
    flags = r_u32(object + 0xA0u);
    uint32 result = 0xFFFFFFFEu;
    if ((flags & 1u) != 0u)
    {
        result = flags & 0xFFFFFFFEu;
        w_u32(object + 0xA0u, result);
        uint32 child = r_u32(object + 0x20u);
        while (child != 0u)
        {
            result = ob_clear_object_flags(child, 3u);
            child = r_u32(child + 0x1Cu);
        }
    }
    return result;
}
