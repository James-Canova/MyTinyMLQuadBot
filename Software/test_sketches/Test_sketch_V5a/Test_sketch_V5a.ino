//Test_sketch_V5a.ino

//for pushbutton and interupts to Reset->Ready->Reset....

//was: pcb_test_push_button_V0a.ino

//James Canova, jscanova@gmail.com

//5 November 2023

//read  digital pin that has a switch and led connected
//when pin low turn RED LED on Arduino, otherwise GREEN
//Note: pin 17 is default HIGH

int nInputPin = 17;   //D17
int nPinState;        // 1 or 0

#define RED 22
#define GREEN 23
#define BLUE 24

void setup() {
  // put your setup code here, to run once:

  pinMode(nInputPin, INPUT_PULLUP); //uses the internal 10k ohm resistor
  //  pinMode(nInputPin, INPUT);

  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  String strOut;
  String strPinState;


  nPinState = digitalRead(nInputPin);   // read the input pin

  if (nPinState == 0) {
    strPinState = "LOW";
    digitalWrite(RED, LOW); //LOW == On
    digitalWrite(BLUE, HIGH);
    digitalWrite(GREEN, HIGH);
  } else {
    strPinState = "HIGH";
    digitalWrite(RED, HIGH);
    digitalWrite(BLUE, HIGH);
    digitalWrite(GREEN, LOW);  //LOW == On
  }

  strOut = ("Pin state: " + strPinState);
  Serial.println(strOut);


  delay(500);

}
