/*
 * PCF8574.c
 *
 * Created: 26/03/2024 05:47:58 a. m.
 *  Author: Cesar M
 */ 

#include "PCF8574.h"


void PCF8574_Send_Data(uint8_t address, uint8_t data)
{
	while (TWI_start_condition());
	while (TWI_write_address(address, TWI_W));
	while (TWI_write_data(0x40));					//address to write
	while (TWI_write_data(data));						// value to register
	TWI_stop_condition();
	
}