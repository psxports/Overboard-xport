#include "draft_signatures.h"
#include "native_timers.h"
#include "psx.h"

/* Unverified draft bodies */
uint32 sub_80026734(uint32 a1, uint32 requested_size)
{
    FUNCTION_MARKER(0x80026734u, "SLES_008.65");
    return ob_draft_unresolved_call(0x80027274u, 2u, r_u32(a1) - 40u, requested_size);
}

uint32 sub_80026898(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80026898u, "SLES_008.65");
    uint32 payload = r_u32(a1);
    w_u16(payload - 2u, a2);
    return sub_800276B4(payload - 40u);
}

uint32 sub_800268E8(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x800268E8u, "SLES_008.65");
    uint32 payload = r_u32(a1);
    /* TODO Bind the SDK memory fill adapter */
    return ob_draft_unresolved_call(0x80063FD8u, 3u, payload, a2 & 255u,
        r_u32(payload - 24u) - r_u32(payload - 20u));
}

uint32 sub_80026758(uint32 a1)
{
    FUNCTION_MARKER(0x80026758u, "SLES_008.65");
    uint32 block = r_u32(a1) - 40u;
    sub_800269D0(block);
    /* TODO Bind helpers outside the chosen translation set */
    ob_draft_unresolved_call(0x80027978u, 1u, block);
    return ob_draft_unresolved_call(0x80027154u, 1u, block);
}

uint32 sub_80011DC0(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80011DC0u, "SLES_008.65");
    return sub_8001F5DC(a1, a2 & 255u);
}

uint32 sub_80011DF0(uint32 a1, uint32 product_low)
{
    FUNCTION_MARKER(0x80011DF0u, "SLES_008.65");
    if ((sint32)product_low < 0) product_low += 255u;
    return sub_8001F64C(a1, (product_low >> 8) & 255u);
}

uint32 sub_80012184(void)
{
    FUNCTION_MARKER(0x80012184u, "SLES_008.65");
    return sub_8001E540();
}

void sub_80054CEC(void)
{
    FUNCTION_MARKER(0x80054CECu, "SLES_008.65");
    w_u32(0x800771E0u, 0u);
}

void nullsub_18(void)
{
    FUNCTION_MARKER(0x8001B058u, "SLES_008.65");
}

void sub_8005F468(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8005F468u, "SLES_008.65");
    xport_gte_write_control(24u, a1 << 16);
    xport_gte_write_control(25u, a2 << 16);
}

void sub_800558F4(void)
{
    FUNCTION_MARKER(0x800558F4u, "SLES_008.65");
    xport_bios_exit_critical();
    ob_native_timers_critical(1u);
}

void sub_80063CD8(void)
{
    FUNCTION_MARKER(0x80063CD8u, "SLES_008.65");
    /* TODO Bind BIOS B0 selector 0x4A */
    ob_draft_unresolved_call(0xB0u, 1u, 0x4Au);
}

uint32 sub_80017554(void)
{
    FUNCTION_MARKER(0x80017554u, "SLES_008.65");
    sub_80026758(0x8006601Cu);
    uint32 result = r_u32(0x80066028u);
    if (result == 0u) result = sub_80026758(0x80066020u);
    w_u32(0x80066024u, 0u);
    return result;
}

uint32 sub_80045490(uint32 a1)
{
    FUNCTION_MARKER(0x80045490u, "SLES_008.65");
    /* TODO Bind the omitted incoming helper carriers */
    ob_draft_unresolved_call(0x80045758u, 0u);
    return a1 + 80u;
}

uint32 sub_8004E614(uint32 a1)
{
    FUNCTION_MARKER(0x8004E614u, "SLES_008.65");
    sub_8004A410(a1);
    /* TODO Bind helper outside the chosen translation set */
    return ob_draft_unresolved_call(0x80043664u, 1u, a1);
}

uint32 sub_80045A44(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80045A44u, "SLES_008.65");
    uint32 y = r_u32(a2 + 4u);
    uint32 z = r_u32(a2 + 8u);
    w_u32(a1 + 132u, r_u32(a2));
    w_u32(a1 + 136u, y);
    w_u32(a1 + 140u, z);
    return sub_80045ADC(a1);
}

uint32 sub_80045378(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x80045378u, "SLES_008.65");
    sub_800455DC(a1, a2);
    uint32 x = r_u32(a1 + 108u);
    uint32 y = r_u32(a1 + 112u);
    uint32 z = r_u32(a1 + 116u);
    w_u32(a3, x);
    w_u32(a3 + 4u, y);
    w_u32(a3 + 8u, z);
    return x;
}

uint32 sub_800292B0(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x800292B0u, "SLES_008.65");
    uint32 shift = sub_800292EC(a1, a2);
    return ((uint32)sub_80028614(a2) & 65535u) << (shift & 31u);
}

