#ifndef OB_BATCH9_FRONTIER_H
#define OB_BATCH9_FRONTIER_H
#include "xport.h"
uint32 ob_memory_payload_size(uint32 handle);
uint32 ob_memory_release_reference(uint32 handle);
uint32 ob_reset_overlay_state(void);
uint32 ob_memory_query_statistics(uint32 output);
uint32 ob_stream_stub_result(void);
uint32 ob_snapshot_controller_flags(void);
#endif
