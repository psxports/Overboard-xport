#include "psx.h"
#include "front_signatures.h"
#include "native_runtime.h"

/* Geometry and color fields consumed by the existing main renderer */
static uint32 front_a_glyph(uint32 texture, uint32 u, uint32 v, uint32 x, uint32 y,
                           uint32 red, uint32 green, uint32 blue, uint32 flags)
{
    return ob_append_colored_texture_quad(texture, u, v, 15u, 15u, x, y, flags, red, green, blue);
}

uint32 ob_front_a_callback(uint32 target,uint32 available,uint32 first,uint32 second)
{
    /* Forward the arguments supplied by the original callback callsite */
    if(available==0) return ob_draft_unresolved_call(target,0);
    if(available==1) return ob_draft_unresolved_call(target,1,first);
    return ob_draft_unresolved_call(target,2,first,second);
}

uint32 ob_front_8008E140(uint32 a1)
{
    FUNCTION_MARKER(0x8008E140u, "FRONT.BIN");
    ob_front_8008DD3C(a1);
    ob_front_8008DD3C(r_u32(0x8009BB8Cu));
    uint32 result = ob_front_8008DD3C(r_u32(0x8009BB90u));
    w_u32(0x8009BB88u, 0u); w_u32(0x8009BB8Cu, 0u); w_u32(0x8009BB90u, 0u);
    return result;
}

uint32 ob_front_8008E270(void)
{
    FUNCTION_MARKER(0x8008E270u, "FRONT.BIN");
    return ob_front_8008E278(r_u32(0x8009BB90u));
}

uint32 ob_front_8008E278(uint32 object)
{
    FUNCTION_MARKER(0x8008E278u, "FRONT.BIN");
    if (r_u32(object + 120u) - 1u < 2u) return 256u;
    sub_80011984(0x8006ABFCu,255u,25u,15u,256u,0u,0u);
    w_u32(r_u32(0x8009BB90u) + 120u,1u);
    return 1u;
}

void ob_front_80092D14(void)
{
    FUNCTION_MARKER(0x80092D14u, "FRONT.BIN");
}

uint32 ob_front_80092280(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80092280u, "FRONT.BIN");
    uint32 value = r_u32(a2 + 8u), sound;
    if (value == 0u) { ob_draft_unresolved_call(0x80011870u,1u,1u); sound = 0x8006AC1Cu; }
    else if (value == 1u) { ob_draft_unresolved_call(0x80011870u,1u,2u); sound = 0x8006AC3Cu; }
    else if (value == 2u) { ob_draft_unresolved_call(0x80011870u,1u,4u); sound = 0x8006AC18u; }
    else { w_u8(0x8006C22Fu,value); return value; }
    sub_80011984(sound,255u,15u,15u,256u,0u,0u);
    value = r_u32(a2 + 8u); w_u8(0x8006C22Fu,value); return value;
}

uint32 ob_front_80092704(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80092704u, "FRONT.BIN");
    uint32 y = r_u32(a2)*17u +55u;
    ob_front_80092E84(a1);
    uint32 selected = r_u32(a1+12u)==a2;
    uint32 flags = selected && (r_u32(a2+4u)&256u)!=0u;
    ob_front_80093BB4(r_u32(a2+8u),164u,y,selected,flags);
    return ob_front_80094488(r_u32(0x8009C878u+r_u32(a2)*4u),90u,y,
                            selected?91u:45u,selected?15u:40u,selected?8u:22u,0u);
}

uint32 ob_front_80092C30(uint32 a1)
{
    FUNCTION_MARKER(0x80092C30u, "FRONT.BIN");
    uint32 item = r_u32(a1+8u);
    ob_front_8009465C(0x8008D200u,50u,91u,15u,8u,0u);
    do {
        uint32 callback = r_u32(item+44u);
        if(callback) ob_front_a_callback(callback,2u,a1,item);
        item = r_u32(item+20u);
    } while(item != r_u32(a1+8u));
    return r_u32(a1+8u);
}

