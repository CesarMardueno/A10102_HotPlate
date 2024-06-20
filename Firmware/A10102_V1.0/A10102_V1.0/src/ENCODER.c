/*
 * ENCODER.c
 *
 * Created: 13/06/2024 10:20:53 p. m.
 *  Author: Cesar M
 */ 

#include "ENCODER.h"


volatile int16_t encoder_count = 0;
volatile uint8_t button_state = 0;
volatile uint8_t button_flag = 0;

void EncoderInit()
{
	DDR_Encoder &= ~(1 << EncoderA);
	DDR_Encoder &= ~(1 << EncoderB);
	DDR_Encoder &= ~(1 << EncoderSw);
	//PORT_Encoder|= (1 << EncoderA) | (1 << EncoderB) | (1 << EncoderSw);
	
	PCICR |= (1 << PCIE2);
	PCMSK2 |= (1 << PCINT21) | (1 << PCINT22) | (1 << PCINT23);
	
}

uint8_t GetEncoderCount()
{
	int16_t count;
	count = encoder_count;
	return count;	
}

uint8_t GetButton()
{
	uint8_t state;
	state = button_state;
	button_flag = 0;
	return state;	
}



ISR(PCINT2_vect)
{
	static uint8_t last_encoder_a = 0;
	static uint8_t last_encoder_b = 0;
	static uint8_t last_button_state = 0;
	static uint8_t debounce_count = 0;

	uint8_t current_encoder_a = PIND & (1 << EncoderA);
	uint8_t current_encoder_b = PIND & (1 << EncoderB);
	uint8_t current_button_state = PIND & (1 << EncoderSw);

	if (current_encoder_a != last_encoder_a) {
		if ((current_encoder_a && !last_encoder_b) || (!current_encoder_a && last_encoder_b)) {
			encoder_count++;
			} else {
			encoder_count--;
		}
	}
	last_encoder_a = current_encoder_a;
	last_encoder_b = current_encoder_b;


	if (current_button_state != last_button_state) {
		debounce_count = 0; 
		} else if (debounce_count < 5) {
		debounce_count++;
		} else if (debounce_count == 5) {
		button_state = !current_button_state; 
		button_flag = 1; 
	}
	last_button_state = current_button_state;
}