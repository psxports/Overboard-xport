#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

void ob_game_800BFC18(uint32 object, uint32 context)
{
    FUNCTION_MARKER(0x800BFC18u, "GAME.BIN");
    uint32 counter = r_u32(0x800D675Cu);
    uint32 resource = r_u32(object + 292u);
    w_u32(0x800D675Cu, counter + 20u);
    uint32 target = 0x800C0744u;
    sint32 divisor;
    switch (resource)
    {
    case 15u: case 16u: case 68u: case 76u:
    case 235u: case 239u: case 248u: case 249u:
        return;
    case 33u:
        counter = r_u32(0x800D675Cu);
        ob_draft_unresolved_call(0x800A19D8u, 3u, object, 0u,
            context + (uint32)((sint32)counter % 250) + 5u);
        return;
    case 49u: case 51u: case 53u: case 55u: case 57u:
    case 59u: case 61u: case 63u: case 65u: case 67u:
    case 69u: case 71u: case 73u:
        counter = r_u32(0x800D675Cu);
        ob_draft_unresolved_call(0x800A9160u, 3u, object, 0u,
            context + (uint32)((sint32)counter % 500) + 5u);
        return;
    case 149u: case 153u:
        ob_game_8009696C(object, r_u32(0x800D6750u), context,
            resource == 149u ? 3350u : 3400u);
        return;
    case 159u:
    {
        uint32 properties = r_u32(object + 108u);
        uint32 index = r_u8(properties + 44u);
        uint32 node = r_u32(0x800D5C98u + 4u * index);
        uint32 sound = ob_draft_unresolved_call(0x80011A24u, 6u,
            0x800663D8u, 112u, 128u, r_u32(node + 44u), context, 1u);
        w_u16(node + 306u, sound);
        ob_draft_unresolved_call(0x800C0744u, 3u, object, 0u, context + 100u);
        return;
    }
    case 229u: case 230u:
        if ((sint32)r_u32(r_u32(0x800D6750u) + 4u) <= 0)
            return;
        divisor = r_s16(object + 308u);
        break;
    case 20u: case 21u: case 22u: case 23u: case 24u: case 25u:
    case 26u: case 27u: case 28u: case 29u: case 30u: case 31u:
        ob_draft_unresolved_call(0x800C0B78u, 1u, object);
        divisor = r_s16(object + 308u);
        break;
    case 164u:
        divisor = r_s16(object + 308u);
        target = 0x800A7A60u;
        break;
    case 167u:
        divisor = r_s16(object + 308u);
        target = 0x800A7CC4u;
        break;
    default:
        divisor = r_s16(object + 308u);
        if (divisor == 0)
            return;
        break;
    }
    counter = r_u32(0x800D675Cu);
    if (divisor == 0)
        xport_mips_break(7u);
    if (divisor == -1 && counter == 0x80000000u)
        xport_mips_break(6u);
    uint32 scheduled = context + (uint32)((sint32)counter % divisor) + 5u;
    ob_draft_unresolved_call(target, 3u, object, 0u, scheduled);
}
