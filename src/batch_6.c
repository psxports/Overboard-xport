#include "psx.h"
#include "draft_signatures.h"
#include "native_extra_signatures.h"
#include "native_runtime.h"
#include "game_signatures.h"
#include "decomp_208_signatures.h"
#include "native_timers.h"

uint32 ob_fire_when_ready(uint32 object, uint32 time, uint32 entry_stack_address)
{
    /* Original occurrences
     * GAME.BIN:0x800A24D0
     * GAME.BIN:0x800A2514
     */
    uint32 ready = r_u8(r_u32(object + 108) + 80);
    if (ready) return ready;
    uint32 flags = r_u16(object + 312);
    w_u16(object + 312, flags & 0xFFFB);
    ob_game_800B006C(object, time);
    return entry_stack_address - 0x4E;
}

uint32 ob_game_800a7700(uint32 object, uint32 time, uint32 retained_step, uint32 effect_record, uint32 projectile_request)
{
    FUNCTION_MARKER(0x800A7700, "GAME.BIN");
    uint32 state = r_u32(object + 108);
    if (r_s32(state + 4) < (sint32)time)
    {
        if (r_u32(state) == 1)
        {
            w_u32(state, 0);
            uint32 random = ob_main_8001AFC8();
            w_u32(state + 4, time + (random & 0xFFF));
            sub_8001195C((uint32)(sint32)r_s16(object + 306));
            w_u16(object + 306, UINT32_MAX);
        }
        else
        {
            w_u32(state, 1);
            uint32 random = ob_main_8001AFC8();
            w_u32(state + 4, time + (random & 0x7FFF) + 10000);
            if (r_s16(object + 306) == -1)
            {
                uint32 sound = ob_main_80011A24(0x80067790, 255, 128, r_u32(object + 44), time, 1);
                w_u16(object + 306, sound);
            }
        }
    }
    if (r_s32(state + 12) < (sint32)time)
    {
        ob_game_800B8E40(r_u32(object + 44), effect_record, time);
        w_u8(effect_record + 95, 1);
        uint32 difference = r_u32(state + 4) - time;
        sint32 spread = (sint32)(35768u - difference) >> 9;
        uint32 step = retained_step;
        do
        {
            uint32 vertical = 64;
            if (r_u32(state) != 1)
                vertical = (uint32)spread + (ob_main_8001AFC8() & 15);
            w_u32(effect_record + 36, vertical);
            w_u32(effect_record + 32, 0);
            w_u32(effect_record + 40, 0);
            uint32 random = ob_main_8001AFC8();
            uint32 x = r_u32(effect_record) - 1024 + (random & 0x7FF);
            uint32 y = r_u32(effect_record + 4) + 1000;
            w_u32(effect_record, x);
            w_u32(effect_record + 4, y);
            random = ob_main_8001AFC8();
            w_u32(effect_record + 44, 0x800C48E4);
            w_u32(effect_record + 56, 4000);
            w_u8(effect_record + 92, 12);
            uint32 owner = r_u32(0x80083E34);
            uint32 z = r_u32(effect_record + 8) - 1024 + ((uint32)((sint32)random >> 5) & 0x7FF);
            w_u16(effect_record + 86, 408);
            w_u16(effect_record + 88, 560);
            w_u16(effect_record + 90, 408);
            w_u32(effect_record + 8, z);
            ob_game_80092408(owner, effect_record, time, 6);
            if (r_u32(state) == 1)
                w_u32(state + 12, time + 750);
            else
            {
                step = (uint32)((sint32)difference >> 4) + 1000;
                if ((sint32)step > 4000) step = 4000;
                w_u32(state + 12, time + step + r_u32(effect_record + 60));
            }
            w_u32(effect_record + 60, r_u32(effect_record + 60) + step);
        } while (r_s32(state + 12) < (sint32)(time + 250));
    }
    if (r_u32(state) == 1 && r_s32(state + 8) < (sint32)time)
    {
        uint32 pitch = (ob_main_8001AFC8() & 0x1FFF) - 12288;
        uint32 random = ob_main_8001AFC8();
        uint32 matrix = ob_draft_scratch_acquire(24);
        sub_80029F58((uint32)(sint32)(sint16)(random * 2), matrix);
        sub_8002A870(matrix, (uint32)(sint32)(sint16)pitch, projectile_request + 12);
        w_u32(projectile_request, r_u32(r_u32(object + 44) + 108));
        w_u32(projectile_request + 4, r_u32(r_u32(object + 44) + 112) + 1000);
        uint32 z = r_u32(r_u32(object + 44) + 116);
        w_u16(projectile_request + 60, 288);
        w_u32(projectile_request + 8, z);
        sint32 slot = r_s16(object + 326);
        w_u32(projectile_request + 44, 2000);
        w_u32(projectile_request + 76, 0x4000);
        w_u16(projectile_request + 86, 10);
        w_u32(projectile_request + 40, 0);
        w_u32(projectile_request + 36, 0);
        w_u32(projectile_request + 32, 0);
        w_u16(projectile_request + 84, 20);
        w_u32(projectile_request + 96, 0x800CBA00 + (uint32)slot * 104);
        /* Define fields the original leaves dependent on prior stack contents */
        w_u16(projectile_request + 50, 0);
        w_u16(projectile_request + 52, 0);
        w_u32(projectile_request + 56, UINT32_MAX);
        w_u32(projectile_request + 88, 0);
        w_u16(projectile_request + 92, 0);
        ob_game_8009A0C4(r_u32(object + 104), projectile_request, time);
        ob_draft_scratch_release(matrix);
        w_u32(state + 8, time + 1000);
    }
    return ob_game_800a7a60(object, 0, time + 250);
}

