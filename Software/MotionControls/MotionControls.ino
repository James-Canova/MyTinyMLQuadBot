//MotionControls.ino

//11 September 2023
//James Canova

//last updated 31 October 2023


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

  
  AllLedsOff();
  delay(500);

  LedOn(GREEN);
  delay(500);  

 

  
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









