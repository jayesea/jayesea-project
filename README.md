# jayesea-project

Dans le dossier fichiers.c.h.Notre-CNN vous trouverez les fichiers.c et .h de notre Modèle réalisé utilisant TensorFlow et le fichier.elf de l'application à mettre sur la carte en utilisant STM32CubeProgrammer.

Dans le dossier fichiers.c.h vous trouverez les fichiers.c et .h du modèle réalisé utilisant Teachable Machine (nous avons utilisé le dataset avec les flèches commentées)  et le fichier .elf de l'application à mettre sur la carte en utilisant STM32CubeProgrammer.

Pour convertir un fichier TFLite en fichiers .c .h il faut utiliser la commande suivante:
stm32ai generate -m .\model.tflite --quantize -v 2


Lien Tuto Teachable Machine :

https://wiki.stmicroelectronics.cn/stm32mcu/index.php?title=AI:How_to_use_Teachable_Machine_to_create_an_image_classification_application_on_STM32&oldid=18896
