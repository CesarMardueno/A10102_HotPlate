/*
* A10102_V1.0.c
*
* Created: 18/07/2023 10:51:41 p. m.
* Author : Cesar M
*/

#include <avr/io.h>
#include <util/delay.h>
#include "AT328_TWI.h"

void Enciende_led();
void Apaga_led();

int main(void)
{	DDRB |= (1 << PORTB5);
	while (1)
	{
		PORTB |= (1 << PORTB5);
		_delay_ms(250);
		PORTB &= ~(1 << PORTB5);
		_delay_ms(250);
	}

}
