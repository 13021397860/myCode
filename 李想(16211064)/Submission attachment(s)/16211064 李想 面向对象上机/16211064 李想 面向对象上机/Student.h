#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#define MAX_SIZE 20
#include <bits/stdc++.h>
using namespace std;
class Student
{
    public:
        public:
		//friend void Date::operator++();
		//friend void Date::operator++(int);
		friend ostream& operator<<(ostream&,const Date&);
		friend ostream& operator<<(ostream&,const Student&);
		static void printnum();
		Student();
		Student(char* , int, int, int);
		Student(Student&);
		int setName(char*nm);
		int getName();
		void print();
		~Student();
		int setDate(int yr, int mon, int dy);
		Student& addCourse(Course *course);
		void removeCourse(int );
		Student& addCourse(const string &courseName,int creditHour);
		float calcCredit();
		int getscore(string subject);
		Date birthDate;
		Course *courseList[MAX_SIZE];
		bool *courseType[MAX_SIZE];
		int GetCourseNumber();
		Course& operator[](int );
		char* name;
	protected:
	private:
		static int sum;

		int courseNumber;
};

#endif // STUDENT_H
