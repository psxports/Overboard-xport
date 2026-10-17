#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800B4874(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x800B4874u, "GAME.BIN");
    uint32 player = r_u32(object + 108u);
    uint32 elapsed = time - r_u32(object + 28u);
    uint32 storage = ob_draft_scratch_acquire(52u);
    uint32 position = storage, offset_position = storage + 12u, descriptor = storage + 24u;
    uint32 target, result, matrix, transition, state, desired, index, table, node, value;
    uint32 volume, sound, heading_time;
    sint32 height, candidate = -1, remaining, delta;
    if (r_u32(player + 92u) != 0u)
    {
        sub_800453C4(r_u32(object + 44u), time, position);
        height = (sint32)ob_draft_unresolved_call(0x800B50C4u, 4u,
            r_u32(position), r_u32(position + 4u), r_u32(position + 8u), time);
        w_u32(position + 4u, (uint32)height);
        if (height < 0) w_u32(position + 4u, 0u);
        sub_800458B4(r_u32(r_u32(player + 92u) + 44u), position, time);
    }
    else
    {
        ob_draft_unresolved_call(0x800B45F4u, 1u, object);
        ob_draft_unresolved_call(0x800B47B0u, 1u, object);
    }
    if (r_u32(player + 96u) != 0u)
    {
        ob_draft_unresolved_call(0x800944C4u, 1u, time);
        sub_800453C4(r_u32(object + 44u), time, offset_position);
        matrix = r_u32(0x800775D0u);
        w_u32(offset_position, r_u32(offset_position) - (uint32)((sint32)r_s16(matrix + 4u) >> 5));
        w_u32(offset_position + 4u, r_u32(offset_position + 4u) - (uint32)((sint32)r_s16(matrix + 10u) >> 5));
        value = (uint32)(sint32)r_s16(matrix + 16u);
        w_u32(offset_position + 4u, r_u32(offset_position + 4u) + 1200u);
        w_u32(offset_position + 8u, r_u32(offset_position + 8u) - (uint32)((sint32)value >> 5));
        sub_800458B4(r_u32(r_u32(player + 96u) + 44u), offset_position, time);
        ob_draft_unresolved_call(0x800B41FCu, 2u, object, player + 68u);
    }
    transition = r_u8(player + 45u);
    if (transition != 0u)
    {
        if (transition < 129u)
        {
            desired = r_u8(player + 47u);
            if (r_u8(player + 46u) != desired)
            {
                if (desired == 1u || desired == 4u)
                {
                    if (r_u32(player + 92u) == 0u)
                        ob_draft_unresolved_call(0x800B4FF8u, 3u, object, 0u, time);
                    if (r_u8(player + 47u) == 4u)
                    {
                        if (r_u32(player + 96u) == 0u)
                        {
                            sub_800453C4(r_u32(object + 44u), time, descriptor);
                            /* TODO Other original 28-byte descriptor fields are indeterminate here */
                            w_u32(descriptor + 12u, 166u);
                            result = ob_game_800BC3D8(r_u32(0x80083E34u), descriptor, time);
                            w_u32(player + 96u, result);
                        }
                        if (r_u8(player + 47u) != 4u) goto remove_attachment;
                    }
                    else goto remove_attachment;
                }
                else
                {
remove_attachment:
                    target = r_u32(player + 96u);
                    if (target != 0u)
                    {
                        ob_draft_unresolved_call(0x800BCAA0u, 1u, target);
                        w_u32(player + 96u, 0u);
                    }
                }
                if ((r_u32(player + 44u) & 0xFFFF0000u) == 0x30000u)
                {
                    w_u8(player + 45u, 1u);
                    ob_draft_unresolved_call(0x80044080u, 2u, r_u32(object + 48u), r_u32(0x800C5A58u));
                }
                state = r_u8(player + 47u);
                w_u8(player + 46u, (uint8)state);
                if (state != 3u)
                {
                    for (index = 0u; index != 8u; ++index)
                    {
                        node = ob_draft_unresolved_call(0x800B3A90u, 2u, object, r_u32(0x800C5A38u + index * 4u));
                        table = 0x800C5718u + r_u32(player + 4u) * 160u
                            + (r_u8(player + 46u) * 8u + index) * 4u;
                        w_u32(node + 40u, r_u32(table));
                    }
                }
                sound = (uint32)(sint32)r_s16(object + 306u);
                if (sound != 0xFFFFFFFFu)
                {
                    /* TODO Original1195C carries an unset a1 into exceptional sound ownership paths */
                    ob_draft_unresolved_call(0x8001195Cu, 1u, sound);
                    w_u16(object + 306u, 0xFFFFu);
                }
                sound = r_u32(0x800C5B0Cu + r_u8(player + 46u) * 4u);
                if (sound != 0xFFFFFFFFu)
                {
                    state = r_u8(player + 46u);
                    w_u32(player + 100u, sound);
                    value = (uint32)(sint32)r_s16(0x800C5B20u + state * 2u);
                    value = (uint32)((sint32)value / 2);
                    result = sub_80011984(r_u32(player + 100u),
                        (uint32)(sint32)r_s16(0x800C5B2Cu + state * 2u), 15u, 15u, value, 0u, 1u);
                    w_u16(object + 306u, (uint16)result);
                }
            }
            delta = (sint32)(2u * (128u - r_u8(player + 45u)));
            volume = (uint16)(delta < 10 ? 10u : (uint32)delta);
        }
        else
        {
            delta = (sint32)(2u * (transition - 127u));
            volume = (uint16)(delta < 10 ? 10u : (uint32)delta);
        }
        state = r_u8(player + 46u);
        if (state == 1u)
        {
            ob_draft_unresolved_call(0x80011D80u, 2u, (uint32)(sint32)r_s16(object + 306u), volume);
            state = r_u8(player + 46u);
        }
        if (state == 3u)
        {
            if (volume >= 125u) table = 0x800C5A68u;
            else if (volume >= 87u) table = 0x800C5A64u;
            else if (volume >= 43u) table = 0x800C5A60u;
            else table = 0x800C5A5Cu;
            ob_draft_unresolved_call(0x80044080u, 2u, r_u32(object + 48u), r_u32(table));
        }
        else
        {
            for (index = 0u; index != 8u; ++index)
            {
                table = 0x800C5718u + r_u32(player + 4u) * 160u
                    + (r_u8(player + 46u) * 8u + index) * 4u;
                if (r_u32(table) != 0x800662CCu)
                {
                    node = ob_draft_unresolved_call(0x800B3A90u, 2u, object, r_u32(0x800C5A38u + index * 4u));
                    w_u16(node + 160u, (uint16)volume);
                }
            }
        }
        value = r_u8(player + 45u);
        delta = (sint32)elapsed >> 3;
        if (delta >= (sint32)value) w_u8(player + 45u, 0u);
        else w_u8(player + 45u, (uint8)(value - (uint32)delta));
    }
    else
    {
        remaining = (sint32)r_u32(player + 36u);
        if (remaining > 0)
        {
            remaining = (sint32)((uint32)remaining - elapsed);
            w_u32(player + 36u, (uint32)remaining);
            if (remaining <= 0)
            {
                if (r_u8(player + 47u) == 4u)
                {
                    target = r_u32(player + 96u);
                    w_u8(player + 45u, 1u);
                    ob_draft_unresolved_call(0x800A6D2Cu, 2u, r_u32(target + 44u), time);
                }
                else
                {
                    w_u8(player + 45u, 255u);
                    sub_80011984(0x80066620u, 128u, 15u, 15u, 256u, 0u, 0u);
                }
                w_u8(player + 47u, 0u);
                w_u32(player + 36u, 0u);
            }
        }
    }
    state = r_u8(player + 46u);
    if (state == 1u)
    {
        if (r_u8(player + 47u) == 1u)
            candidate = (sint32)r_u32(r_u32(object + 44u) + 84u) < 6500 ? 450 : 0;
        else
        {
            sub_800453C4(r_u32(object + 44u), time, descriptor);
            if ((sint32)r_u32(descriptor + 4u) > 0)
                candidate = (sint32)(r_u32(player + 56u) - 50u);
        }
        heading_time = r_u32(player + 40u);
        if ((sint32)heading_time < (sint32)time)
        {
            if (heading_time & 1u)
            {
                value = 5500u - r_u32(player + 36u);
                w_u32(player + 40u, (heading_time + (uint32)((sint32)value >> 2)) & 0xFFFFFFFEu);
                ob_draft_unresolved_call(0x80011D80u, 2u, (uint32)(sint32)r_s16(object + 306u), 128u);
            }
            else
            {
                w_u32(player + 40u, (heading_time + (uint32)((sint32)r_u32(player + 36u) >> 2)) | 1u);
                ob_draft_unresolved_call(0x80011D80u, 2u, (uint32)(sint32)r_s16(object + 306u), 256u);
            }
        }
    }
    else if (state == 0u) goto sample_height;
    else if (state == 2u)
    {
        if ((sint32)r_u32(player + 40u) >= (sint32)time || r_s16(player + 172u) != 0)
            goto sample_height;
        ob_draft_unresolved_call(0x800B8818u, 4u, r_u32(object + 44u), 150u, 4000u, time);
        w_u32(player + 40u, r_u32(player + 40u) + 100u);
        goto sample_height;
    }
    else if (state == 4u)
    {
        if (r_u8(player + 47u) == 4u)
            candidate = (sint32)r_u32(r_u32(object + 44u) + 84u) < 4000 ? 300 : 0;
        else goto sample_height;
    }
    goto finish;
sample_height:
    sub_800453C4(r_u32(object + 44u), time, descriptor);
    if ((sint32)r_u32(descriptor + 4u) > 0)
        candidate = (sint32)(r_u32(player + 56u) - 50u);
finish:
    if ((sint32)time >= (sint32)r_u32(r_u32(object + 124u) + 8u) && candidate != -1)
        w_u32(player + 56u, (uint32)candidate);
    result = ob_draft_unresolved_call(0x800B3AD0u, 3u, object, player + 48u, player + 52u);
    ob_draft_scratch_release(storage);
    return result;
}
