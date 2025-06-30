/*
 * processusBMS.c
 *
 *  Created on: Jun 30, 2025
 *      Author: ilyes
 */
//INCLUSIONS
#include "main.h"

#include "../Service/serviceBaseDeTemps.h"
#include "processusBMS.h"

//Definitions privees


//Declarations de fonctions privees:

unsigned int processusBMS_compteur;

//Definitions de variables privees:

//Definitions de fonctions privees:

// --- Fonctions d'initialisation ---


void processusBMS_waitingHandShake(void)
{
// Idk lol guess we gotta discute wtf we doing
}


/** @brief Initialisation @param @retval */
void processusBMS_initialise(void)
{
	processusBMS_compteur = 0;
	serviceBaseDeTemps_execute[PROCESSUSBMS_PHASE] =
			processusBMS_waitingHandShake;
}

// --- Fonctions pour LED BLEUE ---
