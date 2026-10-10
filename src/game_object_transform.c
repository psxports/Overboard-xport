#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

void ob_game_800C08BC(uint32 object, uint32 matrix_buffer, uint32 descriptor, uint32 context)
{
    FUNCTION_MARKER(0x800C08BCu, "GAME.BIN");
    uint32 resource = r_u32(object + 292u);
    if (resource == 237u)
    {
        uint32 matrix = ob_draft_unresolved_call(0x800AD6E0u, 2u, matrix_buffer, 0u);
        ob_draft_unresolved_call(0x80045848u, 2u, r_u32(object + 44u), matrix);
        ob_draft_unresolved_call(0x800458B4u, 3u,
            r_u32(object + 44u), descriptor, context);
        ob_draft_unresolved_call(0x800AD6E0u, 2u,
            matrix_buffer, (uint32)(sint32)r_s16(descriptor + 16u));
        sint32 random = (sint32)ob_draft_unresolved_call(0x8001B008u, 0u);
        ob_draft_unresolved_call(0x800285A4u, 3u,
            matrix_buffer + 12u, (uint32)(random >> 7), r_u32(object + 44u) + 132u);
        ob_draft_unresolved_call(0x80045ADCu, 1u, r_u32(object + 44u));
        return;
    }
    if (resource == 240u)
    {
        uint32 matrix = ob_draft_unresolved_call(0x800AD6E0u, 2u, matrix_buffer, 0u);
        ob_draft_unresolved_call(0x80045848u, 2u, r_u32(object + 44u), matrix);
        w_u32(descriptor + 4u, 5000u);
        ob_draft_unresolved_call(0x800458B4u, 3u,
            r_u32(object + 44u), descriptor, context);
        ob_draft_unresolved_call(0x800AD6E0u, 2u,
            matrix_buffer, (uint32)(sint32)r_s16(descriptor + 16u));
        ob_draft_unresolved_call(0x800285A4u, 3u,
            matrix_buffer + 12u, 256u, r_u32(object + 44u) + 132u);
        ob_draft_unresolved_call(0x80045ADCu, 1u, r_u32(object + 44u));
        w_u32(object + 288u, 34u);
        uint32 scene = r_u32(object + 48u);
        uint32 properties = r_u32(object + 108u);
        w_u16(properties + 2u, r_u16(scene + 160u));
        sint32 scale = r_s16(properties + 2u);
        w_u16(properties, 1u);
        if (scale < 0)
            scale += 15;
        sub_800440B8(r_u32(object + 48u), (uint32)(scale >> 4));
        return;
    }

    uint32 matrix = ob_draft_unresolved_call(0x800AD6E0u, 2u,
        matrix_buffer, (uint32)(sint32)r_s16(descriptor + 16u));
    ob_draft_unresolved_call(0x80045848u, 2u, r_u32(object + 44u), matrix);
    ob_draft_unresolved_call(0x800458B4u, 3u,
        r_u32(object + 44u), descriptor, context);
    if (r_u32(object + 136u) != 0u)
    {
        uint32 properties = ob_draft_unresolved_call(0x800901FCu, 2u,
            r_u32(object + 292u), 1u);
        if ((r_u8(properties + 36u) & 0x40u) == 0u)
        {
            matrix = ob_draft_unresolved_call(0x800AD6E0u, 2u,
                matrix_buffer, (uint32)(sint32)r_s16(descriptor + 16u));
            ob_draft_unresolved_call(0x80045848u, 2u,
                r_u32(r_u32(object + 136u) + 44u), matrix);
            ob_draft_unresolved_call(0x800458B4u, 3u,
                r_u32(r_u32(object + 136u) + 44u), descriptor, context);
        }
    }
    if (r_u32(object + 140u) != 0u)
    {
        uint32 properties = ob_draft_unresolved_call(0x800901FCu, 2u,
            r_u32(object + 292u), 2u);
        if ((r_u8(properties + 36u) & 0x40u) == 0u)
        {
            matrix = ob_draft_unresolved_call(0x800AD6E0u, 2u,
                matrix_buffer, (uint32)(sint32)r_s16(descriptor + 16u));
            ob_draft_unresolved_call(0x80045848u, 2u,
                r_u32(r_u32(object + 140u) + 44u), matrix);
            ob_draft_unresolved_call(0x800458B4u, 3u,
                r_u32(r_u32(object + 140u) + 44u), descriptor, context);
        }
    }
    if (r_u32(object + 144u) != 0u)
    {
        uint32 properties = ob_draft_unresolved_call(0x800901FCu, 2u,
            r_u32(object + 292u), 3u);
        if ((r_u8(properties + 36u) & 0x40u) == 0u)
        {
            matrix = ob_draft_unresolved_call(0x800AD6E0u, 2u,
                matrix_buffer, (uint32)(sint32)r_s16(descriptor + 16u));
            ob_draft_unresolved_call(0x80045848u, 2u,
                r_u32(r_u32(object + 144u) + 44u), matrix);
            ob_draft_unresolved_call(0x800458B4u, 3u,
                r_u32(r_u32(object + 144u) + 44u), descriptor, context);
        }
    }
}

