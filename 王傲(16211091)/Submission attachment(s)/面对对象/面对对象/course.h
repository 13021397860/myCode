#ifndef COURSE_H
#define COURSE_H
#include<string>
#include<iostream>
using namespace std;
class Course
{
	protected:
		string courseName;
		int creditHour;
	public:
		Course(const string& a="sss",int b=0);
		void setCourseName(const string&);
		void setCreditHour(int);
	    string getCourseName() const;
		int getCreditHour() const;
		virtual void print(){};	
		virtual int getScore()=0;
		//жиди<<
		friend istream& operator>>(istream&,Course&);
		friend ostream& operator<<(ostream&,const Course&);
	
};
#endif
