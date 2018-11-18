#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include"Course.h"

class ObligatoryCourse : public Course {
public:
	ObligatoryCourse();
	ObligatoryCourse(const string,const int,const int=0);

	void setGrade(const int);

	virtual int getScore() const ;

protected:
	int mark;
};

#endif // OBLIGATORYCOURSE_H
