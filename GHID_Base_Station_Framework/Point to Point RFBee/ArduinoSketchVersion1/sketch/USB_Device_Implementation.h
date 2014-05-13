/*
 * USB_Device_Implementation.h
 *
 *  Created on: Jul 17, 2013
 *      Author: francispapineau
 */

#ifndef USB_DEVICE_IMPLEMENTATION_H_
#define USB_DEVICE_IMPLEMENTATION_H_

#include "Command_Interpreter.h"
#include "USB_Structures.h"
#include "Packet_Parser.h"
#include "Main_Defines.h"
#include "NVRAM_API.h"
#include "Scheduler.h"

class USB_DEVICE : public main_defines{

	private:
		
    	//! The pointer to the data structure
		byte* _packet_buffer;

        //! The packet id
        word _packet_id;

        //! The packet size
        byte _packet_size;

        //! The mutex for the packet in the queue
        byte _packet_in_sending_queue;

        //! Our command interpreter
        COMMAND_PARSER* _command_interpreter;

        //! Our Packet Parser
        PACKET_PARSER* _packet_parser;
		
		//! Our Packet decoder
		PACKET_HANDLER* _packet_handler;
		
		//! Sensor db
		SENSOR* _sensors;
		
		//! Scheduler pointer
		SCHEDULER* _scheduler;

        /**
         * Init the rf network
         */
		void _init_rf_network();

		/**
		 * Setup the usb report parameter pointers
		 */
		void _setup_usb_report_params();

		/**
		 * Creates a usb report frame to send
		 */
		void* _create_usb_report_frame();

		/**
		 * Sends the usb report
		 */
		void _send_usb_report_frame(void* report);

	public:

		/**
		 * The class constructor
		 */
		USB_DEVICE(COMMAND_PARSER* command_interpreter,
					PACKET_PARSER* packet_parser, PACKET_HANDLER* packet_handler,
					SENSOR* sensors, SCHEDULER* scheduler);

		/**
		 * Runs the usb device
		 */
		void run_usb();
};


#endif /* USB_DEVICE_IMPLEMENTATION_H_ */
