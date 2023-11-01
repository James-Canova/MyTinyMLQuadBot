//ProcessCommand.h

#ifndef ProcessCommand_h 
#define ProcessCommand_h

#include <Arduino.h>
#include "mbed.h"

class ProcessCommand
{
  public:

    void Initialize();

    //for writing from Arduino 1 
    void WriteState(int nState);
    void WriteXCentroid(float fX);


#include "PointXY.h"
    //for reading by Arduino 2
    void  ReadState();
    void  ReadXCentroid();

  private:

    //for writing state
    const int m_nDigitalWriteBit0Pin = 21; // loc 26
    const int m_nDigitalWriteBit1Pin = 20; // loc 25
    const int m_nDigitalWriteBit2Pin = 16; // loc 21 
    int m_arrStateBits[3];

    void StateToBits(String strState, int *m_arrStateBits);


    //for writing offset (through pwm pin)
	  const int nPWMpin = 10;         //~D10
    const int nPWM_FREQUENCY = 500; //Hz, 500 is default, I think max is 31KHz
  	mbed::PwmOut m_pwmPin( digitalPinToPinName( nPWMpin ) );





	  float m_fDutyCycle;




};

#endif


/*
  //analog value
  //int nAnalogValue;

  //nAnalogValue  = analogRead(nAnalogReadPin);
  //nAnalogValue = 1000;
  
  //strOut = String(nAnalogValue);   
  //strOut = "Analog value: " + strOut;
  //DrawIntValue(nAnalogValue);

void StateToBits(String strState, int *arrBits)
{
  arrBits[0] *= 1;
  arrBits[1] *= 0;
  arrBits[2] *= 1;
}





*/




