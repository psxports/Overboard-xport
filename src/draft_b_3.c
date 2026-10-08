#include "draft_signatures.h"
#include "psx.h"

/* Unverified draft bodies */

uint32 sub_8004F610(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8004f610u, "SLES_008.65");

  sint32 v4;
  sint32 v5;
  sint32 result;
  uint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  if ((r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(160)))) == a2))
  {
    v4 = 8;
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(208))), ((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(208))))) & (uint32)(~2u)));
    return v4;
  }
  v5 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(188))));
  if ((v5 == 1))
    return 16;
  if (((sint32)(v5) >= (sint32)(2)))
  {
    if ((v5 == 2))
      return 32;
    result = ob_native_missing_value(0x8004f610u, "v2");
    if ((v5 == 3))
      return 64;
  }
  else
  {
    result = ob_native_missing_value(0x8004f610u, "v2");
    if (!v5)
    {
      v4 = 1;
      if (((r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(208)))) & 1) == 0))
        return v4;
      result = 1;
      if (((sint32)((sint16)r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(166))))) > (sint32)(0)))
      {
        v7 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))));
        sub_800455DC(v7, r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(156)))));
        result = 1;
        if (((sint32)((uint32)((sint32)((uint32)((sint32)r_u32((v7 + (31) * 4u))) + (uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(84))))))) - (uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(180)))))) == r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(72))))))
        {
          v4 = 7;
          w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(192))), 2);
          v8 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(176))));
          v9 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(180))));
          v10 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(184))));
          w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(208))), ((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(208))))) | (uint32)(2u)));
          w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(196))), v8);
          w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(200))), v9);
          w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(204))), v10);
          return v4;
        }
      }
    }
  }
  return result;
}


void sub_80022AD4(uint32 text, uint32 x, uint32 y, uint32 red, uint32 green, uint32 blue, uint32 flags)
{
    FUNCTION_MARKER(0x80022AD4u, "SLES_008.65");
    uint32 storage = ob_draft_scratch_acquire(124u);
    uint32 arguments = storage + 80u;
    uint32 index = 0u;
    uint32 cursor = text;
    /* The surrounding original helpers are empty */
    while (index < ob_draft_unresolved_call(0x80063FB8u, 1u, text))
    {
        uint32 character = r_u8(cursor);
        if (character == 32u)
            x += 5u;
        else
        {
            if (character - 97u < 26u)
                w_u8(cursor, character - 32u);
            character = r_u8(cursor);
            sint32 glyph = (sint32)(character - 65u);
            sint32 row = glyph;
            if (glyph < 0) row = (sint32)(character - 58u);
            uint32 v = (uint32)(row >> 3) << 3;
            uint32 u = ((uint32)glyph - v) << 3;
            w_u32(arguments + 16u, 5u);
            w_u32(arguments + 20u, x);
            w_u32(arguments + 24u, y);
            w_u32(arguments + 28u, flags);
            w_u32(arguments + 32u, red);
            w_u32(arguments + 36u, green);
            w_u32(arguments + 40u, blue);
            ob_append_colored_texture_quad(0x80067894u, u, v, 7u, arguments);
            x += 1u + (uint32)(sint32)r_s8(0x8006C0DCu + (uint32)glyph);
        }
        ++cursor;
        ++index;
    }
    ob_draft_scratch_release(storage);
}


uint32 sub_80042644(uint32 a1)
{
    FUNCTION_MARKER(0x80042644u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8002DC10 */
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
  uint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  uint32 v11;
  v2 = (uint32)((sint32)((uint32)(a1) + (uint32)(72)));
  ob_draft_unresolved_call(0x8002dc10u, 1u, (uint32)((sint32)((uint32)(a1) + (uint32)(72))));
  v3 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800770c0u)) + (uint32)(8))));
  v4 = 250;
  if (((uint16)(v3) < 0xFBu))
    v4 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800770c0u)) + (uint32)(8))));
  v5 = (sint32)((uint32)((sint16)(v4)) << (uint32)(14));
  if (!((uint16)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800770c0u)) + (uint32)(8)))))))
    xport_mips_break(7u);
  v6 = (v5 / (uint16)(v3));
  w_u16((uint32)((sint32)((uint32)(a1) + (uint32)(74))), 0);
  w_u16((uint32)((sint32)((uint32)(a1) + (uint32)(76))), 0);
  w_u16((uint32)((sint32)((uint32)(a1) + (uint32)(78))), 0);
  w_u16((uint32)((sint32)((uint32)(a1) + (uint32)(82))), 0);
  w_u16((uint32)((sint32)((uint32)(a1) + (uint32)(84))), 0);
  w_u16((uint32)((sint32)((uint32)(a1) + (uint32)(86))), 0);
  w_u16((uint32)((sint32)((uint32)(a1) + (uint32)(72))), ((sint32)(v5) / (sint32)(250)));
  w_u16((uint32)((sint32)((uint32)(a1) + (uint32)(80))), ((sint32)(v5) / (sint32)(250)));
  w_u16((uint32)((sint32)((uint32)(a1) + (uint32)(88))), v6);
  if (((sint16)(v4) == (uint16)(v3)))
  {
    v7 = (sint16)r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(72))));
    v8 = ((sint32)((sint32)((uint32)(v3) << (uint32)(16))) >> 2);
    if (!(r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(72))))))
      xport_mips_break(7u);
    if (((v7 == (sint32)(0u - (uint32)(1))) && (v8 == 0x80000000)))
      xport_mips_break(6u);
    v9 = ((sint32)(v8) / (sint32)(v7));
  }
  else
  {
    v10 = (sint32)((uint32)((sint16)(v3)) * (uint32)((sint16)(v6)));
    v11 = (sint32)((uint32)(v10) + (uint32)(0x2000));
    if ((((v3 ^ v6) & 0x8000) != 0))
      v11 = (sint32)((uint32)(v10) - (uint32)(0x2000));
    v9 = (v11 >> 14);
  }
  w_u16(0x80077498u, v9);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(120))), ((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(120))))) | (uint32)(0x12u)));
  return sub_800328EC(v2);
}


uint32 sub_8002FED4(uint32 a1, uint32 a2, uint32 a3)
{
  FUNCTION_MARKER(0x8002fed4u, "SLES_008.65");
  int64_t product;
  int64_t sum;
  sum = ((int64_t)(sint32)r_u32(a1 + 8u) * (sint16)r_u16(a2 + 12u)) >> 14;
  sum += ((int64_t)(sint32)r_u32(a1 + 4u) * (sint16)r_u16(a2 + 6u)) >> 14;
  sum += ((int64_t)(sint32)r_u32(a1) * (sint16)r_u16(a2 + 0u)) >> 14;
  w_u32(a3 + 0u, (uint32)sum);
  sum = ((int64_t)(sint32)r_u32(a1 + 8u) * (sint16)r_u16(a2 + 14u)) >> 14;
  sum += ((int64_t)(sint32)r_u32(a1 + 4u) * (sint16)r_u16(a2 + 8u)) >> 14;
  sum += ((int64_t)(sint32)r_u32(a1) * (sint16)r_u16(a2 + 2u)) >> 14;
  w_u32(a3 + 4u, (uint32)sum);
  product = (int64_t)(sint32)r_u32(a1 + 8u) * (sint16)r_u16(a2 + 16u);
  sum = product >> 14;
  sum += ((int64_t)(sint32)r_u32(a1 + 4u) * (sint16)r_u16(a2 + 10u)) >> 14;
  sum += ((int64_t)(sint32)r_u32(a1) * (sint16)r_u16(a2 + 4u)) >> 14;
  w_u32(a3 + 8u, (uint32)sum);
  return (uint32)((uint64_t)product >> 32) << 18;
}


uint32 sub_80050A2C(uint32 a1)
{
    FUNCTION_MARKER(0x80050a2cu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8005160C */
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
  sint32 result;
  sint32 v12;
  ;
  uint32 v14;
  ;
  ;
  ;
  ;
  if (r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(224)))))
    v2 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(272))));
  else
    v2 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(264))));
  v3 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(392))));
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(200))), ((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(352))))) + (uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(356)))))));
  v4 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(136))));
  v5 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(140))));
  v6 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(144))));
  w_u32(local_objects + 0u, r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(132)))));
  v14 = v4;
  w_u32(local_objects + 8u, v5);
  w_u32(local_objects + 12u, v6);
  v7 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(152))));
  w_u32(local_objects + 16u, r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(148)))));
  w_u32(local_objects + 20u, v7);
  ob_draft_unresolved_call(0x8005160cu, 3u, (local_objects + 0u), 1, r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(348)))));
  v8 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(232))));
  v9 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(264))));
  while (1)
  {
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(192))), v8);
    v10 = (sint16)r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(46))));
    result = (v10 & (sint8)(((sint32)r_u32(local_objects + 16u)) >> 8));
    if (!result)
    {
      if ((((uint8)(v10) & r_u8((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 12u)) + (uint32)(22))))) != 0))
      {
        result = 1;
        if ((((uint16)(v10) & r_u16(v14)) == 0))
          result = 2;
        w_u8((uint32)((sint32)((uint32)(a1) + (uint32)(148))), result);
      }
      else
      {
        v12 = v9;
        if (((sint32)(v3) < (sint32)(v9)))
          v12 = v3;
        w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(120))), v12);
        result = sub_80050B88((sint32)r_u32(local_objects + 8u), a1);
      }
    }
    if ((v9 == v2))
      break;
    ob_draft_unresolved_call(0x8005160cu, 3u, (local_objects + 0u), 0, r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(228)))));
    v9 = v2;
    v8 = ((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(192))))) + (uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(236))))));
  }

  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_8002D078(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5)
{
    FUNCTION_MARKER(0x8002d078u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8005EEE0 */
    /* TODO: Bind external adapter for sub_80035178 */
    /* TODO: Bind external adapter for sub_80033F48 */
    /* TODO: Bind external adapter for sub_80030924 */
    /* TODO: Bind external adapter for sub_80064018 */
  sint32 v13;
  sint32 v14;
  sint32 v15;
  ob_draft_unresolved_call(0x8005eee0u, 0u);
  w_u32(0x8007FAA0, a1);
  w_u32(0x8007FAA4, 0);
  w_u32(0x8007FAA8, a2);
  w_u32(0x8007FAAC, r_u32(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8007741cu)) + (uint32)(4))))));
  v13 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8007741cu)) + (uint32)(4))));
  w_u32(0x800773b4u, a4);
  w_u32(0x800770c0u, (sint32)(0u - (uint32)(2146960736)));
  w_u32(0x800773b8u, a5);
  v14 = r_u32((uint32)((sint32)((uint32)(v13) + (uint32)(4))));
  w_u32(0x8007FAB4, 320);
  w_u32(0x8007FAB8, 200);
  w_u32(0x8007FABC, 256);
  w_u32(0x8007FAB0, v14);
  v15 = r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8007741cu)) + (uint32)(4))))) + (uint32)(8))));
  w_u32(0x8007FAC4, 1);
  w_u32(0x8007FAC8, 1);
  w_u32(0x8007FACC, a3);
  w_u32(0x8007FAC0, v15);
  if (sub_8002D8A8(a1))
  {
    ob_draft_unresolved_call(0x80035178u, 0u);
    sub_80033F90();
    ob_draft_unresolved_call(0x80033f48u, 0u);
    w_u16(0x8007FE08, 4096);
    w_u16(0x8007FE10, 4096);
    w_u16(0x8007FE18, 4096);
    w_u32(0x8007FE1C, 0);
    w_u32(0x8007FE20, 0);
    w_u32(0x8007FE24, 0);
    w_u16(0x8007FE0E, 0);
    w_u16(0x8007FE14, 0);
    w_u16(0x8007FE0A, 0);
    w_u16(0x8007FE16, 0);
    w_u16(0x8007FE0C, 0);
    w_u16(0x8007FE12, 0);
    w_u32(0x80077394u, (sint32)(0u - (uint32)(2146941600)));
    w_u32(0x800774ccu, 0);
    w_u32(0x800775f8u, (sint32)r_u32(0x800773b4u));
    w_u32(0x80077600u, (sint32)r_u32(0x800773b8u));
    ob_draft_unresolved_call(0x80030924u, 0u);
    return (sint32)(0u - (uint32)(1));
  }
  else
  {
    ob_draft_unresolved_call(0x80064018u, 1u, r_u32(0x80010954u));
    return 0;
  }
}


