#include "draft_signatures.h"
#include "native_runtime.h"
#include "native_cd_toc.h"
#include "psx.h"

/* Unverified draft bodies */

uint32 sub_80031FEC(void)
{
    FUNCTION_MARKER(0x80031fecu, "SLES_008.65");
  sint32 v0;
  sint32 v1;
  sint32 v2;
  sint32 v3;
  sint32 result;
  v0 = sub_8002D98C(480);
  v1 = 0;
  v2 = 0;
  v3 = (sint32)(0u - (uint32)(2146906144));
  w_u32(0x80077404u, v0);
  w_u16(0x80077550u, 0);
  w_u16(0x80077346u, 0);
  w_u16(0x800775a2u, 0);
  w_u16(0x80077638u, 0);
  do
  {
    w_u16((uint32)(v3), v1);
    w_u32((uint32)((sint32)((uint32)(v2) - (uint32)(2146926168))), 0);
    v2 = ((uint32)(v2) + (uint32)(8));
    result = ((sint32)(++v1) < (sint32)(24));
    v3 = ((uint32)(v3) + (uint32)(2));
  }
  while (((sint32)(v1) < (sint32)(24)));
  w_u16(0x800773c4u, 0);
  return result;
}


uint32 sub_8004CDF4(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8004cdf4u, "SLES_008.65");
  sint32 result;
  sint32 v5;
  sint32 v6;
  result = sub_80041B74();
  v5 = r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(a1))) - (uint32)(2146941544))));
  v6 = 0;
  if (v5)
  {
    result = sub_8004CE64(v5, a2);
    v6 = result;
  }
  if (v6)
    return sub_800423D8();
  return result;
}


uint32 sub_800170F8(uint32 a1)
{
    FUNCTION_MARKER(0x800170f8u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80055D74 */
  sint32 v1;
  uint32 v2;
  uint32 v3;
  sint32 result;
  w_u32(0x80065ff8u, a1);
  w_u32(0x80065ffcu, (sint32)r_u32(0x800117c4u));
  v1 = a1;
  ob_draft_unresolved_call(0x80055d74u, 0u);
  v2 = ((0x8006600cu + (v1) * 4u));
  v3 = ((0x80066000u + (v1) * 4u));
  do
  {
    result = sub_800171EC(r_u32(v2), r_u32(0x80065FFCu));
    w_u32(v3, result);
  }
  while (!result);
  ob_native_overlay_loaded(a1);
  return result;
}


uint32 sub_8002D98C(uint32 a1)
{
    FUNCTION_MARKER(0x8002d98cu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8002DB80 */
  sint32 result;
  if (((sint32)r_u32(0x80077358u) < (uint32)(((uint32)(a1) + (uint32)((sint32)r_u32(0x80077354u))))))
  {
    ob_draft_unresolved_call(0x8002db80u, 4u, 22, 0x800109B4u, 0, 0);
    w_u32(0x80077474u, 0);
    return 0;
  }
  else
  {
    result = (sint32)r_u32(0x80077354u);
    w_u32(0x80077584u, (sint32)r_u32(0x80077354u));
    w_u32(0x80077354u, ((uint32)((sint32)r_u32(0x80077354u)) + (uint32)((((uint32)(a1) + (uint32)(3)) & 0xFFFFFFFC))));
  }
  return result;
}


uint32 sub_80021A38(uint32 a1)
{
    FUNCTION_MARKER(0x80021a38u, "SLES_008.65");
  sint32 result;
  uint32 incoming_result;
  if ((a1 == 1))
    incoming_result = sub_80026694((0x8006c0d4u), 196608, 0);
  else
  {
    w_u32(0x8006c0d4u, ((sint32)((uint32)((sint32)((uint32)((sint32)r_u32((0x80065ffcu + (0) * 4u))) + (uint32)((sint32)r_u32((0x80065ffcu + ((sint32)((uint32)((sint32)r_u32(0x80065ff8u)) + (uint32)(1))) * 4u))))) + (uint32)(3)) & 0xFFFFFFFC));
    incoming_result = r_u32(0x8006C0D4u);
  }
  result = ob_fill_words(r_u32(0x8006C0D4u), 196608u, 0u, incoming_result);
  w_u32(0x8008444C, a1);
  return result;
}


uint32 sub_80051450(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80051450u, "SLES_008.65");
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    uint32 local_objects = ob_draft_scratch_acquire(8u);
  ;
  sint32 v5;
  ;
  w_u32(local_objects + 0u, r_u32(a1));
  if (!(sint32)r_u32(0x800775ccu))
    ob_draft_unresolved_call(0x80051450u, 2u, 7u, 0);
  if ((((sint32)r_u32(0x800775ccu) == (sint32)(0u - (uint32)(1))) && ((sint32)r_u32(local_objects + 0u) == 0x80000000)))
    ob_draft_unresolved_call(0x80051450u, 2u, 6u, 0);
  v5 = ((sint32)((sint32)r_u32(local_objects + 0u)) / (sint32)((sint32)r_u32(0x800775ccu)));
  w_u32(local_objects + 4u, r_u32((a1 + (2) * 4u)));
  if (!(sint32)r_u32(0x800775ccu))
    ob_draft_unresolved_call(0x80051450u, 2u, 7u, 0);
  if ((((sint32)r_u32(0x800775ccu) == (sint32)(0u - (uint32)(1))) && ((sint32)r_u32(local_objects + 4u) == 0x80000000)))
    ob_draft_unresolved_call(0x80051450u, 2u, 6u, 0);
  { uint32 draft_return = sub_800514E4(v5, ((sint32)((sint32)r_u32(local_objects + 4u)) / (sint32)((sint32)r_u32(0x800775ccu))), a2); ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_800271EC(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x800271ecu, "SLES_008.65");
  sint32 v3;
  sint32 v4;
  uint32 v5;
  sint32 result;
  uint32 v7;
  v3 = ((uint32)(((0u - (uint32)(a2)) & 3)) + (uint32)(4));
  v4 = ((uint32)(a2) + (uint32)(v3));
  v5 = ((uint32)(r_u32((uint32)(((uint32)(a1) + (uint32)(16))))) - (uint32)(v4));
  result = (v5 < 0x38);
  if ((v5 < 0x38))
  {
    w_u32((uint32)(((uint32)(a1) + (uint32)(20))), (sint32)((uint32)(v3) + (uint32)(v5)));
  }
  else
  {
    w_u32((uint32)(((uint32)(a1) + (uint32)(16))), v4);
    v7 = (uint32)(((uint32)(((uint32)(a1) + (uint32)(v4))) + (uint32)(40)));
    sub_8002691C((sint32)(v7), a1, ((uint32)(v5) - (uint32)(40)));
    result = sub_80027154(v7);
    w_u32((uint32)(((uint32)(a1) + (uint32)(20))), v3);
  }
  return result;
}


uint32 sub_800231E4(void)
{
    FUNCTION_MARKER(0x800231e4u, "SLES_008.65");
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Bind external adapter for sub_80064028 */
    /* TODO: Recover missing meaningful carriers for sub_80013908 before binding the native call */
    uint32 local_objects = ob_draft_scratch_acquire(24u);
  sint32 v0;
  sint32 result;
  ;
  if (r_u8(0x8008AE68))
  {
    v0 = ((uint32)((sint32)r_u32(0x800882BC)) - (uint32)((sint32)r_u32(0x80078DC4)));
    if ((((uint32)((sint32)r_u32(0x800882BC)) - (uint32)((sint32)r_u32(0x80078DC4))) <= 0))
      v0 = 1;
    if (!v0)
      ob_draft_unresolved_call(0x800231e4u, 2u, 7u, 0);
    ob_draft_unresolved_call(0x80064028u, 3u, (local_objects + 0u), 0x80010880u, (sint32)(0u - (uint32)(1000)));
    ob_draft_unresolved_call(0x80013908u, 2u, (local_objects + 0u), 282);
  }
  result = (sint32)r_u32(0x800882BC);
  w_u32(0x80078DC4, (sint32)r_u32(0x800882BC));
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80054264(void)
{
    FUNCTION_MARKER(0x80054264u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80063FD8 */
    /* TODO: Bind external adapter for sub_80065AC4 */
    /* TODO: Bind external adapter for sub_80065AE4 */
    /* TODO: Bind external adapter for sub_80059CA8 */
  sint32 result;
  result = (sint32)((uint32)((sint32)r_u32(0x80073a38u)) + (uint32)(1));
  w_u32(0x80073a38u, result);
  if ((result == 1))
  {
    ob_draft_unresolved_call(0x80063fd8u, 3u, (sint32)(0u - (uint32)(2146960896)), 0, 128);
    ob_draft_unresolved_call(0x80063fd8u, 3u, (sint32)(0u - (uint32)(2146925800)), 0, 128);
    sub_8005491C();
    w_u32(0x80084440, sub_80054A24(0x80053e2cu, 60));
    ob_draft_unresolved_call(0x80065ac4u, 4u, (sint32)(0u - (uint32)(2146907352)), 34, (sint32)(0u - (uint32)(2146906480)), 34);
    ob_draft_unresolved_call(0x80065ae4u, 0u);
    ob_draft_unresolved_call(0x80059ca8u, 1u, 0);
    result = (sint32)r_u32(0x80084440);
    w_u32((uint32)(((uint32)((sint32)r_u32(0x80084440)) + (uint32)(12))), 0);
    w_u32((uint32)((sint32)((uint32)(result) + (uint32)(16))), 0);
  }
  return result;
}


uint32 sub_8001E1E0(void)
{
    FUNCTION_MARKER(0x8001e1e0u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80062EE8 */
    uint32 local_objects = ob_draft_scratch_acquire(8u);
  sint32 v0;
  sint32 v1;
  sint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 result;
  ;
  sint16 v7;
  sint16 v8;
  v0 = 0;
  v1 = 0;
  v2 = (sint32)(0u - (uint32)(2146989068));
  v3 = (sint32)(0u - (uint32)(2146989072));
  do
  {
    w_u32(((local_objects + 0u) + (0) * 4u), (sint32)((uint32)(1) << (uint32)(v0)));
    w_u32(((local_objects + 0u) + (1) * 4u), 3);
    v4 = r_u32((uint32)(v3));
    v3 = ((uint32)(v3) + (uint32)(8));
    ++v0;
    v7 = v4;
    v8 = r_u32((uint32)(v2));
    w_u32((uint32)((sint32)((uint32)(v1) - (uint32)(2146991448))), (sint16)(v4));
    w_u32((uint32)((sint32)((uint32)(v1) - (uint32)(2146991444))), v8);
    v2 = ((uint32)(v2) + (uint32)(8));
    ob_draft_unresolved_call(0x80062ee8u, 1u, (local_objects + 0u));
    result = ((sint32)(v0) < (sint32)(24));
    v1 = ((uint32)(v1) + (uint32)(28));
  }
  while (((sint32)(v0) < (sint32)(24)));
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80046CDC(uint32 a1)
{
    FUNCTION_MARKER(0x80046cdcu, "SLES_008.65");
    /* TODO: IDA supplied excess carriers to sub_80047B24; frozen prototype governs the draft call */
  sint32 v2;
  sint32 v3;
  sint32 v4;
  uint32 v5;
  sint32 v6;
  v2 = (sint32)r_u32(0x80077140u);
  v3 = r_u32((a1 + (6) * 4u));
  w_u32((a1 + (49) * 4u), 0x7FFFFFFF);
  w_u32((a1 + (47) * 4u), 0x7FFFFFFF);
  v4 = (sint32)r_u32(0x80077148u);
  w_u32((a1 + (50) * 4u), (sint32)(0u - (uint32)(1)));
  w_u32((a1 + (48) * 4u), (sint32)(0u - (uint32)(1)));
  w_u32((a1 + (45) * 4u), 0);
  v5 = r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(v3))) + (uint32)(v4))));
  v6 = 0;
  if (((sint32)(v3) > (sint32)(0)))
  {
    do
    {
      if (((r_u32(v5) & 0x8000) != 0))
        (w_u32((uint32)(((uint32)(r_u32((uint32)(v2))) + (uint32)(184))), (r_u32((uint32)(((uint32)(r_u32((uint32)(v2))) + (uint32)(184)))) - 1u)), r_u32((uint32)(((uint32)(r_u32((uint32)(v2))) + (uint32)(184)))));
      w_u32(v5, 128);
      w_u32((v5 + (1) * 4u), 0x7FFFFFFF);
      v5 += (2) * 4u;
      ++v6;
      v2 = ((uint32)(v2) + (uint32)(4));
    }
    while ((v6 < (sint32)r_u32((a1 + (6) * 4u))));
  }
  return sub_80047B24(a1);
}


void sub_8004A48C(uint32 a1)
{
    FUNCTION_MARKER(0x8004a48cu, "SLES_008.65");
    /* TODO: Recover missing meaningful carriers for sub_8002DA68 before binding the native call */
  sint32 v2;
  v2 = (sint32)r_u32(0x80077354u);
  sub_800352B4((uint32)((0x80073900u)));
  w_u32(0x80077574u, (sint32)(0u - (uint32)(2146960680)));
  sub_8004E310((0x80073900u), a1);
  ob_draft_unresolved_call(0x8002da68u, 1u, v2);
  sub_800352B4((uint32)((0x80073954u)));
  w_u32(0x80077574u, (sint32)(0u - (uint32)(2146960488)));
  sub_8004E310((0x80073954u), a1);
  ob_draft_unresolved_call(0x8002da68u, 1u, v2);
  sub_800352B4((uint32)((0x800739a8u)));
  w_u32(0x80077574u, (sint32)(0u - (uint32)(2146960296)));
  sub_8004E310((0x800739a8u), a1);
  ob_draft_unresolved_call(0x8002da68u, 1u, v2);
}


uint32 sub_80034910(uint32 a1)
{
    FUNCTION_MARKER(0x80034910u, "SLES_008.65");
  sint32 v2;
  sint16 v3;
  sint32 v4;
  sint16 v5;
  sint32 result;
  v2 = r_u32(a1);
  v3 = r_u16((uint32)(((uint32)(r_u32(a1)) + (uint32)(6))));
  w_u32(0x80077578u, 0);
  w_u32(0x8007742cu, 0);
  w_u32(0x80077464u, 0);
  w_u32(0x800773a8u, 0);
  if (((v3 & 0xE000) != 0))
    sub_80033FB0(v2);
  v4 = sub_80027D78(r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(16)))));
  v5 = sub_80027D78(r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(20)))));
  sub_800256CC(r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(16)))));
  sub_800256CC(r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(20)))));
  result = sub_80026758(a1);
  w_u32(a1, (sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(v4) << (uint32)(17))) + (uint32)((sint32)((uint32)(4) * (uint32)((v5 & 0x7FFF)))))) + (uint32)(2)));
  return result;
}


