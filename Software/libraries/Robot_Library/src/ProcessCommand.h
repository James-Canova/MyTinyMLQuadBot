//ProcessCommand.h

#ifndef ProcessCommand_h 
#define ProcessCommand_h

#include <Arduino.h>
#include <mbed.h>

class ProcessCommand
{
  public:

    //for writing from Arduino 1 
    void WriteState(int nState);
    void WriteXCentroid(float fX);


    //for reading by Arduino 2
    void  ReadState();
    void  ReadXCentroid();

  private:

    //for writing state
    const int m_nDigitalWriteBit0Pin = 21; // loc 26
    const int m_nDigitalWriteBit1Pin = 20; // loc 25
    const int m_nDigitalWriteBit2Pin = 16; // loc 21 
    int m_arrStateBits[3];

    //for writing x centroid
    const	int m_nPWMpin = 10;         //~D10
		//mbed::PwmOut m_PWMpin;
    mbed::PwmOut pwmPin( digitalPinToPinName( nPWMpin ) );    

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




