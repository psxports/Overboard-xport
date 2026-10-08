#include "draft_signatures.h"
#include "psx.h"

/* Unverified draft bodies */

uint32 sub_800349D8(uint32 a1)
{
    FUNCTION_MARKER(0x800349d8u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_800348B4 */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Bind external adapter for sub_80063FC8 */
    uint32 local_objects = ob_draft_scratch_acquire(8u);
  uint32 v2;
  uint32 v3;
  sint32 v4;
  sint32 v5;
  uint16 v6;
  uint32 v7;
  uint32 v8;
  sint32 v9;
  sint32 v10;
  sint32 v11;
  sint32 v12;
  sint32 v13;
  sint32 v14;
  sint32 v15;
  sint32 v16;
  sint32 i;
  sint16 v18;
  sint16 v19;
  uint32 v20;
  uint16 v21;
  uint16 v22;
  uint16 v23;
  sint16 v24;
  sint16 v25;
  uint32 v26;
  sint32 v27;
  sint32 result;
  sint32 v29;
  sint32 v30;
  ;
  ;
  v2 = (uint32)(r_u32(a1));
  v3 = (uint32)(((uint32)(r_u32(a1)) + (uint32)(12)));
  if ((r_u8((uint32)(((uint32)(r_u32(a1)) + (uint32)(6)))) >= 0x11u))
  {
    v4 = 1;
  }
  else
  {
    v4 = 2;
    if (((r_u16((v2 + (5) * 2u)) & 2) == 0))
      ob_draft_unresolved_call(0x800348b4u, 2u, r_u32(a1), v3);
  }
  if ((sint32)r_u32(0x80077464u))
  {
    v5 = r_u16((v2 + (1) * 2u));
    v6 = (sint32)((uint32)(v5) * (uint32)(r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800773a8u)) + (uint32)(2))))));
    v7 = (sint32)((uint32)(v5) * (uint32)(r_u16((v2 + (2) * 2u))));
    v8 = (v7 / v6);
    v9 = (v7 >> (sint32)((uint32)(v4) - (uint32)(1)));
    w_u8((uint32)((sint32)((uint32)((sint32)r_u32(0x80077464u)) + (uint32)(11))), v8);
    v10 = (sint32)((uint32)((sint32)r_u32(0x80077464u)) + (uint32)(20));
    w_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x80077464u)) + (uint32)(12))), ((sint32)((sint32)(v6)) >> (sint32)((uint32)(v4) + (uint32)(1))));
    sub_80026694(v10, v9, 0);
    ob_draft_unresolved_call(0x80063fc8u, 3u, r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x80077464u)) + (uint32)(20)))), (v2 + (6) * 2u), v9);
  }
  v11 = r_u16((v2 + (4) * 2u));
  if (((v11 == 9) || (v12 = 0, (v11 == 21))))
  {
    sub_80034768((sint32)(v3), (sint32)r_u32(0x800774d8u), (sint32)r_u32(0x800774dcu), 16, 64, r_u16((v2 + (3) * 2u)), v4, (sint32)((local_objects + 0u)));
    w_u32(0x800774d8u, ((uint32)((sint32)r_u32(0x800774d8u)) + (uint32)(16)));
    if (((sint32)((sint32)r_u32(0x800774d8u)) >= (sint32)(1024)))
    {
      w_u32(0x800774d8u, (sint32)r_u32(0x800775dcu));
      w_u32(0x800774dcu, ((uint32)((sint32)r_u32(0x800774dcu)) + (uint32)(64)));
    }
  }
  else
  {
    v14 = (sint32)(0u - (uint32)(2146961216));
    v13 = 0;
    v15 = (sint32)(0u - (uint32)(2146961204));
    while (((r_u16((uint32)((sint32)((uint32)(v15) + (uint32)(2)))) != r_u16((v2 + (4) * 2u))) || (r_u16((uint32)(v15)) != 1)))
    {
      ++v12;
      v15 = ((uint32)(v15) + (uint32)(16));
      v14 = ((uint32)(v14) + (uint32)(16));
      if (((sint32)(v12) >= (sint32)(15)))
        goto LABEL_16;
    }

    v13 = 1;
    LABEL_16:
    v16 = (sint32)(v3);

    if (!v13)
    {
      v14 = (sint32)(0u - (uint32)(2146961216));
      for (i = 0; ((sint32)(i) < (sint32)(15)); ++i)
      {
        if (!(r_u16((uint32)((sint32)((uint32)(v14) + (uint32)(12))))))
          break;
        v14 = ((uint32)(v14) + (uint32)(16));
      }

      v18 = (sint32)r_u32(0x800774d8u);
      v19 = (sint32)r_u32(0x800774dcu);
      w_u16((uint32)((sint32)((uint32)(v14) + (uint32)(8))), 0);
      w_u16((uint32)((sint32)((uint32)(v14) + (uint32)(10))), 0);
      w_u16((uint32)(v14), v18);
      w_u16((uint32)((sint32)((uint32)(v14) + (uint32)(2))), v19);
      v20 = ((sint32)r_u32(0x80077464u) == 0);
      w_u16((uint32)((sint32)((uint32)(v14) + (uint32)(4))), ((sint32)((sint32)(r_u16((v2 + (1) * 2u)))) >> v4));
      if (v20)
        v21 = r_u16((v2 + (2) * 2u));
      else
        v21 = r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800773a8u)) + (uint32)(2))));
      w_u16((uint32)((sint32)((uint32)(v14) + (uint32)(6))), v21);
      w_u16((uint32)((sint32)((uint32)(v14) + (uint32)(12))), 1);
      v22 = r_u16((v2 + (4) * 2u));
      w_u32(0x800774d8u, ((uint32)((sint32)r_u32(0x800774d8u)) + (uint32)(16)));
      v20 = ((sint32)((sint32)r_u32(0x800774d8u)) < (sint32)(1024));
      w_u16((uint32)((sint32)((uint32)(v14) + (uint32)(14))), v22);
      if (!v20)
      {
        w_u32(0x800774d8u, (sint32)r_u32(0x800775dcu));
        w_u32(0x800774dcu, ((uint32)((sint32)r_u32(0x800774dcu)) + (uint32)(64)));
      }
      v16 = (sint32)(v3);
    }
    sub_80034768(v16, ((uint32)(r_u16((uint32)((sint32)((uint32)(v14) + (uint32)(8))))) + (uint32)(r_u16((uint32)(v14)))), ((uint32)(r_u16((uint32)((sint32)((uint32)(v14) + (uint32)(10))))) + (uint32)(r_u16((uint32)((sint32)((uint32)(v14) + (uint32)(2)))))), r_u16((uint32)((sint32)((uint32)(v14) + (uint32)(4)))), r_u16((uint32)((sint32)((uint32)(v14) + (uint32)(6)))), r_u16((v2 + (3) * 2u)), v4, (sint32)((local_objects + 0u)));
    v23 = ((uint32)(r_u16((uint32)((sint32)((uint32)(v14) + (uint32)(8))))) + (uint32)(r_u16((uint32)((sint32)((uint32)(v14) + (uint32)(4))))));
    w_u16((uint32)((sint32)((uint32)(v14) + (uint32)(8))), v23);
    if ((v23 >= 0x10u))
    {
      v24 = r_u16((uint32)((sint32)((uint32)(v14) + (uint32)(10))));
      v25 = r_u16((uint32)((sint32)((uint32)(v14) + (uint32)(6))));
      w_u16((uint32)((sint32)((uint32)(v14) + (uint32)(8))), 0);
      w_u16((uint32)((sint32)((uint32)(v14) + (uint32)(10))), (sint32)((uint32)(v24) + (uint32)(v25)));
    }
    if ((r_u16((uint32)((sint32)((uint32)(v14) + (uint32)(10)))) >= 0x40u))
      w_u16((uint32)((sint32)((uint32)(v14) + (uint32)(12))), 0);
  }
  (w_u32(0x80077608u, ((sint32)r_u32(0x80077608u) + 1u)), (sint32)r_u32(0x80077608u));
  if ((sint32)r_u32(0x80077464u))
    v26 = r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800773a8u)) + (uint32)(2))));
  else
    v26 = r_u16((v2 + (2) * 2u));
  v27 = (sint32)((uint32)((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 0u)) << (uint32)(16))) + (uint32)(((uint32)(((uint16)(((sint32)r_u32(local_objects + 4u)) >> 16) >> 4)) << (uint32)(12))))) + (uint32)(((uint32)(((uint16)((sint32)r_u32(local_objects + 4u)) >> 4)) << (uint32)(8))))) + (uint32)((sint32)((uint32)(16) * (uint32)((uint16)(((uint32)((v26 >> 5)) + (uint32)((sint32)((uint32)(3) * (uint32)((r_u16((v2 + (1) * 2u)) >> 5))))))))));
  if (((r_u16((v2 + (5) * 2u)) & 1) != 0))
    v27 = ((uint32)(v27) + (uint32)(4));
  result = sub_80026758(a1);
  w_u32(a1, (sint32)((uint32)(v27) + (uint32)(2)));
  v29 = (sint32)r_u32(0x80077464u);
  if ((sint32)r_u32(0x80077464u))
  {
    result = (sint32)r_u32(0x80077478u);
    v30 = (sint32)r_u32(0x8007747cu);
    w_u32((uint32)((sint32)r_u32(0x80077464u)), (sint32)r_u32(0x80077478u));
    w_u32((uint32)((sint32)((uint32)(v29) + (uint32)(4))), v30);
  }
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_8001994C(void)
{
    FUNCTION_MARKER(0x8001994cu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_8001AE60 */
    /* TODO: Bind external adapter for sub_8005FB28 */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    uint32 local_objects = ob_draft_scratch_acquire(24u);
  sint32 v0;
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
  uint32 v11;
  sint32 v12;
  ;
  v0 = 0;
  v1 = sub_80054C14();
  w_u32(0x80076874u, v1);
  if (((sint32)r_u32(0x8006c220u) == 1))
  {
    v2 = (sint32)r_u32(0x80076db0u);
    if ((((sint32)r_u32(0x80076db0u) & 3) != 0))
      v2 = sub_800257CC((0x80076db0u));
    else
      (w_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x80076db0u)) - (uint32)(6))), (r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x80076db0u)) - (uint32)(6)))) + 1u)), r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x80076db0u)) - (uint32)(6)))));
    if (((uint32)((sint32)r_u32(0x80076874u)) >= (sint32)r_u32(0x800882BC)))
    {
      while (1)
      {
        ob_draft_unresolved_call((sint32)r_u32(0x800C0FC8), 3u, (sint32)(0u - (uint32)(2146925892)), (sint32)((uint32)(v2) + (uint32)((sint32)r_u32(0x80076878u))), 4);
        w_u32(0x80076878u, ((uint32)((sint32)r_u32(0x80076878u)) + (uint32)(4)));
        if (((sint32)r_u32(0x800882BC) == (sint32)(0u - (uint32)(1))))
          break;
        ob_draft_unresolved_call((sint32)r_u32(0x800A636C), 2u, (local_objects + 0u), 0);
        if (((sint32)r_u32(((local_objects + 0u) + (0) * 4u)) || sub_80054440(0)))
          break;
        ob_draft_unresolved_call((sint32)r_u32(0x800C0FC8), 3u, (local_objects + 0u), (sint32)((uint32)(v2) + (uint32)((sint32)r_u32(0x80076878u))), 4);
        w_u32(0x80076878u, ((uint32)((sint32)r_u32(0x80076878u)) + (uint32)(4)));
        if (((sint32)r_u32(0x800C9984) == (sint32)(0u - (uint32)(1))))
        {
          ob_draft_unresolved_call((sint32)r_u32(0x800C9964), 2u, 0, (sint32)r_u32(((local_objects + 0u) + (0) * 4u)));
        }
        else
        {
          ob_draft_unresolved_call((sint32)r_u32(0x800C9964), 2u, 0, 0);
          ob_draft_unresolved_call(0x8001ae60u, 2u, 0, (sint32)r_u32(((local_objects + 0u) + (0) * 4u)));
        }
        sub_80045D70((sint32)r_u32(0x800882BC));
        ob_draft_unresolved_call((sint32)r_u32(0x800BAA14), 1u, (sint32)r_u32(0x800882BC));
        ob_draft_unresolved_call((sint32)r_u32(0x800AE0F8), 2u, (sint32)r_u32(0x800882BC), 0);
        ob_draft_unresolved_call((sint32)r_u32(0x80093D84), 1u, 0);
        if (((uint32)((sint32)r_u32(0x80076874u)) < (sint32)r_u32(0x800882BC)))
          goto LABEL_14;
      }

      w_u32(0x8006c170u, 1);
      w_u32(0x80076878u, 0);
      w_u32(0x8006c220u, 0);
      w_u32(0x800882BC, (sint32)r_u32(0x80076874u));
      v0 = 7;
    }
    LABEL_14:
    sub_800257A0((0x80076db0u));

    { uint32 draft_return = v0; ob_draft_scratch_release(local_objects);  return draft_return; }
  }
  else
    if ((sint32)r_u32(0x8006c224u))
  {
    v4 = (sint32)r_u32(0x800882BC);
    result = 0;
    if ((((uint32)(v1) - (uint32)(25)) >= (sint32)r_u32(0x800882BC)))
    {
      do
      {
        w_u32(0x800882BC, (sint32)((uint32)(v4) + (uint32)(25)));
        v5 = 0;
        if ((sint8)r_u8(0x8006c230u))
        {
          v6 = (sint32)(0u - (uint32)(2146657948));
          v7 = 0;
          do
          {
            ob_draft_unresolved_call(r_u32((uint32)((sint32)((uint32)(v7) - (uint32)(2146657952)))), 2u, (local_objects + 0u), v5);
            v8 = r_u32((uint32)((sint32)((uint32)(v7) - (uint32)(2146657916))));
            w_u32((uint32)((sint32)((uint32)(v7) - (uint32)(2146657904))), (sint32)r_u32(((local_objects + 0u) + (0) * 4u)));
            if ((v8 == (sint32)(0u - (uint32)(1))))
            {
              ob_draft_unresolved_call(r_u32((uint32)(v6)), 1u, v5);
            }
            else
            {
              ob_draft_unresolved_call(r_u32((uint32)(v6)), 2u, v5, 0);
              ob_draft_unresolved_call(0x8001ae60u, 2u, v5, (sint32)r_u32(((local_objects + 0u) + (0) * 4u)));
            }
            v6 = ((uint32)(v6) + (uint32)(56));
            sub_80045D70((sint32)r_u32(0x800882BC));
            v7 = ((uint32)(v7) + (uint32)(56));
            ob_draft_unresolved_call((sint32)r_u32(0x800BAA14), 1u, (sint32)r_u32(0x800882BC));
            ob_draft_unresolved_call((sint32)r_u32(0x800AE0F8), 2u, (sint32)r_u32(0x800882BC), 0);
            ob_draft_unresolved_call((sint32)r_u32(0x80093D84), 1u, 0);
            ob_draft_unresolved_call(0x8005fb28u, 3u, (sint32)r_u32(0x8006c16cu), (sint32)(0u - (uint32)(2146925892)), 4);
            ob_draft_unresolved_call(0x8005fb28u, 3u, (sint32)r_u32(0x8006c16cu), (local_objects + 0u), 4);
            ++v5;
          }
          while ((v5 < (uint8)((sint8)r_u8(0x8006c230u))));
        }
        v4 = (sint32)r_u32(0x800882BC);
        result = 0;
      }
      while (((uint32)((sint32)((uint32)((sint32)r_u32(0x80076874u)) - (uint32)(25))) >= (sint32)r_u32(0x800882BC)));
    }
  }
  else
  {
    w_u32(0x800882BC, (sint32)((uint32)(25) * (uint32)(((sint32)r_u32(0x800882BC) / 25))));
    result = 0;
    if (((sint32)r_u32(0x800882BC) < v1))
    {
      do
      {
        w_u32(0x800882BC, ((uint32)((sint32)r_u32(0x800882BC)) + (uint32)(25)));
        if (((uint32)((sint32)r_u32(0x80076874u)) < (sint32)r_u32(0x800882BC)))
          w_u32(0x800882BC, (sint32)r_u32(0x80076874u));
        v9 = 0;
        if ((sint8)r_u8(0x8006c230u))
        {
          v10 = 0;
          v11 = (sint32)r_u32(0x8006c138u);
          do
          {
            if ((sint32)r_u32(v11))
            {
              ob_draft_unresolved_call(r_u32((uint32)((sint32)((uint32)(v10) - (uint32)(2146657952)))), 2u, (local_objects + 0u), v9);
              v12 = r_u32((uint32)((sint32)((uint32)(v10) - (uint32)(2146657916))));
              w_u32((uint32)((sint32)((uint32)(v10) - (uint32)(2146657904))), (sint32)r_u32(((local_objects + 0u) + (0) * 4u)));
              if ((v12 == (sint32)(0u - (uint32)(1))))
              {
                ob_draft_unresolved_call(r_u32((uint32)((sint32)((uint32)(v10) - (uint32)(2146657948)))), 1u, v9);
              }
              else
              {
                ob_draft_unresolved_call(r_u32((uint32)((sint32)((uint32)(v10) - (uint32)(2146657948)))), 2u, v9, 0);
                ob_draft_unresolved_call(0x8001ae60u, 2u, v9, (sint32)r_u32(((local_objects + 0u) + (0) * 4u)));
              }
              sub_80045D70((sint32)r_u32(0x800882BC));
              ob_draft_unresolved_call((sint32)r_u32(0x800BAA14), 1u, (sint32)r_u32(0x800882BC));
              ob_draft_unresolved_call((sint32)r_u32(0x800AE0F8), 2u, (sint32)r_u32(0x800882BC), 0);
              ob_draft_unresolved_call((sint32)r_u32(0x80093D84), 1u, 0);
            }
            v10 = ((uint32)(v10) + (uint32)(56));
            ++v9;
            ((v11 += 4u));
          }
          while ((v9 < (uint8)((sint8)r_u8(0x8006c230u))));
        }
        result = 0;
      }
      while (((sint32)r_u32(0x800882BC) < (uint32)((sint32)r_u32(0x80076874u))));
    }
  }
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


