#ifndef OB_BATCH16_FRONTIER_H
#define OB_BATCH16_FRONTIER_H
#include "xport.h"
uint32 ob_link_object(uint32 parent, uint32 child);
uint32 ob_init_object_list(uint32 list);
void ob_resolve_shape_links(uint32 root);
uint32 ob_find_typed_object(uint32 parent, uint32 type, uint32 identifier);
uint32 ob_find_object_identifier(uint32 object, uint32 identifier);
uint32 ob_next_shape(uint32 root, uint32 object);
uint32 ob_find_sound_slot(void);
uint32 ob_find_voice_slot(void);
#endif
