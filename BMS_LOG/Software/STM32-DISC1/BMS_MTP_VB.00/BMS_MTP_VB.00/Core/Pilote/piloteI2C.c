/*
 * piloteI2C.c
 *
 *  Created on: Jun 30, 2025
 *      Author: ilyes
 */


// *************************************************************************************************
//  INCLUDES
// *************************************************************************************************

#include "main.h"
#include <stdio.h>
#include "stdbool.h"
#include "string.h"
#include "piloteI2C.h"




// *************************************************************************************************
//  CONSTANTES
// *************************************************************************************************


// *************************************************************************************************
//  FONCTIONS LOCALES
// *************************************************************************************************


// *************************************************************************************************
//  STRUCTURES ET UNIONS
// *************************************************************************************************


// *************************************************************************************************
// VARIABLES GLOBALES
// *************************************************************************************************


extern I2C_HandleTypeDef hi2c1;

// *************************************************************************************************
// VARIABLES LOCALES
// *************************************************************************************************


/** Auteur               : Philippe  Bonin
  * Date de création     : 24-11-2022
  * @brief               : Transmission I2C
  */
int piloteI2C_Write1Byte(unsigned char ucAddress,unsigned char ucI2C_Output)
 {
   unsigned char ucOutput= ucI2C_Output;
   if (HAL_I2C_Master_Transmit(&hi2c1, ucAddress, &ucOutput, 1, 50) != HAL_OK)
   {
     // Handle error: you can log, set an error flag>, or return a default value
     // For now, return -1 to indicate error
     return -1;
   }
   return 0;
}
///////////////////////////////////////////////////////////////////////////////


/** Auteur               : Philippe  Bonin
  * Date de création     : 24-11-2022
  * @brief               : Reception I2C
  */
unsigned char piloteI2C_Read1Byte(unsigned char ucAddress)
 {
  unsigned char ucI2C_Input = 0;
  if (HAL_I2C_Master_Receive(&hi2c1, ucAddress, &ucI2C_Input, 2, 50) != HAL_OK)    // Lire touche
  {
    // Handle error: you can log, set an error flag, or return a default value
    // For now, return 0xFF to indicate error
    return 0xFF;
  }
  return (ucI2C_Input);
 }
///////////////////////////////////////////////////////////////////////////////


/** Auteur               : Philippe  Bonin
  * Date de création     : 24-11-2022
  * @brief               :
  */
void piloteI2C_initialise(void)
 {
   // faite par le cubeMX et la librarie HAL
 }
///////////////////////////////////////////////////////////////////////////////