uint32 sub_8004E814(void)
{
    FUNCTION_MARKER(0x8004e814u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80025874 */
    /* TODO: Bind external adapter for sub_8005BAFC */
    /* TODO: Bind external adapter for sub_8005BA48 */
    uint32 local_objects = ob_draft_scratch_acquire(32u);
  uint16 v0;
  sint32 v1;
  uint32 v2;
  uint32 v3;
  uint32 v4;
  sint32 v5;
  uint32 v6;
  uint32 v7;
  sint32 v8;
  sint32 v9;
  sint8 v10;
  sint32 result;
  ;
  v0 = 0;
  w_u32(((local_objects + 0u) + (4) * 4u), (sint32)r_u32(0x800669f0u));
  w_u32(((local_objects + 0u) + (5) * 4u), (sint32)r_u32(0x800669f4u));
  w_u32(((local_objects + 0u) + (6) * 4u), (sint32)r_u32(0x800669f8u));
  w_u32(((local_objects + 0u) + (7) * 4u), (sint32)r_u32(0x800669fcu));
  w_u32(((local_objects + 0u) + (0) * 4u), (sint32)r_u32(0x800669f0u));
  w_u32(((local_objects + 0u) + (1) * 4u), (sint32)r_u32(0x800669f4u));
  w_u32(((local_objects + 0u) + (2) * 4u), (sint32)r_u32(0x800669f8u));
  w_u32(((local_objects + 0u) + (3) * 4u), (sint32)r_u32(0x800669fcu));
  v1 = 0;
  do
  {
    v2 = (((local_objects + 0u) + (v1) * 4u));
    ++v0;
    v3 = (uint32)(ob_draft_unresolved_call(0x80025874u, 1u, ((uint32)((sint32)r_u32(v2)) >> 17)));
    v4 = (uint32)(ob_draft_unresolved_call(0x80025874u, 1u, (((uint32)((sint32)r_u32(v2)) >> 2) & 0x7FFF)));
    v5 = (sint32)((uint32)(40) * (uint32)(v1));
    v6 = r_u32(v3);
    v7 = r_u32(v4);
    ob_draft_unresolved_call(0x8005bafcu, 1u, (sint32)((uint32)(v5) - (uint32)(2146940512)));
    ob_draft_unresolved_call(0x8005ba48u, 2u, (sint32)((uint32)(v5) - (uint32)(2146940512)), 1);
    w_u8((uint32)((sint32)((uint32)(v5) - (uint32)(2146940508))), 64);
    w_u8((uint32)((sint32)((uint32)(v5) - (uint32)(2146940507))), 64);
    w_u8((uint32)((sint32)((uint32)(v5) - (uint32)(2146940506))), 64);
    v8 = ((v7 >> 4) & 0xF0);
    v9 = ((v7 >> 8) & 0xF0);
    v10 = (sint32)((uint32)(v9) + (uint32)(63));
    w_u8((uint32)((sint32)((uint32)(v5) - (uint32)(2146940499))), v9);
    w_u8((uint32)((sint32)((uint32)(v5) - (uint32)(2146940491))), v9);
    result = (v0 < 4u);
    w_u8((uint32)((sint32)((uint32)(v5) - (uint32)(2146940500))), v8);
    w_u8((uint32)((sint32)((uint32)(v5) - (uint32)(2146940492))), (sint32)((uint32)(v8) + (uint32)(63)));
    w_u8((uint32)((sint32)((uint32)(v5) - (uint32)(2146940484))), v8);
    w_u8((uint32)((sint32)((uint32)(v5) - (uint32)(2146940483))), v10);
    w_u8((uint32)((sint32)((uint32)(v5) - (uint32)(2146940476))), (sint32)((uint32)(v8) + (uint32)(63)));
    w_u8((uint32)((sint32)((uint32)(v5) - (uint32)(2146940475))), v10);
    w_u16((uint32)((sint32)((uint32)(v5) - (uint32)(2146940498))), (v6 >> 2));
    w_u16((uint32)((sint32)((uint32)(v5) - (uint32)(2146940490))), (uint16)((v7) >> 16));
    v1 = v0;
  }
  while ((v0 < 4u));
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_800455DC(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x800455dcu, "SLES_008.65");
    uint32 local_objects = ob_draft_scratch_acquire(12u);
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
  sint32 result;
  ;
  ;
  ;
  if (((((sint32)r_u32((a1 + (40) * 4u)) & 2) != 0) && (a2 == (sint32)r_u32((a1 + (26) * 4u)))))
  {
    result = (sint32)r_u32((a1 + (19) * 4u));
    if ((a2 != result))
      { uint32 draft_return = ob_advance_object(a1,a2,(uint32)result); ob_draft_scratch_release(local_objects);  return draft_return; }
  }
  else
  {
    /* The original prefix leaves either the zero dirty-bit comparison or the cached time in v0 */
    uint32 incoming_result=(r_u32(a1+160u)&2u)?r_u32(a1+104u):0u;
    ob_advance_object(a1,a2,incoming_result);
    v4 = (sint32)r_u32((a1 + (6) * 4u));
    if (v4)
    {
      sub_800454BC((sint32)r_u32((a1 + (6) * 4u)));
      sub_800455DC(v4, a2);
      if (((r_u32((uint32)((sint32)((uint32)(v4) + (uint32)(160)))) & 4) != 0))
      {
        v5 = (sint32)r_u32((a1 + (24) * 4u));
        v6 = (sint32)r_u32((a1 + (25) * 4u));
        w_u32(local_objects + 0u, (sint32)r_u32((a1 + (23) * 4u)));
        w_u32(local_objects + 4u, v5);
        w_u32(local_objects + 8u, v6);
      }
      else
      {
        sub_80029B70((a1 + (23) * 4u), (uint32)((sint32)((uint32)(v4) + (uint32)(54))), (local_objects + 0u));
      }
      v7 = ((uint32)(r_u32((uint32)((sint32)((uint32)(v4) + (uint32)(120))))) + (uint32)((sint32)r_u32(local_objects + 0u)));
      w_u32((a1 + (30) * 4u), v7);
      w_u32((a1 + (27) * 4u), ((sint32)(v7) >> 8));
      v8 = ((uint32)(r_u32((uint32)((sint32)((uint32)(v4) + (uint32)(124))))) + (uint32)((sint32)r_u32(local_objects + 4u)));
      w_u32((a1 + (31) * 4u), v8);
      w_u32((a1 + (28) * 4u), ((sint32)(v8) >> 8));
      v9 = ((uint32)(r_u32((uint32)((sint32)((uint32)(v4) + (uint32)(128))))) + (uint32)((sint32)r_u32(local_objects + 8u)));
      w_u32((a1 + (32) * 4u), v9);
      w_u32((a1 + (29) * 4u), ((sint32)(v9) >> 8));
    }
    else
    {
      v10 = (sint32)r_u32((a1 + (21) * 4u));
      v11 = (sint32)r_u32((a1 + (22) * 4u));
      v12 = (sint32)r_u32((a1 + (23) * 4u));
      v13 = (sint32)r_u32((a1 + (24) * 4u));
      v14 = (sint32)r_u32((a1 + (25) * 4u));
      w_u32((a1 + (27) * 4u), (sint32)r_u32((a1 + (20) * 4u)));
      w_u32((a1 + (28) * 4u), v10);
      w_u32((a1 + (29) * 4u), v11);
      w_u32((a1 + (30) * 4u), v12);
      w_u32((a1 + (31) * 4u), v13);
      w_u32((a1 + (32) * 4u), v14);
    }
    v15 = (sint32)r_u32((a1 + (40) * 4u));
    w_u32((a1 + (26) * 4u), a2);
    result = (v15 | 2);
    w_u32((a1 + (40) * 4u), result);
  }
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80021460(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8)
{
    FUNCTION_MARKER(0x80021460u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80025874 */
    /* TODO: Bind external adapter for sub_8005BB60 */
    /* TODO: Bind external adapter for sub_8005BA48 */
  uint32 v15;
  uint32 v16;
  uint32 v17;
  sint32 v18;
  sint32 v19;
  sint32 v20;
  uint32 v21;
  uint32 result;
  sint32 v23;
  sint8 v24;
  sint32 v25;
  sint32 v26;
  sint8 v27;
  uint32 v28;
  v15 = (uint32)(ob_draft_unresolved_call(0x80025874u, 1u, (r_u32(a1) >> 17)));
  v16 = (uint32)(ob_draft_unresolved_call(0x80025874u, 1u, ((r_u32(a1) >> 2) & 0x7FFF)));
  v17 = r_u32(v15);
  v18 = ((r_u32(v16) >> 4) & 0xF0);
  v19 = (r_u32(v16) >> 8);
  sub_800217B4((uint16)((r_u32(v16)) >> 16));
  v20 = (sint32)r_u32(0x800774a8u);
  v21 = (uint32)((sint32)r_u32(0x80077634u));
  result = ((sint32)((sint32)((uint32)((sint32)r_u32(0x800775bcu)) - (uint32)((sint32)r_u32(0x800774a8u)))) < (sint32)(20));
  v23 = r_u32((uint32)((sint32)r_u32(0x80077634u)));
  v24 = (v19 & 0xF0);
  if (((sint32)((sint32)((uint32)((sint32)r_u32(0x800775bcu)) - (uint32)((sint32)r_u32(0x800774a8u)))) >= (sint32)(20)))
  {
    v25 = (sint32)r_u32(0x800774a8u);
    v26 = r_u32((uint32)((sint32)r_u32(0x80077634u)));
    w_u32(0x800774a8u, ((uint32)((sint32)r_u32(0x800774a8u)) + (uint32)(20)));
    w_u32(0x80077634u, v20);
    w_u32(v21, ((v26 & 0xFF000000) | (v20 & 0xFFFFFF)));
    ob_draft_unresolved_call(0x8005bb60u, 1u, v25);
    v27 = (sint32)((uint32)(v18) + (uint32)(a2));
    if ((a8 == 1))
    {
      ob_draft_unresolved_call(0x8005ba48u, 2u, v20, 1);
      v27 = (sint32)((uint32)(v18) + (uint32)(a2));
    }
    w_u8((uint32)((sint32)((uint32)(v20) + (uint32)(12))), v27);
    w_u8((uint32)((sint32)((uint32)(v20) + (uint32)(13))), (sint32)((uint32)(v24) + (uint32)(a3)));
    w_u16((uint32)((sint32)((uint32)(v20) + (uint32)(8))), a6);
    w_u16((uint32)((sint32)((uint32)(v20) + (uint32)(10))), a7);
    w_u16((uint32)((sint32)((uint32)(v20) + (uint32)(16))), a4);
    w_u8((uint32)((sint32)((uint32)(v20) + (uint32)(4))), 0x80);
    w_u8((uint32)((sint32)((uint32)(v20) + (uint32)(5))), 0x80);
    w_u8((uint32)((sint32)((uint32)(v20) + (uint32)(6))), 0x80);
    v28 = (uint32)((sint32)r_u32(0x80077634u));
    w_u16((uint32)((sint32)((uint32)(v20) + (uint32)(14))), (v17 >> 2));
    w_u16((uint32)((sint32)((uint32)(v20) + (uint32)(18))), a5);
    result = ((r_u32(v28) & 0xFF000000) | (v23 & 0xFFFFFF));
    w_u32(v28, result);
  }
  return result;
}


uint32 sub_8004F0D8(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    FUNCTION_MARKER(0x8004f0d8u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80043824 */
    /* TODO: Bind external adapter for sub_80043BAC */
    /* TODO: Bind external adapter for sub_800451E4 */
  sint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  sub_80043600(a1, a2, r_u32((uint32)(a3)));
  v7 = r_u32((a1 + (3) * 4u));
  w_u32(a1, (0x800771b8u));
  w_u32((a1 + (6) * 4u), ob_draft_unresolved_call(0x80043824u, 3u, v7, (sint32)((0x8007711cu)), r_u32((uint32)((sint32)((uint32)(a3) + (uint32)(4))))));
  w_u32((a1 + (52) * 4u), 8);
  if (r_u16((uint32)((sint32)((uint32)(a3) + (uint32)(36)))))
    w_u32((a1 + (52) * 4u), 9);
  if (r_u16((uint32)((sint32)((uint32)(a3) + (uint32)(38)))))
    w_u32((a1 + (52) * 4u), ((uint32)(r_u32((a1 + (52) * 4u))) | (uint32)(4u)));
  w_u32((a1 + (17) * 4u), ((uint32)(r_u32((uint32)((sint32)((uint32)(a3) + (uint32)(8))))) << (uint32)(8)));
  w_u32((a1 + (18) * 4u), ((uint32)(r_u32((uint32)((sint32)((uint32)(a3) + (uint32)(12))))) << (uint32)(8)));
  w_u32((a1 + (19) * 4u), ((uint32)(r_u32((uint32)((sint32)((uint32)(a3) + (uint32)(16))))) << (uint32)(8)));
  w_u32((a1 + (20) * 4u), ((uint32)(r_u32((uint32)((sint32)((uint32)(a3) + (uint32)(20))))) << (uint32)(8)));
  w_u32((a1 + (21) * 4u), ((uint32)(r_u32((uint32)((sint32)((uint32)(a3) + (uint32)(24))))) << (uint32)(8)));
  w_u32((a1 + (22) * 4u), ((uint32)(r_u32((uint32)((sint32)((uint32)(a3) + (uint32)(28))))) << (uint32)(8)));
  v8 = r_u32((uint32)((sint32)((uint32)(a3) + (uint32)(32))));
  if (((sint32)(v8) < (sint32)(10)))
    v8 = 10;
  w_u32((a1 + (23) * 4u), v8);
  w_u32((a1 + (24) * 4u), 2147483393);
  w_u32((a1 + (35) * 4u), r_u32((uint32)((sint32)((uint32)(a3) + (uint32)(40)))));
  w_u32((a1 + (36) * 4u), r_u32((uint32)((sint32)((uint32)(a3) + (uint32)(44)))));
  w_u32((a1 + (37) * 4u), r_u32((uint32)((sint32)((uint32)(a3) + (uint32)(48)))));
  ob_draft_unresolved_call(0x80043bacu, 2u, (a1 + (25) * 4u), (sint32)(a1));
  v9 = r_u32((a1 + (28) * 4u));
  w_u32((a1 + (31) * 4u), 2);
  w_u32((a1 + (34) * 4u), 0x8004f478u);
  w_u32((a1 + (33) * 4u), 0);
  w_u32((a1 + (28) * 4u), (sint32)((uint32)(v9) + (uint32)(1)));
  sub_8004F758(a1, a4);
  ob_draft_unresolved_call(0x80043bacu, 2u, (a1 + (7) * 4u), (sint32)(a1));
  v10 = r_u32((a1 + (6) * 4u));
  w_u32((a1 + (16) * 4u), 0x8004f418u);
  ob_draft_unresolved_call(0x800451e4u, 2u, v10, (a1 + (7) * 4u));
  return a1;
}


uint32 sub_8001A1CC(void)
{
    FUNCTION_MARKER(0x8001a1ccu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8001A398 */
  sint32 v0;
  uint32 v1;
  sint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  v0 = 0;
  if ((sint8)r_u8(0x8006c230u))
  {
    v1 = 0x8006c138u;
    v2 = (sint32)(0u - (uint32)(2146657940));
    v3 = (sint32)(0u - (uint32)(2146657944));
    do
    {
      v4 = v0;
      if (((sint8)r_u8(0x8006c230u) != 1))
      {
        if (((sint8)r_u8((0x8006c236u + (v0) * 1u)) != 1))
        {
          w_u32(v1, 0);
          ob_draft_unresolved_call((sint32)r_u32(0x8009450C), 3u, 0, 0, 0);
          ((v1 += 4u));
          goto LABEL_8;
        }
        v4 = v0;
      }
      w_u32(0x8008C6F8, 0);
      w_u32(0x8008C6F4, 255);
      ob_draft_unresolved_call(0x8001a398u, 1u, v4);
      w_u32(0x8006c14cu, v0);
      v5 = r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(104) * (uint32)((sint16)(ob_draft_unresolved_call((sint32)r_u32(0x800A50BC), 1u, (sint32)(0u - (uint32)(2146908440))))))) - (uint32)(2146649520))));
      w_u32(v1, v5);
      w_u32((uint32)(v3), v5);
      v6 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v1)) + (uint32)(108))));
      w_u32((uint32)((sint32)((uint32)(v6) + (uint32)(4))), v0);
      w_u16((uint32)((sint32)((uint32)((sint32)r_u32(v1)) + (uint32)(304))), 0);
      ob_draft_unresolved_call((sint32)r_u32(0x8009450C), 3u, r_u32((uint32)(v3)), (sint32)r_u32(v1), 0);
      w_u8((uint32)((sint32)((uint32)(v6) + (uint32)(45))), 1);
      w_u8((uint32)((sint32)((uint32)(v6) + (uint32)(46))), 4);
      v7 = (sint32)r_u32(((v1 += 4u) - 4u));
      ob_draft_unresolved_call((sint32)r_u32(0x800B4874), 2u, v7, (sint32)r_u32(0x80077334u));
      w_u32((uint32)(v2), ((r_u32((uint32)(v2)) & 0xFFFFFFFC) | 1));
      LABEL_8:
      v2 = ((uint32)(v2) + (uint32)(56));

      ++v0;
      v3 = ((uint32)(v3) + (uint32)(56));
    }
    while ((v0 < (uint8)((sint8)r_u8(0x8006c230u))));
  }
  w_u32(0x8006c14cu, 0);
  w_u16(0x800C4E70, 0);
  w_u32(0x8006c134u, (sint32)r_u32((0x8006c138u + (0) * 4u)));
  return ob_draft_unresolved_call((sint32)r_u32(0x80093C44), 1u, 0);
}


