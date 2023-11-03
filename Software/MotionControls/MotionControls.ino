//MotionControls.ino

//#include ObjDetPH;

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

float m_fXCentroid, m_fOldXCentroid;
String m_strState, m_strOldState;

void setup(){
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
  display.display();
  delay(2000);

  m_fXCentroid = -99.0;
  m_fOldXCentroid = -99.0;
  m_strState = "none";
  m_strOldState = "none";

}


void loop() {

  //read state and x centroid---
  m_strState = "Reset";
  m_fXCentroid = 0.55;
  //reading state and x centroid complete---

  if ( (m_strOldState != m_strState) || (m_fOldXCentroid != m_fXCentroid))
  {
    DrawToOLED(m_strState, m_fXCentroid);
  }

  m_fOldXCentroid = m_fXCentroid;
  m_strOldState = m_strState;


  //put state switch case here------



  
  delay(200);


}



///////////////////////////////////////////////////////////////
//Functions: OLED
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
void DrawToOLED(String m_strState, float m_fXCentroid)
{

  String strOut;

  int nYFirstLine = 4;
  int nYSecondLine = 16;  
  int nTextSize = 1;

  display.clearDisplay();

  display.setTextSize(nTextSize);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text

  //print first line which is the state---
  display.setCursor(0,nYFirstLine);             
  strOut = "State: ";
  strOut = strOut + m_strState;
  display.println(strOut);


  //print second line which is the X centroid---
  display.setCursor(0,nYSecondLine);   
  strOut = "X Centroid: ";
  strOut = strOut + String(m_fXCentroid,2);
  display.println(strOut);

  display.display(); 

}