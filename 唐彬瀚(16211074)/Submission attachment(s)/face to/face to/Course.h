#ifndef COURSE_H
#define COURSE_H
#include<cstring>
#include<iostream>
using namespace std;
class Course
{
	public:		
		Course();
		Course(string, int);
		void setCredit(int);
		void setCourseName(string);
		~Course();
		friend ostream& operator << (ostream &, Course &);
		void setCourse(const string);
		string getCourseName();
		int const getCredit() const;
		virtual int getScore()=0;
	private:		
		int creditHour;
		string cname;
};


#endif
