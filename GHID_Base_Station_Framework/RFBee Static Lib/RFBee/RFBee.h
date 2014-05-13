/* 
* RFBee_Stack.h
*
* Created: 1/25/2014 12:04:03 AM
* Author: francis-ccs
*/


#ifndef __RFBEE_STACK_H__
#define __RFBEE_STACK_H__

#include "Hardware_Defines.h"
#include "NVRAM_API.h"
#include "Main_Defines.h"


/**
 * Defines the error state of the RFBee.
 */
enum rfbee_error_t{
	OK, 
	ERROR
};

class RFBEE_STACK : public main_defines{

public:

	/**
	 * Defines and option type
	 */
	typedef byte option_t;
		
	/**
	 * This is the nvram object passed to the class.
	 */
	NVRAM* nvram_object;
	
	// the error flag
	boolean error_flag;
	

	/**
	 * This is the default constructor for the RFBEE Stack object.
	 * We must pass an NVRAM object pointer to it in order to gain
	 * access to the NVRAM where the commands are stored permanently.
	 */
	RFBEE_STACK(NVRAM* nvram_object);
	
	/**
	 * This is the setup routine for the RFBee.
	 */
	void setup_RF_module();
	
	/**
	 * This gets the hw and sw versions for testing
	 */
	boolean test_RF_module();
	
	/**
	 * This checks the internal flag of the rfbee module interface.
	 */
	boolean check_rfbee_state();
	
	/**
	 * This function takes care of the sending of the command
	 * and AT Command mode. Public wrapper
	 */
	rfbee_error_t rfbee_handle_AT_command();
	 
	 		
private:

	// Defining a buffer for commands to send
	byte tx_buffer[10];
	
	// Defining a receiveing buffer
	byte rx_buffer[10];

	/**
	 * This function sets the address checking scheme in the 
	 * RFBee hardware. 
	 *
	 * @param ADDRESS_SCHEME scheme
	 */
	void rfbee_set_address_checking_scheme(option_t scheme);


	/**
	 * This function sets the address of the RFBee.
	 *
	 * @param option address
	 */
	void rfbee_set_address(option_t address);
	
	
	/**
	 * This function sets the receivable address.
	 *
	 * @param option address
	 */
	void rfbee_set_receivable_address(option_t address);
	
	
	/**
	 * This funtion sets the power of the transmit antenna.
	 *
	 * @param option power
	 */
	void rfbee_set_transmit_power(option_t power);
	
	
	/**
	 * This function sets the baud of the RFBee.
	 *
	 * @param option
	 */
	void rfbee_set_uart_baud(option_t baud);
	
	
	/**
	 * This sets the mode of the RFBee.
	 *
	 * @param option mode
	 */
	void rfbee_set_working_mode(option_t mode);
	
	
	/**
	 * This sets the threshold for reading packets.
	 *
	 * @param option threshold
	 */
	void rfbee_set_threshold(option_t threshold);
	
	
	/**
	 * This sets the transmit datarate of the RFBee
	 *
	 * @param option datarate
	 */
	void rfbee_set_data_rate(option_t datarate);
	
	/**
	 * This resets the RFBee configs.
	 */
	void rfbee_restore_default_state();
	
	/**
	 * This gets the fw version
	 */
	void rfbee_get_firmware_version();
	
	/**
	 * This gets the hw version.
	 */
	void rfbee_get_hardware_version();
	
	/**
	 * This function takes care of the sending of the command
	 * and AT Commadn mode.
	 */
	rfbee_error_t _rfbee_handle_AT_command();
	
	/**
	 * This function handles the response from teh RFBee.
	 */
	rfbee_error_t _rfbee_handle_response();
	
	/**
	 * This is the error method for rfbee stack.
	 * 
	 * \returns false if error
	 */
	boolean _rfbee_error();
	
	/**
	 * This is the sender method.
	 */
	void _rfbee_send_command(void* command, byte size);
	
	/**
	 * read for a custom string
	 */
	void _rfbee_handle_response_custom();
};

#endif //__RFBEE_STACK_H__
