/*
* AT328_TWI.c
*
* Created: 25/07/2023 09:09:44 p. m.
*  Author: Cesar M
*/


#include "AT328_TWI.h"

void TWI_init(uint32_t sclFreq){

	/////// Setting frequency ///////
	/*
	F scl = CPUclk/(16 + (2*TWBR*Prescaler))
	TWBR = (F_CPU/SCL_Freq)/2*Preescaler
	*/

	//Prescaler factor equal 1
	TWSR &=~ (1<<TWPS0);
	TWSR &=~ (1<<TWPS1);
	
	uint32_t baseFreq = F_CPU/sclFreq;

	//factor divisor
	TWBR = (uint8_t) (baseFreq - 16)/2;

	/////// TWI POWER ON ///////
	PRR	 &=~ (1<<PRTWI);

}

bool TWI_start_condition(){
	TWCR = ((1<<TWINT)|(1<<TWSTA)|(1<<TWEN)); //Clear TWINT | Start condition | SDA & SCL pins has enable
	while(!(TWSR & (1<<TWINT)));
	
	if((TWSR & 0xF8)!=TWI_START){
		return false;
	}
	return true;
}

bool TWI_stop_condition(){
	TWCR = ((1<<TWINT)|(1<<TWSTO)|(1<<TWEN));
	
	//	0000 0000
	//	1<<3
	//	0000 1000
	//	3<<3
	//	0001 1000
	//  1<<7
	//	1000 0000
	
	
}

uint8_t TWI_write_address(uint8_t address, uint8_t w_r){
	address = (address << 1);	//Recorro un bit a la izquierda la adress
	if(TWI_R == w_r){
		address |=  TWI_R;		//Relleno address con Write 
	}
	TWAR = adress;
	
}
uint8_t TWI_write_data(uint8_t data){
	
	while(TWSR != TWI_WT_SLA_ACK);
}

