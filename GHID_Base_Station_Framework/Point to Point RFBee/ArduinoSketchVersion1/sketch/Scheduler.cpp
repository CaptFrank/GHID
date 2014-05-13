/* 
* Scheduler.cpp
*
* Created: 1/25/2014 12:58:39 AM
* Author: francis-ccs
*/

#include "Scheduler.h"


// default constructor
SCHEDULER::SCHEDULER(SENSOR* sensors, COMMAND_PARSER* command_int, 
	PACKET_HANDLER* handler){
	
	this->state = INIT_STATE;
	this->uuid = random(255);
	this->sensors = sensors;
	this->command_int = command_int;
	this->handler = handler;

	
} //Scheduler

// This initializes the communication between the
// sensor and the base station.
void SCHEDULER::_init_scheduler(){
	
	// Define the container for commands
	byte command[1];
	
	// Unknown entry point
	if(this->state != INIT_STATE)
		this->command_int->error();

	// Move the state
	this->state = COMS_INIT_STATE;
	
	// Do a network map
	this->command_int->get_nmap(this->sensors);
	
	// Sets priorities...
	this->sort_priority();
	
	// loop through the states...
	// Loop through each thread... Each sensor has its own 
	// processing thread.
	for(register byte i = 0; i < MAX_SENSORS; i++){
		
		if(sensors[i].get_state() == OK_SENSOR_STATE){
			sensors[i].set_state(IDLE_SENSOR_STATE);
			
			// Create a command interpreter
			this->command_int->set_sensor(&this->sensors[i]);
		
			// Confirm the sensor id
			command[0] = REQUEST_NUMBER;
			this->command_int->send_command(command);
			
			// Tx ACK
			command[0] = PING;
			this->command_int->send_command(command);
			
			// Tx CONFIGS
			command[0] = CONFIG_REQ;
			this->command_int->send_command(command);
			
			// Tx STATUS
			command[0] = STATUS_REQ;
			this->command_int->send_command(command);
			
			// Tx SYNC
			command[0] = SYNC;
			this->command_int->send_command(command);
			
			// Tx PAUSE
			command[0] = PAUSE;
			this->command_int->send_command(command);
			
			// Sensor is now at PAUSE.
			sensors[i].set_state(PAUSE_SENSOR_STATE);
		}
			
	} // All enabled sensors should now be paused.
	
	// Unknown corruption
	if(this->state != COMS_INIT_STATE)
		this->command_int->error();
	else
		this->state = IDLE_STATE;
	
}

void SCHEDULER::_start_scheduler(){
	
	// Define command container
	byte command[1];
	
	// Unknown entry point
	if(this->state != IDLE_STATE)
		this->error();
		
	// Move the state to start
	this->state = START_STATE;
	
		// loop through the states...
		// Loop through each thread... Each sensor has its own
		// processing thread.
		for(register byte i = 0; i < MAX_SENSORS; i++){
			
			if(sensors[i].get_state() == PAUSE_SENSOR_STATE || sensors[i].get_state() == IDLE_SENSOR_STATE){
				
				// Create a command interpreter
				this->command_int->set_sensor(&this->sensors[i]);
				
				// Start the data stream.
				command[0] = START;
				this->command_int->send_command(command);
				
				// Set the state
				this->sensors[i].set_state(RUN_SENSOR_STATE);
			}
			
		} // All enabled sensors show now be synced to both the
		  // heartbeat and the sync times... (heartbeat vs. data)
		  // We should be receiving data offset from the heart beat.
}

void SCHEDULER::_stop_scheduler(){
	
		// Define command container
		byte command[1];
		
		// Unknown entry point
		if(this->state != START_STATE)
			this->command_int->error();
		
		// Move the state to stop
		this->state = STOP_STATE;
		
		// loop through the states...
		// Loop through each thread... Each sensor has its own
		// processing thread.
		for(register byte i = 0; i < MAX_SENSORS; i++){
			
			if(sensors[i].get_state() == RUN_SENSOR_STATE){
				
				// Create a command interpreter
				this->command_int->set_sensor(&this->sensors[i]);
				
				// Start the data stream.
				command[0] = STOP;
				this->command_int->send_command(command);
				
				// Set the state
				this->sensors[i].set_state(IDLE_SENSOR_STATE);
			}
			
		} // All sensors now should be stopped and in the IDLE state.
}

void SCHEDULER::_error_scheduler(){
	
	// There is an error in the scheduler and it must restart
	this->state = ERROR_STATE;
	_stop_scheduler();
	_reset_scheduler();
	
	this->command_int->error();
}

void SCHEDULER::_reset_scheduler(){
	
	// Define a command container
	byte command[1];
	
	// We send out a reset message
	// Move the state to start
	this->state = RESET_STATE;
			
	// loop through the states...
	// Loop through each thread... Each sensor has its own
	// processing thread.
	for(register byte i = 0; i < MAX_SENSORS; i++){
				
		if(sensors[i].get_state() != REBOOT_SENSOR_STATE || sensors[i].get_state() != ERROR_SENSOR_STATE){
					
			// Create a command interpreter
			this->command_int->set_sensor(&this->sensors[i]);
					
			// Start the data stream.
			command[0] = ABORT;
			this->command_int->send_command(command);
					
			// Set the state
			this->sensors[i].set_state(BOOT_SENSOR_STATE);
		}
		
	} // All sensors now should be stopped and in the IDLE state.
	
	// We go back to the init scheduler
	_init_scheduler();
}

// This checks the status of the scheduler
boolean SCHEDULER::_check_scheduler_state(){
	
	if((this->state == RESET_STATE) || (this->state == ERROR_STATE))
		return false;
		
	return true;
}

// Entry point of the schduler
void SCHEDULER::run_scheduler(){
	
	// runs the scheduler routines.	
	_init_scheduler();
	_start_scheduler();
}

// sorts the sensro priorities
void SCHEDULER::sort_priority(){
	
	// Bubble sort
	SENSOR temp;
	
	for(register byte i = 0; i < MAX_SENSORS - 1; i++){
		for(register byte j = 0; j < MAX_SENSORS - i - 1; j++){
				
			if(this->sensors[j].priority > this->sensors[j + 1].priority){
				
				temp = this->sensors[j];
				this->sensors[j] = this->sensors[j + 1];
				this->sensors[j + 1] = temp;
			}	
		}
	}
}