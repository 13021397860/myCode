#include "stdafx.h"
#include<iostream>
#include "Course.h"
using namespace std;


Course::Course()
{
}

string Course::getName()
{
	return name;
}

void Course::setName(string a)
{
	name = a;
}

int Course::getCredit()
{
	return creditHour;
}

void Course::setCredit(int a)
{
	creditHour = a;
}


Course::~Course()
{
}

ostream & operator<<(ostream &output, Course & c)
{
	output << "课程名称：" << c.name << "       学分：" << c.creditHour ;
	return output;
}
