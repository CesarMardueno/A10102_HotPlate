/*
 * PCF8574.c
 *
 * Created: 26/03/2024 05:47:58 a. m.
 *  Author: Cesar M
 */ 


void Send_Data()
{
	TWI_start_conditionn();
	TWI_write_address();
}