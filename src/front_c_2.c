#include "front_signatures.h"
#include "native_runtime.h"
#include <stdint.h>

/* Unverified FRONT draft */
/* TODO: Main cleanup aliases still require obsolete guest SP context; pass actual object only */

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

uint32 ob_front_80099AF4(void)
{
    FUNCTION_MARKER(0x80099af4u, "FRONT.BIN");
    /* TODO: Bind original external target 0x8005c504 */
  sint32 v0;
  sint32 v1;
  sint32 v2;
  uint32 v3;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  sint32 v7;
  uint32 v8;
  sint32 v9;
  uint32 v10;
  sint16 v11;
  uint32 v12;
  sint32 v13;
  sint32 v14;
  sint32 v15;
  sint32 v16;
  uint32 v17;
  sint32 result;
  sint32 v19;
  v0 = 0;
  v1 = 0;
  v2 = 0;
  v19 = 0;
  ob_clear_button_edges();
  do
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
    front_c_solid_quad(40u, 36u, 132u, 176u);
    if ((v0 == 1))
    {
      if (!ob_front_800947EC(0xCu))
      {
        if (ob_front_800947EC(7u))
        {
          if ((sint32)r_u32(0x8006C247))
            (w_u32(0x8006C247, ((sint32)r_u32(0x8006C247) - 1u)), (sint32)r_u32(0x8006C247));
          else
            w_u32(0x8006C247, 9);
        }
        else
          if (ob_front_800947EC(5u))
        {
          if (((sint32)r_u32(0x8006C247) == 9))
            w_u32(0x8006C247, 0);
          else
            (w_u32(0x8006C247, ((sint32)r_u32(0x8006C247) + 1u)), (sint32)r_u32(0x8006C247));
        }
        goto LABEL_98;
      }
      goto LABEL_55;
    }
    if (((sint32)(v0) >= (sint32)(2)))
    {
      if (!ob_front_800947EC(0xCu))
      {
        if (ob_front_800947EC(4u))
        {
          v3 = ((sint32)(v2--) > (sint32)(0));
          if (!v3)
            v2 = 2;
          goto LABEL_98;
        }
        v3 = (ob_front_800947EC(6u) == 0);
        v7 = ((sint32)(v2) < (sint32)(2));
        if (!v3)
        {
          ++v2;
          if (!v7)
            v2 = 0;
          goto LABEL_98;
        }
        if (ob_front_800947EC(7u))
        {
          if ((v2 == 1))
          {
            v8 = (uint32)((sint32)((uint32)((sint32)r_u32(0x8009cf38u)) - (uint32)(2147040684)));
            if (r_u8((uint32)((sint32)((uint32)((sint32)r_u32(0x8009cf38u)) - (uint32)(2147040684)))))
              w_u8(v8, ((uint32)(r_u8((uint32)((sint32)((uint32)((sint32)r_u32(0x8009cf38u)) - (uint32)(2147040684))))) - (uint32)(1)));
            else
              w_u8(v8, 5);
            goto LABEL_98;
          }
          if (((sint32)(v2) < (sint32)(2)))
          {
            v5 = 2;
            if (!v2)
            {
              if ((sint32)r_u32(0x8009cf38u))
                (w_u32(0x8009cf38u, ((sint32)r_u32(0x8009cf38u) - 1u)), (sint32)r_u32(0x8009cf38u));
              else
                w_u32(0x8009cf38u, 7);
              v5 = 2;
            }
            goto LABEL_99;
          }
          v5 = 2;
          if ((v2 != 2))
            goto LABEL_99;
          v9 = ob_front_8009B4E4((sint32)r_u32(0x8009cf38u));
          v5 = 2;
          if (((sint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)(v9))) - (uint32)(2147040694))))) <= (sint32)(0)))
            goto LABEL_99;
          if ((r_u16((uint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)(ob_front_8009B4E4((sint32)r_u32(0x8009cf38u))))) - (uint32)(2147040694)))) == 999))
          {
            v10 = (uint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)(ob_front_8009B4E4((sint32)r_u32(0x8009cf38u))))) - (uint32)(2147040694)));
            v11 = (sint32)((uint32)((sint16)r_u16(v10)) - (uint32)(49));
          }
          else
          {
            v10 = (uint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)(ob_front_8009B4E4((sint32)r_u32(0x8009cf38u))))) - (uint32)(2147040694)));
            v11 = (sint32)((uint32)((sint16)r_u16(v10)) - (uint32)(50));
          }
        }
        else
        {
          if (!ob_front_800947EC(5u))
            goto LABEL_98;
          if ((v2 == 1))
          {
            v12 = (uint32)((sint32)((uint32)((sint32)r_u32(0x8009cf38u)) - (uint32)(2147040684)));
            if ((r_u8((uint32)((sint32)((uint32)((sint32)r_u32(0x8009cf38u)) - (uint32)(2147040684)))) == 5))
              w_u8(v12, 0);
            else
              w_u8(v12, ((uint32)(r_u8((uint32)((sint32)((uint32)((sint32)r_u32(0x8009cf38u)) - (uint32)(2147040684))))) + (uint32)(1)));
            goto LABEL_98;
          }
          if (((sint32)(v2) < (sint32)(2)))
          {
            if (v2)
            {
              v5 = 2;
            }
            else
            {
              if (((sint32)r_u32(0x8009cf38u) == 7))
                w_u32(0x8009cf38u, 0);
              else
                (w_u32(0x8009cf38u, ((sint32)r_u32(0x8009cf38u) + 1u)), (sint32)r_u32(0x8009cf38u));
              v5 = 2;
            }
            goto LABEL_99;
          }
          v5 = 2;
          if ((v2 != 2))
            goto LABEL_99;
          v13 = ob_front_8009B4E4((sint32)r_u32(0x8009cf38u));
          v5 = 2;
          if (((sint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)(v13))) - (uint32)(2147040694))))) >= (sint32)(999)))
            goto LABEL_99;
          v14 = ob_front_8009B4E4((sint32)r_u32(0x8009cf38u));
          v15 = (sint32)r_u32(0x8009cf38u);
          w_u16((uint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)(v14))) - (uint32)(2147040694))), ((uint32)(r_u16((uint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)(v14))) - (uint32)(2147040694))))) + (uint32)(50)));
          v16 = ob_front_8009B4E4(v15);
          v5 = 2;
          if (((sint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)(v16))) - (uint32)(2147040694))))) < (sint32)(1000)))
            goto LABEL_99;
          v10 = (uint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)(ob_front_8009B4E4((sint32)r_u32(0x8009cf38u))))) - (uint32)(2147040694)));
          v11 = 999;
        }
        w_u16(v10, v11);
        goto LABEL_98;
      }
      LABEL_55:
      v0 = 0;

      ob_clear_button_edges();
      v5 = 0;
      goto LABEL_99;
    }
    if (ob_front_800947EC(0xCu))
    {
      v19 = 1;
      goto LABEL_98;
    }
    if (ob_front_800947EC(4u))
    {
      v3 = ((sint32)(v1--) > (sint32)(0));
      if (!v3)
        v1 = 5;
      goto LABEL_98;
    }
    v3 = (ob_front_800947EC(6u) == 0);
    v4 = ((sint32)(v1) < (sint32)(5));
    if (!v3)
    {
      ++v1;
      if (!v4)
        v1 = 0;
      goto LABEL_98;
    }
    if (ob_front_800947EC(0xEu))
    {
      if ((v1 == 4))
      {
        v0 = 1;
        goto LABEL_20;
      }
      if (((sint32)(v1) >= (sint32)(5)))
      {
        v5 = 0;
        if ((v1 != 5))
          goto LABEL_99;
        v0 = 2;
        LABEL_20:
        v2 = 0;

        ob_clear_button_edges();
        v5 = v0;
        LABEL_99:
        v6 = v1;

        goto LABEL_100;
      }
      LABEL_98:
      v5 = v0;

      goto LABEL_99;
    }
    if (ob_front_800947EC(7u))
    {
      switch (v1)
      {
        case 0:
          if (((sint32)r_u32(0x8006C246) == 1))
          w_u32(0x8006C246, 9);
        else
          (w_u32(0x8006C246, ((sint32)r_u32(0x8006C246) - 1u)), (sint32)r_u32(0x8006C246));
          goto LABEL_98;

        case 1:
          if ((sint32)r_u32(0x8006C248))
          (w_u32(0x8006C248, ((sint32)r_u32(0x8006C248) - 1u)), (sint32)r_u32(0x8006C248));
        else
          w_u32(0x8006C248, 7);
          goto LABEL_98;

        case 2:
          v5 = 0;
          if (((sint32)r_u32(0x8006C240) == 1))
          w_u32(0x8006C240, 0);
          goto LABEL_99;

        case 3:
          v5 = 0;
          if ((r_u8(0x8006C249) != 1))
          goto LABEL_99;
          w_u8(0x8006C249, 0);
          v6 = v1;
          break;

        default:
          goto LABEL_98;

      }

    }
    else
    {
      if (!ob_front_800947EC(5u))
        goto LABEL_98;
      switch (v1)
      {
        case 0:
          if (((sint32)r_u32(0x8006C246) == 9))
          w_u32(0x8006C246, 1);
        else
          (w_u32(0x8006C246, ((sint32)r_u32(0x8006C246) + 1u)), (sint32)r_u32(0x8006C246));
          goto LABEL_98;

        case 1:
          if (((sint32)r_u32(0x8006C248) == 7))
          w_u32(0x8006C248, 0);
        else
          (w_u32(0x8006C248, ((sint32)r_u32(0x8006C248) + 1u)), (sint32)r_u32(0x8006C248));
          goto LABEL_98;

        case 2:
          v5 = 0;
          if (!(sint32)r_u32(0x8006C240))
          w_u32(0x8006C240, 1);
          goto LABEL_99;

        case 3:
          v5 = 0;
          if (r_u8(0x8006C249))
          goto LABEL_99;
          w_u8(0x8006C249, 1);
          v6 = v1;
          break;

        default:
          goto LABEL_98;

      }

    }
    LABEL_100:
    ob_front_8009A248(v5, v6, v2);

    if (v0)
    {
      if ((v0 == 1))
        v17 = (sint32)r_u32(0x8009c728u);
      else
        v17 = (sint32)r_u32(0x8009c7bcu);
    }
    else
    {
      v17 = (sint32)r_u32(0x8009c600u);
      if (((sint32)(v1) >= (sint32)(4)))
        v17 = (sint32)r_u32(0x8009c694u);
    }
    result = ob_front_80093E70(v17);
  }
  while (!v19);
  return result;
}


