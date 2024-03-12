//Display_test_V0a.ino

//based on pcb_test_oled_3_V0a.ino
//created: 26 July 2023
//last updated: 25 February 2024
//J Canova
//jscanova@gmail.com

//based on ssd1306_128x32_i2c.ino


/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x32 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {
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
}

void loop() {

  float fValue = 0.0;
  testDrawValue(fValue);
  testdrawline(0,((display.height()-1)/2),display.width()-1, ((display.height()-1)/2)); 

  display.clearDisplay();
  display.display(); 
  
  delay(200);

}



//functions---------------------
void testdrawline(int x0, int y0, int x1, int y1) {

  display.clearDisplay(); // Clear display buffer
  display.drawLine(x0, y0, x1, y1, SSD1306_WHITE);
  display.display(); // Update screen with each newly-drawn line 
}



void testDrawValue(float fValue){

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

