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
//
void execute(void);

#include "C:\Program Files\Arduino\hardware\arduino\variants\standard\pins_arduino.h" 
#include "C:\Program Files\Arduino\hardware\arduino\cores\arduino\arduino.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\Main.ino"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\ADS1298Commands.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\ADS1298Driver.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\ADS1298Driver.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\BluetoothCommandDispatcher.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\BluetoothCommandDispatcher.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\BluetoothCommandIndexes.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\BluetoothCommandTable.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\BluetoothCommands.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\BluetoothConnectionCommands.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\BluetoothConnectionHandler.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\BluetoothConnectionHandler.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\CC2540Driver.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\CC2540Driver.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\ConnectionHandler.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\ConnectionProtocolHandler.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\ConnectionProtocolHandler.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\DataProcessor.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\DataProcessor.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\Dispatcher.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\Dispatcher.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\RingBuffer.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\SPI.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\SPI.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\Utilities.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_ADS1298\Src\Polling_Driven\Main\Utilities.h"
