/*
 * IncFile1.h
 *
 * Created: 1/29/2014 8:56:57 PM
 *  Author: francis-ccs
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

 //! ONLY ONE OF THE FOLLOWING SHOULD BE CHOSEN!
 // #define MOUSE_REPORT						//! Only send the Mouse USB report
 #define JOYSTICK_REPORT					//! Only send the joystick USB report

 #define NUM_BUTTONS					8
 #define MAX_BUTTON_VAL					255
 #define NUM_AXES						3
 #define MAX_AXIS_VAL					65535
 
 // This defines the order of the values in the received packet
 #define X_AXIS							1
 #define Y_AXIS							2
 #define Z_AXIS							3
 #define BUTTONS						4
 
 // This defines the number of sensors that there are in the network
 #define MAX_SENSORS		1


#endif /* INCFILE1_H_ */