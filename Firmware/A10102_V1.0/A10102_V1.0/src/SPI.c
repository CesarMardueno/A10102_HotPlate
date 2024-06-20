/*
 * SPI.c
 *
 * Created: 14/12/2023 11:16:17 p. m.
 *  Author: Cesar M
 */ 

#include "SPI.h"

void SPI_Master_Init()
{
	//SS0, MOSI and SCK made as output
	SPI_DDR |=  (1 << SPI_SCK) | (1 << SPI_MOSI);
	SPI_DDR &= ~(1 << SPI_MISO);
			
	SPCR &= ~(1 << DORD);
	SPCR &= ~(1 << CPOL);
	SPCR &= ~(1 << CPHA);
	
	//Enable SPI Communication, Master mode, and Clock Frequency 
	SPCR |= (1 << SPE) | (1 << MSTR) | ( 1<< SPR0);
	SPCR &= ~( 1<< SPR1);
	SPCR &= ~(1<< SPI2X);
	
	//Enable finish transfer Interrupt
	SPCR |= (1 << SPE);
}

void SPI_Master_Transmitter(uint8_t Data)
{
	
	SPDR = Data;
	while(!(SPSR & (1 << SPIF)));
	
}

float SPI_Master_Receiver()
{
	SPDR = 0xff;
	while(!(SPSR & (1 << SPIF)));
	return SPDR;
}

void SPI_Slave_ON(uint8_t spi_ss)
{
	SPI_PORT &= ~(1 << spi_ss);
}

void SPI_Slave_OFF(uint8_t spi_ss)
{
	SPI_PORT |= (1 << spi_ss);
}


/*SPI_Slave_ON(Slave1);
		uint16_t temp = SPI_Master_Receiver();
		_delay_ms(6000);
		SPI_Slave_OFF(Slave1);*/