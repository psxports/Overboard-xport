#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800BA1C8(void)
{
    FUNCTION_MARKER(0x800BA1C8u, "GAME.BIN");
    uint32 object = r_u32(0x80077190u);
    uint32 state = r_u8(object + 41u);
    if (state != 4u) return 4u;
    uint32 enabled = r_u32(0x8006C134u);
    if (enabled == 0u) return enabled;
    ob_draft_unresolved_call(0x8002192Cu, 1u, 0u);
    ob_draft_unresolved_call(0x80016E4Cu, 1u, 1u);
    return ob_draft_unresolved_call(0x80016D24u, 1u, 255u);
}
