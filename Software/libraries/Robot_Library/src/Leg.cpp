//Leg.cpp

#include "Leg.h"


//function declarations
//public

void Leg::Begin()
{
	m_linkUpper.Begin();
	m_linkLower.Begin();
}


void Leg::Initialize(int nLegNumber)
{
	
	int nUpperLinkNumber;
	int nLowerLinkNumber;	

	if (nLegNumber == 0)    //Fore starboard
	{	
		nUpperLinkNumber = 0;
		nLowerLinkNumber =  1;		
	}
	
	if (nLegNumber == 1)    //Aft starboard
	{
		nUpperLinkNumber = 2;
		nLowerLinkNumber =  3;	
	}

	if (nLegNumber == 2)    //Fore port
	{
		nUpperLinkNumber = 4;
		nLowerLinkNumber =  5;	
	}

	if (nLegNumber == 3)    //Aft port
	{
		nUpperLinkNumber = 6;
		nLowerLinkNumber =  7;		
	}

	m_linkUpper.Initialize(nUpperLinkNumber);  
	m_linkLower.Initialize(nLowerLinkNumber);	
}



bool Leg::SetFootXYPos(int nFootPositionIndex)
{	

	float fx, fy;
	float fUpperLinkLength, fLowerLinkLength;
	
	float fTheta1, fTheta2;
	float fErrMM;
	bool bResult;
		
	//calculate servo angles from x,y coordinates (and link lenths)
	fx = m_arrFootPositionCoordsXY[nFootPositionIndex][0]; 
	fy = m_arrFootPositionCoordsXY[nFootPositionIndex][1];
	
	fUpperLinkLength = m_linkUpper.GetLinkLength();
	fLowerLinkLength = m_linkLower.GetLinkLength();	
	
	//fTheta1 and fTheta2 passed by reference
	//bResult based on distance of desired foot position to position calculated with inverse kinimatics
	//(toleralnce is set in inverse kinematics class)
	bResult =  m_InverseKinematics.CalculateAngles(fx, fy, fUpperLinkLength, fLowerLinkLength , fTheta1, fTheta2, fErrMM);  //inverse kinematics
	
	//for debugging
	m_fx = fx;
	m_fy = fy;
	m_fTheta1 = fTheta1; 
	m_fTheta2 = fTheta2;
		

	//move leg servos
	if (bResult)
		SetAnglesOfLegLinks(fTheta1, fTheta2);
	
	return bResult;
}	

//for debugging
float Leg::Get_x(){
	return m_fx;
}

float Leg::Get_y(){
	return m_fy;	
}

float Leg::Get_Theta1(){
	return m_fTheta1;	
}	
	
float Leg::Get_Theta2(){
	return m_fTheta2;	
}



//private-----
void Leg::SetAnglesOfLegLinks(float fTheta1, float fTheta2)
{
	m_linkUpper.SetLinkAngleDeg(fTheta1);
	m_linkLower.SetLinkAngleDeg(fTheta2);	
}