uint32 ob_game_8009c5d4(uint32 object, uint32 index, uint32 time, uint32 retained_record)
{
    FUNCTION_MARKER(0x8009C5D4, "GAME.BIN");
    /* Preserve bytes the original leaves untouched in its attribute storage */
    w_u32(retained_record + 44, 0x800C4C40);
    w_u32(retained_record + 56, 500);
    w_u16(retained_record + 86, 240);
    w_u16(retained_record + 88, 240);
    w_u16(retained_record + 90, 240);
    w_u8(retained_record + 92, 8);
    w_u8(retained_record + 93, 4);
    w_u32(retained_record + 60, 0);
    w_u8(retained_record + 94, 0);
    w_u32(retained_record + 76, UINT32_MAX);
    w_u32(retained_record + 48, object);
    uint32 node = r_u32(0x800C4FFC + index * 4);
    uint32 owner = r_u32(0x80083E34);
    w_u32(retained_record + 52, node);
    return ob_game_80092408(owner, retained_record, time, 6);
}

uint32 ob_game_8009f5c4(uint32 object, uint32 identifier, uint32 time, uint32 retained_record)
{
    FUNCTION_MARKER(0x8009F5C4, "GAME.BIN");
    uint32 node = sub_800437C4(object, (sint32)identifier);
    w_u32(retained_record + 44, 0x800C5290);
    w_u32(retained_record + 56, 2000);
    w_u16(retained_record + 88, 960);
    w_u8(retained_record + 92, 2);
    w_u8(retained_record + 93, 4);
    w_u16(retained_record + 86, 32);
    w_u16(retained_record + 90, 32);
    uint32 owner = r_u32(0x80083E34);
    w_u32(retained_record + 60, 0);
    w_u8(retained_record + 94, 0);
    w_u32(retained_record + 76, 1);
    w_u32(retained_record + 48, object);
    w_u32(retained_record + 52, node);
    return ob_game_80092408(owner, retained_record, time, 6);
}

static void ob_profile_draw_sync(void)
{
    ob_game_800a71c8();
}

