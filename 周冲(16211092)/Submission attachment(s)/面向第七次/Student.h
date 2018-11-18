#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include"Date.h"
#include"Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#define MAX_SIZE 10
class Student
{
	public:
		Student();
		Student(const char*,Date);
        Student(const Student&);
        virtual ~Student();
        char* getName()const
		{
			return name;
		}
        Student& setBD (Date D);
        Date getBirthDate()const
		{	
			return birthDate;
		}
        int getYear()const
		{
			return birthDate.getYear();
		}
        int getMonth()const
		{
			return birthDate.getMonth();
		}
        int getDay()const
		{
			return birthDate.getDay();
		}
        void print()const;
        int GetNumber()const
		{
			return number;
		}
        Student& addCourse(Course *course);
        void printclass()const;
        friend std::ostream&operator<<(std::ostream& o,const Student& a);
        bool removeCourse(int i);
        int getCourseNumber(){return courseNumber;}
        Course* getList(int i){return courseList[i];}
        double calcCredit();
	private:
		char* name;
		Date birthDate;
		Course *courseList[MAX_SIZE];
		int courseNumber;
		static int number;
};
#endif
