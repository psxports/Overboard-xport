#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"
#include "decomp_208_signatures.h"

uint32 ob_game_800A4AC8(uint32 selector)
{
    FUNCTION_MARKER(0x800A4AC8u, "GAME.BIN");
    return ob_game_800a4ad0(selector, r_u32(0x80077190u));
}

uint32 ob_game_800a4ad0(uint32 selector, uint32 descriptor)
{
    FUNCTION_MARKER(0x800A4AD0, "GAME.BIN");
    uint32 index = 0u;
    uint32 offset = 0u;
    if (r_u16(descriptor) != 0u)
    {
        do
        {
            uint32 record = r_u32(0x80077194u) + offset;
            uint32 type = r_u32(record + 12u);
            uint32 create = 0u;
            if (type == 242u)
            {
                uint32 shift = (r_u8(r_u32(0x80077190u) + 42u) + 1u) & 31u;
                sint32 required = (sint16)((1u << shift) - 2u);
                create = r_u16(0x80089B24u) == (uint32)required;
            }
            else
            {
                uint32 difficulty = r_u8(0x8006C22Cu);
                uint32 flags = r_u8(record + 24u);
                if (!((difficulty == 0u && (flags & 1u) == 0u)
                    || (difficulty == 1u && (flags & 2u) == 0u)
                    || (difficulty == 2u && (flags & 4u) == 0u)
                    || r_u8(record + 25u) != selector || type == 250u))
                {
                    if (type == 5u)
                        w_u32(record + 12u, 3u);
                    type = r_u32(r_u32(0x80077194u) + offset + 12u);
                    create = (type - 169u) >= 2u;
                }
            }
            if (create)
            {
                record = r_u32(0x80077194u) + offset;
                sint32 slot = (sint16)ob_game_800A50BC(record);
                record = r_u32(0x80077194u) + offset;
                uint32 table = r_u32(0x8007719Cu);
                uint32 head = r_u32(table + (uint32)r_u16(record + 22u) * 4u);
                uint32 node = 0x800CBA00u + (uint32)slot * 104u;
                if (head == 0u)
                {
                    w_u32(node + 72u, node);
                    w_u32(table + (uint32)r_u16(record + 22u) * 4u, node);
                }
                else
                {
                    uint32 tail = head;
                    while (r_u32(tail + 72u) != head)
                        tail = r_u32(tail + 72u);
                    w_u32(tail + 72u, node);
                    record = r_u32(0x80077194u) + offset;
                    head = r_u32(r_u32(0x8007719Cu) + (uint32)r_u16(record + 22u) * 4u);
                    w_u32(node + 72u, head);
                }
                w_u16(node + 88u, index);
            }
            ++index;
            offset += 28u;
        } while (index < r_u16(r_u32(0x80077190u)));
    }
    uint32 result = r_u8(r_u32(0x80077190u) + 2u);
    index = 0u;
    if (result != 0u)
    {
        uint32 table = r_u32(0x8007719Cu);
        uint32 record = r_u32(0x80077198u);
        do
        {
            if (r_u8(record + 2u) < 7u && r_u8(record + 3u) != 0u)
            {
                uint32 node = r_u32(table + (uint32)r_u8(record + 12u) * 4u);
                if (node != 0u)
                {
                    do
                    {
                        uint32 type = r_u32(node + 44u);
                        if (type == 149u || type == 153u)
                            w_u16(node + 50u, 1u);
                        uint32 table_index = r_u8(record + 12u);
                        node = r_u32(node + 72u);
                        uint32 next = r_u32(node + 72u);
                        uint32 head = r_u32(table + table_index * 4u);
                        if (next == head)
                            break;
                    } while (1);
                }
            }
            ++index;
            result = index < r_u8(r_u32(0x80077190u) + 2u);
            record += 16u;
        } while (result != 0u);
    }
    return result;
}

uint32 ob_game_800A50BC(uint32 record)
{
    FUNCTION_MARKER(0x800A50BCu, "GAME.BIN");
    /* TODO Bind the reached GAME slot allocator */
    uint32 allocated = ob_draft_unresolved_call(0x800A0930u, 2u, record, r_u32(0x80077334u));
    sint32 slot = (sint16)allocated;
    uint32 offset = (uint32)slot * 104u;
    if (r_u8(0x800CBA5Cu + offset) == 2u)
    {
        uint32 context = r_u32(0x80083E34u);
        uint32 parameter = r_u32(0x80077334u);
        w_u32(0x800C8350u, (uint32)slot);
        /* TODO Bind the reached GAME dependent object constructor */
        uint32 object = ob_draft_unresolved_call(0x800BC3D8u, 3u, context, record, parameter);
        if (object != 0u)
        {
            w_u16(object + 326u, allocated);
            w_u32(0x800CBA50u + offset, object);
            w_u32(0x800CBA64u + offset, r_u8(object + 288u));
        }
    }
    return (uint32)slot;
}
