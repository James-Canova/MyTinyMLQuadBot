//ServoSG90.h

#ifndef ServoSG90_h 
#define ServoSG90_h


#include <Adafruit_PWMServoDriver.h>
#include <Arduino.h>


class ServoSG90
{

  public:

		void Begin();
		
		void Initialize(int nServoNumber, bool bAxisAligned);
 
		void SetServoAngleDeg(float fDegrees);	
		
		
  private:
		Adafruit_PWMServoDriver m_PWM;
		
		int m_nServoNumber;
		bool m_bAxisAligned;
		
		float CheckPulseLenLimits(float fPulselen);	
		float ConvertDegToPulseLen(float fDegrees);	
		
		const int SERVO_FREQ = 50.0;   //Hz,  // Analog servos run at ~50 Hz updates
		const int OSCILLATOR_FREQ  = 27000000;   //Hz
		
		//determined experimentally
		//fPulseLen = 2.07 * fDegrees + 291.0;  //new 7 April 2023  
		// This is the minimum pulse length count (out of 4096) for servos
		//corresponds to +90 [deg] (clockwise) accordiong to manufactures definitions of + angle
		const float PULSELEN_MIN  = 100.0;

		// This is the maximum pulse length count (out of 4096)  for servos
		//corresponds to -90 [deg] (counter-clockwise) accordiong to manufactures definitions of + angle
		const float PULSELEN_MAX = 500;
};

#endif
