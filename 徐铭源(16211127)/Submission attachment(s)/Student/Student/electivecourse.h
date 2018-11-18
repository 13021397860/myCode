#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include"course.h"
class ElectiveCourse:public Course
{
	public:
		ElectiveCourse();
		ElectiveCourse(const string tname,const int tcreditHour);
		ElectiveCourse(const string tname,const int tcreditHour,const char tgrade);
		ElectiveCourse(const ElectiveCourse &E); 
		int getGrade()const;
		int setGrade(char tgarde);
		virtual int getScore()const;
		void printCourse()const;
		~ElectiveCourse();
	protected:
		char grade;
};

#endif
