#include "draft_signatures.h"
#include "native_runtime.h"
#include <stdint.h>

/* Unverified draft bodies */

sint32 sub_8002512C(uint32 a1)
{
    FUNCTION_MARKER(0x8002512cu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8002679C */
    /* TODO: Bind external adapter for sub_800268D0 */
    /* TODO: Bind external adapter for sub_80027DF8 */
    /* TODO: Bind external adapter for sub_800267C4 */
  uint32 v2;
  uint32 v3;
  uint32 i;
  uint32 v5;
  sint32 result;
  ob_draft_unresolved_call(0x8002679cu, 2u, a1, 1);
  v2 = ((uint32)(ob_draft_unresolved_call(0x800268d0u, 1u, a1)) >> 1);
  v3 = r_u32(a1);
  for (i = 0; (i < v2); ((v3 += 2u)))
  {
    v5 = (uint32)(ob_draft_unresolved_call(0x80027df8u, 1u, r_u16(v3)));
    if ((r_u32(v5) != 1))
      sub_800256CC(v5);
    ++i;
  }

  ob_draft_unresolved_call(0x800267c4u, 2u, a1, 1);
  sub_80026758(a1);
  result = 1;
  w_u32(a1, (uint32)(1));
  return result;
}


sint32 sub_80022234(sint32 a1)
{
    FUNCTION_MARKER(0x80022234u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8005C890 */
    uint32 local_objects = ob_draft_scratch_acquire(8u);
  sint16 v1;
  sint32 v2;
  ;
  switch (a1)
  {
    case 0:

    case 10:

    case 11:

    case 12:

    case 13:

    case 14:

    case 15:

    case 16:

    case 17:

    case 18:

    case 19:

    case 20:

    case 21:

    case 22:

    case 23:
      v1 = 214;
      if (!(sint32)r_u32(0x800773D0u))
      v1 = 470;
      goto LABEL_8;

    case 1:

    case 9:
      v1 = 203;
      if (!(sint32)r_u32(0x800773D0u))
      v1 = 459;
      goto LABEL_8;

    case 2:

    case 3:

    case 4:

    case 5:

    case 6:

    case 7:

    case 8:
      v1 = 192;
      if (!(sint32)r_u32(0x800773D0u))
      v1 = 448;
      LABEL_8:
    w_u16(((local_objects + 0u) + (1) * 2u), v1);

      break;

    default:
      break;

  }

  v2 = 96;
  w_u16(((local_objects + 0u) + (0) * 2u), 128);
  w_u16(((local_objects + 0u) + (2) * 2u), 20);
  w_u16(((local_objects + 0u) + (3) * 2u), 11);
  if ((sint32)r_u32(0x800773D0u))
    v2 = 352;
  { uint32 draft_return = ob_draft_unresolved_call(0x8005c890u, 3u, (local_objects + 0u), 176, v2); ob_draft_scratch_release(local_objects);  return draft_return; }
}


sint32 sub_80023B28(uint32 a1, sint32 a2)
{
    FUNCTION_MARKER(0x80023b28u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_800544EC */
    /* TODO: Bind external adapter for sub_80054320 */
    /* TODO: Bind external adapter for sub_8005C504 */
    /* TODO: Bind external adapter for sub_8002CFA8 */
    /* TODO: Bind external adapter for sub_80054440 */
  sint32 v4;
  sint32 result;
  v4 = 0;
  ob_draft_unresolved_call(0x800544ECu, 0u);
  if ((a2 > 0))
    w_u32(0x8008969C, a2);
  do
  {
    ob_draft_unresolved_call(0x80054320u, 0u);
    /* Deliver VSync and timer callbacks during the original frame wait */
    while (r_u32(0x80077620u))
      ob_native_pump();

    sub_80016B88(a1);
    ob_draft_unresolved_call(0x8005c504u, 1u, 0);
    w_u32(0x8007754Cu, (sint32)r_u32(0x8007737Cu));
    ob_draft_unresolved_call(0x8002cfa8u, 0u);
    w_u32(0x80077620u, 1);
    result = r_u32(0x8008969C);
    if ((r_u32(0x8008969C) || (a2 <= 0)))
    {
      result = ob_draft_unresolved_call(0x80054440u, 1u, 14);
      if (!result)
        continue;
    }
    v4 = 1;
  }
  while (!v4);
  return result;
}


sint32 sub_80034430(uint32 a1)
{
    FUNCTION_MARKER(0x80034430u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8005C504 */
    /* TODO: Bind external adapter for sub_8005C7C8 */
  sint32 v2;
  sint32 result;
  sint32 i;
  sint32 v5;
  uint32 v6;
  sint32 v7;
  sint32 v8;
  v2 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(16))));
  result = ((sint32)r_u32(0x800882BC) < v2);
  if ((r_u32(0x800882BC) >= (uint32)(v2)))
  {
    for (i = r_u8((uint32)((sint32)((uint32)(a1) + (uint32)(10)))); ((sint32)r_u32(0x800882BC) >= v2); ++i)
      v2 += r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(8))));

    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(16))), v2);
    v5 = r_u8((uint32)((sint32)((uint32)(a1) + (uint32)(11))));
    if ((i >= v5))
    {
      i -= v5;
      do
      {
        v6 = (i >= v5);
        i -= v5;
      }
      while (v6);
      i = ((uint32)(i) & ~(255u << 0) | (((uint32)((sint32)((uint32)(i) + (uint32)(v5))) & 255u) << 0));
    }
    v7 = ((uint32)(r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(12))))) * (uint32)((uint8)(i)));
    v8 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(20))));
    w_u8((uint32)((sint32)((uint32)(a1) + (uint32)(10))), i);
    ob_draft_unresolved_call(0x8005c504u, 1u, 0);
    ob_draft_unresolved_call(0x8005c7c8u, 2u, a1, (sint32)((uint32)(v8) + (uint32)((sint32)((uint32)(4) * (uint32)(v7)))));
    return ob_draft_unresolved_call(0x8005c504u, 1u, 0);
  }
  return result;
}


sint32 sub_8001E108(void)
{
    FUNCTION_MARKER(0x8001e108u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_800637B8 */
    /* TODO: Bind external adapter for sub_80062EE8 */
    uint32 local_objects = ob_draft_scratch_acquire(12u);
  sint32 v0;
  sint32 v1;
  sint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 result;
  ;
  ;
  ;
  ;
  v0 = 0;
  v1 = 0;
  v2 = (0u - (uint32)(2146989068));
  v3 = (0u - (uint32)(2146989072));
  do
  {
    v4 = (sint32)((uint32)(1) << (uint32)(v0));
    w_u32(local_objects + 4u, 3);
    w_u32(local_objects + 0u, (sint32)((uint32)(1) << (uint32)(v0)));
    ob_draft_unresolved_call(0x800637b8u, 1u, (local_objects + 0u));
    ++v0;
    w_u32((uint32)(v3), (sint16)r_u16(local_objects + 8u));
    w_u32((uint32)(v2), (sint16)r_u16(local_objects + 10u));
    w_u32(local_objects + 0u, v4);
    w_u32(local_objects + 4u, 3);
    w_u16(local_objects + 8u, 0);
    w_u16(local_objects + 10u, 0);
    w_u32((uint32)((sint32)((uint32)(v1) - (uint32)(2146991448))), 0);
    w_u32((uint32)((sint32)((uint32)(v1) - (uint32)(2146991444))), 0);
    v3 += 8;
    ob_draft_unresolved_call(0x80062ee8u, 1u, (local_objects + 0u));
    v1 += 28;
    result = (v0 < 24);
    v2 += 8;
  }
  while ((v0 < 24));
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


sint32 sub_80054E08(sint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    FUNCTION_MARKER(0x80054e08u, "SLES_008.65");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
  sint32 result;
  w_u8(a2, (sint32)((uint32)(((a1 / 4500) % 10)) + (uint32)((sint32)((uint32)(16) * (uint32)(((a1 / 4500) / 10))))));
  w_u8(a3, (sint32)((uint32)(((sint32)((uint32)((a1 / 75)) - (uint32)((sint32)((uint32)(60) * (uint32)((a1 / 4500))))) % 10)) + (uint32)((sint32)((uint32)(16) * (uint32)(((sint32)((uint32)((a1 / 75)) - (uint32)((sint32)((uint32)(60) * (uint32)((a1 / 4500))))) / 10))))));
  result = (sint32)((uint32)(((a1 % 75) % 10)) + (uint32)((sint32)((uint32)(16) * (uint32)(((a1 % 75) / 10)))));
  w_u8(a4, result);
  return result;
}


uint32 sub_800262CC(uint32 a1, sint32 a2)
{
    FUNCTION_MARKER(0x800262ccu, "SLES_008.65");
  uint32 v3;
  uint32 v4;
  uint32 v5;
  uint32 v6;
  uint32 v7;
  uint32 v8;
  uint32 result;
  if (a2)
    v3 = ((uint32)((sint32)((uint32)(a2) - (uint32)(1))) >> 3);
  else
    v3 = 0;
  v4 = (uint32)((sint32)((uint32)((sint32)r_u32(0x800770B8u)) + (uint32)((sint32)((uint32)(8) * (uint32)(v3)))));
  v5 = (uint32)(r_u32((v4 + (1) * 4u)));
  if (!v5)
  {
    v5 = (uint32)(r_u32(v4));
    v6 = (uint32)((sint32)((uint32)((sint32)r_u32(0x800770B8u)) + (uint32)((sint32)((uint32)(8) * (uint32)(v3)))));
    if (!(r_u32(v4)))
      goto LABEL_9;
    do
    {
      if (r_u32((v5 + (2) * 4u)))
        break;
      v6 = (uint32)(v5);
      v5 = (uint32)(r_u32(v5));
    }
    while (v5);
    if (!v5)
      LABEL_9:
    v5 = sub_80026164(v6, (sint32)((uint32)((sint32)r_u32(0x800770B8u)) + (uint32)((sint32)((uint32)(8) * (uint32)(v3)))), (sint32)((uint32)(8) * (uint32)(((uint32)(v3) + (uint32)(1)))));

    w_u32((v4 + (1) * 4u), v5);
  }
  v7 = (uint32)(r_u32((v5 + (2) * 4u)));
  v8 = (r_u32(v7) != 0);
  w_u32((v5 + (2) * 4u), r_u32(v7));
  if (!v8)
    w_u32((v4 + (1) * 4u), 0);
  w_u32(v7, v5);
  (w_u16(((uint32)(v5) - (2) * 2u), (r_u16(((uint32)(v5) - (2) * 2u)) + 1u)), r_u16(((uint32)(v5) - (2) * 2u)));
  result = (v7 + (1) * 4u);
  w_u32(a1, (v7 + (1) * 4u));
  return result;
}


sint32 sub_8003042C(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8003042cu, "SLES_008.65");
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    uint32 local_objects = ob_draft_scratch_acquire(4u);
  sint32 v4;
  sint32 v5;
  sint32 result;
  ;
  sub_800303D4(a1, (local_objects + 0u));
  v4 = (uint16)((sint32)r_u32(local_objects + 0u));
  v5 = (sint32)((uint32)((sint16)r_u16(a1)) << (uint32)(14));
  if (!((uint16)((sint32)r_u32(local_objects + 0u))))
    ob_draft_unresolved_call(0x8003042cu, 2u, 7u, 0);
  if ((((uint16)((sint32)r_u32(local_objects + 0u)) == (0u - (uint32)(1))) && (v5 == 0x80000000)))
    ob_draft_unresolved_call(0x8003042cu, 2u, 6u, 0);
  w_u16(a2, (v5 / (uint16)((sint32)r_u32(local_objects + 0u))));
  w_u16((a2 + (1) * 2u), ((sint32)((uint32)((sint16)r_u16((a1 + (1) * 2u))) << (uint32)(14)) / v4));
  result = ((sint32)((uint32)((sint16)r_u16((a1 + (2) * 2u))) << (uint32)(14)) / v4);
  w_u16((a2 + (2) * 2u), result);
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


sint32 sub_8001627C(sint32 a1)
{
    FUNCTION_MARKER(0x8001627cu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80054440 */
    /* TODO: Bind external adapter for sub_800257A0 */
    /* TODO: Bind external adapter for sub_800544EC */
  sint32 result;
  uint32 v3;
  sint32 v4;
  result = ob_draft_unresolved_call(0x80054440u, 1u, r_u8((((uint32)((0x80065BB8u)) + ((sint32)r_u32(0x80065CACu)) * 1u) + (2147066988) * 1u)));
  if (result)
  {
    result = (sint32)r_u32(0x8006C134u);
    if ((sint32)r_u32(0x8006C134u))
    {
      result = ((uint8)((sint8)r_u8(0x8006C231u)) < 0x14u);
      if (((uint8)((sint8)r_u8(0x8006C231u)) < 0x14u))
      {
        sub_80054CD8();
        sub_8001E108();
        v3 = (uint32)((sint32)r_u32(0x800682F4u));
        if ((((sint32)r_u32(0x800682F4u) & 3) != 0))
          v3 = (uint32)(sub_800257CC((0x800682F4u)));
        else
          (w_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800682F4u)) - (uint32)(6))), (r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800682F4u)) - (uint32)(6)))) + 1u)), r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800682F4u)) - (uint32)(6)))));
        v4 = sub_80016220(r_u16(v3));
        sub_80015FA8(a1, v4, v3);
        sub_80016254();
        ob_draft_unresolved_call(0x800257a0u, 1u, (0x800682F4u));
        sub_8001E1E0();
        sub_80054CEC();
        return ob_draft_unresolved_call(0x800544ecu, 0u);
      }
    }
  }
  return result;
}


