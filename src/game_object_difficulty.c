#include "psx.h"
#include "xport.h"
#include "game_signatures.h"

uint32 ob_game_80099514(uint32 object)
{
    FUNCTION_MARKER(0x80099514u, "GAME.BIN");
    if (r_u32(object + 292u) == 255u)
        return 1u;
    uint32 difficulty = r_u8(0x8006C22Cu);
    if (difficulty == 0u || difficulty == 2u || difficulty == 3u)
    {
        uint32 offset = (uint32)(sint32)r_s16(object + 326u) * 104u;
        uint32 value = r_u16(0x800CBA46u + offset);
        if (difficulty == 0u)
            value >>= 1;
        else if (difficulty == 2u)
            value = (value * 3u) >> 1;
        else
            value <<= 1;
        w_u16(0x800CBA46u + offset, value);
    }
    uint32 fields = r_u32(object + 120u);
    if (fields == 0u)
        return 1u;
    difficulty = r_u8(0x8006C22Cu);
    if (difficulty == 1u)
        return 1u;
    if (difficulty == 0u)
    {
        uint32 first = r_u16(fields + 104u);
        uint32 second = r_u16(fields + 106u);
        uint32 third = r_u16(fields + 108u);
        uint32 fourth = r_u16(fields + 110u);
        w_u16(fields + 104u, first);
        w_u16(fields + 106u, second);
        w_u16(fields + 108u, third);
        w_u16(fields + 110u, fourth);
        return first;
    }
    if (difficulty == 2u)
    {
        sint32 first = r_s16(fields + 104u);
        sint32 second = r_s16(fields + 106u);
        w_u16(fields + 104u, (uint32)(first / 2));
        sint32 third = r_s16(fields + 108u);
        w_u16(fields + 106u, (uint32)(second / 2));
        sint32 fourth = r_s16(fields + 110u);
        w_u16(fields + 108u, (uint32)(third / 2));
        sint32 result = fourth / 2;
        w_u16(fields + 110u, (uint32)result);
        return (uint32)result;
    }
    if (difficulty == 3u)
    {
        sint32 first = r_s16(fields + 104u);
        sint32 second = r_s16(fields + 106u);
        sint32 third = r_s16(fields + 108u);
        sint32 fourth = r_s16(fields + 110u);
        w_u16(fields + 104u, (uint32)(first / 3));
        w_u16(fields + 106u, (uint32)(second / 3));
        w_u16(fields + 108u, (uint32)(third / 3));
        sint64 product = (sint64)fourth * 1431655766;
        uint32 result = (uint32)((uint64)product >> 32);
        w_u16(fields + 110u, result - (uint32)(fourth < 0 ? -1 : 0));
        return result;
    }
    return 3u;
}
