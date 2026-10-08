#include "draft_signatures.h"
#include "native_runtime.h"

void sub_800440B8(uint32 object,uint32 value)
{
    FUNCTION_MARKER(0x800440B8u,"SLES_008.65");
    w_u16(object+160u,(uint16)value);
}
