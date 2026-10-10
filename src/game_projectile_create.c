#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_extra_signatures.h"

uint32 ob_game_800B6B9C(uint32 object)
{
    FUNCTION_MARKER(0x800B6B9Cu, "GAME.BIN");
    sint32 voice = (sint16)r_u16(object + 136u);
    if (voice != -1) sub_8001195C((uint32)voice);
    ob_draft_unresolved_call(0x8004E644u, 1u, r_u32(object + 60u));
    uint32 geometry = r_u32(object + 52u);
    if (geometry != 0u) ob_draft_unresolved_call(0x8004651Cu, 1u, geometry);
    uint32 shape = r_u32(object + 48u);
    if (shape != 0u) ob_draft_unresolved_call(0x80044058u, 1u, shape);
    ob_draft_unresolved_call(0x80045124u, 1u, r_u32(object + 44u));
    ob_game_800955B0(object);
    ob_draft_unresolved_call(0x80043664u, 1u, object);
    w_u16(object + 122u, 0xDEADu);
    return 0xDEADu;
}

uint32 ob_game_800B6C38(uint32 object)
{
    FUNCTION_MARKER(0x800B6C38u, "GAME.BIN");
    uint32 output = ob_draft_scratch_acquire(4u);
    w_u32(output, object);
    uint32 attributes = r_u32(object + 108u);
    if (attributes != 0u) ob_draft_unresolved_call(0x800A9E48u, 1u, attributes);
    object = r_u32(output);
    uint32 payload = r_u32(object + 104u);
    if (payload != 0u && payload != 1u)
    {
        ob_draft_unresolved_call(0x800953B4u, 1u, payload);
        sub_800263B4(r_u32(output) + 104u);
    }
    object = r_u32(output);
    uint32 effect = r_u32(object + 116u);
    if (effect != 0u)
    {
        ob_game_80092C14(effect);
        /* The cleanup adapter uses only its object argument */
        ob_game_80092B30(r_u32(r_u32(output) + 116u), 0u, 0u);
        object = r_u32(output);
        w_u32(object + 116u, 0u);
    }
    uint32 collision = r_u32(object + 56u);
    if (collision != 0u) ob_draft_unresolved_call(0x8004F31Cu, 1u, collision);
    ob_game_800B6B9C(r_u32(output));
    uint32 result = sub_800263B4(output);
    ob_draft_scratch_release(output);
    return result;
}

uint32 ob_game_800B7FDC(uint32 node, uint32 unused, uint32 size, uint32 time)
{
    FUNCTION_MARKER(0x800B7FDCu, "GAME.BIN");
    uint32 record = ob_draft_scratch_acquire(96u);
    ob_game_800B8E40(node, record, time);
    w_u32(record + 44u, 0x800C4868u);
    w_u32(record + 56u, 1000u);
    w_u8(record + 92u, 16u);
    uint32 owner = r_u32(0x80083E34u);
    w_u32(record + 4u, 0u);
    w_u16(record + 88u, (uint16)size);
    w_u16(record + 86u, (uint16)size);
    w_u8(record + 93u, 1u);
    uint32 result = ob_game_80092408(owner, record, time, 4u);
    ob_draft_scratch_release(record);
    return result;
}

