/*
 * Main_Defines.h
 *
 *  Created on: Jul 10, 2013
 *      Author: francispapineau
 */

//#include "./Includes.h"

#ifndef MAIN_DEFINES_h_
#define MAIN_DEFINES_h_

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//~~~~~~~~~~~~~~~~~~~~ FUNCTION DEFINITIONS ~~~~~~~~~~~~~~~~~~~~~~~~
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//! Reset the device.
	static void(*reset_device) (void) = 0; //declare reset function @ address 
	
	class main_defines {

	public:

		// the context error pointer
		byte* global_context_error_flag;
		
		/**
		 * This does a memory check of the whole system, and checks
		 * to see how much free mem there is.
		 */
		word memory_check();
	
		//! prototypes
		void error();
		
		//! check context errors
		byte check_context();
	};

#endif