sint32 sub_80016FC4(uint32 a1)
{
    FUNCTION_MARKER(0x80016fc4u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8005ABC0 */
    /* TODO: Bind external adapter for sub_8005AC90 */
    /* TODO: Bind external adapter for sub_8005CB78 */
    /* TODO: Bind external adapter for sub_8005CD50 */
    /* TODO: Bind external adapter for sub_8005C7C8 */
    /* TODO: Bind external adapter for sub_8005C504 */
    /* TODO: Bind external adapter for sub_800257A0 */
    uint32 local_objects = ob_draft_scratch_acquire(152u);
  sint32 v2;
  ;
  ;
  ;
  if ((((sint32)r_u32(a1) & 3) != 0))
  {
    v2 = sub_800257CC(a1);
  }
  else
  {
    (w_u16((uint32)((sint32)((uint32)((sint32)r_u32(a1)) - (uint32)(6))), (r_u16((uint32)((sint32)((uint32)((sint32)r_u32(a1)) - (uint32)(6)))) + 1u)), r_u16((uint32)((sint32)((uint32)((sint32)r_u32(a1)) - (uint32)(6)))));
    v2 = (sint32)r_u32(a1);
  }
  w_u16(((local_objects + 144u) + (1) * 2u), 24);
  w_u16(((local_objects + 144u) + (2) * 2u), 640);
  w_u16(((local_objects + 144u) + (0) * 2u), 0);
  w_u16(((local_objects + 144u) + (3) * 2u), 256);
  ob_draft_unresolved_call(0x8005abc0u, 5u, (local_objects + 0u), 0u, 0u, 640u, 256u);
  ob_draft_unresolved_call(0x8005ac90u, 5u, (local_objects + 92u), 0u, 0u, 640u, 256u);
  ob_draft_unresolved_call(0x8005cb78u, 1u, (local_objects + 0u));
  ob_draft_unresolved_call(0x8005cd50u, 1u, (local_objects + 92u));
  ob_draft_unresolved_call(0x8005c7c8u, 2u, (local_objects + 144u), v2);
  ob_draft_unresolved_call(0x8005c504u, 1u, 0);
  { uint32 draft_return = ob_draft_unresolved_call(0x800257a0u, 1u, a1); ob_draft_scratch_release(local_objects);  return draft_return; }
}


sint32 sub_8001F9B0(sint32 a1, sint32 a2)
{
    a2 = (sint8)a2;
    FUNCTION_MARKER(0x8001f9b0u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80056048 */
    /* TODO: Bind external adapter for sub_800562AC */
    uint32 local_objects = ob_draft_scratch_acquire(8u);
  sint32 result;
  ;
  result = (uint8)((sint8)r_u8(0x8006C012u));
  if ((sint8)r_u8(0x8006C012u))
  {
    sub_8001DF58(r_u8(0x8006C014u));
    result = ((sint32)r_u32(0x80078DB0) < a1);
    if (((sint32)r_u32(0x80078DB0) >= a1))
    {
      result = 5;
      if ((a1 > 0))
      {
        w_u8(((local_objects + 0u) + (0) * 1u), 5);
        while ((ob_draft_unresolved_call(0x80056048u, 3u, 14, (local_objects + 0u), 0) != 1))
          ;

        while ((ob_draft_unresolved_call(0x800562acu, 3u, 2, (0x80078CB0u + 4u * (uint32)a1), 0) != 1))
          ;

        while ((ob_draft_unresolved_call(0x800562acu, 3u, 3, 0, 0) != 1))
          ;

        w_u8(0x80078DBC, a2);
        w_u32(0x80078DB8, a1);
        w_u8(0x80089968, 1);
        result = ((uint8)((sint8)r_u8(0x8006C013u)) | 2);
        w_u8(0x8006C013u, ((uint32)r_u8(0x8006C013u) | 2u));
      }
    }
  }
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


sint32 sub_80053D20(sint32 a1, sint32 a2)
{
    FUNCTION_MARKER(0x80053d20u, "SLES_008.65");
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    uint32 local_objects = ob_draft_scratch_acquire(40u);
  sint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 v5;
  ;
  ;
  uint32 v9;
  if ((sint32)r_u32(0x800771D0u))
  {
    v2 = r_u32((uint32)((sint32)r_u32(0x80077644u)));
    v3 = (sint32)((uint32)(a1) + (uint32)((sint32)r_u32(0x80077458u)));
    if (!(r_u32((uint32)((sint32)r_u32(0x80077644u)))))
      ob_draft_unresolved_call(0x80053d20u, 2u, 7u, 0);
    if (((v2 == (0u - (uint32)(1))) && (v3 == 0x80000000)))
      ob_draft_unresolved_call(0x80053d20u, 2u, 6u, 0);
    v4 = (v3 / r_u32((uint32)((sint32)r_u32(0x80077644u))));
    if (((v2 == (0u - (uint32)(1))) && ((sint32)((uint32)((sint32)r_u32(0x80077468u)) - (uint32)(a2)) == 0x80000000)))
      ob_draft_unresolved_call(0x80053d20u, 2u, 6u, 0);
    v5 = ((sint32)((uint32)((sint32)r_u32(0x80077468u)) - (uint32)(a2)) / v2);
    w_u32(((local_objects + 0u) + (0) * 4u), (sint32)((uint32)((sint32)((uint32)(v4) * (uint32)(v2))) - (uint32)((sint32)r_u32(0x80077458u))));
    w_u32(((local_objects + 0u) + (2) * 4u), (sint32)((uint32)((sint32)r_u32(0x80077468u)) - (uint32)((sint32)((uint32)(v5) * (uint32)(r_u32((uint32)((sint32)r_u32(0x80077644u))))))));
    sub_80051400((local_objects + 0u), (sint32)((local_objects + 16u)));
    v9 = r_u32(local_objects + 24u);
    sub_8004E028(v4, v5, v9);
  }
  { uint32 draft_return = 1; ob_draft_scratch_release(local_objects);  return draft_return; }
}


sint32 sub_8004B7A0(uint32 a1)
{
    FUNCTION_MARKER(0x8004b7a0u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8002679C */
    /* TODO: Bind external adapter for sub_8004B9B0 */
    /* TODO: Bind external adapter for sub_8004BA60 */
    /* TODO: Bind external adapter for sub_800267C4 */
  sint32 v2;
  sint32 v3;
  uint32 v4;
  uint32 v5;
  uint32 v6;
  v2 = r_u32(a1);
  ob_draft_unresolved_call(0x8002679cu, 2u, a1, 1u);
  v3 = 0;
  ob_draft_unresolved_call(0x8004b9b0u, 2u, v2, r_u32(a1));
  v4 = r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(24))));
  if (r_u8((uint32)((sint32)((uint32)(v2) + (uint32)(11)))))
  {
    v5 = (v4 + (2) * 4u);
    do
    {
      if (r_u32(v4))
      {
        sub_800256CC(r_u32(v4));
        ob_draft_unresolved_call(0x8002679cu, 2u, r_u32(v4), 2u);
      }
      v6 = r_u32((v5 - (1) * 4u));
      if (v6)
      {
        sub_800256CC(v6);
        ob_draft_unresolved_call(0x8002679cu, 2u, r_u32((v5 - (1) * 4u)), 2u);
      }
      if (r_u32(v5))
      {
        sub_800256CC(r_u32(v5));
        ob_draft_unresolved_call(0x8002679cu, 2u, r_u32(v5), 2u);
      }
      v5 += (6) * 4u;
      ++v3;
      v4 += (6) * 4u;
    }
    while ((v3 < r_u8((uint32)((sint32)((uint32)(v2) + (uint32)(11))))));
  }
  ob_draft_unresolved_call(0x8004ba60u, 1u, v2);
  return ob_draft_unresolved_call(0x800267c4u, 2u, a1, 1u);
}


sint32 sub_8002744C(uint32 a1)
{
    FUNCTION_MARKER(0x8002744cu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_800275F8 */
    /* TODO: Bind external adapter for sub_8002776C */
    /* TODO: Bind external adapter for nullsub_22 */
    /* TODO: Bind external adapter for sub_80027978 */
  sint8 v2;
  sint32 v3;
  sint32 v4;
  uint32 v5;
  uint32 v6;
  sint32 result;
  v2 = r_u8((uint32)((sint32)((uint32)(a1) + (uint32)(32))));
  v3 = ((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(16))))) - (uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(20))))));
  if ((((v2 & 1) == 0) || r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(34))))))
    goto LABEL_15;
  if ((v2 & 2) == 0 || ((v4 = a1), r_u16(a1 + 36u)))
    v4 = (sint32)r_u32(0x80077228u);
  (w_u16((uint32)((sint32)((uint32)(a1) + (uint32)(34))), (r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(34)))) + 1u)), r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(34)))));
  v5 = sub_80026D30(v3, v4);
  v6 = v5;
  (w_u16((uint32)((sint32)((uint32)(a1) + (uint32)(34))), (r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(34)))) - 1u)), r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(34)))));
  if (v5)
  {
    ob_draft_unresolved_call(0x800275f8u, 2u, a1, v5);
    result = ob_draft_unresolved_call(0x8002776cu, 2u, v6, (sint32)((uint32)(a1) + (uint32)(40)));
    w_u8((uint32)((sint32)((uint32)(a1) + (uint32)(32))), 0);
  }
  else
  {
    LABEL_15:
    if (((((r_u8((uint32)((sint32)((uint32)(a1) + (uint32)(32)))) & 2) == 0) || r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(36))))) || r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(34))))))
    {
      return ob_draft_unresolved_call(0x800279ccu, 1u, v3);
    }
    else
    {
      sub_800269D0(a1);
      result = ob_draft_unresolved_call(0x80027978u, 1u, a1);
      w_u8((uint32)((sint32)((uint32)(a1) + (uint32)(32))), 0);
    }

  }
  return result;
}


