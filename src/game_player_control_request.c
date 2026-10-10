#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800B0768(uint32 object, uint32 input_word, uint32 time)
{
    FUNCTION_MARKER(0x800B0768u, "GAME.BIN");
    uint32 state = r_u32(object + 288u);
    if (state == 3u) return 3u;
    if (state == 20u || state == 22u) return 22u;
    uint32 request = sub_80043B68(object);
    w_u32(request + 36u, 0x800B07E4u);
    w_u32(request + 28u, time);
    w_u32(request + 32u, input_word);
    w_u32(request + 24u, 1u);
    return sub_80045EF4(request);
}
