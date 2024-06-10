/*
* A10102_V1.0.c
*
* Created: 18/07/2023 10:51:41 p. m.
* Author : Cesar M
*/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "LCD_16x2.h"
#include "PCF8574.h"
#include "AT328_TWI.h"
#include "LCD_16x2_TWI.h"
#include "SPI.h"

#define Slave1 1

uint8_t count = 0;


int main(void)
{	
	DDRB |= (1 << Slave1);
	cli();
	TWI_LCD_init(100000);
	SPI_Master_Init();
	sei();
	
	while (1)
	{
		count++;
		SPI_Slave_ON(Slave1);
		uint16_t temp = SPI_Master_Receiver();
		//_delay_ms(6000);
		SPI_Slave_OFF(Slave1);
		
		//uint16_t temp = Temperature_Read(SPI_Master_Receiver(), Slave1);
		
		TWI_LCD_Set_Cursor(1,1);
		TWI_LCD_Printf("Temp: %d", temp);
		TWI_LCD_Set_Cursor(2,1);
		TWI_LCD_Printf("Temp: %d", count);
		_delay_ms(500);
		
		
	}

}
