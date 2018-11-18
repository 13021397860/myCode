#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include "Date.h"
//#include "Students.h"
class MyException
{
	
	public:
		MyException();
		void MyExceptionOfDate(int ,int ,int ,char *);//收集日期填写错误，第一个形参是错误日期，第二个形参是“您所输入的年份/月份/天数错误” 
		void MyExceptionOfStud(int );//收集学生访问学生课程数组错误，形参为错误的数组下标
		void MyExceptionOfOCS(int );//收集必修课成绩设置错误，形参为错误成绩
		void MyExceptionOfOES(char );//收集选修课成绩设置错误，形参为错误成绩 
		~MyException();
	protected:
};

#endif
