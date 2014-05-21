/*
 * USB_Defines.h
 *
 *  Created on: Jul 12, 2013
 *      Author: fjpapin
 */

#ifndef USB_STRUCTURES_h_
#define USB_STRUCTURES_h_

#include "GHID_System_Abstration.h"

//! If the mouse is chosen.
#ifdef MOUSE_REPORT

/**
 * Creating a structure of variable data.
 * This is used to be able to vary the data from the
 * input parameters such as buttons (Setting them HIGH/LOW).
 */

typedef struct {

	union {
		//! Defining the buttons.
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

		//! We can also call the buttons as a group with this byte
		uint8_t buttons_byte;
	}buttons;

	int8_t x;		/*! X axis analog values (8bits) */
	int8_t y;		/*! Y axis analog values (8bits) */
	int8_t wheel;	/*! Wheel analog values. (8bits) */

	//! We need this to separate our data between the packets.
	uint8_t spacer;

}mouse_report_t;

#endif

//! If the joystick is chosen
#ifdef JOYSTICK_REPORT

/**
 * Creating a structure of variable data.
 * This is used to be able to vary the data from the
 * input parameters such as buttons (Setting them HIGH/LOW).
 */

typedef struct {

	//! Buttons can be individually assigned, \
		or assigned as a group
	union {

		 //! Defining the buttons.
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

		 //! We can also call the buttons as a group with this byte
		 uint8_t buttons_byte;
	}buttons;

	//! Axis definition
	int8_t x_axis;
	int8_t y_axis;
	int8_t z_axis;

	//! We need this to separate our data between the packets.
	uint8_t spacer;

}joystick_report_t;

#endif

#endif /* USB_DEFINES_H_ */
