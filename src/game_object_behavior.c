#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_800A9D9C(uint32 node, uint32 mode, uint32 rate, uint32 offset)
{
    FUNCTION_MARKER(0x800A9D9Cu, "GAME.BIN");
    uint32 local = ob_draft_scratch_acquire(4u);
    w_u32(local, 0u);
    sub_800262CC(local, 32);
    uint32 effect = r_u32(local);
    uint32 previous = r_u32(0x800C546Cu);
    w_u32(effect + 4u, node);
    w_u32(effect + 12u, mode);
    w_u32(effect + 16u, rate);
    w_u32(effect + 20u, offset);
    w_u32(effect + 8u, 1u);
    w_u16(effect + 24u, 0u);
    w_u16(effect + 26u, 0u);
    w_u16(effect + 28u, 0u);
    w_u32(effect, previous);
    w_u32(0x800C546Cu, effect);
    ob_draft_scratch_release(local);
    return effect;
}

uint32 ob_game_800BFF00(uint32 object, uint32 owner, uint32 record, uint32 context)
{
    FUNCTION_MARKER(0x800BFF00u, "GAME.BIN");
    uint32 resource = r_u32(object + 292u);
    uint32 properties = r_u32(object + 108u);
    uint32 result;
    uint32 node;
    uint32 effect;
    uint32 size;
    if (resource == 40u)
    {
        node = ob_draft_unresolved_call(0x800437C4u, 2u,
            r_u32(r_u32(object + 44u) + 12u), 65861u);
        result = ob_draft_unresolved_call(0x800A9D9Cu, 4u, node, 0u, 0u, 0u);
        uint32 template = r_u32(0x800D6750u);
        w_u32(properties, result);
        w_u16(result + 26u, 0u - r_u16(template + 16u));
        return result;
    }
    if (resource == 165u)
    {
        node = ob_draft_unresolved_call(0x800437C4u, 2u,
            r_u32(r_u32(object + 44u) + 12u), 65781u);
        if (r_u16(record + 22u) != 0u)
        {
            effect = ob_draft_unresolved_call(0x800A9D9Cu, 4u, node, 0u, 0u, 0u);
            w_u32(properties, effect);
            result = 24u;
        }
        else
        {
            uint32 offset = 0u - 60u * (uint32)(sint32)r_s16(object + 304u);
            effect = ob_draft_unresolved_call(0x800A9D9Cu, 4u, node, 0u, 0u, offset);
            w_u32(properties, effect);
            result = 25u;
        }
        w_u32(object + 288u, result);
        return result;
    }
    if (resource >= 166u)
    {
        result = resource < 229u;
        if (resource >= 229u && resource < 231u)
        {
            uint32 output = r_u32(object + 108u);
            result = ob_draft_unresolved_call(0x800A9D9Cu, 4u,
                r_u32(object + 44u), 0u, 500u, 0u);
            w_u32(output, result);
        }
        return result;
    }
    if (resource == 159u)
    {
        node = ob_draft_unresolved_call(0x800437C4u, 2u,
            r_u32(r_u32(object + 44u) + 12u), 65574u);
        uint32 output = r_u32(object + 108u);
        effect = ob_draft_unresolved_call(0x800A9D9Cu, 4u,
            node, 0u, 5000u - r_u16(record + 18u), 0u);
        w_u32(output + 8u, effect);
        ob_draft_unresolved_call(0x800A29E0u, 2u, object, 1u);
        return ob_draft_unresolved_call(0x800A76A8u, 2u, object, context);
    }
    if (resource == 33u || resource == 36u || resource == 41u)
    {
        ob_draft_unresolved_call(0x800A1BB4u, 2u, object, context);
        uint32 template;
        if (resource == 33u)
        {
            template = 0x800C5320u;
            w_u16(r_u32(object + 116u) + 108u, 260u);
        }
        else if (resource == 36u)
        {
            template = 0x800C5548u;
            w_u16(r_u32(object + 116u) + 108u, 260u);
        }
        else
            template = 0x800C525Cu;
        effect = ob_draft_unresolved_call(0x800ADAD8u, 4u,
            template, owner, r_u32(r_u32(object + 44u) + 32u), object);
        w_u32(properties, effect);
        uint32 attributes = resource == 33u ? 0x800C52A8u
            : resource == 36u ? 0x800C5470u : 0x800C510Cu;
        ob_draft_unresolved_call(0x800ADC1Cu, 3u, effect, r_u32(attributes), context);
        uint32 duration = r_u16(attributes + 20u);
        uint32 child = r_u32(properties);
        if (resource != 41u)
            w_u32(properties + 4u, attributes);
        w_u16(properties + 34u, duration);
        w_u32(child + 4u, object);
        w_u32(properties + 24u, context + 5000u);
        w_u32(properties + 28u, context + 4000u);
        w_u32(properties + 16u, r_u32(record));
        w_u32(properties + 20u, r_u32(record + 8u));
        if (resource == 33u)
        {
            ob_draft_unresolved_call(0x800A29E0u, 2u, object, 2u);
            w_u16(object + 320u, 4096u);
            w_u8(object + 323u, 1u);
            ob_draft_unresolved_call(0x800A1D74u, 2u, object, context);
            ob_draft_unresolved_call(0x800A08A0u, 2u, object, context);
            uint32 current_resource = r_u32(object + 292u);
            w_u32(0x8007FAD0u, 8u);
            w_u32(0x800C8358u, object);
            size = ob_draft_unresolved_call(0x800901A8u, 1u, current_resource) & 0xFFFFu;
            size += r_u16(properties + 40u);
            size += r_u16(properties + 42u);
            w_u32(0x800D6498u, size);
            w_u32(0x800C835Cu, size);
            return ob_draft_unresolved_call(0x800A2D4Cu, 1u, record);
        }
        uint32 current_resource;
        if (resource == 36u)
        {
            ob_draft_unresolved_call(0x800A29E0u, 2u, object, 1u);
            ob_draft_unresolved_call(0x800A1D74u, 2u, object, context);
            ob_draft_unresolved_call(0x800AA62Cu, 2u, object, context);
            w_u32(0x8007FAD0u, 18u);
            ob_draft_unresolved_call(0x800A1BD4u, 2u, object, 0u);
            w_u8(properties + 81u, 0u);
            current_resource = r_u32(object + 292u);
        }
        else
        {
            ob_draft_unresolved_call(0x800A2C78u, 1u, properties);
            current_resource = r_u32(object + 292u);
            w_u32(0x8007FAD0u, 28u);
        }
        w_u32(0x800C8358u, object);
        size = ob_draft_unresolved_call(0x800901A8u, 1u, current_resource) & 0xFFFFu;
        w_u32(0x800D6498u, size);
        w_u32(0x800C835Cu, size);
        return ob_draft_unresolved_call(0x800A2D4Cu, 1u, 0x8006C160u);
    }
    if (resource == 39u)
    {
        if (r_u16(record + 18u) != 0u)
        {
            node = ob_draft_unresolved_call(0x800437C4u, 2u, object, 65842u);
            ob_draft_unresolved_call(0x80044080u, 2u, node, 0x800662CCu);
            w_u32(properties, 0u);
            w_u32(object + 288u, 20u);
        }
        else
        {
            node = ob_draft_unresolved_call(0x800437C4u, 2u,
                r_u32(r_u32(object + 44u) + 12u), 65843u);
            effect = ob_draft_unresolved_call(0x800A9D9Cu, 4u, node, 0u, 300u, 0u);
            w_u32(properties, effect);
            uint32 current_resource = r_u32(object + 292u);
            w_u16(object + 320u, 0x2000u);
            w_u32(0x800C8358u, object);
            size = ob_draft_unresolved_call(0x800901A8u, 1u, current_resource) & 0xFFFFu;
            w_u32(0x800D6498u, size);
            w_u32(0x800C835Cu, size);
            w_u32(object + 332u, context);
        }
        uint32 entry = 0x800CBA60u;
        for (uint32 remaining = 400u; remaining != 0u; --remaining, entry += 104u)
        {
            uint32 candidate = r_u32(entry - 16u);
            if (candidate != 0u && r_u32(entry) == 40u)
                ob_draft_unresolved_call(0x800A9E30u, 5u,
                    r_u32(r_u32(candidate + 108u)), 0u, 1200u, 0u, 1u);
        }
        w_u32(0x8007FAD0u, 13u);
        return ob_draft_unresolved_call(0x800A2D4Cu, 1u, record);
    }
    if (resource == 37u)
        return ob_draft_unresolved_call(0x800A2D4Cu, 1u, record);
    if (resource == 32u)
    {
        ob_draft_unresolved_call(0x8009C428u, 3u, owner, object, context);
        uint32 output = r_u32(object + 108u);
        node = ob_draft_unresolved_call(0x800437C4u, 2u,
            r_u32(r_u32(object + 44u) + 12u), 66002u);
        effect = ob_draft_unresolved_call(0x800A9D9Cu, 4u, node, 0u, 300u, 0u);
        w_u32(output, effect);
        uint32 current_resource = r_u32(object + 292u);
        w_u32(0x8007FAD0u, 23u);
        w_u32(0x800C8358u, object);
        size = (ob_draft_unresolved_call(0x800901A8u, 1u, current_resource) & 0xFFFFu) + 64000u;
        w_u32(0x800D6498u, size);
        w_u32(0x800C835Cu, size);
        ob_draft_unresolved_call(0x800A2D4Cu, 1u, 0x8006C160u);
        w_u8(object + 339u, 5u);
        w_u32(object + 332u, context);
        return 5u;
    }
    if (resource >= 41u)
        return 159u;
    if (resource >= 37u)
        return 39u;
    return 33u;
}
