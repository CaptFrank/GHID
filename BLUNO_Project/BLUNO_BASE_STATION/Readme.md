
Parts needed:
	- Arduino Mega
	- BLE Sheild
	- USB cable
	- Arduino IDE
	
Setup Instructions:

	*** Note: this is the setup guide to setting the arduino mega and the BLE sheild
		as a bluetooth serial GHID device.
	
	This document is a basic step-by-step guide to setting up the GHID system recevier:
		
		1- Upload the receiver firmware wanted:
			- Either the receiver with callbacks or the receiver without callbacks.
					
					- Callback Commands:
						- Connect		=> C
						- Diconnect		=> D
						- Reboot		=> R
			
			- These firmwares can be found in the directories within this project.
			
		2- Upload the USB firmware that is needed. (Only the mouse and the jostick ones
			were tested and deployed).
			
		3- Reboot the device.
		
		4- Connect a central device to the Peripheral device enumerated as Bluno0.8V
			- Follow the bluno AT commands to setup or leave as defaults.
			
		5- After being connected the link light appers and the device is now connected 
			to receive commands an data. For further infromation regarding the type 
			of commands and the data format that is accepted please review the following
			files:
					- Data protocol: ProtocolDefiniton.h
					- Commands: BluetoothConnectionProtocol.h