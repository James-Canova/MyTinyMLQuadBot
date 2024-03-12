//LED_test_V0a.ino

//23 February 2024
//based on Arduino test sketch: Blink.ino
//James Canova
//jscanova@gmail.com

/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

#define RED 22     
#define BLUE 23     
#define GREEN 24


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);

  //turn all LEDs off
  digitalWrite(RED, HIGH);   
  digitalWrite(BLUE, HIGH); 
  digitalWrite(GREEN, HIGH); 
}

// the loop function runs over and over again forever
void loop() {

  //RED on
  digitalWrite(RED, LOW); 
  delay(1000);     

  //RED off
  digitalWrite(RED, HIGH); 
  delay(1000);    

  //GREEN on
  digitalWrite(GREEN, LOW); 
  delay(1000);     

  //GREEN off
  digitalWrite(GREEN, HIGH); 
  delay(1000);    



}
