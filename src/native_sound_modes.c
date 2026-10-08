#include "draft_signatures.h"
#include "native_runtime.h"

/* Only the volume fields selected by mask three are consumed */
static uint32 ob_sound_set_volume(uint32 voice,uint32 left,uint32 right)
{
    uint32 attributes=ob_draft_scratch_acquire(64u);
    w_u32(attributes,1u<<(voice&31u));
    w_u32(attributes+4u,3u);
    w_u16(attributes+8u,(uint16)left);
    w_u16(attributes+10u,(uint16)right);
    uint32 result=ob_draft_unresolved_call(0x80062EE8u,1u,attributes);
    ob_draft_scratch_release(attributes);
    return result;
}

uint32 sub_8001FE3C(uint32 sound_slot)
{
    FUNCTION_MARKER(0x8001FE3Cu,"SLES_008.65");
    uint32 offset=sound_slot*28u;
    uint32 voice=(uint32)(sint32)(sint8)r_u8(0x80078554u+offset);
    uint32 volume=r_u8(0x80078556u+offset);
    uint32 voice_offset=voice*28u;
    if(r_u32(0x800782B4u+voice_offset)==sound_slot)
    {
        uint32 level=volume<<6;
        w_u32(0x800782A8u+voice_offset,level);
        w_u32(0x800782ACu+voice_offset,level);
        return ob_sound_set_volume(voice,level,level);
    }
    return volume;
}

uint32 sub_8001FFC0(uint32 sound_slot)
{
    FUNCTION_MARKER(0x8001FFC0u,"SLES_008.65");
    uint32 offset=sound_slot*28u;
    uint32 volume=r_u8(0x80078556u+offset);
    uint32 flags=r_u32(0x80078548u+offset);
    uint32 pan=r_u8(0x80078557u+offset);
    uint32 separation=r_u8(0x80078558u+offset);
    uint32 secondary_level=volume<<6,primary_level=secondary_level;
    if(flags&4u)
    {
        if(separation<15u)
            primary_level=(uint32)((sint32)(secondary_level*separation)/15);
        else if(separation>=16u)
            secondary_level=(uint32)((sint32)(secondary_level*(31u-separation))/15);
    }
    uint32 primary_left=(uint32)((sint32)(primary_level*r_u8(0x8006C018u+pan))>>8);
    uint32 primary_right=(uint32)((sint32)(primary_level*r_u8(0x8006C036u-pan))>>8);
    uint32 secondary_left=(uint32)((sint32)(secondary_level*r_u8(0x8006C038u+pan))>>8);
    uint32 secondary_right=(uint32)((sint32)(secondary_level*r_u8(0x8006C056u-pan))>>8);
    if((flags&6u)==2u&&r_u8(0x80078BECu)!=1u)
    {
        primary_left=secondary_left;
        primary_right=0u-secondary_right;
    }
    uint32 voice=(uint32)(sint32)(sint8)r_u8(0x80078554u+offset);
    uint32 voice_offset=voice*28u;
    if(r_u32(0x800782B4u+voice_offset)==sound_slot)
    {
        w_u32(0x800782A8u+voice_offset,primary_left);
        w_u32(0x800782ACu+voice_offset,primary_right);
        ob_sound_set_volume(voice,primary_left,primary_right);
    }
    uint32 result=flags&4u;
    if(r_u8(0x80078BECu)==4u&&result)
    {
        voice=(uint32)(sint32)(sint8)r_u8(0x80078555u+offset);
        voice_offset=voice*28u;
        result=r_u32(0x800782B4u+voice_offset);
        if(result==sound_slot)
        {
            uint32 right=0u-secondary_right;
            w_u32(0x800782A8u+voice_offset,secondary_left);
            w_u32(0x800782ACu+voice_offset,right);
            return ob_sound_set_volume(voice,secondary_left,right);
        }
    }
    return result;
}
