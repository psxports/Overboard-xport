#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800BC718(uint32 object, uint32 owner, uint32 record, uint32 context)
{
    FUNCTION_MARKER(0x800BC718u, "GAME.BIN");
    uint32 attributes = ob_draft_scratch_acquire(88u);
    uint32 secondary_attributes = ob_draft_scratch_acquire(56u);
    uint32 effect_data = ob_draft_scratch_acquire(8u);
    uint32 matrix_buffer = ob_draft_scratch_acquire(18u);
    uint32 direction = ob_draft_scratch_acquire(12u);
    /* TODO Bind remaining original GAME setup helpers as their bodies become available */
    ob_draft_unresolved_call(0x800BCFBCu, 4u, object, owner, record, context);
    ob_draft_unresolved_call(0x800BD7E4u, 2u, object, context);
    ob_draft_unresolved_call(0x800BD8ACu, 1u, object);
    (void)r_u32(0x800D6750u);
    ob_draft_unresolved_call(0x800900E0u, 1u, object);
    ob_draft_unresolved_call(0x800BD8E8u, 3u, object, record, context);
    ob_draft_unresolved_call(0x800BDCE0u, 2u, object, record);
    ob_draft_unresolved_call(0x800BDE48u, 3u, object, record, context);
    uint32 object_type = r_u32(record + 12u);
    if (object_type != 234u && object_type != 254u
        && object_type != 164u && object_type != 167u
        && object_type - 248u >= 2u && object_type != 160u)
    {
        ob_resolve_shape_links(r_u32(object + 48u));
    }
    ob_draft_unresolved_call(0x800C08BCu, 4u, object, matrix_buffer, record, context);
    object_type = r_u32(object + 292u);
    if (object_type != 237u && object_type != 240u)
    {
        ob_draft_unresolved_call(0x800BFF00u, 4u, object, owner, record, context);
        if (r_u32(object + 124u) == 0u || r_u32(object + 292u) == 255u)
        {
            ob_draft_unresolved_call(0x800C0DD4u, 1u, object);
        }
        else
        {
            ob_draft_unresolved_call(0x800285A4u, 3u, direction, 0u, r_u32(object + 44u) + 132u);
            ob_draft_unresolved_call(0x80045ADCu, 1u, r_u32(object + 44u));
        }
    }
    ob_draft_unresolved_call(0x800BE604u, 3u, object, attributes, context);
    ob_draft_unresolved_call(0x800BF4FCu, 4u, object, effect_data, secondary_attributes, context);
    ob_draft_unresolved_call(0x80099514u, 1u, object);
    /* Original 800A499C is jr ra followed by nop */
    ob_draft_unresolved_call(0x800BFC18u, 2u, object, context);
    ob_draft_scratch_release(direction);
    ob_draft_scratch_release(matrix_buffer);
    ob_draft_scratch_release(effect_data);
    ob_draft_scratch_release(secondary_attributes);
    ob_draft_scratch_release(attributes);
    return object;
}
