#ifndef OB_NATIVE_RUNTIME_H
#define OB_NATIVE_RUNTIME_H
#include "xport.h"
__declspec(noreturn) void ob_native_missing(uint32 target, uint32 expected, uint32 supplied);
void ob_native_runtime_init(void);
void ob_native_pump(void);
uint32 ob_draft_scratch_acquire(uint32 size);
void ob_draft_scratch_release(uint32 address);
uint32 ob_native_dispatch(uint32 target, uint32 count, const uint32 *args);
uint32 ob_native_front_dispatch(uint32 target, uint32 count, const uint32 *args);
void ob_native_overlay_loaded(uint32 index);
#endif
