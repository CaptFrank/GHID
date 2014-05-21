/*
 * GHIDEEPROM.cpp
 *
 *  Created on: 2014-02-06
 *      Author: francispapineau
 */

#include "GHID_EEPROM.h"

//! The default constructor
GHID_EEPROM::GHID_EEPROM(){

	//! We check the file intergrity
	this->_check_file_system_integrity();

	//! We check if the file is full
	word check = this->_check_remianing_space();
	if( check == 0){
		this->filesystem_full = 1;
		this->space_remaining = 0;
		return;
	}else{
		this->space_remaining = check;
	}
}

//! Write data is not full
void GHID_EEPROM::write_data(int eeprom_ptr, byte* data, byte length){

	//! Check if full
	if((this->filesystem_full != 1) && ((this->space_remaining + length) <= MAX_FS_SIZE)){

		//! Write data
		for(register byte i = 0; i < length; i ++){
			this->write(eeprom_ptr + i, *(data) + i);
		}
		//! We update the space
		this->_update_space(length);
	}
}

//! Read data
void GHID_EEPROM::read_data(buffer_struct_t* buffer, int eeprom_ptr){

	//! Iterate the bytes
	for(register byte i = 0; i < buffer->length; i ++){

		//! Assign the data to the buffe struct
		buffer->buffer[i] = this->read(eeprom_ptr + i);
	}
}

//! Checks the file system integrity
void GHID_EEPROM::_check_file_system_integrity(){

	//! Container for the read bytes
	char header[2];

	//! Get the header
	header[0] = this->read(0);
	header[1] = this->read(1);

	//! Check with consolidated value
	if(strcmp(header, SIGNATURE) != 0){

		//! If not present, reformat the file
		this->_rewrite_header_wipe();
	}
}

//! Checks the remaining file length
word GHID_EEPROM::_check_remianing_space(){

	//! We start the walk from the first address.
	for(word i = 0; i < MAX_FS_SIZE; i ++){

		//! If their is no data in the cell
		if(this->read(i) == 0xFF){

			//! Add data to the remaining space.
			this->space_remaining ++;
		}
	}
}

//! Rewrites the header and wipes the data
void GHID_EEPROM::_rewrite_header_wipe(){

	//! Rewrite the header
	this->write(0, 'f');
	this->write(1, 's');

	//! We start the walk from the first address.
	for(word i = 0; i < MAX_FS_SIZE; i ++){

		//! If their is data in the cell
		if(this->read(i) != 0xFF){

			//! Wipe it
			this->write(i, 0xFF);
		}
	}
	//! We update the space
	this->_update_space(0);
}

//! Update the space remaining
void GHID_EEPROM::_update_space(byte length){

	//! Subtract the written amount
	this->space_remaining -= length;

	//! If the system is full
	if(this->space_remaining == MAX_FS_SIZE){
		this->filesystem_full = 1;
	}
}
