/*
 * Debug_LED_Function.h
 *
 *  Created on: Jul 13, 2013
 *      Author: francispapineau
 */

#ifndef Debug_LED_Function_h_
#define Debug_LED_Function_h_

#include <stdio.h>
#include "Main_Defines.h"

//! Debug indexes
#define FATAL			1
#define WARNING			2
#define INFO			3
#define DEBUG_LED		4
#define MEMORY			5
#define REBOOT			7
#define DEBUG_ERROR		6
#define STATE_CHANGE	8

//! LED error codes
#define FATAL_ERROR		0
#define CLEAR_ERRORS	1
#define WARNING_ERROR	2
#define INFO_ERROR		3
#define DEBUG_INFO		4
#define MEMORY_ERROR	5
#define REBOOT_ERROR	7


//! The Strings needed
const String DEBUG_STRINGS[9] = {

		"FATAL  ",
		"WARNING",
		"INFO   ",
		"DEBUG  ",
		"MEMORY ",
		"REBOOT ",
		"DEBUG E",
		"STATE  "
};

//! The debug codes.
const byte DEBUG_CODES[9] = {

		0b0000001,	// FATAL ERROR
		0b0000010,	// STATE CHANGE
		0b0000100,	// WARNING ERROR
		0b0001000,	// INFO ERROR
		0b0010000,	// DEBUG INFO
		0b0100000,	// MEMORY ERROR
		0b1000000,	// DEBUG ERROR
		0b1111111, 	// REBOOT ERRORS
		0b0000000 	// CLEAR ERRORS
};

//! The LED codes
const byte DEBUG_LED_CODES[9] = {

		0b0001,		// FATAL ERROR
		0b0000,		// CLEAR ERRORS
		0b0010,		// WARNING ERROR
		0b0100,		// INFO ERROR
		0b1000,		// DEBUG INFO
		0b0011,		// MEMORY ERROR
		0b0101,		// DEBUG ERROR
		0b1111		// REBOOT ERROR
};

/**
 * This structure holds all the definitions for
 * states and strings associated debug messages.
 */
struct DEBUG_CODES_STRUCT {

		//! The index to the arrays.
		byte ERROR_INDEX; //! Cannot be bigger than 9;

}; //! Defining a type

/**
 * This is a structure that holds the
 * total errors for each class of errors.
 */
struct ERROR_TYPE_COUNTS {

	//! The counts for each errors.
	byte warnings_errors;
	byte info_errors;
	byte debug_errors;
	byte memory_errors;

	//byte fatal_errors; //not needed since it will reboot.
};

/**
 * This class is implemented to handle debug commands and
 * states to then output the LED states and show a debug
 * code.
 */
class DEBUG_API public main_defines{

	private:

		//! Errors
		ERROR_TYPE_COUNTS errors;

		//! The needed pointers for the print
		char* debug_type;
		byte* debug_code;
		byte* led_debug_code;

		//! Boolean mutexes for the process
		bool debug_set;
		bool reboot_wd;

		/**
		 * This reboots the device given a reason.
		 * @param cause - the debug code
		 */
		void reboot_cause_error(byte cause);

		/**
		 * The default print_error
		 * @param error_type - String
		 * @param error_code - byte
		 * @param error_led_code - byte
		 * @param string - String
		 */
		void print_error(String error_type, byte error_code,
				byte error_led_code, String* string);

	public:

		/**
		 * The default constructor
		 */
		DEBUG_API();

		/**
		 * The print error externally from the api.
		 * @param error_index - byte
		 * @param string - String
		 */
		void print_error(byte error_index, String* string);

		/**
		 * This enables the api.
		 */
		void enable_debug();

		/**
		 * This disables the api.
		 */
		void disable_debug();

		/**
		 * This gets the number of specified errors.
		 * @param debug_type - String
		 * @return byte - number
		 */
		byte get_number_of(String debug_type);

		/**
		 * Tests the leds.
		 * Only happens if there are defined.
		 */
		void test_leds();

		/**
		 * Sets the leds based on the error_message index passed.
		 * @param error_index - byte
		 */
		void set_leds(byte error_index);
};

#endif
