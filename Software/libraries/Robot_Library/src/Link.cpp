//Link.cpp

#include "Link.h"

//public
void Link::Begin()
{
	m_ServoSG90.Begin();	
}


void Link::Initialize(int nLinkNumber)
{	
	m_nServoNumber = nLinkNumber;
	
	if (nLinkNumber == 0 || nLinkNumber == 2 || nLinkNumber == 4 || nLinkNumber == 6)  //upper leg links
	{
		//upper link
		m_fMaxLinkAngleDeg = MAX_LINK_DEG_UPPER_LEG;	
		m_fLinkLength = UPPER_LEG_LENGTH_MM;
	} else {  //lower link
		m_fMaxLinkAngleDeg = MAX_LINK_DEG_LOWER_LEG;	
		m_fLinkLength = LOWER_LEG_LENGTH_MM;	
	}
	
	if (nLinkNumber == 0 || nLinkNumber == 1 || nLinkNumber == 2 || nLinkNumber == 3)   //starboard leg links	
	{	
		//starboard leg links	
		m_bAxisAligned = true;		
	} else { 		//port leg links
		m_bAxisAligned = false;		
	}		
	
    m_ServoSG90.Initialize(m_nServoNumber, m_bAxisAligned);	
}


float Link::GetLinkLength()
{
	return m_fLinkLength;
}


//private
void Link::SetLinkAngleDeg(float fDegrees)
{
	//fDegrees =  CheckLinkAngleLimitDeg(fDegrees);
	m_ServoSG90.SetServoAngleDeg(fDegrees);	
}



float Link::CheckLinkAngleLimitDeg(float fDegrees)
{

	if (fDegrees > m_fMaxLinkAngleDeg) {
		fDegrees = m_fMaxLinkAngleDeg;
	}
	
	if (fDegrees < -m_fMaxLinkAngleDeg) {
		fDegrees = -m_fMaxLinkAngleDeg;
	}	

	return fDegrees;
}