sint32 sub_800454BC(uint32 a1)
{
    FUNCTION_MARKER(0x800454bcu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8002B7FC */
  sint32 result;
  sint32 v3;
  uint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  result = (r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(160)))) & 1);
  if (!result)
  {
    v3 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))));
    v4 = (uint32)((sint32)((uint32)(a1) + (uint32)(36)));
    if (v3)
    {
      sub_800454BC(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24)))));
      if (((r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(160)))) & 8) != 0))
      {
        ob_draft_unresolved_call(0x8002b7fcu, 2u, (uint32)((sint32)((uint32)(v3) + (uint32)(54))), (uint32)((sint32)((uint32)(a1) + (uint32)(54))));
        if (((r_u32((uint32)((sint32)((uint32)(v3) + (uint32)(160)))) & 4) != 0))
        {
          v5 = (r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(160)))) | 4);
          LABEL_14:
          w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(160))), v5);

          result = (r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(160)))) | 1);
          w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(160))), result);
          return result;
        }
        v6 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(160))));
        v7 = (0u - (uint32)(5));
      }
      else
      {
        if (((r_u32((uint32)((sint32)((uint32)(v3) + (uint32)(160)))) & 4) != 0))
          ob_draft_unresolved_call(0x8002b7fcu, 2u, (uint32)((sint32)((uint32)(a1) + (uint32)(36))), (uint32)((sint32)((uint32)(a1) + (uint32)(54))));
        else
          sub_8002B15C((uint32)((sint32)((uint32)(v3) + (uint32)(54))), (uint32)((sint32)((uint32)(a1) + (uint32)(36))), (uint32)((sint32)((uint32)(a1) + (uint32)(54))));
        v6 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(160))));
        v7 = (0u - (uint32)(5));
      }
    }
    else
    {
      ob_draft_unresolved_call(0x8002b7fcu, 2u, v4, (uint32)((sint32)((uint32)(a1) + (uint32)(54))));
      v7 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(160))));
      v5 = (v7 | 4);
      if (((v7 & 8) != 0))
        goto LABEL_14;
      v6 = (0u - (uint32)(5));
    }
    v5 = (v7 & v6);
    goto LABEL_14;
  }
  return result;
}


uint32 sub_80026164(uint32 a1, uint32 a2, sint32 a3)
{
    FUNCTION_MARKER(0x80026164u, "SLES_008.65");
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
  uint32 v6;
  uint32 v7;
  uint32 v8;
  uint32 v9;
  uint32 v10;
  uint32 v11;
  sint32 v12;
  uint32 v13;
  sint32 v14;
  v6 = (sint32)((uint32)(a3) + (uint32)(4));
  if (((uint32)((sint32)((uint32)(a3) + (uint32)(4))) >= 0x7E8))
  {
    v7 = 1;
    v8 = 0;
    v9 = (sint32)((uint32)(a3) + (uint32)(4));
  }
  else
  {
    if ((a3 == (0u - (uint32)(4))))
      ob_draft_unresolved_call(0x80026164u, 2u, 7u, 0);
    v7 = (0x7E8 / v6);
    v8 = (0x7E8 % v6);
    v9 = (sint32)((uint32)((0x7E8 / v6)) * (uint32)(v6));
    if (((0x7E8 % v6) >= 0x101))
      v8 = 0;
  }
  sub_80026694(a1, ((uint32)(((uint32)(v9) + (uint32)(v8))) + (uint32)(24)), 6);
  v10 = r_u32(a1);
  v11 = (r_u32(a1) + (2) * 4u);
  w_u32(v10, 0);
  w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(4))), v10);
  w_u32((v10 + (4) * 4u), v7);
  v12 = r_u32((v10 + (4) * 4u));
  v13 = (v10 + (6) * 4u);
  w_u32((v10 + (1) * 4u), a2);
  w_u32((v10 + (3) * 4u), a3);
  v14 = (sint32)((uint32)(v12) - (uint32)(1));
  for (w_u32((v10 + (5) * 4u), v8); (v14 != (0u - (uint32)(1))); v13 = (uint32)((((uint32)(v13) + (a3) * 1u) + (4) * 1u)))
  {
    w_u32(v11, v13);
    v11 = v13;
    --v14;
  }

  w_u32(v11, 0);
  sub_80026898(a1, (uint16)((sint16)r_u16(0x800770BCu)));
  return v10;
}


sint32 sub_80043404(void)
{
    FUNCTION_MARKER(0x80043404u, "SLES_008.65");
  sint16 v0;
  sint16 v1;
  sint16 v2;
  sint32 result;
  v0 = r_u16((uint32)((sint32)r_u32(0x800775D0u)));
  w_u16(0x8008C8AA, ((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800775D0u)) + (uint32)(6)))) >> 2));
  w_u16(0x8008C8AC, ((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800775D0u)) + (uint32)(12)))) >> 2));
  v1 = r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800775D0u)) + (uint32)(2))));
  w_u16(0x80089668, ((sint16)(r_u16(0x8008CAD0)) >> 2));
  w_u16(0x8008C8AE, (v1 >> 2));
  w_u16(0x8008C8B0, ((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800775D0u)) + (uint32)(8)))) >> 2));
  w_u16(0x8008C8B2, ((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800775D0u)) + (uint32)(14)))) >> 2));
  w_u16(0x8008C8B4, ((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800775D0u)) + (uint32)(4)))) >> 2));
  w_u16(0x8008C8B6, ((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800775D0u)) + (uint32)(10)))) >> 2));
  v2 = r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800775D0u)) + (uint32)(16))));
  w_u16(0x8008C8A8, (v0 >> 2));
  w_u16(0x8008966A, ((sint16)(r_u16(0x8008CAD6)) >> 2));
  w_u16(0x8008966C, ((sint16)(r_u16(0x8008CADC)) >> 2));
  w_u16(0x8008966E, ((sint16)(r_u16(0x8008CAD2)) >> 2));
  w_u16(0x80089670, ((sint16)(r_u16(0x8008CAD8)) >> 2));
  w_u16(0x80089674, ((sint16)(r_u16(0x8008CAD4)) >> 2));
  w_u16(0x80089672, ((sint16)(r_u16(0x8008CADE)) >> 2));
  w_u16(0x8008C8B8, (v2 >> 2));
  w_u16(0x80089676, ((sint16)(r_u16(0x8008CADA)) >> 2));
  result = (((uint32)(r_u16(0x8008CAE0)) << (uint32)(16)) >> 18);
  w_u16(0x80089678, ((sint16)(r_u16(0x8008CAE0)) >> 2));
  return result;
}


sint32 sub_80048BF4(uint32 a1)
{
    FUNCTION_MARKER(0x80048bf4u, "SLES_008.65");
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
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
  sint32 v11;
  sint32 v12;
  sint32 result;
  v1 = r_u32((a1 + (24) * 4u));
  if (v1)
  {
    v3 = ((uint32)(r_u32((a1 + (6) * 4u))) - (uint32)(r_u32((a1 + (21) * 4u))));
    if (((v1 == (0u - (uint32)(1))) && (v3 == 0x80000000)))
      ob_draft_unresolved_call(0x80048bf4u, 2u, 6u, 0);
    v2 = (v3 / v1);
  }
  else
  {
    v2 = 2147483393;
  }
  v4 = r_u32((a1 + (25) * 4u));
  if (v4)
  {
    v6 = ((uint32)(r_u32((a1 + (7) * 4u))) - (uint32)(r_u32((a1 + (22) * 4u))));
    if (((v4 == (0u - (uint32)(1))) && (v6 == 0x80000000)))
      ob_draft_unresolved_call(0x80048bf4u, 2u, 6u, 0);
    v5 = (v6 / v4);
  }
  else
  {
    v5 = 2147483393;
  }
  v7 = r_u32((a1 + (26) * 4u));
  if (v7)
  {
    v9 = ((uint32)(r_u32((a1 + (8) * 4u))) - (uint32)(r_u32((a1 + (23) * 4u))));
    if (((v7 == (0u - (uint32)(1))) && (v9 == 0x80000000)))
      ob_draft_unresolved_call(0x80048bf4u, 2u, 6u, 0);
    v8 = (v9 / v7);
  }
  else
  {
    v8 = 2147483393;
  }
  v10 = v5;
  v11 = (v5 < v2);
  if ((v8 < v5))
  {
    v10 = v8;
    v11 = (v8 < v2);
  }
  v12 = v2;
  if (v11)
    v12 = v10;
  result = ((uint32)(((uint32)(r_u32(a1)) + (uint32)(v12))) + (uint32)(1));
  w_u32((a1 + (27) * 4u), result);
  return result;
}


