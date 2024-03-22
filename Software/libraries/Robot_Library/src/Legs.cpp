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
	
	m_arrPosSeqIndex[0] = 0;  //on ground, centre
 	m_arrPosSeqIndex[1] = 4;  //raised centre
	m_arrPosSeqIndex[2] = 4;  //raised centre
	m_arrPosSeqIndex[3] = 0;	//on ground, centre

}


void Legs::Walk()
{
	int nIndex_foot_0_position;
	int nIndex_foot_1_position;	
	int nIndex_foot_2_position;
	int nIndex_foot_3_position;	

	nIndex_foot_0_position = m_arrFootPosSequence[m_arrPosSeqIndex[0] ];
	nIndex_foot_1_position = m_arrFootPosSequence[m_arrPosSeqIndex[1] ];
	nIndex_foot_2_position = m_arrFootPosSequence[m_arrPosSeqIndex[2] ];
	nIndex_foot_3_position = m_arrFootPosSequence[m_arrPosSeqIndex[3] ];

	m_Leg_0.SetFootXYPos(nIndex_foot_0_position);
	m_Leg_1.SetFootXYPos(nIndex_foot_1_position);
	m_Leg_2.SetFootXYPos(nIndex_foot_2_position);
	m_Leg_3.SetFootXYPos(nIndex_foot_3_position);
	
	for (int i = 0; i < 4; i++) { 	//4 legs
		m_arrPosSeqIndex[i]  ++;
		
		if (m_arrPosSeqIndex[i] > 7) {  //max foot position index = 7
			m_arrPosSeqIndex[i] = 0;
		}
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

