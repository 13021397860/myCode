#pragma once
#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

enum Exceptiontype
{
	Date_invalid, Score_invalid, Range_error
};

class MyException
{
public:
	MyException(Exceptiontype a);
	virtual ~MyException();
	const char* what() const;
protected:
	Exceptiontype exception;
};

#endif // !MYEXCEPTION_H