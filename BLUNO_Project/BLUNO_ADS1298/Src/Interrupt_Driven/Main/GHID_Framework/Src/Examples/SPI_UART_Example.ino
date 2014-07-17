/*
 * SPI_UART_Example.cpp
 *
 *  Created on: 2014-03-11
 *      Author: francispapineau
 */

#include <Arduino.h>
#include <GHID API/GHID_Project.h>

/**
 * This sketch will instantiate 2 UART ports (1 hardware serial, 1 software serial),
 * and will instantiate an SPI port. The user will then be able to write to the UART
 * through the computer interface. The content sent to the Arduino board, will then
 * be broadcast to the UART2, the SPI and the USB interface.
 *
 * For this example to work you must have the following setup
 *
 *  - You must be using the ARDUINO MEGA
 *  - You must be using an Serial cable at UART1 and UART2.
 *  - The SPI port can be scoped for debugging purposes.
 *
 *  - All Analog pins connected to nothing
 *  - Arduino connected to the computer.
 *
 *  Goal:
 *  	The goal of this sketch is to show that it is possible to create a
 *  	hardware UART port as well as a software UART. This sketch also has for
 *  	goal to show how to interface with the SPI port.
 *
 */

//! We define the pins used
#define SW_RX_PIN	10
#define SW_TX_PIN	11

//! These are the prototypes for the sketch
void setup(void);
void loop(void);

//! Here we setup a context object
GHID_System_Abstration system;

//! This is the SPI settings
spi_settings_t spi_settings;

//! This is the SPI handle
GHID_SPI* spi_handle;

//! This is the spi device map
enum spi_device_address_map_t {

	START_DEVICE_ENUM,
	DEFAULT_DEVICE = 0,
	DEVICE_1 = 5, // Our SS pin should be on pin 5 for demo
	END_DEVICE_ENUM
}device_map;

//! These are the UART Settings for both the hw UART and sw UART.
serial_settings_t hw_settings, sw_settings;

//! These are the serial handles
GHID_UART* hw_serial;
GHID_UART* sw_serial;

/**
 * This function overrides the Arduino framework setup function,
 * with our setup routines.
 */
void setup(void){

	//! Here we setup the USB interface
	system.setup_USB_interface();

	//! Here we setup the UART1 port to receive data
	hw_settings.baudrate = 9600;
	hw_settings.hw_sw_flag = HARDWARE_SERIAL_FLAG;
	hw_settings.serial_port = 1;
	hw_settings.parity = SERIAL_8N1;

	//! We create the serial handle
	hw_serial = new GHID_UART(&hw_settings);

	//! Here we setup the UART2 port to send
	sw_settings.baudrate = 9600;
	sw_settings.hw_sw_flag = SOFTWARE_SERIAL_FLAG;
	sw_settings.logic_type = false; // Not inverted
	sw_settings.rx_pin = SW_RX_PIN;
	sw_settings.tx_pin = SW_TX_PIN;

	//! We create the serial handle
	sw_serial = new GHID_UART(&sw_settings);

	//! Here we setup the SPI port to write data
	spi_settings.attach_interrupt = 0x01;
	spi_settings.bit_order = 0x00;
	spi_settings.clock_divider = SPI_CLOCK_DIV2;
	spi_settings.data_mode = SPI_MODE0;
	spi_settings.map = device_map;

	//! Here we create the handle
	spi_handle = new GHID_SPI(&spi_settings);

}

/**
 * This is the main worker function, which never quits until the
 * process is complete.
 */
void loop(){

	//! We start the SPI engine
	spi_handle->begin();

	//! We poll the UART line
	while (true){

		//! If we have received a byte
		if (hw_serial->available()){

			//! Read it
			byte data = hw_serial->read();

			//! Write it to the sw serial
			sw_serial->write(data);

			//! Write it to the SPI bus
			spi_handle->tranfer_data(DEVICE_1, data);

			//! We set the buttons to the byte read
			system.joystick_report.buttons.buttons_byte = data;

			//! We send the data to the CPU through USB
			system.send_USB_frame();
		}
	}
}






