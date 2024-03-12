//Leg_class_test_V0a.ino

//moves a foot in a path

//James Canova
//7 March 2024

#include <Leg.h>

Leg m_Leg_0 = Leg();

int nCount = 0;
int const DELAY = 250;

void setup() {

  Serial.begin(9600);

  m_Leg_0.Begin();  

  delay(DELAY);
}

void loop() {

  float x,y,T1,T2;
  String strOut;

  if (nCount < 1)  //so just initialized once
  {
    int nLegNum = 0;
    m_Leg_0.Initialize(nLegNum);
    nCount ++;
  }

  for (int nFootPositionIndex_Leg_0 = 0; nFootPositionIndex_Leg_0 < 12; nFootPositionIndex_Leg_0 ++)
  {
    x = m_Leg_0.Get_x();
		y = m_Leg_0.Get_y();
		T1 = m_Leg_0.Get_Theta1();
		T2 = m_Leg_0.Get_Theta2();
		
    strOut = String(x) + ", " + String(y) + ", " + String(T1) + ", " +  String(T2); 
    Serial.println(strOut);

    m_Leg_0.SetFootXYPos(nFootPositionIndex_Leg_0);
    delay(DELAY);
  }

}
