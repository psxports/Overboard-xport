#include "psx.h"
#include "xport.h"
#include "game_signatures.h"

uint32 ob_game_800BD8AC(uint32 object)
{
    FUNCTION_MARKER(0x800BD8ACu, "GAME.BIN");
    uint32 definition = ob_game_800901FC(r_u32(object + 292u), 0u);
    uint32 result = r_u32(definition);
    w_u32(object + 112u, result);
    return result;
}
