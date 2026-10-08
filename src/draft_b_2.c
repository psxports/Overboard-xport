#include "draft_signatures.h"
#include "native_runtime.h"
#include "psx.h"

/* Unverified draft bodies */

uint32 sub_800423D8(void)
{
    FUNCTION_MARKER(0x800423d8u, "SLES_008.65");
  uint32 result;
  uint32 v1;
  w_u8(0x8007763au, 2);
  result = (r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800775d0u)) + (uint32)(48)))) & 0xFFFFFFDF);
  v1 = ((sint32)r_u32(0x800773d8u) == 0);
  w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800775d0u)) + (uint32)(48))), result);
  if (!v1)
    return sub_80042424((sint32)r_u32(0x80077554u));
  return result;
}


uint32 sub_80022058(void)
{
    FUNCTION_MARKER(0x80022058u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80059F3C */
    /* TODO: Bind external adapter for sub_80024F18 */
  sint32 result;
  w_u32(0x80089B7C, 1);
  while (!(sint32)r_u32(0x80084448))
    ob_native_pump();

  result = ob_draft_unresolved_call(0x80059f3cu, 1u, 0x8002cff4u);
  result = ob_set_update_callback(0u, (uint32)result);
  w_u32(0x8006c0d8u, 0);
  return result;
}


uint32 sub_80021FF4(uint32 a1)
{
    FUNCTION_MARKER(0x80021ff4u, "SLES_008.65");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
  uint32 v1;
  sint32 result;
  v1 = ((uint32)((sint32)((uint32)(100) * (uint32)((sint32)((uint32)((sint32)r_u32(0x80083E7C)) + (uint32)(a1))))) / (sint32)r_u32(0x80083E30));
  if (!(sint32)r_u32(0x80083E30))
    ob_draft_unresolved_call(0x80021ff4u, 2u, 7u, 0);
  w_u32(0x80083E7C, ((uint32)((sint32)r_u32(0x80083E7C)) + (uint32)(a1)));
  result = 1;
  if ((v1 >= 0x5F))
    w_u32(0x80089B7C, 1);
  return result;
}


uint32 sub_800276B4(uint32 a1)
{
    FUNCTION_MARKER(0x800276b4u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80027AE4 */
  uint32 result;
  result = (uint32)(ob_draft_unresolved_call(0x80027ae4u, 1u, r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(38))))));
  if (result)
  {
    result = r_u32((uint32)(((uint32)(r_u32((uint32)(result))) + (uint32)(4))));
    if (result)
      return (uint32)(ob_draft_unresolved_call(result, 1u, r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))))));
  }
  return result;
}


uint32 sub_8002C77C(uint32 a1)
{
    FUNCTION_MARKER(0x8002c77cu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8005A9DC */
    /* TODO: Bind external adapter for sub_8002C7D8 */
  if ((a1 == 1))
  {
    ob_draft_unresolved_call(0x8005a9dcu, 1u, 0);
    ob_draft_unresolved_call(0x8002c7d8u, 0u);
  }
  else
    if ((a1 == 3))
  {
    ob_draft_unresolved_call(0x8005a9dcu, 1u, 1);
    sub_8002CA3C();
  }
  return (sint32)(0u - (uint32)(1));
}


uint32 sub_800442F0(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x800442F0u, "SLES_008.65");
    uint32 attached = r_u32(a1 + 36u);
    if (attached)
    {
        /* TODO: Bind the original attached model rendering helper */
        return ob_draft_unresolved_call(0x8004492Cu, 5u,
            r_u32(a1 + 36u), r_u32(attached + 40u), a1, a2 & 0xFFFFu, a3 & 0xFFFFu);
    }
    return sub_8004434C(a1, a2 & 0xFFFFu, a3 & 0xFFFFu);
}


uint32 sub_8004F418(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x8004f418u, "SLES_008.65");
  sint32 v3;
  sint32 result;
  sint32 v5;
  v3 = r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))))) + (uint32)(160))));
  result = (v3 & 0x60);
  if (((v3 & 0x60) != 0))
  {
    v5 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(208))));
    result = (v3 & 0x40);
    if (((v5 & 8) != 0))
    {
      if (((v3 & 0x40) != 0))
        w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(208))), (v5 | 0x80000000));
      return sub_8004F758(a1, a3);
    }
  }
  return result;
}


uint32 sub_8002328C(void)
{
    FUNCTION_MARKER(0x8002328cu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80044C58 */
  sint32 result;
  sub_80022E78();
  sub_80054264();
  w_u32(0x80083E34, sub_800435AC(0, 0));
  /* TODO: Resolve the external return carried through the empty nullsub */
  result = ob_draft_unresolved_call(0x80044c58u, 0u);
  nullsub_25();
  w_u8(0x8008C6CC, 0);
  w_u8(0x8008C6CD, 0);
  w_u8(0x8008C6CE, 0);
  w_u8(0x8008CF74, 0);
  w_u8(0x8008CF75, 0);
  w_u8(0x8008CF76, 0);
  return result;
}


uint32 sub_80023138(void)
{
    FUNCTION_MARKER(0x80023138u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8002D888 */
    /* TODO: Bind external adapter for sub_80063F28 */

  sint32 result;
  sub_8002C728(3);
  w_u32(0x800773b8u, 5000000);
  w_u32(0x800773b4u, 5);
  result = sub_8002D078(51200u, 291u, 2u, 5u, 5000000u);
  if (!result)
  {
    ob_draft_unresolved_call(0x8002d888u, 0u);
    return ob_draft_unresolved_call(0x80063f28u, 1u, 1);
  }
  return result;
}


uint32 sub_80022440(void)
{
    FUNCTION_MARKER(0x80022440u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8005C890 */
    uint32 local_objects = ob_draft_scratch_acquire(8u);
  sint16 v0;
  sint32 v1;
  ;
  v0 = 196;
  w_u16(((local_objects + 0u) + (0) * 2u), 234);
  if (!(sint32)r_u32(0x800773d0u))
    v0 = 452;
  v1 = 166;
  w_u16(((local_objects + 0u) + (2) * 2u), 37);
  w_u16(((local_objects + 0u) + (1) * 2u), v0);
  w_u16(((local_objects + 0u) + (3) * 2u), 5);
  if ((sint32)r_u32(0x800773d0u))
    v1 = 422;
  { uint32 draft_return = ob_draft_unresolved_call(0x8005c890u, 3u, (local_objects + 0u), 173, v1); ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80029EEC(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80029eecu, "SLES_008.65");
  sint32 v2;
  sint16 v3;
  sint32 result;
  v2 = (sint32)((uint32)(2) * (uint32)((((uint32)(a1) + (uint32)(8)) >> 4)));
  v3 = r_u16((uint32)((sint32)((uint32)(v2) - (uint32)(2147040508))));
  v2 = ((uint32)(v2) & ~((uint32)65535u << 0) | (((uint32)(r_u16((uint32)((sint32)((uint32)(v2) - (uint32)(2147038460))))) & 65535u) << 0));
  result = 0x4000;
  w_u16((a2 + (2) * 2u), 0);
  w_u16((a2 + (5) * 2u), 0);
  w_u16((a2 + (6) * 2u), 0);
  w_u16((a2 + (7) * 2u), 0);
  w_u16((a2 + (8) * 2u), 0x4000);
  w_u16((a2 + (1) * 2u), v3);
  w_u16(a2, v2);
  w_u16((a2 + (3) * 2u), (sint32)(0u - (uint32)(v3)));
  w_u16((a2 + (4) * 2u), v2);
  return result;
}


void sub_80061034(void)
{
    FUNCTION_MARKER(0x80061034u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80061010 */
    /* TODO: Bind external adapter for sub_80055894 */
    /* TODO: Bind external adapter for sub_800558C4 */
  if (((sint32)r_u32(0x80076338u) == 1))
  {
    w_u32(0x80076338u, 0);
    sub_800558E4();
    w_u32(0x80076374u, 0);
    w_u32(0x80076378u, 0);
    ob_draft_unresolved_call(0x80061010u, 0u);
    ob_draft_unresolved_call(0x80055894u, 0u);
    ob_draft_unresolved_call(0x800558c4u, 0u);
    sub_800558F4();
  }
}


uint32 sub_80024EA8(void)
{
    FUNCTION_MARKER(0x80024ea8u, "SLES_008.65");
  uint32 v0;
  sint32 result;
  uint32 i;
  sint32 v3;
  nullsub_18();
  v0 = (0x8006bc44u);
  result = (sint32)r_u32(0x8006bc40u);
  for (i = 0; (i < (sint32)r_u32(0x8006bc40u)); result = (i < (sint32)r_u32(0x8006bc40u)))
  {
    v3 = (sint32)(r_u32(((v0 += 4u) - 4u)));
    sub_80027E54(i++, v3);
  }

  return result;
}


uint32 sub_8002CFF4(void)
{
    FUNCTION_MARKER(0x8002cff4u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8005CD50 */
    /* TODO: Bind external adapter for sub_8005CB78 */
    /* TODO: Bind external adapter for sub_8005CB04 */
  sint32 result;
  result = (sint32)r_u32(0x80077620u);
  w_u32(0x80073514u, 0);
  if ((sint32)r_u32(0x80077620u))
  {
    w_u32(0x80077620u, 0);
    ob_draft_unresolved_call(0x8005cd50u, 1u, (sint32)((uint32)((sint32)r_u32(0x8007754cu)) + (uint32)(92)));
    ob_draft_unresolved_call(0x8005cb78u, 1u, (sint32)r_u32(0x8007754cu));
    if ((sint32)r_u32(0x80073518u))
      ob_draft_unresolved_call(r_u32(0x80073518u), 0u);
    return ob_draft_unresolved_call(0x8005cb04u, 1u, (sint32)((uint32)((sint32)r_u32(0x8007754cu)) + (uint32)(112)));
  }
  return result;
}


uint32 sub_800174CC(uint32 a1)
{
    FUNCTION_MARKER(0x800174ccu, "SLES_008.65");
  sint32 result;
  sub_80026694((0x8006601cu), a1, 0);
  sub_80026694((0x80066020u), a1, 0);
  result = 1;
  w_u32(0x80066028u, 0);
  w_u32(0x80077374u, a1);
  w_u32(0x80066024u, 1);
  w_u32(0x800775c0u, (sint32)r_u32(0x8006601cu));
  w_u32(0x80077368u, (sint32)r_u32(0x80066020u));
  return result;
}


uint32 sub_80023AA8(void)
{
    FUNCTION_MARKER(0x80023aa8u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80055FD8 */
  sub_800556F4();
  ob_draft_unresolved_call(0x80055fd8u, 2u, 0, (sint32)(0u - (uint32)(2146919536)));
  sub_800251E8((0x8006aa70u));
  sub_800256CC((0x8006aa74u));
  sub_80023B28(0x8006AA78u, 0);
  sub_800259AC(0x8006AA78u);
  sub_80021EFC();
  return sub_80055808();
}


uint32 sub_8004E518(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    FUNCTION_MARKER(0x8004e518u, "SLES_008.65");
    uint32 local_objects = ob_draft_scratch_acquire(4u);
  ;
  w_u32(local_objects + 0u, 0);
  sub_800262CC((local_objects + 0u), 56);
  sub_8004E584((sint32)r_u32(local_objects + 0u), a1, a2);
  w_u8((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 0u)) + (uint32)(54))), a4);
  { uint32 draft_return = (sint32)r_u32(local_objects + 0u); ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_8001DEB4(uint32 a1)
{
    FUNCTION_MARKER(0x8001deb4u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80061924 */
    uint32 local_objects = ob_draft_scratch_acquire((uint32)sizeof(SpuReverbAttr));
  sint32 result;
  ;
  ;
  ;
  a1 &= 255u;
  result = (uint8)((sint8)r_u8(0x8006c00cu));
  if ((sint8)r_u8(0x8006c00cu))
  {
    result = a1;
    if ((sint8)r_u8(0x8006c00du))
    {
      if ((a1 >= 0x80u))
        a1 = 127;
      w_u8(0x80078BE8, a1);
      result = 6;
      if ((sint8)r_u8(0x8006c00eu))
      {
        w_u32(local_objects + 0u, 6);
        w_u16(local_objects + 8u, ((uint32)(a1) << (uint32)(8)));
        w_u16(local_objects + 10u, (sint32)((uint32)((sint32)(0u - (uint32)(256))) * (uint32)(a1)));
        { uint32 draft_return = ob_draft_unresolved_call(0x80061924u, 1u, (local_objects + 0u)); ob_draft_scratch_release(local_objects);  return draft_return; }
      }
    }
  }
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_8004B634(void)
{
    FUNCTION_MARKER(0x8004b634u, "SLES_008.65");
  sint32 i;
  sint32 result;
  sint32 v2;
  sint16 v3;
  sint32 v4;
  for (i = (sint32)r_u32(0x800774d0u); i; i = r_u32((uint32)((sint32)((uint32)(i) + (uint32)(32)))))
  {
    result = (r_u16((uint32)((sint32)((uint32)(i) + (uint32)(38)))) & 0x400);
    if (((r_u16((uint32)((sint32)((uint32)(i) + (uint32)(38)))) & 0x400) != 0))
    {
      v2 = r_u8((uint32)((sint32)((uint32)(i) + (uint32)(55))));
      v3 = r_u16((uint32)((sint32)((uint32)(i) + (uint32)(38))));
      v4 = r_u32((uint32)((sint32)((uint32)(i) + (uint32)(24))));
      w_u8((uint32)((sint32)((uint32)(i) + (uint32)(55))), 0);
      w_u16((uint32)((sint32)((uint32)(i) + (uint32)(38))), (v3 | 0x80));
      result = sub_800442F0(v4, ((v2 != 0)) ? (0x4800) : (0), 5u);
    }
  }

  return result;
}


uint32 sub_8002F284(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8002f284u, "SLES_008.65");
  sint32 v2;
  sint32 result;
  sint16 v4;
  sint16 v5;
  v2 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(48))));
  if (((v2 & 1) != 0))
  {
    result = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(70))));
    v4 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(74))));
    w_u32((uint32)(a2), result);
    w_u16((uint32)((sint32)((uint32)(a2) + (uint32)(4))), v4);
  }
  else
    if (((v2 & 2) != 0))
  {
    return sub_8002F310(a1, a2);
  }
  else
  {
    result = (sint32)r_u32(0x800770dcu);
    v5 = (sint16)r_u16(0x800770e0u);
    w_u32((uint32)(a2), (sint32)r_u32(0x800770dcu));
    w_u16((uint32)((sint32)((uint32)(a2) + (uint32)(4))), v5);
  }
  return result;
}


