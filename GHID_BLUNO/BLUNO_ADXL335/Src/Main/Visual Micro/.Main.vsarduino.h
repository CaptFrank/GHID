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
void loop(void);

#include "C:\Program Files\Arduino\hardware\arduino\variants\standard\pins_arduino.h" 
#include "C:\Program Files\Arduino\hardware\arduino\cores\arduino\arduino.h"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\Main.ino"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\ADXL335.cpp"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\ADXL335.h"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\ADXL335Driver.cpp"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\ADXL335Driver.h"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\BluetoothCommandDispatcher.cpp"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\BluetoothCommandDispatcher.h"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\BluetoothCommandIndexes.h"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\BluetoothCommandTable.h"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\BluetoothCommands.h"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\BluetoothConnectionCommands.h"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\BluetoothConnectionHandler.cpp"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\BluetoothConnectionHandler.h"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\CC2540Driver.cpp"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\CC2540Driver.h"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\ConnectionHandler.h"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\ConnectionProtocolHandler.cpp"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\ConnectionProtocolHandler.h"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\DataProcessor.cpp"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\DataProcessor.h"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\Dispatcher.cpp"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\Dispatcher.h"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\Main.cpp"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\ProtocolDefinition.h"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\RingBuffer.h"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\UserDefines.h"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\Utilities.cpp"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\Utilities.h"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\Watchdog.cpp"
#include "Z:\GHID - Beta\GHID\GHID_BLUNO\BLUNO_ADXL335\Src\Main\Watchdog.h"
