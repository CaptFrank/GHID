/*
 * GHIDSystemAbstration.h
 *
 *  Created on: 2014-02-06
 *      Author: francispapineau
 */

#ifndef GHIDSYSTEMABSTRATION_H_
#define GHIDSYSTEMABSTRATION_H_

#include <Arduino.h>
#include "avr/interrupt.h"

#include "TimerOne.h"
#include "TimerThree.h"

/**
 * Only one of these can be defined at once. These define
 * the USB frame that is sent. Either:
 * 	- Joystick Report
 * 	- Mouse Report
 */
#define JOYSTICK_REPORT
//#define MOUSE_REPORT

#include "GHID_USB_Structures.h"

/**
 * This class is a grouping of both the TimerOne class, which provides
 * the Timer1 timing ability, and also the TimerThree class which supports
 * the Timer3 on the Arduino Mega. It also provides the interface
 * to the USB communication between the system and the Computer.
 *
 * @see TimerOne.h
 * @see TimerThree.h
 */
class GHID_System_Abstration{

	//! Public Context
	public:

	/**
	 * This defines the usb frame
	 */
	#ifdef JOYSTICK_REPORT
	joystick_report_t joystick_report;

	#elif MOUSE_REPORT
	mouse_report_t mouse_report;

	#endif

	/**
	 * This method is the private access analog reference setup routine for the
	 * analog sensor bus. It only really needs to be accessed once.
	 */
	void setup_analog_reference(byte reference);

	/**
	 * This method sets up the interface to the USB PHY.
	 */
	void setup_USB_interface();

	/**
	 * This sends out a USB frame to the computer.
	 */
	void send_USB_frame();

	/**
	 * This class extends the TimerOne class, and gives access to the class
	 * contents in this subclass.
	 *
	 * @see TimerOne.h
	 */
	class GHID_Timer_One : public TimerOne {};

	/**
	 * This class extends the TimerThree class, and gives access to the class
	 * contents in this subclass.
	 *
	 * @see TimerThree.h
	 */
	class GHID_Timer_Three : public TimerThree {};
};

#endif /* GHIDSYSTEMABSTRATION_H_ */
