#include "draft_signatures.h"
#include "psx.h"
#include "native_runtime.h"

/* Unverified draft bodies */

uint32 sub_800496D8(uint32 a1)
{
    FUNCTION_MARKER(0x800496d8u, "SLES_008.65");
  uint32 v2;
  uint32 v3;
  uint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 result;
  sint32 v11;
  sint32 v12;
  sint32 v13;
  sint16 v14;
  sint32 v15;
  sint32 v16;
  sint32 v17;
  sint16 v18;
  sint32 v19;
  sint32 v20;
  sint16 v21;
  v2 = (uint32)((sint32)r_u32((a1 + (5) * 4u)));
  v3 = (uint32)((sint32)r_u32((a1 + (1) * 4u)));
  v4 = (uint32)((sint32)r_u32((a1 + (2) * 4u)));
  w_u32(v2, ((uint32)((sint32)r_u32(v2)) & (uint32)(~8u)));
  sub_80048994(a1);
  w_u32(0x80078EE8, (sint32)r_u32((a1 + (18) * 4u)));
  w_u32(0x80078EEC, (sint32)r_u32((a1 + (19) * 4u)));
  w_u32(0x80078EF0, (sint32)r_u32((a1 + (20) * 4u)));
  v5 = (sint32)r_u32((a1 + (19) * 4u));
  v6 = (sint32)r_u32((a1 + (20) * 4u));
  if (((sint32)(v5) < (sint32)(v6)))
    v5 = (sint32)r_u32((a1 + (20) * 4u));
  v7 = (sint32)r_u32((a1 + (18) * 4u));
  if (((sint32)(v7) < (sint32)(v5)))
    v7 = v5;
  if (((sint32)(v7) < (sint32)(0)))
  {
    w_u32(v2, ((uint32)((sint32)r_u32(v2)) | (uint32)(0x20u)));
    v8 = r_u32((v3 + (34) * 4u));
    w_u32((v3 + (64) * 4u), (r_u32((v4 + (34) * 4u)) & r_u32((v3 + (40) * 4u))));
    v9 = r_u32((v4 + (40) * 4u));
    result = 8;
    LABEL_35:
    w_u32((v4 + (64) * 4u), (v8 & v9));

    return result;
  }
  if (v7)
    goto LABEL_36;
  if ((sint32)r_u32((a1 + (18) * 4u)))
  {
    v11 = (sint32)r_u32((a1 + (19) * 4u));
  }
  else
  {
    v11 = (sint32)r_u32((a1 + (19) * 4u));
    if ((((sint32)(v11) < (sint32)(0)) && ((sint32)(v6) < (sint32)(0))))
    {
      v12 = (sint32)r_u32(v2);
      w_u32(v2, ((uint32)((sint32)r_u32(v2)) | (uint32)(0x40u)));
      v13 = (v12 | 0x140);
      if (((sint32)r_u32((a1 + (12) * 4u)) == (sint32)r_u32((a1 + (9) * 4u))))
        v13 = (v12 | 0x240);
      w_u32(v2, v13);
      v14 = 0x4000;
      if (((sint32)r_u32((a1 + (12) * 4u)) == (sint32)r_u32((a1 + (9) * 4u))))
        v14 = (sint32)(0u - (uint32)(16384));
      w_u16(0x80078ED8, v14);
      w_u16(0x80078EDA, 0);
      w_u16(0x80078EDC, 0);
      LABEL_34:
      v8 = r_u32((v3 + (34) * 4u));

      w_u32((v3 + (64) * 4u), (r_u32((v4 + (34) * 4u)) & r_u32((v3 + (38) * 4u))));
      v9 = r_u32((v4 + (38) * 4u));
      result = 65;
      goto LABEL_35;
    }
  }
  if (v11)
    goto LABEL_25;
  v15 = (sint32)r_u32((a1 + (20) * 4u));
  if (((sint32)(v15) < (sint32)(0)))
  {
    if (((sint32)((sint32)r_u32((a1 + (18) * 4u))) < (sint32)(0)))
    {
      v16 = (sint32)r_u32(v2);
      w_u32(v2, ((uint32)((sint32)r_u32(v2)) | (uint32)(0x40u)));
      v17 = (v16 | 0x440);
      if (((sint32)r_u32((a1 + (13) * 4u)) == (sint32)r_u32((a1 + (10) * 4u))))
        v17 = (v16 | 0x840);
      w_u32(v2, v17);
      w_u16(0x80078ED8, 0);
      v18 = 0x4000;
      if (((sint32)r_u32((a1 + (13) * 4u)) == (sint32)r_u32((a1 + (10) * 4u))))
        v18 = (sint32)(0u - (uint32)(16384));
      w_u16(0x80078EDA, v18);
      w_u16(0x80078EDC, 0);
      goto LABEL_34;
    }
    LABEL_25:
    v15 = (sint32)r_u32((a1 + (20) * 4u));

  }
  if (((!v15 && ((sint32)((sint32)r_u32((a1 + (18) * 4u))) < (sint32)(0))) && ((sint32)((sint32)r_u32((a1 + (19) * 4u))) < (sint32)(0))))
  {
    v19 = (sint32)r_u32(v2);
    w_u32(v2, ((uint32)((sint32)r_u32(v2)) | (uint32)(0x40u)));
    v20 = (v19 | 0x1040);
    if (((sint32)r_u32((a1 + (14) * 4u)) == (sint32)r_u32((a1 + (11) * 4u))))
      v20 = (v19 | 0x2040);
    w_u32(v2, v20);
    w_u16(0x80078ED8, 0);
    w_u16(0x80078EDA, 0);
    v21 = 0x4000;
    if (((sint32)r_u32((a1 + (14) * 4u)) == (sint32)r_u32((a1 + (11) * 4u))))
      v21 = (sint32)(0u - (uint32)(16384));
    w_u16(0x80078EDC, v21);
    goto LABEL_34;
  }
  LABEL_36:
  result = 0;

  w_u32(v2, ((uint32)((sint32)r_u32(v2)) | (uint32)(0x10u)));
  w_u32((v3 + (64) * 4u), 0);
  w_u32((v4 + (64) * 4u), 0);
  return result;
}


uint32 sub_800553D0(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x800553d0u, "SLES_008.65");
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Bind external adapter for sub_80063FC8 */
  uint32 v5;
  uint32 v6;
  sint32 result;
  sint32 v8;
  uint32 v9;
  sint32 v10;
  sint32 v11;
  sint32 v12;
  sint32 v13;
  sint32 v14;
  sint32 v15;
  uint32 v16;
  sint32 v17;
  sint32 v18;
  sint32 v19;
  sint32 v20;
  sint32 v21;
  sint32 v22;
  sint32 v23;
  sint32 v24;
  v5 = r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(16) * (uint32)(a3))) - (uint32)(2146920180))));
  v6 = (uint32)((sint32)((uint32)((sint32)((uint32)(16) * (uint32)(a3))) - (uint32)(2146920172)));
  if ((r_u32(v6) < (sint32)((uint32)(a2) + (uint32)(v5))))
    a2 = ((uint32)(r_u32(v6)) - (uint32)(v5));
  if (!a2)
    return 0;
  v8 = r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(16) * (uint32)(a3))) - (uint32)(2146920176))));
  if (!(sint32)r_u32(0x800771ecu))
    xport_mips_break(7u);
  v9 = (((uint32)((v5 >> 11)) + (uint32)(v8)) / (sint32)r_u32(0x800771ecu));
  if (!(sint32)r_u32(0x800771ecu))
    xport_mips_break(7u);
  v10 = a2;
  v11 = 0;
  v12 = (sint32)((((a2 + v5 - 1u) >> 11) + (uint32)v8) / r_u32(0x800771ECu) - v9 + 1u);
  v13 = (sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(v8) << (uint32)(11))) + (uint32)(v5))) - (uint32)(((uint32)(((uint32)(v9) * (uint32)((sint32)r_u32(0x800771ecu)))) << (uint32)(11))));
  if (((sint32)(v12) > (sint32)(0)))
  {
    do
    {
      v14 = 0;
      v15 = 0;
      do
      {
        if ((((r_u32((uint32)((sint32)((uint32)(v15) - (uint32)(2146925912)))) & 1) != 0) && (r_u32((uint32)((sint32)((uint32)(v15) - (uint32)(2146925908)))) == v9)))
          break;
        ++v14;
        v15 = ((uint32)(v15) + (uint32)(16));
      }
      while (((sint32)(v14) <= (sint32)(0)));
      v16 = 0;
      if ((v14 == 1))
      {
        v17 = 0;
        v18 = (sint32)(0u - (uint32)(2146925904));
        v19 = 0;
        while (r_u32((uint32)((sint32)((uint32)(v19) - (uint32)(2146925912)))))
        {
          if ((!v17 || (r_u32((uint32)(v18)) < v16)))
          {
            v16 = r_u32((uint32)(v18));
            v14 = v17;
          }
          v18 = ((uint32)(v18) + (uint32)(16));
          ++v17;
          v19 = ((uint32)(v19) + (uint32)(16));
          if (((sint32)(v17) > (sint32)(0)))
            goto LABEL_22;
        }

        v14 = v17;
        LABEL_22:
        v20 = (sint32)((uint32)(16) * (uint32)(v14));

        sub_800552D4(((uint32)(v9) * (uint32)((sint32)r_u32(0x800771ecu))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(16) * (uint32)(v14))) - (uint32)(2146925900)))), (sint32)r_u32(0x800771ecu));
        v21 = r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(16) * (uint32)(v14))) - (uint32)(2146925912))));
        v22 = (sint32)r_u32(0x800775d4u);
        w_u32((uint32)((sint32)((uint32)(v20) - (uint32)(2146925908))), v9);
        w_u32((uint32)((sint32)((uint32)(v20) - (uint32)(2146925912))), (v21 | 1));
        w_u32(0x800775d4u, (sint32)((uint32)(v22) + (uint32)(1)));
        w_u32((uint32)((sint32)((uint32)(v20) - (uint32)(2146925904))), v22);
      }
      v23 = v10;
      if (((sint32)((uint32)((sint32)r_u32(0x800771ecu)) << (uint32)(11)) < (uint32)((sint32)((uint32)(v10) + (uint32)(v13)))))
        v23 = (sint32)((uint32)((sint32)((uint32)((sint32)r_u32(0x800771ecu)) << (uint32)(11))) - (uint32)(v13));
      v24 = a1;
      a1 = ((uint32)(a1) + (uint32)(v23));
      v10 = ((uint32)(v10) - (uint32)(v23));
      ob_draft_unresolved_call(0x80063fc8u, 3u, v24, (sint32)((uint32)(v13) + (uint32)(r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(16) * (uint32)(v14))) - (uint32)(2146925900)))))), v23);
      if (!v10)
        break;
      v13 = 0;
      ++v11;
      ++v9;
    }
    while (((sint32)(v11) < (sint32)(v12)));
  }
  result = a2;
  w_u32((uint32)((sint32)((uint32)((sint32)((uint32)(16) * (uint32)(a3))) - (uint32)(2146920180))), ((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(16) * (uint32)(a3))) - (uint32)(2146920180))))) + (uint32)(a2)));
  return result;
}


