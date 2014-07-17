	
	
Parts needed:
	- 2x bluno
	- USB cable
	- Arduino IDE
	
Setup Instructions:

	*** Note: this is the setup guide to setting the Bluno as a bluetooth serial
		device.
	
	This document is a basic step-by-step guide to setting up the bluno system:
		
		1- Set up a bluno based on the configurations listed within the 
			bluno to bluno configuration readme (found in BLUNO_BLUNO/Doc/ folder).
			- You can skip this step if you wish to leave the configurations as 
			defaults.
			
				- You must have one bluno set as a central node.
					- This will be the loopback node.
					
				- You must have one bluno set as a peripheral node.
					- This will be the sensor node.
					
		2.1- The sensor node can be anything and only has to be able to stream serial
			data as an output. The data can be anything and can be structured any how. 
			This step is where the user would upload his custom code to the bluno
			that will be concidered the central device.
			
		2.2- The loopback node needs to be burnt with the appropriate firmware. This can
			be found in the follwoing folder. (BLUNO_BLUNO/Src/) Here you can choose
			weather the serial output will be structured or not. (Look for a .ino file
			as the main file to upload using the Arduino IDE)
			
		3- Once you have uploaded the firmware, the devices need to be reset.
		
		4- Once reset the devices should start by linking to the other bluno and a link
			led light should turn on.
			
		5- Once linked and addressed the data should start flowing on the secondary bluno.
		
Pin Map:
	
	FUNCTION		BLUNO PIN 		(5V) Level Converter (3.3V)				BLUNO
		
		NA				NA						NA							NA