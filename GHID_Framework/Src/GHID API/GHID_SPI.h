/*
* GHIDSPI.h
 *
 *  Created on: 2014-02-06
 *      Author: francispapineau
 */

#ifndef GHIDSPI_H_
#define GHIDSPI_H_

#include <SPI.h>
#include <Arduino.h>

//! These are hardware definitions for the SPI interface \
	on the Arduino Mega 2560
#ifdef __ATMEGA_2560__
	#define MOSI		51
	#define MISO		51
	#define SCLK		52
	#define SS			53
#endif

//! Max buffer size
#define MAX_BUFFER		255

//! Delays
#define ONE_MICRO_SEC	1

//! Buffer structure
struct buffer_struct_t {

	byte length;
	byte buffer[MAX_BUFFER];
}spi_buffer;

//! This is a spi network device list.
//! You must implement this map with the appropriate pin allocations
//! so that SS can select propertly.
enum spi_device_address_map_t {

	START_DEVICE_ENUM,
	DEFAULT_DEVICE = 0,
	END_DEVICE_ENUM
};

//! SPI device settings
struct spi_settings_t {

	byte attach_interrupt;			//! do we attach an interrupt on the SPI bus?
	void (*service_method)(void);	//! Service method for spi input

	byte data_mode;					//! The data mode as per Arduino API
	byte bit_order;					//! The order of bits
	byte clock_divider;				//! Frequency prescaler
	spi_device_address_map_t map;	//! The device map
};

/**
 * This class is an extended class of the Arduino SPIClass.
 * It provides a wrapper to the SPIClass with additional
 * extra features.
 *
 * @see SPI.h
 */
class GHID_SPI : SPIClass{

	//! Public Context
	public:

	//! The publicly accessible buffer
	buffer_struct_t buffer;

	/**
	 * This is the default constructor for the class. It sets up the
	 * required SPI device with a passed settings_t pointer.
	 *
	 * @param settings - pointer to settings
	 */
	GHID_SPI(spi_settings_t* settings);

	/**
	 * This transfers one byte to the slave selected.
	 *
	 * @param device - the address to send
	 * @param data - the data to send
	 */
	void tranfer_data(spi_device_address_map_t device, byte data);

	/**
	 * This method sends a bulk byte array to the requested address.
	 *
	 * @param device - the address of the slave
	 * @param data - the data to send
	 * @param length - the length of the array
	 */
	void transfer_bulk(spi_device_address_map_t device, byte* data, byte length);

	/**
	 * This is the read data from device method. We specify the address to
	 * receive data from and how long of data we need to receive.
	 *
	 * @param device - address
	 * @param length - the length to receive
	 * @param command - the read command
	 */
	buffer_struct_t* read_data(spi_device_address_map_t device, byte length, byte command);

	/**
	 * This checks the spi buffer for any bytes received.
	 */
	void check_spi_buffer();

	//! Private Context
	private:

	//! The settings container
	spi_settings_t settings;

};

#endif /* GHIDSPI_H_ */
