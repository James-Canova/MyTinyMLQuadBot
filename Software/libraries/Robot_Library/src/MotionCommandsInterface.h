//MotionCommandsInterface.h

#ifndef MotionCommandsInterface_h 
#define MotionCommandsInterface_h

//#include "MotionCommandWriteUtility.h"
#include <Arduino.h>


class MotionCommandsInterface
{
public:

	void  WriteState(String strState);
	void  WriteXCentroid(int nXCentorid);	

private:
 
};

#endif
