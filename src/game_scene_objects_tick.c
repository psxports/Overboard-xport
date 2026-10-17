#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

/* Preserve the original signed division traps before evaluating native C division */
static uint32 scene_tick_divide(uint32 numerator, uint32 denominator, int remainder)
{
    if (denominator == 0u)
        return ob_native_missing_value(0x80092C6Cu, "Original break 7: signed division by zero");
    if (numerator == 0x80000000u && denominator == 0xFFFFFFFFu)
        return ob_native_missing_value(0x80092C6Cu, "Original break 6: signed division overflow");
    if (remainder)
        return (uint32)((sint32)numerator % (sint32)denominator);
    return (uint32)((sint32)numerator / (sint32)denominator);
}

static int scene_tick_pause(uint32 node, uint32 *elapsed)
{
    uint32 end = r_u32(node + 160u);
    if ((sint32)*elapsed <= (sint32)end &&
        (sint32)r_u32(node + 156u) < (sint32)*elapsed)
        return 1;
    if ((sint32)*elapsed >= (sint32)end)
        *elapsed -= end - r_u32(node + 156u);
    return 0;
}

static uint32 scene_tick_angular_product(uint32 node, uint32 elapsed, int reverse)
{
    uint32 range = (uint32)r_u16(node + 182u) - (uint32)r_u16(node + 180u);
    uint32 direction = (uint32)(sint32)(sint8)r_u8(node + 193u);
    if (reverse) direction = 0u - direction;
    return direction * range * elapsed;
}

static void scene_tick_apply_angle(uint32 node)
{
    uint32 angle = r_u16(node + 188u);
    sub_800440B8(r_u32(node + 108u),
        angle == 0u ? 1u : (uint32)(sint32)(sint16)angle);
}

