#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"

/* TODO Conditional action helpers retain their real literal call contracts */
uint32 ob_game_800B5CB4(uint32 object, uint32 slot, uint32 angle, uint32 time)
{
    FUNCTION_MARKER(0x800B5CB4u, "GAME.BIN");
    uint32 spawned = 0u;
    uint32 side = 999u;
    uint32 weapon = r_u32(object + 120u);
    uint32 attributes = r_u32(object + 108u);
    uint32 type = r_u32(object + 292u);
    if (type == 255u)
    {
        uint32 index = (uint32)(sint32)r_s8(weapon + 137u);
        sint32 ammunition = r_s16(r_u32(object + 108u) + index * 2u + 120u);
        sint32 cost = r_s16(weapon + 126u);
        if (ammunition - cost < 0)
            return 0u;
        side = (sint32)r_u32(r_u32(object + 44u) + 84u) > 0;
    }
    /* The request contains semantic fields through its final halfword at112 */
    uint32 request = ob_draft_scratch_acquire(116u);
    w_u8(request + 48u, (slot & 255u) < 2u ? slot : 0u);
    w_u32(request + 56u, r_u32(object + 292u));
    uint32 actor_slot = (uint32)(sint32)r_s16(object + 326u);
    w_u32(request + 96u, 0x800CBA00u + actor_slot * 104u);
    uint32 magnitude = r_u16(weapon + 118u);
    w_u16(request + 84u, magnitude - 1u < 128u ? magnitude : 16u);
    sint32 kind = r_s8(weapon + 135u);
    w_u16(request + 86u, (uint32)kind);
    uint32 flags;
    if (r_u32(object + 292u) == 255u)
        flags = 1024u;
    else if ((uint16)(kind - 1) < 2u || kind == 10 || kind == 4)
        flags = 0x08000000u;
    else
        flags = 0x4000u;
    w_u32(request + 76u, flags);
    uint32 target = 0u;
    uint32 attach_owner = 0u;
    switch (kind)
    {
    case 0: case 1:
        w_u16(request + 50u, r_u16(weapon + 122u));
        w_u32(request + 44u, (uint32)(sint32)r_s16(weapon + 120u));
        w_u16(request + 60u, r_u16(weapon + 130u));
        w_u16(request + 84u, r_u16(weapon + 118u));
        target = 0x80094FFCu;
        break;
    case 2:
        w_u16(request + 50u, 0u);
        w_u32(request + 44u, (uint32)(sint32)r_s16(weapon + 120u));
        w_u16(request + 84u, r_u16(weapon + 118u));
        w_u16(request + 60u, r_u16(weapon + 130u));
        w_u16(request + 92u, r_u16(weapon + 122u));
        w_u32(request + 88u, (uint32)(sint32)r_s16(weapon + 124u));
        target = 0x800955F8u;
        attach_owner = 1u;
        break;
    case 3:
        w_u16(request + 50u, side == 999u ? r_u16(weapon + 122u) : side != 0u ? 0x4000u : 0xC000u);
        w_u32(request + 44u, (uint32)(sint32)r_s16(weapon + 120u));
        w_u16(request + 84u, (0u - r_u16(weapon + 118u)) & 0xDFFFu);
        w_u16(request + 60u, r_u16(weapon + 130u));
        w_u16(request + 92u, (uint32)(sint32)r_s16(weapon + 130u) << 3);
        w_u32(request + 88u, (uint32)(sint32)r_s16(weapon + 124u));
        target = 0x800A9720u;
        attach_owner = 1u;
        break;
    case 4:
        w_u16(request + 50u, 12288u);
        w_u32(request + 44u, (uint32)(sint32)r_s16(weapon + 120u));
        w_u16(request + 84u, r_u16(weapon + 118u));
        w_u16(request + 60u, r_u16(weapon + 130u));
        w_u16(request + 92u, (uint32)(sint32)r_s16(weapon + 130u) * 14u);
        w_u32(request + 88u, (uint32)(sint32)r_s16(weapon + 124u));
        target = 0x800A1258u;
        attach_owner = 1u;
        break;
    case 5:
        if ((r_u16(weapon + 130u) & 0x4000u) != 0u)
        {
            w_u16(request + 50u, 1u);
            w_u16(weapon + 130u, r_u16(weapon + 130u) & 0xBFFFu);
        }
        else
            w_u16(request + 50u, 0u);
        w_u32(request + 44u, (uint32)(sint32)r_s16(weapon + 120u));
        w_u16(request + 84u, r_u16(weapon + 118u));
        w_u16(request + 60u, r_u16(weapon + 130u));
        w_u16(request + 92u, r_u16(weapon + 122u));
        w_u32(request + 88u, (uint32)(sint32)r_s16(weapon + 124u));
        target = 0x800A5B44u;
        attach_owner = 1u;
        break;
    case 6:
        w_u16(request + 50u, side == 999u ? 2u : side != 0u);
        w_u16(request + 84u, r_u16(weapon + 118u));
        w_u16(request + 92u, r_u16(weapon + 122u));
        w_u16(request + 60u, r_u16(weapon + 130u));
        w_u32(request + 88u, (uint32)(sint32)r_s16(weapon + 124u));
        target = 0x8009F784u;
        break;
    case 7:
        w_u32(request + 76u, 0x10000000u);
        w_u16(request + 50u, 0xFFF0u);
        w_u32(request + 44u, (uint32)(sint32)r_s16(weapon + 120u));
        w_u32(request + 88u, (uint32)(sint32)r_s16(weapon + 124u));
        w_u16(request + 84u, r_u16(weapon + 118u));
        magnitude = r_u16(weapon + 130u);
        w_u16(request + 60u, 48u);
        w_u16(request + 92u, magnitude);
        w_u16(request + 112u, r_u16(object + 326u));
        actor_slot = (uint32)(sint32)r_s16(object + 326u);
        w_u16(request + 110u, r_u16(0x800CBA44u + actor_slot * 104u));
        target = 0x8009A7E8u;
        break;
    case 8:
        w_u16(request + 50u, 0u);
        w_u16(request + 60u, r_u16(weapon + 130u));
        w_u32(request + 88u, (uint32)(sint32)r_s16(weapon + 124u));
        w_u16(request + 84u, r_u16(weapon + 118u));
        w_u32(request + 44u, (uint32)(sint32)r_s16(weapon + 120u));
        target = 0x800B5904u;
        break;
    case 9: case 10: case 11: case 12:
        if (kind == 10)
        {
            w_u16(request + 50u, r_u16(weapon + 122u));
            w_u32(request + 44u, (uint32)(sint32)r_s16(weapon + 120u));
            w_u16(request + 84u, r_u16(weapon + 118u));
            w_u16(request + 60u, r_u16(weapon + 130u));
        }
        else
        {
            w_u32(request + 44u, (uint32)(sint32)r_s16(weapon + 120u));
            w_u16(request + 60u, r_u16(weapon + 130u));
            w_u16(request + 50u, r_u16(weapon + 122u));
            w_u16(request + 84u, r_u16(weapon + 118u));
        }
        w_u32(request + 88u, (uint32)(sint32)r_s16(weapon + 124u));
        target = kind == 9 ? 0x800AF798u : kind == 10 ? 0x8009A0C4u : kind == 11 ? 0x800AD720u : 0x800A2E24u;
        attach_owner = kind == 10;
        break;
    default:
        goto finished;
    }
    ob_game_800B762C( object, slot & 255u, request,
        (uint32)(sint32)(sint16)angle, time);
    if (kind == 2)
        w_u32(request + 36u, r_u32(request + 36u) - 200u);
    else if (kind == 4)
        w_u32(request + 36u, r_u32(request + 36u) + (uint32)(sint32)r_s16(weapon + 122u));
    else if (kind == 5)
        w_u32(request + 36u, r_u32(request + 36u) + 500u);
    spawned = ob_draft_unresolved_call(target, 3u, r_u32(object + 104u), request, time);
    if (spawned == 0u)
        goto finished;
    if (attach_owner != 0u)
    {
        w_u16(spawned + 120u, r_u16(object + 326u));
        actor_slot = (uint32)(sint32)r_s16(object + 326u);
        w_u16(spawned + 122u, r_u16(0x800CBA44u + actor_slot * 104u));
    }
    uint32 geometry = r_u32(spawned + 52u);
    if (geometry != 0u)
    {
        uint32 owner_geometry = r_u32(object + 52u);
        if (owner_geometry != 0u)
            sub_800465E8(geometry, owner_geometry);
    }
    ob_game_800B7C08(slot & 255u, r_u32(object + 120u), time);
    if (r_u32(object + 292u) != 255u)
        goto finished;
    for (;;)
    {
        uint32 index = (uint32)(sint32)r_s8(weapon + 137u);
        sint32 ammunition = r_s16(attributes + index * 2u + 120u);
        sint32 cost = r_s16(weapon + 126u);
        if (ammunition - cost >= 0 && ammunition != 0)
            break;
        index = (uint32)(sint32)r_s8(weapon + 135u);
        uint32 next = r_u32(0x800C6164u + index * 4u);
        if (next == 0u || next == 3u)
            break;
        uint32 selected = (uint32)(sint32)(sint8)next;
        w_u8(weapon + 135u, next);
        if (r_s8(attributes + selected + 106u) != 0)
        {
            ob_draft_unresolved_call(0x800B7C7Cu, 3u, r_u32(object + 120u), selected,
                (uint32)(sint32)r_s8(attributes + selected + 130u));
            index = (uint32)(sint32)r_s8(weapon + 135u);
            w_u16(attributes + 154u, r_u16(0x800C5A80u + index * 2u));
            w_u8(attributes + 177u, r_u8(weapon + 135u));
        }
        /* TODO Recover the conditional sound mask carried by the prior helper */
        uint32 voice = (uint32)(sint32)r_s16(attributes + 104u);
        uint32 mask = ob_native_missing_value(0x8001195Cu, "B5CB4 sound mask at800B64FC");
        ob_draft_unresolved_call(0x8001195Cu, 2u, voice, mask);
        w_u16(attributes + 104u, 0xFFFFu);
        w_u32(attributes + 160u, 0u);
    }
    uint32 index = (uint32)(sint32)r_s8(weapon + 135u);
    if (r_u32(0x800C6164u + index * 4u) == 999u)
    {
        uint32 selected = 0u;
        for (uint32 candidate = 0u; candidate < 8u; ++candidate)
        {
            uint32 ammo_index = (uint32)(sint32)r_s8(0x800C5EEDu + candidate * 4u);
            if (r_s16(attributes + ammo_index * 2u + 120u) > 0 &&
                r_s8(attributes + candidate + 106u) != 0)
            {
                selected = candidate;
                break;
            }
        }
        w_u8(weapon + 135u, selected);
        ob_draft_unresolved_call(0x800B7C7Cu, 3u, r_u32(object + 120u), selected,
            (uint32)(sint32)r_s8(attributes + selected + 130u));
        index = (uint32)(sint32)r_s8(weapon + 135u);
        w_u16(attributes + 154u, r_u16(0x800C5A80u + index * 2u));
        w_u8(attributes + 177u, r_u8(weapon + 135u));
    }
    if (r_s16(attributes + 120u) == 0 && (sint32)r_u32(attributes + 184u) < (sint32)time)
        w_u32(attributes + 184u, time + 1000u);
    if (r_s16(attributes + 122u) == 0 && (sint32)r_u32(attributes + 188u) < (sint32)time)
        w_u32(attributes + 188u, time + 2000u);
finished:
    ob_draft_scratch_release(request);
    return spawned;
}

uint32 ob_game_800B7C08(uint32 slot, uint32 weapon, uint32 time)
{
    FUNCTION_MARKER(0x800B7C08u, "GAME.BIN");
    slot &= 255u;
    if (slot >= 2u) slot = 0u;
    uint32 index = r_u8(weapon + slot + 112u);
    uint32 mode = r_u8(weapon + 114u);
    uint32 deadline = time + (uint32)(sint32)(sint16)r_u16(weapon + 104u + mode * 2u);
    w_u32(weapon + slot * 48u + index * 4u, deadline);
    mode = r_u8(weapon + 114u);
    uint32 result = time + (uint32)(sint32)(sint16)r_u16(weapon + 108u + mode * 2u);
    w_u32(weapon + slot * 4u + 96u, result);
    return result;
}