void ob_front_80093BB4(uint32 code, uint32 x, uint32 y, uint32 selected, uint32 flags)
{
    FUNCTION_MARKER(0x80093BB4u, "FRONT.BIN");
    uint32 texture;
    switch(code) {
    case 4: case 20: texture=0x8006AD74u; break;
    case 5: case 21: texture=0x8006AD7Cu; break;
    case 6: case 22: texture=0x8006AD70u; break;
    case 7: case 23: texture=0x8006AD78u; break;
    case 8: case 24: texture=selected?0x8006AD4Cu:0x8006AD88u; goto basic;
    case 9: case 25: texture=selected?0x8006AD54u:0x8006AD90u; goto basic;
    case 10: case 26: texture=selected?0x8006AD48u:0x8006AD84u; goto basic;
    case 11: case 27: texture=selected?0x8006AD50u:0x8006AD8Cu; goto basic;
    case 12: case 28: texture=selected?0x8006AD64u:0x8006ADA0u; goto basic;
    case 13: case 29: texture=selected?0x8006AD58u:0x8006AD94u; goto basic;
    case 14: case 30: texture=selected?0x8006AD5Cu:0x8006AD98u; goto basic;
    case 15: case 31: texture=selected?0x8006AD60u:0x8006AD9Cu; goto basic;
    default: return;
    }
    sub_800215FC(texture,0u,0u,16u,16u,x,y,selected?91u:45u,
                 selected?15u:40u,selected?8u:22u,flags);
    return;
basic:
    sub_80021460(texture,0u,0u,16u,16u,x,y,flags);
}

uint32 ob_front_80093E70(uint32 a1)
{
    FUNCTION_MARKER(0x80093E70u, "FRONT.BIN");
    uint32 index, record=a1;
    sint32 count=(sint32)r_u32(a1);
    for(index=0u;(sint32)index<count;++index,record+=36u)
        w_u32(record+36u,ob_front_800946F0(record+8u)+18u);
    if(count==0) ob_native_guest_break(0x80093E70, 7);
    uint32 spacing=(uint32)(357/count), position=12u;
    record=a1;
    for(index=0u;(sint32)index<count;++index,record+=36u) {
        uint32 x=r_u32(record+28u),y=r_u32(record+32u),width=r_u32(record+36u);
        if(x==0xFFFFFFFFu) x=position+(uint32)((sint32)(spacing-width)/2);
        else if(x==0xFFFFFFFEu) x=12u+(uint32)((sint32)(136u-width)/2);
        else if(x==0xFFFFFFFDu) x=233u+(uint32)((sint32)(136u-width)/2);
        if(y==0xFFFFFFFFu) y=220u;
        w_u32(record+28u,x); w_u32(record+32u,y);
        position+=spacing;
        ob_front_80094030(r_u32(record+4u),record+8u,x,y);
    }
    return count>0?0u:357u;
}

void ob_front_80094030(uint32 a1,uint32 a2,uint32 a3,uint32 a4)
{
    FUNCTION_MARKER(0x80094030u,"FRONT.BIN");
    uint32 texture=0u,code=0u;
    switch(a1) {
    case 0: texture=0x8006AD74u; break;
    case 1: texture=0x8006AD70u; break;
    case 2: code=7u; break; case 3: code=5u; break;
    case 4: code=14u; break; case 5: code=15u; break;
    case 6: code=3u; break; case 7: code=12u; break;
    case 8: texture=0x8006AD6Cu; break;
    case 9: texture=0x8006AD68u; break;
    case 10: texture=0x8006AD80u; break;
    default: sub_80022AD4(a2,a3,a4+5u,128u,128u,128u,0u); return;
    }
    if(texture) sub_800215FC(texture,0u,0u,16u,16u,a3,a4,91u,15u,8u,0u);
    else ob_front_80093BB4(code,a3,a4,1u,0u);
    sub_80022AD4(a2,a3+18u,a4+5u,128u,128u,128u,0u);
}

