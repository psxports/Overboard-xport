#include "front_signatures.h"
#include "native_runtime.h"
#include <stdint.h>

/* Unverified FRONT draft */
/* TODO: Main cleanup aliases still require obsolete guest SP context; pass actual object only */

void ob_front_8008EEEC(void)
{
    FUNCTION_MARKER(0x8008EEECu, "FRONT.BIN");
}

static void front_c_solid_quad(uint32 x, uint32 y, uint32 width, uint32 height)
{
    uint32 attributes = ob_draft_scratch_acquire(32u);
    w_u32(attributes + 16u, 196u);
    w_u32(attributes + 20u, 196u);
    w_u32(attributes + 24u, 196u);
    w_u32(attributes + 28u, 1u);
    ob_append_solid_quad(x, y, width, height, attributes);
    ob_draft_scratch_release(attributes);
}

uint32 ob_front_8008E204(void)
{
    FUNCTION_MARKER(0x8008E204u, "FRONT.BIN");
    return ob_front_8008E20C(r_u32(0x8009BB8Cu));
}

uint32 ob_front_80092114(void)
{
    FUNCTION_MARKER(0x80092114u, "FRONT.BIN");
    w_u32(0x8009BB94u, 0x8009BD54u);
    return 0x8009BD54u;
}

uint32 ob_front_80092D1C(uint32 unused_a0, uint32 a2)
{
    FUNCTION_MARKER(0x80092D1Cu, "FRONT.BIN");
    uint32 value = r_u32(a2 + 4u) | 0x100u;
    w_u32(a2 + 4u, value);
    return value;
}

uint32 ob_front_8008E1A0(uint32 object)
{
    FUNCTION_MARKER(0x8008E1A0u, "FRONT.BIN");
    if ((r_u32(object + 120u) - 1u) < 2u)
        return 256u;
    ob_draft_unresolved_call(0x80011984u, 7u, 0x8006ABFCu, 255u, 5u, 15u, 256u, 0u, 0u);
    w_u32(r_u32(0x8009BB88u) + 120u, 1u);
    return 1u;
}

uint32 ob_front_8008E20C(uint32 object)
{
    FUNCTION_MARKER(0x8008E20Cu, "FRONT.BIN");
    if ((r_u32(object + 120u) - 1u) < 2u)
        return 256u;
    ob_draft_unresolved_call(0x80011984u, 7u, 0x8006ABFCu, 255u, 15u, 15u, 256u, 0u, 0u);
    w_u32(r_u32(0x8009BB8Cu) + 120u, 1u);
    return 1u;
}

uint32 ob_front_8008E4D8(void)
{
    FUNCTION_MARKER(0x8008E4D8u, "FRONT.BIN");
    uint32 object = r_u32(0x8009BB88u);
    w_u32(object + 140u, 250u);
    w_u32(object + 120u, 3u);
    return ob_draft_unresolved_call(0x80011984u, 7u, 0x8006AC00u, 255u, 5u, 15u, 256u, 0u, 0u);
}

uint32 ob_front_80093A34(void)
{
    FUNCTION_MARKER(0x80093A34u, "FRONT.BIN");
    return ob_draft_unresolved_call(0x80011984u, 7u, 0x8006AC30u, 255u, 15u, 15u, 256u, 0u, 0u);
}

uint32 ob_front_80093AF4(void)
{
    FUNCTION_MARKER(0x80093AF4u, "FRONT.BIN");
    return ob_draft_unresolved_call(0x80011984u, 7u, 0x8006AC20u, 255u, 15u, 15u, 256u, 0u, 0u);
}

uint32 ob_front_800948D0(uint32 unused_a0, uint32 a2)
{
    FUNCTION_MARKER(0x800948D0u, "FRONT.BIN");
    uint32 object = r_u32(0x8009CF20u + 4u * r_u32(a2));
    w_u32(object + 116u, 80u);
    return ob_front_80094918(object, r_u8(object + 120u));
}

uint32 ob_front_800949AC(uint32 unused_a0, uint32 a2)
{
    FUNCTION_MARKER(0x800949ACu, "FRONT.BIN");
    uint32 object = r_u32(0x8009CF20u + 4u * r_u32(a2));
    w_u32(object + 116u, 40u);
    return ob_front_800949F4(object, r_u8(object + 120u));
}

uint32 ob_front_800928DC(void)
{
    FUNCTION_MARKER(0x800928DCu, "FRONT.BIN");
    uint32 i;
    for (i = 0u; i < 6u; ++i)
        ob_front_8009B8E4(0x8009CF20u + 4u * i);
    return 0u;
}

uint32 ob_front_80099890(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80099890u, "FRONT.BIN");
    uint32 object;
    static const uint8 offsets[9] = {40,4,8,20,24,32,44,48,36};
    if (a2 >= 9u)
        return 0u;
    object = r_u32(0x80065CB0u + 4u * a1);
    return r_u32(object + offsets[a2]);
}

uint32 ob_front_8009B704(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8009B704u, "FRONT.BIN");
    uint32 value;
    a2 &= 255u;
    w_u8(a1 + 120u, (uint8)a2);
    switch (a2)
    {
    case 0u: value = 0x8006AAF0u; break;
    case 1u: value = 0x8006AAF8u; break;
    case 2u: value = 0x8006AB00u; break;
    case 3u: value = 0x8006AB08u; break;
    default: return 3u;
    }
    w_u32(r_u32(a1 + 52u) + 40u, value);
    return value;
}

uint32 ob_front_8009B8E4(uint32 a1)
{
    FUNCTION_MARKER(0x8009B8E4u, "FRONT.BIN");
    uint32 object = r_u32(a1);
    sub_80045124(r_u32(object + 48u));
    ob_draft_unresolved_call(0x80044058u, 1u, r_u32(r_u32(a1) + 52u));
    ob_draft_unresolved_call(0x800436ACu, 1u, r_u32(r_u32(a1)));
    return sub_800263B4(a1);
}

uint32 ob_front_8008DD3C(uint32 a1)
{
    FUNCTION_MARKER(0x8008DD3Cu, "FRONT.BIN");
    uint32 handle = ob_draft_scratch_acquire(4u);
    uint32 result;
    w_u32(handle, a1);
    sub_80045124(r_u32(a1 + 48u));
    ob_draft_unresolved_call(0x80044058u, 1u, r_u32(r_u32(handle) + 52u));
    ob_draft_unresolved_call(0x800436ACu, 1u, r_u32(r_u32(handle)));
    result = sub_800263B4(handle);
    ob_draft_scratch_release(handle);
    return result;
}

uint32 ob_front_8009212C(uint32 unused_a0, uint32 a2)
{
    FUNCTION_MARKER(0x8009212Cu, "FRONT.BIN");
    uint32 mode = r_u32(a2 + 8u);
    uint32 resource;
    w_u8(0x8006C22Cu, (uint8)mode);
    switch ((sint32)mode)
    {
    case 0: resource = 0x8006AC0Cu; break;
    case 1: resource = 0x8006AC10u; break;
    case 2: resource = 0x8006AC14u; break;
    default: return (sint32)mode < 2 ? 1u : 2u;
    }
    return ob_draft_unresolved_call(0x80011984u, 7u, resource,255u,15u,15u,256u,0u,0u);
}

uint32 ob_front_80094B7C(uint32 unused_a0, uint32 a2)
{
    FUNCTION_MARKER(0x80094B7Cu, "FRONT.BIN");
    uint32 object = r_u32(0x8009CF20u + 4u * r_u32(a2));
    uint32 result = r_u32(object + 124u);
    uint32 value;
    if (result)
        return result;
    value = r_u32(a2 + 8u);
    value = (sint32)value > 0 ? value - 1u : r_u32(a2 + 12u);
    w_u32(a2 + 8u, value);
    object = r_u32(0x8009CF20u + 4u * r_u32(a2));
    ob_draft_unresolved_call(0x80011984u,7u,0x8006AC04u,128u,(uint32)(sint32)(sint8)r_u8(object + 112u),15u,256u,0u,0u);
    object = r_u32(0x8009CF20u + 4u * r_u32(a2));
    w_u32(object + 124u, 2u);
    object = r_u32(0x8009CF20u + 4u * r_u32(a2));
    result = r_u32(a2 + 8u);
    w_u8(object + 121u, (uint8)result);
    return result;
}

