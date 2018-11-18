#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include "Course.h"
#define MAX_SIZE 200
class Student
{
	public:
		Student(const char* const,int,int,int);
		Student(const Student&);
		Student& addCourse(const string &courseName,int creditHour);
		Student& addCourse(Course *course);
		char* getname();
		Date getbirthDate();
		int getCourseNumber();
		void setname(const char* const);
		Course &operator[](int);
		friend ostream& operator<<(ostream&,Student&);
		bool removeCourse(int);
		static int getcount();
		double getCalcCredit();
		~Student();
	private:
		char *name;
	    Date birthDate;
	    static int count;
	    Course *courseList[MAX_SIZE];
	    int courseNumber;
	    
};
#endif // EMPLOYEE_
