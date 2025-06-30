#ifndef INTERFACE_LED6_BLUE_H
#define INTERFACE_LED6_BLUE_H

//MODULE: interface_LED6_Blue
//DESCRIPTION: pour interagir avec la LED bleu du STM32F407. 

//HISTORIQUE:
// 2018-09-30, Yves Roy, creation
// 2022-12-10, Philippe Bonin, Modification: Changer T1 par LED6_Blue


//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")

//#define INTERFACE_LED6_BLUE_VALEUR_POUR_ALLUMER  1   
//#define INTERFACE_LED6_BLUE_VALEUR_POUR_ETEINDRE 0

//Dependances logicielles

//pas de dependances logicielles



//INFORMATION PUBLIQUE:
//Definitions publiques:
//pas de definitions publiques


//Fonctions publiques:
void interface_LED6_Blue_allume(void);
void interface_LED6_Blue_eteint(void);
void interface_LED6_Blue_initialise(void);

//Variables publiques:
//pas de variables publiques

#endif
