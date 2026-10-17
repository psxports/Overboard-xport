#include "psx.h"
#include <stdint.h>
#include "native_extra_signatures.h"
#include "native_runtime.h"

uint32 ob_main_800285A4(uint32 vector, uint32 scale, uint32 output)
{
    FUNCTION_MARKER(0x800285A4u, "SLES_008.65");
    int64_t product;
    uint64_t bits;
    uint32 high, value;
    product = (int64_t)(sint32)scale * (int64_t)r_s16(vector);
    bits = (uint64_t)product;
    high = (uint32)(bits >> 32) << 18;
    value = ((uint32)bits >> 14) | high;
    w_u32(output, value);
    product = (int64_t)(sint32)scale * (int64_t)r_s16(vector + 2u);
    bits = (uint64_t)product;
    high = (uint32)(bits >> 32) << 18;
    value = ((uint32)bits >> 14) | high;
    w_u32(output + 4u, value);
    product = (int64_t)(sint32)scale * (int64_t)r_s16(vector + 4u);
    bits = (uint64_t)product;
    high = (uint32)(bits >> 32) << 18;
    value = ((uint32)bits >> 14) | high;
    w_u32(output + 8u, value);
    return high;
}
