#include "psx.h"
#include "xport.h"

uint32 ob_main_80045410(uint32 node, uint32 output)
{
    FUNCTION_MARKER(0x80045410u, "SLES_008.65");
    uint32 x = r_u32(node + 132u);
    uint32 y = r_u32(node + 136u);
    uint32 z = r_u32(node + 140u);
    w_u32(output, x);
    w_u32(output + 4u, y);
    w_u32(output + 8u, z);
    return x;
}