uint32 sub_800444F4(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x800444f4u, "SLES_008.65");
  sint32 v4;
  sint32 v5;
  sint32 v6;
  sint16 v7;
  uint32 result;
  v4 = r_u32((uint32)(((uint32)(a1) + (uint32)(52))));
  sub_800454BC(v4);
  sub_800455DC(v4, a2);
  sub_8002F9C4(((uint32)(a1) + (uint32)(64)), (sint32)((uint32)(v4) + (uint32)(54)));
  sub_8002FAA8((uint32)(((uint32)(a1) + (uint32)(64))), (uint32)((sint32)((uint32)(v4) + (uint32)(108))));
  v5 = r_u32((uint32)(((uint32)(a1) + (uint32)(148))));
  v6 = r_u32((uint32)(((uint32)(a1) + (uint32)(152))));
  v7 = r_u16((uint32)(((uint32)(a1) + (uint32)(160))));
  w_u32((uint32)(((uint32)(a1) + (uint32)(100))), r_u32((uint32)(((uint32)(a1) + (uint32)(144)))));
  w_u32((uint32)(((uint32)(a1) + (uint32)(104))), v5);
  w_u32((uint32)(((uint32)(a1) + (uint32)(108))), v6);
  w_u16((uint32)(((uint32)(a1) + (uint32)(140))), v7);
  if (((r_u32((uint32)((sint32)((uint32)(v4) + (uint32)(160)))) & 4) != 0))
    result = (r_u32((uint32)(((uint32)(a1) + (uint32)(112)))) | 0x100);
  else
    result = (r_u32((uint32)(((uint32)(a1) + (uint32)(112)))) & 0xFFFFFEFF);
  w_u32((uint32)(((uint32)(a1) + (uint32)(112))), result);
  return result;
}


uint32 sub_80046D98(uint32 a1)
{
    FUNCTION_MARKER(0x80046d98u, "SLES_008.65");
    /* TODO: Recover missing meaningful carriers for sub_80047450 before binding the native call */
  sint32 v1;
  sint32 v2;
  uint32 v3;
  uint32 v4;
  sint32 v5;
  sint32 result;
  sint32 i;
  sint32 v8;
  uint32 v9;
  v1 = r_u32((uint32)(((uint32)(a1) + (uint32)(24))));
  v2 = (sint32)((uint32)((sint32)((uint32)(4) * (uint32)(v1))) + (uint32)(4));
  v3 = (uint32)((sint32)((uint32)((sint32)r_u32(0x80077140u)) + (uint32)(v2)));
  v4 = (uint32)((sint32)((uint32)((sint32)r_u32(0x80077148u)) + (uint32)(v2)));
  v5 = (sint32)((uint32)(v1) + (uint32)(1));
  result = ((sint32)((sint32)r_u32(0x80077260u)) < (sint32)((sint32)((uint32)(v1) + (uint32)(1))));
  for (i = (sint32)((uint32)(8) * (uint32)(v1)); ((sint32)((sint32)r_u32(0x80077260u)) >= (sint32)(v5)); ((v3 += 4u)))
  {
    v8 = (sint32)r_u32(v3);
    if ((sint32)r_u32(v3))
    {
      v9 = (uint32)(((uint32)(r_u32(v4)) + (uint32)(i)));
      w_u32(v9, 128);
      w_u32((v9 + (1) * 4u), 0x7FFFFFFF);
      ob_draft_unresolved_call(0x80047450u, 1u, v8);
    }
    ((v4 += 4u));
    result = ((sint32)((sint32)r_u32(0x80077260u)) < (sint32)(++v5));
  }

  return result;
}