uint32 ob_game_800B6E64(uint32 object, uint32 packet, uint32 time)
{
    FUNCTION_MARKER(0x800B6E64u, "GAME.BIN");
    uint32 record = r_u32(packet + 32u);
    uint32 material = r_u32(record + 8u);
    uint32 vector = ob_draft_scratch_acquire(12u);
    uint32 position = ob_draft_scratch_acquire(24u);
    uint32 result;
    sint32 type;
    if (r_u32(packet + 4u) != 1u)
    {
        ob_main_80011A24(0x80067588u, 88u, 256u, r_u32(object + 44u), time, 0u);
        type = (sint16)r_u16(object + 132u);
        if (type != 5)
        {
            ob_draft_unresolved_call(0x800B7FDCu, 4u, r_u32(object + 44u), packet + 20u, 208u, time);
            uint32 geometry = r_u32(object + 52u);
            if (geometry != 0u && r_u32(geometry + 28u) != 0u)
                ob_draft_unresolved_call(0x8004659Cu, 2u, geometry, time);
            type = (sint16)r_u16(object + 132u);
        }
        switch (type)
        {
        case 2:
            sub_80045A7C(r_u32(object + 44u), time);
            ob_main_80045410(r_u32(object + 44u), vector);
            w_u32(vector, 0u);
            w_u32(vector + 4u, (uint32)-300);
            w_u32(vector + 8u, 0u);
            sub_80045A44(r_u32(object + 44u), vector);
            {
                uint32 angles = sub_80045490(r_u32(object + 44u), time);
                w_u32(angles + 4u, r_u32(angles + 4u) - 20u);
                sub_800458B4(r_u32(object + 44u), angles, time);
                uint32 effect = r_u32(object + 60u);
                w_u32(object + 104u, 0u);
                w_u8(effect + 54u, 1u);
            }
            result = 1u;
            goto finish;
        case 3:
            goto expire;
        case 4:
        case 5:
            if (type == 5)
            {
                ob_draft_unresolved_call(0x8004659Cu, 2u, r_u32(object + 52u), time);
                uint16 flags = (sint16)r_u16(object + 144u) == 0 ? 4136u : 40u;
                w_u16(object + 142u, flags);
                w_u8(r_u32(object + 60u) + 54u, 4u);
            }
            sub_80045A7C(r_u32(object + 44u), time);
            ob_main_80045410(r_u32(object + 44u), vector);
            w_u32(vector, (uint32)((sint32)r_u32(vector) / 4));
            w_u32(vector + 4u, 0u);
            w_u32(vector + 8u, (uint32)((sint32)r_u32(vector + 8u) / 4));
            sub_80045A44(r_u32(object + 44u), vector);
            if (type == 5) sub_80045ADC(r_u32(object + 44u));
            {
                uint32 angles = sub_80045490(r_u32(object + 44u), time);
                w_u32(angles + 4u, type == 5 ? 0u : 2u);
                result = sub_800458B4(r_u32(object + 44u), angles, time);
            }
            w_u32(object + 104u, 0u);
            goto finish;
        case 6:
        case 7:
            ob_draft_unresolved_call(0x800B7EECu, 3u, r_u32(object + 44u), packet + 20u, time);
            break;
        default:
            break;
        }
        goto cleanup;
    }
    {
        uint32 packed = r_u8(material + 1u);
        sint32 remaining = packed & 63u;
        type = (sint16)r_u16(object + 132u);
        if (remaining != 0 && type != 7 && type != 9 && type != 5)
        {
            sint32 damage = (sint16)r_u16(object + 138u);
            uint32 stage = packed >> 6;
            if (damage < 0)
            {
                if (((uint32)damage & 0x2000u) == 0u) goto expire;
                damage = -damage;
            }
            damage = damage / 20 + 1;
            do
            {
                sint32 difference = remaining - damage;
                if (difference > 0)
                {
                    remaining = difference;
                    damage = 0;
                }
                else
                {
                    damage -= remaining;
                    ++stage;
                    sub_800453C4(r_u32(object + 44u), time, position);
                    uint32 index = r_u8(material);
                    ob_draft_unresolved_call(0x800BBA70u, 4u, position, index, index + 1u, time);
                    index = (r_u8(material) + 1u) & 255u;
                    w_u8(material, (uint8)index);
                    uint32 resource = r_u32(0x80077644u);
                    remaining = (sint8)r_u8(r_u32(resource + 24u) + index * 24u + 21u);
                    ob_draft_unresolved_call(0x8004BD74u, 2u, record, resource);
                }
                w_u8(material + 1u, (uint8)((uint32)remaining + (stage << 6)));
                if (damage <= 0 || remaining == 0) break;
            } while (1);
            ob_draft_unresolved_call(0x800B7F60u, 3u, r_u32(object + 44u), packet + 20u, time);
        }
        else if (type == 5)
        {
            uint16 flags = r_u16(object + 142u);
            uint32 effect = r_u32(object + 116u);
            w_u32(object + 128u, time - 1u);
            w_u32(object + 104u, 0u);
            w_u16(object + 142u, (uint16)((flags & 4095u) | 0x3000u));
            if (effect != 0u)
            {
                ob_game_80092C14(effect);
                /* The cleanup adapter uses only its object argument */
                ob_game_80092B30(r_u32(object + 116u), 0u, 0u);
                w_u32(object + 116u, 0u);
                w_u32(vector, 0u);
                w_u32(vector + 4u, 0u);
                w_u32(vector + 8u, 0u);
                ob_draft_unresolved_call(0x800B9A28u, 5u, r_u32(object + 44u), vector, 300u, 800u, time);
                sub_8001195C((uint32)(sint32)(sint16)r_u16(object + 136u));
                w_u16(object + 136u, 65535u);
            }
            sub_80045A7C(r_u32(object + 44u), time);
            ob_main_80045410(r_u32(object + 44u), vector);
            w_u32(vector, 0u);
            w_u32(vector + 4u, 0u);
            w_u32(vector + 8u, 0u);
            sub_80045A44(r_u32(object + 44u), vector);
        }
        else
            ob_draft_unresolved_call(0x800B7EECu, 3u, r_u32(object + 44u), packet + 20u, time);
    }
    type = (sint16)r_u16(object + 132u);
    if (type == 2 || type == 3 || (uint16)(type - 4) < 2u)
    {
        w_u32(object + 128u, time - 1u);
        sub_8004F2C4(r_u32(packet), 0);
        sub_80045A7C(r_u32(object + 44u), time);
        w_u32(vector, 0u);
        w_u32(vector + 4u, 0u);
        w_u32(vector + 8u, 0u);
        result = sub_80045A44(r_u32(object + 44u), vector);
        goto finish;
    }
cleanup:
    result = ob_draft_unresolved_call(0x800B6C38u, 1u, object);
    goto finish;
expire:
    {
        uint32 collision = r_u32(object + 56u);
        w_u32(object + 128u, time - 1u);
        result = sub_8004F2C4(collision, 0);
    }
finish:
    ob_draft_scratch_release(position);
    ob_draft_scratch_release(vector);
    return result;
}

