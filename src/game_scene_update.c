#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

void ob_game_800A2D74(uint32 time)
{
    FUNCTION_MARKER(0x800A2D74u, "GAME.BIN");
    uint32 object = r_u32(0x800C8358u);
    if (object == 0u) return;
    uint32 x = r_u32(0x800C84E0u);
    uint32 z = r_u32(0x800C84E8u);
    if ((x | z) == 0u) return;
    sub_800458B4(r_u32(object + 44u), 0x800C84E0u, time);
    object = r_u32(0x800C8358u);
    uint32 type = r_u32(object + 292u);
    if (type == 32u)
    {
        w_u8(object + 339u, 5u);
        object = r_u32(0x800C8358u);
        w_u32(object + 332u, time);
    }
    else
    {
        uint32 properties = ob_game_800901FC(type, 0u);
        object = r_u32(0x800C8358u);
        uint32 state = r_u32(properties + 20u);
        w_u32(object + 288u, state);
    }
}