uint32 sub_8004C64C(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    FUNCTION_MARKER(0x8004c64cu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80024D24 */
    /* TODO: Bind external adapter for sub_8004C4D4 */
    /* TODO: Bind external adapter for sub_8005160C */
    /* TODO: Bind external adapter for sub_800257A0 */
    uint32 local_objects = ob_draft_scratch_acquire(24u);
  sint32 v5;
  sint32 v6;
  uint32 v8;
  sint32 v9;
  uint32 v12;
  sint32 v13;
  sint32 v14;
  sint32 i;
  sint32 v16;
  sint32 v17;
  uint32 v18;
  sint32 v19;
  sint32 v20;
  sint32 v21;
  sint32 v22;
  sint32 v23;
  ;
  sint32 v26;
  sint32 v27;
  v5 = a2;
  v6 = a3;
  v8 = a4;
  v9 = 0;
  v26 = 1;
  if ((((sint32)r_u32(0x800665d8u) & 3) != 0))
  {
    v12 = (uint32)(sub_800257CC((sint32)((0x800665d8u))));
  }
  else
  {
    v12 = (uint32)((sint32)r_u32(0x800665d8u));
    (w_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800665d8u)) - (uint32)(6))), (r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800665d8u)) - (uint32)(6)))) + 1u)), r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800665d8u)) - (uint32)(6)))));
  }
  v13 = (sint32)r_u32(a1);
  w_u32(0x80077644u, (sint32)(v12));
  if (((sint32)(v13) < (sint32)((sint32)(0u - (uint32)((sint32)r_u32(0x80077458u))))))
  {
    v14 = (sint32)(0u - (uint32)((sint32)r_u32(0x80077458u)));
    do
    {
      v8 += (3) * 4u;
      --v5;
      ++v9;
      v13 = ((uint32)(v13) + (uint32)(r_u32(v12)));
      w_u32(a1, v13);
    }
    while (((sint32)(v13) < (sint32)(v14)));
  }
  for (i = (sint32)((uint32)((sint32)r_u32(a1)) + (uint32)((sint32)((uint32)(v5) * (uint32)(r_u32((uint32)((sint32)r_u32(0x80077644u))))))); ((sint32)((sint32)r_u32(0x80077458u)) < (sint32)(i)); ++v9)
  {
    i = ((uint32)(i) - (uint32)(r_u32((uint32)((sint32)r_u32(0x80077644u)))));
    --v5;
  }

  v16 = (sint32)r_u32((a1 + (2) * 4u));
  v17 = (sint32)r_u32(0x80077468u);
  if (((sint32)((sint32)r_u32(0x80077468u)) < (sint32)(v16)))
  {
    v18 = (uint32)((sint32)r_u32(0x80077644u));
    do
    {
      v8 += ((sint32)((uint32)(3) * (uint32)(a2))) * 4u;
      --v6;
      ++v9;
      v16 = ((uint32)(v16) - (uint32)(r_u32(v18)));
      w_u32((a1 + (2) * 4u), v16);
    }
    while (((sint32)(v17) < (sint32)(v16)));
  }
  v19 = (sint32)r_u32((a1 + (2) * 4u));
  if (((sint32)((sint32)((uint32)(v19) - (uint32)((sint32)((uint32)(v6) * (uint32)(r_u32((uint32)((sint32)r_u32(0x80077644u)))))))) < (sint32)((sint32)(0u - (uint32)((sint32)r_u32(0x80077468u))))))
  {
    v20 = (sint32)((uint32)(v6) * (uint32)(r_u32((uint32)((sint32)r_u32(0x80077644u)))));
    do
    {
      v20 = ((uint32)(v20) - (uint32)(r_u32((uint32)((sint32)r_u32(0x80077644u)))));
      --v6;
      ++v9;
    }
    while (((sint32)((sint32)((uint32)(v19) - (uint32)(v20))) < (sint32)((sint32)(0u - (uint32)((sint32)r_u32(0x80077468u))))));
  }
  if (v9)
    ob_draft_unresolved_call(0x80024d24u, 3u, a4, (sint32)((uint32)((sint32)((uint32)(36) * (uint32)(a2))) * (uint32)(a3)), 2147483639);
  sub_80051400(a1, (local_objects + 0u));
  v21 = 0;
  if (((sint32)(v6) > (sint32)(0)))
  {
    v27 = (sint32)((uint32)(36) * (uint32)(a2));
    do
    {
      ob_draft_unresolved_call(0x8004c4d4u, 3u, v8, (sint32)((local_objects + 0u)), (sint32)((uint32)(3) * (uint32)(a2)));
      v22 = (sint32)((uint32)(v5) - (uint32)(2));
      if ((v5 != 1))
      {
        v23 = (sint32)((uint32)(12) * (uint32)(v26));
        do
        {
          ob_draft_unresolved_call(0x8005160cu, 3u, (local_objects + 0u), 0, v26);
          v8 = (uint32)(((uint32)(v8) + (v23) * 1u));
          ob_draft_unresolved_call(0x8004c4d4u, 3u, v8, (sint32)((local_objects + 0u)), (sint32)((uint32)(3) * (uint32)(a2)));
          --v22;
        }
        while ((v22 != (sint32)(0u - (uint32)(1))));
      }
      v26 = (sint32)(0u - (uint32)(v26));
      ob_draft_unresolved_call(0x8005160cu, 3u, (local_objects + 0u), 1, 1);
      ++v21;
      v8 = (uint32)(((uint32)(v8) + (v27) * 1u));
    }
    while (((sint32)(v21) < (sint32)(v6)));
  }
  { uint32 draft_return = ob_draft_unresolved_call(0x800257a0u, 1u, (0x800665d8u)); ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80025DA0(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80025da0u, "SLES_008.65");
    /* Copy the 40-byte template from its guest address in 16-byte groups and an 8-byte tail */
    /* TODO: Bind external adapter for sub_80026460 */
    /* TODO: Bind external adapter for sub_8002679C */
  sint32 v2;
  uint32 v3;
  uint32 v4;
  uint32 v5;
  uint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  uint32 v11;
  sint32 v12;
  sint32 v13;
  sint32 v14;
  uint32 v15;
  sint32 v16;
  sint32 v17;
  sint32 v18;
  sint32 v19;
  uint32 v20;
  sint32 v21;
  uint32 v22;
  uint32 v23;
  sint32 v24;
  sint32 v25;
  sint32 v26;
  sint32 v27;
  uint32 v28;
  uint32 v29;
  sint32 v30;
  sint32 v31;
  sint32 v32;
  sint32 v33;
  sint32 v34;
  sint32 v35;
  sint32 v36;
  uint32 v37;
  uint32 v38;
  sint32 v39;
  sint32 v40;
  sint32 v41;
  sint32 v42;
  uint32 v43;
  uint32 v44;
  sint32 v45;
  sint32 v46;
  sint32 v47;
  sint32 v48;
  sint32 v49;
  sint32 v50;
  v2 = (a1 & 3);
  v3 = (a1 & 0xFFFFFFFC);
  w_u32(0x80077224u, ((uint32)(v3) + (uint32)(40)));
  w_u32(0x80077228u, ((uint32)(v3) + (uint32)(80)));
  w_u32(0x8007722cu, ((uint32)(v3) + (uint32)(120)));
  v4 = (uint32)(((uint32)(v3) + (uint32)(160)));
  v5 = 0x8006C2DCu;
  v6 = ((sint32)((uint32)(a2) - (uint32)(v2)) & 0xFFFFFFFC);
  w_u32(0x80077220u, v3);
  w_u32(0x8007721cu, ((uint32)(((uint32)(v3) + (uint32)(v6))) - (uint32)(40)));
  w_u32(0x80077218u, ((uint32)(v3) + (uint32)(160)));
  w_u32(0x80077244u, ((uint32)(v6) - (uint32)(200)));
  w_u32(0x80077248u, ((uint32)(v6) - (uint32)(200)));
  w_u32(0x80077238u, 1);
  w_u32(0x8007723cu, 1);
  w_u32(0x80077240u, 0);
  do
  {
    v7 = (sint32)r_u32((v5 + (1) * 4u));
    v8 = (sint32)r_u32((v5 + (2) * 4u));
    v9 = (sint32)r_u32((v5 + (3) * 4u));
    w_u32(v4, (sint32)r_u32(v5));
    w_u32((v4 + (1) * 4u), v7);
    w_u32((v4 + (2) * 4u), v8);
    w_u32((v4 + (3) * 4u), v9);
    v5 += (4) * 4u;
    v4 += (4) * 4u;
  }
  while ((v5 != 0x8006C2FCu));
  v10 = (sint32)r_u32((v5 + (1) * 4u));
  w_u32(v4, (sint32)r_u32(v5));
  w_u32((v4 + (1) * 4u), v10);
  v11 = 0x8006C2DCu;
  v12 = (sint32)r_u32(0x80077218u);
  v13 = (sint32)r_u32(0x80077248u);
  v14 = (sint32)r_u32(0x8007721cu);
  w_u8((uint32)((sint32)((uint32)((sint32)r_u32(0x80077218u)) + (uint32)(32))), 0x80);
  v15 = (uint32)((sint32)r_u32(0x8007721cu));
  w_u32((uint32)((sint32)((uint32)(v12) + (uint32)(16))), (sint32)((uint32)(v13) - (uint32)(40)));
  w_u32((uint32)((sint32)((uint32)(v12) + (uint32)(4))), v14);
  do
  {
    v16 = (sint32)r_u32((v11 + (1) * 4u));
    v17 = (sint32)r_u32((v11 + (2) * 4u));
    v18 = (sint32)r_u32((v11 + (3) * 4u));
    w_u32(v15, (sint32)r_u32(v11));
    w_u32((v15 + (1) * 4u), v16);
    w_u32((v15 + (2) * 4u), v17);
    w_u32((v15 + (3) * 4u), v18);
    v11 += (4) * 4u;
    v15 += (4) * 4u;
  }
  while ((v11 != 0x8006C2FCu));
  v19 = (sint32)r_u32((v11 + (1) * 4u));
  w_u32(v15, (sint32)r_u32(v11));
  w_u32((v15 + (1) * 4u), v19);
  v20 = (uint32)((sint32)r_u32(0x8007721cu));
  v21 = (sint32)r_u32(0x80077218u);
  v22 = 0x8006C2DCu;
  w_u8((uint32)((sint32)((uint32)((sint32)r_u32(0x8007721cu)) + (uint32)(32))), 0);
  v23 = (uint32)((sint32)r_u32(0x80077220u));
  w_u32(v20, v21);
  do
  {
    v24 = (sint32)r_u32((v22 + (1) * 4u));
    v25 = (sint32)r_u32((v22 + (2) * 4u));
    v26 = (sint32)r_u32((v22 + (3) * 4u));
    w_u32(v23, (sint32)r_u32(v22));
    w_u32((v23 + (1) * 4u), v24);
    w_u32((v23 + (2) * 4u), v25);
    w_u32((v23 + (3) * 4u), v26);
    v22 += (4) * 4u;
    v23 += (4) * 4u;
  }
  while ((v22 != 0x8006C2FCu));
  v27 = (sint32)r_u32((v22 + (1) * 4u));
  w_u32(v23, (sint32)r_u32(v22));
  w_u32((v23 + (1) * 4u), v27);
  v28 = (uint32)((sint32)r_u32(0x80077224u));
  v29 = 0x8006C2DCu;
  do
  {
    v30 = (sint32)r_u32((v29 + (1) * 4u));
    v31 = (sint32)r_u32((v29 + (2) * 4u));
    v32 = (sint32)r_u32((v29 + (3) * 4u));
    w_u32(v28, (sint32)r_u32(v29));
    w_u32((v28 + (1) * 4u), v30);
    w_u32((v28 + (2) * 4u), v31);
    w_u32((v28 + (3) * 4u), v32);
    v29 += (4) * 4u;
    v28 += (4) * 4u;
  }
  while ((v29 != 0x8006C2FCu));
  v33 = (sint32)r_u32((v29 + (1) * 4u));
  w_u32(v28, (sint32)r_u32(v29));
  w_u32((v28 + (1) * 4u), v33);
  v34 = (sint32)r_u32(0x80077220u);
  v35 = (sint32)r_u32(0x80077218u);
  v36 = (sint32)r_u32(0x80077224u);
  v37 = 0x8006C2DCu;
  w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80077220u)) + (uint32)(12))), (sint32)r_u32(0x80077218u));
  w_u32((uint32)((sint32)((uint32)(v36) + (uint32)(8))), v35);
  w_u32((uint32)((sint32)((uint32)(v35) + (uint32)(12))), v36);
  w_u32((uint32)((sint32)((uint32)(v35) + (uint32)(8))), v34);
  w_u32((uint32)((sint32)((uint32)(v34) + (uint32)(16))), 0);
  w_u32((uint32)((sint32)((uint32)(v36) + (uint32)(16))), (sint32)(0u - (uint32)(1)));
  w_u8((uint32)((sint32)((uint32)(v34) + (uint32)(32))), 0x80);
  w_u8((uint32)((sint32)((uint32)((sint32)r_u32(0x80077224u)) + (uint32)(32))), 0x80);
  v38 = (uint32)((sint32)r_u32(0x80077228u));
  do
  {
    v39 = (sint32)r_u32((v37 + (1) * 4u));
    v40 = (sint32)r_u32((v37 + (2) * 4u));
    v41 = (sint32)r_u32((v37 + (3) * 4u));
    w_u32(v38, (sint32)r_u32(v37));
    w_u32((v38 + (1) * 4u), v39);
    w_u32((v38 + (2) * 4u), v40);
    w_u32((v38 + (3) * 4u), v41);
    v37 += (4) * 4u;
    v38 += (4) * 4u;
  }
  while ((v37 != 0x8006C2FCu));
  v42 = (sint32)r_u32((v37 + (1) * 4u));
  w_u32(v38, (sint32)r_u32(v37));
  w_u32((v38 + (1) * 4u), v42);
  v43 = (uint32)((sint32)r_u32(0x8007722cu));
  v44 = 0x8006C2DCu;
  do
  {
    v45 = (sint32)r_u32((v44 + (1) * 4u));
    v46 = (sint32)r_u32((v44 + (2) * 4u));
    v47 = (sint32)r_u32((v44 + (3) * 4u));
    w_u32(v43, (sint32)r_u32(v44));
    w_u32((v43 + (1) * 4u), v45);
    w_u32((v43 + (2) * 4u), v46);
    w_u32((v43 + (3) * 4u), v47);
    v44 += (4) * 4u;
    v43 += (4) * 4u;
  }
  while ((v44 != 0x8006C2FCu));
  v48 = (sint32)r_u32((v44 + (1) * 4u));
  w_u32(v43, (sint32)r_u32(v44));
  w_u32((v43 + (1) * 4u), v48);
  v49 = (sint32)r_u32(0x80077228u);
  v50 = (sint32)r_u32(0x8007722cu);
  w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80077228u)) + (uint32)(24))), (0x80077230u));
  w_u32(0x80077230u, (sint32)((uint32)(v49) + (uint32)(40)));
  w_u32((uint32)((sint32)((uint32)(v50) + (uint32)(24))), (0x80077234u));
  w_u32(0x80077234u, (sint32)((uint32)(v50) + (uint32)(40)));
  w_u32((uint32)((sint32)((uint32)(v49) + (uint32)(12))), v50);
  w_u32((uint32)((sint32)((uint32)(v50) + (uint32)(8))), v49);
  ob_draft_unresolved_call(0x80026460u, 0u);
  sub_80026694((0x800770b4u), 0, 5);
  ob_draft_unresolved_call(0x8002679cu, 2u, (0x800770b4u), 1);
  sub_80027F54();
  sub_80027CD0(0xFFFF);
  sub_800279D4(0xFFFF);
  return sub_800260F8();
}


