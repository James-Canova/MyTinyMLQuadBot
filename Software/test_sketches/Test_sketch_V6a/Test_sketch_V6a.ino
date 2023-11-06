//Test_sketch_V6a.ino

//https://gammon.com.au/interrupts

const byte LED = 23;
const byte PUSHBUTTON = 17;

volatile int m_nCounter;


void setup ()
{
  m_nCounter = 0;

  Serial.begin(9600);

  //LED
  pinMode (LED, OUTPUT);  

  digitalWrite (PUSHBUTTON, HIGH);  // not sure why this is required******
  attachInterrupt (digitalPinToInterrupt (PUSHBUTTON), pushswitchPressed, RISING);  // attach interrupt handler
  
}  // end of setup

void loop ()
{
  String strOut;


  if (m_nCounter == 0)
  {
    strOut = "Reset";
  }


  if (m_nCounter == 1)
  {
    strOut = "Ready";
  }

  if (m_nCounter == 2)
  {
    strOut = "Walk";
  }

  strOut = "State: " + strOut;
  Serial.println(strOut);
  
} 

///////////////////////////////////////////////////////////
// Interrupt Service Routine (ISR)
void pushswitchPressed ()
{
  m_nCounter = m_nCounter + 1;
  if (m_nCounter > 2) {
    m_nCounter = 0;
    }
}  // end of pushswitchPressed