uint32 sub_8004A410(uint32 a1)
{
    FUNCTION_MARKER(0x8004a410u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_800263B4 */
  uint32 v2;
  sint32 v3;
  sint32 result;
  v2 = (0x80077490u);
  if (((sint32)r_u32(0x80077490u) != a1))
  {
    do
    {
      v3 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v2)) + (uint32)(28))));
      v2 = (uint32)((sint32)((uint32)((sint32)r_u32(v2)) + (uint32)(28)));
    }
    while ((v3 != a1));
  }
  if (r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(48)))))
    ob_draft_unresolved_call(0x800263b4u, 1u, (uint32)((sint32)((uint32)(a1) + (uint32)(48))));
  result = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(28))));
  w_u32(v2, result);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(28))), 0);
  return result;
}


uint32 sub_80054C14(void)
{
    FUNCTION_MARKER(0x80054c14u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80055A24 */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
  sint32 v0;
  uint32 v1;
  if ((sint32)r_u32(0x80084A48))
    v0 = ob_draft_unresolved_call(0x80055a24u, 1u, (sint32)(0u - (uint32)(234881023)));
  else
    v0 = 0;
  v1 = (sint32)((uint32)(((sint32)((sint32)((uint32)(1000) * (uint32)(v0))) / (sint32)(0x3840u))) + (uint32)((sint32)r_u32(0x80084A48)));
  if ((v1 < (sint32)r_u32(0x8007FA80)))
    v1 = (sint32)r_u32(0x8007FA80);
  w_u32(0x8007FA80, v1);
  return v1;
}


uint32 sub_800556F4(void)
{
    FUNCTION_MARKER(0x800556f4u, "SLES_008.65");
  sint32 v0;
  sint32 v1;
  sint32 v2;
  sint32 result;
  v0 = (sint32)(0u - (uint32)(2146925900));
  v1 = 0;
  w_u32(0x800771ecu, 128);
  v2 = (sint32)(0u - (uint32)(2146925900));
  do
  {
    v0 = ((uint32)(v0) + (uint32)(16));
    w_u32((uint32)((sint32)((uint32)(v1) - (uint32)(2146925912))), 0);
    w_u32((uint32)((sint32)((uint32)(v1) - (uint32)(2146925900))), 0);
    v1 = ((uint32)(v1) + (uint32)(16));
    sub_80026694(v2, (sint32)((uint32)((sint32)r_u32(0x800771ecu)) << (uint32)(11)), 0);
    v2 = v0;
  }
  while (((sint32)(v1) <= (sint32)(0)));
  result = 1;
  w_u32(0x800771e4u, 1);
  return result;
}


uint32 sub_80044474(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x80044474u, "SLES_008.65");
  sint32 result;
  sint32 v6;
  uint16 i;
  result = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(60))));
  v6 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(32))));
  for (i = (result | 4); v6; v6 = r_u32((uint32)((sint32)((uint32)(v6) + (uint32)(28)))))
  {
    result = r_u32((uint32)((sint32)((uint32)(v6) + (uint32)(44))));
    if ((result == a2))
      result = sub_800442F0(v6, a3, i);
  }

  return result;
}


uint32 sub_80048020(uint32 a1)
{
    FUNCTION_MARKER(0x80048020u, "SLES_008.65");
  sint32 v1;
  uint32 v2;
  sint32 v3;
  sint32 result;
  v1 = r_u32((a1 + (19) * 4u));
  v2 = (uint32)(r_u32((a1 + (5) * 4u)));
  if ((v1 < (sint32)r_u32((a1 + (20) * 4u))))
    v1 = r_u32((a1 + (20) * 4u));
  v3 = r_u32((a1 + (18) * 4u));
  if (((sint32)(v3) < (sint32)(v1)))
    v3 = v1;
  if (((sint32)(v3) < (sint32)(0)))
  {
    result = (r_u32(v2) | 0x8000);
    w_u32((v2 + (1) * 4u), r_u32(a1));
    w_u32(v2, result);
  }
  else
  {
    w_u32(v2, ((r_u32(v2) & 0xFFFFFF07) | 0x10));
    return sub_800487B8(a1);
  }
  return result;
}


uint32 sub_80047F60(uint32 a1)
{
    FUNCTION_MARKER(0x80047f60u, "SLES_008.65");
  uint32 v2;
  sint32 v3;
  v2 = (uint32)(r_u32((a1 + (2) * 4u)));
  if ((!r_u32((a1 + (7) * 4u)) || !r_u32((v2 + (63) * 4u))))
    return sub_80047FF0(a1);
  v3 = r_u32((a1 + (3) * 4u));
  if ((r_u32((v2 + (65) * 4u)) == v3))
  {
    (w_u32((v2 + (66) * 4u), (r_u32((v2 + (66) * 4u)) + 1u)), r_u32((v2 + (66) * 4u)));
  }
  else
  {
    w_u32((v2 + (65) * 4u), v3);
    w_u32((v2 + (66) * 4u), 0);
  }
  return ob_draft_unresolved_call((uint32)(r_u32((v2 + (63) * 4u))), 3u, r_u32((v2 + (61) * 4u)), a1, r_u32((a1 + (3) * 4u)));
}


