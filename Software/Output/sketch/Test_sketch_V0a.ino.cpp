#include <Arduino.h>
#line 1 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/Test_sketch_V0a/Test_sketch_V0a.ino"
//Test_sketch_V0a.ino


#include "../../libraries/Adafruit_PWM_Servo_Driver_Library/Adafruit_PWMServoDriver.h"


#include "Constants.h"

Adafruit_PWMServoDriver m_PWM;

void setup()
{

	m_PWM.begin();
	m_PWM.setOscillatorFrequency(OSCILLATOR_FREQ);
	m_PWM.setPWMFreq(SERVO_FREQ); 


}


void loop() {

}
