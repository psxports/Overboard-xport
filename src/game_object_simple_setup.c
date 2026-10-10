#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_800C0DD4(uint32 object)
{
    FUNCTION_MARKER(0x800C0DD4u, "GAME.BIN");
    sub_80045A44(r_u32(object + 44u), 0x8006C160u);
    sub_80045ADC(r_u32(object + 44u));
    for (uint32 offset = 136u; offset <= 140u; offset += 4u)
    {
        uint32 child = r_u32(object + offset);
        if (child != 0u)
        {
            sub_80045A44(r_u32(child + 44u), 0x8006C160u);
            child = r_u32(object + offset);
            sub_80045ADC(r_u32(child + 44u));
        }
    }
    uint32 child = r_u32(object + 144u);
    if (child == 0u)
        return child;
    sub_80045A44(r_u32(child + 44u), 0x8006C160u);
    child = r_u32(object + 144u);
    return sub_80045ADC(r_u32(child + 44u));
}
