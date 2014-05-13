/*
 * NVRAM_API.h
 *
 *  Created on: Jul 25, 2013
 *      Author: fjpapin
 */

#ifndef NVRAM_h_
#define NVRAM_h_

#include "Hardware_Defines.h"
#include "EEPROM.h"

/**
 * This class handles the NVRAM accesses and storage
 * structure.
 */
class NVRAM {

	private:

		/**
		 * Loads bytes from NVRAM
		 *
		 * @param address - byte
		 * @param size - byte
		 * @param value - void*
		 */
		void _loadx(uint8_t address, uint8_t size, void* value);

		/**
		 * Saves bytes to NVRAM
		 *
		 * @param address - byte
		 * @param size - byte
		 * @param value - void*
		 */
		void _savex(uint8_t address, uint8_t size, void* value);

	public:

		/**
		 * Load all of the saved variables.
		 */
		void load(void);

		/**
		 * Save all of the loaded variables.
		 */
		void save(void);

		/**
		 * Saves bytes to NVRAM
		 *
		 * @param address - byte
		 * @param size - byte
		 * @param value - void*
		 */
		void savex(uint8_t address, uint8_t size, void* value);

		/**
		 * The structure for the nvram varialbes.
		 */
		struct nv_data_t {

			//! Serial settings
			word serial1_speed;
			word serial2_speed;
			word serial3_speed;
			
			//! GPIO settings
			//!		buttons:
			uint8_t button_1;
			uint8_t button1_setting;
			uint8_t button_2;
			uint8_t button2_setting;

			//!		LEDs:
			uint8_t led_1;
			uint8_t led1_setting;
			uint8_t led_2;
			uint8_t led2_setting;
			uint8_t led_3;
			uint8_t led3_setting;
			uint8_t led_4;
			uint8_t led4_setting;
			
			uint8_t default_values;
			
// 			uint8_t device_name[10];
// 			uint8_t device_role;
// 			uint8_t device_type;
// 			uint8_t device_access_code[6];
// 			uint8_t pairing_password[4];
// 			
// 			struct {
// 				
// 				uint8_t inquiry_mode;
// 				uint8_t max_response;
// 				uint8_t timeout;
// 			}device_mode;
// 		
// 			struct{
// 				
// 				uint8_t baud[7];
// 				uint8_t stop_bit;
// 				uint8_t parity;
// 			}serial_port_params;
// 			
// 			
// 			uint8_t connection_mode;
// 			uint8_t binding_address[18];
// 			uint8_t sniff_params[7];
// 			uint8_t power_params[18];
// 			uint8_t security_mode[3];

		}__attribute__((__packed__));

		//! The exported structure definition.
		struct nv_data_t nv;
};

#endif
