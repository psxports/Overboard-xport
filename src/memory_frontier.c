#include "memory_frontier.h"

uint32 ob_memory_init_groups(void)
{
    FUNCTION_MARKER(0x80026460u, "SLES_008.65");
    for (uint32 index = 0; index < 8u; ++index)
    {
        uint32 record = 0x80078E48u + index * 16u;
        w_u8(record, 1u << index);
        w_u32(record + 4u, 0u);
        w_u32(record + 8u, index);
        w_u32(record + 12u, 0u);
    }
    w_u8(0x80077250u, 0u);
    return 0u;
}

uint32 ob_memory_unlink_free(uint32 block)
{
    FUNCTION_MARKER(0x8002785Cu, "SLES_008.65");
    uint32 previous = r_u32(block + 8u);
    uint32 next = r_u32(block + 12u);
    w_u32(previous + 12u, next);
    w_u32(next + 8u, previous);
    uint32 flags = r_u8(block + 32u);
    w_u32(block + 12u, 0u);
    w_u32(block + 8u, 0u);
    w_u8(block + 32u, flags & 0x7Fu);
    uint32 available = r_u32(0x80077248u);
    uint32 size = r_u32(block + 16u);
    uint32 count = r_u32(0x8007723Cu) - 1u;
    w_u32(0x80077248u, available - 40u - size);
    w_u32(0x8007723Cu, count);
    return count;
}

uint32 ob_memory_insert_physical(uint32 block, uint32 previous, uint32 size)
{
    FUNCTION_MARKER(0x8002691Cu, "SLES_008.65");
    uint32 next = r_u32(previous + 4u);
    w_u32(block + 16u, size);
    w_u32(block, previous);
    w_u32(block + 4u, next);
    w_u32(previous + 4u, block);
    w_u32(next, block);
    w_u8(block + 32u, 0u);
    uint32 count = r_u32(0x80077238u) + 1u;
    w_u32(0x80077238u, count);
    return count;
}

uint32 ob_memory_insert_free(uint32 block)
{
    FUNCTION_MARKER(0x800278ACu, "SLES_008.65");
    uint32 previous = r_u32(0x80077220u);
    uint32 next = r_u32(previous + 12u);
    uint32 size = r_u32(block + 16u);
    while (r_u32(next + 16u) < size)
    {
        previous = next;
        next = r_u32(next + 12u);
    }
    w_u32(block + 8u, previous);
    w_u32(block + 12u, next);
    w_u32(previous + 12u, block);
    w_u32(next + 8u, block);
    w_u8(block + 32u, 0x80u);
    uint32 available = r_u32(0x80077248u);
    size = r_u32(block + 16u);
    uint32 count = r_u32(0x8007723Cu) + 1u;
    available += 40u + size;
    w_u32(0x80077248u, available);
    w_u32(0x8007723Cu, count);
    return available;
}

uint32 ob_memory_link_used(uint32 block)
{
    FUNCTION_MARKER(0x800279A4u, "SLES_008.65");
    uint32 head = r_u32(0x80077228u);
    uint32 count = r_u32(0x80077240u);
    uint32 next = r_u32(head + 12u);
    ++count;
    w_u32(block + 8u, head);
    w_u32(0x80077240u, count);
    w_u32(block + 12u, next);
    w_u32(head + 12u, block);
    w_u32(next + 8u, block);
    return count;
}

uint32 ob_memory_bind_handle(uint32 block, uint32 handle, uint32 flags)
{
    FUNCTION_MARKER(0x80026984u, "SLES_008.65");
    w_u32(block + 24u, handle);
    uint32 prior = r_u32(handle);
    w_u32(block + 28u, prior);
    w_u32(handle, block + 40u);
    w_u8(block + 32u, flags & 0x7Fu);
    uint32 group = r_u8(0x8007724Cu);
    w_u16(block + 38u, 0u);
    w_u16(block + 36u, 0u);
    w_u16(block + 34u, 0u);
    w_u8(block + 33u, group);
    return ob_memory_link_used(block);
}

uint32 ob_memory_lock_block(uint32 block, uint32 flags)
{
    FUNCTION_MARKER(0x800277D0u, "SLES_008.65");
    if (flags & 1u)
        w_u16(block + 34u, (uint32)r_u16(block + 34u) + 1u);
    uint32 result = flags & 2u;
    if (result)
    {
        result = (uint32)r_u16(block + 36u) + 1u;
        w_u16(block + 36u, result);
    }
    return result;
}

uint32 ob_memory_lock_handle(uint32 handle, uint32 flags)
{
    FUNCTION_MARKER(0x8002679Cu, "SLES_008.65");
    uint32 block = r_u32(handle) - 40u;
    return ob_memory_lock_block(block, flags & 0xFFu);
}

uint32 ob_memory_slot_address(uint32 identifier)
{
    FUNCTION_MARKER(0x80027DF8u, "SLES_008.65");
    uint32 tables = r_u32(0x800775F4u);
    uint32 table = r_u32(tables + ((identifier >> 6u) & 0x3FCu));
    uint32 index = identifier & 0xFFu;
    if (table == 0u)
        return 0u;
    uint32 mask = 0x80u >> (index & 7u);
    if ((r_u8(table + 6u + (index >> 3u)) & mask) == 0u)
        return 0u;
    return r_u32(table) + index * 4u;
}

uint32 ob_memory_valid_slot_address(uint32 identifier)
{
    FUNCTION_MARKER(0x80027AE4u, "SLES_008.65");
    if ((identifier & 0xFFFFu) == 0u)
        return 0u;
    uint32 slot = ob_memory_slot_address(identifier & 0xFFFFu);
    if (r_u32(slot) == 0u)
        return 0u;
    return slot;
}

uint32 ob_memory_set_slot_callback(uint32 identifier, uint32 callback)
{
    FUNCTION_MARKER(0x80027A74u, "SLES_008.65");
    uint32 slot = ob_memory_valid_slot_address(identifier & 0xFFFFu);
    uint32 object = r_u32(slot);
    w_u32(object + 8u, callback);
    return object;
}
