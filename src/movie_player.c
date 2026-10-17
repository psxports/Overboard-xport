#include "psx.h"
#include "movie_player.h"
#include "draft_signatures.h"
#include "native_runtime.h"
#include "native_extra_signatures.h"
#include "psx_press.h"
#include "psx_stream.h"
#include <string.h>

/* MOVIE.BIN translations with native PsyQ buffer and callback adapters */
static void ob_movie_8008DD14(void)
{
    FUNCTION_MARKER(0x8008DD14u, "MOVIE.BIN");
    w_u8(0x8009FA28u, 1u);
}

static uint32 ob_movie_8008DD9C(uint32 mode)
{
    FUNCTION_MARKER(0x8008DD9Cu, "MOVIE.BIN");
    if (!mode) ResetCallback();
    DecDCTReset((sint32)mode);
    return 0u;
}

static uint32 ob_movie_8008D690(uint32 rgb24)
{
    uint32 scale = r_u32(0x8009FA34u);
    uint32 width = 320u * scale;
    uint32 height = 256u * scale;
    uint32 pixels[512] = {0};
    PSX_RECT rectangle = {0, 0, 1024, 1};
    FUNCTION_MARKER(0x8008D690u, "MOVIE.BIN");
    SetDefDrawEnv((DRAWENV *)psx_addr(0x8009FA38u, sizeof(DRAWENV)), 0, 0, width, height);
    SetDefDrawEnv((DRAWENV *)psx_addr(0x8009FA94u, sizeof(DRAWENV)), 0, scale == 1u ? height : 0u, width, height);
    SetDefDispEnv((DISPENV *)psx_addr(0x8009FAF0u, sizeof(DISPENV)), 0, scale == 1u ? height : 0u, width, height);
    SetDefDispEnv((DISPENV *)psx_addr(0x8009FB04u, sizeof(DISPENV)), 0, 0, width, height);
    if (scale == 1u)
    {
        for (uint32 env = 0x8009FAF0u; env <= 0x8009FB04u; env += 20u)
        {
            w_u16(env + 8u, 0u); w_u16(env + 10u, 20u);
            w_u16(env + 12u, 256u); w_u16(env + 14u, 256u);
        }
    }
    w_u8(0x8009FB01u, rgb24); w_u8(0x8009FB15u, rgb24);
    for (uint32 row = 0u; row < 512u; ++row)
    {
        rectangle.y = (sint16)row;
        LoadImagePSX(&rectangle, pixels);
    }
    return 0u;
}

static uint32 ob_movie_8008D8D8(void)
{
    FUNCTION_MARKER(0x8008D8D8u, "MOVIE.BIN");
    w_u8(0x8009FA00u, 0u);
    w_u32(0x8009F9ECu, r_u32(0x8009F9F8u));
    w_u32(0x8009F9F0u, r_u32(0x8009F9FCu));
    StSetRing((uint32 *)psx_addr(r_u32(0x8009F9F4u), 20u * 2048u), 20u);
    return 0u;
}

static uint32 ob_movie_8008D928(uint32 filename, uint32 frames)
{
    uint32 local = ob_draft_scratch_acquire(40u);
    uint8 mode = 0x46u;
    FUNCTION_MARKER(0x8008D928u, "MOVIE.BIN");
    CdControlB(CdlSetmode, &mode, NULL);
    if (!CdSearchFileGuest(local, filename))
    {
        ob_draft_scratch_release(local);
        return 1u;
    }
    memcpy(psx_addr(local + 24u, 3u), psx_addr(local, 3u), 3u);
    while (!CdControl(0x15u, (uint8 *)psx_addr(local + 24u, 4u), NULL)) ob_native_pump();
    stream_set_read_mode(0x1C0u);
    while (!CdRead2(0x1C0)) ob_native_pump();
    StSetStream(0u, 1u, frames, NULL, ob_movie_8008DD14);
    ob_draft_scratch_release(local);
    return 0u;
}