uint32 sub_800215FC(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5, uint32 a6, uint32 a7, uint32 a8, uint32 a9, uint32 a10, uint32 a11)
{
    FUNCTION_MARKER(0x800215fcu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80025874 */
    /* TODO: Bind external adapter for sub_8005BB60 */
    /* TODO: Bind external adapter for sub_8005BA48 */
  uint32 v18;
  uint32 v19;
  uint32 v20;
  sint32 v21;
  sint32 v22;
  sint32 v23;
  uint32 v24;
  uint32 result;
  sint32 v26;
  sint8 v27;
  sint32 v28;
  sint32 v29;
  sint8 v30;
  uint32 v31;
  v18 = (uint32)(ob_draft_unresolved_call(0x80025874u, 1u, (r_u32(a1) >> 17)));
  v19 = (uint32)(ob_draft_unresolved_call(0x80025874u, 1u, ((r_u32(a1) >> 2) & 0x7FFF)));
  v20 = r_u32(v18);
  v21 = ((r_u32(v19) >> 4) & 0xF0);
  v22 = (r_u32(v19) >> 8);
  sub_800217B4((uint16)((r_u32(v19)) >> 16));
  v23 = (sint32)r_u32(0x800774a8u);
  v24 = (uint32)((sint32)r_u32(0x80077634u));
  result = ((sint32)((sint32)((uint32)((sint32)r_u32(0x800775bcu)) - (uint32)((sint32)r_u32(0x800774a8u)))) < (sint32)(20));
  v26 = r_u32((uint32)((sint32)r_u32(0x80077634u)));
  v27 = (v22 & 0xF0);
  if (((sint32)((sint32)((uint32)((sint32)r_u32(0x800775bcu)) - (uint32)((sint32)r_u32(0x800774a8u)))) >= (sint32)(20)))
  {
    v28 = (sint32)r_u32(0x800774a8u);
    v29 = r_u32((uint32)((sint32)r_u32(0x80077634u)));
    w_u32(0x800774a8u, ((uint32)((sint32)r_u32(0x800774a8u)) + (uint32)(20)));
    w_u32(0x80077634u, v23);
    w_u32(v24, ((v29 & 0xFF000000) | (v23 & 0xFFFFFF)));
    ob_draft_unresolved_call(0x8005bb60u, 1u, v28);
    v30 = (sint32)((uint32)(v21) + (uint32)(a2));
    if ((a11 == 1))
    {
      ob_draft_unresolved_call(0x8005ba48u, 2u, v23, 1);
      v30 = (sint32)((uint32)(v21) + (uint32)(a2));
    }
    w_u8((uint32)((sint32)((uint32)(v23) + (uint32)(12))), v30);
    w_u8((uint32)((sint32)((uint32)(v23) + (uint32)(13))), (sint32)((uint32)(v27) + (uint32)(a3)));
    w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(8))), a6);
    w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(10))), a7);
    w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(16))), a4);
    w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(18))), a5);
    w_u8((uint32)((sint32)((uint32)(v23) + (uint32)(4))), a8);
    w_u8((uint32)((sint32)((uint32)(v23) + (uint32)(5))), a9);
    w_u8((uint32)((sint32)((uint32)(v23) + (uint32)(6))), a10);
    v31 = (uint32)((sint32)r_u32(0x80077634u));
    w_u16((uint32)((sint32)((uint32)(v23) + (uint32)(14))), (v20 >> 2));
    result = ((r_u32(v31) & 0xFF000000) | (v26 & 0xFFFFFF));
    w_u32(v31, result);
  }
  return result;
}


