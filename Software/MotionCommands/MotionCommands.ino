//MotionCommands.ino

#include "LEDRGB.h"
#include "States.h"
#include "PointXY.h"

#include "ProcessCommand.h"

LEDRGB m_ledRGB;

int m_nStateIndex;
String m_strState;

PointXY m_xyCentroid;

float m_xCentroid;


//arrStates[8] = {"Reset", "Ready", "Sit", "Walk", "Pause","None", "None", "None"};

void setup()
{
	m_ledRGB.Initialize();
	m_ledRGB.AllLedsOff();

	m_nStateIndex = 0; //Reset

	m_xyCentroid.SetValues(0.0, 0.0);
	
}

void loop() {
	
	m_ledRGB.AllLedsOff();
	delay(500);

	//controlled according to state diagram-----
	m_strState = arrStates[m_nStateIndex];

	//from object detection------
	m_xyCentroid.SetValues(20.0, 0.0);
	m_xCentroid = m_xyCentroid.GetX();


	//Write state and xCentroid;







	m_ledRGB.LedOn(BLUE);
	delay(500);

}