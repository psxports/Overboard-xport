#include "draft_signatures.h"

/* Unverified draft bodies */

uint32 sub_8001E298(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8001e298u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80061104 */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Bind external adapter for sub_80062A24 */
    /* TODO: Recover missing meaningful carriers for sub_800629C4 before binding the native call */
    /* TODO: Bind external adapter for sub_80062AAC */
  sint32 result;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  sint32 v11;
  sint32 v12;
  sint32 v13;
  uint32 v14;
  if (!(sint8)r_u8(0x8006c00cu))
    return (sint32)(0u - (uint32)(1));
  v5 = sub_80020260(r_u32((uint32)(((uint32)(a1) + (uint32)(12)))));
  v6 = ob_draft_unresolved_call(0x80061104u, 1u, v5);
  result = (sint32)(0u - (uint32)(2));
  if ((v6 != (sint32)(0u - (uint32)(1))))
  {
    v7 = 0;
    if (!(sint32)r_u32(0x800778A4))
    {
      LABEL_9:
      v10 = sub_80020260(r_u32((uint32)(((uint32)(a1) + (uint32)(16)))));

      v11 = (sint32)((uint32)(20) * (uint32)(v7));
      w_u32((uint32)((sint32)((uint32)(v11) - (uint32)(2146994016))), v6);
      w_u32((uint32)((sint32)((uint32)(v11) - (uint32)(2146994012))), v5);
      w_u32((uint32)((sint32)((uint32)(v11) - (uint32)(2146994000))), ((sint32)((sint32)((uint32)(v10) << (uint32)(12))) / (sint32)(44100)));
      ob_draft_unresolved_call(0x80062a24u, 1u, (uint32)v6);
      ob_draft_unresolved_call(0x800629c4u, 2u, ((uint32)(a1) + (uint32)(48)), v5);
      ob_draft_unresolved_call(0x80062aacu, 1u, 1);
      if (a2)
      {
        v12 = sub_80020260(r_u32((uint32)(((uint32)(a2) + (uint32)(12)))));
        v13 = ob_draft_unresolved_call(0x80061104u, 1u, v12);
        result = (sint32)(0u - (uint32)(2));
        if ((v13 == (sint32)(0u - (uint32)(1))))
          return result;
        v14 = (sub_80020260(r_u32((uint32)(((uint32)(a2) + (uint32)(16))))) == v10);
        result = (sint32)(0u - (uint32)(4));
        if (!v14)
          return result;
        w_u32((uint32)((sint32)((uint32)(v11) - (uint32)(2146994008))), v13);
        w_u32((uint32)((sint32)((uint32)(v11) - (uint32)(2146994004))), v12);
        ob_draft_unresolved_call(0x80062a24u, 1u, (uint32)v13);
        ob_draft_unresolved_call(0x800629c4u, 2u, ((uint32)(a2) + (uint32)(48)), v12);
        ob_draft_unresolved_call(0x80062aacu, 1u, 1);
      }
      return v7;
    }
    v8 = 0;
    v9 = 1;
    while (1)
    {
      v8 = ((uint32)(v8) + (uint32)(20));
      if ((v9 == 128))
        return (sint32)(0u - (uint32)(3));
      ++v9;
      if (!(r_u32((uint32)((sint32)((uint32)(v8) - (uint32)(2146994012))))))
      {
        v7 = (sint32)((uint32)(v9) - (uint32)(1));
        goto LABEL_9;
      }
    }

  }
  return result;
}


uint32 sub_8001A4B0(uint32 a1, uint32 a2, uint32 a3, uint32 divisor_address)
{
    FUNCTION_MARKER(0x8001a4b0u, "SLES_008.65");
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    uint32 local_objects = ob_draft_scratch_acquire(4u);
  uint32 v3 = divisor_address;
  sint32 v4;
  ;
  sint32 v6;
  sint32 v7;
  sint32 result;
  sint16 v9;
  uint32 v10;
  sint32 v11;
  sint32 v12;
  v4 = (sint32)r_u32(v3);
  w_u32(local_objects + 0u, ((uint32)(a1) + (uint32)(a3)));
  if (!((sint32)r_u32(v3)))
    ob_draft_unresolved_call(0x8001a4b0u, 2u, 7u, 0);
  if (((v4 == (sint32)(0u - (uint32)(1))) && ((sint32)r_u32(local_objects + 0u) == 0x80000000)))
    ob_draft_unresolved_call(0x8001a4b0u, 2u, 6u, 0);
  v6 = ((sint32)((sint32)r_u32(local_objects + 0u)) / (sint32)((sint32)r_u32(v3)));
  v7 = ((sint32)((sint32)((uint32)((sint32)r_u32(0x80077468u)) - (uint32)(a2))) / (sint32)(v4));
  if (((v4 == (sint32)(0u - (uint32)(1))) && ((sint32)((uint32)((sint32)r_u32(0x80077468u)) - (uint32)(a2)) == 0x80000000)))
    ob_draft_unresolved_call(0x8001a4b0u, 2u, 6u, 0);
  if (((sub_8004BF54((sint16)(v6), (sint16)(v7)) & 3) == 1))
  {
    result = ((uint32)(result) & ~((uint32)65535u << 0) | (((uint32)(v6) & 65535u) << 0));
    LABEL_18:
    v9 = v7;

    goto LABEL_19;
  }
  if (((sub_8004BF54((sint16)(v6), (sint32)((uint32)((sint16)(v7)) - (uint32)(1))) & 3) == 1))
  {
    result = ((uint32)(result) & ~((uint32)65535u << 0) | (((uint32)(v6) & 65535u) << 0));
    v9 = (sint32)((uint32)(v7) - (uint32)(1));
  }
  else
  {
    if (((sub_8004BF54((sint16)(v6), (sint32)((uint32)((sint16)(v7)) + (uint32)(1))) & 3) != 1))
    {
      if (((sub_8004BF54((sint32)((uint32)((sint16)(v6)) - (uint32)(1)), (sint16)(v7)) & 3) == 1))
      {
        result = ((uint32)(result) & ~((uint32)65535u << 0) | (((uint32)((sint32)((uint32)(v6) - (uint32)(1))) & 65535u) << 0));
      }
      else
      {
        v10 = ((sub_8004BF54((sint32)((uint32)((sint16)(v6)) + (uint32)(1)), (sint16)(v7)) & 3) != 1);
        result = (sint32)((uint32)(v6) + (uint32)(1));
        if (v10)
          { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
      }
      goto LABEL_18;
    }
    result = ((uint32)(result) & ~((uint32)65535u << 0) | (((uint32)(v6) & 65535u) << 0));
    v9 = (sint32)((uint32)(v7) + (uint32)(1));
  }
  LABEL_19:
  v11 = r_u32((uint32)((sint32)r_u32(0x80077644u)));

  v12 = (sint32)((uint32)((sint16)(result)) * (uint32)(r_u32((uint32)((sint32)r_u32(0x80077644u)))));
  w_u32(0x8008C6EC, 0);
  w_u32(0x8008C6E8, (sint32)((uint32)((sint32)((uint32)(v12) - (uint32)((sint32)r_u32(0x80077458u)))) + (uint32)(((sint32)(v11) >> 1))));
  result = (sint32)((uint32)((sint32)((uint32)((sint32)r_u32(0x80077468u)) - (uint32)((sint32)((uint32)(v9) * (uint32)(r_u32((uint32)((sint32)r_u32(0x80077644u)))))))) - (uint32)(((sint32)((sint32)r_u32((uint32)((sint32)r_u32(0x80077644u)))) >> 1)));
  w_u32(0x8008C6F0, result);
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80050380(uint32 a1)
{
    FUNCTION_MARKER(0x80050380u, "SLES_008.65");
    uint32 local_objects = ob_draft_scratch_acquire(24u);
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
  sint8 v14;
  ;
  uint32 v17;
  ;
  ;
  ;
  ;
  v2 = r_u32(a1);
  w_u32((a1 + (31) * 4u), 0);
  w_u32((a1 + (32) * 4u), 1);
  w_u32((a1 + (29) * 4u), v2);
  v3 = r_u32((a1 + (33) * 4u));
  v4 = (uint32)(r_u32((a1 + (34) * 4u)));
  v5 = r_u32((a1 + (35) * 4u));
  v6 = r_u32((a1 + (36) * 4u));
  w_u32(local_objects + 0u, v3);
  v17 = v4;
  w_u32(local_objects + 8u, v5);
  w_u32(local_objects + 12u, v6);
  v7 = r_u32((a1 + (38) * 4u));
  w_u32(local_objects + 16u, r_u32((a1 + (37) * 4u)));
  w_u32(local_objects + 20u, v7);
  w_u32(local_objects + 16u, ((uint32)((sint32)r_u32(local_objects + 16u)) & ~((uint32)255u << 0) | (((uint32)(2) & 255u) << 0)));
  v8 = r_u32((a1 + (66) * 4u));
  v9 = r_u32((a1 + (56) * 4u));
  for (w_u32((a1 + (48) * 4u), r_u32((a1 + (58) * 4u))); ((sint32)(v9) >= (sint32)(0)); --v9)
  {
    v10 = r_u32((a1 + (96) * 4u));
    v11 = r_u32((a1 + (86) * 4u));
    for (w_u32((a1 + (50) * 4u), r_u32((a1 + (88) * 4u))); ((sint32)(v11) >= (sint32)(0)); --v11)
    {
      v12 = (sint16)r_u16(((uint32)(a1) + (23) * 2u));
      if (((v12 & (sint8)(((sint32)r_u32(local_objects + 16u)) >> 8)) == 0))
      {
        if ((((uint8)(v12) & r_u8((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 12u)) + (uint32)(22))))) != 0))
        {
          v14 = 1;
          if ((((uint16)(v12) & r_u16(v17)) == 0))
            v14 = 2;
          w_u8(((uint32)(a1) + (148) * 1u), v14);
        }
        else
        {
          v13 = v8;
          if (((sint32)(v10) < (sint32)(v8)))
            v13 = v10;
          w_u32((a1 + (30) * 4u), v13);
          sub_80050B88((sint32)r_u32(local_objects + 8u), a1);
        }
      }
      if (v11)
      {
        v10 = r_u32((a1 + (98) * 4u));
        sub_8005160C((local_objects + 0u), 1, r_u32((a1 + (87) * 4u)));
        w_u32((a1 + (50) * 4u), ((uint32)(r_u32((a1 + (50) * 4u))) + (uint32)(r_u32((a1 + (89) * 4u)))));
      }
    }

    if (r_u32((a1 + (86) * 4u)))
      sub_8005160C((local_objects + 0u), 1, (0u - (uint32)(r_u32((a1 + (87) * 4u)))));
    if (v9)
    {
      v8 = r_u32((a1 + (68) * 4u));
      sub_8005160C((local_objects + 0u), 0, r_u32((a1 + (57) * 4u)));
      w_u32((a1 + (48) * 4u), ((uint32)(r_u32((a1 + (48) * 4u))) + (uint32)(r_u32((a1 + (59) * 4u)))));
    }
  }

  { uint32 draft_return = 0; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_8004C2C4(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x8004c2c4u, "SLES_008.65");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Recover missing meaningful carriers for sub_8004B514 before binding the native call */
  sint32 v4;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  sint32 i;
  uint32 v12;
  sint16 v13;
  sint32 v14;
  uint32 v15;
  sint32 v16;
  sint32 v17;
  sint32 v18;
  v4 = (sint32)r_u32(0x800665d8u);
  if ((((sint32)r_u32(0x800665d8u) & 3) != 0))
    v4 = sub_800257CC((sint32)((0x800665d8u)));
  else
    (w_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800665d8u)) - (uint32)(6))), (r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800665d8u)) - (uint32)(6)))) + 1u)), r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800665d8u)) - (uint32)(6)))));
  w_u32(0x80077644u, v4);
  v7 = ((uint32)(a2) + (uint32)((sint32)r_u32(0x80077458u)));
  v8 = (sint32)((uint32)((sint32)r_u32(0x80077468u)) - (uint32)(a3));
  if ((((sint32)(v7) < (sint32)(0)) || ((sint32)(v8) < (sint32)(0))))
    goto LABEL_10;
  v9 = (v7 / r_u32((uint32)(v4)));
  if (!(r_u32((uint32)(v4))))
    ob_draft_unresolved_call(0x8004c2c4u, 2u, 7u, 0);
  v10 = (v7 / r_u32((uint32)(v4)));
  if ((((sint32)(v9) < (sint32)((sint32)((uint32)(16) * (uint32)((sint16)r_u16((uint32)((sint32)((uint32)(v4) + (uint32)(4)))))))) && ((sint32)((sint32)(0u - (uint32)(v8))) < (sint32)((sint32)((uint32)(16) * (uint32)((sint16)r_u16((uint32)((sint32)((uint32)(v4) + (uint32)(6))))))))))
  {
    v12 = (uint32)(ob_draft_unresolved_call(0x8004b514u, 2u, ((uint32)(((uint8)(v10) | ((uint32)((uint8)((sint32)(0u - (uint32)((sint8)(v8))))) << (uint32)(8)))) << (uint32)(16)), v4));
    v13 = r_u16(((uint32)(v12) + (1) * 2u));
    v14 = 0;
    v15 = ((uint32)((sint32)r_u32(0x800739fcu)) + ((sint32)((uint32)(9) * (uint32)((v13 & 3)))) * 1u);
    v16 = ((sint32)((sint32)((uint32)((v13 & 0xFFFC)) << (uint32)(16))) >> 14);
    v17 = ((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80077644u)) + (uint32)(24))))) + (uint32)((sint32)((uint32)(24) * (uint32)(r_u8(v12)))));
    do
    {
      v18 = (sint8)r_u8(((v15 += 1u) - 1u));
      ++v14;
      w_u32(a1++, (sint32)((uint32)(v16) + (uint32)((sint32)((uint32)((sint8)r_u8((uint32)((sint32)((uint32)((sint32)((uint32)(v17) + (uint32)(v18))) + (uint32)(12))))) << (uint32)(6)))));
    }
    while (((sint32)(v14) < (sint32)(9)));
  }
  else
  {
    LABEL_10:
    for (i = 8; ((sint32)(i) >= (sint32)(0)); --i)
      w_u32(a1++, 233450262);


  }
  return sub_800257A0((0x800665d8u));
}


