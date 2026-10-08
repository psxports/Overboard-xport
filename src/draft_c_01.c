#include "draft_signatures.h"
#include "native_runtime.h"
#include "native_timers.h"
#include "native_sound_bindings.h"
#include <stdint.h>

/* Unverified draft bodies with unresolved adapters declared separately */

static sint32 draft_c_divide(sint32 numerator, sint32 denominator, uint32 fault)
{
    if (denominator == 0)
        return (sint32)ob_draft_unresolved_call(fault, 1u, 7u);
    if ((uint32)numerator == 0x80000000u && denominator == -1)
        return (sint32)ob_draft_unresolved_call(fault, 1u, 6u);
    return numerator / denominator;
}

void sub_80063C1C(sint32 a1)
{
    FUNCTION_MARKER(0x80063C1Cu, "SLES_008.65");
    ob_draft_unresolved_call(0x80059E8Cu, 1u, 0u);
    sub_800558E4();
    /* TODO: Frozen callee declaration omits the original a0 argument */
    ob_draft_unresolved_call(0x80063CD8u, 1u, (uint32)a1);
    ob_draft_unresolved_call(0x80063D60u, 0u);
    ob_draft_unresolved_call(0x80063E18u, 0u);
    sub_800558F4();
}

sint32 sub_80021C24(void)
{
    FUNCTION_MARKER(0x80021C24u, "SLES_008.65");
    uint32 rectangle = ob_draft_scratch_acquire(8u);
    w_u16(rectangle + 4u, 384u);
    w_u16(rectangle, 0u);
    w_u16(rectangle + 6u, 256u);
    w_u16(rectangle + 2u, (r_u32(0x800773D0u) == 0u) << 8);
    uint32 result = ob_draft_unresolved_call(0x8005C7C8u, 2u, rectangle, r_u32(0x8006C0D4u));
    ob_draft_scratch_release(rectangle);
    return (sint32)result;
}

sint32 sub_80045848(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80045848u, "SLES_008.65");
    uint32 first = r_u32(a2);
    uint32 second = r_u32(a2 + 4u);
    uint32 third = r_u32(a2 + 8u);
    uint32 fourth = r_u32(a2 + 12u);
    w_u32(a1 + 36u, first);
    w_u32(a1 + 40u, second);
    w_u32(a1 + 44u, third);
    w_u32(a1 + 48u, fourth);
    w_u16(a1 + 52u, r_u16(a2 + 16u));
    return (sint32)sub_80045B74(a1);
}

uint32 sub_80027E90(uint32 page_index)
{
    FUNCTION_MARKER(0x80027E90u, "SLES_008.65");
    uint32 allocation = ob_draft_unresolved_call(0x80027ED8u, 1u, page_index);
    sub_80026694(allocation, 1024u, 4u);
    sub_800268E8(allocation, 0u);
    return allocation;
}

sint32 sub_8001DF58(uint32 a1)
{
    FUNCTION_MARKER(0x8001DF58u, "SLES_008.65");
    uint32 command = ob_draft_scratch_acquire(8u);
    uint32 volume = (a1 & 255u) / 3u;
    w_u8(command + 1u, 0u);
    w_u8(command + 3u, 0u);
    w_u8(command, volume);
    w_u8(command + 2u, volume);
    uint32 result = ob_draft_unresolved_call(0x800563F0u, 1u, command);
    ob_draft_scratch_release(command);
    return (sint32)result;
}

sint32 sub_80046914(sint32 a1, sint32 a2)
{
    FUNCTION_MARKER(0x80046914u, "SLES_008.65");
    /* TODO: Callee consumes original incoming a0/a1 */
    sub_80046954((uint32)a1, (uint32)a2);
    return (sint32)sub_80046AF8((uint32)a1, (uint32)a2);
}

sint32 sub_8004F288(uint32 a1)
{
    FUNCTION_MARKER(0x8004F288u, "SLES_008.65");
    sub_80043C18(a1 + 28u);
    sub_80043C18(a1 + 100u);
    return (sint32)sub_80043664(a1);
}

sint32 sub_800269D0(uint32 a1)
{
    FUNCTION_MARKER(0x800269D0u, "SLES_008.65");
    sub_80027710(a1);
    uint32 destination = r_u32(a1 + 24u);
    uint32 result = r_u32(a1 + 28u);
    w_u32(destination, result);
    w_u16(a1 + 38u, 0u);
    return (sint32)result;
}

sint32 sub_80021AD8(void)
{
    FUNCTION_MARKER(0x80021AD8u, "SLES_008.65");
    if (r_u32(0x8008444Cu) == 1u)
        return (sint32)sub_80026758(0x8006C0D4u);
    w_u32(0x8006C0D4u, 0u);
    return 1;
}

void sub_80063C70(void)
{
    FUNCTION_MARKER(0x80063C70u, "SLES_008.65");
    sub_800558E4();
    sub_80063CE8();
    ob_draft_unresolved_call(0x80059E8Cu, 1u, 0u);
    sub_800558F4();
}

