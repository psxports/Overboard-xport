#include "psx.h"
#include "draft_signatures.h"
#include "native_extra_signatures.h"
#include "native_runtime.h"
#include "game_signatures.h"
#include "decomp_208_signatures.h"
#include "psx_spu.h"

uint32 ob_main_8004472c(uint32 object)
{
    FUNCTION_MARKER(0x8004472C, "SLES_008.65");
    uint32 child = r_u32(object + 28);
    if (child)
    {
        if (r_u32(child + 12) == object) ob_main_800447fc(child);
        else ob_main_80044824(child);
    }
    child = r_u32(object + 32);
    if (child)
    {
        if (r_u32(child + 12) == object) ob_main_800447fc(child);
        else ob_main_80044824(child);
    }
    uint32 parent = r_u32(object + 36);
    if (parent) ob_main_800442b0(parent, object);
    if (r_u32(object + 24)) ob_main_80044844(object);
    w_u32(object + 8, 0);
    return ob_unlink_object_record(object);
}

uint32 ob_main_80044894(uint32 object, uint32 parent, uint32 incoming_v0)
{
    FUNCTION_MARKER(0x80044894, "SLES_008.65");
    uint32 identifier = r_u32(object + 44);
    uint32 result = incoming_v0;
    if (identifier)
    {
        result = ob_find_typed_object(parent, 0x8007711C, identifier);
        w_u32(object + 48, result);
    }
    uint32 child = r_u32(object + 28);
    if (child) result = ob_main_80044894(child, parent, result);
    child = r_u32(object + 32);
    if (child) result = ob_main_80044894(child, parent, result);
    return result;
}

sint32 ob_main_8002da80(uint32 pointer, uint32 size)
{
    FUNCTION_MARKER(0x8002DA80, "SLES_008.65");
    ob_restore_heap_pointer(pointer);
    return sub_8002D98C(size) ? -1 : 0;
}

sint32 ob_main_8002dab8(uint32 pointer, uint32 size)
{
    FUNCTION_MARKER(0x8002DAB8, "SLES_008.65");
    ob_main_8002da74(pointer);
    return ob_main_8002D9FC(size) ? -1 : 0;
}

sint32 ob_main_80030524(uint32 first, uint32 second, uint32 output)
{
    FUNCTION_MARKER(0x80030524, "SLES_008.65");
    sint32 ax = r_s16(first);
    sint32 bx = r_s16(second);
    sint32 ay = r_s16(first + 2);
    sint32 by = r_s16(second + 2);
    sint32 az = r_s16(first + 4);
    sint32 bz = r_s16(second + 4);
    uint32 sum = ax * bx;
    sum += ay * by;
    sum += az * bz;
    sint32 result = (sint32)sum >> 14;
    w_u16(output, result);
    return result;
}

