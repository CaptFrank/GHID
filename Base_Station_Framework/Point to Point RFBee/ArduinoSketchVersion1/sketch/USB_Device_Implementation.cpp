/*
 * USB_Device_Implementation.cpp
 *
 *  Created on: Jul 17, 2013
 *      Author: francispapineau
 */

#include "USB_Device_Implementation.h"

//! Default Constructor
USB_DEVICE::USB_DEVICE(COMMAND_PARSER* command_interpreter, 
	PACKET_PARSER* packet_parser, PACKET_HANDLER* packet_handler, 
	SENSOR* sensors, SCHEDULER* scheduler){

	//! Initializing the enviroment variables
	_packet_buffer = EMPTY;
	_packet_id = EMPTY;
	_packet_in_sending_queue = true;
	_packet_size = 0;

	this->_command_interpreter = command_interpreter;
	this->_packet_parser = packet_parser;
	this->_packet_handler = packet_handler;
	this->_sensors = sensors;
	this->_scheduler = scheduler;
	
	//! Set priority
	for(register byte i = 0; i < MAX_SENSORS; i++){
		this->_sensors[i].set_priority(i);
	}
}

//! Create a valid packet to send in USB format
void* USB_DEVICE::_create_usb_report_frame(){
	
	// recreate the structures we need.
#ifdef JOYSTICK_REPORT
	joystick_report_t joystick_report;
#endif
			
#ifdef MOUSE_REPORT
	union mouse_report_union_t {
		mouse_report_t mouse_report;
		unit8_t mouse_report_bytes [sizeof(mouse_report_t)];
	}mouse_report_union;
#endif

	// Defining a generic pointer to return
	void* report;
	
#ifdef MOUSE_REPORT
	for (register byte i = 0; i < sizeof(mouse_report_t); i++){
		mouse_report_union.mouse_report_bytes[i] = packet_parser._data.data_array[i];
	}
	//! Reassign the structure to send.
	report = &mouse_report_union.mouse_report;
#endif

#ifdef JOYSTICK_REPORT

	for(register byte i = 0; i < NUM_AXES; i ++){
		joystick_report.axis[i] = this->_packet_parser->_data.data_array[i];
	}
	for(register byte i = 0; i < NUM_BUTTONS/8; i ++){
		joystick_report.button[i].buttons_byte = this->_packet_parser->_data.data_array[i + NUM_AXES];
	}

	//! Reassign the structure to send.
	report = &joystick_report;
#endif

	return report;
}

//! Sends a USB report frame
void USB_DEVICE::_send_usb_report_frame(void* report){

#ifdef MOUSE_REPORT

	//! Send the structure.
	SERIAL_OUTPUT.write((uint8_t*)&report, sizeof(mouse_report_t));
#endif

#ifdef JOYSTICK_REPORT

	//! Send the structure.
	SERIAL_OUTPUT.write((uint8_t*)&report, sizeof(joystick_report_t));
#endif

	_packet_in_sending_queue = false;
}

//! Setup rf link
void USB_DEVICE::_init_rf_network(){
	
	// Setup the rf network. 
	// The global scheduler entity takes care of that for us.
	// The scheduler should be in the start position.
	this->_scheduler->run_scheduler();
	
	if(memory_check() <= MAX_MEMORY){
#ifdef DEBUG_LEDs
		debug_api.set_leds(MEMORY_ERROR);
#endif
		// We need to stop the network and reset the scheduler.
		this->_scheduler->_stop_scheduler();
		this->_scheduler->_reset_scheduler();
		error();
	}

}

// Run the usb live
void USB_DEVICE::run_usb(){

	#ifdef DEBUG
		DEBUG_SERIAL.println("RUNNING RF INIT()");
	#endif
	//! Sets up the rf network and sends the start command
	_init_rf_network();

	/**
	 * Once the state machine gets here, it polls for data from the router
	 * and parses it into the structures.
	 */

	#ifdef DEBUG
		DEBUG_SERIAL.println("RUNNING USB LIVE");
	#endif
	
	while(1){
		
		//! We check the global error flag
		if(check_context())
			error();
		
		//! delay  the sending of the frame.
		delay(100);
		
		// Poll the serial line
		this->_packet_handler->poll();
		
		//! Create a valid USB Frame
		void* report = _create_usb_report_frame();
		
		//Poll the serial line
		this->_packet_handler->poll();
		
		//! Send the valid report.
		_send_usb_report_frame(&report);
		
		//Poll the serial line
		this->_packet_handler->poll();
		
	}
}