sint32 sub_800256CC(uint32 a1)
{
    FUNCTION_MARKER(0x800256CCu, "SLES_008.65");
    uint32 result = r_u32(a1) & 3u;
    if (result == 1u)
        return (sint32)sub_80025A9C(a1);
    return (sint32)result;
}

sint32 sub_80039808(sint32 a1, sint32 a2)
{
    FUNCTION_MARKER(0x80039808u, "SLES_008.65");
    ob_build_geometry_order((uint32)a1);
    return sub_8003AA8C((uint32)a2);
}

sint32 sub_80047FF0(uint32 a1)
{
    FUNCTION_MARKER(0x80047FF0u, "SLES_008.65");
    uint32 object = r_u32(a1);
    w_u32(a1 + 4u, 0xFFFFFFFFu);
    if (object != 0u)
        return (sint32)sub_80047F60(object);
    return -1;
}

sint32 sub_80045430(sint32 a1)
{
    FUNCTION_MARKER(0x80045430u, "SLES_008.65");
    sub_800454BC((uint32)a1);
    return (sint32)((uint32)a1 + 54u);
}

sint32 sub_80016220(sint32 a1)
{
    FUNCTION_MARKER(0x80016220u, "SLES_008.65");
    sub_80026694(0x80077660u, (uint32)a1 << 1, 0u);
    return (sint32)r_u32(0x80077660u);
}

sint32 sub_80045124(uint32 a1)
{
    FUNCTION_MARKER(0x80045124u, "SLES_008.65");
    uint32 cell = ob_draft_scratch_acquire(4u);
    w_u32(cell, a1);
    sub_80045094(a1);
    uint32 result = sub_800263B4(cell);
    ob_draft_scratch_release(cell);
    return (sint32)result;
}

sint32 sub_8004651C(uint32 a1)
{
    FUNCTION_MARKER(0x8004651Cu, "SLES_008.65");
    uint32 cell = ob_draft_scratch_acquire(4u);
    w_u32(cell, a1);
    sub_800464BC(a1);
    uint32 result = sub_800263B4(cell);
    ob_draft_scratch_release(cell);
    return (sint32)result;
}

void sub_80033F90(void)
{
    FUNCTION_MARKER(0x80033F90u, "SLES_008.65");
    w_u32(0x80077594u, 0u);
    w_u32(0x80077564u, 0u);
    w_u32(0x8007742Cu, 0u);
    w_u32(0x80077464u, 0u);
    w_u32(0x80077578u, 0u);
    w_u32(0x800773A8u, 0u);
}

sint32 sub_80011DA0(sint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80011DA0u, "SLES_008.65");
    return sub_8001F56C((uint32)a1, (sint32)(a2 & 255u));
}

sint32 sub_80045284(sint32 a1, sint32 a2)
{
    FUNCTION_MARKER(0x80045284u, "SLES_008.65");
    return (sint32)sub_80043AB0((uint32)a1 + 144u, (uint32)a2);
}

void sub_80059128(sint32 a1, sint32 a2, sint32 a3)
{
    FUNCTION_MARKER(0x80059128u, "SLES_008.65");
    w_u32(0x8008CEC0u, (uint32)a1);
    w_u32(0x80086B6Cu, (uint32)a2);
    w_u32(0x8008CEB8u, (uint32)a3);
}

sint32 sub_80054CD8(void)
{
    FUNCTION_MARKER(0x80054CD8u, "SLES_008.65");
    w_u32(0x800771E0u, 1u);
    return 1;
}

void sub_80063CE8(void)
{
    FUNCTION_MARKER(0x80063CE8u, "SLES_008.65");
    /* Route the reviewed StartCARD service through its canonical adapter */
    ob_draft_unresolved_call(0x80063CE8u, 0u);
}

sint32 sub_80011DE0(uint32 a0_unused, sint32 multiplier)
{
    FUNCTION_MARKER(0x80011DE0u, "SLES_008.65");
    uint32 product_low = (uint32)multiplier * r_u32(0x800882C0u);
    return (sint32)sub_80011DF0(a0_unused, product_low);
}

void nullsub_25(void)
{
    FUNCTION_MARKER(0x80043CD4u, "SLES_008.65");
    return;
}

sint32 sub_800169D0(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x800169D0u, "SLES_008.65");
    uint32 cursor = a2 + r_u32(a2 + 20u);
    sint32 result = (sint32)r_u32(a2 + 20u);
    uint32 count = 0u;
    if (r_u16(a2 + 4u) != 0u)
    {
        do
        {
            uint32 red = r_u8(cursor++);
            ++count;
            uint32 packed = (red + 4u) >> 3;
            w_u16(a1, packed);
            uint32 green = r_u8(cursor++);
            packed |= 32u * ((green + 4u) >> 3);
            w_u16(a1, packed);
            uint32 blue = r_u8(cursor++);
            w_u16(a1, packed | (((blue + 4u) >> 3) << 10));
            result = r_u16(a2 + 4u);
            a1 += 2u;
        } while (count != (uint32)result);
    }
    return result;
}

