#include <Arduino.h>
#line 1 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
// MotionCommands.ino

// James Canova, jscanova@gmail.com
// last updated: 31 October 2023
// Working on walking using new statically stable crawl gait and adding Walk class

#include "MotionControlsInterface.h"
#include "States.h"
#include "LEDRGB.h"


int nDelay = 500;
LEDRGB ledRGB;



// Setup---------------------------------
#line 18 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
void setup();
#line 25 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
void loop();
#line 18 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionCommands/MotionCommands.ino"
void setup()
{
  Serial.begin(9600);
  delay(nDelay);
}

// Main loop--------------------------
void loop()
{


  

} // end of main loop




