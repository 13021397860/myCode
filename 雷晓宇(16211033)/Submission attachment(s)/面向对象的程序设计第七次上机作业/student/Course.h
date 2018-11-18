#ifndef COURSE_H
#define COURSE_H
#include<string>
#include <iostream>
using namespace std;

class Course
{
	public:
		Course(const string,const int);
		string getName() const;
		int getCreditHour() const;
		void setCourseName(const string);
		void setCreditHour(const int);
		friend ostream& operator<<(ostream& output,const Course& p);
		virtual int getScore() const=0;
		virtual ~Course();
	protected:
	private:
		string name;
		int creditHour;
};

#endif
