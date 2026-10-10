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
    default:
        ob_native_missing(target, UINT32_MAX, count);
    }
}
