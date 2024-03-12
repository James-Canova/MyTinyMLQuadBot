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

};

#endif

