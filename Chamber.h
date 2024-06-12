#include <iostream>
using namespace std;

class Chamber
{
	public:
		Chamber(int, Chamber*, Chamber*, Chamber*);
		void setPtrs(Chamber*, Chamber*, Chamber*);
		int getID();
		Chamber *getDoor1Ptr();
		Chamber *getDoor2Ptr();
		Chamber *getDoor3Ptr();
		int getDoor1ID(); 
		int getDoor2ID();  
		int getDoor3ID(); 

	private:
		Chamber* ch1;
		Chamber* ch2;
		Chamber* ch3;
		int num;	
};