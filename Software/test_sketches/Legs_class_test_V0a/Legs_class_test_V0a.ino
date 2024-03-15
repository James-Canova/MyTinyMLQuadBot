//Legs_class_test_V0a.ino

//tells Legs class object to walk, pause etc. tbd
//legs sends pt indexes to each leg

//start with all the same

//7 March 2024
#include <Legs.h>

Legs m_Legs = Legs();

int nCount = 0;
int const DELAY = 500;

void setup() {

  Serial.begin(9600);

  m_Legs.Begin();  

  delay(250);

}

void loop() {
  String strOut;

  if (nCount < 1)  //so just initialized once
  {
    m_Legs.Initialize();
    nCount = nCount + 1;
    delay(DELAY);    
  }

  //walk
  for (nCount = 0; nCount < 5; nCount++) {
    m_Legs.Walk();
    delay(500);
  }

  //pause walk
  //for (nCount = 0; nCount < 10; nCount++) {
  //  m_Legs.PauseWalk(); 
  //}

  //exit(0);

  delay(DELAY);

}