uint32 sub_80046954(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80046954u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80047A60 */
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
        sub_80046BE8(a1, r_u32(v4), v8, a2);
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


void sub_80040BF0(uint32 a1)
{
    FUNCTION_MARKER(0x80040bf0u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8005F398 */
    /* TODO: Bind external adapter for sub_8005F428 */
    /* TODO: Bind external adapter for sub_8005F3C8 */
  sint16 v2;
  sint16 v3;
  sint16 v4;
  sint16 v5;
  sint16 v6;
  sint16 v7;
  sint16 v8;
  sint16 v9;
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
  sint16 v27;
  sint16 v28;
  sint16 v29;
  sint16 v30;
  sint16 v31;
  sint16 v32;
  sint16 v33;
  sint32 v34;
  sint32 v35;
  sint32 v36;
  v2 = r_u16((uint32)(a1));
  v3 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(2))));
  v4 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(4))));
  v5 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(6))));
  v6 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(8))));
  v7 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(10))));
  v8 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(12))));
  v9 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(14))));
  v10 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(16))));
  v11 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))));
  v12 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(28))));
  v13 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(32))));
  v14 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(36))));
  v15 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(40))));
  v16 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(44))));
  v17 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(48))));
  v18 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(52))));
  w_u16(0x800775f0u, v2);
  w_u16(0x800775a4u, v3);
  w_u16(0x80077410u, v4);
  w_u16(0x800775a6u, v5);
  w_u16(0x80077388u, v6);
  w_u16(0x8007748cu, v7);
  w_u16(0x80077480u, v8);
  w_u16(0x800775a0u, v9);
  w_u32(0x80077598u, v10);
  w_u32(0x80077574u, v11);
  w_u32(0x80077518u, v12);
  w_u32(0x80077628u, v13);
  w_u32(0x800775ecu, v14);
  w_u32(0x80077610u, v15);
  w_u32(0x800773a4u, v16);
  w_u32(0x800775e4u, v17);
  w_u32(0x80077420u, v18);
  v19 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(98))));
  v20 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(100))));
  v21 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(60))));
  v22 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(64))));
  v23 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(108))));
  w_u32(0x80077328u, r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(56)))));
  w_u16(0x80077364u, v19);
  w_u16(0x80077638u, v20);
  w_u32(0x8007759cu, v21);
  w_u32(0x80077530u, v22);
  w_u32(0x800773c0u, v23);
  if ((v19 || v20))
  {
    v24 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(72))));
    v25 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(76))));
    v26 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(80))));
    v27 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(84))));
    v28 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(86))));
    v29 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(88))));
    v30 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(90))));
    v31 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(92))));
    v32 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(94))));
    v33 = r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(96))));
    v34 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(104))));
    v35 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(112))));
    v36 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(116))));
    w_u32(0x800773dcu, r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(68)))));
    w_u32(0x800775b8u, v24);
    w_u32(0x8007736cu, v25);
    w_u32(0x800775c4u, v26);
    w_u16(0x80077524u, v27);
    w_u16(0x8007751eu, v28);
    w_u16(0x80077522u, v29);
    w_u16(0x8007751cu, v30);
    w_u16(0x8007752cu, v31);
    w_u16(0x80077520u, v32);
    w_u16(0x8007735cu, v33);
    w_u32(0x80077560u, v34);
    w_u32(0x80077558u, v35);
    w_u32(0x80077648u, v36);
    ob_draft_unresolved_call(0x8005f398u, 1u, v35);
    ob_draft_unresolved_call(0x8005f428u, 1u, (sint32)r_u32(0x80077558u));
  }
  ob_draft_unresolved_call(0x8005f3c8u, 1u, (sint32)r_u32(0x80077328u));
  ob_restore_heap_pointer(a1);
}


uint32 sub_80044EDC(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    FUNCTION_MARKER(0x80044edcu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80029E30 */
    /* TODO: Bind external adapter for sub_8002B7FC */
    /* TODO: Bind external adapter for sub_80029E54 */
    /* TODO: Bind external adapter for sub_8004395C */
    uint32 local_objects = ob_draft_scratch_acquire(4u);
  uint32 v6;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  sint32 v11;
  uint32 i;
  sint32 v13;
  ;
  v6 = r_u32(a3);
  sub_80043600((uint32)(a1), a2, (sint32)r_u32(r_u32(a3)));
  w_u32((uint32)(a1), (0x8007711cu));
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))), 0);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(28))), 0);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(32))), 0);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(160))), 0);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(72))), a4);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(76))), a4);
  ob_draft_unresolved_call(0x80029e30u, 2u, (v6 + (7) * 4u), (uint32)((sint32)((uint32)(a1) + (uint32)(80))));
  v8 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(88))));
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(92))), ((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(80))))) << (uint32)(8)));
  v9 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(84))));
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(100))), (sint32)((uint32)(v8) << (uint32)(8)));
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(96))), (sint32)((uint32)(v9) << (uint32)(8)));
  ob_draft_unresolved_call(0x8002b7fcu, 2u, ((uint32)(v6) + (5) * 2u), (uint32)((sint32)((uint32)(a1) + (uint32)(36))));
  if ((((r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(36)))) == 0x4000) && (r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(44)))) == 0x4000)) && (r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(52)))) == 0x4000)))
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(160))), ((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(160))))) | (uint32)(8u)));
  ob_draft_unresolved_call(0x80029e54u, 1u, (sint32)((uint32)(a1) + (uint32)(54)));
  v10 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(160))));
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(108))), 0);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(112))), 0);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(116))), 0);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(120))), 0);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(124))), 0);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(128))), 0);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(104))), 0);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(132))), 0);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(136))), 0);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(140))), 0);
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(160))), (v10 | 0x10));
  ob_draft_unresolved_call(0x8004395cu, 1u, (uint32)((sint32)((uint32)(a1) + (uint32)(144))));
  w_u32(a3, r_u32(a3) + 40u);
  v11 = (sint32)((uint32)((sint32)r_u32((v6 + (1) * 4u))) - (uint32)(1));
  for (i = (uint32)((sint32)((uint32)(a1) + (uint32)(32))); (v11 != (sint32)(0u - (uint32)(1))); i = (uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 0u)) + (uint32)(28))))
  {
    w_u32(local_objects + 0u, 0);
    sub_800262CC((local_objects + 0u), 164);
    sub_80044EDC((sint32)r_u32(local_objects + 0u), a1, a3, a4);
    v13 = (sint32)r_u32(local_objects + 0u);
    w_u32((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 0u)) + (uint32)(24))), a1);
    w_u32(i, v13);
    --v11;
  }

  { uint32 draft_return = a1; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80048994(uint32 a1)
{
    FUNCTION_MARKER(0x80048994u, "SLES_008.65");
  uint32 v2;
  sint32 v3;
  uint32 v4;
  uint32 v5;
  uint32 v6;
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
  sint32 result;
  v2 = (uint32)((sint32)r_u32((a1 + (1) * 4u)));
  v3 = (sint32)r_u32(a1);
  v4 = (uint32)((sint32)r_u32((a1 + (2) * 4u)));
  v5 = (uint32)(r_u32((v2 + (8) * 4u)));
  w_u32((a1 + (3) * 4u), (sint32)(v5));
  sub_800455DC(v5, v3);
  v6 = (uint32)(r_u32((v4 + (8) * 4u)));
  v7 = (sint32)r_u32(a1);
  w_u32((a1 + (4) * 4u), (sint32)(v6));
  sub_800455DC(v6, v7);
  w_u32((a1 + (6) * 4u), ((uint32)(r_u32((v2 + (19) * 4u))) + (uint32)(r_u32((v4 + (19) * 4u)))));
  w_u32((a1 + (7) * 4u), ((uint32)(r_u32((v2 + (20) * 4u))) + (uint32)(r_u32((v4 + (20) * 4u)))));
  v8 = (sint32)r_u32((a1 + (4) * 4u));
  w_u32((a1 + (8) * 4u), ((uint32)(r_u32((v2 + (21) * 4u))) + (uint32)(r_u32((v4 + (21) * 4u)))));
  v9 = ((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(v8) + (uint32)(120))))) + (uint32)(r_u32((v4 + (22) * 4u))))) - (uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32((a1 + (3) * 4u))) + (uint32)(120))))) + (uint32)(r_u32((v2 + (22) * 4u))))));
  v10 = (sint32)r_u32((a1 + (4) * 4u));
  v11 = (sint32)r_u32((a1 + (3) * 4u));
  w_u32((a1 + (9) * 4u), v9);
  v12 = ((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(v10) + (uint32)(124))))) + (uint32)(r_u32((v4 + (23) * 4u))))) - (uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(v11) + (uint32)(124))))) + (uint32)(r_u32((v2 + (23) * 4u))))));
  v13 = (sint32)r_u32((a1 + (4) * 4u));
  v14 = (sint32)r_u32((a1 + (3) * 4u));
  w_u32((a1 + (10) * 4u), v12);
  v15 = r_u32((v4 + (24) * 4u));
  v16 = r_u32((uint32)((sint32)((uint32)(v13) + (uint32)(128))));
  v17 = r_u32((uint32)((sint32)((uint32)(v14) + (uint32)(128))));
  v18 = (sint32)r_u32((a1 + (9) * 4u));
  if (((sint32)(v18) < (sint32)(0)))
    v18 = (sint32)(0u - (uint32)(v18));
  v19 = (sint32)((uint32)(v17) + (uint32)(r_u32((v2 + (24) * 4u))));
  w_u32((a1 + (12) * 4u), v18);
  v20 = (sint32)r_u32((a1 + (10) * 4u));
  w_u32((a1 + (11) * 4u), (sint32)((uint32)((sint32)((uint32)(v16) + (uint32)(v15))) - (uint32)(v19)));
  if (((sint32)(v20) < (sint32)(0)))
    v20 = (sint32)(0u - (uint32)(v20));
  w_u32((a1 + (13) * 4u), v20);
  v21 = (sint32)r_u32((a1 + (11) * 4u));
  v22 = (sint32)r_u32((a1 + (8) * 4u));
  if (((sint32)(v21) < (sint32)(0)))
    v21 = (sint32)(0u - (uint32)(v21));
  v23 = (sint32)((uint32)((sint32)r_u32((a1 + (12) * 4u))) - (uint32)((sint32)r_u32((a1 + (6) * 4u))));
  w_u32((a1 + (14) * 4u), v21);
  v24 = (sint32)r_u32((a1 + (13) * 4u));
  v25 = (sint32)r_u32((a1 + (7) * 4u));
  w_u32((a1 + (18) * 4u), v23);
  v26 = (sint32)r_u32((a1 + (14) * 4u));
  w_u32((a1 + (19) * 4u), (sint32)((uint32)(v24) - (uint32)(v25)));
  v27 = (sint32)r_u32((a1 + (4) * 4u));
  w_u32((a1 + (20) * 4u), (sint32)((uint32)(v26) - (uint32)(v22)));
  w_u32((a1 + (15) * 4u), ((uint32)(r_u32((uint32)((sint32)((uint32)(v27) + (uint32)(132))))) - (uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32((a1 + (3) * 4u))) + (uint32)(132)))))));
  w_u32((a1 + (16) * 4u), ((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32((a1 + (4) * 4u))) + (uint32)(136))))) - (uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32((a1 + (3) * 4u))) + (uint32)(136)))))));
  result = ((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32((a1 + (4) * 4u))) + (uint32)(140))))) - (uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32((a1 + (3) * 4u))) + (uint32)(140))))));
  w_u32((a1 + (17) * 4u), result);
  return result;
}


