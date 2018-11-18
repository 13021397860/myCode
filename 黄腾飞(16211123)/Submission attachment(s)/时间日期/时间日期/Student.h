#ifndef STUDENT_H
#define STUDENT_H
#include"Date.h"
#include"Course.h"
#define max_size 10
class Student
{
	public:
		Student();
		Student(const char *,const Date &);
		Student(const Student & );
		~Student();
	    static	int getCount();
		void setName(const char*);
		int getcourseNumber(){return courseNumber;}
		char* getName()const;
		Date getDate()const; 
		void print( )const;
	    Student& addCourse(Course* course ); 
		//Student& addCourse(const string &courseName ,int creditHour);
	    friend ostream &operator <<( ostream &,const Student & );
	    bool removeCourse(int );
	    int dafen(int );
	    int  getfen(int );
	    double  calcCredit()const;
	    string getname(int)const;
	protected:
	private:
		 char  *name;
	    const  Date birthDate;
	    static int count;
	    Course *courseList[max_size];
	    static int courseNumber;
};

#endif