uint32 sub_80018454(void)
{
    FUNCTION_MARKER(0x80018454u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80054440 */
    /* TODO: Bind external adapter for sub_800184EC */
    /* TODO: Bind external adapter for sub_800540F8 */
    /* TODO: Bind external adapter for sub_800541A8 */
  sint32 result;
  uint32 v1;
  if (ob_draft_unresolved_call(0x80054440u, 1u, (uint8)((sint32)r_u32((sint32)r_u32(0x80065cacu)))))
    return ob_draft_unresolved_call(0x800184ecu, 0u);
  if (!ob_draft_unresolved_call(0x800540f8u, 1u, 0))
    return ob_draft_unresolved_call(0x800184ecu, 0u);
  result = 0;
  if (((uint8)((sint8)r_u8(0x8006c230u)) >= 2u))
  {
    result = 0;
    if (((sint32)((sint32)r_u32(0x8006c130u)) > (sint32)(0)))
    {
      v1 = (ob_draft_unresolved_call(0x800541a8u, 1u, 0) != 0);
      result = 0;
      if (!v1)
      {
        v1 = (ob_draft_unresolved_call(0x800541a8u, 1u, 4) != 0);
        result = 0;
        if (!v1)
          return ob_draft_unresolved_call(0x800184ecu, 0u);
      }
    }
  }
  return result;
}


uint32 sub_800117C8(uint32 a1)
{
    FUNCTION_MARKER(0x800117c8u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8001E050 */
    /* TODO: Bind external adapter for sub_800255F0 */
  sint32 result;
  w_u32(0x800882C0, 150);
  sub_8001DBCC((uint8)(a1));
  sub_8001DCF4();
  sub_8001DDF8();
  sub_8001DEB4(16);
  ob_draft_unresolved_call(0x8001e050u, 0u);
  w_u32(0x80065b70u, (a1 == 4));
  ob_draft_unresolved_call(0x800255f0u, 2u, (0x80066140u), 0x800121ccu);
  sub_800118C0(a1);
  result = 3;
  w_u32(0x80065b7cu, 3);
  return result;
}


uint32 sub_8002F4CC(uint32 a1)
{
    FUNCTION_MARKER(0x8002f4ccu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8002F5FC */
    /* TODO: Bind external adapter for sub_8002F594 */
    /* TODO: Bind external adapter for sub_8002F560 */
  sint32 v2;
  sint32 v3;
  v2 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(48))));
  if (((v2 & 2) == 0))
  {
    if (((v2 & 1) != 0))
    {
      ob_draft_unresolved_call(0x8002f5fcu, 2u, a1, (sint32)((uint32)(a1) + (uint32)(70)));
      v3 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(48))));
      w_u16((uint32)((sint32)((uint32)(a1) + (uint32)(18))), 0);
      w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(48))), ((v3 & 0xFFFFFFE1) | 2));
    }
    else
    {
      ob_draft_unresolved_call(0x8002f594u, 2u, a1, (0x800770dcu));
    }
  }
  return ob_draft_unresolved_call(0x8002f560u, 1u, a1);
}


uint32 sub_8004DAA4(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    FUNCTION_MARKER(0x8004daa4u, "SLES_008.65");
    uint32 local_objects = ob_draft_scratch_acquire(24u);
  sint32 v4;
  sint32 v5;
  sint32 v6;
  ;
  ;
  v4 = ((uint32)(r_u32((uint32)((sint32)r_u32(0x80077644u)))) << (uint32)((sint32)((uint32)(2) * (uint32)((sint32)((uint32)(2) - (uint32)(a3))))));
  v5 = (sint32)((uint32)(a1) * (uint32)(v4));
  v6 = (sint32)((uint32)(a2) * (uint32)(v4));
  w_u32(((local_objects + 0u) + (1) * 4u), a4);
  v4 /= 2;
  w_u32(((local_objects + 0u) + (0) * 4u), (sint32)((uint32)((sint32)((uint32)(v5) - (uint32)((sint32)r_u32(0x80077458u)))) + (uint32)(v4)));
  w_u32(((local_objects + 0u) + (2) * 4u), (sint32)((uint32)((sint32)((uint32)((sint32)r_u32(0x80077468u)) - (uint32)(v6))) - (uint32)(v4)));
  { uint32 draft_return = sub_8004DB40((local_objects + 0u), a3, (local_objects + 16u)); ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80034114(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80034114u, "SLES_008.65");
    uint32 local_objects = ob_draft_scratch_acquire(4u);
  sint32 v4;
  sint16 v5;
  sint32 v6;
  ;
  w_u32(local_objects + 0u, 0);
  sub_800262CC((local_objects + 0u), 24);
  v4 = (sint32)r_u32(local_objects + 0u);
  v5 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(4))));
  w_u8((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 0u)) + (uint32)(10))), 0);
  v6 = (sint32)r_u32(local_objects + 0u);
  w_u16((uint32)((sint32)((uint32)(v4) + (uint32)(8))), v5);
  w_u32((uint32)((sint32)((uint32)(v6) + (uint32)(16))), (sint32)((uint32)((sint32)r_u32(0x800882BC)) + (uint32)(r_u16((uint32)((sint32)((uint32)(v6) + (uint32)(8)))))));
  if ((a2 == 1))
    w_u32(0x8007742cu, v6);
  else
    w_u32(0x80077464u, v6);
  { uint32 draft_return = (sint32)r_u32(local_objects + 0u); ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_8002B868(uint32 a1)
{
    FUNCTION_MARKER(0x8002b868u, "SLES_008.65");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
  uint32 v1;
  sint32 i;
  uint32 v3;
  v1 = a1;
  if (a1)
  {
    for (i = 0; ((a1 & 0xC0000000) == 0); ++i)
      a1 = ((uint32)(a1) * (uint32)(4));

    v3 = r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((((uint32)((a1 >> 23)) + (uint32)(1)) >> 1)))) - (uint32)(2147012336))));
    if (i)
      v3 = (((uint32)(v3) + (uint32)((sint32)((uint32)(1) << (uint32)((sint32)((uint32)(i) - (uint32)(1)))))) >> i);
    a1 = (((uint32)(v3) + (uint32)((v1 / v3))) >> 1);
    if ((a1 > 0xFFFF))
      a1 = ((uint32)(a1) & ~((uint32)65535u << 0) | (((uint32)((sint32)(0u - (uint32)(1))) & 65535u) << 0));
  }
  return (uint16)(a1);
}