uint32 sub_8004C944(uint32 a1)
{
    FUNCTION_MARKER(0x8004c944u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8002DC10 */
    /* TODO: Bind external adapter for sub_8002FAA8 */
    /* TODO: Bind external adapter for sub_8004A564 */
    /* TODO: Bind external adapter for sub_8004D0F8 */
    /* TODO: Bind external adapter for sub_800257A0 */
  sint32 v1;
  sint32 v2;
  sint32 v3;
  sint32 i;
  sint32 v5;
  sint32 j;
  sint32 v7;
  sint32 k;
  sint32 v9;
  sint32 m;
  sint32 v11;
  sint32 n;
  sint32 v13;
  sint32 ii;
  sint32 v15;
  sint32 jj;
  sint32 v17;
  sint32 kk;
  sint32 v19;
  sint32 mm;
  sint32 v21;
  sint32 nn;
  sint32 v23;
  sint32 i1;
  sint32 v25;
  sint32 v26;
  sint32 v27;
  sint32 v28;
  uint32 v29;
  sint32 i2;
  sint32 v31;
  sint32 v32;
  sint32 v33;
  sint32 result;
  v1 = (sint32)(0u - (uint32)(2146924488));
  v2 = 47;
  w_u32(0x800C8560, 4);
  w_u32(0x800775fcu, a1);
  w_u32(0x80084A40, 0);
  w_u32(0x8007733cu, 0);
  w_u32(0x80077580u, (sint32)(0u - (uint32)(2146959824)));
  do
  {
    w_u32((uint32)(v1), 0);
    --v2;
    v1 = ((uint32)(v1) + (uint32)(8));
  }
  while (((sint32)(v2) >= (sint32)(0)));
  v3 = (sint32)(0u - (uint32)(2146923336));
  for (i = 47; ((sint32)(i) >= (sint32)(0)); --i)
  {
    w_u32((uint32)(v3), 0);
    v3 = ((uint32)(v3) + (uint32)(8));
  }

  v5 = (sint32)(0u - (uint32)(2146922176));
  for (j = 47; ((sint32)(j) >= (sint32)(0)); --j)
  {
    w_u32((uint32)(v5), 0);
    v5 = ((uint32)(v5) + (uint32)(8));
  }

  v7 = (sint32)(0u - (uint32)(2146925672));
  for (k = 47; ((sint32)(k) >= (sint32)(0)); --k)
  {
    w_u32((uint32)(v7), 0);
    v7 = ((uint32)(v7) + (uint32)(8));
  }

  v9 = (sint32)(0u - (uint32)(2146924104));
  for (m = 47; ((sint32)(m) >= (sint32)(0)); --m)
  {
    w_u32((uint32)(v9), 0);
    v9 = ((uint32)(v9) + (uint32)(8));
  }

  v11 = (sint32)(0u - (uint32)(2146922952));
  for (n = 47; ((sint32)(n) >= (sint32)(0)); --n)
  {
    w_u32((uint32)(v11), 0);
    v11 = ((uint32)(v11) + (uint32)(8));
  }

  v13 = (sint32)(0u - (uint32)(2146921792));
  for (ii = 47; ((sint32)(ii) >= (sint32)(0)); --ii)
  {
    w_u32((uint32)(v13), 0);
    v13 = ((uint32)(v13) + (uint32)(8));
  }

  v15 = (sint32)(0u - (uint32)(2146925288));
  for (jj = 47; ((sint32)(jj) >= (sint32)(0)); --jj)
  {
    w_u32((uint32)(v15), 0);
    v15 = ((uint32)(v15) + (uint32)(8));
  }

  v17 = (sint32)(0u - (uint32)(2146923720));
  for (kk = 47; ((sint32)(kk) >= (sint32)(0)); --kk)
  {
    w_u32((uint32)(v17), 0);
    v17 = ((uint32)(v17) + (uint32)(8));
  }

  v19 = (sint32)(0u - (uint32)(2146922568));
  for (mm = 47; ((sint32)(mm) >= (sint32)(0)); --mm)
  {
    w_u32((uint32)(v19), 0);
    v19 = ((uint32)(v19) + (uint32)(8));
  }

  v21 = (sint32)(0u - (uint32)(2146921408));
  for (nn = 47; ((sint32)(nn) >= (sint32)(0)); --nn)
  {
    w_u32((uint32)(v21), 0);
    v21 = ((uint32)(v21) + (uint32)(8));
  }

  v23 = (sint32)(0u - (uint32)(2146924904));
  for (i1 = 47; ((sint32)(i1) >= (sint32)(0)); --i1)
  {
    w_u32((uint32)(v23), 0);
    v23 = ((uint32)(v23) + (uint32)(8));
  }

  v25 = (sint32)r_u32(0x800665d8u);
  w_u32(0x800C8560, 2);
  v26 = 0;
  if ((((sint32)r_u32(0x800665d8u) & 3) != 0))
    v25 = sub_800257CC((sint32)((0x800665d8u)));
  else
    (w_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800665d8u)) - (uint32)(6))), (r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800665d8u)) - (uint32)(6)))) + 1u)), r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800665d8u)) - (uint32)(6)))));
  v27 = 0;
  v28 = 0;
  w_u32(0x80077644u, v25);
  w_u8(0x8007714cu, 1);
  do
  {
    ob_draft_unresolved_call(0x8002dc10u, 1u, (uint32)(0x800843F0));
    sub_8002F9C4((sint32)(0u - (uint32)(2146941968)), (sint32)((uint32)((sint32)((sint32)r_u32(0x80073694u))) + (uint32)(v28)));
    ob_draft_unresolved_call(0x8002faa8u, 2u, (uint32)(0x800843F0), (sint32)r_u32(0x80073688u));
    v29 = (uint32)((sint32)((uint32)(v27) - (uint32)(2146919448)));
    for (i2 = (sint32)(0u - (uint32)(2146941968)); (i2 != (sint32)(0u - (uint32)(2146941888))); i2 = ((uint32)(i2) + (uint32)(16)))
    {
      v31 = r_u32((uint32)((sint32)((uint32)(i2) + (uint32)(4))));
      v32 = r_u32((uint32)((sint32)((uint32)(i2) + (uint32)(8))));
      v33 = r_u32((uint32)((sint32)((uint32)(i2) + (uint32)(12))));
      w_u32(v29, r_u32((uint32)(i2)));
      w_u32((v29 + (1) * 4u), v31);
      w_u32((v29 + (2) * 4u), v32);
      w_u32((v29 + (3) * 4u), v33);
      v29 += (4) * 4u;
    }

    v27 = ((uint32)(v27) + (uint32)(80));
    ++v26;
    v28 = ((uint32)(v28) + (uint32)(18));
  }
  while (((sint32)(v26) < (sint32)(4)));
  sub_8004E3B0();
  if (!(sint32)r_u32(0x800771d0u))
    sub_8004A48C((sint32)(0u - (uint32)(2146943328)));
  sub_8004CD2C();
  w_u8(0x80077654u, ob_draft_unresolved_call(0x8004a564u, 1u, (sint32)(0u - (uint32)(2146942072))));
  sub_80031FEC();
  if (!(sint32)r_u32(0x800771d0u))
    ob_draft_unresolved_call(0x8004d0f8u, 0u);
  sub_8004A5C4();
  if (!(sint32)r_u32(0x800771d0u))
  {
    sub_8004DFB8((sint32)r_u32(0x80077644u));
    if (!(sint32)r_u32(0x800771d0u))
      ob_draft_unresolved_call(0x800257a0u, 1u, (0x800665d8u));
  }
  if ((((sint32)r_u32(0x8006c208u) == 1) && (r_u8((uint32)((sint32)((uint32)((sint32)r_u32(0x80077190u)) + (uint32)(41)))) != 4)))
    sub_80052A68();
  sub_80051974();
  result = 1;
  if ((sint32)r_u32(0x800771d0u))
  {
    ob_draft_unresolved_call(0x800257a0u, 1u, (0x800665d8u));
    result = 1;
  }
  w_u32(0x800C8560, 1);
  return result;
}


