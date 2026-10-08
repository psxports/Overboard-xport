#include "draft_signatures.h"
#include "native_runtime.h"
#include <stdint.h>

/* Unverified draft bodies */

sint32 sub_8001E540(void)
{
    FUNCTION_MARKER(0x8001e540u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80062930 */
    /* TODO: Bind external adapter for sub_8006272C */
  sint32 result;
  sint32 v1;
  sint32 v2;
  sint32 v3;
  sint32 i;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  sint32 v11;
  sint32 v12;
  result = (uint8)((sint8)r_u8(0x8006C00Cu));
  if ((sint8)r_u8(0x8006C00Cu))
  {
    v1 = 0;
    v2 = 0;
    v3 = (0u - (uint32)(2146991456));
    for (i = 0;; i += 28)
    {
      v5 = r_u32((uint32)((sint32)((uint32)(i) - (uint32)(2146991452))));
      if ((v5 == 1))
        v1 |= (sint32)((uint32)(1) << (uint32)(v2));
      if (((r_u32((uint32)(v3)) & 1) == 0))
        goto LABEL_18;
      if (v5)
        goto LABEL_19;
      v6 = ob_draft_unresolved_call(0x80062930u, 1u, (sint32)((uint32)(1) << (uint32)(v2)));
      if (v6)
      {
        if ((v6 != 3))
          goto LABEL_18;
      }
      v7 = r_u32((uint32)((sint32)((uint32)(i) - (uint32)(2146991436))));
      if ((sint8)r_u8(0x8006C00Fu))
      {
        v8 = (sint32)((uint32)(8) * (uint32)(v7));
        if (((r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(28) * (uint32)(v7))) - (uint32)(2146990780)))) & 2) == 0))
          goto LABEL_13;
        ob_draft_unresolved_call(r_u32(0x8008AE74), 1u, r_u32((uint32)((sint32)((uint32)(i) - (uint32)(2146991436)))));
      }
      v8 = (sint32)((uint32)(8) * (uint32)(v7));
      LABEL_13:
      v9 = (sint32)((uint32)(4) * (uint32)((sint32)((uint32)(v8) - (uint32)(v7))));

      w_u32((uint32)(v3), 0);
      v10 = r_u32((uint32)((sint32)((uint32)(v9) - (uint32)(2146990780))));
      if (((v10 & 2) != 0))
      {
        if (((v10 & 4) != 0))
        {
          v11 = (sint32)((uint32)(28) * (uint32)(r_u32((uint32)((sint32)((uint32)(v9) - (uint32)(2146990768))))));
          w_u32((uint32)((sint32)((uint32)((sint32)((uint32)(28) * (uint32)((sint8)r_u8((uint32)((sint32)((uint32)(v11) - (uint32)(2146990764))))))) - (uint32)(2146991456))), ((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(28) * (uint32)((sint8)r_u8((uint32)((sint32)((uint32)(v11) - (uint32)(2146990764))))))) - (uint32)(2146991456))))) & (uint32)(~4u)));
          v12 = (sint8)r_u8((uint32)((sint32)((uint32)(v11) - (uint32)(2146990763))));
          if ((v12 >= 0))
            w_u32((uint32)((sint32)((uint32)((sint32)((uint32)(28) * (uint32)(v12))) - (uint32)(2146991456))), ((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(28) * (uint32)(v12))) - (uint32)(2146991456))))) & (uint32)(~4u)));
        }
      }
      else
      {
        w_u32((uint32)((sint32)((uint32)(v9) - (uint32)(2146990780))), 0);
      }
      LABEL_18:
      if (r_u32((uint32)((sint32)((uint32)(i) - (uint32)(2146991452)))))
      {
        LABEL_19:
        if (((r_u32((uint32)(v3)) & 4) == 0))
          (w_u32((uint32)((sint32)((uint32)(i) - (uint32)(2146991452))), (r_u32((uint32)((sint32)((uint32)(i) - (uint32)(2146991452)))) - 1u)), r_u32((uint32)((sint32)((uint32)(i) - (uint32)(2146991452)))));

      }

      v3 += 28;
      result = (++v2 < 24);
      if ((v2 >= 24))
      {
        if ((v1 > 0))
          return ob_draft_unresolved_call(0x8006272cu, 2u, 1, v1);
        return result;
      }
    }

  }
  return result;
}


sint32 sub_80024F24(uint32 a1)
{
    FUNCTION_MARKER(0x80024f24u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80025D6C */
    /* TODO: Bind external adapter for sub_80025D50 */
    /* TODO: Bind external adapter for sub_80027D78 */
    /* TODO: Bind external adapter for sub_80027A3C */
    /* TODO: Bind external adapter for sub_80027DF8 */
    uint32 local_objects = ob_draft_scratch_acquire(144u);
  uint32 v1;
  sint32 v2;
  uint32 v3;
  sint32 v4;
  uint32 v5;
  uint32 v6;
  sint32 v7;
  uint32 v8;
  sint32 result;
  sint32 v10;
  sint32 v11;
  sint32 v12;
  sint32 v13;
  uint32 v14;
  sint32 v15;
  uint32 v16;
  sint32 v17;
  uint16 v18;
  uint16 v19;
  ;
  ;
  v1 = a1;
  v2 = r_u8(a1);
  v3 = (local_objects + 0u);
  w_u8(((local_objects + 0u) + (0) * 1u), v2);
  if (v2)
  {
    do
    {
      v4 = r_u8(((v1 += 1u)));
      w_u8(((v3 += 1u)), v4);
    }
    while (v4);
  }
  v5 = v3;
  sub_80025D50(v5, 0x80077094u);
  v6 = sub_80025CB4((local_objects + 128u), (local_objects + 0u));
  v7 = (sint32)r_u32(((local_objects + 128u) + (0) * 4u));
  v8 = (v6 < 0xC);
  result = 100;
  if (!v8)
  {
    v8 = (ob_draft_unresolved_call(0x80025d6cu, 2u, (sint32)r_u32(((local_objects + 128u) + (0) * 4u)), 0x8007709Cu) == 0);
    result = 100;
    if (!v8)
    {
      w_u32(0x80077210u, r_u32((uint32)((sint32)((uint32)(v7) + (uint32)(8)))));
      v10 = (sint32)((uint32)(v7) + (uint32)(12));
      if (((sint32)r_u32(0x80077210u) < 32))
      {
        v11 = 0;
        if (((sint32)r_u32(0x80077210u) <= 0))
        {
          LABEL_11:
          sub_80026758((local_objects + 128u));

          sub_80025D50(v5, 0x800770A4u);
          v14 = sub_80025CB4((local_objects + 128u), (local_objects + 0u));
          v15 = (sint32)r_u32(((local_objects + 128u) + (0) * 4u));
          v8 = (v14 < 0x10);
          result = 200;
          if (!v8)
          {
            v16 = (uint32)((sint32)((uint32)((sint32)r_u32(((local_objects + 128u) + (0) * 4u))) + (uint32)(20)));
            if (ob_draft_unresolved_call(0x80025d6cu, 2u, (sint32)r_u32(((local_objects + 128u) + (0) * 4u)), 0x800770ACu))
            {
              v17 = r_u32((uint32)((sint32)((uint32)(v15) + (uint32)(8))));
              w_u16(0x800775F2u, v17);
              v18 = 1;
              if (((uint16)(v17) <= 1u))
              {
                LABEL_21:
                sub_80026758((local_objects + 128u));

                v19 = ob_draft_unresolved_call(0x80027d78u, 1u, (0x80066048u));
                ob_draft_unresolved_call(0x80027a3cu, 2u, v19, 0x8002512Cu);
                { uint32 draft_return = 0; ob_draft_scratch_release(local_objects);  return draft_return; }
              }
              else
              {
                while (1)
                {
                  v8 = (sub_80027CD0(v18) == 0);
                  result = 201;
                  if (v8)
                    break;
                  if ((r_u32(v16) == 257))
                    sub_800279D4(v18);
                  else
                    w_u32((uint32)(ob_draft_unresolved_call(0x80027df8u, 1u, v18)), r_u32(v16));
                  ++v18;
                  ((v16 += 4u));
                  if ((v18 >= (uint32)((uint16)((sint16)r_u16(0x800775F2u)))))
                    goto LABEL_21;
                }

              }
            }
            else
            {
              { uint32 draft_return = 200; ob_draft_scratch_release(local_objects);  return draft_return; }
            }
          }
        }
        else
        {
          v12 = (0u - (uint32)(2146988600));
          while (1)
          {
            v13 = sub_80054EFC(v10);
            w_u32((uint32)(v12), v13);
            if ((v13 < 0))
              { uint32 draft_return = 102; ob_draft_scratch_release(local_objects);  return draft_return; }
            v10 += 64;
            ++v11;
            v12 += 4;
            if ((v11 >= (sint32)r_u32(0x80077210u)))
              goto LABEL_11;
          }

        }
      }
      else
      {
        { uint32 draft_return = 101; ob_draft_scratch_release(local_objects);  return draft_return; }
      }
    }
  }
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


sint32 sub_80042928(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80042928u, "SLES_008.65");
  uint32 v4;
  uint32 v5;
  uint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  uint32 v10;
  sint32 v11;
  uint32 v12;
  sint32 v13;
  uint32 v14;
  sint32 v15;
  uint32 v16;
  sint32 v17;
  uint32 v18;
  sint32 v19;
  uint32 v20;
  sint32 v21;
  uint32 v22;
  sint32 v23;
  uint32 v24;
  sint32 v25;
  uint32 v26;
  sint32 v27;
  uint32 v28;
  sint32 result;
  v4 = (uint32)(a2);
  v5 = a1;
  v6 = (a1 + (40) * 2u);
  do
  {
    v7 = r_u32(((uint32)(v5) + (1) * 4u));
    v8 = r_u32(((uint32)(v5) + (2) * 4u));
    v9 = r_u32(((uint32)(v5) + (3) * 4u));
    w_u32(v4, r_u32((uint32)(v5)));
    w_u32((v4 + (1) * 4u), v7);
    w_u32((v4 + (2) * 4u), v8);
    w_u32((v4 + (3) * 4u), v9);
    v5 += (8) * 2u;
    v4 += (4) * 4u;
  }
  while ((v5 != v6));
  v10 = (uint32)((sint32)r_u32(0x80077590u));
  v11 = (sint32)((uint32)((sint16)r_u16(a1)) * (uint32)((sint16)r_u16((uint32)((sint32)r_u32(0x80077590u)))));
  if ((((sint16)r_u16(a1) ^ (sint16)r_u16((uint32)((sint32)r_u32(0x80077590u)))) < 0))
    v12 = (sint32)((uint32)(v11) - (uint32)(0x2000));
  else
    v12 = (sint32)((uint32)(v11) + (uint32)(0x2000));
  w_u16((uint32)(a2), (v12 >> 14));
  v13 = (sint32)((uint32)((sint16)r_u16((a1 + (1) * 2u))) * (uint32)((sint16)r_u16((v10 + (4) * 2u))));
  v14 = (sint32)((uint32)(v13) + (uint32)(0x2000));
  if ((((sint16)r_u16((a1 + (1) * 2u)) ^ (sint16)r_u16((v10 + (4) * 2u))) < 0))
    v14 = (sint32)((uint32)(v13) - (uint32)(0x2000));
  w_u16((uint32)((sint32)((uint32)(a2) + (uint32)(2))), (v14 >> 14));
  v15 = (sint32)((uint32)((sint16)r_u16((a1 + (2) * 2u))) * (uint32)((sint16)r_u16((v10 + (8) * 2u))));
  v16 = (sint32)((uint32)(v15) + (uint32)(0x2000));
  if ((((sint16)r_u16((a1 + (2) * 2u)) ^ (sint16)r_u16((v10 + (8) * 2u))) < 0))
    v16 = (sint32)((uint32)(v15) - (uint32)(0x2000));
  w_u16((uint32)((sint32)((uint32)(a2) + (uint32)(4))), (v16 >> 14));
  v17 = (sint32)((uint32)((sint16)r_u16((a1 + (3) * 2u))) * (uint32)((sint16)r_u16(v10)));
  v18 = (sint32)((uint32)(v17) + (uint32)(0x2000));
  if ((((sint16)r_u16((a1 + (3) * 2u)) ^ (sint16)r_u16(v10)) < 0))
    v18 = (sint32)((uint32)(v17) - (uint32)(0x2000));
  w_u16((uint32)((sint32)((uint32)(a2) + (uint32)(6))), (v18 >> 14));
  v19 = (sint32)((uint32)((sint16)r_u16((a1 + (4) * 2u))) * (uint32)((sint16)r_u16((v10 + (4) * 2u))));
  v20 = (sint32)((uint32)(v19) + (uint32)(0x2000));
  if ((((sint16)r_u16((a1 + (4) * 2u)) ^ (sint16)r_u16((v10 + (4) * 2u))) < 0))
    v20 = (sint32)((uint32)(v19) - (uint32)(0x2000));
  w_u16((uint32)((sint32)((uint32)(a2) + (uint32)(8))), (v20 >> 14));
  v21 = (sint32)((uint32)((sint16)r_u16((a1 + (5) * 2u))) * (uint32)((sint16)r_u16((v10 + (8) * 2u))));
  v22 = (sint32)((uint32)(v21) + (uint32)(0x2000));
  if ((((sint16)r_u16((a1 + (5) * 2u)) ^ (sint16)r_u16((v10 + (8) * 2u))) < 0))
    v22 = (sint32)((uint32)(v21) - (uint32)(0x2000));
  w_u16((uint32)((sint32)((uint32)(a2) + (uint32)(10))), (v22 >> 14));
  v23 = (sint32)((uint32)((sint16)r_u16((a1 + (6) * 2u))) * (uint32)((sint16)r_u16(v10)));
  v24 = (sint32)((uint32)(v23) + (uint32)(0x2000));
  if ((((sint16)r_u16((a1 + (6) * 2u)) ^ (sint16)r_u16(v10)) < 0))
    v24 = (sint32)((uint32)(v23) - (uint32)(0x2000));
  w_u16((uint32)((sint32)((uint32)(a2) + (uint32)(12))), (v24 >> 14));
  v25 = (sint32)((uint32)((sint16)r_u16((a1 + (7) * 2u))) * (uint32)((sint16)r_u16((v10 + (4) * 2u))));
  v26 = (sint32)((uint32)(v25) + (uint32)(0x2000));
  if ((((sint16)r_u16((a1 + (7) * 2u)) ^ (sint16)r_u16((v10 + (4) * 2u))) < 0))
    v26 = (sint32)((uint32)(v25) - (uint32)(0x2000));
  w_u16((uint32)((sint32)((uint32)(a2) + (uint32)(14))), (v26 >> 14));
  v27 = (sint32)((uint32)((sint16)r_u16((a1 + (8) * 2u))) * (uint32)((sint16)r_u16((v10 + (8) * 2u))));
  v28 = (sint32)((uint32)(v27) + (uint32)(0x2000));
  if ((((sint16)r_u16((a1 + (8) * 2u)) ^ (sint16)r_u16((v10 + (8) * 2u))) < 0))
    v28 = (sint32)((uint32)(v27) - (uint32)(0x2000));
  w_u16((uint32)((sint32)((uint32)(a2) + (uint32)(16))), (v28 >> 14));
  if (((r_u32(((uint32)(a1) + (12) * 4u)) & 0x20) != 0))
    sub_8002FED4(((uint32)(a1) + (6) * 4u), v10, (uint32)((sint32)((uint32)(a2) + (uint32)(24))));
  result = (r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(48)))) | 0x10);
  w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(48))), result);
  return result;
}


