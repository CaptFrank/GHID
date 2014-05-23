/*
 * BluetoothCommandIndexes.h
 *
 * Created: 5/20/2014 8:22:29 PM
 *  Author: Administrator
 */ 


#ifndef BLUETOOTHCOMMANDINDEXES_H_
#define BLUETOOTHCOMMANDINDEXES_H_

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

//! EXIT AT
#define EXIT_AT									36

#endif /* BLUETOOTHCOMMANDINDEXES_H_ */