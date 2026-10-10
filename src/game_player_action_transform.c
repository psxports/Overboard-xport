#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_extra_signatures.h"

uint32 ob_game_800B5C80(uint32 slot, uint32 weapon, uint32 identifiers)
{
    FUNCTION_MARKER(0x800B5C80u, "GAME.BIN");
    uint32 index = r_u8(weapon + (slot & 255u) + 112u);
    return r_u32(identifiers + index * 4u);
}

uint32 ob_game_800B762C(uint32 object, uint32 slot, uint32 request, uint32 angle, uint32 time)
{
    FUNCTION_MARKER(0x800B762Cu, "GAME.BIN");
    uint32 properties = r_u32(object + 112u);
    uint32 node;
    uint32 heading;
    uint32 matrix = ob_draft_scratch_acquire(18u);
    uint32 matrix_initialized = 0u;
    angle = (uint32)(sint32)(sint16)angle;
    slot &= 255u;
    if (slot < 2u)
    {
        uint32 selector = r_u32(properties + 24u + slot * 4u);
        if (selector != 0u)
        {
            uint32 identifier = ob_draft_unresolved_call(0x800B5C80u, 3u,
                slot, r_u32(object + 120u), selector);
            node = (uint32)sub_800437C4(r_u32(r_u32(object + 44u) + 12u), (sint32)identifier);
        }
        else
            node = r_u32(object + 44u);
        w_u32(request + 100u, node);
        uint32 type = r_u32(object + 292u);
        if (type == 255u)
        {
            uint32 weapon = r_u32(object + 120u);
            uint32 table = r_u32(properties + 32u + slot * 4u);
            uint32 attributes = r_u32(object + 108u);
            uint32 index = r_u8(weapon + slot + 112u);
            uint32 base_heading = r_u16(attributes + 48u);
            uint32 offset = r_u16(table + index * 2u);
            heading = angle + base_heading + offset;
            ob_draft_unresolved_call(0x80029F58u, 2u,
                (uint32)(sint32)(sint16)heading, matrix);
            matrix_initialized = 1u;
            weapon = r_u32(object + 120u);
            index = r_u8(weapon + slot + 112u);
            table = r_u32(properties + 32u + slot * 4u);
            offset = r_u16(table + index * 2u);
            w_u16(request + 108u, offset + angle);
            attributes = r_u32(object + 108u);
            w_u32(request + 104u, attributes + 48u);
        }
        else
        {
            uint32 table = slot == 0u ? r_u32(properties + 32u) : 0u;
            if (slot == 0u && table == 0u)
            {
                heading = 0u;
                node = r_u32(object + 44u);
                w_u16(request + 108u, 0u);
                w_u32(request + 104u, 0u);
            }
            else
            {
                uint32 player = r_u32(object + 124u);
                uint32 weapon;
                uint32 index;
                uint32 base_heading;
                if (player != 0u)
                {
                    weapon = r_u32(object + 120u);
                    if (slot == 1u)
                        table = r_u32(properties + 36u);
                    index = r_u8(weapon + slot + 112u);
                    base_heading = r_u16(player + 4u);
                }
                else
                {
                    weapon = r_u32(object + 120u);
                    if (slot == 1u)
                        table = r_u32(properties + 36u);
                    index = r_u8(weapon + slot + 112u);
                    base_heading = r_u16(object + 296u);
                }
                uint32 offset = r_u16(table + index * 2u);
                heading = angle + base_heading + offset;
                ob_draft_unresolved_call(0x80029F58u, 2u,
                    (uint32)(sint32)(sint16)heading, matrix);
                matrix_initialized = 1u;
                weapon = r_u32(object + 120u);
                index = r_u8(weapon + slot + 112u);
                table = r_u32(properties + 32u + slot * 4u);
                offset = r_u16(table + index * 2u);
                if (player != 0u)
                {
                    w_u16(request + 108u, offset + angle);
                    w_u32(request + 104u, r_u32(object + 124u) + 4u);
                }
                else if (slot == 0u)
                {
                    w_u32(request + 104u, object + 296u);
                    w_u16(request + 108u, offset + angle);
                }
                else
                {
                    w_u16(request + 108u, offset + angle);
                    w_u32(request + 104u, object + 296u);
                }
            }
        }
    }
    else if (slot == 2u || slot == 3u || slot == 4u)
    {
        uint32 identifier = slot == 2u ? 0x10047u : slot == 3u ? 0x10046u : 0x1004Cu;
        node = (uint32)sub_800437C4(r_u32(r_u32(object + 44u) + 12u), (sint32)identifier);
        uint32 attributes = r_u32(object + 108u);
        heading = r_u16(attributes + 48u) + angle;
        if (slot == 3u)
            heading -= 32768u;
        if (slot == 4u)
            ob_draft_unresolved_call(0x80029EECu, 2u, 0u, matrix);
        else
            ob_draft_unresolved_call(0x80029F58u, 2u,
                (uint32)(sint32)(sint16)heading, matrix);
        matrix_initialized = 1u;
    }
    else
    {
        /* TODO The original leaves node and heading undefined for other slots */
        return ob_native_missing_value(0x800B762Cu, "Undefined action transform slot beyond4");
    }
    if (matrix_initialized == 0u)
    {
        /* TODO The original zero-table path consumes an unwritten local matrix */
        return ob_native_missing_value(0x800B762Cu, "Unwritten action transform matrix on zero-table path");
    }
    ob_draft_unresolved_call(0x8002A870u, 3u, matrix,
        (uint32)(sint32)r_s16(request + 50u), request + 12u);
    w_u16(request + 52u, heading);
    if (r_u32(object + 292u) == 255u)
    {
        uint32 weapon = r_u32(object + 120u);
        uint32 attributes = r_u32(object + 108u);
        uint32 index = (uint32)(sint32)r_s8(weapon + 137u);
        uint32 cost = r_u16(weapon + 126u);
        uint32 ammunition = r_u16(attributes + index * 2u + 120u);
        w_u16(attributes + index * 2u + 120u, ammunition - cost);
    }
    sub_80045378(node, time, request);
    uint32 result = r_u32(properties + 32u);
    if (result == 0u)
        result = r_u32(properties + 36u);
    if (result != 0u)
        result = ob_main_80045410(r_u32(object + 44u), request + 32u);
    else
    {
        w_u32(request + 32u, 0u);
        w_u32(request + 36u, 0u);
        w_u32(request + 40u, 0u);
    }
    ob_draft_scratch_release(matrix);
    return result;
}
