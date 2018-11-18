#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include "Date.h"
class MyException
{
	public:
		MyException();
		~MyException();
		void DateException(Date ) throw(Date);
		void CourseException(int ,int );
		void GradeException(int );
	protected:
};

#endif
