#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"

class ElectiveCourse : public Course
{
	public:
		ElectiveCourse(string, int, char);
		
		ElectiveCourse &setGrade(const char);
		int getScore() const;
		~ElectiveCourse();
		
	protected:
		
	private:
		char grade;
};

#endif
