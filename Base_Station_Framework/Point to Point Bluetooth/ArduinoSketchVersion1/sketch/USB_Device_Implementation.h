/*
 * USB_Device_Implementation.h
 *
 *  Created on: Jul 17, 2013
 *      Author: francispapineau
 */

#ifndef USB_DEVICE_IMPLEMENTATION_H_
#define USB_DEVICE_IMPLEMENTATION_H_

#include "USB_Structures.h"
#include "Main_Defines.h"
#include "Bluetooth_Engine.h"
#include "NVRAM_API.h"

class USB_DEVICE {

	private:
		
    	//! The pointer to the data structure
		byte* _packet_buffer;

        //! The packet id
        word _packet_id;

        //! The packet size
        byte _packet_size;

        //! The mutex for the packet in the queue
        byte _packet_in_sending_queue;

		//! The bluetooth engine
		BLUETOOTH_ENGINE* _bt_engine;
		
		//! The error flag
		byte* _internal_error_flag;
		
        /**
         * Init the rf network
         */
		void _init_bluetooth_network();

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
		USB_DEVICE(BLUETOOTH_ENGINE* bt_engine, byte* global_context_error_flag);

		/**
		 * Runs the usb device
		 */
		void run_usb();
};


#endif /* USB_DEVICE_IMPLEMENTATION_H_ */