void ob_game_800a71f4(uint32 index)
{
    FUNCTION_MARKER(0x800A71F4, "GAME.BIN");
    w_u16(0x800C82CC, r_u8(0x800C5462 + index * 4));
    sub_800558E4();
    sint32 event = OpenEventPSX(0xF2000001, 2, 0x2000, 0);
    w_u32(0x800C82C8, event);
    EnableEventPSX(event);
    ob_native_timers_set(0xF2000001, 0xFA00, 0x1000);
    DrawSyncCallback(ob_profile_draw_sync);
    sub_800558F4();
}

static uint32 ob_division_normalization(uint32 word)
{
    uint32 offset;
    if (word > 0xFFFF)
        offset = word > 0xFFFFFF ? 24 : 16;
    else
        offset = word >= 256 ? 8 : 0;
    return 32 - (offset + r_u8(0x80011520 + (word >> offset)));
}

/* Divide a normalized two-word numerator into two base-65536 digits */
static uint32 ob_division_digits(uint32 high, uint32 low, uint32 divisor, uint32 *remainder)
{
    uint32 upper = divisor >> 16;
    uint32 lower = divisor & 0xFFFF;
    if (!upper) ob_native_guest_break(0x8005FC98, 7);
    uint32 first = high / upper;
    uint32 partial = ((high % upper) << 16) | (low >> 16);
    uint32 product = first * lower;
    if (partial < product)
    {
        partial += divisor;
        --first;
        if (partial >= divisor && partial < product)
        {
            --first;
            partial += divisor;
        }
    }
    partial -= product;
    uint32 second = partial / upper;
    partial = ((partial % upper) << 16) | (low & 0xFFFF);
    product = second * lower;
    if (partial < product)
    {
        partial += divisor;
        --second;
        if (partial >= divisor && partial < product)
        {
            --second;
            partial += divisor;
        }
    }
    *remainder = partial - product;
    return (first << 16) | second;
}

uint64 ob_main_8005fc98(uint64 numerator, uint64 denominator, uint32 remainder_address)
{
    FUNCTION_MARKER(0x8005FC98, "SLES_008.65");
    uint32 low = (uint32)numerator;
    uint32 high = (uint32)(numerator >> 32);
    uint32 divisor_low = (uint32)denominator;
    uint32 divisor_high = (uint32)(denominator >> 32);
    uint32 quotient_low;
    uint32 quotient_high;
    uint64 remainder;
    if (!divisor_high)
    {
        if (!divisor_low) ob_native_guest_break(0x8005FC98, 7);
        uint32 shift = ob_division_normalization(divisor_low);
        uint32 normalized = divisor_low << (shift & 31);
        uint32 residue;
        if (high < divisor_low)
        {
            if (shift)
            {
                high = (high << (shift & 31)) | (low >> ((32 - shift) & 31));
                low <<= shift & 31;
            }
            quotient_high = 0;
            quotient_low = ob_division_digits(high, low, normalized, &residue);
        }
        else
        {
            if (!shift)
            {
                high -= divisor_low;
                quotient_high = 1;
            }
            else
            {
                uint32 top = high >> ((32 - shift) & 31);
                uint32 middle = (high << (shift & 31)) | (low >> ((32 - shift) & 31));
                low <<= shift & 31;
                quotient_high = ob_division_digits(top, middle, normalized, &high);
            }
            quotient_low = ob_division_digits(high, low, normalized, &residue);
        }
        remainder = residue >> (shift & 31);
    }
    else if (high < divisor_high)
    {
        quotient_low = 0;
        quotient_high = 0;
        remainder = numerator;
    }
    else
    {
        uint32 shift = ob_division_normalization(divisor_high);
        quotient_high = 0;
        if (!shift)
        {
            quotient_low = high > divisor_high || low >= divisor_low;
            remainder = quotient_low ? numerator - denominator : numerator;
        }
        else
        {
            uint32 reverse = (32 - shift) & 31;
            uint32 normalized_high = (divisor_high << (shift & 31)) | (divisor_low >> reverse);
            uint32 normalized_low = divisor_low << (shift & 31);
            uint32 top = high >> reverse;
            uint32 middle = (high << (shift & 31)) | (low >> reverse);
            low <<= shift & 31;
            uint32 residue;
            quotient_low = ob_division_digits(top, middle, normalized_high, &residue);
            uint64 product = (uint64)quotient_low * normalized_low;
            uint64 partial = ((uint64)residue << 32) | low;
            if (partial < product)
            {
                --quotient_low;
                product -= ((uint64)normalized_high << 32) | normalized_low;
            }
            remainder = (partial - product) >> (shift & 31);
        }
    }
    if (remainder_address)
    {
        w_u32(remainder_address, (uint32)remainder);
        w_u32(remainder_address + 4, (uint32)(remainder >> 32));
    }
    return ((uint64)quotient_high << 32) | quotient_low;
}

