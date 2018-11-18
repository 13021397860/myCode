#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "course.h"

class ElectiveCourse : public Course
{
	public:
		ElectiveCourse(string, int, char);
		
		ElectiveCourse &setGrade(const char);
		int getScore() const ;
		
		~ElectiveCourse();
		
	private:
		char grade;
};

#endif
