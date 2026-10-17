#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_800BCFBC(uint32 object, uint32 owner, uint32 record, uint32 context)
{
    FUNCTION_MARKER(0x800BCFBCu, "GAME.BIN");
    sub_80043600(object, (sint32)owner, 0);
    uint32 child = r_u32(object + 136u);
    if (child != 0u)
        sub_80043600(child, (sint32)owner, 0);
    w_u32(object + 104u, owner);
    ob_game_800C0FA8(object + 248u, record);
    uint32 resource = r_u32(object + 292u);
    w_u32(0x800D6750u, record);
    /* TODO Bind the reached GAME resource and attribute helpers */
    uint32 definition = ob_draft_unresolved_call(0x800901FCu, 2u, resource, 0u);
    ob_draft_unresolved_call(0x800A5184u, 4u, object, r_u32(definition + 20u), record, (uint32)(sint32)r_s16(definition + 18u));
    if ((r_u32(object + 276u) & 16u) != 0u)
        ob_draft_unresolved_call(0x800B9E84u, 1u, object);
    uint32 type = r_u32(record + 12u);
    uint32 data;
    uint32 result;
    uint32 variant;
    switch (type)
    {
    case 2u:
        w_u16(object + 320u, 2048u);
        w_u8(object + 323u, 4u);
        return 4u;
    case 13u:
        return ob_draft_unresolved_call(0x800C0CF4u, 2u, object, record);
    case 33u:
        data = r_u32(object + 108u);
        w_u16(data + 42u, 19200u);
        w_u16(data + 40u, 19200u);
        data = r_u32(object + 116u);
        result = (r_u32(data + 64u) * 3u) >> 1;
        w_u32(data + 68u, result);
        return result;
    case 48u: case 50u:
        data = r_u32(object + 108u);
        if (type == 48u)
            w_u32(data + 12u, r_u16(record + 18u));
        variant = (r_u8(record + 24u) >> 4) & 3u;
        result = variant == 0u ? 1000u : variant == 1u ? 800u : 600u;
        if (variant < 3u)
            w_u32(data + 16u, result);
        return result;
    case 52u:
        data = r_u32(object + 108u);
        w_u32(data + 20u, 5000u);
        variant = (r_u8(record + 24u) >> 4) & 3u;
        result = variant == 0u ? 1000u : variant == 1u ? 3500u : variant == 2u ? 2000u : 600u;
        if (variant < 3u)
        {
            w_u32(data + 16u, variant == 0u ? 1000u : variant == 1u ? 800u : 600u);
            w_u32(data + 24u, variant == 0u ? 5000u : result);
        }
        return result;
    case 54u: case 66u: case 74u: case 75u:
        data = r_u32(object + 108u);
        w_u32(data + 20u, r_u16(record + 18u));
        result = r_u16(record + 20u);
        w_u32(data + 24u, result);
        return result;
    case 56u: case 58u:
        data = r_u32(object + 108u);
        w_u32(data + 12u, r_u16(record + 18u));
        result = r_u16(record + 20u);
        w_u32(data + 16u, result);
        return result;
    case 60u: case 62u:
        data = r_u32(object + 108u);
        if (type == 60u)
            w_u32(data + 12u, r_u16(record + 18u));
        variant = (r_u8(record + 24u) >> 4) & 3u;
        if (variant < 3u)
        {
            w_u32(data + 20u, variant == 0u ? 5000u : variant == 1u ? 3200u : 1800u);
            result = variant == 0u ? 1000u : variant == 1u ? 800u : 600u;
            w_u32(data + 16u, result);
            return result;
        }
        return 1800u;
    case 70u: case 77u:
        w_u32(r_u32(object + 108u) + 16u, 2500u);
        return 2500u;
    case 72u:
        data = r_u32(object + 108u);
        variant = (r_u8(record + 24u) >> 4) & 3u;
        if (variant < 3u)
        {
            w_u32(data + 20u, variant == 0u ? 6000u : variant == 1u ? 4000u : 1000u);
            result = variant == 0u ? 3000u : variant == 1u ? 2000u : 1000u;
            w_u32(data + 16u, result);
            return result;
        }
        return 1000u;
    case 149u: case 153u:
        data = r_u32(object + 108u);
        child = r_u32(0x800C8490u);
        w_u16(data + 6u, type == 149u ? 13955u : 16384u);
        w_u16(data + 4u, r_u16(record + 16u));
        w_u16(object + 312u, type == 149u ? 2u : 1u);
        w_u32(data, child);
        w_u8(child + 324u, 1u);
        result = r_u32(data);
        w_u32(result + 132u, object);
        return result;
    case 162u: case 163u:
        result = r_u32(object + 108u);
        w_u32(result, 0u);
        w_u32(result + 16u, 0u);
        return result;
    case 164u: case 167u:
        result = r_u32(object + 108u);
        w_u32(result, 0u);
        w_u32(result + 8u, 100u);
        w_u32(result + 12u, 100u);
        w_u16(result + 16u, r_u16(record + 20u));
        return result;
    case 229u: case 230u:
        child = r_u32(0x800D6750u);
        data = r_u32(object + 108u);
        w_u32(data + 4u, r_u16(child + 18u));
        result = r_u16(child + 20u) * 1000u + context;
        w_u32(data + 8u, result);
        return result;
    case 234u:
        data = r_u32(object + 108u);
        w_u8(data + 183u, 0u);
        result = r_u16(record + 20u);
        w_u8(data + 184u, result);
        return result;
    case 236u:
        w_u32(r_u32(object + 108u) + 4u, 20u);
        return 20u;
    case 238u:
        ob_draft_unresolved_call(0x800C0CF4u, 2u, object, record);
        /* Fall through to the shared attached-object initialization */
    case 174u:
        data = r_u32(object + 108u);
        child = r_u32(0x800C8490u);
        w_u32(data, child);
        w_u8(child + 324u, 1u);
        result = r_u32(data);
        w_u32(result + 132u, object);
        return result;
    case 255u:
        data = r_u32(object + 108u);
        w_u32(data, 0u);
        uint32 initial = r_u8(0x8006C246u);
        w_u8(data + 47u, 0u);
        w_u32(data + 92u, 0u);
        w_u16(data + 172u, 0u);
        w_u16(data + 104u, 65535u);
        w_u8(data + 44u, initial);
        if (r_u8(0x8006C230u) >= 2u)
        {
            w_u8(data + 44u, 0u);
            for (uint32 i = 0u; i < 8u; ++i)
            {
                sint32 value = r_s8(0x8006C254u + i);
                if (value != 0)
                {
                    w_u8(data + 130u + i, (uint32)value - 1u);
                    w_u8(data + 106u + i, 1u);
                }
                else
                    w_u8(data + 106u + i, 0u);
            }
            for (uint32 i = 0u; i < 5u; ++i)
                w_u16(data + 120u + i * 2u, r_u16(0x8006C24Au + i * 2u));
        }
        else
        {
            w_u8(data + 44u, r_u8(0x800899F2u));
            for (uint32 i = 0u; i < 13u; ++i)
            {
                w_u8(data + 106u + i, r_u8(0x800899CEu + i));
                w_u8(data + 130u + i, r_u8(0x800899DBu + i));
            }
            for (uint32 i = 0u; i < 5u; ++i)
                w_u16(data + 120u + i * 2u, r_u16(0x800899E8u + i * 2u));
        }
        for (uint32 table = 0u; table < 5u; ++table)
            for (uint32 i = 0u; i < 13u; ++i)
            {
                uint32 value = r_u32(0x800899F8u + table * 52u + i * 4u);
                uint32 destination = r_u32(0x80065CB0u + table * 4u);
                w_u32(destination + i * 4u, value);
            }
        w_u16(data + 152u, 0u);
        w_u16(data + 154u, 0u);
        w_u16(data + 156u, 0u);
        w_u16(data + 48u, r_u16(record + 16u));
        child = r_u32(object + 124u);
        w_u32(0x80089990u, context + 500u);
        w_u32(child + 8u, context);
        child = r_u32(object + 124u);
        w_u8(0x80086A2Cu, 255u);
        w_u32(child + 12u, context);
        child = r_u32(object + 124u);
        uint32 angle = r_u16(record + 16u);
        w_u32(0x800D658Cu, 1u);
        w_u16(child + 4u, angle);
        return 1u;
    default:
        /* Preserve the actual switch arithmetic or default jump-address return */
        return (type - 2u) < 254u ? 0x800BD7C4u : (type - 2u) * 4u;
    }
}
