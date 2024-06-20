/*
 * LCD_16x2_TWI.c
 *
 * Created: 28/12/2023 09:41:57 a. m.
 *  Author: Cesar M
 */ 

#include "LCD_16x2_TWI.h"

uint8_t port = Display_On;
static char lcd_buffer [N_Colum + 1];

void TWI_LCD_init(uint32_t sclFreq)
{
	TWI_init(sclFreq);
	_delay_ms(50);
	
	TWI_LCD_Send_data(port &= (~TWI_LCD_RS));
	TWI_LCD_Send_data(port &= (~TWI_LCD_EN));
	TWI_LCD_Send_data(port &= (~TWI_LCD_RW));
	
	TWI_LCD_Write(0x03);
	_delay_us(4500);
	TWI_LCD_Write(0x03);
	_delay_us(4500);
	TWI_LCD_Write(0x03);
	_delay_us(150);
	TWI_LCD_Write(0x02);
	
	TWI_LCD_Command(LCD_FUNCTION_SET | LCD_4BITS);
	TWI_LCD_Command(LCD_FUNCTION_SET | LCD_2LINES | LCD_5X8DOTS);
	TWI_LCD_Command(LCD_DISPLAY_CONTROL | LCD_DISPLAY_ON | LCD_CURSOR_ON | LCD_BLINK_ON);
	TWI_LCD_Command(LCD_CLEAR);
}

void TWI_LCD_Printf(char *str, ...)
{
	va_list args;
	va_start(args, str);
	vsnprintf(lcd_buffer, N_Colum + 1, str, args);
	va_end(args);
	TWI_LCD_Print(lcd_buffer);
}

void TWI_LCD_Print(char *str)
{
	while(*str)
	{
		TWI_LCD_Parser(*str ++);
	}
}

void TWI_LCD_Command (uint8_t data)
{
	//TWI_LCD_Is_Busy();
	_delay_ms(5);
	port &= ~TWI_LCD_RS;
	port &= ~TWI_LCD_EN;
	TWI_LCD_Send_data(port);
	TWI_LCD_Write(data >> 4);
	TWI_LCD_Write(data);
}

void TWI_LCD_Parser (uint8_t data)
{
	//TWI_LCD_Is_Busy();
	_delay_ms(5);
	port |= TWI_LCD_RS;
	port &= ~TWI_LCD_EN;
	TWI_LCD_Send_data(port);
	TWI_LCD_Write(data >> 4);
	TWI_LCD_Write(data);
}

void TWI_LCD_Write(uint8_t data)
{
	
	if ((data & 1) == 0) port &= ~TWI_LCD_D4;	else port |= TWI_LCD_D4;
	if ((data & 2) == 0) port &= ~TWI_LCD_D5;	else port |= TWI_LCD_D5;
	if ((data & 4) == 0) port &= ~TWI_LCD_D6;	else port |= TWI_LCD_D6;
	if ((data & 8) == 0) port &= ~TWI_LCD_D7;	else port |= TWI_LCD_D7;
	
	TWI_LCD_Send_data(port);
	
	TWI_LCD_Send_data(port & (~TWI_LCD_EN));	
	TWI_LCD_Send_data(port | TWI_LCD_EN);
	TWI_LCD_Send_data(port & (~TWI_LCD_EN));
	_delay_us(300);
}

void TWI_LCD_Send_data(uint8_t data)
{
	
	TWI_start_condition();
	TWI_write_address(LCD_address, TWI_W);
	TWI_write_data(Write_address_register);
	TWI_write_data(data);
	TWI_stop_condition();	

}

/*
Posiblemente tenga problemas  puesto que para leer el pin 7 del PCF8574 requiero de mandarle el enable
esto aun no lo tengo implementado, el como leer un pin y al mismo tiempo escribirlo en otro
*/

void TWI_LCD_Is_Busy ()
{
	bool busy_flag;
	
	TWI_LCD_Send_data(port &= ~TWI_LCD_RS);
	TWI_LCD_Send_data(port | TWI_LCD_RW);
	
	do 
	{
		busy_flag = false;
		TWI_LCD_Send_data(port | TWI_LCD_EN);
		_delay_us(1);
		
		busy_flag |= PCF8574_Port_Input(0x27);
		
		TWI_LCD_Send_data(port &= ~TWI_LCD_EN);
		_delay_us(1);
		
		TWI_LCD_Send_data(port | TWI_LCD_EN);
		_delay_us(1);
		TWI_LCD_Send_data(port &= ~TWI_LCD_EN);
		_delay_us(1);
		
	} while (busy_flag);
	
	TWI_LCD_Send_data(port &= ~TWI_LCD_RW);
	port |= Display_On;
}

void TWI_LCD_Set_Cursor(uint8_t Row, uint8_t Col)
{
	static uint8_t local_mem [2] = {0x00, 0x40};
	TWI_LCD_Command( LCD_SET_DDRAM | (local_mem[Row - 1] + (Col - 1)));
}