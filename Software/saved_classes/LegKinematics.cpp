//file: LegKinematics.cpp

#include "LegKinematics.h"



//function definitions
//public-------------
PairValues LegKinematics::CalculateAngles(PairValues aPairCoords, float fL1, float fL2,  PairValues &aPairEstCoords, bool &bResult)
{	
	float fq1, fq2;
	float fTheta1, fTheta2;
	
	PairValues aPairAngles;
	
	//calculate q2-------------
	fq2 = Calculate_q2(aPairCoords, fL1, fL2);	
	
	//calculate q1 using calculated value of q2-----------------	
	fq1 = Calculate_q1(aPairCoords, fL1, fL2, fq2);	
	
	//check result-------------
	aPairAngles.SetValues(fq1 , fq2);	
	bResult = CheckResult(aPairCoords, aPairAngles, aPairEstCoords, fL1, fL2);  //aPairEstCoords returned by reference
	
	//convert result to angles used by servos-------------
	fTheta1 = fq1  + 90.0;		
	fTheta2 = fq2;	
	aPairAngles.SetValues(fTheta1 , fTheta2);			

	return aPairAngles;
}



//private------------		
float LegKinematics::Calculate_q1(PairValues aPairCoords, float fL1, float fL2,  float fq2)
{
	
	float fx, fy;
	float fNum, fDen;
	float fq1_rad, fq2_rad;
	float fq1;	
	float fAlpha_rad, fBeta_rad;
	
	fq2_rad = fq2 * (Pi/180.0);
	
	fx = aPairCoords.GetValue1();
	fy = aPairCoords.GetValue2();	
	
	//calculate fAlpha_rad
	if (fx < 1) {      //1mm, y/x will be appproaching infinity and Alpha will be either 90 [deg] or -90 [deg], want -90 [deg]
		fAlpha_rad = -Pi/2.0;  //-90 [deg]
	} else {
		fAlpha_rad = atan(fy/fx);
		if (fx < 0.0) {
			fAlpha_rad = fAlpha_rad - Pi;
		}
	}
	
	//calculate fBeta_rad
    fNum = fL2 * sin(fq2_rad);
    fDen = fL1 + fL2 * cos(fq2_rad);

	fBeta_rad =atan(fNum / fDen);  //rad 

   fq1_rad = fAlpha_rad - fBeta_rad;
   fq1 = fq1_rad  * 180.0/Pi ;  
   
	return fq1;    //either positive or negative
}


float LegKinematics::Calculate_q2(PairValues aPairCoords, float fL1, float fL2)
{
	float fq2, fq2_rad;
	float fx, fy;
	float fcosfq2;	
	float fNum, fDen;
	
	fx = aPairCoords.GetValue1();
	fy = aPairCoords.GetValue2();	

	fNum = pow(fx, 2) + pow(fy, 2)  - pow(fL1, 2)  - pow(fL2, 2) ;
    fDen = 2.0 * fL1 * fL2;
    fcosfq2 = fNum / fDen;
	
	if (abs(fcosfq2) > 0.9998)     //acos(0.9998) == 1 [deg]
	{
		fq2 = 0.0;
		} else {
		fq2_rad = acos(fcosfq2);  
		fq2 = fq2_rad * 180.0/Pi ;
	}
	
	
	if (fq2 > 0.0) 	//want case where fTheta2 < 0
	{
		fq2 = -1 * fq2;  //cos is positive in quadrant 1 and 4
	}
	
	return fq2;   //always negative
}


bool LegKinematics::CheckResult(PairValues aPairCoords, PairValues aPairAngles, PairValues &aPairEstCoords, float fL1, float fL2)
{
	bool bResult;
	float fxTarget, fyTarget;      //target coordinates
	float fx, fx1, fx2;
	float fy, fy1, fy2;
	
	float fq1, fq2; 									//angles that were calculated
	float fq1Calculated, fq2Calculated;  	//to be calculated from fq1, fq2
	
	float fAngle1, fAngle2, fAngle3;
	float fAngle1_rad, fAngle2_rad, fAngle3_rad; 		//for use with trigonometric functions	
	
	bResult = false;
	
	fxTarget = aPairCoords.GetValue1();
	fyTarget = aPairCoords.GetValue2();	
	
	fq1 = aPairAngles.GetValue1();
	fq2 = aPairAngles.GetValue2();
	
	fAngle1 = fq1 + 90.0;
	fAngle2 = fq2;
	fAngle3 = fAngle1 + fAngle2;

	//convert angles to radian to use with trigonometric functions
	fAngle1_rad = fAngle1 * Pi/180.0;
	fAngle2_rad = fAngle2 * Pi/180.0;
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
	fD = sqrt(pow(fDx, 2) + pow(fDx, 2) );
	
	if (fD < EPLISON_DISP_MM)
	{
		bResult = true;	
	}
	
	aPairEstCoords.SetValues(fx, fy); //returned by reference

	return bResult;
}













