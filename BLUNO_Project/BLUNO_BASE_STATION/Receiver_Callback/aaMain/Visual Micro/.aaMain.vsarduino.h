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
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\aaMain.ino"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\BluetoothConnectionCommands.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\BluetoothConnectionHandler.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\BluetoothConnectionHandler.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\BluetoothConnectionProtocol.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\ByteBuffer.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\ByteBuffer.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\ConnectionHandler.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\ConnectionProtocolHandler.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\ConnectionProtocolHandler.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\HardwareDefines.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\NRF8001Driver.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\NRF8001Driver.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\NRF8001ServiceLocks.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\NRF8001Services.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\NRF8001UARTOverBLE.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\ProtocolDefinition.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\SystemMonitor.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\SystemMonitor.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\USBDeviceImplementation.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\USBDeviceImplementation.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\USBStructures.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\Utilities.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\Utilities.h"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\Watchdog.cpp"
#include "\\vmware-host\Shared Folders\GHID - Beta\GHID\BLUNO_Project\BLUNO_BASE_STATION\Receiver_Callback\aaMain\Watchdog.h"
