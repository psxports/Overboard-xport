#include "draft_signatures.h"
#include <stdint.h>

/* Unverified draft bodies */

sint32 sub_8001A6FC(void)
{
    FUNCTION_MARKER(0x8001a6fcu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8002192C */
    /* TODO: Bind external adapter for sub_80016C20 */
    /* TODO: Bind external adapter for sub_8004659C */
    /* TODO: Bind external adapter for sub_80045A7C */
    /* TODO: Bind external adapter for sub_8001A398 */
    /* TODO: Bind external adapter for sub_8001B060 */
    uint32 local_objects = ob_draft_scratch_acquire(116u);
  sint32 v0;
  sint32 v1;
  sint32 v2;
  sint32 v3;
  sint32 v4;
  uint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  sint32 v11;
  sint32 v12;
  sint32 v13;
  sint32 v14;
  sint32 v15;
  sint32 v16;
  sint32 i;
  sint32 v18;
  uint32 v19;
  sint32 v20;
  sint16 v21;
  sint32 v22;
  sint32 v23;
  sint16 v24;
  sint32 v25;
  sint32 v26;
  uint32 v27;
  ;
  ;
  ;
  w_u32(local_objects + 112u, 0);
  v0 = (sint32)r_u32((0x8006c138u + (r_u16(0x800C4E70)) * 4u));
  if (v0)
  {
    v1 = r_u32((uint32)((sint32)((uint32)(v0) + (uint32)(288))));
    if ((v1 == 22))
    {
      if (((sint16)r_u16(0x80076880u) == 3))
      {
        ob_draft_unresolved_call(0x8002192cu, 1u, 2);
        ob_draft_unresolved_call(0x80016c20u, 1u, r_u8(0x80086A2C));
        v2 = (sint32)r_u32(0x80077334u);
        if (((sint32)((uint32)((sint32)r_u32(0x80077334u)) - (uint32)(r_u32(0x80089990))) >= 51))
        {
          while (1)
          {
            v3 = ((uint32)(r_u32(0x80089990)) + (uint32)(50));
            w_u8(0x80086A2C, ((uint32)(r_u8(0x80086A2C)) + (uint32)(15)));
            w_u32(0x80089990, ((uint32)(r_u32(0x80089990)) + (uint32)(50)));
            if ((r_u8(0x80086A2C) == 255))
              break;
            v2 = (sint32)r_u32(0x80077334u);
            if (((sint32)((uint32)((sint32)r_u32(0x80077334u)) - (uint32)(v3)) < 51))
              { uint32 draft_return = (sint32)r_u32(local_objects + 112u); ob_draft_scratch_release(local_objects);  return draft_return; }
          }

          w_u32(local_objects + 112u, 10);
          w_u32(0x8007687Cu, v2);
          w_u32(0x8008969C, (sint32)((uint32)((sint32)((uint32)(100) * (uint32)((sint32)((uint32)((sint32)((uint32)(30) * (uint32)((sint8)r_u8(0x8006C248u)))) + (uint32)(30))))) + (uint32)(200)));
          v4 = 0;
          if ((sint8)r_u8(0x8006C230u))
          {
            v5 = (sint32)r_u32(0x8006C138u);
            do
            {
              if ((sint32)r_u32(v5))
              {
                if (r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(52))))) + (uint32)(28)))))
                  ob_draft_unresolved_call(0x8004659cu, 0u);
                v6 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(108))));
                ob_draft_unresolved_call(0x80045a7cu, 2u, r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(44)))), (sint32)r_u32(0x80077334u));
                w_u32((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(288))), 23);
                v7 = (sint32)r_u32(v5);
                w_u16(0x80076880u, 0);
                ob_draft_unresolved_call(r_u32(0x8009A704), 1u, v7);
                if ((!(sint8)r_u8(0x8006C240u) || !(r_u16((uint32)((sint32)((uint32)((sint32)((uint32)(104) * (uint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(326))))))) - (uint32)(2146649530)))))))
                  w_u16((uint32)((sint32)((uint32)((sint32)((uint32)(104) * (uint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(326))))))) - (uint32)(2146649530))), ob_draft_unresolved_call(r_u32(0x800901A8), 1u, 255));
                if (((uint8)((sint8)r_u8(0x8006C230u)) >= 2u))
                  ob_draft_unresolved_call(0x8001a398u, 1u, v4);
                ob_draft_unresolved_call(r_u32(0x800C1068), 3u, r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(124)))), 0, 16);
                w_u16((uint32)((sint32)((uint32)(v6) + (uint32)(48))), r_u32(0x8008C6F8));
                w_u16((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(296))), r_u32(0x8008C6F8));
                w_u16((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(124))))) + (uint32)(4))), r_u32(0x8008C6F8));
                w_u32(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(124)))), 0);
                w_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(124))))) + (uint32)(8))), (sint32)r_u32(0x80077334u));
                v8 = ob_draft_unresolved_call(r_u32(0x800AD6E0), 2u, (local_objects + 0u), r_u32(0x8008C6F8));
                sub_80045848(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(44)))), v8);
                sub_800458B4(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(44)))), (0u - (uint32)(2146908440)), (sint32)r_u32(0x80077334u));
                sub_80045A44(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(44)))), (0x8006C160u));
                v9 = (sint32)r_u32(0x8006C164u);
                v10 = (sint32)r_u32(0x8006C168u);
                w_u32((uint32)((sint32)((uint32)(v6) + (uint32)(52))), (sint32)r_u32(0x8006C160u));
                w_u32((uint32)((sint32)((uint32)(v6) + (uint32)(56))), v9);
                w_u32((uint32)((sint32)((uint32)(v6) + (uint32)(60))), v10);
                v11 = (sint32)r_u32(0x8006C164u);
                v12 = (sint32)r_u32(0x8006C168u);
                w_u32((uint32)((sint32)((uint32)(v6) + (uint32)(68))), (sint32)r_u32(0x8006C160u));
                w_u32((uint32)((sint32)((uint32)(v6) + (uint32)(72))), v11);
                w_u32((uint32)((sint32)((uint32)(v6) + (uint32)(76))), v12);
                w_u16((uint32)((sint32)((uint32)(v6) + (uint32)(88))), 0);
                w_u16((uint32)((sint32)((uint32)(v6) + (uint32)(90))), 0);
                w_u16((uint32)((sint32)((uint32)(v6) + (uint32)(84))), 0);
                w_u16((uint32)((sint32)((uint32)(v6) + (uint32)(86))), 0);
                w_u16((uint32)((sint32)((uint32)(v6) + (uint32)(80))), 0);
                w_u16((uint32)((sint32)((uint32)(v6) + (uint32)(82))), 0);
                w_u16((uint32)((sint32)((uint32)(v6) + (uint32)(45))), 1);
                w_u32((uint32)((sint32)((uint32)(v6) + (uint32)(36))), 0);
                w_u16((uint32)((sint32)((uint32)(v6) + (uint32)(50))), 0);
                w_u16((uint32)((sint32)((uint32)(v6) + (uint32)(172))), 0);
                w_u16((uint32)((sint32)((uint32)(v6) + (uint32)(168))), 0);
                sub_8004651C(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(52)))));
                ob_draft_unresolved_call(r_u32(0x800BE604), 3u, (sint32)r_u32(v5), (local_objects + 24u), (sint32)r_u32(0x80077334u));
                w_u8(0x8008AE6A, 0);
                w_u8((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(136))))) + (uint32)(60))))) + (uint32)(52))), 0);
                w_u8((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(140))))) + (uint32)(60))))) + (uint32)(52))), 0);
                ob_draft_unresolved_call(r_u32(0x800B4874), 2u, (sint32)r_u32(v5), (sint32)r_u32(0x80077334u));
                v13 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(60))));
                w_u32(0x8007FAD0, r_u32(0x800843D0));
                w_u8((uint32)((sint32)((uint32)(v13) + (uint32)(52))), 0);
                w_u8((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(136))))) + (uint32)(60))))) + (uint32)(52))), 0);
                w_u8((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(140))))) + (uint32)(60))))) + (uint32)(52))), 0);
                w_u8((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(60))))) + (uint32)(54))), 6);
                v14 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(108))));
                v15 = r_u8((uint32)((sint32)((uint32)(v14) + (uint32)(46))));
                w_u16((uint32)((sint32)((uint32)(v14) + (uint32)(174))), 0);
                if (v15)
                  w_u32((uint32)((sint32)((uint32)(v14) + (uint32)(36))), 1);
                v16 = v14;
                if (((uint8)((sint8)r_u8(0x8006C230u)) >= 2u))
                {
                  for (i = 0; (i < 13); ++i)
                  {
                    if ((sint8)r_u8((0x8006c254u + (i) * 1u)))
                    {
                      w_u8((uint32)((sint32)((uint32)(v16) + (uint32)(130))), (sint32)((uint32)((sint8)r_u8((0x8006c254u + (i) * 1u))) - (uint32)(1)));
                      w_u8((uint32)((sint32)((uint32)(v16) + (uint32)(106))), 1);
                    }
                    else
                    {
                      w_u8((uint32)((sint32)((uint32)(v16) + (uint32)(106))), 0);
                    }
                    ++v16;
                  }

                  v18 = 0;
                  v19 = (0x8006C24Au);
                  v20 = v14;
                  do
                  {
                    v21 = (sint16)r_u16(((v19 += 2u) - 2u));
                    ++v18;
                    w_u16((uint32)((sint32)((uint32)(v20) + (uint32)(120))), v21);
                    v20 += 2;
                  }
                  while ((v18 < 5));
                  v22 = 0;
                  do
                  {
                    v23 = (v22 < 8);
                    if (r_u8((uint32)((sint32)((uint32)((sint32)((uint32)(v14) + (uint32)(v22))) + (uint32)(106)))))
                    {
                      w_u8((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v5)) + (uint32)(120))))) + (uint32)(135))), v22);
                      ob_draft_unresolved_call(r_u32(0x800B7C7C), 0u);
                      v24 = r_u16((uint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)((sint8)r_u8((uint32)((sint32)((uint32)(v14) + (uint32)(177))))))) - (uint32)(2146674048))));
                      w_u8((uint32)((sint32)((uint32)(v14) + (uint32)(177))), v22);
                      w_u16((uint32)((sint32)((uint32)(v14) + (uint32)(156))), v24);
                      w_u16((uint32)((sint32)((uint32)(v14) + (uint32)(154))), v24);
                      w_u16((uint32)((sint32)((uint32)(v14) + (uint32)(152))), v24);
                      v23 = (v22 < 8);
                      if (r_u8((uint32)((sint32)((uint32)((sint32)((uint32)(v14) + (uint32)(v22))) + (uint32)(106)))))
                        break;
                    }
                    ++v22;
                  }
                  while (v23);
                }
              }
              ++v4;
              ((v5 += 4u));
            }
            while ((v4 < (uint8)((sint8)r_u8(0x8006C230u))));
          }
          w_u32(0x80089990, (sint32)r_u32(0x80077334u));
          w_u32(0x8007FAD0, r_u32(0x800843D0));
        }
      }
      else
      {
        ob_draft_unresolved_call(0x8001b060u, 1u, (sint32)r_u32(0x80077334u));
      }
    }
    else
      if ((v1 == 23))
    {
      ob_draft_unresolved_call(0x8002192cu, 1u, 2);
      ob_draft_unresolved_call(0x80016c20u, 1u, r_u8(0x80086A2C));
      if (((sint32)((uint32)((sint32)r_u32(0x80077334u)) - (uint32)(r_u32(0x80089990))) >= 51))
      {
        while (1)
        {
          v25 = ((uint32)(r_u32(0x80089990)) + (uint32)(50));
          w_u8(0x80086A2C, ((uint32)(r_u8(0x80086A2C)) - (uint32)(15)));
          w_u32(0x80089990, ((uint32)(r_u32(0x80089990)) + (uint32)(50)));
          if (!r_u8(0x80086A2C))
            break;
          if (((sint32)((uint32)((sint32)r_u32(0x80077334u)) - (uint32)(v25)) < 51))
            { uint32 draft_return = (sint32)r_u32(local_objects + 112u); ob_draft_scratch_release(local_objects);  return draft_return; }
        }

        v26 = 0;
        if ((sint8)r_u8(0x8006C230u))
        {
          v27 = (sint32)r_u32(0x8006C138u);
          do
          {
            if ((sint32)r_u32(v27))
              w_u32((uint32)((sint32)((uint32)((sint32)r_u32(v27)) + (uint32)(288))), 21);
            ++v26;
            ((v27 += 4u));
          }
          while ((v26 < (uint8)((sint8)r_u8(0x8006C230u))));
        }
      }
    }
  }
  { uint32 draft_return = (sint32)r_u32(local_objects + 112u); ob_draft_scratch_release(local_objects);  return draft_return; }
}


