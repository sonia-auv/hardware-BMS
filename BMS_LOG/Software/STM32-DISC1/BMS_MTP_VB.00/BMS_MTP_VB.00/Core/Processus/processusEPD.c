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
		processusEPD_rst_waiting_busy;

}

void processusEPD_rst_waiting_busy(void)
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
	interface_LED4_Vert_eteint();
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
	uint8_t* imagenoir;
	uint16_t imagesize = ((EPD_3IN52_WIDTH % 8 == 0) ? (EPD_3IN52_WIDTH / 8) : (EPD_3IN52_WIDTH / 8 + 1)) * EPD_3IN52_HEIGHT;
	if ((imagenoir = (uint8_t*)malloc(imagesize)) == NULL)
	{
		uart_len = sprintf(uart_buf, "Failed to apply for black memory...\r\n");
		HAL_UART_Transmit(&huart2, (uint8_t*)uart_buf, uart_len, HAL_MAX_DELAY);
		return -1;
	}
	Paint_NewImage(imagenoir, EPD_3IN52_WIDTH, EPD_3IN52_HEIGHT, ROTATE_270, WHITE);
	Paint_Clear(WHITE);

	Paint_SelectImage(imagenoir);
	Paint_Clear(WHITE);
	Paint_DrawBitMap(gImage_Didou);

	EPD_352_display(imagenoir);
	EPD_352_lut_GC();
	interfaceEPD.request = INTERFACEEPD_REQUEST_REFRESH;
	serviceBaseDeTemps_execute[PROCESSUSEPD_PHASE] = processusEPD_Affichage_waiting_refresh_2;
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
	serviceBaseDeTemps_execute[PROCESSUSEPD_PHASE] = processusEPD_Affichage_printingbootscreen;
}
