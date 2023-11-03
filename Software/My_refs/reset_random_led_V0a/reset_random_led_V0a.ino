//reset_random_led_V0a.ino

//from: https://support.arduino.cc/hc/en-us/articles/
//360016724140-How-to-control-the-RGB-LED-and
//-Power-LED-of-the-Nano-33-BLE-boards-

//folder: Project 10e

//James Canova

 #define RED 22
 #define GREEN 23
 #define BLUE 24  


int nCount = 0;


void setup() {

  Serial.begin(9600);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);  
  pinMode(BLUE, OUTPUT);


}

void loop() {

  AllLedsOff();
  delay(1000); 

  if (nCount < 5){
    digitalWrite(RED, LOW);
    delay(500); 
  }

  nCount = nCount + 1;

}

void AllLedsOff()
{
  digitalWrite(RED, HIGH); 
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
}


void LedOn(int nPin)
{
  digitalWrite(nPin, LOW);
}
