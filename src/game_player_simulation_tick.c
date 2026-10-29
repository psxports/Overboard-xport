#include "decomp_208_signatures.h"
#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800BAA14(uint32 time)
{
    FUNCTION_MARKER(0x800BAA14u, "GAME.BIN");
    return ob_game_800baa1c(time, r_u32(0x800C84D8u));
}
