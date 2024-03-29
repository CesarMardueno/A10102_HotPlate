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
	
	while (1)
	{
		//LCD_Set_Cursor(1,2);
		//LCD_Print("Hola");
		//LCD_Set_Cursor(2,6);
		//LCD_Write(8);
		LCD_Write_Instruction(LCD_CLEAR);
		//LCD_Write_Instruction(LCD_Cursor);
	}

}