uint32 sub_8001DBCC(uint32 a1)
{
    FUNCTION_MARKER(0x8001dbccu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_800610B0 */
    /* TODO: Bind external adapter for sub_80062B54 */
    /* TODO: Bind external adapter for sub_80062A78 */
    /* Reserve the complete SDK object even though mask 3 selects only master volume */
    uint32 local_objects = ob_draft_scratch_acquire((uint32)sizeof(SpuCommonAttr));
  sint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 v5;
  sint32 result;
  ;
  ;
  ;
  sub_800602D0();
  ob_draft_unresolved_call(0x800610b0u, 2u, 128, (sint32)(0u - (uint32)(2146990112)));
  w_u32(local_objects + 0u, 3);
  w_u16(local_objects + 4u, 16320);
  w_u16(local_objects + 6u, 16320);
  ob_draft_unresolved_call(0x80062b54u, 1u, (local_objects + 0u));
  ob_draft_unresolved_call(0x80062a78u, 1u, 0);
  v2 = 0;
  v3 = 0;
  do
  {
    w_u32((uint32)((sint32)((uint32)(v3) - (uint32)(2146994016))), 0);
    w_u32((uint32)((sint32)((uint32)(v3) - (uint32)(2146994012))), 0);
    w_u32((uint32)((sint32)((uint32)(v3) - (uint32)(2146994008))), 0);
    w_u32((uint32)((sint32)((uint32)(v3) - (uint32)(2146994004))), 0);
    ++v2;
    v3 = ((uint32)(v3) + (uint32)(20));
  }
  while (((sint32)(v2) < (sint32)(128)));
  v4 = 0;
  v5 = 0;
  do
  {
    w_u32((uint32)((sint32)((uint32)(v5) - (uint32)(2146991456))), 0);
    w_u32((uint32)((sint32)((uint32)(v5) - (uint32)(2146991452))), 0);
    w_u32((uint32)((sint32)((uint32)(v5) - (uint32)(2146990780))), 0);
    w_u8((uint32)((sint32)((uint32)(v5) - (uint32)(2146990764))), (sint32)(0u - (uint32)(1)));
    w_u8((uint32)((sint32)((uint32)(v5) - (uint32)(2146990763))), (sint32)(0u - (uint32)(1)));
    ++v4;
    v5 = ((uint32)(v5) + (uint32)(28));
  }
  while (((sint32)(v4) < (sint32)(24)));
  result = 1;
  w_u8(0x8006c00fu, 0);
  w_u8(0x8006c00cu, 1);
  w_u8(0x80078BEC, a1);
  w_u8(0x8006c00du, 0);
  w_u8(0x8006c011u, 0);
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


void sub_8005F998(void)
{
    FUNCTION_MARKER(0x8005f998u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8005FB18 */
  uint32 v1;
  v1 = (0x800771f8u);
  do
    w_u32(((v1 += 4u) - 4u), 0);
  while (((uint32)(v1) < 0x8008D018));
  w_u32(0x80075ea4u, (sint32)((uint32)((sint32)((uint32)((sint32)((uint32)((sint32)r_u32(0x80075ec4u)) - (uint32)(8))) - (uint32)((sint32)r_u32(0x80075ec0u)))) - (uint32)(878440)));
  w_u32(0x80075ea0u, (sint32)(0u - (uint32)(2146605208)));
  /* Native entry has no guest return-address continuation to save */
  ob_draft_unresolved_call(0x8005fb18u, 1u, (sint32)(0u - (uint32)(2146605204)));
  sub_80022CD4();
}


uint32 sub_80021B20(uint32 handle)
{
    FUNCTION_MARKER(0x80021B20u, "SLES_008.65");
    uint32 image = ob_draft_scratch_acquire(0x2038u);
    uint32 source;
    w_u32(0x80073514u, 1u);
    while (r_u32(0x80073514u)) ob_native_pump();
    if (r_u32(handle) & 3u)
        source = sub_800257CC(handle);
    else
    {
        source = r_u32(handle);
        w_u16(source - 6u, r_u16(source - 6u) + 1u);
        source = r_u32(handle);
    }
    w_u16(image, r_u16(source));
    w_u16(image + 2u, r_u16(source + 2u));
    uint32 payload = source + 12u;
    uint32 palette = payload + 2u * r_u16(source + 8u);
    w_u32(image + 0x2024u, payload);
    w_u32(image + 0x202Cu, palette);
    w_u32(image + 0x2030u, r_u32(0x8006C0D4u) + 196608u);
    w_u32(image + 0x2028u, palette + 2u * r_u16(source + 10u));
    w_u16(image + 0x2034u, r_u16(source + 4u));
    w_u16(image + 0x2036u, r_u16(source + 6u));
    sub_80021D80(image);
    uint32 result = sub_800257A0(handle);
    ob_draft_scratch_release(image);
    return result;
}


uint32 sub_800251E8(uint32 a1)
{
    FUNCTION_MARKER(0x800251e8u, "SLES_008.65");
  sint32 v2;
  sint32 v3;
  sint32 v4;
  uint32 i;
  sint32 v6;
  uint32 v8;
  sub_800256CC(a1);
  sub_8002679C(a1, 1);
  v2 = r_u32(a1);
  v3 = 1;
  v4 = r_u32((uint32)(((uint32)(r_u32(a1)) + (uint32)(12))));
  for (i = (uint32)(((uint32)(r_u32(a1)) + (uint32)(20))); (v3 < (sint32)r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(8))))); ++v3)
  {
    v6 = (sint32)r_u32(i);
    if (((sint32)r_u32(((i += 4u) - 4u)) != 1))
    {
      v8 = (uint32)(sub_80027DF8((uint16)(v3)));
      if (((r_u32(v8) & 3) == 0))
        sub_80026758(v8);
      w_u32(v8, v6);
    }
  }

  sub_800267C4(a1, 1);
  sub_80026758(a1);
  return v4;
}


uint32 sub_800552D4(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x800552d4u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80055884 */
    /* TODO: Bind external adapter for sub_800558B4 */
    /* TODO: Bind external adapter for sub_80056048 */
    /* TODO: Bind external adapter for sub_80055894 */
    /* TODO: Bind external adapter for sub_80058A98 */
    /* TODO: Bind external adapter for sub_80058BA0 */
    /* TODO: Bind external adapter for sub_80059CA8 */
    uint32 local_objects = ob_draft_scratch_acquire(8u);
  sint32 v5;
  sint32 v6;
  sint32 result;
  ;
  ;
  ;
  (w_u32(0x800771e8u, ((sint32)r_u32(0x800771e8u) + 1u)), (sint32)r_u32(0x800771e8u));
  sub_80054E08(a1, (local_objects + 0u), (local_objects + 1u), (local_objects + 2u));
  w_u8(((local_objects + 2u) + (1) * 1u), 0);
  v5 = ob_draft_unresolved_call(0x80055884u, 4u, (sint32)(0u - (uint32)(268435453)), 32, 0x2000, 0);
  v6 = ob_draft_unresolved_call(0x80055884u, 4u, (sint32)(0u - (uint32)(268435453)), 0x8000, 0x2000, 0);
  ob_draft_unresolved_call(0x800558b4u, 1u, v5);
  ob_draft_unresolved_call(0x800558b4u, 1u, v6);
  ob_draft_unresolved_call(0x80056048u, 3u, 2, (local_objects + 0u), 0);
  ob_draft_unresolved_call(0x80055894u, 1u, v5);
  ob_draft_unresolved_call(0x80055894u, 1u, v6);
  ob_draft_unresolved_call(0x80058a98u, 3u, a3, a2, 128);
  while (1)
  {
    result = ob_draft_unresolved_call(0x80058ba0u, 2u, 1, 0);
    if (((sint32)(result) <= (sint32)(0)))
      break;
    ob_draft_unresolved_call(0x80059ca8u, 1u, 0);
  }

  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_8004735C(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8004735cu, "SLES_008.65");
    /* TODO: Recover missing meaningful carriers for sub_80047450 before binding the native call */
  sint32 v4;
  sint32 v5;
  sint32 result;
  uint32 v7;
  uint32 v8;
  sint32 v9;
  sint32 v10;
  v4 = r_u32((uint32)(((uint32)(a1) + (uint32)(24))));
  v5 = r_u32((uint32)(((uint32)(a1) + (uint32)(184))));
  result = (sint32)((uint32)((sint32)((uint32)(4) * (uint32)(v4))) + (uint32)(4));
  v7 = (uint32)((sint32)((uint32)((sint32)r_u32(0x80077140u)) + (uint32)(result)));
  v8 = (uint32)((sint32)((uint32)((sint32)r_u32(0x80077148u)) + (uint32)(result)));
  if (v5)
  {
    v9 = (sint32)((uint32)(8) * (uint32)(v4));
    do
    {
      v10 = r_u32(v7);
      if (r_u32(v7))
      {
        result = (r_u32((uint32)(((uint32)(r_u32(v8)) + (uint32)(v9)))) & 0x8000);
        if (result)
        {
          --v5;
          sub_800477B8(r_u32(v7), a1, a2, ((uint32)(r_u32(v8)) + (uint32)(v9)));
          result = ob_draft_unresolved_call(0x80047450u, 1u, v10);
        }
      }
      ((v8 += 4u));
      ((v7 += 4u));
    }
    while (v5);
  }
  return result;
}


uint32 sub_8004EEF4(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8004eef4u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8005F428 */
    /* TODO: Bind external adapter for sub_8005F398 */
    /* TODO: Bind external adapter for sub_8005F888 */
    uint32 local_objects = ob_draft_scratch_acquire(72u);
  sint32 v3;
  sint32 result;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  sint32 v12;
  sint32 v13;
  sint32 v14;
  ;
  ;
  w_u32(local_objects + 0u, r_u32(a1));
  w_u32(local_objects + 4u, r_u32((a1 + (1) * 4u)));
  w_u32(local_objects + 8u, r_u32((a1 + (2) * 4u)));
  w_u32(local_objects + 0u, ((uint32)((sint32)r_u32(local_objects + 0u)) - (uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800775d0u)) + (uint32)(24)))))));
  w_u32(local_objects + 4u, ((uint32)((sint32)r_u32(local_objects + 4u)) - (uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800775d0u)) + (uint32)(28)))))));
  w_u32(local_objects + 8u, ((uint32)((sint32)r_u32(local_objects + 8u)) - (uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800775d0u)) + (uint32)(32)))))));
  sub_8002FE50((sint32)((local_objects + 0u)), (sint32)r_u32(0x800775d0u), (sint32)((local_objects + 16u)));
  w_u32(local_objects + 16u, ((uint32)((sint32)r_u32(local_objects + 16u)) >> (uint32)(3)));
  w_u32(local_objects + 20u, ((uint32)((sint32)r_u32(local_objects + 20u)) >> (uint32)(3)));
  w_u32(local_objects + 24u, ((uint32)((sint32)r_u32(local_objects + 24u)) >> (uint32)(3)));
  v12 = (sint32)r_u32(local_objects + 16u);
  v13 = (sint32)r_u32(local_objects + 20u);
  v14 = (sint32)r_u32(local_objects + 24u);
  ob_draft_unresolved_call(0x8005f428u, 1u, (local_objects + 32u));
  ob_draft_unresolved_call(0x8005f398u, 1u, (sint32)(0u - (uint32)(2146907992)));
  sub_8005F488(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800770c0u)) + (uint32)(8)))));
  ob_draft_unresolved_call(0x8005f888u, 4u, (sint32)r_u32(0x800771acu), a2, (local_objects + 64u), (local_objects + 68u));
  v3 = r_u16((uint32)(((uint32)(a2) + (uint32)(2))));
  result = ((uint32)((sint32)r_u32(0x800896C0)) - (uint32)(v3));
  w_u16((uint32)(((uint32)(a2) + (uint32)(2))), ((uint32)((sint32)r_u32(0x800896C0)) - (uint32)(v3)));
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_8004E3B0(void)
{
    FUNCTION_MARKER(0x8004e3b0u, "SLES_008.65");
  sint32 v0;
  uint32 v1;
  sint32 v2;
  sint32 result;
  sub_800427AC();
  v0 = (sint32)r_u32(0x80077590u);
  w_u32(0x80077590u, (sint32)(0u - (uint32)(2146921024)));
  sub_8002DC10((uint32)(0x800898B0));
  v1 = (uint32)((sint32)r_u32(0x800775d0u));
  w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800775d0u)) + (uint32)(48))), ((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800775d0u)) + (uint32)(48))))) & (uint32)(~0x20u)));
  sub_80042928(v1, (sint32)(0u - (uint32)(2146920272)));
  v2 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800775d0u)) + (uint32)(48))));
  w_u32(0x80077590u, v0);
  w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800775d0u)) + (uint32)(48))), (v2 | 0x20));
  w_u16(0x80083EA0, ((sint32)((sint16)((sint32)r_u32(0x800898B0))) >> 2));
  w_u16(0x80083EA2, ((sint32)((sint16)(r_u16(0x800898B6))) >> 2));
  w_u16(0x80083EA4, ((sint32)((sint16)(r_u16(0x800898BC))) >> 2));
  w_u16(0x80083EA6, ((sint32)((sint16)(r_u16(0x800898B2))) >> 2));
  w_u16(0x80083EA8, ((sint32)((sint16)(r_u16(0x800898B8))) >> 2));
  w_u16(0x80083EAA, ((sint32)((sint16)(r_u16(0x800898BE))) >> 2));
  w_u16(0x80083EAC, ((sint32)((sint16)(r_u16(0x800898B4))) >> 2));
  w_u16(0x80083EAE, ((sint32)((sint16)(r_u16(0x800898BA))) >> 2));
  result = (((uint32)(r_u16(0x800898C0)) << (uint32)(16)) >> 18);
  w_u16(0x80083EB0, ((sint32)((sint16)(r_u16(0x800898C0))) >> 2));
  return result;
}


