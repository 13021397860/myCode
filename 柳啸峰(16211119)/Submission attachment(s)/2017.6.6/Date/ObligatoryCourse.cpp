#include "ObligatoryCourse.h"
#include "Course.h"
#include <iostream>
#include <iomanip>
ObligatoryCourse::ObligatoryCourse(int a, string b, int c):Course(b, c)
{
	setMark(a);
}
void ObligatoryCourse::setMark(int b)
{
	mark=(b>=0&&b<=100)?b:-1;
}
int ObligatoryCourse::getScore()const
{
	return mark;
}
void ObligatoryCourse::printCourse()
{
	cout<<setw(10)<<left<<getName()<<getCreditHour()<<"  "<<getScore()<<endl;
}
ObligatoryCourse::~ObligatoryCourse()
{
}