uint32 ob_front_800946F0(uint32 a1)
{
    FUNCTION_MARKER(0x800946F0u, "FRONT.BIN");
    uint32 width = 0u;
    uint32 i = 0u;
    uint32 cursor = a1;
    while ((sint32)i < (sint32)ob_draft_unresolved_call(0x80063FB8u,1u,a1))
    {
        uint32 character = r_u8(cursor);
        width += character == 32u ? 6u : 1u + (uint32)(sint32)(sint8)r_u8(0x8009CC53u + character);
        ++cursor;
        ++i;
    }
    return width;
}

uint32 ob_front_8009789C(uint32 a1)
{
    FUNCTION_MARKER(0x8009789Cu, "FRONT.BIN");
    uint32 target = r_u32(a1 + 16u);
    if (target)
        ob_draft_unresolved_call(target, 0u);
    target = r_u32(a1 + 28u);
    return target ? ob_draft_unresolved_call(target, 1u, a1) : 0u;
}

uint32 ob_front_80092CB0(uint32 a1)
{
    FUNCTION_MARKER(0x80092CB0u, "FRONT.BIN");
    uint32 item, target;
    sub_80021B20(0x8006AAB0u);
    w_u32(0x80073518u, 0x80021C24u);
    item = r_u32(a1 + 12u);
    target = r_u32(item + 48u);
    return target ? ob_draft_unresolved_call(target,1u,a1) : 0u;
}

uint32 ob_front_80094288(uint32 a1, uint32 a2, uint32 a3, uint32 a4, uint32 a5)
{
    FUNCTION_MARKER(0x80094288u, "FRONT.BIN");
    uint32 half_width = (uint32)((sint32)ob_front_800946F0(a1) / 2);
    uint32 left = a3 + 26u - half_width;
    uint32 row = a4 + 2u;
    if (a2 && a5 == 1u)
    {
        ob_draft_unresolved_call(0x80021460u,8u,0x8006ACD0u,0u,0u,32u,31u,a3,a4,0u);
        ob_draft_unresolved_call(0x80021460u,8u,0x8006ACD4u,0u,0u,31u,31u,a3 + 32u,a4,0u);
        return ob_front_80094488(a1,left,row,91u,15u,8u,0u);
    }
    ob_draft_unresolved_call(0x80021460u,8u,0x8006ACD8u,0u,0u,32u,31u,a3,a4,a2 ? 0u : 1u);
    ob_draft_unresolved_call(0x80021460u,8u,0x8006ACDCu,0u,0u,31u,31u,a3 + 32u,a4,a2 ? 0u : 1u);
    return ob_front_80094488(a1,left,row,45u,40u,22u,a2 ? 0u : 1u);
}

uint32 ob_front_80097FE8(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80097fe8u, "FRONT.BIN");
  sint32 v2;
  sint32 v3;
  v2 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))));
  if (v2)
  {
    v3 = r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(20))));
    if ((v3 != v2))
    {
      do
      {
        v2 = r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(20))));
        v3 = r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(20))));
      }
      while ((v3 != r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))))));
    }
    w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(16))), v2);
    w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(20))), v3);
    w_u32((uint32)((sint32)((uint32)(v2) + (uint32)(20))), a2);
    w_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))))) + (uint32)(16))), a2);
  }
  else
  {
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))), a2);
    w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(16))), a2);
    w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(20))), a2);
    w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12))), a2);
  }
  return a2;
}


uint32 ob_front_80093224(void)
{
    FUNCTION_MARKER(0x80093224u, "FRONT.BIN");
  uint32 v0;
  sint32 result;
  v0 = (ob_front_800947EC(12) != 0);
  result = 2;
  if (!v0)
  {
    v0 = (ob_front_800947EC(5) != 0);
    result = 5;
    if (!v0)
    {
      v0 = (ob_front_800947EC(7) != 0);
      result = 4;
      if (!v0)
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
  }
  return result;
}


uint32 ob_front_8009234C(uint32 a1)
{
    FUNCTION_MARKER(0x8009234cu, "FRONT.BIN");
  sint32 v2;
  uint32 v3;
  sint32 result;
  v2 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))));
  ob_front_80094488(0x8008d0f4u, 110, 34, 91, 0xfu, 0x8u, 0u);
  do
  {
    v3 = r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(44))));
    if (v3)
      ob_draft_unresolved_call(v3, 2u, a1, v2);
    v2 = r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(20))));
    result = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))));
  }
  while ((v2 != result));
  return result;
}


uint32 ob_front_80097458(uint32 a1)
{
    FUNCTION_MARKER(0x80097458u, "FRONT.BIN");
    /* TODO: Bind original external target 0x8001cf2c */
  sint32 i;
  sint32 v3;
  ob_front_8009465C((uint32)(0x8008d78cu), 0x2du, 0x5bu, 0xfu, 0x8u, 0u);
  for (i = 0; ((sint32)(i) < (sint32)(20)); ++i)
  {
    v3 = ob_draft_unresolved_call(0x8001cf2cu, 1u, i);
    ob_front_800974E4(i, v3, a1);
  }

  return ob_front_80093E70((sint32)r_u32(0x8009c56cu));
}


uint32 ob_front_80097E5C(uint32 a1)
{
    FUNCTION_MARKER(0x80097E5Cu, "FRONT.BIN");
    uint32 handle_cell = ob_draft_scratch_acquire(4u);
    w_u32(handle_cell, 0u);
    sub_800262CC(handle_cell, 36u);
    uint32 object = r_u32(handle_cell);
    ob_draft_scratch_release(handle_cell);
    if (!object)
        return 0u;
    for (uint32 offset = 0u; offset < 36u; offset += 4u)
        w_u32(object + offset, 0u);
    w_u32(object, r_u32(a1));
    for (uint32 index = 1u; index < 6u; ++index)
        w_u32(object + 12u + index * 4u, r_u32(a1 + index * 4u));
    return object;
}


uint32 ob_front_80092814(uint32 a1)
{
    FUNCTION_MARKER(0x80092814u, "FRONT.BIN");
  sint32 v2;
  uint32 v3;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  uint32 v8;
  uint32 result;
  sub_80021B20((sint32)(0u - (uint32)(2147046740)));
  v2 = 0;
  w_u32(0x80073518u, 0x80021C24u);
  v3 = (0x8009cf20u);
  v4 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))));
  do
  {
    v5 = ob_front_8009B540(v2, r_u32((uint32)((sint32)((uint32)(v4) + (uint32)(8)))));
    w_u32(v3, v5);
    v6 = (sint32)((uint32)(v2) + (uint32)(16));
    ++v2;
    w_u32((uint32)((sint32)((uint32)(v5) + (uint32)(108))), v6);
    v4 = r_u32((uint32)((sint32)((uint32)(v4) + (uint32)(20))));
    ((v3 += 4u));
  }
  while (((sint32)(v2) < (sint32)(6)));
  v7 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))));
  w_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12))), v7);
  v8 = r_u32((uint32)((sint32)((uint32)(v7) + (uint32)(48))));
  if (v8)
    ob_draft_unresolved_call(v8, 1u, a1);
  result = 0x8009C3B0u;
  w_u32(0x8009bb94u, result);
  return result;
}