uint32 sub_8004A908(uint32 a1)
{
    FUNCTION_MARKER(0x8004a908u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8004B3C4 */
    /* TODO: Bind external adapter for sub_8003A430 */
    /* TODO: Bind external adapter for sub_8004B0B0 */
    /* TODO: Bind external adapter for sub_800257A0 */
    uint32 local_objects = ob_draft_scratch_acquire(8u);
  sint32 v1;
  sint32 result;
  sint32 v4;
  uint32 v5;
  uint32 v6;
  sint32 v7;
  sint16 v9;
  uint32 v12;
  ;
  v1 = (sint32)r_u32(0x80077490u);
  for (result = ob_draft_unresolved_call(0x8004b3c4u, 0u); v1; v1 = r_u32((uint32)((sint32)((uint32)(v1) + (uint32)(28)))))
  {
    result = a1;
    if ((r_u8((uint32)((sint32)((uint32)(v1) + (uint32)(36)))) == a1))
    {
      result = (sint8)r_u8((uint32)((sint32)((uint32)(v1) + (uint32)(52))));
      if (!(r_u8((uint32)((sint32)((uint32)(v1) + (uint32)(52))))))
      {
        v4 = sub_80045464(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(v1) + (uint32)(24))))) + (uint32)(52)))), (sint32)r_u32(0x800775fcu));
        v5 = r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(v1) + (uint32)(24))))) + (uint32)(40))));
        v6 = (uint32)(v4);
        if (((r_u32(v5) & 3) != 0))
        {
          v7 = sub_800257CC((sint32)(v5));
        }
        else
        {
          (w_u16((uint32)(((uint32)(r_u32(v5)) - (uint32)(6))), (r_u16((uint32)(((uint32)(r_u32(v5)) - (uint32)(6)))) + 1u)), r_u16((uint32)(((uint32)(r_u32(v5)) - (uint32)(6)))));
          v7 = r_u32(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(v1) + (uint32)(24))))) + (uint32)(40)))));
        }
        if (!ob_draft_unresolved_call(0x8003a430u, 2u, v6, v7))
        {
          v9 = r_u16((uint32)((sint32)((uint32)(v1) + (uint32)(38))));
          if (((v9 & 0x40) == 0))
          {
            if (((v9 & 2) != 0))
            {
              sub_8004B450((local_objects + 0u), ((uint32)((((r_u8((uint32)((sint32)((uint32)(v1) + (uint32)(36))))) & 0xFFFF00FF) | ((uint32)(r_u8((uint32)((sint32)((uint32)(v1) + (uint32)(37))))) << (uint32)(8)))) << (uint32)(16)));
              if (ob_draft_unresolved_call(0x8004b0b0u, 3u, (sint32)((uint32)((((uint8)((sint8)r_u8(((local_objects + 0u) + (0) * 1u)))) | ((uint32)((uint8)((sint8)r_u8(((local_objects + 0u) + (1) * 1u)))) << (uint32)(8)))) << (uint32)(16)), v6, r_u32((uint32)((sint32)((uint32)(v1) + (uint32)(40))))))
              {
                w_u16((uint32)((sint32)((uint32)(v1) + (uint32)(38))), ((uint32)(r_u16((uint32)((sint32)((uint32)(v1) + (uint32)(38))))) | (uint32)(0x100u)));
              }
            }
            else
            {
              sub_8004AAFC(v1, v6);
            }
          }
          v12 = (uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)((sint32)((uint32)(v1) + (uint32)(37))))))) - (uint32)(2146941544)));
          w_u32((uint32)((sint32)((uint32)(v1) + (uint32)(32))), (sint32)r_u32(v12));
          w_u32(v12, v1);
        }
        result = ob_draft_unresolved_call(0x800257a0u, 1u, r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(v1) + (uint32)(24))))) + (uint32)(40)))));
      }
    }
  }

  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_8004670C(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x8004670cu, "SLES_008.65");
    /* TODO: Recover missing meaningful argument 1 of sub_80046E6C */
    /* TODO: Recover missing meaningful argument 2 of sub_80046E6C */
    /* TODO: Recover missing meaningful argument 1 of sub_80047140 */
    /* TODO: Recover missing meaningful argument 2 of sub_80047140 */

  sint32 v3;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  sint32 v11;
  sint32 v13;
  v3 = r_u32((a1 + (8) * 4u));
  v5 = 0;
  if (((r_u32((uint32)((sint32)((uint32)(v3) + (uint32)(160)))) & 0x20) != 0))
  {
    v6 = r_u32((uint32)((sint32)((uint32)(v3) + (uint32)(132))));
    if (((sint32)(v6) < (sint32)(0)))
      v6 = (sint32)(0u - (uint32)(v6));
    v7 = r_u32((uint32)(((uint32)(r_u32((a1 + (8) * 4u))) + (uint32)(136))));
    if (((sint32)(v7) < (sint32)(0)))
      v7 = (sint32)(0u - (uint32)(v7));
    v13 = v7;
    v8 = r_u32((uint32)(((uint32)(r_u32((a1 + (8) * 4u))) + (uint32)(140))));
    if (((sint32)(v8) < (sint32)(0)))
      v8 = (sint32)(0u - (uint32)(v8));
    if (((sint32)r_u32((a1 + (25) * 4u)) >= v6))
    {
      v9 = r_u32((a1 + (28) * 4u));
      if (((sint32)(v9) >= (sint32)(v6)))
      {
        if ((a3 >= r_u32((a1 + (31) * 4u))))
        {
          w_u32((a1 + (25) * 4u), v9);
          w_u32((a1 + (31) * 4u), (sint32)((uint32)(a3) + (uint32)(10000)));
          w_u32((a1 + (28) * 4u), 0);
        }
      }
      else
      {
        w_u32((a1 + (28) * 4u), v6);
      }
    }
    else
    {
      v5 = 1;
      w_u32((a1 + (25) * 4u), (sint32)((uint32)(v6) + (uint32)(((sint32)(v6) >> 2))));
      w_u32((a1 + (31) * 4u), (sint32)((uint32)(a3) + (uint32)(10000)));
    }
    if (((sint32)r_u32((a1 + (26) * 4u)) >= v13))
    {
      v10 = r_u32((a1 + (29) * 4u));
      if (((sint32)(v10) >= (sint32)(v13)))
      {
        if ((a3 >= r_u32((a1 + (32) * 4u))))
        {
          w_u32((a1 + (26) * 4u), v10);
          w_u32((a1 + (32) * 4u), (sint32)((uint32)(a3) + (uint32)(10000)));
          w_u32((a1 + (29) * 4u), 0);
        }
      }
      else
      {
        w_u32((a1 + (29) * 4u), v13);
      }
    }
    else
    {
      v5 = 1;
      w_u32((a1 + (26) * 4u), (sint32)((uint32)(v13) + (uint32)(((sint32)(v13) >> 2))));
      w_u32((a1 + (32) * 4u), (sint32)((uint32)(a3) + (uint32)(10000)));
    }
    if (((sint32)r_u32((a1 + (27) * 4u)) >= v8))
    {
      v11 = r_u32((a1 + (30) * 4u));
      if (((sint32)(v11) >= (sint32)(v8)))
      {
        if ((a3 >= r_u32((a1 + (33) * 4u))))
        {
          w_u32((a1 + (27) * 4u), v11);
          w_u32((a1 + (33) * 4u), (sint32)((uint32)(a3) + (uint32)(10000)));
          w_u32((a1 + (30) * 4u), 0);
        }
      }
      else
      {
        w_u32((a1 + (30) * 4u), v8);
      }
    }
    else
    {
      v5 = 1;
      w_u32((a1 + (27) * 4u), (sint32)((uint32)(v8) + (uint32)(((sint32)(v8) >> 2))));
      w_u32((a1 + (33) * 4u), (sint32)((uint32)(a3) + (uint32)(10000)));
    }
  }
  if ((v5 || ((r_u32((uint32)(((uint32)(r_u32((a1 + (8) * 4u))) + (uint32)(160)))) & 0x40) != 0)))
    return sub_80046E6C(ob_native_missing_value(0x8004670cu, "todo_argument_0"), ob_native_missing_value(0x8004670cu, "todo_argument_1"));
  else
    return sub_80047140(ob_native_missing_value(0x8004670cu, "todo_argument_2"), ob_native_missing_value(0x8004670cu, "todo_argument_3"));
}


