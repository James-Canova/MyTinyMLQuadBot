//Link_class_test_V0b

//James Canova, jscanova@gmail.com
//created: 28 February 2024
//last updated: 4 March 2024

//mpve one linlk

#include <Link.h>

Link m_Link0 = Link();

int nCount = 0;
int const DELAY = 250;

float const LINKMIN_DEG = -45;
float const LINKMAX_DEG = 45;
int const ANGLE_INC_DEG = 5;

void setup() {

  Serial.begin(9600);

  m_Link0.Begin();

  delay(DELAY);  
}

void loop() {

  if (nCount < 1)  
  {
    int nLinkNum = 0;
    m_Link0.Initialize(nLinkNum);
    nCount ++;
  }



  //one way starting at 0 [deg]
  for (int nAngleDeg = 0; nAngleDeg <= LINKMAX_DEG; nAngleDeg = nAngleDeg + ANGLE_INC_DEG) {
    m_Link0.SetLinkAngleDeg(nAngleDeg);
    delay(DELAY);
  }

  //all the way back the other way
  for (int nAngleDeg = LINKMAX_DEG; nAngleDeg >= LINKMIN_DEG; nAngleDeg = nAngleDeg - ANGLE_INC_DEG) {
    m_Link0.SetLinkAngleDeg(nAngleDeg);
    delay(DELAY);        
  }  

  //back to center
  for (int nAngleDeg = LINKMIN_DEG; nAngleDeg <= 0; nAngleDeg = nAngleDeg + ANGLE_INC_DEG) {
    m_Link0.SetLinkAngleDeg(nAngleDeg);
    delay(DELAY);        
  } 

  delay(DELAY);


}
