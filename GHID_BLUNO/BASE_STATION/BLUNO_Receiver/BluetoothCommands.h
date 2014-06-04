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
 * The following list of strings are the possible commands that the BT chip
 * in this case the RF Bluetooth V3.0 chip can parse and interpret.
 *
 * We use these commands via the serial connection to the bluetooth device
 * to configure it and load appropriate settings.
 */

/**
 * Generic String formatter.
 */
prog_char string_input[]					PROGMEM = "%s\r\n";

/**
 * Generic Help command
 */
prog_char help[]		 					PROGMEM = "?\r\n";

/**
 * Reset command
 */
prog_char reset_cmd[]		 				PROGMEM = "AT+RESET\r\n";

/**
 * Restore to defaults command
 */
prog_char restore_cmd[]		 				PROGMEM = "AT+ORGL\r\n";

/**
 * Poll address command
 */
prog_char poll_address_cmd[]		 		PROGMEM = "AT+ADDR?\r\n";

/**
 * Cancel NMAP command
 */
prog_char cancel_nmap_cmd[]		 			PROGMEM = "INQC\r\n";

/**
 * Pair device command
 */
prog_char pair_cmd[]		 				PROGMEM = "AT+ADDR="; // we need mac and timeout

/**
 * Link device command
 */
prog_char link_cmd[]		 				PROGMEM = "AT+LINK="; // we need mac

/**
 * Disconnect device command
 */
prog_char disconnect_cmd[]		 			PROGMEM = "AT+DISC\r\n";

/**
 * Go into energy saving mode command
 */
prog_char energy_save_en_cmd[]		 		PROGMEM = "AT+ENSNIFF="; // we need mac

/**
 * Exit energy saving mode command
 */
prog_char energy_save_ex_cmd[]		 		PROGMEM = "AT+EXSNIFF="; // we need mac

/**
 * Device name commands
 */
prog_char name_cmd[]						PROGMEM = "AT+NAME=";

/**
 * Get remote device name command
 */
prog_char remote_name_cmd[]					PROGMEM = "AT+RNAME?\r\n";

/**
 * Set the device role command
 */
prog_char role_cmd[]						PROGMEM = "AT+ROLE=";
	prog_char role_slave[]					PROGMEM = "0";
	prog_char role_master[]					PROGMEM = "1";
	prog_char role_slave_loop[]				PROGMEM = "2";

/**
 * Set device type command
 */
prog_char type[]							PROGMEM = "AT+CLASS=";
	prog_char type_default[]				PROGMEM = "0";

/**
 * Device Access code command
 */
prog_char access_code_cmd[]					PROGMEM = "AT+IAC=";
	prog_char access_code_default[]			PROGMEM = "938b33";

/**
 * Device Inquiry mode command
 */
prog_char inquiry_mode_cmd[]				PROGMEM = "AT+IAC="; // need mode, response number, timeout

/**
 * Device paring password command
 */
prog_char password_cmd[]					PROGMEM = "AT+PSWD="; // need password

/**
 * Device serial port command
 */
prog_char serial_cmd[]						PROGMEM = "AT+UART="; // need baud, stop, parity

/**
 * Device connection mode command
 */
prog_char connection_mode_cmd[]				PROGMEM = "AT+CMODE="; // need baud, stop, parity
	prog_char connection_mode_specific		PROGMEM = "0";
	prog_char connection_mode_non_specific	PROGMEM = "2";

/**
 * Device binding command
 */
prog_char binding_address_cmd[]				PROGMEM = "AT+BIND="; // need mac

/**
 * Device led polarity command
 */
prog_char led_polarity_cmd[]				PROGMEM = "AT+POLAR="; // polarity for port 8 and 9
	prog_char led_polarity_default[]		PROGMEM = "AT+DEFAULT\r\n";

/**
 * Device GPIO command
 */
prog_char pio_cmd[]							PROGMEM = "AT+PIO="; // need port and output
prog_char mpio_cmd[]						PROGMEM = "AT+MPIO="; // need port mask

/**
 * Device inquiry parameters command
 */
prog_char inquiry_cmd[]						PROGMEM = "AT+IPSCAN="; // need inquiry time interval, poll time, call time interval, call time

/**
 * Device power saving mode command
 */
prog_char sniff_cmd[]						PROGMEM = "AT+SNIFF="; // need max time, min time, try time, timeout

/**
 * Device encryption command
 */
prog_char encrypt_cmd[]						PROGMEM = "AT+SENM="; // security level and encryption

/**
 * Delete device in network table command
 */
prog_char delete_device_cmd[]				PROGMEM = "AT+RMSAD="; // need mac
prog_char delete_all_cmd[]					PROGMEM = "AT+RMSAD\r\n";


/**
 * Network table Command
 */
prog_char netmap_len_cmd[]					PROGMEM = "AT+ADCN?\r\n";

/**
 * Get most used command
 */
prog_char most_used_cmd[]					PROGMEM = "AT+MRAD?\r\n";

/**
 * Get device state command
 */
prog_char device_state_cmd[]				PROGMEM = "AT+STATE?\r\n";


/**
 * Init device command
 */
prog_char init_cmd[]						PROGMEM = "AT+INIT\r\n";

/**
 * Create Network map command
 */
prog_char netmap_cmd[]						PROGMEM = "AT+INQ\r\n";

#endif /* BLUETOOTHCOMMANDS_H_ */