void sub_80028280(sint32 a1, sint32 a2, uint32 a3, uint32 a4)
{
    FUNCTION_MARKER(0x80028280u, "SLES_008.65");
  sint32 v4;
  uint16 v8;
  uint32 v9;
  uint32 v10;
  sint32 v11;
  sint32 v12;
  v4 = a1;
  if (a1 || ((a1 = 0), a2))
  {
    v8 = sub_80027F98(a1, a2);
    v9 = v4;
    if ((v4 < 0))
      v9 = (0u - (uint32)(v4));
    v10 = a2;
    if ((a2 < 0))
      v10 = (0u - (uint32)(a2));
    w_u16(a3, v8);
    if ((v10 >= v9))
    {
      v11 = (sint16)r_u16((uint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)((v8 >> 4)))) - (uint32)(2147040508))));
      v12 = (sint32)((uint32)((sint32)((uint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)((((uint32)(v8) + (uint32)(16)) >> 4)))) - (uint32)(2147040508))))) - (uint32)(v11))) * (uint32)((v8 & 0xF)));
    }
    else
    {
      v11 = (sint16)r_u16((uint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)((v8 >> 4)))) - (uint32)(2147038460))));
      v12 = (sint32)((uint32)((sint32)((uint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)((((uint32)(v8) + (uint32)(16)) >> 4)))) - (uint32)(2147038460))))) - (uint32)(v11))) * (uint32)((v8 & 0xF)));
      v10 = v9;
    }
    w_u32(a4, sub_800283DC(v10, (sint16)((sint32)((uint32)((v12 >> 4)) + (uint32)(v11)))));
  }
  else
  {
    w_u16(a3, 0);
    w_u32(a4, 0);
  }
}


uint32 sub_80017328(uint32 a1, sint32 a2)
{
    FUNCTION_MARKER(0x80017328u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80057CD0 */
  sint32 v4;
  sint32 v5;
  uint32 v6;
  uint32 result;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  sint32 v11;
  sint32 v12;
  sint32 v13;
  sint32 v14;
  sint32 v15;
  sint32 v16;
  v4 = 0;
  if (((sint32)r_u32(0x80066018u) <= 0))
  {
    LABEL_5:
    v6 = (ob_draft_unresolved_call(0x80057cd0u, 2u, a1, a2) != 0);

    result = 0;
    if (v6)
    {
      if (((sint32)r_u32(0x80066018u) < 20))
      {
        v12 = (sint32)((uint32)(7) * (uint32)((sint32)r_u32(0x80066018u)));
        w_u32((0x80077670u + (v12) * 4u), a2);
        v13 = (sint32)r_u32((a1 + (1) * 4u));
        v14 = (sint32)r_u32((a1 + (2) * 4u));
        v15 = (sint32)r_u32((a1 + (3) * 4u));
        w_u32((0x80077674u + (v12) * 4u), (sint32)r_u32(a1));
        w_u32((0x80077678u + (v12) * 4u), v13);
        w_u32((0x8007767cu + (v12) * 4u), v14);
        w_u32((0x80077680u + (v12) * 4u), v15);
        v16 = (sint32)r_u32((a1 + (5) * 4u));
        w_u32((0x80077684u + (v12) * 4u), (sint32)r_u32((a1 + (4) * 4u)));
        w_u32((0x80077688u + (v12) * 4u), v16);
        (w_u32(0x80066018u, ((sint32)r_u32(0x80066018u) + 1u)), (sint32)r_u32(0x80066018u));
      }
      return a1;
    }
  }
  else
  {
    v5 = 0;
    while (1)
    {
      ++v4;
      if (((sint32)r_u32((0x80077670u + (v5) * 4u)) == a2))
        break;
      v5 += 7;
      if ((v4 >= (sint32)r_u32(0x80066018u)))
        goto LABEL_5;
    }

    v8 = (sint32)r_u32((0x80077678u + (v5) * 4u));
    v9 = (sint32)r_u32((0x8007767cu + (v5) * 4u));
    v10 = (sint32)r_u32((0x80077680u + (v5) * 4u));
    w_u32(a1, (sint32)r_u32((0x80077674u + (v5) * 4u)));
    w_u32((a1 + (1) * 4u), v8);
    w_u32((a1 + (2) * 4u), v9);
    w_u32((a1 + (3) * 4u), v10);
    v11 = (sint32)r_u32((0x80077688u + (v5) * 4u));
    w_u32((a1 + (4) * 4u), (sint32)r_u32((0x80077684u + (v5) * 4u)));
    w_u32((a1 + (5) * 4u), v11);
    return a1;
  }
  return result;
}


sint32 sub_800220BC(void)
{
    FUNCTION_MARKER(0x800220bcu, "SLES_008.65");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
  uint32 v0;
  uint32 v1;
  w_u32(0x80073514u, 0);
  if (!r_u32(0x80084468))
  {
    sub_800223A0(0);
    v0 = ((r_u32(0x80089B80) / 5u) % 0x18);
    v1 = ((r_u32(0x80089B80) / 5u) % 5);
    sub_80022234(v0);
    sub_800222FC(v1);
    sub_80022440();
    if (((r_u32(0x80089B7C) == 1) && (((uint32)(v0) - (uint32)(2)) < 4)))
    {
      w_u32(0x80084468, r_u32(0x80089B7C));
      w_u32(0x80089B80, r_u32(0x80089B7C));
    }
  }
  if ((r_u32(0x80084468) == 1))
  {
    if ((r_u32(0x80089B80) >= 0x50u))
    {
      if ((r_u32(0x80089B80) >= 0x78u))
        w_u32(0x80084448, r_u32(0x80084468));
    }
    else
    {
      sub_800223A0(((r_u32(0x80089B80) >> 1) % 0x28u));
    }
  }
  return (w_u32(0x80089B80, (r_u32(0x80089B80) + 1u)), r_u32(0x80089B80));
}


sint32 sub_800427AC(void)
{
    FUNCTION_MARKER(0x800427acu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8002DC10 */
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
  sint32 v0;
  sint32 v1;
  sint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 v5;
  sint32 result;
  ob_draft_unresolved_call(0x8002dc10u, 1u, (uint32)(0x800895C0));
  v0 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8007741Cu)) + (uint32)(12))));
  v1 = r_u32((uint32)((sint32)((uint32)(v0) + (uint32)(24))));
  v2 = r_u32((uint32)((sint32)((uint32)(v0) + (uint32)(28))));
  v3 = (sint32)((uint32)(v1) << (uint32)(16));
  if (((sint16)(v2) < (sint16)(v1)))
    v3 = (sint32)((uint32)(v2) << (uint32)(16));
  v4 = (v3 >> 2);
  if ((((sint16)(v1) == (0u - (uint32)(1))) && (v4 == 0x80000000)))
    ob_draft_unresolved_call(0x800427acu, 2u, 6u, 0);
  if (!((uint16)(v2)))
    ob_draft_unresolved_call(0x800427acu, 2u, 7u, 0);
  if ((((sint16)(v2) == (0u - (uint32)(1))) && (v4 == 0x80000000)))
    ob_draft_unresolved_call(0x800427acu, 2u, 6u, 0);
  v5 = (v4 / (uint16)((sint32)((uint32)(2) * (uint32)(r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800770C0u)) + (uint32)(8))))))));
  if (!((sint32)((uint32)(2) * (uint32)(r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800770C0u)) + (uint32)(8))))))))
    ob_draft_unresolved_call(0x800427acu, 2u, 7u, 0);
  w_u16(0x800895C2, 0);
  w_u16(0x800895C4, 0);
  w_u16(0x800895C6, 0);
  w_u16(0x800895CA, 0);
  w_u16(0x800895CC, 0);
  w_u16(0x800895CE, 0);
  result = (r_u32(0x800895F0) | 0x12);
  w_u32(0x800895F0, ((uint32)(r_u32(0x800895F0)) | (uint32)(0x12u)));
  w_u32(0x800895C0, (v4 / (sint16)(v1)));
  w_u16(0x800895C8, (v4 / (sint16)(v2)));
  w_u16(0x800895D0, v5);
  return result;
}


sint32 sub_800171EC(sint32 a1, sint32 a2)
{
    FUNCTION_MARKER(0x800171ecu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80056048 */
    /* TODO: Bind external adapter for sub_80058A98 */
    /* TODO: Bind external adapter for sub_80058BA0 */
    /* TODO: Bind external adapter for sub_80059CA8 */
    /* TODO: Bind external adapter for sub_80063FC8 */
    /* TODO: Bind external adapter for sub_80055D74 */
    uint32 local_objects = ob_draft_scratch_acquire(40u);
  sint32 v2;
  sint32 i;
  uint32 v6;
  ;
  ;
  ;
  ;
  for (i = 0; (i < 10); ++i)
  {
    if (sub_80017328((local_objects + 8u), a1))
    {
      v6 = ((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 12u)) + (uint32)(2047))) >> 11);
      w_u8(((local_objects + 0u) + (0) * 1u), (sint8)r_u8(((local_objects + 8u) + (0) * 1u)));
      w_u8(((local_objects + 0u) + (1) * 1u), (sint8)r_u8(((local_objects + 8u) + (1) * 1u)));
      w_u8(((local_objects + 0u) + (2) * 1u), (sint8)r_u8(((local_objects + 8u) + (2) * 1u)));
      if ((v6 >= 0x3E9))
        v6 = 1000;
      sub_80026694((local_objects + 32u), ((uint32)(v6) << (uint32)(11)), 0);
      ob_draft_unresolved_call(0x80056048u, 3u, 2, (local_objects + 0u), 0);
      ob_draft_unresolved_call(0x80058a98u, 3u, v6, (sint32)r_u32(((local_objects + 32u) + (0) * 4u)), 128);
      while (1)
      {
        v2 = ob_draft_unresolved_call(0x80058ba0u, 2u, 1, 0);
        if ((v2 <= 0))
          break;
        ob_draft_unresolved_call(0x80059ca8u, 1u, 0);
      }

      ob_draft_unresolved_call(0x80063fc8u, 3u, a2, (sint32)r_u32(((local_objects + 32u) + (0) * 4u)), (sint32)r_u32(local_objects + 12u));
      sub_80026758((local_objects + 32u));
      if (!v2)
        { uint32 draft_return = (sint32)r_u32(local_objects + 12u); ob_draft_scratch_release(local_objects);  return draft_return; }
    }
  }

  if (!v2)
    { uint32 draft_return = (sint32)r_u32(local_objects + 12u); ob_draft_scratch_release(local_objects);  return draft_return; }
  ob_draft_unresolved_call(0x80055d74u, 0u);
  { uint32 draft_return = 0; ob_draft_scratch_release(local_objects);  return draft_return; }
}


