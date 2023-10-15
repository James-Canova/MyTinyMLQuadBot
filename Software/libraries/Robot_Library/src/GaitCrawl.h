//GaitCrawl

#ifndef GaitCrawl_h
#define GaitCrawl_h

#include "Path.h"
#include "PairValues.h"


class GaitCrawl
{
public:
	
	void Initialize();
	void Crawl(float fTurnRate, PairValues &Leg0_XY, PairValues &Leg1_XY, PairValues &Leg2_XY, PairValues &Leg3_XY);


private:

	int m_nStep;  //0->3
	int m_nSubStep; //0->5
	
	Path m_aPathFoot;
	
	int m_arrSeqSubStep[6][4];   //six rows and four columns
	void GenerateSeqSubStepArray();
	
	PairValues GetFootPosition(int nSubStep, int nSequenceNumberLeg);
};


#endif
