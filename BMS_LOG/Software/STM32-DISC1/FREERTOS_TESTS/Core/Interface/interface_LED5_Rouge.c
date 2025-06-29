//interface_LED5_Rouge:
//Historique: 
// 2018-09-30, Yves Roy, creation
// 2022-12-10, Philippe Bonin, Modification: Changer T4 par LED5_Rouge

//INCLUSIONS
#include "main.h"
#include "../Pilote/piloteIOT4.h"
#include "interface_LED5_Rouge.h"

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
void interface_LED5_Rouge_allume(void)
{
  piloteIOT4_metLaSortieA(INTERFACE_LED5_ROUGE_VALEUR_POUR_ALLUMER);
}

void interface_LED5_Rouge_eteint(void)
{
  piloteIOT4_metLaSortieA(INTERFACE_LED5_ROUGE_VALEUR_POUR_ETEINDRE);
}

void interface_LED5_Rouge_initialise(void)
{
  piloteIOT4_metLaSortieA(INTERFACE_LED5_ROUGE_VALEUR_POUR_ETEINDRE);
}
