# jayesea-project

Dans le dossier fichiers.c.h.Notre-CNN vous trouverez les fichiers.c et .h de notre Modèle réalisé utilisant TensorFlow et le fichier.elf de l'application à mettre sur la carte en utilisant STM32CubeProgrammer.

Dans le dossier fichiers.c.h vous trouverez les fichiers.c et .h du modèle réalisé utilisant Teachable Machine (nous avons utilisé le dataset avec les flèches commentées)  et le fichier .elf de l'application à mettre sur la carte en utilisant STM32CubeProgrammer.

**********************Démarche à faire sur le projet STM pour chaque changement de modéle:*****************************************
1- le dossier "FP-AI-VISION1_CC-GTM_network\FP-AI-VISION1_V3.0.0\Projects\STM32H747I-DISCO\Applications\FoodReco_MobileNetDerivative\Quantized_Model\CM7" contient les dossiers Inc et Src a changer en remettant les fichiers network.c et network_data.c dans Src et network.h et network_data.h dans Inc.

2- modification sur le fichier fp_vision_app.c dans "FP-AI-VISION1_CC-GTM_network\FP-AI-VISION1_V3.0.0\Projects\STM32H747I-DISCO\Applications\FoodReco_MobileNetDerivative\Quantized_Model\CM7\Src".
2-1/
    - si le modele est généré utilisant teachable model change les lignes 365 et 366 par ceci:
          App_Context_Ptr->Ai_ContextPtr->nn_input_norm_scale=127.5f;
          App_Context_Ptr->Ai_ContextPtr->nn_input_norm_zp=127;
    - si le modele est généré par tensorflow change ces lignes par:
          App_Context_Ptr->Ai_ContextPtr->nn_input_norm_scale=255.0f;
          App_Context_Ptr->Ai_ContextPtr->nn_input_norm_zp=0;
2-2/
  Réaliser le changement des noms des labels si nécessaire sur la ligne 126 de fichier fp_vision_app.c:
    -pour le modele teachable machine c'est : const char* output_labels[AI_NET_OUTPUT_SIZE] = {"gauche", "droite", "tout droit", "demi tour", "nothing" };
    -pour notre modele CNN réalisé avec tensorflow c'est:const char* output_labels[AI_NET_OUTPUT_SIZE] = {"bas", "droite", "gauche", "haut", "rien" };
    
3-Sur audio_play.c (à partir de la ligne 144) dans "FP-AI-VISION1_CC-GTM_network\FP-AI-VISION1_V3.0.0\Projects\STM32H747I-DISCO\Applications\Common\CM7\Src" penser à réordonner les codes dans les if. Ceci est neccessaire car en changant l'ordre des labels sur le fichier fp_vision_app.c le code (qui génere l'audio) n'est plus synchroniser avec les labels.

4-clean et build
5-utilisant stmcubeprogrammer ajouter les fichiers sounds (disponible dans "FP-AI-VISION1_CC-GTM_network\FP-AI-VISION1_V3.0.0\Utilities\Sound") dans la mémoire aux adresses appropriées:
  DEFAULT à l'adresse 0x90000000
  LEFT à l'adresse 0x90050000
  RIGHT à l'adresse 0x900A0000
  STRAIGHT à l'adresse 0x900F0000
  U-TURN à l'adresse 0x90100000 
6-finalement mettre le fichier.elf dans la carte  (le fichier est généré dans "FP-AI-VISION1_CC-GTM_network\FP-AI-VISION1_V3.0.0\Projects\STM32H747I-DISCO\Applications\FoodReco_MobileNetDerivative\Quantized_Model\STM32CubeIDE\CM7\Quantized_Ext")
*************************************************************************************************************************************************************
  

Pour convertir un fichier TFLite en fichiers .c .h il faut utiliser la commande suivante:
stm32ai generate -m .\model.tflite --quantize -v 2


Lien Tuto Teachable Machine :

https://wiki.stmicroelectronics.cn/stm32mcu/index.php?title=AI:How_to_use_Teachable_Machine_to_create_an_image_classification_application_on_STM32&oldid=18896