uint32 ob_game_800a6f00(void)
{
    FUNCTION_MARKER(0x800A6F00, "GAME.BIN");
    w_u32(0x800C8560, 0);
    sint32 handle = PCcreat(psx_addr(0x8008E2EC, 23), 0);
    w_u32(0x800D5C88, handle);
    if (handle != -1)
    {
        uint32 timer = sub_80054A24(0x800A6E38, 100);
        w_u32(0x800C8310, timer);
        w_u32(0x800D64B8, 1);
    }
    return 1;
}

uint32 ob_game_800a7090(sint32 handle)
{
    FUNCTION_MARKER(0x800A7090, "GAME.BIN");
    w_u32(0x800D64B8, 0);
    sint32 closed = PCclose(handle);
    return ob_main_80054b68(r_u32(0x800C8310), (uint32)closed);
}

uint32 ob_game_800a6f70(uint32 count, uint32 incoming_v0)
{
    FUNCTION_MARKER(0x800A6F70, "GAME.BIN");
    if (!count)
        return incoming_v0;
    uint32 head = r_u32(0x800D64BC);
    w_u32(0x800D64B8, 0);
    uint32 result;
    if (head + count > 512)
    {
        uint32 first_buffer = 0x800C9110 + (head << 2);
        uint32 first_size = (512 - head) << 2;
        uint32 handle = r_u32(0x800D5C88);
        ob_main_8005FB28(handle, first_buffer, first_size);
        handle = r_u32(0x800D5C88);
        uint32 pending = r_u32(0x800C84DC);
        head = r_u32(0x800D64BC);
        uint32 remaining = pending - 512 + head;
        w_u32(0x800C84DC, remaining);
        ob_main_8005FB28(handle, 0x800C9110, remaining << 2);
        result = r_u32(0x800C84DC);
        w_u32(0x800C84DC, 0);
    }
    else
    {
        uint32 buffer = 0x800C9110 + (head << 2);
        uint32 handle = r_u32(0x800D5C88);
        ob_main_8005FB28(handle, buffer, count << 2);
        head = r_u32(0x800D64BC);
        uint32 pending = r_u32(0x800C84DC);
        w_u32(0x800C84DC, 0);
        result = head + pending;
    }
    w_u32(0x800D64BC, result);
    result = r_u32(0x800D64BC);
    w_u32(0x800D64B8, 1);
    result &= 511;
    w_u32(0x800D64BC, result);
    return result;
}

