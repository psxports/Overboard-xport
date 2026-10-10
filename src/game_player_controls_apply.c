#include "psx.h"
#include "draft_signatures.h"
#include "game_signatures.h"

/* TODO Conditional GAME callees retain literal fail-fast bridges pending native bodies */
uint32 ob_game_800B07E4(uint32 object, uint32 input_word, uint32 time)
{
    FUNCTION_MARKER(0x800b07e4u, "GAME.BIN");
    uint32 attributes = ob_draft_scratch_acquire(88u);
  sint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 result;
  sint32 v11;
  sint32 v12;
  sint32 v13;
  uint32 v14;
  sint32 v15;
  sint32 v16;
  uint32 v17;
  sint32 v18;
  sint32 v19;
  sint32 v20;
  sint32 v21;
  uint32 v22;
  sint32 v23;
  uint16 v24;
  sint32 v25;
  sint32 v26;
  sint32 v27;
  sint32 v28;
  uint32 v29;
  sint32 v30;
  uint32 v31;
  sint32 v32;
  sint16 v33;
  uint32 v34;
  sint32 v35;
  sint32 v36;
  sint32 v37;
  sint16 v38;
  sint32 v39;
  sint32 v40;
  sint32 v41;
  sint16 v42;
  sint32 v43;
  sint32 v44;
  sint16 v45;
  uint32 v46;
  sint16 v47;
  sint32 v48;
  sint32 v49;
  sint32 v50;
  sint32 v51;
  sint32 v52;
  sint16 v53;
  sint32 v54;
  sint16 v55;
  sint32 v56;
  sint32 v57;
  sint32 v58;
  sint32 v59;
  sint16 v60;
  uint32 v61;
  sint32 v62;
  sint32 v63;
  sint32 v64;
  sint16 v65;
  uint32 v66;
  sint32 v67;
  sint32 v68;
  sint8 v69;
  sint32 v70;
  sint32 v71;
  sint32 v72;
  sint32 v73;
  sint32 v74;
  sint32 v75;
  sint32 v76;
  sint32 v77;
  sint32 v78;
  sint32 v79;
  sint32 v80;
  sint32 v81;
  sint32 v82;
  sint32 v83;
  sint32 v84;
  sint32 v85;
  sint32 v86;
  sint32 v87;
  sint32 v88;
  sint32 v89;
  sint32 v90;
  sint32 v91;
  sint32 v92;
  sint32 v93;
  sint32 v94;
  sint32 v95;
  sint32 v96;
  uint32 v97;
  sint32 v98;
  sint32 v99;
  sint32 v100;
  sint32 v101;

  sint32 v103;
  sint32 v104;
  sint32 v105;
  uint32 secondary_sound_animation;
  v6 = 0;
  v7 = 0;
  v8 = r_u32((uint32)(((uint32)(object) + (uint32)(112))));
  v9 = 0;
  if ((r_u8(0x8006C230) == 1))
    ob_draft_unresolved_call(0x800a3134u, 2u, object, time);
  result = r_u32((uint32)(((uint32)(object) + (uint32)(28))));
  v105 = r_u32((uint32)(((uint32)(object) + (uint32)(108))));
  v11 = ((uint32)(time) - (uint32)(result));
  v103 = r_u32((uint32)(v8));
  if ((time != (uint32)result))
  {
    if (!(sint16)r_u16((0x800cba46u + ((sint32)((uint32)(52) * (uint32)((sint16)r_u16((uint32)(((uint32)(object) + (uint32)(326))))))) * 2u)))
    {
      v12 = r_u32((uint32)(((uint32)(object) + (uint32)(288))));
      if ((((v12 != 3) && (v12 != 22)) && (v12 != 20)))
      {
        w_u16((uint32)((sint32)((uint32)(v105) + (uint32)(28))), ob_draft_unresolved_call(0x8001afc8u, 0u));
        w_u16((uint32)((sint32)((uint32)(v105) + (uint32)(30))), ((uint32)((ob_draft_unresolved_call(0x8001afc8u, 0u) & 0x1FFF)) + (uint32)(4096)));
        ob_draft_unresolved_call(0x800b3210u, 2u, object, time);
      }
    }
    v13 = (sint16)r_u16((uint32)(((uint32)(object) + (uint32)(306))));
    if (((sint32)(v13) < (sint32)(0)))
    {
      v19 = r_u32(r_u32((uint32)(((uint32)(object) + (uint32)(124)))));
      v17 = ((sint32)(v19) < (sint32)(1001));
      v20 = ((sint32)(v19) >> 7);
      if (v17)
      {
        v21 = ((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(316))))) - (uint32)(v11));
        w_u32((uint32)(((uint32)(object) + (uint32)(316))), v21);
        if (((sint32)(v21) < (sint32)(0)))
        {
          sub_80011984((sint32)(0u - (uint32)(2147061468)), 32, 15, 15, 256, 0, 0);
          w_u32((uint32)(((uint32)(object) + (uint32)(316))), ((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(316))))) + (uint32)(2500)));
        }
      }
      else
      {
        w_u16((uint32)(((uint32)(object) + (uint32)(306))), ob_draft_unresolved_call(0x80011a24u, 6u, (sint32)(0u - (uint32)(2147061464)), v20, 256, r_u32((uint32)(((uint32)(object) + (uint32)(44)))), time, 1));
        w_u32((uint32)((sint32)((uint32)(v105) + (uint32)(100))), (sint32)(0u - (uint32)(2147061464)));
      }
    }
    else
    {
      v14 = r_u32((uint32)(((uint32)(object) + (uint32)(128))));
      if (v14)
      {
        ob_draft_unresolved_call(0x80011e20u, 4u, v13, r_u32((uint32)(((uint32)(object) + (uint32)(44)))), (uint8)(((sint32)((sint32)(((uint32)(((uint32)(r_u32((uint32)(v14))) - (uint32)(time))) << (uint32)(7)))) / (sint32)(32000))), time);
        goto LABEL_22;
      }
      v15 = 128;
      if ((r_u32((uint32)((sint32)((uint32)(v105) + (uint32)(100)))) == (sint32)(0u - (uint32)(2147061464))))
      {
        v16 = r_u32(r_u32((uint32)(((uint32)(object) + (uint32)(124)))));
        v17 = ((sint32)(v16) < (sint32)(1001));
        v15 = ((sint32)(v16) >> 7);
        if (v17)
        {
          /* TODO Recover original conditional ownership mask carrier for 1195C */
          ob_draft_unresolved_call(0x8001195cu, 1u, v13);
          w_u16((uint32)(((uint32)(object) + (uint32)(306))), (sint32)(0u - (uint32)(1)));
          goto LABEL_22;
        }
        v18 = r_u32((uint32)(((uint32)(object) + (uint32)(44))));
      }
      else
      {
        v18 = r_u32((uint32)(((uint32)(object) + (uint32)(44))));
      }
      ob_draft_unresolved_call(0x80011e20u, 4u, v13, v18, v15, time);
    }
    LABEL_22:
    w_u32(0x800c8340u, input_word);

    v22 = input_word;
    if ((object == r_u32(0x800d5c8cu)))
      ob_game_80093E08(time);
    sub_800454BC(r_u32((uint32)(((uint32)(object) + (uint32)(44)))));
    v23 = r_u32((uint32)(((uint32)(object) + (uint32)(108))));
    v24 = sub_8002B868(((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(v23) + (uint32)(52))))) * (uint32)(r_u32((uint32)((sint32)((uint32)(v23) + (uint32)(52))))))) + (uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(v23) + (uint32)(60))))) * (uint32)(r_u32((uint32)((sint32)((uint32)(v23) + (uint32)(60)))))))));
    v25 = r_u32((uint32)(((uint32)(object) + (uint32)(124))));
    v17 = ((sint32)time < r_s32((uint32)((sint32)((uint32)(v25) + (uint32)(8)))));
    v104 = v24;
    if (v17)
    {
      LABEL_94:
      v53 = sub_80027F98(r_u32((uint32)((sint32)((uint32)(v23) + (uint32)(60)))), r_u32((uint32)((sint32)((uint32)(v23) + (uint32)(52)))));

      v54 = r_u32((uint32)((sint32)((uint32)(v23) + (uint32)(180))));
      v55 = v53;
      if (v54 != 0 && (sint32)(time - (uint32)v54) >= 101)
      {
        w_u32((uint32)((sint32)((uint32)(v105) + (uint32)(180))), 0);
        sub_8004651C(r_u32((uint32)(((uint32)(object) + (uint32)(52)))));
        ob_game_800BE604(object, (attributes), time);
      }
      v56 = v105;
      if ((!(r_u16((uint32)((sint32)((uint32)(v105) + (uint32)(120))))) && (r_s32((uint32)((sint32)((uint32)(v23) + (uint32)(184)))) < (sint32)time)))
      {
        (w_u16((uint32)((sint32)((uint32)(v105) + (uint32)(120))), (r_u16((uint32)((sint32)((uint32)(v105) + (uint32)(120)))) + 1u)), r_u16((uint32)((sint32)((uint32)(v105) + (uint32)(120)))));
        v56 = v105;
      }
      if ((!(r_u16((uint32)((sint32)((uint32)(v56) + (uint32)(122))))) && (r_s32((uint32)((sint32)((uint32)(v23) + (uint32)(188)))) < (sint32)time)))
        (w_u16((uint32)((sint32)((uint32)(v56) + (uint32)(122))), (r_u16((uint32)((sint32)((uint32)(v56) + (uint32)(122)))) + 1u)), r_u16((uint32)((sint32)((uint32)(v56) + (uint32)(122)))));
      v57 = (v22 & 0x200);
      if (((v22 & 0x80) != 0))
      {
        v58 = 0;
        v59 = (sint8)r_u8((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(135))));
        do
        {
          if (((sint8)r_u8((uint32)((sint32)((uint32)(v23) + (uint32)(177)))) != (sint8)r_u8((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(135))))))
            break;
          v59 = (sint16)r_u16((0x800c5aa0u + (v59) * 2u));
          if ((r_u8((uint32)((sint32)((uint32)((sint32)((uint32)(v23) + (uint32)(v59))) + (uint32)(106)))) && ((sint32)((sint32)((uint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)((sint8)r_u8((0x800c5eedu + ((sint32)((uint32)(4) * (uint32)(v59))) * 1u))))) + (uint32)(v23))) + (uint32)(120))))) - (uint32)((sint16)r_u16((0x800c5b64u + ((sint32)((uint32)((sint32)((uint32)(35) * (uint32)(v59))) + (uint32)((sint32)((uint32)(7) * (uint32)((sint8)r_u8((uint32)((sint32)((uint32)((sint32)((uint32)(v23) + (uint32)(v59))) + (uint32)(130))))))))) * 2u))))) >= (sint32)(0))))
          {
            v60 = r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(152))));
            w_u8((uint32)((sint32)((uint32)(v23) + (uint32)(177))), v59);
            v61 = ((0x800c5a80u + ((sint8)r_u8((uint32)((sint32)((uint32)(v23) + (uint32)(177))))) * 2u));
            w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(152))), (sint32)((uint32)(v60) - (uint32)(2)));
            w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(154))), (sint16)r_u16(v61));
          }
          ++v58;
        }
        while (((sint32)(v58) < (sint32)(8)));
        v57 = (v22 & 0x200);
      }
      v17 = (v57 == 0);
      v62 = (v22 & 0x1000);
      if (!v17)
      {
        v63 = 0;
        v64 = (sint8)r_u8((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(135))));
        do
        {
          if (((sint8)r_u8((uint32)((sint32)((uint32)(v23) + (uint32)(177)))) != (sint8)r_u8((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(135))))))
            break;
          v64 = (sint16)r_u16((0x800c5a90u + (v64) * 2u));
          if ((r_u8((uint32)((sint32)((uint32)((sint32)((uint32)(v23) + (uint32)(v64))) + (uint32)(106)))) && ((sint32)((sint32)((uint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)((sint8)r_u8((0x800c5eedu + ((sint32)((uint32)(4) * (uint32)(v64))) * 1u))))) + (uint32)(v23))) + (uint32)(120))))) - (uint32)((sint16)r_u16((0x800c5b64u + ((sint32)((uint32)((sint32)((uint32)(35) * (uint32)(v64))) + (uint32)((sint32)((uint32)(7) * (uint32)((sint8)r_u8((uint32)((sint32)((uint32)((sint32)((uint32)(v23) + (uint32)(v64))) + (uint32)(130))))))))) * 2u))))) >= (sint32)(0))))
          {
            v65 = r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(152))));
            w_u8((uint32)((sint32)((uint32)(v23) + (uint32)(177))), v64);
            v66 = ((0x800c5a80u + ((sint8)r_u8((uint32)((sint32)((uint32)(v23) + (uint32)(177))))) * 2u));
            w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(152))), (sint32)((uint32)(v65) + (uint32)(2)));
            w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(154))), (sint16)r_u16(v66));
          }
          ++v63;
        }
        while (((sint32)(v63) < (sint32)(8)));
        v62 = (v22 & 0x1000);
      }
      if (v62)
      {
        v67 = ((v22 >> 2) & 1);
        if (((v22 & 2) != 0))
          v67 |= 2u;
        if (((v22 & 8) != 0))
          v67 |= 4u;
        if (((v22 & 1) != 0))
          v67 |= 8u;
        v68 = (sint8)r_u8((uint32)((sint32)((uint32)(v23) + (uint32)(177))));
        switch (v67)
        {
          case 1:
            w_u8((uint32)((sint32)((uint32)(v23) + (uint32)(177))), 0);
            break;

          case 2:
            v69 = 2;
            goto LABEL_135;

          case 3:
            v69 = 7;
            goto LABEL_135;

          case 4:
            v69 = 1;
            goto LABEL_135;

          case 6:
            v69 = 4;
            goto LABEL_135;

          case 8:
            v69 = 3;
            goto LABEL_135;

          case 9:
            v69 = 5;
            goto LABEL_135;

          case 12:
            v69 = 6;
            LABEL_135:
          w_u8((uint32)((sint32)((uint32)(v23) + (uint32)(177))), v69);

            break;

          default:
            break;

        }

        v70 = (sint8)r_u8((uint32)((sint32)((uint32)(v23) + (uint32)(177))));
        v71 = (sint32)((uint32)(v23) + (uint32)(v70));
        if ((v70 != v68))
        {
          if ((r_u8((uint32)((sint32)((uint32)(v71) + (uint32)(106)))) && ((sint32)((sint32)((uint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)((sint8)r_u8((0x800c5eedu + ((sint32)((uint32)(4) * (uint32)(v70))) * 1u))))) + (uint32)(v23))) + (uint32)(120))))) - (uint32)((sint16)r_u16((0x800c5b64u + ((sint32)((uint32)((sint32)((uint32)(35) * (uint32)(v70))) + (uint32)((sint32)((uint32)(7) * (uint32)((sint8)r_u8((uint32)((sint32)((uint32)(v71) + (uint32)(130))))))))) * 2u))))) >= (sint32)(0))))
          {
            w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(154))), (sint16)r_u16((0x800c5a80u + (v70) * 2u)));
          }
          else
          {
            w_u8((uint32)((sint32)((uint32)(v23) + (uint32)(177))), v68);
          }
        }
      }
      else
      {
        v72 = r_u32((uint32)(((uint32)(object) + (uint32)(120))));
        if (((sint8)r_u8((uint32)((sint32)((uint32)(v72) + (uint32)(135)))) != (sint8)r_u8((uint32)((sint32)((uint32)(v23) + (uint32)(177))))))
        {
          w_u8((uint32)((sint32)((uint32)(v72) + (uint32)(135))), r_u8((uint32)((sint32)((uint32)(v23) + (uint32)(177)))));
          ob_game_800B7C7C(r_u32((uint32)(((uint32)(object) + (uint32)(120)))), (sint8)r_u8((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(135)))), (sint8)r_u8((uint32)((sint32)((uint32)((sint32)((uint32)(v23) + (uint32)((sint8)r_u8((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(135))))))) + (uint32)(130)))));
        }
      }
      v73 = r_u32((uint32)(((uint32)(object) + (uint32)(56))));
      if (((((r_s32((uint32)((sint32)((uint32)(v73) + (uint32)(208)))) & 8) == 0) && ((sint32)time >= r_s32((uint32)(((uint32)(r_s32((uint32)(((uint32)(object) + (uint32)(124))))) + (uint32)(8)))))) && r_u8(0x800771B4)))
        sub_8004F2C4(v73, 1);
      if (r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(172)))))
      {
        LABEL_212:
        v92 = (v22 & 0x30);

        if ((r_u8((uint32)((sint32)((uint32)(v23) + (uint32)(47)))) == 4))
        {
          if (v6)
            w_u32((uint32)((sint32)((uint32)(v23) + (uint32)(36))), 1);
          v92 = (v22 & 0x30);
        }
        if (!v92)
        {
          v93 = r_u32((uint32)((sint32)((uint32)(v23) + (uint32)(160))));
          if (v93)
          {
            v94 = r_u32((uint32)(((uint32)(object) + (uint32)(120))));
            v95 = r_u8((uint32)((sint32)((uint32)(v94) + (uint32)(135))));
            if (((uint32)((sint32)((uint32)(v95) - (uint32)(6))) >= 2))
            {
              if (((sint8)(v95) != 5))
                goto LABEL_224;
              if ((v93 != 2))
              {
                ob_draft_unresolved_call(0x800b5bd8u, 4u, 0, v94, r_u8((uint32)((sint32)((uint32)(v8) + (uint32)(40)))), time);
                w_u16((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(130))), ((uint32)(r_u16((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(130))))) | (uint32)(0x4000u)));
                ob_game_800B5CB4( object, 3, 0, time);
                w_u16((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(130))), ((uint32)(r_u16((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(130))))) & (uint32)(~0x4000u)));
              }
            }
            else
            {
              ob_draft_unresolved_call(0x8001195cu, 2u, (sint16)r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(104)))), (uint32)v94);
              w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(104))), (sint32)(0u - (uint32)(1)));
            }
            w_u32((uint32)((sint32)((uint32)(v23) + (uint32)(160))), 0);
          }
        }
        LABEL_224:
        v96 = r_u32((uint32)(((uint32)(object) + (uint32)(120))));

        if (((sint32)((sint16)r_u16((uint32)((sint32)((uint32)(v96) + (uint32)(132))))) > (sint32)(0)))
          (w_u16((uint32)((sint32)((uint32)(v96) + (uint32)(132))), (r_u16((uint32)((sint32)((uint32)(v96) + (uint32)(132)))) - 1u)), r_u16((uint32)((sint32)((uint32)(v96) + (uint32)(132)))));
        v97 = r_u32((uint32)(((uint32)(object) + (uint32)(128))));
        v98 = object;
        if (!v97)
          goto LABEL_242;
        if (((r_s32((v97 + (1) * 4u)) < (sint32)time) && !(r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(172)))))))
        {
          v99 = (sint32)(r_u32(v97) - time) >> 7;
          if (((sint32)(v99) < (sint32)(150)))
          v99 = (sint32)(r_u32(v97) - time) >> 7;
          ob_draft_unresolved_call(0x800b8818u, 4u, r_u32((uint32)(((uint32)(object) + (uint32)(44)))), v99, 4000, time);
          w_u32(r_u32(object + 128u) + 4u, time + (uint32)((sint32)(20000u - (uint32)((sint32)(r_u32(r_u32(object + 128u)) - time) / 2)) >> 8));
        }
        if ((r_s32((uint32)(((uint32)(r_s32((uint32)(((uint32)(object) + (uint32)(128))))) + (uint32)(8)))) < (sint32)time))
        {
          if (r_u8(0x8008AE6A))
          {
            LABEL_240:
            v98 = object;

            if ((r_s32(r_s32((uint32)(((uint32)(object) + (uint32)(128))))) < (sint32)time))
            {
              ob_draft_unresolved_call(0x8009a704u, 1u, object);
              v98 = object;
            }
            LABEL_242:
            ob_game_800B4874(v98, time);

            result = ((sint32)(v104) < (sint32)(401));
            if (((sint32)(v104) >= (sint32)(401)))
            {
              result = (r_s32((uint32)((sint32)((uint32)(v23) + (uint32)(64)))) < (sint32)time);
              if ((r_s32((uint32)((sint32)((uint32)(v23) + (uint32)(64)))) < (sint32)time))
              {
                result = (sint8)r_u8((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(60))))) + (uint32)(52))));
                if (!(r_u8((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(60))))) + (uint32)(52))))))
                {
                  result = 1374355456;
                  if (((sint32)((sint32)r_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(44))))) + (uint32)(84))))) <= (sint32)(0)))
                  {
                    ob_draft_unresolved_call(0x800b8a58u, 6u, r_u32((uint32)(((uint32)(object) + (uint32)(44)))), (sint32)((uint32)(((sint32)(v104) / (sint32)(50))) + (uint32)(180)), v55, (sint16)r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(48)))), 800, time);
                    v101 = (sint16)r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(80))));
                    if (((sint32)(v101) < (sint32)(0)))
                      v101 = (sint32)(0u - (uint32)(v101));
                    result = ((uint32)(((uint32)(((uint32)(time) + (uint32)(((sint32)((sint32)(0u - (uint32)(v101))) / (sint32)(300))))) + (uint32)(40))) + (uint32)(((sint32)((sint32)((uint32)(6800) - (uint32)(v104))) / (sint32)(120))));
                    w_u32((uint32)((sint32)((uint32)(v23) + (uint32)(64))), result);
                  }
                }
              }
            }
            w_u32((uint32)(((uint32)(object) + (uint32)(28))), time);
            { uint32 draft_return = result; ob_draft_scratch_release(attributes);  return draft_return; }
          }
          w_u8((0x800cba3au + ((sint32)((uint32)(104) * (uint32)((sint16)r_u16((uint32)(((uint32)(object) + (uint32)(326))))))) * 1u), 17);
          ob_draft_unresolved_call(0x800a6c34u, 3u, object, 17, time);
          w_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(128))))) + (uint32)(8))), ((uint32)(time) + (uint32)(5000)));
          ob_draft_unresolved_call(0x800a52c4u, 3u, object, 15, (sint32)(0u - (uint32)(1)));
          ob_draft_unresolved_call(0x80011a24u, 6u, (sint32)(0u - (uint32)(2147065668)), 128, 256, r_u32((uint32)(((uint32)(object) + (uint32)(44)))), time, 0);
        }
        if (!r_u8(0x8008AE6A))
        {
          if (ob_draft_unresolved_call(0x800a52c4u, 3u, object, 150, time))
          {
            v100 = r_u32((uint32)(((uint32)(object) + (uint32)(288))));
            if (((v100 != 3) && (v100 != 20)))
              ob_draft_unresolved_call(0x800b3210u, 2u, object, time);
          }
        }
        goto LABEL_240;
      }
      if (((v22 & 0x10) != 0))
      {
        v17 = (ob_draft_unresolved_call(0x800b5c50u, 3u, 0, r_u32((uint32)(((uint32)(object) + (uint32)(120)))), time) == 0);
        v74 = (v22 & 0x20);
        if (v17)
        {
          LABEL_178:
          if (v74)
          {
            v85 = r_u32((uint32)(((uint32)(object) + (uint32)(120))));
            if (((sint32)((sint8)r_u8((uint32)((sint32)((uint32)((sint32)((uint32)(v105) + (uint32)((sint8)r_u8((uint32)((sint32)((uint32)(v85) + (uint32)(135))))))) + (uint32)(106))))) > (sint32)(0)))
            {
              switch (r_u8((uint32)((sint32)((uint32)(v85) + (uint32)(135)))))
              {
                case 0:
                  if (ob_draft_unresolved_call(0x800b5c50u, 3u, 0, r_u32((uint32)(((uint32)(object) + (uint32)(120)))), time))
                {
                  v6 = 1;
                  ob_draft_unresolved_call(0x800b5bd8u, 4u, 0, r_u32((uint32)(((uint32)(object) + (uint32)(120)))), 1, time);
                  v87 = object;
                  v88 = 2;
                  goto LABEL_211;
                }
                  break;

                case 1:
                  v86 = 0;
                  if (ob_draft_unresolved_call(0x800b5c50u, 3u, 1, r_u32((uint32)(((uint32)(object) + (uint32)(120)))), time))
                {
                  v6 = 1;
                  w_u8((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(113))), 0);
                  do
                  {
                    ob_draft_unresolved_call(0x800b5bd8u, 4u, 1, r_u32((uint32)(((uint32)(object) + (uint32)(120)))), r_u8((uint32)((sint32)((uint32)(v8) + (uint32)(41)))), time);
                    ob_game_800B5CB4( object, 1, 0, time);
                    ++v86;
                  }
                  while (((sint32)((sint16)(v86)) < (sint32)(4)));
                }
                  break;

                case 2:

                case 4:
                  if (ob_draft_unresolved_call(0x800b5c50u, 3u, 0, r_u32((uint32)(((uint32)(object) + (uint32)(120)))), time))
                {
                  v6 = 1;
                  ob_draft_unresolved_call(0x800b5bd8u, 4u, 0, r_u32((uint32)(((uint32)(object) + (uint32)(120)))), r_u8((uint32)((sint32)((uint32)(v8) + (uint32)(40)))), time);
                  v87 = object;
                  v88 = 3;
                  goto LABEL_211;
                }
                  break;

                case 3:
                  if (ob_draft_unresolved_call(0x800b5c50u, 3u, 0, r_u32((uint32)(((uint32)(object) + (uint32)(120)))), time))
                {
                  v6 = 1;
                  ob_draft_unresolved_call(0x800b5bd8u, 4u, 0, r_u32((uint32)(((uint32)(object) + (uint32)(120)))), r_u8((uint32)((sint32)((uint32)(v8) + (uint32)(40)))), time);
                  v87 = object;
                  v88 = 4;
                  goto LABEL_211;
                }
                  break;

                case 5:
                  if (ob_draft_unresolved_call(0x800b5c50u, 3u, 0, r_u32((uint32)(((uint32)(object) + (uint32)(120)))), time))
                {
                  v89 = r_u32((uint32)((sint32)((uint32)(v23) + (uint32)(160))));
                  if ((v89 != 2))
                  {
                    v90 = r_u32((uint32)(((uint32)(object) + (uint32)(120))));
                    v91 = (sint16)r_u16((uint32)((sint32)((uint32)(v90) + (uint32)(132))));
                    if (((sint32)(v91) >= (sint32)((sint32)((uint32)((sint16)r_u16((uint32)((sint32)((uint32)(v90) + (uint32)(130))))) << (uint32)(6)))))
                    {
                      if ((v89 == 1))
                      {
                        ob_draft_unresolved_call(0x800b5bd8u, 4u, 0, v90, r_u8((uint32)((sint32)((uint32)(v8) + (uint32)(40)))), time);
                        w_u16((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(130))), ((uint32)(r_u16((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(130))))) | (uint32)(0x4000u)));
                        ob_game_800B5CB4( object, 3, 0, time);
                        v6 = 1;
                        w_u16((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(130))), ((uint32)(r_u16((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(130))))) & (uint32)(~0x4000u)));
                        w_u32((uint32)((sint32)((uint32)(v23) + (uint32)(160))), 2);
                      }
                    }
                    else
                    {
                      w_u16((uint32)((sint32)((uint32)(v90) + (uint32)(132))), (sint32)((uint32)(v91) + (uint32)(64)));
                      v6 = 1;
                      ob_draft_unresolved_call(0x800b5bd8u, 4u, 0, r_u32((uint32)(((uint32)(object) + (uint32)(120)))), r_u8((uint32)((sint32)((uint32)(v8) + (uint32)(40)))), time);
                      ob_game_800B5CB4( object, 3, 0, time);
                      w_u32((uint32)((sint32)((uint32)(v23) + (uint32)(160))), 1);
                    }
                  }
                }
                  break;

                case 6:
                  secondary_sound_animation = r_u32(object + 120u);
                  if (ob_draft_unresolved_call(0x800b5c50u, 3u, 0, secondary_sound_animation, time))
                {
                  if (!(r_u32((uint32)((sint32)((uint32)(v23) + (uint32)(160))))))
                  {
                    if (((sint32)((sint16)r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(104))))) >= (sint32)(0)))
                      ob_draft_unresolved_call(0x8001195cu, 2u, (sint16)r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(104)))), secondary_sound_animation);
                    w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(104))), ob_draft_unresolved_call(0x80011a24u, 6u, (sint32)(0u - (uint32)(2147061164)), 255, 256, r_u32((uint32)(((uint32)(object) + (uint32)(44)))), time, 1));
                    ob_draft_unresolved_call(0x80011a24u, 6u, (sint32)(0u - (uint32)(2147061160)), 128, 256, r_u32((uint32)(((uint32)(object) + (uint32)(44)))), time, 0);
                  }
                  w_u32((uint32)((sint32)((uint32)(v23) + (uint32)(160))), 1);
                  v6 = 1;
                  ob_draft_unresolved_call(0x800b5bd8u, 4u, 0, r_u32((uint32)(((uint32)(object) + (uint32)(120)))), r_u8((uint32)((sint32)((uint32)(v8) + (uint32)(40)))), time);
                  v87 = object;
                  v88 = 4;
                  goto LABEL_211;
                }
                  break;

                case 7:
                  secondary_sound_animation = r_u32(object + 120u);
                  if (ob_draft_unresolved_call(0x800b5c50u, 3u, 1, secondary_sound_animation, time))
                {
                  if (!(r_u32((uint32)((sint32)((uint32)(v23) + (uint32)(160))))))
                  {
                    if (((sint32)((sint16)r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(104))))) >= (sint32)(0)))
                      ob_draft_unresolved_call(0x8001195cu, 2u, (sint16)r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(104)))), secondary_sound_animation);
                    w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(104))), ob_draft_unresolved_call(0x80011a24u, 6u, (sint32)(0u - (uint32)(2147061156)), 255, 256, r_u32((uint32)(((uint32)(object) + (uint32)(44)))), time, 1));
                    w_u32((uint32)((sint32)((uint32)(v23) + (uint32)(160))), 1);
                  }
                  w_u8((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(113))), 1);
                  v6 = 1;
                  ob_draft_unresolved_call(0x800b5bd8u, 4u, 1, r_u32((uint32)(((uint32)(object) + (uint32)(120)))), r_u8((uint32)((sint32)((uint32)(v8) + (uint32)(41)))), time);
                  v87 = object;
                  v88 = 1;
                  goto LABEL_211;
                }
                  break;

                default:
                  if (ob_draft_unresolved_call(0x800b5c50u, 3u, 0, v85, time))
                {
                  v6 = 1;
                  ob_draft_unresolved_call(0x800b5bd8u, 4u, 0, r_u32((uint32)(((uint32)(object) + (uint32)(120)))), r_u8((uint32)((sint32)((uint32)(v8) + (uint32)(40)))), time);
                  v87 = object;
                  v88 = 0;
                  LABEL_211:
                  ob_game_800B5CB4( v87, v88, 0, time);

                }
                  break;

              }

            }
          }

          goto LABEL_212;
        }
        v75 = r_u32((uint32)(((uint32)(object) + (uint32)(120))));
        if (((sint32)((sint8)r_u8((uint32)((sint32)((uint32)((sint32)((uint32)(v105) + (uint32)((sint8)r_u8((uint32)((sint32)((uint32)(v75) + (uint32)(135))))))) + (uint32)(106))))) > (sint32)(0)))
        {
          switch (r_u8((uint32)((sint32)((uint32)(v75) + (uint32)(135)))))
          {
            case 0:
              v6 = 1;
              ob_draft_unresolved_call(0x800b5bd8u, 4u, 0, r_u32((uint32)(((uint32)(object) + (uint32)(120)))), 1, time);
              v76 = object;
              v77 = 2;
              goto LABEL_176;

            case 1:
              v78 = 0;
              w_u8((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(112))), 0);
              do
            {
              v79 = r_u32((uint32)(((uint32)(object) + (uint32)(120))));
              if ((r_u8((uint32)((sint32)((uint32)(v79) + (uint32)(135)))) != 1))
                break;
              ob_draft_unresolved_call(0x800b5bd8u, 4u, 0, v79, r_u8((uint32)((sint32)((uint32)(v8) + (uint32)(40)))), time);
              ob_game_800B5CB4( object, 0, 0, time);
              ++v78;
            }
            while (((sint32)((sint16)(v78)) < (sint32)(4)));
              v6 = 1;
              break;

            case 2:

            case 4:
              v6 = 1;
              ob_draft_unresolved_call(0x800b5bd8u, 4u, 0, r_u32((uint32)(((uint32)(object) + (uint32)(120)))), r_u8((uint32)((sint32)((uint32)(v8) + (uint32)(40)))), time);
              v76 = object;
              v77 = 3;
              goto LABEL_176;

            case 3:
              v6 = 1;
              ob_draft_unresolved_call(0x800b5bd8u, 4u, 0, r_u32((uint32)(((uint32)(object) + (uint32)(120)))), r_u8((uint32)((sint32)((uint32)(v8) + (uint32)(40)))), time);
              v76 = object;
              v77 = 4;
              goto LABEL_176;

            case 5:
              v82 = r_u32((uint32)((sint32)((uint32)(v23) + (uint32)(160))));
              v74 = (v22 & 0x20);
              if ((v82 == 2))
              goto LABEL_178;
              v83 = r_u32((uint32)(((uint32)(object) + (uint32)(120))));
              v84 = (sint16)r_u16((uint32)((sint32)((uint32)(v83) + (uint32)(132))));
              if (((sint32)(v84) < (sint32)((sint32)((uint32)((sint16)r_u16((uint32)((sint32)((uint32)(v83) + (uint32)(130))))) << (uint32)(6)))))
            {
              w_u16((uint32)((sint32)((uint32)(v83) + (uint32)(132))), (sint32)((uint32)(v84) + (uint32)(64)));
              v6 = 1;
              ob_draft_unresolved_call(0x800b5bd8u, 4u, 0, r_u32((uint32)(((uint32)(object) + (uint32)(120)))), r_u8((uint32)((sint32)((uint32)(v8) + (uint32)(40)))), time);
              ob_game_800B5CB4( object, 3, 0, time);
              w_u32((uint32)((sint32)((uint32)(v23) + (uint32)(160))), 1);
              break;
            }
              v74 = (v22 & 0x20);
              if ((v82 != 1))
              goto LABEL_178;
              ob_draft_unresolved_call(0x800b5bd8u, 4u, 0, v83, r_u8((uint32)((sint32)((uint32)(v8) + (uint32)(40)))), time);
              w_u16((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(130))), ((uint32)(r_u16((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(130))))) | (uint32)(0x4000u)));
              ob_game_800B5CB4( object, 3, 0, time);
              v6 = 1;
              w_u16((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(130))), ((uint32)(r_u16((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(130))))) & (uint32)(~0x4000u)));
              w_u32((uint32)((sint32)((uint32)(v23) + (uint32)(160))), 2);
              break;

            case 6:
              if (!(r_u32((uint32)((sint32)((uint32)(v23) + (uint32)(160))))))
            {
              if (((sint32)((sint16)r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(104))))) >= (sint32)(0)))
                ob_draft_unresolved_call(0x8001195cu, 2u, (sint16)r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(104)))), (uint32)v75);
              w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(104))), ob_draft_unresolved_call(0x80011a24u, 6u, (sint32)(0u - (uint32)(2147061164)), 255, 256, r_u32((uint32)(((uint32)(object) + (uint32)(44)))), time, 1));
              ob_draft_unresolved_call(0x80011a24u, 6u, (sint32)(0u - (uint32)(2147061160)), 128, 256, r_u32((uint32)(((uint32)(object) + (uint32)(44)))), time, 0);
            }
              w_u32((uint32)((sint32)((uint32)(v23) + (uint32)(160))), 1);
              v6 = 1;
              ob_draft_unresolved_call(0x800b5bd8u, 4u, 0, r_u32((uint32)(((uint32)(object) + (uint32)(120)))), r_u8((uint32)((sint32)((uint32)(v8) + (uint32)(40)))), time);
              v76 = object;
              v77 = 4;
              goto LABEL_176;

            case 7:
              w_u8((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(120))))) + (uint32)(112))), 1);
              if (!(r_u32((uint32)((sint32)((uint32)(v23) + (uint32)(160))))))
            {
              if (((sint32)((sint16)r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(104))))) >= (sint32)(0)))
                ob_draft_unresolved_call(0x8001195cu, 2u, (sint16)r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(104)))), (uint32)v75);
              w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(104))), ob_draft_unresolved_call(0x80011a24u, 6u, (sint32)(0u - (uint32)(2147061156)), 255, 256, r_u32((uint32)(((uint32)(object) + (uint32)(44)))), time, 1));
              w_u32((uint32)((sint32)((uint32)(v23) + (uint32)(160))), 1);
            }
              v75 = r_u32((uint32)(((uint32)(object) + (uint32)(120))));
              v80 = r_u8((uint32)((sint32)((uint32)(v8) + (uint32)(40))));
              v81 = time;
              goto LABEL_175;

            default:
              v80 = r_u8((uint32)((sint32)((uint32)(v8) + (uint32)(40))));
              v81 = time;
              LABEL_175:
            v6 = 1;

              ob_draft_unresolved_call(0x800b5bd8u, 4u, 0, v75, v80, v81);
              v76 = object;
              v77 = 0;
              LABEL_176:
            ob_game_800B5CB4( v76, v77, 0, time);

              break;

          }

        }
      }
      v74 = (v22 & 0x20);
      goto LABEL_178;
    }
    if (((sint32)time < r_s32((uint32)((sint32)((uint32)(v25) + (uint32)(12))))))
    {
      LABEL_93:
      w_u16((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(124))))) + (uint32)(4))), ((uint32)(r_u16((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(124))))) + (uint32)(4))))) + (uint32)(v9)));

      w_u32((uint32)v23 + 52u, (uint32)((sint32)(r_u32(r_u32(object + 124u)) * (uint32)r_s16(0x8006C304u + 2u * ((r_u16(r_u32(object + 124u) + 4u) + 8u) >> 4) + 0u)) / 16384));
      w_u32((uint32)v23 + 60u, (uint32)((sint32)(r_u32(r_u32(object + 124u)) * (uint32)r_s16(0x8006C304u + 2u * ((r_u16(r_u32(object + 124u) + 4u) + 8u) >> 4) + 2048u)) / 16384));
      w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(48))), ((uint32)(r_u16((uint32)(((uint32)(r_u32((uint32)(((uint32)(object) + (uint32)(124))))) + (uint32)(4))))) + (uint32)(r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(80)))))));
      goto LABEL_94;
    }
    if (((v22 & 0x1000) == 0))
      v7 = (((v22 & 4) != 0)) ? (0x3E8) : (0);
    if ((r_u8((uint32)((sint32)((uint32)(v23) + (uint32)(46)))) == 2))
      v7 = ((uint32)(v7) + (uint32)(1500));
    v26 = r_u8((uint32)((sint32)((uint32)(v23) + (uint32)(47))));
    if ((v26 == 4))
    {
      v27 = (sint32)((uint32)(((sint32)(v7) / (sint32)(10))) + (uint32)(150));
    }
    else
    {
      v27 = (sint32)((uint32)(v7) + (uint32)(2500));
      if ((v26 == 1))
        v27 = (sint32)((uint32)(((sint32)(v7) / (sint32)(4))) + (uint32)(1500));
    }
    if (((v22 & 0x1000) != 0))
    {
      LABEL_59:
      v39 = (sint16)r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(82))));

      if (((sint32)(v39) > (sint32)(0)))
      {
        w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(82))), (sint32)((uint32)(v39) - (uint32)(100)));
        if ((((sint32)((uint32)(v39) - (uint32)(100)) & 0x8000) == 0))
          goto LABEL_65;
        w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(82))), 0);
        v39 = (sint16)r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(82))));
      }
      if (((sint32)(v39) < (sint32)(0)))
      {
        w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(82))), (sint32)((uint32)(v39) + (uint32)(100)));
        if (((sint32)((sint32)((uint32)((sint32)((uint32)(v39) + (uint32)(100))) << (uint32)(16))) > (sint32)(0)))
          w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(82))), 0);
      }
      LABEL_65:
      v9 = r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(82))));

      if (((v22 & 0x1000) != 0))
      {
        LABEL_81:
        v47 = r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(80))));

        if (((uint16)((sint32)((uint32)(v47) + (uint32)(40))) < 0x51u))
        {
          w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(80))), 0);
        }
        else
        {
          v9 = ((uint32)(v9) + (uint32)(((sint32)(v47) / (sint32)(8))));
          v48 = ((uint32)(r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(80))))) - (uint32)(((sint32)(v47) / (sint32)(16))));
          w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(80))), v48);
          if (((sint32)((sint16)(v48)) >= (sint32)(41)))
            w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(80))), (sint32)((uint32)(v48) - (uint32)(40)));
          v49 = (sint16)r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(80))));
          if (((sint32)(v49) < (sint32)((sint32)(0u - (uint32)(40)))))
            w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(80))), (sint32)((uint32)(v49) + (uint32)(40)));
        }
        v50 = (sint16)(v9);
        if (((v9 & 0x8000u) != 0))
          v50 = (sint32)(0u - (uint32)((sint16)(v9)));
        if (((sint32)(v50) >= (sint32)(21)))
        {
          v51 = (sint32)((uint32)(160) * (uint32)((sint16)(v9)));
          v52 = (sint32)((uint32)((sint32)(0u - (uint32)(160))) * (uint32)((sint16)(v9)));
          if (((sint32)(v51) > (sint32)(0)))
            v52 = (sint32)((uint32)(511) - (uint32)(v51));
          w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(88))), ((uint32)(r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(88))))) - (uint32)(((sint32)(v52) >> 9))));
        }
        goto LABEL_93;
      }
      v40 = (v22 & 0xA);
      if (((v22 & 9) == 9))
      {
        v41 = (sint16)r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(80))));
        v42 = (sint32)((uint32)(v41) - (uint32)(336));
        if (((sint32)(v41) >= (sint32)((sint32)(0u - (uint32)(18431)))))
        {
          w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(80))), v42);
          if (((sint32)(v42) < (sint32)((sint32)(0u - (uint32)(18432)))))
            w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(80))), (sint32)(0u - (uint32)(18432)));
        }
        v40 = (v22 & 0xA);
      }
      v17 = (v40 != 10);
      v43 = (v22 & 0xB);
      if (!v17)
      {
        v44 = (sint16)r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(80))));
        v45 = (sint32)((uint32)(v44) + (uint32)(336));
        if (((sint32)(v44) < (sint32)(18432)))
        {
          w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(80))), v45);
          v43 = (v22 & 0xB);
          if (((sint32)(v45) < (sint32)(18433)))
            goto LABEL_76;
          w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(80))), 18432);
        }
        v43 = (v22 & 0xB);
      }
      LABEL_76:
      if ((v43 == 8))
      {
        w_u32(r_u32((uint32)(((uint32)(object) + (uint32)(124)))), ((uint32)(r_u32(r_u32((uint32)(((uint32)(object) + (uint32)(124)))))) - (uint32)(r_u16((uint32)((sint32)((uint32)(v103) + (uint32)(2)))))));
        v46 = r_u32((uint32)(((uint32)(object) + (uint32)(124))));
        if (((sint32)((sint32)r_u32(v46)) < (sint32)(0)))
          w_u32(v46, 0);
        if (((sint32)((sint32)r_u32(r_u32((uint32)(((uint32)(object) + (uint32)(124)))))) >= (sint32)(21)))
          w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(90))), ((uint32)(r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(90))))) + (uint32)(64)));
      }

      goto LABEL_81;
    }
    if (((v22 & 0x100) != 0))
    {
      v28 = v103;
      w_u32(r_u32((uint32)(((uint32)(object) + (uint32)(124)))), ((uint32)(r_u32(r_u32((uint32)(((uint32)(object) + (uint32)(124)))))) + (uint32)(r_u16((uint32)((sint32)((uint32)(v103) + (uint32)(2)))))));
      v29 = r_u32((uint32)(((uint32)(object) + (uint32)(124))));
      v30 = (sint32)r_u32(v29);
      if (((sint32)(v27) < (sint32)((sint32)r_u32(v29))))
      {
        w_u32(v29, (sint32)((uint32)(v30) - (uint32)((sint32)((uint32)(2) * (uint32)(r_u16((uint32)((sint32)((uint32)(v28) + (uint32)(2)))))))));
        v31 = r_u32((uint32)(((uint32)(object) + (uint32)(124))));
        v32 = (v22 & 3);
        if (((sint32)((sint32)r_u32(v31)) < (sint32)(v27)))
          w_u32(v31, v27);
        goto LABEL_49;
      }
      if (((sint32)((sint32)((uint32)(v27) - (uint32)(v30))) < (sint32)(2000)))
      {
        w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(90))), ((uint32)(r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(90))))) + (uint32)(((sint32)((sint32)((uint32)((sint32)(0u - (uint32)(464))) * (uint32)((sint32)((uint32)(v27) - (uint32)(v30))))) / (sint32)(4000)))));
        LABEL_48:
        v32 = (v22 & 3);

        LABEL_49:
        if (v32)
        {
          v35 = (v22 & 2);
          if (((v22 & 1) != 0))
          {
            v36 = (sint16)r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(82))));
            v35 = (v22 & 2);
            if (((sint32)(v36) >= (sint32)((sint32)(0u - (uint32)(459)))))
            {
              w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(82))), (sint32)((uint32)(v36) - (uint32)(140)));
              if (((sint32)((sint16)((sint32)((uint32)(v36) - (uint32)(140)))) < (sint32)((sint32)(0u - (uint32)(460)))))
                w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(82))), (sint32)(0u - (uint32)(460)));
              v35 = (v22 & 2);
            }
          }
          if (v35)
          {
            v37 = (sint16)r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(82))));
            v38 = (sint32)((uint32)(v37) + (uint32)(140));
            if (((sint32)(v37) < (sint32)(460)))
            {
              w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(82))), v38);
              if (((sint32)(v38) >= (sint32)(461)))
                w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(82))), 460);
            }
          }
        }

        goto LABEL_59;
      }
      if (((sint32)r_u16((uint32)((sint32)((uint32)(v103) + (uint32)(2)))) >= v30))
        goto LABEL_48;
      v33 = ((uint32)(r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(90))))) - (uint32)(464));
    }
    else
    {
      w_u32(r_u32((uint32)(((uint32)(object) + (uint32)(124)))), ((uint32)(r_u32(r_u32((uint32)(((uint32)(object) + (uint32)(124)))))) - (uint32)(r_u16((uint32)((sint32)((uint32)(v103) + (uint32)(2)))))));
      v34 = r_u32((uint32)(((uint32)(object) + (uint32)(124))));
      if (((sint32)((sint32)r_u32(v34)) < (sint32)(0)))
        w_u32(v34, 0);
      v32 = (v22 & 3);
      if (((sint32)((sint32)r_u32(r_u32((uint32)(((uint32)(object) + (uint32)(124)))))) < (sint32)(21)))
        goto LABEL_49;
      v33 = ((uint32)(r_u16((uint32)((sint32)((uint32)(v23) + (uint32)(90))))) + (uint32)(64));
    }
    w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(90))), v33);
    goto LABEL_48;
  }
  { uint32 draft_return = result; ob_draft_scratch_release(attributes);  return draft_return; }
}

