#ifndef OB_BATCH10_FRONTIER_H
#define OB_BATCH10_FRONTIER_H
#include "xport.h"
uint32 ob_consume_button_edge(uint32 index);
uint32 ob_clear_button_edges(void);
uint32 ob_switch_frame_buffer(void);
uint32 ob_memory_coalesce_free(uint32 block);
#endif
