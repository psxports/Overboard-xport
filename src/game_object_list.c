#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_800AF07C(uint32 record)
{
    FUNCTION_MARKER(0x800AF07Cu, "GAME.BIN");
    uint32 resource = r_u32(record + 96u);
    if (resource < 235u)
    {
        if (resource >= 233u || resource == 168u)
            return 0u;
        if (resource >= 169u)
            return resource != 175u;
        return resource != 160u;
    }
    return resource != 237u && resource != 240u;
}

uint32 ob_game_800AEF70(uint32 record)
{
    FUNCTION_MARKER(0x800AEF70u, "GAME.BIN");
    uint32 result = ob_game_800AF07C(record) << 16;
    if (result != 0u)
    {
        uint32 previous = r_u32(0x800C84ECu);
        uint32 count = r_u16(0x800C8364u);
        w_u32(0x800C84ECu, record);
        result = count + 1u;
        w_u32(record + 76u, previous);
        w_u16(0x800C8364u, result);
    }
    return result;
}