static uint32 ob_movie_8008D9E4(void)
{
    uint32 *payload = NULL, *header = NULL;
    uint32 output;
    FUNCTION_MARKER(0x8008D9E4u, "MOVIE.BIN");
    while (StGetNext(&payload, &header)) ob_native_pump();
    memcpy(psx_addr(0x8009FA04u, 28u), header, 28u);
    output = r_u32(0x8009F9ECu + 4u * r_u8(0x8009FA00u));
    DecDCTvlc(payload, (uint32 *)psx_addr(output, 0x25800u));
    while (StFreeRing(payload)) ob_native_pump();
    return r_u32(0x8009FA0Cu);
}

static uint32 ob_movie_8008DA98(uint32 rgb24)
{
    uint32 width, height, words, input;
    FUNCTION_MARKER(0x8008DA98u, "MOVIE.BIN");
    ob_movie_8008DD9C(1u);
    width = ((r_u16(0x8009FA14u) + 8u) >> 4u) << 4u;
    height = ((r_u16(0x8009FA16u) + 8u) >> 4u) << 4u;
    w_u16(0x8009FA14u, width); w_u16(0x8009FA16u, height);
    words = (width & 0xFFF0u) * (height & 0xFFF0u);
    words = rgb24 ? (3u * words) >> 2u : words >> 1u;
    input = r_u32(0x8009F9ECu + 4u * r_u8(0x8009FA00u));
    DecDCTin((uint32 *)psx_addr(input, 0x25800u), (sint32)rgb24);
    DecDCTout((uint32 *)psx_addr(r_u32(0x8009F9E8u), words * 4u), (sint32)words);
    w_u16(0x8009FA20u, r_u16(0x8009FA14u));
    w_u16(0x8009FA24u, r_u16(0x8009FA16u));
    return r_u32(0x8009FA0Cu);
}

static uint32 ob_movie_8008DBA4(uint32 rgb24)
{
    uint32 scale = r_u32(0x8009FA34u);
    uint32 width = r_u16(0x8009FA20u), height = r_u16(0x8009FA24u);
    uint32 difference = 320u * scale - width;
    uint32 x = scale == 2u ? 318u : (difference + (difference >> 31u)) >> 1u;
    uint32 ydiff = (scale << 8u) - height;
    uint32 y = (ydiff + (ydiff >> 31u)) >> 1u;
    uint32 slice = rgb24 == 1u ? 24u : 16u;
    uint32 words = rgb24 == 1u ? (48u * height) >> 2u : (16u * height) >> 1u;
    uint32 pixels = r_u32(0x8009F9E8u);
    uint32 offset = 0u, result = width;
    PSX_RECT rectangle;
    FUNCTION_MARKER(0x8008DBA4u, "MOVIE.BIN");
    width = slice * width / 16u;
    w_u16(0x8009FA20u, width);
    if ((sint16)r_u16(0x8009FA2Cu) == 1 && scale == 1u) y += 256u;
    rectangle.x = (sint16)x; rectangle.y = (sint16)y;
    rectangle.w = (sint16)slice; rectangle.h = (sint16)height;
    while ((offset & 0xFFFFu) < (width & 0xFFFFu))
    {
        LoadImagePSX(&rectangle, (uint32 *)psx_addr(pixels, words * 4u));
        DrawSync(0);
        offset += slice;
        rectangle.x = (sint16)((uint16)rectangle.x + slice);
        result = (offset & 0xFFFFu) < (width & 0xFFFFu);
        pixels += words * 4u;
    }
    return result;
}

static void ob_movie_swap_display(void)
{
    uint32 buffer = (sint16)r_u16(0x8009FA2Cu) == 0;
    w_u16(0x8009FA2Cu, buffer);
    PutDrawEnv((DRAWENV *)psx_addr(0x8009FA38u + 92u * buffer, sizeof(DRAWENV)));
    PutDispEnv((DISPENV *)psx_addr(0x8009FAF0u + 20u * buffer, sizeof(DISPENV)));
}

