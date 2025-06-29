//interface_LED6_Blue:

//Historique: 
// 2018-09-30, Yves Roy, creation
// 2022-12-10, Philippe Bonin, Modification: Changer T1 par LED6_Blue
//
 
//INCLUSIONS
#include "main.h"
#include "../Pilote/piloteIOT1.h"
#include "interface_LED6_Blue.h"

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
void interface_LED6_Blue_allume(void)
{
  piloteIOT1_metLaSortieA(INTERFACE_LED6_BLUE_VALEUR_POUR_ALLUMER);
}

void interface_LED6_Blue_eteint(void)
{
  piloteIOT1_metLaSortieA(INTERFACE_LED6_BLUE_VALEUR_POUR_ETEINDRE);
}

void interface_LED6_Blue_initialise(void)
{
  piloteIOT1_metLaSortieA(INTERFACE_LED6_BLUE_VALEUR_POUR_ETEINDRE);
}

