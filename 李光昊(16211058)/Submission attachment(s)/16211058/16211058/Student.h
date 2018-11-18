#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include "Course.h"
#include<iostream>
#include<string>

#define Maxsize 100
#define OCP 0.6

class Student
{
	friend std::ostream &operator<<(std::ostream &,const Student &);
	public:
		Student();
		Student(const char* const,const Date &);
		Student(const char* const,int,int,int);
		Student(const Student &);
		virtual ~Student();
		
		Student& setname(const char *const);
		
		Student& addCourse(Course *course);
		//Student& addCourse(const std::string &courseName, int creditHour);
		Student& initCourse(Course *[],int);
		
		bool removeCourse(int);
		
		Course* getCourse(int)const;
		bool setObligatoryCourseMark(int,int);
		bool setElectiveCourseMark(int,char);
		
		double calcCredit()const;
		
		const char* getName()const;
		void getDate(int &,int &,int &);
        const Date& getDate2()const;
        static int getCount(){return count;}
        
        int getCourseNumber()const;
        bool courseFull()const;
        
		void print()const;
		bool printCourse()const;
		void printCourse2()const;
		
		int checkCourse(std::string s);
		
	protected:
		static int count;
		char *name;
		const Date birthDate;
		Course *courseList[Maxsize];
		int courseNumber;//其值为选课总数-1，范围 0~Maxsize-1 
};

#endif