void ob_game_80092C6C(uint32 time)
{
    FUNCTION_MARKER(0x80092C6Cu, "GAME.BIN");
    uint32 node = r_u32(0x800C8304u);
    while (node != 0u)
    {
        uint32 elapsed = time - r_u32(node + 136u);
        if (elapsed == 0u) goto stamp;
        if ((r_u16(r_u32(node + 132u)) & 0x10u) != 0u) goto stamp;
        uint32 mode = r_u8(node + 192u);
        if (mode == 16u)
        {
            uint32 random = sub_8001B008();
            uint32 upper = r_u16(node + 182u);
            uint32 lower = r_u16(node + 180u);
            uint32 remainder = scene_tick_divide(random, upper - lower, 1);
            uint32 shape = r_u32(node + 108u);
            uint32 angle = lower + remainder;
            w_u16(node + 188u, (uint16)angle);
            sub_800440B8(shape, (uint32)(sint32)(sint16)angle);
            goto stamp;
        }
        if (mode == 32u)
        {
            uint32 delta = time - r_u32(node + 28u);
            uint32 x_delta = (uint32)(sint32)(sint16)r_u16(node + 170u) * delta;
            uint32 z_delta = (uint32)(sint32)(sint16)r_u16(node + 178u) * delta;
            uint32 y_delta = (uint32)(sint32)(sint16)r_u16(node + 174u) * delta;
            uint32 z = (uint32)r_u16(node + 176u) + z_delta;
            uint32 x = (uint32)r_u16(node + 168u) + x_delta;
            uint32 y = (uint32)r_u16(node + 172u) + y_delta;
            w_u16(node + 168u, (uint16)x);
            w_u16(node + 176u, (uint16)z);
            w_u16(node + 172u, (uint16)y);
            uint32 matrices = ob_draft_scratch_acquire(48u);
            uint32 first = matrices;
            uint32 second = matrices + 24u;
            sub_80029EEC((uint32)(sint32)(sint16)z, first);
            sub_8002A9DC(first, (uint32)(sint32)(sint16)r_u16(node + 168u), second);
            sub_8002AF54(second, (uint32)(sint32)(sint16)r_u16(node + 172u), first);
            sub_80045848(r_u32(r_u32(node + 104u) + 44u), first);
            ob_draft_scratch_release(matrices);
            goto stamp;
        }
        if (mode != 1u && mode != 2u && mode != 4u && mode != 8u && mode != 64u)
            goto stamp;

        uint32 repeat = mode == 1u ? 0u : r_u32(node + 164u);
        uint32 pause = r_u32(node + 152u);
        uint32 group_size = 0u;
        if (mode == 64u && repeat != 0u)
            group_size = scene_tick_divide(r_u8(node + 190u), repeat, 0);
        uint32 duration = 0u;
        int retained_duration = repeat != 0u && pause != 0u;
        if (repeat != 0u)
        {
            duration = r_u32(node + 144u);
            elapsed = scene_tick_divide(elapsed, duration + pause, 1);
        }
        if (pause != 0u && scene_tick_pause(node, &elapsed))
        {
            if (mode == 4u || mode == 8u || mode == 64u)
                scene_tick_apply_angle(node);
            goto stamp;
        }

        if (mode == 1u || mode == 2u)
        {
            uint32 product = elapsed * r_u8(node + 190u);
            if (!retained_duration) duration = r_u32(node + 144u);
            uint32 frame = scene_tick_divide(product, duration, 0);
            if (mode == 1u)
            {
                uint32 table = r_u32(node + 128u);
                w_u8(node + 191u, (uint8)frame);
                uint32 shape = r_u32(node + 108u);
                w_u32(shape + 40u, r_u32(table + 4u * (uint32)(uint8)frame));
            }
            else
            {
                int reverse = (sint32)elapsed >= (sint32)r_u32(node + 148u);
                w_u8(node + 191u, (uint8)frame);
                if (reverse)
                {
                    frame = (uint32)r_u8(node + 190u) - (frame + 1u);
                    w_u8(node + 191u, (uint8)frame);
                    uint32 table = r_u32(node + 128u);
                    uint32 shape = r_u32(node + 108u);
                    w_u32(shape + 40u, r_u32(table + 4u * (uint32)(uint8)frame));
                }
            }
            goto stamp;
        }

        if (mode == 8u)
        {
            uint32 half = r_u32(node + 148u);
            int reverse = (sint32)elapsed > (sint32)half;
            uint32 product = scene_tick_angular_product(node,
                reverse ? elapsed - half : elapsed, reverse);
            uint32 quotient = scene_tick_divide(product, half, 0);
            uint32 base = r_u16(node + (reverse ? 186u : 184u));
            uint32 frames = r_u8(node + 190u);
            w_u16(node + 188u, (uint16)(base + quotient));
            if (frames >= 2u)
            {
                product = elapsed * frames;
                duration = r_u32(node + 144u);
                uint32 frame = scene_tick_divide(product, duration, 0);
                uint32 table;
                if (!reverse)
                {
                    table = r_u32(node + 128u);
                    w_u8(node + 191u, (uint8)frame);
                    frame = (uint32)(uint8)frame;
                }
                else
                {
                    int reverse_frame = (sint32)elapsed >= (sint32)r_u32(node + 148u);
                    w_u8(node + 191u, (uint8)frame);
                    if (reverse_frame)
                    {
                        frame = (uint32)r_u8(node + 190u) - (frame + 1u);
                        w_u8(node + 191u, (uint8)frame);
                    }
                    frame = r_u8(node + 191u);
                    table = r_u32(node + 128u);
                }
                uint32 shape = r_u32(node + 108u);
                w_u32(shape + 40u, r_u32(table + 4u * frame));
            }
            scene_tick_apply_angle(node);
            goto stamp;
        }

        {
            uint32 product = scene_tick_angular_product(node, elapsed, 0);
            if (!retained_duration) duration = r_u32(node + 144u);
            uint32 quotient = scene_tick_divide(product, duration, 0);
            uint32 base = r_u16(node + 184u);
            uint32 frames = r_u8(node + 190u);
            w_u16(node + 188u, (uint16)(base + quotient));
            if (frames >= 2u)
            {
                product = elapsed * frames;
                duration = r_u32(node + 144u);
                uint32 frame = scene_tick_divide(product, duration, 0);
                if (mode == 64u && repeat != 0u)
                {
                    frame = scene_tick_divide(frame, group_size, 1);
                    uint32 shape = r_u32(node + 108u);
                    uint32 table = r_u32(node + 128u);
                    w_u8(node + 191u, (uint8)frame);
                    w_u32(shape + 40u, r_u32(table + 4u * (uint32)(uint8)frame));
                }
                else
                {
                    uint32 table = r_u32(node + 128u);
                    w_u8(node + 191u, (uint8)frame);
                    uint32 shape = r_u32(node + 108u);
                    w_u32(shape + 40u, r_u32(table + 4u * (uint32)(uint8)frame));
                }
            }
            scene_tick_apply_angle(node);
        }

stamp:
        w_u32(node + 28u, time);
        node = r_u32(node + 124u);
    }
}
