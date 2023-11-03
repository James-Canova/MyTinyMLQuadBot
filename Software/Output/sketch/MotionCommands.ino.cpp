#line 1 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
//MotionCommands.ino


#include "MotionCommandWriteUtility.h"
#include "mbed.h"
#include "Constants.h"
#include "Arduino.h"
#include "States.h"

MotionCommandWriteUtility aWriteUtility;

//const int nPWMpin = 10;         //~D10
//const int nPWM_FREQUENCY = 500; //Hz, 500 is default, I think max is 31KHz

mbed::PwmOut m_pwmPin( digitalPinToPinName( nPWM_PIN ) );

String m_strState;

#line 19 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
void setup();
#line 32 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
void loop();
#line 54 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
void WriteData(String strState, float fXCentroid);
#line 63 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
void WriteState(String strState);
#line 88 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
void WriteXCentroid(float fXCentroid);
#line 105 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
int FindIndex(String strState);
#line 126 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
void ConvertIntToBinary(int nIndex,int &nBit2,int &nBit1,int &nBit0);
#line 19 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
void setup() {

  m_strState = "Reset";

  m_pwmPin.period( 1.0 / nPWM_FREQUENCY );   //seconds

  pinMode(nDIGITAL_OUTPUT_PIN_0, OUTPUT); //D7, LSB
  pinMode(nDIGITAL_OUTPUT_PIN_1, OUTPUT);
  pinMode(nDIGITAL_OUTPUT_PIN_2, OUTPUT);

}


void loop() {

  //read from Edge Impulse
  float fXCentroid;
  fXCentroid = 0.55;

  //set according to state diagram (Draftsight)
  m_strState = "Reset";

  //Write Data for reading by Arduino 2
  WriteData(m_strState, fXCentroid);

  //state case switch goes here---

}  



/////////////////////////////////////////////////////////
// Functions for writing state and centroid
// (here until can move mbed to MotionCommandsInterface)
/////////////////////////////////////////////////////////
void WriteData(String strState, float fXCentroid)
{
  WriteState(strState); 
  WriteXCentroid(fXCentroid);
}


/////////////////////////////////////////////////////////
//WriteState
void WriteState(String strState)
{
  int nDigitalWriteValue0;  //LSB
  int nDigitalWriteValue1;
  int nDigitalWriteValue2;

  //find index of strState in arrSTATES
  int nIndex;
  
  nIndex = FindIndex(strState);


  nDigitalWriteValue0 = 0;
  nDigitalWriteValue1 = 1;
  nDigitalWriteValue2 = 0;

  digitalWrite(nDIGITAL_OUTPUT_PIN_0, nDigitalWriteValue0);
  digitalWrite(nDIGITAL_OUTPUT_PIN_1, nDigitalWriteValue1);
  digitalWrite(nDIGITAL_OUTPUT_PIN_2, nDigitalWriteValue2);
}



/////////////////////////////////////////////////////////
//WriteXCentroid
void WriteXCentroid(float fXCentroid)
{

  float fDutyCycle;
  fDutyCycle = fXCentroid;

  //const int m_nPWM_FREQUENCY = 500; //Hz, 500 is default
  //m_nPWMpin.period( 1.0 / nPWM_FREQUENCY );   //must be in seconds

	fDutyCycle = fXCentroid;  //0->1, 0V-3.3V

  m_pwmPin.write(fDutyCycle);
}



//FindIndex-----
int FindIndex(String strState)
{
  int nIndex;
  nIndex = -1;

  int n = sizeof(arrSTATES) / sizeof(arrSTATES[0]);
  
  for(int i=0;i<n;i++)
  {
      if(arrSTATES[i] == strState)
      {
          //If current value is equal to our element
          //then replace the index value and break the loop
          nIndex = i;
          break;
      }
  } 
  return nIndex;
}


void ConvertIntToBinary(int nIndex,int &nBit2,int &nBit1,int &nBit0)
{
  nBit2 = 1;
  nBit1 = 1;       
  nBit0 = 1;
}
