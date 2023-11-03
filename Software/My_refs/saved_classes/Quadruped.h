//Quadruped.h

#ifndef Quadruped_h 
#define Quadruped_h


#include "Leg.h"
#include "Neck.h"
#include "PairValues.h"
#include "GaitCrawl.h"
#include "Path.h"

#include <list>

using namespace std;  //for Strings and lists


class Quadruped
{
public:

	void Initialize();	

	void Reset();  //straightens legs	
	void Ready();		
	void Sit();
	void Crawl(float fTurnRate);
	void PauseWalk();

	void SetNeckAngle(float fAngleDeg);


	String GetState(); //temporary

private:

	GaitCrawl m_aCrawl;
	
	String m_strState;

	
	//Path aPath;
	
	Leg m_legForeStb;   //0
	Leg m_legAftStb;	  //1	
	Leg m_legForePort; //2
	Leg m_legAftPort;   //3 `
	Neck m_neck;


	void Wait(unsigned long nWaitMilliSeconds);
	unsigned long m_nWaitMilliSeconds;



};

#endif
