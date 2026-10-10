#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

static sint32 ob_game_init_add(sint32 first, sint32 second)
{
    return (sint32)((uint32)first + (uint32)second);
}

static sint32 ob_game_init_sub(sint32 first, sint32 second)
{
    return (sint32)((uint32)first - (uint32)second);
}

static sint32 ob_game_init_product(sint32 first, sint32 second)
{
    return (sint32)((uint32)first * (uint32)second);
}

static sint32 ob_game_init_smooth(sint32 difference, sint32 limit)
{
    sint32 sixth = difference / 6;
    if (sixth >= 3 || sixth <= -3)
        difference = sixth;
    if (difference > limit)
        difference = limit;
    if (difference < -limit)
        difference = -limit;
    return difference;
}

void ob_game_8009450C(uint32 object, uint32 camera)
{
    FUNCTION_MARKER(0x8009450Cu, "GAME.BIN");
    w_u32(0x800D5C8Cu, object);
    w_u32(0x800D5C84u, camera);
}

void ob_game_8009470C(uint32 distance, uint32 unused_a1, uint32 angle)
{
    FUNCTION_MARKER(0x8009470Cu, "GAME.BIN");
    w_u32(0x800C4CDCu, distance);
    w_u16(0x800C4CF0u, angle);
}

uint32 ob_game_80093D00(uint32 index)
{
    FUNCTION_MARKER(0x80093D00u, "GAME.BIN");
    uint32 offset = index * 28u;
    ob_game_8009470C(r_u32(0x800C4D28u + offset),
                    r_u32(0x800C4D2Cu + offset),
                    (uint32)r_s16(0x800C4D24u + offset));
    uint32 result = r_u32(0x800C4D3Cu + offset);
    w_u32(0x800C8300u, result);
    return result;
}

uint32 ob_game_80097E04(void)
{
    FUNCTION_MARKER(0x80097E04u, "GAME.BIN");
    w_u16(0x800C9100u, 0u);
    w_u16(0x800C84C8u, 1u);
    w_u16(0x800C8320u, 1u);
    return 1u;
}

uint32 ob_game_800C1104(void)
{
    FUNCTION_MARKER(0x800C1104u, "GAME.BIN");
    uint32 type = r_u8(r_u32(0x80077190u) + 41u);
    if (type >= 5u)
        return type * 4u;
    if (type == 2u)
    {
        w_u32(0x800C991Cu, 0x008C0000u);
        w_u32(0x800C9920u, 0x005F0000u);
        w_u32(0x800C9924u, 0x00190000u);
        w_u32(0x800C9944u, 0x00780000u);
        w_u32(0x800C9948u, 0x00780000u);
        w_u32(0x800C994Cu, 0x00780000u);
        w_u32(0x800C9950u, 0x00420000u);
        w_u32(0x800C9954u, 0x00420000u);
        w_u32(0x800C9958u, 0x00420000u);
        w_u32(0x800C9A78u, 0x00640000u);
        w_u32(0x800C9A7Cu, 0x00850000u);
        w_u32(0x800C9A80u, 0x00C80000u);
        w_u32(0x800C9A84u, 0x00090000u);
        w_u32(0x800C9A88u, 0x00120000u);
        w_u32(0x800C9A90u, 0x001E0000u);
        w_u32(0x800C9A94u, 0x002D0000u);
        w_u32(0x800C9910u, 0x00960000u);
        w_u32(0x800C9914u, 0x00960000u);
        w_u32(0x800C9918u, 0x00960000u);
        w_u32(0x800C9928u, 0x00280000u);
        w_u32(0x800C992Cu, 0x00280000u);
        w_u32(0x800C9930u, 0x00280000u);
        w_u32(0x800C9938u, 0x00960000u);
        w_u32(0x800C993Cu, 0x00960000u);
        w_u32(0x800C9940u, 0x00960000u);
        w_u32(0x800C9A8Cu, 0x00280000u);
        w_u32(0x800C9A98u, 0x00460000u);
        return 0x00460000u;
    }
    w_u32(0x800C991Cu, 0x00A50000u);
    w_u32(0x800C9920u, 0x006E0000u);
    w_u32(0x800C9924u, 0x00220000u);
    w_u32(0x800C9928u, 0x00420000u);
    w_u32(0x800C992Cu, 0x00420000u);
    w_u32(0x800C9930u, 0x00420000u);
    w_u32(0x800C9944u, 0x00960000u);
    w_u32(0x800C9948u, 0x00960000u);
    w_u32(0x800C994Cu, 0x00960000u);
    w_u32(0x800C9950u, 0x00600000u);
    w_u32(0x800C9954u, 0x00600000u);
    w_u32(0x800C9958u, 0x00600000u);
    w_u32(0x800C9A78u, 0x00740000u);
    w_u32(0x800C9A7Cu, 0x00A60000u);
    w_u32(0x800C9A80u, 0x00F10000u);
    w_u32(0x800C9A84u, 0x00090000u);
    w_u32(0x800C9A88u, 0x00150000u);
    w_u32(0x800C9A8Cu, 0x002F0000u);
    w_u32(0x800C9A90u, 0x00260000u);
    w_u32(0x800C9A94u, 0x00370000u);
    w_u32(0x800C9910u, 0x00C80000u);
    w_u32(0x800C9914u, 0x00C80000u);
    w_u32(0x800C9918u, 0x00C80000u);
    w_u32(0x800C9938u, 0x00C80000u);
    w_u32(0x800C993Cu, 0x00C80000u);
    w_u32(0x800C9940u, 0x00C80000u);
    w_u32(0x800C9A98u, 0x00500000u);
    return 0x00500000u;
}

