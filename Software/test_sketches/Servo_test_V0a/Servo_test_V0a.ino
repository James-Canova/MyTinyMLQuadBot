//Servo_test_V0a.ino

//based on servo3_V0b.ino

//modified by: James Canova, jscanova@gmail.com
//created:13 December 2022
//last updated: 26 February 2024

#include <Adafruit_PWMServoDriver.h>
#include <Constants.h>


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


#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

int nCount = 0;

//Define constants
#define SERVOMIN_DEG     -30
#define SERVOMAX_DEG      30
#define ANGLE_INC_DEG     5

#define DELAY 100  //ms


#define SERVOMIN  105 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  477 // This is the 'maximum' pulse length count (out of 4096)
#define SERVOMID  291 // Appproximately zero position

#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
#define OSC_FREQ   27000000


//Setup
void setup() {
  
  Serial.begin(9600);
  Serial.println("Testing.");
  
  pwm.begin();
  pwm.setOscillatorFrequency(OSC_FREQ);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  delay(DELAY);  
}



//Main loop
void loop() {

  //initialize variables
  uint8_t nServoNum;
  uint16_t pulselen;
  float fDegrees;

  String strOut;
  
 
  //center all servos----------------------------------------
  if (nCount < 1) { //so just do once
    for (int nServoNum = 0; nServoNum < 9; nServoNum++) {

        fDegrees = 0.0;  //center position
        pulselen = ConvertDegToPulseLen(fDegrees);
        pulselen = CheckPulseLenLimits(pulselen);  

        //strOut = ("pulselen: " + String(pulselen));
        strOut = ("Centering servo number: " + String(nServoNum));
        Serial.println(strOut);

        //move servo
        pwm.setPWM(nServoNum, 0, pulselen);
        
        delay(DELAY);
      }
    }
  //nCount = nCount + 1;


  //Swing servos one at a time. Angle = SERVOMIN_DEG[deg] to SERVOMAX_DEG[deg]-----
  for (nServoNum = 0; nServoNum < 2; nServoNum++) {
      //one way starting at 0 [deg]
      for (int nAngle = 0; nAngle <= SERVOMAX_DEG; nAngle = nAngle + ANGLE_INC_DEG) {
        SetServoDegrees(nServoNum, nAngle);   
        delay(DELAY);
        }

      //all the way back the other way
      for (int nAngle = SERVOMAX_DEG; nAngle >= SERVOMIN_DEG; nAngle = nAngle - ANGLE_INC_DEG) {
        SetServoDegrees(nServoNum, nAngle);
        delay(DELAY);        
        }  

      //back to center
      for (int nAngle = SERVOMIN_DEG; nAngle <= 0; nAngle = nAngle + ANGLE_INC_DEG) {
        SetServoDegrees(nServoNum, nAngle);
        delay(DELAY);        
        } 
  
    }
    delay(DELAY);

}   //end of main loop



//Function definitions------
void SetServoDegrees(int nServoNum, int nAngle)
  {

  uint16_t pulselen;  
    
  float fDegrees;

  fDegrees = (float)nAngle;

  pulselen = ConvertDegToPulseLen(fDegrees);
  pulselen = CheckPulseLenLimits(pulselen);     
  pwm.setPWM(nServoNum, 0, pulselen); 
  
  }



int CheckPulseLenLimits(int pulselen)  // put your main code here, to run repeatedly:
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

    fPulseLen = 2.1*fDegrees + 291;
    nPulseLen = int(fPulseLen);  
    
    return nPulseLen;
  }
