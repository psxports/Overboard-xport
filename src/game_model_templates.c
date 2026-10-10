#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_800C07BC(uint32 object, uint32 variant, uint32 target, uint32 source, uint32 context)
{
    FUNCTION_MARKER(0x800C07BCu, "GAME.BIN");
    uint32 properties = ob_draft_unresolved_call(0x800901FCu, 2u,
        r_u32(object + 292u), (uint32)(sint32)(sint16)variant);
    uint32 flags = r_u8(properties + 36u);
    uint32 model = r_u32(properties);
    if ((flags & 0x40u) == 0u)
        return ob_draft_unresolved_call(0x800C05CCu, 3u,
            target, r_u32(model + 12u), context);
    w_u32(target + 44u, r_u32(source + 44u));
    uint32 node = ob_draft_unresolved_call(0x80043E3Cu, 2u, target, 0x80073638u);
    w_u32(target + 48u, node);
    w_u32(node + 52u, r_u32(source + 44u));
    w_u32(r_u32(target + 48u) + 48u, 0x10000001u);
    uint32 current_node = r_u32(target + 48u);
    uint32 result = r_u32(model + 12u);
    w_u32(current_node + 40u, result);
    return result;
}