uint32 sub_8002D8A8(uint32 a1)
{
    FUNCTION_MARKER(0x8002d8a8u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8002D940 */
    /* TODO: Bind external adapter for sub_8002DB6C */
  uint32 v2;
  sint32 result;
  sint32 v4;
  if ((sint32)r_u32(0x800770c8u))
    ob_draft_unresolved_call(0x8002d940u, 0u);
  v2 = ((sint32)((uint32)(a1) + (uint32)(3)) & 0xFFFFFFFC);
  sub_80026734(0x800770B4u, v2);
  w_u32(0x800770c8u, (sint32)r_u32(0x800770b4u));
  w_u32(0x800770c4u, (sint32)r_u32(0x800770b4u));
  result = 0;
  if ((sint32)r_u32(0x800770b4u))
  {
    v4 = ob_draft_unresolved_call(0x8002db6cu, 2u, (sint32)r_u32(0x800770b4u), 4);
    result = (sint32)(0u - (uint32)(1));
    w_u32(0x800770c8u, v4);
    w_u32(0x80077440u, ((uint32)(v2) + (uint32)(v4)));
    w_u32(0x800770ccu, v4);
    w_u32(0x80077354u, v4);
    w_u32(0x800770d0u, ((uint32)(v2) + (uint32)(v4)));
    w_u32(0x80077358u, ((uint32)(v2) + (uint32)(v4)));
  }
  return result;
}


uint32 sub_8001DCF4(void)
{
    FUNCTION_MARKER(0x8001dcf4u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80061748 */
    /* TODO: Bind external adapter for sub_80062354 */
    /* TODO: Bind external adapter for sub_80061924 */
    /* TODO: Bind external adapter for sub_80062304 */
    /* TODO: Bind external adapter for sub_80062580 */
    uint32 local_objects = ob_draft_scratch_acquire(24u);
  sint32 result;
  uint32 v1;
  ;
  result = (uint8)((sint8)r_u8(0x8006c00cu));
  if ((sint8)r_u8(0x8006c00cu))
  {
    result = (uint8)((sint8)r_u8(0x8006c00du));
    if (!(sint8)r_u8(0x8006c00du))
    {
      ob_draft_unresolved_call(0x80061748u, 1u, 1);
      ob_draft_unresolved_call(0x80062354u, 2u, 1, 0xFFFFFF);
      w_u32(((local_objects + 0u) + (0) * 4u), 1);
      w_u32(((local_objects + 0u) + (1) * 4u), 4);
      ob_draft_unresolved_call(0x80061924u, 1u, (local_objects + 0u));
      v1 = (ob_draft_unresolved_call(0x80062304u, 1u, 1) != 1);
      result = 1;
      if (!v1)
      {
        w_u8(0x8006c00du, 1);
        w_u8(0x8006c00eu, 0);
        w_u8(0x80078BE8, 64);
        ob_draft_unresolved_call(0x80062580u, 1u, 4);
        { uint32 draft_return = ob_draft_unresolved_call(0x80061748u, 1u, 1); ob_draft_scratch_release(local_objects);  return draft_return; }
      }
    }
  }
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80011984(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7)
{
    FUNCTION_MARKER(0x80011984u, "SLES_008.65");
    sint32 resource = (sint32)r_u32(a1) / 4;
    uint32 product = a2 * r_u32(0x800882C0u);
    if ((sint32)product < 0)
        product += 255u;
    uint32 volume = (uint32)((sint32)product >> 8) & 255u;
    if (resource < 0)
    {
        /* TODO: Original negative resource path returns an undefined incoming t0 carrier */
        return ob_native_missing_value(0x80011984u, "Negative resource incoming result");
    }
    if (a7)
        return (uint32)sub_8001EBBC(resource, volume, (sint32)(a3 & 255u),
            (sint32)(a4 & 255u), (sint32)a5, (sint32)a6);
    sub_8001E7B0((uint32)resource, volume, a3 & 255u, a4 & 255u, a5, a6);
    return 0xFFFFFFFFu;
}


uint32 sub_8001FEDC(uint32 a1)
{
    FUNCTION_MARKER(0x8001FEDCu, "SLES_008.65");
    uint32 sound = 0x80078540u + 28u * a1;
    uint32 pan = r_u8(sound + 23u);
    uint32 volume = (uint32)r_u8(sound + 22u) << 6;
    sint32 left = (sint32)(volume * r_u8(0x8006C018u + pan)) >> 8;
    sint32 right = (sint32)(volume * r_u8(0x8006C036u - pan)) >> 8;
    sint32 voice = r_s8(sound + 20u);
    uint32 state = 0x800782A0u + 28u * (uint32)voice;
    uint32 result = r_u32(state + 20u);
    if (result == a1)
    {
        uint32 attribute = ob_draft_scratch_acquire((uint32)sizeof(SpuVoiceAttr));
        /* Mask selects only the two original volume halfwords */
        w_u32(attribute, 1u << ((uint32)voice & 31u));
        w_u32(attribute + 4u, 3u);
        w_u16(attribute + 8u, left);
        w_u16(attribute + 10u, right);
        w_u32(state + 8u, left);
        w_u32(state + 12u, right);
        result = ob_draft_unresolved_call(0x80062EE8u, 1u, attribute);
        ob_draft_scratch_release(attribute);
    }
    return result;
}

uint32 sub_800222FC(uint32 a1)
{
    FUNCTION_MARKER(0x800222fcu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8005C890 */
    uint32 local_objects = ob_draft_scratch_acquire(8u);
  sint16 v1;
  sint16 v2;
  sint32 v3;
  ;
  switch (a1)
  {
    case 0:
      v1 = 149;
      goto LABEL_7;

    case 1:
      v1 = 165;
      goto LABEL_7;

    case 2:
      v1 = 181;
      goto LABEL_7;

    case 3:
      v1 = 197;
      goto LABEL_7;

    case 4:
      v1 = 213;
      LABEL_7:
    w_u16(((local_objects + 0u) + (0) * 2u), v1);

      break;

    default:
      break;

  }

  v2 = 192;
  if (!(sint32)r_u32(0x800773d0u))
    v2 = 448;
  v3 = 135;
  w_u16(((local_objects + 0u) + (1) * 2u), v2);
  w_u16(((local_objects + 0u) + (2) * 2u), 16);
  w_u16(((local_objects + 0u) + (3) * 2u), 16);
  if ((sint32)r_u32(0x800773d0u))
    v3 = 391;
  { uint32 draft_return = ob_draft_unresolved_call(0x8005c890u, 3u, (local_objects + 0u), 176, v3); ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80022C1C(uint32 a1)
{
    FUNCTION_MARKER(0x80022c1cu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80063FB8 */
  sint32 v2;
  uint32 v3;
  uint32 v4;
  sint32 v5;
  v2 = 0;
  v3 = 0;
  v4 = a1;
  while ((v3 < ob_draft_unresolved_call(0x80063fb8u, 1u, a1)))
  {
    v5 = (uint8)(r_u8(v4));
    if ((v5 == 32))
    {
      v2 = ((uint32)(v2) + (uint32)(5));
    }
    else
    {
      if (((uint32)((sint32)((uint32)(v5) - (uint32)(97))) < 0x1A))
        w_u8(v4, (sint32)((uint32)(v5) - (uint32)(32)));
      v2 = ((uint32)(v2) + (uint32)((sint32)((uint32)(1) + (uint32)((sint8)r_u8((0x8006c09bu + ((uint8)(r_u8(v4))) * 1u))))));
    }
    ((v4 += 1u));
    ++v3;
  }

  return v2;
}


uint32 sub_8001D048(uint32 a1)
{
    FUNCTION_MARKER(0x8001d048u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80063FB8 */
    /* TODO: Bind external adapter for sub_80063F88 */
  sint32 v1;
  sint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 v5;
  v1 = 0;
  v2 = (sint32)((uint32)((sint32)((uint32)(552) * (uint32)(a1))) - (uint32)(2146919116));
  v3 = (sint32)((uint32)(552) * (uint32)(a1));
  do
  {
    if ((r_u32((uint32)((sint32)((uint32)(v3) - (uint32)(2146919116)))) == 1))
    {
      v4 = ob_draft_unresolved_call(0x80063fb8u, 1u, 0x8006BCCCu);
      v5 = ob_draft_unresolved_call(0x80063f88u, 3u, 0x8006BCCCu, (sint32)((uint32)(v2) + (uint32)(12)), v4);
      v2 = ((uint32)(v2) + (uint32)(36));
      if (!v5)
        return v1;
    }
    else
    {
      v2 = ((uint32)(v2) + (uint32)(36));
    }
    ++v1;
    v3 = ((uint32)(v3) + (uint32)(36));
  }
  while (((sint32)(v1) < (sint32)(15)));
  return (sint32)(0u - (uint32)(1));
}


uint32 sub_8004B450(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8004b450u, "SLES_008.65");
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
  sint32 v2;
  uint32 result;
  sint32 v4;
  sint16 v5;
  v2 = ((sint32)(a2) >> 16);
  result = a1;
  v4 = (sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x80077644u)) + (uint32)(4))));
  if (!(r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x80077644u)) + (uint32)(4))))))
    ob_draft_unresolved_call(0x8004b450u, 2u, 7u, 0);
  if (((v4 == (sint32)(0u - (uint32)(1))) && ((uint8)(v2) == 0x80000000)))
    ob_draft_unresolved_call(0x8004b450u, 2u, 6u, 0);
  v5 = ((uint8)(v2) / (sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x80077644u)) + (uint32)(4)))));
  if (!(r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x80077644u)) + (uint32)(4))))))
    ob_draft_unresolved_call(0x8004b450u, 2u, 7u, 0);
  w_u32(a1, (sint32)((uint32)((sint32)((uint32)(16) * (uint32)(((uint8)(v2) % v4)))) + (uint32)(((uint8)((v2) >> 8) & 0xF))));
  w_u32((a1 + (1) * 4u), (sint32)((uint32)((sint32)((uint32)(16) * (uint32)(v5))) + (uint32)(((uint8)((v2) >> 8) >> 4))));
  return result;
}


uint32 sub_80021EFC(void)
{
    FUNCTION_MARKER(0x80021efcu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80059F3C */
    /* TODO: Bind external adapter for sub_80035220 */
    /* TODO: Bind external adapter for sub_80024F18 */
  sint32 result;
  result = (sint32)(0u - (uint32)(1));
  w_u32(0x80083E7C, 0);
  w_u32(0x80083E30, (sint32)(0u - (uint32)(1)));
  if (!(sint32)r_u32(0x8006c0d8u))
  {
    sub_800174CC(1024);
    sub_800226D0();
    w_u32(0x80084468, 0);
    w_u32(0x80089B80, 0);
    w_u32(0x80084448, 0);
    w_u32(0x80089B7C, 0);
    ob_draft_unresolved_call(0x80059f3cu, 1u, 0x800220bcu);
    sub_80021A38(1);
    sub_800251E8((0x800769c8u));
    sub_800256CC((0x800769ccu));
    sub_80021B20(0x800769D0u);
    sub_80021C24();
    sub_80017554();
    sub_80021AD8();
    sub_80026418();
    ob_draft_unresolved_call(0x80035220u, 0u);
    w_u32(0x80077090u, 0x80021FF4u);
    result = 1;
    w_u32(0x8006c0d8u, 1);
  }
  return result;
}


uint32 sub_800502AC(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x800502acu, "SLES_008.65");
  sint32 v3;
  uint32 v4;
  sint32 result;
  w_u32((a1 + (25) * 4u), 2147483393);
  if ((((sint32)((sint32)(0u - (uint32)(a3))) < (sint32)(a2)) && ((sint32)(a2) < (sint32)((sint32)((uint32)(a3) + (uint32)((sint32)r_u32(0x800775d8u)))))))
    w_u32((a1 + (24) * 4u), 0);
  else
    w_u32((a1 + (24) * 4u), 2147483393);
  v3 = (sint32)r_u32(0x800775d8u);
  v4 = ((sint32)((sint32)((uint32)((sint32)r_u32(0x800775d8u)) - (uint32)(a3))) >= (sint32)(a2));
  w_u32((a1 + (27) * 4u), 2147483393);
  if ((v4 || ((sint32)(a2) >= (sint32)((sint32)((uint32)(a3) + (uint32)((sint32)((uint32)(2) * (uint32)(v3))))))))
    w_u32((a1 + (26) * 4u), 2147483393);
  else
    w_u32((a1 + (26) * 4u), 0);
  result = ((sint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)((sint32)r_u32(0x800775d8u)))) - (uint32)(a3))) < (sint32)(a2));
  v4 = ((sint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)((sint32)r_u32(0x800775d8u)))) - (uint32)(a3))) >= (sint32)(a2));
  w_u32((a1 + (29) * 4u), 2147483393);
  if ((v4 || (result = ((sint32)(a2) < (sint32)((sint32)((uint32)(a3) + (uint32)((sint32)r_u32(0x800775ccu))))), ((sint32)(a2) >= (sint32)((sint32)((uint32)(a3) + (uint32)((sint32)r_u32(0x800775ccu))))))))
    w_u32((a1 + (28) * 4u), 2147483393);
  else
    w_u32((a1 + (28) * 4u), 0);
  return result;
}


