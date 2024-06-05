/*
 * PCF8574.h
 *
 * Created: 26/03/2024 05:47:46 a. m.
 *  Author: Cesar M
 */ 


#ifndef PCF8574_H_
#define PCF8574_H_

#include <util/delay.h>
#include "AT328_TWI.h"


/************************************************************************/
/*							Address                                     */
/*																		*/
/*           A2  |  A1  |  A0  | Read Addr  |  Write Addr  |			*/
/*            0  |   0  |   0  |    0x41    |     0x40     |			*/
/*            0  |   0  |   1  |    0x43    |     0x42     |			*/
/*            0  |   1  |   0  |    0x45    |     0x44     |			*/
/*            0  |   1  |   1  |    0x47    |     0x46     |			*/
/*            1  |   0  |   0  |    0x49    |     0x48     |			*/
/*            1  |   0  |   1  |    0x4B    |     0x4A     |			*/
/*            1  |   1  |   0  |    0x4B    |     0x4C     |			*/
/*            1  |   1  |   1  |    0x4F    |     0x4E     |			*/
/************************************************************************/



void PCF8574_Port_Output(uint8_t address, uint8_t data);

uint8_t PCF8574_Port_Input(uint8_t address);



#endif /* PCF8574_H_ */