uint32 ob_front_8009307C(void)
{
    FUNCTION_MARKER(0x8009307cu, "FRONT.BIN");
  uint32 v0;
  sint32 result;
  v0 = (ob_front_800947EC(12) != 0);
  result = 2;
  if (!v0)
  {
    if (ob_front_800947EC(5))
    {
      sub_80011984((sint32)(0u - (uint32)(2147046368)), 255, 15, 15, 0x100u, 0u, 0u);
      return 5;
    }
    else
      if (ob_front_800947EC(7))
    {
      sub_80011984((sint32)(0u - (uint32)(2147046368)), 255, 15, 15, 0x100u, 0u, 0u);
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


uint32 ob_front_800996B8(uint32 a1)
{
    FUNCTION_MARKER(0x800996b8u, "FRONT.BIN");
  sint8 v1;
  uint32 v2;
  sint32 result;
  v1 = (sint32)((uint32)(16) * (uint32)(a1));
  v2 = (ob_front_800947EC(((sint32)((uint32)((sint32)((uint32)(16) * (uint32)(a1))) + (uint32)(4)) & 0xFC)) != 0);
  result = 1;
  if (!v2)
  {
    v2 = (ob_front_800947EC(((sint32)((uint32)(v1) + (uint32)(6)) & 0xFE)) != 0);
    result = 2;
    if (!v2)
    {
      v2 = (ob_front_800947EC((sint32)((uint32)(v1) + (uint32)(7))) != 0);
      result = 3;
      if (!v2)
      {
        v2 = (ob_front_800947EC((sint32)((uint32)(v1) + (uint32)(5))) != 0);
        result = 4;
        if (!v2)
        {
          v2 = (ob_front_800947EC(((sint32)((uint32)(v1) + (uint32)(14)) & 0xFE)) != 0);
          result = 5;
          if (!v2)
          {
            v2 = (ob_front_800947EC((sint32)((uint32)(v1) + (uint32)(15))) != 0);
            result = 6;
            if (!v2)
            {
              v2 = (ob_front_800947EC(((sint32)((uint32)(v1) + (uint32)(12)) & 0xFC)) != 0);
              result = 8;
              if (!v2)
                return ((ob_front_800947EC((sint32)((uint32)(v1) + (uint32)(3))) != 0)) ? (7) : (0);
            }
          }
        }
      }
    }
  }
  return result;
}


uint32 ob_front_800993B4(uint32 a1)
{
    FUNCTION_MARKER(0x800993b4u, "FRONT.BIN");
  sint32 v2;
  uint32 v3;
  sint32 v4;
  uint32 v5;
  sint32 result;
  sint32 v7;
  uint32 v8;
  uint32 v9;
  sint32 v10;
  v2 = 0;
  v3 = (uint32)((sint32)r_u32(0x8009c878u));
  v4 = 60;
  do
  {
    v5 = r_u32(((v3 += 4u) - 4u));
    v4 = ((uint32)(v4) + (uint32)(16));
    ++v2;
    ob_front_80094488(v5, 50, 0x3cu, 0x2du, 0x28u, 0x16u, 0u);
    result = ((sint32)(v2) < (sint32)(9));
  }
  while (((sint32)(v2) < (sint32)(9)));
  v7 = 0;
  if (((sint32)(a1) > (sint32)(0)))
  {
    v8 = 0x8009d040u;
    v9 = 0x8009d028u;
    do
    {
      v10 = (sint32)r_u32(((v8 += 4u) - 4u));
      ob_front_800994B0(v7++, a1, ((sint32)r_u32(v9) == 2), v10);
      result = ((sint32)(v7) < (sint32)(a1));
      ((v9 += 4u));
    }
    while (((sint32)(v7) < (sint32)(a1)));
  }
  return result;
}


uint32 ob_front_8009978C(uint32 a1)
{
    FUNCTION_MARKER(0x8009978cu, "FRONT.BIN");
  sint8 v1;
  uint32 v2;
  sint32 result;
  v1 = (sint32)((uint32)(16) * (uint32)(a1));
  v2 = (ob_front_800947EC(((sint32)((uint32)((sint32)((uint32)(16) * (uint32)(a1))) + (uint32)(4)) & 0xFC)) != 0);
  result = 4;
  if (!v2)
  {
    v2 = (ob_front_800947EC(((sint32)((uint32)(v1) + (uint32)(6)) & 0xFE)) != 0);
    result = 6;
    if (!v2)
    {
      v2 = (ob_front_800947EC(((sint32)((uint32)(v1) + (uint32)(14)) & 0xFE)) != 0);
      result = 14;
      if (!v2)
      {
        v2 = (ob_front_800947EC(((sint32)((uint32)(v1) + (uint32)(12)) & 0xFC)) != 0);
        result = 12;
        if (!v2)
        {
          v2 = (ob_front_800947EC((sint32)((uint32)(v1) + (uint32)(15))) != 0);
          result = 15;
          if (!v2)
          {
            v2 = (ob_front_800947EC((sint32)((uint32)(v1) + (uint32)(13))) != 0);
            result = 13;
            if (!v2)
            {
              v2 = (ob_front_800947EC((sint32)((uint32)(v1) + (uint32)(11))) != 0);
              result = 11;
              if (!v2)
              {
                v2 = (ob_front_800947EC((sint32)((uint32)(v1) + (uint32)(9))) != 0);
                result = 9;
                if (!v2)
                {
                  if (ob_front_800947EC(((sint32)((uint32)(v1) + (uint32)(10)) & 0xFE)))
                  {
                    return 10;
                  }
                  else
                  {
                    v2 = (ob_front_800947EC(((sint32)((uint32)(v1) + (uint32)(8)) & 0xF8)) != 0);
                    result = 8;
                    if (!v2)
                      return (sint32)(0u - (uint32)(1));
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}


uint32 ob_front_8008E65C(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x8008e65cu, "FRONT.BIN");
  sint32 v6;
  sint32 v7;
  sub_80021460((sint32)(0u - (uint32)(2147045980)), 0, 0, 32, 0x40u, 0x95u, a1, 0u);
  sub_80021460((sint32)(0u - (uint32)(2147045976)), 0, 0, 32, 0x40u, 0xb5u, a1, 0u);
  sub_80021460((sint32)(0u - (uint32)(2147045972)), 0, 0, 32, 0x40u, 0xd5u, a1, 0u);
  v6 = a2;
  if (a3)
  {
    ob_front_8009465C(a2, (sint32)((uint32)(a1) + (uint32)(5)), 91, 15, 0x8u, 0u);
    v6 = a3;
    v7 = (sint32)((uint32)(a1) + (uint32)(17));
  }
  else
  {
    v7 = (sint32)((uint32)(a1) + (uint32)(11));
  }
  return ob_front_8009465C(v6, v7, 91, 15, 0x8u, 0u);
}


uint32 ob_front_80094C68(uint32 a1, uint32 a2, uint32 a3, uint32 a4)
{
    FUNCTION_MARKER(0x80094c68u, "FRONT.BIN");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Bind original external target 0x80020bd8 */
  sint32 v3;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  uint32 v7;
  v3 = (sint32)((uint32)((sint32)((uint32)(36) * (uint32)(a2))) + (uint32)((sint32)((uint32)(552) * (uint32)(a1))));
  v4 = (sint32)(a2 << 9u);
  if (r_u32(0x80089D34u + (uint32)v3) && r_u8(0x80084ACAu + (uint32)v4))
  {
    v5 = r_u32((uint32)((sint32)((uint32)(v3) - (uint32)(2146919108))));
    ob_front_80094FB0((sint32)((uint32)(v4) - (uint32)(2146940120)), 0x8009CD60u, 16);
    v6 = (sint32)r_u32((0x8009cec4u + (a2) * 4u));
    v7 = (uint32)((sint32)((uint32)((sint32)((uint32)(v4) - (uint32)(2146940088))) + (uint32)((sint32)((uint32)(((sint32)(v5) / (sint32)(2))) << (uint32)(7)))));
  }
  else
  {
    ob_front_80094FB0(0x8009CE00u, 0x8009CD60u, 16);
    v6 = (sint32)r_u32((0x8009cec4u + (a2) * 4u));
    v7 = 0x8009CD80u;
  }
  ob_draft_unresolved_call(0x80020bd8u, 3u, v6, v7, 0x8009CD60u);
  return sub_80021460((sint32)r_u32((0x8009cec4u + (a2) * 4u)), 0, 0, 16, 0x10u, ((sint32)((a3 << 0x10u)) >> 0x10u), ((sint32)((a4 << 0x10u)) >> 0x10u), 0u);
}


uint32 ob_front_8008E828(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8008e828u, "FRONT.BIN");
  sint32 result;
  result = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12))));
  if ((result == a2))
  {
    sub_80021460((sint32)(0u - (uint32)(2147044712)), 0, 0, 32, 0x40u, 0x8bu, 0x28u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044708)), 0, 0, 32, 0x40u, 0xabu, 0x1eu, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044704)), 0, 0, 32, 0x20u, 0xabu, 0x5eu, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044700)), 0, 0, 32, 0x40u, 0xcbu, 0x20u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044696)), 0, 0, 32, 0x10u, 0xcbu, 0x60u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044692)), 0, 0, 16, 0x40u, 0xebu, 0x32u, 0u);
    return ob_front_8008E65C(130, (sint32)(0x8008d0a0u), 0);
  }
  return result;
}


