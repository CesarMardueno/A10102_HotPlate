/*
 * PCF8574.c
 *
 * Created: 26/03/2024 05:47:58 a. m.
 *  Author: Cesar M
 */ 

#include "PCF8574.h"

uint8_t dato = 0;

void PCF8574_Port_Output(uint8_t address, uint8_t data)
{
	while (TWI_start_condition());
	while (TWI_write_address(address, TWI_W));
	while (TWI_write_data(0x40));						//address to write
	while (TWI_write_data(data));						// value to register
	TWI_stop_condition();
	
}

uint8_t PCF8574_Port_Input(uint8_t address)
{
	TWI_start_condition();
	TWI_write_address(address, TWI_W);
	TWI_write_data(0x41);				
	TWI_restart_condition();
	TWI_write_address(address, TWI_R);
	dato = TWI_read_data(TWI_NACK);							
	TWI_stop_condition();
	return dato;
}



/************************************************************************/
/*							Example code                                */
/************************************************************************/

// /*
// 
// int main(void)
// {	
// 	cli();
// 	LCD_Init();
// 	TWI_init(100000);
// 	sei();
// 	
// 	while (1)
// 	{
// 		PCF8574_Port_Output(0x27, 0xFF);
// 		_delay_ms(2000);
// 		PCF8574_Port_Output(0x27, 0x00);
// 		_delay_ms(2000);
// 		
// 	}
// 
// }*/