sint32 sub_80023A10(void)
{
    FUNCTION_MARKER(0x80023A10u, "SLES_008.65");
    sub_800556F4();
    ob_draft_unresolved_call(0x80055FD8u, 2u, 0u, 0x80089B90u);
    sub_800251E8(0x800769BCu);
    sub_800256CC(0x800769C0u);
    sub_80055808();
    sub_80016FC4(0x800769C4u);
    w_u32(0x8008969Cu, 500u);
    /* Deliver the hardware timer callback while the original countdown waits */
    while (r_s32(0x8008969Cu) > 0 && !xport_isquit())
        ob_native_pump();
    return (sint32)sub_800259AC(0x800769C4u);
}

sint32 sub_80030700(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x80030700u, "SLES_008.65");
    w_u32(0x800770E4u, 0u);
    w_u32(0x80088818u, 0u);
    w_u32(0x8008881Cu, 0u);
    w_u32(0x80088820u, 0u);
    w_u32(0x80088824u, 0u);
    w_u32(0x80088828u, 0u);
    w_u32(0x80088268u, 0u);
    w_u32(0x8008826Cu, 0u);
    w_u32(0x80088270u, 0u);
    w_u32(0x80088274u, 0u);
    w_u32(0x80088278u, 0u);
    return (sint32)ob_draft_unresolved_call(0x8005F448u, 3u, a1 & 255u, a2 & 255u, a3 & 255u);
}

sint32 sub_800465E8(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x800465E8u, "SLES_008.65");
    uint32 larger = a1;
    uint32 smaller = a2;
    if (r_s32(a2 + 24u) >= r_s32(a1 + 24u))
    {
        larger = a2;
        smaller = a1;
    }
    uint32 record = r_u32(r_u32(0x80077148u) + 4u * r_u32(larger + 24u));
    record += 8u * r_u32(smaller + 24u);
    w_u32(record + 4u, 0x7FFFFFFFu);
    w_u32(record, 128u);
    /* TODO: Preserve helper nonstandard argument carriers beyond a0 */
    return (sint32)ob_draft_unresolved_call(0x80047450u, 1u, larger);
}

sint32 sub_800279D4(uint32 a1)
{
    FUNCTION_MARKER(0x800279D4u, "SLES_008.65");
    a1 &= 65535u;
    uint32 cell = sub_80027DF8(a1);
    sub_80026694(cell, 16u, 4u);
    uint32 payload = r_u32(cell);
    w_u16(payload, a1);
    w_u32(payload + 4u, 0u);
    w_u32(payload + 8u, 0u);
    w_u32(payload + 12u, 0u);
    return (sint32)sub_80026898(cell, 0xFFFFu);
}

sint32 sub_800118C0(sint32 a1)
{
    FUNCTION_MARKER(0x800118C0u, "SLES_008.65");
    sub_8001DFF0();
    sub_8001DBCC((uint32)a1 & 255u);
    sub_8001DCF4();
    sub_8001DDF8();
    sub_8001DEB4(0u);
    sub_8001E050();
    w_u32(0x80065B70u, a1 == 4);
    return 1;
}

sint32 sub_8004F074(sint32 a1, sint32 a2, sint32 a3)
{
    FUNCTION_MARKER(0x8004F074u, "SLES_008.65");
    uint32 cell = ob_draft_scratch_acquire(4u);
    w_u32(cell, 0u);
    sub_800262CC(cell, 236);
    sub_8004F0D8(r_u32(cell), (uint32)a1, (uint32)a2, (uint32)a3);
    uint32 result = r_u32(cell);
    ob_draft_scratch_release(cell);
    return (sint32)result;
}

sint32 sub_8004DFB8(sint32 a1)
{
    FUNCTION_MARKER(0x8004DFB8u, "SLES_008.65");
    uint32 mode = r_u8(0x80077654u);
    if (mode == 1u || mode == 3u)
        return (sint32)ob_draft_unresolved_call(0x8004D1C0u, 1u, (uint32)a1);
    if (mode == 0u || mode == 2u)
        return (sint32)sub_8004D634((uint32)a1);
    return 3;
}

uint32 sub_80043600(uint32 a1, sint32 a2, sint32 a3)
{
    FUNCTION_MARKER(0x80043600u, "SLES_008.65");
    sub_80043CDC(a1, (uint32)a3);
    w_u32(a1, 0x800770F8u);
    w_u32(a1 + 12u, 0u);
    w_u32(a1 + 16u, 0u);
    w_u32(a1 + 20u, 0u);
    if (a2 != 0)
        sub_800436D4((uint32)a2, a1);
    return a1;
}

