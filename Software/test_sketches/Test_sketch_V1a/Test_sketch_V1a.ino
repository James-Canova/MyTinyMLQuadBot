//Test_sketch_V1a.ino

//30 October 2023

#include <Adafruit_PWMServoDriver.h>
#include "Constants.h"
#include "MotionCommandWriteUtility.h"

Adafruit_PWMServoDriver m_PWM;

void setup()
{
	m_PWM.begin();
	m_PWM.setOscillatorFrequency(OSCILLATOR_FREQ);
	m_PWM.setPWMFreq(SERVO_FREQ); 
}

void loop() {


}
