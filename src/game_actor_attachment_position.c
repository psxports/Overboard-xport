#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"

uint32 ob_game_8009696C(uint32 object, uint32 record, uint32 time, uint32 distance)
{
    FUNCTION_MARKER(0x8009696Cu, "GAME.BIN");
    uint32 type = r_u32(object + 292u);
    if (type == 149u)
        distance = 3350u;
    else if (type == 153u)
        distance = 3400u;
    uint32 x = r_u32(record);
    uint32 y = r_u32(record + 4u);
    uint32 z = r_u32(record + 8u);
    uint32 position = ob_draft_scratch_acquire(12u);
    w_u32(position, x);
    w_u32(position + 4u, y);
    w_u32(position + 8u, z);
    sint32 heading = r_s16(record + 16u);
    uint32 offset = (uint32)((sint32)(distance << 16) >> 15);
    if (heading == -16384)
        w_u32(position, x - offset);
    else if (heading == -32768)
        w_u32(position + 8u, z - offset);
    else if (heading == 0)
        w_u32(position + 8u, z + offset);
    else if (heading == 16384)
        w_u32(position, x + offset);
    sub_800458B4(r_u32(r_u32(object + 140u) + 44u), position, time);
    uint32 mode = r_u16(record + 18u);
    if (mode == 0u)
        w_u32(object + 288u, 13u);
    else if (mode == 1u)
        w_u32(object + 288u, 12u);
    if (r_u32(object + 288u) != 12u)
    {
        ob_draft_scratch_release(position);
        return 12u;
    }
    uint32 child = r_u32(r_u32(object + 108u));
    sub_80045A7C(r_u32(child + 44u), time);
    /* The original geometry helper never consumes its caller's time */
    sub_80046544(r_u32(child + 52u));
    uint32 child_position = ob_draft_scratch_acquire(12u);
    sub_800453C4(r_u32(child + 44u), time, child_position);
    heading = r_s16(record + 16u);
    if (heading == -16384)
        w_u32(child_position + 8u, r_u32(child_position + 8u) - 4000u);
    else if (heading == -32768)
        w_u32(child_position, r_u32(child_position) + 4000u);
    else if (heading == 0)
        w_u32(child_position, r_u32(child_position) - 4000u);
    else if (heading == 16384)
        w_u32(child_position + 8u, r_u32(child_position + 8u) + 4000u);
    sub_800458B4(r_u32(child + 44u), child_position, time);
    x = r_u32(record);
    y = r_u32(record + 4u);
    z = r_u32(record + 8u);
    /* TODO Bind the conditional attachment animation helper when reached */
    uint32 result = ob_draft_unresolved_call(0x80095DD4u, 5u, object, x, y, z, time);
    ob_draft_scratch_release(child_position);
    ob_draft_scratch_release(position);
    return result;
}