uint32 sub_80025ABC(uint32 a1)
{
    FUNCTION_MARKER(0x80025abcu, "SLES_008.65");
    uint32 local_objects = ob_draft_scratch_acquire(152u);
  sint32 v2;
  uint32 v3;
  sint32 v4;
  uint32 v5;
  sint32 result;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  sint32 v11;
  uint32 v12;
  sint32 v13;
  uint32 v14;
  sint32 v15;
  ;
  ;
  ;
  ;
  ;
  v2 = r_u32(a1);
  v3 = ((r_u32(a1) & 0xFFFFFFC0) >> 4);
  v4 = r_u32((uint32)(((uint32)((r_u32(a1) & 0x3C)) - (uint32)(2146988604))));
  v5 = (sub_800551F8(v4, v3, 0) != v3);
  result = 300;
  if (!v5)
  {
    v5 = (sub_800553D0((local_objects + 0u), 20, v4) != 20);
    result = 301;
    if (!v5)
    {
      result = 302;
      if (((sint32)r_u32(local_objects + 0u) == v2))
      {
        sub_80026694(a1, (sint32)r_u32(local_objects + 4u), 7);
        v7 = sub_800553D0(r_u32(a1), (sint32)r_u32(local_objects + 4u), v4);
        if ((v7 == (sint32)r_u32(local_objects + 4u)))
        {
          if ((sint32)r_u32(0x80077090u))
            ob_draft_unresolved_call(r_u32(0x80077090u), 1u, (uint32)v7);
          v8 = (sint32)r_u32(local_objects + 16u);
          v9 = r_u32(a1);
          v10 = ((sint32)((sint32)r_u32(local_objects + 16u)) < (sint32)(33));
          if ((sint32)r_u32(local_objects + 16u))
          {
            while (1)
            {
              v11 = 32;
              if (v10)
                v11 = v8;
              v8 = ((uint32)(v8) - (uint32)(v11));
              if ((sub_800553D0((local_objects + 24u), (sint32)((uint32)(4) * (uint32)(v11)), v4) != (sint32)((uint32)(4) * (uint32)(v11))))
                { uint32 draft_return = 304; ob_draft_scratch_release(local_objects);  return draft_return; }
              v12 = (local_objects + 24u);
              if (v11)
                break;
              LABEL_19:
              v10 = ((sint32)(v8) < (sint32)(33));

              if (!v8)
                goto LABEL_20;
            }

            while (1)
            {
              v13 = r_u32((uint32)(v12));
              v5 = ((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 4u)) - (uint32)(4))) < r_u32((uint32)(v12)));
              v12 += (4) * 1u;
              if (v5)
                { uint32 draft_return = 305; ob_draft_scratch_release(local_objects);  return draft_return; }
              v14 = (uint32)((sint32)((uint32)(v9) + (uint32)(v13)));
              v15 = sub_80027DF8(r_u16((uint32)((sint32)((uint32)(v9) + (uint32)(v13)))));
              w_u32(v14, v15);
              if (!v15)
                { uint32 draft_return = 306; ob_draft_scratch_release(local_objects);  return draft_return; }
              if (!(--v11))
                goto LABEL_19;
            }

          }
          else
          {
            LABEL_20:
            sub_80026898(a1, r_u16(local_objects + 14u));

            result = 0;
            if ((sint32)r_u32(0x8007708cu))
            {
              result = 0;
              if (((r_u32(a1) & 3) == 0))
              {
                (w_u16((uint32)(((uint32)(r_u32(a1)) - (uint32)(6))), (r_u16((uint32)(((uint32)(r_u32(a1)) - (uint32)(6)))) + 1u)), r_u16((uint32)(((uint32)(r_u32(a1)) - (uint32)(6)))));
                { uint32 draft_return = 0; ob_draft_scratch_release(local_objects);  return draft_return; }
              }
            }
          }
        }
        else
        {
          { uint32 draft_return = 303; ob_draft_scratch_release(local_objects);  return draft_return; }
        }
      }
    }
  }
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80050088(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    FUNCTION_MARKER(0x80050088u, "SLES_008.65");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
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
  sint32 v25;
  sint32 v26;
  sint32 v27;
  sint32 v28;
  sint32 result;
  sint32 v30;
  v4 = r_u32((a1 + (13) * 4u));
  v5 = r_u32((a1 + (14) * 4u));
  v6 = r_u32((a1 + (15) * 4u));
  v7 = r_u32((a1 + (16) * 4u));
  if (((sint32)(v6) < (sint32)(v4)))
  {
    v6 = ((uint32)(v6) + (uint32)(r_u32((a1 + (20) * 4u))));
    v8 = r_u32((a1 + (19) * 4u));
    v7 = ((uint32)(v7) + (uint32)(r_u32((a1 + (21) * 4u))));
    if (((sint32)(v7) >= (sint32)(v8)))
    {
      ++v6;
      v7 = ((uint32)(v7) - (uint32)(v8));
    }
  }
  if ((r_u32((a1 + (6) * 4u)) == (sint32)(0u - (uint32)(1))))
    a2 = (sint32)((uint32)((sint32)r_u32(0x800775ccu)) - (uint32)(a2));
  if ((v4 != a4))
    a2 = ((uint32)(a2) + (uint32)((sint32)((uint32)((sint32)((uint32)(v4) - (uint32)(a4))) * (uint32)(r_u32((a1 + (19) * 4u))))));
  v9 = r_u32((a1 + (19) * 4u));
  v10 = ((uint32)(a2) + (uint32)(a3));
  if ((((sint32)((sint32)(0u - (uint32)(v9))) >= (sint32)(v10)) || ((sint32)(v10) > (sint32)(0))))
  {
    v12 = ((sint32)((sint32)(0u - (uint32)(v10))) % (sint32)(v9));
    if (((v9 == (sint32)(0u - (uint32)(1))) && ((sint32)(0u - (uint32)(v10)) == 0x80000000)))
      ob_draft_unresolved_call(0x80050088u, 2u, 6u, 0);
    v11 = ((sint32)((sint32)(0u - (uint32)(v10))) / (sint32)(v9));
    v13 = v11;
    v14 = ((sint32)((sint32)(0u - (uint32)(v10))) % (sint32)(v9));
    if (((sint32)(v12) < (sint32)(0)))
    {
      v13 = (sint32)((uint32)(v11) - (uint32)(1));
      v14 = (sint32)((uint32)(v12) + (uint32)(v9));
    }
    v4 = ((uint32)(v4) + (uint32)(v13));
    v5 = v14;
    v7 = ((uint32)(v7) + (uint32)(v14));
    v6 = ((uint32)(v6) + (uint32)(v13));
    if (((sint32)(v7) >= (sint32)(v9)))
    {
      ++v6;
      v7 = ((uint32)(v7) - (uint32)(v9));
    }
  }
  v15 = r_u32((a1 + (19) * 4u));
  v16 = ((sint32)((sint32)r_u32(0x800775d8u)) % (sint32)(v15));
  if (((v15 == (sint32)(0u - (uint32)(1))) && ((sint32)r_u32(0x800775d8u) == 0x80000000)))
    ob_draft_unresolved_call(0x80050088u, 2u, 6u, 0);
  v17 = ((sint32)((sint32)r_u32(0x800775d8u)) / (sint32)(v15));
  v18 = ((sint32)((sint32)r_u32(0x800775d8u)) % (sint32)(v15));
  if (((sint32)(v16) < (sint32)(0)))
  {
    v17 = (sint32)((uint32)(((sint32)((sint32)r_u32(0x800775d8u)) / (sint32)(v15))) - (uint32)(1));
    v18 = (sint32)((uint32)(v16) + (uint32)(v15));
  }
  v19 = (sint32)((uint32)(v7) + (uint32)(v18));
  v20 = (sint32)((uint32)(v6) + (uint32)(v17));
  if (((sint32)(v19) >= (sint32)(v15)))
  {
    ++v20;
    v19 = ((uint32)(v19) - (uint32)(v15));
  }
  if (((sint32)a4 >= v20))
  {
    w_u32((a1 + (24) * 4u), 2147483393);
    w_u32((a1 + (25) * 4u), 2147483393);
  }
  else
  {
    w_u32((a1 + (24) * 4u), v4);
    w_u32((a1 + (25) * 4u), v20);
  }
  v21 = r_u32((a1 + (19) * 4u));
  v22 = (sint32)((uint32)(v5) + (uint32)(v18));
  v23 = (sint32)((uint32)(v4) + (uint32)(v17));
  if (((sint32)(v22) >= (sint32)(v21)))
  {
    ++v23;
    v22 = ((uint32)(v22) - (uint32)(v21));
  }
  v24 = (sint32)((uint32)(v19) + (uint32)(v18));
  v25 = (sint32)((uint32)(v20) + (uint32)(v17));
  if (((sint32)(v24) >= (sint32)(v21)))
  {
    ++v25;
    v24 = ((uint32)(v24) - (uint32)(v21));
  }
  if (((sint32)a4 >= v25))
  {
    w_u32((a1 + (26) * 4u), 2147483393);
    w_u32((a1 + (27) * 4u), 2147483393);
  }
  else
  {
    w_u32((a1 + (26) * 4u), v23);
    w_u32((a1 + (27) * 4u), v25);
  }
  v26 = r_u32((a1 + (19) * 4u));
  v27 = (sint32)((uint32)(v23) + (uint32)(v17));
  if (((sint32)((sint32)((uint32)(v22) + (uint32)(v18))) >= (sint32)(v26)))
    ++v27;
  v28 = (sint32)((uint32)(v24) + (uint32)(v18));
  result = ((sint32)(v28) < (sint32)(v26));
  v30 = (sint32)((uint32)(v25) + (uint32)(v17));
  if (((sint32)(v28) >= (sint32)(v26)))
    ++v30;
  w_u32((a1 + (28) * 4u), v27);
  w_u32((a1 + (29) * 4u), v30);
  return result;
}


