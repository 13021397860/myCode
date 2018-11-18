#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"

class ElectiveCourse : public Course
{
	public:
		ElectiveCourse();
		ElectiveCourse(const string &,const int &,const char &);
		~ElectiveCourse();
		
		virtual int getScore()const;
		void setGrade(const char &);
	private:
		char grade;
};

#endif
