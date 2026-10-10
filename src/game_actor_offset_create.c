#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"

uint32 ob_game_80096244(uint32 owner, uint32 record, uint32 output,
    uint32 distance, uint32 context)
{
    FUNCTION_MARKER(0x80096244u, "GAME.BIN");
    uint32 x = r_u32(record);
    uint32 y = r_u32(record + 4u);
    uint32 z = r_u32(record + 8u);
    w_u32(output, x);
    w_u32(output + 4u, y);
    w_u32(output + 8u, z);
    w_u16(output + 16u, r_u16(record + 16u));
    w_u16(output + 18u, r_u16(record + 18u));
    uint32 type = r_u32(record + 12u);
    w_u16(output + 22u, 0u);
    w_u32(output + 12u, 231u);
    w_u16(output + 20u, type);
    uint32 object = ob_game_800BC3D8(owner, output, context);
    uint32 offset = ((r_u16(output + 16u) + 8u) >> 4) << 1;
    uint32 sine = r_u16(0x8006C304u + offset);
    uint32 dx = distance * (uint32)((sint32)(sine << 16) >> 30);
    uint32 cosine = r_u16(0x8006CB04u + offset);
    uint32 dz = distance * (uint32)((sint32)(cosine << 16) >> 30);
    w_u32(0x800C8490u, object);
    w_u32(output + 12u, r_u32(record + 12u));
    x = r_u32(output);
    w_u32(output, x - (uint32)(sint32)(sint16)dx);
    z = r_u32(output + 8u);
    w_u32(output + 8u, z - (uint32)(sint32)(sint16)dz);
    w_u16(output + 20u, r_u16(record + 20u));
    return output;
}
