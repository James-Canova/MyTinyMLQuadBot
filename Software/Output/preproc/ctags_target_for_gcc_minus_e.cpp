# 1 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/Test_sketch_V0a/Test_sketch_V0a.ino"
//Test_sketch_V0a.ino


# 5 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/Test_sketch_V0a/Test_sketch_V0a.ino" 2


# 8 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/Test_sketch_V0a/Test_sketch_V0a.ino" 2

Adafruit_PWMServoDriver m_PWM;

void setup()
{

 m_PWM.begin();
 m_PWM.setOscillatorFrequency(OSCILLATOR_FREQ);
 m_PWM.setPWMFreq(SERVO_FREQ);


}


void loop() {

}
