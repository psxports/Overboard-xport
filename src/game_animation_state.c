#include "psx.h"
#include "game_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800B7C7C(uint32 animation, uint32 type, uint32 variant)
{
    FUNCTION_MARKER(0x800B7C7Cu, "GAME.BIN");
    uint32 signed_type = (uint32)(sint32)(sint16)type;
    uint32 signed_variant = (uint32)(sint32)(sint16)variant;
    uint32 table_offset = (35u * signed_type + 7u * signed_variant) * 2u;
    uint32 type_offset = signed_type * 4u;
    uint16 word;
    uint8 byte;
    w_u32(animation + 100u, 0u);
    w_u32(animation + 96u, 0u);
    w_u8(animation + 113u, 0u);
    w_u8(animation + 112u, 0u);
    word = r_u16(0x800C5B66u + table_offset);
    w_u16(animation + 110u, 0u);
    w_u16(animation + 108u, 0u);
    w_u8(animation + 115u, 0u);
    w_u8(animation + 116u, 0u);
    w_u8(animation + 114u, 0u);
    w_u16(animation + 106u, word);
    w_u16(animation + 104u, word);
    byte = r_u8(0x800C5EECu + type_offset);
    w_u8(animation + 136u, byte);
    byte = r_u8(0x800C5EEDu + type_offset);
    w_u8(animation + 135u, (uint8)type);
    w_u8(animation + 137u, byte);
    word = r_u16(0x800C5B5Cu + table_offset);
    w_u16(animation + 118u, word);
    word = r_u16(0x800C5B5Eu + table_offset);
    w_u16(animation + 120u, word);
    word = r_u16(0x800C5B60u + table_offset);
    w_u16(animation + 122u, word);
    word = r_u16(0x800C5B62u + table_offset);
    w_u16(animation + 124u, word);
    word = r_u16(0x800C5B64u + table_offset);
    w_u16(animation + 126u, word);
    word = r_u16(0x800C5B66u + table_offset);
    w_u16(animation + 128u, word);
    word = r_u16(0x800C5B68u + table_offset);
    w_u8(animation + 134u, 128u);
    w_u16(animation + 132u, 0u);
    w_u16(animation + 130u, word);
    return 128u;
}
