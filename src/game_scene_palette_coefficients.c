#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"

uint32 ob_game_800C17F0(uint32 mode)
{
    FUNCTION_MARKER(0x800C17F0u, "GAME.BIN");
    uint32 enabled = r_u8(r_u32(0x80077190u) + 44u);
    if (enabled == 0u)
        return enabled;
    uint32 duration = r_u32(0x800C61F4u + (mode << 2));
    sint32 divisor = (sint16)duration;
    w_u16(0x800D6494u, duration);
    for (uint32 offset = 0u; offset < 36u; offset += 4u)
    {
        uint32 difference;
        uint32 first;
        uint32 second;
        switch (mode)
        {
        case 0u:
            first = r_u32(0x800C9910u + offset);
            second = r_u32(0x800C9A78u + offset);
            difference = first - second;
            break;
        case 2u:
            first = r_u32(0x800C9938u + offset);
            second = r_u32(0x800C9910u + offset);
            difference = first - second;
            break;
        case 4u:
            first = r_u32(0x800C9910u + offset);
            second = r_u32(0x800C9938u + offset);
            difference = first - second;
            break;
        case 6u:
            first = r_u32(0x800C9A78u + offset);
            second = r_u32(0x800C9910u + offset);
            difference = first - second;
            break;
        case 1u: case 3u: case 5u: case 7u:
            w_u32(0x800C6214u + offset, 0u);
            continue;
        default:
            continue;
        }
        if (divisor == 0)
            xport_mips_break(7u);
        if (divisor == -1 && difference == 0x80000000u)
            xport_mips_break(6u);
        w_u32(0x800C6214u + offset, (uint32)((sint32)difference / divisor));
    }
    return 0u;
}
