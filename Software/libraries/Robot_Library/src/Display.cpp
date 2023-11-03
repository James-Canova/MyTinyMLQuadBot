//Display.cpp

#include "Display.h"

void  Display::Initialize()
{
  Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
	display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
	display.clearDisplay();
  display.display();
}


void Display::DrawFloatValue(float fValue){

  String strOut;

  display.clearDisplay();

  display.setTextSize(1);                     // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);                     // Start at top-left corner

  strOut = "Value is: ";
  strOut = strOut + String(fValue,1);
  display.println(strOut);

  display.display();

} 








