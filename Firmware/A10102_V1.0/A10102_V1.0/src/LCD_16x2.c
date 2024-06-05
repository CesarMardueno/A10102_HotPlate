/*
 * LCD_16x2.c
 *
 * Created: 08/08/2023 10:48:22 p. m.
 *  Author: Cesar M
 */ 

#include "LCD_16X2.h"

static char lcd_buffer [N_Colum + 1];

void configLCDPorts(void)
{
	
	/* Configure the microprocessor pins for the data lines */
	LCD_DDR |= ((1 << LCD_D7) | (1 << LCD_D6) | (1 << LCD_D5) | (1 << LCD_D4));
	
	/* Configure the microprocessor pins for the control lines */
	LCD_DDR |= ((1 << LCD_RS) | (1 << LCD_EN) | (1 << LCD_RW));
	
	LCD_PORT &= ~((1 << LCD_D7) | (1 << LCD_D6) | (1 << LCD_D5) | (1 << LCD_D4));
}


void LCD_Init ()
{
	_delay_ms(50);
	configLCDPorts();
	
	LCD_PORT &= ~(1 << LCD_RS);
	LCD_PORT &= ~(1 << LCD_EN);
	LCD_PORT &= ~(1 << LCD_RW);
	
	LCD_Send_Data(0x03);
	_delay_us(4500);
	LCD_Send_Data(0x03);
	_delay_us(4500);
	LCD_Send_Data(0x03);
	_delay_us(150);
	LCD_Send_Data(0x02);
	LCD_Write_Instruction(LCD_FUNCTION_SET | LCD_4BITS);
	LCD_Write_Instruction(LCD_FUNCTION_SET | LCD_2LINES | LCD_5X8DOTS);
	LCD_Write_Instruction(LCD_DISPLAY_CONTROL | LCD_DISPLAY_ON | LCD_CURSOR_ON | LCD_BLINK_ON);
	LCD_Write_Instruction(LCD_CLEAR);
}

void LCD_Printf(char *str, ...)
{
	va_list args;
	va_start(args, str);
	vsnprintf(lcd_buffer, N_Colum + 1, str, args);
	va_end(args);
	LCD_Print(lcd_buffer);
}

void LCD_Print(char *str)
{
	while (*str)
	{
		LCD_Parser(*str++);
	}
}

void LCD_Write_Instruction(uint8_t data)
{
	//_delay_ms(2);
	LCD_Is_Busy();
	LCD_PORT &= ~(1 << LCD_RS);
	LCD_PORT &= ~(1 << LCD_EN);
	LCD_Send_Data(data >> 4);
	LCD_Send_Data(data);
	/*LCD_Send_Data(4 >> data);
	LCD_Send_Data(data & 0x0F);*/
	
}

void LCD_Parser (uint8_t data)
{	
	//_delay_ms(2);
	LCD_Is_Busy();
	LCD_PORT |= (1 << LCD_RS);
	LCD_PORT &= ~(1 << LCD_EN);
	LCD_Send_Data(data >> 4);
	LCD_Send_Data(data);
	
}


void LCD_Send_Data (uint8_t data)
{
	if ((data & 1) == 0) LCD_PORT &= ~(1 << LCD_D4);	else LCD_PORT |= (1 << LCD_D4);
	if ((data & 2) == 0) LCD_PORT &= ~(1 << LCD_D5);	else LCD_PORT |= (1 << LCD_D5);
	if ((data & 4) == 0) LCD_PORT &= ~(1 << LCD_D6);	else LCD_PORT |= (1 << LCD_D6);
	if ((data & 8) == 0) LCD_PORT &= ~(1 << LCD_D7);	else LCD_PORT |= (1 << LCD_D7);
	
	LCD_PORT &= ~(1 << LCD_EN);
	LCD_PORT |= (1 << LCD_EN);
	LCD_PORT &= ~(1 << LCD_EN);
	_delay_us(300);
	
}

void LCD_Is_Busy ()
{
	bool busy_flag = false; 
	
	LCD_DDR &= ~(1 << LCD_D7);
	LCD_PORT &= ~(1 << LCD_RS);
	LCD_PORT |= (1 << LCD_RW);
	
	
	do 
	{
		LCD_PORT |= (1 << LCD_EN);
		_delay_us(1);
		
		busy_flag = (LCD_D7_Pin & (1 << LCD_D7));
		
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