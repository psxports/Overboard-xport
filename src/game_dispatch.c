#include "game_signatures.h"
#include "native_runtime.h"
uint32 ob_native_game_dispatch(uint32 target, uint32 count, const uint32 *args)
{
    switch (target)
    {
    case 0x800A0D38u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800A0D38(args[0]);
    case 0x800BB7DCu:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800BB7DC(args[0], args[1], args[2]);
    case 0x80093C44u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return ob_game_80093C44();
    case 0x80093D00u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_80093D00((uint32)args[0]);
    case 0x80093E08u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_80093E08((uint32)args[0]);
    case 0x8009450Cu:
        if (count != 2u) ob_native_missing(target, 2u, count);
        ob_game_8009450C((uint32)args[0], (uint32)args[1]);
        return 0u;
    case 0x8009470Cu:
        if (count != 3u) ob_native_missing(target, 3u, count);
        ob_game_8009470C((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        return 0u;
    case 0x80097E04u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return ob_game_80097E04();
    case 0x800C1104u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return ob_game_800C1104();
    case 0x80095494u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return ob_game_80095494();
    case 0x800A5520u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        ob_game_800A5520();
        return 0u;
    case 0x800C15E4u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return ob_game_800C15E4();
    case 0x800AE0C4u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return ob_game_800AE0C4();
    case 0x800C190Cu:
        if (count != 0u) ob_native_missing(target, 0u, count);
        ob_game_800C190C();
        return 0u;
    case 0x800A309Cu:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return ob_game_800A309C();
    case 0x800923F8u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        ob_game_800923F8();
        return 0u;
    case 0x800ADAC8u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        ob_game_800ADAC8();
        return 0u;
    case 0x800A49A4u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return ob_game_800A49A4();
    case 0x800A0BE8u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return ob_game_800A0BE8();
    case 0x800BB3CCu:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return ob_game_800BB3CC();
    case 0x800A4A98u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return ob_game_800A4A98();
    case 0x800A4A34u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return ob_game_800A4A34();
    case 0x800A4AC8u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800A4AC8(args[0]);
    case 0x80092138u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return ob_game_80092138();
    case 0x800A55E4u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return ob_game_800A55E4();
    case 0x800A0B38u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800A0B38(args[0]);
    case 0x800A50BCu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800A50BC(args[0]);
    case 0x800A0930u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return ob_game_800A0930(args[0], args[1]);
    case 0x800A0CB0u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return ob_game_800A0CB0();
    case 0x800901A8u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800901A8(args[0]);
    case 0x800901FCu:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return ob_game_800901FC(args[0], args[1]);
    case 0x800A0D10u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800A0D10(args[0]);
    case 0x800C0FA8u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return ob_game_800C0FA8(args[0], args[1]);
    case 0x800C0FC8u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800C0FC8(args[0], args[1], args[2]);
    case 0x800C1030u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800C1030(args[0], args[1], args[2]);
    case 0x800AEF70u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800AEF70(args[0]);
    case 0x800AF07Cu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800AF07C(args[0]);
    case 0x800BC3D8u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800BC3D8(args[0], args[1], args[2]);
    case 0x800C1068u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        ob_game_800C1068(args[0], args[1], args[2]);
        return 0u;
    case 0x800BCBB8u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800BCBB8(args[0]);
    case 0x800BCD2Cu:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return ob_game_800BCD2C(args[0], args[1]);
    case 0x800BC718u:
        if (count != 4u) ob_native_missing(target, 4u, count);
        return ob_game_800BC718(args[0], args[1], args[2], args[3]);
    case 0x800BCFBCu:
        if (count != 4u) ob_native_missing(target, 4u, count);
        return ob_game_800BCFBC(args[0], args[1], args[2], args[3]);
    case 0x800BD7E4u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return ob_game_800BD7E4(args[0], args[1]);
    case 0x800A5184u:
        if (count != 4u) ob_native_missing(target, 4u, count);
        return ob_game_800A5184(args[0], args[1], args[2], args[3]);
    case 0x80095528u:
        if (count != 4u) ob_native_missing(target, 4u, count);
        return ob_game_80095528(args[0], args[1], args[2], args[3]);
    case 0x800BD8ACu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800BD8AC(args[0]);
    case 0x800900E0u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800900E0(args[0]);
    case 0x800BDCE0u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return ob_game_800BDCE0(args[0], args[1]);
    case 0x800BD8E8u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800BD8E8(args[0], args[1], args[2]);
    case 0x800AD4D0u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800AD4D0(args[0], args[1], args[2]);
    case 0x800BDE48u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800BDE48(args[0], args[1], args[2]);
    case 0x800C08BCu:
        if (count != 4u) ob_native_missing(target, 4u, count);
        ob_game_800C08BC(args[0], args[1], args[2], args[3]);
        return 0u;
    case 0x800AD6E0u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return ob_game_800AD6E0(args[0], args[1]);
    case 0x800BFF00u:
        if (count != 4u) ob_native_missing(target, 4u, count);
        return ob_game_800BFF00(args[0], args[1], args[2], args[3]);
    case 0x800C0DD4u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800C0DD4(args[0]);
    case 0x800BE604u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800BE604(args[0], args[1], args[2]);
    case 0x800BF4FCu:
        if (count != 4u) ob_native_missing(target, 4u, count);
        return ob_game_800BF4FC(args[0], args[1], args[2], args[3]);
    case 0x80099514u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_80099514(args[0]);
    case 0x800BFC18u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        ob_game_800BFC18(args[0], args[1]);
        return 0u;
    case 0x800C0868u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800C0868(args[0]);
    case 0x80097524u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        ob_game_80097524(args[0], args[1], args[2]);
        return 0u;
    case 0x8009949Cu:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return ob_game_8009949C(args[0], args[1]);
    case 0x800C05CCu:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800C05CC(args[0], args[1], args[2]);
    case 0x800C0744u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800C0744(args[0], args[1], args[2]);
    case 0x800B9E84u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800B9E84(args[0]);
    case 0x800C07BCu:
        if (count != 5u) ob_native_missing(target, 5u, count);
        return ob_game_800C07BC(args[0], args[1], args[2], args[3], args[4]);
    case 0x800B7C7Cu:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800B7C7C(args[0], args[1], args[2]);
    case 0x800C0F70u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        ob_game_800C0F70(args[0], args[1], args[2]);
        return 0u;
    case 0x8008FFE0u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_8008FFE0(args[0], args[1], args[2]);
    case 0x80090070u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_80090070(args[0], args[1], args[2]);
    case 0x800B4874u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return ob_game_800B4874(args[0], args[1]);
    case 0x800B45F4u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        ob_game_800B45F4(args[0]);
        return 0u;
    case 0x800B47B0u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        ob_game_800B47B0(args[0]);
        return 0u;
    case 0x800B3AD0u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800B3AD0(args[0], args[1], args[2]);
    case 0x800B3A90u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return ob_game_800B3A90(args[0], args[1]);
    case 0x800A2D74u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        ob_game_800A2D74(args[0]);
        return 0u;
    case 0x800A9C30u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800A9C30(args[0]);
    case 0x80092C6Cu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        ob_game_80092C6C(args[0]);
        return 0u;
    case 0x800A1964u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        ob_game_800A1964(args[0]);
        return 0u;
    case 0x800A5528u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        ob_game_800A5528(args[0]);
        return 0u;
    case 0x800944C4u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800944C4(args[0]);
    case 0x800C136Cu:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return ob_game_800C136C();
    case 0x800BA1C8u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return ob_game_800BA1C8();
    case 0x800BAA14u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800BAA14(args[0]);
    case 0x800AE0F8u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return ob_game_800AE0F8(args[0], args[1]);
    case 0x80093D84u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return ob_game_80093D84();
    case 0x800A636Cu:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return ob_game_800A636C(args[0], args[1]);
    case 0x800B0768u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800B0768(args[0], args[1], args[2]);
    case 0x800B07E4u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800B07E4(args[0], args[1], args[2]);
    case 0x800A3134u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return ob_game_800A3134(args[0], args[1]);
    case 0x80090CB4u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_80090CB4(args[0], args[1], args[2]);
    case 0x800916A0u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return ob_game_800916A0(args[0], args[1]);
    case 0x80092190u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return ob_game_80092190(args[0], args[1]);
    case 0x80097578u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_80097578(args[0], args[1], args[2]);
    case 0x80099798u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return ob_game_80099798(args[0], args[1]);
    case 0x800AEE18u:
        if (count != 5u) ob_native_missing(target, 5u, count);
        return ob_game_800AEE18(args[0], args[1], args[2], args[3], args[4]);
    case 0x800AEEB8u:
        if (count != 4u) ob_native_missing(target, 4u, count);
        return ob_game_800AEEB8(args[0], args[1], args[2], args[3]);
    case 0x800AE36Cu:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800AE36C(args[0], args[1], args[2]);
    case 0x800C0654u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800C0654(args[0], args[1], args[2]);
    case 0x80096244u:
        if (count != 5u) ob_native_missing(target, 5u, count);
        return ob_game_80096244(args[0], args[1], args[2], args[3], args[4]);
    case 0x8009696Cu:
        if (count != 4u) ob_native_missing(target, 4u, count);
        return ob_game_8009696C(args[0], args[1], args[2], args[3]);
    case 0x800C17F0u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800C17F0(args[0]);
    case 0x800B5C50u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800B5C50(args[0], args[1], args[2]);
    case 0x800B5BD8u:
        if (count != 4u) ob_native_missing(target, 4u, count);
        return ob_game_800B5BD8(args[0], args[1], args[2], args[3]);
    case 0x800B5CB4u:
        if (count != 4u) ob_native_missing(target, 4u, count);
        return ob_game_800B5CB4(args[0], args[1], args[2], args[3]);
    case 0x800B1F9Cu:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800B1F9C(args[0], args[1], args[2]);
    case 0x800B2150u:
        if (count != 5u) ob_native_missing(target, 5u, count);
        return ob_game_800B2150(args[0], args[1], args[2], args[3], args[4]);
    case 0x800B89D8u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800B89D8(args[0], args[1], args[2]);
    case 0x800C0C88u:
        if (count != 4u) ob_native_missing(target, 4u, count);
        return ob_game_800C0C88(args[0], args[1], args[2], args[3]);
    case 0x800A940Cu:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800A940C(args[0], args[1], args[2]);
    case 0x800A9D9Cu:
        if (count != 4u) ob_native_missing(target, 4u, count);
        return ob_game_800A9D9C(args[0], args[1], args[2], args[3]);
    case 0x800B5C80u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800B5C80(args[0], args[1], args[2]);
    case 0x800B762Cu:
        if (count != 5u) ob_native_missing(target, 5u, count);
        return ob_game_800B762C(args[0], args[1], args[2], args[3], args[4]);
    case 0x80094FFCu:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_80094FFC(args[0], args[1], args[2]);
    case 0x80095074u:
        if (count != 4u) ob_native_missing(target, 4u, count);
        return ob_game_80095074(args[0], args[1], args[2], args[3]);
    case 0x800B66C4u:
        if (count != 4u) ob_native_missing(target, 4u, count);
        return ob_game_800B66C4(args[0], args[1], args[2], args[3]);
    case 0x800B8060u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800B8060(args[0], args[1], args[2]);
    case 0x800B8138u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800B8138(args[0], args[1], args[2]);
    case 0x800B8E40u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800B8E40(args[0], args[1], args[2]);
    case 0x80092408u:
        if (count != 4u) ob_native_missing(target, 4u, count);
        return ob_game_80092408(args[0], args[1], args[2], args[3]);
    case 0x80092B74u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_80092B74(args[0], args[1], args[2]);
    case 0x80092BD8u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_80092BD8(args[0]);
    case 0x800B7C08u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800B7C08(args[0], args[1], args[2]);
    case 0x8009540Cu:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_8009540C(args[0], args[1], args[2]);
    case 0x80092BA8u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_80092BA8(args[0], args[1], args[2]);
    case 0x80092C14u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        ob_game_80092C14(args[0]);
        return 0u;
    case 0x80092B30u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_80092B30(args[0], args[1], args[2]);
    case 0x80092A8Cu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_80092A8C(args[0]);
    case 0x800955B0u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800955B0(args[0]);
    case 0x800B8A58u:
        if (count != 6u) ob_native_missing(target, 6u, count);
        return ob_game_800B8A58(args[0], args[1], args[2], args[3], args[4], args[5]);
    case 0x80094524u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_80094524(args[0]);
    case 0x8009459Cu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_8009459C(args[0]);
    case 0x8009464Cu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_8009464C(args[0]);
    case 0x800B6E64u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return ob_game_800B6E64(args[0], args[1], args[2]);
    case 0x800B7FDCu:
        if (count != 4u) ob_native_missing(target, 4u, count);
        return ob_game_800B7FDC(args[0], args[1], args[2], args[3]);
    case 0x800B6B9Cu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800B6B9C(args[0]);
    case 0x800B6C38u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_game_800B6C38(args[0]);
    case 0x800B7EEC:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800B7EEC(args[0], args[1], args[2]);
    case 0x800AEB60:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800AEB60(args[0], args[1]);
    case 0x800AEFCC:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800AEFCC(args[0]);
    case 0x8009B0F0:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_8009B0F0(args[0]);
    case 0x800A0B6C:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800A0B6C(args[0]);
    case 0x800BC958:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800BC958(args[0]);
    case 0x800BCAD4:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800BCAD4(args[0]);
    case 0x800BCAA0:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800BCAA0(args[0]);
    case 0x800BE25C:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800BE25C(args[0]);
    case 0x800A9E48:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800A9E48(args[0]);
    case 0x800997F4:
        if (count != 0) ob_native_missing(target, 0, count);
        ob_game_800997F4(); return 0;
    case 0x800A2C78:
        if (count != 1) ob_native_missing(target, 1, count);
        ob_game_800A2C78(args[0]); return 0;
    case 0x800A499C:
        if (count != 0) ob_native_missing(target, 0, count);
        ob_game_800A499C(); return 0;
    case 0x800BB3C4:
        if (count != 0) ob_native_missing(target, 0, count);
        ob_game_800BB3C4(); return 0;
    case 0x800BCA98:
        if (count != 0) ob_native_missing(target, 0, count);
        ob_game_800BCA98(); return 0;
    case 0x800A2C80:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800A2C80(args[0]);
    case 0x80097FC4:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_80097FC4(args[0], args[1]);
    case 0x800BC3C4:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800BC3C4(args[0]);
    case 0x800C191C:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800C191C(args[0]);
    case 0x800C1930:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800C1930(args[0]);
    case 0x800C1944:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800C1944(args[0]);
    case 0x800A9E30:
        if (count != 5) ob_native_missing(target, 5, count);
        return ob_game_800A9E30(args[0], args[1], args[2], args[3], args[4]);
    case 0x800C0F54:
        if (count != 2) ob_native_missing(target, 2, count);
        ob_game_800C0F54(args[0], args[1]); return 0;
    case 0x800A1BB4:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800A1BB4(args[0], args[1]);
    case 0x800A2D4C:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800A2D4C(args[0]);
    case 0x800ADD1C:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800ADD1C(args[0]);
    case 0x800BCB90:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800BCB90(args[0], args[1], args[2]);
    case 0x800BB630:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800BB630(args[0], args[1], args[2]);
    case 0x80094D6C:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_80094D6C(args[0], args[1], args[2]);
    case 0x800AFF34:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800AFF34(args[0], args[1], args[2]);
    case 0x800C0594:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800C0594(args[0]);
    case 0x800A1BD4:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800A1BD4(args[0], args[1]);
    case 0x800B41B8:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800B41B8(args[0], args[1], args[2]);
    case 0x800A1C68:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800A1C68(args[0]);
    case 0x8009F660:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_8009F660(args[0]);
    case 0x800B4164:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800B4164(args[0], args[1]);
    case 0x800954CC:
        if (count != 0) ob_native_missing(target, 0, count);
        return ob_game_800954CC();
    case 0x8009F6A4:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_8009F6A4(args[0]);
    case 0x8009F728:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_8009F728(args[0]);
    case 0x800A73F0:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800A73F0(args[0], args[1], args[2]);
    case 0x800A1B60:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800A1B60(args[0], args[1], args[2]);
    case 0x800A76A8:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800A76A8(args[0], args[1]);
    case 0x800AA62C:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800AA62C(args[0], args[1]);
    case 0x8009F6CC:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_8009F6CC(args[0], args[1]);
    case 0x800AB0C4:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800AB0C4(args[0], args[1], args[2]);
    case 0x800B36D0:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800B36D0(args[0], args[1], args[2]);
    case 0x800BB848:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800BB848(args[0], args[1]);
    case 0x800B31B4:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800B31B4(args[0], args[1], args[2]);
    case 0x800A1AF8:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800A1AF8(args[0], args[1]);
    case 0x800A296C:
        if (count != 0) ob_native_missing(target, 0, count);
        return ob_game_800A296C();
    case 0x800955F8:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800955F8(args[0], args[1], args[2]);
    case 0x8009A0C4:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_8009A0C4(args[0], args[1], args[2]);
    case 0x8009A7E8:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_8009A7E8(args[0], args[1], args[2]);
    case 0x8009C57C:
        if (count != 0) ob_native_missing(target, 0, count);
        return ob_game_8009C57C();
    case 0x8009F784:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_8009F784(args[0], args[1], args[2]);
    case 0x800A1258:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800A1258(args[0], args[1], args[2]);
    case 0x800A2E24:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800A2E24(args[0], args[1], args[2]);
    case 0x800A4E4C:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800A4E4C(args[0]);
    case 0x800A52C4:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800A52C4(args[0], args[1], args[2]);
    case 0x800A5B44:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800A5B44(args[0], args[1], args[2]);
    case 0x800A9720:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800A9720(args[0], args[1], args[2]);
    case 0x800AC640:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800AC640(args[0], args[1]);
    case 0x800AD720:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800AD720(args[0], args[1], args[2]);
    case 0x800AF798:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800AF798(args[0], args[1], args[2]);
    case 0x800B5904:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800B5904(args[0], args[1], args[2]);
    case 0x800BBA70:
        if (count != 4) ob_native_missing(target, 4, count);
        return ob_game_800BBA70(args[0], args[1], args[2], args[3]);
    case 0x800ADD44:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800ADD44(args[0], args[1], args[2]);
    case 0x800A0C34:
        if (count != 0) ob_native_missing(target, 0, count);
        return ob_game_800A0C34();
    case 0x800AEEE8:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800AEEE8(args[0]);
    case 0x800BABEC:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800BABEC(args[0], args[1]);
    case 0x800C1094:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800C1094(args[0]);
    case 0x800A9188:
        if (count != 3) ob_native_missing(target, 3, count);
        ob_game_800A9188(args[0], args[1], args[2]); return 0;
    case 0x800AAC34:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800AAC34(args[0], args[1]);
    case 0x800A7AA8:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800A7AA8(args[0], args[1], args[2]);
    case 0x800A2284:
        if (count != 4) ob_native_missing(target, 4, count);
        return ob_game_800A2284(args[0], args[1], args[2], args[3]);
    case 0x800A08A0:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800A08A0(args[0], args[1]);
    case 0x800ADAD8:
        if (count != 4) ob_native_missing(target, 4, count);
        return ob_game_800ADAD8(args[0], args[1], args[2], args[3]);
    case 0x800B979C:
        if (count != 4) ob_native_missing(target, 4, count);
        return ob_game_800B979C(args[0], args[1], args[2], args[3]);
    case 0x800BB9E8:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800BB9E8(args[0], args[1], args[2]);
    case 0x800C0EB0:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800C0EB0(args[0], args[1], args[2]);
    case 0x800B9584:
        if (count != 4) ob_native_missing(target, 4, count);
        return ob_game_800B9584(args[0], args[1], args[2], args[3]);
    case 0x80092098:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_80092098(args[0], args[1]);
    case 0x800AFE94:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800AFE94(args[0], args[1]);
    case 0x800A7CEC:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800A7CEC(args[0], args[1]);
    case 0x800A8A40:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800A8A40(args[0], args[1], args[2]);
    case 0x800A9680:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800A9680(args[0], args[1]);
    case 0x80094CC0:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_80094CC0(args[0], args[1]);
    case 0x800AAB84:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800AAB84(args[0], args[1], args[2]);
    case 0x800A2C8C:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800A2C8C(args[0]);
    case 0x800ADB68:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800ADB68(args[0]);
    case 0x800BB8A4:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800BB8A4(args[0], args[1]);
    case 0x800AC338:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800AC338(args[0]);
    case 0x800B8F08:
        if (count != 4) ob_native_missing(target, 4, count);
        return ob_game_800B8F08(args[0], args[1], args[2], args[3]);
    case 0x800A200C:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800A200C(args[0], args[1]);
    case 0x800A6D2C:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800A6D2C(args[0], args[1]);
    case 0x8009DE18:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_8009DE18(args[0], args[1], args[2]);
    case 0x800ADDA8:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800ADDA8(args[0], args[1], args[2]);
    case 0x800BA108:
        if (count != 4) ob_native_missing(target, 4, count);
        return ob_game_800BA108(args[0], args[1], args[2], args[3]);
    case 0x800B4FF8:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800B4FF8(args[0], args[1], args[2]);
    case 0x800A1CA8:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800A1CA8(args[0], args[1], args[2]);
    case 0x800B9260:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800B9260(args[0], args[1], args[2]);
    case 0x800BAB08:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800BAB08(args[0], args[1]);
    case 0x8009A704:
        if (count != 1) ob_native_missing(target, 1, count);
        ob_game_8009A704(args[0]); return 0;
    case 0x800B7DA8:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800B7DA8(args[0], args[1]);
    case 0x80094884:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_80094884(args[0], args[1], args[2]);
    case 0x800B50C4:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800B50C4(args[0], args[1], args[2]);
    case 0x800C0CF4:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800C0CF4(args[0], args[1]);
    case 0x800A6C34:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800A6C34(args[0], args[1], args[2]);
    case 0x800AB8BC:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800AB8BC(args[0], args[1], args[2]);
    case 0x800A6A30:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800A6A30(args[0], args[1], args[2]);
    case 0x800B4068:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800B4068(args[0], args[1]);
    case 0x800AC238:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800AC238(args[0], args[1], args[2]);
    case 0x800B8FBC:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800B8FBC(args[0], args[1]);
    case 0x800AFF6C:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800AFF6C(args[0], args[1], args[2]);
    case 0x800A2AEC:
        if (count != 4) ob_native_missing(target, 4, count);
        return ob_game_800A2AEC(args[0], args[1], args[2], args[3]);
    case 0x800A8ADC:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800A8ADC(args[0], args[1]);
    case 0x800A29E0:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800A29E0(args[0], args[1]);
    case 0x800BAD88:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800BAD88(args[0]);
    case 0x800A6B28:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800A6B28(args[0], args[1]);
    case 0x800ADF84:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800ADF84(args[0]);
    case 0x800ADC1C:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800ADC1C(args[0], args[1], args[2]);
    case 0x800ADE68:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800ADE68(args[0], args[1]);
    case 0x8009EF5C:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_8009EF5C(args[0], args[1], args[2]);
    case 0x8009C428:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_8009C428(args[0], args[1], args[2]);
    case 0x800BAC58:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800BAC58(args[0], args[1]);
    case 0x800AB4E4:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800AB4E4(args[0], args[1]);
    case 0x800AC414:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800AC414(args[0], args[1], args[2]);
    case 0x8009C2C8:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_8009C2C8(args[0], args[1], args[2]);
    case 0x80094DA4:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_80094DA4(args[0], args[1], args[2]);
    case 0x80091F3C:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_80091F3C(args[0], args[1], args[2]);
    case 0x800B3EF0:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800B3EF0(args[0], args[1], args[2]);
    case 0x800BB658:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800BB658(args[0], args[1], args[2]);
    case 0x80091918:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_80091918(args[0], args[1]);
    case 0x800A8B44:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800A8B44(args[0], args[1], args[2]);
    case 0x800BBEE0:
        if (count != 0) ob_native_missing(target, 0, count);
        return ob_game_800BBEE0();
    case 0x8009E750:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_8009E750(args[0], args[1], args[2]);
    case 0x800A20D0:
        if (count != 4) ob_native_missing(target, 4, count);
        return ob_game_800A20D0(args[0], args[1], args[2], args[3]);
    case 0x800949FC:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800949FC(args[0], args[1], args[2]);
    case 0x800B8818:
        if (count != 4) ob_native_missing(target, 4, count);
        return ob_game_800B8818(args[0], args[1], args[2], args[3]);
    case 0x80091AC8:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_80091AC8(args[0], args[1], args[2]);
    case 0x800AA198:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800AA198(args[0], args[1], args[2]);
    case 0x8009172C:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_8009172C(args[0], args[1]);
    case 0x800A2760:
        if (count != 6) ob_native_missing(target, 6, count);
        return ob_game_800A2760(args[0], args[1], args[2], args[3], args[4], args[5]);
    case 0x800B820C:
        if (count != 4) ob_native_missing(target, 4, count);
        return ob_game_800B820C(args[0], args[1], args[2], args[3]);
    case 0x800A7D94:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800A7D94(args[0], args[1], args[2]);
    case 0x800A9204:
        if (count != 4) ob_native_missing(target, 4, count);
        return ob_game_800A9204(args[0], args[1], args[2], args[3]);
    case 0x800A2558:
        if (count != 6) ob_native_missing(target, 6, count);
        return ob_game_800A2558(args[0], args[1], args[2], args[3], args[4], args[5]);
    case 0x800A8CE0:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800A8CE0(args[0], args[1]);
    case 0x800B349C:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800B349C(args[0], args[1], args[2]);
    case 0x8009CC64:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_8009CC64(args[0], args[1], args[2]);
    case 0x800A0010:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800A0010(args[0], args[1], args[2]);
    case 0x8009A4A8:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_8009A4A8(args[0], args[1]);
    case 0x800B3210:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800B3210(args[0], args[1]);
    case 0x8009C9E0:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_8009C9E0(args[0], args[1], args[2]);
    case 0x800A7440:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800A7440(args[0], args[1], args[2]);
    case 0x800966EC:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800966EC(args[0], args[1], args[2]);
    case 0x8009C018:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_8009C018(args[0], args[1], args[2]);
    case 0x800AA390:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800AA390(args[0], args[1], args[2]);
    case 0x800AB640:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800AB640(args[0], args[1], args[2]);
    case 0x800A1D74:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800A1D74(args[0], args[1]);
    case 0x8009F090:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_8009F090(args[0], args[1], args[2]);
    case 0x800BADAC:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800BADAC(args[0], args[1]);
    case 0x800BB07C:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800BB07C(args[0], args[1]);
    case 0x800963B4:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800963B4(args[0], args[1], args[2]);
    case 0x800B372C:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800B372C(args[0], args[1], args[2]);
    case 0x8009E3B0:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_8009E3B0(args[0], args[1], args[2]);
    case 0x800AB120:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800AB120(args[0], args[1], args[2]);
    case 0x800A0278:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800A0278(args[0], args[1], args[2]);
    case 0x800B41FC:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800B41FC(args[0], args[1]);
    case 0x800B83FC:
        if (count != 4) ob_native_missing(target, 4, count);
        return ob_game_800B83FC(args[0], args[1], args[2], args[3]);
    case 0x800AD01C:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800AD01C(args[0], args[1]);
    case 0x8009DEDC:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_8009DEDC(args[0], args[1], args[2]);
    case 0x800B51B0:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800B51B0(args[0], args[1], args[2]);
    case 0x800BA234:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800BA234(args[0], args[1], args[2]);
    case 0x800AC6F8:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800AC6F8(args[0], args[1]);
    case 0x800B271C:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800B271C(args[0], args[1], args[2]);
    case 0x800A7F88:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800A7F88(args[0], args[1]);
    case 0x800A6624:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_800A6624(args[0], args[1], args[2]);
    case 0x800A6DF0:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_game_800A6DF0(args[0]);
    case 0x80095D2C:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_80095D2C(args[0], args[1], args[2]);
    case 0x80095DD4:
        if (count != 5) ob_native_missing(target, 5, count);
        return ob_game_80095DD4(args[0], args[1], args[2], args[3], args[4]);
    case 0x80095EEC:
        if (count != 5) ob_native_missing(target, 5, count);
        return ob_game_80095EEC(args[0], args[1], args[2], args[3], args[4]);
    case 0x8009A860:
        if (count != 4) ob_native_missing(target, 4, count);
        return ob_game_8009A860(args[0], args[1], args[2], args[3]);
    case 0x8009A9A8:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_8009A9A8(args[0], args[1], args[2]);
    case 0x8009AB64:
        if (count != 3) ob_native_missing(target, 3, count);
        return ob_game_8009AB64(args[0], args[1], args[2]);
    case 0x800B9AF4:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800B9AF4(args[0], args[1]);
    case 0x800B9C24:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_game_800B9C24(args[0], args[1]);
    default:
        ob_native_missing(target, UINT32_MAX, count);
    }
}
