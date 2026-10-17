#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800BAA14(uint32 time)
{
    FUNCTION_MARKER(0x800BAA14u, "GAME.BIN");
    uint32 countdown = r_u32(0x800C84D8u);
    if ((sint32)countdown <= 0)
    {
        uint32 result = countdown - 1u;
        w_u32(0x800C84D8u, result);
        return result;
    }
    uint32 object = r_u32(0x80077190u);
    w_u32(0x800C84D8u, 20u);
    uint32 count = r_u8(object + 2u);
    if (count == 0u) return count;
    uint32 index = 0u;
    do
    {
        uint32 record = r_u32(0x80077198u) + index * 16u;
        if (r_u8(record) == 3u && r_u8(record + 3u) != 0u)
        {
            uint32 deadline = r_u32(record + 8u);
            if (deadline != 0u && (sint32)time >= (sint32)deadline)
                ob_draft_unresolved_call(0x800BA234u, 3u, (index + 1u) & 255u, 255u, time);
        }
        object = r_u32(0x80077190u);
        count = r_u8(object + 2u);
        ++index;
    } while ((sint32)index < (sint32)count);
    return 0u;
}