uint32 ob_main_8001efec(uint32 parent, uint32 sample, uint32 volume, uint32 pan,
    uint32 mode, uint32 pitch_multiplier, uint32 flags, uint32 enabled)
{
    FUNCTION_MARKER(0x8001EFEC, "SLES_008.65");
    if (!enabled)
        return enabled;
    uint32 disabled = r_u8(0x8006C011);
    if (disabled)
        return disabled;
    uint32 slot = ob_find_sound_slot();
    if (slot == UINT32_MAX)
        return UINT32_MAX;
    uint32 volume_product = (volume & 255) * r_u8(0x8006C010);
    uint32 resource = 0x800778A0 + sample * 20;
    uint32 sound = 0x80078540 + slot * 28;
    uint32 frequency = r_u32(resource + 16);
    w_u32(sound + 4, 3);
    w_u8(sound + 23, pan);
    w_u8(sound + 24, mode);
    w_u32(sound + 8, flags);
    w_u32(sound, frequency);
    w_u32(sound + 12, pitch_multiplier);
    w_u8(sound + 22, volume_product / 255);
    uint32 parent_sound = 0x80078540 + parent * 28;
    uint32 parent_flags = r_u32(parent_sound + 4);
    w_u32(parent_sound + 16, slot);
    w_u32(parent_sound + 4, parent_flags | 4);
    uint32 voice = ob_find_voice_slot();
    if (voice == UINT32_MAX)
        return UINT32_MAX;
    uint32 product = pitch_multiplier * frequency;
    uint32 voice_state = 0x800782A0 + voice * 28;
    w_u8(sound + 20, voice);
    w_u32(voice_state, 5);
    w_u32(voice_state + 4, 2);
    uint32 rounded = product + ((sint32)product < 0 ? 255u : 0u);
    sint32 pitch = (sint32)(rounded << 8) >> 16;
    w_u32(voice_state + 16, pitch);
    w_u32(voice_state + 20, slot);
    uint32 attribute = ob_draft_scratch_acquire(sizeof(SpuVoiceAttr));
    w_u32(attribute, 1u << (voice & 31));
    w_u32(attribute + 4, 144);
    w_u32(attribute + 28, r_u32(resource));
    w_u16(attribute + 20, r_u32(voice_state + 16));
    SpuSetVoiceAttr((SpuVoiceAttr *)psx_addr(attribute, sizeof(SpuVoiceAttr)));
    if (r_u8(0x80078BEC) == 3 && r_u32(resource + 8))
    {
        uint32 second = ob_find_voice_slot();
        if (second != UINT32_MAX)
        {
            uint32 second_state = 0x800782A0 + second * 28;
            w_u8(sound + 21, second);
            w_u32(second_state, 1);
            w_u32(second_state + 4, 1);
            w_u32(second_state + 16, pitch);
            w_u32(second_state + 20, slot);
            w_u32(attribute, 1u << (second & 31));
            w_u32(attribute + 4, 144);
            w_u32(attribute + 28, r_u32(resource + 8));
            w_u16(attribute + 20, r_u32(second_state + 16));
            SpuSetVoiceAttr((SpuVoiceAttr *)psx_addr(attribute, sizeof(SpuVoiceAttr)));
        }
    }
    else if (r_u8(0x80078BEC) == 4 && (flags & 4))
    {
        w_u32(voice_state + 4, 3);
        uint32 second = ob_find_voice_slot();
        if (second != UINT32_MAX)
        {
            product = pitch_multiplier * frequency;
            w_u8(sound + 21, second);
            uint32 second_state = 0x800782A0 + second * 28;
            w_u32(second_state, 5);
            w_u32(second_state + 4, 2);
            rounded = product + ((sint32)product < 0 ? 255u : 0u);
            sint32 second_pitch = (sint32)(rounded << 8) >> 16;
            w_u32(second_state + 16, second_pitch);
            w_u32(second_state + 20, slot);
            w_u32(attribute, 1u << (second & 31));
            w_u32(attribute + 4, 144);
            w_u32(attribute + 28, r_u32(resource));
            w_u16(attribute + 20, r_u32(second_state + 16));
            SpuSetVoiceAttr((SpuVoiceAttr *)psx_addr(attribute, sizeof(SpuVoiceAttr)));
        }
    }
    else
        w_u8(sound + 21, 255);
    sub_8001FDA4(slot);
    ob_draft_scratch_release(attribute);
    return slot;
}

