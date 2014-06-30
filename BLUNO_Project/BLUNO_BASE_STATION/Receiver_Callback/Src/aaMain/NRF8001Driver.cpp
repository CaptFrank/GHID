/* 
* NRF8001Driver.cpp
*
* Created: 6/23/2014 8:14:15 AM
* Author: Administrator
*/

#include "NRF8001Driver.h"

// Public

/**
 * This is the default constructor for the class.
 * 
 * @param state									- the aci settings structure
 * @param utils									- the system utilities
 */
NRF8001Driver::NRF8001Driver(struct aci_state_t* state, Utilities* utils){
	
	// Set the internal access to the settings structure
	this->_aci_state = state;
	this->_utils = utils;
	this->_timing_change_done = false;
	this->_setup_required = false;
	
	// Assign a pipe mapping internally
	if( sizeof(this->_services_pipe_type_mapping) > 0 ){
		services_pipe_type_mapping_t temp[] = SERVICES_PIPE_TYPE_MAPPING_CONTENT;
		memcpy((void*)this->_services_pipe_type_mapping, temp, sizeof(temp));
	}
}

/**
 * This is the default setup loop.
 */
void NRF8001Driver::setup(){
	
	/**
	 *	Point ACI data structures to the the setup data that the nRFgo studio generated for the nRF8001
	 */
	if (NULL != this->_services_pipe_type_mapping){
		this->_aci_state->aci_setup_info.services_pipe_type_mapping = &this->_services_pipe_type_mapping[0];
		
	// Nothing was generated beforehand
	}else{ 
		this->_aci_state->aci_setup_info.services_pipe_type_mapping = NULL;
	}

	// We reset the nRF8001 here by toggling the RESET line connected to the nRF8001
	// If the RESET line is not available we call the ACI Radio Reset to soft reset the nRF8001
	// then we initialize the data structures required to setup the nRF8001
	// The second parameter is for turning debug printing on for the ACI Commands and Events so they be printed on the Serial
	lib_aci_init(this->_aci_state, false);
}

/**
 * This is the default run method.
 */
