#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_native_dispatch(uint32 target, uint32 count, const uint32 *args)
{
    if (target >= 0x8008D018u && target < 0x80200000u)
        return ob_native_front_dispatch(target, count, args);
    switch (target)
    {
        case 0x800117C8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800117C8((uint32)args[0]);
        case 0x800118C0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800118C0((sint32)args[0]);
        case 0x8001195Cu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8001195C((uint32)args[0], (uint32)args[1]);
        case 0x80011984u:
            if (count != 7u) ob_native_missing(target, 7u, count);
            return (uint32)sub_80011984((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5], (uint32)args[6]);
        case 0x80011DA0u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80011DA0((sint32)args[0], (uint32)args[1]);
        case 0x80011DC0u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80011DC0((uint32)args[0], (uint32)args[1]);
        case 0x80011DE0u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80011DE0((uint32)args[0], (sint32)args[1]);
        case 0x80011DF0u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80011DF0((uint32)args[0], (uint32)args[1]);
        case 0x80012184u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80012184();
        case 0x800121CCu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800121CC((uint32)args[0]);
        case 0x8001221Cu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)overboard_poll_event();
        case 0x80012294u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)overboard_drain_events();
        case 0x800122ECu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)overboard_poll_extended_event();
        case 0x8001237Cu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)overboard_drain_extended_events();
        case 0x800123E4u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_800123E4();
        case 0x80012758u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80012758((uint32)args[0]);
        case 0x800129FCu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800129FC((uint32)args[0]);
        case 0x80012BE8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80012BE8((uint32)args[0]);
        case 0x80013794u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_card_channel((uint32)args[0]);
        case 0x80013818u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_zero_callback();
        case 0x80013820u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_init_view_geometry();
        case 0x80013908u:
            if (count != 5u) ob_native_missing(target, 5u, count);
            return (uint32)ob_append_text_glyphs((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4]);
        case 0x80013C00u:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)ob_append_three_digit_indicator((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x80013FA4u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80013FA4((uint32)args[0]);
        case 0x80014BF8u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_append_player_hud((uint32)args[0], (uint32)args[1]);
        case 0x8001578Cu:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)sub_8001578C((sint32)args[0], (sint32)args[1], (sint32)args[2], (sint32)args[3]);
        case 0x800159C8u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_update_player_heading_and_phase();
        case 0x80015FA8u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_80015FA8((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80016220u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80016220((sint32)args[0]);
        case 0x80016254u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80016254();
        case 0x8001627Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8001627C((sint32)args[0]);
        case 0x80016390u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80016390((uint32)args[0]);
        case 0x80016598u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80016598((uint32)args[0]);
        case 0x80016768u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80016768();
        case 0x800169D0u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_800169D0((uint32)args[0], (uint32)args[1]);
        case 0x80016A50u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80016A50((uint32)args[0]);
        case 0x80016B88u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80016B88((uint32)args[0]);
        case 0x80016C20u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_append_fade_quad((uint32)args[0]);
        case 0x80016FC4u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80016FC4((uint32)args[0]);
        case 0x800170B8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_effect_stub_result((uint32)args[0]);
        case 0x800170C0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_draw_text_end((uint32)args[0]);
        case 0x800170C8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_draw_text_begin((uint32)args[0]);
        case 0x800170D0u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_reset_overlay_state();
        case 0x800170F8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800170F8((uint32)args[0]);
        case 0x80017178u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80017178();
        case 0x800171ECu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_800171EC((sint32)args[0], (sint32)args[1]);
        case 0x80017328u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80017328((uint32)args[0], (sint32)args[1]);
        case 0x800174CCu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800174CC((uint32)args[0]);
        case 0x80017554u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80017554();
        case 0x80018454u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80018454();
        case 0x8001994Cu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8001994C();
        case 0x80019EA0u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80019EA0((uint32)args[0], (uint32)args[1]);
        case 0x80019EE0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80019EE0((uint32)args[0]);
        case 0x8001A05Cu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_read_player_packet((uint32)args[0], (uint32)args[1]);
        case 0x8001A0CCu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_write_player_packet((uint32)args[0], (uint32)args[1]);
        case 0x8001A0F0u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)ob_append_player_packet((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8001A1CCu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8001A1CC();
        case 0x8001A398u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_select_player_origin((uint32)args[0]);
        case 0x8001A4B0u:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)sub_8001A4B0((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x8001A6FCu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8001A6FC();
        case 0x8001B008u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_random15();
        case 0x8001B048u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_set_scene_callback((uint32)args[0], (uint32)args[1]);
        case 0x8001B058u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            nullsub_18(); return 0u;
        case 0x8001CF58u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8001CF58();
        case 0x8001D048u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8001D048((uint32)args[0]);
        case 0x8001D1B0u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_init_card_tables();
        case 0x8001DBCCu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8001DBCC((uint32)args[0]);
        case 0x8001DCF4u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8001DCF4();
        case 0x8001DDA0u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8001DDA0();
        case 0x8001DDF8u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8001DDF8();
        case 0x8001DEB4u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8001DEB4((uint32)args[0]);
        case 0x8001DF34u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_set_audio_mode((uint32)args[0]);
        case 0x8001DF58u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8001DF58((uint32)args[0]);
        case 0x8001DFF0u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8001DFF0();
        case 0x8001E050u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_enable_audio_processing();
        case 0x8001E108u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8001E108();
        case 0x8001E1E0u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8001E1E0();
        case 0x8001E298u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8001E298((uint32)args[0], (uint32)args[1]);
        case 0x8001E540u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8001E540();
        case 0x8001E7B0u:
            if (count != 6u) ob_native_missing(target, 6u, count);
            return (uint32)sub_8001E7B0((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5]);
        case 0x8001EBBCu:
            if (count != 6u) ob_native_missing(target, 6u, count);
            return (uint32)sub_8001EBBC((sint32)args[0], (uint32)args[1], (sint32)args[2], (sint32)args[3], (sint32)args[4], (sint32)args[5]);
        case 0x8001F454u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8001F454((uint32)args[0], (uint32)args[1]);
        case 0x8001F56Cu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8001F56C((uint32)args[0], (sint32)args[1]);
        case 0x8001F5DCu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8001F5DC((uint32)args[0], (uint32)args[1]);
        case 0x8001F64Cu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8001F64C((uint32)args[0], (uint32)args[1]);
        case 0x8001F874u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8001F874();
        case 0x8001F9B0u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8001F9B0((sint32)args[0], (sint32)args[1]);
        case 0x8001FC60u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8001FC60();
        case 0x8001FDA4u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8001FDA4((uint32)args[0]);
        case 0x8001FE3Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return sub_8001FE3C(args[0]);
        case 0x8001FFC0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return sub_8001FFC0(args[0]);
        case 0x8001FEDCu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8001FEDC((uint32)args[0]);
        case 0x80020260u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_swap_bytes((uint32)args[0]);
        case 0x80020288u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_find_sound_slot();
        case 0x800202E8u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_find_voice_slot();
        case 0x80020450u:
            if (count != 5u) ob_native_missing(target, 5u, count);
            return (uint32)ob_append_textured_glyph((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4]);
        case 0x80020864u:
            if (count != 5u) ob_native_missing(target, 5u, count);
            return (uint32)ob_append_colored_texture_quad((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4]);
        case 0x80020A70u:
            if (count != 5u) ob_native_missing(target, 5u, count);
            return (uint32)ob_append_solid_quad((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4]);
        case 0x80020D64u:
            if (count != 5u) ob_native_missing(target, 5u, count);
            return (uint32)ob_append_textured_vertices((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4]);
        case 0x80020FD4u:
            if (count != 5u) ob_native_missing(target, 5u, count);
            return (uint32)ob_append_textured_rectangle((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4]);
        case 0x8002140Cu:
            if (count != 5u) ob_native_missing(target, 5u, count);
            return (uint32)ob_append_colored_texture_scaled((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4]);
        case 0x80021460u:
            if (count != 8u) ob_native_missing(target, 8u, count);
            return (uint32)sub_80021460((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5], (uint32)args[6], (uint32)args[7]);
        case 0x800215FCu:
            if (count != 11u) ob_native_missing(target, 11u, count);
            return (uint32)sub_800215FC((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5], (uint32)args[6], (uint32)args[7], (uint32)args[8], (uint32)args[9], (uint32)args[10]);
        case 0x800217B4u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800217B4((sint32)args[0]);
        case 0x8002192Cu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_append_draw_mode((uint32)args[0], (uint32)args[1]);
        case 0x80021A38u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80021A38((uint32)args[0]);
        case 0x80021AD8u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80021AD8();
        case 0x80021B20u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80021B20((uint32)args[0]);
        case 0x80021C24u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80021C24();
        case 0x80021C74u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_build_weight_tree((uint32)args[0]);
        case 0x80021D80u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_unpack_weight_image((uint32)args[0]);
        case 0x80021DE8u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_decode_weight_tree((uint32)args[0], (uint32)args[1]);
        case 0x80021EFCu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80021EFC();
        case 0x80021FF4u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80021FF4((uint32)args[0]);
        case 0x80022058u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80022058();
        case 0x800220BCu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_800220BC();
        case 0x80022234u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80022234((sint32)args[0]);
        case 0x800222FCu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800222FC((uint32)args[0]);
        case 0x800223A0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800223A0((uint32)args[0]);
        case 0x80022440u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80022440();
        case 0x800224A0u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_800224A0();
        case 0x800226D0u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_800226D0();
        case 0x80022AD4u:
            if (count != 7u) ob_native_missing(target, 7u, count);
            sub_80022AD4((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5], (uint32)args[6]); return 0u;
        case 0x80022C1Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80022C1C((uint32)args[0]);
        case 0x80022CD4u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            sub_80022CD4(); return 0u;
        case 0x80022E78u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80022E78();
        case 0x80023138u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80023138();
        case 0x800231E4u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_800231E4();
        case 0x8002328Cu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8002328C();
        case 0x80023308u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80023308((uint32)args[0]);
        case 0x80023A10u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80023A10();
        case 0x80023AA8u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80023AA8();
        case 0x80023B28u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80023B28((uint32)args[0], (sint32)args[1]);
        case 0x80023C08u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80023C08();
        case 0x80023E30u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80023E30();
        case 0x80023E70u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80023E70();
        case 0x80024310u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_effect_setup_stub_result((uint32)args[0]);
        case 0x80024320u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80024320();
        case 0x8002439Cu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8002439C();
        case 0x80024400u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80024400();
        case 0x80024548u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80024548();
        case 0x80024640u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80024640();
        case 0x80024938u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80024938();
        case 0x80024B40u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80024B40();
        case 0x80024D24u:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)ob_fill_words((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x80024D54u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80024D54((uint32)args[0]);
        case 0x80024EA8u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80024EA8();
        case 0x80024F18u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_set_update_callback((uint32)args[0], (uint32)args[1]);
        case 0x80024F24u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80024F24((uint32)args[0]);
        case 0x8002512Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8002512C((uint32)args[0]);
        case 0x800251E8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800251E8((uint32)args[0]);
        case 0x800255F0u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_memory_set_word_for_payload((uint32)args[0], (uint32)args[1]);
        case 0x80025624u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_set_callback_for_payload((uint32)args[0], (uint32)args[1]);
        case 0x80025658u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_memory_set_tail_for_payload((uint32)args[0], (uint32)args[1]);
        case 0x800256CCu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800256CC((uint32)args[0]);
        case 0x80025700u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80025700((uint32)args[0]);
        case 0x800257A0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_release_reference((uint32)args[0]);
        case 0x800257CCu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800257CC((uint32)args[0]);
        case 0x80025874u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_handle_slot_address((uint32)args[0]);
        case 0x800259ACu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800259AC((uint32)args[0]);
        case 0x80025A9Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80025A9C(args[0]);
        case 0x80025ABCu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80025ABC((uint32)args[0]);
        case 0x80025CB4u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80025CB4((uint32)args[0], (sint32)args[1]);
        case 0x80025D50u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_copy_string((uint32)args[0], (uint32)args[1]);
        case 0x80025D6Cu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_string_equal_code((uint32)args[0], (uint32)args[1]);
        case 0x80025DA0u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80025DA0((uint32)args[0], (uint32)args[1]);
        case 0x800260C8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_query_statistics((uint32)args[0]);
        case 0x800260F8u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_800260F8();
        case 0x80026164u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_80026164((uint32)args[0], (uint32)args[1], (sint32)args[2]);
        case 0x80026278u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_unbind_pool_head((uint32)args[0]);
        case 0x800262CCu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_800262CC((uint32)args[0], (sint32)args[1]);
        case 0x800263B4u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_release_pool_cell((uint32)args[0]);
        case 0x80026418u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80026418();
        case 0x80026444u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_swap_pool_heads((uint32)args[0], (uint32)args[1]);
        case 0x80026460u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_memory_init_groups();
        case 0x80026694u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_80026694((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80026734u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80026734((uint32)args[0], (uint32)args[1]);
        case 0x80026758u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80026758((uint32)args[0]);
        case 0x8002679Cu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_memory_lock_handle((uint32)args[0], (uint32)args[1]);
        case 0x800267C4u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_memory_unlock_handle((uint32)args[0], (uint32)args[1]);
        case 0x80026898u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80026898((uint32)args[0], (uint32)args[1]);
        case 0x800268D0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_payload_size((uint32)args[0]);
        case 0x800268E8u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_800268E8((uint32)args[0], (uint32)args[1]);
        case 0x8002691Cu:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)ob_memory_insert_physical((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80026950u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_merge_next((uint32)args[0]);
        case 0x80026984u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)ob_memory_bind_handle((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x800269D0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800269D0((uint32)args[0]);
        case 0x80026D30u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80026D30((uint32)args[0], (uint32)args[1]);
        case 0x80026EB8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80026EB8((sint32)args[0]);
        case 0x80026F48u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80026F48((uint32)args[0]);
        case 0x80027154u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_coalesce_free((uint32)args[0]);
        case 0x800271ECu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_800271EC((uint32)args[0], (uint32)args[1]);
        case 0x80027274u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80027274((uint32)args[0], (sint32)args[1]);
        case 0x8002744Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8002744C((uint32)args[0]);
        case 0x800276B4u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800276B4((uint32)args[0]);
        case 0x80027710u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80027710((uint32)args[0]);
        case 0x800277D0u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_memory_lock_block((uint32)args[0], (uint32)args[1]);
        case 0x80027810u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_memory_unlock_block((uint32)args[0], (uint32)args[1]);
        case 0x8002785Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_unlink_free((uint32)args[0]);
        case 0x800278ACu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_insert_free((uint32)args[0]);
        case 0x80027978u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_unlink_used((uint32)args[0]);
        case 0x800279A4u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_link_used((uint32)args[0]);
        case 0x800279D4u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800279D4((uint32)args[0]);
        case 0x80027A3Cu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_memory_set_slot_word((uint32)args[0], (uint32)args[1]);
        case 0x80027A74u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_memory_set_slot_callback((uint32)args[0], (uint32)args[1]);
        case 0x80027AACu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_memory_set_slot_tail((uint32)args[0], (uint32)args[1]);
        case 0x80027AE4u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_valid_slot_address((uint32)args[0]);
        case 0x80027CD0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80027CD0((uint32)args[0]);
        case 0x80027D78u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_find_identifier((uint32)args[0]);
        case 0x80027DF8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_slot_address((uint32)args[0]);
        case 0x80027E54u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80027E54((uint32)args[0], (uint32)args[1]);
        case 0x80027E90u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80027E90(args[0]);
        case 0x80027ED8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80027ED8((uint32)args[0]);
        case 0x80027F54u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80027F54();
        case 0x80027F98u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80027F98((uint32)args[0], (uint32)args[1]);
        case 0x80028280u:
            if (count != 4u) ob_native_missing(target, 4u, count);
            sub_80028280((sint32)args[0], (sint32)args[1], (uint32)args[2], (uint32)args[3]); return 0u;
        case 0x800283C0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_unsigned_bit_length((uint32)args[0]);
        case 0x800283DCu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_800283DC((uint32)args[0], (sint32)args[1]);
        case 0x80028614u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80028614((uint32)args[0]);
        case 0x80029290u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80029290();
        case 0x800292B0u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_800292B0((uint32)args[0], (uint32)args[1]);
        case 0x800292ECu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_800292EC((uint32)args[0], (uint32)args[1]);
        case 0x80029B70u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_80029B70((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80029E30u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_copy_vector_words((uint32)args[0], (uint32)args[1]);
        case 0x80029E54u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_identity_matrix14((uint32)args[0]);
        case 0x80029E80u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_angle_matrix14((uint32)args[0], (uint32)args[1]);
        case 0x80029EECu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80029EEC((uint32)args[0], (uint32)args[1]);
        case 0x80029F58u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_y_angle_matrix14((uint32)args[0], (uint32)args[1]);
        case 0x8002A870u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)ob_rotate_matrix_x14((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8002A9DCu:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_8002A9DC((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8002AB48u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)ob_rotate_matrix_z14((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8002ADFCu:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)ob_rotate_matrix_y14((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8002AF54u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)ob_rotate_matrix_rows14((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8002B15Cu:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_8002B15C((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8002B7FCu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_copy_matrix_halfwords((uint32)args[0], (uint32)args[1]);
        case 0x8002B868u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8002B868((uint32)args[0]);
        case 0x8002C4ACu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_classify_clip_planes((uint32)args[0], (uint32)args[1]);
        case 0x8002C728u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8002C728((uint32)args[0]);
        case 0x8002C77Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8002C77C((uint32)args[0]);
        case 0x8002CA3Cu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8002CA3C();
        case 0x8002CCC8u:
            if (count != 7u) ob_native_missing(target, 7u, count);
            return (uint32)ob_clip_viewport((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5], (uint32)args[6]);
        case 0x8002CEB0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8002CEB0((uint32)args[0]);
        case 0x8002CFA8u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_switch_frame_buffer();
        case 0x8002CFE4u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_set_frame_callback((uint32)args[0], (uint32)args[1]);
        case 0x8002CFF4u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8002CFF4();
        case 0x8002D078u:
            if (count != 5u) ob_native_missing(target, 5u, count);
            return (uint32)sub_8002D078((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4]);
        case 0x8002D25Cu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8002D25C((uint32)args[0], (sint32)args[1]);
        case 0x8002D8A8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8002D8A8((uint32)args[0]);
        case 0x8002D98Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8002D98C((uint32)args[0]);
        case 0x8002DA68u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            ob_restore_heap_pointer((uint32)args[0]);
            return 0u;
        case 0x8002DB08u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_snapshot_geometry_state();
        case 0x8002DB3Cu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_snapshot_geometry_context();
        case 0x8002DB6Cu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_align_value((uint32)args[0], (uint32)args[1]);
        case 0x8002DC10u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_reset_geometry_record((uint32)args[0]);
        case 0x8002E8D8u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)ob_rotate_short_pair((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8002F284u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8002F284((uint32)args[0], (uint32)args[1]);
        case 0x8002F310u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8002F310((uint32)args[0], (uint32)args[1]);
        case 0x8002F4CCu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8002F4CC((uint32)args[0]);
        case 0x8002F560u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_transpose_matrix((uint32)args[0]);
        case 0x8002F9C4u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8002F9C4((uint32)args[0], (uint32)args[1]);
        case 0x8002FAA8u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_set_geometry_translation((uint32)args[0], (uint32)args[1]);
        case 0x8002FE50u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_8002FE50((sint32)args[0], (uint32)args[1], (sint32)args[2]);
        case 0x8002FED4u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_8002FED4((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x800303D4u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            sub_800303D4((uint32)args[0], (uint32)args[1]); return 0u;
        case 0x8003042Cu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8003042C((uint32)args[0], (uint32)args[1]);
        case 0x80030700u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_80030700((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8003077Cu:
            if (count != 6u) ob_native_missing(target, 6u, count);
            return (uint32)sub_8003077C((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5]);
        case 0x80030924u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_init_geometry_record();
        case 0x80031FECu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80031FEC();
        case 0x800328ECu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800328EC((uint32)args[0]);
        case 0x80033528u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80033528((uint32)args[0]);
        case 0x80033F48u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_init_object_callbacks();
        case 0x80033F90u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            sub_80033F90(); return 0u;
        case 0x80033FB0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80033FB0((uint32)args[0]);
        case 0x800340A0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800340A0((uint32)args[0]);
        case 0x80034114u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80034114((uint32)args[0], (uint32)args[1]);
        case 0x80034234u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80034234();
        case 0x800342F0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800342F0((uint32)args[0]);
        case 0x80034430u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80034430((uint32)args[0]);
        case 0x80034530u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_stamp_object_records((uint32)args[0]);
        case 0x80034768u:
            if (count != 8u) ob_native_missing(target, 8u, count);
            return (uint32)sub_80034768((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5], (uint32)args[6], (uint32)args[7]);
        case 0x80034910u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80034910((uint32)args[0]);
        case 0x800349D8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800349D8((uint32)args[0]);
        case 0x80034E10u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80034E10((uint32)args[0]);
        case 0x80035178u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_init_geometry_callbacks();
        case 0x80035220u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_reset_geometry_workspace();
        case 0x80035270u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_update_geometry_dimensions();
        case 0x800352B4u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800352B4((uint32)args[0]);
        case 0x800354C8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800354C8((uint32)args[0]);
        case 0x80035618u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_relocate_geometry((uint32)args[0], (uint32)args[1]);
        case 0x800357DCu:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)ob_reserve_vertex_span((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8003584Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8003584C((uint32)args[0]);
        case 0x8003858Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            sub_8003858C((uint32)args[0]); return 0u;
        case 0x80039100u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80039100((uint32)args[0]);
        case 0x80039808u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80039808((sint32)args[0], (sint32)args[1]);
        case 0x80039838u:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)sub_80039838((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x80039BD8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_build_geometry_order((uint32)args[0]);
        case 0x80039C30u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_collect_geometry_callbacks((uint32)args[0], (uint32)args[1]);
        case 0x80039E68u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_collect_geometry_indices((uint32)args[0], (uint32)args[1]);
        case 0x8003A430u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_classify_object_sphere((uint32)args[0], (uint32)args[1]);
        case 0x8003AA8Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8003AA8C((uint32)args[0]);
        case 0x800409E0u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_800409E0();
        case 0x80040BF0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            sub_80040BF0((uint32)args[0]); return 0u;
        case 0x800415E4u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800415E4((uint32)args[0]);
        case 0x80041B74u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_init_geometry_workspace();
        case 0x80041BB8u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80041BB8();
        case 0x80041D7Cu:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_80041D7C((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80042368u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_insert_depth_node((uint32)args[0]);
        case 0x800423D8u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_800423D8();
        case 0x80042424u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80042424((uint32)args[0]);
        case 0x800425ECu:
            if (count != 7u) ob_native_missing(target, 7u, count);
            return (uint32)sub_800425EC((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5], (uint32)args[6]);
        case 0x80042644u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80042644((uint32)args[0]);
        case 0x800427ACu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_800427AC();
        case 0x80042928u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80042928((uint32)args[0], (uint32)args[1]);
        case 0x80042B54u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_80042B54((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80043120u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80043120((uint32)args[0]);
        case 0x80043404u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80043404();
        case 0x800435ACu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_800435AC((uint32)args[0], (uint32)args[1]);
        case 0x80043600u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_80043600((uint32)args[0], (sint32)args[1], (sint32)args[2]);
        case 0x80043664u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_unlink_object_record((uint32)args[0]);
        case 0x800436ACu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_free_object_record((uint32)args[0], (uint32)args[1]);
        case 0x800436D4u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_link_object((uint32)args[0], (uint32)args[1]);
        case 0x800436ECu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_detach_owned_record((uint32)args[0], (uint32)args[1]);
        case 0x8004378Cu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_find_first_typed_child((uint32)args[0], (uint32)args[1]);
        case 0x800437C4u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_800437C4((uint32)args[0], (sint32)args[1]);
        case 0x80043824u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)ob_find_typed_object((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8004389Cu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_find_object_identifier((uint32)args[0], (uint32)args[1]);
        case 0x8004395Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_init_object_list((uint32)args[0]);
        case 0x80043974u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)ob_clear_owner_references((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x800439BCu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_insert_ordered_object((uint32)args[0], (uint32)args[1]);
        case 0x80043AB0u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_remove_ordered_object((uint32)args[0], (uint32)args[1]);
        case 0x80043AF4u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)ob_clear_reference_list((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80043B68u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80043B68((uint32)args[0]);
        case 0x80043BACu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_init_reference_record((uint32)args[0], (uint32)args[1]);
        case 0x80043C18u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_reset_reference_record((uint32)args[0]);
        case 0x80043C6Cu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_free_reference_record((uint32)args[0], (uint32)args[1]);
        case 0x80043C94u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_unlink_reference_node((uint32)args[0]);
        case 0x80043CD4u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            nullsub_25(); return 0u;
        case 0x80043CDCu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_init_base_record((uint32)args[0], (uint32)args[1]);
        case 0x80043CF0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_clear_object_record((uint32)args[0]);
        case 0x80043D20u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_attach_link_record((uint32)args[0], (uint32)args[1]);
        case 0x80043D38u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_detach_link_record((uint32)args[0], (uint32)args[1]);
        case 0x80043D78u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_clear_dependent_chain((uint32)args[0]);
        case 0x80043DACu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_init_optional_link((uint32)args[0]);
        case 0x80043DBCu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_clear_optional_link((uint32)args[0]);
        case 0x80043DECu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_attach_optional_link((uint32)args[0], (uint32)args[1]);
        case 0x80043E14u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_detach_optional_link_record((uint32)args[0]);
        case 0x80043E3Cu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80043E3C((uint32)args[0], (uint32)args[1]);
        case 0x80043EACu:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_80043EAC((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80043FD0u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_destroy_geometry_object((uint32)args[0], (uint32)args[1]);
        case 0x80044058u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_free_geometry_object((uint32)args[0], (uint32)args[1]);
        case 0x800440E8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_detach_geometry_child((uint32)args[0]);
        case 0x800440B8u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            sub_800440B8(args[0], args[1]);
            return 0u;
        case 0x80044130u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            ob_resolve_shape_links((uint32)args[0]);
            return 0u;
        case 0x800441ACu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_next_shape((uint32)args[0], (uint32)args[1]);
        case 0x800442F0u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_800442F0((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8004434Cu:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_8004434C((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80044474u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_80044474((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x800444F4u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_800444F4((uint32)args[0], (uint32)args[1]);
        case 0x80044C58u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_init_audio_callback();
        case 0x80044C90u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80044C90((uint32)args[0]);
        case 0x80044CD4u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80044CD4((uint32)args[0]);
        case 0x80044D50u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_init_scene_geometry();
        case 0x80044DBCu:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)sub_80044DBC((uint32)args[0], (uint32)args[1], (uint32)args[2], (sint32)args[3]);
        case 0x80044E5Cu:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_80044E5C((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80044EDCu:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)sub_80044EDC((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x80045094u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80045094((uint32)args[0]);
        case 0x80045124u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80045124((uint32)args[0]);
        case 0x8004514Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_detach_owner_child((uint32)args[0]);
        case 0x800451E4u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_insert_artic_reference((uint32)args[0], (uint32)args[1]);
        case 0x80045204u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80045204((uint32)args[0]);
        case 0x80045284u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80045284((sint32)args[0], (sint32)args[1]);
        case 0x80045378u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_80045378((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x800453C4u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)ob_copy_advanced_position((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80045430u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80045430((sint32)args[0]);
        case 0x80045464u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80045464((uint32)args[0], (uint32)args[1]);
        case 0x80045490u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80045490((uint32)args[0]);
        case 0x800454BCu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800454BC((uint32)args[0]);
        case 0x800455DCu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_800455DC((uint32)args[0], (uint32)args[1]);
        case 0x80045758u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)ob_advance_object((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80045848u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80045848((uint32)args[0], (uint32)args[1]);
        case 0x800458B4u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_800458B4((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80045A44u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80045A44((uint32)args[0], (uint32)args[1]);
        case 0x80045A7Cu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_set_object_time((uint32)args[0], (uint32)args[1]);
        case 0x80045ADCu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80045ADC((uint32)args[0]);
        case 0x80045B74u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_invalidate_object_matrix((uint32)args[0]);
        case 0x80045C30u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_invalidate_object_position((uint32)args[0]);
        case 0x80045C98u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_clear_object_flags((uint32)args[0], (uint32)args[1]);
        case 0x80045D44u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_init_effect_object_list();
        case 0x80045D70u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80045D70((uint32)args[0]);
        case 0x80045EF4u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_register_effect_object((uint32)args[0]);
        case 0x80045F20u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_unregister_effect_object((uint32)args[0], (uint32)args[1]);
        case 0x80045F4Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80045F4C((uint32)args[0]);
        case 0x800460B0u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_find_collision_slot();
        case 0x80046124u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80046124((uint32)args[0]);
        case 0x80046184u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_80046184((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x800461E8u:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)sub_800461E8((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x800464BCu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800464BC((uint32)args[0]);
        case 0x8004651Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004651C((uint32)args[0]);
        case 0x80046544u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80046544((uint32)args[0]);
        case 0x800465E8u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_800465E8((uint32)args[0], (uint32)args[1]);
        case 0x8004670Cu:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_8004670C((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80046914u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80046914((sint32)args[0], (sint32)args[1]);
        case 0x80046954u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80046954((uint32)args[0], (uint32)args[1]);
        case 0x80046AF8u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80046AF8((uint32)args[0], (uint32)args[1]);
        case 0x80046BE8u:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)sub_80046BE8((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x80046CACu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80046CAC((uint32)args[0]);
        case 0x80046CDCu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80046CDC((uint32)args[0]);
        case 0x80046D98u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80046D98((uint32)args[0]);
        case 0x80046E6Cu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80046E6C((uint32)args[0], (uint32)args[1]);
        case 0x80046EACu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80046EAC((uint32)args[0], (uint32)args[1]);
        case 0x80047050u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80047050((uint32)args[0], (uint32)args[1]);
        case 0x80047140u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80047140((uint32)args[0], (uint32)args[1]);
        case 0x8004719Cu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004719C((uint32)args[0], (sint32)args[1]);
        case 0x8004735Cu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004735C((uint32)args[0], (uint32)args[1]);
        case 0x80047450u:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)sub_80047450((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x800477B8u:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)sub_800477B8((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x8004795Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004795C((uint32)args[0]);
        case 0x800479E0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_select_earliest_flagged_contact((uint32)args[0]);
        case 0x80047A60u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_update_object_collision_time((uint32)args[0], (uint32)args[1]);
        case 0x80047B24u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80047B24((uint32)args[0]);
        case 0x80047B54u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_80047B54((uint32)args[0], (sint32)args[1], (sint32)args[2]);
        case 0x80047E2Cu:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)sub_80047E2C((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x80047F60u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80047F60((uint32)args[0]);
        case 0x80047FF0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80047FF0((uint32)args[0]);
        case 0x80048020u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80048020((uint32)args[0]);
        case 0x800480A8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800480A8((uint32)args[0]);
        case 0x80048124u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80048124((uint32)args[0]);
        case 0x800486E4u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800486E4((uint32)args[0]);
        case 0x800487B8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800487B8((uint32)args[0]);
        case 0x80048978u:
            if (count != 5u) ob_native_missing(target, 5u, count);
            return (uint32)ob_world_store_pair((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4]);
        case 0x80048994u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80048994((uint32)args[0]);
        case 0x80048B60u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_collision_normalize_axes((uint32)args[0]);
        case 0x80048BF4u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80048BF4((uint32)args[0]);
        case 0x80048D2Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80048D2C((uint32)args[0]);
        case 0x80048FECu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_world_axis_entry_time((uint32)args[0], (uint32)args[1]);
        case 0x800491B0u:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)sub_800491B0((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x800493F8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800493F8((uint32)args[0]);
        case 0x8004954Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004954C((uint32)args[0]);
        case 0x800496D8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800496D8((uint32)args[0]);
        case 0x80049A10u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80049A10((uint32)args[0]);
        case 0x80049ED4u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_80049ED4((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8004A048u:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)sub_8004A048((uint32)args[0], (uint32)args[1], (sint32)args[2], (sint32)args[3]);
        case 0x8004A1C0u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8004A1C0();
        case 0x8004A2ECu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004A2EC((uint32)args[0]);
        case 0x8004A410u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004A410((uint32)args[0]);
        case 0x8004A48Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            sub_8004A48C((uint32)args[0]); return 0u;
        case 0x8004A564u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_classify_matrix_direction((uint32)args[0]);
        case 0x8004A5C4u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            sub_8004A5C4(); return 0u;
        case 0x8004A908u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004A908((uint32)args[0]);
        case 0x8004AAFCu:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004AAFC((uint32)args[0], (uint32)args[1]);
        case 0x8004B0B0u:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)ob_border_cell_blocked((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x8004B3C4u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_clear_effect_workspace();
        case 0x8004B3E8u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)ob_border_subcell_to_tile((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8004B450u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004B450((uint32)args[0], (uint32)args[1]);
        case 0x8004B514u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)ob_border_cell_address((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8004B634u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8004B634();
        case 0x8004B6ACu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_init_effect_callbacks();
        case 0x8004B70Cu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_refresh_effect_records();
        case 0x8004B7A0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004B7A0((uint32)args[0]);
        case 0x8004B9B0u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_relocate_effect_tables((uint32)args[0], (uint32)args[1]);
        case 0x8004BA60u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_classify_effect_tables((uint32)args[0]);
        case 0x8004BA98u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_classify_effect_block((uint32)args[0]);
        case 0x8004BB48u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_classify_effect_index((uint32)args[0], (uint32)args[1]);
        case 0x8004BBE4u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_classify_effect_cell((uint32)args[0], (uint32)args[1]);
        case 0x8004BC2Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_classify_effect_blocks((uint32)args[0]);
        case 0x8004BC88u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_classify_effect_indices((uint32)args[0]);
        case 0x8004BCF8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_classify_effect_cells((uint32)args[0]);
        case 0x8004BF54u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004BF54((uint32)args[0], (uint32)args[1]);
        case 0x8004C2C4u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_8004C2C4((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8004C4D4u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)ob_copy_spatial_heights((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8004C64Cu:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)sub_8004C64C((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x8004C944u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004C944((uint32)args[0]);
        case 0x8004CD2Cu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8004CD2C();
        case 0x8004CDF4u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004CDF4((uint32)args[0], (uint32)args[1]);
        case 0x8004CE64u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004CE64((uint32)args[0], (uint32)args[1]);
        case 0x8004CF28u:
            if (count != 5u) ob_native_missing(target, 5u, count);
            return (uint32)ob_build_three_axis_codes((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4]);
        case 0x8004D0F8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_build_view_axis_codes((uint32)args[0]);
        case 0x8004D634u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004D634((uint32)args[0]);
        case 0x8004D76Cu:
            if (count != 6u) ob_native_missing(target, 6u, count);
            return (uint32)sub_8004D76C((uint32)args[0], (uint32)args[1], (uint32)args[2], (sint32)args[3], (sint32)args[4], (sint32)args[5]);
        case 0x8004D910u:
            if (count != 6u) ob_native_missing(target, 6u, count);
            return (uint32)sub_8004D910((uint32)args[0], (uint32)args[1], (uint32)args[2], (sint32)args[3], (sint32)args[4], (sint32)args[5]);
        case 0x8004DAA4u:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)sub_8004DAA4((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x8004DB40u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_8004DB40((uint32)args[0], (sint32)args[1], (uint32)args[2]);
        case 0x8004DFB8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004DFB8((sint32)args[0]);
        case 0x8004E028u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_8004E028((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8004E310u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004E310((uint32)args[0], (sint32)args[1]);
        case 0x8004E3B0u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8004E3B0();
        case 0x8004E518u:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)sub_8004E518((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x8004E584u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_8004E584((uint32)args[0], (sint32)args[1], (uint32)args[2]);
        case 0x8004E614u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004E614((uint32)args[0]);
        case 0x8004E644u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004E644((uint32)args[0]);
        case 0x8004E70Cu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_init_sea_texture_packet();
        case 0x8004E814u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8004E814();
        case 0x8004E9E4u:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)sub_8004E9E4((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x8004EC6Cu:
            if (count != 5u) ob_native_missing(target, 5u, count);
            return (uint32)ob_append_sea_quad((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4]);
        case 0x8004EEF4u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004EEF4((uint32)args[0], (uint32)args[1]);
        case 0x8004F004u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004F004((sint32)args[0], (uint32)args[1]);
        case 0x8004F064u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_scene_stub_result((uint32)args[0]);
        case 0x8004F074u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_8004F074((sint32)args[0], (sint32)args[1], (sint32)args[2]);
        case 0x8004F0D8u:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)sub_8004F0D8((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x8004F288u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004F288((uint32)args[0]);
        case 0x8004F2C4u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004F2C4((uint32)args[0], (sint32)args[1]);
        case 0x8004F31Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004F31C((uint32)args[0]);
        case 0x8004F354u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)ob_update_ground_collision_time((uint32)args[0], (uint32)args[1]);
        case 0x8004F418u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_8004F418((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8004F478u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004F478((uint32)args[0], (uint32)args[1]);
        case 0x8004F51Cu:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_8004F51C((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8004F610u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004F610((uint32)args[0], (uint32)args[1]);
        case 0x8004F758u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004F758((uint32)args[0], (uint32)args[1]);
        case 0x8004FA0Cu:
            if (count != 6u) ob_native_missing(target, 6u, count);
            return (uint32)sub_8004FA0C((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (sint32)args[4], (sint32)args[5]);
        case 0x8004FC64u:
            if (count != 7u) ob_native_missing(target, 7u, count);
            return (uint32)sub_8004FC64((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5], (uint32)args[6]);
        case 0x80050088u:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)sub_80050088((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x800502ACu:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_800502AC((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80050380u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80050380((uint32)args[0]);
        case 0x80050550u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80050550((uint32)args[0]);
        case 0x80050644u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80050644((uint32)args[0]);
        case 0x80050870u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_select_spatial_event((uint32)args[0]);
        case 0x800508D0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_800508D0((uint32)args[0]);
        case 0x80050A2Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80050A2C((uint32)args[0]);
        case 0x80050B88u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80050B88((uint32)args[0], (uint32)args[1]);
        case 0x80051400u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80051400((uint32)args[0], (uint32)args[1]);
        case 0x80051450u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80051450((uint32)args[0], (uint32)args[1]);
        case 0x800514E4u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)ob_locate_spatial_cell((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8005160Cu:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)ob_step_spatial_cell((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80051974u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80051974();
        case 0x80052A68u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80052A68();
        case 0x80053D20u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80053D20((sint32)args[0], (sint32)args[1]);
        case 0x80053E2Cu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_update_controller_flags();
        case 0x800540F8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_controller_slot_ready((uint32)args[0]);
        case 0x80054264u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80054264();
        case 0x80054320u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_snapshot_controller_flags();
        case 0x80054440u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_consume_button_edge((uint32)args[0]);
        case 0x800544ECu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_clear_button_edges();
        case 0x80054780u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80054780();
        case 0x8005491Cu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_8005491C();
        case 0x80054A24u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80054A24((sint32)args[0], (uint32)args[1]);
        case 0x80054AE0u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_file_finish_request();
        case 0x80054B30u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80054B30();
        case 0x80054C14u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80054C14();
        case 0x80054CA8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_reset_file_setup((uint32)args[0]);
        case 0x80054CD8u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80054CD8();
        case 0x80054CECu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            sub_80054CEC(); return 0u;
        case 0x80054CFCu:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_file_reset_tables();
        case 0x80054D50u:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)ob_bcd_fields_to_frame((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x80054E08u:
            if (count != 4u) ob_native_missing(target, 4u, count);
            return (uint32)sub_80054E08((sint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x80054EFCu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_80054EFC((uint32)args[0]);
        case 0x800551B0u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_file_close_slot((uint32)args[0]);
        case 0x800551F8u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)ob_file_seek((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x800552D4u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_800552D4((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x800553D0u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            return (uint32)sub_800553D0((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x800556D8u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_file_entry_size((uint32)args[0]);
        case 0x800556F4u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_800556F4();
        case 0x8005577Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)sub_8005577C((uint32)args[0]);
        case 0x80055808u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_80055808();
        case 0x800558E4u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            sub_800558E4(); return 0u;
        case 0x800558F4u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            sub_800558F4(); return 0u;
        case 0x80055954u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_80055954((uint32)args[0], (uint32)args[1]);
        case 0x80056580u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_bcd_to_frame((uint32)args[0]);
        case 0x80058D98u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            sub_80058D98(); return 0u;
        case 0x80058FC0u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_stream_stub_result();
        case 0x80059128u:
            if (count != 3u) ob_native_missing(target, 3u, count);
            sub_80059128((sint32)args[0], (sint32)args[1], (sint32)args[2]); return 0u;
        case 0x8005A9DCu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_set_render_mode((uint32)args[0]);
        case 0x8005A9F4u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)ob_get_render_mode();
        case 0x8005F468u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            sub_8005F468((uint32)args[0], (uint32)args[1]); return 0u;
        case 0x8005F488u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            sub_8005F488((uint32)args[0]); return 0u;
        case 0x8005F998u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            sub_8005F998(); return 0u;
        case 0x800602D0u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            return (uint32)sub_800602D0();
        case 0x80061034u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            sub_80061034(); return 0u;
        case 0x800629C4u:
            if (count != 2u) ob_native_missing(target, 2u, count);
            return (uint32)sub_800629C4((uint32)args[0], (uint32)args[1]);
        case 0x80063C1Cu:
            if (count != 1u) ob_native_missing(target, 1u, count);
            sub_80063C1C((sint32)args[0]); return 0u;
        case 0x80063C70u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            sub_80063C70(); return 0u;
        case 0x80063CD8u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            sub_80063CD8(); return 0u;
        case 0x80063CE8u:
            if (count != 0u) ob_native_missing(target, 0u, count);
            sub_80063CE8(); return 0u;
        case 0x80064900u:
            if (count != 1u) ob_native_missing(target, 1u, count);
            return (uint32)ob_exchange_callback_state((uint32)args[0]);
        default: ob_native_missing(target, UINT32_MAX, count);
    }
}