uint32 ob_front_80091920(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80091920u, "FRONT.BIN");
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
      sub_80021460((sint32)(0u - (uint32)(2147044300)), 0, 0, 32, 0x20u, 0xf4u, 0x24u, 0u);
      v5 = (sint32)(0u - (uint32)(2147044296));
      v6 = 16;
    }
    else
    {
      result = 2;
      if ((((sint32)(v4) < (sint32)(2)) || (v4 != 2)))
        return result;
      sub_80021460((sint32)(0u - (uint32)(2147044300)), 0, 0, 32, 0x40u, 0x114u, 0x18u, 0u);
      sub_80021460((sint32)(0u - (uint32)(2147044296)), 0, 0, 16, 0x40u, 0x134u, 0x18u, 0u);
      sub_80021460((sint32)(0u - (uint32)(2147044324)), 0, 0, 32, 0x20u, 0x154u, 0x38u, 0u);
      sub_80021460((sint32)(0u - (uint32)(2147044320)), 0, 0, 32, 0x20u, 0x12cu, 0x58u, 0u);
      sub_80021460((sint32)(0u - (uint32)(2147044316)), 0, 0, 32, 0x20u, 0x14cu, 0x58u, 0u);
      v5 = (sint32)(0u - (uint32)(2147044312));
      v6 = 32;
    }
    return sub_80021460(v5, 0, 0, v6, 0x10u, 0x13eu, 0x78u, 0u);
  }
  v2 = r_u32((uint32)((sint32)((uint32)(a2) + (uint32)(8))));
  result = ((sint32)(v2) < (sint32)(2));
  if ((v2 == 1))
  {
    sub_80021460((sint32)(0u - (uint32)(2147044292)), 0, 0, 32, 0x20u, 0xf4u, 0x24u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044288)), 0, 0, 32, 0x40u, 0x114u, 0x18u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044284)), 0, 0, 32, 0x40u, 0x134u, 0x18u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044280)), 0, 0, 16, 0x20u, 0x154u, 0x38u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044276)), 0, 0, 32, 0x20u, 0x12cu, 0x58u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044272)), 0, 0, 32, 0x20u, 0x14cu, 0x58u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044268)), 0, 0, 32, 0x10u, 0x13eu, 0x78u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044308)), 0, 0, 32, 0x40u, 0x137u, 0x16u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044304)), 0, 0, 16, 0x40u, 0x157u, 0x16u, 0u);
    return ob_front_8008E65C(20, (sint32)(0x8008d1b4u), (sint32)(0x8008d1c8u));
  }
  else
    if (((sint32)(v2) >= (sint32)(2)))
  {
    result = 2;
    if ((v2 == 2))
    {
      sub_80021460((sint32)(0u - (uint32)(2147044292)), 0, 0, 32, 0x20u, 0xf4u, 0x24u, 0u);
      sub_80021460((sint32)(0u - (uint32)(2147044288)), 0, 0, 32, 0x40u, 0x114u, 0x18u, 0u);
      sub_80021460((sint32)(0u - (uint32)(2147044284)), 0, 0, 32, 0x40u, 0x134u, 0x18u, 0u);
      sub_80021460((sint32)(0u - (uint32)(2147044280)), 0, 0, 16, 0x20u, 0x154u, 0x38u, 0u);
      sub_80021460((sint32)(0u - (uint32)(2147044276)), 0, 0, 32, 0x20u, 0x12cu, 0x58u, 0u);
      sub_80021460((sint32)(0u - (uint32)(2147044272)), 0, 0, 32, 0x20u, 0x14cu, 0x58u, 0u);
      sub_80021460((sint32)(0u - (uint32)(2147044268)), 0, 0, 32, 0x10u, 0x13eu, 0x78u, 0u);
      sub_80021460((sint32)(0u - (uint32)(2147044308)), 0, 0, 32, 0x40u, 0x137u, 0x16u, 0u);
      sub_80021460((sint32)(0u - (uint32)(2147044304)), 0, 0, 16, 0x40u, 0x157u, 0x16u, 0u);
      sub_80021460((sint32)(0u - (uint32)(2147044340)), 0, 0, 32, 0x40u, 0xf4u, 0x1cu, 0u);
      sub_80021460((sint32)(0u - (uint32)(2147044336)), 0, 0, 32, 0x40u, 0x114u, 0x16u, 0u);
      sub_80021460((sint32)(0u - (uint32)(2147044332)), 0, 0, 32, 0x40u, 0x134u, 0x14u, 0u);
      sub_80021460((sint32)(0u - (uint32)(2147044328)), 0, 0, 32, 0x40u, 0x154u, 0x14u, 0u);
      return ob_front_8008E65C(20, (sint32)(0x8008d1b4u), (sint32)(0x8008d1d0u));
    }
  }
  else
    if (!v2)
  {
    sub_80021460((sint32)(0u - (uint32)(2147044292)), 0, 0, 32, 0x40u, 0x137u, 0x16u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044288)), 0, 0, 32, 0x40u, 0x137u, 0x16u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044284)), 0, 0, 32, 0x40u, 0x157u, 0x16u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044280)), 0, 0, 16, 0x40u, 0xf4u, 0x1cu, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044276)), 0, 0, 32, 0x40u, 0x114u, 0x16u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044272)), 0, 0, 32, 0x40u, 0x134u, 0x14u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044268)), 0, 0, 32, 0x40u, 0x154u, 0x14u, 0u);
    return ob_front_8008E65C(20, (sint32)(0x8008d1b4u), (sint32)(0x8008d1c0u));
  }
  return result;
}


