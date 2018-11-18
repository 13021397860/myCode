#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"

class ElectiveCourse : public Course
{
	public:
		ElectiveCourse();
		ElectiveCourse(const string,const int);
		void setScore(const char);
		virtual int getScore() const;
		virtual int O_credit() const;
		virtual int if_E() const;
	protected:
	private:
		char grade;
};

#endif
