#include "batch8_frontier.h"
#include "batch5_frontier.h"
#include <stdint.h>

uint32 ob_file_finish_request(void)
{
    FUNCTION_MARKER(0x80054AE0u, "SLES_008.65");
    uint32 count = r_u32(0x8008969Cu);
    if ((int32_t)count > 0)
    {
        count = r_u32(0x8008969Cu);
        w_u32(0x8008969Cu, count - 1u);
        (void)r_u32(0x8008969Cu);
    }
    uint32 request = r_u32(0x8007FE28u);
    w_u32(request + 12u, 0u);
    w_u32(request + 16u, 0u);
    return request;
}

static void ob_update_button_flag(uint32 flag, uint32 bits, uint32 mask)
{
    if ((bits & mask) != 0u)
        w_u8(flag, r_u8(flag) & 0xFEu);
    else
    {
        uint32 state = r_u8(flag);
        if ((state & 1u) == 0u)
            w_u8(flag, state | 0x20u);
        state = r_u8(flag);
        w_u8(flag, state | 3u);
    }
}

static void ob_update_controller_port(uint32 input, uint32 flags)
{
    if (r_u8(input) != 0u)
        return;
    uint32 type = r_u8(input + 1u) >> 4u;
    if (type == 4u)
    {
        uint32 bits = r_u16(input + 2u);
        for (uint32 index = 0u, mask = 1u; index < 16u; ++index, mask <<= 1u)
            ob_update_button_flag(flags + index, bits, mask);
    }
    else if (type == 8u)
    {
        for (uint32 group = 0u; group < 4u; ++group)
        {
            uint32 present = r_u8(input + 2u + group * 8u);
            uint32 bits = r_u16(input + 4u + group * 8u);
            if (present != 0xFFu)
                for (uint32 index = 0u, mask = 1u; index < 16u; ++index, mask <<= 1u)
                    ob_update_button_flag(flags + group * 16u + index, bits, mask);
        }
    }
}

uint32 ob_update_controller_flags(void)
{
    FUNCTION_MARKER(0x80053E2Cu, "SLES_008.65");
    ob_update_controller_port(0x8008CB28u, 0x8007FA00u);
    ob_update_controller_port(0x8008CE90u, 0x8007FA40u);
    uint32 request = r_u32(0x80084440u);
    w_u32(request + 12u, 0u);
    w_u32(request + 16u, 0u);
    return request;
}

uint32 ob_file_seek(uint32 index, uint32 offset, uint32 origin)
{
    FUNCTION_MARKER(0x800551F8u, "SLES_008.65");
    if (index >= 3u)
        return 0xFFFFFFFFu;
    uint32 record = 0x80089908u + (index << 4u);
    if ((r_u32(record) & 1u) == 0u)
        return 0xFFFFFFFFu;
    if (origin == 0u)
        w_u32(record + 4u, offset);
    else if (origin == 1u)
        w_u32(record + 4u, offset + r_u32(record + 4u));
    else if (origin == 2u)
        w_u32(record + 4u, offset + r_u32(record + 12u));
    return r_u32(record + 4u);
}

uint32 ob_memory_unlock_handle(uint32 handle, uint32 flags)
{
    FUNCTION_MARKER(0x800267C4u, "SLES_008.65");
    uint32 payload = r_u32(handle);
    return ob_memory_unlock_block(payload - 40u, flags & 0xFFu);
}
