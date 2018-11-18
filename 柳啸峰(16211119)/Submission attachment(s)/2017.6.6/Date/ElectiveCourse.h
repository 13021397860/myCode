#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"
#include <cstdio> 
class ElectiveCourse : public Course
{
	char grade;
	public:
		ElectiveCourse(char ,string ,int );
		void setGrade(char );
		int getScore()const;
	virtual	void printCourse();
		~ElectiveCourse();
};

#endif