uint32 ob_front_80094488(uint32 text,uint32 x,uint32 y,uint32 red,uint32 green,uint32 blue,uint32 flags)
{
    FUNCTION_MARKER(0x80094488u,"FRONT.BIN");
    /* The entry identity return is overwritten by the loop comparison */
    uint32 texture=0u,index=0u;
    while((sint32)index<(sint32)ob_draft_unresolved_call(0x80063FB8u,1u,text)) {
        uint32 character=r_u8(text+index);
        if(character==32u) x+=6u;
        else {
            sint32 glyph=(sint32)character-33;
            sint32 page=(glyph<0?glyph+15:glyph)>>4;
            sint32 cell=glyph-page*16;
            if((uint32)page<6u) texture=0x8006AD30u+(uint32)page*4u;
            /* The default page retains the previous glyph texture */
            if(texture) front_a_glyph(texture,(uint32)((cell%4)*16),(uint32)((cell/4)*16),x,y,red,green,blue,flags);
            x+=1u+(uint32)(sint32)(sint8)r_u8(0x8009CC74u+(uint32)glyph);
        }
        ++index;
    }
    /* The terminating signed loop comparison leaves zero in v0 */
    return ob_draw_text_end(0u);
}

uint32 ob_front_8009465C(uint32 text,uint32 y,uint32 red,uint32 green,uint32 blue,uint32 flags)
{
    FUNCTION_MARKER(0x8009465Cu,"FRONT.BIN");
    uint32 width=ob_front_800946F0(text);
    return ob_front_80094488(text,(uint32)((sint32)(386u-width)/2),y,red,green,blue,flags);
}

uint32 ob_front_800949F4(uint32 object,uint32 state)
{
    FUNCTION_MARKER(0x800949F4u,"FRONT.BIN");
    uint32 value;
    switch(state) {
    case 0: value=0x8006AAF0u; break;
    case 1: value=0x8006AAF8u; break;
    case 2: value=0x8006AB00u; break;
    case 3: value=0x8006AB08u; break;
    default: return (sint32)state<2?1u:3u;
    }
    w_u32(r_u32(object+52u)+40u,value); return value;
}

uint32 ob_front_80096B8C(uint32 selected_action,uint32 mode)
{
    FUNCTION_MARKER(0x80096B8Cu,"FRONT.BIN");
    static const uint32 strings[4]={0x8008D754u,0x8008D75Cu,0x8008D764u,0x8008D76Cu};
    uint32 result=0u;
    for(uint32 i=0u;i<4u;++i)
        result=ob_front_80094288(strings[i],r_u32(0x8009CF00u+i*4u),82u+i*56u,188u,mode==2u&&selected_action==i);
    if(mode==2u) { result=0x8009BFA4u; w_u32(0x8009BB94u,result); }
    return result;
}

uint32 ob_front_80094DFC(uint32 card,uint32 slot,uint32 x,uint32 y)
{
    FUNCTION_MARKER(0x80094DFCu,"FRONT.BIN");
    uint32 record=0x80089D34u+card*552u+slot*36u;
    uint32 texture=r_u32(0x8006CEC4u+slot*4u), header=0x80084AC8u+slot*512u;
    uint32 pixels,palette,frames=r_u8(header+2u)&3u;
    if(!r_u32(record)||!frames) { pixels=0x8009CD80u;palette=0x8009CE00u; }
    else
    {
        if(frames>=2u) w_u32(record+8u,r_u32(record+8u)<frames*2u-1u?r_u32(record+8u)+1u:0u);
        palette=header+96u;pixels=header+128u+(uint32)((sint32)r_u32(record+8u)/2)*128u;
    }
    ob_draft_unresolved_call(0x80020BD8u,3u,texture,pixels,palette);
    return sub_80021460(texture,0u,0u,16u,16u,(uint32)(sint32)(sint16)x,(uint32)(sint32)(sint16)y,0u);
}