uint32 ob_front_80095DF0(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x80095df0u, "FRONT.BIN");
  sint32 v6;
  sint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  sint32 v11;
  sint32 v12;
  sint32 result;
  v6 = 0;
  v7 = (sint32)((uint32)(552) * (uint32)(a1));
  v8 = (sint32)((uint32)(552) * (uint32)(a1));
  do
  {
    v9 = a1;
    if (a2)
    {
      if (((sint32)(a1) < (sint32)(0)))
        goto LABEL_18;
      v12 = r_u32((uint32)((sint32)((uint32)(v7) - (uint32)(2146919112))));
      if (((sint32)(v12) > (sint32)(0)))
      {
        if (((sint32)(a3) < (sint32)(0)))
        {
          v9 = a1;
        }
        else
        {
          v9 = a1;
          if ((r_u32((uint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(36) * (uint32)(a3))) + (uint32)(v8))) - (uint32)(2146919112)))) == v12))
          {
            v10 = v6;
            if ((a2 == 2))
            {
              v11 = 2;
              if ((a3 == v6))
              {
                v9 = a1;
                v10 = v6;
                v11 = 3;
              }
              goto LABEL_17;
            }
            goto LABEL_16;
          }
        }
        LABEL_15:
        v10 = v6;

        LABEL_16:
        v11 = 1;

        goto LABEL_17;
      }
      v9 = a1;
      if ((a3 != v6))
        goto LABEL_15;
      v10 = v6;
      if ((a2 != 2))
        goto LABEL_16;
      v9 = a1;
      v11 = 3;
    }
    else
    {
      v10 = v6;
      v11 = 0;
    }
    LABEL_17:
    ob_front_80095F9C(v9, v10, v11);

    LABEL_18:
    ++v6;

    v7 = ((uint32)(v7) + (uint32)(36));
  }
  while (((sint32)(v6) < (sint32)(15)));
  result = 2;
  if ((a1 != (sint32)(0u - (uint32)(1))))
  {
    result = (sint32)((uint32)(16) * (uint32)(a1));
    if ((a2 != 2))
    {
      result = 15;
      if ((r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(552) * (uint32)(a1))) - (uint32)(2146919120)))) == 15))
      {
        result = r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(552) * (uint32)(a1))) - (uint32)(2146919124))));
        if (!result)
          return ob_front_8009465C((uint32)(0x8008d400u), 0x9eu, 0x5bu, 0xfu, 0x8u, 0u);
      }
    }
  }
  return result;
}


uint32 ob_front_80092E84(uint32 a1)
{
    FUNCTION_MARKER(0x80092e84u, "FRONT.BIN");
  uint32 v1;
  sint32 v2;
  uint32 result;
  v1 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))));
  do
  {
    switch (r_u32(v1))
    {
      case 0:
        w_u32((v1 + (2) * 4u), r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(40)))));
        break;

      case 1:
        w_u32((v1 + (2) * 4u), r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(4)))));
        break;

      case 2:
        w_u32((v1 + (2) * 4u), r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(8)))));
        break;

      case 3:
        w_u32((v1 + (2) * 4u), r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(20)))));
        break;

      case 4:
        w_u32((v1 + (2) * 4u), r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(24)))));
        break;

      case 5:
        w_u32((v1 + (2) * 4u), r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(32)))));
        break;

      case 6:
        w_u32((v1 + (2) * 4u), r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(44)))));
        break;

      case 7:
        w_u32((v1 + (2) * 4u), r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(48)))));
        break;

      case 8:
        v2 = (sint32)r_u32(0x80065CB0);
        goto LABEL_21;

      case 9:
        w_u32((v1 + (2) * 4u), r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB4)) + (uint32)(40)))));
        break;

      case 0xA:
        w_u32((v1 + (2) * 4u), r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB4)) + (uint32)(4)))));
        break;

      case 0xB:
        w_u32((v1 + (2) * 4u), r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB4)) + (uint32)(8)))));
        break;

      case 0xC:
        w_u32((v1 + (2) * 4u), r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB4)) + (uint32)(20)))));
        break;

      case 0xD:
        w_u32((v1 + (2) * 4u), r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB4)) + (uint32)(24)))));
        break;

      case 0xE:
        w_u32((v1 + (2) * 4u), r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB4)) + (uint32)(32)))));
        break;

      case 0xF:
        w_u32((v1 + (2) * 4u), r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB4)) + (uint32)(44)))));
        break;

      case 0x10:
        w_u32((v1 + (2) * 4u), r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB4)) + (uint32)(48)))));
        break;

      case 0x11:
        v2 = (sint32)r_u32(0x80065CB4);
        LABEL_21:
      w_u32((v1 + (2) * 4u), r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(36)))));

        break;

      default:
        break;

    }

    v1 = (uint32)(r_u32((v1 + (5) * 4u)));
    result = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(8))));
  }
  while ((v1 != result));
  return result;
}


