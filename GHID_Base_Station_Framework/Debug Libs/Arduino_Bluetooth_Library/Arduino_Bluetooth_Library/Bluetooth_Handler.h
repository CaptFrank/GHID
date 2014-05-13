//
//  Bluetooth_Handler.h
//  Arduino_Bluetooth_Library
//
//  Created by Francis Papineau on 2/3/2014.
//  Copyright (c) 2014 Francis Papineau. All rights reserved.
//

#ifndef __Arduino_Bluetooth_Library__Bluetooth_Handler__
#define __Arduino_Bluetooth_Library__Bluetooth_Handler__

#include "Error_Decoder.h"
#include "Command_Defines.h"

#define MAX_BUFFER				255
#define TEN_THOUSAND_TICKS		10000
#define TIMEOUT					20

/**
 * \brief this is a container definition struct for the 
 * bluetooth response. It is comprised of a holder array, 
 * the receive address and a valid flag.
 */
struct bluetooth_response_t {
    
    //! This valid flag is tells us if the reception was
    //! successfully or not
    boolean valid;
    
    //! This is the received address in ASCII characters
    char* receive_address;
    
    //! This is the received message
    char raw_response[MAX_BUFFER];
	
	//! This is the parsed response
	char parsed_response[MAX_BUFFER];
};


struct bluetooth_settings_t {
	
	byte default_values;
	byte* device_name;
	byte* device_role;
	byte* device_type;
	byte* device_access_code;
	byte* device_mode;
	byte* pairing_password;
	byte* serial_port_params;
	byte* connection_mode;
	byte* binding_address;
	byte* sniff_params;
	byte* power_params;
	byte* security_mode;
	
	byte* remote_device_address_timeout;
	byte* remote_device_address;
	
};


/**
 * \class This class is the handler for the bluetooth connection.
 * \brief This is the api that controls, sets and receives data
 * through the bluetooth interface.
 */
class BLUETOOTH_HANDLER {
    
    // Private Access Context
    private:
    
    //! The response timeout container variable
    word timeout = 1000;
	
	//! The response structure
	bluetooth_response_t response;
	
	//! This is the context mutex
	union {
		struct{
		
			byte running_mutex		: 1;
			byte pause_flag			: 1;
			byte stop_flag			: 1;
			byte start_flag			: 1;
			byte error_flag			: 1;
		}runtime_mutex_flags;
		byte flag_byte;
	}flags;
    
    /**
     * \func error
     * \brief This function is the error function for the bluetooth
     *	module. It provides the exit point for the API.
	 *
     * @param byte error_code 
     */
    void error(byte error_code);
    
    /**
     * \func send_command
     * \brief This is the generic entry point for sending a command
	 * to the hardware.
     *
     * @param byte* comamnd
	 * @param byte length
     */
    void send_command(byte* command, byte length);
	
	/**
     * \func receive_response
     * \brief This is the generic entry point for receiving a command
	 * to the hardware.
     *
	 * @return bluetooth_response_t* response
     */
	bluetooth_response_t* receive_response(byte length, byte* command);
    
	/**
     * \func receive_command
     * \brief This is the generic entry point for receiving a command
	 * to the hardware.
     *
	 * @return bluetooth_response_t* response
     */
	void parse_response(char* packet, byte command_length, byte packet_length);
	
	// ----------------------------------------------------------------------
	
    /**
     * \func _bluetooth_handle_at_command
     * \brief This function is the function which handles
	 * the sending of the AT command
     */
    void _bluetooth_handle_at_command();
    
    /**
     * \func _bluetooth_init_device
     * \brief This function is the entry point for the API.
	 * This function initializes the API and the device.
     */
    void _bluetooth_init_device();
    
    /**
     * \func _bluetooth_reset_device
     * \brief This function handles the reset command that 
	 * is sent to the bluetooth device.
     */
    void _bluetooth_reset_device();
    
