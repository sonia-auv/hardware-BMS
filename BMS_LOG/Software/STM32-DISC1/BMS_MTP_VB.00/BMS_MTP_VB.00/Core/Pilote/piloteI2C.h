/*
 * piloteI2C.h
 *
 *  Created on: Jun 30, 2025
 *      Author: ilyes
 */

#ifndef PILOTE_PILOTEI2C_H_
#define PILOTE_PILOTEI2C_H_



/* Private includes ----------------------------------------------------------*/



/* Exported types ------------------------------------------------------------*/



/* Exported constants --------------------------------------------------------*/



/* Exported functions prototypes ---------------------------------------------*/

void piloteI2C_Write1Byte(unsigned char ucAddress,unsigned char ucI2C_Output);
unsigned char piloteI2C_Read1Byte(unsigned char ucAddress);
void piloteI2C_initialise(void);




#endif /* PILOTE_PILOTEI2C_H_ */
