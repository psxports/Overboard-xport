#ifndef OB_MEMORY_FRONTIER_H
#define OB_MEMORY_FRONTIER_H

#include "xport.h"

uint32 ob_memory_init_groups(void);
uint32 ob_memory_unlink_free(uint32 block);
uint32 ob_memory_insert_physical(uint32 block, uint32 previous, uint32 size);
uint32 ob_memory_insert_free(uint32 block);
uint32 ob_memory_link_used(uint32 block);
uint32 ob_memory_bind_handle(uint32 block, uint32 handle, uint32 flags);
uint32 ob_memory_lock_block(uint32 block, uint32 flags);
uint32 ob_memory_lock_handle(uint32 handle, uint32 flags);
uint32 ob_memory_slot_address(uint32 identifier);
uint32 ob_memory_valid_slot_address(uint32 identifier);
uint32 ob_memory_set_slot_callback(uint32 identifier, uint32 callback);

#endif