uint32 sub_800458B4(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x800458b4u, "SLES_008.65");
  uint32 result;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  v5 = (sint32)r_u32(a2);
  v6 = (sint32)r_u32((a2 + (1) * 4u));
  v7 = (sint32)r_u32((a2 + (2) * 4u));
  w_u32((a1 + (18) * 4u), a3);
  w_u32((a1 + (19) * 4u), a3);
  w_u32((a1 + (20) * 4u), v5);
  w_u32((a1 + (21) * 4u), v6);
  w_u32((a1 + (22) * 4u), v7);
  w_u32((a1 + (23) * 4u), (sint32)((uint32)(v5) << (uint32)(8)));
  w_u32((a1 + (24) * 4u), (sint32)((uint32)(v6) << (uint32)(8)));
  w_u32((a1 + (25) * 4u), (sint32)((uint32)(v7) << (uint32)(8)));
  ob_invalidate_object_position(a1);
  w_u32((a1 + (40) * 4u), ((uint32)(r_u32((a1 + (40) * 4u))) | (uint32)(0x40u)));
  sub_80045204((sint32)(a1));
  result = (r_u32((a1 + (40) * 4u)) & 0xFFFFFFBF);
  w_u32((a1 + (40) * 4u), result);
  return result;
}


uint32 sub_8002F310(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8002f310u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8002E8D8 */
    uint32 local_objects = ob_draft_scratch_acquire(12u);
  sint32 result;
  ;
  ;
  ;
  ;
  sub_80028280((sint16)r_u16((a1 + (8) * 2u)), (sint16)r_u16((a1 + (6) * 2u)), a2, (local_objects + 8u));
  w_u16((a2 + (1) * 2u), (sint32)(0u - (uint32)((sint16)(sub_80027F98((sint32)r_u32(local_objects + 8u), (sint16)r_u16((a1 + (7) * 2u)))))));
  w_u16(local_objects + 0u, (sint16)r_u16(a1));
  w_u16(local_objects + 2u, (sint16)r_u16((a1 + (1) * 2u)));
  w_u16(local_objects + 4u, (sint16)r_u16((a1 + (2) * 2u)));
  ob_draft_unresolved_call(0x8002e8d8u, 3u, (local_objects + 0u), (local_objects + 4u), (0u - (uint32)(r_u16(a2))));
  ob_draft_unresolved_call(0x8002e8d8u, 3u, (local_objects + 4u), (local_objects + 2u), (0u - (uint32)(r_u16((a2 + (1) * 2u)))));
  result = sub_80027F98((sint16)r_u16(local_objects + 0u), (sint16)r_u16(local_objects + 2u));
  w_u16((a2 + (2) * 2u), result);
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80047E2C(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    FUNCTION_MARKER(0x80047e2cu, "SLES_008.65");
  sint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  w_u32(0x80078ED0, a1);
  w_u32(0x80078EF4, r_u32((a1 + (62) * 4u)));
  v4 = r_u32((a1 + (64) * 4u));
  w_u32(0x80078ED4, a3);
  w_u32(0x80078EE0, a4);
  w_u32(0x80078EF8, a2);
  w_u32(0x80078EE4, v4);
  v5 = r_u32((a2 + (61) * 4u));
  w_u32(0x80078F08, a2);
  w_u32(0x80078EFC, v5);
  w_u32(0x80078F2C, r_u32((a2 + (62) * 4u)));
  v6 = r_u32((a2 + (64) * 4u));
  w_u32(0x80078F0C, a3);
  w_u32(0x80078F18, a4);
  w_u32(0x80078F30, a1);
  w_u32(0x80078F1C, v6);
  v7 = r_u32((a1 + (61) * 4u));
  w_u32(0x80078F24, (sint32)r_u32(0x80078EEC));
  w_u32(0x80078F20, (sint32)r_u32(0x80078EE8));
  w_u16(0x80078F10, (0u - (uint32)(r_u16(0x80078ED8))));
  w_u32(0x80078F28, (sint32)r_u32(0x80078EF0));
  w_u16(0x80078F14, (0u - (uint32)(r_u16(0x80078EDC))));
  w_u16(0x80078F12, (0u - (uint32)(r_u16(0x80078EDA))));
  w_u32(0x80078EC8, (sint32)(0u - (uint32)(2146988288)));
  w_u32(0x80078F34, v7);
  w_u32(0x80078F00, 0);
  w_u32(0x80078ECC, 0);
  w_u32(0x80078F04, 0);
  return sub_80047F60((sint32)(0u - (uint32)(2146988344)));
}


uint32 sub_8001F454(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8001f454u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8006272C */
  sint32 result;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  result = (uint8)((sint8)r_u8(0x8006c00cu));
  if ((sint8)r_u8(0x8006c00cu))
  {
    result = (a1 < 0x18);
    if ((a1 != (sint32)(0u - (uint32)(1))))
    {
      result = (sint32)((uint32)(8) * (uint32)(a1));
      if ((a1 < 0x18))
      {
        v4 = (sint32)((uint32)(28) * (uint32)(a1));
        result = (r_u32((uint32)((sint32)((uint32)(v4) - (uint32)(2146990780)))) & 2);
        if (result)
        {
          v5 = (sint8)r_u8((uint32)((sint32)((uint32)(v4) - (uint32)(2146990764))));
          if ((r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(28) * (uint32)(v5))) - (uint32)(2146991436)))) == a1))
          {
            a2 = (sint32)((uint32)(1) << (uint32)(v5));
            w_u32((uint32)((sint32)((uint32)((sint32)((uint32)(28) * (uint32)(v5))) - (uint32)(2146991456))), 0);
          }
          v6 = (sint8)r_u8((uint32)((sint32)((uint32)(v4) - (uint32)(2146990763))));
          if ((((sint32)(v6) >= (sint32)(0)) && (r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(28) * (uint32)(v6))) - (uint32)(2146991436)))) == a1)))
          {
            a2 |= (sint32)((uint32)(1) << (uint32)(v6));
            w_u32((uint32)((sint32)((uint32)((sint32)((uint32)(28) * (uint32)(v6))) - (uint32)(2146991456))), 0);
          }
          ob_draft_unresolved_call(0x8006272cu, 2u, 0, a2);
          result = (sint32)((uint32)(28) * (uint32)(a1));
          w_u32((uint32)((sint32)((uint32)((sint32)((uint32)(28) * (uint32)(a1))) - (uint32)(2146990780))), 0);
        }
      }
    }
  }
  return result;
}


uint32 sub_80050550(uint32 a1)
{
    FUNCTION_MARKER(0x80050550u, "SLES_008.65");
    /* TODO: Bind external adapter for nullsub_28 */
  sint32 result;
  sint32 v3;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  if ((!(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(48))))) || sub_80050380((uint32)(a1))))
  {
    v3 = (sint16)r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(40))));
    v4 = r_u32((uint32)(a1));
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(84))), r_u32((uint32)(a1)));
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(108))), v4);
    if (v3)
    {
      v5 = 1;
    }
    else
    {
      v3 = (sint16)r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(44))));
      v5 = 4;
      if (!(r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(44))))))
      {
        v3 = (sint16)r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(42))));
        v5 = 2;
      }
    }
    if (((sint32)(v3) < (sint32)(0)))
      v5 |= 8u;
    v6 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(4))));
    v7 = (sint32)r_u32(0x800775a8u);
    v8 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))));
    v9 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12))));
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(100))), v5);
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(104))), 1);
    result = (sint32)((uint32)((sint32)r_u32(0x800775b0u)) - (uint32)(v9));
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(88))), (sint32)((uint32)(v6) - (uint32)(v7)));
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(92))), v8);
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(96))), result);
  }
  else
    if (r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(56)))))
  {
    return ob_draft_unresolved_call(0x80050868u, 1u, a1);
  }
  else
  {
    return sub_80050644(a1);
  }
  return result;
}


