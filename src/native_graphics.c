#include "native_graphics.h"
#include "native_runtime.h"
#include "psx.h"

static void graphics_arguments(uint32 target, uint32 count, uint32 required)
{
    if (count != required) ob_native_missing(target, required, count);
}

uint32 ob_native_reset_graph(uint32 mode)
{
    uint32 result = (uint32)ResetGraph((sint32)mode);
    if (result != UINT32_MAX && ((mode & 7u) == 0u || (mode & 7u) == 3u))
    {
        uint32 graph_type = (uint32)GetGraphType();
        /* Original ResetGraph publishes the GPU type and its VRAM bounds */
        if (graph_type >= 5u) ob_native_missing(0x8005C064u, 4u, graph_type);
        w_u8(0x80075BECu, graph_type);
        w_u8(0x80075BEDu, 1u);
        w_u16(0x80075BF0u, r_u16(0x80075C6Cu + 4u * graph_type));
        w_u16(0x80075BF2u, r_u16(0x80075C80u + 4u * graph_type));
    }
    return result;
}

static uint32 native_environment_clip(uint32 command, sint16 x, sint16 y)
{
    sint32 width_limit = (sint16)r_u16(0x80075BF0u) - 1;
    sint32 height_limit = (sint16)r_u16(0x80075BF2u) - 1;
    sint32 clipped_x = x < 0 ? 0 : (x > width_limit ? width_limit : x);
    sint32 clipped_y = y < 0 ? 0 : (y > height_limit ? height_limit : y);
    /* TODO Support alternate GPU draw area encoding if reached */
    if (r_u8(0x80075BECu) == 1u || r_u8(0x80075BECu) == 2u)
        ob_native_missing(0x8005D3F0u, 0u, r_u8(0x80075BECu));
    return command | ((uint32)clipped_x & 0x3FFu) | (((uint32)clipped_y & 0x3FFu) << 10);
}

static void native_font_load(sint32 x, sint32 y)
{
    uint32 address;
    w_u16(0x8007F774u, LoadClut((uint32 *)psx_addr(0x80075194u, 32u), x, y + 128));
    w_u16(0x8007F770u, LoadTPage((uint32 *)psx_addr(0x80075394u, 2048u), 0, 0, x, y, 128, 32));
    w_u32(0x8007518Cu, 0u);
    for (address = 0x8007500Cu; address < 0x8007518Cu; ++address) w_u8(address, 0u);
}

static uint32 native_font_open(const uint32 *args)
{
    sint32 stream = (sint32)r_u32(0x8007518Cu);
    sint32 used;
    sint32 capacity = (sint32)args[5];
    uint32 offset;
    uint32 record;
    uint32 text;
    uint32 sprites;
    sint32 index;
    PSX_RECT texture_window = { 0, 0, 256, 256 };
    if (stream >= 8) return UINT32_MAX;
    if (!stream) w_u32(0x80075B94u, 0u);
    used = (sint32)r_u32(0x80075B94u);
    if ((sint32)((uint32)capacity + (uint32)used) >= 1025) capacity = 1024 - used;
    offset = (uint32)stream * 48u;
    record = 0x8007500Cu + offset;
    text = 0x8007B370u + (uint32)used;
    sprites = 0x8007B770u + (uint32)used * 16u;
    w_u32(0x80075038u + offset, args[2] == 0u);
    SetDrawMode(psx_addr(0x8007501Cu + offset, 12u), 0, 0, r_u16(0x8007F770u), &texture_window);
    if (args[4])
    {
        SetTile(psx_addr(record, 16u));
        w_u8(record + 4u, 0u);
        w_u8(record + 5u, 0u);
        w_u8(record + 6u, 0u);
        SetSemiTrans(psx_addr(record, 16u), args[4] == 2u);
    }
    w_u16(record + 8u, args[0]);
    w_u16(record + 10u, args[1]);
    w_u16(record + 12u, args[2]);
    w_u16(record + 14u, args[3]);
    w_u32(0x80075028u + offset, (uint32)capacity);
    w_u32(0x80075034u + offset, 0u);
    w_u32(0x80075030u + offset, text);
    w_u32(0x8007502Cu + offset, sprites);
    w_u8(text, 0u);
    for (index = 0; index < capacity; ++index)
    {
        uint32 sprite = sprites + (uint32)index * 16u;
        SetSprt8(psx_addr(sprite, 16u));
        w_u16(sprite + 14u, r_u16(0x8007F774u));
    }
    w_u32(0x80075B94u, (uint32)used + (uint32)capacity);
    w_u32(0x8007518Cu, (uint32)stream + 1u);
    return (uint32)stream;
}

