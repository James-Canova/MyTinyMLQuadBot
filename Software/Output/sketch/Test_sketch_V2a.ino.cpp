#include <Arduino.h>
#line 1 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/Test_sketch_V2a/Test_sketch_V2a.ino"
//Test_sketch_V2a.ino

#include "ServoSG90.h"

ServoSG90 m_Servo;

#line 7 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/Test_sketch_V2a/Test_sketch_V2a.ino"
void setup();
#line 13 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/Test_sketch_V2a/Test_sketch_V2a.ino"
void loop();
#line 7 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/Test_sketch_V2a/Test_sketch_V2a.ino"
void setup()
{
    int nServoNumber = 8;
	m_Servo.Initialize(nServoNumber, true);
}

void loop() {

    float fDegrees = -30.0;
    m_Servo.SetServoAngleInServoFrameDeg(fDegrees);

}

