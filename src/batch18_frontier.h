#ifndef OB_BATCH18_FRONTIER_H
#define OB_BATCH18_FRONTIER_H

#include "xport.h"

uint32 ob_insert_depth_node(uint32 root);
uint32 ob_collect_geometry_indices(uint32 root, uint32 depth);
uint32 ob_collect_geometry_callbacks(uint32 root, uint32 depth);
uint32 ob_build_geometry_order(uint32 descriptor);

#endif