uint32 ob_game_800B8A58(uint32 node, uint32 size, uint32 angle, uint32 heading, uint32 distance, uint32 time)
{
    FUNCTION_MARKER(0x800B8A58u, "GAME.BIN");
    uint32 record = ob_draft_scratch_acquire(96u);
    ob_game_800B8E40(node, record, time);
    uint32 lookup = ((heading & 65535u) + 8u) >> 4;
    uint32 product = distance * (uint32)(sint32)(sint16)r_u16(0x8006C304u + lookup * 2u);
    w_u32(record, r_u32(record) - (uint32)((sint32)product / 16384));
    product = distance * (uint32)(sint32)(sint16)r_u16(0x8006CB04u + lookup * 2u);
    w_u32(record + 8u, r_u32(record + 8u) - (uint32)((sint32)product / 16384));
    uint32 matrix = ob_draft_scratch_acquire(18u);
    uint32 m0 = r_u32(record + 12u), m1 = r_u32(record + 16u);
    uint32 m2 = r_u32(record + 20u), m3 = r_u32(record + 24u);
    w_u32(matrix, m0);
    w_u32(matrix + 4u, m1);
    w_u32(matrix + 8u, m2);
    w_u32(matrix + 12u, m3);
    w_u16(matrix + 16u, r_u16(record + 28u));
    sub_8002ADFC(matrix, (uint32)(sint32)(sint16)angle, record + 12u);
    w_u32(record + 44u, 0x800C48A8u);
    w_u32(record + 56u, 500u);
    w_u8(record + 92u, 6u);
    w_u16(record + 86u, size);
    w_u16(record + 88u, size);
    w_u16(record + 90u, size);
    uint32 result = ob_game_80092408(r_u32(0x80083E34u), record, time, 4u);
    ob_draft_scratch_release(matrix);
    ob_draft_scratch_release(record);
    return result;
}

void ob_game_80092C14(uint32 object)
{
    FUNCTION_MARKER(0x80092C14u, "GAME.BIN");
    uint32 next = r_u32(object + 120u);
    if (next != 0u)
    {
        uint32 previous = r_u32(object + 124u);
        if (previous != 0u)
        {
            w_u32(next + 124u, previous);
            w_u32(r_u32(object + 124u) + 120u, next);
        }
        else w_u32(next + 124u, 0u);
    }
    else
    {
        uint32 previous = r_u32(object + 124u);
        w_u32(0x800C8304u, previous);
        if (previous != 0u) w_u32(previous + 120u, 0u);
    }
}

uint32 ob_game_80092A8C(uint32 object)
{
    FUNCTION_MARKER(0x80092A8Cu, "GAME.BIN");
    if (r_u32(object + 104u) == 0u)
    {
        ob_draft_unresolved_call(0x8004E644u, 1u, r_u32(object + 60u));
        ob_draft_unresolved_call(0x80044058u, 1u, r_u32(object + 48u));
        ob_draft_unresolved_call(0x80045124u, 1u, r_u32(object + 44u));
    }
    else if (r_u32(object + 116u) != 0u && r_u32(object + 128u) != 0u)
        ob_draft_unresolved_call(0x80044080u, 2u, r_u32(object + 108u), 0u);
    ob_draft_unresolved_call(0x80043DBCu, 1u, object + 112u);
    ob_game_800955B0(object);
    return ob_draft_unresolved_call(0x80043664u, 1u, object);
}

