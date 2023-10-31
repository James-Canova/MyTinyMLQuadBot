//ProcessCommand.cpp

#include "ProcessCommand.h"


//Write -----------------------------------------
void ProcessCommand::WriteXCentroid(float fX)
{
	//m_PWMpin( digitalPinToPinName( m_nPWMpin ) );  
   
    //const int m_nPWM_FREQUENCY = 500; //Hz, 500 is default
    //m_nPWMpin.period( 1.0 / nPWM_FREQUENCY );   //must be in seconds

	float fDutyCycle;

	fDutyCycle  = 0.9;  //0->1, 0V-3.3V

	//m_nPWMpin.write(fDutyCycle);

}

void ProcessCommand::WriteState(int nState)
{
	/*
	pinMode(nDigitalWriteBit0Pin, OUTPUT);
	pinMode(nDigitalWriteBit1Pin, OUTPUT);
	pinMode(nDigitalWriteBit2Pin, OUTPUT);

	StateToBits(strState, m_arrStateBits);

	int m_arrStateBits[3] = {1, 0, 1};
	digitalWrite(nDigitalWriteBit0Pin, m_arrStateBits[0]);
	digitalWrite(nDigitalWriteBit1Pin, m_arrStateBits[1]);
	digitalWrite(nDigitalWriteBit2Pin, m_arrStateBits[2]);
	*/
}

void ProcessCommand::StateToBits(String strState, int *m_arrStateBits)
{
	int nBit0;
	int nBit1;
	int nBit2;

	//convert strState to int and then to 3 bits
	//.
	//.
	//.
	nBit0 = 1;
	nBit1 = 0;
	nBit2 = 1;


	m_arrStateBits[0] *= nBit0;
	m_arrStateBits[1] *= nBit1;
	m_arrStateBits[2] *= nBit2;
}


//Read ------------------------------------------




