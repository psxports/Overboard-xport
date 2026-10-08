#include "draft_signatures.h"

/* Unverified draft bodies */

uint32 sub_80013FA4(uint32 a1)
{
    FUNCTION_MARKER(0x80013fa4u, "SLES_008.65");
    /* TODO: Bind external adapter for sub_80064028 */
    /* TODO: Bind external adapter for sub_80013908 */
    /* TODO: Bind external adapter for sub_80020FD4 */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Bind external adapter for sub_80020D64 */
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Bind external adapter for sub_80020A70 */
    /* TODO: Bind external adapter for sub_800260C8 */
    /* TODO: Bind external adapter for sub_80063FB8 */
    /* TODO: Bind external adapter for sub_80014BF8 */
    /* TODO: Bind external adapter for sub_80015374 */
    /* TODO: Bind external adapter for sub_80015B1C */
    /* TODO: Bind external adapter for sub_80020864 */
    /* TODO: Bind external adapter for nullsub_16 */
    uint32 local_objects = ob_draft_scratch_acquire(164u);
    uint32 literal_0 = ob_draft_scratch_acquire(4u);
    w_u8(literal_0 + 0u, 120u);
    w_u8(literal_0 + 1u, 37u);
    w_u8(literal_0 + 2u, 100u);
    w_u8(literal_0 + 3u, 0u);
  sint16 v2;
  sint16 v3;
  sint32 v4;
  uint32 v5;
  sint32 v6;
  sint16 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  sint32 v11;
  sint32 v12;
  sint32 v13;
  sint32 v14;
  uint32 v15;
  sint32 v16;
  sint32 v17;
  sint32 v18;
  sint32 v19;
  sint32 v20;
  sint32 v21;
  sint32 v22;
  sint16 v23;
  sint32 v24;
  sint32 v25;
  sint32 v26;
  sint16 v27;
  sint32 v28;
  uint32 v29;
  sint32 v30;
  sint32 v31;
  sint32 v32;
  sint32 v33;
  sint32 v34;
  sint32 v35;
  sint32 v36;
  uint32 v37;
  sint32 v38;
  sint32 v39;
  uint32 v40;
  sint32 v41;
  sint32 v42;
  sint32 v43;
  sint32 v44;
  sint32 v45;
  sint32 v46;
  sint32 v47;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  v2 = 0;
  v3 = 0;
  v4 = 1;
  v5 = 0x8006c138u;
  w_u32(0x8006c174u, 1);
  v6 = (sint32)r_u32((0x8006c138u + (r_u16(0x800C4E70)) * 4u));
  w_u32(0x80065d30u, (((uint32)((uint8)((sint32)r_u32(0x80065d30u))) + (uint32)(1)) & 3));
  v7 = (sint32)(0u - (uint32)(1));
  if (v6)
  {
    v8 = r_u32((uint32)((sint32)((uint32)(v6) + (uint32)(108))));
    if ((((sint8)r_u8(0x8006c230u) == 1) && (sint32)r_u32((0x8006c138u + (0) * 4u))))
    {
      sub_8001578C(0, 12, 220, 0);
      ob_draft_unresolved_call(0x80064028u, 4u, (local_objects + 0u), 0x80010110u, (sint16)r_u16((uint32)((sint32)((uint32)(v8) + (uint32)(32)))), r_u16(0x800D649C));
      ob_draft_unresolved_call(0x80013908u, 2u, (local_objects + 0u), (sint32)((uint32)((sint32)((uint32)(18) * (uint32)((sint32)r_u32(0x8006c174u)))) + (uint32)(12)));
      ob_draft_unresolved_call(0x80020fd4u, 4u, (0x80066674u), 0, 0, 15);
      ob_draft_unresolved_call(0x80064028u, 3u, (local_objects + 0u), literal_0, r_u8((uint32)((sint32)((uint32)(v8) + (uint32)(44)))));
      ob_draft_unresolved_call(0x80013908u, 2u, (local_objects + 0u), ((sint32)((uint32)(16) * (uint32)((sint32)r_u32(0x8006c174u))) | 0xC));
      ob_draft_unresolved_call(0x80020fd4u, 4u, (sint32)r_u32(0x80066678u), 0, 0, 15);
    }
    w_u32(0x8007FA98, (sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(2) * (uint32)((sint32)r_u32(0x8006c174u)))) + (uint32)((sint32)((uint32)(16) * (uint32)((sint32)r_u32(0x8006c174u)))))) + (uint32)(20)));
    v5 = (uint32)((sint32)((uint32)(32) * (uint32)((sint32)r_u32(0x8006c174u))));
    w_u32(0x8007FA94, (sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(369) - (uint32)((sint32)((uint32)(5) * (uint32)((sint32)r_u32(0x8006c174u)))))) - (uint32)((sint32)((uint32)(32) * (uint32)((sint32)r_u32(0x8006c174u)))))) + (uint32)((sint32)((uint32)(16) * (uint32)((sint32)r_u32(0x8006c174u))))));
    if (((sint8)r_u8(0x8006c230u) == 1))
    {
      sub_8002F284((sint32)(0u - (uint32)(2146931856)), (local_objects + 64u));
      v9 = (((uint32)((uint16)((sint32)(0u - (uint32)((sint16)r_u16(((local_objects + 64u) + (0) * 2u)))))) + (uint32)(8)) >> 4);
      v10 = (sint32)((uint32)((sint32)((uint32)((sint32)r_u32(0x8006c174u)) * (uint32)(31))) * (uint32)((sint16)r_u16((0x8006cb04u + (v9) * 2u))));
      v11 = (sint32)((uint32)((sint32)((uint32)((sint32)r_u32(0x8006c174u)) * (uint32)(31))) * (uint32)((sint16)r_u16((0x8006cb04u + ((sint32)((uint32)(v9) - (uint32)(1024))) * 2u))));
      v12 = ((sint32)((sint32)((sint32)((uint32)(((sint32)(v10) / (sint32)(0x4000))) + (uint32)(((uint32)((sint32)((uint32)(v10) + (uint32)((((sint32)(v10) < (sint32)(0))) ? (0x3FFF) : (0)))) >> 31))))) >> 1);
      v13 = ((sint32)((sint32)((sint32)((uint32)(((sint32)(v11) / (sint32)(0x4000))) + (uint32)(((uint32)((sint32)((uint32)(v11) + (uint32)((((sint32)(v11) < (sint32)(0))) ? (0x3FFF) : (0)))) >> 31))))) >> 1);
      w_u32(local_objects + 32u, ((uint32)((sint32)r_u32(local_objects + 32u)) & ~((uint32)65535u << 0) | (((uint32)((sint32)((uint32)((sint32)((uint32)((sint32)r_u32(0x8007FA94)) - (uint32)(v12))) - (uint32)(v13))) & 65535u) << 0)));
      w_u32(local_objects + 32u, ((uint32)((sint32)r_u32(local_objects + 32u)) & ~((uint32)65535u << 16) | (((uint32)((sint32)((uint32)((sint32)((uint32)((sint32)r_u32(0x8007FA98)) + (uint32)(v13))) - (uint32)(v12))) & 65535u) << 16)));
      w_u16(local_objects + 40u, (sint32)((uint32)((sint32)r_u32(local_objects + 32u)) + (uint32)(((sint32)(v10) / (sint32)(0x4000)))));
      w_u16(local_objects + 42u, ((uint32)((uint16)(((sint32)r_u32(local_objects + 32u)) >> 16)) - (uint32)(((sint32)(v11) / (sint32)(0x4000)))));
      w_u16(local_objects + 56u, (sint32)((uint32)((sint16)r_u16(local_objects + 40u)) + (uint32)(((sint32)(v11) / (sint32)(0x4000)))));
      w_u16(local_objects + 48u, (sint32)((uint32)((sint32)r_u32(local_objects + 32u)) + (uint32)(((sint32)(v11) / (sint32)(0x4000)))));
      w_u16(local_objects + 50u, ((uint32)((uint16)(((sint32)r_u32(local_objects + 32u)) >> 16)) + (uint32)(((sint32)(v10) / (sint32)(0x4000)))));
      w_u16(local_objects + 58u, (sint32)((uint32)((sint16)r_u16(local_objects + 42u)) + (uint32)(((sint32)(v10) / (sint32)(0x4000)))));
      ob_draft_unresolved_call(0x80020d64u, 4u, (sint32)r_u32(0x80066668u), 0, 0, 31);
    }
    v4 = (uint8)((sint8)r_u8(0x8006c230u));
    v14 = 0;
    if (((sint8)r_u8(0x8006c230u) == 1))
    {
      if (((sint32)r_u32((0x8006c138u + (0) * 4u)) && (r_u32((uint32)((sint32)((uint32)((sint32)r_u32((0x8006c138u + (0) * 4u))) + (uint32)(288)))) == 20)))
        w_u32(0x80089B78, (uint8)((sint8)r_u8(0x8006c230u)));
    }
    else
    {
      v5 = 0;
      if ((sint8)r_u8(0x8006c230u))
      {
        v15 = 0x8006c138u;
        do
        {
          if (((sint32)r_u32(v15) && (r_u32((uint32)((sint32)((uint32)((sint32)r_u32(v15)) + (uint32)(288)))) == 20)))
            ++v14;
          v5 = (uint32)(((uint32)(v5) + (1) * 1u));
          ((v15 += 4u));
        }
        while (((sint32)(v5) < (uint8)((sint8)r_u8(0x8006c230u))));
      }
      if ((v14 == (sint32)((uint32)((sint8)r_u8(0x8006c235u)) - (uint32)(1))))
        w_u32(0x80089B78, 1);
    }
  }
  if ((sint32)r_u32(0x800C8358))
  {
    v16 = (sint32)r_u32(0x800C835C);
    v17 = (sint32)((uint32)(16) * (uint32)((sint32)r_u32(0x800C835C)));
    if (((sint32)((sint32)r_u32(0x800C835C)) < (sint32)(0)))
    {
      v16 = 0;
      v17 = 0;
    }
    v18 = (sint32)((uint32)((sint32)((uint32)(4) * (uint32)((sint32)((uint32)(v17) - (uint32)(v16))))) - (uint32)(v16));
    if (!(sint32)r_u32(0x800D6498))
      ob_draft_unresolved_call(0x80013fa4u, 2u, 7u, 0);
    if ((((sint32)r_u32(0x800D6498) == (sint32)(0u - (uint32)(1))) && (v18 == 0x80000000)))
      ob_draft_unresolved_call(0x80013fa4u, 2u, 6u, 0);
    ob_draft_unresolved_call(0x80020a70u, 4u, (sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(3) * (uint32)((sint32)r_u32(0x8006c174u)))) + (uint32)(361))) - (uint32)((sint32)((uint32)((sint32)r_u32(0x8006c174u)) << (uint32)(6)))), (sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(4) * (uint32)((sint32)r_u32(0x8006c174u)))) + (uint32)(236))) - (uint32)((sint32)((uint32)(16) * (uint32)((sint32)r_u32(0x8006c174u))))), (sint32)((uint32)(((sint32)(v18) / (sint32)((sint32)r_u32(0x800D6498)))) * (uint32)((sint32)r_u32(0x8006c174u))), (sint32)((uint32)(10) * (uint32)((sint32)r_u32(0x8006c174u))));
    ob_draft_unresolved_call(0x80020fd4u, 4u, (0x80066684u), 0, 0, 63);
  }
  if (((r_u8(0x8008AE69) & 1) != 0))
  {
    ob_draft_unresolved_call(0x800260c8u, 1u, (local_objects + 32u));
    ob_draft_unresolved_call(0x80064028u, 3u, (local_objects + 72u), 0x80010120u, (sint32)r_u32(local_objects + 32u));
    ob_draft_unresolved_call(0x80013908u, 2u, (local_objects + 72u), 12);
    ob_draft_unresolved_call(0x80064028u, 4u, (local_objects + 72u), 0x80010128u, (sint32)((uint32)(80) - (uint32)((sint32)r_u32(0x8007755cu))), 80);
    v19 = ob_draft_unresolved_call(0x80063fb8u, 1u, (local_objects + 72u));
    ob_draft_unresolved_call(0x80013908u, 2u, (local_objects + 72u), (sint32)((uint32)(369) - (uint32)((sint32)((uint32)(10) * (uint32)(v19)))));
    v20 = (sint32)((uint32)((sint32)r_u32(0x800882BC)) - (uint32)((sint32)r_u32(0x80077658u)));
    if (((sint32)((sint32)((uint32)((sint32)r_u32(0x800882BC)) - (uint32)((sint32)r_u32(0x80077658u)))) <= (sint32)(0)))
      v20 = 1;
    ob_draft_unresolved_call(0x80064028u, 3u, (local_objects + 72u), 0x80010138u, ((sint32)(1000) / (sint32)(v20)));
    v21 = ob_draft_unresolved_call(0x80063fb8u, 1u, (local_objects + 72u));
    ob_draft_unresolved_call(0x80013908u, 2u, (local_objects + 72u), (sint32)((uint32)(369) - (uint32)((sint32)((uint32)(10) * (uint32)(v21)))));
    if ((sint32)r_u32(0x8006c134u))
    {
      sub_80045378(r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x8006c134u)) + (uint32)(44)))), (sint32)r_u32(0x800882BC), (local_objects + 152u));
      v22 = r_u32((uint32)((sint32)r_u32(0x80077644u)));
      if (!(r_u32((uint32)((sint32)r_u32(0x80077644u)))))
        ob_draft_unresolved_call(0x80013fa4u, 2u, 7u, 0);
      if (((v22 == (sint32)(0u - (uint32)(1))) && ((sint32)((uint32)((sint32)r_u32(((local_objects + 152u) + (0) * 4u))) + (uint32)((sint32)r_u32(0x80077458u))) == 0x80000000)))
        ob_draft_unresolved_call(0x80013fa4u, 2u, 6u, 0);
      v23 = ((sint32)((uint32)((sint32)r_u32(((local_objects + 152u) + (0) * 4u))) + (uint32)((sint32)r_u32(0x80077458u))) / r_u32((uint32)((sint32)r_u32(0x80077644u))));
      if (!v22)
        ob_draft_unresolved_call(0x80013fa4u, 2u, 7u, 0);
      if (((v22 == (sint32)(0u - (uint32)(1))) && ((sint32)((uint32)((sint32)r_u32(0x80077468u)) - (uint32)((sint32)r_u32(local_objects + 160u))) == 0x80000000)))
        ob_draft_unresolved_call(0x80013fa4u, 2u, 6u, 0);
      v24 = ((sint32)((sint32)((uint32)((sint32)r_u32(0x80077468u)) - (uint32)((sint32)r_u32(local_objects + 160u)))) / (sint32)(v22));
      ob_draft_unresolved_call(0x80064028u, 4u, (local_objects + 72u), 0x80010144u, (sint32)r_u32(((local_objects + 152u) + (0) * 4u)), (sint32)r_u32(local_objects + 160u));
      v25 = ob_draft_unresolved_call(0x80063fb8u, 1u, (local_objects + 72u));
      ob_draft_unresolved_call(0x80013908u, 2u, (local_objects + 72u), (sint32)((uint32)(192) - (uint32)((sint32)((uint32)(5) * (uint32)(v25)))));
      ob_draft_unresolved_call(0x80064028u, 4u, (local_objects + 72u), 0x80010154u, v23, (sint16)(v24));
      v26 = ob_draft_unresolved_call(0x80063fb8u, 1u, (local_objects + 72u));
      ob_draft_unresolved_call(0x80013908u, 2u, (local_objects + 72u), (sint32)((uint32)(192) - (uint32)((sint32)((uint32)(5) * (uint32)(v26)))));
    }
    w_u32(0x80077658u, (sint32)r_u32(0x800882BC));
  }
  v27 = 0;
  if (((uint8)((sint8)r_u8(0x8006c230u)) < 2u))
  {
    ob_draft_unresolved_call(0x80014bf8u, 1u, 0);
  }
  else
  {
    v28 = 0;
    if ((sint8)r_u8(0x8006c230u))
    {
      v29 = 0x8006c138u;
      do
      {
        v5 = (uint32)((sint32)((uint32)(v28) << (uint32)(16)));
        if ((sint32)r_u32(v29))
          ob_draft_unresolved_call(0x80015374u, 2u, (sint16)(v28), v27++);
        ++v28;
        ((v29 += 4u));
      }
      while ((v28 < (uint8)((sint8)r_u8(0x8006c230u))));
    }
    if ((((sint32)((sint8)r_u8(0x8006c248u)) > (sint32)(0)) && !(sint16)r_u16(0x80076880u)))
    {
      if (((sint32)((sint32)r_u32(0x8008969C)) >= (sint32)((sint32)((uint32)(100) * (uint32)((sint32)((uint32)((sint32)((uint32)(30) * (uint32)((sint8)r_u8(0x8006c248u)))) + (uint32)(30)))))))
      {
        v31 = (sint32)((uint32)((sint32)((uint32)(30) * (uint32)((sint8)r_u8(0x8006c248u)))) + (uint32)(30));
      }
      else
      {
        v4 = (sint32)(0x8006c138u);
        v30 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32((0x8006c138u + (r_u16(0x800C4E70)) * 4u))) + (uint32)(288))));
        v31 = ((sint32)((sint32)r_u32(0x8008969C)) / (sint32)(100));
        if ((((v30 != 3) && (v30 != 22)) && !v31))
        {
          v32 = 0;
          if ((sint8)r_u8(0x8006c230u))
          {
            v33 = 0;
            while (1)
            {
              v34 = (sint32)r_u32((uint32)(((uint32)(0x8006c138u) + (((sint32)(v33) >> 14)) * 1u)));
              if (!v34)
                goto LABEL_65;
              v35 = r_u32((uint32)((sint32)((uint32)(v34) + (uint32)(288))));
              if (((v35 == 3) || (v35 == 22)))
                goto LABEL_65;
              v4 = (sint16)r_u16((uint32)((sint32)((uint32)((sint32)((uint32)(104) * (uint32)((sint16)r_u16((uint32)((sint32)((uint32)(v34) + (uint32)(326))))))) - (uint32)(2146649530))));
              if (((sint32)(v3) < (sint32)(v4)))
                break;
              v36 = (sint32)((uint32)(v32) + (uint32)(1));
              if ((v4 == v3))
              {
                ++v2;
                goto LABEL_65;
              }
              LABEL_66:
              v32 = v36;

              v37 = ((sint32)((sint16)(v36)) < (sint32)((sint32)((uint8)((sint8)r_u8(0x8006c230u)))));
              v33 = (sint32)((uint32)(v36) << (uint32)(16));
              if (!v37)
                goto LABEL_67;
            }

            v3 = r_u16((uint32)((sint32)((uint32)((sint32)((uint32)(104) * (uint32)((sint16)r_u16((uint32)((sint32)((uint32)(v34) + (uint32)(326))))))) - (uint32)(2146649530))));
            v2 = 1;
            v7 = v32;
            LABEL_65:
            v36 = (sint32)((uint32)(v32) + (uint32)(1));

            goto LABEL_66;
          }
          LABEL_67:
          v38 = 0;

          if ((sint8)r_u8(0x8006c230u))
          {
            v39 = 0;
            do
            {
              v40 = ((0x8006c138u + (((sint32)(v39) >> 16)) * 4u));
              v4 = (sint32)r_u32(v40);
              if ((sint32)r_u32(v40))
              {
                if ((((sint32)(v39) >> 16) == v7))
                {
                  v41 = (sint32)((uint32)(v38) + (uint32)(1));
                  if ((v2 == 1))
                    goto LABEL_76;
                }
                v42 = r_u32((uint32)((sint32)((uint32)(v4) + (uint32)(288))));
                v41 = (sint32)((uint32)(v38) + (uint32)(1));
                if ((v42 == 3))
                  goto LABEL_76;
                v41 = (sint32)((uint32)(v38) + (uint32)(1));
                if ((v42 == 22))
                  goto LABEL_76;
                w_u8((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(v4) + (uint32)(108))))) + (uint32)(46))), 0);
                ob_draft_unresolved_call((sint32)r_u32(0x800B3210), 2u, (sint32)r_u32(v40), a1);
              }
              v41 = (sint32)((uint32)(v38) + (uint32)(1));
              LABEL_76:
              v38 = v41;

              v37 = ((sint32)((sint16)(v41)) < (sint32)((sint32)((uint8)((sint8)r_u8(0x8006c230u)))));
              v39 = (sint32)((uint32)(v41) << (uint32)(16));
            }
            while (v37);
          }
          w_u16(0x80076880u, 1);
        }
      }
      ob_draft_unresolved_call(0x80015b1cu, 2u, v31, v4);
    }
    v43 = 0;
    if ((((uint32)((sint32)((uint32)((sint32)((uint32)(a1) - (uint32)((sint32)r_u32(0x8007687cu)))) - (uint32)(2001))) < 0xBB7) || (sint8)r_u8(0x8006c249u)))
    {
      v44 = 0;
      if ((sint8)r_u8(0x8006c230u))
      {
        v45 = 0;
        do
        {
          v46 = (sint32)r_u32((0x8006c138u + (((sint32)(v45) >> 16)) * 4u));
          if (v46)
          {
            sub_8004EEF4(((uint32)(r_u32((uint32)((sint32)((uint32)(v46) + (uint32)(44))))) + (uint32)(108)), (local_objects + 152u));
            v47 = v44++;
            ob_draft_unresolved_call(0x80020864u, 4u, (sint32)r_u32((0x80065cf8u + (v47) * 4u)), 0, 0, 15);
          }
          v45 = (sint32)((uint32)(++v43) << (uint32)(16));
        }
        while (((sint32)((sint16)(v43)) < (sint32)((sint32)((uint8)((sint8)r_u8(0x8006c230u))))));
      }
    }
  }
  { uint32 draft_return = ob_draft_unresolved_call(0x800170c0u, 1u, v5); ob_draft_scratch_release(local_objects); ob_draft_scratch_release(literal_0);  return draft_return; }
}


