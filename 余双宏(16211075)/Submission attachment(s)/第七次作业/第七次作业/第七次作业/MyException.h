#ifndef MYEXCEPTION_H_
#define MYEXCEPTION_H_

#include<exception>
using std::exception;
class bad_date :public exception
{
public:
	bad_date() { ; }
	const char* what() { return "��������Ƿ�!"; }
};

class bad_doman :public exception
{
public:
	bad_doman() { ; }
	const char* what() { return"����Խ�磡"; }
};

class bad_grade :public exception
{
public:
	bad_grade() { ; }
	const char* what() { return "�ɼ�����Ƿ�"; }
};

#endif // !MYEXCEPTION_H_