uint32 ob_main_8003a5b4(uint32 handle, uint32 callback)
{
    FUNCTION_MARKER(0x8003A5B4, "SLES_008.65");
    uint32 model = r_u32(handle);
    if (model & 3)
        model = sub_800257CC(handle);
    else
    {
        w_u16(model - 6, r_u16(model - 6) + 1);
        model = r_u32(handle);
    }
    uint32 primitives = r_u32(model + 52);
    uint32 count = r_u16(model + 14);
    uint32 vertices = r_u32(model + 32);
    uint32 index = 0;
    uint32 offset = 0;
    if (count)
    {
        do
        {
            uint32 primitive = r_u32(primitives);
            uint32 flags = r_u16(primitive);
            primitives += 4;
            if (flags & 0x400)
            {
                uint32 type = r_u16(primitive + 2);
                uint32 first;
                uint32 second;
                uint32 third;
                uint32 fourth = 0;
                if (type == 4)
                {
                    uint32 indices = primitive + 12;
                    first = vertices + r_u16(indices) * 8;
                    second = vertices + r_u16(indices + 2) * 8;
                    fourth = vertices + r_u16(indices + 6) * 8;
                    third = vertices + r_u16(indices + 4) * 8;
                }
                else
                {
                    uint32 indices = primitive + type * 2 + 4;
                    first = vertices + r_u16(indices) * 8;
                    second = vertices + r_u16(indices + 2) * 8;
                    third = vertices + r_u16(indices + 4) * 8;
                }
                for (uint32 axis = 0; axis < 3; ++axis)
                {
                    sint32 a = r_s16(first + axis * 2);
                    sint32 b = r_s16(second + axis * 2);
                    sint32 c = r_s16(third + axis * 2);
                    sint32 sum;
                    if (type == 4)
                        sum = a + b + c + r_s16(fourth + axis * 2);
                    else
                        sum = a * 2 + b + c;
                    w_u32(0x1F800000 + axis * 4, sum >> 2);
                }
                for (uint32 axis = 0; axis < 3; ++axis)
                {
                    w_u32(0x1F80000C + axis * 4, r_s16(first + axis * 2));
                    w_u32(0x1F800018 + axis * 4, r_s16(first + axis * 2));
                }
                for (uint32 axis = 0; axis < 2; ++axis)
                {
                    sint32 candidate = r_s16(second + axis * 2);
                    sint32 maximum = r_s32(0x1F80000C + axis * 4);
                    if (maximum < candidate)
                        w_u32(0x1F80000C + axis * 4, candidate);
                    else if (candidate < r_s32(0x1F800018 + axis * 4))
                        w_u32(0x1F800018 + axis * 4, candidate);
                }
                sint32 candidate_z = r_s16(second + 4);
                sint32 maximum_z = r_s32(0x1F800014);
                if (maximum_z < candidate_z)
                    w_u32(0x1F800014, candidate_z);
                /* The original minimum-Z comparison reads the second vertex X */
                else if (r_s16(second) < r_s32(0x1F800020))
                    w_u32(0x1F800020, candidate_z);
                for (uint32 axis = 0; axis < 3; ++axis)
                {
                    uint32 maximum = r_u32(0x1F80000C + axis * 4);
                    uint32 center_first = r_u32(0x1F800000 + axis * 4);
                    uint32 minimum = r_u32(0x1F800018 + axis * 4);
                    uint32 center_second = r_u32(0x1F800000 + axis * 4);
                    w_u32(0x1F80000C + axis * 4, maximum - center_first);
                    w_u32(0x1F800018 + axis * 4, minimum - center_second);
                }
                for (uint32 axis = 0; axis < 3; ++axis)
                {
                    uint32 scale = r_u16(model + 8);
                    uint32 center = r_u32(0x1F800000 + axis * 4);
                    uint32 product = center * scale;
                    w_u32(0x1F800000 + axis * 4, (sint32)product >> 8);
                }
                uint32 data = r_u32(model + 44) + offset;
                ob_draft_unresolved_call(callback, 4u, 0x1F800000u, 0x1F80000Cu, index, data);
            }
            count = r_u16(model + 14);
            ++index;
            offset += 12;
        } while (index < count);
    }
    return sub_800257A0(handle);
}

