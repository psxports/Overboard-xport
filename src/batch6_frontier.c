#include "batch6_frontier.h"
#include <stdint.h>

uint32 ob_clip_viewport(uint32 record, uint32 left, uint32 top, uint32 right, uint32 bottom, uint32 dx, uint32 dy)
{
    FUNCTION_MARKER(0x8002CCC8u, "SLES_008.65");
    if ((int32_t)left >= (int32_t)right)
        return 0u;
    uint32 x0 = left + dx;
    if ((int32_t)top >= (int32_t)bottom)
        return 0u;
    uint32 y0 = top + dy;
    uint32 x1 = right + dx;
    uint32 y1 = bottom + dy;
    w_u32(record, left);
    w_u32(record + 4u, top);
    w_u32(record + 8u, right);
    w_u32(record + 12u, bottom);
    if ((int32_t)x0 < 0 && (int32_t)x1 < 0)
        return 0u;
    uint32 limits = r_u32(r_u32(0x8007741Cu) + 4u);
    uint32 width = r_u32(limits);
    if ((int32_t)width < (int32_t)x0 && (int32_t)width < (int32_t)x1)
        return 0u;
    if ((int32_t)y0 < 0 && (int32_t)y1 < 0)
        return 0u;
    uint32 height = r_u32(limits + 4u);
    if ((int32_t)height < (int32_t)y0 && (int32_t)height < (int32_t)y1)
        return 0u;
    if ((int32_t)x0 < 0)
    {
        w_u32(record + 48u, 0u);
        w_u32(record + 16u, left - x0);
    }
    else
    {
        w_u32(record + 48u, x0);
        w_u32(record + 16u, left);
    }
    if ((int32_t)y0 < 0)
    {
        w_u32(record + 52u, 0u);
        w_u32(record + 20u, top - y0);
    }
    else
    {
        w_u32(record + 52u, y0);
        w_u32(record + 20u, top);
    }
    uint32 global = r_u32(0x8007741Cu);
    width = r_u32(r_u32(global + 4u));
    if ((int32_t)x1 >= (int32_t)width)
    {
        w_u32(record + 56u, width - 1u);
        width = r_u32(r_u32(global + 4u));
        w_u32(record + 24u, right - 1u - (x1 - width));
    }
    else
    {
        w_u32(record + 56u, x1);
        w_u32(record + 24u, right);
    }
    global = r_u32(0x8007741Cu);
    height = r_u32(r_u32(global + 4u) + 4u);
    if ((int32_t)y1 >= (int32_t)height)
    {
        w_u32(record + 60u, height - 1u);
        height = r_u32(r_u32(global + 4u) + 4u);
        w_u32(record + 28u, bottom - 1u - (y1 - height));
    }
    else
    {
        w_u32(record + 60u, y1);
        w_u32(record + 28u, bottom);
    }
    uint32 end_x = r_u32(record + 24u);
    uint32 start_x = r_u32(record + 16u);
    uint32 start_y = r_u32(record + 20u);
    w_u32(record + 40u, dx);
    w_u32(record + 44u, dy);
    uint32 size_x = end_x - start_x;
    uint32 end_y = r_u32(record + 28u);
    w_u32(record + 32u, size_x + 1u);
    end_x = r_u32(record + 56u);
    uint32 size_y = end_y - start_y;
    start_x = r_u32(record + 48u);
    w_u32(record + 36u, size_y + 1u);
    end_y = r_u32(record + 60u);
    size_x = end_x - start_x;
    start_y = r_u32(record + 52u);
    w_u32(record + 64u, size_x + 1u);
    w_u32(record + 68u, end_y - start_y + 1u);
    return 1u;
}

uint32 ob_exchange_callback_state(uint32 value)
{
    FUNCTION_MARKER(0x80064900u, "SLES_008.65");
    uint32 previous = r_u32(0x800772F8u);
    w_u32(0x800772F8u, value);
    return previous;
}
