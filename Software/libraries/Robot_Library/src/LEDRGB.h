//LEDRGB.h

#ifndef LEDRGB_h 
#define LEDRGB_h

#include "Constants.h"



class LEDRGB
{
public:

	void  SetValues(float fX, float fY);
	float GetX();	
	float GetY();		

private:
    float m_fX;  
    float m_fY;
};

#endif


/*



pinMode(RED, OUTPUT);
pinMode(BLUE, OUTPUT);
pinMode(GREEN, OUTPUT);




AllLedsOff();


LedOn(BLUE);

*/