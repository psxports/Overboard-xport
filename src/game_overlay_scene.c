#include "psx.h"
#include "xport.h"

void ob_game_800A5520(void)
{
    FUNCTION_MARKER(0x800A5520u, "GAME.BIN");
}

uint32 ob_game_800C15E4(void)
{
    FUNCTION_MARKER(0x800C15E4u, "GAME.BIN");
    uint32 descriptor = r_u32(0x80077190u);
    const uint32 shifts[8] = {5u,4u,5u,7u,5u,4u,5u,7u};
    for (uint32 i=0u; i<8u; ++i)
        w_u32(0x800C61F4u+i*4u,r_u8(descriptor+44u) << shifts[i]);
    uint32 category = r_u8(descriptor+43u);
    uint32 selector;
    if ((category-6u) >= 13u)
        selector = 7u;
    else if (category == 6u)
        selector = 1u;
    else if (category < 18u)
        selector = 3u;
    else
        selector = 5u;
    uint32 source = selector == 3u ? 0x800C9938u : selector == 7u ? 0x800C9A78u : 0x800C9910u;
    for (uint32 i=0u; i<9u; ++i)
    {
        uint32 value = r_u32(source+i*4u);
        w_u16(0x800D6494u,(selector == 1u || selector == 5u) ? 16u : 128u);
        w_u32(0x800C6238u+i*4u,value);
    }
    uint32 result = r_u32(0x800C61F4u+selector*4u);
    w_u16(0x800D6494u,result);
    for (uint32 i=0u; i<9u; ++i)
        w_u32(0x800C6234u-i*4u,0u);
    w_u32(0x800C848Cu,selector);
    return result;
}

void ob_game_800C190C(void)
{
    FUNCTION_MARKER(0x800C190Cu, "GAME.BIN");
}
