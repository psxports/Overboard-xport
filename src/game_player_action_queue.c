#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"

uint32 ob_game_800B5BD8(uint32 slot, uint32 attributes, uint32 count, uint32 time)
{
    FUNCTION_MARKER(0x800B5BD8u, "GAME.BIN");
    slot &= 255u;
    uint32 deadline_address = attributes + slot * 4u + 96u;
    uint32 deadline = r_u32(deadline_address);
    count &= 255u;
    if ((sint32)time < (sint32)deadline || count == 0u)
        return deadline;
    uint32 index = r_u8(attributes + slot + 112u);
    w_u8(attributes + slot + 112u, (index + 1u) % count);
    w_u32(deadline_address, 0x7FFFFFFFu);
    return 0x7FFFFFFFu;
}
