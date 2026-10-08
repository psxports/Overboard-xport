#include "front_signatures.h"
#include "native_runtime.h"

uint32 ob_front_a_callback(uint32 target,uint32 available,uint32 first,uint32 second);
#include "psx.h"
#include <stdint.h>

uint32 ob_front_8008E138(void)
{
    FUNCTION_MARKER(0x8008e138u, "FRONT.BIN");
  return ob_front_8008E140(r_u32(0x8009BB88u));
}


uint32 ob_front_8008E198(void)
{
    FUNCTION_MARKER(0x8008e198u, "FRONT.BIN");
  return ob_front_8008E1A0(r_u32(0x8009BB88u));
}


void ob_front_8008E654(void)
{
    FUNCTION_MARKER(0x8008e654u, "FRONT.BIN");
  ;
}


uint32 ob_front_800920FC(void)
{
    FUNCTION_MARKER(0x800920fcu, "FRONT.BIN");
  uint32 result;
  result = 0x8009BCC0u;
  w_u32(0x8009bb94u, (sint32)(0x8009BCC0u));
  return result;
}


uint32 ob_front_800971D0(uint32 card_channel)
{
    FUNCTION_MARKER(0x800971d0u, "FRONT.BIN");
    /* TODO: Bind external adapter for sub_80012A90 */
  return (ob_draft_unresolved_call(0x80012a90u, 1u, card_channel) == 0);
}


uint32 ob_front_800971F0(uint32 card_channel)
{
    FUNCTION_MARKER(0x800971f0u, "FRONT.BIN");
    /* TODO: Bind external adapter for sub_80012B70 */
  return (ob_draft_unresolved_call(0x80012b70u, 1u, card_channel) == 0);
}


uint32 ob_front_80093AB4(void)
{
    FUNCTION_MARKER(0x80093ab4u, "FRONT.BIN");
  return sub_80011984((sint32)(0u - (uint32)(2147046344)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
}


uint32 ob_front_80093B74(void)
{
    FUNCTION_MARKER(0x80093b74u, "FRONT.BIN");
  return sub_80011984((sint32)(0u - (uint32)(2147046360)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
}


uint32 ob_front_800921D0(uint32 unused_a0, uint32 a2)
{
    FUNCTION_MARKER(0x800921d0u, "FRONT.BIN");
  sint32 v2;
  v2 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(8))));
  w_u8(0x8006C22E, (sint32)((uint32)(26) * (uint32)(v2)));
  return sub_8001DF58(((sint32)((uint32)(26) * (uint32)(v2)) & 0xFE));
}


uint32 ob_front_800947EC(uint32 a1)
{
    FUNCTION_MARKER(0x800947ecu, "FRONT.BIN");
    /* TODO: Bind external adapter for sub_80054440 */
  sint32 result;
  sint32 v2;
  result = ob_draft_unresolved_call(0x80054440u, 1u, a1);
  v2 = result;
  if (result)
  {
    ob_front_800947B4();
    return v2;
  }
  return result;
}


uint32 ob_front_8008E588(void)
{
    FUNCTION_MARKER(0x8008e588u, "FRONT.BIN");
  sint32 v0;
  v0 = (sint32)r_u32(0x8009bb90u);
  w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8009bb90u)) + (uint32)(140))), 250);
  w_u32((uint32)((sint32)((uint32)(v0) + (uint32)(120))), 3);
  return sub_80011984((sint32)(0u - (uint32)(2147046400)), 255, 25, 15, 0x100u, 0x0u, 0x0u);
}


uint32 ob_front_8009B4E4(uint32 a1)
{
    FUNCTION_MARKER(0x8009b4e4u, "FRONT.BIN");
  sint32 result;
  switch (a1)
  {
    case 0:

    case 1:
      result = 0;
      break;

    case 2:

    case 4:
      result = 2;
      break;

    case 3:
      result = 1;
      break;

    case 5:
      result = 3;
      break;

    case 6:
      result = 4;
      break;

    case 7:
      result = 3;
      break;

    default:
      return a1 < 8u;

  }

  return result;
}


uint32 ob_front_80098058(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x80098058u, "FRONT.BIN");
  sint32 result;
  ob_front_80097FE8(a1, a2);
  w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(28))), a3);
  w_u32((uint32)((sint32)((uint32)(a3) + (uint32)(4))), a1);
  result = a3;
  w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(4))), ((uint32)(r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(4))))) | (uint32)(0x200u)));
  return result;
}


uint32 ob_front_80092BC4(uint32 a1)
{
    FUNCTION_MARKER(0x80092bc4u, "FRONT.BIN");
  uint32 result;
  sub_80021B20((sint32)(0u - (uint32)(2147046736)));
  w_u32(0x80073518u, 0x80021C24u);
  result = r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12))))) + (uint32)(48))));
  if (result)
    return (uint32)(ob_front_a_callback(result, 2u, a1, r_u32(a1 + 12u)));
  return result;
}


uint32 ob_front_8009810C(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x8009810cu, "FRONT.BIN");
  sint32 result;
  ob_front_80097FE8(a1, a2);
  result = a3;
  w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(28))), a3);
  w_u32((uint32)((sint32)((uint32)(a3) + (uint32)(4))), a1);
  w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(4))), ((uint32)(r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(4))))) & (uint32)(~0x200u)));
  return result;
}


uint32 ob_front_80098168(uint32 a1)
{
    FUNCTION_MARKER(0x80098168u, "FRONT.BIN");
    /* TODO: Bind external adapter for sub_800263B4 */
  sint32 v2;
  v2 = (sint32)r_u32(a1);
  if ((((r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(4)))) & 0x200) != 0) && r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(28))))))
    ob_front_800981C8((sint32)((uint32)(v2) + (uint32)(28)));
  return ob_draft_unresolved_call(0x800263b4u, 1u, a1);
}


uint32 ob_front_80092214(uint32 unused_a0, uint32 a2)
{
    FUNCTION_MARKER(0x80092214u, "FRONT.BIN");
    /* TODO: Bind external adapter for sub_8001DF34 */
  sint32 v2;
  v2 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(8))));
  w_u8(0x8006C22D, (sint32)((uint32)(26) * (uint32)(v2)));
  ob_draft_unresolved_call(0x8001df34u, 1u, ((sint32)((uint32)(26) * (uint32)(v2)) & 0xFE));
  return sub_80011984((sint32)(0u - (uint32)(2147046392)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
}


uint32 ob_front_8009482C(uint32 a1)
{
    FUNCTION_MARKER(0x8009482cu, "FRONT.BIN");
    /* TODO: IDA supplied excess carriers to sub_800423D8; frozen prototype governs the draft call */
  sint32 v2;
  uint32 v3;
  sint32 v4;
  v2 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))));
  do
  {
    v3 = r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(44))));
    v4 = a1;
    if (v3)
      ob_draft_unresolved_call(v3, 2u, a1, v2);
    v2 = r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(20))));
  }
  while ((v2 != r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))))));
  return sub_800423D8();
}


uint32 ob_front_800932A0(void)
{
    FUNCTION_MARKER(0x800932a0u, "FRONT.BIN");
  uint32 v0;
  sint32 result;
  v0 = (ob_front_800947EC(12) != 0);
  result = 2;
  if (!v0)
  {
    v0 = (ob_front_800947EC(5) != 0);
    result = 6;
    if (!v0)
    {
      v0 = (ob_front_800947EC(7) != 0);
      result = 7;
      if (!v0)
      {
        v0 = (ob_front_800947EC(4) != 0);
        result = 4;
        if (!v0)
        {
          v0 = (ob_front_800947EC(6) != 0);
          result = 5;
          if (!v0)
            return ((ob_front_800947EC(14) != 0)) ? (0xA) : (0);
        }
      }
    }
  }
  return result;
}


uint32 ob_front_8008ED3C(void)
{
    FUNCTION_MARKER(0x8008ed3cu, "FRONT.BIN");
    /* TODO: Bind external adapter for sub_8001D1B0 */
  w_u8(0x8006C230, 2);
  w_u8(0x8006C231, ((uint32)(r_u8(0x8006C247)) + (uint32)(20)));
  sub_80011984((sint32)(0u - (uint32)(2147046356)), 255, 0, 15, 0x100u, 0x0u, 0x0u);
  sub_80011984((sint32)(0u - (uint32)(2147046344)), 255, 30, 15, 0x100u, 0x0u, 0x0u);
  return ob_draft_unresolved_call(0x8001d1b0u, 0u);
}


uint32 ob_front_80094918(uint32 a1, uint32 selector)
{
    FUNCTION_MARKER(0x80094918u, "FRONT.BIN");
  sint32 result;
  result = ((sint32)(selector) < (sint32)(2));
  if (((sint32)(selector) >= (sint32)(2)))
  {
    result = 3;
    if ((selector == 2))
    {
      result = (sint32)(0u - (uint32)(2147046652));
      w_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(52))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046652)));
    }
    else
      if ((selector == 3))
    {
      result = (sint32)(0u - (uint32)(2147046644));
      w_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(52))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046644)));
    }
  }
  else
    if (!selector)
  {
    result = (sint32)(0u - (uint32)(2147046668));
    w_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(52))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046668)));
  }
  if ((selector == 1))
  {
    result = 0x8006AAFCu;
    w_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(52))))) + (uint32)(40))), result);
  }
  return result;
}


