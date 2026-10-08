#include "native_heap.h"
#include "native_runtime.h"
#include "draft_signatures.h"

static uint32 ob_heap_relocate_block(uint32 original, uint32 replacement)
{
    FUNCTION_MARKER(0x800275F8u, "SLES_008.65");
    uint32 slot = r_u32(original + 24u);
    uint8 flags;
    w_u32(replacement + 24u, slot);
    w_u32(slot, replacement + 40u);
    w_u32(replacement + 28u, r_u32(original + 28u));
    w_u32(replacement + 8u, r_u32(original + 8u));
    w_u32(replacement + 12u, r_u32(original + 12u));
    w_u32(r_u32(original + 8u) + 12u, replacement);
    w_u32(r_u32(original + 12u) + 8u, replacement);
    flags = r_u8(original + 32u);
    w_u32(original + 8u, 0u);
    w_u32(original + 12u, 0u);
    w_u8(replacement + 32u, flags);
    w_u16(replacement + 34u, r_u16(original + 34u));
    w_u16(replacement + 36u, r_u16(original + 36u));
    w_u16(replacement + 38u, r_u16(original + 38u));
    w_u8(replacement + 33u, r_u8(original + 33u));
    return ob_draft_unresolved_call(0x80064894u, 3u, replacement + 40u,
        original + 40u, r_u32(original + 16u) - r_u32(original + 20u));
}

static uint32 ob_heap_notify_relocation(uint32 block, uint32 old_payload)
{
    FUNCTION_MARKER(0x8002776Cu, "SLES_008.65");
    uint32 slot = sub_80027AE4(r_u16(block + 38u));
    uint32 callback;
    if (slot == 0u)
        return slot;
    callback = r_u32(r_u32(slot) + 12u);
    if (callback == 0u)
        return callback;
    return ob_draft_unresolved_call(callback, 2u, r_u32(block + 24u), old_payload);
}

uint32 ob_native_heap_call(uint32 target, uint32 count, const uint32 *args, uint32 *result)
{
    if (target != 0x800275F8u && target != 0x8002776Cu)
        return 0u;
    if (count != 2u)
        ob_native_missing(target, 2u, count);
    if (target == 0x800275F8u)
        *result = ob_heap_relocate_block(args[0], args[1]);
    else
        *result = ob_heap_notify_relocation(args[0], args[1]);
    return 1u;
}
