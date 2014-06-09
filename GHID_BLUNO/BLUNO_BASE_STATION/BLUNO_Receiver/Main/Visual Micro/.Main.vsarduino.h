/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino Mega 2560 or Mega ADK, Platform=avr, Package=arduino
*/

#define __AVR_ATmega2560__
#define ARDUINO 101
#define ARDUINO_MAIN
#define F_CPU 16000000L
#define __AVR__
#define __cplusplus
extern "C" void __cxa_pure_virtual() {;}

//
//

#include "C:\Program Files\Arduino\hardware\arduino\variants\mega\pins_arduino.h" 
#include "C:\Program Files\Arduino\hardware\arduino\cores\arduino\arduino.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\Main.ino"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\BluetoothCommandDispatcher.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\BluetoothCommandDispatcher.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\BluetoothCommandIndexes.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\BluetoothCommandTable.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\BluetoothCommands.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\BluetoothConnectionCommands.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\BluetoothConnectionHandler.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\BluetoothConnectionHandler.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\BluetoothConnectionProtocol.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\ConnectionHandler.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\ConnectionProtocolHandler.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\ConnectionProtocolHandler.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\DFRobotBluetoothDriver.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\DFRobotBluetoothDriver.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\Dispatcher.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\Dispatcher.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\HardwareDefines.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\ProtocolDefinition.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\SystemMonitor.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\SystemMonitor.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\USBDeviceImplementation.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\USBDeviceImplementation.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\USBStructures.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\Utilities.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\Utilities.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\Watchdog.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\GHID_BLUNO\BLUNO_BASE_STATION\BLUNO_Receiver\Main\Watchdog.h"
