/*
 * SPI.h
 *
 * Created: 14/12/2023 11:16:06 p. m.
 *  Author: Cesar M
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>

void SPI_Master_Init(uint8_t Port, uint8_t SS0, uint8_t MOSI0, uint8_t MISO0, uint8_t SCK0);
void SPI_Master_Transmitter(uint8_t Port0, uint8_t SS0, uint8_t Data);
uint16_t SPI_Master_Receiver(uint8_t Port0, uint8_t SS0, uint8_t Data);


#endif /* SPI_H_ */