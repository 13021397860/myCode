#include "Course.h"
#include <string>
Course::Course()
{
}
Course::Course(string a, int b)
{
	setName(a);
	setCreditHour(b);
}
void Course::setName(string a)
{
	name=a;
}
string Course::getName()const
{
	return name;
}
void Course::setCreditHour(int b)
{
	creditHour=(b>0)?b:0;
} 
int Course::getCreditHour()const
{
	return creditHour;
}
Course::~Course()
{
}
