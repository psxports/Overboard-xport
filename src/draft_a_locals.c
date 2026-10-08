#include "draft_signatures.h"

/* Unverified drafts with actual local objects in guest scratch */
uint32 sub_80046184(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x80046184u, "SLES_008.65");
    uint32 local = ob_draft_scratch_acquire(4u);
    w_u32(local, 0u);
    sub_800262CC(local, 268);
    uint32 result = r_u32(local);
    sub_800461E8(result, a1, a2, a3);
    ob_draft_scratch_release(local);
    return result;
}

uint32 sub_80043E3C(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80043E3Cu, "SLES_008.65");
    uint32 local = ob_draft_scratch_acquire(8u);
    w_u32(local, 0u);
    w_u32(local + 4u, a2);
    sub_800262CC(local, 164);
    uint32 result = r_u32(local);
    sub_80043EAC(result, a1, local + 4u);
    ob_draft_scratch_release(local);
    return result;
}

uint32 sub_80044E5C(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x80044E5Cu, "SLES_008.65");
    uint32 local = ob_draft_scratch_acquire(8u);
    w_u32(local, 0u);
    w_u32(local + 4u, a2);
    sub_800262CC(local, 164);
    uint32 result = r_u32(local);
    sub_80044EDC(result, a1, local + 4u, a3);
    ob_draft_scratch_release(local);
    return result;
}

uint32 sub_8004F31C(uint32 a1)
{
    FUNCTION_MARKER(0x8004F31Cu, "SLES_008.65");
    uint32 local = ob_draft_scratch_acquire(4u);
    uint32 state = r_u32(a1 + 92u);
    w_u32(local, a1);
    if (state != 0u) sub_8004F288(a1);
    /* TODO Bind the handle release helper outside the chosen set */
    uint32 result = ob_draft_unresolved_call(0x800263B4u, 1u, local);
    ob_draft_scratch_release(local);
    return result;
}

uint32 sub_8004E644(uint32 a1)
{
    FUNCTION_MARKER(0x8004E644u, "SLES_008.65");
    uint32 local = ob_draft_scratch_acquire(4u);
    w_u32(local, a1);
    sub_8004E614(a1);
    /* TODO Bind the handle release helper outside the chosen set */
    uint32 result = ob_draft_unresolved_call(0x800263B4u, 1u, local);
    ob_draft_scratch_release(local);
    return result;
}

uint32 sub_80051400(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80051400u, "SLES_008.65");
    uint32 local = ob_draft_scratch_acquire(16u);
    w_u32(local, (r_u32(a1) << 8) + r_u32(0x800775A8u));
    w_u32(local + 8u, r_u32(0x800775B0u) - (r_u32(a1 + 8u) << 8));
    uint32 result = sub_80051450(local, a2);
    ob_draft_scratch_release(local);
    return result;
}

uint32 sub_800340A0(uint32 a1)
{
    FUNCTION_MARKER(0x800340A0u, "SLES_008.65");
    uint32 local = ob_draft_scratch_acquire(4u);
    w_u32(local, 0u);
    sub_800262CC(local, 48);
    uint32 value = r_u8(a1 + 11u);
    if (value == 0u) value = r_u8(a1 + 12u);
    uint32 result = r_u32(local);
    w_u16(result + 8u, value);
    uint32 frame = r_u16(a1 + 4u);
    w_u16(result + 10u, frame);
    w_u32(result + 44u, frame + r_u32(0x800882BCu));
    w_u32(0x80077578u, result + 12u);
    ob_draft_scratch_release(local);
    return result;
}

uint32 sub_80033FB0(uint32 a1)
{
    FUNCTION_MARKER(0x80033FB0u, "SLES_008.65");
    uint32 local = ob_draft_scratch_acquire(4u);
    w_u32(local, 0u);
    sub_800262CC(local, 12);
    uint32 record = r_u32(local);
    if (r_u32(0x80077594u) != 0u) w_u32(r_u32(0x80077564u), record);
    else w_u32(0x80077594u, record);
    w_u32(record, 0u);
    uint32 flags = r_u16(a1 + 6u);
    w_u32(0x80077564u, record);
    if ((flags & 0x8000u) != 0u)
    {
        w_u16(record + 4u, 0u);
        w_u32(record + 8u, sub_800340A0(a1));
    }
    uint32 result = r_u16(a1 + 6u), type = (result & 0x6000u) >> 13;
    if (type != 0u)
    {
        w_u32(0x800773A8u, a1);
        w_u16(record + 4u, type);
        /* TODO Bind the texture type 3 adapter with its meaningful type carrier */
        result = type == 3u ? ob_draft_unresolved_call(0x800341A4u, 2u, a1, type) : sub_80034114(a1, type);
        w_u32(record + 8u, result);
    }
    ob_draft_scratch_release(local);
    return result;
}

