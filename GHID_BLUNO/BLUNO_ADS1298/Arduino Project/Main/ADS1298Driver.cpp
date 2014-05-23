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
 *
 * @param setup_method					- The setup method.
 * 										- Allows to customize the setup sequence
 * 											based on needs. By default we set to the
 * 											internal method.
 *
 * @param buff							- The general context ring buffer
 * @param devices						- The device array
 * @param spi_settings					- The SPI settings
 */
ADS1298_Driver::ADS1298_Driver(RingBuff_t* buff, 
							   uint8_t* devices,
							   spi_settings_t* spi_settings) : GHID_SPI(spi_settings){

	//! Assign the global ring buffer type internally
	this->_buff = buff;
	this->_settings;
	this->_devices = devices;
}

/**	
 * This is the setup method for the ads1298
 * 
 * @param setup_method					- The setup method called.
 */	
void ADS1298_Driver::begin(void (*setup_method)(ADS1298_Driver* driver)){
	
	//! Here we setup the pins
	this->_init_pins();
	
	//! We setup the ADS1298
	//! Set the setup method
	setup_method(this);
}

/**
 * This method reads a byte from the ADS1298 chip
 *
 * @param reg_address					- The address to read
 * @return byte							- The byte read
 */
uint8_t ADS1298_Driver::read_byte(int reg_address){

	uint8_t out = 0;

	//! Activate the SPI device
	this->_unset_cs_pin();

	//! Send the address to read
	SPI.transfer(RREG | reg_address);
	delayMicroseconds(5);

	//! Send the number of bytes to read - 1
	SPI.transfer(0);
	delayMicroseconds(5);

	//! Send the read command @ byte 0
	out = SPI.transfer(0);
	delayMicroseconds(1);

	//! Deactivate the SPI Device
	this->_set_cs_pin();
	return(out);
}

/**
 * This method writes a byte to the ADS1298
 *
 * @param reg_address					- The register address
 * @param val_hex						- The value in hex
 */
void ADS1298_Driver::write_byte(int reg_address, uint8_t val_hex){

	//! Activate the SPI device
	this->_unset_cs_pin();

	//! Send the address to write to
	SPI.transfer(WREG | reg_address);
	delayMicroseconds(5);

	//! Send the number of bytes to write - 1
	SPI.transfer(0);
	delayMicroseconds(5);

	//! Transfer the value to write
	SPI.transfer(val_hex);
	delayMicroseconds(1);

	//! Deactivate the SPI device
	this->_set_cs_pin();

}

/**
 * This method sends a command to the ADS1298
 *
 * @param cmd							- The command to send
 */
void ADS1298_Driver::send_command(uint8_t cmd){

	//! We send the command
	//! Start listening
	this->_unset_cs_pin();

	//! Send the data byte
	SPI.transfer(cmd);

	//! Stop listening
	this->_set_cs_pin();
}

/**
 * This method checks which channels are active.
 */
void ADS1298_Driver::check_active_channels(){

	//! Check if we are in read mode or if we do not have a channel available
	//! We return if that is the case.
	if(this->_configs._active || (this->_configs._channels < 1))
		return;

	//! We reset the internal active channels
	this->_configs._active_channels.channel_byte = NONE;
	this->_configs._num_active_channels = NONE;

	//! We loop the channels to see which ones are active and which are not
	for(register uint8_t i = 1; i <= this->_configs._channels; i++){

		delayMicroseconds(1);
		uint8_t temp = this->read_byte(CHnSET + i);

		//! We added the active channel to the struct
		this->_configs._active_channels.channel_byte |= ((temp & 0x07) != SHORTED) << i;
		if(this->_configs._active_channels.channel_byte & (0x01 << i))
			this->_configs._num_active_channels ++;
	}
}

//! Private Context

//! Init methods

/**
 * This sets up the pins
 */
void ADS1298_Driver::_init_pins(){

	//! We setup the pins

	//! SPI BUS
	pinMode(PIN_SS,			OUTPUT);

	//! SIGNALS
	pinMode(PIN_LED, 		OUTPUT);
	pinMode(PIN_RESET, 		OUTPUT);
	pinMode(PIN_START, 		OUTPUT);
	pinMode(PIN_DRDY, 		INPUT);
	
	//! Pull up resistors on DRDY
	digitalWrite(PIN_DRDY,	HIGH);   

	this->_set_cs_pin();

	//! We stop the conversions
	this->_stop_ads1298();

	//! Delay until done setting up
	delay(1);
}

/**
 * This sets up the ADS1298 chip to function
 */
void ADS1298_Driver::_init_ads(ADS1298_Driver* driver){

	//! Let the ads1298 time to boot up
	delay(ONE_MILLI);

	//! Start read command is written
	driver->send_command(SDATAC);

	//! Wait 10 milliseconds
	delay(ONE_MILLI * 10);

	//! Check the model number and the available channels
	driver->_configs._id = driver->read_byte(ID);

	//! We check the number of channels available
	switch (driver->_configs._id & B00011111) {

		//! ADS1294
		case  B10000: //16
	        driver->_configs._channels = 4;
	        break;

	    //! ADS1296
		case B10001: //17
			driver->_configs._channels = 6;
	        break;

	    //! ADS1298
		case B10010: //18
			driver->_configs._channels = 8;
	        break;

	    //! ADS1299
		case B11110: //30
			driver->_configs._channels = 8;
	        break;

		default:
			driver->_configs._channels = 0;
	        break;
	  }

    //! All GPIO set to output 0x0000: (floating CMOS inputs can flicker on and off, creating noise)
	driver->write_byte(GPIO, EMPTY);
	driver->write_byte(CONFIG3, PD_REFBUF | CONFIG3_const);

	//! Setup sampling rate
	driver->write_byte(CONFIG1, HIGH_RES_1k_SPS);

	//! Set the 8 channels to input signal
	//! Set each channel to have 12x gain
	for (register uint8_t i = 1; i < 9; i++) {
		driver->write_byte(CHnSET + i, ELECTRODE_INPUT | GAIN_12X); //report this channel with x12 gain
	}

	//! Check active channels
	driver->check_active_channels();

	//! We start the ads1298
	driver->_start_ads1298();
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
	this->_unset_cs_pin();
	delay(ONE_SECOND);
	this->_set_cs_pin();

	//! Wait longer for TI chip to start
	delay(HALF_SECOND);
}

/**
 * This starts the ADS1298 Conversions
 */
void ADS1298_Driver::_start_ads1298(){

	//! We start the conversions
	digitalWrite(PIN_START, HIGH);
}

/**
 * This stops the ADS1298 Conversions
 */
void ADS1298_Driver::_stop_ads1298(){

	//! We stop the conversions
	digitalWrite(PIN_START, LOW);
}

/**
 * Set SS pin high
 */
void ADS1298_Driver::_set_cs_pin(){

	//! We trigger the CS
	digitalWrite(ADS1298_DEVICE, HIGH);
}

/**
 * Unset ss pin
 */
void ADS1298_Driver::_unset_cs_pin(){

	//! We assert low the ss pin
	digitalWrite(ADS1298_DEVICE, LOW);
}

/**
 * Power down the chip
 */
void ADS1298_Driver::_power_down_ads1898(){

	//! Inverted logic
	digitalWrite(PIN_PWDN, HIGH);
}

/**
 * Power down the chip
 */
void ADS1298_Driver::_unpower_down_ads1898(){

	//! Inverted logic
	digitalWrite(PIN_PWDN, LOW);
}