uint32 ob_front_800978F0(uint32 menu)
{
    FUNCTION_MARKER(0x800978F0u,"FRONT.BIN");
    uint32 callback=r_u32(menu+32u);
    if(callback) ob_front_a_callback(callback,1u,menu,0u);
    callback=r_u32(menu+20u);
    return callback?ob_front_a_callback(callback,1u,menu,0u):0u;
}

uint32 ob_front_80097944(uint32 handle)
{
    FUNCTION_MARKER(0x80097944u,"FRONT.BIN");
    uint32 menu=r_u32(handle),item=r_u32(menu+12u),callback=r_u32(item+32u);
    uint32 command=ob_front_a_callback(callback,1u,handle,0u),parent;
    menu=r_u32(handle);item=r_u32(menu+12u);
    switch(command)
    {
    case 1u: if(!(r_u32(menu)&64u)) return 0xFFFFFFFEu; break;
    case 3u: if(!(r_u32(menu)&64u)) return 0xFFFFFFFDu; break;
    case 2u:
        if(r_u32(menu)&64u) break;
        callback=r_u32(menu+32u);if(callback)ob_front_a_callback(callback,1u,menu,0u);
        menu=r_u32(handle);parent=r_u32(menu+4u);if(!parent)return 0xFFFFFFFEu;
        w_u32(handle,parent);callback=r_u32(parent+28u);if(callback)ob_front_a_callback(callback,1u,parent,0u);
        break;
    case 4u: case 5u:
        callback=r_u32(item+52u);if(callback)ob_front_a_callback(callback,2u,menu,item);
        menu=r_u32(handle);item=r_u32(menu+12u);item=r_u32(item+(command==4u?16u:20u));w_u32(menu+12u,item);
        callback=r_u32(item+48u);if(callback)ob_front_a_callback(callback,2u,menu,item);
        break;
    case 6u: case 7u:
        if(!(r_u32(item+4u)&0x400u))
        {
            sint32 value=(sint32)r_u32(item+8u),maximum=(sint32)r_u32(item+12u);
            if(command==6u)
            {
                if(value<maximum)w_u32(item+8u,(uint32)value+1u);
                else if(r_u32(item+4u)&4u)w_u32(item+8u,0u);else break;
            }
            else
            {
                if(value>0)w_u32(item+8u,(uint32)value-1u);
                else if(r_u32(item+4u)&4u)w_u32(item+8u,(uint32)maximum);else break;
            }
        }
        menu=r_u32(handle);item=r_u32(menu+12u);callback=r_u32(item+(command==6u?56u:60u));
        if(callback)ob_front_a_callback(callback,2u,menu,item);
        break;
    case 10u:
        callback=r_u32(item+64u);if(callback)ob_front_a_callback(callback,2u,menu,item);
        menu=r_u32(handle);item=r_u32(menu+12u);
        if(callback&&(r_u32(item+4u)&1u))return 0xFFFFFFFFu;
        if(r_u32(item+4u)&0x10u)
        {
            callback=r_u32(menu+32u);if(callback)ob_front_a_callback(callback,1u,menu,0u);
            menu=r_u32(handle);item=r_u32(menu+12u);parent=r_u32(item+28u);w_u32(handle,parent);w_u32(parent+4u,menu);
            callback=r_u32(parent+28u);if(callback)ob_front_a_callback(callback,1u,parent,0u);
            parent=r_u32(handle);if(!(r_u32(parent)&0x80u))w_u32(parent+12u,r_u32(parent+8u));
        }
        else if(r_u32(item+4u)&0x20u)
        {
            callback=r_u32(menu+32u);if(callback)ob_front_a_callback(callback,1u,menu,0u);
            menu=r_u32(handle);parent=r_u32(menu+4u);w_u32(handle,parent);
            callback=r_u32(parent+28u);if(callback)ob_front_a_callback(callback,1u,parent,0u);
            if(!(r_u32(menu)&0x80u))w_u32(menu+12u,r_u32(menu+8u));
        }
        else if(r_u32(item+4u)&8u)
        {
            callback=r_u32(menu+32u);if(callback)ob_front_a_callback(callback,1u,menu,0u);
            return r_u32(r_u32(r_u32(handle)+12u));
        }
        break;
    default: break;
    }
    menu=r_u32(handle);callback=r_u32(menu+24u);if(callback)ob_front_a_callback(callback,1u,menu,0u);
    return 0xFFFFFFFFu;
}

