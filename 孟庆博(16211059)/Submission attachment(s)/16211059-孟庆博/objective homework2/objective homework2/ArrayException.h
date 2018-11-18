#include"MyException.h"
#pragma once
class ArrayException:public MyException
{
public:
	ArrayException();
	void out();
	~ArrayException();
};

