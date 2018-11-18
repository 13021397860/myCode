#include "Course.h"
 
Course::Course()
{
	
}

Course::Course(const string theName="",const int theCreditHour=0)
{
	_setName(theName);
	setCreditHour(theCreditHour);
}

Course::Course(const Course &c)
{
	name=c.name;
	creditHour=c.creditHour;
}

string Course::getName() const
{
	return name;
}

int Course::getCreditHour() const
{
	return creditHour;
}

Course& Course::_setName(const string theName)
{
	name=theName;
	return *this; 
}

Course& Course::setCreditHour(const int theCreditHour)
{
	creditHour=theCreditHour;
	return *this;
}


/*void Course::printc() const
{
	cout<<"course name: "<<setw(20)<<name<<"    credit: "<<creditHour;
}*/

Course::~Course()
{
	
}
