#ifndef OB_BATCH13_FRONTIER_H
#define OB_BATCH13_FRONTIER_H
#include "xport.h"
uint32 ob_decode_weight_tree(uint32 tree, uint32 root);
uint32 ob_unpack_weight_image(uint32 tree);
uint32 ob_reset_geometry_workspace(void);
/* Explicit incoming_result preserves guest v0 */
uint32 ob_set_update_callback(uint32 callback, uint32 incoming_result);
uint32 ob_card_channel(uint32 index);
#endif
