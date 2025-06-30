//interface_LED4_Vert:
//Historique: 
// 2018-09-30, Yves Roy, creation
// 2022-12-10, Philippe Bonin, Modification: Changer T3 par LED4_Vert

//INCLUSIONS
#include "main.h"
#include "../Pilote/piloteIOT3.h"
#include "interface_LED4_Vert.h"

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
void interface_LED4_Vert_allume(void)
{
  piloteIOT3_metLaSortieA(INTERFACE_LED4_VERT_VALEUR_POUR_ALLUMER);
}

void interface_LED4_Vert_eteint(void)
{
  piloteIOT3_metLaSortieA(INTERFACE_LED4_VERT_VALEUR_POUR_ETEINDRE);
}

void interface_LED4_Vert_initialise(void)
{
  piloteIOT3_metLaSortieA(INTERFACE_LED4_VERT_VALEUR_POUR_ETEINDRE);
}
