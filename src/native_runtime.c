#include "draft_signatures.h"
#include "native_runtime.h"
#include "native_graphics.h"
#include "native_heap.h"
#include "native_services.h"
#include "native_timers.h"
#include "native_sound_bindings.h"
#include "native_card.h"
#include "native_cd_toc.h"
#include "psx_gpu.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

/* Canonical disc services currently lack declarations in the shared header */
sint32 CdInit(void);
sint32 CdRead(sint32 count, uint32 *destination, sint32 mode);
sint32 CdReadSync(sint32 mode, uint8 *result);
static uint32 native_cd_read_pending;

static void native_cd_sync_event(uint8 status, uint8 *result)
{
    (void)status;
    (void)result;
    DeliverEvent(0xF0000003u, 0x20u);
}

static void native_cd_ready_event(uint8 status, uint8 *result)
{
    (void)status;
    (void)result;
    DeliverEvent(0xF0000003u, 0x40u);
}

const uint32 ob_native_skip_intro_movies = 1u;
const uint32 xport_cd_ready_callback_address = 0x80073AF4u;
const uint32 xport_cd_sync_callback_address = 0x80073AF0u;
const uint32 xport_cd_status_address = 0x80073B00u;
const uint32 xport_cd_setloc_table_address = 0x80073A68u;
const uint32 xport_spu_register_pointer_address = 0x8007633Cu;

/* Addressable native temporaries occupy unused RAM below the executable */
static const uint32 scratch_begin = 0x80009000u;
static uint32 scratch_cursor = 0x80010000u;
static uint32 scratch_frames[256];
static uint32 scratch_depth;
static SVECTOR renderer_vertices[3];
static sint32 renderer_screen[3];
static sint32 renderer_depth[3];

__declspec(noreturn) void ob_native_missing(uint32 target, uint32 expected, uint32 supplied)
{
    char message[256];
    FILE *log;
    snprintf(message, sizeof(message), "Unimplemented native call %08X (expected args %u, supplied %u)", target, expected, supplied);
    log = fopen("../status/native-repair/last-error.log", "w");
    if (log) { fputs(message, log); fputc('\n', log); fclose(log); }
    fprintf(stderr, "%s\n", message);
    xport_message_error("Overboard! startup failure", message);
    exit(1);
}

uint32 ob_native_missing_value(uint32 owner, const char *carrier)
{
    fprintf(stderr, "Missing carrier %s in guest function %08X\n", carrier, owner);
    ob_native_missing(owner, UINT32_MAX, UINT32_MAX);
}

void ob_native_runtime_init(void)
{
    ob_native_timers_init();
    ob_native_sound_bindings_init();
    ob_native_card_init("../tools/duckstation/data/user/bios/ps-30e.bin");
    /* Native BIOS event storage lives below the executable load area */
    xport_guest_fill(0x80008000u, 0u, 32u * 28u);
    w_u32(0xA0000120u, 0x80008000u);
    w_u32(0xA0000124u, 32u * 28u);
    if (!psx_bios_bind_events(0x80008000u, 32u * 28u))
        ob_native_missing(0x80055884u, 32u, 0u);
}

uint32 ob_draft_scratch_acquire(uint32 size)
{
    uint32 aligned = (size + 15u) & ~15u;
    if (aligned < size || aligned > scratch_cursor - scratch_begin || scratch_depth == 256u)
        ob_native_missing(0x80010000u, 0x7000u, size);
    scratch_frames[scratch_depth++] = scratch_cursor;
    scratch_cursor -= aligned;
    return scratch_cursor;
}

void ob_draft_scratch_release(uint32 address)
{
    if (!scratch_depth || address != scratch_cursor)
        ob_native_missing(address, scratch_cursor, scratch_depth);
    scratch_cursor = scratch_frames[--scratch_depth];
}

static uint32 native_malloc(uint32 size)
{
    static uint32 cursor;
    uint32 base = r_u32(0x80075EA0u);
    uint32 capacity = r_u32(0x80075EA4u);
    uint32 aligned = (size + 7u) & ~7u;
    uint32 result;
    if (!cursor) cursor = (base + 7u) & ~7u;
    if (aligned < size || cursor < base || cursor - base > capacity || aligned > capacity - (cursor - base)) return 0u;
    result = cursor;
    cursor += aligned;
    return result;
}

