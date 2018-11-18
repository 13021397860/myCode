#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include"Course.h"
#include <typeinfo>
class ElectiveCourse:public Course
{
	public:
		ElectiveCourse(string, int, char);
		int getScore() const;	
		ElectiveCourse & setgrade(const char ) ;
		~ElectiveCourse();
	private:
		char grade;
};
#endif
