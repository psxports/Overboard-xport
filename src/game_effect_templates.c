#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_extra_signatures.h"
#include "native_runtime.h"

uint32 ob_game_80090070(uint32 object, uint32 attributes, uint32 descriptor)
{
    FUNCTION_MARKER(0x80090070u, "GAME.BIN");
    uint32 value;
    w_u32(attributes, 0u);
    value = r_u32(descriptor + 0u);
    w_u32(attributes + 8u, value);
    value = r_u32(descriptor + 4u);
    w_u32(attributes + 12u, value);
    value = r_u32(descriptor + 8u);
    w_u32(attributes + 16u, value);
    value = r_u32(descriptor + 12u);
    w_u32(attributes + 20u, value);
    value = r_u32(descriptor + 16u);
    w_u32(attributes + 24u, value);
    value = r_u32(descriptor + 20u);
    w_u32(attributes + 28u, value);
    value = r_u32(descriptor + 24u);
    w_u16(attributes + 36u, 0u);
    w_u32(attributes + 40u, object);
    w_u32(attributes + 32u, value);
    value = r_u32(object + 276u) | 0x80000000u;
    w_u32(object + 276u, value);
    return value;
}

uint32 ob_game_800C0C88(uint32 object, uint32 attributes, uint32 descriptor, uint32 time)
{
    FUNCTION_MARKER(0x800C0C88u, "GAME.BIN");
    ob_game_80090070(object, attributes, descriptor);
    w_u32(attributes + 48u, 0x800A940Cu);
    w_u16(attributes + 38u, 0xFFFFu);
    w_u16(attributes + 36u, 0u);
    uint32 result = (uint32)sub_8004F074((sint32)object, (sint32)attributes, (sint32)time);
    w_u32(object + 56u, result);
    return result;
}

uint32 ob_game_800A940C(uint32 object, uint32 attributes, uint32 time)
{
    FUNCTION_MARKER(0x800A940Cu, "GAME.BIN");
    if (r_u32(attributes + 4u) == 1u)
    {
        sub_80045A7C(r_u32(object + 44u), time);
        sub_80045A44(r_u32(object + 44u), 0x8006C160u);
        uint32 type = r_u32(object + 292u);
        w_u32(object + 288u, 37u);
        if (type == 229u)
            ob_draft_unresolved_call(0x80011A24u, 6u,
                0x800660CCu, 255u, 256u, r_u32(object + 44u), time, 0u);
    }
    else
    {
        w_u8(r_u32(object + 60u) + 54u, 6u);
        sub_80045A7C(r_u32(object + 44u), time);
        sub_80045A44(r_u32(object + 44u), 0x8006C160u);
        uint32 position = sub_80045490(r_u32(object + 44u), time);
        w_u32(position + 4u, 0u);
        sub_800458B4(r_u32(object + 44u), position, time);
        uint32 type = r_u32(object + 292u);
        w_u32(object + 288u, 6u);
        if (type == 181u)
        {
            if (r_u32(object + 64u) != 0u)
                sub_80045F20(object + 64u);
            ob_game_800C0744(object, 0u, time);
        }
        else
        {
            sint32 size = r_s16(r_u32(object + 48u) + 160u) / 2;
            if (size < 50) size = 50;
            ob_game_800B89D8(r_u32(object + 44u), (uint32)size, time);
        }
        sub_8004F2C4(r_u32(object + 56u), 0);
        type = r_u32(object + 292u);
        if (type == 229u)
        {
            uint32 state = r_u32(r_u32(object + 108u) + 4u);
            if (state == 23u)
                ob_game_800C0744(object, 0u, time);
            else if (state == 17u)
                ob_draft_unresolved_call(0x8004659Cu, 2u, r_u32(object + 52u), time);
            uint32 target = 0x800CBA20u + (uint32)(sint32)r_s16(object + 326u) * 104u;
            uint32 x = r_u32(position);
            uint32 y = r_u32(position + 4u);
            uint32 z = r_u32(position + 8u);
            w_u32(target, x);
            w_u32(target + 4u, y);
            w_u32(target + 8u, z);
            type = r_u32(object + 292u);
        }
        if (type == 150u)
        {
            if (r_u32(object + 64u) != 0u)
                sub_80045F20(object + 64u);
            ob_game_800C0744(object, 0u, time);
        }
    }
    uint32 result = r_u32(attributes);
    w_u32(result + 96u, time);
    return result;
}

