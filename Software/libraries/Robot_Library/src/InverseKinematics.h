//file: InverseKinematics.h

//Inverse kinematics for two link leg---------------------------
//https://robotacademy.net.au/lesson/inverse-kinematics-
//for-a-2-joint-robot-arm-using-geometry/
//returns two angles

#include<cmath>

#ifndef InverseKinematics_h
#define InverseKinematics_h


#define EPLISON_DISP_MM  	1.0 		//[mm]

#define Pi  3.14159 

class InverseKinematics
{
	public:
	
		bool CalculateAngles(float fx, float fy, float fL1, float fL2, float &fTheta1, float &fTheta2, float &fErrMM);  //inverse kinematics

    private:
		
		float Calculate_Theta1(float fx, float fy, float fL1, float fL2, float Theta2);
		
		float Calculate_Theta2(float fx, float fy,  float fL1, float fL2);		
		
		bool CheckResult(float fx, float fy,  float Theta1, float Theta2, float fL1, float fL2, float &fErrMM);		//forward kinematics	
		
};

#endif
