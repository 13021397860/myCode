#pragma once
#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

enum ExceptionType { Date_Invalid, Range_Error, Score_Invalid };
class MyException
{
public:
	MyException(ExceptionType);
	virtual ~MyException();

	const char* Identify();

protected:
	ExceptionType type;
};

#endif // !MYEXCEPTION_H;

