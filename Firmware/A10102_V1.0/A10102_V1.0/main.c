/*
* A10102_V1.0.c
*
* Created: 18/07/2023 10:51:41 p. m.
* Author : Cesar M
*/

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "LCD_16x2.h"
#include "PCF8574.h"
#include "AT328_TWI.h"
#include "LCD_16x2_TWI.h"
#include "SPI.h"
#include "MAX6675.h"
#include "ENCODER.h"

#define Slave1 2		//PORTB2



//#define EncoderSw	4	// PORTD4


uint8_t count = 0;


int main(void)
{	
	
	cli();
	
	
	DDRB |= (1 << Slave1);
	EncoderInit();
	TWI_LCD_init(100000);
	SPI_Master_Init();
	EncoderInit();
	sei();
	
	while (1)
	{
		count = GetEncoderCount();
			
	
		float temp = Temperature_Read(SPI_Master_Receiver(), Slave1);
		
		TWI_LCD_Set_Cursor(1,1);
		TWI_LCD_Printf("Temp: %02.2f °C", temp);
		TWI_LCD_Set_Cursor(2,1);
		TWI_LCD_Printf("encoder: %03d", count);
		_delay_ms(10);
				
	}
	

}