sint32 sub_8001578C(sint32 a1, sint32 a2, sint32 a3, sint32 a4)
{
    FUNCTION_MARKER(0x8001578cu, "SLES_008.65");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Bind external adapter for sub_80020A70 */
    /* TODO: Bind external adapter for sub_80020FD4 */
  sint32 v7;
  sint32 v8;
  uint32 v9;
  sint32 v10;
  sint32 v11;
  sint32 v12;
  sint32 v13;
  sint32 v14;
  sint32 v15;
  sint32 v16;
  sint32 v17;
  sint32 result;
  v7 = (sint32)((uint32)(2) * (uint32)((sint32)r_u32(0x8006C174u)));
  if (a4)
    v8 = (sint32)((uint32)(20) * (uint32)((sint32)r_u32(0x8006C174u)));
  else
    v8 = (sint32)((uint32)(3) * (uint32)((sint32)r_u32(0x8006C174u)));
  v9 = ((0x8006c138u + (a1) * 4u));
  v10 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v9)) + (uint32)(108))));
  v11 = (uint16)(ob_draft_unresolved_call(r_u32(0x800901A8), 1u, 255));
  v12 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v9)) + (uint32)(288))));
  v13 = ((sint32)((uint32)(59) * (uint32)(r_u16((uint32)((sint32)((uint32)(v10) + (uint32)(174)))))) / v11);
  if (((v12 == 21) || (v12 == 23)))
  {
    v14 = (sint32)r_u32(0x8006C174u);
    v15 = (sint32)((uint32)(v13) * (uint32)((sint32)r_u32(0x8006C174u)));
    v16 = (sint32)((uint32)(a2) + (uint32)(v7));
    v17 = (sint32)((uint32)(a3) + (uint32)(v8));
  }
  else
    if ((v13 >= 19))
  {
    v16 = (sint32)((uint32)(a2) + (uint32)(v7));
    v14 = (sint32)r_u32(0x8006C174u);
    v15 = (sint32)((uint32)(v13) * (uint32)((sint32)r_u32(0x8006C174u)));
    v17 = (sint32)((uint32)(a3) + (uint32)(v8));
  }
  else
  {
    result = ((sint32)r_u32(0x80065D30u) & 2);
    v16 = (sint32)((uint32)(a2) + (uint32)(v7));
    if ((((sint32)r_u32(0x80065D30u) & 2) == 0))
      goto LABEL_12;
    v14 = (sint32)r_u32(0x8006C174u);
    v15 = (sint32)((uint32)(v13) * (uint32)((sint32)r_u32(0x8006C174u)));
    v17 = (sint32)((uint32)(a3) + (uint32)(v8));
  }
  result = ob_draft_unresolved_call(0x80020a70u, 4u, v16, v17, v15, (sint32)((uint32)(10) * (uint32)(v14)));
  LABEL_12:
  if (!a4)
    return ob_draft_unresolved_call(0x80020fd4u, 4u, (0x800666B4u), 0, 0, 63);

  return result;
}


uint32 sub_8004FA0C(uint32 a1, uint32 a2, uint32 a3, uint32 a4, sint32 a5, sint32 a6)
{
    FUNCTION_MARKER(0x8004fa0cu, "SLES_008.65");
    /* TODO: Resolve meaningful argument carriers for sub_8004FC64 without dropping supplied values */
  sint32 v10;
  sint32 v13;
  sint32 v14;
  sint32 v15;
  sint16 v16;
  sint32 v17;
  sint32 v18;
  uint32 result;
  uint32 v20;
  sint32 v21;
  sint32 v22;
  sint32 v23;
  sint32 v24;
  sint32 v25;
  sint32 v26;
  sint32 v27;
  sint32 v28;
  sint32 v29;
  sint8 v30;
  v10 = (sint32)r_u32(0x800775A8u);
  w_u32((uint32)(a1), a6);
  w_u32((uint32)(((uint32)(a1) + (uint32)(4))), ((uint32)(r_u32(a3)) + (uint32)(v10)));
  w_u32((uint32)(((uint32)(a1) + (uint32)(8))), r_u32((a3 + (1) * 4u)));
  w_u32((uint32)(((uint32)(a1) + (uint32)(12))), (sint32)((uint32)((sint32)r_u32(0x800775B0u)) - (uint32)(r_u32((a3 + (2) * 4u)))));
  w_u32((uint32)(((uint32)(a1) + (uint32)(16))), r_u32(a2));
  w_u32((uint32)(((uint32)(a1) + (uint32)(20))), r_u32((a2 + (1) * 4u)));
  w_u32((uint32)(((uint32)(a1) + (uint32)(24))), r_u32((a2 + (2) * 4u)));
  w_u16((uint32)(((uint32)(a1) + (uint32)(40))), r_u32(a4));
  w_u16((uint32)(((uint32)(a1) + (uint32)(42))), r_u32((a4 + (1) * 4u)));
  v13 = r_u32((a4 + (2) * 4u));
  w_u32((uint32)(((uint32)(a1) + (uint32)(108))), 2147483393);
  w_u32((uint32)(((uint32)(a1) + (uint32)(84))), 2147483393);
  w_u32((uint32)(((uint32)(a1) + (uint32)(80))), 2147483393);
  v14 = (sint16)r_u16((uint32)(((uint32)(a1) + (uint32)(42))));
  w_u32((uint32)(((uint32)(a1) + (uint32)(100))), 0);
  w_u32((uint32)(((uint32)(a1) + (uint32)(52))), a5);
  w_u16((uint32)(((uint32)(a1) + (uint32)(44))), (0u - (uint32)((sint16)(v13))));
  if (v14)
  {
    w_u16((uint32)(((uint32)(a1) + (uint32)(46))), 0);
  }
  else
  {
    v15 = r_u32((uint32)(((uint32)(a1) + (uint32)(8))));
    v16 = 8;
    if ((v15 >= (0u - (uint32)(640000))))
    {
      v16 = 4;
      if ((v15 >= (0u - (uint32)(12800))))
      {
        v16 = 1;
        if ((v15 <= 1638399))
          v16 = 2;
      }
    }
    w_u16((uint32)(((uint32)(a1) + (uint32)(46))), v16);
  }
  v17 = r_u32((uint32)(((uint32)(a1) + (uint32)(4))));
  v18 = r_u32((uint32)(((uint32)(a1) + (uint32)(16))));
  result = (uint32)((sint32)((uint32)(v17) - (uint32)(v18)));
  v20 = ((sint32)((uint32)(v17) - (uint32)(v18)) < 0);
  v21 = (sint32)((uint32)(v17) + (uint32)(v18));
  if (v20 || (result = (uint32)((sint32)r_u32(0x80077528u) < v21)) != 0 || ((v22 = r_u32(a1 + 12u)), (v23 = r_u32(a1 + 24u)), (result = v22 - v23), (v20 = (sint32)(v22 - v23) < 0), (v24 = (sint32)(v22 + v23)), v20) || (result = (uint32)((sint32)r_u32(0x80077534u) < v24)) != 0)
  {
    w_u32((uint32)(((uint32)(a1) + (uint32)(48))), 0);
  }
  else
  {
    v25 = r_u32((uint32)(((uint32)(a1) + (uint32)(4))));
    v26 = r_u32((uint32)(((uint32)(a1) + (uint32)(8))));
    v27 = r_u32((uint32)(((uint32)(a1) + (uint32)(12))));
    w_u32((uint32)(((uint32)(a1) + (uint32)(48))), (0u - (uint32)(1)));
    w_u32((uint32)(((uint32)(a1) + (uint32)(176))), a6);
    w_u32((uint32)(((uint32)(a1) + (uint32)(164))), v25);
    w_u32((uint32)(((uint32)(a1) + (uint32)(168))), v26);
    w_u32((uint32)(((uint32)(a1) + (uint32)(172))), v27);
    sub_80051450(((uint32)(a1) + (uint32)(4)), ((uint32)(a1) + (uint32)(132)));
    v28 = (sint32)r_u32(0x800775CCu);
    v29 = r_u32((uint32)(((uint32)(a1) + (uint32)(144))));
    w_u32((uint32)(((uint32)(a1) + (uint32)(156))), 2);
    w_u8((uint32)(((uint32)(a1) + (uint32)(148))), 2);
    w_u32((uint32)(((uint32)(a1) + (uint32)(160))), v28);
    v30 = r_u8((uint32)((sint32)((uint32)(v29) + (uint32)(22))));
    w_u32((uint32)(((uint32)(a1) + (uint32)(296))), a1);
    w_u32((uint32)(((uint32)(a1) + (uint32)(416))), a1);
    w_u8((uint32)(((uint32)(a1) + (uint32)(149))), v30);
    ob_draft_unresolved_call(0x8004fc64u, 4u, ((uint32)(a1) + (uint32)(204)), r_u32((uint32)(((uint32)(a1) + (uint32)(4)))), r_u32(a4), r_u32((uint32)(((uint32)(a1) + (uint32)(16)))));
    ob_draft_unresolved_call(0x8004fc64u, 4u, ((uint32)(a1) + (uint32)(324)), r_u32((uint32)(((uint32)(a1) + (uint32)(12)))), (0u - (uint32)(r_u32((a4 + (2) * 4u)))), r_u32((uint32)(((uint32)(a1) + (uint32)(24)))));
    w_u32((uint32)(((uint32)(a1) + (uint32)(208))), 0x800508D0u);
    result = 0x80050A2Cu;
    w_u32((uint32)(((uint32)(a1) + (uint32)(328))), 0x80050A2Cu);
  }
  return result;
}


