#include "native_callbacks.h"
#include "native_runtime.h"
#include "draft_signatures.h"
#include "psx.h"

sint32 ob_native_callback_dispatch(void *context, uint32 address)
{
    (void)context;
    if (address == 0x8002CFF4u)
    {
        sub_8002CFF4();
        return 1;
    }
    ob_native_dispatch(address, 0u, NULL);
    return 1;
}

void ob_native_callbacks_init(void)
{
    psx_bios_bind_guest_callback_service(ob_native_callback_dispatch, NULL);
}
