#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800A49A4(void)
{
    FUNCTION_MARKER(0x800A49A4u, "GAME.BIN");
    w_u16(0x800C8354u, 0u);
    /* TODO Bind the original GAME initialization helpers as their bodies become available */
    ob_draft_unresolved_call(0x800A0BE8u, 0u);
    ob_draft_unresolved_call(0x800BB3CCu, 0u);
    ob_draft_unresolved_call(0x800A4A98u, 0u);
    ob_draft_unresolved_call(0x800A4A34u, 0u);
    ob_draft_unresolved_call(0x800A4AC8u, 1u, (uint32)r_u8(0x800D6766u));
    ob_draft_unresolved_call(0x80092138u, 0u);
    ob_draft_unresolved_call(0x800A55E4u, 0u);
    uint32 result = r_u32(0x8006C218u);
    if (result != 0u)
    {
        uint32 count = 0u;
        do
        {
            ++count;
            ob_draft_unresolved_call(0x800BBEE0u, 0u);
            result = count < 10u;
        } while (result != 0u);
    }
    return result;
}
