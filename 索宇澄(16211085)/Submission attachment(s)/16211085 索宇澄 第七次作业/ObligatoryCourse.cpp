#include"ObligatoryCourse.h"
#include<iostream>
#include <cstring>
#include <typeinfo>
using namespace std;

ObligatoryCourse::ObligatoryCourse(string courseName, int credithour, int a)
:Course(courseName, credithour)
{
	mark=a;
}

ObligatoryCourse &ObligatoryCourse::setmark(int a)
{
    mark=a;	
    return *this;
}

ObligatoryCourse::~ObligatoryCourse()
{
 
}


