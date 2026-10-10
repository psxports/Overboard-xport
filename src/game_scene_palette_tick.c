#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800C136C(void)
{
    FUNCTION_MARKER(0x800C136Cu, "GAME.BIN");
    sub_80030700(0u, 0u, 0u);
    uint32 previous = r_u32(0x8007F9B0u);
    sint32 elapsed = (sint32)(r_u32(0x80077334u) - previous);
    while (elapsed >= 501)
    {
        w_u32(0x8007F9B0u, previous + 500u);
        uint32 countdown = r_u16(0x800D6494u) - 1u;
        w_u16(0x800D6494u, countdown);
        if ((sint16)countdown <= 0)
        {
            uint32 phase = r_u32(0x800C848Cu) + 1u;
            w_u32(0x800C848Cu, phase);
            if (phase >= 8u)
                w_u32(0x800C848Cu, 0u);
            /* TODO Bind the original conditional palette phase helper when reached */
            ob_game_800C17F0( r_u32(0x800C848Cu));
        }
        previous = r_u32(0x8007F9B0u);
        uint32 first = r_u32(0x800C6238u);
        uint32 first_delta = r_u32(0x800C6214u);
        uint32 second = r_u32(0x800C623Cu);
        uint32 second_delta = r_u32(0x800C6218u);
        w_u32(0x800C6238u, first + first_delta);
        first = r_u32(0x800C6240u);
        w_u32(0x800C623Cu, second + second_delta);
        first_delta = r_u32(0x800C621Cu);
        second = r_u32(0x800C6244u);
        second_delta = r_u32(0x800C6220u);
        w_u32(0x800C6240u, first + first_delta);
        first = r_u32(0x800C6248u);
        w_u32(0x800C6244u, second + second_delta);
        first_delta = r_u32(0x800C6224u);
        second = r_u32(0x800C624Cu);
        second_delta = r_u32(0x800C6228u);
        w_u32(0x800C6248u, first + first_delta);
        first = r_u32(0x800C6250u);
        w_u32(0x800C624Cu, second + second_delta);
        second = r_u32(0x800C6254u);
        second_delta = r_u32(0x800C6230u);
        first_delta = r_u32(0x800C622Cu);
        w_u32(0x800C6254u, second + second_delta);
        second = r_u32(0x800C6258u);
        w_u32(0x800C6250u, first + first_delta);
        second_delta = r_u32(0x800C6234u);
        uint32 now = r_u32(0x80077334u);
        elapsed = (sint32)(now - previous);
        w_u32(0x800C6258u, second + second_delta);
    }
    sub_8003077C(0x800C61DCu, 255u, 4u,
        r_u8(0x800C623Au), r_u8(0x800C623Eu), r_u8(0x800C6242u));
    sub_8003077C(0x800C61E4u, 255u, 4u,
        r_u8(0x800C6246u), r_u8(0x800C624Au), r_u8(0x800C624Eu));
    return sub_8003077C(0x800C61ECu, 255u, 4u,
        r_u8(0x800C6252u), r_u8(0x800C6256u), r_u8(0x800C625Au));
}
