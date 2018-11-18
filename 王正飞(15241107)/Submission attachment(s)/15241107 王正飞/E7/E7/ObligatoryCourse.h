#pragma once
#include"Course.h"

class ObligatoryCourse : public Course
{
public:
	ObligatoryCourse();
	ObligatoryCourse(std::string input_name, const int input_credit_hour, const int input_mark);
	ObligatoryCourse& SetMark(const int input_mark);
	virtual const int GetScore() const;
private:
	int mark;
};