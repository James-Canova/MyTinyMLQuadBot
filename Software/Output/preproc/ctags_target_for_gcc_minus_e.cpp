# 1 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/Test_sketch_V2a/Test_sketch_V2a.ino"
//Test_sketch_V2a.ino

# 4 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/Test_sketch_V2a/Test_sketch_V2a.ino" 2

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
