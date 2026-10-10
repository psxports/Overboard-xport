#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_800AD6E0(uint32 output, uint32 angle)
{
    FUNCTION_MARKER(0x800AD6E0u, "GAME.BIN");
    ob_rotate_matrix_rows14(0x800C5570u, (uint32)(sint32)(sint16)angle, output);
    return output;
}
