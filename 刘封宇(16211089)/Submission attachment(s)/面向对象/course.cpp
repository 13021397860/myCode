#include "course.h"

Course::Course(string courseName, int credit)
:creditHour(credit)
{
	setCourse(courseName,credit);
}

Course &Course::setCourse(string nam, int cre)
{
	name=nam;
	creditHour=cre;
	return *this;
}

ostream& operator<<(ostream &output,const Course &d)
{
	output<<"课程名："<<d.getCourseName()<<"      学分："<<d.getScore();
	return output;
}

Course::~Course()
{
	
}