uint32 sub_8001FC60(void)
{
    FUNCTION_MARKER(0x8001fc60u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80056048 */
    uint32 local_objects = ob_draft_scratch_acquire(8u);
  sint32 result;
  ;
  result = (uint8)((sint8)r_u8(0x8006c012u));
  if ((sint8)r_u8(0x8006c012u))
  {
    sint32 track = ob_native_cd_audio_track();
    if (track <= 0 || track > 99)
      ob_native_missing(0x8001FC60u, 1u, (uint32)track);
    /* This caller consumes only the current track byte of GetlocP */
    w_u8(local_objects, (uint8)(((uint32)track / 10u << 4u) | ((uint32)track % 10u)));

    if (((sint32)r_u32(0x80078DB8) >= (sint32)((uint32)((sint32)((uint32)(10) * (uint32)(((uint8)((sint8)r_u8(((local_objects + 0u) + (0) * 1u))) >> 4)))) + (uint32)(((sint8)r_u8(((local_objects + 0u) + (0) * 1u)) & 0xF)))))
    {
      result = ((uint8)((sint8)r_u8(0x8006c013u)) | 2);
      w_u8(0x8006c013u, ((uint32)((sint8)r_u8(0x8006c013u)) | (uint32)(2u)));
    }
    else
    {
      if (((((sint8)r_u8(0x8006c013u) & 1) != 0) && (((sint8)r_u8(0x8006c013u) & 2) != 0)))
      {
        w_u8(0x8006c013u, ((uint32)((sint8)r_u8(0x8006c013u)) & (uint32)(~2u)));
        ob_draft_unresolved_call((sint32)r_u32(0x80084A4C), 0u);
      }
      if (!r_u8(0x80078DBC))
        sub_8001DF58(0);
      while ((ob_draft_unresolved_call(0x80056048u, 3u, 2, (sint32)((uint32)((sint32)((uint32)(4) * (uint32)((sint32)r_u32(0x80078DB8)))) - (uint32)(2146988880)), 0) != 1))
        ;

      do
        result = ob_draft_unresolved_call(0x80056048u, 3u, 3, 0, 0);
      while ((result != 1));
    }
  }
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80045D70(uint32 a1)
{
    FUNCTION_MARKER(0x80045d70u, "SLES_008.65");
    /* TODO Resolve the frozen release helper ABI without inventing unused incoming carriers */
  sint32 result;
  uint32 i;
  sint32 v4;
  sint32 v5;
  uint32 v6;
  sint32 v7;
  result = (sint32)(0u - (uint32)(2146920720));
  for (i = (uint32)((sint32)r_u32(0x800896F0)); ((sint32)r_u32(0x800896F0) != (sint32)(0u - (uint32)(2146920716))); i = (uint32)((sint32)r_u32(0x800896F0)))
  {
    v4 = (sint32)r_u32((i + (5) * 4u));
    if (v4)
    {
      v5 = (sint32)r_u32((i + (7) * 4u));
      result = ((sint32)a1 < v5);
      if (((sint32)a1 < v5))
        break;
      v6 = (uint32)((sint32)r_u32((i + (9) * 4u)));
      if (!v6)
        break;
      v7 = (sint32)r_u32((i + (8) * 4u));
      sub_80043C94(i);
      if (!(sint32)r_u32((i + (3) * 4u)))
        ob_draft_unresolved_call(0x80043C6Cu, 1u, i);
      w_u32(0x80077334u, v5);
      result = ob_draft_unresolved_call(v6, 3u, v4, v7, v5);
    }
    else
    {
      sub_80043C94(i);
      result = (sint32)r_u32((i + (3) * 4u));
      if (!result)
        result = ob_draft_unresolved_call(0x80043C6Cu, 1u, i);
    }
  }

  w_u32(0x80077334u, a1);
  return result;
}


uint32 sub_8004434C(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x8004434Cu, "SLES_008.65");
    uint32 result = r_u32(a1 + 40u);
    w_u16(a1 + 58u, a2);
    w_u16(a1 + 60u, a3);
    if (result)
    {
        sub_800444F4(a1, r_u32(0x80077448u));
        uint32 descriptor = ob_draft_scratch_acquire(24u);
        uint32 flags = a2 | r_u16(a1 + 56u);
        w_u16(descriptor, flags);
        w_u32(descriptor + 4u, r_u32(a1 + 40u));
        w_u32(descriptor + 8u, a1 + 64u);
        w_u32(descriptor + 12u, a1);
        w_u32(descriptor + 16u, 0x80044474u);
        uint32 depth = r_u32(a1 + 156u);
        if (depth != 0xFFFFFFFFu)
        {
            w_u32(descriptor + 20u, depth);
            w_u16(descriptor, flags | 0x8000u);
        }
        if (a3 & 4u)
            result = sub_80042B54(descriptor, (a3 >> 1u) & 1u, a3 & 1u);
        else
            result = sub_80041D7C(descriptor, (a3 >> 1u) & 1u, a3 & 1u);
        ob_draft_scratch_release(descriptor);
    }
    for (uint32 child = r_u32(a1 + 32u); child; child = r_u32(child + 28u))
    {
        result = r_u32(child + 44u);
        if (!result)
            result = sub_800442F0(child, a2 & 0xFFFFu, a3 & 0xFFFFu);
    }
    return result;
}


uint32 sub_80043EAC(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x80043eacu, "SLES_008.65");
    uint32 local_objects = ob_draft_scratch_acquire(4u);
  uint32 v4;
  sint32 v6;
  sint32 v7;
  uint32 i;
  sint32 v9;
  ;
  v4 = r_u32(a3);
  sub_80043600((uint32)(a1), a2, r_u32(r_u32(a3)));
  w_u32((uint32)(a1), (0x80077104u));
  w_u32((uint32)(((uint32)(a1) + (uint32)(24))), 0);
  w_u32((uint32)(((uint32)(a1) + (uint32)(28))), 0);
  w_u32((uint32)(((uint32)(a1) + (uint32)(32))), 0);
  w_u32((uint32)(((uint32)(a1) + (uint32)(40))), (sint32)r_u32((v4 + (3) * 4u)));
  w_u32((uint32)(((uint32)(a1) + (uint32)(48))), (sint32)r_u32((v4 + (2) * 4u)));
  v6 = (sint32)r_u32((v4 + (4) * 4u));
  w_u16((uint32)(((uint32)(a1) + (uint32)(56))), 128);
  w_u32((uint32)(((uint32)(a1) + (uint32)(36))), 0);
  w_u32((uint32)(((uint32)(a1) + (uint32)(52))), 0);
  w_u32((uint32)(((uint32)(a1) + (uint32)(144))), 0);
  w_u32((uint32)(((uint32)(a1) + (uint32)(148))), 0);
  w_u32((uint32)(((uint32)(a1) + (uint32)(152))), 0);
  w_u16((uint32)(((uint32)(a1) + (uint32)(160))), 256);
  w_u32((uint32)(((uint32)(a1) + (uint32)(156))), (sint32)(0u - (uint32)(1)));
  w_u32((uint32)(((uint32)(a1) + (uint32)(44))), v6);
  sub_8002DC10((uint32)(((uint32)(a1) + (uint32)(64))));
  w_u32(a3, r_u32(a3) + 20u);
  v7 = (sint32)((uint32)((sint32)r_u32((v4 + (1) * 4u))) - (uint32)(1));
  for (i = (uint32)(((uint32)(a1) + (uint32)(32))); (v7 != (sint32)(0u - (uint32)(1))); i = (uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 0u)) + (uint32)(28))))
  {
    w_u32(local_objects + 0u, 0);
    sub_800262CC((local_objects + 0u), 164);
    sub_80043EAC((sint32)r_u32(local_objects + 0u), a1, a3);
    v9 = (sint32)r_u32(local_objects + 0u);
    w_u32((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 0u)) + (uint32)(24))), a1);
    w_u32(i, v9);
    --v7;
  }

  { uint32 draft_return = a1; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80016390(uint32 a1)
{
    FUNCTION_MARKER(0x80016390u, "SLES_008.65");
    /* TODO: Recover missing meaningful carriers for sub_80020450 before binding the native call */
  sint32 result;
  result = ((sint32)((uint32)((sint8)r_u8(0x8006c231u)) + (uint32)(1)) & 3);
  if ((((sint32)((uint32)((sint8)r_u8(0x8006c231u)) + (uint32)(1)) & 3) != 0))
    return ob_draft_unresolved_call(0x80020450u, 4u, a1, 0, 0, 15);
  return result;
}


uint32 sub_8004D634(uint32 a1)
{
    FUNCTION_MARKER(0x8004d634u, "SLES_008.65");
    /* TODO: Recover missing meaningful carriers for sub_8004D76C before binding the native call */
  uint32 v1;
  sint32 v2;
  sint32 v3;
  sint32 result;
  sint32 v5;
  uint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  v1 = (sint32)r_u32(0x80077438u);
  v2 = (sint32)(0u - (uint32)(2146940232));
  v3 = 0;
  do
  {
    result = (sint8)r_u8((uint32)(v1));
    v5 = 0;
    if ((result == (sint32)(0u - (uint32)(1))))
      break;
    v6 = (sint32)r_u32(0x80077430u);
    v7 = (sint32)(0u - (uint32)(2146940248));
    do
    {
      v8 = (sint8)r_u8((uint32)(v6));
      if ((v8 == (sint32)(0u - (uint32)(1))))
        break;
      v9 = (sint32)((uint32)(v8) + (uint32)((sint32)((uint32)((sint8)r_u8((uint32)(v1))) * (uint32)((sint16)r_u16((uint32)(((uint32)(a1) + (uint32)(4))))))));
      v10 = ((uint32)(r_u32((uint32)(((uint32)(a1) + (uint32)(12))))) + (uint32)((sint32)((uint32)(2) * (uint32)(v9))));
      if ((sub_8004DAA4(v8, (sint8)r_u8((uint32)(v1)), 0, 0) != (sint32)(0u - (uint32)(1))))
      {
        sub_8004A908(v9);
        ob_draft_unresolved_call(0x8004d76cu, 4u, v10, v1, v6, v2);
      }
      v7 = ((uint32)(v7) + (uint32)(4));
      ++v5;
      v6 = (uint32)(((uint32)(v6) + (2) * 1u));
    }
    while (((sint32)(v5) < (sint32)(3)));
    v2 = ((uint32)(v2) + (uint32)(4));
    result = ((sint32)(++v3) < (sint32)(3));
    v1 = (uint32)(((uint32)(v1) + (2) * 1u));
  }
  while (((sint32)(v3) < (sint32)(3)));
  return result;
}


uint32 sub_800354C8(uint32 a1)
{
    FUNCTION_MARKER(0x800354C8u, "SLES_008.65");
    uint32 count = r_u16(a1 + 10u);
    w_u32(0x80077598u, a1);
    w_u16(0x80077388u, count);
    w_u16(0x800775F0u, r_u16(a1 + 14u));
    w_u16(0x800775A4u, r_u16(a1 + 12u));
    w_u16(0x80077410u, r_u16(a1 + 16u));
    w_u16(0x800775A6u, r_u16(a1 + 18u));
    uint32 bytes = 4u * count;
    if (bytes >= r_u32(0x8007759Cu))
        w_u32(0x80077574u, sub_8002D98C(bytes));
    else
    {
        w_u32(0x8007759Cu, r_u32(0x8007759Cu) - bytes);
        uint32 cursor = r_u32(0x80077530u);
        w_u32(0x80077574u, cursor);
        w_u32(0x80077530u, cursor + bytes);
    }
    bytes = (2u * (r_u16(0x800775F0u) + 3u * r_u16(a1)) + 3u) & 0xFFFFFFFCu;
    if (bytes >= r_u32(0x8007759Cu))
        w_u32(0x800775E4u, sub_8002D98C(bytes));
    else
    {
        w_u32(0x8007759Cu, r_u32(0x8007759Cu) - bytes);
        uint32 cursor = r_u32(0x80077530u);
        w_u32(0x800775E4u, cursor);
        w_u32(0x80077530u, cursor + bytes);
    }
    bytes = 4u * r_u16(0x80077410u);
    uint32 result;
    if (bytes >= r_u32(0x8007759Cu))
    {
        result = sub_8002D98C(bytes);
        w_u32(0x800773A4u, result);
    }
    else
    {
        w_u32(0x8007759Cu, r_u32(0x8007759Cu) - bytes);
        uint32 cursor = r_u32(0x80077530u);
        w_u32(0x800773A4u, cursor);
        result = cursor + bytes;
        w_u32(0x80077530u, result);
    }
    w_u32(0x80077628u, 0u);
    return result;
}

uint32 sub_80029B70(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x80029b70u, "SLES_008.65");
  sint32 v3;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 result;
  v3 = r_u32(a1);
  v4 = r_u32((a1 + (1) * 4u));
  v5 = (int64_t)(((uint64_t)(((int64_t)((int64_t)(((uint64_t)(v4) * (uint64_t)((int64_t)(r_u32((a2 + (3) * 4u))))))) >> 14)) + (uint64_t)(((int64_t)((int64_t)(((uint64_t)(r_u32(a1)) * (uint64_t)((int64_t)(r_u32(a2)))))) >> 14))));
  v6 = r_u32((a1 + (2) * 4u));
  w_u32(a3, (int64_t)(((uint64_t)(((int64_t)((int64_t)(((uint64_t)(v6) * (uint64_t)((int64_t)(r_u32((a2 + (6) * 4u))))))) >> 14)) + (uint64_t)(v5))));
  w_u32((a3 + (1) * 4u), (int64_t)(((uint64_t)((int64_t)(((uint64_t)(((int64_t)((int64_t)(((uint64_t)(v6) * (uint64_t)((int64_t)(r_u32((a2 + (7) * 4u))))))) >> 14)) + (uint64_t)(((int64_t)((int64_t)(((uint64_t)(v4) * (uint64_t)((int64_t)(r_u32((a2 + (4) * 4u))))))) >> 14))))) + (uint64_t)(((int64_t)((int64_t)(((uint64_t)(v3) * (uint64_t)((int64_t)(r_u32((a2 + (1) * 4u))))))) >> 14)))));
  result = ((uint64_t)(((uint64_t)((int64_t)(((uint64_t)(v6) * (uint64_t)((int64_t)(r_u32((a2 + (8) * 4u))))))) >> 32)) << (uint64_t)(18));
  w_u32((a3 + (2) * 4u), (int64_t)(((uint64_t)((int64_t)(((uint64_t)(((int64_t)((int64_t)(((uint64_t)(v6) * (uint64_t)((int64_t)(r_u32((a2 + (8) * 4u))))))) >> 14)) + (uint64_t)(((int64_t)((int64_t)(((uint64_t)(v4) * (uint64_t)((int64_t)(r_u32((a2 + (5) * 4u))))))) >> 14))))) + (uint64_t)(((int64_t)((int64_t)(((uint64_t)(v3) * (uint64_t)((int64_t)(r_u32((a2 + (2) * 4u))))))) >> 14)))));
  return result;
}


