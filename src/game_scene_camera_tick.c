#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_800944C4(uint32 time)
{
    FUNCTION_MARKER(0x800944C4u, "GAME.BIN");
    ob_game_80093E08(time);
    return (uint32)sub_80044DBC(0x800C4CFCu, 0x800D64A0u, 0x800C4D08u, (sint32)time);
}
