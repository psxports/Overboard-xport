#include "psx.h"
#include "movie_player.h"
#include "draft_signatures.h"
#include "native_runtime.h"
#include "native_cd_toc.h"
#include "native_extra_signatures.h"
#include "psx_press.h"
#include "psx_stream.h"
#include <string.h>

/* The shared player owns decoding, input, display and sound restoration */
static uint32 ob_movie_8008DD9C(uint32 mode)
{
    FUNCTION_MARKER(0x8008DD9Cu, "MOVIE.BIN");
    DecDCTReset((sint32)mode);
    return 0u;
}

static uint32 ob_movie_8008D0D8(uint32 filename, uint32 frames, uint32 rgb24, uint32 setup, uint32 scale)
{
    char path[260] = "DATA/";
    uint32 length = 5u;
    uint32 callback;
    sint32 result;
    FUNCTION_MARKER(0x8008D0D8u, "MOVIE.BIN");

    while (r_u8(filename) == '\\' || r_u8(filename) == '/') ++filename;
    while (r_u8(filename) && r_u8(filename) != ';')
    {
        uint8 character = r_u8(filename++);
        if (length == sizeof(path) - 1u) return UINT32_MAX;
        path[length++] = character == '\\' ? '/' : (char)character;
    }
    path[length] = 0;
    /* Preserve the game's guest callback across the native player boundary */
    callback = VSyncCallbackPSX(0u);
    result = xport_fmv_play(path);
    /* Restore DATA access after the standalone player releases its CD source */
    if (!ob_native_cd_files_init()) result = -1;
    VSyncCallbackPSX(callback);
    sub_80054320();
    if (result < 0)
    {
        xport_message_error("Overboard!", "Cannot play fullscreen movie");
        return UINT32_MAX;
    }
    if (result == 2) return xport_input_read(0) & PADstart ? 2u : 1u;
    return 0u;
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
