/*
 * SPI_UART_Example.cpp
 *
 *  Created on: 2014-03-11
 *      Author: francispapineau
 */

#include "Arduino.h"

#include <cdcacm.h>
#include <GHID_Project.h>

//! Here we define the max data size buffer
#define MAX_DATA_SIZE			64
#define VALID_ACC_PACKET_SIZE	7

//! Defined a button state
#define BUTTON_CLICK			0x01
#define BUTTON_UNCLICK			0x00
#define RESET					0x00

/**
 * Defining the state of the AP in our program
 */
enum ap_stat_t {

	STATE_AP_OFF,
	STATE_IDLE,
	STATE_WAIT_ACC_RESPONSE
}state;

/**
 * This is the received buffer struct
 */
typedef struct rx_packet {

	uint8_t buffer[MAX_DATA_SIZE];
	uint16_t buffer_length;

};

//! These are the prototypes for the sketch
void setup(void);
void loop(void);
void reset_joystick_report(void);
bool send_frame(int len, uint8_t* frame);
bool get_frame(uint8_t* buf, uint16_t *len);

//! Defining some chronos commands
uint8_t AP_ON_COMMAND[] = { 0xFF, 0x07, 0x03 };
uint8_t ACC_DATA_REQUEST[] = { 0xFF, 0x08, 0x07, 0x00, 0x00, 0x00, 0x00 };

//! Here we setup a context object
GHID_System_Abstration system;

//! We define a receive buffer
rx_packet rx_buffer;

//! ======================================================================

/**
 * This is the ACM class object which extends the CDCAsyncOper
 * framework included in the Arduino package.
 *
 * It provides the standard asynchornous method to init and send/receive
 * USB packets from one node to the other.
 */
class ACMAsyncOper : public CDCAsyncOper{

	//! Private context
	private:

	/**
	 * This is the error container that will house the errors if any occur
	 */
	uint8_t _error;

	/**
	 * This is the valid flag, true be default
	 */
	bool _valid;

	//! Public context
	public:

	/**
	 * This is the vitural deconstructor of the class.
	 */
	virtual ~ACMAsyncOper();

	/**
	 * This is the init method of the class extended from the parent class.
	 *
	 * @param pacm						- the acm handle
	 */
	virtual uint8_t OnInit(ACM *pacm);

	/**
	 * This is the usb frame sender utility function.
	 *
	 * @param len						- the length of the frame to send
	 * @param frame						- the frame buffer to send
	 * @return bool						- returns success
	 */
	bool send_frame(int len, uint8_t* frame);

	/**
	 * This method gets a frame from the USB controller.
	 *
	 * @param buf						- the buffer where our data lies
	 * @param len						- the length of the data to get
	 * @return bool						- returns success
	 */
	bool get_frame(uint8_t* buf, uint16_t *len);

};

//! ======================================================================

/**
 * This is the init method of the class extended from the parent class.
 *
 * @param pacm							- the acm handle
 */
uint8_t ACMAsyncOper::OnInit(ACM *pacm){
        
        // Set valid flag
        this->_valid = true;
      
	// Set DTR=1 and RTS=1:
	if ((this->_error = pacm->SetControlLineState(3)) > 0){
		this->_valid = false;
	}

	LINE_CODING lc;
	lc.dwDTERate = 115200;
	lc.bCharFormat = 0;
	lc.bParityType = 0;
	lc.bDataBits = 8;
	
	if ((this->_error = pacm->SetLineCoding(&lc)) > 0){
		this->_valid = false;
	}
}

//! ======================================================================

//! Here we setup USB objects based on the class defined above
USB Usb;
ACMAsyncOper AsyncOper;
ACM Acm(&Usb, &AsyncOper);

//! ======================================================================

/**
 * This function overrides the Arduino framework setup function,
 * with our setup routines.
 */
void setup(){

	//! Provide a system setup
	system.setup_USB_interface();

	//! Init the USB stack
	Usb.Init();

	//! We make the state in power off mode
	state = STATE_AP_OFF;

	//! We delay the time to init the USB stack
	delay(200);

}

//! ======================================================================

/**
 * This is the main worker function, which never quits until the
 * process is complete.
 */
