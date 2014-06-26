/*
             LUFA Library
     Copyright (C) Dean Camera, 2013.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2013  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaims all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *
 *  Header file for Descriptors.c.
 */

#ifndef _DESCRIPTORS_H_
#define _DESCRIPTORS_H_

	/* Includes: */
		#include <avr/pgmspace.h>

		#include <LUFA/Drivers/USB/USB.h>
	
	/* Custom DEscriptor */
	#define DESCRIPTOR_PART_1 \
		HID_RI_USAGE_PAGE(8, 0x01),                     \
		HID_RI_USAGE(8, 0x04),                          \
		HID_RI_COLLECTION(8, 0x01),                     \
			HID_RI_USAGE(8, 0x01),                      \
			HID_RI_COLLECTION(8, 0x00)                
			
	#define DESCRIPTOR_PART_2(MinAxisVal, MaxAxisVal, MinPhysicalVal, MaxPhysicalVal) \
				HID_RI_LOGICAL_MINIMUM(16, MinAxisVal), \
				HID_RI_LOGICAL_MAXIMUM(16, MaxAxisVal), \
				HID_RI_PHYSICAL_MINIMUM(16, MinPhysicalVal), \
				HID_RI_PHYSICAL_MAXIMUM(16, MaxPhysicalVal), \
				HID_RI_REPORT_COUNT(8, 3),              \
				HID_RI_REPORT_SIZE(8, (((MinAxisVal >= -128) && (MaxAxisVal <= 127)) ? 8 : 16)), \
				HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE), \
			HID_RI_END_COLLECTION(0),                   \
			HID_RI_USAGE_PAGE(8, 0x09),                 \
			HID_RI_USAGE_MINIMUM(8, 0x01)
			
			
	#define DESCRIPTOR_PART_3 \
			HID_RI_USAGE_MAXIMUM(8, 0x00),           \
			HID_RI_LOGICAL_MINIMUM(8, 0x00),            \
			HID_RI_LOGICAL_MAXIMUM(8, 0x01),            \
			HID_RI_REPORT_SIZE(8, 0x01),                \
			HID_RI_REPORT_COUNT(8, 0x00),            \
			HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE), \
			HID_RI_REPORT_SIZE(8, 0x00), \
			HID_RI_REPORT_COUNT(8, 0x01),               \
			HID_RI_INPUT(8, HID_IOF_CONSTANT),          \
		HID_RI_END_COLLECTION(0)
		
	
	/* Dynamic sizes */
		uint8_t numButtons = 0;
		uint8_t numAxes = 0;
		
	/* Dynamic Report */
		USB_Descriptor_HIDReport_Datatype_t JoystickReport[];
		
	/* Dynamic Template */
		struct {
			
			//! Header
			const uint8_t* _desc_1;
			
			//! Axes pointer
			uint8_t* _axes;
			
			//! Physical limits
			const uint8_t* _desc_2;
			
			// Buttons
			const uint8_t* _buttons;
			
		} descriptor = {DESCRIPTOR_PART_1, 0x00, DESCRIPTOR_PART_2, DESCRIPTOR_PART_3};

	/* Type Defines: */
		/** Type define for the device configuration descriptor structure. This must be defined in the
		 *  application code, as the configuration descriptor contains several sub-descriptors which
		 *  vary between devices, and which describe the device's usage to the host.
		 */
		typedef struct
		{
			USB_Descriptor_Configuration_Header_t Config;

			// Joystick HID Interface
			USB_Descriptor_Interface_t            HID_Interface;
			USB_HID_Descriptor_HID_t              HID_JoystickHID;
	        USB_Descriptor_Endpoint_t             HID_ReportINEndpoint;
		} USB_Descriptor_Configuration_t;

		/** Enum for the device string descriptor IDs within the device. Each string descriptor should
		 *  have a unique ID index associated with it, which can be used to refer to the string from
		 *  other descriptors.
		 */
		enum StringDescriptors_t
		{
		    STRING_ID_Language      = 0, /**< Supported Languages string descriptor ID (must be zero) */
		    STRING_ID_Manufacturer  = 1, /**< Manufacturer string ID */
		    STRING_ID_Product       = 2, /**< Product string ID */
		};

	/* Macros: */
		/** Endpoint address of the Joystick HID reporting IN endpoint. */
		#define JOYSTICK_EPADDR              (ENDPOINT_DIR_IN | 1)

		/** Size in bytes of the Joystick HID reporting IN endpoint. */
		#define JOYSTICK_EPSIZE              8

	/* Function Prototypes: */
		uint16_t CALLBACK_USB_GetDescriptor(const uint16_t wValue,
		                                    const uint8_t wIndex,
		                                    const void** const DescriptorAddress)
		                                    ATTR_WARN_UNUSED_RESULT ATTR_NON_NULL_PTR_ARG(3);

#endif

