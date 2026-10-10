#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

void ob_game_800B45F4(uint32 object)
{
    FUNCTION_MARKER(0x800B45F4u, "GAME.BIN");
    uint32 flags = r_u32(0x800C8300u);
    sint32 angle = r_s16(r_u32(object + 124u) + 4u);
    uint32 magnitude;
    if ((flags & 8u) != 0u)
        magnitude = angle < 0 ? 0u - (uint32)angle : (uint32)angle;
    else
    {
        sint32 reference = r_s16(r_u32(0x80077428u));
        sint32 difference = (sint32)((uint32)angle - (uint32)reference);
        magnitude = difference < 0 ? 0u - (uint32)difference : (uint32)difference;
    }
    if ((sint16)magnitude >= 16385)
        magnitude = 0xFFFF8000u - magnitude;
    sint32 folded = (sint16)magnitude;
    uint32 scene;
    uint32 model;
    uint32 scale = 500u;
    if (r_u32(object + 292u) == 255u)
    {
        scene = r_u32(r_u32(object + 140u) + 48u);
        uint32 model_address = folded < 4608 ? 0x800C5A74u :
                               folded < 8704 ? 0x800C5A70u : 0x800C5A6Cu;
        model = r_u32(model_address);
    }
    else
    {
        uint32 attachment = r_u32(object + 136u);
        uint32 parameters = r_u32(object + 108u);
        scene = r_u32(attachment + 48u);
        sint32 selector = r_s8(parameters + 26u);
        if (selector == 4)
        {
            model = r_u32(0x800C5A7Cu);
            if (folded >= 4608)
                scale = folded < 8704 ? 550u : 600u;
        }
        else
        {
            if (folded >= 4608)
                selector = r_s8(parameters + (folded < 8704 ? 27u : 28u));
            model = r_u32(0x800C5A6Cu + (uint32)selector * 4u);
        }
    }
    ob_draft_unresolved_call(0x80044080u, 2u, scene, model);
    sub_800440B8(scene, scale);
}
