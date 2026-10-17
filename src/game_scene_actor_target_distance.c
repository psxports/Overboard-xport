#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_80097578(uint32 object, uint32 target_record, uint32 time)
{
    FUNCTION_MARKER(0x80097578u, "GAME.BIN");
    if (r_s16(target_record + 8u) == 0)
    {
        uint32 player = r_u32(0x8006C138u);
        sub_80045A7C(r_u32(player + 44u), time);
        player = r_u32(0x8006C138u);
        sub_80045378(r_u32(player + 44u), time, target_record + 12u);
    }
    uint32 attributes = r_u32(object + 116u);
    uint32 position = ob_draft_scratch_acquire(12u);
    sub_80045378(r_u32(object + 44u), time, position);
    uint32 x = r_u32(position);
    uint32 y = r_u32(position + 4u);
    uint32 z = r_u32(position + 8u);
    w_u32(attributes + 20u, x);
    w_u32(attributes + 24u, y);
    w_u32(attributes + 28u, z);
    uint32 target_x = r_u32(target_record + 12u);
    uint32 target_y = r_u32(target_record + 16u);
    uint32 target_z = r_u32(target_record + 20u);
    (void)target_y;
    uint32 heading = (r_u16(attributes + 104u) & 1u) != 0u
        ? r_u16(object + 296u) : r_u16(r_u32(object + 124u) + 4u);
    uint32 angle = ob_draft_scratch_acquire(2u);
    uint32 distance = ob_draft_scratch_acquire(4u);
    sub_80028280((sint32)(target_z - z), (sint32)(target_x - x), angle, distance);
    uint32 angle_value = r_u16(angle);
    uint32 distance_value = r_u32(distance);
    w_u16(target_record, angle_value - heading);
    w_u32(target_record + 4u, distance_value);
    w_u16(attributes + 82u, r_u32(attributes + 56u) >= distance_value ? 1u : 0u);
    uint32 result = (uint32)(sint32)r_s16(target_record + 8u);
    if (result == 0u)
    {
        w_u16(attributes + 44u, r_u16(0x800C90F8u));
        result = r_u32(0x800C90FCu);
        w_u32(attributes + 48u, result);
    }
    ob_draft_scratch_release(distance);
    ob_draft_scratch_release(angle);
    ob_draft_scratch_release(position);
    return result;
}