    /**
     * \func _bluetooth_get_software_version
     * \brief This function receives the bluetooth device software
     * Version.
	 *
	 * @see bluetooth_response_t
     * @return bluetooth_response_t* - A pointer to the received
     */
    bluetooth_response_t* _bluetooth_get_software_version();
    
    /**
     * \func _bluetooth_restore_defaults
     * \brief This function sends a command to restore to defaults
     */
    void _bluetooth_restore_defaults();
    
    /**
     * \func _bluetooth_delete_autenticated_device
     * \brief This function deletes a device from the authorized
     * network table.
	 *
     * @param char* ascii_device
     */
    void _bluetooth_delete_autenticated_device(char* ascii_device,  byte length);
    
    /**
     * \func _bluetooth_delete_all_authenticated_devices
     * \brief This deletes all authorized devices on the network
	 * table.
     */
    void _bluetooth_delete_all_authenticated_devices();
    
    /**
     * \func _bluetooth_check_if_listed_devices_active
     * \brief This is the check function that checks if the devices
     * on the device list are active.
	 *
     * @return bool - validation
     */
    boolean _bluetooth_check_if_listed_devices_active(char* ascii_device, byte length);
    
    /**
     * \func _bluetooth_check_network_table_length
     * \brief This function checks the length of the network table
	 *
	 * @see bluetooth_response_t
     * @return bluetooth_response_t* - the response return
     */
    bluetooth_response_t* _bluetooth_check_network_table_length();
    
    /**
     * \func _bluetooth_check_most_recently_connected_device
     * \brief This function checks the most recent connection
     *
	 * @see bluetooth_response_t
	 * @return bluetooth_response_t* - the response return
     */
    bluetooth_response_t* _bluetooth_check_most_recently_connected_device();
    
    /**
     * \func _bluetooth_check_working_status
     * \brief This function checks for the working status of the device.
     *
	 * @see bluetooth_response_t
	 * @return bluetooth_response_t* - the response return
     */
    bluetooth_response_t* _bluetooth_check_working_status();
    
    /**
     * \func _bluetooth_check_nearby_devices
     * \brief This function checks the nearby devices.
     *
	 * @see bluetooth_response_t
	 * @return bluetooth_response_t* - the response return
     */
    bluetooth_response_t* _bluetooth_check_nearby_devices();
    
    /**
     * \func _bluetooth_cancel_request_nearby_devices
     * \brief This kills the check nearby device process
     *
     */
    void _bluetooth_cancel_request_nearby_devices();
    
    /**
     * \func _bluetooth_pair_device
     * \brief This function pairs two devices given a password
     *
     * @param char* ascii_param - pairing password in ascii
     */
    void _bluetooth_pair_device(char* ascii_params, byte length);
    
    /**
     * \func _bluetooth_link_to_device
     * \brief This function link 2 devices
     *
     * @param char* ascii_device - name of the device in ascii
     */
    void _bluetooth_link_to_device(char* ascii_device, byte length);
    
    /**
     * \func _bluetooth_disconnect
     * \brief This disconnects the 2 paired connected devices
     */
    void _bluetooth_disconnect();
    
    /**
     * \func _bluetooth_enter_saving_mode
     * \brief This enters the device in power saving mode
     */
    void _bluetooth_enter_saving_mode();
    
    /**
     * \func  _bluetooth_exit_saving_mode
     * \brief This function exits the power saving mode
     */
    void _bluetooth_exit_saving_mode();
    
    /**
     * \func _bluetooth_test
     * \brief This tests the bluetooth device communication
     *
     * @return bool - validation
     */
    bool _bluetooth_test();
    
    // ----------------------------------------------------------------------
    
    /**
     * \func _bluetooth_set_device_name
     * \brief This function sets the device name
     *
     * @param char* ascii_name - name of device in ascii
     */
    void _bluetooth_set_device_name(char* ascii_name,  byte length);
    
    /**
     * \func _bluetooth_set_device_role
     * \brief This function sets the device role
     *
     * @param ascii_role - the role of the device
     */
    void _bluetooth_set_device_role(char* ascii_role,  byte length);
    