uint32 ob_front_80097210(uint32 a1)
{
    FUNCTION_MARKER(0x80097210u, "FRONT.BIN");
    /* TODO: Bind original external target 0x8005c504 */
    /* TODO: Bind original external target 0x8001cf2c */
    /* TODO: Bind original external target 0x8001cebc */
    /* TODO: Bind original external target 0x8001d818 */
    uint32 local_objects = ob_draft_scratch_acquire(376u);
  sint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  uint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  ;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  while (1)
  {
    while ((sint32)r_u32(0x80077620))
      ob_native_pump();

    ob_draft_unresolved_call(0x8005c504u, 1u, 0);
    w_u32(0x8007754C, (sint32)r_u32(0x8007737C));
    ob_switch_frame_buffer();
    w_u32(0x80077620, 1);
    ob_snapshot_controller_flags();
    sub_8002D25C((sint32)(0u - (uint32)(2146906416)), (sint32)(0u - (uint32)(2146931856)));
    sub_8001FC60();
    sub_80012184();
    if (v5)
      goto LABEL_23;
    if (ob_consume_button_edge(12u))
      break;
    if ((ob_consume_button_edge(14u) && ob_draft_unresolved_call(0x8001cf2cu, 1u, v6)))
    {
      if (v6)
        goto LABEL_30;
      ob_draft_unresolved_call(0x8001cebcu, 2u, (local_objects + 0u), 0);
      ob_draft_unresolved_call(0x8001d818u, 1u, (local_objects + 0u));
      w_u32(0x8008969C, 300);
      v5 = 1;
      goto LABEL_23;
    }
    v7 = (ob_consume_button_edge(6u) == 0);
    v8 = ((sint32)(v3) < (sint32)(3));
    if (v7)
    {
      if (ob_consume_button_edge(4u))
      {
        v7 = ((sint32)(v3--) > (sint32)(0));
        if (!v7)
          v3 = 3;
      }
      else
      {
        v7 = (ob_consume_button_edge(5u) == 0);
        v9 = ((sint32)(v2) < (sint32)(4));
        if (v7)
        {
          if (!ob_consume_button_edge(7u))
            goto LABEL_23;
          v7 = ((sint32)(v2--) > (sint32)(0));
          if (!v7)
            v2 = 4;
        }
        else
        {
          ++v2;
          if (!v9)
            v2 = 0;
        }
      }
    }
    else
    {
      ++v3;
      if (!v8)
        v3 = 0;
    }
    v6 = (sint32)((uint32)(v3) + (uint32)((sint32)((uint32)(4) * (uint32)(v2))));
    LABEL_23:
    ob_front_80097458(v6);

    v10 = 122;
    if ((v5 == 1))
    {
      ob_front_8009465C((uint32)(0x8008d774u), 0x7au, 0x80u, 0x80u, 0x80u, 0u);
      if ((ob_consume_button_edge(14u) || !(sint32)r_u32(0x8008969C)))
        v5 = 0;
    }
    if (sub_80012758(a1))
    {
      v6 = (sint32)(0u - (uint32)(1));
      v4 = (sint32)(0u - (uint32)(1));
    }
    if (v4)
      goto LABEL_30;
  }

  v6 = (sint32)(0u - (uint32)(1));
  LABEL_30:
  ob_clear_button_edges();

  { uint32 draft_return = v6; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 ob_front_80092928(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80092928u, "FRONT.BIN");
    /* TODO: Resolve external symbol strcpy instead of the owning function adapter placeholder */
    /* TODO: Bind external adapter for strcpy */
    /* TODO: Bind original external target 0x80024e04 */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Bind original external target 0x8005c504 */
    uint32 local_objects = ob_draft_scratch_acquire(24u);
  sint8 v4;
  sint8 v5;
  sint32 v6;
  uint32 v7;
  ;
  ob_draft_unresolved_call(0x80092928u, 2u, (local_objects + 0u), 0x8008d1d8u);
  w_u8(((local_objects + 0u) + (18) * 1u), (sint8)r_u8(0x8008d1eau));
  v4 = ob_draft_unresolved_call(0x80024e04u, 0u);
  v5 = (sint32)((uint32)(v4) + (uint32)(1));
  w_u8(((local_objects + 0u) + (15) * 1u), ((uint32)(((uint8)((sint32)((uint32)(v4) + (uint32)(1))) / 0xAu)) + (uint32)(48)));
  w_u8(((local_objects + 0u) + (16) * 1u), ((uint32)(((uint8)((sint32)((uint32)(v4) + (uint32)(1))) % 0xAu)) + (uint32)(48)));
  if ((v4 == (sint32)(0u - (uint32)(1))))
    v6 = (sint32)(0u - (uint32)(2147046352));
  else
    v6 = (sint32)(0u - (uint32)(2147046356));
  sub_80011984(v6, 255, 15, 15, 0x100u, 0u, 0u);
  w_u32(0x8008969C, 250);
  while (1)
  {
    ob_snapshot_controller_flags();
    sub_8002D25C((sint32)(0u - (uint32)(2146906416)), (sint32)(0u - (uint32)(2146931856)));
    sub_80012184();
    sub_8001FC60();
    ob_front_8009482C(a1);
    ob_front_800949AC(a1, a2);
    if (v5)
    {
      if (ob_front_800947EC(14))
        break;
    }
    if (((sint32)((sint32)r_u32(0x8008969C)) <= (sint32)(0)))
      break;
    v7 = (local_objects + 0u);
    if (!v5)
      v7 = 0x8008d1ecu;
    ob_front_8009465C(v7, 128, 128, 128, 0x80u, 0u);
    while ((sint32)r_u32(0x80077620))
      ob_native_pump();

    ob_draft_unresolved_call(0x8005c504u, 1u, 0);
    w_u32(0x8007754C, (sint32)r_u32(0x8007737C));
    ob_switch_frame_buffer();
    w_u32(0x80077620, 1);
  }

  ob_clear_button_edges();
  if (v5)
  {
    w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(4))), ((uint32)(r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(4))))) & (uint32)(~1u)));
    w_u8(0x8006C230, 1);
    w_u8(0x8006C233, 0);
    w_u8(0x8006C231, (sint32)((uint32)(v5) - (uint32)(1)));
    ob_init_card_tables();
  }
  else
  {
    ob_front_800948D0(a1, a2);
    w_u32((uint32)((sint32)((uint32)(a2) + (uint32)(4))), ((uint32)(r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(4))))) | (uint32)(1u)));
  }
  { uint32 draft_return = ob_front_800947B4(); ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 ob_front_8009350C(void)
{
    FUNCTION_MARKER(0x8009350cu, "FRONT.BIN");
  if (ob_front_800947EC(4))
  {
    sub_80011984((sint32)(0u - (uint32)(2147046348)), 255, 15, 15, 0x100u, 0u, 0u);
    return 4;
  }
  else
    if (ob_front_800947EC(6))
  {
    sub_80011984((sint32)(0u - (uint32)(2147046348)), 255, 15, 15, 0x100u, 0u, 0u);
    return 6;
  }
  else
    if (ob_front_800947EC(10))
  {
    sub_80011984((sint32)(0u - (uint32)(2147046348)), 255, 15, 15, 0x100u, 0u, 0u);
    return 10;
  }
  else
    if (ob_front_800947EC(8))
  {
    sub_80011984((sint32)(0u - (uint32)(2147046348)), 255, 15, 15, 0x100u, 0u, 0u);
    return 8;
  }
  else
    if (ob_front_800947EC(12))
  {
    sub_80011984((sint32)(0u - (uint32)(2147046348)), 255, 15, 15, 0x100u, 0u, 0u);
    return 12;
  }
  else
    if (ob_front_800947EC(14))
  {
    sub_80011984((sint32)(0u - (uint32)(2147046348)), 255, 15, 15, 0x100u, 0u, 0u);
    return 14;
  }
  else
    if (ob_front_800947EC(15))
  {
    sub_80011984((sint32)(0u - (uint32)(2147046348)), 255, 15, 15, 0x100u, 0u, 0u);
    return 15;
  }
  else
    if (ob_front_800947EC(13))
  {
    sub_80011984((sint32)(0u - (uint32)(2147046348)), 255, 15, 15, 0x100u, 0u, 0u);
    return 13;
  }
  else
    if (ob_front_800947EC(11))
  {
    sub_80011984((sint32)(0u - (uint32)(2147046348)), 255, 15, 15, 0x100u, 0u, 0u);
    return 11;
  }
  else
    if (ob_front_800947EC(9))
  {
    sub_80011984((sint32)(0u - (uint32)(2147046348)), 255, 15, 15, 0x100u, 0u, 0u);
    return 9;
  }
  else
  {
    return (sint32)(0u - (uint32)(1));
  }
}


uint32 ob_front_800923D4(uint32 a1)
{
    FUNCTION_MARKER(0x800923d4u, "FRONT.BIN");
    /* TODO: Bind original external target 0x8005c504 */
    uint32 local_objects = ob_draft_scratch_acquire(8u);
  sint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 v5;
  ;
  v2 = 0;
  sub_80011984((sint32)(0u - (uint32)(2147046352)), 255, 15, 15, 0x100u, 0u, 0u);
  v3 = 0;
  w_u32(((local_objects + 0u) + (0) * 4u), ob_front_80097E5C((sint32)r_u32(0x8009c914u)));
  do
  {
    v4 = ob_front_80097EF8((0x8009cc38u));
    w_u32((uint32)(ob_front_80097FE8((sint32)r_u32(((local_objects + 0u) + (0) * 4u)), v4)), v3++);
  }
  while (((sint32)(v3) < (sint32)(9)));
  ob_front_8009789C((sint32)r_u32(((local_objects + 0u) + (0) * 4u)));
  sub_80021B20((sint32)(0u - (uint32)(2147046732)));
  do
  {
    ob_snapshot_controller_flags();
    sub_8002D25C((sint32)(0u - (uint32)(2146906416)), (sint32)(0u - (uint32)(2146931856)));
    sub_80012184();
    sub_8001FC60();
    if (v2)
    {
      v5 = ob_front_8009350C();
      ob_draft_unresolved_call(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(((local_objects + 0u) + (0) * 4u))) + (uint32)(24)))), 0u);
      if (((sint32)(v5) < (sint32)(0)))
        goto LABEL_14;
      ob_front_80092DAC((sint32)r_u32(((local_objects + 0u) + (0) * 4u)), r_u32((uint32)((sint32)((uint32)((sint32)r_u32(((local_objects + 0u) + (0) * 4u))) + (uint32)(12)))), v5);
      v5 = (sint32)(0u - (uint32)(1));
      v2 = 0;
      w_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(((local_objects + 0u) + (0) * 4u))) + (uint32)(12))))) + (uint32)(4))), ((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(((local_objects + 0u) + (0) * 4u))) + (uint32)(12))))) + (uint32)(4))))) & (uint32)(~0x100u)));
      goto LABEL_13;
    }
    if (ob_front_800947EC(15))
    {
      w_u32((sint32)r_u32(0x80065CB0), 3);
      w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(4))), 4);
      w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(8))), 6);
      w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(12))), 7);
      w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(16))), 5);
      w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(20))), 14);
      w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(24))), 13);
      w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(28))), 12);
      w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(32))), 15);
      w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(36))), 10);
      w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(40))), 11);
      w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(44))), 8);
      w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(48))), 9);
      w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80065CB0)) + (uint32)(52))), 14);
    }
    v5 = ob_front_80097944((local_objects + 0u));
    if (((sint32)(v5) >= (sint32)(0)))
    {
      v5 = (sint32)(0u - (uint32)(1));
      v2 = 1;
      ob_draft_unresolved_call(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(((local_objects + 0u) + (0) * 4u))) + (uint32)(24)))), 0u);
      LABEL_13:
      ob_clear_button_edges();

      goto LABEL_14;
    }
    if ((v5 != (sint32)(0u - (uint32)(1))))
      break;
    LABEL_14:
    ob_front_80093E70((sint32)r_u32(0x8009c444u));

    while ((sint32)r_u32(0x80077620))
      ob_native_pump();

    ob_draft_unresolved_call(0x8005c504u, 1u, 0);
    w_u32(0x8007754C, (sint32)r_u32(0x8007737C));
    ob_switch_frame_buffer();
    w_u32(0x80077620, 1);
  }
  while (((((sint32)r_u32(0x8009cc70u) != 1) || ((sint32)((sint32)r_u32(0x8008969C)) > (sint32)(0))) && (v5 == (sint32)(0u - (uint32)(1)))));
  ob_front_800978F0((sint32)r_u32(((local_objects + 0u) + (0) * 4u)));
  ob_front_800981C8((local_objects + 0u));
  { uint32 draft_return = ob_front_8009789C(a1); ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 ob_front_800974E4(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x800974e4u, "FRONT.BIN");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Recover original call carrier Call operand s1 */
    /* TODO: Recover original call carrier Call operand a0 */
    /* TODO: Recover original call carrier Call operand v0 */
  uint32 a4;
  /* TODO: Invalid level indices leave original text carriers undefined */
  if (a1 >= 20u)
      return ob_native_missing_value(0x800974E4u, "Level index outside 0..19");
  sint32 v4 = (sint32)((a1 == a3 ? 0x8006AD10u : 0x8006AD14u) + 8u * (a1 % 4u));
  sint32 v8;
  sint32 v9;
  sint32 result;
  uint32 v11;
  v8 = ((sint32)(a1) / (sint32)(4));
  v9 = ((sint32)(a1) % (sint32)(4));
  if ((a3 == a1))
  {
    switch (((sint32)(a1) / (sint32)(4)))
    {
      case 0:
        a4 = (sint32)(0u - (uint32)(2147046160));
        if (!a1)
        a4 = (sint32)(0u - (uint32)(2147046176));
        break;

      case 1:
        a4 = (sint32)(0u - (uint32)(2147046144));
        break;

      case 2:
        a4 = (sint32)(0u - (uint32)(2147046168));
        break;

      case 3:
        a4 = (sint32)(0u - (uint32)(2147046152));
        break;

      case 4:
        a4 = (sint32)(0u - (uint32)(2147046136));
        break;

      default:
        a4 = ob_native_missing_value(0x800974E4u, "Undefined level text");
        break;

    }

    if ((v9 == 1))
    {
      v4 = (sint32)(0u - (uint32)(2147046120));
    }
    else
      if (((sint32)(v9) >= (sint32)(2)))
    {
      if ((v9 == 2))
      {
        v4 = (sint32)(0u - (uint32)(2147046112));
      }
      else
        if ((v9 == 3))
      {
        v4 = (sint32)(0u - (uint32)(2147046104));
      }
    }
    else
      if (!v9)
    {
      v4 = (sint32)(0u - (uint32)(2147046128));
    }
  }
  else
  {
    switch (v8)
    {
      case 0:
        a4 = (sint32)(0u - (uint32)(2147046156));
        if (!a1)
        a4 = (sint32)(0u - (uint32)(2147046172));
        break;

      case 1:
        a4 = (sint32)(0u - (uint32)(2147046140));
        break;

      case 2:
        a4 = (sint32)(0u - (uint32)(2147046164));
        break;

      case 3:
        a4 = (sint32)(0u - (uint32)(2147046148));
        break;

      case 4:
        a4 = (sint32)(0u - (uint32)(2147046132));
        break;

      default:
        a4 = ob_native_missing_value(0x800974E4u, "Undefined level text");
        break;

    }

    if ((v9 == 1))
    {
      v4 = (sint32)(0u - (uint32)(2147046116));
    }
    else
      if (((sint32)(v9) >= (sint32)(2)))
    {
      if ((v9 == 2))
      {
        v4 = (sint32)(0u - (uint32)(2147046108));
      }
      else
        if ((v9 == 3))
      {
        v4 = (sint32)(0u - (uint32)(2147046100));
      }
    }
    else
      if (!v9)
    {
      v4 = (sint32)(0u - (uint32)(2147046124));
    }
  }
  result = sub_80021460(a4, 0u, 0u, 32u, 32u, 96u + 40u * (a1 / 4u), 61u + 34u * (a1 % 4u), 0u);
  if (((sint32)(a1) > (sint32)(0)))
    result = sub_80021460(v4, 0u, 0u, 16u, 16u, 120u + 40u * (a1 / 4u), 77u + 34u * (a1 % 4u), 0u);
  if ((a3 == a1))
  {
    if (a2)
    {
      v11 = r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(a1))) - (uint32)(2147042080))));
    }
    else
    {
      v11 = 0x8008d7b4u;
      if (!a1)
        v11 = 0x8008d79cu;
    }
    return ob_front_8009465C((uint32)(v11), 0xc5u, 0x5bu, 0xfu, 0x8u, 0u);
  }
  return result;
}


