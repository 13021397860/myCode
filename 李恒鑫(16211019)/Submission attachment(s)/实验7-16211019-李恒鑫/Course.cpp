#include "Course.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
Course::Course(string str,int cr)
{
	setname(str);
	setCreditHour(cr);
}
void Course::setname(string str)
{
	name=str;
}
void Course::setCreditHour(int cr)
{
	creditHour=cr;
}
string Course::getname()
{
	return name;
}
int Course::getCreditHour()
{
	return creditHour;
}
ostream &operator <<(ostream& output, const Course&course)
{
	output<<left<<setw(18)<<course.name<<setw(10)<<course.creditHour;
	return output; 
}

