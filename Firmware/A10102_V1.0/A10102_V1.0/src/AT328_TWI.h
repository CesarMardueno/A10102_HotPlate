/*
 * AT328_TWI.h
 *
 * Created: 25/07/2023 09:09:53 p. m.
 *  Author: Cesar M
 */ 


#ifndef AT328_TWI_H_
#define AT328_TWI_H_

	#include <avr/io.h>
	
	#define TWI_START 0x10

	void TWI_Init(long sclFreq);
	void twiStarCondition();



#endif /* AT328_TWI_H_ */