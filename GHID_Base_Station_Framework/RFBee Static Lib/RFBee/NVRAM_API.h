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
		 * The structure for the nvram variables.
		 */
		struct nv_data_t {

			//! Serial settings
			word serial1_speed;
			word serial2_speed;
			word serial3_speed;

			//! RF settings
			uint8_t node_address;
			uint8_t device_mode;

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

			//! RFBee settings
			uint8_t address_check_mode;
			uint8_t host_address;
			uint8_t broadcast_address;
			uint8_t transmit_power;
			uint8_t baud_rate;
			uint8_t working_mode;
			uint8_t threashold;
			uint8_t datarate;

			//! Possible RFBEE Commands;
			char AT	 [4];
			
			char ATAC[6];
			char ATMA[6];
			char ATDA[6];
			char ATPA[6];
			char ATBD[6];
			char ATMD[6];
			char ATTH[6];
			char ATDR[6];
			
			char ATRS[5];
			char ATFV[5];
			char ATHV[5];

		}__attribute__((__packed__));

		//! The exported structure definition.
		struct nv_data_t nv;
};

#endif
