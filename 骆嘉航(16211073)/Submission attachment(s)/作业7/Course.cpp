#include <iostream>
#include "Course.h"

using namespace std;

Course::Course()
{
	name.resize(0);
	creditHour=0;
}

Course::Course(const string &x,const int &y)
{
	setName(x);
	setCreditHour(y);
}

Course::~Course()
{
}

int Course::getCreditHour()const
{
	return creditHour;
}

void Course::setCreditHour(const int &x)
{
	creditHour=x;
}

void Course::setName(const string &x)
{
	name=x;
}

string Course::getName()const
{
	return name;
}

ostream& operator << (ostream &output,Course &x)
{
	output << "课程名：" << x.getName() << " 学分：" <<x.getCreditHour() << " 成绩：" << x.getScore();
	return output;
}
