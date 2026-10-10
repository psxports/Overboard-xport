#include "psx.h"
#include "game_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800A5184(uint32 object, uint32 properties_value, uint32 record, uint32 limit)
{
    FUNCTION_MARKER(0x800A5184u, "GAME.BIN");
    uint32 serial = r_u32(0x800C9AB0u);
    w_u16(object + 308u, limit);
    w_u32(object + 288u, properties_value);
    w_u32(object + 128u, 0u);
    w_u16(object + 326u, 0xFFFFu);
    w_u16(object + 302u, serial);
    uint32 heading = r_u16(record + 16u);
    w_u32(0x800C9AB0u, serial + 1u);
    uint32 object_type = r_u32(object + 292u);
    w_u16(object + 296u, heading);
    uint32 pitch = r_u16(record + 18u);
    w_u16(object + 300u, 0xFFFFu);
    w_u32(object + 284u, 0u);
    w_u32(object + 280u, 0u);
    w_u16(object + 306u, 0xFFFFu);
    w_u8(object + 324u, 0u);
    w_u32(object + 332u, 0u);
    w_u16(object + 336u, 0u);
    w_u16(object + 304u, pitch);
    uint32 result;
    if (object_type == 64u)
        result = 64u;
    else if (object_type < 65u)
    {
        if (object_type == 58u)
            result = 1u;
        else if (object_type < 59u)
        {
            if (object_type == 6u)
            {
                result = 0u - 750u;
                w_u32(record + 4u, result);
                return result;
            }
            result = 56u;
            if (object_type != 56u)
                return result;
        }
        else
        {
            result = 62u;
            if (object_type != 60u && object_type != 62u)
                return result;
        }
    }
    else if (object_type == 77u || object_type == 75u)
    {
        result = (uint32)r_u16(object + 296u) - 0x8000u;
        w_u16(object + 296u, result);
        return result;
    }
    else if (object_type < 78u)
    {
        result = 75u;
        if (object_type != 72u)
            return result;
    }
    else
    {
        result = object_type == 167u ? 0u - 1000u : 200u;
        if (object_type == 167u || object_type == 235u)
            w_u32(record + 4u, result);
        return result;
    }
    w_u16(object + 296u, 0u);
    w_u16(record + 16u, 0u);
    return result;
}
