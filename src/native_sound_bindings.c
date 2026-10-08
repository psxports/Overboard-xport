#include "native_sound_bindings.h"
#include "native_runtime.h"
#include "psx_spu.h"

static void bind_native_transfer(uint32 restore_address)
{
    SpuNativeTransferGuestBinding transfer;
    uint32 shift = r_u32(0x80076364u);
    uint32 callback = r_u32(0x80076374u);
    uint32 address;
    if (shift > 15u)
        ob_native_missing(0x80062A24u, 15u, shift);
    if (callback)
        /* TODO Canonical synchronous upload cannot dispatch guest completion callbacks */
        ob_native_missing(callback, 0u, 1u);
    transfer.requested_mode = 0x80075ED8u;
    transfer.normalized_mode = 0x80076358u;
    transfer.address_units = 0x80076354u;
    transfer.completion = 0x80076370u;
    transfer.completion_callback = 0x80076374u;
    transfer.source_address = 0x80076390u;
    transfer.dma_blocks = 0x80076394u;
    transfer.address_shift = shift;
    if (!spu_bind_native_transfer_guest(&transfer))
        ob_native_missing(0x80062A78u, 1u, 0u);
    if (restore_address)
    {
        /* Rebinding resets the private byte cursor so restore actual guest address units */
        address = (uint32)r_u16(0x80076354u) << shift;
        if (SpuSetTransferStartAddr(address) != address)
            ob_native_missing(0x80062A24u, address, 0u);
    }
}

void ob_native_sound_bindings_init(void)
{
    const SpuMallocGuestBinding heap = {
        0x80076364u, 0x8007636Cu, 0x80076398u, 0x8007639Cu,
        0x800763A0u, 0x80075EE0u, 0x80075EE4u
    };
    uint32 shift = r_u32(0x80076364u);

    /* Bind the reviewed SDK guest fields without rewriting their initial state */
    if (!spu_bind_malloc_guest(&heap))
        ob_native_missing(0x800610B0u, 1u, 0u);
    if (shift > 15u)
        ob_native_missing(0x80062A24u, 15u, shift);
    /* Original SDK selects ten work addresses and ten 68 byte register records */
    spu_bind_reverb_presets((const uint32 *)psx_addr(0x800763A4u, 10u * 4u),
        (const uint8 *)psx_addr(0x800763F4u, 10u * 68u), shift);
    bind_native_transfer(0u);
}

void xport_bind_native_spu_transfer(void)
{
    if (spu_transfer_failed())
        ob_native_missing(0x80062AACu, 1u, 0u);
    bind_native_transfer(1u);
}