uint32 sub_80034768(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a9, uint32 a10, uint32 a11, uint32 a12)
{
    FUNCTION_MARKER(0x80034768u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8005C504 */
    /* TODO: Bind external adapter for sub_8005C7C8 */
    /* TODO: Bind external adapter for sub_8005B76C */
    uint32 local_objects = ob_draft_scratch_acquire(8u);
  sint32 v15;
  sint32 v16;
  sint32 v17;
  sint16 v18;
  sint32 v19;
  sint32 result;
  ;
  ;
  w_u32(local_objects + 0u, ((uint32)((sint32)r_u32(local_objects + 0u)) & ~((uint32)65535u << 0) | (((uint32)(a2) & 65535u) << 0)));
  w_u32(local_objects + 0u, ((uint32)((sint32)r_u32(local_objects + 0u)) & ~((uint32)65535u << 16) | (((uint32)(a3) & 65535u) << 16)));
  w_u32(local_objects + 4u, ((uint32)((sint32)r_u32(local_objects + 4u)) & ~((uint32)65535u << 0) | (((uint32)(a4) & 65535u) << 0)));
  w_u32(local_objects + 4u, ((uint32)((sint32)r_u32(local_objects + 4u)) & ~((uint32)65535u << 16) | (((uint32)(a9) & 65535u) << 16)));
  if ((sint32)r_u32(0x80077464u))
  {
    w_u32(0x80077478u, (sint32)r_u32(local_objects + 0u));
    w_u32(0x8007747cu, (sint32)r_u32(local_objects + 4u));
  }
  ob_draft_unresolved_call(0x8005c504u, 1u, 0);
  ob_draft_unresolved_call(0x8005c7c8u, 2u, (local_objects + 0u), a1);
  ob_draft_unresolved_call(0x8005c504u, 1u, 0);
  v15 = ((uint32)((a2 >> 6)) << (uint32)(6));
  v16 = ((uint32)((a3 >> 8)) << (uint32)(8));
  v17 = ((uint32)(((uint32)(a2) - (uint32)(v15))) << (uint32)(a11));
  v18 = ((uint32)(a3) - (uint32)(v16));
  v19 = 1;
  if (((a10 & 0x200) == 0))
  {
    v19 = 2;
    if (((a10 & 0x400) == 0))
      v19 = (((a10 & 0x800) != 0)) ? (3) : (0);
  }
  result = (uint16)(ob_draft_unresolved_call(0x8005b76cu, 4u, ((uint8)(a10) >= 0x11u), v19, v15, v16));
  w_u32((uint32)(a12), result);
  w_u16((uint32)(((uint32)(a12) + (uint32)(4))), v17);
  w_u16((uint32)(((uint32)(a12) + (uint32)(6))), v18);
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_8004BF54(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8004bf54u, "SLES_008.65");
    /* TODO: Recover missing meaningful carriers for sub_8004B514 before binding the native call */
  sint32 v3;
  sint32 v5;
  uint32 v7;
  uint32 v8;
  v3 = (sint32)r_u32(0x800665d8u);
  v5 = 0;
  if ((((sint32)r_u32(0x800665d8u) & 3) != 0))
    v3 = sub_800257CC((sint32)((0x800665d8u)));
  else
    (w_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800665d8u)) - (uint32)(6))), (r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800665d8u)) - (uint32)(6)))) + 1u)), r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800665d8u)) - (uint32)(6)))));
  w_u32(0x80077644u, v3);
  if (((((a1 >= 0) && (a1 < (sint32)((uint32)(16) * (uint32)((sint16)r_u16((uint32)((sint32)((uint32)(v3) + (uint32)(4)))))))) && (a2 >= 0)) && (a2 < (sint32)((uint32)(16) * (uint32)((sint16)r_u16((uint32)((sint32)((uint32)(v3) + (uint32)(6)))))))))
  {
    v7 = (uint32)(ob_draft_unresolved_call(0x8004b514u, 2u, ((uint32)(((uint8)(a1) | ((uint32)((uint8)(a2)) << (uint32)(8)))) << (uint32)(16)), v3));
    v8 = (uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80077644u)) + (uint32)(24))))) + (uint32)((sint32)((uint32)(24) * (uint32)(r_u8(v7))))));
    if (r_u32(v8))
      v5 = 2;
    if (r_u32((v8 + (2) * 4u)))
      v5 |= 1u;
    if (r_u8((v7 + (1) * 1u)))
      v5 |= 4u;
    sub_800257A0((0x800665d8u));
    return v5;
  }
  else
  {
    sub_800257A0((0x800665d8u));
    return 3;
  }
}


