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
	output << "�γ���:" << c.name << "\tѧ�֣�" << c.creditHour << "\t�ɼ���" << c.getScore();
	return output;
}