uint32 sub_800352B4(uint32 a1)
{
    FUNCTION_MARKER(0x800352b4u, "SLES_008.65");
  sint32 v2;
  sint16 v3;
  sint16 v4;
  sint16 v5;
  sint16 v6;
  uint32 v7;
  uint32 v8;
  uint32 v9;
  uint32 v10;
  sint32 result;
  v2 = r_u32((a1 + (5) * 4u));
  v3 = r_u32((a1 + (7) * 4u));
  v4 = r_u32((a1 + (6) * 4u));
  v5 = r_u32((a1 + (8) * 4u));
  v6 = r_u32((a1 + (9) * 4u));
  w_u32(0x80077598u, (sint32)(a1));
  w_u16(0x800775f0u, v3);
  w_u16(0x800775a4u, v4);
  w_u16(0x80077410u, v5);
  w_u16(0x800775a6u, v6);
  w_u16(0x80077388u, v2);
  if (((sint32)((uint32)(24) * (uint32)(v2)) >= (uint32)((sint32)r_u32(0x8007759cu))))
  {
    w_u32(0x80077574u, sub_8002D98C((sint32)((uint32)(24) * (uint32)(v2))));
  }
  else
  {
    w_u32(0x8007759cu, ((uint32)((sint32)r_u32(0x8007759cu)) - (uint32)((sint32)((uint32)(24) * (uint32)(v2)))));
    w_u32(0x80077574u, (sint32)r_u32(0x80077530u));
    w_u32(0x80077530u, ((uint32)((sint32)r_u32(0x80077530u)) + (uint32)((sint32)((uint32)(24) * (uint32)(v2)))));
  }
  v7 = (sint32)((uint32)(44) * (uint32)((uint16)((sint16)r_u16(0x800775a4u))));
  if ((v7 >= (sint32)r_u32(0x8007759cu)))
  {
    w_u32(0x80077518u, sub_8002D98C((sint32)((uint32)(44) * (uint32)((uint16)((sint16)r_u16(0x800775a4u))))));
  }
  else
  {
    w_u32(0x8007759cu, ((uint32)((sint32)r_u32(0x8007759cu)) - (uint32)(v7)));
    w_u32(0x80077518u, (sint32)r_u32(0x80077530u));
    w_u32(0x80077530u, ((uint32)((sint32)r_u32(0x80077530u)) + (uint32)(v7)));
  }
  v8 = ((sint32)((uint32)((sint32)((uint32)(2) * (uint32)(((uint32)((uint16)((sint16)r_u16(0x800775f0u))) + (uint32)((sint32)((uint32)(3) * (uint32)(r_u32(a1)))))))) + (uint32)(3)) & 0xFFFFFFFC);
  if ((v8 >= (sint32)r_u32(0x8007759cu)))
  {
    w_u32(0x800775e4u, sub_8002D98C(((sint32)((uint32)((sint32)((uint32)(2) * (uint32)(((uint32)((uint16)((sint16)r_u16(0x800775f0u))) + (uint32)((sint32)((uint32)(3) * (uint32)(r_u32(a1)))))))) + (uint32)(3)) & 0xFFFFFFFC)));
  }
  else
  {
    w_u32(0x8007759cu, ((uint32)((sint32)r_u32(0x8007759cu)) - (uint32)(v8)));
    w_u32(0x800775e4u, (sint32)r_u32(0x80077530u));
    w_u32(0x80077530u, ((uint32)((sint32)r_u32(0x80077530u)) + (uint32)(v8)));
  }
  v9 = (sint32)((uint32)(4) * (uint32)((uint16)((sint16)r_u16(0x80077410u))));
  if ((v9 >= (sint32)r_u32(0x8007759cu)))
  {
    w_u32(0x800773a4u, sub_8002D98C((sint32)((uint32)(4) * (uint32)((uint16)((sint16)r_u16(0x80077410u))))));
  }
  else
  {
    w_u32(0x8007759cu, ((uint32)((sint32)r_u32(0x8007759cu)) - (uint32)(v9)));
    w_u32(0x800773a4u, (sint32)r_u32(0x80077530u));
    w_u32(0x80077530u, ((uint32)((sint32)r_u32(0x80077530u)) + (uint32)(v9)));
  }
  if (((r_u32((a1 + (3) * 4u)) & 1) != 0))
  {
    v10 = (sint32)((uint32)(16) * (uint32)(r_u32((a1 + (10) * 4u))));
    if ((v10 >= (sint32)r_u32(0x8007759cu)))
    {
      w_u32(0x80077648u, sub_8002D98C((sint32)((uint32)(16) * (uint32)(r_u32((a1 + (10) * 4u))))));
    }
    else
    {
      w_u32(0x8007759cu, ((uint32)((sint32)r_u32(0x8007759cu)) - (uint32)(v10)));
      w_u32(0x80077648u, (sint32)r_u32(0x80077530u));
      w_u32(0x80077530u, ((uint32)((sint32)r_u32(0x80077530u)) + (uint32)(v10)));
    }
  }
  if (((uint32)((sint32)r_u32(0x8007759cu)) <= 0x210))
  {
    result = sub_8002D98C(528);
    w_u32(0x800773dcu, result);
  }
  else
  {
    w_u32(0x8007759cu, ((uint32)((sint32)r_u32(0x8007759cu)) - (uint32)(528)));
    w_u32(0x800773dcu, (sint32)r_u32(0x80077530u));
    result = (sint32)((uint32)((sint32)r_u32(0x80077530u)) + (uint32)(528));
    w_u32(0x80077530u, ((uint32)((sint32)r_u32(0x80077530u)) + (uint32)(528)));
  }
  w_u32(0x80077628u, 0);
  return result;
}


