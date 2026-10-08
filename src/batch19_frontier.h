#ifndef OB_BATCH19_FRONTIER_H
#define OB_BATCH19_FRONTIER_H

#include "xport.h"

void ob_restore_heap_pointer(uint32 pointer);
uint32 ob_release_pool_cell(uint32 cell);
uint32 ob_unlink_reference_node(uint32 node);
uint32 ob_detach_link_record(uint32 parent, uint32 record);
uint32 ob_detach_optional_link_record(uint32 record);
uint32 ob_clear_optional_link(uint32 record);
uint32 ob_reset_reference_record(uint32 record);
uint32 ob_free_reference_record(uint32 record, uint32 guest_sp);
uint32 ob_clear_reference_list(uint32 list, uint32 incoming_result, uint32 guest_sp);
uint32 ob_clear_owner_references(uint32 list, uint32 incoming_result, uint32 guest_sp);
uint32 ob_detach_owner_child(uint32 object);
uint32 ob_detach_geometry_child(uint32 object);
uint32 ob_detach_foreign_geometry_child(uint32 object);
uint32 ob_detach_owned_record(uint32 parent, uint32 object);
uint32 ob_clear_dependent_chain(uint32 object);
uint32 ob_clear_object_record(uint32 object);
uint32 ob_unlink_object_record(uint32 object);
uint32 ob_destroy_geometry_object(uint32 object, uint32 guest_sp);
uint32 ob_free_geometry_object(uint32 object, uint32 guest_sp);

#endif
