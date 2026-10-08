#ifndef OB_NATIVE_GRAPHICS_H
#define OB_NATIVE_GRAPHICS_H
#include "xport.h"
uint32 ob_native_reset_graph(uint32 mode);
sint32 ob_native_graphics_call(uint32 target, uint32 count, const uint32 *args, uint32 *result);
#endif
