#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_80093D84(void)
{
    FUNCTION_MARKER(0x80093D84u, "GAME.BIN");
    uint32 demo = r_u8(0x8006C233u);
    if (demo != 0u) return demo;
    if (sub_80054440(0u) == 0u) return 1u;
    if (r_u8(0x8006C230u) != 1u) return 0x55550000u;
    sint32 next = (sint32)(r_u32(0x800C4D18u) + 1u);
    sint32 index = next % 3;
    w_u32(0x800C4D18u, (uint32)index);
    return ob_game_80093D00((uint32)index);
}
