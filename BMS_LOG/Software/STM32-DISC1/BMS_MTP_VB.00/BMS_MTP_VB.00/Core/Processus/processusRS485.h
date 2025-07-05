/*
 * processusRS485.h
 *
 *  Created on: Jun 30, 2025
 *      Author: ilyes
 */

#ifndef PROCESSUS_PROCESSUSRS485_H_
#define PROCESSUS_PROCESSUSRS485_H_

//MODULE: processusRS485
//DESCRIPTION: Implémente la gestion de la communication RS485.

//HISTORIQUE:
// 2025-06-30, ilyes, création

//DEFINITIONS REQUISES PAR LE MODULE:
//Dépendances matérielles
//(copiez et adaptez ce qui suit dans "main.h")
//pas de dépendances matérielles

//Dépendances logicielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define PROCESSUSRS485_BAUDRATE 115200
//#define PROCESSUSRS485_TIMEOUT_MS 100

//INFORMATION PUBLIQUE:
//Définitions publiques:
//pas de définitions publiques

//Fonctions publiques:
void processusRS485_initialise(void);
void processusRS485_waitingHandShake(void);

//Variables publiques:
//pas de variables publiques

#endif /* PROCESSUS_PROCESSUSRS485_H_ */