sint32 sub_8004E9E4(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    FUNCTION_MARKER(0x8004e9e4u, "SLES_008.65");
  sint32 result;
  sint32 v9;
  sint32 v10;
  sint32 v11;
  uint32 v12;
  if ((((((sint16)r_u16(a1) >= 0) || ((sint16)r_u16(a2) >= 0)) || ((sint16)r_u16(a3) >= 0)) || (result = 1, ((sint16)r_u16(a4) >= 0))))
  {
    if ((((((sint16)r_u16((a1 + (1) * 2u)) >= 0) || ((sint16)r_u16((a2 + (1) * 2u)) >= 0)) || ((sint16)r_u16((a3 + (1) * 2u)) >= 0)) || (result = 2, ((sint16)r_u16((a4 + (1) * 2u)) >= 0))))
    {
      if ((((((sint32)r_u32(0x800881A0) >= (sint16)r_u16(a1)) || ((sint32)r_u32(0x800881A0) >= (sint16)r_u16(a2))) || ((sint32)r_u32(0x800881A0) >= (sint16)r_u16(a3))) || (result = 3, ((sint32)r_u32(0x800881A0) >= (sint16)r_u16(a4)))))
      {
        if ((((((sint32)r_u32(0x800896C0) >= (sint16)r_u16((a1 + (1) * 2u))) || ((sint32)r_u32(0x800896C0) >= (sint16)r_u16((a2 + (1) * 2u)))) || ((sint32)r_u32(0x800896C0) >= (sint16)r_u16((a3 + (1) * 2u)))) || (result = 4, ((sint32)r_u32(0x800896C0) >= (sint16)r_u16((a4 + (1) * 2u))))))
        {
          v9 = (sint32)r_u32(0x800774A8u);
          result = (sint32)((uint32)((sint32)r_u32(0x8007737Cu)) + (uint32)(120));
          w_u32(0x80077634u, (sint32)((uint32)((sint32)r_u32(0x8007737Cu)) + (uint32)(120)));
          v10 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8007737Cu)) + (uint32)(120))));
          if (((sint32)((uint32)((sint32)r_u32(0x800775BCu)) - (uint32)((sint32)r_u32(0x800774A8u))) >= 40))
          {
            w_u32(0x800774A8u, ((uint32)((sint32)r_u32(0x800774A8u)) + (uint32)(40)));
            v11 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8007737Cu)) + (uint32)(120))));
            w_u32(0x80077634u, v9);
            w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8007737Cu)) + (uint32)(120))), ((v11 & 0xFF000000) | (v9 & 0xFFFFFF)));
            ob_draft_unresolved_call(0x800C1030u, 3u, v9, (0u - (uint32)(2146941840)), 40);
            v12 = (uint32)((sint32)r_u32(0x80077634u));
            w_u16((uint32)((sint32)((uint32)(v9) + (uint32)(8))), (sint16)r_u16(a1));
            w_u16((uint32)((sint32)((uint32)(v9) + (uint32)(10))), (sint16)r_u16((a1 + (1) * 2u)));
            w_u16((uint32)((sint32)((uint32)(v9) + (uint32)(16))), (sint16)r_u16(a2));
            w_u16((uint32)((sint32)((uint32)(v9) + (uint32)(18))), (sint16)r_u16((a2 + (1) * 2u)));
            w_u16((uint32)((sint32)((uint32)(v9) + (uint32)(24))), (sint16)r_u16(a3));
            w_u16((uint32)((sint32)((uint32)(v9) + (uint32)(26))), (sint16)r_u16((a3 + (1) * 2u)));
            w_u16((uint32)((sint32)((uint32)(v9) + (uint32)(32))), (sint16)r_u16(a4));
            w_u16((uint32)((sint32)((uint32)(v9) + (uint32)(34))), (sint16)r_u16((a4 + (1) * 2u)));
            result = 0;
            w_u32(v12, ((r_u32(v12) & 0xFF000000) | (v10 & 0xFFFFFF)));
          }
        }
      }
    }
  }
  return result;
}


