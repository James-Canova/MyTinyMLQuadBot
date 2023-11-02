//Test_sketch_V4a.ino


#include "States.h"

//String arrSTATES[8] = {"Reset", "Ready", "Sit", "Walk", "Pause","None", "None", "None"};

String arrStates[8];



void setup() {

  Serial.begin(9600);
 
}



void loop() {

  byte nBit0, nBit1, nBit2;

  String strState;
  strState = "Reset";

  //find index  
  byte nIndex = FindIndex(strState);
  String strOut = String(nIndex);
  Serial.println(strOut);

  //convert to three bits
  for (nIndex = 0; nIndex < 8; nIndex++)
  {
    ConvertIntToBinary(nIndex, nBit2, nBit1, nBit0);
    strOut = String(nIndex) + ": " + String(nBit2) + ", " + String(nBit1) + ", " + String(nBit1);
    Serial.println(strOut);
    delay(500);
  }

}



byte FindIndex(String strState)
{
  byte nIndex;
  nIndex = 8;

  int n = sizeof(arrSTATES) / sizeof(arrSTATES[0]);
  
  for(byte i=0;i<n;i++)
  {
      if(arrSTATES[i] == strState)
      {
          //If current value is equal to our element
          //then replace the index value and break the loop
          nIndex = i;
          break;
      }
  } 
  return nIndex;
}


void ConvertIntToBinary(byte nIndex,byte &nBit2,byte &nBit1,byte &nBit0)
{
  nBit2 = bitRead(nIndex, 2);
  nBit1 = bitRead(nIndex, 1);
  nBit0 = bitRead(nIndex, 0); 
}
