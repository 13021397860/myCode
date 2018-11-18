#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <cstring>
using namespace std;
class Course
{
	friend ostream &operator<<(ostream&,const Course &);
	public:
		Course (string=" " ,int =0);
		void setname(string str);
		void setCreditHour(int cr);
		string getname();
		int getCreditHour();
		virtual int getScore()=0;
	protected:
		string name;
		int creditHour;
};

#endif
