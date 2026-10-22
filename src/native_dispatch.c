#include "draft_signatures.h"
#include "native_runtime.h"
#include "native_extra_signatures.h"

uint32 ob_native_dispatch(uint32 target, uint32 count, const uint32 *args)
{
    if (target >= 0x8008D018u && target < 0x80200000u)
        return ob_native_front_dispatch(target, count, args);
    switch (target)
    {
    case 0x80046660:
        if (count < 3) ob_native_missing(target, 3, count);
        return ob_main_80046660(args[0], args[1], args[2]);
    case 0x80015E98:
        if (count < 3) ob_native_missing(target, 3, count);
        ob_main_80015E98(args[0], args[1], args[2]); return 0;
    case 0x80015F70:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80015F70(args[0]);
    case 0x800452A4:
        if (count < 3) ob_native_missing(target, 3, count);
        return ob_main_800452A4(args[0], args[1], args[2]);

    case 0x80011F24:
        if (count < 4) ob_native_missing(target, 4, count);
        return ob_main_80011F24(args[0], args[1], args[2], args[3]);
    case 0x80012A90:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80012A90(args[0]);
    case 0x80012B70:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80012B70(args[0]);
    case 0x80013318:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_80013318(args[0], args[1]);
    case 0x80013360:
        if (count < 4) ob_native_missing(target, 4, count);
        return ob_main_80013360(args[0], args[1], args[2], args[3]);
    case 0x800130C4:
        if (count < 6) ob_native_missing(target, 6, count);
        return ob_main_800130C4(args[0], args[1], args[2], args[3], args[4], args[5]);
    case 0x80020BD8:
        if (count < 3) ob_native_missing(target, 3, count);
        return ob_main_80020BD8(args[0], args[1], args[2]);
    case 0x8002A110:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8002A110(args[0], args[1]);
    case 0x8001A4A0:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8001A4A0(args[0], args[1]);
    case 0x80013614:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_80013614(args[0], args[1]);
    case 0x80016D24:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80016D24(args[0]);
    case 0x80016E4C:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80016E4C(args[0]);
    case 0x80029CD0:
        if (count < 3) ob_native_missing(target, 3, count);
        return ob_main_80029CD0(args[0], args[1], args[2]);
    case 0x8002ACA8:
        if (count < 3) ob_native_missing(target, 3, count);
        return ob_main_8002ACA8(args[0], args[1], args[2]);
    case 0x80049318:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80049318(args[0]);
    case 0x80049CEC:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80049CEC(args[0]);
    case 0x80049FCC:
        if (count < 4) ob_native_missing(target, 4, count);
        return ob_main_80049FCC(args[0], args[1], args[2], args[3]);
    case 0x8004BD74:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_8004BD74(args[0]);
    case 0x8004BE08:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_8004BE08(args[0]);
    case 0x8001DFCC:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_8001DFCC(args[0]);
    case 0x80011870:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80011870(args[0]);
    case 0x80012164:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80012164(args[0]);
    case 0x800135EC:
        return ob_main_800135EC();
    case 0x8001A690:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8001A690(args[0], args[1]);
    case 0x8001AFC8:
        return ob_main_8001AFC8();
    case 0x8004545C:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_8004545C(args[0]);
    case 0x80045D0C:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80045D0C(args[0]);
    case 0x800499C0:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_800499C0(args[0]);
    case 0x8004E680:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_8004E680(args[0]);
    case 0x8004F9A0:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8004F9A0(args[0], args[1]);
    case 0x80024E04:
        return ob_main_80024E04();
    case 0x8001F6E8:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8001F6E8(args[0], args[1]);
    case 0x80011D80:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_80011D80(args[0], args[1]);

    case 0x80011A24u:
        if (count < 6) ob_native_missing(target, 6u, count);
        return ob_main_80011A24(args[0], args[1], args[2], args[3], args[4], args[5]);
        case 0x80028784u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return ob_main_80028784(args[0], args[1]);
        case 0x80011E20u:
            if (count < 4) ob_native_missing(target, 4u, count);
            ob_main_80011E20(args[0], args[1], args[2], args[3]);
            return 0u;
        case 0x80045410u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return ob_main_80045410(args[0], args[1]);
        case 0x80054538u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return ob_main_80054538(args[0]);
        case 0x800285A4u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return ob_main_800285A4(args[0], args[1], args[2]);
        case 0x80044080u:
            if (count < 2) ob_native_missing(target, 2u, count);
            ob_main_80044080(args[0], args[1]);
            return 0u;
        case 0x8004E66Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return ob_main_8004E66C(args[0]);
        case 0x8004E694u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return ob_main_8004E694(args[0], args[1]);
        case 0x800117C8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800117C8((uint32)args[0]);
        case 0x800118C0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800118C0((sint32)args[0]);
        case 0x8001195Cu:
            if (count == 2) return ob_stop_sound_with_mask(args[0], args[1]);
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8001195C((uint32)args[0]);
        case 0x80011984u:
            if (count < 7) ob_native_missing(target, 7u, count);
            return (uint32)sub_80011984((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5], (uint32)args[6]);
        case 0x80011DA0u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80011DA0((sint32)args[0], (uint32)args[1]);
        case 0x80011DC0u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80011DC0((uint32)args[0], (uint32)args[1]);
        case 0x80011DE0u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80011DE0((uint32)args[0], (sint32)args[1]);
        case 0x80011DF0u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80011DF0((uint32)args[0], (uint32)args[1]);
        case 0x80012184u:
            return (uint32)sub_80012184();
        case 0x800121CCu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800121CC((uint32)args[0]);
        case 0x8001221Cu:
            return (uint32)overboard_poll_event();
        case 0x80012294u:
            return (uint32)overboard_drain_events();
        case 0x800122ECu:
            return (uint32)overboard_poll_extended_event();
        case 0x8001237Cu:
            return (uint32)overboard_drain_extended_events();
        case 0x800123E4u:
            return (uint32)sub_800123E4();
        case 0x80012758u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80012758((uint32)args[0]);
        case 0x800129FCu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800129FC((uint32)args[0]);
        case 0x80012BE8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80012BE8((uint32)args[0]);
        case 0x80013794u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_card_channel((uint32)args[0]);
        case 0x80013818u:
            return (uint32)ob_zero_callback();
        case 0x80013820u:
            return (uint32)ob_init_view_geometry();
        case 0x80013908u:
            if (count < 3) ob_native_missing(target, 3u, count);
            ob_append_text_glyphs((uint32)args[0], (uint32)args[1], (uint32)args[2]);
            return 0u;
        case 0x80013C00u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)ob_append_three_digit_indicator((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80013FA4u:
            if (count < 1) ob_native_missing(target, 1u, count);
            sub_80013FA4(args[0]);
            return 0u;
        case 0x80014BF8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_append_player_hud((uint32)args[0]);
        case 0x8001578Cu:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)sub_8001578C((sint32)args[0], (sint32)args[1], (sint32)args[2], (sint32)args[3]);
        case 0x800159C8u:
            return (uint32)ob_update_player_heading_and_phase();
        case 0x80015FA8u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_80015FA8((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80016220u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80016220((sint32)args[0]);
        case 0x80016254u:
            return (uint32)sub_80016254();
        case 0x8001627Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8001627C((sint32)args[0]);
        case 0x80016390u:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)sub_80016390((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x80016598u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80016598((uint32)args[0]);
        case 0x80016768u:
            return (uint32)sub_80016768();
        case 0x800169D0u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_800169D0((uint32)args[0], (uint32)args[1]);
        case 0x80016A50u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80016A50((uint32)args[0]);
        case 0x80016B88u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80016B88((uint32)args[0]);
        case 0x80016C20u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_append_fade_quad((uint32)args[0]);
        case 0x80016FC4u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80016FC4((uint32)args[0]);
        case 0x800170B8u:
            ob_effect_stub_result();
            return 0u;
        case 0x800170C0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_draw_text_end((uint32)args[0]);
        case 0x800170C8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_draw_text_begin((uint32)args[0]);
        case 0x800170D0u:
            return (uint32)ob_reset_overlay_state();
        case 0x800170F8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800170F8((uint32)args[0]);
        case 0x80017178u:
            return (uint32)sub_80017178();
        case 0x800171ECu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_800171EC((sint32)args[0], (sint32)args[1]);
        case 0x80017328u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80017328((uint32)args[0], (sint32)args[1]);
        case 0x800174CCu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800174CC((uint32)args[0]);
        case 0x80017554u:
            return (uint32)sub_80017554();
        case 0x80018454u:
            return (uint32)sub_80018454();
        case 0x8001994Cu:
            return (uint32)sub_8001994C();
        case 0x80019EA0u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80019EA0((uint32)args[0], (uint32)args[1]);
        case 0x80019EE0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80019EE0((uint32)args[0]);
        case 0x8001A05Cu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_read_player_packet((uint32)args[0], (uint32)args[1]);
        case 0x8001A0CCu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_write_player_packet((uint32)args[0], (uint32)args[1]);
        case 0x8001A0F0u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)ob_append_player_packet((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8001A1CCu:
            return (uint32)sub_8001A1CC();
        case 0x8001A398u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_select_player_origin((uint32)args[0]);
        case 0x8001A4B0u:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)sub_8001A4B0((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x8001A6FCu:
            return (uint32)sub_8001A6FC();
        case 0x8001B008u:
            return (uint32)ob_random15();
        case 0x8001B048u:
            if (count < 1) ob_native_missing(target, 1u, count);
            ob_set_scene_callback(args[0]);
            return 0u;
        case 0x8001B058u:
            nullsub_18(); return 0u;
        case 0x8001CF58u:
            return (uint32)sub_8001CF58();
        case 0x8001D048u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8001D048((uint32)args[0]);
        case 0x8001D1B0u:
            return (uint32)ob_init_card_tables();
        case 0x8001DBCCu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8001DBCC((uint32)args[0]);
        case 0x8001DCF4u:
            return (uint32)sub_8001DCF4();
        case 0x8001DDA0u:
            return (uint32)sub_8001DDA0();
        case 0x8001DDF8u:
            return (uint32)sub_8001DDF8();
        case 0x8001DEB4u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8001DEB4((uint32)args[0]);
        case 0x8001DF34u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_set_audio_mode((uint32)args[0]);
        case 0x8001DF58u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8001DF58((uint32)args[0]);
        case 0x8001DFF0u:
            return (uint32)sub_8001DFF0();
        case 0x8001E050u:
            return (uint32)ob_enable_audio_processing();
        case 0x8001E108u:
            return (uint32)sub_8001E108();
        case 0x8001E1E0u:
            return (uint32)sub_8001E1E0();
        case 0x8001E298u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8001E298((uint32)args[0], (uint32)args[1]);
        case 0x8001E540u:
            return (uint32)sub_8001E540();
        case 0x8001E7B0u:
            if (count < 6) ob_native_missing(target, 6u, count);
            return (uint32)sub_8001E7B0((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5]);
        case 0x8001EBBCu:
            if (count < 6) ob_native_missing(target, 6u, count);
            return (uint32)sub_8001EBBC((sint32)args[0], (uint32)args[1], (sint32)args[2], (sint32)args[3], (sint32)args[4], (sint32)args[5]);
        case 0x8001F454u:
            if (count == 2) return ob_stop_voice_with_mask(args[0], args[1]);
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8001F454((uint32)args[0]);
        case 0x8001F56Cu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8001F56C((uint32)args[0], (sint32)args[1]);
        case 0x8001F5DCu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8001F5DC((uint32)args[0], (uint32)args[1]);
        case 0x8001F64Cu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8001F64C((uint32)args[0], (uint32)args[1]);
        case 0x8001F874u:
            return (uint32)sub_8001F874();
        case 0x8001F9B0u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8001F9B0((sint32)args[0], (sint32)args[1]);
        case 0x8001FC60u:
            return (uint32)sub_8001FC60();
        case 0x8001FDA4u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8001FDA4((uint32)args[0]);
        case 0x8001FE3Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return sub_8001FE3C(args[0]);
        case 0x8001FFC0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return sub_8001FFC0(args[0]);
        case 0x8001FEDCu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8001FEDC((uint32)args[0]);
        case 0x80020260u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_swap_bytes((uint32)args[0]);
        case 0x80020288u:
            return (uint32)ob_find_sound_slot();
        case 0x800202E8u:
            return (uint32)ob_find_voice_slot();
        case 0x80020450u:
            if (count < 8) ob_native_missing(target, 8u, count);
            return (uint32)ob_append_textured_glyph((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5], (uint32)args[6], (uint32)args[7]);
        case 0x80020864u:
            if (count < 11) ob_native_missing(target, 11u, count);
            return ob_append_colored_texture_quad(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10]);
        case 0x80020A70u:
            if (count < 8) ob_native_missing(target, 8u, count);
            return ob_append_solid_quad(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7]);
        case 0x80020D64u:
            if (count < 10) ob_native_missing(target, 10u, count);
            return ob_append_textured_vertices(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9]);
        case 0x80020FD4u:
            if (count < 10) ob_native_missing(target, 10u, count);
            return ob_append_textured_rectangle(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9]);
        case 0x8002140Cu:
            if (count < 13) ob_native_missing(target, 13u, count);
            return (uint32)ob_append_colored_texture_scaled((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5], (uint32)args[6], (uint32)args[7], (uint32)args[8], (uint32)args[9], (uint32)args[10], (uint32)args[11], (uint32)args[12]);
        case 0x80021460u:
            if (count < 8) ob_native_missing(target, 8u, count);
            return (uint32)sub_80021460((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5], (uint32)args[6], (uint32)args[7]);
        case 0x800215FCu:
            if (count < 11) ob_native_missing(target, 11u, count);
            return (uint32)sub_800215FC((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5], (uint32)args[6], (uint32)args[7], (uint32)args[8], (uint32)args[9], (uint32)args[10]);
        case 0x800217B4u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800217B4((sint32)args[0]);
        case 0x8002192Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_append_draw_mode((uint32)args[0]);
        case 0x80021A38u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80021A38((uint32)args[0]);
        case 0x80021AD8u:
            return (uint32)sub_80021AD8();
        case 0x80021B20u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80021B20((uint32)args[0]);
        case 0x80021C24u:
            return (uint32)sub_80021C24();
        case 0x80021C74u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_build_weight_tree((uint32)args[0]);
        case 0x80021D80u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_unpack_weight_image((uint32)args[0]);
        case 0x80021DE8u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_decode_weight_tree((uint32)args[0], (uint32)args[1]);
        case 0x80021EFCu:
            return (uint32)sub_80021EFC();
        case 0x80021FF4u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80021FF4((uint32)args[0]);
        case 0x80022058u:
            return (uint32)sub_80022058();
        case 0x800220BCu:
            return (uint32)sub_800220BC();
        case 0x80022234u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80022234((sint32)args[0]);
        case 0x800222FCu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800222FC((uint32)args[0]);
        case 0x800223A0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800223A0((uint32)args[0]);
        case 0x80022440u:
            return (uint32)sub_80022440();
        case 0x800224A0u:
            return (uint32)sub_800224A0();
        case 0x800226D0u:
            return (uint32)sub_800226D0();
        case 0x80022AD4u:
            if (count < 7) ob_native_missing(target, 7u, count);
            sub_80022AD4((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5], (uint32)args[6]); return 0u;
        case 0x80022C1Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80022C1C((uint32)args[0]);
        case 0x80022CD4u:
            sub_80022CD4(); return 0u;
        case 0x80022E78u:
            return (uint32)sub_80022E78();
        case 0x80023138u:
            return (uint32)sub_80023138();
        case 0x800231E4u:
            return (uint32)sub_800231E4();
        case 0x8002328Cu:
            return (uint32)sub_8002328C();
        case 0x80023308u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80023308((uint32)args[0]);
        case 0x80023A10u:
            return (uint32)sub_80023A10();
        case 0x80023AA8u:
            return (uint32)sub_80023AA8();
        case 0x80023B28u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80023B28((uint32)args[0], (sint32)args[1]);
        case 0x80023C08u:
            return (uint32)sub_80023C08();
        case 0x80023E30u:
            return (uint32)sub_80023E30();
        case 0x80023E70u:
            return (uint32)sub_80023E70();
        case 0x80024310u:
            ob_effect_setup_stub_result();
            return 0u;
        case 0x80024320u:
            return (uint32)sub_80024320();
        case 0x8002439Cu:
            return (uint32)sub_8002439C();
        case 0x80024400u:
            return (uint32)sub_80024400();
        case 0x80024548u:
            return (uint32)sub_80024548();
        case 0x80024640u:
            return (uint32)sub_80024640();
        case 0x80024938u:
            return (uint32)sub_80024938();
        case 0x80024B40u:
            return (uint32)sub_80024B40();
        case 0x80024D24u:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)ob_fill_words((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x80024D54u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80024D54((uint32)args[0]);
        case 0x80024EA8u:
            return (uint32)sub_80024EA8();
        case 0x80024F18u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_set_update_callback((uint32)args[0], (uint32)args[1]);
        case 0x80024F24u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80024F24((uint32)args[0]);
        case 0x8002512Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8002512C((uint32)args[0]);
        case 0x800251E8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800251E8((uint32)args[0]);
        case 0x800255F0u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_memory_set_word_for_payload((uint32)args[0], (uint32)args[1]);
        case 0x80025624u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_set_callback_for_payload((uint32)args[0], (uint32)args[1]);
        case 0x80025658u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_memory_set_tail_for_payload((uint32)args[0], (uint32)args[1]);
        case 0x800256CCu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800256CC((uint32)args[0]);
        case 0x80025700u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80025700((uint32)args[0]);
        case 0x800257A0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_release_reference((uint32)args[0]);
        case 0x800257CCu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800257CC((uint32)args[0]);
        case 0x80025874u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_handle_slot_address((uint32)args[0]);
        case 0x800259ACu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800259AC((uint32)args[0]);
        case 0x80025A9Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80025A9C(args[0]);
        case 0x80025ABCu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80025ABC((uint32)args[0]);
        case 0x80025CB4u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80025CB4((uint32)args[0], (sint32)args[1]);
        case 0x80025D50u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_copy_string((uint32)args[0], (uint32)args[1]);
        case 0x80025D6Cu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_string_equal_code((uint32)args[0], (uint32)args[1]);
        case 0x80025DA0u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80025DA0((uint32)args[0], (uint32)args[1]);
        case 0x800260C8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_query_statistics((uint32)args[0]);
        case 0x800260F8u:
            return (uint32)sub_800260F8();
        case 0x80026164u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_80026164((uint32)args[0], (uint32)args[1], (sint32)args[2]);
        case 0x80026278u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_unbind_pool_head((uint32)args[0]);
        case 0x800262CCu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_800262CC((uint32)args[0], (sint32)args[1]);
        case 0x800263B4u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_release_pool_cell((uint32)args[0]);
        case 0x80026418u:
            return (uint32)sub_80026418();
        case 0x80026444u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_swap_pool_heads((uint32)args[0], (uint32)args[1]);
        case 0x80026460u:
            return (uint32)ob_memory_init_groups();
        case 0x80026694u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_80026694((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80026734u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80026734((uint32)args[0], (uint32)args[1]);
        case 0x80026758u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80026758((uint32)args[0]);
        case 0x8002679Cu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_memory_lock_handle((uint32)args[0], (uint32)args[1]);
        case 0x800267C4u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_memory_unlock_handle((uint32)args[0], (uint32)args[1]);
        case 0x80026898u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80026898((uint32)args[0], (uint32)args[1]);
        case 0x800268D0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_payload_size((uint32)args[0]);
        case 0x800268E8u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_800268E8((uint32)args[0], (uint32)args[1]);
        case 0x8002691Cu:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)ob_memory_insert_physical((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80026950u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_merge_next((uint32)args[0]);
        case 0x80026984u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)ob_memory_bind_handle((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x800269D0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800269D0((uint32)args[0]);
        case 0x80026D30u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80026D30((uint32)args[0], (uint32)args[1]);
        case 0x80026EB8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80026EB8((sint32)args[0]);
        case 0x80026F48u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80026F48((uint32)args[0]);
        case 0x80027154u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_coalesce_free((uint32)args[0]);
        case 0x800271ECu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_800271EC((uint32)args[0], (uint32)args[1]);
        case 0x80027274u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80027274((uint32)args[0], (sint32)args[1]);
        case 0x8002744Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8002744C((uint32)args[0]);
        case 0x800276B4u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800276B4((uint32)args[0]);
        case 0x80027710u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80027710((uint32)args[0]);
        case 0x800277D0u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_memory_lock_block((uint32)args[0], (uint32)args[1]);
        case 0x80027810u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_memory_unlock_block((uint32)args[0], (uint32)args[1]);
        case 0x8002785Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_unlink_free((uint32)args[0]);
        case 0x800278ACu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_insert_free((uint32)args[0]);
        case 0x80027978u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_unlink_used((uint32)args[0]);
        case 0x800279A4u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_link_used((uint32)args[0]);
        case 0x800279D4u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800279D4((uint32)args[0]);
        case 0x80027A3Cu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_memory_set_slot_word((uint32)args[0], (uint32)args[1]);
        case 0x80027A74u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_memory_set_slot_callback((uint32)args[0], (uint32)args[1]);
        case 0x80027AACu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_memory_set_slot_tail((uint32)args[0], (uint32)args[1]);
        case 0x80027AE4u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_valid_slot_address((uint32)args[0]);
        case 0x80027CD0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80027CD0((uint32)args[0]);
        case 0x80027D78u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_find_identifier((uint32)args[0]);
        case 0x80027DF8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_memory_slot_address((uint32)args[0]);
        case 0x80027E54u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80027E54((uint32)args[0], (uint32)args[1]);
        case 0x80027E90u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80027E90(args[0]);
        case 0x80027ED8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80027ED8((uint32)args[0]);
        case 0x80027F54u:
            return (uint32)sub_80027F54();
        case 0x80027F98u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80027F98((uint32)args[0], (uint32)args[1]);
        case 0x80028280u:
            if (count < 4) ob_native_missing(target, 4u, count);
            sub_80028280((sint32)args[0], (sint32)args[1], (uint32)args[2], (uint32)args[3]); return 0u;
        case 0x800283C0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_unsigned_bit_length((uint32)args[0]);
        case 0x800283DCu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_800283DC((uint32)args[0], (sint32)args[1]);
        case 0x80028614u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80028614((uint32)args[0]);
        case 0x80029290u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return sub_80029290(args[0], args[1]);
        case 0x800292B0u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_800292B0((uint32)args[0], (uint32)args[1]);
        case 0x800292ECu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_800292EC((uint32)args[0], (uint32)args[1]);
        case 0x80029B70u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_80029B70((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80029E30u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_copy_vector_words((uint32)args[0], (uint32)args[1]);
        case 0x80029E54u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_identity_matrix14((uint32)args[0]);
        case 0x80029E80u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_angle_matrix14((uint32)args[0], (uint32)args[1]);
        case 0x80029EECu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80029EEC((uint32)args[0], (uint32)args[1]);
        case 0x80029F58u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_y_angle_matrix14((uint32)args[0], (uint32)args[1]);
        case 0x8002A870u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)ob_rotate_matrix_x14((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8002A9DCu:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_8002A9DC((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8002AB48u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)ob_rotate_matrix_z14((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8002ADFCu:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)ob_rotate_matrix_y14((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8002AF54u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)ob_rotate_matrix_rows14((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8002B15Cu:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_8002B15C((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8002B7FCu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_copy_matrix_halfwords((uint32)args[0], (uint32)args[1]);
        case 0x8002B868u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8002B868((uint32)args[0]);
        case 0x8002C4ACu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_classify_clip_planes((uint32)args[0], (uint32)args[1]);
        case 0x8002C728u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8002C728((uint32)args[0]);
        case 0x8002C77Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8002C77C((uint32)args[0]);
        case 0x8002CA3Cu:
            return (uint32)sub_8002CA3C();
        case 0x8002CCC8u:
            if (count < 7) ob_native_missing(target, 7u, count);
            return (uint32)ob_clip_viewport((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5], (uint32)args[6]);
        case 0x8002CEB0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8002CEB0((uint32)args[0]);
        case 0x8002CFA8u:
            return (uint32)ob_switch_frame_buffer();
        case 0x8002CFE4u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_set_frame_callback((uint32)args[0], (uint32)args[1]);
        case 0x8002CFF4u:
            return (uint32)sub_8002CFF4();
        case 0x8002D078u:
            if (count < 5) ob_native_missing(target, 5u, count);
            return (uint32)sub_8002D078((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4]);
        case 0x8002D25Cu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8002D25C((uint32)args[0], (sint32)args[1]);
        case 0x8002D8A8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8002D8A8((uint32)args[0]);
        case 0x8002D98Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8002D98C((uint32)args[0]);
        case 0x8002DA68u:
            if (count < 1) ob_native_missing(target, 1u, count);
            ob_restore_heap_pointer((uint32)args[0]);
            return 0u;
        case 0x8002DB08u:
            return (uint32)ob_snapshot_geometry_state();
        case 0x8002DB3Cu:
            return (uint32)ob_snapshot_geometry_context();
        case 0x8002DB6Cu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_align_value((uint32)args[0], (uint32)args[1]);
        case 0x8002DC10u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_reset_geometry_record((uint32)args[0]);
        case 0x8002E8D8u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)ob_rotate_short_pair((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8002F284u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8002F284((uint32)args[0], (uint32)args[1]);
        case 0x8002F310u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8002F310((uint32)args[0], (uint32)args[1]);
        case 0x8002F4CCu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8002F4CC((uint32)args[0]);
        case 0x8002F560u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_transpose_matrix((uint32)args[0]);
        case 0x8002F9C4u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8002F9C4((uint32)args[0], (uint32)args[1]);
        case 0x8002FAA8u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_set_geometry_translation((uint32)args[0], (uint32)args[1]);
        case 0x8002FE50u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_8002FE50((sint32)args[0], (uint32)args[1], (sint32)args[2]);
        case 0x8002FED4u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_8002FED4((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x800303D4u:
            if (count < 2) ob_native_missing(target, 2u, count);
            sub_800303D4((uint32)args[0], (uint32)args[1]); return 0u;
        case 0x8003042Cu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8003042C((uint32)args[0], (uint32)args[1]);
        case 0x80030700u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_80030700((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8003077Cu:
            if (count < 6) ob_native_missing(target, 6u, count);
            return (uint32)sub_8003077C((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5]);
        case 0x80030924u:
            return (uint32)ob_init_geometry_record();
        case 0x80031FECu:
            return (uint32)sub_80031FEC();
        case 0x800328ECu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800328EC((uint32)args[0]);
        case 0x80033528u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80033528((uint32)args[0]);
        case 0x80033F48u:
            return (uint32)ob_init_object_callbacks();
        case 0x80033F90u:
            sub_80033F90(); return 0u;
        case 0x80033FB0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80033FB0((uint32)args[0]);
        case 0x800340A0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800340A0((uint32)args[0]);
        case 0x80034114u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80034114((uint32)args[0], (uint32)args[1]);
        case 0x80034234u:
            sub_80034234();
            return 0u;
        case 0x800342F0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800342F0((uint32)args[0]);
        case 0x80034430u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80034430((uint32)args[0]);
        case 0x80034530u:
            ob_stamp_object_records();
            return 0u;
        case 0x80034768u:
            if (count < 8) ob_native_missing(target, 8u, count);
            return (uint32)sub_80034768((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5], (uint32)args[6], (uint32)args[7]);
        case 0x80034910u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80034910((uint32)args[0]);
        case 0x800349D8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800349D8((uint32)args[0]);
        case 0x80034E10u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80034E10((uint32)args[0]);
        case 0x80035178u:
            return (uint32)ob_init_geometry_callbacks();
        case 0x80035220u:
            return (uint32)ob_reset_geometry_workspace();
        case 0x80035270u:
            return (uint32)ob_update_geometry_dimensions();
        case 0x800352B4u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800352B4((uint32)args[0]);
        case 0x800354C8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800354C8((uint32)args[0]);
        case 0x80035618u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_relocate_geometry((uint32)args[0], (uint32)args[1]);
        case 0x800357DCu:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)ob_reserve_vertex_span((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8003584Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8003584C((uint32)args[0]);
        case 0x8003858Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            sub_8003858C((uint32)args[0]); return 0u;
        case 0x80039100u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80039100((uint32)args[0]);
        case 0x80039808u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80039808((sint32)args[0], (sint32)args[1]);
        case 0x80039838u:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)sub_80039838((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x80039BD8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_build_geometry_order((uint32)args[0]);
        case 0x80039C30u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_collect_geometry_callbacks((uint32)args[0], (uint32)args[1]);
        case 0x80039E68u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_collect_geometry_indices((uint32)args[0], (uint32)args[1]);
        case 0x8003A430u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_classify_object_sphere((uint32)args[0], (uint32)args[1]);
        case 0x8003AA8Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8003AA8C((uint32)args[0]);
        case 0x800409E0u:
            return (uint32)sub_800409E0();
        case 0x80040BF0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            sub_80040BF0((uint32)args[0]); return 0u;
        case 0x800415E4u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800415E4((uint32)args[0]);
        case 0x80041B74u:
            return (uint32)ob_init_geometry_workspace();
        case 0x80041BB8u:
            return (uint32)sub_80041BB8();
        case 0x80041D7Cu:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_80041D7C((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80042368u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_insert_depth_node((uint32)args[0]);
        case 0x800423D8u:
            return (uint32)sub_800423D8();
        case 0x80042424u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80042424((uint32)args[0]);
        case 0x800425ECu:
            if (count < 7) ob_native_missing(target, 7u, count);
            return (uint32)sub_800425EC((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5], (uint32)args[6]);
        case 0x80042644u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80042644((uint32)args[0]);
        case 0x800427ACu:
            return (uint32)sub_800427AC();
        case 0x80042928u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80042928((uint32)args[0], (uint32)args[1]);
        case 0x80042B54u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_80042B54((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80043120u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80043120((uint32)args[0]);
        case 0x80043404u:
            return (uint32)sub_80043404();
        case 0x800435ACu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_800435AC((uint32)args[0], (uint32)args[1]);
        case 0x80043600u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_80043600((uint32)args[0], (sint32)args[1], (sint32)args[2]);
        case 0x80043664u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_unlink_object_record((uint32)args[0]);
        case 0x800436ACu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return ob_free_object_record(args[0]);
        case 0x800436D4u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_link_object((uint32)args[0], (uint32)args[1]);
        case 0x800436ECu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_detach_owned_record((uint32)args[0], (uint32)args[1]);
        case 0x8004378Cu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_find_first_typed_child((uint32)args[0], (uint32)args[1]);
        case 0x800437C4u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_800437C4((uint32)args[0], (sint32)args[1]);
        case 0x80043824u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)ob_find_typed_object((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8004389Cu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_find_object_identifier((uint32)args[0], (uint32)args[1]);
        case 0x8004395Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_init_object_list((uint32)args[0]);
        case 0x80043974u:
            if (count < 1) ob_native_missing(target, 1u, count);
            ob_clear_owner_references((uint32)args[0]);
            return 0u;
        case 0x800439BCu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_insert_ordered_object((uint32)args[0], (uint32)args[1]);
        case 0x80043AB0u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return ob_remove_ordered_object(args[0], args[1]);
        case 0x80043AF4u:
            if (count < 1) ob_native_missing(target, 1u, count);
            ob_clear_reference_list((uint32)args[0]);
            return 0u;
        case 0x80043B68u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80043B68((uint32)args[0]);
        case 0x80043BACu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_init_reference_record((uint32)args[0], (uint32)args[1]);
        case 0x80043C18u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_reset_reference_record((uint32)args[0]);
        case 0x80043C6Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_free_reference_record((uint32)args[0]);
        case 0x80043C94u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_unlink_reference_node((uint32)args[0]);
        case 0x80043CD4u:
            nullsub_25(); return 0u;
        case 0x80043CDCu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_init_base_record((uint32)args[0], (uint32)args[1]);
        case 0x80043CF0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_clear_object_record((uint32)args[0]);
        case 0x80043D20u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_attach_link_record((uint32)args[0], (uint32)args[1]);
        case 0x80043D38u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_detach_link_record((uint32)args[0], (uint32)args[1]);
        case 0x80043D78u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_clear_dependent_chain((uint32)args[0]);
        case 0x80043DACu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_init_optional_link((uint32)args[0]);
        case 0x80043DBCu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_clear_optional_link((uint32)args[0]);
        case 0x80043DECu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_attach_optional_link((uint32)args[0], (uint32)args[1]);
        case 0x80043E14u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_detach_optional_link_record((uint32)args[0]);
        case 0x80043E3Cu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80043E3C((uint32)args[0], (uint32)args[1]);
        case 0x80043EACu:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_80043EAC((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80043FD0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return ob_destroy_geometry_object(args[0]);
        case 0x80044058u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return ob_free_geometry_object(args[0]);
        case 0x800440E8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_detach_geometry_child((uint32)args[0]);
        case 0x800440B8u:
            if (count < 2) ob_native_missing(target, 2u, count);
            sub_800440B8(args[0], args[1]);
            return 0u;
        case 0x80044130u:
            if (count < 1) ob_native_missing(target, 1u, count);
            ob_resolve_shape_links((uint32)args[0]);
            return 0u;
        case 0x800441ACu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_next_shape((uint32)args[0], (uint32)args[1]);
        case 0x800442F0u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_800442F0((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8004434Cu:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_8004434C((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80044474u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_80044474((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x800444F4u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_800444F4((uint32)args[0], (uint32)args[1]);
        case 0x80044C58u:
            return (uint32)ob_init_audio_callback();
        case 0x80044C90u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80044C90((uint32)args[0]);
        case 0x80044CD4u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80044CD4((uint32)args[0]);
        case 0x80044D50u:
            return (uint32)ob_init_scene_geometry();
        case 0x80044DBCu:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)sub_80044DBC((uint32)args[0], (uint32)args[1], (uint32)args[2], (sint32)args[3]);
        case 0x80044E5Cu:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_80044E5C((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80044EDCu:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)sub_80044EDC((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x80045094u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80045094((uint32)args[0]);
        case 0x80045124u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80045124((uint32)args[0]);
        case 0x8004514Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_detach_owner_child((uint32)args[0]);
        case 0x800451E4u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_insert_artic_reference((uint32)args[0], (uint32)args[1]);
        case 0x80045204u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80045204((uint32)args[0]);
        case 0x80045284u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80045284((sint32)args[0], (sint32)args[1]);
        case 0x80045378u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_80045378((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x800453C4u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)ob_copy_advanced_position((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80045430u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80045430((sint32)args[0]);
        case 0x80045464u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80045464((uint32)args[0], (uint32)args[1]);
        case 0x80045490u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80045490((uint32)args[0], (uint32)args[1]);
        case 0x800454BCu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800454BC((uint32)args[0]);
        case 0x800455DCu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_800455DC((uint32)args[0], (uint32)args[1]);
        case 0x80045758u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)ob_advance_object((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80045848u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80045848((uint32)args[0], (uint32)args[1]);
        case 0x800458B4u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_800458B4((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80045A44u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80045A44((uint32)args[0], (uint32)args[1]);
        case 0x80045A7Cu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_set_object_time((uint32)args[0], (uint32)args[1]);
        case 0x80045ADCu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80045ADC((uint32)args[0]);
        case 0x80045B74u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_invalidate_object_matrix((uint32)args[0]);
        case 0x80045C30u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_invalidate_object_position((uint32)args[0]);
        case 0x80045C98u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_clear_object_flags((uint32)args[0], (uint32)args[1]);
        case 0x80045D44u:
            return (uint32)ob_init_effect_object_list();
        case 0x80045D70u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80045D70((uint32)args[0]);
        case 0x80045EF4u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_register_effect_object((uint32)args[0]);
        case 0x80045F20u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return ob_unregister_effect_object(args[0]);
        case 0x80045F4Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80045F4C((uint32)args[0]);
        case 0x800460B0u:
            return (uint32)ob_find_collision_slot();
        case 0x80046124u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80046124((uint32)args[0]);
        case 0x80046184u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_80046184((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x800461E8u:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)sub_800461E8((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x800464BCu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800464BC((uint32)args[0]);
        case 0x8004651Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004651C((uint32)args[0]);
        case 0x80046544u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80046544((uint32)args[0]);
        case 0x800465E8u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_800465E8((uint32)args[0], (uint32)args[1]);
        case 0x8004670Cu:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_8004670C((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80046914u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80046914((sint32)args[0], (sint32)args[1]);
        case 0x80046954u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80046954((uint32)args[0], (uint32)args[1]);
        case 0x80046AF8u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80046AF8((uint32)args[0], (uint32)args[1]);
        case 0x80046BE8u:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)sub_80046BE8((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x80046CACu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80046CAC((uint32)args[0]);
        case 0x80046CDCu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80046CDC((uint32)args[0]);
        case 0x80046D98u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80046D98((uint32)args[0]);
        case 0x80046E6Cu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80046E6C((uint32)args[0], (uint32)args[1]);
        case 0x80046EACu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80046EAC((uint32)args[0], (uint32)args[1]);
        case 0x80047050u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80047050((uint32)args[0], (uint32)args[1]);
        case 0x80047140u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80047140((uint32)args[0], (uint32)args[1]);
        case 0x8004719Cu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004719C((uint32)args[0], (sint32)args[1]);
        case 0x8004735Cu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004735C((uint32)args[0], (uint32)args[1]);
        case 0x80047450u:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)sub_80047450((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x800477B8u:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)sub_800477B8((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x8004795Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004795C((uint32)args[0]);
        case 0x800479E0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_select_earliest_flagged_contact((uint32)args[0]);
        case 0x80047A60u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return ob_update_object_collision_time(args[0]);
        case 0x80047B24u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80047B24((uint32)args[0]);
        case 0x80047B54u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_80047B54((uint32)args[0], (sint32)args[1], (sint32)args[2]);
        case 0x80047E2Cu:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)sub_80047E2C((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x80047F60u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80047F60((uint32)args[0]);
        case 0x80047FF0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80047FF0((uint32)args[0]);
        case 0x80048020u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80048020((uint32)args[0]);
        case 0x800480A8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800480A8((uint32)args[0]);
        case 0x80048124u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80048124((uint32)args[0]);
        case 0x800486E4u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800486E4((uint32)args[0]);
        case 0x800487B8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800487B8((uint32)args[0]);
        case 0x80048978u:
            if (count < 5) ob_native_missing(target, 5u, count);
            return ob_world_store_pair((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4]);
        case 0x80048994u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80048994((uint32)args[0]);
        case 0x80048B60u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_collision_normalize_axes((uint32)args[0]);
        case 0x80048BF4u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80048BF4((uint32)args[0]);
        case 0x80048D2Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80048D2C((uint32)args[0]);
        case 0x80048FECu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return ob_world_axis_entry_time((uint32)args[0]);
        case 0x800491B0u:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)sub_800491B0((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x800493F8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800493F8((uint32)args[0]);
        case 0x8004954Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004954C((uint32)args[0]);
        case 0x800496D8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800496D8((uint32)args[0]);
        case 0x80049A10u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80049A10((uint32)args[0]);
        case 0x80049ED4u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_80049ED4((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8004A048u:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)sub_8004A048((uint32)args[0], (uint32)args[1], (sint32)args[2], (sint32)args[3]);
        case 0x8004A1C0u:
            return (uint32)sub_8004A1C0();
        case 0x8004A2ECu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004A2EC((uint32)args[0]);
        case 0x8004A410u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004A410((uint32)args[0]);
        case 0x8004A48Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            sub_8004A48C((uint32)args[0]); return 0u;
        case 0x8004A564u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_classify_matrix_direction((uint32)args[0]);
        case 0x8004A5C4u:
            sub_8004A5C4(); return 0u;
        case 0x8004A908u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004A908((uint32)args[0]);
        case 0x8004AAFCu:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004AAFC((uint32)args[0], (uint32)args[1]);
        case 0x8004B0B0u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)ob_border_cell_blocked((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8004B3C4u:
            return (uint32)ob_clear_effect_workspace();
        case 0x8004B3E8u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_border_subcell_to_tile((uint32)args[0], (uint32)args[1]);
        case 0x8004B450u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004B450((uint32)args[0], (uint32)args[1]);
        case 0x8004B514u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return ob_border_cell_address(args[0], args[1]);
        case 0x8004B634u:
            return (uint32)sub_8004B634();
        case 0x8004B6ACu:
            return (uint32)ob_init_effect_callbacks();
        case 0x8004B70Cu:
            return (uint32)ob_refresh_effect_records();
        case 0x8004B7A0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004B7A0((uint32)args[0]);
        case 0x8004B9B0u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_relocate_effect_tables((uint32)args[0], (uint32)args[1]);
        case 0x8004BA60u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_classify_effect_tables((uint32)args[0]);
        case 0x8004BA98u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_classify_effect_block((uint32)args[0]);
        case 0x8004BB48u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_classify_effect_index((uint32)args[0], (uint32)args[1]);
        case 0x8004BBE4u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)ob_classify_effect_cell((uint32)args[0], (uint32)args[1]);
        case 0x8004BC2Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_classify_effect_blocks((uint32)args[0]);
        case 0x8004BC88u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_classify_effect_indices((uint32)args[0]);
        case 0x8004BCF8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_classify_effect_cells((uint32)args[0]);
        case 0x8004BF54u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004BF54((uint32)args[0], (uint32)args[1]);
        case 0x8004C2C4u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_8004C2C4((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8004C4D4u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)ob_copy_spatial_heights((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8004C64Cu:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)sub_8004C64C((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x8004C944u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004C944((uint32)args[0]);
        case 0x8004CD2Cu:
            return (uint32)sub_8004CD2C();
        case 0x8004CDF4u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004CDF4((uint32)args[0], (uint32)args[1]);
        case 0x8004CE64u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004CE64((uint32)args[0], (uint32)args[1]);
        case 0x8004CF28u:
            if (count < 5) ob_native_missing(target, 5u, count);
            return (uint32)ob_build_three_axis_codes((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4]);
        case 0x8004D0F8u:
            return (uint32)ob_build_view_axis_codes();
        case 0x8004D634u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004D634((uint32)args[0]);
        case 0x8004D76Cu:
            if (count < 6) ob_native_missing(target, 6u, count);
            return (uint32)sub_8004D76C((uint32)args[0], (uint32)args[1], (uint32)args[2], (sint32)args[3], (sint32)args[4], (sint32)args[5]);
        case 0x8004D910u:
            if (count < 6) ob_native_missing(target, 6u, count);
            return (uint32)sub_8004D910((uint32)args[0], (uint32)args[1], (uint32)args[2], (sint32)args[3], (sint32)args[4], (sint32)args[5]);
        case 0x8004DAA4u:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)sub_8004DAA4((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x8004DB40u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_8004DB40((uint32)args[0], (sint32)args[1], (uint32)args[2]);
        case 0x8004DFB8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004DFB8((sint32)args[0]);
        case 0x8004E028u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_8004E028((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8004E310u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004E310((uint32)args[0], (sint32)args[1]);
        case 0x8004E3B0u:
            return (uint32)sub_8004E3B0();
        case 0x8004E518u:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)sub_8004E518((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x8004E584u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_8004E584((uint32)args[0], (sint32)args[1], (uint32)args[2]);
        case 0x8004E614u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004E614((uint32)args[0]);
        case 0x8004E644u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004E644((uint32)args[0]);
        case 0x8004E70Cu:
            return (uint32)ob_init_sea_texture_packet();
        case 0x8004E814u:
            return (uint32)sub_8004E814();
        case 0x8004E9E4u:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)sub_8004E9E4((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x8004EC6Cu:
            if (count < 5) ob_native_missing(target, 5u, count);
            return ob_append_sea_quad((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (sint32)args[4]);
        case 0x8004EEF4u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004EEF4((uint32)args[0], (uint32)args[1]);
        case 0x8004F004u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004F004((sint32)args[0], (uint32)args[1]);
        case 0x8004F064u:
            ob_scene_stub_result();
            return 0u;
        case 0x8004F074u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_8004F074((sint32)args[0], (sint32)args[1], (sint32)args[2]);
        case 0x8004F0D8u:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)sub_8004F0D8((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x8004F288u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004F288((uint32)args[0]);
        case 0x8004F2C4u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004F2C4((uint32)args[0], (sint32)args[1]);
        case 0x8004F31Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8004F31C((uint32)args[0]);
        case 0x8004F354u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return ob_update_ground_collision_time(args[0]);
        case 0x8004F418u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_8004F418((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8004F478u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_8004F478((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8004F51Cu:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_8004F51C((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8004F610u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004F610((uint32)args[0], (uint32)args[1]);
        case 0x8004F758u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_8004F758((uint32)args[0], (uint32)args[1]);
        case 0x8004FA0Cu:
            if (count < 6) ob_native_missing(target, 6u, count);
            return (uint32)sub_8004FA0C((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (sint32)args[4], (sint32)args[5]);
        case 0x8004FC64u:
            if (count < 7) ob_native_missing(target, 7u, count);
            return (uint32)sub_8004FC64((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5], (uint32)args[6]);
        case 0x80050088u:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)sub_80050088((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x800502ACu:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_800502AC((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80050380u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80050380((uint32)args[0]);
        case 0x80050550u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80050550((uint32)args[0]);
        case 0x80050644u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80050644((uint32)args[0]);
        case 0x80050870u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_select_spatial_event((uint32)args[0]);
        case 0x800508D0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_800508D0((uint32)args[0]);
        case 0x80050A2Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80050A2C((uint32)args[0]);
        case 0x80050B88u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80050B88((uint32)args[0], (uint32)args[1]);
        case 0x80051400u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80051400((uint32)args[0], (uint32)args[1]);
        case 0x80051450u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80051450((uint32)args[0], (uint32)args[1]);
        case 0x800514E4u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)ob_locate_spatial_cell((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x8005160Cu:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)ob_step_spatial_cell((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x80051974u:
            return (uint32)sub_80051974();
        case 0x80052A68u:
            return (uint32)sub_80052A68();
        case 0x80053D20u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80053D20((sint32)args[0], (sint32)args[1]);
        case 0x80053E2Cu:
            return (uint32)ob_update_controller_flags();
        case 0x800540F8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_controller_slot_ready((uint32)args[0]);
        case 0x80054264u:
            return (uint32)sub_80054264();
        case 0x80054320u:
            return (uint32)ob_snapshot_controller_flags();
        case 0x80054440u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_consume_button_edge((uint32)args[0]);
        case 0x800544ECu:
            return (uint32)ob_clear_button_edges();
        case 0x80054780u:
            return (uint32)sub_80054780();
        case 0x8005491Cu:
            return (uint32)sub_8005491C();
        case 0x80054A24u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80054A24((sint32)args[0], (uint32)args[1]);
        case 0x80054AE0u:
            return (uint32)ob_file_finish_request();
        case 0x80054B30u:
            return (uint32)sub_80054B30();
        case 0x80054C14u:
            return (uint32)sub_80054C14();
        case 0x80054CA8u:
            ob_reset_file_setup();
            return 0u;
        case 0x80054CD8u:
            return (uint32)sub_80054CD8();
        case 0x80054CECu:
            sub_80054CEC(); return 0u;
        case 0x80054CFCu:
            return (uint32)ob_file_reset_tables();
        case 0x80054D50u:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)ob_bcd_fields_to_frame((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x80054E08u:
            if (count < 4) ob_native_missing(target, 4u, count);
            return (uint32)sub_80054E08((sint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        case 0x80054EFCu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_80054EFC((uint32)args[0]);
        case 0x800551B0u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_file_close_slot((uint32)args[0]);
        case 0x800551F8u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)ob_file_seek((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x800552D4u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_800552D4((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x800553D0u:
            if (count < 3) ob_native_missing(target, 3u, count);
            return (uint32)sub_800553D0((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        case 0x800556D8u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_file_entry_size((uint32)args[0]);
        case 0x800556F4u:
            return (uint32)sub_800556F4();
        case 0x8005577Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)sub_8005577C((uint32)args[0]);
        case 0x80055808u:
            return (uint32)sub_80055808();
        case 0x800558E4u:
            sub_800558E4(); return 0u;
        case 0x800558F4u:
            sub_800558F4(); return 0u;
        case 0x80055954u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_80055954((uint32)args[0], (uint32)args[1]);
        case 0x80056580u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_bcd_to_frame((uint32)args[0]);
        case 0x80058D98u:
            sub_80058D98(); return 0u;
        case 0x80058FC0u:
            return (uint32)ob_stream_stub_result();
        case 0x80059128u:
            if (count < 3) ob_native_missing(target, 3u, count);
            sub_80059128((sint32)args[0], (sint32)args[1], (sint32)args[2]); return 0u;
        case 0x8005A9DCu:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_set_render_mode((uint32)args[0]);
        case 0x8005A9F4u:
            return (uint32)ob_get_render_mode();
        case 0x8005F468u:
            if (count < 2) ob_native_missing(target, 2u, count);
            sub_8005F468((uint32)args[0], (uint32)args[1]); return 0u;
        case 0x8005F488u:
            if (count < 1) ob_native_missing(target, 1u, count);
            sub_8005F488((uint32)args[0]); return 0u;
        case 0x8005F998u:
            sub_8005F998(); return 0u;
        case 0x800602D0u:
            return (uint32)sub_800602D0();
        case 0x80061034u:
            sub_80061034(); return 0u;
        case 0x800629C4u:
            if (count < 2) ob_native_missing(target, 2u, count);
            return (uint32)sub_800629C4((uint32)args[0], (uint32)args[1]);
        case 0x80063C1Cu:
            if (count < 1) ob_native_missing(target, 1u, count);
            sub_80063C1C((sint32)args[0]); return 0u;
        case 0x80063C70u:
            sub_80063C70(); return 0u;
        case 0x80063CD8u:
            sub_80063CD8(); return 0u;
        case 0x80063CE8u:
            sub_80063CE8(); return 0u;
        case 0x80064900u:
            if (count < 1) ob_native_missing(target, 1u, count);
            return (uint32)ob_exchange_callback_state((uint32)args[0]);
    case 0x8001FFB8:
        ob_main_8001FFB8(); return 0;
    case 0x80024318:
        ob_main_80024318(); return 0;
    case 0x800279CC:
        ob_main_800279CC(); return 0;
    case 0x8003979C:
        ob_main_8003979C(); return 0;
    case 0x800397A4:
        ob_main_800397A4(); return 0;
    case 0x8004F06C:
        ob_main_8004F06C(); return 0;
    case 0x8002FA88:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8002FA88(args[0], args[1]);
    case 0x800346CC:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_800346CC(args[0]);
    case 0x8001CE24:
        return ob_main_8001CE24();
    case 0x80033F24:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_80033F24(args[0], args[1]);
    case 0x800355F4:
        ob_main_800355F4(); return 0;
    case 0x8004A2C4:
        return ob_main_8004A2C4();
    case 0x8004B98C:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8004B98C(args[0], args[1]);
    case 0x800121A4:
        return ob_main_800121A4();
    case 0x80026710:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_80026710(args[0], args[1]);
    case 0x8001CF2C:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_8001CF2C(args[0]);
    case 0x80024B70:
        return ob_main_80024B70();
    case 0x8002D940:
        return ob_main_8002D940();
    case 0x8001CDE4:
        return ob_main_8001CDE4();
    case 0x800320F8:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_800320F8(args[0], args[1]);
    case 0x80032148:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80032148(args[0]);
    case 0x800346EC:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_800346EC(args[0]);
    case 0x80034724:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80034724(args[0]);
    case 0x80015F24:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80015F24(args[0]);
    case 0x8001DE60:
        return ob_main_8001DE60();
    case 0x8002F3D8:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_8002F3D8(args[0]);
    case 0x8002D888:
        return ob_main_8002D888();
    case 0x80034500:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80034500(args[0]);
    case 0x8002F420:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_8002F420(args[0]);
    case 0x8001E074:
        return ob_main_8001E074();
    case 0x8001D3C0:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_8001D3C0(args[0]);
    case 0x8002FA40:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8002FA40(args[0], args[1]);
    case 0x80046064:
        return ob_main_80046064();
    case 0x8004659C:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8004659C(args[0], args[1]);
    case 0x8001C33C:
        if (count < 4) ob_native_missing(target, 4, count);
        return ob_main_8001C33C(args[0], args[1], args[2], args[3]);
    case 0x80024C3C:
        return ob_main_80024C3C();
    case 0x8002DB80:
        if (count < 4) ob_native_missing(target, 4, count);
        ob_main_8002DB80(args[0], args[1], args[2], args[3]); return 0;
    case 0x8002D9FC:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_8002D9FC(args[0]);
    case 0x8002F594:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8002F594(args[0], args[1]);
    case 0x8001CE4C:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8001CE4C(args[0], args[1]);
    case 0x8001CEBC:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8001CEBC(args[0], args[1]);
    case 0x8001FB50:
        return ob_main_8001FB50();
    case 0x800175A8:
        if (count < 3) ob_native_missing(target, 3, count);
        return ob_main_800175A8(args[0], args[1], args[2]);
    case 0x800132A0:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_800132A0(args[0], args[1]);
    case 0x80023D40:
        return ob_main_80023D40();
    case 0x80023DB8:
        return ob_main_80023DB8();
    case 0x80024CA4:
        return ob_main_80024CA4();
    case 0x80032240:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80032240(args[0]);
    case 0x8001FAC8:
        return ob_main_8001FAC8();
    case 0x800341A4:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_800341A4(args[0]);
    case 0x80015CAC:
        if (count < 3) ob_native_missing(target, 3, count);
        return ob_main_80015CAC(args[0], args[1], args[2]);
    case 0x80024B98:
        return ob_main_80024B98();
    case 0x80029384:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_80029384(args[0], args[1]);
    case 0x80032058:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_80032058(args[0], args[1]);
    case 0x8002755C:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8002755C(args[0], args[1]);
    case 0x800541A8:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_800541A8(args[0]);
    case 0x800305CC:
        if (count < 3) ob_native_missing(target, 3, count);
        return ob_main_800305CC(args[0], args[1], args[2]);
    case 0x80015D40:
        if (count < 3) ob_native_missing(target, 3, count);
        return ob_main_80015D40(args[0], args[1], args[2]);
    case 0x80017618:
        if (count < 4) ob_native_missing(target, 4, count);
        return ob_main_80017618(args[0], args[1], args[2], args[3]);
    case 0x8001D404:
        return ob_main_8001D404();
    case 0x8003DCDC:
        if (count < 1) ob_native_missing(target, 1, count);
        ob_main_8003DCDC(args[0]); return 0;
    case 0x8005FB28:
        if (count < 3) ob_native_missing(target, 3, count);
        return ob_main_8005FB28(args[0], args[1], args[2]);
    case 0x8001345C:
        if (count < 4) ob_native_missing(target, 4, count);
        return ob_main_8001345C(args[0], args[1], args[2], args[3]);
    case 0x80013524:
        if (count < 4) ob_native_missing(target, 4, count);
        return ob_main_80013524(args[0], args[1], args[2], args[3]);
    case 0x80034608:
        return ob_main_80034608();
    case 0x80048610:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80048610(args[0]);
    case 0x8003D0EC:
        return ob_main_8003D0EC();
    case 0x8004B8AC:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_8004B8AC(args[0]);
    case 0x8001D4E4:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_8001D4E4(args[0]);
    case 0x80033074:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80033074(args[0]);
    case 0x80045E98:
        return ob_main_80045E98();
    case 0x8001FBCC:
        return ob_main_8001FBCC();
    case 0x8002CF44:
        return ob_main_8002CF44();
    case 0x800348B4:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_800348B4(args[0], args[1]);
    case 0x800397AC:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_800397AC(args[0], args[1]);
    case 0x8002FD68:
        if (count < 3) ob_native_missing(target, 3, count);
        return ob_main_8002FD68(args[0], args[1], args[2]);
    case 0x80012E78:
        if (count < 3) ob_native_missing(target, 3, count);
        return ob_main_80012E78(args[0], args[1], args[2]);
    case 0x8001AE60:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8001AE60(args[0], args[1]);
    case 0x80013DA4:
        if (count < 3) ob_native_missing(target, 3, count);
        return ob_main_80013DA4(args[0], args[1], args[2]);
    case 0x8004D1C0:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_8004D1C0(args[0]);
    case 0x8002C5DC:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_8002C5DC(args[0]);
    case 0x80037F0C:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80037F0C(args[0]);
    case 0x8001CBBC:
        return ob_main_8001CBBC();
    case 0x8001C148:
        if (count < 5) ob_native_missing(target, 5, count);
        return ob_main_8001C148(args[0], args[1], args[2], args[3], args[4]);
    case 0x8002C018:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8002C018(args[0], args[1]);
    case 0x8002C16C:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8002C16C(args[0], args[1]);
    case 0x80015B1C:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80015B1C(args[0]);
    case 0x80013A6C:
        if (count < 7) ob_native_missing(target, 7, count);
        ob_main_80013A6C(args[0], args[1], args[2], args[3], args[4], args[5], args[6]); return 0;
    case 0x8004D4A0:
        if (count < 6) ob_native_missing(target, 6, count);
        return ob_main_8004D4A0(args[0], args[1], args[2], args[3], args[4], args[5]);
    case 0x8004D2FC:
        if (count < 6) ob_native_missing(target, 6, count);
        return ob_main_8004D2FC(args[0], args[1], args[2], args[3], args[4], args[5]);
    case 0x8003DDB4:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_8003DDB4(args[0]);
    case 0x8002B970:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8002B970(args[0], args[1]);
    case 0x8002BCC4:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8002BCC4(args[0], args[1]);
    case 0x8002BB18:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8002BB18(args[0], args[1]);
    case 0x8002BE6C:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8002BE6C(args[0], args[1]);
    case 0x80026A0C:
        if (count < 1) ob_native_missing(target, 1, count);
        ob_main_80026A0C(args[0]); return 0;
    case 0x8001D5F0:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8001D5F0(args[0], args[1]);
    case 0x80048418:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80048418(args[0]);
    case 0x8002C7D8:
        return ob_main_8002C7D8();
    case 0x8002DF2C:
        if (count < 3) ob_native_missing(target, 3, count);
        return ob_main_8002DF2C(args[0], args[1], args[2]);
    case 0x8002E2BC:
        if (count < 3) ob_native_missing(target, 3, count);
        return ob_main_8002E2BC(args[0], args[1], args[2]);
    case 0x8002E64C:
        if (count < 3) ob_native_missing(target, 3, count);
        return ob_main_8002E64C(args[0], args[1], args[2]);
    case 0x80018190:
        if (count < 5) ob_native_missing(target, 5, count);
        return ob_main_80018190(args[0], args[1], args[2], args[3], args[4]);
    case 0x8002EF88:
        if (count < 3) ob_native_missing(target, 3, count);
        return ob_main_8002EF88(args[0], args[1], args[2]);
    case 0x8004492C:
        if (count < 5) ob_native_missing(target, 5, count);
        return ob_main_8004492C(args[0], args[1], args[2], args[3], args[4]);
    case 0x8001D818:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_8001D818(args[0]);
    case 0x8002F5FC:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8002F5FC(args[0], args[1]);
    case 0x8003A064:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_8003A064(args[0]);
    case 0x80015374:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_80015374(args[0], args[1]);
    case 0x80033158:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_80033158(args[0], args[1]);
    case 0x800184EC:
        return ob_main_800184EC();
    case 0x8003CC8C:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8003CC8C(args[0], args[1]);
    case 0x800188E8:
        if (count < 5) ob_native_missing(target, 5, count);
        return ob_main_800188E8(args[0], args[1], args[2], args[3], args[4]);
    case 0x800176C8:
        if (count < 4) ob_native_missing(target, 4, count);
        return ob_main_800176C8(args[0], args[1], args[2], args[3]);
    case 0x80017C10:
        return ob_main_80017C10();
    case 0x80019360:
        if (count < 5) ob_native_missing(target, 5, count);
        return ob_main_80019360(args[0], args[1], args[2], args[3], args[4]);
    case 0x80018DB0:
        return ob_main_80018DB0();
    case 0x8003803C:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_8003803C(args[0]);
    case 0x8002E968:
        if (count < 3) ob_native_missing(target, 3, count);
        return ob_main_8002E968(args[0], args[1], args[2]);
    case 0x800322BC:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_800322BC(args[0]);
    case 0x8001C3B0:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_8001C3B0(args[0]);
    case 0x80032A68:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_80032A68(args[0], args[1]);
    case 0x80040E28:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80040E28(args[0]);
    case 0x8003D20C:
        ob_main_8003D20C(); return 0;
    case 0x8001B060:
        if (count < 1) ob_native_missing(target, 1, count);
        ob_main_8001B060(args[0]); return 0;
    case 0x8003BB2C:
        return ob_main_8003BB2C();
    case 0x8003DF98:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8003DF98(args[0], args[1]);
    case 0x8003F528:
        if (count < 2) ob_native_missing(target, 2, count);
        return ob_main_8003F528(args[0], args[1]);
    case 0x8005FBE8:
        if (count < 4) ob_native_missing(target, 4, count);
        return ob_main_8005FBE8(args[0], args[1], args[2], args[3]);
    case 0x80063D08:
        if (count < 1) ob_native_missing(target, 1, count);
        return ob_main_80063D08(args[0]);
        default: ob_native_missing(target, UINT32_MAX, count);
    }
}
