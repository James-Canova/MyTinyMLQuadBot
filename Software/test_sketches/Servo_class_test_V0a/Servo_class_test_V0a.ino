//Servo_class_test_V0a.ino

//centre all servos and then swing all servos one at a time

//based on Servo_test_V0a.ino and link class

//*****CURRENTLY ONLY SETUP FOR 1 SERVO*****

//modified by: James Canova, jscanova@gmail.com
//created:13 December 2022
//last updated: 27 February 2024

#include <ServoSG90.h>

//CCW is '+' and CW is '-'
//starboard servos are bAxisAligned
//port servos are not aligned

ServoSG90  m_ServoSG90 = ServoSG90();

int nCount = 0;

int const DELAY = 250;
float const SERVOMIN_DEG = -45;
float const SERVOMAX_DEG = 45;
int const ANGLE_INC_DEG = 5;


//Setup----------------------------------------------
void setup() {

  Serial.begin(9600);

  m_ServoSG90.Begin();

  delay(DELAY);  
}

//Main loop---------------------------------------------------
void loop() {

  Serial.println("Main loop.");
  //initialize variables
  uint8_t nServoNum;
  int nAngleDeg; 

  if (nCount < 1)
  {
    int nServoNumber = 0;
    bool bAxisAligned = true;

    m_ServoSG90.Initialize(nServoNumber, bAxisAligned);

    nCount ++;
  }

  //Swing servos one at a time. Angle = SERVOMIN_DEG[deg] to SERVOMAX_DEG[deg]-----
  //just servos 0 for now
  for (nServoNum = 0; nServoNum < 1; nServoNum++) {
      for (nAngleDeg = 0; nAngleDeg <= SERVOMAX_DEG; nAngleDeg = nAngleDeg + ANGLE_INC_DEG) {
        m_ServoSG90.SetServoAngleDeg(nAngleDeg);	
        delay(DELAY);
        }

      //all the way back the other way
      for (int nAngleDeg = SERVOMAX_DEG; nAngleDeg >= SERVOMIN_DEG; nAngleDeg = nAngleDeg - ANGLE_INC_DEG) {
        m_ServoSG90.SetServoAngleDeg(nAngleDeg);	
        delay(DELAY);        
        }  

      //back to center
      for (int nAngleDeg = SERVOMIN_DEG; nAngleDeg <= 0; nAngleDeg = nAngleDeg + ANGLE_INC_DEG) {
        m_ServoSG90.SetServoAngleDeg(nAngleDeg);	
        delay(DELAY);        
        } 
  
    }
   
    delay(DELAY);

    //exit(0);

}   //end of main loop----------------------------------------------




