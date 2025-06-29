//interface_LED3_Orange:
//Historique: 
// 2018-09-30, Yves Roy, creation
// 2022-12-10, Philippe Bonin, Modification: Changer T2 par LED3_Orange
//
//INCLUSIONS
#include "main.h"
#include "../Pilote/piloteIOT2.h"
#include "interface_LED3_Orange.h"

//Definitions privees
//pas de definitions privees

//Declarations de fonctions privees:
//pas de fonction privees

//Definitions de variables privees:
//pas de variables privees

//Definitions de fonctions privees:
//pas de fonctions privees

//Definitions de variables publiques:
//pas de variables publiques

//Definitions de fonctions publiques:
void interface_LED3_Orange_allume(void)
{
  piloteIOT2_metLaSortieA(INTERFACE_LED3_ORANGE_VALEUR_POUR_ALLUMER);
}

void interface_LED3_Orange_eteint(void)
{
  piloteIOT2_metLaSortieA(INTERFACE_LED3_ORANGE_VALEUR_POUR_ETEINDRE);
}

void interface_LED3_Orange_initialise(void)
{
  piloteIOT2_metLaSortieA(INTERFACE_LED3_ORANGE_VALEUR_POUR_ETEINDRE);
}


