/*
 * AT328_TWI.c
 *
 * Created: 25/07/2023 09:09:44 p. m.
 *  Author: Cesar M
 */ 

#include <avr/io.h>
#include "AT328_TWI.h"

 void TWI_Init(long sclFreq){

	/////// Setting frequency ///////
	/*
		F = 	CPUclk/(16 + (2*TWBR*Prescaler))
		TWBR = (F_CPU/SCL_Freq)/2*Preescaler
	*/

	//Prescaler factor equal 1
	TWSR &=~ (1<<TWPS0);
	TWSR &=~ (1<<TWPS1);
	
	unsigned long baseFreq = F_CPU/sclFreq;

	//factor divisor
	TWBR = (uint8_t) (baseFreq - 16)/2;

	/////// TWI POWER ON ///////
	PRR	 &=~ (1<<PRTWI);

 }
 
 void twiStarCondition(){
	 TWCR = ((1<<TWINT)|(1<<TWSTA)|(1<<TWEN)); //Clear TWINT | Start condition | SDA & SCL pins has enable
	 while(!(TWSR & (1<<TWINT)));
	 
	 if((TWSR & 0xF8)!=TWI_START){
		 return false;
	 }