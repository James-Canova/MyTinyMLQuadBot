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
	/*
	

	float m_arrFootPositionCoordsXY[12][2] = {
		{0.0, -65.0},
		{-10.0,-65.0},
		{-20.0,-65.0},
		{-30.0,-65.0},
		{-20.0, -59.0},
		{-10.0, -59.0},
		{0.0, -59.0},
		{10.0, -59.0},
		{20.0, -59.0},
		{30.0, -65.0},
		{20.0, -65.0},
		{10.0, -65.0}
		} ;


	float m_arrFootPositionCoordsXY[12][2] = {
		{0.0, -71.0},
		{-5.0,-71.0},
		{-10.0,-71.0},
		{-15.0,-71.0},
		{-10.0, -64.0},
		{-5.0, -64.0},
		{0.0, -64.0},
		{5.0, -64.0},
		{10.0, -64.0},
		{15.0, -71.0},
		{10.0, -71.0},
		{5.0, -71.0}
		} ;
*/
	float m_arrFootPositionCoordsXY[14][2] = {
		{0.0, -71.0},
		{-5.0,-71.0},
		{-10.0,-71.0},
		{-15.0,-71.0},
		{-12.5, -67.5},
		{-10.0, -64.0},
		{-5.0, -64.0},
		{0.0, -64.0},
		{5.0, -64.0},
		{10.0, -64.0},
		{12.5, -67.5},
		{15.0, -71.0},
		{10.0, -71.0},
		{5.0, -71.0}
		} ;
		
		//for debugging
		float m_fx, m_fy,  m_fTheta1, m_fTheta2;
		

};

#endif