
	This is the very basic application that runs within the 
	Bluno processor to allow for communication between either
	of the following combinations:
	
		- BLUNO <-> BLUNO
		- BLUNO <-> PHONE / PC
	
	In order to make sure that these Bluno communicate together properly,
	the following AT command sequence must be executed on the BLE chip (in AT mode). 
	This allows for appropriate association between each Bluno or the phone and the Bluno.
	
	After the AT mode settings complete, the device should retain the settings within EEPROM. 
	This means that the device does not have to be reconfigured each reboot. After this, the 
	application named BLUNO_Relay.ino can be loaded on the device.
	
	Here are the AT commands based on each scenario listed above:
	
		- BLUNO <-> BLUNO
			
			- BLUNO #1:
			
				// Enter the AT command mode via the following settings:
					
					- Enter the following AT mode commands to set-up the first Bluno:
						
						**** Terminal settings change ****
							- Terminal settings:
								- BAUD = 115200
								- Line ending = No \n or \r
						
						- '+++'
						
						**** Terminal settings change ****
							- Terminal settings:
								- BAUD = 115200
								- Line ending = \n\r
						
						- 'AT+FSM=FSM_TRANS_USB_COM_BLE'
						- 'AT+ROLE=ROLE_CENTRAL'
						- 'AT+BIND=<ADDRESS>' <--- 
							- Where <ADDRESS> is the address of the peripheral to connect to
						- 'AT+CMODE=UNIQUE'
						- 'AT+SETTING=DEFCENTRAL'
						- 'AT+RESTART'
			
			- BLUNO #2:
			
				// Enter the AT command mode via the following settings:
					
					- Enter the following AT mode commands to set-up the first Bluno:
						
						**** Terminal settings change ****
							- Terminal settings:
								- BAUD = 115200
								- Line ending = No \n or \r
						
						- '+++'
						
						**** Terminal settings change ****
							- Terminal settings:
								- BAUD = 115200
								- Line ending = \n\r
						
						- 'AT+FSM=FSM_TRANS_USB_COM_BLE'
						- 'AT+ROLE=ROLE_PERIPHERAL'
						- 'AT+BIND=<ADDRESS>' <--- 
							- Where <ADDRESS> is the address of the peripheral to connect to
						- 'AT+CMODE=ANYONE'
						- 'AT+SETTING=DEFPERIPHERAL'
						- 'AT+RESTART'
			
		- BLUNO <-> PHONE / PC
			
			- BLUNO:
				
				- The Bluno must be set-up as a Peripheral. 
				- The commands listed above for the Bluno #2 must be followed.
			
			- PC / PHONE:
			
				- Scan for the Bluno advertisement.
				- Connect to the Bluno