uint32 sub_80041D7C(uint32 a1, uint32 a2, uint32 a3)
{
    FUNCTION_MARKER(0x80041D7Cu, "SLES_008.65");
    uint32 object = r_u32(a1 + 12u);
    w_u16(object + 56u, r_u16(object + 56u) & 0xBFFFu);
    uint32 transform = r_u32(a1 + 8u);
    uint32 camera = r_u32(0x800775D0u);
    sint32 x = (sint32)(r_u32(transform + 24u) - r_u32(camera + 24u));
    sint32 y = (sint32)(r_u32(transform + 28u) - r_u32(camera + 28u));
    sint32 z = (sint32)(r_u32(transform + 32u) - r_u32(camera + 32u));
    w_u32(0x1F800008u, (uint32)x);
    w_u32(0x1F80000Cu, (uint32)y);
    w_u32(0x1F800010u, (uint32)z);
    sint32 abs_x = x < 0 ? (sint32)(0u - (uint32)x) : x;
    sint32 abs_y = y < 0 ? (sint32)(0u - (uint32)y) : y;
    sint32 abs_z = z < 0 ? (sint32)(0u - (uint32)z) : z;
    uint32 large = abs_x >= 16000 || abs_y >= 16000 || abs_z >= 16000;
    w_u16(0x1F800000u, (uint32)(large ? x >> 4 : x));
    w_u16(0x1F800002u, (uint32)(large ? y >> 4 : y));
    w_u16(0x1F800004u, (uint32)(large ? z >> 4 : z));
    for (uint32 index = 0u; index < 5u; ++index)
        xport_gte_write_control(index, r_u32(0x8008C8A8u + 4u * index));
    xport_gte_write_data(0u, r_u32(0x1F800000u));
    xport_gte_write_data(1u, r_u32(0x1F800004u));
    xport_gte_execute(0x486012u);
    for (uint32 index = 0u; index < 3u; ++index)
        w_u32(0x1F800008u + 4u * index, xport_gte_read_data(25u + index));
    for (uint32 index = 0u; index < 3u; ++index)
        w_u32(0x1F800018u + 4u * index,
            r_u32(0x1F800008u + 4u * index) << (large ? 4u : 0u));
    uint32 partial = 0u;
    if (a2)
    {
        uint32 handle = r_u32(a1 + 4u);
        uint32 model = r_u32(handle);
        if (model & 3u)
            model = sub_800257CC(handle);
        else
        {
            w_u16(model - 6u, r_u16(model - 6u) + 1u);
            model = r_u32(r_u32(a1 + 4u));
        }
        uint32 scale = ((uint32)r_u16(r_u32(a1 + 8u) + 76u) * r_u16(model + 8u)) >> 8u;
        if ((uint16)scale > 0xFF00u)
            scale = 0xFF00u;
        sint32 radius = (sint32)((uint32)r_u16(model + 22u) * (uint16)scale) >> 8;
        sub_800257A0(r_u32(a1 + 4u));
        sint32 camera_x = (sint32)r_u32(0x1F800018u);
        sint32 camera_y = (sint32)r_u32(0x1F80001Cu);
        sint32 camera_z = (sint32)r_u32(0x1F800020u);
        if (camera_z < (sint32)(r_u32(0x800773B4u) - (uint32)radius))
            return 1u;
        if ((sint32)(r_u32(0x800773B8u) + (uint32)radius) < camera_z)
            return 1u;
        sint32 magnitude_y = camera_y < 0 ? (sint32)(0u - (uint32)camera_y) : camera_y;
        sint32 vertical = (sint32)((uint32)(((int64_t)camera_z * (sint16)r_u16(0x8007734Cu)) >> 14)
            + (uint32)(((int64_t)magnitude_y * (sint16)r_u16(0x8007734Au)) >> 14));
        if (vertical >= radius)
            return 0u;
        sint32 magnitude_x = camera_x < 0 ? (sint32)(0u - (uint32)camera_x) : camera_x;
        sint32 horizontal = (sint32)((uint32)(((int64_t)camera_z * (sint16)r_u16(0x80077344u)) >> 14)
            + (uint32)(((int64_t)magnitude_x * (sint16)r_u16(0x80077340u)) >> 14));
        if (horizontal >= radius)
            return 0u;
        sint32 magnitude_horizontal = horizontal < 0 ? (sint32)(0u - (uint32)horizontal) : horizontal;
        if (radius < magnitude_horizontal)
        {
            sint32 magnitude_vertical = vertical < 0 ? (sint32)(0u - (uint32)vertical) : vertical;
            partial = radius >= magnitude_vertical;
        }
        else
            partial = 1u;
    }
    else
        partial = a3 != 0u;
    uint32 bytes = 56u + 8u * r_u16(0x800775A2u);
    if (r_u32(0x80077614u) < bytes)
    {
        w_u32(0x80077614u, 5600u);
        uint32 allocated = ob_draft_unresolved_call(0x8002D9FCu, 1u, 5600u);
        w_u32(0x800770F0u, allocated);
        if (!allocated)
            return 0u;
    }
    w_u32(0x80077614u, r_u32(0x80077614u) - bytes);
    uint32 node = r_u32(0x800770F0u);
    w_u8(node + 1u, partial);
    w_u16(node + 2u, r_u16(a1));
    w_u16(node + 4u, r_u32(0x80077350u));
    w_u32(node + 12u, r_u32(0x1F800018u));
    w_u32(node + 16u, r_u32(0x1F80001Cu));
    w_u32(node + 20u, r_u32(0x1F800020u));
    node = r_u32(0x800770F0u);
    w_u32(node + 24u, r_u32(a1 + 4u));
    w_u32(node + 44u, 0u);
    w_u32(node + 48u, 0u);
    w_u32(node + 28u, r_u32(a1 + 8u));
    w_u32(node + 32u, r_u32(a1 + 12u));
    w_u32(node + 36u, r_u32(a1 + 16u));
    w_u32(node + 40u, r_u32(a1 + 20u));
    ob_draft_unresolved_call(0x8005F750u, 2u, 0x1F800008u, 0x1F800024u);
    uint32 distance = ob_draft_unresolved_call(0x8005EF68u, 1u,
        r_u32(0x1F800024u) + r_u32(0x1F800028u) + r_u32(0x1F80002Cu));
    w_u32(r_u32(0x800770F0u) + 8u, distance << (large ? 4u : 0u));
    uint32 next = r_u32(0x800770F0u) + 56u;
    uint32 count = r_u16(0x800775A2u);
    if (count)
    {
        w_u16(r_u32(0x800770F0u) + 52u, count);
        ob_draft_unresolved_call(0x80032240u, 1u, next);
        next += 8u * r_u16(0x800775A2u);
    }
    else
        w_u16(r_u32(0x800770F0u) + 52u, 0u);
    node = r_u32(0x800770F0u);
    w_u16(node + 54u, 0u);
    if (r_u32(0x800773D8u))
        sub_80042368(r_u32(0x80077554u));
    else
    {
        w_u32(0x80077554u, node);
        w_u32(node + 44u, 0u);
        w_u32(node + 48u, 0u);
    }
    w_u32(0x800770F0u, next);
    uint32 result = r_u32(0x800773D8u) + 1u;
    w_u32(0x800773D8u, result);
    return result;
}