uint32 sub_80012758(uint32 a1)
{
    FUNCTION_MARKER(0x80012758u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80063B94 */
    /* TODO: Bind external adapter for sub_80063BD4 */
    /* TODO: Bind external adapter for sub_80063BA4 */
  sint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 result;
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
  v2 = 0;
  sub_80012294();
  do
    v3 = sub_80013794(a1);
  while (!ob_draft_unresolved_call(0x80063b94u, 1u, v3));
  v4 = sub_8001221C();
  if ((v4 == 1))
  {
    v6 = (sint32)((uint32)(552) * (uint32)(a1));
    w_u32((uint32)((sint32)((uint32)(v6) - (uint32)(2146919128))), 4);
    w_u32((uint32)((sint32)((uint32)(v6) - (uint32)(2146919124))), 1);
    return 4;
  }
  if (v4)
  {
    if ((v4 != 2))
    {
      if ((v4 == 3))
      {
        v2 = 1;
        v8 = (sint32)((uint32)(552) * (uint32)(a1));
        w_u32((uint32)((sint32)((uint32)(v8) - (uint32)(2146919128))), 3);
        w_u32((uint32)((sint32)((uint32)(v8) - (uint32)(2146919124))), 1);
      }
      sub_8001237C();
      do
        v9 = sub_80013794(a1);
      while (!ob_draft_unresolved_call(0x80063bd4u, 1u, v9));
      sub_800122EC();
      sub_80012294();
      do
        v10 = sub_80013794(a1);
      while (!ob_draft_unresolved_call(0x80063ba4u, 1u, v10));
      v11 = sub_8001221C();
      if ((v11 != 1))
      {
        if (!v11)
        {
          v14 = (sint32)((uint32)(16) * (uint32)(a1));
          if (!v2)
          {
            w_u32((uint32)((sint32)((uint32)((sint32)((uint32)(552) * (uint32)(a1))) - (uint32)(2146919128))), 0);
            v14 = (sint32)((uint32)(16) * (uint32)(a1));
          }
          return r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(8) * (uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((sint32)((uint32)(v14) + (uint32)(a1))))) + (uint32)(a1))))) - (uint32)(2146919128))));
        }
        if ((v11 == 2))
        {
          v12 = (sint32)((uint32)(16) * (uint32)(a1));
        }
        else
        {
          v12 = (sint32)((uint32)(16) * (uint32)(a1));
          if ((v11 != 3))
          {
            v13 = (sint32)((uint32)(17) * (uint32)(a1));
            LABEL_29:
            w_u32((uint32)((sint32)((uint32)((sint32)((uint32)(8) * (uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(v13))) + (uint32)(a1))))) - (uint32)(2146919128))), 4);

            v14 = (sint32)((uint32)(16) * (uint32)(a1));
            return r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(8) * (uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((sint32)((uint32)(v14) + (uint32)(a1))))) + (uint32)(a1))))) - (uint32)(2146919128))));
          }
        }
        v15 = (sint32)((uint32)(8) * (uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((sint32)((uint32)(v12) + (uint32)(a1))))) + (uint32)(a1))));
        w_u32((uint32)((sint32)((uint32)(v15) - (uint32)(2146919128))), v11);
        w_u32((uint32)((sint32)((uint32)(v15) - (uint32)(2146919124))), 1);
        v14 = (sint32)((uint32)(16) * (uint32)(a1));
        return r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(8) * (uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((sint32)((uint32)(v14) + (uint32)(a1))))) + (uint32)(a1))))) - (uint32)(2146919128))));
      }
      v13 = (sint32)((uint32)(17) * (uint32)(a1));
      goto LABEL_29;
    }
    v7 = (sint32)((uint32)(552) * (uint32)(a1));
    w_u32((uint32)((sint32)((uint32)(v7) - (uint32)(2146919128))), 2);
    w_u32((uint32)((sint32)((uint32)(v7) - (uint32)(2146919124))), 1);
    result = 2;
    if (!a1)
      return 5;
  }
  else
    if (sub_800129FC(a1))
  {
    w_u32((uint32)((sint32)((uint32)((sint32)((uint32)(552) * (uint32)(a1))) - (uint32)(2146919128))), 0);
    return 0;
  }
  else
  {
    w_u32((uint32)((sint32)((uint32)((sint32)((uint32)(552) * (uint32)(a1))) - (uint32)(2146919128))), 1);
    return 1;
  }
  return result;
}