static uint32 ob_movie_8008D408(uint32 filename, uint32 frames, uint32 rgb24, uint32 setup)
{
    uint32 result = 0u;
    uint32 base = r_u32(0x8009FA30u);
    FUNCTION_MARKER(0x8008D408u, "MOVIE.BIN");
    if (setup & 0xFFu) ob_movie_8008D690(rgb24 & 0xFFu);
    ob_draft_unresolved_call(0x80055FD8u, 2u, 0u, 0x8009F9E0u);
    w_u32(0x8009F9E8u, base);
    w_u32(0x8009F9F4u, base + 0x70800u);
    w_u32(0x8009F9F8u, base + 0x7A800u);
    w_u32(0x8009F9FCu, base + 0xA0000u);
    ob_movie_8008D8D8();
    if (ob_movie_8008D928(filename, frames) & 0xFFFFu)
    {
        StUnSetRing();
        return UINT32_MAX;
    }
    w_u8(0x8009FA28u, 0u);
    ob_movie_8008D9E4();
    for (uint32 frame = 1u; !r_u8(0x8009FA28u) && frame < frames - 2u; ++frame)
    {
        sub_80054320();
        if (ob_main_80054538(14u)) { result = 1u; w_u8(0x8009FA28u, 1u); }
        if (ob_main_80054538(3u)) { result = 2u; w_u8(0x8009FA28u, 1u); }
        ob_movie_8008DA98(rgb24 & 0xFFu);
        w_u8(0x8009FA00u, r_u8(0x8009FA00u) == 0u);
        if (!r_u8(0x8009FA28u)) ob_movie_8008D9E4();
        DecDCToutSync(0);
        VSync(0);
        ob_movie_swap_display();
        ob_movie_8008DBA4(rgb24 & 0xFFu);
        ob_native_pump();
    }
    VSync(0);
    ob_movie_swap_display();
    StUnSetRing();
    return result;
}

static uint32 ob_movie_8008D0D8(uint32 filename, uint32 frames, uint32 rgb24, uint32 setup, uint32 scale)
{
    uint32 stats = ob_draft_scratch_acquire(16u);
    uint32 size, begin, result;
    FUNCTION_MARKER(0x8008D0D8u, "MOVIE.BIN");
    w_u32(0x8009FA34u, scale & 0xFFu);
    sub_800260C8(stats);
    size = r_u32(stats + 4u);
    w_u32(0x8009FB1Cu, 0u);
    sub_80026694(0x8009FB1Cu, size, 0u);
    begin = r_u32(0x8009FB1Cu);
    if (begin > 0x80110000u || begin + size <= 0x801B3BFFu)
        result = UINT32_MAX;
    else
    {
        w_u32(0x8009FA30u, 0x80126800u);
        result = ob_movie_8008D408(filename, frames, rgb24 & 0xFFu, setup & 0xFFu);
    }
    sub_80026758(0x8009FB1Cu);
    ob_draft_scratch_release(stats);
    return result;
}

uint32 ob_native_movie_dispatch(uint32 target, uint32 count, const uint32 *args)
{
    switch (target)
    {
    case 0x8008DD9Cu:
        if (count != 1u) ob_native_missing(target, 1u, count);
        return ob_movie_8008DD9C(args[0]);
    case 0x8008D0D8u:
        if (count != 5u) ob_native_missing(target, 5u, count);
        return ob_movie_8008D0D8(args[0], args[1], args[2], args[3], args[4]);
    case 0x8008E3B4:
        if (count != 0) ob_native_missing(target, 0, count);
        return ob_movie_8008E3B4();
    case 0x8008DFE0:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_movie_8008DFE0(args[0]);
    case 0x8008DF84:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_movie_8008DF84(args[0], args[1]);
    case 0x8008E1F4:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_movie_8008E1F4(args[0], args[1]);
    case 0x8008E31C:
        if (count != 0) ob_native_missing(target, 0, count);
        return ob_movie_8008E31C();
    case 0x8008E284:
        if (count != 0) ob_native_missing(target, 0, count);
        return ob_movie_8008E284();
    case 0x8008E160:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_movie_8008E160(args[0], args[1]);
    case 0x8008DF08:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_movie_8008DF08(args[0], args[1]);
    case 0x8008E064:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_movie_8008E064(args[0]);
    case 0x8008E3CC:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_movie_8008E3CC(args[0]);
    case 0x8008E530:
        if (count != 2) ob_native_missing(target, 2, count);
        return ob_movie_8008E530(args[0], args[1]);
    case 0x8008E500:
        if (count != 1) ob_native_missing(target, 1, count);
        return ob_movie_8008E500(args[0]);
    default:
        ob_native_missing(target, UINT32_MAX, count);
    }
}
