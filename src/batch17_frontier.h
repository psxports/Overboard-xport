#ifndef OB_BATCH17_FRONTIER_H
#define OB_BATCH17_FRONTIER_H
#include "xport.h"
uint32 ob_angle_matrix14(uint32 angle, uint32 matrix);
uint32 ob_random15(void);
uint32 ob_advance_object(uint32 object, uint32 time, uint32 incoming_result);
uint32 ob_clear_object_flags(uint32 object, uint32 mask);
uint32 ob_invalidate_object_position(uint32 object);
uint32 ob_invalidate_object_matrix(uint32 object);
#endif
