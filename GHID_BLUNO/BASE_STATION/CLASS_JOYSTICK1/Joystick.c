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
 *  Main source file for the Joystick demo. This file contains the main tasks of
 *  the demo and is responsible for the initial application hardware configuration.
 */

#include "Joystick.h"

/** Buffer to hold the previously generated HID report, for comparison purposes inside the HID class driver. */
static uint8_t PrevJoystickHIDReportBuffer[sizeof(USB_JoystickReport_Data_t)];

/** LUFA HID Class driver interface configuration and state information. This structure is
 *  passed to all HID Class driver functions, so that multiple instances of the same class
 *  within a device can be differentiated from one another.
 */
USB_ClassInfo_HID_Device_t Joystick_HID_Interface =
	{
		.Config =
			{
				.InterfaceNumber              = 0,
				.ReportINEndpoint             =
					{
						.Address              = JOYSTICK_EPADDR,
						.Size                 = JOYSTICK_EPSIZE,
						.Banks                = 1,
					},
				.PrevReportINBuffer           = PrevJoystickHIDReportBuffer,
				.PrevReportINBufferSize       = sizeof(PrevJoystickHIDReportBuffer),
			},
	};


/** LUFA CDC Class driver interface configuration and state information. This structure is
 *  passed to all CDC Class driver functions, so that multiple instances of the same class
 *  within a device can be differentiated from one another. This is for the first CDC interface,
 *  which sends strings to the host for each joystick movement.
 */
USB_ClassInfo_CDC_Device_t VirtualSerial_CDC_Interface =
	{
		.Config =
			{
				.ControlInterfaceNumber   = INTERFACE_ID_CDC_CCI,
				.DataINEndpoint           =
					{
						.Address          = CDC_TX_EPADDR,
						.Size             = CDC_TXRX_EPSIZE,
						.Banks            = 1,
					},
				.DataOUTEndpoint =
					{
						.Address          = CDC_RX_EPADDR,
						.Size             = CDC_TXRX_EPSIZE,
						.Banks            = 1,
					},
				.NotificationEndpoint =
					{
						.Address          = CDC_NOTIFICATION_EPADDR,
						.Size             = CDC_NOTIFICATION_EPSIZE,
						.Banks            = 1,
					},
			},
	};

/** Circular buffer to hold data from the serial port before it is sent to the host. */
RingBuff_t USARTtoUSB_Buffer;

//! A joystick report used to send to the host pc
USB_JoystickReport_Data_t joyReport;

/** Main program entry point. This routine contains the overall program flow, including initial
 *  setup of all components and the main program loop.
 */
int main(void)
{	
	
	//! Setup Hardware
	SetupHardware();
	
	//! Set LEDs to a known state
	LEDs_SetAllLEDs(LEDMASK_USB_NOTREADY);
	
	//! Init the buffer
    RingBuffer_InitBuffer(&USARTtoUSB_Buffer);

	//! Enable the interrupt globally
    sei();

    for (;;) {
		
		//! We check to see if there is a byte in the host -> client buffer
		int16_t rx_byte = CDC_Device_ReceiveByte(&VirtualSerial_CDC_Interface);
		
		//! If this is real data, 
		if(!(rx_byte < 0)){
			
			//! We send the byte to the ATMEGA328 uC
			Serial_SendByte(rx_byte);
		}
		
		//! CDC Device Serial Task
		CDC_Device_Serial_Task(&VirtualSerial_CDC_Interface);
		
		//! CDC Device USB Task
		CDC_Device_USBTask(&VirtualSerial_CDC_Interface);
		
		//! HID Device Task
	    HID_Device_USBTask(&Joystick_HID_Interface);
		
		//! USB Task
	    USB_USBTask();
	}
}

/** Configures the board hardware and chip peripherals for the demo's functionality. */
void SetupHardware(void)
{
    /* Disable watchdog if enabled by bootloader/fuses */
    MCUSR &= ~(1 << WDRF);
    wdt_disable();

    /* Hardware Initialization */
    Serial_Init(9600, true);
    LEDs_Init();
    USB_Init();

	//! Serial Port Default INIT
    UCSR1B = ((1 << RXCIE1) | (1 << TXEN1) | (1 << RXEN1));
}

/** Event handler for the library USB Connection event. */
void EVENT_USB_Device_Connect(void)
{
	LEDs_SetAllLEDs(LEDMASK_USB_ENUMERATING);
}

/** Event handler for the library USB Disconnection event. */
void EVENT_USB_Device_Disconnect(void)
{
	LEDs_SetAllLEDs(LEDMASK_USB_NOTREADY);
}

/** Event handler for the library USB Configuration Changed event. */
void EVENT_USB_Device_ConfigurationChanged(void)
{
	
	bool config_success = true;
	
	config_success &= CDC_Device_ConfigureEndpoints(&VirtualSerial_CDC_Interface);
	config_success &= HID_Device_ConfigureEndpoints(&Joystick_HID_Interface);
	
	USB_Device_EnableSOFEvents();
	
	LEDs_SetAllLEDs(config_success ? LEDMASK_USB_READY : LEDMASK_USB_ERROR);
}

