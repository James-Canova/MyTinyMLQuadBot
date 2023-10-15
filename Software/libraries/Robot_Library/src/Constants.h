//Constants.h


//used in class: Path---------------------------------------------------
const float MAX_STRIDE_MM = 30.0;
const float MIN_STRIDE_MM = 5.0; 

//used in class: ???--------------------------------------------
const int NECK_SERVO_NUMBER = 8;

//used in class: Walk---------------------------------------------------
const int NUM_SUB_STEP = 6;

//used in class: Leg--------------------------------------------------
const float DELTA_Y = 6.0;   //amount leg is raised when walking
const float FOOT_ZERO_X_POS = 0.0;
const float FOOT_ZERO_Y_POS = -71.0;


//used in class: Link---------------------------------------------------
const float MAX_MAG_SERVO_DEG_UPPER_LEG  = 45.0;      
const float MAX_MAG_SERVO_DEG_LOWER_LEG  = 30.0;     

//used in class: Link,Leg and Quadraped in Stand function--------
const float UPPER_LEG_LENGTH_MM = 40.0;
const float LOWER_LEG_LENGTH_MM = 33.0;


//used in class: ServoSG90---------------------------------------------------
const int SERVO_FREQ = 50.0;   //Hz,  // Analog servos run at ~50 Hz updates
const int OSCILLATOR_FREQ  = 27000000;   //Hz

// This is the minimum pulse length count (out of 4096) for servos
//corresponds to +90 [deg] (clockwise) accordiong to manufactures definitions of + angle
const float PULSELEN_MIN  = 100.0;

// This is the maximum pulse length count (out of 4096)  for servos
//corresponds to -90 [deg] (counter-clockwise) accordiong to manufactures definitions of + angle
const float PULSELEN_MAX = 645.0;


