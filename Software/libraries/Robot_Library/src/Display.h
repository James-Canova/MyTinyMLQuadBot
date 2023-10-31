//Display.h

#ifndef Display_h 
#define Display_h

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Display
{
public:

	void  ReadValue();

private:
    float m_fX;  
};

#endif


/*
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
*/

/*
// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
*/


/*
  // Clear the display buffer and write to screen
  display.clearDisplay();
  display.display();
  */

 /*
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
*/

/*
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
*/