uint32 sub_80026F48(uint32 a1)
{
    FUNCTION_MARKER(0x80026f48u, "SLES_008.65");
    /* TODO: Bind external adapter for nullsub_22 */
    /* TODO: Bind external adapter for sub_8002785C */
    /* TODO: Bind external adapter for sub_8002691C */
    /* TODO: Bind external adapter for sub_800278AC */
    /* TODO: Bind external adapter for sub_80027154 */
    /* TODO: Bind external adapter for sub_80026950 */
  uint32 v1;
  sint32 v2;
  sint32 v3;
  uint32 v4;
  uint32 v5;
  uint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  uint32 v10;
  sint32 v11;
  v1 = 0;
  v2 = r_u32((uint32)((sint32)r_u32(0x8007721cu)));
  v3 = (sint32)((uint32)(((sint32)(0u - (uint32)(a1)) & 3)) + (uint32)(4));
  v4 = (sint32)((uint32)(a1) + (uint32)(v3));
  v5 = (sint32)((uint32)((sint32)((uint32)(a1) + (uint32)(v3))) + (uint32)(40));
  if (!(r_u32((uint32)((sint32)r_u32(0x8007721cu)))))
    goto LABEL_12;
  do
  {
    if ((((r_u8((uint32)((sint32)((uint32)(v2) + (uint32)(32)))) & 0x80) != 0) || (!(r_u16((uint32)((sint32)((uint32)(v2) + (uint32)(34))))) && (((r_u8((uint32)((sint32)((uint32)(v2) + (uint32)(32)))) & 1) != 0) || (((r_u8((uint32)((sint32)((uint32)(v2) + (uint32)(32)))) & 2) != 0) && !(r_u16((uint32)((sint32)((uint32)(v2) + (uint32)(36))))))))))
    {
      v1 = ((uint32)(v1) + (uint32)((sint32)((uint32)(40) + (uint32)(r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(16))))))));
      if ((v1 >= v5))
        break;
    }
    else
    {
      v1 = 0;
    }
    v2 = r_u32((uint32)(v2));
  }
  while (v2);
  v6 = ((uint32)(v1) - (uint32)(v5));
  if (!v2)
  {
    LABEL_12:
    ob_draft_unresolved_call(0x800279ccu, 0u);

    v6 = ((uint32)(v1) - (uint32)(v5));
  }
  v7 = r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(16))));
  v8 = 56;
  if ((uint32)v7 - (v6 - 40u) >= 0x38u)
    v8 = (sint32)((uint32)(v7) - (uint32)(((uint32)(v6) - (uint32)(40))));
  v9 = (sint32)((uint32)(v8) - (uint32)(40));
  v10 = (sint32)((uint32)(v7) - (uint32)((sint32)((uint32)(v8) - (uint32)(40))));
  if (((r_u8((uint32)((sint32)((uint32)(v2) + (uint32)(32)))) & 0x80) != 0))
  {
    ob_draft_unresolved_call(0x8002785cu, 1u, v2);
    if ((v10 >= 0x38))
    {
      ob_draft_unresolved_call(0x8002691cu, 3u, (sint32)((uint32)(v2) + (uint32)(v10)), v2, v9);
      w_u32((uint32)((sint32)((uint32)(v2) + (uint32)(16))), ((uint32)(v10) - (uint32)(40)));
      ob_draft_unresolved_call(0x800278acu, 1u, v2);
      v2 = ((uint32)(v2) + (uint32)(v10));
    }
  }
  else
  {
    sub_8002744C(v2);
    if ((v10 >= 0x38))
    {
      ob_draft_unresolved_call(0x8002691cu, 3u, (sint32)((uint32)(v2) + (uint32)(v10)), v2, v9);
      w_u32((uint32)((sint32)((uint32)(v2) + (uint32)(16))), ((uint32)(v10) - (uint32)(40)));
      ob_draft_unresolved_call(0x80027154u, 1u, v2);
      v2 = ((uint32)(v2) + (uint32)(v10));
    }
  }
  while ((r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(16)))) < v4))
  {
    v11 = r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(4))));
    if (((r_u8((uint32)((sint32)((uint32)(v11) + (uint32)(32)))) & 0x80) != 0))
      ob_draft_unresolved_call(0x8002785cu, 1u, v11);
    else
      sub_8002744C(v11);
    ob_draft_unresolved_call(0x80026950u, 1u, v2);
  }

  w_u32((uint32)((sint32)((uint32)(v2) + (uint32)(20))), (sint32)((uint32)((sint32)((uint32)(v3) + (uint32)(r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(16))))))) - (uint32)(v4)));
  return v2;
}


uint32 sub_80050644(uint32 a1)
{
    FUNCTION_MARKER(0x80050644u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80050870 */
    /* TODO: Bind external adapter for sub_8005160C */
  uint32 v1;
  sint32 v2;
  sint32 result;
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
  sint32 v29;
  sint32 v30;
  sint32 v31;
  sint32 v32;
  v1 = a1;
  v2 = r_u32(a1);
  while (1)
  {
    ob_draft_unresolved_call(0x80050870u, 1u, a1);
    v31 = r_u32((v1 + (28) * 4u));
    result = (v2 < (sint32)r_u32((v1 + (13) * 4u)));
    if ((v2 >= (sint32)r_u32((v1 + (13) * 4u))))
      break;
    v32 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(8))));
    result = 2147418112;
    if (((sint32)r_u32((v1 + (27) * 4u)) < v32))
      break;
    result = 2147483393;
    if ((v32 == 2147483393))
      break;
    v4 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(36))));
    v5 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(44))));
    v2 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(8))));
    if ((((sint32)(v4) < (sint32)(v5)) || ((v4 == v5) && (r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(40)))) < r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(48))))))))
    {
      v6 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(36))));
      (w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(20))), (r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(20)))) + 1u)), r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(20)))));
      if ((v6 < (sint32)r_u32((v1 + (21) * 4u))))
      {
        w_u32((v1 + (29) * 4u), v6);
        w_u32((v1 + (31) * 4u), r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(40)))));
        w_u32((v1 + (32) * 4u), r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(76)))));
        ob_draft_unresolved_call(r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(4)))), 1u, v1);
      }
      v7 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(56))));
      w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(52))), ((uint32)(r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(52))))) + (uint32)(r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(80)))))));
      v8 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(76))));
      v9 = (sint32)((uint32)(v7) + (uint32)(r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(84))))));
      w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(56))), v9);
      if (((sint32)(v9) >= (sint32)(v8)))
      {
        v10 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(52))));
        w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(56))), (sint32)((uint32)(v9) - (uint32)(v8)));
        w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(52))), (sint32)((uint32)(v10) + (uint32)(1)));
      }
      v11 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(56))));
      v12 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(44))));
      v13 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(48))));
      w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(36))), r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(52)))));
      w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(40))), v11);
      w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(8))), v12);
      w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(12))), v13);
    }
    else
    {
      v14 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(88))));
      v15 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(24))));
      v16 = ((uint32)(r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(92))))) + (uint32)(132));
      w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(16))), ((uint32)(r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(16))))) + (uint32)(v15)));
      ob_draft_unresolved_call(0x8005160cu, 3u, v16, v14, v15);
      v17 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(68))));
      v18 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(72))));
      v19 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(80))));
      v20 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(76))));
      w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(28))), ((uint32)(r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(28))))) + (uint32)(r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(32)))))));
      v21 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(20))));
      v22 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(68))));
      w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(60))), v17);
      w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(64))), v18);
      v23 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(64))));
      v24 = (sint32)((uint32)(v22) + (uint32)(v19));
      v25 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(60))));
      w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(68))), v24);
      v26 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(72))));
      w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(20))), (sint32)((uint32)(v21) - (uint32)(1)));
      v27 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(84))));
      w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(48))), v23);
      v28 = (sint32)((uint32)(v26) + (uint32)(v27));
      w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(72))), (sint32)((uint32)(v26) + (uint32)(v27)));
      w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(44))), v25);
      if (((sint32)((sint32)((uint32)(v26) + (uint32)(v27))) >= (sint32)(v20)))
      {
        v29 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(68))));
        w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(72))), (sint32)((uint32)(v28) - (uint32)(v20)));
        w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(68))), (sint32)((uint32)(v29) + (uint32)(1)));
      }
      v30 = r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(40))));
      w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(8))), r_u32((uint32)((sint32)((uint32)(v31) + (uint32)(36)))));
      w_u32((uint32)((sint32)((uint32)(v31) + (uint32)(12))), v30);
    }
    a1 = v1;
  }

  return result;
}


uint32 sub_8002B15C(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x8002b15cu, "SLES_008.65");
  sint32 v3;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  sint32 v11;
  sint32 result;
  v3 = (sint16)r_u16(a2);
  v4 = (sint16)r_u16((a2 + (1) * 2u));
  v5 = (sint16)r_u16((a2 + (2) * 2u));
  w_u16(a3, ((sint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(v3) * (uint32)((sint16)r_u16(a1)))) + (uint32)((sint32)((uint32)(v4) * (uint32)((sint16)r_u16((a1 + (3) * 2u))))))) + (uint32)((sint32)((uint32)(v5) * (uint32)((sint16)r_u16((a1 + (6) * 2u))))))) >> 14));
  w_u16((a3 + (1) * 2u), ((sint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(v3) * (uint32)((sint16)r_u16((a1 + (1) * 2u))))) + (uint32)((sint32)((uint32)(v4) * (uint32)((sint16)r_u16((a1 + (4) * 2u))))))) + (uint32)((sint32)((uint32)(v5) * (uint32)((sint16)r_u16((a1 + (7) * 2u))))))) >> 14));
  w_u16((a3 + (2) * 2u), ((sint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(v3) * (uint32)((sint16)r_u16((a1 + (2) * 2u))))) + (uint32)((sint32)((uint32)(v4) * (uint32)((sint16)r_u16((a1 + (5) * 2u))))))) + (uint32)((sint32)((uint32)(v5) * (uint32)((sint16)r_u16((a1 + (8) * 2u))))))) >> 14));
  v6 = (sint16)r_u16((a2 + (3) * 2u));
  v7 = (sint16)r_u16((a2 + (4) * 2u));
  v8 = (sint16)r_u16((a2 + (5) * 2u));
  w_u16((a3 + (3) * 2u), ((sint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(v6) * (uint32)((sint16)r_u16(a1)))) + (uint32)((sint32)((uint32)(v7) * (uint32)((sint16)r_u16((a1 + (3) * 2u))))))) + (uint32)((sint32)((uint32)(v8) * (uint32)((sint16)r_u16((a1 + (6) * 2u))))))) >> 14));
  w_u16((a3 + (4) * 2u), ((sint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(v6) * (uint32)((sint16)r_u16((a1 + (1) * 2u))))) + (uint32)((sint32)((uint32)(v7) * (uint32)((sint16)r_u16((a1 + (4) * 2u))))))) + (uint32)((sint32)((uint32)(v8) * (uint32)((sint16)r_u16((a1 + (7) * 2u))))))) >> 14));
  w_u16((a3 + (5) * 2u), ((sint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(v6) * (uint32)((sint16)r_u16((a1 + (2) * 2u))))) + (uint32)((sint32)((uint32)(v7) * (uint32)((sint16)r_u16((a1 + (5) * 2u))))))) + (uint32)((sint32)((uint32)(v8) * (uint32)((sint16)r_u16((a1 + (8) * 2u))))))) >> 14));
  v9 = (sint16)r_u16((a2 + (6) * 2u));
  v10 = (sint16)r_u16((a2 + (7) * 2u));
  v11 = (sint16)r_u16((a2 + (8) * 2u));
  w_u16((a3 + (6) * 2u), ((sint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(v9) * (uint32)((sint16)r_u16(a1)))) + (uint32)((sint32)((uint32)(v10) * (uint32)((sint16)r_u16((a1 + (3) * 2u))))))) + (uint32)((sint32)((uint32)(v11) * (uint32)((sint16)r_u16((a1 + (6) * 2u))))))) >> 14));
  w_u16((a3 + (7) * 2u), ((sint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(v9) * (uint32)((sint16)r_u16((a1 + (1) * 2u))))) + (uint32)((sint32)((uint32)(v10) * (uint32)((sint16)r_u16((a1 + (4) * 2u))))))) + (uint32)((sint32)((uint32)(v11) * (uint32)((sint16)r_u16((a1 + (7) * 2u))))))) >> 14));
  result = ((sint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(v9) * (uint32)((sint16)r_u16((a1 + (2) * 2u))))) + (uint32)((sint32)((uint32)(v10) * (uint32)((sint16)r_u16((a1 + (5) * 2u))))))) + (uint32)((sint32)((uint32)(v11) * (uint32)((sint16)r_u16((a1 + (8) * 2u))))))) >> 14);
  w_u16((a3 + (8) * 2u), result);
  return result;
}


