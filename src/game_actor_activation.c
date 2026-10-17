#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"

uint32 ob_game_80099798(uint32 first_position, uint32 second_position)
{
    FUNCTION_MARKER(0x80099798u, "GAME.BIN");
    uint32 first_x = r_u32(first_position);
    uint32 second_x = r_u32(second_position);
    uint32 x = first_x - second_x;
    if ((sint32)x < 0)
        x = second_x - first_x;
    uint32 first_z = r_u32(first_position + 8u);
    uint32 second_z = r_u32(second_position + 8u);
    uint32 z = first_z - second_z;
    if ((sint32)z < 0)
        z = second_z - first_z;
    return x < z ? z + (x >> 1) : x + (z >> 1);
}

uint32 ob_game_800AEE18(uint32 time, uint32 distance, uint32 descriptor,
    uint32 slot, uint32 threshold)
{
    FUNCTION_MARKER(0x800AEE18u, "GAME.BIN");
    uint32 flags = r_u8(descriptor + 92u);
    if ((flags & 0xF0u) != 0u)
    {
        uint32 result = flags - 16u;
        w_u8(descriptor + 92u, result);
        return result;
    }
    if (distance < threshold)
    {
        return ob_game_800AE36C(
            descriptor, (uint32)(sint32)(sint16)slot, time);
    }
    uint32 type = r_u32(descriptor + 96u);
    if (type == 33u)
        return 1u;
    if (type != 229u)
        return 229u;
    uint32 created_time = r_u32(descriptor);
    uint32 lifetime = r_u16(descriptor + 52u);
    uint32 elapsed = time - created_time + 1000u;
    if ((sint32)lifetime < (sint32)elapsed)
        return ob_game_800A0B38(descriptor);
    return elapsed;
}

uint32 ob_game_800AEEB8(uint32 time, uint32 distance, uint32 descriptor,
    uint32 threshold)
{
    FUNCTION_MARKER(0x800AEEB8u, "GAME.BIN");
    if (distance < threshold)
        return time;
    return ob_game_800AEB60(descriptor, time);
}
