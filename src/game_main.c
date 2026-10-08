#include "xport.h"
#include "psx.h"
#include "draft_signatures.h"
#include "native_runtime.h"
#include "native_callbacks.h"
#include "native_cd_toc.h"

sint32 cd_mount_cue(const char *cue_path);

const uint32 xport_gpu_graph_type_address = 0x80075BECu;

void xport_main(void)
{
    const PSX_EXE executable = {
        "../orig/SLES_008.65", 0x80010000u, 0x800771F8u, 0x8008D018u,
        0x80075EA0u, 0x800D6768u, 0x801FDFF8u - 0x800D6768u
    };
    if (!xport_psx_exe_load(&executable))
    {
        xport_message_error("Overboard!", "Cannot load ../orig/SLES_008.65");
        xport_set_exit_code(1);
        return;
    }
    if (!cd_mount_cue("../status/native-repair/data-track.cue"))
    {
        xport_message_error("Overboard!", "Cannot mount the original data track");
        xport_set_exit_code(1);
        return;
    }
    if (ob_native_cd_toc_init("../iso/Overboard! (Europe).cue") != 31)
    {
        xport_message_error("Overboard!", "Cannot load the original disc TOC");
        xport_set_exit_code(1);
        return;
    }
    ob_native_runtime_init();
    ob_native_callbacks_init();
    sub_80022CD4();
}
