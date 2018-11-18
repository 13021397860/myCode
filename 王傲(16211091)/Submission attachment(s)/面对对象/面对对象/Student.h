#ifndef STUDENT_H
#define STUDENT_H

#include "Date.h"
#include "course.h"
#include <string>
#include "obligatoryCourse.h"
#include "electiveCourse.h"

const int MAX_SIZE = 50;

class Student
{	
	public:
		Student(const char*, int, int, int);
		Student(const char*, const Date &);
		Student(const Student &);
		
		Student &setName(const char* const);
		char* getName() const	{return name;}
		int getCount() const	{return count;}
		const Date &getBirthDate() const	{return birthDate;}
		void printStudent() const;
		
		//2
		Student& addCourse(Course *course)
		{
			courseList[courseNumber] = course;
			courseNumber++;
		}
		Student& addCourse(const string &courseName,int creditHour,bool temp)
		{
			Course * p;
			if(temp==1)
			p = new ObligatoryCourse(courseName,creditHour);
			if(temp==0)
			p = new ElectiveCourse(courseName,creditHour);
			addCourse(p);
		}
		~Student();
		//÷ÿ‘ÿ<< 
		friend istream& operator>>(istream&,Student&);
		friend ostream& operator<<(ostream&,const Student&);
		//ÕÀøŒ
		bool removeCourse(int);
		//«Û∫Õ
		int calcCredit(); 
	private:
		char *name;
		const Date birthDate;
		static int count;
		Course *courseList[MAX_SIZE];
		int courseNumber=0;
};

#endif