uint32 sub_80054780(void)
{
    FUNCTION_MARKER(0x80054780u, "SLES_008.65");
    uint32 interval = 0x10000u;
    uint32 previous_interval;
    uint32 node;
    ob_draft_unresolved_call(0x80055A90u, 1u, 0xF2000001u);
    previous_interval = r_u32(0x800771D8u);
    if (r_u32(0x800771E0u) == 0u)
    {
        uint32 elapsed = 1000u * previous_interval;
        w_u32(0x800896ECu, r_u32(0x800896ECu) + previous_interval);
        w_u32(0x80084A48u, r_u32(0x80084A48u) + elapsed / 0x3840u);
    }
    node = r_u32(0x800771D4u);
    while (node != 0u)
    {
        sint32 remaining = (sint32)(r_u32(node + 8u) - previous_interval);
        w_u32(node + 8u, (uint32)remaining);
        if (remaining <= 0)
        {
            w_u32(node + 8u, (uint32)remaining + r_u32(node + 4u));
            w_u32(node + 16u, r_u32(node + 16u) + 1u);
        }
        remaining = (sint32)r_u32(node + 8u);
        if ((uint32)remaining < interval && remaining > 0)
            interval = (uint32)remaining;
        node = r_u32(node);
    }
    if (interval >= 30000u)
        interval = 30000u;
    node = r_u32(0x800771D4u);
    w_u32(0x800771D8u, interval);
    while (node != 0u)
    {
        uint32 next = r_u32(node);
        if (r_u32(node + 16u) != 0u)
            ob_draft_unresolved_call(r_u32(node + 20u), 0u);
        node = next;
    }
    ob_draft_unresolved_call(0x80055984u, 3u, 0xF2000001u, interval, 4096u);
    ob_draft_unresolved_call(0x80055A5Cu, 1u, 0xF2000001u);
    return ob_draft_unresolved_call(0x800558B4u, 1u, r_u32(0x800882B8u));
}


uint32 sub_8004954C(uint32 a1)
{
    FUNCTION_MARKER(0x8004954cu, "SLES_008.65");
    uint32 local_objects = ob_draft_scratch_acquire(8u);
  sint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  ;
  ;
  sint32 result;
  sint32 v12;
  sub_80048994((uint32)(a1));
  w_u16(0x80078ED8, 0);
  w_u16(0x80078EDA, 0);
  w_u16(0x80078EDC, 0);
  v2 = r_u32((uint32)(((uint32)(a1) + (uint32)(72))));
  v3 = r_u32((uint32)(((uint32)(a1) + (uint32)(76))));
  v4 = 1;
  if (((sint32)(v3) >= (sint32)(v2)))
  {
    if ((v3 == v2))
      v4 = 2;
    else
      v2 = r_u32((uint32)(((uint32)(a1) + (uint32)(76))));
  }
  v5 = r_u32((uint32)(((uint32)(a1) + (uint32)(80))));
  if (((sint32)(v5) >= (sint32)(v2)))
  {
    ++v4;
    if ((v5 != v2))
    {
      v2 = r_u32((uint32)(((uint32)(a1) + (uint32)(80))));
      v4 = 1;
    }
  }
  v6 = (uint16)((sint16)r_u16((0x80077134u + (v4) * 2u)));
  if ((r_u32((uint32)(((uint32)(a1) + (uint32)(72)))) == v2))
  {
    v7 = ((uint32)(v7) & ~((uint32)65535u << 0) | (((uint32)(v6) & 65535u) << 0));
    if ((r_u32((uint32)(((uint32)(a1) + (uint32)(48)))) == r_u32((uint32)(((uint32)(a1) + (uint32)(36))))))
      v7 = (sint32)(0u - (uint32)(v6));
    w_u16(0x80078ED8, v7);
  }
  if ((r_u32((uint32)(((uint32)(a1) + (uint32)(76)))) == v2))
  {
    v8 = ((uint32)(v8) & ~((uint32)65535u << 0) | (((uint32)(v6) & 65535u) << 0));
    if ((r_u32((uint32)(((uint32)(a1) + (uint32)(52)))) == r_u32((uint32)(((uint32)(a1) + (uint32)(40))))))
      v8 = (sint32)(0u - (uint32)(v6));
    w_u16(0x80078EDA, v8);
  }
  if ((r_u32((uint32)(((uint32)(a1) + (uint32)(80)))) == v2))
  {
    if ((r_u32((uint32)(((uint32)(a1) + (uint32)(56)))) == r_u32((uint32)(((uint32)(a1) + (uint32)(44))))))
      v6 = (sint32)(0u - (uint32)(v6));
    w_u16(0x80078EDC, v6);
  }
  w_u32(local_objects + 0u, r_u32((uint32)(((uint32)(a1) + (uint32)(4)))));
  w_u32(local_objects + 4u, r_u32((uint32)(((uint32)(a1) + (uint32)(8)))));
  result = 0;
  if (((sint32)(v2) < (sint32)(0)))
  {
    w_u32(r_u32((uint32)(((uint32)(a1) + (uint32)(20)))), ((r_u32(r_u32((uint32)(((uint32)(a1) + (uint32)(20))))) & 0xFFFFFFCF) | 0x20));
    v12 = r_u32(((local_objects + 0u) + (34) * 4u));
    w_u32(((local_objects + 0u) + (64) * 4u), (r_u32(((local_objects + 4u) + (34) * 4u)) & r_u32(((local_objects + 0u) + (41) * 4u))));
    result = 32;
    w_u32(((local_objects + 4u) + (64) * 4u), (v12 & r_u32(((local_objects + 4u) + (41) * 4u))));
  }
  else
  {
    w_u32(((local_objects + 0u) + (64) * 4u), 0);
    w_u32(((local_objects + 4u) + (64) * 4u), 0);
  }
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_800328EC(uint32 a1)
{
    FUNCTION_MARKER(0x800328ECu, "SLES_008.65");
    sint32 x = (sint16)r_u16(a1);
    sint32 y = (sint16)r_u16(a1 + 8u);
    sint32 z = (sint16)r_u16(a1 + 16u);
    sint32 reciprocal_x;
    sint32 reciprocal_y;
    sint32 reciprocal_z;
    sint32 maximum;
    sint32 magnitude;
    uint32 vector;
    uint32 result;
    if (x == 0 || y == 0 || z == 0)
        xport_mips_break(7u);
    reciprocal_x = 0x10000000 / x;
    reciprocal_y = 0x10000000 / y;
    reciprocal_z = 0x10000000 / z;
    maximum = reciprocal_x < 0 ? -reciprocal_x : reciprocal_x;
    magnitude = reciprocal_y < 0 ? -reciprocal_y : reciprocal_y;
    if (magnitude > maximum) maximum = magnitude;
    magnitude = reciprocal_z < 0 ? -reciprocal_z : reciprocal_z;
    if (magnitude > maximum) maximum = magnitude;
    while (maximum >= 18901)
    {
        reciprocal_x >>= 1;
        reciprocal_y >>= 1;
        reciprocal_z >>= 1;
        maximum >>= 1;
    }
    vector = ob_draft_scratch_acquire(8u);
    w_u16(vector, reciprocal_x);
    w_u16(vector + 2u, reciprocal_y);
    w_u16(vector + 4u, reciprocal_z);
    result = sub_8003042C(vector, 0x8007763Cu);
    ob_draft_scratch_release(vector);
    return result;
}


uint32 sub_80026D30(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80026d30u, "SLES_008.65");
    /* TODO: Recover missing meaningful carriers for sub_800271EC before binding the native call */
    /* TODO: Bind external adapter for sub_80026A0C */
  uint32 v2;
  uint32 v3;
  uint32 v4;
  uint32 result;
  uint32 v6;
  uint32 v7;
  sint32 i;
  v2 = r_u32((uint32)(((uint32)(a2) + (uint32)(24))));
  v3 = (((uint32)(a1) + (uint32)(7)) & 0xFFFFFFFC);
  if (((sint32)r_u32(0x80077248u) && (r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80077224u)) + (uint32)(8))))) + (uint32)(16)))) >= v3)))
  {
    LABEL_10:
    v6 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80077224u)) + (uint32)(8))));

    v7 = (sint32)r_u32(0x8007721cu);
    for (i = (v6 < (sint32)r_u32(0x8007721cu)); (r_u32((uint32)(((uint32)(v6) + (uint32)(16)))) >= v3); i = (v6 < v7))
    {
      if (i)
        v7 = v6;
      v6 = r_u32((uint32)(((uint32)(v6) + (uint32)(8))));
    }

    sub_8002785C(v7);
    w_u32((uint32)(((uint32)(v7) + (uint32)(20))), 0);
    sub_800271EC(v7, a1);
    return v7;
  }
  if (((sint32)r_u32(0x80077248u) >= ((uint32)(v3) + (uint32)(40))))
  {
    LABEL_6:
    if ((r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80077224u)) + (uint32)(8))))) + (uint32)(16)))) < v3))
    {
      while (1)
      {
        ob_draft_unresolved_call(0x80026a0cu, 1u, v3);
        if ((r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80077224u)) + (uint32)(8))))) + (uint32)(16)))) >= v3))
          break;
        v4 = (sub_80026EB8(((uint32)(r_u32(v2)) - (uint32)(40))) == 0);
        result = 0;
        if (v4)
          return result;
      }

    }

    goto LABEL_10;
  }
  while (1)
  {
    v4 = (sub_80026EB8(((uint32)(r_u32(v2)) - (uint32)(40))) == 0);
    result = 0;
    if (v4)
      return result;
    if (((sint32)r_u32(0x80077248u) >= ((uint32)(v3) + (uint32)(40))))
      goto LABEL_6;
  }

}


