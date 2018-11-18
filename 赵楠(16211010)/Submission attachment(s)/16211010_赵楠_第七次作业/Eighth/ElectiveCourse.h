#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"

class ElectiveCourse : public Course
{
	public:
		ElectiveCourse(const string,const int,const char);
		virtual~ElectiveCourse();
		void setGrade(char);
		virtual void setScore(int);
		virtual int getScore()const;
	private:
		char grade;
};

#endif
