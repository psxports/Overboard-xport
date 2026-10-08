#ifndef OB_BATCH5_FRONTIER_H
#define OB_BATCH5_FRONTIER_H
#include "xport.h"
uint32 ob_memory_unlock_block(uint32 block, uint32 flags);
uint32 ob_align_value(uint32 value, uint32 alignment);
uint32 ob_memory_set_slot_tail(uint32 identifier, uint32 value);
uint32 ob_memory_set_word_for_payload(uint32 payload, uint32 value);
uint32 ob_memory_set_tail_for_payload(uint32 payload, uint32 value);
uint32 ob_init_geometry_callbacks(void);
uint32 ob_init_object_callbacks(void);
uint32 ob_reset_geometry_record(uint32 record);
uint32 ob_init_geometry_record(void);
#endif