uint32 ob_front_8008E2DC(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8008e2dcu, "FRONT.BIN");
  sint32 v2;
  sint32 v3;
  if ((r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12)))) == a2))
  {
    v2 = (sint32)r_u32(0x8009bb88u);
    w_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8009bb88u)) + (uint32)(52))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046572)));
    w_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(52))))) + (uint32)(32))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046568)));
  }
  else
  {
    v3 = (sint32)r_u32(0x8009bb88u);
    w_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8009bb88u)) + (uint32)(52))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046640)));
    w_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(v3) + (uint32)(52))))) + (uint32)(32))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046636)));
  }
  return ob_front_8008DD94((uint32)((sint32)r_u32(0x8009bb88u)));
}


uint32 ob_front_8008E090(uint32 a1)
{
    FUNCTION_MARKER(0x8008e090u, "FRONT.BIN");
  uint32 v2;
  uint32 v3;
  sub_80021B20((sint32)(0u - (uint32)(2147046752)));
  w_u32(0x80073518u,0x80021C24u);
  w_u32(0x8009bb88u, (sint32)(ob_front_8008DB20(0)));
  w_u32(0x8009bb8cu, (sint32)(ob_front_8008DB20(1)));
  v2 = ob_front_8008DB20(2);
  v3 = r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12))))) + (uint32)(48))));
  w_u32(0x8009bb90u, (sint32)(v2));
  if (v3)
    ob_front_a_callback(v3,2u,a1,r_u32(a1+12u));
  w_u32(0x8009bb94u, (sint32)(0x8009BB98u));
  return ob_front_80094790(3000);
}


uint32 ob_front_8008E780(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8008e780u, "FRONT.BIN");
  sint32 result;
  result = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12))));
  if ((result == a2))
  {
    sub_80021460((sint32)(0u - (uint32)(2147044656)), 0, 0, 32, 0x40u, 0x31u, 0x8fu, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044652)), 0, 0, 32, 0x40u, 0x51u, 0x86u, 0x0u);
    return ob_front_8008E65C(130, (sint32)(0x8008d090u), (sint32)(0x8008d098u));
  }
  return result;
}


uint32 ob_front_80096E3C(uint32 a1)
{
    FUNCTION_MARKER(0x80096e3cu, "FRONT.BIN");
    /* TODO: Bind external adapter for sub_8001CDE4 */
    /* TODO: Bind external adapter for sub_80013524 */
    /* TODO: Bind external adapter for sub_8001CE24 */
    /* TODO: Bind external adapter for sub_8001CEBC */
    /* TODO: Bind external adapter for sub_8001D818 */
    uint32 local_objects = ob_draft_scratch_acquire(376u);
  ;
  ob_draft_unresolved_call(0x8001cde4u, 0u);
  if (ob_draft_unresolved_call(0x80013524u, 4u, a1, (sint32)(0u - (uint32)(2147042100)), 1, (sint32)r_u32(0x8006BCC0)))
  {
    if ((ob_front_80097210(a1) == (sint32)(0u - (uint32)(1))))
    {
      ob_draft_unresolved_call(0x8001ce24u, 0u);
      { uint32 draft_return = (sint32)(0u - (uint32)(1)); ob_draft_scratch_release(local_objects);  return draft_return; }
    }
    else
    {
      ob_draft_unresolved_call(0x8001cebcu, 1u, (local_objects + 0u));
      ob_draft_unresolved_call(0x8001d818u, 1u, (local_objects + 0u));
      ob_draft_unresolved_call(0x8001ce24u, 0u);
      { uint32 draft_return = 0; ob_draft_scratch_release(local_objects);  return draft_return; }
    }
  }
  else
  {
    ob_draft_unresolved_call(0x8001ce24u, 0u);
    { uint32 draft_return = 1; ob_draft_scratch_release(local_objects);  return draft_return; }
  }
}


uint32 ob_front_800981C8(uint32 a1)
{
    FUNCTION_MARKER(0x800981c8u, "FRONT.BIN");
    /* TODO: Bind external adapter for sub_800263B4 */
    uint32 local_objects = ob_draft_scratch_acquire(8u);
  sint32 v2;
  sint32 v3;
  sint32 v4;
  ;
  v2 = r_u32((uint32)(((uint32)(r_u32((uint32)(a1))) + (uint32)(8))));
  if (v2)
  {
    w_u32(((local_objects + 0u) + (0) * 4u), r_u32((uint32)(((uint32)(r_u32((uint32)(a1))) + (uint32)(8)))));
    w_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)(a1))) + (uint32)(8))))) + (uint32)(16))))) + (uint32)(20))), 0);
    if (r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(20)))))
    {
      do
      {
        v3 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(((local_objects + 0u) + (0) * 4u))) + (uint32)(20))));
        ob_front_80098168((local_objects + 0u));
        v4 = r_u32((uint32)((sint32)((uint32)(v3) + (uint32)(20))));
        w_u32(((local_objects + 0u) + (0) * 4u), v3);
      }
      while (v4);
    }
    ob_front_80098168((local_objects + 0u));
  }
  { uint32 draft_return = ob_draft_unresolved_call(0x800263b4u, 1u, a1); ob_draft_scratch_release(local_objects);  return draft_return; }
}


void ob_front_800988BC(uint32 a1)
{
    FUNCTION_MARKER(0x800988bcu, "FRONT.BIN");
    /* TODO: Bind external adapter for sub_800540F8 */
  sint32 v2;
  uint32 v3;
  uint32 v4;
  v2 = 0;
  if (((sint32)(a1) > (sint32)(0)))
  {
    v3 = 0x8009cf40u;
    v4 = 0x8009D010u;
    do
    {
      if (ob_draft_unresolved_call(0x800540f8u, 1u, (sint8)r_u8((uint32)((sint32)((uint32)(v2) - (uint32)(2147040709))))))
      {
        ob_front_8009898C(v2, a1, 0, (sint32)r_u32(v3), (sint32)r_u32(v4));
        if (!((sint32)r_u32(v3)))
          w_u32(v3, 1);
      }
      else
      {
        ob_front_8009898C(v2, a1, 1, (sint32)r_u32(v3), (sint32)r_u32(v4));
        w_u32(v3, 0);
      }
      ((v3 += 4u));
      ++v2;
      ((v4 += 4u));
    }
    while (((sint32)(v2) < (sint32)(a1)));
  }
}


uint32 ob_front_80093150(void)
{
    FUNCTION_MARKER(0x80093150u, "FRONT.BIN");
  uint32 v0;
  sint32 result;
  v0 = (ob_front_800947EC(12) != 0);
  result = 2;
  if (!v0)
  {
    if (ob_front_800947EC(5))
    {
      sub_80011984((sint32)(0u - (uint32)(2147046368)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
      return 5;
    }
    else
      if (ob_front_800947EC(7))
    {
      sub_80011984((sint32)(0u - (uint32)(2147046368)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
      return 4;
    }
    else
    {
      v0 = (ob_front_800947EC(4) != 0);
      result = 6;
      if (!v0)
      {
        v0 = (ob_front_800947EC(6) != 0);
        result = 7;
        if (!v0)
          return ((ob_front_800947EC(14) != 0)) ? (0xA) : (0);
      }
    }
  }
  return result;
}


uint32 ob_front_80094A88(uint32 unused_a0, uint32 a2)
{
    FUNCTION_MARKER(0x80094a88u, "FRONT.BIN");
  sint32 result;
  sint32 v4;
  result = r_u32((uint32)((sint32)((uint32)((sint32)r_u32((0x8009cf20u + (r_u32(a2)) * 4u))) + (uint32)(124))));
  if (!result)
  {
    v4 = r_u32((a2 + (2) * 4u));
    if ((v4 >= (sint32)r_u32((a2 + (3) * 4u))))
      w_u32((a2 + (2) * 4u), 0);
    else
      w_u32((a2 + (2) * 4u), (sint32)((uint32)(v4) + (uint32)(1)));
    sub_80011984((sint32)(0u - (uint32)(2147046396)), 128, (sint8)r_u8((uint32)((sint32)((uint32)((sint32)r_u32((0x8009cf20u + (r_u32(a2)) * 4u))) + (uint32)(112)))), 15, 0x100u, 0x0u, 0x0u);
    w_u32((uint32)((sint32)((uint32)((sint32)r_u32((0x8009cf20u + (r_u32(a2)) * 4u))) + (uint32)(124))), 1);
    result = r_u32((a2 + (2) * 4u));
    w_u8((uint32)((sint32)((uint32)((sint32)r_u32((0x8009cf20u + (r_u32(a2)) * 4u))) + (uint32)(121))), result);
  }
  return result;
}


uint32 ob_front_8009341C(void)
{
    FUNCTION_MARKER(0x8009341cu, "FRONT.BIN");
  uint32 v0;
  sint32 result;
  v0 = (ob_front_800947EC(21) != 0);
  result = 6;
  if (!v0)
  {
    v0 = (ob_front_800947EC(23) != 0);
    result = 7;
    if (!v0)
    {
      if (ob_front_800947EC(20))
      {
        sub_80011984((sint32)(0u - (uint32)(2147046360)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
        return 4;
      }
      else
        if (ob_front_800947EC(22))
      {
        sub_80011984((sint32)(0u - (uint32)(2147046360)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
        return 5;
      }
      else
        if (ob_front_800947EC(30))
      {
        sub_80011984((sint32)(0u - (uint32)(2147046352)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
        return 10;
      }
      else
      {
        return 0;
      }
    }
  }
  return result;
}


uint32 ob_front_8009331C(void)
{
    FUNCTION_MARKER(0x8009331cu, "FRONT.BIN");
  uint32 v0;
  sint32 result;
  v0 = (ob_front_800947EC(12) != 0);
  result = 2;
  if (!v0)
  {
    v0 = (ob_front_800947EC(5) != 0);
    result = 6;
    if (!v0)
    {
      v0 = (ob_front_800947EC(7) != 0);
      result = 7;
      if (!v0)
      {
        if (ob_front_800947EC(4))
        {
          sub_80011984((sint32)(0u - (uint32)(2147046364)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
          return 4;
        }
        else
          if (ob_front_800947EC(6))
        {
          sub_80011984((sint32)(0u - (uint32)(2147046364)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
          return 5;
        }
        else
          if (ob_front_800947EC(14))
        {
          sub_80011984((sint32)(0u - (uint32)(2147046356)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
          return 10;
        }
        else
        {
          return 0;
        }
      }
    }
  }
  return result;
}


uint32 ob_front_8008EDD0(uint32 a1)
{
    FUNCTION_MARKER(0x8008edd0u, "FRONT.BIN");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
  uint32 v2;
  sint32 result;
  sub_80021B20((sint32)(0u - (uint32)(2147046748)));
  w_u32(0x80073518u, 0x80021C24u);
  v2 = r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12))))) + (uint32)(48))));
  if (v2)
    ob_front_a_callback(v2, 2u, a1, r_u32(a1 + 12u));
  w_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))))) + (uint32)(8))), r_u8(0x8006C22C));
  w_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))))) + (uint32)(20))))) + (uint32)(20))))) + (uint32)(8))), (r_u8(0x8006C22D) / 0x1Au));
  w_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))))) + (uint32)(20))))) + (uint32)(20))))) + (uint32)(20))))) + (uint32)(8))), (r_u8(0x8006C22E) / 0x1Au));
  result = r_u8(0x8006C22F);
  w_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))))) + (uint32)(20))))) + (uint32)(20))))) + (uint32)(20))))) + (uint32)(20))))) + (uint32)(8))), r_u8(0x8006C22F));
  return result;
}


