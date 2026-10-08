#include "draft_signatures.h"
#include "native_timers.h"

/* Unverified draft bodies */

uint32 sub_8001195C(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8001195Cu, "SLES_008.65");
    return a1 != UINT32_MAX ? sub_8001F454(a1, a2) : UINT32_MAX;
}

uint32 sub_80016254(void)
{
    FUNCTION_MARKER(0x80016254u, "SLES_008.65");
    return sub_80026758(0x80077660u);
}

uint32 sub_800602D0(void)
{
    FUNCTION_MARKER(0x800602D0u, "SLES_008.65");
    return ob_draft_unresolved_call(0x800602F0u, 1u, 0u);
}

uint32 sub_80025A9C(uint32 handle)
{
    FUNCTION_MARKER(0x80025A9Cu, "SLES_008.65");
    return sub_80025ABC(handle);
}

uint32 sub_80029290(void)
{
    FUNCTION_MARKER(0x80029290u, "SLES_008.65");
    /* TODO: Recover forwarded argument carriers omitted by IDA */
    return ob_draft_unresolved_call(0x800292B0u, 0u);
}

void sub_800558E4(void)
{
    FUNCTION_MARKER(0x800558E4u, "SLES_008.65");
    ob_native_timers_critical(0u);
    xport_bios_enter_critical();
}

uint32 sub_80055954(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80055954u, "SLES_008.65");
    /* TODO: Bind BIOS B0 firstfile selector 0x42 */
    return ob_draft_unresolved_call(0x80055954u, 2u, a1, a2);
}

void sub_8005F488(uint32 a1)
{
    FUNCTION_MARKER(0x8005F488u, "SLES_008.65");
    xport_gte_write_control(26u, a1);
}

uint32 sub_80026418(void)
{
    FUNCTION_MARKER(0x80026418u, "SLES_008.65");
    uint32 result;
    do result = sub_80026EB8(r_u32(0x80077228u));
    while (result != 0u);
    return result;
}

uint32 sub_80054B30(void)
{
    FUNCTION_MARKER(0x80054B30u, "SLES_008.65");
    w_u32(0x8008969Cu, 0u);
    uint32 result = sub_80054A24(0x80054AE0u, 100u);
    w_u32(0x8007FE28u, result);
    return result;
}

uint32 sub_80045464(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80045464u, "SLES_008.65");
    sub_800455DC(a1, a2);
    return a1 + 108u;
}

uint32 sub_80047B24(uint32 a1)
{
    FUNCTION_MARKER(0x80047B24u, "SLES_008.65");
    uint32 result = r_u32(a1 + 204u);
    if (result != 0u) return ob_draft_unresolved_call(0x80045F20u, 1u, a1 + 204u);
    return result;
}

uint32 sub_80046CAC(uint32 a1)
{
    FUNCTION_MARKER(0x80046CACu, "SLES_008.65");
    /* TODO: Recover forwarded carriers of the first call */
    ob_draft_unresolved_call(0x80046CDCu, 0u);
    return sub_80046D98(a1);
}

uint32 sub_80019EA0(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80019EA0u, "SLES_008.65");
    return ob_draft_unresolved_call(r_u32(0x800B0768u), 3u,
        r_u32(56u * a1 + ((uint32)-2146657944)), a2, r_u32(0x800882BCu));
}

uint32 sub_800259AC(uint32 a1)
{
    FUNCTION_MARKER(0x800259ACu, "SLES_008.65");
    uint32 word = r_u32(a1);
    uint32 result = word & 3u;
    if (word != 0u && result == 0u) return sub_80026758(a1);
    return result;
}

uint32 sub_80023E30(void)
{
    FUNCTION_MARKER(0x80023E30u, "SLES_008.65");
    sub_8005577C(128u);
    sub_80021EFC();
    sub_800170F8(1u);
    sub_80055808();
    return sub_80024548();
}

uint32 sub_80027E54(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80027E54u, "SLES_008.65");
    w_u32(sub_80027ED8(a1), a2);
    return ob_draft_unresolved_call(0x80063FD8u, 3u, a2, 0u, 1024u);
}

uint32 sub_80027F54(void)
{
    FUNCTION_MARKER(0x80027F54u, "SLES_008.65");
    sub_80026694(0x800775F4u, 1028u, 4u);
    sub_800268E8(0x800775F4u, 0u);
    w_u16(r_u32(0x800775F4u) + 1024u, 256u);
    return 256u;
}

uint32 sub_8002C728(uint32 a1)
{
    FUNCTION_MARKER(0x8002C728u, "SLES_008.65");
    w_u32(0x8007741Cu, 0x80084450u);
    w_u32(0x800773ACu, 0x80086A30u);
    sub_8002C77C(a1);
    w_u32(0x80077620u, 0u);
    ob_draft_unresolved_call(0x80059F3Cu, 1u, 0x8002CFF4u);
    return UINT32_MAX;
}

uint32 sub_80044C90(uint32 a1)
{
    FUNCTION_MARKER(0x80044C90u, "SLES_008.65");
    ob_draft_unresolved_call(0x8002679Cu, 2u, a1, 1u);
    sub_80044CD4(r_u32(a1));
    return ob_draft_unresolved_call(0x800267C4u, 2u, a1, 1u);
}

uint32 sub_80043B68(uint32 a1)
{
    FUNCTION_MARKER(0x80043B68u, "SLES_008.65");
    uint32 local = ob_draft_scratch_acquire(4u);
    w_u32(local, 0u);
    sub_800262CC(local, 40u);
    ob_draft_unresolved_call(0x80043BACu, 2u, r_u32(local), a1);
    uint32 result = r_u32(local);
    ob_draft_scratch_release(local);
    return result;
}

uint32 sub_800435AC(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x800435ACu, "SLES_008.65");
    uint32 local = ob_draft_scratch_acquire(4u);
    w_u32(local, 0u);
    sub_800262CC(local, 24u);
    sub_80043600(r_u32(local), a1, a2);
    uint32 result = r_u32(local);
    ob_draft_scratch_release(local);
    return result;
}

uint32 sub_800121CC(uint32 a1)
{
    FUNCTION_MARKER(0x800121CCu, "SLES_008.65");
    uint32 value = sub_8001E298(r_u32(a1), 0u);
    uint32 result = sub_80026758(a1);
    w_u32(a1, 4u * value + 2u);
    return result;
}

uint32 sub_80017178(void)
{
    FUNCTION_MARKER(0x80017178u, "SLES_008.65");
    uint32 index = r_u32(0x80065FF8u);
    ob_draft_unresolved_call(0x80063FD8u, 3u, r_u32(0x80065FFCu), 172u, r_u32(0x80065FFCu + 4u * (index + 1u)));
    index = r_u32(0x80065FF8u);
    w_u32(0x80065FF8u, UINT32_MAX);
    uint32 result = r_u32(0x800117C4u);
    w_u32(0x80065FFCu + 4u * (index + 1u), 0u);
    w_u32(0x80065FFCu, result);
    return result;
}

