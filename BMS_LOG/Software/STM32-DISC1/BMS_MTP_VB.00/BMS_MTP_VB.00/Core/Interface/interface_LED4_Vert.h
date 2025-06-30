#ifndef INTERFACE_LED4_VERT_H
#define INTERFACE_LED4_VERT_H

//MODULE: interface_LED4_Vert
//DESCRIPTION: pour interagir avec la LED verte du  STM32F407. 


//HISTORIQUE:
// 2018-09-30, Yves Roy, creation
// 2022-12-10, Philippe Bonin, Modification: Changer T3 par LED4_Vert


//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles

//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACE_LED4_VERT_VALEUR_POUR_ALLUMER  1   
//#define INTERFACE_LED4_VERT_VALEUR_POUR_ETEINDRE 0

//Dependances logicielles
//(copiez et adaptez ce qui suit dans "main.h")
//pas de dependances logicielles

//INFORMATION PUBLIQUE:
//Definitions publiques:
//pas de definitions publiques

//Fonctions publiques:
void interface_LED4_Vert_allume(void);
void interface_LED4_Vert_eteint(void);
void interface_LED4_Vert_initialise(void);

//Variables publiques:
//pas de variables publiques

#endif
