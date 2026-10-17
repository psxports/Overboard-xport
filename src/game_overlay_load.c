#include "psx.h"
#include "game_signatures.h"
#include "native_runtime.h"

uint32 ob_game_80095494(void)
{
    FUNCTION_MARKER(0x80095494u, "GAME.BIN");
    w_u32(0x800C4DC0u, 0x800C4E08u);
    w_u32(0x800C4DC4u, 0u);
    w_u32(0x800C4E28u, 0u);
    w_u32(0x800C4E2Cu, 0x800C4DA0u);
    return 0x800C4E08u;
}