uint32 sub_80039100(uint32 a1)
{
    FUNCTION_MARKER(0x80039100u, "SLES_008.65");
    uint32 light_matrix = ob_draft_scratch_acquire(32u);
    uint32 transform = r_u32(a1 + 28u);
    w_u16(0x80077638u, 0u);
    w_u16(0x80077364u, 0u);
    for (uint32 row = 0u; row < 3u; ++row)
        for (uint32 column = 0u; column < 3u; ++column)
            w_u16(0x1F800000u + (row * 3u + column) * 2u,
                (uint32)((sint32)(sint16)r_u16(transform + (column * 3u + row) * 2u) >> 2));
    w_u32(0x800773C0u, r_u32(0x80077354u));
    if (r_u32(transform + 48u) & 0x100u)
    {
        for (uint32 index = 0u; index < 5u; ++index)
            w_u32(0x1F800020u + index * 4u, r_u32(0x8008C8A8u + index * 4u));
    }
    else
        ob_draft_unresolved_call(0x8005F288u, 3u, 0x8008C8A8u, 0x1F800000u, 0x1F800020u);
    w_u16(0x1F800026u, 0u - r_u16(0x1F800026u));
    w_u16(0x1F80002Au, 0u - r_u16(0x1F80002Au));
    w_u16(0x1F800028u, 0u - r_u16(0x1F800028u));
    uint32 scale = ((uint32)r_u16(r_u32(a1 + 28u) + 76u) * r_u16(r_u32(a1 + 24u) + 8u)) >> 8u;
    if ((uint16)scale > 0xFF00u)
        scale = 0xFF00u;
    scale &= 0xFFFFu;
    if (!scale)
    {
        /* Original break 7 rejects division by a zero model scale */
        return ob_native_missing_value(0x80039100u, "Zero model scale division");
    }
    for (uint32 axis = 0u; axis < 3u; ++axis)
    {
        sint32 coordinate = (sint32)r_u32(a1 + 12u + axis * 4u);
        sint32 rounding = coordinate <= 0 ? ((sint32)(0u - scale) >> 1) : (sint32)(scale >> 1u);
        sint32 numerator = (sint32)(((uint32)coordinate << 8u) + (uint32)rounding);
        uint32 quotient = (uint32)(numerator / (sint32)scale);
        if (axis == 1u)
            quotient = 0u - quotient;
        w_u32(0x1F800034u + axis * 4u, quotient);
    }
    uint32 magnitude = 0u;
    for (uint32 axis = 0u; axis < 3u; ++axis)
    {
        sint32 coordinate = (sint32)r_u32(0x1F800034u + axis * 4u);
        uint32 absolute = coordinate < 0 ? 0u - (uint32)coordinate : (uint32)coordinate;
        if (magnitude < absolute)
            magnitude = absolute;
    }
    uint32 shift = 0u;
    while (magnitude >= 0x7FF9u)
    {
        magnitude >>= 1u;
        for (uint32 axis = 0u; axis < 3u; ++axis)
            w_u32(0x1F800034u + axis * 4u,
                (uint32)((sint32)r_u32(0x1F800034u + axis * 4u) >> 1));
        ++shift;
    }
    if (!r_u32(0x800774CCu))
    {
        w_u32(0x8007759Cu, 960u);
        w_u32(0x80077530u, 0x1F800040u);
    }
    sub_800354C8(r_u32(a1 + 24u));
    if (shift)
        for (uint32 index = 0u; index < 9u; ++index)
            w_u16(0x1F800020u + index * 2u,
                (uint32)((sint32)(sint16)r_u16(0x1F800020u + index * 2u) >> shift));
    ob_draft_unresolved_call(0x8005F288u, 3u, 0x80088818u, 0x1F800000u, light_matrix);
    ob_draft_unresolved_call(0x8005F3C8u, 1u, light_matrix);
    w_u32(0x80077328u, light_matrix);
    ob_draft_unresolved_call(0x8005F398u, 1u, 0x1F800020u);
    ob_draft_unresolved_call(0x8005F428u, 1u, 0x1F800020u);
    sub_8005F488(r_u32(r_u32(0x800770C0u) + 8u));
    sub_8003584C(r_u32(a1 + 24u));
    sub_8005F488(r_u16(0x80077498u));
    uint16 rotation[9];
    for (uint32 index = 0u; index < 9u; ++index)
        rotation[index] = r_u16(0x1F800020u + index * 2u);
    for (uint32 row = 0u; row < 3u; ++row)
        for (uint32 column = 0u; column < 3u; ++column)
            w_u16(0x1F800000u + (row * 3u + column) * 2u, rotation[column * 3u + row]);
    for (uint32 axis = 0u; axis < 3u; ++axis)
        w_u16(0x1F800020u + axis * 2u,
            0u - (uint32)((sint32)r_u32(0x1F800034u + axis * 4u) >> 1));
    for (uint32 index = 0u; index < 5u; ++index)
        xport_gte_write_control(index, r_u32(0x1F800000u + index * 4u));
    xport_gte_write_data(0u, r_u32(0x1F800020u));
    xport_gte_write_data(1u, r_u32(0x1F800024u));
    xport_gte_execute(0x486012u);
    for (uint32 index = 0u; index < 3u; ++index)
        w_u32(0x1F800028u + index * 4u, xport_gte_read_data(25u + index));
    for (uint32 index = 0u; index < 3u; ++index)
        w_u16(0x1F800020u + index * 2u, r_u32(0x1F800028u + index * 4u));
    sub_80039838(r_u32(a1 + 24u), r_u16(a1 + 2u), 0x1F800020u, (shift << 1u) | 1u);
    uint32 flags = r_u16(a1 + 2u);
    w_u16(0x8007748Cu, flags);
    w_u16(0x80077480u, ((flags & 0x600u) >> 2u) | (flags & 0x6000u));
    w_u16(0x800775A0u, ~((flags & 0x1800u) >> 4u));
    if (!(flags & 1u))
        sub_80039808((sint32)r_u32(a1 + 24u), (sint32)a1);
    /* The original 3979C branch is an empty function */
    uint32 result = r_u32(0x800773C0u);
    w_u32(0x80077354u, result);
    ob_draft_scratch_release(light_matrix);
    return result;
}


