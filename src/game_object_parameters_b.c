#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_800BDCE0(uint32 object, uint32 descriptor)
{
    FUNCTION_MARKER(0x800BDCE0u, "GAME.BIN");
    uint32 resource = r_u32(object + 292u);
    if (resource == 233u)
        return ob_draft_unresolved_call(0x800440B8u, 2u, r_u32(object + 48u), 400u);
    if (resource < 234u)
    {
        if (resource == 166u)
            return ob_draft_unresolved_call(0x800440B8u, 2u, r_u32(object + 48u), 380u);
        uint32 result = resource < 231u;
        if (resource >= 166u)
        {
            result = resource < 229u;
            if (resource < 231u && resource >= 229u)
            {
                result = 23u;
                if (r_u32(r_u32(object + 108u) + 4u) == 23u)
                    return ob_draft_unresolved_call(0x800440B8u, 2u,
                        r_u32(object + 48u), 100u);
            }
        }
        return result;
    }
    uint32 result = resource < 239u;
    if (resource == 238u)
        return result;
    if (resource < 239u)
    {
        result = 1u;
        if (resource == 235u && r_u16(descriptor + 18u) == 1u)
        {
            uint32 scene = r_u32(object + 48u);
            uint32 properties = r_u32(object + 112u);
            uint32 material = r_u32(scene + 32u);
            result = r_u32(properties + 20u);
            w_u32(material + 40u, result);
        }
        return result;
    }
    result = 1u;
    if (resource != 239u)
        return result;
    sint32 variant = r_s16(object + 304u);
    result = variant < 2;
    if (variant == 1)
        return ob_draft_unresolved_call(0x800440B8u, 2u, r_u32(object + 48u), 400u);
    if (variant >= 2)
    {
        result = 2u;
        if (variant == 2)
            return ob_draft_unresolved_call(0x800440B8u, 2u, r_u32(object + 48u), 600u);
    }
    else if (variant == 0)
        return ob_draft_unresolved_call(0x800440B8u, 2u, r_u32(object + 48u), 200u);
    return result;
}
