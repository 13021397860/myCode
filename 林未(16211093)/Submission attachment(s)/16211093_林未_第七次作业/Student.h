#ifndef STUDENT_H
#define STUDENT_H

#include "Date.h"
#include "Course.h"
#define MAX_SIZE 20
using namespace std;

class Student
{
	public:
		Student(const char*, int, int, int);
		Student(const char*, const Date &);
		Student(const Student &);
		
		friend ostream& operator<<(ostream&, const Student&);
		Student &setName(const char* const);
		char *getName() const	{return name;}
		static int getCount() {return count;}
		const Date &getBirthDate() const	{return birthDate;}
		int getCourseNumber() const {return courseNumber;}
		/*void printStudent() const;
		void printCourse() const;*/
		Student &addCourse(Course *);
		//Student &addCourse(const string &, int);
		bool removeCourse(int); 
		double calcCredit();
		
		Course *courseList[MAX_SIZE];
		~Student();
		
	protected:
		
	private:
		char *name;
		const Date birthDate;
		static int count;
		
		int courseNumber; 
};

#endif
