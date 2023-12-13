/*
 * LCD_16x2.c
 *
 * Created: 08/08/2023 10:48:22 p. m.
 *  Author: Cesar M
 */ 

#include "LCD_16X2.h"

static void configLCDPorts(void)
{
	/* configure the microprocessor pins for the data lines */
	LCD_Data_DDR |= (1<<LCD_D7_Bit) | (1<<LCD_D6_Bit) | (1<<LCD_D5_Bit) | (1<<LCD_D4_Bit);
	
	/* configure the microprocessor pins for the control lines */
	LCD_Ctlr_DDR |= (1<<LCD_RW) | (1<<LCD_RS) | (1<<LCD_ENE);
	
	/* Turn on LCD */
	DDRB |= (1<<LCD_ONOFF);
}


void LCD_Init ()
{
	configLCDPorts();
	_delay_ms(50);
	
	LCD_Data_Port &= ~(1 << LCD_RS);
	LCD_Data_Port |= (1 << LCD_ENE);
	LCD_Data_Port &= ~(1 << LCD_RW);
	
	LCD_Send_Data(LCD_Reset);
	_delay_us(10);
	LCD_Send_Data(LCD_Reset);
	_delay_us(200);
	LCD_Send_Data(LCD_Reset);
	_delay_us(80);
	
	LCD_Send_Data(LCD_4BIT);
	LCD_Is_Busy();
	
	LCD_Write_Instruction(LCD_4BIT);
	
	LCD_Is_Busy();
	LCD_Write_Instruction(LCD_OFF);
	
	LCD_Is_Busy();
	LCD_Write_Instruction(LCD_CLR);
	
	LCD_Is_Busy();
	LCD_Write_Instruction(LCD_ROAM_CURSOR);
	
	LCD_Is_Busy();
	LCD_Write_Instruction(LCD_ON);
		
}
void LCD_Write (uint8_t data[])
{
	volatile int i = 0;
	while(data[i] != 0)
	{
		LCD_Is_Busy();
		LCD_Parser(data[i]);
		i++;
	}
}

void LCD_Parser (uint8_t data)
{	
	LCD_Data_Port &= ~(1 >> LCD_RW);
	LCD_Data_Port |= (1 << LCD_RS);
	LCD_Data_Port &= ~(1 << LCD_ENE);
	LCD_Write(data);
	LCD_Write(4 << data);
}

LCD_Write_Instruction(uint8_t data)
{
	LCD_Data_Port &= ~(1 >> LCD_RW);
	LCD_Data_Port &= ~(1 << LCD_RS);
	LCD_Data_Port &= ~(1 << LCD_ENE);
	LCD_Write(data);
	LCD_Write(4 << data);
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
	
	LCD_Data_Port &= ~((1 << LCD_D7_Bit) | (1 << LCD_D6_Bit) | (1 << LCD_D5_Bit) | (1 << LCD_D4_Bit));
	LCD_Data_Port |= ((mask[0] << LCD_D7_Bit) | (mask[1] << LCD_D6_Bit) | (mask[2] << LCD_D5_Bit) | (mask[3] << LCD_D4_Bit));
	
	LCD_Data_Port |= (1 << LCD_ENE);
	_delay_us(1);
	LCD_Data_Port &= ~(1 << LCD_ENE);
	_delay_us(1);
	
		
}

bool LCD_Is_Busy ()
{
	bool busy_flag; 
	
	LCD_Data_DDR &= ~(1 << LCD_D7_Bit);
	LCD_Data_Port &= ~(1 << LCD_RS);
	LCD_Data_Port |= (1 << LCD_RW);
	
	do 
	{
		busy_flag = false;
		LCD_Data_Port |= (1 << LCD_ENE);
		_delay_us(1);
		
		busy_flag |= (LCD_D7_Pin & (1 << LCD_D7_Bit));
		
		LCD_Data_Port &= ~(1 << LCD_ENE);
		_delay_us(1);
		
		LCD_Data_Port |= (1 << LCD_ENE);
		_delay_us(1);
		LCD_Data_Port &= ~(1 << LCD_ENE);
		_delay_us(1);
		
	} while (busy_flag);
	
	LCD_Data_Port &= ~(1 << LCD_RW);
	LCD_Data_DDR |= (1 << LCD_D7_Bit);
}