sint32 sub_80024640(void)
{
    FUNCTION_MARKER(0x80024640u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80055FD8 */
    /* TODO: Bind external adapter for sub_80055D74 */
    /* TODO: Bind external adapter for nullsub_20 */
    /* TODO: Bind external adapter for sub_80013820 */
    /* TODO: Resolve meaningful argument carriers for sub_8003077C without dropping supplied values */
  sint32 v0;
  uint32 v1;
  sint32 result;
  w_u32(0x80084590, 0);
  w_u32(0x8006C170u, 0);
  w_u32(0x800C9AB0, 0);
  w_u16(0x800C5588, 0);
  w_u32(0x80086A40, 0);
  w_u32(0x8006C154u, 0);
  w_u32(0x8007687Cu, 0);
  v0 = 0;
  if ((sint8)r_u8(0x8006C230u))
  {
    v1 = (sint32)r_u32(0x8006C138u);
    do
    {
      w_u32(v1, 0);
      ++v0;
      ((v1 += 4u));
    }
    while ((v0 < (uint8)((sint8)r_u8(0x8006C230u))));
  }
  w_u32(0x8006C134u, 0);
  ob_draft_unresolved_call(r_u32(0x8009450C), 3u, 0, 0, 0);
  sub_8002439C();
  ob_draft_unresolved_call(0x80055fd8u, 2u, 0, r_u32(0x80089900));
  ob_draft_unresolved_call(0x80055d74u, 0u);
  while ((ob_draft_unresolved_call(0x80055fd8u, 2u, 0, (0u - (uint32)(2146920192))) != 2))
    ;

  sub_8005577C(64);
  sub_80021EFC();
  if (((sint8)r_u8(0x8006C233u) == 1))
  {
    sub_800251E8((sint32)r_u32((0x8006c178u + ((uint8)((sint8)r_u8(0x8006C234u))) * 4u)));
    sub_800256CC((0x80076DACu));
    w_u32(0x8006C220u, 1);
  }
  sub_80021EFC();
  w_u32(0x80083E30, sub_800251E8((sint32)r_u32(((0x8006C18Cu) + ((uint8)((sint8)r_u8(0x8006C231u))) * 4u))));
  ob_draft_unresolved_call(0x80055d74u, 0u);
  sub_800256CC((sint32)r_u32(0x80066050u));
  sub_80022058();
  sub_8001F874();
  sub_800224A0();
  ob_draft_unresolved_call(0x80024310u, 0u);
  sub_80055808();
  sub_800174CC(71680);
  sub_8004A1C0();
  ob_draft_unresolved_call(r_u32(0x80097E04), 0u);
  ob_draft_unresolved_call(0x80013820u, 0u);
  ob_draft_unresolved_call(r_u32(0x800C1104), 0u);
  sub_80030700(0, 0, 0);
  ob_draft_unresolved_call(0x8003077cu, 4u, (0u - (uint32)(2146920084)), 255, 2, 0);
  ob_draft_unresolved_call(r_u32(0x80093C44), 1u, 0);
  result = ((uint8)((sint8)r_u8(0x8006C230u)) < 2u);
  if (((uint8)((sint8)r_u8(0x8006C230u)) < 2u))
  {
    result = (sint32)r_u32(0x80077190u);
    w_u32(0x8006C204u, 1);
    switch (r_u8((uint32)((sint32)((uint32)((sint32)r_u32(0x80077190u)) + (uint32)(41)))))
    {
      case 0:
        w_u32(0x8006C208u, 1);
        result = 50;
        goto LABEL_17;

      case 1:
        result = 100;
        goto LABEL_15;

      case 2:
        result = 150;
        goto LABEL_15;

      case 3:
        result = 250;
        LABEL_15:
      w_u32(0x8006C208u, 1);

        w_u16(0x8006C21Cu, result);
        w_u32(0x8006C218u, 1);
        return result;

      case 4:
        result = 50;
        w_u32(0x8006C208u, 0);
        LABEL_17:
      w_u16(0x8006C21Cu, 50);

        goto LABEL_18;

      default:
        return result;

    }

  }
  w_u32(0x8006C204u, 0);
  w_u32(0x8006C208u, 0);
  LABEL_18:
  w_u32(0x8006C218u, 0);

  return result;
}


sint32 sub_8002CA3C(void)
{
    FUNCTION_MARKER(0x8002ca3cu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8005BAE8 */
    /* TODO: Bind external adapter for sub_8005C954 */
    /* TODO: Bind external adapter for sub_8005C064 */
    /* TODO: Bind external adapter for sub_8005ABC0 */
    /* TODO: Bind external adapter for sub_8005AC90 */
    /* TODO: Bind external adapter for sub_8005AD0C */
    /* TODO: Bind external adapter for sub_8005ADB0 */
    /* TODO: Bind external adapter for sub_8005ACCC */
    /* TODO: Bind external adapter for sub_8005C504 */
    /* TODO: Bind external adapter for sub_80059CA8 */
    /* TODO: Bind external adapter for sub_8005B994 */
    /* TODO: Bind external adapter for sub_8005CB78 */
    /* TODO: Bind external adapter for sub_8005CB04 */
    /* TODO: Bind external adapter for sub_8005C468 */
    /* TODO: Bind external adapter for sub_8005CD50 */
    uint32 local_objects = ob_draft_scratch_acquire(24u);
  uint32 v0;
  uint32 v1;
  sint32 v2;
  sint32 result;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  w_u32(0x80077504u, 0x8002CF44u);
  v0 = (uint32)((sint32)r_u32(0x800773ACu));
  v1 = (uint32)((sint32)r_u32(0x8007741Cu));
  w_u32((uint32)((sint32)r_u32(0x800773ACu)), 384);
  w_u32((v0 + (1) * 4u), 256);
  w_u32((v0 + (2) * 4u), 384);
  w_u32((v0 + (3) * 4u), 256);
  w_u32((v1 + (1) * 4u), v0);
  w_u32(v1, 0);
  w_u32((v1 + (2) * 4u), 0);
  w_u32((v1 + (3) * 4u), 0);
  w_u32((v1 + (4) * 4u), 3);
  w_u32((v1 + (5) * 4u), 0);
  ob_draft_unresolved_call(0x8005bae8u, 1u, (local_objects + 0u));
  w_u8(((local_objects + 0u) + (4) * 1u), 0);
  w_u8(((local_objects + 0u) + (5) * 1u), 0);
  w_u8(((local_objects + 0u) + (6) * 1u), 0);
  w_u16(local_objects + 8u, 0);
  w_u16(local_objects + 10u, 0);
  w_u16(local_objects + 12u, 384);
  w_u16(local_objects + 14u, 0);
  w_u16(local_objects + 16u, 0);
  w_u16(local_objects + 18u, 256);
  w_u16(local_objects + 20u, 384);
  w_u16(local_objects + 22u, 256);
  w_u32(0x8007737Cu, (0u - (uint32)(2146932008)));
  ob_draft_unresolved_call(0x8005c954u, 2u, (0u - (uint32)(2146931896)), 8);
  w_u32(0x8007737Cu, (0u - (uint32)(2146932152)));
  ob_draft_unresolved_call(0x8005c954u, 2u, (0u - (uint32)(2146932040)), 8);
  ob_draft_unresolved_call(0x8005c064u, 1u, 0);
  ob_draft_unresolved_call(0x8005abc0u, 5u, (0u - (uint32)(2146932152)), 0, 0, 384, 256);
  ob_draft_unresolved_call(0x8005ac90u, 5u, (0u - (uint32)(2146932060)), 0, 256, 384, 256);
  ob_draft_unresolved_call(0x8005abc0u, 5u, (0u - (uint32)(2146932008)), 0, 256, 384, 256);
  ob_draft_unresolved_call(0x8005ac90u, 5u, (0u - (uint32)(2146931916)), 0, 0, 384, 256);
  w_u32(0x800775DCu, 384);
  w_u32(0x800775E0u, 0);
  w_u32(0x80077370u, 384);
  w_u32(0x80077378u, 0);
  ob_draft_unresolved_call(0x8005ad0cu, 2u, 960, 256);
  v2 = ob_draft_unresolved_call(0x8005adb0u, 6u, 26, 32, 256, 200, 0, 512);
  ob_draft_unresolved_call(0x8005acccu, 1u, v2);
  w_u16(0x80086AACu, 0);
  w_u16(0x80086AAEu, 20);
  w_u16(0x80086AB0u, 256);
  w_u16(0x80086AB2u, 256);
  w_u16(0x80086B3Cu, 0);
  w_u16(0x80086B3Eu, 20);
  w_u16(0x80086B40u, 256);
  w_u16(0x80086B42u, 256);
  ob_draft_unresolved_call(0x8005c504u, 1u, 0);
  ob_draft_unresolved_call(0x80059ca8u, 1u, 0);
  ob_draft_unresolved_call(0x8005b994u, 2u, (sint32)((uint32)((sint32)r_u32(0x8007737Cu)) + (uint32)(112)), (local_objects + 0u));
  ob_draft_unresolved_call(0x8005cb78u, 1u, (0u - (uint32)(2146932152)));
  ob_draft_unresolved_call(0x8005cb04u, 1u, (sint32)((uint32)((sint32)r_u32(0x8007737Cu)) + (uint32)(112)));
  ob_draft_unresolved_call(0x8005c504u, 1u, 0);
  ob_draft_unresolved_call(0x8005cb78u, 1u, (0u - (uint32)(2146932008)));
  ob_draft_unresolved_call(0x8005cb04u, 1u, (sint32)((uint32)((sint32)r_u32(0x8007737Cu)) + (uint32)(112)));
  ob_draft_unresolved_call(0x8005c504u, 1u, 0);
  w_u32(0x8007737Cu, (0u - (uint32)(2146932008)));
  ob_draft_unresolved_call(0x8005c954u, 2u, (0u - (uint32)(2146931896)), 8);
  w_u32(0x8007737Cu, (0u - (uint32)(2146932152)));
  ob_draft_unresolved_call(0x8005c954u, 2u, (0u - (uint32)(2146932040)), 8);
  ob_draft_unresolved_call(0x8005c468u, 1u, 1);
  ob_draft_unresolved_call(0x8005cd50u, 1u, (0u - (uint32)(2146932060)));
  ob_draft_unresolved_call(0x8005cb78u, 1u, (0u - (uint32)(2146932152)));
  result = (0u - (uint32)(1));
  w_u32(0x800773D0u, 0);
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


sint32 sub_80043120(uint32 a1)
{
    FUNCTION_MARKER(0x80043120u, "SLES_008.65");
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Bind external adapter for sub_800257A0 */
    /* TODO: Recover undefined register temporaries without extending the function ABI */
    uint32 local_objects = ob_draft_scratch_acquire(6u);
    uint32 reg_S0;
    uint32 reg_T0;
    uint32 reg_T1;
    uint32 reg_T2;
    uint32 reg_T3;
    uint32 reg_T4;
    uint32 reg_T5;
  sint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 v5;
  sint32 v7;
  sint32 v8;
  uint32 v20;
  sint32 v21;
  sint32 v22;
  sint32 v23;
  ;
  ;
  ;
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
  sint16 v38;
  sint16 v39;
  v2 = ((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))))) + (uint32)(24))))) - (uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800775D0u)) + (uint32)(24))))));
  w_u32(0x1F800008, v2);
  v3 = ((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))))) + (uint32)(28))))) - (uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800775D0u)) + (uint32)(28))))));
  w_u32(0x1F80000C, v3);
  v4 = ((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))))) + (uint32)(32))))) - (uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800775D0u)) + (uint32)(32))))));
  v5 = v2;
  if ((v2 < 0))
    v5 = (0u - (uint32)(v2));
  w_u32(0x1F800010, ((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))))) + (uint32)(32))))) - (uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800775D0u)) + (uint32)(32)))))));
  reg_S0 = 528482304;
  if ((v5 >= 16000))
    goto LABEL_11;
  v7 = v3;
  if ((v3 < 0))
    v7 = (0u - (uint32)(v3));
  if ((v7 >= 16000))
    goto LABEL_11;
  v8 = v4;
  if ((v4 < 0))
    v8 = (0u - (uint32)(v4));
  if ((v8 >= 16000))
  {
    LABEL_11:
    w_u32(0x1F800000, ((sint32)(r_u32(0x1F800008)) >> 4));

    w_u16(0x1F800004, ((sint32)(r_u32(0x1F800010)) >> 4));
    w_u16(0x1F800002, ((sint32)(r_u32(0x1F80000C)) >> 4));
    reg_T0 = r_u32(0x8008C8A8);
    reg_T1 = r_u32(0x8008C8AC);
    reg_T2 = r_u32(0x8008C8B0);
    reg_T3 = r_u32(0x8008C8B4);
    reg_T4 = r_u32(0x8008C8B8);
    ob_draft_unresolved_call(0x80043120u, 0u);
    w_u32(0x1F800018, (sint32)((uint32)(16) * (uint32)(r_u32(0x1F800008))));
    w_u32(0x1F800020, (sint32)((uint32)(16) * (uint32)(r_u32(0x1F800010))));
    w_u32(0x1F80001C, (sint32)((uint32)(16) * (uint32)(r_u32(0x1F80000C))));
  }
  else
  {
    reg_T5 = 528482304;
    w_u32(0x1F800000, v2);
    w_u16(0x1F800002, v3);
    w_u16(0x1F800004, v4);
    reg_T0 = r_u32(0x8008C8A8);
    reg_T1 = r_u32(0x8008C8AC);
    reg_T2 = r_u32(0x8008C8B0);
    reg_T3 = r_u32(0x8008C8B4);
    reg_T4 = r_u32(0x8008C8B8);
    ob_draft_unresolved_call(0x80043120u, 0u);
    w_u32(0x1F800018, r_u32(0x1F800008));
    w_u32(0x1F80001C, r_u32(0x1F80000C));
    w_u32(0x1F800020, r_u32(0x1F800010));
  }
  v20 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(4))));
  if (((r_u32(v20) & 3) != 0))
  {
    v21 = sub_800257CC((sint32)(v20));
  }
  else
  {
    (w_u16((uint32)(((uint32)(r_u32(v20)) - (uint32)(6))), (r_u16((uint32)(((uint32)(r_u32(v20)) - (uint32)(6)))) + 1u)), r_u16((uint32)(((uint32)(r_u32(v20)) - (uint32)(6)))));
    v21 = r_u32(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(4)))));
  }
  w_u8(((local_objects + 0u) + (0) * 1u), 2);
  w_u8(((local_objects + 0u) + (1) * 1u), 0);
  w_u16(local_objects + 2u, r_u16((uint32)(a1)));
  w_u16(local_objects + 4u, (sint32)r_u32(0x80077350u));
  v28 = r_u32(0x1F800018);
  v29 = r_u32(0x1F80001C);
  v30 = r_u32(0x1F800020);
  v31 = v21;
  v22 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))));
  v36 = 0;
  v37 = 0;
  v32 = v22;
  v33 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12))));
  v34 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(16))));
  v23 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(20))));
  v38 = 0;
  v39 = 0;
  v35 = v23;
  sub_8003858C((sint32)((local_objects + 0u)));
  { uint32 draft_return = ob_draft_unresolved_call(0x800257a0u, 1u, r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(4))))); ob_draft_scratch_release(local_objects);  return draft_return; }
}


sint32 sub_80047B54(uint32 a1, sint32 a2, sint32 a3)
{
    FUNCTION_MARKER(0x80047b54u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80047A60 */
    /* TODO: Bind external adapter for sub_800479E0 */
  sint32 v5;
  sint32 v6;
  sint32 v7;
  uint32 v8;
  sint32 v9;
  uint32 v10;
  sint32 v11;
  uint32 v12;
  sint32 v13;
  sint32 v14;
  sint32 v15;
  sint32 v16;
  sint32 v17;
  uint32 v18;
  sint32 v19;
  sint32 v20;
  sint32 v21;
  sint32 v22;
  sint32 result;
  sint32 v24;
  if ((a3 == r_u32((a1 + (49) * 4u))))
  {
    v5 = (sint32)((uint32)(a3) + (uint32)(25));
    v6 = (0u - (uint32)(1));
    if ((r_u32((a1 + (47) * 4u)) < (sint32)((uint32)(a3) + (uint32)(25))))
      v5 = r_u32((a1 + (47) * 4u));
    v7 = 0x7FFFFFFF;
    v8 = (uint32)((sint32)r_u32(0x80077140u));
    v9 = r_u32((a1 + (6) * 4u));
    v10 = r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(v9))) + (uint32)((sint32)r_u32(0x80077148u)))));
    v11 = 0;
    if ((v9 > 0))
    {
      v12 = (v10 + (1) * 4u);
      do
      {
        v13 = (sint32)r_u32(v8);
        if (((sint32)r_u32(v8) && (((sint32)r_u32(v10) & 0x8000) == 0)))
        {
          if ((v5 < (sint32)r_u32(v12)))
          {
            if (((sint32)r_u32(v12) < v7))
            {
              v6 = v11;
              v7 = (sint32)r_u32(v12);
            }
          }
          else
          {
            v24 = v5;
            sub_800477B8((sint32)(a1), (sint32)r_u32(v8), a3, v10);
            v14 = (sint32)r_u32(v12);
            v5 = v24;
            if ((((sint32)r_u32(v10) & 0x8000) != 0))
            {
              (w_u32((a1 + (45) * 4u), (r_u32((a1 + (45) * 4u)) + 1u)), r_u32((a1 + (45) * 4u)));
              (w_u32((uint32)((sint32)((uint32)(v13) + (uint32)(184))), (r_u32((uint32)((sint32)((uint32)(v13) + (uint32)(184)))) + 1u)), r_u32((uint32)((sint32)((uint32)(v13) + (uint32)(184)))));
              v15 = r_u32((a1 + (47) * 4u));
              if (((v14 < v15) || ((v14 == v15) && (r_u32((uint32)((sint32)((uint32)(v13) + (uint32)(24)))) < r_u32((a1 + (48) * 4u))))))
              {
                w_u32((a1 + (47) * 4u), v14);
                w_u32((a1 + (48) * 4u), v11);
              }
            }
            else
              if (((sint32)r_u32(v12) < v7))
            {
              v6 = v11;
              v7 = a3;
            }
          }
        }
        v12 += (2) * 4u;
        v10 += (2) * 4u;
        ++v11;
        ((v8 += 4u));
      }
      while ((v11 < (sint32)r_u32((a1 + (6) * 4u))));
    }
    w_u32((a1 + (50) * 4u), v6);
    w_u32((a1 + (49) * 4u), v7);
  }
  if ((a3 != r_u32((a1 + (47) * 4u))))
    return ob_draft_unresolved_call(0x80047a60u, 1u, a1);
  v16 = r_u32((a1 + (48) * 4u));
  v17 = r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(v16))) + (uint32)((sint32)r_u32(0x80077140u)))));
  v18 = (uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(r_u32((a1 + (6) * 4u))))) + (uint32)((sint32)r_u32(0x80077148u)))))) + (uint32)((sint32)((uint32)(8) * (uint32)(v16)))));
  v19 = sub_800491B0(a1, v17, a3, v18);
  v20 = (sint32)r_u32(v18);
  v21 = v19;
  w_u32((v18 + (1) * 4u), 2147483393);
  w_u32(v18, ((v20 & 0xBFFF7FFF) | 0x40000000));
  v22 = r_u32((a1 + (45) * 4u));
  w_u32((a1 + (48) * 4u), (0u - (uint32)(1)));
  w_u32((a1 + (47) * 4u), 0x7FFFFFFF);
  w_u32((a1 + (45) * 4u), (sint32)((uint32)(v22) - (uint32)(1)));
  (w_u32((uint32)((sint32)((uint32)(v17) + (uint32)(184))), (r_u32((uint32)((sint32)((uint32)(v17) + (uint32)(184)))) - 1u)), r_u32((uint32)((sint32)((uint32)(v17) + (uint32)(184)))));
  ob_draft_unresolved_call(0x800479e0u, 1u, a1);
  if (v21)
    sub_80047E2C(a1, v17, a3, v21);
  result = ((sint32)r_u32(v18) & 0x40000000);
  if (result)
  {
    sub_800477B8((sint32)(a1), v17, a3, v18);
    return sub_80047450(a1, v17, v18, 128);
  }
  return result;
}