uint32 sub_80012BE8(uint32 a1)
{
    FUNCTION_MARKER(0x80012be8u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80064018 */
    /* TODO: Bind external adapter for sub_80013794 */
    /* TODO: Bind external adapter for sub_80064028 */
    /* TODO: Bind external adapter for sub_80063FD8 */
    /* TODO: Bind external adapter for sub_80012E78 */
    /* TODO: Bind external adapter for sub_80063F98 */
    /* TODO: Bind external adapter for sub_80055964 */
    uint32 local_objects = ob_draft_scratch_acquire(760u);
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
  sint32 v18;
  sint32 v19;
  ;
  ;
  ;
  v2 = 1;
  v3 = 15;
  v4 = 0;
  ob_draft_unresolved_call(0x80064018u, 1u, r_u32(0x80010008u));
  v5 = ob_draft_unresolved_call(0x80013794u, 1u, a1);
  ob_draft_unresolved_call(0x80064028u, 3u, (local_objects + 552u), 0x80010024u, v5);
  ob_draft_unresolved_call(0x80063fd8u, 3u, (sint32)((uint32)((sint32)((uint32)(552) * (uint32)(a1))) - (uint32)(2146919128)), 0, 552);
  ob_draft_unresolved_call(0x80063fd8u, 3u, (sint32)(0u - (uint32)(2146940216)), 0, 7680);
  v6 = sub_80055954((local_objects + 552u), (local_objects + 512u));
  v7 = a1;
  if (v6)
  {
    do
    {
      if (ob_draft_unresolved_call(0x80012e78u, 3u, v7, (local_objects + 512u), (local_objects + 0u)))
      {
        v8 = r_u8(local_objects + 3u);
        if (r_u8(local_objects + 3u))
        {
          v9 = (sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(36) * (uint32)(v4))) + (uint32)((sint32)((uint32)(552) * (uint32)(a1))))) - (uint32)(2146919116));
          v10 = (sint32)((uint32)((sint32)((uint32)(36) * (uint32)(v4))) + (uint32)((sint32)((uint32)(552) * (uint32)(a1))));
          do
          {
            if (((sint32)(v3) <= (sint32)(0)))
              break;
            w_u32((uint32)((sint32)((uint32)(v10) - (uint32)(2146919116))), 1);
            w_u32((uint32)((sint32)((uint32)(v10) - (uint32)(2146919112))), v2);
            w_u32((uint32)((sint32)((uint32)(v10) - (uint32)(2146919108))), 0);
            ob_draft_unresolved_call(0x80063f98u, 2u, (sint32)((uint32)(v9) + (uint32)(12)), (local_objects + 512u));
            v11 = (uint32)((sint32)((uint32)((sint32)((uint32)(v4) << (uint32)(9))) - (uint32)(2146940216)));
            v12 = (local_objects + 0u);
            if ((((uint32)((local_objects + 0u)) & 3) != 0))
            {
              do
              {
                v13 = r_u32(((uint32)(v12) + (1) * 4u));
                v14 = r_u32(((uint32)(v12) + (2) * 4u));
                v15 = r_u32(((uint32)(v12) + (3) * 4u));
                w_u32(v11, r_u32((uint32)(v12)));
                w_u32((v11 + (1) * 4u), v13);
                w_u32((v11 + (2) * 4u), v14);
                w_u32((v11 + (3) * 4u), v15);
                v12 += (16) * 1u;
                v11 += (4) * 4u;
              }
              while ((v12 != (local_objects + 512u)));
              v9 = ((uint32)(v9) + (uint32)(36));
            }
            else
            {
              do
              {
                v16 = r_u32(((uint32)(v12) + (1) * 4u));
                v17 = r_u32(((uint32)(v12) + (2) * 4u));
                v18 = r_u32(((uint32)(v12) + (3) * 4u));
                w_u32(v11, r_u32((uint32)(v12)));
                w_u32((v11 + (1) * 4u), v16);
                w_u32((v11 + (2) * 4u), v17);
                w_u32((v11 + (3) * 4u), v18);
                v12 += (16) * 1u;
                v11 += (4) * 4u;
              }
              while ((v12 != (local_objects + 512u)));
              v9 = ((uint32)(v9) + (uint32)(36));
            }
            v10 = ((uint32)(v10) + (uint32)(36));
            ++v4;
            --v8;
            --v3;
          }
          while (((sint32)(v8) > (sint32)(0)));
        }
        ++v2;
      }
      if (!ob_draft_unresolved_call(0x80055964u, 1u, (local_objects + 512u)))
        break;
      v7 = a1;
    }
    while (((sint32)(v3) > (sint32)(0)));
  }
  v19 = (sint32)((uint32)(552) * (uint32)(a1));
  w_u32((uint32)((sint32)((uint32)(v19) - (uint32)(2146919124))), 0);
  w_u32((uint32)((sint32)((uint32)(v19) - (uint32)(2146919120))), v4);
  ob_draft_unresolved_call(0x80064018u, 1u, r_u32(0x80010030u));
  { uint32 draft_return = v4; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80015FA8(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x80015fa8u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8001FB50 */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Bind external adapter for sub_8005C504 */
    /* TODO: Bind external adapter for sub_80059CA8 */
    /* TODO: Bind external adapter for sub_8005C7C8 */
    /* TODO: Bind external adapter for sub_8005CB04 */
    /* TODO: Bind external adapter for sub_8002CFA8 */
    /* TODO: Bind external adapter for sub_8005CB78 */
    /* TODO: Bind external adapter for sub_8005CD50 */
    /* TODO: Bind external adapter for sub_80054320 */
    /* TODO: Bind external adapter for sub_80054440 */
    /* TODO: Bind external adapter for sub_8001FBCC */
    uint32 local_objects = ob_draft_scratch_acquire(528u);
  sint32 v6;
  sint16 v7;
  sint32 v8;
  sint32 v9;
  uint32 v10;
  sint32 result;
  ;
  ;
  ;
  ;
  ;
  ;
  sint16 v18;
  sint32 v19;
  sint32 v20;
  sint32 v21;
  uint32 v22;
  v6 = 0;
  switch ((sint32)r_u32(0x8008CEBC))
  {
    case 9:

    case 0xE:

    case 0x13:

    case 0x18:

    case 0x1D:
      v6 = 1;
      ob_draft_unresolved_call(0x8001fb50u, 0u);
      break;

    default:
      break;

  }

  sub_800169D0((local_objects + 8u), a3);
  v22 = (local_objects + 8u);
  w_u16(local_objects + 0u, ((sint32)((sint32)((uint32)(384) - (uint32)(r_u16(a3)))) / (sint32)(2)));
  v7 = r_u16(a3);
  w_u16(local_objects + 6u, 1);
  w_u16(local_objects + 4u, v7);
  sub_8002D25C((sint32)(0u - (uint32)(2146906416)), (sint32)(0u - (uint32)(2146931856)));
  sub_80016768();
  sub_80016598(a1);
  w_u16(local_objects + 0u, ((sint32)((sint32)((uint32)(384) - (uint32)(r_u16(a3)))) / (sint32)(2)));
  v8 = ((sint32)((sint32)((uint32)(256) - (uint32)(r_u16((a3 + (1) * 2u))))) / (sint32)(2));
  w_u16(local_objects + 2u, v8);
  if (!(sint32)r_u32(0x800773d0u))
    w_u16(local_objects + 2u, (sint32)((uint32)(v8) + (uint32)(256)));
  v21 = (sint32)((uint32)((sint32)(a3)) + (uint32)(r_u32(((uint32)(a3) + (4) * 4u))));
  v9 = r_u32(((uint32)(a3) + (3) * 4u));
  w_u32(((local_objects + 520u) + (1) * 4u), (sint32)(a3));
  v18 = (r_u16(0x80089B24) | 1);
  v19 = v9;
  ob_draft_unresolved_call(0x8005c504u, 1u, 0);
  ob_draft_unresolved_call(0x80059ca8u, 1u, 0);
  for (; v19; (w_u16(local_objects + 2u, ((sint16)r_u16(local_objects + 2u) + 1u)), (sint16)r_u16(local_objects + 2u)))
  {
    w_u32(((local_objects + 520u) + (0) * 4u), a2);
    v20 = 308;
    sub_80016A50((local_objects + 520u));
    ob_draft_unresolved_call(0x8005c504u, 1u, 0);
    ob_draft_unresolved_call(0x8005c7c8u, 2u, (local_objects + 0u), a2);
  }

  ob_draft_unresolved_call(0x8005c504u, 1u, 0);
  w_u32(0x8007754cu, (sint32)r_u32(0x8007737cu));
  ob_draft_unresolved_call(0x8005cb04u, 1u, (sint32)((uint32)((sint32)r_u32(0x8007737cu)) + (uint32)(112)));
  ob_draft_unresolved_call(0x8005c504u, 1u, 0);
  ob_draft_unresolved_call(0x8002cfa8u, 0u);
  ob_draft_unresolved_call(0x8005cb78u, 1u, (sint32)r_u32(0x8007754cu));
  ob_draft_unresolved_call(0x8005cd50u, 1u, (sint32)((uint32)((sint32)r_u32(0x8007754cu)) + (uint32)(92)));
  sub_8001FC60();
  ob_draft_unresolved_call(0x8005c504u, 1u, 0);
  ob_draft_unresolved_call(0x8002cfa8u, 0u);
  ob_draft_unresolved_call(0x80054320u, 0u);
  while (1)
  {
    v10 = (ob_draft_unresolved_call(0x80054440u, 1u, (sint32)r_u32((uint32)((((uint32)((0x80065bb8u)) + ((sint32)r_u32(0x80065cacu)) * 1u) + (2147066988) * 1u)))) != 0);
    result = 1;
    if (v10)
      break;
    ob_draft_unresolved_call(0x80054320u, 0u);
    sub_8001FC60();
  }

  if ((v6 == 1))
    { uint32 draft_return = ob_draft_unresolved_call(0x8001fbccu, 0u); ob_draft_scratch_release(local_objects);  return draft_return; }
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_8004E028(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x8004e028u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8002FAA8 */
    uint32 local_objects = ob_draft_scratch_acquire(16u);
  uint8 v6;
  sint32 v7;
  uint32 v8;
  sint16 v9;
  sint32 v10;
  sint32 v11;
  sint32 v12;
  uint32 v13;
  uint32 v14;
  sint32 v15;
  uint32 v16;
  sint32 v17;
  sint32 v18;
  sint32 v19;
  uint32 v20;
  sint32 v21;
  uint8 v22;
  sint32 v23;
  uint32 result;
  ;
  v6 = ((a1 & 0xF) | (sint32)((uint32)(16) * (uint32)((a2 & 0xF))));
  w_u32(0x80077350u, 6);
  w_u32(0x8007762cu, (sint32)((uint32)(a1) - (uint32)((sint32)r_u32(0x80077494u))));
  w_u32(0x800C8560, ((uint32)((sint32)r_u32(0x800C8560)) | (uint32)(8u)));
  v7 = r_u32((uint32)((sint32)r_u32(0x80077644u)));
  w_u32(0x80077630u, (sint32)((uint32)(a2) - (uint32)((sint32)r_u32(0x8007749cu))));
  v8 = ((sint32)((sint32)((uint32)((sint16)(v7)) + (uint32)(((uint32)((sint32)((uint32)(v7) << (uint32)(16))) >> 31)))) >> 1);
  v9 = v7;
  sub_8004CDF4(v6, 1280);
  v10 = (sint32)(0u - (uint32)(2146941968));
  v11 = (sint16)r_u16(((uint32)(a3) + (1) * 2u));
  v12 = (v11 & 3);
  v13 = (sint32)((uint32)(4) * (uint32)((v11 & 0xFFFFFFFC)));
  v14 = (uint32)((sint32)((uint32)((sint32)((uint32)(80) * (uint32)(v12))) - (uint32)(2146919448)));
  v15 = r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(v6))) - (uint32)(2146941544))));
  v16 = (v14 + (20) * 4u);
  w_u32(0x800773f8u, v12);
  w_u32(0x800774d0u, v15);
  do
  {
    v17 = r_u32((v14 + (1) * 4u));
    v18 = r_u32((v14 + (2) * 4u));
    v19 = r_u32((v14 + (3) * 4u));
    w_u32((uint32)(v10), r_u32(v14));
    w_u32((uint32)((sint32)((uint32)(v10) + (uint32)(4))), v17);
    w_u32((uint32)((sint32)((uint32)(v10) + (uint32)(8))), v18);
    w_u32((uint32)((sint32)((uint32)(v10) + (uint32)(12))), v19);
    v14 += (4) * 4u;
    v10 = ((uint32)(v10) + (uint32)(16));
  }
  while ((v14 != v16));
  w_u32(((local_objects + 0u) + (1) * 4u), v13);
  w_u32(((local_objects + 0u) + (0) * 4u), (sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(a1) * (uint32)(v9))) - (uint32)((sint32)r_u32(0x80077458u)))) + (uint32)((sint16)(v8))));
  w_u32(((local_objects + 0u) + (2) * 4u), (sint32)((uint32)((sint32)((uint32)((sint32)r_u32(0x80077468u)) - (uint32)((sint32)((uint32)(a2) * (uint32)(v9))))) - (uint32)((sint16)(v8))));
  ob_draft_unresolved_call(0x8002faa8u, 2u, (uint32)(0x800843F0), (local_objects + 0u));
  v20 = (uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80077644u)) + (uint32)(24))))) + (uint32)((sint32)((uint32)(24) * (uint32)(r_u8(a3))))));
  if ((sint32)r_u32(v20))
  {
    w_u32(0x800843B0, 128);
    v21 = (sint32)r_u32(v20);
    w_u32(0x800843C0, 0x8004b634u);
    w_u32(0x800843B8, (sint32)(0u - (uint32)(2146941968)));
    w_u32(0x800843BC, v20);
    w_u32(0x80077350u, 6);
    w_u32(0x800843B4, v21);
    sub_80043120((sint32)(0u - (uint32)(2146942032)));
  }
  v22 = v6;
  if ((((sint32)r_u32(0x8006c204u) == 1) && (sint32)r_u32((v20 + (1) * 4u))))
  {
    w_u32(0x800843B0, 128);
    v23 = (sint32)r_u32((v20 + (1) * 4u));
    w_u32(0x800843B8, (sint32)(0u - (uint32)(2146941968)));
    w_u32(0x80077350u, 0);
    w_u32(0x800843B4, v23);
    sub_80043120((sint32)(0u - (uint32)(2146942032)));
    v22 = v6;
  }
  w_u32(0x800C8560, ((uint32)((sint32)r_u32(0x800C8560)) | (uint32)(0x10u)));
  sub_8004CDF4(v22, 0);
  result = ((sint32)r_u32(0x800C8560) & 0xFFFFFFE7);
  w_u32(0x800C8560, ((uint32)((sint32)r_u32(0x800C8560)) & (uint32)(0xFFFFFFE7)));
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80049A10(uint32 a1)
{
    FUNCTION_MARKER(0x80049a10u, "SLES_008.65");
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
  uint32 v12;
  uint32 v13;
  uint32 v14;
  sint32 v15;
  sint32 v16;
  sint32 result;
  sint32 v18;
  sub_80048994(a1);
  w_u32(0x80078EE8, (sint32)r_u32((a1 + (18) * 4u)));
  w_u32(0x80078EEC, (sint32)r_u32((a1 + (19) * 4u)));
  v2 = (sint32)r_u32((a1 + (20) * 4u));
  w_u16(0x80078ED8, 0);
  w_u16(0x80078EDA, 0);
  w_u16(0x80078EDC, 0);
  w_u32(0x80078EF0, v2);
  v3 = (sint32)r_u32((a1 + (18) * 4u));
  v4 = (sint32)r_u32((a1 + (19) * 4u));
  v5 = 1;
  if (((sint32)(v4) >= (sint32)(v3)))
  {
    if ((v4 == v3))
      v5 = 2;
    else
      v3 = (sint32)r_u32((a1 + (19) * 4u));
  }
  v6 = (sint32)r_u32((a1 + (20) * 4u));
  if (((sint32)(v6) >= (sint32)(v3)))
  {
    ++v5;
    if ((v6 != v3))
    {
      v3 = (sint32)r_u32((a1 + (20) * 4u));
      v5 = 1;
    }
  }
  v7 = (uint16)((sint16)r_u16((0x80077134u + (v5) * 2u)));
  v8 = 0;
  if (((sint32)r_u32((a1 + (18) * 4u)) == v3))
  {
    v9 = ((uint32)(v9) & ~((uint32)65535u << 0) | (((uint32)((sint16)r_u16((0x80077134u + (v5) * 2u))) & 65535u) << 0));
    if (((sint32)r_u32((a1 + (12) * 4u)) == (sint32)r_u32((a1 + (9) * 4u))))
      v9 = (sint32)(0u - (uint32)(v7));
    w_u16(0x80078ED8, v9);
    if (!v3)
    {
      v8 = 256;
      if (((sint32)r_u32((a1 + (12) * 4u)) == (sint32)r_u32((a1 + (9) * 4u))))
        v8 = 512;
    }
  }
  if (((sint32)r_u32((a1 + (19) * 4u)) == v3))
  {
    v10 = ((uint32)(v10) & ~((uint32)65535u << 0) | (((uint32)(v7) & 65535u) << 0));
    if (((sint32)r_u32((a1 + (13) * 4u)) == (sint32)r_u32((a1 + (10) * 4u))))
      v10 = (sint32)(0u - (uint32)(v7));
    w_u16(0x80078EDA, v10);
    if (!v3)
    {
      v8 = 1024;
      if (((sint32)r_u32((a1 + (13) * 4u)) == (sint32)r_u32((a1 + (10) * 4u))))
        v8 = 2048;
    }
  }
  if (((sint32)r_u32((a1 + (20) * 4u)) == v3))
  {
    v11 = ((uint32)(v11) & ~((uint32)65535u << 0) | (((uint32)(v7) & 65535u) << 0));
    if (((sint32)r_u32((a1 + (14) * 4u)) == (sint32)r_u32((a1 + (11) * 4u))))
      v11 = (sint32)(0u - (uint32)(v7));
    w_u16(0x80078EDC, v11);
    if (!v3)
    {
      v8 = 4096;
      if (((sint32)r_u32((a1 + (14) * 4u)) == (sint32)r_u32((a1 + (11) * 4u))))
        v8 = 0x2000;
    }
  }
  v12 = (uint32)((sint32)r_u32((a1 + (1) * 4u)));
  v13 = (uint32)((sint32)r_u32((a1 + (2) * 4u)));
  w_u32((v12 + (64) * 4u), 0);
  w_u32((v13 + (64) * 4u), 0);
  v14 = (uint32)((sint32)r_u32((a1 + (5) * 4u)));
  v15 = 0;
  if (((v5 == 1) && !v3))
  {
    w_u32(v14, (((r_u32(v14) & 0xFFFFFFAF) | 0x40) | v8));
    v16 = r_u32((v12 + (34) * 4u));
    v15 = 65;
    w_u32((v12 + (64) * 4u), ((uint32)(r_u32((v12 + (64) * 4u))) | (uint32)((r_u32((v13 + (34) * 4u)) & r_u32((v12 + (38) * 4u))))));
    w_u32((v13 + (64) * 4u), ((uint32)(r_u32((v13 + (64) * 4u))) | (uint32)((v16 & r_u32((v13 + (38) * 4u))))));
  }
  result = v15;
  if (((r_u32(v14) & 0x10000) != 0))
  {
    if (((((sint32)r_u32((a1 + (15) * 4u)) && r_u16(0x80078ED8)) || ((sint32)r_u32((a1 + (16) * 4u)) && r_u16(0x80078EDA))) || ((result = v15, (sint32)r_u32((a1 + (17) * 4u))) && (result = v15, r_u16(0x80078EDC)))))
    {
      v18 = r_u32((v12 + (34) * 4u));
      w_u32((v12 + (64) * 4u), ((uint32)(r_u32((v12 + (64) * 4u))) | (uint32)((r_u32((v13 + (34) * 4u)) & r_u32((v12 + (37) * 4u))))));
      w_u32((v13 + (64) * 4u), ((uint32)(r_u32((v13 + (64) * 4u))) | (uint32)((v18 & r_u32((v13 + (37) * 4u))))));
      return (v15 | 4);
    }
  }
  return result;
}


