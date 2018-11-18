#include "Course.h"

Course::Course(const string &n, int ch)
{
    name=n;
    creditHour=ch;
}

Course::~Course()
{
    //dtor
}
ostream& operator<<(ostream &output, const Course&c)
{
	output<<"ourse name£º"<<c.name
		<<"\tscore£º"<<c.creditHour
		<<"\tgrade£º"<<c.getScore()
		<<"\n";
	return output;
}

