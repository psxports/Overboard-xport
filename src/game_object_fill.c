#include "psx.h"
#include "xport.h"
#include "game_signatures.h"

void ob_game_800C1068(uint32 destination, uint32 count, uint32 fill_byte)
{
    FUNCTION_MARKER(0x800C1068u, "GAME.BIN");
    /* The original zero-count result is undefined and the reached caller ignores it */
    for (uint32 index = 0u; index < count; ++index)
    {
        w_u8(destination, fill_byte);
        ++destination;
    }
}
