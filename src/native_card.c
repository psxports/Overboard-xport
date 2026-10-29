#include "native_card.h"
#include "native_runtime.h"
#include "psx.h"
#include "native_extra_signatures.h"
#include <stdio.h>
#include <string.h>

enum { OB_SAVE_STATE_BYTES = 376, OB_SAVE_BYTES = 8 + 2 * OB_SAVE_STATE_BYTES };

static sint32 ob_native_read_save(uint8 data[OB_SAVE_BYTES])
{
    sint32 size = xport_load(data, OB_SAVE_BYTES);
    if (size == 0) return 0;
    if (size != OB_SAVE_BYTES || memcmp(data, "OBSV\1\0\0\0", 8) != 0)
    {
        fprintf(stderr, "Overboard: Cannot read game save (%d)\n", size);
        return -1;
    }
    return 1;
}

sint32 ob_native_save_game(void)
{
    uint8 data[OB_SAVE_BYTES];
    uint32 state = ob_draft_scratch_acquire(OB_SAVE_STATE_BYTES);
    sint32 result;
    memcpy(data, "OBSV\1\0\0\0", 8);
    ob_main_8001D5F0(state, 0);
    memcpy(data + 8, psx_addr(state, OB_SAVE_STATE_BYTES), OB_SAVE_STATE_BYTES);
    ob_main_8001D5F0(state, r_u8(0x8006C231u));
    memcpy(data + 8 + OB_SAVE_STATE_BYTES, psx_addr(state, OB_SAVE_STATE_BYTES), OB_SAVE_STATE_BYTES);
    ob_draft_scratch_release(state);
    result = xport_save(data, sizeof(data));
    if (result != 1) fprintf(stderr, "Overboard: Cannot write game save\n");
    return result;
}

static sint32 ob_native_restore_save(sint32 checkpoint)
{
    uint8 data[OB_SAVE_BYTES];
    sint32 result = ob_native_read_save(data);
    uint32 state;
    if (result != 1) return result;
    state = ob_draft_scratch_acquire(OB_SAVE_STATE_BYTES);
    memcpy(psx_addr(state, OB_SAVE_STATE_BYTES), data + 8, OB_SAVE_STATE_BYTES);
    ob_main_8001D818(state);
    if (checkpoint)
    {
        memcpy(psx_addr(state, OB_SAVE_STATE_BYTES), data + 8 + OB_SAVE_STATE_BYTES, OB_SAVE_STATE_BYTES);
        ob_main_8001D818(state);
    }
    ob_draft_scratch_release(state);
    return 1;
}

sint32 ob_native_load_game(void)
{
    return ob_native_restore_save(1);
}

sint32 ob_native_load_profile(void)
{
    return ob_native_restore_save(0);
}