sint32 sub_80050B88(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80050b88u, "SLES_008.65");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
  sint32 v4;
  sint16 v5;
  sint32 v6;
  sint32 v7;
  uint32 v8;
  sint32 v9;
  sint32 v10;
  sint32 v11;
  sint32 v12;
  sint32 v13;
  sint32 v14;
  sint32 v15;
  sint32 v16;
  sint32 v17;
  sint32 v18;
  sint32 v19;
  sint32 v20;
  sint32 v21;
  sint32 v22;
  sint32 result;
  sint32 v24;
  sint32 v25;
  sint32 v26;
  sint32 v27;
  sint32 v28;
  sint32 v29;
  sint32 v30;
  sint32 v31;
  sint32 v32;
  sint32 v33;
  uint32 v34;
  uint32 v35;
  sint32 v36;
  sint32 v37;
  sint32 v38;
  uint32 v39;
  sint32 v40;
  uint32 v41;
  sint32 i;
  sint32 v43;
  uint32 v44;
  sint32 v45;
  sint32 v46;
  sint32 v47;
  sint32 v48;
  sint32 v49;
  sint32 v50;
  sint32 v51;
  sint32 v52;
  sint32 v53;
  sint32 v54;
  sint32 v55;
  sint32 v56;
  sint32 v57;
  sint32 v58;
  sint32 v59;
  sint32 v60;
  sint32 v61;
  sint32 v62;
  sint32 v63;
  sint32 v64;
  sint32 v65;
  sint32 v66;
  sint32 v67;
  sint32 v68;
  sint32 v69;
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
  v4 = ((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80077644u)) + (uint32)(24))))) + (uint32)((sint32)((uint32)(24) * (uint32)(r_u8(a1)))));
  v5 = r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(46))));
  v6 = ((uint32)(((uint32)((((uint32)((r_u16(((uint32)(a1) + (1) * 2u)) & 0xFFFC)) << (uint32)(16)) >> 14)) + (uint32)((sint32)((uint32)((sint8)r_u8((uint32)((sint32)((uint32)(v4) + (uint32)(23))))) << (uint32)(6))))) << (uint32)(8));
  if (v5)
  {
    if ((((uint8)(v5) & r_u8((uint32)((sint32)((uint32)(v4) + (uint32)(22))))) != 0))
      return 2147483393;
    v7 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(8))));
    v8 = (v7 <= 0);
    v9 = (v6 < v7);
    if (!v8)
    {
      if (v9)
        return 2147483393;
    }
  }
  v10 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(116))));
  v11 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(176))));
  v12 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(120))));
  v13 = (sint32)((uint32)(v10) - (uint32)(v11));
  if ((v10 != v11))
  {
    v14 = (sint32)((uint32)((sint16)r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(40))))) * (uint32)(v13));
    v15 = (sint32)((uint32)((sint16)r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(42))))) * (uint32)(v13));
    v16 = (sint32)((uint32)((sint16)r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(44))))) * (uint32)(v13));
    v17 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(164))));
    w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(176))), v10);
    w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(164))), (sint32)((uint32)(v17) + (uint32)(v14)));
    v18 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(172))));
    w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(168))), ((uint32)(r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(168))))) + (uint32)(v15)));
    w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(172))), (sint32)((uint32)(v18) + (uint32)(v16)));
  }
  v78 = ((uint32)(r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(164))))) - (uint32)(r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(192))))));
  v79 = ((uint32)(r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(172))))) - (uint32)(r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(200))))));
  v19 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(168))));
  if ((v12 == 2147483393))
  {
    v20 = 0x1000000;
    if (((sint16)r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(42)))) < 0))
      v20 = (0u - (uint32)(16777216));
  }
  else
  {
    v20 = (sint32)((uint32)(v19) + (uint32)((sint32)((uint32)((sint16)r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(42))))) * (uint32)((sint32)((uint32)(v12) - (uint32)(v10))))));
  }
  v21 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(168))));
  if ((v20 < v19))
    v21 = v20;
  if (((v6 < v21) && ((!(r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(76))))) || (v21 > 0)) || ((v19 < 0) && (v20 < 0)))))
    return 2147483393;
  v22 = (sint16)r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(42))));
  if ((v22 <= 0))
  {
    if ((v22 < 0))
    {
      v27 = (0u - (uint32)(v22));
      if ((v19 > 0))
      {
        v28 = (v19 / v27);
        if (((sint32)((uint32)(v19) + (uint32)((sint32)((uint32)((v19 / v27)) * (uint32)((sint16)r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(42)))))))) < 0))
          --v28;
        if ((v28 < 0))
          v28 = 0;
        v29 = (sint32)((uint32)(v10) + (uint32)(v28));
        if (((sint32)((uint32)(v10) + (uint32)(v28)) < r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(84))))))
        {
          v30 = (sint32)((uint32)((sint16)r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(40))))) * (uint32)(v28));
          v31 = (sint32)((uint32)((sint16)r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(44))))) * (uint32)(v28));
          w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(108))), v29);
          w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(84))), v29);
          v32 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(172))));
          w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(100))), 2);
          w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(104))), 2);
          v33 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(164))));
          w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(92))), 0);
          w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(88))), (sint32)((uint32)(v33) + (uint32)(v30)));
          w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(96))), (sint32)((uint32)(v32) + (uint32)(v31)));
        }
        if (((r_u8((uint32)((sint32)((uint32)(v4) + (uint32)(22)))) & 0xE) != 0))
          return r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(84))));
      }
    }
    goto LABEL_36;
  }
  if (r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(40)))))
    goto LABEL_36;
  if (r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(44)))))
    goto LABEL_37;
  if ((v19 >= 0))
    return 2147483393;
  if (((sint32)((uint32)(v10) + (uint32)(v13)) >= r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(84))))))
  {
    LABEL_36:
    if (!(r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(44))))))
    {
      sub_800502AC((uint32)((sint32)((uint32)(a2) + (uint32)(324))), v79, r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(24)))));
      goto LABEL_39;
    }

    LABEL_37:
    sub_80050088((uint32)((sint32)((uint32)(a2) + (uint32)(324))), v79, r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(24)))), v10);

    LABEL_39:
    if (r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(40)))))
      sub_80050088((uint32)((sint32)((uint32)(a2) + (uint32)(204))), v78, r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(16)))), v10);
    else
      sub_800502AC((uint32)((sint32)((uint32)(a2) + (uint32)(204))), v78, r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(16)))));

    v34 = ((uint32)((sint32)r_u32(0x800739FCu)) + ((sint32)((uint32)(9) * (uint32)((r_u16(((uint32)(a1) + (1) * 2u)) & 3)))) * 1u);
    if (((sint32)r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(228)))) < 0))
      v34 += (2) * 1u;
    v35 = (uint32)((sint32)((uint32)(a2) + (uint32)(420)));
    if (((sint32)r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(348)))) < 0))
      v34 += (6) * 1u;
    v36 = 0;
    v37 = (sint32)r_u32(0x80077334u);
    while (1)
    {
      v38 = (sint32)r_u32(v35);
      v39 = (v35 + (1) * 4u);
      v40 = (sint32)r_u32(v39);
      v35 = (v39 + (1) * 4u);
      v41 = (uint32)((sint32)((uint32)(a2) + (uint32)(300)));
      for (i = 0; (i < 3); ++i)
      {
        v43 = (sint32)r_u32(v41);
        v44 = (v41 + (1) * 4u);
        v45 = (sint32)r_u32(v44);
        v46 = ((uint32)(((uint32)((((uint32)((r_u16(((uint32)(a1) + (1) * 2u)) & 0xFFFC)) << (uint32)(16)) >> 14)) + (uint32)((sint32)((uint32)((sint8)r_u8((uint32)((sint32)((uint32)((sint32)((uint32)(v4) + (uint32)((sint8)r_u8(v34)))) + (uint32)(12))))) << (uint32)(6))))) << (uint32)(8));
        v41 = (v44 + (1) * 4u);
        if ((((v21 >= v46) || (v38 >= v45)) || (v43 >= v40)))
          goto LABEL_95;
        if (v43)
        {
          v47 = (v38 < v43);
        }
        else
        {
          v47 = (v38 < 0);
          if (!v38)
          {
            v48 = (sint16)r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(42))));
            v49 = ((sint32)((uint32)(v46) - (uint32)(v19)) / v48);
            if (!(r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(42))))))
              ob_draft_unresolved_call(0x80050b88u, 2u, 7u, 0);
            if (((v48 == (0u - (uint32)(1))) && ((sint32)((uint32)(v46) - (uint32)(v19)) == 0x80000000)))
              ob_draft_unresolved_call(0x80050b88u, 2u, 6u, 0);
            v50 = ((sint32)((uint32)(v46) - (uint32)(v19)) / v48);
            if ((r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(84)))) >= (sint32)((uint32)(v10) + (uint32)(v49))))
            {
              if (((sint32)((uint32)(v10) + (uint32)(v49)) < v37))
                v50 = (sint32)((uint32)(v37) - (uint32)(v10));
              v51 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(164))));
              v52 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(172))));
              w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(108))), (sint32)((uint32)(v10) + (uint32)(v50)));
              w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(84))), (sint32)((uint32)(v10) + (uint32)(v50)));
              w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(92))), v46);
              w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(100))), 2);
              w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(104))), 0);
              w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(88))), v51);
              w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(96))), v52);
            }
            goto LABEL_95;
          }
        }
        v53 = 4;
        if (v47)
          v53 = 1;
        v54 = v43;
        v8 = (v43 >= v38);
        v55 = v45;
        if (!v8)
          v54 = v38;
        if ((v40 < v45))
          v55 = v40;
        if ((v54 < v10))
          v54 = v10;
        v56 = (sint16)r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(42))));
        v57 = (sint32)((uint32)(v54) - (uint32)(v10));
        v58 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(168))));
        v19 = (sint32)((uint32)(v58) + (uint32)((sint32)((uint32)(v56) * (uint32)((sint32)((uint32)(v54) - (uint32)(v10))))));
        v59 = ((sint32)((uint32)(v58) + (uint32)((sint32)((uint32)(v56) * (uint32)((sint32)((uint32)(v55) - (uint32)(v10)))))) < v46);
        if ((v19 >= v46))
        {
          v8 = !v59;
          v68 = (sint32)((uint32)(v19) - (uint32)(v46));
          if (!v8)
          {
            v69 = (v68 / v56);
            if (((v56 == (0u - (uint32)(1))) && (v68 == 0x80000000)))
              ob_draft_unresolved_call(0x80050b88u, 2u, 6u, 0);
            v70 = (sint32)((uint32)(v57) - (uint32)(v69));
            if (((sint32)((uint32)(v57) - (uint32)(v69)) < 0))
              v70 = 0;
            if (((sint32)((uint32)(v10) + (uint32)(v70)) < r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(84))))))
            {
              if (((sint32)((uint32)(v10) + (uint32)(v70)) < v37))
                v70 = (sint32)((uint32)(v37) - (uint32)(v10));
              v71 = (sint32)((uint32)((sint16)r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(40))))) * (uint32)(v70));
              v72 = (sint32)((uint32)((sint16)r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(44))))) * (uint32)(v70));
              v73 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(172))));
              w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(108))), (sint32)((uint32)(v10) + (uint32)(v70)));
              w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(84))), (sint32)((uint32)(v10) + (uint32)(v70)));
              v74 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(164))));
              w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(92))), v46);
              w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(100))), 2);
              w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(104))), 0);
              w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(88))), (sint32)((uint32)(v74) + (uint32)(v71)));
              w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(96))), (sint32)((uint32)(v73) + (uint32)(v72)));
            }
          }
        }
        else
          if ((v54 < (sint32)r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(84))))))
        {
          if ((v54 < v37))
            v54 = v37;
          v60 = (sint32)((uint32)((sint16)r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(40))))) * (uint32)((sint32)((uint32)(v54) - (uint32)(v10))));
          v61 = (sint32)((uint32)((sint16)r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(42))))) * (uint32)((sint32)((uint32)(v54) - (uint32)(v10))));
          v62 = (sint32)((uint32)((sint16)r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(44))))) * (uint32)((sint32)((uint32)(v54) - (uint32)(v10))));
          v63 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(164))));
          w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(108))), v54);
          w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(84))), v54);
          w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(88))), (sint32)((uint32)(v63) + (uint32)(v60)));
          v64 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(172))));
          w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(92))), ((uint32)(r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(168))))) + (uint32)(v61)));
          v65 = (sint32)((uint32)(v64) + (uint32)(v62));
          w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(96))), v65);
          if ((v53 == 1))
          {
            if (((sint16)r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(40)))) <= 0))
            {
              v53 = 9;
              v66 = ((uint32)(r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(88))))) + (uint32)(r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(16))))));
            }
            else
            {
              v66 = ((uint32)(r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(88))))) - (uint32)(r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(16))))));
            }
            w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(88))), v66);
          }
          else
          {
            v53 = 4;
            if (((sint16)r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(44)))) <= 0))
            {
              v53 = 12;
              v67 = (sint32)((uint32)(v65) + (uint32)(r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(24))))));
            }
            else
            {
              v67 = (sint32)((uint32)(v65) - (uint32)(r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(24))))));
            }
            w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(96))), v67);
          }
          w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(100))), v53);
          w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(104))), 0);
        }
        LABEL_95:
        v75 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(228))));

        v34 += (v75) * 1u;
      }

      ++v36;
      v34 += ((sint32)((uint32)(3) * (uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(348))))) - (uint32)(v75))))) * 1u;
      if ((v36 >= 3))
      {
        v76 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(84))));
        if (((v76 != 2147483393) && (v76 == r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(108)))))))
        {
          if ((v76 < (sint32)r_u32(0x80077334u)))
            w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(84))), (sint32)r_u32(0x80077334u));
          v77 = (sint32)((uint32)((sint32)r_u32(0x800775B0u)) - (uint32)(r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(96))))));
          w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(88))), ((uint32)(r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(88))))) - (uint32)((sint32)r_u32(0x800775A8u))));
          w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(96))), v77);
        }
        return r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(84))));
      }
    }

  }
  v24 = ((0u - (uint32)(v19)) / v22);
  if (!(r_u16((uint32)((sint32)((uint32)(a2) + (uint32)(42))))))
    ob_draft_unresolved_call(0x80050b88u, 2u, 7u, 0);
  v25 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(164))));
  w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(100))), 10);
  w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(84))), (sint32)((uint32)(v10) + (uint32)(v24)));
  result = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(84))));
  v26 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(172))));
  w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(92))), 0);
  w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(104))), 3);
  w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(88))), v25);
  w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(108))), (sint32)((uint32)(v10) + (uint32)(v24)));
  w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(96))), v26);
  return result;
}


