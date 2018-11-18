#ifndef MYEXCEPTION_H_
#define MYEXCEPTION_H_

#include<exception>
using std::exception;
class bad_date :public exception
{
public:
	bad_date() { ; }
	const char* what() { return "日期输出非法!"; }
};

class bad_doman :public exception
{
public:
	bad_doman() { ; }
	const char* what() { return"访问越界！"; }
};

class bad_grade :public exception
{
public:
	bad_grade() { ; }
	const char* what() { return "成绩输入非法"; }
};

#endif // !MYEXCEPTION_H_