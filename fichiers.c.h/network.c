/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Sun Jun 19 18:54:13 2022
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "network.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



/*
#define AI_TOOLS_VERSION_MAJOR 6
#define AI_TOOLS_VERSION_MINOR 0
#define AI_TOOLS_VERSION_MICRO 0
#define AI_TOOLS_VERSION_EXTRA "RC6"

*/

/*
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 4
#define AI_TOOLS_API_VERSION_MICRO 0
*/

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network
 
#undef AI_NETWORK_MODEL_SIGNATURE
#define AI_NETWORK_MODEL_SIGNATURE     "37d285b5796f673cbfa31647a1228e13"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Sun Jun 19 18:54:13 2022"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array serving_default_sequential_17_input0_output_array;   /* Array #0 */
AI_STATIC ai_array conversion_0_output_array;   /* Array #1 */
AI_STATIC ai_array conv2d_2_output_array;   /* Array #2 */
AI_STATIC ai_array conv2d_3_output_array;   /* Array #3 */
AI_STATIC ai_array conv2d_4_output_array;   /* Array #4 */
AI_STATIC ai_array conv2d_5_output_array;   /* Array #5 */
AI_STATIC ai_array conv2d_7_output_array;   /* Array #6 */
AI_STATIC ai_array conv2d_8_output_array;   /* Array #7 */
AI_STATIC ai_array conv2d_9_output_array;   /* Array #8 */
AI_STATIC ai_array conv2d_10_output_array;   /* Array #9 */
AI_STATIC ai_array conv2d_11_output_array;   /* Array #10 */
AI_STATIC ai_array eltwise_12_output_array;   /* Array #11 */
AI_STATIC ai_array conv2d_13_output_array;   /* Array #12 */
AI_STATIC ai_array conv2d_15_output_array;   /* Array #13 */
AI_STATIC ai_array conv2d_16_output_array;   /* Array #14 */
AI_STATIC ai_array conv2d_17_output_array;   /* Array #15 */
AI_STATIC ai_array conv2d_18_output_array;   /* Array #16 */
AI_STATIC ai_array conv2d_19_output_array;   /* Array #17 */
AI_STATIC ai_array eltwise_20_output_array;   /* Array #18 */
AI_STATIC ai_array conv2d_21_output_array;   /* Array #19 */
AI_STATIC ai_array conv2d_22_output_array;   /* Array #20 */
AI_STATIC ai_array conv2d_23_output_array;   /* Array #21 */
AI_STATIC ai_array eltwise_24_output_array;   /* Array #22 */
AI_STATIC ai_array conv2d_25_output_array;   /* Array #23 */
AI_STATIC ai_array conv2d_27_output_array;   /* Array #24 */
AI_STATIC ai_array conv2d_28_output_array;   /* Array #25 */
AI_STATIC ai_array conv2d_29_output_array;   /* Array #26 */
AI_STATIC ai_array conv2d_30_output_array;   /* Array #27 */
AI_STATIC ai_array conv2d_31_output_array;   /* Array #28 */
AI_STATIC ai_array eltwise_32_output_array;   /* Array #29 */
AI_STATIC ai_array conv2d_33_output_array;   /* Array #30 */
AI_STATIC ai_array conv2d_34_output_array;   /* Array #31 */
AI_STATIC ai_array conv2d_35_output_array;   /* Array #32 */
AI_STATIC ai_array eltwise_36_output_array;   /* Array #33 */
AI_STATIC ai_array conv2d_37_output_array;   /* Array #34 */
AI_STATIC ai_array conv2d_38_output_array;   /* Array #35 */
AI_STATIC ai_array conv2d_39_output_array;   /* Array #36 */
AI_STATIC ai_array eltwise_40_output_array;   /* Array #37 */
AI_STATIC ai_array conv2d_41_output_array;   /* Array #38 */
AI_STATIC ai_array conv2d_42_output_array;   /* Array #39 */
AI_STATIC ai_array conv2d_43_output_array;   /* Array #40 */
AI_STATIC ai_array conv2d_44_output_array;   /* Array #41 */
AI_STATIC ai_array conv2d_45_output_array;   /* Array #42 */
AI_STATIC ai_array conv2d_46_output_array;   /* Array #43 */
AI_STATIC ai_array eltwise_47_output_array;   /* Array #44 */
AI_STATIC ai_array conv2d_48_output_array;   /* Array #45 */
AI_STATIC ai_array conv2d_49_output_array;   /* Array #46 */
AI_STATIC ai_array conv2d_50_output_array;   /* Array #47 */
AI_STATIC ai_array eltwise_51_output_array;   /* Array #48 */
AI_STATIC ai_array conv2d_52_output_array;   /* Array #49 */
AI_STATIC ai_array conv2d_54_output_array;   /* Array #50 */
AI_STATIC ai_array conv2d_55_output_array;   /* Array #51 */
AI_STATIC ai_array conv2d_56_output_array;   /* Array #52 */
AI_STATIC ai_array conv2d_57_output_array;   /* Array #53 */
AI_STATIC ai_array conv2d_58_output_array;   /* Array #54 */
AI_STATIC ai_array eltwise_59_output_array;   /* Array #55 */
AI_STATIC ai_array conv2d_60_output_array;   /* Array #56 */
AI_STATIC ai_array conv2d_61_output_array;   /* Array #57 */
AI_STATIC ai_array conv2d_62_output_array;   /* Array #58 */
AI_STATIC ai_array eltwise_63_output_array;   /* Array #59 */
AI_STATIC ai_array conv2d_64_output_array;   /* Array #60 */
AI_STATIC ai_array conv2d_65_output_array;   /* Array #61 */
AI_STATIC ai_array conv2d_66_output_array;   /* Array #62 */
AI_STATIC ai_array conv2d_67_output_array;   /* Array #63 */
AI_STATIC ai_array dense_69_output_array;   /* Array #64 */
AI_STATIC ai_array dense_70_output_array;   /* Array #65 */
AI_STATIC ai_array dense_70_fmt_output_array;   /* Array #66 */
AI_STATIC ai_array nl_71_output_array;   /* Array #67 */
AI_STATIC ai_array nl_71_fmt_output_array;   /* Array #68 */
AI_STATIC ai_array conv2d_2_weights_array;   /* Array #69 */
AI_STATIC ai_array conv2d_2_bias_array;   /* Array #70 */
AI_STATIC ai_array conv2d_3_weights_array;   /* Array #71 */
AI_STATIC ai_array conv2d_3_bias_array;   /* Array #72 */
AI_STATIC ai_array conv2d_4_weights_array;   /* Array #73 */
AI_STATIC ai_array conv2d_4_bias_array;   /* Array #74 */
AI_STATIC ai_array conv2d_5_weights_array;   /* Array #75 */
AI_STATIC ai_array conv2d_5_bias_array;   /* Array #76 */
AI_STATIC ai_array conv2d_7_weights_array;   /* Array #77 */
AI_STATIC ai_array conv2d_7_bias_array;   /* Array #78 */
AI_STATIC ai_array conv2d_8_weights_array;   /* Array #79 */
AI_STATIC ai_array conv2d_8_bias_array;   /* Array #80 */
AI_STATIC ai_array conv2d_9_weights_array;   /* Array #81 */
AI_STATIC ai_array conv2d_9_bias_array;   /* Array #82 */
AI_STATIC ai_array conv2d_10_weights_array;   /* Array #83 */
AI_STATIC ai_array conv2d_10_bias_array;   /* Array #84 */
AI_STATIC ai_array conv2d_11_weights_array;   /* Array #85 */
AI_STATIC ai_array conv2d_11_bias_array;   /* Array #86 */
AI_STATIC ai_array conv2d_13_weights_array;   /* Array #87 */
AI_STATIC ai_array conv2d_13_bias_array;   /* Array #88 */
AI_STATIC ai_array conv2d_15_weights_array;   /* Array #89 */
AI_STATIC ai_array conv2d_15_bias_array;   /* Array #90 */
AI_STATIC ai_array conv2d_16_weights_array;   /* Array #91 */
AI_STATIC ai_array conv2d_16_bias_array;   /* Array #92 */
AI_STATIC ai_array conv2d_17_weights_array;   /* Array #93 */
AI_STATIC ai_array conv2d_17_bias_array;   /* Array #94 */
AI_STATIC ai_array conv2d_18_weights_array;   /* Array #95 */
AI_STATIC ai_array conv2d_18_bias_array;   /* Array #96 */
AI_STATIC ai_array conv2d_19_weights_array;   /* Array #97 */
AI_STATIC ai_array conv2d_19_bias_array;   /* Array #98 */
AI_STATIC ai_array conv2d_21_weights_array;   /* Array #99 */
AI_STATIC ai_array conv2d_21_bias_array;   /* Array #100 */
AI_STATIC ai_array conv2d_22_weights_array;   /* Array #101 */
AI_STATIC ai_array conv2d_22_bias_array;   /* Array #102 */
AI_STATIC ai_array conv2d_23_weights_array;   /* Array #103 */
AI_STATIC ai_array conv2d_23_bias_array;   /* Array #104 */
AI_STATIC ai_array conv2d_25_weights_array;   /* Array #105 */
AI_STATIC ai_array conv2d_25_bias_array;   /* Array #106 */
AI_STATIC ai_array conv2d_27_weights_array;   /* Array #107 */
AI_STATIC ai_array conv2d_27_bias_array;   /* Array #108 */
AI_STATIC ai_array conv2d_28_weights_array;   /* Array #109 */
AI_STATIC ai_array conv2d_28_bias_array;   /* Array #110 */
AI_STATIC ai_array conv2d_29_weights_array;   /* Array #111 */
AI_STATIC ai_array conv2d_29_bias_array;   /* Array #112 */
AI_STATIC ai_array conv2d_30_weights_array;   /* Array #113 */
AI_STATIC ai_array conv2d_30_bias_array;   /* Array #114 */
AI_STATIC ai_array conv2d_31_weights_array;   /* Array #115 */
AI_STATIC ai_array conv2d_31_bias_array;   /* Array #116 */
AI_STATIC ai_array conv2d_33_weights_array;   /* Array #117 */
AI_STATIC ai_array conv2d_33_bias_array;   /* Array #118 */
AI_STATIC ai_array conv2d_34_weights_array;   /* Array #119 */
AI_STATIC ai_array conv2d_34_bias_array;   /* Array #120 */
AI_STATIC ai_array conv2d_35_weights_array;   /* Array #121 */
AI_STATIC ai_array conv2d_35_bias_array;   /* Array #122 */
AI_STATIC ai_array conv2d_37_weights_array;   /* Array #123 */
AI_STATIC ai_array conv2d_37_bias_array;   /* Array #124 */
AI_STATIC ai_array conv2d_38_weights_array;   /* Array #125 */
AI_STATIC ai_array conv2d_38_bias_array;   /* Array #126 */
AI_STATIC ai_array conv2d_39_weights_array;   /* Array #127 */
AI_STATIC ai_array conv2d_39_bias_array;   /* Array #128 */
AI_STATIC ai_array conv2d_41_weights_array;   /* Array #129 */
AI_STATIC ai_array conv2d_41_bias_array;   /* Array #130 */
AI_STATIC ai_array conv2d_42_weights_array;   /* Array #131 */
AI_STATIC ai_array conv2d_42_bias_array;   /* Array #132 */
AI_STATIC ai_array conv2d_43_weights_array;   /* Array #133 */
AI_STATIC ai_array conv2d_43_bias_array;   /* Array #134 */
AI_STATIC ai_array conv2d_44_weights_array;   /* Array #135 */
AI_STATIC ai_array conv2d_44_bias_array;   /* Array #136 */
AI_STATIC ai_array conv2d_45_weights_array;   /* Array #137 */
AI_STATIC ai_array conv2d_45_bias_array;   /* Array #138 */
AI_STATIC ai_array conv2d_46_weights_array;   /* Array #139 */
AI_STATIC ai_array conv2d_46_bias_array;   /* Array #140 */
AI_STATIC ai_array conv2d_48_weights_array;   /* Array #141 */
AI_STATIC ai_array conv2d_48_bias_array;   /* Array #142 */
AI_STATIC ai_array conv2d_49_weights_array;   /* Array #143 */
AI_STATIC ai_array conv2d_49_bias_array;   /* Array #144 */
AI_STATIC ai_array conv2d_50_weights_array;   /* Array #145 */
AI_STATIC ai_array conv2d_50_bias_array;   /* Array #146 */
AI_STATIC ai_array conv2d_52_weights_array;   /* Array #147 */
AI_STATIC ai_array conv2d_52_bias_array;   /* Array #148 */
AI_STATIC ai_array conv2d_54_weights_array;   /* Array #149 */
AI_STATIC ai_array conv2d_54_bias_array;   /* Array #150 */
AI_STATIC ai_array conv2d_55_weights_array;   /* Array #151 */
AI_STATIC ai_array conv2d_55_bias_array;   /* Array #152 */
AI_STATIC ai_array conv2d_56_weights_array;   /* Array #153 */
AI_STATIC ai_array conv2d_56_bias_array;   /* Array #154 */
AI_STATIC ai_array conv2d_57_weights_array;   /* Array #155 */
AI_STATIC ai_array conv2d_57_bias_array;   /* Array #156 */
AI_STATIC ai_array conv2d_58_weights_array;   /* Array #157 */
AI_STATIC ai_array conv2d_58_bias_array;   /* Array #158 */
AI_STATIC ai_array conv2d_60_weights_array;   /* Array #159 */
AI_STATIC ai_array conv2d_60_bias_array;   /* Array #160 */
AI_STATIC ai_array conv2d_61_weights_array;   /* Array #161 */
AI_STATIC ai_array conv2d_61_bias_array;   /* Array #162 */
AI_STATIC ai_array conv2d_62_weights_array;   /* Array #163 */
AI_STATIC ai_array conv2d_62_bias_array;   /* Array #164 */
AI_STATIC ai_array conv2d_64_weights_array;   /* Array #165 */
AI_STATIC ai_array conv2d_64_bias_array;   /* Array #166 */
AI_STATIC ai_array conv2d_65_weights_array;   /* Array #167 */
AI_STATIC ai_array conv2d_65_bias_array;   /* Array #168 */
AI_STATIC ai_array conv2d_66_weights_array;   /* Array #169 */
AI_STATIC ai_array conv2d_66_bias_array;   /* Array #170 */
AI_STATIC ai_array conv2d_67_weights_array;   /* Array #171 */
AI_STATIC ai_array conv2d_67_bias_array;   /* Array #172 */
AI_STATIC ai_array dense_69_weights_array;   /* Array #173 */
AI_STATIC ai_array dense_69_bias_array;   /* Array #174 */
AI_STATIC ai_array dense_70_weights_array;   /* Array #175 */
AI_STATIC ai_array dense_70_bias_array;   /* Array #176 */
AI_STATIC ai_array conv2d_2_scratch0_array;   /* Array #177 */
AI_STATIC ai_array conv2d_2_scratch1_array;   /* Array #178 */
AI_STATIC ai_array conv2d_3_scratch0_array;   /* Array #179 */
AI_STATIC ai_array conv2d_3_scratch1_array;   /* Array #180 */
AI_STATIC ai_array conv2d_4_scratch0_array;   /* Array #181 */
AI_STATIC ai_array conv2d_5_scratch0_array;   /* Array #182 */
AI_STATIC ai_array conv2d_5_scratch1_array;   /* Array #183 */
AI_STATIC ai_array conv2d_7_scratch0_array;   /* Array #184 */
AI_STATIC ai_array conv2d_7_scratch1_array;   /* Array #185 */
AI_STATIC ai_array conv2d_8_scratch0_array;   /* Array #186 */
AI_STATIC ai_array conv2d_9_scratch0_array;   /* Array #187 */
AI_STATIC ai_array conv2d_9_scratch1_array;   /* Array #188 */
AI_STATIC ai_array conv2d_10_scratch0_array;   /* Array #189 */
AI_STATIC ai_array conv2d_10_scratch1_array;   /* Array #190 */
AI_STATIC ai_array conv2d_11_scratch0_array;   /* Array #191 */
AI_STATIC ai_array conv2d_13_scratch0_array;   /* Array #192 */
AI_STATIC ai_array conv2d_13_scratch1_array;   /* Array #193 */
AI_STATIC ai_array conv2d_15_scratch0_array;   /* Array #194 */
AI_STATIC ai_array conv2d_15_scratch1_array;   /* Array #195 */
AI_STATIC ai_array conv2d_16_scratch0_array;   /* Array #196 */
AI_STATIC ai_array conv2d_17_scratch0_array;   /* Array #197 */
AI_STATIC ai_array conv2d_17_scratch1_array;   /* Array #198 */
AI_STATIC ai_array conv2d_18_scratch0_array;   /* Array #199 */
AI_STATIC ai_array conv2d_18_scratch1_array;   /* Array #200 */
AI_STATIC ai_array conv2d_19_scratch0_array;   /* Array #201 */
AI_STATIC ai_array conv2d_21_scratch0_array;   /* Array #202 */
AI_STATIC ai_array conv2d_21_scratch1_array;   /* Array #203 */
AI_STATIC ai_array conv2d_22_scratch0_array;   /* Array #204 */
AI_STATIC ai_array conv2d_22_scratch1_array;   /* Array #205 */
AI_STATIC ai_array conv2d_23_scratch0_array;   /* Array #206 */
AI_STATIC ai_array conv2d_25_scratch0_array;   /* Array #207 */
AI_STATIC ai_array conv2d_25_scratch1_array;   /* Array #208 */
AI_STATIC ai_array conv2d_27_scratch0_array;   /* Array #209 */
AI_STATIC ai_array conv2d_27_scratch1_array;   /* Array #210 */
AI_STATIC ai_array conv2d_28_scratch0_array;   /* Array #211 */
AI_STATIC ai_array conv2d_29_scratch0_array;   /* Array #212 */
AI_STATIC ai_array conv2d_29_scratch1_array;   /* Array #213 */
AI_STATIC ai_array conv2d_30_scratch0_array;   /* Array #214 */
AI_STATIC ai_array conv2d_30_scratch1_array;   /* Array #215 */
AI_STATIC ai_array conv2d_31_scratch0_array;   /* Array #216 */
AI_STATIC ai_array conv2d_33_scratch0_array;   /* Array #217 */
AI_STATIC ai_array conv2d_33_scratch1_array;   /* Array #218 */
AI_STATIC ai_array conv2d_34_scratch0_array;   /* Array #219 */
AI_STATIC ai_array conv2d_34_scratch1_array;   /* Array #220 */
AI_STATIC ai_array conv2d_35_scratch0_array;   /* Array #221 */
AI_STATIC ai_array conv2d_37_scratch0_array;   /* Array #222 */
AI_STATIC ai_array conv2d_37_scratch1_array;   /* Array #223 */
AI_STATIC ai_array conv2d_38_scratch0_array;   /* Array #224 */
AI_STATIC ai_array conv2d_38_scratch1_array;   /* Array #225 */
AI_STATIC ai_array conv2d_39_scratch0_array;   /* Array #226 */
AI_STATIC ai_array conv2d_41_scratch0_array;   /* Array #227 */
AI_STATIC ai_array conv2d_41_scratch1_array;   /* Array #228 */
AI_STATIC ai_array conv2d_42_scratch0_array;   /* Array #229 */
AI_STATIC ai_array conv2d_42_scratch1_array;   /* Array #230 */
AI_STATIC ai_array conv2d_43_scratch0_array;   /* Array #231 */
AI_STATIC ai_array conv2d_44_scratch0_array;   /* Array #232 */
AI_STATIC ai_array conv2d_44_scratch1_array;   /* Array #233 */
AI_STATIC ai_array conv2d_45_scratch0_array;   /* Array #234 */
AI_STATIC ai_array conv2d_45_scratch1_array;   /* Array #235 */
AI_STATIC ai_array conv2d_46_scratch0_array;   /* Array #236 */
AI_STATIC ai_array conv2d_48_scratch0_array;   /* Array #237 */
AI_STATIC ai_array conv2d_48_scratch1_array;   /* Array #238 */
AI_STATIC ai_array conv2d_49_scratch0_array;   /* Array #239 */
AI_STATIC ai_array conv2d_49_scratch1_array;   /* Array #240 */
AI_STATIC ai_array conv2d_50_scratch0_array;   /* Array #241 */
AI_STATIC ai_array conv2d_52_scratch0_array;   /* Array #242 */
AI_STATIC ai_array conv2d_52_scratch1_array;   /* Array #243 */
AI_STATIC ai_array conv2d_54_scratch0_array;   /* Array #244 */
AI_STATIC ai_array conv2d_54_scratch1_array;   /* Array #245 */
AI_STATIC ai_array conv2d_55_scratch0_array;   /* Array #246 */
AI_STATIC ai_array conv2d_56_scratch0_array;   /* Array #247 */
AI_STATIC ai_array conv2d_56_scratch1_array;   /* Array #248 */
AI_STATIC ai_array conv2d_57_scratch0_array;   /* Array #249 */
AI_STATIC ai_array conv2d_57_scratch1_array;   /* Array #250 */
AI_STATIC ai_array conv2d_58_scratch0_array;   /* Array #251 */
AI_STATIC ai_array conv2d_60_scratch0_array;   /* Array #252 */
AI_STATIC ai_array conv2d_60_scratch1_array;   /* Array #253 */
AI_STATIC ai_array conv2d_61_scratch0_array;   /* Array #254 */
AI_STATIC ai_array conv2d_61_scratch1_array;   /* Array #255 */
AI_STATIC ai_array conv2d_62_scratch0_array;   /* Array #256 */
AI_STATIC ai_array conv2d_64_scratch0_array;   /* Array #257 */
AI_STATIC ai_array conv2d_64_scratch1_array;   /* Array #258 */
AI_STATIC ai_array conv2d_65_scratch0_array;   /* Array #259 */
AI_STATIC ai_array conv2d_65_scratch1_array;   /* Array #260 */
AI_STATIC ai_array conv2d_66_scratch0_array;   /* Array #261 */
AI_STATIC ai_array conv2d_67_scratch0_array;   /* Array #262 */
AI_STATIC ai_array conv2d_67_scratch1_array;   /* Array #263 */
AI_STATIC ai_array conv2d_67_scratch2_array;   /* Array #264 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor serving_default_sequential_17_input0_output;   /* Tensor #0 */
AI_STATIC ai_tensor conversion_0_output;   /* Tensor #1 */
AI_STATIC ai_tensor conv2d_2_output;   /* Tensor #2 */
AI_STATIC ai_tensor conv2d_3_output;   /* Tensor #3 */
AI_STATIC ai_tensor conv2d_4_output;   /* Tensor #4 */
AI_STATIC ai_tensor conv2d_5_output;   /* Tensor #5 */
AI_STATIC ai_tensor conv2d_7_output;   /* Tensor #6 */
AI_STATIC ai_tensor conv2d_8_output;   /* Tensor #7 */
AI_STATIC ai_tensor conv2d_9_output;   /* Tensor #8 */
AI_STATIC ai_tensor conv2d_10_output;   /* Tensor #9 */
AI_STATIC ai_tensor conv2d_11_output;   /* Tensor #10 */
AI_STATIC ai_tensor eltwise_12_output;   /* Tensor #11 */
AI_STATIC ai_tensor conv2d_13_output;   /* Tensor #12 */
AI_STATIC ai_tensor conv2d_15_output;   /* Tensor #13 */
AI_STATIC ai_tensor conv2d_16_output;   /* Tensor #14 */
AI_STATIC ai_tensor conv2d_17_output;   /* Tensor #15 */
AI_STATIC ai_tensor conv2d_18_output;   /* Tensor #16 */
AI_STATIC ai_tensor conv2d_19_output;   /* Tensor #17 */
AI_STATIC ai_tensor eltwise_20_output;   /* Tensor #18 */
AI_STATIC ai_tensor conv2d_21_output;   /* Tensor #19 */
AI_STATIC ai_tensor conv2d_22_output;   /* Tensor #20 */
AI_STATIC ai_tensor conv2d_23_output;   /* Tensor #21 */
AI_STATIC ai_tensor eltwise_24_output;   /* Tensor #22 */
AI_STATIC ai_tensor conv2d_25_output;   /* Tensor #23 */
AI_STATIC ai_tensor conv2d_27_output;   /* Tensor #24 */
AI_STATIC ai_tensor conv2d_28_output;   /* Tensor #25 */
AI_STATIC ai_tensor conv2d_29_output;   /* Tensor #26 */
AI_STATIC ai_tensor conv2d_30_output;   /* Tensor #27 */
AI_STATIC ai_tensor conv2d_31_output;   /* Tensor #28 */
AI_STATIC ai_tensor eltwise_32_output;   /* Tensor #29 */
AI_STATIC ai_tensor conv2d_33_output;   /* Tensor #30 */
AI_STATIC ai_tensor conv2d_34_output;   /* Tensor #31 */
AI_STATIC ai_tensor conv2d_35_output;   /* Tensor #32 */
AI_STATIC ai_tensor eltwise_36_output;   /* Tensor #33 */
AI_STATIC ai_tensor conv2d_37_output;   /* Tensor #34 */
AI_STATIC ai_tensor conv2d_38_output;   /* Tensor #35 */
AI_STATIC ai_tensor conv2d_39_output;   /* Tensor #36 */
AI_STATIC ai_tensor eltwise_40_output;   /* Tensor #37 */
AI_STATIC ai_tensor conv2d_41_output;   /* Tensor #38 */
AI_STATIC ai_tensor conv2d_42_output;   /* Tensor #39 */
AI_STATIC ai_tensor conv2d_43_output;   /* Tensor #40 */
AI_STATIC ai_tensor conv2d_44_output;   /* Tensor #41 */
AI_STATIC ai_tensor conv2d_45_output;   /* Tensor #42 */
AI_STATIC ai_tensor conv2d_46_output;   /* Tensor #43 */
AI_STATIC ai_tensor eltwise_47_output;   /* Tensor #44 */
AI_STATIC ai_tensor conv2d_48_output;   /* Tensor #45 */
AI_STATIC ai_tensor conv2d_49_output;   /* Tensor #46 */
AI_STATIC ai_tensor conv2d_50_output;   /* Tensor #47 */
AI_STATIC ai_tensor eltwise_51_output;   /* Tensor #48 */
AI_STATIC ai_tensor conv2d_52_output;   /* Tensor #49 */
AI_STATIC ai_tensor conv2d_54_output;   /* Tensor #50 */
AI_STATIC ai_tensor conv2d_55_output;   /* Tensor #51 */
AI_STATIC ai_tensor conv2d_56_output;   /* Tensor #52 */
AI_STATIC ai_tensor conv2d_57_output;   /* Tensor #53 */
AI_STATIC ai_tensor conv2d_58_output;   /* Tensor #54 */
AI_STATIC ai_tensor eltwise_59_output;   /* Tensor #55 */
AI_STATIC ai_tensor conv2d_60_output;   /* Tensor #56 */
AI_STATIC ai_tensor conv2d_61_output;   /* Tensor #57 */
AI_STATIC ai_tensor conv2d_62_output;   /* Tensor #58 */
AI_STATIC ai_tensor eltwise_63_output;   /* Tensor #59 */
AI_STATIC ai_tensor conv2d_64_output;   /* Tensor #60 */
AI_STATIC ai_tensor conv2d_65_output;   /* Tensor #61 */
AI_STATIC ai_tensor conv2d_66_output;   /* Tensor #62 */
AI_STATIC ai_tensor conv2d_67_output;   /* Tensor #63 */
AI_STATIC ai_tensor dense_69_output;   /* Tensor #64 */
AI_STATIC ai_tensor dense_70_output;   /* Tensor #65 */
AI_STATIC ai_tensor dense_70_fmt_output;   /* Tensor #66 */
AI_STATIC ai_tensor nl_71_output;   /* Tensor #67 */
AI_STATIC ai_tensor nl_71_fmt_output;   /* Tensor #68 */
AI_STATIC ai_tensor conv2d_2_weights;   /* Tensor #69 */
AI_STATIC ai_tensor conv2d_2_bias;   /* Tensor #70 */
AI_STATIC ai_tensor conv2d_3_weights;   /* Tensor #71 */
AI_STATIC ai_tensor conv2d_3_bias;   /* Tensor #72 */
AI_STATIC ai_tensor conv2d_4_weights;   /* Tensor #73 */
AI_STATIC ai_tensor conv2d_4_bias;   /* Tensor #74 */
AI_STATIC ai_tensor conv2d_5_weights;   /* Tensor #75 */
AI_STATIC ai_tensor conv2d_5_bias;   /* Tensor #76 */
AI_STATIC ai_tensor conv2d_7_weights;   /* Tensor #77 */
AI_STATIC ai_tensor conv2d_7_bias;   /* Tensor #78 */
AI_STATIC ai_tensor conv2d_8_weights;   /* Tensor #79 */
AI_STATIC ai_tensor conv2d_8_bias;   /* Tensor #80 */
AI_STATIC ai_tensor conv2d_9_weights;   /* Tensor #81 */
AI_STATIC ai_tensor conv2d_9_bias;   /* Tensor #82 */
AI_STATIC ai_tensor conv2d_10_weights;   /* Tensor #83 */
AI_STATIC ai_tensor conv2d_10_bias;   /* Tensor #84 */
AI_STATIC ai_tensor conv2d_11_weights;   /* Tensor #85 */
AI_STATIC ai_tensor conv2d_11_bias;   /* Tensor #86 */
AI_STATIC ai_tensor conv2d_13_weights;   /* Tensor #87 */
AI_STATIC ai_tensor conv2d_13_bias;   /* Tensor #88 */
AI_STATIC ai_tensor conv2d_15_weights;   /* Tensor #89 */
AI_STATIC ai_tensor conv2d_15_bias;   /* Tensor #90 */
AI_STATIC ai_tensor conv2d_16_weights;   /* Tensor #91 */
AI_STATIC ai_tensor conv2d_16_bias;   /* Tensor #92 */
AI_STATIC ai_tensor conv2d_17_weights;   /* Tensor #93 */
AI_STATIC ai_tensor conv2d_17_bias;   /* Tensor #94 */
AI_STATIC ai_tensor conv2d_18_weights;   /* Tensor #95 */
AI_STATIC ai_tensor conv2d_18_bias;   /* Tensor #96 */
AI_STATIC ai_tensor conv2d_19_weights;   /* Tensor #97 */
AI_STATIC ai_tensor conv2d_19_bias;   /* Tensor #98 */
AI_STATIC ai_tensor conv2d_21_weights;   /* Tensor #99 */
AI_STATIC ai_tensor conv2d_21_bias;   /* Tensor #100 */
AI_STATIC ai_tensor conv2d_22_weights;   /* Tensor #101 */
AI_STATIC ai_tensor conv2d_22_bias;   /* Tensor #102 */
AI_STATIC ai_tensor conv2d_23_weights;   /* Tensor #103 */
AI_STATIC ai_tensor conv2d_23_bias;   /* Tensor #104 */
AI_STATIC ai_tensor conv2d_25_weights;   /* Tensor #105 */
AI_STATIC ai_tensor conv2d_25_bias;   /* Tensor #106 */
AI_STATIC ai_tensor conv2d_27_weights;   /* Tensor #107 */
AI_STATIC ai_tensor conv2d_27_bias;   /* Tensor #108 */
AI_STATIC ai_tensor conv2d_28_weights;   /* Tensor #109 */
AI_STATIC ai_tensor conv2d_28_bias;   /* Tensor #110 */
AI_STATIC ai_tensor conv2d_29_weights;   /* Tensor #111 */
AI_STATIC ai_tensor conv2d_29_bias;   /* Tensor #112 */
AI_STATIC ai_tensor conv2d_30_weights;   /* Tensor #113 */
AI_STATIC ai_tensor conv2d_30_bias;   /* Tensor #114 */
AI_STATIC ai_tensor conv2d_31_weights;   /* Tensor #115 */
AI_STATIC ai_tensor conv2d_31_bias;   /* Tensor #116 */
AI_STATIC ai_tensor conv2d_33_weights;   /* Tensor #117 */
AI_STATIC ai_tensor conv2d_33_bias;   /* Tensor #118 */
AI_STATIC ai_tensor conv2d_34_weights;   /* Tensor #119 */
AI_STATIC ai_tensor conv2d_34_bias;   /* Tensor #120 */
AI_STATIC ai_tensor conv2d_35_weights;   /* Tensor #121 */
AI_STATIC ai_tensor conv2d_35_bias;   /* Tensor #122 */
AI_STATIC ai_tensor conv2d_37_weights;   /* Tensor #123 */
AI_STATIC ai_tensor conv2d_37_bias;   /* Tensor #124 */
AI_STATIC ai_tensor conv2d_38_weights;   /* Tensor #125 */
AI_STATIC ai_tensor conv2d_38_bias;   /* Tensor #126 */
AI_STATIC ai_tensor conv2d_39_weights;   /* Tensor #127 */
AI_STATIC ai_tensor conv2d_39_bias;   /* Tensor #128 */
AI_STATIC ai_tensor conv2d_41_weights;   /* Tensor #129 */
AI_STATIC ai_tensor conv2d_41_bias;   /* Tensor #130 */
AI_STATIC ai_tensor conv2d_42_weights;   /* Tensor #131 */
AI_STATIC ai_tensor conv2d_42_bias;   /* Tensor #132 */
AI_STATIC ai_tensor conv2d_43_weights;   /* Tensor #133 */
AI_STATIC ai_tensor conv2d_43_bias;   /* Tensor #134 */
AI_STATIC ai_tensor conv2d_44_weights;   /* Tensor #135 */
AI_STATIC ai_tensor conv2d_44_bias;   /* Tensor #136 */
AI_STATIC ai_tensor conv2d_45_weights;   /* Tensor #137 */
AI_STATIC ai_tensor conv2d_45_bias;   /* Tensor #138 */
AI_STATIC ai_tensor conv2d_46_weights;   /* Tensor #139 */
AI_STATIC ai_tensor conv2d_46_bias;   /* Tensor #140 */
AI_STATIC ai_tensor conv2d_48_weights;   /* Tensor #141 */
AI_STATIC ai_tensor conv2d_48_bias;   /* Tensor #142 */
AI_STATIC ai_tensor conv2d_49_weights;   /* Tensor #143 */
AI_STATIC ai_tensor conv2d_49_bias;   /* Tensor #144 */
AI_STATIC ai_tensor conv2d_50_weights;   /* Tensor #145 */
AI_STATIC ai_tensor conv2d_50_bias;   /* Tensor #146 */
AI_STATIC ai_tensor conv2d_52_weights;   /* Tensor #147 */
AI_STATIC ai_tensor conv2d_52_bias;   /* Tensor #148 */
AI_STATIC ai_tensor conv2d_54_weights;   /* Tensor #149 */
AI_STATIC ai_tensor conv2d_54_bias;   /* Tensor #150 */
AI_STATIC ai_tensor conv2d_55_weights;   /* Tensor #151 */
AI_STATIC ai_tensor conv2d_55_bias;   /* Tensor #152 */
AI_STATIC ai_tensor conv2d_56_weights;   /* Tensor #153 */
AI_STATIC ai_tensor conv2d_56_bias;   /* Tensor #154 */
AI_STATIC ai_tensor conv2d_57_weights;   /* Tensor #155 */
AI_STATIC ai_tensor conv2d_57_bias;   /* Tensor #156 */
AI_STATIC ai_tensor conv2d_58_weights;   /* Tensor #157 */
AI_STATIC ai_tensor conv2d_58_bias;   /* Tensor #158 */
AI_STATIC ai_tensor conv2d_60_weights;   /* Tensor #159 */
AI_STATIC ai_tensor conv2d_60_bias;   /* Tensor #160 */
AI_STATIC ai_tensor conv2d_61_weights;   /* Tensor #161 */
AI_STATIC ai_tensor conv2d_61_bias;   /* Tensor #162 */
AI_STATIC ai_tensor conv2d_62_weights;   /* Tensor #163 */
AI_STATIC ai_tensor conv2d_62_bias;   /* Tensor #164 */
AI_STATIC ai_tensor conv2d_64_weights;   /* Tensor #165 */
AI_STATIC ai_tensor conv2d_64_bias;   /* Tensor #166 */
AI_STATIC ai_tensor conv2d_65_weights;   /* Tensor #167 */
AI_STATIC ai_tensor conv2d_65_bias;   /* Tensor #168 */
AI_STATIC ai_tensor conv2d_66_weights;   /* Tensor #169 */
AI_STATIC ai_tensor conv2d_66_bias;   /* Tensor #170 */
AI_STATIC ai_tensor conv2d_67_weights;   /* Tensor #171 */
AI_STATIC ai_tensor conv2d_67_bias;   /* Tensor #172 */
AI_STATIC ai_tensor dense_69_weights;   /* Tensor #173 */
AI_STATIC ai_tensor dense_69_bias;   /* Tensor #174 */
AI_STATIC ai_tensor dense_70_weights;   /* Tensor #175 */
AI_STATIC ai_tensor dense_70_bias;   /* Tensor #176 */
AI_STATIC ai_tensor conv2d_2_scratch0;   /* Tensor #177 */
AI_STATIC ai_tensor conv2d_2_scratch1;   /* Tensor #178 */
AI_STATIC ai_tensor conv2d_3_scratch0;   /* Tensor #179 */
AI_STATIC ai_tensor conv2d_3_scratch1;   /* Tensor #180 */
AI_STATIC ai_tensor conv2d_4_scratch0;   /* Tensor #181 */
AI_STATIC ai_tensor conv2d_5_scratch0;   /* Tensor #182 */
AI_STATIC ai_tensor conv2d_5_scratch1;   /* Tensor #183 */
AI_STATIC ai_tensor conv2d_7_scratch0;   /* Tensor #184 */
AI_STATIC ai_tensor conv2d_7_scratch1;   /* Tensor #185 */
AI_STATIC ai_tensor conv2d_8_scratch0;   /* Tensor #186 */
AI_STATIC ai_tensor conv2d_9_scratch0;   /* Tensor #187 */
AI_STATIC ai_tensor conv2d_9_scratch1;   /* Tensor #188 */
AI_STATIC ai_tensor conv2d_10_scratch0;   /* Tensor #189 */
AI_STATIC ai_tensor conv2d_10_scratch1;   /* Tensor #190 */
AI_STATIC ai_tensor conv2d_11_scratch0;   /* Tensor #191 */
AI_STATIC ai_tensor conv2d_13_scratch0;   /* Tensor #192 */
AI_STATIC ai_tensor conv2d_13_scratch1;   /* Tensor #193 */
AI_STATIC ai_tensor conv2d_15_scratch0;   /* Tensor #194 */
AI_STATIC ai_tensor conv2d_15_scratch1;   /* Tensor #195 */
AI_STATIC ai_tensor conv2d_16_scratch0;   /* Tensor #196 */
AI_STATIC ai_tensor conv2d_17_scratch0;   /* Tensor #197 */
AI_STATIC ai_tensor conv2d_17_scratch1;   /* Tensor #198 */
AI_STATIC ai_tensor conv2d_18_scratch0;   /* Tensor #199 */
AI_STATIC ai_tensor conv2d_18_scratch1;   /* Tensor #200 */
AI_STATIC ai_tensor conv2d_19_scratch0;   /* Tensor #201 */
AI_STATIC ai_tensor conv2d_21_scratch0;   /* Tensor #202 */
AI_STATIC ai_tensor conv2d_21_scratch1;   /* Tensor #203 */
AI_STATIC ai_tensor conv2d_22_scratch0;   /* Tensor #204 */
AI_STATIC ai_tensor conv2d_22_scratch1;   /* Tensor #205 */
AI_STATIC ai_tensor conv2d_23_scratch0;   /* Tensor #206 */
AI_STATIC ai_tensor conv2d_25_scratch0;   /* Tensor #207 */
AI_STATIC ai_tensor conv2d_25_scratch1;   /* Tensor #208 */
AI_STATIC ai_tensor conv2d_27_scratch0;   /* Tensor #209 */
AI_STATIC ai_tensor conv2d_27_scratch1;   /* Tensor #210 */
AI_STATIC ai_tensor conv2d_28_scratch0;   /* Tensor #211 */
AI_STATIC ai_tensor conv2d_29_scratch0;   /* Tensor #212 */
AI_STATIC ai_tensor conv2d_29_scratch1;   /* Tensor #213 */
AI_STATIC ai_tensor conv2d_30_scratch0;   /* Tensor #214 */
AI_STATIC ai_tensor conv2d_30_scratch1;   /* Tensor #215 */
AI_STATIC ai_tensor conv2d_31_scratch0;   /* Tensor #216 */
AI_STATIC ai_tensor conv2d_33_scratch0;   /* Tensor #217 */
AI_STATIC ai_tensor conv2d_33_scratch1;   /* Tensor #218 */
AI_STATIC ai_tensor conv2d_34_scratch0;   /* Tensor #219 */
AI_STATIC ai_tensor conv2d_34_scratch1;   /* Tensor #220 */
AI_STATIC ai_tensor conv2d_35_scratch0;   /* Tensor #221 */
AI_STATIC ai_tensor conv2d_37_scratch0;   /* Tensor #222 */
AI_STATIC ai_tensor conv2d_37_scratch1;   /* Tensor #223 */
AI_STATIC ai_tensor conv2d_38_scratch0;   /* Tensor #224 */
AI_STATIC ai_tensor conv2d_38_scratch1;   /* Tensor #225 */
AI_STATIC ai_tensor conv2d_39_scratch0;   /* Tensor #226 */
AI_STATIC ai_tensor conv2d_41_scratch0;   /* Tensor #227 */
AI_STATIC ai_tensor conv2d_41_scratch1;   /* Tensor #228 */
AI_STATIC ai_tensor conv2d_42_scratch0;   /* Tensor #229 */
AI_STATIC ai_tensor conv2d_42_scratch1;   /* Tensor #230 */
AI_STATIC ai_tensor conv2d_43_scratch0;   /* Tensor #231 */
AI_STATIC ai_tensor conv2d_44_scratch0;   /* Tensor #232 */
AI_STATIC ai_tensor conv2d_44_scratch1;   /* Tensor #233 */
AI_STATIC ai_tensor conv2d_45_scratch0;   /* Tensor #234 */
AI_STATIC ai_tensor conv2d_45_scratch1;   /* Tensor #235 */
AI_STATIC ai_tensor conv2d_46_scratch0;   /* Tensor #236 */
AI_STATIC ai_tensor conv2d_48_scratch0;   /* Tensor #237 */
AI_STATIC ai_tensor conv2d_48_scratch1;   /* Tensor #238 */
AI_STATIC ai_tensor conv2d_49_scratch0;   /* Tensor #239 */
AI_STATIC ai_tensor conv2d_49_scratch1;   /* Tensor #240 */
AI_STATIC ai_tensor conv2d_50_scratch0;   /* Tensor #241 */
AI_STATIC ai_tensor conv2d_52_scratch0;   /* Tensor #242 */
AI_STATIC ai_tensor conv2d_52_scratch1;   /* Tensor #243 */
AI_STATIC ai_tensor conv2d_54_scratch0;   /* Tensor #244 */
AI_STATIC ai_tensor conv2d_54_scratch1;   /* Tensor #245 */
AI_STATIC ai_tensor conv2d_55_scratch0;   /* Tensor #246 */
AI_STATIC ai_tensor conv2d_56_scratch0;   /* Tensor #247 */
AI_STATIC ai_tensor conv2d_56_scratch1;   /* Tensor #248 */
AI_STATIC ai_tensor conv2d_57_scratch0;   /* Tensor #249 */
AI_STATIC ai_tensor conv2d_57_scratch1;   /* Tensor #250 */
AI_STATIC ai_tensor conv2d_58_scratch0;   /* Tensor #251 */
AI_STATIC ai_tensor conv2d_60_scratch0;   /* Tensor #252 */
AI_STATIC ai_tensor conv2d_60_scratch1;   /* Tensor #253 */
AI_STATIC ai_tensor conv2d_61_scratch0;   /* Tensor #254 */
AI_STATIC ai_tensor conv2d_61_scratch1;   /* Tensor #255 */
AI_STATIC ai_tensor conv2d_62_scratch0;   /* Tensor #256 */
AI_STATIC ai_tensor conv2d_64_scratch0;   /* Tensor #257 */
AI_STATIC ai_tensor conv2d_64_scratch1;   /* Tensor #258 */
AI_STATIC ai_tensor conv2d_65_scratch0;   /* Tensor #259 */
AI_STATIC ai_tensor conv2d_65_scratch1;   /* Tensor #260 */
AI_STATIC ai_tensor conv2d_66_scratch0;   /* Tensor #261 */
AI_STATIC ai_tensor conv2d_67_scratch0;   /* Tensor #262 */
AI_STATIC ai_tensor conv2d_67_scratch1;   /* Tensor #263 */
AI_STATIC ai_tensor conv2d_67_scratch2;   /* Tensor #264 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conversion_0_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv2d_2_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain conv2d_3_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain conv2d_4_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain conv2d_5_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain conv2d_7_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain conv2d_8_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain conv2d_9_chain;   /* Chain #7 */
AI_STATIC_CONST ai_tensor_chain conv2d_10_chain;   /* Chain #8 */
AI_STATIC_CONST ai_tensor_chain conv2d_11_chain;   /* Chain #9 */
AI_STATIC_CONST ai_tensor_chain eltwise_12_chain;   /* Chain #10 */
AI_STATIC_CONST ai_tensor_chain conv2d_13_chain;   /* Chain #11 */
AI_STATIC_CONST ai_tensor_chain conv2d_15_chain;   /* Chain #12 */
AI_STATIC_CONST ai_tensor_chain conv2d_16_chain;   /* Chain #13 */
AI_STATIC_CONST ai_tensor_chain conv2d_17_chain;   /* Chain #14 */
AI_STATIC_CONST ai_tensor_chain conv2d_18_chain;   /* Chain #15 */
AI_STATIC_CONST ai_tensor_chain conv2d_19_chain;   /* Chain #16 */
AI_STATIC_CONST ai_tensor_chain eltwise_20_chain;   /* Chain #17 */
AI_STATIC_CONST ai_tensor_chain conv2d_21_chain;   /* Chain #18 */
AI_STATIC_CONST ai_tensor_chain conv2d_22_chain;   /* Chain #19 */
AI_STATIC_CONST ai_tensor_chain conv2d_23_chain;   /* Chain #20 */
AI_STATIC_CONST ai_tensor_chain eltwise_24_chain;   /* Chain #21 */
AI_STATIC_CONST ai_tensor_chain conv2d_25_chain;   /* Chain #22 */
AI_STATIC_CONST ai_tensor_chain conv2d_27_chain;   /* Chain #23 */
AI_STATIC_CONST ai_tensor_chain conv2d_28_chain;   /* Chain #24 */
AI_STATIC_CONST ai_tensor_chain conv2d_29_chain;   /* Chain #25 */
AI_STATIC_CONST ai_tensor_chain conv2d_30_chain;   /* Chain #26 */
AI_STATIC_CONST ai_tensor_chain conv2d_31_chain;   /* Chain #27 */
AI_STATIC_CONST ai_tensor_chain eltwise_32_chain;   /* Chain #28 */
AI_STATIC_CONST ai_tensor_chain conv2d_33_chain;   /* Chain #29 */
AI_STATIC_CONST ai_tensor_chain conv2d_34_chain;   /* Chain #30 */
AI_STATIC_CONST ai_tensor_chain conv2d_35_chain;   /* Chain #31 */
AI_STATIC_CONST ai_tensor_chain eltwise_36_chain;   /* Chain #32 */
AI_STATIC_CONST ai_tensor_chain conv2d_37_chain;   /* Chain #33 */
AI_STATIC_CONST ai_tensor_chain conv2d_38_chain;   /* Chain #34 */
AI_STATIC_CONST ai_tensor_chain conv2d_39_chain;   /* Chain #35 */
AI_STATIC_CONST ai_tensor_chain eltwise_40_chain;   /* Chain #36 */
AI_STATIC_CONST ai_tensor_chain conv2d_41_chain;   /* Chain #37 */
AI_STATIC_CONST ai_tensor_chain conv2d_42_chain;   /* Chain #38 */
AI_STATIC_CONST ai_tensor_chain conv2d_43_chain;   /* Chain #39 */
AI_STATIC_CONST ai_tensor_chain conv2d_44_chain;   /* Chain #40 */
AI_STATIC_CONST ai_tensor_chain conv2d_45_chain;   /* Chain #41 */
AI_STATIC_CONST ai_tensor_chain conv2d_46_chain;   /* Chain #42 */
AI_STATIC_CONST ai_tensor_chain eltwise_47_chain;   /* Chain #43 */
AI_STATIC_CONST ai_tensor_chain conv2d_48_chain;   /* Chain #44 */
AI_STATIC_CONST ai_tensor_chain conv2d_49_chain;   /* Chain #45 */
AI_STATIC_CONST ai_tensor_chain conv2d_50_chain;   /* Chain #46 */
AI_STATIC_CONST ai_tensor_chain eltwise_51_chain;   /* Chain #47 */
AI_STATIC_CONST ai_tensor_chain conv2d_52_chain;   /* Chain #48 */
AI_STATIC_CONST ai_tensor_chain conv2d_54_chain;   /* Chain #49 */
AI_STATIC_CONST ai_tensor_chain conv2d_55_chain;   /* Chain #50 */
AI_STATIC_CONST ai_tensor_chain conv2d_56_chain;   /* Chain #51 */
AI_STATIC_CONST ai_tensor_chain conv2d_57_chain;   /* Chain #52 */
AI_STATIC_CONST ai_tensor_chain conv2d_58_chain;   /* Chain #53 */
AI_STATIC_CONST ai_tensor_chain eltwise_59_chain;   /* Chain #54 */
AI_STATIC_CONST ai_tensor_chain conv2d_60_chain;   /* Chain #55 */
AI_STATIC_CONST ai_tensor_chain conv2d_61_chain;   /* Chain #56 */
AI_STATIC_CONST ai_tensor_chain conv2d_62_chain;   /* Chain #57 */
AI_STATIC_CONST ai_tensor_chain eltwise_63_chain;   /* Chain #58 */
AI_STATIC_CONST ai_tensor_chain conv2d_64_chain;   /* Chain #59 */
AI_STATIC_CONST ai_tensor_chain conv2d_65_chain;   /* Chain #60 */
AI_STATIC_CONST ai_tensor_chain conv2d_66_chain;   /* Chain #61 */
AI_STATIC_CONST ai_tensor_chain conv2d_67_chain;   /* Chain #62 */
AI_STATIC_CONST ai_tensor_chain dense_69_chain;   /* Chain #63 */
AI_STATIC_CONST ai_tensor_chain dense_70_chain;   /* Chain #64 */
AI_STATIC_CONST ai_tensor_chain dense_70_fmt_chain;   /* Chain #65 */
AI_STATIC_CONST ai_tensor_chain nl_71_chain;   /* Chain #66 */
AI_STATIC_CONST ai_tensor_chain nl_71_fmt_chain;   /* Chain #67 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_nl conversion_0_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d conv2d_2_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d conv2d_3_layer; /* Layer #2 */
AI_STATIC ai_layer_conv2d conv2d_4_layer; /* Layer #3 */
AI_STATIC ai_layer_conv2d conv2d_5_layer; /* Layer #4 */
AI_STATIC ai_layer_conv2d conv2d_7_layer; /* Layer #5 */
AI_STATIC ai_layer_conv2d conv2d_8_layer; /* Layer #6 */
AI_STATIC ai_layer_conv2d conv2d_9_layer; /* Layer #7 */
AI_STATIC ai_layer_conv2d conv2d_10_layer; /* Layer #8 */
AI_STATIC ai_layer_conv2d conv2d_11_layer; /* Layer #9 */
AI_STATIC ai_layer_eltwise_integer eltwise_12_layer; /* Layer #10 */
AI_STATIC ai_layer_conv2d conv2d_13_layer; /* Layer #11 */
AI_STATIC ai_layer_conv2d conv2d_15_layer; /* Layer #12 */
AI_STATIC ai_layer_conv2d conv2d_16_layer; /* Layer #13 */
AI_STATIC ai_layer_conv2d conv2d_17_layer; /* Layer #14 */
AI_STATIC ai_layer_conv2d conv2d_18_layer; /* Layer #15 */
AI_STATIC ai_layer_conv2d conv2d_19_layer; /* Layer #16 */
AI_STATIC ai_layer_eltwise_integer eltwise_20_layer; /* Layer #17 */
AI_STATIC ai_layer_conv2d conv2d_21_layer; /* Layer #18 */
AI_STATIC ai_layer_conv2d conv2d_22_layer; /* Layer #19 */
AI_STATIC ai_layer_conv2d conv2d_23_layer; /* Layer #20 */
AI_STATIC ai_layer_eltwise_integer eltwise_24_layer; /* Layer #21 */
AI_STATIC ai_layer_conv2d conv2d_25_layer; /* Layer #22 */
AI_STATIC ai_layer_conv2d conv2d_27_layer; /* Layer #23 */
AI_STATIC ai_layer_conv2d conv2d_28_layer; /* Layer #24 */
AI_STATIC ai_layer_conv2d conv2d_29_layer; /* Layer #25 */
AI_STATIC ai_layer_conv2d conv2d_30_layer; /* Layer #26 */
AI_STATIC ai_layer_conv2d conv2d_31_layer; /* Layer #27 */
AI_STATIC ai_layer_eltwise_integer eltwise_32_layer; /* Layer #28 */
AI_STATIC ai_layer_conv2d conv2d_33_layer; /* Layer #29 */
AI_STATIC ai_layer_conv2d conv2d_34_layer; /* Layer #30 */
AI_STATIC ai_layer_conv2d conv2d_35_layer; /* Layer #31 */
AI_STATIC ai_layer_eltwise_integer eltwise_36_layer; /* Layer #32 */
AI_STATIC ai_layer_conv2d conv2d_37_layer; /* Layer #33 */
AI_STATIC ai_layer_conv2d conv2d_38_layer; /* Layer #34 */
AI_STATIC ai_layer_conv2d conv2d_39_layer; /* Layer #35 */
AI_STATIC ai_layer_eltwise_integer eltwise_40_layer; /* Layer #36 */
AI_STATIC ai_layer_conv2d conv2d_41_layer; /* Layer #37 */
AI_STATIC ai_layer_conv2d conv2d_42_layer; /* Layer #38 */
AI_STATIC ai_layer_conv2d conv2d_43_layer; /* Layer #39 */
AI_STATIC ai_layer_conv2d conv2d_44_layer; /* Layer #40 */
AI_STATIC ai_layer_conv2d conv2d_45_layer; /* Layer #41 */
AI_STATIC ai_layer_conv2d conv2d_46_layer; /* Layer #42 */
AI_STATIC ai_layer_eltwise_integer eltwise_47_layer; /* Layer #43 */
AI_STATIC ai_layer_conv2d conv2d_48_layer; /* Layer #44 */
AI_STATIC ai_layer_conv2d conv2d_49_layer; /* Layer #45 */
AI_STATIC ai_layer_conv2d conv2d_50_layer; /* Layer #46 */
AI_STATIC ai_layer_eltwise_integer eltwise_51_layer; /* Layer #47 */
AI_STATIC ai_layer_conv2d conv2d_52_layer; /* Layer #48 */
AI_STATIC ai_layer_conv2d conv2d_54_layer; /* Layer #49 */
AI_STATIC ai_layer_conv2d conv2d_55_layer; /* Layer #50 */
AI_STATIC ai_layer_conv2d conv2d_56_layer; /* Layer #51 */
AI_STATIC ai_layer_conv2d conv2d_57_layer; /* Layer #52 */
AI_STATIC ai_layer_conv2d conv2d_58_layer; /* Layer #53 */
AI_STATIC ai_layer_eltwise_integer eltwise_59_layer; /* Layer #54 */
AI_STATIC ai_layer_conv2d conv2d_60_layer; /* Layer #55 */
AI_STATIC ai_layer_conv2d conv2d_61_layer; /* Layer #56 */
AI_STATIC ai_layer_conv2d conv2d_62_layer; /* Layer #57 */
AI_STATIC ai_layer_eltwise_integer eltwise_63_layer; /* Layer #58 */
AI_STATIC ai_layer_conv2d conv2d_64_layer; /* Layer #59 */
AI_STATIC ai_layer_conv2d conv2d_65_layer; /* Layer #60 */
AI_STATIC ai_layer_conv2d conv2d_66_layer; /* Layer #61 */
AI_STATIC ai_layer_conv2d_nl_pool conv2d_67_layer; /* Layer #62 */
AI_STATIC ai_layer_dense dense_69_layer; /* Layer #63 */
AI_STATIC ai_layer_dense dense_70_layer; /* Layer #64 */
AI_STATIC ai_layer_nl dense_70_fmt_layer; /* Layer #65 */
AI_STATIC ai_layer_nl nl_71_layer; /* Layer #66 */
AI_STATIC ai_layer_nl nl_71_fmt_layer; /* Layer #67 */




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_sequential_17_input0_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 150528, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conversion_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 150528, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 200704, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 200704, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 100352, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 602112, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 150528, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25088, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 150528, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 150528, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25088, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_12_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25088, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 150528, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12544, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12544, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_20_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12544, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12544, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_24_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12544, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4704, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4704, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_32_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4704, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4704, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_36_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4704, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4704, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_40_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4704, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_47_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_50_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_51_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9408, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2744, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_58_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2744, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_59_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2744, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_62_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2744, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_63_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2744, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5488, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1280, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  dense_69_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 100, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  dense_70_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  dense_70_fmt_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 5, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  nl_71_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 5, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  nl_71_fmt_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 5, AI_STATIC)

/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 144, AI_STATIC)

/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 768, AI_STATIC)

/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#108 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#109 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#110 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#111 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#112 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#113 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#114 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#115 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#116 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#117 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#118 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#119 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#120 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#121 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#122 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#123 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#124 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#125 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#126 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#127 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#128 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#129 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#130 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#131 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#132 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#133 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#134 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#135 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#136 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#137 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1728, AI_STATIC)

/* Array#138 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#139 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#140 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#141 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#142 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#143 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1728, AI_STATIC)

/* Array#144 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#145 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_50_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#146 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_50_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#147 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#148 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#149 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1728, AI_STATIC)

/* Array#150 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#151 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10752, AI_STATIC)

/* Array#152 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 56, AI_STATIC)

/* Array#153 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#154 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#155 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3024, AI_STATIC)

/* Array#156 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#157 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_58_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#158 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_58_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 56, AI_STATIC)

/* Array#159 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#160 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#161 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3024, AI_STATIC)

/* Array#162 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#163 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_62_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#164 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_62_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 56, AI_STATIC)

/* Array#165 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#166 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#167 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3024, AI_STATIC)

/* Array#168 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#169 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#170 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 112, AI_STATIC)

/* Array#171 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 143360, AI_STATIC)

/* Array#172 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 1280, AI_STATIC)

/* Array#173 */
AI_ARRAY_OBJ_DECLARE(
  dense_69_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128000, AI_STATIC)

/* Array#174 */
AI_ARRAY_OBJ_DECLARE(
  dense_69_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 100, AI_STATIC)

/* Array#175 */
AI_ARRAY_OBJ_DECLARE(
  dense_70_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 500, AI_STATIC)

/* Array#176 */
AI_ARRAY_OBJ_DECLARE(
  dense_70_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 5, AI_STATIC)

/* Array#177 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1196, AI_STATIC)

/* Array#178 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 200704, AI_STATIC)

/* Array#179 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 593, AI_STATIC)

/* Array#180 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 200704, AI_STATIC)

/* Array#181 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 144, AI_STATIC)

/* Array#182 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#183 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 602112, AI_STATIC)

/* Array#184 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1777, AI_STATIC)

/* Array#185 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 150528, AI_STATIC)

/* Array#186 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 272, AI_STATIC)

/* Array#187 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#188 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 150528, AI_STATIC)

/* Array#189 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1777, AI_STATIC)

/* Array#190 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 150528, AI_STATIC)

/* Array#191 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 272, AI_STATIC)

/* Array#192 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#193 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 150528, AI_STATIC)

/* Array#194 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1777, AI_STATIC)

/* Array#195 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#196 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 352, AI_STATIC)

/* Array#197 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#198 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#199 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#200 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#201 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 544, AI_STATIC)

/* Array#202 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#203 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#204 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#205 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#206 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 544, AI_STATIC)

/* Array#207 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#208 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#209 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#210 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#211 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 624, AI_STATIC)

/* Array#212 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#213 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#214 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)

/* Array#215 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#216 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#217 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#218 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#219 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)

/* Array#220 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#221 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#222 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#223 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#224 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)

/* Array#225 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#226 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#227 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#228 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#229 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)

/* Array#230 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#231 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)

/* Array#232 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#233 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#234 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7105, AI_STATIC)

/* Array#235 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#236 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1088, AI_STATIC)

/* Array#237 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#238 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#239 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7105, AI_STATIC)

/* Array#240 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#241 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_50_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1088, AI_STATIC)

/* Array#242 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#243 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#244 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7105, AI_STATIC)

/* Array#245 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9408, AI_STATIC)

/* Array#246 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1328, AI_STATIC)

/* Array#247 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3584, AI_STATIC)

/* Array#248 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#249 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12433, AI_STATIC)

/* Array#250 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#251 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_58_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1904, AI_STATIC)

/* Array#252 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3584, AI_STATIC)

/* Array#253 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#254 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12433, AI_STATIC)

/* Array#255 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#256 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_62_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1904, AI_STATIC)

/* Array#257 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3584, AI_STATIC)

/* Array#258 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#259 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12433, AI_STATIC)

/* Array#260 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#261 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2464, AI_STATIC)

/* Array#262 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 13248, AI_STATIC)

/* Array#263 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 62720, AI_STATIC)

/* Array#264 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_scratch2_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 62720, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(serving_default_sequential_17_input0_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_UINTQ_ZP(127)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conversion_0_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.43816396594047546f),
    AI_PACK_INTQ_ZP(-8)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.356370210647583f),
    AI_PACK_INTQ_ZP(-5)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.4271792471408844f),
    AI_PACK_INTQ_ZP(-5)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_12_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.47960174083709717f),
    AI_PACK_INTQ_ZP(-6)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.281877726316452f),
    AI_PACK_INTQ_ZP(-7)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2541079521179199f),
    AI_PACK_INTQ_ZP(1)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_20_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.28946760296821594f),
    AI_PACK_INTQ_ZP(-11)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2755679190158844f),
    AI_PACK_INTQ_ZP(22)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_24_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.4069519340991974f),
    AI_PACK_INTQ_ZP(9)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.18087714910507202f),
    AI_PACK_INTQ_ZP(-5)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_31_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16772520542144775f),
    AI_PACK_INTQ_ZP(-9)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_32_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.19264152646064758f),
    AI_PACK_INTQ_ZP(-10)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_35_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.17344428598880768f),
    AI_PACK_INTQ_ZP(-28)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_36_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2131931334733963f),
    AI_PACK_INTQ_ZP(-9)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.14312642812728882f),
    AI_PACK_INTQ_ZP(-4)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_40_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.254630446434021f),
    AI_PACK_INTQ_ZP(-10)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_43_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16641511023044586f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_45_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_46_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.15064886212348938f),
    AI_PACK_INTQ_ZP(12)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_47_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.21086324751377106f),
    AI_PACK_INTQ_ZP(6)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_50_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.17488019168376923f),
    AI_PACK_INTQ_ZP(9)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_51_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.22028416395187378f),
    AI_PACK_INTQ_ZP(8)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_52_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #50 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_54_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #51 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_55_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.119657002389431f),
    AI_PACK_INTQ_ZP(-10)))

/* Int quant #52 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #53 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_57_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #54 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_58_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11739104986190796f),
    AI_PACK_INTQ_ZP(10)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_59_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.14773114025592804f),
    AI_PACK_INTQ_ZP(-9)))

/* Int quant #56 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_60_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #57 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_61_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #58 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_62_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1291906088590622f),
    AI_PACK_INTQ_ZP(11)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_63_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1753843128681183f),
    AI_PACK_INTQ_ZP(-2)))

/* Int quant #60 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #61 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_65_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #62 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_66_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12709729373455048f),
    AI_PACK_INTQ_ZP(9)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_67_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02193070575594902f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_69_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.041533421725034714f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_70_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11234140396118164f),
    AI_PACK_INTQ_ZP(-12)))

/* Int quant #66 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_71_fmt_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #67 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006357043515890837f, 0.01532160583883524f, 0.0066710710525512695f, 2.51141898388596e-07f, 0.006800525821745396f, 1.8187306238814926e-07f, 0.0034435198176652193f, 1.8307131810502142e-08f, 0.003978226333856583f, 0.015115456655621529f, 0.004665786400437355f, 1.8814594682226016e-07f, 0.010604714043438435f, 4.271763742735857e-08f, 0.00591351930052042f, 0.015915118157863617f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(4.985916893929243e-05f, 0.00012016946129733697f, 5.232212788541801e-05f, 1.9697405928553735e-09f, 5.333746230462566e-05f, 1.4264555092680098e-09f, 2.7007999960915186e-05f, 1.435853519415886e-10f, 3.1201776437228546e-05f, 0.00011855260527227074f, 3.65944069926627e-05f, 1.4756545985150638e-09f, 8.317422907566652e-05f, 3.3504030105824256e-10f, 4.6380544517887756e-05f, 0.00012482446618378162f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #69 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011045568622648716f, 0.005878211930394173f, 0.010417763143777847f, 0.17514191567897797f, 0.011570106260478497f, 0.16459958255290985f, 0.010207368060946465f, 0.006787153426557779f, 0.006147226318717003f, 0.006388559006154537f, 0.016864372417330742f, 0.2920999526977539f, 0.00905166007578373f, 0.12335662543773651f, 0.00825369730591774f, 0.0041795154102146626f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #70 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00025989575078710914f, 0.00013831087562721223f, 0.00024512383970431983f, 0.004120986443012953f, 0.0002722378121688962f, 0.003872931469231844f, 0.0002401733654551208f, 0.0001596977235749364f, 0.00014464062405750155f, 0.0001503190433140844f, 0.00039680878398939967f, 0.006872940342873335f, 0.00021298024512361735f, 0.00290250894613564f, 0.00019420465105213225f, 9.834153752308339e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #71 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05702180787920952f, 0.05349180847406387f, 0.0441674143075943f, 0.04513700306415558f, 0.07580569386482239f, 0.08323173969984055f, 0.07892855256795883f, 0.043226804584264755f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #72 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0013416896108537912f, 0.001258630771189928f, 0.0010392332915216684f, 0.0010620472021400928f, 0.0017836634069681168f, 0.001958393957465887f, 0.0018571424297988415f, 0.0010171013418585062f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #73 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012586666271090508f, 0.0012817652896046638f, 0.0010751852532848716f, 0.00045756148756481707f, 0.0008011476020328701f, 0.011962365359067917f, 0.0019281662534922361f, 0.0006156168528832495f, 0.0032777816522866488f, 0.0007591744652017951f, 0.000571438402403146f, 0.005666924640536308f, 0.0019215024076402187f, 0.008752254769206047f, 0.0006182172219268978f, 0.009968981146812439f, 0.0014177780831232667f, 0.0007319658761844039f, 0.0005927677848376334f, 0.0010337074054405093f, 0.0009172080317512155f, 0.001038186950609088f, 0.01270560547709465f, 0.007066644728183746f, 0.0009092944674193859f, 0.001657048356719315f, 0.0012901549926027656f, 0.0013737675035372376f, 0.0023969600442796946f, 0.000373286398826167f, 0.00852396059781313f, 0.0015631259884685278f, 0.0007974047330208123f, 0.0005579154239967465f, 0.0036649471148848534f, 0.0023517082445323467f, 0.0022366587072610855f, 0.0010011778213083744f, 0.0014174997340887785f, 0.0011027466971427202f, 0.010991305112838745f, 0.001947991899214685f, 0.00034554509329609573f, 0.0015640342608094215f, 0.0009620565688237548f, 0.008597319014370441f, 0.005953194573521614f, 0.010136542841792107f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #74 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005515023600310087f, 0.0005616233684122562f, 0.0004711074288934469f, 0.0002004869602387771f, 0.0003510340175125748f, 0.005241477396339178f, 0.0008448529988527298f, 0.00026974111096933484f, 0.0014362058136612177f, 0.00033264289959333837f, 0.0002503837167751044f, 0.0024830421898514032f, 0.0008419331279583275f, 0.0038349225651472807f, 0.0002708804968278855f, 0.004368048161268234f, 0.0006212192820385098f, 0.0003207210684195161f, 0.0002597294806037098f, 0.00045293333823792636f, 0.00040188751881942153f, 0.0004548961005639285f, 0.00556713854894042f, 0.003096349071711302f, 0.0003984200593549758f, 0.0007260589045472443f, 0.0005652994150295854f, 0.0006019354332238436f, 0.0010502615477889776f, 0.0001635606458876282f, 0.0037348924670368433f, 0.0006849055062048137f, 0.00034939401666633785f, 0.00024445843882858753f, 0.0016058477340266109f, 0.001030433806590736f, 0.0009800232946872711f, 0.00043868005741387606f, 0.0006210972787812352f, 0.0004831838596146554f, 0.004815993830561638f, 0.0008535398519597948f, 0.0001514054019935429f, 0.0006853034719824791f, 0.0004215385124552995f, 0.003767035435885191f, 0.002608475275337696f, 0.004441468045115471f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #75 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0006960022146813571f, 0.004673338029533625f, 0.005799286067485809f, 0.004585325717926025f, 0.005473228637129068f, 0.00115619704592973f, 0.004120686557143927f, 0.010039376094937325f, 0.0015685390681028366f, 0.00394756393507123f, 0.004072516690939665f, 0.002835886785760522f, 0.007163539528846741f, 0.0012513885740190744f, 0.0033775523770600557f, 0.0005161665030755103f, 0.001948601333424449f, 0.004133909475058317f, 0.007741581182926893f, 0.002655917312949896f, 0.005252061411738396f, 0.0036667142994701862f, 0.0005644146585837007f, 0.004182825330644846f, 0.004516607150435448f, 0.0049261474050581455f, 0.00824637059122324f, 0.004581396467983723f, 0.001819623401388526f, 0.007973470725119114f, 0.0004927467089146376f, 0.00237667141482234f, 0.004740976262837648f, 0.005115050356835127f, 0.0009502918110229075f, 0.001618427806533873f, 0.0015871014911681414f, 0.004581960383802652f, 0.009036457166075706f, 0.004105257801711559f, 0.0015166423982009292f, 0.002240625210106373f, 0.0039426228031516075f, 0.0020661959424614906f, 0.0040962062776088715f, 0.0009301933459937572f, 0.001022531883791089f, 0.000568293733522296f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #76 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.637652349018026e-05f, 0.00010996089986292645f, 0.0001364537893095985f, 0.00010789001680677757f, 0.000128781859530136f, 2.72046363534173e-05f, 9.695733024273068e-05f, 0.00023622061416972429f, 3.690680387080647e-05f, 9.288385626859963e-05f, 9.582392522133887e-05f, 6.672675226582214e-05f, 0.00016855387366376817f, 2.944443804153707e-05f, 7.947182166390121e-05f, 1.2145094842708204e-05f, 4.584944326779805e-05f, 9.726845746627077e-05f, 0.0001821548503357917f, 6.249217403819785e-05f, 0.00012357792002148926f, 8.627563511254266e-05f, 1.328034522884991e-05f, 9.841941937338561e-05f, 0.00010627310985000804f, 0.0001159093517344445f, 0.0001940322545124218f, 0.00010779756848933175f, 4.28146704507526e-05f, 0.00018761107639875263f, 1.1594040188356303e-05f, 5.592168236034922e-05f, 0.00011155238462379202f, 0.00012035412510158494f, 2.2359807189786807e-05f, 3.8080655940575525e-05f, 3.734356505447067e-05f, 0.00010781083256006241f, 0.00021262252994347364f, 9.659430361352861e-05f, 3.5685705370269716e-05f, 5.272059570415877e-05f, 9.276759374188259e-05f, 4.861637717112899e-05f, 9.638132905820385e-05f, 2.1886902686674148e-05f, 2.4059574570856057e-05f, 1.3371617569646332e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #77 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.037059299647808075f, 0.035651758313179016f, 0.029089994728565216f, 0.02369472198188305f, 0.04832088202238083f, 0.027682263404130936f, 0.03448175638914108f, 0.02806408703327179f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #78 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000871983531396836f, 0.0008388649439439178f, 0.0006844704621471465f, 0.0005575228715315461f, 0.0011369619751349092f, 0.0006513473927043378f, 0.0008113354560919106f, 0.000660331454128027f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #79 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001017079339362681f, 0.002131299115717411f, 0.0002862555265892297f, 0.0011835290351882577f, 0.0034716646187007427f, 0.0005405258270911872f, 0.0010831733234226704f, 0.0009075585403479636f, 0.0004938345518894494f, 0.0021115203853696585f, 0.003480556420981884f, 0.002455348614603281f, 0.0023201906587928534f, 0.004251317121088505f, 0.0022003273479640484f, 0.001236998476088047f, 0.000565946800634265f, 0.0007589730084873736f, 0.0002792213635984808f, 0.000594393233768642f, 0.0003193699521943927f, 0.0008273485582321882f, 0.001621830859221518f, 0.002082949737086892f, 0.0010379379382357001f, 0.0015886692563071847f, 0.0016789025394245982f, 0.001364257768727839f, 0.000891864241566509f, 0.0009115571738220751f, 0.0013238691026344895f, 0.0012424695305526257f, 0.0008924576104618609f, 0.0008691827533766627f, 0.0011589425848796964f, 0.0006054104887880385f, 0.001705998438410461f, 0.00033688341500237584f, 0.001857386203482747f, 0.0011845112312585115f, 0.0016652008052915335f, 0.002423427067697048f, 0.0007817459409125149f, 0.0006461389129981399f, 0.001919467467814684f, 0.0016958829946815968f, 0.002717105206102133f, 0.0016281020361930132f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #80 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000362456776201725f, 0.0007595315109938383f, 0.00010201294207945466f, 0.0004217744863126427f, 0.0012371978955343366f, 0.00019262729620095342f, 0.0003860107099171728f, 0.00032342682243324816f, 0.00017598792328499258f, 0.0007524829707108438f, 0.001240366604179144f, 0.0008750131237320602f, 0.0008268468081951141f, 0.0015150427352637053f, 0.0007841311162337661f, 0.0004408294043969363f, 0.00020168657647445798f, 0.0002704753715079278f, 9.950617823051289e-05f, 0.0002118240372510627f, 0.00011381393414922059f, 0.00029484237893484533f, 0.0005779722123406827f, 0.0007423012284561992f, 0.0003698901564348489f, 0.0005661543691530824f, 0.000598310842178762f, 0.00048618082655593753f, 0.0003178338520228863f, 0.0003248518332839012f, 0.0004717874980997294f, 0.0004427791282068938f, 0.0003180453204549849f, 0.0003097508451901376f, 0.00041301260353066027f, 0.0002157502603949979f, 0.0006079670274630189f, 0.00012005521421087906f, 0.0006619170890189707f, 0.00042212451808154583f, 0.0005934279761277139f, 0.0008636371931061149f, 0.00027859097463078797f, 0.00023026466078590602f, 0.0006840410060249269f, 0.0006043621688149869f, 0.000968295382335782f, 0.0005802070372737944f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #81 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.021313272416591644f, 0.006490278989076614f, 0.020576300099492073f, 0.007142683491110802f, 0.004226510412991047f, 0.02407088503241539f, 0.008956119418144226f, 0.005477204453200102f, 0.005267311353236437f, 0.007645723409950733f, 0.0015962873585522175f, 0.008162637241184711f, 0.002049105940386653f, 0.005241465289145708f, 0.004957308992743492f, 0.012294958345592022f, 0.01115544606000185f, 0.008056496270000935f, 0.016579287126660347f, 0.013341553509235382f, 0.008352316915988922f, 0.005031525623053312f, 0.006723926868289709f, 0.004011382348835468f, 0.005998631473630667f, 0.003378578694537282f, 0.004221027716994286f, 0.006701176054775715f, 0.0038175228983163834f, 0.012925872579216957f, 0.007007913198322058f, 0.0036032351199537516f, 0.008853822015225887f, 0.014881474897265434f, 0.0062971655279397964f, 0.0077528818510472775f, 0.006758439354598522f, 0.010019076056778431f, 0.0036080246791243553f, 0.004197163041681051f, 0.011049061082303524f, 0.006143603473901749f, 0.009119655005633831f, 0.009451356716454029f, 0.0047742086462676525f, 0.0049794199876487255f, 0.007149261888116598f, 0.0049676732160151005f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #82 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005014888010919094f, 0.00015271245501935482f, 0.0004841482441406697f, 0.00016806313942652196f, 9.944730845745653e-05f, 0.0005663737538270652f, 0.00021073222160339355f, 0.00012887539924122393f, 0.00012393674114719033f, 0.000179899376234971f, 3.7559704651357606e-05f, 0.00019206205615773797f, 4.821425682166591e-05f, 0.00012332860205788165f, 0.00011664256453514099f, 0.0002892931515816599f, 0.0002624811022542417f, 0.0001895646273624152f, 0.0003901008749380708f, 0.0003139189211651683f, 0.00019652511400636286f, 0.0001183888380182907f, 0.00015821005217731f, 9.43854684010148e-05f, 0.00014114427904132754f, 7.949597056722268e-05f, 9.931829845299944e-05f, 0.00015767473087180406f, 8.982406870927662e-05f, 0.00030413817148655653f, 0.00016489207337144762f, 8.478200470563024e-05f, 0.00020832523296121508f, 0.0003501523460727185f, 0.00014816860493738204f, 0.00018242075748275965f, 0.00015902210725471377f, 0.0002357429766561836f, 8.489470201311633e-05f, 9.875677642412484e-05f, 0.0002599779109004885f, 0.00014455537893809378f, 0.0002145801263395697f, 0.0002223848714493215f, 0.0001123343245126307f, 0.00011716282460838556f, 0.0001682179281488061f, 0.00011688643280649558f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #83 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03518914058804512f, 0.020869262516498566f, 0.019674159586429596f, 0.025971049442887306f, 0.021713411435484886f, 0.048166047781705856f, 0.060791462659835815f, 0.021404998376965523f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #84 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008279798203147948f, 0.0004910414572805166f, 0.0004629214236047119f, 0.0006110835238359869f, 0.0005109038320370018f, 0.0011333187576383352f, 0.0014303873758763075f, 0.000503647024743259f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #85 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0009675038163550198f, 0.0010547698475420475f, 0.0012560244649648666f, 0.0007732955273240805f, 0.0008332763100042939f, 0.0017882841639220715f, 0.0006547698867507279f, 0.000898958882316947f, 0.0007130282465368509f, 0.0011209365911781788f, 0.0005489272880367935f, 0.0007283931481651962f, 0.000654218252748251f, 0.0004280100401956588f, 0.00033523072488605976f, 0.0011892038164660335f, 0.0018630728591233492f, 0.0007714575622230768f, 0.0005209129303693771f, 0.00055219471687451f, 0.0005140864523127675f, 0.0007469253032468259f, 0.0008794002933427691f, 0.0011782123474404216f, 0.004436573013663292f, 0.00023296099971048534f, 0.0006771743064746261f, 0.0005812127492390573f, 0.0007766293128952384f, 0.0003676939522847533f, 0.0003406738687772304f, 0.0011129750637337565f, 0.0007032455177977681f, 0.001539119752123952f, 0.0006005014292895794f, 0.00038353345007635653f, 0.0012015877291560173f, 0.0008785350946709514f, 0.0009102326584979892f, 0.00043066134094260633f, 0.0019643986597657204f, 0.0006454393151216209f, 0.00046006511547602713f, 0.000385434104828164f, 0.00042754350579343736f, 0.0012780373217538f, 0.0005689083482138813f, 0.000866309623233974f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #86 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0004640165134333074f, 0.000505869451444596f, 0.0006023915484547615f, 0.00037087389500811696f, 0.0003996407613158226f, 0.0008576642139814794f, 0.00031402878812514246f, 0.0004311422526370734f, 0.0003419696004129946f, 0.0005376031622290611f, 0.00026326646911911666f, 0.0003493386320769787f, 0.0003137642052024603f, 0.00020527436572592705f, 0.00016077724285423756f, 0.0005703442147932947f, 0.0008935329969972372f, 0.0003699923981912434f, 0.00024983074399642646f, 0.00026483353576622903f, 0.0002465567667968571f, 0.00035822667996399105f, 0.0004217619134578854f, 0.0005650726961903274f, 0.0021277880296111107f, 0.00011172849917784333f, 0.00032477398053742945f, 0.0002787506382446736f, 0.00037247277214191854f, 0.00017634665709920228f, 0.00016338778368663043f, 0.0005337847978807986f, 0.0003372777719050646f, 0.0007381645264104009f, 0.00028800152358599007f, 0.00018394330982118845f, 0.0005762835498899221f, 0.0004213469510432333f, 0.0004365491622593254f, 0.00020654592663049698f, 0.0009421290014870465f, 0.00030955381225794554f, 0.00022064802760723978f, 0.0001848548708949238f, 0.00020505061547737569f, 0.0006129489047452807f, 0.00027284942916594446f, 0.00041548360604792833f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #87 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0036985899787396193f, 0.002424426842480898f, 0.002129692118614912f, 0.004592704586684704f, 0.0035368611570447683f, 0.005474434234201908f, 0.004075004253536463f, 0.0033992091193795204f, 0.003120408859103918f, 0.0022550097201019526f, 0.004713679198175669f, 0.003808042034506798f, 0.0039894236251711845f, 0.008738668635487556f, 0.00801039393991232f, 0.0021633461583405733f, 0.0011027025757357478f, 0.003908209037035704f, 0.004193196073174477f, 0.004183213226497173f, 0.004007310606539249f, 0.0042038350366055965f, 0.0029793153516948223f, 0.0038374383002519608f, 0.002890408504754305f, 0.01395254023373127f, 0.004817186389118433f, 0.006230649538338184f, 0.0035423024091869593f, 0.006067323498427868f, 0.009881108067929745f, 0.002256740815937519f, 0.0038873248267918825f, 0.005827582441270351f, 0.004237550776451826f, 0.008753021247684956f, 0.001348186400718987f, 0.003215428441762924f, 0.005108474753797054f, 0.004579445812851191f, 0.00292237033136189f, 0.006353194825351238f, 0.006933968048542738f, 0.008057999424636364f, 0.004049874376505613f, 0.0023936040233820677f, 0.004114137962460518f, 0.0030662901699543f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #88 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.70256480993703e-05f, 5.7045337598538026e-05f, 5.011040411773138e-05f, 0.00010806364298332483f, 8.322026405949146e-05f, 0.00012881022121291608f, 9.588245302438736e-05f, 7.998139335541055e-05f, 7.342138997046277e-05f, 5.3059055062476546e-05f, 0.00011091009946539998f, 8.960098784882575e-05f, 9.386879537487403e-05f, 0.0002056157391052693f, 0.0001884798548417166f, 5.0902264774776995e-05f, 2.594594297988806e-05f, 9.195785969495773e-05f, 9.866344043985009e-05f, 9.842855070019141e-05f, 9.428966586710885e-05f, 9.891376976156607e-05f, 7.0101537858136e-05f, 9.029266948346049e-05f, 6.800961273256689e-05f, 0.0003282950783614069f, 0.00011334556620568037f, 0.00014660351735074073f, 8.334829180967063e-05f, 0.00014276056026574224f, 0.00023249666264746338f, 5.3099785873200744e-05f, 9.146647062152624e-05f, 0.00013711958308704197f, 9.970708197215572e-05f, 0.00020595344540197402f, 3.172203287249431e-05f, 7.565713895019144e-05f, 0.00012019940913887694f, 0.00010775167174870148f, 6.876165571156889e-05f, 0.00014948693569749594f, 0.00016315218817908317f, 0.00018959998851642013f, 9.529116505291313e-05f, 5.632009560940787e-05f, 9.680324728833511e-05f, 7.214800280053169e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #89 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.030585957691073418f, 0.034607965499162674f, 0.0236478541046381f, 0.023167096078395844f, 0.030001888051629066f, 0.03777662292122841f, 0.0208623968064785f, 0.02253797836601734f, 0.02401794120669365f, 0.03276862949132919f, 0.02030215784907341f, 0.034247927367687225f, 0.022754158824682236f, 0.03173771873116493f, 0.02456587739288807f, 0.03313188627362251f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #90 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0007196696242317557f, 0.0008143050945363939f, 0.0005564201273955405f, 0.000545108166988939f, 0.0007059267954900861f, 0.0008888617157936096f, 0.0004908799310214818f, 0.0005303053767420352f, 0.0005651280516758561f, 0.0007710265927016735f, 0.000477697845781222f, 0.0008058336097747087f, 0.0005353919696062803f, 0.000746769888792187f, 0.0005780206411145627f, 0.0007795738056302071f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #91 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003089656587690115f, 0.0004838291206397116f, 0.00017781129281502217f, 0.0008234467823058367f, 0.0009271578164771199f, 0.00024155127175617963f, 0.0009230637224391103f, 0.0007802360923960805f, 0.0008994857780635357f, 0.0011913056951016188f, 0.0012332546757534146f, 0.0015985437203198671f, 0.00040996630559675395f, 0.0003840753633994609f, 0.0016305450117215514f, 0.0007052040891721845f, 0.0005121762515045702f, 0.001372852479107678f, 0.0009585618390701711f, 0.0009515102137811482f, 0.0013089260319247842f, 0.0005252670962363482f, 0.0006777062662877142f, 0.000759103917516768f, 0.001322482363320887f, 0.00048058925312943757f, 0.0011758157052099705f, 0.0010295279789716005f, 0.001975556369870901f, 0.0011102553689852357f, 0.0006304102716967463f, 0.0006291887839324772f, 0.0007712783990427852f, 0.0005547546898014843f, 0.002830969402566552f, 0.0002710439439397305f, 0.0008400806691497564f, 0.000380087731173262f, 0.0004178679082542658f, 0.0020765711087733507f, 0.000860546890180558f, 0.0010031063575297594f, 0.0013326340122148395f, 0.00258429697714746f, 0.0016894988948479295f, 0.000931442657019943f, 0.0021500515285879374f, 0.0021338851656764746f, 0.001121513661928475f, 0.0010835918365046382f, 0.0015117806615307927f, 0.0015634124865755439f, 0.002447651233524084f, 0.00046760126133449376f, 0.0003408569027669728f, 0.0020176435355097055f, 0.0008794533787295222f, 0.00034683311241678894f, 0.0007020310731604695f, 0.0010692768264561892f, 0.0008876799256540835f, 0.0008250043611042202f, 0.0011448680888861418f, 0.0004319169092923403f, 0.0019811303354799747f, 0.0010880859335884452f, 0.0010507915867492557f, 0.0007473832811228931f, 0.0010932398727163672f, 0.001393558457493782f, 0.0005537429242394865f, 0.0015284065157175064f, 0.0008589014760218561f, 0.0006303146947175264f, 0.0007258474943228066f, 0.0011488529853522778f, 0.0018996319267898798f, 0.0004256797838024795f, 0.0006226044497452676f, 0.0007919808267615736f, 0.0011536560487002134f, 0.0006415877724066377f, 0.0005240989266894758f, 0.0010029847035184503f, 0.0010121166706085205f, 0.001722774119116366f, 0.0010400769533589482f, 0.0026861855294555426f, 0.002136422088369727f, 0.002156727947294712f, 0.0019091010326519608f, 0.0006342538981698453f, 0.001081110443919897f, 0.0011590488720685244f, 0.001030815183185041f, 0.0019351255614310503f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #92 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008709053508937359f, 0.00013638065138366073f, 5.0121041567763314e-05f, 0.000232111313380301f, 0.00026134515064768493f, 6.808792386436835e-05f, 0.00026019109645858407f, 0.00021993117115925997f, 0.0002535450039431453f, 0.0003358025278430432f, 0.0003476270358078182f, 0.0004505938559304923f, 0.0001155603677034378f, 0.00010826229117810726f, 0.0004596143262460828f, 0.00019878133025486022f, 0.00014437107893172652f, 0.00038697654963470995f, 0.00027019722620025277f, 0.00026820952189154923f, 0.000368957087630406f, 0.00014806109538767487f, 0.0001910302962642163f, 0.0002139744901796803f, 0.0003727783332578838f, 0.0001354674022877589f, 0.0003314362547826022f, 0.00029020101646892726f, 0.0005568653577938676f, 0.0003129562537651509f, 0.00017769861733540893f, 0.00017735430446919054f, 0.0002174061955884099f, 0.0001563729892950505f, 0.0007979872170835733f, 7.640125113539398e-05f, 0.00023680002777837217f, 0.00010713826486608014f, 0.00011778765474446118f, 0.0005853391485288739f, 0.00024256900360342115f, 0.0002827533462550491f, 0.0003756398509722203f, 0.0007284557796083391f, 0.00047623211867175996f, 0.0002625529305078089f, 0.0006060516461730003f, 0.0006014946848154068f, 0.00031612973543815315f, 0.0003054403932765126f, 0.00042613729601725936f, 0.0004406911612022668f, 0.0006899383733980358f, 0.00013180637324694544f, 9.607996616978198e-05f, 0.0005687287775799632f, 0.00024789830786176026f, 9.77645322564058e-05f, 0.0001978869258891791f, 0.00030140532180666924f, 0.000250217184657231f, 0.00023255035921465605f, 0.0003227128181606531f, 0.00012174775474704802f, 0.0005584364989772439f, 0.00030670719570480287f, 0.0002961947466246784f, 0.00021067069610580802f, 0.00030815997160971165f, 0.00039281309000216424f, 0.00015608780086040497f, 0.0004308237403165549f, 0.00024210519040934741f, 0.000177671667188406f, 0.00020460024825297296f, 0.00032383608049713075f, 0.0005354639142751694f, 0.00011998965055681765f, 0.00017549832409713417f, 0.0002232417609775439f, 0.0003251899324823171f, 0.00018084929615724832f, 0.00014773181464988738f, 0.0002827190619427711f, 0.0002852931502275169f, 0.0004856116429436952f, 0.0002931745257228613f, 0.0007571758469566703f, 0.0006022098241373897f, 0.0006079335580579937f, 0.0005381330847740173f, 0.00017878205107990652f, 0.00030474094091914594f, 0.00032671005465090275f, 0.00029056385392323136f, 0.0005454688216559589f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #93 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0009803945431485772f, 0.012915197759866714f, 0.031897518783807755f, 0.005656156223267317f, 0.012580139562487602f, 0.0459030345082283f, 0.005537259858101606f, 0.01848357729613781f, 0.00606822595000267f, 0.004457021597772837f, 0.0036431082990020514f, 0.007450487464666367f, 0.004780963994562626f, 0.009797131642699242f, 0.006215493660420179f, 0.005986850708723068f, 0.011866377666592598f, 0.0038348298985511065f, 0.00493077514693141f, 0.007047567050904036f, 0.0036755301989614964f, 0.004853225778788328f, 0.004390568006783724f, 0.00345858046784997f, 0.012133500538766384f, 0.012351393699645996f, 0.009086386300623417f, 0.007222156040370464f, 0.010356845334172249f, 0.004816188011318445f, 0.009388293139636517f, 0.006251134444028139f, 0.004159990232437849f, 0.010921875014901161f, 0.005916273221373558f, 0.018330318853259087f, 0.00954001396894455f, 0.013055217452347279f, 0.021512454375624657f, 0.0047265710309147835f, 0.006139322649687529f, 0.007312971167266369f, 0.0023318335879594088f, 0.004009682685136795f, 0.010213040746748447f, 0.008822882547974586f, 0.006723823957145214f, 0.008753552101552486f, 0.008852128870785236f, 0.04047168791294098f, 0.005621174816042185f, 0.007166077848523855f, 0.004500928800553083f, 0.01041493657976389f, 0.03931128978729248f, 0.0044432212598621845f, 0.0038762527983635664f, 0.00691945618018508f, 0.009783928282558918f, 0.01572590135037899f, 0.006593460217118263f, 0.009324658662080765f, 0.00916373822838068f, 0.02391055040061474f, 0.0056819855235517025f, 0.01365065947175026f, 0.014199506491422653f, 0.02252023294568062f, 0.004842860624194145f, 0.00748564163222909f, 0.00828017108142376f, 0.005489542614668608f, 0.0053171152248978615f, 0.009957361966371536f, 0.010587934404611588f, 0.004984274506568909f, 0.0035739820450544357f, 0.028081713244318962f, 0.00369529752060771f, 0.005059247836470604f, 0.006747779436409473f, 0.006485774647444487f, 0.007378845475614071f, 0.0045148590579628944f, 0.009799870662391186f, 0.004148573148995638f, 0.0055725243873894215f, 0.00337236444465816f, 0.003760840278118849f, 0.0027637570165097713f, 0.01164733525365591f, 0.008340022526681423f, 0.005748629104346037f, 0.007653054315596819f, 0.0036889673210680485f, 0.007532397285103798f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #94 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(2.3068107111612335e-05f, 0.0003038870054297149f, 0.0007505298708565533f, 0.00013308602501638234f, 0.000296003301627934f, 0.0010800714371725917f, 0.0001302884629694745f, 0.0004349077062215656f, 0.00014278179151006043f, 0.00010487109830137342f, 8.572019578423351e-05f, 0.00017530558397993445f, 0.00011249327508267015f, 0.00023052074539009482f, 0.00014624690811615437f, 0.00014086707960814238f, 0.0002792088780552149f, 9.023129678098485e-05f, 0.00011601824371609837f, 0.00016582511307206005f, 8.648306538816541e-05f, 0.00011419354996178299f, 0.00010330748773412779f, 8.137836266541854e-05f, 0.0002854941412806511f, 0.00029062104295007885f, 0.00021379733516369015f, 0.00016993308963719755f, 0.0002436904760543257f, 0.00011332207213854417f, 0.00022090101265348494f, 0.00014708552043884993f, 9.788212628336623e-05f, 0.00025698530953377485f, 0.00013920642959419638f, 0.00043130162521265447f, 0.00022447091760113835f, 0.00030718158814124763f, 0.0005061753909103572f, 0.0001112134414142929f, 0.00014445465058088303f, 0.00017206990742124617f, 5.486667214427143e-05f, 9.434547973796725e-05f, 0.0002403068501735106f, 0.00020759724429808557f, 0.00015820762200746685f, 0.00020596593094523996f, 0.0002082853898173198f, 0.0009522750042378902f, 0.00013226293958723545f, 0.0001686135947238654f, 0.00010590421152301133f, 0.0002450573374517262f, 0.0009249715367332101f, 0.00010454638686496764f, 9.120594768319279e-05f, 0.00016281074204016477f, 0.0002302100765518844f, 0.0003700212109833956f, 0.00015514023834839463f, 0.00021940373699180782f, 0.00021561737230513245f, 0.0005626011989079416f, 0.00013369378575589508f, 0.0003211919975001365f, 0.00033410603646188974f, 0.0005298878531903028f, 0.00011394966713851318f, 0.00017613274394534528f, 0.00019482756033539772f, 0.00012916570995002985f, 0.0001251085923286155f, 0.00023429087013937533f, 0.00024912788649089634f, 0.00011727704986697063f, 8.409369911532849e-05f, 0.0006607461837120354f, 8.694818097865209e-05f, 0.00011904112761840224f, 0.00015877129044383764f, 0.0001526064588688314f, 0.00017361989011988044f, 0.00010623197886161506f, 0.00023058519582264125f, 9.761349065229297e-05f, 0.0001311182277277112f, 7.934975292300805e-05f, 8.849036385072395e-05f, 6.502957694465294e-05f, 0.0002740549389272928f, 0.00019623582193162292f, 0.00013526187103707343f, 0.00018007187463808805f, 8.679923485033214e-05f, 0.00017723288328852504f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #95 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007293766364455223f, 0.015578276477754116f, 0.014443621970713139f, 0.018552491441369057f, 0.012871013022959232f, 0.008878340944647789f, 0.015562744811177254f, 0.014512003399431705f, 0.006717166397720575f, 0.03727472200989723f, 0.014029487036168575f, 0.008083377033472061f, 0.03979111835360527f, 0.04100554436445236f, 0.007310185115784407f, 0.00801785010844469f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #96 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00017161804134957492f, 0.00036654769792221487f, 0.00033984993933700025f, 0.0004365292261354625f, 0.0003028473583981395f, 0.00020890214364044368f, 0.00036618224112316966f, 0.0003414589154999703f, 0.00015805097064003348f, 0.0008770523127168417f, 0.0003301055694464594f, 0.00019019711180590093f, 0.000936261611059308f, 0.0009648363338783383f, 0.0001720043655950576f, 0.000188655307283625f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #97 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0009469864889979362f, 0.00040190585423260927f, 0.000276873615803197f, 0.0008043725392781198f, 0.0006926886853761971f, 0.002606399590149522f, 0.002519493456929922f, 0.0004611860204022378f, 0.00018406134040560573f, 0.0007503777160309255f, 0.00048684480134397745f, 0.0005090698832646012f, 0.0007199725951068103f, 0.000918472942430526f, 0.001215958734974265f, 0.0006517813890241086f, 0.0005323522491380572f, 0.0010769159998744726f, 0.0011048467131331563f, 0.000863334396854043f, 0.0003238104982301593f, 0.00044238127884455025f, 0.0007525630644522607f, 0.0007222248241305351f, 0.0018167882226407528f, 0.0012149227550253272f, 0.0009363478748127818f, 0.00069784140214324f, 0.0006148958345875144f, 0.0006955856224521995f, 0.0004893119912594557f, 0.0006329905590973794f, 0.0009085820056498051f, 0.0009253824828192592f, 0.0004357151919975877f, 0.0008728497195988894f, 0.000251333782216534f, 0.000680948025546968f, 0.0005412385798990726f, 0.0005078136455267668f, 0.0010354681871831417f, 0.0007054022280499339f, 0.0018287190468981862f, 0.0008908381569199264f, 0.0009381106938235462f, 0.0007919369963929057f, 0.0008691694238223135f, 0.0003981505869887769f, 0.00044365201028995216f, 0.0009215199388563633f, 0.0004026778042316437f, 0.0007733521051704884f, 0.0007269592024385929f, 0.000991016742773354f, 0.000669422501232475f, 0.0005160824512131512f, 0.00028791383374482393f, 0.0022336109541356564f, 0.0008103222935460508f, 0.0004081951919943094f, 0.0008026926079764962f, 0.000216949891182594f, 0.0008707365486770868f, 0.0009197572944685817f, 0.0009932680986821651f, 0.001192737021483481f, 0.00044105941196903586f, 0.0009811361087486148f, 0.0005215351702645421f, 0.0006769164465367794f, 0.0005974716041237116f, 0.0002668497618287802f, 0.0003472985699772835f, 0.0004505559627432376f, 0.000406369857955724f, 0.0008326173410750926f, 0.0011281464248895645f, 0.00024018484691623598f, 0.00048269133549183607f, 0.0011473679915070534f, 0.000758127891458571f, 0.0011659213341772556f, 0.0008203588658943772f, 0.0006402230355888605f, 0.00043015970732085407f, 0.0011703644413501024f, 0.0005316882161423564f, 0.0011569360503926873f, 0.001259123906493187f, 0.0005817892961204052f, 0.0005637442809529603f, 0.00033495426760055125f, 0.0008574388339184225f, 0.000558297208044678f, 0.0011523512657731771f, 0.0008923799614422023f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #98 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00027412190684117377f, 0.0001163387278211303f, 8.01459391368553e-05f, 0.00023283979680854827f, 0.00020051092724315822f, 0.0007544682594016194f, 0.0007293117232620716f, 0.00013349841174203902f, 5.327979670255445e-05f, 0.00021721003577113152f, 0.00014092579658608884f, 0.0001473592419642955f, 0.00020840874640271068f, 0.00026586814783513546f, 0.0003519806487020105f, 0.00018866959726437926f, 0.00015409872867166996f, 0.00031173229217529297f, 0.0003198173362761736f, 0.0002499073452781886f, 9.373264765599743e-05f, 0.00012805504957213998f, 0.00021784262207802385f, 0.00020906068675685674f, 0.0005259013269096613f, 0.0003516807919368148f, 0.00027104237233288586f, 0.0002020024840021506f, 0.00017799242050386965f, 0.0002013494959101081f, 0.00014163997548166662f, 0.00018323026597499847f, 0.0002630050585139543f, 0.00026786825037561357f, 0.00012612543650902808f, 0.0002526617026887834f, 7.275298412423581e-05f, 0.00019711238564923406f, 0.0001566710416227579f, 0.00014699560415465385f, 0.0002997345000039786f, 0.00020419109205249697f, 0.0005293549038469791f, 0.00025786878541111946f, 0.0002715526497922838f, 0.0002292401040904224f, 0.0002515963860787451f, 0.00011525169247761369f, 0.0001284228783333674f, 0.00026675016852095723f, 0.00011656217975541949f, 0.000223860377445817f, 0.00021043114247731864f, 0.00028686723089776933f, 0.0001937761262524873f, 0.0001493891468271613f, 8.334172889590263e-05f, 0.0006465580081567168f, 0.00023456204507965595f, 0.00011815928155556321f, 0.0002323535009054467f, 6.279996159719303e-05f, 0.00025205002748407423f, 0.00026623994926922023f, 0.0002875189238693565f, 0.0003452587407082319f, 0.00012767240696121007f, 0.00028400711016729474f, 0.00015096753486432135f, 0.00019594538025557995f, 0.0001729486684780568f, 7.72443599998951e-05f, 0.00010053168807644397f, 0.00013042135105933994f, 0.00011763090878957883f, 0.0002410157467238605f, 0.0003265618288423866f, 6.952573312446475e-05f, 0.00013972350279800594f, 0.0003321258700452745f, 0.00021945346088614315f, 0.0003374964580871165f, 0.00023746732040308416f, 0.00018532382091507316f, 0.00012451730435714126f, 0.00033878258545883f, 0.00015390651242341846f, 0.0003348955069668591f, 0.0003644755925051868f, 0.00016840915486682206f, 0.0001631857012398541f, 9.695840708445758e-05f, 0.00024820075486786664f, 0.00016160895756911486f, 0.00033356837229803205f, 0.00025831509265117347f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #99 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008913255296647549f, 0.00907611008733511f, 0.027996959164738655f, 0.004297306761145592f, 0.007745213340967894f, 0.001347350305877626f, 0.002424537669867277f, 0.008013327606022358f, 0.049562081694602966f, 0.013798614032566547f, 0.00644763745367527f, 0.016707735136151314f, 0.003041887655854225f, 0.017399754375219345f, 0.013861012645065784f, 0.007627828978002071f, 0.007017872761934996f, 0.007483876775950193f, 0.005052539985626936f, 0.004830479621887207f, 0.0331023633480072f, 0.006041702348738909f, 0.008470739237964153f, 0.008126630447804928f, 0.0026251415256410837f, 0.0030793515034019947f, 0.008537319488823414f, 0.007548762019723654f, 0.008842552080750465f, 0.008198725059628487f, 0.004605553578585386f, 0.006547986995428801f, 0.008931713178753853f, 0.004161057993769646f, 0.008619272150099277f, 0.004043213091790676f, 0.02038709819316864f, 0.0067794737406075f, 0.0075254072435200214f, 0.00869228970259428f, 0.005278960335999727f, 0.004852297715842724f, 0.0035011915024369955f, 0.0038627726025879383f, 0.010858297348022461f, 0.008484113961458206f, 0.01207597553730011f, 0.008723953738808632f, 0.00801446195691824f, 0.010851806960999966f, 0.013688389211893082f, 0.016931775957345963f, 0.005926256999373436f, 0.0037179398350417614f, 0.005049888510257006f, 0.0050510442815721035f, 0.03593503683805466f, 0.0011278213933110237f, 0.006026934366673231f, 0.004098204430192709f, 0.009907485917210579f, 0.038187358528375626f, 0.007787939626723528f, 0.01946951262652874f, 0.025632526725530624f, 0.007856636308133602f, 0.007674812339246273f, 0.003412816906347871f, 0.009507540613412857f, 0.006498794071376324f, 0.007328415755182505f, 0.022164655849337578f, 0.011605173349380493f, 0.012321148999035358f, 0.013945143669843674f, 0.0027987088542431593f, 0.02558094449341297f, 0.028798194602131844f, 0.01685517653822899f, 0.005540087353438139f, 0.008156809955835342f, 0.0034026685170829296f, 0.006487617734819651f, 0.011993545107543468f, 0.006234186235815287f, 0.006867400370538235f, 0.007508596405386925f, 0.005739444866776466f, 0.006835005711764097f, 0.007300207391381264f, 0.01137095782905817f, 0.009235861711204052f, 0.015265699476003647f, 0.012578438967466354f, 0.0032561919651925564f, 0.010976516641676426f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #100 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002097236574627459f, 0.0002135555405402556f, 0.00065875198924914f, 0.00010111310257343575f, 0.0001822403137339279f, 3.1702362321084365e-05f, 5.704794602934271e-05f, 0.00018854888912755996f, 0.001166166621260345f, 0.00032467328128404915f, 0.00015170911501627415f, 0.00039312319131568074f, 7.157382788136601e-05f, 0.0004094059986528009f, 0.0003261414822191f, 0.00017947833111975342f, 0.00016512641741428524f, 0.00017609122733119875f, 0.00011888329754583538f, 0.00011365834507159889f, 0.0007788791554048657f, 0.00014215770352166146f, 0.00019931151473429054f, 0.00019121484365314245f, 6.176803435664624e-05f, 7.245533197419718e-05f, 0.0002008781157201156f, 0.00017761792696546763f, 0.00020806005341000855f, 0.0001929111749632284f, 0.00010836596629815176f, 0.0001540702796773985f, 0.00021015795937273651f, 9.790725016500801e-05f, 0.00020280640455894172f, 9.513442637398839e-05f, 0.00047969643492251635f, 0.00015951703244354576f, 0.00017706840299069881f, 0.00020452446187846363f, 0.00012421084102243185f, 0.00011417171481298283f, 8.238097507273778e-05f, 9.088876686291769e-05f, 0.0002554893435444683f, 0.0001996262144530192f, 0.0002841406094375998f, 0.00020526950538624078f, 0.00018857557734008878f, 0.0002553366357460618f, 0.00032207975164055824f, 0.00039839473902247846f, 0.0001394413411617279f, 8.748094114707783e-05f, 0.00011882090620929375f, 0.00011884810373885557f, 0.0008455303031951189f, 2.653697447385639e-05f, 0.0001418102183379233f, 9.642833902034909e-05f, 0.00023311731638386846f, 0.0008985261083580554f, 0.00018324564734939486f, 0.0004581061948556453f, 0.0006031182711012661f, 0.00018486203043721616f, 0.00018058382556773722f, 8.03015791461803e-05f, 0.0002237068401882425f, 0.00015291280578821898f, 0.00017243331240024418f, 0.0005215213168412447f, 0.0002730629057623446f, 0.0002899093960877508f, 0.00032812103745527565f, 6.585197115782648e-05f, 0.0006019045831635594f, 0.0006776045775040984f, 0.00039659239700995386f, 0.0001303549943258986f, 0.0001919249480124563f, 8.006278949324042e-05f, 0.00015264983812812716f, 0.00028220107196830213f, 0.00014668673975393176f, 0.0001615858927834779f, 0.00017667285283096135f, 0.00013504576054401696f, 0.00016082366346381605f, 0.00017176958499476314f, 0.0002675519499462098f, 0.00021731440210714936f, 0.0003591929271351546f, 0.00029596328386105597f, 7.661628478672355e-05f, 0.00025827097124420106f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #101 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008623763918876648f, 0.017390834167599678f, 0.014214018359780312f, 0.020170066505670547f, 0.011906825937330723f, 0.011258339509367943f, 0.01836712844669819f, 0.01299535483121872f, 0.008956287056207657f, 0.02389718033373356f, 0.014291146770119667f, 0.010056533850729465f, 0.03289167955517769f, 0.03305592015385628f, 0.00937081128358841f, 0.009798754937946796f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #102 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00020291209511924535f, 0.00040919610182754695f, 0.0003344475117046386f, 0.00047458981862291694f, 0.00028016060241498053f, 0.0002649021043907851f, 0.0004321677261032164f, 0.0003057730500586331f, 0.00021073616517242044f, 0.0005622865865007043f, 0.00033626228105276823f, 0.00023662432795390487f, 0.0007739218999631703f, 0.0007777863647788763f, 0.00022048968821763992f, 0.00023055894416756928f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #103 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003877491399180144f, 0.0005373861640691757f, 0.0007076248875819147f, 0.0007557272911071777f, 0.0007210129988379776f, 0.000585082801990211f, 0.000542679859790951f, 0.0003215030883438885f, 0.0005644371267408133f, 0.001251877867616713f, 0.0017042758408933878f, 0.0015657676849514246f, 0.001494923490099609f, 0.0019133043242618442f, 0.0017417293274775147f, 0.001516331103630364f, 0.0006513543776236475f, 0.0013847900554537773f, 0.0018517757998779416f, 0.000566585804335773f, 0.002646999666467309f, 0.0006773684290237725f, 0.0005954047082923353f, 0.00045164843322709203f, 0.00157582585234195f, 0.0013393863337114453f, 0.0006596258608624339f, 0.004003094509243965f, 0.000768077268730849f, 0.0004963150131516159f, 0.00030429571052081883f, 0.0014035683125257492f, 0.0014139608247205615f, 0.0009354523499496281f, 0.0007079730276018381f, 0.001752005540765822f, 0.0010094300378113985f, 0.000717880786396563f, 0.0009029036154970527f, 0.0005932605708949268f, 0.0009055561968125403f, 0.0013653585920110345f, 0.0009381172130815685f, 0.0010130400769412518f, 0.0007599655073136091f, 0.0014239897718653083f, 0.0006993499118834734f, 0.0012960440944880247f, 0.0017256299033761024f, 0.001153451157733798f, 0.002343696542084217f, 0.0009751885081641376f, 0.0015237829647958279f, 0.0016116541810333729f, 0.0007227795431390405f, 0.002327661495655775f, 0.0012965406058356166f, 0.00037529884139075875f, 0.0013874223222956061f, 0.0014988593757152557f, 0.00036555834230966866f, 0.0016248784959316254f, 0.0016578782815486193f, 0.0016508345725014806f, 0.0008885126444511116f, 0.0013742318842560053f, 0.00024601584300398827f, 0.000789952406194061f, 0.0009429694036953151f, 0.0017081653932109475f, 0.0027190768159925938f, 0.0012665727408602834f, 0.00041648547630757093f, 0.0005900817341171205f, 0.0015149177052080631f, 0.0009366110316477716f, 0.0004705643223132938f, 0.0008578801644034684f, 0.0017119196709245443f, 0.0010572365717962384f, 0.000570253818295896f, 0.0005196640850044787f, 0.0003966032818425447f, 0.00028469847165979445f, 0.0006845661555416882f, 0.0011550172930583358f, 0.00043630690197460353f, 0.0010261849965900183f, 0.0007401155889965594f, 0.0006501160678453743f, 0.0008265188080258667f, 0.0007939190836623311f, 0.00041364171192981303f, 0.0017254984704777598f, 0.0022385925985872746f, 0.00038608748582191765f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #104 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00015779526438564062f, 0.00021869034389965236f, 0.00028796930564567447f, 0.00030754468753002584f, 0.0002934176300186664f, 0.000238100576098077f, 0.00022084462398197502f, 0.00013083629892207682f, 0.00022969878045842052f, 0.000509454112034291f, 0.0006935583660379052f, 0.0006371921626850963f, 0.0006083620246499777f, 0.0007786228670738637f, 0.0007088001002557576f, 0.0006170738488435745f, 0.0002650699170771986f, 0.0005635429988615215f, 0.0007535837357863784f, 0.00023057319049257785f, 0.001077201683074236f, 0.00027565640630200505f, 0.00024230110284406692f, 0.00018379920220468193f, 0.0006412853836081922f, 0.000545065850019455f, 0.00026843600790016353f, 0.0016290670027956367f, 0.0003125705407001078f, 0.00020197634876240045f, 0.00012383372813928872f, 0.000571184849832207f, 0.0005754141020588577f, 0.00038068415597081184f, 0.00028811098309233785f, 0.0007129820296540856f, 0.00041078950744122267f, 0.0002921429695561528f, 0.0003674383624456823f, 0.00024142854090314358f, 0.000368517852621153f, 0.0005556353135034442f, 0.00038176862290129066f, 0.00041225861059501767f, 0.0003092694387305528f, 0.0005794953904114664f, 0.0002846017887350172f, 0.0005274276481941342f, 0.0007022484205663204f, 0.00046939917956478894f, 0.0009537718142382801f, 0.0003968548553530127f, 0.0006201064097695053f, 0.0006558657623827457f, 0.00029413652373477817f, 0.000947246327996254f, 0.0005276296869851649f, 0.00015272859309334308f, 0.000564614194445312f, 0.0006099637248553336f, 0.0001487646804889664f, 0.0006612474680878222f, 0.0006746767903678119f, 0.0006718102958984673f, 0.00036158194416202605f, 0.000559246342163533f, 0.00010011662379838526f, 0.0003214726457372308f, 0.00038374323048628867f, 0.0006951412069611251f, 0.0011065335711464286f, 0.0005154342507012188f, 0.0001694895763648674f, 0.00024013490474317223f, 0.0006164986989460886f, 0.0003811556671280414f, 0.0001914970634970814f, 0.00034911598777398467f, 0.0006966690416447818f, 0.0004302444576751441f, 0.00023206589685287327f, 0.00021147829829715192f, 0.00016139847866725177f, 0.00011585859465412796f, 0.00027858553221449256f, 0.00047003652434796095f, 0.0001775559358065948f, 0.0004176079819444567f, 0.00030119146686047316f, 0.0002645659842528403f, 0.0003363534342497587f, 0.00032308691879734397f, 0.00016833229165058583f, 0.0007021949277259409f, 0.000910999602638185f, 0.00015711905143689364f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #105 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003427580464631319f, 0.0034825047478079796f, 0.005261993035674095f, 0.0064997621811926365f, 0.0037627662532031536f, 0.002580120926722884f, 0.0038982585538178682f, 0.01010220032185316f, 0.003150882665067911f, 0.0031854240223765373f, 0.0011370577849447727f, 0.002968706889078021f, 0.001683729002252221f, 0.0012516621500253677f, 0.0019559829961508512f, 0.002017840975895524f, 0.0025212252512574196f, 0.0016442291671410203f, 0.0008527929312549531f, 0.0028121222276240587f, 0.0011168799828737974f, 0.003637525951489806f, 0.004639259073883295f, 0.005341663025319576f, 0.0024262198712676764f, 0.0033481987193226814f, 0.003851809771731496f, 0.0017544630682095885f, 0.005717317573726177f, 0.004008904565125704f, 0.012676979415118694f, 0.003566240891814232f, 0.0024283272214233875f, 0.002570509444922209f, 0.003459147410467267f, 0.0026475079357624054f, 0.002149471314623952f, 0.008514375425875187f, 0.0026881187222898006f, 0.005204375367611647f, 0.0027580237947404385f, 0.0016326401382684708f, 0.0018596623558551073f, 0.0026972028426826f, 0.003070991253480315f, 0.0017703769262880087f, 0.004218481946736574f, 0.0034218584187328815f, 0.0010492912260815501f, 0.003164844587445259f, 0.0012814984656870365f, 0.0025039110332727432f, 0.0013871064875274897f, 0.003885789541527629f, 0.0018600309267640114f, 0.0008906005532480776f, 0.004104756750166416f, 0.007524179294705391f, 0.0025790666695684195f, 0.0011827033013105392f, 0.009829296730458736f, 0.0011031790636479855f, 0.00193737109657377f, 0.004504905082285404f, 0.002011127071455121f, 0.0017198972636833787f, 0.011904893442988396f, 0.0015932003734633327f, 0.002409998793154955f, 0.0012522049946710467f, 0.0017657466232776642f, 0.0038387428503483534f, 0.006656152196228504f, 0.004553286824375391f, 0.0069907233119010925f, 0.0037656822241842747f, 0.0033504648599773645f, 0.0028513348661363125f, 0.0010597659274935722f, 0.0039826612919569016f, 0.005108897108584642f, 0.006349899340420961f, 0.0036677478346973658f, 0.007010301575064659f, 0.002903161570429802f, 0.003115709638223052f, 0.006611818913370371f, 0.0031271888874471188f, 0.0031851802486926317f, 0.0025176459457725286f, 0.0033607040531933308f, 0.0031908887904137373f, 0.010165807791054249f, 0.0007552822935394943f, 0.0013970687286928296f, 0.006021131295710802f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #106 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.064895519055426e-05f, 8.194128895411268e-05f, 0.0001238116092281416f, 0.00015293557953555137f, 8.853567851474509e-05f, 6.0708727687597275e-05f, 9.172373393084854e-05f, 0.00023769884137436748f, 7.41384137654677e-05f, 7.495115278288722e-05f, 2.6754301870823838e-05f, 6.985192885622382e-05f, 3.96171526517719e-05f, 2.9450875445036218e-05f, 4.602313128998503e-05f, 4.7478613851126283e-05f, 5.93229488003999e-05f, 3.868774729198776e-05f, 2.0065715943928808e-05f, 6.616758037125692e-05f, 2.6279529265593737e-05f, 8.558885019738227e-05f, 0.00010915903840214014f, 0.00012568618694785982f, 5.708752723876387e-05f, 7.878115138737485e-05f, 9.063081961357966e-05f, 4.128148430027068e-05f, 0.00013452512212097645f, 9.432716615265235e-05f, 0.0002982818696182221f, 8.391155279241502e-05f, 5.713711288990453e-05f, 6.0482576373033226e-05f, 8.139170677168295e-05f, 6.229430437088013e-05f, 5.057579619460739e-05f, 0.00020033825421705842f, 6.324985588435084e-05f, 0.00012245589459780604f, 6.489468069048598e-05f, 3.84150625905022e-05f, 4.375676144263707e-05f, 6.346359441522509e-05f, 7.225861918414012e-05f, 4.16559269069694e-05f, 9.925840276991948e-05f, 8.051432087086141e-05f, 2.468920501996763e-05f, 7.44669305277057e-05f, 3.0152905310387723e-05f, 5.891555338166654e-05f, 3.2637799449730664e-05f, 9.143034549197182e-05f, 4.376543438411318e-05f, 2.0955307263648137e-05f, 9.658251656219363e-05f, 0.0001770395174389705f, 6.0683923948090523e-05f, 2.7828313250211067e-05f, 0.00023127757594920695f, 2.5957155230571516e-05f, 4.558520231512375e-05f, 0.0001059977657860145f, 4.732063825940713e-05f, 4.046817048219964e-05f, 0.0002801151422318071f, 3.748706876649521e-05f, 5.6705855968175456e-05f, 2.9463648388627917e-05f, 4.154698035563342e-05f, 9.032335947267711e-05f, 0.00015661535144317895f, 0.00010713616211432964f, 0.0001644876174395904f, 8.860429079504684e-05f, 7.883446960477158e-05f, 6.709023000439629e-05f, 2.4935668989201076e-05f, 9.370967745780945e-05f, 0.00012020934809697792f, 0.0001494094030931592f, 8.629995136288926e-05f, 0.00016494827286805958f, 6.830968777649105e-05f, 7.331081724260002e-05f, 0.0001555722119519487f, 7.358091534115374e-05f, 7.494541932828724e-05f, 5.9238729591015726e-05f, 7.907539111329243e-05f, 7.507974078180268e-05f, 0.00023919547675177455f, 1.777134821168147e-05f, 3.2872205338208005e-05f, 0.00014167367771733552f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #107 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011890444904565811f, 0.022895164787769318f, 0.01516704447567463f, 0.03311833366751671f, 0.015446820296347141f, 0.017115488648414612f, 0.015509359538555145f, 0.020609302446246147f, 0.02088393084704876f, 0.017550624907016754f, 0.013206577859818935f, 0.02043810486793518f, 0.015926875174045563f, 0.0076985894702374935f, 0.018744170665740967f, 0.015834219753742218f, 0.015669135376811028f, 0.014729933813214302f, 0.011517188511788845f, 0.013870079070329666f, 0.012319034896790981f, 0.012678902596235275f, 0.021685028448700905f, 0.01489051803946495f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #108 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000279775180388242f, 0.0005387097480706871f, 0.000356871634721756f, 0.0007792549440637231f, 0.0003634546010289341f, 0.00040271738544106483f, 0.00036492611980065703f, 0.0004849247634410858f, 0.0004913866287097335f, 0.0004129558801651001f, 0.00031074302387423813f, 0.0004808965895790607f, 0.00037475000135600567f, 0.00018114328850060701f, 0.0004410393303260207f, 0.00037256989162415266f, 0.0003686855488922447f, 0.00034658669028431177f, 0.00027099266299046576f, 0.00032635481329634786f, 0.00028985965764150023f, 0.00029832712607458234f, 0.0005102359573356807f, 0.0003503651241771877f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #109 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00035894778557121754f, 0.00037278133095242083f, 0.0004615637590177357f, 0.0003650622966233641f, 0.0007104468531906605f, 0.0004935978213325143f, 0.0005692528211511672f, 0.000820389308501035f, 0.0004198618116788566f, 0.0005712967249564826f, 0.0006737341755069792f, 0.0005030542961321771f, 0.0007589437300339341f, 0.0007904351223260164f, 0.0009742557303979993f, 0.001329103484749794f, 0.00048370222793892026f, 0.00046470918459817767f, 0.0008023908594623208f, 0.0003966577351093292f, 0.0005140611901879311f, 0.000793393817730248f, 0.0011408969294279814f, 0.0005313033470883965f, 0.0006134984432719648f, 0.0008818777860142291f, 0.0007580520468764007f, 0.00024066104379016906f, 0.0005537669057957828f, 0.0013056622119620442f, 0.00036893674405291677f, 0.0012250543804839253f, 0.0006364104337990284f, 0.0007944640819914639f, 0.00033556201378814876f, 0.0013610579771921039f, 0.0005581303266808391f, 0.0006196624599397182f, 0.0006413407973013818f, 0.00032190626370720565f, 0.00040099021862261f, 0.00031887422665022314f, 0.0010016096057370305f, 0.0011623470345512033f, 0.000715826521627605f, 0.0008885178249329329f, 0.0009817457757890224f, 0.00039277845644392073f, 0.0006234030006453395f, 0.00027070619398728013f, 0.0009901892626658082f, 0.0006815100205130875f, 0.00029354155412875116f, 0.00024581560865044594f, 0.0008268067613244057f, 0.0008098597754724324f, 0.0002988346095662564f, 0.0019179400987923145f, 0.0008019116357900202f, 0.0004117463540751487f, 0.0006084111519157887f, 0.0005714361323043704f, 0.0004735778202302754f, 0.0007344781770370901f, 0.000667861255351454f, 0.000602078449446708f, 0.0006525252829305828f, 0.0012753685005009174f, 0.0008960349950939417f, 0.0007147772703319788f, 0.0012832023203372955f, 0.0011982907308265567f, 0.0011602671584114432f, 0.0012870758073404431f, 0.0007012086571194232f, 0.0008942303247749805f, 0.0005475149373523891f, 0.003295160597190261f, 0.0008021998219192028f, 0.0003315419307909906f, 0.0003950950922444463f, 0.0008508012979291379f, 0.0003568014071788639f, 0.000491695012897253f, 0.0013514356687664986f, 0.0010098114144057035f, 0.0004624167922884226f, 0.0006768142920918763f, 0.0011919912649318576f, 0.0004045679816044867f, 0.0009948196820914745f, 0.0010588258737698197f, 0.0005729749682359397f, 0.0006236035260371864f, 0.0004699663841165602f, 0.00044501328375190496f, 0.0007117507047951221f, 0.0005231481627561152f, 0.0008421532111242414f, 0.0003218488418497145f, 0.000790699094068259f, 0.0007870739209465683f, 0.0006157177267596126f, 0.0010767674539238214f, 0.0010514078894630075f, 0.0005379840149544179f, 0.0001317197020398453f, 0.0002505614538677037f, 0.0009490631055086851f, 0.0006764827994629741f, 0.0006143467035144567f, 0.0008380270446650684f, 0.0005630398518405855f, 0.000170767743838951f, 0.0010824068449437618f, 0.0003915606648661196f, 0.0016550073632970452f, 0.0004912743461318314f, 0.0008764872327446938f, 0.0009179605403915048f, 0.000308872084133327f, 0.0005658146110363305f, 0.0010197121882811189f, 0.0010374276898801327f, 0.0005721363122574985f, 0.0009051246452145278f, 0.0007752229575999081f, 0.0012616433668881655f, 0.0021775118075311184f, 0.00044949440052732825f, 0.0010760898003354669f, 0.0005270371329970658f, 0.0004983429098501801f, 0.000884164241142571f, 0.0006239647627808154f, 0.0007149927550926805f, 0.0007461948553100228f, 0.0005855599883943796f, 0.0009407780016772449f, 0.0012474629329517484f, 0.0002027606824412942f, 0.0008184711914509535f, 0.001648007077164948f, 0.00047535155317746103f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #110 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(6.492545071523637e-05f, 6.742762343492359e-05f, 8.348633855348453e-05f, 6.60314253764227e-05f, 0.00012850359780713916f, 8.928056922741234e-05f, 0.00010296482651028782f, 0.0001483896776335314f, 7.594340422656387e-05f, 0.0001033345251926221f, 0.0001218631150550209f, 9.099103044718504e-05f, 0.00013727557961829007f, 0.00014297165034804493f, 0.00017622059385757893f, 0.00024040444986894727f, 8.74906763783656e-05f, 8.405527478316799e-05f, 0.00014513416681438684f, 7.174631900852546e-05f, 9.29819216253236e-05f, 0.00014350681158248335f, 0.0002063621795969084f, 9.610063716536388e-05f, 0.00011096784874098375f, 0.00015951154637150466f, 0.00013711428618989885f, 4.3530082621145993e-05f, 0.00010016377927968279f, 0.00023616445832885802f, 6.673222378594801e-05f, 0.0002215843414887786f, 0.00011511210323078558f, 0.00014370039571076632f, 6.069549999665469e-05f, 0.00024618429597467184f, 0.0001009530242299661f, 0.00011208278010599315f, 0.0001160038955276832f, 5.822548700962216e-05f, 7.252996874740347e-05f, 5.767706170445308e-05f, 0.00018116828869096935f, 0.00021024201123509556f, 0.0001294766552746296f, 0.0001607125741429627f, 0.0001775753771653399f, 7.104464748408645e-05f, 0.00011275935685262084f, 4.896456448477693e-05f, 0.00017910261522047222f, 0.00012326959404163063f, 5.3094958275323734e-05f, 4.4462427467806265e-05f, 0.00014955045480746776f, 0.00014648512296844274f, 5.405235060607083e-05f, 0.00034691154723986983f, 0.0001450474956072867f, 7.447550888173282e-05f, 0.0001100476729334332f, 0.00010335973638575524f, 8.565940515836701e-05f, 0.00013285031309351325f, 0.00012080083979526535f, 0.00010890223347814754f, 0.00011802691005868837f, 0.00023068502196110785f, 0.0001620722614461556f, 0.00012928686919622123f, 0.0002321019710507244f, 0.0002167434140574187f, 0.00020986581512261182f, 0.00023280260211322457f, 0.00012683261593338102f, 0.00016174583288375288f, 9.903294267132878e-05f, 0.0005960192647762597f, 0.0001450996205676347f, 5.996835898258723e-05f, 7.146367715904489e-05f, 0.0001538905198685825f, 6.453722016885877e-05f, 8.893639460438862e-05f, 0.00024444382870569825f, 0.00018265181279275566f, 8.36406325106509e-05f, 0.00012242024240549654f, 0.00021560398454312235f, 7.317709969356656e-05f, 0.00017994015070144087f, 0.00019151740707457066f, 0.00010363807814428583f, 0.00011279562750132754f, 8.500617695972323e-05f, 8.049273310462013e-05f, 0.0001287394406972453f, 9.46255458984524e-05f, 0.00015232627629302442f, 5.821510058012791e-05f, 0.0001430193951819092f, 0.000142363685881719f, 0.00011136927059851587f, 0.00019476262968964875f, 0.00019017566228285432f, 9.730901365401223e-05f, 2.3825085008866154e-05f, 4.532084130914882e-05f, 0.00017166382167488337f, 0.00012236027396284044f, 0.00011112127685919404f, 0.00015157993766479194f, 0.00010184104030486196f, 3.088798257522285e-05f, 0.00019578266073949635f, 7.082437514327466e-05f, 0.00029935300699435174f, 8.88603026396595e-05f, 0.00015853650984354317f, 0.0001660380803514272f, 5.5867902119643986e-05f, 0.00010234293586108834f, 0.0001844426296884194f, 0.00018764696142170578f, 0.00010348638170398772f, 0.00016371636593248695f, 0.00014022011600900441f, 0.00022820245067123324f, 0.0003938621375709772f, 8.130326750688255e-05f, 0.0001946400589076802f, 9.532897092867643e-05f, 9.013884118758142e-05f, 0.00015992511180229485f, 0.00011286096560070291f, 0.00012932585377711803f, 0.00013496959581971169f, 0.00010591441969154403f, 0.0001701652363408357f, 0.00022563754464499652f, 3.667477358249016e-05f, 0.00014804273087065667f, 0.0002980868157465011f, 8.598023123340681e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #111 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.022750690579414368f, 0.01814982295036316f, 0.011724267154932022f, 0.009609879925847054f, 0.010177450254559517f, 0.014987098053097725f, 0.008481817319989204f, 0.012490889988839626f, 0.013598919846117496f, 0.011882343329489231f, 0.00848937127739191f, 0.007659830152988434f, 0.006613228935748339f, 0.010400102473795414f, 0.023449428379535675f, 0.009854218922555447f, 0.011165734380483627f, 0.008535319939255714f, 0.022020872682332993f, 0.013544794172048569f, 0.006680045742541552f, 0.010245087556540966f, 0.006730667315423489f, 0.008395984768867493f, 0.01062620710581541f, 0.05287802591919899f, 0.020282529294490814f, 0.018406009301543236f, 0.010470111854374409f, 0.018281979486346245f, 0.015277708880603313f, 0.009221689775586128f, 0.009605229832231998f, 0.009336601011455059f, 0.026219196617603302f, 0.010866338387131691f, 0.018407152965664864f, 0.010575133375823498f, 0.012288667261600494f, 0.02933800034224987f, 0.008710241876542568f, 0.0447491891682148f, 0.00510551780462265f, 0.0068451170809566975f, 0.012797670438885689f, 0.009624255821108818f, 0.012994005344808102f, 0.010499101132154465f, 0.009835722856223583f, 0.014325721189379692f, 0.00813195388764143f, 0.00905697327107191f, 0.0192377008497715f, 0.038172464817762375f, 0.010515207424759865f, 0.015343665145337582f, 0.009494349360466003f, 0.00752542819827795f, 0.020408784970641136f, 0.021764351055026054f, 0.014087260700762272f, 0.009952276013791561f, 0.00737751042470336f, 0.005943972151726484f, 0.011967944912612438f, 0.010377727448940277f, 0.010760325938463211f, 0.007737699430435896f, 0.010705394670367241f, 0.011250125244259834f, 0.008662416599690914f, 0.004170926287770271f, 0.022243304178118706f, 0.003430852899327874f, 0.008668089285492897f, 0.022826336324214935f, 0.007763253059238195f, 0.014383516274392605f, 0.007631021551787853f, 0.009977152571082115f, 0.01661878637969494f, 0.017552655190229416f, 0.022931117564439774f, 0.010432461276650429f, 0.012085399590432644f, 0.0067437621764838696f, 0.014225115068256855f, 0.00989025179296732f, 0.008904237300157547f, 0.012647585943341255f, 0.009569653309881687f, 0.00875308457762003f, 0.01705336757004261f, 0.009545932523906231f, 0.007780574262142181f, 0.01178471278399229f, 0.0077626085840165615f, 0.02707524225115776f, 0.002983034122735262f, 0.017292045056819916f, 0.009763519279658794f, 0.007696579676121473f, 0.015743406489491463f, 0.006560144014656544f, 0.007432898040860891f, 0.010576949454843998f, 0.031874705106019974f, 0.014043355360627174f, 0.013531191274523735f, 0.018463388085365295f, 0.0073543814942240715f, 0.008354218676686287f, 0.007635051384568214f, 0.01974398083984852f, 0.027437400072813034f, 0.02228899672627449f, 0.004916988778859377f, 0.003311105305328965f, 0.009609706699848175f, 0.00574770150706172f, 0.013915176503360271f, 0.007139250636100769f, 0.0023404057137668133f, 0.01860753819346428f, 0.004605975467711687f, 0.006874379701912403f, 0.02717379294335842f, 0.006526498589664698f, 0.007137736771255732f, 0.018846485763788223f, 0.0024839078541845083f, 0.002597339916974306f, 0.013754231855273247f, 0.0066433255560696125f, 0.019692178815603256f, 0.008259701542556286f, 0.007148285862058401f, 0.008698507212102413f, 0.008350430987775326f, 0.0127602843567729f, 0.04211868345737457f, 0.011651549488306046f, 0.00669023348018527f, 0.01961510255932808f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #112 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005353103624656796f, 0.00042705467785708606f, 0.0002758651098702103f, 0.00022611483291257173f, 0.00023946941655594856f, 0.00035263760946691036f, 0.00019957218319177628f, 0.0002939032856374979f, 0.0003199745842721313f, 0.0002795845502987504f, 0.00019974992028437555f, 0.00018023130542133003f, 0.00015560539031866938f, 0.0002447082952130586f, 0.0005517512909136713f, 0.00023186397447716445f, 0.00026272315881215036f, 0.00020083105482626706f, 0.0005181381711736321f, 0.00031870105885900557f, 0.00015717755013611168f, 0.0002410608867648989f, 0.00015836863894946873f, 0.00019755258108489215f, 0.0002500284172128886f, 0.0012441888684406877f, 0.0004772359970957041f, 0.0004330825759097934f, 0.0002463555720169097f, 0.00043016421841457486f, 0.00035947549622505903f, 0.00021698094496969134f, 0.00022600541706196964f, 0.00021968473447486758f, 0.0006169222760945559f, 0.0002556785475462675f, 0.00043310949695296586f, 0.00024882666184566915f, 0.00028914512949995697f, 0.0006903058965690434f, 0.00020494687487371266f, 0.0010529221035540104f, 0.00012012983643217012f, 0.00016106158727779984f, 0.0003011216758750379f, 0.0002264530776301399f, 0.0003057412977796048f, 0.0002470376784913242f, 0.00023142877034842968f, 0.00033707579132169485f, 0.000191340091987513f, 0.00021310526062734425f, 0.0004526517877820879f, 0.0008981756400316954f, 0.0002474166394677013f, 0.0003610274288803339f, 0.00022339646238833666f, 0.00017706889775581658f, 0.00048020671238191426f, 0.0005121023859828711f, 0.00033146495115943253f, 0.00023417120974045247f, 0.00017358848708681762f, 0.00013985816622152925f, 0.0002815987099893391f, 0.00024418183602392673f, 0.00025318414554931223f, 0.00018206352251581848f, 0.0002518916444387287f, 0.00026470882585272193f, 0.00020382157526910305f, 9.813944052439183e-05f, 0.0005233718547970057f, 8.072594937402755e-05f, 0.00020395504543557763f, 0.0005370902945287526f, 0.00018266477854922414f, 0.0003384356969036162f, 0.00017955344810616225f, 0.00023475653142668307f, 0.0003910302766598761f, 0.00041300366865471005f, 0.0005395557382144034f, 0.0002454696805216372f, 0.00028436235152184963f, 0.00015867676120251417f, 0.00033470860216766596f, 0.00023271181271411479f, 0.0002095114759868011f, 0.00029759027529507875f, 0.00022516831813845783f, 0.00020595492969732732f, 0.0004012557037640363f, 0.00022461017942987382f, 0.000183072334039025f, 0.00027728735585696995f, 0.00018264961545355618f, 0.000637064513284713f, 7.018903852440417e-05f, 0.000406871666200459f, 0.0002297298633493483f, 0.00018109599477611482f, 0.00037043308839201927f, 0.0001543563266750425f, 0.0001748917275108397f, 0.0002488694153726101f, 0.0007499930798076093f, 0.00033043191069737077f, 0.0003183809749316424f, 0.0004344326735008508f, 0.00017304427456110716f, 0.00019656986114569008f, 0.0001796482683857903f, 0.0004645642766263336f, 0.000645585882011801f, 0.0005244470085017383f, 0.00011569385242182761f, 7.790836389176548e-05f, 0.00022611074382439256f, 0.00013524004316423088f, 0.0003274159098509699f, 0.00016798237629700452f, 5.506837260327302e-05f, 0.00043782443390227854f, 0.00010837589798029512f, 0.00016175011114683002f, 0.0006393833900801837f, 0.0001535646733827889f, 0.00016794675320852548f, 0.0004434467409737408f, 5.844489351147786e-05f, 6.111388211138546e-05f, 0.00032362897763960063f, 0.00015631354472134262f, 0.00046334537910297513f, 0.00019434592104516923f, 0.00016819496522657573f, 0.00020467076683416963f, 0.00019648073066491634f, 0.0003002419834956527f, 0.0009910279186442494f, 0.00027415412478148937f, 0.00015741726383566856f, 0.0004615318321157247f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #113 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_31_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0045663476921617985f, 0.008207128383219242f, 0.004874314647167921f, 0.006571772508323193f, 0.004303348250687122f, 0.011540509760379791f, 0.004229583311825991f, 0.006319655105471611f, 0.00790297333151102f, 0.0058362772688269615f, 0.00548142334446311f, 0.015899620950222015f, 0.004975026939064264f, 0.043720792979002f, 0.0057027824223041534f, 0.011454337276518345f, 0.006737587973475456f, 0.005775805097073317f, 0.024774199351668358f, 0.0032862334046512842f, 0.004458146635442972f, 0.013063528575003147f, 0.014272482134401798f, 0.005019041243940592f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #114 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_31_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001074434767360799f, 0.00019310890638735145f, 0.00011468975571915507f, 0.0001546299463370815f, 0.00010125525295734406f, 0.0002715414157137275f, 9.951960964826867e-05f, 0.00014869777078274637f, 0.00018595231813378632f, 0.00013732416846323758f, 0.00012897467240691185f, 0.000374108727555722f, 0.00011705946235451847f, 0.0010287245968356729f, 0.00013418312300927937f, 0.00026951381005346775f, 0.00015853148943278939f, 0.0001359012967441231f, 0.0005829223664477468f, 7.732314406894147e-05f, 0.00010489756823517382f, 0.0003073771367780864f, 0.0003358231042511761f, 0.00011809509305749089f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #115 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0011776804458349943f, 0.0004037426842842251f, 0.0005348826525732875f, 0.00027613886049948633f, 0.0006296328501775861f, 0.00043811791692860425f, 0.0007123667746782303f, 0.00036521308356896043f, 0.0007884754450060427f, 0.0011837392812594771f, 0.0005252768751233816f, 0.000830534438136965f, 0.0005328366532921791f, 0.000331339513650164f, 0.0005744522786699235f, 0.0005170212243683636f, 0.0008970506605692208f, 0.0014203331666067243f, 0.0004506683617364615f, 0.0002914780634455383f, 0.0005544549785554409f, 0.0006894746329635382f, 0.00017836310144048184f, 0.00038274427060969174f, 0.0005052023334428668f, 0.0005442531546577811f, 0.0002845748676918447f, 0.0002313867153134197f, 0.0005092133651487529f, 0.0007763687754049897f, 0.000637274410109967f, 0.000381108489818871f, 0.00045849831076338887f, 0.0009187087998725474f, 0.0003578097384888679f, 0.0009492915123701096f, 0.0006455691182054579f, 0.0007622113334946334f, 0.0005817704950459301f, 0.0017781974747776985f, 0.0005853264592587948f, 0.001028162078000605f, 0.00015066050400491804f, 0.0004716584808193147f, 0.0005423548282124102f, 0.00030267098918557167f, 0.000422101526055485f, 0.0007183443522080779f, 0.0008938902756199241f, 0.0008630540687590837f, 0.0007392840343527496f, 0.00045651610707864165f, 0.0008240387542173266f, 0.001122021465562284f, 0.0004640726838260889f, 0.00043375673703849316f, 0.0011729426914826035f, 0.0006178620387800038f, 0.000462418858660385f, 0.0007684617303311825f, 0.0004942419473081827f, 0.00047123373951762915f, 0.0003667633282020688f, 0.0011497909436002374f, 0.0010904662776738405f, 0.0005025615100748837f, 0.0015581214101985097f, 0.0003243310493417084f, 0.0008708321838639677f, 0.0004323418834246695f, 0.0007415488362312317f, 0.0008474374189972878f, 0.0003281614917796105f, 0.0008445996209047735f, 0.0005091553903184831f, 0.0005535787204280496f, 0.000386797240935266f, 0.0012204835657030344f, 0.0008182284072972834f, 0.0007653979118913412f, 0.000850080163218081f, 0.0006194284069351852f, 0.0009763605194166303f, 0.00029519994859583676f, 0.00034159483038820326f, 0.0008987790788523853f, 0.0005170188378542662f, 0.0009180443012155592f, 0.0007158532389439642f, 0.0003618164628278464f, 0.000547699979506433f, 0.0008890050230547786f, 0.0005712294951081276f, 0.0005022805999033153f, 0.00044846159289591014f, 0.0004141749523114413f, 0.00032066728454083204f, 0.0010232464410364628f, 0.0008595024701207876f, 0.0005295533919706941f, 0.0004176284419372678f, 0.0008569281199015677f, 0.00048152796807698905f, 0.001073247753083706f, 0.0006407828186638653f, 0.0008062729029916227f, 0.0008954264922067523f, 0.00035064120311290026f, 0.0008495295187458396f, 0.0002794390020426363f, 0.0010234463261440396f, 0.0007656392408534884f, 0.0007286456529982388f, 0.0012225417885929346f, 0.00026683276519179344f, 0.0004940031212754548f, 0.0005662672920152545f, 0.0010719976853579283f, 0.0009510234231129289f, 0.0012055527186021209f, 0.0002675652503967285f, 0.0004552258469630033f, 0.00039507460314780474f, 0.0003758381644729525f, 0.0006451192311942577f, 0.0005840121884830296f, 0.0009418222471140325f, 0.001266044331714511f, 0.00044855481246486306f, 0.00039936963003128767f, 0.0009314647177234292f, 0.000434167159255594f, 0.0009280982776544988f, 0.00018364950665272772f, 0.0011531782802194357f, 0.0007919804193079472f, 0.0006724105915054679f, 0.0010724607855081558f, 0.000542767287697643f, 0.00021385951549746096f, 0.0006849173805676401f, 0.0006874674581922591f, 0.0007540310616604984f, 0.0011605002218857408f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #116 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00022687016462441534f, 7.777760765748098e-05f, 0.00010304061288479716f, 5.319581032381393e-05f, 0.00012129343667766079f, 8.43997040647082e-05f, 0.0001372314291074872f, 7.035520684439689e-05f, 0.00015189310943242162f, 0.0002280373446410522f, 0.00010119014041265473f, 0.00015999542665667832f, 0.00010264646698487923f, 6.382974970620126e-05f, 0.0001106633644667454f, 9.95997543213889e-05f, 0.00017280920292250812f, 0.0002736151509452611f, 8.681743929628283e-05f, 5.6150780437747017e-05f, 0.00010681105050025508f, 0.00013282144209370017f, 3.4360138670308515e-05f, 7.373243715846911e-05f, 9.73229471128434e-05f, 0.00010484575614100322f, 5.4820935474708676e-05f, 4.457469185581431e-05f, 9.809563925955445e-05f, 0.00014956085942685604f, 0.00012276551569812f, 7.341732271015644e-05f, 8.83258180692792e-05f, 0.00017698146984912455f, 6.892901728861034e-05f, 0.00018287297280039638f, 0.00012436341785360128f, 0.00014683355402667075f, 0.00011207315401406959f, 0.00034255467471666634f, 0.00011275818542344496f, 0.00019806671480182558f, 2.902346932387445e-05f, 9.086100908461958e-05f, 0.00010448005923535675f, 5.8306999562773854e-05f, 8.131428330671042e-05f, 0.00013838295126333833f, 0.00017220039444509894f, 0.0001662600552663207f, 0.00014241680037230253f, 8.794396126177162e-05f, 0.0001587440783623606f, 0.00021614792058244348f, 8.939966937759891e-05f, 8.355955651495606e-05f, 0.00022595746850129217f, 0.00011902588448720053f, 8.908107702154666e-05f, 0.00014803763770032674f, 9.521152242086828e-05f, 9.077918366529047e-05f, 7.065384852467105e-05f, 0.00022149748110678047f, 0.00021006909082643688f, 9.68142194324173e-05f, 0.0003001588920596987f, 6.247963028727099e-05f, 0.00016775843687355518f, 8.328699914272875e-05f, 0.00014285309589467943f, 0.00016325163596775383f, 6.321752880467102e-05f, 0.00016270496416836977f, 9.808447066461667e-05f, 0.00010664224828360602f, 7.451321289408952e-05f, 0.00023511581821367145f, 0.00015762477414682508f, 0.0001474474265705794f, 0.00016376073472201824f, 0.00011932763300137594f, 0.0001880875788629055f, 5.686776785296388e-05f, 6.58053468214348e-05f, 0.0001731421798467636f, 9.95992959360592e-05f, 0.0001768534566508606f, 0.00013790305820293725f, 6.970087270019576e-05f, 0.0001055097600328736f, 0.00017125927843153477f, 0.00011004252155544236f, 9.676010085968301e-05f, 8.639232692075893e-05f, 7.978729263413697e-05f, 6.177383329486474e-05f, 0.00019711976347025484f, 0.00016557586786802858f, 0.00010201397526543587f, 8.045257709454745e-05f, 0.00016507993859704584f, 9.276228229282424e-05f, 0.00020675208361353725f, 0.0001234413794009015f, 0.00015532164252363145f, 0.000172496322193183f, 6.754805508535355e-05f, 0.00016365466581191868f, 5.383155439631082e-05f, 0.0001971582678379491f, 0.0001474939053878188f, 0.00014036741049494594f, 0.00023551231424789876f, 5.140307257534005e-05f, 9.51655165408738e-05f, 0.00010908659896813333f, 0.000206511263968423f, 0.00018320660456083715f, 0.0002322395157534629f, 5.1544178859330714e-05f, 8.769539999775589e-05f, 7.610777538502589e-05f, 7.240203558467329e-05f, 0.00012427674664650112f, 0.0001125049966503866f, 0.00018143407942261547f, 0.00024389271857216954f, 8.641028398415074e-05f, 7.693517545703799e-05f, 0.00017943877901416272f, 8.363862434634939e-05f, 0.00017879027291201055f, 3.5378521715756506e-05f, 0.0002221500180894509f, 0.00015256831829901785f, 0.00012953420809935778f, 0.00020660048176068813f, 0.00010455951996846125f, 4.119822187931277e-05f, 0.0001319435250479728f, 0.00013243478315416723f, 0.00014525769802276045f, 0.0002235605352325365f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #117 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00836492795497179f, 0.014070060104131699f, 0.006453193258494139f, 0.021933332085609436f, 0.0166841521859169f, 0.028062419965863228f, 0.008386832661926746f, 0.019275560975074768f, 0.010123775340616703f, 0.006217370741069317f, 0.008774293586611748f, 0.007251087110489607f, 0.015034465119242668f, 0.01870102994143963f, 0.021892163902521133f, 0.006161137484014034f, 0.005358723923563957f, 0.002164042554795742f, 0.008228235878050327f, 0.010322886519134045f, 0.013802813366055489f, 0.00803341530263424f, 0.020579570904374123f, 0.013792527839541435f, 0.01303122192621231f, 0.014343787916004658f, 0.026746680960059166f, 0.020637929439544678f, 0.029829882085323334f, 0.004185062367469072f, 0.004262350033968687f, 0.013466514647006989f, 0.0086037153378129f, 0.008451735600829124f, 0.01970864273607731f, 0.01044733077287674f, 0.008149852976202965f, 0.013217889703810215f, 0.010075517930090427f, 0.008557518944144249f, 0.011082423850893974f, 0.002310071839019656f, 0.04468061774969101f, 0.011451639235019684f, 0.01049340795725584f, 0.007151275407522917f, 0.009666997008025646f, 0.007098295260220766f, 0.00404469994828105f, 0.021494820713996887f, 0.00481556449085474f, 0.019170545041561127f, 0.0073554180562496185f, 0.007066435180604458f, 0.006508523132652044f, 0.020907815545797348f, 0.007669181562960148f, 0.0074005392380058765f, 0.010420876555144787f, 0.009681693278253078f, 0.00889077503234148f, 0.02011987939476967f, 0.014465357176959515f, 0.03379543125629425f, 0.007061134558171034f, 0.0020590471103787422f, 0.006515149027109146f, 0.01414902787655592f, 0.007612175308167934f, 0.010114717297255993f, 0.007715405430644751f, 0.004727990832179785f, 0.014546711929142475f, 0.018193120136857033f, 0.015656055882573128f, 0.00233462848700583f, 0.01059067901223898f, 0.010321969166398048f, 0.004620647523552179f, 0.007715366315096617f, 0.003233712399378419f, 0.012101231142878532f, 0.011327587068080902f, 0.01017846167087555f, 0.007241315208375454f, 0.00607293238863349f, 0.007047845050692558f, 0.0019458996830508113f, 0.007022223435342312f, 0.014023752883076668f, 0.0038240370340645313f, 0.006312617566436529f, 0.008644606918096542f, 0.010456718504428864f, 0.01502602081745863f, 0.02477206662297249f, 0.014487734995782375f, 0.008427819237112999f, 0.0059727830812335014f, 0.00748531986027956f, 0.012437677010893822f, 0.004001901019364595f, 0.023220142349600792f, 0.015648363158106804f, 0.01725899614393711f, 0.004064996261149645f, 0.008435430936515331f, 0.022911643609404564f, 0.007425266783684492f, 0.0196414552628994f, 0.004416623618453741f, 0.013792462646961212f, 0.008541003800928593f, 0.002686538267880678f, 0.012061862275004387f, 0.009832469746470451f, 0.024128425866365433f, 0.00830219965428114f, 0.009299734607338905f, 0.004522612784057856f, 0.014037083834409714f, 0.01172499731183052f, 0.009676622226834297f, 0.011098639108240604f, 0.01464095152914524f, 0.016577117145061493f, 0.0036611047107726336f, 0.003356741974130273f, 0.013529435731470585f, 0.004280958790332079f, 0.013838893733918667f, 0.01007607951760292f, 0.005846401210874319f, 0.026658326387405396f, 0.008472923189401627f, 0.009741820394992828f, 0.0036106330808252096f, 0.007785445544868708f, 0.011846733279526234f, 0.01560656726360321f, 0.008525923825800419f, 0.0060715810395777225f, 0.00598888611420989f, 0.0014929419849067926f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #118 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00019682184210978448f, 0.0003310602332931012f, 0.0001518398494226858f, 0.0005160784348845482f, 0.00039256829768419266f, 0.0006602922221645713f, 0.00019733724184334278f, 0.0004535426269285381f, 0.00023820648493710905f, 0.00014629107317887247f, 0.00020645397307816893f, 0.00017061381367966533f, 0.000353752140654251f, 0.00044002424692735076f, 0.0005151097429916263f, 0.0001449679402867332f, 0.00012608763063326478f, 5.0918650231324136e-05f, 0.00019360554870218039f, 0.00024289145949296653f, 0.00032477208878844976f, 0.00018902153533417732f, 0.0004842251946683973f, 0.00032453006133437157f, 0.00030661700293421745f, 0.00033750091097317636f, 0.0006293336628004909f, 0.00048559834249317646f, 0.0007018796168267727f, 9.847206092672423e-05f, 0.00010029059194494039f, 0.00031685916474089026f, 0.00020244036568328738f, 0.0001988643780350685f, 0.0004637327801901847f, 0.00024581956677138805f, 0.0001917612535180524f, 0.00031100917840376496f, 0.00023707101354375482f, 0.0002013533958233893f, 0.000260762928519398f, 5.435463390313089e-05f, 0.001051308703608811f, 0.0002694503345992416f, 0.00024690371355973184f, 0.00016826530918478966f, 0.00022745876049157232f, 0.0001670187193667516f, 9.516940917819738e-05f, 0.000505760486703366f, 0.00011330740380799398f, 0.0004510716535151005f, 0.0001730686635710299f, 0.00016626906290184706f, 0.00015314172196667641f, 0.000491948623675853f, 0.00018045133037958294f, 0.0001741303422022611f, 0.00024519709404557943f, 0.000227804557653144f, 0.00020919470989611f, 0.00047340893070213497f, 0.000340361351845786f, 0.0007951866136863828f, 0.00016614435298833996f, 4.844816794502549e-05f, 0.00015329763118643314f, 0.00033291830914095044f, 0.00017911000759340823f, 0.0002379933575866744f, 0.0001815389550756663f, 0.00011124684533569962f, 0.00034227556898258626f, 0.00042807342833839357f, 0.0003683778049889952f, 5.493243588716723e-05f, 0.0002491924387868494f, 0.00024286986445076764f, 0.00010872112034121528f, 0.00018153803830500692f, 7.608735177200288e-05f, 0.00028473485144786537f, 0.0002665314532350749f, 0.00023949322348926216f, 0.00017038389341905713f, 0.0001428925315849483f, 0.00016583164688199759f, 4.578587686410174e-05f, 0.0001652287901379168f, 0.00032997067319229245f, 8.9977344032377e-05f, 0.0001485321845393628f, 0.00020340252376627177f, 0.0002460404357407242f, 0.00035355344880372286f, 0.0005828721914440393f, 0.0003408878983464092f, 0.0001983016263693571f, 0.00014053608174435794f, 0.00017612517694942653f, 0.0002926512388512492f, 9.416238026460633e-05f, 0.0005463563138619065f, 0.0003681967791635543f, 0.00040609404095448554f, 9.564697393216193e-05f, 0.00019848073134198785f, 0.0005390975275076926f, 0.00017471215687692165f, 0.0004621518892236054f, 0.00010392055992269889f, 0.0003245285479351878f, 0.00020096480147913098f, 6.321266846498474e-05f, 0.00028380853473208845f, 0.00023135222727432847f, 0.0005677276640199125f, 0.00019534588500391692f, 0.00021881729480810463f, 0.00010641442349879071f, 0.00033028432517312467f, 0.00027588228113017976f, 0.0002276852319482714f, 0.0002611444506328553f, 0.0003444929898250848f, 0.00039004982681944966f, 8.614364196546376e-05f, 7.89821642683819e-05f, 0.0003183396765962243f, 0.00010072844452224672f, 0.0003256210475228727f, 0.00023708422668278217f, 0.00013756238331552595f, 0.0006272547761909664f, 0.0001993628975469619f, 0.00022921930940356106f, 8.495607471559197e-05f, 0.00018318695947527885f, 0.0002787466801237315f, 0.0003672133607324213f, 0.00020060998213011771f, 0.00014286073565017432f, 0.00014091496996115893f, 3.512804687488824e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #119 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_35_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009081311523914337f, 0.008582252077758312f, 0.005189377814531326f, 0.008091994561254978f, 0.00393270468339324f, 0.008352714590728283f, 0.0052671292796730995f, 0.0173746757209301f, 0.006067902781069279f, 0.007369948085397482f, 0.0068389298394322395f, 0.01290169544517994f, 0.00460804533213377f, 0.017129451036453247f, 0.006304414942860603f, 0.01058055181056261f, 0.008176603354513645f, 0.006401443853974342f, 0.0161251462996006f, 0.004500280134379864f, 0.0038471573498100042f, 0.015176872722804546f, 0.022200901061296463f, 0.005816006101667881f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #120 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_35_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00021367792214732617f, 0.0002019353414652869f, 0.00012210301065351814f, 0.000190399878192693f, 9.253423195332289e-05f, 0.0001965344708878547f, 0.0001239324628841132f, 0.00040881591849029064f, 0.000142774180858396f, 0.00017341054626740515f, 0.00016091599536594003f, 0.0003035693080164492f, 0.00010842459596460685f, 0.00040304590947926044f, 0.00014833918248768896f, 0.0002489541657269001f, 0.00019239066750742495f, 0.0001506222179159522f, 0.00037941522896289825f, 0.00010588894656393677f, 9.052135283127427e-05f, 0.0003571028937585652f, 0.0005223741754889488f, 0.0001368472003377974f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #121 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00029393285512924194f, 0.00034228904405608773f, 0.0002549909695517272f, 0.0008397279307246208f, 0.0009536208235658705f, 0.0003294196503702551f, 0.0013333065435290337f, 0.0011024586856365204f, 0.0007289619534276426f, 0.0008881277753971517f, 0.0004475513123907149f, 0.00018886943871621042f, 0.0004166718863416463f, 0.0006632176227867603f, 0.0006031595403328538f, 0.0009344384889118373f, 0.0006157798343338072f, 0.0002771342115011066f, 0.00037244425038807094f, 0.0004887363757006824f, 0.0010241821873933077f, 0.00018466963956598192f, 0.00017261724860873073f, 0.0006631763535551727f, 0.001049115788191557f, 0.00060043710982427f, 0.0009917295537889004f, 0.0005267217638902366f, 0.0007339281728491187f, 0.0006926216883584857f, 0.0008856974309310317f, 0.0005285033257678151f, 0.0005576799158006907f, 0.0010188098531216383f, 0.0007282419828698039f, 0.00024109829973895103f, 0.0004584860580507666f, 0.0007359073497354984f, 0.00020907064026687294f, 0.00022053960128687322f, 0.0009450422367081046f, 0.0010993600590154529f, 0.0007038641488179564f, 0.0011990608181804419f, 0.0008466744911856949f, 0.0006677649798803031f, 0.0006330789183266461f, 0.0006612528814002872f, 0.0006404190789908171f, 0.000769194564782083f, 0.0013199648819863796f, 0.0007040327764116228f, 0.0010545006953179836f, 0.0012784500140696764f, 0.0006561818881891668f, 0.0008309229742735624f, 0.0004804053751286119f, 0.00030711706494912505f, 0.000984277343377471f, 0.0006336889928206801f, 0.0004962208331562579f, 0.0005182154127396643f, 0.001451390329748392f, 0.0006774036446586251f, 0.0009062322787940502f, 0.0010184437269344926f, 0.0005231270333752036f, 0.0008196101989597082f, 0.0009150585392490029f, 0.0005648407386615872f, 0.0006971711409278214f, 0.0003836097603198141f, 0.0003324032586533576f, 0.0005048750317655504f, 9.372541535412893e-05f, 0.0012528625084087253f, 0.0011193974642083049f, 0.0002518193796277046f, 0.0006227511912584305f, 0.0005253161652944982f, 0.0004566200659610331f, 0.0007139265653677285f, 0.0011224212357774377f, 0.0003255452902521938f, 0.001005464349873364f, 0.0005062285345047712f, 0.0006124887731857598f, 0.0007773319957777858f, 0.0010244682198390365f, 0.0007787150098010898f, 0.0005639722803607583f, 0.0010323544265702367f, 0.0006602515932172537f, 0.0005131205543875694f, 0.0004354700504336506f, 0.00040703703416511416f, 0.00023854275059420615f, 0.0009848818881437182f, 0.0006347274756990373f, 0.0006112838163971901f, 0.0006317395600490272f, 0.0009110806277021766f, 0.0009340764372609556f, 0.0008142715669237077f, 0.0004129972367081791f, 0.000756645284127444f, 0.00034733457141555846f, 0.00045445069554261863f, 0.0004970405716449022f, 0.0009882670128718019f, 0.0009241259540431201f, 0.0008384489919990301f, 0.0004584909765981138f, 0.00040448448271490633f, 0.00046996521996334195f, 0.0007365642231889069f, 0.00036630197428166866f, 0.0008936840458773077f, 0.0006010880460962653f, 0.0011875252239406109f, 0.0002985980245284736f, 0.0006199152558110654f, 0.00048212159890681505f, 0.00020820491772610694f, 0.0005005451384931803f, 0.0005666133365593851f, 0.0014767460525035858f, 0.0009913303656503558f, 0.0006407680921256542f, 0.0006288741715252399f, 0.0003834421222563833f, 0.0007491419673897326f, 0.0006447980413213372f, 0.00031329694320447743f, 0.0007986676064319909f, 0.0003133982827421278f, 0.000685062725096941f, 0.0009385173325426877f, 0.0016685310984030366f, 0.0010281983995810151f, 0.0001943746319739148f, 0.0006403842126019299f, 0.00033383723348379135f, 0.0010637241648510098f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #122 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(6.266446871450171e-05f, 7.29736711946316e-05f, 5.436232459032908e-05f, 0.000179024224053137f, 0.00020330540428403765f, 7.023000944172964e-05f, 0.0002842517860699445f, 0.00023503662669099867f, 0.00015540968161076307f, 0.00018934273975901306f, 9.541486360831186e-05f, 4.0265666029881686e-05f, 8.883158443495631e-05f, 0.00014139343693386763f, 0.00012858946865890175f, 0.00019921586499549448f, 0.0001312800304731354f, 5.908311140956357e-05f, 7.940255454741418e-05f, 0.00010419524187454954f, 0.0002183486067224294f, 3.9370297599816695e-05f, 3.6800811358261853e-05f, 0.0001413846475770697f, 0.00022366427583619952f, 0.00012800906552001834f, 0.00021142992773093283f, 0.00011229346273466945f, 0.0001564684498589486f, 0.00014766218373551965f, 0.00018882460426539183f, 0.00011267328227404505f, 0.00011889352754224092f, 0.00021720326913055032f, 0.00015525618800893426f, 5.1400500524323434e-05f, 9.774608042789623e-05f, 0.00015689039719291031f, 4.457242539501749e-05f, 4.7017529141157866e-05f, 0.0002014765195781365f, 0.0002343760133953765f, 0.0001500590005889535f, 0.0002556315448600799f, 0.00018050518701784313f, 0.0001423629146302119f, 0.00013496808242052794f, 0.00014097457460593432f, 0.00013653295172844082f, 0.00016398700245190412f, 0.00028140743961557746f, 0.0001500949583714828f, 0.00022481230553239584f, 0.00027255676104687154f, 0.00013989346916787326f, 0.00017714707064442337f, 0.00010241912968922406f, 6.547525117639452e-05f, 0.00020984116417821497f, 0.00013509814743883908f, 0.00010579087393125519f, 0.0001104799666791223f, 0.00030942645389586687f, 0.0001444178051315248f, 0.0001932025043061003f, 0.00021712521265726537f, 0.00011152709339512512f, 0.0001747352653183043f, 0.0001950841979123652f, 0.00012042016896884888f, 0.00014863209798932076f, 8.178296411642805e-05f, 7.086609548423439e-05f, 0.00010763588943518698f, 1.9981614968855865e-05f, 0.00026710168458521366f, 0.00023864785907790065f, 5.36861625732854e-05f, 0.00013276627578306943f, 0.0001119938024203293f, 9.734826016938314e-05f, 0.00015220424393191934f, 0.00023929249437060207f, 6.940402090549469e-05f, 0.00021435809321701527f, 0.00010792444663820788f, 0.00013057839532848448f, 0.00016572183812968433f, 0.00021840959379915148f, 0.0001660166890360415f, 0.00012023501767544076f, 0.0002200908784288913f, 0.0001407611125614494f, 0.00010939377534668893f, 9.283922554459423e-05f, 8.677750156493858e-05f, 5.085567681817338e-05f, 0.0002099700504913926f, 0.00013531954027712345f, 0.00013032151036895812f, 0.0001346825301880017f, 0.0001942361268447712f, 0.00019913868163712323f, 0.00017359710182063282f, 8.804817480267957e-05f, 0.00016131157462950796f, 7.404934876831248e-05f, 9.688577119959518e-05f, 0.00010596563515719026f, 0.00021069173817522824f, 0.0001970173034351319f, 0.0001787515648175031f, 9.774712816579267e-05f, 8.623331086710095e-05f, 0.00010019335604738444f, 0.0001570304302731529f, 7.809306407580152e-05f, 0.0001905273093143478f, 0.00012814784713555127f, 0.000253172212978825f, 6.36590484646149e-05f, 0.00013216167280916125f, 0.0001027850157697685f, 4.4387859816197306e-05f, 0.00010671278869267553f, 0.00012079807493137196f, 0.0003148321120534092f, 0.00021134482813067734f, 0.00013660735567100346f, 0.00013407165533863008f, 8.174722461262718e-05f, 0.00015971192624419928f, 0.00013746651529800147f, 6.679275975329801e-05f, 0.00017027044668793678f, 6.681436207145452e-05f, 0.00014605067553929985f, 0.000200085443793796f, 0.00035571938497014344f, 0.0002192048414144665f, 4.1439336200710386e-05f, 0.00013652551569975913f, 7.117180939530954e-05f, 0.00022677869128528982f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #123 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.016126779839396477f, 0.012528028339147568f, 0.01951306313276291f, 0.004206305369734764f, 0.009113007225096226f, 0.020099470391869545f, 0.010268145240843296f, 0.003959461580961943f, 0.01320333406329155f, 0.004593660589307547f, 0.017443448305130005f, 0.020983923226594925f, 0.009291596710681915f, 0.017156001180410385f, 0.0025222396943718195f, 0.006421826314181089f, 0.010328288190066814f, 0.01598242297768593f, 0.025930071249604225f, 0.00848330557346344f, 0.006127724889665842f, 0.027263058349490166f, 0.012320466339588165f, 0.017057016491889954f, 0.003460547188296914f, 0.030332021415233612f, 0.011883334256708622f, 0.008765245787799358f, 0.005834826268255711f, 0.0126646114513278f, 0.0019319017883390188f, 0.01043375302106142f, 0.01614988222718239f, 0.008159435354173183f, 0.008172345347702503f, 0.032624855637550354f, 0.00534247187897563f, 0.005658916663378477f, 0.024607570841908455f, 0.012738848105072975f, 0.0026034489274024963f, 0.01318049244582653f, 0.006453590467572212f, 0.007058267947286367f, 0.006048867944628f, 0.007886655628681183f, 0.01065436564385891f, 0.007794835139065981f, 0.005977541673928499f, 0.005754138343036175f, 0.007162315305322409f, 0.007889795117080212f, 0.008091102354228497f, 0.006018890533596277f, 0.005146247800439596f, 0.006075557321310043f, 0.015744484961032867f, 0.028680872172117233f, 0.013038947246968746f, 0.004883231595158577f, 0.03328275680541992f, 0.010126728564500809f, 0.005141190718859434f, 0.015984147787094116f, 0.0017126090824604034f, 0.005935658700764179f, 0.011891732923686504f, 0.004305751994252205f, 0.025918759405612946f, 0.007981550879776478f, 0.007542959880083799f, 0.02415340207517147f, 0.008521011099219322f, 0.012745914049446583f, 0.014906722120940685f, 0.005401242058724165f, 0.006085771135985851f, 0.021371202543377876f, 0.019562209025025368f, 0.0034399523865431547f, 0.008167685009539127f, 0.014065604656934738f, 0.013262545689940453f, 0.014440231956541538f, 0.00257849576883018f, 0.009139467030763626f, 0.003944419790059328f, 0.00839013047516346f, 0.002965380437672138f, 0.008275258354842663f, 0.007460948545485735f, 0.0028564599342644215f, 0.035005293786525726f, 0.01629830151796341f, 0.013903333805501461f, 0.02536703273653984f, 0.01575733907520771f, 0.010761580429971218f, 0.00813224259763956f, 0.01847911812365055f, 0.01826734095811844f, 0.013710705563426018f, 0.006598546635359526f, 0.011805536225438118f, 0.011611723341047764f, 0.004691040143370628f, 0.008954551070928574f, 0.0070309326983988285f, 0.00916466023772955f, 0.0026619473937898874f, 0.005248077679425478f, 0.018088895827531815f, 0.0178472138941288f, 0.01335449144244194f, 0.011009431444108486f, 0.006521504372358322f, 0.013250540010631084f, 0.006386336404830217f, 0.008717643097043037f, 0.009818753227591515f, 0.018702050670981407f, 0.005311581771820784f, 0.014181283302605152f, 0.023833947256207466f, 0.023148393258452415f, 0.0054389359429478645f, 0.00448274239897728f, 0.01117824949324131f, 0.007845010608434677f, 0.015142453834414482f, 0.007768690586090088f, 0.004007655195891857f, 0.01578916795551777f, 0.011877201497554779f, 0.007444259710609913f, 0.015670863911509514f, 0.04201160743832588f, 0.010317418724298477f, 0.002561556175351143f, 0.002811175538226962f, 0.03805868327617645f, 0.010530238971114159f, 0.009477588348090649f, 0.005881123244762421f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #124 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00037945364601910114f, 0.0002947771572507918f, 0.00045913091162219644f, 9.897189011098817e-05f, 0.00021442370780277997f, 0.00047292871749959886f, 0.0002416034258203581f, 9.316380601376295e-05f, 0.0003106666845269501f, 0.00010808613296831027f, 0.00041043409146368504f, 0.0004937393823638558f, 0.00021862580615561455f, 0.00040367062320001423f, 5.934681757935323e-05f, 0.0001511018053861335f, 0.0002430185559205711f, 0.0003760570252779871f, 0.0006101193139329553f, 0.00019960719509981573f, 0.00014418175851460546f, 0.0006414837553165853f, 0.0002898933307733387f, 0.00040134156006388366f, 8.142463775584474e-05f, 0.0007136946078389883f, 0.00027960786246694624f, 0.00020624107855837792f, 0.00013729002967011184f, 0.00029799086041748524f, 4.545651245280169e-05f, 0.00024550006492063403f, 0.000379997247364372f, 0.00019198672089260072f, 0.00019229047757107764f, 0.0007676436798647046f, 0.00012570522085297853f, 0.00013315098476596177f, 0.0005790016730315983f, 0.0002997376141138375f, 6.125762593001127e-05f, 0.0003101292531937361f, 0.0001518491917522624f, 0.00016607689030934125f, 0.00014232630201149732f, 0.00018556836585048586f, 0.00025069096591323614f, 0.00018340788665227592f, 0.000140648044180125f, 0.00013539149949792773f, 0.00016852507542353123f, 0.00018564224592410028f, 0.00019037887977901846f, 0.00014162095612846315f, 0.00012108818918932229f, 0.0001429542899131775f, 0.00037045846693217754f, 0.0006748440791852772f, 0.00030679875635541975f, 0.00011489957250887528f, 0.0007831237162463367f, 0.0002382759703323245f, 0.00012096919817849994f, 0.0003760975960176438f, 4.029668343719095e-05f, 0.00013966255937702954f, 0.00027980547747574747f, 0.00010131181625183672f, 0.0006098531885072589f, 0.00018780119717121124f, 0.00017748141544871032f, 0.0005683153285644948f, 0.00020049438171554357f, 0.00029990385519340634f, 0.00035074641346000135f, 0.00012708804570138454f, 0.00014319461479317397f, 0.0005028518498875201f, 0.00046028729411773384f, 8.094005897874013e-05f, 0.0001921808288898319f, 0.00033095540129579604f, 0.0003120599139947444f, 0.00033977016573771834f, 6.0670488892355934e-05f, 0.0002150462823919952f, 9.280988160753623e-05f, 0.00019741483265534043f, 6.977366138016805e-05f, 0.00019471195992082357f, 0.00017555172962602228f, 6.721082172589377e-05f, 0.0008236540015786886f, 0.00038348944508470595f, 0.00032713726977817714f, 0.0005968713667243719f, 0.0003707609139382839f, 0.00025321365683339536f, 0.00019134688773192465f, 0.0004348027869127691f, 0.0004298198036849499f, 0.00032260484294965863f, 0.00015525992785114795f, 0.00027777731884270906f, 0.00027321703964844346f, 0.000110377419332508f, 0.00021069531794637442f, 0.00016543371020816267f, 0.00021563906921073794f, 6.263405521167442e-05f, 0.00012348417658358812f, 0.0004256210813764483f, 0.0004199344548396766f, 0.0003142233472317457f, 0.0002590454532764852f, 0.00015344716666731983f, 0.00031177743221633136f, 0.00015026674373075366f, 0.00020512101764325052f, 0.00023102949489839375f, 0.00044004825758747756f, 0.0001249783963430673f, 0.0003336772497277707f, 0.0005607987986877561f, 0.0005446680588647723f, 0.00012797497038263828f, 0.00010547629062784836f, 0.0002630176313687116f, 0.00018458848353475332f, 0.0003562930505722761f, 0.00018279271898791194f, 9.429777128389105e-05f, 0.00037150984280742705f, 0.00027946356567554176f, 0.00017515906074550003f, 0.00036872620694339275f, 0.000988508458249271f, 0.0002427627914585173f, 6.0271911934250966e-05f, 6.61453086649999e-05f, 0.0008954984368756413f, 0.000247770338319242f, 0.00022300207638181746f, 0.00013837937149219215f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #125 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00753632839769125f, 0.008019995875656605f, 0.0067336950451135635f, 0.005868542939424515f, 0.00482900720089674f, 0.008653054013848305f, 0.0057270098477602005f, 0.02432941272854805f, 0.007582750637084246f, 0.004557856824249029f, 0.008644452318549156f, 0.010195615701377392f, 0.0051389094442129135f, 0.01878167688846588f, 0.00564588513225317f, 0.011415651068091393f, 0.0064653619192540646f, 0.006628744304180145f, 0.020462773740291595f, 0.005341097246855497f, 0.006616700906306505f, 0.025069810450077057f, 0.028801050037145615f, 0.0077012283727526665f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #126 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00017732537526171654f, 0.0001887057878775522f, 0.00015843988512642682f, 0.00013808337098453194f, 0.00011362370423739776f, 0.0002036012738244608f, 0.0001347531797364354f, 0.0005724568036384881f, 0.00017841767112258822f, 0.00010724369349190965f, 0.00020339888578746468f, 0.00023989684996195138f, 0.00012091551616322249f, 0.0004419218166731298f, 0.00013284436136018485f, 0.00026860355865210295f, 0.00015212617290671915f, 0.00015597045421600342f, 0.00048147703637368977f, 0.00012567287194542587f, 0.00015568708477076143f, 0.0005898778908886015f, 0.0006776718073524535f, 0.00018120538152288646f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #127 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008113232324831188f, 0.0010775492992252111f, 0.0005723476060666144f, 0.0005991226062178612f, 0.0005695565487258136f, 0.000216620959690772f, 0.0005635196575894952f, 0.0007562107057310641f, 0.00036004625144414604f, 0.0007292486843653023f, 0.0006705644773319364f, 0.0008619209984317422f, 0.000840610999148339f, 0.0011124180164188147f, 0.0008973948424682021f, 0.0006878897547721863f, 0.0010445098159834743f, 0.0004966605338267982f, 0.0008466296130791306f, 0.001007533515803516f, 0.0009211412398144603f, 0.0008542484138160944f, 0.0008827652782201767f, 0.0004457172763068229f, 0.0005492367199622095f, 0.0011834970209747553f, 0.0008028554730117321f, 0.00032605533488094807f, 0.0008094653603620827f, 0.0009527849615551531f, 0.0008204763289541006f, 0.0016063262009993196f, 0.001053839223459363f, 0.0007532924646511674f, 0.000439555908087641f, 0.0010581195820122957f, 0.0007339760777540505f, 0.0008233464322984219f, 0.0013385368511080742f, 0.0010147790890187025f, 0.0005099226837046444f, 0.0008318627951666713f, 0.0005092656356282532f, 0.0009151046397164464f, 0.000905409106053412f, 0.0011860650265589356f, 0.0017066756263375282f, 0.0005550682544708252f, 0.000514390179887414f, 0.0007766901981085539f, 0.0005007683648727834f, 0.0006554853171110153f, 0.000437646551290527f, 0.0010441463673487306f, 0.00060150126228109f, 0.0003157711762469262f, 0.0006524514174088836f, 0.001402502995915711f, 0.0007123181130737066f, 0.0008592941449023783f, 0.0015896187396720052f, 0.0008488030289299786f, 0.000896283017937094f, 0.0009491632226854563f, 0.0007608009618707001f, 0.00026909320149570704f, 0.0009162002825178206f, 0.0009112415718846023f, 0.0008256775327026844f, 0.0018196996534243226f, 0.0007441292982548475f, 0.001052745385095477f, 0.0005630339146591723f, 0.0005592163070105016f, 0.0006325563881546259f, 0.0008976783719845116f, 0.0012618321925401688f, 0.0007584310369566083f, 0.0008813321474008262f, 0.0007691272767260671f, 0.00038797230808995664f, 0.0002951848437078297f, 0.0010764754842966795f, 0.0008863614057190716f, 0.0007648873142898083f, 0.00063175248214975f, 0.0009947698563337326f, 0.0007322739693336189f, 0.0015254851896315813f, 0.0009563983767293394f, 0.0006792198400944471f, 0.0008939726394601166f, 0.0006772967171855271f, 0.0008244588389061391f, 0.0006576509913429618f, 0.0006155837909318507f, 0.00048028549645096064f, 0.0010785897029563785f, 0.0003330846084281802f, 0.0005879493546672165f, 0.001291125314310193f, 0.0009774758946150541f, 0.0005699036410078406f, 0.0003486775967758149f, 0.0011401113588362932f, 0.0007246094755828381f, 0.0003114966384600848f, 0.0008546321769244969f, 0.0009993676794692874f, 0.0008321625064127147f, 0.0006647011614404619f, 0.0006660241633653641f, 0.0009249746799468994f, 0.0007223795400932431f, 0.0008455723291262984f, 0.00047298549907281995f, 0.0007365786004811525f, 0.0005878127412870526f, 0.0007805165369063616f, 0.0010107239941135049f, 0.00093432841822505f, 0.0003556467709131539f, 0.000744287041015923f, 0.00073562579927966f, 8.918435196392238e-05f, 0.0006522646290250123f, 0.000863214663695544f, 0.00040231048478744924f, 0.000933731731493026f, 0.0009674594621174037f, 0.0005159183638170362f, 0.0008207346545532346f, 0.0008078076643869281f, 0.0006354910437949002f, 0.0003875376423820853f, 0.0012079855659976602f, 0.0005167658673599362f, 0.0010282461298629642f, 0.0004058095801156014f, 0.0004213530628476292f, 0.0007244300213642418f, 0.0006180170457810163f, 0.0008321877103298903f, 0.0013572543393820524f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #128 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00020658760331571102f, 0.00027437685639597476f, 0.00014573712542187423f, 0.0001525548577774316f, 0.00014502643898595124f, 5.5158292525447905e-05f, 0.00014348926197271794f, 0.00019255427469033748f, 9.167873940896243e-05f, 0.00018568891391623765f, 0.00017074613424483687f, 0.00021947133063804358f, 0.00021404515428002924f, 0.0002832555037457496f, 0.00022850405366625637f, 0.00017515767831355333f, 0.0002659639867488295f, 0.0001264648890355602f, 0.00021557767468038946f, 0.0002565487229730934f, 0.00023455060727428645f, 0.00021751764870714396f, 0.00022477892343886197f, 0.00011349318810971454f, 0.00013985238911118358f, 0.0003013543609995395f, 0.0002044314460363239f, 8.302361675305292e-05f, 0.00020611452055163682f, 0.0002426080609438941f, 0.00020891825261060148f, 0.0004090195579919964f, 0.0002683395578060299f, 0.00019181119569111615f, 0.00011192431702511385f, 0.00026942946715280414f, 0.0001868926628958434f, 0.0002096490643452853f, 0.00034083222271874547f, 0.0002583936438895762f, 0.00012984183558728546f, 0.00021181759075261652f, 0.00012967453221790493f, 0.0002330135030206293f, 0.00023054472694639117f, 0.0003020082658622414f, 0.0004345715860836208f, 0.00014133728109300137f, 0.00013097940245643258f, 0.00019776896806433797f, 0.00012751086615025997f, 0.0001669065241003409f, 0.00011143813753733411f, 0.00026587146567180753f, 0.0001531605375930667f, 8.040495595196262e-05f, 0.00016613399202469736f, 0.0003571199777070433f, 0.00018137787992600352f, 0.0002188024518545717f, 0.0004047653346788138f, 0.00021613109856843948f, 0.0002282209461554885f, 0.00024168584786821157f, 0.0001937230845214799f, 6.85193226672709e-05f, 0.00023329249233938754f, 0.0002320298517588526f, 0.00021024263696745038f, 0.00046335093793459237f, 0.00018947797070723027f, 0.000268061034148559f, 0.00014336557069327682f, 0.00014239350275602192f, 0.00016106812108773738f, 0.0002285762457177043f, 0.0003213009040337056f, 0.00019311963114887476f, 0.0002244140050606802f, 0.0001958432258106768f, 9.878956188913435e-05f, 7.516305049648508e-05f, 0.00027410342590883374f, 0.00022569460270460695f, 0.00019476360466796905f, 0.00016086341929621994f, 0.00025329869822598994f, 0.0001864592486526817f, 0.00038843497168272734f, 0.00024352814943995327f, 0.00017295005091000348f, 0.0002276326558785513f, 0.0001724603644106537f, 0.00020993231737520546f, 0.00016745796892791986f, 0.00015674637688789517f, 0.000122295314213261f, 0.0002746417885646224f, 8.48134804982692e-05f, 0.0001497098128311336f, 0.00032875980832614005f, 0.0002488951140549034f, 0.00014511481276713312f, 8.878393418854102e-05f, 0.0002903070708271116f, 0.00018450763309374452f, 7.931653090054169e-05f, 0.00021761537936981767f, 0.0002544694289099425f, 0.0002118939155479893f, 0.0001692531513981521f, 0.0001695900282356888f, 0.00023552672064397484f, 0.00018393983191344887f, 0.00021530846424866468f, 0.00012043651076965034f, 0.00018755534256342798f, 0.00014967501920182258f, 0.00019874327699653804f, 0.0002573610981926322f, 0.0002379084617132321f, 9.055849659489468e-05f, 0.0001895181485451758f, 0.00018731271848082542f, 2.2709051336278208e-05f, 0.00016608643636573106f, 0.00021980074234306812f, 0.00010244049917673692f, 0.00023775652516633272f, 0.000246344628976658f, 0.0001313685206696391f, 0.0002089840272674337f, 0.0002056924276985228f, 0.00016181536193471402f, 9.867888002190739e-05f, 0.0003075899148825556f, 0.0001315843255724758f, 0.0002618227736093104f, 0.00010333147656638175f, 0.0001072893210221082f, 0.00018446194007992744f, 0.00015736595378257334f, 0.00021190033294260502f, 0.0003455982659943402f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #129 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003426330629736185f, 0.007337741553783417f, 0.0022055439185351133f, 0.002627730369567871f, 0.0072287097573280334f, 0.015240880660712719f, 0.006955714430660009f, 0.006173917092382908f, 0.011643859557807446f, 0.006982831284403801f, 0.006074688397347927f, 0.003766733920201659f, 0.004990074317902327f, 0.005277811083942652f, 0.007054150570183992f, 0.005762411747127771f, 0.0015428494662046432f, 0.010752116329967976f, 0.003856804920360446f, 0.0071332729421556f, 0.006158594973385334f, 0.0034771414939314127f, 0.006197480484843254f, 0.01307518221437931f, 0.005466182250529528f, 0.008664114400744438f, 0.005146163981407881f, 0.009896795265376568f, 0.0017814460443332791f, 0.0025455693248659372f, 0.0055694314651191235f, 0.006349945906549692f, 0.0053838882595300674f, 0.0029453556053340435f, 0.009492723271250725f, 0.001093109487555921f, 0.0010434252908453345f, 0.008069498464465141f, 0.0012730777962133288f, 0.0058286008425056934f, 0.004007855895906687f, 0.006626976653933525f, 0.008721551857888699f, 0.0061093769036233425f, 0.0020343849901109934f, 0.005819076206535101f, 0.00542138097807765f, 0.008535653352737427f, 0.012956292368471622f, 0.0011189653305336833f, 0.009922818280756474f, 0.007764161564409733f, 0.010837426409125328f, 0.0027795007918030024f, 0.016232743859291077f, 0.01150276605039835f, 0.00724836764857173f, 0.005395311396569014f, 0.006323385518044233f, 0.007527498062700033f, 0.0021865670569241047f, 0.0014485473511740565f, 0.008648972027003765f, 0.003656314918771386f, 0.004047154448926449f, 0.005967660807073116f, 0.00670055765658617f, 0.006631696596741676f, 0.00851911585777998f, 0.004774108994752169f, 0.0015924948966130614f, 0.0028983219526708126f, 0.00873593706637621f, 0.0053013963624835014f, 0.010617414489388466f, 0.001196523429825902f, 0.005802513565868139f, 0.005286060273647308f, 0.0056159840896725655f, 0.006355565972626209f, 0.017565302550792694f, 0.007498355582356453f, 0.0055343834683299065f, 0.003420287976041436f, 0.0033085932955145836f, 0.0052682687528431416f, 0.003148025833070278f, 0.00329153286293149f, 0.002547656185925007f, 0.0031584491953253746f, 0.007370765320956707f, 0.005469569470733404f, 0.00543639250099659f, 0.0033551612868905067f, 0.00767058040946722f, 0.002362719038501382f, 0.01628144644200802f, 0.0032057410571724176f, 0.004986491985619068f, 0.0076394639909267426f, 0.003897417336702347f, 0.00537867471575737f, 0.010090958327054977f, 0.008696626871824265f, 0.00458892248570919f, 0.003630454186350107f, 0.005706906784325838f, 0.0037777479737997055f, 0.00611340394243598f, 0.004048344679176807f, 0.004349956288933754f, 0.004302138462662697f, 0.005606940481811762f, 0.0032223279122263193f, 0.008459372445940971f, 0.004654948133975267f, 0.009443769231438637f, 0.004814986605197191f, 0.007060247473418713f, 0.005659759975969791f, 0.001815018942579627f, 0.013575428165495396f, 0.0028571411967277527f, 0.01019025593996048f, 0.03785299137234688f, 0.008835870772600174f, 0.006351619493216276f, 0.010283669456839561f, 0.0030256779864430428f, 0.00484709395095706f, 0.0070548756048083305f, 0.004576252307742834f, 0.0027336229104548693f, 0.008174475282430649f, 0.007338418159633875f, 0.0034900277387350798f, 0.009175753220915794f, 0.0028065366204828024f, 0.007334235589951277f, 0.020516490563750267f, 0.008887229487299919f, 0.006614875514060259f, 0.001453500590287149f, 0.002574482699856162f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #130 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.061954576987773e-05f, 0.00017265274072997272f, 5.189515286474489e-05f, 6.182894867379218e-05f, 0.00017008729628287256f, 0.00035860895877704024f, 0.00016366387717425823f, 0.00014526864106301218f, 0.0002739731571637094f, 0.0001643019204493612f, 0.00014293384447228163f, 8.862903632689267e-05f, 0.00011741351772798225f, 0.00012418378901202232f, 0.00016598001820966601f, 0.0001355861604679376f, 3.630234277807176e-05f, 0.0002529909834265709f, 9.074835543287918e-05f, 0.00016784171748440713f, 0.0001449081173632294f, 8.181509474525228e-05f, 0.00014582306903321296f, 0.00030765135306864977f, 0.00012861605500802398f, 0.00020386152027640492f, 0.00012108621012885123f, 0.0002328657719772309f, 4.191637708572671e-05f, 5.989574856357649e-05f, 0.00013104545359965414f, 0.00014941049448680133f, 0.00012667971896007657f, 6.930248491698876e-05f, 0.00022335820540320128f, 2.5720224584802054e-05f, 2.4551183742005378e-05f, 0.00018987055227626115f, 2.995477188960649e-05f, 0.0001371435500914231f, 9.430249338038266e-05f, 0.00015592886484228075f, 0.0002052129857474938f, 0.0001437500468455255f, 4.786788485944271e-05f, 0.00013691943604499102f, 0.00012756191426888108f, 0.00020083891286049038f, 0.00030485395109280944f, 2.6328596504754387e-05f, 0.00023347808746621013f, 0.0001826861553126946f, 0.0002549982746131718f, 6.540001777466387e-05f, 0.0003819469129666686f, 0.00027065331232734025f, 0.0001705498289084062f, 0.00012694850738625973f, 0.00014878554793540388f, 0.00017711760301608592f, 5.144863825989887e-05f, 3.4083466744050384e-05f, 0.00020350523118395358f, 8.603093738202006e-05f, 9.522716572973877e-05f, 0.00014041554823052138f, 0.0001576601789565757f, 0.00015603992505930364f, 0.00020044979464728385f, 0.00011233198165427893f, 3.7470468669198453e-05f, 6.819581176387146e-05f, 0.00020555146329570562f, 0.00012473874085117131f, 0.0002498215180821717f, 2.8153492166893557e-05f, 0.00013652973575517535f, 0.0001243778970092535f, 0.00013214080536272377f, 0.0001495427277404815f, 0.00041330125532113016f, 0.00017643190221861005f, 0.0001302207965636626f, 8.047736628213897e-05f, 7.784925401210785e-05f, 0.00012395926751196384f, 7.407119846902788e-05f, 7.744783215457574e-05f, 5.9944854001514614e-05f, 7.431645644828677e-05f, 0.00017342976934742182f, 0.00012869575584772974f, 0.000127915118355304f, 7.894496957305819e-05f, 0.0001804842468118295f, 5.559339115279727e-05f, 0.0003830928762909025f, 7.542920502601191e-05f, 0.00011732922575902194f, 0.00017975209630094469f, 9.170393605018035e-05f, 0.00012655706086661667f, 0.00023743431665934622f, 0.00020462651445996016f, 0.00010797465074574575f, 8.542245632270351e-05f, 0.00013428015518002212f, 8.888819138519466e-05f, 0.0001438447943655774f, 9.525517089059576e-05f, 0.00010235191439278424f, 0.00010122678941115737f, 0.00013192801270633936f, 7.58194801164791e-05f, 0.00019904406508430839f, 0.00010952819138765335f, 0.00022220633400138468f, 0.00011329380504321307f, 0.00016612347098998725f, 0.00013317081902641803f, 4.27063278038986e-05f, 0.00031942184432409704f, 6.722685066051781e-05f, 0.00023977072851266712f, 0.0008906586444936693f, 0.0002079028490697965f, 0.0001494498719694093f, 0.00024196869344450533f, 7.119242218323052e-05f, 0.00011404927499825135f, 0.00016599707305431366f, 0.0001076765256584622f, 6.432054215110838e-05f, 0.00019234059436712414f, 0.00017266866052523255f, 8.211829845095053e-05f, 0.00021590008691418916f, 6.603615474887192e-05f, 0.0001725702459225431f, 0.0004827409575227648f, 0.00020911128376610577f, 0.0001556441275170073f, 3.4200013033114374e-05f, 6.057606515241787e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #131 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_43_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011674920096993446f, 0.00967758521437645f, 0.015152351930737495f, 0.011016469448804855f, 0.01176652405411005f, 0.01619415171444416f, 0.008486178703606129f, 0.01100312452763319f, 0.008744035847485065f, 0.010375103913247585f, 0.013144008815288544f, 0.01059738639742136f, 0.010575840249657631f, 0.01261039637029171f, 0.010502099059522152f, 0.012652534060180187f, 0.014006352983415127f, 0.012395715340971947f, 0.010893812403082848f, 0.02277071215212345f, 0.01010508369654417f, 0.013387504033744335f, 0.015813259407877922f, 0.01006450317800045f, 0.012258940376341343f, 0.011503418907523155f, 0.009467682801187038f, 0.010606972500681877f, 0.010264255106449127f, 0.012583581730723381f, 0.008025221526622772f, 0.013279397040605545f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #132 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_43_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002747040125541389f, 0.00022770788928028196f, 0.0003565259394235909f, 0.000259211054071784f, 0.0002768593840301037f, 0.0003810388734564185f, 0.00019967480329796672f, 0.0002588970528449863f, 0.00020574202062562108f, 0.00024412009224761277f, 0.00030927080661058426f, 0.00024935026885941625f, 0.0002488433092366904f, 0.00029671521042473614f, 0.0002471082261763513f, 0.0002977066906169057f, 0.0003295612405054271f, 0.0002916638914030045f, 0.0002563250018283725f, 0.0005357814952731133f, 0.00023776668240316212f, 0.0003150000993628055f, 0.00037207669811323285f, 0.0002368118439335376f, 0.00028844564803875983f, 0.0002706686791498214f, 0.00022276901290751994f, 0.00024957582354545593f, 0.00024151189427357167f, 0.0002960842684842646f, 0.0001888287515612319f, 0.0003124563954770565f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #133 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00032341168844141066f, 0.0011865413980558515f, 0.00031805879552848637f, 0.0008569696801714599f, 0.0010884026996791363f, 0.0005688673700205982f, 0.0008494585636071861f, 0.0005880423705093563f, 0.0014194999821484089f, 0.000893453776370734f, 0.0015005762688815594f, 0.0008270028047263622f, 0.0005817862693220377f, 0.002383592538535595f, 0.0018034526146948338f, 0.0004547315475065261f, 0.0012256193440407515f, 0.000860156083945185f, 0.0018238837365061045f, 0.0010998439975082874f, 0.0008807090925984085f, 0.0005938247195445001f, 0.0004555609484668821f, 0.000861405220348388f, 0.0007413584971800447f, 0.0003781490959227085f, 0.0007626949227415025f, 0.0007613935740664601f, 0.000902740634046495f, 0.0013664723373949528f, 0.0009966593934223056f, 0.0005773658631369472f, 0.0009861013386398554f, 0.0009993899147957563f, 0.001253050286322832f, 0.0019189206650480628f, 0.000491703802254051f, 0.0012835708912461996f, 0.0008920939289964736f, 0.0019229741301387548f, 0.00020619432325474918f, 0.0008181802113540471f, 0.001389644225127995f, 0.0003744441783055663f, 0.0003722052788361907f, 0.0005747011164203286f, 0.0007024090155027807f, 0.0007651347550563514f, 0.0008263442432507873f, 0.0008337268955074251f, 0.000501352536957711f, 0.0003271549358032644f, 0.0013295274693518877f, 0.0013445240911096334f, 0.0010767508065328002f, 0.0011076905066147447f, 0.0009372856584377587f, 0.0005134441307745874f, 0.0007680002017877996f, 0.0005117442342452705f, 0.0007940010400488973f, 0.0004078958590980619f, 0.0013508248375728726f, 0.00033558884751982987f, 0.0008354282472282648f, 0.001025501755066216f, 0.0005406698328442872f, 0.0004367642686702311f, 0.0005455254577100277f, 0.0009065046906471252f, 0.0012371288612484932f, 0.0002626857894938439f, 0.0011775476159527898f, 0.0005784829845651984f, 0.000672396388836205f, 0.0004884321824647486f, 0.001138803898356855f, 0.000778655637986958f, 0.0013029094552621245f, 0.0003051734820473939f, 0.0006195916794240475f, 0.0010168574517592788f, 0.0010228435276076198f, 0.0008496730006299913f, 0.0006060089217498899f, 0.0009372962522320449f, 0.00039773457683622837f, 0.00038102612597867846f, 0.0009999593021348119f, 0.0010798530420288444f, 0.0009866416221484542f, 0.0006766162696294487f, 0.0006114588468335569f, 0.00039862815174274147f, 0.0007683074800297618f, 0.0004820331814698875f, 0.0006433902308344841f, 0.00031804986065253615f, 0.0013087191618978977f, 0.00039831263711676f, 0.0006941891624592245f, 0.0006983534549362957f, 0.0007145751151256263f, 0.0006280087400227785f, 0.0011540221748873591f, 0.0015654697781428695f, 0.00038462397060357034f, 0.00016849528765305877f, 0.0007325145998038352f, 0.0011674624402076006f, 0.0004144679114688188f, 0.0011905290884897113f, 0.00035709235817193985f, 0.0003865266917273402f, 0.0009499866282567382f, 0.0005531367496587336f, 0.0010680857812985778f, 0.0005120821879245341f, 0.0007835535798221827f, 0.000919415382668376f, 0.00022173108300194144f, 0.0003391610807739198f, 0.001141487853601575f, 0.0008704440551809967f, 0.0005368822021409869f, 0.0015807085437700152f, 0.0004956136690452695f, 0.0017418760107830167f, 0.0006078238948248327f, 0.0009586357627995312f, 0.00044055533362552524f, 0.0009647824917919934f, 0.00032291992101818323f, 0.0006823497242294252f, 0.0006670299335382879f, 0.000931031012441963f, 0.0012299418449401855f, 0.0011178527493029833f, 0.0009425882599316537f, 0.001230547670274973f, 0.0008969102636910975f, 0.0009070640662685037f, 0.0012828491162508726f, 0.0005295726587064564f, 0.0006213458254933357f, 0.00047359123709611595f, 0.0014349691336974502f, 0.0011930068721994758f, 0.001028575235977769f, 0.0011111185885965824f, 0.0008787124534137547f, 0.00040993193397298455f, 0.0017185272881761193f, 0.000849826552439481f, 0.0002563465968705714f, 0.000255669467151165f, 0.0008692567935213447f, 0.0010591840837150812f, 0.0015341861872002482f, 0.000568760558962822f, 0.0009047134662978351f, 0.0007762688328512013f, 0.0008521358831785619f, 0.0006855885148979723f, 0.0003516273864079267f, 0.0003149861586280167f, 0.0008165589533746243f, 0.001320986426435411f, 0.0002915158693213016f, 0.0003751031181309372f, 0.0003678590292111039f, 0.0003669419384095818f, 0.0010024365037679672f, 0.0005781264044344425f, 0.0008779868367128074f, 0.0010440903715789318f, 0.0009377953829243779f, 0.0009509588126093149f, 0.0012210238492116332f, 0.0007839326863177121f, 0.0005535164382308722f, 0.0009944252669811249f, 0.0009899070719256997f, 0.0006925844354555011f, 0.000849821197334677f, 0.0010336096165701747f, 0.0009221091750077903f, 0.000737036345526576f, 0.0007869915571063757f, 0.0006954104756005108f, 0.0014408946735784411f, 0.0009405541350133717f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #134 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.3820593166165054e-05f, 0.0001974584156414494f, 5.292979039950296e-05f, 0.0001426126982551068f, 0.000181126655661501f, 9.46681248024106e-05f, 0.000141362746944651f, 9.785913425730541e-05f, 0.00023622624576091766f, 0.00014868420839775354f, 0.0002497185778338462f, 0.0001376257569063455f, 9.681802475824952e-05f, 0.0003966658259741962f, 0.0003001217555720359f, 7.56742010707967e-05f, 0.00020396157924551517f, 0.0001431429700460285f, 0.0003035218105651438f, 0.00018303065735381097f, 0.00014656329585704952f, 9.882140875561163e-05f, 7.581222598673776e-05f, 0.00014335084415506572f, 0.0001233732618857175f, 6.292972102528438e-05f, 0.00012692395830526948f, 0.00012670739670284092f, 0.000150229680002667f, 0.00022740164422430098f, 0.00016585917910560966f, 9.608240361558273e-05f, 0.0001641021663090214f, 0.00016631357721053064f, 0.00020852650050073862f, 0.0003193373850081116f, 8.182694000424817e-05f, 0.00021360558457672596f, 0.0001484579115640372f, 0.00032001195359043777f, 3.431385266594589e-05f, 0.00013615755597129464f, 0.0002312577998964116f, 6.23131709289737e-05f, 6.19405836914666e-05f, 9.563894855091348e-05f, 0.0001168914750451222f, 0.00012732998584397137f, 0.00013751616643276066f, 0.0001387447555316612f, 8.343263471033424e-05f, 5.444352427730337e-05f, 0.00022125346004031599f, 0.00022374912805389613f, 0.00017918759840540588f, 0.000184336444362998f, 0.0001559785014251247f, 8.544485899619758e-05f, 0.00012780683755408973f, 8.516196976415813e-05f, 0.00013213377678766847f, 6.78800352034159e-05f, 0.0002247976663056761f, 5.584705650107935e-05f, 0.00013902787759434432f, 0.00017065898282453418f, 8.997562690638006e-05f, 7.268417539307848e-05f, 9.078368020709604e-05f, 0.0001508560817455873f, 0.00020587693143170327f, 4.371488466858864e-05f, 0.0001959617220563814f, 9.626831160858274e-05f, 0.00011189691576873884f, 8.128249464789405e-05f, 0.00018951417587231845f, 0.00012958006118424237f, 0.00021682381338905543f, 5.078547837911174e-05f, 0.00010310941433999687f, 0.00016922043869271874f, 0.00017021661915350705f, 0.00014139842824079096f, 0.00010084904351970181f, 0.00015598026220686734f, 6.618904444621876e-05f, 6.34085081401281e-05f, 0.00016640833928249776f, 0.00017970385670196265f, 0.00016419206804130226f, 0.00011259916936978698f, 0.00010175599163630977f, 6.633775046793744e-05f, 0.0001278579729842022f, 8.021760731935501e-05f, 0.00010706985631259158f, 5.292830246617086e-05f, 0.00021779064263682812f, 6.628523988183588e-05f, 0.00011552356590982527f, 0.00011621656449278817f, 0.00011891609756276011f, 0.0001045101453200914f, 0.0001920467329910025f, 0.00026051781605929136f, 6.400723941624165e-05f, 2.8040161851095036e-05f, 0.00012190149573143572f, 0.00019428339146543294f, 6.897372077219188e-05f, 0.0001981220266316086f, 5.9425565268611535e-05f, 6.43238818156533e-05f, 0.0001580921234562993f, 9.205031528836116e-05f, 0.00017774562002159655f, 8.521821291651577e-05f, 0.00013039515761192888f, 0.00015300461382139474f, 3.6899404221912846e-05f, 5.6441527704009786e-05f, 0.00018996083235833794f, 0.00014485504652839154f, 8.934531069826335e-05f, 0.00026305377832613885f, 8.247759978985414e-05f, 0.00028987450059503317f, 0.00010115108307218179f, 0.00015953148249536753f, 7.331506640184671e-05f, 0.00016055438027251512f, 5.373875319492072e-05f, 0.00011355330207152292f, 0.00011100385745521635f, 0.00015493763203267008f, 0.0002046809095190838f, 0.00018602759519126266f, 0.00015686092956457287f, 0.00020478172518778592f, 0.00014925941650290042f, 0.00015094917034730315f, 0.00021348547306843102f, 8.812889427645132e-05f, 0.00010340133303543553f, 7.881273631937802e-05f, 0.0002388005523243919f, 0.0001985343697015196f, 0.00017117046809289604f, 0.00018490692309569567f, 0.00014623103197664022f, 6.821886927355081e-05f, 0.00028598890639841557f, 0.00014142398140393198f, 4.265994721208699e-05f, 4.2547260818537325e-05f, 0.00014465746062342077f, 0.0001762642350513488f, 0.0002553117519710213f, 9.465034963795915e-05f, 0.0001505579857621342f, 0.0001291828666580841f, 0.00014180828293319792f, 0.0001140922904596664f, 5.8516110584605485e-05f, 5.2418457926250994e-05f, 0.0001358877489110455f, 0.00021983210172038525f, 4.8512643843423575e-05f, 6.242282688617706e-05f, 6.121730257291347e-05f, 6.106468208599836e-05f, 0.00016682058048900217f, 9.620896889828146e-05f, 0.00014611028018407524f, 0.00017375241441186517f, 0.00015606332453899086f, 0.0001582539116498083f, 0.00020319681789260358f, 0.00013045824016444385f, 9.211349970428273e-05f, 0.0001654873922234401f, 0.0001647354947635904f, 0.00011525651643751189f, 0.00014142309373710304f, 0.0001720082655083388f, 0.0001534529001219198f, 0.0001226539898198098f, 0.00013096728071104735f, 0.00011572681250981987f, 0.00023978664830792695f, 0.0001565224229125306f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #135 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_45_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.018054069951176643f, 0.006620359607040882f, 0.025574855506420135f, 0.003165300702676177f, 0.0038707833737134933f, 0.010654553771018982f, 0.018586188554763794f, 0.009516652673482895f, 0.002369675086811185f, 0.009977934882044792f, 0.009137600660324097f, 0.006001332774758339f, 0.006852997932583094f, 0.0055337930098176f, 0.004216439556330442f, 0.005444965325295925f, 0.005392185878008604f, 0.001886388286948204f, 0.004735955037176609f, 0.0018985667265951633f, 0.009858437813818455f, 0.008257914334535599f, 0.01627267152070999f, 0.009266496635973454f, 0.006080280523747206f, 0.012187195010483265f, 0.00929869245737791f, 0.006684798747301102f, 0.013127397745847702f, 0.012594171799719334f, 0.004340497311204672f, 0.01436261460185051f, 0.00817538145929575f, 0.009938888251781464f, 0.00833510048687458f, 0.008014840073883533f, 0.021734444424510002f, 0.00337464502081275f, 0.007259948644787073f, 0.005115495529025793f, 0.04040203243494034f, 0.0065132747404277325f, 0.010180490091443062f, 0.0176150593906641f, 0.011495635844767094f, 0.006714283023029566f, 0.012829427607357502f, 0.010898608714342117f, 0.006939527112990618f, 0.014497960917651653f, 0.009372871369123459f, 0.012696769088506699f, 0.0064120814204216f, 0.006217225454747677f, 0.006952555384486914f, 0.00991812627762556f, 0.013241811655461788f, 0.008346639573574066f, 0.017746424302458763f, 0.020466869696974754f, 0.00616034772247076f, 0.007098950445652008f, 0.004745627753436565f, 0.015753185376524925f, 0.010432726703584194f, 0.0037518369499593973f, 0.004354389384388924f, 0.01427605003118515f, 0.009706073440611362f, 0.01072175707668066f, 0.006314217112958431f, 0.027233602479100227f, 0.0033200338948518038f, 0.014634041115641594f, 0.008650427684187889f, 0.012654799968004227f, 0.012364260852336884f, 0.007224102504551411f, 0.0015333802439272404f, 0.017031723633408546f, 0.007008409593254328f, 0.00927030947059393f, 0.0030034955125302076f, 0.002046482404693961f, 0.0046643759123981f, 0.008930345997214317f, 0.023561745882034302f, 0.01828763820230961f, 0.008256755769252777f, 0.009024511091411114f, 0.008561868220567703f, 0.013110853731632233f, 0.010244139470160007f, 0.004618815612047911f, 0.006539377849549055f, 0.010644081979990005f, 0.009107486344873905f, 0.024293096736073494f, 0.004487911704927683f, 0.009070850908756256f, 0.011705823242664337f, 0.009653838351368904f, 0.010212792083621025f, 0.004330016206949949f, 0.003704899689182639f, 0.007189409341663122f, 0.01952354423701763f, 0.017613664269447327f, 0.006330360192805529f, 0.005396105349063873f, 0.016108980402350426f, 0.0017283160705119371f, 0.00666263559833169f, 0.015792200341820717f, 0.013920251280069351f, 0.00924642849713564f, 0.005742236971855164f, 0.013588028959929943f, 0.019500192254781723f, 0.004343730863183737f, 0.01191216055303812f, 0.016114214435219765f, 0.003987095318734646f, 0.007410502061247826f, 0.017223171889781952f, 0.006030035670846701f, 0.019651329144835472f, 0.011775963939726353f, 0.011120031587779522f, 0.010214205831289291f, 0.020538493990898132f, 0.007564245257526636f, 0.014181414619088173f, 0.009137528948485851f, 0.008277913555502892f, 0.008080964908003807f, 0.00548674026504159f, 0.005394511856138706f, 0.004774217959493399f, 0.006883119698613882f, 0.007588690146803856f, 0.017314834520220757f, 0.010868092998862267f, 0.00927661545574665f, 0.009569160640239716f, 0.015397797338664532f, 0.006086662411689758f, 0.008693883195519447f, 0.013232143595814705f, 0.004951925482600927f, 0.008388222195208073f, 0.014585409313440323f, 0.001807614928111434f, 0.001677349559031427f, 0.03017820604145527f, 0.038819875568151474f, 0.009412476792931557f, 0.005315831396728754f, 0.005033385008573532f, 0.02320755273103714f, 0.005093209911137819f, 0.00534706749022007f, 0.004767707083374262f, 0.021697018295526505f, 0.0214054137468338f, 0.021281491965055466f, 0.012034153565764427f, 0.00662871403619647f, 0.017615893855690956f, 0.013947735540568829f, 0.02492549456655979f, 0.016685280948877335f, 0.0028590322472155094f, 0.010823586024343967f, 0.015073404647409916f, 0.011003278195858002f, 0.005029336083680391f, 0.002625341759994626f, 0.0014480187091976404f, 0.007488604635000229f, 0.007097747642546892f, 0.0037012833636254072f, 0.007103467360138893f, 0.01109971571713686f, 0.005984210409224033f, 0.005986114498227835f, 0.010553400032222271f, 0.005812572780996561f, 0.01397976279258728f, 0.0033526450861245394f, 0.0028871376998722553f, 0.005886649712920189f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #136 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_45_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00042480166302993894f, 0.00015577317390125245f, 0.0006017613341100514f, 7.447766256518662e-05f, 9.107725782087073e-05f, 0.00025069538969546556f, 0.0004373221017885953f, 0.00022392124810721725f, 5.5757060181349516e-05f, 0.00023477493959944695f, 0.0002150023792637512f, 0.00014120782725512981f, 0.0001612470077816397f, 0.0001302068994846195f, 9.92103450698778e-05f, 0.00012811683700419962f, 0.00012687496200669557f, 4.4385607907315716e-05f, 0.00011143423762405291f, 4.467216058401391e-05f, 0.00023196324764285237f, 0.00019430386601015925f, 0.00038288638461381197f, 0.00021803521667607129f, 0.00014306542288977653f, 0.0002867575385607779f, 0.00021879277483094484f, 0.00015728938160464168f, 0.0003088799421675503f, 0.00029633345548063517f, 0.00010212935012532398f, 0.00033794387127272785f, 0.00019236192747484893f, 0.000233856204431504f, 0.00019612001779023558f, 0.00018858448311220855f, 0.0005113987135700881f, 7.940341311041266e-05f, 0.0001708223280729726f, 0.00012036460248054937f, 0.0009506360511295497f, 0.00015325352433137596f, 0.0002395409537712112f, 0.0004144719860050827f, 0.00027048555784858763f, 0.00015798312961123884f, 0.0003018688876181841f, 0.0002564378664828837f, 0.00016328299534507096f, 0.000341128499712795f, 0.0002205381606472656f, 0.0002987475018016994f, 0.00015087251085788012f, 0.0001462876534787938f, 0.00016358954599127173f, 0.0002333676820853725f, 0.0003115720464847982f, 0.00019639152742456645f, 0.00041756292921490967f, 0.00048157342826016247f, 0.00014494935749098659f, 0.00016703412984497845f, 0.00011166182957822457f, 0.0003706631832756102f, 0.0002454759378451854f, 8.827851706882939e-05f, 0.00010245622252114117f, 0.0003359070688020438f, 0.00022837820870336145f, 0.00025227662990801036f, 0.00014856981579214334f, 0.0006407906766980886f, 7.81184426159598e-05f, 0.00034433038672432303f, 0.00020353947184048593f, 0.0002977600088343024f, 0.0002909237809944898f, 0.00016997888451442122f, 3.607953476603143e-05f, 0.00040074644493870437f, 0.000164903758559376f, 0.00021812492923345417f, 7.067048136377707e-05f, 4.815252759726718e-05f, 0.00010975002078339458f, 0.0002101257850881666f, 0.0005543940351344645f, 0.0004302973684389144f, 0.00019427661027293652f, 0.0002123414451489225f, 0.00020145572489127517f, 0.0003084906784351915f, 0.0002410385786788538f, 0.00010867801756830886f, 0.00015386771701741964f, 0.00025044899666681886f, 0.00021429380285553634f, 0.0005716023151762784f, 0.00010559792281128466f, 0.00021343179105315357f, 0.00027543114265426993f, 0.00022714913939125836f, 0.0002403010003035888f, 0.00010188273881794885f, 8.717411401448771e-05f, 0.00016916258027777076f, 0.00045937750837765634f, 0.00041443915688432753f, 0.00014894964988343418f, 0.00012696719204541296f, 0.00037903484189882874f, 4.066626206622459e-05f, 0.00015676789917051792f, 0.00037158120539970696f, 0.0003275353228673339f, 0.000217563021578826f, 0.00013511146244127303f, 0.0003197183250449598f, 0.00045882805716246367f, 0.0001022054348140955f, 0.0002802861272357404f, 0.0003791579802054912f, 9.381400741403922e-05f, 0.00017436475900467485f, 0.00040525110671296716f, 0.00014188319619279355f, 0.0004623842251021415f, 0.0002770815044641495f, 0.0002616478013806045f, 0.00024033426598180085f, 0.00048325868556275964f, 0.00017798224871512502f, 0.00033368036383762956f, 0.00021500069124158472f, 0.00019477444584481418f, 0.0001901403593365103f, 0.00012909977522213012f, 0.00012692969175986946f, 0.00011233454279135913f, 0.0001619557588128373f, 0.00017855741316452622f, 0.00040740787517279387f, 0.0002557198458816856f, 0.00021827331511303782f, 0.00022515672026202083f, 0.0003623011289164424f, 0.00014321558410301805f, 0.00020456196216400713f, 0.00031134457094594836f, 0.00011651589738903567f, 0.00019736993999686092f, 0.00034318611142225564f, 4.25321159127634e-05f, 3.94670496461913e-05f, 0.0007100754301063716f, 0.0009134088759310544f, 0.000221470050746575f, 0.0001250783825526014f, 0.00011843258835142478f, 0.0005460600950755179f, 0.0001198402387672104f, 0.00012581335613504052f, 0.0001121813475037925f, 0.0005105180898681283f, 0.0005036568036302924f, 0.0005007410072721541f, 0.0002831565507221967f, 0.00015596974117215723f, 0.000414491631090641f, 0.0003281820099800825f, 0.0005864822305738926f, 0.0003925948403775692f, 6.727135041728616e-05f, 0.0002546726318541914f, 0.0003546683583408594f, 0.00025890066171996295f, 0.00011833732423838228f, 6.177274917718023e-05f, 3.407102849450894e-05f, 0.0001762024621712044f, 0.00016700582636985928f, 8.708902169018984e-05f, 0.00016714041703380644f, 0.0002611698000691831f, 0.00014080495748203248f, 0.00014084976282902062f, 0.00024831530754454434f, 0.00013676642265636474f, 0.0003289355954620987f, 7.888576510595158e-05f, 6.793265492888168e-05f, 0.00013850940740667284f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #137 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_46_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007749897427856922f, 0.005714763421565294f, 0.00891017634421587f, 0.0028800428844988346f, 0.011259743012487888f, 0.006039251573383808f, 0.003631435101851821f, 0.00612263847142458f, 0.0035006001126021147f, 0.011075148358941078f, 0.0063078561797738075f, 0.006608118303120136f, 0.006569951307028532f, 0.0054818810895085335f, 0.0053521497175097466f, 0.005054481793195009f, 0.012093666940927505f, 0.01664048433303833f, 0.007726133335381746f, 0.012266820296645164f, 0.013870679773390293f, 0.007803162094205618f, 0.016888732090592384f, 0.0044019948691129684f, 0.010988786816596985f, 0.005640050396323204f, 0.014101758599281311f, 0.012818150222301483f, 0.003660257440060377f, 0.00567741459235549f, 0.004379058722406626f, 0.007833954878151417f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #138 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_46_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00018235052993986756f, 0.0001344650227110833f, 0.0002096512180287391f, 6.776571535738185e-05f, 0.0002649351372383535f, 0.00014210003428161144f, 8.54455356602557e-05f, 0.00014406208356376737f, 8.236706344177946e-05f, 0.00026059173978865147f, 0.0001484201493440196f, 0.00015548513329122216f, 0.00015458709094673395f, 0.00012898544082418084f, 0.00012593294377438724f, 0.00011892898328369483f, 0.00028455688152462244f, 0.00039154081605374813f, 0.00018179137259721756f, 0.0002886310685425997f, 0.00032636892865411937f, 0.00018360381363891065f, 0.00039738192572258413f, 0.0001035763489198871f, 0.00025855968124233186f, 0.0001327070640400052f, 0.0003318060771562159f, 0.00030160354799591005f, 8.61237058416009e-05f, 0.00013358623255044222f, 0.00010303667659172788f, 0.00018432835349813104f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #139 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008625427144579589f, 0.00051379285287112f, 0.0007296895491890609f, 0.000546658702660352f, 0.001209146692417562f, 0.0005111004575155675f, 0.0006256686756387353f, 0.0008359849452972412f, 0.0005311143468134105f, 0.000782495888415724f, 0.0007235250086523592f, 0.001010733307339251f, 0.0002581264707259834f, 0.0007385193603113294f, 0.000339593825628981f, 0.0006864143069833517f, 0.0010900238994508982f, 0.0006189288105815649f, 0.00078851223224774f, 0.00047675592941232026f, 0.000597604492213577f, 0.0010670560877770185f, 0.0010359393199905753f, 0.0010001875925809145f, 0.0007992943283170462f, 0.00034232038888148963f, 0.0007739160791970789f, 0.0006788976606912911f, 0.0010651586344465613f, 0.0005619361181743443f, 0.0006341176922433078f, 0.0009419318521395326f, 0.0003293619956821203f, 0.00034364452585577965f, 0.0007245560409501195f, 0.0006921215099282563f, 0.0002382792008575052f, 0.00059777736896649f, 0.0004890146665275097f, 0.0009467689669691026f, 0.0004770616360474378f, 0.0008485311991535127f, 0.0005926580633968115f, 0.0011245313799008727f, 0.0005165537586435676f, 0.0008116841781884432f, 0.0005404351395554841f, 0.0006057713180780411f, 0.0014962459681555629f, 0.0007633787463419139f, 0.0006356958183459938f, 0.0009400745038874447f, 0.0009432326187379658f, 0.00016035352018661797f, 0.0009569679968990386f, 0.00021536275744438171f, 0.0007625056896358728f, 0.0008143483428284526f, 0.0007173212943598628f, 0.0007827545050531626f, 0.0005537251709029078f, 0.0014227807987481356f, 0.0008706835797056556f, 0.0006278991349972785f, 0.00031010009115561843f, 0.0007867384701967239f, 0.0008765716920606792f, 0.00041726717608980834f, 0.0010861617047339678f, 0.0004928153939545155f, 0.0004844842478632927f, 0.0005188794457353652f, 0.0005307404207997024f, 0.0008663291810080409f, 0.001121107256039977f, 0.0008398945210501552f, 0.0009402642608620226f, 0.0008013628539629281f, 0.0004064335080329329f, 0.0012637709733098745f, 0.0005791607545688748f, 0.0007223670254461467f, 0.0008164359023794532f, 0.0004893203731626272f, 0.0006815489032305777f, 0.00033381141838617623f, 0.0009274841868318617f, 0.0006080447346903384f, 0.000664547027554363f, 0.0008764293161220849f, 0.0008444119594059885f, 0.0009694222826510668f, 0.0007733152015134692f, 0.0010843065101653337f, 0.0009733180631883442f, 0.0005611677188426256f, 0.0004615365469362587f, 0.0011277967132627964f, 0.000733088469132781f, 0.0007174392230808735f, 0.0005699022440239787f, 0.000882044667378068f, 0.00037464036722667515f, 0.0007754567777737975f, 0.0008738130563870072f, 0.0004071898583788425f, 0.000660342862829566f, 0.0006980164325796068f, 0.0010012311395257711f, 0.0006227890262380242f, 0.0007714850944466889f, 0.0004533161118160933f, 0.00022306227765511721f, 0.0008311395649798214f, 0.0007627648301422596f, 0.0007503266097046435f, 0.0007808138034306467f, 0.0004313462704885751f, 0.0008490485488437116f, 0.0008822308154776692f, 0.00045108652557246387f, 0.0005932406056672335f, 0.000745325640309602f, 0.000491010898258537f, 0.0008564531453885138f, 0.0005125324241816998f, 0.0006771680200472474f, 0.0008079250692389905f, 0.0009258085628971457f, 0.00032946644932962954f, 0.0008485735743306577f, 0.0002794366155285388f, 0.002470482839271426f, 0.0007100891671143472f, 0.0004241573915351182f, 0.0006259874789975584f, 0.0010425894288346171f, 0.0005358005873858929f, 0.0004520330694504082f, 0.0009928301442414522f, 0.0008864885312505066f, 0.0009048365755006671f, 0.0007861183839850128f, 0.001098264125175774f, 0.0004907884867861867f, 0.0011856890050694346f, 0.0006651260773651302f, 0.0007853349670767784f, 0.00032986249425448477f, 0.0006142286001704633f, 0.0009907200001180172f, 0.0008178122225217521f, 0.0009024979663081467f, 0.0008739389013499022f, 0.0010244139702990651f, 0.0010817450238391757f, 0.00033939265995286405f, 0.0009125432698056102f, 0.000779742025770247f, 0.000889073999132961f, 0.0012509480584412813f, 0.0012206427054479718f, 0.000714385649189353f, 0.0013826241483911872f, 0.000877216225489974f, 0.000656621006783098f, 0.0009237349731847644f, 0.0007226344314403832f, 0.00028698352980427444f, 0.0008438162039965391f, 0.000777672918047756f, 0.0006596830207854509f, 0.0003550536057446152f, 0.0004507796838879585f, 0.0003724301350302994f, 0.0003904745390173048f, 0.0007339532603509724f, 0.0005985241150483489f, 0.0007098575006239116f, 0.0009141196496784687f, 0.0007627690793015063f, 0.0007413552375510335f, 0.0007431278354488313f, 0.000912803749088198f, 0.001705822185613215f, 0.0008764963713474572f, 0.0003245310508646071f, 0.0006256687338463962f, 0.001273418660275638f, 0.0008483212441205978f, 0.0010146802524104714f, 0.0008299885084852576f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #140 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001818785531213507f, 0.0001083400275092572f, 0.00015386470477096736f, 0.00011527023161761463f, 0.0002549646014813334f, 0.00010777229908853769f, 0.00013193053018767387f, 0.0001762784959282726f, 0.00011199249274795875f, 0.00016499962657690048f, 0.00015256482583936304f, 0.00021312650642357767f, 5.442938709165901e-05f, 0.00015572659322060645f, 7.160785753512755e-05f, 0.000144739547977224f, 0.00022984597308095545f, 0.00013050933193881065f, 0.00016626824799459428f, 0.00010053030564449728f, 0.00012601281923707575f, 0.000225002906518057f, 0.00021844153525307775f, 0.00021090279915370047f, 0.00016854179557412863f, 7.21827891538851e-05f, 0.00016319045971613377f, 0.0001431545679224655f, 0.00022460280160885304f, 0.00011849167640320957f, 0.00013371212116908282f, 0.00019861881446558982f, 6.945033965166658e-05f, 7.246200402732939e-05f, 0.00015278224600479007f, 0.00014594299136660993f, 5.024432539357804e-05f, 0.0001260492717847228f, 0.00010311522055417299f, 0.00019963877275586128f, 0.00010059476335300133f, 0.00017892404866870493f, 0.00012496981071308255f, 0.00023712233814876527f, 0.00010892220598179847f, 0.00017115435912273824f, 0.00011395791079849005f, 0.0001277349074371159f, 0.00031550327548757195f, 0.00016096852777991444f, 0.00013404487981460989f, 0.00019822716421913356f, 0.00019889308896381408f, 3.381266287760809e-05f, 0.0002017893857555464f, 4.541208909358829e-05f, 0.00016078443150036037f, 0.00017171613581012934f, 0.00015125669597182423f, 0.00016505415260326117f, 0.00011676028952933848f, 0.0003000121796503663f, 0.000183595169801265f, 0.00013240084808785468f, 6.538871093653142e-05f, 0.0001658942346693948f, 0.0001848367537604645f, 8.798631461104378e-05f, 0.00022903158969711512f, 0.00010391665273346007f, 0.00010215992369921878f, 0.00010941260552499443f, 0.00011191365047125146f, 0.00018267698760610074f, 0.0002364003157708794f, 0.00017710289102979004f, 0.00019826718198601156f, 0.0001689779746811837f, 8.570188947487622e-05f, 0.00026648284983821213f, 0.0001221237180288881f, 0.00015232065925374627f, 0.00017215633124578744f, 0.00010317968553863466f, 0.00014371360884979367f, 7.03885598341003e-05f, 0.00019557232735678554f, 0.000128214291180484f, 0.0001401285408064723f, 0.00018480673315934837f, 0.0001780554448487237f, 0.00020441552624106407f, 0.00016306375619024038f, 0.00022864039056003094f, 0.00020523701095953584f, 0.00011832964810309932f, 9.732109174365178e-05f, 0.00023781087656971067f, 0.0001545814156997949f, 0.0001512815651949495f, 0.00012017144035780802f, 0.00018599080794956535f, 7.899788761278614e-05f, 0.00016351533122360706f, 0.00018425505550112575f, 8.586137846577913e-05f, 0.0001392420381307602f, 0.00014718601596541703f, 0.00021112285321578383f, 0.0001313233224209398f, 0.00016267785395029932f, 9.558770398143679e-05f, 4.703563536168076e-05f, 0.00017525679140817374f, 0.0001608390739420429f, 0.0001582163095008582f, 0.00016464493819512427f, 9.095507266465575e-05f, 0.00017903312982525676f, 0.00018603005446493626f, 9.511756798019633e-05f, 0.0001250926434295252f, 0.00015716179041191936f, 0.00010353614925406873f, 0.00018059449212159961f, 0.0001080742513295263f, 0.00014278985327109694f, 0.00017036170174833387f, 0.0001952190068550408f, 6.947236397536471e-05f, 0.00017893298354465514f, 5.892291301279329e-05f, 0.0005209340597502887f, 0.0001497317134635523f, 8.943920693127438e-05f, 0.0001319977454841137f, 0.00021984378690831363f, 0.00011298065510345623f, 9.53171620494686e-05f, 0.00020935139036737382f, 0.00018692784942686558f, 0.0001907967816805467f, 0.0001657634711591527f, 0.0002315835445187986f, 0.00010348925570724532f, 0.00025001823087222874f, 0.00014025064592715353f, 0.00016559827781748027f, 6.955587741686031e-05f, 0.00012951823009643704f, 0.00020890643645543605f, 0.00017244654009118676f, 0.0001903036463772878f, 0.0001842815981945023f, 0.00021601126354653388f, 0.00022810026712249964f, 7.156543870223686e-05f, 0.0001924218377098441f, 0.0001644189323997125f, 0.00018747303693089634f, 0.0002637789584696293f, 0.0002573886886239052f, 0.00015063767204992473f, 0.00029154462390579283f, 0.00018497266864869744f, 0.00013845723879057914f, 0.00019478175090625882f, 0.0001523770479252562f, 6.051427772035822e-05f, 0.00017792981816455722f, 0.0001639826368773356f, 0.00013910290726926178f, 7.486775575671345e-05f, 9.505287016509101e-05f, 7.853182614780962e-05f, 8.233672997448593e-05f, 0.00015476376574952155f, 0.00012620673805940896f, 0.00014968286268413067f, 0.00019275423255749047f, 0.00016083996160887182f, 0.00015632457507308573f, 0.00015669835556764156f, 0.00019247675663791597f, 0.0003596952010411769f, 0.00018482087762095034f, 6.843166920589283e-05f, 0.0001319305447395891f, 0.0002685172075871378f, 0.000178879767190665f, 0.00021395877411123365f, 0.00017501406546216458f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #141 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.016203798353672028f, 0.007554057519882917f, 0.004066365770995617f, 0.004748281091451645f, 0.004219762049615383f, 0.012228432111442089f, 0.0046197157353162766f, 0.020520735532045364f, 0.005375362001359463f, 0.00460541108623147f, 0.005876836832612753f, 0.006047585513442755f, 0.018575487658381462f, 0.002638086210936308f, 0.011204955168068409f, 0.00597130972892046f, 0.0029317932203412056f, 0.020427679643034935f, 0.006107732187956572f, 0.007507406175136566f, 0.007267560809850693f, 0.008298497647047043f, 0.0135270981118083f, 0.011631753295660019f, 0.0021178063470870256f, 0.010800798423588276f, 0.005408957600593567f, 0.016951031982898712f, 0.008287232369184494f, 0.004936345387250185f, 0.009154114872217178f, 0.005108756013214588f, 0.012456993572413921f, 0.01994352973997593f, 0.012352596037089825f, 0.015573077835142612f, 0.018828265368938446f, 0.003236063988879323f, 0.005848153959959745f, 0.010064392350614071f, 0.008015773259103298f, 0.005387116689234972f, 0.007616247516125441f, 0.0036570231895893812f, 0.006200704257935286f, 0.006238773465156555f, 0.003814087714999914f, 0.008336582221090794f, 0.0025631317403167486f, 0.005506657063961029f, 0.008391538634896278f, 0.0012246271362528205f, 0.0021680211648344994f, 0.02527785114943981f, 0.0041873520240187645f, 0.023499736562371254f, 0.007079043425619602f, 0.002604075940325856f, 0.010222548618912697f, 0.004853956867009401f, 0.006549963727593422f, 0.005234845448285341f, 0.005766728427261114f, 0.005858441814780235f, 0.014938839711248875f, 0.005808608140796423f, 0.00799810141324997f, 0.007871921174228191f, 0.004368157126009464f, 0.008882684633135796f, 0.006928008049726486f, 0.01448057871311903f, 0.0065931170247495174f, 0.005201361607760191f, 0.010389847680926323f, 0.0044304425828158855f, 0.004964267369359732f, 0.0046560149639844894f, 0.010677642188966274f, 0.0044568427838385105f, 0.014525695703923702f, 0.005282385274767876f, 0.005113885272294283f, 0.028444737195968628f, 0.007052164524793625f, 0.008121535181999207f, 0.007076418958604336f, 0.0036364237312227488f, 0.008585551753640175f, 0.0017275906866416335f, 0.0053757792338728905f, 0.005427372641861439f, 0.0014747085515409708f, 0.0047073462046682835f, 0.0014292163541540504f, 0.009676567278802395f, 0.006433594971895218f, 0.006272854749113321f, 0.005234536714851856f, 0.0069043319672346115f, 0.013152011670172215f, 0.00797850638628006f, 0.01835136115550995f, 0.0015132968546822667f, 0.006619186606258154f, 0.023146646097302437f, 0.0024009146727621555f, 0.006353786215186119f, 0.0127047598361969f, 0.003986837808042765f, 0.005294825416058302f, 0.007499827072024345f, 0.011988019570708275f, 0.0016590937739238143f, 0.012636708095669746f, 0.0057333228178322315f, 0.009924924932420254f, 0.013512912206351757f, 0.0015329273883253336f, 0.004222664050757885f, 0.0188178401440382f, 0.006678731646388769f, 0.011024024337530136f, 0.015206619165837765f, 0.0044531188905239105f, 0.005063288379460573f, 0.006685076281428337f, 0.00618323590606451f, 0.008996655233204365f, 0.015121293254196644f, 0.007910222746431828f, 0.024142660200595856f, 0.0014908576849848032f, 0.011371629312634468f, 0.01391166914254427f, 0.0063115814700722694f, 0.0017983692232519388f, 0.006221874617040157f, 0.003920017741620541f, 0.004404927603900433f, 0.00456650834530592f, 0.006975763477385044f, 0.0034290167968720198f, 0.0034326708409935236f, 0.014398652128875256f, 0.005281529854983091f, 0.005939324852079153f, 0.005377169698476791f, 0.014922181144356728f, 0.008395967073738575f, 0.005178080406039953f, 0.007585057523101568f, 0.003966381307691336f, 0.0020307833328843117f, 0.004857709165662527f, 0.005210993345826864f, 0.007899516262114048f, 0.009750034660100937f, 0.004706408362835646f, 0.010133291594684124f, 0.004169277381151915f, 0.008083284832537174f, 0.011183748953044415f, 0.005547034554183483f, 0.003646834520623088f, 0.008109642192721367f, 0.006832651793956757f, 0.007940644398331642f, 0.018626684322953224f, 0.004149153828620911f, 0.005238965153694153f, 0.002244005212560296f, 0.006161760073155165f, 0.005735913757234812f, 0.008705979213118553f, 0.01571616716682911f, 0.008512547239661217f, 0.005795423407107592f, 0.005080681759864092f, 0.007962062023580074f, 0.005968877114355564f, 0.004010705277323723f, 0.00588963134214282f, 0.0029290346428751945f, 0.004261421505361795f, 0.002787009347230196f, 0.012331672944128513f, 0.009056317619979382f, 0.007884956896305084f, 0.0069588832557201385f, 0.004402851220220327f, 0.0037137973122298717f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #142 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003812658542301506f, 0.00017774253501556814f, 9.567919914843515e-05f, 0.00011172426457051188f, 9.928851795848459e-05f, 0.00028772783116437495f, 0.00010869919788092375f, 0.0004828408418688923f, 0.0001264791062567383f, 0.00010836261935764924f, 0.00013827851216774434f, 0.00014229613589122891f, 0.00043707029544748366f, 6.207262049429119e-05f, 0.00026364601217210293f, 0.00014050140453036875f, 6.898336869198829e-05f, 0.0004806513024959713f, 0.00014371135330293328f, 0.00017664485494606197f, 0.00017100143304560333f, 0.00019525877723935992f, 0.0003182846703566611f, 0.00027368831797502935f, 4.983073813491501e-05f, 0.000254136451985687f, 0.00012726959539577365f, 0.0003988478274550289f, 0.00019499369955155998f, 0.00011614930554060265f, 0.00021539094450417906f, 0.00012020602298434824f, 0.00029310572426766157f, 0.00046925953938625753f, 0.0002906493318732828f, 0.0003664253745228052f, 0.00044301801244728267f, 7.614268542965874e-05f, 0.00013760362344328314f, 0.00023680923914071172f, 0.00018860642740037292f, 0.00012675569450948387f, 0.00017920583195518702f, 8.604760660091415e-05f, 0.00014589892816729844f, 0.00014679467130918056f, 8.974324009614065e-05f, 0.00019615488417912275f, 6.030898293829523e-05f, 0.00012956840510014445f, 0.00019744796736631542f, 2.8814756660722196e-05f, 5.101226270198822e-05f, 0.0005947729805484414f, 9.852593211689964e-05f, 0.0005529350019060075f, 0.00016656573279760778f, 6.127237429609522e-05f, 0.0002405305567663163f, 0.00011421075032558292f, 0.0001541168021503836f, 0.00012317283835727721f, 0.0001356877328362316f, 0.00013784569455310702f, 0.0003515021235216409f, 0.00013667313032783568f, 0.00018819062097463757f, 0.00018522168102208525f, 0.00010278016998199746f, 0.0002090043417410925f, 0.0001630119513720274f, 0.00034071950358338654f, 0.0001551321620354429f, 0.0001223849831148982f, 0.0002444669953547418f, 0.00010424570791656151f, 0.00011680629540933296f, 0.00010955329344142228f, 0.00025123864179477096f, 0.00010486689279787242f, 0.00034178109490312636f, 0.00012429141497705132f, 0.00012032671656925231f, 0.0006692879251204431f, 0.00016593329200986773f, 0.00019109495042357594f, 0.0001665039744693786f, 8.556291140848771e-05f, 0.00020201299048494548f, 4.0649192669661716e-05f, 0.00012648892879951745f, 0.0001277028932236135f, 3.469902367214672e-05f, 0.0001107610878534615f, 3.362862116773613e-05f, 0.00022768393682781607f, 0.00015137871378101408f, 0.00014759658370167017f, 0.00012316557695157826f, 0.00016245487495325506f, 0.0003094591083936393f, 0.00018772957264445722f, 0.0004317967395763844f, 3.5606986784841865e-05f, 0.00015574556891806424f, 0.0005446269642561674f, 5.649211016134359e-05f, 0.00014950086188036948f, 0.00029893554165028036f, 9.380795381730422e-05f, 0.00012458412675186992f, 0.00017646652122493833f, 0.0002820710651576519f, 3.903750257450156e-05f, 0.0002973343071062118f, 0.00013490171113517135f, 0.00023352765128947794f, 0.0003179508785251528f, 3.606887912610546e-05f, 9.93568028206937e-05f, 0.0004427727253641933f, 0.0001571466273162514f, 0.00025938882026821375f, 0.0003578028117772192f, 0.00010477926844032481f, 0.00011913620255654678f, 0.0001572959154145792f, 0.00014548790932167321f, 0.00021168601233512163f, 0.0003557951422408223f, 0.00018612289568409324f, 0.0005680625909008086f, 3.507900328258984e-05f, 0.0002675677533261478f, 0.00032733340049162507f, 0.00014850779552944005f, 4.231457205605693e-05f, 0.00014639705477748066f, 9.223571396432817e-05f, 0.00010364535410190001f, 0.00010744726023403928f, 0.00016413562116213143f, 8.068275201367214e-05f, 8.076872472884133e-05f, 0.0003387918113730848f, 0.00012427128967829049f, 0.0001397488231305033f, 0.00012652164150495082f, 0.0003511101531330496f, 0.00019755217363126576f, 0.00012183719081804156f, 0.00017847194976639003f, 9.332662011729553e-05f, 4.778313814313151e-05f, 0.00011429904407123104f, 0.0001226116146426648f, 0.00018587097292765975f, 0.00022941258794162422f, 0.00011073901987401769f, 0.00023843039525672793f, 9.8100645118393e-05f, 0.0001901949435705319f, 0.00026314702699892223f, 0.00013051845598965883f, 8.580787107348442e-05f, 0.00019081511709373444f, 0.00016076827887445688f, 0.00018683868984226137f, 0.0004382749320939183f, 9.762714762473479e-05f, 0.00012326976866461337f, 5.280012192088179e-05f, 0.00014498259406536818f, 0.0001349626836599782f, 0.00020484656852204353f, 0.0003697921638377011f, 0.00020029523875564337f, 0.00013636291259899735f, 0.00011954545334447175f, 0.00018734263721853495f, 0.00014044417184777558f, 9.436954132979736e-05f, 0.0001385795621899888f, 6.891846715006977e-05f, 0.000100268742244225f, 6.557669257745147e-05f, 0.0002901570114772767f, 0.00021308983559720218f, 0.00018552840629126877f, 0.00016373842663597316f, 0.00010359650332247838f, 8.738346514292061e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #143 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_50_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0101264463737607f, 0.00918611977249384f, 0.010365044698119164f, 0.005089129786938429f, 0.011219711042940617f, 0.006908455863595009f, 0.004548918455839157f, 0.00854492001235485f, 0.006949711125344038f, 0.018635744228959084f, 0.00885335449129343f, 0.00902105774730444f, 0.009762370958924294f, 0.005212767980992794f, 0.006458087358623743f, 0.006344901397824287f, 0.014575164765119553f, 0.015147115103900433f, 0.007065828889608383f, 0.01379906851798296f, 0.030049363151192665f, 0.014199403114616871f, 0.027553731575608253f, 0.005239518359303474f, 0.03390667587518692f, 0.009121792390942574f, 0.023977886885404587f, 0.018095890060067177f, 0.00576006667688489f, 0.007393766660243273f, 0.004664139822125435f, 0.008322687819600105f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #144 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_50_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00023826933465898037f, 0.00021614400611724705f, 0.0002438834053464234f, 0.00011974423250649124f, 0.0002639931917656213f, 0.0001625519071239978f, 0.00010703337466111407f, 0.000201056944206357f, 0.00016352262173313648f, 0.0004384881176520139f, 0.00020831423171330243f, 0.0002122601872542873f, 0.00022970285499468446f, 0.00012265336408745497f, 0.00015195499872788787f, 0.00014929179451428354f, 0.00034294507349841297f, 0.0003564027138054371f, 0.00016625480202492326f, 0.0003246839623898268f, 0.0007070438587106764f, 0.00033410362084396183f, 0.0006483230972662568f, 0.00012328279262874275f, 0.0007978041539900005f, 0.00021463041775859892f, 0.0005641856114380062f, 0.0004257856635376811f, 0.00013553097960539162f, 0.00017397098417859524f, 0.00010974446922773495f, 0.00019582794629968703f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #145 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_52_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0007653206121176481f, 0.0006299425149336457f, 0.0005949361948296428f, 0.0004726735351141542f, 0.0006513496628031135f, 0.001058668247424066f, 0.001816323958337307f, 0.0010857894085347652f, 0.001072707469575107f, 0.0011234898120164871f, 0.000573095167055726f, 0.0006114342832006514f, 0.0005448478041216731f, 0.0007142863469198346f, 0.0013426911318674684f, 0.0006049048388376832f, 0.0008690024842508137f, 0.0002919101098086685f, 0.0009353847126476467f, 0.00098491704557091f, 0.0011313777649775147f, 0.000485420721815899f, 0.0006553393322974443f, 0.0006643316592089832f, 0.0007078956696204841f, 0.0007084241369739175f, 0.0007156254723668098f, 0.0008788052364252508f, 0.0006407378823496401f, 0.0005908616585657f, 0.0008390236180275679f, 0.0008337265462614596f, 0.0007419582107104361f, 0.0007365032797679305f, 0.0006312023033387959f, 0.0009218861232511699f, 0.0012705380795523524f, 0.0006730147288180888f, 0.0005956536042504013f, 0.0008489458705298603f, 0.0007397206500172615f, 0.0006131107802502811f, 0.001136388280428946f, 0.0008339046034961939f, 0.0007653885404579341f, 0.0007062885561026633f, 0.0009955508867278695f, 0.0007945940596982837f, 0.0008887035073712468f, 0.0006127237575128675f, 0.000698669464327395f, 0.0006550028920173645f, 0.0006830821512266994f, 0.0010010439436882734f, 0.0011202315799891949f, 0.0007012280984781682f, 0.0008057239465415478f, 0.000580072752200067f, 0.0007062641670927405f, 0.0006601916393265128f, 0.0010650847107172012f, 0.0005910960026085377f, 0.0007692505605518818f, 0.0004490108403842896f, 0.0010924324160441756f, 0.0008853590115904808f, 0.0008410512236878276f, 0.0009643537341617048f, 0.0007739486754871905f, 0.0009991846745833755f, 0.0006546428776346147f, 0.0007597490912303329f, 0.0006493020919151604f, 0.0011633310932666063f, 0.0007234367658384144f, 0.00120117561891675f, 0.0009501111344434321f, 0.0008759661577641964f, 0.00012707778660114855f, 0.00046699753147549927f, 0.000810597266536206f, 0.0007498445920646191f, 0.001393856480717659f, 0.0007382231997326016f, 0.001074098632670939f, 0.000963011581916362f, 0.0006063252221792936f, 0.0007428828394040465f, 0.0014866265701130033f, 0.0005553147057071328f, 0.00123645702842623f, 0.0008591893711127341f, 0.0010322353336960077f, 0.0008031727047637105f, 0.0011823801323771477f, 0.0010679407278075814f, 0.0012993600685149431f, 0.0004921942600049078f, 0.0009617205942049623f, 0.0005668814992532134f, 0.0008156906696967781f, 0.0007449545082636178f, 0.001065681572072208f, 0.000648419139906764f, 0.0006072766846045852f, 0.0008604033500887454f, 0.0006203708471730351f, 0.0007727888878434896f, 0.000455924920970574f, 0.0010554728796705604f, 0.0006336540682241321f, 0.0008895943174138665f, 0.0008807274280115962f, 0.0005733222351409495f, 0.0008103718282654881f, 0.0011205404298380017f, 0.0009419800480827689f, 0.0007543040555901825f, 0.000549929216504097f, 0.001017384696751833f, 0.0009328936575911939f, 0.00047038288903422654f, 0.001226139604113996f, 0.0008944662404246628f, 0.0010733610251918435f, 0.0009951255051419139f, 0.0009900034638121724f, 0.000466043857159093f, 0.0005946456803940237f, 0.00018142240878660232f, 0.0005543497973121703f, 0.0008888635202310979f, 0.0014755802694708109f, 0.0005209995433688164f, 0.0010578507790341973f, 0.0005582949379459023f, 0.0006605645176023245f, 0.0006793899228796363f, 0.0006175234448164701f, 0.0008597653941251338f, 0.0009327676962129772f, 0.0007032018038444221f, 0.0004550608282443136f, 0.0006568426615558565f, 0.0012350326869636774f, 0.0015564350178465247f, 0.0006890520453453064f, 0.0006754823843948543f, 0.0006636612233705819f, 0.0006759475218132138f, 0.0007022958598099649f, 0.0006855291430838406f, 0.000758960610255599f, 0.0007065821555443108f, 0.0005751291173510253f, 0.0007913770969025791f, 0.0007944457465782762f, 0.0009448741329833865f, 0.0015702878590673208f, 0.0005577494157478213f, 0.0007833252311684191f, 0.0005640321760438383f, 0.00079737463966012f, 0.0010043868096545339f, 0.0004153692570980638f, 0.000635752861853689f, 0.0005910141044296324f, 0.0006366406450979412f, 0.0008556043612770736f, 0.0007082324591465294f, 0.0008418225916102529f, 0.0006507334182970226f, 0.0006876332918182015f, 0.0008901226683519781f, 0.0006700005033053458f, 0.0009134577121585608f, 0.0011370222782716155f, 0.0008243468473665416f, 0.00081832759315148f, 0.0009958473965525627f, 0.0013876970624551177f, 0.000685600854922086f, 0.0006086709327064455f, 0.0005869036540389061f, 0.0007114008767530322f, 0.0009374994551762938f, 0.0007523528183810413f, 0.0005065113073214889f, 0.0004675897944252938f, 0.0012141509214416146f, 0.0007564661209471524f, 0.00018892358639277518f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #146 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_52_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00016858801245689392f, 0.00013876636512577534f, 0.0001310550287598744f, 0.00010412249685032293f, 0.00014348201511893421f, 0.00023320784384850413f, 0.00040010741213336587f, 0.00023918220540508628f, 0.00023630047508049756f, 0.0002474870125297457f, 0.00012624378723558038f, 0.00013468929682858288f, 0.00012002134462818503f, 0.0001573459740029648f, 0.000295773585094139f, 0.00013325095642358065f, 0.00019142749079037458f, 6.430317444028333e-05f, 0.0002060504339169711f, 0.0002169616345781833f, 0.00024922459851950407f, 0.00010693049989640713f, 0.00014436087803915143f, 0.00014634174294769764f, 0.00015593820717185736f, 0.0001560546224936843f, 0.00015764095587655902f, 0.0001935868785949424f, 0.0001411444100085646f, 0.00013015746662858874f, 0.00018482361338101327f, 0.00018365675350651145f, 0.00016344164032489061f, 0.00016224001592490822f, 0.0001390438701491803f, 0.00020307691011112183f, 0.000279879430308938f, 0.00014825449034105986f, 0.00013121306255925447f, 0.0001870093256002292f, 0.00016294873785227537f, 0.00013505859533324838f, 0.00025032833218574524f, 0.00018369598546996713f, 0.00016860297182574868f, 0.00015558418817818165f, 0.0002193041000282392f, 0.0001750364899635315f, 0.00019576730846893042f, 0.00013497333566192538f, 0.0001539058139314875f, 0.00014428676513489336f, 0.00015047218766994774f, 0.00022051413543522358f, 0.0002467692829668522f, 0.0001544694387121126f, 0.0001774882257450372f, 0.00012778084783349186f, 0.00015557881852146238f, 0.00014542975986842066f, 0.00023462130047846586f, 0.00013020908227190375f, 0.0001694537204457447f, 9.890997898764908e-05f, 0.00024064556055236608f, 0.00019503057410474867f, 0.00018527026986703277f, 0.00021243185619823635f, 0.00017048863810487092f, 0.00022010455722920597f, 0.00014420745719689876f, 0.00016736068937461823f, 0.00014303096395451576f, 0.00025626341812312603f, 0.00015936166164465249f, 0.00026459997752681375f, 0.00020929443417117f, 0.00019296146638225764f, 2.799322464852594e-05f, 0.00010287215991411358f, 0.00017856173508334905f, 0.00016517889162059873f, 0.0003070445090997964f, 0.00016261887503787875f, 0.00023660692386329174f, 0.00021213620493654162f, 0.000133563851704821f, 0.00016364532348234206f, 0.0003274802875239402f, 0.00012232703738845885f, 0.00027237189351581037f, 0.0001892658183351159f, 0.00022738509869668633f, 0.00017692623077891767f, 0.0002604596083983779f, 0.00023525042342953384f, 0.00028622846002690494f, 0.00010842260235222057f, 0.00021185181685723364f, 0.00012487501953728497f, 0.00017968373140320182f, 0.00016410168609581888f, 0.00023475277703255415f, 0.0001428364630555734f, 0.00013377344293985516f, 0.0001895332388812676f, 0.00013665787992067635f, 0.00017023315012920648f, 0.00010043304064311087f, 0.00023250396770890802f, 0.0001395839499309659f, 0.00019596354104578495f, 0.0001940103102242574f, 0.00012629380216822028f, 0.00017851208394858986f, 0.0002468372986186296f, 0.000207503282581456f, 0.00016616123321000487f, 0.00012114069977542385f, 0.0002241137408418581f, 0.0002055016957456246f, 0.0001036179019138217f, 0.0002700991462916136f, 0.000197036744793877f, 0.0002364444371778518f, 0.0002192103856941685f, 0.00021808208839502186f, 0.00010266208118991926f, 0.00013099102943670005f, 3.996448504040018e-05f, 0.0001221144775627181f, 0.00019580255320761353f, 0.0003250469744671136f, 0.0001147679504356347f, 0.00023302777844946831f, 0.0001229835324920714f, 0.0001455119054298848f, 0.00014965883747208863f, 0.00013603063416667283f, 0.00018939269648399204f, 0.0002054739452432841f, 0.00015490422083530575f, 0.00010024269431596622f, 0.00014469203597400337f, 0.0002720581542234868f, 0.0003428579948376864f, 0.00015178725880105048f, 0.0001487980771344155f, 0.00014619405556004494f, 0.00014890053716953844f, 0.00015470465586986393f, 0.0001510112197138369f, 0.00016718699771445245f, 0.0001556488568894565f, 0.0001266918407054618f, 0.00017432784079574049f, 0.0001750038209138438f, 0.00020814080198761076f, 0.0003459095605649054f, 0.00012286336277611554f, 0.0001725541369523853f, 0.00012424735177773982f, 0.0001756490091793239f, 0.00022125050600152463f, 9.149927063845098e-05f, 0.00014004629338160157f, 0.0001301910524489358f, 0.0001402418565703556f, 0.00018847608589567244f, 0.00015601239283569157f, 0.0001854401925811544f, 0.00014334626030176878f, 0.00015147472731769085f, 0.00019607992726378143f, 0.0001475905010011047f, 0.0002012202749028802f, 0.0002504680014681071f, 0.0001815905561670661f, 0.00018026461475528777f, 0.0002193694090237841f, 0.0003056876885239035f, 0.00015102700854185969f, 0.00013408056111074984f, 0.0001292855740757659f, 0.00015671034634578973f, 0.0002065162843791768f, 0.0001657314132899046f, 0.00011157641711179167f, 0.0001030026251100935f, 0.00026745820650830865f, 0.00016663750284351408f, 4.161687320447527e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #147 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_54_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004314908757805824f, 0.0026494483463466167f, 0.0033749935682862997f, 0.0045773619785904884f, 0.004104216117411852f, 0.0035769487731158733f, 0.0009729044395498931f, 0.0039015973452478647f, 0.006177680566906929f, 0.004992414731532335f, 0.004664007108658552f, 0.004513063468039036f, 0.0019481312483549118f, 0.0025273326318711042f, 0.0032668483909219503f, 0.003509611589834094f, 0.0015259088249877095f, 0.011944684199988842f, 0.004345881752669811f, 0.0039019035175442696f, 0.0014141497667878866f, 0.002185175893828273f, 0.006100804544985294f, 0.004934641066938639f, 0.003092352068051696f, 0.005519087892025709f, 0.0034143917728215456f, 0.0020023109391331673f, 0.003921364434063435f, 0.0017979337135329843f, 0.001487041707150638f, 0.0014639911241829395f, 0.002002543769776821f, 0.0016757763223722577f, 0.004346621222794056f, 0.0035552051849663258f, 0.002765296259894967f, 0.003043955424800515f, 0.0035127003211528063f, 0.00319747650064528f, 0.0035353570710867643f, 0.002480089198797941f, 0.003871700493618846f, 0.002133316360414028f, 0.004076442215591669f, 0.0023897429928183556f, 0.00414830818772316f, 0.0038531264290213585f, 0.004322872031480074f, 0.004775397013872862f, 0.00325251673348248f, 0.0021900911815464497f, 0.003465766552835703f, 0.002381106372922659f, 0.005391736049205065f, 0.0038462579250335693f, 0.004639057908207178f, 0.00477550458163023f, 0.0031398527789860964f, 0.00628485344350338f, 0.003518199548125267f, 0.002252047648653388f, 0.003011804074048996f, 0.003793494077399373f, 0.003603368066251278f, 0.002489405684173107f, 0.00362050230614841f, 0.005420824512839317f, 0.001460599829442799f, 0.0036074756644666195f, 0.003920667339116335f, 0.004424818325787783f, 0.003976491279900074f, 0.0011296524899080396f, 0.003467186586931348f, 0.004339213483035564f, 0.005244982894510031f, 0.003205004381015897f, 0.00525083439424634f, 0.008910317905247211f, 0.005257208365947008f, 0.004057386890053749f, 0.0023099679965525866f, 0.0016007745871320367f, 0.0023616363760083914f, 0.002317880280315876f, 0.0033954186365008354f, 0.0017828105483204126f, 0.004012363031506538f, 0.00646184990182519f, 0.0024492342490702868f, 0.0033052561338990927f, 0.004411769565194845f, 0.004663617350161076f, 0.0030465126037597656f, 0.00238631060346961f, 0.001221217098645866f, 0.0054838345386087894f, 0.00553191639482975f, 0.0031561327632516623f, 0.0037597501650452614f, 0.004062952473759651f, 0.0024915479589253664f, 0.002212540479376912f, 0.004302074667066336f, 0.001806753221899271f, 0.003331280080601573f, 0.002616901881992817f, 0.004185068421065807f, 0.0036220094189047813f, 0.003432272933423519f, 0.002470677252858877f, 0.0027315232437103987f, 0.003053679596632719f, 0.004891824442893267f, 0.004931086208671331f, 0.001705142087303102f, 0.004654018674045801f, 0.00760864419862628f, 0.003991310019046068f, 0.004837697371840477f, 0.005580045748502016f, 0.0018286440754309297f, 0.0036427276208996773f, 0.001663564587943256f, 0.0016784906620159745f, 0.005600806791335344f, 0.005641627125442028f, 0.002422882942482829f, 0.011194935068488121f, 0.005050571169704199f, 0.0039756642654538155f, 0.0014278708258643746f, 0.002159907715395093f, 0.00431427638977766f, 0.004758033901453018f, 0.004211979452520609f, 0.003245822386816144f, 0.002405528211966157f, 0.004350580740720034f, 0.004991121590137482f, 0.006606617942452431f, 0.009653797373175621f, 0.0022174594923853874f, 0.00487481290474534f, 0.001902707270346582f, 0.004109630826860666f, 0.0025913314893841743f, 0.004313227254897356f, 0.003738251980394125f, 0.0024465767201036215f, 0.00378734664991498f, 0.005164913833141327f, 0.0020317048765718937f, 0.006337813101708889f, 0.0023614675737917423f, 0.0033381888642907143f, 0.003162107430398464f, 0.00134503364097327f, 0.004035307560116053f, 0.0036809330340474844f, 0.005619869567453861f, 0.005405685398727655f, 0.002648942405357957f, 0.0038413063157349825f, 0.005155226681381464f, 0.0022631012834608555f, 0.004004153423011303f, 0.002528493758291006f, 0.0031233401969075203f, 0.0038173417560756207f, 0.002338931430131197f, 0.003220207756385207f, 0.003001332748681307f, 0.005252020433545113f, 0.0038994373753666878f, 0.0028445625212043524f, 0.00403415085747838f, 0.004373136442154646f, 0.003192092292010784f, 0.0016754998359829187f, 0.003159981919452548f, 0.0034963779617100954f, 0.0031821441370993853f, 0.0019517902983352542f, 0.001863130833953619f, 0.002626303816214204f, 0.0038390683475881815f, 0.004374506883323193f, 0.0037297706585377455f, 0.0032025587279349566f, 0.008879171684384346f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #148 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_54_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001015272646327503f, 6.233996100490913e-05f, 7.941161311464384e-05f, 0.0001077026390703395f, 9.656979091232643e-05f, 8.416350465267897e-05f, 2.2891868866281584e-05f, 9.180229244520888e-05f, 0.0001453571894671768f, 0.00011746858217520639f, 0.00010974134784191847f, 0.0001061897273757495f, 4.583838381222449e-05f, 5.946665260125883e-05f, 7.686702156206593e-05f, 8.2579099398572e-05f, 3.5903736716136336e-05f, 0.00028105141245760024f, 0.00010225604637525976f, 9.180949564324692e-05f, 3.327411104692146e-05f, 5.141590372659266e-05f, 0.0001435483427485451f, 0.00011610920046223328f, 7.276122778421268e-05f, 0.00012986089859623462f, 8.033862832235172e-05f, 4.7113200707826763e-05f, 9.226740075973794e-05f, 4.2304323869757354e-05f, 3.4989217965630814e-05f, 3.4446849895175546e-05f, 4.7118679503910244e-05f, 3.943003321182914e-05f, 0.00010227344318991527f, 8.365188841708004e-05f, 6.506579666165635e-05f, 7.162248220993206e-05f, 8.265177166322246e-05f, 7.523474050685763e-05f, 8.318487380165607e-05f, 5.835504271090031e-05f, 9.10988383111544e-05f, 5.019567834096961e-05f, 9.591628622729331e-05f, 5.622924800263718e-05f, 9.760725515661761e-05f, 9.066180064110085e-05f, 0.00010171463509323075f, 0.00011236228601774201f, 7.652981003047898e-05f, 5.153155871084891e-05f, 8.154744864441454e-05f, 5.602603414445184e-05f, 0.00012686438276432455f, 9.050018707057461e-05f, 0.00010915430902969092f, 0.00011236481805099174f, 7.38788876333274e-05f, 0.00014787890540901572f, 8.27811672934331e-05f, 5.298935866449028e-05f, 7.086597906891257e-05f, 8.925868314690888e-05f, 8.478513336740434e-05f, 5.8574252761900425e-05f, 8.518829417880625e-05f, 0.00012754881754517555f, 3.43670544680208e-05f, 8.488177991239354e-05f, 9.225100075127557e-05f, 0.00010411337279947475f, 9.356450027553365e-05f, 2.6580059056868777e-05f, 8.158085984177887e-05f, 0.00010209914034930989f, 0.00012341135879978538f, 7.541186641901731e-05f, 0.00012354904902167618f, 0.00020965453586541116f, 0.00012369902106001973f, 9.54679271671921e-05f, 5.435218918137252e-05f, 3.766528607229702e-05f, 5.5567914387211204e-05f, 5.4538359108846635e-05f, 7.989220466697589e-05f, 4.19484858866781e-05f, 9.440854046260938e-05f, 0.00015204353258013725f, 5.762904402217828e-05f, 7.777073187753558e-05f, 0.00010380634194007143f, 0.00010973217285936698f, 7.168265437940136e-05f, 5.614848487311974e-05f, 2.873452103813179e-05f, 0.00012903141032438725f, 0.0001301627344219014f, 7.426195224979892e-05f, 8.846470882417634e-05f, 9.559888712828979e-05f, 5.862466059625149e-05f, 5.20597786817234e-05f, 0.00010122529056388885f, 4.251184145687148e-05f, 7.838306191843003e-05f, 6.157416646601632e-05f, 9.84721991699189e-05f, 8.522374992026016e-05f, 8.07593678473495e-05f, 5.8133584388997406e-05f, 6.427113839890808e-05f, 7.185128924902529e-05f, 0.00011510175681905821f, 0.00011602556332945824f, 4.012099088868126e-05f, 0.00010950632713502273f, 0.00017902693070936948f, 9.391317871632054e-05f, 0.00011382817319827154f, 0.00013129519356880337f, 4.302692104829475e-05f, 8.571123908041045e-05f, 3.914269836968742e-05f, 3.9493897929787636e-05f, 0.00013178368681110442f, 0.00013274417142383754f, 5.7009012380149215e-05f, 0.00026341024204157293f, 0.00011883697152370587f, 9.354504436487332e-05f, 3.359695983817801e-05f, 5.082135976408608e-05f, 0.0001015123852994293f, 0.00011195374099770561f, 9.910540393320844e-05f, 7.637229282408953e-05f, 5.66006638109684e-05f, 0.00010236660455120727f, 0.00011743815412046388f, 0.00015544983034487814f, 0.0002271481789648533f, 5.217551733949222e-05f, 0.00011470148456282914f, 4.476958201848902e-05f, 9.669720020610839e-05f, 6.0972506616963074e-05f, 0.00010148770525120199f, 8.795886969892308e-05f, 5.756651080446318e-05f, 8.911403710953891e-05f, 0.00012152738781878725f, 4.7804820496821776e-05f, 0.00014912501501385123f, 5.5563945352332667e-05f, 7.854562136344612e-05f, 7.440253102686256e-05f, 3.16478508466389e-05f, 9.494841651758179e-05f, 8.661019091960043e-05f, 0.00013223222049418837f, 0.00012719260121230036f, 6.232805753825232e-05f, 9.038367716129869e-05f, 0.00012129945389460772f, 5.3249441407388076e-05f, 9.421537833986804e-05f, 5.949397018412128e-05f, 7.349035877268761e-05f, 8.98198049981147e-05f, 5.503368083736859e-05f, 7.576959615107626e-05f, 7.061959331622347e-05f, 0.0001235769595950842f, 9.17514698812738e-05f, 6.693088653264567e-05f, 9.492119716014713e-05f, 0.00010289732745150104f, 7.510805880883709e-05f, 3.9423524867743254e-05f, 7.435251609422266e-05f, 8.22677175165154e-05f, 7.487398397643119e-05f, 4.5924480218673125e-05f, 4.383837222121656e-05f, 6.179538468131796e-05f, 9.033102105604485e-05f, 0.0001029295744956471f, 8.775931200943887e-05f, 7.535432087024674e-05f, 0.00020892168686259538f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #149 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_55_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009533325210213661f, 0.008584550581872463f, 0.008388248272240162f, 0.010866490192711353f, 0.010092702694237232f, 0.008638420142233372f, 0.012402785941958427f, 0.008882776834070683f, 0.009763581678271294f, 0.009203629568219185f, 0.009199123829603195f, 0.007536252029240131f, 0.010540405288338661f, 0.007845109328627586f, 0.012860418297350407f, 0.010717393830418587f, 0.010358933359384537f, 0.011385289952158928f, 0.007690103258937597f, 0.009190372191369534f, 0.0074843354523181915f, 0.008188857696950436f, 0.008919746614992619f, 0.011640510521829128f, 0.007441951893270016f, 0.00814113300293684f, 0.011725598946213722f, 0.008650464937090874f, 0.0076873344369232655f, 0.008572283200919628f, 0.00872004497796297f, 0.00610449118539691f, 0.010987033136188984f, 0.008815216831862926f, 0.008693328127264977f, 0.009604510851204395f, 0.009939659386873245f, 0.0071606081910431385f, 0.008906310424208641f, 0.007439324166625738f, 0.008104548789560795f, 0.006380293518304825f, 0.01788734272122383f, 0.008142066188156605f, 0.008164488710463047f, 0.0071101984940469265f, 0.00856119953095913f, 0.01051352359354496f, 0.009092814289033413f, 0.007715991698205471f, 0.010086922906339169f, 0.007952072657644749f, 0.009709075093269348f, 0.008111713454127312f, 0.009539705701172352f, 0.011278841644525528f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #150 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_55_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00022431353863794357f, 0.00020198943093419075f, 0.0001973705511773005f, 0.0002556821273174137f, 0.00023747536761220545f, 0.0002032569464063272f, 0.0002918302488978952f, 0.00020900652452837676f, 0.00022973133309278637f, 0.00021655599994119257f, 0.0002164499746868387f, 0.00017732358537614346f, 0.0002480095427017659f, 0.00018459081184118986f, 0.00030259808409027755f, 0.00025217398069798946f, 0.0002437396178720519f, 0.00026788917602971196f, 0.00018094360711984336f, 0.00021624405053444207f, 0.00017610201030038297f, 0.00019267901370767504f, 0.00020987639436498284f, 0.000273894373094663f, 0.00017510475299786776f, 0.00019155607151333243f, 0.0002758964546956122f, 0.00020354035950731486f, 0.00018087845819536597f, 0.00020170077914372087f, 0.0002051775372819975f, 0.0001436350867152214f, 0.00025851844111457467f, 0.00020741687330882996f, 0.00020454889454413205f, 0.00022598849318455905f, 0.00023387433611787856f, 0.0001684848975855857f, 0.00020956025400664657f, 0.00017504292191006243f, 0.00019069526751991361f, 0.0001501245569670573f, 0.00042087867041118443f, 0.00019157803035341203f, 0.0001921056245919317f, 0.00016729878552723676f, 0.0002014399942709133f, 0.0002473770291544497f, 0.00021394857321865857f, 0.0001815527502913028f, 0.00023733936541248113f, 0.00018710759468376637f, 0.00022844882914796472f, 0.00019086385145783424f, 0.00022446367074735463f, 0.00026538450038060546f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #151 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0004292858357075602f, 0.0005573263624683022f, 0.00040907340007834136f, 0.0007260118727572262f, 0.0005148794734850526f, 0.0005679685273207724f, 0.0005150361103005707f, 0.0009229715797118843f, 0.0007861324120312929f, 0.0004690679779741913f, 0.000484778342070058f, 0.0006044183392077684f, 0.0004163326520938426f, 0.00040144348167814314f, 0.0005693355924449861f, 0.000824830261990428f, 0.0007785637862980366f, 0.0016101335640996695f, 0.0005788090056739748f, 0.000602437648922205f, 0.000967905973084271f, 0.0005683291819877923f, 0.0006322715780697763f, 0.0006145351799204946f, 0.0005178914871066809f, 0.0007041294011287391f, 0.0004777975264005363f, 0.0009330672910436988f, 0.0009362092241644859f, 0.0005970708443783224f, 0.0007456050952896476f, 0.001274197013117373f, 0.0004618161474354565f, 0.0008420507656410336f, 0.0014397981576621532f, 0.0014380371430888772f, 0.0006781696574762464f, 0.0013118732022121549f, 0.000704277481418103f, 0.0004688726912718266f, 0.000779030320700258f, 0.001924334210343659f, 0.0007867860840633512f, 0.0006610905984416604f, 0.0008392397430725396f, 0.00047642859863117337f, 0.0008134982781484723f, 0.0009492703247815371f, 0.0009797585662454367f, 0.0006502544274553657f, 0.000961769837886095f, 0.0005364881944842637f, 0.0005042045377194881f, 0.000522447400726378f, 0.0009910512017086148f, 0.0010730904759839177f, 0.0007974143954925239f, 0.0013076630420982838f, 0.0014045099960640073f, 0.0009525254718028009f, 0.0011431716848164797f, 0.003588717197999358f, 0.0009396058158017695f, 0.0009595952578820288f, 0.0005786056281067431f, 0.0010048907715827227f, 0.0006285416893661022f, 0.0011238630395382643f, 0.0007415009895339608f, 0.0011331979185342789f, 0.0005774335004389286f, 0.0015709807630628347f, 0.000394271599361673f, 0.0004936536424793303f, 0.0010369508527219296f, 0.000987194711342454f, 0.001059159985743463f, 0.00035875928006134927f, 0.0009492933750152588f, 0.0010158659424632788f, 0.0005084961885586381f, 0.0005768781411461532f, 0.0013241821434348822f, 0.0008347340044565499f, 0.0006211517029441893f, 0.0010432974668219686f, 0.0004932357114739716f, 0.0009661538060754538f, 0.001089937868528068f, 0.0015245558461174369f, 0.0006366211455315351f, 0.000887481786776334f, 0.0008756717434152961f, 0.000677277974318713f, 0.0008258528541773558f, 0.0004773772961925715f, 0.0006047216011211276f, 0.00038295378908514977f, 0.0006154270959086716f, 0.00042180027230642736f, 0.0008751673740334809f, 0.0009809371549636126f, 0.0006114071002230048f, 0.0006457034032791853f, 0.0005594762042164803f, 0.0011376721085980535f, 0.0006024775793775916f, 0.0005689411773346364f, 0.0008815154433250427f, 0.0007793987169861794f, 0.0008786313701421022f, 0.0003590694395825267f, 0.0009322756086476147f, 0.0006261438247747719f, 0.0011871234746649861f, 0.0012701029190793633f, 0.0009809329640120268f, 0.0006507301586680114f, 0.0007793800323270261f, 0.0012517876457422972f, 0.0011989576742053032f, 0.0005910518229939044f, 0.0006023484747856855f, 0.0010605128481984138f, 0.0011509854812175035f, 0.00047690622159279883f, 0.0009177171159535646f, 0.0006379784317687154f, 0.0007719466229900718f, 0.00097542634466663f, 0.0010574678890407085f, 0.0006045941263437271f, 0.001956252846866846f, 0.001086596050299704f, 0.0008885955903679132f, 0.0010827851947396994f, 0.0011377132032066584f, 0.0005367817939259112f, 0.0013084583915770054f, 0.0006138593889772892f, 0.0012123218039050698f, 0.0006685921689495444f, 0.001143662491813302f, 0.0007773596444167197f, 0.0004223631403874606f, 0.001072858227416873f, 0.00043181743239983916f, 0.0008299274486489594f, 0.000467990234028548f, 0.0006561425398103893f, 0.000771346443798393f, 0.0009897274430841208f, 0.0009702134993858635f, 0.00027215946465730667f, 0.0011848628055304289f, 0.0014811479486525059f, 0.0006345989531837404f, 0.0010355828562751412f, 0.0008458707015961409f, 0.001581934280693531f, 0.0005138227134011686f, 0.0004411432018969208f, 0.0005788367707282305f, 0.0009980074828490615f, 0.0007114824838936329f, 0.00079846300650388f, 0.001022895099595189f, 0.0005114852101542056f, 0.0009039583965204656f, 0.0011467484291642904f, 0.0017324271611869335f, 0.0005634224507957697f, 0.0005623736069537699f, 0.0009739467641338706f, 0.00025102912331931293f, 0.0007609115564264357f, 0.0015174213331192732f, 0.0006317541119642556f, 0.0009206318063661456f, 0.0005621887394227087f, 0.0011028610169887543f, 0.0009676131303422153f, 0.0007311873487196863f, 0.0005404276889748871f, 0.0011439656373113394f, 0.0008048088056966662f, 0.0005928612663410604f, 0.0004496588371694088f, 0.0009069514344446361f, 0.0008229276863858104f, 0.0011212972458451986f, 0.00032042645034380257f, 0.0012649830896407366f, 0.0004843043570872396f, 0.0003642999508883804f, 0.002302232664078474f, 0.0006788295577280223f, 0.0005031576147302985f, 0.0011653297115117311f, 0.0007154963095672429f, 0.001283424673601985f, 0.00050448311958462f, 0.0011317169992253184f, 0.0011204550974071026f, 0.0004353293334133923f, 0.0013179552042856812f, 0.0005034518544562161f, 0.0003792942443396896f, 0.0033408026210963726f, 0.001155529753305018f, 0.00093320501036942f, 0.001375598250888288f, 0.0012258555507287383f, 0.0006133100832812488f, 0.0009291814058087766f, 0.000768377271015197f, 0.000663168728351593f, 0.0005510458140634f, 0.0009852818911895156f, 0.0009334433707408607f, 0.0019347126362845302f, 0.0006776598165743053f, 0.0003715122875291854f, 0.0006033910904079676f, 0.0003061455499846488f, 0.0011469109449535608f, 0.0011456393403932452f, 0.0009130337275564671f, 0.0002562442678026855f, 0.0008723823120817542f, 0.0010401204926893115f, 0.0005696446751244366f, 0.00013729449710808694f, 0.0009562266059219837f, 8.248808747168823e-09f, 0.0003465105255600065f, 0.0006356291705742478f, 0.0004644569125957787f, 0.0011109377956017852f, 0.0008332155412063003f, 0.0008288684766739607f, 0.00037669253651984036f, 0.0008199381409212947f, 0.0005774049204774201f, 0.0009018636192195117f, 0.0004603192210197449f, 0.0008788726408965886f, 0.001233974238857627f, 0.0015696792397648096f, 0.0008403704850934446f, 0.0011186953634023666f, 0.0006399782723747194f, 0.0007694391533732414f, 0.0009070888627320528f, 0.0007168992888182402f, 0.0008703829953446984f, 0.0008026679279282689f, 0.0006494582048617303f, 0.001187171321362257f, 0.0006230896688066423f, 0.000994037021882832f, 0.0005582367884926498f, 0.0004947673878632486f, 0.0003460619191173464f, 0.0009544598287902772f, 0.0005282929632812738f, 0.0008626411436125636f, 0.00042830005986616015f, 0.0009380963747389615f, 0.0012376990634948015f, 0.00038440630305558443f, 0.0005566786276176572f, 0.000595782941672951f, 0.00039023629506118596f, 0.0007911575958132744f, 0.0009794948855414987f, 0.0005728279356844723f, 0.0013190658064559102f, 0.0008897414663806558f, 0.0005299331387504935f, 0.0008591028745286167f, 0.0008673944394104183f, 0.0005265825893729925f, 0.0007710435893386602f, 0.0004613729252014309f, 0.0007181822438724339f, 0.0004079521168023348f, 0.0012254122411832213f, 0.000605476088821888f, 0.0010225636651739478f, 0.00042088847840204835f, 0.001150153111666441f, 0.0004691889917012304f, 0.0007569235749542713f, 0.000803229515440762f, 0.0005900604301132262f, 0.000632172916084528f, 0.0008349006529897451f, 0.0007107594865374267f, 0.0008300148183479905f, 0.0009458669810555875f, 0.0014344279188662767f, 0.0009254715405404568f, 0.0008149297791533172f, 0.0008740840130485594f, 0.0005085791926831007f, 0.000610063667409122f, 0.0006398322293534875f, 0.0006539833266288042f, 0.0004556825151666999f, 0.0005118445260450244f, 0.0009463105234317482f, 0.0008628929499536753f, 0.0005833353498019278f, 0.00044552728650160134f, 0.0007002161000855267f, 0.0012015693355351686f, 0.0009570936672389507f, 0.0012327816803008318f, 0.0011633527465164661f, 0.000509640434756875f, 0.0009236938785761595f, 0.0012286078417673707f, 0.0011581461876630783f, 0.0012017444241791964f, 0.0013574251206591725f, 0.00032553254277445376f, 0.0006464249454438686f, 0.0014054672792553902f, 0.0008068879833444953f, 0.0011563068255782127f, 0.0007944353856146336f, 0.0013724536402150989f, 0.0010799398878589272f, 0.0012260808143764734f, 0.00012736738426610827f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #152 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.136705658514984e-05f, 6.6688000515569e-05f, 4.8948495532386005e-05f, 8.687240188010037e-05f, 6.160893099149689e-05f, 6.796140951337293e-05f, 6.162767385831103e-05f, 0.00011044001439586282f, 9.406625031260774e-05f, 5.612726818071678e-05f, 5.800712460768409e-05f, 7.23228877177462e-05f, 4.981711754226126e-05f, 4.80355229228735e-05f, 6.8124987592455e-05f, 9.869671339401975e-05f, 9.316061186837032e-05f, 0.00019266374874860048f, 6.925855268491432e-05f, 7.208588067442179e-05f, 0.00011581672879401594f, 6.800456321798265e-05f, 7.565572013845667e-05f, 7.35334397177212e-05f, 6.196934555191547e-05f, 8.42540102894418e-05f, 5.7171819207724184e-05f, 0.00011164803436258808f, 0.00011202399036847055f, 7.144370465539396e-05f, 8.921686821850017e-05f, 0.00015246660041157156f, 5.525953747564927e-05f, 0.00010075727186631411f, 0.00017228192882612348f, 0.00017207121709361672f, 8.114775118883699e-05f, 0.00015697481285315007f, 8.427173452218994e-05f, 5.610390144283883e-05f, 9.321643301518634e-05f, 0.00023026006238069385f, 9.414446685696021e-05f, 7.910411659395322e-05f, 0.00010042091162176803f, 5.700801921193488e-05f, 9.734076593304053e-05f, 0.00011358684423612431f, 0.0001172349730040878f, 7.780749729136005e-05f, 0.00011508249735925347f, 6.419456622097641e-05f, 6.0331603890517727e-05f, 6.251448940020055e-05f, 0.00011858621292049065f, 0.00012840279669035226f, 9.54162169364281e-05f, 0.00015647104009985924f, 0.00016805945779196918f, 0.00011397634079912677f, 0.00013678849791176617f, 0.00042941514402627945f, 0.00011243041808484122f, 0.00011482229456305504f, 6.923421460669488e-05f, 0.0001202422208734788f, 7.520941289840266e-05f, 0.00013447807577904314f, 8.872578473528847e-05f, 0.00013559506624005735f, 6.909396324772388e-05f, 0.00018797884695231915f, 4.7177356464089826e-05f, 5.906911610509269e-05f, 0.00012407843314576894f, 0.00011812475713668391f, 0.0001267359039047733f, 4.2928058974212036e-05f, 0.00011358960182406008f, 0.000121555473015178f, 6.084513006499037e-05f, 6.902751192683354e-05f, 0.000158447670401074f, 9.988177043851465e-05f, 7.432515121763572e-05f, 0.00012483785394579172f, 5.901910844841041e-05f, 0.00011560706479940563f, 0.00013041870261076838f, 0.00018242378428112715f, 7.617617666255683e-05f, 0.00010619340901030228f, 0.00010478025797056034f, 8.104104927042499e-05f, 9.881908044917509e-05f, 5.712153506465256e-05f, 7.235917291836813e-05f, 4.58231006632559e-05f, 7.364016346400604e-05f, 5.04713570990134e-05f, 0.00010471990390215069f, 0.00011737600289052352f, 7.315914263017476e-05f, 7.72629355196841e-05f, 6.694524199701846e-05f, 0.00013613043120130897f, 7.20906609785743e-05f, 6.80777957313694e-05f, 0.0001054794920491986f, 9.326051076641306e-05f, 0.00010513439337955788f, 4.2965173634001985e-05f, 0.00011155330139445141f, 7.492249278584495e-05f, 0.0001420476328348741f, 0.0001519767101854086f, 0.00011737550084944814f, 7.786441710777581e-05f, 9.325827704742551e-05f, 0.0001497851626481861f, 0.00014346367970574647f, 7.07234867149964e-05f, 7.20752141205594e-05f, 0.00012689779396168888f, 0.00013772347301710397f, 5.706516822101548e-05f, 0.00010981127707054839f, 7.633858331246302e-05f, 9.236882033292204e-05f, 0.0001167165901279077f, 0.00012653344310820103f, 7.23439225112088e-05f, 0.00023407935805153102f, 0.00013001883053220809f, 0.00010632668272592127f, 0.00012956283171661198f, 0.00013613534974865615f, 6.42297018202953e-05f, 0.00015656620962545276f, 7.345257472479716e-05f, 0.0001450627896701917f, 8.00017369328998e-05f, 0.00013684722944162786f, 9.301652607973665e-05f, 5.053870700066909e-05f, 0.00012837500253226608f, 5.1669980166479945e-05f, 9.930662781698629e-05f, 5.5998309107962996e-05f, 7.851205009501427e-05f, 9.229700663127005e-05f, 0.0001184278225991875f, 0.00011609283683355898f, 3.2565785659244284e-05f, 0.00014177712728269398f, 0.0001772297255229205f, 7.593420741613954e-05f, 0.00012391473865136504f, 0.00010121435479959473f, 0.0001892895088531077f, 6.148248212412e-05f, 5.2785871957894415e-05f, 6.926187052158639e-05f, 0.00011941858247155324f, 8.513386273989454e-05f, 9.554169082548469e-05f, 0.00012239656643941998f, 6.120278703747317e-05f, 0.00010816495341714472f, 0.00013721648429054767f, 0.00020729703828692436f, 6.741744437022135e-05f, 6.72919413773343e-05f, 0.00011653955152723938f, 3.0037392207304947e-05f, 9.104839409701526e-05f, 0.00018157008162233979f, 7.559380173915997e-05f, 0.00011016004282282665f, 6.726982246618718e-05f, 0.00013196504733059555f, 0.00011578168778214604f, 8.749168773647398e-05f, 6.466595368692651e-05f, 0.00013688349281437695f, 9.630100976210088e-05f, 7.094000466167927e-05f, 5.3804829803993925e-05f, 0.00010852309060283005f, 9.846906323218718e-05f, 0.00013417107402347028f, 3.8341269828379154e-05f, 0.00015136408910620958f, 5.795040851808153e-05f, 4.359104059403762e-05f, 0.0002754782617557794f, 8.122670988086611e-05f, 6.0206330090295523e-05f, 0.0001394398568663746f, 8.561414142604917e-05f, 0.00015357075608335435f, 6.036493869032711e-05f, 0.00013541786756832153f, 0.00013407030201051384f, 5.209020309848711e-05f, 0.00015770256868563592f, 6.024153844919056e-05f, 4.53852117061615e-05f, 0.0003997504245489836f, 0.00013826721988152713f, 0.0001116645144065842f, 0.0001645999582251534f, 0.0001466821995563805f, 7.338684372371063e-05f, 0.00011118306429125369f, 9.194172162096947e-05f, 7.935277972137555e-05f, 6.593648868147284e-05f, 0.00011789587733801454f, 0.0001116930361604318f, 0.00023150190827436745f, 8.108674228424206e-05f, 4.4454045564634725e-05f, 7.219996768981218e-05f, 3.663246025098488e-05f, 0.00013723592564929277f, 0.00013708377082366496f, 0.00010925087553914636f, 3.06614201690536e-05f, 0.00010438665049150586f, 0.00012445769971236587f, 6.81619712850079e-05f, 1.642824827285949e-05f, 0.00011441920651122928f, 9.870276818091384e-10f, 4.146241190028377e-05f, 7.605748396599665e-05f, 5.557552140089683e-05f, 0.00013293148367665708f, 9.970007522497326e-05f, 9.917991701513529e-05f, 4.507389894570224e-05f, 9.811134077608585e-05f, 6.909054354764521e-05f, 0.0001079142966773361f, 5.50804179511033e-05f, 0.00010516326437937096f, 0.00014765365631319582f, 0.00018782311235554516f, 0.00010055621532956138f, 0.00013385973579715937f, 7.65778822824359e-05f, 9.206878166878596e-05f, 0.00010853953426703811f, 8.578201959608123e-05f, 0.00010414741700515151f, 9.60448378464207e-05f, 7.771221862640232e-05f, 0.00014205336628947407f, 7.455704326275736e-05f, 0.00011894349154317752f, 6.679694342892617e-05f, 5.920238254475407e-05f, 4.140873352298513e-05f, 0.00011420780356274918f, 6.321394903352484e-05f, 0.0001032210566336289f, 5.1249102398287505e-05f, 0.00011224979971302673f, 0.00014809936692472547f, 4.599690510076471e-05f, 6.661049701506272e-05f, 7.128959987312555e-05f, 4.669450572691858e-05f, 9.466754272580147e-05f, 0.0001172034244518727f, 6.854287494206801e-05f, 0.00015783545677550137f, 0.00010646379814716056f, 6.341021071420982e-05f, 0.00010279767593601719f, 0.00010378981824032962f, 6.300929089775309e-05f, 9.22607650863938e-05f, 5.5206503020599484e-05f, 8.593553502578288e-05f, 4.881432687398046e-05f, 0.0001466291578253731f, 7.244945300044492e-05f, 0.00012235689791850746f, 5.036225411458872e-05f, 0.00013762387970928103f, 5.614174733636901e-05f, 9.057120769284666e-05f, 9.61120385909453e-05f, 7.060485950205475e-05f, 7.564391853520647e-05f, 9.990170656237751e-05f, 8.50473516038619e-05f, 9.931708336807787e-05f, 0.00011317960888845846f, 0.00017163934535346925f, 0.00011073915084125474f, 9.751205652719364e-05f, 0.0001045902754412964f, 6.085506174713373e-05f, 7.299838762264699e-05f, 7.656040543224663e-05f, 7.825368084013462e-05f, 5.452560435514897e-05f, 6.124578067101538e-05f, 0.00011323267972329631f, 0.00010325118637410924f, 6.98001604177989e-05f, 5.3310461225919425e-05f, 8.37857587612234e-05f, 0.00014377618208527565f, 0.00011452296166680753f, 0.00014751096023246646f, 0.00013920330093242228f, 6.098204539739527e-05f, 0.00011052643822040409f, 0.0001470115385018289f, 0.00013858030433766544f, 0.0001437971368432045f, 0.00016242542187683284f, 3.8952246541157365e-05f, 7.7349272032734e-05f, 0.00016817399591673166f, 9.654979658080265e-05f, 0.0001383602066198364f, 9.505975322099403e-05f, 0.0001642236893530935f, 0.0001292223751079291f, 0.00014670914970338345f, 1.5240399079630151e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #153 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_57_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007825935259461403f, 0.012992409989237785f, 0.007723917253315449f, 0.006867685820907354f, 0.005593663081526756f, 0.004755861591547728f, 0.009268234483897686f, 0.014328781515359879f, 0.00274422625079751f, 0.0074450294487178326f, 0.006256438326090574f, 0.01572675071656704f, 0.01047467440366745f, 0.012266453355550766f, 0.01115775853395462f, 0.006678607780486345f, 0.0036589461378753185f, 0.002882776316255331f, 0.005907048936933279f, 0.006428878288716078f, 0.003787273308262229f, 0.005986938718706369f, 0.00434546172618866f, 0.007184000685811043f, 0.007537662982940674f, 0.006998371332883835f, 0.010939104482531548f, 0.007372237741947174f, 0.005365185905247927f, 0.0026085947174578905f, 0.005080768372863531f, 0.006310209631919861f, 0.007830456830561161f, 0.00835137628018856f, 0.0029802797362208366f, 0.006409929599612951f, 0.008914180099964142f, 0.007498995400965214f, 0.006811207626014948f, 0.01064600981771946f, 0.007563465740531683f, 0.004484064411371946f, 0.007111837156116962f, 0.010051301680505276f, 0.011328790336847305f, 0.006688043940812349f, 0.0047980016097426414f, 0.015677474439144135f, 0.0039921533316373825f, 0.0052179316990077496f, 0.0020068292506039143f, 0.005364612210541964f, 0.00861355196684599f, 0.009019806981086731f, 0.005784997716546059f, 0.0024030604399740696f, 0.005274871829897165f, 0.0026816397439688444f, 0.010015636682510376f, 0.0056602307595312595f, 0.005809737369418144f, 0.010569253005087376f, 0.002480641705915332f, 0.007496165577322245f, 0.013227532617747784f, 0.007400856353342533f, 0.006197948008775711f, 0.007125506177544594f, 0.007573228795081377f, 0.0047293612733483315f, 0.007087354548275471f, 0.002098031109198928f, 0.007960649207234383f, 0.021744001656770706f, 0.003606559243053198f, 0.005531897768378258f, 0.00634026899933815f, 0.019291609525680542f, 0.005899797193706036f, 0.007093743421137333f, 0.006620932370424271f, 0.01037029642611742f, 0.011386409401893616f, 0.007677809800952673f, 0.005214863456785679f, 0.002583656460046768f, 0.005997709464281797f, 0.009244261309504509f, 0.003582686884328723f, 0.009414313361048698f, 0.010069487616419792f, 0.007160534616559744f, 0.013118013739585876f, 0.007463764399290085f, 0.005118140019476414f, 0.008226044476032257f, 0.004759808536618948f, 0.011616017669439316f, 0.005884626414626837f, 0.005879709962755442f, 0.006285961717367172f, 0.00556746544316411f, 0.007514387834817171f, 0.005144632421433926f, 0.015559078194200993f, 0.011177764274179935f, 0.005314768757671118f, 0.007479275111109018f, 0.017425836995244026f, 0.008912330493330956f, 0.008732100948691368f, 0.008092197589576244f, 0.009464792907238007f, 0.006221435032784939f, 0.006360511761158705f, 0.0020664813928306103f, 0.00897134467959404f, 0.00689599709585309f, 0.007059801369905472f, 0.003453208599239588f, 0.008009670302271843f, 0.006716371979564428f, 0.0025989520363509655f, 0.0018637945177033544f, 0.010248617269098759f, 0.008183421567082405f, 0.00373957771807909f, 0.00843227468430996f, 0.013767465949058533f, 0.0015930883819237351f, 0.004032874014228582f, 0.009366904385387897f, 0.0069063203409314156f, 0.004521354101598263f, 0.02137160487473011f, 0.0016452086856588721f, 0.011013912968337536f, 0.004418643657118082f, 0.0025593622121959925f, 0.004284279886633158f, 0.006434489041566849f, 0.009608142077922821f, 0.00649708416312933f, 0.005848165601491928f, 0.01209114957600832f, 0.005205809138715267f, 0.013049931265413761f, 0.0036327296402305365f, 0.010119356215000153f, 0.015925880521535873f, 0.003896708134561777f, 0.005907867103815079f, 0.011886600404977798f, 0.015455172397196293f, 0.01078518945723772f, 0.00247614411637187f, 0.00833821203559637f, 0.003005241509526968f, 0.012213998474180698f, 0.0016915085725486279f, 0.01380784809589386f, 0.005722889676690102f, 0.007791133131831884f, 0.0027171727269887924f, 0.008512292988598347f, 0.007394342217594385f, 0.00877574272453785f, 0.010051531717181206f, 0.0068348306231200695f, 0.008818498812615871f, 0.0011896161595359445f, 0.006243076175451279f, 0.006429832894355059f, 0.0058157965540885925f, 0.014856389723718166f, 0.007124131079763174f, 0.0026461470406502485f, 0.011006120592355728f, 0.009028071537613869f, 0.008102662861347198f, 0.004310280550271273f, 0.011590343900024891f, 0.005203640554100275f, 0.013667084276676178f, 0.005957416258752346f, 0.014691132120788097f, 0.0072812363505363464f, 0.007472996599972248f, 0.00972715113312006f, 0.0038375400472432375f, 0.0023733919952064753f, 0.01808423548936844f, 0.010926879942417145f, 0.007197093218564987f, 0.009160175919532776f, 0.0021193567663431168f, 0.01471023727208376f, 0.009450823999941349f, 0.013630850240588188f, 0.004990869667381048f, 0.006988254841417074f, 0.00954101700335741f, 0.004778325092047453f, 0.006243910640478134f, 0.010098611004650593f, 0.008770275861024857f, 0.0115268025547266f, 0.00729823624715209f, 0.00796010997146368f, 0.018977295607328415f, 0.002994326176121831f, 0.011327886022627354f, 0.0023168534971773624f, 0.008640500716865063f, 0.004872973542660475f, 0.004086566157639027f, 0.006726943887770176f, 0.014513710513710976f, 0.008909325115382671f, 0.005182475317269564f, 0.010530720464885235f, 0.006033307872712612f, 0.010406640358269215f, 0.006505084224045277f, 0.012738293036818504f, 0.00919768400490284f, 0.00778215192258358f, 0.004762162454426289f, 0.014603656716644764f, 0.007682815659791231f, 0.006794599816203117f, 0.009539210237562656f, 0.018858643248677254f, 0.010304294526576996f, 0.13515953719615936f, 0.010605080053210258f, 0.00579939316958189f, 0.004222302231937647f, 0.01464400440454483f, 0.015375562943518162f, 0.012748555280268192f, 0.006996435578912497f, 0.004738663323223591f, 0.008592825382947922f, 0.003087725257501006f, 0.008880279026925564f, 0.007144061848521233f, 0.0024355717469006777f, 0.008782405406236649f, 0.006897639948874712f, 0.00804296787828207f, 0.006034154910594225f, 0.002787506440654397f, 0.004067649133503437f, 0.005642351694405079f, 0.004585638176649809f, 0.007098800968378782f, 0.01569535955786705f, 0.007901892066001892f, 0.0027663849759846926f, 0.002913397504016757f, 0.0114605026319623f, 0.009411702863872051f, 0.006658544298261404f, 0.004851949866861105f, 0.012679842300713062f, 0.006259653717279434f, 0.007954702712595463f, 0.004530700389295816f, 0.00646366598084569f, 0.014980321750044823f, 0.01065476331859827f, 0.008866464719176292f, 0.007424965966492891f, 0.005767343565821648f, 0.011410432867705822f, 0.004690644796937704f, 0.00466669537127018f, 0.004622758831828833f, 0.006119291763752699f, 0.0056945220567286015f, 0.013379807583987713f, 0.004961048718541861f, 0.014590318314731121f, 0.006939164362847805f, 0.007563568186014891f, 0.016403568908572197f, 0.0033094044774770737f, 0.010835697874426842f, 0.005085371434688568f, 0.013734562322497368f, 0.009743313305079937f, 0.006586045958101749f, 0.005001510493457317f, 0.008805522695183754f, 0.008207221515476704f, 0.004625616129487753f, 0.005680131260305643f, 0.00818925816565752f, 0.006370764225721359f, 0.020307060331106186f, 0.0030750150326639414f, 0.01613924466073513f, 0.005936744157224894f, 0.004420241340994835f, 0.011077254079282284f, 0.007809294853359461f, 0.011408556252717972f, 0.0071028973907232285f, 0.010390518233180046f, 0.013968037441372871f, 0.007131598424166441f, 0.0024071591906249523f, 0.014627144671976566f, 0.00963288638740778f, 0.002700872253626585f, 0.002193572698161006f, 0.012879032641649246f, 0.01848437450826168f, 0.001999045256525278f, 0.009951972402632236f, 0.0038335409481078386f, 0.0029733125120401382f, 0.003692319616675377f, 0.0019008825765922666f, 0.011782864108681679f, 0.02383114956319332f, 0.005553562194108963f, 0.002241404727101326f, 0.007035982795059681f, 0.0035544310230761766f, 0.013194410130381584f, 0.00582598801702261f, 0.007281226105988026f, 0.0021771849133074284f, 0.013541053980588913f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #154 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_57_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001841396588133648f, 0.00030570378294214606f, 0.00018173923308495432f, 0.0001615926157683134f, 0.00013161559763830155f, 0.00011190262739546597f, 0.000218076107557863f, 0.0003371477941982448f, 6.457002746174112e-05f, 0.00017517716332804412f, 0.0001472103176638484f, 0.00037004120531491935f, 0.0002464629360474646f, 0.00028862242470495403f, 0.00026253549731336534f, 0.00015714371693320572f, 8.609284850535914e-05f, 6.783003482269123e-05f, 0.0001389893877785653f, 0.00015126772632356733f, 8.911231270758435e-05f, 0.0001408691459801048f, 0.00010224615834886208f, 0.00016903530922718346f, 0.00017735677829477936f, 0.00016466756642330438f, 0.0002573906967882067f, 0.00017346441745758057f, 0.00012623966904357076f, 6.137869786471128e-05f, 0.00011954749061260372f, 0.00014847551938146353f, 0.0001842460478655994f, 0.0001965029805433005f, 7.012423156993464e-05f, 0.0001508218701928854f, 0.0002097454125760123f, 0.00017644694889895618f, 0.0001602637057658285f, 0.00025049434043467045f, 0.00017796389875002205f, 0.0001055074026226066f, 0.00016733734810259193f, 0.00023650121875107288f, 0.0002665597712621093f, 0.00015736575005576015f, 0.00011289415851933882f, 0.000368881766917184f, 9.393302025273442e-05f, 0.00012277487257961184f, 4.7219513362506405e-05f, 0.00012622616486623883f, 0.00020267181389499456f, 0.00021223076328169554f, 0.00013611759641207755f, 5.654259803122841e-05f, 0.00012411463831085712f, 6.309741002041847e-05f, 0.00023566203890368342f, 0.00013318190758582205f, 0.00013669970212504268f, 0.00024868830223567784f, 5.8368041209178045e-05f, 0.0001763803738867864f, 0.00031123607186600566f, 0.00017413779278285801f, 0.0001458340702811256f, 0.0001676589745329693f, 0.00017819361528381705f, 0.00011127909237984568f, 0.00016676128143444657f, 4.936544064548798e-05f, 0.00018730940064415336f, 0.0005116235697641969f, 8.486022124998271e-05f, 0.00013016229786444455f, 0.00014918280066922307f, 0.00045392022002488375f, 0.00013881876657251269f, 0.00016691161727067083f, 0.00015578664897475392f, 0.00024400698021054268f, 0.0002679155149962753f, 0.00018065435870084912f, 0.00012270266597624868f, 6.079191734897904e-05f, 0.00014112258213572204f, 0.0002175120316678658f, 8.429851732216775e-05f, 0.00022151325538288802f, 0.000236929117818363f, 0.00016848316590767354f, 0.00030865916050970554f, 0.00017561798449605703f, 0.00012042682647006586f, 0.00019355399126652628f, 0.00011199549771845341f, 0.0002733180590439588f, 0.00013846179354004562f, 0.00013834612036589533f, 0.00014790498244110495f, 0.00013099919306114316f, 0.000176809131517075f, 0.0001210501795867458f, 0.0003660959773696959f, 0.00026300622266717255f, 0.00012505338236223906f, 0.00017598294652998447f, 0.00041001971112564206f, 0.0002097019023494795f, 0.00020546119776554406f, 0.0001904046512208879f, 0.00022270101180765778f, 0.0001463867083657533f, 0.00014965909940656275f, 4.862309288000688e-05f, 0.0002110904606524855f, 0.00016225875879172236f, 0.0001661129790591076f, 8.125197200570256e-05f, 0.0001884628291008994f, 0.00015803228598088026f, 6.11518116784282e-05f, 4.3853990064235404e-05f, 0.00024114393454510719f, 0.0001925511023728177f, 8.79900690051727e-05f, 0.0001984064729185775f, 0.0003239403886254877f, 3.748443486983888e-05f, 9.489115473115817e-05f, 0.0002203977492172271f, 0.00016250165936071426f, 0.00010638480307534337f, 0.0005028612795285881f, 3.871079388773069e-05f, 0.00025915089645422995f, 0.00010396808647783473f, 6.0220289014978334e-05f, 0.00010080658830702305f, 0.00015139974129851907f, 0.00022607394203078002f, 0.00015287256974261254f, 0.00013760389992967248f, 0.000284497655229643f, 0.0001224896259373054f, 0.00030705719836987555f, 8.547599281882867e-05f, 0.00023810249695088714f, 0.00037472660187631845f, 9.168725227937102e-05f, 0.00013900863996241242f, 0.0002796847256831825f, 0.000363651110092178f, 0.00025376916164532304f, 5.8262216043658555e-05f, 0.0001961932284757495f, 7.071156869642437e-05f, 0.0002873882185667753f, 3.980020119342953e-05f, 0.00032489054137840867f, 0.00013465623487718403f, 0.00018332077888771892f, 6.393347575794905e-05f, 0.0002002892579184845f, 0.00017398453201167285f, 0.000206488068215549f, 0.00023650663206353784f, 0.00016081954527180642f, 0.0002074941003229469f, 2.799096910166554e-05f, 0.0001468959089834243f, 0.00015129019448067993f, 0.00013684228179045022f, 0.00034956212039105594f, 0.0001676266110735014f, 6.22622828814201e-05f, 0.00025896754232235253f, 0.0002124252205248922f, 0.00019065089873038232f, 0.00010141836537513882f, 0.0002727139799389988f, 0.00012243860692251474f, 0.00032157846726477146f, 0.00014017449575476348f, 0.00034567370312288404f, 0.00017132320499513298f, 0.0001758352154865861f, 0.00022887415252625942f, 9.029506327351555e-05f, 5.5844517191872e-05f, 0.0004255114181432873f, 0.0002571030636318028f, 0.000169343373272568f, 0.00021553355327341706f, 4.9867219786392525e-05f, 0.00034612324088811874f, 0.00022237232769839466f, 0.0003207258996553719f, 0.00011743223149096593f, 0.00016442952619399875f, 0.00022449452080763876f, 0.00011243118206039071f, 0.0001469155540689826f, 0.00023761438205838203f, 0.00020635942928493023f, 0.00027121888706460595f, 0.00017172320804093033f, 0.00018729671137407422f, 0.0004465246165636927f, 7.04547346686013e-05f, 0.0002665384963620454f, 5.451419929158874e-05f, 0.00020330589904915541f, 0.00011465819989098236f, 9.615450107958168e-05f, 0.00015828103641979396f, 0.0003414990787860006f, 0.00020963118004146963f, 0.00012194059672765434f, 0.00024778165970928967f, 0.00014196019037626684f, 0.0002448621380608529f, 0.0001530608133180067f, 0.0002997245464939624f, 0.00021641609782818705f, 0.00018310945597477257f, 0.00011205088230781257f, 0.00034361545112915337f, 0.00018077214190270752f, 0.00015987294318620116f, 0.0002244520146632567f, 0.00044373280252330005f, 0.00024245399981737137f, 0.003180224448442459f, 0.00024953129468485713f, 0.000136456306790933f, 9.934828995028511e-05f, 0.000344564818078652f, 0.00036177795846015215f, 0.0002999660209752619f, 0.0001646220189286396f, 0.00011149796046083793f, 0.0002021841355599463f, 7.265235763043165e-05f, 0.00020894774934276938f, 0.000168095575645566f, 5.730757038691081e-05f, 0.0002066448359983042f, 0.0001622974086785689f, 0.00018924630421679467f, 0.00014198011194821447f, 6.558838504133746e-05f, 9.570939437253401e-05f, 0.00013276121171656996f, 0.0001078973727999255f, 0.0001670306082814932f, 0.0003693025792017579f, 0.00018592688138596714f, 6.509141530841589e-05f, 6.855052924947813e-05f, 0.00026965889264829457f, 0.00022145183174870908f, 0.00015667163825128227f, 0.00011416352936066687f, 0.00029834924498572946f, 0.00014728597307112068f, 0.0001871694839792326f, 0.00010660471889423206f, 0.00015208625700324774f, 0.0003524781786836684f, 0.00025070030824281275f, 0.00020862270321231335f, 0.00017470508464612067f, 0.00013570219743996859f, 0.000268480769591406f, 0.00011036811338271946f, 0.00010980459774145856f, 0.00010877080057980493f, 0.00014398334315046668f, 0.00013398875307757407f, 0.0003148190153297037f, 0.00011673055996652693f, 0.0003433016245253384f, 0.0001632744533708319f, 0.00017796631436794996f, 0.00038596632657572627f, 7.786833884892985e-05f, 0.00025495761656202376f, 0.00011965580051764846f, 0.00032316616852767766f, 0.00022925443772692233f, 0.00015496578998863697f, 0.0001176826044684276f, 0.0002071887720376253f, 0.00019311110372655094f, 0.00010883803042815998f, 0.0001336501445621252f, 0.0001926884287968278f, 0.0001499003410572186f, 0.000477813184261322f, 7.235329394461587e-05f, 0.0003797469544224441f, 0.00013968809798825532f, 0.00010400568135082722f, 0.00026064127450808883f, 0.00018374812498223037f, 0.0002684366190806031f, 0.0001671270001679659f, 0.0002444827987346798f, 0.00032865972025319934f, 0.00016780232544988394f, 5.663904084940441e-05f, 0.0003441681037656963f, 0.00022665614960715175f, 6.35499382042326e-05f, 5.16134750796482e-05f, 0.00030303606763482094f, 0.0004349264781922102f, 4.703635931946337e-05f, 0.00023416406475007534f, 9.020096331369132e-05f, 6.996029696892947e-05f, 8.68781135068275e-05f, 4.472665023058653e-05f, 0.0002772438747342676f, 0.0005607329658232629f, 0.00013067205145489424f, 5.273893475532532e-05f, 0.0001655525411479175f, 8.363366941921413e-05f, 0.00031045672949403524f, 0.00013708206824958324f, 0.00017132297216448933f, 5.122788206790574e-05f, 0.0003186130488757044f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #155 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_58_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003722590859979391f, 0.005166194401681423f, 0.006411547306925058f, 0.006104451138526201f, 0.008650653064250946f, 0.009354004636406898f, 0.007212489377707243f, 0.004446621518582106f, 0.011430935002863407f, 0.004489575512707233f, 0.008673436939716339f, 0.01507863774895668f, 0.003991708625108004f, 0.012610598467290401f, 0.009684494696557522f, 0.0032138542737811804f, 0.0063924542628228664f, 0.006518613547086716f, 0.006334715057164431f, 0.005306134466081858f, 0.0071409824304282665f, 0.00658711651340127f, 0.011111904866993427f, 0.005219192244112492f, 0.009618445299565792f, 0.005887887440621853f, 0.004762082826346159f, 0.01019923947751522f, 0.006264984607696533f, 0.004968222696334124f, 0.009383726865053177f, 0.016035165637731552f, 0.004920480772852898f, 0.007519877515733242f, 0.0042666057124733925f, 0.007062897086143494f, 0.00655359635129571f, 0.011172286234796047f, 0.0032313591800630093f, 0.010231728665530682f, 0.008439477533102036f, 0.019687503576278687f, 0.004405539948493242f, 0.004756871145218611f, 0.005347731988877058f, 0.011479390785098076f, 0.005219428800046444f, 0.006460215430706739f, 0.005866401828825474f, 0.00501851923763752f, 0.009528110735118389f, 0.008587398566305637f, 0.007519822102040052f, 0.008015179075300694f, 0.008610982447862625f, 0.006810722406953573f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #156 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_58_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.759037154959515e-05f, 0.00012155751755926758f, 0.0001508599380031228f, 0.00014363414084073156f, 0.00020354478328954428f, 0.00022009422536939383f, 0.00016970562865026295f, 0.0001046263932948932f, 0.0002689631946850568f, 0.00010563707473920658f, 0.00020408087584655732f, 0.00035479149664752185f, 9.392255742568523e-05f, 0.00029671998345293105f, 0.00022787046327721328f, 7.562010432593524e-05f, 0.00015041069127619267f, 0.00015337915101554245f, 0.00014905212447047234f, 0.00012485022307373583f, 0.00016802312165964395f, 0.00015499097935389727f, 0.00026145658921450377f, 0.00012280452938284725f, 0.00022631636238656938f, 0.0001385385257890448f, 0.00011204901238670573f, 0.00023998210963327438f, 0.0001474114105803892f, 0.00011689936218317598f, 0.0002207935758633539f, 0.00037729801260866225f, 0.00011577601981116459f, 0.00017693829431664199f, 0.00010039072367362678f, 0.00016618581139482558f, 0.0001542022655485198f, 0.0002628773218020797f, 7.603198173455894e-05f, 0.00024074656539596617f, 0.00019857594452332705f, 0.00046323539572767913f, 0.00010365976777393371f, 0.00011192638339707628f, 0.0001258289848919958f, 0.0002701033081393689f, 0.00012281008821446449f, 0.00015200507186818868f, 0.00013803299225401133f, 0.00011808281124103814f, 0.0002241908514406532f, 0.00020205644250381738f, 0.00017693699919618666f, 0.0001885924575617537f, 0.0002026113506872207f, 0.00016025229706428945f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #157 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_60_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005764568340964615f, 0.0005423232796601951f, 0.0010303480084985495f, 0.0006638749036937952f, 0.0008720579207874835f, 0.000658545468468219f, 0.0016895580338314176f, 0.0007446880335919559f, 0.0007089873543009162f, 0.0007022980134934187f, 0.00027071169461123645f, 0.0012841671705245972f, 0.0010621445253491402f, 0.0006077828584238887f, 0.0005683014751411974f, 0.000296157319098711f, 0.0008524819277226925f, 0.0006806721212342381f, 0.0013563602697104216f, 0.0005509974434971809f, 0.0004096156044397503f, 0.0009711158345453441f, 0.000755250221118331f, 0.0009097674628719687f, 0.00042412805487401783f, 0.0006566779920831323f, 0.0005046341102570295f, 0.0006350338808260858f, 0.0005467487499117851f, 0.0006819071713835001f, 0.0003202423104085028f, 0.0009004311286844313f, 0.0005017536459490657f, 0.000763557618483901f, 0.0006429022760130465f, 0.00040411174995824695f, 0.0008481190307065845f, 0.0008370816358365119f, 0.00031104922527447343f, 0.0003814268275164068f, 0.0005169797805137932f, 0.00033719342900440097f, 0.0010868702083826065f, 0.0006684440304525197f, 0.0007356541464105248f, 0.0009286842541769147f, 0.0007559863734059036f, 0.001342210453003645f, 0.0007863965583965182f, 0.0008385462570004165f, 0.0004087817796971649f, 0.0007050101994536817f, 0.0008302631904371083f, 0.0010051779681816697f, 0.0006775742513127625f, 0.0005824225954711437f, 0.0008389101712964475f, 0.0006843233131803572f, 0.0005537837278097868f, 0.000604048022069037f, 0.00044210487976670265f, 0.0006202583899721503f, 0.0007435393636114895f, 0.00026061528478749096f, 0.0006201800424605608f, 0.000370099296560511f, 0.0005853591137565672f, 0.00036678012111224234f, 0.0007466966053470969f, 0.000780573405791074f, 0.00036893165088258684f, 0.00046701382962055504f, 0.0008881894173100591f, 0.0008671369287185371f, 0.0006067116628400981f, 0.00047535993508063257f, 0.000768498401157558f, 0.0004306133487261832f, 0.0003472489770501852f, 0.0006805725861340761f, 0.000990980421192944f, 0.00044568354496732354f, 0.0007649481412954628f, 0.0005346631514839828f, 0.0003872243396472186f, 0.000514353159815073f, 0.0005988791235722601f, 0.0004755106056109071f, 0.0005394488107413054f, 0.0008225610363297164f, 0.0004680970450863242f, 0.0008722737547941506f, 0.0004060437495354563f, 0.0008653984987176955f, 0.0006972866831347346f, 0.0005570548819378018f, 0.0007153099286369979f, 0.00048331075231544673f, 0.000760250783059746f, 0.0005694050923921168f, 0.00048263478674925864f, 0.000651601527351886f, 0.0008008485310710967f, 0.0007181179244071245f, 0.0007292472873814404f, 0.0009522295440547168f, 0.0004137176729273051f, 0.0009036797564476728f, 0.0007908677798695862f, 0.0010248656617477536f, 0.000407058687414974f, 0.0006585382507182658f, 0.0004817218577954918f, 0.0006604775553569198f, 0.0011007346911355853f, 0.0007574806804768741f, 0.0008325328817591071f, 0.0005614469409920275f, 0.0006495650741271675f, 0.0007058630581013858f, 0.0004777382127940655f, 0.0004165793361607939f, 0.0006813336513005197f, 0.0004925586399622262f, 0.0006582345813512802f, 0.00045083026634529233f, 0.000844196998514235f, 5.517206227523275e-05f, 0.0005299861659295857f, 0.000364342937245965f, 0.0004355336131993681f, 0.0006692348979413509f, 0.0008974457741715014f, 0.0004351605020929128f, 0.000473147229058668f, 0.00043498221202753484f, 0.00038845313247293234f, 0.0006424154271371663f, 0.0006835070089437068f, 0.0010234417859464884f, 0.0003456384874880314f, 0.0008141638827510178f, 0.0007155180792324245f, 0.0011677122674882412f, 0.0006744283600710332f, 0.0005805548280477524f, 0.0010610900353640318f, 0.0006003576563671231f, 0.0008319597109220922f, 0.0003746177244465798f, 0.0005131170037202537f, 0.0004277118423487991f, 0.0006978872115723789f, 0.00039449799805879593f, 0.0006699693622067571f, 0.0014492843765765429f, 0.0007562973187305033f, 0.0005075189401395619f, 0.00043793770601041615f, 0.0010521382791921496f, 0.0007864244980737567f, 0.0006818301044404507f, 0.0004850155964959413f, 0.0005548803601413965f, 0.0007596865179948509f, 0.0009002372389659286f, 0.0007427912205457687f, 0.0006484441109932959f, 0.0003483426698949188f, 0.000744495599064976f, 0.0006594801088795066f, 0.0006138590397313237f, 0.001139461062848568f, 0.000772463739849627f, 0.0008326562237925828f, 0.0009569113608449697f, 0.0008842534152790904f, 0.000208821875276044f, 0.0004061127547174692f, 0.00038770950050093234f, 0.0005058685783296824f, 0.0006710236775688827f, 0.0013349608052521944f, 0.0007652717176824808f, 0.00042882919660769403f, 0.0004637640668079257f, 0.0005674092099070549f, 0.0004279313434381038f, 0.001231739530339837f, 0.0010362102184444666f, 0.0007660218398086727f, 0.000511208432726562f, 0.0005479246028698981f, 0.00040808008634485304f, 0.0008274595020338893f, 0.0007820419850759208f, 0.00039233179995790124f, 0.0008025761344470084f, 0.0009308959124609828f, 0.00033754383912310004f, 0.0009068554500117898f, 0.0007096815388649702f, 0.0006146026425994933f, 0.0006218778435140848f, 0.0009329730528406799f, 0.0006311951437965035f, 0.00036736144102178514f, 0.000996225979179144f, 0.0007606183062307537f, 0.0008977149846032262f, 0.00038453435990959406f, 0.00129055161960423f, 0.0008775726892054081f, 0.0005177489947527647f, 0.0006398863042704761f, 0.0008087416645139456f, 0.000937949400395155f, 0.000740537594538182f, 0.0006960763712413609f, 0.00028603230020962656f, 0.000514222017955035f, 0.0011427632998675108f, 0.0006409519701264799f, 0.0005910842446610332f, 0.0006062710890546441f, 0.00029881109367124736f, 0.0005719229229725897f, 0.0005010950844734907f, 0.0003076935827266425f, 0.0008769555133767426f, 0.0006765472353436053f, 0.000478168367408216f, 0.0006358715472742915f, 0.0008697412558831275f, 0.0006533824489451945f, 0.0002652071416378021f, 0.0009104168857447803f, 0.0008829113794490695f, 0.00047626724699512124f, 0.0005525168380700052f, 0.00032021765946410596f, 0.000763817981351167f, 0.000784016796387732f, 0.0007419526809826493f, 0.0006414932431653142f, 0.00043420467409305274f, 0.0007259717094711959f, 0.0005737268947996199f, 0.0005960622802376747f, 0.000967762025538832f, 0.000600817147642374f, 0.00023029099975246936f, 0.0005833784234710038f, 0.0008455839706584811f, 0.0004253120278008282f, 0.000484094227431342f, 0.00033456325763836503f, 0.0006704256520606577f, 0.0008369739516638219f, 0.000597357633523643f, 0.0008316842140629888f, 0.000735586741939187f, 0.0003878417192026973f, 0.0008324418449774384f, 0.00042118068085983396f, 0.0007976652123034f, 0.0004791353130713105f, 0.0005599390133284032f, 0.0006864155875518918f, 0.00039913924410939217f, 0.0013572657480835915f, 0.0008250927785411477f, 0.00033405033173039556f, 0.0005276220035739243f, 0.0006405177409760654f, 0.0010161662939935923f, 0.0006508614169433713f, 0.0020236074924468994f, 0.0009090383537113667f, 0.000747669255360961f, 0.0004929962451569736f, 0.000620524282567203f, 0.0008451368194073439f, 0.0007090542349033058f, 0.0003957573208026588f, 0.0009522633627057076f, 0.0003916363057214767f, 0.0009494376135990024f, 0.0011515410151332617f, 0.0005825508269481361f, 0.0011906453873962164f, 0.0006142642232589424f, 0.0007588415173813701f, 0.0006500930176116526f, 0.0006588094402104616f, 0.0003280515084043145f, 0.0008707355591468513f, 0.0008772147702984512f, 0.0008445260464213789f, 0.0005458776140585542f, 0.0006903329049237072f, 0.00033653731225058436f, 0.00042017336818389595f, 0.0004965896951034665f, 0.000812902522739023f, 0.0005048617022112012f, 0.00038727547507733107f, 0.0006280053057707846f, 0.0005999045097269118f, 0.00024733893224038184f, 0.001035853405483067f, 0.000520066125318408f, 0.0005790544091723859f, 0.00047165071009658277f, 0.0004682210856117308f, 0.0008078339160420001f, 0.0006113086128607392f, 0.0006543149356730282f, 0.000570831703953445f, 0.0002958358090836555f, 0.0006206101388670504f, 0.0008666564826853573f, 0.0005665792850777507f, 0.0007955426699481905f, 0.0005045978468842804f, 0.0009126923396252096f, 0.0002799311187118292f, 0.0011028747539967299f, 0.0005283884820528328f, 0.00025026031653396785f, 0.0005786542897112668f, 0.00046257529174908996f, 0.0015140583273023367f, 0.00031088737887330353f, 0.0005962433060631156f, 0.0007398063316941261f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #158 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_60_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.51606237119995e-05f, 8.011803583940491e-05f, 0.0001522144884802401f, 9.807499736780301e-05f, 0.00012883011368103325f, 9.728767327032983e-05f, 0.0002496003289707005f, 0.00011001361417584121f, 0.00010473951260792091f, 0.00010375128476880491f, 3.999254840891808e-05f, 0.00018971148529089987f, 0.00015691181761212647f, 8.978845289675519e-05f, 8.395582699449733e-05f, 4.375165735837072e-05f, 0.00012593812425620854f, 0.00010055646998807788f, 0.00020037664216943085f, 8.13994774944149e-05f, 6.051297896192409e-05f, 0.00014346404350362718f, 0.00011157397966599092f, 0.00013440097973216325f, 6.26569235464558e-05f, 9.701179078547284e-05f, 7.455017475876957e-05f, 9.381427662447095e-05f, 8.077181701082736e-05f, 0.00010073892190121114f, 4.730976070277393e-05f, 0.00013302172010298818f, 7.412464037770405e-05f, 0.00011280123726464808f, 9.49766836129129e-05f, 5.969989069853909e-05f, 0.00012529359082691371f, 0.00012366301962174475f, 4.59516559203621e-05f, 5.634862100123428e-05f, 7.637400995008647e-05f, 4.9813970690593123e-05f, 0.0001605645811650902f, 9.874999523162842e-05f, 0.00010867902892641723f, 0.00013719558774027973f, 0.0001116827261284925f, 0.00019828627409879118f, 0.00011617525888141245f, 0.00012387939204927534f, 6.0389796999515966e-05f, 0.00010415195720270276f, 0.00012265572149772197f, 0.0001484960812376812f, 0.00010009881953010336f, 8.604195318184793e-05f, 0.00012393316137604415f, 0.00010109586582984775f, 8.18111002445221e-05f, 8.923670247895643e-05f, 6.531265535159037e-05f, 9.163148206425831e-05f, 0.00010984391701640561f, 3.850099164992571e-05f, 9.161990601569414e-05f, 5.467519076773897e-05f, 8.647576760267839e-05f, 5.418484579422511e-05f, 0.00011031034227926284f, 0.0001153150005848147f, 5.450269236462191e-05f, 6.899248546687886e-05f, 0.0001312132371822372f, 0.0001281031291000545f, 8.963020809460431e-05f, 7.022546196822077e-05f, 0.00011353114678058773f, 6.361499981721863e-05f, 5.1299488404765725e-05f, 0.00010054176527773961f, 0.000146398670040071f, 6.584134098375216e-05f, 0.00011300665937596932f, 7.898639887571335e-05f, 5.7205092161893845e-05f, 7.598597585456446e-05f, 8.84730980033055e-05f, 7.024772639852017e-05f, 7.969338912516832e-05f, 0.00012151787814218551f, 6.915251287864521e-05f, 0.0001288619969272986f, 5.9985304687870666e-05f, 0.00012784630234818906f, 0.00010301095608156174f, 8.229435479734093e-05f, 0.00010567354911472648f, 7.140004890970886e-05f, 0.00011231271491851658f, 8.411886665271595e-05f, 7.130018639145419e-05f, 9.626183600630611e-05f, 0.00011831026495201513f, 0.00010608838056214154f, 0.00010773253598017618f, 0.00014067396114114672f, 6.111898255767301e-05f, 0.00013350164226721972f, 0.00011683579941745847f, 0.0001514045725343749f, 6.013524398440495e-05f, 9.728660370456055e-05f, 7.116531924111769e-05f, 9.757310181157663e-05f, 0.0001626127923373133f, 0.00011190348595846444f, 0.000122991026728414f, 8.294319559354335e-05f, 9.596098971087486e-05f, 0.00010427795496070758f, 7.057681068545207e-05f, 6.154173752292991e-05f, 0.00010065420065075159f, 7.276624819496647e-05f, 9.724174742586911e-05f, 6.660167127847672e-05f, 0.00012471419177018106f, 8.150631401804276e-06f, 7.829545938875526e-05f, 5.382479866966605e-05f, 6.434187525883317e-05f, 9.886683255899698e-05f, 0.00013258068065624684f, 6.428675987990573e-05f, 6.989858229644597e-05f, 6.426042091334239e-05f, 5.7386623666388914e-05f, 9.490476077189669e-05f, 0.00010097526683239266f, 0.00015119422459974885f, 5.1061568228760734e-05f, 0.00012027735647279769f, 0.00010570430458756164f, 0.00017250746896024793f, 9.963406773749739e-05f, 8.576602704124525e-05f, 0.0001567560393596068f, 8.869152225088328e-05f, 0.00012290636368561536f, 5.534270530915819e-05f, 7.580335659440607e-05f, 6.318635860225186e-05f, 0.00010309967183275148f, 5.827963832416572e-05f, 9.897533891489729e-05f, 0.0002141044387826696f, 0.00011172866652486846f, 7.497634942410514e-05f, 6.46970365778543e-05f, 0.00015543359040748328f, 0.00011617938434937969f, 0.00010072754230350256f, 7.165190618252382e-05f, 8.19731067167595e-05f, 0.00011222935427213088f, 0.00013299306738190353f, 0.00010973339522024617f, 9.579538891557604e-05f, 5.146105831954628e-05f, 0.0001099851870094426f, 9.742574911797419e-05f, 9.068609506357461e-05f, 0.00016833387780934572f, 0.00011411694868002087f, 0.00012300926027819514f, 0.000141365613671951f, 0.00013063177175354213f, 3.084949275944382e-05f, 5.9995501942466944e-05f, 5.7276767620351166e-05f, 7.473253936041147e-05f, 9.913109533954412e-05f, 0.00019721528224181384f, 0.0001130544624174945f, 6.335142825264484e-05f, 6.85123959556222e-05f, 8.382400847040117e-05f, 6.321878754533827e-05f, 0.00018196628661826253f, 0.0001530805166112259f, 0.00011316528252791613f, 7.552140596089885e-05f, 8.094552322290838e-05f, 6.0286136431386694e-05f, 0.00012224153033457696f, 0.00011553195508895442f, 5.7959623518399894e-05f, 0.00011856549099320546f, 0.00013752230734098703f, 4.986573549103923e-05f, 0.00013397079601418227f, 0.00010484205995453522f, 9.079594747163355e-05f, 9.187072282657027e-05f, 0.00013782917812932283f, 9.324718121206388e-05f, 5.427072392194532e-05f, 0.00014717360318172723f, 0.00011236700811423361f, 0.00013262045104056597f, 5.680770118487999e-05f, 0.00019065466767642647f, 0.0001296448172070086f, 7.648764585610479e-05f, 9.453113307245076e-05f, 0.00011947633174713701f, 0.00013856434088665992f, 0.00010940046195173636f, 0.0001028321566991508f, 4.2255876905983314e-05f, 7.59666072553955e-05f, 0.00016882173076737672f, 9.468856296734884e-05f, 8.732154674362391e-05f, 8.956511737778783e-05f, 4.414370414451696e-05f, 8.449082815786824e-05f, 7.40273462724872e-05f, 4.545592310023494e-05f, 0.00012955363490618765f, 9.994709398597479e-05f, 7.064035889925435e-05f, 9.393802611157298e-05f, 0.0001284878671867773f, 9.652493463363498e-05f, 3.917935464414768e-05f, 0.00013449692050926387f, 0.00013043350190855563f, 7.035950693534687e-05f, 8.162394078681245e-05f, 4.730611908598803e-05f, 0.00011283969797659665f, 0.00011582369188545272f, 0.00010960951476590708f, 9.476852574152872e-05f, 6.414554809452966e-05f, 0.00010724862659117207f, 8.475733193336055e-05f, 8.805695688351989e-05f, 0.00014296859444584697f, 8.8759399659466e-05f, 3.402115180506371e-05f, 8.618315769126639e-05f, 0.00012491908273659647f, 6.283183029154316e-05f, 7.151579484343529e-05f, 4.9425412726122886e-05f, 9.904274338623509e-05f, 0.00012364711437840015f, 8.824832184473053e-05f, 0.00012286566197872162f, 0.00010866906814044341f, 5.729629992856644e-05f, 0.000122977580758743f, 6.222150113899261e-05f, 0.00011783999070758f, 7.078320777509362e-05f, 8.27204275992699e-05f, 0.00010140495578525588f, 5.8965295465895906e-05f, 0.00020051041792612523f, 0.00012189189874334261f, 4.934963726554997e-05f, 7.794619887135923e-05f, 9.46244181250222e-05f, 0.00015011940558906645f, 9.615250019123778e-05f, 0.0002989498316310346f, 0.00013429326645564288f, 0.00011045403516618535f, 7.283089507836848e-05f, 9.167075768345967e-05f, 0.0001248530315933749f, 0.00010474939335836098f, 5.846568092238158e-05f, 0.00014067895244807005f, 5.785687972093001e-05f, 0.0001402615016559139f, 0.00017011846648529172f, 8.606089977547526e-05f, 0.00017589540220797062f, 9.07459543668665e-05f, 0.00011210452066734433f, 9.603898070054129e-05f, 9.732667240314186e-05f, 4.8463421990163624e-05f, 0.00012863475421909243f, 0.00012959193554706872f, 0.0001247627951670438f, 8.064311987254769e-05f, 0.00010198366362601519f, 4.971704038325697e-05f, 6.207269325386733e-05f, 7.336176349781454e-05f, 0.00012009101919829845f, 7.458379695890471e-05f, 5.7212648243876174e-05f, 9.277593926526606e-05f, 8.862457616487518e-05f, 3.653966268757358e-05f, 0.00015302780957426876f, 7.682996510993689e-05f, 8.554436499252915e-05f, 6.967749504838139e-05f, 6.917083373991773e-05f, 0.00011934222857235f, 9.030931687448174e-05f, 9.666269033914432e-05f, 8.432962204096839e-05f, 4.370415990706533e-05f, 9.16834469535388e-05f, 0.00012803214485757053f, 8.370140130864456e-05f, 0.00011752642603823915f, 7.454481237800792e-05f, 0.00013483308430295438f, 4.135454219067469e-05f, 0.0001629289472475648f, 7.805943459970877e-05f, 3.6971243389416486e-05f, 8.548525511287153e-05f, 6.833677616668865e-05f, 0.00022367355995811522f, 4.592774712364189e-05f, 8.808370330370963e-05f, 0.00010929243580903858f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #159 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_61_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003986581228673458f, 0.004265355411916971f, 0.00405023992061615f, 0.003894002176821232f, 0.004770467523485422f, 0.006517968140542507f, 0.0028859549202024937f, 0.007582823280245066f, 0.008036617189645767f, 0.006870428565889597f, 0.007251964416354895f, 0.006006656214594841f, 0.002795731881633401f, 0.007456622552126646f, 0.007226862013339996f, 0.009156133979558945f, 0.011699317954480648f, 0.005922253243625164f, 0.011935006827116013f, 0.003494794713333249f, 0.009579489938914776f, 0.00599547429010272f, 0.008594626560807228f, 0.012308595702052116f, 0.0033234863076359034f, 0.007458389736711979f, 0.005299712531268597f, 0.006591538432985544f, 0.0027909784112125635f, 0.005901510361582041f, 0.01126986462622881f, 0.005774894263595343f, 0.006371113937348127f, 0.0049024298787117004f, 0.007083145435899496f, 0.007931266911327839f, 0.003854272421449423f, 0.008520376868546009f, 0.008391209878027439f, 0.0076475078240036964f, 0.008486940525472164f, 0.007300563622266054f, 0.006518820766359568f, 0.005416196770966053f, 0.002035725163295865f, 0.004039425402879715f, 0.0038592456839978695f, 0.005067409947514534f, 0.002704393584281206f, 0.009009766392409801f, 0.0075386203825473785f, 0.0027376858051866293f, 0.00317312590777874f, 0.006567422766238451f, 0.005807327106595039f, 0.008049622178077698f, 0.003995547536760569f, 0.006356644444167614f, 0.013414678163826466f, 0.006899082101881504f, 0.009038809686899185f, 0.00694093806669116f, 0.004327190574258566f, 0.01334702130407095f, 0.004730137065052986f, 0.004220979288220406f, 0.005502942483872175f, 0.007137413136661053f, 0.005992077756673098f, 0.006203422788530588f, 0.015805769711732864f, 0.006643000058829784f, 0.016741083934903145f, 0.008580761030316353f, 0.005681533366441727f, 0.001433399971574545f, 0.006291293539106846f, 0.021499106660485268f, 0.009092300198972225f, 0.010097970254719257f, 0.0038666652981191874f, 0.013626877218484879f, 0.0015428599435836077f, 0.0036043229047209024f, 0.007028022315353155f, 0.009912942536175251f, 0.011446021497249603f, 0.010288786143064499f, 0.0049148621037602425f, 0.0055427937768399715f, 0.0032764507923275232f, 0.009486709721386433f, 0.005912918597459793f, 0.0029149833135306835f, 0.004604875575751066f, 0.016671989113092422f, 0.009821872226893902f, 0.010020637884736061f, 0.002962188096717f, 0.010619275271892548f, 0.0029796722810715437f, 0.007594469003379345f, 0.008012717589735985f, 0.017671987414360046f, 0.010792922228574753f, 0.0011612457456067204f, 0.005928938277065754f, 0.00463944673538208f, 0.008048515766859055f, 0.005211781244724989f, 0.004118075128644705f, 0.007111349143087864f, 0.0033290947321802378f, 0.0052373469807207584f, 0.004607453942298889f, 0.004488830920308828f, 0.004606710281223059f, 0.008996855467557907f, 0.0030691390857100487f, 0.012146181426942348f, 0.0034916952718049288f, 0.004089586902409792f, 0.007209028583019972f, 0.010622133500874043f, 0.003458832623437047f, 0.008659918792545795f, 0.005830818321555853f, 0.18318727612495422f, 0.009691261686384678f, 0.014229022897779942f, 0.016230929642915726f, 0.002321495208889246f, 0.005865119397640228f, 0.008985960856080055f, 0.012499937787652016f, 0.003911822568625212f, 0.01454925537109375f, 0.003924068063497543f, 0.003600434632971883f, 0.002040113089606166f, 0.014523494988679886f, 0.0028707103338092566f, 0.0044358293525874615f, 0.00641839113086462f, 0.001207095105201006f, 0.006780398078262806f, 0.0071227350272238255f, 0.005257424898445606f, 0.006062102038413286f, 0.01998639479279518f, 0.0027939353603869677f, 0.004774698056280613f, 0.007736705243587494f, 0.010494733229279518f, 0.00849099736660719f, 0.0012754278723150492f, 0.007060056086629629f, 0.008782629854977131f, 0.015548091381788254f, 0.006029572803527117f, 0.008596819825470448f, 0.006344845052808523f, 0.0031876948196440935f, 0.003716184990480542f, 0.005105137825012207f, 0.002011190867051482f, 0.0017161063151434064f, 0.004161303862929344f, 0.007659387309104204f, 0.006168346852064133f, 0.0044962638057768345f, 0.004031892400234938f, 0.0016749122878536582f, 0.00913112610578537f, 0.003351974068209529f, 0.0035429729614406824f, 0.005586015526205301f, 0.018582625314593315f, 0.005407437682151794f, 0.009255667217075825f, 0.007358316797763109f, 0.00584417162463069f, 0.007701468653976917f, 0.0031608683057129383f, 0.019264906644821167f, 0.007780506741255522f, 0.006871684454381466f, 0.009070298634469509f, 0.0049919793382287025f, 0.004018355160951614f, 0.006490308791399002f, 0.007765051443129778f, 0.007056157570332289f, 0.002580762142315507f, 0.004702460020780563f, 0.0014110880438238382f, 0.0036399655509740114f, 0.012897636741399765f, 0.0028401457238942385f, 0.019781917333602905f, 0.010179709643125534f, 0.004682526458054781f, 0.00425194064155221f, 0.012136195786297321f, 0.007233080454170704f, 0.01102440059185028f, 0.009073411114513874f, 0.007725305389612913f, 0.0035558638628572226f, 0.01144507247954607f, 0.022218603640794754f, 0.009234986267983913f, 0.006783450022339821f, 0.001948460703715682f, 0.007579800207167864f, 0.0015347911976277828f, 0.008036362938582897f, 0.0038627067115157843f, 0.005389223340898752f, 0.012011048384010792f, 0.004152080975472927f, 0.0019574325997382402f, 0.011648508720099926f, 0.012594981119036674f, 0.007614612113684416f, 0.010976358316838741f, 0.00816228985786438f, 0.009660403244197369f, 0.006498025730252266f, 0.008220041170716286f, 0.011531050316989422f, 0.008025242015719414f, 0.006965884938836098f, 0.0020084248390048742f, 0.00714086415246129f, 0.00824273657053709f, 0.004161593969911337f, 0.0059335785917937756f, 0.010801239870488644f, 0.004438138101249933f, 0.006986919324845076f, 0.0050868140533566475f, 0.0044112359173595905f, 0.01238177064806223f, 0.0069493623450398445f, 0.005898738745599985f, 0.009283707477152348f, 0.004414306487888098f, 0.0033757882192730904f, 0.00907593872398138f, 0.0015842834254726768f, 0.013429033569991589f, 0.010209799744188786f, 0.0014485925203189254f, 0.008543891832232475f, 0.004180521704256535f, 0.009819074533879757f, 0.015282667241990566f, 0.005584838334470987f, 0.005511076655238867f, 0.008059040643274784f, 0.0028835334815084934f, 0.0031367959454655647f, 0.005588970612734556f, 0.014254635199904442f, 0.0035633782390505075f, 0.010806046426296234f, 0.006984042003750801f, 0.007953896187245846f, 0.005466955713927746f, 0.010594721883535385f, 0.012054993771016598f, 0.006099284626543522f, 0.006286675110459328f, 0.004018334671854973f, 0.0013322742888703942f, 0.006753504276275635f, 0.006616905331611633f, 0.00752987340092659f, 0.010540811344981194f, 0.0020375188905745745f, 0.0034300500992685556f, 0.011686010286211967f, 0.0037832544185221195f, 0.005466551054269075f, 0.003493217984214425f, 0.008963664062321186f, 0.005242681596428156f, 0.005152217112481594f, 0.005351724568754435f, 0.003356321481987834f, 0.007995998486876488f, 0.00675751268863678f, 0.0069473665207624435f, 0.006551442202180624f, 0.00674639455974102f, 0.006781954318284988f, 0.002802274189889431f, 0.0020962455309927464f, 0.004261614754796028f, 0.008249045349657536f, 0.0186807531863451f, 0.005930028855800629f, 0.0021199325565248728f, 0.009491130709648132f, 0.005200052168220282f, 0.0049818591214716434f, 0.00451402273029089f, 0.008267806842923164f, 0.1805020123720169f, 0.008079704828560352f, 0.0028978220652788877f, 0.004257858265191317f, 0.012588941492140293f, 0.005427975673228502f, 0.010489578358829021f, 0.014231113716959953f, 0.01339210569858551f, 0.009728919714689255f, 0.015994537621736526f, 0.007224287837743759f, 0.007181243970990181f, 0.0067487140186131f, 0.010809380561113358f, 0.00986594520509243f, 0.003554128808900714f, 0.014426007866859436f, 0.0024851388297975063f, 0.009382428601384163f, 0.009525511413812637f, 0.013625465333461761f, 0.010744319297373295f, 0.00650359969586134f, 0.020398925989866257f, 0.003892664099112153f, 0.009518614038825035f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #160 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_61_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.380191477248445e-05f, 0.00010036130697699264f, 9.52997652348131e-05f, 9.16235803742893e-05f, 0.00011224629997741431f, 0.00015336395881604403f, 6.790482439100742e-05f, 0.00017841937369666994f, 0.0001890968851512298f, 0.000161657138960436f, 0.00017063446284737438f, 0.0001413330901414156f, 6.578192551387474e-05f, 0.00017544993897899985f, 0.0001700438151601702f, 0.00021543845650739968f, 0.00027527808560989797f, 0.00013934713206253946f, 0.00028082370408810675f, 8.223046461353078e-05f, 0.000225399766350165f, 0.00014106999151408672f, 0.0002022265107370913f, 0.0002896140213124454f, 7.819967868272215e-05f, 0.00017549152835272253f, 0.00012469911598600447f, 0.0001550950255477801f, 6.567007949342951e-05f, 0.00013885907537769526f, 0.00026517329388298094f, 0.00013587986177299172f, 0.00014990856288932264f, 0.00011535129306139424f, 0.00016666225565131754f, 0.00018661805370356888f, 9.068876534001902e-05f, 0.0002004794660024345f, 0.00019744024029932916f, 0.00017994135851040483f, 0.00019969271670561284f, 0.00017177796689793468f, 0.00015338402590714395f, 0.00012743992556352168f, 4.7899415221763775e-05f, 9.504530316917226e-05f, 9.080578456632793e-05f, 0.00011923317651962861f, 6.363278953358531e-05f, 0.000211994512937963f, 0.00017737930465955287f, 6.441614095820114e-05f, 7.466178794857115e-05f, 0.0001545276027172804f, 0.00013664299331139773f, 0.0001894028828246519f, 9.401288843946531e-05f, 0.00014956810628063977f, 0.00031563948141410947f, 0.00016233134374488145f, 0.00021267788542900234f, 0.00016331618826370686f, 0.00010181625111727044f, 0.00031404756009578705f, 0.00011129734775749967f, 9.931716340361163e-05f, 0.00012948100629728287f, 0.00016793914255686104f, 0.00014099007239565253f, 0.00014596289838664234f, 0.00037190047441981733f, 0.0001563058904139325f, 0.00039390785968862474f, 0.00020190025679767132f, 0.00013368313375394791f, 3.3727057598298416e-05f, 0.0001480304345022887f, 0.0005058613605797291f, 0.0002139364805771038f, 0.00023759930627420545f, 9.098036389332265e-05f, 0.0003206324181519449f, 3.6302586522651836e-05f, 8.480760152451694e-05f, 0.00016536522889509797f, 0.00023324570793192834f, 0.00026931814500130713f, 0.00024208909599110484f, 0.00011564381566131487f, 0.00013041867350693792f, 7.709296187385917e-05f, 0.00022321670257952064f, 0.00013912750000599772f, 6.858784763608128e-05f, 0.00010835001739906147f, 0.00039228209061548114f, 0.0002311028802068904f, 0.00023577972024213523f, 6.969854439375922e-05f, 0.00024986531934700906f, 7.010993431322277e-05f, 0.00017869338626042008f, 0.0001885345409391448f, 0.0004158114898018539f, 0.00025395111879333854f, 2.732342909439467e-05f, 0.0001395044382661581f, 0.00010916345490841195f, 0.00018937684944830835f, 0.00012263015378266573f, 9.68958847806789e-05f, 0.00016732586664147675f, 7.83316427259706e-05f, 0.00012323170085437596f, 0.00010841068433364853f, 0.00010561955423327163f, 0.00010839318565558642f, 0.00021169072715565562f, 7.221503619803116e-05f, 0.0002857925137504935f, 8.215753769036382e-05f, 9.622557263355702e-05f, 0.00016962421068456024f, 0.0002499325491953641f, 8.138429984683171e-05f, 0.00020376280008349568f, 0.00013719573325943202f, 0.004310288932174444f, 0.00022802969033364207f, 0.0003348005411680788f, 0.00038190424675121903f, 5.4623418691335246e-05f, 0.0001380028115818277f, 0.0002114343806169927f, 0.0002941161801572889f, 9.204288653563708e-05f, 0.00034233543556183577f, 9.233101445715874e-05f, 8.47161136334762e-05f, 4.800266106030904e-05f, 0.0003417292900849134f, 6.75461269565858e-05f, 0.00010437245509820059f, 0.00015102096949703991f, 2.8402238967828453e-05f, 0.00015953878755681217f, 0.00016759376740083098f, 0.00012370411423034966f, 0.00014263769844546914f, 0.00047026813263073564f, 6.573965947609395e-05f, 0.00011234584235353395f, 0.00018204012303613126f, 0.00024693491286598146f, 0.00019978817726951092f, 3.001006734848488e-05f, 0.0001661189744481817f, 0.00020665011834353209f, 0.00036583744804374874f, 0.0001418722968082875f, 0.0002022781118284911f, 0.00014929047028999776f, 7.500458741560578e-05f, 8.743965008761734e-05f, 0.00012012089428026229f, 4.732214074465446e-05f, 4.0378974517807364e-05f, 9.791303455131128e-05f, 0.00018022088625002652f, 0.00014513757196255028f, 0.00010579444642644376f, 9.486806084169075e-05f, 3.9409700548276305e-05f, 0.00021485003526322544f, 7.88699762779288e-05f, 8.336407336173579e-05f, 0.0001314356632065028f, 0.00043723825365304947f, 0.00012723382678814232f, 0.00021778041264042258f, 0.00017313686839770526f, 0.0001375099236611277f, 0.00018121102766599506f, 7.437337626470253e-05f, 0.0004532919265329838f, 0.00018307074788026512f, 0.0001616866939002648f, 0.00021341879619285464f, 0.00011745833762688562f, 9.454953396925703e-05f, 0.00015271315351128578f, 0.00018270709551870823f, 0.00016602723917458206f, 6.072381802368909e-05f, 0.00011064612044719979f, 3.320207179058343e-05f, 8.564625022700056e-05f, 0.00030347381834872067f, 6.682695675408468e-05f, 0.0004654568911064416f, 0.000239522589254193f, 0.0001101770976674743f, 0.00010004566138377413f, 0.0002855575585272163f, 0.00017019013466779143f, 0.0002593976678326726f, 0.000213492035982199f, 0.000181771902134642f, 8.366738620679826e-05f, 0.0002692958223633468f, 0.0005227907095104456f, 0.000217293796595186f, 0.00015961058670654893f, 4.5846136345062405e-05f, 0.00017834824393503368f, 3.611273496062495e-05f, 0.0001890908897621557f, 9.088721708394587e-05f, 0.0001268052583327517f, 0.00028261292027309537f, 9.769602183951065e-05f, 4.6057237341301516e-05f, 0.00027408255846239626f, 0.00029635248938575387f, 0.000179167342139408f, 0.0002582672459539026f, 0.00019205387798137963f, 0.00022730360797140747f, 0.00015289473230950534f, 0.00019341273582540452f, 0.0002713188296183944f, 0.00018882923177443445f, 0.00016390318342018872f, 4.725705730379559e-05f, 0.00016802034224383533f, 0.0001939467474585399f, 9.791985939955339e-05f, 0.00013961362128611654f, 0.0002541468129493296f, 0.00010442677739774808f, 0.0001643981086090207f, 0.00011968974285991862f, 0.00010379379091318697f, 0.0002913357748184353f, 0.00016351441445294768f, 0.00013879385369364172f, 0.0002184401819249615f, 0.0001038660338963382f, 7.94303123257123e-05f, 0.00021355150965973735f, 3.727725925273262e-05f, 0.0003159772604703903f, 0.00024023058358579874f, 3.4084529033862054e-05f, 0.00020103275892324746f, 9.836522076511756e-05f, 0.00023103704734239727f, 0.0003595921734813601f, 0.00013140795635990798f, 0.00012967239308636636f, 0.0001896244939416647f, 6.784784636693075e-05f, 7.380696479231119e-05f, 0.00013150519225746393f, 0.00033540319418534636f, 8.384419197682291e-05f, 0.0002542599104344845f, 0.00016433039854746312f, 0.00018715050828177482f, 0.00012863425945397466f, 0.00024928757920861244f, 0.0002836469211615622f, 0.000143512588692829f, 0.00014792177535127848f, 9.454905375605449e-05f, 3.1347630283562467e-05f, 0.0001589059829711914f, 0.0001556918869027868f, 0.00017717349692247808f, 0.0002480190887581557f, 4.794162305188365e-05f, 8.070706098806113e-05f, 0.000274964957498014f, 8.901775436243042e-05f, 0.00012862472794950008f, 8.219336450565606e-05f, 0.0002109097404172644f, 0.00012335721112322062f, 0.00012122863699914888f, 0.00012592293205671012f, 7.89722689660266e-05f, 0.00018814114446286112f, 0.00015900030848570168f, 0.00016346745542250574f, 0.0001541515812277794f, 0.0001587386941537261f, 0.00015957540017552674f, 6.593586294911802e-05f, 4.932342562824488e-05f, 0.00010027328971773386f, 0.00019409519154578447f, 0.0004395471478346735f, 0.00013953009329270571f, 4.9880767619470134e-05f, 0.00022332073422148824f, 0.00012235417671035975f, 0.00011722021736204624f, 0.00010621230467222631f, 0.0001945366384461522f, 0.004247106146067381f, 0.0001901107025332749f, 6.818404654040933e-05f, 0.00010018490138463676f, 0.0002962104044854641f, 0.00012771708134096116f, 0.0002468136081006378f, 0.00033484972664155066f, 0.00031510836561210454f, 0.00022891575645189732f, 0.00037634206819348037f, 0.00016998325008898973f, 0.00016897045134101063f, 0.0001587932783877477f, 0.00025433837436139584f, 0.0002321398933418095f, 8.362656080862507e-05f, 0.0003394354716874659f, 5.8473855460761115e-05f, 0.00022076303139328957f, 0.00022412968974094838f, 0.0003205991815775633f, 0.00025280751287937164f, 0.00015302587416954339f, 0.00047997472574934363f, 9.159209730569273e-05f, 0.0002239673922304064f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #161 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_62_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006004514172673225f, 0.006672287825495005f, 0.0075259641744196415f, 0.011787718161940575f, 0.010811427608132362f, 0.011334644630551338f, 0.008355858735740185f, 0.006288899574428797f, 0.016605762764811516f, 0.007369942497462034f, 0.01625916175544262f, 0.017795192077755928f, 0.00704930629581213f, 0.010395390912890434f, 0.021041566506028175f, 0.006864215712994337f, 0.008627906441688538f, 0.009934168308973312f, 0.01113484613597393f, 0.011730756610631943f, 0.011761287227272987f, 0.01130280178040266f, 0.009016536176204681f, 0.007169374264776707f, 0.01562911830842495f, 0.009375156834721565f, 0.00883255060762167f, 0.022451287135481834f, 0.009491575881838799f, 0.013603302650153637f, 0.013262934051454067f, 0.019815586507320404f, 0.008827341720461845f, 0.011305060237646103f, 0.008206082507967949f, 0.014803512021899223f, 0.005457728169858456f, 0.023198172450065613f, 0.005911354906857014f, 0.017302898690104485f, 0.008570591919124126f, 0.017877688631415367f, 0.004735968541353941f, 0.008470072411000729f, 0.012854507192969322f, 0.018218044191598892f, 0.006430936977267265f, 0.008358840830624104f, 0.010580864734947681f, 0.007810387294739485f, 0.012674505822360516f, 0.013405994512140751f, 0.014385714195668697f, 0.012731337919831276f, 0.010558334179222584f, 0.00998570118099451f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #162 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_62_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00014128268230706453f, 0.00015699501091148704f, 0.00017708151426631957f, 0.0002773580781649798f, 0.00025438654120080173f, 0.000266697519691661f, 0.00019660843827296048f, 0.0001479741040384397f, 0.00039072384242899716f, 0.0001734104153001681f, 0.0003825685125775635f, 0.0004187104059383273f, 0.00016586603305768222f, 0.0002445974387228489f, 0.0004950956790708005f, 0.00016151096497196704f, 0.00020300956384744495f, 0.00023374514421448112f, 0.0002619963779579848f, 0.00027601781766861677f, 0.00027673618751578033f, 0.00026594827068038285f, 0.0002121537982020527f, 0.00016869115643203259f, 0.00036774398176930845f, 0.00022059192997403443f, 0.0002078247198369354f, 0.0005282656056806445f, 0.00022333119704853743f, 0.00032007772824727f, 0.00031206905259750783f, 0.0004662490973714739f, 0.0002077021636068821f, 0.00026600141427479684f, 0.00019308429909870028f, 0.0003483179316390306f, 0.0001284171303268522f, 0.000545839371625334f, 0.0001390907127643004f, 0.0004071270232088864f, 0.0002016609942074865f, 0.0004206515150144696f, 0.00011143455776618794f, 0.00019929582776967436f, 0.0003024589968845248f, 0.00042865987052209675f, 0.00015131616964936256f, 0.00019667860760819167f, 0.00024896152899600565f, 0.00018377382366452366f, 0.00029822366195730865f, 0.0003154351725243032f, 0.00033848738530650735f, 0.0002995608956553042f, 0.00024843140272423625f, 0.00023495768255088478f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #163 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0006649402785114944f, 0.0007016371819190681f, 0.0006823450676165521f, 0.00038752934779040515f, 0.0010318420827388763f, 0.001696089399047196f, 0.0012214476009830832f, 0.0004119074728805572f, 0.000776986125856638f, 0.0006520307506434619f, 0.0007898996700532734f, 0.0005561304278671741f, 0.000725434860214591f, 0.0007528444984927773f, 0.000570882810279727f, 0.0007315912516787648f, 0.0007319690776057541f, 0.0005577296833507717f, 0.0006917889695614576f, 0.0007486868998967111f, 0.0006801199051551521f, 0.0007849588291719556f, 0.0006584518123418093f, 0.0004536891356110573f, 0.0008272877312265337f, 0.0010672509670257568f, 0.00041948971920646727f, 0.0007390722166746855f, 0.00046094635035842657f, 0.0006863682065159082f, 0.0008935623336583376f, 0.0007655819645151496f, 0.0008401668746955693f, 0.000964007806032896f, 0.0006039122818037868f, 0.0007070221472531557f, 0.0006653124000877142f, 0.0010880768531933427f, 0.0006344556459225714f, 0.0005510462797246873f, 0.0006192508153617382f, 0.0006442319136112928f, 0.000798747583758086f, 0.0007824029889889061f, 0.0007424806826747954f, 0.000556876533664763f, 0.0008408682770095766f, 0.0009031985537149012f, 0.0007894692244008183f, 0.0006747341831214726f, 0.000268580304691568f, 0.0008293255814351141f, 0.0006266394047997892f, 0.0009253066382370889f, 0.000464334967546165f, 0.0008749538101255894f, 0.0007463135407306254f, 0.0007135903579182923f, 0.0007052310393191874f, 0.0005086322780698538f, 0.0006267601856961846f, 0.000617068784777075f, 0.0005208669463172555f, 0.0005122447619214654f, 0.0009067363571375608f, 0.0006690305308438838f, 0.0007627885788679123f, 0.00032541804830543697f, 0.0008087654714472592f, 0.001101383357308805f, 0.0008099450496956706f, 0.0005581793375313282f, 0.0005641503375954926f, 0.0004897693870589137f, 0.0009046258055604994f, 0.0008677614969201386f, 0.0006496286951005459f, 0.0006111497059464455f, 0.0005427730502560735f, 0.0009012096561491489f, 0.0008865157142281532f, 0.0010000335751101375f, 0.0014974242076277733f, 0.0010252241045236588f, 0.0005524339503608644f, 0.0005018217489123344f, 0.0006486981292255223f, 0.0006214958266355097f, 0.0004932566662319005f, 0.0008064733119681478f, 0.0007182647241279483f, 0.0007632864871993661f, 0.0005514384247362614f, 0.0007085987599566579f, 0.00079065264435485f, 0.0006732718902640045f, 0.0007120525697246194f, 0.0008881025132723153f, 0.000682998972479254f, 0.0005107492324896157f, 0.0005839763325639069f, 0.0006604923983104527f, 0.0010148006258532405f, 0.0008522199932485819f, 0.0007370282546617091f, 0.0009174800361506641f, 0.0006176052265800536f, 0.000966439547482878f, 0.0007404366624541581f, 0.0008296563173644245f, 0.0003971608530264348f, 0.0007663253927603364f, 0.0005548582412302494f, 0.0006955345743335783f, 0.0005433241021819413f, 0.000794643652625382f, 0.0007300672004930675f, 0.0009290980524383485f, 0.0008731738198548555f, 0.0007790510426275432f, 0.0007122164824977517f, 0.0006496662390418351f, 0.0006310649332590401f, 0.0006980012403801084f, 0.0011033689370378852f, 0.0008455868810415268f, 0.001059798989444971f, 0.0008595704566687346f, 0.0007392800180241466f, 0.0005228103836998343f, 0.000836299208458513f, 0.0005055915680713952f, 0.000738660164643079f, 0.0005357160698622465f, 0.0003413863596506417f, 0.000769502017647028f, 0.0006515212589874864f, 0.0006481357850134373f, 0.0009932483080774546f, 0.0005974641535431147f, 0.0005079153925180435f, 0.0006440322031266987f, 0.0011980341514572501f, 0.0007443932117894292f, 0.0007645731093361974f, 0.0008629985968582332f, 0.0007776675629429519f, 0.0005717951571568847f, 0.0008317836909554899f, 0.0010040400084108114f, 0.00048461832921020687f, 0.0007265011081472039f, 0.00096609111642465f, 0.0006104922504164279f, 0.0007158149965107441f, 0.0005773053853772581f, 0.0005395496846176684f, 0.0007730299839749932f, 0.0008862834656611085f, 0.0006451529916375875f, 0.0005049113533459604f, 0.0008896293002180755f, 0.0010158185614272952f, 0.0005213830154389143f, 0.0006666505942121148f, 0.0004966082633472979f, 0.0012062093010172248f, 0.000834634352941066f, 0.0007221339619718492f, 0.0009476802661083639f, 0.0006136802840046585f, 0.0009166727541014552f, 0.0009257922065444291f, 0.00081584881991148f, 0.0005824693944305182f, 0.000789992802310735f, 0.0007081245421431959f, 0.0006237251218408346f, 0.0006963793421164155f, 0.0007158592343330383f, 0.0006192934815771878f, 0.0012883668532595038f, 0.0007644848083145916f, 0.0011048807064071298f, 0.0006988706300035119f, 0.001664515002630651f, 0.0006124029750935733f, 0.0005761178326793015f, 0.0005902366247028112f, 0.0007354815606959164f, 0.000516422267537564f, 0.0005960081471130252f, 0.0006981016485951841f, 0.0004966253181919456f, 0.0008808944257907569f, 0.0006731220637448132f, 0.0023691195528954268f, 0.0006153880385681987f, 0.0006232005544006824f, 0.0006243691314011812f, 0.0008073897333815694f, 0.001030939631164074f, 0.0008432955364696681f, 0.0006954643176868558f, 0.0006461467128247023f, 0.001237629447132349f, 0.0008223797776736319f, 0.0005952493520453572f, 0.0005784654640592635f, 0.00047910751891322434f, 0.0007281992584466934f, 0.0005200597806833684f, 0.0004774031403940171f, 0.0006553486455231905f, 0.0005547984619624913f, 0.0005771591095253825f, 0.0008327788673341274f, 0.0006448639906011522f, 0.00036707971594296396f, 0.0013325391337275505f, 0.0006791322375647724f, 0.0008541470160707831f, 0.0006411985377781093f, 0.0006564129143953323f, 0.0007730436627753079f, 0.0007835864089429379f, 0.0006455514230765402f, 0.000928052410017699f, 0.0010667558526620269f, 0.001018586684949696f, 0.0014743219362571836f, 0.0009656816837377846f, 0.0007533603929914534f, 0.0006726727588102221f, 0.0008569828933104873f, 0.0005153596284799278f, 0.0008041919791139662f, 0.000872890290338546f, 0.0008216716232709587f, 0.0005795761244371533f, 0.0006649067508988082f, 0.0007662393618375063f, 0.000752572319470346f, 0.0005786335677839816f, 0.0005732288118451834f, 0.0009738713270053267f, 0.0010180409299209714f, 0.0007430104305967689f, 0.0007919213967397809f, 0.0010527493432164192f, 0.0007440100307576358f, 0.0009008998749777675f, 0.0007418414461426437f, 0.0009428259800188243f, 0.0005554371164180338f, 0.0006758459494449198f, 0.0005959614063613117f, 0.0006964536150917411f, 0.0007224156870506704f, 0.000700930948369205f, 0.0007383791962638497f, 0.0006590168341062963f, 0.0007068226113915443f, 0.0005311210406944156f, 0.0005404299590736628f, 0.0008274183492176235f, 0.0006979000754654408f, 0.0007115774787962437f, 0.00045073599903844297f, 0.0010233415523543954f, 0.0008540228009223938f, 0.0008543241419829428f, 0.0006314110942184925f, 0.0009409774793311954f, 0.0006152119603939354f, 0.0006033758982084692f, 0.000726023456081748f, 0.0009334191563539207f, 0.000657502852845937f, 0.0008735554874874651f, 0.0005718720494769514f, 0.0005827210261486471f, 0.0009951452957466245f, 0.0011103133438155055f, 0.000857610662933439f, 0.0008587014162912965f, 0.0007484618690796196f, 0.0005938700633123517f, 0.0010011321865022182f, 0.0005589908105321229f, 0.0011637534480541945f, 0.000691585591994226f, 0.0006090041715651751f, 0.0004874364531133324f, 0.0008569139172323048f, 0.0006685436819680035f, 0.0005932959029451013f, 0.0007423193892464042f, 0.0007524426328018308f, 0.0005995317478664219f, 0.0010298789711669087f, 0.000596970843616873f, 0.0013417761074379086f, 0.0011379478964954615f, 0.0008261798648163676f, 0.0005103235016576946f, 0.0008949760813266039f, 0.0006799369584769011f, 0.0005645584315061569f, 0.0008377734338864684f, 0.000847703660838306f, 0.000654683739412576f, 0.0007077237823978066f, 0.0007923412485979497f, 0.0006555547588504851f, 0.0006246514385566115f, 0.0006450929795391858f, 0.0006529766251333058f, 0.000604666885919869f, 0.0006776911322958767f, 0.0009669123101048172f, 0.0005405987030826509f, 0.0006470021326094866f, 0.0009280266240239143f, 0.0014496106887236238f, 0.0006949927774257958f, 0.0004989245790056884f, 0.0007888039690442383f, 0.00099334423430264f, 0.0007020909106358886f, 0.0005758300540037453f, 0.0006072219694033265f, 0.00039745241519995034f, 0.0006620276835747063f, 0.0005242477636784315f, 0.000795370782725513f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #164 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011662009637802839f, 0.00012305616110097617f, 0.00011967262253165245f, 6.796656816732138e-05f, 0.0001809689129004255f, 0.0002974674862343818f, 0.00021422274585347623f, 7.224211003631353e-05f, 0.00013627117732539773f, 0.0001143559638876468f, 0.0001385360083077103f, 9.753655467648059e-05f, 0.00012722989777103066f, 0.00013203710841480643f, 0.00010012389248004183f, 0.00012830963532906026f, 0.000128375890199095f, 9.781703556654975e-05f, 0.0001213289360748604f, 0.00013130794104654342f, 0.0001192823619931005f, 0.0001376694708596915f, 0.00011548212205525488f, 7.956995978020132e-05f, 0.00014509329048451036f, 0.0001871790736913681f, 7.3571914981585e-05f, 0.0001296216796617955f, 8.084275759756565e-05f, 0.0001203782157972455f, 0.00015671682194806635f, 0.0001342710602330044f, 0.00014735209697391838f, 0.0001690718490863219f, 0.00010591674072202295f, 0.0001240005949512124f, 0.00011668536171782762f, 0.00019083160441368818f, 0.00011127356992801651f, 9.664487151894718e-05f, 0.00010860688053071499f, 0.00011298817116767168f, 0.00014008779544383287f, 0.0001372212136629969f, 0.00013021945778746158f, 9.766740549821407e-05f, 0.00014747510431334376f, 0.00015840685227885842f, 0.00013846051297150552f, 0.00011833778989966959f, 4.710477151093073e-05f, 0.00014545070007443428f, 0.00010990272130584344f, 0.00016228426829911768f, 8.143707236740738e-05f, 0.00015345317660830915f, 0.00013089168351143599f, 0.00012515255366452038f, 0.00012368646275717765f, 8.920612162910402e-05f, 0.00010992390161845833f, 0.00010822418698808178f, 9.135188884101808e-05f, 8.983969746623188e-05f, 0.00015902733139228076f, 0.0001173374621430412f, 0.0001337811554549262f, 5.707321906811558e-05f, 0.00014184477913659066f, 0.00019316536781843752f, 0.00014205164916347712f, 9.789589967112988e-05f, 9.894312097458169e-05f, 8.589786739321426e-05f, 0.0001586571743246168f, 0.0001521917583886534f, 0.00011393468594178557f, 0.00010718606790760532f, 9.519387822365388e-05f, 0.00015805804287083447f, 0.00015548094233963639f, 0.0001753902033669874f, 0.0002626247296575457f, 0.0001798082230379805f, 9.688825230114162e-05f, 8.80116640473716e-05f, 0.00011377147893654183f, 0.00010900061897700652f, 8.650948439026251e-05f, 0.0001414427679264918f, 0.00012597236491274089f, 0.00013386848149821162f, 9.671365114627406e-05f, 0.00012427711044438183f, 0.00013866806693840772f, 0.00011808132694568485f, 0.00012488284846767783f, 0.0001557592477183789f, 0.00011978730617556721f, 8.957740647019818e-05f, 0.00010242028656648472f, 0.00011584000458242372f, 0.00017798010958358645f, 0.00014946602459531277f, 0.00012926319323014468f, 0.00016091160068754107f, 0.00010831826512003317f, 0.00016949833661783487f, 0.00012986097135581076f, 0.00014550870400853455f, 6.965578359086066e-05f, 0.00013440144539345056f, 9.731343016028404e-05f, 0.00012198585318401456f, 9.529052476864308e-05f, 0.0001393680286128074f, 0.00012804233119823039f, 0.0001629492180654779f, 0.000153140994370915f, 0.0001366333308396861f, 0.00012491160305216908f, 0.0001139412634074688f, 0.00011067889136029407f, 0.00012241846707183868f, 0.00019351360970176756f, 0.00014830267173238099f, 0.0001858721225289628f, 0.0001507551787653938f, 0.00012965811765752733f, 9.169273835141212e-05f, 0.00014667375944554806f, 8.867283031577244e-05f, 0.0001295494002988562f, 9.39561941777356e-05f, 5.987381155136973e-05f, 0.0001349585800198838f, 0.00011426660785218701f, 0.00011367284605512396f, 0.00017420017684344202f, 0.00010478583863005042f, 8.908039308153093e-05f, 0.000112953144707717f, 0.0002101163991028443f, 0.00013055489398539066f, 0.00013409412349574268f, 0.00015135642024688423f, 0.0001363906922051683f, 0.00010028389806393534f, 0.00014588181511498988f, 0.00017609287169761956f, 8.499445539200678e-05f, 0.0001274169044336304f, 0.00016943723312579095f, 0.00010707076580729336f, 0.00012554271961562335f, 0.00010125030530616641f, 9.462855086894706e-05f, 0.00013557732745539397f, 0.0001554402115289122f, 0.00011314971197862178f, 8.855353371473029e-05f, 0.00015602701751049608f, 0.0001781586470315233f, 9.144240175373852e-05f, 0.00011692005500663072f, 8.709730172995478e-05f, 0.00021155018475838006f, 0.00014638177526649088f, 0.00012665096437558532f, 0.00016620825044810772f, 0.0001076298940461129f, 0.0001607700251042843f, 0.0001623694261070341f, 0.00014308709069155157f, 0.00010215599468210712f, 0.00013855235010851175f, 0.0001241939316969365f, 0.00010939159983536229f, 0.00012213400623295456f, 0.00012555047578644007f, 0.00010861436021514237f, 0.0002259593311464414f, 0.0001340786402579397f, 0.0001937787455972284f, 0.0001225709420396015f, 0.0002919298131018877f, 0.0001074058745871298f, 0.00010104203101946041f, 0.00010351824312238023f, 0.0001289919309783727f, 9.057236457010731e-05f, 0.00010453048162162304f, 0.000122436074889265f, 8.710029214853421e-05f, 0.00015449506463482976f, 0.00011805505346274003f, 0.00041550639434717596f, 0.00010792940884130076f, 0.00010929960262728855f, 0.00010950455180136487f, 0.0001416034938301891f, 0.00018081063171848655f, 0.0001479008060414344f, 0.00012197353498777375f, 0.00011332400026731193f, 0.00021706079132854939f, 0.000144232515594922f, 0.00010439739708090201f, 0.00010145377018488944f, 8.402794628636912e-05f, 0.00012771472393069416f, 9.121032780967653e-05f, 8.3729020843748e-05f, 0.00011493787314975634f, 9.7302945505362e-05f, 0.0001012246502796188f, 0.0001460563507862389f, 0.00011309902765788138f, 6.438002310460433e-05f, 0.00023370646522380412f, 0.00011910914327017963f, 0.0001498039928264916f, 0.00011245616769883782f, 0.0001151245305663906f, 0.00013557972852140665f, 0.00013742876762989908f, 0.0001132195902755484f, 0.00016276583482977003f, 0.00018709224241320044f, 0.00017864412802737206f, 0.00025857295258902013f, 0.00016936541942413896f, 0.0001321275922236964f, 0.00011797624756582081f, 0.00015030136273708194f, 9.038599091582e-05f, 0.00014104266301728785f, 0.00015309127047657967f, 0.0001441083149984479f, 0.00010164856212213635f, 0.00011661421012831852f, 0.00013438636960927397f, 0.00013198937813285738f, 0.00010148325236514211f, 0.00010053534060716629f, 0.00017080175166483968f, 0.00017854840552899987f, 0.0001303123717661947f, 0.0001388905948260799f, 0.0001846357190515846f, 0.00013048769324086607f, 0.00015800370601937175f, 0.00013010734983254224f, 0.00016535689064767212f, 9.741495887283236e-05f, 0.00011853277828777209f, 0.00010452228161739185f, 0.00012214704474899918f, 0.00012670038267970085f, 0.0001229322951985523f, 0.00012950012751389295f, 0.00011558121332200244f, 0.00012396559759508818f, 9.315030183643103e-05f, 9.478293941356242e-05f, 0.0001451161951990798f, 0.0001224007282871753f, 0.0001247995242010802f, 7.905202073743567e-05f, 0.00017947805463336408f, 0.00014978220860939473f, 0.00014983504661358893f, 0.00011073960195062682f, 0.00016503268852829933f, 0.00010789852967718616f, 0.00010582266986602917f, 0.0001273331290576607f, 0.00016370708181057125f, 0.00011531568452483043f, 0.00015320793318096548f, 0.00010029738768935204f, 0.00010220012336503714f, 0.00017453287728130817f, 0.00019473154679872096f, 0.00015041146252769977f, 0.00015060276200529188f, 0.0001312684762524441f, 0.00010415549331810325f, 0.0001755828852765262f, 9.803821740206331e-05f, 0.0002041041007032618f, 0.00012129326205467805f, 0.0001068097772076726f, 8.548870391678065e-05f, 0.00015028925554361194f, 0.00011725207150448114f, 0.00010405479406472296f, 0.00013019116886425763f, 0.00013196663348935544f, 0.00010514846508158371f, 0.00018062461458612233f, 0.00010469932021806017f, 0.0002353264862904325f, 0.00019957820768468082f, 0.0001448989933123812f, 8.950273331720382e-05f, 0.0001569647720316425f, 0.00011925027502002195f, 9.901469456963241e-05f, 0.00014693231787532568f, 0.00014867392019368708f, 0.00011482126137707382f, 0.00012412364594638348f, 0.00013896422751713544f, 0.0001149740201071836f, 0.00010955406469292939f, 0.00011313919094391167f, 0.00011452185572125018f, 0.00010604908311506733f, 0.00011885639105457813f, 0.0001695812534308061f, 9.48125307331793e-05f, 0.00011347402323735878f, 0.000162761309184134f, 0.0002542389847803861f, 0.00012189082917757332f, 8.75035475473851e-05f, 0.00013834383571520448f, 0.00017421699885744601f, 0.00012313573097344488f, 0.00010099155770149082f, 0.00010649720934452489f, 6.970691902097315e-05f, 0.00011610927322180942f, 9.194483573082834e-05f, 0.0001394955615978688f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #165 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_65_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007026305887848139f, 0.0036353529430925846f, 0.0043481579050421715f, 0.008057111874222755f, 0.003183589316904545f, 0.0027583667542785406f, 0.003780241822823882f, 0.007726652547717094f, 0.004968347959220409f, 0.005624198820441961f, 0.004172229673713446f, 0.0031316557433456182f, 0.004894586279988289f, 0.002193683059886098f, 0.0642755776643753f, 0.00405290350317955f, 0.004861878231167793f, 0.005475187674164772f, 0.003523685038089752f, 0.003793739015236497f, 0.004936523269861937f, 0.0031934352591633797f, 0.004381969105452299f, 0.011412026360630989f, 0.002301872009411454f, 0.005593509413301945f, 0.005368095822632313f, 0.0021228217519819736f, 0.005094510968774557f, 0.003938939888030291f, 0.003465060144662857f, 0.0058786217123270035f, 0.003438799176365137f, 0.0043287742882966995f, 0.0038222346920520067f, 0.006653220392763615f, 0.003924541641026735f, 0.002440341981127858f, 0.0033816045615822077f, 0.003662097966298461f, 0.004090486094355583f, 0.010454904288053513f, 0.005960528273135424f, 0.0028180598746985197f, 0.004318201914429665f, 0.005548770073801279f, 0.004094368778169155f, 0.0051822783425450325f, 0.005441732704639435f, 0.006758775096386671f, 0.02370383031666279f, 0.004296198487281799f, 0.0055810390040278435f, 0.0017924279673025012f, 0.0034576384350657463f, 0.0032016041222959757f, 0.0031843273900449276f, 0.006726375315338373f, 0.0030015420634299517f, 0.0043002404272556305f, 0.0036640262696892023f, 0.006434028036892414f, 0.004881278146058321f, 0.004669349640607834f, 0.0035531490575522184f, 0.004411451052874327f, 0.0056914035230875015f, 0.0163893885910511f, 0.002642915118485689f, 0.004250579979270697f, 0.003994683735072613f, 0.004687989596277475f, 0.004319107159972191f, 0.004353510215878487f, 0.0020532789640128613f, 0.01010042242705822f, 0.004713099449872971f, 0.00464484840631485f, 0.008694387041032314f, 0.004849503748118877f, 0.002649323083460331f, 0.0037551983259618282f, 0.006822052877396345f, 0.0034535008016973734f, 0.0042635295540094376f, 0.0030570910312235355f, 0.0038581560365855694f, 0.0031596976332366467f, 0.007940893992781639f, 0.001964084105566144f, 0.008930223993957043f, 0.00537131866440177f, 0.00574441347271204f, 0.0029245803598314524f, 0.007753543555736542f, 0.006413229275494814f, 0.005709157790988684f, 0.0025956472381949425f, 0.0027905532624572515f, 0.003386574564501643f, 0.004355667624622583f, 0.0041378336027264595f, 0.003153326688334346f, 0.004787267651408911f, 0.006252500228583813f, 0.0040707397274672985f, 0.004481947980821133f, 0.003659911686554551f, 0.00381884234957397f, 0.0030711940489709377f, 0.006808190140873194f, 0.0028181946836411953f, 0.006303002592176199f, 0.004351021721959114f, 0.004787645302712917f, 0.002209586091339588f, 0.003434413345530629f, 0.005142256151884794f, 0.003685382893308997f, 0.004150067456066608f, 0.005020297132432461f, 0.004567499738186598f, 0.004001356661319733f, 0.0018157820450142026f, 0.003507759189233184f, 0.002471582032740116f, 0.0031753829680383205f, 0.0023147377651184797f, 0.004188192542642355f, 0.0050335838459432125f, 0.0016429719980806112f, 0.0066215344704687595f, 0.007094143889844418f, 0.003244758350774646f, 0.017853837460279465f, 0.0021608907263725996f, 0.00404993025586009f, 0.004498165566474199f, 0.00237607816234231f, 0.005129439756274223f, 0.004829936660826206f, 0.0023331379052251577f, 0.001702204579487443f, 0.0037458916194736958f, 0.003990980330854654f, 0.004722705576568842f, 0.002407197142019868f, 0.0063133579678833485f, 0.003565040184184909f, 0.005057231057435274f, 0.006367780268192291f, 0.005226158536970615f, 0.0018044126918539405f, 0.005949866026639938f, 0.004910432267934084f, 0.0026581089477986097f, 0.004516463726758957f, 0.00603885855525732f, 0.0037233096081763506f, 0.005230995826423168f, 0.005408903118222952f, 0.002575879218056798f, 0.0025459090247750282f, 0.006581172347068787f, 0.004278930835425854f, 0.0055853757075965405f, 0.0035550864413380623f, 0.003986450377851725f, 0.004394446965306997f, 0.0031657994259148836f, 0.0022170848678797483f, 0.0035492312163114548f, 0.004178149159997702f, 0.00456454511731863f, 0.004653145093470812f, 0.002799605717882514f, 0.005982205271720886f, 0.0037832113448530436f, 0.005278708413243294f, 0.00497553450986743f, 0.003997192718088627f, 0.002704822923988104f, 0.003485301276668906f, 0.0035568445455282927f, 0.005490637384355068f, 0.0022080312483012676f, 0.005447688978165388f, 0.0027553378604352474f, 0.004064467269927263f, 0.007070546504110098f, 0.005796934012323618f, 0.005282799247652292f, 0.003939660266041756f, 0.006877190433442593f, 0.007609374821186066f, 0.00458519859239459f, 0.003958749584853649f, 0.004205511417239904f, 0.0032176338136196136f, 0.0046674953773617744f, 0.004302313085645437f, 0.003316274844110012f, 0.005796187557280064f, 0.006121799349784851f, 0.004162074998021126f, 0.004304991569370031f, 0.001682663569226861f, 0.002282769186422229f, 0.006524393334984779f, 0.0061553241685032845f, 0.003055906854569912f, 0.004598713479936123f, 0.0055746715515851974f, 0.003909089602530003f, 0.004700998309999704f, 0.004975238814949989f, 0.003800296690315008f, 0.005526801571249962f, 0.005057735834270716f, 0.0024294257164001465f, 0.004502783063799143f, 0.0031977402977645397f, 0.004256733693182468f, 0.004438144154846668f, 0.00301182153634727f, 0.004923816304653883f, 0.003285988001152873f, 0.002459344221279025f, 0.004615515936166048f, 0.0026306379586458206f, 0.0031617027707397938f, 0.003403307870030403f, 0.0038501787930727005f, 0.002680955920368433f, 0.0033043944276869297f, 0.006883312948048115f, 0.0042607346549630165f, 0.006623898167163134f, 0.004177474416792393f, 0.004200772847980261f, 0.004677496384829283f, 0.004325640853494406f, 0.005212373100221157f, 0.003942255396395922f, 0.0048080445267260075f, 0.0025766887702047825f, 0.0024458877742290497f, 0.006772426888346672f, 0.002428667852655053f, 0.0035877772606909275f, 0.0024100197479128838f, 0.0025519386399537325f, 0.003891038242727518f, 0.0023864901158958673f, 0.005907417740672827f, 0.0038133657071739435f, 0.009106242097914219f, 0.004252016544342041f, 0.004678446799516678f, 0.0038370199035853148f, 0.004881618544459343f, 0.00405421108007431f, 0.0040916032157838345f, 0.0111374007537961f, 0.003552887123078108f, 0.0034982911311089993f, 0.005068909376859665f, 0.0053169019520282745f, 0.0059785619378089905f, 0.003508134977892041f, 0.0046171811409294605f, 0.006955884397029877f, 0.00230309646576643f, 0.004287064541131258f, 0.0033074333332479f, 0.004417730029672384f, 0.005528740584850311f, 0.00434800935909152f, 0.005196909885853529f, 0.0044554066844284534f, 0.0022807985078543425f, 0.004327484406530857f, 0.004617904778569937f, 0.0038224116433411837f, 0.0036609165836125612f, 0.0027214838191866875f, 0.0030328838620334864f, 0.004453353583812714f, 0.005692996084690094f, 0.005361975636333227f, 0.0037250069435685873f, 0.005731719546020031f, 0.005036912392824888f, 0.00559117691591382f, 0.00796284805983305f, 0.004324917681515217f, 0.004602448083460331f, 0.004843942821025848f, 0.004163730423897505f, 0.003978013526648283f, 0.0036294772289693356f, 0.012953465804457664f, 0.0020756935700774193f, 0.004439596552401781f, 0.005450421944260597f, 0.004445825237780809f, 0.0041140904650092125f, 0.006975745782256126f, 0.003756680991500616f, 0.006450754124671221f, 0.0037117344327270985f, 0.005529663525521755f, 0.0020452069584280252f, 0.004133058711886406f, 0.0032451197039335966f, 0.00495003629475832f, 0.003195772645995021f, 0.0047097234055399895f, 0.0050827921368181705f, 0.0025306642055511475f, 0.0018099579028785229f, 0.005530160386115313f, 0.005387332756072283f, 0.00423087552189827f, 0.0025703832507133484f, 0.003149328986182809f, 0.004499286878854036f, 0.006192033179104328f, 0.00451452424749732f, 0.00422861659899354f, 0.002397095551714301f, 0.002362975850701332f, 0.00640035979449749f, 0.006206464022397995f, 0.0059488750994205475f, 0.004185473080724478f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #166 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_65_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00016532484733033925f, 8.553771476726979e-05f, 0.00010230959742330015f, 0.00018957910651806742f, 7.490798452636227e-05f, 6.490274972748011e-05f, 8.894686470739543e-05f, 0.0001818035962060094f, 0.00011690230894600973f, 0.00013233409845270216f, 9.817010868573561e-05f, 7.368601654889062e-05f, 0.00011516673839651048f, 5.161607259651646e-05f, 0.0015123665798455477f, 9.536244033370167e-05f, 0.00011439713853178546f, 0.00012882794544566423f, 8.29102355055511e-05f, 8.926444570533931e-05f, 0.00011615348921623081f, 7.513965101679787e-05f, 0.00010310515790479258f, 0.0002685182844288647f, 5.416169369709678e-05f, 0.00013161198876332492f, 0.00012630813580472022f, 4.994874689145945e-05f, 0.00011987084872089326f, 9.268093708669767e-05f, 8.153083035722375e-05f, 0.0001383205089950934f, 8.091292693279684e-05f, 0.00010185351129621267f, 8.993493247544393e-05f, 0.00015654636081308126f, 9.234216122422367e-05f, 5.741981294704601e-05f, 7.956716581247747e-05f, 8.616701234132051e-05f, 9.624673111829907e-05f, 0.0002459977404214442f, 0.00014024772099219263f, 6.630729330936447e-05f, 0.00010160475358134136f, 0.00013055930321570486f, 9.633808804210275e-05f, 0.0001219359619426541f, 0.00012804077414330095f, 0.00015903000894468278f, 0.0005577371921390295f, 0.00010108702554134652f, 0.00013131856394466013f, 4.217477544443682e-05f, 8.135620009852573e-05f, 7.533185998909175e-05f, 7.492535223718733e-05f, 0.0001582676632096991f, 7.062451913952827e-05f, 0.00010118212958332151f, 8.621238521300256e-05f, 0.00015138890012167394f, 0.00011485360300866887f, 0.00010986705456161872f, 8.360351057490334e-05f, 0.00010379884770372882f, 0.00013391538232099265f, 0.0003856326802633703f, 6.218624184839427e-05f, 0.00010001364717027172f, 9.399255941389129e-05f, 0.00011030564201064408f, 0.00010162605030927807f, 0.00010243553697364405f, 4.831244586966932e-05f, 0.00023765700461808592f, 0.00011089645704487339f, 0.0001092905513360165f, 0.00020457382197491825f, 0.00011410596925998107f, 6.233701424207538e-05f, 8.835760672809556e-05f, 0.00016051888815127313f, 8.125884050969034e-05f, 0.00010031834244728088f, 7.193155761342496e-05f, 9.078014409169555e-05f, 7.434582948917523e-05f, 0.00018684456881601363f, 4.62137431895826e-05f, 0.0002101229183608666f, 0.00012638396583497524f, 0.00013516267063096166f, 6.881365698063746e-05f, 0.000182436328032054f, 0.00015089951921254396f, 0.00013433312415145338f, 6.107405351940542e-05f, 6.566007505171001e-05f, 7.968411227921024e-05f, 0.0001024863013299182f, 9.736078936839476e-05f, 7.419592293445021e-05f, 0.00011264159547863528f, 0.00014711765106767416f, 9.578211029293016e-05f, 0.00010545759869273752f, 8.611557132098824e-05f, 8.985511522041634e-05f, 7.226339221233502e-05f, 0.0001601927069714293f, 6.631046562688425e-05f, 0.00014830594591330737f, 0.0001023769800667651f, 0.0001126504794228822f, 5.1990260544698685e-05f, 8.080972474999726e-05f, 0.0001209942638524808f, 8.671489194966853e-05f, 9.76486480794847e-05f, 0.00011812464072136208f, 0.00010747058695415035f, 9.414956730324775e-05f, 4.272428486729041e-05f, 8.253550913650542e-05f, 5.8154873840976506e-05f, 7.471489516319707e-05f, 5.44644208275713e-05f, 9.854570816969499e-05f, 0.0001184372667921707f, 3.86581668863073e-05f, 0.00015580080798827112f, 0.00016692103235982358f, 7.634725625393912e-05f, 0.00042009030585177243f, 5.084449003334157e-05f, 9.52924820012413e-05f, 0.00010583919356577098f, 5.590772343566641e-05f, 0.00012069270451320335f, 0.00011364556849002838f, 5.489736213348806e-05f, 4.005187292932533e-05f, 8.81386295077391e-05f, 9.390542254550382e-05f, 0.000111122484668158f, 5.663993215421215e-05f, 0.00014854960318189114f, 8.388330024899915e-05f, 0.00011899367382284254f, 0.00014983012806624174f, 0.00012296844215597957f, 4.2456769733689725e-05f, 0.00013999684597365558f, 0.0001155395875684917f, 6.254373874980956e-05f, 0.00010626973380567506f, 0.00014209079381544143f, 8.760728815104812e-05f, 0.00012308225268498063f, 0.00012726831482723355f, 6.060892337700352e-05f, 5.990374120301567e-05f, 0.00015485112089663744f, 0.0001006807287922129f, 0.00013142060197424144f, 8.36490944493562e-05f, 9.379883704241365e-05f, 0.0001033987573464401f, 7.44893986848183e-05f, 5.2166702516842633e-05f, 8.351132419193164e-05f, 9.830939234234393e-05f, 0.00010740106517914683f, 0.00010948577255476266f, 6.587307871086523e-05f, 0.0001407577801728621f, 8.901673572836444e-05f, 0.00012420490384101868f, 0.00011707140220096335f, 9.405159653397277e-05f, 6.364289583871141e-05f, 8.200709271477535e-05f, 8.369045826839283e-05f, 0.00012919146683998406f, 5.195367702981457e-05f, 0.00012818092363886535f, 6.483148172264919e-05f, 9.563452476868406e-05f, 0.00016636580403428525f, 0.00013639844837598503f, 0.00012430116476025432f, 9.269789006793872e-05f, 0.00016181624960154295f, 0.00017904411652125418f, 0.00010788702638819814f, 9.314704948337749e-05f, 9.895321272779256e-05f, 7.57090310798958e-05f, 0.00010982342064380646f, 0.00010123090032720938f, 7.802999607520178e-05f, 0.0001363808842143044f, 0.00014404233661480248f, 9.793118078960106e-05f, 0.00010129392467206344f, 3.9592083339812234e-05f, 5.371221777750179e-05f, 0.00015351513866335154f, 0.0001448311668355018f, 7.190369069576263e-05f, 0.00010820502211572602f, 0.0001311687519773841f, 9.197858162224293e-05f, 0.00011061172699555755f, 0.00011706444638548419f, 8.94187469384633e-05f, 0.0001300423900829628f, 0.00011900554818566889f, 5.7162960729328915e-05f, 0.00010594783816486597f, 7.524094689870253e-05f, 0.00010015843872679397f, 0.00010442692291690037f, 7.086639379849657e-05f, 0.00011585450556594878f, 7.731736695859581e-05f, 5.786692418041639e-05f, 0.00010860037582460791f, 6.189736450323835e-05f, 7.43930067983456e-05f, 8.007783617358655e-05f, 9.059244621312246e-05f, 6.308131560217589e-05f, 7.775046105962247e-05f, 0.00016196031356230378f, 0.0001002525823423639f, 0.00015585642540827394f, 9.829351620282978e-05f, 9.884171595331281e-05f, 0.00011005873966496438f, 0.00010177978401770815f, 0.00012264407996553928f, 9.275894990423694e-05f, 0.00011313045979477465f, 6.062797183403745e-05f, 5.755029997089878e-05f, 0.00015935122792143375f, 5.714512735721655e-05f, 8.441828686045483e-05f, 5.670634709531441e-05f, 6.004561510053463e-05f, 9.155384032055736e-05f, 5.6152708566514775e-05f, 0.0001389980607200414f, 8.972625073511153e-05f, 0.00021426452440209687f, 0.00010004745126934722f, 0.00011008110595867038f, 9.02828251128085e-05f, 0.00011486161383800209f, 9.539320308249444e-05f, 9.627301915315911e-05f, 0.0002620565064717084f, 8.359734783880413e-05f, 8.231273386627436e-05f, 0.00011926845763809979f, 0.0001251035719178617f, 0.0001406720548402518f, 8.254435670096427e-05f, 0.00010863955685636029f, 0.0001636678643990308f, 5.4190506489248946e-05f, 0.00010087210830533877f, 7.782196189509705e-05f, 0.00010394659329904243f, 0.00013008801033720374f, 0.00010230610496364534f, 0.00012228023842908442f, 0.00010483310325071216f, 5.36658480996266e-05f, 0.00010182316327700391f, 0.00010865658259717748f, 8.993910159915686e-05f, 8.613921818323433e-05f, 6.4034917159006e-05f, 7.136197382351384e-05f, 0.00010478479089215398f, 0.0001339528535027057f, 0.0001261641300516203f, 8.764722588239238e-05f, 0.00013486399257089943f, 0.00011851558519992977f, 0.00013155711349099874f, 0.0001873611327027902f, 0.00010176277282880619f, 0.00010829290113179013f, 0.0001139751257142052f, 9.797012899070978e-05f, 9.360031981486827e-05f, 8.539946429664269e-05f, 0.0003047874488402158f, 4.883985093329102e-05f, 0.00010446109808981419f, 0.0001282452285522595f, 0.00010460765770403668f, 9.680213406682014e-05f, 0.0001641351991565898f, 8.839249494485557e-05f, 0.00015178245666902512f, 8.73349272296764e-05f, 0.0001301097363466397f, 4.812251791008748e-05f, 9.724844130687416e-05f, 7.63557618483901e-05f, 0.00011647144128801301f, 7.519464998040348e-05f, 0.00011081702541559935f, 0.00011959511175518855f, 5.9545040130615234e-05f, 4.258724584360607e-05f, 0.00013012142153456807f, 0.00012676077312789857f, 9.955001587513834e-05f, 6.047960778232664e-05f, 7.410185935441405e-05f, 0.00010586557618808001f, 0.0001456948957638815f, 0.0001062240989995189f, 9.949686500476673e-05f, 5.640224844682962e-05f, 5.5599433835595846e-05f, 0.00015059670840855688f, 0.00014603445015382022f, 0.00013997353380545974f, 9.848172339843586e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #167 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_66_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 112,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0051702396012842655f, 0.003933511674404144f, 0.00677636219188571f, 0.007912359200417995f, 0.007383091375231743f, 0.0062961033545434475f, 0.0041075036861002445f, 0.00458610150963068f, 0.004398425109684467f, 0.0063946242444217205f, 0.003803582163527608f, 0.006647830363363028f, 0.005358477123081684f, 0.00557493744418025f, 0.004056704230606556f, 0.0032515048515051603f, 0.0045471033081412315f, 0.006316398270428181f, 0.006214596796780825f, 0.005046133417636156f, 0.004489897284656763f, 0.0038450914435088634f, 0.005561631638556719f, 0.004232609178870916f, 0.006142400670796633f, 0.004175421316176653f, 0.005545170046389103f, 0.004456901457160711f, 0.0038304426707327366f, 0.007476408965885639f, 0.006905671674758196f, 0.004357399884611368f, 0.004407310858368874f, 0.004731259774416685f, 0.006068896967917681f, 0.006464445497840643f, 0.005846076179295778f, 0.006531501654535532f, 0.003145240480080247f, 0.00597647437825799f, 0.005938253365457058f, 0.004549773875623941f, 0.0057222372852265835f, 0.0038655553944408894f, 0.005639680195599794f, 0.005893393885344267f, 0.005410644691437483f, 0.004650223534554243f, 0.005786540452390909f, 0.0056258030235767365f, 0.004007744137197733f, 0.0064424676820635796f, 0.003833305323496461f, 0.006970121990889311f, 0.006646772846579552f, 0.00771242706105113f, 0.005093471147119999f, 0.005755057092756033f, 0.005167159717530012f, 0.005395140964537859f, 0.006677234545350075f, 0.00526269618421793f, 0.003828224493190646f, 0.004740943666547537f, 0.006213617976754904f, 0.0075869993306696415f, 0.005445805378258228f, 0.006510192062705755f, 0.005512433126568794f, 0.005922163370996714f, 0.005875071045011282f, 0.005139862187206745f, 0.006534202490001917f, 0.005981749389320612f, 0.0038464840035885572f, 0.0050046308897435665f, 0.004425148479640484f, 0.005022104829549789f, 0.0065232086926698685f, 0.00555387744680047f, 0.006832383573055267f, 0.006475015077739954f, 0.004725515376776457f, 0.0049006883054971695f, 0.006334465928375721f, 0.004047265741974115f, 0.0035896101035177708f, 0.00591857498511672f, 0.004558531567454338f, 0.005309073254466057f, 0.006017567124217749f, 0.006089219357818365f, 0.0038427147082984447f, 0.00513308122754097f, 0.0058120680041611195f, 0.004907998722046614f, 0.0032660828437656164f, 0.006738620810210705f, 0.004471802618354559f, 0.004527008160948753f, 0.005991404876112938f, 0.005259570199996233f, 0.005875489208847284f, 0.0032369818072766066f, 0.004783761687576771f, 0.00597674073651433f, 0.005063795018941164f, 0.005210614297538996f, 0.0038403228390961885f, 0.005555823910981417f, 0.006063422188162804f, 0.004106470383703709f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #168 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_66_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 112,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00012165270163677633f, 9.255321492673829e-05f, 0.00015944382175803185f, 0.00018617315799929202f, 0.0001737198035698384f, 0.0001481436047470197f, 9.664714889368042e-05f, 0.00010790827218443155f, 0.00010349235526518896f, 0.000150461753946729f, 8.9496053988114e-05f, 0.00015641954087186605f, 0.00012608180986717343f, 0.00013117499474901706f, 9.54518691287376e-05f, 7.650599582120776e-05f, 0.00010699066478991881f, 0.0001486211403971538f, 0.00014622580783907324f, 0.00011873255425598472f, 0.00010564464173512533f, 9.047274215845391e-05f, 0.00013086192484479398f, 9.959080489352345e-05f, 0.0001445270754629746f, 9.824521112022921e-05f, 0.00013047459651716053f, 0.00010486827522981912f, 9.012806549435481e-05f, 0.00017591551295481622f, 0.0001624863944016397f, 0.00010252706124447286f, 0.00010370143718319014f, 0.00011132375948363915f, 0.0001427975803380832f, 0.0001521046069683507f, 0.00013755474356003106f, 0.00015368239837698638f, 7.400565664283931e-05f, 0.00014062292757444084f, 0.00013972360466141254f, 0.00010705350723583251f, 0.0001346408826066181f, 9.095424320548773e-05f, 0.00013269836199469864f, 0.00013866809604223818f, 0.00012730929302051663f, 0.00010941702930722386f, 0.0001361538888886571f, 0.00013237183156888932f, 9.429986675968394e-05f, 0.00015158747555688024f, 9.019541903398931e-05f, 0.00016400287859141827f, 0.00015639465709682554f, 0.0001814688730519265f, 0.00011984637967543676f, 0.00013541310909204185f, 0.00012158023309893906f, 0.0001269444910576567f, 0.00015711139712948352f, 0.00012382815475575626f, 9.007587505038828e-05f, 0.00011155162064824253f, 0.00014620277215726674f, 0.00017851762822829187f, 0.00012813659850507975f, 0.00015318099758587778f, 0.00012970430543646216f, 0.00013934502203483135f, 0.00013823696644976735f, 0.00012093793338863179f, 0.00015374594659078866f, 0.00014074704085942358f, 9.050550579559058e-05f, 0.00011775602615671232f, 0.0001041211435222067f, 0.0001181671759695746f, 0.0001534872717456892f, 0.0001306794729316607f, 0.00016076196334324777f, 0.0001523532991996035f, 0.00011118860129499808f, 0.00011531031486811116f, 0.0001490462600486353f, 9.522978507447988e-05f, 8.446141873719171e-05f, 0.00013926059182267636f, 0.0001072595696314238f, 0.00012491937377490103f, 0.00014158981502987444f, 0.00014327575627248734f, 9.04168191482313e-05f, 0.00012077838619006798f, 0.0001367545482935384f, 0.00011548232578206807f, 7.684900629101321e-05f, 0.00015855579113122076f, 0.00010521888907533139f, 0.00010651784396031871f, 0.00014097423991188407f, 0.00012375459482427686f, 0.00013824680354446173f, 7.616428047185764e-05f, 0.00011255910067120567f, 0.00014062919944990426f, 0.00011914812057511881f, 0.0001226026943186298f, 9.036053961608559e-05f, 0.00013072526780888438f, 0.0001426687667844817f, 9.662283264333382e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #169 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_67_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1280,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0029621743597090244f, 0.0033644703216850758f, 0.0049153524450957775f, 0.003292774548754096f, 0.0039006154984235764f, 0.004424807149916887f, 0.0034887518268078566f, 0.0034346424508839846f, 0.0041217198595404625f, 0.0035716199781745672f, 0.004293471109122038f, 0.003848699387162924f, 0.0034123845398426056f, 0.0036328909918665886f, 0.0048905243165791035f, 0.005025461781769991f, 0.00393777946010232f, 0.003102334914728999f, 0.0032731476239860058f, 0.003895457601174712f, 0.0036590408999472857f, 0.0038306897040456533f, 0.0036488708574324846f, 0.004305759444832802f, 0.0039032879285514355f, 0.003702098038047552f, 0.0038373738061636686f, 0.0033054640516638756f, 0.004221534356474876f, 0.0032322590705007315f, 0.0032622949220240116f, 0.003234345465898514f, 0.0043456945568323135f, 0.0031989668495953083f, 0.0036099764984101057f, 0.0040717413648962975f, 0.0031526193488389254f, 0.0033254511654376984f, 0.004248072858899832f, 0.002717989729717374f, 0.003532933536916971f, 0.0033612586557865143f, 0.0033168538939207792f, 0.004583351779729128f, 0.00375380739569664f, 0.003646325320005417f, 0.0033430755138397217f, 0.003338437993079424f, 0.00485564349219203f, 0.0035840366035699844f, 0.004379378631711006f, 0.004795353394001722f, 0.003416685853153467f, 0.003651074366644025f, 0.004123816732317209f, 0.0044944193214178085f, 0.005938307382166386f, 0.0044990223832428455f, 0.004957282915711403f, 0.003938966430723667f, 0.005099035333842039f, 0.003849896602332592f, 0.0031181268859654665f, 0.0032906183041632175f, 0.0036717732436954975f, 0.005371137987822294f, 0.004111108835786581f, 0.003390368539839983f, 0.0034574829041957855f, 0.0032442992087453604f, 0.005248322617262602f, 0.003320713760331273f, 0.0047577545046806335f, 0.0037853147368878126f, 0.0036603733897209167f, 0.004052985459566116f, 0.0034788409247994423f, 0.0037654771003872156f, 0.0035777667071670294f, 0.003221282036975026f, 0.004163912031799555f, 0.004439814016222954f, 0.0028503912035375834f, 0.0036186897195875645f, 0.004053816664963961f, 0.004163426347076893f, 0.004628990311175585f, 0.0036114307586103678f, 0.004538137931376696f, 0.0034262577537447214f, 0.0034706906881183386f, 0.004572177305817604f, 0.003930628765374422f, 0.0034403798636049032f, 0.004216828383505344f, 0.004287114366889f, 0.003045364050194621f, 0.002938083605840802f, 0.00401325523853302f, 0.003341569099575281f, 0.004316762089729309f, 0.0037072384729981422f, 0.0034710955806076527f, 0.003110656049102545f, 0.004544608294963837f, 0.0031723687425255775f, 0.004046203568577766f, 0.005045577883720398f, 0.004894716665148735f, 0.003499529790133238f, 0.003774539800360799f, 0.003427438670769334f, 0.003892133943736553f, 0.0035728097427636385f, 0.004251927603036165f, 0.00433994410559535f, 0.003647909965366125f, 0.0033451172057539225f, 0.0036913298536092043f, 0.003138078609481454f, 0.0027960767038166523f, 0.0038398378528654575f, 0.005039792507886887f, 0.004316587932407856f, 0.004293434787541628f, 0.003208696376532316f, 0.004374955780804157f, 0.004422201309353113f, 0.003224818268790841f, 0.00390715803951025f, 0.003477038349956274f, 0.002922841813415289f, 0.0035453643649816513f, 0.003880483331158757f, 0.003936633002012968f, 0.003302880795672536f, 0.004205590113997459f, 0.0035609877668321133f, 0.00409786868840456f, 0.00515262596309185f, 0.0027498393319547176f, 0.004421652760356665f, 0.003410582197830081f, 0.0035203061997890472f, 0.0032483094837516546f, 0.0033308682031929493f, 0.0029898423235863447f, 0.004326171241700649f, 0.0034060287289321423f, 0.004507994279265404f, 0.0052445512264966965f, 0.004290164913982153f, 0.003649138379842043f, 0.0035159692633897066f, 0.0038118178490549326f, 0.004307774361222982f, 0.00383915682323277f, 0.003390311961993575f, 0.003095457097515464f, 0.006119788624346256f, 0.0033421425614506006f, 0.004260276444256306f, 0.0036841370165348053f, 0.0033493991941213608f, 0.0031952124554663897f, 0.003786775516346097f, 0.00400565518066287f, 0.0027008422184735537f, 0.003619050607085228f, 0.0033197817392647266f, 0.004175545647740364f, 0.0033442035783082247f, 0.003935686778277159f, 0.003371675731614232f, 0.004278067499399185f, 0.0033198276069015265f, 0.00410841079428792f, 0.0036911156494170427f, 0.004427166655659676f, 0.004071194678544998f, 0.0041862186044454575f, 0.003799168858677149f, 0.004343350883573294f, 0.003289214801043272f, 0.004136508796364069f, 0.003958591725677252f, 0.004303037654608488f, 0.0031933810096234083f, 0.003676677355542779f, 0.0031038864981383085f, 0.004584965296089649f, 0.004086195956915617f, 0.0030248654074966908f, 0.003578494768589735f, 0.00400870805606246f, 0.004072778392583132f, 0.003423432819545269f, 0.0040171267464756966f, 0.0034773279912769794f, 0.004585679620504379f, 0.0035897057969123125f, 0.003431397955864668f, 0.003146434435620904f, 0.0029587838798761368f, 0.00477429386228323f, 0.004196573980152607f, 0.003918379079550505f, 0.0035362110938876867f, 0.003449812764301896f, 0.0038263655733317137f, 0.0033096580300480127f, 0.003911591600626707f, 0.003494484815746546f, 0.004628441762179136f, 0.003941776230931282f, 0.0038159871473908424f, 0.003246939042583108f, 0.0040299599058926105f, 0.003305799560621381f, 0.004657807294279337f, 0.003644191659986973f, 0.003181806765496731f, 0.0030362792313098907f, 0.0035908606369048357f, 0.0042848060838878155f, 0.00393308699131012f, 0.004263146314769983f, 0.005063691642135382f, 0.0036539132706820965f, 0.00630768109112978f, 0.0036029089242219925f, 0.003445018781349063f, 0.003987973555922508f, 0.003754357108846307f, 0.003475191770121455f, 0.004207054618746042f, 0.00454884534701705f, 0.004790265113115311f, 0.005521836224943399f, 0.0038377537857741117f, 0.00419484032317996f, 0.004195132292807102f, 0.004448089748620987f, 0.00633424473926425f, 0.003203409258276224f, 0.0030828998424112797f, 0.0038549788296222687f, 0.0032303251791745424f, 0.0037528942339122295f, 0.004231833852827549f, 0.004594755824655294f, 0.0044718231074512005f, 0.0039125001057982445f, 0.003879116615280509f, 0.004584516864269972f, 0.003646549768745899f, 0.004184157121926546f, 0.0036161956377327442f, 0.0032765676733106375f, 0.004271447192877531f, 0.0042388904839754105f, 0.003505409462377429f, 0.0035445503890514374f, 0.003352345898747444f, 0.004001224879175425f, 0.0038233718369156122f, 0.004652536939829588f, 0.003743969602510333f, 0.004537845496088266f, 0.0041128601878881454f, 0.003538229037076235f, 0.004026023205369711f, 0.0033502401784062386f, 0.004091943614184856f, 0.003830581670626998f, 0.003431562567129731f, 0.006354890298098326f, 0.0038771696854382753f, 0.003176695667207241f, 0.006071372888982296f, 0.004741188138723373f, 0.0035231581423431635f, 0.0031935949809849262f, 0.003838670440018177f, 0.003979407250881195f, 0.004884691443294287f, 0.003888314589858055f, 0.003666393691673875f, 0.0034294200595468283f, 0.003630507504567504f, 0.005184346344321966f, 0.004384122788906097f, 0.0031753932125866413f, 0.003234469797462225f, 0.003810434602200985f, 0.0038565322756767273f, 0.0044325548224151134f, 0.005660794209688902f, 0.004007241223007441f, 0.0034891427494585514f, 0.003919596318155527f, 0.0037625269033014774f, 0.0032248455099761486f, 0.0034492583945393562f, 0.0030559138394892216f, 0.004196771886199713f, 0.0031696604564785957f, 0.0030325460247695446f, 0.0032967571169137955f, 0.004571749363094568f, 0.004812916275113821f, 0.0037127716932445765f, 0.003925019409507513f, 0.004623056389391422f, 0.003556301584467292f, 0.004301831591874361f, 0.0039612106047570705f, 0.004419439472258091f, 0.00391819141805172f, 0.0037713053170591593f, 0.004642801824957132f, 0.00438147597014904f, 0.004088780842721462f, 0.0034643267281353474f, 0.003346133977174759f, 0.0036364933475852013f, 0.0034638133365660906f, 0.00327310967259109f, 0.003134253667667508f, 0.00333037949167192f, 0.0030644931830465794f, 0.003174717305228114f, 0.005083031021058559f, 0.0034763580188155174f, 0.0040988498367369175f, 0.0035751487594097853f, 0.004742742981761694f, 0.004511798731982708f, 0.0035490624140948057f, 0.0038101691752672195f, 0.00406529288738966f, 0.003094490384683013f, 0.003443113761022687f, 0.003168839029967785f, 0.0036394898779690266f, 0.0037023858167231083f, 0.003490738570690155f, 0.0036068614572286606f, 0.003930498845875263f, 0.0032765199430286884f, 0.0047698840498924255f, 0.004658773075789213f, 0.005383722484111786f, 0.004109837580472231f, 0.005526265129446983f, 0.003496570745483041f, 0.0032788091339170933f, 0.003133246907964349f, 0.004803256597369909f, 0.00329365162178874f, 0.003571938956156373f, 0.004280454479157925f, 0.00372205744497478f, 0.0032016735058277845f, 0.0037282356061041355f, 0.0042003183625638485f, 0.003306593047454953f, 0.0032957373186945915f, 0.004800454247742891f, 0.003335255663841963f, 0.004352609161287546f, 0.0032475918997079134f, 0.0034948475658893585f, 0.004117960575968027f, 0.0038880847860127687f, 0.005015515256673098f, 0.003927293699234724f, 0.004906861111521721f, 0.002877302933484316f, 0.003215562319383025f, 0.004144994542002678f, 0.003147804643958807f, 0.003283244324848056f, 0.004246704280376434f, 0.00335312751121819f, 0.004042781889438629f, 0.0038578903768211603f, 0.004407871048897505f, 0.004800190683454275f, 0.003433633828535676f, 0.003342418698593974f, 0.0041420478373765945f, 0.0031723130960017443f, 0.004348712041974068f, 0.004520172718912363f, 0.0038391591515392065f, 0.0038421638309955597f, 0.003500158665701747f, 0.004192360211163759f, 0.0037458851002156734f, 0.0033213256392627954f, 0.003410576144233346f, 0.00416570482775569f, 0.0034403603058308363f, 0.0036236036103218794f, 0.0038853243459016085f, 0.004353207070380449f, 0.00396908400580287f, 0.006485541816800833f, 0.004381355829536915f, 0.004019616171717644f, 0.004383882973343134f, 0.003332157852128148f, 0.0038412604480981827f, 0.0035134360659867525f, 0.00473377900198102f, 0.004256685730069876f, 0.004033641889691353f, 0.004690112080425024f, 0.0034506202209740877f, 0.004171110223978758f, 0.004795975983142853f, 0.004205739591270685f, 0.0034325227607041597f, 0.003227162640541792f, 0.003925823140889406f, 0.00332421762868762f, 0.003914021886885166f, 0.003951767459511757f, 0.003582450794056058f, 0.0035022131633013487f, 0.004267056938260794f, 0.0037143072113394737f, 0.004206966143101454f, 0.003702020039781928f, 0.0035629388876259327f, 0.0036350504960864782f, 0.0041279555298388f, 0.0037537405733019114f, 0.0036773751489818096f, 0.003952719271183014f, 0.0033756510820239782f, 0.0048948414623737335f, 0.003222063882276416f, 0.004089790396392345f, 0.003362115705385804f, 0.003610436338931322f, 0.00388729409314692f, 0.00531136617064476f, 0.004615883342921734f, 0.0031316163949668407f, 0.0043176510371267796f, 0.005071339663118124f, 0.0035983577836304903f, 0.0037777347024530172f, 0.0039926921017467976f, 0.003786012064665556f, 0.0031095268204808235f, 0.003410974284633994f, 0.00290185259655118f, 0.0066179269924759865f, 0.0049520572647452354f, 0.0029818916227668524f, 0.0032399462070316076f, 0.004219433758407831f, 0.0035106795839965343f, 0.0034611383453011513f, 0.0041664717718958855f, 0.004967675544321537f, 0.003332019317895174f, 0.0036424859426915646f, 0.004190773703157902f, 0.0031857311259955168f, 0.0033744312822818756f, 0.0034841797314584255f, 0.004697736352682114f, 0.0032495942432433367f, 0.004388927482068539f, 0.004178712144494057f, 0.004058487247675657f, 0.004560193978250027f, 0.003754423698410392f, 0.002611876465380192f, 0.004303581081330776f, 0.0052032750099897385f, 0.0033818844240158796f, 0.004607797134667635f, 0.004298161715269089f, 0.0030431870836764574f, 0.003433962818235159f, 0.0033718817867338657f, 0.004272162914276123f, 0.0034826400224119425f, 0.00353202479891479f, 0.004304851870983839f, 0.0035449028946459293f, 0.0043202973902225494f, 0.004805420525372028f, 0.003576156683266163f, 0.003997931722551584f, 0.003388427197933197f, 0.005083013325929642f, 0.0034545923117548227f, 0.003727123374119401f, 0.0035533630289137363f, 0.004298783373087645f, 0.004713017959147692f, 0.00373062607832253f, 0.0035124062560498714f, 0.00281945476308465f, 0.0032879291102290154f, 0.003462927881628275f, 0.0032281852327287197f, 0.0045919413678348064f, 0.0033374351914972067f, 0.004353893455117941f, 0.004066035617142916f, 0.0044847289100289345f, 0.004393632523715496f, 0.003506285371258855f, 0.0033648458775132895f, 0.004113912116736174f, 0.005349946673959494f, 0.0041417526081204414f, 0.003848234424367547f, 0.003397733438760042f, 0.004679028410464525f, 0.004853780381381512f, 0.0046649519354105f, 0.0032742787152528763f, 0.006365726701915264f, 0.003535504685714841f, 0.0036333107855170965f, 0.003002334851771593f, 0.004154188092797995f, 0.00448373518884182f, 0.0036109385546296835f, 0.0033877005334943533f, 0.0038082946557551622f, 0.0032024437095969915f, 0.0037793503142893314f, 0.00530313840135932f, 0.0047793942503631115f, 0.0031299875117838383f, 0.003210383001714945f, 0.003936838358640671f, 0.0042728399857878685f, 0.0037714773789048195f, 0.00294130714610219f, 0.004011011682450771f, 0.005140672437846661f, 0.006333069410175085f, 0.00379301980137825f, 0.003450100077316165f, 0.0038420299533754587f, 0.0032766994554549456f, 0.003919941373169422f, 0.003880188101902604f, 0.004928578622639179f, 0.0036757735069841146f, 0.004200443159788847f, 0.00394864659756422f, 0.004022696055471897f, 0.0035731950774788857f, 0.004084239713847637f, 0.0036705038510262966f, 0.003865630365908146f, 0.004764966666698456f, 0.003472303505986929f, 0.0031003281474113464f, 0.004549398086965084f, 0.004818454850465059f, 0.004989089909940958f, 0.0034518444444984198f, 0.004079070873558521f, 0.0035510207526385784f, 0.003354366635903716f, 0.0033248907420784235f, 0.003467963309958577f, 0.0029625638853758574f, 0.003761970903724432f, 0.004135383293032646f, 0.003659704001620412f, 0.004776648711413145f, 0.005870512221008539f, 0.00465012714266777f, 0.00322336726821959f, 0.004082805477082729f, 0.0051069194450974464f, 0.0037863198667764664f, 0.0037340752314776182f, 0.004183941055089235f, 0.004042982589453459f, 0.004448819439858198f, 0.0044803014025092125f, 0.003756837220862508f, 0.0035036804620176554f, 0.0031629009172320366f, 0.002847203053534031f, 0.003151366952806711f, 0.0037002863828092813f, 0.003421926172450185f, 0.005089926067739725f, 0.003592798486351967f, 0.00421297037974f, 0.003974914085119963f, 0.003584706224501133f, 0.004571598023176193f, 0.003927632700651884f, 0.0032710356172174215f, 0.005061660427600145f, 0.004301175940781832f, 0.00320749101229012f, 0.00376138836145401f, 0.0034555334132164717f, 0.00400529382750392f, 0.004653532989323139f, 0.004386376589536667f, 0.004143550992012024f, 0.003762919921427965f, 0.004184543155133724f, 0.004391332156956196f, 0.004077984020113945f, 0.003265638602897525f, 0.005854274611920118f, 0.004045072477310896f, 0.003897598944604397f, 0.0029065634589642286f, 0.004519837908446789f, 0.003582653822377324f, 0.004148488398641348f, 0.003747234819456935f, 0.0038128106389194727f, 0.003723974572494626f, 0.004262762609869242f, 0.0038555837236344814f, 0.004367745481431484f, 0.003120989305898547f, 0.003983011469244957f, 0.0034893120173364878f, 0.005846032407134771f, 0.0039939284324646f, 0.0039042325224727392f, 0.003287811763584614f, 0.004331226926296949f, 0.004535997286438942f, 0.0038230870850384235f, 0.0032234268728643656f, 0.002940013073384762f, 0.004420932848006487f, 0.0033648849930614233f, 0.003510913113132119f, 0.005485952366143465f, 0.002958085387945175f, 0.003923716489225626f, 0.0056234318763017654f, 0.003082903567701578f, 0.0037146033719182014f, 0.0033215901348739862f, 0.0035935912746936083f, 0.0036987634375691414f, 0.0032525788992643356f, 0.004292162135243416f, 0.0040128654800355434f, 0.003820545971393585f, 0.003391462843865156f, 0.004036093596369028f, 0.003352417843416333f, 0.0031651968602091074f, 0.004436196759343147f, 0.004314885474741459f, 0.0039698053151369095f, 0.003564580576494336f, 0.0037234758492559195f, 0.0037635022308677435f, 0.0037297774106264114f, 0.0034196653869003057f, 0.004178146831691265f, 0.0035949326120316982f, 0.0038610813207924366f, 0.0037413188256323338f, 0.005509563256055117f, 0.0030475177336484194f, 0.004559973254799843f, 0.004571881610900164f, 0.003543061437085271f, 0.0029997294768691063f, 0.0032783683855086565f, 0.00462679285556078f, 0.0033908849582076073f, 0.0038366413209587336f, 0.002781146438792348f, 0.004241006448864937f, 0.0034110562410205603f, 0.0033770836889743805f, 0.004305133130401373f, 0.004008967895060778f, 0.003983802627772093f, 0.00406825914978981f, 0.004230304155498743f, 0.0035255977418273687f, 0.003278439398854971f, 0.0033478301484137774f, 0.0031949542462825775f, 0.003808283945545554f, 0.004298692103475332f, 0.004734647460281849f, 0.0038734683766961098f, 0.005410806275904179f, 0.0036318472120910883f, 0.0032526932191103697f, 0.003597504924982786f, 0.003990450873970985f, 0.0036530718207359314f, 0.0033299101050943136f, 0.004036976024508476f, 0.0030972599051892757f, 0.004319015424698591f, 0.004831819329410791f, 0.0033691891003400087f, 0.0035797771997749805f, 0.004385650623589754f, 0.004873013589531183f, 0.005865420680493116f, 0.004063860047608614f, 0.0035398281179368496f, 0.003063357435166836f, 0.003520447527989745f, 0.003479900537058711f, 0.004149496555328369f, 0.003701451700180769f, 0.004281267989426851f, 0.004563324153423309f, 0.004182690754532814f, 0.004538063425570726f, 0.003617816139012575f, 0.003659724025055766f, 0.004247055388987064f, 0.004130721557885408f, 0.003581088734790683f, 0.0031423233449459076f, 0.0033550416119396687f, 0.0036861810367554426f, 0.006072734948247671f, 0.003580274526029825f, 0.003675810294225812f, 0.0038705957122147083f, 0.003920970018953085f, 0.0037337555550038815f, 0.0031526011880487204f, 0.0041847326792776585f, 0.004725039470940828f, 0.004196532536298037f, 0.003375475527718663f, 0.0037838721182197332f, 0.0037047755904495716f, 0.00448200386017561f, 0.003945316653698683f, 0.0038518887013196945f, 0.003912697080522776f, 0.0035066341515630484f, 0.004275746177881956f, 0.0033818574156612158f, 0.004516232758760452f, 0.003608993487432599f, 0.0035271351225674152f, 0.0029475358314812183f, 0.0044801123440265656f, 0.0038984178099781275f, 0.004397981334477663f, 0.0036905973684042692f, 0.0039566317573189735f, 0.004126035608351231f, 0.003393761580809951f, 0.004017827101051807f, 0.004384600557386875f, 0.0034729281906038523f, 0.003927913028746843f, 0.003928858786821365f, 0.005807938519865274f, 0.0043465509079396725f, 0.0041412306018173695f, 0.0034971393179148436f, 0.004865826107561588f, 0.0035962238907814026f, 0.0037453460972756147f, 0.004292232915759087f, 0.0030403758864849806f, 0.003620086470618844f, 0.004031492862850428f, 0.004563336260616779f, 0.004896350670605898f, 0.003316075075417757f, 0.003017794108018279f, 0.0037410128861665726f, 0.0038430807180702686f, 0.0037303066346794367f, 0.003806253196671605f, 0.0037109525874257088f, 0.0029094316996634007f, 0.003603394841775298f, 0.004206246696412563f, 0.00339046330191195f, 0.003353436477482319f, 0.003325133118778467f, 0.0034080983605235815f, 0.0030388899613171816f, 0.0035089512821286917f, 0.0037134727463126183f, 0.0029600325506180525f, 0.004264439921826124f, 0.0031387850176542997f, 0.004202780779451132f, 0.004709987435489893f, 0.003865252248942852f, 0.004131568595767021f, 0.0039000827819108963f, 0.0031189967412501574f, 0.003231070237234235f, 0.003516832599416375f, 0.0034131330903619528f, 0.0035837336909025908f, 0.0037023969925940037f, 0.003444469766691327f, 0.004690661560744047f, 0.003776862984523177f, 0.0036350961308926344f, 0.002930225105956197f, 0.004101108759641647f, 0.004383181221783161f, 0.0032548157032579184f, 0.004400069825351238f, 0.0035027344711124897f, 0.002985740313306451f, 0.004245380405336618f, 0.003629618790000677f, 0.004228337202221155f, 0.0031357111874967813f, 0.0033481549471616745f, 0.004325544461607933f, 0.00364362308755517f, 0.00405625207349658f, 0.004190986044704914f, 0.0037382133305072784f, 0.0035301605239510536f, 0.003848389955237508f, 0.004513812251389027f, 0.0035816330928355455f, 0.0044907573610544205f, 0.0030734518077224493f, 0.004113674629479647f, 0.0032499057706445456f, 0.0029603575821965933f, 0.0031214847695082426f, 0.003096085973083973f, 0.0034700059331953526f, 0.003664362942799926f, 0.00415640277788043f, 0.0032838773913681507f, 0.004119792953133583f, 0.003627513302490115f, 0.0035495443735271692f, 0.003308218205347657f, 0.0029720766469836235f, 0.004225956741720438f, 0.0034761277493089437f, 0.003616757458075881f, 0.0030844772700220346f, 0.003596588736400008f, 0.004312840756028891f, 0.003382220398634672f, 0.003983812872320414f, 0.00473918579518795f, 0.003948417492210865f, 0.004426038824021816f, 0.004134710878133774f, 0.0026497822254896164f, 0.0029900120571255684f, 0.003603713819757104f, 0.004140692763030529f, 0.003226194530725479f, 0.003353161970153451f, 0.004237430635839701f, 0.0034699696116149426f, 0.003261550795286894f, 0.004420971963554621f, 0.004506829660385847f, 0.0037063928321003914f, 0.00487936707213521f, 0.004529417492449284f, 0.004179668612778187f, 0.003669495228677988f, 0.0034063938073813915f, 0.0031893544364720583f, 0.0036273670848459005f, 0.004923535045236349f, 0.003010094864293933f, 0.004265320021659136f, 0.004500055685639381f, 0.004156975075602531f, 0.002885600319132209f, 0.002973913447931409f, 0.00408858060836792f, 0.0036299508064985275f, 0.004287448711693287f, 0.0032969217281788588f, 0.003886751364916563f, 0.0033225417137145996f, 0.004545123316347599f, 0.0031153575982898474f, 0.0032655452378094196f, 0.004276405554264784f, 0.0032842406071722507f, 0.004038607701659203f, 0.0036575670819729567f, 0.0032638441771268845f, 0.0038801943883299828f, 0.004386259242892265f, 0.006266017910093069f, 0.0033433043863624334f, 0.0035418341867625713f, 0.0037159353960305452f, 0.003750019008293748f, 0.004375551361590624f, 0.003761537605896592f, 0.0035675386898219585f, 0.0043622758239507675f, 0.0040155029855668545f, 0.003268867963925004f, 0.004967513028532267f, 0.0036836382932960987f, 0.003703545080497861f, 0.005030590109527111f, 0.004102685023099184f, 0.003496711142361164f, 0.004623484332114458f, 0.0044000460766255856f, 0.0035491918679326773f, 0.0047195469960570335f, 0.003473901655524969f, 0.0028756060637533665f, 0.003623445052653551f, 0.003577267052605748f, 0.003260347293689847f, 0.003417127998545766f, 0.003827175125479698f, 0.003970835357904434f, 0.004037435166537762f, 0.0038029637653380632f, 0.004964381922036409f, 0.003615353722125292f, 0.004663452040404081f, 0.0037088394165039062f, 0.003222369821742177f, 0.0033982081804424524f, 0.00341453542932868f, 0.005389411002397537f, 0.0042851767502725124f, 0.0029914667829871178f, 0.004213717766106129f, 0.003656169632449746f, 0.005473132710903883f, 0.004141768906265497f, 0.005266607739031315f, 0.004633591044694185f, 0.003192879958078265f, 0.0033314276952296495f, 0.003959445282816887f, 0.0034829718060791492f, 0.0037485812790691853f, 0.003829779103398323f, 0.003791988827288151f, 0.004430722910910845f, 0.0047205425798892975f, 0.005846777465194464f, 0.0047716787084937096f, 0.004090785048902035f, 0.004043772350996733f, 0.004073330666869879f, 0.004721174947917461f, 0.003996714949607849f, 0.003887275466695428f, 0.003743657609447837f, 0.0032804214861243963f, 0.0038602601271122694f, 0.0036037880927324295f, 0.004096061456948519f, 0.004099768586456776f, 0.003571128472685814f, 0.0033752296585589647f, 0.003964386414736509f, 0.0036886492744088173f, 0.004123199265450239f, 0.004765571095049381f, 0.004150883294641972f, 0.003768018912523985f, 0.004433669615536928f, 0.0045180791057646275f, 0.0034048312809318304f, 0.00390043156221509f, 0.003843194106593728f, 0.0029916318599134684f, 0.0030236640013754368f, 0.003688886994495988f, 0.006153726950287819f, 0.0034774572122842073f, 0.0048773265443742275f, 0.0036245444789528847f, 0.0035867250990122557f, 0.003957362379878759f, 0.005563497543334961f, 0.0037009778898209333f, 0.0036931829527020454f, 0.003397636115550995f, 0.0035108053125441074f, 0.00312315602786839f, 0.003882891498506069f, 0.003601355943828821f, 0.004141919780522585f, 0.0037264388520270586f, 0.004249582998454571f, 0.003505573607981205f, 0.0033702615182846785f, 0.003496863879263401f, 0.0040143923833966255f, 0.004930148366838694f, 0.00408761203289032f, 0.003532127710059285f, 0.0035236028488725424f, 0.002986844163388014f, 0.0031893234699964523f, 0.0034949963446706533f, 0.003837575437501073f, 0.0030570493545383215f, 0.004893495235592127f, 0.003361109644174576f, 0.00346668460406363f, 0.003403447102755308f, 0.0037285350263118744f, 0.0032160645350813866f, 0.004089984577149153f, 0.003120443318039179f, 0.00305331964045763f, 0.004411507863551378f, 0.0032609186600893736f, 0.004274354316294193f, 0.004194176290184259f, 0.004207543097436428f, 0.003657449036836624f, 0.00410618307068944f, 0.003955939318984747f, 0.005211900919675827f, 0.0037916889414191246f, 0.003477461403235793f, 0.0030775475315749645f, 0.004935852717608213f, 0.0038171960040926933f, 0.003478416707366705f, 0.003811120055615902f, 0.002807736163958907f, 0.004117438569664955f, 0.004986507818102837f, 0.0045080832205712795f, 0.003377595916390419f, 0.00481773866340518f, 0.003528469940647483f, 0.004120280500501394f, 0.003474973840638995f, 0.0035590704064816236f, 0.004208311438560486f, 0.0032097615767270327f, 0.0038121389225125313f, 0.0038719859439879656f, 0.0047120158560574055f, 0.003297202754765749f, 0.002832177560776472f, 0.004443935118615627f, 0.005546833388507366f, 0.004733807872980833f, 0.005225821863859892f, 0.004065012093633413f, 0.004077001474797726f, 0.0032616565003991127f, 0.004428495187312365f, 0.0034507380332797766f, 0.0041101593524217606f, 0.0034873299300670624f, 0.0033979464787989855f, 0.0033217077143490314f, 0.004126436542719603f, 0.004351244308054447f, 0.004121549427509308f, 0.0038676862604916096f, 0.004171481356024742f, 0.0036255216691643f, 0.003853175789117813f, 0.0031272454652935266f, 0.003353825071826577f, 0.003740049432963133f, 0.004161571618169546f, 0.0038523413240909576f, 0.004082819912582636f, 0.00397453224286437f, 0.0041042594239115715f, 0.003406716277822852f, 0.004060358740389347f, 0.0033030244521796703f, 0.003911598119884729f, 0.003598912386223674f, 0.0033983171451836824f, 0.0033244984224438667f, 0.003917078487575054f, 0.003810863709077239f, 0.0035392967984080315f, 0.004076141864061356f, 0.0032399501651525497f, 0.0035825250670313835f, 0.0037887967191636562f, 0.0034658743534237146f, 0.004923576954752207f, 0.0037815668620169163f, 0.004306468181312084f, 0.0036415415816009045f, 0.005419928580522537f, 0.0034398981370031834f, 0.004198750015348196f, 0.0041436259634792805f, 0.0037347155157476664f, 0.005426941905170679f, 0.005220815073698759f, 0.003001410746946931f, 0.0033461847342550755f, 0.004142788704484701f, 0.004206974059343338f, 0.004153857938945293f, 0.005149049684405327f, 0.003303574863821268f, 0.004102028906345367f, 0.004466928541660309f, 0.003459393046796322f, 0.004695061594247818f, 0.003192311618477106f, 0.004960471764206886f, 0.004678432364016771f, 0.003454388352110982f, 0.0036572555545717478f, 0.004506153054535389f, 0.004157997667789459f, 0.003855085698887706f, 0.004047448746860027f, 0.0032528992742300034f, 0.0031916447915136814f, 0.003914966247975826f, 0.003505163360387087f, 0.006585283670574427f, 0.004344310611486435f, 0.004599435720592737f, 0.0035100169479846954f, 0.0038444832898676395f, 0.0033834646455943584f, 0.004003351088613272f, 0.00420225178822875f, 0.0038245406467467546f, 0.004241290036588907f, 0.003688027150928974f, 0.0036127702333033085f, 0.005398440174758434f, 0.003105719108134508f, 0.004005788825452328f, 0.0057796211913228035f, 0.005785456858575344f, 0.0033214506693184376f, 0.0035808472894132137f, 0.0033592567779123783f, 0.005698921158909798f, 0.003717217594385147f, 0.004625357687473297f, 0.005211648065596819f, 0.004571720026433468f, 0.004278082866221666f, 0.0039446596056222916f, 0.0038785599172115326f, 0.003817210905253887f, 0.00523017905652523f, 0.003970298916101456f, 0.006923343054950237f, 0.003713170764967799f, 0.0033579959999769926f, 0.0034032564144581556f, 0.0044823442585766315f, 0.0032880061771720648f, 0.0036915855016559362f, 0.004144938196986914f, 0.004888671450316906f, 0.003922427073121071f, 0.004262295551598072f, 0.0038386518135666847f, 0.003214051714166999f, 0.0032410151325166225f, 0.004596066661179066f, 0.0037974808365106583f, 0.004636259749531746f, 0.004012779798358679f, 0.0035720285959541798f, 0.004115900956094265f, 0.0031793650705367327f, 0.0047223130241036415f, 0.004841194953769445f, 0.003152833553031087f, 0.00377991353161633f, 0.0036642816849052906f, 0.004059857223182917f, 0.0031551532447338104f, 0.004072639625519514f, 0.003970149904489517f, 0.0037611115258187056f, 0.0038610566407442093f, 0.004342364612966776f, 0.003719654167070985f, 0.0035633568186312914f, 0.0036882413551211357f, 0.0035809515975415707f, 0.003973361570388079f, 0.004169093910604715f, 0.0031605239491909742f, 0.0037840597797185183f, 0.004318686667829752f, 0.004346385598182678f, 0.0035405003000050783f, 0.0032194769009947777f, 0.003782112617045641f, 0.004200844094157219f, 0.00346943037584424f, 0.004298144951462746f, 0.003203001571819186f, 0.00426093116402626f, 0.004389071837067604f, 0.003562566824257374f, 0.0037465740460902452f, 0.003922441508620977f, 0.0036037294194102287f, 0.0054223062470555305f, 0.003808380337432027f, 0.004504825454205275f, 0.004984700586646795f, 0.0034064396750181913f, 0.0046753347851336f, 0.003728574840351939f, 0.003573769936338067f, 0.004096942022442818f, 0.005298291798681021f, 0.004652389325201511f, 0.0032641575671732426f, 0.0034198558423668146f, 0.003755254205316305f, 0.004505309741944075f, 0.0036802906543016434f, 0.003964756149798632f, 0.003509960602968931f, 0.004345394670963287f, 0.003441914450377226f, 0.004164028447121382f, 0.0034352662041783333f, 0.00451092841103673f, 0.004927424248307943f, 0.0037634146865457296f, 0.0032375187147408724f, 0.0040099965408444405f, 0.003226038534194231f, 0.0031939938198775053f, 0.003271788125857711f, 0.0028674043715000153f, 0.0034625413827598095f, 0.00473668472841382f, 0.0044266171753406525f, 0.00339365191757679f, 0.0038227688055485487f, 0.0037828937638550997f, 0.0038020992651581764f, 0.004168372135609388f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #170 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_67_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1280,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00037648435682058334f, 0.00042761507211253047f, 0.0006247279816307127f, 0.00041850272100418806f, 0.0004957576747983694f, 0.0005623809993267059f, 0.0004434109141584486f, 0.0004365337663330138f, 0.0005238594603724778f, 0.000453943241154775f, 0.0005456885555759072f, 0.0004891592543572187f, 0.0004337048449087888f, 0.0004617306112777442f, 0.0006215724279172719f, 0.0006387226167134941f, 0.0005004811100661755f, 0.0003942983748856932f, 0.00041600820259191096f, 0.0004951021401211619f, 0.00046505421050824225f, 0.00048687029629945755f, 0.00046376162208616734f, 0.0005472503835335374f, 0.0004960973164997995f, 0.00047052663285285234f, 0.0004877198371104896f, 0.0004201155388727784f, 0.0005365455872379243f, 0.00041081139352172613f, 0.0004146288556512445f, 0.00041107655852101743f, 0.0005523260333575308f, 0.0004065800167154521f, 0.00045881824917159975f, 0.000517507316544652f, 0.0004006894014310092f, 0.00042265583761036396f, 0.000539918546564877f, 0.0003454491379670799f, 0.00044902629451826215f, 0.0004272068908903748f, 0.00042156316339969635f, 0.0005825316184200346f, 0.0004770987725351006f, 0.0004634380748029798f, 0.0004248958430252969f, 0.00042430643225088716f, 0.0006171391578391194f, 0.00045552136725746095f, 0.0005566071486100554f, 0.000609476410318166f, 0.0004342515312600881f, 0.00046404165914282203f, 0.0005241259350441396f, 0.0005712285055778921f, 0.0007547428249381483f, 0.0005718135507777333f, 0.0006300572422333062f, 0.0005006319843232632f, 0.0006480736192315817f, 0.0004893114673905075f, 0.0003963054914493114f, 0.00041822867933660746f, 0.00046667244168929756f, 0.0006826571188867092f, 0.0005225107888691127f, 0.00043090665712952614f, 0.0004394367279019207f, 0.00041234164382331073f, 0.0006670476286672056f, 0.00042205373756587505f, 0.0006046977359801531f, 0.00048110325587913394f, 0.00046522356569767f, 0.0005151234799996018f, 0.0004421512712724507f, 0.00047858196194283664f, 0.0004547244752757251f, 0.0004094162432011217f, 0.0005292219575494528f, 0.0005642883479595184f, 0.00036227700184099376f, 0.0004599256790243089f, 0.0005152291269041598f, 0.0005291601992212236f, 0.0005883321282453835f, 0.00045900308759883046f, 0.0005767850670963526f, 0.00043546810047701f, 0.0004411154077388346f, 0.000581111351493746f, 0.0004995722556486726f, 0.00043726296280510724f, 0.0005359475035220385f, 0.0005448806332424283f, 0.0003870575164910406f, 0.0003734224883373827f, 0.0005100739072076976f, 0.00042470439802855253f, 0.0005486487643793225f, 0.00047117998474277556f, 0.0004411668633110821f, 0.00039535597898066044f, 0.000577607424929738f, 0.00040319949039258063f, 0.0005142615409567952f, 0.0006412792718037963f, 0.0006221052608452737f, 0.0004447807732503861f, 0.0004797338042408228f, 0.0004356181889306754f, 0.000494679668918252f, 0.00045409443555399776f, 0.0005404084804467857f, 0.0005515951779671013f, 0.0004636394733097404f, 0.00042515533277764916f, 0.00046915802522562444f, 0.0003988413081970066f, 0.0003553737769834697f, 0.00048803299432620406f, 0.0006405439926311374f, 0.0005486266454681754f, 0.0005456839571706951f, 0.0004078166384715587f, 0.0005560450372286141f, 0.0005620497977361083f, 0.00040986566455103457f, 0.0004965892294421792f, 0.0004419221659190953f, 0.00037148527917452157f, 0.0004506062250584364f, 0.0004931989242322743f, 0.000500335416290909f, 0.000419787218561396f, 0.0005345191457308829f, 0.0004525919212028384f, 0.0005208280053921044f, 0.0006548847886733711f, 0.00034949713153764606f, 0.0005619801231659949f, 0.00043347576865926385f, 0.000447421392891556f, 0.0004128513392060995f, 0.0004233443469274789f, 0.00038000085623934865f, 0.0005498446407727897f, 0.0004328970389906317f, 0.0005729538970626891f, 0.0006665682885795832f, 0.0005452683544717729f, 0.0004637956153601408f, 0.0004468701663427055f, 0.0004844717332161963f, 0.0005475064390338957f, 0.00048794643953442574f, 0.0004308994684834033f, 0.00039342421223409474f, 0.0007778086001053452f, 0.0004247772740200162f, 0.0005414696061052382f, 0.000468243844807148f, 0.0004256995744071901f, 0.0004061028594151139f, 0.00048128890921361744f, 0.0005091079510748386f, 0.00034326972672715783f, 0.00045997154666110873f, 0.00042193528497591615f, 0.0005307005485519767f, 0.00042503923759795725f, 0.0005002151592634618f, 0.00042853085324168205f, 0.0005437307991087437f, 0.0004219411057420075f, 0.0005221678875386715f, 0.0004691308131441474f, 0.0005626808851957321f, 0.0005174378165975213f, 0.000532057078089565f, 0.0004828640667255968f, 0.0005520281265489757f, 0.00041805030195973814f, 0.0005257391021586955f, 0.0005031262990087271f, 0.0005469044554047287f, 0.00040587008697912097f, 0.00046729572932235897f, 0.000394495582440868f, 0.0005827366840094328f, 0.0005193444667384028f, 0.0003844521997962147f, 0.0004548169963527471f, 0.0005094959633424878f, 0.0005176390986889601f, 0.0004351090465206653f, 0.0005105659365653992f, 0.00044195898226462305f, 0.0005828274879604578f, 0.0004562418907880783f, 0.0004361213941592723f, 0.0003999033069703728f, 0.0003760534164030105f, 0.000606799847446382f, 0.0005333732115104795f, 0.0004980153753422201f, 0.0004494428576435894f, 0.0004384618659969419f, 0.0004863206995651126f, 0.0004206485755275935f, 0.0004971526795998216f, 0.00044413955765776336f, 0.0005882623954676092f, 0.0005009890883229673f, 0.00048500162665732205f, 0.00041267715278081596f, 0.0005121969734318554f, 0.00042015817598439753f, 0.0005919947288930416f, 0.000463166885310784f, 0.00040439903386868536f, 0.0003859028802253306f, 0.0004563886614050716f, 0.0005445872666314244f, 0.0004998847143724561f, 0.000541834335308522f, 0.0006435815012082458f, 0.0004644024884328246f, 0.0008016892243176699f, 0.00045791995944455266f, 0.0004378525773063302f, 0.0005068606697022915f, 0.00047716862172819674f, 0.0004416874726302922f, 0.0005347052356228232f, 0.0005781459622085094f, 0.0006088297232054174f, 0.0007018104661256075f, 0.00048776812036521733f, 0.0005331528373062611f, 0.0005331899737939239f, 0.0005653401603922248f, 0.0008050653850659728f, 0.00040714466013014317f, 0.0003918282163795084f, 0.0004899573978036642f, 0.00041056558256968856f, 0.0004769827064592391f, 0.0005378546193242073f, 0.0005839810473844409f, 0.0005683565977960825f, 0.0004972681635990739f, 0.0004930252325721085f, 0.0005826796987093985f, 0.0004634665965568274f, 0.0005317950272001326f, 0.0004596086801029742f, 0.00041644289740361273f, 0.0005428894073702395f, 0.000538751482963562f, 0.0004455280432011932f, 0.0004505027609411627f, 0.00042607408249750733f, 0.0005085448501631618f, 0.0004859402251895517f, 0.0005913248751312494f, 0.0004758484137710184f, 0.0005767478724010289f, 0.0005227333749644458f, 0.00044969934970140457f, 0.0005116966785863042f, 0.00042580647277645767f, 0.0005200749728828669f, 0.00048685655929148197f, 0.0004361423198133707f, 0.0008076893864199519f, 0.0004927777918055654f, 0.00040374943637289107f, 0.0007716550608165562f, 0.0006025921902619302f, 0.0004477838519960642f, 0.00040589726995676756f, 0.00048788462299853563f, 0.0005057718954049051f, 0.000620831036940217f, 0.0004941942752338946f, 0.0004659887054003775f, 0.00043586999527178705f, 0.00046142766950652003f, 0.0006589163676835597f, 0.0005572101217694581f, 0.00040358389378525317f, 0.00041109236190095544f, 0.00048429591697640717f, 0.0004901548381894827f, 0.0005633656983263791f, 0.0007194716017693281f, 0.000509309524204582f, 0.0004434605943970382f, 0.0004981700913049281f, 0.0004782069881912321f, 0.0004098691279068589f, 0.00043839140562340617f, 0.0003883983881678432f, 0.0005333983572199941f, 0.00040285527938976884f, 0.00038542840047739446f, 0.0004190088948234916f, 0.0005810569855384529f, 0.0006117086159065366f, 0.0004718832205981016f, 0.0004988593282178044f, 0.0005875779315829277f, 0.00045199631131254137f, 0.0005467511364258826f, 0.0005034591304138303f, 0.0005616988055408001f, 0.0004979915102012455f, 0.00047932271263562143f, 0.0005900875548832119f, 0.0005568737396970391f, 0.0005196729907765985f, 0.0004403065540827811f, 0.0004252845828887075f, 0.0004621884727384895f, 0.0004402413032948971f, 0.00041600337135605514f, 0.0003983551578130573f, 0.0004232822102494538f, 0.0003894887922797352f, 0.0004034979792777449f, 0.0006460394943132997f, 0.0004418356984388083f, 0.000520952744409442f, 0.0004543917311821133f, 0.0006027898052707314f, 0.0005734374281018972f, 0.0004510762228164822f, 0.0004842621856369078f, 0.0005166877526789904f, 0.00039330136496573687f, 0.0004376104334369302f, 0.0004027508548460901f, 0.0004625693254638463f, 0.00047056321636773646f, 0.0004436634189914912f, 0.00045842232066206634f, 0.0004995557828806341f, 0.0004164368147030473f, 0.0006062393658794463f, 0.0005921174306422472f, 0.0006842565489932895f, 0.0005223492626100779f, 0.0007023733342066407f, 0.0004444046935532242f, 0.00041672776569612324f, 0.00039822718827053905f, 0.0006104808999225497f, 0.0004186142177786678f, 0.00045398378279060125f, 0.0005440341774374247f, 0.0004730634391307831f, 0.00040692402399145067f, 0.00047384866047650576f, 0.000533849117346108f, 0.0004202590207569301f, 0.00041887929546646774f, 0.0006101247272454202f, 0.00042390197631902993f, 0.0005532048526220024f, 0.0004127601278014481f, 0.00044418565812520683f, 0.0005233816336840391f, 0.000494165054988116f, 0.0006374584045261145f, 0.0004991483874619007f, 0.0006236487533897161f, 0.0003656974295154214f, 0.00040868925862014294f, 0.0005268175737001002f, 0.0004000774642918259f, 0.0004172914777882397f, 0.0005397446220740676f, 0.0004261734429746866f, 0.0005138266133144498f, 0.0004903274239040911f, 0.0005602284800261259f, 0.000610091257840395f, 0.00043640556395985186f, 0.000424812373239547f, 0.0005264430656097829f, 0.00040319241816177964f, 0.0005527095054276288f, 0.0005745016969740391f, 0.0004879467305727303f, 0.0004883286310359836f, 0.0004448606923688203f, 0.0005328376428224146f, 0.00047609186731278896f, 0.00042213150300085545f, 0.000433475011959672f, 0.0005294497823342681f, 0.0004372604889795184f, 0.00046055021812207997f, 0.0004938142374157906f, 0.0005532808136194944f, 0.0005044598365202546f, 0.000824294809717685f, 0.0005568584892898798f, 0.0005108823534101248f, 0.0005571796791628003f, 0.00042350825970061123f, 0.00048821381642483175f, 0.0004465482197701931f, 0.0006016505067236722f, 0.0005410132580436766f, 0.0005126649630255997f, 0.0005961005808785558f, 0.00043856448610313237f, 0.0005301368073560297f, 0.0006095555727370083f, 0.0005345381214283407f, 0.0004362643521744758f, 0.0004101636295672506f, 0.0004989614826627076f, 0.00042249905527569354f, 0.0004974615876562893f, 0.0005022589466534555f, 0.0004553197941277176f, 0.0004451218119356781f, 0.0005423313705250621f, 0.00047207839088514447f, 0.0005346940015442669f, 0.00047051673755049706f, 0.0004528398858383298f, 0.00046200508950278163f, 0.0005246519576758146f, 0.0004770902742166072f, 0.0004673844377975911f, 0.0005023799021728337f, 0.0004290361248422414f, 0.0006221210933290422f, 0.000409515603678301f, 0.0005198012804612517f, 0.0004273157974239439f, 0.00045887668966315687f, 0.0004940645303577185f, 0.0006750602624379098f, 0.000586666283197701f, 0.0003980199689976871f, 0.0005487617454491556f, 0.0006445535691455007f, 0.00045734154991805553f, 0.00048013986088335514f, 0.0005074603832326829f, 0.0004811918770428747f, 0.00039521243888884783f, 0.0004335255944170058f, 0.00036881762207485735f, 0.0008411206072196364f, 0.0006293930928222835f, 0.0003789903421420604f, 0.0004117884091101587f, 0.0005362785886973143f, 0.00044619786785915494f, 0.0004399013123475015f, 0.0005295472801662982f, 0.0006313780904747546f, 0.0004234906518831849f, 0.00046295011998154223f, 0.0005326360114850104f, 0.00040489781531505287f, 0.0004288810887373984f, 0.00044282982707954943f, 0.0005970695638097823f, 0.00041301464079879224f, 0.0005578207783401012f, 0.0005311029963195324f, 0.0005158227286301553f, 0.0005795882898382843f, 0.00047717709094285965f, 0.0003319624229334295f, 0.000546973489690572f, 0.0006613221485167742f, 0.00042982836021110415f, 0.0005856385687366128f, 0.000546284718438983f, 0.0003867808554787189f, 0.0004364473861642182f, 0.0004285570466890931f, 0.0005429803277365863f, 0.00044263413292355835f, 0.00044891078141517937f, 0.0005471350159496069f, 0.0004505475517362356f, 0.0005490981275215745f, 0.0006107559311203659f, 0.00045451984624378383f, 0.000508126278873533f, 0.00043065991485491395f, 0.000646037224214524f, 0.00043906932114623487f, 0.0004737073031719774f, 0.0004516228218562901f, 0.0005463637062348425f, 0.0005990118370391428f, 0.0004741524753626436f, 0.00044641733984462917f, 0.00035834507434628904f, 0.0004178868839517236f, 0.0004401287587825209f, 0.0004102936072740704f, 0.0005836233031004667f, 0.0004241789865773171f, 0.0005533680669032037f, 0.0005167821072973311f, 0.000569996889680624f, 0.0005584188038483262f, 0.0004456393944565207f, 0.0004276628023944795f, 0.0005228670779615641f, 0.0006799637340009212f, 0.0005264055216684937f, 0.0004891001735813916f, 0.00043184272362850606f, 0.000594691839069128f, 0.0006169023690745234f, 0.0005929027684032917f, 0.0004161519755143672f, 0.0008090666378848255f, 0.00044935307232663035f, 0.00046178395859897137f, 0.0003815886448137462f, 0.000527986092492938f, 0.0005698706372641027f, 0.0004589405143633485f, 0.00043056756840087473f, 0.000484023941680789f, 0.0004070219292771071f, 0.0004803451884072274f, 0.0006740145618095994f, 0.0006074480479583144f, 0.00039781295345164835f, 0.00040803098818287253f, 0.0005003614933229983f, 0.0005430664168670774f, 0.00047934456961229444f, 0.0003738321829587221f, 0.0005097887478768826f, 0.0006533655687235296f, 0.0008049159660004079f, 0.0004820825415663421f, 0.0004384983913041651f, 0.0004883116343989968f, 0.00041645963210612535f, 0.0004982139216735959f, 0.0004931613802909851f, 0.0006264090188778937f, 0.00046718085650354624f, 0.0005338649498298764f, 0.0005018623196519911f, 0.0005112737999297678f, 0.00045414341730065644f, 0.0005190958036109805f, 0.0004665111191570759f, 0.0004913111333735287f, 0.0006056143902242184f, 0.0004413203860167414f, 0.0003940433089155704f, 0.0005782161606475711f, 0.000612412579357624f, 0.0006340998224914074f, 0.00043872007518075407f, 0.0005184388719499111f, 0.0004513251187745482f, 0.000426330923801288f, 0.00042258462053723633f, 0.00044076875201426446f, 0.00037653386243619025f, 0.00047813632409088314f, 0.0005255960277281702f, 0.0004651384660974145f, 0.0006070991512387991f, 0.0007461262284778059f, 0.0005910185864195228f, 0.0004096812626812607f, 0.0005189135554246604f, 0.000649075664114207f, 0.000481231021694839f, 0.0004745908663608134f, 0.0005317676113918424f, 0.0005138521664775908f, 0.0005654328851960599f, 0.0005694341962225735f, 0.0004774838453158736f, 0.0004453083092812449f, 0.00040199613431468606f, 0.00036187178920954466f, 0.00040053020347841084f, 0.0004702963924501091f, 0.00043491754331626f, 0.0006469158106483519f, 0.00045663496712222695f, 0.0005354571621865034f, 0.000505200820043683f, 0.00045560646685771644f, 0.0005810377188026905f, 0.0004991914611309767f, 0.0004157397779636085f, 0.0006433233502320945f, 0.0005466678412631154f, 0.00040766343590803444f, 0.0004780622839462012f, 0.00043918893788941205f, 0.0005090620252303779f, 0.0005914514767937362f, 0.0005574966198764741f, 0.0005266341031529009f, 0.00047825693036429584f, 0.0005318440962582827f, 0.0005581264267675579f, 0.0005183007451705635f, 0.00041505382978357375f, 0.0007440624758601189f, 0.000514117768034339f, 0.0004953742609359324f, 0.0003694163460750133f, 0.0005744591471739113f, 0.00045534560922533274f, 0.000527261639945209f, 0.00047626340528950095f, 0.0004845979274250567f, 0.00047330709639936686f, 0.0005417856154963374f, 0.00049003423191607f, 0.0005551286158151925f, 0.00039666928933002055f, 0.0005062299896962941f, 0.00044348210212774575f, 0.0007430149125866592f, 0.0005076174857094884f, 0.000496217398904264f, 0.00041787198279052973f, 0.0005504871951416135f, 0.000576513004489243f, 0.00048590402002446353f, 0.00040968882967717946f, 0.0003736677172128111f, 0.0005618886207230389f, 0.0004276677791494876f, 0.0004462275537662208f, 0.0006972497212700546f, 0.00037596464972011745f, 0.0004986937274225056f, 0.0007147229625843465f, 0.00039182871114462614f, 0.00047211602213792503f, 0.000422165117925033f, 0.00045673572458326817f, 0.0004701028228737414f, 0.0004133939801249653f, 0.0005455221980810165f, 0.0005100243142805994f, 0.00048558105481788516f, 0.00043104574433527887f, 0.0005129765486344695f, 0.00042608322110027075f, 0.00040228795842267573f, 0.0005638286238536239f, 0.00054841028759256f, 0.0005045515135861933f, 0.0004530485311988741f, 0.0004732437082566321f, 0.0004783309414051473f, 0.00047404461656697094f, 0.0004346302303019911f, 0.0005310311680659652f, 0.0004569062148220837f, 0.0004907330148853362f, 0.00047551150782965124f, 0.0007002505590207875f, 0.0003873312671203166f, 0.000579560233745724f, 0.0005810738075524569f, 0.000450313527835533f, 0.0003812575014308095f, 0.00041667174082249403f, 0.0005880528478883207f, 0.00043097231537103653f, 0.0004876267339568585f, 0.00035347617813386023f, 0.0005390204605646431f, 0.0004335360135883093f, 0.00042921819840557873f, 0.0005471707554534078f, 0.0005095289670862257f, 0.0005063305143266916f, 0.000517064705491066f, 0.0005376602057367563f, 0.0004480939242057502f, 0.0004166807630099356f, 0.00042550015496090055f, 0.00040607003029435873f, 0.00048402257380075753f, 0.0005463521229103208f, 0.0006017608684487641f, 0.0004923073574900627f, 0.0006876988336443901f, 0.0004615979560185224f, 0.0004134085029363632f, 0.0004572331381496042f, 0.0005071755149401724f, 0.0004642955318558961f, 0.00042322257650084794f, 0.0005130887147970498f, 0.0003936533466912806f, 0.0005489351460710168f, 0.00061411113711074f, 0.0004282148147467524f, 0.00045498000690713525f, 0.0005574043025262654f, 0.0006193468580022454f, 0.0007454790757037699f, 0.0005165056209079921f, 0.00044990258174948394f, 0.0003893444372806698f, 0.00044743934995494783f, 0.000442285934695974f, 0.0005273897550068796f, 0.00047044450184330344f, 0.000544137554243207f, 0.0005799861392006278f, 0.0005316087044775486f, 0.0005767755792476237f, 0.0004598146479111165f, 0.0004651410272344947f, 0.0005397892673499882f, 0.000525003531947732f, 0.00045514668454416096f, 0.00039938080590218306f, 0.00042641672189347446f, 0.0004685036255978048f, 0.0007718281704001129f, 0.0004550431913230568f, 0.00046718554222024977f, 0.0004919422208331525f, 0.0004983446560800076f, 0.0004745502374134958f, 0.00040068707312457263f, 0.0005318681942299008f, 0.0006005397299304605f, 0.0005333679146133363f, 0.0004290138022042811f, 0.0004809199017472565f, 0.00047086694394238293f, 0.0005696505540981889f, 0.0005014390917494893f, 0.0004895646125078201f, 0.0004972931928932667f, 0.0004456837195903063f, 0.0005434357444755733f, 0.00042982492595911026f, 0.0005740009364672005f, 0.000458693306427449f, 0.00044828932732343674f, 0.00037462383625097573f, 0.0005694101564586163f, 0.0004954783362336457f, 0.0005589715437963605f, 0.0004690649511758238f, 0.0005028771702200174f, 0.0005244079511612654f, 0.000431337917689234f, 0.0005106549360789359f, 0.0005572708905674517f, 0.00044139978126622736f, 0.0004992271424271166f, 0.0004993473412469029f, 0.0007381732575595379f, 0.000552434881683439f, 0.0005263392231427133f, 0.0004444769292604178f, 0.0006184333469718695f, 0.00045707033132202923f, 0.0004760233568958938f, 0.0005455311620607972f, 0.00038642354775220156f, 0.00046010318328626454f, 0.0005123918526805937f, 0.0005799877108074725f, 0.000622312945779413f, 0.000421464181272313f, 0.00038355347351171076f, 0.00047547262511216104f, 0.0004884451627731323f, 0.00047411187551915646f, 0.0004837644810322672f, 0.0004716520197689533f, 0.0003697809006553143f, 0.0004579817468766123f, 0.0005346025573089719f, 0.0004309187061153352f, 0.00042621270404197276f, 0.00042261541238985956f, 0.00043316007941029966f, 0.0003862346929963678f, 0.00044597822125069797f, 0.00047197233652696013f, 0.00037621211959049106f, 0.0005419987719506025f, 0.0003989310935139656f, 0.0005341620417311788f, 0.0005986266769468784f, 0.0004912631120532751f, 0.0005251112161204219f, 0.000495689979288727f, 0.0003964160569012165f, 0.00041066028643399477f, 0.00044697991688735783f, 0.00043379998533055186f, 0.0004554828628897667f, 0.00047056464245542884f, 0.00043778278632089496f, 0.000596170371863991f, 0.00048002906260080636f, 0.0004620108811650425f, 0.00037242367397993803f, 0.0005212398245930672f, 0.00055709044681862f, 0.0004136782663408667f, 0.0005592369707301259f, 0.0004451880813576281f, 0.0003794795193243772f, 0.0005395763437263668f, 0.00046131471754051745f, 0.000537410203833133f, 0.0003985404036939144f, 0.0004255414241924882f, 0.0005497650126926601f, 0.0004630946204997599f, 0.0005155386752448976f, 0.0005326629616320133f, 0.000475116801680997f, 0.0004486738471314311f, 0.0004891199641861022f, 0.0005736933089792728f, 0.0004552158643491566f, 0.0005707631353288889f, 0.000390627421438694f, 0.0005228369263932109f, 0.0004130542220082134f, 0.0003762534470297396f, 0.0003967322700191289f, 0.0003935041604563594f, 0.00044102835818193853f, 0.0004657306126318872f, 0.0005282675265334547f, 0.00041737192077562213f, 0.0005236145225353539f, 0.00046104713692329824f, 0.0004511374863795936f, 0.00042046557064168155f, 0.0003777428937610239f, 0.0005371076404117048f, 0.00044180641998536885f, 0.00045968007179908454f, 0.0003920287126675248f, 0.0004571166937239468f, 0.0005481503903865814f, 0.0004298710555303842f, 0.0005063318531028926f, 0.0006023377063684165f, 0.0005018331576138735f, 0.0005625375779345632f, 0.0005255105788819492f, 0.00033678015461191535f, 0.00038002245128154755f, 0.0004580222594086081f, 0.00052627082914114f, 0.00041004060767591f, 0.00042617780854925513f, 0.0005385659751482308f, 0.00044102375977672637f, 0.00041453426820226014f, 0.0005618935683742166f, 0.0005728058749809861f, 0.00047107250429689884f, 0.000620154372882098f, 0.0005756766768172383f, 0.0005312245921231806f, 0.00046638291678391397f, 0.00043294343049637973f, 0.00040535832522436976f, 0.0004610285395756364f, 0.0006257679779082537f, 0.000382574915420264f, 0.0005421106470748782f, 0.000571944925468415f, 0.0005283402861095965f, 0.0003667519777081907f, 0.0003779763646889478f, 0.0005196475540287793f, 0.0004613569180946797f, 0.0005449231248348951f, 0.00041902982047758996f, 0.000493995554279536f, 0.00042228607344441116f, 0.0005776728503406048f, 0.00039595350972376764f, 0.0004150419554207474f, 0.0005435195635072887f, 0.0004174180794507265f, 0.0005132961086928844f, 0.00046486686915159225f, 0.0004148257721681148f, 0.0004931621951982379f, 0.0005574816605076194f, 0.000796393898781389f, 0.00042492494685575366f, 0.00045015753130428493f, 0.00047228531911969185f, 0.0004766172787640244f, 0.0005561207653954625f, 0.000478081259643659f, 0.00045342452358454466f, 0.0005544334417209029f, 0.0005103595904074609f, 0.00041546428110450506f, 0.0006313574849627912f, 0.0004681804566644132f, 0.0004707105690613389f, 0.0006393743678927422f, 0.0005214401753619313f, 0.0004444225342012942f, 0.0005876323557458818f, 0.0005592339439317584f, 0.0004510926955845207f, 0.0005998416454531252f, 0.00044152350164949894f, 0.00036548174102790654f, 0.00046053004916757345f, 0.00045466097071766853f, 0.00041438132757321f, 0.00043430773075670004f, 0.0004864236107096076f, 0.0005046824226155877f, 0.000513147097080946f, 0.00048334640450775623f, 0.0006309595191851258f, 0.00045950166531838477f, 0.0005927121383138001f, 0.0004713834496214986f, 0.0004095544863957912f, 0.0004319030558690429f, 0.0004339782171882689f, 0.0006849795463494956f, 0.0005446343566291034f, 0.0003802073188126087f, 0.0005355520988814533f, 0.00046468927757814527f, 0.0006956203724257648f, 0.0005264076171442866f, 0.0006693715695291758f, 0.0005889168824069202f, 0.00040580640779808164f, 0.0004234154475852847f, 0.0005032347980886698f, 0.00044267630437389016f, 0.00047643453581258655f, 0.0004867545503657311f, 0.0004819515161216259f, 0.0005631328676827252f, 0.0005999681889079511f, 0.0007431096164509654f, 0.0006064674234949052f, 0.0005199277075007558f, 0.0005139525164850056f, 0.0005177092971280217f, 0.0006000485736876726f, 0.0005079716793261468f, 0.0004940622020512819f, 0.00047580874525010586f, 0.0004169326857663691f, 0.0004906285903416574f, 0.0004580317181535065f, 0.0005205983179621398f, 0.0005210695089772344f, 0.0004538807552307844f, 0.00042898254469037056f, 0.0005038628005422652f, 0.0004688173357862979f, 0.0005240474711172283f, 0.0006056911661289632f, 0.0005275660078041255f, 0.0004789050144609064f, 0.0005635074339807034f, 0.0005742356297560036f, 0.00043274485506117344f, 0.0004957342753186822f, 0.0004884595982730389f, 0.000380228302674368f, 0.0003842995211016387f, 0.000468847545562312f, 0.0007821220206096768f, 0.00044197539682500064f, 0.0006198949995450675f, 0.0004606698057614267f, 0.000455863046227023f, 0.0005029700696468353f, 0.0007071055006235838f, 0.00047038428601808846f, 0.0004693935625255108f, 0.00043183035450056195f, 0.0004462138458620757f, 0.00039694466977380216f, 0.0004935049801133573f, 0.00045772260637022555f, 0.0005264267674647272f, 0.00047362028271891177f, 0.0005401105154305696f, 0.0004455489106476307f, 0.00042835110798478127f, 0.0004444419464562088f, 0.0005102184368297458f, 0.0006266084965318441f, 0.0005195244448259473f, 0.0004489238781388849f, 0.0004478404007386416f, 0.00037961979978717864f, 0.0004053543962072581f, 0.0004442045756150037f, 0.00048774544848129153f, 0.00038854271406307817f, 0.0006219500210136175f, 0.00042718794429674745f, 0.00044060623622499406f, 0.0004325689224060625f, 0.0004738866991829127f, 0.000408753112424165f, 0.000519825960509479f, 0.0003965999057982117f, 0.0003880686708725989f, 0.0005606907070614398f, 0.00041445394163019955f, 0.0005432588513940573f, 0.0005330684361979365f, 0.0005347673431970179f, 0.00046485188067890704f, 0.0005218847654759884f, 0.0005027891602367163f, 0.0006624184898100793f, 0.0004819133901037276f, 0.00044197592069394886f, 0.00039114797255024314f, 0.0006273335311561823f, 0.0004851552948821336f, 0.00044209734187461436f, 0.00048438305384479463f, 0.00035685565671883523f, 0.0005233152769505978f, 0.0006337716476991773f, 0.0005729651893489063f, 0.00042928330367431045f, 0.0006123215425759554f, 0.00044845897355116904f, 0.0005236765136942267f, 0.00044165976578369737f, 0.00045234820572659373f, 0.0005348650156520307f, 0.00040795200038701296f, 0.00048451253678649664f, 0.0004921189392916858f, 0.0005988844786770642f, 0.00041906555998139083f, 0.0003599621122702956f, 0.0005648121004924178f, 0.0007049874984659255f, 0.0006016541738063097f, 0.000664187828078866f, 0.0005166520131751895f, 0.0005181758315302432f, 0.00041454771417193115f, 0.0005628497456200421f, 0.0004385794745758176f, 0.0005223901243880391f, 0.0004432302084751427f, 0.0004318697901908308f, 0.0004221800481900573f, 0.0005244589410722256f, 0.0005530313937924802f, 0.000523837807122618f, 0.0004915724857710302f, 0.0005301840137690306f, 0.00046079399180598557f, 0.0004897282342426479f, 0.00039746443508192897f, 0.00042626209324225783f, 0.0004753501561935991f, 0.000528924516402185f, 0.0004896221798844635f, 0.0005189153598621488f, 0.0005051522748544812f, 0.0005216402933001518f, 0.0004329844086896628f, 0.0005160606233403087f, 0.0004198054666630924f, 0.0004971535527147353f, 0.0004574120102915913f, 0.0004319169092923403f, 0.00042253476567566395f, 0.0004978500655852258f, 0.0004843504575546831f, 0.00044983503175899386f, 0.0005180665757507086f, 0.00041178890387527645f, 0.00045532925287261605f, 0.00048154580872505903f, 0.0004405032377690077f, 0.0006257733330130577f, 0.0004806269134860486f, 0.0005473404307849705f, 0.0004628300666809082f, 0.0006888582720421255f, 0.0004372017574496567f, 0.0005336497561074793f, 0.0005266436492092907f, 0.0004746722406707704f, 0.0006897496059536934f, 0.0006635514437220991f, 0.00038147118175402284f, 0.00042529101483523846f, 0.0005265372456051409f, 0.0005346949910745025f, 0.0005279441247694194f, 0.0006544303032569587f, 0.00041987543227151036f, 0.0005213567637838423f, 0.0005677345325239003f, 0.0004396794829517603f, 0.0005967296310700476f, 0.000405734172090888f, 0.0006304625421762466f, 0.0005946161109022796f, 0.0004390434187371284f, 0.0004648272879421711f, 0.000572719844058156f, 0.0005284702638164163f, 0.000489970960188657f, 0.0005144198075868189f, 0.0004134346963837743f, 0.000405649421736598f, 0.0004975816118530929f, 0.0004454967856872827f, 0.0008369717397727072f, 0.0005521501298062503f, 0.0005845758132636547f, 0.00044611364137381315f, 0.0004886233946308494f, 0.0004300292057450861f, 0.000508815108332783f, 0.0005340948118828237f, 0.0004860887711402029f, 0.0005390564911067486f, 0.00046873826067894697f, 0.0004591733159031719f, 0.0006861271103844047f, 0.00039472850039601326f, 0.0005091249477118254f, 0.0007345742196775973f, 0.0007353159016929567f, 0.0004221473936922848f, 0.00045511600910685956f, 0.00042695243610069156f, 0.0007243174477480352f, 0.00047244830057024956f, 0.0005878704250790179f, 0.0006623863591812551f, 0.0005810532602481544f, 0.0005437327781692147f, 0.0005013555637560785f, 0.0004929544520564377f, 0.0004851571866311133f, 0.0006647416157647967f, 0.000504614261444658f, 0.0008799381903372705f, 0.0004719339485745877f, 0.0004267921904101968f, 0.000432544678915292f, 0.0005696938023902476f, 0.0004178966919425875f, 0.0004691905342042446f, 0.0005268104141578078f, 0.000621336919721216f, 0.0004985298728570342f, 0.0005417262436822057f, 0.00048788226558826864f, 0.00040849726065061986f, 0.0004119242657907307f, 0.0005841476377099752f, 0.0004826495423913002f, 0.000589256058447063f, 0.0005100134294480085f, 0.00045399516238830984f, 0.0005231198738329113f, 0.0004040886997245252f, 0.0006001932197250426f, 0.0006153027643449605f, 0.0004007166135124862f, 0.00048041678383015096f, 0.00046572028077207506f, 0.0005159968859516084f, 0.00040101143531501293f, 0.0005176214617677033f, 0.0005045952857472003f, 0.000478027097415179f, 0.0004907298716716468f, 0.000551902805455029f, 0.0004727579653263092f, 0.00045289300032891333f, 0.0004687655018642545f, 0.0004551292513497174f, 0.0005050034960731864f, 0.0005298805772326887f, 0.00040169403655454516f, 0.00048094376688823104f, 0.0005488934111781418f, 0.0005524138687178493f, 0.00044998800149187446f, 0.0004091867886018008f, 0.000480696267914027f, 0.0005339159397408366f, 0.00044095522025600076f, 0.0005462825647555292f, 0.0004070928262080997f, 0.0005415528430603445f, 0.0005578391719609499f, 0.0004527925921138376f, 0.0004761794116348028f, 0.0004985316772945225f, 0.0004580242675729096f, 0.0006891604280099273f, 0.0004840348265133798f, 0.0005725511000491679f, 0.0006335419602692127f, 0.0004329492512624711f, 0.0005942223942838609f, 0.0004738917632494122f, 0.0004542164970189333f, 0.0005207102512940764f, 0.0006733985501341522f, 0.0005913060740567744f, 0.0004148655862081796f, 0.00043465441558510065f, 0.0004772826505359262f, 0.0005726126837544143f, 0.0004677549877669662f, 0.0005039097741246223f, 0.0004461064818315208f, 0.0005522879073396325f, 0.00043745801667682827f, 0.0005292367422953248f, 0.0004366130451671779f, 0.0005733267753385007f, 0.0006262622773647308f, 0.00047831982374191284f, 0.00041147987940348685f, 0.0005096597014926374f, 0.0004100207588635385f, 0.0004059479688294232f, 0.00041583541315048933f, 0.0003644393291324377f, 0.0004400796315167099f, 0.0006020198343321681f, 0.000562611036002636f, 0.00043132397695444524f, 0.0004858635657001287f, 0.00048079557018354535f, 0.00048323653754778206f, 0.000529788841959089f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #171 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_69_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0014058997621759772f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #172 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_69_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(3.0832372431177646e-05f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #173 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_70_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002699912991374731f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #174 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_70_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011213662489166672f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #175 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #176 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #177 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #178 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #179 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #180 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #181 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #182 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #183 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #184 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #185 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #186 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #187 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #188 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #189 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #190 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #191 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #192 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #193 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #194 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #195 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #196 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #197 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #198 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_45_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #199 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #200 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #201 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_52_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #202 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_54_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #203 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #204 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_57_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #205 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_60_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #206 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_61_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #207 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #208 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_65_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #209 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_67_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #210 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_67_scratch2_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_sequential_17_input0_output, AI_STATIC,
  0, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 224, 224), AI_STRIDE_INIT(4, 1, 1, 3, 672),
  1, &serving_default_sequential_17_input0_output_array, &serving_default_sequential_17_input0_output_intq)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conversion_0_output, AI_STATIC,
  1, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 224, 224), AI_STRIDE_INIT(4, 1, 1, 3, 672),
  1, &conversion_0_output_array, &conversion_0_output_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output, AI_STATIC,
  2, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 112, 112), AI_STRIDE_INIT(4, 1, 1, 16, 1792),
  1, &conv2d_2_output_array, &conv2d_2_output_intq)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_output, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 112, 112), AI_STRIDE_INIT(4, 1, 1, 16, 1792),
  1, &conv2d_3_output_array, &conv2d_3_output_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_output, AI_STATIC,
  4, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 112, 112), AI_STRIDE_INIT(4, 1, 1, 8, 896),
  1, &conv2d_4_output_array, &conv2d_4_output_intq)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_output, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 112, 112), AI_STRIDE_INIT(4, 1, 1, 48, 5376),
  1, &conv2d_5_output_array, &conv2d_5_output_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_output, AI_STATIC,
  6, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 56, 56), AI_STRIDE_INIT(4, 1, 1, 48, 2688),
  1, &conv2d_7_output_array, &conv2d_7_output_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_output, AI_STATIC,
  7, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 56, 56), AI_STRIDE_INIT(4, 1, 1, 8, 448),
  1, &conv2d_8_output_array, &conv2d_8_output_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output, AI_STATIC,
  8, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 56, 56), AI_STRIDE_INIT(4, 1, 1, 48, 2688),
  1, &conv2d_9_output_array, &conv2d_9_output_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_output, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 56, 56), AI_STRIDE_INIT(4, 1, 1, 48, 2688),
  1, &conv2d_10_output_array, &conv2d_10_output_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_output, AI_STATIC,
  10, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 56, 56), AI_STRIDE_INIT(4, 1, 1, 8, 448),
  1, &conv2d_11_output_array, &conv2d_11_output_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_12_output, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 56, 56), AI_STRIDE_INIT(4, 1, 1, 8, 448),
  1, &eltwise_12_output_array, &eltwise_12_output_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_output, AI_STATIC,
  12, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 56, 56), AI_STRIDE_INIT(4, 1, 1, 48, 2688),
  1, &conv2d_13_output_array, &conv2d_13_output_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_output, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 28, 28), AI_STRIDE_INIT(4, 1, 1, 48, 1344),
  1, &conv2d_15_output_array, &conv2d_15_output_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_output, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 28, 28), AI_STRIDE_INIT(4, 1, 1, 16, 448),
  1, &conv2d_16_output_array, &conv2d_16_output_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_output, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_17_output_array, &conv2d_17_output_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_output, AI_STATIC,
  16, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_18_output_array, &conv2d_18_output_intq)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_output, AI_STATIC,
  17, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 28, 28), AI_STRIDE_INIT(4, 1, 1, 16, 448),
  1, &conv2d_19_output_array, &conv2d_19_output_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_20_output, AI_STATIC,
  18, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 28, 28), AI_STRIDE_INIT(4, 1, 1, 16, 448),
  1, &eltwise_20_output_array, &eltwise_20_output_intq)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_output, AI_STATIC,
  19, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_21_output_array, &conv2d_21_output_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_output, AI_STATIC,
  20, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_22_output_array, &conv2d_22_output_intq)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_output, AI_STATIC,
  21, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 28, 28), AI_STRIDE_INIT(4, 1, 1, 16, 448),
  1, &conv2d_23_output_array, &conv2d_23_output_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_24_output, AI_STATIC,
  22, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 28, 28), AI_STRIDE_INIT(4, 1, 1, 16, 448),
  1, &eltwise_24_output_array, &eltwise_24_output_intq)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_output, AI_STATIC,
  23, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_25_output_array, &conv2d_25_output_intq)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_output, AI_STATIC,
  24, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 14, 14), AI_STRIDE_INIT(4, 1, 1, 96, 1344),
  1, &conv2d_27_output_array, &conv2d_27_output_intq)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_output, AI_STATIC,
  25, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 14, 14), AI_STRIDE_INIT(4, 1, 1, 24, 336),
  1, &conv2d_28_output_array, &conv2d_28_output_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_output, AI_STATIC,
  26, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_29_output_array, &conv2d_29_output_intq)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_output, AI_STATIC,
  27, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_30_output_array, &conv2d_30_output_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_output, AI_STATIC,
  28, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 14, 14), AI_STRIDE_INIT(4, 1, 1, 24, 336),
  1, &conv2d_31_output_array, &conv2d_31_output_intq)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_32_output, AI_STATIC,
  29, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 14, 14), AI_STRIDE_INIT(4, 1, 1, 24, 336),
  1, &eltwise_32_output_array, &eltwise_32_output_intq)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_output, AI_STATIC,
  30, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_33_output_array, &conv2d_33_output_intq)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_output, AI_STATIC,
  31, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_34_output_array, &conv2d_34_output_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_output, AI_STATIC,
  32, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 14, 14), AI_STRIDE_INIT(4, 1, 1, 24, 336),
  1, &conv2d_35_output_array, &conv2d_35_output_intq)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_36_output, AI_STATIC,
  33, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 14, 14), AI_STRIDE_INIT(4, 1, 1, 24, 336),
  1, &eltwise_36_output_array, &eltwise_36_output_intq)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_output, AI_STATIC,
  34, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_37_output_array, &conv2d_37_output_intq)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_output, AI_STATIC,
  35, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_38_output_array, &conv2d_38_output_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_output, AI_STATIC,
  36, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 14, 14), AI_STRIDE_INIT(4, 1, 1, 24, 336),
  1, &conv2d_39_output_array, &conv2d_39_output_intq)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_40_output, AI_STATIC,
  37, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 14, 14), AI_STRIDE_INIT(4, 1, 1, 24, 336),
  1, &eltwise_40_output_array, &eltwise_40_output_intq)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_output, AI_STATIC,
  38, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_41_output_array, &conv2d_41_output_intq)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_output, AI_STATIC,
  39, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_42_output_array, &conv2d_42_output_intq)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_output, AI_STATIC,
  40, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 14, 14), AI_STRIDE_INIT(4, 1, 1, 32, 448),
  1, &conv2d_43_output_array, &conv2d_43_output_intq)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_output, AI_STATIC,
  41, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_44_output_array, &conv2d_44_output_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_output, AI_STATIC,
  42, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_45_output_array, &conv2d_45_output_intq)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_output, AI_STATIC,
  43, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 14, 14), AI_STRIDE_INIT(4, 1, 1, 32, 448),
  1, &conv2d_46_output_array, &conv2d_46_output_intq)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_47_output, AI_STATIC,
  44, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 14, 14), AI_STRIDE_INIT(4, 1, 1, 32, 448),
  1, &eltwise_47_output_array, &eltwise_47_output_intq)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_output, AI_STATIC,
  45, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_48_output_array, &conv2d_48_output_intq)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_output, AI_STATIC,
  46, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_49_output_array, &conv2d_49_output_intq)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_50_output, AI_STATIC,
  47, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 14, 14), AI_STRIDE_INIT(4, 1, 1, 32, 448),
  1, &conv2d_50_output_array, &conv2d_50_output_intq)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_51_output, AI_STATIC,
  48, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 14, 14), AI_STRIDE_INIT(4, 1, 1, 32, 448),
  1, &eltwise_51_output_array, &eltwise_51_output_intq)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_output, AI_STATIC,
  49, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_52_output_array, &conv2d_52_output_intq)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_output, AI_STATIC,
  50, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 7, 7), AI_STRIDE_INIT(4, 1, 1, 192, 1344),
  1, &conv2d_54_output_array, &conv2d_54_output_intq)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_output, AI_STATIC,
  51, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 7, 7), AI_STRIDE_INIT(4, 1, 1, 56, 392),
  1, &conv2d_55_output_array, &conv2d_55_output_intq)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_output, AI_STATIC,
  52, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_56_output_array, &conv2d_56_output_intq)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_output, AI_STATIC,
  53, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_57_output_array, &conv2d_57_output_intq)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_58_output, AI_STATIC,
  54, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 7, 7), AI_STRIDE_INIT(4, 1, 1, 56, 392),
  1, &conv2d_58_output_array, &conv2d_58_output_intq)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_59_output, AI_STATIC,
  55, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 7, 7), AI_STRIDE_INIT(4, 1, 1, 56, 392),
  1, &eltwise_59_output_array, &eltwise_59_output_intq)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_output, AI_STATIC,
  56, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_60_output_array, &conv2d_60_output_intq)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_output, AI_STATIC,
  57, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_61_output_array, &conv2d_61_output_intq)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_62_output, AI_STATIC,
  58, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 7, 7), AI_STRIDE_INIT(4, 1, 1, 56, 392),
  1, &conv2d_62_output_array, &conv2d_62_output_intq)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_63_output, AI_STATIC,
  59, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 7, 7), AI_STRIDE_INIT(4, 1, 1, 56, 392),
  1, &eltwise_63_output_array, &eltwise_63_output_intq)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_output, AI_STATIC,
  60, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_64_output_array, &conv2d_64_output_intq)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_output, AI_STATIC,
  61, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_65_output_array, &conv2d_65_output_intq)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_output, AI_STATIC,
  62, 0x1,
  AI_SHAPE_INIT(4, 1, 112, 7, 7), AI_STRIDE_INIT(4, 1, 1, 112, 784),
  1, &conv2d_66_output_array, &conv2d_66_output_intq)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_output, AI_STATIC,
  63, 0x1,
  AI_SHAPE_INIT(4, 1, 1280, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1280, 1280),
  1, &conv2d_67_output_array, &conv2d_67_output_intq)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  dense_69_output, AI_STATIC,
  64, 0x1,
  AI_SHAPE_INIT(4, 1, 100, 1, 1), AI_STRIDE_INIT(4, 1, 1, 100, 100),
  1, &dense_69_output_array, &dense_69_output_intq)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  dense_70_output, AI_STATIC,
  65, 0x1,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5, 5),
  1, &dense_70_output_array, &dense_70_output_intq)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  dense_70_fmt_output, AI_STATIC,
  66, 0x0,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 4, 4, 20, 20),
  1, &dense_70_fmt_output_array, NULL)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  nl_71_output, AI_STATIC,
  67, 0x0,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 4, 4, 20, 20),
  1, &nl_71_output_array, NULL)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  nl_71_fmt_output, AI_STATIC,
  68, 0x1,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5, 5),
  1, &nl_71_fmt_output_array, &nl_71_fmt_output_intq)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights, AI_STATIC,
  69, 0x1,
  AI_SHAPE_INIT(4, 3, 3, 3, 16), AI_STRIDE_INIT(4, 1, 3, 9, 27),
  1, &conv2d_2_weights_array, &conv2d_2_weights_intq)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias, AI_STATIC,
  70, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_2_bias_array, &conv2d_2_bias_intq)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_weights, AI_STATIC,
  71, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 3, 1), AI_STRIDE_INIT(4, 1, 16, 48, 144),
  1, &conv2d_3_weights_array, &conv2d_3_weights_intq)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_bias, AI_STATIC,
  72, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_3_bias_array, &conv2d_3_bias_intq)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_weights, AI_STATIC,
  73, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 8), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &conv2d_4_weights_array, &conv2d_4_weights_intq)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_bias, AI_STATIC,
  74, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_4_bias_array, &conv2d_4_bias_intq)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_weights, AI_STATIC,
  75, 0x1,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 1, 8, 8, 8),
  1, &conv2d_5_weights_array, &conv2d_5_weights_intq)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_bias, AI_STATIC,
  76, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_5_bias_array, &conv2d_5_bias_intq)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_weights, AI_STATIC,
  77, 0x1,
  AI_SHAPE_INIT(4, 48, 3, 3, 1), AI_STRIDE_INIT(4, 1, 48, 144, 432),
  1, &conv2d_7_weights_array, &conv2d_7_weights_intq)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_bias, AI_STATIC,
  78, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_7_bias_array, &conv2d_7_bias_intq)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_weights, AI_STATIC,
  79, 0x1,
  AI_SHAPE_INIT(4, 48, 1, 1, 8), AI_STRIDE_INIT(4, 1, 48, 48, 48),
  1, &conv2d_8_weights_array, &conv2d_8_weights_intq)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_bias, AI_STATIC,
  80, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_8_bias_array, &conv2d_8_bias_intq)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_weights, AI_STATIC,
  81, 0x1,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 1, 8, 8, 8),
  1, &conv2d_9_weights_array, &conv2d_9_weights_intq)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_bias, AI_STATIC,
  82, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_9_bias_array, &conv2d_9_bias_intq)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_weights, AI_STATIC,
  83, 0x1,
  AI_SHAPE_INIT(4, 48, 3, 3, 1), AI_STRIDE_INIT(4, 1, 48, 144, 432),
  1, &conv2d_10_weights_array, &conv2d_10_weights_intq)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_bias, AI_STATIC,
  84, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_10_bias_array, &conv2d_10_bias_intq)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_weights, AI_STATIC,
  85, 0x1,
  AI_SHAPE_INIT(4, 48, 1, 1, 8), AI_STRIDE_INIT(4, 1, 48, 48, 48),
  1, &conv2d_11_weights_array, &conv2d_11_weights_intq)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_bias, AI_STATIC,
  86, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_11_bias_array, &conv2d_11_bias_intq)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_weights, AI_STATIC,
  87, 0x1,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 1, 8, 8, 8),
  1, &conv2d_13_weights_array, &conv2d_13_weights_intq)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_bias, AI_STATIC,
  88, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_13_bias_array, &conv2d_13_bias_intq)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_weights, AI_STATIC,
  89, 0x1,
  AI_SHAPE_INIT(4, 48, 3, 3, 1), AI_STRIDE_INIT(4, 1, 48, 144, 432),
  1, &conv2d_15_weights_array, &conv2d_15_weights_intq)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_bias, AI_STATIC,
  90, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_15_bias_array, &conv2d_15_bias_intq)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_weights, AI_STATIC,
  91, 0x1,
  AI_SHAPE_INIT(4, 48, 1, 1, 16), AI_STRIDE_INIT(4, 1, 48, 48, 48),
  1, &conv2d_16_weights_array, &conv2d_16_weights_intq)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_bias, AI_STATIC,
  92, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_16_bias_array, &conv2d_16_bias_intq)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_weights, AI_STATIC,
  93, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &conv2d_17_weights_array, &conv2d_17_weights_intq)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_bias, AI_STATIC,
  94, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_17_bias_array, &conv2d_17_bias_intq)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_weights, AI_STATIC,
  95, 0x1,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 288, 864),
  1, &conv2d_18_weights_array, &conv2d_18_weights_intq)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_bias, AI_STATIC,
  96, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_18_bias_array, &conv2d_18_bias_intq)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_weights, AI_STATIC,
  97, 0x1,
  AI_SHAPE_INIT(4, 96, 1, 1, 16), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &conv2d_19_weights_array, &conv2d_19_weights_intq)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_bias, AI_STATIC,
  98, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_19_bias_array, &conv2d_19_bias_intq)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_weights, AI_STATIC,
  99, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &conv2d_21_weights_array, &conv2d_21_weights_intq)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_bias, AI_STATIC,
  100, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_21_bias_array, &conv2d_21_bias_intq)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_weights, AI_STATIC,
  101, 0x1,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 288, 864),
  1, &conv2d_22_weights_array, &conv2d_22_weights_intq)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_bias, AI_STATIC,
  102, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_22_bias_array, &conv2d_22_bias_intq)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_weights, AI_STATIC,
  103, 0x1,
  AI_SHAPE_INIT(4, 96, 1, 1, 16), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &conv2d_23_weights_array, &conv2d_23_weights_intq)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_bias, AI_STATIC,
  104, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_23_bias_array, &conv2d_23_bias_intq)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_weights, AI_STATIC,
  105, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &conv2d_25_weights_array, &conv2d_25_weights_intq)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_bias, AI_STATIC,
  106, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_25_bias_array, &conv2d_25_bias_intq)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_weights, AI_STATIC,
  107, 0x1,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 288, 864),
  1, &conv2d_27_weights_array, &conv2d_27_weights_intq)

/* Tensor #108 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_bias, AI_STATIC,
  108, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_27_bias_array, &conv2d_27_bias_intq)

/* Tensor #109 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_weights, AI_STATIC,
  109, 0x1,
  AI_SHAPE_INIT(4, 96, 1, 1, 24), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &conv2d_28_weights_array, &conv2d_28_weights_intq)

/* Tensor #110 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_bias, AI_STATIC,
  110, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_28_bias_array, &conv2d_28_bias_intq)

/* Tensor #111 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_weights, AI_STATIC,
  111, 0x1,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_29_weights_array, &conv2d_29_weights_intq)

/* Tensor #112 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_bias, AI_STATIC,
  112, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_29_bias_array, &conv2d_29_bias_intq)

/* Tensor #113 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_weights, AI_STATIC,
  113, 0x1,
  AI_SHAPE_INIT(4, 144, 3, 3, 1), AI_STRIDE_INIT(4, 1, 144, 432, 1296),
  1, &conv2d_30_weights_array, &conv2d_30_weights_intq)

/* Tensor #114 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_bias, AI_STATIC,
  114, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_30_bias_array, &conv2d_30_bias_intq)

/* Tensor #115 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_weights, AI_STATIC,
  115, 0x1,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 1, 144, 144, 144),
  1, &conv2d_31_weights_array, &conv2d_31_weights_intq)

/* Tensor #116 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_bias, AI_STATIC,
  116, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_31_bias_array, &conv2d_31_bias_intq)

/* Tensor #117 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_weights, AI_STATIC,
  117, 0x1,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_33_weights_array, &conv2d_33_weights_intq)

/* Tensor #118 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_bias, AI_STATIC,
  118, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_33_bias_array, &conv2d_33_bias_intq)

/* Tensor #119 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_weights, AI_STATIC,
  119, 0x1,
  AI_SHAPE_INIT(4, 144, 3, 3, 1), AI_STRIDE_INIT(4, 1, 144, 432, 1296),
  1, &conv2d_34_weights_array, &conv2d_34_weights_intq)

/* Tensor #120 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_bias, AI_STATIC,
  120, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_34_bias_array, &conv2d_34_bias_intq)

/* Tensor #121 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_weights, AI_STATIC,
  121, 0x1,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 1, 144, 144, 144),
  1, &conv2d_35_weights_array, &conv2d_35_weights_intq)

/* Tensor #122 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_bias, AI_STATIC,
  122, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_35_bias_array, &conv2d_35_bias_intq)

/* Tensor #123 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_weights, AI_STATIC,
  123, 0x1,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_37_weights_array, &conv2d_37_weights_intq)

/* Tensor #124 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_bias, AI_STATIC,
  124, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_37_bias_array, &conv2d_37_bias_intq)

/* Tensor #125 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_weights, AI_STATIC,
  125, 0x1,
  AI_SHAPE_INIT(4, 144, 3, 3, 1), AI_STRIDE_INIT(4, 1, 144, 432, 1296),
  1, &conv2d_38_weights_array, &conv2d_38_weights_intq)

/* Tensor #126 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_bias, AI_STATIC,
  126, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_38_bias_array, &conv2d_38_bias_intq)

/* Tensor #127 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_weights, AI_STATIC,
  127, 0x1,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 1, 144, 144, 144),
  1, &conv2d_39_weights_array, &conv2d_39_weights_intq)

/* Tensor #128 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_bias, AI_STATIC,
  128, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_39_bias_array, &conv2d_39_bias_intq)

/* Tensor #129 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_weights, AI_STATIC,
  129, 0x1,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_41_weights_array, &conv2d_41_weights_intq)

/* Tensor #130 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_bias, AI_STATIC,
  130, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_41_bias_array, &conv2d_41_bias_intq)

/* Tensor #131 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_weights, AI_STATIC,
  131, 0x1,
  AI_SHAPE_INIT(4, 144, 3, 3, 1), AI_STRIDE_INIT(4, 1, 144, 432, 1296),
  1, &conv2d_42_weights_array, &conv2d_42_weights_intq)

/* Tensor #132 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_bias, AI_STATIC,
  132, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_42_bias_array, &conv2d_42_bias_intq)

/* Tensor #133 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_weights, AI_STATIC,
  133, 0x1,
  AI_SHAPE_INIT(4, 144, 1, 1, 32), AI_STRIDE_INIT(4, 1, 144, 144, 144),
  1, &conv2d_43_weights_array, &conv2d_43_weights_intq)

/* Tensor #134 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_bias, AI_STATIC,
  134, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_43_bias_array, &conv2d_43_bias_intq)

/* Tensor #135 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_weights, AI_STATIC,
  135, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_44_weights_array, &conv2d_44_weights_intq)

/* Tensor #136 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_bias, AI_STATIC,
  136, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_44_bias_array, &conv2d_44_bias_intq)

/* Tensor #137 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_weights, AI_STATIC,
  137, 0x1,
  AI_SHAPE_INIT(4, 192, 3, 3, 1), AI_STRIDE_INIT(4, 1, 192, 576, 1728),
  1, &conv2d_45_weights_array, &conv2d_45_weights_intq)

/* Tensor #138 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_bias, AI_STATIC,
  138, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_45_bias_array, &conv2d_45_bias_intq)

/* Tensor #139 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_weights, AI_STATIC,
  139, 0x1,
  AI_SHAPE_INIT(4, 192, 1, 1, 32), AI_STRIDE_INIT(4, 1, 192, 192, 192),
  1, &conv2d_46_weights_array, &conv2d_46_weights_intq)

/* Tensor #140 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_bias, AI_STATIC,
  140, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_46_bias_array, &conv2d_46_bias_intq)

/* Tensor #141 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_weights, AI_STATIC,
  141, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_48_weights_array, &conv2d_48_weights_intq)

/* Tensor #142 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_bias, AI_STATIC,
  142, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_48_bias_array, &conv2d_48_bias_intq)

/* Tensor #143 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_weights, AI_STATIC,
  143, 0x1,
  AI_SHAPE_INIT(4, 192, 3, 3, 1), AI_STRIDE_INIT(4, 1, 192, 576, 1728),
  1, &conv2d_49_weights_array, &conv2d_49_weights_intq)

/* Tensor #144 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_bias, AI_STATIC,
  144, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_49_bias_array, &conv2d_49_bias_intq)

/* Tensor #145 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_50_weights, AI_STATIC,
  145, 0x1,
  AI_SHAPE_INIT(4, 192, 1, 1, 32), AI_STRIDE_INIT(4, 1, 192, 192, 192),
  1, &conv2d_50_weights_array, &conv2d_50_weights_intq)

/* Tensor #146 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_50_bias, AI_STATIC,
  146, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_50_bias_array, &conv2d_50_bias_intq)

/* Tensor #147 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_weights, AI_STATIC,
  147, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_52_weights_array, &conv2d_52_weights_intq)

/* Tensor #148 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_bias, AI_STATIC,
  148, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_52_bias_array, &conv2d_52_bias_intq)

/* Tensor #149 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_weights, AI_STATIC,
  149, 0x1,
  AI_SHAPE_INIT(4, 192, 3, 3, 1), AI_STRIDE_INIT(4, 1, 192, 576, 1728),
  1, &conv2d_54_weights_array, &conv2d_54_weights_intq)

/* Tensor #150 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_bias, AI_STATIC,
  150, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_54_bias_array, &conv2d_54_bias_intq)

/* Tensor #151 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_weights, AI_STATIC,
  151, 0x1,
  AI_SHAPE_INIT(4, 192, 1, 1, 56), AI_STRIDE_INIT(4, 1, 192, 192, 192),
  1, &conv2d_55_weights_array, &conv2d_55_weights_intq)

/* Tensor #152 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_bias, AI_STATIC,
  152, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_55_bias_array, &conv2d_55_bias_intq)

/* Tensor #153 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_weights, AI_STATIC,
  153, 0x1,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 1, 56, 56, 56),
  1, &conv2d_56_weights_array, &conv2d_56_weights_intq)

/* Tensor #154 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_bias, AI_STATIC,
  154, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_56_bias_array, &conv2d_56_bias_intq)

/* Tensor #155 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_weights, AI_STATIC,
  155, 0x1,
  AI_SHAPE_INIT(4, 336, 3, 3, 1), AI_STRIDE_INIT(4, 1, 336, 1008, 3024),
  1, &conv2d_57_weights_array, &conv2d_57_weights_intq)

/* Tensor #156 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_bias, AI_STATIC,
  156, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_57_bias_array, &conv2d_57_bias_intq)

/* Tensor #157 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_58_weights, AI_STATIC,
  157, 0x1,
  AI_SHAPE_INIT(4, 336, 1, 1, 56), AI_STRIDE_INIT(4, 1, 336, 336, 336),
  1, &conv2d_58_weights_array, &conv2d_58_weights_intq)

/* Tensor #158 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_58_bias, AI_STATIC,
  158, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_58_bias_array, &conv2d_58_bias_intq)

/* Tensor #159 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_weights, AI_STATIC,
  159, 0x1,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 1, 56, 56, 56),
  1, &conv2d_60_weights_array, &conv2d_60_weights_intq)

/* Tensor #160 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_bias, AI_STATIC,
  160, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_60_bias_array, &conv2d_60_bias_intq)

/* Tensor #161 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_weights, AI_STATIC,
  161, 0x1,
  AI_SHAPE_INIT(4, 336, 3, 3, 1), AI_STRIDE_INIT(4, 1, 336, 1008, 3024),
  1, &conv2d_61_weights_array, &conv2d_61_weights_intq)

/* Tensor #162 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_bias, AI_STATIC,
  162, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_61_bias_array, &conv2d_61_bias_intq)

/* Tensor #163 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_62_weights, AI_STATIC,
  163, 0x1,
  AI_SHAPE_INIT(4, 336, 1, 1, 56), AI_STRIDE_INIT(4, 1, 336, 336, 336),
  1, &conv2d_62_weights_array, &conv2d_62_weights_intq)

/* Tensor #164 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_62_bias, AI_STATIC,
  164, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_62_bias_array, &conv2d_62_bias_intq)

/* Tensor #165 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_weights, AI_STATIC,
  165, 0x1,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 1, 56, 56, 56),
  1, &conv2d_64_weights_array, &conv2d_64_weights_intq)

/* Tensor #166 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_bias, AI_STATIC,
  166, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_64_bias_array, &conv2d_64_bias_intq)

/* Tensor #167 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_weights, AI_STATIC,
  167, 0x1,
  AI_SHAPE_INIT(4, 336, 3, 3, 1), AI_STRIDE_INIT(4, 1, 336, 1008, 3024),
  1, &conv2d_65_weights_array, &conv2d_65_weights_intq)

/* Tensor #168 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_bias, AI_STATIC,
  168, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_65_bias_array, &conv2d_65_bias_intq)

/* Tensor #169 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_weights, AI_STATIC,
  169, 0x1,
  AI_SHAPE_INIT(4, 336, 1, 1, 112), AI_STRIDE_INIT(4, 1, 336, 336, 336),
  1, &conv2d_66_weights_array, &conv2d_66_weights_intq)

/* Tensor #170 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_bias, AI_STATIC,
  170, 0x1,
  AI_SHAPE_INIT(4, 1, 112, 1, 1), AI_STRIDE_INIT(4, 4, 4, 448, 448),
  1, &conv2d_66_bias_array, &conv2d_66_bias_intq)

/* Tensor #171 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_weights, AI_STATIC,
  171, 0x1,
  AI_SHAPE_INIT(4, 112, 1, 1, 1280), AI_STRIDE_INIT(4, 1, 112, 112, 112),
  1, &conv2d_67_weights_array, &conv2d_67_weights_intq)

/* Tensor #172 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_bias, AI_STATIC,
  172, 0x1,
  AI_SHAPE_INIT(4, 1, 1280, 1, 1), AI_STRIDE_INIT(4, 4, 4, 5120, 5120),
  1, &conv2d_67_bias_array, &conv2d_67_bias_intq)

/* Tensor #173 */
AI_TENSOR_OBJ_DECLARE(
  dense_69_weights, AI_STATIC,
  173, 0x1,
  AI_SHAPE_INIT(4, 1280, 100, 1, 1), AI_STRIDE_INIT(4, 1, 1280, 128000, 128000),
  1, &dense_69_weights_array, &dense_69_weights_intq)

/* Tensor #174 */
AI_TENSOR_OBJ_DECLARE(
  dense_69_bias, AI_STATIC,
  174, 0x1,
  AI_SHAPE_INIT(4, 1, 100, 1, 1), AI_STRIDE_INIT(4, 4, 4, 400, 400),
  1, &dense_69_bias_array, &dense_69_bias_intq)

/* Tensor #175 */
AI_TENSOR_OBJ_DECLARE(
  dense_70_weights, AI_STATIC,
  175, 0x1,
  AI_SHAPE_INIT(4, 100, 5, 1, 1), AI_STRIDE_INIT(4, 1, 100, 500, 500),
  1, &dense_70_weights_array, &dense_70_weights_intq)

/* Tensor #176 */
AI_TENSOR_OBJ_DECLARE(
  dense_70_bias, AI_STATIC,
  176, 0x1,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 4, 4, 20, 20),
  1, &dense_70_bias_array, &dense_70_bias_intq)

/* Tensor #177 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch0, AI_STATIC,
  177, 0x0,
  AI_SHAPE_INIT(4, 1, 1196, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1196, 1196),
  1, &conv2d_2_scratch0_array, NULL)

/* Tensor #178 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch1, AI_STATIC,
  178, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 112, 112), AI_STRIDE_INIT(4, 1, 1, 16, 1792),
  1, &conv2d_2_scratch1_array, &conv2d_2_scratch1_intq)

/* Tensor #179 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch0, AI_STATIC,
  179, 0x0,
  AI_SHAPE_INIT(4, 1, 593, 1, 1), AI_STRIDE_INIT(4, 1, 1, 593, 593),
  1, &conv2d_3_scratch0_array, NULL)

/* Tensor #180 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch1, AI_STATIC,
  180, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 112, 112), AI_STRIDE_INIT(4, 1, 1, 16, 1792),
  1, &conv2d_3_scratch1_array, &conv2d_3_scratch1_intq)

/* Tensor #181 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch0, AI_STATIC,
  181, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 1, 1, 144, 144),
  1, &conv2d_4_scratch0_array, NULL)

/* Tensor #182 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch0, AI_STATIC,
  182, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_5_scratch0_array, NULL)

/* Tensor #183 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch1, AI_STATIC,
  183, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 112, 112), AI_STRIDE_INIT(4, 1, 1, 48, 5376),
  1, &conv2d_5_scratch1_array, &conv2d_5_scratch1_intq)

/* Tensor #184 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch0, AI_STATIC,
  184, 0x0,
  AI_SHAPE_INIT(4, 1, 1777, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1777, 1777),
  1, &conv2d_7_scratch0_array, NULL)

/* Tensor #185 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch1, AI_STATIC,
  185, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 56, 56), AI_STRIDE_INIT(4, 1, 1, 48, 2688),
  1, &conv2d_7_scratch1_array, &conv2d_7_scratch1_intq)

/* Tensor #186 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_scratch0, AI_STATIC,
  186, 0x0,
  AI_SHAPE_INIT(4, 1, 272, 1, 1), AI_STRIDE_INIT(4, 1, 1, 272, 272),
  1, &conv2d_8_scratch0_array, NULL)

/* Tensor #187 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch0, AI_STATIC,
  187, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_9_scratch0_array, NULL)

/* Tensor #188 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch1, AI_STATIC,
  188, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 56, 56), AI_STRIDE_INIT(4, 1, 1, 48, 2688),
  1, &conv2d_9_scratch1_array, &conv2d_9_scratch1_intq)

/* Tensor #189 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_scratch0, AI_STATIC,
  189, 0x0,
  AI_SHAPE_INIT(4, 1, 1777, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1777, 1777),
  1, &conv2d_10_scratch0_array, NULL)

/* Tensor #190 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_scratch1, AI_STATIC,
  190, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 56, 56), AI_STRIDE_INIT(4, 1, 1, 48, 2688),
  1, &conv2d_10_scratch1_array, &conv2d_10_scratch1_intq)

/* Tensor #191 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_scratch0, AI_STATIC,
  191, 0x0,
  AI_SHAPE_INIT(4, 1, 272, 1, 1), AI_STRIDE_INIT(4, 1, 1, 272, 272),
  1, &conv2d_11_scratch0_array, NULL)

/* Tensor #192 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_scratch0, AI_STATIC,
  192, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_13_scratch0_array, NULL)

/* Tensor #193 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_scratch1, AI_STATIC,
  193, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 56, 56), AI_STRIDE_INIT(4, 1, 1, 48, 2688),
  1, &conv2d_13_scratch1_array, &conv2d_13_scratch1_intq)

/* Tensor #194 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_scratch0, AI_STATIC,
  194, 0x0,
  AI_SHAPE_INIT(4, 1, 1777, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1777, 1777),
  1, &conv2d_15_scratch0_array, NULL)

/* Tensor #195 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_scratch1, AI_STATIC,
  195, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 28, 28), AI_STRIDE_INIT(4, 1, 1, 48, 1344),
  1, &conv2d_15_scratch1_array, &conv2d_15_scratch1_intq)

/* Tensor #196 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_scratch0, AI_STATIC,
  196, 0x0,
  AI_SHAPE_INIT(4, 1, 352, 1, 1), AI_STRIDE_INIT(4, 1, 1, 352, 352),
  1, &conv2d_16_scratch0_array, NULL)

/* Tensor #197 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch0, AI_STATIC,
  197, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_17_scratch0_array, NULL)

/* Tensor #198 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch1, AI_STATIC,
  198, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_17_scratch1_array, &conv2d_17_scratch1_intq)

/* Tensor #199 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch0, AI_STATIC,
  199, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_18_scratch0_array, NULL)

/* Tensor #200 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch1, AI_STATIC,
  200, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_18_scratch1_array, &conv2d_18_scratch1_intq)

/* Tensor #201 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_scratch0, AI_STATIC,
  201, 0x0,
  AI_SHAPE_INIT(4, 1, 544, 1, 1), AI_STRIDE_INIT(4, 1, 1, 544, 544),
  1, &conv2d_19_scratch0_array, NULL)

/* Tensor #202 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch0, AI_STATIC,
  202, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_21_scratch0_array, NULL)

/* Tensor #203 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch1, AI_STATIC,
  203, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_21_scratch1_array, &conv2d_21_scratch1_intq)

/* Tensor #204 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_scratch0, AI_STATIC,
  204, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_22_scratch0_array, NULL)

/* Tensor #205 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_scratch1, AI_STATIC,
  205, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_22_scratch1_array, &conv2d_22_scratch1_intq)

/* Tensor #206 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_scratch0, AI_STATIC,
  206, 0x0,
  AI_SHAPE_INIT(4, 1, 544, 1, 1), AI_STRIDE_INIT(4, 1, 1, 544, 544),
  1, &conv2d_23_scratch0_array, NULL)

/* Tensor #207 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_scratch0, AI_STATIC,
  207, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_25_scratch0_array, NULL)

/* Tensor #208 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_scratch1, AI_STATIC,
  208, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_25_scratch1_array, &conv2d_25_scratch1_intq)

/* Tensor #209 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_scratch0, AI_STATIC,
  209, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_27_scratch0_array, NULL)

/* Tensor #210 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_scratch1, AI_STATIC,
  210, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 14, 14), AI_STRIDE_INIT(4, 1, 1, 96, 1344),
  1, &conv2d_27_scratch1_array, &conv2d_27_scratch1_intq)

/* Tensor #211 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_scratch0, AI_STATIC,
  211, 0x0,
  AI_SHAPE_INIT(4, 1, 624, 1, 1), AI_STRIDE_INIT(4, 1, 1, 624, 624),
  1, &conv2d_28_scratch0_array, NULL)

/* Tensor #212 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_scratch0, AI_STATIC,
  212, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_29_scratch0_array, NULL)

/* Tensor #213 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_scratch1, AI_STATIC,
  213, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_29_scratch1_array, &conv2d_29_scratch1_intq)

/* Tensor #214 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_scratch0, AI_STATIC,
  214, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_30_scratch0_array, NULL)

/* Tensor #215 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_scratch1, AI_STATIC,
  215, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_30_scratch1_array, &conv2d_30_scratch1_intq)

/* Tensor #216 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_scratch0, AI_STATIC,
  216, 0x0,
  AI_SHAPE_INIT(4, 1, 816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 816, 816),
  1, &conv2d_31_scratch0_array, NULL)

/* Tensor #217 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_scratch0, AI_STATIC,
  217, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_33_scratch0_array, NULL)

/* Tensor #218 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_scratch1, AI_STATIC,
  218, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_33_scratch1_array, &conv2d_33_scratch1_intq)

/* Tensor #219 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_scratch0, AI_STATIC,
  219, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_34_scratch0_array, NULL)

/* Tensor #220 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_scratch1, AI_STATIC,
  220, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_34_scratch1_array, &conv2d_34_scratch1_intq)

/* Tensor #221 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_scratch0, AI_STATIC,
  221, 0x0,
  AI_SHAPE_INIT(4, 1, 816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 816, 816),
  1, &conv2d_35_scratch0_array, NULL)

/* Tensor #222 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_scratch0, AI_STATIC,
  222, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_37_scratch0_array, NULL)

/* Tensor #223 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_scratch1, AI_STATIC,
  223, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_37_scratch1_array, &conv2d_37_scratch1_intq)

/* Tensor #224 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_scratch0, AI_STATIC,
  224, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_38_scratch0_array, NULL)

/* Tensor #225 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_scratch1, AI_STATIC,
  225, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_38_scratch1_array, &conv2d_38_scratch1_intq)

/* Tensor #226 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_scratch0, AI_STATIC,
  226, 0x0,
  AI_SHAPE_INIT(4, 1, 816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 816, 816),
  1, &conv2d_39_scratch0_array, NULL)

/* Tensor #227 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_scratch0, AI_STATIC,
  227, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_41_scratch0_array, NULL)

/* Tensor #228 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_scratch1, AI_STATIC,
  228, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_41_scratch1_array, &conv2d_41_scratch1_intq)

/* Tensor #229 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_scratch0, AI_STATIC,
  229, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_42_scratch0_array, NULL)

/* Tensor #230 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_scratch1, AI_STATIC,
  230, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_42_scratch1_array, &conv2d_42_scratch1_intq)

/* Tensor #231 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_scratch0, AI_STATIC,
  231, 0x0,
  AI_SHAPE_INIT(4, 1, 896, 1, 1), AI_STRIDE_INIT(4, 1, 1, 896, 896),
  1, &conv2d_43_scratch0_array, NULL)

/* Tensor #232 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_scratch0, AI_STATIC,
  232, 0x0,
  AI_SHAPE_INIT(4, 1, 2048, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2048, 2048),
  1, &conv2d_44_scratch0_array, NULL)

/* Tensor #233 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_scratch1, AI_STATIC,
  233, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_44_scratch1_array, &conv2d_44_scratch1_intq)

/* Tensor #234 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_scratch0, AI_STATIC,
  234, 0x0,
  AI_SHAPE_INIT(4, 1, 7105, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7105, 7105),
  1, &conv2d_45_scratch0_array, NULL)

/* Tensor #235 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_scratch1, AI_STATIC,
  235, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_45_scratch1_array, &conv2d_45_scratch1_intq)

/* Tensor #236 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_scratch0, AI_STATIC,
  236, 0x0,
  AI_SHAPE_INIT(4, 1, 1088, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1088, 1088),
  1, &conv2d_46_scratch0_array, NULL)

/* Tensor #237 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_scratch0, AI_STATIC,
  237, 0x0,
  AI_SHAPE_INIT(4, 1, 2048, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2048, 2048),
  1, &conv2d_48_scratch0_array, NULL)

/* Tensor #238 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_scratch1, AI_STATIC,
  238, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_48_scratch1_array, &conv2d_48_scratch1_intq)

/* Tensor #239 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_scratch0, AI_STATIC,
  239, 0x0,
  AI_SHAPE_INIT(4, 1, 7105, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7105, 7105),
  1, &conv2d_49_scratch0_array, NULL)

/* Tensor #240 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_scratch1, AI_STATIC,
  240, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_49_scratch1_array, &conv2d_49_scratch1_intq)

/* Tensor #241 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_50_scratch0, AI_STATIC,
  241, 0x0,
  AI_SHAPE_INIT(4, 1, 1088, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1088, 1088),
  1, &conv2d_50_scratch0_array, NULL)

/* Tensor #242 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_scratch0, AI_STATIC,
  242, 0x0,
  AI_SHAPE_INIT(4, 1, 2048, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2048, 2048),
  1, &conv2d_52_scratch0_array, NULL)

/* Tensor #243 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_scratch1, AI_STATIC,
  243, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_52_scratch1_array, &conv2d_52_scratch1_intq)

/* Tensor #244 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_scratch0, AI_STATIC,
  244, 0x0,
  AI_SHAPE_INIT(4, 1, 7105, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7105, 7105),
  1, &conv2d_54_scratch0_array, NULL)

/* Tensor #245 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_scratch1, AI_STATIC,
  245, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 7, 7), AI_STRIDE_INIT(4, 1, 1, 192, 1344),
  1, &conv2d_54_scratch1_array, &conv2d_54_scratch1_intq)

/* Tensor #246 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_scratch0, AI_STATIC,
  246, 0x0,
  AI_SHAPE_INIT(4, 1, 1328, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1328, 1328),
  1, &conv2d_55_scratch0_array, NULL)

/* Tensor #247 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_scratch0, AI_STATIC,
  247, 0x0,
  AI_SHAPE_INIT(4, 1, 3584, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3584, 3584),
  1, &conv2d_56_scratch0_array, NULL)

/* Tensor #248 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_scratch1, AI_STATIC,
  248, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_56_scratch1_array, &conv2d_56_scratch1_intq)

/* Tensor #249 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_scratch0, AI_STATIC,
  249, 0x0,
  AI_SHAPE_INIT(4, 1, 12433, 1, 1), AI_STRIDE_INIT(4, 1, 1, 12433, 12433),
  1, &conv2d_57_scratch0_array, NULL)

/* Tensor #250 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_scratch1, AI_STATIC,
  250, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_57_scratch1_array, &conv2d_57_scratch1_intq)

/* Tensor #251 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_58_scratch0, AI_STATIC,
  251, 0x0,
  AI_SHAPE_INIT(4, 1, 1904, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1904, 1904),
  1, &conv2d_58_scratch0_array, NULL)

/* Tensor #252 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_scratch0, AI_STATIC,
  252, 0x0,
  AI_SHAPE_INIT(4, 1, 3584, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3584, 3584),
  1, &conv2d_60_scratch0_array, NULL)

/* Tensor #253 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_scratch1, AI_STATIC,
  253, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_60_scratch1_array, &conv2d_60_scratch1_intq)

/* Tensor #254 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_scratch0, AI_STATIC,
  254, 0x0,
  AI_SHAPE_INIT(4, 1, 12433, 1, 1), AI_STRIDE_INIT(4, 1, 1, 12433, 12433),
  1, &conv2d_61_scratch0_array, NULL)

/* Tensor #255 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_scratch1, AI_STATIC,
  255, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_61_scratch1_array, &conv2d_61_scratch1_intq)

/* Tensor #256 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_62_scratch0, AI_STATIC,
  256, 0x0,
  AI_SHAPE_INIT(4, 1, 1904, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1904, 1904),
  1, &conv2d_62_scratch0_array, NULL)

/* Tensor #257 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_scratch0, AI_STATIC,
  257, 0x0,
  AI_SHAPE_INIT(4, 1, 3584, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3584, 3584),
  1, &conv2d_64_scratch0_array, NULL)

/* Tensor #258 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_scratch1, AI_STATIC,
  258, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_64_scratch1_array, &conv2d_64_scratch1_intq)

/* Tensor #259 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_scratch0, AI_STATIC,
  259, 0x0,
  AI_SHAPE_INIT(4, 1, 12433, 1, 1), AI_STRIDE_INIT(4, 1, 1, 12433, 12433),
  1, &conv2d_65_scratch0_array, NULL)

/* Tensor #260 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_scratch1, AI_STATIC,
  260, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_65_scratch1_array, &conv2d_65_scratch1_intq)

/* Tensor #261 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_scratch0, AI_STATIC,
  261, 0x0,
  AI_SHAPE_INIT(4, 1, 2464, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2464, 2464),
  1, &conv2d_66_scratch0_array, NULL)

/* Tensor #262 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_scratch0, AI_STATIC,
  262, 0x0,
  AI_SHAPE_INIT(4, 1, 13248, 1, 1), AI_STRIDE_INIT(4, 1, 1, 13248, 13248),
  1, &conv2d_67_scratch0_array, NULL)

/* Tensor #263 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_scratch1, AI_STATIC,
  263, 0x1,
  AI_SHAPE_INIT(4, 1, 1280, 7, 7), AI_STRIDE_INIT(4, 1, 1, 1280, 8960),
  1, &conv2d_67_scratch1_array, &conv2d_67_scratch1_intq)

/* Tensor #264 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_scratch2, AI_STATIC,
  264, 0x1,
  AI_SHAPE_INIT(4, 1, 1280, 7, 7), AI_STRIDE_INIT(4, 1, 1, 1280, 8960),
  1, &conv2d_67_scratch2_array, &conv2d_67_scratch2_intq)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_sequential_17_input0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_0_layer, 0,
  NL_TYPE, 0x0, NULL,
  nl, node_convert_integer,
  &conversion_0_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_2_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_2_weights, &conv2d_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_2_scratch0, &conv2d_2_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_layer, 2,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_2_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_3_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_3_weights, &conv2d_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_3_scratch0, &conv2d_3_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_3_layer, 3,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_3_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_4_layer, AI_STATIC, 
  .groups = 16, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_4_weights, &conv2d_4_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_4_layer, 4,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_4_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_5_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_5_weights, &conv2d_5_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_5_scratch0, &conv2d_5_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_5_layer, 5,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_5_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_7_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_7_weights, &conv2d_7_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_7_scratch0, &conv2d_7_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_7_layer, 7,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_7_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_8_layer, AI_STATIC, 
  .groups = 48, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_8_output, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_8_weights, &conv2d_8_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_8_layer, 8,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_8_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_9_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_9_weights, &conv2d_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_9_scratch0, &conv2d_9_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_layer, 9,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_9_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_10_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_10_weights, &conv2d_10_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_10_scratch0, &conv2d_10_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_10_layer, 10,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_10_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_11_layer, AI_STATIC, 
  .groups = 48, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_11_weights, &conv2d_11_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_11_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_11_layer, 11,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_11_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_12_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_8_output, &conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_12_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_12_layer, 12,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_12_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_13_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_13_weights, &conv2d_13_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_13_scratch0, &conv2d_13_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_13_layer, 13,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_13_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_15_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_15_weights, &conv2d_15_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_15_scratch0, &conv2d_15_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_15_layer, 15,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_15_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_16_layer, AI_STATIC, 
  .groups = 48, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_16_output, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_16_weights, &conv2d_16_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_16_layer, 16,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_16_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_17_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_17_weights, &conv2d_17_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_17_scratch0, &conv2d_17_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_17_layer, 17,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_17_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_18_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_18_weights, &conv2d_18_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_18_scratch0, &conv2d_18_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_18_layer, 18,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_18_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_19_layer, AI_STATIC, 
  .groups = 96, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_19_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_19_weights, &conv2d_19_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_19_layer, 19,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_19_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_20_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_16_output, &conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_20_output, &eltwise_20_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_20_layer, 20,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_20_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_21_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_21_weights, &conv2d_21_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_21_scratch0, &conv2d_21_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_21_layer, 21,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_21_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_22_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_22_weights, &conv2d_22_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_22_scratch0, &conv2d_22_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_22_layer, 22,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_22_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_23_layer, AI_STATIC, 
  .groups = 96, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_23_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_23_weights, &conv2d_23_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_23_layer, 23,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_23_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_24_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_20_output, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_24_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_24_layer, 24,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_24_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_25_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_25_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_25_weights, &conv2d_25_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_25_scratch0, &conv2d_25_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_25_layer, 25,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_25_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_27_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_27_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_27_weights, &conv2d_27_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_27_scratch0, &conv2d_27_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_27_layer, 27,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_27_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_28_layer, AI_STATIC, 
  .groups = 96, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_28_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_28_output, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_28_weights, &conv2d_28_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_28_layer, 28,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_28_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_29_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_29_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_29_weights, &conv2d_29_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_29_scratch0, &conv2d_29_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_29_layer, 29,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_29_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_30_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_30_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_30_weights, &conv2d_30_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_30_scratch0, &conv2d_30_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_30_layer, 30,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_30_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_31_layer, AI_STATIC, 
  .groups = 144, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_31_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_31_weights, &conv2d_31_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_31_layer, 31,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_31_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_32_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_32_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_28_output, &conv2d_31_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_32_output, &eltwise_32_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_32_layer, 32,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_32_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_33_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_33_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_33_weights, &conv2d_33_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_33_scratch0, &conv2d_33_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_33_layer, 33,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_33_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_34_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_34_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_34_weights, &conv2d_34_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_34_scratch0, &conv2d_34_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_34_layer, 34,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_34_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_35_layer, AI_STATIC, 
  .groups = 144, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_35_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_35_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_35_weights, &conv2d_35_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_35_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_35_layer, 35,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_35_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_36_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_36_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_32_output, &conv2d_35_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_36_output, &eltwise_36_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_36_layer, 36,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_36_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_37_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_37_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_36_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_37_weights, &conv2d_37_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_37_scratch0, &conv2d_37_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_37_layer, 37,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_37_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_38_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_38_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_38_weights, &conv2d_38_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_38_scratch0, &conv2d_38_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_38_layer, 38,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_38_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_39_layer, AI_STATIC, 
  .groups = 144, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_39_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_39_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_39_weights, &conv2d_39_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_39_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_39_layer, 39,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_39_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_40_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_40_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_36_output, &conv2d_39_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_40_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_40_layer, 40,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_40_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_41_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_41_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_40_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_41_weights, &conv2d_41_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_41_scratch0, &conv2d_41_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_41_layer, 41,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_41_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_42_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_42_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_42_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_42_weights, &conv2d_42_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_42_scratch0, &conv2d_42_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_42_layer, 42,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_42_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_43_layer, AI_STATIC, 
  .groups = 144, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_43_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_42_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_43_output, &conv2d_43_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_43_weights, &conv2d_43_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_43_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_43_layer, 43,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_43_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_44_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_44_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_43_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_44_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_44_weights, &conv2d_44_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_44_scratch0, &conv2d_44_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_44_layer, 44,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_44_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_45_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_45_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_44_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_45_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_45_weights, &conv2d_45_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_45_scratch0, &conv2d_45_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_45_layer, 45,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_45_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_46_layer, AI_STATIC, 
  .groups = 192, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_46_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_45_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_46_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_46_weights, &conv2d_46_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_46_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_46_layer, 46,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_46_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_47_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_47_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_43_output, &conv2d_46_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_47_output, &eltwise_47_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_47_layer, 47,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_47_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_48_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_48_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_47_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_48_weights, &conv2d_48_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_48_scratch0, &conv2d_48_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_48_layer, 48,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_48_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_49_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_49_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_49_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_49_weights, &conv2d_49_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_49_scratch0, &conv2d_49_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_49_layer, 49,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_49_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_50_layer, AI_STATIC, 
  .groups = 192, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_50_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_49_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_50_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_50_weights, &conv2d_50_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_50_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_50_layer, 50,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_50_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_51_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_51_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_47_output, &conv2d_50_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_51_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_51_layer, 51,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_51_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_52_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_52_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_51_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_52_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_52_weights, &conv2d_52_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_52_scratch0, &conv2d_52_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_52_layer, 52,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_52_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_54_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_54_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_52_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_54_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_54_weights, &conv2d_54_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_54_scratch0, &conv2d_54_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_54_layer, 54,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_54_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_55_layer, AI_STATIC, 
  .groups = 192, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_55_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_54_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_55_output, &conv2d_55_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_55_weights, &conv2d_55_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_55_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_55_layer, 55,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_55_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_56_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_56_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_55_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_56_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_56_weights, &conv2d_56_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_56_scratch0, &conv2d_56_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_56_layer, 56,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_56_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_57_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_57_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_56_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_57_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_57_weights, &conv2d_57_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_57_scratch0, &conv2d_57_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_57_layer, 57,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_57_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_58_layer, AI_STATIC, 
  .groups = 336, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_58_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_57_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_58_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_58_weights, &conv2d_58_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_58_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_58_layer, 58,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_58_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_59_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_59_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_55_output, &conv2d_58_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_59_output, &eltwise_59_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_59_layer, 59,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_59_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_60_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_60_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_59_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_60_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_60_weights, &conv2d_60_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_60_scratch0, &conv2d_60_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_60_layer, 60,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_60_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_61_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_61_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_60_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_61_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_61_weights, &conv2d_61_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_61_scratch0, &conv2d_61_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_61_layer, 61,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_61_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_62_layer, AI_STATIC, 
  .groups = 336, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_62_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_61_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_62_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_62_weights, &conv2d_62_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_62_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_62_layer, 62,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_62_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_63_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_63_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_59_output, &conv2d_62_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_63_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_63_layer, 63,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_63_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_64_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_64_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_63_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_64_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_64_weights, &conv2d_64_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_64_scratch0, &conv2d_64_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_64_layer, 64,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_64_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_65_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_65_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_64_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_65_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_65_weights, &conv2d_65_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_65_scratch0, &conv2d_65_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_65_layer, 65,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_65_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_66_layer, AI_STATIC, 
  .groups = 336, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_66_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_65_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_66_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_66_weights, &conv2d_66_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_66_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_66_layer, 66,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_66_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_67_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_67_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_66_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_67_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_67_weights, &conv2d_67_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_67_scratch0, &conv2d_67_scratch1, &conv2d_67_scratch2)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_67_layer, 68,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_nl_pool_integer_SSSA_ch,
  &conv2d_67_chain,
  &AI_NET_OBJ_INSTANCE, &dense_69_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(7, 7), 
  .pool_stride = AI_SHAPE_2D_INIT(7, 7), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_ap_array_integer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_69_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_67_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_69_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_69_weights, &dense_69_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_69_layer, 69,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &dense_69_chain,
  &AI_NET_OBJ_INSTANCE, &dense_70_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_70_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_69_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_70_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_70_weights, &dense_70_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_70_layer, 70,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &dense_70_chain,
  &AI_NET_OBJ_INSTANCE, &dense_70_fmt_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_70_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_70_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_70_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_70_fmt_layer, 70,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &dense_70_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &nl_71_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_71_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_70_fmt_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_71_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_71_layer, 71,
  NL_TYPE, 0x0, NULL,
  nl, forward_sm,
  &nl_71_chain,
  &AI_NET_OBJ_INSTANCE, &nl_71_fmt_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_71_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_71_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_71_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_71_fmt_layer, 71,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &nl_71_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &nl_71_fmt_layer, AI_STATIC, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 539128, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 610784, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &serving_default_sequential_17_input0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &nl_71_fmt_output),
  &conversion_0_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool network_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, 4));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    serving_default_sequential_17_input0_output_array.data = AI_PTR(NULL);
    serving_default_sequential_17_input0_output_array.data_start = AI_PTR(NULL);
    conversion_0_output_array.data = AI_PTR(activations + 364672);
    conversion_0_output_array.data_start = AI_PTR(activations + 364672);
    conv2d_2_output_array.data = AI_PTR(activations + 312688);
    conv2d_2_output_array.data_start = AI_PTR(activations + 312688);
    conv2d_3_output_array.data = AI_PTR(activations + 309072);
    conv2d_3_output_array.data_start = AI_PTR(activations + 309072);
    conv2d_4_output_array.data = AI_PTR(activations + 509920);
    conv2d_4_output_array.data_start = AI_PTR(activations + 509920);
    conv2d_5_output_array.data = AI_PTR(activations + 2736);
    conv2d_5_output_array.data_start = AI_PTR(activations + 2736);
    conv2d_7_output_array.data = AI_PTR(activations + 0);
    conv2d_7_output_array.data_start = AI_PTR(activations + 0);
    conv2d_8_output_array.data = AI_PTR(activations + 150800);
    conv2d_8_output_array.data_start = AI_PTR(activations + 150800);
    conv2d_9_output_array.data = AI_PTR(activations + 326416);
    conv2d_9_output_array.data_start = AI_PTR(activations + 326416);
    conv2d_10_output_array.data = AI_PTR(activations + 175888);
    conv2d_10_output_array.data_start = AI_PTR(activations + 175888);
    conv2d_11_output_array.data = AI_PTR(activations + 272);
    conv2d_11_output_array.data_start = AI_PTR(activations + 272);
    eltwise_12_output_array.data = AI_PTR(activations + 25360);
    eltwise_12_output_array.data_start = AI_PTR(activations + 25360);
    conv2d_13_output_array.data = AI_PTR(activations + 200976);
    conv2d_13_output_array.data_start = AI_PTR(activations + 200976);
    conv2d_15_output_array.data = AI_PTR(activations + 39412);
    conv2d_15_output_array.data_start = AI_PTR(activations + 39412);
    conv2d_16_output_array.data = AI_PTR(activations + 352);
    conv2d_16_output_array.data_start = AI_PTR(activations + 352);
    conv2d_17_output_array.data = AI_PTR(activations + 89184);
    conv2d_17_output_array.data_start = AI_PTR(activations + 89184);
    conv2d_18_output_array.data = AI_PTR(activations + 239712);
    conv2d_18_output_array.data_start = AI_PTR(activations + 239712);
    conv2d_19_output_array.data = AI_PTR(activations + 13440);
    conv2d_19_output_array.data_start = AI_PTR(activations + 13440);
    eltwise_20_output_array.data = AI_PTR(activations + 25984);
    eltwise_20_output_array.data_start = AI_PTR(activations + 25984);
    conv2d_21_output_array.data = AI_PTR(activations + 113792);
    conv2d_21_output_array.data_start = AI_PTR(activations + 113792);
    conv2d_22_output_array.data = AI_PTR(activations + 189056);
    conv2d_22_output_array.data_start = AI_PTR(activations + 189056);
    conv2d_23_output_array.data = AI_PTR(activations + 544);
    conv2d_23_output_array.data_start = AI_PTR(activations + 544);
    eltwise_24_output_array.data = AI_PTR(activations + 13088);
    eltwise_24_output_array.data_start = AI_PTR(activations + 13088);
    conv2d_25_output_array.data = AI_PTR(activations + 100896);
    conv2d_25_output_array.data_start = AI_PTR(activations + 100896);
    conv2d_27_output_array.data = AI_PTR(activations + 22372);
    conv2d_27_output_array.data_start = AI_PTR(activations + 22372);
    conv2d_28_output_array.data = AI_PTR(activations + 624);
    conv2d_28_output_array.data_start = AI_PTR(activations + 624);
    conv2d_29_output_array.data = AI_PTR(activations + 35088);
    conv2d_29_output_array.data_start = AI_PTR(activations + 35088);
    conv2d_30_output_array.data = AI_PTR(activations + 91536);
    conv2d_30_output_array.data_start = AI_PTR(activations + 91536);
    conv2d_31_output_array.data = AI_PTR(activations + 6144);
    conv2d_31_output_array.data_start = AI_PTR(activations + 6144);
    eltwise_32_output_array.data = AI_PTR(activations + 10848);
    eltwise_32_output_array.data_start = AI_PTR(activations + 10848);
    conv2d_33_output_array.data = AI_PTR(activations + 43776);
    conv2d_33_output_array.data_start = AI_PTR(activations + 43776);
    conv2d_34_output_array.data = AI_PTR(activations + 72000);
    conv2d_34_output_array.data_start = AI_PTR(activations + 72000);
    conv2d_35_output_array.data = AI_PTR(activations + 816);
    conv2d_35_output_array.data_start = AI_PTR(activations + 816);
    eltwise_36_output_array.data = AI_PTR(activations + 5520);
    eltwise_36_output_array.data_start = AI_PTR(activations + 5520);
    conv2d_37_output_array.data = AI_PTR(activations + 38448);
    conv2d_37_output_array.data_start = AI_PTR(activations + 38448);
    conv2d_38_output_array.data = AI_PTR(activations + 66672);
    conv2d_38_output_array.data_start = AI_PTR(activations + 66672);
    conv2d_39_output_array.data = AI_PTR(activations + 816);
    conv2d_39_output_array.data_start = AI_PTR(activations + 816);
    eltwise_40_output_array.data = AI_PTR(activations + 10224);
    eltwise_40_output_array.data_start = AI_PTR(activations + 10224);
    conv2d_41_output_array.data = AI_PTR(activations + 43152);
    conv2d_41_output_array.data_start = AI_PTR(activations + 43152);
    conv2d_42_output_array.data = AI_PTR(activations + 71376);
    conv2d_42_output_array.data_start = AI_PTR(activations + 71376);
    conv2d_43_output_array.data = AI_PTR(activations + 896);
    conv2d_43_output_array.data_start = AI_PTR(activations + 896);
    conv2d_44_output_array.data = AI_PTR(activations + 46848);
    conv2d_44_output_array.data_start = AI_PTR(activations + 46848);
    conv2d_45_output_array.data = AI_PTR(activations + 122112);
    conv2d_45_output_array.data_start = AI_PTR(activations + 122112);
    conv2d_46_output_array.data = AI_PTR(activations + 8256);
    conv2d_46_output_array.data_start = AI_PTR(activations + 8256);
    eltwise_47_output_array.data = AI_PTR(activations + 14528);
    eltwise_47_output_array.data_start = AI_PTR(activations + 14528);
    conv2d_48_output_array.data = AI_PTR(activations + 58432);
    conv2d_48_output_array.data_start = AI_PTR(activations + 58432);
    conv2d_49_output_array.data = AI_PTR(activations + 96064);
    conv2d_49_output_array.data_start = AI_PTR(activations + 96064);
    conv2d_50_output_array.data = AI_PTR(activations + 1088);
    conv2d_50_output_array.data_start = AI_PTR(activations + 1088);
    eltwise_51_output_array.data = AI_PTR(activations + 7360);
    eltwise_51_output_array.data_start = AI_PTR(activations + 7360);
    conv2d_52_output_array.data = AI_PTR(activations + 51264);
    conv2d_52_output_array.data_start = AI_PTR(activations + 51264);
    conv2d_54_output_array.data = AI_PTR(activations + 16516);
    conv2d_54_output_array.data_start = AI_PTR(activations + 16516);
    conv2d_55_output_array.data = AI_PTR(activations + 1328);
    conv2d_55_output_array.data_start = AI_PTR(activations + 1328);
    conv2d_56_output_array.data = AI_PTR(activations + 24120);
    conv2d_56_output_array.data_start = AI_PTR(activations + 24120);
    conv2d_57_output_array.data = AI_PTR(activations + 57048);
    conv2d_57_output_array.data_start = AI_PTR(activations + 57048);
    conv2d_58_output_array.data = AI_PTR(activations + 5976);
    conv2d_58_output_array.data_start = AI_PTR(activations + 5976);
    eltwise_59_output_array.data = AI_PTR(activations + 8720);
    eltwise_59_output_array.data_start = AI_PTR(activations + 8720);
    conv2d_60_output_array.data = AI_PTR(activations + 27928);
    conv2d_60_output_array.data_start = AI_PTR(activations + 27928);
    conv2d_61_output_array.data = AI_PTR(activations + 60856);
    conv2d_61_output_array.data_start = AI_PTR(activations + 60856);
    conv2d_62_output_array.data = AI_PTR(activations + 1904);
    conv2d_62_output_array.data_start = AI_PTR(activations + 1904);
    eltwise_63_output_array.data = AI_PTR(activations + 4648);
    eltwise_63_output_array.data_start = AI_PTR(activations + 4648);
    conv2d_64_output_array.data = AI_PTR(activations + 23856);
    conv2d_64_output_array.data_start = AI_PTR(activations + 23856);
    conv2d_65_output_array.data = AI_PTR(activations + 56784);
    conv2d_65_output_array.data_start = AI_PTR(activations + 56784);
    conv2d_66_output_array.data = AI_PTR(activations + 2464);
    conv2d_66_output_array.data_start = AI_PTR(activations + 2464);
    conv2d_67_output_array.data = AI_PTR(activations + 0);
    conv2d_67_output_array.data_start = AI_PTR(activations + 0);
    dense_69_output_array.data = AI_PTR(activations + 1280);
    dense_69_output_array.data_start = AI_PTR(activations + 1280);
    dense_70_output_array.data = AI_PTR(activations + 0);
    dense_70_output_array.data_start = AI_PTR(activations + 0);
    dense_70_fmt_output_array.data = AI_PTR(activations + 8);
    dense_70_fmt_output_array.data_start = AI_PTR(activations + 8);
    nl_71_output_array.data = AI_PTR(activations + 28);
    nl_71_output_array.data_start = AI_PTR(activations + 28);
    nl_71_fmt_output_array.data = AI_PTR(NULL);
    nl_71_fmt_output_array.data_start = AI_PTR(NULL);
    conv2d_2_scratch0_array.data = AI_PTR(activations + 515200);
    conv2d_2_scratch0_array.data_start = AI_PTR(activations + 515200);
    conv2d_2_scratch1_array.data = AI_PTR(activations + 312688);
    conv2d_2_scratch1_array.data_start = AI_PTR(activations + 312688);
    conv2d_3_scratch0_array.data = AI_PTR(activations + 515800);
    conv2d_3_scratch0_array.data_start = AI_PTR(activations + 515800);
    conv2d_3_scratch1_array.data = AI_PTR(activations + 309072);
    conv2d_3_scratch1_array.data_start = AI_PTR(activations + 309072);
    conv2d_4_scratch0_array.data = AI_PTR(activations + 509776);
    conv2d_4_scratch0_array.data_start = AI_PTR(activations + 509776);
    conv2d_5_scratch0_array.data = AI_PTR(activations + 610272);
    conv2d_5_scratch0_array.data_start = AI_PTR(activations + 610272);
    conv2d_5_scratch1_array.data = AI_PTR(activations + 2736);
    conv2d_5_scratch1_array.data_start = AI_PTR(activations + 2736);
    conv2d_7_scratch0_array.data = AI_PTR(activations + 609004);
    conv2d_7_scratch0_array.data_start = AI_PTR(activations + 609004);
    conv2d_7_scratch1_array.data = AI_PTR(activations + 0);
    conv2d_7_scratch1_array.data_start = AI_PTR(activations + 0);
    conv2d_8_scratch0_array.data = AI_PTR(activations + 150528);
    conv2d_8_scratch0_array.data_start = AI_PTR(activations + 150528);
    conv2d_9_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_9_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_9_scratch1_array.data = AI_PTR(activations + 175888);
    conv2d_9_scratch1_array.data_start = AI_PTR(activations + 175888);
    conv2d_10_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_10_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_10_scratch1_array.data = AI_PTR(activations + 175888);
    conv2d_10_scratch1_array.data_start = AI_PTR(activations + 175888);
    conv2d_11_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_11_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_13_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_13_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_13_scratch1_array.data = AI_PTR(activations + 50448);
    conv2d_13_scratch1_array.data_start = AI_PTR(activations + 50448);
    conv2d_15_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_15_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_15_scratch1_array.data = AI_PTR(activations + 1780);
    conv2d_15_scratch1_array.data_start = AI_PTR(activations + 1780);
    conv2d_16_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_16_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_17_scratch0_array.data = AI_PTR(activations + 12896);
    conv2d_17_scratch0_array.data_start = AI_PTR(activations + 12896);
    conv2d_17_scratch1_array.data = AI_PTR(activations + 13920);
    conv2d_17_scratch1_array.data_start = AI_PTR(activations + 13920);
    conv2d_18_scratch0_array.data = AI_PTR(activations + 12896);
    conv2d_18_scratch0_array.data_start = AI_PTR(activations + 12896);
    conv2d_18_scratch1_array.data = AI_PTR(activations + 164448);
    conv2d_18_scratch1_array.data_start = AI_PTR(activations + 164448);
    conv2d_19_scratch0_array.data = AI_PTR(activations + 12896);
    conv2d_19_scratch0_array.data_start = AI_PTR(activations + 12896);
    conv2d_21_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_21_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_21_scratch1_array.data = AI_PTR(activations + 38528);
    conv2d_21_scratch1_array.data_start = AI_PTR(activations + 38528);
    conv2d_22_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_22_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_22_scratch1_array.data = AI_PTR(activations + 38528);
    conv2d_22_scratch1_array.data_start = AI_PTR(activations + 38528);
    conv2d_23_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_23_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_25_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_25_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_25_scratch1_array.data = AI_PTR(activations + 25632);
    conv2d_25_scratch1_array.data_start = AI_PTR(activations + 25632);
    conv2d_27_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_27_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_27_scratch1_array.data = AI_PTR(activations + 3556);
    conv2d_27_scratch1_array.data_start = AI_PTR(activations + 3556);
    conv2d_28_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_28_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_29_scratch0_array.data = AI_PTR(activations + 5328);
    conv2d_29_scratch0_array.data_start = AI_PTR(activations + 5328);
    conv2d_29_scratch1_array.data = AI_PTR(activations + 6864);
    conv2d_29_scratch1_array.data_start = AI_PTR(activations + 6864);
    conv2d_30_scratch0_array.data = AI_PTR(activations + 5328);
    conv2d_30_scratch0_array.data_start = AI_PTR(activations + 5328);
    conv2d_30_scratch1_array.data = AI_PTR(activations + 63312);
    conv2d_30_scratch1_array.data_start = AI_PTR(activations + 63312);
    conv2d_31_scratch0_array.data = AI_PTR(activations + 5328);
    conv2d_31_scratch0_array.data_start = AI_PTR(activations + 5328);
    conv2d_33_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_33_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_33_scratch1_array.data = AI_PTR(activations + 15552);
    conv2d_33_scratch1_array.data_start = AI_PTR(activations + 15552);
    conv2d_34_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_34_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_34_scratch1_array.data = AI_PTR(activations + 15552);
    conv2d_34_scratch1_array.data_start = AI_PTR(activations + 15552);
    conv2d_35_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_35_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_37_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_37_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_37_scratch1_array.data = AI_PTR(activations + 10224);
    conv2d_37_scratch1_array.data_start = AI_PTR(activations + 10224);
    conv2d_38_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_38_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_38_scratch1_array.data = AI_PTR(activations + 10224);
    conv2d_38_scratch1_array.data_start = AI_PTR(activations + 10224);
    conv2d_39_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_39_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_41_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_41_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_41_scratch1_array.data = AI_PTR(activations + 14928);
    conv2d_41_scratch1_array.data_start = AI_PTR(activations + 14928);
    conv2d_42_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_42_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_42_scratch1_array.data = AI_PTR(activations + 5332);
    conv2d_42_scratch1_array.data_start = AI_PTR(activations + 5332);
    conv2d_43_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_43_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_44_scratch0_array.data = AI_PTR(activations + 7168);
    conv2d_44_scratch0_array.data_start = AI_PTR(activations + 7168);
    conv2d_44_scratch1_array.data = AI_PTR(activations + 9216);
    conv2d_44_scratch1_array.data_start = AI_PTR(activations + 9216);
    conv2d_45_scratch0_array.data = AI_PTR(activations + 7168);
    conv2d_45_scratch0_array.data_start = AI_PTR(activations + 7168);
    conv2d_45_scratch1_array.data = AI_PTR(activations + 84480);
    conv2d_45_scratch1_array.data_start = AI_PTR(activations + 84480);
    conv2d_46_scratch0_array.data = AI_PTR(activations + 7168);
    conv2d_46_scratch0_array.data_start = AI_PTR(activations + 7168);
    conv2d_48_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_48_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_48_scratch1_array.data = AI_PTR(activations + 20800);
    conv2d_48_scratch1_array.data_start = AI_PTR(activations + 20800);
    conv2d_49_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_49_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_49_scratch1_array.data = AI_PTR(activations + 20800);
    conv2d_49_scratch1_array.data_start = AI_PTR(activations + 20800);
    conv2d_50_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_50_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_52_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_52_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_52_scratch1_array.data = AI_PTR(activations + 13632);
    conv2d_52_scratch1_array.data_start = AI_PTR(activations + 13632);
    conv2d_54_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_54_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_54_scratch1_array.data = AI_PTR(activations + 7108);
    conv2d_54_scratch1_array.data_start = AI_PTR(activations + 7108);
    conv2d_55_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_55_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_56_scratch0_array.data = AI_PTR(activations + 4072);
    conv2d_56_scratch0_array.data_start = AI_PTR(activations + 4072);
    conv2d_56_scratch1_array.data = AI_PTR(activations + 7656);
    conv2d_56_scratch1_array.data_start = AI_PTR(activations + 7656);
    conv2d_57_scratch0_array.data = AI_PTR(activations + 4072);
    conv2d_57_scratch0_array.data_start = AI_PTR(activations + 4072);
    conv2d_57_scratch1_array.data = AI_PTR(activations + 40584);
    conv2d_57_scratch1_array.data_start = AI_PTR(activations + 40584);
    conv2d_58_scratch0_array.data = AI_PTR(activations + 4072);
    conv2d_58_scratch0_array.data_start = AI_PTR(activations + 4072);
    conv2d_60_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_60_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_60_scratch1_array.data = AI_PTR(activations + 11464);
    conv2d_60_scratch1_array.data_start = AI_PTR(activations + 11464);
    conv2d_61_scratch0_array.data = AI_PTR(activations + 11464);
    conv2d_61_scratch0_array.data_start = AI_PTR(activations + 11464);
    conv2d_61_scratch1_array.data = AI_PTR(activations + 44392);
    conv2d_61_scratch1_array.data_start = AI_PTR(activations + 44392);
    conv2d_62_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_62_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_64_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_64_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_64_scratch1_array.data = AI_PTR(activations + 7392);
    conv2d_64_scratch1_array.data_start = AI_PTR(activations + 7392);
    conv2d_65_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_65_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_65_scratch1_array.data = AI_PTR(activations + 40320);
    conv2d_65_scratch1_array.data_start = AI_PTR(activations + 40320);
    conv2d_66_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_66_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_67_scratch0_array.data = AI_PTR(activations + 7952);
    conv2d_67_scratch0_array.data_start = AI_PTR(activations + 7952);
    conv2d_67_scratch1_array.data = AI_PTR(activations + 21200);
    conv2d_67_scratch1_array.data_start = AI_PTR(activations + 21200);
    conv2d_67_scratch2_array.data = AI_PTR(activations + 83920);
    conv2d_67_scratch2_array.data_start = AI_PTR(activations + 83920);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool network_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_weights_array.data = AI_PTR(weights + 0);
    conv2d_2_weights_array.data_start = AI_PTR(weights + 0);
    conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_bias_array.data = AI_PTR(weights + 432);
    conv2d_2_bias_array.data_start = AI_PTR(weights + 432);
    conv2d_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_weights_array.data = AI_PTR(weights + 496);
    conv2d_3_weights_array.data_start = AI_PTR(weights + 496);
    conv2d_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_bias_array.data = AI_PTR(weights + 640);
    conv2d_3_bias_array.data_start = AI_PTR(weights + 640);
    conv2d_4_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_weights_array.data = AI_PTR(weights + 704);
    conv2d_4_weights_array.data_start = AI_PTR(weights + 704);
    conv2d_4_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_bias_array.data = AI_PTR(weights + 832);
    conv2d_4_bias_array.data_start = AI_PTR(weights + 832);
    conv2d_5_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_weights_array.data = AI_PTR(weights + 864);
    conv2d_5_weights_array.data_start = AI_PTR(weights + 864);
    conv2d_5_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_bias_array.data = AI_PTR(weights + 1248);
    conv2d_5_bias_array.data_start = AI_PTR(weights + 1248);
    conv2d_7_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_weights_array.data = AI_PTR(weights + 1440);
    conv2d_7_weights_array.data_start = AI_PTR(weights + 1440);
    conv2d_7_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_bias_array.data = AI_PTR(weights + 1872);
    conv2d_7_bias_array.data_start = AI_PTR(weights + 1872);
    conv2d_8_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_weights_array.data = AI_PTR(weights + 2064);
    conv2d_8_weights_array.data_start = AI_PTR(weights + 2064);
    conv2d_8_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_bias_array.data = AI_PTR(weights + 2448);
    conv2d_8_bias_array.data_start = AI_PTR(weights + 2448);
    conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_weights_array.data = AI_PTR(weights + 2480);
    conv2d_9_weights_array.data_start = AI_PTR(weights + 2480);
    conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_bias_array.data = AI_PTR(weights + 2864);
    conv2d_9_bias_array.data_start = AI_PTR(weights + 2864);
    conv2d_10_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_weights_array.data = AI_PTR(weights + 3056);
    conv2d_10_weights_array.data_start = AI_PTR(weights + 3056);
    conv2d_10_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_bias_array.data = AI_PTR(weights + 3488);
    conv2d_10_bias_array.data_start = AI_PTR(weights + 3488);
    conv2d_11_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_weights_array.data = AI_PTR(weights + 3680);
    conv2d_11_weights_array.data_start = AI_PTR(weights + 3680);
    conv2d_11_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_bias_array.data = AI_PTR(weights + 4064);
    conv2d_11_bias_array.data_start = AI_PTR(weights + 4064);
    conv2d_13_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_13_weights_array.data = AI_PTR(weights + 4096);
    conv2d_13_weights_array.data_start = AI_PTR(weights + 4096);
    conv2d_13_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_13_bias_array.data = AI_PTR(weights + 4480);
    conv2d_13_bias_array.data_start = AI_PTR(weights + 4480);
    conv2d_15_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_weights_array.data = AI_PTR(weights + 4672);
    conv2d_15_weights_array.data_start = AI_PTR(weights + 4672);
    conv2d_15_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_bias_array.data = AI_PTR(weights + 5104);
    conv2d_15_bias_array.data_start = AI_PTR(weights + 5104);
    conv2d_16_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_weights_array.data = AI_PTR(weights + 5296);
    conv2d_16_weights_array.data_start = AI_PTR(weights + 5296);
    conv2d_16_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_bias_array.data = AI_PTR(weights + 6064);
    conv2d_16_bias_array.data_start = AI_PTR(weights + 6064);
    conv2d_17_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_weights_array.data = AI_PTR(weights + 6128);
    conv2d_17_weights_array.data_start = AI_PTR(weights + 6128);
    conv2d_17_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_bias_array.data = AI_PTR(weights + 7664);
    conv2d_17_bias_array.data_start = AI_PTR(weights + 7664);
    conv2d_18_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_weights_array.data = AI_PTR(weights + 8048);
    conv2d_18_weights_array.data_start = AI_PTR(weights + 8048);
    conv2d_18_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_bias_array.data = AI_PTR(weights + 8912);
    conv2d_18_bias_array.data_start = AI_PTR(weights + 8912);
    conv2d_19_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_weights_array.data = AI_PTR(weights + 9296);
    conv2d_19_weights_array.data_start = AI_PTR(weights + 9296);
    conv2d_19_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_bias_array.data = AI_PTR(weights + 10832);
    conv2d_19_bias_array.data_start = AI_PTR(weights + 10832);
    conv2d_21_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_weights_array.data = AI_PTR(weights + 10896);
    conv2d_21_weights_array.data_start = AI_PTR(weights + 10896);
    conv2d_21_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_bias_array.data = AI_PTR(weights + 12432);
    conv2d_21_bias_array.data_start = AI_PTR(weights + 12432);
    conv2d_22_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_weights_array.data = AI_PTR(weights + 12816);
    conv2d_22_weights_array.data_start = AI_PTR(weights + 12816);
    conv2d_22_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_bias_array.data = AI_PTR(weights + 13680);
    conv2d_22_bias_array.data_start = AI_PTR(weights + 13680);
    conv2d_23_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_weights_array.data = AI_PTR(weights + 14064);
    conv2d_23_weights_array.data_start = AI_PTR(weights + 14064);
    conv2d_23_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_bias_array.data = AI_PTR(weights + 15600);
    conv2d_23_bias_array.data_start = AI_PTR(weights + 15600);
    conv2d_25_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_25_weights_array.data = AI_PTR(weights + 15664);
    conv2d_25_weights_array.data_start = AI_PTR(weights + 15664);
    conv2d_25_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_25_bias_array.data = AI_PTR(weights + 17200);
    conv2d_25_bias_array.data_start = AI_PTR(weights + 17200);
    conv2d_27_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_weights_array.data = AI_PTR(weights + 17584);
    conv2d_27_weights_array.data_start = AI_PTR(weights + 17584);
    conv2d_27_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_bias_array.data = AI_PTR(weights + 18448);
    conv2d_27_bias_array.data_start = AI_PTR(weights + 18448);
    conv2d_28_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_weights_array.data = AI_PTR(weights + 18832);
    conv2d_28_weights_array.data_start = AI_PTR(weights + 18832);
    conv2d_28_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_bias_array.data = AI_PTR(weights + 21136);
    conv2d_28_bias_array.data_start = AI_PTR(weights + 21136);
    conv2d_29_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_29_weights_array.data = AI_PTR(weights + 21232);
    conv2d_29_weights_array.data_start = AI_PTR(weights + 21232);
    conv2d_29_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_29_bias_array.data = AI_PTR(weights + 24688);
    conv2d_29_bias_array.data_start = AI_PTR(weights + 24688);
    conv2d_30_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_30_weights_array.data = AI_PTR(weights + 25264);
    conv2d_30_weights_array.data_start = AI_PTR(weights + 25264);
    conv2d_30_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_30_bias_array.data = AI_PTR(weights + 26560);
    conv2d_30_bias_array.data_start = AI_PTR(weights + 26560);
    conv2d_31_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_31_weights_array.data = AI_PTR(weights + 27136);
    conv2d_31_weights_array.data_start = AI_PTR(weights + 27136);
    conv2d_31_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_31_bias_array.data = AI_PTR(weights + 30592);
    conv2d_31_bias_array.data_start = AI_PTR(weights + 30592);
    conv2d_33_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_weights_array.data = AI_PTR(weights + 30688);
    conv2d_33_weights_array.data_start = AI_PTR(weights + 30688);
    conv2d_33_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_bias_array.data = AI_PTR(weights + 34144);
    conv2d_33_bias_array.data_start = AI_PTR(weights + 34144);
    conv2d_34_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_34_weights_array.data = AI_PTR(weights + 34720);
    conv2d_34_weights_array.data_start = AI_PTR(weights + 34720);
    conv2d_34_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_34_bias_array.data = AI_PTR(weights + 36016);
    conv2d_34_bias_array.data_start = AI_PTR(weights + 36016);
    conv2d_35_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_35_weights_array.data = AI_PTR(weights + 36592);
    conv2d_35_weights_array.data_start = AI_PTR(weights + 36592);
    conv2d_35_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_35_bias_array.data = AI_PTR(weights + 40048);
    conv2d_35_bias_array.data_start = AI_PTR(weights + 40048);
    conv2d_37_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_37_weights_array.data = AI_PTR(weights + 40144);
    conv2d_37_weights_array.data_start = AI_PTR(weights + 40144);
    conv2d_37_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_37_bias_array.data = AI_PTR(weights + 43600);
    conv2d_37_bias_array.data_start = AI_PTR(weights + 43600);
    conv2d_38_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_38_weights_array.data = AI_PTR(weights + 44176);
    conv2d_38_weights_array.data_start = AI_PTR(weights + 44176);
    conv2d_38_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_38_bias_array.data = AI_PTR(weights + 45472);
    conv2d_38_bias_array.data_start = AI_PTR(weights + 45472);
    conv2d_39_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_39_weights_array.data = AI_PTR(weights + 46048);
    conv2d_39_weights_array.data_start = AI_PTR(weights + 46048);
    conv2d_39_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_39_bias_array.data = AI_PTR(weights + 49504);
    conv2d_39_bias_array.data_start = AI_PTR(weights + 49504);
    conv2d_41_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_41_weights_array.data = AI_PTR(weights + 49600);
    conv2d_41_weights_array.data_start = AI_PTR(weights + 49600);
    conv2d_41_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_41_bias_array.data = AI_PTR(weights + 53056);
    conv2d_41_bias_array.data_start = AI_PTR(weights + 53056);
    conv2d_42_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_42_weights_array.data = AI_PTR(weights + 53632);
    conv2d_42_weights_array.data_start = AI_PTR(weights + 53632);
    conv2d_42_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_42_bias_array.data = AI_PTR(weights + 54928);
    conv2d_42_bias_array.data_start = AI_PTR(weights + 54928);
    conv2d_43_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_43_weights_array.data = AI_PTR(weights + 55504);
    conv2d_43_weights_array.data_start = AI_PTR(weights + 55504);
    conv2d_43_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_43_bias_array.data = AI_PTR(weights + 60112);
    conv2d_43_bias_array.data_start = AI_PTR(weights + 60112);
    conv2d_44_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_44_weights_array.data = AI_PTR(weights + 60240);
    conv2d_44_weights_array.data_start = AI_PTR(weights + 60240);
    conv2d_44_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_44_bias_array.data = AI_PTR(weights + 66384);
    conv2d_44_bias_array.data_start = AI_PTR(weights + 66384);
    conv2d_45_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_45_weights_array.data = AI_PTR(weights + 67152);
    conv2d_45_weights_array.data_start = AI_PTR(weights + 67152);
    conv2d_45_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_45_bias_array.data = AI_PTR(weights + 68880);
    conv2d_45_bias_array.data_start = AI_PTR(weights + 68880);
    conv2d_46_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_46_weights_array.data = AI_PTR(weights + 69648);
    conv2d_46_weights_array.data_start = AI_PTR(weights + 69648);
    conv2d_46_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_46_bias_array.data = AI_PTR(weights + 75792);
    conv2d_46_bias_array.data_start = AI_PTR(weights + 75792);
    conv2d_48_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_48_weights_array.data = AI_PTR(weights + 75920);
    conv2d_48_weights_array.data_start = AI_PTR(weights + 75920);
    conv2d_48_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_48_bias_array.data = AI_PTR(weights + 82064);
    conv2d_48_bias_array.data_start = AI_PTR(weights + 82064);
    conv2d_49_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_49_weights_array.data = AI_PTR(weights + 82832);
    conv2d_49_weights_array.data_start = AI_PTR(weights + 82832);
    conv2d_49_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_49_bias_array.data = AI_PTR(weights + 84560);
    conv2d_49_bias_array.data_start = AI_PTR(weights + 84560);
    conv2d_50_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_50_weights_array.data = AI_PTR(weights + 85328);
    conv2d_50_weights_array.data_start = AI_PTR(weights + 85328);
    conv2d_50_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_50_bias_array.data = AI_PTR(weights + 91472);
    conv2d_50_bias_array.data_start = AI_PTR(weights + 91472);
    conv2d_52_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_52_weights_array.data = AI_PTR(weights + 91600);
    conv2d_52_weights_array.data_start = AI_PTR(weights + 91600);
    conv2d_52_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_52_bias_array.data = AI_PTR(weights + 97744);
    conv2d_52_bias_array.data_start = AI_PTR(weights + 97744);
    conv2d_54_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_54_weights_array.data = AI_PTR(weights + 98512);
    conv2d_54_weights_array.data_start = AI_PTR(weights + 98512);
    conv2d_54_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_54_bias_array.data = AI_PTR(weights + 100240);
    conv2d_54_bias_array.data_start = AI_PTR(weights + 100240);
    conv2d_55_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_55_weights_array.data = AI_PTR(weights + 101008);
    conv2d_55_weights_array.data_start = AI_PTR(weights + 101008);
    conv2d_55_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_55_bias_array.data = AI_PTR(weights + 111760);
    conv2d_55_bias_array.data_start = AI_PTR(weights + 111760);
    conv2d_56_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_56_weights_array.data = AI_PTR(weights + 111984);
    conv2d_56_weights_array.data_start = AI_PTR(weights + 111984);
    conv2d_56_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_56_bias_array.data = AI_PTR(weights + 130800);
    conv2d_56_bias_array.data_start = AI_PTR(weights + 130800);
    conv2d_57_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_57_weights_array.data = AI_PTR(weights + 132144);
    conv2d_57_weights_array.data_start = AI_PTR(weights + 132144);
    conv2d_57_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_57_bias_array.data = AI_PTR(weights + 135168);
    conv2d_57_bias_array.data_start = AI_PTR(weights + 135168);
    conv2d_58_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_58_weights_array.data = AI_PTR(weights + 136512);
    conv2d_58_weights_array.data_start = AI_PTR(weights + 136512);
    conv2d_58_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_58_bias_array.data = AI_PTR(weights + 155328);
    conv2d_58_bias_array.data_start = AI_PTR(weights + 155328);
    conv2d_60_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_60_weights_array.data = AI_PTR(weights + 155552);
    conv2d_60_weights_array.data_start = AI_PTR(weights + 155552);
    conv2d_60_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_60_bias_array.data = AI_PTR(weights + 174368);
    conv2d_60_bias_array.data_start = AI_PTR(weights + 174368);
    conv2d_61_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_61_weights_array.data = AI_PTR(weights + 175712);
    conv2d_61_weights_array.data_start = AI_PTR(weights + 175712);
    conv2d_61_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_61_bias_array.data = AI_PTR(weights + 178736);
    conv2d_61_bias_array.data_start = AI_PTR(weights + 178736);
    conv2d_62_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_62_weights_array.data = AI_PTR(weights + 180080);
    conv2d_62_weights_array.data_start = AI_PTR(weights + 180080);
    conv2d_62_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_62_bias_array.data = AI_PTR(weights + 198896);
    conv2d_62_bias_array.data_start = AI_PTR(weights + 198896);
    conv2d_64_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_64_weights_array.data = AI_PTR(weights + 199120);
    conv2d_64_weights_array.data_start = AI_PTR(weights + 199120);
    conv2d_64_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_64_bias_array.data = AI_PTR(weights + 217936);
    conv2d_64_bias_array.data_start = AI_PTR(weights + 217936);
    conv2d_65_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_65_weights_array.data = AI_PTR(weights + 219280);
    conv2d_65_weights_array.data_start = AI_PTR(weights + 219280);
    conv2d_65_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_65_bias_array.data = AI_PTR(weights + 222304);
    conv2d_65_bias_array.data_start = AI_PTR(weights + 222304);
    conv2d_66_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_66_weights_array.data = AI_PTR(weights + 223648);
    conv2d_66_weights_array.data_start = AI_PTR(weights + 223648);
    conv2d_66_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_66_bias_array.data = AI_PTR(weights + 261280);
    conv2d_66_bias_array.data_start = AI_PTR(weights + 261280);
    conv2d_67_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_67_weights_array.data = AI_PTR(weights + 261728);
    conv2d_67_weights_array.data_start = AI_PTR(weights + 261728);
    conv2d_67_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_67_bias_array.data = AI_PTR(weights + 405088);
    conv2d_67_bias_array.data_start = AI_PTR(weights + 405088);
    dense_69_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_69_weights_array.data = AI_PTR(weights + 410208);
    dense_69_weights_array.data_start = AI_PTR(weights + 410208);
    dense_69_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_69_bias_array.data = AI_PTR(weights + 538208);
    dense_69_bias_array.data_start = AI_PTR(weights + 538208);
    dense_70_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_70_weights_array.data = AI_PTR(weights + 538608);
    dense_70_weights_array.data_start = AI_PTR(weights + 538608);
    dense_70_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_70_bias_array.data = AI_PTR(weights + 539108);
    dense_70_bias_array.data_start = AI_PTR(weights + 539108);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_network_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 58587644,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_network_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_network_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_network_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_network_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= network_configure_weights(net_ctx, &params->params);
  ok &= network_configure_activations(net_ctx, &params->activations);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_network_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

