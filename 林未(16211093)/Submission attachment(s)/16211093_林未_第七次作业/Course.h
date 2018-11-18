#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
using namespace std;

class Course
{
	public:
		Course(string, int);
		
		friend ostream& operator<<(ostream&, const Course&);
		Course& setName(const string);
		string getCourseName()	const	{return name;}
        int getCreditHour()	const	{return creditHour;}
        virtual int getScore() const = 0;
        
        virtual ~Course();
	
	protected:
		string name;
		int creditHour;
	
	private:
}; 

#endif
