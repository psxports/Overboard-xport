#include "batch11_frontier.h"

uint32 ob_snapshot_geometry_state(void)
{
    FUNCTION_MARKER(0x8002DB08u, "SLES_008.65");
    uint32 state = r_u32(0x800770C8u);
    uint32 context = r_u32(0x80077440u);
    w_u32(0x80077474u, 0xFFFFFFFFu);
    w_u32(0x80077354u, state);
    w_u32(0x80077358u, context);
    return state;
}

uint32 ob_update_geometry_dimensions(void)
{
    FUNCTION_MARKER(0x80035270u, "SLES_008.65");
    uint32 context = r_u32(0x800770C0u);
    uint32 width_owner = r_u32(context + 4u);
    uint32 height_owner = r_u32(context + 4u);
    uint32 width = r_u32(width_owner + 64u);
    uint32 height = r_u32(height_owner + 68u);
    w_u16(0x800774E0u, width);
    uint32 half_width = (uint32)((int32_t)(width << 16) >> 17);
    w_u16(0x800774E2u, height);
    uint32 half_height = (uint32)((int32_t)(height << 16) >> 17);
    w_u16(0x80077568u, half_width);
    w_u16(0x8007756Au, half_height);
    return half_width;
}

uint32 ob_snapshot_geometry_context(void)
{
    FUNCTION_MARKER(0x8002DB3Cu, "SLES_008.65");
    uint32 context = r_u32(0x80077440u);
    w_u32(0x80077358u, context);
    return context;
}

uint32 ob_init_geometry_workspace(void)
{
    FUNCTION_MARKER(0x80041B74u, "SLES_008.65");
    w_u32(0x800770F0u, 0x80086BC0u);
    w_u32(0x80077614u, 0x15E0u);
    w_u32(0x800773D8u, 0u);
    w_u32(0x80077484u, 0x800868C8u);
    return ob_snapshot_geometry_context();
}
