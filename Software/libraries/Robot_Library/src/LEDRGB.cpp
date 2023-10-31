//LEDRGB.cpp

#include "LEDRGB.h"

void  LEDRGB::Initialize()
{
	pinMode(RED, OUTPUT);
	pinMode(BLUE, OUTPUT);
	pinMode(GREEN, OUTPUT);

	pinMode(nDigitalWriteBit0Pin, OUTPUT);
	pinMode(nDigitalWriteBit1Pin, OUTPUT);
	pinMode(nDigitalWriteBit2Pin, OUTPUT);	
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




