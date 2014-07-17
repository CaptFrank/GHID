	
	
Parts needed:
	- 2x bluno
	- MMA7361L
	- Hookup cable
	- USB cable
	- Arduino IDE
	
Setup Instructions:

	*** Note: this is the setup guide to setting the MMA7361L as a bluetooth serial
		device.
	
	This document is a basic step-by-step guide to setting up the bluno system
	with the MMA7361L:
		
		1- Set up a bluno based on the configurations listed within the 
			bluno to bluno configuration readme (found in BLUNO_BLUNO/Doc/ folder).
			- You can skip this step if you wish to leave the configurations as 
			defaults.
			
				- You must have one bluno set as a central node.
					- This will be the loopback node.
					
				- You must have one bluno set as a peripheral node.
					- This will be the sensor node.
			
		2.1- Next, assuming the setup went well, you need to upload the Main.ino file that
			you wish on the sensor node.
			
		2.2- The loopback node needs to be burnt with the appropriate firmware. This can
			be found in the follwoing folder. (BLUNO_BLUNO/Src/) Here you can choose
			weather the serial output will be structured or not. (Look for a .ino file
			as the main file to upload using the Arduino IDE)
			
		3- Once you have uploaded the firmware, the devices need to be reset.
		
		4- Once reset the devices should start by linking to the other bluno and a link
			led light should turn on.
			
		5- Once linked and addressed the data should start flowwing on the secondary bluno.
		
Pin Map:
	
	FUNCTION		BLUNO PIN											MMA7361L
		
		GND				GND ---------------------------------------------> GND
		5V				5V	---------------------------------------------> V+
		
		X				A0 	---------------------------------------------> X
		Y				A1	---------------------------------------------> Y
		Z				A2	---------------------------------------------> Z
		
		SLEEP			D3	---------------------------------------------> SLEEP
		STATUS			D4	---------------------------------------------> ST
		0G				D5	---------------------------------------------> 0G
		G_SELECT		D6	---------------------------------------------> G
						