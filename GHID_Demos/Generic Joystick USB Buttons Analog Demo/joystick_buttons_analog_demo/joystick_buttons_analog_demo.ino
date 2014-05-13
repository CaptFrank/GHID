/* Arduino USB Joystick HID demo */

/* Author: Francis Papineau
 * Released into the public domain.
 */

// Defines the number of axes that we will be using.
#define NUM_AXES		3	       // 8 axes, X, Y, Z, etc

// This is the number of inputs
#define NUM_INPUTS      5

// This is the hardware configurations
#define X_AXIS          1
#define Y_AXIS          0
#define BUTTON_A        5
#define BUTTON_B        3
#define BUTTON_C        4

/**
 * This is the definition of the joystick report structure.
 * This structure is responsible for containing the required
 * data pieces to send to the USB interpreter.
 */
typedef struct joyReport_t {

	// Declares the button definitions.
	// We use unions so we can define specifically each button
	// on the joystick.
    union {
    
      // Defining the buttons.
      struct{
        byte button_1 : 1;
        byte button_2 : 1;
        byte button_3 : 1;
        byte button_4 : 1;
        byte button_5 : 1;
        byte button_6 : 1;
        byte button_7 : 1;
        byte button_8 : 1;
      }buttons_bits;
      
      // We can also call the buttons as a group with this byte
      uint8_t buttons_byte;
    }buttons;
    
    // We define the axes of the joystick
    int8_t x;
    int8_t y;
    int8_t z;
    
    // We need a spacer to allow for less data corruption.
    uint8_t spacer;
};

// We declare a Joystick Report type variable
joyReport_t joyReport;

// Default function declarations.
void setup(void);
void loop(void);

/**
 * This is the setup of the device. We do all of the hardware configs,
 * in this function.
 *
 * \params void
 * \return void
 */
void setup() {
    
    // Set the initiale values of the axes
    joyReport.x = 0;
    joyReport.y = 0;
    joyReport.buttons.buttons_byte = 0;
 
 	// Set the hardware as INPUTS
    pinMode(X_AXIS, INPUT);
    pinMode(Y_AXIS, INPUT);
    pinMode(BUTTON_A, INPUT);
    pinMode(BUTTON_B, INPUT);
    pinMode(BUTTON_C, INPUT);

	// Starts the serial transport to the USB interpreter.
    Serial.begin(115200);
}


/**
 * This is the work function of the device. It is the one responsible 
 * in getting and processing the data from the hardware.
 *
 * \params void
 * \return void
 */
void loop() {

	// Delay 100ms 
    delay(100);
    
    // Check the buttons and assign a HIGH or LOW value to them
    if(digitalRead(BUTTON_A) == HIGH){
      joyReport.buttons.buttons_bits.button_1 &= 0;
    } else {
      joyReport.buttons.buttons_bits.button_1 |= 1;
    }
    
    if(digitalRead(BUTTON_B) == HIGH){
      joyReport.buttons.buttons_bits.button_2 &= 0;
    } else {
      joyReport.buttons.buttons_bits.button_2 |= 1;
    }
    
    if(digitalRead(BUTTON_C) == HIGH){
      joyReport.buttons.buttons_bits.button_3 &= 0;
    } else {
      joyReport.buttons.buttons_bits.button_3 |= 1;
    }
    
    // Get the values of the analog joystick and map them to a signed 
    // integer value between -100 to 100.
    joyReport.x = (int8_t) map(analogRead(X_AXIS), 0, 1023, -100, 100);
    joyReport.y = (int8_t) map(analogRead(Y_AXIS), 0, 1023, -100, 100);

	// We now send the Joystick Report to the USB interpreter
    Serial.write((uint8_t *)&joyReport, sizeof(joyReport_t));
    
    // We reset the buttons to allow for less artefacts to occur.
    joyReport.buttons.buttons_byte = 0;

}
