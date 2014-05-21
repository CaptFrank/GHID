/*
 * GHID_Project.h
 *
 *  Created on: 2014-02-10
 *      Author: francispapineau
 */

#ifndef GHID_PROJECT_H_
#define GHID_PROJECT_H_

//! To run the USB Interface
#ifdef GHID_USB
#include "GHID_System_Abstration.h"
#include "GHID_USB_Structures.h"
#endif

//! For configuration
#ifdef GHID_ANALOG_PORT
#include "GHID_Analog_Port.h"
#endif

#ifdef GHID_DIGITAL_PORT
#include "GHID_Digital_Port.h"
#endif

#ifdef GHID_EEPROM
#include "GHID_EEPROM.h"
#endif

#ifdef GHID_UART
#include "GHID_UART.h"
#endif

#ifdef GHID_I2C
#include "GHID_I2C.h"
#endif

#ifdef GHID_SPI
#include "GHID_SPI.h"
#endif

#ifdef GHID_1_WIRE
#include "GHID_Dallas_1_Wire.h"
#endif

#endif /* GHID_PROJECT_H_ */