uint32 sub_800257CC(uint32 a1)
{
    FUNCTION_MARKER(0x800257CCu, "SLES_008.65");
    if ((r_u32(a1) & 3u) == 1u)
    {
        sub_80025A9C(a1);
        if ((r_u32(a1) & 3u) == 0u)
        {
            uint32 refs = r_u32(a1) - 6u;
            w_u16(refs, r_u16(refs) + 1u);
        }
    }
    return r_u32(a1);
}

uint32 sub_80025700(uint32 a1)
{
    FUNCTION_MARKER(0x80025700u, "SLES_008.65");
    uint32 handle = sub_80027DF8(a1 & 65535u);
    if ((r_u32(handle) & 3u) != 0u) return sub_800257CC(handle);
    uint32 refs = r_u32(handle) - 6u;
    w_u16(refs, r_u16(refs) + 1u);
    return r_u32(handle);
}

uint32 sub_800292EC(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x800292ECu, "SLES_008.65");
    uint32 x = r_u32(a1), y = r_u32(a1 + 4u), z = r_u32(a1 + 8u);
    if ((sint32)x < 0) x = 0u - x;
    if ((sint32)y < 0) y = 0u - y;
    if ((sint32)z < 0) z = 0u - z;
    uint32 magnitude = x | y | z, shift = 0u;
    while (magnitude > 32767u) { magnitude >>= 1; ++shift; }
    w_u16(a2, (uint32)(r_s32(a1) >> shift));
    w_u16(a2 + 2u, (uint32)(r_s32(a1 + 4u) >> shift));
    w_u16(a2 + 4u, (uint32)(r_s32(a1 + 8u) >> shift));
    return shift;
}

uint32 sub_80046124(uint32 a1)
{
    FUNCTION_MARKER(0x80046124u, "SLES_008.65");
    uint32 table = r_u32(0x80077140u);
    w_u32(table + a1 * 4u, 0u);
    if (a1 == r_u32(0x80077260u))
    {
        uint32 index = a1 - 1u;
        while ((sint32)index >= 0 && r_u32(table + index * 4u) == 0u) --index;
        w_u32(0x80077260u, index);
    }
    uint32 result = r_u32(0x8007755Cu) + 1u;
    w_u32(0x8007755Cu, result);
    return result;
}

uint32 sub_800480A8(uint32 a1)
{
    FUNCTION_MARKER(0x800480A8u, "SLES_008.65");
    sint32 maximum = r_s32(a1 + 76u);
    if (maximum < r_s32(a1 + 80u)) maximum = r_s32(a1 + 80u);
    if (r_s32(a1 + 72u) > maximum) maximum = r_s32(a1 + 72u);
    if (maximum >= 0) return sub_80048124(a1);
    uint32 result = r_u32(a1 + 20u);
    uint32 flags = r_u32(result);
    w_u32(result + 4u, r_u32(a1));
    w_u32(result, flags | 0x8000u);
    return result;
}

uint32 sub_80045204(uint32 a1)
{
    FUNCTION_MARKER(0x80045204u, "SLES_008.65");
    uint32 cursor = r_u32(a1 + 144u);
    uint32 result = r_u32(cursor);
    while (result != 0u)
    {
        uint32 object = r_u32(cursor + 20u);
        if (object != 0u)
        {
            /* TODO Resolve the guest callback target */
            ob_draft_unresolved_call(r_u32(cursor + 36u), 3u, object,
                r_u32(cursor + 32u), r_u32(a1 + 72u));
        }
        cursor = r_u32(cursor);
        result = r_u32(cursor);
    }
    return result;
}

uint32 sub_800486E4(uint32 a1)
{
    FUNCTION_MARKER(0x800486E4u, "SLES_008.65");
    uint32 contact = r_u32(a1 + 20u);
    w_u32(contact, r_u32(contact) | 0x8000u);
    uint32 result;
    if (r_s32(a1 + 72u) < 0 && r_s32(a1 + 76u) < 0 && r_s32(a1 + 80u) < 0)
    {
        if ((r_u32(a1 + 60u) | r_u32(a1 + 64u) | r_u32(a1 + 68u)) != 0u)
        {
            /* TODO Bind the existing collision normalization stack adapter */
            ob_draft_unresolved_call(0x80048B60u, 1u, a1);
            sub_80048BF4(a1);
            result = r_u32(a1 + 108u);
        }
        else result = 2147483393u;
    }
    else result = r_u32(a1);
    w_u32(contact + 4u, result);
    return result;
}

