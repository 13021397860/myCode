#include <string>
using namespace std;
#include <iostream>
using std::ostream;
using std::istream;
#ifndef COURSE_H
#define COURSE_H
class Course{
	
		friend ostream& operator<<(ostream &,const Course &);
		
	public:
		
		virtual int getObligatoryCredit() const		{ return creditHour;}
		virtual int getElectiveNumber() const  {return 1;}
		
		Course(string,int);
		Course &setCourse(string ,int);
		string getCourseName()	const	{return name;}
        int getCreditHour()	const	{return creditHour;}
        virtual int getScore() const=0;
		
		void printCourse() const;
		
		~Course();
	
	protected:
		string name;
		int creditHour;
		
	private:
		
};
#endif
