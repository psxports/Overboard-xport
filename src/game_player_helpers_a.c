#include "decomp_208_signatures.h"
#include "psx.h"
#include "game_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800BB3CC(void)
{
    FUNCTION_MARKER(0x800BB3CCu, "GAME.BIN");
    return ob_game_800bb3d4(r_u32(0x80077190u));
}

uint32 ob_game_800A55E4(void)
{
    FUNCTION_MARKER(0x800A55E4u, "GAME.BIN");
    return ob_game_800a55ec(r_u32(0x80077190u));
}
