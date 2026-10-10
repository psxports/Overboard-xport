#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"

uint32 ob_game_800C0654(uint32 object, uint32 geometry, uint32 context)
{
    FUNCTION_MARKER(0x800C0654u, "GAME.BIN");
    ob_game_800C05CC(object, geometry, context);
    uint32 child = r_u32(object + 136u);
    if (child == 0u)
        return child;
    uint32 details = ob_game_800901FC(r_u32(object + 292u), 1u);
    uint32 flags = r_u8(details + 36u);
    uint32 resource = r_u32(details);
    if ((flags & 64u) == 0u)
    {
        child = r_u32(object + 136u);
        uint32 model = r_u32(resource + 12u);
        return ob_game_800C05CC(child, model, context);
    }
    child = r_u32(object + 136u);
    uint32 artic = r_u32(object + 44u);
    w_u32(child + 44u, artic);
    uint32 shape = sub_80043E3C(r_u32(object + 136u), 0x80073638u);
    child = r_u32(object + 136u);
    w_u32(child + 48u, shape);
    shape = r_u32(r_u32(object + 136u) + 48u);
    artic = r_u32(object + 44u);
    w_u32(shape + 52u, artic);
    shape = r_u32(r_u32(object + 136u) + 48u);
    w_u32(shape + 48u, 0x10000001u);
    shape = r_u32(r_u32(object + 136u) + 48u);
    uint32 model = r_u32(resource + 12u);
    w_u32(shape + 40u, model);
    return model;
}
