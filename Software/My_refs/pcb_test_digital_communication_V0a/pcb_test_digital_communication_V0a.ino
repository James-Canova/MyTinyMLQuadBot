//pcb_test_digital_communication_V0a

//was: Catbot_dev_7_V0a


//based on Arduino examples
//modified by James Canova
//jscanova@gmail.com

//17 July 2023



// These constants won't change. They're used to give names to the pins used:
const int nAnalogOutPin = 14;     //A0, D14 
const int nDigitalOutPin0 =  7;   //D7, most significant value
const int nDigitalOutPin1 =  8;   //D8
const int nDigitalOutPin2 =  9;   //D9, least significant value


int nAnalogWriteValue;
int nDigitalWriteValue0;
int nDigitalWriteValue1;
int nDigitalWriteValue2;


void setup() {

  // set pins as outputs
  pinMode(nAnalogOutPin, OUTPUT);  //500 Hz
  pinMode(nDigitalOutPin0, OUTPUT);
  pinMode(nDigitalOutPin1, OUTPUT);
  pinMode(nDigitalOutPin2, OUTPUT);

}

void loop() {

  nAnalogWriteValue = 150;     //A0,D14
  nDigitalWriteValue0 = 0;   //D7
  nDigitalWriteValue1 = 0;   //D8
  nDigitalWriteValue2 = 1;   //D9

  
  analogWrite(nAnalogOutPin, nAnalogWriteValue);
  digitalWrite(nDigitalOutPin0, nDigitalWriteValue0);
  digitalWrite(nDigitalOutPin1, nDigitalWriteValue1);
  digitalWrite(nDigitalOutPin2, nDigitalWriteValue2);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}
