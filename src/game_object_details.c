#include "game_signatures.h"
#include "draft_signatures.h"
#include "native_runtime.h"

uint32 ob_game_800901FC(uint32 object_type, uint32 variant)
{
  FUNCTION_MARKER(0x800901FCu, "GAME.BIN");
  uint32 v3;
  uint32 v4;
  uint32 v5;
  uint32 v6;
  uint32 v7;
  uint32 v8;
  uint32 v9;
  uint32 v10;
  uint32 v11;
  uint32 v12;
  uint32 v13;
  uint32 v14;
  uint32 v15;
  uint32 v16;
  uint32 v17;
  uint32 v18;
  uint32 v19;
  uint32 v20;
  uint32 v21;
  uint32 v22;
  uint32 v23;
  uint32 v24;
  uint32 v25;
  uint32 v26;
  uint32 v27;
  uint32 v28;
  uint32 v29;
  uint32 v30;
  uint32 v31;
  uint32 v32;
  uint32 v33;
  uint32 v34;
  uint32 v35;

  switch ( object_type )
  {
    case 2:
      return 0x800C3AC4u;
    case 3:
      if ( !(uint16)variant )
        return 0x800C39FCu;
      v24 = variant << 16;
      if ( (sint16)variant == 1 )
        return 0x800C430Cu;
LABEL_77:
      v25 = ((sint32)v24 >> 16);
      if ( !(((sint32)v24 >> 16)) )
        return 0x800C3A24u;
      v26 = variant << 16;
      if ( v25 == 1 )
        return 0x800C430Cu;
LABEL_82:
      v27 = ((sint32)v26 >> 16);
      if ( !(((sint32)v26 >> 16)) )
        return 0x800C3A74u;
      v28 = variant << 16;
      if ( v27 == 1 )
        return 0x800C430Cu;
LABEL_87:
      v29 = ((sint32)v28 >> 16);
      if ( !(((sint32)v28 >> 16)) )
        return 0x800C3A4Cu;
      v30 = variant << 16;
      if ( v29 == 1 )
        return 0x800C430Cu;
LABEL_92:
      if ( !(((sint32)v30 >> 16)) )
        return 0x800C3A9Cu;
      if ( ((sint32)v30 >> 16) == 1 )
        return 0x800C430Cu;
      return 0x800C3AC4u;
    case 4:
      v28 = variant << 16;
      goto LABEL_87;
    case 6:
      return 0x800C3AECu;
    case 7:
      return 0x800C3BDCu;
    case 8:
      return 0x800C3B8Cu;
    case 10:
      if ( !(uint16)variant )
        return 0x800C3B14u;
      v31 = variant << 16;
      if ( (sint16)variant == 1 )
        return 0x800C430Cu;
LABEL_103:
      if ( !(((sint32)v31 >> 16)) )
        return 0x800C3B3Cu;
      if ( ((sint32)v31 >> 16) == 1 )
        return 0x800C430Cu;
      return 0x800C3B64u;
    case 11:
      return 0x800C39D4u;
    case 12:
      return 0x800C3BB4u;
    case 13:
      if ( !(uint16)variant )
        return 0x800C46CCu;
      if ( (sint16)variant == 1 )
        return 0x800C46F4u;
      return 0x800C462Cu;
    case 15:
      return 0x800C476Cu;
    case 16:
      return 0x800C4794u;
    case 20:
      if ( !(uint16)variant )
        return 0x800C37F4u;
      v3 = variant << 16;
      if ( (sint16)variant == 1 )
        return 0x800C4334u;
LABEL_16:
      v4 = ((sint32)v3 >> 16);
      if ( !(((sint32)v3 >> 16)) )
        return 0x800C381Cu;
      v5 = variant << 16;
      if ( v4 == 1 )
        return 0x800C4334u;
LABEL_21:
      v6 = ((sint32)v5 >> 16);
      if ( !(((sint32)v5 >> 16)) )
        return 0x800C3844u;
      v7 = variant << 16;
      if ( v6 == 1 )
        return 0x800C4334u;
LABEL_26:
      v8 = ((sint32)v7 >> 16);
      if ( !(((sint32)v7 >> 16)) )
        return 0x800C386Cu;
      v9 = variant << 16;
      if ( v8 == 1 )
        return 0x800C4334u;
LABEL_31:
      v10 = ((sint32)v9 >> 16);
      if ( !(((sint32)v9 >> 16)) )
        return 0x800C3894u;
      v11 = variant << 16;
      if ( v10 == 1 )
        return 0x800C4334u;
LABEL_36:
      v12 = ((sint32)v11 >> 16);
      if ( !(((sint32)v11 >> 16)) )
        return 0x800C38BCu;
      v13 = variant << 16;
      if ( v12 == 1 )
        return 0x800C4334u;
LABEL_41:
      v14 = ((sint32)v13 >> 16);
      if ( !(((sint32)v13 >> 16)) )
        return 0x800C38E4u;
      v15 = variant << 16;
      if ( v14 == 1 )
        return 0x800C4334u;
LABEL_46:
      v16 = ((sint32)v15 >> 16);
      if ( !(((sint32)v15 >> 16)) )
        return 0x800C390Cu;
      v17 = variant << 16;
      if ( v16 == 1 )
        return 0x800C4334u;
LABEL_51:
      v18 = ((sint32)v17 >> 16);
      if ( !(((sint32)v17 >> 16)) )
        return 0x800C3934u;
      v19 = variant << 16;
      if ( v18 == 1 )
        return 0x800C4334u;
LABEL_56:
      v20 = ((sint32)v19 >> 16);
      if ( !(((sint32)v19 >> 16)) )
        return 0x800C395Cu;
      v21 = variant << 16;
      if ( v20 == 1 )
        return 0x800C4334u;
LABEL_61:
      v22 = ((sint32)v21 >> 16);
      if ( !(((sint32)v21 >> 16)) )
        return 0x800C3984u;
      v23 = variant << 16;
      if ( v22 == 1 )
        return 0x800C4334u;
LABEL_66:
      if ( !(((sint32)v23 >> 16)) )
        return 0x800C39ACu;
      if ( ((sint32)v23 >> 16) == 1 )
        return 0x800C4334u;
      return 0x800C39D4u;
    case 21:
      v3 = variant << 16;
      goto LABEL_16;
    case 22:
      v5 = variant << 16;
      goto LABEL_21;
    case 23:
      v7 = variant << 16;
      goto LABEL_26;
    case 24:
      v9 = variant << 16;
      goto LABEL_31;
    case 25:
      v11 = variant << 16;
      goto LABEL_36;
    case 26:
      v13 = variant << 16;
      goto LABEL_41;
    case 27:
      v15 = variant << 16;
      goto LABEL_46;
    case 28:
      v17 = variant << 16;
      goto LABEL_51;
    case 29:
      v19 = variant << 16;
      goto LABEL_56;
    case 30:
      v21 = variant << 16;
      goto LABEL_61;
    case 31:
      v23 = variant << 16;
      goto LABEL_66;
    case 32:
      return 0x800C3CCCu;
    case 33:
      return 0x800C3C04u;
    case 36:
      return 0x800C3C2Cu;
    case 37:
      return 0x800C3CA4u;
    case 38:
      return 0x800C3CF4u;
    case 39:
      return 0x800C3D1Cu;
    case 40:
      return 0x800C3D44u;
    case 41:
      if ( !(uint16)variant )
        return 0x800C3C54u;
      if ( (sint16)variant == 1 )
        return 0x800C3C7Cu;
      return 0x800C3CA4u;
    case 48:
    case 49:
      return 0x800C3D6Cu;
    case 50:
    case 51:
      return 0x800C3D94u;
    case 52:
    case 53:
      return 0x800C3DBCu;
    case 54:
    case 55:
      return 0x800C3DE4u;
    case 56:
    case 57:
      return 0x800C3E0Cu;
    case 58:
    case 59:
      return 0x800C3E34u;
    case 60:
    case 61:
      return 0x800C3E5Cu;
    case 62:
    case 63:
      return 0x800C3E84u;
    case 64:
    case 65:
      return 0x800C3EACu;
    case 66:
    case 67:
    case 68:
    case 69:
      return 0x800C3ED4u;
    case 70:
    case 71:
      return 0x800C3EFCu;
    case 72:
    case 73:
      return 0x800C3F24u;
    case 74:
      return 0x800C3F4Cu;
    case 75:
      return 0x800C3F74u;
    case 76:
      return 0x800C3F9Cu;
    case 77:
      return 0x800C3FC4u;
    case 149:
      if ( (sint16)variant == 1 )
        return 0x800C417Cu;
      if ( (sint16)variant >= 2 )
      {
        if ( (sint16)variant == 2 )
          return 0x800C41A4u;
        v32 = variant << 16;
        if ( (sint16)variant == 3 )
          return 0x800C41CCu;
      }
      else
      {
        v32 = variant << 16;
        if ( !(uint16)variant )
          return 0x800C4154u;
      }
LABEL_177:
      v33 = ((sint32)v32 >> 16);
      v34 = ((sint32)v32 >> 16) == 1;
      v35 = ((sint32)v32 >> 16) < 2;
      if ( v34 )
        return 0x800C421Cu;
      if ( v35 )
      {
        if ( !v33 )
          return 0x800C41F4u;
      }
      else
      {
        if ( v33 == 2 )
          return 0x800C4244u;
        if ( v33 == 3 )
          return 0x800C426Cu;
      }
      return 0x800C44C4u;
    case 150:
      v24 = variant << 16;
      goto LABEL_77;
    case 151:
      v26 = variant << 16;
      goto LABEL_82;
    case 153:
      v32 = variant << 16;
      goto LABEL_177;
    case 156:
      v30 = variant << 16;
      goto LABEL_92;
    case 157:
      return 0x800C4064u;
    case 158:
      return 0x800C408Cu;
    case 159:
      if ( !(uint16)variant )
        return 0x800C4384u;
      if ( (sint16)variant == 1 )
        return 0x800C43ACu;
      return 0x800C4424u;
    case 160:
    case 247:
      return 0x800C4564u;
    case 161:
    case 168:
      return 0x800C453Cu;
    case 162:
      return 0x800C4104u;
    case 163:
      return 0x800C412Cu;
    case 164:
      return 0x800C4654u;
    case 165:
      return 0x800C4514u;
    case 166:
      return 0x800C46A4u;
    case 167:
      return 0x800C467Cu;
    case 171:
      return 0x800C462Cu;
    case 172:
      return 0x800C40B4u;
    case 173:
      return 0x800C40DCu;
    case 174:
      if ( !(uint16)variant )
        return 0x800C471Cu;
      if ( (sint16)variant == 1 )
        return 0x800C4744u;
LABEL_217:
      {
        uint32 text = ob_draft_scratch_acquire(56u);
        ob_draft_unresolved_call(0x80064028u, 3u, text, 0x8008D01Cu, object_type);
        ob_draft_scratch_release(text);
        return 0u;
      }
    case 175:
      return 0x800C42BCu;
    case 180:
      v31 = variant << 16;
      goto LABEL_103;
    case 181:
      return 0x800C3B64u;
    case 224:
      if ( !(uint16)variant )
        return 0x800C4014u;
      if ( (sint16)variant == 1 )
        return 0x800C403Cu;
      return 0x800C4064u;
    case 229:
    case 230:
      return 0x800C4604u;
    case 231:
      return 0x800C4294u;
    case 232:
      return 0x800C42E4u;
    case 233:
      return 0x800C430Cu;
    case 234:
      return 0x800C4424u;
    case 235:
      return 0x800C43D4u;
    case 236:
      return 0x800C43FCu;
    case 237:
      return 0x800C4474u;
    case 238:
      return 0x800C44C4u;
    case 239:
      return 0x800C44ECu;
    case 240:
      return 0x800C449Cu;
    case 241:
      return 0x800C3FECu;
    case 242:
      return 0x800C458Cu;
    case 243:
    case 244:
    case 245:
    case 246:
      if ( !(uint16)variant )
        return 0x800C45B4u;
      if ( (sint16)variant == 1 )
        return 0x800C45DCu;
      return 0x800C4564u;
    case 248:
    case 249:
      return 0x800C37CCu;
    case 254:
      return 0x800C444Cu;
    case 255:
      if ( (sint16)variant == 1 )
        return 0x800C435Cu;
      if ( (sint16)variant < 2 )
      {
        if ( !(uint16)variant )
          return 0x800C377Cu;
        return 0x800C37CCu;
      }
      if ( (sint16)variant != 2 )
        return 0x800C37CCu;
      return 0x800C4334u;
    default:
      goto LABEL_217;
  }
}