void NRF8001Driver::run(){
	
	// We enter the if statement only when there is a ACI event available to be processed
	if (lib_aci_event_get(this->_aci_state, &this->_aci_data)){
  
		// Get the event pointer
		aci_evt_t* aci_evt;
		aci_evt = &this->_aci_data.evt;

		// We switch on the event opcode
		switch(aci_evt->evt_opcode){
			
			/**
			 *	As soon as you reset the nRF8001 you will get an ACI Device Started Event
			 */
			case ACI_EVT_DEVICE_STARTED:
			
				// Get the number of credits
				this->_aci_state->data_credit_total = aci_evt->params.device_started.credit_available;
			
				// Switch on the device mode
				switch(aci_evt->params.device_started.device_mode){
				
					// In setup mode
					case ACI_DEVICE_SETUP:
                         
						#ifdef DEBUG           
							Serial.println(F("Evt Device Started: Setup"));
						#endif
						
						// A setup must to issued before use
						this->_setup_required = true;
						break;

					// In standby mode
					case ACI_DEVICE_STANDBY:
					
					#ifdef DEBUG   
						Serial.println(F("Evt Device Started: Standby"));
					#endif
					
					// Looking for a device by sending radio advertisements
					// When the device connects to us we will get an ACI_EVT_CONNECTED event from the nRF8001
					if (aci_evt->params.device_started.hw_error){
						delay(20); //Magic number used to make sure the HW error event is handled correctly.
					}else{ 
					
						// Connect
						lib_aci_connect(180/* in seconds */, 0x0050 /* advertising interval 50ms*/);
                        
						#ifdef DEBUG
							Serial.println(F("Advertising process started"));
						#endif
					}
					break;
				}
			break;

			/**
			 * If we get a command response
			 */
			case ACI_EVT_CMD_RSP:
			
				// If an ACI command response event comes with an error -> stop
				if (ACI_STATUS_SUCCESS != aci_evt->params.cmd_rsp.cmd_status){
			
					// ACI ReadDynamicData and ACI WriteDynamicData will have status codes of
					// TRANSACTION_CONTINUE and TRANSACTION_COMPLETE
					// all other ACI commands will have status code of ACI_STATUS_SCUCCESS for a successful command

					#ifdef DEBUG
						Serial.print(F("ACI Command "));
						Serial.println(aci_evt->params.cmd_rsp.cmd_opcode, HEX);
						Serial.print(F("Evt Cmd respone: Status "));
						Serial.println(aci_evt->params.cmd_rsp.cmd_status, HEX);
					#endif
				}
			
				// If we get a Device Version request
				if (ACI_CMD_GET_DEVICE_VERSION == aci_evt->params.cmd_rsp.cmd_opcode){
				
					// Store the version and configuration information of the nRF8001 in the Hardware Revision String Characteristic
					lib_aci_set_local_data(this->_aci_state, PIPE_DEVICE_INFORMATION_HARDWARE_REVISION_STRING_SET,
											(uint8_t *)&(aci_evt->params.cmd_rsp.params.get_device_version), 
											sizeof(aci_evt_cmd_rsp_params_get_device_version_t));
				}
			break;

			/**
			 * If we get a connected event
			 */
			case ACI_EVT_CONNECTED:
			
				// UART setup is complete

				#ifdef DEBUG
					Serial.println(F("Evt Connected"));
				#endif
                                
				this->_uart_over_ble_init();
				this->_timing_change_done = false;
				this->_aci_state->data_credit_available = this->_aci_state->data_credit_total;

				/**
				 *	Get the device version of the nRF8001 and store it in the Hardware Revision String
				 */
				lib_aci_device_version();
				break;

			/**
			 * If we get a pipe status request
			 */
			case ACI_EVT_PIPE_STATUS:
				
				#ifdef DEBUG
					Serial.println(F("Evt Pipe Status"));
				#endif
				
				// Check the pipes
				if (lib_aci_is_pipe_available(this->_aci_state, 
												PIPE_UART_OVER_BTLE_UART_TX_TX) 
												&& (false == this->_timing_change_done)){
					
					// change the timing on the link as specified in the nRFgo studio -> nRF8001 conf. -> GAP.
					// Used to increase or decrease bandwidth
					lib_aci_change_timing_GAP_PPCP(); 
					this->_timing_change_done = true;
				}
			break;

			/**
			 * If we get a timing change request
			 */
			case ACI_EVT_TIMING:

				#ifdef DEBUG			        
					Serial.println(F("Evt link connection interval changed"));
				#endif
				
				// Set the new timing
				lib_aci_set_local_data(this->_aci_state,
										PIPE_UART_OVER_BTLE_UART_LINK_TIMING_CURRENT_SET,
										(uint8_t *)&(aci_evt->params.timing.conn_rf_interval), /* Byte aligned */
										PIPE_UART_OVER_BTLE_UART_LINK_TIMING_CURRENT_SET_MAX_SIZE);
				break;

			/**
			 * If we get disconnected status
			 */
			case ACI_EVT_DISCONNECTED:
			
				#ifdef DEBUG
					Serial.println(F("Evt Disconnected/Advertising timed out"));
				#endif
				
				// Start advertising
				lib_aci_connect(180/* in seconds */, 0x0100 /* advertising interval 100ms*/);
				break;

			/**
			 * If we get data from the remote node
			 */
			case ACI_EVT_DATA_RECEIVED:
		
				#ifdef DEBUG
					Serial.print(F("Pipe Number: "));
					Serial.println(aci_evt->params.data_received.rx_data.pipe_number, DEC);
                #endif
				            
				// If we have received data from the rx pipe
				if (PIPE_UART_OVER_BTLE_UART_RX_RX == aci_evt->params.data_received.rx_data.pipe_number){
					
					// Reset the buffer memory
					memset(this->_uart_buffer.data, 0x00, sizeof(this->_uart_buffer));
					
					// Reset the length
					this->_uart_buffer.length = 0;
				
					// Store the data received into a buffer type
					for(register uint8_t i = 0; i < aci_evt->len - 2; i++){
					
						this->_uart_buffer.data[i] = aci_evt->params.data_received.rx_data.aci_data[i];
						this->_uart_buffer.length ++;
					}
            
                    #ifdef DEBUG
						Serial.print("Read data: ");
						Serial.write((uint8_t*)this->_uart_buffer.data, this->_uart_buffer.length);
						Serial.println();
					#endif
					
					// Put the data within the ring buffer
					for(register uint8_t i = 0; i < this->_uart_buffer.length; i ++){
						this->_utils->ring_buffer.put(this->_uart_buffer.data[i]);
					}
				}
			
				// If we got a control point byte
				if (PIPE_UART_OVER_BTLE_UART_CONTROL_POINT_RX == 
					aci_evt->params.data_received.rx_data.pipe_number){

					// We process the token	
					this->_uart_process_control_point(&aci_evt->params.data_received.rx_data.aci_data[0], 
													aci_evt->len - 2); //Subtract for Opcode and Pipe number
				}
				break;

			/**
			 * If we get a data credit token
			 */
			case ACI_EVT_DATA_CREDIT:
		
				// We add a credit token to the queue
				this->_aci_state->data_credit_available += aci_evt->params.data_credit.credit;
				break;

		
			/**
			 * If we get a pipe error
			 */
			case ACI_EVT_PIPE_ERROR:
		
				// See the appendix in the nRF8001 Product Specification for details on the error codes

				// Increment the credit available as the data packet was not sent.
				// The pipe error also represents the Attribute protocol Error Response sent from the peer and that should not be counted
				// for the credit.
				if (ACI_STATUS_ERROR_PEER_ATT_ERROR != aci_evt->params.pipe_error.error_code){
					this->_aci_state->data_credit_available++;
				}
				break;

			/**
			 * If we get a hardware error
			 */
			case ACI_EVT_HW_ERROR:	
                
				#ifdef DEBUG
					Serial.print(F("HW error: "));
					Serial.println(aci_evt->params.hw_error.line_num, DEC);
				#endif
			
				// Restart the adversiting mode...
				lib_aci_connect(180/* in seconds */, 0x0050 /* advertising interval 50ms*/);
				break;

		} // End switch
	} // End If

	/** 
	 * If setup_required is set to true when the device starts up and enters setup mode.
	 * It indicates that do_aci_setup() should be called. The flag should be cleared if
	 * do_aci_setup() returns ACI_STATUS_TRANSACTION_COMPLETE.
	 */
	if(this->_setup_required){ 
		
		// If we setup properly
		if (SETUP_SUCCESS == do_aci_setup(this->_aci_state)) {
			this->_setup_required = false;
		}
	}
}

