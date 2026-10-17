#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_8009949C(uint32 object, uint32 mode)
{
    FUNCTION_MARKER(0x8009949Cu, "GAME.BIN");
    uint32 physics = r_u32(object + 116u);
    w_u32(physics + 56u, 27500u);
    w_u32(physics + 60u, 11000u);
    w_u32(physics + 64u, 500u);
    w_u16(physics + 106u, 32000u);
    w_u16(physics + 108u, 3000u);
    w_u8(physics, 0u);
    w_u8(physics + 1u, 0u);
    for (uint32 index = 0u; index < 8u; ++index)
        w_u8(physics + index + 3u, 0u);
    w_u8(physics, mode);
    w_u8(physics + 1u, mode);
    w_u8(physics + 99u, 100u);
    return 100u;
}