uint32 ob_front_800999D8(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x800999d8u, "FRONT.BIN");
  sint32 v6;
  uint32 v7;
  uint32 v8;
  uint8 v9;
  uint8 v10;
  uint32 result;
  v6 = 0;
  v7 = ((0x8009cf58u + ((sint32)((uint32)((sint32)((uint32)(9) * (uint32)(a1))) + (uint32)(a2))) * 4u));
  v8 = ((0x8009cf58u + ((sint32)((uint32)(9) * (uint32)(a1))) * 4u));
  do
  {
    if (((sint32)r_u32(v8) == a3))
    {
      v9 = ob_front_80092D30(v6);
      w_u32(v8, (sint32)r_u32(v7));
      w_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(v9))) + (uint32)(r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(a1))) - (uint32)(2147066704))))))), (sint32)r_u32(v7));
    }
    ++v6;
    ((v8 += 4u));
  }
  while (((sint32)(v6) < (sint32)(9)));
  v10 = ob_front_80092D30(a2);
  w_u32((0x8009cf58u + ((sint32)((uint32)((sint32)((uint32)(9) * (uint32)(a1))) + (uint32)(a2))) * 4u), a3);
  result = (uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(v10))) + (uint32)(r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(a1))) - (uint32)(2147066704)))))));
  w_u32(result, a3);
  return result;
}


uint32 ob_front_80096CEC(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80096cecu, "FRONT.BIN");
    /* TODO: Bind external adapter for sub_80012294 */
    /* TODO: Bind external adapter for sub_80013794 */
    /* TODO: Bind external adapter for sub_80063BA4 */
    /* TODO: Bind external adapter for sub_8001221C */
  sint32 result;
  sint32 v4;
  result = (sint32)(0u - (uint32)(1));
  w_u32((0x8009cf00u + (0) * 4u), 0);
  w_u32(0x8009cf04u, 0);
  w_u32(0x8009cf08u, 0);
  w_u32(0x8009cf0cu, 0);
  if ((a1 != (sint32)(0u - (uint32)(1))))
  {
    result = 3;
    if ((!a2 || (a2 == 3)))
    {
      ob_draft_unresolved_call(0x80012294u, 0u);
      do
        v4 = ob_draft_unresolved_call(0x80013794u, 1u, a1);
      while (!ob_draft_unresolved_call(0x80063ba4u, 1u, v4));
      ob_draft_unresolved_call(0x8001221cu, 0u);
      sub_80012BE8(a1);
      if ((sub_8001D048(a1) != (sint32)(0u - (uint32)(1))))
      {
        w_u32((0x8009cf00u + (0) * 4u), 1);
        w_u32(0x8009cf08u, 1);
      }
      result = (sint32)((uint32)(16) * (uint32)(a1));
      if ((a1 != (sint32)(0u - (uint32)(1))))
      {
        if ((((sint32)((sint32)r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(552) * (uint32)(a1))) - (uint32)(2146919120))))) < (sint32)(15)) || (sub_8001D048(a1) != (sint32)(0u - (uint32)(1)))))
          w_u32(0x8009cf04u, 1);
        result = 1;
        w_u32(0x8009cf0cu, (r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(552) * (uint32)(a1))) - (uint32)(2146919120)))) > 0));
      }
    }
  }
  return result;
}


uint32 ob_front_8008F684(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8008f684u, "FRONT.BIN");
  sint32 result;
  result = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12))));
  if ((result == a2))
  {
    sub_80021460((sint32)(0u - (uint32)(2147044588)), 0, 0, 32, 0x40u, 0x35u, 0x16u, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044584)), 0, 0, 32, 0x40u, 0x55u, 0x16u, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044580)), 0, 0, 32, 0x40u, 0x75u, 0x16u, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044576)), 0, 0, 32, 0x40u, 0x35u, 0x56u, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044572)), 0, 0, 32, 0x40u, 0x55u, 0x56u, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044568)), 0, 0, 32, 0x10u, 0x75u, 0x56u, 0x0u);
    return ob_front_8008E65C(20, (sint32)(0x8008d0f4u), 0);
  }
  return result;
}


uint32 ob_front_80096EDC(uint32 a1)
{
    FUNCTION_MARKER(0x80096edcu, "FRONT.BIN");
    /* TODO: Bind external adapter for sub_8001D5F0 */
    /* TODO: Bind external adapter for sub_8001CDE4 */
    /* TODO: Bind external adapter for sub_80013524 */
    /* TODO: Bind external adapter for sub_800130C4 */
    /* TODO: Bind external adapter for sub_8001CE4C */
    /* TODO: Bind external adapter for sub_8001345C */
    /* TODO: Bind external adapter for sub_8001CE24 */
    /* TODO: Bind external adapter for sub_80013360 */
    uint32 local_objects = ob_draft_scratch_acquire(376u);
  sint32 v2;
  sint32 v3;
  ;
  v2 = sub_8001D048(a1);
  if ((v2 != (sint32)(0u - (uint32)(1))))
  {
    ob_draft_unresolved_call(0x8001d5f0u, 2u, (local_objects + 0u), (sint32)r_u32(0x8006C231));
    ob_draft_unresolved_call(0x8001cde4u, 0u);
    v3 = (sint32)((uint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(552) * (uint32)(a1))) - (uint32)(2146919116))) + (uint32)((sint32)((uint32)(36) * (uint32)(v2))))) + (uint32)(12));
    if (ob_draft_unresolved_call(0x80013524u, 4u, a1, v3, 1, (sint32)r_u32(0x8006BCC0)))
    {
      ob_draft_unresolved_call(0x800130c4u, 4u, (sint32)r_u32(0x8006BCC0), 0x8008d340u, 1, 1);
      ob_draft_unresolved_call(0x8001ce4cu, 2u, (local_objects + 0u), (sint32)r_u32(0x8006C231));
      if (ob_draft_unresolved_call(0x8001345cu, 4u, a1, v3, 1, (sint32)r_u32(0x8006BCC0)))
        goto LABEL_7;
    }
    LABEL_6:
    ob_draft_unresolved_call(0x8001ce24u, 0u);

    { uint32 draft_return = 1; ob_draft_scratch_release(local_objects);  return draft_return; }
  }
  ob_draft_unresolved_call(0x8001d5f0u, 2u, (local_objects + 0u), (sint32)r_u32(0x8006C231));
  ob_draft_unresolved_call(0x8001cde4u, 0u);
  ob_draft_unresolved_call(0x800130c4u, 4u, (sint32)r_u32(0x8006BCC0), 0x8008d340u, 1, 1);
  ob_draft_unresolved_call(0x8001ce4cu, 2u, (local_objects + 0u), (sint32)r_u32(0x8006C231));
  if (!ob_draft_unresolved_call(0x80013360u, 4u, a1, (sint32)(0u - (uint32)(2147042100)), 1, (sint32)r_u32(0x8006BCC0)))
    goto LABEL_6;
  LABEL_7:
  ob_draft_unresolved_call(0x8001ce24u, 0u);

  { uint32 draft_return = 0; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 ob_front_8008E998(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8008e998u, "FRONT.BIN");
  sint32 result;
  result = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12))));
  if ((result == a2))
  {
    sub_80021460((sint32)(0u - (uint32)(2147044688)), 0, 0, 32, 0x40u, 0xe9u, 0x94u, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044684)), 0, 0, 32, 0x40u, 0x109u, 0x94u, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044680)), 0, 0, 32, 0x40u, 0x129u, 0x94u, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044676)), 0, 0, 32, 0x40u, 0x117u, 0x54u, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044672)), 0, 0, 32, 0x40u, 0x137u, 0x54u, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044668)), 0, 0, 16, 0x40u, 0x157u, 0x45u, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044664)), 0, 0, 32, 0x10u, 0x126u, 0x44u, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044660)), 0, 0, 16, 0x10u, 0x146u, 0x44u, 0x0u);
    return ob_front_8008E65C(130, (sint32)(0x8008d0acu), (sint32)(0x8008d0b4u));
  }
  return result;
}


