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
#include <stdarg.h>
	
	
/*				Pin Mapping					*/
//#if (!defined LCD_DDR || !defined LCD_PORT)
//#warning "Pines por defecto"
#define LCD_DDR DDRD	
#define LCD_PORT PORTD
#define LCD_RW 1
#define LCD_RS 2
#define LCD_EN 3
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7
#define LCD_D7_Pin	PIND

//#endif

#define N_Colum 16
#define N_Row	2
	
/*				LCD Commands				*/
/************************************************************************/
/*           Clear Display Mode    D7 D6 D5 D4 D3 D2 D1 D0              */
/*                                 0  0  0  0  0  0  0  1               */
/************************************************************************/

#define LCD_CLEAR           0x01

/************************************************************************/
/*           Return Home Mode      D7 D6 D5 D4 D3 D2 D1 D0              */
/*                                 0  0  0  0  0  0  1  0               */
/************************************************************************/

#define LCD_HOME            0x02

/************************************************************************/
/*           Clear Display Mode    D7 D6 D5 D4 D3 D2 D1 D0              */
/*                                 0  0  0  0  0  1 I/D S               */
/*           I/D = 1 Inc           0 Dec                                */
/*            S  = 1 Shift On      0 Shift off                          */
/************************************************************************/

#define LCD_ENTRY_MODE      0x04
#define LCD_INCREMENT       0x02
#define LCD_DECREMENT       0x00   
#define LCD_SHIFT_ON        0x01
#define LCD_SHIFT_OFF       0x00

/************************************************************************/
/*          Display control Mode   D7 D6 D5 D4 D3 D2 D1 D0              */
/*                                 0  0  0  0  1  D  U  B               */
/*            D = 1 Disp On        0 Disp Off                           */
/*            U = 1 Cursor on      0 cursor off                         */
/*            B = 1 Blink on       0 Blink  off                         */
/************************************************************************/

#define LCD_DISPLAY_CONTROL 0X08
#define LCD_DISPLAY_ON		0x04
#define LCD_DISPLAY_OFF		0x00
#define LCD_CURSOR_ON		0x02
#define LCD_CURSOR_OFF		0x00
#define LCD_BLINK_ON		0x01
#define LCD_BLINK_OFF		0x00

/************************************************************************/
/*      Cursor or Display shift Mode   D7 D6 D5 D4 D3  D2  D1 D0        */
/*										0  0  0 1  S/C R/L *  *         */
/*           S/C = 1 DISP SHIFT		0 CURSOR MOVE                       */
/*           R/L = 1 SHIFT RIGHT    0 SHIFT LEFT                        */
/************************************************************************/

#define LCD_DISPCURSOR_SHIFT	0X10
#define LCD_DISPLAY_SHIFT		0X08
#define LCD_CURSOR_SHIFT		0X00
#define LCD_MOVE_RIGHT			0X04
#define LCD_MOVE_LEFT			0X00

/************************************************************************/
/*          FUNCION SET     Mode   D7 D6 D5 D4  D3 D2 D1 D0             */
/*                                 0  0  1  D/L N  F  *  *              */
/*           D/L = 1 8 BITS MODE	     0 4 BITS MODE                  */
/*            N = 1 2 LINES MODE	     0 1 LINE MODE                  */
/*            F = 1 MATRIZ  5X10		 0 MATRIZ 5X8                   */
/************************************************************************/

#define LCD_FUNCTION_SET    0x20
#define LCD_8BITS			0X10
#define LCD_4BITS			0x00
#define LCD_2LINES			0X08
#define LCD_1LINE			0X00
#define LCD_5X10DOTS		0X04
#define LCD_5X8DOTS			0X00

/************************************************************************/
/*              SET CGRAM		   D7 D6 D5  D4  D3  D2  D1  D0         */
/*                                 0  1  ACG ACG ACG ACG ACG ACG        */
/************************************************************************/

#define  LDC_SET_CGRAM		0X40

/************************************************************************/
/*              SET DDRAM		   D7 D6 D5  D4  D3  D2  D1  D0         */
/*                                 1  0  ADD ADD ADD ADD ADD ADD        */
/************************************************************************/

#define LCD_SET_DDRAM		0x80



void configLCDPorts(void);
	
void LCD_Init ();

void LCD_Parser (uint8_t data);

void LCD_Send_Data (uint8_t data);

void LCD_Write_Instruction(uint8_t data);

void LCD_Is_Busy ();

void LCD_Set_Cursor(uint8_t Row, uint8_t Col);

void LCD_Print(char *str);

void LCD_Printf(char *str, ...);



#endif /* LCD_16X2_H_ */