uint32 sub_80046BE8(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    FUNCTION_MARKER(0x80046BE8u, "SLES_008.65");
    if (((r_u32(a1 + 136u) & r_u32(a2 + 172u)) != 0u ||
        (r_u32(a2 + 136u) & r_u32(a1 + 172u)) != 0u) &&
        (r_u32(a1 + 28u) | r_u32(a2 + 28u)) == 0u)
    {
        w_u32(a3, 8u);
        uint32 flags = 9u;
        if ((r_u32(a1 + 136u) & r_u32(a2 + 140u)) == 0u &&
            (r_u32(a2 + 136u) & r_u32(a1 + 140u)) == 0u) flags = 10u;
        w_u32(a3, flags);
        return sub_800477B8(a1, a2, a4, a3);
    }
    w_u32(a3, 128u);
    w_u32(a3 + 4u, 0x7FFFFFFFu);
    return 128u;
}

uint32 sub_8004F478(uint32 a1, uint32 a3)
{
    FUNCTION_MARKER(0x8004F478u, "SLES_008.65");
    if (r_u32(a1 + 152u) == a3) return sub_8004F758(a1, a3);
    sub_8004F610(a1, a3);
    w_u32(a1 + 156u, 2147483393u);
    w_u32(a1 + 160u, 2147483393u);
    w_u32(a1 + 152u, a3);
    /* TODO Bind the existing ground collision helper stack adapter */
    ob_draft_unresolved_call(0x8004F354u, 1u, a1);
    w_u32(a1 + 208u, r_u32(a1 + 208u) & 0x7FFFFFFFu);
    /* TODO Supply omitted collision helper carriers */
    return ob_draft_unresolved_call(0x8004F51Cu, 1u, a1);
}

uint32 sub_8004CE64(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8004CE64u, "SLES_008.65");
    uint32 count = 0u, mask = (a2 | 0x90u) & 65535u;
    for (uint32 cursor = a1; cursor != 0u; cursor = r_u32(cursor + 32u))
    {
        if ((r_u16(cursor + 38u) & mask) == 0u)
        {
            uint32 flags = r_u16(cursor + 38u);
            w_u32(0x80077350u, r_u8(cursor + 54u));
            ++count;
            sub_800442F0(r_u32(cursor + 24u), r_u8(cursor + 55u) != 0u ? 0x4800u : 0u,
                (flags & 2u) == 0u);
            flags = r_u16(cursor + 38u);
            w_u8(cursor + 55u, 0u);
            w_u16(cursor + 38u, flags | 0x80u);
        }
    }
    return count;
}

uint32 sub_80047140(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80047140u, "SLES_008.65");
    if (r_u32(a1 + 180u) != 0u) sub_8004719C(a1, a2);
    uint32 result = r_u32(a1 + 184u);
    if (result != 0u) return sub_8004735C(a1, a2);
    return result;
}

uint32 sub_80046544(uint32 a1)
{
    FUNCTION_MARKER(0x80046544u, "SLES_008.65");
    uint32 count = r_u32(a1 + 28u);
    if (count == 0u)
    {
        sub_80046CAC(a1);
        sub_80045284(r_u32(a1 + 32u), a1 + 36u);
        count = r_u32(a1 + 28u);
    }
    w_u32(a1 + 28u, count + 1u);
    return count + 1u;
}

uint32 sub_800464BC(uint32 a1)
{
    FUNCTION_MARKER(0x800464BCu, "SLES_008.65");
    /* TODO Bind helpers outside the chosen translation set */
    ob_draft_unresolved_call(0x80043C18u, 1u, a1 + 36u);
    if (r_u32(a1 + 28u) == 0u) sub_80046CAC(a1);
    sub_80046124(r_u32(a1 + 24u));
    ob_draft_unresolved_call(0x80043C18u, 1u, a1 + 204u);
    return ob_draft_unresolved_call(0x80043664u, 1u, a1);
}

uint32 sub_8001F5DC(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8001F5DCu, "SLES_008.65");
    uint32 result = r_u8(0x8006C00Cu);
    if (result != 0u)
    {
        result = a1 < 24u;
        if (a1 != 0xFFFFFFFFu)
        {
            result = a1 * 8u;
            if (a1 < 24u)
            {
                uint32 voice = (uint32)-2146990780 + a1 * 28u;
                result = r_u32(voice) & 2u;
                if (result != 0u)
                {
                    w_u8(voice + 20u, a2);
                    return sub_8001FDA4(a1);
                }
            }
        }
    }
    return result;
}

uint32 sub_8001F64C(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8001F64Cu, "SLES_008.65");
    uint32 result = r_u8(0x8006C00Cu);
    if (result != 0u)
    {
        result = a1 < 24u;
        if (a1 != 0xFFFFFFFFu)
        {
            result = a1 * 8u;
            if (a1 < 24u)
            {
                result = a2 & 255u;
                uint32 voice = (uint32)-2146990780 + a1 * 28u;
                if ((r_u32(voice) & 2u) != 0u)
                {
                    uint64_t scaled = UINT64_C(2155905153) * result * r_u8(0x8006C010u);
                    w_u8(voice + 18u, (uint32)(scaled >> 32) >> 7);
                    return sub_8001FDA4(a1);
                }
            }
        }
    }
    return result;
}

