#include "draft_signatures.h"

/* Unverified renderer draft with declaration-only GTE adapters */
extern void ob_draft_gte_load_vertex(uint32 slot, uint32 guest_address);
extern void ob_draft_gte_command(uint32 opcode);
extern void ob_draft_gte_store_data(uint32 reg, uint32 guest_address);

uint32 sub_8003584C(uint32 a1)
{
    FUNCTION_MARKER(0x8003584cu, "SLES_008.65");
    /* TODO: Bind declaration-only GTE adapters to ordered device loads, commands and stores */
    /* TODO: Bind external adapter for sub_800357DC */
    /* TODO: Recover undefined register temporaries without extending the function ABI */
  uint32 vertex_cursor;
  sint32 v383;
  sint32 v2, v3;
  uint32 v5;
  sint32 v7, v8, v9, v10, v11, v12, v13, v14;
  sint32 v15, v16, result, v19;
  uint32 v20;
  sint32 v21;
  uint32 v23;
  sint32 i;
  uint32 v25;
  sint32 v26;
  uint32 v27, v28;
  sint32 v29;
  sint16 v30;
  sint32 v31, v32, v33;
  sint16 v34;
  sint32 v35;
  uint32 v36;
  sint32 v37;
  sint16 v38;
  sint32 v39, v40, v41;
  sint16 v42;
  sint32 v43;
  uint32 v44;
  sint32 v45;
  sint16 v46;
  sint32 v47, v48, v49;
  sint16 v50;
  uint32 v51;
  sint32 v52;
  sint16 v53;
  sint32 v54, v55, v56;
  uint32 v57, v58;
  sint32 v59, v60, v62, v63;
  sint16 v64, v65, v66;
  uint32 v67;
  sint32 v69;
  uint32 v70, v71;
  sint32 v72, v73;
  sint16 v74;
  uint32 v75;
  sint32 v76;
  uint32 v77;
  sint32 v78, v79, v80;
  sint16 v81;
  sint32 v82;
  uint32 v83;
  sint32 v84;
  sint16 v85;
  sint32 v86, v87, v88;
  sint16 v89;
  uint32 v90;
  sint32 v91;
  sint16 v92;
  sint32 v93, v94, v95;
  uint32 v96, v97;
  sint32 v98;
  uint32 v99;
  sint32 v100, v101, v103, v104;
  sint16 v105, v106;
  uint32 v107, v109;
  sint32 v110;
  uint32 v111;
  sint32 v112;
  uint32 v113, v114;
  sint32 v115;
  sint16 v116;
  sint32 v117, v118, v119;
  sint16 v120;
  sint32 v121, v122;
  sint16 v123;
  uint32 v124;
  sint32 v125;
  uint32 v126;
  sint32 v127, v128;
  sint16 v129;
  sint32 v130, v131;
  sint16 v132;
  uint32 v133;
  sint32 v134;
  sint16 v135;
  sint32 v136, v137, v138;
  uint32 v139, v140;
  sint32 v141;
  uint32 v142;
  sint32 v143, v144, v146, v147;
  sint16 v148, v149, v150;
  uint32 v151;
  sint32 v153;
  uint32 v154;
  sint32 v155;
  uint32 v156, v157;
  sint32 v158;
  sint16 v159;
  sint32 v160, v161, v162;
  sint16 v163;
  sint32 v164;
  uint32 v165;
  sint32 v166;
  sint16 v167;
  sint32 v168, v169, v170, v171;
  sint16 v172;
  sint32 v173, v174;
  uint32 v175;
  sint32 v176, v177, v178;
  uint32 v179;
  sint32 v180;
  uint32 v181;
  sint32 v182;
  uint32 v183;
  sint32 v185, v186;
  sint16 v187;
  uint32 v188;
  sint32 v189;
  uint32 v190;
  sint32 v191, v193, v194;
  sint16 v195, v196, v197;
  uint32 v198;
  sint32 v200;
  uint32 v201;
  sint32 v202;
  uint32 v203;
  sint32 v204, v205, v206;
  sint16 v207;
  sint32 v208;
  uint32 v209;
  sint32 v210;
  sint16 v211;
  sint32 v212, v213, v214;
  sint16 v215;
  sint32 v216;
  uint32 v217;
  sint32 v218;
  sint16 v219;
  sint32 v220, v221, v222;
  uint32 v223, v224;
  sint32 v225, v226, v227, v228;
  sint16 v229;
  uint32 v230;
  sint32 v231, v232, v234, v235;
  sint16 v236, v237;
  uint32 v238;
  sint32 v240;
  uint32 v241, v242;
  sint32 v243, v244;
  sint16 v245;
  uint32 v246;
  sint32 v247;
  uint32 v248;
  sint32 v249, v250, v251;
  sint16 v252;
  uint32 v253;
  sint32 v254;
  sint16 v255;
  sint32 v256, v257, v258;
  uint32 v259, v260;
  sint32 v261;
  uint32 v262;
  sint32 v263, v264, v265, v266;
  sint16 v267;
  uint32 v268;
  sint32 v269, v270, v272, v273;
  sint16 v274, v275, v276;
  uint32 v277;
  sint32 v279;
  uint32 v280;
  sint32 v281;
  uint32 v282, v283;
  sint32 v284;
  sint16 v285;
  sint32 v286, v287, v288, v289;
  sint16 v290;
  sint32 v291, v292;
  uint32 v293;
  sint32 v294, v295, v296, v297, v298;
  uint32 v299;
  sint32 v300;
  uint32 v301;
  sint32 v302;
  uint32 v303;
  sint32 v305, v306;
  sint16 v307;
  uint32 v308;
  sint32 v309;
  uint32 v310;
  sint32 v311, v312, v313, v314;
  sint16 v315;
  uint32 v316;
  sint32 v317, v319, v320;
  sint16 v321, v322, v323;
  uint32 v324;
  sint32 v326;
  uint32 v327;
  sint32 v328;
  uint32 v329;
  sint32 v330, v331, v332;
  sint16 v333;
  sint32 v334;
  uint32 v335;
  sint32 v336;
  sint16 v337;
  sint32 v338, v339, v340;
  uint32 v341, v342;
  sint32 v343, v344, v346, v347;
  sint16 v348;
  uint32 v349;
  sint32 v350;
  uint32 v351;
  sint32 v352, v354, v355;
  sint16 v356, v357, v358;
  uint32 v359;
  sint32 v361;
  uint32 v362;
  sint32 v363;
  uint32 v364;
  sint32 v365, v366, v367;
  sint16 v368;
  sint32 v369;
  uint32 v370;
  sint32 v371;
  sint16 v372;
  sint32 v373, v374, v375, v377;
  uint32 v378;
  sint32 v379;
  uint32 v381;
  sint32 j;
  v2 = (sint32)r_u32(0x800773f8u);
  v3 = (sint32)r_u32(0x80077574u);
  vertex_cursor = r_u32((uint32)(((uint32)(a1) + (uint32)(32))));
  v5 = 0;
  if (((r_u16((uint32)(((uint32)(a1) + (uint32)(4)))) & 0x10) != 0))
  {
    if ((sint32)r_u32(0x80077350u))
    {
      if (((sint32)r_u32(0x80077350u) == 2))
      {
        v2 = 0;
        v7 = (sint32)((uint32)((sint32)((uint32)(8) * (uint32)((sint32)r_u32(0x80077630u)))) - (uint32)(2146924104));
        v8 = (sint32)((uint32)((sint32)((uint32)(8) * (uint32)((sint32)r_u32(0x80077630u)))) - (uint32)(2146922952));
        v9 = (sint32)((uint32)(8) * (uint32)((sint32)r_u32(0x8007762cu)));
        v10 = (sint32)((uint32)((sint32)((uint32)(8) * (uint32)((sint32)r_u32(0x8007762cu)))) - (uint32)(2146921792));
        v11 = (sint32)(0u - (uint32)(2146925288));
        v383 = 2;
      }
      else
      {
        v383 = 8;
        v7 = (sint32)((uint32)((sint32)((uint32)(8) * (uint32)((sint32)r_u32(0x80077630u)))) - (uint32)(2146923720));
        v8 = (sint32)((uint32)((sint32)((uint32)(8) * (uint32)((sint32)r_u32(0x80077630u)))) - (uint32)(2146922568));
        v9 = (sint32)((uint32)(8) * (uint32)((sint32)r_u32(0x8007762cu)));
        v10 = (sint32)((uint32)((sint32)((uint32)(8) * (uint32)((sint32)r_u32(0x8007762cu)))) - (uint32)(2146921408));
        v11 = (sint32)(0u - (uint32)(2146924904));
      }
    }
    else
    {
      v7 = (sint32)((uint32)((sint32)((uint32)(8) * (uint32)((sint32)r_u32(0x80077630u)))) - (uint32)(2146924488));
      v8 = (sint32)((uint32)((sint32)((uint32)(8) * (uint32)((sint32)r_u32(0x80077630u)))) - (uint32)(2146923336));
      v9 = (sint32)((uint32)(8) * (uint32)((sint32)r_u32(0x8007762cu)));
      v10 = (sint32)((uint32)((sint32)((uint32)(8) * (uint32)((sint32)r_u32(0x8007762cu)))) - (uint32)(2146922176));
      v11 = (sint32)(0u - (uint32)(2146925672));
      v383 = 8;
    }
    v12 = (sint32)((uint32)(v9) + (uint32)(v11));
    w_u8((uint32)((sint32)((uint32)(v7) + (uint32)(7))), (r_u32((uint32)(v7)) && (r_u8((uint32)((sint32)((uint32)(v7) + (uint32)(6)))) == (sint32)((uint32)((sint32)r_u32(0x8007762cu)) - (uint32)(1)))));
    w_u8((uint32)((sint32)((uint32)(v8) + (uint32)(7))), (r_u32((uint32)(v8)) && (r_u8((uint32)((sint32)((uint32)(v8) + (uint32)(6)))) == (sint32)((uint32)((sint32)r_u32(0x8007762cu)) + (uint32)(1)))));
    w_u8((uint32)((sint32)((uint32)(v10) + (uint32)(7))), (r_u32((uint32)(v10)) && (r_u8((uint32)((sint32)((uint32)(v10) + (uint32)(6)))) == (sint32)((uint32)((sint32)r_u32(0x80077630u)) - (uint32)(1)))));
    w_u8((uint32)((sint32)((uint32)(v12) + (uint32)(7))), (r_u32((uint32)(v12)) && (r_u8((uint32)((sint32)((uint32)(v12) + (uint32)(6)))) == (sint32)((uint32)((sint32)r_u32(0x80077630u)) + (uint32)(1)))));
    if ((v2 == 2))
    {
      v15 = v7;
      v7 = v8;
      v8 = v15;
      v16 = v10;
      v10 = v12;
      v12 = v16;
    }
    else
      if (((sint32)(v2) >= (sint32)(3)))
    {
      v14 = v7;
      if ((v2 == 3))
      {
        v7 = v12;
        v12 = v8;
        v8 = v10;
        v10 = v14;
      }
    }
    else
    {
      v13 = v7;
      if ((v2 == 1))
      {
        v7 = v10;
        v10 = v8;
        v8 = v12;
        v12 = v13;
      }
    }
    if (r_u8((uint32)((sint32)((uint32)(v7) + (uint32)(7)))))
    {
      v5 = 1;
    }
    else
      if (r_u8((uint32)((sint32)((uint32)(v8) + (uint32)(7)))))
    {
      v5 = 4;
    }
    result = r_u8((uint32)((sint32)((uint32)(v10) + (uint32)(7))));
    if (r_u8((uint32)((sint32)((uint32)(v10) + (uint32)(7)))))
    {
      v5 |= 2u;
    }
    else
    {
      result = (v5 < 0xD);
      if (r_u8((uint32)((sint32)((uint32)(v12) + (uint32)(7)))))
        v5 |= 8u;
    }
    switch (v5)
    {
      case 0u:
        ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
        ob_draft_gte_load_vertex(1, ((uint32)(vertex_cursor) + (uint32)(8)));
        ob_draft_gte_load_vertex(2, ((uint32)(vertex_cursor) + (uint32)(16)));
        ob_draft_gte_command(0x280030);
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(24));
        v19 = (sint32)((uint32)(v3) + (uint32)(12));
        v20 = (uint16)(((uint32)(r_u16((uint32)(((uint32)(a1) + (uint32)(10))))) - (uint32)(3)));
        v21 = 3;
        if ((v20 >= 3))
      {
        do
        {
          ob_draft_gte_store_data(12, ((uint32)((uint32)(v19)) + (uint32)((sint32)(0u - (uint32)(12)))));
          ob_draft_gte_store_data(13, ((uint32)((uint32)(v19)) + (uint32)((sint32)(0u - (uint32)(8)))));
          ob_draft_gte_store_data(14, ((uint32)((uint32)(v19)) + (uint32)((sint32)(0u - (uint32)(4)))));
          ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
          ob_draft_gte_load_vertex(1, ((uint32)(vertex_cursor) + (uint32)(8)));
          ob_draft_gte_load_vertex(2, ((uint32)(vertex_cursor) + (uint32)(16)));
          ob_draft_gte_command(0x280030);
          vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(24));
          v21 = ((uint32)(v21) + (uint32)(3));
          v19 = ((uint32)(v19) + (uint32)(12));
        }
        while ((v20 >= (uint16)(v21)));
      }
        ob_draft_gte_store_data(12, ((uint32)((uint32)(v19)) + (uint32)((sint32)(0u - (uint32)(12)))));
        ob_draft_gte_store_data(13, ((uint32)((uint32)(v19)) + (uint32)((sint32)(0u - (uint32)(8)))));
        ob_draft_gte_store_data(14, ((uint32)((uint32)(v19)) + (uint32)((sint32)(0u - (uint32)(4)))));
        if (((uint16)(((uint32)(((uint32)(r_u16((uint32)(((uint32)(a1) + (uint32)(10))))) - (uint32)(3))) + (uint32)(2))) >= (uint32)((uint16)(v21))))
      {
        ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
        ob_draft_gte_command(0x180001);
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
        v23 = (uint16)(((uint32)(((uint32)(r_u16((uint32)(((uint32)(a1) + (uint32)(10))))) - (uint32)(3))) + (uint32)(2)));
        for (i = (sint32)((uint32)(v19) + (uint32)(4)); ((uint16)(v21) < v23); i = ((uint32)(i) + (uint32)(4)))
        {
          ob_draft_gte_store_data(14, ((uint32)((uint32)((sint32)((uint32)(i) - (uint32)(4)))) + (uint32)(0)));
          ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
          ob_draft_gte_command(0x180001);
          vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
          ++v21;
        }

        ob_draft_gte_store_data(14, ((uint32)((uint32)((sint32)((uint32)(i) - (uint32)(4)))) + (uint32)(0)));
      }
        v25 = (uint32)((sint32)r_u32(0x80077574u));
        v26 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))));
        ob_draft_unresolved_call(0x800357dcu, 3u, v8, v26, v383);
        v27 = (uint32)(((uint32)(r_u32((uint32)(v8))) + (uint32)((sint32)((uint32)(4) * (uint32)(v26)))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v8) + (uint32)(6))), (sint32)r_u32(0x80077630u));
      else
        w_u8((uint32)((sint32)((uint32)(v8) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
        ob_draft_unresolved_call(0x800357dcu, 3u, v10, ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(87)))))), v383);
        v28 = (uint32)(((uint32)(r_u32((uint32)(v10))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80)))))))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v10) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
      else
        w_u8((uint32)((sint32)((uint32)(v10) + (uint32)(6))), (sint32)r_u32(0x80077630u));
        v29 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(80)))))
      {
        do
        {
          ((v27 -= 4u));
          ((v28 -= 4u));
          v30 = v29;
          v29 = ((uint32)(v29) + (uint32)(0xFFFF));
          w_u32(v27, (sint32)r_u32(v25));
          v31 = (sint32)r_u32(((v25 += 4u) - 4u));
          w_u32(v28, v31);
        }
        while (v30);
      }
        v32 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(81)))))
      {
        do
        {
          ((v27 -= 4u));
          v33 = (sint32)r_u32(((v25 += 4u) - 4u));
          v34 = v32;
          v32 = ((uint32)(v32) + (uint32)(0xFFFF));
          w_u32(v27, v33);
        }
        while (v34);
      }
        v35 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))));
        ob_draft_unresolved_call(0x800357dcu, 3u, v12, v35, v383);
        v36 = (uint32)(((uint32)(r_u32((uint32)(v12))) + (uint32)((sint32)((uint32)(4) * (uint32)(v35)))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v12) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
      else
        w_u8((uint32)((sint32)((uint32)(v12) + (uint32)(6))), (sint32)r_u32(0x80077630u));
        v37 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(82)))))
      {
        do
        {
          ((v27 -= 4u));
          ((v36 -= 4u));
          v38 = v37;
          v37 = ((uint32)(v37) + (uint32)(0xFFFF));
          w_u32(v27, (sint32)r_u32(v25));
          v39 = (sint32)r_u32(((v25 += 4u) - 4u));
          w_u32(v36, v39);
        }
        while (v38);
      }
        v40 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(83)))))
      {
        do
        {
          ((v36 -= 4u));
          v41 = (sint32)r_u32(((v25 += 4u) - 4u));
          v42 = v40;
          v40 = ((uint32)(v40) + (uint32)(0xFFFF));
          w_u32(v36, v41);
        }
        while (v42);
      }
        v43 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))));
        ob_draft_unresolved_call(0x800357dcu, 3u, v7, v43, v383);
        v44 = (uint32)(((uint32)(r_u32((uint32)(v7))) + (uint32)((sint32)((uint32)(4) * (uint32)(v43)))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v7) + (uint32)(6))), (sint32)r_u32(0x80077630u));
      else
        w_u8((uint32)((sint32)((uint32)(v7) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
        v45 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(84)))))
      {
        do
        {
          ((v36 -= 4u));
          ((v44 -= 4u));
          v46 = v45;
          v45 = ((uint32)(v45) + (uint32)(0xFFFF));
          w_u32(v36, (sint32)r_u32(v25));
          v47 = (sint32)r_u32(((v25 += 4u) - 4u));
          w_u32(v44, v47);
        }
        while (v46);
      }
        v48 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(85)))))
      {
        do
        {
          ((v44 -= 4u));
          v49 = (sint32)r_u32(((v25 += 4u) - 4u));
          v50 = v48;
          v48 = ((uint32)(v48) + (uint32)(0xFFFF));
          w_u32(v44, v49);
        }
        while (v50);
      }
        v51 = (uint32)(((uint32)(((uint32)(((uint32)(r_u32((uint32)(v10))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))))))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(87))))))))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80)))))))));
        v52 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(86)))))
      {
        do
        {
          ((v44 -= 4u));
          ((v51 -= 4u));
          v53 = v52;
          v52 = ((uint32)(v52) + (uint32)(0xFFFF));
          w_u32(v44, (sint32)r_u32(v25));
          v54 = (sint32)r_u32(((v25 += 4u) - 4u));
          w_u32(v51, v54);
        }
        while (v53);
      }
        result = r_u8((uint32)(((uint32)(a1) + (uint32)(87))));
        v55 = (sint32)((uint32)(result) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(87)))))
      {
        do
        {
          ((v51 -= 4u));
          v56 = (sint32)r_u32(((v25 += 4u) - 4u));
          result = ((uint32)(result) & ~((uint32)65535u << 0) | (((uint32)(v55) & 65535u) << 0));
          v55 = ((uint32)(v55) + (uint32)(0xFFFF));
          result = (uint16)(result);
          w_u32(v51, v56);
        }
        while ((uint16)(result));
      }
        break;

      case 1u:
        v57 = (uint32)(v3);
        v58 = r_u32((uint32)(v7));
        v59 = r_u8((uint32)(((uint32)(a1) + (uint32)(81))));
        v60 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))))) + (uint32)(v59));
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)((sint32)((uint32)(8) * (uint32)(v60))));
        v62 = (sint32)((uint32)(v60) - (uint32)(1));
        if (((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))))) + (uint32)((uint16)(v59))))
      {
        do
        {
          v63 = (sint32)r_u32(((v58 += 4u) - 4u));
          v64 = v62;
          v62 = ((uint32)(v62) + (uint32)(0xFFFF));
          w_u32(((v57 += 4u) - 4u), v63);
        }
        while (v64);
      }
        v65 = r_u8((uint32)(((uint32)(a1) + (uint32)(82))));
        v66 = ((uint32)(((uint32)(r_u16((uint32)(((uint32)(a1) + (uint32)(10))))) - (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))))) - (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))));
        v67 = (uint16)((sint32)((uint32)(v66) - (uint32)(v65)));
        if ((v66 != v65))
      {
        ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
        ob_draft_gte_command(0x180001);
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
        v69 = 1;
        if ((v67 > 1))
        {
          do
          {
            ob_draft_gte_store_data(14, ((uint32)((uint32)(v57)) + (uint32)(0)));
            ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
            ob_draft_gte_command(0x180001);
            vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
            ++v69;
            ((v57 += 4u));
          }
          while (((uint16)(v69) < v67));
        }
        ob_draft_gte_store_data(14, ((uint32)((uint32)(v57)) + (uint32)(0)));
      }
        v70 = (uint32)(v3);
        ob_draft_unresolved_call(0x800357dcu, 3u, v10, ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(87)))))), v383);
        v71 = (uint32)(((uint32)(r_u32((uint32)(v10))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80)))))))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v10) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
      else
        w_u8((uint32)((sint32)((uint32)(v10) + (uint32)(6))), (sint32)r_u32(0x80077630u));
        v72 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(80)))))
      {
        do
        {
          ((v71 -= 4u));
          v73 = (sint32)r_u32(((v70 += 4u) - 4u));
          v74 = v72;
          v72 = ((uint32)(v72) + (uint32)(0xFFFF));
          w_u32(v71, v73);
        }
        while (v74);
      }
        v75 = ((v70 + (r_u8((uint32)(((uint32)(a1) + (uint32)(81))))) * 4u));
        v76 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))));
        ob_draft_unresolved_call(0x800357dcu, 3u, v12, v76, v383);
        v77 = (uint32)(((uint32)(r_u32((uint32)(v12))) + (uint32)((sint32)((uint32)(4) * (uint32)(v76)))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v12) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
      else
        w_u8((uint32)((sint32)((uint32)(v12) + (uint32)(6))), (sint32)r_u32(0x80077630u));
        v78 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))));
        v79 = (sint32)((uint32)(v78) - (uint32)(1));
        if (v78)
      {
        do
        {
          ((v77 -= 4u));
          v80 = (sint32)r_u32(((v75 += 4u) - 4u));
          v81 = v79;
          v79 = ((uint32)(v79) + (uint32)(0xFFFF));
          w_u32(v77, v80);
        }
        while (v81);
      }
        v82 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))));
        ob_draft_unresolved_call(0x800357dcu, 3u, v7, v82, v383);
        v83 = (uint32)(((uint32)(r_u32((uint32)(v7))) + (uint32)((sint32)((uint32)(4) * (uint32)(v82)))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v7) + (uint32)(6))), (sint32)r_u32(0x80077630u));
      else
        w_u8((uint32)((sint32)((uint32)(v7) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
        v84 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(84)))))
      {
        do
        {
          ((v77 -= 4u));
          ((v83 -= 4u));
          v85 = v84;
          v84 = ((uint32)(v84) + (uint32)(0xFFFF));
          w_u32(v77, (sint32)r_u32(v75));
          v86 = (sint32)r_u32(((v75 += 4u) - 4u));
          w_u32(v83, v86);
        }
        while (v85);
      }
        v87 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(85)))))
      {
        do
        {
          ((v83 -= 4u));
          v88 = (sint32)r_u32(((v75 += 4u) - 4u));
          v89 = v87;
          v87 = ((uint32)(v87) + (uint32)(0xFFFF));
          w_u32(v83, v88);
        }
        while (v89);
      }
        v90 = (uint32)(((uint32)(((uint32)(((uint32)(r_u32((uint32)(v10))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))))))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(87))))))))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80)))))))));
        v91 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(86)))))
      {
        do
        {
          ((v83 -= 4u));
          ((v90 -= 4u));
          v92 = v91;
          v91 = ((uint32)(v91) + (uint32)(0xFFFF));
          w_u32(v83, (sint32)r_u32(v75));
          v93 = (sint32)r_u32(((v75 += 4u) - 4u));
          w_u32(v90, v93);
        }
        while (v92);
      }
        result = r_u8((uint32)(((uint32)(a1) + (uint32)(87))));
        v94 = (sint32)((uint32)(result) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(87)))))
      {
        do
        {
          ((v90 -= 4u));
          v95 = (sint32)r_u32(((v75 += 4u) - 4u));
          result = ((uint32)(result) & ~((uint32)65535u << 0) | (((uint32)(v94) & 65535u) << 0));
          v94 = ((uint32)(v94) + (uint32)(0xFFFF));
          result = (uint16)(result);
          w_u32(v90, v95);
        }
        while ((uint16)(result));
      }
        break;

      case 2u:
        v96 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))));
        v97 = (uint32)(v3);
        if (v96)
      {
        ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
        ob_draft_gte_command(0x180001);
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
        v98 = 1;
        if ((v96 > 1))
        {
          do
          {
            ob_draft_gte_store_data(14, ((uint32)((uint32)(v97)) + (uint32)(0)));
            ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
            ob_draft_gte_command(0x180001);
            vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
            ++v98;
            ((v97 += 4u));
          }
          while (((uint16)(v98) < v96));
        }
        ob_draft_gte_store_data(14, ((uint32)((uint32)(v97)) + (uint32)(0)));
        ((v97 += 4u));
      }
        v99 = r_u32((uint32)(v10));
        v100 = r_u8((uint32)(((uint32)(a1) + (uint32)(83))));
        v101 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))))) + (uint32)(v100));
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)((sint32)((uint32)(8) * (uint32)(v101))));
        v103 = (sint32)((uint32)(v101) - (uint32)(1));
        if (((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))))) + (uint32)((uint16)(v100))))
      {
        do
        {
          v104 = (sint32)r_u32(((v99 += 4u) - 4u));
          v105 = v103;
          v103 = ((uint32)(v103) + (uint32)(0xFFFF));
          w_u32(((v97 += 4u) - 4u), v104);
        }
        while (v105);
      }
        v106 = ((uint32)(((uint32)(((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))));
        v107 = (uint16)(((uint32)(r_u16((uint32)(((uint32)(a1) + (uint32)(10))))) - (uint32)(v106)));
        if ((r_u16((uint32)(((uint32)(a1) + (uint32)(10)))) != v106))
      {
        ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
        ob_draft_gte_command(0x180001);
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
        v109 = (v97 + (1) * 4u);
        v110 = 1;
        if ((v107 > 1))
        {
          do
          {
            ob_draft_gte_store_data(14, ((uint32)((uint32)(((uint32)((uint32)(v109)) - (uint32)(4)))) + (uint32)(0)));
            ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
            ob_draft_gte_command(0x180001);
            vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
            ++v110;
            ((v109 += 4u));
          }
          while (((uint16)(v110) < v107));
        }
        ob_draft_gte_store_data(14, ((uint32)((uint32)(((uint32)((uint32)(v109)) - (uint32)(4)))) + (uint32)(0)));
      }
        v111 = (uint32)(v3);
        v112 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))));
        ob_draft_unresolved_call(0x800357dcu, 3u, v8, v112, v383);
        v113 = (uint32)(((uint32)(r_u32((uint32)(v8))) + (uint32)((sint32)((uint32)(4) * (uint32)(v112)))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v8) + (uint32)(6))), (sint32)r_u32(0x80077630u));
      else
        w_u8((uint32)((sint32)((uint32)(v8) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
        ob_draft_unresolved_call(0x800357dcu, 3u, v10, ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(87)))))), v383);
        v114 = (uint32)(((uint32)(r_u32((uint32)(v10))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80)))))))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v10) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
      else
        w_u8((uint32)((sint32)((uint32)(v10) + (uint32)(6))), (sint32)r_u32(0x80077630u));
        v115 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(80)))))
      {
        do
        {
          ((v113 -= 4u));
          ((v114 -= 4u));
          v116 = v115;
          v115 = ((uint32)(v115) + (uint32)(0xFFFF));
          w_u32(v113, (sint32)r_u32(v111));
          v117 = (sint32)r_u32(((v111 += 4u) - 4u));
          w_u32(v114, v117);
        }
        while (v116);
      }
        v118 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(81)))))
      {
        do
        {
          ((v113 -= 4u));
          v119 = (sint32)r_u32(((v111 += 4u) - 4u));
          v120 = v118;
          v118 = ((uint32)(v118) + (uint32)(0xFFFF));
          w_u32(v113, v119);
        }
        while (v120);
      }
        v121 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(82)))))
      {
        do
        {
          ((v113 -= 4u));
          v122 = (sint32)r_u32(((v111 += 4u) - 4u));
          v123 = v121;
          v121 = ((uint32)(v121) + (uint32)(0xFFFF));
          w_u32(v113, v122);
        }
        while (v123);
      }
        v124 = ((v111 + (r_u8((uint32)(((uint32)(a1) + (uint32)(83))))) * 4u));
        v125 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))));
        ob_draft_unresolved_call(0x800357dcu, 3u, v7, v125, v383);
        v126 = (uint32)(((uint32)(r_u32((uint32)(v7))) + (uint32)((sint32)((uint32)(4) * (uint32)(v125)))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v7) + (uint32)(6))), (sint32)r_u32(0x80077630u));
      else
        w_u8((uint32)((sint32)((uint32)(v7) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
        v127 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(84)))))
      {
        do
        {
          ((v126 -= 4u));
          v128 = (sint32)r_u32(((v124 += 4u) - 4u));
          v129 = v127;
          v127 = ((uint32)(v127) + (uint32)(0xFFFF));
          w_u32(v126, v128);
        }
        while (v129);
      }
        v130 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(85)))))
      {
        do
        {
          ((v126 -= 4u));
          v131 = (sint32)r_u32(((v124 += 4u) - 4u));
          v132 = v130;
          v130 = ((uint32)(v130) + (uint32)(0xFFFF));
          w_u32(v126, v131);
        }
        while (v132);
      }
        v133 = (uint32)(((uint32)(((uint32)(((uint32)(r_u32((uint32)(v10))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))))))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(87))))))))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80)))))))));
        v134 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(86)))))
      {
        do
        {
          ((v126 -= 4u));
          ((v133 -= 4u));
          v135 = v134;
          v134 = ((uint32)(v134) + (uint32)(0xFFFF));
          w_u32(v126, (sint32)r_u32(v124));
          v136 = (sint32)r_u32(((v124 += 4u) - 4u));
          w_u32(v133, v136);
        }
        while (v135);
      }
        result = r_u8((uint32)(((uint32)(a1) + (uint32)(87))));
        v137 = (sint32)((uint32)(result) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(87)))))
      {
        do
        {
          ((v133 -= 4u));
          v138 = (sint32)r_u32(((v124 += 4u) - 4u));
          result = ((uint32)(result) & ~((uint32)65535u << 0) | (((uint32)(v137) & 65535u) << 0));
          v137 = ((uint32)(v137) + (uint32)(0xFFFF));
          result = (uint16)(result);
          w_u32(v133, v138);
        }
        while ((uint16)(result));
      }
        break;

      case 3u:
        v223 = (uint32)(v3);
        v224 = r_u32((uint32)(v7));
        v225 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))));
        v226 = ((uint32)(vertex_cursor) + (uint32)((sint32)((uint32)(8) * (uint32)(v225))));
        v227 = (sint32)((uint32)(v225) - (uint32)(1));
        if (((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))) + (uint32)((uint16)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))))))
      {
        do
        {
          v228 = (sint32)r_u32(((v224 += 4u) - 4u));
          v229 = v227;
          v227 = ((uint32)(v227) + (uint32)(0xFFFF));
          w_u32(((v223 += 4u) - 4u), v228);
        }
        while (v229);
      }
        v230 = r_u32((uint32)(v10));
        v231 = r_u8((uint32)(((uint32)(a1) + (uint32)(83))));
        v232 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))))) + (uint32)(v231));
        vertex_cursor = (sint32)((uint32)(v226) + (uint32)((sint32)((uint32)(8) * (uint32)(v232))));
        v234 = (sint32)((uint32)(v232) - (uint32)(1));
        if (((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))))) + (uint32)((uint16)(v231))))
      {
        do
        {
          v235 = (sint32)r_u32(((v230 += 4u) - 4u));
          v236 = v234;
          v234 = ((uint32)(v234) + (uint32)(0xFFFF));
          w_u32(((v223 += 4u) - 4u), v235);
        }
        while (v236);
      }
        v237 = ((uint32)(((uint32)(((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))));
        v238 = (uint16)(((uint32)(r_u16((uint32)(((uint32)(a1) + (uint32)(10))))) - (uint32)(v237)));
        if ((r_u16((uint32)(((uint32)(a1) + (uint32)(10)))) != v237))
      {
        ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
        ob_draft_gte_command(0x180001);
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
        v240 = 1;
        if ((v238 > 1))
        {
          do
          {
            ob_draft_gte_store_data(14, ((uint32)((uint32)(v223)) + (uint32)(0)));
            ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
            ob_draft_gte_command(0x180001);
            vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
            ++v240;
            ((v223 += 4u));
          }
          while (((uint16)(v240) < v238));
        }
        ob_draft_gte_store_data(14, ((uint32)((uint32)(v223)) + (uint32)(0)));
      }
        v241 = (uint32)(v3);
        ob_draft_unresolved_call(0x800357dcu, 3u, v10, ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(87)))))), v383);
        v242 = (uint32)(((uint32)(r_u32((uint32)(v10))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80)))))))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v10) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
      else
        w_u8((uint32)((sint32)((uint32)(v10) + (uint32)(6))), (sint32)r_u32(0x80077630u));
        v243 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(80)))))
      {
        do
        {
          ((v242 -= 4u));
          v244 = (sint32)r_u32(((v241 += 4u) - 4u));
          v245 = v243;
          v243 = ((uint32)(v243) + (uint32)(0xFFFF));
          w_u32(v242, v244);
        }
        while (v245);
      }
        v246 = ((v241 + (((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))))) * 4u));
        v247 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))));
        ob_draft_unresolved_call(0x800357dcu, 3u, v7, v247, v383);
        v248 = (uint32)(((uint32)(r_u32((uint32)(v7))) + (uint32)((sint32)((uint32)(4) * (uint32)(v247)))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v7) + (uint32)(6))), (sint32)r_u32(0x80077630u));
      else
        w_u8((uint32)((sint32)((uint32)(v7) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
        v249 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))));
        v250 = (sint32)((uint32)(v249) - (uint32)(1));
        if (v249)
      {
        do
        {
          ((v248 -= 4u));
          v251 = (sint32)r_u32(((v246 += 4u) - 4u));
          v252 = v250;
          v250 = ((uint32)(v250) + (uint32)(0xFFFF));
          w_u32(v248, v251);
        }
        while (v252);
      }
        v253 = (uint32)(((uint32)(((uint32)(((uint32)(r_u32((uint32)(v10))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))))))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(87))))))))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80)))))))));
        v254 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(86)))))
      {
        do
        {
          ((v248 -= 4u));
          ((v253 -= 4u));
          v255 = v254;
          v254 = ((uint32)(v254) + (uint32)(0xFFFF));
          w_u32(v248, (sint32)r_u32(v246));
          v256 = (sint32)r_u32(((v246 += 4u) - 4u));
          w_u32(v253, v256);
        }
        while (v255);
      }
        result = r_u8((uint32)(((uint32)(a1) + (uint32)(87))));
        v257 = (sint32)((uint32)(result) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(87)))))
      {
        do
        {
          ((v253 -= 4u));
          v258 = (sint32)r_u32(((v246 += 4u) - 4u));
          result = ((uint32)(result) & ~((uint32)65535u << 0) | (((uint32)(v257) & 65535u) << 0));
          v257 = ((uint32)(v257) + (uint32)(0xFFFF));
          result = (uint16)(result);
          w_u32(v253, v258);
        }
        while ((uint16)(result));
      }
        break;

      case 4u:
        v139 = ((uint32)(((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))));
        v140 = (uint32)(v3);
        if (v139)
      {
        ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
        ob_draft_gte_command(0x180001);
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
        v141 = 1;
        if ((v139 > 1))
        {
          do
          {
            ob_draft_gte_store_data(14, ((uint32)((uint32)(v140)) + (uint32)(0)));
            ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
            ob_draft_gte_command(0x180001);
            vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
            ++v141;
            ((v140 += 4u));
          }
          while (((uint16)(v141) < v139));
        }
        ob_draft_gte_store_data(14, ((uint32)((uint32)(v140)) + (uint32)(0)));
        ((v140 += 4u));
      }
        v142 = r_u32((uint32)(v8));
        v143 = r_u8((uint32)(((uint32)(a1) + (uint32)(85))));
        v144 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))))) + (uint32)(v143));
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)((sint32)((uint32)(8) * (uint32)(v144))));
        v146 = (sint32)((uint32)(v144) - (uint32)(1));
        if (((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))))) + (uint32)((uint16)(v143))))
      {
        do
        {
          v147 = (sint32)r_u32(((v142 += 4u) - 4u));
          v148 = v146;
          v146 = ((uint32)(v146) + (uint32)(0xFFFF));
          w_u32(((v140 += 4u) - 4u), v147);
        }
        while (v148);
      }
        v149 = r_u16((uint32)(((uint32)(a1) + (uint32)(10))));
        v150 = ((uint32)(((uint32)(((uint32)(((uint32)(((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))));
        v151 = (uint16)((sint32)((uint32)(v149) - (uint32)(v150)));
        if ((v149 != v150))
      {
        ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
        ob_draft_gte_command(0x180001);
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
        v153 = 1;
        if ((v151 > 1))
        {
          do
          {
            ob_draft_gte_store_data(14, ((uint32)((uint32)(v140)) + (uint32)(0)));
            ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
            ob_draft_gte_command(0x180001);
            vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
            ++v153;
            ((v140 += 4u));
          }
          while (((uint16)(v153) < v151));
        }
        ob_draft_gte_store_data(14, ((uint32)((uint32)(v140)) + (uint32)(0)));
      }
        v154 = (uint32)(v3);
        v155 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))));
        ob_draft_unresolved_call(0x800357dcu, 3u, v8, v155, v383);
        v156 = (uint32)(((uint32)(r_u32((uint32)(v8))) + (uint32)((sint32)((uint32)(4) * (uint32)(v155)))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v8) + (uint32)(6))), (sint32)r_u32(0x80077630u));
      else
        w_u8((uint32)((sint32)((uint32)(v8) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
        ob_draft_unresolved_call(0x800357dcu, 3u, v10, ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(87)))))), v383);
        v157 = (uint32)(((uint32)(r_u32((uint32)(v10))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80)))))))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v10) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
      else
        w_u8((uint32)((sint32)((uint32)(v10) + (uint32)(6))), (sint32)r_u32(0x80077630u));
        v158 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(80)))))
      {
        do
        {
          ((v156 -= 4u));
          ((v157 -= 4u));
          v159 = v158;
          v158 = ((uint32)(v158) + (uint32)(0xFFFF));
          w_u32(v156, (sint32)r_u32(v154));
          v160 = (sint32)r_u32(((v154 += 4u) - 4u));
          w_u32(v157, v160);
        }
        while (v159);
      }
        v161 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(81)))))
      {
        do
        {
          ((v156 -= 4u));
          v162 = (sint32)r_u32(((v154 += 4u) - 4u));
          v163 = v161;
          v161 = ((uint32)(v161) + (uint32)(0xFFFF));
          w_u32(v156, v162);
        }
        while (v163);
      }
        v164 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))));
        ob_draft_unresolved_call(0x800357dcu, 3u, v12, v164, v383);
        v165 = (uint32)(((uint32)(r_u32((uint32)(v12))) + (uint32)((sint32)((uint32)(4) * (uint32)(v164)))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v12) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
      else
        w_u8((uint32)((sint32)((uint32)(v12) + (uint32)(6))), (sint32)r_u32(0x80077630u));
        v166 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(82)))))
      {
        do
        {
          ((v156 -= 4u));
          ((v165 -= 4u));
          v167 = v166;
          v166 = ((uint32)(v166) + (uint32)(0xFFFF));
          w_u32(v156, (sint32)r_u32(v154));
          v168 = (sint32)r_u32(((v154 += 4u) - 4u));
          w_u32(v165, v168);
        }
        while (v167);
      }
        v169 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))));
        v170 = (sint32)((uint32)(v169) - (uint32)(1));
        if (v169)
      {
        do
        {
          ((v165 -= 4u));
          v171 = (sint32)r_u32(((v154 += 4u) - 4u));
          v172 = v170;
          v170 = ((uint32)(v170) + (uint32)(0xFFFF));
          w_u32(v165, v171);
        }
        while (v172);
      }
        v173 = r_u8((uint32)(((uint32)(a1) + (uint32)(86))));
        v174 = r_u8((uint32)(((uint32)(a1) + (uint32)(87))));
        v175 = ((v154 + (r_u8((uint32)(((uint32)(a1) + (uint32)(85))))) * 4u));
        v176 = ((uint32)(((uint32)(r_u32((uint32)(v10))) + (uint32)((sint32)((uint32)(4) * (uint32)(v173))))) + (uint32)((sint32)((uint32)(4) * (uint32)(v174))));
        v177 = (sint32)((uint32)(v173) + (uint32)(v174));
        v178 = (sint32)((uint32)(v177) - (uint32)(1));
        result = (sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))));
        v179 = (uint32)((sint32)((uint32)(v176) + (uint32)(result)));
        if (v177)
      {
        do
        {
          ((v179 -= 4u));
          v180 = (sint32)r_u32(((v175 += 4u) - 4u));
          result = ((uint32)(result) & ~((uint32)65535u << 0) | (((uint32)(v178) & 65535u) << 0));
          v178 = ((uint32)(v178) + (uint32)(0xFFFF));
          result = (uint16)(result);
          w_u32(v179, v180);
        }
        while ((uint16)(result));
      }
        break;

      case 6u:
        v259 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))));
        v260 = (uint32)(v3);
        if (v259)
      {
        ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
        ob_draft_gte_command(0x180001);
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
        v261 = 1;
        if ((v259 > 1))
        {
          do
          {
            ob_draft_gte_store_data(14, ((uint32)((uint32)(v260)) + (uint32)(0)));
            ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
            ob_draft_gte_command(0x180001);
            vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
            ++v261;
            ((v260 += 4u));
          }
          while (((uint16)(v261) < v259));
        }
        ob_draft_gte_store_data(14, ((uint32)((uint32)(v260)) + (uint32)(0)));
        ((v260 += 4u));
      }
        v262 = r_u32((uint32)(v10));
        v263 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))));
        v264 = ((uint32)(vertex_cursor) + (uint32)((sint32)((uint32)(8) * (uint32)(v263))));
        v265 = (sint32)((uint32)(v263) - (uint32)(1));
        if (((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))) + (uint32)((uint16)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))))))
      {
        do
        {
          v266 = (sint32)r_u32(((v262 += 4u) - 4u));
          v267 = v265;
          v265 = ((uint32)(v265) + (uint32)(0xFFFF));
          w_u32(((v260 += 4u) - 4u), v266);
        }
        while (v267);
      }
        v268 = r_u32((uint32)(v8));
        v269 = r_u8((uint32)(((uint32)(a1) + (uint32)(85))));
        v270 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))))) + (uint32)(v269));
        vertex_cursor = (sint32)((uint32)(v264) + (uint32)((sint32)((uint32)(8) * (uint32)(v270))));
        v272 = (sint32)((uint32)(v270) - (uint32)(1));
        if (((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))))) + (uint32)((uint16)(v269))))
      {
        do
        {
          v273 = (sint32)r_u32(((v268 += 4u) - 4u));
          v274 = v272;
          v272 = ((uint32)(v272) + (uint32)(0xFFFF));
          w_u32(((v260 += 4u) - 4u), v273);
        }
        while (v274);
      }
        v275 = r_u16((uint32)(((uint32)(a1) + (uint32)(10))));
        v276 = ((uint32)(((uint32)(((uint32)(((uint32)(((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))));
        v277 = (uint16)((sint32)((uint32)(v275) - (uint32)(v276)));
        if ((v275 != v276))
      {
        ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
        ob_draft_gte_command(0x180001);
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
        v279 = 1;
        if ((v277 > 1))
        {
          do
          {
            ob_draft_gte_store_data(14, ((uint32)((uint32)(v260)) + (uint32)(0)));
            ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
            ob_draft_gte_command(0x180001);
            vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
            ++v279;
            ((v260 += 4u));
          }
          while (((uint16)(v279) < v277));
        }
        ob_draft_gte_store_data(14, ((uint32)((uint32)(v260)) + (uint32)(0)));
      }
        v280 = (uint32)(v3);
        v281 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))));
        ob_draft_unresolved_call(0x800357dcu, 3u, v8, v281, v383);
        v282 = (uint32)(((uint32)(r_u32((uint32)(v8))) + (uint32)((sint32)((uint32)(4) * (uint32)(v281)))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v8) + (uint32)(6))), (sint32)r_u32(0x80077630u));
      else
        w_u8((uint32)((sint32)((uint32)(v8) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
        ob_draft_unresolved_call(0x800357dcu, 3u, v10, ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(87)))))), v383);
        v283 = (uint32)(((uint32)(r_u32((uint32)(v10))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80)))))))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v10) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
      else
        w_u8((uint32)((sint32)((uint32)(v10) + (uint32)(6))), (sint32)r_u32(0x80077630u));
        v284 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(80)))))
      {
        do
        {
          ((v282 -= 4u));
          ((v283 -= 4u));
          v285 = v284;
          v284 = ((uint32)(v284) + (uint32)(0xFFFF));
          w_u32(v282, (sint32)r_u32(v280));
          v286 = (sint32)r_u32(((v280 += 4u) - 4u));
          w_u32(v283, v286);
        }
        while (v285);
      }
        v287 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))));
        v288 = (sint32)((uint32)(v287) - (uint32)(1));
        if (v287)
      {
        do
        {
          ((v282 -= 4u));
          v289 = (sint32)r_u32(((v280 += 4u) - 4u));
          v290 = v288;
          v288 = ((uint32)(v288) + (uint32)(0xFFFF));
          w_u32(v282, v289);
        }
        while (v290);
      }
        v291 = r_u8((uint32)(((uint32)(a1) + (uint32)(86))));
        v292 = r_u8((uint32)(((uint32)(a1) + (uint32)(87))));
        v293 = ((v280 + (((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))))) * 4u));
        v294 = (sint32)((uint32)(4) * (uint32)(v291));
        v295 = (sint32)((uint32)(4) * (uint32)(v292));
        v296 = (sint32)((uint32)(v291) + (uint32)(v292));
        v297 = (sint32)((uint32)(v296) - (uint32)(1));
        v298 = ((uint32)(((uint32)(r_u32((uint32)(v10))) + (uint32)(v294))) + (uint32)(v295));
        result = (sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))));
        v299 = (uint32)((sint32)((uint32)(v298) + (uint32)(result)));
        if (v296)
      {
        do
        {
          ((v299 -= 4u));
          v300 = (sint32)r_u32(((v293 += 4u) - 4u));
          result = ((uint32)(result) & ~((uint32)65535u << 0) | (((uint32)(v297) & 65535u) << 0));
          v297 = ((uint32)(v297) + (uint32)(0xFFFF));
          result = (uint16)(result);
          w_u32(v299, v300);
        }
        while ((uint16)(result));
      }
        break;

      case 8u:
        v181 = (uint32)(v3);
        v182 = r_u8((uint32)(((uint32)(a1) + (uint32)(80))));
        v183 = (uint32)(((uint32)(((uint32)(r_u32((uint32)(v12))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))))))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(87)))))))));
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)((sint32)((uint32)(8) * (uint32)(v182))));
        v185 = (sint32)((uint32)(v182) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(80)))))
      {
        do
        {
          v186 = (sint32)r_u32(((v183 += 4u) - 4u));
          v187 = v185;
          v185 = ((uint32)(v185) + (uint32)(0xFFFF));
          w_u32(((v181 += 4u) - 4u), v186);
        }
        while (v187);
      }
        v188 = ((uint32)(((uint32)(((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))));
        if (v188)
      {
        ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
        ob_draft_gte_command(0x180001);
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
        v189 = 1;
        if ((v188 > 1))
        {
          do
          {
            ob_draft_gte_store_data(14, ((uint32)((uint32)(v181)) + (uint32)(0)));
            ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
            ob_draft_gte_command(0x180001);
            vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
            ++v189;
            ((v181 += 4u));
          }
          while (((uint16)(v189) < v188));
        }
        ob_draft_gte_store_data(14, ((uint32)((uint32)(v181)) + (uint32)(0)));
        ((v181 += 4u));
      }
        v190 = r_u32((uint32)(v12));
        v191 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(87))))));
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)((sint32)((uint32)(8) * (uint32)(v191))));
        v193 = (sint32)((uint32)(v191) - (uint32)(1));
        if (((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) + (uint32)((uint16)(r_u8((uint32)(((uint32)(a1) + (uint32)(87))))))))
      {
        do
        {
          v194 = (sint32)r_u32(((v190 += 4u) - 4u));
          v195 = v193;
          v193 = ((uint32)(v193) + (uint32)(0xFFFF));
          w_u32(((v181 += 4u) - 4u), v194);
        }
        while (v195);
      }
        v196 = r_u16((uint32)(((uint32)(a1) + (uint32)(10))));
        v197 = ((uint32)(((uint32)(((uint32)(((uint32)(((uint32)(((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(87))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))));
        v198 = (uint16)((sint32)((uint32)(v196) - (uint32)(v197)));
        if ((v196 != v197))
      {
        ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
        ob_draft_gte_command(0x180001);
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
        v200 = 1;
        if ((v198 > 1))
        {
          do
          {
            ob_draft_gte_store_data(14, ((uint32)((uint32)(v181)) + (uint32)(0)));
            ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
            ob_draft_gte_command(0x180001);
            vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
            ++v200;
            ((v181 += 4u));
          }
          while (((uint16)(v200) < v198));
        }
        ob_draft_gte_store_data(14, ((uint32)((uint32)(v181)) + (uint32)(0)));
      }
        v201 = (uint32)(v3);
        v202 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))));
        ob_draft_unresolved_call(0x800357dcu, 3u, v8, v202, v383);
        v203 = (uint32)(((uint32)(r_u32((uint32)(v8))) + (uint32)((sint32)((uint32)(4) * (uint32)(v202)))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v8) + (uint32)(6))), (sint32)r_u32(0x80077630u));
      else
        w_u8((uint32)((sint32)((uint32)(v8) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
        v204 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))));
        v205 = (sint32)((uint32)(v204) - (uint32)(1));
        if (v204)
      {
        do
        {
          ((v203 -= 4u));
          v206 = (sint32)r_u32(((v201 += 4u) - 4u));
          v207 = v205;
          v205 = ((uint32)(v205) + (uint32)(0xFFFF));
          w_u32(v203, v206);
        }
        while (v207);
      }
        v208 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))));
        ob_draft_unresolved_call(0x800357dcu, 3u, v12, v208, v383);
        v209 = (uint32)(((uint32)(r_u32((uint32)(v12))) + (uint32)((sint32)((uint32)(4) * (uint32)(v208)))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v12) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
      else
        w_u8((uint32)((sint32)((uint32)(v12) + (uint32)(6))), (sint32)r_u32(0x80077630u));
        v210 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(82)))))
      {
        do
        {
          ((v203 -= 4u));
          ((v209 -= 4u));
          v211 = v210;
          v210 = ((uint32)(v210) + (uint32)(0xFFFF));
          w_u32(v203, (sint32)r_u32(v201));
          v212 = (sint32)r_u32(((v201 += 4u) - 4u));
          w_u32(v209, v212);
        }
        while (v211);
      }
        v213 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(83)))))
      {
        do
        {
          ((v209 -= 4u));
          v214 = (sint32)r_u32(((v201 += 4u) - 4u));
          v215 = v213;
          v213 = ((uint32)(v213) + (uint32)(0xFFFF));
          w_u32(v209, v214);
        }
        while (v215);
      }
        v216 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))));
        ob_draft_unresolved_call(0x800357dcu, 3u, v7, v216, v383);
        v217 = (uint32)(((uint32)(r_u32((uint32)(v7))) + (uint32)((sint32)((uint32)(4) * (uint32)(v216)))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v7) + (uint32)(6))), (sint32)r_u32(0x80077630u));
      else
        w_u8((uint32)((sint32)((uint32)(v7) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
        v218 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(84)))))
      {
        do
        {
          ((v209 -= 4u));
          ((v217 -= 4u));
          v219 = v218;
          v218 = ((uint32)(v218) + (uint32)(0xFFFF));
          w_u32(v209, (sint32)r_u32(v201));
          v220 = (sint32)r_u32(((v201 += 4u) - 4u));
          w_u32(v217, v220);
        }
        while (v219);
      }
        result = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))));
        v221 = (sint32)((uint32)(result) - (uint32)(1));
        if (result)
      {
        do
        {
          ((v217 -= 4u));
          v222 = (sint32)r_u32(((v201 += 4u) - 4u));
          result = ((uint32)(result) & ~((uint32)65535u << 0) | (((uint32)(v221) & 65535u) << 0));
          v221 = ((uint32)(v221) + (uint32)(0xFFFF));
          result = (uint16)(result);
          w_u32(v217, v222);
        }
        while ((uint16)(result));
      }
        break;

      case 9u:
        v341 = (uint32)(v3);
        v342 = r_u32((uint32)(v7));
        v343 = r_u8((uint32)(((uint32)(a1) + (uint32)(81))));
        v344 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))))) + (uint32)(v343));
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)((sint32)((uint32)(8) * (uint32)(v344))));
        v346 = (sint32)((uint32)(v344) - (uint32)(1));
        if (((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))))) + (uint32)((uint16)(v343))))
      {
        do
        {
          v347 = (sint32)r_u32(((v342 += 4u) - 4u));
          v348 = v346;
          v346 = ((uint32)(v346) + (uint32)(0xFFFF));
          w_u32(((v341 += 4u) - 4u), v347);
        }
        while (v348);
      }
        v349 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))));
        if (v349)
      {
        ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
        ob_draft_gte_command(0x180001);
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
        v350 = 1;
        if ((v349 > 1))
        {
          do
          {
            ob_draft_gte_store_data(14, ((uint32)((uint32)(v341)) + (uint32)(0)));
            ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
            ob_draft_gte_command(0x180001);
            vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
            ++v350;
            ((v341 += 4u));
          }
          while (((uint16)(v350) < v349));
        }
        ob_draft_gte_store_data(14, ((uint32)((uint32)(v341)) + (uint32)(0)));
        ((v341 += 4u));
      }
        v351 = r_u32((uint32)(v12));
        v352 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(87))))));
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)((sint32)((uint32)(8) * (uint32)(v352))));
        v354 = (sint32)((uint32)(v352) - (uint32)(1));
        if (((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) + (uint32)((uint16)(r_u8((uint32)(((uint32)(a1) + (uint32)(87))))))))
      {
        do
        {
          v355 = (sint32)r_u32(((v351 += 4u) - 4u));
          v356 = v354;
          v354 = ((uint32)(v354) + (uint32)(0xFFFF));
          w_u32(((v341 += 4u) - 4u), v355);
        }
        while (v356);
      }
        v357 = r_u16((uint32)(((uint32)(a1) + (uint32)(10))));
        v358 = ((uint32)(((uint32)(((uint32)(((uint32)(((uint32)(((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(87))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))));
        v359 = (uint16)((sint32)((uint32)(v357) - (uint32)(v358)));
        if ((v357 != v358))
      {
        ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
        ob_draft_gte_command(0x180001);
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
        v361 = 1;
        if ((v359 > 1))
        {
          do
          {
            ob_draft_gte_store_data(14, ((uint32)((uint32)(v341)) + (uint32)(0)));
            ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
            ob_draft_gte_command(0x180001);
            vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
            ++v361;
            ((v341 += 4u));
          }
          while (((uint16)(v361) < v359));
        }
        ob_draft_gte_store_data(14, ((uint32)((uint32)(v341)) + (uint32)(0)));
      }
        v362 = (uint32)((sint32)((uint32)(v3) + (uint32)((sint32)((uint32)(4) * (uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81)))))))))));
        v363 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))));
        ob_draft_unresolved_call(0x800357dcu, 3u, v12, v363, v383);
        v364 = (uint32)(((uint32)(r_u32((uint32)(v12))) + (uint32)((sint32)((uint32)(4) * (uint32)(v363)))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v12) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
      else
        w_u8((uint32)((sint32)((uint32)(v12) + (uint32)(6))), (sint32)r_u32(0x80077630u));
        v365 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))));
        v366 = (sint32)((uint32)(v365) - (uint32)(1));
        if (v365)
      {
        do
        {
          ((v364 -= 4u));
          v367 = (sint32)r_u32(((v362 += 4u) - 4u));
          v368 = v366;
          v366 = ((uint32)(v366) + (uint32)(0xFFFF));
          w_u32(v364, v367);
        }
        while (v368);
      }
        v369 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))));
        ob_draft_unresolved_call(0x800357dcu, 3u, v7, v369, v383);
        v370 = (uint32)(((uint32)(r_u32((uint32)(v7))) + (uint32)((sint32)((uint32)(4) * (uint32)(v369)))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v7) + (uint32)(6))), (sint32)r_u32(0x80077630u));
      else
        w_u8((uint32)((sint32)((uint32)(v7) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
        v371 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(84)))))
      {
        do
        {
          ((v364 -= 4u));
          ((v370 -= 4u));
          v372 = v371;
          v371 = ((uint32)(v371) + (uint32)(0xFFFF));
          w_u32(v364, (sint32)r_u32(v362));
          v373 = (sint32)r_u32(((v362 += 4u) - 4u));
          w_u32(v370, v373);
        }
        while (v372);
      }
        result = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))));
        v374 = (sint32)((uint32)(result) - (uint32)(1));
        if (result)
      {
        do
        {
          ((v370 -= 4u));
          v375 = (sint32)r_u32(((v362 += 4u) - 4u));
          result = ((uint32)(result) & ~((uint32)65535u << 0) | (((uint32)(v374) & 65535u) << 0));
          v374 = ((uint32)(v374) + (uint32)(0xFFFF));
          result = (uint16)(result);
          w_u32(v370, v375);
        }
        while ((uint16)(result));
      }
        break;

      case 0xCu:
        v301 = (uint32)(v3);
        v302 = r_u8((uint32)(((uint32)(a1) + (uint32)(80))));
        v303 = (uint32)(((uint32)(((uint32)(r_u32((uint32)(v12))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))))))) + (uint32)((sint32)((uint32)(4) * (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(87)))))))));
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)((sint32)((uint32)(8) * (uint32)(v302))));
        v305 = (sint32)((uint32)(v302) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(80)))))
      {
        do
        {
          v306 = (sint32)r_u32(((v303 += 4u) - 4u));
          v307 = v305;
          v305 = ((uint32)(v305) + (uint32)(0xFFFF));
          w_u32(((v301 += 4u) - 4u), v306);
        }
        while (v307);
      }
        v308 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))));
        if (v308)
      {
        ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
        ob_draft_gte_command(0x180001);
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
        v309 = 1;
        if ((v308 > 1))
        {
          do
          {
            ob_draft_gte_store_data(14, ((uint32)((uint32)(v301)) + (uint32)(0)));
            ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
            ob_draft_gte_command(0x180001);
            vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
            ++v309;
            ((v301 += 4u));
          }
          while (((uint16)(v309) < v308));
        }
        ob_draft_gte_store_data(14, ((uint32)((uint32)(v301)) + (uint32)(0)));
        ((v301 += 4u));
      }
        v310 = r_u32((uint32)(v8));
        v311 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))));
        v312 = ((uint32)(vertex_cursor) + (uint32)((sint32)((uint32)(8) * (uint32)(v311))));
        v313 = (sint32)((uint32)(v311) - (uint32)(1));
        if (((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))) + (uint32)((uint16)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))))))
      {
        do
        {
          v314 = (sint32)r_u32(((v310 += 4u) - 4u));
          v315 = v313;
          v313 = ((uint32)(v313) + (uint32)(0xFFFF));
          w_u32(((v301 += 4u) - 4u), v314);
        }
        while (v315);
      }
        v316 = r_u32((uint32)(v12));
        v317 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(87))))));
        vertex_cursor = (sint32)((uint32)(v312) + (uint32)((sint32)((uint32)(8) * (uint32)(v317))));
        v319 = (sint32)((uint32)(v317) - (uint32)(1));
        if (((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))) + (uint32)((uint16)(r_u8((uint32)(((uint32)(a1) + (uint32)(87))))))))
      {
        do
        {
          v320 = (sint32)r_u32(((v316 += 4u) - 4u));
          v321 = v319;
          v319 = ((uint32)(v319) + (uint32)(0xFFFF));
          w_u32(((v301 += 4u) - 4u), v320);
        }
        while (v321);
      }
        v322 = r_u16((uint32)(((uint32)(a1) + (uint32)(10))));
        v323 = ((uint32)(((uint32)(((uint32)(((uint32)(((uint32)(((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(87))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(86))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(85))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))));
        v324 = (uint16)((sint32)((uint32)(v322) - (uint32)(v323)));
        if ((v322 != v323))
      {
        ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
        ob_draft_gte_command(0x180001);
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
        v326 = 1;
        if ((v324 > 1))
        {
          do
          {
            ob_draft_gte_store_data(14, ((uint32)((uint32)(v301)) + (uint32)(0)));
            ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
            ob_draft_gte_command(0x180001);
            vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
            ++v326;
            ((v301 += 4u));
          }
          while (((uint16)(v326) < v324));
        }
        ob_draft_gte_store_data(14, ((uint32)((uint32)(v301)) + (uint32)(0)));
      }
        v327 = (uint32)(v3);
        v328 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))));
        ob_draft_unresolved_call(0x800357dcu, 3u, v8, v328, v383);
        v329 = (uint32)(((uint32)(r_u32((uint32)(v8))) + (uint32)((sint32)((uint32)(4) * (uint32)(v328)))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v8) + (uint32)(6))), (sint32)r_u32(0x80077630u));
      else
        w_u8((uint32)((sint32)((uint32)(v8) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
        v330 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(80))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(81))))));
        v331 = (sint32)((uint32)(v330) - (uint32)(1));
        if (v330)
      {
        do
        {
          ((v329 -= 4u));
          v332 = (sint32)r_u32(((v327 += 4u) - 4u));
          v333 = v331;
          v331 = ((uint32)(v331) + (uint32)(0xFFFF));
          w_u32(v329, v332);
        }
        while (v333);
      }
        v334 = ((uint32)(((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))));
        ob_draft_unresolved_call(0x800357dcu, 3u, v12, v334, v383);
        v335 = (uint32)(((uint32)(r_u32((uint32)(v12))) + (uint32)((sint32)((uint32)(4) * (uint32)(v334)))));
        if (((v2 & 1) != 0))
        w_u8((uint32)((sint32)((uint32)(v12) + (uint32)(6))), (sint32)r_u32(0x8007762cu));
      else
        w_u8((uint32)((sint32)((uint32)(v12) + (uint32)(6))), (sint32)r_u32(0x80077630u));
        v336 = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(82))))) - (uint32)(1));
        if (r_u8((uint32)(((uint32)(a1) + (uint32)(82)))))
      {
        do
        {
          ((v329 -= 4u));
          ((v335 -= 4u));
          v337 = v336;
          v336 = ((uint32)(v336) + (uint32)(0xFFFF));
          w_u32(v329, (sint32)r_u32(v327));
          v338 = (sint32)r_u32(((v327 += 4u) - 4u));
          w_u32(v335, v338);
        }
        while (v337);
      }
        result = ((uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(83))))) + (uint32)(r_u8((uint32)(((uint32)(a1) + (uint32)(84))))));
        v339 = (sint32)((uint32)(result) - (uint32)(1));
        if (result)
      {
        do
        {
          ((v335 -= 4u));
          v340 = (sint32)r_u32(((v327 += 4u) - 4u));
          result = ((uint32)(result) & ~((uint32)65535u << 0) | (((uint32)(v339) & 65535u) << 0));
          v339 = ((uint32)(v339) + (uint32)(0xFFFF));
          result = (uint16)(result);
          w_u32(v335, v340);
        }
        while ((uint16)(result));
      }
        break;

      default:
        return result;

    }

  }
  else
  {
    ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
    ob_draft_gte_load_vertex(1, ((uint32)(vertex_cursor) + (uint32)(8)));
    ob_draft_gte_load_vertex(2, ((uint32)(vertex_cursor) + (uint32)(16)));
    ob_draft_gte_command(0x280030);
    vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(24));
    v377 = (sint32)((uint32)((sint32)r_u32(0x80077574u)) + (uint32)(12));
    v378 = (uint16)(((uint32)(r_u16((uint32)(((uint32)(a1) + (uint32)(10))))) - (uint32)(3)));
    v379 = 3;
    if ((v378 >= 3))
    {
      do
      {
        ob_draft_gte_store_data(12, ((uint32)((uint32)(v377)) + (uint32)((sint32)(0u - (uint32)(12)))));
        ob_draft_gte_store_data(13, ((uint32)((uint32)(v377)) + (uint32)((sint32)(0u - (uint32)(8)))));
        ob_draft_gte_store_data(14, ((uint32)((uint32)(v377)) + (uint32)((sint32)(0u - (uint32)(4)))));
        ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
        ob_draft_gte_load_vertex(1, ((uint32)(vertex_cursor) + (uint32)(8)));
        ob_draft_gte_load_vertex(2, ((uint32)(vertex_cursor) + (uint32)(16)));
        ob_draft_gte_command(0x280030);
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(24));
        v379 = ((uint32)(v379) + (uint32)(3));
        v377 = ((uint32)(v377) + (uint32)(12));
      }
      while ((v378 >= (uint16)(v379)));
    }
    ob_draft_gte_store_data(12, ((uint32)((uint32)(v377)) + (uint32)((sint32)(0u - (uint32)(12)))));
    ob_draft_gte_store_data(13, ((uint32)((uint32)(v377)) + (uint32)((sint32)(0u - (uint32)(8)))));
    ob_draft_gte_store_data(14, ((uint32)((uint32)(v377)) + (uint32)((sint32)(0u - (uint32)(4)))));
    result = ((uint16)(((uint32)(((uint32)(r_u16((uint32)(((uint32)(a1) + (uint32)(10))))) - (uint32)(3))) + (uint32)(2))) < (uint32)((uint16)(v379)));
    if (((uint16)(((uint32)(((uint32)(r_u16((uint32)(((uint32)(a1) + (uint32)(10))))) - (uint32)(3))) + (uint32)(2))) >= (uint32)((uint16)(v379))))
    {
      ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
      ob_draft_gte_command(0x180001);
      vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
      v381 = (uint16)(((uint32)(((uint32)(r_u16((uint32)(((uint32)(a1) + (uint32)(10))))) - (uint32)(3))) + (uint32)(2)));
      for (j = (sint32)((uint32)(v377) + (uint32)(4)); ((uint16)(v379) < v381); j = ((uint32)(j) + (uint32)(4)))
      {
        ob_draft_gte_store_data(14, ((uint32)((uint32)((sint32)((uint32)(j) - (uint32)(4)))) + (uint32)(0)));
        ob_draft_gte_load_vertex(0, ((uint32)(vertex_cursor) + (uint32)(0)));
        ob_draft_gte_command(0x180001);
        vertex_cursor = ((uint32)(vertex_cursor) + (uint32)(8));
        ++v379;
      }

      result = (sint32)((uint32)(j) - (uint32)(4));
      ob_draft_gte_store_data(14, ((uint32)((uint32)((sint32)((uint32)(j) - (uint32)(4)))) + (uint32)(0)));
    }
  }
  return result;
}

