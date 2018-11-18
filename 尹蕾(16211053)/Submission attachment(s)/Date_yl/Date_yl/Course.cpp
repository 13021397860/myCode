#include "Course.h"
#include<iomanip>
using namespace std;
Course::Course(const string x, int a)
{
    name=x;
    creditHour=a;
    //ctor
}

Course::~Course()
{
    //dtor
}

void Course::setName(const string x)
{
    name=x;
}

void Course::setCreditHour(int a)
{
    creditHour=a;
}

string Course::getName()const
{
    return name;
}

int Course::getCreditHour()const
{
    return creditHour;
}

ostream& operator <<(ostream &output,const Course& c)
{
	output<<"课程名："<<c.getName()
		<<"       学分："<<c.getCreditHour()
		<<"       分数："<<c.getScore()
		<<"\n";
	return output;
}
