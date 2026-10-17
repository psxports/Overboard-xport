#include "psx.h"
#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800BD8E8(uint32 object, uint32 record, uint32 context)
{
  FUNCTION_MARKER(0x800BD8E8u,"GAME.BIN");
  uint32 result;
  uint32 properties;
  uint32 geometry;
  uint32 model;
  uint32 selector;

  uint32 object_type = r_u32(object + 292u);
  result = object_type - 2u < 254u ? 0x800BDCC4u : 0u;
  properties = r_u32(object + 112u);
  switch ( object_type )
  {
    case 2:
    case 3:
    case 4:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 36:
    case 37:
    case 39:
    case 40:
    case 41:
    case 156:
    case 159:
    case 162:
    case 163:
    case 165:
    case 174:
    case 235:
    case 238:
      ob_draft_unresolved_call(0x800AD4D0u,3u,object,properties,context);
      result = r_u32(object + 136u);
      if ( result )
      {
        uint32 details = ob_game_800901FC(r_u32(object + 292u),1u);
        uint32 shared = r_u8(details + 36u);
        geometry = r_u32(details);
        if ( (shared & 0x40u) != 0 )
        {
          w_u32(r_u32(object+136u)+44u,r_u32(object+44u));
          uint32 shape = ob_draft_unresolved_call(0x80043E3Cu,2u,r_u32(object+136u),0x80073638u);
          w_u32(r_u32(object+136u)+48u,shape);
          w_u32(r_u32(r_u32(object+136u)+48u)+52u,r_u32(object+44u));
          w_u32(r_u32(r_u32(object+136u)+48u)+48u,0x10000001u);
          result = r_u32(geometry+12u);
          w_u32(r_u32(r_u32(object+136u)+48u)+40u,result);
        }
        else if ( r_u32(geometry+8u) )
        {
          ob_draft_unresolved_call(0x800AD4D0u,3u,r_u32(object+136u),geometry,context);
          uint32 child = r_u32(object+136u);
          uint32 root = r_u32(child+48u);
          ob_resolve_shape_links(root);
          return root != 0u ? 0u : child;
        }
        else
        {
          return ob_draft_unresolved_call(0x800C05CCu,3u,r_u32(object+136u),r_u32(geometry+12u),context);
        }
      }
      return result;
    case 6:
    case 7:
    case 10:
    case 11:
    case 12:
    case 13:
    case 38:
    case 150:
    case 151:
    case 157:
    case 158:
    case 161:
    case 166:
    case 168:
    case 171:
    case 172:
    case 173:
    case 175:
    case 180:
    case 181:
    case 224:
    case 231:
    case 233:
    case 234:
    case 236:
    case 239:
    case 241:
    case 243:
    case 244:
    case 245:
    case 246:
    case 254:
      model = r_u32(properties+12u);
      return ob_game_800C0654(object,model,context);
    case 8:
      if ( r_u16(record+22u) == 53712 )
      {
        model = 0x80069898u;
        w_u32(object+332u,context+10000u);
      }
      else
      {
        w_u32(object+332u,context+60000u);
        model = r_u32(properties+12u);
      }
      return ob_game_800C0654(object,model,context);
    case 15:
    case 16:
    case 48:
    case 50:
    case 52:
    case 54:
    case 56:
    case 58:
    case 60:
    case 62:
    case 64:
    case 66:
    case 68:
    case 70:
    case 72:
    case 74:
    case 75:
    case 76:
    case 77:
      return ob_draft_unresolved_call(0x800A9204u,4u,object,properties,0u,context);
    case 49:
    case 51:
    case 53:
    case 55:
    case 57:
    case 59:
    case 61:
    case 63:
    case 65:
    case 67:
    case 69:
    case 71:
    case 73:
      
      w_u8(object+324u,r_u8(object+324u)|2u);
      return ob_draft_unresolved_call(0x800A9204u,4u,object,properties,1u,context);
    case 149:
    case 153:
      ob_draft_unresolved_call(0x800C07BCu,5u,object, 0, object, 0,context);
      ob_draft_unresolved_call(0x800C07BCu,5u,object, 1, r_u32(object+136u), object,context);
      ob_draft_unresolved_call(0x800C07BCu,5u,object, 2, r_u32(object+140u), r_u32(object+136u),context);
      return ob_draft_unresolved_call(0x800C07BCu,5u,object, 3, r_u32(object+144u), r_u32(object+140u),context);
    case 160:
      selector = r_u16(record+18u);
      if ( selector == 1 )
      {
        model = 0x80066618u;
        return ob_game_800C0654(object,model,context);
      }
      if ( selector < 2 )
      {
        model = 0x80066614u;
        return ob_game_800C0654(object,model,context);
      }
      result = 2;
      if ( selector != 2 )
        return result;
      model = 0x8006661Cu;
      return ob_game_800C0654(object,model,context);
    case 164:
    case 167:
    case 247:
    case 248:
    case 249:
      model = 0x800662CCu;
      return ob_game_800C0654(object,model,context);
    case 229:
    case 230:
      model = r_u32(0x800C53C4u+r_u32(r_u32(object+108u)+4u)*4u);
      return ob_game_800C0654(object,model,context);
    case 232:
      selector = r_u16(record+18u);
      result = 1;
      if ( selector )
      {
        if ( selector != 1 )
          return result;
        model = r_u32(properties+16u);
      }
      else
      {
        model = r_u32(properties+12u);
      }
      return ob_game_800C0654(object,model,context);
    case 237:
    case 240:
      selector = r_u16(record+18u);
      if ( selector == 1 )
      {
        model = r_u32(properties+12u);
      }
      else if ( selector >= 2 )
      {
        result = 2;
        if ( selector != 2 )
          return result;
        model = r_u32(properties+16u);
      }
      else
      {
        model = r_u32(properties+8u);
      }
      return ob_game_800C0654(object,model,context);
    case 242:
      model = 0x8006643Cu;
      return ob_game_800C0654(object,model,context);
    case 255:
      ob_draft_unresolved_call(0x800AD4D0u,3u,object,properties,context);
      ob_draft_unresolved_call(0x800C07BCu,5u,object, 1, r_u32(object+136u), object,context);
      return ob_draft_unresolved_call(0x800C07BCu,5u,object, 2, r_u32(object+140u), r_u32(object+136u),context);
    default:
      return result;
  }
}
