#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_extra_signatures.h"
#include "native_runtime.h"

uint32 ob_game_80090CB4(uint32 object, uint32 command, uint32 time)
{
    FUNCTION_MARKER(0x80090CB4u, "GAME.BIN");
    if (r_u32(object + 288u) == 1u)
        return ob_draft_unresolved_call(0x800916A0u, 2u, object, time);
    sub_80045A7C(r_u32(object + 44u), time);
    uint32 child = r_u32(object + 136u);
    if (child != 0u) sub_80045A7C(r_u32(child + 44u), time);
    uint32 previous_time = r_u32(object + 28u);
    uint32 elapsed = time - previous_time;
    if (elapsed == 0u)
        return ob_draft_unresolved_call(0x800916A0u, 2u, object, time);
    uint32 type = r_u32(object + 292u);
    if (type == 150u || type == 151u)
    {
        uint32 model = r_u32(object + 44u);
        uint32 height = r_u32(model + 136u);
        if (height != 0u)
        {
            w_u32(model + 136u, height - 3u * elapsed);
            sub_80045ADC(r_u32(object + 44u));
            sub_80045B74(r_u32(object + 44u));
            goto finish;
        }
        if (r_u32(model + 112u) != 0u)
        {
            uint32 descriptor = r_u32(object + 112u);
            uint8 saved = r_u8(descriptor + 40u);
            w_u8(descriptor + 40u, 0u);
            ob_draft_unresolved_call(0x800B7DA8u, 2u, r_u32(object + 120u), 8u);
            ob_draft_unresolved_call(0x800B5BD8u, 4u, 0u, r_u32(object + 120u), (uint32)r_u8(descriptor + 40u), time);
            if (ob_draft_unresolved_call(0x800B5C50u, 3u, 0u, r_u32(object + 120u), time) != 0u)
                ob_draft_unresolved_call(0x800B5CB4u, 4u, object, 0u, 0u, time);
            w_u8(descriptor + 40u, saved);
        }
        return ob_draft_unresolved_call(0x800BCAA0u, 1u, object);
    }
    if (type != 3u && type != 4u && type != 156u) goto finish;

    /* Addressable vectors and packed rotation matrix, without ABI home slots */
    uint32 storage = ob_draft_scratch_acquire(54u);
    uint32 vector = storage;
    uint32 rotated_vector = storage + 12u;
    uint32 position = storage + 24u;
    uint32 matrix = storage + 36u;
    if (type == 3u || type == 4u)
    {
        if (type == 3u)
            ob_draft_unresolved_call(0x80097E28u, 3u, 0u, object, time);
        else
        {
            ob_draft_unresolved_call(0x80097578u, 3u, object, 0x800C90F8u, time);
            ob_draft_unresolved_call(0x80098088u, 3u, object, 0u, time);
            ob_draft_unresolved_call(0x80097850u, 4u, object, 0x800C90F8u, 0u, time);
        }
        sub_80029F58((uint32)(sint32)r_s16(r_u32(object + 124u) + 4u), matrix);
        w_u32(vector + 4u, 0u);
        w_u32(vector, 0u);
        w_u32(vector + 8u, r_u32(r_u32(object + 124u)));
        sub_80029B70(vector, matrix, rotated_vector);
        sub_80045A44(r_u32(object + 44u), rotated_vector);
        sub_80045848(r_u32(object + 44u), matrix);
        sub_80045B74(r_u32(object + 44u));
        if (type == 4u)
            ob_draft_unresolved_call(0x80091C9Cu, 3u, object, r_u32(object + 116u), time);
    }
    else
    {
        uint32 state = r_u32(object + 288u);
        uint32 record = r_u32(object + 108u);
        if (state == 0u)
        {
            w_u16(object + 308u, 50u);
            sub_80045A44(r_u32(object + 44u), 0x8006C160u);
            child = r_u32(object + 136u);
            if (child != 0u) sub_80045A44(r_u32(child + 44u), 0x8006C160u);
            ob_draft_unresolved_call(0x80092190u, 2u, object, time);
            if (r_s16(record) == 0 || r_s16(record + 2u) >= 3)
                w_u16(record + 12u, (uint16)(r_u16(record + 12u) | 1u));
            if ((r_u16(record + 12u) & 1u) != 0u && r_s16(record + 4u) == 0)
            {
                uint32 material = r_u32(r_u32(r_u32(object + 48u) + 32u) + 32u);
                w_u32(material + 40u, 0x800662CCu);
                sub_8001195C((uint32)(sint32)r_s16(record + 14u));
                w_u16(record + 14u, 0xFFFFu);
                uint32 angle = ob_draft_unresolved_call(0x8001AFC8u, 0u);
                uint32 offset = 2u * (((angle & 0xFFFFu) + 8u) >> 4);
                sint32 sine = r_s16(0x8006C304u + offset);
                w_u32(vector + 4u, 0u);
                w_u32(vector, (uint32)((-5000 * sine) >> 14));
                w_u32(vector + 8u, (uint32)((-5000 * (sint32)r_s16(0x8006CB04u + offset)) >> 14));
                sub_80045A44(r_u32(object + 44u), vector);
                child = r_u32(object + 136u);
                if (child != 0u) sub_80045A44(r_u32(child + 44u), vector);
                w_u16(object + 308u, 1638u);
                w_u32(object + 288u, 31u);
                w_u16(record, 0xFFFFu);
                w_u16(record + 12u, 0xFFFEu);
            }
            else
            {
                uint32 material = r_u32(r_u32(r_u32(object + 48u) + 32u) + 32u);
                w_u32(material + 40u, 0x8006775Cu);
                if (r_s16(record + 14u) == -1)
                    w_u16(record + 14u, (uint16)sub_80011984(0x80067750u, 128u, 15u, 15u, 256u, 2u, 1u));
                if (r_s16(record + 4u) != 0)
                {
                    uint32 spawned = r_u32(record + 8u);
                    sub_80045A7C(r_u32(spawned + 44u), time);
                    sub_80045378(r_u32(spawned + 44u), time, vector);
                    if ((sint32)r_u32(vector + 4u) >= 6001)
                    {
                        ob_draft_unresolved_call(0x800BCAA0u, 1u, spawned);
                        w_u32(record + 8u, 0u);
                        w_u16(record + 4u, 0u);
                    }
                }
                else if ((r_u16(record + 12u) & 1u) == 0u)
                {
                    uint32 player = r_u32(0x8006C138u);
                    uint32 player_index = (uint32)(sint32)r_s16(player + 326u);
                    w_u8(0x800CBA3Au + 104u * player_index, 17u);
                    uint32 spawned = ob_draft_unresolved_call(0x800A6C34u, 3u, r_u32(0x8006C138u), 17u, time);
                    w_u16(record + 4u, 1u);
                    w_u32(record + 8u, spawned);
                    w_u32(r_u32(spawned + 44u) + 132u, 0u);
                    w_u32(r_u32(spawned + 44u) + 136u, 700u);
                    w_u32(r_u32(spawned + 44u) + 140u, 0u);
                    uint32 model = r_u32(spawned + 44u);
                    w_u32(spawned + 288u, 9u);
                    sub_80045ADC(model);
                    /* Incoming time is unused by the real one-argument helper */
                    sub_80046544(r_u32(spawned + 52u));
                    ob_draft_unresolved_call(0x80011A24u, 6u, 0x800660BCu, 144u, 256u, r_u32(object + 44u), time, 0u);
                    w_u16(record + 2u, (uint16)(r_u16(record + 2u) + 1u));
                }
            }
        }
        else if (state == 31u)
        {
            w_u16(object + 308u, 30000u);
            ob_draft_unresolved_call(0x80045410u, 2u, r_u32(object + 44u), vector);
            if ((r_u32(vector) | r_u32(vector + 8u)) != 0u)
            {
                sub_80045A44(r_u32(object + 44u), 0x8006C160u);
                child = r_u32(object + 136u);
                if (child != 0u) sub_80045A44(r_u32(child + 44u), 0x8006C160u);
                ob_main_8004E66C(r_u32(object + 60u));
                child = r_u32(object + 136u);
                if (child != 0u) ob_main_8004E66C(r_u32(child + 60u));
                sub_8001195C((uint32)(sint32)r_s16(object + 306u));
                w_u16(object + 306u, 0xFFFFu);
            }
            ob_draft_unresolved_call(0x80092190u, 2u, object, time);
            if (r_s16(record) >= 20 || (sint32)(time - r_u32(object + 316u)) > 600000)
            {
                uint32 effect = r_u32(object + 60u);
                w_u32(object + 316u, time);
                ob_draft_unresolved_call(0x8004E680u, 1u, effect);
                child = r_u32(object + 136u);
                if (child != 0u) ob_draft_unresolved_call(0x8004E680u, 1u, r_u32(child + 60u));
                uint32 material = r_u32(r_u32(r_u32(object + 48u) + 32u) + 32u);
                w_u32(material + 40u, 0x800662CCu);
                sub_8001195C((uint32)(sint32)r_s16(record + 14u));
                w_u16(record + 14u, 0xFFFFu);
                uint32 angle = ob_draft_unresolved_call(0x8001AFC8u, 0u);
                uint32 px = r_u32(0x800C9104u);
                uint32 py = r_u32(0x800C9108u);
                uint32 pz = r_u32(0x800C910Cu);
                w_u32(position, px);
                w_u32(position + 4u, py);
                w_u32(position + 8u, pz);
                uint32 offset = 2u * (((angle & 0xFFFFu) + 8u) >> 4);
                sint32 sine = r_s16(0x8006C304u + offset);
                w_u32(position + 4u, 6500u);
                w_u32(position, r_u32(position) + (uint32)((32000 * sine) >> 14));
                w_u32(position + 8u, r_u32(position + 8u) + (uint32)((32000 * (sint32)r_s16(0x8006CB04u + offset)) >> 14));
                sub_800458B4(r_u32(object + 44u), position, time);
                sine = r_s16(0x8006C304u + offset);
                w_u32(vector + 4u, 0u);
                w_u32(vector, (uint32)((-5000 * sine) >> 14));
                w_u32(vector + 8u, (uint32)((-5000 * (sint32)r_s16(0x8006CB04u + offset)) >> 14));
                sub_80045A44(r_u32(object + 44u), vector);
                child = r_u32(object + 136u);
                if (child != 0u) sub_80045A44(r_u32(child + 44u), vector);
                w_u16(object + 308u, 1638u);
                w_u32(object + 288u, 0u);
                w_u16(record, 0u);
                w_u16(record + 2u, 0u);
                uint32 sound = ob_draft_unresolved_call(0x80011A24u, 6u, 0x8006774Cu, 0u, 256u, r_u32(object + 44u), time, 1u);
                w_u16(object + 306u, (uint16)sound);
                w_u8(object + 341u, 255u);
            }
        }
        sub_80029F58((uint32)(sint32)(sint16)(0u - 4u * time), matrix);
        sub_80045848(r_u32(object + 44u), matrix);
        sub_80045B74(r_u32(object + 44u));
        if (r_u32(r_u32(object + 48u) + 32u) != 0u)
        {
            sub_80029F58((uint32)(sint32)(sint16)(3u * time), matrix);
            sub_80045848(r_u32(r_u32(r_u32(object + 48u) + 32u) + 52u), matrix);
            sub_80045B74(r_u32(r_u32(r_u32(object + 48u) + 32u) + 52u));
        }
        if (r_u32(r_u32(r_u32(object + 48u) + 32u) + 32u) != 0u)
        {
            sub_80029F58((uint32)(sint32)(sint16)(20u * time), matrix);
            sub_80045848(r_u32(r_u32(r_u32(r_u32(object + 48u) + 32u) + 32u) + 52u), matrix);
            sub_80045B74(r_u32(r_u32(r_u32(r_u32(object + 48u) + 32u) + 32u) + 52u));
        }
    }
    ob_draft_scratch_release(storage);
finish:
    ob_game_800C0744(object, 0u, time + (uint32)(sint32)r_s16(object + 308u));
    w_u32(object + 28u, time);
    return ob_draft_unresolved_call(0x800916A0u, 2u, object, time);
}

