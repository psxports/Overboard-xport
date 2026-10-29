#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"
#include "decomp_208_signatures.h"

uint32 ob_game_80093D84(void)
{
    FUNCTION_MARKER(0x80093D84, "GAME.BIN");
    return ob_game_80093d8c(r_u8(0x8006C233));
}

uint32 ob_game_80093d8c(uint32 demo)
{
    FUNCTION_MARKER(0x80093D8C, "GAME.BIN");
    if (demo)
        return demo;
    if (!sub_80054440(0))
        return 1;
    if (r_u8(0x8006C230) != 1)
        return 0x55550000;
    sint32 next = (sint32)(r_u32(0x800C4D18) + 1);
    sint32 index = next % 3;
    w_u32(0x800C4D18, index);
    return ob_game_80093D00(index);
}
