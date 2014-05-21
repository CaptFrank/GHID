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
		at_mode,
		help,
		string_input,

		//! FSM MODE
		fsm_mode_change,
		fsm_mode_transparent,
		fsm_mode_HID,

		//! ROLE CHANGE
		role_mode_change,
		role_mode_central,
		role_mode_peripheral,

		//! MIN CON INTERVAL
		con_min_interval_change,
		con_min_interval_ten,
		con_min_interval_twenty,

		//! MAX CON INTERVAL
		con_max_interval_change,
		con_max_interval_ten,
		con_max_interval_forty,

		//! BAUDRATE
		con_baudrate_change,

		//! BINDING ADDRESS
		binding_address_change,

		//! CONNECTION MODE
		connection_mode_change,
		connection_mode_unique,
		connection_mode_anyone,

		//! GET MAC ADDRESS
		get_mac_address,

		//! DEVICE NAME
		set_device_name,

		//! REBOOT
		reboot_ble,

		//! SETTING CHANGE
		setting_change,
		setting_default,
		setting_peripheral,
		setting_central,

		//! IBEACON
		ibeacon_change,
		ibeacon_on,
		ibeacon_off,

		ibeacon_major_num_change,
		ibeacon_minor_num_change,

		//! TX POWER
		set_tx_power,

		//! RSSI
		get_RSSI_value,

		//! FW VERSION
		get_firmware_ver,

		//! PSW CHANGE
		password_change
};
#endif /* BLUETOOTHCOMMANDTABLE_H_ */
