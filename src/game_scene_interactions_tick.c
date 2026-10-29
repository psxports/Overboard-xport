#include "decomp_208_signatures.h"
#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800BA1C8(void)
{
    FUNCTION_MARKER(0x800BA1C8u, "GAME.BIN");
    return ob_game_800ba1d0(r_u32(0x80077190u));
}
