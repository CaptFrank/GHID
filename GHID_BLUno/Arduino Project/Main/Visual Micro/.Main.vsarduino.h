/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino Uno, Platform=avr, Package=arduino
*/

#define __AVR_ATmega328p__
#define __AVR_ATmega328P__
#define ARDUINO 101
#define ARDUINO_MAIN
#define F_CPU 16000000L
#define __AVR__
#define __cplusplus
extern "C" void __cxa_pure_virtual() {;}

void setup(void);
//
void start_device(void);
void stop_device(void);

#include "C:\Program Files\Arduino\hardware\arduino\variants\standard\pins_arduino.h" 
#include "C:\Program Files\Arduino\hardware\arduino\cores\arduino\arduino.h"
#include "Z:\GHID_BLUno\Arduino Project\Main\Main.ino"
#include "Z:\GHID_BLUno\Arduino Project\Main\ADS1298Commands.h"
#include "Z:\GHID_BLUno\Arduino Project\Main\ADS1298Driver.cpp"
#include "Z:\GHID_BLUno\Arduino Project\Main\ADS1298Driver.h"
#include "Z:\GHID_BLUno\Arduino Project\Main\BluetoothCommandDispatcher.cpp"
#include "Z:\GHID_BLUno\Arduino Project\Main\BluetoothCommandDispatcher.h"
#include "Z:\GHID_BLUno\Arduino Project\Main\BluetoothCommandTable.h"
#include "Z:\GHID_BLUno\Arduino Project\Main\BluetoothCommands.h"
#include "Z:\GHID_BLUno\Arduino Project\Main\BluetoothConnectionCommands.h"
#include "Z:\GHID_BLUno\Arduino Project\Main\BluetoothConnectionHandler.cpp"
#include "Z:\GHID_BLUno\Arduino Project\Main\BluetoothConnectionHandler.h"
#include "Z:\GHID_BLUno\Arduino Project\Main\CC2540Driver.cpp"
#include "Z:\GHID_BLUno\Arduino Project\Main\CC2540Driver.h"
#include "Z:\GHID_BLUno\Arduino Project\Main\ConnectionHandler.h"
#include "Z:\GHID_BLUno\Arduino Project\Main\ConnectionProtocolHandler.cpp"
#include "Z:\GHID_BLUno\Arduino Project\Main\ConnectionProtocolHandler.h"
#include "Z:\GHID_BLUno\Arduino Project\Main\DataProcessor.cpp"
#include "Z:\GHID_BLUno\Arduino Project\Main\DataProcessor.h"
#include "Z:\GHID_BLUno\Arduino Project\Main\Dispatcher.cpp"
#include "Z:\GHID_BLUno\Arduino Project\Main\Dispatcher.h"
#include "Z:\GHID_BLUno\Arduino Project\Main\GHID_SPI.cpp"
#include "Z:\GHID_BLUno\Arduino Project\Main\GHID_SPI.h"
#include "Z:\GHID_BLUno\Arduino Project\Main\RingBuffer.h"
