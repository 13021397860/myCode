#include "Course.h"


Course::Course(const string & n, int h)
{
	name = n;
	creditHour = h;
}

Course::Course(const Course & a)
{
	name = a.name;
	creditHour = a.creditHour;
}

Course::~Course()
{
}

ostream & operator<<(ostream & output, const Course & c)
{
	output << "课程名:" << c.name << "\t学分：" << c.creditHour << "\t成绩：" << c.getScore();
	return output;
}
