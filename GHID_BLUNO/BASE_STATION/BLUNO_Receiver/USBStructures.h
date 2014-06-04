/*
 * USB_Defines.h
 *
 *  Created on: Jul 12, 2013
 *      Author: fjpapin
 */

#ifndef USB_STRUCTURES_h_
#define USB_STRUCTURES_h_

#include "HardwareDefines.h"

/// If the mouse is chosen.
#ifdef MOUSE_REPORT

/**
 * Creating a structure of variable data.
 * This is used to be able to vary the data from the
 * input parameters such as buttons (Setting them HIGH/LOW).
 */

typedef struct mouse_report_t{

	union button_byte_t{
		// Defining the buttons.
		struct{
			byte button_1 : 1;
			byte button_2 : 1;
			byte button_3 : 1;
			byte button_4 : 1;
			byte button_5 : 1;
			byte button_6 : 1;
			byte button_7 : 1;
			byte button_8 : 1;
		}buttons_bits;
		
		// We can also call the buttons as a group with this byte
		uint8_t buttons_byte;
	};

	button_byte_t button[(NUM_BUTTONS)/8]; // 8 buttons per byte
	
	int8_t x;		/*! X axis analog values (8bits) */
	int8_t y;		/*! Y axis analog values (8bits) */
	int8_t wheel;	/*! Wheel analog values. (8bits) */
	
	// We need this to separate our data between the packets.
	uint8_t spacer;
	
};

#endif

/// If the joystick is chosen
#ifdef JOYSTICK_REPORT

/**
 * Creating a structure of variable data.
 * This is used to be able to vary the data from the
 * input parameters such as buttons (Setting them HIGH/LOW).
 */

typedef struct joystick_report_t{

 	int8_t axis[NUM_AXES]; // 1 axis with 16 bits.
	 
	 
	 union button_byte_t {
		 
		 // Defining the buttons.
		 struct{
			 byte button_1 : 1;
			 byte button_2 : 1;
			 byte button_3 : 1;
			 byte button_4 : 1;
			 byte button_5 : 1;
			 byte button_6 : 1;
			 byte button_7 : 1;
			 byte button_8 : 1;
		 }buttons_bits;
		 
		 // We can also call the buttons as a group with this byte
		 uint8_t buttons_byte;
	};
	 
	button_byte_t button[(NUM_BUTTONS)/8]; // 8 buttons per byte
	
	// We need this to separate our data between the packets.
	uint8_t spacer;
	
};

#endif

#endif /* USB_DEFINES_H_ */
