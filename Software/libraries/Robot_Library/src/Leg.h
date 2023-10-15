//Leg.h

#ifndef Leg_h
#define Leg_h

#include "LegKinematics.h"
#include "Link.h"
#include "PairValues.h"


using namespace std;

class Leg
{
	
public:

	void Initialize(int nLegNumber);

	void SetFootXYPos(PairValues aPairCoordsXY);
	
	void UpdateCurrentFootPos(PairValues aPairCoordsXY);
	
	
 private:
 
	int m_nLegNumber;
 
	Link m_linkUpper;
	Link m_linkLower;
	
	PairValues m_CurrentFootPos;
	
	bool m_bfootPosKnown;
	
	void SetAnglesOfLegLinks(PairValues aPairAngles);	

	PairValues m_aPairAngles;   //temporary	
	
};

#endif