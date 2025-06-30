/*
 * piloteSPI.h
 *
 *  Created on: Jun 30, 2025
 *      Author: ilyes
 */

#ifndef PILOTE_PILOTESPI_H_
#define PILOTE_PILOTESPI_H_


void Pilote_SPI1_Transmit(uint8_t* data, uint16_t size);
void Pilote_SPI1_Receive(uint8_t* buffer, uint16_t size);
void piloteSPI_initialise(void);


#endif /* PILOTE_PILOTESPI_H_ */
