#include "psx.h"
#include "xport.h"
#include "game_signatures.h"

uint32 ob_game_800A0CB0(void)
{
    FUNCTION_MARKER(0x800A0CB0u, "GAME.BIN");
    sint16 slot = -1;
    for (uint32 index = 0u; index < 400u; ++index)
    {
        if (r_u32(0x800CBA60u + index * 104u) == 0u)
        {
            slot = (sint16)index;
            break;
        }
    }
    w_u16(0x800C9AB4u, (uint16)slot);
    return (uint32)(sint32)slot;
}
