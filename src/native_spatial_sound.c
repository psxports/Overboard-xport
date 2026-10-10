#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"
#include "native_extra_signatures.h"

void ob_main_80011E20(uint32 voice, uint32 node, uint32 volume, uint32 time)
{
    FUNCTION_MARKER(0x80011E20u, "SLES_008.65");
    if ((sint32)voice < 0) return;
    uint32 position = sub_80045464(node, time);
    uint32 distance = ob_game_80094524(position);
    uint32 level = 0u;
    if (distance < 20000u)
    {
        uint32 attenuation = ((20000u - distance) * 255u) / 20000u;
        level = (uint32)((sint32)(attenuation * volume) >> 8);
        uint32 pan = ob_game_8009459C(position);
        uint32 separation = r_u32(0x80065B70u) != 0u ? ob_game_8009464C(position) : 15u;
        sub_80011DA0((sint32)voice, pan);
        sub_80011DC0(voice, separation);
    }
    sub_80011DE0(voice, (sint32)level);
}

uint32 ob_main_80028784(uint32 first, uint32 second)
{
    FUNCTION_MARKER(0x80028784u, "SLES_008.65");
    uint32 x1 = (uint32)(sint32)(sint16)r_u16(first);
    uint32 x2 = (uint32)(sint32)(sint16)r_u16(second);
    uint32 sum = x1 * x2;
    uint32 y1 = (uint32)(sint32)(sint16)r_u16(first + 2u);
    uint32 y2 = (uint32)(sint32)(sint16)r_u16(second + 2u);
    uint32 y_product = y1 * y2;
    uint32 z1 = (uint32)(sint32)(sint16)r_u16(first + 4u);
    uint32 z2 = (uint32)(sint32)(sint16)r_u16(second + 4u);
    sum += y_product;
    sum += z1 * z2;
    return (uint32)((sint32)(sum << 2) >> 16);
}

uint32 ob_game_80094524(uint32 position)
{
    FUNCTION_MARKER(0x80094524u, "GAME.BIN");
    uint32 dx = (uint32)((sint32)(r_u32(position) - r_u32(0x800C4CD0u)) >> 8);
    uint32 x_squared = dx * dx;
    uint32 dz = (uint32)((sint32)(r_u32(position + 8u) - r_u32(0x800C4CD8u)) >> 8);
    uint32 squared = x_squared + dz * dz;
    if ((sint32)squared > 65535) return 0xFFFFFFFFu;
    return (sub_8002B868(squared) & 65535u) << 8;
}

static uint32 ob_sound_direction_level(uint32 position, uint32 direction, sint32 divisor)
{
    uint32 vector = ob_draft_scratch_acquire(12u);
    uint32 compact = ob_draft_scratch_acquire(8u);
    w_u32(vector, r_u32(position) - r_u32(0x800C4CD0u));
    w_u32(vector + 4u, r_u32(position + 4u) - r_u32(0x800C4CD4u));
    w_u32(vector + 8u, r_u32(position + 8u) - r_u32(0x800C4CD8u));
    sub_80029290(vector, compact);
    uint32 value = ob_main_80028784(direction, compact);
    sint32 level = (sint16)value / divisor + 16;
    if (level < 0) level = 0;
    if (level >= 31) level = 30;
    ob_draft_scratch_release(compact);
    ob_draft_scratch_release(vector);
    return (uint32)level;
}

uint32 ob_game_8009459C(uint32 position)
{
    FUNCTION_MARKER(0x8009459Cu, "GAME.BIN");
    return ob_sound_direction_level(position, 0x800D64A0u, 512);
}

uint32 ob_game_8009464C(uint32 position)
{
    FUNCTION_MARKER(0x8009464Cu, "GAME.BIN");
    return ob_sound_direction_level(position, 0x800D64ACu, 1024);
}

uint32 ob_main_80011A24(uint32 sound, uint32 volume, uint32 pitch, uint32 node, uint32 time, uint32 flags)
{
    FUNCTION_MARKER(0x80011A24u, "SLES_008.65");
    sint32 index = (sint32)r_u32(sound) / 4;
    if (index < 0) return 0xFFFFFFFFu;
    uint32 position = sub_80045464(node, time);
    uint32 distance = ob_game_80094524(position);
    if (r_u8(0x8006C231u) < 20u && distance >= 20000u)
    {
        distance = 20000u;
        if ((flags & 1u) == 0u) return 0u;
    }
    uint32 stamp_address = 0x8008C718u + (uint32)index * 4u;
    uint32 previous = r_u32(stamp_address);
    if (previous != 0xFFFFFFFFu && (flags & 3u) == 0u && (sint32)time >= (sint32)previous)
        if ((sint32)(time - previous) < 100) return 0xFFFFFFFFu;
    w_u32(stamp_address, time);
    uint32 level = volume;
    if (r_u8(0x8006C231u) < 20u)
    {
        uint32 attenuation = ((20000u - distance) * 255u) / 20000u;
        level = (uint32)((sint32)(attenuation * volume) / 256);
    }
    uint32 pan = ob_game_8009459C(position);
    uint32 separation = r_u32(0x80065B70u) != 0u ? ob_game_8009464C(position) : 15u;
    return sub_80011984(sound, level, pan, separation, pitch, 4u, flags & 1u);
}
