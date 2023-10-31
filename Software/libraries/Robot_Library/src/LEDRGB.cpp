//LEDRGB.cpp

#include "LEDRGB.h"

void  LEDRGB::SetValues(float fX, float fY)
{
	m_fX = fX;  
	m_fY = fY;		
}


float LEDRGB::GetX()
{	
	return m_fX;
}

float LEDRGB::GetY()
{	
	return m_fY;
}







