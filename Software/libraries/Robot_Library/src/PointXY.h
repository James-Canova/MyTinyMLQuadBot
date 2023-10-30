//PointXY.h

#ifndef PointXY_h 
#define PointXY_h

class PointXY
{
public:

	void  SetValues(float fX, float fY);
	float GetX();	
	float GetY();		

private:
    float m_fX;  
    float m_fY;
};

#endif
