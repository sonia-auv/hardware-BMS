/*
 * processusEPD.c
 *
 *  Created on: Jun 30, 2025
 *      Author: ilyes
 */
 //INCLUSIONS
#include "main.h"

#include "../Pilote/piloteI2C.h"
#include "../Pilote/piloteSPI_EPAPER.h"
#include "../Interface/interface_LED4_Vert.h"
#include "../Interface/EPD_352_Interface.h"
#include "../Service/serviceBaseDeTemps.h"
#include "processusEPD.h"

//Definitions privees


//Declarations de fonctions privees:

unsigned int processusEPD_compteur;

//Definitions de variables privees:

//Definitions de fonctions privees:

// --- Fonctions d'initialisation ---

/** @brief Initialisation @param @retval */
void processusEPD_initialise(void)
{
	//EPD_352_Init();
	processusEPD_compteur = 0;
	serviceBaseDeTemps_execute[PROCESSUSEPD_PHASE] =
			processusEPD_request_init;
}
void processusEPD_request_init(void)
{
	interface_LED4_Vert_allume();
	interfaceEPD.request = INTERFACEEPD_REQUEST_INITIALISE;
	serviceBaseDeTemps_execute[PROCESSUSEPD_PHASE] =
		processusEPD_rst_delay_400_MS;

}

void processusEPD_rst_delay_400_MS(void)
{
	processusEPD_compteur++;
	if (processusEPD_compteur < PROCESSUSEPD_TEMP_RST_MS)
	{
		return;
	}
	processusEPD_compteur =0;
	serviceBaseDeTemps_execute[PROCESSUSEPD_PHASE] =
		processusEPD_post_reset;
}
void processusEPD_post_reset(void)
{
	interface_LED4_Vert_eteint();
}

// --- Fonctions pour LED BLEUE ---
