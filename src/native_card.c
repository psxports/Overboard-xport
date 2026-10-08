#include "native_card.h"
#include "native_runtime.h"
#include "native_timers.h"
#include "psx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Immutable SCPH-5502 kernel data copied or relocated by BIOS startup */
typedef struct
{
    uint32 rom_offset;
    uint32 destination;
    uint32 bytes;
    uint8 expected[20];
} CardKernelSeed;
static const CardKernelSeed card_seeds[] =
{
    { 0x1018Cu, 0x68Cu, 4u, { 0x80,0x0C,0x00,0x00 } },
    { 0x104E0u, 0x9E0u, 4u, { 0xD0,0x43,0x00,0x00 } },
    { 0x15F08u, 0xCF0u, 8u, { 0x00,0x00,0x02,0x3C,0x1C,0x64,0x42,0x24 } },
    { 0x15F44u, 0x6444u, 20u, { 0x74,0x10,0x62,0x8C,0x00,0x00,0x00,0x00,0x80,0x00,0x42,0x30,0x50,0x00,0x40,0x10,0x00,0x00,0x00,0x00 } },
    { 0x14898u, 0x4D98u, 20u, { 0x0A,0x00,0x6F,0x94,0x00,0x00,0x08,0x3C,0x25,0xC0,0xE2,0x01,0x12,0x00,0x19,0x37,0x0A,0x00,0x79,0xA4 } }
};
static uint32 card_initialized;

static void card_failure(const char *reason)
{
    fprintf(stderr, "Native BIOS card initialization failed: %s\n", reason);
    abort();
}

void ob_native_card_init(const char *bios_path)
{
    FILE *file;
    uint8 data[20];
    size_t index;
    if (card_initialized) card_failure("Kernel data already initialized");
    file = xport_fopen(bios_path, "rb");
    if (!file) card_failure("Cannot open supplied BIOS ROM");
    if (fseek(file, 0, SEEK_END) || ftell(file) != 524288L)
    {
        fclose(file);
        card_failure("Unexpected BIOS ROM size");
    }
    /* Validate every required range before changing guest kernel data */
    for (index = 0u; index < sizeof(card_seeds) / sizeof(card_seeds[0]); ++index)
    {
        const CardKernelSeed *seed = &card_seeds[index];
        if (fseek(file, (long)seed->rom_offset, SEEK_SET) ||
            fread(data, 1u, seed->bytes, file) != seed->bytes ||
            memcmp(data, seed->expected, seed->bytes))
        {
            fclose(file);
            card_failure("Supplied BIOS kernel bytes differ from SCPH-5502");
        }
    }
    fclose(file);
    for (index = 0u; index < sizeof(card_seeds) / sizeof(card_seeds[0]); ++index)
    {
        const CardKernelSeed *seed = &card_seeds[index];
        memcpy(psx_addr(seed->destination, seed->bytes), seed->expected, seed->bytes);
    }
    card_initialized = 1u;
}

sint32 ob_native_card_call(uint32 target, uint32 count, const uint32 *args, uint32 *result)
{
    uint32 routine;
    uint32 destination;
    uint32 offset;
    (void)args;
    if (target != 0x80063D60u && target != 0x80063E18u) return 0;
    if (count) ob_native_missing(target, 0u, count);
    if (!card_initialized) card_failure("Kernel data is not initialized");
    ob_native_timers_critical(0u);
    xport_bios_enter_critical();
    if (target == 0x80063D60u)
    {
        /* B0 selector 0x56 returns the C0 table at 0x674 */
        routine = r_u32(0x674u + 6u * 4u);
        destination = ((r_u32(routine + 0x70u) & 0xFFFFu) << 16) +
            (r_u32(routine + 0x74u) & 0xFFFFu) + 0x28u;
        if (destination != 0x6444u) card_failure("Unexpected first kernel patch destination");
        for (offset = 0u; offset < 20u; offset += 4u)
            w_u32(destination + offset, r_u32(0x80063D08u + offset));
        w_u32(0x80077284u, destination + 20u);
    }
    else
    {
        /* B0 selector 0x57 returns the B0 table at 0x874 */
        routine = r_u32(0x874u + 91u * 4u);
        destination = routine + 0x9C8u;
        if (destination != 0x4D98u) card_failure("Unexpected second kernel patch destination");
        for (offset = 0u; offset < 20u; offset += 4u)
        {
            uint32 original = r_u32(destination + offset);
            uint32 patch = r_u32(0x80063DE8u + offset);
            w_u32(0x80063DE8u + offset, original);
            w_u32(destination + offset, patch);
        }
    }
    /* The original leaves interrupts disabled for its caller to restore */
    FlushCache();
    /* Retain the computed V0 carrier before the void cache flush */
    *result = target == 0x80063D60u ? destination + 20u : routine + 20u;
    return 1;
}