sint32 sub_800260F8(void)
{
    FUNCTION_MARKER(0x800260F8u, "SLES_008.65");
    sub_80026694(0x800770B8u, 0x2000u, 4u);
    sub_800268E8(0x800770B8u, 0u);
    w_u16(0x800770BCu, 0xFFFEu);
    sub_80027CD0(65534u);
    sub_800279D4(r_u16(0x800770BCu));
    return (sint32)sub_80027A74(r_u16(0x800770BCu), 0x80026278u);
}

sint32 sub_800437C4(uint32 a1, sint32 a2)
{
    FUNCTION_MARKER(0x800437C4u, "SLES_008.65");
    uint32 node = r_u32(a1 + 20u);
    while (node != 0u)
    {
        uint32 result = sub_8004389C(node, (uint32)a2);
        if (result != 0u)
            return (sint32)result;
        node = r_u32(node + 16u);
    }
    return 0;
}

sint32 sub_8004F004(sint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8004F004u, "SLES_008.65");
    sint32 sign = ((uint32)a1 & 8u) != 0u ? -1 : 1;
    w_u16(a2, ((uint32)a1 & 1u) != 0u ? (uint32)sign : 0u);
    w_u16(a2 + 2u, ((uint32)a1 & 2u) != 0u ? (uint32)sign : 0u);
    w_u16(a2 + 4u, ((uint32)a1 & 4u) != 0u ? (uint32)-sign : 0u);
    return -sign;
}

sint32 sub_8001F56C(uint32 a1, sint32 a2)
{
    FUNCTION_MARKER(0x8001F56Cu, "SLES_008.65");
    sint32 result = r_u8(0x8006C00Cu);
    if (result != 0)
    {
        result = a1 < 24u;
        if (a1 != 0xFFFFFFFFu)
        {
            result = (sint32)(8u * a1);
            if (a1 < 24u)
            {
                uint32 slot = 0x80078540u + 28u * a1;
                result = r_u32(slot + 4u) & 2u;
                if (result != 0)
                {
                    w_u8(slot + 23u, (uint32)a2);
                    /* TODO: Frozen helper signature omits the slot selector */
                    return (sint32)ob_draft_unresolved_call(0x8001FDA4u, 1u, a1);
                }
            }
        }
    }
    return result;
}

void sub_800303D4(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x800303D4u, "SLES_008.65");
    uint32 outputs = ob_draft_scratch_acquire(8u);
    sub_80028280(r_s16(a1), r_s16(a1 + 2u), outputs, outputs + 4u);
    sub_80028280(r_s16(a1 + 4u), r_s32(outputs + 4u), outputs, a2);
    ob_draft_scratch_release(outputs);
}

uint32 sub_8002F9C4(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8002F9C4u, "SLES_008.65");
    uint32 first = r_u32(a2);
    uint32 second = r_u32(a2 + 4u);
    uint32 third = r_u32(a2 + 8u);
    uint32 fourth = r_u32(a2 + 12u);
    w_u32(a1, first);
    w_u32(a1 + 4u, second);
    w_u32(a1 + 8u, third);
    w_u32(a1 + 12u, fourth);
    w_u16(a1 + 16u, r_u16(a2 + 16u));
    uint32 result = (r_u32(a1 + 48u) & 0xFFFFFFE0u) | 2u;
    w_u32(a1 + 48u, result);
    return result;
}

sint32 sub_8001DDF8(void)
{
    FUNCTION_MARKER(0x8001DDF8u, "SLES_008.65");
    sint32 result = r_u8(0x8006C00Cu);
    if (result != 0)
    {
        result = r_u8(0x8006C00Du);
        if (result != 0)
        {
            uint32 attributes = ob_draft_scratch_acquire(24u);
            w_u32(attributes, 6u);
            w_u16(attributes + 8u, r_u8(0x80078BE8u) << 8);
            w_u16(attributes + 10u, 0u - (r_u8(0x80078BE8u) << 8));
            ob_draft_unresolved_call(0x80061924u, 1u, attributes);
            ob_draft_scratch_release(attributes);
            w_u8(0x8006C00Eu, 1u);
            result = 1;
        }
    }
    return result;
}

sint32 sub_8004F2C4(uint32 a1, sint32 a2)
{
    FUNCTION_MARKER(0x8004F2C4u, "SLES_008.65");
    if (a2 != 0)
    {
        uint32 result = r_u32(a1 + 208u) | 8u;
        w_u32(a1 + 208u, result);
        return (sint32)result;
    }
    uint32 effect = r_u32(a1 + 100u);
    w_u32(a1 + 208u, r_u32(a1 + 208u) & ~8u);
    if (effect != 0u)
        /* TODO Existing binding requires unavailable guest stack carrier */
        return (sint32)ob_draft_unresolved_call(0x80045F20u, 1u, a1 + 100u);
    return -9;
}

