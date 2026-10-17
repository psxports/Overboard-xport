#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_8008FFE0(uint32 object, uint32 attributes, uint32 descriptor)
{
    FUNCTION_MARKER(0x8008FFE0u, "GAME.BIN");
    w_u32(attributes + 32u, r_u16(descriptor));
    w_u32(attributes + 36u, r_u32(descriptor + 4u));
    w_u32(attributes + 40u, r_u32(descriptor + 8u));
    w_u32(attributes + 44u, r_u32(descriptor + 12u));
    w_u32(attributes + 52u, r_u32(descriptor + 16u));
    w_u32(attributes + 56u, r_u32(descriptor + 20u));
    w_u32(attributes + 48u, r_u32(descriptor + 24u));
    w_u32(attributes + 60u, r_u32(descriptor + 28u));
    w_u32(attributes + 68u, r_u32(descriptor + 32u));
    uint32 flags = r_u32(descriptor + 36u);
    w_u32(attributes + 72u, object);
    w_u32(attributes + 76u, 0u);
    w_u32(attributes + 64u, flags);
    uint32 result = r_u32(r_u32(object + 44u) + 8u);
    w_u32(attributes + 4u, result);
    return result;
}