uint32 ob_front_80097EF8(uint32 template_address)
{
    FUNCTION_MARKER(0x80097EF8u,"FRONT.BIN");
    uint32 handle=ob_draft_scratch_acquire(4u),object;
    w_u32(handle,0u);sub_800262CC(handle,68u);object=r_u32(handle);
    if(object)
    {
        ob_fill_words(object,68u,0u,object);
        for(uint32 i=0u;i<4u;++i)w_u32(object+i*4u,r_u32(template_address+i*4u));
        for(uint32 i=0u;i<9u;++i)w_u32(object+32u+i*4u,r_u32(template_address+16u+i*4u));
    }
    ob_draft_scratch_release(handle);return object;
}

void ob_front_80094FB0(uint32 source,uint32 destination,uint32 count)
{
    FUNCTION_MARKER(0x80094FB0u,"FRONT.BIN");
    if((sint32)count<=0)return;
    uint32 end=destination+count*2u;
    do
    {
        uint32 pixel=r_u16(source),color=0u;
        if(pixel)
        {
            uint32 sum=(pixel&31u)+((pixel>>5)&31u)+((pixel>>10)&31u);
            uint32 red=(uint32)(((uint64)(sum*26u)*0x2C0B02C1u)>>36);
            uint32 green=(uint32)(((uint64)(sum*22u)*0x2C0B02C1u)>>36);
            uint32 blue=(uint32)(((uint64)(sum*15u)*0x2C0B02C1u)>>36);
            color=red+(green<<5)+(blue<<10)+0x8000u;
        }
        w_u16(destination,(uint16)color);destination+=2u;source+=2u;
    }while((sint32)destination<(sint32)end);
}

uint32 ob_front_80095F9C(uint32 card,uint32 slot,uint32 state)
{
    FUNCTION_MARKER(0x80095F9Cu,"FRONT.BIN");
    uint32 x=136u+(uint32)((sint32)slot%5)*24u,y=88u+(uint32)((sint32)slot/5)*24u;
    if(card==0xFFFFFFFFu)state=0u;
    if(state==0u)return ob_draft_unresolved_call(0x80020A70u,8u,x,y,16u,16u,128u,128u,128u,1u);
    if(state>=1u&&state<=3u)
    {
        if(r_u32(0x8006BCC4u)==card&&r_u32(0x8006BCC8u)==slot)
            ob_draft_unresolved_call(0x80020A70u,8u,x-4u,y-4u,24u,24u,64u,64u,64u,1u);
        if(state>=2u)ob_draft_unresolved_call(0x80020A70u,8u,x-4u,y-4u,24u,24u,96u,0u,0u,1u);
        if(state<=2u)return ob_front_80094C68(card,slot,(uint32)(sint32)(sint16)x,(uint32)(sint32)(sint16)y);
        ob_front_80094DFC(card,slot,(uint32)(sint32)(sint16)x,(uint32)(sint32)(sint16)y);
        uint32 header=0x80084AC8u+slot*512u,text=0x8008D414u,storage=0u;
        if(r_u8(header)==83u&&r_u8(header+1u)==67u)
        {
            storage=ob_draft_scratch_acquire(40u);
            ob_draft_unresolved_call(0x80063FA8u,3u,storage,header+4u,32u);w_u8(storage+32u,0u);text=storage;
        }
        uint32 result=ob_front_8009465C(text,158u,91u,15u,8u,0u);
        if(storage)ob_draft_scratch_release(storage);return result;
    }
    return (sint32)state<2?1u:3u;
}

