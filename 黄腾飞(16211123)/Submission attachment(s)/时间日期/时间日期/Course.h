#ifndef COURSE_H
#define COURSE_H
#include<string>
#include<iostream>
using namespace std;
class Course
{
	public:
		Course();
		Course(const string&, int );
		~Course();
		string   getName()const;
		int      getCreditHour()const;
		string   setName(const string );
		void     setCreditHour(const int ); 
		virtual void print()const{};
		virtual  int getScore()const=0;
		friend ostream &operator <<( ostream &,const Course & );
	protected:
	private:
	     string  name;
		 int  creditHour;//ังทึ 
		
};

#endif