uint32 sub_80039838(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    FUNCTION_MARKER(0x80039838u, "SLES_008.65");
    uint32 reg_T0;
    uint32 reg_T1;
    uint32 reg_T2;
  uint32 v4;
  sint16 v5;
  uint32 v6;
  sint32 v7;
  sint16 v8;
  sint16 v9;
  uint32 v10;
  sint32 v12;
  sint32 v18;
  sint32 v20;
  uint32 v21;
  uint32 v22;
  uint32 v23;
  sint16 v29;
  sint32 result;
  uint32 v32;
  sint32 v35;
  sint32 i;
  sint32 v37;
  v4 = (uint32)((sint32)r_u32(0x800773a4u));
  v5 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(14))));
  v6 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(52))));
  v7 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(16))));
  v8 = (sint32)((uint32)(v5) - (uint32)(3));
  v9 = (sint32)((uint32)(v5) - (uint32)(3));
  if (((a2 & 0x80) != 0))
  {
    v10 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(44))));

    v12 = r_u32((a3 + (1) * 4u));
    w_u32(0x1F800000, r_u32(a3));
    w_u32(0x1F800004, v12);
    reg_T0 = (sint32)r_u32(v10);
    reg_T1 = (sint32)r_u32((v10 + (6) * 4u));
    reg_T2 = (sint32)r_u32((v10 + (7) * 4u));
    xport_gte_write_control(0u, reg_T0);
    xport_gte_write_control(3u, reg_T1);
    xport_gte_write_control(4u, reg_T2);
    reg_T0 = ((uint32)(r_u16(((uint32)(v10) + (2) * 2u))) + (uint32)((sint32)((uint32)((sint16)r_u16(((uint32)(v10) + (6) * 2u))) << (uint32)(16))));
    reg_T1 = ((uint32)(r_u16(((uint32)(v10) + (7) * 2u))) + (uint32)((sint32)((uint32)((sint16)r_u16(((uint32)(v10) + (8) * 2u))) << (uint32)(16))));
    xport_gte_write_control(1u, reg_T0);
    xport_gte_write_control(2u, reg_T1);
    xport_gte_write_data(0u, r_u32(0x1F800000u));
    xport_gte_write_data(1u, r_u32(0x1F800004u));
    xport_gte_execute(0x486012u);
    v18 = 0;
    if (((sint32)(v8) < (sint32)(0)))
    {
      v29 = v5;
    }
    else
    {
      v18 = 3;
      if (((sint32)(v8) >= (sint32)(3)))
      {

        v20 = v8;
        v21 = (v10 + (8) * 4u);
        v22 = (v6 + (2) * 4u);
        v23 = (uint32)((sint32)((uint32)((sint32)r_u32(0x800773a4u)) + (uint32)(8)));
        do
        {
          w_u32(0x1F800008u, xport_gte_read_data(25u));
          w_u32(0x1F80000Cu, xport_gte_read_data(26u));
          w_u32(0x1F800010u, xport_gte_read_data(27u));
          reg_T0 = (sint32)r_u32((v10 + (9) * 4u));
          reg_T1 = (sint32)r_u32((v10 + (15) * 4u));
          reg_T2 = (sint32)r_u32((v10 + (16) * 4u));
          xport_gte_write_control(0u, reg_T0);
          xport_gte_write_control(3u, reg_T1);
          xport_gte_write_control(4u, reg_T2);
          reg_T0 = ((uint32)(r_u16(((uint32)(v10) + (20) * 2u))) + (uint32)((sint32)((uint32)((sint16)r_u16(((uint32)(v10) + (24) * 2u))) << (uint32)(16))));
          reg_T1 = ((uint32)(r_u16(((uint32)(v10) + (25) * 2u))) + (uint32)((sint32)((uint32)((sint16)r_u16(((uint32)(v10) + (26) * 2u))) << (uint32)(16))));
          xport_gte_write_control(1u, reg_T0);
          xport_gte_write_control(2u, reg_T1);
          xport_gte_write_data(0u, r_u32(0x1F800000u));
          xport_gte_write_data(1u, r_u32(0x1F800004u));
          xport_gte_execute(0x486012u);
          if (((sint32)(((sint32)((sint32)r_u32((v21 - (6) * 4u))) >> (a4 & 31u))) >= (sint32)((sint32)r_u32(0x1F800008))))
            w_u32(v4, 0);
          else
            w_u32(v4, (sint32)r_u32(v6));
          if (((sint32)(((sint32)((sint32)r_u32((v21 - (3) * 4u))) >> (a4 & 31u))) >= (sint32)((sint32)r_u32(0x1F80000C))))
            w_u32((v23 - (1) * 4u), 0);
          else
            w_u32((v23 - (1) * 4u), r_u32((v22 - (1) * 4u)));
          if (((sint32)(((sint32)((sint32)r_u32(v21)) >> (a4 & 31u))) >= (sint32)((sint32)r_u32(0x1F800010))))
            w_u32(v23, 0);
          else
            w_u32(v23, r_u32(v22));
          v23 += (3) * 4u;
          v4 += (3) * 4u;
          v22 += (3) * 4u;
          v6 += (3) * 4u;
          v21 += (9) * 4u;
          v18 = ((uint32)(v18) + (uint32)(3));
          v10 += (9) * 4u;
        }
        while (((sint32)(v20) >= (sint32)(v18)));
      }
      w_u32(0x1F800008u, xport_gte_read_data(25u));
      w_u32(0x1F80000Cu, xport_gte_read_data(26u));
      w_u32(0x1F800010u, xport_gte_read_data(27u));
      if (((sint32)(((sint32)((sint32)r_u32((v10 + (2) * 4u))) >> (a4 & 31u))) >= (sint32)((sint32)r_u32(0x1F800008))))
        w_u32(v4, 0);
      else
        w_u32(v4, (sint32)r_u32(v6));
      if (((sint32)(((sint32)((sint32)r_u32((v10 + (5) * 4u))) >> (a4 & 31u))) >= (sint32)((sint32)r_u32(0x1F80000C))))
        w_u32((v4 + (1) * 4u), 0);
      else
        w_u32((v4 + (1) * 4u), (sint32)r_u32((v6 + (1) * 4u)));
      if (((sint32)(((sint32)((sint32)r_u32((v10 + (8) * 4u))) >> (a4 & 31u))) >= (sint32)((sint32)r_u32(0x1F800010))))
        w_u32((v4 + (2) * 4u), 0);
      else
        w_u32((v4 + (2) * 4u), (sint32)r_u32((v6 + (2) * 4u)));
      v29 = (sint32)((uint32)(v9) + (uint32)(3));
      v4 += (3) * 4u;
      v6 += (3) * 4u;
      v10 += (9) * 4u;
    }
    result = ((sint32)(v18) < (sint32)((sint16)(v7)));

    if (((sint32)(v18) < (sint32)((sint16)(v7))))
    {
      v32 = v10;
      do
      {
        reg_T0 = (sint32)r_u32(v32);
        reg_T1 = (sint32)r_u32((v32 + (1) * 4u));
        xport_gte_write_control(0u, reg_T0);
        xport_gte_write_control(1u, reg_T1);
        xport_gte_write_data(0u, r_u32(0x1F800000u));
        xport_gte_write_data(1u, r_u32(0x1F800004u));
        xport_gte_execute(0x486012u);
        w_u32(0x1F800008u, xport_gte_read_data(25u));
        if (((sint32)(((sint32)((sint32)r_u32((v32 + (2) * 4u))) >> (a4 & 31u))) >= (sint32)((sint32)r_u32(0x1F800008))))
        {
          w_u32(((v4 += 4u) - 4u), 0);
          ((v6 += 4u));
        }
        else
        {
          if (((sint32)(v29) < (sint32)(v18)))
          {
            w_u32(v4, 1);
          }
          else
          {
            v35 = (sint32)r_u32(((v6 += 4u) - 4u));
            w_u32(v4, v35);
          }
          ((v4 += 4u));
        }
        result = ((sint32)(++v18) < (sint32)((sint16)(v7)));
        v32 += (3) * 4u;
      }
      while (((sint32)(v18) < (sint32)((sint16)(v7))));
    }
  }
  else
  {
    result = (sint32)((uint32)(v7) << (uint32)(16));
    if (((a2 & 1) == 0))
    {
      result = (sint16)(v7);
      for (i = 0; ((sint32)(i) < (sint32)((sint16)(v7))); ((v4 += 4u)))
      {
        v37 = (sint32)r_u32(((v6 += 4u) - 4u));
        ++i;
        w_u32(v4, v37);
        result = ((sint32)(i) < (sint32)((sint16)(v7)));
      }

    }
  }
  return result;
}


