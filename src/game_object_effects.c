#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800BF4FC(uint32 object, uint32 effect_data, uint32 secondary_attributes, uint32 context)
{
    FUNCTION_MARKER(0x800BF4FCu, "GAME.BIN");
    uint32 nodes[4], details, index = 0u, node, result, type, callback, descriptor;
    uint32 vectors, vector, transformed, position, matrix, record, model;
    sint32 kind, parameter, y;
    nodes[0] = object;
    nodes[1] = r_u32(object + 136u);
    nodes[2] = r_u32(object + 140u);
    nodes[3] = r_u32(object + 144u);
    /* TODO Bind remaining original GAME effect helpers when reached */
    do
    {
        w_u32(effect_data + 4u, 0u);
        w_u32(effect_data, 0u);
        w_u32(secondary_attributes + 4u, 0x10000001u);
        w_u32(secondary_attributes, 0u);
        details = ob_game_800901FC(r_u32(object + 292u), (uint32)(sint32)(sint16)index);
        parameter = r_s16(details + 14u);
        kind = (sint16)ob_draft_unresolved_call(0x800C0868u, 1u, (uint32)(sint32)r_s16(details + 12u));
        if (kind != 102)
        {
            /* TODO Original descriptor variants beyond three children exceed its four-node array */
            if ((uint32)(sint32)(sint16)index >= 4u)
                node = ob_native_missing_value(0x800BF4FCu, "Attachment array index");
            else node = nodes[(uint32)(sint32)(sint16)index];
            result = sub_8004E518(node, effect_data, context, (uint32)kind);
            w_u32(node + 60u, result);
            ob_draft_unresolved_call(0x8004E694u, 2u, r_u32(node + 60u), (uint32)parameter);
        }
        ++index;
    } while (r_u16(details + 32u) >= 2u);
    type = r_u32(object + 292u);
    if (type < 152u)
    {
        if (type >= 150u)
        {
            model = r_u32(object + 44u);
            w_u32(object + 288u, 8u);
            w_u32(model + 136u, (uint32)-1000);
            goto activate;
        }
        if (type < 9u)
        {
            if (type >= 6u || type == 2u) goto ordinary;
            if (type >= 2u && type < 5u)
            {
                w_u32(secondary_attributes + 4u, r_u32(r_u32(object + 48u) + 48u));
                goto create_effect;
            }
            return type < 5u;
        }
        if (type >= 17u)
        {
            if (type >= 32u || type < 20u) return type < 20u;
            goto ordinary;
        }
        if (type >= 15u)
        {
            if (r_u32(r_u32(0x800D6750u) + 4u) != 0u)
            {
                model = r_u32(object + 44u);
                w_u32(object + 288u, 8u);
                w_u32(model + 136u, 1000u);
            }
            else
            {
                model = r_u32(object + 44u);
                w_u32(object + 288u, 6u);
                sub_80045A44(model, 0x8006C160u);
            }
            ob_draft_unresolved_call(0x800C0744u, 3u, object, 0u, context + (uint32)(sint32)r_s16(object + 308u));
            sub_80045ADC(r_u32(object + 44u));
            type = r_u32(object + 292u);
            if (type == 15u) w_u32(secondary_attributes + 4u, 65801u);
            else if (type == 16u) w_u32(secondary_attributes + 4u, 65806u);
            goto create_effect;
        }
        if (type == 10u) goto create_effect;
        return 10u;
    }
    if (type == 224u) goto stationary;
    if (type >= 225u)
    {
        if (type == 238u)
        {
            w_u32(secondary_attributes + 4u, 65897u);
            goto stationary;
        }
        if (type < 239u)
        {
            if (type >= 231u || type < 229u) return type < 229u;
            if (r_u32(r_u32(object + 108u) + 4u) == 17u)
            {
                matrix = ob_draft_unresolved_call(0x8004545Cu, 2u, r_u32(object + 44u), context);
                sub_80029F58((uint32)(sint32)r_s16(r_u32(0x800D6750u) + 16u), matrix);
                vectors = ob_draft_scratch_acquire(36u);
                position = vectors;
                vector = vectors + 12u;
                transformed = vectors + 24u;
                w_u32(vector, 0u);
                if (r_u32(r_u32(0x800D6750u) + 4u) != 0u)
                {
                    w_u32(vector + 4u, 1500u);
                    w_u32(vector + 8u, 1000u);
                }
                else
                {
                    w_u32(vector + 4u, 0u);
                    w_u32(vector + 8u, 0u);
                }
                sub_80029B70(vector, matrix, transformed);
                sub_80045A44(r_u32(object + 44u), transformed);
                sub_80045848(r_u32(object + 44u), matrix);
                record = r_u32(0x800D6750u);
                result = r_u32(record);
                y = (sint32)r_u32(record + 4u);
                node = r_u32(record + 8u);
                w_u32(position, result);
                w_u32(position + 4u, (uint32)y);
                w_u32(position + 8u, node);
                if (y < 0)
                {
                    w_u32(r_u32(0x800D6750u) + 4u, 10u);
                    w_u32(position + 4u, 10u);
                }
                sub_800458B4(r_u32(object + 44u), position, context);
                sub_80045B74(r_u32(object + 44u));
                w_u32(object + 288u, 8u);
                ob_draft_scratch_release(vectors);
                goto activate;
            }
            y = (sint32)r_u32(r_u32(0x800D6750u) + 4u);
            if (y > 0)
            {
                model = r_u32(object + 44u);
                w_u32(object + 288u, 8u);
                w_u32(model + 136u, 1000u);
            }
            else if (y < 0)
            {
                vector = ob_draft_scratch_acquire(12u);
                result = r_u32(0x8008FB54u);
                node = r_u32(0x8008FB58u);
                record = r_u32(0x8008FB5Cu);
                w_u32(vector, result);
                w_u32(vector + 4u, node);
                w_u32(vector + 8u, record);
                model = r_u32(object + 44u);
                w_u32(object + 288u, 4u);
                sub_80045A44(model, vector);
                ob_draft_scratch_release(vector);
            }
            else
            {
                model = r_u32(object + 44u);
                w_u32(object + 288u, 6u);
                sub_80045A44(model, 0x8006C160u);
            }
            goto activate;
        }
        if (type != 255u) return 255u;
        w_u32(secondary_attributes + 4u, 65605u);
        descriptor = 0x800C3680u;
        callback = 0x800B1F9Cu;
        goto create_stationary;
    }
    if (type == 160u) return 1u;
    if (type >= 161u)
    {
        if (type >= 182u || type < 180u) return type < 180u;
        goto create_effect;
    }
    if (type == 156u)
    {
        ob_draft_unresolved_call(0x8004E66Cu, 1u, r_u32(object + 60u));
        sub_80045A44(r_u32(object + 44u), 0x8006C160u);
        result = r_u32(object + 136u);
        if (result != 0u)
        {
            ob_draft_unresolved_call(0x8004E66Cu, 1u, r_u32(result + 60u));
            return sub_80045A44(r_u32(r_u32(object + 136u) + 44u), 0x8006C160u);
        }
        return result;
    }
    if (type == 159u)
    {
        if (r_u8(0x8006C230u) < 2u) return 1u;
        return ob_draft_unresolved_call(0x8004E66Cu, 1u, r_u32(r_u32(object + 136u) + 60u));
    }
    return 159u;
ordinary:
    /* The type is reloaded after earlier effect creation */
    switch (r_u32(object + 292u))
    {
    case 2u: w_u32(secondary_attributes + 4u, 65836u); break;
    case 20u: w_u32(secondary_attributes + 4u, 65557u); break;
    case 21u: w_u32(secondary_attributes + 4u, 65546u); break;
    case 22u: w_u32(secondary_attributes + 4u, 65690u); break;
    case 23u: w_u32(secondary_attributes + 4u, 65770u); break;
    case 24u: w_u32(secondary_attributes + 4u, 65795u); break;
    case 25u: w_u32(secondary_attributes + 4u, 65699u); break;
    case 26u: w_u32(secondary_attributes + 4u, 65648u); break;
    case 27u: w_u32(secondary_attributes + 4u, 65675u); break;
    case 28u: w_u32(secondary_attributes + 4u, 65786u); break;
    case 29u: w_u32(secondary_attributes + 4u, 65815u); break;
    case 30u: w_u32(secondary_attributes + 4u, 65885u); break;
    case 31u: w_u32(secondary_attributes + 4u, 65903u); break;
    default: break;
    }
    descriptor = 0x800C369Cu;
    callback = 0x800AB0C4u;
    goto create_stationary;
stationary:
    descriptor = 0x800C3664u;
    callback = 0x8009DE18u;
create_stationary:
    ob_draft_unresolved_call(0x80090070u, 3u, object, secondary_attributes, descriptor);
    w_u32(secondary_attributes + 48u, callback);
    w_u16(secondary_attributes + 38u, 0xFFFFu);
    w_u16(secondary_attributes + 36u, 0u);
    result = (uint32)sub_8004F074((sint32)object, (sint32)secondary_attributes, (sint32)context);
    w_u32(object + 56u, result);
    return result;
activate:
    sub_80045ADC(r_u32(object + 44u));
create_effect:
    return ob_draft_unresolved_call(0x800C0C88u, 4u, object, secondary_attributes, 0x800C36B8u, context);
}
