#include<iostream>
#include<cstring>
#include "Date.h"
#include "MyException.h"
using namespace std;

MyException::MyException()
{
	
}

MyException::~MyException()
{
	
}

void MyException::DateException(Date date)
throw(Date) 
{
	if(date.wrongDate(date.getYear(),date.getMonth(),date.getDay()))
	throw date;
}



void MyException::CourseException(int num)
{
	if(num>3||num<=0)
	throw num;
}

void MyException::GradeException(int grade)
{
	if(grade>100||grade<0)
	throw grade;
}
 
