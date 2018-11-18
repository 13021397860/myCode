#include"MyException.h"
#pragma once
class GradeException: public MyException
{
public:
	GradeException();
	void out();
	~GradeException();
};

