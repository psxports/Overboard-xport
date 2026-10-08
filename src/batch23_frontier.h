#ifndef OB_BATCH23_FRONTIER_H
#define OB_BATCH23_FRONTIER_H
#include "xport.h"
uint32 ob_select_player_origin(uint32 identifier);
uint32 ob_find_collision_slot(void);
uint32 ob_remove_ordered_object(uint32 object, uint32 guest_sp);
uint32 ob_unregister_effect_object(uint32 object, uint32 guest_sp);
uint32 ob_update_object_collision_time(uint32 object, uint32 guest_sp);
uint32 ob_update_ground_collision_time(uint32 object, uint32 guest_sp);
uint32 ob_insert_artic_reference(uint32 object, uint32 reference);
uint32 ob_copy_advanced_position(uint32 object, uint32 time, uint32 output);
uint32 ob_y_angle_matrix14(uint32 angle, uint32 matrix);
#endif
