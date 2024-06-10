/*
 * MAX6675.c
 *
 * Created: 14/12/2023 06:10:49 a. m.
 *  Author: Cesar M
 */ 

#include "MAX6675.h"

uint16_t Temperature_Read(uint8_t spi_read, uint8_t spi_slave)
{
	uint8_t temp = 0;
	
	uint8_t highByte = SPI_Master_Receiver();
	uint8_t lowByte = SPI_Master_Receiver();
	SPI_Slave_ON(spi_slave);
	if (lowByte & (1<<2)) {
		return -400;
	}
	else {
		temp = (highByte << 5 | lowByte>>3);
	}
	SPI_Slave_OFF(spi_slave);
	return temp;
}