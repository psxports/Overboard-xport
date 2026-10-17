#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800BC3D8(uint32 owner, uint32 record, uint32 context)
{
    FUNCTION_MARKER(0x800BC3D8u, "GAME.BIN");
    uint32 storage = ob_draft_scratch_acquire(28u);
    uint32 temporary_record = storage;
    uint32 object_cell = storage + 24u;
    w_u32(object_cell, 0u);
    uint32 details = ob_game_800901FC(r_u32(record + 12u), 0u);
    uint32 object_type = r_u32(record + 12u);
    uint32 flags = r_u32(details + 24u);
    /* TODO Bind the original GAME construction helpers as their bodies become available */
    switch (object_type)
    {
    case 33u:
    case 36u:
    case 159u:
    {
        uint32 saved_index;
        uint32 mode;
        uint32 selector;
        if (object_type == 33u)
        {
            saved_index = r_u16(record + 22u);
            w_u32(0x800D6758u, 0x800C32CCu);
            w_u32(0x800C90CCu, 2000u);
            w_u32(0x800C8344u, 2000u);
            w_u32(0x800C8360u, 0x800A0278u);
            mode = 2u;
            selector = 0u;
        }
        else if (object_type == 36u)
        {
            saved_index = r_u16(record + 22u);
            w_u32(0x800D6758u, 0x800C331Cu);
            w_u32(0x800C90CCu, 2000u);
            w_u32(0x800C8344u, 625u);
            w_u32(0x800C8360u, 0x800AA390u);
            mode = 1u;
            selector = 0u;
        }
        else
        {
            w_u32(0x800D6758u, 0x800C35ECu);
            w_u32(0x800C8360u, 0x800A7440u);
            w_u32(0x800C90CCu, 2000u);
            w_u32(0x800C8344u, 1000u);
            uint32 selected = r_u32(0x800C5584u);
            saved_index = r_u16(record + 22u);
            selector = r_u8(selected + 93u);
            mode = 1u;
        }
        /* Keep the unused fifth positional slot ahead of the meaningful context */
        ob_draft_unresolved_call(0x800A2760u, 6u, owner, record, temporary_record, mode, selector, context);
        w_u16(record + 22u, saved_index);
        break;
    }
    case 48u: case 50u: case 52u: case 54u: case 56u:
    case 58u: case 60u: case 62u: case 64u: case 66u:
    case 70u: case 72u: case 74u: case 75u: case 77u:
        flags |= 3u;
        break;
    case 149u: case 153u: case 174u: case 238u:
    {
        uint32 saved_index = r_u16(record + 22u);
        uint32 distance = object_type == 149u ? 3350u : object_type == 153u ? 3400u : 0u;
        record = ob_game_80096244( owner, record, temporary_record, distance, context);
        w_u16(record + 22u, saved_index);
        break;
    }
    case 248u:
        ob_draft_unresolved_call(0x8001A4A0u, 2u, r_u32(record), r_u32(record + 8u));
        break;
    default:
        break;
    }
    if (r_s32(0x8007755Cu) > 0)
    {
        uint32 size = ob_draft_unresolved_call(0x800BCBB8u, 1u, flags);
        sub_800262CC(object_cell, (sint32)size);
        size = ob_draft_unresolved_call(0x800BCBB8u, 1u, flags);
        ob_draft_unresolved_call(0x800C1068u, 3u, r_u32(object_cell), size, 0u);
        uint32 object = r_u32(object_cell);
        if (object != 0u)
        {
            w_u16(object + 326u, r_u32(0x800C8350u));
            uint32 index = r_u16(record + 20u);
            w_u32(0x800C8350u, 0xFFFFFFFFu);
            w_u8(object + 339u, index);
            object = r_u32(object_cell);
            w_u32(object + 276u, flags);
            ob_draft_unresolved_call(0x800BCD2Cu, 2u, object, flags);
            uint32 mode;
            if ((flags & 4u) != 0u)
            {
                object = r_u32(object_cell);
                ob_draft_unresolved_call(0x80097524u, 3u, r_u32(object + 124u), record, context);
                mode = 1u;
            }
            else
                mode = 6u;
            if ((flags & 1u) != 0u)
            {
                ob_draft_unresolved_call(0x8009949Cu, 2u, r_u32(object_cell), mode);
                if ((flags & 0x40u) != 0u)
                {
                    object = r_u32(object_cell);
                    w_u16(r_u32(object + 116u) + 104u, 1u);
                }
            }
            object = r_u32(object_cell);
            w_u32(object + 292u, r_u32(record + 12u));
            ob_draft_unresolved_call(0x800BC718u, 4u, object, owner, record, context);
            w_u8(r_u32(object_cell) + 325u, 0u);
        }
        w_u32(r_u32(object_cell) + 28u, context);
    }
    uint32 result = r_u32(object_cell);
    w_u32(0x800C5584u, 0u);
    ob_draft_scratch_release(storage);
    return result;
}