uint32 sub_8004F758(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8004f758u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8004F9A0 */
    /* TODO: Recover missing meaningful carriers for sub_8004FA0C before binding the native call */
    /* TODO: Recover missing meaningful carriers for sub_8004F354 before binding the native call */
    uint32 local_objects = ob_draft_scratch_acquire(16u);
  uint32 v4;
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
  ;
  v4 = r_u32((uint32)(((uint32)(a1) + (uint32)(24))));
  v5 = (uint32)((sint32)r_u32(0x800770f4u));
  sub_800455DC(v4, a2);
  v6 = r_u32((uint32)(((uint32)(a1) + (uint32)(208))));
  w_u32((uint32)(((uint32)(a1) + (uint32)(156))), 2147483393);
  w_u32((uint32)(((uint32)(a1) + (uint32)(160))), 2147483393);
  w_u32((uint32)(((uint32)(a1) + (uint32)(152))), 2147483393);
  if (((v6 & 2) != 0))
    ob_draft_unresolved_call(0x8004f9a0u, 2u, a1, a2);
  if ((((sint32)r_u32((v4 + (40) * 4u)) & 0x10) == 0))
  {
    v7 = r_u32((uint32)(((uint32)(a1) + (uint32)(160))));
    v8 = ((uint32)(a2) + (uint32)(r_u32((uint32)(((uint32)(a1) + (uint32)(92))))));
    w_u32((uint32)(((uint32)(a1) + (uint32)(152))), (sint32)((uint32)(v8) - (uint32)(1)));
    if (((sint32)(v8) < (sint32)(v7)))
      v7 = v8;
    w_u32(((local_objects + 0u) + (0) * 4u), (sint32)((uint32)((sint32)r_u32((v4 + (30) * 4u))) + (uint32)(r_u32((uint32)(((uint32)(a1) + (uint32)(80)))))));
    w_u32(((local_objects + 0u) + (1) * 4u), (sint32)((uint32)((sint32)r_u32((v4 + (31) * 4u))) + (uint32)(r_u32((uint32)(((uint32)(a1) + (uint32)(84)))))));
    w_u32(((local_objects + 0u) + (2) * 4u), (sint32)((uint32)((sint32)r_u32((v4 + (32) * 4u))) + (uint32)(r_u32((uint32)(((uint32)(a1) + (uint32)(88)))))));
    ob_draft_unresolved_call(0x8004fa0cu, 4u, v5, ((uint32)(a1) + (uint32)(68)), (local_objects + 0u), (v4 + (33) * 4u));
    if (((r_u32((uint32)(((uint32)(a1) + (uint32)(208)))) & 2) != 0))
    {
      w_u32((v5 + (14) * 4u), (sint32)(0u - (uint32)(1)));
      w_u32((v5 + (15) * 4u), r_u32((uint32)(((uint32)(a1) + (uint32)(196)))));
      w_u32((v5 + (16) * 4u), r_u32((uint32)(((uint32)(a1) + (uint32)(200)))));
      w_u32((v5 + (17) * 4u), r_u32((uint32)(((uint32)(a1) + (uint32)(204)))));
      w_u32((v5 + (18) * 4u), r_u32((uint32)(((uint32)(a1) + (uint32)(192)))));
    }
    else
    {
      w_u32((v5 + (14) * 4u), 0);
    }
    if (((r_u32((uint32)(((uint32)(a1) + (uint32)(208)))) & 4) != 0))
      w_u32((v5 + (19) * 4u), (sint32)(0u - (uint32)(1)));
    else
      w_u32((v5 + (19) * 4u), 0);
    sub_80050550(v5);
    v9 = r_u32((v5 + (27) * 4u));
    if (((sint32)(v9) < (sint32)(v7)))
    {
      v10 = r_u32((v5 + (21) * 4u));
      if ((v10 == v9))
      {
        w_u32((uint32)(((uint32)(a1) + (uint32)(156))), v10);
        sub_8004F004(r_u32((v5 + (25) * 4u)), (uint32)(((uint32)(a1) + (uint32)(164))));
        w_u32((uint32)(((uint32)(a1) + (uint32)(172))), 1);
        w_u32((uint32)(((uint32)(a1) + (uint32)(176))), r_u32((v5 + (22) * 4u)));
        w_u32((uint32)(((uint32)(a1) + (uint32)(180))), r_u32((v5 + (23) * 4u)));
        w_u32((uint32)(((uint32)(a1) + (uint32)(184))), r_u32((v5 + (24) * 4u)));
        v11 = r_u32((v5 + (26) * 4u));
        w_u32((uint32)(((uint32)(a1) + (uint32)(144))), ((uint32)(a1) + (uint32)(212)));
        w_u32((uint32)(((uint32)(a1) + (uint32)(188))), v11);
        v12 = r_u32((v5 + (34) * 4u));
        v13 = r_u32((v5 + (35) * 4u));
        v14 = r_u32((v5 + (36) * 4u));
        w_u32((uint32)(((uint32)(a1) + (uint32)(212))), r_u32((v5 + (33) * 4u)));
        w_u32((uint32)(((uint32)(a1) + (uint32)(216))), v12);
        w_u32((uint32)(((uint32)(a1) + (uint32)(220))), v13);
        w_u32((uint32)(((uint32)(a1) + (uint32)(224))), v14);
        v15 = r_u32((v5 + (38) * 4u));
        w_u32((uint32)(((uint32)(a1) + (uint32)(228))), r_u32((v5 + (37) * 4u)));
        w_u32((uint32)(((uint32)(a1) + (uint32)(232))), v15);
        w_u32((uint32)(((uint32)(a1) + (uint32)(160))), 2147483393);
      }
      else
      {
        v16 = r_u32((v5 + (20) * 4u));
        w_u32((uint32)(((uint32)(a1) + (uint32)(156))), 2147483393);
        w_u32((uint32)(((uint32)(a1) + (uint32)(160))), v16);
      }
    }
  }
  { uint32 draft_return = ob_draft_unresolved_call(0x8004f354u, 1u, (uint32)(a1)); ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80016768(void)
{
    FUNCTION_MARKER(0x80016768u, "SLES_008.65");
    /* TODO: Recover missing meaningful carriers for sub_80020450 before binding the native call */
  sint32 v0;
  sint32 v1;
  sint32 v2;
  uint32 v3;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  uint32 v9;
  sint32 v10;
  sint32 v11;
  sint32 result;
  v0 = 0;
  v1 = 24;
  v2 = 0;
  v3 = r_u32((uint32)(((uint32)((0x80065f24u)) + (((sint8)r_u8(0x8006c231u) & 0xFC)) * 1u)));
  do
  {
    v4 = r_u8(((v3 += 1u) - 1u));
    v5 = (sint32)((sint32)r_u32(((0x80065f48u) + (v4) * 4u)));
    ++v0;
    ob_draft_unresolved_call(0x80020450u, 4u, v5, 1, 1, 14);
    ob_draft_unresolved_call(0x80020450u, 4u, v5, 0, 1, 14);
    ob_draft_unresolved_call(0x80020450u, 4u, v5, 1, 0, 14);
    ob_draft_unresolved_call(0x80020450u, 4u, v5, 0, 0, 14);
    v1 = ((uint32)(v1) + (uint32)(14));
    v2 = ((uint32)(v2) + (uint32)(14));
  }
  while ((v0 != 12));
  v6 = 0;
  v7 = 30;
  v8 = 0;
  v9 = r_u32((uint32)(((uint32)((0x80065f38u)) + (((sint8)r_u8(0x8006c231u) & 0xFC)) * 1u)));
  do
  {
    v10 = r_u8(((v9 += 1u) - 1u));
    v11 = (sint32)((sint32)r_u32(((0x80065f48u) + (v10) * 4u)));
    ++v6;
    ob_draft_unresolved_call(0x80020450u, 4u, v11, 1, 1, 14);
    ob_draft_unresolved_call(0x80020450u, 4u, v11, 0, 1, 14);
    ob_draft_unresolved_call(0x80020450u, 4u, v11, 1, 0, 14);
    ob_draft_unresolved_call(0x80020450u, 4u, v11, 0, 0, 14);
    v7 = ((uint32)(v7) + (uint32)(14));
    result = 7;
    v8 = ((uint32)(v8) + (uint32)(14));
  }
  while ((v6 != 7));
  return result;
}


uint32 sub_80054EFC(uint32 a1)
{
    FUNCTION_MARKER(0x80054efcu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80063FB8 */
    /* TODO: Bind external adapter for sub_80063F68 */
    /* TODO: Bind external adapter for sub_80063F78 */
    /* TODO: Bind external adapter for sub_80057CD0 */
    /* TODO: Bind external adapter for sub_80063F98 */
    uint32 local_objects = ob_draft_scratch_acquire(52u);
  uint32 v1;
  uint32 v2;
  uint32 i;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 result;
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
  int64_t v19;
  ;
  uint32 file_info_available = 0u;
  ;
  ;
  v1 = a1;
  v2 = 0;
  if ((r_u8(a1) == 95))
    v1 = ((uint32)(a1) + (uint32)(1));
  for (i = v1;; ((i += 1u)))
  {
    v4 = (sint32)(0u - (uint32)(1));
    if ((v2 >= ob_draft_unresolved_call(0x80063fb8u, 1u, v1)))
      break;
    v5 = (uint8)(r_u8(i));
    ++v2;
    if (((uint32)((sint32)((uint32)(v5) - (uint32)(97))) < 0x1A))
      w_u8(i, (sint32)((uint32)(v5) - (uint32)(32)));
  }

  v6 = 0;
  v7 = 0;
  while (((r_u32((uint32)((sint32)((uint32)(v7) - (uint32)(2146920184)))) & 1) != 0))
  {
    ++v6;
    v7 = ((uint32)(v7) + (uint32)(16));
    if (((sint32)(v6) >= (sint32)(3)))
      goto LABEL_11;
  }

  v4 = v6;
  LABEL_11:
  result = (sint32)(0u - (uint32)(1));

  if ((v4 != (sint32)(0u - (uint32)(1))))
  {
    if ((r_u8(v1) == 92))
      w_u8(local_objects + 24u, 0u);
    else
      w_u16(((local_objects + 24u) + (0) * 2u), (sint16)r_u16(0x800771f0u));
    ob_draft_unresolved_call(0x80063f68u, 2u, (local_objects + 24u), v1);
    ob_draft_unresolved_call(0x80063f68u, 2u, (local_objects + 24u), (0x800771f4u));
    w_u32(local_objects + 48u, (sint32)(0u - (uint32)(1)));
    v10 = 0;
    v11 = (sint32)(0u - (uint32)(2146960104));
    v12 = 0;
    while (1)
    {
      v13 = ob_draft_unresolved_call(0x80063f78u, 2u, v11, (local_objects + 24u));
      v11 = ((uint32)(v11) + (uint32)(24));
      if (!v13)
        break;
      ++v10;
      v12 = ((uint32)(v12) + (uint32)(24));
      if (((sint32)(v10) >= (sint32)(10)))
        goto LABEL_22;
    }

    w_u32(local_objects + 48u, r_u32((uint32)((sint32)((uint32)(v12) - (uint32)(2146960084)))));
    LABEL_22:
    if (((sint32)r_u32(local_objects + 48u) != (sint32)(0u - (uint32)(1))))
      goto LABEL_28;

    v9 = 0;
    v14 = 0;
    while (1)
    {
      ++v14;
      if (ob_draft_unresolved_call(0x80057cd0u, 2u, (local_objects + 0u), (local_objects + 24u)))
        break;
      if (((sint32)(v14) >= (sint32)(1000)))
        goto LABEL_26;
    }

    v9 = 1;
    file_info_available = 1u;
    LABEL_26:
    result = (sint32)(0u - (uint32)(1));

    if (v9)
    {
      sub_80054D50((uint8)((sint8)r_u8(((local_objects + 0u) + (0) * 1u))), (uint8)((sint8)r_u8(((local_objects + 0u) + (1) * 1u))), (uint8)((sint8)r_u8(((local_objects + 0u) + (2) * 1u))), (local_objects + 48u));
      LABEL_28:
      v15 = (sint32)((uint32)(24) * (uint32)((sint32)r_u32(0x8007740cu)));

      w_u32((uint32)((sint32)((uint32)((sint32)((uint32)(16) * (uint32)(v4))) - (uint32)(2146920184))), ((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(16) * (uint32)(v4))) - (uint32)(2146920184))))) | (uint32)(1u)));
      /* CdSearchFile writes the size field beside its four-byte position output */
      /* TODO Recover cached-file size when the original local CDFILE output was not filled */
      v16 = file_info_available ? (sint32)r_u32(local_objects + 4u) : (sint32)ob_native_missing_value(0x80054EFCu, "Cached CDFILE size");
      v17 = (sint32)r_u32(local_objects + 48u);
      w_u32((uint32)((sint32)((uint32)((sint32)((uint32)(16) * (uint32)(v4))) - (uint32)(2146920180))), 0);
      w_u32((uint32)((sint32)((uint32)((sint32)((uint32)(16) * (uint32)(v4))) - (uint32)(2146920176))), v17);
      w_u32((uint32)((sint32)((uint32)((sint32)((uint32)(16) * (uint32)(v4))) - (uint32)(2146920172))), v16);
      ob_draft_unresolved_call(0x80063f98u, 2u, (sint32)((uint32)(v15) - (uint32)(2146960104)), (local_objects + 24u));
      v18 = (sint32)((uint32)((sint32)r_u32(0x8007740cu)) + (uint32)(1));
      v19 = (int64_t)(((uint64_t)(1717986919LL) * (uint64_t)((sint32)((uint32)((sint32)r_u32(0x8007740cu)) + (uint32)(1)))));
      result = v4;
      w_u32((uint32)((sint32)((uint32)((sint32)((uint32)(24) * (uint32)((sint32)r_u32(0x8007740cu)))) - (uint32)(2146960084))), (sint32)r_u32(local_objects + 48u));
      w_u32(0x8007740cu, (sint32)((uint32)(v18) - (uint32)((sint32)((uint32)(10) * (uint32)(((uint32)((((sint32)((uint64_t)v19 >> 32)) >> 2)) - (uint32)(((sint32)(v18) >> 31))))))));
    }
  }
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80048D2C(uint32 a1)
{
    FUNCTION_MARKER(0x80048d2cu, "SLES_008.65");
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    uint32 local_objects = ob_draft_scratch_acquire(8u);
  sint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  ;
  sint32 v10;
  sint32 v11;
  ;
  sint32 result;
  sint32 v14;
  sint32 v15;
  sint32 v16;
  sint32 v17;
  sint32 v18;
  sint32 v19;
  sint32 v20;
  sint32 v21;
  sint32 v22;
  v2 = r_u32((a1 + (21) * 4u));
  v3 = r_u32((a1 + (6) * 4u));
  w_u32((a1 + (27) * 4u), 2147483393);
  v4 = (sint32)((uint32)(v2) + (uint32)(v3));
  v14 = v4;
  v15 = ((uint32)(r_u32((a1 + (22) * 4u))) + (uint32)(r_u32((a1 + (7) * 4u))));
  v16 = ((uint32)(r_u32((a1 + (23) * 4u))) + (uint32)(r_u32((a1 + (8) * 4u))));
  v5 = r_u32((a1 + (24) * 4u));
  v6 = (sint32)(0u - (uint32)(1));
  if (v5)
  {
    v6 = 0;
    if (((sint32)(v4) < (sint32)(0)))
    {
      if (((v5 == (sint32)(0u - (uint32)(1))) && ((sint32)(0u - (uint32)(v4)) == 0x80000000)))
        ob_draft_unresolved_call(0x80048d2cu, 2u, 6u, 0);
      v6 = ((sint32)((sint32)(0u - (uint32)(v4))) / (sint32)(v5));
    }
  }
  v7 = r_u32((a1 + (25) * 4u));
  v8 = (sint32)(0u - (uint32)(1));
  if (v7)
  {
    v8 = 0;
    if (((sint32)(v15) < (sint32)(0)))
    {
      w_u32(local_objects + 0u, (sint32)(0u - (uint32)(v15)));
      if (((v7 == (sint32)(0u - (uint32)(1))) && ((sint32)r_u32(local_objects + 0u) == 0x80000000)))
        ob_draft_unresolved_call(0x80048d2cu, 2u, 6u, 0);
      v8 = ((sint32)((sint32)r_u32(local_objects + 0u)) / (sint32)(v7));
    }
  }
  v10 = r_u32((a1 + (26) * 4u));
  v11 = (sint32)(0u - (uint32)(1));
  if (v10)
  {
    v11 = 0;
    if (((sint32)(v16) < (sint32)(0)))
    {
      w_u32(local_objects + 4u, (sint32)(0u - (uint32)(v16)));
      if (((v10 == (sint32)(0u - (uint32)(1))) && ((sint32)r_u32(local_objects + 4u) == 0x80000000)))
        ob_draft_unresolved_call(0x80048d2cu, 2u, 6u, 0);
      v11 = ((sint32)((sint32)r_u32(local_objects + 4u)) / (sint32)(v10));
    }
  }
  if (((sint32)(v6) >= (sint32)(v8)))
  {
    if (((sint32)(v6) >= (sint32)(v11)))
    {
      v19 = (sint32)((uint32)(v15) + (uint32)((sint32)((uint32)(v6) * (uint32)(r_u32((a1 + (25) * 4u))))));
      result = ((sint32)((sint32)((uint32)(2) * (uint32)(r_u32((a1 + (7) * 4u))))) < (sint32)(v19));
      if (((sint32)((sint32)((uint32)(2) * (uint32)(r_u32((a1 + (7) * 4u))))) >= (sint32)(v19)))
      {
        v21 = (sint32)((uint32)(v16) + (uint32)((sint32)((uint32)(v6) * (uint32)(r_u32((a1 + (26) * 4u))))));
        result = ((sint32)((sint32)((uint32)(2) * (uint32)(r_u32((a1 + (8) * 4u))))) < (sint32)(v21));
        if (((sint32)((sint32)((uint32)(2) * (uint32)(r_u32((a1 + (8) * 4u))))) >= (sint32)(v21)))
        {
          result = ((uint32)(r_u32(a1)) + (uint32)(v6));
          LABEL_31:
          w_u32((a1 + (27) * 4u), result);

          { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
        }
      }
      { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
    }
    LABEL_28:
    v18 = (sint32)((uint32)(v14) + (uint32)((sint32)((uint32)(v11) * (uint32)(r_u32((a1 + (24) * 4u))))));

    result = ((sint32)((sint32)((uint32)(2) * (uint32)(r_u32((a1 + (6) * 4u))))) < (sint32)(v18));
    if (((sint32)((sint32)((uint32)(2) * (uint32)(r_u32((a1 + (6) * 4u))))) >= (sint32)(v18)))
    {
      v20 = (sint32)((uint32)(v15) + (uint32)((sint32)((uint32)(v11) * (uint32)(r_u32((a1 + (25) * 4u))))));
      result = ((sint32)((sint32)((uint32)(2) * (uint32)(r_u32((a1 + (7) * 4u))))) < (sint32)(v20));
      if (((sint32)((sint32)((uint32)(2) * (uint32)(r_u32((a1 + (7) * 4u))))) >= (sint32)(v20)))
      {
        result = ((uint32)(r_u32(a1)) + (uint32)(v11));
        goto LABEL_31;
      }
    }
    { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
  }
  if (((sint32)(v8) < (sint32)(v11)))
    goto LABEL_28;
  v17 = (sint32)((uint32)(v14) + (uint32)((sint32)((uint32)(v8) * (uint32)(r_u32((a1 + (24) * 4u))))));
  result = ((sint32)((sint32)((uint32)(2) * (uint32)(r_u32((a1 + (6) * 4u))))) < (sint32)(v17));
  if (((sint32)((sint32)((uint32)(2) * (uint32)(r_u32((a1 + (6) * 4u))))) >= (sint32)(v17)))
  {
    v22 = (sint32)((uint32)(v16) + (uint32)((sint32)((uint32)(v8) * (uint32)(r_u32((a1 + (26) * 4u))))));
    result = ((sint32)((sint32)((uint32)(2) * (uint32)(r_u32((a1 + (8) * 4u))))) < (sint32)(v22));
    if (((sint32)((sint32)((uint32)(2) * (uint32)(r_u32((a1 + (8) * 4u))))) >= (sint32)(v22)))
    {
      result = ((uint32)(r_u32(a1)) + (uint32)(v8));
      goto LABEL_31;
    }
  }
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_800461E8(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    FUNCTION_MARKER(0x800461e8u, "SLES_008.65");
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
  sint32 v18;
  sint32 v19;
  sint32 v20;
  sint32 v21;
  sint32 v22;
  sub_80043600(a1, a2, r_u32(a3));
  w_u32(a1, (0x80077128u));
  v7 = sub_800460B0();
  w_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(v7))) + (uint32)((sint32)r_u32(0x80077140u)))), a1);
  v8 = r_u32((a1 + (3) * 4u));
  w_u32((a1 + (6) * 4u), v7);
  v9 = (uint32)(sub_80043824(v8, (sint32)((0x8007711cu)), r_u32((a3 + (1) * 4u))));
  w_u32((a1 + (8) * 4u), v9);
  w_u32((a1 + (7) * 4u), 0);
  w_u32((a1 + (19) * 4u), ((uint32)(r_u32((a3 + (2) * 4u))) << (uint32)(8)));
  w_u32((a1 + (20) * 4u), ((uint32)(r_u32((a3 + (3) * 4u))) << (uint32)(8)));
  w_u32((a1 + (21) * 4u), ((uint32)(r_u32((a3 + (4) * 4u))) << (uint32)(8)));
  w_u32((a1 + (22) * 4u), ((uint32)(r_u32((a3 + (5) * 4u))) << (uint32)(8)));
  w_u32((a1 + (23) * 4u), ((uint32)(r_u32((a3 + (6) * 4u))) << (uint32)(8)));
  w_u32((a1 + (24) * 4u), ((uint32)(r_u32((a3 + (7) * 4u))) << (uint32)(8)));
  w_u32((a1 + (34) * 4u), r_u32((a3 + (9) * 4u)));
  w_u32((a1 + (35) * 4u), r_u32((a3 + (10) * 4u)));
  w_u32((a1 + (36) * 4u), r_u32((a3 + (11) * 4u)));
  w_u32((a1 + (41) * 4u), r_u32((a3 + (16) * 4u)));
  w_u32((a1 + (42) * 4u), r_u32((a3 + (17) * 4u)));
  w_u32((a1 + (40) * 4u), r_u32((a3 + (15) * 4u)));
  w_u32((a1 + (37) * 4u), r_u32((a3 + (12) * 4u)));
  w_u32((a1 + (39) * 4u), r_u32((a3 + (14) * 4u)));
  w_u32((a1 + (38) * 4u), r_u32((a3 + (13) * 4u)));
  v10 = r_u32((a3 + (16) * 4u));
  w_u32((a1 + (43) * 4u), v10);
  v11 = (v10 | r_u32((a3 + (17) * 4u)));
  w_u32((a1 + (43) * 4u), v11);
  v12 = (v11 | r_u32((a3 + (15) * 4u)));
  w_u32((a1 + (43) * 4u), v12);
  v13 = (v12 | r_u32((a3 + (12) * 4u)));
  w_u32((a1 + (43) * 4u), v13);
  v14 = (v13 | r_u32((a3 + (14) * 4u)));
  w_u32((a1 + (43) * 4u), v14);
  w_u32((a1 + (43) * 4u), (v14 | r_u32((a3 + (13) * 4u))));
  w_u32((a1 + (61) * 4u), r_u32((a3 + (18) * 4u)));
  w_u32((a1 + (62) * 4u), r_u32((a3 + (19) * 4u)));
  w_u32((a1 + (63) * 4u), r_u32((a3 + (20) * 4u)));
  w_u32((a1 + (44) * 4u), r_u32((a3 + (8) * 4u)));
  v15 = r_u32((v9 + (33) * 4u));
  if (((sint32)(v15) < (sint32)(0)))
    v15 = (sint32)(0u - (uint32)(v15));
  w_u32((a1 + (25) * 4u), v15);
  v16 = r_u32((v9 + (34) * 4u));
  if (((sint32)(v16) < (sint32)(0)))
    v16 = (sint32)(0u - (uint32)(v16));
  w_u32((a1 + (26) * 4u), v16);
  v17 = r_u32((v9 + (35) * 4u));
  w_u32((a1 + (28) * 4u), r_u32((a1 + (25) * 4u)));
  v18 = r_u32((a1 + (26) * 4u));
  if (((sint32)(v17) < (sint32)(0)))
    v17 = (sint32)(0u - (uint32)(v17));
  w_u32((a1 + (27) * 4u), v17);
  v19 = r_u32((a1 + (27) * 4u));
  w_u32((a1 + (31) * 4u), ((uint32)(a4) + (uint32)(10000)));
  w_u32((a1 + (32) * 4u), ((uint32)(a4) + (uint32)(10000)));
  w_u32((a1 + (33) * 4u), ((uint32)(a4) + (uint32)(10000)));
  w_u32((a1 + (29) * 4u), v18);
  w_u32((a1 + (30) * 4u), v19);
  sub_80043BAC(((uint32)(a1) + (uint32)(51)), (sint32)(a1));
  v20 = r_u32((a1 + (54) * 4u));
  w_u32((a1 + (57) * 4u), 2);
  w_u32((a1 + (60) * 4u), 0x80047b54u);
  w_u32((a1 + (59) * 4u), 0);
  w_u32((a1 + (65) * 4u), 2147483393);
  w_u32((a1 + (66) * 4u), 0);
  w_u32((a1 + (45) * 4u), 0);
  w_u32((a1 + (46) * 4u), 0);
  w_u32((a1 + (54) * 4u), (sint32)((uint32)(v20) + (uint32)(1)));
  sub_80046914(a1, a4);
  sub_80043BAC(((uint32)(a1) + (uint32)(9)), (sint32)(a1));
  v21 = r_u32((a1 + (8) * 4u));
  v22 = r_u32((a1 + (12) * 4u));
  w_u32((a1 + (18) * 4u), 0x8004670cu);
  w_u32((a1 + (12) * 4u), (sint32)((uint32)(v22) + (uint32)(1)));
  sub_800451E4(v21, ((uint32)(a1) + (uint32)(9)));
  return a1;
}


