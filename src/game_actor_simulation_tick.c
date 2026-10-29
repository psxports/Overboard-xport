#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"
#include "decomp_208_signatures.h"

uint32 ob_game_800AE0F8(uint32 time, uint32 flags)
{
    FUNCTION_MARKER(0x800AE0F8, "GAME.BIN");
    return ob_game_800ae100(time, flags, r_u32(0x800C82E8));
}

uint32 ob_game_800ae100(uint32 time, uint32 flags, uint32 delay)
{
    FUNCTION_MARKER(0x800AE100, "GAME.BIN");
    if ((sint32)delay > 0)
    {
        --delay;
        w_u32(0x800C82E8u, delay);
        return delay;
    }
    uint32 counter = r_u16(0x800C5588u) + 1u;
    w_u16(0x800C5588u, counter);
    sint32 signed_counter = (sint16)counter;
    uint32 result = flags & 1u;
    if (signed_counter % 15 != 0 && result == 0u)
        return result;
    result = r_u32(0x8006C138u);
    if (result == 0u)
        return result;
    uint32 threshold = r_u8(0x8006C230u) == 1u ? 53900u : 960000u;
    ob_set_object_time(r_u32(r_u32(0x8006C138u) + 44u), time);
    uint32 player_position = ob_draft_scratch_acquire(16u);
    uint32 actor_position = ob_draft_scratch_acquire(16u);
    sub_80045378(r_u32(r_u32(0x8006C138u) + 44u), time, player_position);
    result = r_u32(0x800C855Cu);
    if ((sint32)result >= 0)
    {
        uint32 slot = 0u;
        uint32 offset = 0u;
        uint32 descriptor = 0x800CBA00u;
        uint32 position = 0x800CBA20u;
        do
        {
            if (r_u32(0x800CBA60u + offset) != 0u &&
                (ob_game_800A0D10(position) & 1u) != 0u)
            {
                uint32 kind = r_u8(0x800CBA5Cu + offset) & 15u;
                if (kind == 1u)
                {
                    uint32 distance = ob_game_80099798(
                        player_position, position);
                    ob_game_800AEE18(
                        time, distance, descriptor, slot, threshold);
                }
                else if (kind == 2u && r_u8(0x8006C230u) == 1u)
                {
                    uint32 distance;
                    if ((flags & 2u) != 0u)
                        distance = threshold * 10u;
                    else
                    {
                        uint32 object = r_u32(0x800CBA50u + offset);
                        sub_80045378(r_u32(object + 44u), time, actor_position);
                        distance = ob_game_80099798(
                            player_position, actor_position);
                    }
                    ob_game_800AEEB8(
                        time, distance, descriptor, 55000u);
                }
            }
            descriptor += 104u;
            offset += 104u;
            uint32 maximum = r_u32(0x800C855Cu);
            ++slot;
            result = (sint32)maximum < (sint32)slot;
            position += 104u;
        }
        while (result == 0u);
    }
    ob_draft_scratch_release(actor_position);
    ob_draft_scratch_release(player_position);
    return result;
}
