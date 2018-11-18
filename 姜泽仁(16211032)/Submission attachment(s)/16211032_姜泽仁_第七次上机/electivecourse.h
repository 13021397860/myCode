#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "course.h" // inheriting class's header file
#include<string>
// No description
class ElectiveCourse : public Course
{
	// private section
	public:
		bool setgrade(const char &);
		virtual const int getScore()const;
		virtual const int getType()const{return 2;}
		void print()const;
		// class constructor
		ElectiveCourse(const string &,const int &,const char &);
		ElectiveCourse(const string &,const int &);
		// class destructor
		virtual ~ElectiveCourse();
	protected:
		char grade;
};

#endif // ELECTIVECOURSE_H