uint32 sub_8004FC64(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7)
{
    FUNCTION_MARKER(0x8004fc64u, "SLES_008.65");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Bind external adapter for sub_8005160C */
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
  sint32 v23;
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
  sint32 v34;
  sint32 v35;
  sint32 v36;
  sint32 v37;
  sint32 v38;
  sint32 v39;
  sint32 v40;
  sint32 v41;
  sint32 v42;
  sint32 result;
  if (((sint32)(a4) >= (sint32)(10)))
  {
    if (((sint32)(((sint32)((sint32)r_u32(0x800775ccu)) / (sint32)(2))) < (sint32)(a4)))
      a4 = ((sint32)((sint32)r_u32(0x800775ccu)) / (sint32)(2));
  }
  else
  {
    a4 = 10;
  }
  v12 = ((sint32)(a2) % (sint32)(a6));
  if (((a6 == (sint32)(0u - (uint32)(1))) && (a2 == 0x80000000)))
    ob_draft_unresolved_call(0x8004fc64u, 2u, 6u, 0);
  v13 = ((sint32)(a2) / (sint32)(a6));
  w_u32(a1, 0);
  w_u32((a1 + (22) * 4u), a7);
  if (((sint32)(a3) < (sint32)(0)))
  {
    w_u32((a1 + (19) * 4u), (sint32)(0u - (uint32)(a3)));
    w_u32((a1 + (6) * 4u), (sint32)(0u - (uint32)(1)));
    w_u32((a1 + (8) * 4u), (sint32)(0u - (uint32)(a6)));
    if (v12)
    {
      v14 = (sint32)((uint32)(a6) - (uint32)(v12));
    }
    else
    {
      v14 = 0;
      v13 = (sint32)((uint32)(((sint32)(a2) / (sint32)(a6))) - (uint32)(1));
    }
  }
  else
  {
    v14 = ((sint32)(a2) % (sint32)(a6));
    w_u32((a1 + (19) * 4u), a3);
    w_u32((a1 + (6) * 4u), 1);
    w_u32((a1 + (8) * 4u), a6);
  }
  v15 = (sint32)r_u32((a1 + (19) * 4u));
  if (v15)
  {
    if (((v15 == (sint32)(0u - (uint32)(1))) && (a6 == 0x80000000)))
      ob_draft_unresolved_call(0x8004fc64u, 2u, 6u, 0);
    w_u32((a1 + (20) * 4u), ((sint32)(a6) / (sint32)(v15)));
    w_u32((a1 + (21) * 4u), ((sint32)(a6) % (sint32)(v15)));
  }
  else
  {
    w_u32((a1 + (20) * 4u), 0);
    w_u32((a1 + (21) * 4u), 0);
  }
  v16 = (sint32)r_u32(a1);
  v17 = (sint32)((uint32)(v14) + (uint32)(a4));
  w_u32((a1 + (5) * 4u), 0);
  w_u32((a1 + (4) * 4u), v13);
  w_u32(a1, (v16 | 1));
  if (((sint32)(a6) < (sint32)((sint32)((uint32)(v14) + (uint32)(a4)))))
  {
    v20 = (sint32)r_u32((a1 + (19) * 4u));
    if (v20)
    {
      v21 = (sint32)((uint32)((sint32)((uint32)(2) * (uint32)(a6))) - (uint32)(v17));
      if (((v20 == (sint32)(0u - (uint32)(1))) && (v21 == 0x80000000)))
        ob_draft_unresolved_call(0x8004fc64u, 2u, 6u, 0);
      w_u32((a1 + (9) * 4u), (sint32)((uint32)(a5) + (uint32)(((sint32)(v21) / (sint32)(v20)))));
      w_u32((a1 + (10) * 4u), ((sint32)(v21) % (sint32)(v20)));
    }
    else
    {
      w_u32((a1 + (9) * 4u), 2147483393);
      w_u32((a1 + (10) * 4u), 0);
    }
    (w_u32((a1 + (5) * 4u), ((sint32)r_u32((a1 + (5) * 4u)) + 1u)), (sint32)r_u32((a1 + (5) * 4u)));
  }
  else
  {
    v18 = (sint32)r_u32((a1 + (19) * 4u));
    v19 = (sint32)((uint32)(a6) - (uint32)(v17));
    if (v18)
    {
      if (((v18 == (sint32)(0u - (uint32)(1))) && (v19 == 0x80000000)))
        ob_draft_unresolved_call(0x8004fc64u, 2u, 6u, 0);
      w_u32((a1 + (9) * 4u), (sint32)((uint32)(a5) + (uint32)(((sint32)(v19) / (sint32)(v18)))));
      w_u32((a1 + (10) * 4u), ((sint32)(v19) % (sint32)(v18)));
    }
    else
    {
      w_u32((a1 + (9) * 4u), 2147483393);
      w_u32((a1 + (10) * 4u), 0);
    }
  }
  w_u32(a1, ((uint32)((sint32)r_u32(a1)) | (uint32)(2u)));
  if (((sint32)((sint32)((uint32)(v14) - (uint32)(a4))) < (sint32)(0)))
  {
    v24 = (sint32)r_u32((a1 + (19) * 4u));
    v25 = (sint32)((uint32)(a4) - (uint32)(v14));
    if (v24)
    {
      if (((v24 == (sint32)(0u - (uint32)(1))) && (v25 == 0x80000000)))
        ob_draft_unresolved_call(0x8004fc64u, 2u, 6u, 0);
      w_u32((a1 + (11) * 4u), (sint32)((uint32)(a5) + (uint32)(((sint32)(v25) / (sint32)(v24)))));
      w_u32((a1 + (12) * 4u), ((sint32)(v25) % (sint32)(v24)));
    }
    else
    {
      w_u32((a1 + (11) * 4u), 2147483393);
      w_u32((a1 + (12) * 4u), 0);
    }
    v26 = (sint32)((uint32)((sint32)r_u32((a1 + (23) * 4u))) + (uint32)(132));
    v27 = (sint32)(0u - (uint32)((sint32)r_u32((a1 + (6) * 4u))));
    w_u32((a1 + (4) * 4u), ((uint32)((sint32)r_u32((a1 + (4) * 4u))) - (uint32)((sint32)r_u32((a1 + (6) * 4u)))));
    ob_draft_unresolved_call(0x8005160cu, 3u, v26, a7, v27);
    (w_u32((a1 + (5) * 4u), ((sint32)r_u32((a1 + (5) * 4u)) + 1u)), (sint32)r_u32((a1 + (5) * 4u)));
  }
  else
  {
    v22 = (sint32)r_u32((a1 + (19) * 4u));
    v23 = (sint32)((uint32)(a6) - (uint32)((sint32)((uint32)(v14) - (uint32)(a4))));
    if (v22)
    {
      if (((v22 == (sint32)(0u - (uint32)(1))) && (v23 == 0x80000000)))
        ob_draft_unresolved_call(0x8004fc64u, 2u, 6u, 0);
      w_u32((a1 + (11) * 4u), (sint32)((uint32)(a5) + (uint32)(((sint32)(v23) / (sint32)(v22)))));
      w_u32((a1 + (12) * 4u), ((sint32)(v23) % (sint32)(v22)));
    }
    else
    {
      w_u32((a1 + (11) * 4u), 2147483393);
      w_u32((a1 + (12) * 4u), 0);
    }
  }
  v28 = (sint32)r_u32((a1 + (9) * 4u));
  v29 = (sint32)r_u32((a1 + (10) * 4u));
  v30 = (sint32)r_u32((a1 + (12) * 4u));
  v31 = (sint32)r_u32((a1 + (20) * 4u));
  w_u32((a1 + (15) * 4u), (sint32)r_u32((a1 + (11) * 4u)));
  v32 = (sint32)r_u32((a1 + (15) * 4u));
  w_u32((a1 + (13) * 4u), v28);
  v33 = (sint32)r_u32((a1 + (19) * 4u));
  w_u32((a1 + (16) * 4u), v30);
  v34 = (sint32)((uint32)(v32) + (uint32)(v31));
  v35 = (sint32)r_u32((a1 + (16) * 4u));
  w_u32((a1 + (17) * 4u), v34);
  v36 = (sint32)r_u32((a1 + (21) * 4u));
  w_u32((a1 + (14) * 4u), v29);
  v37 = (sint32)((uint32)(v35) + (uint32)(v36));
  w_u32((a1 + (18) * 4u), v37);
  if (((sint32)(v37) >= (sint32)(v33)))
  {
    v38 = (sint32)r_u32((a1 + (17) * 4u));
    w_u32((a1 + (18) * 4u), (sint32)((uint32)(v37) - (uint32)(v33)));
    w_u32((a1 + (17) * 4u), (sint32)((uint32)(v38) + (uint32)(1)));
  }
  v39 = (sint32)r_u32((a1 + (9) * 4u));
  v40 = (sint32)r_u32((a1 + (11) * 4u));
  if ((((sint32)(v39) < (sint32)(v40)) || ((v39 == v40) && ((sint32)((sint32)r_u32((a1 + (10) * 4u))) < (sint32)((sint32)r_u32((a1 + (12) * 4u)))))))
  {
    v41 = (sint32)r_u32((a1 + (10) * 4u));
    w_u32((a1 + (2) * 4u), v39);
    w_u32((a1 + (3) * 4u), v41);
  }
  else
  {
    v42 = (sint32)r_u32((a1 + (12) * 4u));
    w_u32((a1 + (2) * 4u), (sint32)r_u32((a1 + (11) * 4u)));
    w_u32((a1 + (3) * 4u), v42);
  }
  result = (sint32)r_u32((a1 + (4) * 4u));
  w_u32((a1 + (7) * 4u), (sint32)((uint32)(result) * (uint32)(a6)));
  return result;
}


