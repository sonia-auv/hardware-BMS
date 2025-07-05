/*
 * processusEPD.c
 *
 *  Created on: Jun 30, 2025
 *      Author: ilyes
 */
 //INCLUSIONS
#include "main.h"
#include <stdlib.h>
#include "../Pilote/piloteI2C.h"
#include "../Pilote/piloteSPI_EPAPER.h"
#include "../Interface/interface_LED4_Vert.h"
#include "../Interface/interface_LED3_Orange.h"
#include "../Interface/EPD_352_Interface.h"
#include "../Service/serviceBaseDeTemps.h"
#include "../Interface/fonts.h"
#include "../Interface/GUI_Paint.h"
#include "../Interface/ImageData.h"
#include "processusEPD.h"

//Definitions privees


//Declarations de fonctions privees:

unsigned int processusEPD_compteur;
uint8_t* image;
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
	interfaceEPD.request = INTERFACEEPD_REQUEST_INITIALISE;
	serviceBaseDeTemps_execute[PROCESSUSEPD_PHASE] =
			processusEPD_rst_waiting_rst;

}

void processusEPD_rst_waiting_rst(void)
{
	processusEPD_compteur++;
	// If the delay is not reached and a request is still pending, stay in this process
	if (processusEPD_compteur < PROCESSUSEPD_TEMPS_RST_MS)
	{
		if (interfaceEPD.request != INTERFACEEPD_REQUEST_NONE)
		{
			// If a request is pending, we stay in this process
			return;
		}
	}
	// Otherwise, the delay is reached or no request is pending, so we can move on
	processusEPD_compteur = 0;
	serviceBaseDeTemps_execute[PROCESSUSEPD_PHASE] =
		processusEPD_post_reset;
}
void processusEPD_post_reset(void)
{
	EPD_352_Init();
	serviceBaseDeTemps_execute[PROCESSUSEPD_PHASE] =
		processusEPD_Affichage_bootscreen;
}

void processusEPD_Affichage_bootscreen(void)
{
	EPD_352_display_NUM(EPD_3IN52_BLACK);
	EPD_352_lut_GC();
	interfaceEPD.request = INTERFACEEPD_REQUEST_REFRESH;
	serviceBaseDeTemps_execute[PROCESSUSEPD_PHASE] =
		processusEPD_Affichage_waiting_refresh_1;

}
void processusEPD_Affichage_waiting_refresh_1(void)
{
	processusEPD_compteur++;
	if (processusEPD_compteur < PROCESSUSEPD_TEMPS_REFRESH_MS)
	{
		if (interfaceEPD.request != INTERFACEEPD_REQUEST_NONE)
		{
			// If a request is pending, we stay in this process
			return;
		}
	}
	processusEPD_compteur = 0;
	EPD_352_SendCommand(0x50);
	EPD_352_SendData(0x17);
	serviceBaseDeTemps_execute[PROCESSUSEPD_PHASE] =
		processusEPD_Affichage_waiting_refresh_postdelay500;
}
void processusEPD_Affichage_waiting_refresh_postdelay500(void)
{
	processusEPD_compteur++;
	if (processusEPD_compteur < PROCESSUSEPD_TEMPS_500_MS)
	{
		return;
	}
	processusEPD_compteur = 0;
	serviceBaseDeTemps_execute[PROCESSUSEPD_PHASE] = processusEPD_Affichage_printingbootscreen;
}
void processusEPD_Affichage_printingbootscreen(void)
{

	uint16_t imagesize = ((EPD_3IN52_WIDTH % 8 == 0) ? (EPD_3IN52_WIDTH / 8) : (EPD_3IN52_WIDTH / 8 + 1)) * EPD_3IN52_HEIGHT;
	if ((image = (uint8_t*)malloc(imagesize)) == NULL)
	{
		free(image);
		interface_LED4_Vert_allume();
		serviceBaseDeTemps_execute[PROCESSUSEPD_PHASE] = processusEPD_Affichage_printingbootscreen;
	}
	else
	{
		Paint_NewImage(image, EPD_3IN52_WIDTH, EPD_3IN52_HEIGHT, ROTATE_270, WHITE);
		Paint_Clear(WHITE);
		Paint_SelectImage(image);
		Paint_Clear(WHITE);
		Paint_DrawBitMap(gImage_Didou);
		EPD_352_display(image);
		EPD_352_lut_GC();
		interfaceEPD.request = INTERFACEEPD_REQUEST_REFRESH;
		serviceBaseDeTemps_execute[PROCESSUSEPD_PHASE] = processusEPD_Affichage_waiting_refresh_2;
	}

}
void processusEPD_Affichage_waiting_refresh_2(void)
{
	processusEPD_compteur++;
	if (processusEPD_compteur < PROCESSUSEPD_TEMPS_REFRESH_MS)
	{
		if (interfaceEPD.request != INTERFACEEPD_REQUEST_NONE)
		{
			// If a request is pending, we stay in this process
			return;
		}
	}
	processusEPD_compteur = 0;
	serviceBaseDeTemps_execute[PROCESSUSEPD_PHASE] = processusEPD_Affichage_waiting_refresh_postdelay2000;
}
void processusEPD_Affichage_waiting_refresh_postdelay2000(void)
{
	processusEPD_compteur++;
	if (processusEPD_compteur < PROCESSUSEPD_TEMPS_2000_MS)
	{
		return;
	}
	processusEPD_compteur = 0;
	serviceBaseDeTemps_execute[PROCESSUSEPD_PHASE] = processusEPD_Affichage_removingbootscreen;
}
void processusEPD_Affichage_removingbootscreen(void)
{
	Paint_SelectImage(image);
	Paint_Clear(WHITE);
	EPD_352_lut_GC();
	interfaceEPD.request = INTERFACEEPD_REQUEST_REFRESH;
	serviceBaseDeTemps_execute[PROCESSUSEPD_PHASE] = processusEPD_Affichage_waiting_refresh_3;
	return;

}
void processusEPD_Affichage_waiting_refresh_3(void)
{
	processusEPD_compteur++;
	if (processusEPD_compteur < PROCESSUSEPD_TEMPS_REFRESH_MS)
	{
		if (interfaceEPD.request != INTERFACEEPD_REQUEST_NONE)
		{
			// If a request is pending, we stay in this process
			return;
		}
	}
	processusEPD_compteur = 0;
	EPD_352_display(image);
	Paint_SelectImage(image);
	Paint_Clear(WHITE);
	serviceBaseDeTemps_execute[PROCESSUSEPD_PHASE] = processusEPD_Affichage_loop;
	return;
}
void processusEPD_Affichage_loop(void)
{

}