uint32 ob_front_800962A4(uint32 card_state,uint32 card_status,uint32 disabled)
{
    FUNCTION_MARKER(0x800962A4u,"FRONT.BIN");
    uint32 storage=ob_draft_scratch_acquire(112u),second=storage+56u,format=0;
    w_u8(storage,r_u8(0x8008D420u));w_u8(storage+1u,r_u8(0x8008D421u));
    w_u8(second,r_u8(0x8008D420u));w_u8(second+1u,r_u8(0x8008D421u));
    ob_draft_unresolved_call(0x80063FD8u,3u,storage+2u,0u,48u);
    ob_draft_unresolved_call(0x80063FD8u,3u,second+2u,0u,48u);
    switch(card_state)
    {
    case 0xFFFFFFFFu:format=0x8008D424u;break;
    case 0u:format=ob_draft_unresolved_call(0x800541A8u,1u,0u)?0x8008D44Cu:0x8008D43Cu;break;
    case 1u:format=0x8008D45Cu;break;
    case 2u:format=0x8008D46Cu;break;
    case 3u:format=0x8008D47Cu;break;
    case 4u:format=ob_draft_unresolved_call(0x800541A8u,1u,4u)?0x8008D49Cu:0x8008D48Cu;break;
    case 5u:format=0x8008D4ACu;break;
    case 6u:format=0x8008D4BCu;break;
    case 7u:format=0x8008D4CCu;break;
    default:break;
    }
    if(format) ob_draft_unresolved_call(0x80064028u,2u,card_state==0xFFFFFFFFu?second:storage,format);
    if(card_state!=0xFFFFFFFFu)
    {
        switch(card_status)
        {
        case 0u:case 3u:ob_draft_unresolved_call(0x80064028u,4u,second,0x8008D4DCu,storage,0x8008D4E4u);break;
        case 1u:ob_draft_unresolved_call(0x80064028u,4u,second,0x8008D4DCu,storage,0x8008D4FCu);break;
        case 4u:ob_draft_unresolved_call(0x80064028u,4u,second,0x8008D4DCu,storage,0x8008D4F0u);break;
        case 2u:case 5u:ob_draft_unresolved_call(0x80064028u,2u,second,0x8008D508u);break;
        default:break;
        }
    }
    uint32 result=ob_front_8009465C(second,51u,disabled?45u:91u,disabled?40u:15u,disabled?22u:8u,0u);
    if(!disabled){result=card_state==0xFFFFFFFFu?0x8009BDE8u:0x8009BE7Cu;w_u32(0x8009BB94u,result);}
    ob_draft_scratch_release(storage);return result;
}

