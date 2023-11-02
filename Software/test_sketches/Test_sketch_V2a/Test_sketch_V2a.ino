//Test_sketch_V2a.ino

#include "ServoSG90.h"

ServoSG90 m_Servo;

void setup()
{
    int nServoNumber = 8;
	m_Servo.Initialize(nServoNumber, true);
}

void loop() {

    float fDegrees = -30.0;
    m_Servo.SetServoAngleInServoFrameDeg(fDegrees);

}
