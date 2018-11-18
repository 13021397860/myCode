#include<iostream>
#include<cstring>
#include "Date.h"
using namespace std;

class MyException
{
	public:
		MyException();
		~MyException();
		void DateException(Date) throw(Date);
		void CourseException(int);
		void GradeException(int);
};	
