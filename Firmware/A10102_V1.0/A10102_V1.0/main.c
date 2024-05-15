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





int main(void)
{	
	cli();
	LCD_Init();
	DDRC &= ~(( 1 << PORTC5) | ( 1 << PORTC4));
	PORTC |= (( 1 << PORTC5) | ( 1 << PORTC4));
	TWI_init(100000);
	//LCD_Write_Instruction(LCD_DISPLAY_CONTROL | LCD_CURSOR_OFF | LCD_BLINK_OFF);
	sei();
	
	while (1)
	{
		int l = 8;
		//LCD_Set_Cursor(1,1);
		LCD_Printf("El numero es: %02d", l);
		PCF8574_Send_Data(0x27, 0xFF);
		_delay_ms(2000);
		PCF8574_Send_Data(0x27, 0x00);
		_delay_ms(2000);
		
	}

}
