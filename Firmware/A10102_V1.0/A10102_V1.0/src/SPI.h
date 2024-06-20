/*
 * SPI.h
 *
 * Created: 14/12/2023 11:16:06 p. m.
 *  Author: Cesar M
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#include <stdint.h>

#define SPI_DDR DDRB
#define SPI_PORT PORTB
#define SPI_MOSI		3
#define SPI_MISO		4
#define SPI_SCK			5	

void SPI_Master_Init();
void SPI_Master_Transmitter(uint8_t Data);
float SPI_Master_Receiver();
void SPI_Slave_ON(uint8_t spi_ss);
void SPI_Slave_OFF(uint8_t spi_ss);


#endif /* SPI_H_ */