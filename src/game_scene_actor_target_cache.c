#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_80092190(uint32 object, uint32 time)
{
    FUNCTION_MARKER(0x80092190u, "GAME.BIN");
    if (r_u8(0x8006C230u) != 1u)
        return 1u;
    uint32 attributes = r_u32(object + 108u);
    ob_game_80097578(object, 0x800C90F8u, time);
    uint32 offset = (uint32)(sint32)r_s16(object + 326u) * 104u;
    uint32 x = r_u32(0x800C9104u);
    uint32 cached = r_u32(0x800CBA20u + offset);
    uint32 equal = x == cached;
    if (equal != 0u)
    {
        uint32 y = r_u32(0x800C9108u);
        cached = r_u32(0x800CBA24u + offset);
        equal = y == cached;
        if (equal != 0u)
        {
            uint32 z = r_u32(0x800C910Cu);
            cached = r_u32(0x800CBA28u + offset);
            equal = z == cached;
        }
    }
    if (equal != 0u)
    {
        uint32 result = (uint32)(sint32)r_s16(attributes + 4u);
        if (result != 0u)
            return result;
        result = (uint32)r_u16(attributes) + 1u;
        w_u16(attributes, result);
        return result;
    }
    w_u16(attributes, 0u);
    /* Reload the slot and source before each ordered cache write */
    offset = (uint32)(sint32)r_s16(object + 326u) * 104u;
    x = r_u32(0x800C9104u);
    w_u32(0x800CBA20u + offset, x);
    offset = (uint32)(sint32)r_s16(object + 326u) * 104u;
    uint32 y = r_u32(0x800C9108u);
    w_u32(0x800CBA24u + offset, y);
    offset = (uint32)(sint32)r_s16(object + 326u) * 104u;
    uint32 z = r_u32(0x800C910Cu);
    w_u32(0x800CBA28u + offset, z);
    return offset;
}
