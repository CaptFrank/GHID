/*
 * ADS1298Driver.h
 *
 *  Created on: 2014-05-15
 *      Author: francispapineau
 */

#ifndef ADS1298DRIVER_H_
#define ADS1298DRIVER_H_

#include <Arduino.h>
#include <SPI/SPI.h>

#include "GHID_SPI.h"
#include "ADS1298Commands.h"

//! Pin definitions - SPI Bus
#define PIN_MOSI		11
#define PIN_MISO		12
#define PIN_SCLK		10 		//! Default
#define PIN_SS			13

//! Pin definitions - Signals
#define PIN_RESET		9
#define PIN_START		8
#define PIN_DRDY		7
#define PIN_LED			6

//! I/O Commands
#define READ			0x20
#define WRITE			0x40

//! Delays
#define ONE_SECOND		1000
#define HALF_SECOND		500
#define ONE_MILLI		1

//! General defines
#define TRUE			0x01
#define FALSE			0x00

//! This is a spi network device list.
//! You must implement this map with the appropriate pin allocations
//! so that SS can select propertly.
enum spi_device_address_map_t {

	START_DEVICE_ENUM,
	DEVICE_ADS1298 = PIN_SS, //! OUR DEVICE SS
	END_DEVICE_ENUM
} ads1298_map;
/**
 * This is the ADS1298 Driver. It handles the reads and writes to the ADS1298
 * device.
 */
class ADS1298_Driver : GHID_SPI{

	//! Public Context
	public:

		/**
		 * This is the default constructor for the class
		 *
		 * @param setup_method					- The setup method.
		 * 										- Allows to customize the setup sequence
		 * 											based on needs. By default we set to the
		 * 											internal method.
		 */
		ADS1298_Driver(void(*setup_method)(void) = this->_setup_method);

		/**
		 * This method sets up the ADS1298 chip
		 */
		void setup_ads1298();

		/**
		 * This method reads a byte from the ADS1298 chip
		 *
		 * @param address						- The address to read
		 * @return byte							- The byte read
		 */
		uint8_t read_byte(int address);

		/**
		 * This method writes a byte to the ADS1298
		 *
		 * @param reg_address					- The register address
		 * @param val_hex						- The value in hex
		 */
		void write_byte(int reg_address, int val_hex);

		/**
		 * This method sends a command to the ADS1298
		 *
		 * @param cmd							- The command to send
		 */
		void send_command(uint8_t cmd);

	//! Private Context
	private:

		//! Internal setup method pointer
		void(*_setup_method)(void);

		//! Init methods

		/**
		 * This sets up the pins
		 */
		void _init_pins();

		/**
		 * This sets up the SPI bus
		 */
		void _init_spi();

		/**
		 * This sets up the ADS1298 chip to function
		 */
		void _init_ads();

		/**
		 * Reset the entire ADS1298 chip
		 */
		void _reset_ads1298();

		/**
		 * Reset the comms on the ADS1298
		 */
		void _reset_ads1298_comms();

		/**
		 * This starts the ADS1298 Conversions
		 */
		void _start_ads1298();
		//TODO

		/**
		 * This stops the ADS1298 Conversions
		 */
		void _stop_ads1298();
		//TODO
};

#endif /* ADS1298DRIVER_H_ */