static uint32 native_call(uint32 target, uint32 argument_count, uint32 *args)
{
    uint32 index;
    uint32 graphics_result;
    switch (target)
    {
        case 0x80058668u:
            if (argument_count != 3u) ob_native_missing(target, 3u, argument_count);
            if (!xport_guest_copy(xport_guest_ref(args[0]), xport_guest_ref(args[1]), args[2])) ob_native_missing(target, 3u, argument_count); return args[0];
        case 0x80059CA8u:
            if (argument_count != 1u) ob_native_missing(target, 1u, argument_count);
            return (uint32)VSync((sint32)args[0]);
        case 0x8005C064u:
            if (argument_count != 1u) ob_native_missing(target, 1u, argument_count);
            return ob_native_reset_graph(args[0]);
        case 0x8005C2D4u:
            if (argument_count != 1u) ob_native_missing(target, 1u, argument_count);
            return (uint32)SetGraphDebug((sint32)args[0]);
        case 0x8005C468u:
            if (argument_count != 1u) ob_native_missing(target, 1u, argument_count);
            SetDispMask((sint32)args[0]); return 0u;
        case 0x8005C504u:
            if (argument_count != 1u) ob_native_missing(target, 1u, argument_count);
            return (uint32)DrawSync((sint32)args[0]);
        case 0x8005EE9Cu:
            if (argument_count != 3u) ob_native_missing(target, 3u, argument_count);
            if (!xport_guest_fill(args[0], (uint8)args[1], args[2])) ob_native_missing(target, 3u, argument_count); return UINT32_MAX;
        case 0x8005EEE0u:
            if (argument_count != 0u) ob_native_missing(target, 0u, argument_count);
            InitGeom(); return 0u;
        case 0x80063F68u:
            if (argument_count != 2u) ob_native_missing(target, 2u, argument_count);
            ob_copy_string(args[0] + (uint32)strlen((const char *)psx_addr(args[0], 1u)), args[1]); return args[0];
        case 0x80063F78u:
            if (argument_count != 2u) ob_native_missing(target, 2u, argument_count);
            return (uint32)strcmp((const char *)psx_addr(args[0], 1u), (const char *)psx_addr(args[1], 1u));
        case 0x80063F88u:
            if (argument_count != 3u) ob_native_missing(target, 3u, argument_count);
            return (uint32)strncmp((const char *)psx_addr(args[0], 1u), (const char *)psx_addr(args[1], 1u), args[2]);
        case 0x80063F98u:
            if (argument_count != 2u) ob_native_missing(target, 2u, argument_count);
            return ob_copy_string(args[0], args[1]), args[0];
        case 0x80063FA8u:
            if (argument_count != 3u) ob_native_missing(target, 3u, argument_count);
            for (index = 0u; index < args[2]; ++index) { uint8 value = r_u8(args[1]); w_u8(args[0] + index, value); if (value) ++args[1]; } return args[0];
        case 0x80063FB8u:
            if (argument_count != 1u) ob_native_missing(target, 1u, argument_count);
            return (uint32)strlen((const char *)psx_addr(args[0], 1u));
        case 0x80063FC8u:
            if (argument_count != 3u) ob_native_missing(target, 3u, argument_count);
            if (!xport_guest_copy(xport_guest_ref(args[0]), xport_guest_ref(args[1]), args[2])) ob_native_missing(target, 3u, argument_count); return args[0];
        case 0x80063FD8u:
            if (argument_count != 3u) ob_native_missing(target, 3u, argument_count);
            if (!xport_guest_fill(args[0], (uint8)args[1], args[2])) ob_native_missing(target, 3u, argument_count); return args[0];
        case 0x80064894u:
            if (argument_count != 3u) ob_native_missing(target, 3u, argument_count);
            if (!xport_guest_copy(xport_guest_ref(args[0]), xport_guest_ref(args[1]), args[2])) ob_native_missing(target, 3u, argument_count); return args[0];
        case 0x80065B60u:
            if (argument_count != 2u) ob_native_missing(target, 2u, argument_count);
            if (!xport_guest_fill(args[0], 0u, args[1])) ob_native_missing(target, 2u, argument_count); return args[0];
        case 0x80057CD0u:
            if (argument_count != 2u) ob_native_missing(target, 2u, argument_count);
            return CdSearchFilePSX(psx_addr(args[0], 24u), (const char *)psx_addr(args[1], 1u)) ? args[0] : 0u;
        case 0x80056048u:
            if (argument_count != 3u) ob_native_missing(target, 3u, argument_count);
            if (ob_native_cd_audio_call(args[0], args[1], args[2], &graphics_result)) return graphics_result;
            return CD_cw((uint8)args[0], args[1] ? (const uint8 *)psx_addr(args[1], 1u) : NULL, args[2] ? (uint8 *)psx_addr(args[2], 8u) : NULL, 0u) == 0 ? 1u : 0u;
        case 0x800562ACu:
            if (argument_count != 3u) ob_native_missing(target, 3u, argument_count);
            if (ob_native_cd_audio_call(args[0], args[1], args[2], &graphics_result)) return graphics_result;
            return (uint32)CdControlB((uint8)args[0], args[1] ? (uint8 *)psx_addr(args[1], 1u) : NULL, args[2] ? (uint8 *)psx_addr(args[2], 8u) : NULL);
        case 0x80058A98u:
            if (argument_count != 3u) ob_native_missing(target, 3u, argument_count);
            {
                sint32 read_result = CdRead((sint32)args[0], (uint32 *)psx_addr(args[1], 1u), (sint32)args[2]);
                native_cd_read_pending = 1u;
                return (uint32)read_result;
            }
        case 0x80058BA0u:
            if (argument_count != 2u) ob_native_missing(target, 2u, argument_count);
            {
                sint32 read_result = CdReadSync((sint32)args[0], args[1] ? (uint8 *)psx_addr(args[1], 1u) : NULL);
                if (native_cd_read_pending && read_result <= 0)
                {
                    uint32 callback = r_u32(0x80073E04u);
                    native_cd_read_pending = 0u;
                    if (callback == 0x80055E54u)
                        DeliverEvent(0xF0000003u, 0x40u);
                    else if (callback)
                        /* TODO Canonical CdRead lacks guest callback result delivery */
                        ob_native_missing(callback, 2u, 0u);
                }
                return (uint32)read_result;
            }
        case 0x80055884u:
            if (argument_count != 4u) ob_native_missing(target, 4u, argument_count);
            return (uint32)OpenEventPSX(args[0],args[1],args[2],args[3]);
        case 0x80055894u:
            if (argument_count != 1u) ob_native_missing(target, 1u, argument_count);
            return (uint32)CloseEventPSX(args[0]);
        case 0x800558A4u:
            if (argument_count != 1u) ob_native_missing(target, 1u, argument_count);
            return (uint32)TestEvent(args[0]);
        case 0x800558B4u:
            if (argument_count != 1u) ob_native_missing(target, 1u, argument_count);
            return (uint32)EnableEventPSX(args[0]);
        case 0x800558C4u:
            if (argument_count != 1u) ob_native_missing(target, 1u, argument_count);
            return (uint32)DisableEventPSX(args[0]);
        case 0x80055E7Cu:
            if (argument_count != 2u) ob_native_missing(target, 2u, argument_count);
            DeliverEvent(args[0], args[1]); return 0u;
        case 0x80056018u:
            if (argument_count != 1u) ob_native_missing(target, 1u, argument_count);
            if (args[0] && args[0] != 0x80055E04u)
                /* TODO Canonical guest callback adapter currently aborts */
                ob_native_missing(args[0], 2u, 0u);
            index = r_u32(0x80073AF0u);
            w_u32(0x80073AF0u, args[0]);
            CdSyncCallback(args[0] ? native_cd_sync_event : NULL);
            return index;
        case 0x80056030u:
            if (argument_count != 1u) ob_native_missing(target, 1u, argument_count);
            if (args[0] && args[0] != 0x80055E2Cu)
                /* TODO Canonical guest callback adapter currently aborts */
                ob_native_missing(args[0], 2u, 0u);
            index = r_u32(0x80073AF4u);
            w_u32(0x80073AF4u, args[0]);
            CdReadyCallback(args[0] ? native_cd_ready_event : NULL);
            return index;
        case 0x80058C6Cu:
            if (argument_count != 1u) ob_native_missing(target, 1u, argument_count);
            if (args[0] && args[0] != 0x80055E54u)
                /* TODO Canonical CdRead lacks guest callback result delivery */
                ob_native_missing(args[0], 2u, 0u);
            index = r_u32(0x80073E04u);
            w_u32(0x80073E04u, args[0]);
            return index;
        case 0x8001DF34u:
            if (argument_count != 1u) ob_native_missing(target, 1u, argument_count);
            index = r_u8(0x8006C00Cu);
            if (index) w_u8(0x8006C010u, (uint8)args[0]);
            return index;
        case 0x800563F0u:
            if (argument_count != 1u) ob_native_missing(target, 1u, argument_count);
            return (uint32)CdMix((CdlATV *)psx_addr(args[0], sizeof(CdlATV)));
        case 0x80026460u:
            if (argument_count != 0u) ob_native_missing(target, 0u, argument_count);
            for (index = 0u; index < 8u; ++index)
            {
                uint32 entry = 0x80078E48u + index * 16u;
                w_u8(entry, 1u << index);
                w_u32(entry + 4u, 0u);
                w_u32(entry + 8u, index);
                w_u32(entry + 12u, 0u);
            }
            w_u8(0x80077250u, 0u);
            return 0u;
        case 0x8002679Cu:
            if (argument_count != 2u) ob_native_missing(target, 2u, argument_count);
            return sub_800277D0(r_u32(args[0]) - 40u, args[1] & 0xFFu);
        case 0x80059EACu:
            if (argument_count != 0u) ob_native_missing(target, 0u, argument_count);
            return (uint32)ResetCallback();
        case 0x80055D74u:
        {
            if (argument_count != 0u) ob_native_missing(target, 0u, argument_count);
            if (!CdInit()) return 0u;
            w_u32(0x80073AF0u, 0x80055E04u);
            w_u32(0x80073AF4u, 0x80055E2Cu);
            w_u32(0x80073E04u, 0x80055E54u);
            CdSyncCallback(native_cd_sync_event);
            CdReadyCallback(native_cd_ready_event);
            native_cd_read_pending = 0u;
            return CD_cw(1u, NULL, NULL, 0u) == 0 ? 1u : 0u;
        }
        case 0x80055FD8u:
            if (argument_count != 2u) ob_native_missing(target, 2u, argument_count);
            return (uint32)CD_sync((sint32)args[0], args[1] ? (uint8 *)psx_addr(args[1], 8u) : NULL);
        case 0x80064008u:
            if (argument_count != 1u) ob_native_missing(target, 1u, argument_count);
            return native_malloc(args[0]);
        default:
            if (ob_native_graphics_call(target, argument_count, args, &graphics_result)) return graphics_result;
            if (ob_native_heap_call(target, argument_count, args, &graphics_result)) return graphics_result;
            if (ob_native_services_call(target, argument_count, args, &graphics_result)) return graphics_result;
            if (ob_native_card_call(target, argument_count, args, &graphics_result)) return graphics_result;
            return ob_native_dispatch(target, argument_count, args);
    }
}

