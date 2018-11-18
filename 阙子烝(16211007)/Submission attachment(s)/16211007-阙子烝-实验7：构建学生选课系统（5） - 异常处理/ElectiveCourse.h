#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"

class ElectiveCourse:public Course
{
	public:
		ElectiveCourse();
		//~ElectiveCourse();
		void setScore(const int );
		int getScore() const;
		
	private:
		char grade;
};

#endif
