
/**
 * This is the most basic application that a Bluno can upload. 
 * The User most customize the application to his needs. It is 
 * important to note that the Bluno can also output daaa through the 
 * Serial port. The serial port (Serial) outputs to the Bluno and the 
 * Computer ---- This can be changed by changing the AT setting. Please
 * review these for clarification. (Bluno_AT_Settings.txt)
 */

#include <Arduino.h>

// The demo tag
#define DEMO_TAG			"DEMO"

//! These are the prototypes for the sketch
void setup(void);
void loop(void);

/**
 * This function overrides the Arduino framework setup function,
 * with our setup routines.
 */
void setup(void){

	//=========================================
	// INSERT SETUP CODE HERE 
	//=========================================
	
	//! Setup the Serial Interface
	Serial.begin(115200);
}

/**
 * This is the main worker function, which never quits until the
 * process is complete.
 */
void loop(){

	//==========================================
	// INSERT WORKER CODE HERE
	//==========================================
	
	//! We check for available serial data within the 
	//! serial ring buffer
	if(Serial.available()){
		
		//! We got some data...
		//! Make a message
		message_t* msg = SimpleProtocol::get_message(millis(), DEMO_TAG, Serial.read());
		
		//! loop it back to the other Bluno node
		Serial.write(msg->message, msg->message_length);
		//! This will output something like this:
		//!		- "[123421]: <DEMO> {Hello World}\n\r"
	}
}
