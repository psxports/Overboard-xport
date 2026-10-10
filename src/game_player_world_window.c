#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800A3134(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800A3134u, "GAME.BIN");
    uint32 position = ob_draft_scratch_acquire(12u);
    sub_80045378(r_u32(object + 44u), time, position);
    uint32 x = r_u32(position) - 1250u;
    sint32 relative_x = (sint32)(x + r_u32(0x80077458u));
    uint32 z = r_u32(position + 8u) + 1250u;
    sint32 relative_z = (sint32)(r_u32(0x80077468u) - z);
    w_u32(position, x);
    sint32 previous_x = r_s16(0x800C90F4u);
    w_u32(position + 8u, z);
    sint32 quotient_x = relative_x / 7500;
    sint32 quotient_z = relative_z / 7500;
    sint32 cell_x = (sint16)(uint16)quotient_x;
    sint32 cell_z = (sint16)(uint16)quotient_z;
    uint32 result;
    if (cell_x < previous_x + 1 && previous_x - 1 < cell_x)
    {
        sint32 previous_z = r_s16(0x800C90F6u);
        result = cell_z < previous_z + 1;
        if (result != 0u)
        {
            result = previous_z - 1 < cell_z;
            if (result != 0u)
            {
                ob_draft_scratch_release(position);
                return result;
            }
        }
    }
    uint32 origin = ob_draft_scratch_acquire(16u);
    x = r_u32(position);
    w_u16(0x800C90F6u, (uint32)quotient_z);
    uint32 window = r_u32(0x800C90D0u);
    w_u32(origin, x - 30000u);
    z = r_u32(position + 8u);
    w_u8(0x800D6492u, 0u);
    w_u16(0x800C90F4u, (uint32)quotient_x);
    /* Only the horizontal coordinates belong to the window input */
    w_u32(origin + 8u, z + 30000u);
    result = sub_8004C64C(origin, 9u, 9u, window);
    w_u32(0x800C90D4u, time);
    ob_draft_scratch_release(origin);
    ob_draft_scratch_release(position);
    return result;
}
