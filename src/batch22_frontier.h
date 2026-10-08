#ifndef OB_BATCH22_FRONTIER_H
#define OB_BATCH22_FRONTIER_H
#include "xport.h"
uint32 ob_reset_file_setup(uint32 incoming_result);
uint32 ob_stamp_object_records(uint32 incoming_result);
uint32 ob_init_optional_link(uint32 node);
uint32 ob_attach_link_record(uint32 head, uint32 node);
uint32 ob_attach_optional_link(uint32 node, uint32 head);
uint32 ob_init_reference_record(uint32 object, uint32 head);
uint32 ob_rotate_matrix_rows14(uint32 source, uint32 angle, uint32 output);
uint32 ob_find_first_typed_child(uint32 parent, uint32 type);
uint32 ob_insert_ordered_object(uint32 list, uint32 object);
uint32 ob_register_effect_object(uint32 object);
#endif
