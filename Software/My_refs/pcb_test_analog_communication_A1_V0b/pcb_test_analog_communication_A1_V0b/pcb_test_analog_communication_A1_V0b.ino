//pcb_test_analog_communication_A1_V0b
//generates a pwm signal at ~D10 (loc 13)

//was: Catbot_dev_7_V0a


//based on Arduino examples
//modified by James Canova
//jscanova@gmail.com

//19 July 2023
//last updated 4 August 2023

#include "mbed.h"


const int nPWMpin = 10;         //~D10
const int nPWM_FREQUENCY = 500; //Hz, 500 is default, I think max is 31KHz

float fDutyCycle;


mbed::PwmOut pwmPin( digitalPinToPinName( nPWMpin ) );


void setup() {

  pwmPin.period( 1.0 / nPWM_FREQUENCY );   //must be in seconds

}


void loop() {

   //fDutyCycle
   for (int i = 0; i <= 10; i++) {

    fDutyCycle = 0.1 * i;      
    pwmPin.write(fDutyCycle);

    String strOut;
    strOut = String(fDutyCycle, 1);   
    strOut = "Duty cycle: " + strOut;
    Serial.print(strOut); 
    Serial.print("\n");

    delay(10000);

   }  

}
