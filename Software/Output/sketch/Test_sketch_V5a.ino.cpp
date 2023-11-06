#include <Arduino.h>
#line 1 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/test_sketches/Test_sketch_V5a/Test_sketch_V5a.ino"
//Test_sketch_V5a.ino
//was: pcb_test_push_button_V0a.ino

////for pushbutton and interupts to Reset->Ready->Reset....

//5 November 2023

//note: pin nPUSHPUTTON (push button on Arduino 1 is default HIGH)

#include "Constants.h"
//#include "mbed.h"

//PinName pnPBpin = (PinName)nPUSHPUTTON_PIN;
//mbed::InterruptIn m_pbPushbutton(pnPBpin);

#include "LEDRGB.h"

LEDRGB m_ledRGB;

String m_strState;
String m_strOldState;

String m_strTemp;

volatile int m_nCounter;

volatile bool m_bFlag;


///////////////////////////////////////////////////////////////
//ISR
///////////////////////////////////////////////////////////////
#line 33 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/test_sketches/Test_sketch_V5a/Test_sketch_V5a.ino"
void isrPushButton();
#line 39 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/test_sketches/Test_sketch_V5a/Test_sketch_V5a.ino"
void setup();
#line 64 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/test_sketches/Test_sketch_V5a/Test_sketch_V5a.ino"
void loop();
#line 33 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/test_sketches/Test_sketch_V5a/Test_sketch_V5a.ino"
void isrPushButton() {
  m_bFlag != m_bFlag;
}


 
void setup() {
    //put your setup code here, to run once:

    Serial.begin(9600);


    m_ledRGB.Initialize();	
    m_ledRGB.AllLedsOff();
    //m_ledRGB.LedOn(GREEN);

    m_strState = "Reset";
    m_strOldState = "None"; 

    m_strTemp = "...";
    m_nCounter = 0;

    m_bFlag = true;

   //m_pbPushbutton.fall(&isrPushButton);  

    digitalWrite (nPUSHPUTTON_PIN, HIGH);  // internal pull-up resistor
    attachInterrupt(digitalPinToInterrupt(17), isrPushButton, CHANGE);   

}

void loop() {
  //put your main code here, to run repeatedly:

  if (m_bFlag)
  {
    m_ledRGB.AllLedsOff(); 
    m_ledRGB.LedOn(RED);

  } else {
    m_ledRGB.AllLedsOff(); 
  }

 /*
  switch (m_nCounter) {

     case 0:   //Reset (straighten legs)
        m_strTemp = "...";    
        m_ledRGB.AllLedsOff(); 
        m_ledRGB.LedOn(RED);
        delay(2000);
       break;

     case 1:  //Ready
        m_strTemp = "...";
        m_ledRGB.AllLedsOff(); 
        //m_ledRGB.LedOn(GREEN);        
       break;

     case 2:  //Sit
        m_strTemp = "...";
        m_ledRGB.AllLedsOff(); 
        //m_ledRGB.LedOn(BLUE);   
       break;

     case 3:  //Walk
        m_strTemp = "...";
       break;

     case 4:  //Pause
        m_strTemp = "...";
       //put 2nd level state for neck movement
       break;

     default: 
        m_strTemp = "...";
   }  //end switch

  delay(500);

  */

}






/*
  m_nCounter = m_nCounter + 1;
  if (m_nCounter > 2)
  {
    m_nCounter = 0;
  }
*/
