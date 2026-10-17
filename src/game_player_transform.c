#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

uint32 ob_game_800B3AD0(uint32 object, uint32 angle_pointer, uint32 position)
{
    FUNCTION_MARKER(0x800B3AD0u, "GAME.BIN");
    uint32 matrix = ob_draft_scratch_acquire(24u);
    uint32 vector = ob_draft_scratch_acquire(12u);
    uint32 temporary = ob_draft_scratch_acquire(56u);
    uint32 coordinates[3] = {r_u32(position), r_u32(position + 4u), r_u32(position + 8u)};
    for (uint32 axis = 0u; axis < 3u; ++axis)
        w_u32(vector + axis * 4u, coordinates[axis]);
    uint32 parameters = r_u32(object + 108u);
    uint32 scene = r_u32(object + 44u);
    for (uint32 axis = 0u; axis < 2u; ++axis)
    {
        sint32 angle = r_s16(parameters + 84u + axis * 2u);
        sint32 magnitude = angle < 0 ? -angle : angle;
        if (magnitude >= (axis == 0u ? 129 : 17))
        {
            uint32 speed_address = parameters + 88u + axis * 2u;
            w_u16(speed_address, (uint32)r_u16(speed_address) - 10u - (uint32)(angle / 8));
        }
    }
    for (uint32 axis = 0u; axis < 2u; ++axis)
    {
        uint32 angle_address = parameters + 84u + axis * 2u;
        uint32 speed_address = parameters + 88u + axis * 2u;
        if (r_s16(angle_address) >= 8193)
        {
            w_u16(angle_address, 8192u);
            w_u16(speed_address, 0u);
        }
        if (r_s16(angle_address) < -8192)
        {
            w_u16(angle_address, (uint32)-8192);
            w_u16(speed_address, 0u);
        }
    }
    if (r_u32(object + 288u) != 3u)
    {
        if (r_s16(parameters + 88u) >= 433) w_u16(parameters + 88u, 432u);
        if (r_s16(parameters + 88u) < -432) w_u16(parameters + 88u, (uint32)-432);
        if (r_s16(parameters + 90u) >= 833) w_u16(parameters + 90u, 832u);
        if (r_s16(parameters + 90u) < -832) w_u16(parameters + 90u, (uint32)-832);
        sint32 speed = r_s16(parameters + 88u);
        if (speed >= 33) w_u16(parameters + 88u, (uint32)(speed - 8));
        speed = r_s16(parameters + 88u);
        if (speed < -32) w_u16(parameters + 88u, (uint32)(speed + 8));
        speed = r_s16(parameters + 90u);
        if (speed >= 65) w_u16(parameters + 90u, (uint32)(speed - 16));
        speed = r_s16(parameters + 90u);
        if (speed < -64) w_u16(parameters + 90u, (uint32)(speed + 16));
    }
    w_u16(parameters + 84u, (uint32)r_u16(parameters + 84u) + (uint32)(r_s16(parameters + 88u) / 4));
    w_u16(parameters + 86u, (uint32)r_u16(parameters + 86u) + (uint32)(r_s16(parameters + 90u) / 4));
    sub_80029F58((uint32)r_s16(angle_pointer), temporary);
    sub_8002AB48(temporary, (uint32)r_s16(parameters + 84u), matrix);
    sub_8002A870(matrix, (uint32)r_s16(parameters + 86u), temporary);
    sub_80045848(scene, temporary);
    sub_80045B74(scene);
    for (uint32 axis = 0u; axis < 3u; ++axis)
        w_u32(vector + axis * 4u, r_u32(vector + axis * 4u) + r_u32(parameters + 68u + axis * 4u));
    sub_80045A7C(scene, r_u32(0x80077334u));
    sub_80045A44(scene, vector);
    uint32 result = 0x92490000u;
    for (uint32 axis = 0u; axis < 3u; ++axis)
    {
        uint32 address = parameters + 68u + axis * 4u;
        sint32 displacement = r_s32(address);
        sint32 magnitude = displacement < 0 ? (sint32)(0u - (uint32)displacement) : displacement;
        if (magnitude > 0)
        {
            sint32 damped = (sint32)((uint32)displacement * 6u) / 7;
            w_u32(address, (uint32)damped);
            sint32 absolute = damped < 0 ? -damped : damped;
            uint32 clear = absolute < 101 ? 1u : 0u;
            if (clear != 0u) w_u32(address, 0u);
            if (axis == 2u) result = clear;
        }
    }
    ob_draft_scratch_release(temporary);
    ob_draft_scratch_release(vector);
    ob_draft_scratch_release(matrix);
    return result;
}