uint32 sub_80048124(uint32 a1)
{
    FUNCTION_MARKER(0x80048124u, "SLES_008.65");
    /* TODO: Recover missing meaningful carriers for sub_80048FEC before binding the native call */
    uint32 local_objects = ob_draft_scratch_acquire(4u);
  uint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 result;
  sint32 v6;
  ;
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
  v2 = (uint32)(r_u32((a1 + (5) * 4u)));
  v3 = ob_draft_unresolved_call(0x80048fecu, 0u);
  if ((v3 != 0x7FFFFFFF))
  {
    v4 = (sint32)r_u32(v2);
    w_u32((v2 + (1) * 4u), v3);
    result = (v4 & 0xFFFF7FFF);
    w_u32(v2, result);
    { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
  }
  w_u32(v2, ((uint32)((sint32)r_u32(v2)) | (uint32)(0x8000u)));
  if (((!r_u32((a1 + (15) * 4u)) && !r_u32((a1 + (16) * 4u))) && !r_u32((a1 + (17) * 4u))))
  {
    v6 = r_u32((a1 + (19) * 4u));
    w_u32(local_objects + 0u, r_u32((a1 + (20) * 4u)));
    if (((sint32)(v6) < (sint32)((sint32)r_u32(local_objects + 0u))))
      v6 = r_u32((a1 + (20) * 4u));
    v8 = r_u32((a1 + (18) * 4u));
    if (((sint32)(v8) < (sint32)(v6)))
      v8 = v6;
    if (v8)
    {
      LABEL_45:
      result = 2147483393;

      goto LABEL_46;
    }
    if (r_u32((a1 + (18) * 4u)))
    {
      v9 = r_u32((a1 + (19) * 4u));
    }
    else
    {
      v9 = r_u32((a1 + (19) * 4u));
      if ((((sint32)(v9) < (sint32)(0)) && ((sint32)((sint32)r_u32(local_objects + 0u)) < (sint32)(0))))
      {
        result = r_u32(a1);
        w_u32((v2 + (1) * 4u), r_u32(a1));
        { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
      }
    }
    if (!v9)
    {
      v10 = r_u32((a1 + (20) * 4u));
      if (((sint32)(v10) >= (sint32)(0)))
      {
        LABEL_21:
        if (((!v10 && (r_u32((a1 + (18) * 4u)) < 0)) && (r_u32((a1 + (19) * 4u)) < 0)))
        {
          result = r_u32(a1);
          w_u32((v2 + (1) * 4u), r_u32(a1));
          { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
        }

        goto LABEL_45;
      }
      if ((r_u32((a1 + (18) * 4u)) < 0))
      {
        result = r_u32(a1);
        w_u32((v2 + (1) * 4u), r_u32(a1));
        { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
      }
    }
    v10 = r_u32((a1 + (20) * 4u));
    goto LABEL_21;
  }
  sub_80048B60(a1);
  if (((((((!r_u32((a1 + (24) * 4u)) && (r_u32((a1 + (18) * 4u)) > 0)) || (!r_u32((a1 + (25) * 4u)) && (r_u32((a1 + (19) * 4u)) > 0))) || (!r_u32((a1 + (26) * 4u)) && (r_u32((a1 + (20) * 4u)) > 0))) || (r_u32((a1 + (6) * 4u)) < r_u32((a1 + (21) * 4u)))) || (r_u32((a1 + (7) * 4u)) < r_u32((a1 + (22) * 4u)))) || (r_u32((a1 + (8) * 4u)) < r_u32((a1 + (23) * 4u)))))
  {
    goto LABEL_45;
  }
  sub_80048D2C(a1);
  v11 = r_u32((a1 + (27) * 4u));
  w_u32((v2 + (1) * 4u), v11);
  v12 = r_u32((a1 + (27) * 4u));
  result = ((sint32)(v12) > (sint32)(2147483392));
  if (((sint32)(v12) > (sint32)(2147483392)))
    { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
  v13 = 0;
  if (!r_u32((a1 + (24) * 4u)))
    v13 = (r_u32((a1 + (18) * 4u)) == 0);
  v14 = 0;
  if (!r_u32((a1 + (25) * 4u)))
    v14 = (r_u32((a1 + (19) * 4u)) == 0);
  v15 = 0;
  v16 = (sint32)((uint32)(v13) + (uint32)(v14));
  if (!r_u32((a1 + (26) * 4u)))
    v15 = (r_u32((a1 + (20) * 4u)) == 0);
  v17 = (sint32)((uint32)(v16) + (uint32)(v15));
  if (!v17)
  {
    result = ((sint32)r_u32(v2) | 0x10000);
    w_u32(v2, result);
    { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
  }
  if ((v17 != 1))
    goto LABEL_45;
  result = (sint32)((uint32)(v11) + (uint32)(1));
  LABEL_46:
  w_u32((v2 + (1) * 4u), result);

  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


void sub_8004A5C4(void)
{
    FUNCTION_MARKER(0x8004a5c4u, "SLES_008.65");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    uint32 local_objects = ob_draft_scratch_acquire(12u);
  sint32 i;
  sint16 v1;
  uint32 v2;
  uint32 v3;
  uint32 v4;
  sint32 v5;
  ;
  sint32 v7;
  sint8 v8;
  ;
  sint32 v10;
  sint32 v11;
  sint32 v12;
  sint32 v13;
  sint32 v14;
  sint32 v15;
  sint32 v16;
  ;
  sint32 v18;
  sint32 v19;
  sint32 v20;
  sint32 v21;
  sint32 v22;
  sint16 v23;
  for (i = (sint32)r_u32(0x80077490u); i; i = r_u32((uint32)((sint32)((uint32)(i) + (uint32)(28)))))
  {
    v1 = r_u16((uint32)((sint32)((uint32)(i) + (uint32)(38))));
    w_u16((uint32)((sint32)((uint32)(i) + (uint32)(38))), (v1 & 0xFC2F));
    if (((r_u32((uint32)((sint32)((uint32)(i) + (uint32)(36)))) & 0x90000) != 0x10000))
    {
      if (((v1 & 8) != 0))
        w_u16((uint32)((sint32)((uint32)(i) + (uint32)(38))), ((v1 & 0xFC26) | 1));
      v2 = r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(i) + (uint32)(24))))) + (uint32)(40))));
      if (((r_u32(v2) & 3) != 0))
        sub_800257CC((sint32)(v2));
      else
        (w_u16((uint32)(((uint32)(r_u32(v2)) - (uint32)(6))), (r_u16((uint32)(((uint32)(r_u32(v2)) - (uint32)(6)))) + 1u)), r_u16((uint32)(((uint32)(r_u32(v2)) - (uint32)(6)))));
      v3 = (uint32)(sub_80045464(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(i) + (uint32)(24))))) + (uint32)(52)))), (sint32)r_u32(0x800775fcu)));
      v4 = v3;
      if ((((r_u16((uint32)((sint32)((uint32)(i) + (uint32)(38)))) & 4) != 0) && (sint32)r_u32(0x800774f4u)))
      {
        v16 = r_u32((uint32)((sint32)((uint32)(i) + (uint32)(40))));
        w_u32(local_objects + 8u, (sint32)r_u32(v3));
        if (((sint32)r_u32(v3) >= ((uint32)(r_u32((uint32)((sint32)r_u32(0x800774f4u)))) - (uint32)(((sint32)(v16) / (sint32)(2))))))
        {
          if ((((uint32)(r_u32((uint32)((sint32)r_u32(0x800774f4u)))) + (uint32)(((sint32)(v16) / (sint32)(2)))) < (sint32)r_u32(local_objects + 8u)))
            w_u32(local_objects + 8u, ((uint32)((sint32)r_u32(local_objects + 8u)) - (uint32)(v16)));
        }
        else
        {
          w_u32(local_objects + 8u, ((uint32)((sint32)r_u32(local_objects + 8u)) + (uint32)(v16)));
        }
        v18 = ((sint32)((uint32)((sint32)r_u32(local_objects + 8u)) + (uint32)((sint32)r_u32(0x80077458u))) / r_u32((uint32)((sint32)r_u32(0x80077644u))));
        if (!(r_u32((uint32)((sint32)r_u32(0x80077644u)))))
          ob_draft_unresolved_call(0x8004a5c4u, 2u, 7u, 0);
        if (((r_u32((uint32)((sint32)r_u32(0x80077644u))) == (sint32)(0u - (uint32)(1))) && ((sint32)((uint32)((sint32)r_u32(local_objects + 8u)) + (uint32)((sint32)r_u32(0x80077458u))) == 0x80000000)))
          ob_draft_unresolved_call(0x8004a5c4u, 2u, 6u, 0);
        v19 = (sint32)r_u32((v3 + (2) * 4u));
        v20 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800774f4u)) + (uint32)(8))));
        v21 = v18;
        if (((sint32)(v19) >= (sint32)((sint32)((uint32)(v20) - (uint32)(((sint32)(v16) / (sint32)(2)))))))
        {
          if (((sint32)((sint32)((uint32)(v20) + (uint32)(((sint32)(v16) / (sint32)(2))))) < (sint32)(v19)))
            v19 = ((uint32)(v19) - (uint32)(v16));
        }
        else
        {
          v19 = ((uint32)(v19) + (uint32)(v16));
        }
        if (!(r_u32((uint32)((sint32)r_u32(0x80077644u)))))
          ob_draft_unresolved_call(0x8004a5c4u, 2u, 7u, 0);
        if (((r_u32((uint32)((sint32)r_u32(0x80077644u))) == (sint32)(0u - (uint32)(1))) && ((sint32)((uint32)((sint32)r_u32(0x80077468u)) - (uint32)(v19)) == 0x80000000)))
          ob_draft_unresolved_call(0x8004a5c4u, 2u, 6u, 0);
        v22 = (sint32)((uint32)(((sint32)((sint32)((uint32)(((sint32)((uint32)((sint32)r_u32(0x80077468u)) - (uint32)(v19)) / r_u32((uint32)((sint32)r_u32(0x80077644u))))) << (uint32)(16))) >> 20)) * (uint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x80077644u)) + (uint32)(4))))));
        v23 = r_u16((uint32)((sint32)((uint32)(i) + (uint32)(38))));
        w_u8((uint32)((sint32)((uint32)(i) + (uint32)(37))), (sint32)((uint32)((v21 & 0xF)) + (uint32)((sint32)((uint32)(16) * (uint32)((((sint32)((uint32)((sint32)r_u32(0x80077468u)) - (uint32)(v19)) / r_u32((uint32)((sint32)r_u32(0x80077644u)))) & 0xF))))));
        w_u16((uint32)((sint32)((uint32)(i) + (uint32)(38))), (v23 | 0x40));
        w_u8((uint32)((sint32)((uint32)(i) + (uint32)(36))), (sint32)((uint32)(((sint32)((sint32)((uint32)(v21) << (uint32)(16))) >> 20)) + (uint32)(v22)));
      }
      else
      {
        v5 = r_u32((uint32)((sint32)r_u32(0x80077644u)));
        w_u32(local_objects + 0u, (sint32)((uint32)((sint32)r_u32(0x80077468u)) - (uint32)((sint32)r_u32((v3 + (2) * 4u)))));
        v7 = ((sint32)r_u32(local_objects + 0u) / r_u32((uint32)((sint32)r_u32(0x80077644u))));
        if (!(r_u32((uint32)((sint32)r_u32(0x80077644u)))))
          ob_draft_unresolved_call(0x8004a5c4u, 2u, 7u, 0);
        if (((v5 == (sint32)(0u - (uint32)(1))) && ((sint32)r_u32(local_objects + 0u) == 0x80000000)))
          ob_draft_unresolved_call(0x8004a5c4u, 2u, 6u, 0);
        v8 = ((sint32)r_u32(local_objects + 0u) / r_u32((uint32)((sint32)r_u32(0x80077644u))));
        w_u32(local_objects + 4u, (sint32)((uint32)((sint32)r_u32(v3)) + (uint32)((sint32)r_u32(0x80077458u))));
        if (((v5 == (sint32)(0u - (uint32)(1))) && ((sint32)r_u32(local_objects + 4u) == 0x80000000)))
          ob_draft_unresolved_call(0x8004a5c4u, 2u, 6u, 0);
        v10 = ((sint32)((sint32)r_u32(local_objects + 4u)) / (sint32)(v5));
        v11 = (sint32)((uint32)(((sint32)((sint32)((uint32)(v7) << (uint32)(16))) >> 20)) * (uint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x80077644u)) + (uint32)(4))))));
        v12 = (v8 & 0xF);
        v13 = (v10 & 0xF);
        w_u8((uint32)((sint32)((uint32)(i) + (uint32)(37))), ((v10 & 0xF) | (sint32)((uint32)(16) * (uint32)(v12))));
        v14 = (r_u16((uint32)((sint32)((uint32)(i) + (uint32)(38)))) & 2);
        w_u8((uint32)((sint32)((uint32)(i) + (uint32)(36))), (sint32)((uint32)(((sint32)((sint32)((uint32)(v10) << (uint32)(16))) >> 20)) + (uint32)(v11)));
        if (!v14)
        {
          v15 = (v10 & 0xF);
          if ((((!v13 || !v12) || (v15 == 15)) || (v12 == 15)))
            sub_8004AAFC(i, v4);
        }
      }
      sub_800257A0(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(i) + (uint32)(24))))) + (uint32)(40)))));
    }
  }

    ob_draft_scratch_release(local_objects); 
}


