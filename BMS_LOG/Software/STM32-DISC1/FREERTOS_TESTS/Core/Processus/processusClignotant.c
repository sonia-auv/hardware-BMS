//processusClignotant:
//Historique: 
// Ilyes Gharmoul


//INCLUSIONS
#include "main.h"

#include "../Interface/interfaceB1.h"

#include "../Interface/interface_LED3_Orange.h"
#include "../Interface/interface_LED4_Vert.h"
#include "../Interface/interface_LED5_Rouge.h"
#include "../Interface/interface_LED6_Blue.h"

#include "../Service/serviceBaseDeTemps.h"
#include "../Processus/processusClignotant.h"


//Definitions privees
#define PROCESSUSCLIGNOTANT_COMPTE_COURT_ETEINT (\
  PROCESSUSCLIGNOTANT_TEMPS_COURT_ETEINT_EN_MS * FREQUENCE_DE_LA_BASE_DE_TEMPS_EN_HZ \
  /1000.0)
#define PROCESSUSCLIGNOTANT_COMPTE_COURT_ALLUME (\
  PROCESSUSCLIGNOTANT_TEMPS_COURT_ALLUME_EN_MS * FREQUENCE_DE_LA_BASE_DE_TEMPS_EN_HZ \
  /1000.0)
#define PROCESSUSCLIGNOTANT_COMPTE_LONG_ETEINT (\
  PROCESSUSCLIGNOTANT_TEMPS_LONG_ETEINT_EN_MS * FREQUENCE_DE_LA_BASE_DE_TEMPS_EN_HZ \
  /1000.0)
#define PROCESSUSCLIGNOTANT_COMPTE_LONG_ALLUME (\
  PROCESSUSCLIGNOTANT_TEMPS_LONG_ALLUME_EN_MS * FREQUENCE_DE_LA_BASE_DE_TEMPS_EN_HZ \
  /1000.0)


//Declarations de fonctions privees:

unsigned int processusClignotant_compteur;

//Definitions de variables privees:

  
//Definitions de fonctions privees:

void processusClignotant_blue_AllumeLongtemps(void)
{
	  processusClignotant_compteur++;
	  if (interfaceB1.etatDuBouton == INTERFACEB1_APPUYE)
	  {
		  interface_LED6_Blue_eteint();
		  serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
		  processusClignotant_orange_AllumeLongtemps;
	  }
	  if (processusClignotant_compteur < PROCESSUSCLIGNOTANT_COMPTE_LONG_ALLUME)
	  {
	    return;
	  }
	  processusClignotant_compteur = 0;
	  interface_LED6_Blue_allume();
	  serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
	  processusClignotant_blue_Eteint_court;
}

void processusClignotant_blue_Eteint_court(void)
{
	  processusClignotant_compteur++;
	  if (processusClignotant_compteur < PROCESSUSCLIGNOTANT_COMPTE_LONG_ALLUME*2)
	  {
	    return;
	  }
	  processusClignotant_compteur = 0;
	  interface_LED6_Blue_eteint();
	  serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
	processusClignotant_blue_AllumeLongtemps;
}

void processusClignotant_orange_AllumeLongtemps(void)
{
	  processusClignotant_compteur++;
	  if (interfaceB1.etatDuBouton == INTERFACEB1_APPUYE)
	  {
		  interface_LED3_Orange_eteint();
		  serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
		  processusClignotant_blue_AllumeLongtemps;
	  }
	  if (processusClignotant_compteur < PROCESSUSCLIGNOTANT_COMPTE_LONG_ALLUME)
	  {
	    return;
	  }
	  processusClignotant_compteur = 0;
	  interface_LED3_Orange_allume();
	  serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
	  processusClignotant_orange_Eteint_court;
}

void processusClignotant_orange_Eteint_court(void)
{
	  processusClignotant_compteur++;
	  if (processusClignotant_compteur < PROCESSUSCLIGNOTANT_COMPTE_LONG_ALLUME*2)
	  {
	    return;
	  }
	  processusClignotant_compteur = 0;
	  interface_LED3_Orange_eteint();
	  serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
	  processusClignotant_orange_AllumeLongtemps;
}
//Definitions de variables publiques:
// Aucune variable publique
//Definitions de fonctions publiques:


//fonction publiques:

/** @brief Initialisation @param @retval */
void processusClignotant_initialise(void)
{
  processusClignotant_compteur = 0;
  serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
    processusClignotant_orange_AllumeLongtemps;
}
