//Link.cpp

#include "Link.h"

//function definitions
//public
void Link::Initialize(int nServoNumber, float fLength, bool bAxisAligned)
{	
	m_nServoNumber = nServoNumber;
	m_fLength = fLength;	
	m_bAxisAligned = bAxisAligned;
	
	if (nServoNumber == 0 || nServoNumber == 2 || nServoNumber == 3 || nServoNumber == 6)  //upper leg servo
	{
		m_fMaxServoAngle = 45.0;		
	} else {  //lower leg servo
		m_fMaxServoAngle = 30.0;			
	}
	
	m_ServoSG90.Initialize(nServoNumber, bAxisAligned);
}


//private
void Link::SetAngleInLegFrame(float fDegrees)
{
	fDegrees =  CheckServoAngleLimit(fDegrees);
	m_ServoSG90.SetServoAngleInServoFrameDeg(fDegrees);	
}

float Link::CheckServoAngleLimit(float fDegrees)
{

	if (fDegrees > m_fMaxServoAngle) {
		fDegrees = m_fMaxServoAngle;
	}
	
	if (fDegrees < -m_fMaxServoAngle) {
		fDegrees = -m_fMaxServoAngle;
	}	

	return fDegrees;
}