# 1 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/test_sketches/Test_sketch_V5a/Test_sketch_V5a.ino"
//Test_sketch_V5a.ino
//was: pcb_test_push_button_V0a.ino

////for pushbutton and interupts to Reset->Ready->Reset....

//https://gammon.com.au/interrupts

//5 November 2023

# 11 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/test_sketches/Test_sketch_V5a/Test_sketch_V5a.ino" 2
# 12 "/home/james/Public/Projects/MyTinyMLQuadBot/Software/test_sketches/Test_sketch_V5a/Test_sketch_V5a.ino" 2

LEDRGB m_ledRGB;

String m_strState;

volatile int m_nCounter;

void setup() {
    //put your setup code here, to run once:

    Serial.begin(9600);

    m_ledRGB.Initialize();
    m_ledRGB.AllLedsOff();

    m_nCounter = 0;

    //for pushbutton
    digitalWrite (nPUSHPUTTON_PIN, HIGH); // internal pull-up resistor
    attachInterrupt(digitalPinToInterrupt(17), isrPushButton, RISING);
}



void loop() {
  //put your main code here, to run repeatedly:

String strOut;


  if (m_nCounter == 0)
  {
    strOut = "Reset";
    m_ledRGB.AllLedsOff();
    m_ledRGB.LedOn(RED);
  }

  if (m_nCounter == 1)
  {
    strOut = "Ready";
    m_ledRGB.AllLedsOff();
    m_ledRGB.LedOn(GREEN);
  }

  if (m_nCounter == 2)
  {
    strOut = "Walk";
    m_ledRGB.AllLedsOff();
    m_ledRGB.LedOn(BLUE);

  }

  strOut = "State: " + strOut;
  Serial.println(strOut);

}

///////////////////////////////////////////////////////////////
//ISR
///////////////////////////////////////////////////////////////
void isrPushButton() {
  m_nCounter = m_nCounter + 1;
  if (m_nCounter > 2) {
    m_nCounter = 0;
    }
}
