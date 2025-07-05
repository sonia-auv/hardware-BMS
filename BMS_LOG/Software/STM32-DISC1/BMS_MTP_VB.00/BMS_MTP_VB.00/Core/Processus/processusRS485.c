/*
 * processusRS485.c
 *
 *  Created on: Jun 30, 2025
 *      Author: ilyes
 */

// INCLUSIONS
#include "main.h"

#include "../Service/serviceBaseDeTemps.h"
#include "processusRS485.h"

// Definitions privees

// Declarations de fonctions privees:
unsigned int processusRS485_compteur;

// Definitions de variables privees:

// Definitions de fonctions privees:

// --- Fonctions d'initialisation ---

void processusRS485_waitingHandShake(void)
{
    // A definir selon le protocole RS485
}

/** @brief Initialisation @param @retval */
void processusRS485_initialise(void)
{
    processusRS485_compteur = 0;
    serviceBaseDeTemps_execute[PROCESSUSRS485_PHASE] =
        processusRS485_waitingHandShake;
}

// --- Fonctions pour gestion RS485 ---
