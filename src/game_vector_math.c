#include "psx.h"
#include "game_signatures.h"
#include "native_runtime.h"

void ob_game_800C0F70(uint32 record, uint32 value, uint32 middle)
{
    FUNCTION_MARKER(0x800C0F70u, "GAME.BIN");
    w_u32(record + 8u, value);
    w_u32(record + 12u, middle);
    w_u32(record + 16u, value);
    w_u32(record + 20u, 0u);
    w_u32(record + 24u, 0u);
    w_u32(record + 28u, 0u);
}