sint32 sub_8002A9DC(uint32 a1, uint32 a2, uint32 a3)
{
    a2 = (uint16)a2;
    FUNCTION_MARKER(0x8002a9dcu, "SLES_008.65");
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
  sint32 result;
  v3 = (sint32)((uint32)(2) * (uint32)((((uint32)(a2) + (uint32)(8)) >> 4)));
  v4 = (sint16)(r_u16((a1 + (1) * 2u)));
  v5 = (sint16)r_u16((uint32)((sint32)((uint32)(v3) - (uint32)(2147038460))));
  v6 = (sint16)(r_u16((a1 + (2) * 2u)));
  v7 = (sint32)((uint32)(v4) * (uint32)(v5));
  v8 = (sint16)r_u16((uint32)((sint32)((uint32)(v3) - (uint32)(2147040508))));
  v9 = (sint32)((uint32)(v6) * (uint32)((0u - (uint32)(v8))));
  v10 = (sint32)((uint32)(v4) * (uint32)(v8));
  v11 = (sint32)((uint32)(v6) * (uint32)(v5));
  v12 = (sint16)(r_u16((a1 + (4) * 2u)));
  v13 = (sint32)((uint32)(v12) * (uint32)(v5));
  v14 = (sint16)(r_u16((a1 + (5) * 2u)));
  v15 = (sint32)((uint32)(v14) * (uint32)((0u - (uint32)(v8))));
  v16 = (sint32)((uint32)(v12) * (uint32)(v8));
  v17 = (sint32)((uint32)(v14) * (uint32)(v5));
  v18 = (sint16)(r_u16((a1 + (7) * 2u)));
  v19 = (sint32)((uint32)(v18) * (uint32)(v5));
  v20 = (sint16)(r_u16((a1 + (8) * 2u)));
  v21 = (sint32)((uint32)(v18) * (uint32)(v8));
  v18 = ((uint32)(v18) & ~(65535u << 0) | (((uint32)(r_u16(a1)) & 65535u) << 0));
  w_u16((a3 + (1) * 2u), ((sint32)((uint32)(v7) + (uint32)(v9)) >> 14));
  w_u16((a3 + (2) * 2u), ((sint32)((uint32)(v10) + (uint32)(v11)) >> 14));
  w_u16(a3, v18);
  v18 = ((uint32)(v18) & ~(65535u << 0) | (((uint32)(r_u16((a1 + (3) * 2u))) & 65535u) << 0));
  w_u16((a3 + (4) * 2u), ((sint32)((uint32)(v13) + (uint32)(v15)) >> 14));
  w_u16((a3 + (5) * 2u), ((sint32)((uint32)(v16) + (uint32)(v17)) >> 14));
  w_u16((a3 + (3) * 2u), v18);
  v18 = ((uint32)(v18) & ~(65535u << 0) | (((uint32)(r_u16((a1 + (6) * 2u))) & 65535u) << 0));
  w_u16((a3 + (7) * 2u), ((sint32)((uint32)(v19) + (uint32)((sint32)((uint32)(v20) * (uint32)((0u - (uint32)(v8)))))) >> 14));
  w_u16((a3 + (6) * 2u), v18);
  result = (sint32)((uint32)(v20) * (uint32)(v5));
  w_u16((a3 + (8) * 2u), ((sint32)((uint32)(v21) + (uint32)((sint32)((uint32)(v20) * (uint32)(v5)))) >> 14));
  return result;
}


uint32 sub_800217B4(sint32 a1)
{
    a1 = (sint16)a1;
    FUNCTION_MARKER(0x800217b4u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8005D3F0 */
    uint32 local_objects = ob_draft_scratch_acquire(28u);
  sint32 v1;
  uint32 result;
  sint32 v3;
  sint32 v5;
  sint16 v6;
  sint16 v7;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  v1 = (sint32)r_u32(0x800774A8u);
  result = ((sint32)((uint32)((sint32)r_u32(0x800775BCu)) - (uint32)((sint32)r_u32(0x800774A8u))) < 64);
  v3 = r_u32((uint32)((sint32)r_u32(0x80077634u)));
  if (((sint32)((uint32)((sint32)r_u32(0x800775BCu)) - (uint32)((sint32)r_u32(0x800774A8u))) >= 64))
  {
    v5 = (sint32)r_u32(0x8007737Cu);
    w_u32((uint32)((sint32)r_u32(0x80077634u)), ((r_u32((uint32)((sint32)r_u32(0x80077634u))) & 0xFF000000) | ((sint32)r_u32(0x800774A8u) & 0xFFFFFF)));
    w_u16(((local_objects + 0u) + (0) * 2u), r_u16((uint32)(v5)));
    w_u16(((local_objects + 0u) + (1) * 2u), r_u16((uint32)((sint32)((uint32)(v5) + (uint32)(2)))));
    w_u16(((local_objects + 0u) + (2) * 2u), r_u16((uint32)((sint32)((uint32)(v5) + (uint32)(4)))));
    w_u16(((local_objects + 0u) + (3) * 2u), r_u16((uint32)((sint32)((uint32)(v5) + (uint32)(6)))));
    w_u16(((local_objects + 0u) + (4) * 2u), r_u16((uint32)((sint32)((uint32)(v5) + (uint32)(8)))));
    w_u16(((local_objects + 0u) + (5) * 2u), r_u16((uint32)((sint32)((uint32)(v5) + (uint32)(10)))));
    w_u16(((local_objects + 0u) + (6) * 2u), r_u16((uint32)((sint32)((uint32)(v5) + (uint32)(12)))));
    w_u16(((local_objects + 0u) + (7) * 2u), r_u16((uint32)((sint32)((uint32)(v5) + (uint32)(14)))));
    v6 = r_u16((uint32)((sint32)((uint32)(v5) + (uint32)(16))));
    w_u32(0x80077634u, v1);
    w_u16(((local_objects + 0u) + (8) * 2u), v6);
    v7 = r_u16((uint32)((sint32)((uint32)(v5) + (uint32)(18))));
    w_u32(0x800774A8u, (sint32)((uint32)(v1) + (uint32)(64)));
    w_u16(((local_objects + 0u) + (10) * 2u), a1);
    w_u16(((local_objects + 0u) + (9) * 2u), v7);
    w_u8(local_objects + 22u, r_u8((uint32)((sint32)((uint32)(v5) + (uint32)(22)))));
    w_u8(local_objects + 23u, r_u8((uint32)((sint32)((uint32)(v5) + (uint32)(23)))));
    w_u8(local_objects + 24u, r_u8((uint32)((sint32)((uint32)(v5) + (uint32)(24)))));
    w_u8(local_objects + 25u, r_u8((uint32)((sint32)((uint32)(v5) + (uint32)(25)))));
    w_u8(local_objects + 26u, r_u8((uint32)((sint32)((uint32)(v5) + (uint32)(26)))));
    w_u8(local_objects + 27u, r_u8((uint32)((sint32)((uint32)(v5) + (uint32)(27)))));
    ob_draft_unresolved_call(0x8005d3f0u, 2u, v1, (local_objects + 0u));
    result = ((r_u32((uint32)((sint32)r_u32(0x80077634u))) & 0xFF000000) | (v3 & 0xFFFFFF));
    w_u32((uint32)((sint32)r_u32(0x80077634u)), result);
  }
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


sint32 sub_80028614(uint32 a1)
{
    FUNCTION_MARKER(0x80028614u, "SLES_008.65");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Resolve external symbol __trap instead of the owning function adapter placeholder */
    /* TODO: Bind external adapter for __trap */
  uint16 v2;
  sint32 v3;
  sint32 v4;
  sint16 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  v2 = sub_8002B868((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)((sint16)r_u16(a1)) * (uint32)((sint16)r_u16(a1)))) + (uint32)((sint32)((uint32)((sint16)r_u16((a1 + (1) * 2u))) * (uint32)((sint16)r_u16((a1 + (1) * 2u))))))) + (uint32)((sint32)((uint32)((sint16)r_u16((a1 + (2) * 2u))) * (uint32)((sint16)r_u16((a1 + (2) * 2u)))))));
  if (v2)
  {
    v3 = (v2 >> 1);
    if ((v2 > 0x7FFFu))
    {
      v4 = ((uint32)((uint16)((sint16)r_u16((a1 + (1) * 2u)))) << (uint32)(16));
      w_u16(a1, ((uint32)((sint16)r_u16(a1)) >> (uint32)(1)));
      v5 = (sint16)r_u16((a1 + (2) * 2u));
      w_u16((a1 + (1) * 2u), (v4 >> 17));
      w_u16((a1 + (2) * 2u), (v5 >> 1));
    }
    else
    {
      v3 = ((uint32)(v3) & ~(65535u << 0) | (((uint32)(v2) & 65535u) << 0));
    }
    v6 = (sint16)(v3);
    v7 = (sint32)((uint32)((sint16)r_u16(a1)) << (uint32)(14));
    v8 = (v7 / (sint16)(v3));
    if (!((uint16)(v3)))
      ob_draft_unresolved_call(0x80028614u, 2u, 7u, 0);
    if ((((sint16)(v3) == (0u - (uint32)(1))) && (v7 == 0x80000000)))
      ob_draft_unresolved_call(0x80028614u, 1u, 0x5Du);
    v9 = (sint32)((uint32)((sint16)r_u16((a1 + (1) * 2u))) << (uint32)(14));
    if (((v6 == (0u - (uint32)(1))) && (v9 == 0x80000000)))
      ob_draft_unresolved_call(0x80028614u, 1u, 0x5Du);
    v10 = (sint32)((uint32)((sint16)r_u16((a1 + (2) * 2u))) << (uint32)(14));
    if (((v6 == (0u - (uint32)(1))) && (v10 == 0x80000000)))
      ob_draft_unresolved_call(0x80028614u, 1u, 0x5Du);
    w_u16(a1, v8);
    w_u16((a1 + (1) * 2u), (v9 / v6));
    w_u16((a1 + (2) * 2u), (v10 / v6));
  }
  return v2;
}


sint32 sub_800508D0(uint32 a1)
{
    FUNCTION_MARKER(0x800508d0u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8005160C */
    uint32 local_objects = ob_draft_scratch_acquire(4u);
  sint32 v2;
  sint32 v3;
  uint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  sint32 result;
  sint32 v12;
  ;
  uint32 v14;
  sint32 v15;
  sint32 v16;
  sint32 v17;
  sint32 v18;
  if (r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(344)))))
    v2 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(392))));
  else
    v2 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(384))));
  v3 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(272))));
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(192))), ((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(232))))) + (uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(236)))))));
  v4 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(136))));
  v5 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(140))));
  v6 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(144))));
  w_u32(local_objects + 0u, r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(132)))));
  v14 = v4;
  v15 = v5;
  v16 = v6;
  v7 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(152))));
  v17 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(148))));
  v18 = v7;
  ob_draft_unresolved_call(0x8005160cu, 3u, (local_objects + 0u), 0, r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(228)))));
  v8 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(352))));
  v9 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(384))));
  while (1)
  {
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(200))), v8);
    v10 = (sint16)r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(46))));
    result = (v10 & (sint8)((v17) >> 8));
    if (!result)
    {
      if ((((uint8)(v10) & r_u8((uint32)((sint32)((uint32)(v16) + (uint32)(22))))) != 0))
      {
        result = 1;
        if ((((uint16)(v10) & r_u16(v14)) == 0))
          result = 2;
        w_u8((uint32)((sint32)((uint32)(a1) + (uint32)(148))), result);
      }
      else
      {
        v12 = v3;
        if ((v9 < v3))
          v12 = v9;
        w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(120))), v12);
        result = sub_80050B88(v15, a1);
      }
    }
    if ((v9 == v2))
      break;
    ob_draft_unresolved_call(0x8005160cu, 3u, (local_objects + 0u), 1, r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(348)))));
    v9 = v2;
    v8 = ((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(200))))) + (uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(356))))));
  }

  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


