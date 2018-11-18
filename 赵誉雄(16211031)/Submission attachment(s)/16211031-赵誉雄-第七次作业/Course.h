#include <iostream>
#include <iomanip>
using namespace std;
#ifndef COURSE_H
#define COURSE_H

class Course {
	friend ostream& operator<<(ostream& output, const Course& c)
	{
		output<<"course name: "<<setw(18)<<c.name<<"	credit: "<<c.creditHour<<"	score: ";
		if(c.getScore()<0){
			output<<setw(5)<<"NULL"<<endl;
		}
		else{
			output<<setw(5)<<c.getScore()<<endl;
		}
		return output;
	} 
		
	public:
		Course();
		Course(const string,const int);
		Course(const Course &);
		string getName() const;
		int getCreditHour() const;
		Course& _setName(const string);
		Course& setCreditHour(const int);
		virtual int getScore() const=0;
		virtual int O_credit() const=0;
		virtual int if_E() const=0;
		//void printc() const;
		virtual ~Course();
		
		
	protected:
		
	private:
		string name;
		int creditHour;
};

#endif
