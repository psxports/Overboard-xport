#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"

uint32 ob_game_800B5C50(uint32 slot, uint32 attributes, uint32 time)
{
    FUNCTION_MARKER(0x800B5C50u, "GAME.BIN");
    slot &= 255u;
    uint32 index = r_u8(attributes + slot + 112u);
    uint32 deadline = r_u32(attributes + slot * 48u + index * 4u);
    return (sint32)deadline < (sint32)time;
}
