/*
 * GHIDEEPROM.h
 *
 *  Created on: 2014-02-06
 *      Author: francispapineau
 */

#ifndef GHIDEEPROM_H_
#define GHIDEEPROM_H_

#include <EEPROM.h>

//! Max buffer size
#define MAX_BUFFER	255

//! Max FS size
#define MAX_FS_SIZE 4000

//! The file signature
#define SIGNATURE	"fs"

//! Buffer structure
struct buffer_struct_t {

	byte length;
	byte buffer[MAX_BUFFER];
};

/**
 * This class is an override of the Arduino EEPROM class, which handles,
 * the eeprom reading and writing on the internal Arduino eeprom.
 *
 * @see EEPROMClass.h
 */
class GHID_EEPROM : public EEPROMClass{

	//! Public context
	public:

	/**
	 * The default constructor.
	 * In the default constructor, we check the filesystem integrity,
	 * and the remaining space.
	 */
	GHID_EEPROM();

	/**
	 * The extended class has 2 methods that are used.
	 * 	- read(eeprom_address)
	 * 		- The eeprom address parameter is the address of
	 * 		the eeprom that we wish to read.
	 *
	 * 	- write(eeprom_address, data)
	 * 		- The eeprom address parameter that we wish to write to.
	 * 		- The data is the data that we wish to write to the eeprom.
	 *
	 * 	Note: these 2 methods override the full flag.
	 */

	// ------------------------------------------------------------------------

	/**
	 * The following method is essentially the same method, provided
	 * by the EEPROMClass API, but instead it uses a byte* and a length.
	 * This method is advantageous, as it throws less data on the stack.
	 *
	 * @param eeprom_ptr - byte data address at which we will write the data to
	 * @param data - byte* data pointer
	 * @param length - byte length of data to write.
	 */
	void write_data(int eeprom_ptr, byte* data, byte length);


	/**
	 * The following is a method that also follows the same path as the given
	 * read() function in the EEPROMClass API, but instead of reading a byte at
	 * a time, we read a certain number of bytes into a buffer.
	 *
	 * @param buffer_struct_t* - a pointer to a buffer structure
	 * @param eeprom_ptr - the start address to read
	 */
	void read_data(buffer_struct_t* buffer, int eeprom_ptr);

	//! Private Context
	private:

	/**
	 * This method is a local reset switch. It resets the device to
	 * address 0.
	 */
	void (*reset)(void) = 0;

	/**
	 * This is the flag that indicates that the file system is full;
	 */
	byte filesystem_full = 0;

	/**
	 * This is the space remaining in the file system.
	 */
	word space_remaining = MAX_FS_SIZE;

	/**
	 * This method is implemented, to see if the filesystem has been corrupted
	 * or if it is still in good state. If the file system is corrupt, the system
	 * reboots.
	 *
	 * This method essentially checks if the first 2 bytes of the filesystem are
	 * 'f','s', which are the filesystem header.
	 */
	void _check_file_system_integrity();

	/**
	 * This returns the remaining space in the fielsystem.
	 */
	word _check_remianing_space();

	/**
	 * This method rewrites the filesystem header and wipes the eeprom.
	 */
	void _rewrite_header_wipe();

	/**
	 * This method updates the space remaining in the file system.
	 */
	void _update_space(byte length);


};

#endif /* GHIDEEPROM_H_ */
