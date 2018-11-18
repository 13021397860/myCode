#ifndef STUDENT_H
#define STUDENT_H
#include"Date.h"
#include"Course.h"
#define MAX_SIZE 10 
class Student
{
	public:
		Student();
		Student(const char *const, Date &);
		Student(Student &);
		~Student(); 
		void setName(char *);
		void setBirthday(const Date &);
		char getName() const;
		Date getBirthday();
		void printStudent();
		int getcount() const;
		Student& addCourse(const string &courseName, int credit);
		Student& addCourse(Course *);
		friend ostream& operator << (ostream &, Student &);
		bool removeCourse(int);
		int getCaleCredit();
		int getCourseNumber();
		Course *outputList();
		Course *getList(int);
	private:
		char *sname;
		Date birthday;
		static int count;
		Course *courseList[MAX_SIZE];
		int courseNumber;
		int count_1;
};
#endif
