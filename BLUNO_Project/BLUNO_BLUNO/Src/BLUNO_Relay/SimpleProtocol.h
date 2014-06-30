/* 
* SimpleProtocol.h
*
* Created: 6/30/2014 11:33:28 AM
* Author: Administrator
*/


#ifndef __SIMPLEPROTOCOL_H__
#define __SIMPLEPROTOCOL_H__

/**
 * This class is a simple example of structuring a response to a call 
 * when communicating with another machine or human.
 */

/**
 * Defines a mesage type 
 */
struct message_t {
	char* message;
	int message_length;
};

/**
 * As mentioned above this class is a simple class that structures messages
 * for structured outputs. We use this class to make sure that the other
 * machine or human can understand the messages that we are sending.
 */
class SimpleProtocol{ 
	
	// Public Context
	public:
	
	/**
	 * This class only has one method in it, as it is just a builder and 
	 * no logic is really needed to be performed. This builds a message.
	 *
	 * @param time							- the system time 
	 * @param tag							- the message category tag
	 * @param message						- the message
	 */
	message_t* get_message(unsigned long time, char* tag, char* message){
		
		char data[100];
		sprintf(data, this->_message_template, time, tag, message);
		
		message_t msg = {.message = data, 
						 .message_length = strlen(data)};
						 
		return &msg;	
	}
	
	// Private Context
	private:
		
		// The message template
		static const char _message_template = "[%l]: <%s> {%s}\n\r";
	
	
}; //SimpleProtocol

#endif //__SIMPLEPROTOCOL_H__
