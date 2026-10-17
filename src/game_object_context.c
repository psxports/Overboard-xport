#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_800BD7E4(uint32 object, uint32 context)
{
    FUNCTION_MARKER(0x800BD7E4u, "GAME.BIN");
    uint32 properties = ob_draft_unresolved_call(0x800901FCu, 2u,
        r_u32(object + 292u), 0u);
    w_u32(object, r_u32(properties + 4u));
    uint32 data = r_u32(properties + 8u);
    uint32 result = ob_draft_unresolved_call(0x80095528u, 4u,
        object, data, 0x800BCAA0u, context);
    uint32 attachment = r_u32(object + 136u);
    if (attachment != 0u)
        result = ob_draft_unresolved_call(0x80095528u, 4u,
            attachment, data, 0x800BCA98u, context);
    attachment = r_u32(object + 140u);
    if (attachment != 0u)
        result = ob_draft_unresolved_call(0x80095528u, 4u,
            attachment, data, 0x800BCA98u, context);
    attachment = r_u32(object + 144u);
    if (attachment != 0u)
        result = ob_draft_unresolved_call(0x80095528u, 4u,
            attachment, data, 0x800BCA98u, context);
    return result;
}
