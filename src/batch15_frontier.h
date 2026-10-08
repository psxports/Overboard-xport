#ifndef OB_BATCH15_FRONTIER_H
#define OB_BATCH15_FRONTIER_H
#include "xport.h"
uint32 ob_set_scene_callback(uint32 callback, uint32 incoming_result);
uint32 ob_init_scene_geometry(void);
uint32 ob_identity_matrix14(uint32 matrix);
uint32 ob_copy_vector_words(uint32 source, uint32 destination);
uint32 ob_copy_matrix_halfwords(uint32 source, uint32 destination);
uint32 ob_set_geometry_translation(uint32 geometry, uint32 source);
uint32 ob_transpose_matrix(uint32 matrix);
uint32 ob_init_card_tables(void);
uint32 ob_set_frame_callback(uint32 callback, uint32 incoming_result);
#endif