uint32 ob_game_80093E08(uint32 state)
{
    FUNCTION_MARKER(0x80093E08u, "GAME.BIN");
    sint32 extra_z = 0;
    w_u32(0x800C4D14u, state);
    if (r_u8(0x8006C230u) < 2u && r_u32(0x800D5C8Cu) == 0u)
        return 0u;
    uint32 temporary = ob_draft_scratch_acquire(60u);
    uint32 first_matrix = temporary;
    uint32 second_matrix = temporary + 24u;
    uint32 position = temporary + 48u;
    if (r_u8(0x8006C230u) < 2u)
    {
        sub_80045378(r_u32(r_u32(0x800D5C8Cu) + 44u), state, 0x800C4CD0u);
        w_u32(0x800C4CD4u, 0u);
    }
    else
    {
        uint32 index;
        for (index = 0u; index < 5u; ++index)
        {
            uint32 object = r_u32(0x8006C138u + index * 4u);
            if (object != 0u && r_u32(object + 288u) != 22u && r_u32(object + 288u) != 20u)
            {
                sub_80045378(r_u32(object + 44u), state, position);
                break;
            }
        }
        if (index == 5u)
        {
            ob_draft_scratch_release(temporary);
            return 1u;
        }
        sint32 min_x = r_s32(position);
        sint32 max_x = min_x;
        sint32 min_z = r_s32(position + 8u);
        sint32 max_z = min_z;
        for (++index; index < 5u; ++index)
        {
            uint32 object = r_u32(0x8006C138u + index * 4u);
            if (object == 0u || r_u32(object + 288u) == 22u || r_u32(object + 288u) == 20u)
                continue;
            sub_80045378(r_u32(object + 44u), state, position);
            sint32 x = r_s32(position);
            sint32 z = r_s32(position + 8u);
            if (x > max_x) max_x = x;
            if (x < min_x) min_x = x;
            if (z > max_z) max_z = z;
            if (z < min_z) min_z = z;
        }
        sint32 middle_x = ob_game_init_add(max_x, min_x) / 2;
        sint32 middle_z = ob_game_init_add(max_z, min_z) / 2;
        if (r_u32(0x800C4D20u) != 0u)
        {
            w_u32(0x800C4CD0u, (uint32)middle_x);
            w_u32(0x800C4CD4u, 0u);
            w_u32(0x800C4CD8u, (uint32)middle_z);
        }
        else
        {
            sint32 x = r_s32(0x800C4CD0u);
            sint32 z = r_s32(0x800C4CD8u);
            w_u32(0x800C4CD0u, (uint32)ob_game_init_sub(x, ob_game_init_smooth(ob_game_init_sub(x, middle_x), 3200)));
            w_u32(0x800C4CD4u, 0u);
            w_u32(0x800C4CD8u, (uint32)ob_game_init_sub(z, ob_game_init_smooth(ob_game_init_sub(z, middle_z), 3200)));
        }
        sint32 width = ob_game_init_sub(max_x, min_x);
        sint32 depth = ob_game_init_sub(max_z, min_z);
        sint32 distance = ob_game_init_sub(r_s32(0x800C4D7Cu), 25000);
        if (width >= 10000 || depth >= 8000)
        {
            sint32 horizontal = ob_game_init_product(ob_game_init_sub(width, 10000), 12) / 16;
            sint32 vertical = ob_game_init_product(ob_game_init_sub(depth, 8000), 20) / 16;
            if (horizontal < vertical) horizontal = vertical;
            distance = ob_game_init_sub(distance, horizontal);
            if (horizontal > 0) extra_z = -(horizontal >> 3);
        }
        if (r_u32(0x800C4D20u) == 0u)
            distance = ob_game_init_smooth(distance, 1200);
        w_u32(0x800C4D7Cu, (uint32)ob_game_init_sub(r_s32(0x800C4D7Cu), distance));
        w_u32(0x800C4D18u, 3u);
        ob_game_80093D00(3u);
    }
    uint32 angle_offset = 2u * ((r_u16(0x800C4CF0u) + 8u) >> 4);
    sint32 distance = r_s32(0x800C4CDCu);
    sint32 offset_x;
    sint32 offset_y;
    sint32 offset_z;
    if ((r_u32(0x800C8300u) & 8u) != 0u)
    {
        sub_80029E54(first_matrix);
        offset_x = 0;
        offset_y = ob_game_init_product(distance, r_s16(0x8006C304u + angle_offset)) / 16384;
        w_u32(0x800C4CF4u, (uint32)offset_y);
        sint32 cosine = ob_game_init_product(distance, r_s16(0x8006CB04u + angle_offset)) / 16384;
        offset_z = (sint32)(0u - (uint32)cosine);
    }
    else
    {
        uint32 transform = r_u32(r_u32(0x800D5C84u) + 124u);
        sub_80029F58((uint32)r_s16(transform + 4u), first_matrix);
        offset_y = ob_game_init_product(distance, r_s16(0x8006C304u + angle_offset)) / 16384;
        uint32 yaw_offset = 2u * ((r_u16(transform + 4u) + 8u) >> 4);
        sint32 sine = ob_game_init_product(offset_y, r_s16(0x8006C304u + yaw_offset));
        offset_x = (sint32)(0u - (uint32)sine) / 24576;
        sint32 cosine = ob_game_init_product(offset_y, r_s16(0x8006CB04u + yaw_offset));
        w_u32(0x800C4CF4u, (uint32)offset_y);
        offset_z = (sint32)(0u - (uint32)cosine) / 24576;
    }
    sub_8002ADFC(first_matrix, (uint32)r_s16(0x800C4CF2u), second_matrix);
    sub_8002A870(second_matrix, (uint32)r_s16(0x800C4CF0u), 0x800D64A0u);
    w_u32(0x800C4CFCu, r_u32(0x800C4CD0u) + (uint32)offset_x);
    w_u32(0x800C4D00u, r_u32(0x800C4CD4u) + (uint32)offset_y);
    w_u32(0x800C4D04u, r_u32(0x800C4CD8u) + (uint32)offset_z + (uint32)extra_z);
    uint32 result = r_u32(0x800C8300u) & 16u;
    if (result != 0u)
    {
        ob_draft_unresolved_call(0x8002A110u, 2u, 0x800D6760u, first_matrix);
        result = sub_8002A870(first_matrix, 15616u, 0x800D64A0u);
    }
    ob_draft_scratch_release(temporary);
    return result;
}

uint32 ob_game_80093C44(void)
{
    FUNCTION_MARKER(0x80093C44u, "GAME.BIN");
    w_u32(0x800C4D20u, 1u);
    ob_game_80093E08(r_u32(0x80077334u));
    w_u32(0x800C4D20u, 0u);
    return sub_80044D50();
}
