//Neck.cpp

#include "Neck.h"

//function declarations
//public----
void Neck::Initialize(int nServoNumber, bool bAxisAligned)
{
	m_nServoNumber = nServoNumber;
	m_AxisAligned = bAxisAligned;
	
	aServoSG90.Initialize(nServoNumber, bAxisAligned);
	
}

void Neck::SetServoAngleInServoFrameDeg(float fAngleDegrees)   //CCW = +   		
{
	m_fAngleDegrees = fAngleDegrees;
	aServoSG90.SetServoAngleInServoFrameDeg(fAngleDegrees);
}	

float Neck::GetRotationAngle()
{
	return m_fAngleDegrees;	
}