static void ob_player_contact_rebound(uint32 attributes, uint32 velocity_offset, uint32 recoil_offset, sint32 contact, sint32 minimum)
{
    uint32 sum = r_u32(attributes + velocity_offset) + r_u32(attributes + recoil_offset);
    uint32 recoil = 0u - (uint32)((sint32)(sum << 3u) / 5);
    uint32 magnitude = (sint32)recoil < 0 ? 0u - recoil : recoil;
    w_u32(attributes + recoil_offset, recoil);
    if ((sint32)magnitude >= 6001)
        w_u32(attributes + recoil_offset, (sint32)recoil > 0 ? 6000u : 0u - 6000u);
    recoil = r_u32(attributes + recoil_offset);
    magnitude = (sint32)recoil < 0 ? 0u - recoil : recoil;
    if ((sint32)magnitude < minimum)
        w_u32(attributes + recoil_offset, contact < 0 ? (uint32)minimum : 0u - (uint32)minimum);
    recoil = r_u32(attributes + recoil_offset);
    if ((contact < 0 && (sint32)recoil < 0) || (contact >= 0 && (sint32)recoil > 0))
        w_u32(attributes + recoil_offset, 0u - recoil);
}

uint32 ob_game_800B2150(uint32 object, uint32 contact_xy, uint32 contact_z, uint32 time, uint32 minimum)
{
    FUNCTION_MARKER(0x800B2150u, "GAME.BIN");
    uint32 attributes = r_u32(object + 108u);
    if (minimum == 0u) minimum = 2000u;
    if (r_u32(r_u32(object + 56u) + 96u) == time)
    {
        sub_80045A7C(r_u32(object + 44u), time);
        return sub_80045A44(r_u32(object + 44u), 0x8006C160u);
    }
    sint32 x = (sint16)contact_xy;
    sint32 y = (sint16)(contact_xy >> 16u);
    sint32 z = (sint16)contact_z;
    if (x != 0)
    {
        ob_player_contact_rebound(attributes, 52u, 68u, x, (sint32)minimum);
        uint32 player = r_u32(object + 124u);
        if (x < 0)
        {
            if (r_s16(player + 4u) < -16384)
                w_u16(player + 4u, r_u16(player + 4u) - (uint32)(r_s32(player) / 2));
            player = r_u32(object + 124u);
            if ((uint16)(r_u16(player + 4u) + 0x3FFFu) < 0x3FFFu)
                w_u16(player + 4u, r_u16(player + 4u) + (uint32)(r_s32(player) / 2));
        }
        else
        {
            if (r_u16(player + 4u) - 1u < 0x3FFFu)
                w_u16(player + 4u, r_u16(player + 4u) - (uint32)(r_s32(player) / 2));
            player = r_u32(object + 124u);
            if (r_s16(player + 4u) > 16384)
                w_u16(player + 4u, r_u16(player + 4u) + (uint32)(r_s32(player) / 2));
        }
        w_u16(attributes + 48u, r_u16(r_u32(object + 124u) + 4u) + r_u16(attributes + 80u));
    }
    if (y != 0)
    {
        uint32 position = ob_draft_scratch_acquire(12u);
        sub_800453C4(r_u32(object + 44u), time, position);
        sint32 vertical = r_s32(position + 4u);
        ob_draft_scratch_release(position);
        if (vertical > 0)
        {
            uint32 speed = r_u32(attributes + 56u);
            if ((sint32)speed < 0) speed = 0u - speed;
            sint32 rebound = (sint32)(speed * 6u) >> 3;
            w_u32(attributes + 56u, (uint32)rebound);
            if (rebound < 1000) w_u32(attributes + 56u, 1000u);
            if (r_s32(attributes + 56u) > 0 && r_u8(0x8008AE6Au) == 0u)
            {
                uint32 state = r_u32(object + 288u);
                if (state != 20u && state != 22u && ob_draft_unresolved_call(0x800A52C4u, 3u, object, 100u, 0xFFFFFFFFu))
                {
                    w_u32(attributes + 56u, 0u);
                    ob_draft_unresolved_call(0x800B9584u, 4u, r_u32(object + 44u), 1000u, 6u, time);
                    uint32 geometry = r_u32(object + 52u);
                    if (r_u32(geometry + 28u) == 0u)
                        ob_draft_unresolved_call(0x80046544u, 2u, geometry, time);
                    uint32 target = r_u32(attributes + 92u);
                    if (target != 0u)
                    {
                        ob_draft_unresolved_call(0x800BCAA0u, 1u, target);
                        w_u32(attributes + 92u, 0u);
                    }
                }
            }
        }
    }
    if (z != 0)
    {
        ob_player_contact_rebound(attributes, 60u, 76u, z, (sint32)minimum);
        uint32 player = r_u32(object + 124u);
        if (z < 0)
        {
            if (r_s16(player + 4u) > 16384)
                w_u16(player + 4u, (uint32)(sint32)r_s16(player + 4u) - (uint32)(r_s32(player) / 2));
            player = r_u32(object + 124u);
            if (r_s16(player + 4u) < -16384)
                w_u16(player + 4u, (uint32)(sint32)r_s16(player + 4u) + (uint32)(r_s32(player) / 2));
        }
        else
        {
            if (r_u16(player + 4u) - 1u < 0x3FFFu)
                w_u16(player + 4u, r_u16(player + 4u) + (uint32)(r_s32(player) / 2));
            player = r_u32(object + 124u);
            if ((uint16)(r_u16(player + 4u) + 0x3FFFu) < 0x3FFFu)
                w_u16(player + 4u, r_u16(player + 4u) - (uint32)(r_s32(player) / 2));
        }
        w_u16(attributes + 48u, r_u16(r_u32(object + 124u) + 4u) + r_u16(attributes + 80u));
    }
    sub_80045A7C(r_u32(object + 44u), time);
    ob_game_800B3AD0(object, attributes + 48u, attributes + 52u);
    ob_draft_unresolved_call(0x80011A24u, 6u, 0x80067228u,
        (uint32)(r_s32(r_u32(object + 124u)) / 60), 256u, r_u32(object + 44u), time, 0u);
    uint32 player = r_u32(object + 124u);
    uint32 result = (uint32)(r_s32(player) / 2);
    w_u32(player, result);
    return result;
}

