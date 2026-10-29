#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"
#include "native_extra_signatures.h"
#include "decomp_208_signatures.h"

void ob_game_800B45F4(uint32 object)
{
    FUNCTION_MARKER(0x800B45F4, "GAME.BIN");
    ob_game_800b45fc(object, r_u32(0x800C8300));
}

uint32 ob_game_800b45fc(uint32 object, uint32 flags)
{
    FUNCTION_MARKER(0x800B45FC, "GAME.BIN");
    uint32 position = r_u32(object + 124);
    sint32 angle;
    uint32 magnitude;
    if (flags & 8)
    {
        angle = r_s16(position + 4);
        magnitude = angle < 0 ? (uint32)-angle : (uint32)angle;
    }
    else
    {
        uint32 reference_position = r_u32(0x80077428);
        angle = r_s16(position + 4);
        sint32 reference = r_s16(reference_position);
        sint32 difference = angle - reference;
        magnitude = difference < 0 ? (uint32)-difference : (uint32)difference;
    }
    if ((sint16)magnitude >= 16385)
        magnitude = 0xFFFF8000u - magnitude;
    sint32 folded = (sint16)magnitude;
    uint32 scene;
    uint32 model;
    uint32 scale = 500;
    uint32 result;
    if (r_u32(object + 292) == 255)
    {
        scene = r_u32(r_u32(object + 140) + 48);
        uint32 model_address = folded < 4608 ? 0x800C5A74 :
                               folded < 8704 ? 0x800C5A70 : 0x800C5A6C;
        model = r_u32(model_address);
        result = folded < 8704;
        ob_main_80044080(scene, model);
    }
    else
    {
        uint32 attachment = r_u32(object + 136);
        uint32 parameters = r_u32(object + 108);
        scene = r_u32(attachment + 48);
        sint32 selector = r_s8(parameters + 26);
        if (selector == 4)
        {
            model = r_u32(0x800C5A7C);
            ob_main_80044080(scene, model);
            if (folded >= 4608)
                scale = folded < 8704 ? 550 : 600;
            result = folded < 8704;
        }
        else
        {
            if (folded >= 4608)
                selector = r_s8(parameters + (folded < 8704 ? 27 : 28));
            result = (uint32)selector << 2;
            model = r_u32(0x800C5A6C + result);
            ob_main_80044080(scene, model);
        }
    }
    sub_800440B8(scene, scale);
    return result;
}
