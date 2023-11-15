//MotionCommands.ino

#include "MotionCommandWriteUtility.h"
#include "Constants.h"
#include <Arduino.h>
#include "States.h"
#include "mbed.h"
#include "LEDRGB.h"

MotionCommandWriteUtility m_aWriteUtility;

//for writing X centroid to Arduino 2 as PWM signal
mbed::PwmOut m_pwmPin( digitalPinToPinName( nPWM_PIN ) );

int m_arrBits[3];

String m_strState;

LEDRGB m_ledRGB;

volatile int m_nCounter;



void setup() {

  Serial.begin(9600);

  //for writing X centroid as a PWM signal
  m_pwmPin.period( 1.0 / nPWM_FREQUENCY );   //seconds

  //for writing state
  pinMode(nDIGITAL_OUTPUT_PIN_0, OUTPUT); //LSB
  pinMode(nDIGITAL_OUTPUT_PIN_1, OUTPUT);
  pinMode(nDIGITAL_OUTPUT_PIN_2, OUTPUT);

  m_nCounter = 0;
    
  //for pushbutton
  digitalWrite (nPUSHPUTTON_PIN, HIGH);  // internal pull-up resistor
  attachInterrupt(digitalPinToInterrupt(17), isrPushButton, RISING);
  //nPUSHPUTTON_PIN   

}


void loop() {

  String strOut;

  //read from Edge Impulse
  float fXCentroid;
  fXCentroid = 0.50;

  //set according to state diagram (Draftsight)
  m_strState = "Reset";

  //Write Data for reading by Arduino 2
  WriteData(m_strState, fXCentroid);

  if (m_nCounter == 0)
  {
    strOut = "Reset";
    m_ledRGB.AllLedsOff();
    m_ledRGB.LedOn(RED);
  }

  if (m_nCounter == 1)
  {
    strOut = "Ready";
    m_ledRGB.AllLedsOff();
    m_ledRGB.LedOn(GREEN);    
  }

  if (m_nCounter == 2)
  {
    strOut = "Walk";
    m_ledRGB.AllLedsOff();
    m_ledRGB.LedOn(BLUE);
    
  }

  strOut = "State: " + strOut;
  Serial.println(strOut);


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
  byte byteIndex;

  byteIndex = FindIndex(strState);

  nDigitalWriteValue0 = bitRead(byteIndex,0);
  nDigitalWriteValue1 = bitRead(byteIndex,1);
  nDigitalWriteValue2 = bitRead(byteIndex,2);

  digitalWrite(nDIGITAL_OUTPUT_PIN_0, nDigitalWriteValue0);
  digitalWrite(nDIGITAL_OUTPUT_PIN_1, nDigitalWriteValue1);
  digitalWrite(nDIGITAL_OUTPUT_PIN_2, nDigitalWriteValue2);
}



/////////////////////////////////////////////////////////
//WriteXCentroid
void WriteXCentroid(float fXCentroid)
{
  float fDutyCycle;

	fDutyCycle = fXCentroid;  //0->1, 0V-3.3V

  m_pwmPin.write(fDutyCycle);
}



/////////////////////////////////////////////////////////
//FindIndex
byte FindIndex(String strState)
{
  byte byteIndex;
  byteIndex = 0;

  int n = sizeof(arrSTATES) / sizeof(arrSTATES[0]);
  
  for(int i=0; i<n; i++)
  {
      if(arrSTATES[i] == strState)
      {
          //If current value is equal to our element
          //then save value and break the loop
          byteIndex = i;
          break;
      }
  } 
  return byteIndex;
}


void ConvertIntToBinary(int nIndex,int &nBit2,int &nBit1,int &nBit0)
{
  nBit2 = 1;
  nBit1 = 1;       
  nBit0 = 1;
}



///////////////////////////////////////////////////////////////
//ISR
///////////////////////////////////////////////////////////////
void isrPushButton() {
  m_nCounter = m_nCounter + 1;
  if (m_nCounter > 2) {
    m_nCounter = 0;
    }
}