//Arduino_2.ino

//11 September 2023
//James Canova

//last updated 7 October 2023

//reads output of low pass filter (0v...3.3v) on analog pin  (0..)
//and displays on OLED 

const int nAnalogReadPin = 15;         //D15/A1

const int nDigitalReadBit0Pin = 7;
const int nDigitalReadBit1Pin = 8;
const int nDigitalReadBit2Pin = 9;

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "Quadruped.h"
#include "States.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

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


  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever

  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT); 

}


  // Clear the display buffer and write to screen
  display.clearDisplay();
  display.display();
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

  //display value on OLED
  //strOut ="String";
  DrawStringValue(strOut);


  //analog value
  //int nAnalogValue;

  //nAnalogValue  = analogRead(nAnalogReadPin);
  //nAnalogValue = 1000;
  
  //strOut = String(nAnalogValue);   
  //strOut = "Analog value: " + strOut;
  //DrawIntValue(nAnalogValue);

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







void DrawIntValue(int nValue ) {

  String strOut;

  display.clearDisplay();

  display.setTextSize(1);                     // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);                     // Start at top-left corner

  strOut = "Value is: ";
  strOut = strOut + String(nValue);
  display.println(strOut);

  display.display();

}

void DrawStringValue(String strValue ) {

  String strOut;

  display.clearDisplay();

  display.setTextSize(1);                     // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);                     // Start at top-left corner

  strOut = "Current state: ";
  strOut = strOut +strValue;
  display.println(strOut);

  display.display();

}
