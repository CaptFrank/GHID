/*
 * Sensor_Parser.h
 *
 *  Created on: Jul 13, 2013
 *      Author: francispapineau
 */

#ifndef SENSOR_PARSER_H_
#define SENSOR_PARSER_H_

#include "Network_Protocol.h"
#include "Packet_Handler.h"
#include "Main_Defines.h"
#include "Sensor.h"


#define MAX_TOKENS			40

/**
 * This class takes care of the packet parsing.
 */
class PACKET_PARSER : public main_defines{

	private:

		//! Packet handler
		PACKET_HANDLER* _packet_handler;
		
		//! Sensor db
		SENSOR* db;
		
		//! Old timestamp.
		uint32_t old_sensor_time_stamp;
		
		//! The buffer size
		uint8_t packet_size;

		/**
		 * Gets if a packet was read, and what type.
		 */
		bool _check_read_packet(byte packet_type);

		/**
		 * Gets the sensor data.
		 * @param buf - void*
		 */
		void _get_sensor_data();

		/**
		 * Gets the sensor configs based on the buf passed.
		 * @param buf - void*
		 */
		void _get_sensor_configs();

		/**
		 * Checks the packet header as any packet comes in.
		 */
		void _check_packet_header();

		/**
		 * Checks the ack signal and returns if true.
		 * If false, the router reloads as there might be an error.
		 */
		void _check_ack();

		/**
		 * Checks the heartbeat signals and sees if any error should be
		 * fired off.
		 */
		void _check_heartbeat();

		/**
		 * Checks the router status and sees if any errors should
		 * be fired off.
		 */
		void _check_sensor_status();
		
		/**
		 * This methods checks the sync report from the sensor addressed.
		 */
		void _check_sensor_sync();
		
		/**
		 * This method checks the sensor error report and reboots the
		 * remote node.
		 */
		void _check_sensor_error();

		/**
		 * Checks the memory space to see if we can allocate
		 * more structures.
		 */
		void _check_memory_space(size_t mem_space = MAX_MEMORY);

		/**
		 * Checks the packet integrity
		 *
		 * @param packet - String*
		 * @return bool
		 */
		bool _check_packet_integrity(char* packet);
		 
		/**
		 * Allocates the memory... saves mem
		 * @param dest_pointer - void*
		 * @param size - size_t
		 * @param buf - void *
		 */
		void _alloc_mem(void* dest_pointer, size_t size, void* buff);

		/**
		 * Parses a packet
		 *
		 * @param packet_id - byte
		 * @param packet_ver - byte
		 * @param buf - void*
		 */
		void _parse(byte packet_id, byte packet_ver, void *buf);

	public :

		/**
		 * Default constructor
		 */
		PACKET_PARSER(SENSOR* db);

		/**
		 * Publicly accessible parsing method.
		 *
		 * @param arg - void*
		 * @param packet_id - byte
		 * @param packet_ver - byte
		 * @param buf - void*
		 */
		static void parse(void *arg, byte packet_id, byte packet_ver, void *buf);

		/**
		 * Sets the packet handler object.
		 *
		 * @param packet_handler - handler object
		 */
		void set_handler (PACKET_HANDLER* packet_handler);

		//! The structures needed to parse info into.
		struct sensor_packet_header_t			_header;
		struct sensor_ack_info_t				_ack;
		struct sensor_heartbeat_t 				_heartbeat;
		struct sensor_status_report_t 			_status;
		struct sensor_error_t					_error;
		
		/**
		 * These will get reallocated to how many sensors there are in
		 * the sensor network.
		 */
		struct sensor_configs_t			 		_configs;
		struct sensor_sync_report_t				_sync;
		struct sensor_data_struct_t 			_data;
};

#endif /* SENSOR_PARSER_H_ */
