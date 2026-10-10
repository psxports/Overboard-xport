#include "psx.h"
#include "game_signatures.h"

uint32 ob_game_800C0868(uint32 kind)
{
    FUNCTION_MARKER(0x800C0868u, "GAME.BIN");
    sint32 value = (sint32)(sint16)kind;
    if (value == 100)
        value = r_s32(r_u32(0x800D6750u) + 4u) < 0 ? 1 : 6;
    else if (value == 101)
        value = 102;
    return (uint32)value;
}
