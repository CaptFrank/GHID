/*
 * Main_Defines.cpp
 *
 *  Created on: Jul 31, 2013
 *      Author: fjpapin
 */

#include "Main_Defines.h"

#define PAUSE_ROUTER				0x07 	// Pause router

	/**
	 * This does a memory check of the whole system, and checks
	 * to see how much free mem there is.
	 */
	word main_defines::memory_check(){
        #ifdef DEBUG
			DEBUG_SERIAL.println("EXEC MEM CHECK");
        #endif
		word freemem;
		freemem = ((word)&freemem) - ((word)&__bss_end);
		return freemem;
	}

	/**
	 * This function is accessible throughout the code repo
	 * it allows the functions to return and terminate the process
	 * as an error.
	 */
	void main_defines::error(){

	#ifdef DEBUG_LEDs
		debug_api.print_error(FATAL, FATAL_ERROR);
		debug_api.set_leds(FATAL_ERROR);
	#endif

	#ifndef DEBUG
		command_interpreter.send_cmd(USB_DEVICE_CMD, (void*)PAUSE_ROUTER);
		DEBUG_SERIAL.println("REBOOTING DEVICE.");
	#endif

	// We send a stop to the network
	error();

	#ifdef SELECT_BUTTON_2
		//! Infinite loop hangs the system
		for(;;);
	#endif
		reset_device();
	}
	
	byte main_defines::check_context(){
		return *(this->global_context_error_flag);
	}


