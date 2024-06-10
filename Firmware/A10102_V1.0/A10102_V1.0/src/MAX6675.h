/*
 * MAX6675.h
 *
 * Created: 14/12/2023 06:10:39 a. m.
 *  Author: Cesar M
 */ 


#ifndef MAX6675_H_
#define MAX6675_H_

#include <avr/io.h>
#include <util/delay.h>

#include "SPI.h"

uint16_t Temperature_Read(uint8_t spi_read, uint8_t spi_slave);

#endif /* MAX6675_H_ */