uint32 ob_game_80092B30(uint32 object, uint32 unused, uint32 time)
{
    FUNCTION_MARKER(0x80092B30u, "GAME.BIN");
    uint32 callback = r_u32(object + 196u);
    if (callback != 0u)
    {
        /* TODO Recover callback-specific carriers if this optional hook is reached */
        ob_native_missing_value(callback, "92B30 optional cleanup hook ABI");
    }
    uint32 output = ob_draft_scratch_acquire(4u);
    w_u32(output, object);
    ob_game_80092A8C(object);
    uint32 result = sub_800263B4(output);
    ob_draft_scratch_release(output);
    return result;
}

uint32 ob_game_80092BA8(uint32 object, uint32 unused, uint32 time)
{
    FUNCTION_MARKER(0x80092BA8u, "GAME.BIN");
    ob_game_80092C14(object);
    return ob_game_80092B30(object, unused, time);
}

uint32 ob_game_800955B0(uint32 object)
{
    FUNCTION_MARKER(0x800955B0u, "GAME.BIN");
    ob_draft_unresolved_call(0x80043C18u, 1u, object + 64u);
    uint32 next = r_u32(object + 32u);
    uint32 previous = r_u32(object + 36u);
    w_u32(next + 36u, previous);
    w_u32(previous + 32u, next);
    w_u32(object + 32u, 0u);
    w_u32(object + 36u, 0u);
    return previous;
}

uint32 ob_game_8009540C(uint32 object, uint32 unused, uint32 time)
{
    FUNCTION_MARKER(0x8009540Cu, "GAME.BIN");
    ob_draft_unresolved_call(0x80045A7Cu, 2u, r_u32(object + 44u), time);
    uint32 elapsed = time - r_u32(object + 28u);
    if (elapsed != 0u)
    {
        uint32 node = r_u32(object + 44u);
        w_u32(node + 136u, r_u32(node + 136u) - elapsed * 6u);
        sub_80045ADC(r_u32(object + 44u));
        w_u32(object + 28u, time);
    }
    w_u32(object + 92u, time + 200u);
    return ob_draft_unresolved_call(0x80045EF4u, 1u, object + 64u);
}

uint32 ob_game_80094FFC(uint32 owner, uint32 request, uint32 time)
{
    FUNCTION_MARKER(0x80094FFCu, "GAME.BIN");
    uint32 available = r_u32(0x8007755Cu);
    uint32 output = ob_draft_scratch_acquire(4u);
    w_u32(output, 0u);
    /* The original entry falls through the shared allocation body at95004 */
    if ((sint32)available > 0)
    {
        sub_800262CC(output, 160);
        uint32 object = r_u32(output);
        if (object != 0u)
            ob_game_80095074(object, owner, request, time);
    }
    uint32 result = r_u32(output);
    ob_draft_scratch_release(output);
    return result;
}

uint32 ob_game_80095074(uint32 object, uint32 owner, uint32 request, uint32 time)
{
    FUNCTION_MARKER(0x80095074u, "GAME.BIN");
    uint32 geometry_template = ob_draft_scratch_acquire(84u);
    w_u32(request + 64u, 0x8006722Cu);
    w_u32(request + 68u, geometry_template);
    w_u32(request + 72u, 0x80067234u);
    w_u32(request + 80u, 6u);
    ob_game_800B66C4(object, owner, request, time);
    uint32 flags = r_u32(request + 56u) == 255u ? 0x2407AB36u : 32u;
    w_u32(geometry_template + 40u, 0u);
    w_u32(geometry_template + 44u, flags);
    w_u32(geometry_template + 52u, 0u);
    w_u32(geometry_template + 56u, 0u);
    w_u32(geometry_template + 48u, flags);
    w_u32(geometry_template + 60u, flags);
    w_u32(geometry_template + 68u, 0u);
    w_u32(geometry_template + 64u, 0u);
    w_u32(geometry_template + 80u, 0x800B6D10u);
    uint32 geometry = ob_draft_unresolved_call(0x80046184u, 3u, object, geometry_template, time);
    w_u32(object + 52u, geometry);
    w_u32(object + 100u, 0x8009540Cu);
    w_u32(object + 92u, time + 50u);
    ob_draft_unresolved_call(0x80045EF4u, 1u, object + 64u);
    ob_game_800B8060(r_u32(object + 44u), 0u, time);
    ob_game_800B8138(r_u32(object + 44u), 0u, time);
    if (r_u32(request + 56u) == 255u)
    {
        uint32 slot = r_u8(request + 48u);
        if (slot == 0u || slot == 1u)
        {
            uint32 record = r_u32(request + 96u);
            uint32 player = r_u32(record + 80u);
            uint32 attributes = r_u32(player + 108u);
            uint32 recoil = r_u16(attributes + 88u);
            recoil = slot == 0u ? recoil + 12288u : recoil - 12288u;
            w_u16(attributes + 88u, recoil);
        }
    }
    ob_draft_scratch_release(geometry_template);
    return object;
}

