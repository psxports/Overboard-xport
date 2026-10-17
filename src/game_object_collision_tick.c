#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

void ob_game_800A5528(uint32 time)
{
    FUNCTION_MARKER(0x800A5528u, "GAME.BIN");
    uint32 remaining = 400u;
    uint32 offset = 0xA280u;
    do
    {
        uint32 object = r_u32(0x800CBA50u + offset);
        if (object != 0u)
        {
            switch (r_u32(object + 292u))
            {
            case 2u: case 3u: case 5u: case 11u:
            case 15u: case 16u: case 32u: case 33u:
            case 39u: case 41u: case 54u: case 56u:
            case 58u: case 64u: case 66u: case 74u:
            case 75u: case 156u: case 163u: case 164u:
            case 165u: case 169u: case 174u: case 175u:
            case 238u: case 239u: case 240u:
            {
                sint32 index = (sint16)r_u16(object + 306u);
                if (index != -1)
                {
                    /* TODO Bind the reached MAIN sound update body when required */
                    ob_draft_unresolved_call(0x80011E20u, 4u,
                        (uint32)index, r_u32(object + 44u), r_u8(object + 341u), time);
                }
                break;
            }
            default:
                break;
            }
        }
        --remaining;
        offset -= 104u;
    }
    while (remaining != 0u);
}