uint32 ob_front_8009A2E4(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8009a2e4u, "FRONT.BIN");
    /* TODO: Bind original external target 0x80064028 */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Recover original call carrier Call operand s2 */
    /* TODO: Recover original call carrier Call operand s6 */
    uint32 local_objects = ob_draft_scratch_acquire(16u);
    uint32 literal_0 = ob_draft_scratch_acquire(3u);
    w_u8(literal_0 + 0u, 37u);
    w_u8(literal_0 + 1u, 100u);
    w_u8(literal_0 + 2u, 0u);
  sint32 v3;
  sint32 v4;
  uint32 v5;
  sint32 v6;
  uint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  sint32 v11;
  uint32 v12;
  sint32 v13;
  uint32 v14;
  sint32 v15;
  sint32 v16;
  uint32 v17;
  sint32 v18;
  uint32 v19;
  sint32 v20;
  ;
  if (a1)
  {
    ob_front_80094488((uint32)(0x8008d9c8u), 50, 0x32u, 0x2du, 0x28u, 0x16u, 0u);
    ob_draft_unresolved_call(0x80064028u, 3u, (local_objects + 0u), literal_0, r_u8(0x8006C246));
    v3 = ob_front_800946F0((local_objects + 0u));
    ob_front_80094488((local_objects + 0u), (sint32)((uint32)(162) - (uint32)(v3)), 0x32u, 0x2du, 0x28u, 0x16u, 0u);
    ob_front_80094488((uint32)(0x8008d9d4u), 50, 0x4bu, 0x2du, 0x28u, 0x16u, 0u);
    if (r_u8(0x8006C248))
      ob_draft_unresolved_call(0x80064028u, 4u, (local_objects + 0u), 0x8008d9e0u, ((sint32)((sint32)((uint32)((sint32)((uint32)(30) * (uint32)(((uint32)(r_u8(0x8006C248)) - (uint32)(1))))) + (uint32)(60))) / (sint32)(60)), ((sint32)((sint32)((uint32)((sint32)((uint32)(30) * (uint32)(((uint32)(r_u8(0x8006C248)) - (uint32)(1))))) + (uint32)(60))) % (sint32)(60)));
    else
      ob_draft_unresolved_call(0x80064028u, 2u, (local_objects + 0u), 0x8008d9dcu);
    v4 = ob_front_800946F0((local_objects + 0u));
    ob_front_80094488((local_objects + 0u), (sint32)((uint32)(162) - (uint32)(v4)), 0x4bu, 0x2du, 0x28u, 0x16u, 0u);
    ob_front_80094488((uint32)(0x8008d9e8u), 50, (0x4bu + 0x19u), 0x2du, 0x28u, 0x16u, 0u);
    v5 = 0x8008d9f4u;
    if (!r_u8(0x8006C240))
      v5 = 0x8008d9dcu;
    v6 = ob_front_800946F0((uint32)(v5));
    ob_front_80094488((uint32)(v5), (sint32)((uint32)(162) - (uint32)(v6)), (0x4bu + 0x19u), 0x2du, 0x28u, 0x16u, 0u);
    ob_front_80094488((uint32)(0x8008d9f8u), 50, ((0x4bu + 0x19u) + 0x19u), 0x2du, 0x28u, 0x16u, 0u);
    v7 = 0x8008d9f4u;
    if (!r_u8(0x8006C249))
      v7 = 0x8008d9dcu;
    v8 = ob_front_800946F0((uint32)(v7));
    ob_front_80094488((uint32)(v7), (sint32)((uint32)(162) - (uint32)(v8)), ((0x4bu + 0x19u) + 0x19u), 0x2du, 0x28u, 0x16u, 0u);
    ob_front_80094488((uint32)(0x8008da04u), 50, (((0x4bu + 0x19u) + 0x19u) + 0x19u), 0x2du, 0x28u, 0x16u, 0u);
    { uint32 draft_return = ob_front_80094488(0x8008DA0Cu, 50u, 175u, 45u, 40u, 22u, 0u); ob_draft_scratch_release(local_objects); ob_draft_scratch_release(literal_0);  return draft_return; }
  }
  ob_front_80094488((uint32)(0x8008d9c8u), 50, 0x32u, 0x2du, 0x28u, 0x16u, 0u);
  ob_draft_unresolved_call(0x80064028u, 3u, (local_objects + 0u), literal_0, r_u8(0x8006C246));
  v9 = ob_front_800946F0((local_objects + 0u));
  ob_front_80094488((local_objects + 0u), (sint32)((uint32)(162) - (uint32)(v9)), 0x32u, 0x2du, 0x28u, 0x16u, 0u);
  if ((a2 == 1))
  {
    ob_front_80094488((uint32)(0x8008d9d4u), 50, ((((0x4bu + 0x19u) + 0x19u) + 0x19u) + 0x19u), 0x5bu, 0xfu, 0x8u, 0u);
    if (r_u8(0x8006C248))
      goto LABEL_15;
    LABEL_14:
    ob_draft_unresolved_call(0x80064028u, 2u, (local_objects + 0u), 0x8008d9dcu);

    goto LABEL_16;
  }
  ob_front_80094488((uint32)(0x8008d9d4u), 50, ((((0x4bu + 0x19u) + 0x19u) + 0x19u) + 0x19u), 0x2du, 0x28u, 0x16u, 0u);
  if (!r_u8(0x8006C248))
    goto LABEL_14;
  LABEL_15:
  ob_draft_unresolved_call(0x80064028u, 4u, (local_objects + 0u), 0x8008d9e0u, ((sint32)((sint32)((uint32)((sint32)((uint32)(30) * (uint32)(((uint32)(r_u8(0x8006C248)) - (uint32)(1))))) + (uint32)(60))) / (sint32)(60)), ((sint32)((sint32)((uint32)((sint32)((uint32)(30) * (uint32)(((uint32)(r_u8(0x8006C248)) - (uint32)(1))))) + (uint32)(60))) % (sint32)(60)));

  LABEL_16:
  v10 = (sint32)((uint32)(162) - (uint32)(ob_front_800946F0((local_objects + 0u))));

  ob_front_80094488((local_objects + 0u), v10, ((((0x4bu + 0x19u) + 0x19u) + 0x19u) + 0x19u), 0x2du, 0x28u, 0x16u, 0u);
  if ((a2 == 2))
  {
    ob_front_80094488((uint32)(0x8008d9e8u), 50, (((((0x4bu + 0x19u) + 0x19u) + 0x19u) + 0x19u) + 0x19u), 0x5bu, 0xfu, 0x8u, 0u);
    if (r_u8(0x8006C240))
    {
      v11 = ob_front_800946F0((uint32)(0x8008d9f4u));
      v12 = 0x8008d9f4u;
    }
    else
    {
      v11 = ob_front_800946F0((uint32)(0x8008d9dcu));
      v12 = 0x8008d9dcu;
    }
    v13 = (sint32)((uint32)(162) - (uint32)(v11));
  }
  else
  {
    ob_front_80094488((uint32)(0x8008d9e8u), 50, (((((0x4bu + 0x19u) + 0x19u) + 0x19u) + 0x19u) + 0x19u), 0x2du, 0x28u, 0x16u, 0u);
    v14 = 0x8008d9f4u;
    if (!r_u8(0x8006C240))
      v14 = 0x8008d9dcu;
    v15 = ob_front_800946F0((uint32)(v14));
    v12 = v14;
    v13 = (sint32)((uint32)(162) - (uint32)(v15));
  }
  ob_front_80094488((uint32)(v12), v13, (((((0x4bu + 0x19u) + 0x19u) + 0x19u) + 0x19u) + 0x19u), 0x2du, 0x28u, 0x16u, 0u);
  if ((a2 == 3))
  {
    ob_front_80094488((uint32)(0x8008d9f8u), 50, ((((((0x4bu + 0x19u) + 0x19u) + 0x19u) + 0x19u) + 0x19u) + 0x19u), 0x5bu, 0xfu, 0x8u, 0u);
    if (r_u8(0x8006C249))
    {
      v16 = ob_front_800946F0((uint32)(0x8008d9f4u));
      v17 = 0x8008d9f4u;
    }
    else
    {
      v16 = ob_front_800946F0((uint32)(0x8008d9dcu));
      v17 = 0x8008d9dcu;
    }
    v18 = (sint32)((uint32)(162) - (uint32)(v16));
  }
  else
  {
    ob_front_80094488((uint32)(0x8008d9f8u), 50, ((((((0x4bu + 0x19u) + 0x19u) + 0x19u) + 0x19u) + 0x19u) + 0x19u), 0x2du, 0x28u, 0x16u, 0u);
    v19 = 0x8008d9f4u;
    if (!r_u8(0x8006C249))
      v19 = 0x8008d9dcu;
    v20 = ob_front_800946F0((uint32)(v19));
    v17 = v19;
    v18 = (sint32)((uint32)(162) - (uint32)(v20));
  }
  ob_front_80094488((uint32)(v17), v18, ((((((0x4bu + 0x19u) + 0x19u) + 0x19u) + 0x19u) + 0x19u) + 0x19u), 0x2du, 0x28u, 0x16u, 0u);
  ob_front_80094488((uint32)(0x8008da04u), 50, (((((((0x4bu + 0x19u) + 0x19u) + 0x19u) + 0x19u) + 0x19u) + 0x19u) + 0x19u), 0x5bu, 0xfu, 0x8u, 0u);
  if ((a2 == 4))
    ob_front_8009AB74(1);
  if ((a2 == 5))
  {
    ob_front_80094488((uint32)(0x8008da0cu), 50, (((((((0x4bu + 0x19u) + 0x19u) + 0x19u) + 0x19u) + 0x19u) + 0x19u) + 0x19u), 0x2du, 0x28u, 0x16u, 0u);
    { uint32 draft_return = ob_front_8009AE68(1, 0); ob_draft_scratch_release(local_objects); ob_draft_scratch_release(literal_0);  return draft_return; }
  }
  { uint32 draft_return = ob_front_80094488(0x8008DA0Cu, 50u, 175u, 45u, 40u, 22u, 0u); ob_draft_scratch_release(local_objects); ob_draft_scratch_release(literal_0);  return draft_return; }
}