void sub_8003858C(uint32 a1)
{
    FUNCTION_MARKER(0x8003858cu, "SLES_008.65");
    /* TODO: Bind external adapter for sub_800322BC */
    /* TODO: Bind external adapter for sub_8002E968 */
    /* TODO: Bind external adapter for sub_8002FA88 */
    /* TODO: Recover inline assembly or exception adapter semantics from the original listing */
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Bind external adapter for sub_8003A064 */
    /* TODO: Bind external adapter for sub_8005F288 */
    /* TODO: Bind external adapter for sub_8005F3C8 */
    /* TODO: Bind external adapter for sub_8002FD68 */
    /* TODO: Bind external adapter for sub_8005F398 */
    /* TODO: Bind external adapter for sub_8005F428 */
    /* TODO: Bind external adapter for sub_8003803C */
    /* TODO: Bind external adapter for sub_80037F0C */
    /* TODO: Bind external adapter for nullsub_24 */
    /* TODO: Bind external adapter for nullsub_23 */
    /* TODO: Bind external adapter for sub_800397AC */
    /* TODO: Bind external adapter for sub_800355F4 */
    uint32 local_objects = ob_draft_scratch_acquire(304u);
  uint32 v2;
  sint32 v3;
  sint32 v4;
  sint16 v5;
  sint8 v6;
  uint32 v7;
  sint32 v8;
  sint32 v9;
  sint32 v10;
  sint32 v11;
  uint32 v12;
  uint32 v13;
  sint32 v14;
  sint32 v15;
  sint32 v16;
  sint32 v17;
  sint32 v18;
  sint32 v19;
  uint32 v20;
  sint32 v21;
  sint32 v22;
  sint32 v23;
  sint32 v24;
  sint32 v25;
  sint32 v26;
  sint32 v27;
  sint32 v28;
  uint32 v29;
  uint32 v30;
  uint32 v31;
  sint32 v32;
  sint32 v33;
  uint32 v34;
  sint32 v35;
  sint32 v36;
  uint32 v37;
  sint16 v38;
  sint16 v39;
  sint32 v40;
  sint32 v41;
  sint32 v42;
  sint32 v43;
  sint32 v44;
  sint32 v45;
  sint32 v46;
  sint32 v47;
  sint32 v48;
  sint32 v49;
  sint32 v50;
  sint32 v51;
  uint32 v52;
  sint32 v53;
  sint16 v54;
  uint32 v55;
  uint32 v56;
  uint32 v57;
  sint32 v58;
  sint16 v59;
  sint32 v60;
  sint32 v61;
  sint32 v62;
  sint32 v63;
  uint32 v64;
  sint32 i;
  uint32 v66;
  sint32 v67;
  sint32 v68;
  ;
  sint32 v70;
  sint32 v71;
  sint32 v72;
  sint32 v73;
  sint32 v74;
  sint32 v75;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  v2 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))));
  w_u32(0x80077350u, (sint16)r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(4)))));
  v3 = 0;
  if (((sint32)((uint32)((sint32)r_u32(0x800775bcu)) - (uint32)((sint32)r_u32(0x800774a8u))) >= (sint32)((uint32)r_u16(v2 + 14u) << 6)))
  {
    if (((r_u16((v2 + (1) * 2u)) & 0x20) != 0))
    {
      sub_800415E4(a1);
      { ob_draft_scratch_release(local_objects);  return; }
    }
    if (((r_u8((uint32)((sint32)((uint32)(a1) + (uint32)(1)))) & 1) == 0))
    {
      sub_80039100(a1);
      w_u16(0x80077324u, 0);
      { ob_draft_scratch_release(local_objects);  return; }
    }
    if ((sint32)r_u32(0x800774ccu))
    {
      if (((!(sint16)r_u16(0x80077324u) && !(r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(52)))))) && (((sint32)((sint32)((uint32)((sint32)r_u32(0x800775c8u)) * (uint32)((uint16)(r_u16((v2 + (4) * 2u)))))) >> 8) < (sint32)r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(20)))))))
      {
        goto LABEL_14;
      }
    }
    else
      if ((!(r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(52))))) && (((sint32)((sint32)((uint32)((sint32)r_u32(0x800775c8u)) * (uint32)((uint16)(r_u16((v2 + (4) * 2u)))))) >> 8) < (sint32)r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(20)))))))
    {
      w_u16(0x80077324u, 0);
      LABEL_14:
      sub_80039100(a1);

      { ob_draft_scratch_release(local_objects);  return; }
    }
    w_u32(0x800773c0u, (sint32)r_u32(0x80077354u));
    v4 = sub_8002D98C(528);
    w_u32(0x800775c4u, (sint32)((uint32)(v4) + (uint32)(120)));
    w_u32(0x8007736cu, v4);
    w_u32(0x80077560u, (sint32)((uint32)(v4) + (uint32)(240)));
    w_u16(0x80077638u, 0);
    if ((sint32)r_u32(0x800774ccu))
    {
      v5 = (sint16)r_u16(0x80077324u);
      if (((sint16)r_u16(0x80077324u) || r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(52))))))
      {
        if (ob_draft_unresolved_call(0x800322bcu, 1u, a1))
        {
          w_u16(0x80077324u, v5);
          { ob_draft_scratch_release(local_objects);  return; }
        }
        w_u16(0x80077324u, v5);
      }
    }
    else
      if (r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(52)))))
    {
      if (ob_draft_unresolved_call(0x800322bcu, 1u, a1))
        { ob_draft_scratch_release(local_objects);  return; }
    }
    else
    {
      w_u16(0x80077324u, 0);
    }
    v6 = r_u8((uint32)((sint32)((uint32)(a1) + (uint32)(1))));
    v7 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(28))));
    w_u8((uint32)((sint32)((uint32)(a1) + (uint32)(1))), r_u16((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))))) + (uint32)(4)))));
    v8 = r_u32((v7 + (7) * 4u));
    v9 = r_u32((v7 + (8) * 4u));
    v70 = r_u32((v7 + (6) * 4u));
    v71 = v8;
    v72 = v9;
    v10 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(28))));
    v11 = r_u32((uint32)((sint32)((uint32)(v10) + (uint32)(48))));
    v12 = (local_objects + 80u);
    if (((v11 & 0x100) != 0))
    {
      v13 = (uint32)((sint32)r_u32(0x800775d0u));
      v14 = (sint32)((uint32)((sint32)r_u32(0x800775d0u)) + (uint32)(80));
      do
      {
        v15 = r_u32((v13 + (1) * 4u));
        v16 = r_u32((v13 + (2) * 4u));
        v17 = r_u32((v13 + (3) * 4u));
        w_u32((uint32)(v12), r_u32(v13));
        w_u32(((uint32)(v12) + (1) * 4u), v15);
        w_u32(((uint32)(v12) + (2) * 4u), v16);
        w_u32(((uint32)(v12) + (3) * 4u), v17);
        v13 += (4) * 4u;
        v12 += (8) * 2u;
      }
      while ((v13 != (uint32)(v14)));
    }
    else
    {
      w_u32((uint32)((sint32)((uint32)(v10) + (uint32)(48))), (v11 & 0xFFFFFFDF));
      ob_draft_unresolved_call(0x8002e968u, 3u, r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(28)))), (sint32)r_u32(0x800775d0u), (sint32)((local_objects + 80u)));
    }
    w_u16(local_objects + 82u, (sint32)(0u - (uint32)((sint16)r_u16(local_objects + 82u))));
    w_u16(local_objects + 94u, (sint32)(0u - (uint32)((sint16)r_u16(local_objects + 94u))));
    w_u16(local_objects + 88u, (sint32)(0u - (uint32)((sint16)r_u16(local_objects + 88u))));
    w_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(28))))) + (uint32)(48))), ((uint32)(r_u32((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(28))))) + (uint32)(48))))) | (uint32)(0x20u)));
    v18 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(16))));
    v19 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(20))));
    w_u32(local_objects + 104u, r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(12)))));
    w_u32(local_objects + 112u, v19);
    w_u32(local_objects + 108u, (sint32)(0u - (uint32)(v18)));
    w_u32(local_objects + 128u, ((uint32)((sint32)r_u32(local_objects + 128u)) | (uint32)(0x20u)));
    v20 = (((uint32)(r_u16((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(28))))) + (uint32)(76))))) * (uint32)((uint32)(r_u16((uint32)(((uint32)(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))))) + (uint32)(8))))))) >> 8);
    if (((uint16)(v20) > 0xFF00u))
      v20 = ((uint32)(v20) & ~((uint32)65535u << 0) | (((uint32)((sint32)(0u - (uint32)(256))) & 65535u) << 0));
    ob_draft_unresolved_call(0x8002fa88u, 2u, (sint32)((local_objects + 80u)), v20);
    sub_80042928((local_objects + 80u), (local_objects + 160u));
    w_u16(0x80077364u, 0);
    if (((sint32)((sint32)r_u32(local_objects + 184u)) <= (sint32)(0)))
      v21 = ((sint32)(0u - (uint32)r_u16(local_objects + 236u)) >> 1);
    else
      v21 = (r_u16(local_objects + 236u) >> 1);
    v22 = (sint32)((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 184u)) << (uint32)(8))) + (uint32)(v21));
    if (!r_u16(local_objects + 236u))
      ob_draft_unresolved_call(0x8003858cu, 2u, 7u, 0);
    if (((r_u16(local_objects + 236u) == (sint32)(0u - (uint32)(1))) && (v22 == 0x80000000)))
      ob_draft_unresolved_call(0x8003858cu, 2u, 6u, 0);
    w_u32(0x800774f8u, (v22 / (sint32)r_u16(local_objects + 236u)));
    if (((sint32)((sint32)r_u32(local_objects + 188u)) <= (sint32)(0)))
      v23 = ((sint32)(0u - (uint32)r_u16(local_objects + 236u)) >> 1);
    else
      v23 = (r_u16(local_objects + 236u) >> 1);
    v24 = (sint32)((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 188u)) << (uint32)(8))) + (uint32)(v23));
    if (((r_u16(local_objects + 236u) == (sint32)(0u - (uint32)(1))) && (v24 == 0x80000000)))
      ob_draft_unresolved_call(0x8003858cu, 2u, 6u, 0);
    w_u32(0x800774fcu, (v24 / (sint32)r_u16(local_objects + 236u)));
    if (((sint32)((sint32)r_u32(local_objects + 192u)) <= (sint32)(0)))
      v25 = ((sint32)(0u - (uint32)r_u16(local_objects + 236u)) >> 1);
    else
      v25 = (r_u16(local_objects + 236u) >> 1);
    v26 = (sint32)((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 192u)) << (uint32)(8))) + (uint32)(v25));
    if (((r_u16(local_objects + 236u) == (sint32)(0u - (uint32)(1))) && (v26 == 0x80000000)))
      ob_draft_unresolved_call(0x8003858cu, 2u, 6u, 0);
    w_u32(0x80077500u, (v26 / (sint32)r_u16(local_objects + 236u)));
    if (((sint32)((sint32)r_u32(0x800773b8u)) <= (sint32)(0)))
      v27 = ((sint32)(0u - (uint32)r_u16(local_objects + 236u)) >> 1);
    else
      v27 = (r_u16(local_objects + 236u) >> 1);
    v28 = (sint32)((uint32)((sint32)((uint32)((sint32)r_u32(0x800773b8u)) << (uint32)(8))) + (uint32)(v27));
    if (((r_u16(local_objects + 236u) == (sint32)(0u - (uint32)(1))) && (v28 == 0x80000000)))
      ob_draft_unresolved_call(0x8003858cu, 2u, 6u, 0);
    w_u32(0x800774acu, (v28 / (sint32)r_u16(local_objects + 236u)));
    if (((v6 & 1) == 0))
      goto LABEL_70;
    v29 = (sint32)r_u32(0x800774f8u);
    if (((sint32)((sint32)r_u32(0x800774f8u)) < (sint32)(0)))
      v29 = (sint32)(0u - (uint32)((sint32)r_u32(0x800774f8u)));
    v30 = (sint32)r_u32(0x800774fcu);
    if (((sint32)((sint32)r_u32(0x800774fcu)) < (sint32)(0)))
      v30 = (sint32)(0u - (uint32)((sint32)r_u32(0x800774fcu)));
    v31 = (sint32)r_u32(0x80077500u);
    v32 = (v29 < (sint32)r_u32(0x80077338u));
    if (((sint32)((sint32)r_u32(0x80077500u)) < (sint32)(0)))
      v31 = (sint32)(0u - (uint32)((sint32)r_u32(0x80077500u)));
    if ((((v32 && (v30 < (sint32)r_u32(0x80077338u))) && (v31 < (sint32)r_u32(0x800775c8u))) && (v33 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24)))), w_u16(0x80077524u, 32760), w_u16(0x8007751eu, 32760), w_u16(0x80077522u, 32760), w_u16(0x8007751cu, 32760), w_u16(0x8007752cu, 32760), w_u16(0x80077520u, 32760), ob_draft_unresolved_call(0x8003a064u, 2u, v33, (local_objects + 160u)))))
    {
      v34 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(28))));
      v35 = v71;
      v36 = v72;
      w_u32((v34 + (6) * 4u), v70);
      w_u32((v34 + (7) * 4u), v35);
      w_u32((v34 + (8) * 4u), v36);
    }
    else
    {
      LABEL_70:
      v37 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(28))));

      v38 = (sint16)r_u16(v37);
      w_u16(((local_objects + 0u) + (1) * 2u), ((sint32)((sint16)r_u16((v37 + (3) * 2u))) >> 2));
      w_u16(((local_objects + 0u) + (2) * 2u), ((sint32)((sint16)r_u16((v37 + (6) * 2u))) >> 2));
      w_u16(((local_objects + 0u) + (3) * 2u), ((sint32)((sint16)r_u16((v37 + (1) * 2u))) >> 2));
      w_u16(((local_objects + 0u) + (4) * 2u), ((sint32)((sint16)r_u16((v37 + (4) * 2u))) >> 2));
      w_u16(((local_objects + 0u) + (5) * 2u), ((sint32)((sint16)r_u16((v37 + (7) * 2u))) >> 2));
      w_u16(((local_objects + 0u) + (6) * 2u), ((sint32)((sint16)r_u16((v37 + (2) * 2u))) >> 2));
      w_u16(((local_objects + 0u) + (7) * 2u), ((sint32)((sint16)r_u16((v37 + (5) * 2u))) >> 2));
      v39 = (sint16)r_u16((v37 + (8) * 2u));
      w_u16(((local_objects + 0u) + (0) * 2u), ((sint32)(v38) >> 2));
      w_u16(((local_objects + 0u) + (8) * 2u), ((sint32)(v39) >> 2));
      ob_draft_unresolved_call(0x8005f288u, 3u, (sint32)(0u - (uint32)(2146924520)), (local_objects + 0u), (local_objects + 272u));
      w_u32(0x80077328u, (sint32)((local_objects + 272u)));
      ob_draft_unresolved_call(0x8005f3c8u, 1u, local_objects + 272u);
      if (!(sint32)r_u32(0x800774ccu))
      {
        w_u32(0x8007759cu, 960);
        w_u32(0x80077530u, 528482368);
      }
      sub_800352B4(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24)))));
      w_u32(0x800775ecu, (sint32)((local_objects + 160u)));
      w_u32(0x80077610u, (sint32)((local_objects + 184u)));
      if (((sint32)((sint32)r_u32(local_objects + 104u)) <= (sint32)(0)))
        v40 = ((sint32)(0u - (uint32)r_u16(local_objects + 156u)) >> 1);
      else
        v40 = (r_u16(local_objects + 156u) >> 1);
      v41 = (sint32)((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 104u)) << (uint32)(8))) + (uint32)(v40));
      if (!r_u16(local_objects + 156u))
        ob_draft_unresolved_call(0x8003858cu, 2u, 7u, 0);
      if (((r_u16(local_objects + 156u) == (sint32)(0u - (uint32)(1))) && (v41 == 0x80000000)))
        ob_draft_unresolved_call(0x8003858cu, 2u, 6u, 0);
      v73 = (v41 / (sint32)r_u16(local_objects + 156u));
      if (((sint32)((sint32)r_u32(local_objects + 108u)) <= (sint32)(0)))
        v42 = ((sint32)(0u - (uint32)r_u16(local_objects + 156u)) >> 1);
      else
        v42 = (r_u16(local_objects + 156u) >> 1);
      v43 = (sint32)((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 108u)) << (uint32)(8))) + (uint32)(v42));
      if (((r_u16(local_objects + 156u) == (sint32)(0u - (uint32)(1))) && (v43 == 0x80000000)))
        ob_draft_unresolved_call(0x8003858cu, 2u, 6u, 0);
      v74 = (v43 / (sint32)r_u16(local_objects + 156u));
      if (((sint32)((sint32)r_u32(local_objects + 112u)) <= (sint32)(0)))
        v44 = ((sint32)(0u - (uint32)r_u16(local_objects + 156u)) >> 1);
      else
        v44 = (r_u16(local_objects + 156u) >> 1);
      v45 = (sint32)((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 112u)) << (uint32)(8))) + (uint32)(v44));
      if (((r_u16(local_objects + 156u) == (sint32)(0u - (uint32)(1))) && (v45 == 0x80000000)))
        ob_draft_unresolved_call(0x8003858cu, 2u, 6u, 0);
      v46 = (v45 / (sint32)r_u16(local_objects + 156u));
      v47 = v73;
      v75 = v46;
      if (((sint32)(v73) < (sint32)(0)))
        v47 = (sint32)(0u - (uint32)(v73));
      v48 = v74;
      v49 = ((sint32)(v47) < (sint32)(v74));
      if (((sint32)(v74) < (sint32)(0)))
      {
        v48 = (sint32)(0u - (uint32)(v74));
        v49 = ((sint32)(v47) < (sint32)((sint32)(0u - (uint32)(v74))));
      }
      if (v49)
        v47 = v48;
      v50 = v46;
      v51 = ((sint32)(v47) < (sint32)(v46));
      if (((sint32)(v46) < (sint32)(0)))
      {
        v50 = (sint32)(0u - (uint32)(v46));
        v51 = ((sint32)(v47) < (sint32)((sint32)(0u - (uint32)(v46))));
      }
      v52 = !v51;
      v53 = ((sint32)(v47) < (sint32)(18901));
      if (v52)
        goto LABEL_104;
      v47 = v50;
      while (1)
      {
        v53 = ((sint32)(v47) < (sint32)(18901));
        LABEL_104:
        v47 >>= 1;

        if (v53)
          break;
        ++v3;
        v73 >>= 1;
        v75 >>= 1;
        v74 >>= 1;
      }

      v54 = 0;
      w_u16(((local_objects + 64u) + (0) * 2u), (sint32)(0u - (uint32)((sint16)(v73))));
      w_u16(((local_objects + 64u) + (2) * 2u), (sint32)(0u - (uint32)((sint16)(v75))));
      w_u16(((local_objects + 64u) + (1) * 2u), (sint32)(0u - (uint32)((sint16)(v74))));
      ob_draft_unresolved_call(0x8002fd68u, 3u, (local_objects + 80u), (local_objects + 64u), (local_objects + 72u));
      sub_80039838(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24)))), r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(2)))), (local_objects + 72u), v3);
      v55 = (sint32)r_u32(0x800774fcu);
      v56 = (sint32)r_u32(0x800774f8u);
      if (((sint32)((sint32)r_u32(0x800774f8u)) < (sint32)(0)))
        v56 = (sint32)(0u - (uint32)((sint32)r_u32(0x800774f8u)));
      w_u32(local_objects + 264u, (sint32)r_u32(0x800774fcu));
      if (((sint32)((sint32)r_u32(0x800774fcu)) < (sint32)(0)))
        v55 = (sint32)(0u - (uint32)((sint32)r_u32(0x800774fcu)));
      w_u32(local_objects + 260u, (sint32)r_u32(0x800774f8u));
      w_u32(local_objects + 268u, (sint32)r_u32(0x80077500u));
      if ((v56 < v55))
        v56 = v55;
      v57 = (sint32)r_u32(0x80077500u);
      if (((sint32)((sint32)r_u32(0x80077500u)) < (sint32)(0)))
        v57 = (sint32)(0u - (uint32)((sint32)r_u32(0x80077500u)));
      v58 = (v56 < 0x7FF9);
      if ((v56 >= v57))
        goto LABEL_117;
      v56 = v57;
      while (1)
      {
        v58 = (v56 < 0x7FF9);
        LABEL_117:
        ++v54;

        if (v58)
          break;
        v56 >>= 1;
        w_u32(local_objects + 260u, ((sint32)r_u32(local_objects + 260u) >> 1));
        w_u32(local_objects + 268u, ((sint32)r_u32(local_objects + 268u) >> 1));
        w_u32(local_objects + 264u, ((sint32)r_u32(local_objects + 264u) >> 1));
      }

      v59 = (sint32)((uint32)(v54) - (uint32)(1));
      v60 = (sint16)r_u16((uint32)((sint32)r_u32(0x800775ecu)));
      w_u16(((local_objects + 240u) + (1) * 2u), ((sint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800775ecu)) + (uint32)(6))))) >> (sint32)((uint32)(v59) + (uint32)(2))));
      w_u16(((local_objects + 240u) + (2) * 2u), ((sint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800775ecu)) + (uint32)(12))))) >> (sint32)((uint32)(v59) + (uint32)(2))));
      w_u16(((local_objects + 240u) + (3) * 2u), ((sint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800775ecu)) + (uint32)(2))))) >> (sint32)((uint32)(v59) + (uint32)(2))));
      w_u16(((local_objects + 240u) + (4) * 2u), ((sint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800775ecu)) + (uint32)(8))))) >> (sint32)((uint32)(v59) + (uint32)(2))));
      w_u16(((local_objects + 240u) + (5) * 2u), ((sint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800775ecu)) + (uint32)(14))))) >> (sint32)((uint32)(v59) + (uint32)(2))));
      w_u16(((local_objects + 240u) + (6) * 2u), ((sint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800775ecu)) + (uint32)(4))))) >> (sint32)((uint32)(v59) + (uint32)(2))));
      w_u16(((local_objects + 240u) + (7) * 2u), ((sint32)((sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800775ecu)) + (uint32)(10))))) >> (sint32)((uint32)(v59) + (uint32)(2))));
      v61 = (sint16)r_u16((uint32)((sint32)((uint32)((sint32)r_u32(0x800775ecu)) + (uint32)(16))));
      w_u16(((local_objects + 240u) + (0) * 2u), ((sint32)(v60) >> (sint32)((uint32)(v59) + (uint32)(2))));
      w_u16(((local_objects + 240u) + (8) * 2u), ((sint32)(v61) >> (sint32)((uint32)(v59) + (uint32)(2))));
      ob_draft_unresolved_call(0x8005f398u, 1u, (local_objects + 240u));
      ob_draft_unresolved_call(0x8005f428u, 1u, (local_objects + 240u));
      w_u32(0x80077558u, (sint32)((local_objects + 240u)));
      if ((sint16)r_u16(0x80077364u))
      {
        v62 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))));
        w_u8((uint32)((sint32)((uint32)(a1) + (uint32)(1))), ((uint32)(r_u8((uint32)((sint32)((uint32)(a1) + (uint32)(1))))) | (uint32)(0x40u)));
        ob_draft_unresolved_call(0x8003803cu, 2u, v62, r_u32(0x800775ecu));
      }
      else
        if ((sint16)r_u16(0x80077638u))
      {
        v63 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24))));
        w_u8((uint32)((sint32)((uint32)(a1) + (uint32)(1))), ((uint32)(r_u8((uint32)((sint32)((uint32)(a1) + (uint32)(1))))) | (uint32)(0x40u)));
        ob_draft_unresolved_call(0x80037f0cu, 2u, v63, r_u32(0x800775ecu));
      }
      else
      {
        sub_8003584C(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24)))));
      }
      w_u16(0x8007748cu, r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(2)))));
      w_u16(0x80077480u, (((uint16)(((sint16)r_u16(0x8007748cu) & 0x600)) >> 2) | ((sint16)r_u16(0x8007748cu) & 0x6000)));
      w_u16(0x800775a0u, ~(((uint16)(((sint16)r_u16(0x8007748cu) & 0x1800)) >> 4)));
      if ((sint16)r_u16(0x80077638u))
      {
        if (v59)
        {
          v64 = (uint32)((sint32)r_u32(0x80077560u));
          for (i = ((uint32)((uint16)((sint16)r_u16(0x80077638u))) - (uint32)(1)); ((sint32)(i) >= (sint32)(0)); v64 += (3) * 4u)
          {
            --i;
            w_u32(v64, ((sint32)r_u32(v64) >> ((uint32)v59 & 31u)));
          }

        }
      }
      if (((r_u16((uint32)((sint32)((uint32)(a1) + (uint32)(2)))) & 1) != 0))
      {
        if (((r_u8((uint32)((sint32)((uint32)(a1) + (uint32)(1)))) & 0x40) != 0))
          ob_draft_unresolved_call(0x800397a4u, 2u, r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24)))), a1);
        else
          ob_draft_unresolved_call(0x8003979cu, 2u, r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24)))), a1);
      }
      else
        if (((r_u8((uint32)((sint32)((uint32)(a1) + (uint32)(1)))) & 0x40) != 0))
      {
        ob_draft_unresolved_call(0x800397acu, 2u, r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24)))), a1);
      }
      else
      {
        sub_80039808(r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(24)))), a1);
      }
      v66 = r_u32((uint32)((sint32)((uint32)(a1) + (uint32)(28))));
      v67 = v71;
      v68 = v72;
      w_u32((v66 + (6) * 4u), v70);
      w_u32((v66 + (7) * 4u), v67);
      w_u32((v66 + (8) * 4u), v68);
      ob_draft_unresolved_call(0x800355f4u, 0u);
    }
  }
    ob_draft_scratch_release(local_objects); 
}


