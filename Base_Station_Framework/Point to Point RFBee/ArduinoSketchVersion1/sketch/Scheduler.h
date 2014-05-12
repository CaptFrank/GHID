/* 
* Scheduler.h
*
* Created: 1/25/2014 12:58:39 AM
* Author: francis-ccs
*/

#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include "Packet_Handler.h"
#include "Command_Interpreter.h"
#include "Packet_Watchdog.h"

class SCHEDULER : public main_defines{

public:

	// Creating an enum for the state machine
	enum scheduler_state_t {
		INIT_STATE, 
		COMS_INIT_STATE,
		IDLE_STATE, 
		START_STATE, 
		STOP_STATE, 
		RESET_STATE, 
		ERROR_STATE
		};
	
	// function pointers
	struct{
		void (*_init_scheduler)();
		void (*_start_scheduler)();
		void (*_stop_scheduler)();
		void (*_reset_scheduler)();
		void (*_error_scheduler)();
		}fcn_ptr;

	// Unique scheduler id
	byte uuid;
	
	// byte scheduler state
	scheduler_state_t state;
	
	// the device tp be accessed
	SENSOR* sensors;
	
	// the command parser address access
	COMMAND_PARSER* command_int;
	
	// The watchdog for polling
	WATCHDOG* watchdog;
	
	// the handler
	PACKET_HANDLER* handler;
	
	// The NVRAM object
	NVRAM* nvram;
	
	// The default constructor
	SCHEDULER(SENSOR* sensor, COMMAND_PARSER* command_int, PACKET_HANDLER* handler);
	
	// The entry point for the scheduler
	void run_scheduler();
	
	// The priority sorter
	void sort_priority();
	
	// Init the sensor communication
	void _init_scheduler();
	
	// This starts the scheduler engine
	void _start_scheduler();
	
	// This stops the scheduler engine
	void _stop_scheduler();
	
	// This resets the scheduler engine
	void _reset_scheduler();
	
	// This invokes the error state of the scheduler
	void _error_scheduler();
	
	// This checks the status of the scheduler
	boolean _check_scheduler_state();
	

}; //Scheduler

#endif //__SCHEDULER_H__
