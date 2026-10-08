#include "front_signatures.h"
#include "native_runtime.h"

static uint32 loaded_overlay = UINT32_MAX;

void ob_native_overlay_loaded(uint32 index)
{
    if (index > 2u) ob_native_missing(0x800170F8u, 2u, index);
    loaded_overlay = index;
}

uint32 ob_native_front_dispatch(uint32 target, uint32 count, const uint32 *args)
{
    if (loaded_overlay != 0u) ob_native_missing(target, 0u, loaded_overlay);
    switch (target)
    {
    case 0x8008DB20u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_8008DB20((uint32)args[0]);
    case 0x8008DD3Cu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_8008DD3C((uint32)args[0]);
    case 0x8008DD94u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_8008DD94((uint32)args[0]);
    case 0x8008E090u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_8008E090((uint32)args[0]);
    case 0x8008E138u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_8008E138();
    case 0x8008E140u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_8008E140((uint32)args[0]);
    case 0x8008E198u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_8008E198();
    case 0x8008E1A0u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_8008E1A0((uint32)args[0]);
    case 0x8008E204u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_8008E204();
    case 0x8008E20Cu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_8008E20C((uint32)args[0]);
    case 0x8008E270u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_8008E270();
    case 0x8008E278u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_8008E278((uint32)args[0]);
    case 0x8008E2DCu:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_8008E2DC((uint32)args[0], (uint32)args[1]);
    case 0x8008E380u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_8008E380((uint32)args[0], (uint32)args[1]);
    case 0x8008E424u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_8008E424((uint32)args[0], (uint32)args[1]);
    case 0x8008E4D8u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_8008E4D8();
    case 0x8008E530u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_8008E530();
    case 0x8008E588u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_8008E588();
    case 0x8008E5E0u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_8008E5E0((uint32)args[0]);
    case 0x8008E654u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        ob_front_8008E654();
        return 0u;
    case 0x8008E65Cu:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return (uint32)ob_front_8008E65C((uint32)args[0], (uint32)args[1], (uint32)args[2]);
    case 0x8008E780u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_8008E780((uint32)args[0], (uint32)args[1]);
    case 0x8008E828u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_8008E828((uint32)args[0], (uint32)args[1]);
    case 0x8008E998u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_8008E998((uint32)args[0], (uint32)args[1]);
    case 0x8008EB5Cu:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_8008EB5C();
    case 0x8008EBC8u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_8008EBC8((uint32)args[0], (uint32)args[1]);
    case 0x8008ED3Cu:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_8008ED3C();
    case 0x8008EDD0u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_8008EDD0((uint32)args[0]);
    case 0x8008EEECu:
        if (count != 0u) ob_native_missing(target, 0u, count);
        ob_front_8008EEEC();
        return 0u;
    case 0x8008EEF4u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_8008EEF4((uint32)args[0], (uint32)args[1]);
    case 0x8008F684u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_8008F684((uint32)args[0], (uint32)args[1]);
    case 0x8008F7F0u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_8008F7F0((uint32)args[0], (uint32)args[1]);
    case 0x80091274u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_80091274((uint32)args[0], (uint32)args[1]);
    case 0x80091920u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_80091920((uint32)args[0], (uint32)args[1]);
    case 0x800920FCu:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_800920FC();
    case 0x80092114u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_80092114();
    case 0x8009212Cu:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_8009212C((uint32)args[0], (uint32)args[1]);
    case 0x800921D0u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_800921D0((uint32)args[0], (uint32)args[1]);
    case 0x80092214u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_80092214((uint32)args[0], (uint32)args[1]);
    case 0x80092280u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_80092280((uint32)args[0], (uint32)args[1]);
    case 0x8009234Cu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_8009234C((uint32)args[0]);
    case 0x800923D4u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_800923D4((uint32)args[0]);
    case 0x80092704u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_80092704((uint32)args[0], (uint32)args[1]);
    case 0x80092814u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_80092814((uint32)args[0]);
    case 0x800928DCu:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_800928DC();
    case 0x80092928u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_80092928((uint32)args[0], (uint32)args[1]);
    case 0x80092BC4u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_80092BC4((uint32)args[0]);
    case 0x80092C30u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_80092C30((uint32)args[0]);
    case 0x80092CB0u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_80092CB0((uint32)args[0]);
    case 0x80092D14u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        ob_front_80092D14();
        return 0u;
    case 0x80092D1Cu:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_80092D1C((uint32)args[0], (uint32)args[1]);
    case 0x80092D30u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_80092D30((uint32)args[0]);
    case 0x80092DACu:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return (uint32)ob_front_80092DAC((uint32)args[0], (uint32)args[1], (uint32)args[2]);
    case 0x80092E84u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_80092E84((uint32)args[0]);
    case 0x8009307Cu:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_8009307C();
    case 0x80093150u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_80093150();
    case 0x80093224u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_80093224();
    case 0x800932A0u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_800932A0();
    case 0x8009331Cu:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_8009331C();
    case 0x8009341Cu:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_8009341C();
    case 0x8009350Cu:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_8009350C();
    case 0x80093780u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_80093780();
    case 0x800939F4u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_800939F4();
    case 0x80093A34u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_80093A34();
    case 0x80093A74u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_80093A74();
    case 0x80093AB4u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_80093AB4();
    case 0x80093AF4u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_80093AF4();
    case 0x80093B34u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_80093B34();
    case 0x80093B74u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_80093B74();
    case 0x80093BB4u:
        if (count != 5u) ob_native_missing(target, 5u, count);
        ob_front_80093BB4((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4]);
        return 0u;
    case 0x80093E70u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_80093E70((uint32)args[0]);
    case 0x80094030u:
        if (count != 4u) ob_native_missing(target, 4u, count);
        ob_front_80094030((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
        return 0u;
    case 0x80094288u:
        if (count != 5u) ob_native_missing(target, 5u, count);
        return (uint32)ob_front_80094288((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4]);
    case 0x80094488u:
        if (count != 7u) ob_native_missing(target, 7u, count);
        return (uint32)ob_front_80094488((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5], (uint32)args[6]);
    case 0x8009465Cu:
        if (count != 6u) ob_native_missing(target, 6u, count);
        return (uint32)ob_front_8009465C((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4], (uint32)args[5]);
    case 0x800946F0u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_800946F0((uint32)args[0]);
    case 0x80094790u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_80094790((uint32)args[0]);
    case 0x800947B4u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_800947B4();
    case 0x800947ECu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_800947EC((uint32)args[0]);
    case 0x8009482Cu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_8009482C((uint32)args[0]);
    case 0x80094894u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_80094894((uint32)args[0], (uint32)args[1]);
    case 0x800948D0u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_800948D0((uint32)args[0], (uint32)args[1]);
    case 0x80094918u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_80094918((uint32)args[0], (uint32)args[1]);
    case 0x800949ACu:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_800949AC((uint32)args[0], (uint32)args[1]);
    case 0x800949F4u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_800949F4((uint32)args[0], (uint32)args[1]);
    case 0x80094A88u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_80094A88((uint32)args[0], (uint32)args[1]);
    case 0x80094B7Cu:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_80094B7C((uint32)args[0], (uint32)args[1]);
    case 0x80094C68u:
        if (count != 4u) ob_native_missing(target, 4u, count);
        return (uint32)ob_front_80094C68((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
    case 0x80094DFCu:
        if (count != 4u) ob_native_missing(target, 4u, count);
        return (uint32)ob_front_80094DFC((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
    case 0x80094FB0u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        ob_front_80094FB0((uint32)args[0], (uint32)args[1], (uint32)args[2]);
        return 0u;
    case 0x80095094u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_80095094();
    case 0x80095D1Cu:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_80095D1C((uint32)args[0], (uint32)args[1]);
    case 0x80095DF0u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return (uint32)ob_front_80095DF0((uint32)args[0], (uint32)args[1], (uint32)args[2]);
    case 0x80095F9Cu:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return (uint32)ob_front_80095F9C((uint32)args[0], (uint32)args[1], (uint32)args[2]);
    case 0x800962A4u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return (uint32)ob_front_800962A4((uint32)args[0], (uint32)args[1], (uint32)args[2]);
    case 0x80096550u:
        if (count != 4u) ob_native_missing(target, 4u, count);
        return (uint32)ob_front_80096550((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
    case 0x80096B8Cu:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_80096B8C((uint32)args[0], (uint32)args[1]);
    case 0x80096CECu:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_80096CEC((uint32)args[0], (uint32)args[1]);
    case 0x80096E3Cu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_80096E3C((uint32)args[0]);
    case 0x80096EDCu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_80096EDC((uint32)args[0]);
    case 0x80097094u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_80097094((uint32)args[0]);
    case 0x80097114u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_80097114((uint32)args[0], (uint32)args[1]);
    case 0x800971D0u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_800971D0((uint32)args[0]);
    case 0x800971F0u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_800971F0((uint32)args[0]);
    case 0x80097210u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_80097210((uint32)args[0]);
    case 0x80097458u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_80097458((uint32)args[0]);
    case 0x800974E4u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return (uint32)ob_front_800974E4((uint32)args[0], (uint32)args[1], (uint32)args[2]);
    case 0x8009789Cu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_8009789C((uint32)args[0]);
    case 0x800978F0u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_800978F0((uint32)args[0]);
    case 0x80097944u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_80097944((uint32)args[0]);
    case 0x80097DFCu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_80097DFC((uint32)args[0]);
    case 0x80097E5Cu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_80097E5C((uint32)args[0]);
    case 0x80097EF8u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_80097EF8((uint32)args[0]);
    case 0x80097FE8u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_80097FE8((uint32)args[0], (uint32)args[1]);
    case 0x80098058u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return (uint32)ob_front_80098058((uint32)args[0], (uint32)args[1], (uint32)args[2]);
    case 0x800980B0u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return (uint32)ob_front_800980B0((uint32)args[0], (uint32)args[1], (uint32)args[2]);
    case 0x8009810Cu:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return (uint32)ob_front_8009810C((uint32)args[0], (uint32)args[1], (uint32)args[2]);
    case 0x80098168u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_80098168((uint32)args[0]);
    case 0x800981C8u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_800981C8((uint32)args[0]);
    case 0x80098298u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_80098298((uint32)args[0]);
    case 0x800988BCu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        ob_front_800988BC((uint32)args[0]);
        return 0u;
    case 0x8009898Cu:
        if (count != 5u) ob_native_missing(target, 5u, count);
        ob_front_8009898C((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3], (uint32)args[4]);
        return 0u;
    case 0x80098DFCu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_80098DFC((uint32)args[0]);
    case 0x800993B4u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_800993B4((uint32)args[0]);
    case 0x800994B0u:
        if (count != 4u) ob_native_missing(target, 4u, count);
        return (uint32)ob_front_800994B0((uint32)args[0], (uint32)args[1], (uint32)args[2], (uint32)args[3]);
    case 0x800996B8u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_800996B8((uint32)args[0]);
    case 0x8009978Cu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_8009978C((uint32)args[0]);
    case 0x80099890u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_80099890((uint32)args[0], (uint32)args[1]);
    case 0x800999D8u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return (uint32)ob_front_800999D8((uint32)args[0], (uint32)args[1], (uint32)args[2]);
    case 0x80099AF4u:
        if (count != 0u) ob_native_missing(target, 0u, count);
        return (uint32)ob_front_80099AF4();
    case 0x8009A248u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return (uint32)ob_front_8009A248((uint32)args[0], (uint32)args[1], (uint32)args[2]);
    case 0x8009A2E4u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_8009A2E4((uint32)args[0], (uint32)args[1]);
    case 0x8009AB74u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_8009AB74((uint32)args[0]);
    case 0x8009AE68u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_8009AE68((uint32)args[0], (uint32)args[1]);
    case 0x8009B4E4u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_8009B4E4((uint32)args[0]);
    case 0x8009B540u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_8009B540((uint32)args[0], (uint32)args[1]);
    case 0x8009B704u:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_8009B704((uint32)args[0], (uint32)args[1]);
    case 0x8009B7A0u:
        if (count != 3u) ob_native_missing(target, 3u, count);
        return (uint32)ob_front_8009B7A0((uint32)args[0], (uint32)args[1], (uint32)args[2]);
    case 0x8009B8E4u:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return (uint32)ob_front_8009B8E4((uint32)args[0]);
    case 0x8009B94Cu:
        if (count != 2u) ob_native_missing(target, 2u, count);
        return (uint32)ob_front_8009B94C((uint32)args[0], (uint32)args[1]);
    default:
        ob_native_missing(target, UINT32_MAX, count);
    }
}