sint32 sub_80023E70(void)
{
    FUNCTION_MARKER(0x80023e70u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80054320 */
    /* TODO: Bind external adapter for sub_8001FAC8 */
    /* TODO: Bind external adapter for sub_800159C8 */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Bind external adapter for sub_80013A6C */
    /* TODO: Bind external adapter for sub_8005B994 */
    /* TODO: Bind external adapter for sub_80013818 */
    /* TODO: Bind external adapter for sub_8005C504 */
    /* TODO: Bind external adapter for sub_8002CFA8 */
    /* TODO: Bind external adapter for sub_80018DB0 */
    /* TODO: Bind external adapter for sub_80017C10 */
  sint32 v0;
  sint32 v1;
  sint32 v2;
  sint32 result;
  sint32 v4;
  ob_draft_unresolved_call(r_u32(0x800A9C30), 1u, r_u32(0x800882BC));
  ob_draft_unresolved_call(r_u32(0x80092C6C), 1u, r_u32(0x800882BC));
  ob_draft_unresolved_call(r_u32(0x800A1964), 1u, r_u32(0x800882BC));
  ob_draft_unresolved_call(r_u32(0x800A5528), 1u, r_u32(0x800882BC));
  ob_draft_unresolved_call(0x80054320u, 0u);
  v0 = sub_8001994C();
  ob_draft_unresolved_call(r_u32(0x800944C4), 1u, r_u32(0x800882BC));
  sub_8001FC60();
  if ((r_u32(0x8007FAD0) != r_u32(0x8008CEBC)))
  {
    ob_draft_unresolved_call(0x8001fac8u, 0u);
    sub_8001F9B0(r_u32(0x8007FAD0), 1);
    sub_8001DF58((sint8)r_u8(0x8006C22Eu));
    w_u32(0x800843D0, r_u32(0x8008CEBC));
    w_u32(0x8008CEBC, r_u32(0x8007FAD0));
  }
  (w_u32(0x80086A40, (r_u32(0x80086A40) + 1u)), r_u32(0x80086A40));
  if (!(sint8)r_u8(0x8006C233u))
    sub_8001627C(r_u32(0x800882BC));
  sub_8002D25C((0u - (uint32)(2146906416)), (0u - (uint32)(2146931856)));
  ob_draft_unresolved_call(r_u32(0x800BA1C8), 0u);
  ob_draft_unresolved_call(0x800159c8u, 0u);
  if (!v0)
    v0 = sub_8001A6FC();
  sub_800231E4();
  sub_80013FA4(r_u32(0x800882BC));
  if ((((sint8)r_u8(0x8006C233u) == 1) && ((r_u32(0x800882BC) % 1000) < 500)))
    ob_draft_unresolved_call(0x80013a6cu, 2u, r_u32(0x80010934u), 156);
  ob_draft_unresolved_call(r_u32(0x800C136C), 0u);
  if ((sint32)r_u32((0x8006c138u + (0) * 4u)))
  {
    v1 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32((0x8006c138u + (0) * 4u))) + (uint32)(124))));
    w_u32(0x800774F4u, (0u - (uint32)(2146677552)));
    w_u32(0x80077428u, (sint32)((uint32)(v1) + (uint32)(4)));
  }
  else
  {
    w_u32(0x800774F4u, 0);
    w_u32(0x80077428u, 0);
  }
  sub_8004C944(r_u32(0x800882BC));
  if ((sint32)r_u32(0x800773D0u))
    v2 = (0u - (uint32)(2146908472));
  else
    v2 = (0u - (uint32)(2146906256));
  ob_draft_unresolved_call(0x8005b994u, 2u, (sint32)((uint32)((sint32)r_u32(0x8007737Cu)) + (uint32)(112)), v2);
  if (((!(sint8)r_u8(0x8006C233u) && (r_u32((uint32)((sint32)((uint32)((sint32)r_u32((0x8006c138u + (0) * 4u))) + (uint32)(288)))) != 23)) && !v0))
    v0 = ob_draft_unresolved_call(0x80013818u, 0u);
  sub_80034234();
  sub_80012184();
  while ((sint32)r_u32(0x80077620u))
    ;

  ob_draft_unresolved_call(0x8005c504u, 1u, 0);
  w_u32(0x8007754Cu, (sint32)r_u32(0x8007737Cu));
  ob_draft_unresolved_call(0x8002cfa8u, 0u);
  w_u32(0x80077620u, 1);
  if (((!(sint8)r_u8(0x8006C233u) && (r_u32((uint32)((sint32)((uint32)((sint32)r_u32((0x8006c138u + (0) * 4u))) + (uint32)(288)))) != 23)) && !v0))
    v0 = sub_80018454();
  if (((sint32)r_u32(0x8006C154u) == 1))
  {
    v0 = 9;
    if (((sint8)r_u8(0x8006C231u) != 19))
      v0 = ob_draft_unresolved_call(0x80018db0u, 0u);
  }
  result = v0;
  if (r_u32(0x80089B78))
  {
    v4 = 8;
    if (((uint8)((sint8)r_u8(0x8006C230u)) >= 2u))
      return ob_draft_unresolved_call(0x80017c10u, 0u);
    return v4;
  }
  return result;
}


sint32 sub_80034E10(uint32 a1)
{
    FUNCTION_MARKER(0x80034e10u, "SLES_008.65");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Bind external adapter for sub_8005C504 */
    /* TODO: Bind external adapter for sub_8005C7C8 */
    /* TODO: Bind external adapter for sub_8005B834 */
    uint32 local_objects = ob_draft_scratch_acquire(8u);
  sint32 v2;
  uint16 v3;
  uint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  uint32 v10;
  sint32 v11;
  sint32 v12;
  uint32 v13;
  uint32 v14;
  uint32 v15;
  uint32 v16;
  sint32 v17;
  sint16 v18;
  uint32 v19;
  sint32 v20;
  sint32 v21;
  sint32 v22;
  uint16 v23;
  uint16 v24;
  sint32 result;
  ;
  ;
  v2 = (sint32)r_u32(a1);
  if ((sint32)r_u32(0x8007742Cu))
    v3 = r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800773A8u)) + (uint32)(12))));
  else
    v3 = (r_u16((uint32)((sint32)((uint32)(v2) + (uint32)(2)))) & 0x7FFF);
  v4 = (uint32)((sint32)((uint32)((sint32)r_u32(a1)) + (uint32)(4)));
  v5 = 1;
  v6 = 0;
  if ((sint32)r_u32(0x80077578u))
  {
    v7 = (sint32)r_u32(0x80077578u);
  }
  else
    if ((sint32)r_u32(0x8007742Cu))
  {
    v5 = ((r_u16((uint32)((sint32)((uint32)(v2) + (uint32)(2)))) & 0x7FFF) / v3);
    v6 = ((sint32)((uint32)(256) - (uint32)(v3)) & 3);
    v8 = ((uint32)(v3) + (uint32)(v6));
    sub_80026694((sint32)((uint32)((sint32)r_u32(0x8007742Cu)) + (uint32)(20)), (sint32)((uint32)((sint32)((uint32)(2) * (uint32)(v8))) * (uint32)(v5)), 0);
    v9 = (sint32)r_u32(0x8007742Cu);
    v7 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8007742Cu)) + (uint32)(20))));
    w_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x8007742Cu)) + (uint32)(12))), (v8 >> 1));
    w_u8((uint32)((sint32)((uint32)(v9) + (uint32)(11))), v5);
  }
  else
  {
    v7 = (0u - (uint32)(2146907960));
  }
  v10 = (uint32)(v7);
  v11 = 0;
  if (v5)
  {
    do
    {
      v12 = 0;
      if (v3)
      {
        do
        {
          v13 = r_u8(v4);
          v14 = (v4 + (1) * 1u);
          v15 = r_u8(((v14 += 1u) - 1u));
          v16 = r_u8(v14);
          v4 = (v14 + (1) * 1u);
          v17 = ((uint32)(((uint32)(((uint32)((v16 >> 1)) << (uint32)(10))) + (uint32)((v13 >> 1)))) + (uint32)((sint32)((uint32)(32) * (uint32)((v15 >> 1)))));
          if (v12)
          {
            v18 = (v17 | 0x8000);
          }
          else
          {
            v18 = (v17 | 0x8000);
            if (((r_u16((uint32)((sint32)((uint32)(v2) + (uint32)(2)))) & 0x8000) != 0))
              v18 = 0;
          }
          w_u16(v10, v18);
          ++v12;
          ((v10 += 2u));
        }
        while ((v12 < v3));
      }
      ++v11;
      v10 += (v6) * 2u;
    }
    while ((v11 < v5));
  }
  if (((sint32)((uint32)((sint32)r_u32(0x800774B4u)) + (uint32)(v3)) >= (sint32)((uint32)((sint32)r_u32(0x800775DCu)) + (uint32)(512))))
  {
    w_u32(0x800774B4u, (sint32)r_u32(0x80077370u));
    (w_u32(0x800774B8u, ((sint32)r_u32(0x800774B8u) + 1u)), (sint32)r_u32(0x800774B8u));
  }
  w_u32(local_objects + 4u, ((uint32)((sint32)r_u32(local_objects + 4u)) & ~(65535u << 0) | (((uint32)(v3) & 65535u) << 0)));
  w_u32(local_objects + 4u, ((uint32)((sint32)r_u32(local_objects + 4u)) & ~(65535u << 16) | (((uint32)(1) & 65535u) << 16)));
  w_u32(local_objects + 0u, ((uint32)((sint32)r_u32(local_objects + 0u)) & ~(65535u << 0) | (((uint32)((sint32)r_u32(0x800774B4u)) & 65535u) << 0)));
  w_u32(local_objects + 0u, ((uint32)((sint32)r_u32(local_objects + 0u)) & ~(65535u << 16) | (((uint32)((sint32)r_u32(0x800774B8u)) & 65535u) << 16)));
  if ((sint32)r_u32(0x80077578u))
  {
    v19 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80077564u)) + (uint32)(8))));
    v20 = (sint32)r_u32(local_objects + 4u);
    w_u32(v19, (sint32)r_u32(local_objects + 0u));
    w_u32((v19 + (1) * 4u), v20);
  }
  else
  {
    v21 = (sint32)r_u32(0x8007742Cu);
    if ((sint32)r_u32(0x8007742Cu))
    {
      v22 = (sint32)r_u32(local_objects + 4u);
      w_u32((uint32)((sint32)r_u32(0x8007742Cu)), (sint32)r_u32(local_objects + 0u));
      w_u32((uint32)((sint32)((uint32)(v21) + (uint32)(4))), v22);
    }
  }
  ob_draft_unresolved_call(0x8005c504u, 1u, 0);
  ob_draft_unresolved_call(0x8005c7c8u, 2u, (local_objects + 0u), v7);
  ob_draft_unresolved_call(0x8005c504u, 1u, 0);
  v23 = ob_draft_unresolved_call(0x8005b834u, 2u, (sint32)r_u32(0x800774B4u), (sint32)r_u32(0x800774B8u));
  w_u32(0x800774B4u, ((uint32)((sint32)r_u32(0x800774B4u)) + (uint32)(v3)));
  v24 = v23;
  if ((((sint32)r_u32(0x800774B4u) & 0xF) != 0))
    w_u32(0x800774B4u, (sint32)((uint32)((sint32)((uint32)((sint32)r_u32(0x800774B4u)) + (uint32)(16))) - (uint32)(((sint32)r_u32(0x800774B4u) & 0xF))));
  if (((sint32)((uint32)((sint32)r_u32(0x800775DCu)) + (uint32)(512)) < (sint32)r_u32(0x800774B4u)))
  {
    w_u32(0x800774B4u, (sint32)r_u32(0x80077370u));
    (w_u32(0x800774B8u, ((sint32)r_u32(0x800774B8u) + 1u)), (sint32)r_u32(0x800774B8u));
  }
  (w_u32(0x800773F4u, ((sint32)r_u32(0x800773F4u) + 1u)), (sint32)r_u32(0x800773F4u));
  sub_80026758(a1);
  result = (sint32)((uint32)((sint32)((uint32)(4) * (uint32)(v24))) + (uint32)(2));
  w_u32(a1, result);
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


