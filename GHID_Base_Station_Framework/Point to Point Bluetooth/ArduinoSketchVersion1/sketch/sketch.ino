// Do not remove the include below
#include <Arduino.h>
#include <avr/wdt.h>
#include "Arduino_HID_Joystick.h"

void configure_device(NVRAM* nvram_object);

/**
 * This is the main function that does the work
 * on the uC. It returns 0 if successfully terminated,
 * and 1 is there is an error.
 * @return
 */

void setup(){

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//~~~~~~~~~~~~~~~~~~~~ INTERRUPT DEFINITIONS ~~~~~~~~~~~~~~~~~~~~~~~
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	// We setup the timer 1 to toggle every 5 second
	// This is our environment context monitor.
	noInterrupts();           // disable all interrupts
	TCCR1A = 0;
	TCCR1B = 0;

	TCNT1 = 68572;            // preload timer 1hz
	TCCR1B |= (1 << CS12);    // 256 prescaler
	TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt

    // Sets the interrupt flags for Serial output and input.
    interrupts();
        
	//! Loads the settings saved in NVRAM
	//! Also loads the commands to the cached mem.
	nvram.load();
	configure_device(&nvram);

	#ifdef DEBUG
		DEBUG_SERIAL.println("STARTING DEBUG ENGINE");
	#endif
	#ifdef DEBUG
		//! Start Debug Engine.
		//debug_api.enable_debug();
	#endif

	#ifdef DEBUG_LEDs
		//! Check LEDs
		debug_api.test_leds();
		debug_api.set_leds(CLEAR_ERRORS);
	#endif

	#ifdef DEBUG
		DEBUG_SERIAL.println("STARTED DEBUG ENGINE");
	#endif

	//! Reset and reboot device.
	attachInterrupt(SELECT_BUTTON_2, reset_device, HIGH);

	#ifdef DEBUG
		DEBUG_SERIAL.println("INTERRUPT ATTACHED TO BUTTON 2");
		DEBUG_SERIAL.println("ENTERING SELECT LOOP");
	#endif

	//! Wait 5sec to check the pin.
	delay(THREE_SECONDS);

        #ifdef DEBUG
          // Force the chosing to emulation device
          digitalWrite(SELECT_BUTTON_1, LOW);
        #endif
        
	//! Check choice (default = Emulation).
	//! 1 - Emulation
	//! 0 - Real USB device
    byte select_pin_read = LOW; // digitalRead(SELECT_BUTTON_1);
	
    if(select_pin_read == HIGH){

		//! Defines the generic pointer (EMULATION).
		//! This is where we setup the object pointer.
		EMULATION_DEVICE emulation_device;
		generic_pointer = &emulation_device;
		emulation_chosen = true;

	#ifdef DEBUG
		DEBUG_SERIAL.println("EMULATION CHOSEN");
	#endif

	}else if(select_pin_read == LOW){

		//! Define the generic pointer (USB HOST DEVICE).
		//! This is where we setup the object pointer.
		USB_DEVICE usb_host_device(&bt_device, &global_context_error_flag);
		generic_pointer = &usb_host_device;
		usb_device_chosen = true;

	#ifdef DEBUG
		DEBUG_SERIAL.println("USB DEVICE CHOSEN");
	#endif
	
		//! We setup the bluetooth device.
		bt_device.setup_bluetooth_device();
		bt_device.set_btd_wii(&btd, &wii_device);
			
		#ifdef DEBUG
			DEBUG_SERIAL.println("BLUETOOTH MODULE SETUP");
		#endif

	}else{
          
          // The device had an internal issue. We reboot by force.
        #ifdef DEBUG
	        DEBUG_SERIAL.println("FATAL ERROR REBOOTING.");
		#endif
		
        #ifdef DEBUG_LEDs
        	debug_api.set_leds(REBOOT_ERROR);
        #endif
        	error();
	}
        
        #ifdef DEBUG  
                int free_mem = memory_check();
                DEBUG_SERIAL.print("FREE MEM: ");
                DEBUG_SERIAL.println(free_mem);
		#endif

	//! Timer is initialized to keep track of the CPU idle time.
	TCCR1B = _BV(CS12) | _BV(CS11);

	#ifdef DEBUG
		DEBUG_SERIAL.println("USB INIT");
	#endif

	#ifdef DEBUG
		DEBUG_SERIAL.println("MEM CHECK");
	#endif
    //! Check memory integrity
    if(memory_check() <= EMPTY){
	#ifdef DEBUG_LEDs
    	debug_api.set_leds(MEMORY_ERROR);
	#endif
		error();
    }
}

void loop(){

	#ifdef DEBUG
      // We are only testing the setup part of the running process
      DEBUG_SERIAL.println("DEBUGGING STARTUP PROCEDURE");
	  delay(ONE_SECOND);
	#endif

	//! If the emulation device is chosen.
	//! Start the emulation process.
	if(emulation_chosen){
	#ifdef DEBUG
		DEBUG_SERIAL.println("STARTING EMULATION ENGINE");
		delay(ONE_SECOND);
	#endif
		//! Cast to the emulation device pointer
		((EMULATION_DEVICE*) generic_pointer)->emulate_usb();

	}else if(usb_device_chosen){
	#ifdef DEBUG
		DEBUG_SERIAL.println("STARTING USB DEVICE ENGINE");
		delay(ONE_SECOND);
	#endif
		//! Cast to the USB device pointer
		((USB_DEVICE*) generic_pointer)->run_usb();
		
	}else{ //! Something went wrong.
	#ifdef DEBUG_LEDs
		debug_api.set_leds(FATAL_ERROR);
	#endif
		error();
	}
}

/**
 * This function configures the device with NVRAM stored
 * parameters.
 * @param nvram_object - NVRAM
 */
void configure_device(NVRAM* nvram_object){
	
        SERIAL_OUTPUT.begin(nvram_object->nv.serial1_speed);
		RF_SERIAL.begin(nvram_object->nv.serial2_speed);
	#ifdef DEBUG
		DEBUG_SERIAL.begin(nvram_object->nv.serial3_speed);
		DEBUG_SERIAL.println("BOOT SERIAL");
	#endif

	//! Buttons setup
	pinMode(nvram_object->nv.button_1,
				 nvram_object->nv.button1_setting);
	pinMode(nvram_object->nv.button_2,
				 nvram_object->nv.button2_setting);

	//! LED setup
	pinMode(nvram_object->nv.led_1,
				 nvram_object->nv.led1_setting);
	pinMode(nvram_object->nv.led_2,
				 nvram_object->nv.led2_setting);
	pinMode(nvram_object->nv.led_3,
				 nvram_object->nv.led3_setting);
	pinMode(nvram_object->nv.led_4,
				 nvram_object->nv.led4_setting);
				 
	// Set the default values
	nvram_object->nv.default_values = 1;
	
	#ifdef DEBUG
		DEBUG_SERIAL.println("NVRAM READ");
	#endif
}

