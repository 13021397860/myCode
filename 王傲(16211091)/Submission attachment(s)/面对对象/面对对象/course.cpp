#include "course.h"

Course::Course(const string& _courseName, int _creditHour)
{
	setCourseName(_courseName);
	setCreditHour(_creditHour);
}

void Course::setCourseName(const string& _courseName)
{
	courseName=_courseName;
}

void Course::setCreditHour(int _creditHour)
{
	creditHour=_creditHour;
}

string Course::getCourseName() const
{
	return courseName;
}

int Course::getCreditHour() const
{
	return creditHour;
}
istream& operator >>(istream& is,Course& course)
{
	is>>course.courseName>>course.creditHour;
	return is;
}
ostream& operator <<(ostream& os,const Course& course)
{
	os<<"¿Î³Ì£º"<<course.courseName<<" Ñ§·Ö£º"<<course.creditHour<<endl;
	return os;
}
