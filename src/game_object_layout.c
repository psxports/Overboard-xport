#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_800BCD2C(uint32 object, uint32 flags)
{
    FUNCTION_MARKER(0x800BCD2Cu, "GAME.BIN");
    uint32 offset = 352u;
    flags &= 0x3FFFFFFFu;
    w_u32(object + 104u, 0u);
    w_u32(object + 108u, 0u);
    w_u32(object + 116u, 0u);
    w_u32(object + 120u, 0u);
    w_u32(object + 124u, 0u);
    w_u32(object + 128u, 0u);
    w_u32(object + 136u, 0u);
    w_u32(object + 140u, 0u);
    w_u32(object + 144u, 0u);
    w_u32(object + 132u, 0u);
    if ((flags & 1u) != 0u)
    {
        w_u32(object + 116u, object + 352u);
        offset = 472u;
    }
    if ((flags & 2u) != 0u)
    {
        w_u32(object + 120u, object + offset);
        offset += 140u;
    }
    if ((flags & 4u) != 0u)
    {
        w_u32(object + 124u, object + offset);
        offset += 16u;
    }
    if ((flags & 8u) != 0u)
    {
        w_u32(object + 128u, object + offset);
        offset += 28u;
    }
    if ((flags & 0x40u) != 0u)
    {
        w_u32(object + 108u, object + offset);
        offset += 28u;
    }
    if ((flags & 0x80u) != 0u)
    {
        w_u32(object + 108u, object + offset);
        offset += 8u;
    }
    if ((flags & 0x200u) != 0u)
    {
        w_u32(object + 108u, object + offset);
        offset += 32u;
    }
    if ((flags & 0x400u) != 0u)
    {
        w_u32(object + 108u, object + offset);
        offset += 196u;
    }
    if ((flags & 0x1000u) != 0u)
    {
        w_u32(object + 108u, object + offset);
        offset += 92u;
    }
    if ((flags & 0x2000u) != 0u)
    {
        w_u32(object + 108u, object + offset);
        offset += 24u;
    }
    if ((flags & 0x8000u) != 0u)
    {
        w_u32(object + 108u, object + offset);
        offset += 12u;
    }
    if ((flags & 0x20000u) != 0u)
    {
        w_u32(object + 108u, object + offset);
        offset += 8u;
    }
    if ((flags & 0x40000u) != 0u)
    {
        w_u32(object + 108u, object + offset);
        offset += 16u;
    }
    if ((flags & 0x100000u) != 0u)
    {
        w_u32(object + 108u, object + offset);
        offset += 8u;
    }
    if ((flags & 0x200000u) != 0u)
    {
        w_u32(object + 108u, object + offset);
        offset += 188u;
    }
    if ((flags & 0x400000u) != 0u)
    {
        w_u32(object + 108u, object + offset);
        offset += 8u;
    }
    if ((flags & 0x800000u) != 0u)
    {
        w_u32(object + 108u, object + offset);
        offset += 24u;
    }
    if ((flags & 0x4000u) != 0u)
    {
        w_u32(object + 108u, object + offset);
        offset += 20u;
    }
    if ((flags & 0x1000000u) != 0u)
    {
        w_u32(object + 108u, object + offset);
        offset += 12u;
    }
    if ((flags & 0x2000000u) != 0u)
    {
        w_u32(object + 136u, object + offset);
        offset += 104u;
    }
    if ((flags & 0x4000000u) != 0u)
    {
        uint32 first = object + offset;
        offset += 104u;
        uint32 second = object + offset;
        offset += 104u;
        w_u32(object + 136u, first);
        w_u32(object + 140u, second);
    }
    if ((flags & 0x8000000u) != 0u)
    {
        uint32 first = object + offset;
        offset += 104u;
        uint32 second = object + offset;
        offset += 104u;
        uint32 third = object + offset;
        offset += 104u;
        w_u32(object + 136u, first);
        w_u32(object + 140u, second);
        w_u32(object + 144u, third);
    }
    if ((flags & 0x10000000u) != 0u)
    {
        w_u32(object + 108u, object + offset);
        offset += 16u;
    }
    uint32 result = object + offset;
    if ((flags & 0x100u) != 0u)
        w_u32(object + 108u, result);
    return result;
}
