#ifndef COURSE_H
#define COURSE_H
#include<string>
#include<iostream>
#include "MyException.h"
using namespace std; 
class Course
{
	public:
		Course(const string tname,const int tcreditHour);
		Course();
		Course(const Course &C);
		string getName()const;
		int getCreditHour()const;
		string setName(string _name);
		int setCreditHour(int _creditHour); 
		virtual void printCourse()const{};//�麯�� 
		friend ostream &operator <<(ostream&out,const Course &C);
		virtual int getScore()const=0;//���麯�� 
		~Course();
	protected:
		string name;
		int creditHour;
};
#endif
