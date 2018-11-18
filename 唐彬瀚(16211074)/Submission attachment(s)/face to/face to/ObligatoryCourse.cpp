#include<iostream>
#include<cstring>
#include "Course.h"
#include "ObligatoryCourse.h"
using namespace std;
ObligatoryCourse::ObligatoryCourse()
{
	
}
ObligatoryCourse::ObligatoryCourse(string c)
{
	oname=c;
}
ObligatoryCourse::~ObligatoryCourse()
{
	
}
void ObligatoryCourse::setMark(const int i)
{
	mark=i;
}
int ObligatoryCourse::getScore()
{
	return mark;
}
string ObligatoryCourse::getName()
{
	return oname;
}
ostream& operator << (ostream &output, ObligatoryCourse &c)
{
	output<<"Course Name£º "<<c.oname<<";    Credit£º "<<c.getCredit();
	return output; 
}
