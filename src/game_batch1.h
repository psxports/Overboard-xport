#ifndef OB_GAME_BATCH1_H
#define OB_GAME_BATCH1_H
#include "xport.h"
uint32 ob_update_player_heading_and_phase(void);
uint32 ob_rotate_short_pair(uint32 first, uint32 second, uint32 angle);
uint32 ob_append_fade_quad(uint32 intensity);
uint32 ob_append_draw_mode(uint32 blend, uint32 caller_stack);
uint32 ob_append_solid_quad(uint32 x, uint32 y, uint32 width, uint32 height, uint32 caller_stack);
uint32 ob_append_textured_vertices(uint32 descriptor, uint32 u, uint32 v, uint32 u_end, uint32 caller_stack);
uint32 ob_append_textured_glyph(uint32 descriptor, uint32 u, uint32 v, uint32 width, uint32 caller_stack);
uint32 ob_append_text_glyphs(uint32 string, uint32 x, uint32 y, uint32 caller_stack, uint32 incoming_result);
uint32 ob_append_textured_rectangle(uint32 descriptor, uint32 u, uint32 v, uint32 width, uint32 caller_stack);
uint32 ob_append_colored_texture_quad(uint32 descriptor, uint32 u, uint32 v, uint32 width, uint32 caller_stack);
uint32 ob_append_colored_texture_scaled(uint32 descriptor, uint32 u, uint32 v, uint32 width, uint32 caller_stack);
uint32 ob_classify_matrix_direction(uint32 matrix);
uint32 ob_build_three_axis_codes(uint32 primary, uint32 secondary, uint32 table, uint32 position, uint32 limit);
uint32 ob_append_three_digit_indicator(uint32 value, uint32 x, uint32 y, uint32 caller_stack);
uint32 ob_build_view_axis_codes(uint32 caller_stack);
uint32 ob_append_player_hud(uint32 player_index, uint32 caller_stack);
uint32 ob_border_cell_blocked(uint32 packed, uint32 position, uint32 radius, uint32 caller_stack);
uint32 ob_border_cell_address(uint32 packed, uint32 dimensions, uint32 caller_stack);
uint32 ob_border_subcell_to_tile(uint32 output, uint32 packed, uint32 caller_stack);
uint32 ob_classify_clip_planes(uint32 vertices, uint32 count);
uint32 ob_classify_object_sphere(uint32 position, uint32 resource);
uint32 ob_reserve_vertex_span(uint32 record, uint32 requested, uint32 stride);
uint32 ob_append_sea_quad(uint32 first, uint32 second, uint32 third, uint32 fourth, uint32 caller_stack);
uint32 ob_init_sea_texture_packet(void);
uint32 ob_unsigned_bit_length(uint32 value);
uint32 ob_world_store_pair(uint32 first, uint32 second, uint32 time, uint32 result_record, uint32 caller_stack);
uint32 ob_world_axis_entry_time(uint32 record, uint32 caller_stack);
uint32 ob_zero_callback(void);
uint32 ob_controller_slot_ready(uint32 index);
uint32 ob_select_spatial_event(uint32 state);
uint32 ob_collision_normalize_axes(uint32 collision);
uint32 ob_select_earliest_flagged_contact(uint32 object);
#endif
