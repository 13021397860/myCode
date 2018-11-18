#include "Course.h"

Course::Course(const string a,int b)
	:name(a),creditHour(b)
{
	setCourse(a,b);
}

int Course::setCourse(const string &a,int b)
{
	name=a;
	creditHour=b;
}

const string Course::getCoursename()const
{
	return name;
}

const int Course::getCoursecreditHour()const
{
	return creditHour;
}

ostream& operator<<(ostream& output,const Course &s)
{
	output<<"科目："<<s.getCoursename()<<" 学分:"<<s.getCoursecreditHour();
}

Course::~Course()
{
}
