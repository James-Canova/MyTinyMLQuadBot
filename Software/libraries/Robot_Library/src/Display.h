//Display.h

#ifndef Display_h 
#define Display_h

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int SCREEN_WIDTH = 128; // OLED display width, in pixels
const int SCREEN_HEIGHT = 32; // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
const int  OLED_RESET = 4; // Reset pin # (or -1 if sharing Arduino reset pin)
const int  SCREEN_ADDRESS = 0x3C;


class Display
{
public:

	void  Begin();
	void  Initialize();
	void DrawFloatValue(float fValue);

private:

  Adafruit_SSD1306 display;
};

#endif


