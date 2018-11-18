#include "ObligatoryCourse.h"
#include "MyException.h"
#include<iostream>
#include<cstring>
using namespace std;

ObligatoryCourse::ObligatoryCourse()
{
	mark=-1;
	//cout<<"constructor ObligatoryCourse\n";
}

ObligatoryCourse::ObligatoryCourse(string s,int c)
:Course(s,c)
{
	mark=-1;
	//cout<<"constructor ObligatoryCourse\n";
}

ObligatoryCourse::ObligatoryCourse(const ObligatoryCourse &o)
:Course(o.getName(),o.getCreditHour())
{
	mark=-1;
	//cout<<"constructor ObligatoryCourse\n";
}

ObligatoryCourse::~ObligatoryCourse()
{
	//cout<<"destructor ObligatoryCourse\n";
}

ObligatoryCourse& ObligatoryCourse::setMark(int amark)
{
	if(amark<0||amark>100)throw MyException("³É¼¨·Ç·¨£¡");
	mark=amark;
}

int ObligatoryCourse::getScore()const
{
	return mark;
}
