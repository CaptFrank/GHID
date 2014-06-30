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
#define _VMDEBUG 1
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
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\aaMain.ino"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\BluetoothConnectionCommands.h"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\BluetoothConnectionHandler.cpp"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\BluetoothConnectionHandler.h"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\BluetoothConnectionProtocol.h"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\ByteBuffer.cpp"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\ByteBuffer.h"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\ConnectionHandler.h"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\ConnectionProtocolHandler.cpp"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\ConnectionProtocolHandler.h"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\HardwareDefines.h"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\NRF8001Driver.cpp"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\NRF8001Driver.h"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\NRF8001ServiceLocks.h"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\NRF8001Services.h"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\NRF8001UARTOverBLE.h"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\ProtocolDefinition.h"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\SystemMonitor.cpp"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\SystemMonitor.h"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\USBDeviceImplementation.cpp"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\USBDeviceImplementation.h"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\USBStructures.h"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\Utilities.cpp"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\Utilities.h"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\Watchdog.cpp"
#include "Z:\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver\aaMain\Watchdog.h"
