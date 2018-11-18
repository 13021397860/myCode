#include <iostream>
#include "ObligatoryCourse.h"

using namespace std;

ObligatoryCourse::ObligatoryCourse():Course()
{
	mark=0;
}

ObligatoryCourse::ObligatoryCourse(const string &Name,const int &CH,const int &Mark):Course(Name,CH)
{
	mark=Mark;
}

ObligatoryCourse::~ObligatoryCourse()
{
	
}

void ObligatoryCourse::setMark(const int &Mark)
{
	mark=Mark;
}

int ObligatoryCourse::getScore()const
{
	return mark;
}
