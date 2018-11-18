#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include<iostream>
#include<exception>
class MyException
{
	public:
		MyException():DateE("日期错误"),GradeE("得分错误"),CourseE("课程错误");
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