sint32 sub_80041BB8(void)
{
    FUNCTION_MARKER(0x80041bb8u, "SLES_008.65");
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
  sint32 v0;
  sint32 v1;
  sint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 result;
  w_u16(0x80077544u, 0);
  v0 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800770C0u)) + (uint32)(8))));
  w_u16(0x80077548u, (0u - (uint32)(((sint16)r_u16(0x800774E2u) >> 1))));
  w_u16(0x80077546u, v0);
  v1 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800770C0u)) + (uint32)(8))));
  w_u16(0x8007753Eu, 0);
  w_u16(0x80077540u, (0u - (uint32)(((sint16)r_u16(0x800774E0u) >> 1))));
  w_u16(0x8007753Cu, v1);
  sub_8003042C((0x80077544u), (sint8)r_u8(0x80077348u));
  sub_8003042C((0x8007753Cu), (0x80077340u));
  v2 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800770C0u)) + (uint32)(8))));
  w_u16(0x8007750Eu, 0);
  w_u16(0x80077510u, 1024);
  w_u16(0x8007750Cu, (0u - (uint32)((sint16)(v2))));
  sub_8003042C((0x8007750Cu), (0x8007732Cu));
  v3 = (sint32)((uint32)(4700) * (uint32)((sint32)((uint32)((sint16)r_u16(0x8007732Cu)) - (uint32)((sint16)r_u16(0x80077340u)))));
  v4 = ((sint32)((uint32)((sint32)((uint32)((0u - (uint32)((sint16)r_u16(0x80077344u)))) * (uint32)((sint16)r_u16(0x8007732Cu)))) + (uint32)((sint32)((uint32)((sint16)r_u16(0x80077330u)) * (uint32)((sint16)r_u16(0x80077340u))))) >> 14);
  if (!v4)
    ob_draft_unresolved_call(0x80041bb8u, 2u, 7u, 0);
  if (((v4 == (0u - (uint32)(1))) && (v3 == 0x80000000)))
    ob_draft_unresolved_call(0x80041bb8u, 2u, 6u, 0);
  v5 = (v3 / v4);
  v6 = (sint32)((uint32)((sint16)r_u16(0x80077330u)) - (uint32)((sint16)r_u16(0x80077344u)));
  result = (sint32)((uint32)(4700) * (uint32)(v6));
  if (((v4 == (0u - (uint32)(1))) && (result == 0x80000000)))
    ob_draft_unresolved_call(0x80041bb8u, 2u, 6u, 0);
  w_u32(0x800775C8u, (0u - (uint32)(v5)));
  w_u32(0x80077338u, ((sint32)((uint32)(4700) * (uint32)(v6)) / v4));
  return result;
}


sint32 sub_8004A048(uint32 a1, uint32 a2, sint32 a3, sint32 a4)
{
    FUNCTION_MARKER(0x8004a048u, "SLES_008.65");
  uint32 v4;
  sint32 v9;
  uint32 v10;
  uint32 v11;
  uint32 v12;
  sint32 v13;
  sint32 v14;
  sint32 v15;
  sint32 v16;
  sint32 v17;
  sint32 v18;
  sint32 result;
  v4 = (uint32)((sint32)r_u32(0x80077140u));
  v9 = 0;
  if (((sint32)r_u32(0x80077260u) < 0))
    return 0;
  while (1)
  {
    v10 = (uint32)(r_u32(v4));
    v11 = (r_u32(((v4 += 4u) - 4u)) == 0);
    if (((!v11 && !r_u32((v10 + (7) * 4u))) && ((r_u32((v10 + (34) * 4u)) & a3) != 0)))
    {
      v12 = (uint32)(r_u32((v10 + (8) * 4u)));
      sub_800455DC(v12, a4);
      v13 = r_u32((v10 + (19) * 4u));
      v14 = (sint32)((uint32)((sint32)r_u32((v12 + (30) * 4u))) + (uint32)(r_u32((v10 + (22) * 4u))));
      if (((r_u32(a1) < (sint32)((uint32)(v14) + (uint32)(v13))) && ((sint32)((uint32)(v14) - (uint32)(v13)) < r_u32(a2))))
      {
        v15 = r_u32((v10 + (21) * 4u));
        v16 = (sint32)((uint32)((sint32)r_u32((v12 + (32) * 4u))) + (uint32)(r_u32((v10 + (24) * 4u))));
        if (((r_u32((a1 + (2) * 4u)) < (sint32)((uint32)(v16) + (uint32)(v15))) && ((sint32)((uint32)(v16) - (uint32)(v15)) < r_u32((a2 + (2) * 4u)))))
        {
          v17 = r_u32((v10 + (20) * 4u));
          v18 = (sint32)((uint32)((sint32)r_u32((v12 + (31) * 4u))) + (uint32)(r_u32((v10 + (23) * 4u))));
          if ((r_u32((a1 + (1) * 4u)) < (sint32)((uint32)(v18) + (uint32)(v17))))
          {
            result = (0u - (uint32)(1));
            if (((sint32)((uint32)(v18) - (uint32)(v17)) < r_u32((a2 + (1) * 4u))))
              break;
          }
        }
      }
    }
    if (((sint32)r_u32(0x80077260u) < ++v9))
      return 0;
  }

  return result;
}


sint32 sub_8004D910(uint32 a1, uint32 a2, uint32 a3, sint32 a4, sint32 a5, sint32 a6)
{
    FUNCTION_MARKER(0x8004d910u, "SLES_008.65");
  sint32 v10;
  uint32 v11;
  sint32 v12;
  uint32 v13;
  sint32 v14;
  sint32 v15;
  sint32 result;
  v10 = 0;
  v11 = ((0x800736dcu + ((sint8)r_u8(a2)) * 4u));
  do
  {
    v12 = 0;
    v13 = ((0x800736dcu + ((sint8)r_u8(a3)) * 4u));
    do
    {
      v14 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80077644u)) + (uint32)(20))));
      if (((r_u16(a1) & 0xFFF0) != 0))
        v14 += (sint32)((uint32)(4) * (uint32)(((uint32)(((uint32)((r_u16(a1) & 0xFFF0)) + (uint32)((sint8)r_u8((uint32)(v13))))) + (uint32)((sint32)((uint32)(4) * (uint32)((sint8)r_u8((uint32)(v11))))))));
      v15 = a4;
      if (a4)
        v15 = sub_8004DAA4((sint8)(((uint32)(r_u8((uint32)(v13))) + (uint32)((sint32)((uint32)(4) * (uint32)(a5))))), (sint8)(((uint32)(r_u8((uint32)(v11))) + (uint32)((sint32)((uint32)(4) * (uint32)(a6))))), 2, (((uint32)((r_u16((uint32)((sint32)((uint32)(v14) + (uint32)(2)))) & 0xFFFC)) << (uint32)(16)) >> 14));
      if ((v15 != (0u - (uint32)(1))))
        sub_8004E028((sint32)((uint32)(((sint32)((uint32)(a5) << (uint32)(24)) >> 22)) + (uint32)((sint8)r_u8((uint32)(v13)))), (sint32)((uint32)(((sint32)((uint32)(a6) << (uint32)(24)) >> 22)) + (uint32)((sint8)r_u8((uint32)(v11)))), v14);
      ++v12;
      v13 = (uint32)(((uint32)(v13) + (1) * 1u));
    }
    while ((v12 < 4));
    result = (++v10 < 4);
    v11 = (uint32)(((uint32)(v11) + (1) * 1u));
  }
  while ((v10 < 4));
  return result;
}


sint32 sub_800123E4(void)
{
    FUNCTION_MARKER(0x800123e4u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80055884 */
    /* TODO: Bind external adapter for sub_80055874 */
    /* TODO: Bind external adapter for sub_800558B4 */
  sint32 i;
  sint32 result;
  sub_800558E4();
  w_u32(0x80089688, ob_draft_unresolved_call(0x80055884u, 4u, (0u - (uint32)(201326591)), 4, 0x2000, 0));
  w_u32(0x8008968C, ob_draft_unresolved_call(0x80055884u, 4u, (0u - (uint32)(201326591)), 0x8000, 0x2000, 0));
  w_u32(0x80089690, ob_draft_unresolved_call(0x80055884u, 4u, (0u - (uint32)(201326591)), 256, 0x2000, 0));
  w_u32(0x80089698, ob_draft_unresolved_call(0x80055884u, 4u, (0u - (uint32)(201326591)), 0x2000, 0x2000, 0));
  w_u32(0x80089718, ob_draft_unresolved_call(0x80055884u, 4u, (0u - (uint32)(268435439)), 4, 0x2000, 0));
  w_u32(0x8008971C, ob_draft_unresolved_call(0x80055884u, 4u, (0u - (uint32)(268435439)), 0x8000, 0x2000, 0));
  w_u32(0x80089720, ob_draft_unresolved_call(0x80055884u, 4u, (0u - (uint32)(268435439)), 256, 0x2000, 0));
  w_u32(0x800897A8, ob_draft_unresolved_call(0x80055884u, 4u, (0u - (uint32)(268435439)), 0x2000, 0x2000, 0));
  w_u32(0x800897D0, ob_draft_unresolved_call(0x80055884u, 4u, (0u - (uint32)(268435439)), 512, 0x2000, 0));
  sub_800558F4();
  sub_80063C1C(0);
  sub_80063C70();
  ob_draft_unresolved_call(0x80055874u, 0u);
  ob_draft_unresolved_call(0x800558b4u, 1u, r_u32(0x80089688));
  ob_draft_unresolved_call(0x800558b4u, 1u, r_u32(0x8008968C));
  ob_draft_unresolved_call(0x800558b4u, 1u, r_u32(0x80089690));
  ob_draft_unresolved_call(0x800558b4u, 1u, r_u32(0x80089698));
  ob_draft_unresolved_call(0x800558b4u, 1u, r_u32(0x80089718));
  ob_draft_unresolved_call(0x800558b4u, 1u, r_u32(0x8008971C));
  ob_draft_unresolved_call(0x800558b4u, 1u, r_u32(0x80089720));
  ob_draft_unresolved_call(0x800558b4u, 1u, r_u32(0x800897A8));
  ob_draft_unresolved_call(0x800558b4u, 1u, r_u32(0x800897D0));
  for (i = 3864; (i >= 0); i -= 552)
    w_u32((uint32)((sint32)((uint32)(i) - (uint32)(2146919124))), 1);

  result = 1;
  w_u32(0x80065B80u, 1);
  return result;
}


sint32 sub_8004D76C(uint32 a1, uint32 a2, uint32 a3, sint32 a4, sint32 a5, sint32 a6)
{
    FUNCTION_MARKER(0x8004d76cu, "SLES_008.65");
    /* TODO: Resolve meaningful argument carriers for sub_8004D910 without dropping supplied values */
  sint32 v13;
  uint32 v14;
  sint32 v15;
  sint32 v16;
  uint32 v17;
  sint32 v18;
  sint32 v19;
  sint32 result;
  v13 = 0;
  v14 = ((0x800736dcu + ((sint8)(r_u8((a2 + (1) * 1u)))) * 4u));
  do
  {
    v15 = 0;
    v16 = a5;
    v17 = ((0x800736dcu + ((sint8)(r_u8((a3 + (1) * 1u)))) * 4u));
    do
    {
      v18 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80077644u)) + (uint32)(16))));
      if (((r_u16(a1) & 0xFFF0) != 0))
        v18 += (sint32)((uint32)(2) * (uint32)(((uint32)(((uint32)((r_u16(a1) & 0xFFF0)) + (uint32)((sint8)r_u8((uint32)(v17))))) + (uint32)((sint32)((uint32)(4) * (uint32)((sint8)r_u8((uint32)(v14))))))));
      v19 = a6;
      if (a6)
        v19 = sub_8004DAA4((sint8)(((uint32)(r_u8((uint32)(v17))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8(a3)))))), (sint8)(((uint32)(r_u8((uint32)(v14))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8(a2)))))), 1, 0);
      if ((v19 != (0u - (uint32)(1))))
        ob_draft_unresolved_call(0x8004d910u, 3u, v18, a4, v16);
      v17 = (uint32)(((uint32)(v17) + (1) * 1u));
      ++v15;
      ++v16;
    }
    while ((v15 < 4));
    v14 = (uint32)(((uint32)(v14) + (1) * 1u));
    result = (++v13 < 4);
    ++a4;
  }
  while ((v13 < 4));
  return result;
}


