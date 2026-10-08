#ifndef OB_DRAFT_SIGNATURES_H
#define OB_DRAFT_SIGNATURES_H

#include "xport.h"
#include "psx.h"

/* Unverified draft declarations */
uint32 sub_800117C8(uint32 a1);
sint32 sub_800118C0(sint32 a1);
uint32 sub_8001195C(uint32 a1, uint32 a2);
uint32 sub_80011984(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7);
sint32 sub_80011DA0(sint32 a1, uint32 a2);
uint32 sub_80011DC0(uint32 a1, uint32 a2);
sint32 sub_80011DE0(uint32 a0_unused, sint32 multiplier);
uint32 sub_80011DF0(uint32 a1, uint32 product_low);
uint32 sub_80012184(void);
uint32 sub_800121CC(uint32 a1);
sint32 overboard_poll_event(void);
sint32 overboard_drain_events(void);
sint32 overboard_poll_extended_event(void);
sint32 overboard_drain_extended_events(void);
sint32 sub_800123E4(void);
uint32 sub_80012758(uint32 a1);
uint32 sub_800129FC(uint32 a1);
uint32 sub_80012BE8(uint32 a1);
uint32 ob_card_channel(uint32 index);
uint32 ob_zero_callback(void);
uint32 ob_init_view_geometry(void);
uint32 ob_append_text_glyphs(uint32 string, uint32 x, uint32 y, uint32 caller_stack, uint32 incoming_result);
uint32 ob_append_three_digit_indicator(uint32 value, uint32 x, uint32 y, uint32 caller_stack);
uint32 sub_80013FA4(uint32 a1);
uint32 ob_append_player_hud(uint32 player_index, uint32 caller_stack);
sint32 sub_8001578C(sint32 a1, sint32 a2, sint32 a3, sint32 a4);
uint32 ob_update_player_heading_and_phase(void);
uint32 sub_80015FA8(uint32 a1, uint32 a2, uint32 a3);
sint32 sub_80016220(sint32 a1);
uint32 sub_80016254(void);
sint32 sub_8001627C(sint32 a1);
uint32 sub_80016390(uint32 a1);
uint32 sub_80016598(uint32 a1);
uint32 sub_80016768(void);
sint32 sub_800169D0(uint32 a1, uint32 a2);
uint32 sub_80016A50(uint32 a1);
uint32 sub_80016B88(uint32 a1);
uint32 ob_append_fade_quad(uint32 intensity);
sint32 sub_80016FC4(uint32 a1);
uint32 ob_effect_stub_result(uint32 incoming_result);
uint32 ob_draw_text_end(uint32 incoming_result);
uint32 ob_draw_text_begin(uint32 incoming_result);
uint32 ob_reset_overlay_state(void);
uint32 sub_800170F8(uint32 a1);
uint32 sub_80017178(void);
sint32 sub_800171EC(sint32 a1, sint32 a2);
uint32 sub_80017328(uint32 a1, sint32 a2);
uint32 sub_800174CC(uint32 a1);
uint32 sub_80017554(void);
uint32 sub_80018454(void);
uint32 sub_8001994C(void);
uint32 sub_80019EA0(uint32 a1, uint32 a2);
uint32 sub_80019EE0(uint32 a1);
uint32 ob_read_player_packet(uint32 output, uint32 index);
uint32 ob_write_player_packet(uint32 index, uint32 value);
uint32 ob_append_player_packet(uint32 count, uint32 value, uint32 offset);
uint32 sub_8001A1CC(void);
uint32 ob_select_player_origin(uint32 identifier);
uint32 sub_8001A4B0(uint32 a1, uint32 a2, uint32 a3, uint32 divisor_address);
sint32 sub_8001A6FC(void);
uint32 ob_random15(void);
uint32 ob_set_scene_callback(uint32 callback, uint32 incoming_result);
void nullsub_18(void);
uint32 sub_8001CF58(void);
uint32 sub_8001D048(uint32 a1);
uint32 ob_init_card_tables(void);
uint32 sub_8001DBCC(uint32 a1);
uint32 sub_8001DCF4(void);
uint32 sub_8001DDA0(void);
sint32 sub_8001DDF8(void);
uint32 sub_8001DEB4(uint32 a1);
uint32 ob_set_audio_mode(uint32 mode);
sint32 sub_8001DF58(uint32 a1);
sint32 sub_8001DFF0(void);
uint32 ob_enable_audio_processing(void);
sint32 sub_8001E108(void);
uint32 sub_8001E1E0(void);
uint32 sub_8001E298(uint32 a1, uint32 a2);
sint32 sub_8001E540(void);
uint32 sub_8001E7B0(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a9, uint32 a10);
sint32 sub_8001EBBC(sint32 a1, uint32 a2, sint32 a3, sint32 a4, sint32 a5, sint32 a6);
uint32 sub_8001F454(uint32 a1, uint32 a2);
sint32 sub_8001F56C(uint32 a1, sint32 a2);
uint32 sub_8001F5DC(uint32 a1, uint32 a2);
uint32 sub_8001F64C(uint32 a1, uint32 a2);
sint32 sub_8001F874(void);
sint32 sub_8001F9B0(sint32 a1, sint32 a2);
uint32 sub_8001FC60(void);
uint32 sub_8001FDA4(uint32 sound_slot);
uint32 sub_8001FE3C(uint32 sound_slot);
uint32 sub_8001FFC0(uint32 sound_slot);
uint32 sub_8001FEDC(uint32 a1);
uint32 ob_swap_bytes(uint32 value);
uint32 ob_find_sound_slot(void);
uint32 ob_find_voice_slot(void);
uint32 ob_append_textured_glyph(uint32 descriptor, uint32 u, uint32 v, uint32 width, uint32 caller_stack);
uint32 ob_append_colored_texture_quad(uint32 descriptor, uint32 u, uint32 v, uint32 width, uint32 caller_stack);
uint32 ob_append_solid_quad(uint32 x, uint32 y, uint32 width, uint32 height, uint32 caller_stack);
uint32 ob_append_textured_vertices(uint32 descriptor, uint32 u, uint32 v, uint32 u_end, uint32 caller_stack);
uint32 ob_append_textured_rectangle(uint32 descriptor, uint32 u, uint32 v, uint32 width, uint32 caller_stack);
uint32 ob_append_colored_texture_scaled(uint32 descriptor, uint32 u, uint32 v, uint32 width, uint32 caller_stack);
uint32 sub_80021460(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8);
uint32 sub_800215FC(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8, uint32 a9, uint32 a10, uint32 a11);
uint32 sub_800217B4(sint32 a1);
uint32 ob_append_draw_mode(uint32 blend, uint32 caller_stack);
uint32 sub_80021A38(uint32 a1);
sint32 sub_80021AD8(void);
uint32 sub_80021B20(uint32 a1);
sint32 sub_80021C24(void);
uint32 ob_build_weight_tree(uint32 tree);
uint32 ob_unpack_weight_image(uint32 tree);
uint32 ob_decode_weight_tree(uint32 tree, uint32 root);
uint32 sub_80021EFC(void);
uint32 sub_80021FF4(uint32 a1);
uint32 sub_80022058(void);
sint32 sub_800220BC(void);
sint32 sub_80022234(sint32 a1);
uint32 sub_800222FC(uint32 a1);
uint32 sub_800223A0(uint32 a1);
uint32 sub_80022440(void);
uint32 sub_800224A0(void);
sint32 sub_800226D0(void);
void sub_80022AD4(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7);
uint32 sub_80022C1C(uint32 a1);
void sub_80022CD4(void);
sint32 sub_80022E78(void);
uint32 sub_80023138(void);
uint32 sub_800231E4(void);
uint32 sub_8002328C(void);
uint32 sub_80023308(uint32 a1);
sint32 sub_80023A10(void);
uint32 sub_80023AA8(void);
sint32 sub_80023B28(uint32 a1, sint32 a2);
uint32 sub_80023C08(void);
uint32 sub_80023E30(void);
sint32 sub_80023E70(void);
uint32 ob_effect_setup_stub_result(uint32 incoming_result);
sint32 sub_80024320(void);
uint32 sub_8002439C(void);
uint32 sub_80024400(void);
sint32 sub_80024548(void);
sint32 sub_80024640(void);
sint32 sub_80024938(void);
uint32 sub_80024B40(void);
uint32 ob_fill_words(uint32 destination, uint32 bytes, uint32 value, uint32 incoming_result);
sint32 sub_80024D54(uint32 a1);
uint32 sub_80024EA8(void);
uint32 ob_set_update_callback(uint32 callback, uint32 incoming_result);
sint32 sub_80024F24(uint32 a1);
sint32 sub_8002512C(uint32 a1);
uint32 sub_800251E8(uint32 a1);
uint32 ob_memory_set_word_for_payload(uint32 payload, uint32 value);
uint32 ob_set_callback_for_payload(uint32 payload, uint32 callback);
uint32 ob_memory_set_tail_for_payload(uint32 payload, uint32 value);
sint32 sub_800256CC(uint32 a1);
uint32 sub_80025700(uint32 a1);
uint32 ob_memory_release_reference(uint32 handle);
uint32 sub_800257CC(uint32 a1);
uint32 ob_handle_slot_address(uint32 identifier);
uint32 sub_800259AC(uint32 a1);
uint32 sub_80025A9C(uint32 handle);
uint32 sub_80025ABC(uint32 a1);
sint32 sub_80025CB4(uint32 a1, sint32 a2);
uint32 ob_copy_string(uint32 destination, uint32 source);
uint32 ob_string_equal_code(uint32 left, uint32 right);
uint32 sub_80025DA0(uint32 a1, uint32 a2);
uint32 ob_memory_query_statistics(uint32 output);
sint32 sub_800260F8(void);
uint32 sub_80026164(uint32 a1, uint32 a2, sint32 a3);
uint32 ob_unbind_pool_head(uint32 cell);
uint32 sub_800262CC(uint32 a1, sint32 a2);
uint32 ob_release_pool_cell(uint32 cell);
uint32 sub_80026418(void);
uint32 ob_swap_pool_heads(uint32 first, uint32 second);
uint32 ob_memory_init_groups(void);
uint32 sub_80026694(uint32 a1, uint32 a2, uint32 a3);
uint32 sub_80026734(uint32 a1, uint32 requested_size);
uint32 sub_80026758(uint32 a1);
uint32 ob_memory_lock_handle(uint32 handle, uint32 flags);
uint32 ob_memory_unlock_handle(uint32 handle, uint32 flags);
uint32 sub_80026898(uint32 a1, uint32 a2);
uint32 ob_memory_payload_size(uint32 handle);
uint32 sub_800268E8(uint32 a1, uint32 a2);
uint32 ob_memory_insert_physical(uint32 block, uint32 previous, uint32 size);
uint32 ob_memory_merge_next(uint32 block);
uint32 ob_memory_bind_handle(uint32 block, uint32 handle, uint32 flags);
sint32 sub_800269D0(uint32 a1);
uint32 sub_80026D30(uint32 a1, uint32 a2);
sint32 sub_80026EB8(sint32 a1);
uint32 sub_80026F48(uint32 a1);
uint32 ob_memory_coalesce_free(uint32 block);
uint32 sub_800271EC(uint32 a1, uint32 a2);
sint32 sub_80027274(uint32 a1, sint32 a2);
sint32 sub_8002744C(uint32 a1);
uint32 sub_800276B4(uint32 a1);
uint32 sub_80027710(uint32 a1);
uint32 ob_memory_lock_block(uint32 block, uint32 flags);
uint32 ob_memory_unlock_block(uint32 block, uint32 flags);
uint32 ob_memory_unlink_free(uint32 block);
uint32 ob_memory_insert_free(uint32 block);
uint32 ob_memory_unlink_used(uint32 block);
uint32 ob_memory_link_used(uint32 block);
sint32 sub_800279D4(uint32 a1);
uint32 ob_memory_set_slot_word(uint32 identifier, uint32 value);
uint32 ob_memory_set_slot_callback(uint32 identifier, uint32 callback);
uint32 ob_memory_set_slot_tail(uint32 identifier, uint32 value);
uint32 ob_memory_valid_slot_address(uint32 identifier);
uint32 sub_80027CD0(uint32 a1);
uint32 ob_memory_find_identifier(uint32 payload);
uint32 ob_memory_slot_address(uint32 identifier);
uint32 sub_80027E54(uint32 a1, uint32 a2);
uint32 sub_80027E90(uint32 page_index);
uint32 sub_80027ED8(uint32 a1);
uint32 sub_80027F54(void);
uint32 sub_80027F98(uint32 a1, uint32 a2);
void sub_80028280(sint32 a1, sint32 a2, uint32 a3, uint32 a4);
uint32 ob_unsigned_bit_length(uint32 value);
sint32 sub_800283DC(uint32 a1, sint32 a2);
sint32 sub_80028614(uint32 a1);
uint32 sub_80029290(void);
uint32 sub_800292B0(uint32 a1, uint32 a2);
uint32 sub_800292EC(uint32 a1, uint32 a2);
uint32 sub_80029B70(uint32 a1, uint32 a2, uint32 a3);
uint32 ob_copy_vector_words(uint32 source, uint32 destination);
uint32 ob_identity_matrix14(uint32 matrix);
uint32 ob_angle_matrix14(uint32 angle, uint32 matrix);
uint32 sub_80029EEC(uint32 a1, uint32 a2);
uint32 ob_y_angle_matrix14(uint32 angle, uint32 matrix);
uint32 ob_rotate_matrix_x14(uint32 matrix, uint32 angle, uint32 output);
sint32 sub_8002A9DC(uint32 a1, uint32 a2, uint32 a3);
uint32 ob_rotate_matrix_z14(uint32 matrix, uint32 angle, uint32 output);
uint32 ob_rotate_matrix_y14(uint32 matrix, uint32 angle, uint32 output);
uint32 ob_rotate_matrix_rows14(uint32 source, uint32 angle, uint32 output);
uint32 sub_8002B15C(uint32 a1, uint32 a2, uint32 a3);
uint32 ob_copy_matrix_halfwords(uint32 source, uint32 destination);
uint32 sub_8002B868(uint32 a1);
uint32 ob_classify_clip_planes(uint32 vertices, uint32 count);
uint32 sub_8002C728(uint32 a1);
uint32 sub_8002C77C(uint32 a1);
sint32 sub_8002CA3C(void);
uint32 ob_clip_viewport(uint32 record, uint32 left, uint32 top, uint32 right, uint32 bottom, uint32 dx, uint32 dy);
sint32 sub_8002CEB0(uint32 a1);
uint32 ob_switch_frame_buffer(void);
uint32 ob_set_frame_callback(uint32 callback, uint32 incoming_result);
uint32 sub_8002CFF4(void);
uint32 sub_8002D078(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5);
sint32 sub_8002D25C(uint32 a1, sint32 a2);
uint32 sub_8002D8A8(uint32 a1);
uint32 sub_8002D98C(uint32 a1);
void ob_restore_heap_pointer(uint32 pointer);
uint32 ob_snapshot_geometry_state(void);
uint32 ob_snapshot_geometry_context(void);
uint32 ob_align_value(uint32 value, uint32 alignment);
uint32 ob_reset_geometry_record(uint32 record);
uint32 ob_rotate_short_pair(uint32 first, uint32 second, uint32 angle);
uint32 sub_8002F284(uint32 a1, uint32 a2);
uint32 sub_8002F310(uint32 a1, uint32 a2);
uint32 sub_8002F4CC(uint32 a1);
uint32 ob_transpose_matrix(uint32 matrix);
uint32 sub_8002F9C4(uint32 a1, uint32 a2);
uint32 ob_set_geometry_translation(uint32 geometry, uint32 source);
sint32 sub_8002FE50(sint32 a1, uint32 a2, sint32 a3);
uint32 sub_8002FED4(uint32 a1, uint32 a2, uint32 a3);
void sub_800303D4(uint32 a1, uint32 a2);
sint32 sub_8003042C(uint32 a1, uint32 a2);
sint32 sub_80030700(uint32 a1, uint32 a2, uint32 a3);
uint32 sub_8003077C(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6);
uint32 ob_init_geometry_record(void);
uint32 sub_80031FEC(void);
uint32 sub_800328EC(uint32 a1);
uint32 sub_80033528(uint32 a1);
uint32 ob_init_object_callbacks(void);
void sub_80033F90(void);
uint32 sub_80033FB0(uint32 a1);
uint32 sub_800340A0(uint32 a1);
uint32 sub_80034114(uint32 a1, uint32 a2);
sint32 sub_80034234(void);
uint32 sub_800342F0(uint32 a1);
sint32 sub_80034430(uint32 a1);
uint32 ob_stamp_object_records(uint32 incoming_result);
uint32 sub_80034768(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a9, uint32 a10, uint32 a11, uint32 a12);
uint32 sub_80034910(uint32 a1);
uint32 sub_800349D8(uint32 a1);
sint32 sub_80034E10(uint32 a1);
uint32 ob_init_geometry_callbacks(void);
uint32 ob_reset_geometry_workspace(void);
uint32 ob_update_geometry_dimensions(void);
uint32 sub_800352B4(uint32 a1);
uint32 sub_800354C8(uint32 a1);
uint32 ob_relocate_geometry(uint32 geometry, uint32 base);
uint32 ob_reserve_vertex_span(uint32 record, uint32 requested, uint32 stride);
uint32 sub_8003584C(uint32 a1);
void sub_8003858C(uint32 a1);
uint32 sub_80039100(uint32 a1);
sint32 sub_80039808(sint32 a1, sint32 a2);
uint32 sub_80039838(uint32 a1, uint32 a2, uint32 a3, uint32 a4);
uint32 ob_build_geometry_order(uint32 descriptor);
uint32 ob_collect_geometry_callbacks(uint32 root, uint32 depth);
uint32 ob_collect_geometry_indices(uint32 root, uint32 depth);
uint32 ob_classify_object_sphere(uint32 position, uint32 resource);
sint32 sub_8003AA8C(uint32 a1);
uint32 sub_800409E0(void);
void sub_80040BF0(uint32 a1);
sint32 sub_800415E4(uint32 a1);
uint32 ob_init_geometry_workspace(void);
sint32 sub_80041BB8(void);
uint32 sub_80041D7C(uint32 a1, uint32 a2, uint32 a3);
uint32 ob_insert_depth_node(uint32 root);
uint32 sub_800423D8(void);
sint32 sub_80042424(uint32 a1);
uint32 sub_800425EC(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7);
uint32 sub_80042644(uint32 a1);
sint32 sub_800427AC(void);
sint32 sub_80042928(uint32 a1, uint32 a2);
uint32 sub_80042B54(uint32 a1, uint32 a2, uint32 a3);
sint32 sub_80043120(uint32 a1);
sint32 sub_80043404(void);
uint32 sub_800435AC(uint32 a1, uint32 a2);
uint32 sub_80043600(uint32 a1, sint32 a2, sint32 a3);
uint32 ob_unlink_object_record(uint32 object);
uint32 ob_free_object_record(uint32 object, uint32 guest_sp);
uint32 ob_link_object(uint32 parent, uint32 child);
uint32 ob_detach_owned_record(uint32 parent, uint32 object);
uint32 ob_find_first_typed_child(uint32 parent, uint32 type);
sint32 sub_800437C4(uint32 a1, sint32 a2);
uint32 ob_find_typed_object(uint32 parent, uint32 type, uint32 identifier);
uint32 ob_find_object_identifier(uint32 object, uint32 identifier);
uint32 ob_init_object_list(uint32 list);
uint32 ob_clear_owner_references(uint32 list, uint32 incoming_result, uint32 guest_sp);
uint32 ob_insert_ordered_object(uint32 list, uint32 object);
uint32 ob_remove_ordered_object(uint32 object, uint32 guest_sp);
uint32 ob_clear_reference_list(uint32 list, uint32 incoming_result, uint32 guest_sp);
uint32 sub_80043B68(uint32 a1);
uint32 ob_init_reference_record(uint32 object, uint32 head);
uint32 ob_reset_reference_record(uint32 record);
uint32 ob_free_reference_record(uint32 record, uint32 guest_sp);
uint32 ob_unlink_reference_node(uint32 node);
void nullsub_25(void);
uint32 ob_init_base_record(uint32 record, uint32 value);
uint32 ob_clear_object_record(uint32 object);
uint32 ob_attach_link_record(uint32 head, uint32 node);
uint32 ob_detach_link_record(uint32 parent, uint32 record);
uint32 ob_clear_dependent_chain(uint32 object);
uint32 ob_init_optional_link(uint32 node);
uint32 ob_clear_optional_link(uint32 record);
uint32 ob_attach_optional_link(uint32 node, uint32 head);
uint32 ob_detach_optional_link_record(uint32 record);
uint32 sub_80043E3C(uint32 a1, uint32 a2);
uint32 sub_80043EAC(uint32 a1, uint32 a2, uint32 a3);
uint32 ob_destroy_geometry_object(uint32 object, uint32 guest_sp);
uint32 ob_free_geometry_object(uint32 object, uint32 guest_sp);
uint32 ob_detach_geometry_child(uint32 object);
void ob_resolve_shape_links(uint32 root);
void sub_800440B8(uint32 object, uint32 value);
uint32 ob_next_shape(uint32 root, uint32 object);
uint32 sub_800442F0(uint32 a1, uint32 a2, uint32 a3);
uint32 sub_8004434C(uint32 a1, uint32 a2, uint32 a3);
uint32 sub_80044474(uint32 a1, uint32 a2, uint32 a3);
uint32 sub_800444F4(uint32 a1, uint32 a2);
uint32 ob_init_audio_callback(void);
uint32 sub_80044C90(uint32 a1);
sint32 sub_80044CD4(uint32 a1);
uint32 ob_init_scene_geometry(void);
sint32 sub_80044DBC(uint32 a1, uint32 a2, uint32 a3, sint32 a4);
uint32 sub_80044E5C(uint32 a1, uint32 a2, uint32 a3);
uint32 sub_80044EDC(uint32 a1, uint32 a2, uint32 a3, uint32 a4);
sint32 sub_80045094(uint32 a1);
sint32 sub_80045124(uint32 a1);
uint32 ob_detach_owner_child(uint32 object);
uint32 ob_insert_artic_reference(uint32 object, uint32 reference);
uint32 sub_80045204(uint32 a1);
sint32 sub_80045284(sint32 a1, sint32 a2);
uint32 sub_80045378(uint32 a1, uint32 a2, uint32 a3);
uint32 ob_copy_advanced_position(uint32 object, uint32 time, uint32 output);
sint32 sub_80045430(sint32 a1);
uint32 sub_80045464(uint32 a1, uint32 a2);
uint32 sub_80045490(uint32 a1);
sint32 sub_800454BC(uint32 a1);
uint32 sub_800455DC(uint32 a1, uint32 a2);
uint32 ob_advance_object(uint32 object, uint32 time, uint32 incoming_result);
sint32 sub_80045848(uint32 a1, uint32 a2);
uint32 sub_800458B4(uint32 a1, uint32 a2, uint32 a3);
uint32 sub_80045A44(uint32 a1, uint32 a2);
uint32 ob_set_object_time(uint32 object, uint32 time);
uint32 sub_80045ADC(uint32 a1);
uint32 ob_invalidate_object_matrix(uint32 object);
uint32 ob_invalidate_object_position(uint32 object);
uint32 ob_clear_object_flags(uint32 object, uint32 mask);
uint32 ob_init_effect_object_list(void);
uint32 sub_80045D70(uint32 a1);
uint32 ob_register_effect_object(uint32 object);
uint32 ob_unregister_effect_object(uint32 object, uint32 guest_sp);
uint32 sub_80045F4C(uint32 a1);
uint32 ob_find_collision_slot(void);
uint32 sub_80046124(uint32 a1);
uint32 sub_80046184(uint32 a1, uint32 a2, uint32 a3);
uint32 sub_800461E8(uint32 a1, uint32 a2, uint32 a3, uint32 a4);
uint32 sub_800464BC(uint32 a1);
sint32 sub_8004651C(uint32 a1);
uint32 sub_80046544(uint32 a1);
sint32 sub_800465E8(uint32 a1, uint32 a2);
uint32 sub_8004670C(uint32 a1, uint32 a2, uint32 a3);
sint32 sub_80046914(sint32 a1, sint32 a2);
uint32 sub_80046954(uint32 a1, uint32 a2);
uint32 sub_80046AF8(uint32 a1, uint32 a2);
uint32 sub_80046BE8(uint32 a1, uint32 a2, uint32 a3, uint32 a4);
uint32 sub_80046CAC(uint32 a1);
uint32 sub_80046CDC(uint32 a1);
uint32 sub_80046D98(uint32 a1);
uint32 sub_80046E6C(uint32 a1, uint32 a2);
uint32 sub_80046EAC(uint32 a1, uint32 a2);
uint32 sub_80047050(uint32 a1, uint32 a2);
uint32 sub_80047140(uint32 a1, uint32 a2);
sint32 sub_8004719C(uint32 a1, sint32 a2);
uint32 sub_8004735C(uint32 a1, uint32 a2);
uint32 sub_80047450(uint32 a1, uint32 a2, uint32 a3, uint32 a4);
uint32 sub_800477B8(uint32 a1, uint32 a2, uint32 a3, uint32 a4);
sint32 sub_8004795C(uint32 a1);
uint32 ob_select_earliest_flagged_contact(uint32 object);
uint32 ob_update_object_collision_time(uint32 object, uint32 guest_sp);
uint32 sub_80047B24(uint32 a1);
sint32 sub_80047B54(uint32 a1, sint32 a2, sint32 a3);
uint32 sub_80047E2C(uint32 a1, uint32 a2, uint32 a3, uint32 a4);
uint32 sub_80047F60(uint32 a1);
sint32 sub_80047FF0(uint32 a1);
uint32 sub_80048020(uint32 a1);
uint32 sub_800480A8(uint32 a1);
uint32 sub_80048124(uint32 a1);
uint32 sub_800486E4(uint32 a1);
uint32 sub_800487B8(uint32 a1);
uint32 ob_world_store_pair(uint32 first, uint32 second, uint32 time, uint32 result_record, uint32 caller_stack);
uint32 sub_80048994(uint32 a1);
uint32 ob_collision_normalize_axes(uint32 collision);
sint32 sub_80048BF4(uint32 a1);
uint32 sub_80048D2C(uint32 a1);
uint32 ob_world_axis_entry_time(uint32 record, uint32 caller_stack);
uint32 sub_800491B0(uint32 a1, uint32 a2, uint32 a3, uint32 a4);
uint32 sub_800493F8(uint32 a1);
uint32 sub_8004954C(uint32 a1);
uint32 sub_800496D8(uint32 a1);
uint32 sub_80049A10(uint32 a1);
uint32 sub_80049ED4(uint32 a1, uint32 a2, uint32 a3);
sint32 sub_8004A048(uint32 a1, uint32 a2, sint32 a3, sint32 a4);
uint32 sub_8004A1C0(void);
uint32 sub_8004A2EC(uint32 a1);
uint32 sub_8004A410(uint32 a1);
void sub_8004A48C(uint32 a1);
uint32 ob_classify_matrix_direction(uint32 matrix);
void sub_8004A5C4(void);
uint32 sub_8004A908(uint32 a1);
uint32 sub_8004AAFC(uint32 a1, uint32 a2);
uint32 ob_border_cell_blocked(uint32 packed, uint32 position, uint32 radius, uint32 caller_stack);
uint32 ob_clear_effect_workspace(void);
uint32 ob_border_subcell_to_tile(uint32 output, uint32 packed, uint32 caller_stack);
uint32 sub_8004B450(uint32 a1, uint32 a2);
uint32 ob_border_cell_address(uint32 packed, uint32 dimensions, uint32 caller_stack);
uint32 sub_8004B634(void);
uint32 ob_init_effect_callbacks(void);
uint32 ob_refresh_effect_records(void);
sint32 sub_8004B7A0(uint32 a1);
uint32 ob_relocate_effect_tables(uint32 descriptor, uint32 base);
uint32 ob_classify_effect_tables(uint32 descriptor);
uint32 ob_classify_effect_block(uint32 block);
uint32 ob_classify_effect_index(uint32 cell, uint32 descriptor);
uint32 ob_classify_effect_cell(uint32 cell, uint32 descriptor);
uint32 ob_classify_effect_blocks(uint32 descriptor);
uint32 ob_classify_effect_indices(uint32 descriptor);
uint32 ob_classify_effect_cells(uint32 descriptor);
uint32 sub_8004BF54(uint32 a1, uint32 a2);
uint32 sub_8004C2C4(uint32 a1, uint32 a2, uint32 a3);
uint32 ob_copy_spatial_heights(uint32 output, uint32 state, uint32 stride);
uint32 sub_8004C64C(uint32 a1, uint32 a2, uint32 a3, uint32 a4);
uint32 sub_8004C944(uint32 a1);
sint32 sub_8004CD2C(void);
uint32 sub_8004CDF4(uint32 a1, uint32 a2);
uint32 sub_8004CE64(uint32 a1, uint32 a2);
uint32 ob_build_three_axis_codes(uint32 primary, uint32 secondary, uint32 table, uint32 position, uint32 limit);
uint32 ob_build_view_axis_codes(uint32 caller_stack);
uint32 sub_8004D634(uint32 a1);
sint32 sub_8004D76C(uint32 a1, uint32 a2, uint32 a3, sint32 a4, sint32 a5, sint32 a6);
sint32 sub_8004D910(uint32 a1, uint32 a2, uint32 a3, sint32 a4, sint32 a5, sint32 a6);
uint32 sub_8004DAA4(uint32 a1, uint32 a2, uint32 a3, uint32 a4);
sint32 sub_8004DB40(uint32 a1, sint32 a2, uint32 a3);
sint32 sub_8004DFB8(sint32 a1);
uint32 sub_8004E028(uint32 a1, uint32 a2, uint32 a3);
sint32 sub_8004E310(uint32 a1, sint32 a2);
uint32 sub_8004E3B0(void);
uint32 sub_8004E518(uint32 a1, uint32 a2, uint32 a3, uint32 a4);
sint32 sub_8004E584(uint32 a1, sint32 a2, uint32 a3);
uint32 sub_8004E614(uint32 a1);
uint32 sub_8004E644(uint32 a1);
uint32 ob_init_sea_texture_packet(void);
uint32 sub_8004E814(void);
sint32 sub_8004E9E4(uint32 a1, uint32 a2, uint32 a3, uint32 a4);
uint32 ob_append_sea_quad(uint32 first, uint32 second, uint32 third, uint32 fourth, uint32 caller_stack);
uint32 sub_8004EEF4(uint32 a1, uint32 a2);
sint32 sub_8004F004(sint32 a1, uint32 a2);
uint32 ob_scene_stub_result(uint32 incoming_result);
sint32 sub_8004F074(sint32 a1, sint32 a2, sint32 a3);
uint32 sub_8004F0D8(uint32 a1, uint32 a2, uint32 a3, uint32 a4);
sint32 sub_8004F288(uint32 a1);
sint32 sub_8004F2C4(uint32 a1, sint32 a2);
uint32 sub_8004F31C(uint32 a1);
uint32 ob_update_ground_collision_time(uint32 object, uint32 guest_sp);
uint32 sub_8004F418(uint32 a1, uint32 a2, uint32 a3);
uint32 sub_8004F478(uint32 a1, uint32 a3);
uint32 sub_8004F51C(uint32 a1, uint32 a2, uint32 a3);
uint32 sub_8004F610(uint32 a1, uint32 a2);
uint32 sub_8004F758(uint32 a1, uint32 a2);
uint32 sub_8004FA0C(uint32 a1, uint32 a2, uint32 a3, uint32 a4, sint32 a5, sint32 a6);
uint32 sub_8004FC64(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7);
uint32 sub_80050088(uint32 a1, uint32 a2, uint32 a3, uint32 a4);
uint32 sub_800502AC(uint32 a1, uint32 a2, uint32 a3);
uint32 sub_80050380(uint32 a1);
uint32 sub_80050550(uint32 a1);
uint32 sub_80050644(uint32 a1);
uint32 ob_select_spatial_event(uint32 state);
sint32 sub_800508D0(uint32 a1);
uint32 sub_80050A2C(uint32 a1);
sint32 sub_80050B88(uint32 a1, uint32 a2);
uint32 sub_80051400(uint32 a1, uint32 a2);
uint32 sub_80051450(uint32 a1, uint32 a2);
uint32 ob_locate_spatial_cell(uint32 x, uint32 z, uint32 output);
uint32 ob_step_spatial_cell(uint32 state, uint32 axis, uint32 increment);
sint32 sub_80051974(void);
uint32 sub_80052A68(void);
sint32 sub_80053D20(sint32 a1, sint32 a2);
uint32 ob_update_controller_flags(void);
uint32 ob_controller_slot_ready(uint32 index);
uint32 sub_80054264(void);
uint32 ob_snapshot_controller_flags(void);
uint32 ob_consume_button_edge(uint32 index);
uint32 ob_clear_button_edges(void);
uint32 sub_80054780(void);
sint32 sub_8005491C(void);
sint32 sub_80054A24(sint32 a1, uint32 a2);
uint32 ob_file_finish_request(void);
uint32 sub_80054B30(void);
uint32 sub_80054C14(void);
uint32 ob_reset_file_setup(uint32 incoming_result);
sint32 sub_80054CD8(void);
void sub_80054CEC(void);
uint32 ob_file_reset_tables(void);
uint32 ob_bcd_fields_to_frame(uint32 minute, uint32 second, uint32 frame, uint32 destination);
sint32 sub_80054E08(sint32 a1, uint32 a2, uint32 a3, uint32 a4);
uint32 sub_80054EFC(uint32 a1);
uint32 ob_file_close_slot(uint32 index);
uint32 ob_file_seek(uint32 index, uint32 offset, uint32 origin);
uint32 sub_800552D4(uint32 a1, uint32 a2, uint32 a3);
uint32 sub_800553D0(uint32 a1, uint32 a2, uint32 a3);
uint32 ob_file_entry_size(uint32 index);
uint32 sub_800556F4(void);
uint32 sub_8005577C(uint32 a1);
uint32 sub_80055808(void);
void sub_800558E4(void);
void sub_800558F4(void);
uint32 sub_80055954(uint32 a1, uint32 a2);
uint32 ob_bcd_to_frame(uint32 source);
void sub_80058D98(void);
uint32 ob_stream_stub_result(void);
void sub_80059128(sint32 a1, sint32 a2, sint32 a3);
uint32 ob_set_render_mode(uint32 mode);
uint32 ob_get_render_mode(void);
void sub_8005F468(uint32 a1, uint32 a2);
void sub_8005F488(uint32 a1);
void sub_8005F998(void);
uint32 sub_800602D0(void);
void sub_80061034(void);
uint32 sub_800629C4(uint32 a1, uint32 a2);
void sub_80063C1C(sint32 a1);
void sub_80063C70(void);
void sub_80063CD8(void);
void sub_80063CE8(void);
uint32 ob_exchange_callback_state(uint32 value);

