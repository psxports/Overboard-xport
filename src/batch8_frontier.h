#ifndef OB_BATCH8_FRONTIER_H
#define OB_BATCH8_FRONTIER_H
#include "xport.h"
uint32 ob_file_finish_request(void);
uint32 ob_update_controller_flags(void);
uint32 ob_file_seek(uint32 index, uint32 offset, uint32 origin);
uint32 ob_memory_unlock_handle(uint32 handle, uint32 flags);
#endif
