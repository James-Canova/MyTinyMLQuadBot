//MotionCommandReadUtility.cpp

#include "MotionCommandReadUtility.h"
#include "Constants.h"

//scaled to 0 to 1 (for pwm duty cycle)
float MotionCommandReadUtility::GetXCentroid()
{	
	int nValueFromEImodel;  //0 to IMAGE_WIDTH_PIXELS (from Constants.h)
	nValueFromEImodel = 55; //temporary

	float fScaledXValue = nValueFromEImodel / IMAGE_WIDTH_PIXELS;

	return m_fXCentroid;
}








