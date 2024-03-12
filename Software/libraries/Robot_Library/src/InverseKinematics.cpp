//file: InverseKinematics.cpp

#include "InverseKinematics.h"



//function definitions
//public-------------


bool InverseKinematics::CalculateAngles(float fx, float fy, float fL1, float fL2, float &fTheta1, float &fTheta2, float &fErrMM)
{	
	float Theta1, Theta2;
	bool bResult;
	
	//calculate q2-------------
	Theta2 = Calculate_Theta2(fx, fy, fL1, fL2);	
	
	//calculate q1 using calculated value of q2-----------------	
	Theta1 = Calculate_Theta1(fx, fy, fL1, fL2, Theta2);	
	
	//check result-------------
	bResult = CheckResult( fx, fy, Theta1, Theta2, fL1, fL2, fErrMM); 
	
	//convert result to angles used by servos are returned by reference 
	fTheta1 = Theta1  + 90.0;		//to put wrt to y axis rather than x axis, to agree with how servo angle is defined 
	fTheta2 = Theta2;	

	return bResult;		

}



//private------------		
float InverseKinematics::Calculate_Theta1(float fx, float fy,  float fL1, float fL2,  float Theta2)
{
	float fNum, fDen;
	float Theta1_rad, Theta2_rad;
	float Theta1;	
	float fAlpha_rad, fBeta_rad;
	
	Theta2_rad = Theta2 * (Pi/180.0);
	
	//calculate fAlpha_rad
	fAlpha_rad = atan2f(fy, fx);   //atan2, angles between -Pi and Pi

	//calculate fBeta_rad
    fNum = fL2 * sin(Theta2_rad);
    fDen = fL1 + fL2 * cos(Theta2_rad);

	fBeta_rad =atan2(fNum, fDen);  //rad 

   Theta1_rad = fAlpha_rad - fBeta_rad;
   Theta1 = Theta1_rad  * 180.0/Pi ;  
   
	return Theta1;    //either positive or negative
}


float InverseKinematics::Calculate_Theta2(float fx, float fy, float fL1, float fL2)
{
	float Theta2, Theta2_rad;
	float fcosTheta2;	
	float fNum, fDen;
	
	fNum = pow(fx, 2) + pow(fy, 2)  - pow(fL1, 2)  - pow(fL2, 2) ;
    fDen = 2.0 * fL1 * fL2;
    fcosTheta2 = fNum / fDen;
	
	Theta2_rad = acos(fcosTheta2);  //acos, angles between Pi/2 and -Pi/2
	
	Theta2= Theta2_rad * 180.0/Pi;
	
	if (Theta2 > 0.0) 	//want case where fTheta2 < 0 for this particular robot
	{
		Theta2 = -1 * Theta2;  //cos is positive in quadrant 1 and 4
	}
	
	return Theta2;   //always negative
}


bool InverseKinematics::CheckResult(float fxTarget, float fyTarget,  float Theta1, float Theta2, float fL1, float fL2, float &fErrMM)
{
	bool bResult;
	float fx, fx1, fx2;
	float fy, fy1, fy2;
	
	float fAngle1, fAngle2, fAngle3;
	float fAngle1_rad, fAngle3_rad; 		//for use with trigonometric functions	
	
	bResult = false;
	
	fAngle1 = Theta1 + 90;   	//to put wrt to y axis rather than x axis, to agree with how servo angle is defined 
	fAngle2 = Theta2;
	fAngle3 = fAngle1 + fAngle2;

	//convert angles to radians to use with trigonometric functions
	fAngle1_rad = fAngle1 * Pi/180.0;
	fAngle3_rad = fAngle3 * Pi/180.0;

	//calculate fx
	fx1 = fL1 * sin(fAngle1_rad);
	fx2 = fL2 * sin(fAngle3_rad);
	fx = fx1 + fx2;

	//calculate y
	fy1 = -1.0 * fL1 * cos(fAngle1_rad);
	fy2 = -1.0 * fL2 * cos(fAngle3_rad);
	fy = fy1 + fy2; 

	//calculate if accurate within EPLISON_DISP_MM
	float fDx, fDy;
	float fD;
	
	fDx = fxTarget - fx;
	fDy = fyTarget - fy;
	fD = sqrt(pow(fDx, 2) + pow(fDy, 2) );
	
	fErrMM = fD;
	
	if (fD < EPLISON_DISP_MM)
	{
		bResult = true;	
	}

	return bResult;
}