    /**
     * \func _bluetooth_set_device_type
     * \brief This sets the device type
     *
     * @param ascii_type - device type
     */
    void _bluetooth_set_device_type(char* ascii_type, byte length);
    
    /**
     * \func _bluetooth_set_access_code
     * \brief This sets the access code for the pairing
     *
     * @param ascii_access_code - password
     */
    void _bluetooth_set_access_code(char* ascii_access_code, byte length);
    
    /**
     * \func _bluetooth_set_inquiry_mode
     * \brief This sets the inquiry mode
     *
     * @param ascii_inquiry_mode
     */
    void _bluetooth_set_inquiry_mode(char* ascii_inquiry_mode, byte length);
    
    /**
     * \func _bluetooth_set_pairing_password
     * \brief This sets the pairing password
     *
     * @param ascii_password - password
     */
    void _bluetooth_set_pairing_password(char* ascii_password, byte length);
    
    /**
     * \func _bluetooth_set_serial_port_params
     * \brief This sets the port parameters
     *
     * @param ascii_params - parameters
     */
    void _bluetooth_set_serial_port_params(char* ascii_params, byte length);
    
    /**
     * \func _bluetooth_set_connection_mode
     * \brief This sets the connection mode
     *
     * @param ascii_connection_mode - connection mode
     */
    void _bluetooth_set_connection_mode(char* ascii_connection_mode,  byte length);
    
    /**
     * \func _bluetooth_set_binding_address
     * \brief This sets the binding address
     *
     * @param ascii_binding_address - address
     */
    void _bluetooth_set_binding_address(char* ascii_binding_address, byte length);
    
    /**
     * \func _bluetooth_set_led_polarity
     * \brief This sets the led polarity
     *
     * @param ascii_polarity - polarity
     */
    void _bluetooth_set_led_polarity(char* ascii_polarity, byte length);
    
    /**
     * \func _bluetooth_set_pio_output
     * \brief This is a function which sets the output of the pio
     *
     * @param ascii_pio - pio 
     */
    void _bluetooth_set_pio_output(char* ascii_pio, byte length);
    
    /**
     * \func  _bluetooth_set_multiple_output
     * \brief Sets multiple output
     *
     * @param ascii_ports - ports
     */
    void _bluetooth_set_multiple_output(char* ascii_ports, byte length);
    
    /**
     * \func _bluetooth_set_pio_input
     * \brief This sets the pio inputs
     *
     * @param ascii_port - port 
     */
    void _bluetooth_set_pio_input(char* ascii_port, byte length);
    
    /**
     * \func _bluetooth_set_inquiry_params
     * \brief This sets the inquiry parameters
     *
     * @param ascii_param
     */
    void _bluetooth_set_inquiry_params(char* ascii_params, byte length);
    
    /**
     * \func _bluetooth_set_sniff_power
     * \brief This function sets the power mode
     *
     * @param ascii_sniff - the power mode
     */
    void _bluetooth_set_sniff_power(char* ascii_sniff, byte length);
    
    /**
     * \func _bluetooth_set_security_mode
     * \brief This sets the security mode
     *
     * @param ascii_enc - encryption mode
     */
    void _bluetooth_set_security_mode(char* ascii_enc, byte length);
    
    // ----------------------------------------------------------------------

    /**
     * \func _bluetooth_get_device_address
     * \brief This gets the device address
     *
     * @see bluetooth_response_t
     * @return bluetooth_response_t*
     */
    bluetooth_response_t* _bluetooth_get_device_address();

    /**
     * \func _bluetooth_get_device_name
     * \brief This gets the local device name
     *
     * @see bluetooth_response_t
     * @return bluetooth_response_t*
     */
    bluetooth_response_t* _bluetooth_get_device_name();

    /**
     * \func _bluetooth_get_remote_device_name
     * \brief This gets the remote device name
     *
     * @see bluetooth_response_t
     * @return bluetooth_response_t*
     */
    bluetooth_response_t* _bluetooth_get_remote_device_name();
    
