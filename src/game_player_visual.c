#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

void ob_game_800B47B0(uint32 object)
{
    FUNCTION_MARKER(0x800B47B0u, "GAME.BIN");
    uint32 attributes = r_u32(object + 108u);
    uint32 position = ob_draft_scratch_acquire(12u);
    uint32 matrix = ob_draft_scratch_acquire(18u);
    ob_copy_advanced_position(r_u32(object + 44u), r_u32(0x80077334u), position);
    w_u32(position + 4u, 0u);
    uint32 child = r_u32(object + 136u);
    sub_800458B4(r_u32(child + 44u), position, r_u32(0x80077334u));
    ob_y_angle_matrix14((uint32)(sint32)(sint16)r_u16(attributes + 48u), matrix);
    child = r_u32(object + 136u);
    sub_80045848(r_u32(child + 44u), matrix);
    sint32 value = (sint32)r_u32(r_u32(object + 124u));
    child = r_u32(object + 136u);
    sint32 quotient = value / 40;
    uint32 scale = (uint32)(sint32)(sint16)(300u - (uint32)quotient);
    sub_800440B8(r_u32(child + 48u), scale);
    ob_draft_scratch_release(matrix);
    ob_draft_scratch_release(position);
}