uint32 sub_80027710(uint32 a1)
{
    FUNCTION_MARKER(0x80027710u, "SLES_008.65");
    uint32 result = sub_80027AE4(r_u16(a1 + 38u));
    if (result != 0u)
    {
        result = r_u32(r_u32(result) + 8u);
        if (result != 0u)
        {
            /* TODO: Indirect guest callback requires the declared adapter */
            return ob_draft_unresolved_call(result, 1u, r_u32(a1 + 24u));
        }
    }
    return result;
}

sint32 sub_8001DFF0(void)
{
    FUNCTION_MARKER(0x8001DFF0u, "SLES_008.65");
    sint32 result = r_u8(0x8006C00Cu);
    if (result != 0)
    {
        if (r_u8(0x8006C00Du) != 0u)
            sub_8001DDA0();
        ob_draft_unresolved_call(0x8006272Cu, 2u, 0u, 0xFFFFFFu);
        result = (sint32)ob_draft_unresolved_call(0x80061034u, 0u);
        w_u8(0x8006C00Cu, 0u);
    }
    return result;
}

uint32 sub_800629C4(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x800629C4u, "SLES_008.65");
    uint32 length = a2 > 0x7EFF0u ? 0x7EFF0u : a2;
    xport_bind_native_spu_transfer();
    SpuWrite((uint8 *)psx_addr(a1, length), length);
    if (r_u32(0x80076374u) == 0u)
        w_u32(0x80076370u, 0u);
    return length;
}

sint32 sub_80024548(void)
{
    FUNCTION_MARKER(0x80024548u, "SLES_008.65");
    w_u8(0x8008AE6Cu, 12u);
    w_u8(0x8008AE6Du, 6u);
    w_u8(0x8008AE6Eu, 1u);
    w_u8(0x8008AE69u, 0u);
    w_u32(0x8006C134u, 0u);
    w_u32(0x8006C138u, 0u);
    w_u32(0x8006C13Cu, 0u);
    w_u32(0x800C4D18u, 0u);
    ob_draft_unresolved_call(0x8009450Cu, 3u, 0u, 0u, 0u);
    ob_draft_unresolved_call(0x80093D00u, 1u, r_u32(0x800C4D18u));
    w_u32(0x800C8390u, 1u);
    w_u32(0x800C8488u, 0u);
    w_u16(0x80089B24u, 0u);
    w_u32(0x80084444u, 0u);
    ob_draft_unresolved_call(0x80055FD8u, 2u, 0u, r_u32(0x80089900u));
    ob_draft_unresolved_call(0x80055D74u, 0u);
    ob_draft_unresolved_call(0x80095494u, 0u);
    sub_8004B6AC();
    nullsub_25();
    ob_draft_unresolved_call(0x800A5520u, 0u);
    ob_draft_unresolved_call(0x800170B8u, 0u);
    ob_draft_unresolved_call(0x8004F064u, 0u);
    return (sint32)sub_80045F4C(80u);
}

sint32 sub_8001F874(void)
{
    FUNCTION_MARKER(0x8001F874u, "SLES_008.65");
    sint32 result = r_u8(0x8006C00Cu);
    if (result != 0)
    {
        uint32 temporaries = ob_draft_scratch_acquire(56u);
        uint32 command = temporaries + 40u;
        ob_draft_unresolved_call(0x80055D74u, 0u);
        w_u8(command, 5u);
        while (ob_draft_unresolved_call(0x800562ACu, 3u, 14u, command, 0u) != 1u) { }
        do
        {
            w_u32(0x80078DB0u, ob_draft_unresolved_call(0x80055B2Cu, 1u, 0x80078CB0u));
        } while (r_s32(0x80078DB0u) < 0);
        w_u8(0x8006C012u, 1u);
        w_u32(temporaries, 960u);
        w_u32(temporaries + 24u, 1u);
        w_u8(0x8006C013u, 0u);
        w_u8(0x80078DBCu, 0u);
        w_u32(temporaries + 20u, 0u);
        w_u16(temporaries + 16u, 0x7FFFu);
        w_u16(temporaries + 18u, 0x7FFFu);
        ob_draft_unresolved_call(0x80062B54u, 1u, temporaries);
        ob_draft_scratch_release(temporaries);
        result = r_u8(0x8006C00Du);
        if (result != 0)
            return (sint32)ob_draft_unresolved_call(0x80061748u, 1u, 1u);
    }
    return result;
}

sint32 sub_80034234(void)
{
    FUNCTION_MARKER(0x80034234u, "SLES_008.65");
    uint32 node = r_u32(0x80077594u);
    /* TODO: Original result is unspecified when the list is empty */
    sint32 result;
    if (node == 0u)
        return (sint32)ob_draft_unresolved_call(0x80034234u, 0u);
    do
    {
        sint32 type = r_s16(node + 4u);
        result = type < 2;
        if (type == 0)
            result = (sint32)sub_800342F0(r_u32(node + 8u));
        else if (type == 1 || type == 2)
            result = sub_80034430(r_u32(node + 8u));
        else if (type >= 2)
        {
            result = 3;
            if (type == 3)
                result = (sint32)ob_draft_unresolved_call(0x80034500u, 1u, r_u32(node + 8u));
        }
        node = r_u32(node);
    } while (node != 0u);
    return result;
}

