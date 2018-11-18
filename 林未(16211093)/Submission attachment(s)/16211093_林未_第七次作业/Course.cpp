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
	output << "�γ�����" << studCourse.getCourseName()
		   << "\tѧ�֣�" << studCourse.getCreditHour()
		   << "\t�ɼ���" << studCourse.getScore();
	return output;
}

Course::~Course()
{
	
}
