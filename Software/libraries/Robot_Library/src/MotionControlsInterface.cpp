//MotionControlsInterface.cpp

#include "MotionControlsInterface.h"

void  MotionControlsInterface::ReadValue()
{
	int a;
	a = 1;	
}



/*
//reads output of low pass filter (0v...3.3v) on analog pin  (0..)
const int nAnalogReadPin = 15;         //D15/A1
const int nDigitalReadBit0Pin = 7;
const int nDigitalReadBit1Pin = 8;
const int nDigitalReadBit2Pin = 9;


int nBit0;
int nBit1;
int nBit2;
int arrBit[3];


nBit0 = digitalRead(nDigitalReadBit0Pin);   
nBit1 = digitalRead(nDigitalReadBit1Pin);
nBit2 = digitalRead(nDigitalReadBit2Pin); 

arrBit[0] = nBit0;
arrBit[1] = nBit1; 
arrBit[2] = nBit2;

strOut = BitsToSting(arrBit);



String BitsToSting(int* arrBits)
{
  String strState;
  int nIndex;

  nIndex = 4 * arrBits[2] + 2 * arrBits[1] + arrBits[0];

  strState = arrStates[nIndex];

  return strState;
}



*/






