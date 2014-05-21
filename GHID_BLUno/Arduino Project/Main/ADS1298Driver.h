/*
 * ADS1298Driver.h
 *
 *  Created on: 2014-05-15
 *      Author: francispapineau
 */

#ifndef ADS1298DRIVER_H_
#define ADS1298DRIVER_H_

#include <Arduino.h>
#include "SPI.h"

#include "GHID_SPI.h"
#include "RingBuffer.h"
#include "ADS1298Commands.h"

//! Pin definitions - SPI Bus
#define PIN_MOSI				11
#define PIN_MISO				12
#define PIN_SCLK				10 		//! Default
#define PIN_SS					13

//! Pin definitions - Signals
#define PIN_RESET				9
#define PIN_START				8
#define PIN_DRDY				2
#define PIN_LED					6
#define PIN_PWDN				7

//! I/O Commands
#define READ					0x20
#define WRITE					0x40

//! Delays
#define ONE_SECOND				1000
#define HALF_SECOND				500
#define ONE_MILLI				1

//! General defines
#define TRUE					0x01
#define FALSE					0x00
#define NONE					0x00
#define SPACER					0x00

//! SPI Device settings
#define NUMBER_OF_SPI_DEVICES	1
#define ADS1298_DEVICE			13

//! Packet defines
#define HEADER					3
#define CHANNEL_RESOLUTION		3
#define NUM_CHANNELS			8
#define DATA_PACKET_SIZE		HEADER + (CHANNEL_RESOLUTION * NUM_CHANNELS)

//! This initializes the pinout and the device map.
#define __ATMEGA_32__

/**
 * We define a structure that tells us which channels are ON and
 * which channels are OFF.
 */
typedef struct active_channels_t {

	//! We unionize the bits to a byte
	union {

		//! individual bits
		struct {

			uint8_t channel_1 : 1;
			uint8_t channel_2 : 1;
			uint8_t channel_3 : 1;
			uint8_t channel_4 : 1;
			uint8_t channel_5 : 1;
			uint8_t channel_6 : 1;
			uint8_t channel_7 : 1;
			uint8_t channel_8 : 1;

		} channel_bits;

		uint8_t channel_byte;
	};
};

/**
 * We create an rx buffer
 */
typedef struct rx_buffer_t {

	union {
		struct {
			uint8_t _header[HEADER];
			uint8_t _data[CHANNEL_RESOLUTION * NUM_CHANNELS + 1];
		}packet;
		uint8_t packet_array[HEADER + (DATA_PACKET_SIZE)];
	}data;
};

/**
 * This is the ADS1298 Driver. It handles the reads and writes to the ADS1298
 * device.
 */
class ADS1298_Driver : public GHID_SPI {

	//! Public Context
	public:

		/**
		 * This is the default constructor for the class
		 *
		 * @param buff							- The general context ring buffer
		 * @param setup_method					- The setup method called.
		 * @param devices						- The device array
		 * @param spi_settings					- The SPI settings
		 */
		ADS1298_Driver(RingBuff_t* buff, 
					   uint8_t* devices, 
					   spi_settings_t* settings,
					   void (*setup_method)(ADS1298_Driver* driver) = _init_ads);

		/**
		 * This method reads a byte from the ADS1298 chip
		 *
		 * @param reg_address					- The address to read
		 * @return byte							- The byte read
		 */
		uint8_t read_byte(int reg_address);

		/**
		 * This method writes a byte to the ADS1298
		 *
		 * @param reg_address					- The register address
		 * @param val_hex						- The value in hex
		 */
		void write_byte(int reg_address, uint8_t val_hex);

		/**
		 * This method sends a command to the ADS1298
		 *
		 * @param cmd							- The command to send
		 */
		void send_command(uint8_t cmd);

		/**
		 * This method checks which channels are active.
		 */
		void check_active_channels();

		//! The internal Ring Buffer access
		RingBuff_t* _buff;

		//! The internal rx buffer type
		rx_buffer_t _rx_buff;

	//! Private Context
	private:

		//! Configuration structure
		struct {

			//! The id of the device
			uint8_t _id;

			//! Number of channels available
			uint8_t _channels;

			//! Number of active channels
			uint8_t _num_active_channels;
			active_channels_t _active_channels;

			//! The guard that tells us if the streaming has started
			uint8_t _active;

		}_configs;
		
		//! device map
		uint8_t* _devices;
		
		//! spi settings
		spi_settings_t* _settings;
		
		//! Init methods

		/**
		 * This sets up the pins
		 */
		void _init_pins();

		/**
		 * This sets up the ADS1298 chip to function
		 */
		static void _init_ads(ADS1298_Driver* driver);

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

		/**
		 * This stops the ADS1298 Conversions
		 */
		void _stop_ads1298();

		/**
		 * Power down the chip
		 */
		void _power_down_ads1898();

		/**
		 * Unpower down the chip
		 */
		void _unpower_down_ads1898();

		/**
		 * Set SS pin high
		 */
		void _set_ss_pin();

		/**
		 * Unset ss pin
		 */
		void _unset_ss_pin();

};

#endif /* ADS1298DRIVER_H_ */
