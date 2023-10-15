//ServoSG90.h

#ifndef ServoSG90_h 
#define ServoSG90_h

#include <Adafruit_PWMServoDriver.h>
#include "Constants.h"


class ServoSG90
{

  public:		
		
		void Initialize(int nServoNumber, bool bAxisAligned);
 
		void SetServoAngleInServoFrameDeg(float fDegrees);	
		
		
  private:
		Adafruit_PWMServoDriver m_PWM;
		
		int m_nServoNumber;
		bool m_bAxisAligned;
		
		float CheckPulseLenLimits(float fPulselen);	
		float ConvertDegToPulseLen(float fDegrees);	
		
		
};

#endif
