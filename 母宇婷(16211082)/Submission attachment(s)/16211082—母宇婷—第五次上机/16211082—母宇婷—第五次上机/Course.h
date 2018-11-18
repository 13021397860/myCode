#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string.h>

using namespace std;

class Course
{
	friend ostream &operator<<(ostream &,const Course&);
	public:
		Course(const string ,int);
		~Course();
		const string getCoursename()const;
		const int getCoursecreditHour()const;
		int setCourse(const string& ,int);
		string name;
		virtual const int getScore()const=0;
	protected:
	private:
		int creditHour;
};

#endif
