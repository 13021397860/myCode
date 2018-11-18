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
		virtual void printCourse()const{};//Ðéº¯Êý 
		friend ostream &operator <<(ostream&out,const Course &C);
		virtual int getScore()const=0;//´¿Ðéº¯Êý 
		~Course();
	protected:
		string name;
		int creditHour;
};
#endif