sint32 sub_8001EBBC(sint32 a1, uint32 a2, sint32 a3, sint32 a4, sint32 a5, sint32 a6)
{
    FUNCTION_MARKER(0x8001EBBCu, "SLES_008.65");
    uint32 enabled = r_u8(0x8006C00Cu);
    if (enabled == 0u) return enabled;
    enabled = r_u8(0x8006C011u);
    if (enabled == 0u) return enabled;
    sint32 slot = (sint32)sub_80020288();
    if (slot == -1) return (uint32)-1;
    uint32 resource = 0x800778A0u + 20u * (uint32)a1;
    uint32 sound = 0x80078540u + 28u * (uint32)slot;
    uint32 frequency = r_u32(resource + 16u);
    uint32 volume_product = (a2 & 255u) * r_u8(0x8006C010u);
    w_u32(sound + 4u, 3u);
    w_u8(sound + 23u, a3);
    w_u8(sound + 24u, a4);
    w_u32(sound + 8u, a6);
    w_u32(sound, frequency);
    w_u32(sound + 12u, a5);
    /* Original signed multiply-high correction computes unsigned byte volume / 255 */
    w_u8(sound + 22u, volume_product / 255u);
    sint32 voice = (sint32)sub_800202E8();
    if (voice == -1) return -1;
    uint32 voice_state = 0x800782A0u + 28u * (uint32)voice;
    sint32 product = (sint32)((uint32)a5 * frequency);
    uint32 rounded = (uint32)product + (product < 0 ? 255u : 0u);
    sint32 pitch = (sint32)(rounded << 8) >> 16;
    w_u8(sound + 20u, voice);
    w_u32(voice_state, 1u);
    w_u32(voice_state + 4u, 1u);
    w_u32(voice_state + 16u, pitch);
    w_u32(voice_state + 20u, slot);
    uint32 attribute = ob_draft_scratch_acquire((uint32)sizeof(SpuVoiceAttr));
    /* Mask selects only the original pitch and sample address fields */
    w_u32(attribute, 1u << ((uint32)voice & 31u));
    w_u32(attribute + 4u, 144u);
    w_u32(attribute + 28u, r_u32(resource));
    w_u16(attribute + 20u, pitch);
    ob_draft_unresolved_call(0x80062EE8u, 1u, attribute);
    uint32 mode = r_u8(0x80078BECu);
    uint32 secondary_address = r_u32(resource + 8u);
    if (mode == 3u && secondary_address != 0u)
    {
        sint32 second = (sint32)sub_800202E8();
        if (second != -1)
        {
            uint32 second_state = 0x800782A0u + 28u * (uint32)second;
            w_u8(sound + 21u, second);
            w_u32(second_state, 1u);
            w_u32(second_state + 4u, 1u);
            w_u32(second_state + 16u, pitch);
            w_u32(second_state + 20u, slot);
            w_u32(attribute, 1u << ((uint32)second & 31u));
            w_u32(attribute + 4u, 144u);
            w_u32(attribute + 28u, secondary_address);
            w_u16(attribute + 20u, pitch);
            ob_draft_unresolved_call(0x80062EE8u, 1u, attribute);
        }
    }
    else if (mode == 4u && (a6 & 4u) != 0u)
    {
        w_u32(voice_state + 4u, 2u);
        sint32 second = (sint32)sub_800202E8();
        if (second != -1)
        {
            uint32 second_state = 0x800782A0u + 28u * (uint32)second;
            w_u8(sound + 21u, second);
            w_u32(second_state, 1u);
            w_u32(second_state + 4u, 1u);
            w_u32(second_state + 16u, pitch);
            w_u32(second_state + 20u, slot);
            w_u32(attribute, 1u << ((uint32)second & 31u));
            w_u32(attribute + 4u, 144u);
            w_u32(attribute + 28u, r_u32(resource));
            w_u16(attribute + 20u, pitch);
            ob_draft_unresolved_call(0x80062EE8u, 1u, attribute);
        }
    }
    else
        w_u8(sound + 21u, 255u);
    ob_draft_scratch_release(attribute);
    ob_draft_unresolved_call(0x8001FDA4u, 1u, (uint32)slot);
    return slot;
}



