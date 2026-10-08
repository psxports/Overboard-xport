#ifndef OB_NATIVE_CARD_H
#define OB_NATIVE_CARD_H
#include "xport.h"
void ob_native_card_init(const char *bios_path);
sint32 ob_native_card_call(uint32 target, uint32 count, const uint32 *args, uint32 *result);
#endif