sint32 sub_80054A24(sint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80054A24u, "SLES_008.65");
    uint32 cell = ob_draft_scratch_acquire(4u);
    w_u32(cell, 0u);
    sub_800262CC(cell, 24);
    uint32 node = r_u32(cell);
    if (node == 0u)
    {
        ob_draft_scratch_release(cell);
        return 0;
    }
    uint32 next = r_u32(0x800771D4u);
    uint32 now = r_u32(0x800771D8u);
    w_u32(node + 12u, 0u);
    w_u32(node + 16u, 0u);
    w_u32(node + 20u, (uint32)a1);
    w_u32(node, next);
    uint32 interval = a2 != 0u ? 0x3840u / a2 : ob_draft_unresolved_call(0x80054A80u, 1u, 7u);
    w_u32(node + 4u, interval);
    w_u32(node + 8u, now + interval);
    sub_800558E4();
    w_u32(0x800771D4u, r_u32(cell));
    sub_800558F4();
    uint32 result = r_u32(cell);
    ob_draft_scratch_release(cell);
    return (sint32)result;
}

sint32 sub_80024D54(uint32 a1)
{
    FUNCTION_MARKER(0x80024D54u, "SLES_008.65");
    uint32 previous = r_u8(0x8006C22Eu);
    uint32 step = a1 - 1u;
    /* TODO: Original result carrier is unspecified for a1 equal to one */
    if (a1 == 1u)
        return (sint32)ob_draft_unresolved_call(0x80024DE8u, 0u);
    sint32 result;
    do
    {
        uint32 product = step * r_u8(0x8006C22Eu);
        uint32 volume = a1 != 0u ? product / a1 : ob_draft_unresolved_call(0x80024DA8u, 1u, 7u);
        sint32 difference = (sint32)previous - (sint32)(volume & 255u);
        result = difference < 3;
        if (difference >= 3)
        {
            result = sub_8001DF58(volume);
            previous = volume & 255u;
        }
        --step;
    } while (step != 0u);
    return result;
}

sint32 sub_8004CD2C(void)
{
    FUNCTION_MARKER(0x8004CD2Cu, "SLES_008.65");
    uint32 table = r_u32(0x80077644u);
    uint32 numerator = r_u32(0x800843D8u) + r_u32(0x80077458u);
    sint32 first = draft_c_divide((sint32)numerator, r_s32(table), 0x8004CD58u);
    w_u8(0x80077424u, (uint32)first);
    numerator = r_u32(0x80077468u) - r_u32(0x800843E0u);
    sint32 second = draft_c_divide((sint32)numerator, r_s32(table), 0x8004CDC8u);
    w_u32(0x80077494u, ((uint32)first & 0xF0u) - 16u);
    w_u8(0x80077425u, (uint32)second);
    uint32 result = ((uint32)second & 0xF0u) - 16u;
    w_u32(0x8007749Cu, result);
    return (sint32)result;
}

sint32 sub_80025CB4(uint32 a1, sint32 a2)
{
    FUNCTION_MARKER(0x80025CB4u, "SLES_008.65");
    sint32 file = (sint32)sub_80054EFC((uint32)a2);
    if (file < 0)
        return 0;
    uint32 length = sub_800556D8((uint32)file);
    sub_80026694(a1, length, 1u);
    uint32 received = sub_800553D0(r_u32(a1), length, (uint32)file);
    sub_800551B0((uint32)file);
    return received == length ? (sint32)received : 0;
}

sint32 sub_80044DBC(uint32 a1, uint32 a2, uint32 a3, sint32 a4)
{
    FUNCTION_MARKER(0x80044DBCu, "SLES_008.65");
    w_u32(0x80077448u, (uint32)a4);
    sub_80029E30(a1, 0x800843D8u);
    sub_8002B7FC(a2, 0x80084388u);
    sub_80029E30(a3, 0x800843A0u);
    sub_8002F9C4(0x80086B70u, 0x80084388u);
    sub_8002FAA8(0x80086B70u, 0x800843D8u);
    return (sint32)sub_8002F4CC(0x80086B70u);
}

uint32 sub_80045ADC(uint32 a1)
{
    FUNCTION_MARKER(0x80045ADCu, "SLES_008.65");
    uint32 flags = r_u32(a1 + 160u);
    if (r_u32(a1 + 132u) != 0u || r_u32(a1 + 136u) != 0u || r_u32(a1 + 140u) != 0u)
        flags &= ~0x10u;
    else
        flags |= 0x10u;
    w_u32(a1 + 160u, flags);
    w_u32(a1 + 160u, r_u32(a1 + 160u) | 0x20u);
    sub_80045204(a1);
    uint32 result = r_u32(a1 + 160u) & ~0x20u;
    w_u32(a1 + 160u, result);
    return result;
}

