/*
 * LCD_16x2.c
 *
 * Created: 08/08/2023 10:48:22 p. m.
 *  Author: Cesar M
 */ 

#include "LCD_16X2.h"



void configLCDPorts(void)
{
	/* Configure the microprocessor pins for the data lines */
	LCD_DDR |= (1 << LCD_D7) | (1 << LCD_D6) | (1 << LCD_D5) | (1 << LCD_D4);
	
	/* Configure the microprocessor pins for the control lines */
	LCD_DDR |= (1 << LCD_RS) | (1 << LCD_EN) | (1 << LCD_RW);

}


void LCD_Init ()
{
	
	configLCDPorts();
	
	LCD_PORT &= ~(1 << LCD_RS);
	LCD_PORT &= ~(1 << LCD_EN);
	
	_delay_ms(15);
	LCD_Send_Data(0x03);
	_delay_ms(4.1);
	LCD_Send_Data(0x03);
	_delay_us(100);
	LCD_Send_Data(0x03);
	LCD_Send_Data(0x02);

	LCD_Is_Busy();
	LCD_Write_Instruction(LCD_FUNCTION_SET | LCD_4BITS | LCD_2LINES | LCD_5X8DOTS);

	LCD_Is_Busy();
	LCD_Write_Instruction(LCD_DISPLAY_CONTROL | LCD_DISPLAY_ON | LCD_CURSOR_ON | LCD_BLINK_ON);
	
	LCD_Is_Busy();
	LCD_Write_Instruction(LCD_CLEAR);
	
	//LCD_Is_Busy();
	//LCD_Write_Instruction(LCD_ROAM_CURSOR);
		
}

void LCD_Print(char *str)
{
	while (*str)
	{
		LCD_Write(*str);
		str++;
	}
}

void LCD_Write (uint8_t data)
{
	//LCD_Is_Busy();
	LCD_Parser(data);
}

void LCD_Write_Instruction(uint8_t data)
{
	//LCD_Is_Busy();
	LCD_PORT &= ~(1 << LCD_RS);
	LCD_PORT &= ~(1 << LCD_EN);
	LCD_Send_Data(4 >> data);
	LCD_Send_Data(data & 0x0F);
	
}

void LCD_Parser (uint8_t data)
{	
	LCD_PORT |= (1 << LCD_RS);
	LCD_PORT &= ~(1 << LCD_EN);
	LCD_Send_Data(4 >> data);
	LCD_Send_Data(data & 0x0F);
	
}


void LCD_Send_Data (uint8_t data)
{
	uint8_t mask[4] = {0};
	for (uint8_t i = 0; i < 4; i++)
	{
		if (data & 1 << (7 - i))
		{
			mask[i] = 1;
		}
	}
	
	LCD_PORT &= ~((1 << LCD_D7) | (1 << LCD_D6) | (1 << LCD_D5) | (1 << LCD_D4));
	LCD_PORT |= ((mask[3] << LCD_D7) | (mask[2] << LCD_D6) | (mask[1] << LCD_D5) | (mask[0] << LCD_D4));
	
	LCD_PORT |= (1 << LCD_EN);
	_delay_us(400);
	LCD_PORT &= ~(1 << LCD_EN);
	_delay_us(400);
	
		
}

void LCD_Is_Busy ()
{
	bool busy_flag; 
	
	LCD_DDR &= ~(1 << LCD_D7);
	LCD_PORT &= ~(1 << LCD_RS);
	LCD_PORT |= (1 << LCD_RW);
	
	
	do 
	{
		busy_flag = false;
		LCD_PORT |= (1 << LCD_EN);
		_delay_us(1);
		
		busy_flag |= (LCD_D7_Pin & (1 << LCD_D7));
		
		LCD_PORT &= ~(1 << LCD_EN);
		_delay_us(1);
		
		LCD_PORT |= (1 << LCD_EN);
		_delay_us(1);
		LCD_PORT &= ~(1 << LCD_EN);
		_delay_us(1);
		
	} while (busy_flag);
	
	LCD_PORT &= ~(1 << LCD_RW);
	LCD_DDR |= (1 << LCD_D7);
}

void LCD_Set_Cursor(uint8_t Row, uint8_t Col)
{
	static uint8_t local_mem [2] = {0x00, 0x40};
		LCD_Write_Instruction( LCD_SET_DDRAM | (local_mem[Row - 1] + (Col - 1)));		
}