uint32 ob_game_800B1F9C(uint32 object, uint32 attributes, uint32 time)
{
    FUNCTION_MARKER(0x800B1F9Cu, "GAME.BIN");
    if (r_u32(attributes + 4u) == 1u)
    {
        uint32 xy = r_u16(attributes + 12u) | (r_u16(attributes + 14u) << 16u);
        uint32 z = (time & 0xFFFF0000u) | r_u16(attributes + 16u);
        ob_game_800B2150(object, xy, z, time, 0u);
    }
    else
    {
        uint32 player_attributes = r_u32(object + 108u);
        uint32 position = ob_draft_scratch_acquire(12u);
        sub_800453C4(r_u32(object + 44u), time, position);
        w_u32(position + 4u, 0u);
        w_u32(player_attributes + 56u, 0u);
        sub_800458B4(r_u32(object + 44u), position, time);
        uint32 target = r_u32(player_attributes + 92u);
        if (target != 0u)
        {
            ob_draft_unresolved_call(0x800BCAA0u, 1u, target);
            w_u32(player_attributes + 92u, 0u);
        }
        if (r_u32(object + 288u) == 3u)
        {
            w_u8(r_u32(r_u32(object + 136u) + 60u) + 52u, 1u);
            w_u8(r_u32(r_u32(object + 140u) + 60u) + 52u, 1u);
        }
        else
        {
            sub_80045A7C(r_u32(object + 44u), time);
            ob_main_80045410(r_u32(object + 44u), position);
            w_u32(position + 4u, 0u);
            sub_80045A44(r_u32(object + 44u), position);
            ob_game_800B89D8(r_u32(object + 44u), 200u, time);
            sub_80011984(0x80067588u, 128u, 15u, 15u, 256u, 0u, 0u);
            uint32 model = r_u32(r_u32(object + 136u) + 60u);
            if (r_s8(model + 52u) != 0)
            {
                ob_draft_unresolved_call(0x8004E680u, 1u, model);
                ob_draft_unresolved_call(0x8004E680u, 1u, r_u32(r_u32(object + 140u) + 60u));
            }
        }
        ob_draft_scratch_release(position);
    }
    uint32 result = r_u32(attributes);
    w_u32(result + 96u, time);
    return result;
}

uint32 ob_game_800A0D38(uint32 object)
{
    FUNCTION_MARKER(0x800A0D38u, "GAME.BIN");
    sint32 index = r_s16(object + 326u);
    return index == -1 ? 0u : 0x800CBA20u + (uint32)index * 104u;
}

uint32 ob_game_800BB7DC(uint32 object, uint32 contact, uint32 time)
{
    FUNCTION_MARKER(0x800BB7DCu, "GAME.BIN");
    uint32 record = ob_game_800A0D38(object);
    if ((r_u32(contact + 28u) & 0x20u) != 0u && r_u32(contact + 24u) == 32u)
        ob_draft_unresolved_call(0x800BA234u, 3u, r_u8(record + 27u), 1u, time);
    return (uint32)sub_80047FF0(contact);
}
