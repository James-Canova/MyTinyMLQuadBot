#include <Display.h>

//Display_class_test_V0a.ino

//modified by: James Canova, jscanova@gmail.com
//created: 1 March 2024
//last updated: 1 March 2024

Display  m_Display = Display();

int const DELAY = 250;

int nCount = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  m_Display.Begin();

  delay(DELAY);  

}

void loop() {
  // put your main code here, to run repeatedly:

  if (nCount < 1)
  {
    m_Display.Initialize();

    nCount ++;
  }

  float fValue;
  fValue = 10.0;
  m_Display.DrawFloatValue(fValue);

}
