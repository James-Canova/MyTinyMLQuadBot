//Display.h

#ifndef Display_h 
#define Display_h

class Display
{
public:

	void  SetValues(float fValue1, float fValue2);
	float GetValue1();	
	float GetValue2();		

private:
    float m_fValue1;  
    float m_fValue2;
};

#endif
