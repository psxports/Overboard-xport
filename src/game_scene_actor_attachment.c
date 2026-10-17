#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_800916A0(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800916A0u, "GAME.BIN");
    uint32 child = r_u32(object + 136u);
    if (child == 0u)
        return child;
    uint32 position = ob_draft_scratch_acquire(12u);
    sub_800453C4(r_u32(object + 44u), time, position);
    if (r_u32(object + 292u) == 156u)
        w_u32(position + 4u, 0u);
    else
    {
        /* TODO Conditional ground-height helper retains its actual native call contract */
        sint32 height = (sint32)ob_draft_unresolved_call(0x800B50C4u, 4u,
            r_u32(position), r_u32(position + 4u), r_u32(position + 8u), time);
        w_u32(position + 4u, height < 0 ? 0u : (uint32)height);
    }
    child = r_u32(object + 136u);
    uint32 result = sub_800458B4(r_u32(child + 44u), position, time);
    ob_draft_scratch_release(position);
    return result;
}
