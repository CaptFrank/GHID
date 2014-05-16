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

//! GENERIC
#define AT_MODE									0
#define HELP									1
#define STRING_INPUT							2

//! FSM MODE
#define FSM_MODE_CHANGE							3
#define FSM_MODE_TRANSPARENT					4
#define FMS_MODE_HID							5

//! ROLE CHANGE
#define ROLE_CHANGE								6
#define ROLE_CENTRAL							7
#define ROLE_PERIPHERAL							8

//! MIN CON INTERVAL
#define MIN_CON_INTERVAL_CHANGE					9
#define MIN_CON_TEN								10
#define MIN_CON_TWENTY							11

//! MAX CON INTERVAL
#define MAX_CON_INTERVAL_CHANGE					12
#define MAS_CON_TEN								13
#define MAX_CON_FORTY							14

//! BAUDRATE
#define BAUDRATE_CHANGE							15

//! BINDING ADDRESS
#define BINDING_ADDRESS_CHANGE					16

//! CONNECTION MODE
#define CONNECTION_MODE_CHANGE					17
#define CONNECTION_MODE_UNIQUE					18
#define CONNECTION_MODE_ANY						19

//! GET MAC ADDRESS
#define GET_MAC_ADDRESS							20

//! DEVICE NAME
#define SET_DEVICE_NAME							21

//! REBOOT
#define REBOOT									22

//! SETTING CHANGE
#define SETTING_CHANGE							23
#define SETTING_DEFAULT							24
#define SETTING_PERIPHERAL						25
#define SETTING_CENTRAL							26

//! IBEACON SETTINGS
#define IBEACON_SETTING_CHANGE					27
#define IBEACON_ON								28
#define IBEACON_OFF								29
#define IBEACON_MAJOR_NUM						30
#define IBEACON_MINOR_NUM						31

//! TX POWER
#define TX_POWER_SETTING						32

//! RSSI VALUE
#define GET_RSSI_VALUE							33

//! FW VERSION
#define GET_FW_VERSION							34

//! PSW CHANGE
#define PSW_CHANGE								35

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
