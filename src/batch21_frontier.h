#ifndef OB_BATCH21_FRONTIER_H
#define OB_BATCH21_FRONTIER_H
#include "xport.h"
uint32 ob_relocate_effect_tables(uint32 descriptor, uint32 base);
uint32 ob_classify_effect_block(uint32 block);
uint32 ob_classify_effect_blocks(uint32 descriptor);
uint32 ob_classify_effect_index(uint32 cell, uint32 descriptor);
uint32 ob_classify_effect_indices(uint32 descriptor);
uint32 ob_classify_effect_cell(uint32 cell, uint32 descriptor);
uint32 ob_classify_effect_cells(uint32 descriptor);
uint32 ob_classify_effect_tables(uint32 descriptor);
uint32 ob_effect_setup_stub_result(uint32 incoming_result);
uint32 ob_clear_effect_workspace(void);
uint32 ob_init_view_geometry(void);
uint32 ob_refresh_effect_records(void);
uint32 ob_init_effect_object_list(void);
#endif
