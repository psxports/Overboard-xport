#ifndef OB_NATIVE_SERVICES_H
#define OB_NATIVE_SERVICES_H
#include "xport.h"
uint32 ob_native_sprintf(uint32 count, const uint32 *args);
sint32 ob_native_services_call(uint32 target, uint32 count, const uint32 *args, uint32 *result);
#endif
