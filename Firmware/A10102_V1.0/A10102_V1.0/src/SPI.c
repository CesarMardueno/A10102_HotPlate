/*
 * SPI.c
 *
 * Created: 14/12/2023 11:16:17 p. m.
 *  Author: Cesar M
 */ 

#include "SPI.h"

void SPI_Master_Init(uint8_t Port0, uint8_t SS0, uint8_t MOSI0, uint8_t MISO0, uint8_t SCK0)
{
	//SS0, MOSI and SCK made as output
	Port0 |= (1 << SS0) | (1 << MOSI0) | (1 << SCK0);
	//Eneable SPI Comunication, Master mode, and Clock Frecuency 
	SPCR |= (1 << SPE) | (1 << MSTR) | ( 1<< SPR0);
	//Eneable finish transfer Interrupt
	SPCR |= (1 << SPIE);
}

void SPI_Master_Transmitter(uint8_t Port0, uint8_t SS0, uint8_t Data)
{
	Port0 &= ~(1 << SS0);
	SPDR = Data;
	while(!(SPDR & (1 << SPIF)));
	Port0 |= (1 << SS0);
}

uint16_t SPI_Master_Receiver(uint8_t Port0, uint8_t SS0, uint8_t Data)
{
	Port0 &= ~(1 << SS0);
	Data = SPDR;
	while(!(SPDR & (1 << SPIF)));
	Port0 |= (1 << SS0);
	return Data;
}