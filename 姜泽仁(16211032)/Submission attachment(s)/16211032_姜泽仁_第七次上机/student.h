#ifndef STUDENT_H
#define STUDENT_H
#include "date.h"
#define MAX_SIZE 10
#include "course.h" 
#include"obligatorycourse.h"
#include"electivecourse.h"
/*
 * No description
 */
class Student
{
	char *name;
	const Date birthDate;
	static int count; 
	Course *courseList[MAX_SIZE];
	int courseNumber;
	// private section
	public:
		Student& addCourse(Course *&);
		//Student& addCourse(ObligatoryCourse *);
		//Student& addCourse(ElectiveCourse *);
		Student& addCourse(const string &, int);
		const static int getcount(){return count;}
		void setname(const char *const);
		const Date& getbirthDate()const{return birthDate;}
		const char* const getname()const{return name;}
		const int getcourseNumber()const{return courseNumber;}
		const double calcCredit()const;
		bool removeCourse(int);
		void print()const;
		void printCourse()const;
		friend ostream & operator <<(ostream &,Student &);
		Course & operator [](int);
		// class constructor
		Student(const char *const,const int&,const int&,const int&);
		Student(const char *const,const Date&);
		Student(const Student &);
		// class destructor
		~Student();
		
	protected:
};

#endif // STUDENT_H