uint32 sub_8001CF58(void)
{
    FUNCTION_MARKER(0x8001cf58u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8001CDE4 */
    /* TODO: Bind external adapter for sub_80013524 */
    /* TODO: Bind external adapter for sub_8001CF2C */
    /* TODO: Bind external adapter for sub_8001CEBC */
    /* TODO: Bind external adapter for sub_8001D818 */
    /* TODO: Bind external adapter for sub_8001CE24 */
    uint32 local_objects = ob_draft_scratch_acquire(376u);
  sint32 v0;
  sint32 v1;
  sint32 v2;
  sint32 result;
  ;
  v0 = 0;
  v1 = 0;
  while (1)
  {
    v2 = sub_80012758(v1);
    if ((!v2 || (v2 == 3)))
    {
      sub_80012BE8(v1);
      if ((sub_8001D048(v1) != (sint32)(0u - (uint32)(1))))
        v0 = 1;
    }
    if (v0)
      break;
    result = ((sint32)(++v1) < (sint32)(8));
    if (((sint32)(v1) >= (sint32)(8)))
      { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
  }

  ob_draft_unresolved_call(0x8001cde4u, 0u);
  if (ob_draft_unresolved_call(0x80013524u, 4u, v1, 0x8006BCCCu, 1u, (sint32)r_u32(0x8006bcc0u)))
  {
    if (ob_draft_unresolved_call(0x8001cf2cu, 1u, 0))
    {
      ob_draft_unresolved_call(0x8001cebcu, 2u, (local_objects + 0u), 0);
      ob_draft_unresolved_call(0x8001d818u, 1u, (local_objects + 0u));
    }
  }
  { uint32 draft_return = ob_draft_unresolved_call(0x8001ce24u, 0u); ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_8004F51C(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x8004f51cu, "SLES_008.65");
    uint32 local_objects = ob_draft_scratch_acquire(12u);
  sint32 result;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  ;
  sint16 v11;
  sint16 v12;
  sint16 v13;
  sint32 v14;
  sint32 v15;
  sint32 v16;
  sint32 v17;
  result = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(148))));
  if (result)
  {
    w_u32(((local_objects + 0u) + (1) * 4u), a2);
    w_u32(((local_objects + 0u) + (0) * 4u), a1);
    w_u32(((local_objects + 0u) + (2) * 4u), a3);
    v11 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(164))));
    v12 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(166))));
    v13 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(168))));
    v4 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(80))));
    if (v11)
    {
      v5 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(68))));
      if (((sint32)(v11) > (sint32)(0)))
        v5 = (sint32)(0u - (uint32)(v5));
      v4 = ((uint32)(v4) + (uint32)(v5));
    }
    v14 = ((sint32)(v4) >> 8);
    v6 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(84))));
    if (v12)
    {
      v7 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(72))));
      if (((sint32)(v12) > (sint32)(0)))
        v7 = (sint32)(0u - (uint32)(v7));
      v6 = ((uint32)(v6) + (uint32)(v7));
    }
    v15 = ((sint32)(v6) >> 8);
    v8 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(88))));
    if (v13)
    {
      v9 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(76))));
      if (((sint32)(v13) > (sint32)(0)))
        v9 = (sint32)(0u - (uint32)(v9));
      v8 = ((uint32)(v8) + (uint32)(v9));
    }
    v16 = ((sint32)(v8) >> 8);
    v17 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(144))));
    { uint32 draft_return = ob_draft_unresolved_call(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(148)))), 2u, r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(140)))), (local_objects + 0u)); ob_draft_scratch_release(local_objects);  return draft_return; }
  }
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_8004A1C0(void)
{
    FUNCTION_MARKER(0x8004a1c0u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8004B3C4 */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
  sint32 v0;
  sint32 v1;
  sint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 result;
  v0 = (sint32)r_u32(0x800665d8u);
  if ((((sint32)r_u32(0x800665d8u) & 3) != 0))
    v0 = sub_800257CC((sint32)((0x800665d8u)));
  else
    (w_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800665d8u)) - (uint32)(6))), (r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800665d8u)) - (uint32)(6)))) + 1u)), r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800665d8u)) - (uint32)(6)))));
  w_u32(0x80077644u, v0);
  w_u32(0x80077490u, 0);
  ob_draft_unresolved_call(0x8004b3c4u, 0u);
  v1 = (sint32)((uint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x80077644u)) + (uint32)(4))))) * (uint32)(r_u32((uint32)((sint32)r_u32(0x80077644u)))));
  v2 = (sint32)((uint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x80077644u)) + (uint32)(6))))) * (uint32)(r_u32((uint32)((sint32)r_u32(0x80077644u)))));
  v3 = ((uint32)(r_u32((uint32)((sint32)r_u32(0x80077644u)))) << (uint32)(8));
  v4 = r_u32((uint32)((sint32)r_u32(0x80077644u)));
  w_u32(0x80077320u, 0);
  w_u32(0x800775ccu, v3);
  w_u32(0x80077458u, (sint32)((uint32)(8) * (uint32)(v1)));
  w_u32(0x80077468u, (sint32)((uint32)(8) * (uint32)(v2)));
  w_u32(0x800775a8u, (sint32)((uint32)(v1) << (uint32)(11)));
  result = (sint32)((uint32)(v2) << (uint32)(11));
  w_u32(0x800775b0u, (sint32)((uint32)(v2) << (uint32)(11)));
  w_u32(0x80077528u, (sint32)((uint32)(v1) << (uint32)(12)));
  w_u32(0x80077534u, (sint32)((uint32)(v2) << (uint32)(12)));
  w_u32(0x800775d8u, ((sint32)(v3) / (sint32)(3)));
  w_u32(0x80077488u, ((sint32)(v4) / (sint32)(3)));
  return result;
}


uint32 sub_80046AF8(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80046af8u, "SLES_008.65");
    /* TODO: Recover missing meaningful argument 2 of sub_80047450 */
    /* TODO: Recover missing meaningful argument 3 of sub_80047450 */
    /* TODO: Recover missing meaningful argument 4 of sub_80047450 */

  sint32 v4;
  sint32 v5;
  uint32 v6;
  uint32 v7;
  sint32 v8;
  sint32 result;
  sint32 i;
  sint32 v11;
  v4 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))));
  v5 = (sint32)((uint32)((sint32)((uint32)(4) * (uint32)(v4))) + (uint32)(4));
  v6 = (uint32)((sint32)((uint32)((sint32)r_u32(0x80077140u)) + (uint32)(v5)));
  v7 = (uint32)((sint32)((uint32)((sint32)r_u32(0x80077148u)) + (uint32)(v5)));
  v8 = (sint32)((uint32)(v4) + (uint32)(1));
  result = ((sint32)((sint32)r_u32(0x80077260u)) < (sint32)((sint32)((uint32)(v4) + (uint32)(1))));
  for (i = (sint32)((uint32)(8) * (uint32)(v4)); ((sint32)((sint32)r_u32(0x80077260u)) >= (sint32)(v8)); ((v6 += 4u)))
  {
    v11 = r_u32(v6);
    if (r_u32(v6))
    {
      sub_80046BE8(r_u32(v6), a1, ((uint32)(r_u32(v7)) + (uint32)(i)), a2);
      sub_80047450(v11, ob_native_missing_value(0x80046af8u, "todo_argument_0"), ob_native_missing_value(0x80046af8u, "todo_argument_1"), ob_native_missing_value(0x80046af8u, "todo_argument_2"));
    }
    ((v7 += 4u));
    result = ((sint32)((sint32)r_u32(0x80077260u)) < (sint32)(++v8));
  }

  return result;
}


uint32 sub_80047050(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80047050u, "SLES_008.65");
    /* TODO: Recover missing meaningful argument 2 of sub_80047450 */
    /* TODO: Recover missing meaningful argument 3 of sub_80047450 */
    /* TODO: Recover missing meaningful argument 4 of sub_80047450 */

  sint32 v4;
  sint32 v5;
  uint32 v6;
  uint32 v7;
  sint32 v8;
  sint32 result;
  sint32 i;
  sint32 v11;
  v4 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))));
  v5 = (sint32)((uint32)((sint32)((uint32)(4) * (uint32)(v4))) + (uint32)(4));
  v6 = (uint32)((sint32)((uint32)((sint32)r_u32(0x80077140u)) + (uint32)(v5)));
  v7 = (uint32)((sint32)((uint32)((sint32)r_u32(0x80077148u)) + (uint32)(v5)));
  v8 = (sint32)((uint32)(v4) + (uint32)(1));
  result = ((sint32)((sint32)r_u32(0x80077260u)) < (sint32)((sint32)((uint32)(v4) + (uint32)(1))));
  for (i = (sint32)((uint32)(8) * (uint32)(v4)); ((sint32)((sint32)r_u32(0x80077260u)) >= (sint32)(v8)); ((v6 += 4u)))
  {
    v11 = r_u32(v6);
    if (r_u32(v6))
    {
      sub_800477B8(r_u32(v6), a1, a2, ((uint32)(r_u32(v7)) + (uint32)(i)));
      sub_80047450(v11, ob_native_missing_value(0x80047050u, "todo_argument_0"), ob_native_missing_value(0x80047050u, "todo_argument_1"), ob_native_missing_value(0x80047050u, "todo_argument_2"));
    }
    ((v7 += 4u));
    result = ((sint32)((sint32)r_u32(0x80077260u)) < (sint32)(++v8));
  }

  return result;
}