uint32 sub_80033528(uint32 a1)
{
    FUNCTION_MARKER(0x80033528u, "SLES_008.65");
  sint32 v1;
  uint32 v2;
  sint32 v3;
  sint32 v4;
  sint32 v5;
  uint32 v6;
  sint8 v7;
  sint8 v8;
  uint32 v9;
  uint32 v10;
  uint16 v11;
  uint32 v12;
  sint32 v13;
  uint32 v14;
  sint32 v15;
  uint32 v16;
  uint32 v17;
  sint32 v18;
  sint8 v19;
  sint8 v20;
  uint32 v21;
  uint32 v22;
  sint32 v23;
  sint32 v24;
  sint32 v25;
  sint32 v26;
  uint16 v27;
  uint16 v28;
  uint32 v29;
  sint32 v30;
  uint32 v31;
  sint16 v32;
  uint32 v33;
  uint32 v34;
  sint32 v35;
  uint32 v36;
  sint8 v37;
  sint8 v38;
  sint32 v39;
  uint32 v40;
  sint32 v41;
  sint8 v42;
  uint32 v43;
  uint32 v44;
  sint32 v45;
  uint32 v46;
  sint32 v47;
  sint32 v48;
  uint32 v49;
  sint32 v50;
  sint8 v51;
  sint8 v52;
  uint32 v53;
  uint32 v54;
  sint32 v55;
  sint32 v56;
  sint32 v57;
  sint32 v58;
  uint16 v59;
  uint16 v60;
  uint32 v61;
  sint32 v62;
  uint32 v63;
  sint16 v64;
  uint32 v65;
  uint32 v66;
  uint32 v67;
  sint32 v68;
  uint32 v69;
  sint8 v70;
  sint8 v71;
  sint32 v72;
  uint32 v73;
  sint32 v74;
  sint8 v75;
  uint32 v76;
  sint32 v77;
  uint32 v78;
  sint32 v79;
  sint32 v80;
  sint32 v81;
  sint32 v82;
  sint32 v83;
  sint32 v84;
  sint32 v85;
  sint32 v86;
  uint32 v87;
  sint32 v88;
  uint32 v89;
  sint32 v90;
  sint32 v91;
  sint32 v92;
  sint32 v93;
  sint32 v94;
  sint32 v95;
  v1 = r_u32(a1);
  sub_8002679C(a1, 1u);
  v2 = a1;
  v3 = r_u32(a1);
  v4 = v1;
  if (((r_u16((uint32)(((uint32)(r_u32(a1)) + (uint32)(2)))) & 0x40) != 0))
  {
    sub_800256CC(r_u32((uint32)((sint32)((uint32)(v3) + (uint32)(80)))));
    v2 = a1;
    v4 = v1;
  }
  v5 = 0;
  sub_80035618(r_u32(v2), v4);
  v6 = r_u32((uint32)((sint32)((uint32)(v3) + (uint32)(52))));
  v7 = r_u8((uint32)((sint32)((uint32)(v3) + (uint32)(25))));
  w_u8((uint32)((sint32)((uint32)(v3) + (uint32)(24))), ((uint32)(r_u8((uint32)((sint32)((uint32)(v3) + (uint32)(24))))) * (uint32)(4)));
  v8 = r_u8((uint32)((sint32)((uint32)(v3) + (uint32)(26))));
  w_u8((uint32)((sint32)((uint32)(v3) + (uint32)(25))), (sint32)((uint32)(4) * (uint32)(v7)));
  v9 = (r_u16((uint32)((sint32)((uint32)(v3) + (uint32)(14)))) == 0);
  w_u8((uint32)((sint32)((uint32)(v3) + (uint32)(26))), (sint32)((uint32)(4) * (uint32)(v8)));
  if (!v9)
  {
    do
    {
      v10 = r_u32(v6);
      v11 = r_u16(r_u32(v6));
      if (((v11 & 1) == 0))
      {
        if (((v11 & 6) == 6))
        {
          v12 = r_u32(v6);
          v13 = r_u16((v10 + (1) * 2u));
          v14 = v10 + 4u * (uint32)v13 + 4u;
          v15 = r_u32(r_u32((uint32)(v14)));
          v16 = v14;
          if (((v15 & 3) != 0))
          {
            v17 = sub_800257CC(r_u32((uint32)(v14)));
          }
          else
          {
            (w_u16((uint32)((sint32)((uint32)(v15) - (uint32)(6))), (r_u16((uint32)((sint32)((uint32)(v15) - (uint32)(6)))) + 1u)), r_u16((uint32)((sint32)((uint32)(v15) - (uint32)(6)))));
            v17 = r_u32(r_u32((uint32)(v14)));
          }
          v18 = ((v17 >> 2) & 0x7FFF);
          v19 = r_u8(((uint32)(v14) + (6) * 1u));
          w_u8(((uint32)(v14) + (4) * 1u), ((uint32)(r_u8(((uint32)(v14) + (4) * 1u))) * (uint32)(4)));
          v20 = r_u8(((uint32)(v14) + (5) * 1u));
          w_u8(((uint32)(v14) + (6) * 1u), (sint32)((uint32)(4) * (uint32)(v19)));
          w_u8(((uint32)(v14) + (5) * 1u), (sint32)((uint32)(4) * (uint32)(v20)));
          v21 = sub_80025700((v17 >> 17));
          v22 = sub_80025700(v18);
          v23 = ((v22 >> 4) & 0xF0);
          v24 = ((v22 >> 8) & 0xF0);
          v25 = ((uint32)(((uint32)((v21 >> 2)) << (uint32)(16))) + (uint32)((uint16)((v22) >> 16)));
          v26 = ((uint8)(v22) >> 4);
          v27 = (sint16)r_u16((0x800735f0u + ((sint32)((uint32)(3) * (uint32)(v26))) * 2u));
          v28 = (sint16)r_u16((0x800735f2u + ((sint32)((uint32)(3) * (uint32)(v26))) * 2u));
          v29 = (uint32)((v14 + (4) * 2u));
          if (((v22 & 4) != 0))
          {
            v30 = 0;
            if (v13)
            {
              v31 = (uint32)((v14 + (5) * 2u));
              do
              {
                v32 = (sint16)r_u16(v29);
                ++v30;
                w_u16(v29, (sint16)r_u16(v31));
                w_u16(v31, v32);
                v31 += (2) * 2u;
                v29 += (2) * 2u;
              }
              while (((sint32)(v30) < (sint32)(v13)));
            }
          }
          v33 = (v14 + (4) * 2u);
          v10 = v33;
          v34 = v33;
          v35 = 0;
          if (v13)
          {
            do
            {
              w_u16(v10, (uint32)v23 + (uint32)((sint32)((uint32)r_u16(v10) * v27) >> 8));
              v36 = (v10 + (1) * 2u);
              ++v35;
              w_u16(v36, (uint32)v24 + (uint32)((sint32)((uint32)r_u16(v36) * v28) >> 8));
              v10 = v36 + 2u;
            }
            while (((sint32)(v35) < (sint32)(v13)));
          }
          v37 = 0;
          v38 = 0;
          v39 = 0;
          if (v13)
          {
            v40 = v33;
            do
            {
              if ((r_u16(v40) >= 0x100u))
                v37 = (sint8)v27;
              if ((r_u16((v40 + (1) * 2u)) >= 0x100u))
                v38 = (sint8)v28;
              ++v39;
              v40 += (2) * 2u;
            }
            while (((sint32)(v39) < (sint32)(v13)));
          }
          v41 = 0;
          if (v13)
          {
            do
            {
              ++v41;
              w_u8((uint32)(v34), ((uint32)(r_u8((uint32)(v33))) - (uint32)(v37)));
              v42 = r_u8(((uint32)(v33) + (2) * 1u));
              v33 += (2) * 2u;
              w_u8(((uint32)(((v34 += 2u) - 2u)) + (1) * 1u), (sint32)((uint32)(v42) - (uint32)(v38)));
            }
            while (((sint32)(v41) < (sint32)(v13)));
          }
          if (((r_u16(v12) & 0x200) != 0))
          {
            w_u8(((uint32)(v16) + (16) * 1u), v23);
            w_u8(((uint32)(v16) + (17) * 1u), v24);
            w_u8(((uint32)(v16) + (18) * 1u), v27);
            w_u8(((uint32)(v16) + (19) * 1u), v28);
          }
          sub_800257A0(r_u32((uint32)(v16)));
          w_u32((uint32)(v16), v25);
        }
        else
          if (((v11 & 4) == 0))
        {
          v44 = r_u32(v6);
          if (((v11 & 2) != 0))
          {
            v45 = r_u16((v10 + (1) * 2u));
            v46 = v10 + 4u * (uint32)v45 + 4u;
            v47 = r_u32((uint32)((sint32)r_u32(v46)));
            v48 = (sint32)(v44 + 4u * (uint32)v45 + 4u);
            if (((v47 & 3) != 0))
            {
              v49 = sub_800257CC((sint32)r_u32(v46));
            }
            else
            {
              (w_u16((uint32)((sint32)((uint32)(v47) - (uint32)(6))), (r_u16((uint32)((sint32)((uint32)(v47) - (uint32)(6)))) + 1u)), r_u16((uint32)((sint32)((uint32)(v47) - (uint32)(6)))));
              v49 = r_u32((uint32)((sint32)r_u32(v46)));
            }
            v50 = ((v49 >> 2) & 0x7FFF);
            v51 = r_u8((uint32)((sint32)((uint32)(v48) + (uint32)(6))));
            w_u8((uint32)((sint32)((uint32)(v48) + (uint32)(4))), ((uint32)(r_u8((uint32)((sint32)((uint32)(v48) + (uint32)(4))))) * (uint32)(4)));
            v52 = r_u8((uint32)((sint32)((uint32)(v48) + (uint32)(5))));
            w_u8((uint32)((sint32)((uint32)(v48) + (uint32)(6))), (sint32)((uint32)(4) * (uint32)(v51)));
            w_u8((uint32)((sint32)((uint32)(v48) + (uint32)(5))), (sint32)((uint32)(4) * (uint32)(v52)));
            v53 = sub_80025700((v49 >> 17));
            v54 = sub_80025700(v50);
            v55 = ((v54 >> 4) & 0xF0);
            v56 = ((v54 >> 8) & 0xF0);
            v57 = ((uint32)(((uint32)((v53 >> 2)) << (uint32)(16))) + (uint32)((uint16)((v54) >> 16)));
            v58 = ((uint8)(v54) >> 4);
            v59 = (sint16)r_u16((0x800735f0u + ((sint32)((uint32)(3) * (uint32)(v58))) * 2u));
            v60 = (sint16)r_u16((0x800735f2u + ((sint32)((uint32)(3) * (uint32)(v58))) * 2u));
            v61 = (uint32)((sint32)((uint32)(v48) + (uint32)(8)));
            if (((v54 & 4) != 0))
            {
              v62 = 0;
              if (v45)
              {
                v63 = (uint32)((sint32)((uint32)(v48) + (uint32)(10)));
                do
                {
                  v64 = (sint16)r_u16(v61);
                  ++v62;
                  w_u16(v61, (sint16)r_u16(v63));
                  w_u16(v63, v64);
                  v63 += (2) * 2u;
                  v61 += (2) * 2u;
                }
                while (((sint32)(v62) < (sint32)(v45)));
              }
            }
            v65 = (v46 + (2) * 4u);
            v66 = v65;
            v67 = v65;
            v68 = 0;
            if (v45)
            {
              do
              {
                w_u16(v66, (uint32)v55 + (uint32)((sint32)((uint32)r_u16(v66) * v59) >> 8));
                v69 = (v66 + (1) * 2u);
                ++v68;
                w_u16(v69, (uint32)v56 + (uint32)((sint32)((uint32)r_u16(v69) * v60) >> 8));
                v66 = (v69 + (1) * 2u);
              }
              while (((sint32)(v68) < (sint32)(v45)));
            }
            v70 = 0;
            v71 = 0;
            v72 = 0;
            if (v45)
            {
              v73 = (uint32)(v65);
              do
              {
                if ((r_u16(v73) >= 0x100u))
                  v70 = (sint8)v59;
                if ((r_u16((v73 + (1) * 2u)) >= 0x100u))
                  v71 = (sint8)v60;
                ++v72;
                v73 += (2) * 2u;
              }
              while (((sint32)(v72) < (sint32)(v45)));
            }
            v74 = 0;
            if (v45)
            {
              do
              {
                ++v74;
                w_u8(v67, ((uint32)(r_u8(v65)) - (uint32)(v70)));
                v75 = r_u8((v65 + (2) * 1u));
                v65 += (4) * 1u;
                w_u8((v67 + (1) * 1u), (sint32)((uint32)(v75) - (uint32)(v71)));
                v67 += (2) * 1u;
              }
              while (((sint32)(v74) < (sint32)(v45)));
            }
            if (((r_u16(v44) & 0x200) != 0))
            {
              w_u8((uint32)((sint32)((uint32)(v48) + (uint32)(16))), v55);
              w_u8((uint32)((sint32)((uint32)(v48) + (uint32)(17))), v56);
              w_u8((uint32)((sint32)((uint32)(v48) + (uint32)(18))), v59);
              w_u8((uint32)((sint32)((uint32)(v48) + (uint32)(19))), v60);
            }
            sub_800257A0(r_u32((uint32)(v48)));
            w_u32((uint32)(v48), v57);
          }
          goto LABEL_51;
        }
      }
      v43 = v10 + 4u * r_u16(v10 + 2u) + 4u;
      w_u8((uint32)(v43), ((uint32)(r_u8((uint32)(v43))) * (uint32)(4)));
      v43 = (uint32)(((uint32)(v43) + (1) * 1u));
      w_u8((uint32)(v43), ((uint32)(r_u8((uint32)(v43))) * (uint32)(4)));
      w_u8(((uint32)(v43) + (1) * 1u), ((uint32)(r_u8(((uint32)(v43) + (1) * 1u))) * (uint32)(4)));
      LABEL_51:
      ++v5;

      ((v6 += 4u));
    }
    while ((v5 < r_u16((uint32)((sint32)((uint32)(v3) + (uint32)(14))))));
  }
  v76 = r_u32((uint32)((sint32)((uint32)(v3) + (uint32)(44))));
  v77 = 0;
  if (r_u16((uint32)((sint32)((uint32)(v3) + (uint32)(16)))))
  {
    v78 = (uint32)((v76 + (4) * 2u));
    do
    {
      v79 = (sint16)r_u16(v76);
      if (((sint32)(v79) >= (sint32)(0)))
        v80 = (sint32)((uint32)(v79) + (uint32)(2));
      else
        v80 = (sint32)((uint32)(v79) - (uint32)(2));
      w_u16(v76, ((sint32)(v80) >> 2));
      v81 = (sint16)r_u16(((uint32)(v78) - (3) * 2u));
      if (((sint32)(v81) >= (sint32)(0)))
        v82 = (sint32)((uint32)(v81) + (uint32)(2));
      else
        v82 = (sint32)((uint32)(v81) - (uint32)(2));
      w_u16(((uint32)(v78) - (3) * 2u), ((sint32)(v82) >> 2));
      v83 = (sint16)r_u16(((uint32)(v78) - (2) * 2u));
      if (((sint32)(v83) >= (sint32)(0)))
        v84 = (sint32)((uint32)(v83) + (uint32)(2));
      else
        v84 = (sint32)((uint32)(v83) - (uint32)(2));
      w_u16(((uint32)(v78) - (2) * 2u), ((sint32)(v84) >> 2));
      v85 = (sint32)r_u32(v78);
      if (((sint32)((sint32)r_u32(v78)) >= (sint32)(0)))
        v86 = (sint32)((uint32)(v85) + (uint32)(0x2000));
      else
        v86 = (sint32)((uint32)(v85) - (uint32)(0x2000));
      w_u32(v78, ((sint32)(v86) >> 14));
      v78 += (3) * 4u;
      ++v77;
      v76 += (6) * 2u;
    }
    while ((v77 < r_u16((uint32)((sint32)((uint32)(v3) + (uint32)(16))))));
  }
  v87 = r_u32((uint32)((sint32)((uint32)(v3) + (uint32)(48))));
  v88 = 0;
  if (r_u16((uint32)((sint32)((uint32)(v3) + (uint32)(18)))))
  {
    v89 = (v87 + (2) * 2u);
    do
    {
      v90 = (sint16)r_u16(v87);
      if (((sint32)(v90) >= (sint32)(0)))
        v91 = (sint32)((uint32)(v90) + (uint32)(2));
      else
        v91 = (sint32)((uint32)(v90) - (uint32)(2));
      w_u16(v87, ((sint32)(v91) >> 2));
      v92 = (sint16)r_u16((v89 - (1) * 2u));
      if (((sint32)(v92) >= (sint32)(0)))
        v93 = (sint32)((uint32)(v92) + (uint32)(2));
      else
        v93 = (sint32)((uint32)(v92) - (uint32)(2));
      w_u16((v89 - (1) * 2u), ((sint32)(v93) >> 2));
      v94 = (sint16)r_u16(v89);
      if (((sint32)(v94) >= (sint32)(0)))
        v95 = (sint32)((uint32)(v94) + (uint32)(2));
      else
        v95 = (sint32)((uint32)(v94) - (uint32)(2));
      w_u16(v89, ((sint32)(v95) >> 2));
      v89 += (4) * 2u;
      ++v88;
      v87 += (4) * 2u;
    }
    while ((v88 < r_u16((uint32)((sint32)((uint32)(v3) + (uint32)(18))))));
  }
  return sub_800267C4(a1, 1u);
}



