#include "native_timers.h"
#include "native_runtime.h"
#include "psx.h"

/* PAL GPU clock divided by the 3406 clocks in each scanline */
#define OB_PAL_GPU_HZ 53203425ull
#define OB_PAL_LINE_US_DENOM 3406000000ull
static uint64 timer_time;
static uint64 timer_fraction;
static uint32 timer_configured;
static uint32 timer_irq_enabled;
static uint32 timer_pending;
static uint32 timer_interrupts_enabled = 1u;
static uint32 timer_delivering;

void ob_native_timers_init(void)
{
    timer_time = xport_timer_get();
    timer_fraction = 0u;
    timer_configured = 0u;
    timer_irq_enabled = 0u;
    timer_pending = 0u;
    timer_interrupts_enabled = 1u;
    timer_delivering = 0u;
}

static void timer_advance(void)
{
    uint64 now = xport_timer_get();
    uint64 elapsed;
    uint64 scaled;
    uint64 ticks;
    uint64 value;
    uint32 period;
    PsxTimerState state;
    if (now < timer_time)
        ob_native_missing(0x80055984u, 0u, 1u);
    elapsed = now - timer_time;
    timer_time = now;
    if (!timer_configured) return;
    scaled = (elapsed % OB_PAL_LINE_US_DENOM) * OB_PAL_GPU_HZ + timer_fraction;
    ticks = (elapsed / OB_PAL_LINE_US_DENOM) * OB_PAL_GPU_HZ + scaled / OB_PAL_LINE_US_DENOM;
    timer_fraction = scaled % OB_PAL_LINE_US_DENOM;
    if (!ticks) return;
    psx_timers_export(&state);
    period = state.target[1] ? state.target[1] : 0x10000u;
    value = (uint64)state.counter[1] + ticks;
    if (value >= period)
    {
        state.mode[1] |= 0x800u;
        /* The hardware IRQ latch coalesces elapsed targets until delivery */
        if (state.mode[1] & 0x10u) timer_pending = 1u;
    }
    state.counter[1] = (uint32)(value % period);
    if (!psx_timers_import(&state))
        ob_native_missing(0x80055984u, 1u, 0u);
}

void ob_native_timers_poll(void)
{
    timer_advance();
    if (!timer_pending || !timer_irq_enabled || !timer_interrupts_enabled || timer_delivering) return;
    timer_pending = 0u;
    timer_delivering = 1u;
    DeliverEvent(0xF2000001u, 2u);
    timer_delivering = 0u;
}

void ob_native_timers_critical(uint32 enabled)
{
    timer_interrupts_enabled = enabled != 0u;
    if (enabled) ob_native_timers_poll();
}

uint32 ob_native_timers_set(uint32 counter, uint32 target, uint32 mode)
{
    uint32 index = (uint16)counter;
    uint32 result;
    timer_advance();
    if (index >= 3u) return 0u;
    /* TODO Support CPU-clock counters and synchronized gate modes when reached */
    if (index != 1u || (mode & 0x11u) || (mode & ~0x1011u))
        ob_native_missing(0x80055984u, 0x1000u, mode);
    result = (uint32)SetRCnt(index, (uint16)target, mode);
    timer_configured = result;
    timer_time = xport_timer_get();
    timer_fraction = 0u;
    timer_pending = 0u;
    return result;
}

uint32 ob_native_timers_get(uint32 counter)
{
    PsxTimerState state;
    uint32 index = (uint16)counter;
    timer_advance();
    if (index >= 3u) return 0u;
    if (index != 1u) ob_native_missing(0x80055A24u, 1u, index);
    psx_timers_export(&state);
    return state.counter[index];
}

uint32 ob_native_timers_start(uint32 counter)
{
    uint32 index = (uint16)counter;
    timer_advance();
    if (index >= 3u) return 0u;
    if (index != 1u) ob_native_missing(0x80055A5Cu, 1u, index);
    timer_irq_enabled = 1u;
    return 1u;
}

uint32 ob_native_timers_stop(uint32 counter)
{
    uint32 index = (uint16)counter;
    timer_advance();
    if (index >= 3u) return 1u;
    if (index != 1u) ob_native_missing(0x80055A90u, 1u, index);
    /* StopRCnt masks interrupts while the hardware counter keeps counting */
    timer_irq_enabled = 0u;
    return 1u;
}
