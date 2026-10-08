#include "front_signatures.h"
#include "native_runtime.h"

uint32 ob_front_a_callback(uint32 target,uint32 available,uint32 first,uint32 second);

uint32 ob_front_8008E380(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8008e380u, "FRONT.BIN");
  sint32 v2;
  sint32 v3;
  if ((r_u32((uint32)(((uint32)(a1) + (uint32)(12)))) == a2))
  {
    v2 = (sint32)r_u32(0x8009bb8cu);
    w_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8009bb8cu)) + (uint32)(52))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046572)));
    w_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(52))))) + (uint32)(32))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046540)));
  }
  else
  {
    v3 = (sint32)r_u32(0x8009bb8cu);
    w_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8009bb8cu)) + (uint32)(52))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046640)));
    w_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(v3) + (uint32)(52))))) + (uint32)(32))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046580)));
  }
  return ob_front_8008DD94((uint32)((sint32)r_u32(0x8009bb8cu)));
}


uint32 ob_front_8008E424(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8008e424u, "FRONT.BIN");
  sint32 v2;
  sint32 v3;
  if ((r_u32((uint32)(((uint32)(a1) + (uint32)(12)))) == a2))
  {
    v2 = (sint32)r_u32(0x8009bb90u);
    w_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8009bb90u)) + (uint32)(52))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046572)));
    w_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(52))))) + (uint32)(32))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046536)));
  }
  else
  {
    v3 = (sint32)r_u32(0x8009bb90u);
    w_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8009bb90u)) + (uint32)(52))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046640)));
    w_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(v3) + (uint32)(52))))) + (uint32)(32))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046576)));
  }
  ob_front_8008DD94((uint32)((sint32)r_u32(0x8009bb90u)));
  return ob_front_80093E70(0x8009BB98u);
}


uint32 ob_front_8008E530(void)
{
    FUNCTION_MARKER(0x8008e530u, "FRONT.BIN");
  sint32 v0;
  v0 = (sint32)r_u32(0x8009bb8cu);
  w_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8009bb8cu)) + (uint32)(140))), 250);
  w_u32((uint32)((sint32)((uint32)(v0) + (uint32)(120))), 3);
  return sub_80011984((sint32)(0u - (uint32)(2147046400)), 255, 15, 15, 256u, 0u, 0u);
}


uint32 ob_front_8008E5E0(uint32 a1)
{
    FUNCTION_MARKER(0x8008e5e0u, "FRONT.BIN");
  uint32 v2;
  uint32 result;
  sub_80021B20((sint32)(0u - (uint32)(2147046744)));
  w_u32(0x80073518u,0x80021C24u);
  v2 = r_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(a1) + (uint32)(12))))) + (uint32)(48))));
  if (v2)
    ob_front_a_callback(v2,2u,a1,r_u32(a1+12u));
  result = 0x8009BC2Cu;
  w_u32(0x8009bb94u,0x8009BC2Cu);
  return result;
}


uint32 ob_front_8008EB5C(void)
{
    FUNCTION_MARKER(0x8008eb5cu, "FRONT.BIN");
  w_u8(0x8006C230, 1);
  w_u8(0x8006C231, 0);
  w_u8(0x8006C233, 0);
  w_u8(0x8006C234, 0);
  sub_80011984((sint32)(0u - (uint32)(2147046356)), 255, 15, 15, 256u, 0u, 0u);
  return ob_init_card_tables();
}


uint32 ob_front_8008EBC8(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x8008ebc8u, "FRONT.BIN");
  sint32 result;
  result = r_u32((uint32)(((uint32)(a1) + (uint32)(12))));
  if ((result == a2))
  {
    sub_80021460((sint32)(0u - (uint32)(2147044712)), 0, 0, 32, 64u, 139u, 40u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044708)), 0, 0, 32, 64u, 171u, 30u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044704)), 0, 0, 32, 32u, 171u, 94u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044700)), 0, 0, 32, 64u, 203u, 32u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044696)), 0, 0, 32, 16u, 203u, 96u, 0u);
    sub_80021460((sint32)(0u - (uint32)(2147044692)), 0, 0, 16, 64u, 235u, 50u, 0u);
    return ob_front_8008E65C(197, 0x8008D0BCu, 0x8008D0C8u);
  }
  return result;
}


uint32 ob_front_80092D30(uint32 a1)
{
    FUNCTION_MARKER(0x80092d30u, "FRONT.BIN");
  a1 &= 255u;
  sint32 result;
  switch (a1)
  {
    case 0:
      result = 10;
      break;

    case 1:
      result = 1;
      break;

    case 2:
      result = 2;
      break;

    case 3:
      result = 5;
      break;

    case 4:
      result = 6;
      break;

    case 5:
      result = 8;
      break;

    case 6:
      result = 11;
      break;

    case 7:
      result = 12;
      break;

    case 8:
      result = 9;
      break;

    default:
      result = 0;
      break;

  }

  return result;
}