void sub_80022CD4(void)
{
    FUNCTION_MARKER(0x80022CD4u, "SLES_008.65");
    uint32 requested_size = 0x190000u;
    uint32 heap;
    uint32 state = 0u;
    uint32 local = ob_draft_scratch_acquire(8u);
    /* The linked executable contains no constructor entries */
    if (r_u32(0x80075E9Cu) == 0u) w_u32(0x80075E9Cu, 1u);
    /* ResetCallback and CdInit use SDK adapters */
    ob_draft_unresolved_call(0x80059EACu, 0u);
    ob_draft_unresolved_call(0x80055D74u, 0u);
    w_u32(0x80078DC0u, 0u);
    do
    {
        heap = ob_draft_unresolved_call(0x80064008u, 1u, requested_size);
        w_u32(0x80078DC0u, heap);
        requested_size -= 0x400u;
    } while (heap == 0u && !xport_isquit());
    if (xport_isquit()) { ob_draft_scratch_release(local); return; }
    sub_80025DA0(heap, requested_size);
    ob_draft_unresolved_call(0x80055D74u, 0u);
    sub_80024EA8();
    sub_80054CFC();
    ob_draft_unresolved_call(0x80055D74u, 0u);
    while (ob_draft_unresolved_call(0x80055FD8u, 2u, 0u, local) != 2u)
        if (xport_isquit()) { ob_draft_scratch_release(local); return; }
    sub_80026694(local + 4u, 0xEA60u, 0u);
    sub_800556F4();
    sub_80026758(local + 4u);
    ob_draft_unresolved_call(0x80055D74u, 0u);
    while (ob_draft_unresolved_call(0x80055FD8u, 2u, 0u, local) != 2u)
        if (xport_isquit()) { ob_draft_scratch_release(local); return; }
    sub_80024F24(0x8001087Cu);
    sub_80055808();
    sub_80023138();
    sub_8005491C();
    sub_80054B30();
    sub_8002328C();
    sub_8002439C();
    sub_800123E4();
    sub_80024320();
    sub_80023A10();
    sub_80024320();
    sub_800170D0();
    sub_80023C08();
    sub_80023AA8();
    sub_8001CF58();
    sub_8001DF58(r_u8(0x8006C22Eu));
    sub_8001DF34(r_u8(0x8006C22Du));
    while (!xport_isquit())
    {
        sub_80023308(state == 5u ? 2u : 0u);
        sub_8002439C();
        state = sub_80024400();
    }
    ob_draft_scratch_release(local);
}
