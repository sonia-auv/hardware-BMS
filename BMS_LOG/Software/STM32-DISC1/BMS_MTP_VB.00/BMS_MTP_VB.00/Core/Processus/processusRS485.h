/*
 * processusRS485.h
 *
 *  Created on: Jun 30, 2025
 *      Author: ilyes
 */

#ifndef PROCESSUS_PROCESSUSRS485_H_
#define PROCESSUS_PROCESSUSRS485_H_

//MODULE: processusRS485
//DESCRIPTION: Impl�mente la gestion de la communication RS485.

//HISTORIQUE:
// 2025-06-30, ilyes, cr�ation

//DEFINITIONS REQUISES PAR LE MODULE:
//D�pendances mat�rielles
//(copiez et adaptez ce qui suit dans "main.h")
//pas de d�pendances mat�rielles

//D�pendances logicielles
//(copiez et adaptez ce qui suit dans "main.h")
//#define PROCESSUSRS485_BAUDRATE 115200
//#define PROCESSUSRS485_TIMEOUT_MS 100

//INFORMATION PUBLIQUE:
//D�finitions publiques:
//pas de d�finitions publiques

//Fonctions publiques:
void processusRS485_initialise(void);
void processusRS485_waitingHandShake(void);

//Variables publiques:
//pas de variables publiques

#endif /* PROCESSUS_PROCESSUSRS485_H_ */
