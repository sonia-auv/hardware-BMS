#ifndef INTERFACE_LED3_ORANGE_H
#define INTERFACE_LED3_ORANGE_H

//MODULE: interface_LED3_Orange
//DESCRIPTION: pour interagir avec la LED orange du  STM32F407. 

//HISTORIQUE:
// 2018-09-30, Yves Roy, creation
// 2022-12-10, Philippe Bonin, Modification: Changer T2 par LED3_Orange

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles

//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACE_LED3_ORANGE_VALEUR_POUR_ALLUMER  1   
//#define INTERFACE_LED3_ORANGE_VALEUR_POUR_ETEINDRE 0

//Dependances logicielles



//INFORMATION PUBLIQUE:
//Definitions publiques:



//Fonctions publiques:
void interface_LED3_Orange_allume(void);
void interface_LED3_Orange_eteint(void);
void interface_LED3_Orange_initialise(void);

//Variables publiques:
//pas de variables publiques

#endif
