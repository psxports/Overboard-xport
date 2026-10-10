#include "psx.h"
#include "native_extra_signatures.h"
#include "native_runtime.h"

uint32 ob_main_80054538(uint32 index)
{
    FUNCTION_MARKER(0x80054538u, "SLES_008.65");
    index &= 255u;
    uint32 saved = r_u8(0x80088318u + index);
    return 0u - (saved & 1u);
}
