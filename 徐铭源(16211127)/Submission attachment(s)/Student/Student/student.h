#include"date.h"
#include"course.h" 
#include"electivecourse.h"
#include"oblitarycourse.h"
#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 10
#include<iostream>
#include<typeinfo>
using namespace std;

class Student
{
	friend Course;
	public:
		Student();
		Student(const char *tname);
		Student(const char *tname,const Date &d);
		Student(const Student &S);
		void setName( char *tname);
		char* getName()const;
		Date getBirthday()const; 
		int getCourseNumber()const;
		void PrintBirthday()const;
		void PrintName()const;
		static int getCount();
		int calcCredit(); 
		
		Student& addCourse(Course *Course); 
//		Student& addCourse(const string &courseName,int creditHour);
		bool removeCourse(int i);
		friend ostream &operator <<(ostream&out,const Student &S);
		
		~Student();
	private:
		char* name;
		const Date birthday; 
		static int count;
	private:
		Course* CourseList[MAX_SIZE+1];//已选课程(全是指针) 
		int CourseNumber;
};

#endif
