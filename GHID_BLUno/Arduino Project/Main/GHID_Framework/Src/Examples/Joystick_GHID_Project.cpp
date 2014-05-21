
#include <Arduino.h>

//! We need digital ports
#define GHID_DIGITAL_PORT

//! We need analog ports
#define GHID_ANALOG_PORT

#include <GHID API/GHID_Project.h>
#include <Included Libraries/ADXL335.h>

//! We define our analog axis
#define X_AXIS		1
#define Y_AXIS		0

//! We define the digital inputs
#define D_1			5
#define D_2			3
#define D_3			4

//! These are the prototypes for the sketch
void setup(void);
void loop(void);

//! Here we setup a context object
GHID_System_Abstration system;

//! We need 3 analog ports for the accelerometer
Analog_Port X;
Analog_Port Y;

//! We need 3 digital ports for the buttons
Digital_Port D1;
Digital_Port D2;
Digital_Port D3;

/**
 * This function overrides the Arduino framework setup function,
 * with our setup routines.
 */
void setup(void){

	//! Here we setup the USB interface
	system.setup_USB_interface();

	//=========================================
	// INSERT SETUP CODE HERE 
	//=========================================
	
	//! We setup the analog and digital ports;
	X = new Analog_Port(X_AXIS, 'I');
	Y = new Analog_Port(Y_AXIS, 'I');

	D1 = new Digital_Port(D_1, 'I');
	D2 = new Digital_Port(D_2, 'I');
	D3 = new Digital_Port(D_3, 'I');

}

/**
 * This is the main worker function, which never quits until the
 * process is complete.
 */
void loop(){

	//==========================================
	// INSERT WORKER CODE HERE
	//==========================================
	
	//! We delay 10ms
	delay(10);

	//! Here we check the button states with no destructive writes

	//! Button 1
	if(D1.read_port() == HIGH){
		system.joystick_report.buttons.buttons_bits.button_1 &= 0;
	} else {
		system.joystick_report.buttons.buttons_bits.button_1 |= 1;
	}

	//! Button 2
	if(D2.read_port() == HIGH){
		system.joystick_report.buttons.buttons_bits.button_2 &= 0;
	} else {
		system.joystick_report.buttons.buttons_bits.button_2 |= 1;
	}

	//! Button 3
	if(D3.read_port() == HIGH){
		system.joystick_report.buttons.buttons_bits.button_3 &= 0;
	} else {
		system.joystick_report.buttons.buttons_bits.button_3 |= 1;
	}


	//! We map the values
	system.joystick_report.x_axis = (int8_t) map(X.read_port(), 0, 1023, -100, 100);
	system.joystick_report.y_axis = (int8_t) map(Y.read_port(), 0, 1023, -100, 100);
	system.joystick_report.z_axis = (int8_t) 0x00; //! not used

	system.send_USB_frame();
}


