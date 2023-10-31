// MotionCommands.ino

// James Canova, jscanova@gmail.com
// last updated: 7 October 2023
// Working on walking using new statically stable crawl gait and adding Walk class

#include "MotionControlsInterface.h"
#include "States.h"
#include "PairValues.h"

#define RED 22
#define BLUE 24
#define GREEN 23

String strOut;

int nDelay = 500;

const int nDigitalWriteBit0Pin = 21; // loc 26
const int nDigitalWriteBit1Pin = 20; // loc 25
const int nDigitalWriteBit2Pin = 16; // loc 21

// Setup---------------------------------
void setup()
{

  Serial.begin(9600);

  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);

  pinMode(nDigitalWriteBit0Pin, OUTPUT);
  pinMode(nDigitalWriteBit1Pin, OUTPUT);
  pinMode(nDigitalWriteBit2Pin, OUTPUT);

  delay(500);
}

// Main loop--------------------------
void loop()
{

  AllLedsOff();
  delay(500);

  LedOn(BLUE);
  delay(500);

  if (arrStates[0] == "Reset")
  {
    Serial.println(arrStates[0]);
  }
  else
  {
    Serial.println("None");
  }

  int arrBits[3] = {1, 0, 1};
  String strState = "Reset";

  StateToBits(strState, arrBits);

  digitalWrite(nDigitalWriteBit0Pin, arrBits[0]);
  digitalWrite(nDigitalWriteBit1Pin, arrBits[1]);
  digitalWrite(nDigitalWriteBit2Pin, arrBits[2]);

  // nCommand = 3;

  // fTurnRate = 0.0;   //-1 to 1

  // switch (nCommand) {

  //   case 0:  //Reset (traighten legs)
  //     strOut = ("Reset.");
  //     Serial.println(strOut);
  //     break;

  //   case 1:  //ready
  //     strOut = ("Ready.");
  //     Serial.println(strOut);
  //     break;

  //   case 2:  //sit
  //     strOut = ("Sit.");
  //     Serial.println(strOut);
  //     break;

  //   case 3:  //Crawl
  //     strOut = ("rawl...");
  //     Serial.println(strOut);
  //     break;

  //   case 4:  //Pause walk
  //     strOut = ("Pause walk.");
  //     Serial.println(strOut);
  //     break;

  //   case 5:  //Set neck angle
  //     fNeckAngle = -10.0;
  //     strOut = ("Set neck angle.");
  //     Serial.println(strOut);
  //     break;

  //   default:
  //     strOut = ("Invalid command.");
  //     Serial.println(strOut);
  // }  //end switch

  delay(nDelay);

  // for debugging----------------
  //  strOut = "=================================";
  //  Serial.println(strOut);

  // strOut = aQuadruped.GetState();
  // strOut = "State:  " + strOut;
  // Serial.println(strOut);

  /*
    float fX, fY;
    int nCounter;
    m_lstFootPositions = aQuadruped.GetLstFootPositions();
    //iterate through list of points and print
    nCounter = 0;
    for (PairValues aPairCoordsXY : m_lstFootPositions)
    {
      fX = aPairCoordsXY.GetValue1();
      fY = aPairCoordsXY.GetValue2();
      strOut = String(nCounter) + ": " + String(fX) + ", " + String(fY);
      Serial.println(strOut);
      nCounter = nCounter + 1;
    }
    */

} // end of main loop

// Functions-------------------------------------------
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

void StateToBits(String strState, int *arrBits)
{
  arrBits[0] *= 1;
  arrBits[1] *= 0;
  arrBits[2] *= 1;
}