uint32 ob_front_80096550(uint32 action,uint32 card,uint32 choice,uint32 mode)
{
    FUNCTION_MARKER(0x80096550u,"FRONT.BIN");
    if(action>=23u)return 0u;
    uint32 result=ob_front_80095DF0(card,action==0u?(mode==1u?2u:1u):0u,choice);
    if(action==0u){if(mode==1u){result=0x8009BF10u;w_u32(0x8009BB94u,result);}return result;}
    if(action==4u||action==14u)return result;
    if(action<=3u)
    {
        uint32 heading=action==1u?0x8008D58Cu:action==2u?0x8008D5A0u:0x8008D568u;
        uint32 interactive=action==2u||mode==1u;
        ob_front_8009465C(heading,100u,interactive?91u:45u,interactive?15u:40u,interactive?8u:22u,0u);
        uint32 yes=interactive&&!choice,no=interactive&&choice;
        ob_front_80094488(0x8008D584u,162u,125u,yes?91u:45u,yes?15u:40u,yes?8u:22u,0u);
        result=ob_front_80094488(0x8008D588u,202u,125u,no?91u:45u,no?15u:40u,no?8u:22u,0u);
        if(interactive)
        {
            if(action==1u)result=choice?0x8009C038u:0x8009C0CCu;
            else if(action==2u)result=choice?0x8009C160u:0x8009C1F4u;
            else result=choice?0x8009C288u:0x8009C31Cu;
            w_u32(0x8009BB94u,result);
        }
        return result;
    }
    static const uint32 messages[23]={0u,0u,0u,0u,0u,0x8008D5A8u,0x8008D5B4u,0x8008D5C0u,0x8008D5FCu,0x8008D5DCu,0x8008D608u,0x8008D614u,0x8008D624u,0x8008D634u,0u,0x8008D64Cu,0x8008D664u,0x8008D680u,0x8008D698u,0x8008D6ACu,0x8008D6C4u,0x8008D6D4u,0x8008D6E4u};
    return ob_front_8009465C(messages[action],112u,91u,15u,8u,0u);
}

uint32 ob_front_800994B0(uint32 player,uint32 unused_a1,uint32 locked,uint32 selected)
{
    FUNCTION_MARKER(0x800994B0u,"FRONT.BIN");
    uint32 text=ob_draft_scratch_acquire(8u),x=150u+player*40u;
    ob_draft_unresolved_call(0x80064028u,3u,text,0x8008D968u,player+1u);
    uint32 heading_selected=!locked&&selected==0xFFFFFFFFu;
    ob_front_80094488(text,x,42u,heading_selected?91u:45u,heading_selected?15u:40u,heading_selected?8u:22u,locked?1u:0u);
    for(uint32 i=0u;i<9u;++i)
    {
        uint32 active=!locked&&selected==i;
        ob_front_80093BB4(r_u32(0x8009CF58u+(player*9u+i)*4u),x,61u+i*16u,active,locked?1u:active&&r_u32(0x8009D028u+player*4u)==3u);
    }
    uint32 result=ob_front_80093E70(0x8009C4D8u);ob_draft_scratch_release(text);return result;
}

uint32 ob_front_8008F7F0(uint32 menu,uint32 item)
{
    FUNCTION_MARKER(0x8008F7F0u,"FRONT.BIN");
    static const uint32 selected_geometry[14][3]={
        {64u,169u,63u},{64u,201u,65u},{64u,233u,70u},{16u,201u,129u},{32u,158u,108u},
        {32u,138u,112u},{32u,140u,100u},{32u,144u,94u},{32u,174u,114u},{32u,152u,120u},
        {32u,158u,100u},{32u,134u,123u},{32u,140u,106u},{32u,144u,84u}};
    static const uint32 idle_geometry[9][2]={{136u,112u},{140u,100u},{140u,90u},{175u,115u},{150u,120u},{156u,100u},{134u,123u},{136u,106u},{146u,86u}};
    uint32 volume=r_u32(item+8u);
    if(r_u32(menu+12u)==item)
    {
        if(volume<10u)
            for(uint32 i=0u;i<5u+volume;++i)
                sub_80021460(0x8006B32Cu+i*4u,0u,0u,32u,selected_geometry[i][0],selected_geometry[i][1],selected_geometry[i][2],0u);
        return ob_front_8008E65C(20u,0x8008D100u,0x8008D104u);
    }
    if(volume>=10u)return 0u;
    /* The zero-volume jump leaves the original epilogue address in the return carrier */
    uint32 result=0x80091250u;
    for(uint32 i=0u;i<volume;++i)
        result=sub_80021460(0x8006B364u+i*4u,0u,0u,32u,32u,idle_geometry[i][0],idle_geometry[i][1],0u);
    return result;
}

