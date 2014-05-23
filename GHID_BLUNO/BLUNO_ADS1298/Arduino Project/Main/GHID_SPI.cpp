/*
 * GHIDSPI.cpp
 *
 *  Created on: 2014-02-06
 *      Author: francispapineau
 */

#include "GHID_SPI.h"

//! Default constructor
GHID_SPI::GHID_SPI(spi_settings_t* settings) {

	//! We copy the settings into our internal class.
	memcpy(&this->settings, settings, sizeof(this->settings));

	//! We set the SS pins to outputs
	for(register byte i = 0; i < settings->num_devices; i ++){
		//! We set the ss pin as an output.
		pinMode(settings->devices[i], OUTPUT);
	}

	//! We start the SPI engine
	SPI.begin();

	//! We set the SPI bit order
	SPI.setBitOrder(settings->bit_order);

	//! We set the clock divider
	SPI.setClockDivider(settings->clock_divider);

	//! We set the data mode of the bus
	SPI.setDataMode(settings->data_mode);

	//! We setup the interrupt
	if(settings->attach_interrupt == true){
		SPI.attachInterrupt();
	}

	#ifdef SLAVE_MODE
	//! We reset the buffer position
	spi_buffer.length = 0;
	#endif
}

//! Transfer Data method
void GHID_SPI::tranfer_data(byte device, byte data){

	//! Start listening
	digitalWrite(device, LOW);

	//! Send the data byte
	SPI.transfer(data);
	delayMicroseconds(ONE_MICRO_SEC);

	//! Stop listening
	digitalWrite(device, HIGH);

}

//! Transfer bulk data
void GHID_SPI::transfer_bulk(byte device, byte* data, byte length){

	//! Start listening
	digitalWrite(device, LOW);

	for(register byte i = 0; i < length; i ++){

		//! Send the data byte
		SPI.transfer((*data) + i);
		delayMicroseconds(ONE_MICRO_SEC);
	}
	//! Stop listening
	digitalWrite(device, HIGH);
}

//! Read data into a buffer struct
buffer_struct_t* GHID_SPI::read_data(byte device,
										byte length,
										byte command){

	for(register byte i = 0; i < length; i ++){
		this->buffer.buffer[i] = SPI.transfer(command);
	}

	return &this->buffer;
}

#ifdef SLAVE_MODE
//! Checks for the isr buffer if its full
void GHID_SPI::check_spi_buffer(){

	//! Copy the data received
	memcpy(&this->buffer, &spi_buffer, spi_buffer.length);

	//! Reset the position.
	spi_buffer.length = 0x00;
}

//! If the interrupt is online
ISR(SPI_STC_vect){

	//! Get a buffered char
	byte c = SPDR;

	//! If not full
	if(MAX_BUFFER < sizeof(spi_buffer.length)){

		//! We add one more byte to the array
		spi_buffer.buffer[spi_buffer.length ++] = c;
	}
}
#endif
