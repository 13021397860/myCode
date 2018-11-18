#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 15
#include <iostream>
#include "Date.h"
#include "Course.h"
extern const Date bDefault; 
extern const char nDefault[200];
//在.h中只声明 
class Student
{
	public:
		static int count;
		const double weight;
		Student(const char n[]=nDefault,const Date b=bDefault);
		Student(const Student &s);
		virtual ~Student();
		void setName(const char n[]);
		void setBirthDate(const Date b);
		char* getName() const;
		const Date& getBirthDate() const;
		Student& addCourse(Course *course);
		//Student& addCourse(const std::string &courseName, int creditHour);
		friend std::ostream& operator<<(std::ostream&,const Student&);
		bool removeCourse(int ); 
		bool setGrade(int,int);
		double calcCredit() const;

	protected:
		
	private:
		char *name;
		Date birthDate;
		Course *courseList[MAX_SIZE];
		int courseNumber;
};

#endif