sint32 ob_main_80030574(uint32 first, uint32 second, uint32 output)
{
    FUNCTION_MARKER(0x80030574, "SLES_008.65");
    uint32 local = ob_draft_scratch_acquire(16);
    sub_8003042C(first, local);
    sub_8003042C(second, local + 8);
    sint32 result = ob_main_80030524(local, local + 8, output);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_main_800357a8(uint32 record, uint32 base)
{
    FUNCTION_MARKER(0x800357A8, "SLES_008.65");
    uint32 first = r_u32(record + 8);
    uint32 second = r_u32(record + 12);
    w_u32(record + 8, base + first);
    uint32 third = r_u32(record + 16);
    w_u32(record + 12, base + second);
    uint32 fourth = r_u32(record + 20);
    uint32 result = base + third;
    w_u32(record + 16, result);
    w_u32(record + 20, base + fourth);
    return result;
}

sint32 ob_main_800513ac(uint32 object, uint32 value)
{
    FUNCTION_MARKER(0x800513AC, "SLES_008.65");
    sint32 result = ob_main_800513f0();
    if (!result)
    {
        w_u32(object + 80, value);
        w_u32(object + 108, value);
    }
    return result;
}

uint32 ob_main_80054560(uint32 incoming_counter_v0)
{
    FUNCTION_MARKER(0x80054560, "SLES_008.65");
    uint32 result = incoming_counter_v0 - 1;
    w_u32(0x80073A38, result);
    if (result) return result;
    ob_main_80054b68(r_u32(0x80084440), 0);
    ob_main_800549d4();
    return xport_bios_stop_pad();
}

uint32 ob_main_800549d4(void)
{
    FUNCTION_MARKER(0x800549D4, "SLES_008.65");
    uint32 result = r_u32(0x800771DC) - 1;
    w_u32(0x800771DC, result);
    if (result) return result;
    CloseEventPSX(r_u32(0x800882B8));
    return ob_draft_unresolved_call(0x80055A90, 1, 0xF2000001);
}

uint32 ob_main_80054b68(uint32 record, uint32 incoming_v0)
{
    FUNCTION_MARKER(0x80054B68, "SLES_008.65");
    uint32 cell = ob_draft_scratch_acquire(4);
    w_u32(cell, record);
    uint32 current = r_u32(0x800771D4);
    uint32 previous = 0;
    while (current && current != record)
    {
        previous = current;
        current = r_u32(previous);
    }
    uint32 result = incoming_v0;
    if (current)
    {
        sub_800558E4();
        uint32 next = r_u32(current);
        if (previous) w_u32(previous, next);
        else w_u32(0x800771D4, next);
        sub_800558F4();
        result = ob_release_pool_cell(cell);
    }
    ob_draft_scratch_release(cell);
    return result;
}

uint32 ob_main_8002dc90(uint32 matrix, uint32 mode)
{
    FUNCTION_MARKER(0x8002DC90, "SLES_008.65");
    if (mode == 0)
    {
        uint32 flags = r_u32(matrix + 48);
        if (flags & 1)
        {
            uint32 result = flags & 0xFFFFFFE1;
            w_u32(matrix + 48, result);
            return result;
        }
        if (flags & 2)
        {
            sub_8002F310(matrix, matrix + 70);
            return ob_main_8002FA40(matrix, matrix + 70);
        }
        ob_main_8002F594(matrix, 0x800770DC);
        uint32 result = r_u32(matrix + 48) & 0xFFFFFFFD;
        w_u32(matrix + 48, result);
        return result;
    }
    if (mode == 1)
    {
        uint32 flags = r_u32(matrix + 48);
        uint32 result;
        if (flags & 2) result = flags & 0xFFFFFFFE;
        else if (flags & 1)
        {
            ob_main_8002F5FC(matrix, matrix + 70);
            flags = r_u32(matrix + 48);
            w_u16(matrix + 18, 0);
            result = (flags & 0xFFFFFFE2) | 2;
        }
        else
        {
            ob_main_8002F594(matrix, 0x800770DC);
            result = r_u32(matrix + 48) & 0xFFFFFFFE;
        }
        w_u32(matrix + 48, result);
        return result;
    }
    if (mode != 2) return 2;
    uint32 flags = r_u32(matrix + 48);
    if (flags & 1)
    {
        if (flags & 2) return 2;
        ob_main_8002F5FC(matrix, matrix + 70);
        flags = r_u32(matrix + 48);
        w_u16(matrix + 18, 0);
        uint32 result = (flags | 2) & 0xFFFFFFE3;
        w_u32(matrix + 48, result);
        return result;
    }
    if (!(flags & 2)) return ob_main_8002F594(matrix, 0x800770DC);
    sub_8002F310(matrix, matrix + 70);
    uint32 result = r_u32(matrix + 48) | 1;
    w_u32(matrix + 48, result);
    return result;
}

uint32 ob_main_8002de20(uint32 matrix, uint32 angles, uint32 local)
{
    FUNCTION_MARKER(0x8002DE20, "SLES_008.65");
    uint32 flags = r_u32(matrix + 48);
    if (!(flags & 2))
    {
        if (!(flags & 1)) ob_main_8002F594(matrix, 0x800770DC);
        else
        {
            ob_main_8002F5FC(matrix, matrix + 70);
            flags = r_u32(matrix + 48);
            w_u16(matrix + 18, 0);
            w_u32(matrix + 48, (flags & 0xFFFFFFE3) | 2);
        }
    }
    ob_main_8002DF2C(matrix, angles, local);
    flags = r_u32(matrix + 48);
    uint32 previous = r_u16(matrix + 18);
    w_u32(matrix + 48, flags & 0xFFFFFFFE);
    uint32 limit = r_u16(matrix + 20);
    uint32 next = previous + 1;
    w_u16(matrix + 18, next);
    next &= 65535;
    uint32 result = limit < next;
    if (result)
    {
        result = r_u32(matrix + 48) & 16;
        if (result) w_u16(matrix + 18, previous);
        else
        {
            result = ob_main_8002F3D8(matrix);
            w_u16(matrix + 18, 0);
        }
    }
    return result;
}

uint32 ob_main_8002e1b0(uint32 matrix, uint32 angles, uint32 local)
{
    FUNCTION_MARKER(0x8002E1B0, "SLES_008.65");
    uint32 flags = r_u32(matrix + 48);
    if (!(flags & 2))
    {
        if (!(flags & 1)) ob_main_8002F594(matrix, 0x800770DC);
        else
        {
            ob_main_8002F5FC(matrix, matrix + 70);
            flags = r_u32(matrix + 48);
            w_u16(matrix + 18, 0);
            w_u32(matrix + 48, (flags & 0xFFFFFFE3) | 2);
        }
    }
    ob_main_8002E2BC(matrix, angles, local);
    flags = r_u32(matrix + 48);
    uint32 previous = r_u16(matrix + 18);
    w_u32(matrix + 48, flags & 0xFFFFFFFE);
    uint32 limit = r_u16(matrix + 20);
    uint32 next = previous + 1;
    w_u16(matrix + 18, next);
    next &= 65535;
    uint32 result = limit < next;
    if (result)
    {
        result = r_u32(matrix + 48) & 16;
        if (result) w_u16(matrix + 18, previous);
        else
        {
            result = ob_main_8002F3D8(matrix);
            w_u16(matrix + 18, 0);
        }
    }
    return result;
}

uint32 ob_main_8002e540(uint32 matrix, uint32 angles, uint32 local)
{
    FUNCTION_MARKER(0x8002E540, "SLES_008.65");
    uint32 flags = r_u32(matrix + 48);
    if (!(flags & 2))
    {
        if (!(flags & 1)) ob_main_8002F594(matrix, 0x800770DC);
        else
        {
            ob_main_8002F5FC(matrix, matrix + 70);
            flags = r_u32(matrix + 48);
            w_u16(matrix + 18, 0);
            w_u32(matrix + 48, (flags & 0xFFFFFFE3) | 2);
        }
    }
    ob_main_8002E64C(matrix, angles, local);
    flags = r_u32(matrix + 48);
    uint32 previous = r_u16(matrix + 18);
    w_u32(matrix + 48, flags & 0xFFFFFFFE);
    uint32 limit = r_u16(matrix + 20);
    uint32 next = previous + 1;
    w_u16(matrix + 18, next);
    next &= 65535;
    uint32 result = limit < next;
    if (result)
    {
        result = r_u32(matrix + 48) & 16;
        if (result) w_u16(matrix + 18, previous);
        else
        {
            result = ob_main_8002F3D8(matrix);
            w_u16(matrix + 18, 0);
        }
    }
    return result;
}

uint32 ob_main_8002fadc(uint32 vector, uint32 angles, uint32 output)
{
    FUNCTION_MARKER(0x8002FADC, "SLES_008.65");
    uint32 high = r_u32((vector + 3) & ~3);
    uint32 low = r_u32(vector & ~3);
    uint32 offset = vector & 3;
    uint32 pair = offset ? (low >> (offset * 8)) | (high << ((4 - offset) * 8)) : low;
    sint32 z = r_s16(vector + 4);
    uint32 end = output + 3;
    offset = end & 3;
    w_masked_u32(end & ~3, pair >> ((3 - offset) * 8), (1 << (offset + 1)) - 1);
    offset = output & 3;
    w_masked_u32(output & ~3, pair << (offset * 8), (15 << offset) & 15);
    w_u16(output + 4, z);
    ob_rotate_short_pair(output, output + 2, (sint16)(0 - r_u16(angles + 4)));
    ob_rotate_short_pair(output + 4, output + 2, r_s16(angles + 2));
    return ob_rotate_short_pair(output, output + 4, r_s16(angles));
}

uint32 ob_main_8002fb78(uint32 vector, uint32 matrix, uint32 output)
{
    FUNCTION_MARKER(0x8002FB78, "SLES_008.65");
    uint32 flags = r_u32(matrix + 48);
    if (!(flags & 2))
        ob_main_8002F594(matrix, flags & 1 ? matrix + 70 : 0x800770DC);
    return ob_main_8002fbfc(vector, matrix, output);
}

uint32 ob_main_8002fbfc(uint32 vector, uint32 matrix, uint32 output)
{
    FUNCTION_MARKER(0x8002FBFC, "SLES_008.65");
    uint32 result = 0;
    for (uint32 column = 0; column < 3; ++column)
    {
        sint32 x = r_s16(vector);
        sint32 a = r_s16(matrix + column * 2);
        uint32 sum = x * a;
        sint32 y = r_s16(vector + 2);
        sint32 b = r_s16(matrix + column * 2 + 6);
        sum += y * b;
        sint32 z = r_s16(vector + 4);
        sint32 c = r_s16(matrix + column * 2 + 12);
        sum += z * c;
        result = (sint32)sum >> 14;
        w_u16(output + column * 2, result);
    }
    return result;
}

uint32 ob_main_8002fce4(uint32 matrix, uint32 vector, uint32 output)
{
    FUNCTION_MARKER(0x8002FCE4, "SLES_008.65");
    uint32 flags = r_u32(matrix + 48);
    if (!(flags & 2))
        ob_main_8002F594(matrix, flags & 1 ? matrix + 70 : 0x800770DC);
    return ob_main_8002FD68(matrix, vector, output);
}

uint32 ob_main_8003005c(uint32 matrix, uint32 vector, uint32 output)
{
    FUNCTION_MARKER(0x8003005C, "SLES_008.65");
    uint32 flags = r_u32(matrix + 48);
    if (!(flags & 2))
        ob_main_8002F594(matrix, flags & 1 ? matrix + 70 : 0x800770DC);
    return ob_main_800300e0(matrix, vector, output);
}

static uint32 ob_matrix_add_trapping(uint32 first, uint32 second, uint32 pc)
{
    uint32 sum = first + second;
    if ((~(first ^ second) & (first ^ sum)) & 0x80000000)
        xport_mips_overflow_exception(pc);
    return sum;
}

uint32 ob_main_800300e0(uint32 matrix, uint32 vector, uint32 output)
{
    FUNCTION_MARKER(0x800300E0, "SLES_008.65");
    static const uint32 add_pc[3][2] = {
        {0x80030130, 0x80030158},
        {0x800301B0, 0x800301D8},
        {0x80030230, 0x8003025C}
    };
    uint32 result = 0;
    for (uint32 row = 0; row < 3; ++row)
    {
        sint32 coefficient = r_s16(matrix + row * 6);
        sint32 component = r_s32(vector);
        sint64 product = (sint64)coefficient * component;
        uint32 first = (uint32)(product >> 14);
        component = r_s32(vector + 4);
        coefficient = r_s16(matrix + row * 6 + 2);
        product = (sint64)component * coefficient;
        uint32 second = (uint32)(product >> 14);
        uint32 sum = ob_matrix_add_trapping(second, first, add_pc[row][0]);
        component = r_s32(vector + 8);
        coefficient = r_s16(matrix + row * 6 + 4);
        product = (sint64)component * coefficient;
        uint32 third = (uint32)(product >> 14);
        result = (uint32)((uint64)product >> 32) << 18;
        sum = ob_matrix_add_trapping(third, sum, add_pc[row][1]);
        w_u32(output + row * 4, sum);
    }
    return result;
}

uint32 ob_main_80030268(uint32 vector, uint32 matrix, uint32 output)
{
    FUNCTION_MARKER(0x80030268, "SLES_008.65");
    uint32 flags = r_u32(matrix + 48);
    if (!(flags & 2))
        ob_main_8002F594(matrix, flags & 1 ? matrix + 70 : 0x800770DC);
    return ob_main_800302ec(vector, matrix, output);
}

uint32 ob_main_800302ec(uint32 vector, uint32 matrix, uint32 output)
{
    FUNCTION_MARKER(0x800302EC, "SLES_008.65");
    uint32 result = 0;
    for (uint32 column = 0; column < 3; ++column)
    {
        sint32 a = r_s16(matrix + column * 2);
        sint32 x = r_s16(vector);
        uint32 sum = a * x;
        sint32 b = r_s16(matrix + column * 2 + 6);
        sint32 y = r_s16(vector + 2);
        sum += b * y;
        sint32 c = r_s16(matrix + column * 2 + 12);
        sint32 z = r_s16(vector + 4);
        sum += c * z;
        result = (sint32)sum >> 14;
        w_u16(output + column * 2, result);
    }
    return result;
}

uint32 ob_game_80097548(uint32 object, uint32 incoming_v0)
{
    FUNCTION_MARKER(0x80097548, "GAME.BIN");
    uint32 cell = ob_draft_scratch_acquire(4);
    w_u32(cell, object);
    uint32 result = incoming_v0;
    if (object) result = ob_release_pool_cell(cell);
    ob_draft_scratch_release(cell);
    return result;
}

uint32 ob_game_800b8dbc(uint32 node, uint32 context, uint32 time)
{
    FUNCTION_MARKER(0x800B8DBC, "GAME.BIN");
    uint32 record = ob_draft_scratch_acquire(96);
    ob_game_800B8E40(node, record, time);
    w_u32(record + 44, 0x800C4AB0);
    w_u32(record + 56, 900);
    w_u16(record + 86, 400);
    w_u16(record + 88, 400);
    w_u8(record + 92, 8);
    w_u32(record + 4, 0);
    w_u8(record + 95, 1);
    w_u32(record + 60, 500);
    w_u8(record + 93, 1);
    uint32 result = ob_game_80092408(r_u32(0x80083E34), record, time, 4);
    ob_draft_scratch_release(record);
    return result;
}

uint32 ob_game_800b970c(uint32 node, uint32 size, uint32 flags, uint32 time)
{
    FUNCTION_MARKER(0x800B970C, "GAME.BIN");
    uint32 record = ob_draft_scratch_acquire(96);
    ob_game_800B8E40(node, record, time);
    w_u32(record + 44, 0x800C4B18);
    w_u32(record + 56, 1200);
    w_u8(record + 92, 16);
    w_u16(record + 90, size);
    w_u16(record + 86, size);
    w_u16(record + 88, size);
    w_u8(record + 93, 1);
    uint32 result = ob_game_80092408(r_u32(0x80083E34), record, time, flags);
    ob_draft_scratch_release(record);
    return result;
}

uint32 ob_game_800ba1d0(uint32 descriptor_v0)
{
    FUNCTION_MARKER(0x800BA1D0, "GAME.BIN");
    uint32 type = r_u8(descriptor_v0 + 41);
    if (type != 4) return 4;
    uint32 player = r_u32(0x8006C134);
    if (!player) return 0;
    ob_append_draw_mode(0);
    ob_main_80016E4C(1);
    return ob_main_80016D24(255);
}

uint32 ob_game_800baa1c(uint32 time, uint32 incoming_counter_v0)
{
    FUNCTION_MARKER(0x800BAA1C, "GAME.BIN");
    if ((sint32)incoming_counter_v0 <= 0)
    {
        uint32 result = incoming_counter_v0 - 1;
        w_u32(0x800C84D8, result);
        return result;
    }
    uint32 descriptor = r_u32(0x80077190);
    w_u32(0x800C84D8, 20);
    uint32 count = r_u8(descriptor + 2);
    uint32 index = 0;
    while (index < count)
    {
        uint32 record = r_u32(0x80077198) + index * 16;
        if (r_u8(record) == 3 && r_u8(record + 3))
        {
            uint32 deadline = r_u32(record + 8);
            if (deadline && (sint32)time >= (sint32)deadline)
                ob_game_800BA234((index + 1) & 255, 255, time);
        }
        count = r_u8(r_u32(0x80077190) + 2);
        ++index;
    }
    return 0;
}

uint32 ob_game_800bb3d4(uint32 descriptor_v0)
{
    FUNCTION_MARKER(0x800BB3D4, "GAME.BIN");
    uint32 count = r_u8(descriptor_v0 + 2);
    uint32 index = 0;
    uint32 offset = 0;
    while (index < count)
    {
        uint32 record = r_u32(0x80077198) + offset;
        if (r_u8(record) == 1)
            w_u8(record + 3, r_u8(record + 4) ? 0 : 1);
        record = r_u32(0x80077198) + offset;
        w_u32(record + 8, r_u8(record) == 4);
        count = r_u8(r_u32(0x80077190) + 2);
        ++index;
        offset += 16;
    }
    w_u32(0x800C84D8, 20);
    return 20;
}

uint32 ob_game_800a9c38(uint32 time, uint32 previous_time_v0)
{
    FUNCTION_MARKER(0x800A9C38, "GAME.BIN");
    uint32 node = r_u32(0x800C546C);
    uint32 elapsed = time - previous_time_v0;
    uint32 local = ob_draft_scratch_acquire(48);
    uint32 result = previous_time_v0;
    while (node)
    {
        result = r_u32(node + 8);
        if (result)
        {
            uint32 x_product = r_u32(node + 12) * elapsed;
            uint32 z_product = r_u32(node + 20) * elapsed;
            uint32 y_product = r_u32(node + 16) * elapsed;
            uint32 z = r_u16(node + 28) + (sint32)z_product / 100;
            uint32 x = r_u16(node + 24) + (sint32)x_product / 100;
            w_u16(node + 28, z);
            w_u16(node + 24, x);
            uint32 y = r_u16(node + 26) + (sint32)y_product / 100;
            w_u16(node + 26, y);
            sub_80029EEC((sint16)z, local);
            sub_8002A9DC(local, r_s16(node + 24), local + 24);
            ob_rotate_matrix_rows14(local + 24, r_s16(node + 26), local);
            result = sub_80045848(r_u32(node + 4), local);
        }
        node = r_u32(node);
    }
    w_u32(0x800C8308, time);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_game_800a9fe4(uint32 object, uint32 time, uint32 target_v0)
{
    FUNCTION_MARKER(0x800A9FE4, "GAME.BIN");
    uint32 target = sub_80045464(r_u32(target_v0 + 44), time);
    uint32 position = sub_80045464(r_u32(object + 44), time);
    uint32 z = r_u32(position + 8);
    uint32 target_z = r_u32(target + 8);
    uint32 x = r_u32(position);
    uint32 target_x = r_u32(target);
    uint32 local = ob_draft_scratch_acquire(8);
    sub_80028280(z - target_z, x - target_x, local, local + 4);
    uint32 rotation = r_u32(object + 124);
    sint32 angle = r_s16(local);
    sint32 heading = r_s16(rotation + 4);
    uint32 difference = angle >= heading ? angle - heading : heading - angle;
    uint32 distance = r_u32(local + 4);
    if (distance >= 25000)
        ob_game_800A1BD4(object, 0);
    else
    {
        if (r_s32(object + 316) < (sint32)time)
        {
            ob_game_800AA898(r_u32(object + 44), time);
            w_u32(object + 316, time + 2500);
            ob_game_800A1BD4(object, 0);
        }
        if (((difference - 0x4001) & 65535) < 0x7FFF)
        {
            distance = r_u32(local + 4);
            if (distance < 15000)
            {
                if (((difference - 0x7001) & 65535) >= 0x1FFF || distance < 9001)
                    ob_game_800A1BD4(object, 5);
                else if (r_s32(object + 316) < (sint32)time)
                {
                    ob_game_800A1BD4(object, 3);
                    w_u32(object + 316, time + 10000);
                }
            }
            else if (((difference - 0x7E01) & 65535) < 0x3FF)
                ob_game_800A1BD4(object, 1);
            else if (((difference - 0x6801) & 65535) < 0x2FFF)
                ob_game_800A1BD4(object, 2);
            else
                ob_game_800A1BD4(object, ((time >> 5) & 3) ? 0 : 7);
        }
    }
    w_u32(object + 288, 18);
    ob_draft_scratch_release(local);
    return 18;
}

sint32 ob_main_8001f944(void)
{
    FUNCTION_MARKER(0x8001F944, "SLES_008.65");
    sint32 result;
    do
    {
        result = ob_draft_unresolved_call(0x80055B2C, 1, 0x80078CB0);
        w_u32(0x80078DB0, result);
    } while (result < 0);
    return result;
}

uint32 ob_main_8001f984(uint32 incoming_v0)
{
    FUNCTION_MARKER(0x8001F984, "SLES_008.65");
    uint32 result = incoming_v0;
    if (result)
    {
        result = ob_draft_unresolved_call(0x80055D74, 0);
        w_u8(0x8006C012, 0);
    }
    return result;
}

uint32 ob_main_800203bc(uint32 mode)
{
    FUNCTION_MARKER(0x800203BC, "SLES_008.65");
    uint32 result;
    if (mode == 2)
    {
        result = r_u8(0x80089968);
        if (result != 3) return result;
        ob_draft_unresolved_call(0x80056048, 3, 3, 0, 0);
        result = 1;
    }
    else
    {
        result = r_u8(0x80078DBC);
        if (!result) return result;
        uint32 parameter = 0x80078CB0 + r_u32(0x80078DB8) * 4;
        ob_draft_unresolved_call(0x80056048, 3, 22, parameter, 0);
        result = 3;
    }
    w_u8(0x80089968, result);
    return result;
}

uint32 ob_main_80020cd4(uint32 texture, uint32 palette)
{
    FUNCTION_MARKER(0x80020CD4, "SLES_008.65");
    uint32 clut_handle = sub_80025874(r_u32(texture) >> 17);
    sub_80025874((r_u32(texture) >> 2) & 32767);
    uint32 clut = r_u32(clut_handle);
    uint32 rectangle = ob_draft_scratch_acquire(8);
    w_u16(rectangle + 4, 16);
    w_u16(rectangle + 6, 1);
    clut = (clut >> 2) << 4;
    w_u16(rectangle, clut & 1023);
    w_u16(rectangle + 2, clut >> 10);
    ob_draft_unresolved_call(0x8005C7C8, 2, rectangle, palette);
    uint32 result = ob_draft_unresolved_call(0x8005C504, 1, 0);
    ob_draft_scratch_release(rectangle);
    return result;
}

uint32 ob_main_80015de8(uint32 text, uint32 output, uint32 count)
{
    FUNCTION_MARKER(0x80015DE8, "SLES_008.65");
    uint32 character = r_u8(text);
    while (character && count)
    {
        ++text;
        uint32 encoded = ob_main_80015F70(character);
        w_u16(output, ((encoded & 255) << 8) | ((encoded & 0xFF00) >> 8));
        output += 2;
        character = r_u8(text);
        --count;
    }
    uint32 space = ob_main_80015F70(32);
    space = ((space & 255) << 8) | ((space & 0xFF00) >> 8);
    while (count)
    {
        w_u16(output, space);
        --count;
        output += 2;
    }
    return space;
}

sint32 ob_main_80013ee4(uint32 object, uint32 vector, uint32 time)
{
    FUNCTION_MARKER(0x80013EE4, "SLES_008.65");
    uint32 local = ob_draft_scratch_acquire(24);
    uint32 matrix = sub_80045430((sint32)r_u32(object + 44));
    sint32 heading = ob_main_80014bac(matrix);
    sub_80045378(r_u32(object + 44), time, local);
    uint32 x = r_u32(vector);
    uint32 position_x = r_u32(local);
    w_u32(vector, x - position_x);
    uint32 y = r_u32(vector + 4);
    uint32 position_y = r_u32(local + 4);
    uint32 z = r_u32(vector + 8);
    w_u32(vector + 4, y - position_y);
    uint32 position_z = r_u32(local + 8);
    x = r_u32(vector);
    z -= position_z;
    w_u32(vector + 8, z);
    sub_80028280((sint32)x, (sint32)z, local + 16, local + 20);
    uint32 angle = 0x4000 - r_u16(local + 16) - (uint32)heading;
    w_u16(local + 16, angle);
    ob_draft_scratch_release(local);
    return (sint16)angle;
}

uint32 ob_main_800164ec(uint32 output, uint32 source, uint32 flags)
{
    FUNCTION_MARKER(0x800164EC, "SLES_008.65");
    uint32 state = ob_draft_scratch_acquire(544);
    sub_800169D0(state + 32, source);
    w_u32(state + 20, source + r_u32(source + 16));
    uint32 remaining = r_u32(source + 12);
    w_u32(state + 24, state + 32);
    w_u32(state + 4, source);
    w_u32(state, output);
    w_u16(state + 8, flags);
    w_u32(state + 12, remaining);
    if (remaining)
    {
        do
        {
            w_u32(state + 16, 308);
            sub_80016A50(state);
        } while (r_u32(state + 12));
    }
    uint32 length = r_u32(source + 12);
    remaining = r_u32(state + 12);
    ob_draft_scratch_release(state);
    return length - remaining;
}

sint32 ob_main_8001e488(uint32 index, uint32 enabled_v0)
{
    FUNCTION_MARKER(0x8001E488, "SLES_008.65");
    if (!enabled_v0) return -1;
    uint32 offset = index * 20;
    if (!r_u32(0x800778A0 + offset)) return -1;
    uint32 second = r_u32(0x800778A8 + offset);
    if (second)
    {
        SpuFree(second);
        w_u32(0x800778AC + offset, 0);
        w_u32(0x800778B0 + offset, 0);
    }
    SpuFree(r_u32(0x800778A0 + offset));
    w_u32(0x800778A4 + offset, 0);
    w_u32(0x800778B0 + offset, 0);
    return 1;
}

uint32 ob_main_80024260(uint32 wait_v0)
{
    FUNCTION_MARKER(0x80024260, "SLES_008.65");
    if (wait_v0)
        while (r_u32(0x80077620)) ob_native_pump();
    ob_draft_unresolved_call(0x8005C504, 1, 0);
    w_u32(0x8007754C, r_u32(0x8007737C));
    sub_8002CFA8();
    w_u32(0x80077620, 1);
    return 1;
}

uint32 ob_main_800242c4(uint32 alternate_v0)
{
    FUNCTION_MARKER(0x800242C4, "SLES_008.65");
    uint32 frame_buffer = r_u32(0x8007737C);
    uint32 environment = alternate_v0 ? 0x8008C6C8 : 0x8008CF70;
    return ob_draft_unresolved_call(0x8005B994, 2, frame_buffer + 112, environment);
}

sint32 ob_main_80029fc4(uint32 axis, uint32 angle, uint32 output)
{
    FUNCTION_MARKER(0x80029FC4, "SLES_008.65");
    uint32 offset = (((angle & 65535) + 8) >> 4) * 2;
    uint32 cosine = r_u16(0x8006CB04 + offset);
    sint32 x = r_s16(axis);
    sint32 complement = (sint16)(0x4000 - cosine);
    sint32 y = r_s16(axis + 2);
    sint32 z = r_s16(axis + 4);
    sint32 scaled_x = (sint16)((complement * x) >> 14);
    sint32 scaled_y = (sint16)((complement * y) >> 14);
    sint32 scaled_z = (sint16)((complement * z) >> 14);
    sint32 xx = scaled_x * x;
    sint32 yy = scaled_y * y;
    sint32 zz = scaled_z * z;
    sint32 xy = scaled_x * y;
    sint32 xz = scaled_x * z;
    sint32 yz = scaled_y * z;
    sint32 sine = r_s16(0x8006C304 + offset);
    sint32 sine_x = sine * x;
    sint32 sine_y = sine * y;
    w_u16(output, (uint32)(xx >> 14) + cosine);
    w_u16(output + 8, (uint32)(yy >> 14) + cosine);
    w_u16(output + 16, (uint32)(zz >> 14) + cosine);
    sint32 sum = (sint32)((uint32)yz + (uint32)sine_x) >> 14;
    sint32 difference = (sint32)((uint32)yz - (uint32)sine_x) >> 14;
    sint32 sine_z = sine * z;
    w_u16(output + 10, sum);
    w_u16(output + 14, difference);
    difference = (sint32)((uint32)xz - (uint32)sine_y) >> 14;
    sum = (sint32)((uint32)xz + (uint32)sine_y) >> 14;
    w_u16(output + 4, difference);
    w_u16(output + 12, sum);
    sum = (sint32)((uint32)xy + (uint32)sine_z) >> 14;
    difference = (sint32)((uint32)xy - (uint32)sine_z) >> 14;
    w_u16(output + 2, sum);
    w_u16(output + 6, difference);
    return sum;
}

uint32 ob_main_8002b3c4(uint32 first, uint32 second, uint32 output)
{
    FUNCTION_MARKER(0x8002B3C4, "SLES_008.65");
    return sub_8002B15C(second, first, output);
}

sint32 ob_main_8002b3ec(uint32 first, uint32 second, uint32 output)
{
    FUNCTION_MARKER(0x8002B3EC, "SLES_008.65");
    sint32 result = 0;
    for (uint32 row = 0; row < 3; ++row)
    {
        sint32 a = r_s16(second + row * 6);
        sint32 x = r_s16(first);
        sint32 b = r_s16(second + row * 6 + 2);
        sint32 y = r_s16(first + 2);
        sint32 c = r_s16(second + row * 6 + 4);
        sint32 z = r_s16(first + 4);
        uint32 sum = (uint32)(a * x) + (uint32)(b * y) + (uint32)(c * z);
        result = (sint32)sum >> 14;
        w_u16(output + row * 6, result);
        for (uint32 column = 1; column < 3; ++column)
        {
            x = r_s16(first + column * 6);
            y = r_s16(first + column * 6 + 2);
            z = r_s16(first + column * 6 + 4);
            sum = (uint32)(a * x) + (uint32)(b * y) + (uint32)(c * z);
            result = (sint32)sum >> 14;
            w_u16(output + row * 6 + column * 2, result);
        }
    }
    return result;
}

sint32 ob_main_8002b654(uint32 first, uint32 second, uint32 output)
{
    FUNCTION_MARKER(0x8002B654, "SLES_008.65");
    return ob_main_8002b3ec(second, first, output);
}

uint32 ob_main_8002b0b4(uint32 matrix, uint32 axis, uint32 angle, uint32 output)
{
    FUNCTION_MARKER(0x8002B0B4, "SLES_008.65");
    uint32 local = ob_draft_scratch_acquire(24);
    ob_main_80029fc4(axis, (sint16)angle, local);
    uint32 result = sub_8002B15C(matrix, local, output);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_main_8002b108(uint32 matrix, uint32 axis, uint32 angle, uint32 output)
{
    FUNCTION_MARKER(0x8002B108, "SLES_008.65");
    uint32 local = ob_draft_scratch_acquire(24);
    ob_main_80029fc4(axis, (sint16)angle, local);
    uint32 result = ob_main_8002b3c4(matrix, local, output);
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_main_80027b24(void)
{
    FUNCTION_MARKER(0x80027B24, "SLES_008.65");
    for (uint32 page_index = 0; page_index < 256; ++page_index)
    {
        uint32 table = r_u32(0x800775F4);
        uint32 page = r_u32(table + page_index * 4);
        if (!page) page = sub_80027E90(page_index);
        if (!r_u16(page + 4)) continue;
        for (uint32 byte_index = 0; byte_index < 32; ++byte_index)
        {
            uint32 bits = r_u8(page + 6 + byte_index);
            if (bits == 255) continue;
            uint32 bit_index = 0;
            while (bits & 128)
            {
                bits <<= 1;
                ++bit_index;
            }
            uint32 address = page + 6 + byte_index;
            bits = r_u8(address);
            w_u8(address, bits | (128 >> bit_index));
            uint32 result = (page_index << 8) | (byte_index << 3) | bit_index;
            uint32 remaining = r_u16(page + 4);
            w_u16(page + 4, remaining - 1);
            return result & 65535;
        }
    }
    return 0;
}

sint32 ob_main_800281d0(uint32 value)
{
    FUNCTION_MARKER(0x800281D0, "SLES_008.65");
    sint32 clamped = (sint16)value;
    if (clamped > 0x4000) clamped = 0x4000;
    else if (clamped < -0x4000) clamped = -0x4000;
    sint32 magnitude = clamped < 0 ? -clamped : clamped;
    sint32 arc;
    if (magnitude <= 0x3C00)
        arc = r_u16(0x8006EB08 + (magnitude >> 2) * 2);
    else
        arc = r_u16(0x8007090A + (magnitude - 0x3C00) * 2);
    if (clamped < 0) arc = -arc;
    return (sint16)(0x4000 - arc);
}

uint32 ob_main_8002a324(uint32 matrix)
{
    FUNCTION_MARKER(0x8002A324, "SLES_008.65");
    uint32 last_row = matrix + 12;
    uint32 length = sub_80028614(last_row) & 65535;
    if (!length) return ob_identity_matrix14(matrix);
    ob_main_800287d4(matrix + 6, last_row, matrix);
    sub_80028614(matrix);
    return ob_main_800287d4(last_row, matrix, matrix + 6);
}

sint32 ob_main_8002a54c(uint32 matrix, uint32 scale, uint32 output, uint32 initial_product_v1)
{
    FUNCTION_MARKER(0x8002A54C, "SLES_008.65");
    sint32 result = (sint32)(initial_product_v1 + 0x2000) >> 14;
    w_u16(output, result);
    for (uint32 index = 1; index < 9; ++index)
    {
        sint32 value = r_s16(matrix + index * 2);
        sint32 factor = r_s16(scale + (index / 3) * 2);
        sint32 product = value * factor;
        sint32 bias = (value < 0) != (factor < 0) ? -0x2000 : 0x2000;
        result = (product + bias) >> 14;
        w_u16(output + index * 2, result);
    }
    return result;
}

sint32 ob_main_8002a6ec(uint32 matrix, uint32 scale, uint32 output, uint32 initial_product_v1)
{
    FUNCTION_MARKER(0x8002A6EC, "SLES_008.65");
    sint32 result = (sint32)(initial_product_v1 + 0x2000) >> 14;
    w_u16(output, result);
    for (uint32 index = 1; index < 9; ++index)
    {
        sint32 value = r_s16(matrix + index * 2);
        sint32 factor = r_s16(scale + (index / 3) * 2);
        sint32 product = value * factor;
        sint32 bias = (value < 0) != (factor < 0) ? -0x2000 : 0x2000;
        result = (product + bias) >> 14;
        uint32 offset = (index % 3) * 6 + (index / 3) * 2;
        w_u16(output + offset, result);
    }
    return result;
}

sint32 ob_main_8002b67c(uint32 matrix, uint32 axis)
{
    FUNCTION_MARKER(0x8002B67C, "SLES_008.65");
    sint32 first = r_s16(matrix);
    sint32 middle = r_s16(matrix + 8);
    sint32 last = r_s16(matrix + 16);
    sint32 trace = first + middle + last - 0x4000;
    sint32 cosine = (sint16)(trace / 2);
    uint32 radicand = 0x10000000 - (uint32)(cosine * cosine);
    sint32 sine = (sint16)sub_8002B868(radicand);
    if (!sine)
    {
        w_u16(axis, 0);
        w_u16(axis + 2, 0);
        w_u16(axis + 4, 0x4000);
        return 0;
    }
    sint32 divisor = sine * 2;
    first = r_s16(matrix + 10);
    last = r_s16(matrix + 14);
    w_u16(axis, ((first - last) * 0x4000) / divisor);
    first = r_s16(matrix + 12);
    last = r_s16(matrix + 4);
    w_u16(axis + 2, ((first - last) * 0x4000) / divisor);
    first = r_s16(matrix + 2);
    last = r_s16(matrix + 6);
    w_u16(axis + 4, ((first - last) * 0x4000) / divisor);
    return ob_main_800281d0(cosine);
}

uint32 ob_main_80029484(uint32 vector, sint32 divisor, uint32 output)
{
    FUNCTION_MARKER(0x80029484, "SLES_008.65");
    uint64 denominator = (uint64)(sint64)divisor;
    uint32 result = 0;
    for (uint32 index = 0; index < 3; ++index)
    {
        sint64 numerator = (sint64)r_s32(vector + index * 4) * 0x4000;
        result = (uint32)__divdi3PSX((uint64)numerator, denominator);
        w_u16(output + index * 2, result);
    }
    return result;
}

uint32 ob_main_8004597c(uint32 object, uint32 position, uint32 time)
{
    FUNCTION_MARKER(0x8004597C, "SLES_008.65");
    sint32 x = r_s32(position);
    sint32 y = r_s32(position + 4);
    sint32 z = r_s32(position + 8);
    w_u32(object + 72, time);
    w_u32(object + 76, time);
    w_u32(object + 92, x);
    w_u32(object + 96, y);
    w_u32(object + 100, z);
    w_u32(object + 80, x >> 8);
    w_u32(object + 84, y >> 8);
    w_u32(object + 88, z >> 8);
    ob_invalidate_object_position(object);
    w_u32(object + 160, r_u32(object + 160) | 64);
    sub_80045204(object);
    uint32 flags = r_u32(object + 160) & ~64u;
    w_u32(object + 160, flags);
    return flags;
}

uint32 ob_main_8002c2c4(uint32 edge, uint32 output)
{
    FUNCTION_MARKER(0x8002C2C4, "SLES_008.65");
    uint32 base;
    uint32 other;
    uint32 target;
    if (r_u16(edge + 42) == 1)
    {
        base = r_u32(edge + 12);
        other = r_u32(edge + 16);
        target = edge + 16;
    }
    else
    {
        base = r_u32(edge + 16);
        other = r_u32(edge + 12);
        target = edge + 12;
    }
    uint32 result;
    if (r_u16(0x800774E4) & 2)
    {
        uint32 other_x = r_u32(other);
        uint32 base_x = r_u32(base);
        sint32 factor = r_s16(edge + 32);
        uint32 product = (other_x - base_x) * (uint32)factor;
        uint32 other_y = r_u32(other + 4);
        uint32 base_y = r_u32(base + 4);
        uint32 difference_y = other_y - base_y;
        sint32 half = r_s16(edge + 34) >> 1;
        uint32 rounded = (sint32)product > 0 ? product + (uint32)half : product - (uint32)half;
        sint32 divisor = r_s16(edge + 34);
        if (!divisor)
            ob_native_guest_break(0x8002C2C4, 7);
        if (divisor == -1 && rounded == 0x80000000u)
            ob_native_guest_break(0x8002C2C4, 6);
        sint32 quotient = (sint32)rounded / divisor;
        w_u32(output, (uint32)quotient + r_u32(base));
        factor = r_s16(edge + 32);
        product = difference_y * (uint32)factor;
        half = r_s16(edge + 34) >> 1;
        rounded = (sint32)product > 0 ? product + (uint32)half : product - (uint32)half;
        divisor = r_s16(edge + 34);
        if (!divisor)
            ob_native_guest_break(0x8002C2C4, 7);
        if (divisor == -1 && rounded == 0x80000000u)
            ob_native_guest_break(0x8002C2C4, 6);
        quotient = (sint32)rounded / divisor;
        result = (uint32)quotient + r_u32(base + 4);
        w_u32(output + 4, result);
    }
    else
    {
        sint32 numerator = r_s16(edge + 32) * 4096;
        sint32 divisor = r_s16(edge + 34);
        if (!divisor)
            ob_native_guest_break(0x8002C2C4, 7);
        /* A signed 16-bit factor scaled by 4096 cannot reach INT32_MIN */
        sint32 weight = numerator / divisor;
        result = LoadAverageShort12(
            (SVECTOR *)psx_addr(base + 8, sizeof(SVECTOR)),
            (SVECTOR *)psx_addr(other + 8, sizeof(SVECTOR)),
            (sint32)(4096u - (uint32)weight), weight,
            (SVECTOR *)psx_addr(output + 8, sizeof(SVECTOR)));
    }
    w_u32(target, output);
    return result;
}

uint32 ob_main_8004c0d0(sint32 height, uint32 x, uint32 z)
{
    FUNCTION_MARKER(0x8004C0D0, "SLES_008.65");
    uint32 map = r_u32(0x800665D8);
    if (map & 3)
        map = sub_800257CC(0x800665D8);
    else
        w_u16(map - 6, r_u16(map - 6) + 1);
    uint32 origin_x = r_u32(0x80077458);
    sint32 cell_size = r_s32(map);
    uint32 numerator = x + origin_x;
    if (!cell_size)
        ob_native_guest_break(0x8004C0D0, 7);
    if (cell_size == -1 && numerator == 0x80000000u)
        ob_native_guest_break(0x8004C0D0, 6);
    sint32 column = (sint32)numerator / cell_size;
    uint32 origin_z = r_u32(0x80077468);
    w_u32(0x80077644, map);
    numerator = origin_z - z;
    if (!cell_size)
        ob_native_guest_break(0x8004C0D0, 7);
    if (cell_size == -1 && numerator == 0x80000000u)
        ob_native_guest_break(0x8004C0D0, 6);
    sint32 row = (sint32)numerator / cell_size;
    if (column < 0 || column >= r_s16(map + 4) * 16 ||
        row < 0 || row >= r_s16(map + 6) * 16)
    {
        sub_800257A0(0x800665D8);
        return 0;
    }
    uint32 packed = (((uint32)column & 255) | (((uint32)row & 255) << 8)) << 16;
    uint32 cell = ob_border_cell_address(packed, map);
    uint32 kind = r_u8(cell);
    uint32 dimensions = r_u32(0x80077644);
    uint32 record = r_u32(dimensions + 24) + kind * 24;
    uint32 flag;
    if (height < -2500)
        flag = 8;
    else if (height < -50)
        flag = 4;
    else if (height < 6400)
        flag = 2;
    else
        flag = 1;
    sub_800257A0(0x800665D8);
    return (r_u8(record + 22) & flag) != 0;
}

uint32 ob_main_80033cb4(uint32 handle, uint32 base)
{
    FUNCTION_MARKER(0x80033CB4, "SLES_008.65");
    uint32 model = r_u32(handle);
    ob_main_800357a8(model, base);
    uint32 count = r_u16(model + 6);
    uint32 record = r_u32(model + 12);
    uint32 processed = 0;
    if (!count)
        return 0;
    do
    {
        uint32 slot;
        uint32 uv;
        uint32 vertices;
        uint32 next;
        if (r_u16(record) == 3)
        {
            slot = record + 8;
            uv = record + 12;
            vertices = 3;
            next = record + 20;
        }
        else
        {
            slot = record + 12;
            uv = record + 16;
            vertices = 4;
            next = record + 24;
        }
        uint32 reference = r_u32(slot);
        uint32 resource = r_u32(reference);
        if (resource & 3)
            resource = sub_800257CC(reference);
        else
        {
            w_u16(resource - 6, r_u16(resource - 6) + 1);
            reference = r_u32(slot);
            resource = r_u32(reference);
        }
        uint32 second_id = (resource >> 2) & 0x7FFF;
        uint32 first = sub_80025700(resource >> 17);
        uint32 second = sub_80025700(second_id);
        uint32 packed = ((first >> 2) << 16) + (second >> 16);
        uint32 offset_u = (second >> 4) & 0xF0;
        uint32 offset_v = (second >> 8) & 0xF0;
        uint32 table = 0x800735F0 + ((second >> 4) & 15) * 6;
        uint32 scale_u = r_u16(table);
        uint32 scale_v = r_u16(table + 2);
        if (second & 4)
        {
            for (uint32 index = 0; index < vertices; ++index)
            {
                uint32 address = uv + index * 2;
                uint32 u = r_u8(address);
                uint32 v = r_u8(address + 1);
                w_u8(address, v);
                w_u8(address + 1, u);
            }
        }
        for (uint32 index = 0; index < vertices; ++index)
        {
            uint32 address = uv + index * 2;
            uint32 u = r_u8(address);
            w_u8(address, ((u * scale_u) >> 8) + offset_u);
            uint32 v = r_u8(address + 1);
            w_u8(address + 1, ((v * scale_v) >> 8) + offset_v);
        }
        uint32 release_handle = r_u32(slot);
        ++processed;
        sub_800257A0(release_handle);
        w_u32(slot, packed);
        record = next;
        count = r_u16(model + 6);
    } while (processed < count);
    return 0;
}

uint32 ob_main_8005fab8(uint32 incoming_v0)
{
    FUNCTION_MARKER(0x8005FAB8, "SLES_008.65");
    /* The original constructor loop is bypassed or has a literal zero count */
    return incoming_v0;
}

uint32 ob_game_800a419c(uint32 slot, uint32 flags, sint32 distance)
{
    FUNCTION_MARKER(0x800A419C, "GAME.BIN");
    w_u32(0x800C8560, flags | 128);
    if (distance == 127)
        return 127;
    if (r_s32(0x800C82BC) >= distance)
    {
        sint32 layer = (sint16)slot;
        do
        {
            uint32 cursor = 0x800C81CC;
            uint32 map = 0x800D5EA4 + (uint32)(layer * 504);
            sint32 step = (sint16)distance;
            do
            {
                if (r_s16(cursor) == distance)
                {
                    sint32 x = r_s16(cursor - 4);
                    sint32 z = r_s16(cursor - 2);
                    w_u16(cursor, UINT32_MAX);
                    uint32 cell = map + (uint32)(x * 24 + z);
                    if (x - 1 >= 0 && r_s8(cell - 24) == -2)
                        ob_game_800A4600(step, layer, x - 1, z);
                    if (x + 1 < 21 && r_s8(cell + 24) == -2)
                        ob_game_800A4600(step, layer, x + 1, z);
                    if (z - 1 >= 0 && r_s8(cell - 1) == -2)
                        ob_game_800A4600(step, layer, x, z - 1);
                    if (z + 1 < 21 && r_s8(cell + 1) == -2)
                        ob_game_800A4600(step, layer, x, z + 1);
                }
                cursor += 8;
            } while (cursor < 0x800C82BC);
            sint32 limit = r_s32(0x800C82BC);
            distance = (sint32)((uint32)distance + 1);
            if (limit < distance)
                break;
        } while (1);
    }
    uint32 result = r_u32(0x800C8560) & ~128u;
    w_u32(0x800C8560, result);
    return result;
}

uint32 ob_main_80030f60(uint32 payload, uint32 node, uint32 descriptor,
    uint32 previous_shape, uint32 previous_mode, uint32 incoming_s5)
{
    FUNCTION_MARKER(0x80030F60, "SLES_008.65");
    uint32 end = r_u32(0x800775BC);
    uint32 cursor = r_u32(0x800774A8);
    uint32 model = r_u32(payload + 24);
    uint32 required = r_u16(model + 14) << 6;
    if ((sint32)(end - cursor) < (sint32)required)
        return required;
    uint32 shift = 0;
    uint32 saved_vertices = incoming_s5;
    uint32 shape = r_u32(node + 16);
    w_u16(0x80077638, 0);
    w_u16(0x80077364, 0);
    if (shape != previous_shape || r_u8(node + 2) != (uint8)previous_mode)
    {
        sint32 direction_x = r_s16(shape + 12);
        sint32 direction_z = r_s16(shape + 16);
        uint32 angle = sub_80027F98(direction_x, direction_z);
        uint32 index = ((0x4000u - angle) & 65535) + 8;
        index = (index >> 4) * 2;
        sint32 cosine = r_s16(0x8006CB04 + index) >> 2;
        w_u16(0x1F800042, 0);
        w_u16(0x1F800050, cosine);
        w_u16(0x1F800040, cosine);
        sint32 sine = r_s16(0x8006C304 + index) >> 2;
        w_u16(0x1F800046, 0);
        w_u16(0x1F800048, 4096);
        w_u16(0x1F80004A, 0);
        w_u16(0x1F80004E, 0);
        w_u16(0x1F800044, sine);
        w_u16(0x1F80004C, -sine);
        MulMatrix0((MATRIX *)psx_addr(0x8008C8A8, sizeof(MATRIX)),
            (MATRIX *)psx_addr(0x1F800040, sizeof(MATRIX)),
            (MATRIX *)psx_addr(0x1F800060, sizeof(MATRIX)));
        uint32 second = r_u16(0x1F800066);
        uint32 fourth = r_u16(0x1F80006A);
        w_u16(0x1F800066, 0u - second);
        uint32 third = r_u16(0x1F800068);
        w_u16(0x1F80006A, 0u - fourth);
        w_u16(0x1F800068, 0u - third);
    }
    uint32 x = r_u32(payload + 12);
    uint32 render_cursor = r_u32(0x80077354);
    w_u32(0x1F800074, x);
    uint32 y = r_u32(payload + 16);
    w_u32(0x800773C0, render_cursor);
    w_u32(0x1F800078, 0u - y);
    uint32 z = r_u32(payload + 20);
    x = r_u32(0x1F800074);
    y = r_u32(0x1F800078);
    uint32 maximum = (sint32)x < 0 ? 0u - x : x;
    uint32 magnitude_y = (sint32)y < 0 ? 0u - y : y;
    w_u32(0x1F80007C, z);
    if (maximum < magnitude_y)
        maximum = magnitude_y;
    uint32 magnitude_z = (sint32)z < 0 ? 0u - z : z;
    if (maximum < magnitude_z)
        maximum = magnitude_z;
    while (maximum >= 0x7FF9)
    {
        ++shift;
        w_u32(0x1F800074, r_s32(0x1F800074) >> 1);
        uint32 current_z = r_u32(0x1F80007C);
        uint32 current_y = r_u32(0x1F800078);
        w_u32(0x1F80007C, (sint32)current_z >> 1);
        w_u32(0x1F800078, (sint32)current_y >> 1);
        maximum >>= 1;
    }
    model = r_u32(payload + 24);
    w_u32(0x8007759C, 800);
    w_u32(0x80077530, 0x1F8000E0);
    sub_800354C8(model);
    if (shift)
    {
        for (uint32 index = 0; index < 9; ++index)
            w_u16(0x1F800080 + index * 2, r_s16(0x1F800060 + index * 2) >> shift);
    }
    else
    {
        uint32 coefficients[9];
        for (uint32 index = 0; index < 9; ++index)
            coefficients[index] = r_u16(0x1F800060 + index * 2);
        for (uint32 index = 0; index < 9; ++index)
            w_u16(0x1F800080 + index * 2, coefficients[index]);
    }
    if (!r_u32(descriptor))
    {
        model = r_u32(payload + 24);
        uint32 bytes = r_u16(model + 10) * 8;
        uint32 available = r_u32(0x8007759C);
        uint32 temporary;
        if (bytes < available)
        {
            temporary = r_u32(0x80077530);
            w_u32(0x8007759C, available - bytes);
            w_u32(0x80077530, temporary + bytes);
        }
        else
            temporary = sub_8002D98C(bytes);
        uint32 first = r_u16(0x1F800044);
        uint32 second = r_u16(0x1F80004C);
        w_u16(0x1F800044, second);
        w_u16(0x1F80004C, first);
        SetRotMatrix((MATRIX *)psx_addr(0x1F800040, sizeof(MATRIX)));
        xport_gte_write_data(0, r_u32(descriptor + 4));
        xport_gte_write_data(1, r_u32(descriptor + 8));
        xport_gte_execute(0x486012);
        uint32 mac_x = xport_gte_read_data(25);
        uint32 mac_y = xport_gte_read_data(26);
        uint32 mac_z = xport_gte_read_data(27);
        w_u16(0x1F8000A0, mac_x);
        w_u16(0x1F8000A2, mac_y);
        w_u16(0x1F8000A4, mac_z);
        uint32 position = r_u32(node + 12);
        x = r_u32(node + 20);
        uint32 origin = r_u32(position);
        w_u16(0x1F8000A8, r_u16(descriptor + 12) + x - origin);
        position = r_u32(node + 12);
        z = r_u32(node + 28);
        origin = r_u32(position + 8);
        w_u16(0x1F8000AC, r_u16(descriptor + 16) + z - origin);
        w_u16(0x1F8000AA, r_u16(descriptor + 14));
        SetRotMatrix((MATRIX *)psx_addr(0x1F800040, sizeof(MATRIX)));
        xport_gte_write_data(0, r_u32(0x1F8000A8));
        xport_gte_write_data(1, r_u32(0x1F8000AC));
        xport_gte_execute(0x486012);
        w_u32(0x1F8000B0, xport_gte_read_data(25));
        w_u32(0x1F8000B4, xport_gte_read_data(26));
        w_u32(0x1F8000B8, xport_gte_read_data(27));
        model = r_u32(payload + 24);
        uint32 vertex_count = r_u16(model + 10);
        sint32 remaining = (sint32)vertex_count - 1;
        uint32 vertices = r_u32(model + 32);
        uint32 output = temporary;
        while (remaining >= 0)
        {
            uint32 offset_x = r_u32(0x1F8000B0);
            x = r_u16(vertices);
            uint32 offset_z = r_u32(0x1F8000B8);
            w_u16(0x1F8000A8, x - offset_x);
            z = r_u16(vertices + 4);
            w_u16(0x1F8000AA, 0);
            w_u16(0x1F8000AC, z - offset_z);
            xport_gte_write_control(0, r_u32(0x1F8000A0));
            xport_gte_write_control(1, r_u32(0x1F8000A4));
            xport_gte_write_data(0, r_u32(0x1F8000A8));
            xport_gte_write_data(1, r_u32(0x1F8000AC));
            xport_gte_execute(0x486012);
            w_u32(0x1F8000C0, xport_gte_read_data(25));
            uint32 numerator = r_u32(0x1F8000C0) << 12;
            sint32 divisor = r_s16(descriptor + 6);
            if (!divisor)
                ob_native_guest_break(0x80030F60, 7);
            if (divisor == -1 && numerator == 0x80000000u)
                ob_native_guest_break(0x80030F60, 6);
            w_u32(0x1F8000C4, (sint32)numerator / divisor);
            --remaining;
            w_u16(output, r_u16(vertices));
            uint32 correction = r_u32(0x1F8000C4);
            w_u16(output + 2, r_u16(vertices + 2) - correction);
            w_u16(output + 4, r_u16(vertices + 4));
            vertices += 8;
            output += 8;
        }
        if (vertex_count)
            model = r_u32(payload + 24);
        saved_vertices = r_u32(model + 32);
        w_u32(model + 32, temporary);
        first = r_u16(0x1F80004C);
        second = r_u16(0x1F800044);
        w_u16(0x1F800044, first);
        w_u16(0x1F80004C, second);
    }
    SetRotMatrix((MATRIX *)psx_addr(0x1F800080, sizeof(MATRIX)));
    SetTransMatrix((MATRIX *)psx_addr(0x1F800060, sizeof(MATRIX)));
    SetGeomScreen(r_u32(r_u32(0x800770C0) + 8));
    sub_8003584C(r_u32(payload + 24));
    SetGeomScreen(r_u16(0x80077498));
    model = r_u32(payload + 24);
    uint32 material_output = r_u32(0x800773A4);
    uint32 material_count = r_u16(model + 16);
    uint32 materials = r_u32(model + 52);
    for (uint32 index = 0; index < material_count; ++index)
    {
        w_u32(material_output, r_u32(materials));
        materials += 4;
        material_output += 4;
    }
    uint32 indices = r_u32(0x800775E4);
    sint32 index = r_u16(0x800775F0) - 1;
    w_u16(0x8007748C, 0);
    w_u16(0x80077480, 0);
    w_u16(0x800775A0, 65535);
    for (; index >= 0; --index)
    {
        w_u16(indices, index);
        indices += 2;
    }
    sub_8003AA8C(payload);
    uint32 result = r_u32(0x800773C0);
    uint32 projection = r_u32(descriptor);
    w_u32(0x80077354, result);
    if (!projection)
    {
        result = r_u32(payload + 24);
        w_u32(result + 32, saved_vertices);
    }
    return result;
}

uint32 ob_main_80031650(uint32 payload, uint32 node, uint32 descriptor,
    uint32 previous_shape, uint32 previous_mode, uint32 incoming_s6)
{
    FUNCTION_MARKER(0x80031650, "SLES_008.65");
    uint32 end = r_u32(0x800775BC);
    uint32 model = r_u32(payload + 24);
    uint32 cursor = r_u32(0x800774A8);
    uint32 required = r_u16(model + 14) << 6;
    if ((sint32)(end - cursor) < (sint32)required)
        return 1;
    if (!r_u16(payload + 52))
    {
        uint32 extent = r_u16(model + 8);
        uint32 product = r_u32(0x800775C8) * extent;
        sint32 limit = (sint32)product >> 8;
        if (limit < r_s32(payload + 20))
        {
            w_u16(0x80077324, 0);
            return ob_main_80030f60(payload, node, descriptor,
                previous_shape, previous_mode, descriptor);
        }
    }
    uint32 saved_vertices = incoming_s6;
    uint32 shape = r_u32(node + 16);
    if (shape != previous_shape || r_u8(node + 2) != (uint8)previous_mode)
    {
        sint32 direction_x = r_s16(shape + 12);
        sint32 direction_z = r_s16(shape + 16);
        uint32 angle = sub_80027F98(direction_x, direction_z);
        uint32 index = ((((0x4000u - angle) & 65535) + 8) >> 4) * 2;
        uint32 cosine = r_u16(0x8006CB04 + index);
        w_u16(0x800882CA, 0);
        w_u16(0x800882D8, cosine);
        w_u16(0x800882C8, cosine);
        uint32 sine = r_u16(0x8006C304 + index);
        w_u16(0x800882CE, 0);
        w_u16(0x800882D0, 0x4000);
        w_u16(0x800882D2, 0);
        w_u16(0x800882D6, 0);
        w_u16(0x800882CC, 0u - sine);
        w_u16(0x800882D4, sine);
        uint32 position = r_u32(node + 12);
        uint32 x = r_u32(position);
        uint32 y = r_u32(position + 4);
        uint32 z = r_u32(position + 8);
        w_u32(0x800882E0, x);
        w_u32(0x800882E4, y);
        w_u32(0x800882E8, z);
    }
    w_u32(0x800773C0, r_u32(0x80077354));
    uint32 allocation = sub_8002D98C(528);
    w_u32(0x800775C4, allocation + 120);
    uint32 planes = r_u16(payload + 52);
    w_u32(0x8007736C, allocation);
    w_u32(0x80077560, allocation + 240);
    w_u16(0x80077638, 0);
    if (planes)
    {
        uint32 result = ob_main_800322BC(payload);
        if (result)
            return result;
    }
    else
        w_u16(0x80077324, 0);
    uint32 local = ob_draft_scratch_acquire(248);
    model = r_u32(payload + 24);
    uint32 old_flags = r_u8(payload + 1);
    uint32 transform = r_u32(payload + 28);
    uint32 model_flags = r_u16(model + 4);
    w_u8(payload + 1, model_flags);
    uint32 flags = r_u32(transform + 48);
    uint32 camera = r_u32(0x800775D0);
    w_u32(transform + 48, flags & ~32u);
    ob_main_8002E968(r_u32(payload + 28), camera, local);
    uint32 first = r_u16(local + 2);
    uint32 second = r_u16(local + 14);
    w_u16(local + 2, 0u - first);
    uint32 third = r_u16(local + 8);
    w_u16(local + 14, 0u - second);
    w_u16(local + 8, 0u - third);
    transform = r_u32(payload + 28);
    w_u32(transform + 48, r_u32(transform + 48) | 32);
    uint32 x = r_u32(payload + 12);
    uint32 y = r_u32(payload + 16);
    uint32 z = r_u32(payload + 20);
    w_u32(local + 24, x);
    w_u32(local + 28, y);
    w_u32(local + 32, z);
    y = r_u32(local + 28);
    flags = r_u32(local + 48);
    w_u32(local + 28, 0u - y);
    w_u32(local + 48, flags | 32);
    sub_80042928(local, local + 80);
    x = r_u32(local + 104);
    y = r_u32(local + 108);
    z = r_u32(local + 112);
    uint32 pool = r_u32(0x800773B8);
    w_u16(0x80077364, 0);
    w_u32(0x800774F8, x);
    w_u32(0x800774FC, y);
    w_u32(0x80077500, z);
    w_u32(0x800774AC, pool);
    if (old_flags & 1)
    {
        uint32 absolute_x = (sint32)x < 0 ? 0u - x : x;
        uint32 absolute_y = (sint32)y < 0 ? 0u - y : y;
        uint32 absolute_z = (sint32)z < 0 ? 0u - z : z;
        uint32 extent = r_u32(0x80077338);
        if (absolute_x < extent && absolute_y < extent && absolute_z < r_u32(0x800775C8))
        {
            model = r_u32(payload + 24);
            w_u16(0x80077524, 32760);
            w_u16(0x8007751E, 32760);
            w_u16(0x80077522, 32760);
            w_u16(0x8007751C, 32760);
            w_u16(0x8007752C, 32760);
            w_u16(0x80077520, 32760);
            uint32 result = ob_main_8003A064(model);
            if (result)
            {
                ob_draft_scratch_release(local);
                return result;
            }
        }
    }
    model = r_u32(payload + 24);
    w_u32(0x8007759C, 960);
    w_u32(0x80077530, 0x1F800040);
    sub_800352B4(model);
    uint32 output = r_u32(0x800773A4);
    model = r_u32(payload + 24);
    w_u32(0x800775EC, local + 80);
    w_u32(0x80077610, local + 104);
    uint32 material_count = r_u16(model + 16);
    uint32 materials = r_u32(model + 52);
    for (uint32 index = 0; index < material_count; ++index)
    {
        w_u32(output, r_u32(materials));
        materials += 4;
        output += 4;
    }
    if (!r_u32(descriptor))
    {
        shape = r_u32(node + 16);
        sint32 direction_x = r_s16(shape + 12);
        sint32 direction_z = r_s16(shape + 16);
        uint32 angle = sub_80027F98(direction_x, direction_z);
        uint32 index = ((((0x4000u - angle) & 65535) + 8) >> 4) * 2;
        sint32 cosine = r_s16(0x8006CB04 + index) >> 2;
        w_u16(0x1F800042, 0);
        w_u16(0x1F800050, cosine);
        w_u16(0x1F800040, cosine);
        sint32 sine = -r_s16(0x8006C304 + index);
        w_u16(0x1F800046, 0);
        w_u16(0x1F80004A, 0);
        w_u16(0x1F80004E, 0);
        w_u16(0x1F800044, sine >> 2);
        uint32 negative_sine = r_u16(0x1F800044);
        w_u16(0x1F800048, 4096);
        w_u16(0x1F80004C, 0u - negative_sine);
        model = r_u32(payload + 24);
        uint32 bytes = r_u16(model + 10) * 8;
        uint32 available = r_u32(0x8007759C);
        uint32 temporary;
        if (bytes < available)
        {
            temporary = r_u32(0x80077530);
            w_u32(0x8007759C, available - bytes);
            w_u32(0x80077530, temporary + bytes);
        }
        else
            temporary = sub_8002D98C(bytes);
        SetRotMatrix((MATRIX *)psx_addr(0x1F800040, sizeof(MATRIX)));
        xport_gte_write_data(0, r_u32(descriptor + 4));
        xport_gte_write_data(1, r_u32(descriptor + 8));
        xport_gte_execute(0x486012);
        uint32 mac_x = xport_gte_read_data(25);
        uint32 mac_y = xport_gte_read_data(26);
        uint32 mac_z = xport_gte_read_data(27);
        w_u16(0x1F8000A0, mac_x);
        w_u16(0x1F8000A2, mac_y);
        w_u16(0x1F8000A4, mac_z);
        uint32 position = r_u32(node + 12);
        x = r_u32(node + 20);
        uint32 origin = r_u32(position);
        w_u16(0x1F8000A8, r_u16(descriptor + 12) + x - origin);
        position = r_u32(node + 12);
        z = r_u32(node + 28);
        origin = r_u32(position + 8);
        w_u16(0x1F8000AC, r_u16(descriptor + 16) + z - origin);
        w_u16(0x1F8000AA, r_u16(descriptor + 14));
        SetRotMatrix((MATRIX *)psx_addr(0x1F800040, sizeof(MATRIX)));
        xport_gte_write_data(0, r_u32(0x1F8000A8));
        xport_gte_write_data(1, r_u32(0x1F8000AC));
        xport_gte_execute(0x486012);
        w_u32(0x1F8000B0, xport_gte_read_data(25));
        w_u32(0x1F8000B4, xport_gte_read_data(26));
        w_u32(0x1F8000B8, xport_gte_read_data(27));
        model = r_u32(payload + 24);
        uint32 vertex_count = r_u16(model + 10);
        sint32 remaining = (sint32)vertex_count - 1;
        uint32 vertices = r_u32(model + 32);
        uint32 output = temporary;
        while (remaining >= 0)
        {
            uint32 offset_x = r_u32(0x1F8000B0);
            x = r_u16(vertices);
            uint32 offset_z = r_u32(0x1F8000B8);
            w_u16(0x1F8000A8, x - offset_x);
            z = r_u16(vertices + 4);
            w_u16(0x1F8000AA, 0);
            w_u16(0x1F8000AC, z - offset_z);
            xport_gte_write_control(0, r_u32(0x1F8000A0));
            xport_gte_write_control(1, r_u32(0x1F8000A4));
            xport_gte_write_data(0, r_u32(0x1F8000A8));
            xport_gte_write_data(1, r_u32(0x1F8000AC));
            xport_gte_execute(0x486012);
            w_u32(0x1F8000C0, xport_gte_read_data(25));
            uint32 numerator = r_u32(0x1F8000C0) << 12;
            sint32 divisor = r_s16(descriptor + 6);
            if (!divisor)
                ob_native_guest_break(0x80031650, 7);
            if (divisor == -1 && numerator == 0x80000000u)
                ob_native_guest_break(0x80031650, 6);
            w_u32(0x1F8000C4, (sint32)numerator / divisor);
            --remaining;
            w_u16(output, r_u16(vertices));
            uint32 correction = r_u32(0x1F8000C4);
            w_u16(output + 2, r_u16(vertices + 2) - correction);
            w_u16(output + 4, r_u16(vertices + 4));
            vertices += 8;
            output += 8;
        }
        if (vertex_count)
            model = r_u32(payload + 24);
        saved_vertices = r_u32(model + 32);
        w_u32(model + 32, temporary);
    }
    x = r_u32(0x800774F8);
    y = r_u32(0x800774FC);
    z = r_u32(0x80077500);
    w_u32(local + 180, x);
    w_u32(local + 184, y);
    w_u32(local + 188, z);
    uint32 maximum = (sint32)x < 0 ? 0u - x : x;
    uint32 absolute_y = (sint32)y < 0 ? 0u - y : y;
    uint32 absolute_z = (sint32)z < 0 ? 0u - z : z;
    if (maximum < absolute_y)
        maximum = absolute_y;
    if (maximum < absolute_z)
        maximum = absolute_z;
    uint32 shift = 0;
    while (maximum >= 0x7FF9)
    {
        ++shift;
        maximum >>= 1;
        w_u32(local + 180, r_s32(local + 180) >> 1);
        uint32 current_z = r_u32(local + 188);
        uint32 current_y = r_u32(local + 184);
        w_u32(local + 188, (sint32)current_z >> 1);
        w_u32(local + 184, (sint32)current_y >> 1);
    }
    uint32 matrix = r_u32(0x800775EC);
    sint32 first_coefficient = r_s16(matrix);
    static const uint8 source_offsets[7] = {6, 12, 2, 8, 14, 4, 10};
    for (uint32 index = 0; index < 7; ++index)
        w_u16(local + 162 + index * 2, r_s16(matrix + source_offsets[index]) >> (shift + 2));
    sint32 last_coefficient = r_s16(matrix + 16);
    w_u16(local + 160, first_coefficient >> (shift + 2));
    w_u16(local + 176, last_coefficient >> (shift + 2));
    SetRotMatrix((MATRIX *)psx_addr(local + 160, sizeof(MATRIX)));
    SetTransMatrix((MATRIX *)psx_addr(local + 160, sizeof(MATRIX)));
    uint32 clipped = r_u16(0x80077364);
    w_u32(0x80077558, local + 160);
    flags = r_u8(payload + 1);
    model = r_u32(payload + 24);
    w_u8(payload + 1, flags | 64);
    if (clipped)
        ob_main_8003803C(model);
    else
        ob_main_80037F0C(model);
    uint32 indices = r_u32(0x800775E4);
    sint32 index = r_u16(0x800775F0) - 1;
    w_u16(0x8007748C, 0);
    w_u16(0x80077480, 0);
    w_u16(0x800775A0, 65535);
    for (; index >= 0; --index)
    {
        w_u16(indices, index);
        indices += 2;
    }
    uint32 count = r_u16(0x80077638);
    if (count && shift)
    {
        uint32 values = r_u32(0x80077560);
        for (uint32 item = 0; item < count; ++item)
        {
            w_u32(values, r_s32(values) >> shift);
            values += 12;
        }
    }
    if (r_u16(0x80077364))
        ob_main_8003DF98(r_u32(payload + 24), payload);
    else
        ob_main_8003F528(r_u32(payload + 24), payload);
    ob_main_800355F4();
    uint32 result = r_u32(descriptor);
    if (!result)
    {
        result = r_u32(payload + 24);
        w_u32(result + 32, saved_vertices);
    }
    ob_draft_scratch_release(local);
    return result;
}

uint32 ob_main_80030964(uint32 node, uint32 descriptors)
{
    FUNCTION_MARKER(0x80030964, "SLES_008.65");
    uint32 payload = ob_draft_scratch_acquire(512);
    uint32 previous_shape = 0;
    uint32 previous_mode = 255;
    uint32 result;
    do
    {
        uint32 position = r_u32(node + 12);
        uint32 descriptor_index = r_u8(node + 1);
        w_u32(0x1F8000B8, r_u32(position));
        w_u32(0x1F8000BC, r_u32(node + 24));
        position = r_u32(node + 12);
        w_u32(0x1F8000C0, r_u32(position + 8));
        uint32 descriptor = descriptors + descriptor_index * 20;
        sint32 offset_y = r_s16(descriptor + 14);
        uint32 y = r_u32(0x1F8000BC);
        uint32 camera = r_u32(0x800775D0);
        w_u32(0x1F8000BC, y + (uint32)offset_y);
        uint32 x = r_u32(0x1F8000B8);
        w_u32(0x1F8000B8, x - r_u32(camera + 24));
        y = r_u32(0x1F8000BC);
        uint32 camera_y = r_u32(camera + 28);
        uint32 z = r_u32(0x1F8000C0);
        w_u32(0x1F8000BC, y - camera_y);
        uint32 camera_z = r_u32(camera + 32);
        x = r_u32(0x1F8000B8);
        z -= camera_z;
        uint32 magnitude_x = (sint32)x < 0 ? 0u - x : x;
        w_u32(0x1F8000C0, z);
        uint32 magnitude_y = 0;
        uint32 magnitude_z = 0;
        uint32 large = (sint32)magnitude_x >= 16000;
        if (!large)
        {
            y = r_u32(0x1F8000BC);
            magnitude_y = (sint32)y < 0 ? 0u - y : y;
            large = (sint32)magnitude_y >= 16000;
            if (!large)
            {
                magnitude_z = (sint32)z < 0 ? 0u - z : z;
                large = (sint32)magnitude_z >= 16000;
            }
        }
        if (large)
        {
            x = r_u32(0x1F8000B8);
            z = r_u32(0x1F8000C0);
            w_u16(0x1F8000A0, (sint32)x >> 4);
            y = r_u32(0x1F8000BC);
            w_u16(0x1F8000A4, (sint32)z >> 4);
            w_u16(0x1F8000A2, (sint32)y >> 4);
        }
        else
        {
            y = r_u32(0x1F8000BC);
            z = r_u32(0x1F8000C0);
            w_u16(0x1F8000A0, x);
            w_u16(0x1F8000A2, y);
            w_u16(0x1F8000A4, z);
        }
        SetRotMatrix((MATRIX *)psx_addr(0x8008C8A8, sizeof(MATRIX)));
        xport_gte_write_data(0, r_u32(0x1F8000A0));
        xport_gte_write_data(1, r_u32(0x1F8000A4));
        xport_gte_execute(0x486012);
        uint32 destination = large ? 0x1F8000B8 : 0x1F8000C8;
        w_u32(destination, xport_gte_read_data(25));
        w_u32(destination + 4, xport_gte_read_data(26));
        w_u32(destination + 8, xport_gte_read_data(27));
        if (large)
        {
            x = r_u32(0x1F8000B8);
            z = r_u32(0x1F8000C0);
            w_u32(0x1F8000C8, x << 4);
            y = r_u32(0x1F8000BC);
            w_u32(0x1F8000D0, z << 4);
            w_u32(0x1F8000CC, y << 4);
        }
        SetRotMatrix((MATRIX *)psx_addr(0x8008C8A8, sizeof(MATRIX)));
        xport_gte_write_data(0, r_u32(descriptor + 4));
        xport_gte_write_data(1, r_u32(descriptor + 8));
        xport_gte_execute(0x486012);
        uint32 mac_x = xport_gte_read_data(25);
        uint32 mac_y = xport_gte_read_data(26);
        uint32 mac_z = xport_gte_read_data(27);
        w_u16(0x1F8000B0, mac_x);
        w_u16(0x1F8000B2, mac_y);
        w_u16(0x1F8000B4, mac_z);
        sint32 offset_x = r_s16(descriptor + 12);
        camera = r_u32(0x800775D0);
        x = r_u32(node + 20);
        uint32 origin = r_u32(camera + 24);
        w_u16(0x1F8000A0, (sint32)(x + (uint32)offset_x - origin) >> 4);
        offset_y = r_s16(descriptor + 14);
        y = r_u32(node + 24);
        origin = r_u32(camera + 28);
        w_u16(0x1F8000A2, (sint32)(y + (uint32)offset_y - origin) >> 4);
        sint32 offset_z = r_s16(descriptor + 16);
        z = r_u32(node + 28);
        origin = r_u32(camera + 32);
        w_u16(0x1F8000A4, (sint32)(z + (uint32)offset_z - origin) >> 4);
        SetRotMatrix((MATRIX *)psx_addr(0x8008C8A8, sizeof(MATRIX)));
        xport_gte_write_data(0, r_u32(0x1F8000A0));
        xport_gte_write_data(1, r_u32(0x1F8000A4));
        xport_gte_execute(0x486012);
        mac_x = xport_gte_read_data(25);
        mac_y = xport_gte_read_data(26);
        mac_z = xport_gte_read_data(27);
        w_u16(0x1F8000A8, mac_x);
        w_u16(0x1F8000AA, mac_y);
        w_u16(0x1F8000AC, mac_z);
        uint32 first_row = r_u32(0x1F8000B0);
        uint32 first_tail = r_u32(0x1F8000B4);
        xport_gte_write_control(0, first_row);
        xport_gte_write_control(1, first_tail);
        xport_gte_write_data(0, r_u32(0x1F8000A8));
        xport_gte_write_data(1, r_u32(0x1F8000AC));
        xport_gte_execute(0x486012);
        result = xport_gte_read_data(25);
        if ((sint32)result < 0)
        {
            uint32 mask = r_u8(node);
            uint32 count = 0;
            uint32 bit = 0;
            uint32 point = payload + 256;
            uint32 reference = payload + 440;
            while (mask)
            {
                if (mask & 1)
                {
                    uint32 world = payload + 160 + bit * 12;
                    sint32 dx = r_s16(0x800735B0 + bit * 4);
                    x = r_u32(node + 20);
                    w_u32(world + 4, 0);
                    w_u32(world, x + (uint32)dx);
                    sint32 dz = r_s16(0x800735B2 + bit * 4);
                    z = r_u32(node + 28);
                    ++count;
                    w_u32(world + 8, z + (uint32)dz);
                    x = r_u32(world);
                    y = r_u32(world + 4);
                    z = r_u32(world + 8);
                    w_u32(point, x);
                    w_u32(point + 4, y);
                    w_u32(point + 8, z);
                    uint32 table = 0x80073578 + bit * 6;
                    uint32 high = r_u32((table + 3) & ~3u);
                    uint32 low = r_u32(table & ~3u);
                    uint32 offset = table & 3;
                    uint32 pair = offset ? (low >> (offset * 8)) | (high << ((4 - offset) * 8)) : low;
                    sint32 tail = r_s16(table + 4);
                    w_masked_u32(point + 12, pair, 15);
                    w_masked_u32(point + 12, pair, 15);
                    w_u16(point + 16, tail);
                    w_u32(reference, point);
                    uint32 type = r_u8(0x800735A8 + bit);
                    point += 20;
                    w_u16(reference + 4, type);
                    reference += 8;
                }
                mask >>= 1;
                ++bit;
            }
            uint32 handle = r_u32(node + 4);
            uint32 model = r_u32(handle);
            if (model & 3)
                model = sub_800257CC(handle);
            else
            {
                w_u16(model - 6, r_u16(model - 6) + 1);
                handle = r_u32(node + 4);
                model = r_u32(handle);
            }
            w_u8(payload + 1, r_u8(node + 2));
            w_u32(payload + 12, r_u32(0x1F8000C8));
            w_u32(payload + 16, r_u32(0x1F8000CC));
            z = r_u32(0x1F8000D0);
            w_u32(payload + 24, model);
            w_u32(payload + 28, 0x800882C8);
            w_u32(payload + 20, z);
            w_u16(payload + 52, count);
            for (uint32 index = 0; index < count; ++index)
            {
                uint32 ref = payload + 440 + index * 8;
                w_u32(payload + 56 + index * 8, r_u32(ref));
                w_u16(payload + 60 + index * 8, r_u16(ref + 4));
            }
            if (r_u8(node + 2))
                ob_main_80031650(payload, node, descriptor, previous_shape, previous_mode, previous_shape);
            else
                ob_main_80030f60(payload, node, descriptor, previous_shape, previous_mode, previous_mode);
            previous_shape = r_u32(node + 16);
            handle = r_u32(node + 4);
            previous_mode = r_u8(node + 2);
            result = sub_800257A0(handle);
        }
        node = r_u32(node + 8);
    } while (node);
    w_u16(0x800775A2, 0);
    w_u16(0x80077324, 0);
    ob_draft_scratch_release(payload);
    return result;
}
