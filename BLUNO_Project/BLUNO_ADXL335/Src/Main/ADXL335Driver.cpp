/*
 * ADXL335Driver.cpp
 *
 * Created: 5/21/2014 1:10:12 PM
 *  Author: Administrator
 */ 
/*
 * ADXL335Driver.cpp
 *
 * Created: 5/21/2014 1:10:40 PM
 *  Author: Administrator
 */

#include "ADXL335Driver.h"

//! Public Context

/**
 * This is the default constructor for the class. A pin map
 * is passed to the constructor to allow for setting up of the device.
 *
 * @param pin_map							- MMA7361L_pin_map_t*
 */
ADXL335_Driver::ADXL335_Driver(ADXL335_pin_map_t* pin_map, double ref){

	//! We set the internal pin map reference
	this->_pin_map = pin_map;

	//! Set the reference voltage
	this->_ref = ref;
}

/**
 * This is the pin setup method.
 */
void ADXL335_Driver::begin(){

	//! We create the accelerometer object
	this->_accel = new ADXL335(this->_pin_map->x_pin, 
							   this->_pin_map->y_pin, 
							   this->_pin_map->z_pin, 
							   this->_ref);
}

/**
 *	This method runs the ADC thread
 *
 * @param buff								- The RingBuff type
 */
void ADXL335_Driver::run(RingBuff_t* buff){
	
	//! Containers
	int x_axis;
	int y_axis;
	int z_axis;	
	
	//! We get all axis values
	x_axis = this->get_accel(X_AXIS);
	delay(10);
	y_axis = this->get_accel(Y_AXIS);
	delay(10);
	z_axis = this->get_accel(Z_AXIS);
	delay(10);
	
	//! Create a data container
	uint8_t _data[SIZE_OF_DATA] = {x_axis, y_axis, z_axis, 0x00};
	
	//! We put the data into the ringbuffer
	for(uint8_t i = 0; i < sizeof(_data); i++){
		RingBuffer_Insert(buff, _data[i]);
	}
}

/**
 * This is a method that gets the raw selected axis value.
 *
 * @param axis								- The axis needed to be measured
 * @return int								- The analog value
 */
int ADXL335_Driver::get_raw(axis_t axis){

	//! We read the raw value of the axis defined
	switch(axis){

		case X_AXIS:
			return analogRead(this->_pin_map->x_pin);

		case Y_AXIS:
			return analogRead(this->_pin_map->y_pin);

		case Z_AXIS:
			return analogRead(this->_pin_map->z_pin);

		//! Nothing to do
		default:
			return 0;
	}

}

/**
 * This is a method that gets the voltage of the selected axis.
 *
 * @param axis								- The axis needed to be measured
 * @return int								- The analog value
 */
int ADXL335_Driver::get_volt(axis_t axis){
		return this->_mapADXL335V(this->get_raw(axis));
}

/**
 * This is a method that gets the accelerometer value of the selected axis.
 *
 * @param axis								- The axis needed to be measured
 * @return int								- The analog value
 */
int ADXL335_Driver::get_accel(axis_t axis){

	//! We update the accelerometer values
	this->_accel->update();
	
	//! Temp data
	float value;

	//! We read the raw value of the axis defined
	switch(axis){

		case X_AXIS:
		value = this->_accel->getX();
		break;

		case Y_AXIS:
		value = this->_accel->getY();
		break;

		case Z_AXIS:
		value = this->_accel->getZ();
		break;

		//! Nothing to do
		default:
		return 0;
	}
	
	//! Map the input to a value
	return this->_mapADXL335G(value * 100.00);
}

/**
 * This method does all conversions and returns the values.
 *
 * @param _XAxis							- The x axis value
 * @param _YAxis							- The y axis value
 * @param _ZAxis							- The z axis value
 */
void ADXL335_Driver::get_accel_xyz(int *_XAxis, int *_YAxis, int *_ZAxis){

	*_XAxis = this->get_accel(X_AXIS);
	*_YAxis = this->get_accel(Y_AXIS);
	*_ZAxis = this->get_accel(Z_AXIS);

}

/**
 * This gets the total vector of the 3 components.
 *
 * @return int								- The total vector
 */
int ADXL335_Driver::get_total_vector(){

	return sqrt(square(this->_mapADXL335G(this->get_accel(X_AXIS))) +
				square(this->_mapADXL335G(this->get_accel(Y_AXIS))) +
				square(this->_mapADXL335G(this->get_accel(Z_AXIS))));

}

//! Private Context

/**
 * This maps a voltage value to an integer value
 *
 * @param value								- The read voltage
 * @return int								- The mapped value
 */
int ADXL335_Driver::_mapADXL335V(int value){

	//! Switch on the reference voltage
	if (this->_ref == V_3V){

		return map(value,0,1024,0,3300);

	}else{

		return map(value,0,1024,0,5000);
	}
}

/**
 * This maps a gravity value to an integer value
 *
 * @param value								- The read value
 * @return int								- The mapped value
 */
int ADXL335_Driver::_mapADXL335G(int value){
	return map(value,-120.00,120.00,(-MAX_AXIS_VALUE),(MAX_AXIS_VALUE));
}
