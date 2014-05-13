/*
 * NVRAM_API.cpp
 *
 *  Created on: Jul 25, 2013
 *      Author: fjpapin
 */

#include "NVRAM_API.h"
#include "Hardware_Defines.h"

#define SPACE 	0x00

//! Define the structure
const NVRAM::nv_data_t nvram_default PROGMEM = {

        9600,
        9600,
        9600,
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
		
		0x01 // Set default params on the Bluetooth chip
		
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



