/*
 * ENCODER.h
 *
 * Created: 13/06/2024 10:21:03 p. m.
 *  Author: Cesar M
 */ 


#ifndef ENCODER_H_
#define ENCODER_H_

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define DDR_Encoder DDRD
#define PORT_Encoder PORTD
#define EncoderA	5	// PORTD5
#define EncoderB	6	// PORTD6
#define EncoderSw	7

#define EncoderMinLimit 0
#define EncoderMaxLimit 9


void EncoderInit();

uint8_t GetEncoderCount();


uint8_t GetButton();



#endif /* ENCODER_H_ */