#include "xport.h"
#include "psx.h"

sint32 overboard_poll_event(void)
{
    FUNCTION_MARKER(0x8001221Cu, "SLES_008.65");
    for (;;)
    {
        if (TestEvent(r_u32(0x80089688u)))
            return 0;
        if (TestEvent(r_u32(0x8008968Cu)))
            return 1;
        if (TestEvent(r_u32(0x80089690u)))
            return 2;
        if (TestEvent(r_u32(0x80089698u)))
            return 3;
    }
}

sint32 overboard_drain_events(void)
{
    FUNCTION_MARKER(0x80012294u, "SLES_008.65");
    TestEvent(r_u32(0x80089688u));
    TestEvent(r_u32(0x8008968Cu));
    TestEvent(r_u32(0x80089690u));
    return TestEvent(r_u32(0x80089698u));
}

sint32 overboard_poll_extended_event(void)
{
    FUNCTION_MARKER(0x800122ECu, "SLES_008.65");
    for (;;)
    {
        if (TestEvent(r_u32(0x80089718u)))
            return 0;
        if (TestEvent(r_u32(0x8008971Cu)))
            return 1;
        if (TestEvent(r_u32(0x80089720u)))
            return 2;
        if (TestEvent(r_u32(0x800897A8u)))
            return 3;
        if (TestEvent(r_u32(0x800897D0u)))
            return 4;
    }
}

sint32 overboard_drain_extended_events(void)
{
    FUNCTION_MARKER(0x8001237Cu, "SLES_008.65");
    TestEvent(r_u32(0x80089718u));
    TestEvent(r_u32(0x8008971Cu));
    TestEvent(r_u32(0x80089720u));
    TestEvent(r_u32(0x800897A8u));
    return TestEvent(r_u32(0x800897D0u));
}
