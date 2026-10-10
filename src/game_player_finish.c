#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800C0744(uint32 object, uint32 value, uint32 context)
{
    FUNCTION_MARKER(0x800C0744u, "GAME.BIN");
    uint32 result = ob_game_800901FC(r_u32(object + 292u), 0u);
    uint32 properties = r_u32(result + 28u);
    if (properties != 0u)
    {
        result = r_u32(object + 64u);
        if (result == 0u)
        {
            w_u32(object + 100u, properties);
            w_u32(object + 96u, value);
            w_u32(object + 92u, context);
            result = ob_draft_unresolved_call(0x80045EF4u, 1u, object + 64u);
        }
    }
    return result;
}