uint32 sub_80042B54(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x80042B54u, "SLES_008.65");
    uint32 transform = r_u32(a1 + 8u);
    uint32 camera = r_u32(0x800775D0u);
    sint32 x = (sint32)(r_u32(transform + 24u) - r_u32(camera + 24u));
    sint32 y = (sint32)(r_u32(transform + 28u) - r_u32(camera + 28u));
    sint32 z = (sint32)(r_u32(transform + 32u) - r_u32(camera + 32u));
    w_u32(0x1F800008u, (uint32)x);
    w_u32(0x1F80000Cu, (uint32)y);
    w_u32(0x1F800010u, (uint32)z);
    sint32 abs_x = x < 0 ? (sint32)(0u - (uint32)x) : x;
    sint32 abs_y = y < 0 ? (sint32)(0u - (uint32)y) : y;
    sint32 abs_z = z < 0 ? (sint32)(0u - (uint32)z) : z;
    uint32 large = abs_x >= 16000 || abs_y >= 16000 || abs_z >= 16000;
    w_u16(0x1F800000u, (uint32)(large ? x >> 4 : x));
    w_u16(0x1F800002u, (uint32)(large ? y >> 4 : y));
    w_u16(0x1F800004u, (uint32)(large ? z >> 4 : z));
    for (uint32 index = 0u; index < 5u; ++index)
        xport_gte_write_control(index, r_u32(0x8008C8A8u + 4u * index));
    xport_gte_write_data(0u, r_u32(0x1F800000u));
    xport_gte_write_data(1u, r_u32(0x1F800004u));
    xport_gte_execute(0x486012u);
    for (uint32 index = 0u; index < 3u; ++index)
        w_u32(0x1F800008u + 4u * index, xport_gte_read_data(25u + index));
    for (uint32 index = 0u; index < 3u; ++index)
        w_u32(0x1F800018u + 4u * index,
            r_u32(0x1F800008u + 4u * index) << (large ? 4u : 0u));
    uint32 handle = r_u32(a1 + 4u);
    uint32 model = r_u32(handle);
    if (model & 3u)
        model = sub_800257CC(handle);
    else
    {
        w_u16(model - 6u, r_u16(model - 6u) + 1u);
        model = r_u32(r_u32(a1 + 4u));
    }
    uint32 partial = 0u;
    if (a2)
    {
        uint32 scale = ((uint32)r_u16(r_u32(a1 + 8u) + 76u) * r_u16(model + 8u)) >> 8u;
        if ((uint16)scale > 0xFF00u)
            scale = 0xFF00u;
        sint32 radius = (sint32)((uint32)r_u16(model + 22u) * (uint16)scale) >> 8;
        sint32 camera_x = (sint32)r_u32(0x1F800018u);
        sint32 camera_y = (sint32)r_u32(0x1F80001Cu);
        sint32 camera_z = (sint32)r_u32(0x1F800020u);
        if (camera_z < (sint32)(r_u32(0x800773B4u) - (uint32)radius))
            goto release_model;
        if ((sint32)(r_u32(0x800773B8u) + (uint32)radius) < camera_z)
            goto release_model;
        sint32 magnitude_y = camera_y < 0 ? (sint32)(0u - (uint32)camera_y) : camera_y;
        sint32 vertical = (sint32)((uint32)(((int64_t)camera_z * (sint16)r_u16(0x8007734Cu)) >> 14)
            + (uint32)(((int64_t)magnitude_y * (sint16)r_u16(0x8007734Au)) >> 14));
        if (radius < vertical)
            goto release_model;
        sint32 magnitude_x = camera_x < 0 ? (sint32)(0u - (uint32)camera_x) : camera_x;
        sint32 horizontal = (sint32)((uint32)(((int64_t)camera_z * (sint16)r_u16(0x80077344u)) >> 14)
            + (uint32)(((int64_t)magnitude_x * (sint16)r_u16(0x80077340u)) >> 14));
        if (radius < horizontal)
            goto release_model;
        sint32 magnitude_horizontal = horizontal < 0 ? (sint32)(0u - (uint32)horizontal) : horizontal;
        if (magnitude_horizontal < radius)
            partial = 1u;
        else
        {
            sint32 magnitude_vertical = vertical < 0 ? (sint32)(0u - (uint32)vertical) : vertical;
            partial = magnitude_vertical < radius;
        }
    }
    else
        partial = a3 != 0u;
    {
        /* Addressable draw record includes clipping data and acquired LOD handles */
        uint32 record = ob_draft_scratch_acquire(296u);
        w_u8(record, 2u);
        w_u8(record + 1u, partial);
        w_u16(record + 2u, r_u16(a1));
        w_u16(record + 4u, r_u32(0x80077350u));
        w_u32(record + 12u, r_u32(0x1F800018u));
        w_u32(record + 16u, r_u32(0x1F80001Cu));
        w_u32(record + 20u, r_u32(0x1F800020u));
        w_u32(record + 24u, model);
        w_u32(record + 28u, r_u32(a1 + 8u));
        w_u32(record + 32u, r_u32(a1 + 12u));
        w_u32(record + 36u, r_u32(a1 + 16u));
        w_u32(record + 40u, r_u32(a1 + 20u));
        w_u32(record + 44u, 0u);
        w_u32(record + 48u, 0u);
        uint32 count = r_u16(0x800775A2u);
        w_u16(record + 52u, count);
        if (count)
            ob_draft_unresolved_call(0x80032240u, 1u, record + 56u);
        w_u16(record + 54u, 0u);
        model = r_u32(record + 24u);
        uint32 lod_count = 0u;
        while (r_u32(model + 72u))
        {
            if ((sint32)r_u32(0x1F800020u) >= (sint32)r_u32(model + 76u))
                break;
            uint32 lod_handle = r_u32(model + 72u);
            w_u32(record + 256u + 4u * lod_count, lod_handle);
            lod_handle = r_u32(r_u32(record + 24u) + 72u);
            uint32 lod_model = r_u32(lod_handle);
            if (lod_model & 3u)
                lod_model = sub_800257CC(lod_handle);
            else
            {
                w_u16(lod_model - 6u, r_u16(lod_model - 6u) + 1u);
                lod_model = r_u32(r_u32(r_u32(record + 24u) + 72u));
            }
            ++lod_count;
            w_u32(record + 24u, lod_model);
            model = lod_model;
        }
        sub_8003858C(record);
        while (lod_count)
        {
            --lod_count;
            sub_800257A0(r_u32(record + 256u + 4u * lod_count));
        }
        ob_draft_scratch_release(record);
    }
release_model:
    return sub_800257A0(r_u32(a1 + 4u));
}