uint32 ob_front_80092DAC(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x80092dacu, "FRONT.BIN");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
  sint32 v5;
  uint8 v6;
  sint32 i;
  sint32 v8;
  uint32 v9;
  uint32 result;
  v5 = ((sint32)r_u32(a2) / 9);
  v6 = ob_front_80092D30(((sint32)r_u32(a2) % 9));
  for (i = 0; ((sint32)(i) < (sint32)(13)); ++i)
  {
    v8 = r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(v5))) - (uint32)(2147066704))));
    v9 = (uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(i))) + (uint32)(v8)));
    if ((r_u32(v9) == a3))
      w_u32(v9, r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(v6))) + (uint32)(v8)))));
  }

  w_u32((a2 + (2) * 4u), a3);
  result = (uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(v6))) + (uint32)(r_u32((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)(v5))) - (uint32)(2147066704)))))));
  w_u32(result, a3);
  return result;
}


uint32 ob_front_800939F4(void)
{
    FUNCTION_MARKER(0x800939f4u, "FRONT.BIN");
  return sub_80011984((sint32)(0u - (uint32)(2147046356)), 255, 15, 15, 256u, 0u, 0u);
}


uint32 ob_front_80093A74(void)
{
    FUNCTION_MARKER(0x80093a74u, "FRONT.BIN");
  return sub_80011984((sint32)(0u - (uint32)(2147046348)), 255, 15, 15, 256u, 0u, 0u);
}


uint32 ob_front_80093B34(void)
{
    FUNCTION_MARKER(0x80093b34u, "FRONT.BIN");
  return sub_80011984((sint32)(0u - (uint32)(2147046364)), 255, 15, 15, 256u, 0u, 0u);
}


uint32 ob_front_80094790(uint32 a1)
{
    FUNCTION_MARKER(0x80094790u, "FRONT.BIN");
  sint32 result;
  result = 1;
  w_u32(0x8009cc70u, 1);
  w_u32(0x8009cc6cu, a1);
  w_u32(0x8008969C, a1);
  return result;
}


uint32 ob_front_800947B4(void)
{
    FUNCTION_MARKER(0x800947b4u, "FRONT.BIN");
  sint32 result;
  result = (sint32)r_u32(0x8009cc6cu);
  w_u32(0x8008969C, (sint32)r_u32(0x8009cc6cu));
  return result;
}


uint32 ob_front_80094894(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80094894u, "FRONT.BIN");
  return ob_front_8009B94C((sint32)r_u32((0x8009cf20u + (r_u32(a2)) * 4u)), (r_u32((uint32)(((uint32)(a1) + (uint32)(12)))) == (uint32)(a2)));
}


uint32 ob_front_80095D1C(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80095d1cu, "FRONT.BIN");
  sint32 v2;
  uint32 v3;
  sint32 result;
  v2 = 0;
  v3 = ((0x8009cf00u + (a1) * 4u));
  do
  {
    if (!a2)
    {
      result = a1;
      if ((sint32)r_u32(v3))
        return result;
      ++a1;
      ((v3 += 4u));
      if (((sint32)a1 < 4))
        goto LABEL_18;
      v3 = 0x8009cf00u;
      goto LABEL_16;
    }
    if (((sint32)a2 > 0))
    {
      if ((a2 != 1))
      {
        ++v2;
        goto LABEL_19;
      }
      ((v3 += 4u));
      if ((a1 != 3))
      {
        ++a1;
        goto LABEL_18;
      }
      v3 = 0x8009cf00u;
      LABEL_16:
      a1 = 0;

      LABEL_18:
      ++v2;

      goto LABEL_19;
    }
    if ((a2 == (sint32)(0u - (uint32)(1))))
    {
      ((v3 -= 4u));
      if (a1)
      {
        --a1;
      }
      else
      {
        v3 = (0x8009cf0cu);
        a1 = 3;
      }
      goto LABEL_18;
    }
    ++v2;
    LABEL_19:
    result = (sint32)(0u - (uint32)(1));

    if (((sint32)(v2) >= (sint32)(5)))
      break;
    result = a1;
  }
  while (!((sint32)r_u32(v3)));
  return result;
}


uint32 ob_front_80097094(uint32 card)
{
    FUNCTION_MARKER(0x80097094u,"FRONT.BIN");
    uint32 result;
    if(r_u32(0x8006BCC4u)==card&&r_u32(0x8006BCC8u)==sub_8001D048(card))
    {
        result=0xFFFFFFFFu;w_u32(0x8006BCC4u,result);
    }
    else
    {
        w_u32(0x8006BCC4u,card);result=sub_8001D048(card);
    }
    w_u32(0x8006BCC8u,result);return 0u;
}

