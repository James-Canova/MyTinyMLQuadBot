//ProcessCommand.cpp

#include "ProcessCommand.h"


void ProcessCommand::Initialize()
{



}

//Write -----------------------------------------
void ProcessCommand::WriteXCentroid(float fX)
{

	float fDutyCycle  = fX;  //0->1, 0V-3.3V

	m_pwmPin.write(fDutyCycle);

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




