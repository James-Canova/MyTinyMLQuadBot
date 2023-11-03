//pcb_test_led_V0a

//from: https://support.arduino.cc/hc/en-us/articles/
//360016724140-How-to-control-the-RGB-LED-and
//-Power-LED-of-the-Nano-33-BLE-boards-

//folder: Project 10b

//James Canova

 #define RED 22     
 #define BLUE 24     
 #define GREEN 23

void setup() {
  // put your setup code here, to run once:

  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);  

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(RED, LOW); // turn the LED off by making the voltage LOW
  delay(1000);            // wait for a second
  digitalWrite(GREEN, LOW);
  delay(1000);  
  digitalWrite(BLUE, LOW);
  delay(1000);  
  digitalWrite(RED, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(1000);                         
  digitalWrite(GREEN, HIGH);
  delay(1000);  
  digitalWrite(BLUE, HIGH);
  delay(1000);    
}
