#include "psx.h"
#include "native_extra_signatures.h"
#include "native_runtime.h"

uint32 ob_main_8004E694(uint32 object, uint32 flags)
{
    FUNCTION_MARKER(0x8004E694u, "SLES_008.65");
    uint32 result;
    if (flags & 2u)
        w_u16(object + 38u, (uint16)(r_u16(object + 38u) | 2u));
    if (flags & 8u)
        w_u16(object + 38u, (uint16)(r_u16(object + 38u) | 8u));
    if (flags & 4u)
        w_u16(object + 38u, (uint16)(r_u16(object + 38u) | 4u));
    result = flags & 0x400u;
    if (result != 0u)
    {
        result = r_u16(object + 38u) | 0x400u;
        w_u16(object + 38u, (uint16)result);
    }
    return result;
}

uint32 ob_main_8004E66C(uint32 object)
{
    FUNCTION_MARKER(0x8004E66Cu, "SLES_008.65");
    uint32 result = r_u8(object + 52u) + 1u;
    w_u8(object + 52u, (uint8)result);
    return result;
}