uint32 sub_80027F98(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80027f98u, "SLES_008.65");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
  sint32 v4;
  sint32 result;
  uint32 v6;
  uint32 v7;
  uint32 v8;
  uint32 v9;
  sint8 v10;
  uint32 v11;
  sint32 v12;
  sint32 v13;
  sint32 v14;
  sint32 v15;
  sint32 v16;
  v4 = 0;
  if (a1)
  {
    v6 = a1;
    if (((sint32)a1 < 0))
      v6 = (0u - (uint32)(a1));
    v7 = a2;
    if (((sint32)a2 < 0))
      v7 = (0u - (uint32)(a2));
    v8 = v7;
    if ((v6 < v7))
    {
      v7 = v6;
      v6 = v8;
      v4 = 1;
    }
    if (((v7 <= 0xFFFF) || (v9 = sub_800283C0(v7), v10 = ((uint32)(v9) - (uint32)(20)), (v9 < 0x15))))
    {
      v11 = ((uint32)(v7) << (uint32)(12));
    }
    else
    {
      v6 >>= ((uint32)v10 & 31u);
      v11 = v7 << ((12u - (uint32)v10) & 31u);
    }
    v12 = (sint32)((uint32)(2) * (uint32)((v11 / v6)));
    if ((v6 < (sint32)((uint32)(2) * (uint32)((v11 % v6)))))
      v12 = (sint32)((uint32)(2) * (uint32)(((uint32)((v11 / v6)) + (uint32)(1))));
    v13 = r_u16((uint32)((sint32)((uint32)(v12) - (uint32)(2147020532))));
    if (((sint32)a1 >= 0))
    {
      if (((sint32)a2 < 0))
      {
        v15 = (sint32)((uint32)(v13) - (uint32)(0x4000));
        if (!v4)
          v15 = (sint32)(0u - (uint32)(v13));
        goto LABEL_31;
      }
      v14 = 0x4000;
      if (!v4)
      {
        v16 = (sint32)((uint32)(v13) << (uint32)(16));
        return ((sint32)(v16) >> 16);
      }
      goto LABEL_30;
    }
    if (((sint32)a2 >= 0))
    {
      v15 = (sint32)((uint32)(v13) + (uint32)(0x4000));
      if (!v4)
      {
        v14 = (sint32)(0u - (uint32)(32768));
        goto LABEL_30;
      }
    }
    else
    {
      if (v4)
      {
        v14 = (sint32)(0u - (uint32)(16384));
        LABEL_30:
        v15 = (sint32)((uint32)(v14) - (uint32)(v13));

        goto LABEL_31;
      }
      v15 = (sint32)((uint32)(v13) - (uint32)(0x8000));
    }
    LABEL_31:
    v16 = (sint32)((uint32)(v15) << (uint32)(16));

    return ((sint32)(v16) >> 16);
  }
  if (!a2)
    return 0;
  result = (sint32)(0u - (uint32)(16384));
  if (((sint32)a2 > 0))
    return 0x4000;
  return result;
}


uint32 sub_800477B8(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    FUNCTION_MARKER(0x800477b8u, "SLES_008.65");
    /* TODO: Recover missing meaningful carriers for sub_80048978 before binding the native call */
    /* TODO: Bind external adapter for sub_80048610 */
    /* TODO: Bind external adapter for sub_80048418 */
  sint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 result;
  uint32 v8;
  uint32 v9;
  v4 = r_u32(a4);
  v5 = (sint32)r_u32(0x800770f4u);
  v6 = (r_u32(a4) & 3);
  w_u32(a4, ((uint32)(r_u32(a4)) & (uint32)(0xBFFEFFFF)));
  result = 2;
  if ((v6 == 1))
  {
    v9 = (v4 & 0xF8);
    if ((v9 == 32))
    {
      ob_draft_unresolved_call(0x80048978u, 0u);
      sub_80048994(v5);
      return sub_800486E4(v5);
    }
    else
    {
      result = 8;
      if ((v9 < 0x21))
      {
        result = 16;
        if ((v9 == 8))
        {
          ob_draft_unresolved_call(0x80048978u, 0u);
          sub_80048994(v5);
          return sub_80048020(v5);
        }
        else
          if ((v9 == 16))
        {
          ob_draft_unresolved_call(0x80048978u, 0u);
          sub_80048994(v5);
          return sub_800487B8(v5);
        }
      }
    }
  }
  else
  {
    v8 = (v4 & 0xF8);
    if ((v6 == 2))
    {
      if ((v8 == 32))
      {
        ob_draft_unresolved_call(0x80048978u, 0u);
        sub_80048994(v5);
        return ob_draft_unresolved_call(0x80048610u, 1u, v5);
      }
      else
        if ((v8 >= 0x21))
      {
        result = 64;
        if ((v8 == 64))
        {
          ob_draft_unresolved_call(0x80048978u, 0u);
          sub_80048994(v5);
          return ob_draft_unresolved_call(0x80048418u, 1u, v5);
        }
      }
      else
      {
        result = 16;
        if ((v8 == 8))
        {
          ob_draft_unresolved_call(0x80048978u, 0u);
          sub_80048994(v5);
          return sub_800480A8(v5);
        }
        else
          if ((v8 == 16))
        {
          ob_draft_unresolved_call(0x80048978u, 0u);
          sub_80048994(v5);
          return sub_80048124(v5);
        }
      }
    }
  }
  return result;
}


uint32 sub_800409E0(void)
{
    FUNCTION_MARKER(0x800409e0u, "SLES_008.65");
  sint32 result;
  sint16 v1;
  sint16 v2;
  sint16 v3;
  sint16 v4;
  sint16 v5;
  sint16 v6;
  sint16 v7;
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
  sint16 v25;
  sint16 v26;
  sint16 v27;
  sint16 v28;
  sint16 v29;
  sint16 v30;
  sint16 v31;
  sint32 v32;
  sint32 v33;
  sint32 v34;
  result = sub_8002D98C(120);
  v1 = (sint16)r_u16(0x800775a4u);
  v2 = (sint16)r_u16(0x80077410u);
  v3 = (sint16)r_u16(0x800775a6u);
  v4 = (sint16)r_u16(0x80077388u);
  v5 = (sint16)r_u16(0x8007748cu);
  v6 = (sint16)r_u16(0x80077480u);
  v7 = (sint16)r_u16(0x800775a0u);
  v8 = (sint32)r_u32(0x80077598u);
  v9 = (sint32)r_u32(0x80077574u);
  v10 = (sint32)r_u32(0x80077518u);
  v11 = (sint32)r_u32(0x80077628u);
  v12 = (sint32)r_u32(0x800775ecu);
  v13 = (sint32)r_u32(0x80077610u);
  v14 = (sint32)r_u32(0x800773a4u);
  v15 = (sint32)r_u32(0x800775e4u);
  v16 = (sint32)r_u32(0x80077420u);
  w_u16((uint32)(result), (sint16)r_u16(0x800775f0u));
  w_u16((uint32)((sint32)((uint32)(result) + (uint32)(2))), v1);
  w_u16((uint32)((sint32)((uint32)(result) + (uint32)(4))), v2);
  w_u16((uint32)((sint32)((uint32)(result) + (uint32)(6))), v3);
  w_u16((uint32)((sint32)((uint32)(result) + (uint32)(8))), v4);
  w_u16((uint32)((sint32)((uint32)(result) + (uint32)(10))), v5);
  w_u16((uint32)((sint32)((uint32)(result) + (uint32)(12))), v6);
  w_u16((uint32)((sint32)((uint32)(result) + (uint32)(14))), v7);
  w_u32((uint32)((sint32)((uint32)(result) + (uint32)(16))), v8);
  w_u32((uint32)((sint32)((uint32)(result) + (uint32)(24))), v9);
  w_u32((uint32)((sint32)((uint32)(result) + (uint32)(28))), v10);
  w_u32((uint32)((sint32)((uint32)(result) + (uint32)(32))), v11);
  w_u32((uint32)((sint32)((uint32)(result) + (uint32)(36))), v12);
  w_u32((uint32)((sint32)((uint32)(result) + (uint32)(40))), v13);
  w_u32((uint32)((sint32)((uint32)(result) + (uint32)(44))), v14);
  w_u32((uint32)((sint32)((uint32)(result) + (uint32)(48))), v15);
  w_u32((uint32)((sint32)((uint32)(result) + (uint32)(52))), v16);
  v17 = (sint32)r_u32(0x8007759cu);
  v18 = (sint32)r_u32(0x80077530u);
  v19 = (uint16)((sint16)r_u16(0x80077364u));
  v20 = (uint16)((sint16)r_u16(0x80077638u));
  v21 = (sint32)r_u32(0x800773c0u);
  w_u32((uint32)((sint32)((uint32)(result) + (uint32)(56))), (sint32)r_u32(0x80077328u));
  w_u32((uint32)((sint32)((uint32)(result) + (uint32)(60))), v17);
  w_u32((uint32)((sint32)((uint32)(result) + (uint32)(64))), v18);
  w_u16((uint32)((sint32)((uint32)(result) + (uint32)(98))), v19);
  w_u16((uint32)((sint32)((uint32)(result) + (uint32)(100))), v20);
  w_u32((uint32)((sint32)((uint32)(result) + (uint32)(108))), v21);
  if ((v19 || v20))
  {
    v22 = (sint32)r_u32(0x800775b8u);
    v23 = (sint32)r_u32(0x8007736cu);
    v24 = (sint32)r_u32(0x800775c4u);
    v25 = (sint16)r_u16(0x80077524u);
    v26 = (sint16)r_u16(0x8007751eu);
    v27 = (sint16)r_u16(0x80077522u);
    v28 = (sint16)r_u16(0x8007751cu);
    v29 = (sint16)r_u16(0x8007752cu);
    v30 = (sint16)r_u16(0x80077520u);
    v31 = (sint16)r_u16(0x8007735cu);
    v32 = (sint32)r_u32(0x80077560u);
    v33 = (sint32)r_u32(0x80077558u);
    v34 = (sint32)r_u32(0x80077648u);
    w_u32((uint32)((sint32)((uint32)(result) + (uint32)(68))), (sint32)r_u32(0x800773dcu));
    w_u32((uint32)((sint32)((uint32)(result) + (uint32)(72))), v22);
    w_u32((uint32)((sint32)((uint32)(result) + (uint32)(76))), v23);
    w_u32((uint32)((sint32)((uint32)(result) + (uint32)(80))), v24);
    w_u16((uint32)((sint32)((uint32)(result) + (uint32)(84))), v25);
    w_u16((uint32)((sint32)((uint32)(result) + (uint32)(86))), v26);
    w_u16((uint32)((sint32)((uint32)(result) + (uint32)(88))), v27);
    w_u16((uint32)((sint32)((uint32)(result) + (uint32)(90))), v28);
    w_u16((uint32)((sint32)((uint32)(result) + (uint32)(92))), v29);
    w_u16((uint32)((sint32)((uint32)(result) + (uint32)(94))), v30);
    w_u16((uint32)((sint32)((uint32)(result) + (uint32)(96))), v31);
    w_u32((uint32)((sint32)((uint32)(result) + (uint32)(104))), v32);
    w_u32((uint32)((sint32)((uint32)(result) + (uint32)(112))), v33);
    w_u32((uint32)((sint32)((uint32)(result) + (uint32)(116))), v34);
  }
  return result;
}


