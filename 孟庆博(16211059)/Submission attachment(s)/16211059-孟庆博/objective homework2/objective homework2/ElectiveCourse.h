#pragma once
#include "stdafx.h"
#include"Course.h"
class ElectiveCourse:public Course
{
public:
	ElectiveCourse();
	void setGrade(int a);
	int getScore();
	virtual ~ElectiveCourse();
private:
	char grade;
};

