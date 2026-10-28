#include "native_card.h"
#include "native_runtime.h"
#include "native_timers.h"
#include "psx.h"

uint32 _patch_card(void);
uint32 _patch_card2(void);

void ob_native_card_init(void)
{
    /* Native card services own IRQ handling; no BIOS instructions are executed */
    psx_bios_bind_card_patches(0u, 0x80063D08u, 0x80063DE8u, 0x6444u, 0x4D98u);
}

sint32 ob_native_card_call(uint32 target, uint32 count, const uint32 *args, uint32 *result)
{
    (void)args;
    if (target != 0x80063D60u && target != 0x80063E18u) return 0;
    if (count) ob_native_missing(target, 0u, count);
    ob_native_timers_critical(0u);
    xport_bios_enter_critical();
    if (target == 0x80063D60u)
    {
        *result = _patch_card();
        w_u32(0x80077284u, *result);
    }
    else
        *result = _patch_card2();
    return 1;
}
