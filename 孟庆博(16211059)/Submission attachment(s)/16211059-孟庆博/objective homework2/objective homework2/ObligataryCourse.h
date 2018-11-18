#pragma once
#include "stdafx.h"
#include"Course.h"
class ObligataryCourse :public Course
{
public:
	ObligataryCourse();
	int getScore();
	void setGrade(int a);
	virtual ~ObligataryCourse();
private:
	int mark;
};

