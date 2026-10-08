#ifndef OB_BATCH12_FRONTIER_H
#define OB_BATCH12_FRONTIER_H
#include "xport.h"
/* Explicit incoming_result carries unchanged guest v0 */
uint32 ob_draw_text_begin(uint32 incoming_result);
uint32 ob_draw_text_end(uint32 incoming_result);
uint32 ob_handle_slot_address(uint32 identifier);
uint32 ob_fill_words(uint32 destination, uint32 bytes, uint32 value, uint32 incoming_result);
uint32 ob_build_weight_tree(uint32 tree);
#endif
