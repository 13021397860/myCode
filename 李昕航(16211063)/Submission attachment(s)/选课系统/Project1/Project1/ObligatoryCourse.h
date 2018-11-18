#pragma once
#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"
class ObligatoryCourse :
	public Course
{
public:
	ObligatoryCourse();
	ObligatoryCourse(string, int);
	virtual~ObligatoryCourse();

	virtual int getScore() const;

	virtual void setGrade(int);

protected:
	int mark;
};

#endif //!OBLIGATORYCOURSE_H;

