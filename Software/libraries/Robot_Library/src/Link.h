//Link.h

#ifndef Link_h
#define Link_h

#include "ServoSG90.h"

class Link
{
  public:

		void Initialize(int nServoNumber, float fLength, bool bAxisAligned);

		void SetAngleInLegFrame(float fAngleDeg);
				

	private:
	
		int m_nServoNumber;
		float m_fLength;
		bool m_bAxisAligned;
		
		ServoSG90  m_ServoSG90;
		
		void SetServoAngleInServoFrameDeg(float fDegrees);		

		float CheckServoAngleLimit(float fDegrees);
		
		float m_fMaxServoAngle;
		
};

#endif