uint32 sub_80049ED4(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x80049ed4u, "SLES_008.65");
    uint32 local_objects = ob_draft_scratch_acquire(32u);
  uint32 v6;
  ;
  ;
  v6 = (uint32)(r_u32((a1 + (8) * 4u)));
  sub_800455DC(v6, a3);
  w_u32(((local_objects + 0u) + (0) * 4u), (sint32)((uint32)((sint32)((uint32)((sint32)r_u32((v6 + (30) * 4u))) + (uint32)(r_u32((a1 + (22) * 4u))))) - (uint32)(r_u32((a1 + (19) * 4u)))));
  w_u32(((local_objects + 0u) + (1) * 4u), (sint32)((uint32)((sint32)((uint32)((sint32)r_u32((v6 + (31) * 4u))) + (uint32)(r_u32((a1 + (23) * 4u))))) - (uint32)(r_u32((a1 + (20) * 4u)))));
  w_u32(((local_objects + 0u) + (2) * 4u), (sint32)((uint32)((sint32)((uint32)((sint32)r_u32((v6 + (32) * 4u))) + (uint32)(r_u32((a1 + (24) * 4u))))) - (uint32)(r_u32((a1 + (21) * 4u)))));
  w_u32(((local_objects + 16u) + (0) * 4u), (sint32)((uint32)((sint32)((uint32)((sint32)r_u32((v6 + (30) * 4u))) + (uint32)(r_u32((a1 + (22) * 4u))))) + (uint32)(r_u32((a1 + (19) * 4u)))));
  w_u32(((local_objects + 16u) + (1) * 4u), (sint32)((uint32)((sint32)((uint32)((sint32)r_u32((v6 + (31) * 4u))) + (uint32)(r_u32((a1 + (23) * 4u))))) + (uint32)(r_u32((a1 + (20) * 4u)))));
  w_u32(((local_objects + 16u) + (2) * 4u), (sint32)((uint32)((sint32)((uint32)((sint32)r_u32((v6 + (32) * 4u))) + (uint32)(r_u32((a1 + (24) * 4u))))) + (uint32)(r_u32((a1 + (21) * 4u)))));
  { uint32 draft_return = sub_8004A048((local_objects + 0u), (local_objects + 16u), a2, a3); ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80045F4C(uint32 a1)
{
    FUNCTION_MARKER(0x80045f4cu, "SLES_008.65");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
  sint32 v2;
  uint32 v3;
  sint32 i;
  sint32 v5;
  sint32 v6;
  uint32 v7;
  sint32 v8;
  uint32 v9;
  uint32 j;
  sint32 result;
  w_u32(0x8007713cu, a1);
  w_u32(0x8007755cu, a1);
  v2 = ((sint32)((sint32)((uint32)(a1) * (uint32)((sint32)((uint32)(a1) - (uint32)(1))))) / (sint32)(2));
  sub_80026694((sint32)((0x80077144u)), (sint32)((uint32)(8) * (uint32)(v2)), 0);
  sub_80026694((sint32)((0x80077140u)), (sint32)((uint32)(4) * (uint32)(a1)), 0);
  sub_80026694((sint32)((0x80077148u)), (sint32)((uint32)(4) * (uint32)(a1)), 0);
  v3 = (uint32)((sint32)r_u32(0x80077144u));
  for (i = 0; ((sint32)(i) < (sint32)(v2)); v3 += (2) * 4u)
  {
    w_u32(v3, 128);
    w_u32((v3 + (1) * 4u), 0x7FFFFFFF);
    ++i;
  }

  v5 = 1;
  v6 = (sint32)r_u32(0x80077140u);
  v7 = (uint32)((sint32)r_u32(0x80077148u));
  v8 = (sint32)r_u32(0x80077144u);
  w_u32((uint32)((sint32)r_u32(0x80077140u)), 0);
  v9 = (uint32)((sint32)((uint32)(v6) + (uint32)(4)));
  w_u32(v7, 0);
  for (j = (v7 + (1) * 4u); ((sint32)(v5) < (sint32)(a1)); ((j += 4u)))
  {
    w_u32(((v9 += 4u) - 4u), 0);
    w_u32(j, v8);
    v8 = ((uint32)(v8) + (uint32)((sint32)((uint32)(8) * (uint32)(v5++))));
  }

  result = (sint32)(0u - (uint32)(1));
  w_u32(0x80077260u, (sint32)(0u - (uint32)(1)));
  return result;
}


uint32 sub_80019EE0(uint32 a1)
{
    FUNCTION_MARKER(0x80019ee0u, "SLES_008.65");
  sint32 v1;
  sint32 v2;
  sint8 v3;
  w_u32(0x80077538u, a1);
  w_u32(0x8007756cu, 0);
  w_u16(0x80076880u, 0);
  if (((sint32)((sint8)r_u8(0x8006c248u)) > (sint32)(0)))
    w_u32(0x8008969C, (sint32)((uint32)((sint32)((uint32)(100) * (uint32)((sint32)((uint32)((sint32)((uint32)(30) * (uint32)((sint8)r_u8(0x8006c248u)))) + (uint32)(30))))) + (uint32)(200)));
  if (((uint8)((sint8)r_u8(0x8006c230u)) >= 2u))
    w_u32(0x800C4D18, 3);
  w_u8(0x8008AE6A, 0);
  ob_draft_unresolved_call((sint32)r_u32(0x80093D00), 1u, (sint32)r_u32(0x800C4D18));
  v1 = 0;
  if ((sint8)r_u8(0x8006c230u))
  {
    v2 = 0;
    do
    {
      w_u32((uint32)((sint32)((uint32)(v2) - (uint32)(2146657940))), 0);
      w_u32((uint32)((sint32)((uint32)(v2) - (uint32)(2146657948))), 0x8001a0ccu);
      w_u32((uint32)((sint32)((uint32)(v2) - (uint32)(2146657952))), 0x8001a05cu);
      w_u32((uint32)((sint32)((uint32)(v2) - (uint32)(2146657924))), 0);
      w_u32((uint32)((sint32)((uint32)(v2) - (uint32)(2146657916))), (sint32)(0u - (uint32)(1)));
      w_u32((uint32)((sint32)((uint32)(v2) - (uint32)(2146657908))), 0);
      w_u32((uint32)((sint32)((uint32)(v2) - (uint32)(2146657944))), 0);
      w_u32((uint32)((sint32)((uint32)(v2) - (uint32)(2146657936))), 0);
      v3 = (sint8)r_u8((0x8006c23bu + (v1++) * 1u));
      w_u16((uint32)((sint32)((uint32)(v2) - (uint32)(2146657900))), v3);
      v2 = ((uint32)(v2) + (uint32)(56));
    }
    while ((v1 < (uint8)((sint8)r_u8(0x8006c230u))));
  }
  ob_draft_unresolved_call((sint32)r_u32(0x800A49A4), 1u, v1);
  return sub_8001A1CC();
}


uint32 sub_8004A2EC(uint32 a1)
{
    FUNCTION_MARKER(0x8004a2ecu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_800257A0 */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
  sint32 v1;
  sint32 v3;
  uint32 v4;
  uint32 v5;
  sint32 v6;
  sint32 result;
  v1 = (sint32)r_u32(0x80077490u);
  v3 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))));
  w_u32(0x80077490u, a1);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(32))), 0);
  w_u8((uint32)((sint32)((uint32)(a1) + (uint32)(36))), 0);
  w_u8((uint32)((sint32)((uint32)(a1) + (uint32)(37))), 0);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(48))), 0);
  w_u16((uint32)((sint32)((uint32)(a1) + (uint32)(38))), 0);
  w_u8((uint32)((sint32)((uint32)(a1) + (uint32)(52))), 0);
  w_u8((uint32)((sint32)((uint32)(a1) + (uint32)(53))), 0);
  w_u8((uint32)((sint32)((uint32)(a1) + (uint32)(55))), 0);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(28))), v1);
  v4 = r_u32((uint32)((sint32)((uint32)(v3) + (uint32)(40))));
  if (((r_u32(v4) & 3) != 0))
  {
    v5 = (uint32)(sub_800257CC((sint32)(v4)));
  }
  else
  {
    (w_u16((uint32)(((uint32)(r_u32(v4)) - (uint32)(6))), (r_u16((uint32)(((uint32)(r_u32(v4)) - (uint32)(6)))) + 1u)), r_u16((uint32)(((uint32)(r_u32(v4)) - (uint32)(6)))));
    v5 = r_u32(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))))) + (uint32)(40)))));
  }
  v6 = ((uint32)((uint16)(r_u16((v5 + (4) * 2u)))) * (uint32)(((sint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)((sint16)(r_u16((v5 + (33) * 2u)))) + (uint32)((sint16)(r_u16((v5 + (35) * 2u)))))) - (uint32)((sint16)(r_u16((v5 + (30) * 2u)))))) - (uint32)((sint16)(r_u16((v5 + (32) * 2u)))))) >> 3)));
  if (((r_u16((v5 + (1) * 2u)) & 0x40) != 0))
    sub_800262CC((uint32)((sint32)((uint32)(a1) + (uint32)(48))), 256);
  result = ob_draft_unresolved_call(0x800257a0u, 1u, r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))))) + (uint32)(40)))));
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(40))), ((sint32)(v6) / (sint32)(256)));
  return result;
}


uint32 sub_80023C08(void)
{
    FUNCTION_MARKER(0x80023c08u, "SLES_008.65");
    /* Temporarily skip intro movies by the user's native startup choice */
    if (ob_native_skip_intro_movies) return 0u;
    /* TODO: Bind external adapter for sub_80054440 */

  sub_80030700(0, 0, 0);
  sub_8003077C(0x8008C704u, 255, 2, 255, 255, 255);
  sub_800170F8(2);
  sub_8002439C();
  sub_8001F874();
  ob_draft_unresolved_call(0x8008DD9Cu, 1u, 0u);
  ob_draft_unresolved_call(0x8008D0D8u, 5u, 0x800108C8u, 230u, 1u, 1u, 1u);
  if (!ob_draft_unresolved_call(0x80054440u, 1u, 3))
  {
    ob_draft_unresolved_call(0x8008D0D8u, 5u, 0x800108DCu, 147u, 1u, 1u, 2u);
    if (!ob_draft_unresolved_call(0x80054440u, 1u, 3))
    {
      ob_draft_unresolved_call(0x8008D0D8u, 5u, 0x800108ECu, 326u, 1u, 1u, 1u);
      if (!ob_draft_unresolved_call(0x80054440u, 1u, 3))
        ob_draft_unresolved_call(0x8008D0D8u, 5u, 0x80010900u, 1790u, 1u, 1u, 1u);
    }
  }
  sub_80024D54(0x3FFFF);
  sub_80024320();
  sub_8001F874();
  sub_80017178();
  return sub_80026418();
}


uint32 sub_8003077C(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6)
{
    FUNCTION_MARKER(0x8003077cu, "SLES_008.65");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Bind external adapter for sub_8005F3F8 */
  sint32 v11;
  sint32 v12;
  uint32 v13;
  sint32 v14;
  uint32 v15;
  sint32 v16;
  v11 = a2;
  if (((sint32)((sint16)(a2)) >= (sint32)(256)))
    v11 = 255;
  if (((sint32)((sint32)r_u32(0x800770e4u)) < (sint32)(3)))
  {
    v12 = (sint16)(((sint32)(((sint32)((sint32)((uint32)(v11) << (uint32)(16))) >> 2)) / (sint32)(255)));
    v13 = (uint32)((sint32)((uint32)((sint32)((uint32)(6) * (uint32)((sint32)r_u32(0x800770e4u)))) - (uint32)(2146924520)));
    w_u16(v13, ((sint32)((sint16)(((uint32)((sint32)((uint32)((sint32)(0u - (uint32)((sint16)r_u16(a1)))) * (uint32)(v12))) >> 14))) >> 2));
    w_u16((v13 + (1) * 2u), ((sint32)((sint16)(((uint32)((sint32)((uint32)((sint32)(0u - (uint32)((sint16)r_u16((a1 + (1) * 2u))))) * (uint32)(v12))) >> 14))) >> 2));
    v14 = (sint32)((uint32)(2) * (uint32)((sint32)r_u32(0x800770e4u)));
    w_u16((v13 + (2) * 2u), ((sint32)((sint16)(((uint32)((sint32)((uint32)((sint32)(0u - (uint32)((sint16)r_u16((a1 + (2) * 2u))))) * (uint32)(v12))) >> 14))) >> 2));
    v15 = (uint32)((sint32)((uint32)(v14) - (uint32)(2146925976)));
    w_u16(v15, (sint32)((uint32)(16) * (uint32)(a4)));
    w_u16((v15 + (3) * 2u), (sint32)((uint32)(16) * (uint32)(a5)));
    v16 = (sint32)r_u32(0x800770e4u);
    w_u16((v15 + (6) * 2u), (sint32)((uint32)(16) * (uint32)(a6)));
    w_u32(0x800770e4u, (sint32)((uint32)(v16) + (uint32)(1)));
  }
  return ob_draft_unresolved_call(0x8005f3f8u, 1u, (sint32)(0u - (uint32)(2146925976)));
}


