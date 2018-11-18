#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"
#include<cstring>

class ElectiveCourse : public Course
{
	public:
		ElectiveCourse();
		ElectiveCourse(std::string,int);
		ElectiveCourse(const ElectiveCourse &e);
		virtual~ElectiveCourse();
		
		ElectiveCourse& setGrade(char);
		char getGrade()const;
		virtual int getScore()const;
		
	protected:
		char grade;
};

#endif
