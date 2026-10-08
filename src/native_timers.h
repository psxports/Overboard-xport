#ifndef OB_NATIVE_TIMERS_H
#define OB_NATIVE_TIMERS_H
#include "xport.h"
void ob_native_timers_init(void);
void ob_native_timers_poll(void);
void ob_native_timers_critical(uint32 enabled);
uint32 ob_native_timers_set(uint32 counter, uint32 target, uint32 mode);
uint32 ob_native_timers_get(uint32 counter);
uint32 ob_native_timers_start(uint32 counter);
uint32 ob_native_timers_stop(uint32 counter);
#endif
