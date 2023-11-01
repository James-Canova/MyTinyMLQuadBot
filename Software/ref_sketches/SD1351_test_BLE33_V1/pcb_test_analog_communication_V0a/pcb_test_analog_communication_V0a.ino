//pcb_test_analog_communication_V0a

//was: Catbot_dev_7_V0a


//based on Arduino examples
//modified by James Canova
//jscanova@gmail.com

//19 July 2023

#include "mbed.h"

//for generating sin wave to be used as duty cycle (0.0 to 1.0)---
const float fSineWave_Amplitude = 0.95 * (1.0/2.0);
const float fSineWave_Y_offset = 0.5;

float fSineWave_Freq_Hz;
float fAngle_Deg;
float fAngle_Rad;
float fTime_Sec;
float fTime_Inc_Sec;
float fRotationalSpeed_Deg;
float fSinWaveValue;


//for PWM signal---
const int nPWMpin = 10;         //~D10nPWMpin = 10
const int nPWM_FREQUENCY = 500; //Hz, 500 is default, I think max is 31KHz

int nPWM_Period_usec;
float fPWM_Period_sec;
float fPWM_Frequency_Hz;  //should equal nPWM_FREQUENCY

float fDutyCycle;

mbed::PwmOut pwmPin( digitalPinToPinName( nPWMpin ) );


void setup() {

  pwmPin.period( 1.0 / nPWM_FREQUENCY );   //must be in seconds

  //for sin wave generation
  fTime_Sec = 0.0;
  fSineWave_Freq_Hz = 1.0;
  fTime_Inc_Sec = (1.0/fSineWave_Freq_Hz) / 20.0;   //20 samples per cycle

  fRotationalSpeed_Deg = fSineWave_Freq_Hz * 360.0;  //cycles/sec * deg/cycle = deg/sec 

}

void loop() {

   //generate sin wave value at current time which will be assigned to duty cycle
   fAngle_Deg = fRotationalSpeed_Deg * fTime_Sec;
   fAngle_Rad = fAngle_Deg * (PI/180);
   fSinWaveValue =  fSineWave_Amplitude * sin(fAngle_Rad) + fSineWave_Y_offset;
   

   //assign sin wave value to duty cycle
   fDutyCycle = fSinWaveValue;
   pwmPin.write(fDutyCycle);   
    
   nPWM_Period_usec = pwmPin.read_period_us();
   fPWM_Period_sec = float(nPWM_Period_usec)/(1000000.0);
   fPWM_Frequency_Hz = 5.0 / fPWM_Period_sec;

   String strOut;
   strOut = String(fDutyCycle, 1);   
   strOut = strOut;
   Serial.print(strOut); 
   Serial.print("\n");

   fTime_Sec = fTime_Sec + fTime_Inc_Sec;

   delay(300); //ms

}
