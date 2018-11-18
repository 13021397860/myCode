#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include"Course.h"

class ElectiveCourse : public Course {
public:
	ElectiveCourse();
	ElectiveCourse(const string,const int,const char='F');

	void setGrade(const char);

	virtual int getScore() const ;

protected:
	char grade;
};

#endif // ELECTIVECOURSE_H
