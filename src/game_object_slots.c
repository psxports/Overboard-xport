#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_800A0930(uint32 descriptor, uint32 owner)
{
    FUNCTION_MARKER(0x800A0930u, "GAME.BIN");
    uint32 slot = ob_draft_unresolved_call(0x800A0CB0u, 0u);
    w_u16(0x800C9AB4u, slot);
    if (slot == 0xFFFFFFFFu)
        return slot;

    uint32 record = 0x800CBA00u + 104u * slot;
    w_u32(record + 96u, r_u32(descriptor + 12u));
    uint32 scales[3];
    scales[0] = r_u32(0x8008DDCCu);
    scales[1] = r_u32(0x8008DDD0u);
    scales[2] = r_u32(0x8008DDD4u);
    uint32 selector = (r_u8(descriptor + 24u) >> 4) & 3u;
    uint32 size = ob_draft_unresolved_call(0x800901A8u, 1u,
        r_u32(descriptor + 12u)) & 0xFFFFu;
    /* TODO: Selector 3 reads an uninitialized fourth scale word in the original */
    uint32 scale = selector < 3u ? scales[selector]
        : ob_native_missing_value(0x800A0930u, "Uninitialized fourth descriptor scale");
    uint32 product = scale * size;
    if ((sint32)product < 0)
        product += 63u;
    w_u16(record + 70u, (uint32)((sint32)product >> 6));

    ob_draft_unresolved_call(0x800C0FA8u, 2u, record + 4u, descriptor);
    ob_draft_unresolved_call(0x800C0FA8u, 2u, record + 32u, descriptor);
    w_u32(record + 80u, 0u);
    w_u32(record + 84u, 0u);
    w_u32(record + 60u, r_u32(descriptor));
    uint32 coordinate = r_u32(descriptor + 8u);
    w_u8(record + 93u, 0u);
    w_u32(record + 64u, coordinate);
    if ((ob_draft_unresolved_call(0x800A0D10u, 1u, descriptor) & 1u) != 0u)
        w_u8(record + 92u, 1u);
    else
    {
        w_u8(record + 92u, 2u);
        ob_draft_unresolved_call(0x800AEF70u, 1u, record);
    }

    uint32 serial = r_u16(0x800C5330u);
    w_u16(record + 88u, 0xFFFFu);
    w_u32(record, owner);
    w_u16(0x800C5330u, serial + 1u);
    w_u16(record + 68u, serial);
    if (((serial + 1u) & 0xFFFFu) == 0u)
        w_u16(0x800C5330u, serial + 2u);
    return slot;
}