uint32 ob_front_80098DFC(uint32 a1)
{
    FUNCTION_MARKER(0x80098dfcu, "FRONT.BIN");
    /* TODO: Bind original external target 0x800541a8 */
    /* TODO: Bind original external target 0x8005c504 */
    /* TODO: Recover original call carrier Call operand v0 */
  sint32 v2;
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
  uint32 v13;
  uint32 v14;
  sint32 v15;
  sint32 v16;
  sint32 v17;
  uint32 v18;
  sint32 v19;
  uint32 v20;
  sint32 v21;
  sint32 v23;
  v2 = 0;
  v3 = 0;
  if (((sint32)(a1) > (sint32)(0)))
  {
    v4 = 0x8009d040u;
    v5 = 0x8009d010u;
    v6 = 0x8009d028u;
    do
    {
      if (((sint32)r_u32(v5) == 1))
        w_u32(v6, (sint32)r_u32(v5));
      else
        w_u32(v6, 2);
      w_u32(v5, 0);
      w_u32(((v4 += 4u) - 4u), (sint32)(0u - (uint32)(1)));
      ((v5 += 4u));
      ++v2;
      ((v6 += 4u));
    }
    while (((sint32)(v2) < (sint32)(a1)));
  }
  w_u32(0x80073518u, 0x80021C24u);
  do
  {
    if (ob_draft_unresolved_call(0x800541a8u, 1u, 0))
    {
      v23 = 1;
      w_u32(0x8006C130, 1);
      v7 = 5;
    }
    else
      if (ob_draft_unresolved_call(0x800541a8u, 1u, 4))
    {
      v23 = 2;
      w_u32(0x8006C130, 2);
      v7 = 5;
    }
    else
    {
      v7 = 2;
      v23 = 0;
      w_u32(0x8006C130, 0);
    }
    while ((sint32)r_u32(0x80077620))
      ob_native_pump();

    ob_draft_unresolved_call(0x8005c504u, 1u, 0);
    w_u32(0x8007754C, (sint32)r_u32(0x8007737C));
    v8 = 0;
    ob_switch_frame_buffer();
    w_u32(0x80077620, 1);
    ob_snapshot_controller_flags();
    sub_8002D25C((sint32)(0u - (uint32)(2146906416)), (sint32)(0u - (uint32)(2146931856)));
    sub_8001FC60();
    sub_80012184();
    front_c_solid_quad(40u, 36u, 304u, 176u);
    v9 = (sint32)(0u - (uint32)(2147040709));
    v10 = 0;
    v11 = (sint32)(0u - (uint32)(2147066704));
    v12 = 0;
    v13 = 0x8009d028u;
    v14 = 0x8009d040u;
    do
    {
      if (((uint32)((sint32)((uint32)(v8) - (uint32)(1))) >= 3))
      {
        v15 = v23;
      }
      else
      {
        v15 = v23;
        if ((v23 == 2))
        {
          w_u8((uint32)(v9), (sint32)((uint32)(v8) + (uint32)(4)));
          goto LABEL_23;
        }
      }
      if (v15)
        w_u8((uint32)(v9), v8);
      else
        w_u8((uint32)(v9), (sint32)((uint32)(v12) * (uint32)(4)));
      LABEL_23:
      v16 = (sint32)r_u32(v13);

      if (((sint32)r_u32(v13) == 2))
      {
        v21 = ob_front_800996B8((sint8)r_u8((uint32)(v9)));
        if ((v21 == 5))
        {
          w_u32(v13, 1);
        }
        else
        {
          if ((v21 != 7))
          {
            ++v9;
            goto LABEL_60;
          }
          if (!v8)
            LABEL_58:
          v3 = 1;

        }
        goto LABEL_59;
      }
      if (((uint32)((sint32)r_u32(v13)) >= 3))
      {
        if ((v16 != 3))
        {
          ++v9;
          goto LABEL_60;
        }
        if (((v21 = (sint32)ob_front_8009978C((sint8)r_u8((uint32)(v9)))) != (sint32)(0u - (uint32)(1))))
        {
          ob_front_800999D8(v8, (sint32)r_u32((0x8009d040u + (v12) * 4u)), v21);
          w_u32(v13, 1);
        }
        LABEL_59:
        ++v9;

        goto LABEL_60;
      }
      if ((v16 == 1))
      {
        switch (ob_front_800996B8((sint8)r_u8((uint32)(v9))))
        {
          case 1:
            if (((sint32)r_u32(v14) == (sint32)(0u - (uint32)(1))))
            w_u32(v14, 8);
          else
            (w_u32(v14, ((sint32)r_u32(v14) - 1u)), (sint32)r_u32(v14));
            goto LABEL_59;

          case 2:
            if (((sint32)r_u32(v14) == 8))
            w_u32(v14, (sint32)(0u - (uint32)(1)));
          else
            (w_u32(v14, ((sint32)r_u32(v14) + 1u)), (sint32)r_u32(v14));
            goto LABEL_59;

          case 5:
            if (((sint32)r_u32(v14) == (sint32)(0u - (uint32)(1))))
          {
            v3 = 1;
            w_u32((0x8009d028u + (v12) * 4u), 2);
            v17 = 0;
            v18 = 0x8009d028u;
            do
            {
              if (((sint32)r_u32(v18) != 2))
                v3 = 0;
              ++v17;
              ((v18 += 4u));
            }
            while (((sint32)(v17) < (sint32)(v7)));
            ++v9;
          }
          else
          {
            ++v9;
            ob_clear_button_edges();
            w_u32((0x8009d028u + (v12) * 4u), 3);
          }
            break;

          case 6:
            w_u32(r_u32((uint32)(v11)), 3);
            w_u32((uint32)(((uint32)(r_u32((uint32)(v11))) + (uint32)(4))), 4);
            w_u32((uint32)(((uint32)(r_u32((uint32)(v11))) + (uint32)(8))), 6);
            w_u32((uint32)(((uint32)(r_u32((uint32)(v11))) + (uint32)(12))), 7);
            w_u32((uint32)(((uint32)(r_u32((uint32)(v11))) + (uint32)(16))), 5);
            w_u32((uint32)(((uint32)(r_u32((uint32)(v11))) + (uint32)(20))), 14);
            w_u32((uint32)(((uint32)(r_u32((uint32)(v11))) + (uint32)(24))), 13);
            w_u32((uint32)(((uint32)(r_u32((uint32)(v11))) + (uint32)(28))), 12);
            w_u32((uint32)(((uint32)(r_u32((uint32)(v11))) + (uint32)(32))), 15);
            w_u32((uint32)(((uint32)(r_u32((uint32)(v11))) + (uint32)(36))), 10);
            w_u32((uint32)(((uint32)(r_u32((uint32)(v11))) + (uint32)(40))), 11);
            w_u32((uint32)(((uint32)(r_u32((uint32)(v11))) + (uint32)(44))), 8);
            w_u32((uint32)(((uint32)(r_u32((uint32)(v11))) + (uint32)(48))), 9);
            w_u32((uint32)(((uint32)(r_u32((uint32)(v11))) + (uint32)(52))), 14);
            w_u32((0x8009cf5cu + (v10) * 4u), 4);
            w_u32((0x8009cf58u + (v10) * 4u), 11);
            w_u32((0x8009cf60u + (v10) * 4u), 6);
            w_u32((0x8009cf64u + (v10) * 4u), 14);
            w_u32((0x8009cf68u + (v10) * 4u), 13);
            w_u32((0x8009cf6cu + (v10) * 4u), 15);
            w_u32((0x8009cf70u + (v10) * 4u), 8);
            w_u32((0x8009cf74u + (v10) * 4u), 9);
            w_u32((0x8009cf78u + (v10) * 4u), 10);
            ++v9;
            break;

          case 7:
            goto LABEL_58;

          case 8:
            v3 = 1;
            v19 = 0;
            w_u32(v14, (sint32)(0u - (uint32)(1)));
            w_u32(v13, 2);
            v20 = 0x8009d028u;
            do
          {
            if (((sint32)r_u32(v20) != 2))
              v3 = 0;
            ++v19;
            ((v20 += 4u));
          }
          while (((sint32)(v19) < (sint32)(v7)));
            ++v9;
            break;

          default:
            goto LABEL_59;

        }

      }
      else
      {
        ++v9;
      }
      LABEL_60:
      v10 = ((uint32)(v10) + (uint32)(9));

      v11 = ((uint32)(v11) + (uint32)(4));
      ++v12;
      ((v13 += 4u));
      ++v8;
      ((v14 += 4u));
    }
    while (((sint32)(v8) < (sint32)(v7)));
    ob_front_800993B4(v7);
  }
  while (!v3);
  return ob_init_card_tables();
}