uint32 sub_8004AAFC(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8004aafcu, "SLES_008.65");
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Bind external adapter for sub_8004B0B0 */
    /* TODO: Bind external adapter for sub_8004B3E8 */
    uint32 local_objects = ob_draft_scratch_acquire(32u);
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
  sint32 v15;
  uint8 v16;
  sint32 v17;
  uint8 v18;
  uint32 v19;
  uint8 v20;
  sint32 v21;
  sint32 v22;
  sint32 v23;
  sint32 v24;
  sint32 v25;
  int64_t v26;
  sint32 result;
  sint8 v28;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  v3 = a2;
  v4 = 0;
  v5 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(40))));
  w_u16((uint32)((sint32)((uint32)(a1) + (uint32)(38))), ((uint32)(r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(38))))) | (uint32)(0x40u)));
  if (!a2)
    v3 = (uint32)(sub_80045464(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))))) + (uint32)(52)))), (sint32)r_u32(0x800775fcu)));
  v6 = r_u32((uint32)((sint32)r_u32(0x80077644u)));
  if (!(r_u32((uint32)((sint32)r_u32(0x80077644u)))))
    ob_draft_unresolved_call(0x8004aafcu, 2u, 7u, 0);
  if (((v6 == (sint32)(0u - (uint32)(1))) && (r_u32(v3) == 0x80000000)))
    ob_draft_unresolved_call(0x8004aafcu, 2u, 6u, 0);
  v7 = (r_u32(v3) % r_u32((uint32)((sint32)r_u32(0x80077644u))));
  v8 = r_u32((v3 + (2) * 4u));
  v9 = ((sint32)(v8) % (sint32)(v6));
  if (((v6 == (sint32)(0u - (uint32)(1))) && (v8 == 0x80000000)))
    ob_draft_unresolved_call(0x8004aafcu, 2u, 6u, 0);
  v10 = (r_u32(v3) % r_u32((uint32)((sint32)r_u32(0x80077644u))));
  v11 = ((sint32)(v8) % (sint32)(v6));
  if (((v7 & 0x8000) != 0))
    v10 = ((uint32)(v10) & ~((uint32)65535u << 0) | (((uint32)((sint32)((uint32)(v7) + (uint32)(v6))) & 65535u) << 0));
  if (((v9 & 0x8000) != 0))
    v11 = (sint32)((uint32)(v9) + (uint32)(v6));
  if (((sint32)((sint32)((uint32)((sint16)(v10)) - (uint32)(v5))) >= (sint32)(0)))
  {
    v12 = (sint32)((uint32)(v11) << (uint32)(16));
    if (((sint32)(v6) >= (sint32)((sint32)((uint32)((sint16)(v10)) + (uint32)(v5)))))
      goto LABEL_20;
    v4 = 3;
  }
  else
  {
    v4 = 1;
  }
  v12 = (sint32)((uint32)(v11) << (uint32)(16));
  LABEL_20:
  v13 = ((sint32)(v12) >> 16);

  v14 = (sint32)((uint32)(((sint32)(v12) >> 16)) - (uint32)(v5));
  v15 = (sint32)((uint32)(v13) + (uint32)(v5));
  if (((sint32)(v14) >= (sint32)(0)))
  {
    v14 = ((sint32)r_u32((uint32)((sint32)r_u32(0x80077644u))) < v15);
    if (((sint32)r_u32((uint32)((sint32)r_u32(0x80077644u))) < v15))
      v4 |= 0xCu;
  }
  else
  {
    v4 |= 4u;
  }
  sub_8004B450((local_objects + 0u), (sint32)((uint32)((((v14 & 0xFFFF0000) | r_u8((uint32)((sint32)((uint32)(a1) + (uint32)(36))))) | ((uint32)(r_u8((uint32)((sint32)((uint32)(a1) + (uint32)(37))))) << (uint32)(8)))) << (uint32)(16)));
  w_u8(local_objects + 8u, r_u8(local_objects + 0u));
  w_u8(local_objects + 9u, r_u8(local_objects + 1u));
  if (((v4 & 1) == 0))
    goto LABEL_35;
  if ((((v4 & 2) != 0) || !r_u8(local_objects + 0u)))
  {
    v17 = (v4 & 4);
    if ((r_u8(local_objects + 0u) >= (sint32)((uint32)((sint32)((uint32)(16) * (uint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x80077644u)) + (uint32)(4))))))) - (uint32)(1))))
      goto LABEL_36;
    if ((r_u8(local_objects + 0u) >= (uint32)((uint8)((sint8)r_u8(0x80077424u)))))
    {
      v16 = ((uint32)(r_u8(local_objects + 8u)) + (uint32)(1));
      goto LABEL_34;
    }
    (w_u8(local_objects + 0u, (r_u8(local_objects + 0u) + 1u)), r_u8(local_objects + 0u));
  }
  else
  {
    if (((uint8)((sint8)r_u8(0x80077424u)) >= (uint32)(r_u8(local_objects + 0u))))
    {
      v16 = ((uint32)(r_u8(local_objects + 8u)) - (uint32)(1));
      LABEL_34:
      w_u8(local_objects + 8u, v16);

      goto LABEL_35;
    }
    (w_u8(local_objects + 0u, (r_u8(local_objects + 0u) - 1u)), r_u8(local_objects + 0u));
  }
  LABEL_35:
  v17 = (v4 & 4);

  LABEL_36:
  if (!v17)
    goto LABEL_48;

  if (((v4 & 8) != 0))
  {
    v18 = r_u8(local_objects + 1u);
    v19 = r_u8(local_objects + 1u);
  }
  else
  {
    v18 = r_u8(local_objects + 1u);
    v19 = r_u8(local_objects + 1u);
    if ((r_u8(local_objects + 1u) < (sint32)((uint32)((sint32)((uint32)(16) * (uint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x80077644u)) + (uint32)(6))))))) - (uint32)(1))))
    {
      if ((r_u8(local_objects + 1u) < (uint32)((uint8)((sint8)r_u8(0x80077425u)))))
      {
        v20 = ((uint32)(r_u8(local_objects + 9u)) + (uint32)(1));
        LABEL_47:
        w_u8(local_objects + 9u, v20);

        goto LABEL_48;
      }
      (w_u8(local_objects + 1u, (r_u8(local_objects + 1u) + 1u)), r_u8(local_objects + 1u));
      goto LABEL_48;
    }
  }
  v21 = (sint32)((uint32)(v4) << (uint32)(16));
  if (!v19)
    goto LABEL_49;
  if (((uint8)((sint8)r_u8(0x80077425u)) < v19))
  {
    v20 = ((uint32)(r_u8(local_objects + 9u)) - (uint32)(1));
    goto LABEL_47;
  }
  w_u8(local_objects + 1u, ((uint32)(v18) - (uint32)(1)));
  LABEL_48:
  v21 = (sint32)((uint32)(v4) << (uint32)(16));

  LABEL_49:
  if (v21)
  {
    v22 = (uint8)((sint8)r_u8(0x80077654u));
    if ((((sint8)r_u8(0x80077654u) & 1) != 0))
    {
      if (((((sint8)r_u8(0x80077654u) == 1) && (r_u8(local_objects + 8u) < (uint32)(r_u8(local_objects + 0u)))) || (((sint8)r_u8(0x80077654u) == 3) && (r_u8(local_objects + 0u) < (uint32)(r_u8(local_objects + 8u))))))
        goto LABEL_70;
      if ((r_u8(local_objects + 0u) != r_u8(local_objects + 8u)))
        goto LABEL_71;
      v22 = r_u8(local_objects + 1u);
      v23 = (r_u8(local_objects + 1u) < (uint32)(r_u8(local_objects + 9u)));
      if ((r_u8(local_objects + 9u) < (uint32)(r_u8(local_objects + 1u))))
      {
        v23 = (r_u8(local_objects + 1u) < (uint32)(r_u8(local_objects + 9u)));
        if ((r_u8(local_objects + 9u) >= (uint32)((uint8)((sint8)r_u8(0x80077425u)))))
          goto LABEL_70;
      }
      if (!v23)
      {
        LABEL_71:
        v26 = ob_draft_unresolved_call(0x8004b0b0u, 3u, (sint32)((uint32)((((v22 & 0xFFFF0000) | r_u8(local_objects + 0u)) | ((uint32)(r_u8(local_objects + 1u)) << (uint32)(8)))) << (uint32)(16)), v3, v5);

        v26 = ((uint64_t)(v26) & ~((uint64_t)4294967295u << 32) | (((uint64_t)((((v26) >> 32) & (0xFFFFFF00))) & 4294967295u) << 32));
        if ((uint32)(v26))
        {
          w_u16((uint32)((sint32)((uint32)(a1) + (uint32)(38))), ((uint32)(r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(38))))) | (uint32)(0x100u)));
          v26 = ((uint64_t)(v26) & ~((uint64_t)4294967295u << 0) | (((uint64_t)(ob_draft_unresolved_call(0x8004b0b0u, 3u, ((uint32)(((((uint32)((v26) >> 32) | r_u8(local_objects + 8u)) & 0xFFFF00FF) | ((uint32)(r_u8(local_objects + 9u)) << (uint32)(8)))) << (uint32)(16)), v3, v5)) & 4294967295u) << 0));
          if ((uint32)(v26))
          {
            v26 = ((uint64_t)(v26) & ~((uint64_t)4294967295u << 0) | (((uint64_t)((sint8)(r_u8(local_objects + 8u))) & 4294967295u) << 0));
            w_u8(local_objects + 0u, r_u8(local_objects + 8u));
            w_u8(local_objects + 1u, r_u8(local_objects + 9u));
          }
        }
        goto LABEL_76;
      }
      v24 = ((uint8)((sint8)r_u8(0x80077425u)) < (uint32)(r_u8(local_objects + 9u)));
    }
    else
    {
      if (((!(sint8)r_u8(0x80077654u) && (r_u8(local_objects + 1u) < (uint32)(r_u8(local_objects + 9u)))) || (((sint8)r_u8(0x80077654u) == 2) && (r_u8(local_objects + 9u) < (uint32)(r_u8(local_objects + 1u))))))
        goto LABEL_70;
      if ((r_u8(local_objects + 1u) != r_u8(local_objects + 9u)))
        goto LABEL_71;
      v22 = r_u8(local_objects + 0u);
      v25 = (r_u8(local_objects + 0u) < (uint32)(r_u8(local_objects + 8u)));
      if ((r_u8(local_objects + 8u) < (uint32)(r_u8(local_objects + 0u))))
      {
        v25 = (r_u8(local_objects + 0u) < (uint32)(r_u8(local_objects + 8u)));
        if ((r_u8(local_objects + 8u) >= (uint32)((uint8)((sint8)r_u8(0x80077424u)))))
          goto LABEL_70;
      }
      if (!v25)
        goto LABEL_71;
      v24 = ((uint8)((sint8)r_u8(0x80077424u)) < (uint32)(r_u8(local_objects + 8u)));
    }
    if (!v24)
    {
      LABEL_70:
      w_u8(local_objects + 16u, r_u8(local_objects + 0u));

      w_u8(local_objects + 17u, r_u8(local_objects + 1u));
      w_u8(local_objects + 0u, r_u8(local_objects + 8u));
      w_u8(local_objects + 1u, r_u8(local_objects + 9u));
      w_u8(local_objects + 8u, r_u8(local_objects + 16u));
      w_u8(local_objects + 9u, r_u8(local_objects + 17u));
      goto LABEL_71;
    }
    goto LABEL_71;
  }

  v26 = ((uint64_t)(v26) & ~((uint64_t)4294967295u << 0) | (((uint64_t)(ob_draft_unresolved_call(0x8004b0b0u, 3u, ((uint32)((r_u8(local_objects + 0u) | ((uint32)(r_u8(local_objects + 1u)) << (uint32)(8)))) << (uint32)(16)), v3, v5)) & 4294967295u) << 0));
  if ((uint32)(v26))
  {
    v26 = ((uint64_t)(v26) & ~((uint64_t)4294967295u << 0) | (((uint64_t)((r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(38)))) | 0x100)) & 4294967295u) << 0));
    w_u16((uint32)((sint32)((uint32)(a1) + (uint32)(38))), v26);
  }
  LABEL_76:
  ob_draft_unresolved_call(0x8004b3e8u, 2u, (local_objects + 24u), ((uint64_t)((((v26 & 0xFFFF0000) | r_u8(local_objects + 0u)) | ((uint32)(r_u8(local_objects + 1u)) << (uint32)(8)))) << (uint64_t)(16)));

  result = (sint8)r_u8(((local_objects + 24u) + (0) * 1u));
  v28 = (sint8)r_u8(((local_objects + 24u) + (1) * 1u));
  w_u8((uint32)((sint32)((uint32)(a1) + (uint32)(36))), (sint8)r_u8(((local_objects + 24u) + (0) * 1u)));
  w_u8((uint32)((sint32)((uint32)(a1) + (uint32)(37))), v28);
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80023308(uint32 a1)
{
    FUNCTION_MARKER(0x80023308u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80055FD8 */
    /* TODO: Bind external adapter for sub_8001B048 */
    /* TODO: Bind external adapter for sub_80044D50 */
    /* TODO: Bind external adapter for sub_8001D1B0 */
    /* TODO: Bind external adapter for sub_80054320 */
    /* TODO: Bind external adapter for sub_8005C504 */
    /* TODO: Bind external adapter for sub_8002CFA8 */
    /* TODO: Bind external adapter for sub_8001DF34 */
    /* TODO: Bind external adapter for sub_8001B008 */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Bind external adapter for sub_8002CFE4 */
    /* TODO: Bind external adapter for sub_80035220 */
    uint32 local_objects = ob_draft_scratch_acquire(64u);

  sint32 v3;
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
  sint32 v15;
  sint32 v16;
  sint32 v17;
  sint32 v18;
  sint32 v19;
  sint32 v20;
  sint32 v21;
  sint32 v22;
  sint32 v23;
  sint32 v24;
  sint8 v25;
  ;
  ;
  ;
  ;
  ;
  ;
  w_u32(((local_objects + 0u) + (0) * 4u), (sint32)r_u32(0x80010888u));
  w_u32(((local_objects + 0u) + (1) * 4u), (sint32)r_u32(0x8001088cu));
  w_u32(((local_objects + 0u) + (2) * 4u), (sint32)r_u32(0x80010890u));
  w_u32(((local_objects + 16u) + (0) * 4u), (sint32)r_u32(0x80010894u));
  w_u32(((local_objects + 16u) + (1) * 4u), (sint32)r_u32(0x80010898u));
  w_u32(((local_objects + 16u) + (2) * 4u), (sint32)r_u32(0x8001089cu));
  w_u32(((local_objects + 32u) + (0) * 4u), (sint32)r_u32(0x800108a0u));
  w_u32(((local_objects + 32u) + (1) * 4u), (sint32)r_u32(0x800108a4u));
  w_u32(((local_objects + 32u) + (2) * 4u), (sint32)r_u32(0x800108a8u));
  w_u32(((local_objects + 32u) + (3) * 4u), (sint32)r_u32(0x800108acu));
  w_u16(local_objects + 48u, (sint16)r_u16(0x800108b0u));
  sub_8005577C(128);
  sub_80021EFC();
  sub_800170F8(0);
  ob_draft_unresolved_call(0x80055fd8u, 2u, 0, (sint32)(0u - (uint32)(2146919536)));
  w_u32(0x80083E30, sub_800251E8((0x8006aa84u)));
  sub_800256CC(0x8006AA88u);
  sub_80022058();
  sub_80055808();
  sub_800174CC(61440);
  sub_80021A38(0);
  sub_8001F874();
  ob_draft_unresolved_call(0x80055fd8u, 2u, 0, (sint32)(0u - (uint32)(2146919536)));
  sub_8001F9B0(2, 1);
  sub_8001DF58((uint32)r_u8(0x8006c22eu));
  sub_800544EC();
  w_u16(0x8008C704u, 12288u);
  w_u16(0x8008C706, (sint32)(0u - (uint32)(5888)));
  w_u16(0x8008CF8A, (sint32)(0u - (uint32)(13568)));
  w_u16(0x8008C708, 12288);
  w_u16(0x8008CF88, 0);
  w_u16(0x8008CF8C, (sint32)(0u - (uint32)(4096)));
  w_u32(0x80066030u, 0u);
  sub_80030700(0, 0, 0);
  sub_8003077C((sint32)(0u - (uint32)(2146908412)), 255, 2, 255, 255u, 255u);
  ob_draft_unresolved_call(0x80044d50u, 0u);
  sub_80044DBC((local_objects + 0u), (local_objects + 32u), (local_objects + 16u), (sint32)r_u32(0x80077334u));
  sub_800224A0();
  /* TODO Overlay code targets remain unresolved until their actual loaded implementations are bound */
  if (a1)
  {
    ob_draft_unresolved_call(0x80095094u, 0u);
  }
  else
  {
    w_u8(0x8006c231u, 0);
    v3 = 0;
    ob_draft_unresolved_call(0x8001d1b0u, 0u);
    w_u32(local_objects + 60u, ob_draft_unresolved_call(0x80097E5Cu, 1u, (sint32)(0u - (uint32)(2146842468))));
    v5 = ob_draft_unresolved_call(0x80097EF8u, 1u, (sint32)(0u - (uint32)(2146842324)));
    v4 = ob_draft_unresolved_call(0x80097E5Cu, 1u, (sint32)(0u - (uint32)(2146842444)));
    v7 = ob_draft_unresolved_call(0x80098058u, 3u, (sint32)r_u32(local_objects + 60u), v5, v4);
    v6 = ob_draft_unresolved_call(0x80097EF8u, 1u, (sint32)(0u - (uint32)(2146842220)));
    ob_draft_unresolved_call(0x80097FE8u, 2u, (sint32)r_u32(local_objects + 60u), v6);
    v9 = ob_draft_unresolved_call(0x80097EF8u, 1u, (sint32)(0u - (uint32)(2146842168)));
    v8 = ob_draft_unresolved_call(0x80097E5Cu, 1u, (sint32)(0u - (uint32)(2146842396)));
    v11 = ob_draft_unresolved_call(0x80098058u, 3u, (sint32)r_u32(local_objects + 60u), v9, v8);
    v10 = ob_draft_unresolved_call(0x80097EF8u, 1u, (sint32)(0u - (uint32)(2146841856)));
    ob_draft_unresolved_call(0x80097FE8u, 2u, v11, v10);
    v12 = ob_draft_unresolved_call(0x80097EF8u, 1u, (sint32)(0u - (uint32)(2146841804)));
    ob_draft_unresolved_call(0x80097FE8u, 2u, v11, v12);
    v13 = ob_draft_unresolved_call(0x80097EF8u, 1u, (sint32)(0u - (uint32)(2146841752)));
    ob_draft_unresolved_call(0x80097FE8u, 2u, v11, v13);
    v14 = ob_draft_unresolved_call(0x80097EF8u, 1u, (sint32)(0u - (uint32)(2146841700)));
    ob_draft_unresolved_call(0x80097FE8u, 2u, v11, v14);
    v15 = ob_draft_unresolved_call(0x80097EF8u, 1u, (sint32)(0u - (uint32)(2146841648)));
    ob_draft_unresolved_call(0x80097FE8u, 2u, v11, v15);
    v16 = ob_draft_unresolved_call(0x80097EF8u, 1u, (sint32)(0u - (uint32)(2146842116)));
    ob_draft_unresolved_call(0x80097FE8u, 2u, v7, v16);
    v18 = ob_draft_unresolved_call(0x80097EF8u, 1u, (sint32)(0u - (uint32)(2146842012)));
    v17 = ob_draft_unresolved_call(0x80097E5Cu, 1u, (sint32)(0u - (uint32)(2146842372)));
    v20 = ob_draft_unresolved_call(0x80098058u, 3u, v7, v18, v17);
    v19 = ob_draft_unresolved_call(0x80097EF8u, 1u, (sint32)(0u - (uint32)(2146841908)));
    ob_draft_unresolved_call(0x80097FE8u, 2u, v7, v19);
    do
    {
      v21 = ob_draft_unresolved_call(0x80097EF8u, 1u, (sint32)(0u - (uint32)(2146841596)));
      w_u32((uint32)(ob_draft_unresolved_call(0x80097FE8u, 2u, v20, v21)), v3++);
    }
    while (((sint32)(v3) < (sint32)(6)));
    ob_draft_unresolved_call(0x8009789Cu, 1u, (sint32)r_u32(local_objects + 60u));
    w_u32(local_objects + 56u, (sint32)r_u32(local_objects + 60u));
    ob_draft_unresolved_call(0x80094790u, 1u, 3000);
    while (1)
    {
      ob_draft_unresolved_call(0x80054320u, 0u);
      sub_8002D25C((sint32)(0u - (uint32)(2146906416)), (sint32)(0u - (uint32)(2146931856)));
      sub_80012184();
      sub_8001FC60();
      v22 = ob_draft_unresolved_call(0x80097944u, 1u, (local_objects + 56u));
      if ((sint32)r_u32(0x8009BB94))
        ob_draft_unresolved_call(0x80093E70u, 1u, r_u32(0x8009BB94u));
      while (r_u32(0x80077620u))
        ob_native_pump();

      ob_draft_unresolved_call(0x8005c504u, 1u, 0);
      w_u32(0x8007754cu, (sint32)r_u32(0x8007737cu));
      ob_draft_unresolved_call(0x8002cfa8u, 0u);
      w_u32(0x80077620u, 1);
      if ((v22 == 100))
      {
        v23 = ob_draft_unresolved_call(0x80095094u, 1u, 0);
        if (v23)
        {
          if ((((sint32)(v23) > (sint32)(0)) && (v23 == 1)))
          {
            ob_draft_unresolved_call(0x800947B4u, 0u);
            w_u8(0x8006c233u, 0);
            sub_8001DF58((uint32)r_u8(0x8006c22eu));
            ob_draft_unresolved_call(0x8001df34u, 1u, (uint32)r_u8(0x8006c22du));
          }
        }
        else
        {
          w_u32(local_objects + 56u, v7);
          ob_draft_unresolved_call(0x8009789Cu, 1u, v7);
          v22 = (sint32)(0u - (uint32)(1));
          sub_8001DF58((uint32)r_u8(0x8006c22eu));
          ob_draft_unresolved_call(0x8001df34u, 1u, (uint32)r_u8(0x8006c22du));
        }
      }
      else
        if ((v22 == 200))
      {
        v24 = ob_draft_unresolved_call(0x80098298u, 1u, 5);
        if (v24)
        {
          if ((v24 == 1))
          {
            w_u8(0x8006c233u, 0);
            w_u32(0x800771d0u, 1);
            w_u8(0x8006c231u, (sint32)((uint32)((uint32)r_u8(0x8006c247u)) + (uint32)(20)));
            ob_draft_unresolved_call(0x800947B4u, 0u);
          }
        }
        else
        {
          v22 = (sint32)(0u - (uint32)(1));
          w_u32(local_objects + 56u, (sint32)r_u32(local_objects + 60u));
          ob_draft_unresolved_call(0x8009789Cu, 1u, r_u32(local_objects + 60u));
        }
      }
      else
      {
        w_u32(0x800771d0u, 0);
      }
      if ((((sint32)r_u32(local_objects + 56u) == (sint32)r_u32(local_objects + 60u)) && ((sint32)((sint32)r_u32(0x8008969C)) <= (sint32)(0))))
        break;
      if ((v22 != (sint32)(0u - (uint32)(1))))
        goto LABEL_33;
    }

    w_u8(0x8006c230u, 1);
    w_u8(0x8006c233u, 1);
    w_u8(0x8006c234u, (((sint32)ob_draft_unresolved_call(0x8001b008u, 0u) >> 4) % 5));
    switch ((uint32)r_u8(0x8006c234u))
    {
      case 0:
        v25 = 2;
        goto LABEL_30;

      case 1:
        v25 = 5;
        goto LABEL_30;

      case 2:
        v25 = 9;
        goto LABEL_30;

      case 3:
        v25 = 13;
        goto LABEL_30;

      case 4:
        v25 = 16;
        LABEL_30:
      w_u8(0x8006c231u, v25);

        break;

      default:
        break;

    }

    ob_draft_unresolved_call(0x8001d1b0u, 0u);
    ob_draft_unresolved_call(0x800978F0u, 1u, (sint32)r_u32(local_objects + 56u));
    LABEL_33:
    sub_8001FC60();

    sub_80012184();
    ob_draft_unresolved_call(0x800981C8u, 1u, (local_objects + 60u));
  }
  /* The original callback setter return is unused */
  w_u32(0x80073518u, 0u);
  sub_80021AD8();
  sub_80017554();
  sub_800259AC((0x8006aa84u));
  sub_80026418();
  ob_draft_unresolved_call(0x80035220u, 0u);
  sub_80017178();
  { uint32 draft_return = sub_80024D54(0x3FFFF); ob_draft_scratch_release(local_objects);  return draft_return; }
}



