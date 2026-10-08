#ifndef OB_AUDIT_FRONTIER_H
#define OB_AUDIT_FRONTIER_H

#include "xport.h"

uint32 ob_file_reset_tables(void);
uint32 ob_memory_unlink_used(uint32 block);
uint32 ob_copy_string(uint32 destination, uint32 source);
uint32 ob_bcd_to_frame(uint32 source);
uint32 ob_bcd_fields_to_frame(uint32 minute, uint32 second, uint32 frame, uint32 destination);
uint32 ob_file_entry_size(uint32 index);
uint32 ob_file_close_slot(uint32 index);
uint32 ob_string_equal_code(uint32 left, uint32 right);
uint32 ob_memory_merge_next(uint32 block);
uint32 ob_memory_find_identifier(uint32 payload);
uint32 ob_memory_set_slot_word(uint32 identifier, uint32 value);
uint32 ob_set_render_mode(uint32 mode);
uint32 ob_get_render_mode(void);

#endif
