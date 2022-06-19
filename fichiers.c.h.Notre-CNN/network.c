/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Fri Apr 29 13:42:05 2022
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
#define AI_NETWORK_MODEL_SIGNATURE     "30d5bff444ea981a4503b7f7d0018347"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Fri Apr 29 13:42:05 2022"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array serving_default_conv2d_27_input0_output_array;   /* Array #0 */
AI_STATIC ai_array conv2d_0_output_array;   /* Array #1 */
AI_STATIC ai_array conv2d_2_output_array;   /* Array #2 */
AI_STATIC ai_array conv2d_4_output_array;   /* Array #3 */
AI_STATIC ai_array dense_7_output_array;   /* Array #4 */
AI_STATIC ai_array dense_8_output_array;   /* Array #5 */
AI_STATIC ai_array dense_8_fmt_output_array;   /* Array #6 */
AI_STATIC ai_array nl_9_output_array;   /* Array #7 */
AI_STATIC ai_array nl_9_fmt_output_array;   /* Array #8 */
AI_STATIC ai_array conv2d_0_weights_array;   /* Array #9 */
AI_STATIC ai_array conv2d_0_bias_array;   /* Array #10 */
AI_STATIC ai_array conv2d_2_weights_array;   /* Array #11 */
AI_STATIC ai_array conv2d_2_bias_array;   /* Array #12 */
AI_STATIC ai_array conv2d_4_weights_array;   /* Array #13 */
AI_STATIC ai_array conv2d_4_bias_array;   /* Array #14 */
AI_STATIC ai_array dense_7_weights_array;   /* Array #15 */
AI_STATIC ai_array dense_7_bias_array;   /* Array #16 */
AI_STATIC ai_array dense_8_weights_array;   /* Array #17 */
AI_STATIC ai_array dense_8_bias_array;   /* Array #18 */
AI_STATIC ai_array conv2d_0_scratch0_array;   /* Array #19 */
AI_STATIC ai_array conv2d_0_scratch1_array;   /* Array #20 */
AI_STATIC ai_array conv2d_2_scratch0_array;   /* Array #21 */
AI_STATIC ai_array conv2d_2_scratch1_array;   /* Array #22 */
AI_STATIC ai_array conv2d_4_scratch0_array;   /* Array #23 */
AI_STATIC ai_array conv2d_4_scratch1_array;   /* Array #24 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor serving_default_conv2d_27_input0_output;   /* Tensor #0 */
AI_STATIC ai_tensor conv2d_0_output;   /* Tensor #1 */
AI_STATIC ai_tensor conv2d_2_output;   /* Tensor #2 */
AI_STATIC ai_tensor conv2d_4_output;   /* Tensor #3 */
AI_STATIC ai_tensor conv2d_4_output0;   /* Tensor #4 */
AI_STATIC ai_tensor dense_7_output;   /* Tensor #5 */
AI_STATIC ai_tensor dense_8_output;   /* Tensor #6 */
AI_STATIC ai_tensor dense_8_fmt_output;   /* Tensor #7 */
AI_STATIC ai_tensor nl_9_output;   /* Tensor #8 */
AI_STATIC ai_tensor nl_9_fmt_output;   /* Tensor #9 */
AI_STATIC ai_tensor conv2d_0_weights;   /* Tensor #10 */
AI_STATIC ai_tensor conv2d_0_bias;   /* Tensor #11 */
AI_STATIC ai_tensor conv2d_2_weights;   /* Tensor #12 */
AI_STATIC ai_tensor conv2d_2_bias;   /* Tensor #13 */
AI_STATIC ai_tensor conv2d_4_weights;   /* Tensor #14 */
AI_STATIC ai_tensor conv2d_4_bias;   /* Tensor #15 */
AI_STATIC ai_tensor dense_7_weights;   /* Tensor #16 */
AI_STATIC ai_tensor dense_7_bias;   /* Tensor #17 */
AI_STATIC ai_tensor dense_8_weights;   /* Tensor #18 */
AI_STATIC ai_tensor dense_8_bias;   /* Tensor #19 */
AI_STATIC ai_tensor conv2d_0_scratch0;   /* Tensor #20 */
AI_STATIC ai_tensor conv2d_0_scratch1;   /* Tensor #21 */
AI_STATIC ai_tensor conv2d_2_scratch0;   /* Tensor #22 */
AI_STATIC ai_tensor conv2d_2_scratch1;   /* Tensor #23 */
AI_STATIC ai_tensor conv2d_4_scratch0;   /* Tensor #24 */
AI_STATIC ai_tensor conv2d_4_scratch1;   /* Tensor #25 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conv2d_0_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv2d_2_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain conv2d_4_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain dense_7_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain dense_8_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain dense_8_fmt_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain nl_9_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain nl_9_fmt_chain;   /* Chain #7 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_conv2d_nl_pool conv2d_0_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d_nl_pool conv2d_2_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d_nl_pool conv2d_4_layer; /* Layer #2 */
AI_STATIC ai_layer_dense dense_7_layer; /* Layer #3 */
AI_STATIC ai_layer_dense dense_8_layer; /* Layer #4 */
AI_STATIC ai_layer_nl dense_8_fmt_layer; /* Layer #5 */
AI_STATIC ai_layer_nl nl_9_layer; /* Layer #6 */
AI_STATIC ai_layer_nl nl_9_fmt_layer; /* Layer #7 */




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_conv2d_27_input0_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 150528, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 193600, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21632, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 144, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  dense_7_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  dense_8_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  dense_8_fmt_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 5, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  nl_9_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 5, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  nl_9_fmt_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 5, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4800, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 288, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 1, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  dense_7_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3600, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  dense_7_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 25, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  dense_8_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 125, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  dense_8_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 5, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6316, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 56320, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9664, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3328, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1732, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 48, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(serving_default_conv2d_27_input0_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01484849862754345f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08528126031160355f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.044261664152145386f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_7_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11837971955537796f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_8_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.046898674219846725f),
    AI_PACK_INTQ_ZP(-124)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_9_fmt_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008264754433184862f, 0.0008563815499655902f, 0.0010319609427824616f, 0.0007909561973065138f, 0.0007732930826023221f, 0.0007795683341100812f, 0.0009497104911133647f, 0.0009790243348106742f, 0.0005669926176778972f, 0.0009235999314114451f, 0.0006717723445035517f, 0.0008836007909849286f, 0.0008677357691340148f, 0.0007638100069016218f, 0.0009749809396453202f, 0.0007875189767219126f, 0.0007106158882379532f, 0.0009071924141608179f, 0.000961582874879241f, 0.0005978017579764128f, 0.0007164604030549526f, 0.0007743863388895988f, 0.0005208700313232839f, 0.0007329515647143126f, 0.0005118457484059036f, 0.0009750702884048223f, 0.0006892600795254111f, 0.0008670750539749861f, 0.000952880538534373f, 0.0005638703587464988f, 0.000889107002876699f, 0.0006925878114998341f, 0.0005258736200630665f, 0.0006892654928378761f, 0.0008157732663676143f, 0.0007812250405550003f, 0.001209856360219419f, 0.0009880040306597948f, 0.0007786228088662028f, 0.0006480780430138111f, 0.0008446560241281986f, 0.001042962190695107f, 0.001037539797835052f, 0.0008066511945798993f, 0.000480583927128464f, 0.0007320669246837497f, 0.0005187197239138186f, 0.0006211383733898401f, 0.0008583214948885143f, 0.0006999422330409288f, 0.0009543654741719365f, 0.0007318495190702379f, 0.0008010583696886897f, 0.0007741183508187532f, 0.0005019007949158549f, 0.0005734791629947722f, 0.000777103821747005f, 0.0008737738826312125f, 0.0006609041593037546f, 0.0007519291830249131f, 0.0009017864358611405f, 0.000598609447479248f, 0.0010059075430035591f, 0.0009515637066215277f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(3.241080321458867e-06f, 3.358359208505135e-06f, 4.046905814902857e-06f, 3.101789161519264e-06f, 3.0325220450322377e-06f, 3.057130925299134e-06f, 3.724355110534816e-06f, 3.839311375486432e-06f, 2.2235005872062175e-06f, 3.621960786404088e-06f, 2.634401425893884e-06f, 3.4651013720576884e-06f, 3.4028855679935077e-06f, 2.995333488797769e-06f, 3.8234547901083715e-06f, 3.088309995291638e-06f, 2.786729055515025e-06f, 3.557617446858785e-06f, 3.770913508560625e-06f, 2.344320819247514e-06f, 2.8096487767470535e-06f, 3.0368094030563952e-06f, 2.042627784248907e-06f, 2.8743199891323457e-06f, 2.0072384359082207e-06f, 3.823805400315905e-06f, 2.70298096438637e-06f, 3.4002944175881566e-06f, 3.7367865388659993e-06f, 2.2112565147835994e-06f, 3.486694367893506e-06f, 2.716030849114759e-06f, 2.062249677692307e-06f, 2.7030021101381863e-06f, 3.1991110063245287e-06f, 3.063627900701249e-06f, 4.744535090139834e-06f, 3.874525646097027e-06f, 3.053422915400006e-06f, 2.5414826723135775e-06f, 3.312376747999224e-06f, 4.090048150828807e-06f, 4.068783709954005e-06f, 3.163338305967045e-06f, 1.8846429838959011e-06f, 2.8708509489661083e-06f, 2.034195176747744e-06f, 2.4358369046240114e-06f, 3.36596690431179e-06f, 2.7448716082290048e-06f, 3.7426100334414514e-06f, 2.869998297683196e-06f, 3.1414056138601154e-06f, 3.0357584819284966e-06f, 1.9682386209751712e-06f, 2.248938017146429e-06f, 3.047466179850744e-06f, 3.4265644899278414e-06f, 2.591781139926752e-06f, 2.948742121589021e-06f, 3.536417580107809e-06f, 2.3474881345464382e-06f, 3.9447359085897915e-06f, 3.731622655323008e-06f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0012834965018555522f, 0.0005512756179086864f, 0.001324958517216146f, 0.0005574860842898488f, 0.00152856414206326f, 0.0005559464334510267f, 0.0006319041713140905f, 0.0012805282603949308f, 0.0007738578133285046f, 0.0014330771518871188f, 0.0017359512858092785f, 0.001098614651709795f, 0.000644970394205302f, 0.0008058954845182598f, 0.0013719425769522786f, 0.0015703727258369327f, 0.0005553762894123793f, 0.0005576157127507031f, 0.0007799953455105424f, 0.000546797236893326f, 0.0005587164196185768f, 0.0014303710777312517f, 0.001250862143933773f, 0.0005656061111949384f, 0.0013524756068363786f, 0.0006420954596251249f, 0.0006931768148206174f, 0.0011814251774922013f, 0.000547859410289675f, 0.0007207696326076984f, 0.000564157438930124f, 0.0012875287793576717f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.9057995814364403e-05f, 8.185615115507971e-06f, 1.9673645510920323e-05f, 8.277831511804834e-06f, 2.2696882297168486e-05f, 8.254969543486368e-06f, 9.382828466186766e-06f, 1.9013921701116487e-05f, 1.1490627002785914e-05f, 2.1279043721733615e-05f, 2.5776269467314705e-05f, 1.63127788255224e-05f, 9.576841875968967e-06f, 1.1966338206548244e-05f, 2.0371287973830476e-05f, 2.3317677914747037e-05f, 8.246503966802265e-06f, 8.279756002593786e-06f, 1.1581760190892965e-05f, 8.119118319882546e-06f, 8.296099622384645e-06f, 2.1238862245809287e-05f, 1.85734243132174e-05f, 8.398401405429468e-06f, 2.0082232367713004e-05f, 9.534153832646552e-06f, 1.0292635124642402e-05f, 1.754239019646775e-05f, 8.13488986750599e-06f, 1.0702347026381176e-05f, 8.376890946237836e-06f, 1.911786966957152e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0016441765474155545f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00014021745300851762f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_7_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0019883576314896345f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_7_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.800801879260689e-05f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_8_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003973217215389013f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_8_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0004703483427874744f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01484849862754345f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08528126031160355f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.044261664152145386f),
    AI_PACK_INTQ_ZP(-128)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_conv2d_27_input0_output, AI_STATIC,
  0, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 224, 224), AI_STRIDE_INIT(4, 1, 1, 3, 672),
  1, &serving_default_conv2d_27_input0_output_array, &serving_default_conv2d_27_input0_output_intq)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_output, AI_STATIC,
  1, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 55, 55), AI_STRIDE_INIT(4, 1, 1, 64, 3520),
  1, &conv2d_0_output_array, &conv2d_0_output_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output, AI_STATIC,
  2, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 26, 26), AI_STRIDE_INIT(4, 1, 1, 32, 832),
  1, &conv2d_2_output_array, &conv2d_2_output_intq)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_output, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 12, 12), AI_STRIDE_INIT(4, 1, 1, 1, 12),
  1, &conv2d_4_output_array, &conv2d_4_output_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_output0, AI_STATIC,
  4, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 1, 1, 144, 144),
  1, &conv2d_4_output_array, &conv2d_4_output_intq)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  dense_7_output, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 25, 1, 1), AI_STRIDE_INIT(4, 1, 1, 25, 25),
  1, &dense_7_output_array, &dense_7_output_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  dense_8_output, AI_STATIC,
  6, 0x1,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5, 5),
  1, &dense_8_output_array, &dense_8_output_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  dense_8_fmt_output, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 4, 4, 20, 20),
  1, &dense_8_fmt_output_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  nl_9_output, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 4, 4, 20, 20),
  1, &nl_9_output_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  nl_9_fmt_output, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5, 5),
  1, &nl_9_fmt_output_array, &nl_9_fmt_output_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_weights, AI_STATIC,
  10, 0x1,
  AI_SHAPE_INIT(4, 3, 5, 5, 64), AI_STRIDE_INIT(4, 1, 3, 15, 75),
  1, &conv2d_0_weights_array, &conv2d_0_weights_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_bias, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_0_bias_array, &conv2d_0_bias_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights, AI_STATIC,
  12, 0x1,
  AI_SHAPE_INIT(4, 64, 4, 4, 32), AI_STRIDE_INIT(4, 1, 64, 256, 1024),
  1, &conv2d_2_weights_array, &conv2d_2_weights_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_2_bias_array, &conv2d_2_bias_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_weights, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 1), AI_STRIDE_INIT(4, 1, 32, 96, 288),
  1, &conv2d_4_weights_array, &conv2d_4_weights_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_bias, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &conv2d_4_bias_array, &conv2d_4_bias_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  dense_7_weights, AI_STATIC,
  16, 0x1,
  AI_SHAPE_INIT(4, 144, 25, 1, 1), AI_STRIDE_INIT(4, 1, 144, 3600, 3600),
  1, &dense_7_weights_array, &dense_7_weights_intq)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  dense_7_bias, AI_STATIC,
  17, 0x1,
  AI_SHAPE_INIT(4, 1, 25, 1, 1), AI_STRIDE_INIT(4, 4, 4, 100, 100),
  1, &dense_7_bias_array, &dense_7_bias_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  dense_8_weights, AI_STATIC,
  18, 0x1,
  AI_SHAPE_INIT(4, 25, 5, 1, 1), AI_STRIDE_INIT(4, 1, 25, 125, 125),
  1, &dense_8_weights_array, &dense_8_weights_intq)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  dense_8_bias, AI_STATIC,
  19, 0x1,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 4, 4, 20, 20),
  1, &dense_8_bias_array, &dense_8_bias_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_scratch0, AI_STATIC,
  20, 0x0,
  AI_SHAPE_INIT(4, 1, 6316, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6316, 6316),
  1, &conv2d_0_scratch0_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_scratch1, AI_STATIC,
  21, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 220, 4), AI_STRIDE_INIT(4, 1, 1, 64, 14080),
  1, &conv2d_0_scratch1_array, &conv2d_0_scratch1_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch0, AI_STATIC,
  22, 0x0,
  AI_SHAPE_INIT(4, 1, 9664, 1, 1), AI_STRIDE_INIT(4, 1, 1, 9664, 9664),
  1, &conv2d_2_scratch0_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch1, AI_STATIC,
  23, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 52, 2), AI_STRIDE_INIT(4, 1, 1, 32, 1664),
  1, &conv2d_2_scratch1_array, &conv2d_2_scratch1_intq)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch0, AI_STATIC,
  24, 0x0,
  AI_SHAPE_INIT(4, 1, 1732, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1732, 1732),
  1, &conv2d_4_scratch0_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch1, AI_STATIC,
  25, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 24, 2), AI_STRIDE_INIT(4, 1, 1, 1, 24),
  1, &conv2d_4_scratch1_array, &conv2d_4_scratch1_intq)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_conv2d_27_input0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_0_weights, &conv2d_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_0_scratch0, &conv2d_0_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_0_layer, 1,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_nl_pool_integer_SSSA_ch,
  &conv2d_0_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_2_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(4, 4), 
  .pool_stride = AI_SHAPE_2D_INIT(4, 4), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_mp_array_integer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_2_weights, &conv2d_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_2_scratch0, &conv2d_2_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_layer, 3,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_nl_pool_integer_SSSA_ch,
  &conv2d_2_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_4_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_mp_array_integer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_4_weights, &conv2d_4_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_4_scratch0, &conv2d_4_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_4_layer, 5,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_nl_pool_integer_SSSA,
  &conv2d_4_chain,
  &AI_NET_OBJ_INSTANCE, &dense_7_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_mp_array_integer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_7_weights, &dense_7_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_7_layer, 7,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &dense_7_chain,
  &AI_NET_OBJ_INSTANCE, &dense_8_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_8_weights, &dense_8_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_8_layer, 8,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &dense_8_chain,
  &AI_NET_OBJ_INSTANCE, &dense_8_fmt_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_8_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_8_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_8_fmt_layer, 8,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &dense_8_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &nl_9_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_8_fmt_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_9_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_9_layer, 9,
  NL_TYPE, 0x0, NULL,
  nl, forward_sm,
  &nl_9_chain,
  &AI_NET_OBJ_INSTANCE, &nl_9_fmt_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_9_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_9_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_9_fmt_layer, 9,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &nl_9_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &nl_9_fmt_layer, AI_STATIC, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 42092, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 256236, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &serving_default_conv2d_27_input0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &nl_9_fmt_output),
  &conv2d_0_layer, 0, NULL)



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
    serving_default_conv2d_27_input0_output_array.data = AI_PTR(NULL);
    serving_default_conv2d_27_input0_output_array.data_start = AI_PTR(NULL);
    conv2d_0_output_array.data = AI_PTR(activations + 62636);
    conv2d_0_output_array.data_start = AI_PTR(activations + 62636);
    conv2d_2_output_array.data = AI_PTR(activations + 12992);
    conv2d_2_output_array.data_start = AI_PTR(activations + 12992);
    conv2d_4_output_array.data = AI_PTR(activations + 1780);
    conv2d_4_output_array.data_start = AI_PTR(activations + 1780);
    dense_7_output_array.data = AI_PTR(activations + 0);
    dense_7_output_array.data_start = AI_PTR(activations + 0);
    dense_8_output_array.data = AI_PTR(activations + 28);
    dense_8_output_array.data_start = AI_PTR(activations + 28);
    dense_8_fmt_output_array.data = AI_PTR(activations + 0);
    dense_8_fmt_output_array.data_start = AI_PTR(activations + 0);
    nl_9_output_array.data = AI_PTR(activations + 20);
    nl_9_output_array.data_start = AI_PTR(activations + 20);
    nl_9_fmt_output_array.data = AI_PTR(NULL);
    nl_9_fmt_output_array.data_start = AI_PTR(NULL);
    conv2d_0_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_0_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_0_scratch1_array.data = AI_PTR(activations + 6316);
    conv2d_0_scratch1_array.data_start = AI_PTR(activations + 6316);
    conv2d_2_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_2_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_2_scratch1_array.data = AI_PTR(activations + 9664);
    conv2d_2_scratch1_array.data_start = AI_PTR(activations + 9664);
    conv2d_4_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_4_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_4_scratch1_array.data = AI_PTR(activations + 1732);
    conv2d_4_scratch1_array.data_start = AI_PTR(activations + 1732);
    
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
    
    conv2d_0_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_0_weights_array.data = AI_PTR(weights + 0);
    conv2d_0_weights_array.data_start = AI_PTR(weights + 0);
    conv2d_0_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_0_bias_array.data = AI_PTR(weights + 4800);
    conv2d_0_bias_array.data_start = AI_PTR(weights + 4800);
    conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_weights_array.data = AI_PTR(weights + 5056);
    conv2d_2_weights_array.data_start = AI_PTR(weights + 5056);
    conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_bias_array.data = AI_PTR(weights + 37824);
    conv2d_2_bias_array.data_start = AI_PTR(weights + 37824);
    conv2d_4_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_weights_array.data = AI_PTR(weights + 37952);
    conv2d_4_weights_array.data_start = AI_PTR(weights + 37952);
    conv2d_4_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_bias_array.data = AI_PTR(weights + 38240);
    conv2d_4_bias_array.data_start = AI_PTR(weights + 38240);
    dense_7_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_7_weights_array.data = AI_PTR(weights + 38244);
    dense_7_weights_array.data_start = AI_PTR(weights + 38244);
    dense_7_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_7_bias_array.data = AI_PTR(weights + 41844);
    dense_7_bias_array.data_start = AI_PTR(weights + 41844);
    dense_8_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_8_weights_array.data = AI_PTR(weights + 41944);
    dense_8_weights_array.data_start = AI_PTR(weights + 41944);
    dense_8_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_8_bias_array.data = AI_PTR(weights + 42072);
    dense_8_bias_array.data_start = AI_PTR(weights + 42072);
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
      
      .n_macc            = 324279211,
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

