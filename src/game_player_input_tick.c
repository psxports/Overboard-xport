#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800A636C(uint32 output, uint32 player_index)
{
    FUNCTION_MARKER(0x800A636Cu, "GAME.BIN");
    uint32 mapping = r_u32(0x80065CB0u + player_index * 4u);
    uint32 device_offset = (uint32)(sint32)(sint16)r_u16(0x800C9994u + player_index * 56u) << 4;
    w_u32(0x80065CACu, mapping);
    uint32 button = (r_u32(mapping) + device_offset) & 255u;
    uint32 result = ob_draft_unresolved_call(0x80054538u, 1u, button);
    uint32 input_word = result != 0u ? 0x800u : 0u;
    static const uint32 offsets[13] = { 4u, 8u, 12u, 16u, 20u, 24u, 36u, 40u, 44u, 48u, 28u, 32u, 52u };
    static const uint32 masks[13] = { 4u, 8u, 1u, 2u, 0x10u, 0x20u, 0x40u, 0x100u, 0x80u, 0x200u, 0x400u, 0x1000u, 0x2000u };
    uint32 index;
    for (index = 0u; index < 13u; ++index)
    {
        mapping = r_u32(0x80065CACu);
        button = (r_u32(mapping + offsets[index]) + device_offset) & 255u;
        if (index == 8u || index == 9u)
            result = sub_80054440(button);
        else
            result = ob_draft_unresolved_call(0x80054538u, 1u, button);
        if (result != 0u) input_word |= masks[index];
    }
    w_u32(output, input_word);
    return result;
}
