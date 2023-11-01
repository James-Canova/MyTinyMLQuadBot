//MotionCommands.ino

#include "LEDRGB.h"
#include "States.h"
#include "PointXY.h"

//#include "ProcessCommand.h"
#include "mbed.h"

LEDRGB m_ledRGB;

//ProcessCommand m_pcProcessCommand;

int m_nStateIndex;
String m_strState;

PointXY m_xyCentroid;
float m_xCentroid;

float fTime_Sec, fTime_Inc_Sec;

const int nPWMpin = 10;         //~D10
const int nPWM_FREQUENCY = 500; //Hz, 500 is default, I think max is 31KHz

mbed::PwmOut pwmPin( digitalPinToPinName( nPWMpin ) );

void setup() {

	Serial.begin(9600);

	m_ledRGB.Initialize();
	m_ledRGB.AllLedsOff();

	m_nStateIndex = 0; //Reset
	m_xyCentroid.SetValues(0.0, 0.0);

	//for sin wave generation (initial)
	fTime_Sec = 0.0;
	fTime_Inc_Sec = 0.0;	


	pwmPin.period( 1.0 / nPWM_FREQUENCY );   //must be in seconds

}


void loop() {
	
	m_ledRGB.AllLedsOff();
	delay(500);

	//controlled according to state diagram-----
	m_strState = arrStates[m_nStateIndex];

	//from object detection------
	//m_xyCentroid.SetValues(20.0, 0.0);
	//m_xCentroid = m_xyCentroid.GetX();
	//duty cycle to model (scaled) m_xCentroid
	fTime_Sec = fTime_Sec + fTime_Inc_Sec;
	float fDutyCycle = SinWave(fTime_Sec, fTime_Inc_Sec);


	//send duty cycle to pwm==========
	//OPTION #1
	pwmPin.write(fDutyCycle);

	//send duty cycle to pwm==========
	//OPTION #2
	//m_pcProcessCommand.WriteXCentroid(fDutyCycle);

	m_ledRGB.LedOn(BLUE);
	delay(500);

}


float SinWave(float fTimeSec, float &fTime_Inc_Sec)
{
	float fSinValue;

	float fSineWave_Amplitude = 0.95 * (1.0/2.0);
	float fSineWave_Y_offset = 0.5;

	float fSineWave_Freq_Hz;
	float fAngle_Deg;
	float fAngle_Rad;
	float fRotationalSpeed_Deg;

	fRotationalSpeed_Deg = fSineWave_Freq_Hz * 360.0;  //cycles/sec * deg/cycle = deg/sec 

	fSineWave_Freq_Hz = 1.0;
	fTime_Inc_Sec = (1.0/fSineWave_Freq_Hz) / 20.0;   //20 samples per cycle
	fRotationalSpeed_Deg = fSineWave_Freq_Hz * 360.0;  //cycles/sec * deg/cycle = deg/sec

	fAngle_Deg = fRotationalSpeed_Deg * fTime_Sec;
	fAngle_Rad = fAngle_Deg * (PI/180);
	fSinValue =  fSineWave_Amplitude * sin(fAngle_Rad) + fSineWave_Y_offset;

	return fSinValue;	
}


