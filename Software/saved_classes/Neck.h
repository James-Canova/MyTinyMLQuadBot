//Neck.h

#ifndef Neck_h 
#define Neck_h

//#include "Constants.h"
#include "ServoSG90.h"

//#include <string>
//using namespace std;


class Neck
{
public:

	void Initialize(int nServoNumber, bool bAxisAligned);
	void SetServoAngleInServoFrameDeg(float fDegrees);	   //CCW = + 
	float GetRotationAngle();
 
private:

	ServoSG90 aServoSG90; 
	float m_fAngleDegrees; 
	int m_nServoNumber;
	bool m_AxisAligned;

};

#endif