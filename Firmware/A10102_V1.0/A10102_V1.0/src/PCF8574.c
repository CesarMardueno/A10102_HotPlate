/*
 * PCF8574.c
 *
 * Created: 26/03/2024 05:47:58 a. m.
 *  Author: Cesar M
 */ 

#include "PCF8574.h"

void Send_Data()
{
	TWI_start_conditionn();
	TWI_write_address( Address, 1);
	TWI_write_data();
}