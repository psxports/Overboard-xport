#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_800BCBB8(uint32 flags)
{
    FUNCTION_MARKER(0x800BCBB8u, "GAME.BIN");
    flags &= 0x3FFFFFFFu;
    uint32 size = (flags & 1u) != 0u ? 472u : 352u;
    if ((flags & 2u) != 0u) size += 140u;
    if ((flags & 4u) != 0u) size += 16u;
    if ((flags & 8u) != 0u) size += 28u;
    if ((flags & 0x10u) != 0u) size += 20u;
    if ((flags & 0x40u) != 0u) size += 28u;
    if ((flags & 0x80u) != 0u) size += 8u;
    if ((flags & 0x200u) != 0u) size += 32u;
    if ((flags & 0x400u) != 0u) size += 196u;
    if ((flags & 0x1000u) != 0u) size += 92u;
    if ((flags & 0x2000u) != 0u) size += 24u;
    if ((flags & 0x8000u) != 0u) size += 12u;
    if ((flags & 0x20000u) != 0u) size += 8u;
    if ((flags & 0x40000u) != 0u) size += 16u;
    if ((flags & 0x100000u) != 0u) size += 8u;
    if ((flags & 0x200000u) != 0u) size += 188u;
    if ((flags & 0x400000u) != 0u) size += 8u;
    if ((flags & 0x800000u) != 0u) size += 24u;
    if ((flags & 0x4000u) != 0u) size += 20u;
    if ((flags & 0x1000000u) != 0u) size += 12u;
    if ((flags & 0x2000000u) != 0u) size += 104u;
    if ((flags & 0x4000000u) != 0u) size += 208u;
    if ((flags & 0x8000000u) != 0u) size += 312u;
    if ((flags & 0x10000000u) != 0u) size += 16u;
    if ((flags & 0x100u) != 0u) size += 4u;
    return size;
}
