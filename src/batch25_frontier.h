#ifndef OB_BATCH25_FRONTIER_H
#define OB_BATCH25_FRONTIER_H
#include "xport.h"
uint32 ob_locate_spatial_cell(uint32 x, uint32 z, uint32 output);
uint32 ob_copy_spatial_heights(uint32 output, uint32 state, uint32 stride);
uint32 ob_step_spatial_cell(uint32 state, uint32 axis, uint32 increment);
#endif
