//Path.h

#ifndef Path_h
#define Path_h

#include "PairValues.h"

#include <list>


using namespace std; //for lists


class Path
{
	public:
		void Initialize();
		PairValues GetFootPosition(int nIndex);
	
	
	private:
		void GenerateLstFootPositions();
		list<PairValues> m_lstFootPositions;
		
};

#endif