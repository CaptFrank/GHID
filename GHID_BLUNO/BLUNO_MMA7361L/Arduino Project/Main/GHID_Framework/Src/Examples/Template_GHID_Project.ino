
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
	
}

/**
 * This is the main worker function, which never quits until the
 * process is complete.
 */
void loop(){

	//==========================================
	// INSERT WORKER CODE HERE
	//==========================================
	
	system.send_USB_frame();
}


