#ifndef COURSE_H
#define COURSE_H
#include<iostream>
#include<iomanip>
#include<typeinfo>

using namespace std;

class Course {
public:
	Course();
	Course(const string,const int);
	Course(const Course&);

	void setName(const string);
	void setCreditHour(const int);

	string getName() const;
	int getCreditHour() const;

	virtual int getScore() const =0 ;

	friend ostream& operator<<(ostream&, const Course&);

	virtual ~Course();

protected:
	string name;
	int creditHour;
};

#endif // COURSE_H