sint32 sub_80024938(void)
{
    FUNCTION_MARKER(0x80024938u, "SLES_008.65");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Bind external adapter for sub_8001DF34 */
    /* TODO: Bind external adapter for sub_8004B70C */
    /* TODO: Bind external adapter for sub_80045D44 */
    /* TODO: Bind external adapter for sub_80054CA8 */
    /* TODO: Bind external adapter for sub_80034530 */
    /* TODO: Bind external adapter for sub_800544EC */
    /* TODO: Bind external adapter for sub_80063FF8 */
    /* TODO: Bind external adapter for sub_8001B048 */
  sint32 v0;
  sint32 v1;
  uint32 v2;
  sint32 v3;
  uint32 v4;
  sint32 v5;
  if (((uint8)((sint8)r_u8(0x8006C231u)) >= 0x14u))
  {
    v2 = 1;
    w_u32(0x8008CEBC, ((uint32)((((uint32)((uint8)((sint8)r_u8(0x8006C231u))) - (uint32)(20)) % 3)) + (uint32)(3)));
    w_u32(0x8007FAD0, r_u32(0x8008CEBC));
  }
  else
  {
    v0 = (sint32)((uint32)(5) * (uint32)(((uint8)((sint8)r_u8(0x8006C231u)) >> 2)));
    v1 = (sint32)((uint32)((sint32)((uint32)(v0) + (uint32)(((sint8)r_u8(0x8006C231u) & 1)))) + (uint32)(6));
    w_u32(0x8008CEBC, v1);
    w_u32(0x8007FAD0, v1);
    v2 = ((v1 < 6) || (v1 != (sint32)((uint32)(v0) + (uint32)(9))));
  }
  sub_8001F9B0(r_u32(0x8008CEBC), v2);
  sub_8001DF58((sint8)r_u8(0x8006C22Eu));
  ob_draft_unresolved_call(0x8001df34u, 1u, (sint8)r_u8(0x8006C22Du));
  w_u32(0x800C546C, 0);
  v3 = 0;
  if ((sint8)r_u8(0x8006C230u))
  {
    v4 = (sint32)r_u32(0x8006C138u);
    do
    {
      w_u32(v4, 0);
      ++v3;
      ((v4 += 4u));
    }
    while ((v3 < (uint8)((sint8)r_u8(0x8006C230u))));
  }
  w_u32(0x8006C134u, 0);
  ob_draft_unresolved_call(r_u32(0x8009450C), 3u, 0, 0, 0);
  ob_draft_unresolved_call(r_u32(0x800AE0C4), 0u);
  ob_draft_unresolved_call(r_u32(0x800C190C), 0u);
  ob_draft_unresolved_call(0x8004b70cu, 0u);
  w_u8(0x800C9980, 0);
  w_u8(0x800C99B8, 0);
  w_u32(0x800882BC, 0);
  w_u32(0x8007F9B0, 0);
  w_u32(0x80086A40, 0);
  w_u32(0x80089B78, 0);
  w_u32(0x800C8358, 0);
  w_u32(0x800D5C8C, 0);
  w_u16(0x80089B24, 0);
  ob_draft_unresolved_call(r_u32(0x800A309C), 0u);
  ob_draft_unresolved_call(0x80045d44u, 0u);
  ob_draft_unresolved_call(0x80054ca8u, 0u);
  ob_draft_unresolved_call(0x80034530u, 0u);
  ob_draft_unresolved_call(r_u32(0x800923F8), 0u);
  ob_draft_unresolved_call(r_u32(0x800ADAC8), 0u);
  sub_80019EE0(0);
  ob_draft_unresolved_call(r_u32(0x800C15E4), 0u);
  /* TODO Recover incoming carrier left by external 800C15E4 */
  v5 = (sint32)ob_native_missing_value(0x80024938u, "800544EC incoming a0");
  ob_draft_unresolved_call(0x800544ecu, 1u, v5);
  ob_draft_unresolved_call(0x80063ff8u, 1u, 0);
  ob_draft_unresolved_call(0x8001b048u, 1u, 0);
  sub_800224A0();
  return sub_800224A0();
}


uint32 sub_800487B8(uint32 a1)
{
    FUNCTION_MARKER(0x800487b8u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80048FEC */
    /* TODO: Bind external adapter for sub_80048B60 */
  uint32 v2;
  sint32 v3;
  uint32 v4;
  uint32 result;
  v2 = (uint32)(r_u32((a1 + (5) * 4u)));
  v3 = ob_draft_unresolved_call(0x80048fecu, 0u);
  if ((v3 != 0x7FFFFFFF))
  {
    v4 = r_u32(v2);
    w_u32((v2 + (1) * 4u), v3);
    result = (v4 & 0xFFFF7FFF);
    w_u32(v2, result);
    return result;
  }
  w_u32(v2, ((uint32)(r_u32(v2)) | (uint32)(0x8000u)));
  if (((r_u32((a1 + (15) * 4u)) || r_u32((a1 + (16) * 4u))) || r_u32((a1 + (17) * 4u))))
  {
    ob_draft_unresolved_call(0x80048b60u, 1u, a1);
    if (((((sint32)(r_u32((a1 + (21) * 4u))) < (sint32)(r_u32((a1 + (6) * 4u)))) && ((sint32)(r_u32((a1 + (22) * 4u))) < (sint32)(r_u32((a1 + (7) * 4u))))) && ((sint32)(r_u32((a1 + (23) * 4u))) < (sint32)(r_u32((a1 + (8) * 4u))))))
    {
      if ((((r_u32((a1 + (24) * 4u)) || ((r_u32((a1 + (18) * 4u)) & 0x80000000) != 0)) && (r_u32((a1 + (25) * 4u)) || ((r_u32((a1 + (19) * 4u)) & 0x80000000) != 0))) && (r_u32((a1 + (26) * 4u)) || ((r_u32((a1 + (20) * 4u)) & 0x80000000) != 0))))
      {
        sub_80048D2C(a1);
        result = ((uint32)(r_u32((a1 + (27) * 4u))) + (uint32)(1));
      }
      else
      {
        result = 2147483393;
      }
    }
    else
    {
      result = 2147483393;
    }
  }
  else
  {
    if (((((r_u32((a1 + (18) * 4u)) & 0x80000000) != 0) && ((r_u32((a1 + (19) * 4u)) & 0x80000000) != 0)) && ((r_u32((a1 + (20) * 4u)) & 0x80000000) != 0)))
    {
      result = r_u32(a1);
      w_u32((v2 + (1) * 4u), r_u32(a1));
      return result;
    }
    result = 2147483393;
  }
  w_u32((v2 + (1) * 4u), result);
  return result;
}


sint32 sub_80042424(uint32 a1)
{
    FUNCTION_MARKER(0x80042424u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80040E28 */
    /* TODO: Bind external adapter for sub_800257A0 */
    uint32 local_objects = ob_draft_scratch_acquire(40u);
  sint32 v2;
  uint32 v3;
  sint32 v4;
  sint32 v5;
  uint32 v6;
  sint32 v7;
  sint32 v8;
  uint32 v9;
  sint32 v10;
  uint32 v11;
  sint32 result;
  sint32 v13;
  ;
  v2 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(48))));
  if (v2)
    sub_80042424(v2);
  v3 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))));
  if ((((sint32)r_u32(v3) & 3) != 0))
  {
    v4 = sub_800257CC(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24)))));
  }
  else
  {
    (w_u16((uint32)((sint32)((uint32)((sint32)r_u32(v3)) - (uint32)(6))), (r_u16((uint32)((sint32)((uint32)((sint32)r_u32(v3)) - (uint32)(6)))) + 1u)), r_u16((uint32)((sint32)((uint32)((sint32)r_u32(v3)) - (uint32)(6)))));
    v4 = (sint32)r_u32(v3);
  }
  v5 = (r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(2)))) & 0x8000);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))), v4);
  if (v5)
  {
    ob_draft_unresolved_call(0x80040e28u, 1u, a1);
    v6 = v3;
  }
  else
  {
    v7 = 0;
    if (r_u32((uint32)((sint32)((uint32)(v4) + (uint32)(72)))))
    {
      do
      {
        v8 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))));
        if ((r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(20)))) >= r_u32((uint32)((sint32)((uint32)(v8) + (uint32)(76))))))
          break;
        w_u32(((local_objects + 0u) + (v7) * 4u), r_u32((uint32)((sint32)((uint32)(v8) + (uint32)(72)))));
        v9 = r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))))) + (uint32)(72))));
        if (((r_u32(v9) & 3) != 0))
        {
          v10 = sub_800257CC((sint32)(v9));
        }
        else
        {
          (w_u16((uint32)(((uint32)(r_u32(v9)) - (uint32)(6))), (r_u16((uint32)(((uint32)(r_u32(v9)) - (uint32)(6)))) + 1u)), r_u16((uint32)(((uint32)(r_u32(v9)) - (uint32)(6)))));
          v10 = r_u32(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))))) + (uint32)(72)))));
        }
        w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))), v10);
        ++v7;
      }
      while (r_u32((uint32)((sint32)((uint32)(v10) + (uint32)(72)))));
      sub_8003858C(a1);
      if ((v7 > 0))
      {
        v11 = (uint32)((((local_objects + 0u) + ((sint32)((uint32)(v7) - (uint32)(1))) * 4u)));
        do
        {
          --v7;
          ob_draft_unresolved_call(0x800257a0u, 1u, r_u32(((v11 -= 4u) + 4u)));
        }
        while ((v7 > 0));
        v6 = v3;
        goto LABEL_20;
      }
    }
    else
    {
      sub_8003858C(a1);
    }
    v6 = v3;
  }
  LABEL_20:
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))), v6);

  result = ob_draft_unresolved_call(0x800257a0u, 1u, v6);
  v13 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(44))));
  if (v13)
    { uint32 draft_return = sub_80042424(v13); ob_draft_scratch_release(local_objects);  return draft_return; }
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


