#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 10
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"
class Student
{
	public:
		Student(const char* const,int,int,int);
		Student(const Student &);
		Student& addCourse(Course* course);
		~Student();
		char* getName();
		void setName(const char* const);
		Date setBirthdate(int,int,int);
		Date getBirthdate();
		int getCourseNumber(); 
		friend ostream& operator<<(ostream& os,Student& p);
		Course& operator[](int);
		bool removeCourse(int); 
		double calcCredit();
	protected:
	private:
		char* Name;
		Date Birthdate;
		static int count;
		Course* courseList[MAX_SIZE];  
		int courseNumber;
};

#endif
