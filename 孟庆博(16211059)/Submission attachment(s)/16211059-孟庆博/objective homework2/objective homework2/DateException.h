#include"MyException.h"
#pragma once
class DateException:public MyException
{
public:
	DateException();
	void out();
	~DateException();
};

