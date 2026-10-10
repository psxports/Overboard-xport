#include "psx.h"
#include "game_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800A309C(void)
{
    FUNCTION_MARKER(0x800A309Cu, "GAME.BIN");
    w_u32(0x800C90D0u, 0x800C8568u);
    w_u16(0x800C90F0u, 27u);
    w_u16(0x800C90F2u, 27u);
    w_u16(0x800C90F4u, 0x7FFFu);
    w_u16(0x800C90F6u, 0x7FFFu);
    w_u32(0x800C90D4u, 0u);
    for (uint32 index = 0u; index < 3u; ++index)
    {
        w_u32(0x800C90E4u + index * 4u, 0u);
        w_u32(0x800D5E98u + index * 4u, 0u);
    }
    w_u32(0x800C90DCu, 10000u);
    w_u32(0x800C90D8u, 0u);
    w_u32(0x800C90E0u, 0u - 5000u);
    return 0u - 5000u;
}
