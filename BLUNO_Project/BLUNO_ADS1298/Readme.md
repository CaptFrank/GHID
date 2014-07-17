	
	
Parts needed:
	- 2x bluno
	- ADS1298
	- Logic level Converter
	- Hookup cable
	- USB cable
	- Arduino IDE
	
Setup Instructions:

	*** Note: this is the setup guide to setting the ADS1298 as a bluetooth serial
		device.
	
	This document is a basic step-by-step guide to setting up the bluno system
	with the ADS1298:
		
		1- Set up a bluno based on the configurations listed within the 
			bluno to bluno configuration readme (found in BLUNO_BLUNO/Doc/ folder).
			- You can skip this step if you wish to leave the configurations as 
			defaults.
			
				- You must have one bluno set as a central node.
					- This will be the loopback node.
					
				- You must have one bluno set as a peripheral node.
					- This will be the sensor node.
			
		2.1- Next, assuming the setup went well, you need to upload the Main.ino file that
			you wish on the sensor node. You can either choose the Polling or 
			the Interrupt program. The Interrupt program requires the 
			setting up of the DRDY signal on the bluno.
			(Follow the pin map below)
			
		2.2- The loopback node needs to be burnt with the appropriate firmware. This can
			be found in the follwoing folder. (BLUNO_BLUNO/Src/) Here you can choose
			weather the serial output will be structured or not. (Look for a .ino file
			as the main file to upload using the Arduino IDE)
			
		3- Once you have uploaded the firmware, the devices need to be reset.
		
		4- Once reset the devices should start by linking to the other bluno and a link
			led light should turn on.
			
		5- Once linked and addressed the data should start flowing on the secondary bluno.
		
Pin Map:
	
	FUNCTION		BLUNO PIN 		(5V) Level Converter (3.3V)			ADS1298
		
		MISO			12 ------------------> | ************************> Yellow
		MOSI			11 ------------------> | ************************> Green
		SCLK			13 ------------------> | ************************> Purple
		SS				10 ------------------> | ************************> Blue
		 
		DRDY			3 -----------------------------------------------> Orange
		
		GND				GND -----------------> |
							---------------------------------------------> Brown
		3.3V			3.3V ----------------> |
							---------------------------------------------> Red
							
		*** Note: the Header that has teh GND and the 3.3V Rails needs to be connected to 
		the connector J4 and the Signals header must be conencted to the connector J3. 
		The ECG leads must be connected to the J1 connector.