uint32 ob_front_80098298(uint32 a1)
{
    FUNCTION_MARKER(0x80098298u, "FRONT.BIN");
    /* TODO: Bind original external target 0x800541a8 */
    /* TODO: Bind original external target 0x8005c504 */
  sint32 v2;
  uint32 v3;
  sint32 v4;
  uint32 v5;
  sint32 v6;
  sint32 v7;
  sint32 v8;
  uint32 v9;
  uint32 v10;
  sint32 v11;
  sint32 v12;
  sint32 v13;
  sint32 v14;
  uint32 v15;
  sint32 v16;
  uint32 v17;
  sint32 v18;
  sint32 v19;
  uint32 v20;
  uint32 v21;
  sint32 v22;
  uint32 v23;
  sint32 v24;
  sint32 v25;
  uint32 v26;
  sint32 v27;
  sint32 v28;
  uint32 v29;
  sint32 v30;
  sint32 v31;
  sint32 v32;
  uint32 v33;
  uint32 v34;
  sint32 v35;
  sint32 v36;
  uint32 v37;
  sint32 v39;
  sint32 v40;
  uint32 v41;
  v40 = 0;
  ob_clear_button_edges();
  v2 = 0;
  w_u32(0x8009d054u, 0);
  v39 = 0;
  if (((sint32)(a1) > (sint32)(0)))
  {
    v3 = (0x8009cf58u);
    do
    {
      v4 = 0;
      v5 = v3;
      do
        w_u32(((v5 += 4u) - 4u), ob_front_80099890(v2, v4++));
      while (((sint32)(v4) < (sint32)(9)));
      ++v2;
      v3 += (9) * 4u;
    }
    while (((sint32)(v2) < (sint32)(a1)));
  }
  ob_draft_unresolved_call(0x800541a8u, 1u, 0);
  ob_draft_unresolved_call(0x800541a8u, 1u, 4);
  sub_80021B20((sint32)(0u - (uint32)(2147046728)));
  w_u32(0x80073518u, 0x80021C24u);
  v6 = 1;
  if ((ob_draft_unresolved_call(0x800541a8u, 1u, 0) || ((v6 = 2), ob_draft_unresolved_call(0x800541a8u, 1u, 4))))
  {
    w_u32(0x8006C130, v6);
    v7 = 5;
  }
  else
  {
    v7 = 2;
    w_u32(0x8006C130, 0);
  }
  v8 = 0;
  v9 = 0x8009d010u;
  v10 = 0x8009cf40u;
  do
  {
    v11 = v8;
    if ((v7 == 2))
      v11 = (sint32)((uint32)(4) * (uint32)(v8));
    if (ob_controller_slot_ready(v11))
      w_u32(v10, 1);
    else
      w_u32(v10, 0);
    w_u32(((v9 += 4u) - 4u), 0);
    ++v8;
    ((v10 += 4u));
  }
  while (((sint32)(v8) < (sint32)(v7)));
  LABEL_18:
  v12 = 1;

  if ((ob_draft_unresolved_call(0x800541a8u, 1u, 0) || ((v12 = 2), ob_draft_unresolved_call(0x800541a8u, 1u, 4))))
  {
    w_u32(0x8006C130, v12);
    v13 = 5;
  }
  else
  {
    v12 = 0;
    v13 = 2;
    w_u32(0x8006C130, 0);
  }
  v14 = 0;
  ob_snapshot_controller_flags();
  sub_8002D25C((sint32)(0u - (uint32)(2146906416)), (sint32)(0u - (uint32)(2146931856)));
  front_c_solid_quad(40u, 36u, 304u, 190u);
  sub_8001FC60();
  sub_80012184();
  v15 = 0x8009cf40u;
  v16 = 0;
  v17 = 0x8009d010u;
  v18 = (sint32)(0u - (uint32)(2147040709));
  while (2)
  {
    if ((((uint32)((sint32)((uint32)(v14) - (uint32)(1))) < 3) && (v12 == 2)))
    {
      w_u8((uint32)(v18), (sint32)((uint32)(v14) + (uint32)(4)));
    }
    else
      if (v12)
    {
      w_u8((uint32)(v18), v14);
    }
    else
    {
      w_u8((uint32)(v18), (sint32)((uint32)(v16) * (uint32)(4)));
    }
    v41 = v17;
    v19 = ob_front_800996B8((sint8)r_u8((uint32)(v18)));
    v20 = v41;
    switch (v19)
    {
      case 1:
        if (((sint32)r_u32(v15) != 1))
        goto LABEL_71;
        v21 = ((0x8009d010u + (v16) * 4u));
        if (v14)
      {
        if (!((sint32)r_u32(v21)))
          goto LABEL_44;
        w_u32(v21, 0);
      }
      else
        if ((sint32)r_u32((0x8009d010u + (0) * 4u)))
      {
        (w_u32((0x8009d010u + (0) * 4u), ((sint32)r_u32((0x8009d010u + (0) * 4u)) - 1u)), (sint32)r_u32((0x8009d010u + (0) * 4u)));
      }
      else
      {
        w_u32((0x8009d010u + (0) * 4u), 2);
      }
        goto LABEL_71;

      case 2:
        if (((sint32)r_u32(v15) == 1))
      {
        v21 = ((0x8009d010u + (v16) * 4u));
        if (v14)
        {
          if ((sint32)r_u32(v21))
            w_u32(v21, 0);
          else
            LABEL_44:
          w_u32(v21, 1);

        }
        else
          if (((sint32)r_u32((0x8009d010u + (0) * 4u)) == 2))
        {
          w_u32((0x8009d010u + (0) * 4u), 0);
        }
        else
        {
          (w_u32((0x8009d010u + (0) * 4u), ((sint32)r_u32((0x8009d010u + (0) * 4u)) + 1u)), (sint32)r_u32((0x8009d010u + (0) * 4u)));
        }
      }
        goto LABEL_71;

      case 5:
        if (((sint32)r_u32(v41) == 2))
      {
        ob_front_80099AF4();
        v20 = v41;
        ((v15 += 4u));
      }
      else
      {
        w_u32((0x8009cf40u + (v16) * 4u), 2);
        v22 = 0;
        v23 = 0x8009cf40u;
        do
        {
          ++v22;
          ((v23 += 4u));
        }
        while (((sint32)(v22) < (sint32)(v13)));
        ((v15 += 4u));
      }
        goto LABEL_72;

      case 7:
        v27 = 0;
        if (!v14)
      {
        v28 = 0;
        v29 = 0x8009cf40u;
        do
        {
          if (((sint32)r_u32(v29) == 2))
            ++v27;
          ++v28;
          ((v29 += 4u));
        }
        while (((sint32)(v28) < (sint32)(v13)));
        if ((((sint32)r_u32((0x8009cf40u + (0) * 4u)) == 2) && ((sint32)(v27) >= (sint32)(2))))
          w_u32(0x8009d054u, 1);
      }
        goto LABEL_71;

      case 8:
        if (((sint32)r_u32(v15) == 2))
      {
        w_u32(v15, 1);
        v24 = 0;
        v25 = 0;
        v26 = 0x8009cf40u;
        do
        {
          if (((sint32)r_u32(v26) == 2))
            ++v25;
          ++v24;
          ((v26 += 4u));
        }
        while (((sint32)(v24) < (sint32)(v13)));
        if (((sint32)(v25) < (sint32)(2)))
        {
          w_u32(0x8009d054u, 0);
          ((v15 += 4u));
          goto LABEL_72;
        }
      }
      else
        if (!v14)
      {
        v39 = 1;
      }
        LABEL_71:
      ((v15 += 4u));

        LABEL_72:
      ++v16;

        v17 = (v20 + (1) * 4u);
        ++v14;
        ++v18;
        if (((sint32)(v14) < (sint32)(v13)))
        continue;
        v30 = 0;
        if (((sint32)r_u32(0x8009d054u) != 1))
        goto LABEL_88;
        w_u8(0x8006C235, 0);
        v31 = 0;
        v32 = (sint32)(0u - (uint32)(2147040714));
        v33 = 0x8009cf40u;
        v34 = 0x8009d010u;
        do
      {
        if (((sint32)r_u32(v34) == 1))
          v30 = 1;
        if (((sint32)r_u32(v33) == 2))
        {
          w_u8((uint32)(v32), 1);
          (w_u8(0x8006C235, (r_u8(0x8006C235) + 1u)), r_u8(0x8006C235));
        }
        else
        {
          w_u8((uint32)(v32), 0);
        }
        ++v32;
        ((v33 += 4u));
        ++v31;
        ((v34 += 4u));
      }
      while (((sint32)(v31) < (sint32)(v13)));
        if (v30)
      {
        ob_front_80098DFC(v13);
        v36 = 0;
        v37 = 0x8009d010u;
        do
        {
          w_u32(v37, 0);
          ++v36;
          ((v37 += 4u));
        }
        while (((sint32)(v36) < (sint32)(v13)));
        w_u32(0x8009d054u, 0);
        LABEL_88:
        v35 = v13;

      }
      else
      {
        v40 = 1;
        w_u8(0x8006C230, 5);
        v35 = v13;
      }
        ob_front_800988BC(v35);
        while ((sint32)r_u32(0x80077620))
      ob_native_pump();

        ob_draft_unresolved_call(0x8005c504u, 1u, 0);
        w_u32(0x8007754C, (sint32)r_u32(0x8007737C));
        ob_switch_frame_buffer();
        w_u32(0x80077620, 1);
        if ((!v39 && !v40))
        goto LABEL_18;
        ob_init_card_tables();
        return (v39 ^ 1);

      default:
        goto LABEL_71;

    }

  }

}


