#ifndef COURSE_H
#define COURSE_H
#include <iostream>
using namespace std;
class Course
{
	public:
		Course();
		Course(string,int);
		friend ostream &operator<<(ostream&, const Course&);
		virtual~Course();
		int getCredit()const;
		string getName()const;
		virtual int getScore()const=0;
		virtual void setScore(int);
		void setName(string);
		void setCredit(int);
	private:
		string name;
		int creditHour;
};

#endif
