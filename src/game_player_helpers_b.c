#include "psx.h"
#include "draft_signatures.h"

uint32 ob_game_800A0BE8(void)
{
    FUNCTION_MARKER(0x800A0BE8u, "GAME.BIN");
    uint32 record = 0x800CBA00u;
    for (uint32 index = 0u; index < 400u; ++index)
    {
        /* TODO: Bind the observed GAME record reset helper */
        ob_draft_unresolved_call(0x800A0B38u, 1u, record);
        record += 104u;
    }
    return 0u;
}

uint32 ob_game_800A4A98(void)
{
    FUNCTION_MARKER(0x800A4A98u, "GAME.BIN");
    uint32 difficulty = r_u8(0x8006C22Cu);
    w_u8(0x800D6766u, 0u);
    w_u8(0x800C61B1u, 0u);
    uint32 mask = 1u << (difficulty & 31u);
    w_u8(0x800C8314u, mask);
    return mask;
}

uint32 ob_game_800A4A34(void)
{
    FUNCTION_MARKER(0x800A4A34u, "GAME.BIN");
    uint32 descriptor = r_u32(0x80077190u);
    uint32 index = 0u;
    uint32 output = r_u32(0x8007719Cu);
    do
    {
        w_u32(output, 0u);
        ++index;
        output += 4u;
    }
    while (index <= r_u8(descriptor + 3u));
    sint32 offset = 0xA218;
    do
    {
        w_u32(0x800CBA48u + (uint32)offset, 0u);
        offset -= 104;
    }
    while (offset >= 0);
    return (uint32)offset;
}

uint32 ob_game_80092138(void)
{
    FUNCTION_MARKER(0x80092138u, "GAME.BIN");
    if (r_u8(0x8006C230u) != 1u)
        return 1u;
    /* TODO: The original initializes only 24 bytes of this 28-byte descriptor */
    uint32 descriptor = ob_draft_scratch_acquire(28u);
    w_u32(descriptor + 4u, 6500u);
    w_u32(descriptor, 0u);
    w_u32(descriptor + 8u, 0u);
    w_u32(descriptor + 12u, 156u);
    w_u16(descriptor + 20u, 0u);
    w_u16(descriptor + 22u, 0u);
    w_u16(descriptor + 16u, 0u);
    w_u16(descriptor + 18u, 0u);
    /* TODO: Bind the observed GAME descriptor creation helper */
    uint32 result = ob_draft_unresolved_call(0x800A50BCu, 1u, descriptor);
    ob_draft_scratch_release(descriptor);
    return result;
}

uint32 ob_game_800A0B38(uint32 record)
{
    FUNCTION_MARKER(0x800A0B38u, "GAME.BIN");
    w_u32(record + 100u, 16u);
    w_u32(record + 96u, 0u);
    w_u32(record + 80u, 0u);
    w_u16(record + 88u, 0xFFFFu);
    w_u16(record + 68u, 0u);
    w_u32(record + 76u, 0u);
    w_u32(record + 16u, 0u);
    w_u16(record + 26u, 0xFFFFu);
    w_u32(record + 44u, 0u);
    w_u16(record + 54u, 0xFFFFu);
    return 0xFFFFu;
}

