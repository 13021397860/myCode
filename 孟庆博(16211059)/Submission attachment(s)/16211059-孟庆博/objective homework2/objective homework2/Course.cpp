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
	output << "�γ����ƣ�" << c.name << "       ѧ�֣�" << c.creditHour ;
	return output;
}