uint32 sub_8001FDA4(uint32 sound_slot)
{
    FUNCTION_MARKER(0x8001FDA4u, "SLES_008.65");
    uint32 mode = r_u8(0x80078BECu);
    if (mode == 2u) return sub_8001FEDC(sound_slot);
    if (mode >= 3u)
    {
        /* The mode-three identity helper receives the already computed result four */
        if (mode == 3u) return 4u;
        /* TODO: Bind the nonselected stereo voice-volume helper */
        if (mode == 4u) return ob_draft_unresolved_call(0x8001FFC0u, 1u, sound_slot);
        return 4u;
    }
    /* TODO: Bind the nonselected mono voice-volume helper */
    if (mode == 1u) return ob_draft_unresolved_call(0x8001FE3Cu, 1u, sound_slot);
    return 1u;
}

uint32 sub_8001DDA0(void)
{
    FUNCTION_MARKER(0x8001DDA0u, "SLES_008.65");
    uint32 result = r_u8(0x8006C00Cu);
    if (result != 0u)
    {
        result = r_u8(0x8006C00Du);
        if (result != 0u)
        {
            /* TODO Bind SDK sound adapters */
            ob_draft_unresolved_call(0x80061748u, 1u, 0u);
            result = ob_draft_unresolved_call(0x80062580u, 1u, 4u);
            w_u8(0x8006C00Du, 0u);
            w_u8(0x8006C00Eu, 0u);
        }
    }
    return result;
}

uint32 sub_8002439C(void)
{
    FUNCTION_MARKER(0x8002439Cu, "SLES_008.65");
    uint32 mode = r_u8(0x8006C22Fu);
    if (mode == 1u) return sub_800117C8(2u);
    if (mode < 2u) return mode == 0u ? sub_800117C8(1u) : 1u;
    if (mode == 2u) return sub_800117C8(4u);
    return 2u;
}

uint32 sub_80027ED8(uint32 a1)
{
    FUNCTION_MARKER(0x80027ED8u, "SLES_008.65");
    uint32 slot = r_u32(0x800775F4u) + a1 * 4u;
    sub_80026694(slot, 40u, 4u);
    uint32 result = r_u32(slot);
    sub_800268E8(slot, 0u);
    w_u16(result + 4u, a1 != 0u ? 256u : 255u);
    if (a1 == 0u) w_u8(result + 6u, 128u);
    return result;
}

uint32 sub_80027CD0(uint32 a1)
{
    FUNCTION_MARKER(0x80027CD0u, "SLES_008.65");
    uint32 high = (a1 >> 8) & 255u, low = a1 & 255u;
    uint32 page = r_u32(r_u32(0x800775F4u) + high * 4u);
    if (page == 0u) page = sub_80027E90(high);
    uint32 mask = 128u >> (low & 7u), bit_address = page + (low >> 3) + 6u;
    if ((r_u8(bit_address) & mask) != 0u) return 0u;
    w_u16(page + 4u, r_u16(page + 4u) - 1u);
    w_u8(bit_address, r_u8(bit_address) | mask);
    w_u32(r_u32(page) + low * 4u, 0u);
    return 0xFFFFFFFFu;
}

uint32 sub_80055808(void)
{
    FUNCTION_MARKER(0x80055808u, "SLES_008.65");
    w_u32((uint32)-2146925912, 0u);
    uint32 result = sub_80026758((uint32)-2146925900);
    w_u32(0x800771E4u, 0u);
    return result;
}

uint32 sub_8005577C(uint32 a1)
{
    FUNCTION_MARKER(0x8005577Cu, "SLES_008.65");
    w_u32(0x800771ECu, (a1 & 65535u) >> 1);
    w_u32((uint32)-2146925912, 0u);
    w_u32((uint32)-2146925900, 0u);
    sub_80026694((uint32)-2146925900, r_u32(0x800771ECu) << 11, 0u);
    w_u32(0x800771E4u, 1u);
    return 1u;
}

uint32 sub_80026694(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x80026694u, "SLES_008.65");
    uint32 block;
    if ((a3 & 1u) != 0u) block = sub_80026D30(a2, r_u32(0x80077228u));
    else block = sub_80026F48(a2);
    if (block != 0u) return sub_80026984(block, a1, a3 & 255u);
    /* TODO Preserve the null helper's incoming result carrier */
    return ob_draft_unresolved_call(0x800279CCu, 0u);
}



