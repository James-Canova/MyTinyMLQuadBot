# 1 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionControls/MotionControls.ino"
//MotionControls.ino


//#include "MotionControlsInterface.h";

# 7 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionControls/MotionControls.ino" 2
# 8 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionControls/MotionControls.ino" 2

# 10 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionControls/MotionControls.ino" 2
# 11 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionControls/MotionControls.ino" 2
# 12 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/MotionControls/MotionControls.ino" 2

#define SCREEN_WIDTH 128 /* OLED display width, in pixels*/
#define SCREEN_HEIGHT 32 /* OLED display height, in pixels*/

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET 4 /* Reset pin # (or -1 if sharing Arduino reset pin)*/
#define SCREEN_ADDRESS 0x3C /*|< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32*/
Adafruit_SSD1306 display(128 /* OLED display width, in pixels*/, 32 /* OLED display height, in pixels*/, &Wire, 4 /* Reset pin # (or -1 if sharing Arduino reset pin)*/);


float m_fXCentroid, m_fOldXCentroid;
String m_strState, m_strOldState;

void setup(){
  Serial.begin(9600);


  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(0x02 /*|< Gen. display voltage from 3.3V*/, 0x3C /*|< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32*/)) {
    Serial.println((reinterpret_cast<const __FlashStringHelper *>(("SSD1306 allocation failed"))));
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
  m_strState = ReadState();
  m_fXCentroid = ReadXCentroid();

  //reading state and x centroid complete---

  if ( (m_strOldState != m_strState) || (m_fOldXCentroid != m_fXCentroid))
  {
    DrawToOLED(m_strState, m_fXCentroid);
  }

  m_fOldXCentroid = m_fXCentroid;
  m_strOldState = m_strState;


  //write X centroid and state to pins----
  DrawToOLED(m_strState, m_fXCentroid);
  //WriteState(m_strState); 
  //WriteXCentroid(m_fXCentroid);


  //put state switch case here------


  delay(200);

}



///////////////////////////////////////////////////////////////
//Functions: OLED
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
void DrawToOLED(String strState, float fXCentroid)
{

  String strOut;

  int nYFirstLine = 4;
  int nYSecondLine = 16;
  int nTextSize = 1;

  display.clearDisplay();

  display.setTextSize(nTextSize); // Normal 1:1 pixel scale
  display.setTextColor(1 /*|< Draw 'on' pixels*/); // Draw white text

  //print first line which is the state---
  display.setCursor(0,nYFirstLine);
  strOut = "State: ";
  strOut = strOut + strState;
  display.println(strOut);


  //print second line which is the X centroid---
  display.setCursor(0,nYSecondLine);
  strOut = "X Centroid: ";
  strOut = strOut + String(fXCentroid,2);
  display.println(strOut);

  display.display();

}


///////////////////////////////////////////////////////////////
//Functions: For MotionCommandsInterface (but temporarily here
// becuase of mbed problem
//makes use of MotionCommandWriteUtility which would normally
//be connected to MotionCommandsInterface
///////////////////////////////////////////////////////////////
//ReadState
String ReadState()
{

  int nBit0;
  int nBit1;
  int nBit2;
  int arrBit[3];

  String strReadState;

  nBit0 = digitalRead(nDIGITAL_INPUT_PIN_0);
  nBit1 = digitalRead(nDIGITAL_INPUT_PIN_1);
  nBit2 = digitalRead(nDIGITAL_INPUT_PIN_2);

  nBit0 = 0;
  nBit1 = 0;
  nBit2 = 1;

  arrBit[0] = nBit0;
  arrBit[1] = nBit1;
  arrBit[2] = nBit2;

  strReadState = BitsToString(arrBit);

  return strReadState;

}


///////////////////////////////////////////////////////////////
//ReadState
String BitsToString(int* arrBit)
{
    String strState;
    int nIndex;

    //nIndex =  (arrBit[2] * 4.0) + (arrBit[1] * 2.0) + arrBit[0];

    strState = arrSTATES[nIndex];

    //strState = String(nIndex);

    return strState;

}

///////////////////////////////////////////////////////////////
//ReadXCentroid
float ReadXCentroid()
{
  int nReadValue;

  //read output of low pass filter (0v...3.3v) on analog pin 
  analogReadResolution(nANALOG_INPUT_RESOLUTIION);
  nReadValue = analogRead(nANALOG_INPUT_PIN); //(0..4095  ==  12 bit)
  return nReadValue;

}
