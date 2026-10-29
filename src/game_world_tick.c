#include "decomp_208_signatures.h"
#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_800A9C30(uint32 time)
{
    FUNCTION_MARKER(0x800A9C30u, "GAME.BIN");
    return ob_game_800a9c38(time, r_u32(0x800C8308u));
}