uint32 sub_800224A0(void)
{
    FUNCTION_MARKER(0x800224a0u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8005B994 */
    /* TODO: Bind external adapter for sub_8005C504 */
    uint32 local_objects = ob_draft_scratch_acquire(6u);
  sint32 v0;
  sint32 v1;
  sint32 v2;
  sint32 result;
  ;
  ;
  w_u32(local_objects + 0u, (sint32)r_u32(0x8001086cu));
  w_u16(local_objects + 4u, (sint16)r_u16(0x80010870u));
  sub_80030700(0, 0, 0);
  sub_8003077C(local_objects, 255u, 2u, 255u, 255u, 255u);
  sub_8002D25C((sint32)(0u - (uint32)(2146906416)), (sint32)(0u - (uint32)(2146931856)));
  if ((sint32)r_u32(0x800773d0u))
    v0 = (sint32)(0u - (uint32)(2146906256));
  else
    v0 = (sint32)(0u - (uint32)(2146908472));
  ob_draft_unresolved_call(0x8005b994u, 2u, (sint32)((uint32)((sint32)r_u32(0x8007737cu)) + (uint32)(112)), v0);
  while ((sint32)r_u32(0x80077620u))
    ob_native_pump();

  ob_draft_unresolved_call(0x8005c504u, 1u, 0);
  w_u32(0x8007754cu, (sint32)r_u32(0x8007737cu));
  sub_8002CFA8();
  sub_8002D25C((sint32)(0u - (uint32)(2146906416)), (sint32)(0u - (uint32)(2146931856)));
  if ((sint32)r_u32(0x800773d0u))
    v1 = (sint32)(0u - (uint32)(2146906256));
  else
    v1 = (sint32)(0u - (uint32)(2146908472));
  ob_draft_unresolved_call(0x8005b994u, 2u, (sint32)((uint32)((sint32)r_u32(0x8007737cu)) + (uint32)(112)), v1);
  while ((sint32)r_u32(0x80077620u))
    ob_native_pump();

  ob_draft_unresolved_call(0x8005c504u, 1u, 0);
  w_u32(0x8007754cu, (sint32)r_u32(0x8007737cu));
  sub_8002CFA8();
  w_u32(0x80077620u, 1);
  sub_8002D25C((sint32)(0u - (uint32)(2146906416)), (sint32)(0u - (uint32)(2146931856)));
  if ((sint32)r_u32(0x800773d0u))
    v2 = (sint32)(0u - (uint32)(2146906256));
  else
    v2 = (sint32)(0u - (uint32)(2146908472));
  ob_draft_unresolved_call(0x8005b994u, 2u, (sint32)((uint32)((sint32)r_u32(0x8007737cu)) + (uint32)(112)), v2);
  while ((sint32)r_u32(0x80077620u))
    ob_native_pump();

  ob_draft_unresolved_call(0x8005c504u, 1u, 0);
  w_u32(0x8007754cu, (sint32)r_u32(0x8007737cu));
  sub_8002CFA8();
  result = 1;
  w_u32(0x80077620u, 1);
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80046EAC(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80046eacu, "SLES_008.65");
    /* TODO: Recover missing meaningful carriers for sub_80047A60 before binding the native call */
  sint32 v3;
  uint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  uint32 v8;
  sint32 v9;
  uint32 v10;
  sint32 v11;
  sint32 v12;
  sint32 v13;
  sint32 v16;
  sint32 v17;
  sint32 v18;
  v3 = 0x7FFFFFFF;
  v16 = (sint32)(0u - (uint32)(1));
  v4 = (uint32)((sint32)r_u32(0x80077140u));
  v5 = 0x7FFFFFFF;
  v6 = 0;
  v17 = (sint32)(0u - (uint32)(1));
  v7 = r_u32((a1 + (6) * 4u));
  v8 = r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(v7))) + (uint32)((sint32)r_u32(0x80077148u)))));
  v9 = 0;
  if (((sint32)(v7) > (sint32)(0)))
  {
    v10 = (v8 + (1) * 4u);
    do
    {
      v11 = r_u32(v4);
      if (r_u32(v4))
      {
        v12 = (sint32)r_u32(v8);
        v18 = v3;
        sub_800477B8(a1, r_u32(v4), a2, v8);
        v3 = v18;
        if ((((sint32)r_u32(v8) & 0x8000) != 0))
        {
          if (((sint32)((sint32)r_u32(v10)) < (sint32)(v5)))
          {
            v5 = (sint32)r_u32(v10);
            v17 = r_u32((uint32)((sint32)((uint32)(v11) + (uint32)(24))));
          }
          ++v9;
          if (((v12 & 0x8000) != 0))
            goto LABEL_14;
          v13 = ((uint32)(r_u32((uint32)((sint32)((uint32)(v11) + (uint32)(184))))) + (uint32)(1));
        }
        else
        {
          if (((sint32)((sint32)r_u32(v10)) < (sint32)(v18)))
          {
            v3 = (sint32)r_u32(v10);
            v16 = r_u32((uint32)((sint32)((uint32)(v11) + (uint32)(24))));
          }
          if (((v12 & 0x8000) == 0))
            goto LABEL_14;
          v13 = ((uint32)(r_u32((uint32)((sint32)((uint32)(v11) + (uint32)(184))))) - (uint32)(1));
        }
        w_u32((uint32)((sint32)((uint32)(v11) + (uint32)(184))), v13);
      }
      LABEL_14:
      v10 += (2) * 4u;

      v8 += (2) * 4u;
      ++v6;
      ((v4 += 4u));
    }
    while ((v6 < (sint32)r_u32((a1 + (6) * 4u))));
  }
  w_u32((a1 + (45) * 4u), v9);
  w_u32((a1 + (50) * 4u), v16);
  w_u32((a1 + (49) * 4u), v3);
  w_u32((a1 + (48) * 4u), v17);
  w_u32((a1 + (47) * 4u), v5);
  return ob_draft_unresolved_call(0x80047a60u, 0u);
}


uint32 sub_80016598(uint32 a1)
{
    FUNCTION_MARKER(0x80016598u, "SLES_008.65");
    uint32 local_objects = ob_draft_scratch_acquire(20u);
  sint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  ;
  uint32 v8;
  ;
  v2 = (sint32)(0u - (uint32)(2146649600));
  v3 = 100;
  v4 = 0;
  v5 = 0;
  v6 = (sint32)(0u - (uint32)(2146649568));
  w_u16(0x80077668u, r_u8((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8006c134u)) + (uint32)(108))))) + (uint32)(178)))));
  do
  {
    w_u32(local_objects + 16u, r_u32((uint32)((sint32)((uint32)(v6) + (uint32)(64)))));
    if ((r_u32(local_objects + 16u) == 236))
    {
      if ((r_u16((uint32)((sint32)((uint32)(v6) + (uint32)(20)))) < v3))
      {
        v3 = r_u16((uint32)((sint32)((uint32)(v6) + (uint32)(20))));
        v4 = v2;
      }
    }
    else
    {
      if ((r_u32(local_objects + 16u) >= 0xED))
      {
        if (((r_u32(local_objects + 16u) < 0xF8) && (r_u32(local_objects + 16u) >= 0xF2)))
        {
          v8 = (0x80068304u);
          LABEL_18:
          sub_80016390((sint32)(v8));

          goto LABEL_19;
        }
      }
      else
      {
        if (!r_u32(local_objects + 16u))
          goto LABEL_19;
        if ((r_u32(local_objects + 16u) == 235))
        {
          if (!(r_u16((uint32)((sint32)((uint32)(v6) + (uint32)(18))))))
            goto LABEL_19;
          v8 = (0x80068300u);
          goto LABEL_18;
        }
      }
      if (((sint16)r_u16(0x80077668u) && (r_u16((uint32)((sint32)((uint32)(v6) + (uint32)(22)))) == (uint16)((sint16)r_u16(0x80077668u)))))
      {
        v8 = (sint32)r_u32(0x80068308u);
        goto LABEL_18;
      }
    }
    LABEL_19:
    v6 = ((uint32)(v6) + (uint32)(104));

    ++v5;
    v2 = ((uint32)(v2) + (uint32)(104));
  }
  while (((sint32)(v5) < (sint32)(400)));
  if (v4)
    sub_80016390((sint32)((0x800682fcu)));
  sub_80045A7C(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8006c134u)) + (uint32)(44)))), a1);
  sub_80045378(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8006c134u)) + (uint32)(44)))), a1, (local_objects + 0u));
  { uint32 draft_return = sub_80016390((sint32)((0x800682f8u))); ob_draft_scratch_release(local_objects);  return draft_return; }
}



