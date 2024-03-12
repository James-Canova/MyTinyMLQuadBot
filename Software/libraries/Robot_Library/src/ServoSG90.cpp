//ServoSG90.cpp

#include "ServoSG90.h"		


//Note:
//Positve angles == counter clockwise in servo frame (i.e Z axis or when viewed from top)
//Negative angles == clockwise 


//Function definitions------
//public-----
void ServoSG90::Begin()
{
	m_PWM = Adafruit_PWMServoDriver(); 
	
	m_PWM.begin();
	m_PWM.setOscillatorFrequency(OSCILLATOR_FREQ);
	m_PWM.setPWMFreq(SERVO_FREQ) ;	
	
}	


void ServoSG90::Initialize(int nServoNumber, bool bAxisAligned)
{
	m_nServoNumber = nServoNumber;
	m_bAxisAligned = bAxisAligned;
}



void ServoSG90::SetServoAngleDeg(float fDegrees)   
{  
	float fPulseLen; 

	if(!m_bAxisAligned){
		fDegrees = -1 * fDegrees;
	}
	
	fPulseLen = ConvertDegToPulseLen(fDegrees);
	m_PWM.setPWM(m_nServoNumber, 0,  fPulseLen);  
}	  


//private----
//to prevent attempting to drive servo outside +/-90 deg limits
float ServoSG90::CheckPulseLenLimits(float fPulselen)
 {
   if (fPulselen > PULSELEN_MAX) 
      {
        fPulselen = PULSELEN_MAX;  
      }
  
     if (fPulselen < PULSELEN_MIN)
      {
        fPulselen = PULSELEN_MIN;        
      }    

    return fPulselen;
  }


//Degrees is +CCW when viewing servo from top
//equation generated experimentally
float ServoSG90::ConvertDegToPulseLen(float fDegrees)
  {
    float fPulseLen;
	
	//determined experimentally
	fPulseLen = 2.07 * fDegrees + 291.0;  //new 7 April 2023  

	fPulseLen = CheckPulseLenLimits(fPulseLen);

	return fPulseLen;
  }
  
  


