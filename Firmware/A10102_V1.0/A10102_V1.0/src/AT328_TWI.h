/*
 * AT328_TWI.h
 *
 * Created: 25/07/2023 09:09:53 p. m.
 *  Author: Cesar M
 */ 


#ifndef AT328_TWI_H_
#define AT328_TWI_H_

	#include <avr/io.h>
	#include <stdint.h>
	#include <stdbool.h>
	
	#define	TWI_W			0x00U
	#define	TWI_R			0x01U
	#define TWI_ACK			0x01U	//bit del registro
	#define TWI_NACK		0x00U	// bit del registro
	
	#define TWI_START		0x08U
	#define TWI_RESTART		0x10U
	#define TWI_WT_SLA_ACK	0x18U	//code for write ack received
	#define TWI_MT_DATA_ACK	0x20U	//code for master data ack not received	
	#define TWI_RD_SLA_ACK	0x40U	//code for read ack recived
	

	void TWI_init(uint32_t sclFreq);
	bool TWI_start_conditionn();
	bool TWI_restart_condition();
	void TWI_stop_condition();
	bool TWI_write_address(uint8_t address, uint8_t w_r);
	bool TWI_write_data(uint8_t data);
	uint8_t TWI_read_data(uint8_t ack_nack);


#endif /* AT328_TWI_H_ */