sint32 sub_8004719C(uint32 a1, sint32 a2)
{
    FUNCTION_MARKER(0x8004719cu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80047A60 */
  sint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  uint32 v9;
  uint32 i;
  sint32 v11;
  sint32 v12;
  sint32 v13;
  sint32 v14;
  v4 = r_u32((a1 + (45) * 4u));
  v5 = r_u32((a1 + (48) * 4u));
  v6 = 0;
  w_u32((a1 + (47) * 4u), 0x7FFFFFFF);
  v7 = (sint32)r_u32(0x80077140u);
  w_u32((a1 + (48) * 4u), (0u - (uint32)(1)));
  v8 = ((v4 == 1)) ? (v5) : (0);
  v9 = (uint32)((sint32)((uint32)(v7) + (uint32)((sint32)((uint32)(4) * (uint32)(v8)))));
  for (i = (uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(r_u32((a1 + (6) * 4u))))) + (uint32)((sint32)r_u32(0x80077148u)))))) + (uint32)((sint32)((uint32)(8) * (uint32)(v8))))); v4; ++v8)
  {
    v11 = r_u32(v9);
    if ((r_u32(v9) && ((r_u32(i) & 0x8000) != 0)))
    {
      sub_800477B8(a1, r_u32(v9), a2, i);
      if (((r_u32(i) & 0x8000) != 0))
      {
        v12 = r_u32((i + (1) * 4u));
        if ((v12 < (sint32)r_u32((a1 + (47) * 4u))))
        {
          w_u32((a1 + (47) * 4u), v12);
          w_u32((a1 + (48) * 4u), r_u32((uint32)((sint32)((uint32)(v11) + (uint32)(24)))));
        }
        ++v6;
      }
      else
      {
        v13 = r_u32((i + (1) * 4u));
        if ((v13 < (sint32)r_u32((a1 + (49) * 4u))))
        {
          w_u32((a1 + (49) * 4u), v13);
          w_u32((a1 + (50) * 4u), r_u32((uint32)((sint32)((uint32)(v11) + (uint32)(24)))));
        }
        (w_u32((uint32)((sint32)((uint32)(v11) + (uint32)(184))), (r_u32((uint32)((sint32)((uint32)(v11) + (uint32)(184)))) - 1u)), r_u32((uint32)((sint32)((uint32)(v11) + (uint32)(184)))));
      }
      if (((--v4 == 1) && (v8 < v5)))
      {
        v14 = (sint32)((uint32)((sint32)((uint32)(v5) - (uint32)(v8))) - (uint32)(1));
        v8 = (sint32)((uint32)(v5) - (uint32)(1));
        i += ((sint32)((uint32)(2) * (uint32)(v14))) * 4u;
        v9 += (v14) * 4u;
      }
    }
    i += (2) * 4u;
    ((v9 += 4u));
  }

  w_u32((a1 + (45) * 4u), v6);
  return ob_draft_unresolved_call(0x80047a60u, 1u, a1);
}


sint32 sub_80027274(uint32 a1, sint32 a2)
{
    FUNCTION_MARKER(0x80027274u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8002755C */
    /* TODO: Bind external adapter for sub_800277D0 */
    /* TODO: Bind external adapter for nullsub_22 */
    /* TODO: Bind external adapter for sub_8002785C */
    /* TODO: Bind external adapter for sub_80026950 */
    /* TODO: Bind external adapter for sub_80027810 */
  uint32 v5;
  uint32 v6;
  sint32 v7;
  sint32 i;
  sint32 v9;
  sint32 v10;
  sint32 v11;
  sint32 v12;
  if ((((r_u8((uint32)((sint32)((uint32)(a1) + (uint32)(32)))) & 1) != 0) && !(r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(34)))))))
    return ob_draft_unresolved_call(0x8002755cu, 0u);
  v5 = ((sint32)((uint32)(a2) + (uint32)(7)) & 0xFFFFFFFC);
  ob_draft_unresolved_call(0x800277d0u, 2u, a1, 2);
  v6 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(16))));
  v7 = a1;
  LABEL_5:
  for (i = (v6 < v5); i; i = (v6 < v5))
  {
    v9 = r_u32((uint32)((sint32)((uint32)(v7) + (uint32)(4))));
    if (((r_u8((uint32)((sint32)((uint32)(v9) + (uint32)(32)))) & 0x80) == 0))
    {
      if ((r_u8(v9 + 32u) & 3) == 0 || r_u16(v9 + 34u) || ((v7 = r_u32(v7 + 4u)), r_u16(v9 + 36u)))
      {
        v7 = v9;
        ob_draft_unresolved_call(0x800279ccu, 0u);
      }
      v6 += (sint32)((uint32)(40) + (uint32)(r_u32((uint32)((sint32)((uint32)(v7) + (uint32)(16))))));
      w_u16((uint32)((sint32)((uint32)(v7) + (uint32)(34))), ((uint32)(r_u16((uint32)((sint32)((uint32)(v9) + (uint32)(34))))) + (uint32)(1)));
      goto LABEL_5;
    }
    ob_draft_unresolved_call(0x8002785cu, 1u, r_u32((uint32)((sint32)((uint32)(v7) + (uint32)(4)))));
    if ((v5 < ((uint32)(((uint32)(v6) + (uint32)(r_u32((uint32)((sint32)((uint32)(v9) + (uint32)(16))))))) + (uint32)(40))))
    {
      v10 = 56;
      if ((((uint32)(v5) - (uint32)(v6)) >= 0x38))
        v10 = ((uint32)(v5) - (uint32)(v6));
      sub_800271EC(v9, (sint32)((uint32)(v10) - (uint32)(40)));
    }
    v11 = r_u32((uint32)((sint32)((uint32)(v9) + (uint32)(16))));
    v6 += (sint32)((uint32)(40) + (uint32)(v11));
    w_u32((uint32)((sint32)((uint32)(v7) + (uint32)(20))), ((uint32)(r_u32((uint32)((sint32)((uint32)(v7) + (uint32)(20))))) + (uint32)((sint32)((uint32)(40) + (uint32)(v11)))));
    ob_draft_unresolved_call(0x80026950u, 1u, v7);
  }


  while ((r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(16)))) < v5))
  {
    v12 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(4))));
    (w_u16((uint32)((sint32)((uint32)(v12) + (uint32)(34))), (r_u16((uint32)((sint32)((uint32)(v12) + (uint32)(34)))) - 1u)), r_u16((uint32)((sint32)((uint32)(v12) + (uint32)(34)))));
    sub_8002744C(v12);
    ob_draft_unresolved_call(0x80026950u, 1u, a1);
  }

  sub_800271EC(a1, a2);
  return ob_draft_unresolved_call(0x80027810u, 2u, a1, 2);
}


sint32 sub_80022E78(void)
{
    FUNCTION_MARKER(0x80022e78u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8002CCC8 */
    /* TODO: Bind external adapter for sub_8005BAE8 */
    /* TODO: Bind external adapter for sub_8005BA48 */
  w_u32(0x800896C0, 256);
  w_u32(0x800881A0, 384);
  ob_draft_unresolved_call(0x8002ccc8u, 7u, 0x80084A58u, 0xFFFFFF40u, 0xFFFFFF80u, 192u, 128u, 192u, 128u);
  ob_draft_unresolved_call(0x8005bae8u, 1u, (0u - (uint32)(2146908472)));
  ob_draft_unresolved_call(0x8005bae8u, 1u, (0u - (uint32)(2146906256)));
  w_u8(0x8008C6CC, 0);
  w_u8(0x8008C6CD, 0);
  w_u8(0x8008C6CE, 0);
  w_u16(0x8008C6D0, 0);
  w_u16(0x8008C6D2, 0);
  w_u16(0x8008C6D4, 384);
  w_u16(0x8008C6D6, 0);
  w_u16(0x8008C6D8, 0);
  w_u16(0x8008C6DA, 256);
  w_u16(0x8008C6DC, 384);
  w_u16(0x8008C6DE, 256);
  w_u8(0x8008CF74, 0);
  w_u8(0x8008CF75, 0);
  w_u8(0x8008CF76, 0);
  w_u16(0x8008CF78, 0);
  w_u16(0x8008CF7A, 0);
  w_u16(0x8008CF7C, 384);
  w_u16(0x8008CF7E, 0);
  w_u16(0x8008CF80, 0);
  w_u16(0x8008CF82, 256);
  w_u16(0x8008CF84, 384);
  w_u16(0x8008CF86, 256);
  ob_draft_unresolved_call(0x8005bae8u, 1u, (0u - (uint32)(2146920296)));
  w_u8(0x8008989C, 0);
  w_u8(0x8008989D, 0);
  w_u8(0x8008989E, 0);
  w_u16(0x800898A0, 0);
  w_u16(0x800898A2, 0);
  w_u16(0x800898A4, 384);
  w_u16(0x800898A6, 0);
  w_u16(0x800898A8, 0);
  w_u16(0x800898AA, 256);
  w_u16(0x800898AC, 384);
  w_u16(0x800898AE, 256);
  ob_draft_unresolved_call(0x800425ecu, 7u, 0x8008CED0u, 0xFFFFFF40u, 0xFFFFFF80u, 192u, 128u, 192u, 128u);
  ob_draft_unresolved_call(0x8005bae8u, 1u, (0u - (uint32)(2146920704)));
  w_u8(0x80089704, 0);
  w_u8(0x80089705, 0);
  w_u8(0x80089706, 0);
  w_u16(0x80089708, 0);
  w_u16(0x8008970A, 0);
  w_u16(0x8008970C, 384);
  w_u16(0x8008970E, 0);
  w_u16(0x80089710, 0);
  w_u16(0x80089712, 256);
  w_u16(0x80089714, 384);
  w_u16(0x80089716, 256);
  ob_draft_unresolved_call(0x8005bae8u, 1u, (0u - (uint32)(2146920072)));
  w_u8(0x8008997C, 0);
  w_u8(0x8008997D, 0);
  w_u8(0x8008997E, 0);
  w_u16(0x80089980, 0);
  w_u16(0x80089982, 0);
  w_u16(0x80089984, 384);
  w_u16(0x80089986, 0);
  w_u16(0x80089988, 0);
  w_u16(0x8008998A, 256);
  w_u16(0x8008998C, 384);
  w_u16(0x8008998E, 256);
  ob_draft_unresolved_call(0x8005ba48u, 2u, (0u - (uint32)(2146920704)), 1);
  return ob_draft_unresolved_call(0x8005ba48u, 2u, (0u - (uint32)(2146920072)), 1);
}