sint32 sub_8003AA8C(uint32 a1)
{
    FUNCTION_MARKER(0x8003aa8cu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8005F3C8 */
    /* TODO: Bind external adapter for sub_8005F59C */
    uint32 local_objects = ob_draft_scratch_acquire(68u);
    uint32 normal_first;
    uint32 primitive_data;
    uint32 normal_third;
    uint32 normal_second;
  sint32 v1;
  sint32 v2;
  uint32 v3;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  sint32 v11;
  sint32 v12;
  sint32 v13;
  sint32 v14;
  sint32 result;
  uint32 v16;
  uint16 v17;
  uint32 v18;
  uint32 v19;
  sint16 v20;
  sint16 v22;
  sint32 v23;
  sint32 v24;
  uint32 v25;
  sint32 v26;
  sint32 v27;
  sint32 v28;
  sint32 v29;
  sint32 v30;
  sint32 v33;
  sint32 v34;
  sint32 v35;
  uint32 v36;
  sint32 v37;
  sint32 v38;
  sint32 v39;
  sint32 v40;
  sint32 v41;
  sint32 v44;
  sint8 v50;
  uint32 v51;
  sint32 v55;
  uint32 v56;
  sint32 v57;
  sint32 v58;
  sint32 v59;
  sint32 v60;
  sint32 v61;
  sint32 v62;
  sint32 v63;
  uint32 v64;
  sint32 v65;
  sint32 v66;
  sint32 v67;
  sint32 v68;
  sint32 v69;
  sint32 v70;
  sint32 v71;
  sint32 v73;
  sint32 v75;
  sint16 v76;
  sint32 v77;
  sint32 v78;
  sint32 v79;
  sint32 v80;
  sint16 v82;
  ;
  sint32 v84;
  sint32 v85;
  sint32 v86;
  sint32 v87;
  sint32 v88;
  ;
  sint32 v90;
  sint32 v91;
  if (!(sint32)r_u32(0x800774CCu))
    w_u32(0x80077634u, (sint32)((uint32)((sint32)((uint32)((sint32)r_u32(0x8007737Cu)) + (uint32)((sint32)((uint32)(4) * (uint32)((sint32)r_u32(0x80077350u)))))) + (uint32)(112)));
  v1 = (sint32)r_u32(0x800774A8u);
  v2 = (sint32)r_u32(0x80077634u);
  v3 = (uint32)((sint32)r_u32(0x800775E4u));
  v4 = (sint32)r_u32(0x80077574u);
  v87 = r_u32((uint32)((sint32)r_u32(0x80077634u)));
  v82 = (sint16)r_u16(0x80077480u);
  w_u16(local_objects + 0u, (sint16)r_u16(0x800775A0u));
  v86 = ((uint32)((uint16)((sint16)r_u16(0x800775F0u))) + (uint32)(r_u16((uint32)((sint32)r_u32(0x80077598u)))));
  v88 = (sint32)r_u32(0x800773A4u);
  v84 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80077598u)) + (uint32)(44))));
  v5 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80077598u)) + (uint32)(48))));
  w_u32(0x1F800004, 8355711);
  v85 = v5;
  if ((v86 > 0))
  {
    v6 = (0u - (uint32)(16777216));
    while (1)
    {
      v7 = r_u16(v3);
      if ((v7 != 0xFFFF))
        break;
      w_u32(local_objects + 64u, v6);
      v76 = (sint16)r_u16(0x800775A6u);
      v77 = (sint32)r_u32(0x8007759Cu);
      v78 = (sint32)r_u32(0x80077530u);
      v79 = (sint32)r_u32(0x80077328u);
      v80 = (sint32)r_u32(0x800773C0u);
      v8 = sub_800409E0();
      v9 = r_u16((v3 + (1) * 2u));
      v10 = r_u16((v3 + (2) * 2u));
      v11 = v8;
      w_u32(0x800774A8u, v1);
      w_u32(0x80077634u, v2);
      v12 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(32))));
      v13 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(2))));
      (w_u32(0x800774CCu, ((sint32)r_u32(0x800774CCu) + 1u)), (sint32)r_u32(0x800774CCu));
      ob_draft_unresolved_call(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(36)))), 3u, v12, (sint32)((uint32)(v9) + (uint32)((sint32)((uint32)(v10) << (uint32)(16)))), v13);
      v1 = (sint32)r_u32(0x800774A8u);
      v2 = (sint32)r_u32(0x80077634u);
      w_u32(0x1F800004, 8355711);
      (w_u32(0x800774CCu, ((sint32)r_u32(0x800774CCu) - 1u)), (sint32)r_u32(0x800774CCu));
      w_u16(0x800775A6u, v76);
      w_u32(0x8007759Cu, v77);
      w_u32(0x80077530u, v78);
      w_u32(0x80077328u, v79);
      w_u32(0x800773C0u, v80);
      ob_draft_unresolved_call(0x8005f3c8u, 1u, v79);
      sub_80040BF0(v11);
      v14 = v86;
      v6 = (sint32)r_u32(local_objects + 64u);
      v3 += (3) * 2u;
      if (((sint32)((uint32)((sint32)r_u32(0x800775BCu)) - (uint32)(v1)) < (sint32)((uint32)(v86) << (uint32)(6))))
      {
        result = ((r_u32((uint32)(v2)) & (sint32)r_u32(local_objects + 64u)) | (v87 & 0xFFFFFF));
        w_u32((uint32)(v2), result);
        { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
      }
      LABEL_82:
      v86 = (sint32)((uint32)(v14) - (uint32)(1));

      if (((sint32)((uint32)(v14) - (uint32)(1)) <= 0))
        goto LABEL_83;
    }

    v16 = r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(v7))) + (uint32)(v88))));
    if (v16)
    {
      v17 = r_u16((v16 + (1) * 2u));
      v18 = ((v16 + (v17) * 2u));
      v19 = (v18 + (2) * 2u);
      v20 = ((r_u16(v16) | v82) & (sint16)r_u16(local_objects + 0u));
      primitive_data = ((v16 + ((sint32)((uint32)((sint32)((uint32)(2) * (uint32)(v17))) + (uint32)(2))) * 2u));
      v22 = v20;
      if (((v20 & 0x4000) != 0))
      {
        v22 = ((v20 & 0xFFF8) | 1);
        primitive_data += (2) * 2u;
      }
      if (((v22 & 2) != 0))
      {
        if ((v17 == 4))
        {
          v23 = r_u32((uint32)(primitive_data));
          if (((v22 & 0x200) != 0))
          {
            v24 = (sint32)((uint32)(v1) + (uint32)(12));
            w_u32((uint32)(v2), ((r_u32((uint32)(v2)) & v6) | (v1 & 0xFFFFFF)));
            v25 = (uint32)(v1);
            w_u32(0x1F800008, r_u8(((uint32)(primitive_data) + (16) * 1u)));
            v26 = (sint32)((uint32)(v1) + (uint32)(52));
            w_u32(0x1F80000C, r_u8(((uint32)(primitive_data) + (17) * 1u)));
            v27 = ((sint32)((uint32)(v1) + (uint32)(12)) & 0xFFFFFF);
            w_u32(0x1F800010, r_u8(((uint32)(primitive_data) + (18) * 1u)));
            v1 += 64;
            w_u32(0x1F800014, r_u8(((uint32)(primitive_data) + (19) * 1u)));
            w_u32(v25, 0x2000000);
            v28 = (((sint32)r_u32(v25) & v6) | v27);
            w_u32((v25 + (1) * 4u), ((uint32)((uint16)(v23)) - (uint32)(520093184)));
            v29 = r_u32(0x1F80000C);
            v30 = (sint32)((uint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(32) * (uint32)((sint32)((uint32)(31) - (uint32)((((uint32)(r_u32(0x1F800014)) - (uint32)(1)) >> 3)))))) - (uint32)(503316449))) - (uint32)((((uint32)(r_u32(0x1F800010)) - (uint32)(1)) >> 3)))) + (uint32)((sint32)((uint32)(((sint32)(r_u32(0x1F800008)) >> 3)) << (uint32)(10))));
            w_u32(v25, v28);
            w_u32((v25 + (2) * 4u), (sint32)((uint32)(v30) + (uint32)((sint32)((uint32)((v29 >> 3)) << (uint32)(15)))));
            w_u32((uint32)(v24), ((r_u32((uint32)(v24)) & v6) | (v26 & 0xFFFFFF)));
            v2 = v26;
            w_u32((uint32)(v26), 0x2000000);
            w_u32((uint32)((sint32)((uint32)(v26) + (uint32)(8))), (0u - (uint32)(503316480)));
            w_u32((uint32)((sint32)((uint32)(v26) + (uint32)(4))), (0u - (uint32)(520093184)));
          }
          else
          {
            v24 = v1;
            v1 += 40;
            w_u32((uint32)(v2), ((r_u32((uint32)(v2)) & v6) | (v24 & 0xFFFFFF)));
            v2 = v24;
          }
          w_u16((uint32)((sint32)((uint32)(v24) + (uint32)(14))), (uint16)((v23) >> 16));
          w_u16((uint32)((sint32)((uint32)(v24) + (uint32)(22))), v23);
          if (((v22 & 0x80) != 0))
          {
            normal_second = (sint32)((uint32)(v84) + (uint32)((sint32)((uint32)(12) * (uint32)(r_u16(v3)))));
            xport_gte_write_data(0u, r_u32(normal_second));
            xport_gte_write_data(1u, r_u32(normal_second + 4u));
            xport_gte_write_data(6u, r_u32(0x1F800004u));
            xport_gte_execute(0x108041Bu);
          }
          else
          {
            w_u32((uint32)((sint32)((uint32)(v24) + (uint32)(4))), 8355711);
          }
          w_u32((uint32)((sint32)((uint32)(v24) + (uint32)(8))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(r_u16(v19)))) + (uint32)(v4)))));
          w_u32((uint32)((sint32)((uint32)(v24) + (uint32)(16))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(r_u16((v19 + (1) * 2u))))) + (uint32)(v4)))));
          w_u32((uint32)((sint32)((uint32)(v24) + (uint32)(32))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(r_u16((v19 + (2) * 2u))))) + (uint32)(v4)))));
          w_u32((uint32)((sint32)((uint32)(v24) + (uint32)(24))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(r_u16((v19 + (3) * 2u))))) + (uint32)(v4)))));
          w_u16((uint32)((sint32)((uint32)(v24) + (uint32)(12))), r_u16((primitive_data + (4) * 2u)));
          w_u16((uint32)((sint32)((uint32)(v24) + (uint32)(20))), r_u16((primitive_data + (5) * 2u)));
          w_u16((uint32)((sint32)((uint32)(v24) + (uint32)(36))), r_u16((primitive_data + (6) * 2u)));
          w_u16((uint32)((sint32)((uint32)(v24) + (uint32)(28))), r_u16((primitive_data + (7) * 2u)));
          v33 = (v22 & 0x100);
          if (((v22 & 0x80) != 0))
          {
            w_u32((uint32)v24 + 4u, xport_gte_read_data(22u));
            v33 = (v22 & 0x100);
          }
          w_u8((uint32)((sint32)((uint32)(v24) + (uint32)(3))), 9);
          if (v33)
            w_u8((uint32)((sint32)((uint32)(v24) + (uint32)(7))), 46);
          else
            w_u8((uint32)((sint32)((uint32)(v24) + (uint32)(7))), 44);
        }
        else
        {
          v34 = r_u32((uint32)(primitive_data));
          if (((v22 & 0x200) != 0))
          {
            v35 = (sint32)((uint32)(v1) + (uint32)(12));
            w_u32((uint32)(v2), ((r_u32((uint32)(v2)) & v6) | (v1 & 0xFFFFFF)));
            v36 = (uint32)(v1);
            w_u32(0x1F800008, r_u8(((uint32)(primitive_data) + (16) * 1u)));
            v37 = (sint32)((uint32)(v1) + (uint32)(44));
            w_u32(0x1F80000C, r_u8(((uint32)(primitive_data) + (17) * 1u)));
            v38 = ((sint32)((uint32)(v1) + (uint32)(12)) & 0xFFFFFF);
            w_u32(0x1F800010, r_u8(((uint32)(primitive_data) + (18) * 1u)));
            v1 += 56;
            w_u32(0x1F800014, r_u8(((uint32)(primitive_data) + (19) * 1u)));
            w_u32(v36, 0x2000000);
            v39 = (((sint32)r_u32(v36) & v6) | v38);
            w_u32((v36 + (1) * 4u), ((uint32)((uint16)(v34)) - (uint32)(520093184)));
            v40 = r_u32(0x1F80000C);
            v41 = (sint32)((uint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(32) * (uint32)((sint32)((uint32)(31) - (uint32)((((uint32)(r_u32(0x1F800014)) - (uint32)(1)) >> 3)))))) - (uint32)(503316449))) - (uint32)((((uint32)(r_u32(0x1F800010)) - (uint32)(1)) >> 3)))) + (uint32)((sint32)((uint32)(((sint32)(r_u32(0x1F800008)) >> 3)) << (uint32)(10))));
            w_u32(v36, v39);
            w_u32((v36 + (2) * 4u), (sint32)((uint32)(v41) + (uint32)((sint32)((uint32)((v40 >> 3)) << (uint32)(15)))));
            w_u32((uint32)(v35), ((r_u32((uint32)(v35)) & v6) | (v37 & 0xFFFFFF)));
            v2 = v37;
            w_u32((uint32)(v37), 0x2000000);
            w_u32((uint32)((sint32)((uint32)(v37) + (uint32)(8))), (0u - (uint32)(503316480)));
            w_u32((uint32)((sint32)((uint32)(v37) + (uint32)(4))), (0u - (uint32)(520093184)));
          }
          else
          {
            v35 = v1;
            v1 += 32;
            w_u32((uint32)(v2), ((r_u32((uint32)(v2)) & v6) | (v35 & 0xFFFFFF)));
            v2 = v35;
          }
          w_u16((uint32)((sint32)((uint32)(v35) + (uint32)(14))), (uint16)((v34) >> 16));
          w_u16((uint32)((sint32)((uint32)(v35) + (uint32)(22))), v34);
          if (((v22 & 0x80) != 0))
          {
            normal_second = (sint32)((uint32)(v84) + (uint32)((sint32)((uint32)(12) * (uint32)(r_u16(v3)))));
            xport_gte_write_data(0u, r_u32(normal_second));
            xport_gte_write_data(1u, r_u32(normal_second + 4u));
            xport_gte_write_data(6u, r_u32(0x1F800004u));
            xport_gte_execute(0x108041Bu);
          }
          else
          {
            w_u32((uint32)((sint32)((uint32)(v35) + (uint32)(4))), 8355711);
          }
          w_u32((uint32)((sint32)((uint32)(v35) + (uint32)(8))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(r_u16(v19)))) + (uint32)(v4)))));
          w_u32((uint32)((sint32)((uint32)(v35) + (uint32)(16))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(r_u16((v19 + (1) * 2u))))) + (uint32)(v4)))));
          w_u32((uint32)((sint32)((uint32)(v35) + (uint32)(24))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(r_u16((v19 + (2) * 2u))))) + (uint32)(v4)))));
          w_u16((uint32)((sint32)((uint32)(v35) + (uint32)(12))), r_u16((primitive_data + (4) * 2u)));
          w_u16((uint32)((sint32)((uint32)(v35) + (uint32)(20))), r_u16((primitive_data + (5) * 2u)));
          w_u16((uint32)((sint32)((uint32)(v35) + (uint32)(28))), r_u16((primitive_data + (6) * 2u)));
          v44 = (v22 & 0x100);
          if (((v22 & 0x80) != 0))
          {
            w_u32((uint32)v35 + 4u, xport_gte_read_data(22u));
            v44 = (v22 & 0x100);
          }
          w_u8((uint32)((sint32)((uint32)(v35) + (uint32)(3))), 7);
          if (v44)
            w_u8((uint32)((sint32)((uint32)(v35) + (uint32)(7))), 38);
          else
            w_u8((uint32)((sint32)((uint32)(v35) + (uint32)(7))), 36);
        }
        goto LABEL_81;
      }
      if (((v22 & 4) != 0))
      {
        if ((((v22 & 0x80) == 0) || !(sint16)r_u16(0x800775A6u)))
        {
          v55 = v1;
          if ((v17 == 4))
          {
            w_u32((uint32)(v2), ((r_u32((uint32)(v2)) & v6) | (v1 & 0xFFFFFF)));
            v2 = v1;
            w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(8))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(r_u16(v19)))) + (uint32)(v4)))));
            w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(16))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)(r_u16((v18 + (3) * 2u)))))) + (uint32)(v4)))));
            w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(32))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)(r_u16((v18 + (4) * 2u)))))) + (uint32)(v4)))));
            v1 += 36;
            w_u32((uint32)((sint32)((uint32)(v55) + (uint32)(24))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)(r_u16((v18 + (5) * 2u)))))) + (uint32)(v4)))));
            v56 = (v18 + (6) * 2u);
            if (((v22 & 0x80) != 0))
            {
              v90 = v6;
              ob_draft_unresolved_call(0x8005f59cu, 3u, (sint32)((uint32)(v84) + (uint32)((sint32)((uint32)(12) * (uint32)(r_u16(v3))))), primitive_data, (sint32)((uint32)(v55) + (uint32)(12)));
              v57 = r_u8((uint32)((sint32)((uint32)(v55) + (uint32)(12))));
              v58 = r_u8((uint32)((sint32)((uint32)(v55) + (uint32)(13))));
              v59 = r_u8((uint32)((sint32)((uint32)(v55) + (uint32)(14))));
              v6 = v90;
            }
            else
            {
              v57 = r_u8(((uint32)(v18) + (12) * 1u));
              v58 = r_u8(((uint32)(v18) + (13) * 1u));
              v59 = r_u8(((uint32)(v18) + (14) * 1u));
            }
            v60 = (sint16)r_u16((v56 + (2) * 2u));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(4))), ((sint32)((uint32)(v60) * (uint32)(v57)) >> 4));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(5))), ((sint32)((uint32)(v60) * (uint32)(v58)) >> 4));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(6))), ((sint32)((uint32)(v60) * (uint32)(v59)) >> 4));
            v61 = (sint16)r_u16((v56 + (3) * 2u));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(12))), ((sint32)((uint32)(v61) * (uint32)(v57)) >> 4));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(13))), ((sint32)((uint32)(v61) * (uint32)(v58)) >> 4));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(14))), ((sint32)((uint32)(v61) * (uint32)(v59)) >> 4));
            v62 = (sint16)r_u16((v56 + (4) * 2u));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(28))), ((sint32)((uint32)(v62) * (uint32)(v57)) >> 4));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(29))), ((sint32)((uint32)(v62) * (uint32)(v58)) >> 4));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(30))), ((sint32)((uint32)(v62) * (uint32)(v59)) >> 4));
            v63 = (sint16)r_u16((v56 + (5) * 2u));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(20))), ((sint32)((uint32)(v63) * (uint32)(v57)) >> 4));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(21))), ((sint32)((uint32)(v63) * (uint32)(v58)) >> 4));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(22))), ((sint32)((uint32)(v63) * (uint32)(v59)) >> 4));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(3))), 8);
            if (((v22 & 0x100) != 0))
              w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(7))), 58);
            else
              w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(7))), 56);
          }
          else
          {
            w_u32((uint32)(v2), ((r_u32((uint32)(v2)) & v6) | (v1 & 0xFFFFFF)));
            v2 = v1;
            w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(8))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(r_u16(v19)))) + (uint32)(v4)))));
            w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(16))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)(r_u16((v18 + (3) * 2u)))))) + (uint32)(v4)))));
            v1 += 28;
            w_u32((uint32)((sint32)((uint32)(v55) + (uint32)(24))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)(r_u16((v18 + (4) * 2u)))))) + (uint32)(v4)))));
            v64 = (v18 + (5) * 2u);
            if (((v22 & 0x80) != 0))
            {
              v91 = v6;
              ob_draft_unresolved_call(0x8005f59cu, 3u, (sint32)((uint32)(v84) + (uint32)((sint32)((uint32)(12) * (uint32)(r_u16(v3))))), primitive_data, (sint32)((uint32)(v55) + (uint32)(12)));
              v65 = r_u8((uint32)((sint32)((uint32)(v55) + (uint32)(12))));
              v66 = r_u8((uint32)((sint32)((uint32)(v55) + (uint32)(13))));
              v67 = r_u8((uint32)((sint32)((uint32)(v55) + (uint32)(14))));
              v6 = v91;
            }
            else
            {
              v65 = r_u8(((uint32)(v18) + (10) * 1u));
              v66 = r_u8(((uint32)(v18) + (11) * 1u));
              v67 = r_u8(((uint32)(v18) + (12) * 1u));
            }
            v68 = (sint16)r_u16((v64 + (2) * 2u));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(4))), ((sint32)((uint32)(v68) * (uint32)(v65)) >> 4));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(5))), ((sint32)((uint32)(v68) * (uint32)(v66)) >> 4));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(6))), ((sint32)((uint32)(v68) * (uint32)(v67)) >> 4));
            v69 = (sint16)r_u16((v64 + (3) * 2u));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(12))), ((sint32)((uint32)(v69) * (uint32)(v65)) >> 4));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(13))), ((sint32)((uint32)(v69) * (uint32)(v66)) >> 4));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(14))), ((sint32)((uint32)(v69) * (uint32)(v67)) >> 4));
            v70 = (sint16)r_u16((v64 + (4) * 2u));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(20))), ((sint32)((uint32)(v70) * (uint32)(v65)) >> 4));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(21))), ((sint32)((uint32)(v70) * (uint32)(v66)) >> 4));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(22))), ((sint32)((uint32)(v70) * (uint32)(v67)) >> 4));
            w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(3))), 6);
            if (((v22 & 0x100) != 0))
              w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(7))), 50);
            else
              w_u8((uint32)((sint32)((uint32)(v55) + (uint32)(7))), 48);
          }
          goto LABEL_81;
        }
        if ((v17 == 4))
        {
          normal_first = (sint32)((uint32)(v85) + (uint32)((sint32)((uint32)(8) * (uint32)((uint16)(r_u16((primitive_data + (6) * 2u)))))));
          normal_second = (sint32)((uint32)(v85) + (uint32)((sint32)((uint32)(8) * (uint32)((uint16)(r_u16((primitive_data + (7) * 2u)))))));
          normal_third = (sint32)((uint32)(v85) + (uint32)((sint32)((uint32)(8) * (uint32)((uint16)(r_u16((primitive_data + (8) * 2u)))))));
          xport_gte_write_data(0u, r_u32(normal_first));
          xport_gte_write_data(1u, r_u32(normal_first + 4u));
          xport_gte_write_data(2u, r_u32(normal_second));
          xport_gte_write_data(3u, r_u32(normal_second + 4u));
          xport_gte_write_data(4u, r_u32(normal_third));
          xport_gte_write_data(5u, r_u32(normal_third + 4u));
          xport_gte_write_data(6u, r_u32(primitive_data));
          xport_gte_execute(0x118043Fu);
          w_u32((uint32)(v2), ((r_u32((uint32)(v2)) & v6) | (v1 & 0xFFFFFF)));
          v2 = v1;
          w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(8))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)(r_u16((v18 + (2) * 2u)))))) + (uint32)(v4)))));
          w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(16))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)(r_u16((v18 + (3) * 2u)))))) + (uint32)(v4)))));
          w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(32))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)(r_u16((v18 + (4) * 2u)))))) + (uint32)(v4)))));
          v1 += 36;
          w_u32((uint32)((sint32)((uint32)(v2) + (uint32)(24))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)(r_u16((v18 + (5) * 2u)))))) + (uint32)(v4)))));
          w_u32((uint32)v2 + 4u, xport_gte_read_data(20u));
          w_u32((uint32)v2 + 12u, xport_gte_read_data(21u));
          w_u32((uint32)v2 + 28u, xport_gte_read_data(22u));
          normal_third = (sint32)((uint32)(v85) + (uint32)((sint32)((uint32)(8) * (uint32)((uint16)(r_u16((primitive_data + (9) * 2u)))))));
          xport_gte_write_data(0u, r_u32(normal_third));
          xport_gte_write_data(1u, r_u32(normal_third + 4u));
          xport_gte_write_data(6u, r_u32(primitive_data));
          xport_gte_execute(0x108041Bu);
          w_u32((uint32)v2 + 20u, xport_gte_read_data(22u));
          w_u8((uint32)((sint32)((uint32)(v2) + (uint32)(3))), 8);
          if (((v22 & 0x100) != 0))
            v50 = 58;
          else
            v50 = 56;
        }
        else
        {
          v51 = ((primitive_data + (((uint32)(v17) + (uint32)(2))) * 2u));
          normal_first = (sint32)((uint32)(v85) + (uint32)((sint32)((uint32)(8) * (uint32)(r_u16(v51)))));
          normal_second = (sint32)((uint32)(v85) + (uint32)((sint32)((uint32)(8) * (uint32)(r_u16((v51 + (1) * 2u))))));
          normal_third = (sint32)((uint32)(v85) + (uint32)((sint32)((uint32)(8) * (uint32)(r_u16((v51 + (2) * 2u))))));
          xport_gte_write_data(0u, r_u32(normal_first));
          xport_gte_write_data(1u, r_u32(normal_first + 4u));
          xport_gte_write_data(2u, r_u32(normal_second));
          xport_gte_write_data(3u, r_u32(normal_second + 4u));
          xport_gte_write_data(4u, r_u32(normal_third));
          xport_gte_write_data(5u, r_u32(normal_third + 4u));
          xport_gte_write_data(6u, r_u32(primitive_data));
          xport_gte_execute(0x118043Fu);
          w_u32((uint32)(v2), ((r_u32((uint32)(v2)) & v6) | (v1 & 0xFFFFFF)));
          v2 = v1;
          w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(8))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)(r_u16((v18 + (2) * 2u)))))) + (uint32)(v4)))));
          w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(16))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)(r_u16((v18 + (3) * 2u)))))) + (uint32)(v4)))));
          v1 += 28;
          w_u32((uint32)((sint32)((uint32)(v2) + (uint32)(24))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)(r_u16((v18 + (4) * 2u)))))) + (uint32)(v4)))));
          w_u32((uint32)v2 + 4u, xport_gte_read_data(20u));
          w_u32((uint32)v2 + 12u, xport_gte_read_data(21u));
          w_u32((uint32)v2 + 20u, xport_gte_read_data(22u));
          w_u8((uint32)((sint32)((uint32)(v2) + (uint32)(3))), 6);
          if (((v22 & 0x100) != 0))
            v50 = 50;
          else
            v50 = 48;
        }
        goto LABEL_80;
      }
      if (((v22 & 1) != 0))
      {
        if ((v17 == 4))
        {
          v71 = v1;
          if (((v22 & 0x4000) != 0))
          {
            w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(4))), 0xFFFFFF);
          }
          else
            if (((v22 & 0x80) != 0))
          {
            normal_third = (sint32)((uint32)(v84) + (uint32)((sint32)((uint32)(12) * (uint32)(v7))));
            xport_gte_write_data(0u, r_u32(normal_third));
            xport_gte_write_data(1u, r_u32(normal_third + 4u));
            xport_gte_write_data(6u, r_u32(primitive_data));
            xport_gte_execute(0x108041Bu);
          }
          else
          {
            w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(4))), r_u32((uint32)(primitive_data)));
          }
          w_u32((uint32)(v2), ((r_u32((uint32)(v2)) & v6) | (v1 & 0xFFFFFF)));
          v2 = v1;
          w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(8))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(r_u16(v19)))) + (uint32)(v4)))));
          w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(12))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)(r_u16((v18 + (3) * 2u)))))) + (uint32)(v4)))));
          w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(20))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)(r_u16((v18 + (4) * 2u)))))) + (uint32)(v4)))));
          w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(16))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)(r_u16((v18 + (5) * 2u)))))) + (uint32)(v4)))));
          v1 += 24;
          if (((v22 & 0x80) != 0))
            w_u32((uint32)v2 + 4u, xport_gte_read_data(22u));
          w_u8((uint32)((sint32)((uint32)(v71) + (uint32)(3))), 5);
          if (((v22 & 0x100) != 0))
            v50 = 42;
          else
            v50 = 40;
        }
        else
        {
          v73 = v1;
          if (((v22 & 0x4000) != 0))
          {
            w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(4))), 0xFFFFFF);
          }
          else
            if (((v22 & 0x80) != 0))
          {
            normal_third = (sint32)((uint32)(v84) + (uint32)((sint32)((uint32)(12) * (uint32)(v7))));
            xport_gte_write_data(0u, r_u32(normal_third));
            xport_gte_write_data(1u, r_u32(normal_third + 4u));
            xport_gte_write_data(6u, r_u32(primitive_data));
            xport_gte_execute(0x108041Bu);
          }
          else
          {
            w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(4))), r_u32((uint32)(primitive_data)));
          }
          w_u32((uint32)(v2), ((r_u32((uint32)(v2)) & v6) | (v1 & 0xFFFFFF)));
          v2 = v1;
          w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(8))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(r_u16(v19)))) + (uint32)(v4)))));
          w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(12))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)(r_u16((v18 + (3) * 2u)))))) + (uint32)(v4)))));
          w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(16))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)(r_u16((v18 + (4) * 2u)))))) + (uint32)(v4)))));
          v1 += 20;
          if (((v22 & 0x80) != 0))
            w_u32((uint32)v2 + 4u, xport_gte_read_data(22u));
          w_u8((uint32)((sint32)((uint32)(v73) + (uint32)(3))), 4);
          if (((v22 & 0x100) != 0))
            v50 = 34;
          else
            v50 = 32;
        }
        LABEL_80:
        w_u8((uint32)((sint32)((uint32)(v2) + (uint32)(7))), v50);

      }
    }
    LABEL_81:
    v14 = v86;

    ((v3 += 2u));
    goto LABEL_82;
  }
  LABEL_83:
  v75 = r_u32((uint32)(v2));

  result = (0u - (uint32)(16777216));
  w_u32(0x800774A8u, v1);
  w_u32(0x80077634u, v2);
  w_u32((uint32)(v2), ((v75 & 0xFF000000) | (v87 & 0xFFFFFF)));
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


