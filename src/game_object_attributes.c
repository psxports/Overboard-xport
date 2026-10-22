#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800BE604(uint32 object, uint32 attributes, uint32 context)
{
    FUNCTION_MARKER(0x800BE604u, "GAME.BIN");
    uint32 type, descriptor = 0u, callback = 0u, result, player;
    uint32 vector, index, angle, record, mode;
    sint32 heading, distance, dx, dz, extent;
    sint16 distances[5];
    w_u32(attributes + 4u, 0x10000001u);
    w_u32(attributes, 0u);
    type = r_u32(object + 292u);
    /* TODO Bind remaining original GAME attribute helpers when reached */
    switch (type)
    {
    case 2u:
    case 7u:
    case 12u:
        ob_draft_unresolved_call(0x800C0F54u, 2u, attributes, 500u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C33E4u);
        callback = 0x800AFF6Cu;
        goto set_callback;
    case 3u:
    case 4u:
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 1000u, 1000u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C3434u);
        result = r_u32(r_u32(object + 48u) + 48u);
        w_u32(attributes + 80u, 0x80091AC8u);
        w_u32(attributes + 4u, result);
        goto create;
    case 6u:
    case 20u:
    case 21u:
    case 22u:
    case 23u:
    case 24u:
    case 25u:
    case 26u:
    case 27u:
    case 28u:
    case 29u:
    case 30u:
    case 31u:
        ob_draft_unresolved_call(0x800C0F54u, 2u, attributes, 1000u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C3254u);
        callback = 0x800AB120u;
        goto set_callback;
    case 8u:
        ob_draft_unresolved_call(0x800C0F54u, 2u, attributes, 500u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C340Cu);
        callback = 0x800AFF6Cu;
        goto set_callback;
    case 10u:
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 1000u, 500u);
        w_u32(attributes + 24u, 610u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C3344u);
        result = r_u32(r_u32(object + 48u) + 48u);
        w_u32(attributes + 80u, 0x80091AC8u);
        w_u32(attributes + 4u, result);
        goto create;
    case 11u:
        ob_draft_unresolved_call(0x800C0F54u, 2u, attributes, 1000u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C327Cu);
        callback = 0x800AB120u;
        goto set_callback;
    case 13u:
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 1500u, 1000u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C354Cu);
        callback = 0x800963B4u;
        goto set_callback;
    case 15u:
    case 16u:
    case 52u:
    case 54u:
    case 60u:
    case 66u:
    case 68u:
    case 70u:
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 1000u, 1200u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C345Cu);
        callback = 0x800A8B44u;
        goto set_callback;
    case 33u:
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 3000u, 500u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C32A4u);
        callback = 0x800A0010u;
        w_u32(attributes + 4u, 65714u);
        goto create_with_extra;
    case 36u:
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 3000u, 500u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C32F4u);
        callback = 0x800AA198u;
        w_u32(attributes + 4u, 65913u);
        goto create_with_extra;
    case 37u:
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 800u, 3200u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C336Cu);
        callback = 0x8009C9E0u;
        goto set_callback;
    case 41u:
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 1000u, 10000u);
        w_u32(attributes + 24u, 5000u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C3344u);
        callback = 0x8009CC64u;
        goto create_with_extra;
    case 48u:
    case 50u:
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 1600u, 1200u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C345Cu);
        result = r_u32(r_u32(object + 48u) + 48u);
        w_u32(attributes + 80u, 0x800A8B44u);
        w_u32(attributes + 4u, result);
        goto create;
    case 56u:
    case 58u:
    case 62u:
    case 64u:
    case 72u:
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 1000u, 1200u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C345Cu);
        result = r_u32(r_u32(object + 48u) + 48u);
        w_u32(attributes + 80u, 0x800A8B44u);
        w_u32(attributes + 4u, result);
        goto create;
    case 157u:
    case 158u:
    case 172u:
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 550u, 1000u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C34FCu);
        result = r_u32(r_u32(object + 48u) + 48u);
        w_u32(attributes + 80u, 0x800949FCu);
        w_u32(attributes + 4u, result);
        goto create;
    case 159u:
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 1500u, 1000u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C35C4u);
        callback = 0x800A73F0u;
        goto set_callback;
    case 162u:
    case 163u:
    case 173u:
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 1000u, 1000u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C34FCu);
        result = r_u32(r_u32(object + 48u) + 48u);
        w_u32(attributes + 80u, 0x80094DA4u);
        w_u32(attributes + 4u, result);
        goto create;
    case 175u:
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 1500u, 1000u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C359Cu);
        callback = 0x800A7CECu;
        goto set_callback;
    case 224u:
        ob_draft_unresolved_call(0x800C0F54u, 2u, attributes, 1300u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C3484u);
        result = r_u32(r_u32(object + 48u) + 48u);
        w_u32(attributes + 80u, 0x8009DEDCu);
        w_u32(attributes + 4u, result);
        goto create;
    case 236u:
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 500u, 500u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C533Cu);
        result = r_u32(r_u32(object + 48u) + 48u);
        w_u32(attributes + 80u, 0x800BB8A4u);
        w_u32(attributes + 4u, result);
        goto create;
    case 239u:
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 1000u, 1200u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C327Cu);
        callback = 0x800AC414u;
        goto set_callback;
    case 241u:
        ob_draft_unresolved_call(0x800C0F54u, 2u, attributes, 500u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C34ACu);
        callback = 0x800AAB84u;
        goto set_callback;
    case 32u:
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 6500u, 10u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C3394u);
        w_u32(attributes + 80u, 0x8009C018u);
        result = sub_80046184(object, attributes, context);
        player = r_u32(object + 108u);
        w_u32(object + 52u, result);
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 4000u, 2000u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C3394u);
        w_u32(attributes + 80u, 0x8009C018u);
        result = sub_80046184(object, attributes, context);
        w_u32(player + 20u, result);
        return result;
    case 38u:
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, r_u32(0x800D6758u));
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, r_u32(0x800C90CCu), r_u32(0x800C8344u));
        callback = r_u32(0x800C8360u);
        goto set_callback;
    case 39u:
        if (r_u32(object + 288u) == 20u) return 20u;
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C33BCu);
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 2500u, 7000u);
        callback = 0x8009F090u;
        goto set_callback;
    case 40u:
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C33BCu);
        ob_draft_unresolved_call(0x800C0F54u, 2u, attributes, 500u);
        callback = 0x8009EF5Cu;
        goto set_callback;
    case 171u:
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 1000u, 500u);
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 1000u, 500u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C533Cu);
        callback = 0x800A6A30u;
        goto set_callback;
    case 229u: case 230u:
        mode = r_u16(r_u32(0x800D6750u) + 18u);
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 1000u, 500u);
        descriptor = mode == 25u ? 0x800C5364u : 0x800C533Cu;
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, descriptor);
        w_u32(attributes + 80u, 0x800A6A30u);
        result = sub_80046184(object, attributes, context);
        record = r_u32(0x800D6750u);
        w_u32(object + 52u, result);
        if (r_u16(record + 18u) == 17u)
            return ob_draft_unresolved_call(0x80046544u, 1u, result);
        return 17u;
    case 231u:
        descriptor = 0x800C354Cu;
        result = r_u32(r_u32(object + 48u) + 48u);
        w_u32(attributes + 80u, 0x800963B4u);
        w_u32(attributes + 4u, result);
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 1000u, 1000u);
        mode = r_u8(object + 339u);
        if (mode == 149u || mode == 153u)
        {
            w_u32(attributes + 12u, 300u);
            descriptor = 0x800C3574u;
            if (r_u16(r_u32(0x800D6750u) + 16u) & 0x4000u)
            {
                w_u32(attributes + 16u, 1000u);
                w_u32(attributes + 8u, 3500u);
            }
            else
            {
                w_u32(attributes + 16u, 3500u);
                w_u32(attributes + 8u, 1000u);
            }
        }
        else if (mode == 174u)
        {
            heading = r_s16(r_u32(0x800D6750u) + 16u);
            if (heading == -16384 || heading == 16384) w_u32(attributes + 8u, 4000u);
            else if (heading == -32768 || heading == 0) w_u32(attributes + 16u, 4000u);
        }
        else if (mode == 238u)
        {
            ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 1000u, 1200u);
            descriptor = 0x800C327Cu;
            w_u32(attributes + 80u, 0x800AC414u);
        }
        if (r_u16(r_u32(0x800D6750u) + 20u) == 246u)
        {
            result = r_u32(0x800C82F0u);
            record = r_u32(0x800C82F4u);
            mode = r_u32(0x800C82F8u);
            w_u32(attributes + 8u, result);
            w_u32(attributes + 12u, record);
            w_u32(attributes + 16u, mode);
        }
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, descriptor);
        goto create;
    case 160u:
        record = r_u32(0x800D6750u);
        mode = r_u16(record + 18u);
        if (mode == 1u)
        {
            w_u32(attributes + 20u, 0u);
            w_u32(attributes + 24u, 0u);
            w_u32(attributes + 28u, 0u);
            heading = r_s16(record + 16u);
            player = r_u32(0x80077644u);
            result = r_u32(player);
            if (heading != 0 && heading != -32768)
            {
                w_u32(attributes + 12u, 100u);
                w_u32(attributes + 8u, (uint32)((sint32)result >> 1));
                w_u32(attributes + 16u, r_u32(player));
            }
            else
            {
                w_u32(attributes + 12u, 100u);
                w_u32(attributes + 8u, result);
                w_u32(attributes + 16u, (uint32)((sint32)r_u32(player) >> 1));
            }
        }
        else if (mode == 0u || mode == 2u)
        {
            extent = (sint32)r_u32(r_u32(0x80077644u));
            if (mode == 0u) extent >>= 1;
            ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, (uint32)extent, 100u);
        }
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C3524u);
        w_u32(attributes + 80u, 0x800BB7DCu);
        result = sub_80046184(object, attributes, context);
        w_u32(object + 52u, result);
        result = ob_draft_unresolved_call(0x80049ED4u, 3u, result, 32u, context);
        if (result != 0u)
            return ob_draft_unresolved_call(0x800BA234u, 3u, r_u8(r_u32(0x800D6750u) + 27u), 1u, context);
        return result;
    case 242u:
        extent = (sint32)r_u32(r_u32(0x80077644u));
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, (uint32)(extent >> 2), 100u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C3524u);
        callback = 0x800BB848u;
        goto set_callback;
    case 243u: case 244u: case 245u: case 246u:
        /* The copied table is an ordinary local value, not a guest ABI frame */
        for (index = 0u; index < 5u; ++index)
            distances[index] = r_s16(0x8008F74Cu + index * 2u);
        extent = (sint32)r_u32(r_u32(0x80077644u));
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, (uint32)((extent / 3) >> 1), 100u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C3524u);
        w_u32(attributes + 80u, 0x800BB848u);
        result = sub_80046184(object, attributes, context);
        type = r_u32(object + 292u);
        w_u32(object + 52u, result);
        angle = ((uint32)r_u16(object + 296u) + 8u) >> 4;
        /* Keep the created attributes if the type no longer names a distance entry */
        if (type - 243u >= 5u) return result;
        distance = distances[type - 243u];
        dx = (sint32)((uint32)distance * (uint32)((sint32)((uint32)r_u16(0x8006CB04u + angle * 2u) << 16) >> 30));
        dz = (sint32)((uint32)distance * (uint32)((sint32)((uint32)r_u16(0x8006C304u + angle * 2u) << 16) >> 30));
        vector = ob_draft_scratch_acquire(12u);
        record = r_u32(0x800D6750u);
        w_u32(vector + 4u, 0u);
        w_u32(vector, r_u32(record) + (uint32)dx);
        w_u32(vector + 8u, r_u32(record + 8u) + (uint32)dz);
        ob_draft_unresolved_call(0x800C0EB0u, 3u, vector, object, context);
        record = r_u32(0x800D6750u);
        w_u32(vector, r_u32(record) - (uint32)dx);
        w_u32(vector + 8u, r_u32(record + 8u) - (uint32)dz);
        result = ob_draft_unresolved_call(0x800C0EB0u, 3u, vector, object, context);
        ob_draft_scratch_release(vector);
        return result;
    case 247u:
        extent = (sint32)r_u32(r_u32(0x80077644u));
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, (uint32)(extent / 3) * 2u, 100u);
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C3524u);
        callback = 0x800BB848u;
        goto set_callback;
    case 161u: case 168u:
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, 0x800C3614u);
        if (r_u16(object + 270u) != 0u)
            ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 33u, 10000u);
        else ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 1075u, 1000u);
        callback = 0x800B51B0u;
        goto set_callback;
    case 255u:
        ob_draft_unresolved_call(0x800C0F70u, 3u, attributes, 800u, 1200u);
        w_u32(attributes + 24u, 1200u);
        player = r_u32(object + 108u);
        if (r_u32(player + 180u) != 0u) descriptor = 0x800C322Cu;
        else if (r_s16(player + 172u) != 0) descriptor = 0x800C3204u;
        else descriptor = 0x800C31DCu;
        ob_draft_unresolved_call(0x8008FFE0u, 3u, object, attributes, descriptor);
        callback = 0x800B271Cu;
        goto set_callback;
    default:
        /* The jump table leaves its default target in the original return carrier */
        return type - 2u < 254u ? 0x800BF4D4u : 0u;
    }
create_with_extra:
    w_u32(attributes + 80u, callback);
    result = sub_80046184(object, attributes, context);
    w_u32(object + 52u, result);
    return ob_draft_unresolved_call(0x800A1D74u, 2u, object, context);
set_callback:
    w_u32(attributes + 80u, callback);
create:
    result = sub_80046184(object, attributes, context);
    w_u32(object + 52u, result);
    return result;
}
