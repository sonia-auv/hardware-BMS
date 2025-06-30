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
#include "processusClignotant.h"

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

// --- Fonctions d'initialisation ---
/** @brief Initialisation @param @retval */
void processusClignotant_initialise(void)
{
	processusClignotant_compteur = 0;
	serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
			processusClignotant_blue_AllumeLongtemps;
}

// --- Fonctions pour LED BLEUE ---
void processusClignotant_blue_AllumeLongtemps(void)
{
	interface_LED6_Blue_allume();
	processusClignotant_compteur++;
	if (interfaceB1.etatDuBouton == INTERFACEB1_APPUYE)
	{
		processusClignotant_compteur = 0;
		interface_LED6_Blue_eteint();
		serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
		processusClignotant_blue_AllumeCourt_relache;
	}
	if (processusClignotant_compteur < PROCESSUSCLIGNOTANT_COMPTE_LONG_ALLUME)
	{
		return;
	}
	processusClignotant_compteur = 0;
	serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
		processusClignotant_blue_EteintLongtemps;
}

void processusClignotant_blue_EteintLongtemps(void)
{
	interface_LED6_Blue_eteint();
	processusClignotant_compteur++;
	if (processusClignotant_compteur < PROCESSUSCLIGNOTANT_COMPTE_LONG_ETEINT)
	{
		return;
	}
	processusClignotant_compteur = 0;
	serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
			processusClignotant_blue_AllumeLongtemps;
}

void processusClignotant_blue_AllumeCourt_relache(void)
{
	if (interfaceB1.etatDuBouton == INTERFACEB1_APPUYE)
	{
		return;
	}
	serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
		processusClignotant_blue_AllumeCourt;
}

void processusClignotant_blue_AllumeCourt(void)
{
	interface_LED6_Blue_allume();
	processusClignotant_compteur++;
	if (interfaceB1.etatDuBouton == INTERFACEB1_APPUYE)
	{
		processusClignotant_compteur = 0;
		serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
			processusClignotant_blue_AllumeLongtemps_relache;
	}
	if (processusClignotant_compteur < PROCESSUSCLIGNOTANT_COMPTE_COURT_ALLUME)
	{
		return;
	}
	processusClignotant_compteur = 0;
	serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
		processusClignotant_blue_EteintCourt;
}

void processusClignotant_blue_EteintCourt(void)
{
	interface_LED6_Blue_eteint();
	processusClignotant_compteur++;
	if (processusClignotant_compteur < PROCESSUSCLIGNOTANT_COMPTE_COURT_ETEINT)
	{
		return;
	}
	processusClignotant_compteur = 0;
	serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
			processusClignotant_blue_AllumeCourt;
}

void processusClignotant_blue_AllumeLongtemps_relache(void)
{
	if (interfaceB1.etatDuBouton == INTERFACEB1_APPUYE)
	{
		return;
	}
	serviceBaseDeTemps_execute[PROCESSUSCLIGNOTANT_PHASE] =
			processusClignotant_blue_AllumeLongtemps;
}



//Definitions de variables publiques:
// Aucune variable publique
//Definitions de fonctions publiques:
//fonction publiques:
