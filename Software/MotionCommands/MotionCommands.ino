// MotionCommands.ino

// James Canova, jscanova@gmail.com
// last updated: 31 October 2023
// Working on walking using new statically stable crawl gait and adding Walk class

#include "MotionControlsInterface.h"
#include "States.h"
#include "LEDRGB.h"
#include "Constants.h"


int nDelay = 500;
LEDRGB ledRGB;



// Setup---------------------------------
void setup()
{
  Serial.begin(9600);
  delay(nDelay);
}

// Main loop--------------------------
void loop()
{


  

} // end of main loop



