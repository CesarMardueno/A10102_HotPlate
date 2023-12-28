/*
 * LCD_16x2.h
 *
 * Created: 08/08/2023 10:53:22 p. m.
 *  Author: Cesar M
 */ 


#ifndef LCD_16X2_H_
#define LCD_16X2_H_
	
#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>
#include <util/delay.h>
	
/*		Control Port		*/
#define LCD_Data_Port	PORTD
#define LCD_Data_DDR	DDRD
#define LCD_Ctlr_DDR	DDRD
	
/*		LCD Data PINS		*/
#define LCD_D7_Pin	PIND
#define LCD_D7_Bit	0x07
#define LCD_D6_Bit	0x06
#define LCD_D5_Bit	0x05
#define LCD_D4_Bit	0x04
	
/*		LCD control pins	*/
#define LCD_ENE 0x02
#define LCD_RW  0x01
#define LCD_RS  0x02
#define LCD_ONOFF 0x00
	
/*		LCD Functions		*/
#define LCD_CLR 0x01
#define LCD_HOME 0x02
#define LCD_ROAM_CURSOR 0x06
#define LCD_ON 0x0C
#define LCD_OFF 0x08
#define LCD_BLINK_CURSOR 0x0B
#define LCD_Reset 0x30
#define LCD_4BIT 0x28
	
	
	
void LCD_Init ();
void LCD_Parser (uint8_t data);
void LCD_Send_Data (uint8_t data);
void LCD_Write_Instruction();
void LCD_Write (uint8_t data[]);
bool LCD_Is_Busy ();
	

#endif /* LCD_16X2_H_ */