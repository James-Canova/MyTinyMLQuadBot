//Link.h

#ifndef Link_h
#define Link_h

#include "ServoSG90.h"

class Link
{
  public:

		void Begin();
		
		void Initialize(int nServoNumber);

		void SetLinkAngleDeg(float fDegrees);	

		float GetLinkLength();	  //for use in Leg for inverse kinematics
		

		
	private:
	
		ServoSG90  m_ServoSG90 = ServoSG90();	

		int m_nServoNumber;	
		bool m_bAxisAligned;
		
		int m_nLinkNumber;
		float m_fLinkLength;

		float CheckLinkAngleLimitDeg(float fDegrees);
		
		float m_fMaxLinkAngleDeg;  //symmetric
		
		const float MAX_LINK_DEG_UPPER_LEG  = 75.0;      
		const float MAX_LINK_DEG_LOWER_LEG  = 45.0;   

		const float UPPER_LEG_LENGTH_MM = 40.0;
		const float LOWER_LEG_LENGTH_MM = 33.0;	
		

		
};

#endif