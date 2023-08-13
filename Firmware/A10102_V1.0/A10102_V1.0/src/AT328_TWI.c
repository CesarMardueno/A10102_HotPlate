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

bool TWI_restart_condition(){
	TWCR = ((1<<TWINT)|(1<<TWSTA)|(1<<TWEN));
	while(!(TWSR & (1<<TWINT)));
	if((TWSR & 0xF8)!=TWI_RESTART){
		return false;
	}
	return true;
}

void TWI_stop_condition(){
	TWCR = ((1<<TWINT)|(1<<TWSTO)|(1<<TWEN));
		
}

bool TWI_write_address(uint8_t address, uint8_t w_r){
	uint8_t wrt_rd = 0;
	address = (address << 1);	//go through the memory address 1 bit to be able to write the action
	if(TWI_R == w_r){
		address |=  TWI_R;		//Relleno address con Write 
		wrt_rd = TWI_RD_SLA_ACK;
	}
	else{
		address |= TWI_W;
		wrt_rd = TWI_WT_SLA_ACK;
	}
	TWDR = address;
	TWCR = ((1<<TWINT) | (1<<TWEN));
	if ((TWSR & 0xF8)!=wrt_rd)
	{
		return false;
	}
	return true;
}
bool TWI_write_data(uint8_t data){
	TWDR = data;
	TWCR = ((1<<TWINT)  | (1<<TWEN));
	while(!(TWCR & (1<<TWINT)));
	
	if((TWSR & 0xF8) != TWI_MT_DATA_ACK){
		return false;
	}
	return true;
}

uint8_t TWI_read_data(uint8_t ack_nack){
	TWCR = ((1<<TWINT) | (1<<TWEN) | (ack_nack<<TWEA));
	while(!(TWCR & (1<<TWINT)));
	return TWDR;
}

