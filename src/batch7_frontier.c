#include "batch7_frontier.h"
#include "audit_frontier.h"

uint32 ob_init_base_record(uint32 record, uint32 value)
{
    FUNCTION_MARKER(0x80043CDCu, "SLES_008.65");
    w_u32(record, 0u);
    w_u32(record + 8u, value);
    w_u32(record + 4u, 0u);
    return record;
}

uint32 ob_init_audio_callback(void)
{
    FUNCTION_MARKER(0x80044C58u, "SLES_008.65");
    uint32 identifier = ob_memory_find_identifier(0x8006625Cu);
    return ob_memory_set_slot_word(identifier & 0xFFFFu, 0x80044C90u);
}

uint32 ob_enable_audio_processing(void)
{
    FUNCTION_MARKER(0x8001E050u, "SLES_008.65");
    uint32 enabled = r_u8(0x8006C00Cu);
    if (enabled != 0u)
        w_u8(0x8006C011u, 1u);
    return 1u;
}
