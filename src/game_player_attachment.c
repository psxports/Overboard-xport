#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800C05CC(uint32 object, uint32 geometry, uint32 context)
{
    FUNCTION_MARKER(0x800C05CCu, "GAME.BIN");
    uint32 model = sub_80044E5C(object, 0x80073660u, context);
    w_u32(object + 44u, model);
    uint32 shape = sub_80043E3C(object, 0x80073638u);
    model = r_u32(object + 44u);
    w_u32(object + 48u, shape);
    w_u32(model + 8u, 0x10000001u);
    w_u32(r_u32(object + 48u) + 48u, 0x10000001u);
    w_u32(r_u32(object + 48u) + 40u, geometry);
    ob_resolve_shape_links(r_u32(object + 48u));
    /* The incoming result is the shape pointer; a completed traversal returns zero */
    return 0u;
}
