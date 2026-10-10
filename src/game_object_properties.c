#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_800901A8(uint32 resource)
{
    FUNCTION_MARKER(0x800901A8u, "GAME.BIN");
    uint32 properties = ob_draft_unresolved_call(0x800901FCu, 2u, resource, 0u);
    uint32 object = r_u32(properties);
    if (object != 0u)
    {
        uint32 geometry = r_u32(object + 4u);
        if (geometry != 0u)
            return r_u16(geometry + 12u);
    }
    return 0u;
}

uint32 ob_game_800A0D10(uint32 descriptor)
{
    FUNCTION_MARKER(0x800A0D10u, "GAME.BIN");
    uint32 properties = ob_draft_unresolved_call(0x800901FCu, 2u,
        r_u32(descriptor + 12u), 0u);
    return (uint32)(sint32)r_s16(properties + 16u);
}