uint32 sub_8001E7B0(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a9, uint32 a10)
{
    FUNCTION_MARKER(0x8001E7B0u, "SLES_008.65");
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
    w_u32(sound + 4u, 1u);
    w_u8(sound + 23u, a3);
    w_u8(sound + 24u, a4);
    w_u32(sound + 8u, a10);
    w_u32(sound, frequency);
    w_u32(sound + 12u, a9);
    /* Original signed multiply-high correction computes unsigned byte volume / 255 */
    w_u8(sound + 22u, volume_product / 255u);
    sint32 voice = (sint32)sub_800202E8();
    if (voice == -1) return (uint32)(8u * (uint32)voice);
    uint32 voice_state = 0x800782A0u + 28u * (uint32)voice;
    sint32 product = (sint32)((uint32)a9 * frequency);
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
    else if (mode == 4u && (a10 & 4u) != 0u)
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
    return ob_draft_unresolved_call(0x8001FDA4u, 1u, (uint32)slot);
}



uint32 sub_80047450(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    FUNCTION_MARKER(0x80047450u, "SLES_008.65");
    /* TODO: Recover missing meaningful carriers for sub_80047A60 before binding the native call */
    uint32 local_objects = ob_draft_scratch_acquire(4u);
  ;
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
  w_u32(local_objects + 0u, r_u32((uint32)(((uint32)(a2) + (uint32)(24)))));
  v6 = r_u32(a3);
  if (((a4 & 0x80) != 0))
  {
    if (((r_u32(a3) & 0x80) == 0))
    {
      v7 = r_u32((a3 + (1) * 4u));
      if (((v6 & 0x8000) != 0))
      {
        (w_u32((a1 + (45) * 4u), (r_u32((a1 + (45) * 4u)) + 1u)), r_u32((a1 + (45) * 4u)));
        (w_u32((uint32)(((uint32)(a2) + (uint32)(184))), (r_u32((uint32)(((uint32)(a2) + (uint32)(184)))) + 1u)), r_u32((uint32)(((uint32)(a2) + (uint32)(184)))));
        v8 = r_u32((a1 + (47) * 4u));
        if ((((sint32)(v7) < (sint32)(v8)) || ((v7 == v8) && ((sint32)r_u32(local_objects + 0u) < r_u32((a1 + (48) * 4u))))))
        {
          w_u32((a1 + (47) * 4u), v7);
          w_u32((a1 + (48) * 4u), (sint32)r_u32(local_objects + 0u));
        }
      }
      else
      {
        v9 = r_u32((a1 + (49) * 4u));
        if ((((sint32)(v7) < (sint32)(v9)) || ((v7 == v9) && ((sint32)r_u32(local_objects + 0u) < r_u32((a1 + (50) * 4u))))))
        {
          w_u32((a1 + (49) * 4u), v7);
          w_u32((a1 + (50) * 4u), (sint32)r_u32(local_objects + 0u));
        }
      }
    }
    { uint32 draft_return = ob_draft_unresolved_call(0x80047a60u, 1u, a1); ob_draft_scratch_release(local_objects);  return draft_return; }
  }
  v10 = r_u32((a3 + (1) * 4u));
  if (((a4 & 0x8000) != 0))
  {
    if (((v6 & 0x80) != 0))
    {
      (w_u32((a1 + (45) * 4u), (r_u32((a1 + (45) * 4u)) - 1u)), r_u32((a1 + (45) * 4u)));
      (w_u32((uint32)(((uint32)(a2) + (uint32)(184))), (r_u32((uint32)(((uint32)(a2) + (uint32)(184)))) - 1u)), r_u32((uint32)(((uint32)(a2) + (uint32)(184)))));
      if ((r_u32((a1 + (48) * 4u)) == (sint32)r_u32(local_objects + 0u)))
        goto LABEL_21;
      goto LABEL_50;
    }
    if (((v6 & 0x8000) != 0))
    {
      v11 = r_u32((a1 + (48) * 4u));
      if ((v11 == (sint32)r_u32(local_objects + 0u)))
      {
        v12 = r_u32((a1 + (47) * 4u));
        if (((sint32)(v10) >= (sint32)(v12)))
        {
          if (((sint32)(v12) < (sint32)(v10)))
          {
            LABEL_21:
            w_u32((a1 + (47) * 4u), 0x7FFFFFFF);

            w_u32((a1 + (48) * 4u), (sint32)(0u - (uint32)(1)));
          }
        }
        else
        {
          w_u32((a1 + (47) * 4u), v10);
        }
        LABEL_50:
        v17 = r_u32((a1 + (50) * 4u));

        goto LABEL_51;
      }
      v13 = r_u32((a1 + (47) * 4u));
      if (((sint32)(v10) < (sint32)(v13)))
      {
        LABEL_40:
        w_u32((a1 + (47) * 4u), v10);

        w_u32((a1 + (48) * 4u), (sint32)r_u32(local_objects + 0u));
        goto LABEL_50;
      }
      v14 = ((sint32)((sint32)r_u32(local_objects + 0u)) < (sint32)(v11));
      if ((v10 != v13))
        goto LABEL_50;
      LABEL_39:
      if (!v14)
        goto LABEL_50;

      goto LABEL_40;
    }
    (w_u32((a1 + (45) * 4u), (r_u32((a1 + (45) * 4u)) - 1u)), r_u32((a1 + (45) * 4u)));
    (w_u32((uint32)(((uint32)(a2) + (uint32)(184))), (r_u32((uint32)(((uint32)(a2) + (uint32)(184)))) - 1u)), r_u32((uint32)(((uint32)(a2) + (uint32)(184)))));
    if ((r_u32((a1 + (48) * 4u)) == (sint32)r_u32(local_objects + 0u)))
    {
      w_u32((a1 + (47) * 4u), 0x7FFFFFFF);
      w_u32((a1 + (48) * 4u), (sint32)(0u - (uint32)(1)));
    }
    v15 = r_u32((a1 + (49) * 4u));
    if (((sint32)(v10) < (sint32)(v15)))
    {
      LABEL_49:
      w_u32((a1 + (49) * 4u), v10);

      w_u32((a1 + (50) * 4u), (sint32)r_u32(local_objects + 0u));
      goto LABEL_50;
    }
    if ((v10 != v15))
      goto LABEL_50;
    v16 = ((sint32)r_u32(local_objects + 0u) < r_u32((a1 + (50) * 4u)));
    LABEL_48:
    if (!v16)
      goto LABEL_50;

    goto LABEL_49;
  }
  if (((v6 & 0x80) == 0))
  {
    if (((v6 & 0x8000) != 0))
    {
      (w_u32((a1 + (45) * 4u), (r_u32((a1 + (45) * 4u)) + 1u)), r_u32((a1 + (45) * 4u)));
      (w_u32((uint32)(((uint32)(a2) + (uint32)(184))), (r_u32((uint32)(((uint32)(a2) + (uint32)(184)))) + 1u)), r_u32((uint32)(((uint32)(a2) + (uint32)(184)))));
      if ((r_u32((a1 + (50) * 4u)) == (sint32)r_u32(local_objects + 0u)))
      {
        w_u32((a1 + (49) * 4u), 0x7FFFFFFF);
        w_u32((a1 + (50) * 4u), (sint32)(0u - (uint32)(1)));
      }
      v18 = r_u32((a1 + (47) * 4u));
      if (((sint32)(v10) < (sint32)(v18)))
        goto LABEL_40;
      if ((v10 != v18))
        goto LABEL_50;
      v14 = ((sint32)r_u32(local_objects + 0u) < r_u32((a1 + (48) * 4u)));
      goto LABEL_39;
    }
    v19 = r_u32((a1 + (50) * 4u));
    if ((v19 != (sint32)r_u32(local_objects + 0u)))
    {
      v21 = r_u32((a1 + (49) * 4u));
      if (((sint32)(v10) < (sint32)(v21)))
        goto LABEL_49;
      v16 = ((sint32)((sint32)r_u32(local_objects + 0u)) < (sint32)(v19));
      if ((v10 != v21))
        goto LABEL_50;
      goto LABEL_48;
    }
    v20 = r_u32((a1 + (49) * 4u));
    if (((sint32)(v10) < (sint32)(v20)))
    {
      w_u32((a1 + (49) * 4u), v10);
      goto LABEL_50;
    }
    if (((sint32)(v20) >= (sint32)(v10)))
      goto LABEL_50;
    LABEL_45:
    w_u32((a1 + (49) * 4u), 0x7FFFFFFF);

    w_u32((a1 + (50) * 4u), (sint32)(0u - (uint32)(1)));
    goto LABEL_50;
  }
  v17 = r_u32((a1 + (50) * 4u));
  if ((v17 == (sint32)r_u32(local_objects + 0u)))
    goto LABEL_45;
  LABEL_51:
  if ((v17 == (sint32)(0u - (uint32)(1))))
    sub_8004795C(a1);

  if ((r_u32((a1 + (48) * 4u)) == (sint32)(0u - (uint32)(1))))
    sub_800479E0(a1);
  { uint32 draft_return = ob_draft_unresolved_call(0x80047a60u, 1u, a1); ob_draft_scratch_release(local_objects);  return draft_return; }
}