uint32 ob_game_800af0ec(uint32 x1, uint32 y1, uint32 x2, uint32 y2,
    uint32 width, uint32 red, uint32 green, uint32 blue)
{
    FUNCTION_MARKER(0x800AF0EC, "GAME.BIN");
    uint32 window_xy = r_u32(0x8008E970);
    uint32 window_wh = r_u32(0x8008E974);
    PSX_RECT window;
    window.x = (sint16)window_xy;
    window.y = (sint16)(window_xy >> 16);
    window.w = (sint16)window_wh;
    window.h = (sint16)(window_wh >> 16);
    uint32 jitter_mask = 7;
    uint32 jitter_center = 3;
    uint32 counter = r_u32(0x800C5710);
    w_u32(0x800C5710, counter + 1);
    if ((sint32)counter >= 5)
    {
        sint32 random = (sint32)ob_random15() >> 2;
        w_u32(0x800C570C, random % 8);
        w_u32(0x800C5710, 0);
    }
    uint32 end = r_u32(0x800775BC);
    uint32 mode_packet = r_u32(0x800774A8);
    if (end - mode_packet < 876)
        return 1;
    uint32 old_tag = r_u32(r_u32(0x80077634));
    w_u32(0x800774A8, mode_packet + 12);
    uint32 page = GetTPage(0, 1, 0, 0);
    SetDrawMode(psx_addr(mode_packet, 12), 1, 0, (uint16)page, &window);
    uint32 previous = r_u32(0x80077634);
    uint32 polygons = r_u32(0x800774A8);
    w_u32(0x80077634, mode_packet);
    uint32 tag = r_u32(previous);
    w_u32(previous, (tag & 0xFF000000) | (mode_packet & 0xFFFFFF));
    for (uint32 index = 0; index < 24; ++index)
    {
        uint32 packet = polygons + index * 36;
        POLY_G4 *polygon = (POLY_G4 *)psx_addr(packet, sizeof(POLY_G4));
        setPolyG4(polygon);
        setSemiTrans(polygon, 1);
        w_u8(packet + 4, 0);
        w_u8(packet + 5, 0);
        w_u8(packet + 6, 0);
        w_u8(packet + 12, 0);
        w_u8(packet + 13, 0);
        w_u8(packet + 14, 0);
        w_u8(packet + 20, red);
        w_u8(packet + 21, green);
        w_u8(packet + 22, blue);
        w_u8(packet + 28, red);
        w_u8(packet + 29, green);
        w_u8(packet + 30, blue);
    }
    uint32 dx = x2 - x1;
    uint32 dy = y2 - y1;
    uint32 angle = sub_80027F98(dx, dy);
    uint32 perpendicular = ((((angle + 0x4000) & 65535) + 8) >> 4) * 2;
    uint32 product = width * (uint32)r_s16(0x8006CB04 + perpendicular);
    sint32 offset_x = (sint32)product / 16384;
    product = width * (uint32)r_s16(0x8006C304 + perpendicular);
    sint32 offset_y = (sint32)product / 16384;
    w_u16(polygons + 24, x1);
    w_u16(polygons + 26, y1);
    uint32 length = ob_main_8002b904(dx * dx + dy * dy);
    if ((sint32)length < 48)
    {
        jitter_mask = 3;
        jitter_center = 1;
    }
    uint32 packet = polygons;
    for (uint32 step = 0; step < 11; ++step)
    {
        uint32 pattern = r_u32(0x800C570C);
        uint32 table_offset = step * 4 + pattern * 48;
        angle += r_u16(0x800C558C + table_offset);
        sint32 amplitude = r_s16(0x800C558E + table_offset);
        uint32 trigonometric = (((angle & 65535) + 8) >> 4) * 2;
        sint32 cosine = r_s16(0x8006CB04 + trigonometric);
        product = (uint32)amplitude * (uint32)cosine;
        product *= length;
        sint32 delta_x = (sint32)product / 0x4000000;
        w_u16(packet + 32, r_u16(packet + 24) + (uint32)delta_x);
        amplitude = r_s16(0x800C558E + table_offset);
        sint32 sine = r_s16(0x8006C304 + trigonometric);
        product = (uint32)amplitude * (uint32)sine;
        product *= length;
        sint32 delta_y = (sint32)product / 0x4000000;
        w_u16(packet + 34, r_u16(packet + 26) + (uint32)delta_y);
        uint32 random = (uint32)((sint32)ob_random15() >> 4);
        uint32 center_x = r_u16(packet + 32);
        center_x += (random & jitter_mask) - jitter_center;
        w_u16(packet + 32, center_x);
        random = (uint32)((sint32)ob_random15() >> 4);
        uint32 center_y = r_u16(packet + 34);
        center_y += (random & jitter_mask) - jitter_center;
        uint32 start_x = r_u16(packet + 24);
        w_u16(packet + 34, center_y);
        uint32 start_y = r_u16(packet + 26);
        w_u16(packet + 8, start_x + (uint32)offset_x);
        center_x = r_u16(packet + 32);
        w_u16(packet + 10, start_y + (uint32)offset_y);
        uint32 next_x = r_u16(packet + 32);
        w_u16(packet + 16, center_x + (uint32)offset_x);
        center_y = r_u16(packet + 34);
        w_u16(packet + 60, next_x);
        uint32 next_y = r_u16(packet + 34);
        w_u16(packet + 18, center_y + (uint32)offset_y);
        w_u16(packet + 62, next_y);
        packet += 36;
    }
    uint32 start_x = r_u16(packet + 24);
    uint32 start_y = r_u16(packet + 26);
    w_u16(packet + 16, x2);
    w_u16(packet + 18, y2);
    w_u16(packet + 32, x2);
    w_u16(packet + 8, start_x + (uint32)offset_x);
    w_u16(packet + 10, start_y + (uint32)offset_y);
    w_u16(packet + 34, y2);
    uint32 opposite = packet + 36;
    uint32 source = polygons;
    for (uint32 step = 0; step < 12; ++step)
    {
        w_u16(opposite + 8, r_u16(source + 24) - (uint32)offset_x);
        w_u16(opposite + 10, r_u16(source + 26) - (uint32)offset_y);
        w_u16(opposite + 16, r_u16(source + 32) - (uint32)offset_x);
        w_u16(opposite + 18, r_u16(source + 34) - (uint32)offset_y);
        w_u16(opposite + 24, r_u16(source + 24));
        w_u16(opposite + 26, r_u16(source + 26));
        w_u16(opposite + 32, r_u16(source + 32));
        w_u16(opposite + 34, r_u16(source + 34));
        opposite += 36;
        source += 36;
    }
    opposite -= 36;
    w_u16(opposite + 16, x2);
    w_u16(opposite + 18, y2);
    w_u16(opposite + 32, x2);
    w_u16(opposite + 34, y2);
    w_u16(polygons + 8, x1);
    w_u16(polygons + 10, y1);
    w_u16(polygons + 24, x1);
    w_u16(polygons + 26, y1);
    w_u16(polygons + 440, x1);
    w_u16(polygons + 442, y1);
    w_u16(polygons + 456, x1);
    w_u16(polygons + 458, y1);
    uint32 tail = 0;
    for (uint32 index = 0; index < 24; ++index)
    {
        previous = r_u32(0x80077634);
        tail = r_u32(0x800774A8);
        tag = r_u32(previous);
        w_u32(0x800774A8, tail + 36);
        w_u32(0x80077634, tail);
        w_u32(previous, (tag & 0xFF000000) | (tail & 0xFFFFFF));
    }
    tag = r_u32(tail);
    uint32 result = old_tag & 0xFFFFFF;
    w_u32(tail, (tag & 0xFF000000) | result);
    return result;
}
