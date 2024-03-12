//Link_class_test_V0a

//really same as Servo_class_test.ino

#include "ServoSG90.h"

ServoSG90 m_ServoSG90;

//James Canova, jscanova@gmail.com
//created: 28 February 2024
//last updated: 28 February 2024

void setup() {
    float fDegrees;
    int nServoNum;

    nServoNum = 0;
  	m_ServoSG90.Initialize(nServoNum, true);

    fDegrees = 45;
	  m_ServoSG90.SetServoAngleInServoFrameDeg(fDegrees);	

}

void loop() {
  // put your main code here, to run repeatedly:

}