    /**
     * \func _bluetooth_get_device_role
     * \brief This gets the device role
     *
     * @see bluetooth_response_t
     * @return bluetooth_response_t*
     */
    bluetooth_response_t* _bluetooth_get_device_role();
    
    /**
     * \func _bluetooth_get_device_type
     * \brief This gets the device type
     *
     * @see bluetooth_response_t
     * @return bluetooth_response_t*
     */
    bluetooth_response_t* _bluetooth_get_device_type();
    
    /**
     * \func _bluetooth_get_access_code
     * \brief This gets the access code
     *
     * @see bluetooth_response_t
     * @return bluetooth_response_t*
     */
    bluetooth_response_t* _bluetooth_get_access_code();
    
    /**
     * \func _bluetooth_get_inquiry_mode
     * \brief This function gets the inquiry mode
     *
     * @see bluetooth_response_t
     * @return bluetooth_response_t*
     */
    bluetooth_response_t* _bluetooth_get_inquiry_mode();
    
    /**
     * \func _bluetooth_get_pairing_password
     * \brief This function gets the pairing password
     *
     * @see bluetooth_response_t
     * @return bluetooth_response_t*
     */
    bluetooth_response_t* _bluetooth_get_pairing_password();
    
    /**
     * \func _bluetooth_get_serial_port_params
     * \brief This gets the serial parameters
     *
     * @see bluetooth_response_t
     * @return bluetooth_response_t*
     */
    bluetooth_response_t* _bluetooth_get_serial_port_params();
    
    /**
     * \func _bluetooth_get_connection_params
     * \brief This is a function that gets connection parameters
     *
     * @see bluetooth_response_t
     * @return bluetooth_response_t*
     */
    bluetooth_response_t* _bluetooth_get_connection_params();
    
    /**
     * \func _bluetooth_get_binding_address
     * \brief This is a function that gets the binding address
     *
     * @see bluetooth_response_t
     * @return bluetooth_response_t*
     */
    bluetooth_response_t* _bluetooth_get_binding_address();
    
    /**
     * \func _bluetooth_get_led_polarity
     * \brief This is a function that gets the led polarity.
     *
     * @see bluetooth_response_t
     * @return bluetooth_response_t*
     */
    bluetooth_response_t* _bluetooth_get_led_polarity();
    
    /**
     * \func _bluetooth_get_pio_input
     * \brief This function gets the pio inputs
     *
     * @see bluetooth_response_t
     * @return bluetooth_response_t*
     */
    bluetooth_response_t* _bluetooth_get_pio_input();
    
    /**
     * \func _bluetooth_get_inquiry_params
     * \brief This function gets the inquiry parameters
     *
     * @see bluetooth_response_t
     * @return bluetooth_response_t*
     */
    bluetooth_response_t* _bluetooth_get_inquiry_params();
    
    /**
     * \func _bluetooth_get_sniff_power_param
     * \brief This gets the sniff power parameters.
     *
     * @see bluetooth_response_t
     * @return bluetooth_response_t*
     */
    bluetooth_response_t* _bluetooth_get_sniff_power_param();
    
    /**
     * \func _bluetooth_get_security_mode
     * \brief This function gets the security mode of the device
	 *		- 
     *
	 * @see bluetooth_response_t
	 * @return bluetooth_response_t* - the response return
     */
    bluetooth_response_t* _bluetooth_get_security_mode();
    
    public:
    
    // The default operations function table
    struct default_operations{
        
