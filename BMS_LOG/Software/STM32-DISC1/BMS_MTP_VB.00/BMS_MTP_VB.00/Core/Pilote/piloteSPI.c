/**
 * @file piloteSPI.c
 * @brief   Pilote SPI - Impl�mentation des fonctions pour la gestion du SPI
 * @author  [Votre Nom]
 * @date    [Date]
 */
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_spi.h"

#include "main.h"
#include "piloteSPI.h"



extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;

void Pilote_SPI1_Transmit(uint8_t* data, uint16_t size) {
    HAL_SPI_Transmit(&hspi1, data, size, 1000);
}

void Pilote_SPI1_Receive(uint8_t* buffer, uint16_t size) {
    HAL_SPI_Receive(&hspi1, buffer, size, 1000);
}

void piloteSPI_initialise(void)
{
	//ne fait rien, HAL lib does it for us
}
