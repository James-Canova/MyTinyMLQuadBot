//Leg.h

#ifndef Leg_h
#define Leg_h

#include "Link.h"
#include "InverseKinematics.h"

//using namespace std;

class Leg
{
	
public:

	void Begin();

	void Initialize(int nLegNumber);

	bool SetFootXYPos(int nFootPositionIndex);
	
			
	//for debugging		
	float Get_x();
	float Get_y();
	float Get_Theta1();
	float Get_Theta2();
		
	
 private:
 
	int m_nLegNumber;
 
	Link m_linkUpper = Link();
	Link m_linkLower = Link();

	//calculates Theta 1 and Theta 2 from foot position
	InverseKinematics m_InverseKinematics = InverseKinematics();

	//fTheta1:  upper link,   fTheta2:  lower link
	void SetAnglesOfLegLinks(float fTheta1, float fTheta2);	
	
	//initialize coordinates of foot positions [mm]
	//1st column is the x values
	//2nd column is the y values
	
	float m_arrFootPositionCoordsXY[4][2] = {
		{0.0, -71.0},
		{-15.0,-71.0},
		{0.0, -64.0},
		{15.0, -71.0}
		} ;
		
		//for debugging
		float m_fx, m_fy,  m_fTheta1, m_fTheta2;
		

};

#endif