uint32 sub_80016A50(uint32 a1)
{
    FUNCTION_MARKER(0x80016a50u, "SLES_008.65");
  uint32 v2;
  sint32 v3;
  uint32 v4;
  uint32 v5;
  sint8 v6;
  uint32 v7;
  uint16 v8;
  sint32 v9;
  sint32 v10;
  sint32 v11;
  sint32 v12;
  uint32 v13;
  sint16 v14;
  sint32 v15;
  uint32 v16;
  while (((sint32)((sint32)r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(16))))) > (sint32)(0)))
  {
    v2 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(20))));
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(20))), (v2 + (1) * 1u));
    v3 = r_u8(v2);
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(20))), (v2 + (2) * 1u));
    v4 = (v3 | ((uint32)(r_u8((v2 + (1) * 1u))) << (uint32)(8)));
    v5 = (v4 >> 4);
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12))), ((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12))))) - (uint32)(2)));
    if ((uint16)((v4 >> 4)))
    {
      v6 = (v4 & 0xF);
      do
      {
        v7 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(20))));
        w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(20))), (v7 + (1) * 1u));
        v8 = r_u8(v7);
        v9 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(4))));
        v10 = v8;
        (w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12))), (r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12)))) - 1u)), r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12)))));
        v11 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(4))));
        v12 = ((sint32)(v10) >> r_u16((uint32)((sint32)((uint32)(v9) + (uint32)(6)))));
        w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(16))), ((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(16))))) - (uint32)((uint16)(v12))));
        if (((((sint32)((sint32)(r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(8)))))) >> v6) & 1) != 0))
          v13 = (uint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)((uint8)((v10 & (sint32)((uint32)((sint32)((uint32)(1) << (uint32)(r_u16((uint32)((sint32)((uint32)(v11) + (uint32)(6))))))) - (uint32)(1))))))) + (uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24)))))));
        else
          v13 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))));
        v14 = (sint16)r_u16(v13);
        v15 = 0;
        if ((uint16)(v12))
        {
          do
          {
            v16 = r_u32((uint32)(a1));
            ++v15;
            w_u32((uint32)(a1), ((uint32)(r_u32((uint32)(a1))) + (uint32)(2)));
            w_u16(v16, v14);
          }
          while ((v15 != (uint16)(v12)));
        }
        --v5;
      }
      while ((uint16)(v5));
    }
  }

  return r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12))));
}


uint32 sub_800493F8(uint32 a1)
{
    FUNCTION_MARKER(0x800493f8u, "SLES_008.65");
  sint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  uint32 v8;
  uint32 v9;
  sub_80048994((uint32)(a1));
  w_u32(0x80078ED8, 0);
  w_u16(0x80078EDA, 0);
  w_u16(0x80078EDC, 0);
  v2 = (r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(72)))) >= 0);
  if (((sint32)((sint32)r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(76))))) >= (sint32)(0)))
    ++v2;
  v3 = v2;
  if (((sint32)((sint32)r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(80))))) >= (sint32)(0)))
    v3 = (sint32)((uint32)(v2) + (uint32)(1));
  v4 = (uint16)((sint16)r_u16((0x80077134u + (v3) * 2u)));
  if (((sint32)((sint32)r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(72))))) >= (sint32)(0)))
  {
    v5 = ((uint32)(v5) & ~((uint32)65535u << 0) | (((uint32)((sint16)r_u16((0x80077134u + (v3) * 2u))) & 65535u) << 0));
    if ((r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(48)))) != r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(36))))))
      v5 = (sint32)(0u - (uint32)(v4));
    w_u32(0x80078ED8, v5);
  }
  if (((sint32)((sint32)r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(76))))) >= (sint32)(0)))
  {
    v6 = ((uint32)(v6) & ~((uint32)65535u << 0) | (((uint32)(v4) & 65535u) << 0));
    if ((r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(52)))) != r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(40))))))
      v6 = (sint32)(0u - (uint32)(v4));
    w_u16(0x80078EDA, v6);
  }
  if (((sint32)((sint32)r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(80))))) >= (sint32)(0)))
  {
    v7 = ((uint32)(v7) & ~((uint32)65535u << 0) | (((uint32)(v4) & 65535u) << 0));
    if ((r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(56)))) != r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(44))))))
      v7 = (sint32)(0u - (uint32)(v4));
    w_u16(0x80078EDC, v7);
  }
  w_u32(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(20)))), ((r_u32(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(20))))) & 0xFFFFFFCF) | 0x10));
  v8 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))));
  v9 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(4))));
  w_u32((v9 + (64) * 4u), (r_u32((v8 + (34) * 4u)) & r_u32((v9 + (42) * 4u))));
  w_u32((v8 + (64) * 4u), (r_u32((v9 + (34) * 4u)) & r_u32((v8 + (42) * 4u))));
  return 16;
}


uint32 sub_80024400(void)
{
    FUNCTION_MARKER(0x80024400u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80024B70 */
    /* TODO: Bind external adapter for sub_80024B98 */
    /* TODO: Bind external adapter for sub_80024C3C */
    /* TODO: Bind external adapter for sub_80024CA4 */
    /* TODO: Bind external adapter for sub_80023D40 */
    /* TODO: Bind external adapter for sub_80023DB8 */
  sint32 v0;
  sint32 result;
  w_u32(0x8006c228u, 0);
  sub_80023E30();
  do
  {
    sub_80024640();
    do
    {
      sub_80024938();
      do
      {
        sub_80024B40();
        do
          v0 = sub_80023E70();
        while (!v0);
        ob_draft_unresolved_call(0x80024b70u, 0u);
      }
      while ((v0 == 10));
      ob_draft_unresolved_call(0x80024b98u, 0u);
    }
    while (((((((v0 != 2) && ((uint32)((sint32)((uint32)(v0) - (uint32)(5))) >= 2)) && ((uint32)((sint32)((uint32)(v0) - (uint32)(8))) >= 2)) && (v0 != 7)) && (v0 != 3)) && (v0 != 11)));
    ob_draft_unresolved_call(0x80024c3cu, 0u);
  }
  while ((((((v0 != 2) && ((uint32)((sint32)((uint32)(v0) - (uint32)(7))) >= 2)) && (v0 != 9)) && (v0 != 5)) && (v0 != 11)));
  ob_draft_unresolved_call(0x80024ca4u, 0u);
  if ((v0 == 8))
  {
    sub_800224A0();
    ob_draft_unresolved_call(0x80023d40u, 0u);
    return 8;
  }
  else
  {
    result = v0;
    if ((v0 == 9))
    {
      sub_800224A0();
      ob_draft_unresolved_call(0x80023db8u, 0u);
      return 9;
    }
  }
  return result;
}


uint32 sub_800342F0(uint32 a1)
{
    FUNCTION_MARKER(0x800342f0u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8005C504 */
    /* TODO: Bind external adapter for sub_8005C7C8 */
    uint32 local_objects = ob_draft_scratch_acquire(1u);
  uint32 v2;
  uint32 v3;
  sint32 result;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  uint32 v9;
  sint32 v10;
  uint32 v11;
  uint32 v12;
  sint32 v13;
  sint16 v14;
  uint32 v15;
  sint32 v16;
  uint32 i;
  sint32 j;
  sint16 v19;
  ;
  v2 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(44))));
  v3 = (sint32)r_u32(0x800882BC);
  result = ((sint32)r_u32(0x800882BC) < v2);
  v5 = 0;
  if (((sint32)r_u32(0x800882BC) >= v2))
  {
    v6 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(10))));
    do
    {
      w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(44))), ((uint32)(v2) + (uint32)(v6)));
      v2 = ((uint32)(v2) + (uint32)(v6));
      ++v5;
    }
    while ((v3 >= v2));
    v7 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(8))));
    result = ((sint32)(v5) < (sint32)(v7));
    if (((sint32)(v5) >= (sint32)(v7)))
    {
      v8 = (sint32)((uint32)(v5) - (uint32)(v7));
      do
      {
        result = ((sint32)(v8) < (sint32)(v7));
        v9 = ((sint32)(v8) >= (sint32)(v7));
        v8 = ((uint32)(v8) - (uint32)(v7));
      }
      while (v9);
      v5 = (sint32)((uint32)(v8) + (uint32)(v7));
    }
    v10 = (sint32)((uint32)(v7) - (uint32)(v5));
    if (v5)
    {
      v11 = (uint32)((sint32)((uint32)((sint32)((uint32)(a1) + (uint32)((sint32)((uint32)(2) * (uint32)(v10))))) + (uint32)(12)));
      v12 = (local_objects + 0u);
      v13 = (sint32)((uint32)(v5) - (uint32)(1));
      do
      {
        v14 = (sint16)r_u16(((v11 += 2u) - 2u));
        --v13;
        w_u16((uint32)(v12), v14);
        v12 += (2) * 1u;
      }
      while ((v13 != (sint32)(0u - (uint32)(1))));
      v15 = (v11 - (1) * 2u);
      v16 = (sint32)((uint32)(v10) - (uint32)(1));
      for (i = (v12 - (2) * 1u); (v16 != (sint32)(0u - (uint32)(1))); ((v15 -= 2u)))
      {
        --v16;
        w_u16(v15, (sint16)r_u16((v15 + ((sint32)(0u - (uint32)(v5))) * 2u)));
      }

      for (j = (sint32)((uint32)(v5) - (uint32)(1)); (j != (sint32)(0u - (uint32)(1))); ((v15 -= 2u)))
      {
        v19 = r_u16((uint32)(i));
        i -= (2) * 1u;
        --j;
        w_u16(v15, v19);
      }

      ob_draft_unresolved_call(0x8005c504u, 1u, 0);
      ob_draft_unresolved_call(0x8005c7c8u, 2u, a1, (sint32)((uint32)(a1) + (uint32)(12)));
      { uint32 draft_return = ob_draft_unresolved_call(0x8005c504u, 1u, 0); ob_draft_scratch_release(local_objects);  return draft_return; }
    }
  }
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