uint32 ob_front_8009B540(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8009b540u, "FRONT.BIN");
    /* TODO: Bind external adapter for sub_8001B008 */
    /* TODO: Bind external adapter for sub_80044130 */
    /* TODO: Bind external adapter for sub_80029E80 */
    uint32 local_objects = ob_draft_scratch_acquire(28u);
  sint32 v4;
  sint32 v5;
  uint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v10;
  sint16 v11;
  sint32 v12;
  sint32 v13;
  uint32 v14;
  sint32 v15;
  sint32 v16;
  ;
  ;
  w_u32(local_objects + 24u, 0);
  sub_800262CC((local_objects + 24u), 164);
  if (!(sint32)r_u32(local_objects + 24u))
    { uint32 draft_return = 0; ob_draft_scratch_release(local_objects);  return draft_return; }
  v4 = sub_800435AC(0, 0);
  w_u32((uint32)((sint32)r_u32(local_objects + 24u)), v4);
  if (!v4)
    { uint32 draft_return = 0; ob_draft_scratch_release(local_objects);  return draft_return; }
  v5 = sub_80044E5C(v4, (sint32)(0u - (uint32)(2147010976)), 0);
  v6 = (uint32)((sint32)r_u32(local_objects + 24u));
  w_u32((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 24u)) + (uint32)(48))), v5);
  if (!v5)
    { uint32 draft_return = 0; ob_draft_scratch_release(local_objects);  return draft_return; }
  v7 = sub_80043E3C(r_u32(v6), (sint32)(0u - (uint32)(2147011016)));
  v8 = (sint32)r_u32(local_objects + 24u);
  w_u32((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 24u)) + (uint32)(52))), v7);
  if (!v7)
    { uint32 draft_return = 0; ob_draft_scratch_release(local_objects);  return draft_return; }
  w_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(v8) + (uint32)(48))))) + (uint32)(8))), 268435457);
  w_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(v8) + (uint32)(52))))) + (uint32)(48))), 268435457);
  w_u8((uint32)((sint32)((uint32)(v8) + (uint32)(112))), (sint32)((uint32)(6) * (uint32)(a1)));
  w_u8((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 24u)) + (uint32)(121))), a2);
  v10 = (sint32)r_u32(local_objects + 24u);
  w_u32((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 24u)) + (uint32)(140))), (sint32)((uint32)((sint32)((uint32)(3000) * (uint32)(a1))) - (uint32)(7500)));
  w_u32((uint32)((sint32)((uint32)(v10) + (uint32)(124))), 0);
  w_u32((uint32)((sint32)((uint32)(v10) + (uint32)(144))), 7000);
  v11 = ob_draft_unresolved_call(0x8001b008u, 0u);
  v12 = (sint32)r_u32(local_objects + 24u);
  v13 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 24u)) + (uint32)(144))));
  w_u32((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 24u)) + (uint32)(148))), 12000);
  w_u32((uint32)((sint32)((uint32)(v12) + (uint32)(144))), (sint32)((uint32)((sint32)((uint32)(v13) + (uint32)(1000))) - (uint32)((v11 & 0x7D0))));
  if (((a2 & 1) != 0))
    w_u32((uint32)((sint32)((uint32)(v12) + (uint32)(128))), (sint32)(0u - (uint32)(32768)));
  else
    w_u32((uint32)((sint32)((uint32)(v12) + (uint32)(128))), 0);
  v14 = (uint32)((sint32)r_u32(local_objects + 24u));
  v15 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 24u)) + (uint32)(48))));
  v16 = (sint32)((uint32)((sint32)r_u32(local_objects + 24u)) + (uint32)(140));
  w_u32((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 24u)) + (uint32)(132))), 0);
  w_u32((v14 + (34) * 4u), 0);
  w_u32((v14 + (38) * 4u), 0);
  w_u32((v14 + (39) * 4u), 0);
  w_u32((v14 + (40) * 4u), 0);
  w_u32((v14 + (29) * 4u), 40);
  sub_800458B4(v15, v16, 0);
  ob_draft_unresolved_call(0x80044130u, 1u, r_u32((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 24u)) + (uint32)(52)))));
  ob_draft_unresolved_call(0x80029e80u, 2u, (sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 24u)) + (uint32)(128)))), (local_objects + 0u));
  sub_80045848(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 24u)) + (uint32)(48)))), (local_objects + 0u));
  ob_front_8009B704((sint32)r_u32(local_objects + 24u), a2);
  { uint32 draft_return = (sint32)r_u32(local_objects + 24u); ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 ob_front_8008DB20(uint32 a1)
{
    FUNCTION_MARKER(0x8008db20u, "FRONT.BIN");
    /* TODO: Bind external adapter for sub_800257A0 */
    /* TODO: Bind external adapter for sub_80044130 */
    uint32 local_objects = ob_draft_scratch_acquire(20u);
  sint32 v1;
  sint32 v2;
  uint32 v4;
  uint32 result;
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
  ;
  ;
  w_u32(local_objects + 16u, 0);
  sub_800262CC((local_objects + 16u), 144);
  v4 = r_u32(local_objects + 16u);
  if (!r_u32(local_objects + 16u))
    { uint32 draft_return = 0; ob_draft_scratch_release(local_objects);  return draft_return; }
  w_u32((r_u32(local_objects + 16u) + (29) * 4u), a1);
  v6 = (sint32)r_u32((v4 + (29) * 4u));
  w_u32((v4 + (30) * 4u), 0);
  w_u32((v4 + (32) * 4u), 0);
  w_u32((v4 + (33) * 4u), 0);
  w_u32((v4 + (34) * 4u), 0);
  w_u32((v4 + (35) * 4u), 0);
  if ((v6 == 1))
  {
    v1 = (sint32)(0u - (uint32)(2147046712));
    v2 = (sint32)(0u - (uint32)(2147046708));
    v7 = 15;
    w_u32(((local_objects + 0u) + (0) * 4u), 0);
  }
  else
    if (v6)
  {
    if ((v6 != 2))
      goto LABEL_11;
    v1 = (sint32)(0u - (uint32)(2147046704));
    v2 = (sint32)(0u - (uint32)(2147046700));
    w_u32(((local_objects + 0u) + (0) * 4u), 2500);
    v7 = 25;
  }
  else
  {
    v1 = (sint32)(0u - (uint32)(2147046720));
    v2 = (sint32)(0u - (uint32)(2147046716));
    w_u32(((local_objects + 0u) + (0) * 4u), (sint32)(0u - (uint32)(2500)));
    v7 = 5;
  }
  w_u32((v4 + (31) * 4u), v7);
  LABEL_11:
  w_u32(((local_objects + 0u) + (1) * 4u), (sint32)(0u - (uint32)(1400)));

  w_u32(((local_objects + 0u) + (2) * 4u), 2500);
  v8 = sub_800435AC(0, 0);
  w_u32(r_u32(local_objects + 16u), v8);
  v9 = v8;
  if (((r_u32((uint32)(v1)) & 3) != 0))
  {
    v10 = sub_800257CC(v1);
    v9 = v8;
  }
  else
  {
    (w_u16((uint32)(((uint32)(r_u32((uint32)(v1))) - (uint32)(6))), (r_u16((uint32)(((uint32)(r_u32((uint32)(v1))) - (uint32)(6)))) + 1u)), r_u16((uint32)(((uint32)(r_u32((uint32)(v1))) - (uint32)(6)))));
    v10 = r_u32((uint32)(v1));
  }
  v11 = sub_80044E5C(v9, v10, 0);
  w_u32((r_u32(local_objects + 16u) + (12) * 4u), v11);
  ob_draft_unresolved_call(0x800257a0u, 1u, v1);
  v12 = v8;
  if (((r_u32((uint32)(v2)) & 3) != 0))
  {
    v13 = sub_800257CC(v2);
    v12 = v8;
  }
  else
  {
    (w_u16((uint32)(((uint32)(r_u32((uint32)(v2))) - (uint32)(6))), (r_u16((uint32)(((uint32)(r_u32((uint32)(v2))) - (uint32)(6)))) + 1u)), r_u16((uint32)(((uint32)(r_u32((uint32)(v2))) - (uint32)(6)))));
    v13 = r_u32((uint32)(v2));
  }
  v14 = sub_80043E3C(v12, v13);
  w_u32((r_u32(local_objects + 16u) + (13) * 4u), v14);
  ob_draft_unresolved_call(0x800257a0u, 1u, v2);
  sub_800458B4((sint32)r_u32((r_u32(local_objects + 16u) + (12) * 4u)), (local_objects + 0u), 0);
  ob_draft_unresolved_call(0x80044130u, 1u, (sint32)r_u32((r_u32(local_objects + 16u) + (13) * 4u)));
  result = r_u32(local_objects + 16u);
  v15 = (sint32)r_u32((r_u32(local_objects + 16u) + (13) * 4u));
  w_u32((r_u32(local_objects + 16u) + (27) * 4u), r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(v15) + (uint32)(32))))) + (uint32)(52)))));
  w_u32((result + (28) * 4u), r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(v15) + (uint32)(32))))) + (uint32)(28)))));
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 ob_front_8009B94C(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8009b94cu, "FRONT.BIN");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Bind external adapter for sub_80029F58 */
    uint32 local_objects = ob_draft_scratch_acquire(24u);
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
  ;
  v5 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(124))));
  v6 = a2;
  if ((v5 == 1))
  {
    v7 = ((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(128))))) + (uint32)(2048));
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(128))), v7);
    if (((v7 & 0x7FFF) == 0))
      goto LABEL_8;
    v8 = (sint32)((uint32)(v7) + (uint32)((((sint32)(v7) < (sint32)(0))) ? (0x7FFF) : (0)));
  }
  else
  {
    if ((!v5 || (v5 != 2)))
      goto LABEL_15;
    v9 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(128))));
    v7 = (sint32)((uint32)(v9) - (uint32)(2048));
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(128))), (sint32)((uint32)(v9) - (uint32)(2048)));
    if ((((sint32)((uint32)(v9) - (uint32)(2048)) & 0x7FFF) == 0))
    {
      LABEL_8:
      w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(124))), 0);

      goto LABEL_15;
    }
    v8 = (sint32)((uint32)(v9) - (uint32)(2048));
    if (((sint32)(v7) < (sint32)(0)))
      v8 = (sint32)((uint32)(v9) + (uint32)(30719));
  }
  v10 = (sint32)((uint32)(v7) - (uint32)((sint32)((uint32)(((sint32)(v8) >> 15)) << (uint32)(15))));
  if (((sint32)(v10) < (sint32)(0)))
    v10 = (sint32)(0u - (uint32)(v10));
  if ((v10 == 0x4000))
    ob_front_8009B7A0(a1, r_u8((uint32)((sint32)((uint32)(a1) + (uint32)(121)))), a2);
  LABEL_15:
  v11 = ((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(144))))) + (uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(156))))));

  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(144))), v11);
  if (((sint32)(v11) >= (sint32)((sint32)(0u - (uint32)(3750)))))
  {
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(156))), ((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(156))))) - (uint32)(25)));
  }
  else
  {
    v12 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(116))));
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(144))), (sint32)(0u - (uint32)(3750)));
    if ((v12 == 80))
    {
      v13 = ((0u - (uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(156)))))) / 3);
      if (((sint32)(v13) > (sint32)(0)))
        sub_80011984((sint32)(0u - (uint32)(2147046412)), v13, (sint8)r_u8((uint32)((sint32)((uint32)(a1) + (uint32)(112)))), 15, 0x100u, 0x0u, 0x0u);
      w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(156))), 500);
    }
    else
    {
      v14 = (0u - (uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(156))))));
      w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(156))), v14);
      if (((sint32)(v14) >= (sint32)(26)))
      {
        if (((sint32)(((sint32)(v14) / (sint32)(3))) > (sint32)(0)))
          sub_80011984((sint32)(0u - (uint32)(2147046412)), ((sint32)(v14) / (sint32)(3)), (sint8)r_u8((uint32)((sint32)((uint32)(a1) + (uint32)(112)))), 15, 0x100u, 0x0u, 0x0u);
      }
    }
    v15 = ((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(156))))) * (uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(116))))));
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(156))), ((sint32)(v15) / (sint32)(100)));
    if (((sint32)(((sint32)(v15) / (sint32)(100))) < (sint32)(26)))
      w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(156))), 0);
  }
  ob_draft_unresolved_call(0x80029f58u, 4u, (sint16)r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(128)))), (local_objects + 0u), v6, 0);
  sub_80045848(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(48)))), (local_objects + 0u));
  sub_800458B4(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(48)))), (sint32)((uint32)(a1) + (uint32)(140)), 0);
  { uint32 draft_return = sub_800442F0(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(52)))), 0, 0); ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 ob_front_80093780(void)
{
    FUNCTION_MARKER(0x80093780u, "FRONT.BIN");
  if (ob_front_800947EC(20))
  {
    sub_80011984((sint32)(0u - (uint32)(2147046344)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
    return 20;
  }
  else
    if (ob_front_800947EC(22))
  {
    sub_80011984((sint32)(0u - (uint32)(2147046344)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
    return 22;
  }
  else
    if (ob_front_800947EC(26))
  {
    sub_80011984((sint32)(0u - (uint32)(2147046344)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
    return 26;
  }
  else
    if (ob_front_800947EC(24))
  {
    sub_80011984((sint32)(0u - (uint32)(2147046344)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
    return 24;
  }
  else
    if (ob_front_800947EC(28))
  {
    sub_80011984((sint32)(0u - (uint32)(2147046344)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
    return 28;
  }
  else
    if (ob_front_800947EC(30))
  {
    sub_80011984((sint32)(0u - (uint32)(2147046344)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
    return 30;
  }
  else
    if (ob_front_800947EC(31))
  {
    sub_80011984((sint32)(0u - (uint32)(2147046344)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
    return 31;
  }
  else
    if (ob_front_800947EC(29))
  {
    sub_80011984((sint32)(0u - (uint32)(2147046344)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
    return 29;
  }
  else
    if (ob_front_800947EC(27))
  {
    sub_80011984((sint32)(0u - (uint32)(2147046344)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
    return 27;
  }
  else
    if (ob_front_800947EC(25))
  {
    sub_80011984((sint32)(0u - (uint32)(2147046344)), 255, 15, 15, 0x100u, 0x0u, 0x0u);
    return 25;
  }
  else
  {
    return (sint32)(0u - (uint32)(1));
  }
}


uint32 ob_front_8009AB74(uint32 a1)
{
    FUNCTION_MARKER(0x8009ab74u, "FRONT.BIN");
    /* TODO: Bind external adapter for sub_80020A70 */
    /* TODO: Bind external adapter for sub_80064028 */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    uint32 local_objects = ob_draft_scratch_acquire(16u);
  sint32 v1;
  sint32 v2;
  sint32 v4;
  ;
  ob_draft_unresolved_call(0x80020a70u, 4u, 212, 36, 132, 176);
  ob_draft_unresolved_call(0x80064028u, 3u, (local_objects + 0u), 0x8008da14u, (sint32)((uint32)((sint32)r_u32(0x8006C247)) + (uint32)(1)));
  switch ((sint32)r_u32(0x8006C247))
  {
    case 0:
      v1 = (sint32)(0u - (uint32)(2147046272));
      v2 = (sint32)(0u - (uint32)(2147046268));
      break;

    case 1:
      v1 = (sint32)(0u - (uint32)(2147046264));
      v2 = (sint32)(0u - (uint32)(2147046260));
      break;

    case 2:
      v1 = (sint32)(0u - (uint32)(2147046256));
      v2 = (sint32)(0u - (uint32)(2147046252));
      break;

    case 3:
      v1 = (sint32)(0u - (uint32)(2147046248));
      v2 = (sint32)(0u - (uint32)(2147046244));
      break;

    case 4:
      v1 = (sint32)(0u - (uint32)(2147046240));
      v2 = (sint32)(0u - (uint32)(2147046236));
      break;

    case 5:
      v1 = (sint32)(0u - (uint32)(2147046232));
      v2 = (sint32)(0u - (uint32)(2147046228));
      break;

    case 6:
      v1 = (sint32)(0u - (uint32)(2147046224));
      v2 = (sint32)(0u - (uint32)(2147046220));
      break;

    case 7:
      v1 = (sint32)(0u - (uint32)(2147046216));
      v2 = (sint32)(0u - (uint32)(2147046212));
      break;

    case 8:
      v1 = (sint32)(0u - (uint32)(2147046208));
      v2 = (sint32)(0u - (uint32)(2147046204));
      break;

    case 9:
      v1 = (sint32)(0u - (uint32)(2147046200));
      v2 = (sint32)(0u - (uint32)(2147046196));
      break;

    default:
      v1 = ob_native_missing_value(0x8009AB74u, "Invalid arena sprite");
      v2 = v1;
      break;

  }

  if (a1)
  {
    sub_800215FC(v1, 0, 0, 64, 0x40u, 0xe6u, 0x32u, 0x2du, 0x28u, 0x16u, 0x0u);
    sub_800215FC(v2, 0, 0, 32, 0x40u, 0x126u, 0x32u, 0x2du, 0x28u, 0x16u, 0x0u);
  }
  else
  {
    sub_80021460(v1, 0, 0, 64, 0x40u, 0xe6u, 0x32u, 0x0u);
    sub_80021460(v2, 0, 0, 32, 0x40u, 0x126u, 0x32u, 0x0u);
  }
  v4 = (sint32)((uint32)(278) - (uint32)((ob_front_800946F0((local_objects + 0u)) / 2)));
  { uint32 draft_return = ob_front_80094488((local_objects + 0u), v4, 120, (a1) ? (45) : (91), (a1) ? (40) : (15), (a1) ? (22) : (8), 0); ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 ob_front_8008DD94(uint32 a1)
{
    FUNCTION_MARKER(0x8008dd94u, "FRONT.BIN");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Bind external adapter for sub_80029E80 */
    /* TODO: Bind external adapter for sub_8001B008 */
    /* TODO: Bind external adapter for sub_800440B8 */
    uint32 local_objects = ob_draft_scratch_acquire(24u);
  sint32 v2;
  sint32 v3;
  sint32 v4;
  uint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  sint8 v9;
  sint32 v10;
  sint32 v11;
  sint32 v12;
  ;
  switch (r_u32((a1 + (30) * 4u)))
  {
    case 1:
      v2 = ((uint32)(r_u32((a1 + (32) * 4u))) + (uint32)(2500));
      w_u32((a1 + (32) * 4u), v2);
      if (((sint32)(v2) >= (sint32)(19001)))
    {
      w_u32((a1 + (32) * 4u), 19000);
      w_u32((a1 + (30) * 4u), 2);
    }
      break;

    case 3:
      w_u32((a1 + (32) * 4u), ((uint32)(r_u32((a1 + (32) * 4u))) - (uint32)(r_u32((a1 + (35) * 4u)))));
      v3 = r_u32((a1 + (32) * 4u));
      w_u32((a1 + (35) * 4u), ((uint32)(r_u32((a1 + (35) * 4u))) + (uint32)(1000)));
      if (((sint32)(v3) <= (sint32)(0)))
    {
      w_u32((a1 + (32) * 4u), 0);
      w_u32((a1 + (30) * 4u), 4);
    }
      break;

    case 4:
      v4 = (sint32)r_u32(a1 + 140u) / 4;
      w_u32((a1 + (35) * 4u), v4);
      w_u32((a1 + (32) * 4u), v4);
      w_u32((a1 + (30) * 4u), 5);
      break;

    case 5:
      v5 = (r_s32(a1 + 140u) < 11);
      w_u32((a1 + (32) * 4u), 0);
      if (v5)
      w_u32((a1 + (30) * 4u), 0);
    else
      w_u32((a1 + (30) * 4u), 4);
      v6 = ((sint32)((sint32)((uint32)(255) * (uint32)(r_u32((a1 + (35) * 4u))))) / (sint32)(1812));
      if (((uint32)((sint32)((uint32)(v6) - (uint32)(1))) < 0xFF))
      sub_80011984((sint32)(0u - (uint32)(2147046408)), v6, r_u32((a1 + (31) * 4u)), 15, 0x100u, 0x0u, 0x0u);
      break;

    default:
      break;

  }

  ob_draft_unresolved_call(0x80029e80u, 2u, (sint16)r_u16(((uint32)(a1) + (64) * 2u)), (local_objects + 0u));
  sub_80045848(r_u32((a1 + (27) * 4u)), (local_objects + 0u));
  sub_80030700(0, 0, 0);
  sub_8003077C((sint32)(0u - (uint32)(2146908412)), 255, 2, 255, 0xffu, 0xffu);
  v7 = r_u32((a1 + (32) * 4u));
  v5 = ((sint32)(v7) <= (sint32)(0));
  v8 = ((sint32)(v7) < (sint32)(500));
  if (!v5)
  {
    v9 = ob_draft_unresolved_call(0x8001b008u, 0u);
    v10 = r_u32((a1 + (32) * 4u));
    v11 = (sint32)((uint32)((sint32)((uint32)(((sint32)(v10) / (sint32)(75))) - (uint32)(31))) + (uint32)((v9 & 0x3F)));
    if (((sint32)(v11) >= (sint32)(256)))
      v11 = 255;
    if (((sint32)(v11) < (sint32)(0)))
      v11 = 0;
    v12 = (sint32)((uint32)((sint32)((uint32)(((sint32)(v10) / (sint32)(160))) - (uint32)(15))) + (uint32)((v9 & 0x1F)));
    if (((sint32)((sint16)(v12)) < (sint32)(5)))
      v12 = 5;
    ob_draft_unresolved_call(0x800440b8u, 2u, r_u32((a1 + (28) * 4u)), (sint16)(v12));
    sub_8003077C((sint32)(0u - (uint32)(2146906232)), (sint16)(v11), 2, 255, 0xffu, 0x0u);
    v8 = (r_s32(a1 + 128u) < 500);
  }
  if (v8)
    w_u32((uint32)(((uint32)(r_u32((a1 + (28) * 4u))) + (uint32)(44))), (r_u32((uint32)(((uint32)(r_u32((a1 + (28) * 4u))) + (uint32)(44)))) == 0));
  sub_800442F0(r_u32((a1 + (13) * 4u)), 0, 3);
  if (((sint32)((sint32)(r_u32((a1 + (32) * 4u)))) < (sint32)(500)))
    w_u32((uint32)(((uint32)(r_u32((a1 + (28) * 4u))) + (uint32)(44))), (r_u32((uint32)(((uint32)(r_u32((a1 + (28) * 4u))) + (uint32)(44)))) == 0));
  { uint32 draft_return = sub_800423D8(); ob_draft_scratch_release(local_objects);  return draft_return; }
}


void ob_front_8009898C(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 selection)
{
    FUNCTION_MARKER(0x8009898cu, "FRONT.BIN");
    /* TODO: IDA supplied excess carriers to sub_80094288; frozen prototype governs the draft call */
  sint32 v9;
  sint32 v10;
  sint32 v12;
  sint32 result;
  sint32 v14;
  uint32 v15;
  sint32 v16;
  sint32 v17;
  sint32 v18;
  sint32 v19;
  sint32 v20;
  uint32 v21;
  uint32 v22;
  uint32 v23;
  v12 = (sint32)((uint32)(((sint32)((sint32)((uint32)(384) - (uint32)((sint32)((uint32)(56) * (uint32)(a2))))) >> 1)) + (uint32)((sint32)((uint32)(56) * (uint32)(a1))));
  if (a3)
  {
    sub_80021460((sint32)(0u - (uint32)(2147045800)), 0, 0, 32, 64, (sint32)((uint32)(v12) - (uint32)(6)), 36, (a3 != 0));
    sub_80021460((sint32)(0u - (uint32)(2147045796)), 0, 0, 32, 64, (sint32)((uint32)(v12) + (uint32)(26)), 36, (a3 != 0));
    ob_front_80094288((sint32)(0x8008d840u), 0, v12, 100, 0);
    ob_front_80094288((sint32)(0x8008d848u), 0, v12, 124, 0);
    if (a1)
      return;
    ob_front_80094288((sint32)(0x8008d850u), 0, v12, 148, 0);
  }
  else
  {
    if ((a4 == 2))
    {
      switch (a1)
      {
        case 0:
          v10 = (sint32)(0u - (uint32)(2147045812));
          v14 = (sint32)(0u - (uint32)(2147045816));
          break;

        case 1:
          v10 = (sint32)(0u - (uint32)(2147045828));
          v14 = (sint32)(0u - (uint32)(2147045832));
          break;

        case 2:
          v10 = (sint32)(0u - (uint32)(2147045820));
          v14 = (sint32)(0u - (uint32)(2147045824));
          break;

        case 3:
          v10 = (sint32)(0u - (uint32)(2147045804));
          v14 = (sint32)(0u - (uint32)(2147045808));
          break;

        case 4:
          v9 = (sint32)(0u - (uint32)(2147045840));
          v10 = (sint32)(0u - (uint32)(2147045836));
          v14 = v9;
          break;

        default:
        v14 = ob_native_missing_value(0x8009898Cu, "Invalid player index sprite carrier");

          break;

      }

      sub_80021460(v14, 0, 0, 32, 64, (sint32)((uint32)(v12) - (uint32)(6)), 36, 0);
      sub_80021460(v10, 0, 0, 32, 64, (sint32)((uint32)(v12) + (uint32)(26)), 36, 0);
      ob_front_80094288((sint32)(0x8008d858u), 1, v12, 100, 1);
      v15 = 0x8008d864u;
      v16 = v12;
      v17 = 172;
    }
    else
    {
      sub_80021460((sint32)(0u - (uint32)(2147045800)), 0, 0, 32, 64, (sint32)((uint32)(v12) - (uint32)(6)), 36, (a3 != 0));
      sub_80021460((sint32)(0u - (uint32)(2147045796)), 0, 0, 32, 64, (sint32)((uint32)(v12) + (uint32)(26)), 36, (a3 != 0));
      ob_front_80094288((sint32)(0x8008d840u), 1, v12, 100, (selection == 0));
      ob_front_80094288((sint32)(0x8008d848u), 1, v12, 124, (selection == 1));
      ob_front_80094030(8, (sint32)(0x8008d86cu), v12, 172);
      ob_front_80094030(4, (sint32)(0x8008d874u), v12, 188);
      result = (selection ^ 2);
      if (a1)
        return;
      ob_front_80094288((sint32)(0x8008d850u), 1, v12, 148, (result == 0));
      v15 = 0x8008d87cu;
      v16 = v12;
      v17 = 204;
    }
    ob_front_80094030(7, (sint32)(v15), v16, v17);
  }
  v18 = 0;
  if (!a1)
  {
    v19 = 0;
    v20 = 0;
    v21 = 0x8009D010u;
    v22 = 0x8009cf40u;
    do
    {
      if (((sint32)r_u32(v22) == 2))
      {
        ++v19;
        if (((sint32)r_u32(v21) == 1))
          v18 = 1;
      }
      ((v21 += 4u));
      ++v20;
      ((v22 += 4u));
    }
    while (((sint32)(v20) < (sint32)(5)));
    if (((sint32)(v19) < (sint32)(2)))
    {
      v23 = 0x8008d908u;
      if (!v19)
        v23 = 0x8008d8f0u;
    }
    else
      if (((sint32)r_u32((0x8009cf40u + (0) * 4u)) == 2))
    {
      v23 = 0x8008d8b0u;
      if (v18)
        v23 = 0x8008d884u;
    }
    else
    {
      v23 = 0x8008d8d8u;
    }
    ob_front_8009465C((uint32)(v23), 20, 128, 128, 128, 0);
  }
  return;
}


uint32 ob_front_8009AE68(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8009ae68u, "FRONT.BIN");
    /* TODO: Bind external adapter for sub_80020A70 */
    /* TODO: Bind external adapter for sub_80064028 */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    uint32 local_objects = ob_draft_scratch_acquire(24u);
    uint32 literal_0 = ob_draft_scratch_acquire(3u);
    w_u8(literal_0 + 0u, 37u);
    w_u8(literal_0 + 1u, 100u);
    w_u8(literal_0 + 2u, 0u);
  sint32 v2;
  sint32 v3;
  sint32 v6;
  sint32 v7;
  uint32 v8;
  sint32 v9;
  uint32 v10;
  sint32 v11;
  sint32 v12;
  sint32 v13;
  ;
  ob_draft_unresolved_call(0x80020a70u, 4u, 212, 36, 132, 176);
  if ((a2 || a1))
  {
    switch ((sint32)r_u32(0x8009cf38u))
    {
      case 0:
        v7 = (sint32)(0u - (uint32)(2147045928));
        v3 = (sint32)(0u - (uint32)(2147045924));
        v8 = 0x8008da48u;
        goto LABEL_12;

      case 1:
        v7 = (sint32)(0u - (uint32)(2147045960));
        v3 = (sint32)(0u - (uint32)(2147045956));
        v8 = 0x8008da58u;
        goto LABEL_12;

      case 2:
        v7 = (sint32)(0u - (uint32)(2147045944));
        v3 = (sint32)(0u - (uint32)(2147045940));
        v8 = 0x8008da64u;
        goto LABEL_12;

      case 3:
        v7 = (sint32)(0u - (uint32)(2147045864));
        v3 = (sint32)(0u - (uint32)(2147045860));
        v8 = 0x8008da74u;
        goto LABEL_12;

      case 4:
        v7 = (sint32)(0u - (uint32)(2147045848));
        v3 = (sint32)(0u - (uint32)(2147045844));
        v8 = 0x8008da7cu;
        goto LABEL_12;

      case 5:
        v7 = (sint32)(0u - (uint32)(2147045880));
        v3 = (sint32)(0u - (uint32)(2147045876));
        v8 = 0x8008da84u;
        goto LABEL_12;

      case 6:
        v7 = (sint32)(0u - (uint32)(2147045896));
        v3 = (sint32)(0u - (uint32)(2147045892));
        v8 = 0x8008da90u;
        goto LABEL_12;

      case 7:
        v7 = (sint32)(0u - (uint32)(2147045912));
        v3 = (sint32)(0u - (uint32)(2147045908));
        v8 = 0x8008da9cu;
        LABEL_12:
      ob_draft_unresolved_call(0x80064028u, 2u, (local_objects + 0u), v8);

        v6 = v7;
        break;

      default:
        v6 = ob_native_missing_value(0x8009AE68u, "Invalid weapon sprite");
        v2 = v6;
        v3 = v6;
        break;

    }

    sub_80021460(v6, 0, 0, 32, 0x40u, 0xf6u, 0x32u, 0x0u);
    sub_80021460(v3, 0, 0, 32, 0x40u, 0x116u, 0x32u, 0x0u);
    v9 = (sint32)((uint32)(278) - (uint32)((ob_front_800946F0((local_objects + 0u)) / 2)));
  }
  else
  {
    switch ((sint32)r_u32(0x8009cf38u))
    {
      case 0:
        v2 = (sint32)(0u - (uint32)(2147045936));
        v3 = (sint32)(0u - (uint32)(2147045932));
        v10 = 0x8008da48u;
        goto LABEL_23;

      case 1:
        v2 = (sint32)(0u - (uint32)(2147045968));
        v3 = (sint32)(0u - (uint32)(2147045964));
        v10 = 0x8008da58u;
        goto LABEL_23;

      case 2:
        v2 = (sint32)(0u - (uint32)(2147045952));
        v3 = (sint32)(0u - (uint32)(2147045948));
        v10 = 0x8008da64u;
        goto LABEL_23;

      case 3:
        v2 = (sint32)(0u - (uint32)(2147045872));
        v3 = (sint32)(0u - (uint32)(2147045868));
        v10 = 0x8008da74u;
        goto LABEL_23;

      case 4:
        v2 = (sint32)(0u - (uint32)(2147045856));
        v3 = (sint32)(0u - (uint32)(2147045852));
        v10 = 0x8008da7cu;
        goto LABEL_23;

      case 5:
        v2 = (sint32)(0u - (uint32)(2147045888));
        v3 = (sint32)(0u - (uint32)(2147045884));
        v10 = 0x8008da84u;
        goto LABEL_23;

      case 6:
        v2 = (sint32)(0u - (uint32)(2147045904));
        v3 = (sint32)(0u - (uint32)(2147045900));
        v10 = 0x8008da90u;
        goto LABEL_23;

      case 7:
        v2 = (sint32)(0u - (uint32)(2147045920));
        v3 = (sint32)(0u - (uint32)(2147045916));
        v10 = 0x8008da9cu;
        LABEL_23:
      ob_draft_unresolved_call(0x80064028u, 2u, (local_objects + 0u), v10);

        break;

      default:
        v6 = ob_native_missing_value(0x8009AE68u, "Invalid weapon sprite");
        v2 = v6;
        v3 = v6;
        break;

    }

    sub_80021460(v2, 0, 0, 32, 0x40u, 0xf6u, 0x32u, 0x0u);
    sub_80021460(v3, 0, 0, 32, 0x40u, 0x116u, 0x32u, 0x0u);
    v9 = (sint32)((uint32)(278) - (uint32)((ob_front_800946F0((local_objects + 0u)) / 2)));
  }
  ob_front_80094488((local_objects + 0u), v9, 120, ((a2 || a1)) ? (45) : (91), ((a2 || a1)) ? (40) : (15), ((a2 || a1)) ? (22) : (8), 0);
  if (((a2 == 1) && !a1))
  {
    ob_front_80094488((uint32)(0x8008daacu), 222, 150, (((a2 == 1) && !a1)) ? (91) : (45), (((a2 == 1) && !a1)) ? (15) : (40), (((a2 == 1) && !a1)) ? (8) : (22), 0);
    if (r_u8((uint32)((sint32)((uint32)((sint32)r_u32(0x8009cf38u)) - (uint32)(2147040684)))))
    {
      LABEL_31:
      ob_draft_unresolved_call(0x80064028u, 3u, (local_objects + 0u), literal_0, (sint8)r_u8((uint32)((sint32)((uint32)((sint32)r_u32(0x8009cf38u)) - (uint32)(2147040684)))));

      goto LABEL_32;
    }
  }
  else
  {
    ob_front_80094488((uint32)(0x8008daacu), 222, 150, (((a2 == 1) && !a1)) ? (91) : (45), (((a2 == 1) && !a1)) ? (15) : (40), (((a2 == 1) && !a1)) ? (8) : (22), 0);
    if (r_u8((uint32)((sint32)((uint32)((sint32)r_u32(0x8009cf38u)) - (uint32)(2147040684)))))
      goto LABEL_31;
  }
  ob_draft_unresolved_call(0x80064028u, 2u, (local_objects + 0u), 0x8008d9dcu);
  LABEL_32:
  v11 = (sint32)((uint32)(334) - (uint32)(ob_front_800946F0((local_objects + 0u))));

  ob_front_80094488((local_objects + 0u), v11, 150, (((a2 == 1) && !a1)) ? (91) : (45), (((a2 == 1) && !a1)) ? (15) : (40), (((a2 == 1) && !a1)) ? (8) : (22), 0);
  ob_front_80094488((uint32)(0x8008dab4u), 222, 180, (((a2 == 2) && !a1)) ? (91) : (45), (((a2 == 2) && !a1)) ? (15) : (40), (((a2 == 2) && !a1)) ? (8) : (22), 0);
  v12 = ob_front_8009B4E4((sint32)r_u32(0x8009cf38u));
  ob_draft_unresolved_call(0x80064028u, 3u, (local_objects + 0u), literal_0, (sint16)r_u16((uint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)(v12))) - (uint32)(2147040694)))));
  v13 = (sint32)((uint32)(334) - (uint32)(ob_front_800946F0((local_objects + 0u))));
  { uint32 draft_return = ob_front_80094488((local_objects + 0u), v13, 180, (((a2 == 2) && !a1)) ? (91) : (45), (((a2 == 2) && !a1)) ? (15) : (40), (((a2 == 2) && !a1)) ? (8) : (22), 0); ob_draft_scratch_release(local_objects); ob_draft_scratch_release(literal_0);  return draft_return; }
}


uint32 ob_front_80091274(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80091274u, "FRONT.BIN");
  sint32 result;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  result = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12))));
  if ((result == a2))
  {
    sub_80021460((sint32)(0u - (uint32)(2147044416)), 0, 0, 32, 0x40u, 0x103u, 0x6au, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044412)), 0, 0, 32, 0x40u, 0xefu, 0xaau, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044408)), 0, 0, 32, 0x40u, 0x10fu, 0xaau, 0x0u);
    switch (r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(8)))))
    {
      case 0:
        v4 = (sint32)(0u - (uint32)(2147044472));
        v5 = 32;
        goto LABEL_13;

      case 1:
        v4 = (sint32)(0u - (uint32)(2147044468));
        v5 = 32;
        goto LABEL_13;

      case 2:
        v4 = (sint32)(0u - (uint32)(2147044464));
        v5 = 32;
        goto LABEL_13;

      case 3:
        v4 = (sint32)(0u - (uint32)(2147044460));
        v5 = 32;
        goto LABEL_13;

      case 4:
        sub_80021460((sint32)(0u - (uint32)(2147044456)), 0, 0, 32, 0x40u, 0x107u, 0x6au, 0x0u);
        v4 = (sint32)(0u - (uint32)(2147044452));
        v5 = 32;
        goto LABEL_13;

      case 5:
        v4 = (sint32)(0u - (uint32)(2147044448));
        v5 = 32;
        goto LABEL_13;

      case 6:
        v4 = (sint32)(0u - (uint32)(2147044444));
        v5 = 32;
        goto LABEL_13;

      case 7:
        sub_80021460((sint32)(0u - (uint32)(2147044440)), 0, 0, 32, 0x40u, 0x10au, 0x6eu, 0x0u);
        v4 = (sint32)(0u - (uint32)(2147044436));
        v5 = 16;
        goto LABEL_13;

      case 8:
        sub_80021460((sint32)(0u - (uint32)(2147044432)), 0, 0, 32, 0x40u, 0x10au, 0x6eu, 0x0u);
        v4 = (sint32)(0u - (uint32)(2147044428));
        v5 = 16;
        goto LABEL_13;

      case 9:
        sub_80021460((sint32)(0u - (uint32)(2147044424)), 0, 0, 16, 0x40u, 0x10au, 0x6eu, 0x0u);
        v4 = (sint32)(0u - (uint32)(2147044420));
        v5 = 32;
        LABEL_13:
      sub_80021460(v4, 0, 0, v5, 0x20u, 0x118u, 0x68u, 0x0u);

        break;

      default:
        return ob_front_8008E65C(20, (sint32)(0x8008d15cu), (sint32)(0x8008d104u));

    }

    return ob_front_8008E65C(20, (sint32)(0x8008d15cu), (sint32)(0x8008d104u));
  }
  else
  {
    switch (r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(8)))))
    {
      case 0:
        sub_80021460((sint32)(0u - (uint32)(2147044404)), 0, 0, 16, 0x40u, 0x106u, 0x6bu, 0x0u);
        v6 = (sint32)(0u - (uint32)(2147044400));
        goto LABEL_26;

      case 1:
        sub_80021460((sint32)(0u - (uint32)(2147044396)), 0, 0, 32, 0x40u, 0x104u, 0x6bu, 0x0u);
        v6 = (sint32)(0u - (uint32)(2147044392));
        goto LABEL_26;

      case 2:
        sub_80021460((sint32)(0u - (uint32)(2147044388)), 0, 0, 32, 0x40u, 0x106u, 0x6au, 0x0u);
        v6 = (sint32)(0u - (uint32)(2147044384));
        goto LABEL_26;

      case 3:
        sub_80021460((sint32)(0u - (uint32)(2147044380)), 0, 0, 32, 0x40u, 0x106u, 0x6au, 0x0u);
        v6 = (sint32)(0u - (uint32)(2147044376));
        goto LABEL_26;

      case 4:
        sub_80021460((sint32)(0u - (uint32)(2147044372)), 0, 0, 32, 0x40u, 0x106u, 0x6au, 0x0u);
        v6 = (sint32)(0u - (uint32)(2147044368));
        goto LABEL_26;

      case 5:
        v6 = (sint32)(0u - (uint32)(2147044364));
        goto LABEL_26;

      case 6:
        v6 = (sint32)(0u - (uint32)(2147044360));
        goto LABEL_26;

      case 7:
        v6 = (sint32)(0u - (uint32)(2147044356));
        goto LABEL_26;

      case 8:
        v6 = (sint32)(0u - (uint32)(2147044352));
        goto LABEL_26;

      case 9:
        sub_80021460((sint32)(0u - (uint32)(2147044348)), 0, 0, 16, 0x40u, 0x107u, 0x6eu, 0x0u);
        v6 = (sint32)(0u - (uint32)(2147044344));
        LABEL_26:
      result = sub_80021460(v6, 0, 0, 32, 0x20u, 0x117u, 0x69u, 0x0u);

        break;

      default:
        return result;

    }

  }
  return result;
}


