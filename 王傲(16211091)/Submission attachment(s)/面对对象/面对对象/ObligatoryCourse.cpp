#include "course.h"
#include "obligatoryCourse.h"

using namespace std;

ObligatoryCourse::ObligatoryCourse(const string& _courseName,int _mark,int _creditHour)
:Course(_courseName, _creditHour)
{
	setMark( _mark);
}
void ObligatoryCourse::setMark(int _mark)
{
	mark=_mark;
}

int ObligatoryCourse::getScore()
{
	return mark;
}

