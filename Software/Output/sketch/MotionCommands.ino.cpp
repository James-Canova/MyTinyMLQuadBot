#line 1 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
//MotionCommands.ino


#include "ObjDetPH.h"
#include "mbed.h"
#include "Constants.h"
#include "Arduino.h"
#include "States.h"

ObjDetPH aObjDet;

mbed::PwmOut m_pwmPin( digitalPinToPinName( nPWM_PIN ) );

String m_strState;


#line 17 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
void setup();
#line 30 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
void loop();
#line 52 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
void WriteData(String strState, float fXCentroid);
#line 61 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
void WriteState(String strState);
#line 86 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
void WriteXCentroid(float fXCentroid);
#line 96 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
int FindIndex(String strState);
#line 117 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
void ConvertIntToBinary(int nIndex,int &nBit2,int &nBit1,int &nBit0);
#line 17 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
void setup() {

  m_strState = "Reset";

  m_pwmPin.period( 1.0 / nPWM_FREQUENCY );   //seconds

  pinMode(nDIGITAL_OUTPUT_PIN_0, OUTPUT); //D7, most significant value
  pinMode(nDIGITAL_OUTPUT_PIN_1, OUTPUT);
  pinMode(nDIGITAL_OUTPUT_PIN_2, OUTPUT);

}


void loop() {

  //Read centroid from ObjDetPH
  float fXCentroid;
  fXCentroid = aObjDet.GetXCentroid();


  //Write Data for reading by Arduino 2
  WriteData(m_strState, fXCentroid);

}  



//------------------------------------------------------------------
//Functions---------------------------------------------------------
//Write functions will go in ProcessCommand when I figure
//out how to use mbed  outside of a .ino



//WriteData-----
void WriteData(String strState, float fXCentroid)
{
  WriteState(strState); 
  WriteXCentroid(fXCentroid);
}



//WriteState-----
void WriteState(String strState)
{
  int nDigitalWriteValue0;  //most significant bit
  int nDigitalWriteValue1;
  int nDigitalWriteValue2;

  //find index of strState in arrSTATES
  int nIndex;
  nIndex = FindIndex(arrSTATES, strState);


  
  nDigitalWriteValue0 = 0;
  nDigitalWriteValue1 = 1;
  nDigitalWriteValue2 = 0;

  digitalWrite(nDIGITAL_OUTPUT_PIN_0, nDigitalWriteValue0);
  digitalWrite(nDIGITAL_OUTPUT_PIN_1, nDigitalWriteValue1);
  digitalWrite(nDIGITAL_OUTPUT_PIN_2, nDigitalWriteValue2);
}




//WriteXCentroid-----
void WriteXCentroid(float fXCentroid)
{
    float fDutyCycle;

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
