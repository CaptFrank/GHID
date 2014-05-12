
#include <Arduino.h>
#include <GHID API/GHID_Project.h>

//! These are the prototypes for the sketch
void setup(void);
void loop(void);

//! Here we setup a context object
GHID_System_Abstration system;

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
	
	//! Here we set the analog seed for the random number
	//! generation.
	randomSeed(analogRead(0));

}

/**
 * This is the main worker function, which never quits until the
 * process is complete.
 */
void loop(){

	//==========================================
	// INSERT WORKER CODE HERE
	//==========================================
	
	//! We assign the random values to the USB frame
	system.joystick_report.x_axis = random(100);
	system.joystick_report.y_axis = random(100);
	system.joystick_report.z_axis = random(100);
	system.joystick_report.buttons = random(8);
	
	system.send_USB_frame();
}


