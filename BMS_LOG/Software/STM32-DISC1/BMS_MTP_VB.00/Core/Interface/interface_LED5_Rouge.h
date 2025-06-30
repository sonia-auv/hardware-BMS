#ifndef INTERFACE_LED5_ROUGE_H
#define INTERFACE_LED5_ROUGE_H

//MODULE: interfaceT4
//DESCRIPTION: pour interagir avec la LED rouge du  STM32F407. 

//HISTORIQUE:
// 2018-09-30, Yves Roy, creation
// 2022-12-10, Philippe Bonin, Modification: Changer T4 par LED5_Rouge

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define INTERFACE_LED5_ROUGE_VALEUR_POUR_ALLUMER  1   
//#define INTERFACE_LED5_ROUGE_VALEUR_POUR_ETEINDRE 0

//Dependances logicielles



//INFORMATION PUBLIQUE:



//Fonctions publiques:
void interface_LED5_Rouge_allume(void);
void interface_LED5_Rouge_eteint(void);
void interface_LED5_Rouge_initialise(void);

//Variables publiques:


#endif
