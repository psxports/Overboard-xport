#include "psx.h"
#include "native_extra_signatures.h"
#include "native_runtime.h"

void ob_main_80044080(uint32 shape, uint32 geometry)
{
    FUNCTION_MARKER(0x80044080u, "SLES_008.65");
    w_u32(shape + 40u, geometry);
}