uint32 ob_front_8008EEF4(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8008eef4u, "FRONT.BIN");
  sint32 v2;
  sint32 result;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  if ((r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12)))) != a2))
  {
    v4 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(8))));
    if ((v4 == 1))
    {
      sub_80021460((sint32)(0u - (uint32)(2147044600)), 0, 0, 32, 0x40u, 0x48u, 0x8eu, 0x0u);
      v5 = (sint32)(0u - (uint32)(2147044596));
      v6 = 16;
    }
    else
    {
      result = 2;
      if ((((sint32)(v4) < (sint32)(2)) || (v4 != 2)))
        return result;
      sub_80021460((sint32)(0u - (uint32)(2147044600)), 0, 0, 32, 0x40u, 0x48u, 0x8eu, 0x0u);
      sub_80021460((sint32)(0u - (uint32)(2147044596)), 0, 0, 16, 0x40u, 0x68u, 0x8eu, 0x0u);
      v5 = (sint32)(0u - (uint32)(2147044592));
      v6 = 32;
    }
    return sub_80021460(v5, 0, 0, v6, 0x40u, 0x16u, 0x8bu, 0x0u);
  }
  v2 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(8))));
  result = ((sint32)(v2) < (sint32)(2));
  if ((v2 == 1))
  {
    sub_80021460((sint32)(0u - (uint32)(2147044648)), 0, 0, 32, 0x40u, 0x16u, 0x8bu, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044644)), 0, 0, 32, 0x40u, 0x36u, 0x8bu, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044640)), 0, 0, 32, 0x40u, 0x56u, 0x8bu, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044636)), 0, 0, 32, 0x40u, 0x76u, 0x8bu, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044632)), 0, 0, 16, 0x40u, 0x96u, 0x8bu, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044628)), 0, 0, 32, 0x20u, 0x16u, 0xcbu, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044624)), 0, 0, 32, 0x20u, 0x36u, 0xcbu, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044620)), 0, 0, 32, 0x20u, 0x56u, 0xcbu, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044616)), 0, 0, 32, 0x20u, 0x76u, 0xcbu, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044612)), 0, 0, 32, 0x40u, 0x4bu, 0x8du, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044608)), 0, 0, 16, 0x40u, 0x6bu, 0x8du, 0x0u);
    return ob_front_8008E65C(20, (sint32)(0x8008d0d0u), (sint32)(0x8008d0e4u));
  }
  else
    if (((sint32)(v2) >= (sint32)(2)))
  {
    result = 2;
    if ((v2 == 2))
    {
      sub_80021460((sint32)(0u - (uint32)(2147044648)), 0, 0, 32, 0x40u, 0x16u, 0x8bu, 0x0u);
      sub_80021460((sint32)(0u - (uint32)(2147044644)), 0, 0, 32, 0x40u, 0x36u, 0x8bu, 0x0u);
      sub_80021460((sint32)(0u - (uint32)(2147044640)), 0, 0, 32, 0x40u, 0x56u, 0x8bu, 0x0u);
      sub_80021460((sint32)(0u - (uint32)(2147044636)), 0, 0, 32, 0x40u, 0x76u, 0x8bu, 0x0u);
      sub_80021460((sint32)(0u - (uint32)(2147044632)), 0, 0, 16, 0x40u, 0x96u, 0x8bu, 0x0u);
      sub_80021460((sint32)(0u - (uint32)(2147044628)), 0, 0, 32, 0x20u, 0x16u, 0xcbu, 0x0u);
      sub_80021460((sint32)(0u - (uint32)(2147044624)), 0, 0, 32, 0x20u, 0x36u, 0xcbu, 0x0u);
      sub_80021460((sint32)(0u - (uint32)(2147044620)), 0, 0, 32, 0x20u, 0x56u, 0xcbu, 0x0u);
      sub_80021460((sint32)(0u - (uint32)(2147044616)), 0, 0, 32, 0x20u, 0x76u, 0xcbu, 0x0u);
      sub_80021460((sint32)(0u - (uint32)(2147044612)), 0, 0, 32, 0x40u, 0x4bu, 0x8du, 0x0u);
      sub_80021460((sint32)(0u - (uint32)(2147044608)), 0, 0, 16, 0x40u, 0x6bu, 0x8du, 0x0u);
      sub_80021460((sint32)(0u - (uint32)(2147044604)), 0, 0, 32, 0x40u, 0x50u, 0xacu, 0x0u);
      return ob_front_8008E65C(20, (sint32)(0x8008d0d0u), (sint32)(0x8008d0ecu));
    }
  }
  else
    if (!v2)
  {
    sub_80021460((sint32)(0u - (uint32)(2147044648)), 0, 0, 32, 0x40u, 0x36u, 0x8bu, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044644)), 0, 0, 32, 0x40u, 0x56u, 0x8bu, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044640)), 0, 0, 32, 0x40u, 0x76u, 0x8bu, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044636)), 0, 0, 32, 0x40u, 0x96u, 0x8bu, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044632)), 0, 0, 16, 0x20u, 0x16u, 0xcbu, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044628)), 0, 0, 32, 0x20u, 0x36u, 0xcbu, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044624)), 0, 0, 32, 0x20u, 0x56u, 0xcbu, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044620)), 0, 0, 32, 0x20u, 0x76u, 0xcbu, 0x0u);
    sub_80021460((sint32)(0u - (uint32)(2147044616)), 0, 0, 32, 0x40u, 0x4fu, 0xaau, 0x0u);
    return ob_front_8008E65C(20, (sint32)(0x8008d0d0u), (sint32)(0x8008d0dcu));
  }
  return result;
}


