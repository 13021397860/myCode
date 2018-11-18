#ifndef COURSE_H
#define COURSE_H
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
// No description
class Course
{
	// private section
	public:
		void setname(const string &);
		void setcreditHour(const int &);
		const string getname()const{return name;}
		const int getcreditHour()const{return creditHour;}
		virtual void print()const;
		friend ostream & operator <<(ostream &,Course &);
		// class constructor
		Course(const string &,const int &);
		// class destructor
		virtual ~Course();
		
		virtual const int getScore()const=0;  
		virtual const int getType()const=0;
	protected:
		string name;
		int creditHour;
};

#endif // COURSE_H