/** Event handler for the library USB Control Request reception event. */
void EVENT_USB_Device_ControlRequest(void)
{
	CDC_Device_ProcessControlRequest(&VirtualSerial_CDC_Interface);
	HID_Device_ProcessControlRequest(&Joystick_HID_Interface);
}

/** Event handler for the USB device Start Of Frame event. */
void EVENT_USB_Device_StartOfFrame(void)
{
	HID_Device_MillisecondElapsed(&Joystick_HID_Interface);
}

/** HID class driver callback function for the creation of HID reports to the host.
 *
 *  \param[in]     HIDInterfaceInfo  Pointer to the HID class interface configuration structure being referenced
 *  \param[in,out] ReportID    Report ID requested by the host if non-zero, otherwise callback should set to the generated report ID
 *  \param[in]     ReportType  Type of the report to create, either HID_REPORT_ITEM_In or HID_REPORT_ITEM_Feature
 *  \param[out]    ReportData  Pointer to a buffer where the created report should be stored
 *  \param[out]    ReportSize  Number of bytes written in the report (or zero if no report is to be sent)
 *
 *  \return Boolean \c true to force the sending of the report, \c false to let the library determine if it needs to be sent
 */
bool CALLBACK_HID_Device_CreateHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
                                         uint8_t* const ReportID,
                                         const uint8_t ReportType,
                                         void* ReportData,
                                         uint16_t* const ReportSize)
{
	
	USB_JoystickReport_Data_t newReport;
	int ind;
	
    USB_JoystickReport_Data_t *reportp = (USB_JoystickReport_Data_t*)ReportData;
	
	//! We check to see if we need to send a string first...
	if(RINGBUFF_Check_Packet_Type(SERIAL_DATA_HEADER)){
		CDC_Device_Serial_Task(&VirtualSerial_CDC_Interface);
	}
	
	RingBuff_Count_t BufferCount = RingBuffer_GetCount(&USARTtoUSB_Buffer);

	if (BufferCount >= 8) {
		for (ind = 0; ind < sizeof(joyReport); ind ++) {
			((uint8_t *)&newReport)[ind] = RingBuffer_Remove(&USARTtoUSB_Buffer);
		}

		joyReport.Button = newReport.Button;
		joyReport.X = newReport.X;
		joyReport.Y = newReport.Y;
		joyReport.Z = newReport.Z;
				 
		/* Remove spacer */
		RingBuffer_Remove(&USARTtoUSB_Buffer);
	}
	

    *reportp = joyReport;

    *ReportSize = sizeof(USB_JoystickReport_Data_t);
    return false;
}

/** HID class driver callback function for the processing of HID reports from the host.
 *
 *  \param[in] HIDInterfaceInfo  Pointer to the HID class interface configuration structure being referenced
 *  \param[in] ReportID    Report ID of the received report from the host
 *  \param[in] ReportType  The type of report that the host has sent, either HID_REPORT_ITEM_Out or HID_REPORT_ITEM_Feature
 *  \param[in] ReportData  Pointer to a buffer where the received report has been stored
 *  \param[in] ReportSize  Size in bytes of the received HID report
 */
void CALLBACK_HID_Device_ProcessHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
                                          const uint8_t ReportID,
                                          const uint8_t ReportType,
                                          const void* ReportData,
                                          const uint16_t ReportSize)
{
	// Unused (but mandatory for the HID class driver) in this demo, since there are no Host->Device reports
}

//! Custom Task Engine
void CDC_Device_Serial_Task(USB_ClassInfo_CDC_Device_t* ptr){
	
	//! We check if there is a serial string that needs to be written
	//! The data format should be the following:
	//!		- HEADER 
	//!		- LENGTH
	//!		- DATA*
	if(RINGBUFF_Check_Packet_Type(SERIAL_DATA_HEADER)){
		
		//! Remove the header - no need to send it
		RingBuffer_Remove(&USARTtoUSB_Buffer);
		
		//! Remove the length of the data to send
		uint8_t length = RingBuffer_Remove(&USARTtoUSB_Buffer);
		
		//! We write the serial string
		for(register uint8_t i = 0; i < length; i ++){
			CDC_Device_SendByte(ptr, (uint8_t)RingBuffer_Remove(&USARTtoUSB_Buffer));
		}
	}
}

//! Custom check function
bool RINGBUFF_Check_Packet_Type(uint8_t type){
	
	if(USARTtoUSB_Buffer.Out[0] == type){
		return true;
	}
	return false;
}

/** ISR to manage the reception of data from the serial port, placing received bytes into a circular buffer
 *  for later transmission to the host.
 */
ISR(USART1_RX_vect, ISR_BLOCK)
{
    uint8_t ReceivedByte = UDR1;

    if ((USB_DeviceState == DEVICE_STATE_Configured)) {
		RingBuffer_Insert(&USARTtoUSB_Buffer, ReceivedByte);
    }
}