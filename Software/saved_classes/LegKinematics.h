//file: LegKinematics.h

//Inverse kinematics for two link leg---------------------------
//https://robotacademy.net.au/lesson/inverse-kinematics-
//for-a-2-joint-robot-arm-using-geometry/
//returns two angles

#include "PairValues.h"
#include<cmath>  //for BLE 33

#ifndef LegKinematics_h
#define LegKinematics_h


#define EPLISON_DISP_MM  	1.0 		//[mm]

#define Pi  3.14159 

class LegKinematics
{
	public:
	
		PairValues CalculateAngles(PairValues aPairCoords, float fL1, float fL2,  PairValues &aPairEstCoords, bool &bResult);  //inverse kinematics

	
    private:
		
		float Calculate_q1(PairValues aPairCoords, float fL1, float fL2,  float fq2);
		
		float Calculate_q2(PairValues aPairCoords, float fL1, float fL2);		
		
		bool CheckResult(PairValues aPairCoords, PairValues aPairAngles, PairValues &aPairEstCoords, float fL1, float fL2);		//forward kinematics	
		
};

#endif
