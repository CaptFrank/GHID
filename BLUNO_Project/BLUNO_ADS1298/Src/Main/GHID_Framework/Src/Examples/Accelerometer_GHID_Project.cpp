#include <Arduino.h>

//! We need digital ports
#define GHID_DIGITAL_PORT

//! We need analog ports
#define GHID_ANALOG_PORT

#include <GHID API/GHID_Project.h>
#include <Included Libraries/ADXL335.h>

//! We define our analog axis
#define A_1			5
#define A_2			4
#define A_3			3

//! We define the digital inputs
#define D_1			7
#define D_2			8
#define D_3			9

//! We define the rails
#define GND_		2
#define VCC_		0

//! We define the reference voltage
#define AREF		3.3

//! These are the prototypes for the sketch
void setup(void);
void loop(void);

//! Here we setup a context object
GHID_System_Abstration system;

//! We need 3 analog ports for the accelerometer
Analog_Port A1;
Analog_Port A2;
Analog_Port A3;

//! Define the rails
Analog_Port GND;
Analog_Port VCC;

//! We need 3 digital ports for the buttons
Digital_Port D1;
Digital_Port D2;
Digital_Port D3;

//! Create an accelerometer object
ADXL335 accelerometer(A_1, A_2, A_3, AREF);

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
	A1 = new Analog_Port(A_1, 'I');
	A2 = new Analog_Port(A_2, 'I');
	A3 = new Analog_Port(A_3, 'I');

	VCC = new Analog_Port(VCC_, 'O');
	GND = new Analog_Port(GND_, 'O');

	D1 = new Digital_Port(D_1, 'I');
	D2 = new Digital_Port(D_2, 'I');
	D3 = new Digital_Port(D_3, 'I');

	//! We write the values for the rails
	VCC.write_port(255); 	//! ON
	GND.write_port(0); 		//! OFF

	//! We set the analog reference
	system.setup_analog_reference(EXTERNAL);

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

	//! We update the accelerometer values
	accelerometer.update();

	//! We map the values
	system.joystick_report.x_axis = (int8_t) (accelerometer.getX() * 100.0);
	system.joystick_report.y_axis = (int8_t) (accelerometer.getY() * 100.0);
	system.joystick_report.z_axis = (int8_t) (accelerometer.getZ() * 100.0);

	system.joystick_report.buttons.buttons_bits.button_1 = D1.read_port();
	system.joystick_report.buttons.buttons_bits.button_2 = D2.read_port();
	system.joystick_report.buttons.buttons_bits.button_3 = D3.read_port();

	system.send_USB_frame();
}
