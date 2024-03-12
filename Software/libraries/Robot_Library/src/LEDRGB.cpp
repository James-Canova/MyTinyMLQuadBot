//LEDRGB.cpp
//#include "Constants.h"

#include "LEDRGB.h"

void  LEDRGB::Initialize()
{
	pinMode(RED, OUTPUT);
	pinMode(BLUE, OUTPUT);
	pinMode(GREEN, OUTPUT);
}


void  LEDRGB::AllLedsOff()
{
	digitalWrite(RED, HIGH);
	digitalWrite(GREEN, HIGH);
	digitalWrite(BLUE, HIGH);
}


void LEDRGB::LedOn(int nPin)
{
	digitalWrite(nPin, LOW);
}




