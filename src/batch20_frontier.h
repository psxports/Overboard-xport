#ifndef OB_BATCH20_FRONTIER_H
#define OB_BATCH20_FRONTIER_H
#include "xport.h"
uint32 ob_free_object_record(uint32 object);
uint32 ob_swap_pool_heads(uint32 first, uint32 second);
uint32 ob_unbind_pool_head(uint32 cell);
uint32 ob_set_callback_for_payload(uint32 payload, uint32 callback);
uint32 ob_init_effect_callbacks(void);
void ob_effect_stub_result(void);
void ob_scene_stub_result(void);
#endif