sint32 sub_800226D0(void)
{
    FUNCTION_MARKER(0x800226d0u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8005B994 */
    /* TODO: Bind external adapter for sub_8005C504 */
    /* TODO: Bind external adapter for sub_8002CFA8 */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    uint32 local_objects = ob_draft_scratch_acquire(6u);
  sint32 v0;
  sint32 v1;
  sint32 v2;
  sint32 v3;
  ;
  ;
  w_u32(local_objects + 0u, (sint32)r_u32(0x8001086Cu));
  w_u16(local_objects + 4u, (sint16)r_u16(0x80010870u));
  sub_80030700(0, 0, 0);
  sub_8003077C(local_objects, 255u, 2u, 255u, 255u, 255u);
  sub_8002D25C((0u - (uint32)(2146906416)), (0u - (uint32)(2146931856)));
  if ((sint32)r_u32(0x800773D0u))
    v0 = (0u - (uint32)(2146906256));
  else
    v0 = (0u - (uint32)(2146908472));
  ob_draft_unresolved_call(0x8005b994u, 2u, (sint32)((uint32)((sint32)r_u32(0x8007737Cu)) + (uint32)(112)), v0);
  while (r_u32(0x80077620u))
    ob_native_pump();

  ob_draft_unresolved_call(0x8005c504u, 1u, 0);
  w_u32(0x8007754Cu, (sint32)r_u32(0x8007737Cu));
  ob_draft_unresolved_call(0x8002cfa8u, 0u);
  sub_8002D25C((0u - (uint32)(2146906416)), (0u - (uint32)(2146931856)));
  if ((sint32)r_u32(0x800773D0u))
    v1 = (0u - (uint32)(2146906256));
  else
    v1 = (0u - (uint32)(2146908472));
  ob_draft_unresolved_call(0x8005b994u, 2u, (sint32)((uint32)((sint32)r_u32(0x8007737Cu)) + (uint32)(112)), v1);
  v2 = sub_80022C1C(0x80010874u);
  sub_80022AD4(0x80010874u, 192u - (uint32)(v2 / 2), 166u, 128u, 128u, 128u, 0u);
  while (r_u32(0x80077620u))
    ob_native_pump();

  ob_draft_unresolved_call(0x8005c504u, 1u, 0);
  w_u32(0x8007754Cu, (sint32)r_u32(0x8007737Cu));
  ob_draft_unresolved_call(0x8002cfa8u, 0u);
  w_u32(0x80077620u, 1);
  sub_8002D25C((0u - (uint32)(2146906416)), (0u - (uint32)(2146931856)));
  sub_80022AD4(0x80010874u, 234u, 196u, 128u, 128u, 128u, 0u);
  sub_80021460((0x80067878u), 0, 0, 32, 64u, 0u, 0u, 0u);
  sub_80021460((0x8006787Cu), 0, 0, 16, 32u, 135u, 193u, 0u);
  sub_80021460((0x80067880u), 0, 0, 16, 16u, 150u, 192u, 0u);
  sub_80021460((0x80067884u), 0, 0, 16, 16u, 166u, 192u, 0u);
  sub_80021460((0x80067888u), 0, 0, 16, 16u, 182u, 192u, 0u);
  sub_80021460((0x8006788Cu), 0, 0, 16, 16u, 198u, 192u, 0u);
  sub_80021460((0x80067890u), 0, 0, 16, 16u, 214u, 192u, 0u);
  if ((sint32)r_u32(0x800773D0u))
    v3 = (0u - (uint32)(2146906256));
  else
    v3 = (0u - (uint32)(2146908472));
  ob_draft_unresolved_call(0x8005b994u, 2u, (sint32)((uint32)((sint32)r_u32(0x8007737Cu)) + (uint32)(112)), v3);
  while (r_u32(0x80077620u))
    ob_native_pump();

  ob_draft_unresolved_call(0x8005c504u, 1u, 0);
  w_u32(0x8007754Cu, (sint32)r_u32(0x8007737Cu));
  ob_draft_unresolved_call(0x8002cfa8u, 0u);
  w_u32(0x80077620u, 1);
  while (r_u32(0x80077620u))
    ob_native_pump();

  { uint32 draft_return = ob_draft_unresolved_call(0x8005c504u, 1u, 0); ob_draft_scratch_release(local_objects);  return draft_return; }
}


sint32 sub_8004DB40(uint32 a1, sint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x8004db40u, "SLES_008.65");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Bind external adapter for sub_8002C4AC */
    uint32 local_objects = ob_draft_scratch_acquire(32u);
  sint32 v5;
  uint16 v6;
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
  sint32 result;
  sint32 v19;
  sint32 v20;
  sint32 v21;
  sint16 v22;
  sint16 v23;
  sint32 v24;
  sint32 v25;
  sint32 v26;
  sint32 v27;
  sint32 i;
  sint32 v29;
  ;
  ;
  ;
  ;
  w_u32(a3, 0);
  w_u32(((local_objects + 16u) + (0) * 4u), ((uint32)(r_u32(a1)) - (uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800775D0u)) + (uint32)(24)))))));
  w_u32(((local_objects + 16u) + (1) * 4u), ((uint32)(r_u32((a1 + (1) * 4u))) - (uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800775D0u)) + (uint32)(28)))))));
  v5 = ((uint32)(r_u32((a1 + (2) * 4u))) - (uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800775D0u)) + (uint32)(32))))));
  (w_u32(0x80084A40, (r_u32(0x80084A40) + 1u)), r_u32(0x80084A40));
  w_u32(((local_objects + 16u) + (2) * 4u), v5);
  sub_8002FED4((local_objects + 16u), (uint32)(0x800898B0), (local_objects + 0u));
  if ((a2 == 2))
  {
    v6 = 353;
  }
  else
  {
    v6 = 4626;
    if ((a2 == 1))
      v6 = 1173;
  }
  if (((sint32)r_u32(local_objects + 0u) <= 0))
    v7 = ((0u - (uint32)(v6)) >> 1);
  else
    v7 = (v6 >> 1);
  v8 = ((sint32)((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 0u)) << (uint32)(8))) + (uint32)(v7)) / v6);
  if (((sint32)r_u32(local_objects + 4u) <= 0))
    v9 = ((0u - (uint32)(v6)) >> 1);
  else
    v9 = (v6 >> 1);
  v10 = ((sint32)((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 4u)) << (uint32)(8))) + (uint32)(v9)) / v6);
  if (((sint32)r_u32(local_objects + 8u) <= 0))
    v11 = ((0u - (uint32)(v6)) >> 1);
  else
    v11 = (v6 >> 1);
  v12 = ((sint32)((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 8u)) << (uint32)(8))) + (uint32)(v11)) / v6);
  v13 = v6;
  if (((sint32)r_u32(0x800773B8u) <= 0))
    v14 = ((0u - (uint32)(v6)) >> 1);
  else
    v14 = (v6 >> 1);
  v15 = (sint32)r_u32(0x8007744Cu);
  w_u32(0x800774ACu, ((sint32)((uint32)((sint32)((uint32)((sint32)r_u32(0x800773B8u)) << (uint32)(8))) + (uint32)(v14)) / v13));
  v16 = (sint32)r_u32(0x80077444u);
  v17 = (sint32)r_u32(0x80077450u);
  if (((sint32)r_u32(0x8007744Cu) < (sint32)((uint32)(v12) - (uint32)(v10))))
  {
    w_u16(0x80077524u, 32760);
    v19 = (sint32)((uint32)(v12) + (uint32)(v10));
  }
  else
  {
    result = (0u - (uint32)(1));
    if (((sint32)((uint32)(v12) + (uint32)((sint32)r_u32(0x8007744Cu))) < v10))
      { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
    w_u32(a3, ((uint32)(r_u32(a3)) | (uint32)(4u)));
    w_u16(0x80077524u, (sint32)((uint32)(v12) - (uint32)(v10)));
    v19 = (sint32)((uint32)(v12) + (uint32)(v10));
  }
  if ((v15 < v19))
  {
    w_u16(0x8007751Eu, 32760);
    v20 = (sint32)((uint32)(v12) - (uint32)(v8));
  }
  else
  {
    result = (0u - (uint32)(1));
    if ((v10 < (sint32)((uint32)((0u - (uint32)(v12))) - (uint32)(v15))))
      { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
    w_u32(a3, ((uint32)(r_u32(a3)) | (uint32)(8u)));
    w_u16(0x8007751Eu, v19);
    v20 = (sint32)((uint32)(v12) - (uint32)(v8));
  }
  if ((v16 < v20))
  {
    w_u16(0x80077522u, 32760);
    v21 = (sint32)((uint32)(v12) + (uint32)(v8));
  }
  else
  {
    result = (0u - (uint32)(1));
    if (((sint32)((uint32)(v12) + (uint32)(v16)) < v8))
      { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
    w_u32(a3, ((uint32)(r_u32(a3)) | (uint32)(1u)));
    w_u16(0x80077522u, v20);
    v21 = (sint32)((uint32)(v12) + (uint32)(v8));
  }
  if ((v16 < v21))
  {
    w_u16(0x8007751Cu, 32760);
  }
  else
  {
    result = (0u - (uint32)(1));
    if ((v8 < (sint32)((uint32)((0u - (uint32)(v12))) - (uint32)(v16))))
      { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
    w_u32(a3, ((uint32)(r_u32(a3)) | (uint32)(2u)));
    w_u16(0x8007751Cu, v21);
  }
  v22 = (sint32)((uint32)(v12) - (uint32)((sint32)r_u32(0x800773B4u)));
  if (((sint32)((uint32)(v12) - (uint32)((sint32)r_u32(0x800773B4u))) >= v17))
  {
    w_u16(0x80077520u, 32760);
  }
  else
  {
    result = (0u - (uint32)(1));
    if ((v12 < (sint32)((uint32)((sint32)r_u32(0x800773B4u)) - (uint32)(v17))))
      { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
    w_u32(a3, ((uint32)(r_u32(a3)) | (uint32)(0x20u)));
    w_u16(0x80077520u, v22);
  }
  v23 = (sint32)((uint32)((sint32)r_u32(0x800774ACu)) - (uint32)(v12));
  if (((sint32)((uint32)((sint32)r_u32(0x800774ACu)) - (uint32)(v12)) >= v17))
  {
    w_u16(0x8007752Cu, 32760);
  }
  else
  {
    result = (0u - (uint32)(1));
    if (((sint32)((uint32)((sint32)r_u32(0x800773B8u)) + (uint32)(v17)) < v12))
      { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
    w_u32(a3, ((uint32)(r_u32(a3)) | (uint32)(0x10u)));
    w_u16(0x8007752Cu, v23);
  }
  if (!(r_u32(a3)))
    { uint32 draft_return = 1; ob_draft_scratch_release(local_objects);  return draft_return; }
  if ((a2 == 2))
  {
    v24 = (0u - (uint32)(2146960296));
    v25 = (0u - (uint32)(2146960296));
  }
  else
  {
    v24 = (0u - (uint32)(2146960680));
    v25 = (0u - (uint32)(2146960680));
    if ((a2 == 1))
    {
      v24 = (0u - (uint32)(2146960488));
      v25 = (0u - (uint32)(2146960488));
    }
  }
  ob_draft_unresolved_call(0x8002c4acu, 2u, v25, 8);
  v26 = (0u - (uint32)(1));
  v27 = 0;
  for (i = 7; (i >= 0); --i)
  {
    v29 = r_u32((uint32)((sint32)((uint32)(v24) + (uint32)(16))));
    v24 += 24;
    v26 &= v29;
    v27 |= v29;
  }

  result = (0u - (uint32)(1));
  if (!v26)
    { uint32 draft_return = (v27 != 0); ob_draft_scratch_release(local_objects);  return draft_return; }
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


sint32 sub_800415E4(uint32 a1)
{
    FUNCTION_MARKER(0x800415e4u, "SLES_008.65");
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Bind external adapter for sub_8005F398 */
    /* TODO: Bind external adapter for sub_8005F428 */
  sint32 v2;
  sint32 v3;
  uint32 v4;
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
  sint32 result;
  uint32 v18;
  uint32 v19;
  uint32 v20;
  sint32 v21;
  uint32 v22;
  sint32 v23;
  uint32 v24;
  uint32 v25;
  sint32 v26;
  sint32 v27;
  sint32 v28;
  uint32 v29;
  sint32 v30;
  uint32 v31;
  sint32 v32;
  sint32 v33;
  sint16 v34;
  sint8 v35;
  uint32 v36;
  sint32 v37;
  w_u32(0x1F800020, r_u32(0x8007FE08));
  w_u32(0x1F800024, r_u32(0x8007FE0C));
  w_u16(0x1F800028, r_u32(0x8007FE10));
  w_u32(0x1F80002C, r_u32(0x8007FE14));
  w_u32(0x1F800030, r_u32(0x8007FE18));
  w_u32(0x1F800034, r_u32(0x8007FE1C));
  w_u32(0x1F800038, r_u32(0x8007FE20));
  w_u32(0x1F80003C, r_u32(0x8007FE24));
  w_u16(0x1F800028, (0u - (uint32)(r_u32(0x8007FE10))));
  v2 = r_u32((a1 + (6) * 4u));
  v3 = 0;
  v4 = (((uint32)(r_u16((uint32)(((uint32)(r_u32((a1 + (7) * 4u))) + (uint32)(76))))) * (uint32)((uint32)(r_u16((uint32)((sint32)((uint32)(v2) + (uint32)(8))))))) >> 8);
  if (((uint16)(v4) > 0xFF00u))
    v4 = ((uint32)(v4) & ~(65535u << 0) | (((uint32)((0u - (uint32)(256))) & 65535u) << 0));
  v5 = r_u32((a1 + (3) * 4u));
  v6 = (sint32)((uint32)(v5) << (uint32)(8));
  if ((v5 <= 0))
    v7 = ((0u - (uint32)((uint16)(v4))) >> 1);
  else
    v7 = ((uint16)(v4) >> 1);
  v8 = (sint32)((uint32)(v6) + (uint32)(v7));
  if (!((uint16)(v4)))
    ob_draft_unresolved_call(0x800415e4u, 2u, 7u, 0);
  w_u32(0x1F800034, (v8 / (uint16)(v4)));
  v9 = r_u32((a1 + (4) * 4u));
  v10 = (sint32)((uint32)(v9) << (uint32)(8));
  if ((v9 <= 0))
    v11 = ((0u - (uint32)((uint16)(v4))) >> 1);
  else
    v11 = ((uint16)(v4) >> 1);
  v12 = (sint32)((uint32)(v10) + (uint32)(v11));
  w_u32(0x1F800038, (0u - (uint32)((v12 / (uint16)(v4)))));
  v13 = r_u32((a1 + (5) * 4u));
  v14 = (sint32)((uint32)(v13) << (uint32)(8));
  if ((v13 <= 0))
    v15 = ((0u - (uint32)((uint16)(v4))) >> 1);
  else
    v15 = ((uint16)(v4) >> 1);
  v16 = ((sint32)((uint32)(v14) + (uint32)(v15)) / (uint16)(v4));
  w_u32(0x1F80003C, v16);
  result = ((uint32)v16 < (uint32)(((uint32)((r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800770C0u)) + (uint32)(8)))) >> 1)) + (uint32)(10))));
  if (((uint32)v16 >= (uint32)(((uint32)((r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800770C0u)) + (uint32)(8)))) >> 1)) + (uint32)(10)))))
  {
    v18 = r_u32(0x1F800038);
    v19 = r_u32(0x1F800034);
    if ((r_u32(0x1F800034) < 0))
      v19 = (0u - (uint32)(r_u32(0x1F800034)));
    if ((r_u32(0x1F800038) < 0))
      v18 = (0u - (uint32)(r_u32(0x1F800038)));
    if ((v19 < v18))
      v19 = v18;
    v20 = v16;
    if ((v16 < 0))
      v20 = (0u - (uint32)(v16));
    v21 = (v19 < 0x7FF9);
    if ((v19 >= v20))
      goto LABEL_29;
    v19 = v20;
    while (1)
    {
      v21 = (v19 < 0x7FF9);
      LABEL_29:
      v19 >>= 1;

      if (v21)
        break;
      ++v3;
      w_u32(0x1F800034, ((sint32)(r_u32(0x1F800034)) >> 1));
      w_u32(0x1F80003C, ((sint32)(r_u32(0x1F80003C)) >> 1));
      w_u32(0x1F800038, ((sint32)(r_u32(0x1F800038)) >> 1));
    }

    sub_8005F488(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800770C0u)) + (uint32)(8)))));
    if (v3)
    {
      w_u32(0x1F800020, (r_u32(0x1F800020) >> v3));
      w_u32(0x1F800022, (r_u32(0x1F800022) >> v3));
      w_u32(0x1F800024, (r_u32(0x1F800024) >> v3));
      w_u32(0x1F800026, (r_u32(0x1F800026) >> v3));
      w_u16(0x1F800028, (r_u16(0x1F800028) >> v3));
      w_u32(0x1F80002A, (r_u32(0x1F80002A) >> v3));
      w_u32(0x1F80002C, (r_u32(0x1F80002C) >> v3));
      w_u32(0x1F80002E, (r_u32(0x1F80002E) >> v3));
      w_u32(0x1F800030, (r_u32(0x1F800030) >> v3));
    }
    ob_draft_unresolved_call(0x8005f398u, 1u, 528482336);
    ob_draft_unresolved_call(0x8005f428u, 1u, 528482336);
    v22 = (sint32)((uint32)(4) * (uint32)(r_u16((uint32)((sint32)((uint32)(v2) + (uint32)(10))))));
    if ((v22 >= (sint32)r_u32(0x8007759Cu)))
    {
      w_u32(0x80077574u, sub_8002D98C(v22));
    }
    else
    {
      w_u32(0x8007759Cu, ((uint32)((sint32)r_u32(0x8007759Cu)) - (uint32)(v22)));
      w_u32(0x80077574u, (sint32)r_u32(0x80077530u));
      w_u32(0x80077530u, ((uint32)((sint32)r_u32(0x80077530u)) + (uint32)(v22)));
    }
    w_u16(0x80077388u, r_u16((uint32)((sint32)((uint32)(v2) + (uint32)(10)))));
    sub_8003584C(v2);
    if (!(sint32)r_u32(0x800774CCu))
      w_u32(0x80077634u, (sint32)((uint32)((sint32)((uint32)((sint32)r_u32(0x8007737Cu)) + (uint32)((sint32)((uint32)(4) * (uint32)((sint32)r_u32(0x80077350u)))))) + (uint32)(112)));
    v23 = (sint32)r_u32(0x800774A8u);
    v24 = (uint32)((sint32)r_u32(0x80077634u));
    v25 = r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(40))));
    v26 = r_u16((uint32)((sint32)((uint32)(v2) + (uint32)(14))));
    v27 = (sint32)r_u32(0x80077574u);
    v28 = r_u32((uint32)((sint32)r_u32(0x80077634u)));
    if (r_u16((uint32)((sint32)((uint32)(v2) + (uint32)(14)))))
    {
      v29 = (v25 + (17) * 2u);
      v30 = (sint32)((uint32)((sint32)r_u32(0x800774A8u)) - (uint32)(33));
      do
      {
        v31 = (uint32)(v23);
        v32 = r_u32((uint32)((v29 - (7) * 2u)));
        w_u32(v24, ((r_u32(v24) & 0xFF000000) | (v23 & 0xFFFFFF)));
        v30 += 40;
        w_u32((uint32)((sint32)((uint32)(v30) + (uint32)(1))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)((sint16)r_u16((v29 - (11) * 2u)))))) + (uint32)(v27)))));
        w_u32((uint32)((sint32)((uint32)(v30) + (uint32)(9))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)((sint16)r_u16((v29 - (10) * 2u)))))) + (uint32)(v27)))));
        w_u32((uint32)((sint32)((uint32)(v30) + (uint32)(25))), r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)((sint16)r_u16((v29 - (9) * 2u)))))) + (uint32)(v27)))));
        v33 = r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((uint16)((sint16)r_u16((v29 - (8) * 2u)))))) + (uint32)(v27))));
        w_u32((uint32)((sint32)((uint32)(v30) - (uint32)(3))), 8355711);
        w_u32((uint32)((sint32)((uint32)(v30) + (uint32)(17))), v33);
        w_u16((uint32)((sint32)((uint32)(v30) + (uint32)(5))), (sint16)r_u16((v29 - (3) * 2u)));
        w_u16((uint32)((sint32)((uint32)(v30) + (uint32)(13))), (sint16)r_u16((v29 - (2) * 2u)));
        v23 += 40;
        w_u16((uint32)((sint32)((uint32)(v30) + (uint32)(29))), (sint16)r_u16((v29 - (1) * 2u)));
        v34 = (sint16)r_u16(v29);
        w_u16((uint32)((sint32)((uint32)(v30) + (uint32)(7))), (uint16)((v32) >> 16));
        w_u16((uint32)((sint32)((uint32)(v30) + (uint32)(15))), v32);
        w_u16((uint32)((sint32)((uint32)(v30) + (uint32)(21))), v34);
        v24 = v31;
        if (((r_u16(v25) & 0x100) != 0))
          v35 = 46;
        else
          v35 = 44;
        w_u8((uint32)((sint32)((uint32)(v30) - (uint32)(4))), 9);
        w_u8((uint32)(v30), v35);
        v29 += (22) * 2u;
        --v26;
        v25 += (22) * 2u;
      }
      while ((v26 > 0));
    }
    v36 = r_u32(v24);
    v37 = (uint16)((sint16)r_u16(0x80077498u));
    w_u32(0x800774A8u, v23);
    w_u32(0x80077634u, (sint32)(v24));
    w_u32(v24, ((v36 & 0xFF000000) | (v28 & 0xFFFFFF)));
    /* TODO Recover SDK return carrier */
    return (sint32)ob_draft_unresolved_call(0x8005F488u, 1u, (uint32)v37);
  }
  return result;
}


