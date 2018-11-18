#include "Course.h"

Course::Course()
	:name(),creditHour(0)
{
}

Course::Course(string s, int x)
	: name(s), creditHour(x)
{
}

Course::~Course()
{
}

int Course::getCreditHour() const
{
	return creditHour;
}

string Course::getName() const
{
	return name;
}

void Course::setCreditHour(int x)
{
	creditHour = x > 0 ? x : 0;
}

void Course::setName(string s)
{
	name = s.size() > 0 ? s : "NULL";
}

ostream& operator<<(ostream &os,const Course &c)
{
	os << "课程名称: " << c.getName() << " 学分: " << c.getCreditHour() << " 成绩: " << c.getScore() << endl;
	return os;
}