uint32 ob_front_80097114(uint32 a1, uint32 a2)
{
    FUNCTION_MARKER(0x80097114u, "FRONT.BIN");
    /* TODO: Bind external adapter for sub_80013318 */
  sint32 v4;
  sint32 v5;
  v4 = ob_draft_unresolved_call(0x80013318u,2u,a1,0x80089D40u+a1*552u+a2*36u);
  if (((sint32)r_u32(0x8006BCC4) == a1))
  {
    v5 = (sint32)(0u - (uint32)(1));
    if (((sint32)r_u32(0x8006BCC8) == a2))
      w_u32(0x8006BCC4, (sint32)(0u - (uint32)(1)));
    else
      v5 = sub_8001D048(r_u32(0x8006BCC4u));
    w_u32(0x8006BCC8, v5);
  }
  return (v4 == 0);
}


uint32 ob_front_80097DFC(uint32 a1)
{
    FUNCTION_MARKER(0x80097dfcu, "FRONT.BIN");
  sint32 v2;
  uint32 v3;
  sint32 result;
  v2 = r_u32((uint32)(((uint32)(a1) + (uint32)(8))));
  do
  {
    v3 = r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(44))));
    if (v3)
      ob_front_a_callback(v3,2u,a1,(uint32)v2);
    v2 = r_u32((uint32)((sint32)((uint32)(v2) + (uint32)(20))));
    result = r_u32((uint32)(((uint32)(a1) + (uint32)(8))));
  }
  while ((v2 != result));
  return result;
}


uint32 ob_front_800980B0(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x800980b0u, "FRONT.BIN");
  sint32 result;
  ob_front_80097FE8(a1, a2);
  result = a3;
  w_u32((uint32)(((uint32)(a2) + (uint32)(28))), a3);
  w_u32((uint32)(((uint32)(a3) + (uint32)(4))), a1);
  w_u32((uint32)(((uint32)(a2) + (uint32)(4))), ((uint32)(r_u32((uint32)(((uint32)(a2) + (uint32)(4))))) & (uint32)(~0x200u)));
  return result;
}


uint32 ob_front_8009A248(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x8009a248u, "FRONT.BIN");
    /* TODO: IDA supplied excess carriers to sub_8009AB74; frozen prototype governs the draft call */
  sint32 result;
  if ((a1 == 1))
  {
    ob_front_8009A2E4(1, a2);
    return ob_front_8009AB74(0);
  }
  else
  {
    result = ((sint32)a1 < 2);
    if (((sint32)a1 >= 2))
    {
      result = 2;
      if ((a1 == 2))
      {
        ob_front_8009A2E4(1, a2);
        return ob_front_8009AE68(0, a3);
      }
    }
    else
      if (!a1)
    {
      return ob_front_8009A2E4(0, a2);
    }
  }
  return result;
}


uint32 ob_front_8009B7A0(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x8009b7a0u, "FRONT.BIN");
  sint32 result;
  result = r_u8((uint32)(((uint32)(a1) + (uint32)(120))));
  if ((result != a2))
  {
    w_u8((uint32)(((uint32)(a1) + (uint32)(120))), a2);
    if (a3)
    {
      if (((uint8)(a2) == 1))
      {
        result = (sint32)(0u - (uint32)(2147046660));
        w_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(a1) + (uint32)(52))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046660)));
      }
      else
        if (((uint8)(a2) >= 2u))
      {
        result = 3;
        if (((uint8)(a2) == 2))
        {
          result = (sint32)(0u - (uint32)(2147046652));
          w_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(a1) + (uint32)(52))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046652)));
        }
        else
          if (((uint8)(a2) == 3))
        {
          result = (sint32)(0u - (uint32)(2147046644));
          w_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(a1) + (uint32)(52))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046644)));
        }
      }
      else
      {
        result = (sint32)(0u - (uint32)(2147046668));
        w_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(a1) + (uint32)(52))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046668)));
      }
    }
    else
      if (((uint8)(a2) == 1))
    {
      result = (sint32)(0u - (uint32)(2147046664));
      w_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(a1) + (uint32)(52))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046664)));
    }
    else
      if (((uint8)(a2) >= 2u))
    {
      result = 3;
      if (((uint8)(a2) == 2))
      {
        result = (sint32)(0u - (uint32)(2147046656));
        w_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(a1) + (uint32)(52))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046656)));
      }
      else
        if (((uint8)(a2) == 3))
      {
        result = (sint32)(0u - (uint32)(2147046648));
        w_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(a1) + (uint32)(52))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046648)));
      }
    }
    else
    {
      result = (sint32)(0u - (uint32)(2147046672));
      w_u32((uint32)(((uint32)(r_u32((uint32)(((uint32)(a1) + (uint32)(52))))) + (uint32)(40))), (sint32)(0u - (uint32)(2147046672)));
    }
  }
  return result;
}


