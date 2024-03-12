//Constants.h

#ifndef Constants_h 
#define Constants_h

//used in MotionCommands.ino to generate pwm signal to send Arduino 2
const int nPWM_PIN = 10;         //~D10
const int nPWM_FREQUENCY = 500; //Hz, 500 is default, I think max is 31KHz

//used in MotionCommands.ino to send state to send Arduino 2
const int nDIGITAL_OUTPUT_PIN_0 = 16;   //LSB
const int nDIGITAL_OUTPUT_PIN_1 = 20;   
const int nDIGITAL_OUTPUT_PIN_2 = 21;   


//used in MotionControls.ino to read analog signal (0V->3.3V) from low pass filter
const int nANALOG_INPUT_RESOLUTIION = 12;   //12 bit, 0..4095
const int nANALOG_INPUT_PIN = 15;           //D15/A1 

//used in MotionControls.ino to read state from Arduino 1
const int nDIGITAL_INPUT_PIN_0 = 9;     //LSB
const int nDIGITAL_INPUT_PIN_1 = 8;  
const int nDIGITAL_INPUT_PIN_2 = 7;   

//push button, Arduino
const int nPUSHPUTTON_PIN = 17;  

//used in class: Display
//const int SCREEN_WIDTH = 128; // OLED display width, in pixels
//const int SCREEN_HEIGHT = 32; // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
//const int  OLED_RESET = 4; // Reset pin # (or -1 if sharing Arduino reset pin)
//const int  SCREEN_ADDRESS = 0x3C; ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32


//used in class ....
const int IMAGE_WIDTH_PIXELS = 96;


//used in class: ....
//const float MAX_STRIDE_MM = 30.0;
const float MAX_STRIDE_MM = 60.0;
const float MIN_STRIDE_MM = 5.0; 

//used in class: ???--------------------------------------------
const int NECK_SERVO_NUMBER = 8;

//used in class: Walk---------------------------------------------------
const int NUM_SUB_STEP = 6;

//used in class: Leg--------------------------------------------------
//const float DELTA_Y = 6.0;   //amount leg is raised when walking
const float FOOT_ZERO_X_POS = 0.0;
const float FOOT_ZERO_Y_POS = -65.0;


//used in class: Link---------------------------------------------------


//----
const int RED = 22; 
const int BLUE = 24;
const int GREEN = 23;  

#endif