/*
 * ADS1298Driver.cpp
 *
 *  Created on: 2014-05-15
 *      Author: francispapineau
 */

#include "ADS1298Driver.h"

//! Public Context

/**
 * This is the default constructor for the class
 */
ADS1298_Driver::ADS1298_Driver(){

	//! Here we setup the pins
	this->_init_pins();

	//! Here we setup the SPI bus
	this->_init_spi();
}

/**
 * This method sets up the ADS1298 chip
 */
void ADS1298_Driver::setup_ads1298(){

	//! We setup the ADS1298
	this->_init_ads();
}

/**
 * This method reads a byte from the ADS1298 chip
 *
 * @param address						- The address to read
 * @return byte							- The byte read
 */
uint8_t ADS1298_Driver::read_byte(int address){

	  uint8_t out = 0;
	  digitalWrite(PIN_SS, LOW);
	  SPI.transfer(RREG | address);
	  delayMicroseconds(5);
	  SPI.transfer(0);	// number of registers to be read/written – 1
	  delayMicroseconds(5);
	  out = SPI.transfer(0);
	  delayMicroseconds(1);
	  digitalWrite(PIN_SS, HIGH);
	  return(out);
}

/**
 * This method writes a byte to the ADS1298
 *
 * @param reg_address					- The register address
 * @param val_hex						- The value in hex
 */
void ADS1298_Driver::write_byte(int reg_address, int val_hex){

	digitalWrite(PIN_SS, LOW);
	SPI.transfer(WREG | reg_address);
	SPI.transfer(0);	// number of registers to be read/written – 1
	SPI.transfer(val_hex);
	delayMicroseconds(1);
	digitalWrite(PIN_SS, HIGH);

}

/**
 * This method sends a command to the ADS1298
 *
 * @param cmd							- The command to send
 */
void ADS1298_Driver::send_command(uint8_t cmd){

	//! We send the command
	this->tranfer_data(DEVICE_ADS1298, cmd);
}

//! Private Context

//! Init methods

/**
 * This sets up the pins
 */
void ADS1298_Driver::_init_pins(){

	//! We setup the pins

	//! SPI BUS
	pinMode(PIN_SCLK, 		OUTPUT);
	pinMode(PIN_MISO, 		OUTPUT);
	pinMode(PIN_MOSI, 		OUTPUT);
	pinMode(PIN_SS,			OUTPUT);

	//! SIGNALS
	pinMode(PIN_LED, 		OUTPUT);
	pinMode(PIN_DRDY, 		OUTPUT);
	pinMode(PIN_RESET, 		OUTPUT);
	pinMode(PIN_START, 		OUTPUT);

	//! We trigger the CS
	digitalWrite(PIN_SS,	HIGH);

	//! We stop the conversions
	digitalWrite(PIN_START, LOW);

	//! Delay until done setting up
	delay(1);
}

/**
 * This sets up the SPI bus
 */
void ADS1298_Driver::_init_spi(){

	//! We build a spi settings structure
	spi_settings_t settings;
	settings.bit_order = MSBFIRST;
	settings.clock_divider = SPI_CLOCK_DIV16;
	settings.data_mode = SPI_MODE1;
	settings.attach_interrupt = FALSE; //! MASTER MODE
	settings.map = ads1298_map;

	//! Create the SPI object
	this->GHID_SPI(&settings);
}

/**
 * This sets up the ADS1298 chip to function
 */
void ADS1298_Driver::_init_ads(){




}

/**
 * Reset the entire ADS1298 chip
 */
void ADS1298_Driver::_reset_ads1298(){

	//! Reset the device
	digitalWrite(PIN_RESET, HIGH);
	delay(ONE_SECOND);
	digitalWrite(PIN_RESET, LOW);
	delay(ONE_SECOND);
	digitalWrite(PIN_RESET, HIGH);
	delay(ONE_MILLI);
}

/**
 * Reset the comms on the ADS1298
 */
void ADS1298_Driver::_reset_ads1298_comms(){

	//! Reset communication
	digitalWrite(PIN_SS, LOW);
	delay(ONE_SECOND);
	digitalWrite(PIN_SS, HIGH);

	//! Wait longer for TI chip to start
	delay(HALF_SECOND);

}
