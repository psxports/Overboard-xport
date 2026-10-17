#include "psx.h"
#include "game_signatures.h"
#include "native_runtime.h"

void ob_game_80097524(uint32 slot, uint32 descriptor, uint32 context)
{
    FUNCTION_MARKER(0x80097524u, "GAME.BIN");
    w_u32(slot, 0u);
    w_u32(slot + 8u, context);
    if (descriptor != 0u)
        w_u16(slot + 4u, r_u16(descriptor + 16u));
    else
        w_u16(slot + 4u, 0u);
    w_u32(slot, 0u);
}
