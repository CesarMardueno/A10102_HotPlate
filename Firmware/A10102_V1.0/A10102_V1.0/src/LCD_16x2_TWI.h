/*
 * LCD_16x2_TWI.h
 *
 * Created: 28/12/2023 09:42:08 a. m.
 *  Author: Cesar M
 */ 


#ifndef LCD_16X2_TWI_H_
#define LCD_16X2_TWI_H_

#include <avr/io.h>
#include "AT328_TWI.h"

void TWI_LCD_init(uint32_t sclFreq);


#endif /* LCD_16X2_TWI_H_ */