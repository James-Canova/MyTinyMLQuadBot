//Servo_calibration_V0a.ino

//James Canova, jscanova@gmail.com
//18 March 2023
//last updated 7 April 2023


//For finiding relation between pulselen and servo angle [deg]
//using drw in folder 10e


#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

//Define constants
#define SERVOMIN  100 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  645 // This is the 'maximum' pulse length count (out of 4096)
#define SERVOMID  256 // Appproximately zero position

#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600

int nCounter = 0;  //for counting and ending loop
int nNumberLoops = 5;

//Setup
void setup() {
                                                 
  Serial.begin(9600);
  Serial.println("Testing.");
  
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(50);  
  delay(10);  
}



//Main loop
void loop() {

  uint8_t servonum;
  servonum = 0;

  //initialize variables
  int nOption = 1;  
  

  uint16_t pulselen;  

  //center a servo
  if (nOption == 0){
    pulselen = 445;
    pwm.setPWM(servonum, 0, pulselen);    
  }



  uint16_t microsec;

  //min, max pulselen
  if (nOption == 1){
    pulselen = 92;       //original = 100 to 645 
    pwm.setPWM(servonum, 0, pulselen);    
    delay(500);


    pulselen = 475;       //original = 100 to 645 
    pwm.setPWM(servonum, 0, pulselen);    
    delay(500);
    
   }


  //min, mid, max microseconds
  if (nOption == 2){
    //full CCW, 1000
    //center, 1500
    //full CW, 2000
    
    microsec = 550;
    pwm.writeMicroseconds(servonum, microsec);
    delay(500);

    microsec = 1500;
    pwm.writeMicroseconds(servonum, microsec);   
    delay(500);
    
    microsec = 2450           ;
    pwm.writeMicroseconds(servonum, microsec);   
    delay(500);   
    
  }


  //center servos
  if (nOption == 3){
    for (servonum = 0; servonum < 1; servonum++) {      
      pwm.setPWM(servonum, 0, 256);    //256
    }
  }

/*
  //exit loop
  nCounter = nCounter + 1;
  if (nCounter >= nNumberLoops)
  {
    delay(500);
    Serial.println("Exiting sketch.");
    exit(0);
  }
  */

  delay(1000);

}
