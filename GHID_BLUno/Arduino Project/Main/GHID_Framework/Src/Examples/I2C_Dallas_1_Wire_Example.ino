/*
 * I2C_Dallas_1_Wire_Example.cpp
 *
 *  Created on: 2014-03-11
 *      Author: francispapineau
 */

#include <Arduino.h>
#include <GHID API/GHID_Project.h>

/**
 * This sketch will read a one wire sensor (DS1820 sensor) and will
 * wire the value to and EEPROM.
 *
 * For this example to work you must have the following setup
 *
 *  - An I2C enabled eeprom must be setup on the I2C bus.
 *  - A Dallas One Wire DS1820 sensor must be setup on pin 5.
 *
 *  - All Analog pins connected to nothing
 *  - Arduino connected to the computer.
 *
 *  Goal:
 *  	The goal of this sketch is to demo the ability to read and write
 *  	using mutiple protocols. In this case the I2C and Dallas one wire
 *  	protocols are used.
 *
 *  Note:
 *  	For more information about the 1-wire sketch please see:
 *  		- http://playground.arduino.cc/Learning/OneWire#.Ux_ZIdwjFZg
 */

//! Hardware definitions
#define ONE_WIRE_PIN		0x05
#define TWO_WIRE_ADDRESS	0x00

//! These are the prototypes for the sketch
void setup(void);
void loop(void);
void check_ds1820(void);

//! Here we setup a context object
GHID_System_Abstration system;

//! Here we create the one wire driver
GHID_Dallas_1_Wire one_wire(ONE_WIRE_PIN);

//! Here we create the EEPROM driver
GHID_EEPROM eeprom;

//! One wire addresses found
uint8_t one_wire_address_found[8];

/**
 * This function overrides the Arduino framework setup function,
 * with our setup routines.
 */
void setup(void){

	//! Here we setup the USB interface
	system.setup_USB_interface();

	//! Here we setup the devices.
	check_ds1820();
}

/**
 * This is the main worker function, which never quits until the
 * process is complete.
 */
void loop(){

	//! Here we read the sensor and write the value to the internal
	//! EEPROM of the arduino and the external eeprom as well.

	one_wire.reset();
	one_wire.select(one_wire_address_found);
	one_wire.write(0x44,1);         // start conversion, with parasite power on at the end

	delay(1000);     // maybe 750ms is enough, maybe not
	// we might do a ds.depower() here, but the reset will take care of it.

	uint8_t present = one_wire.reset();
	one_wire.select(one_wire_address_found);
	one_wire.write(0xBE);

    // we need 9 bytes
	one_wire.buffer = one_wire.read_bulk(9);

	//! We write the data to the eeprom
	eeprom.write_data(0x02, one_wire.buffer.buffer, 9);

	//! We send the data in the usb packet
	memcpy((void*)&system.joystick_report, (void*)&one_wire.buffer.buffer,
			sizeof(system.joystick_report));

	system.send_USB_frame();
}

/**
 * This function checks the one wire bus for more devices.
 */
void check_ds1820(){

	//! We check to see if there are more one wire devices on the bus
	 if (!one_wire.search(one_wire_address_found)){
		 one_wire.reset_search();
	     return;
	  }
	 return;
}