void loop(){

	//! We check to see if the USB buffer was not empty
	Usb.Task();

	//! We check if our receiver is ready
	if (!Acm.isReady())
		return; //! An error occured

	/**
	 * This is the main state machine of the USB receiver.
	 */
	switch (state) {

		//! If the state of the AP is off
		case STATE_AP_OFF:

			//! We send an ON command
			if (!send_frame(sizeof(AP_ON_COMMAND), AP_ON_COMMAND)) {
				return; //! An error occured
			}

			//! Then we set the state to IDLE
			state = STATE_IDLE;
			break;

		//! If the state is in fact IDLE
		case STATE_IDLE:

			//! We send a data request command
			if (!send_frame(sizeof(ACC_DATA_REQUEST), ACC_DATA_REQUEST)) {
				return; //! An error occured
			}

			//! We set the state to WAIT for data
			state = STATE_WAIT_ACC_RESPONSE;
			break;

		//! If the state is in wait for data mode
		case STATE_WAIT_ACC_RESPONSE:

                        //! Assigne the size of the buffer
                        rx_buffer.buffer_length = MAX_DATA_SIZE;
                        
			//! We get the frame from teh AP
			if (!get_frame(rx_buffer.buffer, &rx_buffer.buffer_length)) {
				return; //! An error occured
			}

			//! We check if we got a valid packet
			if (rx_buffer.buffer_length == VALID_ACC_PACKET_SIZE) {

				//! We type cast the data to respective containers
				byte type = (byte) rx_buffer.buffer[3];
				int8_t x = (int8_t) rx_buffer.buffer[4];
				int8_t y = (int8_t) rx_buffer.buffer[5];
				int8_t z = (int8_t) rx_buffer.buffer[6];

				//! Here we map the inputs to the framework.
				system.joystick_report.x_axis = x;
				system.joystick_report.y_axis = y;
				system.joystick_report.z_axis = z;

				/**
				 * Button mapping:
				 * 	 - Button 1 = [*]
				 * 	 - Button 2 = [#]
				 * 	 - Button 3 = [^]
				 */

				//! We switch on the button pushes
				switch (type) {

					//! We have button 1 pushed
					case 0x11:
						system.joystick_report.buttons.buttons_bits.button_1 = BUTTON_CLICK;
						break;

					//! We have button 2 pushed
					case 0x21:
						system.joystick_report.buttons.buttons_bits.button_2 = BUTTON_CLICK;
						break;

					//! We have button 3 pushed
					case 0x31:
						system.joystick_report.buttons.buttons_bits.button_3 = BUTTON_CLICK;
						break;

					//! No need for this.
					case 0xFF:
						break;

					//! Default case
					default:
						break;
				}

				//! Send the usb packet
				system.send_USB_frame();

				//! Reset the joystick report.
				reset_joystick_report();

				//! We start the state machine over again
				state = STATE_IDLE;
			}
			break;

		//! Nothing happens
		default:
			break;
	}
}

//! ======================================================================

/**
 * This is jsut a utility function which resets the joystick report container
 * to allow for less noise in the USB stream.
 */
void reset_joystick_report(){

	system.joystick_report.buttons.buttons_byte = BUTTON_UNCLICK;
	system.joystick_report.x_axis = RESET;
	system.joystick_report.y_axis = RESET;
	system.joystick_report.z_axis = RESET;
	return;
}

/**
 * This is the usb frame sender utility function.
 *
 * @param len						- the length of the frame to send
 * @param frame						- the frame buffer to send
 * @return bool						- returns success
 */
bool send_frame(int len, uint8_t* frame){

	//! Send the data
	bool rcode = Acm.SndData(len, frame);

	//! Send the success back
	if (rcode) {
		return false;
	}else {
		return true;
	}
}
/**
 * This method gets a frame from the USB controller.
 *
 * @param buf						- the buffer where our data lies
 * @param len						- the length of the data to get
 * @return bool						- returns success
 */
bool get_frame(uint8_t* buf, uint16_t *len){

	//! Get the data
	bool rcode = Acm.RcvData(len, buf);

	//! Send the success back
	if (rcode && rcode != hrNAK) {
		return false;
	}
	return true;
}