sint32 ob_native_graphics_call(uint32 target, uint32 count, const uint32 *args, uint32 *result)
{
    switch (target)
    {
    case 0x8005F59Cu:
        graphics_arguments(target, count, 3u);
        /* NormalColorCol loads one packed normal and one color before NCCS */
        xport_gte_write_data(0u, r_u32(args[0]));
        xport_gte_write_data(1u, r_u32(args[0] + 4u));
        xport_gte_write_data(6u, r_u32(args[1]));
        xport_gte_execute(0x108041Bu);
        w_u32(args[2], xport_gte_read_data(22u));
        *result = 0u;
        return 1;
    case 0x8005F398u:
    {
        uint32 index;
        graphics_arguments(target, count, 1u);
        /* Original SetRotMatrix writes exactly five packed control words */
        for (index = 0u; index < 5u; ++index)
            xport_gte_write_control(index, r_u32(args[0] + 4u * index));
        *result = 0u;
        return 1;
    }
    case 0x8005F428u:
    {
        MATRIX translation;
        graphics_arguments(target, count, 1u);
        translation.t[0] = r_s32(args[0] + 20u);
        translation.t[1] = r_s32(args[0] + 24u);
        translation.t[2] = r_s32(args[0] + 28u);
        SetTransMatrix(&translation);
        *result = 0u;
        return 1;
    }
    case 0x8005F288u:
        graphics_arguments(target, count, 3u);
        /* Original MulMatrix0 consumes and writes five packed rotation words */
        MulMatrix0((MATRIX *)psx_addr(args[0], 20u), (MATRIX *)psx_addr(args[1], 20u),
            (MATRIX *)psx_addr(args[2], 20u));
        *result = args[2];
        return 1;
    case 0x8005F750u:
        graphics_arguments(target, count, 2u);
        /* Original Square0 reads and writes exactly three vector words */
        Square0((VECTOR *)psx_addr(args[0], 12u), (VECTOR *)psx_addr(args[1], 12u));
        *result = args[1];
        return 1;
    case 0x8005EF68u:
        graphics_arguments(target, count, 1u);
        *result = SquareRoot0((sint32)args[0]);
        return 1;
    case 0x8005BA48u:
        graphics_arguments(target, count, 2u);
        SetSemiTrans(psx_addr(args[0], 8u), (sint32)args[1]);
        *result = r_u8(args[0] + 7u);
        return 1;
    case 0x8005BAE8u:
        graphics_arguments(target, count, 1u);
        SetPolyF4(psx_addr(args[0], 24u));
        *result = 0x28u;
        return 1;
    case 0x8005B994u:
        graphics_arguments(target, count, 2u);
        AddPrim(psx_addr(args[0], 4u), psx_addr(args[1], 4u));
        *result = r_u32(args[0]);
        return 1;
    case 0x8005C954u:
        graphics_arguments(target, count, 2u);
        if ((sint32)args[1] <= 0 || args[1] > 0x80000u) ob_native_missing(target, 1u, args[1]);
        ClearOTag((uint32 *)psx_addr(args[0], (size_t)args[1] * 4u), (sint32)args[1]);
        *result = args[0] + (args[1] - 1u) * 4u;
        return 1;
    case 0x8005C064u:
        graphics_arguments(target, count, 1u);
        *result = ob_native_reset_graph(args[0]);
        return 1;
    case 0x8005ABC0u:
        graphics_arguments(target, count, 5u);
        SetDefDrawEnv((DRAWENV *)psx_addr(args[0], sizeof(DRAWENV)), (sint32)args[1], (sint32)args[2], (sint32)args[3], (sint32)args[4]);
        *result = args[0];
        return 1;
    case 0x8005AC90u:
        graphics_arguments(target, count, 5u);
        SetDefDispEnv((DISPENV *)psx_addr(args[0], sizeof(DISPENV)), (sint32)args[1], (sint32)args[2], (sint32)args[3], (sint32)args[4]);
        *result = args[0];
        return 1;
    case 0x8005AD0Cu:
        graphics_arguments(target, count, 2u);
        native_font_load((sint32)args[0], (sint32)args[1]);
        *result = 0u;
        return 1;
    case 0x8005ADB0u:
        graphics_arguments(target, count, 6u);
        *result = native_font_open(args);
        return 1;
    case 0x8005ACCCu:
        graphics_arguments(target, count, 1u);
        if ((sint32)args[0] >= 0 && (sint32)args[0] <= (sint32)r_u32(0x8007518Cu))
        {
            w_u32(0x80075190u, args[0]);
            w_u32(0x80075BE8u, 0x8005B38Cu);
        }
        *result = 0u;
        return 1;
    case 0x8005C698u:
        graphics_arguments(target, count, 4u);
        *result = (uint32)ClearImage((PSX_RECT *)psx_addr(args[0], sizeof(PSX_RECT)), (uint8)args[1], (uint8)args[2], (uint8)args[3]);
        return 1;
    case 0x8005C504u:
        graphics_arguments(target, count, 1u);
        *result = (uint32)DrawSync((sint32)args[0]);
        return 1;
    case 0x80059F3Cu:
        graphics_arguments(target, count, 1u);
        *result = VSyncCallbackPSX(args[0]);
        return 1;
    case 0x80059CA8u:
        graphics_arguments(target, count, 1u);
        *result = (uint32)VSync((sint32)args[0]);
        return 1;
    case 0x8005CB78u:
        graphics_arguments(target, count, 1u);
        PutDrawEnv((DRAWENV *)psx_addr(args[0], sizeof(DRAWENV)));
        *result = args[0];
        return 1;
    case 0x8005CB04u:
        graphics_arguments(target, count, 1u);
        DrawOTag((uint32 *)psx_addr(args[0], 4u));
        *result = 0u;
        return 1;
    case 0x8005C468u:
        graphics_arguments(target, count, 1u);
        SetDispMask((sint32)args[0]);
        *result = 0u;
        return 1;
    case 0x8005CD50u:
        graphics_arguments(target, count, 1u);
        PutDispEnv((DISPENV *)psx_addr(args[0], sizeof(DISPENV)));
        *result = args[0];
        return 1;
    case 0x8005F3F8u:
        graphics_arguments(target, count, 1u);
        /* Original GTE color matrix consumes five packed words */
        SetColorMatrix((MATRIX *)psx_addr(args[0], 20u));
        *result = 0u;
        return 1;
    case 0x8005F3C8u:
        graphics_arguments(target, count, 1u);
        /* Original GTE light matrix uses the same packed nine coefficients */
        SetLightMatrix((MATRIX *)psx_addr(args[0], 20u));
        *result = 0u;
        return 1;
    case 0x8005F448u:
        graphics_arguments(target, count, 3u);
        SetBackColor((sint32)args[0], (sint32)args[1], (sint32)args[2]);
        *result = 0u;
        return 1;
    case 0x8005C7C8u:
    {
        PSX_RECT *rectangle;
        uint32 bytes;
        graphics_arguments(target, count, 2u);
        rectangle = (PSX_RECT *)psx_addr(args[0], sizeof(PSX_RECT));
        if (rectangle->w < 0 || rectangle->h < 0)
            ob_native_missing(target, 0u, (uint32)rectangle->w);
        bytes = (uint32)rectangle->w * (uint32)rectangle->h * 2u;
        *result = (uint32)LoadImagePSX(rectangle, (uint32 *)psx_addr(args[1], bytes));
        return 1;
    }
    case 0x8005BAFCu:
        graphics_arguments(target, count, 1u);
        SetPolyFT4(psx_addr(args[0], 8u));
        *result = 0x2Cu;
        return 1;
    case 0x8005BB10u:
        graphics_arguments(target, count, 1u);
        SetPolyG4(psx_addr(args[0], 8u));
        *result = 0x38u;
        return 1;
    case 0x8005BB38u:
        graphics_arguments(target, count, 1u);
        SetSprt8(psx_addr(args[0], 8u));
        *result = 0x74u;
        return 1;
    case 0x8005BB60u:
        graphics_arguments(target, count, 1u);
        SetSprt(psx_addr(args[0], 8u));
        *result = 0x64u;
        return 1;
    case 0x8005B76Cu:
        graphics_arguments(target, count, 4u);
        /* TODO Support the alternate GPU texture page encoding if reached */
        if (r_u8(0x80075BECu) == 1u || r_u8(0x80075BECu) == 2u)
            ob_native_missing(target, 0u, r_u8(0x80075BECu));
        *result = GetTPage((sint32)args[0], (sint32)args[1], (sint32)args[2], (sint32)args[3]);
        return 1;
    case 0x8005B834u:
        graphics_arguments(target, count, 2u);
        *result = GetClut((sint32)args[0], (sint32)args[1]);
        return 1;
    case 0x8005C890u:
    {
        PSX_RECT *rectangle;
        graphics_arguments(target, count, 3u);
        rectangle = (PSX_RECT *)psx_addr(args[0], 8u);
        if (!rectangle->w || !rectangle->h) { *result = UINT32_MAX; return 1; }
        w_u32(0x80075C9Cu, r_u32(args[0]));
        w_u32(0x80075CA0u, (args[1] & 0xFFFFu) | (args[2] << 16));
        w_u32(0x80075CA4u, r_u32(args[0] + 4u));
        *result = (uint32)MoveImage(rectangle, (sint16)args[1], (sint16)args[2]);
        return 1;
    }
    case 0x8005D3F0u:
    {
        DRAWENV *environment;
        graphics_arguments(target, count, 2u);
        /* The original packet builder reads only the 28-byte environment prefix */
        environment = (DRAWENV *)psx_addr(args[1], 28u);
        SetDrawEnv(psx_addr(args[0], 40u), environment);
        w_u32(args[0] + 4u, native_environment_clip(0xE3000000u, environment->clip.x, environment->clip.y));
        w_u32(args[0] + 8u, native_environment_clip(0xE4000000u,
            (sint16)(environment->clip.x + environment->clip.w - 1),
            (sint16)(environment->clip.y + environment->clip.h - 1)));
        if (environment->isbg)
        {
            sint32 width = environment->clip.w;
            sint32 height = environment->clip.h;
            sint32 max_width = (sint16)r_u16(0x80075BF0u) - 1;
            sint32 max_height = (sint16)r_u16(0x80075BF2u) - 1;
            uint16 x = (uint16)environment->clip.x;
            uint16 y = (uint16)environment->clip.y;
            uint32 code;
            width = width < 0 ? 0 : (width > max_width ? max_width : width);
            height = height < 0 ? 0 : (height > max_height ? max_height : height);
            code = (uint32)environment->r0 | ((uint32)environment->g0 << 8) | ((uint32)environment->b0 << 16);
            /* The original uses a VRAM fill when X and width are aligned */
            if ((x & 63u) || ((uint16)width & 63u))
            {
                code |= 0x60000000u;
                x = (uint16)(x - (uint16)environment->ofs[0]);
                y = (uint16)(y - (uint16)environment->ofs[1]);
            }
            else code |= 0x02000000u;
            w_u32(args[0] + 28u, code);
            w_u32(args[0] + 32u, x | ((uint32)y << 16));
            w_u32(args[0] + 36u, (uint16)width | ((uint32)(uint16)height << 16));
        }
        *result = r_u8(args[0] + 3u);
        return 1;
    }
    default:
        return 0;
    }
}

