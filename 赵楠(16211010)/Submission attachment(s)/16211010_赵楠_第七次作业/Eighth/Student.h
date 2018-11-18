#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include "Course.h"
#include "Console.h"
#define MAX_SIZE 50

class Student
{
	public:
		Student(char*,int,int,int);
		Student(const Student&);
		void setName(char*);
		void setBirthdate(int,int,int);
		void SsetScore(int,int);
		char* getName();
		int getBirth_y();
		int getBirth_m();
		int getBirth_d();
		void print();
		void printnum();
		void printcourse()const;
		void file_in();
		void file_print(const Student&);
		void showmecourse();
		bool removeCourse(int);
		friend ostream &operator<<(ostream&,const Student&);
		Student& addCourse(Course*);
		void filecourse(int&,string&,int&,int);
		float caleCredit();
		void checkCScorse();
		virtual~Student();
	private:
		int Credit[MAX_SIZE];
		int Type[MAX_SIZE];
		int canchoose;
		string courses[MAX_SIZE];
		int credit;
		char *name;
		Date birthDate;
		Course *courseList[MAX_SIZE];
		int courseNumber;		
};

#endif
