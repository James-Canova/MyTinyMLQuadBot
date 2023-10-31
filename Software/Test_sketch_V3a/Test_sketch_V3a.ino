//Test_sketch_V3a.ino

#include "Link.h"
#include "Constants.h"

Link m_Link;

void setup()
{
    int nServoNumber = 8;
    float fLength = NECK_LENGTH_MM;
    bool bAxisAligned = true; 

    m_Link.Initialize(nServoNumber, fLength, bAxisAligned);

    float fAngleDeg = 30.0;
	m_Link.SetAngleInLegFrame(fAngleDeg);
				    
}

void loop() {

    float fDegrees = -30.0;
    m_Servo.SetServoAngleInServoFrameDeg(fDegrees);

}
