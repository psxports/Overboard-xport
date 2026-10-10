#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_80095528(uint32 object, uint32 data, uint32 callback, uint32 context)
{
    FUNCTION_MARKER(0x80095528u, "GAME.BIN");
    uint32 previous = r_u32(0x800C4E2Cu);
    w_u32(object + 32u, 0x800C4E08u);
    w_u32(object + 36u, previous);
    w_u32(0x800C4E2Cu, object);
    w_u32(previous + 32u, object);
    w_u32(object + 24u, data);
    w_u32(object + 44u, 0u);
    w_u32(object + 48u, 0u);
    w_u32(object + 52u, 0u);
    w_u32(object + 56u, 0u);
    w_u32(object + 60u, 0u);
    w_u32(object + 40u, callback);
    w_u32(object + 28u, context);
    ob_draft_unresolved_call(0x80043BACu, 2u, object + 64u, object);
    uint32 previous_count = r_u32(object + 76u);
    w_u32(object + 100u, 0u);
    w_u32(object + 96u, 0u);
    uint32 result = previous_count + 1u;
    w_u32(object + 76u, result);
    return result;
}
