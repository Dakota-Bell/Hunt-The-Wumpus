#include <iostream>
#include "Chamber.h"
using namespace std;

Chamber::Chamber(int count, Chamber* cham1, Chamber* cham2, Chamber* cham3)
{
	num = count;
	cham1 = nullptr;
	cham2 = nullptr;
	cham3 = nullptr;
}

void Chamber::setPtrs(Chamber* cham1, Chamber* cham2, Chamber* cham3)
{
	ch1 = cham1; // assigns the private attribute to what it passed in as parameters for chamber 1
	ch2 = cham2; // assigns the private attribute to what it passed in as parameters for chamber 2
	ch3 = cham3; // assigns the private attribute to what it passed in as parameters for chamber 3
}

int Chamber::getID() // returns what num is assigned
{
	return num;
}

Chamber* Chamber::getDoor1Ptr()
{
	return ch1; // returns ch1 pointer and dereferences in driver
}
Chamber* Chamber::getDoor2Ptr()
{
	return ch2; // returns ch2 pointer and dereferences in driver
}
Chamber* Chamber::getDoor3Ptr()
{
	return ch3; // returns ch3 pointer and dereferences in driver
}

int Chamber::getDoor1ID()
{
	return ch1->getID(); // returns ch1 ID number as a dereferenced method (getID)
}

int Chamber::getDoor2ID()
{
	return ch2->getID(); // returns ch2 ID number as a dereferenced method (getID)
}
	
int Chamber::getDoor3ID()
{
	return ch3->getID(); // returns ch3 ID number as a dereferenced method (getID)
}