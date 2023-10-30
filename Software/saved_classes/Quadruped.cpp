//Quadruped.cpp

#include "Quadruped.h"

//function definiitions
//public-----
void Quadruped::Initialize()
{
	int nLegNumber;

	nLegNumber = 0;
	m_legForeStb.Initialize(nLegNumber);   
	
	nLegNumber = 1;	
	m_legAftStb.Initialize(nLegNumber);

	nLegNumber = 2;	
	m_legForePort.Initialize(nLegNumber); 
	
	nLegNumber = 3;		
	m_legAftPort.Initialize(nLegNumber);  

	bool bAxesAligned = true;	
	m_neck.Initialize(NECK_SERVO_NUMBER, bAxesAligned);	

	//aWalk.Initialize();
	
	m_nWaitMilliSeconds = 500;  //milliseconds
	
	Ready();
}


//Makes all servo angles zero so can check servo arm positions on splines.
//Only activated by switch (just for adjusting leg position on servos).
void Quadruped::Reset()   
{
	//set all link servo angle to zero, i.e. all legs will be vertical
	PairValues aPairCoords;
	float XPos = 0.0;	
	float YPos = -1.0 *(UPPER_LEG_LENGTH_MM  + LOWER_LEG_LENGTH_MM);
	
	bool bRaise = false;
	
	aPairCoords.SetValues(XPos, YPos);    //for all legs
	
	//set position of all feet
	m_legForeStb.SetFootXYPos(aPairCoords);	
	m_legAftStb.SetFootXYPos(aPairCoords);	
	m_legForePort.SetFootXYPos(aPairCoords);		
	m_legAftPort.SetFootXYPos(aPairCoords);		
	
	//set neck so head is facing straight forward
	float fNeckAngleDeg = 20.0;
	m_neck.SetServoAngleInServoFrameDeg(fNeckAngleDeg);
	
	m_strState = "straightenLegs";
}


//Put all legs in same position in preparation to walk
void Quadruped::Ready()
{	
	//Ready to walk
	PairValues aPairCoords;
	float XPos = FOOT_ZERO_X_POS;
	float YPos = FOOT_ZERO_Y_POS;

	aPairCoords.SetValues(XPos, YPos);    //for all feet

	//set position of all feet
	m_legForeStb.SetFootXYPos(aPairCoords);	
	m_legAftStb.SetFootXYPos(aPairCoords);	
	m_legForePort.SetFootXYPos(aPairCoords);		
	m_legAftPort.SetFootXYPos(aPairCoords);		
	
	//set neck so head is facing straight forward
	float fNeckAngleDeg = 0.0;
	m_neck.SetServoAngleInServoFrameDeg(fNeckAngleDeg);
	
	m_strState = "ready";	
	
	//current position of foot is now known
	m_legForeStb.UpdateCurrentFootPos(aPairCoords);	
	m_legAftStb.UpdateCurrentFootPos(aPairCoords);	
	m_legForePort.UpdateCurrentFootPos(aPairCoords);		
	m_legAftPort.UpdateCurrentFootPos(aPairCoords);		

	Wait(m_nWaitMilliSeconds); //ms	
}


//Sit
void Quadruped::Sit()
{
	//set position of forward legs
	PairValues aPairCoordsFore;
	float XPosFore= 0.0;	
	float YPosFore = -73.0;

	aPairCoordsFore.SetValues(XPosFore, YPosFore);    

	m_legForeStb.SetFootXYPos(aPairCoordsFore);
	m_legForePort.SetFootXYPos(aPairCoordsFore);	
	
	
	//set position of aft legs	
	PairValues aPairCoordsAft;
	float XPosAft= 36.7;	
	float YPosAft= -60.0;

	aPairCoordsAft.SetValues(XPosAft, YPosAft);    
	
	m_legAftStb.SetFootXYPos(aPairCoordsAft);
	m_legAftPort.SetFootXYPos(aPairCoordsAft);	
	
	//set neck so head is facing straight forward
	float fNeckAngleDeg = 0.0;
	m_neck.SetServoAngleInServoFrameDeg(fNeckAngleDeg);	
	
	m_strState = "sit";
}

	

void Quadruped::Crawl(float fTurnRate)
{	

	if (not(m_strState == "crawl" || m_strState =="pauseWalk" || m_strState == "ready") )
	{
		Ready();
	} else {
		
		
		
		int a = 1;
		
	}
	
}	

	

void Quadruped::PauseWalk()
{
	m_strState = "pauseWalk";
}


void Quadruped::SetNeckAngle(float fAngle_Deg)
{
	m_neck.SetServoAngleInServoFrameDeg(fAngle_Deg);
	
	m_strState = "setNeckAngle";	
}



void Quadruped::Wait(unsigned long nWaitMilliSeconds)
{
	unsigned long nStartTime, nEndTime, nCurrentTime;	
	
	nStartTime = millis();
	nCurrentTime = nStartTime;
	nEndTime = nStartTime + nWaitMilliSeconds;

	while (nCurrentTime <= nEndTime) {
		nCurrentTime = millis();
	}	
}





//---------------------------------------------------------------------------------------------------------------
//temporary


String Quadruped::GetState()
{
	return m_strState;	
}
