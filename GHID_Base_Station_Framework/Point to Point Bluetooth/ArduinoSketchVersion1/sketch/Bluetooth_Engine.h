/* 
* Bluetooth_Device.h
*
* Created: 2/19/2014 11:24:08 PM
* Author: francis-ccs
*/


#ifndef __BLUETOOTH_ENGINE_H__
#define __BLUETOOTH_ENGINE_H__

#include "Bluetooth_Handler.h"
#include "USB_Structures.h"
#include "Hardware_Defines.h"

//#include "BTD.h"
#include "Wii.h"

// Max buffer size
#define MAX_BUFFER_SIZE		255
#define HALF_X_BOARD_CM		22	//Round up for faster computation - 21.59
#define HALF_Y_BOARD_CM		12	//Round down for faster computation - 12.07		

#define BIT16				65535
#define BIT8				255

#define HID_RPT_PROTOCOL	0x01

/**
 * This class is the bluetooth engine for the USB device.
 * It handles the connection, data receive and processing of the 
 * Bluetooth HID from the Board.
 */
class BLUETOOTH_ENGINE{

	// Public context
	public:
	
	// Void pointer to report.
	void* report;
	
	// The structures definition.
	#ifdef JOYSTICK_REPORT
		joystick_report_t joystick_report;
	#endif
	#ifdef MOUSE_REPORT
		mouse_report_t mouse_report;
	#endif

// 	// The bluetooth SPP stack
// 	BTD btd(&RF_SERIAL);
// 	
// 	// The bluetooth HID handler
// 	WII wii_device(&btd, PAIR);

	// The pointer to the buffer returned from \
		the bluetooth stack.
	bluetooth_response_t* buffer;
	
	// This is a pointer to the structure created by the \
		user with the settings of the bluetooth device. \
		This constrtuct can be empty when using defaults.
	bluetooth_settings_t bt_settings;
	
	// This is the bluetooth stack entry pointer. \
		it provides a manager to the bluetooth stack.
	BLUETOOTH_HANDLER* handler;
	
	/**
     * \func BLUETOOTH_ENGINE
     * \brief This is the default constructor to this class.
     *
     * @param BLUETOOTH_HANDLER* handler
     */
	BLUETOOTH_ENGINE(BLUETOOTH_HANDLER* handler);
	
	/**
     * \func BLUETOOTH_ENGINE
     * \brief This is the default constructor to this class.
     *
     * @param BLUETOOTH_HANDLER* handler
	 * @param bluetooth_settings_t* settings
     */
	BLUETOOTH_ENGINE(BLUETOOTH_HANDLER* handler, 
						bluetooth_settings_t* settings);
	
	/**
     * \func set_btd_wii
     * \brief This sets the bluetooth stack and device
     *
     * @param BTD* the bluetooth stack
	 * @param WII* the wii stack
     */
	void set_btd_wii(BTD* btd, WII* wii);
	
	/**
     * \func setup_bluetooth_device
     * \brief This is the entry point to the class
     */
	void setup_bluetooth_device();
	
	/**
     * \func run
     * \brief This is the run thread method
     */
	void run();
	
	// This is the private context
	private:
	
	// Containers for the computed results
	uint16_t x_axis;
	uint16_t y_axis;
	
	// Data container [0] = x, [1] = y;
	byte data[2];
	
	// Pointers for device and stack
	BTD* btd;
	WII* wii_device;
		
	/**
     * \func _poll
     * \brief This function polls the serial bus for data.
	 * This returns true if we have a good packet and false if 
	 * the packet is not valid.
	 *
	 * @returns boolean
     */
	void _poll();
	
	/**
     * \func _process_rx_packet
     * \brief This is the processing method. It performs the
	 * interpolation for directions with the received data.
     */
	void _process_rx_packet();
		
	/**
     * \func _set_usb_frameun
     * \brief This function returns a void* of the report 
	 * constructed.
	 * 
	 * @returns void* - structure pointer.
     */
	void* _set_usb_frame();
	
}; //Bluetooth_Device

#endif //__BLUETOOTH_DEVICE_H__
