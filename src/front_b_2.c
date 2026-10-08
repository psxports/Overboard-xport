#include "front_signatures.h"
#include "native_runtime.h"
#include "psx.h"
#include <stdint.h>

uint32 ob_front_80095094(void)
{
    FUNCTION_MARKER(0x80095094u, "FRONT.BIN");
    /* TODO: Bind external adapter for sub_800544EC */
    /* TODO: Bind external adapter for sub_800135EC */
    /* TODO: Bind external adapter for sub_80054320 */
    /* TODO: Bind external adapter for sub_80013614 */
    /* TODO: Bind external adapter for sub_8001CE24 */
    /* TODO: Bind external adapter for sub_8001D5F0 */
    /* TODO: Bind external adapter for sub_8001CDE4 */
    /* TODO: Bind external adapter for sub_80013524 */
    /* TODO: Bind external adapter for sub_8001CF2C */
    /* TODO: Bind external adapter for sub_800130C4 */
    /* TODO: Bind external adapter for sub_8001CE4C */
    /* TODO: Bind external adapter for sub_8001345C */
    /* TODO: Bind external adapter for sub_80054440 */
    /* TODO: Bind external adapter for sub_8005C504 */
    /* TODO: Bind external adapter for sub_8002CFA8 */
    uint32 local_objects = ob_draft_scratch_acquire(376u);
  sint32 v0;
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
  sint32 result;
  sint32 v12;
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
  sint32 v23;
  sint32 v24;
  sint32 v25;
  ;
  sint32 v27;
  sint32 v28;
  v0 = 0;
  v1 = 0;
  v2 = 2;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v27 = 0;
  ob_draft_unresolved_call(0x800544ecu, 0u);
  ob_draft_unresolved_call(0x800135ecu, 0u);
  sub_80021B20((sint32)(0u - (uint32)(2147046736)));
  w_u32(0x80073518u, 0x80021C24u);
  w_u32(0x8009bb94u, (sint32)(0x8009BDE8u));
  while (2)
  {
    ob_draft_unresolved_call(0x80054320u, 0u);
    sub_8002D25C((sint32)(0u - (uint32)(2146906416)), (sint32)(0u - (uint32)(2146931856)));
    sub_80012184();
    if ((sint32)r_u32(0x8009bb94u))
      ob_front_80093E70((uint32)((sint32)r_u32(0x8009bb94u)));
    if ((((sint32)r_u32(0x8006BCC4) != (sint32)(0u - (uint32)(1))) && sub_80012758((sint32)r_u32(0x8006BCC4))))
    {
      w_u32(0x8006BCC4, (sint32)(0u - (uint32)(1)));
      w_u32(0x8006BCC8, (sint32)(0u - (uint32)(1)));
    }
    switch (v3)
    {
      case 0:
        v6 = 0;
        v5 = 4;
        goto LABEL_9;

      case 1:

      case 24:
        v6 = 0;
        v5 = 4;
        v3 = 2;
        goto LABEL_77;

      case 2:
        v9 = ob_draft_unresolved_call(0x80013614u, 2u, v0, 0);
        v0 = v9;
        if ((v9 == (sint32)(0u - (uint32)(1))))
      {
        ob_front_80096CEC((sint32)(0u - (uint32)(1)), 2);
      }
      else
      {
        v2 = sub_80012758(v9);
        v3 = 6;
        v6 = 0;
        ob_front_80096CEC(v0, v2);
        switch (v2)
        {
          case 0:

          case 3:
            goto LABEL_17;

          case 1:
            goto LABEL_18;

          case 2:

          case 5:
            v5 = 14;
            break;

          case 4:
            goto LABEL_20;

          default:
            goto LABEL_77;

        }

      }
        goto LABEL_77;

      case 3:

      case 6:
        if ((v0 == (sint32)(0u - (uint32)(1))))
      {
        v0 = ob_draft_unresolved_call(0x80013614u, 2u, (sint32)(0u - (uint32)(1)), 1);
        v6 = 0;
        LABEL_9:
        v3 = 1;

      }
      else
      {
        v2 = sub_80012758(v0);
        switch (v2)
        {
          case 0:
            LABEL_17:
          v5 = 0;

            break;

          case 1:
            LABEL_18:
          v5 = 1;

            break;

          case 2:

          case 5:
            v6 = 0;
            v5 = 14;
            goto LABEL_9;

          case 4:
            v6 = 0;
            LABEL_20:
          v5 = 13;

            break;

          default:
            goto LABEL_77;

        }

      }
        goto LABEL_77;

      case 4:

      case 5:
        if (((v0 == (sint32)(0u - (uint32)(1))) || (v2 = sub_80012758(v0) != 0)))
      {
        v6 = 0;
        if ((v3 == 5))
          ob_draft_unresolved_call(0x8001ce24u, 0u);
        v5 = 4;
        v3 = 1;
        v2 = 2;
      }
        goto LABEL_77;

      case 7:
        v3 = 15;
        goto LABEL_77;

      case 8:
        v3 = 16;
        goto LABEL_77;

      case 9:
        v3 = 17;
        goto LABEL_77;

      case 10:
        v3 = 18;
        goto LABEL_77;

      case 11:
        v3 = 19;
        goto LABEL_77;

      case 12:
        v3 = 20;
        goto LABEL_77;

      case 13:
        v3 = 14;
        goto LABEL_77;

      case 14:
        v28 = sub_8001D048(v0);
        if ((v28 == (sint32)(0u - (uint32)(1))))
        goto LABEL_40;
        ob_draft_unresolved_call(0x8001d5f0u, 2u, (local_objects + 0u), r_u8(0x8006C231));
        ob_draft_unresolved_call(0x8001cde4u, 0u);
        if (ob_draft_unresolved_call(0x80013524u, 4u, v0, (sint32)((uint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(552) * (uint32)(v0))) - (uint32)(2146919116))) + (uint32)((sint32)((uint32)(36) * (uint32)(v28))))) + (uint32)(12)), 1, (sint32)r_u32(0x8006BCC0)))
      {
        v3 = 5;
        if (ob_draft_unresolved_call(0x8001cf2cu, 1u, r_u8(0x8006C231)))
        {
          v5 = 3;
          v6 = 1;
          v1 = 0;
        }
        else
        {
          ob_draft_unresolved_call(0x8001ce24u, 0u);
          LABEL_40:
          v3 = 9;

          v5 = 8;
        }
      }
      else
      {
        LABEL_36:
        ob_draft_unresolved_call(0x8001ce24u, 0u);

        LABEL_59:
        w_u32(0x8008969C, 300);

        v3 = 26;
        v5 = 18;
      }
        goto LABEL_77;

      case 15:
        ob_draft_unresolved_call(0x800130c4u, 4u, (sint32)r_u32(0x8006BCC0), 0x8008d340u, 1, 1);
        ob_draft_unresolved_call(0x8001ce4cu, 2u, (local_objects + 0u), r_u8(0x8006C231));
        if (!ob_draft_unresolved_call(0x8001345cu, 4u, v0, (sint32)((uint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(552) * (uint32)(v0))) - (uint32)(2146919116))) + (uint32)((sint32)((uint32)(36) * (uint32)(v28))))) + (uint32)(12)), 1, (sint32)r_u32(0x8006BCC0)))
        goto LABEL_36;
        ob_draft_unresolved_call(0x8001ce24u, 0u);
        w_u32(0x8008969C, 300);
        v3 = 28;
        goto LABEL_61;

      case 16:
        v10 = ob_front_80096E3C(v0);
        if (v10)
      {
        if (((sint32)(v10) > (sint32)(0)))
        {
          if ((v10 == 1))
          {
            w_u32(0x8008969C, 300);
            v3 = 26;
            v5 = 17;
          }
        }
        else
          if ((v10 == (sint32)(0u - (uint32)(1))))
        {
          v5 = 0;
          v3 = 6;
          v6 = 2;
        }
        LABEL_77:
        if ((v6 == 1))
        {
          switch (v3)
          {
            case 5:
              if (ob_draft_unresolved_call(0x80054440u, 1u, 12))
            {
              v6 = 2;
              v5 = 0;
              v3 = 6;
              ob_draft_unresolved_call(0x8001ce24u, 0u);
              break;
            }
              if (ob_draft_unresolved_call(0x80054440u, 1u, 7))
              goto LABEL_118;
              if (ob_draft_unresolved_call(0x80054440u, 1u, 5))
              goto LABEL_121;
              if (ob_draft_unresolved_call(0x80054440u, 1u, 14))
            {
              v16 = v0;
              if (v1)
                goto LABEL_174;
              v6 = 2;
              v5 = 0;
              v3 = 6;
              ob_draft_unresolved_call(0x8001ce24u, 1u, v0);
              break;
            }
              if (ob_draft_unresolved_call(0x80054440u, 1u, 15))
            {
              v16 = v0;
              if ((v1 != 1))
                goto LABEL_174;
              v3 = 7;
              v5 = 9;
              break;
            }
              LABEL_173:
            v16 = v0;

              goto LABEL_174;

            case 3:
              if (ob_draft_unresolved_call(0x80054440u, 1u, 12))
            {
              v3 = 25;
              goto LABEL_173;
            }
              if (ob_draft_unresolved_call(0x80054440u, 1u, 4))
            {
              v6 = 0;
              v3 = 6;
              break;
            }
              if (ob_draft_unresolved_call(0x80054440u, 1u, 7))
              goto LABEL_118;
              if (ob_draft_unresolved_call(0x80054440u, 1u, 5))
              goto LABEL_121;
              if (ob_draft_unresolved_call(0x80054440u, 1u, 14))
            {
              v16 = v0;
              if (v1)
                goto LABEL_174;
              v6 = 0;
              v3 = 6;
            }
            else
            {
              if (!ob_draft_unresolved_call(0x80054440u, 1u, 15))
                goto LABEL_173;
              v16 = v0;
              if ((v1 != 1))
                goto LABEL_174;
              v3 = 11;
              v5 = 11;
            }
              break;

            case 4:
              if (ob_draft_unresolved_call(0x80054440u, 1u, 12))
            {
              v5 = 0;
              v1 = v27;
              v3 = 6;
              break;
            }
              if (ob_draft_unresolved_call(0x80054440u, 1u, 7))
            {
              LABEL_118:
              v16 = v0;

              if (!v1)
                v1 = 1;
              goto LABEL_174;
            }
              if (ob_draft_unresolved_call(0x80054440u, 1u, 5))
            {
              LABEL_121:
              v16 = v0;

              if ((v1 == 1))
                v1 = 0;
              goto LABEL_174;
            }
              if (ob_draft_unresolved_call(0x80054440u, 1u, 14))
            {
              v16 = v0;
              if (v1)
                goto LABEL_174;
              v5 = 0;
              v1 = v27;
              v3 = 6;
            }
            else
            {
              if (!ob_draft_unresolved_call(0x80054440u, 1u, 15))
                goto LABEL_173;
              v16 = v0;
              if ((v1 != 1))
                goto LABEL_174;
              v3 = 10;
              v1 = v27;
              v5 = 10;
            }
              break;

            default:
              if (((((uint32)((sint32)((uint32)(v3) - (uint32)(27))) < 2) || (v3 == 29)) || (v3 == 26)))
            {
              v17 = ob_draft_unresolved_call(0x80054440u, 1u, 14);
              v16 = v0;
              if (v17)
              {
                w_u32(0x8008969C, 0);
                v16 = v0;
              }
              goto LABEL_174;
            }
              if (ob_draft_unresolved_call(0x80054440u, 1u, 12))
            {
              v6 = 2;
              v4 = ob_front_80095D1C(v4, 0);
            }
            else
            {
              v18 = (ob_draft_unresolved_call(0x80054440u, 1u, 6) == 0);
              v19 = ((sint32)(v8) < (sint32)(2));
              if (v18)
              {
                if (ob_draft_unresolved_call(0x80054440u, 1u, 4))
                {
                  v18 = ((sint32)(v8--) > (sint32)(0));
                  if (!v18)
                    v8 = 2;
                }
                else
                {
                  v18 = (ob_draft_unresolved_call(0x80054440u, 1u, 5) == 0);
                  v20 = ((sint32)(v7) < (sint32)(4));
                  if (v18)
                  {
                    if (ob_draft_unresolved_call(0x80054440u, 1u, 7))
                    {
                      v18 = ((sint32)(v7--) > (sint32)(0));
                      if (!v18)
                        v7 = 4;
                    }
                  }
                  else
                  {
                    ++v7;
                    if (!v20)
                      v7 = 0;
                  }
                }
              }
              else
              {
                ++v8;
                if (!v19)
                  v8 = 0;
              }
            }
              v1 = (sint32)((uint32)((sint32)((uint32)(5) * (uint32)(v8))) + (uint32)(v7));
              if (!ob_draft_unresolved_call(0x80054440u, 1u, 14))
              goto LABEL_173;
              v16 = v0;
              if ((r_u32((uint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(36) * (uint32)(v1))) + (uint32)((sint32)((uint32)(552) * (uint32)(v0))))) - (uint32)(2146919116)))) != 1))
              goto LABEL_174;
              v5 = 2;
              v27 = (sint32)((uint32)((sint32)((uint32)(5) * (uint32)(v8))) + (uint32)(v7));
              v1 = 0;
              v3 = 4;
              break;

          }

          LABEL_172:
          ob_draft_unresolved_call(0x800544ecu, 0u);

          goto LABEL_173;
        }

        if (!v6)
        {
          if (ob_draft_unresolved_call(0x80054440u, 1u, 12))
            v3 = 25;
          if (ob_draft_unresolved_call(0x80054440u, 1u, 7))
          {
            v5 = 4;
            v3 = 22;
          }
          else
            if (ob_draft_unresolved_call(0x80054440u, 1u, 5))
          {
            v5 = 4;
            v3 = 21;
          }
          else
          {
            v13 = ob_draft_unresolved_call(0x80054440u, 1u, 6);
            v14 = v4;
            if (v13 || ((v15 = ob_draft_unresolved_call(0x80054440u, 1u, 14)), (v14 = v4), v15))
            {
              v4 = ob_front_80095D1C(v14, 0);
              v6 = 2;
              if ((v4 == (sint32)(0u - (uint32)(1))))
              {
                v6 = 1;
                v1 = 0;
                v4 = 1;
                v3 = 3;
              }
              else
              {
                v1 = 0;
                v7 = 0;
                v8 = 0;
              }
              goto LABEL_172;
            }
          }
          goto LABEL_173;
        }
        if (ob_draft_unresolved_call(0x80054440u, 1u, 12))
          v3 = 25;
        v21 = ob_draft_unresolved_call(0x80054440u, 1u, 7);
        v22 = v4;
        if (v21)
        {
          v23 = (sint32)(0u - (uint32)(1));
          LABEL_157:
          v4 = ob_front_80095D1C(v22, v23);

          goto LABEL_173;
        }
        v24 = ob_draft_unresolved_call(0x80054440u, 1u, 5);
        v22 = v4;
        if (v24)
        {
          v23 = 1;
          goto LABEL_157;
        }
        if (!ob_draft_unresolved_call(0x80054440u, 1u, 14))
        {
          v25 = ob_draft_unresolved_call(0x80054440u, 1u, 4);
          v16 = v0;
          if (!v25)
            goto LABEL_174;
          v6 = 0;
          goto LABEL_172;
        }
        if ((v4 == 1))
        {
          v5 = 7;
          v3 = 13;
          goto LABEL_173;
        }
        if (((sint32)(v4) >= (sint32)(2)))
        {
          if ((v4 == 2))
          {
            ob_front_80097094(v0);
            v16 = v0;
            goto LABEL_174;
          }
          v16 = v0;
          if ((v4 == 3))
          {
            v6 = 1;
            v5 = 0;
            v1 = 0;
            goto LABEL_172;
          }
        }
        else
        {
          v16 = v0;
          if (!v4)
          {
            v5 = 6;
            v3 = 8;
            goto LABEL_173;
          }
        }
        LABEL_174:
        ob_front_800962A4(v16, v2, v6);

        ob_front_80096550(v5, v0, v1, v6);
        ob_front_80096B8C(v4, v6);
        sub_8001FC60();
        while (r_u32(0x80077620u))
          ob_native_pump();

        ob_draft_unresolved_call(0x8005c504u, 1u, 0);
        w_u32(0x8007754C, (sint32)r_u32(0x8007737C));
        ob_draft_unresolved_call(0x8002cfa8u, 0u);
        w_u32(0x80077620, 1);
        result = 0;
        if ((v3 == 25))
          { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
        continue;
      }
        { uint32 draft_return = (r_u8(0x8006C231) != 0); ob_draft_scratch_release(local_objects);  return draft_return; }

      case 17:
        if (ob_front_80096EDC(v0))
        goto LABEL_59;
        w_u32(0x8008969C, 300);
        v6 = 1;
        v3 = 28;
        LABEL_61:
      v5 = 20;

        goto LABEL_77;

      case 18:
        if (ob_front_80097114(v0, v1))
      {
        w_u32(0x8008969C, 300);
        v3 = 26;
        v5 = 19;
      }
      else
      {
        w_u32(0x8008969C, 300);
        v3 = 29;
        v5 = 22;
      }
        goto LABEL_77;

      case 19:
        if (ob_front_800971D0(v0))
      {
        w_u32(0x8008969C, 300);
        v3 = 26;
        v5 = 15;
      }
      else
      {
        w_u32(0x8008969C, 300);
        v3 = 26;
        v5 = 21;
      }
        goto LABEL_77;

      case 20:
        if (!ob_front_800971F0(v0))
        goto LABEL_9;
        w_u32(0x8008969C, 300);
        v3 = 26;
        v5 = 16;
        goto LABEL_77;

      case 21:
        v0 = ob_draft_unresolved_call(0x80013614u, 2u, v0, 1);
        v3 = 24;
        if ((v0 != (sint32)(0u - (uint32)(1))))
        v5 = 5;
        goto LABEL_77;

      case 22:
        v0 = ob_draft_unresolved_call(0x80013614u, 2u, v0, (sint32)(0u - (uint32)(1)));
        v3 = 24;
        if ((v0 != (sint32)(0u - (uint32)(1))))
        v5 = 5;
        goto LABEL_77;

      case 23:
        v12 = v0;
        if ((v0 != (sint32)(0u - (uint32)(1))))
      {
        v2 = sub_80012758(v0);
        v12 = v0;
      }
        v0 = ob_draft_unresolved_call(0x80013614u, 2u, v12, 0);
        ob_front_80096CEC(v0, v2);
        v3 = 6;
        v5 = 0;
        v6 = 0;
        goto LABEL_77;

      case 26:

      case 27:
        if (((sint32)((sint32)r_u32(0x8008969C)) <= (sint32)(0)))
      {
        v6 = 0;
        v5 = 4;
        v3 = 1;
        v2 = 2;
        ob_draft_unresolved_call(0x800544ecu, 0u);
      }
        goto LABEL_77;

      case 28:

      case 29:
        v2 = sub_80012758(v0);
        if (v2)
      {
        v6 = 0;
        v5 = 4;
        v3 = 1;
        v2 = 2;
      }
        if (!(sint32)r_u32(0x8008969C))
      {
        v5 = 0;
        v3 = 6;
        v6 = 2;
        v2 = sub_80012758(v0);
        v0 = ob_draft_unresolved_call(0x80013614u, 2u, v0, 0);
        ob_front_80096CEC(v0, v2);
        v4 = ob_front_80095D1C(v4, 0);
        ob_draft_unresolved_call(0x800544ecu, 0u);
      }
        goto LABEL_77;

      default:
        goto LABEL_77;

    }

  }

}


