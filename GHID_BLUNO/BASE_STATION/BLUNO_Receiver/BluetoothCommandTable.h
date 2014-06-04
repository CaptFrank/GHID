/*
 * BluetoothCommandTable.h
 *
 *  Created on: 2014-05-14
 *      Author: francispapineau
 */

#ifndef BLUETOOTHCOMMANDTABLE_H_
#define BLUETOOTHCOMMANDTABLE_H_

#include <avr/pgmspace.h>
#include "BluetoothCommands.h"

/**
 * EEPROM String Pointer Table
 */
PROGMEM const char *command_pointers[] = {

		//! GENERIC
		string_input,
		help,
		reset_cmd,
		restore_cmd,
		poll_address_cmd,
		cancel_nmap_cmd,
		pair_cmd,
		link_cmd,
		disconnect_cmd,
		energy_save_en_cmd,
		energy_save_ex_cmd,
		name_cmd,
		remote_name_cmd,
		role_cmd,
		role_slave,
		role_master,
		role_slave_loop,
		type,
		type_default,
		access_code_cmd,
		access_code_default,
		inquiry_mode_cmd,
		password_cmd,
		serial_cmd,
		connection_mode_cmd,
		connection_mode_specific,
		connection_mode_non_specific,
		binding_address_cmd,
		led_polarity_cmd,
		led_polarity_default,
		pio_cmd,
		mpio_cmd,
		inquiry_cmd,
		sniff_cmd,
		encrypt_cmd,
		delete_device_cmd,
		delete_all_cmd,
		netmap_len_cmd,
		most_used_cmd,
		device_state_cmd,
		init_cmd,
		netmap_cmd
		
};
#endif /* BLUETOOTHCOMMANDTABLE_H_ */
