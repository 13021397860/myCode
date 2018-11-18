#include "Course.h"
using namespace std;

Course::Course(string courseName, int credit)
:creditHour(credit)
{
	setName(courseName);
}

Course& Course::setName(const string courseName)
{
	name = courseName;
	return *this;
}

ostream& operator<<(ostream& output, const Course& studCourse)
{
	output << "课程名：" << studCourse.getCourseName()
		   << "\t学分：" << studCourse.getCreditHour()
		   << "\t成绩：" << studCourse.getScore();
	return output;
}

Course::~Course()
{
	
}
