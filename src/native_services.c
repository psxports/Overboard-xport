#include "native_services.h"
#include "native_timers.h"
#include "native_runtime.h"
#include "psx.h"

/* These canonical SDK entry points lack shared header declarations */
uint32 _SpuInit(uint32 mode);
uint32 SpuInitMalloc(uint32 count, uint32 table);

static void service_arguments(uint32 target, uint32 count, uint32 required)
{
    if (count != required)
        ob_native_missing(target, required, count);
}

sint32 ob_native_services_call(uint32 target, uint32 count, const uint32 *args, uint32 *result)
{
    switch (target)
    {
        case 0x80063B94u:
            service_arguments(target, count, 1u);
            *result = (uint32)_card_info((sint32)args[0]);
            return 1;
        case 0x80063BA4u:
            service_arguments(target, count, 1u);
            *result = psx_bios_card_load_guest(args[0]);
            return 1;
        case 0x80063BD4u:
            service_arguments(target, count, 1u);
            /* The SDK marks a new card then writes sector 63 with a null buffer */
            _new_card();
            *result = psx_bios_card_write_guest(args[0], 63u, 0u);
            return 1;
        case 0x80055B2Cu:
        {
            CdlLOC toc[100];
            sint32 tracks;
            sint32 track;
            service_arguments(target, count, 1u);
            tracks = CdGetToc(toc);
            if (tracks > 0)
            {
                /* GetTD supplies minute and second; the original SDK clears frames */
                for (track = 0; track <= tracks; ++track)
                {
                    uint32 destination = args[0] + (uint32)track * 4u;
                    w_u8(destination, toc[track].minute);
                    w_u8(destination + 1u, toc[track].second);
                    w_u8(destination + 2u, 0u);
                }
            }
            *result = (uint32)tracks;
            return 1;
        }
        case 0x80055984u:
            service_arguments(target, count, 3u);
            *result = ob_native_timers_set(args[0], args[1], args[2]);
            return 1;
        case 0x80055A24u:
            service_arguments(target, count, 1u);
            /* Read the counter maintained by the native clock bridge */
            *result = ob_native_timers_get(args[0]);
            return 1;
        case 0x80055A5Cu:
        {
            uint32 counter;
            uint32 address;
            uint32 mask;
            service_arguments(target, count, 1u);
            counter = (uint16)args[0];
            address = r_u32(0x80073A40u) + 4u;
            mask = r_u32(0x80073A48u + 4u * counter);
            /* Original SDK enables the counter interrupt mask even before range return */
            w_u32(address, r_u32(address) | mask);
            *result = ob_native_timers_start(args[0]);
            return 1;
        }
        case 0x80055A90u:
            service_arguments(target, count, 1u);
            /* Canonical StopRCnt dereferences the guest pointer slot itself */
            StopRCnt((uint16)args[0], 0x80073A40u, 0x80073A48u);
            *result = ob_native_timers_stop(args[0]);
            return 1;
        case 0x80063CD8u:
            service_arguments(target, count, 1u);
            *result = xport_bios_init_card(args[0]);
            return 1;
        case 0x80063CE8u:
        case 0x80055874u:
            service_arguments(target, count, 0u);
            *result = xport_bios_start_card();
            return 1;
        case 0x80059E8Cu:
            service_arguments(target, count, 1u);
            *result = ChangeClearPAD(args[0]);
            return 1;
        case 0x8006591Cu:
        case 0x80065AC4u:
            service_arguments(target, count, 4u);
            /* Original TAP initialization clears both complete guest packet buffers */
            if (!xport_guest_fill(args[0], 0u, args[1]) ||
                !xport_guest_fill(args[2], 0u, args[3]))
                ob_native_missing(target, 1u, 0u);
            w_u32(0x800772D4u, 0u);
            w_u32(0x800772C8u, 0u);
            w_u32(0x800772E0u, 0u);
            w_u32(0x800772E4u, 0u);
            w_u32(0x800772F0u, 0u);
            w_u32(0x800772F4u, 0u);
            w_u32(0x800772D8u, args[0]);
            w_u32(0x800772DCu, args[2]);
            w_u32(0x800772E8u, args[1]);
            w_u32(0x800772ECu, args[3]);
            w_u32(0x800772BCu, 0x8006582Cu);
            w_u32(0x800772C0u, 0x800658A0u);
            w_u32(0x800772B8u, 0u);
            w_u32(0x800772C4u, 0u);
            /* Canonical input publishes the digital packet consumed by the game */
            *result = InitPAD(args[0], args[1], args[2], args[3]);
            if (*result)
                w_u32(0x800772C8u, 1u);
            return 1;
        case 0x800659E4u:
        case 0x80065AE4u:
            service_arguments(target, count, 0u);
            /* Canonical StartPAD owns BIOS polling and interrupt bookkeeping */
            *result = StartPAD();
            return 1;
        case 0x80061034u:
            service_arguments(target, count, 0u);
            /* Original quit detaches SDK events without erasing voices or SPU RAM */
            *result = 1u;
            if (r_u32(0x80076338u) == 1u)
            {
                w_u32(0x80076338u, 0u);
                xport_bios_enter_critical();
                w_u32(0x80076374u, 0u);
                w_u32(0x80076378u, 0u);
                DMACallback(4u, NULL);
                CloseEventPSX(r_u32(0x80075ED0u));
                *result = (uint32)DisableEventPSX(r_u32(0x80075ED0u));
                xport_bios_exit_critical();
            }
            return 1;
        case 0x8006272Cu:
        {
            uint32 bits;
            uint32 high;
            uint32 queued;
            uint32 opposite;
            uint32 current;
            service_arguments(target, count, 2u);
            bits = args[1] & 0xFFFFFFu;
            high = bits >> 16;
            if (args[0] != 0u && args[0] != 1u)
            {
                *result = 1u;
                return 1;
            }
            if (r_u32(0x80076334u) & 1u)
            {
                queued = args[0] ? 0x80086A18u : 0x80086A1Cu;
                opposite = args[0] ? 0x80086A1Cu : 0x80086A18u;
                w_u16(queued, (uint16)bits);
                w_u16(queued + 2u, (uint16)high);
                w_u32(0x80075F00u, r_u32(0x80075F00u) | 1u);
                current = r_u32(0x80075EFCu);
                w_u32(0x80075EFCu, args[0] ? current | bits : current & ~bits);
                current = r_u16(opposite);
                if (current & bits)
                    w_u16(opposite, (uint16)(current & ~bits));
                current = r_u16(opposite + 2u);
                *result = current & high;
                if (*result)
                {
                    *result = current & ~high;
                    w_u16(opposite + 2u, (uint16)*result);
                }
            }
            else
            {
                SpuSetKey((sint32)args[0], bits);
                current = r_u32(0x80075ED4u);
                *result = args[0] ? current | bits : current & ~bits;
                w_u32(0x80075ED4u, *result);
            }
            return 1;
        }
        case 0x800602F0u:
            service_arguments(target, count, 1u);
            if (args[0] != 0u)
                /* TODO Canonical SPU warm initialization is unavailable */
                ob_native_missing(target, 0u, args[0]);
            *result = _SpuInit(args[0]);
            return 1;
        case 0x800610B0u:
            service_arguments(target, count, 2u);
            *result = SpuInitMalloc(args[0], args[1]);
            return 1;
        case 0x80061104u:
            service_arguments(target, count, 1u);
            *result = (uint32)SpuMalloc((sint32)args[0]);
            return 1;
        case 0x80061748u:
            service_arguments(target, count, 1u);
            *result = (uint32)SpuSetReverb((sint32)args[0]);
            return 1;
        case 0x80061924u:
            service_arguments(target, count, 1u);
            *result = (uint32)SpuSetReverbModeParam((SpuReverbAttr *)psx_addr(args[0], sizeof(SpuReverbAttr)));
            return 1;
        case 0x80062304u:
            service_arguments(target, count, 1u);
            *result = (uint32)SpuReserveReverbWorkArea((sint32)args[0]);
            /* Original SDK stores the actual reservation result in its guest flag */
            w_u32(0x80075EE0u, *result);
            return 1;
        case 0x80062354u:
            service_arguments(target, count, 2u);
            *result = SpuSetReverbVoice((sint32)args[0], args[1]);
            return 1;
        case 0x80062580u:
            service_arguments(target, count, 1u);
            /* Canonical clear checks heap occupation and clears the original preset area synchronously */
            *result = (uint32)SpuClearReverbWorkArea((sint32)args[0]);
            return 1;
        case 0x80062930u:
            service_arguments(target, count, 1u);
            *result = (uint32)SpuGetKeyStatus(args[0]);
            return 1;
        case 0x80062A24u:
        {
            uint32 address;
            uint32 shift;
            service_arguments(target, count, 1u);
            address = SpuSetTransferStartAddr(args[0]);
            shift = r_u32(0x80076364u) & 31u;
            /* Original SDK returns the aligned address in SPU units */
            *result = (uint16)(address >> shift);
            return 1;
        }
        case 0x80062A78u:
            service_arguments(target, count, 1u);
            *result = (uint32)SpuSetTransferMode((sint32)args[0]);
            return 1;
        case 0x80062AACu:
            service_arguments(target, count, 1u);
            *result = (uint32)SpuIsTransferCompleted((sint32)args[0]);
            return 1;
        case 0x80062B54u:
        {
            uint32 mask;
            service_arguments(target, count, 1u);
            mask = r_u32(args[0]);
            SpuSetCommonAttr((SpuCommonAttr *)psx_addr(args[0], sizeof(SpuCommonAttr)));
            /* Original final mask branch leaves either zero or the register base in v0 */
            *result = !mask || (mask & 0x2000u) ? r_u32(0x8007633Cu) : 0u;
            return 1;
        }
        case 0x80062EE8u:
            service_arguments(target, count, 1u);
            SpuSetVoiceAttr((SpuVoiceAttr *)psx_addr(args[0], sizeof(SpuVoiceAttr)));
            /* The reviewed default voice range exits with v0 equal to zero */
            *result = 0u;
            return 1;
        default:
            return 0;
    }
}







