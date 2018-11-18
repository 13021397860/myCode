#pragma once
#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"
class ElectiveCourse :
	public Course
{
public:
	ElectiveCourse();
	ElectiveCourse(string, int);
	virtual~ElectiveCourse();

	virtual int getScore() const;

	virtual void setGrade(char);

protected:
	char grade;
};

#endif // !ELECTIVECOURSE_H;

