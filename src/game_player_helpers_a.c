#include "psx.h"
#include "game_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800BB3CC(void)
{
    FUNCTION_MARKER(0x800BB3CCu, "GAME.BIN");
    uint32 records_header = r_u32(0x80077190u);
    if (r_u8(records_header + 2u) != 0u)
    {
        uint32 index = 0u;
        uint32 offset = 0u;
        do
        {
            uint32 record = r_u32(0x80077198u) + offset;
            if (r_u8(record) == 1u)
                w_u8(record + 3u, r_u8(record + 4u) != 0u ? 0u : 1u);
            record = r_u32(0x80077198u) + offset;
            w_u32(record + 8u, r_u8(record) == 4u ? 1u : 0u);
            records_header = r_u32(0x80077190u);
            uint32 count = r_u8(records_header + 2u);
            ++index;
            offset += 16u;
            if ((sint32)index >= (sint32)count)
                break;
        } while (1);
    }
    w_u32(0x800C84D8u, 20u);
    return 20u;
}

uint32 ob_game_800A55E4(void)
{
    FUNCTION_MARKER(0x800A55E4u, "GAME.BIN");
    uint32 records_header = r_u32(0x80077190u);
    uint32 count = r_u16(records_header);
    w_u16(0x800D649Cu, 0u);
    uint32 result = count;
    if (count != 0u)
    {
        uint32 index = 0u;
        uint32 selector = r_u8(0x8006C22Cu);
        uint32 record = r_u32(0x80077194u);
        do
        {
            if ((selector != 0u || (r_u8(record + 24u) & 1u) != 0u)
                && (selector != 1u || (r_u8(record + 24u) & 2u) != 0u)
                && (selector != 2u || (r_u8(record + 24u) & 4u) != 0u)
                && r_u32(record + 12u) - 229u < 2u
                && r_u16(record + 18u) == 18u)
            {
                w_u16(0x800D649Cu, (uint32)r_u16(0x800D649Cu) + 1u);
            }
            ++index;
            result = (sint32)index < (sint32)count;
            record += 28u;
        } while (result != 0u);
    }
    return result;
}
