
//servo3_V0a.ino

//modified by: James Canova, jscanova@gmail.com
//created:13 December 2022
//last updated: 23 March 2023


//For centering all servos etc.

/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 8 servos, one after the other on the
  first 8 pins of the PCA9685

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815
  
  These drivers use I2C to communicate, 2 pins are required to  
  interface.

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/
//CCW is '+' and CW is '-'


#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

//Define constants
#define SERVOMIN_DEG  45
#define SERVOMAX_DEG  -45

#define SERVOMIN  100 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  645 // This is the 'maximum' pulse length count (out of 4096)
#define SERVOMID  256 // Appproximately zero position

#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

int nCounter = 0;  //for counting and ending loop
int nNumberLoops = 1;

//Setup
void setup() {
  
  Serial.begin(9600);
  Serial.println("Testing.");
  
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  delay(10);  
}



//Main loop
void loop() {

  //initialize variables
  uint8_t servonum;
  uint16_t pulselen;
  float fDegrees;

  String strOut;
  
  
  //center all servos
  for (int servonum = 0; servonum < 9; servonum++) {

      fDegrees = 0.0;  //center position
      pulselen = ConvertDegToPulseLen(fDegrees);
      pulselen = CheckPulseLenLimits(pulselen);  

      strOut = ("pulselen: " + String(pulselen));
      Serial.println(strOut);

      //move servo
      pwm.setPWM(servonum, 0, pulselen);
      
      delay(500);
    }



//swing servos, adding one at a time. Angle = -10[deg] to 10[deg]
  float fCurrentAngle;

  for (servonum = 0; servonum < 9; servonum++) {

      for (int nAngle = -10; nAngle <= 10; nAngle = nAngle + 2) {
    
        fCurrentAngle = (float)nAngle;
    
        pulselen = ConvertDegToPulseLen(fDegrees);
        pulselen = CheckPulseLenLimits(pulselen);     
        pwm.setPWM(servonum, 0, pulselen);     //move servo

      }

      for (int nAngle = 10; nAngle >= 10; nAngle = nAngle - 2) {
    
        fCurrentAngle = (float)nAngle;
    
        pulselen = ConvertDegToPulseLen(fDegrees);
        pulselen = CheckPulseLenLimits(pulselen);     
        pwm.setPWM(servonum, 0, pulselen);     //move servo

      }
        
      
    }

 

 

/*
//drive servos one at a time from min to max pulse length
 //center all servos
for (int servonum = 0; servonum < 9; servonum++) {
  for (int nPulseLength = 200; nPulseLength < 300; nPulseLength = nPulseLength + 10) {

        strOut = ("nPulseLength: " + String(nPulseLength));        
        Serial.println(strOut);

        strOut = ("servonum: " + String(servonum));        
        Serial.println(strOut);

        //move servo
        pwm.setPWM(servonum, 0, nPulseLength);
        
        delay(500);
      }
}
*/
    

/*
    Serial.println("-------\n");

    //exit loop
    nCounter = nCounter + 1;
    if (nCounter >= nNumberLoops)
    {
      delay(500);
      Serial.println("Exiting sketch.");
      exit(0);
    };
*/

    delay(1000);

}



//Function definitions------
int CheckPulseLenLimits(int pulselen)
  {
   if (pulselen > SERVOMAX) 
      {
        int old_pulselen = pulselen;
        pulselen = SERVOMAX;
        Serial.println("Pulse length too long and was reset to SERVOMAX."); 
        Serial.println(old_pulselen);           
        Serial.println("\n");      
      }
  
     if (pulselen < SERVOMIN)
      {
        pulselen = SERVOMIN;
        Serial.println("Pulse length too short and was reset to SERVOMIN.");      
        Serial.println("\n");           
      }    

    return pulselen;
  }


void PrintPulseLength(int num, int pulselen)
  {
    String strOne = String(num) + ": Pulse length: ";
    String strOut = strOne + String(pulselen);
    Serial.println(strOut);
  }


int ConvertDegToPulseLen(float fDegrees)
  {
    float fPulseLen;
    uint16_t nPulseLen;

    fPulseLen = (1.14*pow(10,-4))*pow(fDegrees,3) + 0.0141*sq(fDegrees) + 2.1*fDegrees + 256;
    nPulseLen = int(fPulseLen);  
    
    return nPulseLen;
  }
