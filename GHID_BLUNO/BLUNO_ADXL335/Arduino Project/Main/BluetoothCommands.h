/*
 * BluetoothCommands.h
 *
 *  Created on: 2014-05-13
 *      Author: francispapineau
 */

#ifndef BLUETOOTHCOMMANDS_H_
#define BLUETOOTHCOMMANDS_H_

#include <avr/pgmspace.h>

/**
 * The following list of strings are the possible commands that the BTLE chip
 * in this case the TI CC2540 BT 4.0 chip can parse and interpret.
 *
 * We use these commands via the serial connection to the bluetooth device
 * to configure it and load appropriate settings.
 */

/**
 * These are the mode change commands that the CC2540 understands (FSM)
 */
//
prog_char fsm_mode_change[] 				PROGMEM = "AT+FSM=";
prog_char fsm_mode_transparent[] 			PROGMEM = "FSM_TRANS_USB_COM_BLE\r\n";
prog_char fsm_mode_HID[]		 			PROGMEM = "FSM_HID_USB_COM_BLE_AT\r\n";

/**
 * These are the role change commands that the CC2540 understands (ROLE)
 */
//
prog_char role_mode_change[] 				PROGMEM = "AT+ROLE=";
prog_char role_mode_central[]				PROGMEM = "ROLE_CENTRAL\r\n";
prog_char role_mode_peripheral[]			PROGMEM = "ROLE_PERIPHERAL\r\n";

/**
 * Sets the min connection interval
 */
//
prog_char con_min_interval_change[]			PROGMEM = "AT+MIN_INTERVAL=";
prog_char con_min_interval_ten[]			PROGMEM = "10";
prog_char con_min_interval_twenty[]			PROGMEM = "20";

/**
 * Sets the max connection interval
 */
//
prog_char con_max_interval_change[]			PROGMEM = "AT+MAX_INTERVAL=";
prog_char con_max_interval_ten[]			PROGMEM = "10";
prog_char con_max_interval_forty[]			PROGMEM = "40";

/**
 * Sets the baud rate of the bluetooth transceiver.
 */
//
prog_char con_baudrate_change[]				PROGMEM = "AT+UART=";

/**
 * Sets the binding address to the BLE
 */
//
prog_char binding_address_change[]			PROGMEM = "AT+BIND=";

/**
 * Sets the binding scheme for the BLE chip
 */
//
prog_char connection_mode_change[]			PROGMEM = "AT+CMODE=";
prog_char connection_mode_unique[]			PROGMEM = "UNIQUE\r\n";
prog_char connection_mode_anyone[]			PROGMEM = "ANYONE\r\n";

/**
 * Get the MAC address of the chip
 */
prog_char get_mac_address[]					PROGMEM = "AT+MAC=?\r\n";

/**
 * Set the device name
 */
//
prog_char set_device_name[]					PROGMEM = "AT+NAME=";

/**
 * Restarts the BLE chip process
 */
prog_char reboot_ble[]						PROGMEM = "AT+RESTART\r\n";

/**
 * Change the default operation of the BLE chip.
 */
prog_char setting_change[]					PROGMEM = "AT+SETTING=";
prog_char setting_default[]					PROGMEM	= "DEFAULT\r\n";
prog_char setting_peripheral[]				PROGMEM = "DEFPERIPHERAL\r\n";
prog_char setting_central[]					PROGMEM = "DEFCENTRAL\r\n";

/**
 * Turn on the IBeacon capability
 */
//
prog_char ibeacon_change[]					PROGMEM = "AT+IBEACONS=";
prog_char ibeacon_on[]						PROGMEM = "ON\r\n";
prog_char ibeacon_off[]						PROGMEM = "OFF\r\n";

/**
 * Get the version of the firmware.
 */
prog_char get_firmware_ver[]				PROGMEM = "AT+VERSION=?\r\n";

/**
 * Get the RSSI value for the transceiver
 */
prog_char get_RSSI_value[]					PROGMEM = "AT+RSSI=?\r\n";

/**
 * Set the Major value of the IBeacon (0-65535)
 */
//
prog_char ibeacon_major_num_change[]		PROGMEM = "AT+MAJOR=";

/**
 * Set the Minor value of the IBeacon (0-65535)
 */
//
prog_char ibeacon_minor_num_change[]		PROGMEM = "AT+MINOR=";

/**
 * Set the password of the BLE chip
 */
prog_char password_change[]					PROGMEM = "AT+PASSWOR=";

/**
 * Set the TX power for the transceiver
 */
prog_char set_tx_power[]					PROGMEM = "AT+TXPOWER=";

/**
 * Generic Help command
 */
prog_char help[]		 					PROGMEM = "?\r\n";

/**
 * Generic Enter AT Mode command
 */
prog_char at_mode[]							PROGMEM = "+++";

/**
 * Generic String formatter.
 */
prog_char string_input[]					PROGMEM = "%s\r\n";

#endif /* BLUETOOTHCOMMANDS_H_ */
