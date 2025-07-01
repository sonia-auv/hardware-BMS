/*
 * processusEPD.h
 *
 *  Created on: Jun 30, 2025
 *      Author: ilyes
 */

#ifndef PROCESSUS_PROCESUSEPD_H_
#define PROCESSUS_PROCESUSEPD_H_
//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles
//(copiez et adaptez ce qui suit dans "main.h")
//pas de dependances materielles

//Dependances logicielles
//(copiez et adaptez ce qui suit dans "main.h")

//INFORMATION PUBLIQUE:
//Definitions publiques:
//pas de definitions publiques

//Fonctions publiques:
void processusEPD_initialise(void);
void processusEPD_request_init(void);
void processusEPD_rst_waiting_busy(void);
void processusEPD_post_reset(void);
void processusEPD_Affichage_bootscreen(void);
void processusEPD_Affichage_waiting_refresh_1(void);
void processusEPD_Affichage_waiting_refresh_2(void);
void processusEPD_Affichage_waiting_refresh_postdelay500(void);
void processusEPD_Affichage_waiting_refresh_postdelay2000(void);

//Variables publiques:
//pas de variables publiques



#endif /* PROCESSUS_PROCESUSEPD_H_ */

