#include "psx.h"
#include "game_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800B3A90(uint32 object, uint32 identifier)
{
    FUNCTION_MARKER(0x800B3A90u, "GAME.BIN");
    uint32 current = r_u32(r_u32(object + 48u) + 32u);
    while (r_u32(current + 8u) != identifier)
        current = r_u32(current + 28u);
    return current;
}
