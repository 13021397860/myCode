#ifndef COURSE_H
#define COURSE_H
#include<string>
#include <typeinfo>
using namespace std;
 
class Course
{
	friend ostream & operator<<(ostream & , const Course & );
	public:
		Course();
		Course(string, int);
		Course(const Course &);
		string getCourseName() const	{return Name;}
		int getCreditHour() const	{return creditHour;}
		Course & setName(const string ) ;
		Course & setcreditHour(int ) ;
		//virtual int getScore() const	{}
		virtual int getScore() const=0;	
		~Course();
	private:
		string Name;
		int creditHour;

};




#endif