		void (*_bluetooth_test)();
        void (*_bluetooth_handle_at_command)();
        void (*_bluetooth_init_device)();
        void (*_bluetooth_reset_device)();
        bluetooth_response_t* (*_bluetooth_get_software_version)();
        void (*_bluetooth_restore_defaults)();
        void (*_bluetooth_delete_autenticated_device)(char* ascii_device, byte length);
        void (*_bluetooth_delete_all_authenticated_devices)();
        boolean (*_bluetooth_check_if_listed_devices_active)();
        bluetooth_response_t* (*_bluetooth_check_network_table_length)();
        bluetooth_response_t* (*_bluetooth_check_most_recently_connected_device)();
        bluetooth_response_t* (*_bluetooth_check_working_status)();
        bluetooth_response_t* (*_bluetooth_check_nearby_devices)();
        void (*_bluetooth_cancel_request_nearby_devices)();
        void (*_bluetooth_pair_device)(char* ascii_params, byte length);
        void (*_bluetooth_link_to_device)(char* ascii_device, byte length);
        void (*_bluetooth_disconnect)();
        void (*_bluetooth_enter_saving_mode)();
        void (*_bluetooth_exit_saving_mode)();
    };
    
    // The setter function table
    struct setter_oprations{
		
        void (*_bluetooth_set_device_name)(char* ascii_name, byte length);
        void (*_bluetooth_set_device_role)(char* ascii_role, byte length);
        void (*_bluetooth_set_device_type)(char* ascii_type, byte length);
        void (*_bluetooth_set_access_code)(char* ascii_access_code, byte length);
        void (*_bluetooth_set_inquiry_mode)(char* ascii_inquiry_mode, byte length);
        void (*_bluetooth_set_pairing_password)(char* ascii_password, byte length);
        void (*_bluetooth_set_serial_port_params)(char* ascii_params, byte length);
        void (*_bluetooth_set_connection_mode)(char* ascii_connection_mode, byte length);
        void (*_bluetooth_set_binding_address)(char* ascii_binding_address, byte length);
        void (*_bluetooth_set_led_polarity)(char* ascii_polarity, byte length);
        void (*_bluetooth_set_pio_output)(char* ascii_pio, byte length);
        void (*_bluetooth_set_multiple_output)(char* ascii_ports, byte length);
        void (*_bluetooth_set_pio_input)(char* ascii_port, byte length);
        void (*_bluetooth_set_inquiry_params)(char* ascii_params, byte length);
        void (*_bluetooth_set_sniff_power)(char* ascii_sniff, byte length);
        void (*_bluetooth_set_security_mode)(char* ascii_enc, byte length);
    };
    
    // The getter function table
    struct getter_operations{
        
        bluetooth_response_t* (*_bluetooth_get_device_address)();
        bluetooth_response_t* (*_bluetooth_get_device_name)();
        bluetooth_response_t* (*_bluetooth_get_remote_device_name)();
        bluetooth_response_t* (*_bluetooth_get_device_role)();
        bluetooth_response_t* (*_bluetooth_get_device_type)();
        bluetooth_response_t* (*_bluetooth_get_access_code)();
        bluetooth_response_t* (*_bluetooth_get_inquiry_mode)();
        bluetooth_response_t* (*_bluetooth_get_pairing_password)();
        bluetooth_response_t* (*_bluetooth_get_serial_port_params)();
        bluetooth_response_t* (*_bluetooth_get_connection_params)();
        bluetooth_response_t* (*_bluetooth_get_binding_address)();
        bluetooth_response_t* (*_bluetoot_get_led_polarity)();
        bluetooth_response_t* (*_bluetooth_get_pio_output_polarity)();
        bluetooth_response_t* (*_bluetooth_get_pio_input)();
        bluetooth_response_t* (*_bluetooth_get_inquiry_params)();
        bluetooth_response_t* (*_bluetooth_get_sniff_power_param)();
        bluetooth_response_t* (*_bluetooth_get_security_mode)();
    };
    
    // Check the bluetooth device
    void check_device()
    
    // Setup the Bluetooth device
    void setup_device()
    
    // Pair the device
    void pair_device();
    
    // Start the device (link)
    void start_device_stream();
    
    // Pause the device
    void pause_device_stream();
    
    // Stop the device
    void stop_device_stream();
    
    // Return to uC context
    byte return_to_uC_context(byte error_code);
};

/**
 * This is the UART ISR
 */

#endif /* defined(__Arduino_Bluetooth_Library__Bluetooth_Handler__) */