/**
 * This is the default write method.
 *
 * @param buffer								- the data buffer
 * @param length								- the data length
 * @returns bool								- the write status
 */
bool NRF8001Driver::write(uint8_t* buffer, uint8_t length){
	
	// Satus container	
	bool status = false;
	
	// Check if we have a pipe free
	if (lib_aci_is_pipe_available(this->_aci_state, PIPE_UART_OVER_BTLE_UART_TX_TX) &&
									(this->_aci_state->data_credit_available > 0)){
		
		// Send the data							
		status = lib_aci_send_data(PIPE_UART_OVER_BTLE_UART_TX_TX, buffer, length);
		
		// If we have a good status
		if (status){
			
			// Decrease the write tokens
			this->_aci_state->data_credit_available--;
		}
	}
	
	// Return the status
	return status;
}
		
/**
* This is the default read method. Only returns true if data is received
*
* @returns buffer_t							- the data buffer
*/
buffer_t* NRF8001Driver::read(){
	
	// Timeout
	uint16_t timeout = TIMEOUT;
	
	while(timeout --){
		
		// Run the engine again
		this->run();
	
		// If valid data
		if(this->_uart_buffer.valid){
			return &this->_uart_buffer;
		}
		
		// Delay the cpu
		delay(500);
	}
}

// Private

/**
 * This is the default process control point method.
 *
 * @param buffer								- the data buffer
 * @param length								- the data length
 */
bool NRF8001Driver::_uart_process_control_point(uint8_t* buffer, uint8_t length){

	// Status container
	bool status = false;
	
	// Connection parameters pointer
	aci_ll_conn_params_t* conn_params;

	// If hte TX pipe is available
	if (lib_aci_is_pipe_available(this->_aci_state, PIPE_UART_OVER_BTLE_UART_CONTROL_POINT_TX) ){
		
		// We switch on the buffer pointer
		switch(*buffer){
			
			/**
			 *	Queues a ACI Disconnect to the nRF8001 when this packet is received.
			 *	May cause some of the UART packets being sent to be dropped
			 */
			case UART_OVER_BLE_DISCONNECT:
			
				/**
				 *	Parameters:
				 *	None
				 */
				lib_aci_disconnect(this->_aci_state, ACI_REASON_TERMINATE);
				status = true;
				break;

			/**
			 *	Queues an ACI Change Timing to the nRF8001
			 */
			case UART_OVER_BLE_LINK_TIMING_REQ:
			
				/**
				 * Parameters:
				 * Connection interval min: 2 bytes
				 * Connection interval max: 2 bytes
				 * Slave latency:           2 bytes
				 * Timeout:                 2 bytes
				 * Same format as Peripheral Preferred Connection Parameters 
				 *         (See nRFgo studio -> nRF8001 Configuration -> GAP Settings)
				 * Refer to the ACI Change Timing Request in the nRF8001 Product Specifications
				 */
				
                
                #ifdef DEBUG
					Serial.print(F("UART over BLE linkin timing request."));
                #endif
				
				conn_params = (aci_ll_conn_params_t*)(buffer + 1);
				lib_aci_change_timing(conn_params->min_conn_interval,
									  conn_params->max_conn_interval,
									  conn_params->slave_latency,
									  conn_params->timeout_mult);
				status = true;
				break;

			/**
			 *	Clears the RTS of the UART over BLE
			 */
			case UART_OVER_BLE_TRANSMIT_STOP:

				/**
				 * Parameters:
				 *	None
				 */
				this->_uart_over_ble.uart_rts_local = false;
				status = true;
				break;

			/**
			 *	Set the RTS of the UART over BLE
			 */
			case UART_OVER_BLE_TRANSMIT_OK:
					
				/**
				 *	Parameters:
				 *	None
				 */
				this->_uart_over_ble.uart_rts_local = true;
				status = true;
				break;
		}
	}
	
	return status;
}