/* Existing entry names retain their current signatures */
#define sub_8001221C overboard_poll_event
#define sub_80012294 overboard_drain_events
#define sub_800122EC overboard_poll_extended_event
#define sub_8001237C overboard_drain_extended_events
#define sub_80013794 ob_card_channel
#define sub_80013818 ob_zero_callback
#define sub_80013820 ob_init_view_geometry
#define sub_80013908 ob_append_text_glyphs
#define sub_80013C00 ob_append_three_digit_indicator
#define sub_80014BF8 ob_append_player_hud
#define sub_800159C8 ob_update_player_heading_and_phase
#define sub_80016C20 ob_append_fade_quad
#define sub_800170B8 ob_effect_stub_result
#define sub_800170C0 ob_draw_text_end
#define sub_800170C8 ob_draw_text_begin
#define sub_800170D0 ob_reset_overlay_state
#define sub_8001A05C ob_read_player_packet
#define sub_8001A0CC ob_write_player_packet
#define sub_8001A0F0 ob_append_player_packet
#define sub_8001A398 ob_select_player_origin
#define sub_8001B008 ob_random15
#define sub_8001B048 ob_set_scene_callback
#define sub_8001D1B0 ob_init_card_tables
#define sub_8001DF34 ob_set_audio_mode
#define sub_8001E050 ob_enable_audio_processing
#define sub_80020260 ob_swap_bytes
#define sub_80020288 ob_find_sound_slot
#define sub_800202E8 ob_find_voice_slot
#define sub_80020450 ob_append_textured_glyph
#define sub_80020864 ob_append_colored_texture_quad
#define sub_80020A70 ob_append_solid_quad
#define sub_80020D64 ob_append_textured_vertices
#define sub_80020FD4 ob_append_textured_rectangle
#define sub_8002140C ob_append_colored_texture_scaled
#define sub_8002192C ob_append_draw_mode
#define sub_80021C74 ob_build_weight_tree
#define sub_80021D80 ob_unpack_weight_image
#define sub_80021DE8 ob_decode_weight_tree
#define sub_80024310 ob_effect_setup_stub_result
#define sub_80024D24 ob_fill_words
#define sub_80024F18 ob_set_update_callback
#define sub_800255F0 ob_memory_set_word_for_payload
#define sub_80025624 ob_set_callback_for_payload
#define sub_80025658 ob_memory_set_tail_for_payload
#define sub_800257A0 ob_memory_release_reference
#define sub_80025874 ob_handle_slot_address
#define sub_80025D50 ob_copy_string
#define sub_80025D6C ob_string_equal_code
#define sub_800260C8 ob_memory_query_statistics
#define sub_80026278 ob_unbind_pool_head
#define sub_800263B4 ob_release_pool_cell
#define sub_80026444 ob_swap_pool_heads
#define sub_80026460 ob_memory_init_groups
#define sub_8002679C ob_memory_lock_handle
#define sub_800267C4 ob_memory_unlock_handle
#define sub_800268D0 ob_memory_payload_size
#define sub_8002691C ob_memory_insert_physical
#define sub_80026950 ob_memory_merge_next
#define sub_80026984 ob_memory_bind_handle
#define sub_80027154 ob_memory_coalesce_free
#define sub_800277D0 ob_memory_lock_block
#define sub_80027810 ob_memory_unlock_block
#define sub_8002785C ob_memory_unlink_free
#define sub_800278AC ob_memory_insert_free
#define sub_80027978 ob_memory_unlink_used
#define sub_800279A4 ob_memory_link_used
#define sub_80027A3C ob_memory_set_slot_word
#define sub_80027A74 ob_memory_set_slot_callback
#define sub_80027AAC ob_memory_set_slot_tail
#define sub_80027AE4 ob_memory_valid_slot_address
#define sub_80027D78 ob_memory_find_identifier
#define sub_80027DF8 ob_memory_slot_address
#define sub_800283C0 ob_unsigned_bit_length
#define sub_80029E30 ob_copy_vector_words
#define sub_80029E54 ob_identity_matrix14
#define sub_80029E80 ob_angle_matrix14
#define sub_80029F58 ob_y_angle_matrix14
#define sub_8002A870 ob_rotate_matrix_x14
#define sub_8002AB48 ob_rotate_matrix_z14
#define sub_8002ADFC ob_rotate_matrix_y14
#define sub_8002AF54 ob_rotate_matrix_rows14
#define sub_8002B7FC ob_copy_matrix_halfwords
#define sub_8002C4AC ob_classify_clip_planes
#define sub_8002CCC8 ob_clip_viewport
#define sub_8002CFA8 ob_switch_frame_buffer
#define sub_8002CFE4 ob_set_frame_callback
#define sub_8002DA68 ob_restore_heap_pointer
#define sub_8002DB08 ob_snapshot_geometry_state
#define sub_8002DB3C ob_snapshot_geometry_context
#define sub_8002DB6C ob_align_value
#define sub_8002DC10 ob_reset_geometry_record
#define sub_8002E8D8 ob_rotate_short_pair
#define sub_8002F560 ob_transpose_matrix
#define sub_8002FAA8 ob_set_geometry_translation
#define sub_80030924 ob_init_geometry_record
#define sub_80033F48 ob_init_object_callbacks
#define sub_80034530 ob_stamp_object_records
#define sub_80035178 ob_init_geometry_callbacks
#define sub_80035220 ob_reset_geometry_workspace
#define sub_80035270 ob_update_geometry_dimensions
#define sub_80035618 ob_relocate_geometry
#define sub_800357DC ob_reserve_vertex_span
#define sub_80039BD8 ob_build_geometry_order
#define sub_80039C30 ob_collect_geometry_callbacks
#define sub_80039E68 ob_collect_geometry_indices
#define sub_8003A430 ob_classify_object_sphere
#define sub_80041B74 ob_init_geometry_workspace
#define sub_80042368 ob_insert_depth_node
#define sub_80043664 ob_unlink_object_record
#define sub_800436AC ob_free_object_record
#define sub_800436D4 ob_link_object
#define sub_800436EC ob_detach_owned_record
#define sub_8004378C ob_find_first_typed_child
#define sub_80043824 ob_find_typed_object
#define sub_8004389C ob_find_object_identifier
#define sub_8004395C ob_init_object_list
#define sub_80043974 ob_clear_owner_references
#define sub_800439BC ob_insert_ordered_object
#define sub_80043AB0 ob_remove_ordered_object
#define sub_80043AF4 ob_clear_reference_list
#define sub_80043BAC ob_init_reference_record
#define sub_80043C18 ob_reset_reference_record
#define sub_80043C6C ob_free_reference_record
#define sub_80043C94 ob_unlink_reference_node
#define sub_80043CDC ob_init_base_record
#define sub_80043CF0 ob_clear_object_record
#define sub_80043D20 ob_attach_link_record
#define sub_80043D38 ob_detach_link_record
#define sub_80043D78 ob_clear_dependent_chain
#define sub_80043DAC ob_init_optional_link
#define sub_80043DBC ob_clear_optional_link
#define sub_80043DEC ob_attach_optional_link
#define sub_80043E14 ob_detach_optional_link_record
#define sub_80043FD0 ob_destroy_geometry_object
#define sub_80044058 ob_free_geometry_object
#define sub_800440E8 ob_detach_geometry_child
#define sub_80044130 ob_resolve_shape_links
#define sub_800441AC ob_next_shape
#define sub_80044C58 ob_init_audio_callback
#define sub_80044D50 ob_init_scene_geometry
#define sub_8004514C ob_detach_owner_child
#define sub_800451E4 ob_insert_artic_reference
#define sub_800453C4 ob_copy_advanced_position
#define sub_80045758 ob_advance_object
#define sub_80045A7C ob_set_object_time
#define sub_80045B74 ob_invalidate_object_matrix
#define sub_80045C30 ob_invalidate_object_position
#define sub_80045C98 ob_clear_object_flags
#define sub_80045D44 ob_init_effect_object_list
#define sub_80045EF4 ob_register_effect_object
#define sub_80045F20 ob_unregister_effect_object
#define sub_800460B0 ob_find_collision_slot
#define sub_800479E0 ob_select_earliest_flagged_contact
#define sub_80047A60 ob_update_object_collision_time
#define sub_80048978 ob_world_store_pair
#define sub_80048B60 ob_collision_normalize_axes
#define sub_80048FEC ob_world_axis_entry_time
#define sub_8004A564 ob_classify_matrix_direction
#define sub_8004B0B0 ob_border_cell_blocked
#define sub_8004B3C4 ob_clear_effect_workspace
#define sub_8004B3E8 ob_border_subcell_to_tile
#define sub_8004B514 ob_border_cell_address
#define sub_8004B6AC ob_init_effect_callbacks
#define sub_8004B70C ob_refresh_effect_records
#define sub_8004B9B0 ob_relocate_effect_tables
#define sub_8004BA60 ob_classify_effect_tables
#define sub_8004BA98 ob_classify_effect_block
#define sub_8004BB48 ob_classify_effect_index
#define sub_8004BBE4 ob_classify_effect_cell
#define sub_8004BC2C ob_classify_effect_blocks
#define sub_8004BC88 ob_classify_effect_indices
#define sub_8004BCF8 ob_classify_effect_cells
#define sub_8004C4D4 ob_copy_spatial_heights
#define sub_8004CF28 ob_build_three_axis_codes
#define sub_8004D0F8 ob_build_view_axis_codes
#define sub_8004E70C ob_init_sea_texture_packet
#define sub_8004EC6C ob_append_sea_quad
#define sub_8004F064 ob_scene_stub_result
#define sub_8004F354 ob_update_ground_collision_time
#define sub_80050870 ob_select_spatial_event
#define sub_800514E4 ob_locate_spatial_cell
#define sub_8005160C ob_step_spatial_cell
#define sub_80053E2C ob_update_controller_flags
#define sub_800540F8 ob_controller_slot_ready
#define sub_80054320 ob_snapshot_controller_flags
#define sub_80054440 ob_consume_button_edge
#define sub_800544EC ob_clear_button_edges
#define sub_80054AE0 ob_file_finish_request
#define sub_80054CA8 ob_reset_file_setup
#define sub_80054CFC ob_file_reset_tables
#define sub_80054D50 ob_bcd_fields_to_frame
#define sub_800551B0 ob_file_close_slot
#define sub_800551F8 ob_file_seek
#define sub_800556D8 ob_file_entry_size
#define sub_80056580 ob_bcd_to_frame
#define sub_80058FC0 ob_stream_stub_result
#define sub_8005A9DC ob_set_render_mode
#define sub_8005A9F4 ob_get_render_mode
#define sub_80064900 ob_exchange_callback_state

/* Unresolved carriers terminate with an explicit diagnostic */
uint32 ob_native_missing_value(uint32 owner, const char *carrier);
uint32 ob_draft_unresolved_call(uint32 target, uint32 argument_count, ...);
uint32 ob_draft_scratch_acquire(uint32 size);
void ob_draft_scratch_release(uint32 address);

#endif
