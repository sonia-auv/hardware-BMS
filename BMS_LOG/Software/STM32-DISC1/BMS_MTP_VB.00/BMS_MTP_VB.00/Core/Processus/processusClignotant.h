#ifndef PROCESSUSCLIGNOTANT_H
#define PROCESSUSCLIGNOTANT_H

//MODULE: processusClignotant
//DESCRIPTION: implemente la gestion d'un clignotant en utilise un pointeur de
//fonctions fourni par serviceBaseDeTemps.

//HISTORIQUE:
// 2018-09-30, Yves Roy, creation

//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//pas de dependances materielles

//Dependances logicielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define PROCESSUSCLIGNOTANT_PHASE 0
//#define PROCESSUSCLIGNOTANT_TEMPS_COURT_ETEINT_EN_MS  300
//#define PROCESSUSCLIGNOTANT_TEMPS_COURT_ALLUME_EN_MS  200
//#define PROCESSUSCLIGNOTANT_TEMPS_LONG_ETEINT_EN_MS  500
//#define PROCESSUSCLIGNOTANT_TEMPS_LONG_ALLUME_EN_MS  1000

//INFORMATION PUBLIQUE:
//Definitions publiques:
//pas de definitions publiques

//Fonctions publiques:
void processusClignotant_initialise(void);
void processusClignotant_orange_AllumeLongtemps(void);
void processusClignotant_orange_Eteint_court(void);

void processusClignotant_orange_Eteint_relache(void);
void processusClignotant_orange_Allume_relache(void);

void processusClignotant_blue_Eteint_relache(void);
void processusClignotant_blue_Allume_relache(void);

void processusClignotant_blue_AllumeLongtemps(void);
void processusClignotant_blue_Eteint_court(void);
//Variables publiques:
//pas de variables publiques

#endif


