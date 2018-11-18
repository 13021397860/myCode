#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include "Date.h"
#include "Course.h"
#include "MyException.h"

using namespace std;

class Student
{
	public:
		Student();
		Student(const char* const,const Date &);
		Student(const char* const,const int &,const int &,const int &);
		Student(const Student &);
		virtual ~Student();
		char *get_name()const;
		Date get_date()const;
		void set_name(const char* const); 
		int getCourseCounter()const;
		Course* getCourse(const int &)const;
		static int get_count();
		Student& addCourse(Course *course);
		friend ostream& operator << (ostream &,Student &);
		void removeCourse(const int &);
		bool checkOC(const int &);
		double calcGrade();
	private:
		char *name;
		Date BirthDate;
		static int count;
		vector <Course*> courseList;
};
#endif 
