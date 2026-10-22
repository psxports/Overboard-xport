#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

static uint32 ob_game_copy_words(uint32 destination, uint32 source, uint32 size, uint32 zero_word_result)
{
    uint32 words = size >> 2;
    if (words == 0u)
        return zero_word_result;
    for (uint32 index = 0u; index < words; ++index)
    {
        uint32 value = r_u32(source);
        source += 4u;
        w_u32(destination, value);
        destination += 4u;
    }
    return 0u;
}

uint32 ob_game_800C1030(uint32 destination, uint32 source, uint32 size)
{
    FUNCTION_MARKER(0x800C1030u, "GAME.BIN");
    /* Callers use the copied memory; the zero-word return carrier is unspecified */
    return ob_game_copy_words(destination, source, size, 0u);
}

uint32 ob_game_800C0FC8(uint32 destination, uint32 source, uint32 size)
{
    FUNCTION_MARKER(0x800C0FC8u, "GAME.BIN");
    uint32 result = size & 3u;
    if (result == 0u)
    {
        uint32 destination_alignment = destination & 3u;
        result = source & 3u;
        if (destination_alignment == 0u && result == 0u)
            return ob_game_copy_words(destination, source, size, result);
    }
    if (size == 0u)
        return result;
    for (uint32 index = 0u; index < size; ++index)
    {
        uint32 value = r_u8(source);
        ++source;
        w_u8(destination, value);
        ++destination;
    }
    return 0u;
}

uint32 ob_game_800C0FA8(uint32 destination, uint32 source)
{
    FUNCTION_MARKER(0x800C0FA8u, "GAME.BIN");
    return ob_game_800C0FC8(destination, source, 28u);
}
