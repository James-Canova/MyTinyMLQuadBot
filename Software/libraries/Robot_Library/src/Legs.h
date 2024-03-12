//Legs_h.h

#ifndef Legs_h
#define Legs_h

#include "Leg.h"


class Legs
{
	
public:

	void Begin();

	void Initialize();

	void Walk();
	
	void PauseWalk();
	
	void Sit();	
	
	void Reset();
	
 private:
 
	Leg m_Leg_0 = Leg();
	Leg m_Leg_1 = Leg();
	Leg m_Leg_2 = Leg();
	Leg m_Leg_3 = Leg();
	
	int m_arrFootPosSequence[24] = {0,0,0,1,1,1,2,2,2,3,4,5,6,7,8,9,9,9,10,10,10,11,11,11};	
	
	 //0->23 (indexes in m_arrFootPosSequence)
	int m_nIndexSeqFoot0; 
	int m_nIndexSeqFoot1; 
	int m_nIndexSeqFoot2; 	
	int m_nIndexSeqFoot3; 	
	
};

#endif