void ob_native_pump(void)
{
    static uint32 running;
    static uint32 presented = UINT32_MAX;
    sint32 frame;
    if (running) return;
    running = 1u;
    ob_native_timers_poll();
    frame = VSync(-1);
    if (frame < 0) ob_native_missing(0x80059CA8u, 1u, 0u);
    if ((uint32)frame != presented)
    {
        gpu_present();
        presented = (uint32)frame;
    }
    running = 0u;
}

uint32 ob_draft_unresolved_call(uint32 target, uint32 argument_count, ...)
{
    uint32 args[16];
    uint32 index;
    uint32 result;
    va_list list;
    if (argument_count > 16u) ob_native_missing(target, 16u, argument_count);
    va_start(list, argument_count);
    for (index = 0u; index < argument_count; ++index) args[index] = va_arg(list, uint32);
    va_end(list);
    result = native_call(target, argument_count, args);
    ob_native_pump();
    return result;
}

void ob_draft_gte_load_vertex(uint32 slot, uint32 address)
{
    if (slot >= 3u) ob_native_missing(slot, 3u, slot);
    renderer_vertices[slot].vx = (sint16)r_u16(address);
    renderer_vertices[slot].vy = (sint16)r_u16(address + 2u);
    renderer_vertices[slot].vz = (sint16)r_u16(address + 4u);
    renderer_vertices[slot].pad = (sint16)r_u16(address + 6u);
}

void ob_draft_gte_command(uint32 opcode)
{
    sint32 flags;
    if ((opcode & 63u) == 0x30u)
        gte_project3_full_depth(renderer_vertices, renderer_screen, renderer_depth, &flags);
    else if ((opcode & 63u) == 1u)
    {
        renderer_screen[0] = renderer_screen[1];
        renderer_screen[1] = renderer_screen[2];
        renderer_depth[2] = gte_project_full_depth(renderer_vertices, &renderer_screen[2], &flags);
    }
    else xport_gte_execute(opcode);
}

void ob_draft_gte_store_data(uint32 reg, uint32 address)
{
    if (reg >= 12u && reg <= 14u) w_u32(address, (uint32)renderer_screen[reg - 12u]);
    else w_u32(address, xport_gte_read_data(reg));
}
