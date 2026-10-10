#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"

/* TODO Conditional dependencies retain literal fail-fast bridges until reached */
uint32 ob_game_800AE36C(uint32 descriptor, uint32 slot, uint32 time)
{
    FUNCTION_MARKER(0x800AE36Cu, "GAME.BIN");
    w_u32(0x800C5584u, descriptor);
    uint32 scaled = (descriptor - 0x800CBA00u) * 0xC4EC4EC5u;
    w_u32(0x800C8350u, (uint32)((sint32)scaled >> 3));
    uint32 object = ob_game_800BC3D8(r_u32(0x80083E34u), descriptor + 32u, time);
    if (object == 0u)
        return 0u;
    w_u16(object + 326u, slot);
    uint32 state = r_u32(descriptor + 100u);
    if (state != 16u)
        w_u32(object + 288u, state);
    else
    {
        uint32 type = r_u32(descriptor + 96u);
        if (type == 224u)
        {
            uint32 random = ob_draft_unresolved_call(0x8001AFC8u, 0u);
            w_u32(descriptor + 60u, (uint32)((sint32)random / 64) - 256u);
            random = ob_draft_unresolved_call(0x8001AFC8u, 0u);
            w_u32(descriptor + 64u, (uint32)((sint32)random / 64) - 256u);
            w_u16(descriptor + 50u, 256u);
        }
        else if (type == 238u)
        {
            uint32 random = ob_draft_unresolved_call(0x8001AFC8u, 0u);
            w_u32(descriptor + 60u, (((random & 0x7FFFu) >> 8) - 64u) << 2);
            random = ob_draft_unresolved_call(0x8001AFC8u, 0u);
            w_u32(descriptor + 64u, (((random & 0x7FFFu) >> 8) - 64u) << 2);
        }
        switch (r_u32(descriptor + 96u))
        {
        case 3u: case 4u: case 10u:
        case 20u: case 21u: case 22u: case 23u: case 24u: case 25u:
        case 26u: case 27u: case 28u: case 29u: case 30u: case 31u:
        case 33u: case 36u: case 40u: case 48u: case 50u: case 52u:
        case 54u: case 56u: case 58u: case 60u: case 62u: case 64u:
        case 66u: case 70u: case 157u: case 158u: case 159u:
        case 162u: case 163u: case 165u: case 172u: case 173u:
        case 235u: case 236u: case 243u: case 244u: case 245u: case 246u:
        {
            uint32 bounds = ob_draft_unresolved_call(0x800C1094u, 2u,
                r_u32(r_u32(object + 48u) + 40u), 0x80066144u);
            sint32 lower = r_s16(bounds + 66u);
            sint32 upper = r_s16(bounds + 70u);
            uint32 height = (uint32)(sint32)(sint16)((lower + upper) / 2);
            ob_draft_unresolved_call(0x800B9260u, 3u, r_u32(object + 44u), height, time);
            break;
        }
        default:
            break;
        }
    }
    w_u8(descriptor + 92u, 2u);
    w_u32(descriptor + 80u, object);
    if ((r_u8(object + 324u) & 2u) != 0u)
        ob_draft_unresolved_call(0x800A9188u, 3u, object, r_u32(descriptor), time);

    uint32 type = r_u32(descriptor + 96u);
    switch (type)
    {
    case 49u: case 51u: case 53u: case 55u: case 57u: case 59u:
    case 61u: case 63u: case 65u: case 67u: case 69u: case 71u: case 73u:
        if (r_u8(descriptor + 93u) == 1u && r_u32(object + 64u) != 0u)
            sub_80045F20(object + 64u);
        break;
    case 4u:
        ob_draft_unresolved_call(0x80091F3Cu, 3u, object, 0u, time);
        w_u32(object + 28u, time);
        break;
    case 224u:
    case 238u:
    {
        if (type == 224u)
        {
            uint32 shape = r_u32(object + 48u);
            uint32 height = r_u16(descriptor + 50u);
            w_u16(shape + 160u, height);
            shape = r_u32(object + 48u);
            ob_draft_unresolved_call(0x8009E750u, 3u, object,
                (uint32)(sint32)r_s16(shape + 160u), time);
            uint32 child = r_u32(object + 136u);
            if (child != 0u)
                sub_800440B8(r_u32(child + 48u),
                    (uint32)(sint32)r_s16(r_u32(object + 48u) + 160u));
        }
        uint32 velocity = ob_draft_scratch_acquire(12u);
        uint32 x = r_u32(0x8008E590u);
        uint32 y = r_u32(0x8008E594u);
        uint32 z = r_u32(0x8008E598u);
        w_u32(velocity, x);
        w_u32(velocity + 4u, y);
        w_u32(velocity + 8u, z);
        w_u32(velocity, r_u32(descriptor + 60u));
        w_u32(velocity + 8u, r_u32(descriptor + 64u));
        sub_80045A7C(r_u32(object + 44u), time);
        sub_80045A44(r_u32(object + 44u), velocity);
        sub_80045B74(r_u32(object + 44u));
        w_u32(object + 28u, time);
        ob_draft_scratch_release(velocity);
        break;
    }
    case 158u:
    {
        uint32 record = ob_draft_unresolved_call(0x800A0D38u, 1u, object);
        uint32 index = r_u8(record + 27u);
        uint32 resources = r_u32(object + 112u);
        uint32 enabled = index != 0u && r_u8(r_u32(0x80077198u) + (index << 4) - 13u) != 0u;
        uint32 shape = r_u32(object + 48u);
        uint32 model = r_u32(resources + (enabled ? 20u : 16u));
        w_u32(shape + 40u, model);
        break;
    }
    case 162u:
    {
        uint32 record = ob_draft_unresolved_call(0x800A0D38u, 1u, object);
        uint32 index = r_u8(record + 27u);
        if (index != 0u && r_u8(r_u32(0x80077198u) + (index << 4) - 13u) != 0u)
        {
            uint32 node = (uint32)sub_800437C4(r_u32(r_u32(object + 44u) + 12u), 0x10086);
            uint32 matrix = ob_draft_unresolved_call(0x8004545Cu, 2u, node, time);
            sub_80029E80(0xFFFF8000u, matrix);
            sub_80045B74(node);
        }
        break;
    }
    case 163u:
    {
        uint32 record = ob_draft_unresolved_call(0x800A0D38u, 1u, object);
        uint32 index = r_u8(record + 27u);
        if (index == 0u || r_u8(r_u32(0x80077198u) + (index << 4) - 13u) == 0u)
            break;
        uint32 attributes = r_u32(object + 108u);
        uint32 node = (uint32)sub_800437C4(r_u32(r_u32(object + 44u) + 12u), 0x1007B);
        sub_80045A7C(node, time);
        uint32 matrix = ob_draft_scratch_acquire(18u);
        sub_80029E80(0xFFFF8000u, matrix);
        sub_80045848(node, matrix);
        w_u16(attributes + 10u, 0x8000u);
        node = (uint32)sub_800437C4(r_u32(r_u32(object + 44u) + 12u), 0x1007C);
        sub_80045A7C(node, time);
        index = r_u8(record + 27u);
        uint32 entry = r_u32(0x80077198u) + (index << 4) - 16u;
        uint32 duration = (uint32)r_u8(entry + 7u) * 500u;
        if (duration == 0u)
            return ob_native_missing_value(0x800AE36Cu, "BREAK 7 actor duration division by zero");
        uint32 rate = (uint32)((sint32)0xFF9C0258u / (sint32)duration);
        uint32 remaining = duration - (r_u32(entry + 8u) - time);
        uint32 numerator = (uint32)((sint32)remaining / 1000) << 16;
        sint32 denominator = (sint32)duration / 1000;
        if (denominator == 0)
            return ob_native_missing_value(0x800AE36Cu, "BREAK 7 actor phase division by zero");
        if (denominator == -1 && numerator == 0x80000000u)
            return ob_native_missing_value(0x800AE36Cu, "BREAK 6 actor phase division overflow");
        uint32 phase = (uint32)((sint32)numerator / denominator);
        uint32 animation = ob_draft_unresolved_call(0x800A9D9Cu, 4u, node, 0u, rate, 0u);
        w_u32(attributes + 16u, animation);
        w_u16(animation + 26u, 0u - phase);
        uint32 voice = ob_draft_unresolved_call(0x80011A24u, 6u,
            0x800683CCu, 255u, 256u, r_u32(object + 44u), time, 1u);
        uint32 artic = r_u32(object + 44u);
        w_u16(object + 306u, voice);
        w_u8(object + 341u, 255u);
        sub_80045B74(artic);
        ob_draft_scratch_release(matrix);
        break;
    }
    default:
        if ((type == 2u || (type >= 20u && type < 32u)) && r_u32(object + 288u) == 3u)
        {
            if (r_u32(object + 64u) != 0u)
                sub_80045F20(object + 64u);
            w_u8(r_u32(object + 60u) + 54u, 1u);
            uint32 matrix = ob_draft_unresolved_call(0x8004545Cu, 2u, r_u32(object + 44u), time);
            uint32 random = ob_draft_unresolved_call(0x8001AFC8u, 0u);
            sub_80029E80((random & 0x1FFFu) + 4096u, matrix);
            sub_80045848(r_u32(object + 44u), matrix);
            uint32 position = ob_draft_scratch_acquire(12u);
            sub_800453C4(r_u32(object + 44u), time, position);
            w_u32(position + 4u, 0xFFFFF600u);
            sub_800458B4(r_u32(object + 44u), position, time);
            sub_80045B74(r_u32(object + 44u));
            sub_80046544(r_u32(object + 52u));
            ob_draft_unresolved_call(0x8004E66Cu, 1u, r_u32(r_u32(object + 136u) + 60u));
            ob_draft_unresolved_call(0x800AC338u, 1u, object);
            ob_draft_scratch_release(position);
        }
        break;
    }
    if ((ob_game_800A0D10(descriptor + 32u) & 1u) != 0u)
        ob_game_800AEF70(descriptor);
    return object;
}
