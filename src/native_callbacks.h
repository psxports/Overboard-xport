#ifndef OB_NATIVE_CALLBACKS_H
#define OB_NATIVE_CALLBACKS_H
#include "xport.h"
void ob_native_callbacks_init(void);
sint32 ob_native_callback_dispatch(void *context, uint32 address);
#endif