uint32 ob_game_800B8E40(uint32 node, uint32 record, uint32 time)
{
    FUNCTION_MARKER(0x800B8E40u, "GAME.BIN");
    sub_80029E54(record + 12u);
    uint32 position = sub_80045464(node, time);
    w_u32(record + 48u, 0u);
    w_u32(record, r_u32(position));
    w_u32(record + 4u, r_u32(position + 4u));
    uint32 z = r_u32(position + 8u);
    w_u8(record + 93u, 4u);
    w_u32(record + 40u, 0u);
    w_u32(record + 36u, 0u);
    w_u32(record + 32u, 0u);
    w_u32(record + 60u, 0u);
    w_u32(record + 76u, 1u);
    w_u8(record + 94u, 0u);
    w_u32(record + 8u, z);
    return 1u;
}

uint32 ob_game_800B8060(uint32 node, uint32 unused, uint32 time)
{
    FUNCTION_MARKER(0x800B8060u, "GAME.BIN");
    uint32 record = ob_draft_scratch_acquire(96u);
    ob_game_800B8E40(node, record, time);
    uint32 matrix = (uint32)sub_80045430((sint32)node);
    uint32 m0 = r_u32(matrix), m1 = r_u32(matrix + 4u);
    uint32 m2 = r_u32(matrix + 8u), m3 = r_u32(matrix + 12u);
    w_u32(record + 12u, m0);
    w_u32(record + 16u, m1);
    w_u32(record + 20u, m2);
    w_u32(record + 24u, m3);
    w_u16(record + 28u, r_u16(matrix + 16u));
    w_u32(record + 44u, 0x800C4914u);
    w_u32(record + 56u, 250u);
    w_u16(record + 86u, 256u);
    w_u16(record + 88u, 256u);
    w_u8(record + 92u, 9u);
    w_u8(record + 93u, 1u);
    /* TODO Fields not written by the original remain unspecified */
    uint32 result = ob_game_80092408(r_u32(0x80083E34u), record, time, 6u);
    ob_draft_scratch_release(record);
    return result;
}

uint32 ob_game_800B8138(uint32 node, uint32 unused, uint32 time)
{
    FUNCTION_MARKER(0x800B8138u, "GAME.BIN");
    if ((sint16)r_u16(0x800C5B54u) != 1) return 1u;
    uint32 record = ob_draft_scratch_acquire(96u);
    ob_game_800B8E40(node, record, time);
    w_u32(record + 44u, 0x800C48E4u);
    w_u32(record + 56u, 750u);
    w_u8(record + 92u, 12u);
    for (uint32 particle = 0u; particle < 2u; ++particle)
    {
        w_u32(record + 32u, (sub_8001B008() & 127u) - 64u);
        w_u32(record + 36u, sub_8001B008() & 255u);
        w_u32(record + 40u, (sub_8001B008() & 127u) - 64u);
        w_u16(record + 86u, 128u);
        w_u16(record + 88u, 280u);
        w_u16(record + 90u, 128u);
        ob_game_80092408(r_u32(0x80083E34u), record, time, 6u);
    }
    ob_draft_scratch_release(record);
    return 2u;
}

uint32 ob_game_80092B74(uint32 object, uint32 value, uint32 expires)
{
    FUNCTION_MARKER(0x80092B74u, "GAME.BIN");
    w_u32(object + 100u, 0x80092BA8u);
    w_u32(object + 96u, value);
    w_u32(object + 92u, expires);
    return ob_draft_unresolved_call(0x80045EF4u, 1u, object + 64u);
}

uint32 ob_game_80092BD8(uint32 object)
{
    FUNCTION_MARKER(0x80092BD8u, "GAME.BIN");
    uint32 previous = r_u32(0x800C8304u);
    w_u32(0x800C8304u, object);
    if (previous != 0u)
    {
        w_u32(previous + 120u, object);
        w_u32(object + 124u, previous);
    }
    else w_u32(object + 124u, 0u);
    w_u32(object + 120u, 0u);
    return previous;
}

