#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_800B9E84(uint32 object)
{
    FUNCTION_MARKER(0x800B9E84u, "GAME.BIN");
    w_u32(object + 160u, 0u);
    w_u32(object + 164u, 0u);
    uint32 result = ob_draft_unresolved_call(0x80063FE8u, 0u);
    w_u32(object + 156u, result);
    return result;
}
