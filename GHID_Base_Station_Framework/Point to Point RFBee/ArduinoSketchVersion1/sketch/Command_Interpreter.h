/*
 * Command_Interpreter.h
 *
 *  Created on: Jul 25, 2013
 *      Author: francispapineau
 */

#ifndef COMMAND_INTERPRETER_h_
#define COMMAND_INTERPRETER_h_

#include "Hardware_Defines.h"
#include "NVRAM_API.h"
#include "Sensor.h"
#include "Main_Defines.h"

#include "Network_Protocol.h"
#include "Packet_Handler.h"
#include "User_Configs.h"

#define PACKET_TIMEOUT_WATCH		10000 //! 10

/**
 * This class handles commands sent from the sensor nodes to the
 * base station, and executes them.
 * We can also send commands through this class.
 */
class COMMAND_PARSER : public main_defines{

	private:

		//! The command buffer to send.
		uint8_t* command_buffer;

		//! Our packet decoder pointer
		PACKET_HANDLER* packet_decoder;
		
		//! Our reference to a sensor object.
		SENSOR* sensor;

		/**
		 * Constructs a command
		 *
		 * @param command - byte
		 */
		void _send_command(uint8_t* command);

		/**
		 * Sends a command from the local board
		 *
		 * @param packet_id - byte
		 * @param packet_ver - byte
		 * @param buf - void*
		 */
		void _send_cmd(uint8_t packet_id, void *buf);

		/**
		 * Sends and checks for a response.
		 *
		 * @param packet_id - byte
		 * @param command - byte*
		 * @param len - int
		 */
		void _send_check(uint8_t receive_packet_id, uint8_t* command, int len);
		
		/**
		 * Pings all sensors on the network to see if they exist.
		 */
		void _get_nmap(SENSOR* sensor_db);

	public:

		//! Our command database loaded in cache.
		NVRAM* nvram_object;

		/**
		 * Default constructor.
		 *
		 * @param nvram_object
		 */
		COMMAND_PARSER(NVRAM* nvram_object, PACKET_HANDLER* packet_decoder);

		/**
		 * Sends a command via the public domain.
		 *
		 * @param buf - void*
		 */
		void send_cmd(uint8_t packet_id, void *buf);
		
		/**
		 * This method sets teh sensor pointer for access.
		 */
		void set_sensor(SENSOR* sensor);
		
		/**
		 * Send command override on the public side
		 */
		void send_command(uint8_t* command);
		
	    /**
		 * Get nmap override for public
		 */
		void get_nmap(SENSOR* sensor_db);
};

#endif