uint32 ob_game_80092408(uint32 owner, uint32 record, uint32 time, uint32 flags)
{
    FUNCTION_MARKER(0x80092408u, "GAME.BIN");
    uint32 output = ob_draft_scratch_acquire(4u);
    w_u32(output, 0u);
    sub_800262CC(output, 204);
    uint32 object = r_u32(output);
    w_u32(object + 196u, 0u);
    sub_80043600(object, (sint32)owner, 0);
    w_u32(object, 0x800C47E4u);
    ob_game_80095528(object, 30u, 0x80092B30u, time);
    w_u32(object + 104u, r_u32(record + 48u));
    sub_80043DAC(object + 112u);
    if (r_u32(record + 48u) != 0u)
    {
        w_u32(object + 108u, r_u32(record + 52u));
        w_u32(object + 132u, r_u32(r_u32(record + 48u) + 60u) + 38u);
        sub_80043DEC(object + 112u, r_u32(record + 48u));
    }
    else
    {
        w_u32(object + 44u, sub_80044E5C(object, 0x80073660u, time));
        uint32 shape = sub_80043E3C(object, 0x80073638u);
        uint32 node = r_u32(object + 44u);
        w_u32(object + 48u, shape);
        w_u32(node + 8u, 0x10000001u);
        w_u32(r_u32(object + 48u) + 48u, 0x10000001u);
        shape = r_u32(object + 48u);
        w_u32(shape + 40u, r_u32(r_u32(record + 44u)));
        sub_80044130(r_u32(object + 48u));
        sub_800458B4(r_u32(object + 44u), record, time);
        for (uint32 axis = 0u; axis < 3u; ++axis)
            w_u32(r_u32(object + 44u) + 132u + axis * 4u, r_u32(record + 32u + axis * 4u));
        sub_80045ADC(r_u32(object + 44u));
        sub_80045848(r_u32(object + 44u), record + 12u);
        uint32 position = ob_draft_scratch_acquire(8u);
        w_u32(position, 0u);
        w_u32(position + 4u, 0u);
        uint32 behavior = sub_8004E518(object, position, time, flags);
        w_u32(object + 60u, behavior);
        ob_draft_unresolved_call(0x8004E694u, 2u, behavior, r_u8(record + 94u) == 0u ? 2u : 8u);
        ob_draft_scratch_release(position);
        w_u32(object + 132u, r_u32(object + 60u) + 38u);
        w_u32(object + 108u, r_u32(object + 48u));
    }
    w_u32(object + 136u, time);
    w_u8(object + 190u, r_u8(record + 92u));
    w_u8(object + 192u, r_u8(record + 93u));
    w_u16(object + 180u, r_u16(record + 86u));
    w_u16(object + 182u, r_u16(record + 88u));
    uint32 resource = r_u32(record + 44u);
    w_u8(object + 191u, 0u);
    w_u32(object + 128u, resource);
    w_u32(object + 144u, r_u32(record + 56u));
    uint32 initial = r_u16(record + 86u), final = r_u16(record + 88u);
    if (initial == final) w_u16(object + 188u, initial);
    uint32 mode = r_u8(object + 192u);
    switch (mode)
    {
    case 1u:
    case 2u:
    case 4u:
    case 8u:
    case 16u:
    case 64u:
    {
        uint32 duration = r_u32(record + 56u);
        uint32 pause = r_u32(record + 60u);
        uint32 repeats = mode == 64u ? 1u : r_u32(record + 76u);
        if (mode == 2u || mode == 8u) duration *= 2u;
        uint32 lifetime = (duration + pause) * repeats;
        if (mode == 2u || mode == 8u)
            w_u32(object + 144u, r_u32(object + 144u) * 2u);
        w_u32(object + 140u, lifetime);
        if (mode == 4u || mode == 8u || mode == 16u || mode == 64u)
        {
            w_u16(object + 188u, r_u16(record + 90u));
            w_u16(object + 184u, r_u16(record + 90u));
            if (mode != 16u)
            {
                uint32 midpoint = r_u16(record + 90u);
                initial = r_u16(record + 86u);
                if (midpoint == initial)
                {
                    w_u8(object + 193u, 1u);
                    w_u16(object + 186u, r_u16(record + 88u));
                }
                else
                {
                    if (mode == 8u)
                    {
                        w_u8(object + 193u, 255u);
                        w_u16(object + 186u, r_u16(record + 86u));
                    }
                    else
                    {
                        w_u16(object + 186u, initial);
                        w_u8(object + 193u, 255u);
                    }
                }
            }
        }
        break;
    }
    case 32u:
        w_u16(object + 168u, r_u16(record + 80u));
        w_u16(object + 172u, r_u16(record + 82u));
        w_u16(object + 176u, r_u16(record + 84u));
        w_u16(object + 170u, (uint32)((sint32)r_u32(record + 64u) / 1024));
        w_u16(object + 174u, (uint32)((sint32)r_u32(record + 68u) / 1024));
        w_u16(object + 178u, (uint32)((sint32)r_u32(record + 72u) / 1024));
        break;
    default:
        break;
    }
    sub_800440B8(r_u32(object + 108u), (uint32)(sint32)(sint16)r_u16(object + 188u));
    w_u32(object + 148u, (uint32)((sint32)r_u32(object + 144u) / 2));
    uint32 repeats = r_u32(record + 76u);
    w_u32(object + 164u, repeats == 1u ? 0u : repeats);
    w_u32(object + 152u, 0u);
    uint32 pause = r_u32(record + 60u);
    if (pause != 0u)
    {
        w_u32(object + 152u, pause);
        uint32 pause_mode = r_u8(record + 95u);
        if (pause_mode == 1u)
        {
            if (r_u8(record + 92u) >= 2u)
                w_u32(r_u32(object + 108u) + 40u, 0x800662CCu);
            w_u32(object + 156u, 0u);
            w_u32(object + 160u, r_u32(record + 60u));
        }
        else if (pause_mode == 2u || pause_mode == 3u)
        {
            uint32 delay_offset = pause_mode == 2u ? 144u : 148u;
            w_u32(object + 156u, r_u32(object + delay_offset));
            w_u32(object + 160u, r_u32(object + delay_offset) + r_u32(record + 60u));
        }
    }
    if ((sint32)r_u32(record + 76u) >= 0)
        ob_game_80092B74(object, 0u, time + r_u32(object + 140u));
    ob_game_80092BD8(object);
    uint32 result = r_u32(output);
    ob_draft_scratch_release(output);
    return result;
}

