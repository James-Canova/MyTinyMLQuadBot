//Leg.cpp

#include "Leg.h"


//function declarations
//public
void Leg::Initialize(int nLegNumber)
{
	int nServoNumberUpperLink;
	int nServoNumberLowerLink;	
	
	float fLengthUpper = UPPER_LEG_LENGTH_MM;
	float fLengthLower = LOWER_LEG_LENGTH_MM;		
	
	bool bAxesAligned;	
	
	m_nLegNumber = nLegNumber;
	
	if (nLegNumber == 0)    //Fore starboard
	{	
		nServoNumberUpperLink = 0;
		nServoNumberLowerLink =  1;		
		bAxesAligned = true;	
	}
	
	if (nLegNumber == 1)    //Aft starboard
	{
		nServoNumberUpperLink = 2;
		nServoNumberLowerLink =  3;
		bAxesAligned = true;		
	}

	if (nLegNumber == 2)    //Fore port
	{
		nServoNumberUpperLink = 4;
		nServoNumberLowerLink =  5;	
		bAxesAligned = false;		
	}

	if (nLegNumber == 3)    //Aft port
	{
		nServoNumberUpperLink = 6;
		nServoNumberLowerLink =  7;	
		bAxesAligned = false;		
	}

	m_linkUpper.Initialize(nServoNumberUpperLink, fLengthUpper, bAxesAligned);  
	m_linkLower.Initialize(nServoNumberLowerLink, fLengthLower, bAxesAligned);	
	
	m_CurrentFootPos.SetValues(-999.0, -999.0); 
	m_bfootPosKnown = false;
}




void Leg::UpdateCurrentFootPos(PairValues aPairCoordsXY)
{
	m_CurrentFootPos = aPairCoordsXY;
	m_bfootPosKnown = true;
}



void Leg::SetFootXYPos(PairValues aPairCoordsXY)
{	
	PairValues aPairAngles, aPairEstCoords;
	bool bResult;
	float fValue1, fValue2;

	LegKinematics aKinematics;

	//calculate servo angles from x,y coordinates 
	aPairAngles = aKinematics.CalculateAngles(aPairCoordsXY, UPPER_LEG_LENGTH_MM, LOWER_LEG_LENGTH_MM,  aPairEstCoords, bResult);  //inverse kinematics	

	//move leg servos
	SetAnglesOfLegLinks(aPairAngles);

	//update m_CurrentFootPos
	UpdateCurrentFootPos(aPairCoordsXY);
}	


//private-----
void Leg::SetAnglesOfLegLinks(PairValues aPairAngles)
{
	float fAngleUpperLink, fAngleLowerLink;
	
	fAngleUpperLink = aPairAngles.GetValue1();
	fAngleLowerLink = aPairAngles.GetValue2();
	
	m_linkUpper.SetAngleInLegFrame(fAngleUpperLink);;
	m_linkLower.SetAngleInLegFrame(fAngleLowerLink);	
}