uint32 sub_80052A68(void)
{
    FUNCTION_MARKER(0x80052a68u, "SLES_008.65");
    /* TODO: Confirm divide zero and overflow exception paths in the draft arithmetic */
    /* TODO: Bind external adapter for sub_8004EC6C */
    uint32 local_objects = ob_draft_scratch_acquire(1280u);
  sint32 result;
  sint32 v1;
  sint32 v2;
  uint16 v3;
  sint32 v4;
  sint32 v5;
  sint32 v6;
  int64_t v7;
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
  sint16 v20;
  sint32 v21;
  uint32 v22;
  sint32 v23;
  uint32 v24;
  sint32 v25;
  uint32 v26;
  sint32 v27;
  sint32 v28;
  sint32 v29;
  sint16 v30;
  sint16 v31;
  sint32 v32;
  sint16 v33;
  uint32 v34;
  sint32 v35;
  sint32 v36;
  uint32 v37;
  sint32 v38;
  sint32 v39;
  uint32 v40;
  sint32 v41;
  sint32 v42;
  sint32 v43;
  sint16 v44;
  sint32 v45;
  sint32 v46;
  sint16 v47;
  uint32 v48;
  sint32 v49;
  sint32 v50;
  sint32 v51;
  uint32 v52;
  sint32 v53;
  sint32 v54;
  sint32 v55;
  sint32 v56;
  sint16 v57;
  uint32 v58;
  sint32 v59;
  sint32 v60;
  uint32 v61;
  sint32 v62;
  sint32 v63;
  uint32 v64;
  sint32 v65;
  sint32 v66;
  uint32 v67;
  sint32 v68;
  sint32 v69;
  sint32 v70;
  sint16 v71;
  uint32 v72;
  sint32 v73;
  uint32 v74;
  sint32 v75;
  sint32 v76;
  sint16 v77;
  sint32 v78;
  uint32 v79;
  uint32 v80;
  sint32 v81;
  sint32 v82;
  sint32 v83;
  sint32 v84;
  sint16 v85;
  sint16 v86;
  sint32 v87;
  sint16 v88;
  uint32 v89;
  sint32 v90;
  sint32 v91;
  uint32 v92;
  sint32 v93;
  sint32 v94;
  uint32 v95;
  sint32 v96;
  sint32 v97;
  sint32 v98;
  sint16 v99;
  sint32 v100;
  sint32 v101;
  sint16 v102;
  uint32 v103;
  sint32 v104;
  sint32 v105;
  sint32 v106;
  uint32 v107;
  sint32 v108;
  sint32 v109;
  sint32 v110;
  sint32 v111;
  sint16 v112;
  uint32 v113;
  sint32 v114;
  sint32 v115;
  uint32 v116;
  sint32 v117;
  sint32 v118;
  uint32 v119;
  sint32 v120;
  uint32 v121;
  sint32 v122;
  sint32 v123;
  sint32 v124;
  sint16 v125;
  uint32 v126;
  sint32 v127;
  uint32 v128;
  sint32 v129;
  sint32 v130;

  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  uint16 v168;
  uint16 v169;
  uint16 v170;
  uint16 v171;
  sint16 v172;
  sint16 v173;
  uint32 v174;
  uint32 v175;
  uint32 v176;
  uint32 v177;
  uint32 v178;
  uint32 v179;
  uint32 v180;
  uint32 v181;
  uint32 v182;
  uint32 v183;
  uint32 v184;
  uint32 v185;
  uint32 v186;
  uint32 v187;
  result = (sint32)r_u32(0x800774f4u);
  if (!(sint32)r_u32(0x800774f4u))
    { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
  result = (sint32)r_u32(0x8006c208u);
  if (!(sint32)r_u32(0x8006c208u))
    { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
  sub_8004E814();
  v1 = r_u32((uint32)((sint32)r_u32(0x800774f4u)));
  if (((sint32)((sint32)r_u32((uint32)((sint32)r_u32(0x800774f4u)))) >= (sint32)(0)))
    w_u32(local_objects + 0u, (sint32)((uint32)(v1) - (uint32)(((sint32)(((sint32)(v1) % (sint32)(22500))) / (sint32)(3)))));
  else
    w_u32(local_objects + 0u, (sint32)((uint32)(v1) + (uint32)(((sint32)(((sint32)((sint32)(0u - (uint32)(v1))) % (sint32)(22500))) / (sint32)(3)))));
  v2 = r_u32((uint32)((sint32)((uint32)((sint32)r_u32(0x800774f4u)) + (uint32)(8))));
  if (((sint32)(v2) >= (sint32)(0)))
    w_u32(local_objects + 8u, (sint32)((uint32)(v2) - (uint32)(((sint32)(((sint32)(v2) % (sint32)(22500))) / (sint32)(3)))));
  else
    w_u32(local_objects + 8u, (sint32)((uint32)(v2) + (uint32)(((sint32)(((sint32)((sint32)(0u - (uint32)(v2))) % (sint32)(22500))) / (sint32)(3)))));
  v3 = ((((sint32)((sint8)((sint32)r_u32(local_objects + 0u))) / (sint32)((sint32)(0u - (uint32)(28)))) & 1) | (sint32)((uint32)(2) * (uint32)((((sint32)((sint8)((sint32)r_u32(local_objects + 8u))) / (sint32)((sint32)(0u - (uint32)(28)))) & 1))));
  w_u32(local_objects + 4u, 0);
  v168 = v3;
  if (!(sint32)r_u32(0x800C8300))
  {
    v4 = r_u16((uint32)((sint32)r_u32(0x80077428u)));
    v5 = (sint32)((uint32)((sint32)((uint32)((sint32)r_u32(local_objects + 0u)) - (uint32)(6144))) - (uint32)(((sint32)((sint16)r_u16((0x8006c304u + (((sint32)((sint32)((uint32)(v4) + (uint32)(8))) >> 4)) * 2u))) / (sint32)(3))));
    w_u32(local_objects + 0u, v5);
    v6 = ((uint32)((uint16)((sint16)r_u16((0x8006cb04u + ((((uint32)(r_u16((uint32)((sint32)r_u32(0x80077428u)))) + (uint32)(8)) >> 4)) * 2u)))) << (uint32)(16));
    v7 = ((uint64_t)(1431655766LL) * (uint64_t)((sint16)r_u16((0x8006cb04u + ((((uint32)(r_u16((uint32)((sint32)r_u32(0x80077428u)))) + (uint32)(8)) >> 4)) * 2u))));
    v168 = (v3 ^ 2);
    v8 = (sint32)((uint32)((sint32)r_u32(local_objects + 8u)) - (uint32)((sint16)(((uint32)((uint16)((v7) >> 32)) - (uint32)(((sint32)(v6) >> 31))))));
    w_u32(local_objects + 8u, (sint32)((uint32)(v8) - (uint32)(7500)));
    if (((uint32)((sint32)((uint32)(v4) - (uint32)(0x2000))) >= 0x4000))
    {
      v9 = (sint32)((uint32)(v8) - (uint32)(22500));
      if (((uint32)((sint32)((uint32)(v4) - (uint32)(24576))) >= 0x4000))
      {
        if (((uint16)((sint32)((uint32)(v4) + (uint32)(24576))) < 0x4000u))
        {
          w_u32(local_objects + 0u, (sint32)((uint32)(v5) - (uint32)(15000)));
          goto LABEL_17;
        }
        v9 = (sint32)((uint32)(v8) + (uint32)(7500));
      }
      w_u32(local_objects + 8u, v9);
      goto LABEL_17;
    }
    w_u32(local_objects + 0u, (sint32)((uint32)(v5) + (uint32)(15000)));
  }
  LABEL_17:
  w_u32(local_objects + 8u, ((uint32)((sint32)r_u32(local_objects + 8u)) + (uint32)(((sint32)((sint32)r_u32(0x800771ccu)) % (sint32)(7500)))));

  if (((sint32)((sint32)r_u32(0x800771ccu)) >= (sint32)(7500)))
    v168 ^= 2u;
  sub_8004EEF4((local_objects + 0u), (sint32)((local_objects + 128u)));
  w_u32(local_objects + 20u, (sint32)r_u32(local_objects + 4u));
  w_u32(local_objects + 24u, (sint32)r_u32(local_objects + 8u));
  v10 = v168;
  w_u32(local_objects + 16u, (sint32)((uint32)((sint32)r_u32(local_objects + 0u)) + (uint32)(7500)));
  sub_8004EEF4((local_objects + 16u), (sint32)((local_objects + 384u)));
  w_u32(local_objects + 32u, (sint32)r_u32(local_objects + 0u));
  w_u32(local_objects + 36u, (sint32)r_u32(local_objects + 4u));
  w_u32(local_objects + 40u, (sint32)((uint32)((sint32)r_u32(local_objects + 8u)) + (uint32)(7500)));
  sub_8004EEF4((local_objects + 32u), (sint32)((local_objects + 640u)));
  w_u32(local_objects + 52u, (sint32)r_u32(local_objects + 36u));
  w_u32(local_objects + 56u, (sint32)r_u32(local_objects + 40u));
  w_u32(local_objects + 48u, (sint32)((uint32)((sint32)r_u32(local_objects + 32u)) + (uint32)(7500)));
  sub_8004EEF4((local_objects + 48u), (sint32)((local_objects + 896u)));
  ob_draft_unresolved_call(0x8004ec6cu, 9u, (local_objects + 128u), (local_objects + 384u), (local_objects + 640u), (local_objects + 896u), (sint16)(v168), ob_native_missing_value(0x80052a68u, "v131"), (sint32)r_u32(local_objects + 0u), (sint32)r_u32(local_objects + 4u), (sint32)r_u32(local_objects + 8u));
  w_u32(local_objects + 64u, (sint32)r_u32(local_objects + 0u));
  w_u32(local_objects + 68u, (sint32)r_u32(local_objects + 4u));
  w_u32(local_objects + 72u, (sint32)r_u32(local_objects + 8u));
  w_u32(local_objects + 96u, (sint32)r_u32(local_objects + 32u));
  w_u32(local_objects + 100u, (sint32)r_u32(local_objects + 36u));
  w_u32(local_objects + 104u, (sint32)r_u32(local_objects + 40u));
  v11 = 1;
  do
  {
    v12 = v11;
    v10 ^= 1u;
    v13 = ((sint32)((sint32)((uint32)(v11) << (uint32)(16))) >> 14);
    w_u32(local_objects + 64u, ((uint32)((sint32)r_u32(local_objects + 64u)) - (uint32)(7500)));
    w_u32(local_objects + 96u, ((uint32)((sint32)r_u32(local_objects + 96u)) - (uint32)(7500)));
    sub_8004EEF4((local_objects + 64u), (sint32)((uint32)((sint32)((local_objects + 128u))) + (uint32)(v13)));
    sub_8004EEF4((local_objects + 96u), (sint32)((uint32)((sint32)((local_objects + 640u))) + (uint32)(v13)));
    v14 = ob_draft_unresolved_call(0x8004ec6cu, 9u, (uint32)(((uint32)((local_objects + 128u)) + (v13) * 1u)), (uint32)(((uint32)((((local_objects + 128u) + 0xFFFFFFFCu))) + (v13) * 1u)), (uint32)(((uint32)((local_objects + 640u)) + (v13) * 1u)), (uint32)(((uint32)((((local_objects + 640u) + 0xFFFFFFFCu))) + (v13) * 1u)), (sint16)(v10), ob_native_missing_value(0x80052a68u, "v132"), (sint32)r_u32(local_objects + 0u), (sint32)r_u32(local_objects + 4u), (sint32)r_u32(local_objects + 8u));
    v11 = (sint32)((uint32)(v12) + (uint32)(1));
  }
  while (!((sint32)((uint32)(v14) << (uint32)(16))));
  w_u16(((local_objects + 896u) + (128) * 2u), v12);
  w_u32(((local_objects + 1160u) + (0) * 4u), (sint32)r_u32(local_objects + 64u));
  w_u32(((local_objects + 1160u) + (1) * 4u), (sint32)r_u32(local_objects + 68u));
  w_u32(((local_objects + 1160u) + (2) * 4u), (sint32)r_u32(local_objects + 72u));
  w_u16(local_objects + 1216u, v12);
  w_u32(((local_objects + 1224u) + (0) * 4u), (sint32)r_u32(local_objects + 96u));
  w_u32(((local_objects + 1224u) + (1) * 4u), (sint32)r_u32(local_objects + 100u));
  w_u32(((local_objects + 1224u) + (2) * 4u), (sint32)r_u32(local_objects + 104u));
  w_u32(local_objects + 80u, (sint32)r_u32(local_objects + 16u));
  w_u32(local_objects + 84u, (sint32)r_u32(local_objects + 20u));
  w_u32(local_objects + 88u, (sint32)r_u32(local_objects + 24u));
  w_u32(local_objects + 112u, (sint32)r_u32(local_objects + 48u));
  w_u32(local_objects + 116u, (sint32)r_u32(local_objects + 52u));
  w_u32(local_objects + 120u, (sint32)r_u32(local_objects + 56u));
  v15 = v168;
  v16 = 1;
  do
  {
    v17 = v16;
    v15 ^= 1u;
    v18 = ((sint32)((sint32)((uint32)(v16) << (uint32)(16))) >> 14);
    w_u32(local_objects + 80u, ((uint32)((sint32)r_u32(local_objects + 80u)) + (uint32)(7500)));
    w_u32(local_objects + 112u, ((uint32)((sint32)r_u32(local_objects + 112u)) + (uint32)(7500)));
    sub_8004EEF4((local_objects + 80u), (sint32)((uint32)((sint32)((local_objects + 384u))) + (uint32)(v18)));
    sub_8004EEF4((local_objects + 112u), (sint32)((uint32)((sint32)((local_objects + 896u))) + (uint32)(v18)));
    v19 = ob_draft_unresolved_call(0x8004ec6cu, 9u, (uint32)(((uint32)((((local_objects + 384u) + 0xFFFFFFFCu))) + (v18) * 1u)), (uint32)(((uint32)((local_objects + 384u)) + (v18) * 1u)), (uint32)(((uint32)((((local_objects + 896u) + 0xFFFFFFFCu))) + (v18) * 1u)), (uint32)(((uint32)((local_objects + 896u)) + (v18) * 1u)), (sint16)(v15), ob_native_missing_value(0x80052a68u, "v132"), (sint32)r_u32(local_objects + 0u), (sint32)r_u32(local_objects + 4u), (sint32)r_u32(local_objects + 8u));
    v16 = (sint32)((uint32)(v17) + (uint32)(1));
  }
  while (!((sint32)((uint32)(v19) << (uint32)(16))));
  w_u16(local_objects + 1184u, v17);
  w_u32(((local_objects + 1192u) + (0) * 4u), (sint32)r_u32(local_objects + 80u));
  w_u32(((local_objects + 1192u) + (1) * 4u), (sint32)r_u32(local_objects + 84u));
  w_u32(((local_objects + 1192u) + (2) * 4u), (sint32)r_u32(local_objects + 88u));
  w_u16(local_objects + 1248u, v17);
  w_u32(((local_objects + 1256u) + (0) * 4u), (sint32)r_u32(local_objects + 112u));
  w_u32(((local_objects + 1256u) + (1) * 4u), (sint32)r_u32(local_objects + 116u));
  w_u32(((local_objects + 1256u) + (2) * 4u), (sint32)r_u32(local_objects + 120u));
  v171 = 1;
  v170 = 0;
  v169 = v168;
  v174 = (local_objects + 128u);
  v175 = (local_objects + 384u);
  v186 = (local_objects + 0u);
  do
  {
    v21 = ((uint32)(v171) << (uint32)(7));
    v169 ^= 2u;
    v20 = v169;
    w_u32(local_objects + 8u, ((uint32)((sint32)r_u32(local_objects + 8u)) - (uint32)(7500)));
    w_u32(local_objects + 24u, ((uint32)((sint32)r_u32(local_objects + 24u)) - (uint32)(7500)));
    v22 = (uint32)(((uint32)(v174) + (v21) * 1u));
    sub_8004EEF4((local_objects + 0u), (sint32)((uint32)((sint32)(v174)) + (uint32)(v21)));
    v23 = (sint32)((uint32)((sint32)(v175)) + (uint32)(v21));
    sub_8004EEF4((local_objects + 16u), v23);
    v24 = (uint32)(v23);
    v25 = v170;
    if (((uint32)(ob_draft_unresolved_call(0x8004ec6cu, 9u, v22, v24, ((v174 + ((sint32)((uint32)(64) * (uint32)(v170))) * 2u)), ((v175 + ((sint32)((uint32)(64) * (uint32)(v170))) * 2u)), v20, ob_native_missing_value(0x80052a68u, "v132"), (sint32)r_u32(local_objects + 0u), (sint32)r_u32(local_objects + 4u), (sint32)r_u32(local_objects + 8u))) << (uint32)(16)))
    {
      v172 = 0;
      v173 = 0;
      w_u32(local_objects + 64u, (sint32)r_u32(local_objects + 0u));
      w_u32(local_objects + 68u, (sint32)r_u32(local_objects + 4u));
      w_u32(local_objects + 72u, (sint32)r_u32(local_objects + 8u));
      v50 = v25;
      v51 = v169;
      v52 = ((uint32)(v186) + ((sint32)((uint32)(2) * (uint32)(v25))) * 1u);
      v178 = (sint32)((uint32)(12) * (uint32)(v25));
      v53 = 1;
      do
      {
        v54 = v53;
        v55 = (sint16)(v53);
        v56 = (sint32)((uint32)(2) * (uint32)((sint16)(v53)));
        w_u32(local_objects + 64u, ((uint32)((sint32)r_u32(local_objects + 64u)) - (uint32)(7500)));
        sub_8004EEF4((local_objects + 64u), (sint32)(((v22 + (v56) * 2u))));
        v57 = (v51 ^ 1);
        v51 ^= 1u;
        if (((sint32)((sint16)r_u16(((uint32)(v52) + (576) * 2u))) < (sint32)(v55)))
        {
          v58 = (((local_objects + 1160u) + ((v178 / 4)) * 4u));
          v59 = (sint32)(((v174 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v50))) + (uint32)(v56))) * 2u)));
          w_u32(v58, (sint32)((uint32)((sint32)r_u32(((local_objects + 1160u) + ((v178 / 4)) * 4u))) - (uint32)(7500)));
          sub_8004EEF4(v58, v59);
        }
        if (!(((uint32)(ob_draft_unresolved_call(0x8004ec6cu, 9u, ((v22 + (v56) * 2u)), ((v22 + ((sint32)((uint32)(v56) - (uint32)(2))) * 2u)), ((v174 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v50))) + (uint32)(v56))) * 2u)), ((v174 + ((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v50))) - (uint32)(2))) + (uint32)(v56))) * 2u)), v57, ob_native_missing_value(0x80052a68u, "v132"), (sint32)r_u32(local_objects + 0u), (sint32)r_u32(local_objects + 4u), (sint32)r_u32(local_objects + 8u))) << (uint32)(16))))
          ++v172;
        v53 = (sint32)((uint32)(v54) + (uint32)(1));
      }
      while (((sint32)((sint16)r_u16(((uint32)(v52) + (576) * 2u))) >= (sint32)(v55)));
      v60 = v171;
      v61 = ((v186 + ((sint32)((uint32)(3) * (uint32)(v171))) * 4u));
      w_u16((((uint32)(v186) + (v171) * 2u) + (576) * 2u), v54);
      v62 = (sint32)r_u32(local_objects + 68u);
      v63 = (sint32)r_u32(local_objects + 72u);
      w_u32((v61 + (290) * 4u), (sint32)r_u32(local_objects + 64u));
      w_u32((v61 + (291) * 4u), v62);
      w_u32((v61 + (292) * 4u), v63);
      w_u32(local_objects + 80u, (sint32)r_u32(local_objects + 16u));
      w_u32(local_objects + 84u, (sint32)r_u32(local_objects + 20u));
      w_u32(local_objects + 88u, (sint32)r_u32(local_objects + 24u));
      v64 = ((v175 + ((sint32)((uint32)(64) * (uint32)(v60))) * 2u));
      v65 = v169;
      v66 = v170;
      v67 = ((uint32)(v186) + ((sint32)((uint32)(2) * (uint32)(v170))) * 1u);
      v179 = (sint32)((uint32)(12) * (uint32)(v170));
      v68 = 1;
      do
      {
        v45 = v68;
        v69 = (sint16)(v68);
        v70 = (sint32)((uint32)(2) * (uint32)((sint16)(v68)));
        w_u32(local_objects + 80u, ((uint32)((sint32)r_u32(local_objects + 80u)) + (uint32)(7500)));
        sub_8004EEF4((local_objects + 80u), (sint32)(((v64 + (v70) * 2u))));
        v71 = (v65 ^ 1);
        v65 ^= 1u;
        if (((sint32)((sint16)r_u16(((uint32)(v67) + (592) * 2u))) < (sint32)(v69)))
        {
          v72 = (((local_objects + 1192u) + ((v179 / 4)) * 4u));
          v73 = (sint32)(((v175 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v66))) + (uint32)(v70))) * 2u)));
          w_u32(v72, (sint32)((uint32)((sint32)r_u32(((local_objects + 1192u) + ((v179 / 4)) * 4u))) + (uint32)(7500)));
          sub_8004EEF4(v72, v73);
        }
        if (!(((uint32)(ob_draft_unresolved_call(0x8004ec6cu, 9u, ((v64 + ((sint32)((uint32)(v70) - (uint32)(2))) * 2u)), ((v64 + (v70) * 2u)), ((v175 + ((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v66))) - (uint32)(2))) + (uint32)(v70))) * 2u)), ((v175 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v66))) + (uint32)(v70))) * 2u)), v71, ob_native_missing_value(0x80052a68u, "v132"), (sint32)r_u32(local_objects + 0u), (sint32)r_u32(local_objects + 4u), (sint32)r_u32(local_objects + 8u))) << (uint32)(16))))
          ++v173;
        v68 = (sint32)((uint32)(v45) + (uint32)(1));
      }
      while (((sint32)((sint16)r_u16(((uint32)(v67) + (592) * 2u))) >= (sint32)(v69)));
    }
    else
    {
      v172 = 1;
      v173 = 1;
      w_u32(local_objects + 64u, (sint32)r_u32(local_objects + 0u));
      w_u32(local_objects + 68u, (sint32)r_u32(local_objects + 4u));
      w_u32(local_objects + 72u, (sint32)r_u32(local_objects + 8u));
      v26 = v22;
      v27 = v25;
      v28 = (sint32)((uint32)(2) * (uint32)(v25));
      v29 = v169;
      v176 = (sint32)((uint32)(12) * (uint32)(v25));
      v30 = 1;
      do
      {
        v31 = v30;
        v32 = (sint32)((uint32)(2) * (uint32)(v30));
        w_u32(local_objects + 64u, ((uint32)((sint32)r_u32(local_objects + 64u)) - (uint32)(7500)));
        sub_8004EEF4((local_objects + 64u), (sint32)(((v26 + (v32) * 2u))));
        v33 = (v29 ^ 1);
        v29 ^= 1u;
        if (((sint32)((sint16)r_u16((uint32)((((uint32)(v186) + (v28) * 1u) + (1152) * 1u)))) < (sint32)(v30)))
        {
          v34 = (((local_objects + 1160u) + ((v176 / 4)) * 4u));
          v35 = (sint32)(((v174 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v27))) + (uint32)(v32))) * 2u)));
          w_u32(v34, (sint32)((uint32)((sint32)r_u32(((local_objects + 1160u) + ((v176 / 4)) * 4u))) - (uint32)(7500)));
          sub_8004EEF4(v34, v35);
        }
        ++v30;
      }
      while (!(((uint32)(ob_draft_unresolved_call(0x8004ec6cu, 9u, ((v26 + (v32) * 2u)), ((v26 + ((sint32)((uint32)(v32) - (uint32)(2))) * 2u)), ((v174 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v27))) + (uint32)(v32))) * 2u)), ((v174 + ((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v27))) - (uint32)(2))) + (uint32)(v32))) * 2u)), v33, ob_native_missing_value(0x80052a68u, "v132"), (sint32)r_u32(local_objects + 0u), (sint32)r_u32(local_objects + 4u), (sint32)r_u32(local_objects + 8u))) << (uint32)(16))));
      v36 = v171;
      v37 = ((v186 + ((sint32)((uint32)(3) * (uint32)(v171))) * 4u));
      w_u16((((uint32)(v186) + (v171) * 2u) + (576) * 2u), v31);
      v38 = (sint32)r_u32(local_objects + 68u);
      v39 = (sint32)r_u32(local_objects + 72u);
      w_u32((v37 + (290) * 4u), (sint32)r_u32(local_objects + 64u));
      w_u32((v37 + (291) * 4u), v38);
      w_u32((v37 + (292) * 4u), v39);
      w_u32(local_objects + 80u, (sint32)r_u32(local_objects + 16u));
      w_u32(local_objects + 84u, (sint32)r_u32(local_objects + 20u));
      w_u32(local_objects + 88u, (sint32)r_u32(local_objects + 24u));
      v40 = ((v175 + ((sint32)((uint32)(64) * (uint32)(v36))) * 2u));
      v41 = v169;
      v42 = v170;
      v43 = (sint32)((uint32)(2) * (uint32)(v170));
      v177 = (sint32)((uint32)(12) * (uint32)(v170));
      v44 = 1;
      do
      {
        v45 = ((uint32)(v45) & ~((uint32)65535u << 0) | (((uint32)(v44) & 65535u) << 0));
        v46 = (sint32)((uint32)(2) * (uint32)(v44));
        w_u32(local_objects + 80u, ((uint32)((sint32)r_u32(local_objects + 80u)) + (uint32)(7500)));
        sub_8004EEF4((local_objects + 80u), (sint32)(((v40 + (v46) * 2u))));
        v47 = (v41 ^ 1);
        v41 ^= 1u;
        if (((sint32)((sint16)r_u16((uint32)((((uint32)(v186) + (v43) * 1u) + (1184) * 1u)))) < (sint32)(v44)))
        {
          v48 = (((local_objects + 1192u) + ((v177 / 4)) * 4u));
          v49 = (sint32)(((v175 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v42))) + (uint32)(v46))) * 2u)));
          w_u32(v48, (sint32)((uint32)((sint32)r_u32(((local_objects + 1192u) + ((v177 / 4)) * 4u))) + (uint32)(7500)));
          sub_8004EEF4(v48, v49);
        }
        ++v44;
      }
      while (!(((uint32)(ob_draft_unresolved_call(0x8004ec6cu, 9u, ((v40 + ((sint32)((uint32)(v46) - (uint32)(2))) * 2u)), ((v40 + (v46) * 2u)), ((v175 + ((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v42))) - (uint32)(2))) + (uint32)(v46))) * 2u)), ((v175 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v42))) + (uint32)(v46))) * 2u)), v47, ob_native_missing_value(0x80052a68u, "v132"), (sint32)r_u32(local_objects + 0u), (sint32)r_u32(local_objects + 4u), (sint32)r_u32(local_objects + 8u))) << (uint32)(16))));
    }
    v74 = ((v186 + ((sint32)((uint32)(3) * (uint32)(v171))) * 4u));
    w_u16((((uint32)(v186) + (v171) * 2u) + (592) * 2u), v45);
    v75 = (sint32)r_u32(local_objects + 84u);
    v76 = (sint32)r_u32(local_objects + 88u);
    w_u32((v74 + (298) * 4u), (sint32)r_u32(local_objects + 80u));
    w_u32((v74 + (299) * 4u), v75);
    w_u32((v74 + (300) * 4u), v76);
    v171 ^= 1u;
    v170 ^= 1u;
  }
  while (((sint32)((sint32)((uint32)(v172) + (uint32)(v173))) > (sint32)(0)));
  v171 = 1;
  v170 = 0;
  v169 = v168;
  v180 = (local_objects + 640u);
  v181 = (local_objects + 896u);
  v187 = (local_objects + 0u);
  do
  {
    v78 = ((uint32)(v171) << (uint32)(7));
    v169 ^= 2u;
    v77 = v169;
    w_u32(local_objects + 40u, ((uint32)((sint32)r_u32(local_objects + 40u)) + (uint32)(7500)));
    w_u32(local_objects + 56u, ((uint32)((sint32)r_u32(local_objects + 56u)) + (uint32)(7500)));
    v79 = (uint32)(((uint32)(v180) + (v78) * 1u));
    sub_8004EEF4((local_objects + 32u), (sint32)((uint32)((sint32)(v180)) + (uint32)(v78)));
    v80 = (uint32)(((uint32)(v181) + (v78) * 1u));
    sub_8004EEF4((local_objects + 48u), (sint32)(v80));
    v81 = v170;
    if (((uint32)(ob_draft_unresolved_call(0x8004ec6cu, 9u, ((v180 + ((sint32)((uint32)(64) * (uint32)(v170))) * 2u)), ((v181 + ((sint32)((uint32)(64) * (uint32)(v170))) * 2u)), v79, v80, v77, ob_native_missing_value(0x80052a68u, "v132"), (sint32)r_u32(local_objects + 0u), (sint32)r_u32(local_objects + 4u), (sint32)r_u32(local_objects + 8u))) << (uint32)(16)))
    {
      v172 = 0;
      v173 = 0;
      w_u32(local_objects + 96u, (sint32)r_u32(local_objects + 32u));
      w_u32(local_objects + 100u, (sint32)r_u32(local_objects + 36u));
      w_u32(local_objects + 104u, (sint32)r_u32(local_objects + 40u));
      v105 = v81;
      v106 = v169;
      v107 = ((uint32)(v187) + ((sint32)((uint32)(2) * (uint32)(v81))) * 1u);
      v184 = (sint32)((uint32)(12) * (uint32)(v81));
      v108 = 1;
      do
      {
        v109 = v108;
        v110 = (sint16)(v108);
        v111 = (sint32)((uint32)(2) * (uint32)((sint16)(v108)));
        w_u32(local_objects + 96u, ((uint32)((sint32)r_u32(local_objects + 96u)) - (uint32)(7500)));
        sub_8004EEF4((local_objects + 96u), (sint32)(((v79 + (v111) * 2u))));
        v112 = (v106 ^ 1);
        v106 ^= 1u;
        if (((sint32)((sint16)r_u16(((uint32)(v107) + (608) * 2u))) < (sint32)(v110)))
        {
          v113 = (((local_objects + 1224u) + ((v184 / 4)) * 4u));
          v114 = (sint32)(((v180 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v105))) + (uint32)(v111))) * 2u)));
          w_u32(v113, (sint32)((uint32)((sint32)r_u32(((local_objects + 1224u) + ((v184 / 4)) * 4u))) - (uint32)(7500)));
          sub_8004EEF4(v113, v114);
        }
        if (!(((uint32)(ob_draft_unresolved_call(0x8004ec6cu, 9u, ((v180 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v105))) + (uint32)(v111))) * 2u)), ((v180 + ((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v105))) - (uint32)(2))) + (uint32)(v111))) * 2u)), ((v79 + (v111) * 2u)), ((v79 + ((sint32)((uint32)(v111) - (uint32)(2))) * 2u)), v112, ob_native_missing_value(0x80052a68u, "v132"), (sint32)r_u32(local_objects + 0u), (sint32)r_u32(local_objects + 4u), (sint32)r_u32(local_objects + 8u))) << (uint32)(16))))
          ++v172;
        v108 = (sint32)((uint32)(v109) + (uint32)(1));
      }
      while (((sint32)((sint16)r_u16(((uint32)(v107) + (608) * 2u))) >= (sint32)(v110)));
      v115 = v171;
      v116 = ((v187 + ((sint32)((uint32)(3) * (uint32)(v171))) * 4u));
      w_u16((((uint32)(v187) + (v171) * 2u) + (608) * 2u), v109);
      v117 = (sint32)r_u32(local_objects + 100u);
      v118 = (sint32)r_u32(local_objects + 104u);
      w_u32((v116 + (306) * 4u), (sint32)r_u32(local_objects + 96u));
      w_u32((v116 + (307) * 4u), v117);
      w_u32((v116 + (308) * 4u), v118);
      w_u32(local_objects + 112u, (sint32)r_u32(local_objects + 48u));
      w_u32(local_objects + 116u, (sint32)r_u32(local_objects + 52u));
      w_u32(local_objects + 120u, (sint32)r_u32(local_objects + 56u));
      v119 = ((v181 + ((sint32)((uint32)(64) * (uint32)(v115))) * 2u));
      v120 = v170;
      v121 = ((uint32)(v187) + ((sint32)((uint32)(2) * (uint32)(v170))) * 1u);
      v185 = (sint32)((uint32)(12) * (uint32)(v170));
      v122 = 1;
      do
      {
        v100 = v122;
        v123 = (sint16)(v122);
        v124 = (sint32)((uint32)(2) * (uint32)((sint16)(v122)));
        w_u32(local_objects + 112u, ((uint32)((sint32)r_u32(local_objects + 112u)) + (uint32)(7500)));
        sub_8004EEF4((local_objects + 112u), (sint32)(((v119 + (v124) * 2u))));
        v125 = (v106 ^ 1);
        v106 ^= 1u;
        if (((sint32)((sint16)r_u16(((uint32)(v121) + (624) * 2u))) < (sint32)(v123)))
        {
          v126 = (((local_objects + 1256u) + ((v185 / 4)) * 4u));
          v127 = (sint32)(((v181 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v120))) + (uint32)(v124))) * 2u)));
          w_u32(v126, (sint32)((uint32)((sint32)r_u32(((local_objects + 1256u) + ((v185 / 4)) * 4u))) + (uint32)(7500)));
          sub_8004EEF4(v126, v127);
        }
        if (!(((uint32)(ob_draft_unresolved_call(0x8004ec6cu, 9u, ((v181 + ((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v120))) - (uint32)(2))) + (uint32)(v124))) * 2u)), ((v181 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v120))) + (uint32)(v124))) * 2u)), ((v119 + ((sint32)((uint32)(v124) - (uint32)(2))) * 2u)), ((v119 + (v124) * 2u)), v125, ob_native_missing_value(0x80052a68u, "v132"), (sint32)r_u32(local_objects + 0u), (sint32)r_u32(local_objects + 4u), (sint32)r_u32(local_objects + 8u))) << (uint32)(16))))
          ++v173;
        v122 = (sint32)((uint32)(v100) + (uint32)(1));
      }
      while (((sint32)((sint16)r_u16(((uint32)(v121) + (624) * 2u))) >= (sint32)(v123)));
    }
    else
    {
      v172 = 1;
      v173 = 1;
      w_u32(local_objects + 96u, (sint32)r_u32(local_objects + 32u));
      w_u32(local_objects + 100u, (sint32)r_u32(local_objects + 36u));
      w_u32(local_objects + 104u, (sint32)r_u32(local_objects + 40u));
      v82 = v81;
      v83 = (sint32)((uint32)(2) * (uint32)(v81));
      v84 = v169;
      v182 = (sint32)((uint32)(12) * (uint32)(v81));
      v85 = 1;
      do
      {
        v86 = v85;
        v87 = (sint32)((uint32)(2) * (uint32)(v85));
        w_u32(local_objects + 96u, ((uint32)((sint32)r_u32(local_objects + 96u)) - (uint32)(7500)));
        sub_8004EEF4((local_objects + 96u), (sint32)(((v79 + (v87) * 2u))));
        v88 = (v84 ^ 1);
        v84 ^= 1u;
        if (((sint32)((sint16)r_u16((uint32)((((uint32)(v187) + (v83) * 1u) + (1216) * 1u)))) < (sint32)(v85)))
        {
          v89 = (((local_objects + 1224u) + ((v182 / 4)) * 4u));
          v90 = (sint32)(((v180 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v82))) + (uint32)(v87))) * 2u)));
          w_u32(v89, (sint32)((uint32)((sint32)r_u32(((local_objects + 1224u) + ((v182 / 4)) * 4u))) - (uint32)(7500)));
          sub_8004EEF4(v89, v90);
        }
        ++v85;
      }
      while (!(((uint32)(ob_draft_unresolved_call(0x8004ec6cu, 9u, ((v180 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v82))) + (uint32)(v87))) * 2u)), ((v180 + ((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v82))) - (uint32)(2))) + (uint32)(v87))) * 2u)), ((v79 + (v87) * 2u)), ((v79 + ((sint32)((uint32)(v87) - (uint32)(2))) * 2u)), v88, ob_native_missing_value(0x80052a68u, "v132"), (sint32)r_u32(local_objects + 0u), (sint32)r_u32(local_objects + 4u), (sint32)r_u32(local_objects + 8u))) << (uint32)(16))));
      v91 = v171;
      v92 = ((v187 + ((sint32)((uint32)(3) * (uint32)(v171))) * 4u));
      w_u16((((uint32)(v187) + (v171) * 2u) + (608) * 2u), v86);
      v93 = (sint32)r_u32(local_objects + 100u);
      v94 = (sint32)r_u32(local_objects + 104u);
      w_u32((v92 + (306) * 4u), (sint32)r_u32(local_objects + 96u));
      w_u32((v92 + (307) * 4u), v93);
      w_u32((v92 + (308) * 4u), v94);
      w_u32(local_objects + 112u, (sint32)r_u32(local_objects + 48u));
      w_u32(local_objects + 116u, (sint32)r_u32(local_objects + 52u));
      w_u32(local_objects + 120u, (sint32)r_u32(local_objects + 56u));
      v95 = ((v181 + ((sint32)((uint32)(64) * (uint32)(v91))) * 2u));
      v96 = v169;
      v97 = v170;
      v98 = (sint32)((uint32)(2) * (uint32)(v170));
      v183 = (sint32)((uint32)(12) * (uint32)(v170));
      v99 = 1;
      do
      {
        v100 = ((uint32)(v100) & ~((uint32)65535u << 0) | (((uint32)(v99) & 65535u) << 0));
        v101 = (sint32)((uint32)(2) * (uint32)(v99));
        w_u32(local_objects + 112u, ((uint32)((sint32)r_u32(local_objects + 112u)) + (uint32)(7500)));
        sub_8004EEF4((local_objects + 112u), (sint32)(((v95 + (v101) * 2u))));
        v102 = (v96 ^ 1);
        v96 ^= 1u;
        if (((sint32)((sint16)r_u16((uint32)((((uint32)(v187) + (v98) * 1u) + (1248) * 1u)))) < (sint32)(v99)))
        {
          v103 = (((local_objects + 1256u) + ((v183 / 4)) * 4u));
          v104 = (sint32)(((v181 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v97))) + (uint32)(v101))) * 2u)));
          w_u32(v103, (sint32)((uint32)((sint32)r_u32(((local_objects + 1256u) + ((v183 / 4)) * 4u))) + (uint32)(7500)));
          sub_8004EEF4(v103, v104);
        }
        ++v99;
      }
      while (!(((uint32)(ob_draft_unresolved_call(0x8004ec6cu, 9u, ((v181 + ((sint32)((uint32)((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v97))) - (uint32)(2))) + (uint32)(v101))) * 2u)), ((v181 + ((sint32)((uint32)((sint32)((uint32)(64) * (uint32)(v97))) + (uint32)(v101))) * 2u)), ((v95 + ((sint32)((uint32)(v101) - (uint32)(2))) * 2u)), ((v95 + (v101) * 2u)), v102, ob_native_missing_value(0x80052a68u, "v132"), (sint32)r_u32(local_objects + 0u), (sint32)r_u32(local_objects + 4u), (sint32)r_u32(local_objects + 8u))) << (uint32)(16))));
    }
    v128 = ((v187 + ((sint32)((uint32)(3) * (uint32)(v171))) * 4u));
    w_u16((((uint32)(v187) + (v171) * 2u) + (624) * 2u), v100);
    v129 = (sint32)r_u32(local_objects + 116u);
    v130 = (sint32)r_u32(local_objects + 120u);
    w_u32((v128 + (314) * 4u), (sint32)r_u32(local_objects + 112u));
    w_u32((v128 + (315) * 4u), v129);
    w_u32((v128 + (316) * 4u), v130);
    v171 ^= 1u;
    v170 ^= 1u;
    result = v173;
  }
  while (((sint32)((sint32)((uint32)(v172) + (uint32)(v173))) > (sint32)(0)));
  { uint32 draft_return = result; ob_draft_scratch_release(local_objects);  return draft_return; }
}


