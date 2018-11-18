#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "Course.h"

class ElectiveCourse : public Course
{
	public:
		ElectiveCourse(const string &,const int &);
		bool setGrade(char); 
		virtual int getScore() const;
		~ElectiveCourse();
	protected:
	private:
		char Grade;
};
#endif
