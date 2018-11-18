#pragma once
#include "Course.h"
#include <string>
#include "Base.h"
class ElectiveCourse: public Course,virtual public Base
{
public:
	virtual int classID() const;
	explicit ElectiveCourse(const std::string &ECourseName, int credit);
	ElectiveCourse(const ElectiveCourse &T);
	~ElectiveCourse();
	virtual int setScore(char theGrade);
	virtual int getScore()const;
private:
	int changeToScore(char theGrade)const;
	char grade;
	bool ifGrade;
	static const int ClassID=051205;
};

