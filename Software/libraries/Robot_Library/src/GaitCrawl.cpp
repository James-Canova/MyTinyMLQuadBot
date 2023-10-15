//GaitCrawl.cpp

#include "GaitCrawl.h"
#include "Constants.h"

void GaitCrawl::Initialize()
{
	m_nStep = 0;
	m_nSubStep = 0; 
	
	m_aPathFoot.Initialize();
}


void GaitCrawl::Crawl(float fTurnRate, PairValues &Leg0_XY, PairValues &Leg1_XY, PairValues &Leg2_XY, PairValues &Leg3_XY)
{
	
	int nSequenceNumberLeg0, nSequenceNumberLeg1, nSequenceNumberLeg2, nSequenceNumberLeg3;
	int nIndexLeg0, nIndexLeg1,  nIndexLeg2, nIndexLeg3;

	
	nIndexLeg0 = 0; nIndexLeg1 = 0;  nIndexLeg2 = 0;  nIndexLeg3 = 0;   //temporary	
	
	switch(m_nStep) {
		
	  case 0: {
		  
			nSequenceNumberLeg0 = 0;
			nSequenceNumberLeg1 = 3;
			nSequenceNumberLeg2 = 2;
			nSequenceNumberLeg3 = 1;	  		
			Leg0_XY = GaitCrawl::GetFootPosition(m_nSubStep, nSequenceNumberLeg0);
			
			
			
			//....repeat for remaining nSequenceNumberLegX numbers 
			
			
			

		  
		    if (m_nSubStep > NUM_SUB_STEP)
			{
				m_nSubStep = 0;				
				m_nStep = 1;					
			}
		}
		break;


		
	  case 1: {

		    if (m_nSubStep > NUM_SUB_STEP)
			{
				m_nSubStep = 0;				
				m_nStep = 2;					
			}  
		}
		break; 
			
			
	  case 2: {

		    if (m_nSubStep > NUM_SUB_STEP)
			{
				m_nSubStep = 0;				
				m_nStep = 3;					
			}  	  
		}
		break;
		
		
	  case 3: {
		  
		    if (m_nSubStep > NUM_SUB_STEP)
			{
				m_nSubStep = 0;				
				m_nStep = 0;					
			}  
		}
		break; 		
		
		
	  default: {
			m_nStep = 0;  
			m_nSubStep = 0;					
	  }

	}
	
	m_nSubStep = m_nSubStep + 1;
	
}


void GaitCrawl::GenerateSeqSubStepArray()
{
	int nSequenceNumber;  //0->3
	int nSubStepNumber;    //0->5
	int nPathIndex;
	
	int nCounter;
	
	//sequence 0
	nSequenceNumber = 0;
	for (nSubStepNumber = 0; nSubStepNumber < 5; nSubStepNumber++) {
		nPathIndex = nSubStepNumber + 3;
		m_arrSeqSubStep[nSubStepNumber][nSequenceNumber] = nPathIndex;
	}	
	
	
	//sequence 1
	nSequenceNumber = 1;
	for (nSubStepNumber = 0; nSubStepNumber < 5; nSubStepNumber++) {
		
		if (nSubStepNumber <=2)
		{
			nPathIndex = 1;
		} else {
			nPathIndex = 2;			
		}
		
		m_arrSeqSubStep[nSubStepNumber][nSequenceNumber] = nPathIndex;
	}	


	
	//sequence 2
	nSequenceNumber = 2;
	for (nSubStepNumber = 0; nSubStepNumber < 5; nSubStepNumber++) {
		
		if (nSubStepNumber <=2)
		{
			nPathIndex = 11;
		} else {
			nPathIndex = 0;			
		}

		m_arrSeqSubStep[nSubStepNumber][nSequenceNumber] = nPathIndex;
	}	
	
	
	//sequence 3
	nSequenceNumber = 3;
	for (nSubStepNumber = 0; nSubStepNumber < 5; nSubStepNumber++) {
		
		if (nSubStepNumber <=2)
		{
			nPathIndex = 9;
		} else {
			nPathIndex = 10;			
		}
		
		m_arrSeqSubStep[nSubStepNumber][nSequenceNumber] = nPathIndex;
	}		
	
}



PairValues GaitCrawl::GetFootPosition(int nSubStep, int nSequenceNumberLeg)
{
	PairValues aPosXY;
	int nIndexLeg;
	
	nIndexLeg = m_arrSeqSubStep[nSubStep][nSequenceNumberLeg] ;		
	aPosXY = m_aPathFoot.GetFootPosition(nIndexLeg);			
	
	return aPosXY;
}