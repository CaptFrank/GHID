/*
 * Utilities.h
 *
 * Created: 5/20/2014 12:42:56 PM
 *  Author: Administrator
 */ 


#ifndef UTILITIES_H_
#define UTILITIES_H_

//! --------------------------------------------------
//! Source Code
//! --------------------------------------------------

/**
 * This class is the global device handler. It starts and stops the device processe globally.
 */
class utilities {

	//! Public Context
	public: 
		/**
		 * This function simply acts as a boolean flag toggle. We use
		 * it to start the device data acquisition.
		 */
		void start_device(void);

		/**
		 * This function simply acts as a boolean flag toggle. We use
		 * it to stop the device data acquisition.
		 */
		void stop_device(void);
		
		/**
		 * Reboot the device
		 */
		void reboot();
			
		//! start engine boolean
		bool start_engine;
	
};


#endif /* UTILITIES_H_ */