uint32 sub_80016B88(uint32 a1)
{
    FUNCTION_MARKER(0x80016B88u, "SLES_008.65");
    uint32 data;
    if ((r_u32(a1) & 3u) != 0u) data = sub_800257CC(a1);
    else
    {
        uint32 refs = r_u32(a1) - 6u;
        w_u16(refs, r_u16(refs) + 1u);
        data = r_u32(a1);
    }
    uint32 rect = ob_draft_scratch_acquire(8u);
    w_u16(rect, 0u);
    w_u16(rect + 2u, (r_u32(0x800773D0u) == 0u) << 8);
    w_u16(rect + 4u, 384u);
    w_u16(rect + 6u, 256u);
    /* TODO Bind the SDK image transfer adapter */
    ob_draft_unresolved_call(0x8005C7C8u, 2u, rect, data + 20u);
    ob_draft_scratch_release(rect);
    return sub_800257A0(a1);
}

uint32 sub_800223A0(uint32 a1)
{
    FUNCTION_MARKER(0x800223A0u, "SLES_008.65");
    sint32 index = (sint32)a1;
    uint32 rect = ob_draft_scratch_acquire(8u), second = (uint32)(index / 12) << 6;
    uint32 active = r_u32(0x800773D0u);
    w_u16(rect, (uint32)(index % 12) * 32u);
    w_u16(rect + 2u, active != 0u ? second : second + 256u);
    w_u16(rect + 4u, 32u);
    w_u16(rect + 6u, 64u);
    /* TODO Bind SDK image movement */
    uint32 result = ob_draft_unresolved_call(0x8005C890u, 3u, rect, 176u,
        active != 0u ? 352u : 96u);
    ob_draft_scratch_release(rect);
    return result;
}

uint32 sub_800129FC(uint32 a1)
{
    FUNCTION_MARKER(0x800129FCu, "SLES_008.65");
    uint32 buffer = ob_draft_scratch_acquire(128u);
    /* TODO Bind SDK buffer clear and card reads */
    ob_draft_unresolved_call(0x80063FD8u, 3u, buffer, 0u, 128u);
    sub_8001237C();
    uint32 descriptor;
    do { descriptor = sub_80013794(a1); }
    while (ob_draft_unresolved_call(0x80063BC4u, 3u, descriptor, 0u, buffer) == 0u);
    uint32 result = 0u;
    if (sub_800122EC() == 0u && r_u8(buffer) == 77u) result = r_u8(buffer + 1u) == 67u;
    ob_draft_scratch_release(buffer);
    return result;
}

uint32 sub_80024B40(void)
{
    FUNCTION_MARKER(0x80024B40u, "SLES_008.65");
    /* TODO Bind guest callbacks */
    ob_draft_unresolved_call(r_u32(0x800A2D74u), 1u, r_u32(0x800882BCu));
    return ob_draft_unresolved_call(r_u32(0x80093C44u), 1u, 0u);
}

void sub_80058D98(void)
{
    FUNCTION_MARKER(0x80058D98u, "SLES_008.65");
    sub_800558E4();
    /* TODO Bind the SDK shutdown adapters */
    ob_draft_unresolved_call(0x80056438u, 1u, 0u);
    ob_draft_unresolved_call(0x80056030u, 1u, 0u);
    w_u8(r_u32(0x80073E44u), 0u);
    w_u8(r_u32(0x80073E50u), 0u);
    sub_800558F4();
}

uint32 sub_80046E6C(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80046E6Cu, "SLES_008.65");
    sub_80046EAC(a1, a2);
    return sub_80047050(a1, a2);
}

uint32 sub_800425EC(uint32 a1, uint32 a2, uint32 a3, uint32 a4,
    uint32 a5, uint32 a6, uint32 a7)
{
    FUNCTION_MARKER(0x800425ECu, "SLES_008.65");
    sub_8002CCC8(a1, a2, a3, a4, a5, a6, a7);
    sub_80042644(a1);
    w_u32(a1 + 152u, 0x7F645459u);
    return 1u;
}
