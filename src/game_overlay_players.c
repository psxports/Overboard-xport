#include "psx.h"
#include "xport.h"

uint32 ob_game_800AE0C4(void)
{
    FUNCTION_MARKER(0x800AE0C4u, "GAME.BIN");
    w_u32(0x800C82E8u, 0u);
    w_u16(0x800C5588u, 0u);
    w_u32(0x800C84ECu, 0u);
    w_u16(0x800C8364u, 0u);
    w_u32(0x800C855Cu, 399u);
    return 399u;
}
