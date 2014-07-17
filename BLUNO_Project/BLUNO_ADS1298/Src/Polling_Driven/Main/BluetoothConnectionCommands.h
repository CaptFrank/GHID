/*
 * BluetoothConnectionCommands.h
 *
 *  Created on: 2014-05-16
 *      Author: francispapineau
 */

#ifndef BLUETOOTHCONNECTIONCOMMANDS_H_
#define BLUETOOTHCONNECTIONCOMMANDS_H_

/**
 * These are the possible commands that can be received by the sensor node.
 */

//! Generic commands
#define REBOOT							0x01
#define RESET							0x02
#define SUSPEND							0x03
#define RESUME							0x04
#define START							0x05
#define STOP							0x06

//! Get command
#define GET								0x10

//! Not command issued
#define COMMAND_NULL					0xFF

#endif /* BLUETOOTHCONNECTIONCOMMANDS_H_ */