sint32 sub_8002D25C(uint32 a1, sint32 a2)
{
    FUNCTION_MARKER(0x8002d25cu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8002DB08 */
    /* TODO: Bind external adapter for sub_80035270 */
    /* TODO: Bind external adapter for sub_8002DB80 */
    /* TODO: Bind external adapter for sub_80041B74 */
    /* TODO: Resolve external symbol __PAIR64__ instead of the owning function adapter placeholder */
    /* TODO: Bind external adapter for __PAIR64__ */
    /* TODO: Bind external adapter for sub_8005C954 */
  sint32 v5;
  sint32 v6;
  sint32 v7;
  int64_t v9;
  int64_t v10;
  sint32 v11;
  sint32 v12;
  uint32 v13;
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
  if ((r_u32((a1 + (38) * 4u)) != 2137281625))
    return 0;
  sub_8002CEB0(a1);
  v5 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8007741Cu)) + (uint32)(12))));
  v6 = r_u32((uint32)((sint32)((uint32)(v5) + (uint32)(24))));
  v7 = r_u32((uint32)((sint32)((uint32)(v5) + (uint32)(28))));
  w_u32(0x80077590u, (sint32)((a1 + (18) * 4u)));
  w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800770C0u)) + (uint32)(4))), a1);
  w_u16(0x800774A4u, (v6 >> 1));
  w_u16(0x800774A6u, (v7 >> 1));
  ob_draft_unresolved_call(0x8002db08u, 0u);
  ob_draft_unresolved_call(0x80035270u, 0u);
  w_u32(0x800775D0u, a2);
  if (((sint32)r_u32(0x800770E4u) <= 0))
    ob_draft_unresolved_call(0x8002db80u, 4u, 18u, 0x80010984u, 0u, 0u);
  ob_draft_unresolved_call(0x80041b74u, 0u);
  sub_80041BB8();
  sub_8005F488((uint16)((sint16)r_u16(0x80077498u)));
  sub_8005F468((sint16)r_u16(0x800774A4u), (sint16)r_u16(0x800774A6u));
  v9 = (int64_t)(sint16)r_u16(r_u32(0x80077590u) + 16u);

  w_u32(0x800773B4u, (((uint64_t)(v9) * (uint64_t)((uint32)((sint32)r_u32(0x800775F8u)))) >> 14));
  if (((sint32)r_u32(0x800773B4u) <= 0))
    w_u32(0x800773B4u, 1);
  v10 = (int64_t)(sint16)r_u16(r_u32(0x80077590u) + 16u) * (int64_t)r_u32(0x80077600u);
  w_u32(0x80077508u, ((uint32)(((uint16)((sint16)r_u16(0x80077498u)) >> 1)) + (uint32)(10)));
  w_u32(0x800773B8u, (v10 >> 14));
  if ((sint32)r_u32(0x800773D0u))
    v11 = (sint32)r_u32(0x800775C0u);
  else
    v11 = (sint32)r_u32(0x80077368u);
  w_u32(0x800774A8u, v11);
  w_u32(0x800775BCu, (sint32)((uint32)((sint32)((uint32)(v11) + (uint32)((sint32)r_u32(0x80077374u)))) - (uint32)(196)));
  ob_draft_unresolved_call(0x8005c954u, 2u, (sint32)((uint32)((sint32)r_u32(0x8007737Cu)) + (uint32)(112)), 8);
  w_u32(0x80077634u, (sint32)((uint32)((sint32)r_u32(0x8007737Cu)) + (uint32)(136)));
  sub_80042928((sint32)r_u32(0x800775D0u), (0u - (uint32)(2146907440)));
  sub_80043404();
  v12 = ((sint32)((uint32)(2375) * (uint32)((sint16)r_u16((uint32)((sint32)r_u32(0x80077590u))))) >> 13);
  v13 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8007741Cu)) + (uint32)(12))));
  w_u32(0x8007738Cu, ((uint32)(((uint32)(r_u32((v13 + (2) * 4u))) - (uint32)(r_u32(v13)))) + (uint32)((sint16)r_u16(0x800774A4u))));
  v14 = ((uint32)(((uint32)(r_u32((v13 + (4) * 4u))) - (uint32)(r_u32(v13)))) + (uint32)((sint16)r_u16(0x800774A4u)));
  v15 = ((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8007741Cu)) + (uint32)(12))))) + (uint32)(12))))) - (uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8007741Cu)) + (uint32)(12))))) + (uint32)(4))))));
  v16 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8007741Cu)) + (uint32)(12))));
  w_u32(0x80077398u, v14);
  v17 = r_u32((uint32)((sint32)((uint32)(v16) + (uint32)(20))));
  v18 = r_u32((uint32)((sint32)((uint32)(v16) + (uint32)(4))));
  w_u32(0x80077390u, (sint32)((uint32)(v15) + (uint32)((sint16)r_u16(0x800774A6u))));
  w_u32(0x8007739Cu, (sint32)((uint32)((sint32)((uint32)(v17) - (uint32)(v18))) + (uint32)((sint16)r_u16(0x800774A6u))));
  v19 = (sint32)((uint32)(11585) * (uint32)((sint16)((sint32)((uint32)(2) * (uint32)(v12)))));
  if (((((sint32)((uint32)(2) * (uint32)(v12)) ^ 0x2D41) & 0x8000) != 0))
    v20 = (sint32)((uint32)(v19) - (uint32)(0x2000));
  else
    v20 = (sint32)((uint32)(v19) + (uint32)(0x2000));
  w_u32(0x80077444u, (v20 >> 14));
  v21 = ((sint32)((uint32)(2375) * (uint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x80077590u)) + (uint32)(8)))))) >> 13);
  v22 = (sint32)((uint32)(11585) * (uint32)((sint16)((sint32)((uint32)(2) * (uint32)(v21)))));
  if (((((sint32)((uint32)(2) * (uint32)(v21)) ^ 0x2D41) & 0x8000) != 0))
    v23 = (sint32)((uint32)(v22) - (uint32)(0x2000));
  else
    v23 = (sint32)((uint32)(v22) + (uint32)(0x2000));
  w_u32(0x8007744Cu, (v23 >> 14));
  v24 = ((sint32)((uint32)(2375) * (uint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x80077590u)) + (uint32)(16)))))) >> 13);
  v25 = (sint32)((uint32)(11585) * (uint32)((sint16)((sint32)((uint32)(2) * (uint32)(v24)))));
  if (((((sint32)((uint32)(2) * (uint32)(v24)) ^ 0x2D41) & 0x8000) != 0))
    v26 = (sint32)((uint32)(v25) - (uint32)(0x2000));
  else
    v26 = (sint32)((uint32)(v25) + (uint32)(0x2000));
  w_u32(0x80077450u, (v26 >> 14));
  v27 = ((sint32)((uint32)(5875) * (uint32)((sint16)r_u16((uint32)((sint32)r_u32(0x80077590u))))) >> 14);
  v28 = (sint32)((uint32)(11585) * (uint32)((sint16)((sint32)((uint32)(2) * (uint32)(v27)))));
  if (((((sint32)((uint32)(2) * (uint32)(v27)) ^ 0x2D41) & 0x8000) != 0))
    v29 = (sint32)((uint32)(v28) - (uint32)(0x2000));
  else
    v29 = (sint32)((uint32)(v28) + (uint32)(0x2000));
  w_u32(0x800774BCu, (v29 >> 14));
  v30 = ((sint32)((uint32)(5875) * (uint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x80077590u)) + (uint32)(8)))))) >> 14);
  v31 = (sint32)((uint32)(11585) * (uint32)((sint16)((sint32)((uint32)(2) * (uint32)(v30)))));
  if (((((sint32)((uint32)(2) * (uint32)(v30)) ^ 0x2D41) & 0x8000) != 0))
    v32 = (sint32)((uint32)(v31) - (uint32)(0x2000));
  else
    v32 = (sint32)((uint32)(v31) + (uint32)(0x2000));
  w_u32(0x800774C4u, (v32 >> 14));
  v33 = ((sint32)((uint32)(5875) * (uint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x80077590u)) + (uint32)(16)))))) >> 14);
  v34 = (sint32)((uint32)(11585) * (uint32)((sint16)((sint32)((uint32)(2) * (uint32)(v33)))));
  if (((((sint32)((uint32)(2) * (uint32)(v33)) ^ 0x2D41) & 0x8000) != 0))
    v35 = (sint32)((uint32)(v34) - (uint32)(0x2000));
  else
    v35 = (sint32)((uint32)(v34) + (uint32)(0x2000));
  w_u32(0x800774C8u, (v35 >> 14));
  return (0u - (uint32)(1));
}




