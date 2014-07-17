
#include <Arduino.h>
#include <GHID API/GHID_Project.h>

/**
 * This sketch will set all analog ports as inputs, and will
 * set 2 digital ports (2, 3) as outputs, while 4, 5, 6 are
 * set as inputs. The pins 4 and 5 will be attached to
 * interrupts, which will interrupt the CPU process
 * on signal rising.
 *
 * For this example to work you must have the following setup
 *
 *  - Digital Pin 1 = LED -> pulled at a low state.
 *  - Digital Pin 2 = LED -> pulled at a low state.
 *
 *  - Digital Pin 3 = Switch -> pulled to a low state.
 *  - Digital Pin 4 = Receive line on the serial terminal (SERIAL0 - RX)
 *  - Digital Pin 5 = Transmit line on the serial terminal (SERIAL0 - TX)
 *
 *  - All Analog pins connected to nothing
 *  - Arduino connected to the computer.
 *
 *  Goal:
 *  	The goal of this example is to generate some random axis movement
 *  	from noise on the analog pins, while also providing some serial
 *  	transmission feedback in form of an led blinking and also to explain
 *  	how this framework can support external usb buttons.
 */

//! These are the prototypes for the sketch
void setup(void);
void loop(void);

//! Here we are allocating an array of analog pins.
Analog_Port analog_port[3];

//! Here we are allocating an array of digital pins \
	that will be set later on in this program.
Digital_Port digital_port[5];

//! Here we setup a context object
GHID_System_Abstration system;

/**
 * This function overrides the Arduino framework setup function,
 * with our setup routines.
 */
void setup(void){

	//! Here we setup the USB interface
	system.setup_USB_interface();

	//! We are setting analog ports as inputs.
	for(register byte i = 0; i < 3; i++){
		analog_port[i] = Analog_Port(i, 'I');
	}

	//! We allocate 2 of the digital pins as outputs.
	digital_port[0] = Digital_Port(1, 'O');
	digital_port[1] = Digital_Port(2, 'O');

	//! We then allocate the 3 remaining pins as inputs
	for(register byte i = 3; i < 5; i++){
		digital_port[i] = Digital_Port(i, 'I');
	}

	//! Then we Attach the interrupt to the digital inputs.

	//! Serial Terminal
	digital_port[3].set_trigger_settings(RISING, turn_led1_HIGH, 1);
	digital_port[4].set_trigger_settings(RISING, turn_led1_LOW, 2);

	//! Switch
	digital_port[2].set_trigger_settings(CHANGE, toggle_led2, 3);

}

/**
 * This function sets the led that is plugged in
 * digital port 1 at a high state (Turned On).
 */
void turn_led1_HIGH(){

	//! We write a high value to the port
	digital_port[0].write_port(HIGH);
}

/**
 * This function sets the led that is plugged in
 * digital port 1 at a low state (Turned Off).
 */
void turn_led1_LOW(){

	//! We write a low value to the port
	digital_port[0].write_port(LOW);
}

/**
 * This function reads the switch state and assigns it to a
 * button bit inside the USB structure.
 */
void toggle_led2(){

	//! We toggle the led2
	byte temp_value = digital_port[1].read_port();
	system.joystick_report.buttons.buttons_bits.button_1 = temp_value;
}

/**
 * This is the main worker function, which never quits until the
 * process is complete.
 *
 * All we do in this function is read the data from the analog ports,
 * and send them off to the computer in form of usb packets.
 */
void loop(){

	//! Here we assign the analog ports to the respective \
		usb frame section.
		system.joystick_report.x_axis = analog_port[0].read_port();
		system.joystick_report.y_axis = analog_port[1].read_port();
		system.joystick_report.z_axis = analog_port[2].read_port();
		system.send_USB_frame();
}
