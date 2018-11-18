#ifndef STUDENT_H
#define STUDENT_H
#include <typeinfo>
#include"date.h"
#include "Course.h"
#define MAX_SIZE 50
#include<string>
class Student
{
	friend ostream & operator<<(ostream & , const Student & );
	public:
		static int counter;
		Course *courseList[MAX_SIZE];
		Student();
		Student(const char*, int, int, int);
		Student(const char*, const Date &);
		Student(const Student &);
		
		bool removeCourse(int i);
		
		double calcCredit() const ;	
		
		char* getName() const	;
		const Date &getBirthDate() const;
		int getCount() const;
		int getcourseNumber() const	;
		Student & setName(const char* ) ;
		Student &addCourse(Course *);
		void printCourse() const;
		~Student();
	private:
		char* name;
		const Date birthDate;
		
		
		int courseNumber; 
};
#endif
