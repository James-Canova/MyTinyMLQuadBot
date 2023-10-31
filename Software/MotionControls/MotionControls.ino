//MotionControls.ino

//11 September 2023
//James Canova

//last updated 30 October 2023

//reads output of low pass filter (0v...3.3v) on analog pin  (0..)
//and displays on OLED 

const int nAnalogReadPin = 15;         //D15/A1

const int nDigitalReadBit0Pin = 7;
const int nDigitalReadBit1Pin = 8;
const int nDigitalReadBit2Pin = 9;



#include "MotionContolsInterface.h"
#include "States.h"


#define RED 22     
#define BLUE 23     
#define GREEN 24 

//define global variables
Quadruped aQuadruped;
float fNeckAngle;
list<PairValues> m_lstFootPositions;

//for command from other Arduino, 3 digital pins and switch on D11, second Arduino
//see States.h
int nCommand;

float fTurnRate;   

String strOut;

void setup() {

  aQuadruped.Initialize(); 

  // open a serial connection
  Serial.begin(9600);

  // change the resolution to 12 bits (default is 10 bits)
  //12 bits == 0...4095
  analogReadResolution(12);   
  pinMode(nAnalogReadPin, INPUT); //configured as an input

  pinMode(nDigitalReadBit0Pin, INPUT);    
  pinMode(nDigitalReadBit1Pin, INPUT); 
  pinMode(nDigitalReadBit2Pin, INPUT); 


  

  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT); 

}


  delay(2000);
}

void loop() {

  String strOut;

  int nBit0;
  int nBit1;
  int nBit2;
  int arrBit[3];

  AllLedsOff();
  delay(500);

  LedOn(GREEN);
  delay(500);  

  nBit0 = digitalRead(nDigitalReadBit0Pin);   
  nBit1 = digitalRead(nDigitalReadBit1Pin);
  nBit2 = digitalRead(nDigitalReadBit2Pin); 

  arrBit[0] = nBit0;
  arrBit[1] = nBit1; 
  arrBit[2] = nBit2;
  
  strOut = BitsToSting(arrBit);

  
  // nCommand = 3;
  // fTurnRate = 0.0;   //-1 to 1



  // switch (nCommand) {

  //   case 0:  //straighten legs
  //     aQuadruped.StraightenLegs();
  //     strOut = ("Straighten legs.");
  //     Serial.println(strOut);
  //     break;

  //   case 1:  //ready
  //     aQuadruped.Ready();       
  //     strOut = ("Ready.");
  //     Serial.println(strOut); 
  //     break;
      
  //   case 2:  //sit
  //     aQuadruped.Sit();        
  //     strOut = ("Sit.");
  //     Serial.println(strOut);
  //     break;

  //   case 3:  //Crawl
  //     aQuadruped.Crawl(fTurnRate);
  //     strOut = ("rawl...");
  //     Serial.println(strOut);    
  //     break;

  //   case 4:  //Pause walk
  //     aQuadruped.PauseWalk();
  //     strOut = ("Pause walk.");
  //     Serial.println(strOut);     
  //     break;

  //   case 5:  //Set neck angle
  //     fNeckAngle = -10.0;
  //     aQuadruped.SetNeckAngle(fNeckAngle);
  //     strOut = ("Set neck angle.");      
  //     Serial.println(strOut);
  //     break;

  //   default:
  //     strOut = ("Invalid command.");
  //     Serial.println(strOut);
  // }  //end switch
    

  delay(1000); 

}


//Functions-------------------------------------------
void AllLedsOff()
{
  digitalWrite(RED, HIGH); 
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
}


void LedOn(int nPin)
{
  digitalWrite(nPin, LOW);
}


String BitsToSting(int* arrBits)
{
  String strState;
  int nIndex;

  nIndex = 4 * arrBits[2] + 2 * arrBits[1] + arrBits[0];

  strState = arrStates[nIndex];

  return strState;
}