sint32 sub_800283DC(uint32 a1, sint32 a2)
{
    FUNCTION_MARKER(0x800283DCu, "SLES_008.65");
    sint32 divisor_signed = (sint16)a2;
    if (divisor_signed < 0)
        divisor_signed = (sint16)(0u - (uint32)divisor_signed);
    uint32 divisor = (uint32)divisor_signed;
    if (divisor == 0u)
    {
        xport_mips_break(7u);
        return -1;
    }
    uint32 remainder = a1 % divisor;
    uint32 whole = a1 / divisor;
    uint32 fraction_numerator = remainder << 14;
    uint32 fraction = fraction_numerator / divisor;
    if (divisor < 2u * (fraction_numerator % divisor))
        ++fraction;
    if (whole > 0x3FFFFu)
        return -1;
    uint32 base = whole << 14;
    if (fraction > 0xFFFFFFFFu - base)
        return -1;
    return (sint32)(base + fraction);
}

sint32 sub_8002CEB0(uint32 a1)
{
    FUNCTION_MARKER(0x8002CEB0u, "SLES_008.65");
    uint32 packet = r_u32(0x8007741Cu);
    w_u32(packet + 8u, a1);
    w_u32(packet + 12u, a1 + 40u);
    ob_draft_unresolved_call(0x8005ABC0u, 5u, 0x80086A48u, r_u32(a1 + 48u),
        (uint32)r_s16(0x80086B36u) + r_u32(a1 + 52u), r_u32(a1 + 64u), r_u32(a1 + 68u));
    return (sint32)ob_draft_unresolved_call(0x8005ABC0u, 5u, 0x80086AD8u, r_u32(a1 + 48u),
        (uint32)r_s16(0x80086AA6u) + r_u32(a1 + 52u), r_u32(a1 + 64u), r_u32(a1 + 68u));
}

sint32 sub_8004E310(uint32 a1, sint32 a2)
{
    FUNCTION_MARKER(0x8004E310u, "SLES_008.65");
    uint32 input = r_u32(a1 + 32u);
    ob_draft_unresolved_call(0x8005F398u, 1u, (uint32)a2);
    ob_draft_unresolved_call(0x8005F428u, 1u, 0x8007FE08u);
    sint32 result = r_u16(0x80077388u);
    uint32 output = r_u32(0x80077574u);
    uint32 index = 0u;
    if (result != 0)
    {
        do
        {
            /* TODO: Inline GTE MVMVA 0x480012 stores MAC1/MAC2/MAC3 as halfwords */
            ob_draft_unresolved_call(0x8004E354u, 3u, input, output + 8u, 0x480012u);
            input += 8u;
            ++index;
            result = index < r_u16(0x80077388u);
            output += 24u;
        } while (result != 0);
    }
    return result;
}

sint32 sub_8005491C(void)
{
    FUNCTION_MARKER(0x8005491Cu, "SLES_008.65");
    uint32 result = r_u32(0x800771DCu) + 1u;
    w_u32(0x800771DCu, result);
    if (result == 1u)
    {
        w_u32(0x800771D8u, 0u);
        w_u32(0x800771D4u, 0u);
        w_u32(0x800896BCu, 0u);
        w_u32(0x800896ECu, 0u);
        w_u32(0x80084A48u, 0u);
        w_u32(0x800882B8u, ob_draft_unresolved_call(0x80055884u, 4u, 0xF2000001u, 2u, 4096u, 0x80054780u));
        ob_draft_unresolved_call(0x80055984u, 3u, 0xF2000001u, 2880u, 4096u);
        ob_draft_unresolved_call(0x80055A5Cu, 1u, 0xF2000001u);
        w_u32(0x800771E0u, 0u);
        return (sint32)ob_draft_unresolved_call(0x800558B4u, 1u, r_u32(0x800882B8u));
    }
    return (sint32)result;
}

sint32 sub_80026EB8(sint32 a1)
{
    FUNCTION_MARKER(0x80026EB8u, "SLES_008.65");
    uint32 node = r_u32(0x8007722Cu);
    if (node == (uint32)a1)
        return 0;
    do
    {
        if ((r_u8(node + 32u) & 2u) != 0u && r_u16(node + 36u) == 0u && r_u16(node + 34u) == 0u)
            break;
        node = r_u32(node + 8u);
    } while (node != (uint32)a1);
    if (node == (uint32)a1)
        return 0;
    uint32 result = r_u32(node + 16u);
    sub_80026758(r_u32(node + 24u));
    return (sint32)result;
}

sint32 sub_80045094(uint32 a1)
{
    FUNCTION_MARKER(0x80045094u, "SLES_008.65");
    uint32 child;
    while ((child = r_u32(a1 + 32u)) != 0u)
    {
        if (r_u32(child + 12u) == a1)
            sub_80045124(child);
        else
            ob_draft_unresolved_call(0x80045D0Cu, 1u, child);
    }
    /* TODO Existing binding requires unavailable result and stack carriers */
    ob_draft_unresolved_call(0x80043974u, 1u, a1 + 144u);
    if (r_u32(a1 + 24u) != 0u)
        sub_8004514C(a1);
    w_u32(a1 + 8u, 0u);
    return (sint32)sub_80043664(a1);
}

