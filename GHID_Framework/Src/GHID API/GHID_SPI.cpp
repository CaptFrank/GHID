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
	for(register byte i = START_DEVICE_ENUM; i != END_DEVICE_ENUM; i ++){
		//! We set the ss pin as an output.
		pinMode(static_cast<byte>(this->settings.map[i]), OUTPUT);
	}

	//! We start the SPI engine
	SPI.begin();

	//! We set the SPI bit order
	SPI.setBitOrder(this->settings.bit_order);

	//! We set the clock divider
	SPI.setClockDivider(this->settings.clock_divider);

	//! We set the data mode of the bus
	SPI.setDataMode(this->settings.data_mode);

	//! We setup the interrupt
	if(this->settings.attach_interrupt == 0x01){
		SPI.attachInterrupt();
	}

	//! We reset the buffer position
	spi_buffer.length = 0;
}

//! Transfer Data method
void GHID_SPI::tranfer_data(spi_device_address_map_t device, byte data){

	//! Start listening
	digitalWrite(device, LOW);

	//! Send the data byte
	SPI.transfer(data);

	//! Stop listening
	digitalWrite(device, HIGH);

}

//! Transfer bulk data
void GHID_SPI::transfer_bulk(spi_device_address_map_t device, byte* data, byte length){

	for(register byte i = 0; i < length; i ++)
		this->tranfer_data(device, (*data) + i);
}

//! Read data into a buffer struct
buffer_struct_t* GHID_SPI::read_data(spi_device_address_map_t device,
										byte length,
										byte command){

	for(register byte i = 0; i < length; i ++){
		this->buffer.buffer[i] = SPI.transfer(command);
	}

	return this->buffer;
}

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
	if(spi_buffer.length < sizeof(spi_buffer.buffer)){

		//! We add one more byte to the array
		spi_buffer.length[spi_buffer.length ++] = c;
	}
}
