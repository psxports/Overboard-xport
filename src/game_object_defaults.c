#include "psx.h"
#include "xport.h"
#include "game_signatures.h"

uint32 ob_game_800900E0(uint32 object)
{
    FUNCTION_MARKER(0x800900E0u, "GAME.BIN");
    uint32 type = r_u32(object + 292u);
    if (type == 229u) return 235u;
    if (type == 235u) return 230u;
    if (type == 230u) return 160u;
    if (type == 160u) return 242u;
    if (type == 242u) return 237u;
    if (type == 237u) return 240u;
    if (type == 240u || type == 254u) return 254u;
    uint32 resource = r_u32(object + 112u);
    if (resource == 0u)
        return 254u;
    uint32 result = r_u32(resource + 4u);
    if (result == 0u)
        return result;
    uint32 output = r_u32(object + 116u);
    if (output == 0u)
        return result;
    result = r_u32(result);
    w_u32(output + 56u, result);
    uint32 definition = r_u32(resource + 4u);
    output = r_u32(object + 116u);
    result = r_u32(definition + 4u);
    w_u32(output + 60u, result);
    definition = r_u32(resource + 4u);
    output = r_u32(object + 116u);
    result = r_u32(definition + 8u);
    w_u16(output + 106u, result);
    definition = r_u32(resource + 4u);
    output = r_u32(object + 116u);
    result = r_u16(definition + 14u);
    w_u16(output + 108u, result);
    return result;
}
