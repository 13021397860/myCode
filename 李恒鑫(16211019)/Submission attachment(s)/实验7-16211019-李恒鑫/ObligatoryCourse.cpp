#include "ObligatoryCourse.h"
#include "Course.h"
#include <iostream>
using namespace std;
ObligatoryCourse::ObligatoryCourse(const string &coursename,int coursehour,int coursemark):Course(coursename,coursehour)
{
	setmark(coursemark);
}
void ObligatoryCourse::setmark(int coursemark)
{
	mark=(coursemark<0)?0:coursemark;
}
int ObligatoryCourse::getScore()
{
	return mark;
}

