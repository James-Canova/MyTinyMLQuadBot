//Legs.cpp

#include "Legs.h"


//function declarations
//public

void Legs::Begin()
{
	m_Leg_0.Begin();
	m_Leg_1.Begin();	
	m_Leg_2.Begin();
	m_Leg_3.Begin();	
}


void Legs::Initialize()
{
	m_Leg_0.Initialize(0);
	m_Leg_1.Initialize(1);	
	m_Leg_2.Initialize(2);	
	m_Leg_3.Initialize(3);	
	
	m_nIndexSeqFoot0 = 0;
	m_nIndexSeqFoot1 = m_nIndexSeqFoot1 + 18;
	m_nIndexSeqFoot2 = m_nIndexSeqFoot2 + 11;
	m_nIndexSeqFoot3 = m_nIndexSeqFoot3 + 5;	
	
}


void Legs::Walk()
{
	int nIndex_foot_0_position;
	int nIndex_foot_1_position;	
	int nIndex_foot_2_position;
	int nIndex_foot_3_position;	

	nIndex_foot_0_position = m_arrFootPosSequence[m_nIndexSeqFoot0];
	nIndex_foot_1_position = m_arrFootPosSequence[m_nIndexSeqFoot1];
	nIndex_foot_2_position = m_arrFootPosSequence[m_nIndexSeqFoot2];
	nIndex_foot_3_position = m_arrFootPosSequence[m_nIndexSeqFoot3];

	m_Leg_0.SetFootXYPos(nIndex_foot_0_position);
	m_Leg_1.SetFootXYPos(nIndex_foot_1_position);
	m_Leg_2.SetFootXYPos(nIndex_foot_2_position);
	m_Leg_3.SetFootXYPos(nIndex_foot_3_position);
	
	m_nIndexSeqFoot0 = m_nIndexSeqFoot0 + 1;
	if (m_nIndexSeqFoot0 > 23) {
		m_nIndexSeqFoot0 = 0;
	}
	
	m_nIndexSeqFoot1 = m_nIndexSeqFoot1 + 1;
	if (m_nIndexSeqFoot1 > 23) {
		m_nIndexSeqFoot1 = 0;
	}

	m_nIndexSeqFoot2 = m_nIndexSeqFoot2 + 1;
	if (m_nIndexSeqFoot2 > 23) {
		m_nIndexSeqFoot2 = 0;
	}
	
	m_nIndexSeqFoot3 = m_nIndexSeqFoot3 + 1;
	if (m_nIndexSeqFoot3 > 23) {
		m_nIndexSeqFoot3 = 0;
	}	
	
	
}

void Legs::PauseWalk()
{
	
}

void Legs::Sit()
{
	
}

void Legs::Reset()
{
	
}



//private-----

