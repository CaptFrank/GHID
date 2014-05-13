/*
 * NVRAM_API.cpp
 *
 *  Created on: Jul 25, 2013
 *      Author: fjpapin
 */

#include "NVRAM_API.h"

#define SPACE 	0x00

//! Define the structure
const NVRAM::nv_data_t nvram_default PROGMEM = {

        9600,
        9600,
        9600,
        0x0A, // RF Setting
        0x01, // RF Setting
        SELECT_BUTTON_1,
        INPUT,
        SELECT_BUTTON_2,
        INPUT,
        DBG_LED_1,
        OUTPUT,
        DBG_LED_2,
        OUTPUT,
        DBG_LED_3,
        OUTPUT,
        DBG_LED_4,
        OUTPUT,
		
		// RFBee settings
		0x02, // Address check and broad.
		0x01, // Base address 1
		0x00, // Broadcast
		0x07, // 10dBm
		0x00, // 9600
		0x03, // Transceiver
		0x00, // Default
		0x00,  // 76800 bps
		
		//! Possible RFbee commands stored.
		'+', '+', '+', '\r',
			
		'A', 'T', 'A', 'C', SPACE, '\r',
		'A', 'T', 'M', 'A', SPACE, '\r',
		'A', 'T', 'D', 'A', SPACE, '\r',
		'A', 'T', 'P', 'A', SPACE, '\r',
		'A', 'T', 'B', 'D', SPACE, '\r',
		'A', 'T', 'M', 'D', SPACE, '\r',
		'A', 'T', 'T', 'H', SPACE, '\r',
		'A', 'T', 'D', 'R', SPACE, '\r',
			
		'A', 'T', 'R', 'S', '\r',
		'A', 'T', 'F', 'V', '\r',
		'A', 'T', 'H', 'V', '\r'		
};

//! Load the saved args.
void NVRAM::load(void){
        // check for signature
        if (('f' != EEPROM.read(0)) ||
            ('s' != EEPROM.read(1))) {
                // load defaults
                memcpy_P(&nv, (void*)&nvram_default, sizeof(nv));
        } else {
                // load from NVRAM
                _loadx(2, sizeof(nv), &nv);
        }
}

//! Save the args
void NVRAM::save(void){
        // save to NVRAM
        _savex(2, sizeof(nv), &nv);

        EEPROM.write(0, 'f');
        EEPROM.write(1, 's');
}

//! Load bytes
void NVRAM::_loadx(uint8_t address, uint8_t size, void *value){
        uint8_t         *rp;

        rp = (uint8_t *)value;
        while (size--)
                *rp++ = EEPROM.read(address++);
}

//! Save bytes
void NVRAM::_savex(uint8_t address, uint8_t size, void *value){
        uint8_t         *rp;

        rp = (uint8_t *)value;
        while (size--)
        	EEPROM.write(address++, *rp++);
}

// Saves @ the specific address
void NVRAM::savex(byte address, byte size, void* value){
	_savex(address, size, value);
}



