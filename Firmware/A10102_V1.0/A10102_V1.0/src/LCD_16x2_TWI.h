/*
 * LCD_16x2_TWI.h
 *
 * Created: 28/12/2023 09:42:08 a. m.
 *  Author: Cesar M
 */ 


#ifndef LCD_16X2_TWI_H_
#define LCD_16X2_TWI_H_

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>
#include <util/delay.h>
#include <stdarg.h>

#include "AT328_TWI.h"
#include "LCD_16x2.h"
#include "PCF8574.h"

#define TWI_LCD_RS 0x01
#define TWI_LCD_RW 0x02
#define TWI_LCD_EN 0x04
#define TWI_LCD_D4 0x10
#define TWI_LCD_D5 0x20
#define TWI_LCD_D6 0x40
#define TWI_LCD_D7 0x80
#define Display_On 0x08

#define LCD_address 0x27
#define Write_address_register 0x41


void TWI_LCD_init(uint32_t sclFreq);

void TWI_LCD_Send_data(uint8_t data);

void TWI_LCD_Parser (uint8_t data);

void TWI_LCD_Command (uint8_t data);

void TWI_LCD_Write(uint8_t data);

void TWI_LCD_Print(char *str);

void TWI_LCD_Printf(char *str, ...);

void TWI_LCD_Is_Busy();

void TWI_LCD_Set_Cursor(uint8_t Row, uint8_t Col);


#endif /* LCD_16X2_TWI_H_ */