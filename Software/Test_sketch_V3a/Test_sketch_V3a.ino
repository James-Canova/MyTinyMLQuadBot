//Test_sketch_V3a.ino

#include "Link.h"
#include "Constants.h"

Link m_Link;

void setup()
{
NECK_LENGTH_MM
    int nServoNumber = 8;
	m_Servo.Initialize(nServoNumber, true);


		void Initialize(int nServoNumber, float fLength, bool bAxisAligned);

		void SetAngleInLegFrame(float fAngleDeg);
				    
}

void loop() {

    float fDegrees = -30.0;
    m_Servo.SetServoAngleInServoFrameDeg(fDegrees);

}
