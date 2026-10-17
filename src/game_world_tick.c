#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_800A9C30(uint32 time)
{
    FUNCTION_MARKER(0x800A9C30u, "GAME.BIN");
    uint32 result = r_u32(0x800C8308u);
    uint32 record = r_u32(0x800C546Cu);
    uint32 elapsed = time - result;
    uint32 matrix = ob_draft_scratch_acquire(24u);
    uint32 intermediate = ob_draft_scratch_acquire(24u);
    while (record != 0u)
    {
        result = r_u32(record + 8u);
        if (result != 0u)
        {
            sint32 x_product = (sint32)(r_u32(record + 12u) * elapsed);
            sint32 z_product = (sint32)(r_u32(record + 20u) * elapsed);
            sint32 y_product = (sint32)(r_u32(record + 16u) * elapsed);
            uint32 z_angle = (uint32)r_u16(record + 28u) + (uint32)(z_product / 100);
            uint32 x_angle = r_u16(record + 24u);
            w_u16(record + 28u, z_angle);
            w_u16(record + 24u, x_angle + (uint32)(x_product / 100));
            w_u16(record + 26u, (uint32)r_u16(record + 26u) + (uint32)(y_product / 100));
            sub_80029EEC((uint32)(sint16)z_angle, matrix);
            sub_8002A9DC(matrix, (uint32)r_s16(record + 24u), intermediate);
            sub_8002AF54(intermediate, (uint32)r_s16(record + 26u), matrix);
            result = (uint32)sub_80045848(r_u32(record + 4u), matrix);
        }
        record = r_u32(record);
    }
    w_u32(0x800C8308u, time);
    ob_draft_scratch_release(intermediate);
    ob_draft_scratch_release(matrix);
    return result;
}
