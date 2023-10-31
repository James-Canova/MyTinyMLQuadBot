//LEDRGB.h

#ifndef LEDRGB_h 
#define LEDRGB_h

#include <Arduino.h>
#include "Constants.h"

class LEDRGB
{
	public:

		void Initialize();	
		void AllLedsOff();
		void LedOn(int nPin);

	private:
		const int nDigitalWriteBit0Pin = 21; // loc 26
		const int nDigitalWriteBit1Pin = 20; // loc 25
		const int nDigitalWriteBit2Pin = 16; // loc 21	

};

#endif

