#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"

class ObligatoryCourse : public Course
{
	int mark;
	public:
		ObligatoryCourse(int, string ,int );
		void setMark(int );
		int getScore()const;
		~ObligatoryCourse();
	virtual	void printCourse();
};

#endif