sint32 sub_8004E584(uint32 a1, sint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x8004E584u, "SLES_008.65");
    sub_80043600(a1, a2, r_s32(a3));
    w_u32(a1, 0x800771A0u);
    uint32 selector = r_u32(a3 + 4u);
    uint32 component = selector != 0u ? sub_80043824(r_u32(a1 + 12u), 0x80077104u, selector)
        : sub_8004378C(r_u32(a1 + 12u), 0x80077104u);
    w_u32(a1 + 24u, component);
    return (sint32)sub_8004A2EC(a1);
}

sint32 sub_80024320(void)
{
    FUNCTION_MARKER(0x80024320u, "SLES_008.65");
    uint32 temporary = ob_draft_scratch_acquire(104u);
    ob_draft_unresolved_call(0x8005ABC0u, 5u, temporary, 0u, 0u, 1024u, 512u);
    w_u8(temporary + 23u, 1u);
    w_u8(temporary + 24u, 0u);
    ob_draft_unresolved_call(0x8005CB78u, 1u, temporary);
    w_u16(temporary + 100u, 1023u);
    w_u16(temporary + 96u, 0u);
    w_u16(temporary + 98u, 0u);
    w_u16(temporary + 102u, 511u);
    ob_draft_unresolved_call(0x8005C698u, 4u, temporary + 96u, 0u, 0u, 0u);
    uint32 result = ob_draft_unresolved_call(0x8005C504u, 1u, 0u);
    ob_draft_scratch_release(temporary);
    return (sint32)result;
}

sint32 sub_8002FE50(sint32 a1, uint32 a2, sint32 a3)
{
    FUNCTION_MARKER(0x8002FE50u, "SLES_008.65");
    uint32 flags = r_u32(a2 + 48u);
    if ((flags & 2u) == 0u)
        /* TODO Bind external target with the recovered object and vector */
        ob_draft_unresolved_call(0x8002F594u, 2u, a2, (flags & 1u) != 0u ? a2 + 70u : 0x800770DCu);
    return (sint32)sub_8002FED4((uint32)a1, a2, (uint32)a3);
}

sint32 sub_8004795C(uint32 a1)
{
    FUNCTION_MARKER(0x8004795Cu, "SLES_008.65");
    sint32 count = r_s32(a1 + 24u);
    w_u32(a1 + 196u, 0x7FFFFFFFu);
    uint32 table = r_u32(0x80077148u);
    w_u32(a1 + 200u, 0xFFFFFFFFu);
    uint32 result = table + 4u * (uint32)count;
    uint32 entry = r_u32(result);
    for (sint32 index = 0; index < count; ++index)
    {
        if ((r_u32(entry) & 0x8000u) == 0u)
        {
            sint32 distance = r_s32(entry + 4u);
            if (distance < r_s32(a1 + 196u))
            {
                w_u32(a1 + 200u, (uint32)index);
                w_u32(a1 + 196u, (uint32)distance);
            }
        }
        entry += 8u;
        result = index + 1 < count;
    }
    return (sint32)result;
}

sint32 sub_80044CD4(uint32 a1)
{
    FUNCTION_MARKER(0x80044CD4u, "SLES_008.65");
    uint32 resource = r_u32(a1 + 12u);
    if (resource != 0u)
        sub_800256CC(resource);
    sint32 count = r_s32(a1 + 4u);
    uint32 next = a1 + 20u;
    for (sint32 index = 0; index < count; ++index)
        next = (uint32)sub_80044CD4(next);
    return (sint32)next;
}

uint32 sub_800491B0(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    FUNCTION_MARKER(0x800491B0u, "SLES_008.65");
    uint32 flags = r_u32(a4);
    uint32 packet = r_u32(0x800770F4u);
    uint32 shape = flags & 3u;
    uint32 command = flags & 0xF8u;
    if (shape != 1u && shape != 2u)
        return 128u;
    if (command != 8u && command != 16u && command != 32u && !(shape == 2u && command == 64u))
        return 128u;
    /* TODO: Common pair-store helper must preserve the fifth packet argument */
    ob_draft_unresolved_call(0x80048978u, 5u, a1, a2, a3, a4, packet);
    if (shape == 1u)
    {
        if (command == 8u)
            return ob_draft_unresolved_call(0x80049318u, 1u, packet);
        if (command == 32u)
            return sub_800493F8(packet);
        return sub_8004954C(packet);
    }
    if (command == 8u)
        return sub_800496D8(packet);
    if (command == 32u)
        return ob_draft_unresolved_call(0x800499C0u, 1u, packet);
    if (command == 16u)
        return sub_80049A10(packet);
    return ob_draft_unresolved_call(0x80049CECu, 1u, packet);
}



