#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include<iostream>
#include<exception>
class MyException
{
	public:
		MyException():DateE("���ڴ���"),GradeE("�÷ִ���"),CourseE("�γ̴���");
		virtual ~MyException(); 
		const char*DExcep(){return DateE};
		const char*GExcep(){return GradeE};
		const char*CExcep(){return CourseE};
	private:
		const char*DateE;
		const char*GradeE;
		const char*CourseE;
};
#endif
