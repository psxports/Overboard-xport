#ifndef OB_BATCH24_FRONTIER_H
#define OB_BATCH24_FRONTIER_H
#include "xport.h"
uint32 ob_rotate_matrix_z14(uint32 matrix, uint32 angle, uint32 output);
uint32 ob_rotate_matrix_x14(uint32 matrix, uint32 angle, uint32 output);
uint32 ob_set_object_time(uint32 object, uint32 time);
uint32 ob_rotate_matrix_y14(uint32 matrix, uint32 angle, uint32 output);
uint32 ob_read_player_packet(uint32 output, uint32 index);
uint32 ob_append_player_packet(uint32 count, uint32 value, uint32 offset);
uint32 ob_write_player_packet(uint32 index, uint32 value);
#endif
