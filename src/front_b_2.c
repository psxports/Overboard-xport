#include "native_card.h"
#include "front_signatures.h"
#include "native_runtime.h"
#include "psx.h"
#include <stdint.h>

uint32 ob_front_80095094(void)
{
    FUNCTION_MARKER(0x80095094u, "FRONT.BIN");
    /* Load directly without the original memory-card manager */
    if (ob_native_load_game() != 1) return 0u;
    return r_u8(0x8006C231u) != 0u;
}


