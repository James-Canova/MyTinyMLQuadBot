//Path.cpp

#include "Path.h"
#include "Constants.h"

//function definitions

//public
void Path::Initialize()
{
	GenerateLstFootPositions();
}

PairValues  Path::GetFootPosition(int nIndex)
{
	PairValues aPosXY;
	
	list<PairValues>::iterator it = m_lstFootPositions.begin();
	advance(it, nIndex);
	
	aPosXY = *it;
	
	return aPosXY;
}



//private
//calculate twelve points in leg coordinates and return as a list 
void Path::GenerateLstFootPositions()
{
		float fX[12], fY[12];
		float fXtemp, fYtemp;
		PairValues aPoint;

		//point 0 (start position)
		fXtemp	= 0.0;
		fYtemp = FOOT_ZERO_Y_POS;
		aPoint.SetValues(fXtemp, fYtemp);
		m_lstFootPositions.push_back(aPoint); //add to back of list 	
		
		//point 1 	
		fXtemp	= -(1.0/6.0) * MAX_STRIDE_MM;
		fYtemp = FOOT_ZERO_Y_POS;
		aPoint.SetValues(fXtemp, fYtemp);
		m_lstFootPositions.push_back(aPoint); //add to back of list 	

		//point 2 	
		fXtemp	= -(2.0/6.0) * MAX_STRIDE_MM;
		fYtemp = FOOT_ZERO_Y_POS;
		aPoint.SetValues(fXtemp, fYtemp);
		m_lstFootPositions.push_back(aPoint); //add to back of list 	
	
		//point 3 	
		fXtemp	= -(3.0/6.0) * MAX_STRIDE_MM;
		fYtemp = FOOT_ZERO_Y_POS;
		aPoint.SetValues(fXtemp, fYtemp);
		m_lstFootPositions.push_back(aPoint); 			
		
		//point 4 	
		fXtemp	= -(2.0/6.0) * MAX_STRIDE_MM;
		fYtemp = FOOT_ZERO_Y_POS + DELTA_Y;
		aPoint.SetValues(fXtemp, fYtemp);
		m_lstFootPositions.push_back(aPoint); //add to back of list 			
		
		//point 5 	
		fXtemp	= -(1.0/6.0) * MAX_STRIDE_MM;
		fYtemp = FOOT_ZERO_Y_POS + DELTA_Y;
		aPoint.SetValues(fXtemp, fYtemp);
		m_lstFootPositions.push_back(aPoint); //add to back of list 	

		//point 6 	
		fXtemp	= 0.0;
		fYtemp = FOOT_ZERO_Y_POS + DELTA_Y;
		aPoint.SetValues(fXtemp, fYtemp);
		m_lstFootPositions.push_back(aPoint); //add to back of list 		
		
		//point 7 	
		fXtemp	= (1.0/6.0) * MAX_STRIDE_MM;
		fYtemp = FOOT_ZERO_Y_POS + DELTA_Y;
		aPoint.SetValues(fXtemp, fYtemp);
		m_lstFootPositions.push_back(aPoint); //add to back of list 					

		//point 8 (target point)
		fXtemp	= (2.0/6.0) * MAX_STRIDE_MM;
		fYtemp = FOOT_ZERO_Y_POS + DELTA_Y;
		aPoint.SetValues(fXtemp, fYtemp);
		m_lstFootPositions.push_back(aPoint); //add to back of list 			
	
		//point 9 (target point)
		fXtemp	= (3.0/6.0) * MAX_STRIDE_MM;
		fYtemp = FOOT_ZERO_Y_POS;
		aPoint.SetValues(fXtemp, fYtemp);
		m_lstFootPositions.push_back(aPoint); //add to back of list 			

		//point 10	
		fXtemp	= (2.0/6.0) * MAX_STRIDE_MM;
		fYtemp = FOOT_ZERO_Y_POS;
		aPoint.SetValues(fXtemp, fYtemp);
		m_lstFootPositions.push_back(aPoint); //add to back of list 				

		//point 11 (target point)
		fXtemp	= (1.0/6.0) * MAX_STRIDE_MM;
		fYtemp = FOOT_ZERO_Y_POS;
		aPoint.SetValues(fXtemp, fYtemp);
		m_lstFootPositions.push_back(aPoint); //add to back of list 			
}



