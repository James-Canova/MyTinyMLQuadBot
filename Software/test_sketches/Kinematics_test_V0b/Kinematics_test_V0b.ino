
//Kinematics_test_V0b.ino

//James Canova, jscanova@gmail.com
//14 March 2023
//last updated: 3 March 2024

//To test inverse kinematics (LegKinematics class)

#include "InverseKinematics.h"

//define global variables
InverseKinematics m_InverseKinematics;

float m_arrFootPositionCoordsXY[12][2] = {
		{0.0, -65.0},
		{-10.0,-65.0},
		{-20.0,-65.0},
		{-30.0,-65.0},
		{-20.0, -59.0},
		{-10.0, -59.0},
		{0.0, -59.0},
		{10.0, -59.0},
		{20.0, -59.0},
		{30.0, -65.0},
		{20.0, -65.0},
		{10.0, -65.0}
		} ;




//Setup---------------------------------
void setup() {
  
  Serial.begin(9600);
  Serial.println("Testing.");
  
  delay(250);
}


//Main loop--------------------------
void loop() {

   int bResult = false;
   float fTheta1, fTheta2;
   float fTargetX;
   float fTargetY;
   float fErrMM;

   String strOut;
  
   for (int nIndex = 0; nIndex < 12; nIndex ++) {
 
      fTargetX = m_arrFootPositionCoordsXY[nIndex][0];
      fTargetY = m_arrFootPositionCoordsXY[nIndex][1];

      //strOut = String(nIndex) + "  X: " + String(fTargetX) + ",  Y: + " + String(fTargetY); 
      //Serial.println(strOut);  
      delay(500);

      //solve inverse kinematics
      bResult = m_InverseKinematics.CalculateAngles(fTargetX, fTargetY, 40.0, 33.0 , fTheta1, fTheta2, fErrMM);  //inverse kinematics	 
 
      strOut = String(nIndex) + "," + String(fTargetX) + "," + String(fTargetY) + 
        "," + String(fTheta1) + "," + String(fTheta2)  + "," + String(fErrMM);  

      if (bResult)
      {
        strOut = strOut + ", true";
          //Serial.println("Inverse kinematics ok.");
      } else {
          //Serial.println("Inverse kinematics failed.");
        strOut = strOut + ", false";    
      }

      //strOut = "Theta1: " + String(fTheta1) + ",  Theta2: + " + String(fTheta2);
      
      delay(250);

      Serial.println(strOut);
    }
    
    delay(500);

    //exit(0);

}  //end of main loop
