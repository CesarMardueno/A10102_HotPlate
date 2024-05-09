/*
* A10102_V1.0.c
*
* Created: 18/07/2023 10:51:41 p. m.
* Author : Cesar M
*/

#include <avr/io.h>
#include <util/delay.h>
#include "LCD_16x2.h"



int main(void)
{	
	LCD_Init();
	//LCD_Write_Instruction(LCD_DISPLAY_CONTROL | LCD_CURSOR_OFF | LCD_BLINK_OFF);
	
	while (1)
	{
		int l = 8;
		LCD_Set_Cursor(1,1);
		LCD_Printf("El numero es: %02d", l);
		
	}

}
