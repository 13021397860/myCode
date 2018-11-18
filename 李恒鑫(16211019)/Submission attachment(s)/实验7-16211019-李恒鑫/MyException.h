#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <iostream>
using namespace std;
class MyException
{
	public:
		MyException(){
		};
		void catchDate(bool x);
		bool catchElGrade(char);
		bool catchObGrade(int);
		void catchCourse(int);
	protected:
};

#endif