uint32 ob_game_800B66C4(uint32 object, uint32 owner, uint32 request, uint32 time)
{
    FUNCTION_MARKER(0x800B66C4u, "GAME.BIN");
    sub_80043600(object, (sint32)owner, 0);
    w_u32(object, 0x800C5B58u);
    ob_game_80095528(object, 14u, 0x800B6C38u, time);
    w_u32(object + 44u, sub_80044E5C(object, 0x80073660u, time));
    uint32 shape = sub_80043E3C(object, 0x80073638u);
    uint32 node = r_u32(object + 44u);
    w_u32(object + 48u, shape);
    w_u32(node + 8u, 0x10000001u);
    w_u32(r_u32(object + 48u) + 48u, 0x10000001u);
    shape = r_u32(object + 48u);
    w_u32(shape + 40u, r_u32(request + 64u));
    sub_80044130(r_u32(object + 48u));
    sub_80045848(r_u32(object + 44u), request + 12u);
    sub_800458B4(r_u32(object + 44u), request, time);
    sint32 radius = (sint16)r_u16(request + 60u);
    shape = r_u32(object + 48u);
    if (radius < 0) radius = -radius;
    sub_800440B8(shape, (uint32)(sint32)(sint16)radius);
    ob_draft_unresolved_call(0x800285A4u, 3u, request + 24u, r_u32(request + 44u), r_u32(object + 44u) + 132u);
    sint32 kind = (sint16)r_u16(request + 86u);
    if (kind == 0 || kind == 6 || kind == 2 || kind == 4 || kind == 5 || kind == 7)
    {
        for (uint32 axis = 0u; axis < 3u; ++axis)
        {
            node = r_u32(object + 44u);
            uint32 addition = r_u32(request + 32u + axis * 4u);
            uint32 velocity = r_u32(node + 132u + axis * 4u);
            if (kind != 0 && kind != 6)
                addition = (uint32)((sint32)addition / 3);
            w_u32(node + 132u + axis * 4u, velocity + addition);
        }
    }
    sub_80045ADC(r_u32(object + 44u));
    kind = (sint16)r_u16(request + 86u);
    uint32 extent = kind == 7 ? (uint32)((sint32)(sint16)r_u16(request + 92u) * 14 + 400) : 100u;
    w_u32(r_u32(request + 68u) + 4u, 0x10000001u);
    ob_game_800C0F70(r_u32(request + 68u), 100u, (uint32)(sint32)(sint16)extent);
    w_u32(r_u32(request + 68u) + 32u, 200u);
    uint32 geometry = r_u32(request + 68u);
    w_u32(geometry + 36u, r_u32(request + 76u));
    w_u32(r_u32(request + 68u) + 72u, object);
    w_u32(r_u32(request + 68u) + 76u, 0u);
    uint32 position = ob_draft_scratch_acquire(8u);
    w_u32(position, 0u);
    w_u32(position + 4u, 0u);
    uint32 behavior = sub_8004E518(object, position, time, r_u32(request + 80u));
    w_u32(object + 60u, behavior);
    ob_draft_unresolved_call(0x8004E694u, 2u, behavior, 2u);
    ob_draft_scratch_release(position);
    kind = (sint16)r_u16(request + 86u);
    if (kind == 0 || kind == 7 || (uint16)(kind - 3) < 2u || kind == 5 || kind == 2 || (uint16)(kind - 9) < 2u || kind == 1)
    {
        uint32 collision = ob_draft_scratch_acquire(52u);
        w_u32(collision + 4u, 0x10000001u);
        w_u32(collision, 0u);
        w_u32(collision + 8u, 100u);
        w_u32(collision + 12u, 100u);
        w_u32(collision + 16u, 100u);
        w_u32(collision + 32u, 100u);
        w_u16(collision + 38u, 0xFFFFu);
        w_u32(collision + 20u, 0u);
        w_u32(collision + 24u, 0u);
        w_u32(collision + 28u, 0u);
        w_u16(collision + 36u, 0u);
        w_u32(collision + 40u, object);
        /* TODO The original leaves collision offset44 unspecified */
        w_u32(collision + 48u, 0x800B6E64u);
        w_u32(object + 56u, (uint32)sub_8004F074((sint32)object, (sint32)collision, (sint32)time));
        ob_draft_scratch_release(collision);
    }
    w_u16(object + 136u, 0xFFFFu);
    w_u16(object + 120u, 0xFFFFu);
    w_u32(object + 124u, time);
    uint32 type = r_u32(r_u32(request + 96u) + 96u);
    uint32 expires = time + r_u32(request + 88u);
    w_u32(object + 128u, type == 255u ? expires & 0xFFFFFFFEu : expires | 1u);
    w_u32(object + 104u, 0u);
    w_u16(object + 140u, r_u16(request + 92u));
    w_u16(object + 132u, r_u16(request + 86u));
    uint32 magnitude = r_u16(request + 84u);
    w_u16(object + 142u, 0xFFFFu);
    w_u16(object + 138u, magnitude);
    uint32 record = r_u32(request + 96u);
    w_u32(object + 116u, 0u);
    w_u32(object + 112u, record);
    w_u16(object + 148u, r_u16(request + 50u));
    uint32 speed = r_u32(request + 44u);
    w_u32(object + 156u, 0u);
    w_u32(object + 152u, speed);
    uint32 heading = r_u16(request + 52u);
    w_u32(object + 108u, 0u);
    w_u16(object + 146u, heading);
    if (r_u32(request + 72u) != 0u)
    {
        uint32 source_type = r_u32(request + 56u);
        if (source_type == 255u)
            sub_80011984(r_u32(request + 72u), 64u, 15u, 15u, 256u, 0u, 0u);
        else if (source_type != 0xFFFFFFFFu)
            ob_draft_unresolved_call(0x80011A24u, 6u, r_u32(request + 72u), 64u, 256u, r_u32(object + 44u), time, 0u);
    }
    w_u16(object + 134u, 0u);
    w_u16(object + 122u, 0u);
    if ((sint16)r_u16(request + 60u) < 0)
        ob_draft_unresolved_call(0x8004E66Cu, 1u, r_u32(object + 60u));
    return object;
}


uint32 ob_game_800B89D8(uint32 node, uint32 size, uint32 time)
{
    FUNCTION_MARKER(0x800B89D8u, "GAME.BIN");
    uint32 record = ob_draft_scratch_acquire(96u);
    ob_game_800B8E40(node, record, time);
    w_u32(record + 44u, 0x800C4CA4u);
    w_u32(record + 56u, 600u);
    w_u8(record + 92u, 11u);
    w_u16(record + 88u, size);
    w_u16(record + 90u, size);
    w_u16(record + 86u, size);
    w_u8(record + 93u, 1u);
    uint32 result = ob_game_80092408(r_u32(0x80083E34u), record, time, 4u);
    ob_draft_scratch_release(record);
    return result;
}
