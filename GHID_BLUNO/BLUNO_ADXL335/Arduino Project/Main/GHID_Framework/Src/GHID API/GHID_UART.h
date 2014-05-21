/*
 * GHIDUART.h
 *
 *  Created on: 2014-02-06
 *      Author: francispapineau
 */

#ifndef GHIDUART_H_
#define GHIDUART_H_

#define __AVR_ATmega2560__

#include "Arduino.h"
#include <avr/io.h>

//! We deine the HARDWARE flag, and the SOFTWARE flag
#define HARDWARE_SERIAL_FLAG	0
#define SOFTWARE_SERIAL_FLAG	1

//! Definition of a quadword
typedef uint32_t qword;

//! This is a container for the serial settings.
struct serial_settings_t {

	byte hw_sw_flag; 		//! This determines the type of device
	qword baudrate;			//! This determines the baud rate of the device
	byte logic_type;		//! This determines of the device has reverse logic
	byte serial_port;		//! The hardware serial port used
	byte rx_pin;			//! The rx pin for the software serial port
	byte tx_pin;			//! The tx pin for the software serial port
	byte parity;			//! The parity of the serial port as defined in \
								the arduino API.
};

/**
 * This class is a class in which we can define two types of UART interfaces.
 * Either software serial drivers can be instantiated or hardware serial
 * bus drivers can be instantiated. This class extends the SoftwareSerial class
 * and the HardwareSerial class which are both included in the Arduino IDE framework.
 *
 * @see SoftwareSerial.h
 * @see HardwareSerial.h
 */
class GHID_UART : public SoftwareSerial, public HardwareSerial{

	//! The public context
	public:

	/**
	 * This is the default constructor for the class.
	 * It mainly assigns the parameters to created serial ports.
	 *
	 * @see serial_settings - the settings for the serial port
	 * @param serial_settings - the settings
	 */
	GHID_UART(serial_settings_t* settings);


	//! The private context
	private:

	//! A map of the available Hardware Serials on the ATMega 256
	const void* map[] = {Serial1, Serial2, Serial3};

	//! The pointer to the appropriate subclass device
	//! - Either hardware or software serial
	HardwareSerial* serial_driver_hw;
	SoftwareSerial* serial_driver_sw;

	//! The settings container
	serial_settings_t settings;

	/**
	 * This is the method which we use to set the appropriate
	 * device to the internal class object representing a device.
	 */
	void _get_object_type();

	/**
	 * This method sets up the set device internally
	 */
	void _setup_device();
};

#endif /* GHIDUART_H_ */
