/*
 * BluetoothCommandIndexes.h
 *
 * Created: 5/20/2014 8:22:29 PM
 *  Author: Administrator
 */ 


#ifndef BLUETOOTHCOMMANDINDEXES_H_
#define BLUETOOTHCOMMANDINDEXES_H_

/**
 * The following are the indexes for the strings within the command string table.
 */

//! DEFAULT
#define STRING_INPUT										0
#define HELP												1
#define RESET_CMD											2
#define RESTORE_CMD											3

//! CONNECTION
#define POLL_ADDRESS										4
#define CANCEL_NMAP											5
#define PAIR												6
#define LINK												7
#define DISCONNECT											8

//! ENERGY SAVE
#define ENERGY_SAVE_ENTER									9
#define ENERGY_SAVE_EXIT									10

//! NAMES
#define NAME												11
#define REMOTE_NAME											12

//! DEVICE ROLE
#define ROLE												13
#define ROLE_SLAVE											14
#define ROLE_MASTER											15
#define ROLE_SLAVE_LOOP										16

//! DEVICE TYPE
#define TYPE												17
#define TYPE_DEFAULT										18

//! ACCESS CODE
#define ACCESS_CODE											19
#define ACCESS_CODE_DEFAULT									20

//! INQUIRY
#define INQUIRY_MODE										21

//! PASSWORD
#define PASSWORD_CMD										22

//! SERIAL SETTINGS
#define SERIAL_SETTINGS										23

//! CONNECTION MODE
#define CONNECTION_MODE										24
#define CONNECTION_MODE_SPECIFIC							25
#define CONNECTION_MODE_NON_SPECIFIC						26

//! BINDING ADDRESS
#define BINDING_ADDRESS										27

//! GPIO
#define LED_POLARITY										28
#define LED_POLARITY_DEFAULT								29
#define PIO													30
#define MPIO												31

//! INQUIRY
#define INQUIRY												32
#define SNIFF												33
#define ENCRYPT												34

//! NMAP SETTINGS
#define DELETE_DEVICE										33
#define DELETE_ALL											34
#define NETMAP_LEN											35
#define MOST_USED											36

//! GENERAL STATUS
#define DEVICE_STATE										37
#define INIT												38
#define NETMAP												39

/**
 * The following are some states that the bluetooth device might enter at runtime.
 */
#define SOFTWARE_VERSION					"1.0-20090818"

#define INIT								"INITIALIZED"
#define READY								"READY"
#define PAIRABLE 							"PAIRABLE"
#define PAIRED 								"PAIRD"
#define NMAP 								"INQUIRING"
#define CONNECTING 							"CONNECTING"
#define CONNECTED 							"CONNECTED"
#define DISCONNECTED 						"DISCONNECTED"
#define UNKNOWN 							"NUKNOW"

#endif /* BLUETOOTHCOMMANDINDEXES_H_ */