sint32 sub_80051974(void)
{
    FUNCTION_MARKER(0x80051974u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8004E70C */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    uint32 local_objects = ob_draft_scratch_acquire(1282u);
  sint32 result;
  sint32 v1;
  sint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  uint32 v11;
  uint32 v12;
  sint32 v13;
  sint32 v14;
  sint32 v15;
  sint32 v16;
  sint32 v17;
  sint16 v18;
  sint16 v19;
  sint32 v20;
  sint32 v21;
  sint32 v22;
  sint32 v23;
  uint32 v24;
  sint32 v25;
  sint32 v26;
  sint32 v27;
  uint32 v28;
  sint32 v29;
  sint32 v30;
  sint16 v31;
  sint16 v32;
  sint32 v33;
  uint32 v34;
  sint32 v35;
  uint32 v36;
  sint32 v37;
  uint32 v38;
  sint32 v39;
  uint32 v40;
  sint32 v41;
  sint32 v42;
  sint16 v43;
  sint32 v44;
  sint32 v45;
  sint32 v46;
  sint32 v47;
  uint32 v48;
  sint32 v49;
  sint32 v50;
  uint32 v51;
  sint32 v52;
  uint32 v53;
  sint32 v54;
  sint32 v55;
  sint16 v56;
  sint32 v57;
  sint32 v58;
  sint32 v59;
  sint32 v60;
  sint32 v61;
  sint32 v62;
  sint32 v63;
  uint32 v64;
  uint32 v65;
  sint32 v66;
  sint32 v67;
  sint32 v68;
  sint32 v69;
  sint32 v70;
  sint16 v71;
  sint16 v72;
  sint32 v73;
  sint32 v74;
  sint32 v75;
  sint32 v76;
  uint32 v77;
  sint32 v78;
  sint32 v79;
  sint32 v80;
  uint32 v81;
  sint32 v82;
  sint32 v83;
  sint16 v84;
  sint16 v85;
  sint32 v86;
  uint32 v87;
  sint32 v88;
  sint32 v89;
  uint32 v90;
  sint32 v91;
  uint32 v92;
  sint32 v93;
  sint32 v94;
  sint16 v95;
  sint32 v96;
  sint32 v97;
  sint32 v98;
  sint32 v99;
  uint32 v100;
  sint32 v101;
  sint32 v102;
  uint32 v103;
  sint32 v104;
  uint32 v105;
  sint32 v106;
  sint32 v107;
  sint16 v108;
  sint32 v109;
  sint32 v110;
  sint32 v111;
  sint32 v112;
  sint32 v113;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  uint16 v150;
  sint16 v151;
  sint16 v152;
  uint32 v153;
  uint32 v154;
  sint32 v155;
  uint32 v156;
  uint32 v157;
  uint32 v158;
  sint32 v159;
  uint32 v160;
  result = (sint32)r_u32(0x800774F4u);
  if ((sint32)r_u32(0x800774F4u))
  {
    result = (sint32)r_u32(0x8006C214u);
    if ((sint32)r_u32(0x8006C214u))
    {
      ob_draft_unresolved_call(0x8004e70cu, 0u);
      if ((sint32)r_u32(0x800771D0u))
        sub_8004A908(8u);
      v1 = r_u32((uint32)((sint32)r_u32(0x800774F4u)));
      if (((sint32)r_u32((uint32)((sint32)r_u32(0x800774F4u))) >= 0))
        w_u32(local_objects + 0u, (sint32)((uint32)(7500) * (uint32)((v1 / 7500))));
      else
        w_u32(local_objects + 0u, (sint32)((uint32)((sint32)((uint32)(v1) + (uint32)(((0u - (uint32)(v1)) % 7500)))) - (uint32)(7500)));
      v2 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800774F4u)) + (uint32)(8))));
      if ((v2 >= 0))
        w_u32(local_objects + 8u, (sint32)((uint32)(7500) * (uint32)((v2 / 7500))));
      else
        w_u32(local_objects + 8u, (sint32)((uint32)((sint32)((uint32)(v2) + (uint32)(((0u - (uint32)(v2)) % 7500)))) - (uint32)(7500)));
      w_u32(local_objects + 4u, 0);
      if ((sint32)r_u32(0x800771D0u))
      {
        if ((r_u32(0x800C4D04) >= 0))
          w_u32(local_objects + 8u, (sint32)((uint32)(7500) * (uint32)((r_u32(0x800C4D04) / 7500))));
        else
          w_u32(local_objects + 8u, ((uint32)(((uint32)(r_u32(0x800C4D04)) + (uint32)(((0u - (uint32)(r_u32(0x800C4D04))) % 7500)))) - (uint32)(7500)));
      }
      sub_8004EEF4((local_objects + 0u), (sint32)((local_objects + 128u)));
      w_u32(local_objects + 20u, (sint32)r_u32(local_objects + 4u));
      w_u32(local_objects + 24u, (sint32)r_u32(local_objects + 8u));
      w_u32(local_objects + 16u, (sint32)((uint32)((sint32)r_u32(local_objects + 0u)) + (uint32)(7500)));
      sub_8004EEF4((local_objects + 16u), (sint32)((local_objects + 384u)));
      w_u32(local_objects + 32u, (sint32)r_u32(local_objects + 0u));
      w_u32(local_objects + 36u, (sint32)r_u32(local_objects + 4u));
      w_u32(local_objects + 40u, (sint32)((uint32)((sint32)r_u32(local_objects + 8u)) + (uint32)(7500)));
      sub_8004EEF4((local_objects + 32u), (sint32)((local_objects + 640u)));
      w_u32(local_objects + 52u, (sint32)r_u32(local_objects + 36u));
      w_u32(local_objects + 56u, (sint32)r_u32(local_objects + 40u));
      w_u32(local_objects + 48u, (sint32)((uint32)((sint32)r_u32(local_objects + 32u)) + (uint32)(7500)));
      sub_8004EEF4((local_objects + 48u), (sint32)((local_objects + 896u)));
      sub_8004E9E4((local_objects + 128u), (local_objects + 384u), (local_objects + 640u), (local_objects + 896u));
      sub_80053D20((sint32)r_u32(local_objects + 32u), (sint32)r_u32(local_objects + 40u));
      w_u32(local_objects + 64u, (sint32)r_u32(local_objects + 0u));
      w_u32(local_objects + 68u, (sint32)r_u32(local_objects + 4u));
      w_u32(local_objects + 72u, (sint32)r_u32(local_objects + 8u));
      w_u32(local_objects + 96u, (sint32)r_u32(local_objects + 32u));
      w_u32(local_objects + 100u, (sint32)r_u32(local_objects + 36u));
      w_u32(local_objects + 104u, (sint32)r_u32(local_objects + 40u));
      v3 = 1;
      do
      {
        v4 = v3;
        v5 = ((sint32)((uint32)(v3) << (uint32)(16)) >> 14);
        w_u32(local_objects + 64u, ((uint32)((sint32)r_u32(local_objects + 64u)) - (uint32)(7500)));
        w_u32(local_objects + 96u, ((uint32)((sint32)r_u32(local_objects + 96u)) - (uint32)(7500)));
        sub_8004EEF4((local_objects + 64u), (sint32)((uint32)((sint32)((local_objects + 128u))) + (uint32)(v5)));
        sub_8004EEF4((local_objects + 96u), (sint32)((uint32)((sint32)((local_objects + 640u))) + (uint32)(v5)));
        if (((uint32)(sub_8004E9E4((uint32)(((uint32)((local_objects + 128u)) + (v5) * 1u)), (uint32)(((uint32)((((local_objects + 128u) + ((0u - (uint32)(2))) * 2u))) + (v5) * 1u)), (uint32)(((uint32)((local_objects + 640u)) + (v5) * 1u)), (uint32)(((uint32)((((local_objects + 640u) + ((0u - (uint32)(2))) * 2u))) + (v5) * 1u)))) << (uint32)(16)))
          break;
        v3 = (sint32)((uint32)(v4) + (uint32)(1));
      }
      while (sub_80053D20((sint32)r_u32(local_objects + 96u), (sint32)r_u32(local_objects + 104u)));
      w_u16(((local_objects + 896u) + (128) * 2u), v4);
      w_u32(((local_objects + 1160u) + (0) * 4u), (sint32)r_u32(local_objects + 64u));
      w_u32(((local_objects + 1160u) + (1) * 4u), (sint32)r_u32(local_objects + 68u));
      w_u32(((local_objects + 1160u) + (2) * 4u), (sint32)r_u32(local_objects + 72u));
      w_u16(local_objects + 1216u, v4);
      w_u32(((local_objects + 1224u) + (0) * 4u), (sint32)r_u32(local_objects + 96u));
      w_u32(((local_objects + 1224u) + (1) * 4u), (sint32)r_u32(local_objects + 100u));
      w_u32(((local_objects + 1224u) + (2) * 4u), (sint32)r_u32(local_objects + 104u));
      w_u32(local_objects + 80u, (sint32)r_u32(local_objects + 16u));
      w_u32(local_objects + 84u, (sint32)r_u32(local_objects + 20u));
      w_u32(local_objects + 88u, (sint32)r_u32(local_objects + 24u));
      w_u32(local_objects + 112u, (sint32)r_u32(local_objects + 48u));
      w_u32(local_objects + 116u, (sint32)r_u32(local_objects + 52u));
      w_u32(local_objects + 120u, (sint32)r_u32(local_objects + 56u));
      v6 = 1;
      do
      {
        v7 = v6;
        v8 = ((sint32)((uint32)(v6) << (uint32)(16)) >> 14);
        w_u32(local_objects + 80u, ((uint32)((sint32)r_u32(local_objects + 80u)) + (uint32)(7500)));
        w_u32(local_objects + 112u, ((uint32)((sint32)r_u32(local_objects + 112u)) + (uint32)(7500)));
        sub_8004EEF4((local_objects + 80u), (sint32)((uint32)((sint32)((local_objects + 384u))) + (uint32)(v8)));
        sub_8004EEF4((local_objects + 112u), (sint32)((uint32)((sint32)((local_objects + 896u))) + (uint32)(v8)));
        if (((uint32)(sub_8004E9E4((uint32)(((uint32)((((local_objects + 384u) + ((0u - (uint32)(2))) * 2u))) + (v8) * 1u)), (uint32)(((uint32)((local_objects + 384u)) + (v8) * 1u)), (uint32)(((uint32)((((local_objects + 896u) + ((0u - (uint32)(2))) * 2u))) + (v8) * 1u)), (uint32)(((uint32)((local_objects + 896u)) + (v8) * 1u)))) << (uint32)(16)))
          break;
        v6 = (sint32)((uint32)(v7) + (uint32)(1));
      }
      while (sub_80053D20((sint32)((uint32)((sint32)r_u32(local_objects + 112u)) - (uint32)(7500)), (sint32)r_u32(local_objects + 56u)));
      w_u16(local_objects + 1184u, v7);
      w_u32(((local_objects + 1192u) + (0) * 4u), (sint32)r_u32(local_objects + 80u));
      w_u32(((local_objects + 1192u) + (1) * 4u), (sint32)r_u32(local_objects + 84u));
      w_u32(((local_objects + 1192u) + (2) * 4u), (sint32)r_u32(local_objects + 88u));
      w_u16(local_objects + 1248u, v7);
      w_u32(((local_objects + 1256u) + (0) * 4u), (sint32)r_u32(local_objects + 112u));
      w_u32(((local_objects + 1256u) + (1) * 4u), (sint32)r_u32(local_objects + 116u));
      w_u32(((local_objects + 1256u) + (2) * 4u), (sint32)r_u32(local_objects + 120u));
      v150 = 1;
      v153 = (local_objects + 128u);
      w_u16(local_objects + 1280u, 0);
      v154 = (local_objects + 384u);
      do
      {
        v9 = v150;
        v10 = ((uint32)(v150) << (uint32)(7));
        w_u32(local_objects + 8u, ((uint32)((sint32)r_u32(local_objects + 8u)) - (uint32)(7500)));
        w_u32(local_objects + 24u, ((uint32)((sint32)r_u32(local_objects + 24u)) - (uint32)(7500)));
        v11 = (uint32)(((uint32)(v153) + (v10) * 1u));
        sub_8004EEF4((local_objects + 0u), (sint32)((uint32)((sint32)(v153)) + (uint32)(v10)));
        v12 = (uint32)(((uint32)(v154) + (v10) * 1u));
        sub_8004EEF4((local_objects + 16u), (sint32)(v12));
        v13 = r_u16(local_objects + 1280u);
        v14 = sub_8004E9E4(v11, v12, ((v153 + ((sint32)((uint32)(64) * (uint32)(r_u16(local_objects + 1280u)))) * 2u)), ((v154 + ((sint32)((uint32)(64) * (uint32)(r_u16(local_objects + 1280u)))) * 2u)));
        sub_80053D20((sint32)r_u32(local_objects + 0u), (sint32)((uint32)((sint32)r_u32(local_objects + 8u)) + (uint32)(7500)));
        if ((sint32)((uint32)(v14) << (uint32)(16)))
        {
          v151 = 0;
          v152 = 0;
          w_u32(local_objects + 64u, (sint32)r_u32(local_objects + 0u));
          w_u32(local_objects + 68u, (sint32)r_u32(local_objects + 4u));
          w_u32(local_objects + 72u, (sint32)r_u32(local_objects + 8u));
          v39 = v13;
          v40 = ((uint32)((local_objects + 0u)) + ((sint32)((uint32)(2) * (uint32)(v13))) * 1u);
          v41 = (sint32)((uint32)(3) * (uint32)(v13));
          v42 = 1;
          do
          {
            v43 = v42;
            v44 = (sint32)((uint32)(2) * (uint32)((sint16)(v42)));
            w_u32(local_objects + 64u, ((uint32)((sint32)r_u32(local_objects + 64u)) - (uint32)(7500)));
            sub_8004EEF4((local_objects + 64u), (sint32)(((v11 + (v44) * 2u))));
            if (((sint16)r_u16(((uint32)(v40) + (576) * 2u)) < (sint16)(v42)))
            {
              v45 = (sint32)(((v153 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v39))) + (uint32)(v44))) * 2u)));
              w_u32(((local_objects + 1160u) + (v41) * 4u), ((uint32)((sint32)r_u32(((local_objects + 1160u) + (v41) * 4u))) - (uint32)(7500)));
              sub_8004EEF4((((local_objects + 1160u) + (v41) * 4u)), v45);
            }
            v36 = (((uint32)(sub_8004E9E4(((v11 + (v44) * 2u)), ((v11 + ((sint32)((uint32)(v44) - (uint32)(2))) * 2u)), ((v153 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v39))) + (uint32)(v44))) * 2u)), ((v153 + ((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v39))) - (uint32)(2))) + (uint32)(v44))) * 2u)))) << (uint32)(16)) != 0);
            v46 = (sint32)((uint32)(v42) << (uint32)(16));
            if (!v36)
            {
              v36 = (sub_80053D20((sint32)r_u32(local_objects + 64u), (sint32)((uint32)((sint32)r_u32(local_objects + 72u)) + (uint32)(7500))) == 0);
              v46 = (sint32)((uint32)(v42) << (uint32)(16));
              if (!v36)
                ++v151;
            }
            ++v42;
          }
          while (((sint16)r_u16(((uint32)(v40) + (576) * 2u)) >= (v46 >> 16)));
          v47 = v150;
          v48 = ((local_objects + 0u) + ((sint32)((uint32)(3) * (uint32)(v150))) * 4u);
          w_u16((((uint32)((local_objects + 0u)) + (v150) * 2u) + (576) * 2u), v43);
          v49 = (sint32)r_u32(local_objects + 68u);
          v50 = (sint32)r_u32(local_objects + 72u);
          w_u32((v48 + (290) * 4u), (sint32)r_u32(local_objects + 64u));
          w_u32((v48 + (291) * 4u), v49);
          w_u32((v48 + (292) * 4u), v50);
          w_u32(local_objects + 80u, (sint32)r_u32(local_objects + 16u));
          w_u32(local_objects + 84u, (sint32)r_u32(local_objects + 20u));
          w_u32(local_objects + 88u, (sint32)r_u32(local_objects + 24u));
          v51 = ((v154 + ((sint32)((uint32)(64) * (uint32)(v47))) * 2u));
          v52 = r_u16(local_objects + 1280u);
          v53 = ((uint32)((local_objects + 0u)) + ((sint32)((uint32)(2) * (uint32)(r_u16(local_objects + 1280u)))) * 1u);
          v54 = (sint32)((uint32)(3) * (uint32)(r_u16(local_objects + 1280u)));
          v55 = 1;
          do
          {
            v56 = v55;
            v57 = (sint32)((uint32)(2) * (uint32)((sint16)(v55)));
            w_u32(local_objects + 80u, ((uint32)((sint32)r_u32(local_objects + 80u)) + (uint32)(7500)));
            sub_8004EEF4((local_objects + 80u), (sint32)(((v51 + (v57) * 2u))));
            if (((sint16)r_u16(((uint32)(v53) + (592) * 2u)) < (sint16)(v55)))
            {
              v58 = (sint32)(((v154 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v52))) + (uint32)(v57))) * 2u)));
              w_u32(((local_objects + 1192u) + (v54) * 4u), ((uint32)((sint32)r_u32(((local_objects + 1192u) + (v54) * 4u))) + (uint32)(7500)));
              sub_8004EEF4((((local_objects + 1192u) + (v54) * 4u)), v58);
            }
            v36 = (((uint32)(sub_8004E9E4(((v51 + ((sint32)((uint32)(v57) - (uint32)(2))) * 2u)), ((v51 + (v57) * 2u)), ((v154 + ((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v52))) - (uint32)(2))) + (uint32)(v57))) * 2u)), ((v154 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v52))) + (uint32)(v57))) * 2u)))) << (uint32)(16)) != 0);
            v59 = (sint32)((uint32)(v55) << (uint32)(16));
            if (!v36)
            {
              v36 = (sub_80053D20((sint32)((uint32)((sint32)r_u32(local_objects + 80u)) - (uint32)(7500)), (sint32)((uint32)((sint32)r_u32(local_objects + 88u)) + (uint32)(7500))) == 0);
              v59 = (sint32)((uint32)(v55) << (uint32)(16));
              if (!v36)
                ++v152;
            }
            ++v55;
          }
          while (((sint16)r_u16(((uint32)(v53) + (592) * 2u)) >= (v59 >> 16)));
          v38 = ((local_objects + 0u) + ((sint32)((uint32)(3) * (uint32)(v150))) * 4u);
          w_u16((((uint32)((local_objects + 0u)) + (v150) * 2u) + (592) * 2u), v56);
        }
        else
        {
          v151 = 1;
          v152 = 1;
          w_u32(local_objects + 64u, (sint32)r_u32(local_objects + 0u));
          w_u32(local_objects + 68u, (sint32)r_u32(local_objects + 4u));
          w_u32(local_objects + 72u, (sint32)r_u32(local_objects + 8u));
          v155 = v9;
          v15 = v13;
          v16 = (sint32)((uint32)(2) * (uint32)(v13));
          v17 = (sint32)((uint32)(3) * (uint32)(v13));
          v18 = 1;
          do
          {
            v19 = v18;
            v20 = (sint32)((uint32)(2) * (uint32)(v18));
            w_u32(local_objects + 64u, ((uint32)((sint32)r_u32(local_objects + 64u)) - (uint32)(7500)));
            sub_8004EEF4((local_objects + 64u), (sint32)(((v11 + (v20) * 2u))));
            if (((sint16)r_u16((uint32)((((uint32)((local_objects + 0u)) + (v16) * 1u) + (1152) * 1u))) < v18))
            {
              v21 = (sint32)(((v153 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v15))) + (uint32)(v20))) * 2u)));
              w_u32(((local_objects + 1160u) + (v17) * 4u), ((uint32)((sint32)r_u32(((local_objects + 1160u) + (v17) * 4u))) - (uint32)(7500)));
              sub_8004EEF4((((local_objects + 1160u) + (v17) * 4u)), v21);
            }
            if (((uint32)(sub_8004E9E4(((v11 + (v20) * 2u)), ((v11 + ((sint32)((uint32)(v20) - (uint32)(2))) * 2u)), ((v153 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v15))) + (uint32)(v20))) * 2u)), ((v153 + ((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v15))) - (uint32)(2))) + (uint32)(v20))) * 2u)))) << (uint32)(16)))
              break;
            ++v18;
          }
          while (sub_80053D20((sint32)r_u32(local_objects + 64u), (sint32)((uint32)((sint32)r_u32(local_objects + 72u)) + (uint32)(7500))));
          v22 = v155;
          v23 = (sint32)((uint32)(2) * (uint32)(v155));
          w_u16((((uint32)((local_objects + 0u)) + (v155) * 2u) + (576) * 2u), v19);
          v24 = (((local_objects + 0u) + (v23) * 4u) + (v22) * 4u);
          v25 = (sint32)r_u32(local_objects + 68u);
          v26 = (sint32)r_u32(local_objects + 72u);
          w_u32((v24 + (290) * 4u), (sint32)r_u32(local_objects + 64u));
          w_u32((v24 + (291) * 4u), v25);
          w_u32((v24 + (292) * 4u), v26);
          w_u32(local_objects + 80u, (sint32)r_u32(local_objects + 16u));
          w_u32(local_objects + 84u, (sint32)r_u32(local_objects + 20u));
          w_u32(local_objects + 88u, (sint32)r_u32(local_objects + 24u));
          v27 = v150;
          v28 = ((v154 + ((sint32)((uint32)(64) * (uint32)(v150))) * 2u));
          v29 = r_u16(local_objects + 1280u);
          v30 = (sint32)((uint32)(2) * (uint32)(r_u16(local_objects + 1280u)));
          v156 = (sint32)((uint32)(12) * (uint32)(r_u16(local_objects + 1280u)));
          v31 = 1;
          while (1)
          {
            v32 = v31;
            v33 = (sint32)((uint32)(2) * (uint32)(v31));
            w_u32(local_objects + 80u, ((uint32)((sint32)r_u32(local_objects + 80u)) + (uint32)(7500)));
            sub_8004EEF4((local_objects + 80u), (sint32)(((v28 + (v33) * 2u))));
            if (((sint16)r_u16((uint32)((((uint32)((local_objects + 0u)) + (v30) * 1u) + (1184) * 1u))) < v31))
            {
              v34 = (((local_objects + 1192u) + ((v156 / 4)) * 4u));
              v35 = (sint32)(((v154 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v29))) + (uint32)(v33))) * 2u)));
              w_u32(v34, (sint32)((uint32)((sint32)r_u32(((local_objects + 1192u) + ((v156 / 4)) * 4u))) + (uint32)(7500)));
              sub_8004EEF4(v34, v35);
            }
            v36 = (((uint32)(sub_8004E9E4(((v28 + ((sint32)((uint32)(v33) - (uint32)(2))) * 2u)), ((v28 + (v33) * 2u)), ((v154 + ((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v29))) - (uint32)(2))) + (uint32)(v33))) * 2u)), ((v154 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v29))) + (uint32)(v33))) * 2u)))) << (uint32)(16)) != 0);
            v37 = (sint32)((uint32)(2) * (uint32)(v27));
            if (v36)
              break;
            ++v31;
            if (!sub_80053D20((sint32)((uint32)((sint32)r_u32(local_objects + 80u)) - (uint32)(7500)), (sint32)((uint32)((sint32)r_u32(local_objects + 88u)) + (uint32)(7500))))
            {
              v37 = (sint32)((uint32)(2) * (uint32)(v27));
              break;
            }
          }

          w_u16((uint32)((((uint32)((local_objects + 0u)) + (v37) * 1u) + (1184) * 1u)), v32);
          v38 = (((local_objects + 0u) + (v37) * 4u) + (v27) * 4u);
        }
        v60 = (sint32)r_u32(local_objects + 84u);
        v61 = (sint32)r_u32(local_objects + 88u);
        w_u32((v38 + (298) * 4u), (sint32)r_u32(local_objects + 80u));
        w_u32((v38 + (299) * 4u), v60);
        w_u32((v38 + (300) * 4u), v61);
        v150 ^= 1u;
        w_u16(local_objects + 1280u, ((uint32)(r_u16(local_objects + 1280u)) ^ (uint32)(1u)));
      }
      while (((sint32)((uint32)(v151) + (uint32)(v152)) > 0));
      v150 = 1;
      v157 = (local_objects + 640u);
      w_u16(local_objects + 1280u, 0);
      v158 = (local_objects + 896u);
      do
      {
        v62 = v150;
        v63 = ((uint32)(v150) << (uint32)(7));
        w_u32(local_objects + 40u, ((uint32)((sint32)r_u32(local_objects + 40u)) + (uint32)(7500)));
        w_u32(local_objects + 56u, ((uint32)((sint32)r_u32(local_objects + 56u)) + (uint32)(7500)));
        v64 = (uint32)(((uint32)(v157) + (v63) * 1u));
        sub_8004EEF4((local_objects + 32u), (sint32)((uint32)((sint32)(v157)) + (uint32)(v63)));
        v65 = (uint32)(((uint32)(v158) + (v63) * 1u));
        sub_8004EEF4((local_objects + 48u), (sint32)(v65));
        v66 = r_u16(local_objects + 1280u);
        v67 = sub_8004E9E4(((v157 + ((sint32)((uint32)(64) * (uint32)(r_u16(local_objects + 1280u)))) * 2u)), ((v158 + ((sint32)((uint32)(64) * (uint32)(r_u16(local_objects + 1280u)))) * 2u)), v64, v65);
        sub_80053D20((sint32)r_u32(local_objects + 32u), (sint32)r_u32(local_objects + 40u));
        if ((sint32)((uint32)(v67) << (uint32)(16)))
        {
          v151 = 0;
          v152 = 0;
          w_u32(local_objects + 96u, (sint32)r_u32(local_objects + 32u));
          w_u32(local_objects + 100u, (sint32)r_u32(local_objects + 36u));
          w_u32(local_objects + 104u, (sint32)r_u32(local_objects + 40u));
          v91 = v66;
          v92 = ((uint32)((local_objects + 0u)) + ((sint32)((uint32)(2) * (uint32)(v66))) * 1u);
          v93 = (sint32)((uint32)(3) * (uint32)(v66));
          v94 = 1;
          do
          {
            v95 = v94;
            v96 = (sint32)((uint32)(2) * (uint32)((sint16)(v94)));
            w_u32(local_objects + 96u, ((uint32)((sint32)r_u32(local_objects + 96u)) - (uint32)(7500)));
            sub_8004EEF4((local_objects + 96u), (sint32)(((v64 + (v96) * 2u))));
            if (((sint16)r_u16(((uint32)(v92) + (608) * 2u)) < (sint16)(v94)))
            {
              v97 = (sint32)(((v157 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v91))) + (uint32)(v96))) * 2u)));
              w_u32(((local_objects + 1224u) + (v93) * 4u), ((uint32)((sint32)r_u32(((local_objects + 1224u) + (v93) * 4u))) - (uint32)(7500)));
              sub_8004EEF4((((local_objects + 1224u) + (v93) * 4u)), v97);
            }
            v36 = (((uint32)(sub_8004E9E4(((v157 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v91))) + (uint32)(v96))) * 2u)), ((v157 + ((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v91))) - (uint32)(2))) + (uint32)(v96))) * 2u)), ((v64 + (v96) * 2u)), ((v64 + ((sint32)((uint32)(v96) - (uint32)(2))) * 2u)))) << (uint32)(16)) != 0);
            v98 = (sint32)((uint32)(v94) << (uint32)(16));
            if (!v36)
            {
              v36 = (sub_80053D20((sint32)r_u32(local_objects + 96u), (sint32)r_u32(local_objects + 40u)) == 0);
              v98 = (sint32)((uint32)(v94) << (uint32)(16));
              if (!v36)
                ++v151;
            }
            ++v94;
          }
          while (((sint16)r_u16(((uint32)(v92) + (608) * 2u)) >= (v98 >> 16)));
          v99 = v150;
          v100 = ((local_objects + 0u) + ((sint32)((uint32)(3) * (uint32)(v150))) * 4u);
          w_u16((((uint32)((local_objects + 0u)) + (v150) * 2u) + (608) * 2u), v95);
          v101 = (sint32)r_u32(local_objects + 100u);
          v102 = (sint32)r_u32(local_objects + 104u);
          w_u32((v100 + (306) * 4u), (sint32)r_u32(local_objects + 96u));
          w_u32((v100 + (307) * 4u), v101);
          w_u32((v100 + (308) * 4u), v102);
          w_u32(local_objects + 112u, (sint32)r_u32(local_objects + 48u));
          w_u32(local_objects + 116u, (sint32)r_u32(local_objects + 52u));
          w_u32(local_objects + 120u, (sint32)r_u32(local_objects + 56u));
          v103 = ((v158 + ((sint32)((uint32)(64) * (uint32)(v99))) * 2u));
          v104 = r_u16(local_objects + 1280u);
          v105 = ((uint32)((local_objects + 0u)) + ((sint32)((uint32)(2) * (uint32)(r_u16(local_objects + 1280u)))) * 1u);
          v106 = (sint32)((uint32)(3) * (uint32)(r_u16(local_objects + 1280u)));
          v107 = 1;
          do
          {
            v108 = v107;
            v109 = (sint32)((uint32)(2) * (uint32)((sint16)(v107)));
            w_u32(local_objects + 112u, ((uint32)((sint32)r_u32(local_objects + 112u)) + (uint32)(7500)));
            sub_8004EEF4((local_objects + 112u), (sint32)(((v103 + (v109) * 2u))));
            if (((sint16)r_u16(((uint32)(v105) + (624) * 2u)) < (sint16)(v107)))
            {
              v110 = (sint32)(((v158 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v104))) + (uint32)(v109))) * 2u)));
              w_u32(((local_objects + 1256u) + (v106) * 4u), ((uint32)((sint32)r_u32(((local_objects + 1256u) + (v106) * 4u))) + (uint32)(7500)));
              sub_8004EEF4((((local_objects + 1256u) + (v106) * 4u)), v110);
            }
            v36 = (((uint32)(sub_8004E9E4(((v158 + ((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v104))) - (uint32)(2))) + (uint32)(v109))) * 2u)), ((v158 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v104))) + (uint32)(v109))) * 2u)), ((v103 + ((sint32)((uint32)(v109) - (uint32)(2))) * 2u)), ((v103 + (v109) * 2u)))) << (uint32)(16)) != 0);
            v111 = (sint32)((uint32)(v107) << (uint32)(16));
            if (!v36)
            {
              v36 = (sub_80053D20((sint32)((uint32)((sint32)r_u32(local_objects + 112u)) - (uint32)(7500)), (sint32)r_u32(local_objects + 56u)) == 0);
              v111 = (sint32)((uint32)(v107) << (uint32)(16));
              if (!v36)
                ++v152;
            }
            ++v107;
          }
          while (((sint16)r_u16(((uint32)(v105) + (624) * 2u)) >= (v111 >> 16)));
          v90 = ((local_objects + 0u) + ((sint32)((uint32)(3) * (uint32)(v150))) * 4u);
          w_u16((((uint32)((local_objects + 0u)) + (v150) * 2u) + (624) * 2u), v108);
        }
        else
        {
          v151 = 1;
          v152 = 1;
          w_u32(local_objects + 96u, (sint32)r_u32(local_objects + 32u));
          w_u32(local_objects + 100u, (sint32)r_u32(local_objects + 36u));
          w_u32(local_objects + 104u, (sint32)r_u32(local_objects + 40u));
          v159 = v62;
          v68 = v66;
          v69 = (sint32)((uint32)(2) * (uint32)(v66));
          v70 = (sint32)((uint32)(3) * (uint32)(v66));
          v71 = 1;
          do
          {
            v72 = v71;
            v73 = (sint32)((uint32)(2) * (uint32)(v71));
            w_u32(local_objects + 96u, ((uint32)((sint32)r_u32(local_objects + 96u)) - (uint32)(7500)));
            sub_8004EEF4((local_objects + 96u), (sint32)(((v64 + (v73) * 2u))));
            if (((sint16)r_u16((uint32)((((uint32)((local_objects + 0u)) + (v69) * 1u) + (1216) * 1u))) < v71))
            {
              v74 = (sint32)(((v157 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v68))) + (uint32)(v73))) * 2u)));
              w_u32(((local_objects + 1224u) + (v70) * 4u), ((uint32)((sint32)r_u32(((local_objects + 1224u) + (v70) * 4u))) - (uint32)(7500)));
              sub_8004EEF4((((local_objects + 1224u) + (v70) * 4u)), v74);
            }
            if (((uint32)(sub_8004E9E4(((v157 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v68))) + (uint32)(v73))) * 2u)), ((v157 + ((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v68))) - (uint32)(2))) + (uint32)(v73))) * 2u)), ((v64 + (v73) * 2u)), ((v64 + ((sint32)((uint32)(v73) - (uint32)(2))) * 2u)))) << (uint32)(16)))
              break;
            ++v71;
          }
          while (sub_80053D20((sint32)r_u32(local_objects + 96u), (sint32)r_u32(local_objects + 104u)));
          v75 = v159;
          v76 = (sint32)((uint32)(2) * (uint32)(v159));
          w_u16((((uint32)((local_objects + 0u)) + (v159) * 2u) + (608) * 2u), v72);
          v77 = (((local_objects + 0u) + (v76) * 4u) + (v75) * 4u);
          v78 = (sint32)r_u32(local_objects + 100u);
          v79 = (sint32)r_u32(local_objects + 104u);
          w_u32((v77 + (306) * 4u), (sint32)r_u32(local_objects + 96u));
          w_u32((v77 + (307) * 4u), v78);
          w_u32((v77 + (308) * 4u), v79);
          w_u32(local_objects + 112u, (sint32)r_u32(local_objects + 48u));
          w_u32(local_objects + 116u, (sint32)r_u32(local_objects + 52u));
          w_u32(local_objects + 120u, (sint32)r_u32(local_objects + 56u));
          v80 = v150;
          v81 = ((v158 + ((sint32)((uint32)(64) * (uint32)(v150))) * 2u));
          v82 = r_u16(local_objects + 1280u);
          v83 = (sint32)((uint32)(2) * (uint32)(r_u16(local_objects + 1280u)));
          v160 = (sint32)((uint32)(12) * (uint32)(r_u16(local_objects + 1280u)));
          v84 = 1;
          while (1)
          {
            v85 = v84;
            v86 = (sint32)((uint32)(2) * (uint32)(v84));
            w_u32(local_objects + 112u, ((uint32)((sint32)r_u32(local_objects + 112u)) + (uint32)(7500)));
            sub_8004EEF4((local_objects + 112u), (sint32)(((v81 + (v86) * 2u))));
            if (((sint16)r_u16((uint32)((((uint32)((local_objects + 0u)) + (v83) * 1u) + (1248) * 1u))) < v84))
            {
              v87 = (((local_objects + 1256u) + ((v160 / 4)) * 4u));
              v88 = (sint32)(((v158 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v82))) + (uint32)(v86))) * 2u)));
              w_u32(v87, (sint32)((uint32)((sint32)r_u32(((local_objects + 1256u) + ((v160 / 4)) * 4u))) + (uint32)(7500)));
              sub_8004EEF4(v87, v88);
            }
            v36 = (((uint32)(sub_8004E9E4(((v158 + ((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v82))) - (uint32)(2))) + (uint32)(v86))) * 2u)), ((v158 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v82))) + (uint32)(v86))) * 2u)), ((v81 + ((sint32)((uint32)(v86) - (uint32)(2))) * 2u)), ((v81 + (v86) * 2u)))) << (uint32)(16)) != 0);
            v89 = (sint32)((uint32)(2) * (uint32)(v80));
            if (v36)
              break;
            ++v84;
            if (!sub_80053D20((sint32)((uint32)((sint32)r_u32(local_objects + 112u)) - (uint32)(7500)), (sint32)r_u32(local_objects + 120u)))
            {
              v89 = (sint32)((uint32)(2) * (uint32)(v80));
              break;
            }
          }

          w_u16((uint32)((((uint32)((local_objects + 0u)) + (v89) * 1u) + (1248) * 1u)), v85);
          v90 = (((local_objects + 0u) + (v89) * 4u) + (v80) * 4u);
        }
        v112 = (sint32)r_u32(local_objects + 116u);
        v113 = (sint32)r_u32(local_objects + 120u);
        w_u32((v90 + (314) * 4u), (sint32)r_u32(local_objects + 112u));
        w_u32((v90 + (315) * 4u), v112);
        w_u32((v90 + (316) * 4u), v113);
        v150 ^= 1u;
        w_u16(local_objects + 1280u, ((uint32)(r_u16(local_objects + 1280u)) ^ (uint32)(1u)));
        result = v152;
      }
      while (((sint32)((uint32)(v151) + (uint32)(v152)) > 0));
    }
  }
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


