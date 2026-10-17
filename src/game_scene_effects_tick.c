#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

void ob_game_800A1964(uint32 time)
{
    FUNCTION_MARKER(0x800A1964u, "GAME.BIN");
    uint32 node = r_u32(0x800C84F0u);
    while (node != 0u)
    {
        uint32 object = r_u32(node + 4u);
        // TODO Implement native bodies for A2C80 and A1D74
        if (ob_draft_unresolved_call(0x800A2C80u, 1u, r_u32(object + 108u)) != 0u)
            ob_draft_unresolved_call(0x800A1D74u, 2u, object, time);
        node = r_u32(node);
    }
}
