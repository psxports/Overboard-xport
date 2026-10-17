#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800AD4D0(uint32 object, uint32 properties, uint32 context)
{
    FUNCTION_MARKER(0x800AD4D0u, "GAME.BIN");
    uint32 handle = r_u32(properties + 8u);
    uint32 payload = r_u32(handle);
    if ((payload & 3u) != 0u)
        payload = sub_800257CC(handle);
    else
    {
        w_u16(payload - 6u, (uint32)r_u16(payload - 6u) + 1u);
        payload = r_u32(r_u32(properties + 8u));
    }
    uint32 model = sub_80044E5C(object, payload, context);
    w_u32(object + 44u, model);
    ob_memory_release_reference(r_u32(properties + 8u));
    handle = r_u32(properties + 12u);
    payload = r_u32(handle);
    if ((payload & 3u) != 0u)
        payload = sub_800257CC(handle);
    else
    {
        w_u16(payload - 6u, (uint32)r_u16(payload - 6u) + 1u);
        payload = r_u32(r_u32(properties + 12u));
    }
    uint32 shape = sub_80043E3C(object, payload);
    w_u32(object + 48u, shape);
    ob_memory_release_reference(r_u32(properties + 12u));
    return sub_80045A44(r_u32(object + 44u), 0x8006C160u);
}
