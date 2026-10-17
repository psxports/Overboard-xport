#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800BDE48(uint32 object, uint32 record, uint32 context)
{
    FUNCTION_MARKER(0x800BDE48u, "GAME.BIN");
    uint32 details = ob_game_800901FC(r_u32(object + 292u), 0u);
    uint32 mode = r_u8(details + 34u);
    /* TODO Bind the original GAME animation selection helpers */
    switch (mode)
    {
    case 1u:
        w_u8(object + 323u, 0u);
        w_u16(object + 320u, 2048u);
        /* Fall through to the record-selected animation */
    case 4u:
    {
        uint32 variant = ((uint32)r_u8(record + 24u) >> 4) & 3u;
        uint32 selection = r_u32(object + 120u);
        uint32 index = r_u8(details + 35u) + variant;
        ob_draft_unresolved_call(0x800B7DA8u, 2u, selection, index);
        break;
    }
    case 2u:
        ob_draft_unresolved_call(0x800B7C7Cu, 3u, r_u32(object + 120u), (uint32)r_u8(details + 35u), 0u);
        break;
    case 3u:
        ob_draft_unresolved_call(0x800B7DA8u, 2u, r_u32(object + 120u), (uint32)r_u8(details + 35u));
        break;
    case 5u:
    {
        uint32 player = r_u32(object + 108u);
        uint32 index = 0u;
        while (r_s8(player + index + 106u) == 0)
        {
            ++index;
            if (index >= 8u)
                break;
        }
        if (index < 8u)
        {
            ob_draft_unresolved_call(0x800B7C7Cu, 3u, r_u32(object + 120u), index, (uint32)(sint32)r_s8(player + index + 130u));
            w_u8(r_u32(object + 120u) + 135u, index);
            w_u8(player + 177u, index);
            uint32 angle = r_u16(0x800C5A80u + index * 2u);
            w_u16(player + 156u, angle);
            w_u16(player + 154u, angle);
            w_u16(player + 152u, angle);
        }
        else
        {
            ob_draft_unresolved_call(0x800B7C7Cu, 3u, r_u32(object + 120u), 0u, (uint32)(sint32)r_s8(player + 130u));
            w_u8(r_u32(object + 120u) + 135u, 0u);
            w_u8(player + 177u, 0u);
            uint32 angle = r_u16(0x800C5A80u);
            w_u16(player + 156u, angle);
            w_u16(player + 154u, angle);
            w_u16(player + 152u, angle);
        }
        break;
    }
    default:
        break;
    }
    uint32 object_type = r_u32(object + 292u);
    uint32 sound;
    uint32 volume = 255u;
    uint32 pitch = 256u;
    uint32 enabled = 1u;
    uint32 result = 255u;
    switch (object_type)
    {
    case 2u:
    {
        uint32 slot = ob_draft_unresolved_call(0x80011A24u, 6u, 0x80068F30u, 128u, 256u, r_u32(object + 44u), context, 1u);
        uint32 selection = r_u32(object + 120u);
        w_u16(object + 306u, slot);
        w_u8(selection + 114u, 1u);
        w_u8(r_u32(object + 120u) + 115u, 8u);
        return 8u;
    }
    case 3u:
        result = ob_draft_unresolved_call(0x80011A24u, 6u, 0x800660D0u, 128u, 256u, r_u32(object + 44u), context, 1u);
        w_u16(object + 306u, result);
        return result;
    case 11u: sound = 0x80068B30u; break;
    case 16u: sound = 0x80067254u; break;
    case 15u: case 56u: case 58u: sound = 0x8006725Cu; break;
    case 32u: sound = 0x8006A12Cu; break;
    case 174u: sound = 0x80069138u; break;
    case 238u: sound = 0x800697D4u; break;
    case 175u:
        sound = 0x80066434u;
        volume = 128u;
        pitch = 206u;
        result = 160u;
        break;
    case 229u: case 230u:
        sound = 0x80067224u;
        volume = 138u;
        enabled = 0u;
        result = 138u;
        break;
    case 255u:
        for (uint32 index = 0u; index < 12u; ++index)
            w_u32(r_u32(object + 120u) + index * 4u, 0u);
        for (uint32 index = 0u; index < 12u; ++index)
            w_u32(r_u32(object + 120u) + 48u + index * 4u, 0u);
        return 48u;
    default:
        if (object_type < 4u)
            return 2u;
        if (object_type < 16u)
            return 11u;
        if (object_type < 33u)
            return 16u;
        if (object_type < 59u)
            return 56u;
        if (object_type < 175u)
        {
            if (object_type == 156u)
                w_u16(r_u32(object + 108u) + 14u, 0xFFFFu);
            return 0xFFFFFFFFu;
        }
        if (object_type < 231u)
            return 175u;
        return 255u;
    }
    uint32 slot = ob_draft_unresolved_call(0x80011A24u, 6u, sound, volume, pitch, r_u32(object + 44u), context, enabled);
    if (enabled != 0u)
        w_u16(object + 306u, slot);
    w_u8(object + 341u, result);
    return result;
}
